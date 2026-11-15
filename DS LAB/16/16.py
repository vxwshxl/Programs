# 16. k-Nearest Neighbors (kNN) classification.

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score, confusion_matrix

iris = load_iris()
X_train, X_test, y_train, y_test = train_test_split(iris.data, iris.target, test_size=0.3, random_state=42)

knn = KNeighborsClassifier(n_neighbors=5).fit(X_train, y_train)
y_pred = knn.predict(X_test)
print("kNN Accuracy:", accuracy_score(y_test, y_pred))
print("Confusion Matrix:\n", confusion_matrix(y_test, y_pred))
print("Prediction for [5.1, 3.5, 1.4, 0.2]:", iris.target_names[knn.predict([[5.1, 3.5, 1.4, 0.2]])[0]])

# Output:
# kNN Accuracy: 1.0
# Confusion Matrix:
#  [[19  0  0]
#  [ 0 13  0]
#  [ 0  0 13]]
# Prediction for [5.1, 3.5, 1.4, 0.2]: setosa
