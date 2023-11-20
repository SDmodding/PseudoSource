// File Line: 54
// RVA: 0x15DF960
void dynamic_initializer_for__hkMeshBoneIndexMappingClass__()
{
  hkClass::hkClass(
    &hkMeshBoneIndexMappingClass,
    "hkMeshBoneIndexMapping",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkMeshBoneIndexMappingClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0x1319690
hkClass *__fastcall hkMeshBoneIndexMapping::staticClass()
{
  return &hkMeshBoneIndexMappingClass;
}

// File Line: 64
// RVA: 0x13196B0
void __fastcall finishLoadedObjecthkMeshBoneIndexMapping(void *p, int finishing)
{
  ;
}

// File Line: 70
// RVA: 0x13196C0
void __fastcall cleanupLoadedObjecthkMeshBoneIndexMapping(void *p)
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
      2 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)v2 = 0i64;
    v2[3] = 2147483648;
  }
}

// File Line: 113
// RVA: 0x15DF890
void dynamic_initializer_for__hkIndexedTransformSetClass__()
{
  hkClass::hkClass(
    &hkIndexedTransformSetClass,
    "hkIndexedTransformSet",
    &hkReferencedObjectClass,
    104,
    0i64,
    0,
    0i64,
    0,
    &hkIndexedTransformSetClass_Members,
    6,
    0i64,
    0i64,
    0,
    2u);
}

// File Line: 116
// RVA: 0x13196A0
hkClass *__fastcall hkIndexedTransformSet::staticClass()
{
  return &hkIndexedTransformSetClass;
}

// File Line: 123
// RVA: 0x1319730
void __fastcall finishLoadedObjecthkIndexedTransformSet(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkIndexedTransformSet::hkIndexedTransformSet);
}

// File Line: 129
// RVA: 0x1319750
void __fastcall cleanupLoadedObjecthkIndexedTransformSet(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 133
// RVA: 0x1319760
hkBaseObjectVtbl *__fastcall getVtablehkIndexedTransformSet()
{
  hkIndexedTransformSet v1; // [rsp+20h] [rbp-78h]

  hkIndexedTransformSet::hkIndexedTransformSet(&v1, 0);
  return v1.vfptr;
}

// File Line: 155
// RVA: 0x15DF900
hkBaseObjectVtbl *dynamic_initializer_for__hkIndexedTransformSetTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkIndexedTransformSet();
  hkIndexedTransformSetTypeInfo.m_size = 104i64;
  hkIndexedTransformSetTypeInfo.m_typeName = "hkIndexedTransformSet";
  hkIndexedTransformSetTypeInfo.m_vtable = result;
  hkIndexedTransformSetTypeInfo.m_scopedName = "!hkIndexedTransformSet";
  hkIndexedTransformSetTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkIndexedTransformSet;
  hkIndexedTransformSetTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkIndexedTransformSet;
  return result;
}

