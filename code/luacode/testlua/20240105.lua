x = 1
y = 2

--print(x, y)
x, y = y, x

--print(x, y)


a = 1
b = 2

function test()
    a = 2
    print(a)
    print(b)
end

print(a)
test()

a = "2024"
print(a)

print(type(a))

b = 2024
print(type(b))


t = os.clock()
print(t)


local x = os.clock()
local s = 0
for i = 1, 10000000 do s = s + i end
print(string.format("elapsed time: %.2f\n", os.clock() - x))

--log(1, os.clock()-x)


-- a = "abc"
-- b = "abc"

-- loca abc = 123
