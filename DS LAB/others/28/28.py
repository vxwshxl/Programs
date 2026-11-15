# 28. Write a Python program to implement Singular Value Decomposition (SVD) for dimensionality reduction.

import numpy as np
from sklearn.datasets import load_digits
from sklearn.decomposition import TruncatedSVD

A = np.array([[3, 1, 1], [-1, 3, 1], [2, 2, 2], [1, 0, 4]], dtype=float)
U, S, Vt = np.linalg.svd(A, full_matrices=False)
print("Singular Values:", S.round(4))
print("Rank-2 Approximation:\n", (U[:, :2] @ np.diag(S[:2]) @ Vt[:2]).round(4))

X = load_digits().data
svd = TruncatedSVD(n_components=20, random_state=42)
X_reduced = svd.fit_transform(X)
print("\nOriginal Shape:", X.shape)
print("Reduced Shape:", X_reduced.shape)
print("Variance Kept:", svd.explained_variance_ratio_.sum())
