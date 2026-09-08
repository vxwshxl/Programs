# 10. Write a Python program to create bar charts, histograms,
# pie charts, box plots, scatter plots, and heatmaps.

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David', 'Eve'],
    'Age': [25, 30, 35, 40, 45],
    'Salary': [50000, 60000, 70000, 80000, 90000]
}

df = pd.DataFrame(data)

# 1. Bar Chart
plt.bar(df['Name'], df['Salary'])
plt.title("Salary by Employee")
plt.xlabel("Name")
plt.ylabel("Salary")
plt.show()

# 2. Histogram
plt.hist(df['Age'], bins=5)
plt.title("Age Distribution")
plt.xlabel("Age")
plt.ylabel("Frequency")
plt.show()

# 3. Pie Chart
plt.pie(df['Salary'], labels=df['Name'], autopct='%1.1f%%')
plt.title("Salary Distribution")
plt.show()

# 4. Box Plot
plt.boxplot(df['Salary'])
plt.title("Salary Box Plot")
plt.ylabel("Salary")
plt.show()

# 5. Scatter Plot
plt.scatter(df['Age'], df['Salary'])
plt.title("Age vs Salary")
plt.xlabel("Age")
plt.ylabel("Salary")
plt.show()

# 6. Heatmap
correlation = df[['Age', 'Salary']].corr()

sns.heatmap(correlation, annot=True)
plt.title("Correlation Heatmap")
plt.show()