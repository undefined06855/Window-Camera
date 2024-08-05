#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include "Windower.hpp"
#include "ShaderManager.hpp"
#include <fmt/core.h>
#include <fmt/color.h>

using namespace geode::prelude;

class $modify(GJBaseGameLayer) {
	void update(float dt) {
		auto state = this->m_gameState;
		Windower::get().update(state);
		GJBaseGameLayer::update(dt);
	}
};

$on_mod(Loaded) {
	log::info("\x1b[96m\x1b[41m =========== LOADING ===========\x1b[0m");
	Windower::get().init();
	ShaderManager::get().init();

}
