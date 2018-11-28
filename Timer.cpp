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