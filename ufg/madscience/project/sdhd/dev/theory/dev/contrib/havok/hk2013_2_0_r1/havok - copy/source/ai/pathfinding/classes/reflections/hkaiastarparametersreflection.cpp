// File Line: 71
// RVA: 0x15C3520
hkClassEnum *dynamic_initializer_for__hkaiAstarOutputParametersClass_Members__()
{
  hkClassEnum *result; // rax

  unk_142105AE8 = hkaiAstarOutputParametersSearchStatusEnum;
  result = hkaiAstarOutputParametersTerminationCauseEnum;
  unk_142105B10 = hkaiAstarOutputParametersTerminationCauseEnum;
  return result;
}

// File Line: 113
// RVA: 0x15C34A0
void dynamic_initializer_for__hkaiAstarOutputParametersClass__()
{
  hkClass::hkClass(
    &hkaiAstarOutputParametersClass,
    "hkaiAstarOutputParameters",
    0i64,
    16,
    0i64,
    0,
    &hkaiAstarOutputParametersEnums,
    2,
    &hkaiAstarOutputParametersClass_Members,
    5,
    &hkaiAstarOutputParameters_Default,
    0i64,
    0,
    2);
}

// File Line: 116
// RVA: 0xBB7BE0
hkClass *__fastcall hkaiAstarOutputParameters::staticClass()
{
  return &hkaiAstarOutputParametersClass;
}

// File Line: 123
// RVA: 0xBB7BF0
void __fastcall finishLoadedObjecthkaiAstarOutputParameters(void *p, int finishing)
{
  ;
}

// File Line: 129
// RVA: 0xBB7C00
void __fastcall cleanupLoadedObjecthkaiAstarOutputParameters(void *p)
{
  ;
}

