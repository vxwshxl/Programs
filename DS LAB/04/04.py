# 4. Compute and visualize covariance and correlation matrices.

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

# Output:
# Covariance Matrix:
#              A           B      C
# A  216.666667  216.666667  135.0
# B  216.666667  216.666667  135.0
# C  135.000000  135.000000   87.5
#
# Correlation Matrix:
#            A         B         C
# A  1.000000  1.000000  0.980469
# B  1.000000  1.000000  0.980469
# C  0.980469  0.980469  1.000000
