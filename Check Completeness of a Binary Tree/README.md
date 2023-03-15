# Question
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

**Example 1:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-1.png)
```
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
```
**Example 2:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-2.png)
```
Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
```

<h1 align="center">Solution</h1>

# First Algorithm

## Intuition
In order to address this issue, we must retrieve the data from the BST by level instead of following a traversal method that goes from left to right (as is the case with recursion). To accomplish this, we will rely on the use of queue data structures. This approach is commonly referred to as the Breadth First Search algorithm.

you can know more about queue from [here](https://www.geeksforgeeks.org/queue-cpp-stl/)

## Approach
To check if a binary search tree (BST) is complete, we need to examine its structural properties. A complete binary tree is a tree in which all levels, except possibly the last level, are completely filled, and all nodes are as far left as possible.

Here's an approach to check the completeness of a BST:

1. Perform a level order traversal of the BST and add all nodes to a queue.
2. Keep dequeuing nodes from the queue until a null node is dequeued.
3. Check that there are no non-null nodes after a null node is dequeued. If there are, then the BST is not complete.
4. Continue dequeuing nodes until the queue is empty. If the queue is empty, then the BST is complete.

## Complexity
- Time complexity: O(n)

- Space complexity: O(n)

## Pseudocode
```
function is_complete_bst(root):
   
    queue.enqueue(root)
    isNullFound = false
    
    while queue is not empty:
        node = queue.dequeue()
        
        if node is null:
            isNullFound = true
        else:
            if isNullFound:
                return false
            
            queue.enqueue(node.left)
            queue.enqueue(node.right)
    
    return true
```

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/check-completeness-of-a-binary-tree/solutions/3300694/easy-solution-in-c-pseudocode-depending-on-queue/)

# Second Algorithm

## Intuition
A binary search tree (BST) has a parent node with two child nodes, and each level of parents has half the nodes of the next level (which are the children). To represent the BST in an array from the root to the leaves in a left-to-right order, we can calculate the indices of the child nodes based on their parent node. The index of a child node is equal to 2 times the index of its parent node, and since the starting index is 0, the index of the left child is 2 times the index of the parent plus 1, and the index of the right child is 2 times the index of the parent plus 2. This information is the starting point for our algorithm, which is called depth-first search.

## Approach
Based on the information about the indices of the nodes in the array representation of a BST, we can determine the number of nodes in the tree. We can then use this information to check if the index of a child node exceeds the array size, indicating that the BST is not complete. If the index is within the array size, we can continue recursively checking the left and right child nodes until the end of the tree is reached.

## Complexity
- Time complexity: O(n)

- Space complexity: O(n)

## Pseudocode
```
is_complete_BST(root)
    return checkCom(root, 0, countNodes(root))

countNodes(root)
    if root is null:
        return 0
    return 1 + countNodes(root.left) + countNodes(root.right)

checkCom(root, index, n)
    if root is null:
        return true
    if index >= n:
        return fasle
    return checkCom(root.left, index*2 +1, n) and checkCom(root.right, index*2+2, n)

```

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/check-completeness-of-a-binary-tree/solutions/3300839/easy-solution-without-queue-using-in-c-pseudocode/)
