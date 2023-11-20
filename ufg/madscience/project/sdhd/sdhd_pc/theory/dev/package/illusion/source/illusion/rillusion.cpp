// File Line: 25
// RVA: 0x94190
void __fastcall OnPropertyChangedMaterial(char *object, UFG::qReflectField *field, UFG::qReflectType *field_type, char *field_data, void *user_data)
{
  char *v5; // rbx

  v5 = object;
  UFG::qReflectOnDemandLoader::LoadCachedReferences((UFG::qReflectObject *)object);
  Illusion::rMaterial::OnChange((Illusion::rMaterial *)v5);
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
    OnPropertyChangedMaterial,
    (void (__fastcall *)(char *, void *))OnPropertyChangedMaterial,
    0i64);
  return atexit(dynamic_atexit_destructor_for__MaterialNotification__);
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
    UFG::OnLoadClass<Illusion::rMaterial>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 34
// RVA: 0x92720
const char *__fastcall UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject>::GetTypeName(UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject> *this)
{
  return "Illusion::rTexture";
}

// File Line: 39
// RVA: 0x1457B20
__int64 Illusion::_dynamic_initializer_for__DefaultMaterialHandle__()
{
  unsigned __int64 v0; // rax

  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&Illusion::DefaultMaterialHandle.mPrev);
  v0 = UFG::qStringHash64("Illusion::rMaterial", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(
    (UFG::qReflectHandleBase *)&Illusion::DefaultMaterialHandle.mPrev,
    v0,
    0x7FFFB56FBBFDC9B3ui64);
  return atexit(Illusion::_dynamic_atexit_destructor_for__DefaultMaterialHandle__);
}

// File Line: 40
// RVA: 0x1457B80
__int64 Illusion::_dynamic_initializer_for__DefaultMaterialTexture__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&Illusion::DefaultMaterialTexture.mPrev);
  return atexit(Illusion::_dynamic_atexit_destructor_for__DefaultMaterialTexture__);
}

// File Line: 45
// RVA: 0x92250
Illusion::rMaterial *__fastcall Illusion::rMaterial::GetDefault()
{
  Illusion::rMaterial *result; // rax
  unsigned __int64 v1; // rbx
  UFG::qReflectWarehouse *v2; // rax
  UFG::qReflectInventoryBase *v3; // rax
  UFG::qReflectObject *v4; // rax

  result = (Illusion::rMaterial *)Illusion::DefaultMaterialHandle.mData;
  if ( !Illusion::DefaultMaterialHandle.mData )
  {
    v1 = UFG::qStringHash64("Illusion::rMaterial", 0xFFFFFFFFFFFFFFFFui64);
    v2 = UFG::qReflectWarehouse::Instance();
    v3 = UFG::qReflectWarehouse::GetInventory(v2, v1);
    v4 = UFG::qReflectInventoryBase::FindObjectByName(v3, "DefaultMaterial");
    if ( v4 )
      UFG::qReflectHandleBase::Init(
        (UFG::qReflectHandleBase *)&Illusion::DefaultMaterialHandle.mPrev,
        Illusion::DefaultMaterialHandle.mTypeUID,
        v4->mBaseNode.mUID);
    result = (Illusion::rMaterial *)Illusion::DefaultMaterialHandle.mData;
  }
  return result;
}

// File Line: 58
// RVA: 0x922D0
UFG::qResourceData *__fastcall Illusion::rMaterial::GetDefaultTexture(Illusion::rMaterial *this)
{
  UFG::qResourceInventory *v1; // rax
  UFG::qResourceWarehouse *v2; // rax

  if ( !Illusion::DefaultMaterialTexture.mNameUID )
  {
    v1 = `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result )
    {
      v2 = UFG::qResourceWarehouse::Instance();
      v1 = UFG::qResourceWarehouse::GetInventory(v2, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result = v1;
    }
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&Illusion::DefaultMaterialTexture.mPrev,
      0x8B43FABF,
      0x3218EEB7u,
      v1);
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
void __fastcall Illusion::eCastShadow::SetSunShadowView(unsigned int shadow_cull_index)
{
  sCastShadowViewFilter[0] |= 1 << shadow_cull_index;
  dword_14216ADC8 |= 1 << shadow_cull_index;
}

// File Line: 81
// RVA: 0x958F0
void __fastcall Illusion::eCastShadow::SetSpotShadowView(unsigned int shadow_cull_index)
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

