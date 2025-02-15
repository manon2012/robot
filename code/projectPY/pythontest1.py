

def test01():
    print ("hello,world!")


def teststring():
    st1 = 'hello,world';
    print (st1[0]);

def printAll(str):
    print (str);
def printAllReverse(str):
    print(reversed(str));

def findonlychar(str):
    n =0
    for i in range(len(str)):
        # if (str[i].IsAlpha() & ~(str[i].Isdigit())):
        #     n = n + 1
        print(str[i])
    print(n)  


             



if __name__ == "__main__":
    # test01()
    # teststring()
    # printAll("hello,world!");
    # printAllReverse("hello");
    findonlychar("hello");