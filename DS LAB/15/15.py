# 15. Model evaluation: confusion matrix, accuracy, precision, recall, F1, ROC-AUC.

from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import confusion_matrix, accuracy_score, precision_score, recall_score, f1_score, roc_auc_score

X, y = load_breast_cancer(return_X_y=True)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=42)

model = make_pipeline(StandardScaler(), LogisticRegression()).fit(X_train, y_train)
y_pred = model.predict(X_test)
y_prob = model.predict_proba(X_test)[:, 1]

print("Confusion Matrix:\n", confusion_matrix(y_test, y_pred))
print("Accuracy:", accuracy_score(y_test, y_pred))
print("Precision:", precision_score(y_test, y_pred))
print("Recall:", recall_score(y_test, y_pred))
print("F1-Score:", f1_score(y_test, y_pred))
print("ROC-AUC:", roc_auc_score(y_test, y_prob))

# Output:
# Confusion Matrix:
#  [[53  1]
#  [ 2 87]]
# Accuracy: 0.9790209790209791
# Precision: 0.9886363636363636
# Recall: 0.9775280898876404
# F1-Score: 0.9830508474576272
# ROC-AUC: 0.9977111943404079
