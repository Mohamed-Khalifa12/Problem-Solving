# Question

## 1491. Average Salary Excluding the Minimum and Maximum Salary

You are given an array of **unique** integers `salary` where `salary[i]` is the salary of the `ith` employee.

Return *the average salary of employees excluding the minimum and maximum salary*. Answers within `10^-5` of the actual answer will be accepted.<br/>

**Example 1:**<br/>
```
Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500

```
**Example 2:**<br/>
```
Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
```

**Constraints:**
- `3 <= salary.length <= 100`
- `1000 <= salary[i] <= 106`
- All the integers of `salary` are **unique**.

*you can try to solve the problem from [here](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/)*

<h1 align="center">Solution</h1>

## Intuition
In this problem, we can sort the vector with ease and then traverse it starting from the second element up to the element immediately preceding the last one.

## Approach
**Function:** average(vector<int>& salary)

**Input:** A vector of integers representing salaries.

**Output:** The average salary.

**Steps:**

1. Sort the vector of salaries in ascending order.
2. Calculate the sum of all the salaries except the first and last one.
3. Divide the sum by the number of salaries minus 2.
4. Return the result.

## Complexity
- Time complexity: O(nlogn), where n is the size of the vector.(sorting)

- Space complexity: O(1)

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/solutions/3473641/easy-explanation-with-steps/)
