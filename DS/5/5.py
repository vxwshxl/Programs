# 5. Write a Python program to analyze univariate and multivariate normal distributions.

import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm, multivariate_normal

# -------------------------------
# 1. Univariate Normal Distribution
# -------------------------------

# Generate data
data = np.random.normal(loc=50, scale=10, size=1000)

# Calculate mean and standard deviation
mean = np.mean(data)
std = np.std(data)

print("Univariate Normal Distribution")
print("Mean:", mean)
print("Standard Deviation:", std)

# Plot histogram
plt.figure(figsize=(7, 5))
plt.hist(data, bins=30, density=True, alpha=0.6)

# Plot normal distribution curve
x = np.linspace(min(data), max(data), 100)
y = norm.pdf(x, mean, std)

plt.plot(x, y)
plt.title("Univariate Normal Distribution")
plt.xlabel("Value")
plt.ylabel("Density")
plt.show()


# -------------------------------
# 2. Multivariate Normal Distribution
# -------------------------------

# Mean vector
mean_vector = [50, 30]

# Covariance matrix
covariance_matrix = [
    [100, 50],
    [50, 64]
]

# Generate multivariate normal data
multi_data = np.random.multivariate_normal(
    mean_vector,
    covariance_matrix,
    1000
)

# Print mean and covariance
print("\nMultivariate Normal Distribution")
print("Mean Vector:")
print(np.mean(multi_data, axis=0))

print("\nCovariance Matrix:")
print(np.cov(multi_data, rowvar=False))

# Plot multivariate data
plt.figure(figsize=(7, 5))
plt.scatter(multi_data[:, 0], multi_data[:, 1], alpha=0.5)

plt.title("Multivariate Normal Distribution")
plt.xlabel("Variable 1")
plt.ylabel("Variable 2")
plt.show()