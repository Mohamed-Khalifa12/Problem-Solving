# Question
Given a `m x n` `grid` filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

**Note:** You can only move either down or right at any point in time.<br/>
**Example 1:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg)
```
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
```
**Example 2:**<br/>
```
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 200`
- `0 <= grid[i][j] <= 100`

<h1 align="center">Solution</h1>

## Intuition
The goal is to find the path from the top-left corner to the bottom-right corner with the minimum sum. You can only move down or right, so the possible paths for the given example are:

![Screenshot](https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg)

(1,1) -> (2,1) -> (3,1) -> (3,2) -> (3,3) (sum = 1 + 1 + 4 + 2 + 1 = 9)
(1,1) -> (2,1) -> (2,2) -> (3,2) -> (3,3) (sum = 1 + 5 + 2 + 1 = 9)
(1,1) -> (1,2) -> (2,2) -> (3,2) -> (3,3) (sum = 3 + 5 + 2 + 1 = 11)
(1,1) -> (1,2) -> (1,3) -> (2,3) -> (3,3) (sum = 1 + 1 + 1 + 2 + 1 = 6)
The minimum path is the fourth path, which has a sum of 6.

The intuition behind the solution is to use dynamic programming to build up a table of minimum sums for each cell in the grid, starting from the top-left corner. Each cell's minimum sum is the sum of the value of the cell and the minimum of the values of the cells to the left and above it. The minimum sum for the bottom-right cell is the solution to the problem.

## Approach 

You can solve this problem by:

1. Initialize `rowsNum` to the number of rows in `grid` and `colNum` to the number of columns in `grid`. 

2. Add up the values of the first row of `grid` by iterating from the second column to the last column and adding the value of the current cell to the value of the previous cell in the row. 

3. Add up the values of the first column of `grid` by iterating from the second row to the last row and adding the value of the current cell to the value of the previous cell in the column. 

4. Iterate over the remaining cells of `grid` (excluding the first row and the first column) and update each cell by adding the value of the current cell to the minimum value of the cell above it and the cell to the left of it. 

5. Return the value of the bottom-right cell of `grid` as the minimum path sum. 

That's it! This approach takes advantage of the fact that you can only move down or right to calculate the minimum path sum efficiently using dynamic programming.

## Complexity
- Time complexity: O(m*n), where m and n are the number of rows and columns in the input grid, respectively.

- Space complexity: O(m*n), where m and n are the number of rows and columns in the input grid, respectively.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/minimum-path-sum/solutions/3349108/easy-solution-in-cpp-with-explanation/)