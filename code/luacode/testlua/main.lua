print("hello world")

for i = 1, 10, 1 do
   io.write(i, " ")
end

-- Count = 0;
-- while true do
--     io.write("hello\n")
--     Count = Count + 1
--     if Count ==10 then
--         break
--     end
-- end

Count = 100
io.write(tostring(Count))

local age

mytable = setmetatable({ key1 = "value1" }, {
   __index = function(mytable, key)
      if key == "key2" then
         return "metatablevalue"
      else
         return mytable[key]
      end
   end
})

print(mytable.key1, mytable.key2)



--[[ function returning the max between two numbers --]]
function max(num1, num2)
   if (num1 > num2) then
      result = num1;
   else
      result = num2;
   end

   return result;
end

r = max(10, 20)
print(r)


for i = 1, 100, 1 do
   io.write(i, " ")
end

-- while true do

-- end


if 1 then
   if 2 then
   else

   end
end

t = { ['@'] = 'abc', ['{}'] = 1729, [6.28] = 'tt' }
a = t['@']
b = t['{}']
print(a)
print(b)


-- u = {key1 = 'abc', key2 = 'cba'}
-- for k,v in ipairs(u) do
--    print (k,v)
-- end

tb = { "oh", [3] = "god", "my", [5] = "hello", [6] = "world" }

for k, v in pairs(tb) do
   print(k, v)
end

for i = 1, #tb do
   if tb[i] then
      print(tb[i])
   else
   end
end
