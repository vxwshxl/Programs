# 32. Information retrieval using TF-IDF.

from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

docs = [
    "Python is a popular programming language for data science and machine learning",
    "Machine learning algorithms learn patterns from data to make predictions",
    "Deep learning uses neural networks with many layers",
    "Pandas and NumPy are Python libraries for data analysis",
    "Football is the most popular sport in the world",
    "The World Cup is a famous football tournament held every four years",
    "Healthy food and regular exercise keep the body fit",
    "Neural networks are inspired by the human brain"]

vectorizer = TfidfVectorizer(stop_words='english')
tfidf = vectorizer.fit_transform(docs)
print("Vocabulary:", vectorizer.get_feature_names_out())

query = "python data analysis"
scores = cosine_similarity(vectorizer.transform([query]), tfidf)[0]
print(f"\nTop results for '{query}':")
for i in scores.argsort()[::-1][:3]:
    print(f"D{i} (Score: {scores[i]:.4f}): {docs[i]}")

# Output:
# Vocabulary: ['algorithms' 'analysis' 'body' 'brain' 'cup' 'data' 'deep' 'exercise'
#  'famous' 'fit' 'food' 'football' 'healthy' 'held' 'human' 'inspired'
#  'language' 'layers' 'learn' 'learning' 'libraries' 'machine' 'make'
#  'networks' 'neural' 'numpy' 'pandas' 'patterns' 'popular' 'predictions'
#  'programming' 'python' 'regular' 'science' 'sport' 'tournament' 'uses'
#  'world' 'years']
#
# Top results for 'python data analysis':
# D3 (Score: 0.6526): Pandas and NumPy are Python libraries for data analysis
# D0 (Score: 0.3311): Python is a popular programming language for data science and machine learning
# D1 (Score: 0.1350): Machine learning algorithms learn patterns from data to make predictions
