# 16. Write a Python program to implement the k-Nearest Neighbors (kNN) classification algorithm.

import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import (accuracy_score, confusion_matrix,
                             classification_report, ConfusionMatrixDisplay)

iris = load_iris()
X, y = iris.data, iris.target

print("Features:", iris.feature_names)
print("Classes:", iris.target_names.tolist())

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=42, stratify=y
)

# kNN measures distance, so features must be on the same scale
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# Train with k = 5
knn = KNeighborsClassifier(n_neighbors=5)
knn.fit(X_train_scaled, y_train)

y_pred = knn.predict(X_test_scaled)

print("\nAccuracy (k = 5):", accuracy_score(y_test, y_pred))

print("\nConfusion Matrix:")
print(confusion_matrix(y_test, y_pred))

print("\nClassification Report:")
print(classification_report(y_test, y_pred, target_names=iris.target_names))

# Try every k from 1 to 25. Small k follows the noise (overfits),
# large k smooths too much (underfits).
k_values = range(1, 26)
train_scores = []
test_scores = []

for k in k_values:
    model = KNeighborsClassifier(n_neighbors=k).fit(X_train_scaled, y_train)
    train_scores.append(model.score(X_train_scaled, y_train))
    test_scores.append(model.score(X_test_scaled, y_test))

best_k = k_values[int(np.argmax(test_scores))]
print("Best k on the test set:", best_k)

# Classify a new flower
new_flower = [[5.1, 3.5, 1.4, 0.2]]
prediction = knn.predict(scaler.transform(new_flower))[0]

print("\nNew flower:", new_flower[0])
print("Predicted species:", iris.target_names[prediction])

# Accuracy for each k, and the confusion matrix for k = 5
fig, axes = plt.subplots(1, 2, figsize=(13, 5))

axes[0].plot(k_values, train_scores, marker='o', label="Training Accuracy")
axes[0].plot(k_values, test_scores, marker='s', label="Testing Accuracy")
axes[0].set_title("kNN Accuracy vs k")
axes[0].set_xlabel("k (number of neighbors)")
axes[0].set_ylabel("Accuracy")
axes[0].legend()

ConfusionMatrixDisplay.from_predictions(
    y_test, y_pred, display_labels=iris.target_names,
    ax=axes[1], cmap='Blues', colorbar=False
)
axes[1].set_title("Confusion Matrix (k = 5)")

plt.tight_layout()
plt.show()
