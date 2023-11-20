// File Line: 22
// RVA: 0xC95250
void __fastcall hkcdStaticAabbTree::hkcdStaticAabbTree(hkcdStaticAabbTree *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_treePtr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkcdStaticAabbTree::`vftable';
  this->m_shouldDeleteTree.m_bool = 1;
}

// File Line: 27
// RVA: 0xC95280
void __fastcall hkcdStaticAabbTree::hkcdStaticAabbTree(hkcdStaticAabbTree *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkcdStaticAabbTree::`vftable';
  if ( f.m_finishing )
    this->m_shouldDeleteTree.m_bool = this->m_memSizeAndFlags != 0;
}

// File Line: 35
// RVA: 0xC952B0
void __fastcall hkcdStaticAabbTree::~hkcdStaticAabbTree(hkcdStaticAabbTree *this)
{
  hkcdStaticAabbTree *v1; // rbx
  hkcdStaticTree::DefaultTreeStorage6 *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkcdStaticAabbTree::`vftable';
  v2 = (hkcdStaticTree::DefaultTreeStorage6 *)this->m_treePtr;
  if ( v2 && v1->m_shouldDeleteTree.m_bool )
    hkcdStaticTree::DefaultTreeStorage6::`scalar deleting destructor'(v2, 1);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 43
// RVA: 0xC95300
void __fastcall hkcdStaticAabbTree::buildFromDynamicTree(hkcdStaticAabbTree *this, hkcdDynamicAabbTree *dynTree)
{
  void **v2; // rbx
  hkcdDynamicAabbTree *v3; // rsi
  hkcdStaticAabbTree *v4; // rdi
  int v5; // eax
  _QWORD **v6; // rax
  _QWORD **v7; // rax
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6> *v8; // rax

  v2 = (void **)this->m_treePtr;
  v3 = dynTree;
  v4 = this;
  if ( v2 )
  {
    v5 = *((_DWORD *)v2 + 3);
    *((_DWORD *)v2 + 2) = 0;
    if ( v5 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *v2,
        6 * (v5 & 0x3FFFFFFF));
    *v2 = 0i64;
    *((_DWORD *)v2 + 3) = 2147483648;
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void **, signed __int64))(*v6[11] + 16i64))(v6[11], v2, 48i64);
  }
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6> *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(
                                                                  v7[11],
                                                                  48i64);
  if ( v8 )
  {
    v8->m_nodes.m_data = 0i64;
    v8->m_nodes.m_size = 0;
    v8->m_nodes.m_capacityAndFlags = 2147483648;
    v8->m_domain.m_min = (hkVector4f)xmmword_141A712A0;
    v8->m_domain.m_max.m_quad = _mm_xor_ps(
                                  (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                  v8->m_domain.m_min.m_quad);
  }
  else
  {
    v8 = 0i64;
  }
  v4->m_treePtr = v8;
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6>::convertFromDynamicTree<hkcdDynamicTree::DefaultTree48Storage>(
    v8,
    (hkcdDynamicTree::DefaultTree48Storage *)v3->m_treePtr);
}

// File Line: 54
// RVA: 0xC95490
signed __int64 __fastcall hkcdStaticAabbTree::getMemoryFootPrint(hkcdStaticAabbTree *this)
{
  return 6 * (*((unsigned int *)this->m_treePtr + 2) + 8i64);
}

// File Line: 60
// RVA: 0xC954B0
__int64 __fastcall hkcdStaticAabbTree::getNumLeaves(hkcdStaticAabbTree *this)
{
  return (*((_DWORD *)this->m_treePtr + 2) + 1) / 2;
}

// File Line: 66
// RVA: 0xC95400
unsigned int __fastcall hkcdStaticAabbTree::castRay(hkcdStaticAabbTree *this, hkVector4f *start, hkVector4f *end, hkcdAabbTreeQueries::RaycastCollector *collector)
{
  return hkcdAabbTree_castRay<hkcdStaticTree::DefaultTreeStorage6>(this->m_treePtr, start, end, collector);
}

// File Line: 72
// RVA: 0xC95410
void __fastcall hkcdStaticAabbTree::queryAabb(hkcdStaticAabbTree *this, hkAabb *aabb, hkcdAabbTreeQueries::AabbCollector *collector)
{
  hkcdAabbTree_queryAabb<hkcdStaticTree::DefaultTreeStorage6>(this->m_treePtr, aabb, collector);
}

// File Line: 78
// RVA: 0xC95420
void __fastcall hkcdStaticAabbTree::queryAabb(hkcdStaticAabbTree *this, hkAabb *aabb, hkArray<unsigned int,hkContainerTempAllocator> *hits)
{
  hkResult result; // [rsp+30h] [rbp+8h]

  hkcdAabbTree_queryAabbHits<hkcdStaticTree::DefaultTreeStorage6>(&result, this->m_treePtr, aabb, hits);
}

// File Line: 84
// RVA: 0xC95450
unsigned int __fastcall hkcdStaticAabbTree::getClosestPoint(hkcdStaticAabbTree *this, hkVector4f *point, hkSimdFloat32 *maxDistance, hkcdAabbTreeQueries::ClosestPointCollector *collector, hkVector4f *closestPointOut)
{
  return hkcdAabbTree_getClosestPoint<hkcdStaticTree::DefaultTreeStorage6>(
           this->m_treePtr,
           point,
           maxDistance,
           collector,
           closestPointOut);
}

// File Line: 90
// RVA: 0xC95460
void __fastcall hkcdStaticAabbTree::getAllPairs(hkcdStaticAabbTree *this, hkcdAabbTreeQueries::AllPairsCollector *collector)
{
  hkcdAabbTree_getAllPairs<hkcdStaticTree::DefaultTreeStorage6>(this->m_treePtr, collector);
}

// File Line: 95
// RVA: 0xC95470
void __fastcall hkcdStaticAabbTree::getAllPairs(hkcdStaticAabbTree *this, hkcdStaticAabbTree *otherTree, hkcdAabbTreeQueries::AllPairsCollector *collector)
{
  hkcdAabbTree_getAllPairs<hkcdStaticTree::DefaultTreeStorage6>(this->m_treePtr, otherTree->m_treePtr, collector);
}

