# 29. Write a Python program to implement Principal Component Analysis (PCA) for feature extraction and dimensionality reduction.

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_wine
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression

wine = load_wine()
X, y = wine.data, wine.target

print("Original shape:", X.shape)

# PCA looks for directions of largest variance. Without scaling,
# 'proline' (values in the 1000s) would dominate every component.
X_scaled = StandardScaler().fit_transform(X)

# Fit with all components first, to see how much each one explains
pca_full = PCA().fit(X_scaled)
cumulative = np.cumsum(pca_full.explained_variance_ratio_)

print("\nExplained Variance Ratio:")
for i, (ratio, total) in enumerate(zip(pca_full.explained_variance_ratio_, cumulative), 1):
    print(f"PC{i:<2d}  {ratio:.4f}   cumulative: {total:.4f}")

needed = np.argmax(cumulative >= 0.95) + 1
print(f"\nComponents needed for 95% variance: {needed} (out of {X.shape[1]})")

# PCA can also pick the number of components for a target variance
pca_95 = PCA(n_components=0.95).fit(X_scaled)
print("PCA(n_components=0.95) chose:", pca_95.n_components_)

# Reduce to 2 components
pca = PCA(n_components=2)
X_pca = pca.fit_transform(X_scaled)

print("\nReduced shape:", X_pca.shape)
print("Variance kept by 2 components:", pca.explained_variance_ratio_.sum().round(4))

# Loadings: how much each original feature contributes to each component.
# This is the "feature extraction" - PC1 and PC2 are new features built from these.
loadings = pd.DataFrame(
    pca.components_.T,
    index=wine.feature_names, columns=['PC1', 'PC2']
)

print("\nLoadings:")
print(loadings.round(3))

print("\nTop features in PC1:", list(loadings['PC1'].abs().sort_values(ascending=False).index[:3]))
print("Top features in PC2:", list(loadings['PC2'].abs().sort_values(ascending=False).index[:3]))

# Accuracy with all 13 features vs only 2 principal components
for name, data in [('All 13 features', X_scaled), ('2 principal components', X_pca)]:
    X_train, X_test, y_train, y_test = train_test_split(
        data, y, test_size=0.3, random_state=42, stratify=y
    )
    model = LogisticRegression(max_iter=1000).fit(X_train, y_train)
    print(f"{name:24s} Accuracy: {model.score(X_test, y_test):.4f}")

fig, axes = plt.subplots(1, 2, figsize=(14, 5.5))

# Scree plot
components = range(1, len(cumulative) + 1)
axes[0].bar(components, pca_full.explained_variance_ratio_, label="Individual")
axes[0].step(components, cumulative, where='mid', color='red', label="Cumulative")
axes[0].axhline(0.95, color='gray', linestyle='--', label="95%")
axes[0].set_title("Scree Plot")
axes[0].set_xlabel("Principal Component")
axes[0].set_ylabel("Explained Variance Ratio")
axes[0].legend()

# The data in its first two components
for c, name in enumerate(wine.target_names):
    axes[1].scatter(X_pca[y == c, 0], X_pca[y == c, 1], label=name, alpha=0.7)

axes[1].set_title("Wine Data on the First Two Principal Components")
axes[1].set_xlabel(f"PC1 ({pca.explained_variance_ratio_[0]:.1%} variance)")
axes[1].set_ylabel(f"PC2 ({pca.explained_variance_ratio_[1]:.1%} variance)")
axes[1].legend()

plt.tight_layout()
plt.show()
