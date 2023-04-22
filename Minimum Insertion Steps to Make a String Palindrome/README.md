# Question

## 1312. Minimum Insertion Steps to Make a String Palindrome

Given a string `s`. In one step you can insert any character at any index of the string.

*Return the minimum number of steps* to make `s` palindrome.

A **Palindrome String** is one that reads the same backward as well as forward.

**Example 1:**<br/>
```
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
```
**Example 2:**<br/>
```
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
```

**Example 3:**<br/>
```
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
```

**Constraints:**
- `1 <= s.length <= 500`
- `s` consists of lowercase English letters.

*you can try to solve the problem from [here](https://leetcode.com/problems/simplify-path/description/)*

<h1 align="center">Solution</h1>

## Intuition
In this algorithm, we will heavily rely on the solution to the "Longest Palindromic Sequence" problem that we have previously solved. The solution to the algorithm will be determined by subtracting the length of the longest palindromic sequence from the size of the input string.

ex.
<ins>m</ins>b<ins>a</ins>d<ins>m</ins> 
if we removed the longest palindromic seq from the string we have the min char to be added to the string to create a palindromic seq again.

*You can check The [Longest Palindromic Subsequence](https://github.com/Mohamed-Khalifa12/Problem-Solving/tree/main/Longest%20Palindromic%20Subsequence) first*

## Approach
you will find a top-down(Recursion) and down-top(iterative) approaches. you can just subtract the result from the size of the string :"D

## Complexity
- Time complexity: O(n^2), where n is the length of the string.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/solutions/3444369/easy-solution-with-explanation-in-cpp/)