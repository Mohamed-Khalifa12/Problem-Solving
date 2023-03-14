# Question
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

- For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.<br/>

Return the total sum of all root-to-leaf numbers.

**Example 1:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2021/02/19/num1tree.jpg)
```
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
```
**Example 2:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2021/02/19/num2tree.jpg)
```
Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
```

<h1 align="center">Solution</h1>

# First Algorithm

## Intuition
To find the sum of every branch in a Binary Search Tree (BST), we can traverse each branch recursively and append the value of each node as a character to a string variable. Starting from the root node, we move on to each child node and continue the process until we reach a leaf node. After collecting the values of each branch as a string, we convert the string into an integer and add it to the sum variable. By repeating this procedure for each branch of the BST, we can obtain the total sum of every branch from the root to the leaf.

## Approach
At the beginning of the program, we define a sum variable that initially holds the sum of each branch from the root to the leaf as 0. We also create a string (str) that initially contains the values from the root to the leaf as an empty string ("").

We create a helper function called "summer", which accepts the root node of the tree, the string (str) containing the values from the root to the leaf, and the address of the sum variable.

If the root node is null, we exit the function, and this is one of the two base cases. If the root node is not null, we add the value of the root to the string (str) and check if it is the last element of the tree or not by checking if the left and right children are null. If it is the last element, we calculate the sum up to now, which is the conversion of the string to an integer, and then exit the function. This is the second base case.

We then repeat this process sequentially for the left and right branches of the tree until we reach the end of each branch. Finally, we return the sum variable.

## Complexity
- Time complexity: O(n)

- Space complexity: O(h)

## Pseudocode
```
// Main program
function sumNumbers(root)
    sum = 0, str = ""
    summer(root, str, sum)  // Call the helper function
    return sum

function summer(node, str, sum):
    if node is null:
        return
    str += string(node.value)   // Add node value to str
    if node.left is null and node.right is null:  // Check if leaf node
        sum += int(str)   // Convert str to int and add to sum
    summer(node.left, str, sum)   // Recursively process left subtree
    summer(node.right, str, sum)  // Recursively process right subtree

```
# LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/sum-root-to-leaf-numbers/solutions/3296939/easy-solution-with-strings-in-c-pseudocode/)

# Second Algorithm

## Intuition
By closely examining any branch in a binary tree, we can derive its corresponding number without explicitly constructing a string representation. For instance, if we consider the branch from the root to a leaf node, say, 4->9->5, whose string representation is "495", we can obtain its numerical value by calculating the sum (400 + 90 + 5) or by performing the mathematical expression ((4 * 10 + 9) * 10 + 5). This reveals a pattern of constructing numbers, which is to multiply the parent node's value by 10 and then add the current node's value. We can apply this pattern recursively from the root to a leaf node to compute the sum of all root-to-leaf numbers.
This Algorithm is called recursive Depth-First Search (DFS) traversal of the binary tree.

## Approach
In this algorithm, we utilize a helper function known as "summer," which takes the tree's root and the calculated pattern value from the previous node as inputs.

To exit the recursive function, we check if the root is null, and if so, we return 0 as the initial base case. If the root is not null, we apply the pattern by calculating the sum of depth (sumDepth = sumDepth * 10 + root.value). Afterward, we check if the current node is the last element of the tree. If it is, we return the sumDepth. Otherwise, we recursively repeat the same process for both the left and right nodes, summing the output from each recursion and then returning the final output.

## Complexity
- Time complexity: O(n)

- Space complexity: O(h)

## Pseudocode
```
function sumNumbers(root)
    return summer(root, 0)

function summer(root, pattern):
    if root is null:
        return 0
    
    pattern = pattern * 10 + root.value
    
    if root has no left or right child:
        return pattern
    
    return summer(root.left, pattern) + summer(root.right, pattern)

```
# LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/sum-root-to-leaf-numbers/solutions/3297102/easy-solution-without-strings-with-c-pseudocode/)


