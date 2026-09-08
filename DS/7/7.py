# 7. Write a Python program to compute confidence intervals
# for population parameters.

import numpy as np
from scipy import stats

data = [48, 52, 51, 49, 50, 53, 47, 52, 51, 50]

# Calculate sample mean
mean = np.mean(data)

# Calculate standard error
standard_error = stats.sem(data)

# Calculate 95% confidence interval
confidence_interval = stats.t.interval(
    0.95,
    len(data) - 1,
    loc=mean,
    scale=standard_error
)

print("Mean:", mean)
print("95% Confidence Interval:", confidence_interval)