/*
    =======================================================
    Basic Terms:
    =======================================================

      Graph: A collection of vertices (nodes) and edges (connections) that can represent relationships between objects.

      Vertex (Node): The fundamental unit of a graph, representing an entity (e.g., a person in a social network).

      Edge: A connection between two vertices. It can be directed (one-way) or undirected (two-way).

      Directed Graph (Digraph): A graph where edges have a direction, indicating a one-way relationship.

      Undirected Graph: A graph where edges have no direction, indicating a two-way relationship.

      Weighted Graph: A graph in which edges have weights (values) representing costs, distances, or other metrics.

      Unweighted Graph: A graph where edges do not have weights.



    =======================================================
    Types of Graphs:
    =======================================================

      Simple Graph: A graph with no multiple edges and no loops (edges connecting a vertex to itself).

      Multigraph: A graph that allows multiple edges between the same pair of vertices.

      Complete Graph: A graph where there is an edge between every pair of vertices.

      Cycle: A path in a graph that starts and ends at the same vertex without repeating any edges or vertices.

      Acyclic Graph: A graph that does not contain any cycles.

      Tree: A special type of acyclic graph that is connected and has no cycles.

      Forest: A collection of disjoint trees.

      Connected Graph: A graph in which there is a path between every pair of vertices.

      Disconnected Graph: A graph in which at least one pair of vertices does not have a path connecting them.



    =======================================================
    Graph Representations:
    =======================================================

      Adjacency Matrix: A 2D array where the rows and columns represent vertices, and the values indicate whether an edge exists between them.

      Adjacency List: An array (or list) of lists where each list represents a vertex and contains the vertices to which it is connected.

      Incidence Matrix: A matrix that shows the relationship between vertices and edges.



    =======================================================
    Graph Traversal:
    =======================================================

      Depth-First Search (DFS): An algorithm for traversing or searching through a graph that explores as far as possible along each branch before backtracking.

      Breadth-First Search (BFS): An algorithm for traversing or searching through a graph that explores all the neighbors at the present depth before moving on to nodes at the next depth level.

      Additional Concepts
      Subgraph: A graph formed from a subset of the vertices and edges of another graph.

      Path: A sequence of edges that connects a sequence of vertices.

      Degree of a Vertex: The number of edges connected to a vertex. In a directed graph, it can be split into in-degree and out-degree.

      Source Vertex: A vertex with an out-degree greater than zero but an in-degree of zero.

      Sink Vertex: A vertex with an in-degree greater than zero but an out-degree of zero.

      Graph Isomorphism: A condition where two graphs can be transformed into each other by renaming vertices.

      Eulerian Path/Circuit: A path (or circuit) that visits every edge in the graph exactly once.

      Hamiltonian Path/Circuit: A path (or circuit) that visits every vertex in the graph exactly once.

      Graph Coloring: The assignment of colors to vertices of a graph such that no two adjacent vertices share the same color.

*/