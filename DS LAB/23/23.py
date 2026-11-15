# 23. Write a Python program to implement K-Means clustering.

import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans

X, _ = make_blobs(n_samples=300, centers=4, cluster_std=0.8, random_state=42)
kmeans = KMeans(n_clusters=4, n_init=10, random_state=42)
labels = kmeans.fit_predict(X)
print("Cluster Centres:\n", kmeans.cluster_centers_)

plt.scatter(X[:, 0], X[:, 1], c=labels, cmap='viridis')
plt.scatter(*kmeans.cluster_centers_.T, c='red', marker='X', s=200)
plt.title("K-Means Clustering")
plt.show()
