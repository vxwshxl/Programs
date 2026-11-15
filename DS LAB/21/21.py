# 21. Write a Python program to implement Logistic Regression for binary classification.

from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

X, y = load_breast_cancer(return_X_y=True)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=42)

model = make_pipeline(StandardScaler(), LogisticRegression()).fit(X_train, y_train)
print("Logistic Regression Accuracy:", accuracy_score(y_test, model.predict(X_test)))
print("P(benign) for first test sample:", model.predict_proba(X_test[:1])[0, 1])

# Output:
# Logistic Regression Accuracy: 0.9790209790209791
# P(benign) for first test sample: 0.8766704261947693
