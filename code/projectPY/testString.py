import collections


def findonlychar(str):
    n =0
    for i in range(len(str)):
        # if (str[i].IsAlpha() & ~(str[i].Isdigit())):
        #     n = n + 1
        print(str[i])
    print(n)  


def print2(str):
    for i in range(len(str)):
        print(str[len(str)-i-1])             

class Solution:
 def firstUniqChar(self, s):
    count = collections.Counter(s)# 该函数就是Python基础库里词频统计的集成函数
    index = 0
    for ch in s:
        if count[ch] == 1:
            return index
        else:
            index += 1 
    return -1
 
 def test(self,s):
     for ch in s:
         print(ch)


if __name__ == "__main__":

    # findonlychar("hello,world!");
    #print2("hello,world!")
    s1 =Solution()
    #print(s1.firstUniqChar("hello,hworld!"))
    print(s1.test("hello,hworld!"))

