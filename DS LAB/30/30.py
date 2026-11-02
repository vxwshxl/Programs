# 30. Write a Python program to compare the performance of PCA and SVD on a given dataset.

import time
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_digits
from sklearn.decomposition import PCA, TruncatedSVD
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression

# 1797 digit images, 64 pixel features each
digits = load_digits()
X, y = digits.data, digits.target

print("Dataset shape:", X.shape)

# The one real difference: PCA subtracts the mean of each feature first,
# TruncatedSVD works on the data as it is. Pixel values are never centred,
# so the two give different results here.
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=42, stratify=y
)

component_counts = [2, 5, 10, 15, 20, 30, 40]
results = []

for n in component_counts:
    for name, reducer in [('PCA', PCA(n_components=n, random_state=42)),
                          ('SVD', TruncatedSVD(n_components=n, random_state=42))]:
        start = time.perf_counter()
        reducer.fit(X_train)
        fit_time = time.perf_counter() - start

        train_reduced = reducer.transform(X_train)
        test_reduced = reducer.transform(X_test)

        # How much information is lost when going down and back up
        rebuilt = reducer.inverse_transform(test_reduced)
        error = np.mean((X_test - rebuilt) ** 2)

        model = LogisticRegression(max_iter=5000).fit(train_reduced, y_train)

        results.append({
            'Components': n,
            'Method': name,
            'Variance Explained': reducer.explained_variance_ratio_.sum(),
            'Reconstruction MSE': error,
            'Accuracy': model.score(test_reduced, y_test),
            'Fit Time (ms)': fit_time * 1000
        })

results = pd.DataFrame(results)

print("\nPCA vs SVD:")
print(results.round(4).to_string(index=False))

# Side-by-side accuracy table
print("\nAccuracy by number of components:")
print(results.pivot(index='Components', columns='Method', values='Accuracy').round(4))

# Proof that the difference is only the centring step:
# SVD on mean-centred data gives the same components as PCA
X_centered = X_train - X_train.mean(axis=0)
pca = PCA(n_components=10).fit(X_train)
svd = TruncatedSVD(n_components=10, algorithm='arpack').fit(X_centered)

same = np.allclose(np.abs(pca.components_), np.abs(svd.components_), atol=1e-6)
print("\nSVD on centred data matches PCA:", same)

fig, axes = plt.subplots(1, 3, figsize=(18, 5))

for name, marker in [('PCA', 'o'), ('SVD', 's')]:
    subset = results[results['Method'] == name]
    axes[0].plot(subset['Components'], subset['Variance Explained'], marker=marker, label=name)
    axes[1].plot(subset['Components'], subset['Reconstruction MSE'], marker=marker, label=name)
    axes[2].plot(subset['Components'], subset['Accuracy'], marker=marker, label=name)

titles = ["Variance Explained", "Reconstruction Error (MSE)", "Classification Accuracy"]

for ax, title in zip(axes, titles):
    ax.set_title(title)
    ax.set_xlabel("Number of components")
    ax.legend()

plt.tight_layout()
plt.show()
