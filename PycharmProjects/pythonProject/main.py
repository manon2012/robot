# This is a sample Python script.
import fnmatch
import os


# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.
    a =100
    b = "robot"
    print(a)
    print(b)

def findmp3():
    rootPath = '/'
    pattern = '*.mp3'

    for root, dirs, files in os.walk(rootPath):
        for filename in fnmatch.filter(files, pattern):
            print(os.path.join(root, filename))


def test01():
    sum = 0
    for i in range(1,101):
        sum += i
    print (sum)

def IsPreme(x):
    for i in range(2,x):
        if x%i == 0:
            return False
    return  True

def add100Preme():
    sum = 0
    premelist = []
    for i in range(2,100):
        if(IsPreme(i)):
            sum += i
            premelist.append(i)
    print("all prime in 100 sum is: "+str(sum))
    print (premelist)
    print (len(premelist))

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    #print_hi('PyCharm')
    #findmp3()
    #test01()
    #print(IsPreme(97))
    #print(IsPreme(99))
    add100Preme()
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
