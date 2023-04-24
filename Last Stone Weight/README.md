# Question

## 1046. Last Stone Weight

You are given an array of integers `stones` where `stones[i]` is the weight of the `ith` stone.

We are playing a game with the stones. On each turn, we choose the **heaviest two stones** and smash them together. Suppose the heaviest two stones have weights `x` and `y` with `x <= y`. The result of this smash is:

- If `x == y`, both stones are destroyed, and
- If `x != y`, the stone of weight `x` is destroyed, and the stone of weight `y` has new weight `y - x`.
At the end of the game, there is **at most one** stone left.

Return *the weight of the last remaining stone*. If there are no stones left, return `0`.<br/>

**Example 1:**<br/>
```
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
```
**Example 2:**<br/>
```
Input: stones = [1]
Output: 1
```

**Constraints:**
- `1 <= stones.length <= 30`
- `1 <= stones[i] <= 1000`

*you can try to solve the problem from [here](https://leetcode.com/problems/last-stone-weight/description/)*

<h1 align="center">Solution</h1>


## Intuition
In this algorithm, we easily sort the vector in descending order. so the first 2 element are the biggest one smash them due the conditions.

## Approach
1. Determine the size of the input vector `stones` and store it in an integer variable `n`.
2. Sort the input vector `stones` in descending order.
3. Initialize an integer variable `i` to 0.
4. Use a while loop to iterate through the `stones` vector while `i` is less than `n - 1`.
5. Check if the current stone weight at index `i` is equal to the stone weight at index `i + 1`.
6. If they are equal, set the weight at index `i + 1` to 0 and increment `i` by 2.
7. If they are not equal, set the weight at index `i + 1` to the absolute value of the difference between the weights at indices `i` and `i + 1`.
8. Increment `i` by 1 and sort the `stones` vector again in descending order, starting from index `i`.
9. Continue looping until there is only one stone left or no stones at all.
10. Return the weight of the remaining stone, which will be at index 0 if there is only one stone left.

## Complexity
- Time complexity: O(nlogn), where n is the size of the input vector `stones`.
- Space complexity: O(n), where n is the size of the input vector `stones`.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/last-stone-weight/solutions/3450437/easy-solution-in-cpp-with-explanation/)
