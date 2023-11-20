// File Line: 60
// RVA: 0x15CBDD0
void dynamic_initializer_for__hkpStorageSampledHeightFieldShapeClass__()
{
  hkClass::hkClass(
    &hkpStorageSampledHeightFieldShapeClass,
    "hkpStorageSampledHeightFieldShape",
    &hkpSampledHeightFieldShapeClass,
    176,
    0i64,
    0,
    0i64,
    0,
    &hkpStorageSampledHeightFieldShapeClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 63
// RVA: 0xCEC9A0
hkClass *__fastcall hkpStorageSampledHeightFieldShape::staticClass()
{
  return &hkpStorageSampledHeightFieldShapeClass;
}

// File Line: 70
// RVA: 0xCEC9B0
void __fastcall finishLoadedObjecthkpStorageSampledHeightFieldShape(void *p, int finishing)
{
  int v2; // edi
  _BYTE *v3; // rbx

  if ( p )
  {
    v2 = finishing;
    v3 = p;
    hkpSampledHeightFieldShape::hkpSampledHeightFieldShape(
      (hkpSampledHeightFieldShape *)p,
      (hkFinishLoadedObjectFlag)finishing);
    *(_QWORD *)v3 = &hkpStorageSampledHeightFieldShape::`vftable;
    if ( v2 )
      v3[73] = 0;
  }
}

// File Line: 76
// RVA: 0xCEC9F0
void __fastcall cleanupLoadedObjecthkpStorageSampledHeightFieldShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 80
// RVA: 0xCECA00
void **__fastcall getVtablehkpStorageSampledHeightFieldShape()
{
  hkpSampledHeightFieldShape v1; // [rsp+20h] [rbp-B8h]

  hkpSampledHeightFieldShape::hkpSampledHeightFieldShape(&v1, 0);
  return &hkpStorageSampledHeightFieldShape::`vftable;
}

// File Line: 102
// RVA: 0x15CBE40
void **dynamic_initializer_for__hkpStorageSampledHeightFieldShapeTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpStorageSampledHeightFieldShape();
  hkpStorageSampledHeightFieldShapeTypeInfo.m_size = 176i64;
  hkpStorageSampledHeightFieldShapeTypeInfo.m_typeName = "hkpStorageSampledHeightFieldShape";
  hkpStorageSampledHeightFieldShapeTypeInfo.m_vtable = result;
  hkpStorageSampledHeightFieldShapeTypeInfo.m_scopedName = "!hkpStorageSampledHeightFieldShape";
  hkpStorageSampledHeightFieldShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpStorageSampledHeightFieldShape;
  hkpStorageSampledHeightFieldShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpStorageSampledHeightFieldShape;
  return result;
}

