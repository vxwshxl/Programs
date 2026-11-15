# 34. Create and analyze social network graphs using NetworkX.

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

# Output:
# Nodes: ['Asha', 'Rahul', 'Meera', 'Arjun', 'Priya', 'Karan', 'Dev']
# Edges: [('Asha', 'Rahul'), ('Asha', 'Meera'), ('Rahul', 'Meera'), ('Meera', 'Arjun'), ('Arjun', 'Priya'), ('Arjun', 'Karan'), ('Priya', 'Karan'), ('Karan', 'Dev')]
# Degree: {'Asha': 2, 'Rahul': 2, 'Meera': 3, 'Arjun': 3, 'Priya': 2, 'Karan': 3, 'Dev': 1}
# Shortest path Asha -> Dev: ['Asha', 'Meera', 'Arjun', 'Karan', 'Dev']
