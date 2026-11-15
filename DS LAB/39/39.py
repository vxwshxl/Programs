# 39. Write a Python program to perform exploratory data analysis (EDA) on a real-world dataset.

import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.datasets import load_wine

df = load_wine(as_frame=True).frame

df.info()
print("\nSummary Statistics:\n", df.describe())
print("\nMissing Values:\n", df.isnull().sum())

sns.boxplot(data=df, x='target', y='alcohol')
plt.title("Alcohol by Wine Class")
plt.show()
