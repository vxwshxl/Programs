# 33. Write a Python program to compute document similarity using cosine similarity.

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

documents = {
    'D1': "The cat sat on the mat",
    'D2': "The dog sat on the log",
    'D3': "The cat and the dog are popular pets",
    'D4': "Machine learning finds patterns in data",
    'D5': "Deep learning is a part of machine learning",
    'D6': "Data science uses machine learning and statistics"
}

names = list(documents.keys())
texts = list(documents.values())

print("Documents:")
for name, text in documents.items():
    print(f"{name}: {text}")

# -------------------------------
# 1. Cosine similarity by hand
# -------------------------------

# cos(A, B) = (A . B) / (|A| * |B|)
# 1 = same direction (same words), 0 = no words in common
counter = CountVectorizer()
counts = counter.fit_transform(texts).toarray()

a, b = counts[0], counts[1]
manual = np.dot(a, b) / (np.linalg.norm(a) * np.linalg.norm(b))

print("\nWord-count vectors:")
print(pd.DataFrame(counts[:2], index=names[:2], columns=counter.get_feature_names_out()))
print(f"\nCosine similarity of D1 and D2 (by hand): {manual:.4f}")
print(f"Cosine similarity of D1 and D2 (sklearn): {cosine_similarity([a], [b])[0, 0]:.4f}")

# -------------------------------
# 2. Similarity matrix for all documents
# -------------------------------

count_similarity = pd.DataFrame(cosine_similarity(counts), index=names, columns=names)

# TF-IDF lowers the weight of words that appear everywhere
tfidf = TfidfVectorizer(stop_words='english').fit_transform(texts)
tfidf_similarity = pd.DataFrame(cosine_similarity(tfidf), index=names, columns=names)

print("\nCosine Similarity (word counts):")
print(count_similarity.round(3))

print("\nCosine Similarity (TF-IDF, stop words removed):")
print(tfidf_similarity.round(3))

# Most similar pair, ignoring each document compared with itself
values = tfidf_similarity.values.copy()
np.fill_diagonal(values, 0)
i, j = np.unravel_index(values.argmax(), values.shape)

print(f"\nMost similar pair: {names[i]} and {names[j]} ({values[i, j]:.4f})")
print(f"  {names[i]}: {texts[i]}")
print(f"  {names[j]}: {texts[j]}")

print("\nMost similar document to each:")
for name in names:
    best = tfidf_similarity[name].drop(name).idxmax()
    print(f"{name} -> {best} ({tfidf_similarity.loc[name, best]:.4f})")

fig, axes = plt.subplots(1, 2, figsize=(14, 5.5))

sns.heatmap(count_similarity, annot=True, fmt='.2f', cmap='Blues',
            vmin=0, vmax=1, ax=axes[0])
axes[0].set_title("Cosine Similarity - Word Counts")

sns.heatmap(tfidf_similarity, annot=True, fmt='.2f', cmap='Blues',
            vmin=0, vmax=1, ax=axes[1])
axes[1].set_title("Cosine Similarity - TF-IDF")

plt.tight_layout()
plt.show()
