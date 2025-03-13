import osmnx as ox
import pandas as pd

# Use more specific query to ensure we get the full city of Purwokerto
print("Downloading Purwokerto city data...")

city_center = (109.2408501, -7.4279011)  # longitude, latitude
# Get network around this point with 5km radius (covers the city)
G = ox.graph_from_point(city_center[::-1], dist=2000, network_type="drive")
print("Downloaded Purwokerto city data using coordinate-based approach")

# Get node data and convert to DataFrame
nodes = ox.graph_to_gdfs(G, nodes=True, edges=False)
nodes_df = nodes.reset_index()[["osmid", "y", "x"]]

# Print summary of nodes collected
print(f"Collected {len(nodes_df)} nodes covering Purwokerto city area")

# Save to Excel
nodes_df.to_excel("Purwokerto_Nodes.xlsx", index=False)
print("Data nodes saved as Purwokerto_Nodes.xlsx")