# Question
## 662. Maximum Width of Binary Tree
Given the `root` of a binary tree, return the **maximum width** of the given tree.

The **maximum width** of a tree is the maximum **width** among all levels.

The **width** of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a **32-bit** signed integer.<br/>

**Example 1:**<br/>
![image](https://assets.leetcode.com/uploads/2021/05/03/width1-tree.jpg)
```
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
```
**Example 2:**<br/>
![image](https://assets.leetcode.com/uploads/2022/03/14/maximum-width-of-binary-tree-v3.jpg)
```
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
```
**Example 3:**<br/>
![image](https://assets.leetcode.com/uploads/2021/05/03/width3-tree.jpg)
```
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 3000]`.
- `-100 <= Node.val <= 100`

*You can try to solve this problem from [here](https://leetcode.com/problems/maximum-width-of-binary-tree/description/)*

<h1 align="center">Solution</h1>

## Intuition
To find the maximum width of a binary tree, we need to check each level of the tree. We can do this using a breadth-first search (BFS) algorithm. BFS is an algorithm that visits all of the nodes in a tree one level at a time. This allows us to easily find the maximum width of the tree, which is the number of nodes on the level with the most nodes.

## Approach
1.	Initialize a queue `q` and push the root node into it.
2.	Initialize a variable `maxLength` to 1.
3.	While the queue is not empty:
    1. Get the size of the queue `size`.
    2. Get the front and back nodes of the queue `front` and `back`.
    3. Update `maxLength` to the maximum of `maxLength` and `back - front + 1`.
    4. For each node in the queue:
        - If the node has a left child, push it into the queue.
        - If the node has a right child, push it into the queue.
4.	Return `maxLength`.


## Complexity
- Time complexity:  O(N), where N is the number of nodes in the tree.

- Space complexity: O(H) = O(lg(N)), where H is the height of the tree.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/maximum-width-of-binary-tree/solutions/3438242/easy-solution-and-explanation-in-cpp/)
