# 17. Decision Tree classification.

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, export_text
from sklearn.metrics import accuracy_score

iris = load_iris()
X_train, X_test, y_train, y_test = train_test_split(iris.data, iris.target, test_size=0.3, random_state=42)

dt = DecisionTreeClassifier(criterion='gini', max_depth=3, random_state=42).fit(X_train, y_train)
print("Decision Tree Accuracy:", accuracy_score(y_test, dt.predict(X_test)))
print("\nDecision Rules:\n" + export_text(dt, feature_names=iris.feature_names))

# Output:
# Decision Tree Accuracy: 1.0
#
# Decision Rules:
# |--- petal length (cm) <= 2.45
# |   |--- class: 0
# |--- petal length (cm) >  2.45
# |   |--- petal length (cm) <= 4.75
# |   |   |--- petal width (cm) <= 1.60
# |   |   |   |--- class: 1
# |   |   |--- petal width (cm) >  1.60
# |   |   |   |--- class: 2
# |   |--- petal length (cm) >  4.75
# |   |   |--- petal width (cm) <= 1.75
# |   |   |   |--- class: 1
# |   |   |--- petal width (cm) >  1.75
# |   |   |   |--- class: 2
