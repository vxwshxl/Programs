# 36. Write a Python program to perform graph partitioning and analyze neighborhood properties.

import networkx as nx
from networkx.algorithms.community import kernighan_lin_bisection

G = nx.karate_club_graph()

A, B = kernighan_lin_bisection(G, seed=42)
print("Partition A:", sorted(A))
print("Partition B:", sorted(B))
print("Edges cut:", nx.cut_size(G, A, B))

node = 0
print(f"\nNeighbors of node {node}:", sorted(G.neighbors(node)))
print(f"Degree of node {node}:", G.degree(node))
print(f"Clustering Coefficient of node {node}:", nx.clustering(G, node))
