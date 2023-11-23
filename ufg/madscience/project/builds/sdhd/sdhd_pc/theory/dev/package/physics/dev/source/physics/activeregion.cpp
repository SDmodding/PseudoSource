// File Line: 21
// RVA: 0x968F0
void __fastcall UFG::ActiveRegion::ActiveRegion(UFG::ActiveRegion *this, hkVector4f *extents, hkVector4f *centre)
{
  __m128 m_quad; // xmm0

  this->mPrev = this;
  this->mNext = this;
  m_quad = extents->m_quad;
  this->mExtents = (hkVector4f)extents->m_quad;
  this->mAabb.m_min.m_quad = _mm_sub_ps(centre->m_quad, m_quad);
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
  char *v2; // rax
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v3; // rcx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *mNext; // rax

  this->mRegions.mNode.mPrev = &this->mRegions.mNode;
  this->mRegions.mNode.mNext = &this->mRegions.mNode;
  this->mNames.p = 0i64;
  *(_QWORD *)&this->mNames.size = 0i64;
  this->mExtents.m_data = 0i64;
  this->mExtents.m_size = 0;
  this->mExtents.m_capacityAndFlags = 0x80000000;
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
  mNext = this->mRegions.mNode.mNext;
  this->mRegions.mNode.mNext = v3;
  v3->mPrev = &this->mRegions.mNode;
  v3->mNext = mNext;
  mNext->mPrev = v3;
}

// File Line: 74
// RVA: 0x9B330
void __fastcall UFG::ActiveRegionManager::~ActiveRegionManager(UFG::ActiveRegionManager *this)
{
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *mNext; // rcx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *mPrev; // rdx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v4; // rax
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v5; // rdx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v6; // rax
  int m_capacityAndFlags; // r8d
  UFG::qString *p; // rcx
  unsigned int *p_mStringHash32; // rbx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v10; // rcx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v11; // rax

  mNext = this->mRegions.mNode.mNext;
  mPrev = mNext->mPrev;
  v4 = mNext->mNext;
  mPrev->mNext = v4;
  v4->mPrev = mPrev;
  mNext->mPrev = mNext;
  mNext->mNext = mNext;
  v5 = mNext->mPrev;
  v6 = mNext->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  mNext->mPrev = mNext;
  mNext->mNext = mNext;
  operator delete[](mNext);
  this->mExtents.m_size = 0;
  m_capacityAndFlags = this->mExtents.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mExtents.m_data,
      16 * m_capacityAndFlags);
  this->mExtents.m_data = 0i64;
  this->mExtents.m_capacityAndFlags = 0x80000000;
  p = this->mNames.p;
  if ( p )
  {
    p_mStringHash32 = &p[-1].mStringHash32;
    `eh vector destructor iterator(
      p,
      0x28ui64,
      p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
  this->mNames.p = 0i64;
  *(_QWORD *)&this->mNames.size = 0i64;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)this);
  v10 = this->mRegions.mNode.mPrev;
  v11 = this->mRegions.mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->mRegions.mNode.mPrev = &this->mRegions.mNode;
  this->mRegions.mNode.mNext = &this->mRegions.mNode;
}

// File Line: 82
// RVA: 0xACC90
char __fastcall UFG::ActiveRegionManager::IsInActiveRegion(UFG::ActiveRegionManager *this, hkVector4f *p)
{
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *mNext; // rax

  mNext = this->mRegions.mNode.mNext;
  if ( mNext == (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *)this )
    return 0;
  while ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(p->m_quad, (__m128)mNext[3]), _mm_cmple_ps((__m128)mNext[2], p->m_quad))) & 7) != 7 )
  {
    mNext = mNext->mNext;
    if ( mNext == (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *)this )
      return 0;
  }
  return 1;
}

// File Line: 112
// RVA: 0xB1440
void __fastcall UFG::ActiveRegionManager::SetModeFromSymbol(UFG::ActiveRegionManager *this, UFG::qSymbol *name)
{
  __int64 v2; // rbx
  UFG::qString *p; // rsi
  unsigned int mUID; // r14d
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *mNext; // rdx
  hkVector4f *m_data; // rax
  __m128 m_quad; // xmm0
  __m128 v10; // xmm2

  v2 = 0i64;
  if ( this->mNames.size )
  {
    while ( 1 )
    {
      p = this->mNames.p;
      mUID = name->mUID;
      if ( p[v2].mStringHash32 == -1 )
        p[v2].mStringHash32 = UFG::qStringHash32(p[v2].mData, 0xFFFFFFFF);
      if ( mUID == p[v2].mStringHash32 )
        break;
      v2 = (unsigned int)(v2 + 1);
      if ( (unsigned int)v2 >= this->mNames.size )
        return;
    }
    mNext = this->mRegions.mNode.mNext;
    m_data = this->mExtents.m_data;
    this->mCurrentMode = v2;
    m_quad = m_data[(int)v2].m_quad;
    v10 = _mm_mul_ps(_mm_add_ps((__m128)mNext[3], (__m128)mNext[2]), *(__m128 *)_xmm);
    mNext[1] = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion>)m_quad;
    mNext[3] = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion>)_mm_add_ps(m_quad, v10);
    mNext[2] = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion>)_mm_sub_ps(v10, m_quad);
  }
}

// File Line: 129
// RVA: 0xB1400
void __fastcall UFG::ActiveRegionManager::SetMode(UFG::ActiveRegionManager *this, unsigned int mode)
{
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *mNext; // r8
  hkVector4f *m_data; // rax
  __m128 m_quad; // xmm0
  __m128 v5; // xmm2

  mNext = this->mRegions.mNode.mNext;
  m_data = this->mExtents.m_data;
  this->mCurrentMode = mode;
  m_quad = m_data[mode].m_quad;
  v5 = _mm_mul_ps(_mm_add_ps((__m128)mNext[3], (__m128)mNext[2]), *(__m128 *)_xmm);
  mNext[1] = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion>)m_quad;
  mNext[3] = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion>)_mm_add_ps(m_quad, v5);
  mNext[2] = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion>)_mm_sub_ps(v5, m_quad);
}

// File Line: 145
// RVA: 0xB0650
void __fastcall UFG::ActiveRegionManager::SetCentre(UFG::ActiveRegionManager *this, hkVector4f *centre)
{
  __m128 *mNext; // rax

  mNext = (__m128 *)this->mRegions.mNode.mNext;
  mNext[2] = _mm_sub_ps(centre->m_quad, mNext[1]);
  mNext[3] = _mm_add_ps(centre->m_quad, mNext[1]);
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

