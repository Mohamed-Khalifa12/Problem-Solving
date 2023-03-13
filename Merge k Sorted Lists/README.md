# Question
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

**Example 1:**<br/>
```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```
**Example 2:**<br/>
```
Input: lists = []
Output: []
```
**Example 3:**<br/>
```
Input: lists = [[]]
Output: []
```

<h1 align="center">Solution</h1>

## Intuition
The main concept of the algorithm is to keep track of the first element of each linked list and repeatedly find the minimum element among them. We then add the minimum element to the merged linked list and move to the next element of the linked list it came from. We continue doing this until we reach the end of all the linked lists and have merged them into a single sorted linked list.

## Approach
To begin, we first check if the input vector is empty or has only one element. If it is empty, we return a null pointer. If it has only one element, we return it as the merged linked list. If neither of these cases is true, we proceed with the algorithm.

The algorithm involves checking if all elements have been processed or not. If all the pointers point to null nodes, we exit the recursion. However, if not, we continue with the algorithm by using a function that we create to find the minimum value among the elements pointed to by the pointers in each linked list. This function serves two purposes: it returns the minimum value, and it moves the pointer of a specific linked list to the next element.

We repeat this process until we reach the end of each linked list and the recursion exits through the base case.

## Complexity
- Time complexity: O(n)

- Space complexity: O(n)

## Pseudocode
```
mergeKLists(lists):
    // Check if input vector is empty
    if lists is empty:
        return null
    // Check if input vector has only one element
    if size of lists is 1:
        return the only list in lists
    //base case
    if all pointers points to null:
        return null
    //proceed the recursion
    val = min(lists)
    return ListNode(val, mergeKLists(lists))

min(lists)
    min = lists[0].val, index = 0
    for i = 1 upto size(lists)
        if(lists[i].val < min)
            min = lists[i].val
            index = i
    lists[index] = lists[index].next
    return min
```

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/merge-k-sorted-lists/solutions/3290230/easy-recursion-solution/)