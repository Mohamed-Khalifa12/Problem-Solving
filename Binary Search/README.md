# Question
Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.<br/>
**Example 1:**<br/>
```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```
**Example 2:**<br/>
```
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

**Constraints:**

- `1 <= nums.length <= 104`
- `-104 < nums[i], target < 104`
- All the integers in `nums` are **unique**.
- `nums` is sorted in ascending order.

## Intuition
This problem uses a divide and conquer strategy where the array of numbers is divided into two parts. The middle element is checked to see if it is greater than the target value. If it is, the second half of the array is discarded and the first half is divided into two halves recursively until the target value is found. If the target value is found, the index of the element is returned. If it is not found, the recursion will continue until the start index is greater than the end index, at which point -1 will be returned to indicate that the target value is not present in the array.

## Approach
1. Define a function to perform the binary search, which takes the following parameters:
    - A reference to the vector of integers to search
    - The starting index of the search range
    - The ending index of the search range
    - The target integer to search for
    
2. In the binary search function, if the starting index is greater than  the ending index, return -1 to indicate that the target integer was not found.

3. Calculate the middle index of the search range as the average of the starting and ending indices.

4. Check if the middle element of the search range equals the target integer. If it does, return the index of the middle element.

5. If the middle element is less than the target integer, recursively call the binary search function with the updated starting index set to the middle index + 1.

6. If the middle element is greater than the target integer, recursively call the binary search function with the updated ending index set to the middle index - 1.
7. Return -1 if the target integer is not found within the search range.

## Complexity
- Time complexity: O(log n), where n is the size of the input array.

- Space complexity: O(log n), where n is the size of the input array.

## Code
**Algo1 file WITH RECURSION :**<br/>
**Algo2 file WITHOUT RECURSION :**

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/binary-search/solutions/3367422/easy-solution-with-without-recursion-d/)
