# 24. Write a Python program to implement Hierarchical Clustering and visualize the dendrogram.

import matplotlib.pyplot as plt
from scipy.cluster.hierarchy import linkage, dendrogram, fcluster
from sklearn.datasets import make_blobs

X, _ = make_blobs(n_samples=50, centers=3, cluster_std=2.5, random_state=7)
Z = linkage(X, method='ward')
print("Cluster labels:", fcluster(Z, t=3, criterion='maxclust'))

dendrogram(Z)
plt.title("Hierarchical Clustering Dendrogram")
plt.xlabel("Sample index")
plt.ylabel("Distance")
plt.show()

# Output:
# Cluster labels: [3 1 3 2 3 3 3 1 2 1 3 1 2 2 3 2 3 3 2 1 3 3 1 2 3 3 3 3 1 3 1 2 1 2 3 3 1
#  3 2 3 1 3 2 1 3 1 3 1 1 1]
