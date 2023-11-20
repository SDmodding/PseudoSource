// File Line: 53
// RVA: 0x15C92A0
void dynamic_initializer_for__hkcdDynamicAabbTreeClass__()
{
  hkClass::hkClass(
    &hkcdDynamicAabbTreeClass,
    "hkcdDynamicAabbTree",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkcdDynamicAabbTree::Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 56
// RVA: 0xC8F450
hkClass *__fastcall hkcdDynamicAabbTree::staticClass()
{
  return &hkcdDynamicAabbTreeClass;
}

// File Line: 63
// RVA: 0xC8F460
void __fastcall finishLoadedObjecthkcdDynamicAabbTree(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkcdDynamicAabbTree::hkcdDynamicAabbTree);
}

// File Line: 69
// RVA: 0xC8F480
void __fastcall cleanupLoadedObjecthkcdDynamicAabbTree(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 73
// RVA: 0xC8F490
hkBaseObjectVtbl *__fastcall getVtablehkcdDynamicAabbTree()
{
  hkcdDynamicAabbTree v1; // [rsp+20h] [rbp-28h]

  hkcdDynamicAabbTree::hkcdDynamicAabbTree(&v1, 0);
  return v1.vfptr;
}

// File Line: 95
// RVA: 0x15C9310
hkBaseObjectVtbl *dynamic_initializer_for__hkcdDynamicAabbTreeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkcdDynamicAabbTree();
  hkcdDynamicAabbTreeTypeInfo.m_size = 32i64;
  hkcdDynamicAabbTreeTypeInfo.m_typeName = "hkcdDynamicAabbTree";
  hkcdDynamicAabbTreeTypeInfo.m_vtable = result;
  hkcdDynamicAabbTreeTypeInfo.m_scopedName = "!hkcdDynamicAabbTree";
  hkcdDynamicAabbTreeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkcdDynamicAabbTree;
  hkcdDynamicAabbTreeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkcdDynamicAabbTree;
  return result;
}

