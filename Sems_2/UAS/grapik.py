'''WATERMARK ADMIN Hd'''
import time
import numpy as np
from collections import defaultdict, deque

class Grafika:
    def __init__(self, num_of_vertices):
        self.v = num_of_vertices
        self.graph = defaultdict(list)
        self.matrix = np.zeros((num_of_vertices, num_of_vertices))

    def addEdging(self, u, v):
        self.graph[u].append(v)
        self.matrix[u][v] = 1

    def BFS_list(self, s):
        visited = [False] * (self.v)
        queue = deque([s])
        visited[s] = True
        while queue:
            s = queue.popleft()
            queue.extend(i for i in self.graph[s] if not visited[i])
            visited[s] = True

    def DFS_list(self, s):
        visited = [False] * (self.v)
        stack = [s]
        while stack:
            s = stack.pop()
            if not visited[s]:
                visited[s] = True
                stack.extend(node for node in self.graph[s] if not visited[node])

    def BFS_matrix(self, s):
        visited = [False] * (self.v)
        queue = deque([s])
        visited[s] = True
        while queue:
            s = queue.popleft()
            queue.extend(i for i in range(self.v) if self.matrix[s][i] and not visited[i])
            visited[s] = True

    def DFS_matrix(self, s):
        visited = [False] * (self.v)
        stack = [s]
        while stack:
            s = stack.pop()
            if not visited[s]:
                visited[s] = True
                stack.extend(i for i in range(self.v) if self.matrix[s][i] and not visited[i])

g = Grafika(1000)
for i in range(999):
    g.addEdging(i, i+1)

print("Abdulhadi - Graph Traversal Time - Abdulhadi")
print("Adjency List vs Adjency Matrix")
print("1000 Vertices, 999 Edges")
print("\nAdjency List: ")
start = time.time()
g.BFS_list(0)
end = time.time()
print(f"BFS List Time: {end - start}")

start = time.time()
g.DFS_list(0)
end = time.time()
print(f"DFS List Time: {end - start}")

print('\nAdjency Matrix: ')
start = time.time()
g.BFS_matrix(0)
end = time.time()
print(f"BFS Matrix Time: {end - start}")

start = time.time()
g.DFS_matrix(0)
end = time.time()
print(f"DFS Matrix Time: {end - start}")
print("\n Lead Them To Paradise! - Abdulhadi")