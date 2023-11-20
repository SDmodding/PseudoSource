// File Line: 95
// RVA: 0x15C3050
void dynamic_initializer_for__hkaiUserEdgeUtilsObbClass__()
{
  hkClass::hkClass(
    &hkaiUserEdgeUtilsObbClass,
    "hkaiUserEdgeUtilsObb",
    0i64,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkaiUserEdgeUtils_ObbClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 98
// RVA: 0xBB7830
hkClass *__fastcall hkaiUserEdgeUtils::Obb::staticClass()
{
  return &hkaiUserEdgeUtilsObbClass;
}

// File Line: 105
// RVA: 0xBB7880
void __fastcall cleanupLoadedObjecthkaiUserEdgeUtilsObb(void *p)
{
  ;
}

// File Line: 132
// RVA: 0x15C31A0
hkClassEnum *dynamic_initializer_for__hkaiUserEdgeUtils_UserEdgeSetupClass_Members__()
{
  hkClassEnum *result; // rax

  unk_142105680 = hkaiUserEdgeUtilsUserEdgeDirectionEnum;
  result = hkaiUserEdgeUtilsUserEdgeSetupSpaceEnum;
  unk_1421056A8 = hkaiUserEdgeUtilsUserEdgeSetupSpaceEnum;
  return result;
}

// File Line: 174
// RVA: 0x15C3120
void dynamic_initializer_for__hkaiUserEdgeUtilsUserEdgeSetupClass__()
{
  hkClass::hkClass(
    &hkaiUserEdgeUtilsUserEdgeSetupClass,
    "hkaiUserEdgeUtilsUserEdgeSetup",
    0i64,
    224,
    0i64,
    0,
    0i64,
    0,
    &hkaiUserEdgeUtils_UserEdgeSetupClass_Members,
    11,
    &hkaiUserEdgeUtilsUserEdgeSetup_Default,
    0i64,
    0,
    2u);
}

// File Line: 177
// RVA: 0xBB7840
hkClass *__fastcall hkaiUserEdgeUtils::UserEdgeSetup::staticClass()
{
  return &hkaiUserEdgeUtilsUserEdgeSetupClass;
}

// File Line: 184
// RVA: 0xBB7890
void __fastcall cleanupLoadedObjecthkaiUserEdgeUtilsUserEdgeSetup(void *p)
{
  ;
}

// File Line: 214
// RVA: 0x15C3190
hkClassEnum *dynamic_initializer_for__hkaiUserEdgeUtils_UserEdgePairClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiUserEdgeUtilsUserEdgeDirectionEnum;
  unk_1421058E8 = hkaiUserEdgeUtilsUserEdgeDirectionEnum;
  return result;
}

// File Line: 230
// RVA: 0x15C30B0
void dynamic_initializer_for__hkaiUserEdgeUtilsUserEdgePairClass__()
{
  hkClass::hkClass(
    &hkaiUserEdgeUtilsUserEdgePairClass,
    "hkaiUserEdgeUtilsUserEdgePair",
    0i64,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkaiUserEdgeUtils_UserEdgePairClass_Members,
    12,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 233
// RVA: 0xBB7850
hkClass *__fastcall hkaiUserEdgeUtils::UserEdgePair::staticClass()
{
  return &hkaiUserEdgeUtilsUserEdgePairClass;
}

// File Line: 240
// RVA: 0xBB78A0
void __fastcall cleanupLoadedObjecthkaiUserEdgeUtilsUserEdgePair(void *p)
{
  ;
}

// File Line: 272
// RVA: 0x15C2FF0
void dynamic_initializer_for__hkaiUserEdgeUtilsClass__()
{
  hkClass::hkClass(
    &hkaiUserEdgeUtilsClass,
    "hkaiUserEdgeUtils",
    0i64,
    1,
    0i64,
    0,
    &hkaiUserEdgeUtilsEnums,
    3,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 275
// RVA: 0xBB7820
hkClass *__fastcall hkaiUserEdgeUtils::staticClass()
{
  return &hkaiUserEdgeUtilsClass;
}

// File Line: 282
// RVA: 0xBB78B0
void __fastcall cleanupLoadedObjecthkaiUserEdgeUtils(void *p)
{
  ;
}

// File Line: 320
// RVA: 0x15C2F20
void dynamic_initializer_for__hkaiUserEdgeSetupArrayClass__()
{
  hkClass::hkClass(
    &hkaiUserEdgeSetupArrayClass,
    "hkaiUserEdgeSetupArray",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiUserEdgeSetupArrayClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 323
// RVA: 0xBB7860
hkClass *__fastcall hkaiUserEdgeSetupArray::staticClass()
{
  return &hkaiUserEdgeSetupArrayClass;
}

// File Line: 330
// RVA: 0xBB78C0
void __fastcall finishLoadedObjecthkaiUserEdgeSetupArray(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiUserEdgeSetupArray::`vftable;
}

// File Line: 336
// RVA: 0xBB78E0
void __fastcall cleanupLoadedObjecthkaiUserEdgeSetupArray(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 340
// RVA: 0xBB78F0
void **__fastcall getVtablehkaiUserEdgeSetupArray()
{
  return &hkaiUserEdgeSetupArray::`vftable;
}

// File Line: 362
// RVA: 0x15C2F90
void **dynamic_initializer_for__hkaiUserEdgeSetupArrayTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiUserEdgeSetupArray();
  hkaiUserEdgeSetupArrayTypeInfo.m_size = 32i64;
  hkaiUserEdgeSetupArrayTypeInfo.m_typeName = "hkaiUserEdgeSetupArray";
  hkaiUserEdgeSetupArrayTypeInfo.m_vtable = result;
  hkaiUserEdgeSetupArrayTypeInfo.m_scopedName = "!hkaiUserEdgeSetupArray";
  hkaiUserEdgeSetupArrayTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiUserEdgeSetupArray;
  hkaiUserEdgeSetupArrayTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiUserEdgeSetupArray;
  return result;
}

// File Line: 388
// RVA: 0x15C2E50
void dynamic_initializer_for__hkaiUserEdgePairArrayClass__()
{
  hkClass::hkClass(
    &hkaiUserEdgePairArrayClass,
    "hkaiUserEdgePairArray",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiUserEdgePairArrayClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 391
// RVA: 0xBB7870
hkClass *__fastcall hkaiUserEdgePairArray::staticClass()
{
  return &hkaiUserEdgePairArrayClass;
}

// File Line: 398
// RVA: 0xBB7900
void __fastcall finishLoadedObjecthkaiUserEdgePairArray(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiUserEdgePairArray::`vftable;
}

// File Line: 404
// RVA: 0xBB7920
void __fastcall cleanupLoadedObjecthkaiUserEdgePairArray(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 408
// RVA: 0xBB7930
void **__fastcall getVtablehkaiUserEdgePairArray()
{
  return &hkaiUserEdgePairArray::`vftable;
}

// File Line: 430
// RVA: 0x15C2EC0
void **dynamic_initializer_for__hkaiUserEdgePairArrayTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiUserEdgePairArray();
  hkaiUserEdgePairArrayTypeInfo.m_size = 32i64;
  hkaiUserEdgePairArrayTypeInfo.m_typeName = "hkaiUserEdgePairArray";
  hkaiUserEdgePairArrayTypeInfo.m_vtable = result;
  hkaiUserEdgePairArrayTypeInfo.m_scopedName = "!hkaiUserEdgePairArray";
  hkaiUserEdgePairArrayTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiUserEdgePairArray;
  hkaiUserEdgePairArrayTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiUserEdgePairArray;
  return result;
}

