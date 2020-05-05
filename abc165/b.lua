money = 100
X = tonumber(io.read())

year = 0
while money < X do
	money = money + math.floor(money/100)
	year = year + 1
end

print(year)
