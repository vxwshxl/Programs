# 37. Interactive data visualization using Plotly.

import plotly.express as px

df = px.data.iris()
fig = px.scatter(df, x='sepal_length', y='sepal_width', color='species',
                 size='petal_length', hover_data=['petal_width'], title="Interactive Iris Scatter Plot")
fig.show()

# Output:
# (opens an interactive Plotly dashboard in the web browser - no printed output)
