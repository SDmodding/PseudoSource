// File Line: 52
// RVA: 0x15CB0F0
void dynamic_initializer_for__hkpNamedMeshMaterialClass__()
{
  hkClass::hkClass(
    &hkpNamedMeshMaterialClass,
    "hkpNamedMeshMaterial",
    &hkpMeshMaterialClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpNamedMeshMaterialClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 55
// RVA: 0xCEC140
hkClass *__fastcall hkpNamedMeshMaterial::staticClass()
{
  return &hkpNamedMeshMaterialClass;
}

// File Line: 62
// RVA: 0xCEC150
void __fastcall finishLoadedObjecthkpNamedMeshMaterial(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkStringPtr::hkStringPtr(p + 1, finishing);
}

// File Line: 68
// RVA: 0xCEC170
void __fastcall cleanupLoadedObjecthkpNamedMeshMaterial(hkStringPtr *p)
{
  hkStringPtr::~hkStringPtr(p + 1);
}

