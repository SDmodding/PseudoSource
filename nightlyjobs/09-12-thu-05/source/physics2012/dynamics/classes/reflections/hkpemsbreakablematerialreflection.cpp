// File Line: 48
// RVA: 0x15D10A0
void dynamic_initializer_for__hkpExtendedMeshShapeBreakableMaterialClass__()
{
  hkClass::hkClass(
    &hkpExtendedMeshShapeBreakableMaterialClass,
    "hkpExtendedMeshShapeBreakableMaterial",
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
// RVA: 0xD50D70
hkClass *__fastcall hkpExtendedMeshShapeBreakableMaterial::staticClass()
{
  return &hkpExtendedMeshShapeBreakableMaterialClass;
}

// File Line: 58
// RVA: 0xD50D80
void __fastcall finishLoadedObjecthkpExtendedMeshShapeBreakableMaterial(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpExtendedMeshShapeBreakableMaterial::hkpExtendedMeshShapeBreakableMaterial);
}

// File Line: 64
// RVA: 0xD50DA0
void __fastcall cleanupLoadedObjecthkpExtendedMeshShapeBreakableMaterial(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 68
// RVA: 0xD50DB0
hkBaseObjectVtbl *__fastcall getVtablehkpExtendedMeshShapeBreakableMaterial()
{
  hkpExtendedMeshShapeBreakableMaterial v1; // [rsp+20h] [rbp-48h]

  hkpExtendedMeshShapeBreakableMaterial::hkpExtendedMeshShapeBreakableMaterial(&v1, 0);
  return v1.vfptr;
}

// File Line: 90
// RVA: 0x15D1100
hkBaseObjectVtbl *dynamic_initializer_for__hkpExtendedMeshShapeBreakableMaterialTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpExtendedMeshShapeBreakableMaterial();
  hkpExtendedMeshShapeBreakableMaterialTypeInfo.m_size = 56i64;
  hkpExtendedMeshShapeBreakableMaterialTypeInfo.m_typeName = "hkpExtendedMeshShapeBreakableMaterial";
  hkpExtendedMeshShapeBreakableMaterialTypeInfo.m_vtable = result;
  hkpExtendedMeshShapeBreakableMaterialTypeInfo.m_scopedName = "!hkpExtendedMeshShapeBreakableMaterial";
  hkpExtendedMeshShapeBreakableMaterialTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpExtendedMeshShapeBreakableMaterial;
  hkpExtendedMeshShapeBreakableMaterialTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpExtendedMeshShapeBreakableMaterial;
  return result;
}

