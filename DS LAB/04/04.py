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

# Both matrices go on one figure so they can be compared side by side
fig, axes = plt.subplots(1, 2, figsize=(12, 5))

matrices = [
    (covariance_matrix, "Covariance Matrix"),
    (correlation_matrix, "Correlation Matrix")
]

for ax, (matrix, title) in zip(axes, matrices):
    image = ax.imshow(matrix, cmap='coolwarm')
    fig.colorbar(image, ax=ax)

    ax.set_xticks(range(len(df.columns)))
    ax.set_xticklabels(df.columns)
    ax.set_yticks(range(len(df.columns)))
    ax.set_yticklabels(df.columns)
    ax.set_title(title)

    # Write each value inside its cell
    for i in range(len(df.columns)):
        for j in range(len(df.columns)):
            ax.text(j, i, round(matrix.iloc[i, j], 2),
                    ha='center', va='center')

plt.tight_layout()
plt.show()
