# 38. Write a Python program to visualize multidimensional datasets using pair plots and dimensionality reduction techniques.

import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.decomposition import PCA

iris = load_iris(as_frame=True)
df = iris.data
df['species'] = iris.target_names[iris.target]

sns.pairplot(df, hue='species')
plt.show()

X_pca = PCA(n_components=2).fit_transform(df.drop(columns='species'))
sns.scatterplot(x=X_pca[:, 0], y=X_pca[:, 1], hue=df['species'])
plt.title("2D PCA Visualization")
plt.show()

# Output:
# (graph only - no printed output)
