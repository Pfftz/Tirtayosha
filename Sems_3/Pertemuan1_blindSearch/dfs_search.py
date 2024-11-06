import time

class GraphNode:
    def __init__(self, value):
        self.value = value
        self.children = []

def dfs_search_recursive(node, target, path, visited):
    if node is None:
        return None
    
    path.append(node.value)
    visited.add(node.value)
    
    if node.value == target:
        return path
    
    for child in node.children:
        if child.value not in visited:
            result = dfs_search_recursive(child, target, path, visited)
            if result is not None:
                return result
    
    path.pop()  # Backtrack if not found in this path
    return None

# Printing the structure to verify
def print_graph(node, level=0, visited=None):
    if visited is None:
        visited = set()
    if node.value in visited:
        return
    visited.add(node.value)
    print(' ' * level * 2 + str(node.value))
    for child in node.children:
        print_graph(child, level + 1, visited)

# Example usage:
# Constructing a simple graph similar to the heuristic function example
nodes = {value: GraphNode(value) for value in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'}
nodes['A'].children.extend([nodes['B'], nodes['C']])
nodes['B'].children.extend([nodes['D'], nodes['E']])
nodes['C'].children.append(nodes['F'])
nodes['D'].children.append(nodes['G'])
nodes['E'].children.append(nodes['H'])
nodes['F'].children.append(nodes['I'])
nodes['G'].children.append(nodes['J'])
nodes['H'].children.append(nodes['K'])
nodes['I'].children.append(nodes['L'])
nodes['J'].children.append(nodes['M'])
nodes['K'].children.append(nodes['N'])
nodes['L'].children.append(nodes['O'])
nodes['M'].children.append(nodes['P'])
nodes['N'].children.append(nodes['Q'])
nodes['O'].children.append(nodes['R'])
nodes['P'].children.append(nodes['S'])
nodes['Q'].children.append(nodes['T'])
nodes['R'].children.append(nodes['U'])
nodes['S'].children.append(nodes['V'])
nodes['T'].children.append(nodes['W'])
nodes['U'].children.append(nodes['X'])
nodes['V'].children.append(nodes['Y'])
nodes['W'].children.append(nodes['Z'])
nodes['X'].children = []  # No children
nodes['Y'].children = []  # No children
nodes['Z'].children = []  # Goal node

# Measure the time to find a value and track the path
start_time = time.perf_counter()
path = dfs_search_recursive(nodes['A'], 'Z', [], set())
end_time = time.perf_counter()

elapsed_time = end_time - start_time

print_graph(nodes['A'])

if path:
    print(f"Path to node with value 'Z': {path}")
else:
    print("Value not found in the graph.")
    
print(f"Time taken to find the node: {elapsed_time:.6f} seconds")