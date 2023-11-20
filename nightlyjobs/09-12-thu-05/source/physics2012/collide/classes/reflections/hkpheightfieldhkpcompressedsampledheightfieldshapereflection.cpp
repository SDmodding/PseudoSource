// File Line: 62
// RVA: 0x15CBAE0
void dynamic_initializer_for__hkpCompressedSampledHeightFieldShapeClass__()
{
  hkClass::hkClass(
    &hkpCompressedSampledHeightFieldShapeClass,
    "hkpCompressedSampledHeightFieldShape",
    &hkpSampledHeightFieldShapeClass,
    176,
    0i64,
    0,
    0i64,
    0,
    &hkpCompressedSampledHeightFieldShapeClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 65
// RVA: 0xCEC6D0
hkClass *__fastcall hkpCompressedSampledHeightFieldShape::staticClass()
{
  return &hkpCompressedSampledHeightFieldShapeClass;
}

// File Line: 72
// RVA: 0xCEC6E0
void __fastcall finishLoadedObjecthkpCompressedSampledHeightFieldShape(void *p, int finishing)
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
    *(_QWORD *)v3 = &hkpCompressedSampledHeightFieldShape::`vftable;
    if ( v2 )
      v3[73] = 1;
  }
}

// File Line: 78
// RVA: 0xCEC720
void __fastcall cleanupLoadedObjecthkpCompressedSampledHeightFieldShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 82
// RVA: 0xCEC730
void **__fastcall getVtablehkpCompressedSampledHeightFieldShape()
{
  hkpSampledHeightFieldShape v1; // [rsp+20h] [rbp-B8h]

  hkpSampledHeightFieldShape::hkpSampledHeightFieldShape(&v1, 0);
  return &hkpCompressedSampledHeightFieldShape::`vftable;
}

// File Line: 104
// RVA: 0x15CBB50
void **dynamic_initializer_for__hkpCompressedSampledHeightFieldShapeTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpCompressedSampledHeightFieldShape();
  hkpCompressedSampledHeightFieldShapeTypeInfo.m_size = 176i64;
  hkpCompressedSampledHeightFieldShapeTypeInfo.m_typeName = "hkpCompressedSampledHeightFieldShape";
  hkpCompressedSampledHeightFieldShapeTypeInfo.m_vtable = result;
  hkpCompressedSampledHeightFieldShapeTypeInfo.m_scopedName = "!hkpCompressedSampledHeightFieldShape";
  hkpCompressedSampledHeightFieldShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpCompressedSampledHeightFieldShape;
  hkpCompressedSampledHeightFieldShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpCompressedSampledHeightFieldShape;
  return result;
}

