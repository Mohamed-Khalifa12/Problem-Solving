# Question

## 2215. Find the Difference of Two Arrays

Given two **0-indexed** integer arrays `nums1` and `nums2`, return *a list `answer` of size `2` where:*

- `answer[0]` is a list of all **distinct** integers in `nums1` which are **not** present in `nums2`.
- `answer[1]` is a list of all **distinct** integers in `nums2` which are **not** present in `nums1`.
**Note** that the integers in the lists may be returned in **any** order.<br/>

**Example 1:**<br/>
```
Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
```
**Example 2:**<br/>
```
Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
```

**Constraints:**
- `1 <= nums1.length, nums2.length <= 1000`
- `-1000 <= nums1[i], nums2[i] <= 1000`

*you can try to solve the problem from [here](https://leetcode.com/problems/find-the-difference-of-two-arrays/description/)*

<h1 align="center">Solution</h1>


## Intuition
This problem involves substituting vectors with hash tables that have faster data access and insertion capabilities. Two maps are created for `nums1` and `nums2`, respectively. Then, we go through the first map and verify if each element exists in the other map. Finally, we append the resulting vector to the result.

## Approach

1. Create two empty unordered maps `mp1` and `mp2` to store the elements of `nums1` and `nums2`, respectively.
2. Create an empty two-dimensional vector `result` with two empty vectors to store the elements that are different between `nums1` and `nums2`.
3. Loop through both `nums1` and `nums2` simultaneously, adding each element to its corresponding map.
4. Compare the elements in `mp1` and `mp2` and add any elements in `mp1` that are not in `mp2` to the first vector in `result`.
5. Add any elements in `mp2` that are not in `mp1` to the second vector in `result`.
6. Return the `result` vector.


```
function findDifference(nums1, nums2)
    mp1 = create empty unordered map
    mp2 = create empty unordered map
    result = create a vector of two empty vectors

    i = 0
    j = 0
    n1 = size of nums1
    n2 = size of nums2

    while i < n1 or j < n2 do
        if i < n1 then
            mp1[nums1[i]] = 1
            i = i + 1
        end if
        
        if j < n2 then
            mp2[nums2[j]] = 1
            j = j + 1
        end if
    end while

    for it in mp1 do
        if mp2 does not have key it.first then
            append it.first to result[0]
        end if
    end for

    for it in mp2 do
        if mp1 does not have key it.first then
            append it.first to result[1]
        end if
    end for

    return result
end function
```

## Complexity
- Time & Space complexity: O(n), where is is the max between n1, n2.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/find-the-difference-of-two-arrays/solutions/3479750/easy-efficient-solution-with-explanation-and-pseudocode/)