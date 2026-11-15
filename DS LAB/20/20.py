# 20. Write a Python program to implement Naive Bayes classification.

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score

X, y = load_iris(return_X_y=True)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

nb = GaussianNB().fit(X_train, y_train)
print("Naive Bayes Accuracy:", accuracy_score(y_test, nb.predict(X_test)))

# Output:
# Naive Bayes Accuracy: 0.9777777777777777
