# Question

## 1572. Matrix Diagonal Sum
Given a square matrix `mat`, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.<br/>

**Example 1:**<br/>
![image](https://assets.leetcode.com/uploads/2020/08/14/sample_1911.png)
```
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
```
**Example 2:**<br/>
```
Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
```

**Example 3:**<br/>
```
Input: mat = [[5]]
Output: 5
```

**Constraints:**
- `n == mat.length == mat[i].length`
- `1 <= n <= 100`
- `1 <= mat[i][j] <= 100`

*You can try to solve this problem from [here](https://leetcode.com/problems/matrix-diagonal-sum/description/)*

<h1 align="center">Solution</h1>

## Intuition
The algorithm we're using can be solved through two distinct approaches. These include dynamic programming and an iterative approach.

In dynamic programming, it is possible to update the diagonal values of the matrix from the edges towards the center. Once this has been completed, the center of the matrix can be returned as the solution. Although this approach may not be the most optimal, it serves as a useful demonstration of dynamic programming in action.

With the iterative approach, we iterate through each element in the matrix and identify those that exist along the primary diagonal (where the row and column indices are equal) and the secondary diagonal (where the sum of the row and column indices equals n-1). Once all these elements have been identified, we add them together to obtain the final result.

## Approach
**Dynamic Programming Approach**
```
function diagonalSum(mat: vector<vector<int>>) -> int:
    if size of mat == 1
        return mat[0][0]
    end if
    
    min = 0, max = size of mat - 1
    
    while min + 1 < max - 1
        mat[min + 1][min + 1] += mat[min][min]
        mat[min + 1][max - 1] += mat[min][max]
        mat[max - 1][min + 1] += mat[max][min]
        mat[max - 1][max - 1] += mat[max][max]
        min += 1, max -= 1
    end while

    summer = mat[min][min] + mat[min][max] + mat[max][min] + mat[max][max]

    if size of mat is even
        return summer
    end if

    return summer + mat[min + 1][min + 1]
end function
```
**Itrative Approach**
```
function diagonalSum(mat: vector<vector<int>>) -> int:
    n = size of mat
    summer = 0

    for i = 0 to n-1
        for j = 0 to n-1
            if i == j or i + j == n-1
                summer += mat[i][j]
            end if
        end for
    end for

    return summer
end function
```

## Complexity
- Time complexity: O(n), where n is the length of `mat`

- Space complexity: O(1)

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/matrix-diagonal-sum/solutions/3498860/two-easy-solution-dp-iterative-with-pseudocode/)