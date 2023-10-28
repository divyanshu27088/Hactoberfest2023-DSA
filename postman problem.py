//The postman problem is a classic problem in graph theory. 
//It involves finding the shortest possible route that visits each node in a graph at least once and then returns to the starting node. 
//You can solve this problem using the Held-Karp algorithm for finding the optimal solution in polynomial time for small graphs
import networkx as nx

# Create a graph
G = nx.Graph()

# Add edges to the graph
G.add_edge('A', 'B', weight=3)
G.add_edge('A', 'C', weight=4)
G.add_edge('B', 'C', weight=2)
G.add_edge('B', 'D', weight=5)
G.add_edge('C', 'D', weight=1)

# Find the minimum weight perfect matching
odd_degree_nodes = [v for v, d in G.degree() if d % 2 == 1]
G.add_edges_from(nx.complete_graph(odd_degree_nodes).edges)

# Find the Eulerian circuit
eulerian_circuit = list(nx.eulerian_circuit(G))

# Compute the minimum weight perfect matching
min_weight_perfect_matching = sum([G[u][v]['weight'] for u, v in eulerian_circuit])

print("Minimum Weight Perfect Matching:", min_weight_perfect_matching)
print("Eulerian Circuit:", eulerian_circuit)
