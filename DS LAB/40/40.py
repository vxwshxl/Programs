# 40. Write a Python program to develop an end-to-end data science application including data preprocessing, visualization, machine learning model development, evaluation, and prediction using a real-world dataset.

import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split, cross_val_score, StratifiedKFold, GridSearchCV
from sklearn.pipeline import Pipeline
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import (accuracy_score, classification_report, confusion_matrix,
                             roc_auc_score, roc_curve, ConfusionMatrixDisplay)

# =====================================================
# Step 1: Load the data
# =====================================================

# Breast Cancer Wisconsin: 569 real tumour samples, 30 measurements each
data = load_breast_cancer(as_frame=True)
df = data.frame
df['diagnosis'] = df['target'].map({0: 'malignant', 1: 'benign'})

print("STEP 1: LOAD DATA")
print("Shape:", df.shape)
print(df.iloc[:5, :6])

# =====================================================
# Step 2: Preprocessing
# =====================================================

print("\nSTEP 2: PREPROCESSING")
print("Missing values:", df.isnull().sum().sum())
print("Duplicate rows:", df.duplicated().sum())
print("Class balance:")
print(df['diagnosis'].value_counts())

X = df[data.feature_names]
y = df['target']

# Split first, so the test set stays completely unseen until Step 5
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42, stratify=y
)

print("Training rows:", len(X_train), " Testing rows:", len(X_test))

# =====================================================
# Step 3: Visualization (done in the figure at the end)
# =====================================================

correlation_with_target = X.corrwith(y).sort_values()

print("\nSTEP 3: EXPLORATION")
print("Features most linked to the diagnosis:")
print(correlation_with_target.head(5).round(3))

# =====================================================
# Step 4: Build and select a model
# =====================================================

# Every model is a pipeline: fill any missing values -> scale -> classify.
# The same steps then run automatically on new data at prediction time.
def make_model(classifier):
    return Pipeline([
        ('imputer', SimpleImputer(strategy='median')),
        ('scaler', StandardScaler()),
        ('model', classifier)
    ])


candidates = {
    'Logistic Regression': make_model(LogisticRegression(max_iter=1000)),
    'SVM': make_model(SVC(probability=True, random_state=42)),
    'Random Forest': make_model(RandomForestClassifier(random_state=42))
}

cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=42)

print("\nSTEP 4: MODEL SELECTION (5-fold CV, ROC-AUC)")

cv_results = {}
for name, pipeline in candidates.items():
    scores = cross_val_score(pipeline, X_train, y_train, cv=cv, scoring='roc_auc')
    cv_results[name] = scores.mean()
    print(f"{name:20s} {scores.mean():.4f} (+/- {scores.std():.4f})")

best_name = max(cv_results, key=cv_results.get)
print("Best model:", best_name)

# Tune the regularisation strength of the chosen model
param_grids = {
    'Logistic Regression': {'model__C': [0.01, 0.1, 1, 10, 100]},
    'SVM': {'model__C': [0.1, 1, 10, 100], 'model__gamma': ['scale', 0.01, 0.001]},
    'Random Forest': {'model__n_estimators': [100, 300], 'model__max_depth': [None, 5, 10]}
}

search = GridSearchCV(candidates[best_name], param_grids[best_name],
                      cv=cv, scoring='roc_auc')
search.fit(X_train, y_train)

final_model = search.best_estimator_

print("Best parameters:", search.best_params_)
print("Tuned CV ROC-AUC:", round(search.best_score_, 4))

# =====================================================
# Step 5: Evaluate on the untouched test set
# =====================================================

y_pred = final_model.predict(X_test)
y_prob = final_model.predict_proba(X_test)[:, 1]

print("\nSTEP 5: EVALUATION")
print("Test Accuracy:", round(accuracy_score(y_test, y_pred), 4))
print("Test ROC-AUC:", round(roc_auc_score(y_test, y_prob), 4))

print("\nConfusion Matrix:")
print(confusion_matrix(y_test, y_pred))

print("\nClassification Report:")
print(classification_report(y_test, y_pred, target_names=data.target_names))

# =====================================================
# Step 6: Predict for new patients
# =====================================================

# Two rows the model has never seen, standing in for new patients
new_patients = X_test.iloc[[0, 5]]

predictions = final_model.predict(new_patients)
probabilities = final_model.predict_proba(new_patients)

print("STEP 6: PREDICTION")
for i, (index, pred) in enumerate(zip(new_patients.index, predictions)):
    print(f"Patient {index}: predicted {data.target_names[pred]:9s} "
          f"(P(benign) = {probabilities[i, 1]:.4f}), "
          f"actual {data.target_names[y_test.loc[index]]}")

# =====================================================
# Visual summary of the whole pipeline
# =====================================================

fig, axes = plt.subplots(2, 2, figsize=(15, 11))

sns.countplot(data=df, x='diagnosis', ax=axes[0, 0])
axes[0, 0].set_title("1. Class Balance")

top = correlation_with_target.reindex(correlation_with_target.abs().sort_values().index).tail(10)
axes[0, 1].barh(top.index, top.values,
                color=['tomato' if v < 0 else 'seagreen' for v in top.values])
axes[0, 1].set_title("2. Top 10 Features by Correlation with Diagnosis")
axes[0, 1].set_xlabel("Correlation with benign (1)")

ConfusionMatrixDisplay.from_predictions(
    y_test, y_pred, display_labels=data.target_names,
    ax=axes[1, 0], cmap='Blues', colorbar=False
)
axes[1, 0].set_title(f"3. Confusion Matrix - {best_name}")

fpr, tpr, _ = roc_curve(y_test, y_prob)
axes[1, 1].plot(fpr, tpr, label=f"{best_name} (AUC = {roc_auc_score(y_test, y_prob):.3f})")
axes[1, 1].plot([0, 1], [0, 1], color='gray', linestyle='--', label="Random Guess")
axes[1, 1].set_title("4. ROC Curve on Test Set")
axes[1, 1].set_xlabel("False Positive Rate")
axes[1, 1].set_ylabel("True Positive Rate")
axes[1, 1].legend()

plt.tight_layout()
plt.show()
