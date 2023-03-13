# Question
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

**Example 1:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg)
```
Input: root = [1,2,2,3,4,4,3]
Output: true
```
**Example 2:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg)
```
Input: root = [1,2,2,null,3,null,3]
Output: false
```

<h1 align="center">Solution</h1>

## Intuition
Sure! The isSymmetric function checks if a binary tree is symmetric by checking if its left subtree is a mirror image of its right subtree. Intuitively, a binary tree is symmetric if and only if its left and right subtrees are mirror images of each other.

To check if two subtrees are mirror images of each other, we compare the values of their root nodes and recursively check if their left and right subtrees are mirror images of each other, but with the order reversed. This is because for two subtrees to be mirror images of each other, their corresponding branches must be mirror images of each other, but with the order reversed.

## Approach
The isSymmetric function checks if the root node is NULL, in which case it returns true, since an empty tree is always symmetric. Otherwise, it calls the isMirror function with the left and right subtrees of the root node.

The isMirror function recursively checks if two nodes are mirror images of each other by comparing their values and their left and right subtrees. If both nodes are NULL, it returns true, since two NULL nodes are considered to be mirror images of each other. If only one of the nodes is NULL, it returns false, since a node and a NULL value cannot be mirror images. If the values of the nodes are not equal, it returns false, since two nodes with different values cannot be mirror images. Otherwise, it recursively checks if the left subtree of the first node is a mirror image of the right subtree of the second node, and if the right subtree of the first node is a mirror image of the left subtree of the second node. If both of these checks are true, it returns true, indicating that the two nodes are mirror images of each other.

## Complexity
- Time complexity: O(n) 
where n is the number of node as it vists each node in the BST
- Space complexity: O(h) 
where h is the height of the tree

## pseudocode
```
function isSymmetric(root):
    if root is null:
        return true
    return isMirror(root.left, root.right)

function isMirror(left, right):
    if left is null and right is null:
        return true
    if left is null or rigth is null:
        return false
    return left.val == right.val and isMirror(left.left, right.right) and isMirror(left.right, right.left)

```

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/symmetric-tree/solutions/3293701/easy-recursion-solution-with-explanation/)