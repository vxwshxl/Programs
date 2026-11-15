# 34. Write a Python program to create and analyze social network graphs using the NetworkX library.

import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph([('Asha', 'Rahul'), ('Asha', 'Meera'), ('Rahul', 'Meera'), ('Meera', 'Arjun'),
              ('Arjun', 'Priya'), ('Arjun', 'Karan'), ('Priya', 'Karan'), ('Karan', 'Dev')])

print("Nodes:", G.nodes())
print("Edges:", G.edges())
print("Degree:", dict(G.degree()))
print("Shortest path Asha -> Dev:", nx.shortest_path(G, 'Asha', 'Dev'))

nx.draw(G, with_labels=True, node_color='lightgreen', node_size=1200)
plt.title("Friendship Network")
plt.show()
