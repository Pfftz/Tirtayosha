#!/usr/bin/env python3
from Agent import *  # See the Agent.py file
import itertools
import copy

# All your code can go here.

# You can change the main function as you wish. Run this program to see the output. Also see Agent.py code.

total_count = 0

kb = []  # main knowledge base to store the propositional sentences in cnf form

actions = []  # store the moves taken by the agent

current_status = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0],
                  [0, 0, 0, 0]]  # keep track of the safe spots in the map
allowed_moves = [[0, 1], [0, -1], [1, 0], [-1, 0]]
moves = ['Up', 'Down', 'Right', 'Left']
moves_taken = []


def FindAdjacentRooms(cl):
    cLoc = cl
    validMoves = [[0, 1], [0, -1], [-1, 0], [1, 0]]
    adjRooms = []
    for vM in validMoves:
        room = []
        valid = True
        for v, inc in zip(cLoc, vM):
            z = v + inc
            if z < 1 or z > 4:
                valid = False
                break
            else:
                room.append(z)
        if valid:
            adjRooms.append(room)
    return adjRooms


def legal(r, c):
    return 0 <= r < 4 and 0 <= c < 4


def bfs(current, target):  # used for going from one safe path to another
    visited = [[False] * 4 for _ in range(4)]  # maintaining the visited list
    q = []
    # used for keeping track of the directions moved
    dir = {(current[0], current[1]): (None, None)}
    q.append((current[0], current[1]))
    visited[current[0]][current[1]] = True
    while q:
        s = q.pop(0)
        if s[0] == target[0] and s[1] == target[1]:  # checking if target has been reached
            break
        for i in range(4):
            newr = s[0] + allowed_moves[i][0]
            newc = s[1] + allowed_moves[i][1]
            # checking if next move is legal
            if legal(newr, newc) and current_status[newr][newc] == 1 and not visited[newr][newc]:
                visited[newr][newc] = True  # update the visited list
                q.append((newr, newc))
                dir[(newr, newc)] = ((s[0], s[1]), moves[i])

    target_moves = []
    top = (target[0], target[1])
    while top != (current[0], current[1]):
        # adding the moves taken to reach the target
        target_moves.append(dir[top][1])
        top = dir[top][0]

    target_moves.reverse()  # reversing the list to get the correct order
    return target_moves


def initialize(ag):  # initialize the knowledge base with the rules of the game
    big_s1 = set()
    big_s2 = set()
    for i in range(4):
        for j in range(4):
            for l, r in (('B', 'P'), ('S', 'W')):
                neighbours = FindAdjacentRooms([i + 1, j + 1])
                first_element = set()
                for x, y in neighbours:
                    # converting the formula of bidirection here
                    first_element.add((f'{r}{x}{y}', 1))
                # p <=> r V q === (~pVrVq)and(pV~r)and(pV~q)
                first_element.add((f'{l}{i + 1}{j + 1}', 0))
                kb.append(first_element)  # first expression is (~pVrVq...)
                for x, y in neighbours:
                    # this expression corresponds to (pV~r)and(pV~q) and so on
                    kb.append({(f'{r}{x}{y}', 0), (f'{l}{i + 1}{j + 1}', 1)})
                if r == 'P':
                    big_s1.add((f'{r}{i + 1}{j + 1}', 1))
                else:
                    big_s2.add((f'{r}{i + 1}{j + 1}', 1))

    kb.append(big_s1)  # there is at least one Pit Condition
    kb.append(big_s2)  # there is at least one Wumpus condition

    k = 0
    store = dict()
    for i in range(4):
        for j in range(4):
            for i1 in range(4):
                for j1 in range(4):
                    if i1 == i and j1 == j:
                        continue
                    else:
                        temp1 = (f'W{i + 1}{j + 1}', 0)
                        temp2 = (f'W{i1 + 1}{j1 + 1}', 0)
                        if (temp1, temp2) not in store and (temp2, temp1) not in store:
                            store[(temp1, temp2)] = 1
                            store[(temp2, temp1)] = 1
                            k += 1
                            # there are at most one wumpus
                            kb.append({temp1, temp2})
                            # there are at most one pit
                            kb.append({(f'P{i + 1}{j + 1}', 0),
                                      (f'P{i1 + 1}{j1 + 1}', 0)})


def literal_expr(expr):  # select the first literal
    for c in expr:
        for d in c:
            return d[0]


def dpll(expr):
    global total_count
    total_count += 1
    # using the pure symbol function get all the pure symbols
    ps = pure_symbols(expr)
    expr_new = []
    to_add = True
    if len(ps) != 0:
        for c in expr:
            for k in c:
                if k in ps:
                    to_add = False  # checking if pure symbol exists in the clause and removing it if it exists
                    break
            if to_add:
                expr_new.append(c)
            to_add = True
    else:
        expr_new = copy.deepcopy(expr)

    # getting unit clauses and also checking if they are any polarising unit clauses
    polarity, uc = unit_clauses(expr_new)
    if not polarity:  # for eg p, ~p
        return False

    if len(uc) != 0:
        for i in uc:
            expr_new.remove(i)  # first remove all the unit clauses

        to_change = []
        to_add = True
        for k in expr_new:
            for j in k:
                for i in uc:
                    for z in i:
                        if z == j:
                            to_add = False
                            break
                if not to_add:
                    break
            if to_add:
                # remove other clauses containing the unit clauses
                to_change.append(k)
            to_add = True

        for i in uc:
            new_one = None
            for k in i:
                new_one = {(k[0], 1 - k[1])}
            # remove the negation of the unit clauses from the clauses
            to_change = [c.difference(new_one) for c in to_change]

        expr_new = copy.deepcopy(to_change)

    if len(expr_new) == 0:  # early termination condition: if there are no clauses it's true
        return True

    if any([len(c) == 0 for c in expr_new]):  # if there is a box clause
        return False

    if expr_new != expr:  # check if pure symbol/unit clause heuristic did anything
        return dpll(expr_new)
    else:  # at this point pure symbol and unit clause have not produced any effect so start assigning values to variables
        cnf = copy.deepcopy(expr_new)
        l = literal_expr(cnf)
        expr_new_one = []
        for c in cnf:
            if (l, 1) not in c:
                expr_new_one.append(c)
        expr_new_one = [c.difference({(l, 0)}) for c in expr_new_one]
        done = dpll(expr_new_one)
        if done:
            return done

        expr_new_one = []
        for c in cnf:
            if (l, 0) not in c:
                expr_new_one.append(c)
        expr_new_one = [c.difference({(l, 1)}) for c in expr_new_one]
        done = dpll(expr_new_one)
        if done:
            return done

        return False  # return false if both fail


def pure_symbols(expr):
    symbols = set()  # get the list of symbols
    for c in expr:
        for d in c:
            symbols.add(d[0])

    main_list = dict()
    holding_val = dict()
    for i in symbols:
        main_list[i] = True  # initially mark all symbols as pure symbols

    for a in expr:
        for b in a:
            if not main_list[b[0]]:
                continue
            if b[0] in holding_val:
                # check if var already exists in the dict and mark it as false if other form exists
                if b[1] != holding_val[b[0]]:
                    main_list[b[0]] = False
            else:
                holding_val[b[0]] = b[1]

    to_ret = set()
    for i in main_list:
        if main_list[i]:  # make a set to return
            to_ret.add((i, holding_val[i]))

    return to_ret


def unit_clauses(expr):
    to_ret = list()
    to_ret_cons = True
    # find unit clauses and also check if complimentary unit clauses are present
    track_truth = dict()
    for d in expr:
        if len(d) == 1:
            for t in d:
                to_ret.append({t})
                if t[0] not in track_truth:
                    track_truth[t[0]] = t[1]
                else:
                    if t[1] != track_truth[t[0]]:
                        to_ret_cons = False
                        break

    return to_ret_cons, to_ret


def simulation(ag):
    stack = [[1, 1]]  # stack which contains places which are safe to visit
    # current_status list which has places which are marked safe
    current_status[0][0] = 1
    visited = dict()  # dict which keeps track of tiles which have already been visited
    visited[(0, 0)] = 1
    score = 0  # Initialize score

    try:
        while ag.FindCurrentLocation() != [4, 4]:
            my_tile = ag.FindCurrentLocation()
            stack.pop()  # pop the current element from visited
            # mark the current element as visited
            visited[(my_tile[0], my_tile[1])] = 1
            breeze, stench = ag.PerceiveCurrentLocation()

            if breeze:  # add the perception around the environment
                kb.append({(f'B{my_tile[0]}{my_tile[1]}', 1)})
            else:
                kb.append({(f'B{my_tile[0]}{my_tile[1]}', 0)})

            if stench:
                kb.append({(f'S{my_tile[0]}{my_tile[1]}', 1)})
            else:
                kb.append({(f'S{my_tile[0]}{my_tile[1]}', 0)})

            adj_rooms = FindAdjacentRooms([my_tile[0], my_tile[1]])

            for room in adj_rooms:  # check on the neighbours using dpll
                if (room[0], room[1]) in visited:  # check if the room is already visited
                    continue
                # check if wumpus is not present by using kb^~alpha is unsat
                wump_alive = {(f'W{room[0]}{room[1]}', 1)}
                kb.append(wump_alive)
                val1 = dpll(kb)
                if val1:
                    kb.remove(wump_alive)
                    # check if wumpus is present
                    wump_alive_here = {(f'W{room[0]}{room[1]}', 0)}
                    kb.append(wump_alive_here)
                    val11 = dpll(kb)
                    if not val11:
                        kb.remove(wump_alive_here)
                        kb.append(wump_alive)
                        # mark the wumpus is present
                        current_status[room[0] - 1][room[1] - 1] = 2
                    else:
                        kb.remove(wump_alive_here)
                    continue
                kb.remove(wump_alive)
                # check the same conditions for the pit as well
                kb.append({(f'W{room[0]}{room[1]}', 0)})
                pit_present = {(f'P{room[0]}{room[1]}', 1)}
                kb.append(pit_present)
                val2 = dpll(kb)
                if val2:
                    kb.remove(pit_present)
                    pit_present_here = {(f'P{room[0]}{room[1]}', 0)}
                    kb.append(pit_present_here)
                    val21 = dpll(kb)
                    if not val21:
                        kb.remove(pit_present_here)
                        kb.append(pit_present)
                        current_status[room[0] - 1][room[1] - 1] = 2
                    else:
                        kb.remove(pit_present_here)
                    continue
                kb.remove(pit_present)
                kb.append({(f'P{room[0]}{room[1]}', 0)})
                stack.append(room)  # adding room to the stack
                # marking the room as safe
                current_status[room[0] - 1][room[1] - 1] = 1

            if len(stack) == 0:  # backtracking back to the start if stack is empty
                stack.append([1, 1])
                visited.clear()

            new_location = stack[-1]
            p1 = [my_tile[0] - 1, my_tile[1] - 1]
            p2 = [new_location[0] - 1, new_location[1] - 1]
            path = bfs(p1, p2)

            for p in path:  # move to the new location
                ag.TakeAction(p)
                actions.append(p)
                moves_taken.append(ag.FindCurrentLocation())
                score -= 1  # Deduct 1 point for each move
                if ag._hasGold:
                    score += 1000  # Add 1000 points if gold is found
                    print("Gold found! Final score: ", score)
                    return  # Stop the simulation
    finally:
        print("tiles gone to reach: ", moves_taken)
        print("actions taken to reach: ", actions)
        print("total number of calls to dpll: ", total_count)


def main():
    ag = Agent()
    initialize(ag)
    simulation(ag)


if __name__ == '__main__':
    main()
