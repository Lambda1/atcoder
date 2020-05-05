A,B,N = string.match(io.read(), "(%d+) (%d+) (%d+)")
A,B,N = tonumber(A), tonumber(B), tonumber(N)

x = N
if B-1 < N then
	x = B-1
end

--[[
max = 0
for x = 0, N, 1 do
	tmp = math.floor((A*x)/B) - A * math.floor(x/B)
	if tmp > max then
		max = tmp
	end
end
]]

tmp = math.floor((A*x)/B) - A * math.floor(x/B)
print(tmp)
