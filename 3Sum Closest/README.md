# Question
Given an integer array (nums) of length (n) and an integer (target), find three integers in nums such that the sum is closest to target.

Return the (sum) of the three integers.

You may assume that each input would have exactly one solution.

**Example 1:**<br/>
```
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```
**Example 2:**<br/>
```
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
```
<h1 align="center">Solution</h1>

## Intuition
We need to point to 3 elements in the arrays and check whether their sum equals the target. The first idea which comes to my mind is to use 3 for nested loops.
But the problem is the time complexity which will be O(n^3) 😞

## Approach
The Algorithm I use is:
1. Sort the vector so the smallest elements will be on the left side and the greater ones will be on the right side.
2. Define 3-pointers (i, low, high). i ⇒ the first element in the vector (and will be a counter in the for loop). low ⇒ the element comes after i. high  ⇒ the last element of the array.
3. Sum the elements of the 3-pointers and compare the sum to the target if they are equal 
	then we reached the target.
4. But if it isn’t equal to the target we get the difference between the target and the sum and the sum of the 3 elements.
5. Then try to move the left or right pointer to the next or previous elements depending on which is bigger the sum or the target.
6. Repeat steps 2,3,4 and 5 until reaching the minimum difference or the target.

## Pseudo Code
```
THREE-SUM-CLOSEST(NUMS, target)
    Sum = 0, diff = inf
	Sort NUMS
	For i = 0 ⇒ size -2
		First = NUMS[i], low = i+1, high = size -1
		While low < high
			If First + NUMS[low] + NUMS[high] = target 
				Return target
			If  |First + NUMS[low] + NUMS[high] - target| < diff
				diff = |First + NUMS[low] + NUMS[high] - target|
				Sum = First + NUMS[low] + NUMS[high]
			If First + NUMS[low] + NUMS[high] < target
				low++
			Else
				high++
	Return Sum
```
## Complexity
- Time complexity: O(n^2)

## LeetCode Account
You can have a close look from [here - LeetCode](https://leetcode.com/problems/3sum-closest/solutions/3274280/easy-solution-using-c/)

