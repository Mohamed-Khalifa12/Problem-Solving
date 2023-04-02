# Question
You are given two positive integer arrays `spells` and `potions`, of length `n` and `m` respectively, where `spells[i]` represents the strength of the `ith` spell and `potions[j]` represents the strength of the `jth` potion.

You are also given an integer `success`. A spell and potion pair is considered **successful** if the **product** of their strengths is **at least** `success`.

Return *an integer array `pairs` of length `n` where `pairs[i]` is the number of **potions** that will form a successful pair with the `ith` spell.*<br/>
**Example 1:**<br/>
```
Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
- 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
Thus, [4,0,3] is returned.
```
**Example 2:**<br/>
```
Input: spells = [3,1,2], potions = [8,5,8], success = 16
Output: [2,0,2]
Explanation:
- 0th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
- 1st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful. 
- 2nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful. 
Thus, [2,0,2] is returned.
```

**Constraints:**

- `n == spells.length`
- `m == potions.length`
- `1 <= n, m <= 105`
- `1 <= spells[i], potions[i] <= 105`
- `1 <= success <= 1010`

<h1 align="center">Solution</h1>

## Intuition
The objective of this task is to simulate a binary search algorithm, but with a different condition. Instead of finding an element, we need to find the index where a `success` variable is greater than or equal to that index. To achieve this, we first sort the `potion` array to make it possible to apply the binary search algorithm. We begin by checking the middle element of `potions`, and if the product of the middle element and the `spell` element is greater than the `success` variable, we continue the search on the left half of the array, otherwise we continue on the right half. This process is repeated until we find the last index that satisfies the condition. The number of elements passed is then calculated by subtracting the last index we found from the length of the array.

*Binary Search (BS) algorithm available along with its solution and code, and you can access it from [GitHub](https://github.com/Mohamed-Khalifa12/Problem-Solving/tree/main/Binary%20Search) or [LeetCode](https://leetcode.com/problems/binary-search/solutions/3367422/easy-solution-with-without-recursion-d/)*

## Approach
1. First, sort the `potions` array in non-decreasing order using the `sort()` function.

2. Create an empty vector `result` to store the number of successful pairs for each spell.

3. Iterate over each element `spell` in the `spells` vector.

4. Set `start` to 0 and `end` to the last index of the `potions` array, which is `potions.size() - 1`. Also, set `index` to `length`, where `length` is the size of the `potions` array.

5. While `start` is less than or equal to `end`, do the following:

    1. Calculate the middle index `mid` as the average of `start` and `end`.
    2. Check if the product of `spell` and the element at index `mid` in the `potions` array is greater than or equal to the `success` variable. If it is, update end to be `mid - 1` and store the current index `mid` in the `index` variable.
    3. If the product is less than the `success` variable, update `start` to be `mid + 1`.

6. After the while loop, push the result `length - index` into the `result` vector.

7. Repeat steps 3 to 6 for each element in the `spells` vector.

8. Return the `result` vector.

This algorithm uses binary search to find the index of the first element in the `potions` array that satisfies the condition for a successful pair, and then calculates the number of remaining elements in the array to determine the number of successful pairs.

## Complexity
- Time complexity: O(Q * logN), where Q is the size of the `spells` vector and N is the size of the `potions` array.

- Space complexity: O(Q), where Q is the size of the `spells`.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/solutions/3372001/easy-solution-with-explanation-in-cpp-d-beats-96-5/)