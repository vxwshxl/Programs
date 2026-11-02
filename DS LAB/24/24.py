# 24. Write a Python program to implement Hierarchical Clustering and visualize the dendrogram.

import numpy as np
import matplotlib.pyplot as plt
from scipy.cluster.hierarchy import linkage, dendrogram, fcluster
from sklearn.datasets import make_blobs
from sklearn.cluster import AgglomerativeClustering
from sklearn.metrics import silhouette_score

# A small dataset keeps the dendrogram readable
X, y_true = make_blobs(n_samples=50, centers=3, cluster_std=2.5, random_state=7)

print("Dataset shape:", X.shape)

# Agglomerative (bottom-up): every point starts as its own cluster,
# then the two closest clusters are merged, again and again.
# 'ward' merges the pair that increases total variance the least.
Z = linkage(X, method='ward')

# Each row of Z is one merge: [cluster a, cluster b, distance, size]
print("\nFirst 5 merges:")
print(Z[:5].round(3))
print("\nLast 3 merges (the big jumps):")
print(Z[-3:].round(3))

# Cut the tree into 3 clusters
labels_scipy = fcluster(Z, t=3, criterion='maxclust')
print("\nPoints per cluster (SciPy):", np.bincount(labels_scipy)[1:])

# The same thing with Scikit-learn
model = AgglomerativeClustering(n_clusters=3, linkage='ward')
labels = model.fit_predict(X)

print("Points per cluster (Scikit-learn):", np.bincount(labels))
print("Silhouette Score:", silhouette_score(X, labels))

# The linkage rule decides what "closest clusters" means
print("\nLinkage Comparison:")
for method in ['ward', 'complete', 'average', 'single']:
    result = AgglomerativeClustering(n_clusters=3, linkage=method).fit_predict(X)
    print(f"{method:9s} Silhouette: {silhouette_score(X, result):.4f}")

# A horizontal cut between the last two merges gives 3 clusters
cut_height = (Z[-3, 2] + Z[-2, 2]) / 2

fig, axes = plt.subplots(1, 2, figsize=(15, 6))

dendrogram(Z, ax=axes[0], color_threshold=cut_height)
axes[0].axhline(cut_height, color='red', linestyle='--', label="Cut for 3 clusters")
axes[0].set_title("Dendrogram (Ward linkage)")
axes[0].set_xlabel("Sample index")
axes[0].set_ylabel("Merge distance")
axes[0].legend()

axes[1].scatter(X[:, 0], X[:, 1], c=labels, cmap='viridis', s=60)
axes[1].set_title("Hierarchical Clusters (k = 3)")
axes[1].set_xlabel("Feature 1")
axes[1].set_ylabel("Feature 2")

plt.tight_layout()
plt.show()
