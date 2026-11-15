# 29. PCA for feature extraction and dimensionality reduction.

import matplotlib.pyplot as plt
from sklearn.datasets import load_wine
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA

wine = load_wine()
X = StandardScaler().fit_transform(wine.data)
pca = PCA(n_components=2)
X_pca = pca.fit_transform(X)
print("Original Shape:", X.shape, " Reduced Shape:", X_pca.shape)
print("Explained Variance Ratio:", pca.explained_variance_ratio_)

plt.scatter(X_pca[:, 0], X_pca[:, 1], c=wine.target, cmap='viridis')
plt.xlabel("PC1")
plt.ylabel("PC2")
plt.title("PCA of Wine Dataset")
plt.show()

# Output:
# Original Shape: (178, 13)  Reduced Shape: (178, 2)
# Explained Variance Ratio: [0.36198848 0.1920749 ]
