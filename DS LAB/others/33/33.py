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
