# 34. Write a Python program to create and analyze social network graphs using the NetworkX library.

import pandas as pd
import matplotlib.pyplot as plt
import networkx as nx

# -------------------------------
# 1. Build a small friendship network by hand
# -------------------------------

G_small = nx.Graph()
G_small.add_edges_from([
    ('Asha', 'Rahul'), ('Asha', 'Meera'), ('Rahul', 'Meera'),
    ('Meera', 'Arjun'), ('Arjun', 'Priya'), ('Arjun', 'Karan'),
    ('Priya', 'Karan'), ('Karan', 'Dev')
])

print("Friendship Network")
print("Nodes:", list(G_small.nodes()))
print("Edges:", list(G_small.edges()))
print("Friends of Meera:", list(G_small.neighbors('Meera')))
print("Shortest path Asha -> Dev:", nx.shortest_path(G_small, 'Asha', 'Dev'))

# -------------------------------
# 2. Analyze a real social network
# -------------------------------

# Zachary's Karate Club: 34 members of a university club,
# an edge means two members met outside the club
G = nx.karate_club_graph()

print("\nKarate Club Network")
print("Number of nodes:", G.number_of_nodes())
print("Number of edges:", G.number_of_edges())
print("Density:", round(nx.density(G), 4))
print("Connected:", nx.is_connected(G))
print("Diameter (longest shortest path):", nx.diameter(G))
print("Average shortest path length:", round(nx.average_shortest_path_length(G), 4))
print("Average clustering coefficient:", round(nx.average_clustering(G), 4))
print("Triangles in the graph:", sum(nx.triangles(G).values()) // 3)

# Centrality: four ways of asking "who is important?"
#   Degree      - who has the most friends
#   Betweenness - who sits on the most shortest paths (a bridge)
#   Closeness   - who can reach everyone in the fewest steps
#   Eigenvector - who is friends with other important people
centrality = pd.DataFrame({
    'Degree': dict(G.degree()),
    'Degree Centrality': nx.degree_centrality(G),
    'Betweenness': nx.betweenness_centrality(G),
    'Closeness': nx.closeness_centrality(G),
    'Eigenvector': nx.eigenvector_centrality(G)
})

print("\nTop 5 members by degree centrality:")
print(centrality.sort_values('Degree Centrality', ascending=False).head().round(4))

for measure in ['Betweenness', 'Closeness', 'Eigenvector']:
    print(f"Most central by {measure:11s}: node {centrality[measure].idxmax()}")

print("\nShortest path from node 0 to node 33:", nx.shortest_path(G, 0, 33))

fig, axes = plt.subplots(1, 3, figsize=(20, 6))

nx.draw(G_small, nx.spring_layout(G_small, seed=42), ax=axes[0], with_labels=True,
        node_color='lightgreen', node_size=1200, font_size=9)
axes[0].set_title("Small Friendship Network")

# Node size by degree, colour by betweenness
pos = nx.spring_layout(G, seed=42)
sizes = [3000 * c for c in centrality['Degree Centrality']]

nodes = nx.draw_networkx_nodes(G, pos, ax=axes[1], node_size=sizes,
                               node_color=list(centrality['Betweenness']), cmap='plasma')
nx.draw_networkx_edges(G, pos, ax=axes[1], alpha=0.4)
nx.draw_networkx_labels(G, pos, ax=axes[1], font_size=8)
fig.colorbar(nodes, ax=axes[1], label="Betweenness Centrality")
axes[1].set_title("Karate Club (size = degree, colour = betweenness)")
axes[1].axis('off')

degrees = [d for _, d in G.degree()]
axes[2].hist(degrees, bins=range(1, max(degrees) + 2), edgecolor='black')
axes[2].set_title("Degree Distribution")
axes[2].set_xlabel("Degree (number of friends)")
axes[2].set_ylabel("Number of members")

plt.tight_layout()
plt.show()
