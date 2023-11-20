// File Line: 6
// RVA: 0x14649A0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::AudioAction_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::AudioAction,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 7
// RVA: 0x14647A0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::AudioEmitterDefinition_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::AudioEmitterDefinition", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::AudioEmitterDefinition,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::AudioEmitterDefinition>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 8
// RVA: 0x1464C40
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::AudioEventPropertyData_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::AudioEventPropertyData", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::AudioEventPropertyData,UFG::qReflectObject>::sInventory.vfptr,
    "UFG::AudioEventPropertyData",
    v0);
  UFG::qReflectObjectType<UFG::AudioEventPropertyData,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::AudioEventPropertyData>::`vftable;
  UFG::qReflectInventory<UFG::AudioEventPropertyData>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::AudioEventPropertyData,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::AudioEventPropertyData,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::AudioEventPropertyData_UFG::qReflectObject_::sInventory__);
}

// File Line: 9
// RVA: 0x1464860
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::AudioEventPropertyList_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::AudioEventPropertyList", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::AudioEventPropertyList,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::AudioEventPropertyList>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 10
// RVA: 0x14649D0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::AudioEnvironmentSettings_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::AudioEnvironmentSettings,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 11
// RVA: 0x1464AC0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::AudioCategoryPropertyData_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::AudioCategoryPropertyData", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::AudioCategoryPropertyData,UFG::qReflectObject>::sInventory.vfptr,
    "UFG::AudioCategoryPropertyData",
    v0);
  UFG::qReflectObjectType<UFG::AudioCategoryPropertyData,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::AudioCategoryPropertyData>::`vftable;
  UFG::qReflectInventory<UFG::AudioCategoryPropertyData>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::AudioCategoryPropertyData,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::AudioCategoryPropertyData,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::AudioCategoryPropertyData_UFG::qReflectObject_::sInventory__);
}

// File Line: 12
// RVA: 0x1464960
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::SoundEngineInitParamsReflect_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::SoundEngineInitParamsReflect", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::SoundEngineInitParamsReflect,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::SoundEngineInitParamsReflect>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 13
// RVA: 0x1464E40
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::SoundEngineDeviceSettingsReflect_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::SoundEngineDeviceSettingsReflect", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::SoundEngineDeviceSettingsReflect,UFG::qReflectObject>::sInventory.vfptr,
    "UFG::SoundEngineDeviceSettingsReflect",
    v0);
  UFG::qReflectObjectType<UFG::SoundEngineDeviceSettingsReflect,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::SoundEngineDeviceSettingsReflect>::`vftable;
  UFG::qReflectInventory<UFG::SoundEngineDeviceSettingsReflect>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::SoundEngineDeviceSettingsReflect,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::SoundEngineDeviceSettingsReflect,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::SoundEngineDeviceSettingsReflect_UFG::qReflectObject_::sInventory__);
}

// File Line: 14
// RVA: 0x1464A00
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::FilePackageManifest_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::FilePackageManifest,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 15
// RVA: 0x14648E0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::FilePackageManifestNode_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::FilePackageManifestNode", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::FilePackageManifestNode,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::FilePackageManifestNode>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

