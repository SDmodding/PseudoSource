// File Line: 56
// RVA: 0x15D64D0
void dynamic_initializer_for__hkxBlobMeshShapeClass__()
{
  hkClass::hkClass(
    &hkxBlobMeshShapeClass,
    "hkxBlobMeshShape",
    &hkMeshShapeClass,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkxBlobMeshShapeClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xE31A30
hkClass *__fastcall hkxBlobMeshShape::staticClass()
{
  return &hkxBlobMeshShapeClass;
}

// File Line: 66
// RVA: 0xE31A40
void __fastcall finishLoadedObjecthkxBlobMeshShape(void *p, int finishing)
{
  hkStringPtr *v2; // rcx

  if ( p )
  {
    v2 = (hkStringPtr *)((char *)p + 48);
    v2[-6].m_stringAndFlag = (const char *)&hkxBlobMeshShape::`vftable;
    v2[-4].m_stringAndFlag = (const char *)&hkxBlob::`vftable;
    hkStringPtr::hkStringPtr(v2, (hkFinishLoadedObjectFlag)finishing);
  }
}

// File Line: 72
// RVA: 0xE31A70
void __fastcall cleanupLoadedObjecthkxBlobMeshShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 76
// RVA: 0xE31A80
void **__fastcall getVtablehkxBlobMeshShape()
{
  hkStringPtr v1; // [rsp+50h] [rbp-18h]

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkxBlobMeshShape::`vftable;
}

// File Line: 98
// RVA: 0x15D6540
void **dynamic_initializer_for__hkxBlobMeshShapeTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxBlobMeshShape();
  hkxBlobMeshShapeTypeInfo.m_size = 56i64;
  hkxBlobMeshShapeTypeInfo.m_typeName = "hkxBlobMeshShape";
  hkxBlobMeshShapeTypeInfo.m_vtable = result;
  hkxBlobMeshShapeTypeInfo.m_scopedName = "!hkxBlobMeshShape";
  hkxBlobMeshShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxBlobMeshShape;
  hkxBlobMeshShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxBlobMeshShape;
  return result;
}

