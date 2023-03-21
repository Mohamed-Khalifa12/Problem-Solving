# Question
Given an integer array `nums`, return the number of **subarrays** filled with `0`.

A **subarray** is a contiguous non-empty sequence of elements within an array.

**Example 1:**<br/>
```
Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation: 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
```
**Example 2:**<br/>
```
Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.
```

**Example 2:**<br/>
```
Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.
```

**Constraints:**

- `1 <= nums.length <= 105`
- `-109 <= nums[i] <= 109`

<h1 align="center">Solution</h1>

## Intuition
Our algorithm involves determining the number of subarrays of zeros in a series of zeros. We achieve this by adding up the number of zeros in each subarray until the subarray comes to an end. For instance, a subarray of [0000] has 1 + 2 + 3 + 4 subarrays of zeros, which translates to a total of 10 subarrays. Essentially, our objective is to identify all the series of zeros and calculate the number of subarrays of zeros for each of them.

## Approach
Initially, we initialize two variables, `cnt` and `zeroSubarraysEndingAtCurrentIndex`, to zero. `cnt` will store the final count of all subarrays with only zeros, while `zeroSubarraysEndingAtCurrentIndex` will store the number of subarrays of zeros that end at the current index.

We then iterate through the elements of the vector `nums` and check if the current element is zero. If it is zero, we increment `zeroSubarraysEndingAtCurrentIndex` and add it to `cnt`. This is because the current index is the end of a new subarray of zeros, and we need to count all the subarrays of zeros that end at this index.

If the current element is not zero, we reset `zeroSubarraysEndingAtCurrentIndex` to zero. This is because we have reached the end of a subarray of zeros, and any further zeros encountered will begin a new subarray.

Finally, we return `cnt`, which represents the total number of subarrays of zeros in the input vector.

## Complexity
- Time complexity:  O(n)

- Space complexity: O(1)

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/number-of-zero-filled-subarrays/solutions/3326537/easy-solution-with-explanation-in-cpp/)