// File Line: 50
// RVA: 0x15CB090
void dynamic_initializer_for__hkpMeshMaterialClass__()
{
  hkClass::hkClass(
    &hkpMeshMaterialClass,
    "hkpMeshMaterial",
    0i64,
    4,
    0i64,
    0,
    0i64,
    0,
    &hkpMeshMaterialClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 53
// RVA: 0xCEC120
hkClass *__fastcall hkpMeshMaterial::staticClass()
{
  return &hkpMeshMaterialClass;
}

// File Line: 60
// RVA: 0xCEC130
void __fastcall cleanupLoadedObjecthkpMeshMaterial(void *p)
{
  ;
}

