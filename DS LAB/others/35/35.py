# 35. Write a Python program to detect communities in a social network graph.

import networkx as nx
from networkx.algorithms.community import greedy_modularity_communities

G = nx.karate_club_graph()
communities = list(greedy_modularity_communities(G))

print(f"Detected {len(communities)} communities:")
for i, comm in enumerate(communities, 1):
    print(f"Community {i}: {sorted(comm)}")
