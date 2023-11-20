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
    1u);
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
void __fastcall cleanupLoadedObjecthkxMaterialTextureStage(void *p)
{
  _QWORD *v1; // rbx
  hkReferencedObject *v2; // rcx

  v1 = p;
  v2 = *(hkReferencedObject **)p;
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  *v1 = 0i64;
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
    5u);
}

// File Line: 308
// RVA: 0xE32120
hkClass *__fastcall hkxMaterial::staticClass()
{
  return &hkxMaterialClass;
}

// File Line: 315
// RVA: 0xE321B0
void __fastcall finishLoadedObjecthkxMaterial(void *p, int finishing)
{
  hkStringPtr *v2; // rcx

  if ( p )
  {
    v2 = (hkStringPtr *)((char *)p + 32);
    v2[-4].m_stringAndFlag = (const char *)&hkxMaterial::`vftable;
    hkStringPtr::hkStringPtr(v2, (hkFinishLoadedObjectFlag)finishing);
  }
}

// File Line: 321
// RVA: 0xE321E0
void __fastcall cleanupLoadedObjecthkxMaterial(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 325
// RVA: 0xE321F0
void **__fastcall getVtablehkxMaterial()
{
  hkStringPtr v1; // [rsp+40h] [rbp-C8h]

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
  hkxMaterialTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxMaterial;
  hkxMaterialTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxMaterial;
  return result;
}

