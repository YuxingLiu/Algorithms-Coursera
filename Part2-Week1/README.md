# Algorithm-Part2-Week1
Breatdth-first and depth-first search, strongly connected components.

## Problem 1

The file [SCC.txt](https://d18ky98rnyall9.cloudfront.net/_410e934e6553ac56409b2cb7096a44aa_SCC.txt?Expires=1571097600&Signature=ayXhR09wt7t57qDkQMWtleN0UfF6IpvK4Y5zYJ9hdr0y-tw6w4kV7uOSxhiZGVIZGODe3WcSLG9tvnBj4z6R8aN7mRSb4dpDtOmwuk~4cQPMMloK5WNZIJRZtukRd~kp~wFXy9fp2Dwig6CFc3Dfz352kNwY673lsxsY8tQKjyo_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A) contains the edges of a directed graph. Vertices are labeled as positive integers from 1 to 875714. Every row indicates an edge, the vertex label in first column is the tail and the vertex label in second column is the head (recall the graph is directed, and the edges are directed from the first column vertex to the second column vertex). So for example, the 11^{th} row looks liks : "2 47646". This just means that the vertex with label 2 has an outgoing edge to the vertex with label 47646.

Your task is to code up the algorithm from the video lectures for computing strongly connected components (SCCs), and to run this algorithm on the given graph.

Output Format: You should output the sizes of the 5 largest SCCs in the given graph, in decreasing order of sizes, separated by commas (avoid any spaces). So if your algorithm computes the sizes of the five largest SCCs to be 500, 400, 300, 200 and 100, then your answer should be "500,400,300,200,100" (without the quotes). If your algorithm finds less than 5 SCCs, then write 0 for the remaining terms. Thus, if your algorithm computes only 3 SCCs whose sizes are 400, 300, and 100, then your answer should be "400,300,100,0,0" (without the quotes). (Note also that your answer should not have any spaces in it.)

WARNING: This is the most challenging programming assignment of the course. Because of the size of the graph you may have to manage memory carefully. The best way to do this depends on your programming language and environment, and we strongly suggest that you exchange tips for doing this on the discussion forums.
