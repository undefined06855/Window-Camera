#include <Geode/Geode.hpp>
using namespace geode::prelude;

class ShaderManager {
public:
    static ShaderManager& get();
    void init();

    CCRenderTexture* tex;
    CCSprite* spr;
};
