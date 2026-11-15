# 14. Write a Python program to perform model selection using train-test split and cross-validation techniques.

from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier

X, y = make_classification(n_samples=500, n_features=8, n_informative=5, n_redundant=2, random_state=42)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=42)

models = {'Logistic Regression': LogisticRegression(), 'kNN': KNeighborsClassifier(),
          'Decision Tree': DecisionTreeClassifier(random_state=42)}
cv = {}
for name, m in models.items():
    test = m.fit(X_train, y_train).score(X_test, y_test)
    cv[name] = cross_val_score(m, X, y, cv=5).mean()
    print(f"{name:20s} Test Accuracy: {test:.4f}  5-Fold CV: {cv[name]:.4f}")
print("Best model:", max(cv, key=cv.get))
