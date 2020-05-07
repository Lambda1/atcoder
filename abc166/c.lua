N,M = io.read("*number"), io.read("*number")

H = {}
for i = 1, N, 1 do
	H[i] = io.read("*number")
end

graph = {}
for i = 1, N*N, 1 do graph[i] = 0 end

for i = 1, M, 1 do
	A, B = io.read("*number"), io.read("*number")
	graph[B*N+A] = 1
	graph[A*(N-1)+B] = 1
end

for i = 0, N-1, 1 do
	for j = 1, N, 1 do
		io.write(graph[i*N+j])
		io.write(" ")
	end
	print("")
end
