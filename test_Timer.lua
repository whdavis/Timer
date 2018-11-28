local ITERATIONS = 1e8

local timer = Timer.new()
local n = 0
timer:start()
for i = 1, ITERATIONS do
	n = n + i
end
timer:stop()
print(string.format("Time elapsed: %f", timer:count()))