local wait = assert(require("wait"))

local timer = Timer.new()
print("Waiting...")
timer:start()
wait(3)
timer:stop()
print(string.format("Time elapsed: %f", timer:count()))