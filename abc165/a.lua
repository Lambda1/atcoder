K = io.read()
A,B = string.match(io.read(), "(%d+) (%d+)")
A,B = tonumber(A), tonumber(B)

tmp = math.floor(B/K) * K

if (tmp >= A) then
	print("OK")
else
	print("NG")
end
