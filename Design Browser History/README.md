# Question
You have a **browser** of one tab where you start on the `homepage` and you can visit another `url`, get back in the history number of `steps` or move forward in the history number of `steps`.

Implement the `BrowserHistory` class:

1- `BrowserHistory(string homepage)` Initializes the object with the homepage of the browser.
2- `void visit(string url)` Visits `url` from the current page. It clears up all the forward history.
3- `string back(int steps)` Move `steps` back in history. If you can only return `x` steps in the history and `steps > x`, you will return only `x` steps. Return the current `url` after moving back in history **at most** `steps`.
4- `string forward(int steps)` Move `steps` forward in history. If you can only forward `x` steps in the history and `steps > x`, you will forward only `x` steps. Return the current `url` after forwarding in history at most `steps`.

**Example 1:**<br/>
```
Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
```
**Constraints:**

- `1 <= homepage.length <= 20`
- `1 <= url.length <= 20`
- `1 <= steps <= 100`
- `homepage` and `url` consist of  '.' or lower case English letters.
- At most `5000` calls will be made to `visit`, `back`, and `forward`.

<h1 align="center">Solution</h1>


## Intuition
This code defines a `BrowserHistory` class that implements a doubly-linked list using the `Node` class. The `Node` class has three members - `value`, `prev`, and `next`. `value` stores the URL of a web page, while `prev` and `next` are pointers to the previous and next nodes in the linked list, respectively.

The `BrowserHistory` class has four member functions - `visit`, `back`, `forward`, and a private function `push`. The `visit` function adds a new node with the given URL to the end of the linked list using the `push` function. The `back` function moves the pointer to the previous node by the given number of `steps` and returns the URL of the node pointed to by the pointer. The `forward` function moves the pointer to the next node by the given number of `steps` and returns the URL of the node pointed to by the pointer.

The `push` function creates a new node with the given URL and adds it to the end of the linked list. If the linked list is empty, the new node becomes the root node, and the pointer is set to the root node. Otherwise, the new node is added as the next node after the current pointer, and the pointer is moved to the new node.

The `pop` function moves the pointer to the previous node and returns the URL of the new node pointed to by the pointer. It's used by the `back` function to move the pointer by the given number of `steps` and return the URL of the node pointed to by the pointer.

The `stepForward` function moves the pointer to the next node and returns the URL of the new node pointed to by the pointer. It's used by the `forward` function to move the pointer by the given number of `steps` and return the URL of the node pointed to by the pointer.

The `intializeBrowser` function initializes the root and pointer pointers to `nullptr`. It's used by the `BrowserHistory` constructor to set up the initial state of the linked list.

Overall, this implementation allows for efficient navigation through the user's browsing history by using a doubly-linked list to keep track of visited web pages.

## Approach
To impelement this Algorithm we need to:
1. Define a `Node` class with three members: `value (a string representing a URL)`, `prev (a pointer to the previous node)`, and `next (a pointer to the next node)`. This class will be used to implement a doubly-linked list.

2. Define a `BrowserHistory` class with a private member variable `root (a stack of Node pointers)` and a private member variable `pointer (a pointer to the current node)`.

3. Define a public constructor for the `BrowserHistory` class that takes a string representing the URL of the initial web page. In the constructor, create a new `Node` with the given URL and push it onto the stack. Set `pointer` to point to the new node.

4. Define a public `visit` function that takes a string representing a new URL to visit. In the function, create a new `Node` with the given URL and push it onto the stack. Set `pointer` to point to the new node.

5. Define a public `back` function that takes an integer representing the number of steps to go back in the browser history. In the function, pop the top node off the stack and set `pointer` to point to the new top node. Repeat this process for the given number of steps, or until there are no more nodes to go back to.

6. Define a public `forward` function that takes an integer representing the number of steps to go forward in the browser history. In the function, use the `next` pointers of the nodes in the stack to move `index` forward by the given number of steps, or until there are no more nodes to go forward to.

## Complexity
- Time complexity: 
    - O(1) => visit function
    - O(n) => back function, where n is the number of steps
    - O(n) => forward function, where n is the number of steps

- Space complexity:
    - O(n) => where n is the number of URLs visited

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/design-browser-history/solutions/3313236/easy-solution-with-explanation-adding-level-of-abstraction-to-be-clear-code/)