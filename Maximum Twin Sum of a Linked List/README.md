# Question

## 2130. Maximum Twin Sum of a Linked List

In a linked list of size `n`, where `n` is **even**, the `ith` node **(0-indexed)** of the linked list is known as the **twin** of the `(n-1-i)th` node, if `0 <= i <= (n / 2) - 1`.

For example, if `n = 4`, then node `0` is the twin of node `3`, and node `1` is the twin of node `2`. These are the only nodes with twins for `n = 4`.
The **twin sum** is defined as the sum of a node and its twin.

Given the `head` of a linked list with even length, return the **maximum twin sum** of the linked list.<br/>

**Example 1:**<br/>
![image](https://assets.leetcode.com/uploads/2021/12/03/eg1drawio.png)
```
Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 
```
**Example 2:**<br/>
![image](https://assets.leetcode.com/uploads/2021/12/03/eg2drawio.png)
```
Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 
```

**Example 3:**<br/>
![image](https://assets.leetcode.com/uploads/2021/12/03/eg3drawio.png)
```
Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
```

**Constraints:**
- The number of nodes in the list is an even integer in the range `[2, 10^5]`.
- `1 <= Node.val <= 10^5`

*you can try to solve the problem from [here](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/)*

<h1 align="center">Solution</h1>

## Intuition
In this particular situation, our approach involves converting the linked list into a vector. This conversion allows us to easily access elements from the end and navigate backwards. However, if the linked list were a doubly linked list, there would be no need for the vector.

## Approach

```
function pairSum(head)
    current = head
    values = empty vector

    while current is not null
        values.push_back(current.val)
        current = current.next

    i = 0
    j = values.size() - 1
    maximumSum = 0

    while i < j
        maximumSum = max(maximumSum, values[i] + values[j])
        i++
        j--

    return maximumSum
```

## Complexity
- Time & Space complexity: O(n) time, where n is the number of nodes in the linked list.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/solutions/3537512/easy-cpp-solution-with-pseudocode-and-explanation/)