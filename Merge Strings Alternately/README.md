# Question
## 1768. Merge Strings Alternately
You are given two strings `word1` and `word2`. Merge the strings by adding letters in alternating order, starting with `word1`. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return *the merged string.*<br/>

**Example 1:**<br/>
```
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
```
**Example 2:**<br/>
```
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
```
**Example 3:**<br/>
```
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
```

**Constraints:**

- `1 <= word1.length, word2.length <= 100`
- `word1` and `word2` consist of lowercase English letters.

*You can try to solve this problem from [here](https://leetcode.com/problems/merge-strings-alternately/description/)*

<h1 align="center">Solution</h1>

## Intuition
The basic concept of this algorithm is to go through every character in the string and include one character from each string until both strings have been fully utilized.

## Approach

1. Initialize variables: `i` and `j` to 0, and create an empty string `str` to store the result.
2. Enter a while loop that runs until the end of both input strings is reached.
3. Check if the current index `i` or `j` is not at the end of the corresponding input string using the null terminator character `'\0'`.
4. If `word1[i]` is not at the end, append the character at index `i` of `word1` to the result string `str` and increment `i` by one.
5. Similarly, if `word2[j]` is not at the end, append the character at index `j` of `word2` to the result string `str` and increment `j` by one.
6. Return the resulting string `str`.

## Complexity
- Time complexity: O(n), where n is the length of longest of them either `word1` or `word2`
- Space complexity: O(n + m), where n and m is the length of the two strings. 

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/merge-strings-alternately/solutions/3430196/easy-cpp-solution-and-explanation/)