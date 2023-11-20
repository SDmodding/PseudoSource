// File Line: 78
// RVA: 0x15C6460
void dynamic_initializer_for__hkMultiThreadCheckClass__()
{
  hkClass::hkClass(
    &hkMultiThreadCheckClass,
    "hkMultiThreadCheck",
    0i64,
    12,
    0i64,
    0,
    &hkMultiThreadCheckEnums,
    2,
    &hkMultiThreadCheck::Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 81
// RVA: 0xC54D40
hkClass *__fastcall hkMultiThreadCheck::staticClass()
{
  return &hkMultiThreadCheckClass;
}

// File Line: 88
// RVA: 0xC54D50
void __fastcall cleanupLoadedObjecthkMultiThreadCheck(void *p)
{
  ;
}

