#include "Timer.h"

Timer::Timer() {
	
}

Timer::~Timer() {
	
}

void Timer::start() {
	start_time = std::chrono::high_resolution_clock::now();
	return;
}

void Timer::stop() {
	finish_time = std::chrono::high_resolution_clock::now();
	return;
}

double Timer::count() const {
	auto t = std::chrono::duration_cast<std::chrono::duration<double> >(finish_time - start_time);
	return t.count();
}

int lua_Timer_new(lua_State* L) {
	void** vpp = reinterpret_cast<void**>(lua_newuserdata(L, sizeof(Timer*)));
	*vpp = new Timer();
	luaL_setmetatable(L, LUA_TIMER);
	return 1;
}

int lua_Timer_delete(lua_State* L) {
	Timer* t = *reinterpret_cast<Timer**>(luaL_checkudata(L, 1, LUA_TIMER));
	delete t;
	return 0;
}

int lua_Timer_start(lua_State* L) {
	Timer* t = *reinterpret_cast<Timer**>(luaL_checkudata(L, 1, LUA_TIMER));
	t->start();
	return 0;
}

int lua_Timer_stop(lua_State* L) {
	Timer* t = *reinterpret_cast<Timer**>(luaL_checkudata(L, 1, LUA_TIMER));
	t->stop();
	return 0;
}

int lua_Timer_count(lua_State* L) {
	Timer* t = *reinterpret_cast<Timer**>(luaL_checkudata(L, 1, LUA_TIMER));
	lua_pushnumber(L, t->count());
	return 1;
}

int lua_Timer_newindex(lua_State* L) {
	lua_pushliteral(L, "Attempt to modify a read-only object");
	return lua_error(L);
}
int lua_Timer_table_newindex(lua_State* L) {
	lua_pushliteral(L, "Attempt to modify a read-only table");
	return lua_error(L);
}

void lua_Timer_register(lua_State* L) {
	lua_newtable(L);
	lua_pushcfunction(L, lua_Timer_new);
	lua_setfield(L, -2, "new");
	luaL_setfuncs(L, Timer_methods, 0);
	
	lua_newtable(L);
	lua_pushliteral(L, "metatable");
	lua_setfield(L, -2, "__metatable");
	lua_pushcfunction(L, lua_Timer_table_newindex);
	lua_setfield(L, -2, "__newindex");
	lua_pushvalue(L, 1);
	lua_setfield(L, -2, "__index");
	lua_setmetatable(L, -2);
	lua_setglobal(L, LUA_TIMER);
	
	luaL_newmetatable(L, LUA_TIMER);
	lua_pushliteral(L, "metatable");
	lua_setfield(L, -2, "__metatable");
	luaL_setfuncs(L, Timer_metamethods, 0);
	
	lua_newtable(L);
	luaL_setfuncs(L, Timer_methods, 0);
	lua_setfield(L, -2, "__index");
	lua_pop(L, 1);
	
	return;
}