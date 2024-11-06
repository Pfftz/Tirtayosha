import time

class Node:
    def __init__(self, state, parent=None, cost=0, heuristic=0):
        self.state = state
        self.parent = parent
        self.cost = cost
        self.heuristic = heuristic
        self.total_cost = cost + heuristic

    def __lt__(self, other):
        return self.total_cost < other.total_cost

def astar_search(start, goal, heuristic_func, get_successors, cost_func):
    from queue import PriorityQueue

    open_list = PriorityQueue()
    open_list.put(Node(start, heuristic=heuristic_func(start)))
    closed_list = set()

    while not open_list.empty():
        current_node = open_list.get()
        current_state = current_node.state

        if current_state in closed_list:
            continue

        closed_list.add(current_state)

        if current_state == goal:
            return reconstruct_path(current_node)

        for successor in get_successors(current_state):
            if successor not in closed_list:
                g_cost = current_node.cost + cost_func(current_state, successor)
                h_cost = heuristic_func(successor)
                open_list.put(Node(successor, parent=current_node, cost=g_cost, heuristic=h_cost))

    return None

def reconstruct_path(node):
    path = []
    while node:
        path.append(node.state)
        node = node.parent
    return path[::-1]

# Example heuristic function
def heuristic_func(state):
    # Simple heuristic: distance to goal (assuming goal is 'G')
    heuristic_values = {
        'A': 6,
        'B': 5,
        'C': 4,
        'D': 3,
        'E': 2,
        'F': 1,
        'G': 0
    }
    return heuristic_values.get(state, float('inf'))

# Example successor function
def get_successors(state):
    # Simple graph representation
    successors = {
        'A': ['B', 'C'],
        'B': ['D', 'E'],
        'C': ['F'],
        'D': ['G'],
        'E': ['G'],
        'F': ['G'],
        'G': []
    }
    return successors.get(state, [])

# Example cost function
def cost_func(current_state, successor):
    # Uniform cost for simplicity
    return 1

# Example usage
start_state = "A"
goal_state = "G"

start_time = time.time()
path = astar_search(start_state, goal_state, heuristic_func, get_successors, cost_func)
end_time = time.time()

print("Path found:", path)
print("Time taken:", end_time - start_time, "seconds")
