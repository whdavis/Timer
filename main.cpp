#include <iostream>
extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}
#include "Timer.h"

int main(int argc, char* argv[]) {
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
}