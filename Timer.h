#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#define LUA_TIMER "Timer"
extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

class Timer {
public:
	Timer();
	~Timer();
	void start();
	void stop();
	double count() const;
private:
	std::chrono::high_resolution_clock::time_point start_time;
	std::chrono::high_resolution_clock::time_point finish_time;
};

int lua_Timer_new(lua_State* L);
int lua_Timer_delete(lua_State* L);
int lua_Timer_start(lua_State* L);
int lua_Timer_stop(lua_State* L);
int lua_Timer_count(lua_State* L);
void lua_Timer_register(lua_State* L);

const luaL_Reg Timer_methods[] {
	{nullptr, nullptr}
};

const luaL_Reg Timer_metamethods[] {
	{nullptr, nullptr}
};

#endif