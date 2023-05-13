# Question

## 2466. Count Ways To Build Good Strings

Given the integers `zero`, `one`, `low`, and `high`, we can construct a string by starting with an empty string, and then at each step perform either of the following:

- Append the character `'0'` `zero` times.
- Append the character `'1'` `one` times.
This can be performed any number of times.

A **good** string is a string constructed by the above process having a **length** between `low` and `high` **(inclusive)**.

Return *the number of **different** good strings that can be constructed satisfying these properties.* Since the answer can be large, return it **modulo** `10^9 + 7.`<br/>

**Example 1:**<br/>
```
Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation: 
One possible valid good string is "011". 
It can be constructed as follows: "" -> "0" -> "01" -> "011". 
All binary strings from "000" to "111" are good strings in this example.
```
**Example 2:**<br/>
```
Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".
```

**Constraints:**
- `1 <= low <= high <= 10^5`
- `1 <= zero, one <= low`

*you can try to solve the problem from [here](https://leetcode.com/problems/count-ways-to-build-good-strings/description/)*

<h1 align="center">Solution</h1>

## Intuition
To solve this problem, we use a recursive approach. We start at the bottom of the problem and generate all possible strings. Then, we move up one level at a time, always choosing the maximum possible string at each step.

To do this, we first initialize the first element of the memoization vector to 1. This is because when we reach this point in the recursion, we will have already generated all possible strings of length 1.

For each subsequent element in the memoization vector, we add the maximum possible string of the previous length to the current element. This ensures that we always choose the maximum possible string at each step.

## Approach

- The `countGoodStrings` function takes four integers `low`, `high`, `zero`, and `one` as input.
- It initializes an array `memo` with size equal to `high + 1` and initializes all elements to -1.
- It sets `memo[0]` to 1.
- It iterates over the range of values from `low` to `high`, calling the `solve` function with `i`, `zero`, `one`, and `memo` as arguments.
- It adds the result to `answer` and takes the modulo of `mod`.
- Finally, it returns `answer`.

The solve function takes `i`, `zero`, `one`, and `memo` as input and returns an integer value. It checks if `memo[i]` has already been computed. If so, it returns `memo[i]`. If not, it recursively calls itself with `i - one` and `i - zero` as arguments and computes the number of valid strings of length `i` that can be formed using `zero` zeros and `one` ones. It updates `memo[i]` with the computed value and returns it.

```
FUNCTION countGoodStrings(low: integer, high: integer, zero: integer, one: integer) -> integer
    memo = array of integers with size equal to high + 1, initialized to -1
    memo[0] = 1
    answer = 0
    FOR i FROM low TO high DO
        answer += solve(i, zero, one, memo)
        answer %= mod
    END FOR
    RETURN answer
END FUNCTION

FUNCTION solve(i: integer, zero: integer, one: integer, memo: array of integers) -> integer
    IF memo[i] != -1
        RETURN memo[i]
    count = 0
    IF i >= one
        count += solve(i - one, zero, one, memo)
    IF i >= zero
        count += solve(i - zero, zero, one, memo)
    memo[i] = count % mod
    RETURN memo[i]
END FUNCTION
```

## Complexity
- Time & Space complexity: O(high)

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/count-ways-to-build-good-strings/solutions/3521062/easy-cpp-solution-with-explanation-and-pseudocode/)