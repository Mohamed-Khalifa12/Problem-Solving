# Question

## 1721. Swapping Nodes in a Linked List

You are given the `head` of a linked list, and an integer `k`.

Return *the head of the linked list after **swapping** the values of the `kth` node from the beginning and the `kth` node from the end (the list is **1-indexed**)*.<br/>

**Example 1:**<br/>
![image](https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg)
```
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
```
**Example 2:**<br/>
```
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
```

**Constraints:**
- The number of nodes in the list is `n`.
- `1 <= k <= n <= 10^5`
- `0 <= Node.val <= 100`

*you can try to solve the problem from [here](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/)*

<h1 align="center">Solution</h1>

## Intuition
To solve this problem, we use a method called the "two pointer approach". We start by setting a pointer to the `kth` element of the linked list. We then move this pointer towards the end of the list while simultaneously moving another pointer from the beginning towards the end. Eventually, when the `kth` pointer reach the end of the LL the other pointer reach `(n-k)th` element. Now we have the 2 elements we want to swap.

## Approach
```
1. Initialize leftptr and rightptr as head and endptr as NULL.
2. Traverse the linked list from head using rightptr, incrementing it k-1 times.
3. Set endptr to the current position of rightptr.
4. Traverse the linked list again with leftptr and rightptr simultaneously until rightptr reaches the end of the list.
5. Swap the values of endptr and leftptr.
6. Return the head of the modified linked list.
```

## Complexity
- Time complexity: O(n), where n is the number of nodes in the linked list.

- Space complexity:  O(1).

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/solutions/3528421/easy-solution-in-cpp-with-explanation-and-pseudocode/)
