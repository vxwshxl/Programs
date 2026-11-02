# 14. Write a Python program to perform model selection using train-test split and cross-validation techniques.

import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_classification
from sklearn.model_selection import (train_test_split, cross_val_score,
                                     StratifiedKFold, GridSearchCV)
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier

# Synthetic dataset: 500 samples, 8 features, 2 classes
X, y = make_classification(
    n_samples=500, n_features=8, n_informative=5,
    n_redundant=2, random_state=42
)

print("Dataset shape:", X.shape)
print("Samples per class:", np.bincount(y))

# -------------------------------
# 1. Train-test split
# -------------------------------

# stratify=y keeps the class ratio the same in both sets
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25, random_state=42, stratify=y
)

print("\nTraining samples:", len(X_train))
print("Testing samples:", len(X_test))

# Scaling is inside each pipeline, so it is learned from the training
# folds only and never sees the data it is tested on
models = {
    'Logistic Regression': make_pipeline(StandardScaler(), LogisticRegression()),
    'kNN': make_pipeline(StandardScaler(), KNeighborsClassifier()),
    'Decision Tree': DecisionTreeClassifier(random_state=42)
}

print("\nTrain-Test Split Accuracy:")

for name, model in models.items():
    model.fit(X_train, y_train)
    train_acc = model.score(X_train, y_train)
    test_acc = model.score(X_test, y_test)
    print(f"{name:20s} Train: {train_acc:.4f}  Test: {test_acc:.4f}")

# -------------------------------
# 2. K-Fold cross-validation
# -------------------------------

# One split can be lucky or unlucky. Five folds give five scores,
# so we see both the average and how much it moves around.
cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=42)

cv_scores = {}

print("\n5-Fold Cross-Validation Accuracy:")

for name, model in models.items():
    scores = cross_val_score(model, X_train, y_train, cv=cv)
    cv_scores[name] = scores
    print(f"{name:20s} Folds: {np.round(scores, 3)}  "
          f"Mean: {scores.mean():.4f}  Std: {scores.std():.4f}")

best_name = max(cv_scores, key=lambda name: cv_scores[name].mean())
print("\nBest model by cross-validation:", best_name)

# -------------------------------
# 3. Choosing a hyperparameter with GridSearchCV
# -------------------------------

# Try k = 1 to 30 for kNN, scoring each with the same 5 folds
param_grid = {'kneighborsclassifier__n_neighbors': range(1, 31)}

grid = GridSearchCV(
    make_pipeline(StandardScaler(), KNeighborsClassifier()),
    param_grid, cv=cv
)
grid.fit(X_train, y_train)

best_k = grid.best_params_['kneighborsclassifier__n_neighbors']

print("\nBest k for kNN:", best_k)
print("Best CV accuracy:", grid.best_score_)

# The test set is used once, at the very end, on the chosen model
print("Test accuracy with best k:", grid.score(X_test, y_test))

# -------------------------------
# 4. Plot both results together
# -------------------------------

fig, axes = plt.subplots(1, 2, figsize=(13, 5))

# Spread of fold scores for each model
axes[0].boxplot(list(cv_scores.values()), tick_labels=list(cv_scores.keys()))
axes[0].set_title("5-Fold CV Accuracy per Model")
axes[0].set_ylabel("Accuracy")

# CV accuracy for every k tried
k_values = list(param_grid['kneighborsclassifier__n_neighbors'])
mean_scores = grid.cv_results_['mean_test_score']

axes[1].plot(k_values, mean_scores, marker='o')
axes[1].axvline(best_k, color='red', linestyle='--', label=f"Best k = {best_k}")
axes[1].set_title("kNN: Choosing k with Cross-Validation")
axes[1].set_xlabel("k (number of neighbors)")
axes[1].set_ylabel("Mean CV Accuracy")
axes[1].legend()

plt.tight_layout()
plt.show()
