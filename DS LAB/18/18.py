# 18. Write a Python program to implement Support Vector Machine (SVM) classification.

import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.inspection import DecisionBoundaryDisplay
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report

iris = load_iris()
X, y = iris.data, iris.target

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=42, stratify=y
)

# SVM finds the widest margin between classes, measured in distance,
# so features must be scaled
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# Train an SVM with the RBF kernel
svm = SVC(kernel='rbf', C=1.0, gamma='scale')
svm.fit(X_train_scaled, y_train)

y_pred = svm.predict(X_test_scaled)

print("Accuracy (RBF kernel):", accuracy_score(y_test, y_pred))
print("Support vectors per class:", svm.n_support_)

print("\nConfusion Matrix:")
print(confusion_matrix(y_test, y_pred))

print("\nClassification Report:")
print(classification_report(y_test, y_pred, target_names=iris.target_names))

# Compare the common kernels
kernels = ['linear', 'poly', 'rbf']

print("Kernel Comparison:")

for kernel in kernels:
    model = SVC(kernel=kernel).fit(X_train_scaled, y_train)
    print(f"{kernel:8s} Accuracy: {model.score(X_test_scaled, y_test):.4f}")

# To draw the decision boundary we need 2D, so use only
# petal length and petal width (columns 2 and 3)
X_2d = scaler.fit_transform(X[:, 2:4])

fig, axes = plt.subplots(1, 3, figsize=(17, 5))

for ax, kernel in zip(axes, kernels):
    model = SVC(kernel=kernel).fit(X_2d, y)

    DecisionBoundaryDisplay.from_estimator(
        model, X_2d, response_method='predict',
        alpha=0.3, cmap='viridis', ax=ax
    )
    ax.scatter(X_2d[:, 0], X_2d[:, 1], c=y, cmap='viridis', edgecolor='k')

    # Circle the support vectors - the only points that define the boundary
    ax.scatter(model.support_vectors_[:, 0], model.support_vectors_[:, 1],
               s=120, facecolors='none', edgecolors='red',
               label="Support Vectors")

    ax.set_title(f"SVM - {kernel} kernel")
    ax.set_xlabel("Petal length (scaled)")
    ax.set_ylabel("Petal width (scaled)")
    ax.legend(loc='upper left')

plt.tight_layout()
plt.show()
