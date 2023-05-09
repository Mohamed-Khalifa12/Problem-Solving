# Question

## 54. Spiral Matrix

Given an `m x n` `matrix`, *return all elements of the `matrix` in spiral order.*<br/>

**Example 1:**<br/>
[!image](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)
```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```
**Example 2:**<br/>
[!image](https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg)
```
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

**Constraints:**
- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 10`
- `-100 <= matrix[i][j] <= 100`

*you can try to solve the problem from [here](https://leetcode.com/problems/spiral-matrix/description/)*

<h1 align="center">Solution</h1>

## Intuition
This problem involves setting limits and looping through them. The limits include the top, bottom, left, and right boundaries. The loop starts at the left and moves to the right, then moves down to the next row. The loop does not need to repeat the first row, so the top limit is increased by one, and this process is repeated in all four directions. For more details, please refer to the "Approach" section.

## Approach

1. Start at the top left corner of the matrix.
2. Add all elements in the current row to the output array.
3. Move down one row.
4. Add all elements in the current column to the output array.
5. Move right one column.
6. Repeat steps 3 and 4 until you reach the bottom right corner of the matrix.
7. Reverse the order of the elements in the output array.
8. Return the output array.

```
# Pseudocode for spiralOrder()

# Input: A 2D array of integers, matrix
# Output: A 1D array of integers, spiralOrder

# Initialize variables
n = len(matrix)
m = len(matrix[0])
output = []
idx = 0
left = 0
top = 0
right = m - 1
bottom = n - 1

# While there are still elements to be added to the output array
while idx < n * m:

    # Add all elements in the current row to the output array
    for i in range(left, right + 1):
        output.append(matrix[top][i])
        top += 1

    # Add all elements in the current column to the output array
    for i in range(top, bottom + 1):
        output.append(matrix[i][right])
        right -= 1

    # Add all elements in the current row in reverse order to the output array
    for i in range(right, left - 1, -1):
        output.append(matrix[bottom][i])
        bottom -= 1

    # Add all elements in the current column in reverse order to the output array
    for i in range(bottom, top - 1, -1):
        output.append(matrix[i][left])
        left += 1

# Return the output array
return output

```

## Complexity
- Time & Space complexity: O(n * m), where n and m are the number of rows and columns in the matrix.


## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/spiral-matrix/solutions/3503354/easy-cpp-solution-with-pseudocode/)