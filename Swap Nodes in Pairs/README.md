# Question

## 24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)<br/>

**Example 1:**<br/>
![image](https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg)
```
Input: head = [1,2,3,4]
Output: [2,1,4,3]
```
**Example 2:**<br/>
```
Input: head = []
Output: []
```

**Example 3:**<br/>
```
Input: head = [1]
Output: [1]
```

**Constraints:**
- The number of nodes in the list is in the range `[0, 100]`.
- `0 <= Node.val <= 100`

*you can try to solve the problem from [here](https://leetcode.com/problems/swap-nodes-in-pairs/description/)*

<h1 align="center">Solution</h1>


## Intuition
In this particular issue, we establish two pointers: the initial one points to the first element, and the second one points to the second element. After swapping their positions, we advance both pointers by two steps to access two different nodes in the linked lists. We continue this process until either of the pointers becomes null.

## Approach
1. Check if the input `head` is null or there is only one node (`head->next` is null). If so, return the `head` as is since there is nothing to swap.
2. Initialize two pointers, `first` and `second`, pointing to the first and second nodes, respectively.
3. Enter a loop that continues as long as both `first` and `second` pointers are not null.
4. Inside the loop, swap the values of the nodes pointed to by `first` and `second` using the `swap` function.
5. Move the first pointer two steps forward by assigning `first = first->next->next`. This skips over the swapped nodes.
6. Check if the `second` pointer has a next node (`second->next`). If it does, move the `second` pointer two steps forward by assigning `second = second->next->next`. This also skips over the swapped nodes.
7. Repeat steps 4-6 until either the `first` pointer or the `second` pointer becomes null. This will happen when there are no more pairs of nodes to swap.
8. Finally, return the `head` pointer, which now represents the modified linked list with swapped pairs.

```
function swapPairs(head):
    if head is null or head->next is null:
        return head

    first = head
    second = head->next

    while first and second:
        swap(first->val, second->val)
        first = first->next->next

        if second->next is not null:
            second = second->next->next

    return head
```

## Complexity
- Time complexity: O(n), where n is the number of nodes in the linked list.

- Space complexity: O(1).

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/swap-nodes-in-pairs/solutions/3531971/easy-cpp-solution-with-explanation-and-pseudocode/)