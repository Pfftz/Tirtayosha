import osmnx as ox
import networkx as nx
import matplotlib.pyplot as plt

# koordinat titik asal dan tujuan (Monas ke Bundaran HI)
origin_point = (-6.1754, 106.8272)  # monas
destination_point = (-6.1931, 106.8236)  # bundaran HI

# mengambil data jalan dari open street map
graph = ox.graph_from_place("Jakarta, Indonesia", network_type="drive")

# ambil node dari komponen terhubung terbesar
largest_component_nodes = max(nx.strongly_connected_components(graph), key=len)
G = graph.subgraph(largest_component_nodes).copy()

# Temukan node terdekat dari titik asal dan tujuan
orig_node = ox.distance.nearest_nodes(graph, origin_point[1], origin_point[0])
dest_node = ox.distance.nearest_nodes(
    graph, destination_point[1], destination_point[0])

# Jalur terpendek dengan algoritma Dijkstra
shortest_route_dijkstra = nx.shortest_path(
    G, orig_node, dest_node, weight='length', method='dijkstra'
)

# Definisikan fungsi heuristik untuk A* (menggunakan jarak Euclidean)


def heuristic(u, v):
    u_data = G.nodes[u]
    v_data = G.nodes[v]
    return ((u_data['x'] - v_data['x'])**2 + (u_data['y'] - v_data['y'])**2)**0.5


# Jalur terpendek dengan algoritma A* menggunakan nx.astar_path
shortest_route_astar = nx.astar_path(
    G, orig_node, dest_node, heuristic=heuristic, weight='length'
)

# Untuk menampilkan dua rute, gunakan plot_graph_routes
fig, ax = ox.plot_graph_routes(
    G,
    routes=[shortest_route_dijkstra, shortest_route_astar],
    route_colors=['b', 'r'],
    route_linewidth=6,
    node_size=0,
    bgcolor='k'
)

# keterangan tambahan
plt.title("Jalur terpendek: Dijkstra (biru) vs A* (merah)")
plt.show()
