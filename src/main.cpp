#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include "Windower.hpp"
using namespace geode::prelude;

class $modify(GJBaseGameLayer) {
	void update(float dt) {
		auto state = this->m_gameState;
		Windower::get().update(state);
		GJBaseGameLayer::update(dt);
	}
};

$on_mod(Loaded) {
	Windower::get().init();
}
