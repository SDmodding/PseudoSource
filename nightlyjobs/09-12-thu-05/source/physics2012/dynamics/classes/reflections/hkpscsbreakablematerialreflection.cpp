// File Line: 48
// RVA: 0x15D1810
void dynamic_initializer_for__hkpStaticCompoundShapeBreakableMaterialClass__()
{
  hkClass::hkClass(
    &hkpStaticCompoundShapeBreakableMaterialClass,
    "hkpStaticCompoundShapeBreakableMaterial",
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
// RVA: 0xD51220
hkClass *__fastcall hkpStaticCompoundShapeBreakableMaterial::staticClass()
{
  return &hkpStaticCompoundShapeBreakableMaterialClass;
}

// File Line: 58
// RVA: 0xD51230
void __fastcall finishLoadedObjecthkpStaticCompoundShapeBreakableMaterial(
        hkpStaticCompoundShapeBreakableMaterial *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpStaticCompoundShapeBreakableMaterial::hkpStaticCompoundShapeBreakableMaterial(p, finishing);
}

// File Line: 64
// RVA: 0xD51250
void __fastcall cleanupLoadedObjecthkpStaticCompoundShapeBreakableMaterial(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 68
// RVA: 0xD51260
hkBaseObjectVtbl *__fastcall getVtablehkpStaticCompoundShapeBreakableMaterial()
{
  hkpStaticCompoundShapeBreakableMaterial v1; // [rsp+20h] [rbp-48h] BYREF

  hkpStaticCompoundShapeBreakableMaterial::hkpStaticCompoundShapeBreakableMaterial(&v1, 0);
  return v1.vfptr;
}

// File Line: 90
// RVA: 0x15D1870
hkBaseObjectVtbl *dynamic_initializer_for__hkpStaticCompoundShapeBreakableMaterialTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpStaticCompoundShapeBreakableMaterial();
  hkpStaticCompoundShapeBreakableMaterialTypeInfo.m_size = 56i64;
  hkpStaticCompoundShapeBreakableMaterialTypeInfo.m_typeName = "hkpStaticCompoundShapeBreakableMaterial";
  hkpStaticCompoundShapeBreakableMaterialTypeInfo.m_vtable = result;
  hkpStaticCompoundShapeBreakableMaterialTypeInfo.m_scopedName = "!hkpStaticCompoundShapeBreakableMaterial";
  hkpStaticCompoundShapeBreakableMaterialTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpStaticCompoundShapeBreakableMaterial;
  hkpStaticCompoundShapeBreakableMaterialTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpStaticCompoundShapeBreakableMaterial;
  return result;
}

