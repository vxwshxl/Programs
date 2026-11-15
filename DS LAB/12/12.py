# 12. Multiple Linear Regression with model evaluation.

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score

df = pd.DataFrame({
    'Experience': range(1, 16),
    'Education': [12, 14, 16, 16, 14, 18, 16, 18, 20, 16, 18, 20, 18, 20, 22],
    'Projects': [2, 3, 5, 4, 6, 7, 6, 8, 9, 8, 10, 11, 10, 12, 13],
    'Salary': [39000, 44500, 49500, 50500, 53000, 59500, 61000, 68500,
               71000, 69000, 76500, 81500, 81000, 85000, 91500]})
X, y = df.drop(columns='Salary'), df['Salary']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=1)

model = LinearRegression().fit(X_train, y_train)
y_pred = model.predict(X_test)
print("Coefficients:", model.coef_)
print("Intercept:", model.intercept_)
print("MSE:", mean_squared_error(y_test, y_pred))
print("R2 Score:", r2_score(y_test, y_pred))

# Output:
# Coefficients: [2866.65373507 1107.60162076   96.64209664]
# Intercept: 22505.043320832818
# MSE: 2101589.657324817
# R2 Score: 0.9804974976120563
