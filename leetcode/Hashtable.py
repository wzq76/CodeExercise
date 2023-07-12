from typing import List


def twoSum(self, nums: List[int], target: int) -> List[int]:
    '''
    1. 两数之和
    :param self:
    :param nums:
    :param target:
    :return:
    '''
    records = dict()
    for i, val in enumerate(nums):
        if target - val in records:
            return [records[target - val], i]
        records[val] = i
    return []


def isAnagram(self, s: str, t: str) -> bool:
    """
    242.有效的字母异位词
    :param self:
    :param s:
    :param t:
    :return:
    """
    record = [0] * 26
    for i in s:
        record[ord(i) - ord("a")] += 1
    for i in t:
        record[ord(i) - ord("a")] -= 1
    for i in range(26):
        if record[i] != 0:
            return False
    return True


def threeSum(self, nums: List[int]) -> List[List[int]]:
    nums.sort()
    result = []
    for i in range(len(nums)):
        if nums[i]>0:
            return result
    if i>0 and nums[i]:
        return

