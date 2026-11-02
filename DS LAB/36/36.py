# 36. Write a Python program to perform graph partitioning and analyze neighborhood properties.

import matplotlib.pyplot as plt
import networkx as nx
from networkx.algorithms.community import kernighan_lin_bisection

G = nx.karate_club_graph()

print("Nodes:", G.number_of_nodes(), " Edges:", G.number_of_edges())

# -------------------------------
# 1. Graph partitioning
# -------------------------------

# Kernighan-Lin splits the graph into two equal halves while cutting
# as few edges as possible, by repeatedly swapping nodes between the halves
part_a, part_b = kernighan_lin_bisection(G, seed=42)

print("\nKernighan-Lin Bisection")
print(f"Partition A ({len(part_a)} nodes): {sorted(part_a)}")
print(f"Partition B ({len(part_b)} nodes): {sorted(part_b)}")

cut_edges = [(u, v) for u, v in G.edges if (u in part_a) != (v in part_a)]

print("\nEdges inside A:", G.subgraph(part_a).number_of_edges())
print("Edges inside B:", G.subgraph(part_b).number_of_edges())
print("Edges cut between A and B:", nx.cut_size(G, part_a, part_b))

# Lower is better for both: few edges leave each part compared to its size
print("Normalized cut:", round(nx.normalized_cut_size(G, part_a, part_b), 4))
print("Conductance:", round(nx.conductance(G, part_a, part_b), 4))

# Compare with a naive split of the same size: every other node
naive_a = set(list(G.nodes)[::2])
naive_b = set(G.nodes) - naive_a
print("Edges cut by a naive alternating split:", nx.cut_size(G, naive_a, naive_b))

# -------------------------------
# 2. Neighborhood properties
# -------------------------------

print("\nNeighborhood of selected nodes:")
print(f"{'Node':>4s} {'Degree':>7s} {'Clustering':>11s} {'Avg Nbr Degree':>15s}  Neighbors")

avg_neighbor_degree = nx.average_neighbor_degree(G)

for node in [0, 33, 2, 11]:
    print(f"{node:>4d} {G.degree(node):>7d} {nx.clustering(G, node):>11.4f} "
          f"{avg_neighbor_degree[node]:>15.2f}  {sorted(G.neighbors(node))}")

# Clustering of a node: what fraction of its friends are also friends
# with each other. Node 11 has one friend, so it has no triangles at all.

# Second-order neighborhood: friends of friends
two_hop = nx.single_source_shortest_path_length(G, 0, cutoff=2)
print("\nNodes within 2 steps of node 0:", len([n for n, d in two_hop.items() if d == 2]),
      "at distance 2,", len([n for n, d in two_hop.items() if d == 1]), "at distance 1")

print("\nCommon neighbors of 0 and 33:", sorted(nx.common_neighbors(G, 0, 33)))

# Jaccard coefficient: shared neighbors / all neighbors of the pair.
# Unlinked pairs with a high score are likely future friendships.
# With no pairs given, it scores every pair that is not already linked.
predictions = sorted(nx.jaccard_coefficient(G), key=lambda x: x[2], reverse=True)

print("\nTop 5 likely new links (Jaccard coefficient):")
for u, v, score in predictions[:5]:
    print(f"  {u:2d} - {v:2d}  score: {score:.4f}")

# Ego network: one node, its neighbors, and the edges among them
ego = nx.ego_graph(G, 0, radius=1)
print("\nEgo network of node 0:", ego.number_of_nodes(), "nodes,", ego.number_of_edges(), "edges")

# k-core: the largest subgraph where every node has at least k neighbors
core = nx.k_core(G, k=4)
print("4-core members:", sorted(core.nodes))

fig, axes = plt.subplots(1, 2, figsize=(16, 6.5))

pos = nx.spring_layout(G, seed=42)
colours = ['skyblue' if n in part_a else 'salmon' for n in G.nodes]
inside = [e for e in G.edges if e not in cut_edges]

nx.draw_networkx_nodes(G, pos, ax=axes[0], node_color=colours, node_size=350)
nx.draw_networkx_labels(G, pos, ax=axes[0], font_size=8)
nx.draw_networkx_edges(G, pos, ax=axes[0], edgelist=inside, edge_color='gray', alpha=0.5)
nx.draw_networkx_edges(G, pos, ax=axes[0], edgelist=cut_edges,
                       edge_color='red', style='dashed', width=1.5)
axes[0].set_title(f"Kernighan-Lin Partition ({len(cut_edges)} cut edges in red)")
axes[0].axis('off')

ego_colours = ['gold' if n == 0 else 'lightgreen' for n in ego.nodes]
nx.draw(ego, nx.spring_layout(ego, seed=42), ax=axes[1], with_labels=True,
        node_color=ego_colours, node_size=500, font_size=9, edge_color='gray')
axes[1].set_title("Ego Network of Node 0")

plt.tight_layout()
plt.show()
