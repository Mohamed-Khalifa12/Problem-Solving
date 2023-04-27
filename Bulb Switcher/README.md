# Question

## 319. Bulb Switcher

There are `n` bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the `ith` round, you toggle every `i` bulb. For the `nth` round, you only toggle the last bulb.

Return *the number of bulbs that are on after `n` rounds.*<br/>

**Example 1:**<br/>
![img](https://assets.leetcode.com/uploads/2020/11/05/bulb.jpg)
```
Input: n = 3
Output: 1
Explanation: At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off]. 
So you should return 1 because there is only one bulb is on.
```
**Example 2:**<br/>
```
Input: n = 0
Output: 0
```

**Example 3:**<br/>
```
Input: n = 1
Output: 1
```

**Constraints:**
- `0 <= n <= 10^9`

*you can try to solve the problem from [here](https://leetcode.com/problems/bulb-switcher/description/)*

<h1 align="center">Solution</h1>

## Intuition
In this problem, the best approach is to focus on each bulb and observe what happens. For example, consider bulb 1 which has only 1 factor, which is odd, so its status will change from off to on and not change again. Bulb 2 has factors (1, 2) which are even, so it will change its status from on to off and not change again. Similarly, bulb 3 has factors (1, 3) which are even, so it will also change its status from on to off and not change again. Bulb 4 has factors (1, 2, 4) which are odd, so it will change its status from on to off to on, and its status will not change again. You can continue this sequence until the end and observe that bulbs with odd numbers of factors will end up being on while bulbs with even numbers of factors will end up being off.

Specifically, we notice that the bulbs whose number is a perfect square have an odd number of factors, while all other bulbs have an even number of factors. For example, the factors of 12 are (1, 2, 3, 4, 6, 12), and there are an even number of them, so bulb 12 will be off at the end. However, the factors of 16 are (1, 2, 4, 8, 16), and the last factor is equal to the square root of 16, so the number of factors is odd, and bulb 16 will be on at the end.

Therefore, we can conclude that any perfect square will cause the corresponding bulb to be on at the end, and the number of bulbs that will be on is equal to the number of perfect squares less than or equal to n.

## Approach
1. return sqrt(`n`)

## Complexity
- Time & Space complexity: O(1)

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/bulb-switcher/solutions/3461605/easy-explanation/)
