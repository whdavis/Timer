#ifndef TIMER_H
#define TIMER_H
#include <chrono>
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

#endif