local DATE_CMD = "date +%s.%N"

local function tick()
	local file = assert(io.popen(DATE_CMD), "io.popen failed!")
	local s = assert(file:read("*all"))
	file:close()
	return tonumber(s)
end

return tick