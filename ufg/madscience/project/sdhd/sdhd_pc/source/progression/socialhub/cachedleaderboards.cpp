// File Line: 43
// RVA: 0x4AB5C0
UFG::CachedLeaderboardManager *__fastcall UFG::CachedLeaderboardManager::Instance()
{
  if ( (_S15_1 & 1) == 0 )
  {
    _S15_1 |= 1u;
    instance_5.m_lLeaderboards.mNode.mPrev = (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)&instance_5;
    instance_5.m_lLeaderboards.mNode.mNext = (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)&instance_5;
    instance_5.m_bIsCachedLeaderboardBuilt = 0;
    atexit(UFG::CachedLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  return &instance_5;
}

// File Line: 49
// RVA: 0x495890
void __fastcall UFG::CachedLeaderboardManager::BuildCachedLeaderboard(UFG::CachedLeaderboardManager *this)
{
  UFG::OSuiteLeaderboardManager *v2; // r15
  unsigned int size; // r12d
  unsigned int v4; // esi
  __int64 v5; // rbp
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v6; // rbx
  __int64 v7; // rdi
  UFG::StatGamePropertyManager *p_mNext; // rax
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *mPrev; // rax

  if ( !this->m_bIsCachedLeaderboardBuilt )
  {
    v2 = UFG::OSuiteLeaderboardManager::Instance();
    size = v2->mLeaderboardData.size;
    v4 = 0;
    if ( size )
    {
      v5 = 0i64;
      do
      {
        if ( v2->mLeaderboardData.p[v5].mCategory == LeaderboardCategory_StatGame )
        {
          v6 = (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)UFG::qMalloc(
                                                                              0x30ui64,
                                                                              "CachedLeaderboardManager",
                                                                              0i64);
          if ( v6 )
          {
            v7 = (__int64)&v2->mLeaderboardData.p[v4];
            if ( (_S18_2 & 1) == 0 )
            {
              _S18_2 |= 1u;
              UFG::StatGamePropertyManager::StatGamePropertyManager(&instance_8);
              atexit(UFG::StatGamePropertyManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
            }
            p_mNext = (UFG::StatGamePropertyManager *)&instance_8.m_lProperties.mNode.mNext[-1].mNext;
            if ( &instance_8.m_lProperties.mNode.mNext[-1].mNext == (UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> **)((char *)&instance_8 - 8) )
            {
LABEL_11:
              p_mNext = 0i64;
            }
            else
            {
              while ( p_mNext[1].m_lProperties.mNode.mNext != (UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> *)v7 )
              {
                p_mNext = (UFG::StatGamePropertyManager *)&p_mNext[1].m_lProperties.mNode.mPrev[-1].mNext;
                if ( p_mNext == (UFG::StatGamePropertyManager *)((char *)&instance_8 - 8) )
                  goto LABEL_11;
              }
            }
            v6->mPrev = v6;
            v6->mNext = v6;
            v6[1].mPrev = v6 + 1;
            v6[1].mNext = v6 + 1;
            v6[2].mPrev = (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)p_mNext;
            v6[2].mNext = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          mPrev = this->m_lLeaderboards.mNode.mPrev;
          mPrev->mNext = v6;
          v6->mPrev = mPrev;
          v6->mNext = &this->m_lLeaderboards.mNode;
          this->m_lLeaderboards.mNode.mPrev = v6;
        }
        ++v4;
        ++v5;
      }
      while ( v4 < size );
    }
    this->m_bIsCachedLeaderboardBuilt = 1;
  }
}

// File Line: 71
// RVA: 0x497A70
void __fastcall UFG::CachedLeaderboardManager::ClearCachedLeaderboards(UFG::CachedLeaderboardManager *this)
{
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *mNext; // rbx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *mPrev; // rdx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v4; // rax
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v5; // rdi
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v6; // rax
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v7; // rdx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v8; // rcx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v9; // rdx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v10; // rcx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v11; // rdx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v12; // rax
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v13; // rdx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v14; // rax

  if ( (UFG::CachedLeaderboardManager *)this->m_lLeaderboards.mNode.mNext == this )
  {
    this->m_bIsCachedLeaderboardBuilt = 0;
  }
  else
  {
    do
    {
      mNext = this->m_lLeaderboards.mNode.mNext;
      mPrev = mNext->mPrev;
      v4 = mNext->mNext;
      mPrev->mNext = v4;
      v4->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      v5 = mNext + 1;
      v6 = mNext[1].mNext;
      if ( v6 != &mNext[1] )
      {
        do
        {
          v7 = v6->mPrev;
          v8 = v6->mNext;
          v7->mNext = v8;
          v8->mPrev = v7;
          v6->mPrev = v6;
          v6->mNext = v6;
          v9 = v6->mPrev;
          v10 = v6->mNext;
          v9->mNext = v10;
          v10->mPrev = v9;
          v6->mPrev = v6;
          v6->mNext = v6;
          operator delete[](v6);
          v6 = mNext[1].mNext;
        }
        while ( v6 != v5 );
      }
      v11 = v5->mPrev;
      v12 = mNext[1].mNext;
      v11->mNext = v12;
      v12->mPrev = v11;
      v5->mPrev = v5;
      mNext[1].mNext = mNext + 1;
      v13 = mNext->mPrev;
      v14 = mNext->mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      operator delete[](mNext);
    }
    while ( (UFG::CachedLeaderboardManager *)this->m_lLeaderboards.mNode.mNext != this );
    this->m_bIsCachedLeaderboardBuilt = 0;
  }
}

// File Line: 94
// RVA: 0x4C8BD0
void __fastcall UFG::CachedLeaderboardManager::UpsertEntry(
        UFG::CachedLeaderboardManager *this,
        int id,
        UFG::CachedLeaderboard::Entry *entry)
{
  UFG::CachedLeaderboardManager *mNext; // rbp
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *mPrev; // rdi
  bool *p_m_bIsCachedLeaderboardBuilt; // rbx
  int m_iRating; // eax
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rdi
  UFG::allocator::free_link *v10; // rax
  int v11; // edi
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v12; // r11
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v13; // rax
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v14; // r9
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v15; // rdx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v16; // r8
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v17; // rcx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v18; // rax
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v19; // rax
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v20; // rax
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v21; // r10
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v22; // r8
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v23; // r9
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v24; // rcx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v25; // rdx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v26; // rcx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v27; // rcx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *v28; // rcx
  UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *i; // rax

  mNext = (UFG::CachedLeaderboardManager *)this->m_lLeaderboards.mNode.mNext;
  if ( mNext != this )
  {
    while ( mNext[1].m_lLeaderboards.mNode.mNext[1].mNext->mPrev != (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)id )
    {
      mNext = (UFG::CachedLeaderboardManager *)mNext->m_lLeaderboards.mNode.mNext;
      if ( mNext == this )
        return;
    }
    mPrev = mNext[1].m_lLeaderboards.mNode.mPrev;
    p_m_bIsCachedLeaderboardBuilt = &mNext->m_bIsCachedLeaderboardBuilt;
    while ( 1 )
    {
      if ( mPrev == (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)p_m_bIsCachedLeaderboardBuilt )
      {
        v8 = UFG::qMalloc(0x60ui64, "CachedLeaderboardManager", 0i64);
        v9 = v8;
        if ( v8 )
        {
          v8->mNext = v8;
          v8[1].mNext = v8;
          LODWORD(v8[2].mNext) = entry->m_iRating;
          HIDWORD(v8[2].mNext) = entry->m_uRank;
          LODWORD(v8[11].mNext) = entry->m_eEntryType;
          UFG::qStringCopy((char *)&v8[3], 64, entry->m_sUsername, -1);
        }
        else
        {
          v9 = 0i64;
        }
        v10 = *(UFG::allocator::free_link **)p_m_bIsCachedLeaderboardBuilt;
        v10[1].mNext = v9;
        v9->mNext = v10;
        v9[1].mNext = (UFG::allocator::free_link *)p_m_bIsCachedLeaderboardBuilt;
        *(_QWORD *)p_m_bIsCachedLeaderboardBuilt = v9;
        goto LABEL_16;
      }
      if ( LODWORD(mPrev[5].mNext) == entry->m_eEntryType
        && !(unsigned int)UFG::qStringCompare((const char *)&mPrev[1].mNext, entry->m_sUsername, -1) )
      {
        break;
      }
      mPrev = mPrev->mNext;
    }
    m_iRating = entry->m_iRating;
    if ( m_iRating > SLODWORD(mPrev[1].mPrev) )
      LODWORD(mPrev[1].mPrev) = m_iRating;
LABEL_16:
    v11 = 1;
    v12 = mNext[1].m_lLeaderboards.mNode.mPrev;
    do
    {
      v13 = 0i64;
      while ( v12 != (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)p_m_bIsCachedLeaderboardBuilt )
      {
        v14 = v12->mNext;
        if ( v14 == (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)p_m_bIsCachedLeaderboardBuilt )
          break;
        if ( SLODWORD(v12[1].mPrev) >= SLODWORD(v14[1].mPrev) )
        {
          v12 = v12->mNext;
        }
        else
        {
          v15 = v12->mPrev;
          v16 = v14->mNext;
          v15->mNext = v14;
          v14->mPrev = v15;
          v12->mPrev = v12;
          v12->mNext = v12;
          v17 = v14->mPrev;
          v18 = v14->mNext;
          v17->mNext = v18;
          v18->mPrev = v17;
          v14->mPrev = v14;
          v14->mNext = v14;
          v19 = v15->mNext;
          v15->mNext = v14;
          v14->mPrev = v15;
          v14->mNext = v19;
          v19->mPrev = v14;
          v20 = v16->mPrev;
          v20->mNext = v12;
          v12->mPrev = v20;
          v12->mNext = v16;
          v16->mPrev = v12;
          v13 = v14;
        }
      }
      v12 = 0i64;
      if ( !v13 || v13 == (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)p_m_bIsCachedLeaderboardBuilt )
        break;
      do
      {
        v21 = v13->mPrev;
        if ( (bool *)v13->mPrev == p_m_bIsCachedLeaderboardBuilt )
          break;
        if ( SLODWORD(v21[1].mPrev) >= SLODWORD(v13[1].mPrev) )
        {
          v13 = v13->mPrev;
        }
        else
        {
          v22 = v21->mPrev;
          v23 = v13->mNext;
          v24 = v21->mNext;
          v22->mNext = v24;
          v24->mPrev = v22;
          v21->mPrev = v21;
          v21->mNext = v21;
          v25 = v13->mPrev;
          v26 = v13->mNext;
          v25->mNext = v26;
          v26->mPrev = v25;
          v13->mPrev = v13;
          v13->mNext = v13;
          v27 = v22->mNext;
          v22->mNext = v13;
          v13->mPrev = v22;
          v13->mNext = v27;
          v27->mPrev = v13;
          v28 = v23->mPrev;
          v28->mNext = v21;
          v21->mPrev = v28;
          v21->mNext = v23;
          v23->mPrev = v21;
          v12 = v21;
        }
      }
      while ( v13 != (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)p_m_bIsCachedLeaderboardBuilt );
    }
    while ( v12 );
    for ( i = mNext[1].m_lLeaderboards.mNode.mPrev;
          i != (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)p_m_bIsCachedLeaderboardBuilt;
          i = i->mNext )
    {
      HIDWORD(i[1].mPrev) = v11++;
    }
  }
}

