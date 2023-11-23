// File Line: 21
// RVA: 0x206A60
UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> *__fastcall UFG::Editor::EditorWindowManager::CreateWindow(
        UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> *result,
        const char *type_name)
{
  const char *group_tag; // rax

  group_tag = UFG::Editor::mWindowGroup_Game;
  if ( UFG::Editor::mWindowMode == WindowMode_Editor )
    group_tag = UFG::Editor::mWindowGroup_Editor;
  UFG::DUIManager::CreateWindow(UFG::gDUIWindowManager, result, type_name, "DUI.GameOverlay", group_tag);
  return result;
}

