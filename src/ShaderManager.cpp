#include "ShaderManager.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/CCNode.hpp>
using namespace geode::prelude;

const GLchar* shader_vsh = R"(

// uhhh
)";

const GLchar* shader_fsh = R"(

// uhhhh

)";

ShaderManager& ShaderManager::get() {
    static ShaderManager instance;
    return instance;
}

void ShaderManager::init() {

}


