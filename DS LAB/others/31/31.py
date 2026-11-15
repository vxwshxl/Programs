# 31. Text preprocessing: tokenization, stop-word removal, stemming.

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

# Output:
# Tokens: ['data', 'science', 'is', 'an', 'interdisciplinary', 'field', 'that', 'uses', 'scientific', 'methods', 'processes', 'algorithms', 'and', 'systems', 'to', 'extract', 'knowledge', 'from', 'data', 'data', 'scientists', 'are', 'analyzing', 'large', 'datasets', 'building', 'predictive', 'models', 'and', 'communicating', 'their', 'findings', 'clearly', 'the', 'studies', 'of', 'machine', 'learning', 'are', 'running', 'everywhere', 'today']
#
# After Stop-word Removal: ['data', 'science', 'interdisciplinary', 'field', 'uses', 'scientific', 'methods', 'processes', 'algorithms', 'systems', 'extract', 'knowledge', 'data', 'data', 'scientists', 'analyzing', 'large', 'datasets', 'building', 'predictive', 'models', 'communicating', 'findings', 'clearly', 'studies', 'machine', 'learning', 'running', 'everywhere', 'today']
#
# After Stemming: ['data', 'scienc', 'interdisciplinari', 'field', 'use', 'scientif', 'method', 'process', 'algorithm', 'system', 'extract', 'knowledg', 'data', 'data', 'scientist', 'analyz', 'larg', 'dataset', 'build', 'predict', 'model', 'commun', 'find', 'clearli', 'studi', 'machin', 'learn', 'run', 'everywher', 'today']
