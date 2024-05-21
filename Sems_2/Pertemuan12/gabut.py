import time
import igraph

num_nodes = 10000
graph = igraph.Graph.Barabasi(num_nodes, 2)

adj_list = graph.get_adjlist()

adj_matrix = graph.get_adjacency()

def bfs_with_adj_list(graph, start):
    visited = [False] * len(graph)
    queue = [start]
    visited[start] = True
    while queue:
        node = queue.pop(0)
        for neighbor in graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)

def dfs_with_adj_list(graph, start):
    visited = [False] * len(graph)
    stack = [start]
    while stack:
        node = stack.pop()
        if not visited[node]:
            visited[node] = True
            stack.extend(neigh for neigh in graph[node] if not visited[neigh])

def bfs_with_adj_matrix(matrix, start):
    visited = [False] * len(matrix)
    queue = [start]
    visited[start] = True
    while queue:
        node = queue.pop(0)
        for i in range(len(matrix[node])):
            if matrix[node][i] and not visited[i]:
                visited[i] = True
                queue.append(i)

def dfs_with_adj_matrix(matrix, start):
    visited = [False] * len(matrix)
    stack = [start]
    while stack:
        node = stack.pop()
        if not visited[node]:
            visited[node] = True
            stack.extend(i for i in range(len(matrix[node])) if matrix[node][i] and not visited[i])

start_time = time.time()
bfs_with_adj_list(adj_list, 0)
bfs_adj_list_time = time.time() - start_time
print("Time kompleksitas BFS dengan adjacency list:", "{:.2f}".format(bfs_adj_list_time), "seconds")

start_time = time.time()
dfs_with_adj_list(adj_list, 0)
dfs_adj_list_time = time.time() - start_time
print("Time kompleksitas DFS dengan adjacency list:", "{:.2f}".format(dfs_adj_list_time), "detik")

start_time = time.time()
bfs_with_adj_matrix(adj_matrix.data, 0)
bfs_adj_matrix_time = time.time() - start_time
print("Time kompleksitas BFS dengan adjacency matrix:", "{:.2f}".format(bfs_adj_matrix_time), "detik")

start_time = time.time()
dfs_with_adj_matrix(adj_matrix.data, 0)
dfs_adj_matrix_time = time.time() - start_time
print("Time kompleksitas DFS dengan adjacency matrix:", "{:.2f}".format(dfs_adj_matrix_time), "detik")

fastest_algorithm = min(bfs_adj_list_time, dfs_adj_list_time, bfs_adj_matrix_time, dfs_adj_matrix_time)
if fastest_algorithm == bfs_adj_list_time:
    print("Time kompleksitas paling cepat adalah BFS dengan adjacency list:", "{:.2f}".format(fastest_algorithm), "detik")
elif fastest_algorithm == dfs_adj_list_time:
    print("Time kompleksitas paling cepat adalah DFS dengan adjacency list:", "{:.2f}".format(fastest_algorithm), "detik")
elif fastest_algorithm == bfs_adj_matrix_time:
    print("Time kompleksitas paling cepat adalah BFS dengan adjacency matrix:", "{:.2f}".format(fastest_algorithm), "detik")
else:
    print("Time kompleksitas paling cepat adalah DFS dengan adjacency matrix:", "{:.2f}".format(fastest_algorithm), "detik")