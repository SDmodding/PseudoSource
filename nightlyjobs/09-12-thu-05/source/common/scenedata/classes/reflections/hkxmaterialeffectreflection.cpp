// File Line: 57
// RVA: 0x15D6E80
hkClassEnum *dynamic_initializer_for__hkxMaterialEffectClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkxMaterialEffectEffectTypeEnum;
  unk_142115728 = hkxMaterialEffectEffectTypeEnum;
  return result;
}

// File Line: 75
// RVA: 0x15D6E10
void dynamic_initializer_for__hkxMaterialEffectClass__()
{
  hkClass::hkClass(
    &hkxMaterialEffectClass,
    "hkxMaterialEffect",
    &hkReferencedObjectClass,
    48,
    0i64,
    0,
    &hkxMaterialEffectEnums,
    1,
    &hkxMaterialEffectClass_Members,
    3,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 78
// RVA: 0xE32280
hkClass *__fastcall hkxMaterialEffect::staticClass()
{
  return &hkxMaterialEffectClass;
}

// File Line: 85
// RVA: 0xE32290
void __fastcall finishLoadedObjecthkxMaterialEffect(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v2; // rcx

  if ( p )
  {
    v2 = p + 2;
    v2[-2].m_stringAndFlag = (const char *)&hkxMaterialEffect::`vftable;
    hkStringPtr::hkStringPtr(v2, finishing);
  }
}

// File Line: 91
// RVA: 0xE322C0
void __fastcall cleanupLoadedObjecthkxMaterialEffect(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 95
// RVA: 0xE322D0
void **__fastcall getVtablehkxMaterialEffect()
{
  hkStringPtr v1; // [rsp+30h] [rbp-28h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkxMaterialEffect::`vftable;
}

// File Line: 117
// RVA: 0x15D6E90
void **dynamic_initializer_for__hkxMaterialEffectTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxMaterialEffect();
  hkxMaterialEffectTypeInfo.m_size = 48i64;
  hkxMaterialEffectTypeInfo.m_typeName = "hkxMaterialEffect";
  hkxMaterialEffectTypeInfo.m_vtable = result;
  hkxMaterialEffectTypeInfo.m_scopedName = "!hkxMaterialEffect";
  hkxMaterialEffectTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxMaterialEffect;
  hkxMaterialEffectTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxMaterialEffect;
  return result;
}

