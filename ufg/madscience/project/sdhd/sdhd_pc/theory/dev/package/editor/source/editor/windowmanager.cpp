// File Line: 21
// RVA: 0x206A60
UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> *__fastcall UFG::Editor::EditorWindowManager::CreateWindow(UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> *result, const char *type_name)
{
  UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> *v2; // rbx
  const char *group_tag; // rax

  v2 = result;
  group_tag = UFG::Editor::mWindowGroup_Game;
  if ( UFG::Editor::mWindowMode == WindowMode_Editor )
    group_tag = UFG::Editor::mWindowGroup_Editor;
  UFG::DUIManager::CreateWindow(
    (UFG::DUIManager *)&UFG::gDUIWindowManager->vfptr,
    result,
    type_name,
    "DUI.GameOverlay",
    group_tag);
  return v2;
}

