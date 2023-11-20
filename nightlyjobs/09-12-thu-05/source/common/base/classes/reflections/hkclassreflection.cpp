// File Line: 71
// RVA: 0x15C63E0
hkClassEnum *dynamic_initializer_for__hkClass::Members__()
{
  hkClassEnum *result; // rax

  result = hkClassFlagValuesEnum;
  unk_142108C30 = hkClassFlagValuesEnum;
  return result;
}

// File Line: 88
// RVA: 0x15C63F0
void dynamic_initializer_for__hkClassClass__()
{
  hkClass::hkClass(
    &hkClassClass,
    "hkClass",
    0i64,
    80,
    0i64,
    0,
    &hkClassEnums,
    2,
    &hkClass::Members,
    10,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 91
// RVA: 0xC54D20
hkClass *__fastcall hkClass::staticClass()
{
  return &hkClassClass;
}

// File Line: 98
// RVA: 0xC54D30
void __fastcall cleanupLoadedObjecthkClass(void *p)
{
  ;
}

