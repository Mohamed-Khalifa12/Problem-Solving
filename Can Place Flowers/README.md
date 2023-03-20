# Question
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array `flowerbed` containing `0`'s and `1`'s, where `0` means empty and `1` means not empty, and an integer `n`, return if `n` new flowers can be planted in the `flowerbed` without violating the no-adjacent-flowers rule.

**Example 1:**<br/>
```
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
```
**Example 2:**<br/>
```
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
```

**Constraints:**

- `1 <= flowerbed.length <= 2 * 104`
- `flowerbed[i]` is `0` or `1`.
- There are no two adjacent flowers in `flowerbed`.
- `0 <= n <= flowerbed.length`

<h1 align="center">Solution</h1>

## Intuition
This algorithm involves iterating through all elements in an array and examining whether the preceding and succeeding elements are equal to 0. If they are, we can plant a flower in the current index. After doing so, we will decrease the total number of flowers left to be planted by 1 and mark the current index as "planted" by changing its value to 1.

## Approach
1. Initialize a counter variable "n" to the number of flowers that need to be planted.
2. Iterate through the elements of the "flowerbed" array from left to right.
3. For each element in the array, check if it's possible to plant a flower in the current index. To do this, check if the current element and its adjacent elements (if they exist) are all 0. If they are, plant a flower in the current index and decrement the "n" counter variable by 1.
4. After iterating through the entire "flowerbed" array, check if the "n" counter variable is equal to 0. If it is, return True, indicating that all "n" flowers have been successfully planted. Otherwise, return False, indicating that it was not possible to plant all "n" flowers in the given "flowerbed" array.

## Complexity
- Time complexity: O(n), where n is the size of the vector 

- Space complexity: O(1)

## Pseudocode
```
function canPlaceFlowers(flowerbed, n):
    if n = 0:
        return true
    for i = 0 to length(flowerbed) - 1 do
        if flowerbed[i] = 1:
            continue
        //This part indicate to the current index = 0
        if flowerbed[i-1] and flowerbed[i+1]:
            flowerbed[i] = 1
            n = n - 1
        if n = 0 then
            return True
    return False

```
## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/can-place-flowers/solutions/3319708/easy-solution-with-cpp-and-explanation/)