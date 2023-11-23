// File Line: 119
// RVA: 0x15C1770
void dynamic_initializer_for__hkaiNavMeshFaceClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshFaceClass,
    "hkaiNavMeshFace",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMesh_FaceClass_Members,
    6,
    0i64,
    0i64,
    0,
    6);
}

// File Line: 122
// RVA: 0xBB6990
hkClass *__fastcall hkaiNavMesh::Face::staticClass()
{
  return &hkaiNavMeshFaceClass;
}

// File Line: 129
// RVA: 0xBB69B0
void __fastcall cleanupLoadedObjecthkaiNavMeshFace(void *p)
{
  ;
}

// File Line: 152
// RVA: 0x15C1840
hkClassEnum *dynamic_initializer_for__hkaiNavMesh_EdgeClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiNavMeshEdgeFlagBitsEnum;
  unk_142104A50 = hkaiNavMeshEdgeFlagBitsEnum;
  return result;
}

// File Line: 170
// RVA: 0x15C1700
void dynamic_initializer_for__hkaiNavMeshEdgeClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshEdgeClass,
    "hkaiNavMeshEdge",
    0i64,
    20,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMesh_EdgeClass_Members,
    7,
    0i64,
    0i64,
    0,
    8);
}

// File Line: 173
// RVA: 0xBB69A0
hkClass *__fastcall hkaiNavMesh::Edge::staticClass()
{
  return &hkaiNavMeshEdgeClass;
}

// File Line: 180
// RVA: 0xBB69C0
void __fastcall cleanupLoadedObjecthkaiNavMeshEdge(void *p)
{
  ;
}

// File Line: 251
// RVA: 0x15C1680
void dynamic_initializer_for__hkaiNavMeshClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshClass,
    "hkaiNavMesh",
    &hkReferencedObjectClass,
    176,
    0i64,
    0,
    &hkaiNavMeshEnums,
    4,
    &hkaiNavMesh::Members,
    12,
    &hkaiNavMesh_Default,
    0i64,
    0,
    14);
}

// File Line: 254
// RVA: 0xBB6980
hkClass *__fastcall hkaiNavMesh::staticClass()
{
  return &hkaiNavMeshClass;
}

// File Line: 261
// RVA: 0xBB69D0
void __fastcall finishLoadedObjecthkaiNavMesh(hkaiNavMesh *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiNavMesh::hkaiNavMesh(p, finishing);
}

// File Line: 267
// RVA: 0xBB69F0
void __fastcall cleanupLoadedObjecthkaiNavMesh(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 271
// RVA: 0xBB6A00
hkBaseObjectVtbl *__fastcall getVtablehkaiNavMesh()
{
  hkaiNavMesh v1; // [rsp+20h] [rbp-B8h] BYREF

  hkaiNavMesh::hkaiNavMesh(&v1, 0);
  return v1.vfptr;
}

// File Line: 293
// RVA: 0x15C17E0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiNavMeshTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiNavMesh();
  hkaiNavMeshTypeInfo.m_size = 176i64;
  hkaiNavMeshTypeInfo.m_typeName = "hkaiNavMesh";
  hkaiNavMeshTypeInfo.m_vtable = result;
  hkaiNavMeshTypeInfo.m_scopedName = "!hkaiNavMesh";
  hkaiNavMeshTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiNavMesh;
  hkaiNavMeshTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiNavMesh;
  return result;
}

