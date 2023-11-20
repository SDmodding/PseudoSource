// File Line: 78
// RVA: 0x15CBD10
void dynamic_initializer_for__hkpSampledHeightFieldShapeCoarseMinMaxLevelClass__()
{
  hkClass::hkClass(
    &hkpSampledHeightFieldShapeCoarseMinMaxLevelClass,
    "hkpSampledHeightFieldShapeCoarseMinMaxLevel",
    0i64,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkpSampledHeightFieldShape_CoarseMinMaxLevelClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 81
// RVA: 0xCEC8C0
hkClass *__fastcall hkpSampledHeightFieldShape::CoarseMinMaxLevel::staticClass()
{
  return &hkpSampledHeightFieldShapeCoarseMinMaxLevelClass;
}

// File Line: 88
// RVA: 0xCEC8D0
void __fastcall finishLoadedObjecthkpSampledHeightFieldShapeCoarseMinMaxLevel(void *p, int finishing)
{
  ;
}

// File Line: 94
// RVA: 0xCEC8E0
void __fastcall cleanupLoadedObjecthkpSampledHeightFieldShapeCoarseMinMaxLevel(void *p)
{
  int v1; // er8
  _DWORD *v2; // rbx

  v1 = *((_DWORD *)p + 3);
  v2 = p;
  *((_DWORD *)p + 2) = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    *((_DWORD *)p + 3) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      16 * v1);
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

// File Line: 124
// RVA: 0x15CBD00
hkClassEnum *dynamic_initializer_for__hkpSampledHeightFieldShapeClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpSampledHeightFieldShapeHeightFieldTypeEnum;
  unk_14210D290 = hkpSampledHeightFieldShapeHeightFieldTypeEnum;
  return result;
}

// File Line: 166
// RVA: 0x15CBC80
void dynamic_initializer_for__hkpSampledHeightFieldShapeClass__()
{
  hkClass::hkClass(
    &hkpSampledHeightFieldShapeClass,
    "hkpSampledHeightFieldShape",
    &hkpHeightFieldShapeClass,
    144,
    0i64,
    0,
    &hkpSampledHeightFieldShapeEnums,
    1,
    &hkpSampledHeightFieldShapeClass_Members,
    13,
    &hkpSampledHeightFieldShape_Default,
    0i64,
    0,
    1u);
}

// File Line: 169
// RVA: 0xCEC8B0
hkClass *__fastcall hkpSampledHeightFieldShape::staticClass()
{
  return &hkpSampledHeightFieldShapeClass;
}

// File Line: 176
// RVA: 0xCEC950
void __fastcall finishLoadedObjecthkpSampledHeightFieldShape(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpSampledHeightFieldShape::hkpSampledHeightFieldShape);
}

// File Line: 182
// RVA: 0xCEC970
void __fastcall cleanupLoadedObjecthkpSampledHeightFieldShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 186
// RVA: 0xCEC980
hkBaseObjectVtbl *__fastcall getVtablehkpSampledHeightFieldShape()
{
  hkpSampledHeightFieldShape v1; // [rsp+20h] [rbp-98h]

  hkpSampledHeightFieldShape::hkpSampledHeightFieldShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 208
// RVA: 0x15CBD70
hkBaseObjectVtbl *dynamic_initializer_for__hkpSampledHeightFieldShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpSampledHeightFieldShape();
  hkpSampledHeightFieldShapeTypeInfo.m_size = 144i64;
  hkpSampledHeightFieldShapeTypeInfo.m_typeName = "hkpSampledHeightFieldShape";
  hkpSampledHeightFieldShapeTypeInfo.m_vtable = result;
  hkpSampledHeightFieldShapeTypeInfo.m_scopedName = "!hkpSampledHeightFieldShape";
  hkpSampledHeightFieldShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpSampledHeightFieldShape;
  hkpSampledHeightFieldShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpSampledHeightFieldShape;
  return result;
}

