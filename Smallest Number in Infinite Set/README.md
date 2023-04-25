# Question

## 2336. Smallest Number in Infinite Set

You have a set which contains all positive integers `[1, 2, 3, 4, 5, ...]`.

Implement the `SmallestInfiniteSet` class:

- `SmallestInfiniteSet()` Initializes the **SmallestInfiniteSet** object to contain **all** positive integers.
- `int popSmallest()` **Removes** and returns the smallest integer contained in the infinite set.
- `void addBack(int num)` **Adds** a positive integer `num` back into the infinite set, if it is not already in the infinite set.<br/>

**Example 1:**<br/>
```
Input
["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
[[], [2], [], [], [], [1], [], [], []]
Output
[null, null, 1, 2, 3, null, 1, 4, 5]

Explanation
SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change is made.
smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to the set and
                                   // is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 5, and remove it from the set.
```

**Constraints:**
- `1 <= num <= 1000`
- At most `1000` calls will be made **in total** to `popSmallest` and `addBack`.

*you can try to solve the problem from [here](https://leetcode.com/problems/smallest-number-in-infinite-set/description/)*

<h1 align="center">Solution</h1>

## Intuition
This data structure uses a min priority queue to insert and extract elements in O(lgn) time. The priority queue is initialized with the integers from 0 to 1000. A set is also initialized to prevent duplicates. When adding an element, we first check if it is already in the set. If it is not, we add it. To remove an element, we extract the smallest element from the priority queue and erase it from the set.

## Approach
**Initialize a min priority queue pq and a set s.**
For i from 0 to 1000:
  Push i onto pq.
  Insert i into s.

**popSmallest():**
  Remove the smallest element from pq and return it.
  Erase the element from s.

**addBack(num):**
  If num is not in s:
    Insert num into s.
    Push num onto pq.


## Complexity
- Time complexity: O(n) for the constructor, O(log n) for popSmallest(), and O(log n) for addBack(). 

- Space complexity: O(n)

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/smallest-number-in-infinite-set/solutions/3455342/easy-solution-in-cpp-with-explanation-pseudocode/)