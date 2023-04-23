# Question

## 1416. Restore The Array

A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits `s` and all we know is that all integers in the array were in the range `[1, k]` and there are no leading zeros in the array.

Given the string `s` and the integer `k`, return *the number of the possible arrays that can be printed as `s` using the mentioned program*. Since the answer may be very large, return it **modulo** `109 + 7`.<br/>

**Example 1:**<br/>
```
Input: s = "1000", k = 10000
Output: 1
Explanation: The only possible array is [1000]
```
**Example 2:**<br/>
```
Input: s = "1000", k = 10
Output: 0
Explanation: There cannot be an array that was printed this way and has all integer >= 1 and <= 10.
```

**Example 3:**<br/>
```
Input: s = "1317", k = 2000
Output: 8
Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]
```

**Constraints:**
- `1 <= s.length <= 105`
- `s` consists of only digits and does not contain leading zeros.
- `1 <= k <= 109`

*you can try to solve the problem from [here](https://leetcode.com/problems/restore-the-array/description/)*

<h1 align="center">Solution</h1>


## Intuition
In this problem we depends on top-down approach [Recursion]. we first select the first char of the string and when it passed the tests get the rest substring and apply recusion on the sub string till the end.

![td.png](https://assets.leetcode.com/users/images/beae650b-3a4b-426f-baff-ff51c85ab82c_1682259668.283265.png)

we also use a memoization vector (memo) to improve the performance and avoid reputaion.


## Approach
This code is an implementation of a depth-first search (DFS) algorithm that counts the number of ways a string can be split into contiguous substrings, each of which represents a number that is less than or equal to a given value k. The function numberOfArrays takes two inputs: a string s and an integer k, and returns the number of ways s can be split into contiguous substrings that represent numbers less than or equal to k.

The function dfs is a recursive helper function that implements the DFS algorithm. It takes four inputs: the string s, the value k, a vector memo that stores the memoized values of the function, and the starting and ending indices of the current substring being processed.

The DFS algorithm works as follows:

1. If the memoized value of the current substring has already been computed, return that value.
2. If the current substring is empty, return 1.
3. If the current substring starts with a 0, return 0, since a number cannot have leading zeroes.
4. For each possible length of the current substring, starting from the current index and going up to the end of the string:
    - Convert the substring to a number.
    - If the number is greater than k, break out of the loop, since numbers greater than k cannot be used.
    - Recursively call dfs on the remaining part of the string, starting from the next index, and add the resulting count to the running total.
5. Memoize the count for the current substring and return it.

## Complexity
- Time complexity: O(n^2), where n is the length of the input string `s`

- Space complexity: O(n)

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/restore-the-array/solutions/3447706/easy-solution-and-explanation-in-cpp/)