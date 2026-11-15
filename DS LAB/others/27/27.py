# 27. Content-based recommendation system.

import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

movies = pd.DataFrame({
    'Title': ['Inception', 'Interstellar', 'The Matrix', 'Titanic',
              'The Notebook', 'La La Land', 'Avengers', 'Iron Man',
              'Gravity', 'Pride and Prejudice'],
    'Genre': ['SciFi Thriller', 'SciFi Adventure', 'SciFi Action', 'Romance Drama',
              'Romance Drama', 'Romance Musical', 'Action Superhero', 'Action Superhero',
              'SciFi Thriller', 'Romance Drama'],
    'Description': [
        'A thief enters dreams to steal secrets and plant an idea in a mind',
        'Astronauts travel through a wormhole in space to save humanity',
        'A hacker learns reality is a simulation and fights the machines',
        'A love story aboard a ship that sinks in the ocean',
        'A young couple falls in love despite family and class differences',
        'A musician and an actress fall in love while chasing dreams in the city',
        'Superheroes team up to save the world from an alien invasion',
        'A billionaire engineer builds a powered suit and becomes a superhero',
        'Astronauts are stranded in space after an accident and fight to survive',
        'A love story about pride, class and family in old England']})

tfidf = TfidfVectorizer(stop_words='english').fit_transform(movies['Genre'] + ' ' + movies['Description'])
sim = cosine_similarity(tfidf)

scores = pd.Series(sim[1], index=movies['Title']).drop('Interstellar').sort_values(ascending=False)
print("Recommendations for 'Interstellar':\n", scores.head(3).round(3))

# Output:
# Recommendations for 'Interstellar':
#  Title
# Gravity       0.285
# Avengers      0.106
# The Matrix    0.064
# dtype: float64
