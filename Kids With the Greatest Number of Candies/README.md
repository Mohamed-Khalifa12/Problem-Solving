# Question
## 1431. Kids With the Greatest Number of Candies
There are `n` kids with candies. You are given an integer array `candies`, where each `candies[i]` represents the number of candies the `ith` kid has, and an integer `extraCandies`, denoting the number of extra candies that you have.

Return *a boolean array `result` of length `n`, where `result[i]` is `true` if, after giving the `ith` kid all the `extraCandies`, they will have the **greatest** number of candies among all the `kids`, or false otherwise.*

Note that **multiple** kids can have the **greatest** number of candies.<br/>

**Example 1:**<br/>
```
Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
```
**Example 2:**<br/>
```
Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
Explanation: There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.
```

**Example 3:**<br/>
```
Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]
```

**Constraints:**

- `n == candies.length`
- `2 <= n <= 100`
- `1 <= candies[i] <= 100`
- `1 <= extraCandies <= 50`

*You can try to solve this problem from [here](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/)*

<h1 align="center">Solution</h1>

## Intuition
The main objective of this problem is to find the highest value in the array and then verify whether the sum of the extra candies and the candies already present is greater than or equal to that maximum value.

## Approach
1. Finds the maximum number of candies among all children.
2. Iterates through the candies array again and checks whether the sum of the extra candies and the candies of the current child is greater than or equal to the maximum number of candies found earlier.
3. that child is capable of having the most candies with the extra candies added, and the corresponding element of the result vector is set to true.
4. Finally, the function returns the result vector.

## Complexity
- Time & Space Complexity: O(n), where n is the size of candies array.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/solutions/3426428/easy-solution-with-explanation-in-cpp/)
