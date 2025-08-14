class Solution:
#  def firstUniqChar(self, s):
#     count = collections.Counter(s)# 该函数就是Python基础库里词频统计的集成函数
#     index = 0
#     for ch in s:
#         if count[ch] == 1:
#             return index
#         else:
#             index += 1 
#     return -1