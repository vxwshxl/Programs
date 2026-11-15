# 27. Write a Python program to implement a content-based recommendation system.

import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

# Content-based filtering needs no other users - only a description of each item
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
        'A love story about pride, class and family in old England'
    ]
})

print("Movies:")
print(movies[['Title', 'Genre']].to_string(index=False))

# Combine genre and description into one text per movie.
# Genre is repeated so it counts for more than a single word in the plot.
movies['Content'] = (movies['Genre'] + ' ') * 2 + movies['Description']

# TF-IDF turns each text into a vector of word weights
vectorizer = TfidfVectorizer(stop_words='english')
tfidf_matrix = vectorizer.fit_transform(movies['Content'])

print("\nTF-IDF matrix shape:", tfidf_matrix.shape, "(movies x words)")

# Similarity of every movie to every other movie
similarity = cosine_similarity(tfidf_matrix)


def recommend(title, top_n=3):
    index = movies.index[movies['Title'] == title][0]

    scores = pd.Series(similarity[index], index=movies['Title'])
    scores = scores.drop(title).sort_values(ascending=False)

    return scores.head(top_n)


for title in ['Interstellar', 'Titanic', 'Iron Man']:
    print(f"\nBecause you watched {title}:")
    for movie, score in recommend(title).items():
        print(f"  {movie:22s} similarity: {score:.3f}")

# Recommend from a user's profile: the average vector of everything they liked
liked = ['Inception', 'The Matrix']
liked_rows = movies.index[movies['Title'].isin(liked)]

profile = tfidf_matrix[liked_rows].mean(axis=0)
profile_scores = cosine_similarity(profile.A, tfidf_matrix)[0]

ranking = pd.Series(profile_scores, index=movies['Title'])
ranking = ranking.drop(liked).sort_values(ascending=False)

print(f"\nUser liked {liked}")
print("Recommended for this user:")
for movie, score in ranking.head(3).items():
    print(f"  {movie:22s} score: {score:.3f}")
