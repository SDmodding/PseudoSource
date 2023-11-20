// File Line: 9
// RVA: 0x14759A0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::GameAsset_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::GameAsset", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::GameAsset,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::GameAsset>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 10
// RVA: 0x14759E0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::GameAssetData_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::GameAssetData", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::GameAssetData,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::GameAssetData>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

