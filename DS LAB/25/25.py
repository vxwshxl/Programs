# 25. Write a Python program to compare different clustering algorithms using clustering performance metrics.

import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans, AgglomerativeClustering, DBSCAN
from sklearn.mixture import GaussianMixture
from sklearn.metrics import (silhouette_score, davies_bouldin_score,
                             calinski_harabasz_score, adjusted_rand_score)

# 4 groups with different spreads, so the algorithms do not all agree
X, y_true = make_blobs(
    n_samples=400, centers=4, cluster_std=[0.6, 1.2, 0.8, 1.6], random_state=42
)
X = StandardScaler().fit_transform(X)

print("Dataset shape:", X.shape)

models = {
    'K-Means': KMeans(n_clusters=4, n_init=10, random_state=42),
    'Agglomerative': AgglomerativeClustering(n_clusters=4, linkage='ward'),
    'DBSCAN': DBSCAN(eps=0.25, min_samples=8),
    'Gaussian Mixture': GaussianMixture(n_components=4, random_state=42)
}

# Silhouette         higher is better  (-1 to 1)  - tight, well-separated clusters
# Davies-Bouldin     lower is better   (0 and up) - average similarity to nearest cluster
# Calinski-Harabasz  higher is better  (0 and up) - between vs within cluster spread
# Adjusted Rand      higher is better  (-1 to 1)  - agreement with the true labels.
#                    Only usable here because make_blobs gives us the answer.
results = []
all_labels = {}

for name, model in models.items():
    labels = model.fit_predict(X)
    all_labels[name] = labels

    # DBSCAN labels outliers as -1. They are left out of the scores,
    # which flatters DBSCAN a little - it gets to skip the hardest points
    mask = labels != -1

    results.append({
        'Algorithm': name,
        'Clusters': len(set(labels[mask])),
        'Noise Points': int((~mask).sum()),
        'Silhouette': silhouette_score(X[mask], labels[mask]),
        'Davies-Bouldin': davies_bouldin_score(X[mask], labels[mask]),
        'Calinski-Harabasz': calinski_harabasz_score(X[mask], labels[mask]),
        'Adjusted Rand': adjusted_rand_score(y_true, labels)
    })

results = pd.DataFrame(results)

print("\nClustering Comparison:")
print(results.round(4).to_string(index=False))

print("\nBest by each metric:")
print("Silhouette        :", results.loc[results['Silhouette'].idxmax(), 'Algorithm'])
print("Davies-Bouldin    :", results.loc[results['Davies-Bouldin'].idxmin(), 'Algorithm'])
print("Calinski-Harabasz :", results.loc[results['Calinski-Harabasz'].idxmax(), 'Algorithm'])
print("Adjusted Rand     :", results.loc[results['Adjusted Rand'].idxmax(), 'Algorithm'])

# One scatter per algorithm, plus the true groups for reference
fig, axes = plt.subplots(1, 5, figsize=(22, 4.5))

axes[0].scatter(X[:, 0], X[:, 1], c=y_true, cmap='viridis', s=15)
axes[0].set_title("True Groups")

for ax, (name, labels) in zip(axes[1:], all_labels.items()):
    ax.scatter(X[:, 0], X[:, 1], c=labels, cmap='viridis', s=15)

    # DBSCAN noise points in red
    noise = labels == -1
    if noise.any():
        ax.scatter(X[noise, 0], X[noise, 1], c='red', marker='x', s=20, label="Noise")
        ax.legend()

    score = results.loc[results['Algorithm'] == name, 'Silhouette'].iloc[0]
    ax.set_title(f"{name}\nSilhouette = {score:.3f}")

for ax in axes:
    ax.set_xticks([])
    ax.set_yticks([])

plt.tight_layout()
plt.show()
