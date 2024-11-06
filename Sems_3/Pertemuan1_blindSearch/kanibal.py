from collections import deque

# Definisi state: (mp, mc, bp, bq, br, p, q, r, P, Q, R, boat)
# mp, mc: jumlah misionaris dan kanibal di sisi awal
# bp, bq, br, p, q, r: posisi misionaris (0: sisi awal, 1: sisi akhir)
# P, Q, R: posisi kanibal (0: sisi awal, 1: sisi akhir)
# boat: posisi perahu (0: sisi awal, 1: sisi akhir)


def is_valid(state):
    mp, mc, bp, bq, br, p, q, r, P, Q, R, boat = state
    if mp > 0 and mp < mc:  # Sisi awal
        return False
    if (3 - mp) > 0 and (3 - mp) < (3 - mc):  # Sisi akhir
        return False
    return True


def get_neighbors(state):
    mp, mc, bp, bq, br, p, q, r, P, Q, R, boat = state
    neighbors = []
    if boat == 0:  # Perahu di sisi awal
        passengers = [i for i in range(6) if [bp, bq, br, p, q, r][i] == 0]
        for i in range(len(passengers)):
            for j in range(i, len(passengers)):
                new_state = list(state)
                new_state[passengers[i]+2] = 1
                new_state[passengers[j]+2] = 1
                new_state[-1] = 1
                new_state[0] = sum([1 for x in new_state[2:5] if x == 0])
                new_state[1] = sum([1 for x in new_state[5:8] if x == 0])
                if is_valid(tuple(new_state)):
                    neighbors.append(tuple(new_state))
    else:  # Perahu di sisi akhir
        passengers = [i for i in range(6) if [bp, bq, br, p, q, r][i] == 1]
        for i in range(len(passengers)):
            for j in range(i, len(passengers)):
                new_state = list(state)
                new_state[passengers[i]+2] = 0
                new_state[passengers[j]+2] = 0
                new_state[-1] = 0
                new_state[0] = sum([1 for x in new_state[2:5] if x == 0])
                new_state[1] = sum([1 for x in new_state[5:8] if x == 0])
                if is_valid(tuple(new_state)):
                    neighbors.append(tuple(new_state))
    return neighbors


def bfs():
    start = (3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    goal = (0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1)
    queue = deque([(start, [])])
    visited = set()

    while queue:
        state, path = queue.popleft()
        if state == goal:
            return path

        if state in visited:
            continue

        visited.add(state)

        for neighbor in get_neighbors(state):
            new_path = path + [neighbor]
            queue.append((neighbor, new_path))

    return None


def print_solution(solution):
    if not solution:
        print("Tidak ada solusi.")
        return

    print("Solusi ditemukan:")
    for i, state in enumerate(solution):
        mp, mc, bp, bq, br, p, q, r, P, Q, R, boat = state
        print(f"Langkah {i+1}:")
        print(f"Sisi awal: {mp}M {mc}K | ", end="")
        print(f"Sisi akhir: {3-mp}M {3-mc}K")
        print("Misionaris:", "".join(['p' if bp == 0 else ' ', 'q' if bq == 0 else ' ', 'r' if br == 0 else ' ']), "|",
              "".join(['p' if bp == 1 else ' ', 'q' if bq == 1 else ' ', 'r' if br == 1 else ' ']))
        print("Kanibal:   ", "".join(['P' if P == 0 else ' ', 'Q' if Q == 0 else ' ', 'R' if R == 0 else ' ']), "|",
              "".join(['P' if P == 1 else ' ', 'Q' if Q == 1 else ' ', 'R' if R == 1 else ' ']))
        print("Perahu:    ", "B" if boat == 0 else " ",
              "|", "B" if boat == 1 else " ")
        print()

    print("Solusi selesai!")


solution = bfs()
print_solution(solution)
