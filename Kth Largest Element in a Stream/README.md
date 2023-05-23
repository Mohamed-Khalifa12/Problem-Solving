# Question
## 703. Kth Largest Element in a Stream

Design a class to find the `kth` largest element in a stream. Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.

Implement `KthLargest` class:

- `KthLargest(int k, int[] nums)` Initializes the object with the integer `k` and the stream of integers `nums`.
- `int add(int val)` Appends the integer `val` to the stream and returns the element representing the `kth` largest element in the stream.

**Example 1:**<br/>
```
Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
```

**Constraints:**
- `1 <= k <= 10^4`
- `0 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `-10^4 <= val <= 10^4`
- At most `10^4` calls will be made to `add`.
- It is guaranteed that there will be at least `k` elements in the array when you search for the `kth` element.

*you can try to solve the problem from [here](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)*

<h1 align="center">Solution</h1>

## Intuition
In this algorithm, we utilize the priority queue data structure to get the max element and remove it tot get the next max one and so on.

you can find more about priority queues (types, impelementation and explanation) from [here](https://github.com/Mohamed-Khalifa12/algorithms-and-data-structures/tree/main/Heap%20Sort)

## Approach

```
Class KthLargest
    Constructor KthLargest(k, nums)
        Assign k to this.k
        For i = 0 to nums.size() - 1
            Push nums[i] into this.pq

    Function add(val)
        Push val into this.pq
        While this.pq.size() > this.k
            Pop an element from this.pq
        Return this.pq.top()

```

## Complexity
- Time complexity: O(nlogn), where n is the size of nums.

- Space complexity: O(n).

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/kth-largest-element-in-a-stream/solutions/3555442/easy-cpp-solution-with-pseudocode/)