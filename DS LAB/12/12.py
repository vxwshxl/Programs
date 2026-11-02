# 12. Write a Python program to implement Multiple Linear Regression and evaluate the model.

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score

data = {
    'Experience': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15],
    'Education': [12, 14, 16, 16, 14, 18, 16, 18, 20, 16, 18, 20, 18, 20, 22],
    'Projects': [2, 3, 5, 4, 6, 7, 6, 8, 9, 8, 10, 11, 10, 12, 13],
    'Salary': [39000, 44500, 49500, 50500, 53000, 59500, 61000, 68500,
               71000, 69000, 76500, 81500, 81000, 85000, 91500]
}

df = pd.DataFrame(data)

print("Dataset:")
print(df)

# Correlation of every feature with the target
print("\nCorrelation Matrix:")
print(df.corr())

# Three features (X) predicting one target (y)
X = df[['Experience', 'Education', 'Projects']]
y = df['Salary']

# Split into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=1
)

# Train the model
model = LinearRegression()
model.fit(X_train, y_train)

# Each feature gets its own coefficient. Experience and Projects are highly
# correlated above, so the shared effect lands mostly on one of them.
print("\nCoefficients:")
print(pd.DataFrame({'Feature': X.columns, 'Coefficient': model.coef_}))

print("\nIntercept:", model.intercept_)

# Predict on the test set
y_pred = model.predict(X_test)

print("\nActual vs Predicted:")
print(pd.DataFrame({'Actual': y_test, 'Predicted': y_pred}))

# Evaluate the model
mse = mean_squared_error(y_test, y_pred)

print("\nMean Absolute Error:", mean_absolute_error(y_test, y_pred))
print("Mean Squared Error:", mse)
print("Root Mean Squared Error:", np.sqrt(mse))

# Comparing the two scores shows whether the model is overfitting
train_r2 = r2_score(y_train, model.predict(X_train))
test_r2 = r2_score(y_test, y_pred)

print("Training R2 Score:", train_r2)
print("Testing R2 Score:", test_r2)

# Adjusted R2 penalises adding features that do not help.
# It measures fit, so it is calculated on the training data.
n = X_train.shape[0]
k = X_train.shape[1]
adjusted_r2 = 1 - (1 - train_r2) * (n - 1) / (n - k - 1)

print("Adjusted R2 Score:", adjusted_r2)

# Predict for a new employee
new_data = pd.DataFrame({
    'Experience': [16],
    'Education': [20],
    'Projects': [14]
})

print("\nPredicted Salary for new employee:", model.predict(new_data)[0])

# With many features a regression line cannot be drawn,
# so actual values are plotted against predicted values instead
plt.figure(figsize=(7, 5))
plt.scatter(y_test, y_pred, label="Predictions")
plt.plot([y.min(), y.max()], [y.min(), y.max()],
         color='red', label="Perfect Prediction")

plt.title("Multiple Linear Regression")
plt.xlabel("Actual Salary")
plt.ylabel("Predicted Salary")
plt.legend()
plt.show()
