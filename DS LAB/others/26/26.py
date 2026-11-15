# 26. Write a Python program to develop a recommendation system using collaborative filtering.

import pandas as pd
from sklearn.metrics.pairwise import cosine_similarity

ratings = pd.DataFrame({
    'Inception':     [5, 4, 0, 1, 0, 5],
    'Interstellar':  [5, 5, 4, 0, 1, 4],
    'The Matrix':    [4, 0, 5, 1, 2, 5],
    'Titanic':       [1, 1, 0, 5, 4, 0],
    'The Notebook':  [0, 1, 1, 5, 5, 1],
    'La La Land':    [1, 0, 2, 4, 5, 0],
    'Avengers':      [4, 5, 4, 2, 0, 0]
}, index=['Asha', 'Rahul', 'Meera', 'Arjun', 'Priya', 'Karan'])

sim = pd.DataFrame(cosine_similarity(ratings), index=ratings.index, columns=ratings.index)
print("User Similarity Matrix:\n", sim.round(2))

user = 'Priya'
similar = sim[user].drop(user).idxmax()
recs = ratings.loc[similar, ratings.loc[user] == 0].sort_values(ascending=False)
print(f"\n{user} is most similar to {similar}")
print(f"Recommended for {user}:", list(recs.index))
