# 4. Write a Python program to compute and visualize covariance
# and correlation matrices for multivariate datasets.

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.DataFrame({
    'A': [10, 20, 20, 30, 40, 50],
    'B': [15, 25, 25, 35, 45, 55],
    'C': [5, 10, 15, 20, 25, 30]
})

# Compute covariance matrix
covariance_matrix = df.cov()

# Compute correlation matrix
correlation_matrix = df.corr()

print("Covariance Matrix:\n", covariance_matrix)

print("\nCorrelation Matrix:\n", correlation_matrix)

# Visualize covariance matrix
plt.figure(figsize=(6, 5))
plt.imshow(covariance_matrix, cmap='coolwarm')
plt.colorbar()
plt.xticks(range(len(df.columns)), df.columns)
plt.yticks(range(len(df.columns)), df.columns)
plt.title("Covariance Matrix")

for i in range(len(df.columns)):
    for j in range(len(df.columns)):
        plt.text(j, i, round(covariance_matrix.iloc[i, j], 2),
                 ha='center', va='center')

plt.show()

# Visualize correlation matrix
plt.figure(figsize=(6, 5))
plt.imshow(correlation_matrix, cmap='coolwarm')
plt.colorbar()
plt.xticks(range(len(df.columns)), df.columns)
plt.yticks(range(len(df.columns)), df.columns)
plt.title("Correlation Matrix")

for i in range(len(df.columns)):
    for j in range(len(df.columns)):
        plt.text(j, i, round(correlation_matrix.iloc[i, j], 2),
                 ha='center', va='center')

plt.show()