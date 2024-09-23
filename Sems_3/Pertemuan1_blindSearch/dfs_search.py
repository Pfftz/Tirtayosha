import time

class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = []

def dfs_search_recursive(node, target, path):
    if node is None:
        return None
    
    path.append(node.value)
    
    if node.value == target:
        return path
    
    for child in node.children:
        result = dfs_search_recursive(child, target, path)
        if result is not None:
            return result
    
    path.pop()  # Backtrack if not found in this path
    return None

# Printing the structure to verify
def print_tree(node, level=0):
    print(' ' * level * 2 + str(node.value))
    for child in node.children:
        print_tree(child, level + 1)

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
child1.children[0].children.append(TreeNode(9))
node_with_value_9 = child1.children[0].children[-1]
# Adding a new child with value 10 to the node with value 9
node_with_value_9.children.append(TreeNode(10))
node_with_value_9.children.append(TreeNode(11))

# Measure the time to find a value and track the path
start_time = time.perf_counter()
path = dfs_search_recursive(root, 11, [])
end_time = time.perf_counter()

elapsed_time = end_time - start_time

print_tree(root)

if path:
    print(f"Path to node with value 5: {path}")
else:
    print("Value not found in the tree.")
    
print(f"Time taken to find the node: {elapsed_time:.6f} seconds")