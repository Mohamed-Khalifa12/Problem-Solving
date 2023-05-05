# Question

## 1456. Maximum Number of Vowels in a Substring of Given Length
Given a string `s` and an integer `k`, return *the maximum number of vowel letters in any substring of `s` with length `k`*.

**Vowel letters** in English are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.<br/>

**Example 1:**<br/>
```
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
```
**Example 2:**<br/>
```
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
```

**Example 3:**<br/>
```
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
```

**Constraints:**
- `1 <= s.length <= 10^5`
- `s` consists of lowercase English letters.
- `1 <= k <= s.length`

*You can try to solve this problem from [here](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/)*

<h1 align="center">Solution</h1>

## Intuition
In this particular issue, we will utilize a window slider approach (using 2 pointers) to examine the highest count of vowels within a specified length of k.

## Approach

1. Initialize the variables L (length of input string s), vLength (count of vowels in the first window of length k), and maxLength (maximum count of vowels seen so far).

2. Iterate over the first window of length k in s and count the number of vowels in it.

3. If the count of vowels in the first window is greater than or equal to k, return k, as we cannot have more than k vowels in a substring of length k.

4. Initialize two pointers, start and end, to the beginning and end of the first window, respectively. Iterate over the remaining substrings of length k in s using these pointers.

5. For each substring, move the start pointer forward by 1 and the end pointer forward by 1. If the character at the start pointer is a vowel, decrement vLength, and if the character at the end pointer is a vowel, increment vLength.

6. Update maxLength to be the maximum of maxLength and vLength.

7. If maxLength is greater than or equal to k, return k.

8. If all substrings of length k have been checked and maxLength is still less than k, return maxLength as the maximum count of vowels in any substring of length k.

```
function maxVowels(string s, int k) {
    L = length of s
    vLength = 0
    maxLength = 0

    for i from 0 to k-1 {
        if isVowel(s[i]) {
            vLength++
        }
    }

    maxLength = max(maxLength, vLength)
    if maxLength >= k {
        return k
    }

    start = 0
    end = k - 1
    for i from end to L-1 {
        if isVowel(s[start]) {
            vLength--
        }
        if isVowel(s[end+1]) {
            vLength++
        }
        start++
        end++
        maxLength = max(maxLength, vLength)
        if maxLength >= k {
            return k
        }
    }

    return maxLength
}

function isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
}

```

## Complexity
- Time complexity: O(n), where n is the size of string `s`

- Space complexity:  O(1), as it uses a constant amount of additional space to store variables and does not depend on the size of the input.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/solutions/3487138/easy-explanation-and-pseudocode/)