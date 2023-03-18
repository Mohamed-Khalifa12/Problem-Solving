# Question
A trie (pronounced as "try") or **prefix** tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

- `Trie()` Initializes the trie object.
- `void insert(String word)` Inserts the string `word` into the trie.
- `boolean search(String word)` Returns `true` if the string `word` is in the trie (i.e., was inserted before), and `false` otherwise.
- `boolean startsWith(String prefix)` Returns `true` if there is a previously inserted string `word` that has the prefix prefix, and `false` otherwise.

**Example 1:**<br/>
```
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
```
**Constraints:**

- `1 <= word.length, prefix.length <= 2000`
- `word` and `prefix` consist only of lowercase English letters.
- At most `3 * 10^4` calls **in total** will be made to `insert`, `search`, and `startsWith`.

<h1 align="center">Solution</h1>

## Intuition
In order to use the Trie-Prefix Tree data structure, we rely on the concept of `Binary Search Trees (BST)` to store the data within it. This allows us to insert and search for data in `O(lgn)` time complexity.

To achieve this, we first define a node class to represent the elements of the tree. Next, we construct the BST by inserting the data in alphabetical order. Finally, we can access the data in a traversal manner to retrieve a specific element.

## Approach
This code defines a Trie data structure with insert, search, and startsWith operations. Here's a detailed explanation of the approach:

- The `Node` class represents a node in the Trie. Each node has a value (a string), a left child pointer, and a right child pointer. The `left` and `right` pointers are used to store the children of a node.
- The `Trie` class represents the Trie data structure. It has a private member `root`, which is a pointer to the root node of the Trie. The `root` pointer is initialized to `nullptr` in the constructor.
- The `insert` function inserts a new string into the Trie. It first checks if the Trie is empty (i.e., `root` is `nullptr`). If it is empty, it creates a new `Node` with the given string and sets it as the root node. If the Trie is not empty, it traverses the Trie from the root node and compares each node's value with the given string. If the given string is less than the node's value, it goes to the left child. Otherwise, it goes to the right child. It continues until it finds a node with no child in the appropriate direction and then creates a new `Node` with the given string and sets it as that child.
- The `search` function searches for a string in the Trie. It starts at the root node and compares each node's value with the given string. If the string is less than the node's value, it goes to the left child. If the string is greater than the node's value, it goes to the right child. It continues until it finds a node with the given string as its value or reaches a leaf node with no child in the appropriate direction.
- The `startsWith` function checks if any string in the Trie starts with a given prefix. It starts at the root node and checks if the prefix is a prefix of the node's value. If it is, it returns true. If the prefix is less than the node's value, it goes to the left child. If the prefix is greater than the node's value, it goes to the right child. It continues until it finds a node that does not have the prefix as a prefix or reaches a leaf node with no child in the appropriate direction.
- The `is_string_less` function is a helper function that compares two strings and returns true if the first string is less than the second string in lexicographic order.
- The `search_recrusion` function is a recursive helper function for the `search` function. It takes a node and a string as arguments and searches for the string in the subtree rooted at the node.
- The `startsWith_recrusion` function is a recursive helper function for the `startsWith` function. It takes a node and a string as arguments and checks if any string in the subtree rooted at the node starts with the given prefix.
- The `is_part` function is a helper function that checks if the first string is a prefix of the second string. It does this by taking a substring of the second string that has the same length as the first string and comparing it with the first string.

Overall, this code provides a simple implementation of a Trie data structure that can be used for fast prefix matching and searching of strings.

## Complexity
- Time complexity:  For the `insert` function `O(h)`, where h is the height of the trie, but for `search` and `startsWith` is `O(n)`, where n is the length of the input string.

- Space complexity: `O(n)`, where n is the total number of characters in all the strings.

## Pseudocode
```
class Node
{
    // define node class for Trie
}

class Trie {
private:
    Node *root;

    // define helper functions for search and insertion

public:
    Trie() {
        // initialize root node to nullptr
    }
    
    void insert(string word) {
        // insert a new word into the Trie
    }
    
    bool search(string word) {
        // search for a word in the Trie
    }
    
    bool startsWith(string prefix) {
        // check if the Trie contains a word with the given prefix
    }
};

```

# LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/implement-trie-prefix-tree/solutions/3309347/easy-solution-using-bst-with-explanation/)