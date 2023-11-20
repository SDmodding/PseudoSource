// File Line: 67
// RVA: 0x15C6140
void dynamic_initializer_for__hkClassEnumItemClass__()
{
  hkClass::hkClass(
    &hkClassEnumItemClass,
    "hkClassEnumItem",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkClassEnum::Item::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 70
// RVA: 0xC549E0
hkClass *__fastcall hkClassEnum::Item::staticClass()
{
  return &hkClassEnumItemClass;
}

// File Line: 77
// RVA: 0xC549F0
void __fastcall cleanupLoadedObjecthkClassEnumItem(void *p)
{
  ;
}

// File Line: 99
// RVA: 0x15C60C0
hkClassEnum *dynamic_initializer_for__hkClassEnum::Members__()
{
  hkClassEnum *result; // rax

  result = hkClassEnumFlagValuesEnum;
  unk_142108938 = hkClassEnumFlagValuesEnum;
  return result;
}

// File Line: 116
// RVA: 0x15C60D0
void dynamic_initializer_for__hkClassEnumClass__()
{
  hkClass::hkClass(
    &hkClassEnumClass,
    "hkClassEnum",
    0i64,
    40,
    0i64,
    0,
    &hkClassEnumEnums,
    1,
    &hkClassEnum::Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 119
// RVA: 0xC549D0
hkClass *__fastcall hkClassEnum::staticClass()
{
  return &hkClassEnumClass;
}

// File Line: 126
// RVA: 0xC54A00
void __fastcall cleanupLoadedObjecthkClassEnum(void *p)
{
  ;
}

