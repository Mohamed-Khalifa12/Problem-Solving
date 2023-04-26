# Question

## 258. Add Digits

Given an integer `num`, repeatedly add all its digits until the result has only one digit, and return it.<br/>

**Example 1:**<br/>
```
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
```
**Example 2:**<br/>
```
Input: num = 0
Output: 0
```

**Constraints:**
- `0 <= num <= 2^31 - 1`

*you can try to solve the problem from [here](https://leetcode.com/problems/add-digits/description/)*

<h1 align="center">Solution</h1>

## Intuition
This problem involves checking if the given number `num` is a single digit number. If it is, we return the number as is. However, if the number has multiple digits, we need to repeatedly add its digits until we get a single digit number. The way to do this is to calculate the sum of all the digits in the number and use this sum as the new number.

## Approach
pseudocode for the algorithm :
```
function addDigits(num):
  if num < 0:
    return num

  while num > 9:
    str = to_string(num)
    num = summer(str)

  return num

function summer(str):
  sum = 0
  for i in range(len(str)):
    sum += str[i] - '0'

  return sum
```

## Complexity
- Time complexity: O(n), where n is the number of digits in the input number. 

- Space complexity: O(1)

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/add-digits/solutions/3457449/easy-solution-in-cpp-with-explanation-pseudocode/)
