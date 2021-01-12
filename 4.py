class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m = len(nums1)
        n = len(nums2)
        nums1.extend(nums2)# 合并
        nums1.sort()# 排序		
        if (m + n) & 1:# 如果是奇数 返回中位数
            return nums1[(m + n - 1) >> 1]
        else:# 返回两个中位数的平均值
            return (nums1[(m + n - 1) >> 1] + nums1[(m + n) >> 1]) / 2
