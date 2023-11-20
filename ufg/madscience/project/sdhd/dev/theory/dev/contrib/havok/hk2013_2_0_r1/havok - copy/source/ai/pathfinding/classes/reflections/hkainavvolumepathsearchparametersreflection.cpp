// File Line: 58
// RVA: 0x15C3BA0
hkClassEnum *dynamic_initializer_for__hkaiNavVolumePathSearchParametersClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiNavVolumePathSearchParametersLineOfSightFlagsEnum;
  unk_142106378 = hkaiNavVolumePathSearchParametersLineOfSightFlagsEnum;
  return result;
}

// File Line: 99
// RVA: 0x15C3B20
void dynamic_initializer_for__hkaiNavVolumePathSearchParametersClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumePathSearchParametersClass,
    "hkaiNavVolumePathSearchParameters",
    0i64,
    40,
    0i64,
    0,
    &hkaiNavVolumePathSearchParametersEnums,
    1,
    &hkaiNavVolumePathSearchParametersClass_Members,
    6,
    &hkaiNavVolumePathSearchParameters_Default,
    0i64,
    0,
    4u);
}

// File Line: 102
// RVA: 0xBB7F30
hkClass *__fastcall hkaiNavVolumePathSearchParameters::staticClass()
{
  return &hkaiNavVolumePathSearchParametersClass;
}

// File Line: 109
// RVA: 0xBB7F40
void __fastcall finishLoadedObjecthkaiNavVolumePathSearchParameters(void *p, int finishing)
{
  ;
}

// File Line: 115
// RVA: 0xBB7F50
void __fastcall cleanupLoadedObjecthkaiNavVolumePathSearchParameters(void *p)
{
  ;
}

