# 6. Hypothesis testing using SciPy.

from scipy import stats

t, p = stats.ttest_1samp([48, 52, 51, 49, 50, 53, 47, 52, 51, 50], 50)
print("T-statistic:", t)
print("P-value:", p)
print("Reject the null hypothesis" if p < 0.05 else "Fail to reject the null hypothesis")

# Output:
# T-statistic: 0.5023310149673481
# P-value: 0.6274948659508928
# Fail to reject the null hypothesis
