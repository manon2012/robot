sum = 0

num = 1

while num <= 100 do
    sum = sum + num

    num = num + 1
end

print("sum =", sum)

age = 40
sex = "Male"

if age == 40 and sex == "Male" then
    print("男人四十一枝花")
elseif age > 60 and sex ~= "Female" then
    print("old man without country!")
elseif age < 20 then
    io.write("too young, too naive!\n")
else
    local age = io.read()
    print("Your age is " .. age)
end


sum = 0
for i = 1, 100 do
    sum = sum + i
end


sum = 0
for i = 1, 100, 2 do
    sum = sum + i
end


sum = 0
for i = 100, 1, -2 do
    sum = sum + i
end


sum = 2
repeat
    sum = sum ^ 2 --幂操作
    print(sum)
until sum > 1000


function fib(n)
    if n < 2 then return 1 end
    return fib(n - 2) + fib(n - 1)
end

function newCounter()
    local i = 0
    return function() -- anonymous function
        i = i + 1
        return i
    end
end

c1 = newCounter()
print(c1()) --> 1
print(c1()) --> 2



function myPower(x)
    return function(y) return y ^ x end
end

power2 = myPower(2)
power3 = myPower(3)

print(power2(4)) --4的2次方
print(power3(5)) --5的3次方



function getUserInfo(id)
    print(id)
    return "haoel", 37, "haoel@hotmail.com", "http://jb51.net"
end

name, age, email, website, bGay = getUserInfo()



function foo(x) return x ^ 2 end

foo = function(x) return x ^ 2 end




haoel = { name = "ChenHao", age = 37, handsome = True }
haoel.website = "http://jb51.net/"
local age = haoel.age
haoel.handsome = false
haoel.name = nil

t = { [20] = 100, ['name'] = "ChenHao", [3.14] = "PI" }
