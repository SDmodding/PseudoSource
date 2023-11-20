// File Line: 9
// RVA: 0x220760
const char *__fastcall UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData>::GetTypeName(UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData> *this)
{
  return "UFG::ModelData";
}

// File Line: 10
// RVA: 0x146EDE0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::CollisionData_UFG::ModelAssetData_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::CollisionData", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::CollisionData,UFG::ModelAssetData>::sInventory.vfptr,
    "UFG::CollisionData",
    v0);
  UFG::qReflectObjectType<UFG::CollisionData,UFG::ModelAssetData>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::CollisionData>::`vftable;
  UFG::qReflectInventory<UFG::CollisionData>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::CollisionData,UFG::ModelAssetData>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::CollisionData,UFG::ModelAssetData>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::CollisionData_UFG::ModelAssetData_::sInventory__);
}

// File Line: 11
// RVA: 0x146ECD0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::FreeRunData_UFG::ModelAssetData_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::FreeRunData", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::FreeRunData,UFG::ModelAssetData>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::FreeRunData>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 12
// RVA: 0x146EDD0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::SkeletonData_UFG::ModelAssetData_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::SkeletonData,UFG::ModelAssetData>::sFactoryOp);
}

// File Line: 13
// RVA: 0x220740
const char *__fastcall UFG::qReflectObjectType<UFG::CoverData,UFG::ModelAssetData>::GetTypeName(UFG::qReflectObjectType<UFG::CoverData,UFG::ModelAssetData> *this)
{
  return "UFG::CoverData";
}

