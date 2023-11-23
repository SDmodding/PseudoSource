// File Line: 66
// RVA: 0x15C85F0
void dynamic_initializer_for__hkcdSimdTreeNodeClass__()
{
  hkClass::hkClass(
    &hkcdSimdTreeNodeClass,
    "hkcdSimdTreeNode",
    &hkcdFourAabbClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkcdSimdTree_NodeClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 69
// RVA: 0xC8E610
hkClass *__fastcall hkcdSimdTree::Node::staticClass()
{
  return &hkcdSimdTreeNodeClass;
}

// File Line: 76
// RVA: 0xC8E620
void __fastcall finishLoadedObjecthkcdSimdTreeNode(void *p, int finishing)
{
  ;
}

// File Line: 82
// RVA: 0xC8E630
void __fastcall cleanupLoadedObjecthkcdSimdTreeNode(void *p)
{
  ;
}

// File Line: 120
// RVA: 0x15C8590
void dynamic_initializer_for__hkcdSimdTreeClass__()
{
  hkClass::hkClass(
    &hkcdSimdTreeClass,
    "hkcdSimdTree",
    0i64,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkcdSimdTreeClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 123
// RVA: 0xC8E600
hkClass *__fastcall hkcdSimdTree::staticClass()
{
  return &hkcdSimdTreeClass;
}

// File Line: 130
// RVA: 0xC8E640
void __fastcall finishLoadedObjecthkcdSimdTree(void *p, int finishing)
{
  ;
}

// File Line: 136
// RVA: 0xC8E650
void __fastcall cleanupLoadedObjecthkcdSimdTree(_DWORD *p)
{
  int v1; // r8d

  v1 = p[3];
  p[2] = 0;
  if ( v1 < 0 )
  {
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)p,
      112 * (v1 & 0x3FFFFFFF));
    *(_QWORD *)p = 0i64;
    p[3] = 0x80000000;
  }
}

