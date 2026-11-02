# 17. Write a Python program to implement Decision Tree classification.

import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree, export_text
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report

iris = load_iris()
X, y = iris.data, iris.target

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=42, stratify=y
)

# Trees do not need scaling. max_depth stops the tree from
# growing until it memorises the training data.
tree = DecisionTreeClassifier(criterion='gini', max_depth=3, random_state=42)
tree.fit(X_train, y_train)

y_pred = tree.predict(X_test)

print("Training Accuracy:", tree.score(X_train, y_train))
print("Testing Accuracy:", accuracy_score(y_test, y_pred))

print("\nConfusion Matrix:")
print(confusion_matrix(y_test, y_pred))

print("\nClassification Report:")
print(classification_report(y_test, y_pred, target_names=iris.target_names))

# The learned rules, as plain if-else text
print("Decision Rules:")
print(export_text(tree, feature_names=iris.feature_names))

# How much each feature reduced impurity across all splits
importance = pd.DataFrame({
    'Feature': iris.feature_names,
    'Importance': tree.feature_importances_
}).sort_values('Importance', ascending=False)

print("Feature Importance:")
print(importance)

# Compare with an unlimited tree to see overfitting
full_tree = DecisionTreeClassifier(random_state=42).fit(X_train, y_train)
print("\nUnlimited tree depth:", full_tree.get_depth())
print("Unlimited tree - Train:", full_tree.score(X_train, y_train),
      " Test:", full_tree.score(X_test, y_test))

# The tree itself, and the importance of each feature
fig, axes = plt.subplots(1, 2, figsize=(18, 7),
                         gridspec_kw={'width_ratios': [3, 1]})

plot_tree(tree, feature_names=iris.feature_names,
          class_names=iris.target_names, filled=True, rounded=True,
          ax=axes[0])
axes[0].set_title("Decision Tree (max_depth = 3)")

axes[1].barh(importance['Feature'], importance['Importance'])
axes[1].invert_yaxis()
axes[1].set_title("Feature Importance")
axes[1].set_xlabel("Importance")

plt.tight_layout()
plt.show()
