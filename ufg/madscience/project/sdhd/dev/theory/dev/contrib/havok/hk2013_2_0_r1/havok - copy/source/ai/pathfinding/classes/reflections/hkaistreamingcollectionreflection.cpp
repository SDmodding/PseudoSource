// File Line: 63
// RVA: 0x15C2D80
void dynamic_initializer_for__hkaiStreamingCollectionInstanceInfoClass__()
{
  hkClass::hkClass(
    &hkaiStreamingCollectionInstanceInfoClass,
    "hkaiStreamingCollectionInstanceInfo",
    0i64,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkaiStreamingCollection_InstanceInfoClass_Members,
    6,
    0i64,
    0i64,
    0,
    4);
}

// File Line: 66
// RVA: 0xBB77B0
hkClass *__fastcall hkaiStreamingCollection::InstanceInfo::staticClass()
{
  return &hkaiStreamingCollectionInstanceInfoClass;
}

// File Line: 73
// RVA: 0xBB77C0
void __fastcall cleanupLoadedObjecthkaiStreamingCollectionInstanceInfo(void *p)
{
  ;
}

// File Line: 133
// RVA: 0x15C2D10
void dynamic_initializer_for__hkaiStreamingCollectionClass__()
{
  hkClass::hkClass(
    &hkaiStreamingCollectionClass,
    "hkaiStreamingCollection",
    &hkReferencedObjectClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkaiStreamingCollectionClass_Members,
    3,
    &hkaiStreamingCollection_Default,
    0i64,
    0,
    2);
}

// File Line: 136
// RVA: 0xBB77A0
hkClass *__fastcall hkaiStreamingCollection::staticClass()
{
  return &hkaiStreamingCollectionClass;
}

// File Line: 143
// RVA: 0xBB77D0
void __fastcall finishLoadedObjecthkaiStreamingCollection(
        hkaiStreamingCollection *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiStreamingCollection::hkaiStreamingCollection(p, finishing);
}

// File Line: 149
// RVA: 0xBB77F0
void __fastcall cleanupLoadedObjecthkaiStreamingCollection(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 153
// RVA: 0xBB7800
hkBaseObjectVtbl *__fastcall getVtablehkaiStreamingCollection()
{
  hkaiStreamingCollection v1; // [rsp+20h] [rbp-38h] BYREF

  hkaiStreamingCollection::hkaiStreamingCollection(&v1, 0);
  return v1.vfptr;
}

// File Line: 175
// RVA: 0x15C2DF0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiStreamingCollectionTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiStreamingCollection();
  hkaiStreamingCollectionTypeInfo.m_size = 48i64;
  hkaiStreamingCollectionTypeInfo.m_typeName = "hkaiStreamingCollection";
  hkaiStreamingCollectionTypeInfo.m_vtable = result;
  hkaiStreamingCollectionTypeInfo.m_scopedName = "!hkaiStreamingCollection";
  hkaiStreamingCollectionTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiStreamingCollection;
  hkaiStreamingCollectionTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiStreamingCollection;
  return result;
}

