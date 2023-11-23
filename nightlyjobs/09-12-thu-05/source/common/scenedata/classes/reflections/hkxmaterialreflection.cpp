// File Line: 122
// RVA: 0x15D6E00
hkClassEnum *dynamic_initializer_for__hkxMaterial_TextureStageClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkxMaterialTextureTypeEnum;
  unk_142115618 = hkxMaterialTextureTypeEnum;
  return result;
}

// File Line: 160
// RVA: 0x15D6D30
void dynamic_initializer_for__hkxMaterialTextureStageClass__()
{
  hkClass::hkClass(
    &hkxMaterialTextureStageClass,
    "hkxMaterialTextureStage",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkxMaterial_TextureStageClass_Members,
    3,
    &hkxMaterialTextureStage_Default,
    0i64,
    0,
    1);
}

// File Line: 163
// RVA: 0xE32130
hkClass *__fastcall hkxMaterial::TextureStage::staticClass()
{
  return &hkxMaterialTextureStageClass;
}

// File Line: 170
// RVA: 0xE32150
void __fastcall finishLoadedObjecthkxMaterialTextureStage(void *p, int finishing)
{
  ;
}

// File Line: 176
// RVA: 0xE32160
void __fastcall cleanupLoadedObjecthkxMaterialTextureStage(hkReferencedObject **p)
{
  hkReferencedObject *v2; // rcx

  v2 = *p;
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  *p = 0i64;
}

// File Line: 212
// RVA: 0x15D6CD0
void dynamic_initializer_for__hkxMaterialPropertyClass__()
{
  hkClass::hkClass(
    &hkxMaterialPropertyClass,
    "hkxMaterialProperty",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkxMaterial_PropertyClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 215
// RVA: 0xE32140
hkClass *__fastcall hkxMaterial::Property::staticClass()
{
  return &hkxMaterialPropertyClass;
}

// File Line: 222
// RVA: 0xE32190
void __fastcall finishLoadedObjecthkxMaterialProperty(void *p, int finishing)
{
  ;
}

// File Line: 228
// RVA: 0xE321A0
void __fastcall cleanupLoadedObjecthkxMaterialProperty(void *p)
{
  ;
}

// File Line: 260
// RVA: 0x15D6C30
hkClassEnum *dynamic_initializer_for__hkxMaterial::Members__()
{
  hkClassEnum *result; // rax

  unk_1421154F8 = hkxMaterialUVMappingAlgorithmEnum;
  result = hkxMaterialTransparencyEnum;
  unk_142115570 = hkxMaterialTransparencyEnum;
  return result;
}

// File Line: 305
// RVA: 0x15D6C50
void dynamic_initializer_for__hkxMaterialClass__()
{
  hkClass::hkClass(
    &hkxMaterialClass,
    "hkxMaterial",
    &hkxAttributeHolderClass,
    224,
    0i64,
    0,
    &hkxMaterialEnums,
    4,
    &hkxMaterial::Members,
    17,
    &hkxMaterial_Default,
    0i64,
    0,
    5);
}

// File Line: 308
// RVA: 0xE32120
hkClass *__fastcall hkxMaterial::staticClass()
{
  return &hkxMaterialClass;
}

// File Line: 315
// RVA: 0xE321B0
void __fastcall finishLoadedObjecthkxMaterial(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v2; // rcx

  if ( p )
  {
    v2 = p + 4;
    v2[-4].m_stringAndFlag = (const char *)&hkxMaterial::`vftable;
    hkStringPtr::hkStringPtr(v2, finishing);
  }
}

// File Line: 321
// RVA: 0xE321E0
void __fastcall cleanupLoadedObjecthkxMaterial(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 325
// RVA: 0xE321F0
void **__fastcall getVtablehkxMaterial()
{
  hkStringPtr v1; // [rsp+40h] [rbp-C8h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkxMaterial::`vftable;
}

// File Line: 347
// RVA: 0x15D6DA0
void **dynamic_initializer_for__hkxMaterialTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxMaterial();
  hkxMaterialTypeInfo.m_size = 224i64;
  hkxMaterialTypeInfo.m_typeName = "hkxMaterial";
  hkxMaterialTypeInfo.m_vtable = result;
  hkxMaterialTypeInfo.m_scopedName = "!hkxMaterial";
  hkxMaterialTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxMaterial;
  hkxMaterialTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxMaterial;
  return result;
}

