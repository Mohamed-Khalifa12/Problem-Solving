# Question

## 881. Boats to Save People

You are given an array `people` where `people[i]` is the weight of the `ith` person, and an **infinite number of boats** where each boat can carry a maximum weight of `limit`. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most `limit`.

Return *the minimum number of boats to carry every given person.*<br/>
**Example 1:**<br/>
```
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
```
**Example 2:**<br/>
```
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
```
**Example 3:**<br/>
```
Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
```

**Constraints:**
- `1 <= people.length <= 5 * 104`
- `1 <= people[i] <= limit <= 3 * 104`

<h1 align="center">Solution</h1>

## Intuition
We can arrange the people in ascending order and establish two pointers: one at the beginning representing the smallest element and another at the end representing the largest element. When the sum of these two elements exceeds the limit, we will only take the larger element and move the end pointer one step back. This will count as one boat journey. On the other hand, if the sum does not exceed the limit, we will move both pointers towards each other, increase the number of boats by one until the start pointer surpasses the end pointer.

## Approach
1. The first step is to sort the vector in ascending order using the standard library's sort function. This ensures that the heavier people are placed towards the end of the vector, making it easier to pair them up later.

2. Two pointers are then established, one pointing to the beginning of the vector (i.e., the lightest person), and another to the end of the vector (i.e., the heaviest person). A counter is also initialized to zero to keep track of the number of boats required.

3. A while loop is then initiated, with the condition that the start pointer is less than or equal to the end pointer. This loop continues until all people have been accounted for.

4. Inside the loop, an if statement checks whether the sum of the weights of the people pointed to by the start and end pointers is less than or equal to the weight limit of the boat. If the sum is less than or equal to the limit, both the start pointer and the end pointer remain in their respective positions, indicating that the two people can be transported in the same boat. The start pointer is then incremented by one, and the end pointer is decremented by one to indicate that these two people have been paired and accounted for.

5. In the case where the sum of weights is greater than the limit, only the heaviest person (i.e., the person pointed to by the end pointer) can be transported in the boat. Therefore, the end pointer is moved one step towards the beginning of the vector, indicating that this person has been transported. The start pointer remains in place.

6. In both cases, the counter is incremented to indicate that a boat has been used.

7. After the loop completes, the value of the counter is returned, representing the minimum number of boats required to rescue all the people.

## Complexity
- Time complexity: O(n), where n is the number of people. (without sort algorithm).

- Space complexity: O(1)

