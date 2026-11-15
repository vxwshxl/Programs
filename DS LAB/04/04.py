# 4. Write a Python program to compute and visualize covariance
# and correlation matrices for multivariate datasets.

import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

df = pd.DataFrame({'A': [10, 20, 20, 30, 40, 50],
                   'B': [15, 25, 25, 35, 45, 55],
                   'C': [5, 10, 15, 20, 25, 30]})
print("Covariance Matrix:\n", df.cov())
print("\nCorrelation Matrix:\n", df.corr())

fig, ax = plt.subplots(1, 2, figsize=(12, 5))
sns.heatmap(df.cov(), annot=True, cmap='coolwarm', ax=ax[0]).set_title("Covariance Matrix")
sns.heatmap(df.corr(), annot=True, cmap='coolwarm', ax=ax[1]).set_title("Correlation Matrix")
plt.show()
