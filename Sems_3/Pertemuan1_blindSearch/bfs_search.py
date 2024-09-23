import time

class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = []

def bfs_search_with_path(root, target):
    if root is None:
        return None

    queue = [root]
    parent = {root: None}

    while queue:
        current_node = queue.pop(0)
        
        if current_node.value == target:
            # Backtrack to find the path
            path = []
            while current_node is not None:
                path.append(current_node.value)
                current_node = parent[current_node]
            path.reverse()
            return path
        
        for child in current_node.children:
            if child not in parent:
                queue.append(child)
                parent[child] = current_node
    
    return None

# Example usage:
# Constructing a simple tree
root = TreeNode(1)
child1 = TreeNode(2)
child2 = TreeNode(3)
root.children.append(child1)
root.children.append(child2)
child1.children.append(TreeNode(4))
child1.children.append(TreeNode(5))
child2.children.append(TreeNode(6))
child2.children.append(TreeNode(7))

# Measure the time to find a value and track the path
start_time = time.perf_counter()
path = bfs_search_with_path(root, 5)
end_time = time.perf_counter()

elapsed_time = end_time - start_time

if path:
    print(f"Path to node with value 5: {path}")
else:
    print("Value not found in the tree.")

print(f"Time taken to find the node: {elapsed_time:.6f} seconds")