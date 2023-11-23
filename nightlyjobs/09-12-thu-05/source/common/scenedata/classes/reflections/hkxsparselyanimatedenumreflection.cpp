// File Line: 54
// RVA: 0x15D67B0
void dynamic_initializer_for__hkxEnumItemClass__()
{
  hkClass::hkClass(
    &hkxEnumItemClass,
    "hkxEnumItem",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkxEnum_ItemClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xE31C50
hkClass *__fastcall hkxEnum::Item::staticClass()
{
  return &hkxEnumItemClass;
}

// File Line: 64
// RVA: 0xE31C70
void __fastcall finishLoadedObjecthkxEnumItem(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkStringPtr::hkStringPtr(p + 1, finishing);
}

// File Line: 70
// RVA: 0xE31C90
void __fastcall cleanupLoadedObjecthkxEnumItem(hkStringPtr *p)
{
  hkStringPtr::~hkStringPtr(p + 1);
}

// File Line: 107
// RVA: 0x15D6740
void dynamic_initializer_for__hkxEnumClass__()
{
  hkClass::hkClass(
    &hkxEnumClass,
    "hkxEnum",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkxEnumClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 110
// RVA: 0xE31C40
hkClass *__fastcall hkxEnum::staticClass()
{
  return &hkxEnumClass;
}

// File Line: 117
// RVA: 0xE31CA0
void __fastcall finishLoadedObjecthkxEnum(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkxEnum::`vftable;
}

// File Line: 123
// RVA: 0xE31CC0
void __fastcall cleanupLoadedObjecthkxEnum(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 127
// RVA: 0xE31CD0
void **__fastcall getVtablehkxEnum()
{
  return &hkxEnum::`vftable;
}

// File Line: 149
// RVA: 0x15D6810
void **dynamic_initializer_for__hkxEnumTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxEnum();
  hkxEnumTypeInfo.m_size = 32i64;
  hkxEnumTypeInfo.m_typeName = "hkxEnum";
  hkxEnumTypeInfo.m_vtable = result;
  hkxEnumTypeInfo.m_scopedName = "!hkxEnum";
  hkxEnumTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxEnum;
  hkxEnumTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxEnum;
  return result;
}

// File Line: 176
// RVA: 0x15D6870
void dynamic_initializer_for__hkxSparselyAnimatedEnumClass__()
{
  hkClass::hkClass(
    &hkxSparselyAnimatedEnumClass,
    "hkxSparselyAnimatedEnum",
    &hkxSparselyAnimatedIntClass,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkxSparselyAnimatedEnumClass_Members,
    1,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 179
// RVA: 0xE31C60
hkClass *__fastcall hkxSparselyAnimatedEnum::staticClass()
{
  return &hkxSparselyAnimatedEnumClass;
}

// File Line: 186
// RVA: 0xE31CE0
void __fastcall finishLoadedObjecthkxSparselyAnimatedEnum(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkxSparselyAnimatedEnum::`vftable;
}

// File Line: 192
// RVA: 0xE31D00
void __fastcall cleanupLoadedObjecthkxSparselyAnimatedEnum(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 196
// RVA: 0xE31D10
void **__fastcall getVtablehkxSparselyAnimatedEnum()
{
  return &hkxSparselyAnimatedEnum::`vftable;
}

// File Line: 218
// RVA: 0x15D68E0
void **dynamic_initializer_for__hkxSparselyAnimatedEnumTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxSparselyAnimatedEnum();
  hkxSparselyAnimatedEnumTypeInfo.m_size = 56i64;
  hkxSparselyAnimatedEnumTypeInfo.m_typeName = "hkxSparselyAnimatedEnum";
  hkxSparselyAnimatedEnumTypeInfo.m_vtable = result;
  hkxSparselyAnimatedEnumTypeInfo.m_scopedName = "!hkxSparselyAnimatedEnum";
  hkxSparselyAnimatedEnumTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxSparselyAnimatedEnum;
  hkxSparselyAnimatedEnumTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxSparselyAnimatedEnum;
  return result;
}

