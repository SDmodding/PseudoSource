// File Line: 75
// RVA: 0x15BFDC0
void dynamic_initializer_for__hkaiEdgeGeometryEdgeClass__()
{
  hkClass::hkClass(
    &hkaiEdgeGeometryEdgeClass,
    "hkaiEdgeGeometryEdge",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkaiEdgeGeometry_EdgeClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 78
// RVA: 0xB47CD0
hkClass *__fastcall hkaiEdgeGeometry::Edge::staticClass()
{
  return &hkaiEdgeGeometryEdgeClass;
}

// File Line: 85
// RVA: 0xB47CF0
void __fastcall cleanupLoadedObjecthkaiEdgeGeometryEdge(void *p)
{
  ;
}

// File Line: 106
// RVA: 0x15BFEF0
hkClassEnum *dynamic_initializer_for__hkaiEdgeGeometry_FaceClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiEdgeGeometryFaceFlagBitsEnum;
  unk_142102DD0 = hkaiEdgeGeometryFaceFlagBitsEnum;
  return result;
}

// File Line: 122
// RVA: 0x15BFE20
void dynamic_initializer_for__hkaiEdgeGeometryFaceClass__()
{
  hkClass::hkClass(
    &hkaiEdgeGeometryFaceClass,
    "hkaiEdgeGeometryFace",
    0i64,
    12,
    0i64,
    0,
    0i64,
    0,
    &hkaiEdgeGeometry_FaceClass_Members,
    3,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 125
// RVA: 0xB47CE0
hkClass *__fastcall hkaiEdgeGeometry::Face::staticClass()
{
  return &hkaiEdgeGeometryFaceClass;
}

// File Line: 132
// RVA: 0xB47D00
void __fastcall finishLoadedObjecthkaiEdgeGeometryFace(void *p, int finishing)
{
  ;
}

// File Line: 138
// RVA: 0xB47D10
void __fastcall cleanupLoadedObjecthkaiEdgeGeometryFace(void *p)
{
  ;
}

// File Line: 179
// RVA: 0x15BFD50
void dynamic_initializer_for__hkaiEdgeGeometryClass__()
{
  hkClass::hkClass(
    &hkaiEdgeGeometryClass,
    "hkaiEdgeGeometry",
    &hkReferencedObjectClass,
    80,
    0i64,
    0,
    &hkaiEdgeGeometryEnums,
    1,
    &hkaiEdgeGeometryClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 182
// RVA: 0xB47CC0
hkClass *__fastcall hkaiEdgeGeometry::staticClass()
{
  return &hkaiEdgeGeometryClass;
}

// File Line: 189
// RVA: 0xB47D20
void __fastcall finishLoadedObjecthkaiEdgeGeometry(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkaiEdgeGeometry::`vftable;
}

// File Line: 195
// RVA: 0xB47D40
void __fastcall cleanupLoadedObjecthkaiEdgeGeometry(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 199
// RVA: 0xB47D50
void **__fastcall getVtablehkaiEdgeGeometry()
{
  return &hkaiEdgeGeometry::`vftable;
}

// File Line: 221
// RVA: 0x15BFE90
void **dynamic_initializer_for__hkaiEdgeGeometryTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiEdgeGeometry();
  hkaiEdgeGeometryTypeInfo.m_size = 80i64;
  hkaiEdgeGeometryTypeInfo.m_typeName = "hkaiEdgeGeometry";
  hkaiEdgeGeometryTypeInfo.m_vtable = result;
  hkaiEdgeGeometryTypeInfo.m_scopedName = "!hkaiEdgeGeometry";
  hkaiEdgeGeometryTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiEdgeGeometry;
  hkaiEdgeGeometryTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiEdgeGeometry;
  return result;
}

