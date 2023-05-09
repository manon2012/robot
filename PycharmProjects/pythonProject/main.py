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

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    #print_hi('PyCharm')
    #findmp3()
    test01()
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
