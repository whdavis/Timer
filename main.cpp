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
	/*
	try {
		if (argc > 1) {
			// FIXME
		} else {
			throw "Filename(s) expected from command line";
		}
	} catch (const char* e) {
		std::cerr << e << std::endl;
	}
	return 0;
	*/
	Timer timer;
	timer.start();
	std::this_thread::sleep_for(std::chrono::duration<int, std::ratio<1, 1> >(3));
	timer.stop();
	std::cout << "Time elapsed: " << timer.count() << std::endl;
	return 0;
}