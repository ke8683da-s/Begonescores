#include "../include/main.hpp"

MAKE_HOOK_OFFSETLESS(StandardLevelDetailViewController_DidActivate, void, Il2CppObject* self, bool firstActivation, int activationType) {
    StandardLevelDetailViewController_DidActivate(self, firstActivation, activationType);
    if (!firstActivation)
    {
        UNDO();
    }
    dothething(self);

}
MAKE_HOOK_OFFSETLESS(FlyingScoreEffect_InitAndPresent, void, Il2CppObject* self, Il2CppObject* noteCutInfo, int multiplier, float duration, Vector3 targetPos, Quaternion rotation, Color color) {
    FlyingScoreEffect_InitAndPresent(self, noteCutInfo, multiplier, duration, targetPos, rotation, color);
    if (Enabled)
    {
        FlyingScoreEffect_InitAndPresent(self, noteCutInfo, multiplier, 0.0f, targetPos, rotation, color);
    }
    else
    {
        FlyingScoreEffect_InitAndPresent(self, noteCutInfo, multiplier, duration, targetPos, rotation, color);
    }
}
extern "C" void load() {
    INSTALL_HOOK_OFFSETLESS(StandardLevelDetailViewController_DidActivate, il2cpp_utils::FindMethodUnsafe("", "StandardLevelDetailViewController", "DidActivate", 2));
    INSTALL_HOOK_OFFSETLESS(FlyingScoreEffect_InitAndPresent, il2cpp_utils::FindMethodUnsafe("", "FlyingScoreEffect", "InitAndPresent", 6));
}