# Question
## 1020. Number of Enclaves
You are given an `m x n` binary matrix `grid`, where `0` represents a sea cell and `1` represents a land cell.

A **move** consists of walking from one land cell to another adjacent (**4-directionally**) land cell or walking off the boundary of the `grid`.

Return *the number of land cells in `grid` for which we cannot walk off the boundary of the grid in any number of **moves.*** <br/>

**Example 1:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2021/02/18/enclaves1.jpg)
```
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
```
**Example 2:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2021/02/18/enclaves2.jpg)
```
Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
```

**Constraints:**
- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 500`
- `grid[i][j] is either 0 or 1.`

<h1 align="center">Solution</h1>


![Screenshot 2023-04-07 175000.png](https://assets.leetcode.com/users/images/b44a0fbc-c919-4c6d-b0ec-00184d9dc3c6_1680882955.832393.png)

# Intuition
<h6>The problem requires us to change any ones that are on the boundary and any connected ones to zeros. Once this is done, the sum of all elements in the grid will give us the required result.</h6>

# Approach

* Defines a 2D vector called `directions` that contains four directions: right, down, up, and left.
* The function `numEnclaves` takes a 2D vector called `grid` as input, which represents a rectangular grid of 0's and 1's. The function initializes some variables, loops through each element in the grid, and checks if the element is on the boundary and has a value of 1. If this is true, the function calls the `dfs` function, which takes in the grid and the indices of the current element.
* The `dfs` function recursively visits each neighbor of the current element in the four directions specified in `directions` and changes the value of the neighbor to 0 if it has a value of 1. This effectively changes any ones that are on the boundary and any connected ones to zeros. The function stops when it has visited all connected 1's.
* After `dfs` is called on all boundary elements with a value of 1, the function `numEnclaves` loops through the entire grid and calculates the sum of all elements in the grid. This sum is returned as the output of the function.

# Complexity
- Time & Space complexity: O(N * M) time, where N is the number of rows and M is the number of columns in the grid.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/number-of-enclaves/solutions/3390920/easy-solution-with-explanation-beats-96-2/)