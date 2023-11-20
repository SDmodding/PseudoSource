// File Line: 25
// RVA: 0x4AB790
UFG::SocialLogDataManager *__fastcall UFG::SocialLogDataManager::Instance()
{
  UFG::GameStatTracker *v0; // rdi

  if ( _S16_2 & 1 )
    return &instance_6;
  _S16_2 |= 1u;
  instance_6.m_lSocialLogDataList.mNode.mPrev = (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)&instance_6;
  instance_6.m_lSocialLogDataList.mNode.mNext = (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)&instance_6;
  instance_6.m_bHasNewChallengeMessage = 0;
  v0 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v0 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v0;
  instance_6.m_bHasNewChallengeMessage = v0->mpSnapshots[0]->mBools[47].mValue;
  atexit(UFG::SocialLogDataManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  return &instance_6;
}

// File Line: 31
// RVA: 0x4BCAA0
void __fastcall UFG::SocialLogDataManager::SetHasNewChallengeMessageFlag(UFG::SocialLogDataManager *this, bool flag)
{
  bool v2; // di
  UFG::SocialLogDataManager *v3; // rsi
  UFG::GameStatTracker *v4; // rbx

  v2 = flag;
  v3 = this;
  v4 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  if ( !(*((_BYTE *)v4 + 6216) & 1) )
    v4->mpSnapshots[0]->mBools[47].mValue = v2;
  v3->m_bHasNewChallengeMessage = v2;
}

// File Line: 37
// RVA: 0x493A30
void __fastcall UFG::SocialLogDataManager::AddToSaveData(UFG::SocialLogDataManager *this, const char *data, int size)
{
  int v3; // esi
  char *v4; // rbp
  unsigned int v5; // ecx
  UFG::GameStatTracker *v6; // rbx
  UFG::GameStatTracker *v7; // rdx
  UFG::GameStatTracker *v8; // r8
  unsigned int v9; // edi
  UFG::PersistentData::MapBinary *v10; // rbx
  UFG::qSymbol *v11; // rax
  UFG::PersistentData::Binary binary; // [rsp+28h] [rbp-20h]
  UFG::qWiseSymbol result; // [rsp+60h] [rbp+18h]

  v3 = size;
  v4 = (char *)data;
  v5 = _S12_6;
  v6 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v5 = _S12_6;
  }
  v7 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v7 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v7;
  if ( !(*((_BYTE *)v7 + 6216) & 1) )
  {
    ++v7->mpSnapshots[0]->mInts[137].mValue;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( !(v5 & 1) )
      {
        _S12_6 = v5 | 1;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        v5 = _S12_6;
      }
      v7 = &sGameStatTracker;
      if ( UFG::GameStatTracker::mspInstance )
        v7 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v7;
    }
    else
    {
      v7 = UFG::GameStatTracker::mspInstance;
    }
  }
  if ( !(v5 & 1) )
  {
    _S12_6 = v5 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v5 = _S12_6;
    v7 = UFG::GameStatTracker::mspInstance;
  }
  v8 = &sGameStatTracker;
  if ( v7 )
    v8 = v7;
  UFG::GameStatTracker::mspInstance = v8;
  v9 = v8->mpSnapshots[0]->mInts[137].mValue;
  if ( !(v5 & 1) )
  {
    _S12_6 = v5 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v8 = UFG::GameStatTracker::mspInstance;
  }
  if ( v8 )
    v6 = v8;
  UFG::GameStatTracker::mspInstance = v6;
  v10 = v6->mpSnapshots[0]->mpMapBinaries[1];
  binary.mpBuffer = v4;
  binary.mSize = v3;
  v11 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, v9);
  UFG::PersistentData::MapBinary::SetBinary(v10, v11, &binary);
  if ( v10->mValues.size > 0x64 )
    UFG::PersistentData::MapBinary::KeepLatest(v10, 0x50u);
}

// File Line: 54
// RVA: 0x493BF0
void __fastcall UFG::SocialLogDataManager::AddToSaveData(UFG::SocialLogDataManager *this, UFG::SocialLogData *data)
{
  UFG::SocialLogData *v2; // rsi
  UFG::SocialLogDataManager *v3; // rbp
  UFG::GameStatTracker *v4; // rax
  const char *v5; // rdi
  int v6; // eax
  UFG::allocator::free_link *v7; // rbx
  unsigned int v8; // eax
  int v9; // eax

  v2 = data;
  v3 = this;
  if ( data->m_iCommId == 4 )
  {
    v4 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v4 + 6216) & 1) )
      v4->mpSnapshots[0]->mBools[47].mValue = 1;
    v3->m_bHasNewChallengeMessage = 1;
  }
  v5 = v2->vfptr->Serialize((UFG::OSuiteMessage *)&v2->vfptr);
  v6 = v2->vfptr->Size((UFG::OSuiteMessage *)&v2->vfptr);
  v7 = UFG::qMalloc(v6, "SocialLogDataManager", 0i64);
  v8 = v2->vfptr->Size((UFG::OSuiteMessage *)&v2->vfptr);
  UFG::qMemCopy(v7, v5, v8);
  v9 = v2->vfptr->Size((UFG::OSuiteMessage *)&v2->vfptr);
  UFG::SocialLogDataManager::AddToSaveData(v3, (const char *)v7, v9);
}

// File Line: 68
// RVA: 0x4C5A30
void __fastcall UFG::SocialLogDataManager::UpdateChallengeStatus(UFG::SocialLogDataManager *this, UFG::SocialLogData *data)
{
  UFG::SocialLogData *v2; // rdi
  UFG::PersistentData::MapFloat *v3; // r15
  UFG::PersistentData::MapFloat *v4; // r14
  unsigned int v5; // esi
  UFG::PersistentData::KeyValue *v6; // rbp
  UFG::PersistentData::KeyValue v7; // rbp
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rbx
  int v10; // ebp
  int v11; // eax
  UFG::allocator::free_link *v12; // rsi
  unsigned int v13; // edi
  const void *v14; // rax
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+28h] [rbp-50h]
  int dest; // [rsp+88h] [rbp+10h]
  UFG::allocator::free_link *name; // [rsp+90h] [rbp+18h]

  v2 = data;
  if ( data->m_iCommId == 4 )
  {
    v3 = (UFG::PersistentData::MapFloat *)UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBinaries[1];
    UFG::PersistentData::MapInt::GetIterator(v3, &result);
    v4 = result.mList;
    v5 = result.mIndex;
    if ( result.mIndex < result.mList->mValues.size )
    {
      while ( 1 )
      {
        v6 = &v4->mValues.p[3i64 * v5 + 1];
        if ( v6 )
        {
          v7 = *v6;
          if ( v7 )
          {
            dest = 0;
            UFG::qMemCopy(&dest, (const void *)(*(_QWORD *)&v7 + 4i64), 4u);
            UFG::qEndianSwapBytes((char *)&dest, 4u);
            if ( dest == 4 )
            {
              v8 = UFG::qMalloc(0xD0ui64, "SocialLogDataManager", 0i64);
              v9 = v8;
              name = v8;
              if ( v8 )
              {
                UFG::SocialLogData::SocialLogData((UFG::SocialLogData *)v8);
                v9->mNext = (UFG::allocator::free_link *)&UFG::SocialLogData_Challenge::`vftable';
                LODWORD(v9[24].mNext) = 0;
                v9[25].mNext = 0i64;
              }
              else
              {
                v9 = 0i64;
              }
              ((void (__fastcall *)(UFG::allocator::free_link *, _QWORD))v9->mNext[3].mNext)(v9, v7);
              if ( v2->m_iVersion == LODWORD(v9[5].mNext)
                && v2->m_iCommId == HIDWORD(v9[5].mNext)
                && (UFG::allocator::free_link *)v2->m_iTimeStamp == v9[6].mNext
                && v2->m_iLeaderboardId == LODWORD(v9[7].mNext)
                && v2->m_iScore == HIDWORD(v9[7].mNext)
                && (UFG::allocator::free_link *)v2->m_cSrcOnlineId.m_SteamId.m_steamid.m_unAll64Bits == v9[10].mNext
                && (UFG::allocator::free_link *)v2->m_cDstOnlineId.m_SteamId.m_steamid.m_unAll64Bits == v9[18].mNext )
              {
                break;
              }
            }
          }
        }
        if ( ++v5 >= v4->mValues.size )
          return;
      }
      LODWORD(name) = v4->mValues.p[3 * v5].mKey.mUID;
      LODWORD(v9[24].mNext) = 1;
      v10 = ((__int64 (__fastcall *)(UFG::allocator::free_link *))v9->mNext[1].mNext)(v9);
      v11 = ((__int64 (__fastcall *)(UFG::allocator::free_link *))v9->mNext[1].mNext)(v9);
      v12 = UFG::qMalloc(v11, "SocialLogDataManager", 0i64);
      v13 = ((__int64 (__fastcall *)(UFG::allocator::free_link *))v9->mNext[1].mNext)(v9);
      v14 = (const void *)((__int64 (__fastcall *)(UFG::allocator::free_link *))v9->mNext[2].mNext)(v9);
      UFG::qMemCopy(v12, v14, v13);
      if ( v12 )
      {
        *(_QWORD *)&result.mIndex = v12;
        LODWORD(result.mList) = v10;
        UFG::PersistentData::MapBinary::SetBinary(
          (UFG::PersistentData::MapBinary *)v3,
          (UFG::qSymbol *)&name,
          (UFG::PersistentData::Binary *)&result);
      }
    }
  }
}

// File Line: 122
// RVA: 0x4A4490
UFG::SocialLogDataManager *__fastcall UFG::SocialLogDataManager::GetList(UFG::SocialLogDataManager *this)
{
  UFG::SocialLogDataManager *v1; // rdi
  UFG::SocialLogDataManager *v2; // rax
  UFG::SocialLogDataManager *i; // rbx
  UFG::SocialLogDataManager *v4; // rdx
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v5; // rcx
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v6; // rax
  UFG::GameStatTracker *v7; // rbx
  UFG::PersistentData::MapFloat *v8; // r14
  unsigned int v9; // esi
  UFG::PersistentData::KeyValue *v10; // rdx
  UFG::PersistentData::KeyValue v11; // rbp
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rbx
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v17; // rbx
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v18; // rax
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+28h] [rbp-50h]
  int dest; // [rsp+80h] [rbp+8h]
  UFG::allocator::free_link *v22; // [rsp+88h] [rbp+10h]

  v1 = this;
  v2 = (UFG::SocialLogDataManager *)&this->m_lSocialLogDataList.mNode.mNext[-2].mNext;
  for ( i = this - 1; v2 != i; v2 = (UFG::SocialLogDataManager *)&v1->m_lSocialLogDataList.mNode.mNext[-2].mNext )
  {
    v4 = v2 + 1;
    v5 = v2[1].m_lSocialLogDataList.mNode.mPrev;
    v6 = v2[1].m_lSocialLogDataList.mNode.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->m_lSocialLogDataList.mNode.mPrev = &v4->m_lSocialLogDataList.mNode;
    v4->m_lSocialLogDataList.mNode.mNext = &v4->m_lSocialLogDataList.mNode;
    if ( v4 != (UFG::SocialLogDataManager *)24 )
      ((void (__fastcall *)(UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> **, signed __int64))v4[-1].m_lSocialLogDataList.mNode.mPrev->mPrev)(
        &v4[-1].m_lSocialLogDataList.mNode.mPrev,
        1i64);
  }
  v7 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v7 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v7;
  UFG::PersistentData::MapInt::GetIterator(
    (UFG::PersistentData::MapFloat *)v7->mpSnapshots[0]->mpMapBinaries[1],
    &result);
  v8 = result.mList;
  v9 = result.mIndex;
  if ( result.mIndex < result.mList->mValues.size )
  {
    do
    {
      v10 = &v8->mValues.p[3i64 * v9 + 1];
      if ( v10 )
      {
        v11 = *v10;
        if ( *v10 )
        {
          dest = 0;
          UFG::qMemCopy(&dest, (const void *)(*(_QWORD *)&v11 + 4i64), 4u);
          UFG::qEndianSwapBytes((char *)&dest, 4u);
          switch ( dest )
          {
            case 0:
              v16 = UFG::qMalloc(0xD0ui64, "SocialLogDataManager", 0i64);
              v13 = v16;
              v22 = v16;
              if ( v16 )
              {
                UFG::SocialLogData::SocialLogData((UFG::SocialLogData *)v16);
                v13->mNext = (UFG::allocator::free_link *)&UFG::SocialLogData_NewHighScore::`vftable';
                LODWORD(v13[24].mNext) = 0;
                v13[25].mNext = 0i64;
              }
              else
              {
                v13 = 0i64;
              }
LABEL_31:
              if ( v13 )
              {
                ((void (__fastcall *)(UFG::allocator::free_link *, _QWORD))v13->mNext[3].mNext)(v13, v11);
                v17 = (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)&v13[3];
                v18 = v1->m_lSocialLogDataList.mNode.mPrev;
                v18->mNext = v17;
                v17->mPrev = v18;
                v17->mNext = &v1->m_lSocialLogDataList.mNode;
                v1->m_lSocialLogDataList.mNode.mPrev = v17;
              }
              break;
            case 1:
              v15 = UFG::qMalloc(0xC8ui64, "SocialLogDataManager", 0i64);
              v13 = v15;
              v22 = v15;
              if ( v15 )
              {
                UFG::SocialLogData::SocialLogData((UFG::SocialLogData *)v15);
                v13->mNext = (UFG::allocator::free_link *)&UFG::SocialLogData_AwardAchieved::`vftable';
                v13[24].mNext = 0i64;
              }
              else
              {
                v13 = 0i64;
              }
              goto LABEL_31;
            case 3:
              v14 = UFG::qMalloc(0xD0ui64, "SocialLogDataManager", 0i64);
              v13 = v14;
              v22 = v14;
              if ( v14 )
              {
                UFG::SocialLogData::SocialLogData((UFG::SocialLogData *)v14);
                v13->mNext = (UFG::allocator::free_link *)&UFG::SocialLogData_BeatChallenge::`vftable';
                LODWORD(v13[24].mNext) = 0;
                v13[25].mNext = 0i64;
              }
              else
              {
                v13 = 0i64;
              }
              goto LABEL_31;
            case 4:
              v12 = UFG::qMalloc(0xD0ui64, "SocialLogDataManager", 0i64);
              v13 = v12;
              v22 = v12;
              if ( v12 )
              {
                UFG::SocialLogData::SocialLogData((UFG::SocialLogData *)v12);
                v13->mNext = (UFG::allocator::free_link *)&UFG::SocialLogData_Challenge::`vftable';
                LODWORD(v13[24].mNext) = 0;
                v13[25].mNext = 0i64;
              }
              else
              {
                v13 = 0i64;
              }
              goto LABEL_31;
          }
        }
      }
      ++v9;
    }
    while ( v9 < v8->mValues.size );
  }
  return v1;
}

// File Line: 180
// RVA: 0x4AD530
char __fastcall UFG::SocialLogDataManager::ListContainsActiveFlowEntries(UFG::SocialLogDataManager *this)
{
  UFG::SocialLogDataManager *v1; // rbx
  UFG::SocialLogDataManager *v2; // rsi
  UFG::OSuiteLeaderboardManager *v3; // rax
  UFG::OSuiteLeaderboardData *v4; // rax
  UFG::OSuiteLeaderboardData *v5; // rdi

  v1 = (UFG::SocialLogDataManager *)&this->m_lSocialLogDataList.mNode.mPrev[-2].mNext;
  v2 = this - 1;
  if ( v1 == &this[-1] )
    return 0;
  while ( 1 )
  {
    v3 = UFG::OSuiteLeaderboardManager::Instance();
    v4 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingId(v3, (int)v1[2].m_lSocialLogDataList.mNode.mNext);
    v5 = v4;
    if ( v4 )
    {
      if ( v4->mFlow.mUID != -1 )
      {
        if ( !(_S19_1 & 1) )
        {
          _S19_1 |= 1u;
          UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
          atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
        }
        UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
        if ( v5->mFlow.mUID == unk_14240BAE0 )
          break;
      }
    }
    v1 = (UFG::SocialLogDataManager *)&v1[1].m_lSocialLogDataList.mNode.mPrev[-2].mNext;
    if ( v1 == v2 )
      return 0;
  }
  return 1;
}

