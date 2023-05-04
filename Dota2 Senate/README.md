# Question

## 649. Dota2 Senate

In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise **one** of the two rights:

- **Ban one senator's right:** A senator can make another senator lose all his rights in this and all the following rounds.
- **Announce the victory:** If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.

Given a string `senate` representing each senator's party belonging. The character `'R'` and `'D'` represent the Radiant party and the Dire party. Then if there are `n` senators, the size of the given string will be `n`.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be `"Radiant"` or `"Dire"`.<br/>

**Example 1:**<br/>
```
Input: senate = "RD"
Output: "Radiant"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
```
**Example 2:**<br/>
```
Input: senate = "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in round 1. 
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
```

**Constraints:**
- `n == senate.length`
- `1 <= n <= 104`
- `senate[i]` is either `'R'` or `'D'`.

*you can try to solve the problem from [here](https://leetcode.com/problems/dota2-senate/description/)*

<h1 align="center">Solution</h1>

## Intuition

The optimal approach for each participant in this algorithm is to cancel the upcoming turn of their opponent.

## Approach
1. First, we count the number of 'R's in the `senate` string and subtract it from the length of the string to get the number of 'D's.
2. We define a lambda function `ban` that takes in a banned character and a starting index, and removes the first occurrence of the banned character from the `senate` string starting from the given index. The function also returns a boolean indicating whether or not the index looped around to the beginning of the string during the search for the banned character.
3. We use a while loop to simulate the game until one of the teams has no members left.
4. Within the loop, we use an if-else statement to ban a member from the opposing team based on the current member being processed.
5. We use the `ban` function to remove the banned member from the `senate` string, decrement the count of the corresponding team, and adjust the index accordingly.
6. Return the name of the winning team, which will be "Radiant" if `dCount` is zero and "Dire" otherwise.


```
function predictPartyVictory(senate):
    rCount = count the number of 'R' in the senate string
    dCount = length of senate minus rCount

    ban = lambda function that takes in a banned character and a start index
        isLoop = false
        pointer = startAt

        while true:
            if pointer == 0:
                isLoop = true
            if senate[pointer] == bannedChar:
                remove the banned character from senate at the pointer index
                break
            pointer = (pointer + 1) modulo length of senate
        
        return isLoop

    count = 0
    while rCount > 0 and dCount > 0:
        if senate[count] == 'R':
            res = ban('D', (count + 1) modulo length of senate)
            dCount--
            if res:
                count--
        else:
            res = ban('R', (count + 1) modulo length of senate)
            rCount--
            if res:
                count--
        
        count = (count + 1) modulo length of senate
    
    return "Radiant" if dCount == 0 else "Dire"

```

## Complexity
- Time complexity: O(N^2), where N is the length of the `senate` string.

- Space complexity: O(N), where N is the length of the `senate` string.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/dota2-senate/solutions/3484515/easy-explanation-and-pseudocode/)
