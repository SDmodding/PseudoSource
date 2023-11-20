// File Line: 57
// RVA: 0x15D0140
void dynamic_initializer_for__hkpPhantomClass__()
{
  hkClass::hkClass(
    &hkpPhantomClass,
    "hkpPhantom",
    &hkpWorldObjectClass,
    232,
    0i64,
    0,
    0i64,
    0,
    &hkpPhantom::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 60
// RVA: 0xD4FEF0
hkClass *__fastcall hkpPhantom::staticClass()
{
  return &hkpPhantomClass;
}

