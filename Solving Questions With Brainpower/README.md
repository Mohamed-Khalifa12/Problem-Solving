# Question

## 71. Simplify Path

You are given a **0-indexed** 2D integer array `questions` where `questions[i] = [pointsi, brainpoweri]`.

The array describes the questions of an exam, where you have to process the questions **in order** (i.e., starting from question `0`) and make a decision whether to **solve** or **skip** each question. Solving question `i` will **earn** you `pointsi` points but you will be **unable** to solve each of the next `brainpoweri` questions. If you skip question `i`, you get to make the decision on the next question.

- For example, given `questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:`
    - If question `0` is solved, you will earn `3` points but you will be unable to solve questions `1` and `2`.
    - If instead, question `0` is skipped and question `1` is solved, you will earn `4` points but you will be unable to solve questions `2` and `3`.
Return *the **maximum** points you can earn for the exam.*<br/>

**Example 1:**<br/>
```
Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
```
**Example 2:**<br/>
```
Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.
```

**Constraints:**
- `1 <= questions.length <= 10^5`
- `questions[i].length == 2`
- `1 <= pointsi, brainpoweri <= 10^5`

*you can try to solve the problem from [here](https://leetcode.com/problems/solving-questions-with-brainpower/description/)*

<h1 align="center">Solution</h1>

## Intuition
There are two ways to solve this problem: top-down (recursion) and bottom-up (iteration). The goal is to choose whether to answer a question and skip the next few questions, or to skip the question and get the maximum of the two choices. We can figure out the 2 approaches.

## Approach
### Bottom-Up Appraoch
The idea is to use a dynamic programming array to store the maximum number of points that can be obtained up to each question. The array is initialized with the points for the first question. For each subsequent question, the array is updated by adding the points for the question and the maximum number of points that can be obtained by skipping the question and the next few questions. The maximum value in the array is then returned as the answer.

Here is a more detailed explanation of the approach:

1. Create a dynamic programming array to store the maximum number of points that can be obtained up to each question.
2. Initialize the array with the points for the first question.
3. For each subsequent question:
    - Update the array by adding the points for the question.
    - Calculate the maximum number of points that can be obtained by skipping the question and the next few questions.
    - Set the array value for the current question to the maximum of the two values.
4. Return the maximum value in the array.
```
FUNCTION mostPoints(questions: 2D vector of integers) -> long long
    n = questions.size()
    dp = array of long longs with n elements
    dp[n - 1] = questions[n - 1][0]

    FOR i = n - 2 DOWNTO 0
        dp[i] = questions[i][0]
        skipped = i + 1 + questions[i][1]
        IF skipped < n
            dp[i] += dp[skipped]
        dp[i] = max(dp[i], dp[i + 1])

    RETURN dp[0]
END FUNCTION

```

### Top-Down Approach
The idea is to use a memoization table to store the maximum number of points that can be obtained up to each question. The table is initialized with -1, which indicates that the value is not yet known. The function solve() is called recursively to calculate the maximum number of points for each question. The function works by first checking if the value is already known in the table. If it is, the value is returned. Otherwise, the value is calculated by adding the points for the question and the maximum number of points that can be obtained by skipping the question and the next few questions. The value is then stored in the table and returned.

Here is a more detailed explanation of the approach:

1. Create a memoization table to store the maximum number of points that can be obtained up to each question.
2. Initialize the table with -1, which indicates that the value is not yet known.
3. Create a recursive function `solve()` to calculate the maximum number of points for each question.
4. The function `solve()` works by first checking if the value is already known in the table.
5. If it is, the value is returned.
6. Otherwise, the value is calculated by adding the points for the question and the maximum number of points that can be obtained by skipping the question and the next few questions.
7. The value is then stored in the table and returned.
8. The function `mostPoints()` calls the function `solve()` to calculate the maximum number of points for the entire question set.


```
FUNCTION mostPoints(questions: 2D vector of integers) -> long long
    memo = array of long longs with size equal to number of questions, initialized to -1
    RETURN solve(questions, memo, 0)
END FUNCTION

FUNCTION solve(questions: 2D vector of integers, memo: array of long longs, i: integer) -> long long
    IF i >= questions.size()
        RETURN 0
    IF memo[i] != -1
        RETURN memo[i]
    memo[i] = max(questions[i][0] + solve(questions, memo, i + questions[i][1] + 1), solve(questions, memo, i + 1))
    RETURN memo[i]
END FUNCTION
```

## Complexity
- Time & Space complexity: O(n), where n is the size of `questions`.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/solving-questions-with-brainpower/solutions/3518963/easy-solution-in-cpp-with-explanation-and-pseudocode/)