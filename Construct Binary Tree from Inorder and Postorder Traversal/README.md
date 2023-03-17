# Question
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

**Example 1:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)
```
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
```
**Example 2:**<br/>
```
Input: inorder = [-1], postorder = [-1]
Output: [-1]
```

<h1 align="center">Solution</h1>

## Intuition
The algorithm for constructing a BST from inorder and postorder traversal arrays is based on the following observations:

1. In a postorder traversal of a BST, the last element is always the root of the tree.
2. In an inorder traversal of a BST, all the elements to the left of the root belong to the left subtree, and all the elements to the right of the root belong to the right subtree.

Using these observations, we can construct the BST as follows:

1. Identify the root of the BST by taking the last element of the postorder traversal array.
2. Find the position of the root in the inorder traversal array.
3. Recursively construct the left subtree of the root by using the left portion of the inorder traversal array and the corresponding portion of the postorder traversal array.
4. Recursively construct the right subtree of the root by using the right portion of the inorder traversal array and the corresponding portion of the postorder traversal array.

The intuition behind this algorithm is that we can use the inorder traversal array to determine the structure of the BST, and we can use the postorder traversal array to determine the root of each subtree. By recursively constructing subtrees using these arrays, we can build the entire BST.

## Approach
To construct a binary search tree (BST) from its inorder traversal array and postorder traversal array, you can use the following recursive algorithm:

1. The last element in the postorder traversal array is always the root of the BST.
2. Search for the position of the root element in the inorder traversal array.
3. All the elements to the left of the root element in the inorder traversal array will be in the left subtree of the root, and all the elements to the right of the root element in the inorder traversal array will be in the right subtree of the root.
4. Recursively construct the left subtree of the root using the left portion of the inorder traversal array and the corresponding portion of the postorder traversal array.
5. Recursively construct the right subtree of the root using the right portion of the inorder traversal array and the corresponding portion of the postorder traversal array.

## Complexity
- Time complexity: O(n)

- Space complexity: O(n)

## Pseudocode
```
function buildTree(inorder, postorder)
    //depending on un_ordered mapped to improve the time complexity
    create map mp;
        for i = 0 upto inorder size:
            mp[inorder[i]] = i;
        return buildTreeHelper(mp, postorder, postorder.size() -1, 0, inorder.size() - 1);

function buildTreeHelper(mp, postorder, postIndex, start, end)
    if start > end:
        return null
    // to get the index in order vector corresponding to the value in the postorder
    //that's wht one of the constraints that each value is unique
    inorderIndex = mp[postorder[postIndex]]
    tree = TreeNode(postorder[postIndex])
    //indicate to the next root
    postIndex--

    //start from the right side as from the left to the right in postorder is the right root  
    tree.right = buildTreeHelper(mp, postorder, postIndex, inorderIndex + 1, end)
    tree.left = buildTreeHelper(mp, postorder, postIndex, start, inorderIndex - 1)
```
## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solutions/3305736/easy-solution-with-explanation-using-pseudocode/)
