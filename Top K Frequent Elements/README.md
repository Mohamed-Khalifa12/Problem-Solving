# Question
## 347. Top K Frequent Elements

Given an integer array `nums` and an integer `k`, return the `k` most *frequent elements*. You may return the answer in **any order**.

**Example 1:**<br/>
```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```
**Example 2:**<br/>
```
Input: nums = [1], k = 1
Output: [1]
```

**Constraints:**
- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `k` is in the range `[1, the number of unique elements in the array]`.
- It is **guaranteed** that the answer is **unique**.
 

**Follow up**: Your algorithm's time complexity must be better than `O(n log n)`, where n is the array's size.

*you can try to solve the problem from [here](https://leetcode.com/problems/top-k-frequent-elements/description/)*

<h1 align="center">Solution</h1>



## Intuition
In this algorithm, we utilize the priority queue data structure once we have mapped the elements in the unordered map.

you can find more about priority queues (types, impelementation and explanation) from [here](https://github.com/Mohamed-Khalifa12/algorithms-and-data-structures/tree/main/Heap%20Sort)

## Approach
```
function topKFrequent(nums, k):
    n = length(nums)
    mp = empty unordered_map<int, int>
    Res = empty vector<int>

    // Count the frequency of each number in the input array
    for i from 0 to n-1:
        mp[nums[i]]++

    m = empty max priority_queue of pairs of integers
    // Push frequency and number pairs into the priority queue
    for each pair (key, value) in mp:
        m.push(make_pair(value, key))

    // Extract the top k frequent numbers from the priority queue
    for i from 0 to k-1:
        Res.push_back(m.top().second)
        m.pop()

    return Res
```

## Complexity
- Time complexity: O(n + mlogm + klogm),  where n is the number of elements in the array and  m is the number of unique elements in the input array.
- Space complexity: O(m + k).

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/top-k-frequent-elements/solutions/3553211/easy-cpp-solution-with-pseudocode/)
