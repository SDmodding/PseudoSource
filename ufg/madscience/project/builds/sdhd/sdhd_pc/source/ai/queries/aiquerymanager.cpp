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
  UFG::qList<UFG::AICoverQuery,UFG::AICoverQuery,1,0> *v1; // rdi
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v2; // rbx
  UFG::AIQueryManager *i; // rsi
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v4; // rcx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v5; // rdx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v6; // rcx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v7; // rax
  bool v8; // zf
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v9; // rcx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v10; // rcx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v11; // rax

  v1 = &this->m_listpCoverQueries;
  v2 = this->m_listpCoverQueries.mNode.mNext - 2;
  for ( i = this - 1; v2 != (UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *)i; v2 = v1->mNode.mNext - 2 )
  {
    v4 = v2[14].mNext;
    if ( v4 || v2[15].mPrev )
      ((void (__fastcall *)(UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *, UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *))v2[15].mPrev)(
        v4,
        v2);
    v5 = v2 + 2;
    v6 = v2[2].mPrev;
    v7 = v2[2].mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = v5;
    v5->mNext = v5;
    v8 = LODWORD(v2[1].mNext)-- == 1;
    if ( v8 )
      ((void (__fastcall *)(UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *, signed __int64))v2->mPrev->mPrev)(
        v2,
        1i64);
  }
  v9 = v1[1].mNode.mNext;
  if ( v9 )
    operator delete[](v9);
  v1[1].mNode.mNext = 0i64;
  v1[1].mNode.mPrev = 0i64;
  UFG::qList<UFG::AICoverQuery,UFG::AICoverQuery,1,0>::DeleteNodes(v1);
  v10 = v1->mNode.mPrev;
  v11 = v1->mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
}

// File Line: 55
// RVA: 0x389720
void __fastcall UFG::AIQueryManager::SubmitQuery(UFG::AIQueryManager *this, UFG::AIQuery *pAIQuery)
{
  __int64 v2; // rbp
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v3; // rdi
  UFG::AIQuery *v4; // rsi
  unsigned int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::qReflectInventoryBase **v8; // rax

  ++pAIQuery->m_iRefCount;
  v2 = this->m_apQueries.size;
  v3 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_apQueries;
  v4 = pAIQuery;
  v5 = this->m_apQueries.capacity;
  v6 = v2 + 1;
  if ( (signed int)v2 + 1 > v5 )
  {
    if ( v5 )
      v7 = 2 * v5;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = v2 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v3, v7, "qArray.Add");
  }
  v8 = v3->p;
  v3->size = v6;
  v8[v2] = (UFG::qReflectInventoryBase *)v4;
}

// File Line: 62
// RVA: 0x34CD00
void __fastcall UFG::AIQueryManager::CancelQuery(UFG::AIQueryManager *this, UFG::AIQuery *pQueryToCancel)
{
  UFG::AIQueryManager *v2; // r9
  unsigned int v3; // ecx
  __int64 v4; // r8
  UFG::AIQuery *v5; // r10
  int v6; // er8
  signed __int64 v7; // rdx
  unsigned int v8; // eax
  bool v9; // zf

  v2 = this;
  v3 = this->m_apQueries.size;
  v4 = 0i64;
  v5 = pQueryToCancel;
  if ( v3 )
  {
    while ( pQueryToCancel != v2->m_apQueries.p[v4] )
    {
      v4 = (unsigned int)(v4 + 1);
      if ( (unsigned int)v4 >= v3 )
        return;
    }
    if ( (signed int)v4 >= 0 )
    {
      v6 = v4 + 1;
      if ( v6 != v3 )
      {
        v7 = v6;
        do
        {
          ++v6;
          ++v7;
          v2->m_apQueries.p[v7 - 2] = v2->m_apQueries.p[v7 - 1];
        }
        while ( v6 != v2->m_apQueries.size );
      }
      v8 = v2->m_apQueries.size;
      if ( v8 > 1 )
        v2->m_apQueries.size = v8 - 1;
      else
        v2->m_apQueries.size = 0;
      v9 = v5->m_iRefCount-- == 1;
      if ( v9 )
        v5->vfptr->__vecDelDtor(v5, 1u);
    }
  }
}

// File Line: 98
// RVA: 0x38C2E0
void __fastcall UFG::AIQueryManager::Update(UFG::AIQueryManager *this)
{
  UFG::AIQueryManager *v1; // rbx
  UFG::allocator::free_link *v2; // r13
  unsigned int v3; // er15
  unsigned int v4; // er12
  unsigned __int64 v5; // rdi
  UFG::PlayerCoverComponent *v6; // rax
  float v7; // xmm0_4
  __int64 v8; // rsi
  unsigned int v9; // edi
  signed __int64 v10; // rbp
  unsigned __int64 v11; // r13
  unsigned __int64 v12; // rax
  UFG::AIQuery *v13; // r14
  __int64 v14; // r8
  signed __int64 v15; // rdx
  unsigned int v16; // eax
  bool v17; // zf
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v18; // rsi
  signed __int64 v19; // rbx
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
  UFG::allocator::free_link *v31; // rbx
  UFG::allocator::free_link *v32; // rcx
  UFG::allocator::free_link *v33; // r8
  UFG::allocator::free_link *v34; // rdx
  UFG::allocator::free_link *v35; // rax
  float v36; // [rsp+80h] [rbp+8h]
  unsigned __int64 start; // [rsp+88h] [rbp+10h]
  __int64 i; // [rsp+90h] [rbp+18h]

  v1 = this;
  v2 = 0i64;
  v3 = 0;
  v4 = 0;
  v36 = FLOAT_0_001;
  v5 = UFG::qGetTicks();
  start = v5;
  if ( LocalPlayer )
  {
    v6 = (UFG::PlayerCoverComponent *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&LocalPlayer->vfptr,
                                        UFG::PlayerCoverComponent::_TypeUID);
    if ( v6 )
      UFG::PlayerCoverComponent::UpdateCoverQuery(v6);
  }
  if ( !(_S70 & 1) )
  {
    _S70 |= 1u;
    if ( (UFG::AIQueryManager *)&v1->m_listpCoverQueries.mNode.mNext[-2] == &v1[-1] )
      v7 = FLOAT_0_001;
    else
      v7 = FLOAT_0_00050000002;
    fNumSecondsForStandardQueries = v7;
  }
  v8 = 0i64;
  if ( v1->m_apQueries.size )
  {
    v9 = 1;
    v10 = 8i64;
    v11 = start;
    do
    {
      v12 = UFG::qGetTicks();
      if ( UFG::qGetTickTime(v11, v12) > fNumSecondsForStandardQueries )
        break;
      v13 = v1->m_apQueries.p[v8];
      if ( !v13->vfptr->Update(v1->m_apQueries.p[v8], &v36, 0) )
      {
        v14 = v9;
        if ( v9 != v1->m_apQueries.size )
        {
          v15 = v10;
          do
          {
            *(UFG::AIQuery **)((char *)v1->m_apQueries.p + v15 - 8) = *(UFG::AIQuery **)((char *)v1->m_apQueries.p + v15);
            v14 = (unsigned int)(v14 + 1);
            v15 += 8i64;
          }
          while ( (_DWORD)v14 != v1->m_apQueries.size );
        }
        v16 = v1->m_apQueries.size;
        if ( v16 > 1 )
          v1->m_apQueries.size = v16 - 1;
        else
          v1->m_apQueries.size = 0;
        LODWORD(v8) = v8 - 1;
        --v9;
        v10 -= 8i64;
        v17 = v13->m_iRefCount-- == 1;
        if ( v17 )
          ((void (__fastcall *)(UFG::AIQuery *, signed __int64, __int64))v13->vfptr->__vecDelDtor)(v13, 1i64, v14);
      }
      v8 = (unsigned int)(v8 + 1);
      ++v9;
      v10 += 8i64;
    }
    while ( (unsigned int)v8 < v1->m_apQueries.size );
    v2 = 0i64;
    v5 = start;
  }
  v18 = v1->m_listpCoverQueries.mNode.mNext - 2;
  v19 = (signed __int64)&v1[-1];
  for ( i = v19; v18 != (UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *)v19; v18 = v18[2].mNext - 2 )
  {
    v20 = UFG::qGetTicks();
    if ( UFG::qGetTickTime(v5, v20) > 0.001 )
      break;
    if ( !((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *, float *, _QWORD))v18->mPrev->mNext)(
            v18,
            &v36,
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
      v5 = start;
    }
  }
  if ( v3 )
  {
    v29 = v2;
    v30 = v3;
    do
    {
      v31 = v29->mNext;
      v32 = v29->mNext[29].mNext;
      if ( v32 || v31[30].mNext )
        ((void (__fastcall *)(UFG::allocator::free_link *, UFG::allocator::free_link *))v31[30].mNext)(v32, v29->mNext);
      v33 = v31 + 4;
      v34 = v31[4].mNext;
      v35 = v31[5].mNext;
      v34[1].mNext = v35;
      v35->mNext = v34;
      v33->mNext = v33;
      v33[1].mNext = v33;
      v17 = LODWORD(v31[3].mNext)-- == 1;
      if ( v17 )
        ((void (__fastcall *)(UFG::allocator::free_link *, signed __int64))v31->mNext->mNext)(v31, 1i64);
      ++v29;
      --v30;
    }
    while ( v30 );
  }
  if ( v2 )
    operator delete[](v2);
}

