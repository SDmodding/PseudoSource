// File Line: 48
// RVA: 0x15D15B0
void dynamic_initializer_for__hkpSimpleBreakableMaterialClass__()
{
  hkClass::hkClass(
    &hkpSimpleBreakableMaterialClass,
    "hkpSimpleBreakableMaterial",
    &hkpBreakableMaterialClass,
    32,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 51
// RVA: 0xD510A0
hkClass *__fastcall hkpSimpleBreakableMaterial::staticClass()
{
  return &hkpSimpleBreakableMaterialClass;
}

// File Line: 58
// RVA: 0xD510B0
void __fastcall finishLoadedObjecthkpSimpleBreakableMaterial(
        hkpSimpleBreakableMaterial *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpSimpleBreakableMaterial::hkpSimpleBreakableMaterial(p, finishing);
}

// File Line: 64
// RVA: 0xD510D0
void __fastcall cleanupLoadedObjecthkpSimpleBreakableMaterial(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 68
// RVA: 0xD510E0
hkBaseObjectVtbl *__fastcall getVtablehkpSimpleBreakableMaterial()
{
  hkpSimpleBreakableMaterial v1; // [rsp+20h] [rbp-28h] BYREF

  hkpSimpleBreakableMaterial::hkpSimpleBreakableMaterial(&v1, 0);
  return v1.vfptr;
}

// File Line: 90
// RVA: 0x15D1610
hkBaseObjectVtbl *dynamic_initializer_for__hkpSimpleBreakableMaterialTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpSimpleBreakableMaterial();
  hkpSimpleBreakableMaterialTypeInfo.m_size = 32i64;
  hkpSimpleBreakableMaterialTypeInfo.m_typeName = "hkpSimpleBreakableMaterial";
  hkpSimpleBreakableMaterialTypeInfo.m_vtable = result;
  hkpSimpleBreakableMaterialTypeInfo.m_scopedName = "!hkpSimpleBreakableMaterial";
  hkpSimpleBreakableMaterialTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpSimpleBreakableMaterial;
  hkpSimpleBreakableMaterialTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpSimpleBreakableMaterial;
  return result;
}

