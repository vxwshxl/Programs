# 32. Write a Python program to implement information retrieval using TF-IDF vectorization.

import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

# A small collection of documents to search through
documents = [
    "Python is a popular programming language for data science and machine learning",
    "Machine learning algorithms learn patterns from data to make predictions",
    "Deep learning uses neural networks with many layers",
    "Pandas and NumPy are Python libraries for data analysis",
    "Football is the most popular sport in the world",
    "The World Cup is a famous football tournament held every four years",
    "Healthy food and regular exercise keep the body fit",
    "Neural networks are inspired by the human brain"
]

print("Documents:")
for i, doc in enumerate(documents):
    print(f"D{i}: {doc}")

# TF  (term frequency)          - how often a word appears in this document
# IDF (inverse doc frequency)   - words found in few documents get a higher weight
# TF-IDF = TF x IDF, so common words like "the" count for almost nothing
vectorizer = TfidfVectorizer(stop_words='english')
tfidf_matrix = vectorizer.fit_transform(documents)

vocabulary = vectorizer.get_feature_names_out()

print("\nVocabulary size:", len(vocabulary))
print("TF-IDF matrix shape:", tfidf_matrix.shape, "(documents x words)")

# IDF of a few words: rarer words are worth more
idf = pd.Series(vectorizer.idf_, index=vocabulary)
print("\nIDF of selected words:")
print(idf[['data', 'learning', 'python', 'football', 'brain']].round(4))

# The highest-weighted words in each document
tfidf_df = pd.DataFrame(tfidf_matrix.toarray(), columns=vocabulary)

print("\nTop 3 words per document:")
for i, row in tfidf_df.iterrows():
    top = row.sort_values(ascending=False).head(3)
    print(f"D{i}: {', '.join(f'{word} ({score:.2f})' for word, score in top.items())}")


def search(query, top_n=3):
    # The query is turned into a vector with the same vocabulary,
    # then compared against every document
    query_vector = vectorizer.transform([query])
    scores = cosine_similarity(query_vector, tfidf_matrix)[0]

    ranking = scores.argsort()[::-1][:top_n]
    return [(i, scores[i]) for i in ranking if scores[i] > 0]


queries = ["python data analysis", "neural networks", "football world cup", "cooking recipes"]

for query in queries:
    print(f"\nQuery: '{query}'")
    results = search(query)

    if not results:
        print("  No relevant documents found")

    for rank, (i, score) in enumerate(results, 1):
        print(f"  {rank}. D{i} (score {score:.4f}): {documents[i]}")
