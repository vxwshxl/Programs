# 40. Write a Python program to develop an end-to-end data science application including data preprocessing, visualization, machine learning model development, evaluation, and prediction using a real-world dataset.

import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import classification_report, confusion_matrix

# 1. Load data
data = load_breast_cancer(as_frame=True)
df = data.frame

# 2. Preprocessing
df = df.drop_duplicates().dropna()
X, y = df.drop(columns='target'), df['target']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
scaler = StandardScaler()
X_train, X_test = scaler.fit_transform(X_train), scaler.transform(X_test)

# 3. Visualization
sns.countplot(x=y)
plt.title("Class Balance (0 = malignant, 1 = benign)")
plt.show()

# 4. Model
model = LogisticRegression().fit(X_train, y_train)

# 5. Evaluation
y_pred = model.predict(X_test)
print("Confusion Matrix:\n", confusion_matrix(y_test, y_pred))
print("\nClassification Report:\n", classification_report(y_test, y_pred))

# 6. Prediction
print("Prediction for first test patient:", data.target_names[model.predict(X_test[:1])[0]])

# Output:
# Confusion Matrix:
#  [[41  2]
#  [ 1 70]]
#
# Classification Report:
#                precision    recall  f1-score   support
#
#            0       0.98      0.95      0.96        43
#            1       0.97      0.99      0.98        71
#
#     accuracy                           0.97       114
#    macro avg       0.97      0.97      0.97       114
# weighted avg       0.97      0.97      0.97       114
#
# Prediction for first test patient: benign
