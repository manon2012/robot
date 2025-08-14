# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.
def print_test(num, char):
    for i in range(num):
        for j in range(num-i):
            print(char, end="")
        #print(char)
def print_pattern(num_rows, char):
	for i in range(num_rows):
		for num_cols in range(num_rows-i):
			print(char, end="")
		print()


def test01():
    my_dict = {"a": 1, "b": 2, "c": 3}
    for pair in my_dict.items():
        print(pair)
    for k, v in my_dict.items():
        print (k, v)
# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    test01()
    #print_hi('PyCharm')
    #print_test(3,"p")
    #print_pattern(6,'p')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
