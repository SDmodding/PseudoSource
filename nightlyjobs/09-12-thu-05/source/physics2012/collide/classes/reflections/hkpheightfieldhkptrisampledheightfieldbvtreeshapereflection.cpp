// File Line: 65
// RVA: 0x15CBEA0
void dynamic_initializer_for__hkpTriSampledHeightFieldBvTreeShapeClass__()
{
  hkClass::hkClass(
    &hkpTriSampledHeightFieldBvTreeShapeClass,
    "hkpTriSampledHeightFieldBvTreeShape",
    &hkpBvTreeShapeClass,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkpTriSampledHeightFieldBvTreeShape::Members,
    4,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 68
// RVA: 0xCECB10
hkClass *__fastcall hkpTriSampledHeightFieldBvTreeShape::staticClass()
{
  return &hkpTriSampledHeightFieldBvTreeShapeClass;
}

// File Line: 75
// RVA: 0xCECB20
void __fastcall finishLoadedObjecthkpTriSampledHeightFieldBvTreeShape(
        hkpTriSampledHeightFieldBvTreeShape *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpTriSampledHeightFieldBvTreeShape::hkpTriSampledHeightFieldBvTreeShape(p, finishing);
}

// File Line: 81
// RVA: 0xCECB40
void __fastcall cleanupLoadedObjecthkpTriSampledHeightFieldBvTreeShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 85
// RVA: 0xCECB50
hkBaseObjectVtbl *__fastcall getVtablehkpTriSampledHeightFieldBvTreeShape()
{
  hkpTriSampledHeightFieldBvTreeShape v1; // [rsp+20h] [rbp-58h] BYREF

  hkpTriSampledHeightFieldBvTreeShape::hkpTriSampledHeightFieldBvTreeShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 107
// RVA: 0x15CBF10
hkBaseObjectVtbl *dynamic_initializer_for__hkpTriSampledHeightFieldBvTreeShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpTriSampledHeightFieldBvTreeShape();
  hkpTriSampledHeightFieldBvTreeShapeTypeInfo.m_size = 80i64;
  hkpTriSampledHeightFieldBvTreeShapeTypeInfo.m_typeName = "hkpTriSampledHeightFieldBvTreeShape";
  hkpTriSampledHeightFieldBvTreeShapeTypeInfo.m_vtable = result;
  hkpTriSampledHeightFieldBvTreeShapeTypeInfo.m_scopedName = "!hkpTriSampledHeightFieldBvTreeShape";
  hkpTriSampledHeightFieldBvTreeShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpTriSampledHeightFieldBvTreeShape;
  hkpTriSampledHeightFieldBvTreeShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpTriSampledHeightFieldBvTreeShape;
  return result;
}

