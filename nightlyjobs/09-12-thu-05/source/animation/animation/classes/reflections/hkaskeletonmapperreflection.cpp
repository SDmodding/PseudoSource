// File Line: 69
// RVA: 0x15BE1E0
void dynamic_initializer_for__hkaSkeletonMapperClass__()
{
  hkClass::hkClass(
    &hkaSkeletonMapperClass,
    "hkaSkeletonMapper",
    &hkReferencedObjectClass,
    192,
    0i64,
    0,
    &hkaSkeletonMapperEnums,
    1,
    &hkaSkeletonMapperClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 72
// RVA: 0xB1C690
hkClass *__fastcall hkaSkeletonMapper::staticClass()
{
  return &hkaSkeletonMapperClass;
}

// File Line: 79
// RVA: 0xB1C6A0
void __fastcall finishLoadedObjecthkaSkeletonMapper(void *p, int finishing)
{
  hkaSkeletonMapperData *v2; // rcx

  if ( p )
  {
    v2 = (hkaSkeletonMapperData *)((char *)p + 16);
    *(_QWORD *)&v2[-1].m_keepUnmappedLocal.m_bool = &hkaSkeletonMapper::`vftable;
    hkaSkeletonMapperData::hkaSkeletonMapperData(v2, (hkFinishLoadedObjectFlag)finishing);
  }
}

// File Line: 85
// RVA: 0xB1C6D0
void __fastcall cleanupLoadedObjecthkaSkeletonMapper(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 89
// RVA: 0xB1C6E0
void **__fastcall getVtablehkaSkeletonMapper()
{
  hkaSkeletonMapperData v1; // [rsp+30h] [rbp-B8h]

  hkaSkeletonMapperData::hkaSkeletonMapperData(&v1, 0);
  return &hkaSkeletonMapper::`vftable;
}

// File Line: 111
// RVA: 0x15BE250
void **dynamic_initializer_for__hkaSkeletonMapperTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaSkeletonMapper();
  hkaSkeletonMapperTypeInfo.m_size = 192i64;
  hkaSkeletonMapperTypeInfo.m_typeName = "hkaSkeletonMapper";
  hkaSkeletonMapperTypeInfo.m_vtable = result;
  hkaSkeletonMapperTypeInfo.m_scopedName = "!hkaSkeletonMapper";
  hkaSkeletonMapperTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaSkeletonMapper;
  hkaSkeletonMapperTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaSkeletonMapper;
  return result;
}

