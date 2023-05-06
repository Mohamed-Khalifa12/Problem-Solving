# Question

## 1498. Number of Subsequences That Satisfy the Given Sum Condition

You are given an array of integers `nums` and an integer `target`.

Return *the number of **non-empty** subsequences of `nums` such that the sum of the minimum and maximum element on it is less or equal to `target`*. Since the answer may be too large, return it **modulo** `10^9 + 7`.<br/>

**Example 1:**<br/>
```
Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)
```
**Example 2:**<br/>
```
Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
```

**Example 3:**<br/>
```
Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).
```

**Constraints:**
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^6`
- `1 <= target <= 10^6`

*you can try to solve the problem from [here](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/)*

<h1 align="center">Solution</h1>

## Intuition
This algorithm uses a technique called the "two pointers approach" after sorting the "nums" array. The goal is to find the smallest and largest numbers that satisfy the condition of having a sum that is less than or equal to the target. Once these two numbers have been identified, we can calculate the number of subsequences by taking 2 to the power of the difference between the two pointers. If the two pointers do not initially meet the condition, they are moved until the condition is satisfied.

## Approach

1. Sort the `nums` array in ascending order using `sort`.
2. Initialize variables `left` and `right` to the first and last indices of the sorted `nums` array.
3. Initialize `result` to zero.
4. Initialize an array `power` of size `L` (the length of `nums`) to store the power of 2 values.
5. Fill the `power` array using a loop that starts from index 1 and updates each element as the product of the previous element and 2, modulo `mod`.
6. Use a while loop to iterate through the sorted `nums` array while `left` is less than or equal to `right`.
7. Check if the sum of `nums[left]` and `nums[right]` is less than or equal to the target. If it is, update `result` by adding the power of 2 value for the difference between `right` and `left` to `result`.
8. Increment `left` if the sum is less than or equal to the target, otherwise decrement `right`.
9. Return `result` as the final answer.

```
function numSubseq(nums: array of integers, target: integer) -> integer
    // Sort the array in ascending order
    sort(nums)

    // Initialize variables
    L = length(nums)
    left = 0
    right = L - 1
    result = 0
    mod = 1000000007

    // Initialize the power array
    power = new array of integers with size L
    power[0] = 1
    for i = 1 to L - 1 do
        power[i] = (power[i - 1] * 2) % mod

    // Use the two pointers approach to find the number of subsequences
    while left <= right do
        if nums[left] + nums[right] <= target then
            result = (result + power[right - left]) % mod
            left = left + 1
        else
            right = right - 1

    // Return the result
    return result

```

## Complexity
- Time complexity: O(nlgn), where n is the length of `nums`.

- Space complexity: O(n), where n is the length of `nums`.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/solutions/3494111/easy-solution-with-explanation-and-pseudocode/)
