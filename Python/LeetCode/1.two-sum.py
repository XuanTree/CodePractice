#
# @lc app=leetcode.cn id=1 lang=python3
# @lcpr version=30204
#
# [1] 两数之和
#
# @lcpr-template-start
# @lcpr-template-end
# @lc code=start
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for i in range(len(nums)):
            num1 = nums[i]
            num2 = target - num1
            if num2 in nums[i + 1:]: 
                return [i,nums[i + 1:].index(num2)+ i + 1]