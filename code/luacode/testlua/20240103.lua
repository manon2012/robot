-- arr = { 1, 2, 3, 4, 'Hello' }

-- for key, var in pairs(arr) do
--     print(key, var)
-- end

arr = {}
for var = 1, 10 do
    table.insert(arr, 1, var)
end

for key, var in pairs(arr) do
    print(key, var)
end

newarr = {}
for i = 1, 10 do
    newarr[i] = i
end

for k, v in pairs(newarr) do
    print(k, v)
end


local sum = 0
for i = 1, 100 do
    sum = sum + i
end
io.write(sum)

local function add100()
    local sum = 0
    for i = 1, 100 do
        sum = sum + i
    end
    io.write(sum)
end

add100()

if sum > 5000 then
    io.write("bigger tha 5000\n")
else
    io.write("smallorequal 5000\n")
end

arr = {}
for i = 1, 100 do
    arr[i] = i
end

local newsum = 0
for i = 1, 100 do
    newsum = newsum + arr[i]
end

io.write(newsum)

a1 = {}
a1.x = 100
a1.y = 200

a2 = { x = 100, y = 200 }

if (a1 == a2) then
    print("equal")
else
    print("not equal")
end

print(_G)
test = 100
print(_G["a1"]["x"])


function t1()
    return 0, 1
end

function t2()
    return 2, 3
end

p1, p2, p3, p4 = t1(), 2
print(p1)
print(p2)
print(p3)
print(p4)

n1, n2 = t1()
print(n1)
print(n2)


abc = { 1, 3, 9, "x", "y", 2 }
for k, v in pairs(abc) do
    print(k, v)
end


-- tb = { "ok", [3] = "god", "my", [5] = "hello", [6] = "world" }
-- for k, v in ipairs(tb) do
--     print(k, v)
-- end
