// File Line: 55
// RVA: 0x15BF000
void dynamic_initializer_for__hkaMeshBindingMappingClass__()
{
  hkClass::hkClass(
    &hkaMeshBindingMappingClass,
    "hkaMeshBindingMapping",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkaMeshBinding_MappingClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xB1D880
hkClass *__fastcall hkaMeshBinding::Mapping::staticClass()
{
  return &hkaMeshBindingMappingClass;
}

// File Line: 65
// RVA: 0xB1D890
void __fastcall finishLoadedObjecthkaMeshBindingMapping(void *p, int finishing)
{
  ;
}

// File Line: 71
// RVA: 0xB1D8A0
void __fastcall cleanupLoadedObjecthkaMeshBindingMapping(void *p)
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

// File Line: 114
// RVA: 0x15BEF90
void dynamic_initializer_for__hkaMeshBindingClass__()
{
  hkClass::hkClass(
    &hkaMeshBindingClass,
    "hkaMeshBinding",
    &hkReferencedObjectClass,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkaMeshBindingClass_Members,
    6,
    0i64,
    0i64,
    0,
    3u);
}

// File Line: 117
// RVA: 0xB1D870
hkClass *__fastcall hkaMeshBinding::staticClass()
{
  return &hkaMeshBindingClass;
}

// File Line: 124
// RVA: 0xB1D910
void __fastcall finishLoadedObjecthkaMeshBinding(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaMeshBinding::hkaMeshBinding);
}

// File Line: 130
// RVA: 0xB1D930
void __fastcall cleanupLoadedObjecthkaMeshBinding(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 134
// RVA: 0xB1D940
hkBaseObjectVtbl *__fastcall getVtablehkaMeshBinding()
{
  hkaMeshBinding v1; // [rsp+20h] [rbp-58h]

  hkaMeshBinding::hkaMeshBinding(&v1, 0);
  return v1.vfptr;
}

// File Line: 156
// RVA: 0x15BF060
hkBaseObjectVtbl *dynamic_initializer_for__hkaMeshBindingTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaMeshBinding();
  hkaMeshBindingTypeInfo.m_size = 80i64;
  hkaMeshBindingTypeInfo.m_typeName = "hkaMeshBinding";
  hkaMeshBindingTypeInfo.m_vtable = result;
  hkaMeshBindingTypeInfo.m_scopedName = "!hkaMeshBinding";
  hkaMeshBindingTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaMeshBinding;
  hkaMeshBindingTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaMeshBinding;
  return result;
}

