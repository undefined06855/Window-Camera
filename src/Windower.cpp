#include "Windower.hpp"
#include <Windows.h>
#include <Geode/Geode.hpp>
using namespace geode::prelude;

Windower& Windower::get() {
	static Windower instance;
	return instance;
}

void Windower::init() {
	auto director = CCDirector::sharedDirector();
	auto window = director->getOpenGLView()->getWindow();
	// nice update-friendly code
	this->window = WindowFromDC(*reinterpret_cast<HDC*>(reinterpret_cast<uintptr_t>(window) + 0x278));
	GetWindowRect(this->window, &this->rect);

	this->desktop = GetDesktopWindow();
	GetWindowRect(this->desktop, &this->desktopRect);
}

// magic code that works somehow
void Windower::update(GJGameState state) {
	auto zoom = 1 / state.m_cameraZoom;
	auto x = state.m_cameraOffset.x * zoom;
	auto y = -state.m_cameraOffset.y * zoom;

	auto width = this->rect.right - this->rect.left;
	auto height = this->rect.bottom - this->rect.top;


	if (true) {
		long maxX = this->desktopRect.right - width;
		long maxY = this->desktopRect.bottom - height;
		x = (int)(state.m_cameraPosition.x * zoom) % maxX;
		y = -(int)(state.m_cameraPosition.y * zoom) % maxY;
	}

	auto newWidth = width * zoom;
	auto newHeight = height * zoom;

	auto deltaWidth = newWidth - width;
	auto deltaHeight = newHeight - height;

	auto newLeft = this->rect.left - deltaWidth / 2;
	auto newTop = this->rect.top - deltaHeight / 2;

	SetWindowPos(this->window, nullptr, newLeft + x, newTop + y, newWidth, newHeight, SWP_NOZORDER);
}
