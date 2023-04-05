# Question
## 2439. Minimize Maximum of Array
You are given a **0-indexed** array `nums` comprising of `n` non-negative integers.

In one operation, you must:
- Choose an integer `i` such that `1 <= i < n` and `nums[i] > 0`.
- Decrease `nums[i]` by 1.
- Increase `nums[i - 1]` by 1.

*Return the **minimum** possible value of the **maximum** integer of `nums` after performing **any** number of operations.*<br/>

**Example 1:**<br/>
```
Input: nums = [3,7,1,6]
Output: 5
Explanation:
One set of optimal operations is as follows:
1. Choose i = 1, and nums becomes [4,6,1,6].
2. Choose i = 3, and nums becomes [4,6,2,5].
3. Choose i = 1, and nums becomes [5,5,2,5].
The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
Therefore, we return 5.
```
**Example 2:**<br/>
```
Input: nums = [10,1]
Output: 10
Explanation:
It is optimal to leave nums as is, and since 10 is the maximum value, we return 10.
```

**Constraints:**
- `n == nums.length`
- `2 <= n <= 105`
- `0 <= nums[i] <= 109`

*you can try to solve the problem from [here](https://leetcode.com/problems/minimize-maximum-of-array/description/)*

<h1 align="center">Solution</h1>


## Question Explaination
JUST IMAGINE :"D
In this problem scenario, instead of numbers in each cell of the array, we have a bottle of water, and the quantity of water in each bottle corresponds to the number in the array. For instance, if a cell has a value of 5, the bottle in that cell is filled with more than 2 units of water. Our goal is to pour water from one bottle to another according to two conditions. First, we can only pour water from a bottle into the previous bottle; pouring into the next bottle is not allowed. Second, we must pour water until each bottle contains the minimum possible amount of water.

## Intuition
If we imagine that we can pour water in both the next and previous bottles, we can add up the quantities in all the bottles and then divide the total by the number of bottles to get the minimum number that must be present in each bottle. Since each value must be an integer, we can easily round up to the nearest integer using the ceil function. For example, if we have an array like [3, 7, 1, 6], the average value of the bottles would be 3.5, but because we need integer values, we can consider them as 4, 4, 3, and 3. Therefore, the maximum value to be returned would be the ceil of 3.5, which is 4.

To solve the main problem, which is pouring water to each bottle only to the previous one, we can follow these steps:

- First, we start with the first bottle only and consider it's quantity is the max. Then, we join the second bottle to it and check whether the quantity of water in the second bottle has increased or not after applying the average concept as mentioned above. If the quantity has increased, then pouring was in the wrong direction, and we discard it. But if the quantity has decreased, then pouring was in the right direction, so we save the new quantity.

- We can use the max function to keep track of the saved data to get the maximum value of the average quantity of water saved at each bottle. We repeat the process by adding the next bottle to the last saved bottle and check the quantity of water in the new bottle. We keep doing this until we reach the end of the array (the last bottle). Finally, we return the saved data.

For example, let's say we have an array of bottles with water quantities [3, 7, 1, 6]. We start by considering first quantity 3 is the max. Then we calculate the average quantity, which should be (3+7)/2 = 5. Since the water quantity in the second bottle has decreased to 4, the pouring is in the right dirstion and save the average value. We repeat the process with the next bottle and save the new data if it's larger than the previous saved data.

After repeating the process until the last bottle, we will have the minimum possible value of the maximum integer in each bottle.

## Approach
Here's a step-by-step approach to understanding the given code:

1. Define an integer variable called `prefixsum` and initialize it to 0. This variable will be used to keep track of the sum of values in the array up to a certain index.
2. Define another integer variable called `output` and initialize it to 0. This variable will be used to keep track of the minimum value in the array that will be the largest.
3. Iterate over each element in the input array `nums`.
4. Add the current element to the `prefixsum` variable.
5. Compute the average value of the array elements up to and including the current element by dividing `prefixsum` by `(i + 1)`, where `i` is the current index of the array.
6. Use the `ceil` function to round up the average value to the nearest integer, since the array elements must be integers.
7. Update `output` to be the maximum value between its current value and the rounded up average value from step 6.
9. Return `output` after the iteration is complete.

## Complexity
- Time complexity: O(n), where n is the size of the input array nums.

- Space complexity: O(1), since we only use a constant amount of extra space to store the prefix sum, the output value, and the loop counter variable.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/minimize-maximum-of-array/solutions/3383621/bottle-solution-approach-d/)