#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>
#include "layoutSelectionLayer.hpp"
#include "getProfilePage.hpp"

using namespace geode::prelude;

class $modify(PLProfilePage, ProfilePage) {
    void loadPageFromUserInfo(GJUserScore* p0) {
        ProfilePage::loadPageFromUserInfo(p0);

		auto profilePage = getCurrentProfilePage();
		if (!profilePage) {
			log::error("ProfilePage not found");
            return;
        } else {
            log::info("ProfilePage found");
            auto layer = getLayerInProfilePage(profilePage);
            if (!layer) {
                log::error("CCLayer not found in ProfilePage");
                return;
            } else {
                auto leftmenu = layer->getChildByID("left-menu");

                auto spr = CircleButtonSprite::createWithSpriteFrameName("GJ_paintBtn_001.png");
                spr->setScale(0.7);

                auto btn = CCMenuItemSpriteExtra::create(
                    spr,
                    layer,
                    menu_selector(PLProfilePage::openLayoutSelectionLayer)
                );

                btn->setScale(0.8);

                leftmenu->addChild(btn);
            }
        }
    }

    void openLayoutSelectionLayer(CCObject* sender) {
        MyPopup::create("hello world!")->show();
    }
};
