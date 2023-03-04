# Intuition
At first, I thought I could merge the 2 sorted arrays into one larger array and get the middle of the new array, which is the median.<br />
BUT: this algorithm needs more time O(n+m) at least and more memory.

# Approach
So the solution steps:
1. Imagine an array its size = sum of the size of the 2 arrays.
2. Surly the median will be in the middle of the new array (1 or 2 elements depending on whether it’s even or odd).
3. So we gonna find the 1 or 2 elements directly without caring about the first and last elements in that array.
4. Get the number on each side of the new array [(size of 1st array + size of 2nd array + 1)/2] (let it be => side).
5. We then get some elements from the 1st and 2nd array but under one condition the sum of the 2 parts equal the side of the larger array.
6. So we have chosen to get from the 1st array half of it (let it be =>m) and get the rest from the 2nd array (let it be => n). The condition must be achieved (n + m = side).
7. Here we finished our Algorithm as we get 2 indices from the 2 arrays so it’s time to check if they are the true elements or not. [Note: The indices m, n are in the middle of each array if they are the true elements so all the elements before m in the 1st array and before n in the 2nd array must be less than or equal to the element in the m and n indices in order]. So we gonna check:
    1. If the element in (m) place is larger than the element in (n - 1) place so it will be okay and the first test passed 🎉
    2. And if the element in (n) place is larger than the element in (m -1) place so it is okay again and the second test passed also 🎉
    3. Then it is time to get the median ⇒
        * If the size of the 2 arrays is an even number so we have 2 elements in the middle. And you will find the m and n elements are the first 2 elements on the right side of the larger array so we want to get the minimum of them to be the first element in the middle 👏.  And we will find that the element just before m in the 1st array and the element just before n in the 2nd array are the last elements on the left side of the larger array so we want to get the maximum of them to be the second element in the middle 🎉. Simply add them together and divide by 2 to get the median.
        * But what if the size is odd it is a simple condition as you need only to get the max of the 2 elements which is before m and n.
    4. But what if one of the a or b conditions is false so we have to change the places of m and n in the 2 arrays and do these steps again until it is achieved?
    5. And to achieve O(lg(m)) we can’t change m linearly by adding or subtracting 1 from it. So m will be the middle element of the 2nd half or the 1st half of the 1st array depending on your need to make it larger or smaller. 
    6. Doing d and e steps until it fits the condition of a and b then do c ;)

# Critical Questions
1. Why do we start with the smaller array, not the larger one?<br />
    To minimize the probability of a missing element while getting the middle of 1st array.
	Not looping more times in the larger array will increase execution time, which causes better performance.
2. What if the element of m or n get out of the range of the array or the elements just before them  = -1?<br />
So we make the element in index -1 = -inf (smallest number in the int range) and make the element in the L (the length of the array) =  inf (the largest number in the int range).

# Complexity
- Time complexity: O(lgn)

# LeetCode Account
You can have a look to the problem & solution from [here - LeetCode account](https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/3256807/easy-recursion-solution-with-explanation/)
