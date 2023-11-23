// File Line: 5
// RVA: 0x1585C20
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::WorldToolsWindow_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::WorldToolsWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::WorldToolsWindow,UFG::DUIWindow>::sDeserializeOp,
    v0,
    (void (__fastcall *)(char *))UFG::OnLoadClass<UFG::Editor::WorldToolsWindow>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

