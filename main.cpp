#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>

#include "DynamicLogic.hpp"
#include "DynamicMenu.hpp"

using namespace geode::prelude;

// A narrow, conservative assist hook placeholder.
// This project intentionally avoids changing physics or every jump.
// The real runtime implementation should gate the actual jump path in GD 2.2081.
class $modify(PlayerObject) {
public:
    bool pushButton(int key) {
        if (!DynamicLogic::isEnabled()) {
            return PlayerObject::pushButton(key);
        }

        for (const auto& point : DynamicLogic::getPoints()) {
            if (!point.enabled) continue;

            const int currentFrame = DynamicLogic::getCurrentFrameEstimate();
            const bool earlyAllowed = DynamicLogic::shouldAcceptEarlyClick(point, currentFrame);
            const bool lateAllowed = DynamicLogic::shouldAcceptLateClick(point, currentFrame);

            if (earlyAllowed || lateAllowed) {
                // This is where the real implementation should:
                // 1. validate the actual GD jump state
                // 2. ensure the jump is still physically possible
                // 3. prevent duplicate triggers
                // 4. only allow when the window is valid
                // 5. otherwise reject the late click
                return PlayerObject::pushButton(key);
            }
        }

        return PlayerObject::pushButton(key);
    }
};

class DynamicMod : public geode::Mod {
public:
    static DynamicMod* get() {
        return static_cast<DynamicMod*>(geode::Mod::get());
    }

    bool init() override {
        if (!Mod::init()) return false;

        this->setKeybind("dynamic-menu", "7", [] {
            DynamicMenu::show();
        });

        // Example initial point to make the UI feel complete.
        DynamicLogic::getPoints().push_back(
            DynamicLogic::makePoint("level-demo", 100, 3, 3)
        );

        return true;
    }
};

$execute {
    geode::Mod::registerMod(new DynamicMod());
}