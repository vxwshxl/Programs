# 13. Ridge and Lasso Regression.

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import Ridge, Lasso

df = pd.DataFrame({
    'Experience': range(1, 16),
    'Education': [12, 14, 16, 16, 14, 18, 16, 18, 20, 16, 18, 20, 18, 20, 22],
    'Projects': [2, 3, 5, 4, 6, 7, 6, 8, 9, 8, 10, 11, 10, 12, 13],
    'Distance': [12, 30, 8, 25, 40, 15, 33, 6, 22, 18, 35, 10, 28, 20, 14],
    'Salary': [39000, 44500, 49500, 50500, 53000, 59500, 61000, 68500,
               71000, 69000, 76500, 81500, 81000, 85000, 91500]})
X_train, X_test, y_train, y_test = train_test_split(df.drop(columns='Salary'), df['Salary'], test_size=0.3, random_state=1)

for name, m in [('Ridge', Ridge(alpha=1.0)), ('Lasso', Lasso(alpha=100.0, max_iter=10000))]:
    model = make_pipeline(StandardScaler(), m).fit(X_train, y_train)
    print(f"{name} R2 Score:", model.score(X_test, y_test))
    print(f"{name} Coefs:", m.coef_.round(2))

# Output:
# Ridge R2 Score: 0.9735442276317761
# Ridge Coefs: [7769.75 3114.27 5702.76 -193.01]
# Lasso R2 Score: 0.9800886182117426
# Lasso Coefs: [13465.47  3363.96   408.81    -0.  ]
