# 15. Write a Python program to evaluate machine learning models using confusion matrix, accuracy, precision, recall, F1-score, and ROC-AUC.

import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import (confusion_matrix, accuracy_score, precision_score,
                             recall_score, f1_score, roc_auc_score, roc_curve,
                             classification_report, ConfusionMatrixDisplay)

# Built-in dataset: 569 tumours, 30 measurements each
data = load_breast_cancer()
X, y = data.data, data.target

print("Dataset shape:", X.shape)
print("Classes:", data.target_names.tolist())   # 0 = malignant, 1 = benign

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25, random_state=42, stratify=y
)

model = make_pipeline(StandardScaler(), LogisticRegression(max_iter=1000))
model.fit(X_train, y_train)

# Hard predictions (0 or 1) and the probability of class 1
y_pred = model.predict(X_test)
y_prob = model.predict_proba(X_test)[:, 1]

# -------------------------------
# 1. Confusion matrix
# -------------------------------

cm = confusion_matrix(y_test, y_pred)
tn, fp, fn, tp = cm.ravel()

print("\nConfusion Matrix:")
print(cm)
print(f"\nTrue Negatives : {tn}")
print(f"False Positives: {fp}")
print(f"False Negatives: {fn}")
print(f"True Positives : {tp}")

# -------------------------------
# 2. Metrics built from the confusion matrix
# -------------------------------

# Accuracy  = (TP + TN) / total
# Precision = TP / (TP + FP)   - of those predicted positive, how many were
# Recall    = TP / (TP + FN)   - of the actual positives, how many were found
# F1        = harmonic mean of precision and recall
print("\nAccuracy :", accuracy_score(y_test, y_pred))
print("Precision:", precision_score(y_test, y_pred))
print("Recall   :", recall_score(y_test, y_pred))
print("F1-Score :", f1_score(y_test, y_pred))

# ROC-AUC uses the probabilities, not the hard predictions:
# it measures how well the model ranks positives above negatives
print("ROC-AUC  :", roc_auc_score(y_test, y_prob))

print("\nClassification Report:")
print(classification_report(y_test, y_pred, target_names=data.target_names))

# -------------------------------
# 3. Plot the confusion matrix and the ROC curve
# -------------------------------

fig, axes = plt.subplots(1, 2, figsize=(12, 5))

ConfusionMatrixDisplay(cm, display_labels=data.target_names).plot(
    ax=axes[0], cmap='Blues', colorbar=False
)
axes[0].set_title("Confusion Matrix")

fpr, tpr, thresholds = roc_curve(y_test, y_prob)

axes[1].plot(fpr, tpr, label=f"Logistic Regression (AUC = {roc_auc_score(y_test, y_prob):.3f})")
axes[1].plot([0, 1], [0, 1], color='gray', linestyle='--', label="Random Guess")
axes[1].set_title("ROC Curve")
axes[1].set_xlabel("False Positive Rate")
axes[1].set_ylabel("True Positive Rate")
axes[1].legend()

plt.tight_layout()
plt.show()
