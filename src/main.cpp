#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include "layoutSelectionLayer.hpp"

using namespace geode::prelude;

class $modify(PLProfilePage, ProfilePage) {
    static CCLayer* getLayerInProfilePage(ProfilePage* profilePage) {
        log::info("Inspecting children of the ProfilePage");
        CCObject* obj;
        CCARRAY_FOREACH(profilePage->getChildren(), obj) {
            log::info("Child object type: {}", typeid(*obj).name());
            auto layer = typeinfo_cast<CCLayer*>(obj);
            if (layer != nullptr) {
                return layer;
            }
        }
        log::error("CCLayer not found in the ProfilePage");
        return nullptr;
    }

	static ProfilePage* getCurrentProfilePage() {
        auto currentScene = CCDirector::sharedDirector()->getRunningScene();
        if (!currentScene) {
            log::error("No running scene found");
            return nullptr;
        }

        log::info("Inspecting children of the current scene");
        CCObject* obj;
        CCARRAY_FOREACH(currentScene->getChildren(), obj) {
            log::info("Child object type: {}", typeid(*obj).name());
            auto profilePage = typeinfo_cast<ProfilePage*>(obj);
            if (profilePage != nullptr) {
                return profilePage;
            }
        }

        log::error("ProfilePage not found in the current scene");
        return nullptr;
    }

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
