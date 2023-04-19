# Question
## 1372. Longest ZigZag Path in a Binary Tree
You are given the `root` of a binary tree.

A ZigZag path for a binary tree is defined as follow:

- Choose **any** node in the binary tree and a direction (right or left).
- If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
- Change the direction from right to left or from left to right.
- Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return *the longest **ZigZag** path contained in that tree.*<br/>

**Example 1:**<br/>
![Alt](https://assets.leetcode.com/uploads/2020/01/22/sample_1_1702.png)
```
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
```
**Example 2:**<br/>
![Alt](https://assets.leetcode.com/uploads/2020/01/22/sample_2_1702.png)
```
Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
```

**Example 3:**<br/>
```
Input: root = [1]
Output: 0
```

**Constraints:**
- The number of nodes in the tree is in the range `[1, 5 * 10^4]`.
- `1 <= Node.val <= 100`

*You can try to solve this problem from [here](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/)*

<h1 align="center">Solution</h1>


## Intuition
The solution works by recursively traversing the tree in a depth-first manner and keeping track of the maximum length of zigzag path.

![1372-1.png](https://assets.leetcode.com/users/images/5f747732-ce05-485a-bb13-abc75529fc51_1681911445.7256358.png)


## Approach
1. Define a function that takes the root of a binary tree as an argument and returns the length of the longest zigzag path in the tree.
2. Initialize maxLength to 0.
3. Define a helper function that takes the current node, the direction of the previous node (0 for left, 1 for right), and the length of the zigzag path seen so far.
4. If the current node is null, return.
5. If the length of the zigzag path seen so far is greater than maxLength, update maxLength.
6. Recursively call the helper function on the left child of the current node with the opposite direction of the previous node (0 for right, 1 for left), and increment the length of the zigzag path seen so far if the previous direction was right.
7. Recursively call the helper function on the right child of the current node with the opposite direction of the previous node (1 for left, 0 for right), and increment the length of the zigzag path seen so far if the previous direction was left.
8. Return maxLength.

## Complexity
- Time complexity: O(n), where n is the number of nodes in the binary tree.

- Space complexity: O(log(n)), where n is the number of nodes in the binary tree.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/solutions/3434973/easy-solution-and-explanation-in-cpp/)