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
	
	return 1;
}

int lua_Timer_delete(lua_State* L) {
	
	return 0;
}

int lua_Timer_start(lua_State* L) {
	
	return 0;
}

int lua_Timer_stop(lua_State* L) {
	
	return 0;
}

int lua_Timer_count(lua_State* L) {
	
	return 1;
}

void lua_Timer_register(lua_State* L) {
	
	return;
}