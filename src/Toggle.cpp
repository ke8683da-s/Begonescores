#include "../include/main.hpp"
#include "../extern/beatsaber-hook/shared/customui/customui.hpp"
#include "../extern/beatsaber-hook/shared/utils/utils.h"
CustomUI::TextObject Test;
using namespace il2cpp_utils;
bool Enabled = true;
bool ButtonExists = false;
Il2CppObject* PlayButton;
Il2CppObject* DetailView;
Il2CppObject* DetailViewController;
Il2CppObject* Button;
bool HitCounter_b;
Il2CppObject* TMPLocalizer;

Il2CppObject* TMP;

static void SetSpacing(float spacing)
{
    Il2CppObject* ButtonObj = *RunMethod<Il2CppObject*>(Button, "get_gameObject");
    Il2CppObject* ButtonTransform = *RunMethod<Il2CppObject*>(ButtonObj, "get_transform");
    auto parent = *CRASH_UNLESS(il2cpp_utils::RunMethod<Il2CppObject*>(ButtonTransform, "get_parent"));
    Il2CppObject* parentObj = *RunMethod<Il2CppObject*>(parent, "get_gameObject");
    auto comp = *CRASH_UNLESS(il2cpp_utils::RunMethod<Il2CppObject*>(parentObj, "GetComponent", GetSystemType("UnityEngine.UI", "HorizontalLayoutGroup")));
    SetPropertyValue(comp, "spacing", &spacing);
}

std::string GetTextfrombool(bool bol)
{
    return (bol) ? "on" : "off";
}

void Destroy(Il2CppObject* obj)
{
    RunMethod(GetClassFromName("UnityEngine", "Object"), "Destroy", obj);
}

void Toggle()
{
    if (Enabled)
    {
        Enabled = false;

        std::string text = "BGS:" + GetTextfrombool(Enabled);
        RunMethod(TMP, "set_text", createcsstr(text));
    }
    else
    {
        Enabled = true;
        std::string text = "BGS:" + GetTextfrombool(Enabled);
        RunMethod(TMP, "set_text", createcsstr(text));
    }
}

void dothething(Il2CppObject* self)
{
    DetailView = *CRASH_UNLESS(il2cpp_utils::GetFieldValue(self, "_standardLevelDetailView"));
    Il2CppObject* PracticeButton = *CRASH_UNLESS(il2cpp_utils::GetFieldValue(DetailView, "_practiceButton"));
    Il2CppObject* levelName = *CRASH_UNLESS(il2cpp_utils::GetFieldValue(DetailView, "_playButton"));
    Button = *RunMethod<Il2CppObject*>("UnityEngine", "Object", "Instantiate", levelName);
    PlayButton = levelName;
    auto Transform = *CRASH_UNLESS(il2cpp_utils::RunMethod<Il2CppObject*>(levelName, "get_transform"));
    auto Transform2 = *CRASH_UNLESS(il2cpp_utils::RunMethod<Il2CppObject*>(PracticeButton, "get_transform"));
    Vector3 Scale = { 0.9, 0.9, 0.9};
    Vector3 Pos = { 0, 0, 2.6f };

    Il2CppObject* ButtonObj = *RunMethod<Il2CppObject*>(Button, "get_gameObject");
    TMP = *RunMethod<Il2CppObject*>(ButtonObj, "GetComponentInChildren", GetSystemType("TMPro", "TextMeshProUGUI"));
    TMPLocalizer = *RunMethod<Il2CppObject*>(ButtonObj, "GetComponentInChildren", GetSystemType("Polyglot", "LocalizedTextMeshProUGUI"));
    if (TMPLocalizer != nullptr)
    {
        RunMethod(GetClassFromName("UnityEngine", "Object"), "Destroy", TMPLocalizer);
    }
    //RunMethod(ButtonObj, "AddComponent", GetSystemType("HMUI", "HoverHint"));
    //Il2CppObject* HoverHint = *RunMethod<Il2CppObject*>(ButtonObj, "GetComponent", GetSystemType("HMUI", "HoverHint"));
    //std::string text2 = "Be gone scores toggle.";
    //SetPropertyValue(HoverHint, "text", &text2);
    //auto Controllers = *il2cpp_utils::RunMethod<Array<Il2CppObject*>*>("UnityEngine", "Resources", "GetObjectsOfTypeAll", GetSystemType("HMUI", "HoverHintController"));
    //Il2CppObject* Controller = *il2cpp_utils::RunMethod<Il2CppObject*>(Controllers, "First");
    //SetFieldValue(HoverHint, "_hoverHintController", Controller);
    std::string text = "BGS:" + GetTextfrombool(Enabled);
    RunMethod(TMP, "set_text", createcsstr(text));
    auto ButtonTransform = *CRASH_UNLESS(il2cpp_utils::RunMethod<Il2CppObject*>(Button, "get_transform"));
    auto parent = *CRASH_UNLESS(il2cpp_utils::RunMethod<Il2CppObject*>(Transform, "get_parent"));
    auto parent2 = *CRASH_UNLESS(il2cpp_utils::RunMethod<Il2CppObject*>(parent, "get_parent"));
    RunMethod(ButtonTransform, "SetParent", parent);
    RunMethod(ButtonTransform, "set_localScale", Scale);
    RunMethod(Transform, "set_localScale", Scale);
    RunMethod(Transform2, "set_localScale", Scale);
    RunMethod(ButtonTransform, "set_position", Pos);
    Il2CppObject* OnClick = *CRASH_UNLESS(il2cpp_utils::GetPropertyValue(Button, "onClick"));
    auto action = MakeAction(il2cpp_functions::class_get_type(il2cpp_utils::GetClassFromName("UnityEngine.Events", "UnityAction")), nullptr, Toggle);
    il2cpp_utils::RunMethod(OnClick, "AddListener", action);
    SetSpacing(0.3f);
}

void UNDO()
{
    Il2CppObject* ButtonObj = *RunMethod<Il2CppObject*>(Button, "get_gameObject");
    Destroy(ButtonObj);
}



