# 39. Write a Python program to perform exploratory data analysis (EDA) on a real-world dataset.

import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import load_wine

# Real chemical analysis of 178 wines from three cultivators in Italy
wine = load_wine(as_frame=True)
df = wine.frame
df['cultivar'] = df['target'].map(dict(enumerate(wine.target_names.tolist())))

# -------------------------------
# 1. First look
# -------------------------------

print("Shape:", df.shape)
print("\nFirst 5 rows:")
print(df.head())

print("\nColumn types and non-null counts:")
df.info()

# -------------------------------
# 2. Data quality
# -------------------------------

print("\nMissing values per column:")
print(df.isnull().sum())

print("\nDuplicate rows:", df.duplicated().sum())

# -------------------------------
# 3. Summary statistics
# -------------------------------

features = wine.feature_names

print("\nSummary Statistics:")
print(df[features].describe().T.round(2))

# Skewness: 0 is symmetric, above 1 or below -1 is strongly skewed
print("\nSkewness:")
print(df[features].skew().sort_values(ascending=False).round(3))

# -------------------------------
# 4. Target variable
# -------------------------------

print("\nWines per cultivar:")
print(df['cultivar'].value_counts())

print("\nMean of each feature per cultivar:")
print(df.groupby('cultivar')[features].mean().T.round(2))

# -------------------------------
# 5. Outliers (IQR rule)
# -------------------------------

# A value is an outlier if it is more than 1.5 x IQR outside the middle 50%
q1 = df[features].quantile(0.25)
q3 = df[features].quantile(0.75)
iqr = q3 - q1

outliers = ((df[features] < q1 - 1.5 * iqr) | (df[features] > q3 + 1.5 * iqr)).sum()

print("\nOutliers per feature:")
print(outliers[outliers > 0].sort_values(ascending=False))

# -------------------------------
# 6. Relationships between features
# -------------------------------

correlation = df[features].corr()

# Every pair once, strongest first
pairs = correlation.where(np.triu(np.ones(correlation.shape, dtype=bool), k=1)).stack()
pairs = pairs.reindex(pairs.abs().sort_values(ascending=False).index)

print("\nStrongest feature correlations:")
print(pairs.head(5).round(3))

# Which features best tell the cultivars apart
print("\nCorrelation of each feature with the cultivar label:")
print(df[features].corrwith(df['target']).sort_values().round(3))

# -------------------------------
# 7. Key findings
# -------------------------------

print("\nKey Findings:")
print("- No missing values or duplicates, so no cleaning is needed")
print(f"- Classes are fairly balanced: {df['cultivar'].value_counts().to_dict()}")
print(f"- Strongest pair: {pairs.index[0][0]} and {pairs.index[0][1]} ({pairs.iloc[0]:.2f})")
print("- Proline and flavanoids differ the most between cultivars")
print("- Features have very different scales (proline is in the 1000s), so scale before modelling")

fig, axes = plt.subplots(2, 3, figsize=(19, 11))

sns.countplot(data=df, x='cultivar', ax=axes[0, 0])
axes[0, 0].set_title("Wines per Cultivar")

sns.heatmap(correlation, cmap='coolwarm', center=0, ax=axes[0, 1],
            xticklabels=True, yticklabels=True)
axes[0, 1].set_title("Correlation Heatmap")
axes[0, 1].tick_params(labelsize=7)

sns.histplot(data=df, x='alcohol', hue='cultivar', kde=True, ax=axes[0, 2])
axes[0, 2].set_title("Alcohol Distribution by Cultivar")

sns.boxplot(data=df, x='cultivar', y='proline', ax=axes[1, 0])
axes[1, 0].set_title("Proline by Cultivar")

sns.boxplot(data=df, x='cultivar', y='flavanoids', ax=axes[1, 1])
axes[1, 1].set_title("Flavanoids by Cultivar")

sns.scatterplot(data=df, x='flavanoids', y='total_phenols', hue='cultivar', ax=axes[1, 2])
axes[1, 2].set_title("Flavanoids vs Total Phenols")

plt.tight_layout()
plt.show()
