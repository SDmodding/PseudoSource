// File Line: 53
// RVA: 0x15C9370
void dynamic_initializer_for__hkcdStaticAabbTreeClass__()
{
  hkClass::hkClass(
    &hkcdStaticAabbTreeClass,
    "hkcdStaticAabbTree",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticAabbTree::Members,
    2,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 56
// RVA: 0xC8F4B0
hkClass *__fastcall hkcdStaticAabbTree::staticClass()
{
  return &hkcdStaticAabbTreeClass;
}

// File Line: 63
// RVA: 0xC8F4C0
void __fastcall finishLoadedObjecthkcdStaticAabbTree(hkcdStaticAabbTree *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkcdStaticAabbTree::hkcdStaticAabbTree(p, finishing);
}

// File Line: 69
// RVA: 0xC8F4E0
void __fastcall cleanupLoadedObjecthkcdStaticAabbTree(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 73
// RVA: 0xC8F4F0
hkBaseObjectVtbl *__fastcall getVtablehkcdStaticAabbTree()
{
  hkcdStaticAabbTree v1; // [rsp+20h] [rbp-28h] BYREF

  hkcdStaticAabbTree::hkcdStaticAabbTree(&v1, 0);
  return v1.vfptr;
}

// File Line: 95
// RVA: 0x15C93E0
hkBaseObjectVtbl *dynamic_initializer_for__hkcdStaticAabbTreeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkcdStaticAabbTree();
  hkcdStaticAabbTreeTypeInfo.m_size = 32i64;
  hkcdStaticAabbTreeTypeInfo.m_typeName = "hkcdStaticAabbTree";
  hkcdStaticAabbTreeTypeInfo.m_vtable = result;
  hkcdStaticAabbTreeTypeInfo.m_scopedName = "!hkcdStaticAabbTree";
  hkcdStaticAabbTreeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkcdStaticAabbTree;
  hkcdStaticAabbTreeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkcdStaticAabbTree;
  return result;
}

