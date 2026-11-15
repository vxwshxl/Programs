# 31. Write a Python program to perform text preprocessing including tokenization, stop-word removal, and stemming.

import string
import nltk
from nltk.tokenize import sent_tokenize, word_tokenize
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer, SnowballStemmer, LancasterStemmer

# Download the tokenizer and stop-word list only if they are missing
for resource, path in [('punkt_tab', 'tokenizers/punkt_tab'),
                       ('stopwords', 'corpora/stopwords')]:
    try:
        nltk.data.find(path)
    except LookupError:
        nltk.download(resource, quiet=True)

text = """Data Science is an interdisciplinary field that uses scientific methods,
processes, algorithms and systems to extract knowledge from data. Data scientists
are analyzing large datasets, building predictive models, and communicating their
findings clearly. The studies of machine learning are running everywhere today!"""

print("Original Text:")
print(text)

# 1. Sentence tokenization
sentences = sent_tokenize(text)

print("\nSentences:")
for i, sentence in enumerate(sentences, 1):
    print(f"{i}. {sentence}")

# 2. Word tokenization
tokens = word_tokenize(text)
print("\nWord Tokens:")
print(tokens)
print("Number of tokens:", len(tokens))

# 3. Lowercase and remove punctuation
tokens = [word.lower() for word in tokens if word not in string.punctuation]
print("\nAfter lowercasing and removing punctuation:")
print(tokens)

# 4. Stop-word removal: drop common words that carry little meaning
stop_words = set(stopwords.words('english'))
filtered = [word for word in tokens if word not in stop_words]

print("\nStop words removed:", [word for word in tokens if word in stop_words])
print("\nAfter stop-word removal:")
print(filtered)
print("Tokens left:", len(filtered), "of", len(tokens))

# 5. Stemming: cut each word down to its root
porter = PorterStemmer()
stemmed = [porter.stem(word) for word in filtered]

print("\nAfter Porter stemming:")
print(stemmed)

# Different stemmers cut more or less aggressively
snowball = SnowballStemmer('english')
lancaster = LancasterStemmer()

print("\nStemmer Comparison:")
print(f"{'Word':15s}{'Porter':12s}{'Snowball':12s}{'Lancaster':12s}")
for word in ['analyzing', 'scientists', 'studies', 'running', 'communicating', 'clearly']:
    print(f"{word:15s}{porter.stem(word):12s}{snowball.stem(word):12s}{lancaster.stem(word):12s}")

# Most frequent stems in the cleaned text
frequency = nltk.FreqDist(stemmed)
print("\nMost common stems:", frequency.most_common(5))
