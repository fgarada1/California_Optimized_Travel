## Leading Question 
What is the most optimal way to get from Point A to Point B in the state of San Francisco, California? Given a pair of endpoints, our algorithm will find the most optimal route between the two destinations. We will optimize based on the amount of roads or the geographical distance between two points depending on what the user chooses. We will use the A* Algorithm in order to find the shortest path between two nodes.
## Dataset Acquisition

1. **Data Format**
We will be using the following dataset: https://www.cs.utah.edu/~lifeifei/SpatialDataset.htm. The dataset includes road data for the entirety of California, but since that is a lot of data, we will focus on one subset - the city of San Francisco, for which there is a separate dataset. The format of this dataset is Start Nodes, End Nodes, and Length of Edge. 

2. **Data Correction**
We will  restrict our dataset to the area that we are interested in (San Francisco) so we will check for and remove nodes that are not within this area. We will also check for negative edge lengths, and remove those as well. As we go through the CSV, we will condense each entry into a node with only the relevant information necessary for answering the leading question for this project, and adding more things if needed. We will connect the nodes to form a weighted, undirected graph. This graph will be an adjacency matrix, whose weights will be the distance between two points. The storage space for this graph will be O(n^2).



3. **Data Storage**
We will use a priority queue in order to help with the Floyd-Warshall’s Algorithm and the A* Algorithm. Additionally, we will use an adjacency matrix to store the connection between nodes and edges. Each node will have an entry that represents what it connects to. The weights for the edges will be the distances between the two nodes.

## Algorithm 
1. **BFS (Traversal)**
The user will input a starting point and a range. We will use a Breadth First Traversal in order to retireve all nodes that can be reached by traveling within an inputed range, from the starting point. We will a return a vector of locations (represented by the nodes). The worst-case Big-O Runtime and space-complexity for our traversal is O(n).
If our program is too slow because of the dataset being too big for this runtime, then we will try to find a way to optimize it and reduce the runtime, possibly by implementing an AVL tree which would reduce the worst-case runtime of BFS to O(logn). The worst case space-complexity is O(n^2) since we are using an adjacency matrix.

2. **Floyd-Warshall (Covered)**
The algorithm will return the shortest path between all pairs of nodes in our graph. The input will be an adjacency matrix with the rows and columns represented by locations, and the content of the matrix representing the distances between the locations, only using direct connections. The output will be two adjacency matrices where each row and column once again represent all the locations. The content of the first matrix will be the shortest distance between every x and y location points, and the content of the second matrix will contain the locations that allow for the quickest path from one location point x to another location point y.
Since we are using an adjacency matrix, the worst-case Big-O Runtime for our algorithm is O(n^3) and the worst case space-complexity is O(n^2).

3. **A* Search (Complex/Uncovered)**
The input for our A* Search algorithm will be two nodes each representing a location, an adjacency matrix with the rows and columns represented by locations, and the content of the matrix representing the distances between the locations, only using direct connections. The algorithm will return the shortest path (a vector of locations) between the two points. 
Since we are using a priority queue with a binary heap implementation and adjacency matrix, the worst-case Big-O Runtime for our algorithm is O(n^2). The worst case space-complexity is O(n^2) since we are using an adjacency matrix.
(This was omitted in the original project proposal, but the heuristic for this algorithm is the geographical distance between two locations.)

## Timeline

Note: Test cases for each section of the project should be worked on and are due at the same time that each project deadline is due.

- Team Contract, Final Project Proposal, Github Repo Creation, Development Log (Due Nov 4th)

- Team meeting (Every wednesday starting on (Nov 9th)

- Have the data structure set up to hold the algorithm, Parse the CSV, Development Log Due (Nov 11th)

- Mid-Project Checkin (November 14th – 18th)

- Have BFS done, Start Floyd-Warshall, Development Log Due (Nov 18th)

- Finish Floyd-Warshall algorithm, Have A* and most of the project done, focus on integration testing (Nov 27th)

- Work on anything that was left over and needed more time, Development Log Due (Dec 2nd)

- Film the video, and also make arrangements for the video (Dec 4th)

- Edit the video and add final additions to the project (Dec 5th)

- Final Project Due (Dec 8th)
