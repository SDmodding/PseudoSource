// File Line: 48
// RVA: 0x15D1220
void dynamic_initializer_for__hkpListShapeBreakableMaterialClass__()
{
  hkClass::hkClass(
    &hkpListShapeBreakableMaterialClass,
    "hkpListShapeBreakableMaterial",
    &hkpBreakableMultiMaterialClass,
    56,
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
// RVA: 0xD50E40
hkClass *__fastcall hkpListShapeBreakableMaterial::staticClass()
{
  return &hkpListShapeBreakableMaterialClass;
}

// File Line: 58
// RVA: 0xD50E50
void __fastcall finishLoadedObjecthkpListShapeBreakableMaterial(
        hkpListShapeBreakableMaterial *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpListShapeBreakableMaterial::hkpListShapeBreakableMaterial(p, finishing);
}

// File Line: 64
// RVA: 0xD50E70
void __fastcall cleanupLoadedObjecthkpListShapeBreakableMaterial(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 68
// RVA: 0xD50E80
hkBaseObjectVtbl *__fastcall getVtablehkpListShapeBreakableMaterial()
{
  hkpListShapeBreakableMaterial v1; // [rsp+20h] [rbp-48h] BYREF

  hkpListShapeBreakableMaterial::hkpListShapeBreakableMaterial(&v1, 0);
  return v1.vfptr;
}

// File Line: 90
// RVA: 0x15D1280
hkBaseObjectVtbl *dynamic_initializer_for__hkpListShapeBreakableMaterialTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpListShapeBreakableMaterial();
  hkpListShapeBreakableMaterialTypeInfo.m_size = 56i64;
  hkpListShapeBreakableMaterialTypeInfo.m_typeName = "hkpListShapeBreakableMaterial";
  hkpListShapeBreakableMaterialTypeInfo.m_vtable = result;
  hkpListShapeBreakableMaterialTypeInfo.m_scopedName = "!hkpListShapeBreakableMaterial";
  hkpListShapeBreakableMaterialTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpListShapeBreakableMaterial;
  hkpListShapeBreakableMaterialTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpListShapeBreakableMaterial;
  return result;
}

