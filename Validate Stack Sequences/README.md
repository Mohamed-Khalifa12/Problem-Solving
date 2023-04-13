# Question
## 946. Validate Stack Sequences
Given two integer arrays `pushed` and `popped` each with distinct values, return `true` *if this could have been the result of a sequence of push and pop operations on an initially empty stack, or `false` otherwise.*

**Example 1:**<br/>
```
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
```
**Example 2:**<br/>
```
Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
```

**Constraints:**

- `1 <= pushed.length <= 1000`
- `0 <= pushed[i] <= 1000`
- All the elements of `pushed` are **unique**.
- `popped.length == pushed.length`
- `popped` is a permutation of `pushed`.

*You can try to solve this problem from [here](https://leetcode.com/problems/validate-stack-sequences/)*

<h1 align="center">Solution</h1>

# Two pointers Method

## Intuition
In this particular algorithm, the procedure involves adding an element to a stack and subsequently verifying if the element can be removed from the stack. This is determined by checking whether the topmost element in the stack matches the element in the popped array.

## Approach
1. Initialize two index variables i and j to 0, representing the next elements to be added to the stack and the next element to be matched with the popped array, respectively.
2. Create an empty stack to hold the pushed elements.
3. Push the first element from the pushed array onto the stack.
4. While there are still elements in the popped array to be matched:
    1. If the top element of the stack matches the current element of the popped array, pop the element from the stack and increment j.
    2. Otherwise, if there are still elements in the pushed array that have not been added to the stack, push the next element onto the stack and increment i.
    3. If neither of the above conditions is true, then the popped array cannot be obtained by pushing and popping elements from the stack in the correct order, so return false.
5. If all elements in the popped array have been matched and popped from the stack, then return true.

## Complexity
- Time & Space complexity: O(n), where n is the length of the pushed 

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/validate-stack-sequences/solutions/3412207/easy-one-pointer-method-d/)

<hr/>

# One pointer

## Intuition
In this particular algorithm, the procedure involves adding an element to a stack and subsequently verifying if the element can be removed from the stack. This is determined by checking whether the topmost element in the stack matches the element in the popped array.

## Approach
1. Create an empty stack and a variable to keep track of the current position in the popped array.
2. Iterate through each element of the pushed array and add it to the stack.
3. For each element added to the stack, check if it matches the current element in the popped array. If it does, pop the element from the stack and increment the position in the popped array.
4. After all elements in the pushed array have been added to the stack, if the stack is empty, return true (which indicates that the popped array can be obtained by pushing and popping elements from the stack in the correct order). Otherwise, return false.

## Complexity
- Time & Space complexity: O(n), where n is the length of the pushed array.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/validate-stack-sequences/solutions/3412210/easy-two-pointer-method-in-cpp-with-explanation-d/)


