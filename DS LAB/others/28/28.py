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

# Output:
# Singular Values: [5.7605 3.2422 2.7027]
# Rank-2 Approximation:
#  [[ 1.9225  0.3353  2.0951]
#  [-0.9314  3.0423  0.9303]
#  [ 1.5023  1.693   2.5058]
#  [ 2.2701  0.7835  2.7092]]
#
# Original Shape: (1797, 64)
# Reduced Shape: (1797, 20)
# Variance Kept: 0.8940622384867832
