/*

 * Let a.i refer to the value of the i-th integer (i.e. vertex i), and let
   min refer to the index (i.e. the vertex number) of the smallest integer
   (i.e. the smallest vertex).

   The first observation is that for every pair of distinct vertices, a shortest
   path between them will consist of either 1 edge or 2 edges.
   This is because the minimum possible weight among all the edges of the graph
   is a.min, and for every pair of distinct vertices ('vertex u' and
   'vertex v'), a shortest path between them will either be the edge between
   them, or the edge between 'vertex u' and 'vertex min' followed by the edge
   between 'vertex min' and 'vertex v'.
   [Every path consisting of 3 or more edges will have a weight greater than
    (2 * a.min)]

   Now, the second observation is that for all edges having the same weight, the
   shortest distances between the corresponding end vertices of those edges will
   be the same.
   For eg., if the edge between 'vertex i' and 'vertex j' has a weight of
   5 (say), and the edge between 'vertex k' and 'vertex l' also has a weight of
   5, then the shortest distance between 'vertex i' and 'vertex j' will be equal
   to the shortest distance between 'vertex k' and 'vertex l'.
   If a.min == 2 (say), then this shortest distance will be 2 * 2 (i.e. 4), and
   if a.min == 4 (say), then this shortest distance will be 5.

   Finally, the third observation is that for every edge between 'vertex i' and
   'vertex j' such that (j - i >= 2), there is an edge between 'vertex k' and
   'vertex (k+1)' in the range (i <= k < j) having the same weight.
   For eg., the weight of the edge between 'vertex 1' and 'vertex 10' must be
   equal to the the weight of either the edge between 'vertex 1' and 'vertex 2',
   or the edge between 'vertex 2' and 'vertex 3', or the edge between 'vertex 3'
   and 'vertex 4', ... , or the edge between 'vertex 9' and 'vertex 10'.
   Now, since the diameter of the graph depends upon the shortest distances
   between vertices, therefore from the second observation above, we can say
   that in order to find the diameter, we can discard every edge between
   'vertex i' and 'vertex j' such that (j - i >= 2).

   How do we proceed from here?
   The editorial doesn't explain what exactly we are binary searching for, i.e.
   we are binary searching for the largest possible integer such that ____?

 */
