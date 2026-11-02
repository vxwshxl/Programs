# 21. Write a Python program to implement Logistic Regression for binary classification.

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import (accuracy_score, confusion_matrix, classification_report,
                             roc_auc_score, ConfusionMatrixDisplay)

# Two classes: 0 = malignant, 1 = benign
data = load_breast_cancer()
X, y = data.data, data.target

print("Dataset shape:", X.shape)
print("Samples per class:", dict(zip(data.target_names, np.bincount(y))))

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25, random_state=42, stratify=y
)

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# Logistic regression: z = w.x + b, then P(class 1) = 1 / (1 + e^-z)
model = LogisticRegression(max_iter=1000)
model.fit(X_train_scaled, y_train)

y_pred = model.predict(X_test_scaled)
y_prob = model.predict_proba(X_test_scaled)[:, 1]

print("\nIntercept (b):", model.intercept_[0])

# Biggest weights in either direction. Negative pushes towards
# malignant (0), positive pushes towards benign (1).
coefficients = pd.DataFrame({
    'Feature': data.feature_names,
    'Coefficient': model.coef_[0]
})
coefficients = coefficients.reindex(
    coefficients['Coefficient'].abs().sort_values(ascending=False).index
)

print("\nTop 5 most influential features:")
print(coefficients.head().to_string(index=False))

print("\nAccuracy:", accuracy_score(y_test, y_pred))
print("ROC-AUC:", roc_auc_score(y_test, y_prob))

print("\nConfusion Matrix:")
print(confusion_matrix(y_test, y_pred))

print("\nClassification Report:")
print(classification_report(y_test, y_pred, target_names=data.target_names))

# Predict one new sample (the first test row)
sample = X_test_scaled[:1]
print("Prediction for one sample:", data.target_names[model.predict(sample)[0]])
print("Probability of benign:", model.predict_proba(sample)[0, 1])

fig, axes = plt.subplots(1, 2, figsize=(13, 5))

# Every test sample on the sigmoid curve: z on the x-axis,
# predicted probability on the y-axis, coloured by its true class
z = model.decision_function(X_test_scaled)
z_line = np.linspace(z.min(), z.max(), 300)

axes[0].plot(z_line, 1 / (1 + np.exp(-z_line)), color='black', label="Sigmoid")
axes[0].scatter(z[y_test == 0], y_prob[y_test == 0], color='red', alpha=0.6, label="Malignant")
axes[0].scatter(z[y_test == 1], y_prob[y_test == 1], color='green', alpha=0.6, label="Benign")
axes[0].axhline(0.5, color='gray', linestyle='--', label="Threshold 0.5")
axes[0].set_title("Logistic (Sigmoid) Function")
axes[0].set_xlabel("z = w.x + b")
axes[0].set_ylabel("P(benign)")
axes[0].legend()

ConfusionMatrixDisplay.from_predictions(
    y_test, y_pred, display_labels=data.target_names,
    ax=axes[1], cmap='Blues', colorbar=False
)
axes[1].set_title("Confusion Matrix")

plt.tight_layout()
plt.show()
