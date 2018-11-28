local tick = assert(require("tick"))

local function wait(s)
	local start = tick()
	repeat until tick() > start + s
	return
end

return wait