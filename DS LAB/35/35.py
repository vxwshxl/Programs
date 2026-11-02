# 35. Write a Python program to detect communities in a social network graph.

import matplotlib.pyplot as plt
import networkx as nx
from networkx.algorithms import community

# Zachary's Karate Club. After a dispute the club really did split in two,
# so we know the true communities and can check our answers.
G = nx.karate_club_graph()

actual = [
    {n for n in G.nodes if G.nodes[n]['club'] == 'Mr. Hi'},
    {n for n in G.nodes if G.nodes[n]['club'] == 'Officer'}
]

print("Nodes:", G.number_of_nodes(), " Edges:", G.number_of_edges())


def show(name, communities):
    communities = sorted(communities, key=len, reverse=True)
    print(f"\n{name}")
    print("Number of communities:", len(communities))
    for i, members in enumerate(communities, 1):
        print(f"  Community {i} ({len(members)} members): {sorted(members)}")

    # Modularity: how many more edges fall inside communities than chance
    # would predict. Above about 0.3 usually means real structure.
    print("Modularity:", round(community.modularity(G, communities), 4))


show("Actual Split (ground truth)", actual)

# 1. Greedy modularity: start with every node alone, keep merging
#    the pair of communities that raises modularity the most
greedy = community.greedy_modularity_communities(G)
show("Greedy Modularity", greedy)

# 2. Louvain: the same goal, but moves single nodes between communities first
louvain = community.louvain_communities(G, seed=42)
show("Louvain", louvain)

# 3. Label propagation: every node repeatedly takes the most common label
#    among its neighbours until nothing changes
label_prop = list(community.label_propagation_communities(G))
show("Label Propagation", label_prop)

# 4. Girvan-Newman: keep removing the edge with the highest betweenness;
#    the graph falls apart into communities
girvan = next(community.girvan_newman(G))
show("Girvan-Newman (first split)", girvan)

# How many members Girvan-Newman put on the right side of the real split
correct = max(len(girvan[0] & actual[0]) + len(girvan[1] & actual[1]),
              len(girvan[0] & actual[1]) + len(girvan[1] & actual[0]))
print(f"\nGirvan-Newman matched the real split for {correct} of {G.number_of_nodes()} members")

pos = nx.spring_layout(G, seed=42)
results = [("Actual Split", actual), ("Greedy Modularity", greedy),
           ("Louvain", louvain), ("Girvan-Newman", girvan)]

fig, axes = plt.subplots(1, 4, figsize=(22, 5.5))

for ax, (title, communities) in zip(axes, results):
    colour = {}
    for i, members in enumerate(communities):
        for node in members:
            colour[node] = i

    nx.draw(G, pos, ax=ax, with_labels=True, font_size=8, node_size=300,
            node_color=[colour[n] for n in G.nodes], cmap='Set2', edge_color='gray')
    ax.set_title(f"{title}\n{len(communities)} communities, "
                 f"modularity {community.modularity(G, communities):.3f}")

plt.tight_layout()
plt.show()
