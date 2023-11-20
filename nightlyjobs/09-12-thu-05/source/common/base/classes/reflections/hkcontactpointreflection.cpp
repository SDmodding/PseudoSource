// File Line: 51
// RVA: 0x15C6810
void dynamic_initializer_for__hkContactPointClass__()
{
  hkClass::hkClass(
    &hkContactPointClass,
    "hkContactPoint",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkContactPoint::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 54
// RVA: 0xC54E80
hkClass *__fastcall hkContactPoint::staticClass()
{
  return &hkContactPointClass;
}

// File Line: 61
// RVA: 0xC54E90
void __fastcall cleanupLoadedObjecthkContactPoint(void *p)
{
  ;
}

