# Question

## 20. Valid Parentheses

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.<br/>

**Example 1:**<br/>
```
Input: s = "()"
Output: true
```
**Example 2:**<br/>
```
Input: s = "()[]{}"
Output: true
```

**Example 3:**<br/>
```
Input: s = "(]"
Output: false
```

**Constraints:**
- `1 <= s.length <= 104`
- `s` consists of parentheses only `'()[]{}'`.

*you can try to solve the problem from [here](https://leetcode.com/problems/valid-parentheses/description/)*

<h1 align="center">Solution</h1>

![Screenshot 2023-04-10 142515.png](https://assets.leetcode.com/users/images/70060b1c-b414-4426-80f6-76a70fcb85d5_1681129612.4168012.png)

## Intuition
The problem at hand has a simple solution, but we want the best one. To achieve this, we need to follow some steps. Firstly, if the size of the string is odd, the solution cannot be valid since there will always be an unclosed parenthesis. Secondly, if the size of the string is even, we will use the stack data structure. Whenever an open parenthesis is encountered (i.e., `(`, `{`, or `[`), we push it onto the stack. If a closed parenthesis is encountered, we check whether the stack is empty or not. If the stack is empty and the first parenthesis is closed, the solution is not valid, and we reject it. We then check whether the closed parenthesis matches the top of the stack. We can determine this by looking at the ASCII code for the characters. For instance, the difference between `(` and `)` is 1, and the difference between `{` and `}` and `[` and `]` is 2. If any of the tests fail, we reject the solution and return false. If we reach the end of the string and the stack is empty, the solution is valid. Otherwise, if some parentheses are still open, the solution is not valid, and we reject it.

## Approach

1. Check if the length of the string is odd. If it is, return false as it can never be a valid set of parentheses.
2. Initialize an empty stack.
3. Iterate through each character in the string.
4. If the character is an opening parenthesis, push it onto the stack.
5. If the character is a closing parenthesis, check whether the stack is empty or not.
6. If the stack is empty, return false as the closing parenthesis has no corresponding opening parenthesis.
7. If the stack is not empty, pop the top element of the stack and compare its ASCII code with the ASCII code of the closing parenthesis.
8. If the difference between the two ASCII codes is not 1 for `(` and `)` or not 2 for `{`, `}`, `[`, and `]`, return false as the parentheses do not match.
9. If all parentheses are matched successfully, check whether the stack is empty or not.
10. If the stack is empty, return true as the string is a valid set of parentheses.
11. If the stack is not empty, return false as there are unmatched opening parentheses in the stack.

## Complexity
- Time & Space complexity: O(n), where n is the length of the string.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/valid-parentheses/solutions/3400682/dominating-the-parentheses-game-easy-solution-beats-100/)
