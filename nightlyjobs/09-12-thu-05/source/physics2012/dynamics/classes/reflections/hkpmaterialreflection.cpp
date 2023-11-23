// File Line: 52
// RVA: 0x15D1DB0
hkClassEnum *dynamic_initializer_for__hkpMaterial::Members__()
{
  hkClassEnum *result; // rax

  result = hkpMaterialResponseTypeEnum;
  hkpMaterial::Members.m_enum = hkpMaterialResponseTypeEnum;
  return result;
}

// File Line: 92
// RVA: 0x15D1DC0
void dynamic_initializer_for__hkpMaterialClass__()
{
  hkClass::hkClass(
    &hkpMaterialClass,
    "hkpMaterial",
    0i64,
    12,
    0i64,
    0,
    &hkpMaterialEnums,
    1,
    &hkpMaterial::Members,
    4,
    &hkpMaterial_Default,
    0i64,
    0,
    2);
}

// File Line: 95
// RVA: 0xD514C0
hkClass *__fastcall hkpMaterial::staticClass()
{
  return &hkpMaterialClass;
}

// File Line: 102
// RVA: 0xD514D0
void __fastcall finishLoadedObjecthkpMaterial(void *p, int finishing)
{
  ;
}

// File Line: 108
// RVA: 0xD514E0
void __fastcall cleanupLoadedObjecthkpMaterial(void *p)
{
  ;
}

