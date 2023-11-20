// File Line: 19
// RVA: 0x21F280
const char *__fastcall UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject>::GetTypeName(UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject> *this)
{
  return "UFG::ModelAsset";
}

// File Line: 20
// RVA: 0x146EAF0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::ModelAssetData_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::ModelAssetData,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 31
// RVA: 0x146EC00
__int64 dynamic_initializer_for__ModelNotification__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::ModelAsset", 0xFFFFFFFFFFFFFFFFui64);
  UFG::EditNotification::EditNotification(
    &ModelNotification,
    v0,
    (void (__fastcall *)(char *, UFG::qReflectField *, UFG::qReflectType *, char *, void *))_,
    (void (__fastcall *)(char *, void *))_,
    0i64);
  return atexit(dynamic_atexit_destructor_for__ModelNotification__);
}

