# 3. Write a Python program to perform descriptive statistical analysis
# including mean, median, mode, variance, standard deviation, and covariance.

import pandas as pd
import numpy as np

df = pd.DataFrame({
    'A': [10, 20, 20, 30, 40, 50],
    'B': [15, 25, 25, 35, 45, 55]
})

print("Mean:\n", df.mean())

print("\nMedian:\n", df.median())

print("\nMode:\n", df.mode())

print("\nVariance:\n", df.var())

print("\nStandard Deviation:\n", df.std())

print("\nCovariance:\n", df.cov())