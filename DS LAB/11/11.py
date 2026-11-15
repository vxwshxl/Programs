# 11. Write a Python program to implement Simple Linear Regression using Scikit-learn.

import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

df = pd.DataFrame({'Experience': range(1, 11),
                   'Salary': [30000, 35000, 41000, 44000, 52000, 55000, 62000, 66000, 71000, 78000]})
X, y = df[['Experience']], df['Salary']

model = LinearRegression().fit(X, y)
print("Slope:", model.coef_[0], " Intercept:", model.intercept_)
print("R2 Score:", model.score(X, y))
print("Predicted Salary for 11 years:", model.predict(pd.DataFrame({'Experience': [11]}))[0])

plt.scatter(X, y, label="Data")
plt.plot(X, model.predict(X), color='red', label="Regression Line")
plt.title("Simple Linear Regression")
plt.legend()
plt.show()

# Output:
# Slope: 5248.48484848485  Intercept: 24533.333333333325
# R2 Score: 0.9965768897535254
# Predicted Salary for 11 years: 82266.66666666667
