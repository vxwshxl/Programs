# 26. Write a Python program to develop a recommendation system using collaborative filtering.

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.metrics.pairwise import cosine_similarity

# User-movie ratings (1 to 5). 0 means the user has not rated that movie.
ratings = pd.DataFrame({
    'Inception':     [5, 4, 0, 1, 0, 5],
    'Interstellar':  [5, 5, 4, 0, 1, 4],
    'The Matrix':    [4, 0, 5, 1, 2, 5],
    'Titanic':       [1, 1, 0, 5, 4, 0],
    'The Notebook':  [0, 1, 1, 5, 5, 1],
    'La La Land':    [1, 0, 2, 4, 5, 0],
    'Avengers':      [4, 5, 4, 2, 0, 0]
}, index=['Asha', 'Rahul', 'Meera', 'Arjun', 'Priya', 'Karan'])

print("User-Movie Rating Matrix:")
print(ratings)

# -------------------------------
# 1. User-based collaborative filtering
# -------------------------------

# Two users are similar if they rated the same movies the same way
user_similarity = pd.DataFrame(
    cosine_similarity(ratings),
    index=ratings.index, columns=ratings.index
)

print("\nUser Similarity (cosine):")
print(user_similarity.round(3))


def predict_rating(user, movie):
    # Weighted average of what similar users gave this movie,
    # using only the users who actually rated it
    others = ratings.index[(ratings[movie] > 0) & (ratings.index != user)]
    weights = user_similarity.loc[user, others]

    if weights.sum() == 0:
        return 0

    return np.dot(weights, ratings.loc[others, movie]) / weights.sum()


def recommend(user, top_n=2):
    unrated = ratings.columns[ratings.loc[user] == 0]
    predictions = {movie: predict_rating(user, movie) for movie in unrated}
    return sorted(predictions.items(), key=lambda item: item[1], reverse=True)[:top_n]


for user in ['Asha', 'Priya', 'Karan']:
    most_similar = user_similarity[user].drop(user).idxmax()
    print(f"\n{user} is most similar to {most_similar}")
    print(f"Recommendations for {user}:")
    for movie, score in recommend(user):
        print(f"  {movie:15s} predicted rating: {score:.2f}")

# -------------------------------
# 2. Item-based collaborative filtering
# -------------------------------

# Two movies are similar if the same users rated them the same way
item_similarity = pd.DataFrame(
    cosine_similarity(ratings.T),
    index=ratings.columns, columns=ratings.columns
)

print("\nMovies most similar to each other (item-based):")
for movie in ['Inception', 'Titanic']:
    similar = item_similarity[movie].drop(movie).sort_values(ascending=False)
    print(f"Because you liked {movie}: {list(similar.index[:2])}")

# -------------------------------
# 3. Plot the ratings and the similarity between users
# -------------------------------

fig, axes = plt.subplots(1, 2, figsize=(15, 5.5))

sns.heatmap(ratings, annot=True, cmap='YlGnBu', ax=axes[0])
axes[0].set_title("Ratings (0 = not rated)")

sns.heatmap(user_similarity, annot=True, fmt='.2f', cmap='coolwarm', ax=axes[1])
axes[1].set_title("User-User Cosine Similarity")

plt.tight_layout()
plt.show()
