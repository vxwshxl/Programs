# 22. Write a Python program to compare the performance of different classification algorithms on the same dataset.

from sklearn.datasets import load_wine
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.svm import SVC
from sklearn.ensemble import RandomForestClassifier
from sklearn.naive_bayes import GaussianNB

X, y = load_wine(return_X_y=True)
X = StandardScaler().fit_transform(X)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

models = {"Logistic Regression": LogisticRegression(), "kNN": KNeighborsClassifier(),
          "Decision Tree": DecisionTreeClassifier(random_state=42), "SVM": SVC(),
          "Random Forest": RandomForestClassifier(random_state=42), "Naive Bayes": GaussianNB()}
for name, model in models.items():
    model.fit(X_train, y_train)
    print(f"{name:20s} Accuracy: {accuracy_score(y_test, model.predict(X_test)):.4f}")
