# Question

## 71. Simplify Path

Given a string `path`, which is an **absolute path** (starting with a slash `'/'`) to a file or directory in a Unix-style file system, convert it to the simplified **canonical path**.

In a Unix-style file system, a period `'.'` refers to the current directory, a double period `'..'` refers to the directory up a level, and any multiple consecutive slashes (i.e. `'//'`) are treated as a single slash `'/'`. For this problem, any other format of periods such as `'...'` are treated as file/directory names.

The **canonical path** should have the following format:

- The path starts with a single slash `'/'`.
- Any two directories are separated by a single slash `'/'`.
- The path does not end with a trailing `'/'`.
- The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period `'.'` or double period `'..'`)
Return *the simplified **canonical path.***<br/>

**Example 1:**<br/>
```
Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
```
**Example 2:**<br/>
```
Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
```

**Example 3:**<br/>
```
Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
```

**Constraints:**
- `1 <= path.length <= 3000`
- `path` consists of English letters, digits, period `'.'`, slash `'/'` or `'_'`.
- `path` is a valid absolute Unix path.

*you can try to solve the problem from [here](https://leetcode.com/problems/simplify-path/description/)*

<h1 align="center">Solution</h1>

![Screenshot 2023-04-12 092059.png](https://assets.leetcode.com/users/images/e1c538e5-beef-46f0-8edc-36dfc244ffdc_1681284724.4251435.png)

## Intuition
This problem involves dividing a string into an array of substrings using the delimiter `'/'`, which can be achieved by using the splitString function. Once the substrings have been generated, they can be pushed onto a stack. As we iterate through the substrings, if we encounter the sequence `'..'`, we can remove the top element from the stack. Finally, we can format the contents of the stack to meet the specified requirements.

## Approach
1. Split the input string path by the slash character `'/'` and store the components in an array. 
2. Create an empty stack. 
3. For each component in the array: 
    1. If the component is an empty string or `'.'`, ignore it. 
    2. If the component is `'..'`, pop the top element off the stack (if it exists). 
    3. Otherwise, push the component onto the stack. 
4. Create an empty string. 
5. While the stack is not empty, pop the top element off the stack and prepend it to the output string, separated by a slash `'/'`. 
6. If the output string is empty, return `'/'`. 
7. Otherwise, return the output string. 

## Complexity
- Time & Space complexity: O(n), where n is the length of the input string `path`.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/simplify-path/solutions/3407928/easy-stack-based-solution/)
