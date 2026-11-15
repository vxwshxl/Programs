# 31. Write a Python program to perform text preprocessing including tokenization, stop-word removal, and stemming.

import nltk
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer

nltk.download('punkt_tab', quiet=True)
nltk.download('stopwords', quiet=True)

text = """Data Science is an interdisciplinary field that uses scientific methods,
processes, algorithms and systems to extract knowledge from data. Data scientists
are analyzing large datasets, building predictive models, and communicating their
findings clearly. The studies of machine learning are running everywhere today!"""

tokens = [w for w in word_tokenize(text.lower()) if w.isalnum()]
filtered = [w for w in tokens if w not in stopwords.words('english')]
stemmed = [PorterStemmer().stem(w) for w in filtered]

print("Tokens:", tokens)
print("\nAfter Stop-word Removal:", filtered)
print("\nAfter Stemming:", stemmed)
