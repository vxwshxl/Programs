# 6. Write a Python program to perform hypothesis testing
# using statistical libraries such as SciPy.

import numpy as np
from scipy import stats

data = [48, 52, 51, 49, 50, 53, 47, 52, 51, 50]

# Perform one-sample t-test
t_statistic, p_value = stats.ttest_1samp(data, 50)

print("T-statistic:", t_statistic)
print("P-value:", p_value)

# Decision
if p_value < 0.05:
    print("Reject the null hypothesis")
else:
    print("Fail to reject the null hypothesis")