# 38. Write a Python program to visualize multidimensional datasets using pair plots and dimensionality reduction techniques.

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import load_iris
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
from sklearn.manifold import TSNE

# 4 features per flower - too many dimensions to draw in one plot
iris = load_iris(as_frame=True)
df = iris.frame
df['species'] = iris.target_names[iris.target]

print("Dataset shape:", iris.data.shape)
print(df.head().to_string())

print("\nCorrelation between features:")
print(iris.data.corr().round(3).to_string())

# -------------------------------
# 1. Pair plot: every feature against every other feature
# -------------------------------

# 4 features give a 4 x 4 grid. The diagonal shows each feature on its own.
pair = sns.pairplot(df.drop(columns='target'), hue='species', height=2.2)
pair.figure.suptitle("Iris Pair Plot", y=1.02)

# -------------------------------
# 2. Dimensionality reduction: squeeze 4 dimensions into 2
# -------------------------------

X_scaled = StandardScaler().fit_transform(iris.data)

# PCA: linear, keeps the directions of largest variance
pca = PCA(n_components=2)
X_pca = pca.fit_transform(X_scaled)

print("\nPCA explained variance:", pca.explained_variance_ratio_.round(4))
print("Total variance kept:", pca.explained_variance_ratio_.sum().round(4))

# t-SNE: non-linear, keeps points that were close together still close
tsne = TSNE(n_components=2, perplexity=30, random_state=42)
X_tsne = tsne.fit_transform(X_scaled).astype(float)

print("t-SNE final KL divergence:", round(tsne.kl_divergence_, 4))

reduced = pd.DataFrame({
    'PC1': X_pca[:, 0], 'PC2': X_pca[:, 1],
    'TSNE1': X_tsne[:, 0], 'TSNE2': X_tsne[:, 1],
    'species': df['species']
})

print("\nFirst 5 rows in reduced form:")
print(reduced.head().round(3).to_string())

fig, axes = plt.subplots(1, 2, figsize=(14, 5.5))

sns.scatterplot(data=reduced, x='PC1', y='PC2', hue='species', ax=axes[0])
axes[0].set_title(f"PCA ({pca.explained_variance_ratio_.sum():.1%} variance kept)")

sns.scatterplot(data=reduced, x='TSNE1', y='TSNE2', hue='species', ax=axes[1])
axes[1].set_title("t-SNE")

plt.tight_layout()

# Both figures (the pair plot and the reduction plots) open together
plt.show()
