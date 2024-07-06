#include "Windows.h"
#include <Geode/Geode.hpp>
using namespace geode::prelude;

class Windower {
public:
	static Windower& get();

	HWND window;
	RECT rect;

	void init();
	void update(GJGameState state);
};
