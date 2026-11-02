# 13. Write a Python program to implement Ridge Regression and Lasso Regression.

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LinearRegression, Ridge, Lasso
from sklearn.metrics import mean_squared_error, r2_score

# The dataset from experiment 12, plus 'Distance' (km from office),
# which has nothing to do with salary
data = {
    'Experience': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15],
    'Education': [12, 14, 16, 16, 14, 18, 16, 18, 20, 16, 18, 20, 18, 20, 22],
    'Projects': [2, 3, 5, 4, 6, 7, 6, 8, 9, 8, 10, 11, 10, 12, 13],
    'Distance': [12, 30, 8, 25, 40, 15, 33, 6, 22, 18, 35, 10, 28, 20, 14],
    'Salary': [39000, 44500, 49500, 50500, 53000, 59500, 61000, 68500,
               71000, 69000, 76500, 81500, 81000, 85000, 91500]
}

df = pd.DataFrame(data)

print("Dataset:")
print(df)

# Experience and Projects move together, and Distance is unrelated to Salary
print("\nCorrelation with Salary:")
print(df.corr()['Salary'])

X = df.drop(columns='Salary')
y = df['Salary']

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=1
)

# Both penalties act on the size of the coefficients, so every feature
# must be on the same scale first, otherwise the penalty is unfair
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# 1. Ordinary Linear Regression - no penalty at all
linear = LinearRegression()
linear.fit(X_train_scaled, y_train)

# 2. Ridge Regression - L2 penalty, shrinks coefficients towards zero
ridge = Ridge(alpha=1.0)
ridge.fit(X_train_scaled, y_train)

# 3. Lasso Regression - L1 penalty, can set coefficients exactly to zero
lasso = Lasso(alpha=100.0, max_iter=10000)
lasso.fit(X_train_scaled, y_train)

# Compare what each penalty did to the coefficients
coefficients = pd.DataFrame({
    'Feature': X.columns,
    'Linear': linear.coef_,
    'Ridge': ridge.coef_,
    'Lasso': lasso.coef_
})

print("\nCoefficients:")
print(coefficients)

print("\nLasso dropped:", list(X.columns[lasso.coef_ == 0]))

# Compare accuracy on the test set
print("\nModel Performance:")

for name, model in [('Linear', linear), ('Ridge', ridge), ('Lasso', lasso)]:
    y_pred = model.predict(X_test_scaled)
    rmse = np.sqrt(mean_squared_error(y_test, y_pred))
    print(f"{name:8s} R2: {r2_score(y_test, y_pred):.4f}  RMSE: {rmse:.2f}")

# Everything is drawn on one figure: the coefficients each model chose,
# then what happens to those coefficients as the penalty grows
fig, axes = plt.subplots(1, 3, figsize=(16, 5))

# Plot 1: how the three models weight each feature
positions = np.arange(len(X.columns))
width = 0.25

axes[0].bar(positions - width, linear.coef_, width, label="Linear")
axes[0].bar(positions, ridge.coef_, width, label="Ridge")
axes[0].bar(positions + width, lasso.coef_, width, label="Lasso")

axes[0].set_xticks(positions)
axes[0].set_xticklabels(X.columns, rotation=45, ha='right')
axes[0].set_title("Coefficients under each penalty")
axes[0].set_xlabel("Feature")
axes[0].set_ylabel("Coefficient")
axes[0].legend()

# Plots 2 and 3: what happens as the penalty strength grows
alphas = np.logspace(-2, 4, 50)

ridge_path = []
lasso_path = []

for a in alphas:
    r = Ridge(alpha=a).fit(X_train_scaled, y_train)
    l = Lasso(alpha=a, max_iter=10000).fit(X_train_scaled, y_train)
    ridge_path.append(r.coef_)
    lasso_path.append(l.coef_)

ridge_path = np.array(ridge_path)
lasso_path = np.array(lasso_path)

for i, feature in enumerate(X.columns):
    axes[1].plot(alphas, ridge_path[:, i], label=feature)
    axes[2].plot(alphas, lasso_path[:, i], label=feature)

axes[1].set_title("Ridge (L2) - shrinks towards zero")
axes[2].set_title("Lasso (L1) - reaches exactly zero")

for ax in axes[1:]:
    ax.set_xscale('log')
    ax.set_xlabel("Alpha")
    ax.set_ylabel("Coefficient")
    ax.legend()

for ax in axes:
    ax.axhline(0, color='black', linewidth=0.8)

plt.tight_layout()
plt.show()
