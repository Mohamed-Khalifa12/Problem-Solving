# Question

## 1035. Uncrossed Lines

You are given two integer arrays `nums1` and `nums2`. We write the integers of `nums1` and `nums2` (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers `nums1[i]` and `nums2[j]` such that:

- `nums1[i] == nums2[j]`, and
- the line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return *the maximum number of connecting lines we can draw in this way.*<br/>

**Example 1:**<br/>
[!image](https://assets.leetcode.com/uploads/2019/04/26/142.png)
```
Input: nums1 = [1,4,2], nums2 = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.
```
**Example 2:**<br/>
```
Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
Output: 3
```
**Example 3:**<br/>
```
Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
Output: 2
```

**Constraints:**
- `1 <= nums1.length, nums2.length <= 500`
- `1 <= nums1[i], nums2[j] <= 2000`

*you can try to solve the problem from [here](https://leetcode.com/problems/uncrossed-lines/description/)*

<h1 align="center">Solution</h1>

## Approach
### Bottom-top Approach
```
function maxUncrossedLines(nums1, nums2):

#Initialize the dynamic programming table.
dp = [length(nums1) + 1)][length(nums2) + 1)]

#Iterate over the elements of the first array.
for i = 1 upto len(nums1):
# Iterate over the elements of the second array.
for j = 1 upto len(nums2):
# If the current elements are equal, then add 1 to the value of the dynamic programming table.
if nums1[i - 1] == nums2[j - 1]:
dp[i][j] = dp[i - 1][j - 1] + 1
# Otherwise, set the value of the dynamic programming table to the maximum of the values of the dynamic programming table above and to the left.
else:
dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])

#Return the value of the dynamic programming table at (len(nums1), len(nums2)).
return dp[len(nums1)][len(nums2)]
```
1. Initialize a dynamic programming table with dimensions (len(nums1) + 1, len(nums2) + 1).
2. Iterate over the elements of nums1.
3. For each element in nums1, iterate over the elements of nums2.
4. If the current elements are equal, then add 1 to the value of the dynamic programming table at the current row and column.
5. Otherwise, set the value of the dynamic programming table at the current row and column to the maximum of the values of the dynamic programming table above and to the left.
6. Return the value of the dynamic programming table at (len(nums1), len(nums2)).

### top-bottom Approach
```
function maxUncrossedLines(nums1, nums2):
  # Initialize the dynamic programming table.
    dp = [length(nums1) + 1)][length(nums2) + 1)]

  # Recursively solve the problem.
  return solve(len(nums1), len(nums2), nums1, nums2, dp)


function solve(i, j, nums1, nums2, dp):
  # If we've reached the end of one of the arrays, return 0.
  if i <= 0 or j <= 0:
    return 0

  # If we've already solved this subproblem, return the cached result.
  if dp[i][j] != -1:
    return dp[i][j]

  # If the current elements are equal, add 1 to the result of the subproblem.
  if nums1[i - 1] == nums2[j - 1]:
    dp[i][j] = 1 + solve(i - 1, j - 1, nums1, nums2, dp)

  # Otherwise, take the maximum of the results of the subproblems.
  else:
    dp[i][j] = max(solve(i - 1, j, nums1, nums2, dp), solve(i, j - 1, nums1, nums2, dp))

  # Return the result of the subproblem.
  return dp[i][j]

```
1. Initialize a dynamic programming table dp with dimensions (len(nums1) + 1, len(nums2) + 1).
2. Initialize all values in dp to -1.
3. Recursively solve the problem using the following steps:
    * If i <= 0 or j <= 0, return 0.
    * If dp[i][j] != -1, return dp[i][j].
    * If nums1[i - 1] == nums2[j - 1], set dp[i][j] to 1 + solve(i - 1, j - 1, nums1, nums2, dp).
    * Otherwise, set dp[i][j] to max(solve(i - 1, j, nums1, nums2, dp), solve(i, j - 1, nums1, nums2, dp)).
4. Return dp[len(nums1)][len(nums2)].

## Complexity
- Time & Space complexity: O(n1*n2), where n1 is the length of `nums1` and n2 is the length of `nums2`.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/uncrossed-lines/solutions/3515254/easy-solution-in-cpp-with-explanation-and-pseudocode/)