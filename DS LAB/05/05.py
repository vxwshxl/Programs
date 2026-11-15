# 5. Analyze univariate and multivariate normal distributions.

import numpy as np
import matplotlib.pyplot as plt

data = np.random.normal(50, 10, 1000)
multi = np.random.multivariate_normal([50, 30], [[100, 50], [50, 64]], 1000)
print("Univariate Mean:", data.mean(), " Std:", data.std())
print("Multivariate Mean:", multi.mean(axis=0))
print("Multivariate Covariance:\n", np.cov(multi, rowvar=False))

fig, ax = plt.subplots(1, 2, figsize=(12, 5))
ax[0].hist(data, bins=30)
ax[0].set_title("Univariate Normal Distribution")
ax[1].scatter(multi[:, 0], multi[:, 1], alpha=0.5)
ax[1].set_title("Multivariate Normal Distribution")
plt.show()

# Output:
# Univariate Mean: 49.67332303089289  Std: 9.824210693574127
# Multivariate Mean: [49.88341838 29.75859401]
# Multivariate Covariance:
#  [[103.73097274  55.03180105]
#  [ 55.03180105  72.89431088]]
