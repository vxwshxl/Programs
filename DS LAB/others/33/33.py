# 33. Write a Python program to compute document similarity using cosine similarity.

from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

docs = ["The cat sat on the mat",
        "The dog sat on the log",
        "The cat and the dog are popular pets",
        "Machine learning finds patterns in data",
        "Deep learning is a part of machine learning",
        "Data science uses machine learning and statistics"]

sim = cosine_similarity(TfidfVectorizer().fit_transform(docs))
print("Cosine Similarity Matrix:\n", sim.round(3))
print(f"\nSimilarity (Doc 0 & Doc 1): {sim[0][1]:.4f}")
print(f"Similarity (Doc 0 & Doc 3): {sim[0][3]:.4f}")

# Output:
# Cosine Similarity Matrix:
#  [[1.    0.661 0.443 0.    0.    0.   ]
#  [0.661 1.    0.443 0.    0.    0.   ]
#  [0.443 0.443 1.    0.    0.    0.111]
#  [0.    0.    0.    1.    0.264 0.329]
#  [0.    0.    0.    0.264 1.    0.247]
#  [0.    0.    0.111 0.329 0.247 1.   ]]
#
# Similarity (Doc 0 & Doc 1): 0.6611
# Similarity (Doc 0 & Doc 3): 0.0000
