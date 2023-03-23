# Question
You are given a positive integer `n` representing `n` cities numbered from `1` to `n`. You are also given a**2D** array `roads` where `roads[i] = [ai, bi, distancei]` indicates that there is a bidirectional road between cities `ai` and `bi` with a distance equal to `distancei`. The cities graph is not necessarily connected.

The **score** of a path between two cities is defined as the **minimum** distance of a road in this path.

Return the **minimum** possible score of a path between cities `1` and `n`.

**Note:**

- A path is a sequence of roads between two cities.
- It is allowed for a path to contain the same road multiple times, and you can visit cities `1` and `n` multiple times along the path.
- The test cases are generated such that there is at least one path between `1` and `n`.

**Example 1:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2022/10/12/graph11.png)
```
Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.
```
**Example 2:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2022/10/12/graph22.png)
```
Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
Output: 2
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.
```

**Constraints:**

- `2 <= n <= 105`
- `1 <= roads.length <= 105`
- `roads[i].length == 3`
- `1 <= ai, bi <= n`
- `ai != bi`
- `1 <= distancei <= 104`
- There are no repeated edges.
- There is at least one path between `1` and `n`.

<h1 align="center">Solution</h1>

# Breath First Search

## Intuition
In this algorithm, the main aim for us is to reconstruct the cities in such a way that we know what cities each city is connected to and what the distance between these cities is.

so why I did so ?
Actually, if we construct the roads, we can easily know all the distances between this city and all the connected cities. and then move from this city to one of the connected cities, and repeat this process again until the end [all cities are visited]. Once we reach the end of all cities, we return the minimum score of the path.

This algorithm is called `Breadth First Search`, which we will explain the implementation in the next section.

## Make it clear
To reconstruct the roads vector, we require a vector of vectors of pairs, which is a data structure that stores two related pieces of data. This vector will be of size (n+1), which is one more than the size of the road vector. The reason for using a vector of vector of pairs is that the inner vector represents all the data related to a specific node based on its index (e.g., v[2] represents node #2), and each inner vector contains pairs that denote the connected city and the distance between the two cities.

For instance, the adjusted vector example provided is adj = [[], [(2, 7), (4, 8)], [(1, 7), (3, 6), (4, 5)], [(2, 6)], [(1, 8), (2, 5)]]. This means that adj[2] represents all the connected cities to city #2. The pair (1, 7) denotes that it is connected to city #1 with a distance of 7, while (3, 6) means it is connected to city #3 with a distance of 6, and so on until the end.

The reason why we need a vector of size (n+1) is now clear. When a city is indexed as #n, it needs an index in n, so we require an additional cell for it.

The second part of this algorithm deals with determining the current city, identifying the next city, and verifying if it has already been visited or not. To accomplish this, we will use a queue data structure. Initially, we will add the starting city (city #1) to the queue and check its connected cities to find the minimum distance. We will then add these connected cities to the queue and mark them as visited to ensure we don't revisit them again. We will continue this process until the queue becomes empty, which signifies that all the cities have been visited.

## Approach
1. Create a vector of vectors of pairs `adjacency list` to store the cities and their connected cities with their distances.
2. Create a boolean vector `isVisited` of size n+1 to mark visited cities. Initially, set all cities as unvisited.
3. Create a queue data structure to store the cities and their distances.
4. Add the starting city to the queue, mark it as visited, and set its distance to zero.
5. While the queue is not empty, dequeue the front city, and visit all its unvisited connected cities. For each unvisited connected city, mark it as visited, calculate its distance from the starting city, and add it to the queue.
6. Continue dequeuing cities from the queue until it becomes empty. At this point, all the cities would have been visited, and we would have the minimum distance to reach each city from the starting city.

## Complexity
- Time complexity: O(V+E), where V is the number of vertices (cities) and E is the number of edges (roads) in the graph. It is because we visit each vertex once and explore all of its connected vertices.

- Space complexity: O(V+E), where V is the number of vertices (cities) and E is the number of edges (roads) in the graph. It is because we visit each vertex once and explore all of its connected vertices.

## pseudocode
```
getMin(roads, n):
    // Step 1: Initialization
    visited = createBooleanArray(n+1) // Create a boolean array to mark visited cities
    queue = createQueue() // Create a queue data structure
    answer = infinity

    // Step 2: Add the starting city to the queue and mark it as visited
    queue.enqueue(1)
    visited[1] = true
    
    // Step 3: Traverse the graph using BFS
    while not queue.isEmpty():
        currentCity = queue.dequeue()
        for each neighborCity in adjacencyList[currentCity]:
            answer = min(answer, neighborCity.second)
            if not visited[neighborCity]:
                visited[neighborCity] = true
                queue.enqueue(neighborCity)
    
    // Step 4: Return the minimum distance to reach each city from the starting city
    return answer

minScore(roads, n)
    adjacencyList = createAdjacencyList() // Create an empty adjacency list
    return getMin(roads, n)
```
## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/solutions/3329975/easy-cpp-solution-with-queue-data-structure-with-explanation/)


# Deapth First Search

## Intuition
In this algorithm, the main aim for us is to reconstruct the cities in such a way that we know what cities each city is connected to and what the distance between these cities is.

so why I did so ?
Actually, if we construct the roads, we can easily know all the distances between this city and all the connected cities. and then move from this city to one of the connected cities, and repeat this process again until the end [all cities are visited]. Once we reach the end of all cities, we return the minimum score of the path.

This algorithm is called `Depth First Search`, which we will explain the implementation in the next section.

## Make it clear
To reconstruct the roads vector, we require a vector of vectors of pairs, which is a data structure that stores two related pieces of data. This vector will be of size (n+1), which is one more than the size of the road vector. The reason for using a vector of vector of pairs is that the inner vector represents all the data related to a specific node based on its index (e.g., v[2] represents node #2), and each inner vector contains pairs that denote the connected city and the distance between the two cities.

For instance, the adjusted vector example provided is adj = [[], [(2, 7), (4, 8)], [(1, 7), (3, 6), (4, 5)], [(2, 6)], [(1, 8), (2, 5)]]. This means that adj[2] represents all the connected cities to city #2. The pair (1, 7) denotes that it is connected to city #1 with a distance of 7, while (3, 6) means it is connected to city #3 with a distance of 6, and so on until the end.

The reason why we need a vector of size (n+1) is now clear. When a city is indexed as #n, it needs an index in n, so we require an additional cell for it.

The second step in this algorithm focuses on three main tasks: identifying the current city, determining the next city in the route, and checking whether it has been visited before. To accomplish these tasks, the algorithm utilizes recursion, which is a technique that involves repeatedly calling a function within itself.
To begin the process, the algorithm adds the first city to the route and evaluates which other cities it is connected to. Then, it calculates the minimum path to the next city and checks whether it has been visited before. If the next city has not yet been visited, the algorithm proceeds to that city, marks it as visited, and repeats the process for the next city in the route. This pattern continues until all cities on the route have been visited.
By utilizing recursion, the algorithm is able to efficiently navigate the route and calculate the minimum path between each city, while also ensuring that no city is visited twice.

## Approach
That is for The main function:
1. Define a function `minScore` that takes an integer `n` and a 2D vector `roads` as input. The `roads` vector represents the edges between the cities, where each edge is a vector with three integers: the starting city, the ending city, and the score associated with the edge.
2. Create a 2D vector `adj` with `n+1` rows and columns, which will be used to represent the adjacency list for the graph. For each edge in `roads`, add two pairs to `adj`: one representing the connection from the starting city to the ending city with the associated score, and the other representing the connection from the ending city to the starting city with the same score.
3. Initialize a variable `value` to `INT_MAX`, which will be used to store the minimum score.
4. Create a boolean vector `isVisited` with `n+1` elements, which will be used to keep track of which nodes have been visited.
5. Call the recursive function `getMin` with `adj`, `value`, `1`, and `isVisited` as arguments.
6. Return the value of `value` as the minimum score.

For getMin function:
1. Define a function `getMin` that takes `adj`, a reference to `minScore`, an integer `node`, and a boolean vector `isVisited` as input.
2. Mark the current `node` as visited by setting the corresponding element in `isVisited` to `true`.
3. For each element in the vector associated with `node` in `adj`, perform the following steps:
a. Compare the score of the current element to the current value of `minScore`. If the score is lower, update `minScore` to the score of the current element.
b. If the `first` element of the current element (which represents the connection to another node) has not been visited, recursively call `getMin` with `adj`, `minScore`, the `first` element of the current element, and `isVisited` as arguments.
4. Once all elements in the vector associated with `node` have been processed, return to the previous level of recursion.

# Complexity
- Time complexity: O(V+E), where V is the number of vertices (cities) and E is the number of edges (roads) in the graph. It is because we visit each vertex once and explore all of its connected vertices.

- Space complexity: O(V+E), where V is the number of vertices (cities) and E is the number of edges (roads) in the graph. It is because we visit each vertex once and explore all of its connected vertices.

# Pseudocode
```
getMin(adjacencyList, answer, 1, isVisited):
    isVisited = true
    for each neighborCity in adjacencyList[currentCity]:
        answer = min(answer, neighborCity.second)
        if not visited[neighborCity]:
            getMin(adjacencyList, answer, neighborCity, isVisited)
    


minScore(roads, n)
    adjacencyList = createAdjacencyList() // Create an empty adjacency list
    answer = infinity
    isVisited = createBooleanArray(n+1) // Create a boolean array to mark visited cities
    getMin(adjacencyList, answer, 1, isVisted)
    return answer
```

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/solutions/3330451/easy-cpp-solution-using-recursion/)

