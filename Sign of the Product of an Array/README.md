# Question

## 1822. Sign of the Product of an Array

There is a function `signFunc(x)` that returns:

* `1` if `x` is positive.
* `-1` if `x` is negative.
* `0` if `x` is equal to `0`.
You are given an integer array `nums`. Let `product` be the product of all values in the array `nums`.

Return `signFunc(product)`.<br/>

**Example 1:**<br/>
```
Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1
```
**Example 2:**<br/>
```
Input: nums = [1,5,0,2,-3]
Output: 0
Explanation: The product of all values in the array is 0, and signFunc(0) = 0
```
**Example 3:**<br/>
```
Input: nums = [-1,1,-1,1,-1]
Output: -1
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1
```

**Constraints:**
- `1 <= nums.length <= 1000`
- `-100 <= nums[i] <= 100`

*you can try to solve the problem from [here](https://leetcode.com/problems/sign-of-the-product-of-an-array/description/)*

<h1 align="center">Solution</h1>


## Intuition
This problem involves counting the number of negative numbers in an array. If the array contains 0, the result will be 0 and the function should return it. After iterating through the array, if the number of negative numbers is even, the result will be positive. If the number of negative numbers is odd, the result will be negative.

## Approach

1. Get the length `n` of the input array `nums`.
2. Initialize a variable `count` to 0 to keep track of the number of negative numbers in the array.
3. Iterate through the array using a loop with index `i` from 0 to `n-1`:
    1. If the current element `nums[i]` is equal to 0, return 0 as the array product should be 0.
    2. If the current element `nums[i]` is negative, increment the count variable.
4. After the iteration, check if `count` is even or odd:
    1. If `count` is even, return 1 as the array product should be positive.
    2. If `count` is odd, return -1 as the array product should be negative.

```
function arraySign(nums):
    n = length of nums
    count = 0
    for i = 0 to n-1:
        if nums[i] == 0:
            return 0
        if nums[i] < 0:
            count = count + 1
    if count is even:
        return 1
    else:
        return -1

```

## Complexity
- Time complexity:  O(n), where n is the length of the input array.

- Space complexity: O(1).

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/sign-of-the-product-of-an-array/solutions/3477511/easy-explanation-with-pseudocode/)