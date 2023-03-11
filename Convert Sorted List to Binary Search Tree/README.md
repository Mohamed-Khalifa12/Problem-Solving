# Intuition
Initially, the central element of the Linked List is identified as the root of the Binary Search Tree (BST). Subsequently, the Linked List is partitioned into two smaller Linked Lists, and the aforementioned procedure is repeated recursively on both the left and right portions.
# Approach
To start, we check if the linked list is empty. If it is, we return null. If there is only one element in the linked list, we return that element as the binary search tree. If neither of these conditions applies, we proceed with our algorithm.

Our initial task is to locate the middle element of the linked list and designate it as the root of the binary search tree.

To accomplish this, we employ two pointers: slow and fast. Initially, the slow pointer is positioned at the head of the linked list, while the fast pointer is located two elements ahead of the slow pointer. We increment the slow pointer by one step and the fast pointer by two steps.

When the fast pointer reaches the end of the linked list, the slow pointer will be positioned one step back to the middle element.

At this point, we identify the middle element as the root of the binary search tree. We then split the linked list into two smaller parts and apply the same steps recursively to create the left and right subtrees of the binary search tree.

# Complexity
- Time complexity: O(n)

- Space complexity: O(n)

# Pseudocode
```
function sortedListToBST(head):
    if head is null:
        return null
    if head.next is null:
        return new TreeNode(head.val)
    
    # Find middle element
    slow = head
    fast = head.next.next
    while fast is not null and fast.next is not null:
        slow = slow.next
        fast = fast.next.next
    
    # Create new node for root
    root = new TreeNode(slow.next.val)

    # Recursively build left and right subtrees
    root.right = sortedListToBST(slow.next.next)
    # Divide list into two smaller parts
    slow.next = null
    root.left = sortedListToBST(head)

    
    return root
```
In this pseudocode, we first handle the base cases where the linked list is empty or contains only one element. Then we use a slow and fast pointer to find the middle element of the linked list, which will become the root of the binary search tree.

We create a new node for the root, divide the linked list into two smaller parts, and recursively build the left and right subtrees of the binary search tree. Finally, we return the root node.

# LeetCode 
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/solutions/3283860/easy-recursion-solution/)