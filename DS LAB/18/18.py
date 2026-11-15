# 18. Support Vector Machine (SVM) classification.

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score

X, y = load_iris(return_X_y=True)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

for kernel in ['linear', 'poly', 'rbf']:
    svm = SVC(kernel=kernel).fit(X_train, y_train)
    print(f"SVM ({kernel}) Accuracy:", accuracy_score(y_test, svm.predict(X_test)))

# Output:
# SVM (linear) Accuracy: 1.0
# SVM (poly) Accuracy: 0.9777777777777777
# SVM (rbf) Accuracy: 1.0
