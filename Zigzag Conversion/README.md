# Problem 
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

**Example 1**<br/>
Input: s = "PAYPALISHIRING", numRows = 3
```
P   A   H   N
A P L S I I G
Y   I   R
```
Output: "PAHNAPLSIIGYIR"

**Example 2**<br/>
Input: s = "PAYPALISHIRING", numRows = 4
```
P     I    N
A   L S  I G
Y A   H R
P     I
```
Output: "PINALSIGYAHRPI"

<h1 align="center">Solution</h1>

## Intuition
At first, I think that we can solve it as a series like adding x to the first element and so on.
but, it will be complex and need a lot of conditions.

## Approach
The Algorithm I use is:

1. Define a string array with a number of rows length.
2. Looping through each char in the string passed as an argument till the number of rows and add the char to the corresponding index (row) in the array.
3. Then looping from the end to the start (for the array) excluding the first and last element in the array to keep it in a zigzag form.
4. Keep executing steps 2 & 3 until I reached the end of the string.
5. Read the chars from the array of strings in order from index 0 to length and the string we get is the required

## Pseudo Code
```
CONVERT-TO-ZIGZAG( S , n )
	Let A[n], count
	While count ≠ length
		For i = 0 upto n
			If count < n 
				A[i] = S[count++]
			Else
				Break
		
		For i = n - 2 downto 1
			If count < n 
				A[i] = S[count++]
			Else
				Break
	
	For i = 0 upto n
		For j = 0 upto size(A[i])
			New_string += A[i][j]
	Return New_string 

``` 

## Complexity
- Time complexity: O(n)

- Space complexity: O(n)

## LeetCode Account

You can have a close look from [here - LeetCode](https://leetcode.com/problems/zigzag-conversion/solutions/3265093/solution-of-zigzag-problem-with-explanation/)
