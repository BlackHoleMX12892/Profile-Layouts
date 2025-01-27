#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

CCLayer* getLayerInProfilePage(ProfilePage* profilePage) {
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

ProfilePage* getCurrentProfilePage() {
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
