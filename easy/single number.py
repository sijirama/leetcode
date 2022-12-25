class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for num in nums:
            x = nums.count(num)
            index = num
            if x == 1:
                break
        return index
        
            
        