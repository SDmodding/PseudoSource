// File Line: 10
// RVA: 0x14E9A40
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::PlayerStatData2_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::PlayerStatData2,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 11
// RVA: 0x14EA0A0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::StatModifierTypeBase_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::StatModifierTypeBase", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::StatModifierTypeBase,UFG::qReflectObject>::sInventory,
    "UFG::StatModifierTypeBase",
    v0);
  UFG::qReflectObjectType<UFG::StatModifierTypeBase,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::StatModifierTypeBase>::`vftable;
  UFG::qReflectInventory<UFG::StatModifierTypeBase>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::StatModifierTypeBase,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::StatModifierTypeBase,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::StatModifierTypeBase_UFG::qReflectObject_::sInventory__);
}

// File Line: 12
// RVA: 0x14E9500
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::PlayerStatModifierType_UFG::StatModifierTypeBase_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::PlayerStatModifierType", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::PlayerStatModifierType,UFG::StatModifierTypeBase>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::PlayerStatModifierType>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 13
// RVA: 0x14E9540
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::RacketInstanceStatModifierType_UFG::StatModifierTypeBase_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::RacketInstanceStatModifierType", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::RacketInstanceStatModifierType,UFG::StatModifierTypeBase>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::RacketInstanceStatModifierType>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 14
// RVA: 0x14E9A10
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::GangMemberStatModifierType_UFG::StatModifierTypeBase_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::GangMemberStatModifierType,UFG::StatModifierTypeBase>::sFactoryOp);
}

// File Line: 15
// RVA: 0x14EA020
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::RangedWeaponStatModifierType_UFG::StatModifierTypeBase_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::RangedWeaponStatModifierType", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::RangedWeaponStatModifierType,UFG::StatModifierTypeBase>::sInventory,
    "UFG::RangedWeaponStatModifierType",
    v0);
  UFG::qReflectObjectType<UFG::RangedWeaponStatModifierType,UFG::StatModifierTypeBase>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::RangedWeaponStatModifierType>::`vftable;
  UFG::qReflectInventory<UFG::RangedWeaponStatModifierType>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::RangedWeaponStatModifierType,UFG::StatModifierTypeBase>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    &UFG::qReflectObjectType<UFG::RangedWeaponStatModifierType,UFG::StatModifierTypeBase>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::RangedWeaponStatModifierType_UFG::StatModifierTypeBase_::sInventory__);
}

// File Line: 16
// RVA: 0x14EA1A0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::ThrownWeaponStatModifierType_UFG::StatModifierTypeBase_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::ThrownWeaponStatModifierType", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::ThrownWeaponStatModifierType,UFG::StatModifierTypeBase>::sInventory,
    "UFG::ThrownWeaponStatModifierType",
    v0);
  UFG::qReflectObjectType<UFG::ThrownWeaponStatModifierType,UFG::StatModifierTypeBase>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::ThrownWeaponStatModifierType>::`vftable;
  UFG::qReflectInventory<UFG::ThrownWeaponStatModifierType>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::ThrownWeaponStatModifierType,UFG::StatModifierTypeBase>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    &UFG::qReflectObjectType<UFG::ThrownWeaponStatModifierType,UFG::StatModifierTypeBase>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::ThrownWeaponStatModifierType_UFG::StatModifierTypeBase_::sInventory__);
}

// File Line: 17
// RVA: 0x14E9440
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::MeleeWeaponStatModifierType_UFG::StatModifierTypeBase_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::MeleeWeaponStatModifierType", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::MeleeWeaponStatModifierType,UFG::StatModifierTypeBase>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::MeleeWeaponStatModifierType>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 18
// RVA: 0x14EA220
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::UpgradeType_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::UpgradeType", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::UpgradeType,UFG::qReflectObject>::sInventory,
    "UFG::UpgradeType",
    v0);
  UFG::qReflectObjectType<UFG::UpgradeType,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::UpgradeType>::`vftable;
  UFG::qReflectInventory<UFG::UpgradeType>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::UpgradeType,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::UpgradeType,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::UpgradeType_UFG::qReflectObject_::sInventory__);
}

// File Line: 20
// RVA: 0x14E9740
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::CommodityType_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::CommodityType", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::CommodityType,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::CommodityType>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 21
// RVA: 0x14E97C0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::InformantType_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::InformantType", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::InformantType,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::InformantType>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 22
// RVA: 0x14E9B00
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::ContactType_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::ContactType,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 23
// RVA: 0x14E9B20
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::PlayerInstanceData2_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::PlayerInstanceData2,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 25
// RVA: 0x14EA520
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::RacketCoreLevel_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::RacketCoreLevel", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::RacketCoreLevel,UFG::qReflectObject>::sInventory,
    "UFG::RacketCoreLevel",
    v0);
  UFG::qReflectObjectType<UFG::RacketCoreLevel,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::RacketCoreLevel>::`vftable;
  UFG::qReflectInventory<UFG::RacketCoreLevel>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::RacketCoreLevel,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::RacketCoreLevel,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::RacketCoreLevel_UFG::qReflectObject_::sInventory__);
}

// File Line: 26
// RVA: 0x14EA5A0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::RacketCorePrefabs_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::RacketCorePrefabs", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::RacketCorePrefabs,UFG::qReflectObject>::sInventory,
    "UFG::RacketCorePrefabs",
    v0);
  UFG::qReflectObjectType<UFG::RacketCorePrefabs,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::RacketCorePrefabs>::`vftable;
  UFG::qReflectInventory<UFG::RacketCorePrefabs>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::RacketCorePrefabs,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::RacketCorePrefabs,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::RacketCorePrefabs_UFG::qReflectObject_::sInventory__);
}

// File Line: 27
// RVA: 0x14EA620
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::RacketLevel_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::RacketLevel", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::RacketLevel,UFG::qReflectObject>::sInventory,
    "UFG::RacketLevel",
    v0);
  UFG::qReflectObjectType<UFG::RacketLevel,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::RacketLevel>::`vftable;
  UFG::qReflectInventory<UFG::RacketLevel>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::RacketLevel,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::RacketLevel,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::RacketLevel_UFG::qReflectObject_::sInventory__);
}

// File Line: 28
// RVA: 0x40C8B0
const char *__fastcall UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(
        UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *this)
{
  return "UFG::RacketType";
}

// File Line: 30
// RVA: 0x14E9B70
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::SafehouseBlock_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::SafehouseBlock,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 31
// RVA: 0x14EA7A0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::TurfBlock_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::TurfBlock", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::TurfBlock,UFG::qReflectObject>::sInventory,
    "UFG::TurfBlock",
    v0);
  UFG::qReflectObjectType<UFG::TurfBlock,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::TurfBlock>::`vftable;
  UFG::qReflectInventory<UFG::TurfBlock>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::TurfBlock,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::TurfBlock,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::TurfBlock_UFG::qReflectObject_::sInventory__);
}

// File Line: 32
// RVA: 0x40C8C0
const char *__fastcall UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(
        UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *this)
{
  return "UFG::TurfTemplate";
}

// File Line: 41
// RVA: 0x40CE50
void __fastcall UFG::RacketType::GetWorldSize(UFG::RacketType::eSize size, UFG::qVector3 *outSize)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm0_4

  if ( size == MEDIUM )
  {
    outSize->x = UFG::TurfManager::TURF_LOT_SIZE * 2.0;
    v4 = UFG::TurfManager::TURF_LOT_SIZE;
    outSize->z = 0.0;
    outSize->y = v4;
  }
  else if ( (unsigned int)(size - 2) > 1 )
  {
    outSize->x = UFG::TurfManager::TURF_LOT_SIZE;
    v3 = UFG::TurfManager::TURF_LOT_SIZE;
    outSize->z = 0.0;
    outSize->y = v3;
  }
  else
  {
    outSize->x = UFG::TurfManager::TURF_LOT_SIZE * 2.0;
    v2 = UFG::TurfManager::TURF_LOT_SIZE;
    outSize->z = 0.0;
    outSize->y = v2 * 2.0;
  }
}

// File Line: 72
// RVA: 0x40CDF0
void __fastcall UFG::RacketType::GetWorldPositionOffset(UFG::RacketType::eSize size, UFG::qVector3 *outOffset)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm1_4

  v2 = UFG::TurfManager::TURF_LOT_SIZE;
  if ( size != MEDIUM )
  {
    if ( (unsigned int)(size - 2) <= 1 )
    {
      outOffset->x = UFG::TurfManager::TURF_LOT_SIZE;
      v3 = UFG::TurfManager::TURF_LOT_SIZE;
      outOffset->z = 0.0;
      LODWORD(outOffset->y) = LODWORD(v3) ^ _xmm[0];
      return;
    }
    v2 = UFG::TurfManager::TURF_LOT_SIZE * 0.5;
  }
  outOffset->x = v2;
  v4 = UFG::TurfManager::TURF_LOT_SIZE;
  outOffset->z = 0.0;
  outOffset->y = v4 * -0.5;
}

