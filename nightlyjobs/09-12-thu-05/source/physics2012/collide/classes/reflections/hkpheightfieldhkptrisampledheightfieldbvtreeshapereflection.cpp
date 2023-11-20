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
    1u);
}

// File Line: 68
// RVA: 0xCECB10
hkClass *__fastcall hkpTriSampledHeightFieldBvTreeShape::staticClass()
{
  return &hkpTriSampledHeightFieldBvTreeShapeClass;
}

// File Line: 75
// RVA: 0xCECB20
void __fastcall finishLoadedObjecthkpTriSampledHeightFieldBvTreeShape(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpTriSampledHeightFieldBvTreeShape::hkpTriSampledHeightFieldBvTreeShape);
}

// File Line: 81
// RVA: 0xCECB40
void __fastcall cleanupLoadedObjecthkpTriSampledHeightFieldBvTreeShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 85
// RVA: 0xCECB50
hkBaseObjectVtbl *__fastcall getVtablehkpTriSampledHeightFieldBvTreeShape()
{
  hkpTriSampledHeightFieldBvTreeShape v1; // [rsp+20h] [rbp-58h]

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
  hkpTriSampledHeightFieldBvTreeShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpTriSampledHeightFieldBvTreeShape;
  hkpTriSampledHeightFieldBvTreeShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpTriSampledHeightFieldBvTreeShape;
  return result;
}

