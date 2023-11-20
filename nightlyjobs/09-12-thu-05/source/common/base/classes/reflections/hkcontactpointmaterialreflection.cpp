// File Line: 92
// RVA: 0x15C57E0
void dynamic_initializer_for__hkContactPointMaterialClass__()
{
  hkClass::hkClass(
    &hkContactPointMaterialClass,
    "hkContactPointMaterial",
    0i64,
    16,
    0i64,
    0,
    &hkContactPointMaterialEnums,
    1,
    &hkContactPointMaterial::Members,
    5,
    &hkContactPointMaterial_Default,
    0i64,
    0,
    1u);
}

// File Line: 95
// RVA: 0xC545E0
hkClass *__fastcall hkContactPointMaterial::staticClass()
{
  return &hkContactPointMaterialClass;
}

// File Line: 102
// RVA: 0xC545F0
void __fastcall cleanupLoadedObjecthkContactPointMaterial(void *p)
{
  ;
}

