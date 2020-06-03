N,K = string.match(io.read(), "(%d+) (%d+)")
N,K = tonumber(N), tonumber(K)

t = {}
for i = 0, N-1, 1 do t[i+1] = 0 end

for i = 0, K-1, 1 do
	d = io.read("*number")
	for j = 0, d-1, 1 do
		A = io.read("*number")
		t[A] = t[A] + 1
	end
end

ans = 0
for i = 0, N-1, 1 do
	if t[i+1] == 0 then
		ans = ans + 1
	end
end

print(ans)
