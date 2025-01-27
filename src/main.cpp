#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>
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
                auto socialsmenu = layer->getChildByID("player-menu");
                socialsmenu->setVisible(false);
                MyPopup::create("hello world!")->show();
            }
        }
    }
};
