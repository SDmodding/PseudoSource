// File Line: 69
// RVA: 0x15C1400
void dynamic_initializer_for__hkaiEdgePathFollowingCornerInfoClass__()
{
  hkClass::hkClass(
    &hkaiEdgePathFollowingCornerInfoClass,
    "hkaiEdgePathFollowingCornerInfo",
    0i64,
    2,
    0i64,
    0,
    0i64,
    0,
    &hkaiEdgePath_FollowingCornerInfoClass_Members,
    1,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 72
// RVA: 0xBB67A0
hkClass *__fastcall hkaiEdgePath::FollowingCornerInfo::staticClass()
{
  return &hkaiEdgePathFollowingCornerInfoClass;
}

// File Line: 79
// RVA: 0xBB67C0
void __fastcall cleanupLoadedObjecthkaiEdgePathFollowingCornerInfo(void *p)
{
  ;
}

// File Line: 105
// RVA: 0x15C14D0
hkClassEnum *dynamic_initializer_for__hkaiEdgePath_EdgeClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiNavMeshEdgeFlagBitsEnum;
  unk_1421048D8 = hkaiNavMeshEdgeFlagBitsEnum;
  return result;
}

// File Line: 121
// RVA: 0x15C1390
void dynamic_initializer_for__hkaiEdgePathEdgeClass__()
{
  hkClass::hkClass(
    &hkaiEdgePathEdgeClass,
    "hkaiEdgePathEdge",
    0i64,
    144,
    0i64,
    0,
    0i64,
    0,
    &hkaiEdgePath_EdgeClass_Members,
    8,
    0i64,
    0i64,
    0,
    2u);
}

// File Line: 124
// RVA: 0xBB67B0
hkClass *__fastcall hkaiEdgePath::Edge::staticClass()
{
  return &hkaiEdgePathEdgeClass;
}

// File Line: 131
// RVA: 0xBB67D0
void __fastcall cleanupLoadedObjecthkaiEdgePathEdge(void *p)
{
  ;
}

// File Line: 194
// RVA: 0x15C1310
void dynamic_initializer_for__hkaiEdgePathClass__()
{
  hkClass::hkClass(
    &hkaiEdgePathClass,
    "hkaiEdgePath",
    &hkReferencedObjectClass,
    64,
    0i64,
    0,
    &hkaiEdgePathEnums,
    1,
    &hkaiEdgePath::Members,
    6,
    &hkaiEdgePath_Default,
    0i64,
    0,
    1u);
}

// File Line: 197
// RVA: 0xBB6790
hkClass *__fastcall hkaiEdgePath::staticClass()
{
  return &hkaiEdgePathClass;
}

// File Line: 204
// RVA: 0xBB67E0
void __fastcall finishLoadedObjecthkaiEdgePath(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiEdgePath::hkaiEdgePath);
}

// File Line: 210
// RVA: 0xBB6800
void __fastcall cleanupLoadedObjecthkaiEdgePath(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 214
// RVA: 0xBB6810
hkBaseObjectVtbl *__fastcall getVtablehkaiEdgePath()
{
  hkaiEdgePath v1; // [rsp+20h] [rbp-48h]

  hkaiEdgePath::hkaiEdgePath(&v1, 0);
  return v1.vfptr;
}

// File Line: 236
// RVA: 0x15C1470
hkBaseObjectVtbl *dynamic_initializer_for__hkaiEdgePathTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiEdgePath();
  hkaiEdgePathTypeInfo.m_size = 64i64;
  hkaiEdgePathTypeInfo.m_typeName = "hkaiEdgePath";
  hkaiEdgePathTypeInfo.m_vtable = result;
  hkaiEdgePathTypeInfo.m_scopedName = "!hkaiEdgePath";
  hkaiEdgePathTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiEdgePath;
  hkaiEdgePathTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiEdgePath;
  return result;
}

