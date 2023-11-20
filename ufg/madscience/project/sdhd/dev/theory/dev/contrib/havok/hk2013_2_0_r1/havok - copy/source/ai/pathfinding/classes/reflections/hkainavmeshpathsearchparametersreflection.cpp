// File Line: 85
// RVA: 0x15C3A20
hkClassEnum *dynamic_initializer_for__hkaiNavMeshPathSearchParametersClass_Members__()
{
  hkClassEnum *result; // rax

  unk_142106050 = hkaiNavMeshPathSearchParametersOutputPathFlagsEnum;
  unk_142106078 = hkaiNavMeshPathSearchParametersLineOfSightFlagsEnum;
  result = hkaiNavMeshPathSearchParametersUserEdgeTraversalTestTypeEnum;
  unk_1421060F0 = hkaiNavMeshPathSearchParametersUserEdgeTraversalTestTypeEnum;
  return result;
}

// File Line: 145
// RVA: 0x15C39A0
void dynamic_initializer_for__hkaiNavMeshPathSearchParametersClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshPathSearchParametersClass,
    "hkaiNavMeshPathSearchParameters",
    0i64,
    72,
    0i64,
    0,
    &hkaiNavMeshPathSearchParametersEnums,
    3,
    &hkaiNavMeshPathSearchParametersClass_Members,
    17,
    &hkaiNavMeshPathSearchParameters_Default,
    0i64,
    0,
    0xAu);
}

// File Line: 148
// RVA: 0xBB7E50
hkClass *__fastcall hkaiNavMeshPathSearchParameters::staticClass()
{
  return &hkaiNavMeshPathSearchParametersClass;
}

// File Line: 155
// RVA: 0xBB7E60
void __fastcall finishLoadedObjecthkaiNavMeshPathSearchParameters(void *p, int finishing)
{
  ;
}

// File Line: 161
// RVA: 0xBB7E70
void __fastcall cleanupLoadedObjecthkaiNavMeshPathSearchParameters(void *p)
{
  ;
}

