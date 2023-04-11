# Question

## 2390. Removing Stars From a String
You are given a string `s`, which contains stars `*`.

In one operation, you can:

- Choose a star in `s`.
- Remove the closest **non-star** character to its **left**, as well as remove the star itself.

Return *the string after **all** stars have been removed.*

**Note:**
- The input will be generated such that the operation is always possible.
- It can be shown that the resulting string will always be unique.<br/>

**Example 1:**<br/>
```
Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
```
**Example 2:**<br/>
```
Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
```

**Constraints:**
- `1 <= s.length <= 105`
- `s` consists of lowercase English letters and stars `*`.
- The operation above can be performed on `s`.

*you can try to solve the problem from [here](https://leetcode.com/problems/removing-stars-from-a-string/description/)*

<h1 align="center">Solution</h1>

# Two Pointers Solution

## Intuition
###### Initially, I attempted to solve this problem by removing each '*' character along with the previous element until the end. However, the issue with this approach is that the removing function would take a linear time of O(n) and iterating through the string would also take a linear time. As a result, this algorithm would have a time complexity of O(n^2), which would not be efficient.

###### So, instead of removing characters, we can shift only the necessary character. To achieve this, we can use two iterators: one that loops through the string and another that moves forward until it finds a '*' character. The second iterator will then move back one element, indicating that this element needs to be removed. This process will continue until the end of the string is reached.


## Approach
1. Initialize a variable `j` to 0, which represents the index of the next character that will be shifted in the modified string.
2. Next, iterate through the string `s` using a for loop. If the current character is a '*', j is decremented to indicate that the previous character should be removed. Otherwise, the current character is shifted to the position indicated by `j`, and `j` is incremented to prepare for the next character.
3. Finally, return a substring of s from the beginning up to index `j`, which represents the modified string without any '*' characters.

#### **Note:**
```
ios_base::sync_with_stdio(false);
```
###### this peace of code means that disable the synchronization between the C++ standard streams and the standard C streams. Disabling this synchronization can improve the performance of I/O operations in C++ programs.

## Complexity
- Time & Space complexity:  O(n), where n is the length of the input string `s`.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/removing-stars-from-a-string/solutions/3403781/tricky-solution-with-explanation-d/)

# Stack

## Intuition
###### In this Algorithm we add any character to the stack except for `'*'`, but if it encounters a `'*'`, it removes the last character from the stack until it reaches the end, resulting in the desired stack of characters.

## Approach
1. Initialize a variable `i` to 0, which will be used to traverse the input string `s`.
2. Create an empty stack `st` of characters to store the characters of the input string.
3. Initialize an empty string `output` to store the output string.
4. Traverse the input string using a while loop until the end of the string is reached.
5. If the current character is `'*'`, then pop the top character from the stack.
6. Otherwise, push the current character onto the stack.
7. Increment the value of `i`.
8. After the loop, traverse the stack using another while loop until it becomes empty.
9. Append the top character of the stack to the `output` string and pop it from the stack.
10. Reverse the `output` string using the `reverse` function from the `algorithm` library.
11. Return the `output` string.

## Complexity
- Time complexity: O(n), where n is the length of the input string `s`.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/removing-stars-from-a-string/solutions/3403820/stack-dependent-solution-d/)
