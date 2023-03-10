# Intuition
At first, I thought we can mapping the values of each node of the linked list until it repeats but it will have a lot of constraints to achieve it until I found Floyd’s Cycle Finding Algorithm.

# What is Floyd’s Cycle Finding Algorithm?
It is a pointer algorithm that uses only two pointers, moving through the sequence at different speeds. This algorithm is used to find a loop in a linked list. It uses two pointers one moving twice as fast as the other one. The faster one is called the fast pointer and the other one is called the slow pointer.

![1.jpeg](https://assets.leetcode.com/users/images/c9b159a2-8bec-4129-a17b-9f2575cc13a7_1678413310.2222655.jpeg)
![2.jpeg](https://assets.leetcode.com/users/images/734c31af-0a21-4014-8fbb-b301a6986a81_1678413334.8628674.jpeg)

you can read more about the algo from [here](https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/)

# Approach
1. Define the two pointers (slow and fast) at the head of the LL.
2. Move the fast pointer by 2 steps and the slow pointer by 1 step.
3. If they don’t meet, simply the LL doesn’t have a loop.
4. If they meet, the LL has a loop. So from the point of meeting, we can reset the slow pointer to the head and then move each of them by one step until they meet. The new met point is the beginning of the loop which we seek for ;)
	(You can find the proof of that algorithm in the previous section)

# Pseudocode
```
DETECT-CYCLE(head)
	Slow = head
	Fast = head
	While Fast & Fast -> next
		Slow = Slow ->next
		Fast = Fast -> next -> next
		If Slow = Fast
            Slow = head
            While Slow ≠ Fast
                Slow = Slow -> next
                Fast = Fast -> next
            Return Slow OR Fast
	Return NULL
```

# Complexity
- Time complexity: O(n)

- Space complexity: O(1)

# Performance 

![Capture.PNG](https://assets.leetcode.com/users/images/bb52f9df-ae6e-43bd-bb52-f7642b8e9ec7_1678413850.063016.png)

# LeetCode Account
You can have a close look from my [LeetCode Account](https://leetcode.com/problems/linked-list-cycle-ii/solutions/3278325/easy-solution-with-algo-explanation-beats-99-38/)
