// File Line: 8
// RVA: 0x1476170
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::tStatistics_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::tStatistics", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::tStatistics,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::tStatistics>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

