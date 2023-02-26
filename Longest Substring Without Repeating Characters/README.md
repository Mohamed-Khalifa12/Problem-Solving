**Intuition**
At first I guss it would be solved nested loops but it needs more time, Memory and effort to execute it.

**Approach**
With the map (Dictonary) Data Structue make it easy as it could save the char I loop throgh and the number of chars in it so it make it easy to solve that problem.

**Complexity**
Time complexity: O(n)

**Explanation**
  *we need a left and right pointers to indicate the first and last element in the substring we will loop through. So we define a left and right int as well as length (which will count the number of chars in substring) and maxLength (which save the maxLength of substring we reach to).
  *we depends also on map (dictionay) Data Structure which save data in pairs (here the char and the number of the chars in the substring).
  *At first we fixed the left pointer at 0 and move the right pointer until the number of last chars the right pointer points to exceed 1 char.each iteration we increase the length of the substring by one as the left pointer is fixed and add the new char in the map.
  *when the number of chars exceed 1 then we start to move the right pointer untill the number of chars of char that right pointer points to less than 1 and continue till the end. each iteration of that loop decrease the length of substring by one as we move the right pointer and the left is fixed.
  *At the end we return the maxLength.
  *This Algo is Called sliding window

You can have a look of the solution in [here](https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/3232912/explanation-of-the-algo/)
