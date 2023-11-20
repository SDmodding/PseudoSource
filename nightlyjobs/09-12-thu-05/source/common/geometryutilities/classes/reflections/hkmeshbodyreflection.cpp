// File Line: 61
// RVA: 0x15DF6D0
void dynamic_initializer_for__hkMeshBodyClass__()
{
  hkClass::hkClass(
    &hkMeshBodyClass,
    "hkMeshBody",
    &hkReferencedObjectClass,
    16,
    0i64,
    0,
    &hkMeshBodyEnums,
    1,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 64
// RVA: 0x1319620
hkClass *__fastcall hkMeshBody::staticClass()
{
  return &hkMeshBodyClass;
}

