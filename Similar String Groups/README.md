# Question

## 839. Similar String Groups

Two strings `X` and `Y` are similar if we can swap two letters (in different positions) of `X`, so that it equals `Y`. Also two strings `X` and `Y` are similar if they are equal.

For example, `"tars"` and `"rats"` are similar (swapping at positions `0` and `2`), and `"rats"` and `"arts"` are similar, but `"star"` is not similar to `"tars"`, `"rats"`, or `"arts"`.

Together, these form two connected groups by similarity: `{"tars", "rats", "arts"}` and `{"star"}`.  Notice that `"tars"` and `"arts"` are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list `strs` of strings where every string in `strs` is an anagram of every other string in `strs`. How many groups are there?<br/>

**Example 1:**<br/>
```
Input: strs = ["tars","rats","arts","star"]
Output: 2
```
**Example 2:**<br/>
```
Input: strs = ["omv","ovm"]
Output: 1
```

**Constraints:**
- `1 <= strs.length <= 300`
- `1 <= strs[i].length <= 300`
- `strs[i]` consists of lowercase letters only.
- All words in `strs` have the same length and are anagrams of each other.

*you can try to solve the problem from [here](https://leetcode.com/problems/similar-string-groups/description/)*

<h1 align="center">Solution</h1>

## Intuition
The first step in this problem is to check the similarity between two strings. This is a straightforward task. We can iterate through the two strings, counting the number of changes that are allowed. If the number of changes is 0 or 2, then the strings are similar. Otherwise, the strings are not similar.

The goal of this task is to group similar strings together. We can do this by creating a graph, where each node represents the index of a string, and two nodes are connected if the strings are similar. At the end, we can count the number of groups of strings that have been created.

## Approach

#### function isSimillar(str1, str2)
**Count the number of changes between the two strings.**
```
count = 0
for i = 0 upto size(str1)
    if str1[i] != str2[i]
        count += 1
Return True if the number of changes is 0 or 2, False otherwise.
```
#### function numSimilarGroups(1D Array of strings)
**Create a graph, where each node represents a string, and two nodes are connected if the strings are similar.**
```
n = size(strs)
Define 2D Array adj
for i = 0 upto n - 1
    for j = i + 1 upto n
        if isSimilar(strs[i], strs[j])
            adj[i].add(j)
            adj[j].add(i)
```

**Visit the graph elements and count the number of groups.**
```
Define 1D Array visited
count = 0
for i = 0 upto n
    if i not in visited
    dfs(adj, visited, i)
    count += 1
return count
```

#### function dfs(adj, visited, node):

**Mark the node as visited.**
`visited[node] = True`

**Visit all of the node's neighbours that have not been visited yet.**
```
for neighbour in adj[node]
    if neighbour not in visited:
        dfs(adj, visited, neighbour)
```
## Complexity
- Time complexity: The time complexity of the code is O(n^2 . m), where n is the number of strings and m is the length od the string.

- Space complexity: O(n), where n is the number of strings.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/similar-string-groups/solutions/3463668/easy-explanation-with-pseudocode/)
