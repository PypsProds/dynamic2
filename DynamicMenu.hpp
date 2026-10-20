#pragma once

#include <Geode/Geode.hpp>
#include <vector>

#include "ActivationPoint.hpp"

class DynamicMenu : public CCLayer {
protected:
    CCMenuItemToggler* m_masterToggle = nullptr;
    CCLabelBMFont* m_statusLabel = nullptr;
    CCLabelBMFont* m_debugLabel = nullptr;
    CCMenu* m_pointsMenu = nullptr;

public:
    static DynamicMenu* create();
    static void show();
    static void hide();

    bool init() override;
    void update(float dt) override;

    void onClose(CCObject*);
    void onAddPoint(CCObject*);
    void onToggleMaster(CCObject*);
    void onSetEarlyTolerance(CCObject*);
    void onSetLateTolerance(CCObject*);
    void onPointToggle(CCObject*);
    void onPointDelete(CCObject*);

    void refreshList();
};