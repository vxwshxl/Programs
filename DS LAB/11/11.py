# 11. Write a Python program to implement Simple Linear Regression using Scikit-learn.

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score

data = {
    'Experience': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    'Salary': [30000, 35000, 41000, 44000, 52000,
               55000, 62000, 66000, 71000, 78000]
}

df = pd.DataFrame(data)

print("Dataset:")
print(df)

# Feature (X) must be 2D, target (y) stays 1D
X = df[['Experience']]
y = df['Salary']

# Split into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=1
)

# Train the model
model = LinearRegression()
model.fit(X_train, y_train)

# Model parameters:  Salary = m * Experience + c
print("\nSlope (m):", model.coef_[0])
print("Intercept (c):", model.intercept_)

# Predict on the test set
y_pred = model.predict(X_test)

print("\nActual vs Predicted:")
print(pd.DataFrame({'Actual': y_test, 'Predicted': y_pred}))

# Evaluate the model
print("\nMean Absolute Error:", mean_absolute_error(y_test, y_pred))
print("Mean Squared Error:", mean_squared_error(y_test, y_pred))
print("Root Mean Squared Error:", np.sqrt(mean_squared_error(y_test, y_pred)))
print("R2 Score:", r2_score(y_test, y_pred))

# Predict for a new value
new_experience = pd.DataFrame({'Experience': [11]})
print("\nPredicted Salary for 11 years:", model.predict(new_experience)[0])

# Plot the data points and the regression line
plt.figure(figsize=(7, 5))
plt.scatter(X, y, label="Actual Data")
plt.plot(X, model.predict(X), color='red', label="Regression Line")

plt.title("Simple Linear Regression")
plt.xlabel("Years of Experience")
plt.ylabel("Salary")
plt.legend()
plt.show()
