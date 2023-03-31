# Question
Given a rectangular pizza represented as a `rows x cols` matrix containing the following characters: `'A'` (an apple) and `'.'` (empty cell) and given the integer `k`. You have to cut the pizza into `k` pieces using `k-1` cuts. 

For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

*Return the number of ways of cutting the pizza such that each piece contains **at least** one apple.* Since the answer can be a huge number, return this modulo 10^9 + 7.<br/>
**Example 1:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2020/04/23/ways_to_cut_apple_1.png)
```
Input: pizza = ["A..","AAA","..."], k = 3
Output: 3 
Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.
```
**Example 2:**<br/>
```
Input: pizza = ["A..","AA.","..."], k = 3
Output: 1
```
**Example 3:**<br/>
```
Input: pizza = ["A..","A..","..."], k = 1
Output: 1
```

**Constraints:**

- `1 <= rows, cols <= 50`
- `rows == pizza.length`
- `cols == pizza[i].length`
- `1 <= k <= 10`
- `pizza` consists of characters `'A'` and `'.'` only.

<h1 align="center">Solution</h1>

## Question Explaination 
Before we begin to solve the problem, it is important to provide an explanation of the problem requirements. The task is to cut a rectangular pizza k-1 times while ensuring that each resulting piece of pizza contains at least one apple. The solution should output the total number of ways that the pizza can be cut to meet this condition.
## Intuition
The solution to the problem involves breaking it down into smaller subproblems recursively. We start at the first row and divide it into two parts, the first part being row #0 and the second part being the rest of the pizza. We then check the validity of these parts using the isValid function. If they are valid, we move on to the second row and divide the remaining pizza into two parts: row #1 and the rest. We continue to do this recursively until we reach the end of the pizza.

There are two end conditions that we need to consider. The first is when the number of cuts has been completed, and in this case, we count it as a valid way of cutting the pizza as all parts have apples. The second end condition is when we have finished cutting all the rows before completing all the cuts. In this case, we try to cut from the columns, and if a cut is valid, we divide the right part into column #1 and the rest, and recursively continue until we reach the end (the number of cuts have been completed). This is the base condition that gets us out of the recursion.

If the solution isn't clear yet, you can refer to the approach section for more information :D

## Approach
1. The `isValid` function checks whether there is at least one apple in the sub-matrix defined by the given row and column ranges. It returns true if there is, and false otherwise.

2. The `solve` function recursively cuts the pizza by rows and columns, and counts the number of ways to do so while maintaining the condition that each sub-matrix has at least one apple. It takes the current row and column indices, and the remaining number of cuts as parameters.

3. In the `solve` function, we first check if there are any cuts remaining. If not, we return 1 to indicate that we have found a valid way to cut the pizza.

4. We loop through the rows and columns, and check if cutting at the current row or column index would result in two valid sub-matrices. If so, we recursively call `solve` with the new row or column index, and decrement the remaining number of cuts. We add the number of ways returned by the recursive call to the total count.

5. Finally, we return the total count of valid ways to cut the pizza.

6. The `ways` function simply calls `solve` with initial parameters of 0 for the row index, 0 for the column index, and `k-1` for the remaining number of cuts.

## Complexity
- Time complexity: O(R * C * K^2), where R is the number of rows in the pizza, C is the number of columns in the pizza, and K is the number of cuts to be made.

- Space complexity: O(R * C), which is the space used by the pizza matrix. We are not using any extra space in this algorithm other than the call stack space used by the recursion.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/solutions/3362764/question-explanation-d-easy-explained-solution/)