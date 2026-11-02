# 28. Write a Python program to implement Singular Value Decomposition (SVD) for dimensionality reduction.

import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_digits
from sklearn.decomposition import TruncatedSVD
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression

# -------------------------------
# 1. SVD by hand on a small matrix
# -------------------------------

# Any matrix A can be split into A = U * S * V^T
A = np.array([
    [3, 1, 1],
    [-1, 3, 1],
    [2, 2, 2],
    [1, 0, 4]
], dtype=float)

U, S, Vt = np.linalg.svd(A, full_matrices=False)

print("Original Matrix A:")
print(A)
print("\nU (left singular vectors):")
print(U.round(4))
print("\nSingular Values S:")
print(S.round(4))
print("\nV^T (right singular vectors):")
print(Vt.round(4))

print("\nA rebuilt from U * S * V^T:")
print((U @ np.diag(S) @ Vt).round(4))

# Keep only the largest k singular values: a smaller, approximate A
k = 2
A_k = U[:, :k] @ np.diag(S[:k]) @ Vt[:k, :]

print(f"\nRank-{k} approximation of A:")
print(A_k.round(4))
print("Approximation error:", np.linalg.norm(A - A_k).round(4))

# -------------------------------
# 2. SVD for dimensionality reduction on real data
# -------------------------------

# 1797 handwritten digits, each an 8x8 image = 64 features
digits = load_digits()
X, y = digits.data, digits.target

print("\nDigits dataset shape:", X.shape)

svd_full = TruncatedSVD(n_components=63, random_state=42).fit(X)
cumulative = np.cumsum(svd_full.explained_variance_ratio_)

for target in [0.80, 0.90, 0.95]:
    needed = np.argmax(cumulative >= target) + 1
    print(f"Components needed for {int(target * 100)}% variance: {needed}")

# Reduce 64 features to 20
svd = TruncatedSVD(n_components=20, random_state=42)
X_reduced = svd.fit_transform(X)

print("\nReduced shape:", X_reduced.shape)
print("Variance kept with 20 components:", svd.explained_variance_ratio_.sum().round(4))

# Does a classifier still work on the smaller data?
for name, data in [('All 64 features', X), ('20 SVD components', X_reduced)]:
    X_train, X_test, y_train, y_test = train_test_split(
        data, y, test_size=0.3, random_state=42, stratify=y
    )
    model = LogisticRegression(max_iter=5000).fit(X_train, y_train)
    print(f"{name:18s} Accuracy: {model.score(X_test, y_test):.4f}")

# What an image looks like when rebuilt from fewer components
image = X[0:1]
rebuilt = {}

for n in [2, 10, 20, 40]:
    model = TruncatedSVD(n_components=n, random_state=42).fit(X)
    rebuilt[n] = model.inverse_transform(model.transform(image))

fig = plt.figure(figsize=(15, 8))

ax1 = fig.add_subplot(2, 2, 1)
ax1.plot(range(1, 64), cumulative, marker='.')
ax1.axhline(0.90, color='red', linestyle='--', label="90% variance")
ax1.set_title("Cumulative Explained Variance (SVD)")
ax1.set_xlabel("Number of components")
ax1.set_ylabel("Variance explained")
ax1.legend()

ax2 = fig.add_subplot(2, 2, 2)
two_d = TruncatedSVD(n_components=2, random_state=42).fit_transform(X)
scatter = ax2.scatter(two_d[:, 0], two_d[:, 1], c=y, cmap='tab10', s=8)
fig.colorbar(scatter, ax=ax2, label="Digit")
ax2.set_title("Digits in 2 SVD Components")
ax2.set_xlabel("Component 1")
ax2.set_ylabel("Component 2")

# Original image next to its rebuilt versions
images = [('Original (64)', image)] + [(f"{n} components", r) for n, r in rebuilt.items()]

for i, (title, img) in enumerate(images):
    ax = fig.add_subplot(2, 5, 6 + i)
    ax.imshow(img.reshape(8, 8), cmap='gray_r')
    ax.set_title(title)
    ax.axis('off')

plt.tight_layout()
plt.show()
