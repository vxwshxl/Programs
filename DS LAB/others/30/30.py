# 30. Compare PCA and SVD on a dataset.

import time
from sklearn.datasets import load_digits
from sklearn.decomposition import PCA, TruncatedSVD

X = load_digits().data

for name, model in [('PCA', PCA(n_components=10)), ('SVD', TruncatedSVD(n_components=10, random_state=42))]:
    start = time.time()
    model.fit_transform(X)
    t = time.time() - start
    print(f"{name} Time: {t:.5f}s | Explained Var: {model.explained_variance_ratio_.sum():.4f}")

# Output:
# PCA Time: 0.00221s | Explained Var: 0.7382
# SVD Time: 0.00156s | Explained Var: 0.7324
