# 37. Write a Python program to create interactive data visualizations using Plotly.

import plotly.express as px
import plotly.graph_objects as go
from plotly.subplots import make_subplots

# The iris dataset ships with Plotly, so nothing is downloaded
df = px.data.iris()

print("Dataset:")
print(df.head())

summary = df.groupby('species')[['sepal_length', 'sepal_width',
                                 'petal_length', 'petal_width']].mean()
print("\nMean measurements per species:")
print(summary.round(3))

# Four interactive charts in one figure. Hover over points to see values,
# drag to zoom, double-click to reset, click a legend entry to hide a species.
fig = make_subplots(
    rows=2, cols=2,
    subplot_titles=("Scatter: Sepal Length vs Width",
                    "Bar: Mean Petal Length",
                    "Histogram: Petal Length",
                    "Box: Petal Width")
)

colours = {'setosa': '#636EFA', 'versicolor': '#EF553B', 'virginica': '#00CC96'}

for species, colour in colours.items():
    subset = df[df['species'] == species]

    # Only the first chart adds legend entries; legendgroup links the
    # other three, so clicking the legend hides the species everywhere
    fig.add_trace(go.Scatter(
        x=subset['sepal_length'], y=subset['sepal_width'], mode='markers',
        name=species, legendgroup=species, marker=dict(color=colour, size=8),
        hovertemplate="Sepal length: %{x}<br>Sepal width: %{y}"
    ), row=1, col=1)

    fig.add_trace(go.Bar(
        x=[species], y=[summary.loc[species, 'petal_length']],
        name=species, legendgroup=species, showlegend=False, marker_color=colour
    ), row=1, col=2)

    fig.add_trace(go.Histogram(
        x=subset['petal_length'], name=species, legendgroup=species,
        showlegend=False, marker_color=colour, opacity=0.7
    ), row=2, col=1)

    fig.add_trace(go.Box(
        y=subset['petal_width'], name=species, legendgroup=species,
        showlegend=False, marker_color=colour
    ), row=2, col=2)

fig.update_layout(
    title="Iris Dataset - Interactive Dashboard",
    barmode='overlay',
    height=750,
    hovermode='closest'
)

fig.update_xaxes(title_text="Sepal length (cm)", row=1, col=1)
fig.update_yaxes(title_text="Sepal width (cm)", row=1, col=1)
fig.update_yaxes(title_text="Petal length (cm)", row=1, col=2)
fig.update_xaxes(title_text="Petal length (cm)", row=2, col=1)
fig.update_yaxes(title_text="Count", row=2, col=1)
fig.update_yaxes(title_text="Petal width (cm)", row=2, col=2)

print("\nOpening the interactive chart in your browser...")

# Opens in the default web browser (or the Plots pane in Spyder)
fig.show()
