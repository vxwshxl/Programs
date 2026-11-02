# 22. Write a Python program to compare the performance of different classification algorithms on the same dataset.

import time
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_wine
from sklearn.model_selection import train_test_split, cross_val_score, StratifiedKFold
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.svm import SVC
from sklearn.ensemble import RandomForestClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score

wine = load_wine()
X, y = wine.data, wine.target

print("Dataset shape:", X.shape)
print("Classes:", wine.target_names.tolist())

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=42, stratify=y
)

# Same data, same split, same folds for every model - a fair race.
# Distance-based models get a scaler; trees and Naive Bayes do not need one.
models = {
    'Logistic Regression': make_pipeline(StandardScaler(), LogisticRegression(max_iter=1000)),
    'kNN': make_pipeline(StandardScaler(), KNeighborsClassifier()),
    'Decision Tree': DecisionTreeClassifier(random_state=42),
    'SVM': make_pipeline(StandardScaler(), SVC()),
    'Random Forest': RandomForestClassifier(random_state=42),
    'Naive Bayes': GaussianNB()
}

cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=42)

results = []
cv_scores = {}

for name, model in models.items():
    start = time.perf_counter()
    model.fit(X_train, y_train)
    train_time = time.perf_counter() - start

    y_pred = model.predict(X_test)
    scores = cross_val_score(model, X_train, y_train, cv=cv)
    cv_scores[name] = scores

    # 'macro' averages the score of each class equally
    results.append({
        'Model': name,
        'Accuracy': accuracy_score(y_test, y_pred),
        'Precision': precision_score(y_test, y_pred, average='macro'),
        'Recall': recall_score(y_test, y_pred, average='macro'),
        'F1-Score': f1_score(y_test, y_pred, average='macro'),
        'CV Mean': scores.mean(),
        'CV Std': scores.std(),
        'Train Time (ms)': train_time * 1000
    })

results = pd.DataFrame(results).sort_values('CV Mean', ascending=False)

print("\nModel Comparison (sorted by CV accuracy):")
print(results.round(4).to_string(index=False))

print("\nBest model:", results.iloc[0]['Model'])

fig, axes = plt.subplots(1, 2, figsize=(16, 6))

# Test-set metrics side by side for every model
metrics = ['Accuracy', 'Precision', 'Recall', 'F1-Score']
positions = np.arange(len(results))
width = 0.2

for i, metric in enumerate(metrics):
    axes[0].bar(positions + (i - 1.5) * width, results[metric], width, label=metric)

axes[0].set_xticks(positions)
axes[0].set_xticklabels(results['Model'], rotation=30, ha='right')
axes[0].set_ylim(0.8, 1.06)
axes[0].set_title("Test-Set Metrics")
axes[0].set_ylabel("Score")
axes[0].legend(loc='upper center', ncol=4)

# The spread of 5-fold CV accuracy for every model
order = list(results['Model'])
axes[1].boxplot([cv_scores[name] for name in order], tick_labels=order)
axes[1].tick_params(axis='x', labelrotation=30)
axes[1].set_title("5-Fold Cross-Validation Accuracy")
axes[1].set_ylabel("Accuracy")

plt.tight_layout()
plt.show()
