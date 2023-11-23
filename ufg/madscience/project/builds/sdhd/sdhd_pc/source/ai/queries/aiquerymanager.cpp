// File Line: 25
// RVA: 0x32BB80
void __fastcall UFG::AIQueryManager::AIQueryManager(UFG::AIQueryManager *this)
{
  this->m_listpCoverQueries.mNode.mPrev = &this->m_listpCoverQueries.mNode;
  this->m_listpCoverQueries.mNode.mNext = &this->m_listpCoverQueries.mNode;
  this->m_apQueries.p = 0i64;
  *(_QWORD *)&this->m_apQueries.size = 0i64;
}

// File Line: 40
// RVA: 0x3347F0
void __fastcall UFG::AIQueryManager::~AIQueryManager(UFG::AIQueryManager *this)
{
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v2; // rbx
  UFG::AIQueryManager *i; // rsi
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *mNext; // rcx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *mPrev; // rcx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v6; // rax
  UFG::AIQuery **p; // rcx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v9; // rcx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v10; // rax

  v2 = this->m_listpCoverQueries.mNode.mNext - 2;
  for ( i = this - 1;
        v2 != (UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *)i;
        v2 = this->m_listpCoverQueries.mNode.mNext - 2 )
  {
    mNext = v2[14].mNext;
    if ( mNext || v2[15].mPrev )
      ((void (__fastcall *)(UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *, UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *))v2[15].mPrev)(
        mNext,
        v2);
    mPrev = v2[2].mPrev;
    v6 = v2[2].mNext;
    mPrev->mNext = v6;
    v6->mPrev = mPrev;
    v2[2].mPrev = v2 + 2;
    v2[2].mNext = v2 + 2;
    if ( LODWORD(v2[1].mNext)-- == 1 )
      ((void (__fastcall *)(UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *, __int64))v2->mPrev->mPrev)(v2, 1i64);
  }
  p = this->m_apQueries.p;
  if ( p )
    operator delete[](p);
  this->m_apQueries.p = 0i64;
  *(_QWORD *)&this->m_apQueries.size = 0i64;
  UFG::qList<UFG::AICoverQuery,UFG::AICoverQuery,1,0>::DeleteNodes(&this->m_listpCoverQueries);
  v9 = this->m_listpCoverQueries.mNode.mPrev;
  v10 = this->m_listpCoverQueries.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  this->m_listpCoverQueries.mNode.mPrev = &this->m_listpCoverQueries.mNode;
  this->m_listpCoverQueries.mNode.mNext = &this->m_listpCoverQueries.mNode;
}

// File Line: 55
// RVA: 0x389720
void __fastcall UFG::AIQueryManager::SubmitQuery(UFG::AIQueryManager *this, UFG::qReflectInventoryBase *pAIQuery)
{
  __int64 size; // rbp
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_m_apQueries; // rdi
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::qReflectInventoryBase **p; // rax

  ++LODWORD(pAIQuery->mBaseNode.mChildren[0]);
  size = this->m_apQueries.size;
  p_m_apQueries = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_apQueries;
  capacity = this->m_apQueries.capacity;
  v6 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_m_apQueries, v7, "qArray.Add");
  }
  p = p_m_apQueries->p;
  p_m_apQueries->size = v6;
  p[size] = pAIQuery;
}

// File Line: 62
// RVA: 0x34CD00
void __fastcall UFG::AIQueryManager::CancelQuery(UFG::AIQueryManager *this, UFG::AIQuery *pQueryToCancel)
{
  unsigned int size; // ecx
  __int64 v4; // r8
  int v6; // r8d
  __int64 v7; // rdx
  unsigned int v8; // eax

  size = this->m_apQueries.size;
  v4 = 0i64;
  if ( size )
  {
    while ( pQueryToCancel != this->m_apQueries.p[v4] )
    {
      v4 = (unsigned int)(v4 + 1);
      if ( (unsigned int)v4 >= size )
        return;
    }
    if ( (int)v4 >= 0 )
    {
      v6 = v4 + 1;
      if ( v6 != size )
      {
        v7 = v6;
        do
        {
          ++v6;
          ++v7;
          this->m_apQueries.p[v7 - 2] = this->m_apQueries.p[v7 - 1];
        }
        while ( v6 != this->m_apQueries.size );
      }
      v8 = this->m_apQueries.size;
      if ( v8 > 1 )
        this->m_apQueries.size = v8 - 1;
      else
        this->m_apQueries.size = 0;
      if ( pQueryToCancel->m_iRefCount-- == 1 )
        pQueryToCancel->vfptr->__vecDelDtor(pQueryToCancel, 1i64);
    }
  }
}

// File Line: 98
// RVA: 0x38C2E0
void __fastcall UFG::AIQueryManager::Update(UFG::AIQueryManager *this)
{
  UFG::allocator::free_link *v2; // r13
  unsigned int v3; // r15d
  unsigned int v4; // r12d
  unsigned __int64 Ticks; // rdi
  UFG::PlayerCoverComponent *ComponentOfType; // rax
  float v7; // xmm0_4
  __int64 v8; // rsi
  unsigned int v9; // edi
  __int64 v10; // rbp
  unsigned __int64 v11; // r13
  unsigned __int64 v12; // rax
  UFG::AIQuery *v13; // r14
  __int64 v14; // r8
  __int64 v15; // rdx
  unsigned int size; // eax
  bool v17; // zf
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v18; // rsi
  UFG::AIQueryManager *v19; // rbx
  unsigned __int64 v20; // rax
  __int64 v21; // r14
  unsigned int v22; // edi
  unsigned int v23; // ebx
  unsigned __int64 v24; // rax
  UFG::allocator::free_link *v25; // rax
  UFG::allocator::free_link *v26; // rbp
  UFG::allocator::free_link *v27; // rdx
  __int64 v28; // r8
  UFG::allocator::free_link *v29; // rdi
  __int64 v30; // rsi
  UFG::allocator::free_link *mNext; // rbx
  UFG::allocator::free_link *v32; // rcx
  UFG::allocator::free_link *v33; // rdx
  UFG::allocator::free_link *v34; // rax
  float v35; // [rsp+80h] [rbp+8h] BYREF
  unsigned __int64 start; // [rsp+88h] [rbp+10h]
  UFG::AIQueryManager *i; // [rsp+90h] [rbp+18h]

  v2 = 0i64;
  v3 = 0;
  v4 = 0;
  v35 = FLOAT_0_001;
  Ticks = UFG::qGetTicks();
  start = Ticks;
  if ( LocalPlayer )
  {
    ComponentOfType = (UFG::PlayerCoverComponent *)UFG::SimObject::GetComponentOfType(
                                                     LocalPlayer,
                                                     UFG::PlayerCoverComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::PlayerCoverComponent::UpdateCoverQuery(ComponentOfType);
  }
  if ( (_S70 & 1) == 0 )
  {
    _S70 |= 1u;
    if ( (UFG::AIQueryManager *)&this->m_listpCoverQueries.mNode.mNext[-2] == &this[-1] )
      v7 = FLOAT_0_001;
    else
      v7 = FLOAT_0_00050000002;
    fNumSecondsForStandardQueries = v7;
  }
  v8 = 0i64;
  if ( this->m_apQueries.size )
  {
    v9 = 1;
    v10 = 8i64;
    v11 = start;
    do
    {
      v12 = UFG::qGetTicks();
      if ( UFG::qGetTickTime(v11, v12) > fNumSecondsForStandardQueries )
        break;
      v13 = this->m_apQueries.p[v8];
      if ( !v13->vfptr->Update(v13, &v35, 0) )
      {
        v14 = v9;
        if ( v9 != this->m_apQueries.size )
        {
          v15 = v10;
          do
          {
            *(UFG::AIQuery **)((char *)this->m_apQueries.p + v15 - 8) = *(UFG::AIQuery **)((char *)this->m_apQueries.p
                                                                                         + v15);
            v14 = (unsigned int)(v14 + 1);
            v15 += 8i64;
          }
          while ( (_DWORD)v14 != this->m_apQueries.size );
        }
        size = this->m_apQueries.size;
        if ( size > 1 )
          this->m_apQueries.size = size - 1;
        else
          this->m_apQueries.size = 0;
        LODWORD(v8) = v8 - 1;
        --v9;
        v10 -= 8i64;
        v17 = v13->m_iRefCount-- == 1;
        if ( v17 )
          ((void (__fastcall *)(UFG::AIQuery *, __int64, __int64))v13->vfptr->__vecDelDtor)(v13, 1i64, v14);
      }
      v8 = (unsigned int)(v8 + 1);
      ++v9;
      v10 += 8i64;
    }
    while ( (unsigned int)v8 < this->m_apQueries.size );
    v2 = 0i64;
    Ticks = start;
  }
  v18 = this->m_listpCoverQueries.mNode.mNext - 2;
  v19 = this - 1;
  for ( i = v19; v18 != (UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *)v19; v18 = v18[2].mNext - 2 )
  {
    v20 = UFG::qGetTicks();
    if ( UFG::qGetTickTime(Ticks, v20) > 0.001 )
      break;
    if ( !((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *, float *, _QWORD))v18->mPrev->mNext)(
            v18,
            &v35,
            0i64) )
    {
      v21 = v3;
      v22 = v3 + 1;
      if ( v3 + 1 > v4 )
      {
        v23 = 1;
        if ( v4 )
          v23 = 2 * v4;
        for ( ; v23 < v22; v23 *= 2 )
          ;
        if ( v23 <= 2 )
          v23 = 2;
        if ( v23 - v22 > 0x10000 )
          v23 = v3 + 65537;
        if ( v23 != v3 )
        {
          v24 = 8i64 * v23;
          if ( !is_mul_ok(v23, 8ui64) )
            v24 = -1i64;
          v25 = UFG::qMalloc(v24, "qArray.Add", 0i64);
          v26 = v25;
          if ( v2 )
          {
            if ( v3 )
            {
              v27 = v25;
              v28 = v3;
              do
              {
                v27->mNext = *(UFG::allocator::free_link **)((char *)v27 + (char *)v2 - (char *)v25);
                ++v27;
                --v28;
              }
              while ( v28 );
            }
            operator delete[](v2);
          }
          v2 = v26;
          v4 = v23;
        }
        v19 = i;
      }
      ++v3;
      v2[v21].mNext = (UFG::allocator::free_link *)v18;
      Ticks = start;
    }
  }
  if ( v3 )
  {
    v29 = v2;
    v30 = v3;
    do
    {
      mNext = v29->mNext;
      v32 = v29->mNext[29].mNext;
      if ( v32 || mNext[30].mNext )
        ((void (__fastcall *)(UFG::allocator::free_link *, UFG::allocator::free_link *))mNext[30].mNext)(
          v32,
          v29->mNext);
      v33 = mNext[4].mNext;
      v34 = mNext[5].mNext;
      v33[1].mNext = v34;
      v34->mNext = v33;
      mNext[4].mNext = mNext + 4;
      mNext[5].mNext = mNext + 4;
      v17 = LODWORD(mNext[3].mNext)-- == 1;
      if ( v17 )
        ((void (__fastcall *)(UFG::allocator::free_link *, __int64))mNext->mNext->mNext)(mNext, 1i64);
      ++v29;
      --v30;
    }
    while ( v30 );
  }
  if ( v2 )
    operator delete[](v2);
}

