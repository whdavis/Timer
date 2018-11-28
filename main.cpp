#include <iostream>
#include <thread>
#include <chrono>
extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}
#include "Timer.h"

int main(int argc, char* argv[]) {
	try {
		if (argc > 1) {
			lua_State* L = luaL_newstate();
			luaL_openlibs(L);
			lua_Timer_register(L);
			for (char** cpp = argv + 1; cpp < argv + argc; ++cpp) {
				if (luaL_dofile(L, *cpp)) {
					auto e = lua_tostring(L, -1);
					lua_close(L);
					throw e;
				}
			}
			lua_close(L);
		} else {
			throw "Filename(s) expected from command line";
		}
	} catch (const char* e) {
		std::cerr << e << std::endl;
	}
	return 0;
}