#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class MyPopup : public Popup<std::string const&> {
protected:
    bool setup(std::string const& value) override {
        this->setTitle("Select Layout");

        auto buttonsmenu = CCMenu::create();
        auto spr = ButtonSprite::create("Layout 1");
        auto btn = CCMenuItemSpriteExtra::create(spr, this, nullptr);
        
        buttonsmenu->addChild(btn);

        m_mainLayer->addChildAtPosition(buttonsmenu, Anchor::Center);

        return true;
    }

public:
    static MyPopup* create(std::string const& text) {
        auto ret = new MyPopup();
        if (ret->initAnchored(300.f, 200.f, text)) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }
};
