function main()
	local aux, j;
	local i = 1;
	local count = 0;

	while count < 10001 do
		i = i + 1;         -- this update should be placed before the in statement to avoid inaccurate results.
		aux = math.floor(i / 2); -- round the number.
		if 2 <= aux then   -- to avoid errors with first number.
			for j = 2, aux do
				--io.write( i );
				if i % j == 0 then
					break;
				elseif j == aux then
					count = count + 1;
				end
			end
		else
			count = count + 1
		end
	end

	io.write("The 10 001st prime number is: ", i, "\n\n");
end

main()
