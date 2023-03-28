# Question
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array `days`. Each day is an integer from `1` to `365`.

Train tickets are sold in **three different ways:**

- a 1-day pass is sold for costs[0] dollars,
- a 7-day pass is sold for costs[1] dollars, and
- a 30-day pass is sold for costs[2] dollars.
- The passes allow that many days of consecutive travel.

For example, if we get a **7-day** pass on day `2`, then we can travel for `7` days: `2`, `3`, `4`, `5`, `6`, `7`, and `8`.
Return *the minimum number of dollars you need to travel every day in the given list of days.*<br/>
**Example 1:**<br/>
```
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
```
**Example 2:**<br/>
```
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.
```

**Constraints:**

- `1 <= days.length <= 365`
- `1 <= days[i] <= 365`
- `days` is in strictly increasing order.
- `costs.length == 3`
- `1 <= costs[i] <= 1000`

<h1 align="center">Solution</h1>

## Intuition
The main idea behind the problem is to find the minimum cost of purchasing a train ticket on a specific day. If the day is a day for traveling, we need to decide which type of ticket to purchase. We can either buy a 1-day ticket, a 7-day ticket, or a 30-day ticket. To determine the cheapest option, we compare the cost of buying a 1-day ticket plus the cost of the previous day's ticket with the cost of buying a 7-day ticket 7 days ago plus the cost of the 7-day ticket and the cost of buying a 30-day ticket 30 days ago plus the cost of the 30-day ticket. Finally, we choose the cheapest option among the three.

## Approach
1. Create an array `db` of size 366, where each element represents a day in the year, including February 29th for leap years. Initialize the first element `db[0]` to 0, as the cost of purchasing a ticket on day 0 is 0. 

2. Create an unordered set `set` to store the available days for the train ride. Iterate over the `days` vector and insert each day into the `set`. 

3. Iterate over the 365 days of the year, starting from day 1. For each day, check if the current day is available for the train ride by using the `find()` method on the `set`. 

4. If the day is not available for the train ride, set the cost of purchasing a ticket on that day to be the same as the previous day. 

5. If the day is available for the train ride, calculate the cost of purchasing a 1-day ticket, a 7-day ticket, and a 30-day ticket. The cost of purchasing a 1-day ticket is the cost of the previous day's ticket plus the cost of a 1-day ticket. The cost of purchasing a 7-day ticket is the cost of purchasing a 7-day ticket 7 days ago plus the cost of a 7-day ticket. Similarly, the cost of purchasing a 30-day ticket is the cost of purchasing a 30-day ticket 30 days ago plus the cost of a 30-day ticket. 

6. Take the minimum of the costs calculated in step 5, and set the value of `db[i]` to that minimum value. 

7. After iterating over all the days, return `db[365]`, which is the minimum cost of purchasing tickets for the train ride for the entire year. 

This approach calculates the minimum cost of purchasing tickets for the train ride in a dynamic programming way, where we reuse the results of previous calculations to find the minimum cost of purchasing tickets for future days. 

## Complexity
- Time complexity: O(365)

- Space complexity: O(365)

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/minimum-cost-for-tickets/solutions/3352928/easy-solution-with-cpp-explanation-without-recursion/)