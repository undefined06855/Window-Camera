#include "Windows.h"
#include <Geode/Geode.hpp>
using namespace geode::prelude;

class Windower {
public:
	static Windower& get();

	HWND window;
	RECT rect;
	HWND desktop;
	RECT desktopRect;

	void init();
	void update(GJGameState state);
};
