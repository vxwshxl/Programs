# 26. Recommendation system using collaborative filtering.

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

# Output:
# User Similarity Matrix:
#         Asha  Rahul  Meera  Arjun  Priya  Karan
# Asha   1.00   0.87   0.80   0.33   0.28   0.87
# Rahul  0.87   1.00   0.63   0.34   0.20   0.61
# Meera  0.80   0.63   1.00   0.39   0.44   0.65
# Arjun  0.33   0.34   0.39   1.00   0.94   0.22
# Priya  0.28   0.20   0.44   0.94   1.00   0.28
# Karan  0.87   0.61   0.65   0.22   0.28   1.00
#
# Priya is most similar to Arjun
# Recommended for Priya: ['Avengers', 'Inception']
