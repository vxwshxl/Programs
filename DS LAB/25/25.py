# 25. Write a Python program to compare different clustering algorithms using clustering performance metrics.

from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans, AgglomerativeClustering
from sklearn.mixture import GaussianMixture
from sklearn.metrics import silhouette_score, davies_bouldin_score

X, _ = make_blobs(n_samples=400, centers=4, cluster_std=[0.6, 1.2, 0.8, 1.6], random_state=42)

models = {'K-Means': KMeans(n_clusters=4, n_init=10, random_state=42),
          'Agglomerative': AgglomerativeClustering(n_clusters=4),
          'Gaussian Mixture': GaussianMixture(n_components=4, random_state=42)}
for name, m in models.items():
    labels = m.fit_predict(X)
    print(f"{name:16s} Silhouette: {silhouette_score(X, labels):.4f}  Davies-Bouldin: {davies_bouldin_score(X, labels):.4f}")

# Output:
# K-Means          Silhouette: 0.7821  Davies-Bouldin: 0.3085
# Agglomerative    Silhouette: 0.7820  Davies-Bouldin: 0.3093
# Gaussian Mixture Silhouette: 0.7751  Davies-Bouldin: 0.3142
