# 23. Write a Python program to implement K-Means clustering.

import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score

# 300 points around 4 hidden centres. K-Means never sees the true labels.
X, y_true = make_blobs(n_samples=300, centers=4, cluster_std=0.8, random_state=42)

print("Dataset shape:", X.shape)

# Elbow method: inertia (sum of squared distances to the nearest centroid)
# always drops as k grows - look for where the drop slows down
k_values = range(1, 11)
inertias = []

for k in k_values:
    model = KMeans(n_clusters=k, n_init=10, random_state=42).fit(X)
    inertias.append(model.inertia_)

print("\nElbow Method:")
for k, inertia in zip(k_values, inertias):
    print(f"k = {k:2d}  Inertia: {inertia:.2f}")

# Silhouette score: close to 1 means points sit well inside their cluster
print("\nSilhouette Scores:")
for k in range(2, 11):
    labels = KMeans(n_clusters=k, n_init=10, random_state=42).fit_predict(X)
    print(f"k = {k:2d}  Silhouette: {silhouette_score(X, labels):.4f}")

# Fit the final model with k = 4
kmeans = KMeans(n_clusters=4, n_init=10, random_state=42)
labels = kmeans.fit_predict(X)

print("\nCluster Centres:")
print(kmeans.cluster_centers_)

print("\nPoints per cluster:", np.bincount(labels))
print("Inertia:", kmeans.inertia_)
print("Silhouette Score:", silhouette_score(X, labels))
print("Iterations to converge:", kmeans.n_iter_)

# Assign new points to the nearest centroid
new_points = [[0, 5], [-8, -6]]
print("\nNew points:", new_points)
print("Assigned clusters:", kmeans.predict(new_points))

fig, axes = plt.subplots(1, 2, figsize=(13, 5))

axes[0].plot(k_values, inertias, marker='o')
axes[0].axvline(4, color='red', linestyle='--', label="Elbow at k = 4")
axes[0].set_title("Elbow Method")
axes[0].set_xlabel("Number of clusters (k)")
axes[0].set_ylabel("Inertia")
axes[0].legend()

axes[1].scatter(X[:, 0], X[:, 1], c=labels, cmap='viridis', alpha=0.7)
axes[1].scatter(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1],
                c='red', marker='X', s=250, label="Centroids")
axes[1].set_title("K-Means Clusters (k = 4)")
axes[1].set_xlabel("Feature 1")
axes[1].set_ylabel("Feature 2")
axes[1].legend()

plt.tight_layout()
plt.show()
