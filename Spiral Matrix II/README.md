# Question

## 59. Spiral Matrix II

Given a positive integer `n`, generate an `n x n` matrix filled with elements from `1` to `n^2` in spiral order.<br/>

**Example 1:**<br/>
[!image](https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg)
```
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
```
**Example 2:**<br/>
```
Input: n = 1
Output: [[1]]
```

**Constraints:**
- `1 <= n <= 20`

*you can try to solve the problem from [here](https://leetcode.com/problems/spiral-matrix-ii/description/)*

<h1 align="center">Solution</h1>

## Intuition
This problem involves setting limits and looping through them. The limits include the top, bottom, left, and right boundaries. The loop starts at the left and moves to the right, then moves down to the next row. The loop does not need to repeat the first row, so the top limit is increased by one, and this process is repeated in all four directions. For more details, please refer to the "Approach" section.

## Approach
1. Initialize a matrix of size n x n.
2. Initialize four indexes: left, right, top, and bottom.
3. Initialize a value to be used.
4. Iterate until all values have been placed in the matrix.
    - Place the value in the current row, starting at the leftmost column.
    - Increment the top index.
    - Place the value in the current column, starting at the topmost row.
    - Decrement the right index.
    - Place the value in the current row, starting at the rightmost column.
    - Decrement the bottom index.
    - Place the value in the current column, starting at the bottommost row.
    - Increment the left index.
    - Increment the value.
5. Return the matrix.

```
function generateMatrix(n):
    // create an empty n x n matrix filled with zeroes
    result = createMatrix(n, n, 0)
    // initialize the variables for the bounds and the starting value
    left = 0
    right = n - 1
    top = 0
    bottom = n - 1
    value = 1
    // loop until all elements have been filled
    while (value <= n * n):
        // fill the top row from left to right
        for i from left to right:
            result[top][i] = value
            value = value + 1
        top = top + 1
        // fill the right column from top to bottom
        for i from top to bottom:
            result[i][right] = value
            value = value + 1
        right = right - 1
        // fill the bottom row from right to left
        for i from right to left:
            result[bottom][i] = value
            value = value + 1
        bottom = bottom - 1
        // fill the left column from bottom to top
        for i from bottom to top:
            result[i][left] = value
            value = value + 1
        left = left + 1
    // return the filled matrix
    return result

```

## Complexity
- Time & Space complexity: O(n^2), where n is the size of the matrix.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/spiral-matrix-ii/solutions/3508498/easy-cpp-solution-with-explanation-and-pseudocode/)