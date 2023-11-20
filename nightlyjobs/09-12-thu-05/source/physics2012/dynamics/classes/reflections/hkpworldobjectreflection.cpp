// File Line: 126
// RVA: 0x15D2050
void dynamic_initializer_for__hkpWorldObjectClass__()
{
  hkClass::hkClass(
    &hkpWorldObjectClass,
    "hkpWorldObject",
    &hkReferencedObjectClass,
    200,
    0i64,
    0,
    &hkpWorldObjectEnums,
    2,
    &hkpWorldObject::Members,
    6,
    &hkpWorldObject_Default,
    0i64,
    0,
    0);
}

// File Line: 129
// RVA: 0xD515C0
hkClass *__fastcall hkpWorldObject::staticClass()
{
  return &hkpWorldObjectClass;
}

