# 20. Write a Python program to implement Naive Bayes classification.

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.stats import norm
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import (accuracy_score, confusion_matrix,
                             classification_report, ConfusionMatrixDisplay)

iris = load_iris()
X, y = iris.data, iris.target

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=42, stratify=y
)

# Gaussian Naive Bayes assumes every feature is normally distributed
# within each class, and that features are independent of each other
nb = GaussianNB()
nb.fit(X_train, y_train)

y_pred = nb.predict(X_test)

# P(class) learned from the training data
print("Class Priors:")
for name, prior in zip(iris.target_names, nb.class_prior_):
    print(f"{name:12s} {prior:.4f}")

# The mean of each feature within each class
print("\nFeature Means per Class:")
print(pd.DataFrame(nb.theta_, index=iris.target_names, columns=iris.feature_names))

print("\nAccuracy:", accuracy_score(y_test, y_pred))

print("\nConfusion Matrix:")
print(confusion_matrix(y_test, y_pred))

print("\nClassification Report:")
print(classification_report(y_test, y_pred, target_names=iris.target_names))

# Naive Bayes gives a probability for each class, not just a label
print("Predicted probabilities for the first 5 test flowers:")
probabilities = pd.DataFrame(nb.predict_proba(X_test[:5]).round(4),
                             columns=iris.target_names)
probabilities['Predicted'] = iris.target_names[y_pred[:5]]
probabilities['Actual'] = iris.target_names[y_test[:5]]
print(probabilities)

fig, axes = plt.subplots(1, 2, figsize=(13, 5))

ConfusionMatrixDisplay.from_predictions(
    y_test, y_pred, display_labels=iris.target_names,
    ax=axes[0], cmap='Blues', colorbar=False
)
axes[0].set_title("Confusion Matrix")

# The bell curve the model learned for petal length (feature 2) in each class
feature = 2
x = np.linspace(X[:, feature].min() - 1, X[:, feature].max() + 1, 300)

for c, name in enumerate(iris.target_names):
    mean = nb.theta_[c, feature]
    std = np.sqrt(nb.var_[c, feature])
    axes[1].plot(x, norm.pdf(x, mean, std), label=name)
    axes[1].hist(X_train[y_train == c, feature], bins=10, density=True, alpha=0.3)

axes[1].set_title("Learned Gaussian for Petal Length per Class")
axes[1].set_xlabel("Petal length (cm)")
axes[1].set_ylabel("Density")
axes[1].legend()

plt.tight_layout()
plt.show()
