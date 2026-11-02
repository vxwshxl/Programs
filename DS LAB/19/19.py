# 19. Write a Python program to implement Random Forest classification.

import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_wine
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report

wine = load_wine()
X, y = wine.data, wine.target

print("Dataset shape:", X.shape)
print("Classes:", wine.target_names.tolist())

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=42, stratify=y
)

# 100 trees, each trained on a random sample of rows and
# considering a random subset of features at every split
forest = RandomForestClassifier(n_estimators=100, oob_score=True, random_state=42)
forest.fit(X_train, y_train)

y_pred = forest.predict(X_test)

print("\nRandom Forest Accuracy:", accuracy_score(y_test, y_pred))

# Out-of-bag score: each tree is tested on the rows it never saw,
# a free validation score without touching the test set
print("Out-of-Bag Score:", forest.oob_score_)

# One tree on its own, for comparison
single_tree = DecisionTreeClassifier(random_state=42).fit(X_train, y_train)
print("Single Decision Tree Accuracy:", single_tree.score(X_test, y_test))

print("\nConfusion Matrix:")
print(confusion_matrix(y_test, y_pred))

print("\nClassification Report:")
print(classification_report(y_test, y_pred, target_names=wine.target_names))

importance = pd.DataFrame({
    'Feature': wine.feature_names,
    'Importance': forest.feature_importances_
}).sort_values('Importance', ascending=False)

print("Feature Importance:")
print(importance.to_string(index=False))

# How accuracy changes as more trees are added
tree_counts = [1, 5, 10, 20, 50, 100, 200]
accuracies = []

for n in tree_counts:
    model = RandomForestClassifier(n_estimators=n, random_state=42).fit(X_train, y_train)
    accuracies.append(model.score(X_test, y_test))

print("\nTrees vs Accuracy:")
for n, acc in zip(tree_counts, accuracies):
    print(f"{n:4d} trees: {acc:.4f}")

fig, axes = plt.subplots(1, 2, figsize=(14, 6))

axes[0].barh(importance['Feature'], importance['Importance'])
axes[0].invert_yaxis()
axes[0].set_title("Random Forest Feature Importance")
axes[0].set_xlabel("Importance")

axes[1].plot(tree_counts, accuracies, marker='o')
axes[1].set_xscale('log')
axes[1].set_title("Accuracy vs Number of Trees")
axes[1].set_xlabel("Number of Trees (log scale)")
axes[1].set_ylabel("Test Accuracy")

plt.tight_layout()
plt.show()
