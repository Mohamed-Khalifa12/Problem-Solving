# Question

## 1964. Find the Longest Valid Obstacle Course at Each Position

You want to build some obstacle courses. You are given a **0-indexed** integer array `obstacles` of length `n`, where `obstacles[i]` describes the height of the `ith` obstacle.

For every index `i` between `0` and `n - 1` **(inclusive)**, find the length of the **longest obstacle course** in `obstacles` such that:

- You choose any number of obstacles between `0` and `i` **inclusive**.
- You must include the `ith` obstacle in the course.
- You must put the chosen obstacles in the **same order** as they appear in `obstacles`.
- Every obstacle (except the first) is **taller** than or the **same height** as the obstacle immediately before it.
*Return an array `ans` of length `n`, where `ans[i]` is the length of **the longest obstacle course** for index `i` as described above.*<br/>

**Example 1:**<br/>
```
Input: obstacles = [1,2,3,2]
Output: [1,2,3,3]
Explanation: The longest valid obstacle course at each position is:
- i = 0: [1], [1] has length 1.
- i = 1: [1,2], [1,2] has length 2.
- i = 2: [1,2,3], [1,2,3] has length 3.
- i = 3: [1,2,3,2], [1,2,2] has length 3.
```
**Example 2:**<br/>
```
Input: obstacles = [2,2,1]
Output: [1,2,1]
Explanation: The longest valid obstacle course at each position is:
- i = 0: [2], [2] has length 1.
- i = 1: [2,2], [2,2] has length 2.
- i = 2: [2,2,1], [1] has length 1.
```

**Example 3:**<br/>
```
Input: obstacles = [3,1,5,6,4,2]
Output: [1,1,2,3,2,2]
Explanation: The longest valid obstacle course at each position is:
- i = 0: [3], [3] has length 1.
- i = 1: [3,1], [1] has length 1.
- i = 2: [3,1,5], [3,5] has length 2. [1,5] is also valid.
- i = 3: [3,1,5,6], [3,5,6] has length 3. [1,5,6] is also valid.
- i = 4: [3,1,5,6,4], [3,4] has length 2. [1,4] is also valid.
- i = 5: [3,1,5,6,4,2], [1,2] has length 2.
```

**Constraints:**
- `n == obstacles.length`
- `1 <= n <= 10^5`
- `1 <= obstacles[i] <= 10^7`

*you can try to solve the problem from [here](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/description/)*

<h1 align="center">Solution</h1>


## Intuition
This problem requires finding the longest sequence of obstacles from 0 to index i. The approach is to do this greedily by adding each `obstacle[i]` to a list vector in a specific way. The appropriate index to add the obstacle is immediately after the element that is smaller than it. If the obstacle is the largest, it should be added at the end of the list to continue the sequence of the longest obstacles. If it is not the largest, then it should be added directly after an element that is smaller than it, and the longest obstacle sequence should be updated to be the index where the new obstacle is added.

## Approach

1. Initialize an empty list vector to keep track of the longest obstacle sequence.
2. Iterate through the obstacles vector and for each obstacle, find its appropriate index in the list vector using the `upper_bound` function.
3. If the index found in step 2 is equal to the length of the list vector, then add the obstacle to the end of the list vector. Otherwise, replace the element at the found index with the current obstacle.
4. Record the length of the longest obstacle sequence at each position by adding 1 to the index found in step 2, and store it in the result vector.
5. Return the result vector containing the length of the longest obstacle sequence at each position.

```
function longestObstacleCourseAtEachPosition(obstacles):
    n = length(obstacles)
    result = array of n integers
    list = empty array of integers
    
    for i from 0 to n-1 do:
        idx = index of the first element in list that is greater than obstacles[i]
        if idx is equal to the length of list then:
            append obstacles[i] to the end of list
        else:
            set list[idx] to obstacles[i]
        set result[i] to idx + 1
    
    return result

```

## Complexity
- Time complexity: O(nlgn), where n is the length of `obstacles`.

- Space complexity: O(n), where n is the length of `obstacles`.


## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/solutions/3494627/easy-explanation-with-pseudocode/)