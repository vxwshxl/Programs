# 35. Write a Python program to detect communities in a social network graph.

import networkx as nx
from networkx.algorithms.community import greedy_modularity_communities

G = nx.karate_club_graph()
communities = list(greedy_modularity_communities(G))

print(f"Detected {len(communities)} communities:")
for i, comm in enumerate(communities, 1):
    print(f"Community {i}: {sorted(comm)}")

# Output:
# Detected 3 communities:
# Community 1: [8, 14, 15, 18, 20, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33]
# Community 2: [1, 2, 3, 7, 9, 12, 13, 17, 21]
# Community 3: [0, 4, 5, 6, 10, 11, 16, 19]
