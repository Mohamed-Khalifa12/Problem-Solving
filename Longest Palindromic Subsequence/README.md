# Question
## 516. Longest Palindromic Subsequence
Given a string `s`, find the longest palindromic **subsequence**'s length in `s`.

A **subsequence** is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.<br/>

**Example 1:**<br/>
```
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
```
**Example 2:**<br/>
```
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
```

**Constraints:**
- `1 <= s.length <= 1000`
- `s` consists only of lowercase English letters.


*You can try to solve this problem from [here](https://leetcode.com/problems/longest-palindromic-subsequence/description/)*

## Intuition
This algorithm can be solved in two ways. The first way is to use a top-down approach, which involves breaking the problem down into smaller subproblems and solving them recursively. The second way is to use a bottom-up approach, which involves solving the subproblems iteratively and then combining the solutions to find the solution to the original problem.

## Bottom-Top Approach [iteration]
let's consider: `"bbbab"`
```
       b  b  b  a  b             b  b  b  a  b        
    b  0  0  0  0  0          b  0  0  0  0  0          
    b  0  0  0  0  0     ==>  b  0  0  0  0  0            
    b  0  0  0  0  0          b  0  0  0  0  0          
    a  0  0  0  0  0          a  0  0  0  1  0            
    b  0  0  0  0  0          b  0  0  0  0  1 

       b  b  b  a  b             b  b  b  a  b        
    b  0  0  0  0  0          b  0  0  0  0  0          
    b  0  0  0  0  0     <==  b  0  0  0  0  0            
    b  0  0  1  1  3          b  0  0  0  0  0          
    a  0  0  0  1  1          a  0  0  0  1  1            
    b  0  0  0  0  1          b  0  0  0  0  1  

       b  b  b  a  b             b  b  b  a  b        
    b  0  0  0  0  0          b  1  2  3  3  4 -> is the output          
    b  0  1  2  2  3     ==>  b  0  1  2  2  3            
    b  0  0  1  1  3          b  0  0  1  1  3          
    a  0  0  0  1  1          a  0  0  0  1  1            
    b  0  0  0  0  1          b  0  0  0  0  1              

```
**At first we need to know the subsequence and palindrome:**
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

A palindrome is a string that reads the same forwards and backwards.

To find the longest palindrome subsequence in the string "bbbab", we can use a dynamic programming approach.

1. We create a 2D array of size n x n, where n is the length of the string "bbbab". We initialize the diagonal of the array with 1, because a string of length 1 is always a palindrome.

2. Then, we iterate over the array diagonally, starting from the second diagonal, and filling the entries based on the following logic:

    - If the two characters at the current indices are the same, we add 2 to the value of the entry diagonally down and to the right (i.e., i+1, j-1), because we have found two more characters that form a palindrome.
    - If the two characters are different, we take the maximum value of the entry to the right (i.e., i, j-1) and the entry diagonally down (i+1, j), because we need to find the longest palindrome subsequence in the remaining substrings.
3. After filling the entire array, the value in the top right corner of the array will be the length of the longest palindrome subsequence in the string. In this case, the value is 4, which means that the longest palindrome subsequence has length 4.

## Top-Bottom Approach [Recursion]
The algorithm starts at the beginning of the string and compares the first and last characters. If they are equal, they are removed and we found the first 2 elements (add them to the rest) and the algorithm is applied to the remaining string. If the first and last characters are not equal, the algorithm finds the longest palindrome that starts at the beginning of the string and ends at the element before the last one. It then finds the longest palindrome that starts at the second character of the string and ends at the end of the string. The algorithm returns the maximum length of the two palindromes. as shown in the figure below:
![Screenshot 2023-04-12 092059.png](https://leetcode.com/problems/longest-palindromic-subsequence/Figures/516/516-1.png )

let's consider "bbbab":
```
                     |   |      | |  
                    "bbbab" -> "bba"   
                    we got      /\     
                    the first  /  \    
                    2 ele    "bb" "ba" 

                      ||         |    ||
                 |   "bb" -> ""  |   "ba"   |                   
                 |  we have      |    / \   |                   
                 |  another 2    |  'b' 'a' |
                 |  (4 till now) |   3 here |
                                       |
                                   'b' | 'a'
                                 1 ele |  1 ele           

/*
1. at first we check the first and last element to find if they are
    equal or not. but they are equal 'b' & 'b' so they are first 2 
    subsequence (imagine we remove between them [property of subseq]
    we find "bb" which is palindrome. so our misson to find out 
    the rest) we have 2 till now :D
2. remove them and check the rest "bba".
3. oops they aren't equal. so surly the required subsequence will 
    be from the first of new string till the end - 1 OR it will
    be from the second char till the end. we check both and get
    the max.
4. as we see we have both "bb" (from the first till the end - 1)
    and "ba" (from the second till the end). we will get the max 
    between them.
5. "bb" the first and the last elemnt is equal 'b' = 'b' so we will
    remove them and add 2 to the result
6. on the other hand we have "ba" which are not equal so we will get
    the max between them which will be one for both.
7. so at "bba" we will find the max between (2 "bb" and 1 "ba") so 
    this substring will return 2.
8. we have at the original string "bbbab" [2 from the first and the
    last element] and [2 from substring "bba"] point #6
9. the result will be 4
*/
```

## Complexity
- Time complexity: O(n^2), where n is the length of the string.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/longest-palindromic-subsequence/solutions/3416574/a-visual-guide-to-the-longest-palindromic-subsequence-problem-down-top-and-top-down-approaches/)