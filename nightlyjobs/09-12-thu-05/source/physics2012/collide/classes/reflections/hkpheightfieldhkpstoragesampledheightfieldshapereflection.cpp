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
void __fastcall finishLoadedObjecthkpStorageSampledHeightFieldShape(
        hkpSampledHeightFieldShape *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkpSampledHeightFieldShape::hkpSampledHeightFieldShape(p, finishing);
    p->vfptr = (hkBaseObjectVtbl *)&hkpStorageSampledHeightFieldShape::`vftable;
    if ( finishing.m_finishing )
      p->m_heightfieldType.m_storage = 0;
  }
}

// File Line: 76
// RVA: 0xCEC9F0
void __fastcall cleanupLoadedObjecthkpStorageSampledHeightFieldShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 80
// RVA: 0xCECA00
void **__fastcall getVtablehkpStorageSampledHeightFieldShape()
{
  hkpSampledHeightFieldShape v1; // [rsp+20h] [rbp-B8h] BYREF

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
  hkpStorageSampledHeightFieldShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpStorageSampledHeightFieldShape;
  hkpStorageSampledHeightFieldShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpStorageSampledHeightFieldShape;
  return result;
}

