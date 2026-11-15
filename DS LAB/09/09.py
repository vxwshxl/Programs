# 9. Write a Python program to visualize data using Matplotlib and Seaborn.

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.DataFrame({'Age': [25, 30, 35, 40, 45], 'Salary': [50000, 60000, 70000, 80000, 90000]})

fig, ax = plt.subplots(1, 2, figsize=(12, 5))
ax[0].plot(df['Age'], df['Salary'], marker='o')
ax[0].set_title("Matplotlib Line Plot")
sns.scatterplot(data=df, x='Age', y='Salary', ax=ax[1]).set_title("Seaborn Scatter Plot")
plt.show()
