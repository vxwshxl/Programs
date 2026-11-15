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

# Output:
# <class 'pandas.DataFrame'>
# RangeIndex: 178 entries, 0 to 177
# Data columns (total 14 columns):
#  #   Column                        Non-Null Count  Dtype
# ---  ------                        --------------  -----
#  0   alcohol                       178 non-null    float64
#  1   malic_acid                    178 non-null    float64
#  2   ash                           178 non-null    float64
#  3   alcalinity_of_ash             178 non-null    float64
#  4   magnesium                     178 non-null    float64
#  5   total_phenols                 178 non-null    float64
#  6   flavanoids                    178 non-null    float64
#  7   nonflavanoid_phenols          178 non-null    float64
#  8   proanthocyanins               178 non-null    float64
#  9   color_intensity               178 non-null    float64
#  10  hue                           178 non-null    float64
#  11  od280/od315_of_diluted_wines  178 non-null    float64
#  12  proline                       178 non-null    float64
#  13  target                        178 non-null    int64
# dtypes: float64(13), int64(1)
# memory usage: 19.6 KB
#
# Summary Statistics:
#            alcohol  malic_acid  ...      proline      target
# count  178.000000  178.000000  ...   178.000000  178.000000
# mean    13.000618    2.336348  ...   746.893258    0.938202
# std      0.811827    1.117146  ...   314.907474    0.775035
# min     11.030000    0.740000  ...   278.000000    0.000000
# 25%     12.362500    1.602500  ...   500.500000    0.000000
# 50%     13.050000    1.865000  ...   673.500000    1.000000
# 75%     13.677500    3.082500  ...   985.000000    2.000000
# max     14.830000    5.800000  ...  1680.000000    2.000000
#
# [8 rows x 14 columns]
#
# Missing Values:
#  alcohol                         0
# malic_acid                      0
# ash                             0
# alcalinity_of_ash               0
# magnesium                       0
# total_phenols                   0
# flavanoids                      0
# nonflavanoid_phenols            0
# proanthocyanins                 0
# color_intensity                 0
# hue                             0
# od280/od315_of_diluted_wines    0
# proline                         0
# target                          0
# dtype: int64
