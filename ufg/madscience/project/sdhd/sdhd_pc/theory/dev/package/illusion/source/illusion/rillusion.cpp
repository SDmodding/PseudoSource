// File Line: 25
// RVA: 0x94190
void __fastcall OnPropertyChangedMaterial(
        Illusion::rMaterial *object,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type,
        char *field_data,
        void *user_data)
{
  UFG::qReflectOnDemandLoader::LoadCachedReferences(object);
  Illusion::rMaterial::OnChange(object);
}

// File Line: 30
// RVA: 0x1457BB0
__int64 dynamic_initializer_for__MaterialNotification__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("Illusion::rMaterial", 0xFFFFFFFFFFFFFFFFui64);
  UFG::EditNotification::EditNotification(
    &MaterialNotification,
    v0,
    (void (__fastcall *)(char *, UFG::qReflectField *, UFG::qReflectType *, char *, void *))OnPropertyChangedMaterial,
    (void (__fastcall *)(char *, void *))OnPropertyChangedMaterial,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__MaterialNotification__);
}

// File Line: 33
// RVA: 0x1457950
void dynamic_initializer_for__UFG::qReflectObjectType_Illusion::rMaterial_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("Illusion::rMaterial", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<Illusion::rMaterial,UFG::qReflectObject>::sDeserializeOp,
    v0,
    (void (__fastcall *)(char *))UFG::OnLoadClass<Illusion::rMaterial>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 34
// RVA: 0x92720
const char *__fastcall UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject>::GetTypeName(
        UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject> *this)
{
  return "Illusion::rTexture";
}

// File Line: 39
// RVA: 0x1457B20
__int64 Illusion::_dynamic_initializer_for__DefaultMaterialHandle__()
{
  unsigned __int64 v0; // rax

  UFG::qReflectHandleBase::qReflectHandleBase(&Illusion::DefaultMaterialHandle);
  v0 = UFG::qStringHash64("Illusion::rMaterial", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&Illusion::DefaultMaterialHandle, v0, 0x7FFFB56FBBFDC9B3ui64);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__DefaultMaterialHandle__);
}

// File Line: 40
// RVA: 0x1457B80
__int64 Illusion::_dynamic_initializer_for__DefaultMaterialTexture__()
{
  UFG::qResourceHandle::qResourceHandle(&Illusion::DefaultMaterialTexture);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__DefaultMaterialTexture__);
}

// File Line: 45
// RVA: 0x92250
Illusion::rMaterial *__fastcall Illusion::rMaterial::GetDefault()
{
  Illusion::rMaterial *result; // rax
  unsigned __int64 v1; // rbx
  UFG::qReflectWarehouse *v2; // rax
  UFG::qReflectInventoryBase *Inventory; // rax
  UFG::qReflectObject *ObjectByName; // rax

  result = (Illusion::rMaterial *)Illusion::DefaultMaterialHandle.mData;
  if ( !Illusion::DefaultMaterialHandle.mData )
  {
    v1 = UFG::qStringHash64("Illusion::rMaterial", 0xFFFFFFFFFFFFFFFFui64);
    v2 = UFG::qReflectWarehouse::Instance();
    Inventory = UFG::qReflectWarehouse::GetInventory(v2, v1);
    ObjectByName = UFG::qReflectInventoryBase::FindObjectByName(Inventory, "DefaultMaterial");
    if ( ObjectByName )
      UFG::qReflectHandleBase::Init(
        &Illusion::DefaultMaterialHandle,
        Illusion::DefaultMaterialHandle.mTypeUID,
        ObjectByName->mBaseNode.mUID);
    return (Illusion::rMaterial *)Illusion::DefaultMaterialHandle.mData;
  }
  return result;
}

// File Line: 58
// RVA: 0x922D0
UFG::qResourceData *__fastcall Illusion::rMaterial::GetDefaultTexture(Illusion::rMaterial *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v2; // rax

  if ( !Illusion::DefaultMaterialTexture.mNameUID )
  {
    Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
    {
      v2 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v2, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&Illusion::DefaultMaterialTexture, 0x8B43FABF, 0x3218EEB7u, Inventory);
  }
  return Illusion::DefaultMaterialTexture.mData;
}

// File Line: 68
// RVA: 0x8E7F0
void __fastcall Illusion::eCastShadow::ClearCastShadowViewFilter(Illusion::eCastShadow *this)
{
  UFG::qMemSet(sCastShadowViewFilter, 0, 0x10u);
}

// File Line: 73
// RVA: 0x95A00
void __fastcall Illusion::eCastShadow::SetSunShadowView(char shadow_cull_index)
{
  sCastShadowViewFilter[0] |= 1 << shadow_cull_index;
  dword_14216ADC8 |= 1 << shadow_cull_index;
}

// File Line: 81
// RVA: 0x958F0
void __fastcall Illusion::eCastShadow::SetSpotShadowView(char shadow_cull_index)
{
  sCastShadowViewFilter[0] |= 1 << shadow_cull_index;
  dword_14216ADC4 |= 1 << shadow_cull_index;
}

// File Line: 89
// RVA: 0x92240
__int64 __fastcall Illusion::eCastShadow::GetCastShadowViewsCulled(Illusion::eCastShadow::Enum value)
{
  return sCastShadowViewFilter[value];
}

