# This is a sample Python script.

"""
usage:
python main.py  7Jfilename.csv
then a test2023new6J.csv file will create

"""
import csv
import pandas as pd
# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
def readcsv(csvfilename):
    import csv

    op = open(csvfilename, "r")
    dt = csv.DictReader(op)
    print(dt)
    up_dt = []
    for r in dt:
        print(r)


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.

newlist=[]

def normal(csvfilename):
    with open(csvfilename,'r') as f:
        for line in f.readlines():
            #print (line.split(" "))

            templist = line.split(" ")
            #print (newlist)
            del templist[2]
            #print (newlist)
            newlist.append(templist)
    print (newlist)

    newstringlist = []
    for i in range(len(newlist)):
        data = " ".join(newlist[i])
        data = data[:-2]
        newstringlist.append(data)

    # with open('./test2023new.csv', 'w') as f:
    #     writer = csv.writer(f)
    #     writer.writerow(newstringlist)

    with open('test2023new6J.csv', 'w') as f:
        writer = csv.writer(f)
        for val in newstringlist:
            writer.writerow([val])

import sys
def main():
    #data = pd.read_csv('test2023.csv')
    #print (data)
    print (sys.argv[1])
    #print (list(data)[0])
    #print(len(list(data)))
    normal(sys.argv[1])

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    #print_hi('PyCharm')
    #readcsv("test2023.csv")
    main()



# See PyCharm help at https://www.jetbrains.com/help/pycharm/
