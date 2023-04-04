# Question

## 2405. Optimal Partition of String
Given a string `s`, partition the string into one or more **substrings** such that the characters in each substring are **unique**. That is, no letter appears in a single substring more than **once**.

Return *the **minimum** number of substrings in such a partition.*
Note that each character should belong to exactly one substring in a partition.<br/>

**Example 1:**<br/>
```
Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
```
**Example 2:**<br/>
```
Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").
```

**Constraints:**
- `1 <= s.length <= 10^5`
- `s` consists of only English lowercase letters.

*you can try to solve the problem from [here](https://leetcode.com/problems/boats-to-save-people/description/)*

<h1 align="center">Solution</h1>

# An unordered map-dependent solution.

## Intuition
In this algorithm, we rely on the `unordered_map` data structure, which is based on a hash table. This allows us to assign a numerical value to each character in the string. If a character appears more than once in a substring, the algorithm increments a counter to indicate that the character has been found twice. The hash table is then cleared, and the process repeats until the end of the main string is reached.

## Approach
1. Initialize variables:

    - `i` to 0, which represents the current index of the string being processed.
    - `count` to 1, which represents the current count of substrings.
    - `mp` as an empty unordered_map, which will be used to keep track of the characters seen in the current substring.
    
2. Loop through the string until the end is reached:

    - Check if the current character `s[i]` has already been seen in the current substring by checking if `mp[s[i]] + 1 == 2`. If it has, then this means that the current character is not the same as the previous characters in the substring, so we need to start a new substring. To do this, increment `count` to indicate that a new substring is starting and clear the `mp` unordered_map.
    - Add the current character `s[i]` to the `mp` unordered_map and increment its count.
    - Increment `i` to move to the next character in the string.
    
3. Once the end of the string has been reached, return the value of `count`.

## Complexity
- Time complexity:  O(n), where n is the length of the input string `s`.

- Space complexity:  O(1) + O(26) = O(1), which is constant space.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/optimal-partition-of-string/solutions/3380793/efficient-algorithm-using-unordered-map-in-linear-time/)

# A bit manipulation-dependent solution.

## Intuition
This algorithm uses bit manipulation to reduce the space and time complexity. First, a series of bits is initialized with zeros, and each character of the input string is converted to a number from 0 to 26 by subtracting 'a' from it. Then, a bitwise AND operator is used to check whether the corresponding bit for that character is already set to 1 or not. If it's not set to 1, the bit is set to 1, and if it is already set to 1, the bit is cleared.

## Approach
1. Initialize a `counter` variable counter to 1, a `mask` variable mask to 0, and an index variable `i` to 0.
2. Loop through the string `s` until the end of the string is reached (i.e., until `s[i]` becomes `'\0'`).
3. For each character `s[i]` in the string, calculate its numerical value by subtracting the character 'a' from it, and store it in the variable `shift`.
4. Check if the `shift`-th bit in the `mask` variable is already set to 1 or not. This is done by performing a bitwise AND operation between `mask` and a number where only the `shift`-th bit is set to 1 (i.e., `(1<<shift)`). If the result of this operation is greater than 0, it means that the `shift`-th bit in `mask` is already set to 1, indicating that the current character `s[i]` is not unique in the current substring. In this case, increment the `counter` variable to start a new substring, and reset the `mask` variable to 0.
5. If the `shift`-th bit in `mask` is not set to 1, set it to 1 by performing a bitwise OR operation between `mask` and a number where only the `shift`-th bit is set to 1 (i.e., `(1<<shift)`).
6. Increment the index variable `i` to move to the next character in the string.
7. After the loop ends, return the final value of the `counter` variable, which represents the minimum number of substrings required to partition the given string `s`.

## Complexity
- Time complexity: O(n), where n is the length of the input string `s`.

- Space complexity: O(1)

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/optimal-partition-of-string/solutions/3380866/efficient-solution-using-bit-manipulation-techniques-d/)

