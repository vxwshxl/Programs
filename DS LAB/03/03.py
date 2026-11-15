# 3. Write a Python program to perform descriptive statistical analysis
# including mean, median, mode, variance, standard deviation, and covariance.

import pandas as pd

df = pd.DataFrame({'A': [10, 20, 20, 30, 40, 50], 'B': [15, 25, 25, 35, 45, 55]})

print("Mean:\n", df.mean())
print("\nMedian:\n", df.median())
print("\nMode:\n", df.mode())
print("\nVariance:\n", df.var())
print("\nStandard Deviation:\n", df.std())
print("\nCovariance:\n", df.cov())

# Output:
# Mean:
#  A    28.333333
# B    33.333333
# dtype: float64
#
# Median:
#  A    25.0
# B    30.0
# dtype: float64
#
# Mode:
#      A   B
# 0  20  25
#
# Variance:
#  A    216.666667
# B    216.666667
# dtype: float64
#
# Standard Deviation:
#  A    14.719601
# B    14.719601
# dtype: float64
#
# Covariance:
#              A           B
# A  216.666667  216.666667
# B  216.666667  216.666667
