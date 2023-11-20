// File Line: 21
// RVA: 0x968F0
void __fastcall UFG::ActiveRegion::ActiveRegion(UFG::ActiveRegion *this, hkVector4f *extents, hkVector4f *centre)
{
  __m128 v3; // xmm0

  this->mPrev = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *)&this->mPrev;
  v3 = extents->m_quad;
  this->mExtents = (hkVector4f)extents->m_quad;
  this->mAabb.m_min.m_quad = _mm_sub_ps(centre->m_quad, v3);
  this->mAabb.m_max.m_quad = _mm_add_ps(centre->m_quad, this->mExtents.m_quad);
}

// File Line: 28
// RVA: 0xB0630
void __fastcall UFG::ActiveRegion::SetCentre(UFG::ActiveRegion *this, hkVector4f *centre)
{
  this->mAabb.m_min.m_quad = _mm_sub_ps(centre->m_quad, this->mExtents.m_quad);
  this->mAabb.m_max.m_quad = _mm_add_ps(centre->m_quad, this->mExtents.m_quad);
}

// File Line: 63
// RVA: 0x96930
void __fastcall UFG::ActiveRegionManager::ActiveRegionManager(UFG::ActiveRegionManager *this)
{
  UFG::ActiveRegionManager *v1; // rbx
  char *v2; // rax
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v3; // rcx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v4; // rax

  v1 = this;
  this->mRegions.mNode.mPrev = &this->mRegions.mNode;
  this->mRegions.mNode.mNext = &this->mRegions.mNode;
  this->mNames.p = 0i64;
  *(_QWORD *)&this->mNames.size = 0i64;
  this->mExtents.m_data = 0i64;
  this->mExtents.m_size = 0;
  this->mExtents.m_capacityAndFlags = 2147483648;
  v2 = UFG::qMalloc(0x40ui64, "ActiveRegion", 0i64);
  v3 = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *)v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = v2;
    *((_QWORD *)v2 + 1) = v2;
    *((_OWORD *)v2 + 1) = _xmm;
    *((__m128 *)v2 + 2) = _mm_sub_ps((__m128)0i64, (__m128)_xmm);
    *((__m128 *)v2 + 3) = _mm_add_ps((__m128)_xmm, (__m128)0i64);
  }
  else
  {
    v3 = 0i64;
  }
  v4 = v1->mRegions.mNode.mNext;
  v1->mRegions.mNode.mNext = v3;
  v3->mPrev = &v1->mRegions.mNode;
  v3->mNext = v4;
  v4->mPrev = v3;
}

// File Line: 74
// RVA: 0x9B330
void __fastcall UFG::ActiveRegionManager::~ActiveRegionManager(UFG::ActiveRegionManager *this)
{
  UFG::ActiveRegionManager *v1; // rdi
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v2; // rcx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v3; // rdx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v4; // rax
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v5; // rdx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v6; // rax
  int v7; // er8
  UFG::qString *v8; // rcx
  unsigned int *v9; // rbx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v10; // rcx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v11; // rax

  v1 = this;
  v2 = this->mRegions.mNode.mNext;
  v3 = v2->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  operator delete[](v2);
  v1->mExtents.m_size = 0;
  v7 = v1->mExtents.m_capacityAndFlags;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mExtents.m_data,
      16 * v7);
  v1->mExtents.m_data = 0i64;
  v1->mExtents.m_capacityAndFlags = 2147483648;
  v8 = v1->mNames.p;
  if ( v8 )
  {
    v9 = &v8[-1].mStringHash32;
    `eh vector destructor iterator'(
      v8,
      0x28ui64,
      v8[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v9);
  }
  v1->mNames.p = 0i64;
  *(_QWORD *)&v1->mNames.size = 0i64;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)v1);
  v10 = v1->mRegions.mNode.mPrev;
  v11 = v1->mRegions.mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v1->mRegions.mNode.mPrev = &v1->mRegions.mNode;
  v1->mRegions.mNode.mNext = &v1->mRegions.mNode;
}

// File Line: 82
// RVA: 0xACC90
char __fastcall UFG::ActiveRegionManager::IsInActiveRegion(UFG::ActiveRegionManager *this, hkVector4f *p)
{
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v2; // rax

  v2 = this->mRegions.mNode.mNext;
  if ( v2 == (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *)this )
    return 0;
  while ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(p->m_quad, (__m128)v2[3]), _mm_cmpleps((__m128)v2[2], p->m_quad))) & 7) != 7 )
  {
    v2 = v2->mNext;
    if ( v2 == (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *)this )
      return 0;
  }
  return 1;
}

// File Line: 112
// RVA: 0xB1440
void __fastcall UFG::ActiveRegionManager::SetModeFromSymbol(UFG::ActiveRegionManager *this, UFG::qSymbol *name)
{
  __int64 v2; // rbx
  UFG::qSymbol *v3; // r15
  UFG::ActiveRegionManager *v4; // rbp
  UFG::qString *v5; // rsi
  unsigned int v6; // er14
  __m128 *v7; // rdx
  hkVector4f *v8; // rax
  __m128 v9; // xmm0
  __m128 v10; // xmm2

  v2 = 0i64;
  v3 = name;
  v4 = this;
  if ( this->mNames.size )
  {
    while ( 1 )
    {
      v5 = v4->mNames.p;
      v6 = v3->mUID;
      if ( v5[v2].mStringHash32 == -1 )
        v5[v2].mStringHash32 = UFG::qStringHash32(v5[v2].mData, 0xFFFFFFFF);
      if ( v6 == v5[v2].mStringHash32 )
        break;
      v2 = (unsigned int)(v2 + 1);
      if ( (unsigned int)v2 >= v4->mNames.size )
        return;
    }
    v7 = (__m128 *)v4->mRegions.mNode.mNext;
    v8 = v4->mExtents.m_data;
    v4->mCurrentMode = v2;
    v9 = v8[(signed int)v2].m_quad;
    v10 = _mm_mul_ps(_mm_add_ps(v7[3], v7[2]), *(__m128 *)_xmm);
    v7[1] = v9;
    v7[3] = _mm_add_ps(v9, v10);
    v7[2] = _mm_sub_ps(v10, v9);
  }
}

// File Line: 129
// RVA: 0xB1400
void __fastcall UFG::ActiveRegionManager::SetMode(UFG::ActiveRegionManager *this, int mode)
{
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v2; // r8
  hkVector4f *v3; // rax
  __m128 v4; // xmm0
  __m128 v5; // xmm2

  v2 = this->mRegions.mNode.mNext;
  v3 = this->mExtents.m_data;
  this->mCurrentMode = mode;
  v4 = v3[mode].m_quad;
  v5 = _mm_mul_ps(_mm_add_ps((__m128)v2[3], (__m128)v2[2]), *(__m128 *)_xmm);
  v2[1] = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion>)v4;
  v2[3] = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion>)_mm_add_ps(v4, v5);
  v2[2] = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion>)_mm_sub_ps(v5, v4);
}

// File Line: 145
// RVA: 0xB0650
void __fastcall UFG::ActiveRegionManager::SetCentre(UFG::ActiveRegionManager *this, hkVector4f *centre)
{
  __m128 *v2; // rax

  v2 = (__m128 *)this->mRegions.mNode.mNext;
  v2[2] = _mm_sub_ps(centre->m_quad, v2[1]);
  v2[3] = _mm_add_ps(centre->m_quad, v2[1]);
}

// File Line: 155
// RVA: 0xA96F0
hkVector4f *__fastcall UFG::ActiveRegionManager::GetCentre(UFG::ActiveRegionManager *this, hkVector4f *result)
{
  hkVector4f *v2; // rax

  v2 = result;
  result->m_quad = _mm_mul_ps(
                     _mm_add_ps((__m128)this->mRegions.mNode.mNext[3], (__m128)this->mRegions.mNode.mNext[2]),
                     *(__m128 *)_xmm);
  return v2;
}

