# Question
There are `n` computers numbered from `0` to `n - 1` connected by ethernet cables `connections` forming a network where `connections[i] = [ai, bi]` represents a connection between computers `ai` and `bi`. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network `connections`. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return `-1`.

**Example 1:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2020/01/02/sample_1_1677.png)
```
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
```
**Example 2:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2020/01/02/sample_2_1677.png)
```
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
```
**Example 3:**<br/>
```
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
```

**Constraints:**

- `2 <= n <= 10^5`
- `1 <= connections.length <= min(n * (n - 1) / 2, 105)`
- `connections[i].length == 2`
- `1 <= ai, bi <= n`
- `ai != bi`
- There are no repeated connections.
- No two computers are connected by more than one cable.

<h1 align="center">Solution</h1>

# Breath First Search

## Intuition
This code is an implementation of a function that takes as input the number of nodes `n` and a list of `connections` between nodes connections, and returns the minimum number of extra connections needed to make all nodes connected in the graph.

The function first checks if the number of connections is less than `n-1`, in which case it is impossible to connect all nodes and the function returns -1.

Then, it initializes an adjacency list `adj` for the graph using the `connections` list. The `adj` list stores for each node all its adjacent nodes.

Next, the function counts the number of connected components in the graph using a breadth-first search (BFS) algorithm. For each unvisited node, the BFS algorithm visits all its adjacent nodes and marks them as visited. The number of times the BFS algorithm is called corresponds to the number of connected components in the graph.

Finally, the function returns the number of extra connections needed to connect all nodes in the graph, which is equal to the number of connected components minus one.

The `bfs` function is a helper function that performs a BFS traversal starting from a given node and marks all visited nodes in the `isVisited` list.

## Approach
1. Check if the number of connections is less than `n-1`. If so, it is impossible to connect all nodes and return `-1`. 
2. Create an adjacency list `adj` for the graph using the connections list. For each connection in `connections`, add the two nodes to each other's adjacency list. 

3. Initialize a counter `NumberofConnected` to 0, which will count the number of connected components in the graph. 

4. Create a boolean list `isVisited` to keep track of visited nodes, initialized to false for all nodes. 

5. Loop through all nodes from 0 to n-1. For each node that is not yet visited, increment `NumberofConnected` and call the `bfs` function to visit all its adjacent nodes. 

6. The `bfs` function takes the adjacency list adj, a starting node, and the `isVisited` list. It performs a BFS traversal starting from the starting node, adding all unvisited adjacent nodes to the queue and marking them as visited in the `isVisited` list. 

7. After the loop in step 5, return the number of extra connections needed to connect all nodes in the graph, which is equal to the number of connected components minus one. 

## Complexity
- Time complexity: O(V+E), where V is the number of vertices and E is the number of edges in the graph.

- Space complexity: O(V+E), where V is the number of vertices and E is the number of edges in the graph.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/number-of-operations-to-make-network-connected/solutions/3333748/easy-solution-in-cpp-using-queues-bfs-algorithm/)



# Deapth First Search

## Intuition
This code is implementing a function called `makeConnected` which takes an integer `n` representing the number of nodes in a network and a vector of vectors called `connections` representing the connections between those nodes. The function returns the minimum number of cables required to connect all the nodes in the network. If it is not possible to connect all nodes, the function returns -1. 

The function first checks if the number of connections is less than n-1, which is the minimum number of connections required to make the network connected. If this is the case, it means that it is not possible to connect all the nodes, and the function returns -1. 

If there are enough connections, the function creates an adjacency list called adj which stores the connections between the nodes. It then initializes a variable called `NumberofConnected` to zero and creates a boolean vector called `isVisited` which stores whether a node has been visited or not. 

The function then loops through all the nodes in the network, and if a node has not been visited yet, it increments `NumberofConnected` and performs a depth-first search (DFS) on that node to mark all nodes connected to it as visited. 

The `dfs` function is called to perform the DFS search. It takes the adjacency list, the current node, and the `isVisited` vector as input. The function first marks the current node as visited in the `isVisited` vector. It then loops through all the neighbors of the current node and recursively calls the `dfs` function on each unvisited neighbor. 

Finally, the `makeConnected` function returns the difference between `NumberofConnected` and 1, since that is the minimum number of cables required to connect all the nodes in the network. 

 

## Approach
The problem asks to find the minimum number of cables required to connect all the nodes in a network. To connect all the nodes, the network must be connected, which means that all nodes must be reachable from each other. 

We can start by checking if the given network is already connected or not. If it is connected, no cables are required, and we can return 0. If the network is not connected, we need to add cables to connect the nodes. 

To connect the nodes, we can start by selecting any unconnected node and perform a depth-first search (DFS) on that node to mark all nodes connected to it as visited. We repeat this process for any unvisited nodes until all nodes are visited. 

Each time we perform a DFS, we increment a counter that represents the number of connected components in the network. The minimum number of cables required to connect all the nodes in the network is equal to the number of connected components minus 1. 

If there are fewer connections than n-1, the network cannot be connected, and we should return -1. 

Therefore, the `makeConnected` function implementation follows this approach by first checking if there are enough connections to connect all the nodes. If not, it returns -1. If there are enough connections, it uses DFS to mark all the connected nodes and counts the number of connected components. Finally, it returns the minimum number of cables required to connect all the nodes. 

 

## Complexity
- Time complexity: O(V+E), where V is the number of vertices and E is the number of edges in the graph.

- Space complexity: O(V+E), where V is the number of vertices and E is the number of edges in the graph.


## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/number-of-operations-to-make-network-connected/solutions/3333775/easy-solution-in-cpp-using-recursion-dfs-algorithm/)