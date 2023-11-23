// File Line: 47
// RVA: 0x1501F40
__int64 dynamic_initializer_for__UFG::DataSynchronizer::m_lSocialLogDataList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DataSynchronizer::m_lSocialLogDataList__);
}

// File Line: 48
// RVA: 0x1501F10
__int64 dynamic_initializer_for__UFG::DataSynchronizer::m_cMutex__()
{
  UFG::qMutex::qMutex(&UFG::DataSynchronizer::m_cMutex, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DataSynchronizer::m_cMutex__);
}

// File Line: 56
// RVA: 0x430BC0
void UFG::DataSynchronizer::SetOptionsDirty(void)
{
  UFG::DataSynchronizer::m_bOptionsDirty = 1;
}

// File Line: 62
// RVA: 0x4315F0
void __fastcall UFG::DataSynchronizer::UpdateLeaderboardCallback(
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *pWebServiceClient,
        UFG::OSuiteLeaderboardData *pLBD)
{
  UFG::qSymbol *p_mLeaderboardName; // rbx
  UFG::GameStatTracker *v4; // rax

  if ( pData )
  {
    if ( pData->Status.eError == HTTPERROR_OK )
    {
      p_mLeaderboardName = &pLBD->mLeaderboardName;
      v4 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::SetStat(v4, LeaderboardDirtyScoreBoolList, p_mLeaderboardName, 0);
    }
  }
}

// File Line: 78
// RVA: 0x42B580
__int64 UFG::DataSynchronizer_UploadToServerAll()
{
  unsigned int v0; // ebx
  UFG::GameStatTracker *v1; // rax
  UFG::PersistentData::MapBool *MapBool; // r15
  __int64 v3; // rbp
  __int64 v4; // rdi
  __int64 v5; // r14
  __int64 v6; // rbx
  UFG::GameStatTracker *v7; // rax
  UFG::PersistentData::MapInt *MapInt; // rax
  int Status; // esi
  int v10; // ecx
  UFG::OSuiteLeaderboardData *v11; // rbx
  UFG::OSuiteLeaderboardData *v12; // rbx
  UFG::OSuiteLeaderboardData *v13; // rbx
  UFG::OSuiteLeaderboardData *v14; // rbx
  UFG::OSuiteLeaderboardManager *v15; // rax
  bool m_bConnected; // bl
  UFG::GameStatTracker *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rbx
  bool v20; // dl
  UFG::allocator::free_link *v21; // rax
  __int64 result; // rax

  UFG::GameStatAction::TemporaryData::Update();
  if ( (_S10_6 & 1) == 0 )
  {
    _S10_6 |= 1u;
    UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
    atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  v0 = dword_1424014F8;
  v1 = UFG::GameStatTracker::Instance();
  MapBool = UFG::GameStatTracker::GetMapBool(v1, LeaderboardDirtyScoreBoolList);
  if ( v0 )
  {
    v3 = 0i64;
    v4 = 0i64;
    v5 = v0;
    do
    {
      if ( UFG::PersistentData::MapBool::GetStatus(MapBool, (UFG::qSymbol *)(v4 + qword_142401500 + 48)) )
      {
        v6 = qword_142401500;
        v7 = UFG::GameStatTracker::Instance();
        MapInt = UFG::GameStatTracker::GetMapInt(v7, LeaderboardScoreIntList);
        Status = UFG::PersistentData::MapInt::GetStatus(MapInt, (UFG::qSymbol *)(v4 + v6 + 48));
        v10 = *(_DWORD *)(qword_142401500 + v3 + 96);
        if ( v10 )
        {
          switch ( v10 )
          {
            case 1:
              v12 = (UFG::OSuiteLeaderboardData *)(v4 + qword_142401500);
              if ( (_S10_6 & 1) == 0 )
              {
                _S10_6 |= 1u;
                UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
                atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
              }
              UFG::OSuiteLeaderboardManager::UploadStatGameResult(
                &instance_4,
                v12,
                Status,
                UFG::DataSynchronizer::UpdateLeaderboardCallback);
              break;
            case 2:
              v13 = (UFG::OSuiteLeaderboardData *)(v4 + qword_142401500);
              if ( (_S10_6 & 1) == 0 )
              {
                _S10_6 |= 1u;
                UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
                atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
              }
              UFG::OSuiteLeaderboardManager::UploadMissionResult(
                &instance_4,
                v13,
                Status,
                UFG::DataSynchronizer::UpdateLeaderboardCallback);
              break;
            case 3:
              v14 = (UFG::OSuiteLeaderboardData *)(v4 + qword_142401500);
              v15 = UFG::OSuiteLeaderboardManager::Instance();
              UFG::OSuiteLeaderboardManager::UploadRaceResult(
                v15,
                v14,
                Status,
                1,
                &customCaption,
                UFG::DataSynchronizer::UpdateLeaderboardCallback);
              break;
          }
        }
        else
        {
          v11 = (UFG::OSuiteLeaderboardData *)(v4 + qword_142401500);
          if ( (_S10_6 & 1) == 0 )
          {
            _S10_6 |= 1u;
            UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
            atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
          }
          UFG::OSuiteLeaderboardManager::UploadStatAwardResult(
            &instance_4,
            v11,
            Status,
            UFG::DataSynchronizer::UpdateLeaderboardCallback);
        }
      }
      v4 += 312i64;
      v3 += 312i64;
      --v5;
    }
    while ( v5 );
  }
  if ( (_S10_6 & 1) == 0 )
  {
    _S10_6 |= 1u;
    UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
    atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  UFG::OSuiteLeaderboardManager::UploadPlayerStats(&instance_4);
  if ( (_S10_6 & 1) == 0 )
  {
    _S10_6 |= 1u;
    UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
    atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  m_bConnected = UFG::OSuiteManager::Instance()->m_bConnected;
  v17 = UFG::GameStatTracker::Instance();
  if ( (int)UFG::GameStatTracker::GetStat(v17, IsBannedByCommunityManager) <= 0 && m_bConnected )
  {
    v18 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
    v19 = v18;
    if ( v18 )
    {
      v18[1].mNext = v18 + 1;
      v18[2].mNext = v18 + 1;
      v18->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable;
      v18->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateBanStatusEvent::`vftable;
      LODWORD(v18[3].mNext) = 6;
    }
    else
    {
      v19 = 0i64;
    }
    UFG::qMutex::Lock(&stru_142401548);
    v20 = unk_142401538 - 8i64 == (_QWORD)&unk_142401528;
    v21 = (UFG::allocator::free_link *)qword_142401530;
    *(_QWORD *)(qword_142401530 + 8i64) = v19 + 1;
    v19[1].mNext = v21;
    v19[2].mNext = (UFG::allocator::free_link *)&qword_142401530;
    qword_142401530 = v19 + 1;
    if ( v20 )
      UFG::qEvent::Signal(&stru_142401578);
    UFG::qMutex::Unlock(&stru_142401548);
  }
  result = _S10_6;
  if ( (_S10_6 & 1) == 0 )
  {
    _S10_6 |= 1u;
    UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
    result = atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  unk_142401544 = 1;
  return result;
}

// File Line: 118
// RVA: 0x42F560
void __fastcall UFG::DataSynchronizer::RecvMessageCB(
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuite::ZOFeed *v2; // r12
  unsigned __int64 v3; // rbx
  int v4; // r15d
  int v5; // esi
  OSuite::ZAtomEntry *Entry; // rdi
  OSuite::ZOEntry *v7; // rbp
  OSuite::ZOProperty *v8; // rax
  int BinarySize; // eax
  size_t v10; // rdi
  UFG::allocator::free_link *v11; // r14
  OSuite::ZOProperty *v12; // rax
  bool v13; // bp
  UFG::allocator::free_link *v14; // rax
  __int64 v15; // rax
  __int64 v16; // rdi
  UFG::OnlineManager *v17; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v18; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mNext; // rax
  UFG::OnlineManager *v20; // rax
  UFG::qString *OnlineName; // rax
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v22; // rax
  UFG::GameStatTracker *v23; // rax
  UFG::allocator::free_link *v24; // rax
  __int64 v25; // rax
  __int64 v26; // rdi
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *mPrev; // rax
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> callback; // [rsp+38h] [rbp-90h] BYREF
  UFG::OnlineId result; // [rsp+48h] [rbp-80h] BYREF
  UFG::qString v30; // [rsp+60h] [rbp-68h] BYREF
  int v; // [rsp+D0h] [rbp+8h] BYREF
  int dest; // [rsp+E0h] [rbp+18h] BYREF
  UFG::allocator::free_link *v33; // [rsp+E8h] [rbp+20h]

  if ( pData->Status.eError == HTTPERROR_OK )
  {
    v2 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOFeed>(pWebServiceClient, &pData->URL);
    if ( v2 )
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::DataSynchronizer::m_cMutex);
      v3 = 0i64;
      v4 = OSuite::ZAtomFeed::TotalEntries(v2);
      v5 = 0;
      if ( v4 > 0 )
      {
        do
        {
          Entry = OSuite::ZAtomFeed::GetEntry(v2, v5);
          v7 = 0i64;
          if ( Entry->vfptr[1].__vecDelDtor(Entry, OSuite::ZOEntry::s_nClassId) )
            v7 = (OSuite::ZOEntry *)Entry;
          v8 = OSuite::ZOEntry::Property(v7, "bin_Data");
          BinarySize = OSuite::ZOProperty::GetBinarySize(v8);
          if ( BinarySize )
          {
            v10 = BinarySize;
            v11 = UFG::qMalloc(BinarySize, "RecvMessageCB", 0i64);
            memset(v11, 0, v10);
            v12 = OSuite::ZOEntry::Property(v7, "bin_Data");
            OSuite::ZOProperty::GetBinary(v12, (char *)v11, v10);
            dest = 0;
            UFG::qMemCopy(&dest, v11, 4u);
            v13 = dest == 0;
            v = 0;
            UFG::qMemCopy(&v, (char *)&v11->mNext + 4, 4u);
            UFG::qEndianSwapBytes((char *)&v, 4u);
            if ( v == 3 )
            {
              v24 = UFG::qMalloc(0xD0ui64, "DataSynchronizer", 0i64);
              v33 = v24;
              if ( v24 )
              {
                UFG::SocialLogData_BeatChallenge::SocialLogData_BeatChallenge((UFG::SocialLogData_BeatChallenge *)v24);
                v26 = v25;
              }
              else
              {
                v26 = 0i64;
              }
              (*(void (__fastcall **)(__int64, UFG::allocator::free_link *))(*(_QWORD *)v26 + 24i64))(v26, v11);
              if ( v13 )
              {
                mPrev = UFG::DataSynchronizer::m_lSocialLogDataList.mNode.mPrev;
                UFG::DataSynchronizer::m_lSocialLogDataList.mNode.mPrev->mNext = (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)(v26 + 24);
                *(_QWORD *)(v26 + 24) = mPrev;
                *(_QWORD *)(v26 + 32) = &UFG::DataSynchronizer::m_lSocialLogDataList;
                UFG::DataSynchronizer::m_lSocialLogDataList.mNode.mPrev = (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)(v26 + 24);
              }
              if ( *(_QWORD *)(v26 + 48) > v3 )
                v3 = *(_QWORD *)(v26 + 48);
            }
            else if ( v == 4 )
            {
              v14 = UFG::qMalloc(0xD0ui64, "DataSynchronizer", 0i64);
              v33 = v14;
              if ( v14 )
              {
                UFG::SocialLogData_Challenge::SocialLogData_Challenge((UFG::SocialLogData_Challenge *)v14);
                v16 = v15;
              }
              else
              {
                v16 = 0i64;
              }
              (*(void (__fastcall **)(__int64, UFG::allocator::free_link *))(*(_QWORD *)v16 + 24i64))(v16, v11);
              v17 = UFG::OnlineManager::Instance();
              *(_QWORD *)(v16 + 144) = UFG::OnlineManager::GetOnlineId(v17, &result)->m_SteamId.m_steamid.m_unAll64Bits;
              v18 = result.mPrev;
              mNext = result.mNext;
              result.mPrev->mNext = result.mNext;
              mNext->mPrev = v18;
              result.mPrev = &result;
              result.mNext = &result;
              v20 = UFG::OnlineManager::Instance();
              OnlineName = UFG::OnlineManager::GetOnlineName(v20, &v30);
              UFG::qString::Set((UFG::qString *)(v16 + 152), OnlineName->mData, OnlineName->mLength, 0i64, 0);
              UFG::qString::~qString(&v30);
              if ( v13 )
              {
                v22 = UFG::DataSynchronizer::m_lSocialLogDataList.mNode.mPrev;
                UFG::DataSynchronizer::m_lSocialLogDataList.mNode.mPrev->mNext = (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)(v16 + 24);
                *(_QWORD *)(v16 + 24) = v22;
                *(_QWORD *)(v16 + 32) = &UFG::DataSynchronizer::m_lSocialLogDataList;
                UFG::DataSynchronizer::m_lSocialLogDataList.mNode.mPrev = (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)(v16 + 24);
              }
              if ( *(_QWORD *)(v16 + 48) > v3 )
                v3 = *(_QWORD *)(v16 + 48);
              v23 = UFG::GameStatTracker::Instance();
              UFG::GameStatTracker::ApplyDelta(v23, SocialChallengeReceived, 1);
            }
            operator delete[](v11);
          }
          ++v5;
        }
        while ( v5 < v4 );
        if ( v3 )
        {
          callback.m_Closure.m_pthis = 0i64;
          callback.m_Closure.m_pFunction = 0i64;
          if ( (_S7_11 & 1) == 0 )
          {
            _S7_11 |= 1u;
            UFG::OSuiteMessenger::OSuiteMessenger(&instance_1);
            atexit(UFG::OSuiteMessenger::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
          }
          UFG::OSuiteMessenger::Delete(&instance_1, v3, &callback);
        }
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::DataSynchronizer::m_cMutex);
      UFG::DataSynchronizer::m_bAddToSaveDataRequired = 1;
    }
  }
}

// File Line: 217
// RVA: 0x42A580
void UFG::DataSynchronizer::AddToSaveData(void)
{
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *mNext; // rdx
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v1; // r14
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v2; // r12
  char v3; // si
  UFG::GameStatTracker *v4; // rax
  UFG::PersistentData::MapFloat *MapBinary; // rax
  UFG::PersistentData::Binary *Binary; // rax
  char *mpBuffer; // rdi
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rbx
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rbx
  UFG::SocialLogDataManager *v12; // rax
  unsigned int v13; // r10d
  int v14; // r8d
  int v15; // edx
  unsigned int v16; // ecx
  unsigned int v17; // r9d
  __int64 v18; // r15
  int v19; // esi
  UFG::GameStatTracker *v20; // rax
  UFG::PersistentData::MapInt *MapInt; // rax
  int Status; // eax
  int mNext_high; // eax
  UFG::CachedLeaderboardManager *v24; // rax
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *mPrev; // rcx
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v26; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v27; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v28; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v29; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v30; // rax
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v31; // rcx
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v32; // rax
  UFG::OnlineFriend frnd; // [rsp+20h] [rbp-B9h] BYREF
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+80h] [rbp-59h] BYREF
  UFG::CachedLeaderboard::Entry entry; // [rsp+90h] [rbp-49h] BYREF
  __int64 v36; // [rsp+F0h] [rbp+17h]
  UFG::OnlineId *dest; // [rsp+140h] [rbp+67h] BYREF
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v38; // [rsp+148h] [rbp+6Fh]
  UFG::allocator::free_link *v39; // [rsp+150h] [rbp+77h]

  v36 = -2i64;
  UFG::qGetSystemTimeUTC();
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::DataSynchronizer::m_cMutex);
  mNext = UFG::DataSynchronizer::m_lSocialLogDataList.mNode.mNext;
  v1 = (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)((char *)UFG::DataSynchronizer::m_lSocialLogDataList.mNode.mNext
                                                           - 24);
  v2 = (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)((char *)&UFG::DataSynchronizer::m_lSocialLogDataList - 24);
  v38 = (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)((char *)&UFG::DataSynchronizer::m_lSocialLogDataList - 24);
  if ( &UFG::DataSynchronizer::m_lSocialLogDataList.mNode.mNext[-2].mNext != (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> **)((char *)&UFG::DataSynchronizer::m_lSocialLogDataList - 24) )
  {
    while ( 1 )
    {
      v3 = 1;
      v4 = UFG::GameStatTracker::Instance();
      MapBinary = (UFG::PersistentData::MapFloat *)UFG::GameStatTracker::GetMapBinary(v4, SocialLogBinaryList);
      UFG::PersistentData::MapInt::GetIterator(MapBinary, &result);
      if ( UFG::PersistentData::MapBinary::Iterator::IsValid(&result) )
      {
        do
        {
          Binary = UFG::PersistentData::MapBinary::Iterator::GetBinary((UFG::PersistentData::MapBinary::Iterator *)&result);
          if ( Binary )
          {
            mpBuffer = (char *)Binary->mpBuffer;
            if ( Binary->mpBuffer )
            {
              LODWORD(dest) = 0;
              UFG::qMemCopy(&dest, mpBuffer + 4, 4u);
              UFG::qEndianSwapBytes((char *)&dest, 4u);
              if ( (_DWORD)dest == 3 )
              {
                v10 = UFG::qMalloc(0xD0ui64, "DataSynchronizer", 0i64);
                v11 = v10;
                v39 = v10;
                if ( v10 )
                {
                  UFG::SocialLogData::SocialLogData((UFG::SocialLogData *)v10);
                  v11->mNext = (UFG::allocator::free_link *)&UFG::SocialLogData_BeatChallenge::`vftable;
                  LODWORD(v11[24].mNext) = 0;
                  v11[25].mNext = 0i64;
                }
                else
                {
                  v11 = 0i64;
                }
                ((void (__fastcall *)(UFG::allocator::free_link *, char *))v11->mNext[3].mNext)(v11, mpBuffer);
                if ( LODWORD(v1[2].mNext) == LODWORD(v11[5].mNext)
                  && HIDWORD(v1[2].mNext) == HIDWORD(v11[5].mNext)
                  && v1[3].mPrev == (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)v11[6].mNext
                  && LODWORD(v1[3].mNext) == LODWORD(v11[7].mNext)
                  && HIDWORD(v1[3].mNext) == HIDWORD(v11[7].mNext)
                  && v1[5].mPrev == (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)v11[10].mNext
                  && v1[9].mPrev == (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)v11[18].mNext )
                {
                  v3 = 0;
                }
              }
              else if ( (_DWORD)dest == 4 )
              {
                v8 = UFG::qMalloc(0xD0ui64, "DataSynchronizer", 0i64);
                v9 = v8;
                v39 = v8;
                if ( v8 )
                {
                  UFG::SocialLogData::SocialLogData((UFG::SocialLogData *)v8);
                  v9->mNext = (UFG::allocator::free_link *)&UFG::SocialLogData_Challenge::`vftable;
                  LODWORD(v9[24].mNext) = 0;
                  v9[25].mNext = 0i64;
                }
                else
                {
                  v9 = 0i64;
                }
                ((void (__fastcall *)(UFG::allocator::free_link *, char *))v9->mNext[3].mNext)(v9, mpBuffer);
                if ( LODWORD(v1[2].mNext) == LODWORD(v9[5].mNext)
                  && HIDWORD(v1[2].mNext) == HIDWORD(v9[5].mNext)
                  && v1[3].mPrev == (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)v9[6].mNext
                  && LODWORD(v1[3].mNext) == LODWORD(v9[7].mNext)
                  && HIDWORD(v1[3].mNext) == HIDWORD(v9[7].mNext)
                  && v1[5].mPrev == (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)v9[10].mNext
                  && v1[9].mPrev == (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)v9[18].mNext )
                {
                  v3 = 0;
                }
              }
            }
          }
          UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&result);
        }
        while ( UFG::PersistentData::MapBinary::Iterator::IsValid(&result) );
        v2 = v38;
        if ( !v3 )
          goto LABEL_48;
      }
      v12 = UFG::SocialLogDataManager::Instance();
      UFG::SocialLogDataManager::AddToSaveData(v12, (UFG::SocialLogData *)v1);
      if ( HIDWORD(v1[2].mNext) != 4 )
        goto LABEL_48;
      if ( (_S10_6 & 1) == 0 )
      {
        _S10_6 |= 1u;
        UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
        atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
      }
      v13 = (unsigned int)v1[3].mNext;
      if ( !dword_1424014F8 || (v14 = 0, v15 = dword_1424014F8 - 1, dword_1424014F8 - 1 < 0) )
      {
LABEL_43:
        v18 = 0i64;
        goto LABEL_44;
      }
      while ( 1 )
      {
        v16 = (unsigned int)(v15 + v14) >> 1;
        v17 = *(_DWORD *)(312i64 * v16 + qword_142401500);
        if ( v17 >= v13 )
          break;
        v14 = v16 + 1;
LABEL_40:
        if ( v14 > v15 )
          goto LABEL_43;
      }
      if ( v17 > v13 )
        break;
      v18 = qword_142401500 + 312i64 * v16;
LABEL_44:
      v19 = *(_DWORD *)(v18 + 96);
      v20 = UFG::GameStatTracker::Instance();
      MapInt = UFG::GameStatTracker::GetMapInt(v20, LeaderboardScoreIntList);
      Status = UFG::PersistentData::MapInt::GetStatus(MapInt, (UFG::qSymbol *)(v18 + 48));
      UFG::DataSynchronizer::SendBeatChallengeMessageIfNeeded((UFG::OSuiteLeaderboardData *)v18, Status, v19 == 3);
      if ( v19 == 1 )
      {
        frnd.mPrev = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
        frnd.mNext = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
        frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable;
        dest = &frnd.m_cOnlineId;
        frnd.m_cOnlineId.mPrev = &frnd.m_cOnlineId;
        frnd.m_cOnlineId.mNext = &frnd.m_cOnlineId;
        frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits = __PAIR64__(
                                                               HIDWORD(frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits),
                                                               0) & 0xFF0FFFFF00000000ui64;
        HIBYTE(frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits) = 0;
        *((_DWORD *)&frnd.m_cOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
        UFG::qString::qString(&frnd.m_sOnlineName);
        if ( UFG::OnlineFriendManager::FindFriend(&frnd, (UFG::OnlineId *)&v1[4]) )
        {
          mNext_high = HIDWORD(v1[3].mNext);
          entry.mPrev = &entry;
          entry.mNext = &entry;
          entry.m_iRating = mNext_high;
          entry.m_uRank = 0;
          entry.m_eEntryType = EntryType_Friend;
          UFG::qStringCopy(entry.m_sUsername, 64, frnd.m_sOnlineName.mData, -1);
          v24 = UFG::CachedLeaderboardManager::Instance();
          UFG::CachedLeaderboardManager::UpsertEntry(v24, (int)v1[3].mNext, &entry);
          mPrev = entry.mPrev;
          v26 = entry.mNext;
          entry.mPrev->mNext = entry.mNext;
          v26->mPrev = mPrev;
          entry.mPrev = &entry;
          entry.mNext = &entry;
        }
        frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable;
        UFG::qString::~qString(&frnd.m_sOnlineName);
        dest = &frnd.m_cOnlineId;
        v27 = frnd.m_cOnlineId.mPrev;
        v28 = frnd.m_cOnlineId.mNext;
        frnd.m_cOnlineId.mPrev->mNext = frnd.m_cOnlineId.mNext;
        v28->mPrev = v27;
        frnd.m_cOnlineId.mPrev = &frnd.m_cOnlineId;
        frnd.m_cOnlineId.mNext = &frnd.m_cOnlineId;
        v29 = frnd.mPrev;
        v30 = frnd.mNext;
        frnd.mPrev->mNext = frnd.mNext;
        v30->mPrev = v29;
        frnd.mPrev = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
        frnd.mNext = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
      }
LABEL_48:
      v1 = (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)((char *)v1[2].mPrev - 24);
      if ( v1 == v2 )
      {
        mNext = UFG::DataSynchronizer::m_lSocialLogDataList.mNode.mNext;
        goto LABEL_50;
      }
    }
    v15 = v16 - 1;
    goto LABEL_40;
  }
LABEL_50:
  if ( &mNext[-2].mNext != (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> **)v2 )
  {
    do
    {
      v31 = mNext->mPrev;
      v32 = mNext->mNext;
      v31->mNext = v32;
      v32->mPrev = v31;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      if ( mNext != (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)24 )
        ((void (__fastcall *)(UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> **, __int64))mNext[-2].mNext->mPrev)(
          &mNext[-2].mNext,
          1i64);
      mNext = UFG::DataSynchronizer::m_lSocialLogDataList.mNode.mNext;
    }
    while ( (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)((char *)UFG::DataSynchronizer::m_lSocialLogDataList.mNode.mNext
                                                                - 24) != v2 );
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::DataSynchronizer::m_cMutex);
}

// File Line: 316
// RVA: 0x431320
void __fastcall UFG::DataSynchronizer::Update(float timeDelta)
{
  UFG::UIScreenTextureManager *v1; // rax
  int GameState; // ebx
  UFG::GameSaveLoad *v3; // rax
  UFG::ProgressionTracker *v4; // rax
  UFG::ProgressionTracker::ActiveMasterMode mActiveMasterMode; // ebx
  UFG::ProgressionTracker::State mState; // edi
  bool v7; // al
  UFG::GameSaveLoad *v8; // rax
  void (__fastcall *v9)(OSuite::fastdelegate::detail::GenericClass *); // rax
  UFG::OSuiteMessenger *v10; // rax
  UFG::GameSaveLoad *v11; // rax
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> callback; // [rsp+20h] [rbp-28h] BYREF

  v1 = UFG::UIScreenTextureManager::Instance();
  GameState = UFG::UIScreenTextureManager::GetGameState(v1);
  v3 = UFG::GameSaveLoad::Instance();
  if ( UFG::GameSaveLoad::IsSaveAvaliable(v3) && GameState == GameState_Gameplay )
  {
    v4 = UFG::ProgressionTracker::Instance();
    mActiveMasterMode = v4->mActiveMasterMode;
    mState = v4->mState;
    v7 = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "GarageBrowser") != 0i64;
    if ( mActiveMasterMode == ActiveMasterMode_OpenWorld
      && mState == STATE_COMPLETE
      && !v7
      && UFG::DataSynchronizer::m_rTimeElapsed > 600.0 )
    {
      if ( UFG::OSuiteManager::Instance()->m_bConnected )
      {
        UFG::DataSynchronizer_UploadToServerAll();
        if ( UFG::DataSynchronizer::m_bOptionsDirty )
        {
          v8 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::UpdateGameOptionsTelemetry(v8);
          UFG::DataSynchronizer::m_bOptionsDirty = 0;
        }
        v9 = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>::InvokeStaticFunction;
        callback.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)UFG::DataSynchronizer::RecvMessageCB;
        if ( !UFG::DataSynchronizer::RecvMessageCB )
          v9 = 0i64;
        callback.m_Closure.m_pFunction = v9;
        v10 = UFG::OSuiteMessenger::Instance();
        UFG::OSuiteMessenger::Recv(v10, 20, &callback);
      }
      else
      {
        v11 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SaveAutoGameSlot(v11);
      }
      UFG::DataSynchronizer::m_rTimeElapsed = 0.0;
    }
  }
  if ( UFG::DataSynchronizer::m_bAddToSaveDataRequired )
  {
    UFG::DataSynchronizer::AddToSaveData();
    UFG::DataSynchronizer::m_bAddToSaveDataRequired = 0;
  }
  UFG::DataSynchronizer::m_rTimeElapsed = UFG::DataSynchronizer::m_rTimeElapsed + timeDelta;
}

// File Line: 358
// RVA: 0x150E980
__int64 UFG::_dynamic_initializer_for__sym_DLC_Ghost__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DLC_Ghost", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_DLC_Ghost, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_DLC_Ghost__);
}

// File Line: 360
// RVA: 0x431CD0
void __fastcall UFG::DataSynchronizer::UpdateStatAwardRankAndBringUpHudIfNeeded(
        UFG::OSuiteLeaderboardData *pLBD,
        int score,
        int rank)
{
  UFG::ProgressionTracker *v6; // rax
  UFG::StatGamePropertyManager *v7; // rax
  UFG::StatAwardPropertyData *PropertyData; // rdi
  UFG::GameStatTracker *v9; // rax
  unsigned __int64 SystemTimeUTC; // rax
  UFG::SocialLogDataManager *v11; // rax
  unsigned int v12; // r12d
  int v13; // esi
  int v14; // r15d
  unsigned int v15; // ebp
  __int64 v16; // r14
  __int64 v17; // rdi
  UFG::OSuiteLeaderboardData *v18; // rbx
  UFG::StatGamePropertyManager *v19; // rax
  __int64 v20; // rbx
  UFG::GameStatTracker *v21; // rax
  UFG::PersistentData::MapInt *MapInt; // rax
  UFG::qSymbol *v23; // rax
  int v24; // r9d
  int v25; // r8d
  unsigned int mUID; // r10d
  __int64 v27; // rdx
  unsigned int v28; // eax
  UFG::OSuiteLeaderboardData *v29; // r15
  UFG::GameStatTracker *v30; // rax
  int Stat; // ebp
  unsigned int v32; // edi
  __int64 v33; // r14
  __int64 v34; // rbx
  UFG::qSymbol *v35; // rbx
  UFG::GameStatTracker *v36; // rax
  UFG::PersistentData::MapInt *v37; // rax
  UFG::GameStatTracker *v38; // rax
  UFG::GameStatTracker *v39; // rax
  UFG::GameStatTracker *v40; // rax
  UFG::StatGamePropertyManager *v41; // rax
  UFG::StatGamePropertyData *v42; // rax
  UFG::StatAwardPropertyData *v43; // rbx
  UFG::GameStatTracker *v44; // rax
  unsigned __int64 v45; // rax
  UFG::SocialLogDataManager *v46; // rax
  UFG::GameStatTracker *v47; // rax
  unsigned __int64 v48; // rax
  UFG::SocialLogDataManager *v49; // rax
  UFG::GameStatTracker *v50; // rax
  unsigned __int64 v51; // rax
  UFG::SocialLogDataManager *v52; // rax
  UFG::SocialLogData_AwardAchieved v53; // [rsp+30h] [rbp-F8h] BYREF
  UFG::qSymbol result; // [rsp+130h] [rbp+8h] BYREF

  if ( pLBD )
  {
    if ( pLBD->mFlow.mUID == -1
      || (v6 = UFG::ProgressionTracker::Instance(), pLBD->mFlow.mUID == UFG::ProgressionTracker::GetActiveFlow(v6)->mUID) )
    {
      v7 = (UFG::StatGamePropertyManager *)UFG::StatAwardPropertyManager::Instance();
      PropertyData = (UFG::StatAwardPropertyData *)UFG::StatGamePropertyManager::GetPropertyData(v7, pLBD);
      v9 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::SetStat(v9, StatAwardRankIntList, &pLBD->mLeaderboardName, rank);
      SystemTimeUTC = UFG::qGetSystemTimeUTC();
      UFG::SocialLogData_AwardAchieved::SocialLogData_AwardAchieved(
        &v53,
        (SystemTimeUTC - 116444736000000000i64) / 0x2710,
        pLBD->mLeaderboardId,
        rank);
      v11 = UFG::SocialLogDataManager::Instance();
      UFG::SocialLogDataManager::AddToSaveData(v11, &v53);
      UFG::DataSynchronizer::ShowMedalAward(rank, PropertyData, score);
      UFG::SocialLogData_AwardAchieved::~SocialLogData_AwardAchieved(&v53);
      if ( (_S10_6 & 1) == 0 )
      {
        _S10_6 |= 1u;
        UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
        atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
      }
      v12 = dword_1424014F8;
      v13 = 0;
      if ( pLBD->mFlow.mUID == UFG::sym_DLC_Ghost.mUID )
      {
        v14 = 0;
        v15 = 0;
        if ( dword_1424014F8 )
        {
          v16 = 0i64;
          do
          {
            if ( *(_DWORD *)(v16 + qword_142401500 + 304) == UFG::sym_DLC_Ghost.mUID
              && !*(_DWORD *)(v16 + qword_142401500 + 96) )
            {
              v17 = 312i64 * v15;
              v18 = (UFG::OSuiteLeaderboardData *)(v17 + qword_142401500);
              v19 = (UFG::StatGamePropertyManager *)UFG::StatAwardPropertyManager::Instance();
              UFG::StatGamePropertyManager::GetPropertyData(v19, v18);
              v20 = qword_142401500;
              v21 = UFG::GameStatTracker::Instance();
              MapInt = UFG::GameStatTracker::GetMapInt(v21, StatAwardRankIntList);
              if ( UFG::PersistentData::MapInt::GetStatus(MapInt, (UFG::qSymbol *)(v17 + v20 + 48)) >= 3 )
                ++v14;
            }
            ++v15;
            v16 += 312i64;
          }
          while ( v15 < v12 );
          if ( v14 >= 5 )
            UFG::AchievementTrophyManager::UnlockAchievementTrophy(54);
        }
      }
      if ( pLBD->mFlow.mUID == UFG::ProgressionTracker::GetDefaultFlow()->mUID )
      {
        if ( (_S10_6 & 1) == 0 )
        {
          _S10_6 |= 1u;
          UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
          atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
        }
        v23 = UFG::qSymbol::create_from_string(&result, "StatAwardsOverall");
        if ( unk_142401518 )
        {
          v24 = 0;
          v25 = unk_142401518 - 1;
          if ( unk_142401518 - 1 >= 0 )
          {
            mUID = v23->mUID;
            do
            {
              v27 = (unsigned int)(v25 + v24) >> 1;
              v28 = *(_DWORD *)(*(_QWORD *)(unk_142401520 + 8 * v27) + 48i64);
              if ( v28 >= mUID )
              {
                if ( v28 <= mUID )
                {
                  v29 = *(UFG::OSuiteLeaderboardData **)(unk_142401520 + 8 * v27);
                  goto LABEL_30;
                }
                v25 = v27 - 1;
              }
              else
              {
                v24 = v27 + 1;
              }
            }
            while ( v24 <= v25 );
          }
        }
        v29 = 0i64;
LABEL_30:
        v30 = UFG::GameStatTracker::Instance();
        Stat = UFG::GameStatTracker::GetStat(v30, StatAward_OverallRank);
        v32 = 0;
        if ( v12 )
        {
          v33 = 0i64;
          do
          {
            v34 = qword_142401500;
            if ( *(_DWORD *)(v34 + v33 + 304) == UFG::ProgressionTracker::GetDefaultFlow()->mUID
              && !*(_DWORD *)(v33 + qword_142401500 + 96) )
            {
              v35 = (UFG::qSymbol *)(qword_142401500 + 312i64 * v32);
              if ( v29 != (UFG::OSuiteLeaderboardData *)v35 )
              {
                v36 = UFG::GameStatTracker::Instance();
                v37 = UFG::GameStatTracker::GetMapInt(v36, StatAwardRankIntList);
                v13 += UFG::PersistentData::MapInt::GetStatus(v37, v35 + 12);
              }
            }
            ++v32;
            v33 += 312i64;
          }
          while ( v32 < v12 );
        }
        v38 = UFG::GameStatTracker::Instance();
        if ( v13 > (int)UFG::GameStatTracker::GetStat(v38, LeaderboardScoreIntList, &v29->mLeaderboardName) )
        {
          v39 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v39, LeaderboardScoreIntList, &v29->mLeaderboardName, v13);
          v40 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v40, LeaderboardDirtyScoreBoolList, &v29->mLeaderboardName, 1);
        }
        v41 = (UFG::StatGamePropertyManager *)UFG::StatAwardPropertyManager::Instance();
        v42 = UFG::StatGamePropertyManager::GetPropertyData(v41, v29);
        v43 = (UFG::StatAwardPropertyData *)v42;
        if ( v13 >= *((_DWORD *)&v42->mFormatType + 1) )
        {
          if ( Stat == 3 )
            return;
          v44 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v44, StatAward_OverallRank, 3);
          v45 = UFG::qGetSystemTimeUTC();
          UFG::SocialLogData_AwardAchieved::SocialLogData_AwardAchieved(
            &v53,
            (v45 - 116444736000000000i64) / 0x2710,
            v29->mLeaderboardId,
            3);
          v46 = UFG::SocialLogDataManager::Instance();
          UFG::SocialLogDataManager::AddToSaveData(v46, &v53);
          UFG::DataSynchronizer::ShowMedalAward(3, v43, v13);
          goto LABEL_48;
        }
        if ( v13 >= SLODWORD(v42[1].vfptr) )
        {
          if ( Stat == 2 )
            return;
          v47 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v47, StatAward_OverallRank, 2);
          v48 = UFG::qGetSystemTimeUTC();
          UFG::SocialLogData_AwardAchieved::SocialLogData_AwardAchieved(
            &v53,
            (v48 - 116444736000000000i64) / 0x2710,
            v29->mLeaderboardId,
            2);
          v49 = UFG::SocialLogDataManager::Instance();
          UFG::SocialLogDataManager::AddToSaveData(v49, &v53);
          UFG::DataSynchronizer::ShowMedalAward(2, v43, v13);
          goto LABEL_48;
        }
        if ( v13 >= SHIDWORD(v42[1].vfptr) && Stat != 1 )
        {
          v50 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v50, StatAward_OverallRank, 1);
          v51 = UFG::qGetSystemTimeUTC();
          UFG::SocialLogData_AwardAchieved::SocialLogData_AwardAchieved(
            &v53,
            (v51 - 116444736000000000i64) / 0x2710,
            v29->mLeaderboardId,
            1);
          v52 = UFG::SocialLogDataManager::Instance();
          UFG::SocialLogDataManager::AddToSaveData(v52, &v53);
          UFG::DataSynchronizer::ShowMedalAward(1, v43, v13);
LABEL_48:
          UFG::SocialLogData_AwardAchieved::~SocialLogData_AwardAchieved(&v53);
        }
      }
    }
  }
}

// File Line: 475
// RVA: 0x431C10
void __fastcall UFG::DataSynchronizer::UpdateStatAwardRankAndBringUpHudIfNeeded(
        UFG::OSuiteLeaderboardData *pLBD,
        int score)
{
  UFG::ProgressionTracker *v4; // rax
  UFG::GameStatTracker *v5; // rax
  int Stat; // ebx
  UFG::StatGamePropertyManager *v7; // rax
  UFG::StatGamePropertyData *PropertyData; // rax
  UFG::StatAwardRank v9; // r8d

  if ( pLBD )
  {
    if ( pLBD->mFlow.mUID == -1
      || (v4 = UFG::ProgressionTracker::Instance(), pLBD->mFlow.mUID == UFG::ProgressionTracker::GetActiveFlow(v4)->mUID) )
    {
      v5 = UFG::GameStatTracker::Instance();
      Stat = UFG::GameStatTracker::GetStat(v5, StatAwardRankIntList, &pLBD->mLeaderboardName);
      v7 = (UFG::StatGamePropertyManager *)UFG::StatAwardPropertyManager::Instance();
      PropertyData = UFG::StatGamePropertyManager::GetPropertyData(v7, pLBD);
      if ( score >= *((_DWORD *)&PropertyData->mFormatType + 1) )
      {
        if ( Stat == 3 )
          return;
        v9 = StatAwardRank_Gold;
        goto LABEL_13;
      }
      if ( score >= SLODWORD(PropertyData[1].vfptr) )
      {
        if ( Stat == 2 )
          return;
        v9 = StatAwardRank_Silver;
        goto LABEL_13;
      }
      if ( score >= SHIDWORD(PropertyData[1].vfptr) && Stat != 1 )
      {
        v9 = StatAwardRank_Bronze;
LABEL_13:
        UFG::DataSynchronizer::UpdateStatAwardRankAndBringUpHudIfNeeded(pLBD, score, v9);
      }
    }
  }
}

// File Line: 515
// RVA: 0x431970
void UFG::DataSynchronizer::UpdateRankingList(void)
{
  int v0; // ebx
  UFG::qSymbol *v1; // rax
  int v2; // r9d
  int v3; // r8d
  unsigned int mUID; // r10d
  __int64 v5; // rdx
  unsigned int v6; // eax
  UFG::qSymbol *v7; // r15
  unsigned int i; // ebp
  __int64 v9; // rsi
  UFG::qSymbol *v10; // rdi
  UFG::GameStatTracker *v11; // rax
  int Stat; // r14d
  UFG::OSuiteLeaderboardData *v13; // rdi
  UFG::StatGamePropertyManager *v14; // rax
  UFG::StatGamePropertyData *PropertyData; // rax
  __int64 v16; // rdi
  UFG::GameStatTracker *v17; // rax
  __int64 v18; // rdi
  __int64 v19; // rdi
  UFG::GameStatTracker *v20; // rax
  __int64 v21; // rdi
  __int64 v22; // rdi
  UFG::GameStatTracker *v23; // rax
  __int64 v24; // rdi
  UFG::qSymbol *v25; // r15
  UFG::GameStatTracker *v26; // rax
  UFG::GameStatTracker *v27; // rax
  UFG::GameStatTracker *v28; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF

  v0 = 0;
  if ( (_S10_6 & 1) == 0 )
  {
    _S10_6 |= 1u;
    UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
    atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  v1 = UFG::qSymbol::create_from_string(&result, "StatAwardsOverall");
  if ( unk_142401518 )
  {
    v2 = 0;
    v3 = unk_142401518 - 1;
    if ( unk_142401518 - 1 >= 0 )
    {
      mUID = v1->mUID;
      do
      {
        v5 = (unsigned int)(v3 + v2) >> 1;
        v6 = *(_DWORD *)(*(_QWORD *)(unk_142401520 + 8 * v5) + 48i64);
        if ( v6 >= mUID )
        {
          if ( v6 <= mUID )
          {
            v7 = *(UFG::qSymbol **)(unk_142401520 + 8 * v5);
            goto LABEL_14;
          }
          v3 = v5 - 1;
        }
        else
        {
          v2 = v5 + 1;
        }
      }
      while ( v2 <= v3 );
    }
  }
  v7 = 0i64;
LABEL_14:
  if ( (_S10_6 & 1) == 0 )
  {
    _S10_6 |= 1u;
    UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
    atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  for ( i = 0; i < dword_1424014F8; ++i )
  {
    v9 = 312i64 * i;
    v10 = (UFG::qSymbol *)(v9 + qword_142401500);
    if ( !*(_DWORD *)(v9 + qword_142401500 + 96) && v10 != v7 )
    {
      v11 = UFG::GameStatTracker::Instance();
      Stat = UFG::GameStatTracker::GetStat(v11, LeaderboardScoreIntList, v10 + 12);
      v13 = (UFG::OSuiteLeaderboardData *)(v9 + qword_142401500);
      v14 = (UFG::StatGamePropertyManager *)UFG::StatAwardPropertyManager::Instance();
      PropertyData = UFG::StatGamePropertyManager::GetPropertyData(v14, v13);
      if ( Stat < *((_DWORD *)&PropertyData->mFormatType + 1) )
      {
        if ( Stat < SLODWORD(PropertyData[1].vfptr) )
        {
          if ( Stat >= SHIDWORD(PropertyData[1].vfptr) )
          {
            v22 = qword_142401500;
            v23 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(v23, StatAwardRankIntList, (UFG::qSymbol *)(v9 + v22 + 48), 1);
            v24 = qword_142401500;
            if ( *(_DWORD *)(v24 + v9 + 304) == UFG::ProgressionTracker::GetDefaultFlow()->mUID )
              ++v0;
          }
        }
        else
        {
          v19 = qword_142401500;
          v20 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v20, StatAwardRankIntList, (UFG::qSymbol *)(v9 + v19 + 48), 2);
          v21 = qword_142401500;
          if ( *(_DWORD *)(v21 + v9 + 304) == UFG::ProgressionTracker::GetDefaultFlow()->mUID )
            v0 += 2;
        }
      }
      else
      {
        v16 = qword_142401500;
        v17 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v17, StatAwardRankIntList, (UFG::qSymbol *)(v9 + v16 + 48), 3);
        v18 = qword_142401500;
        if ( *(_DWORD *)(v18 + v9 + 304) == UFG::ProgressionTracker::GetDefaultFlow()->mUID )
          v0 += 3;
      }
    }
  }
  v25 = v7 + 12;
  v26 = UFG::GameStatTracker::Instance();
  if ( v0 > (int)UFG::GameStatTracker::GetStat(v26, LeaderboardScoreIntList, v25) )
  {
    v27 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v27, LeaderboardScoreIntList, v25, v0);
    v28 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v28, LeaderboardDirtyScoreBoolList, v25, 1);
  }
}

// File Line: 566
// RVA: 0x430BD0
void __fastcall UFG::DataSynchronizer::ShowMedalAward(int medal, UFG::StatAwardPropertyData *prop, int score)
{
  UFG::UIHKScreenHud *Instance; // rdi
  char *PlayerDisplayName; // rbx
  int v8; // ebp
  int v9; // r14d
  unsigned int v10; // edi
  __int64 v11; // rsi
  __int64 v12; // rbx
  __int64 v13; // rbx
  UFG::GameStatTracker *v14; // rax
  int Stat; // r15d
  UFG::OSuiteLeaderboardData *v16; // rbx
  UFG::StatGamePropertyManager *v17; // rax
  UFG::StatGamePropertyData *PropertyData; // rax
  UFG::qString scoreStr; // [rsp+38h] [rbp-40h] BYREF

  Instance = UFG::UIHKScreenHud::getInstance();
  if ( Instance )
  {
    PlayerDisplayName = UFG::UI::GetPlayerDisplayName();
    UFG::qString::qString(&scoreStr);
    UFG::StatAwardPropertyData::FormatScore(prop, &scoreStr, score);
    UFG::UIHKScreenHud::SetSocialAwardMedal(
      Instance,
      medal,
      prop->m_pLBD->mCaption.mData,
      PlayerDisplayName,
      scoreStr.mData);
    UFG::qString::~qString(&scoreStr);
  }
  v8 = 0;
  v9 = 0;
  if ( (_S10_6 & 1) == 0 )
  {
    _S10_6 |= 1u;
    UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
    atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  v10 = 0;
  if ( dword_1424014F8 )
  {
    do
    {
      v11 = 312i64 * v10;
      v12 = qword_142401500;
      if ( !*(_DWORD *)(qword_142401500 + v11 + 96)
        && *(_DWORD *)(v12 + v11 + 304) == UFG::ProgressionTracker::GetDefaultFlow()->mUID )
      {
        v13 = qword_142401500;
        v14 = UFG::GameStatTracker::Instance();
        Stat = UFG::GameStatTracker::GetStat(v14, LeaderboardScoreIntList, (UFG::qSymbol *)(v11 + v13 + 48));
        v16 = (UFG::OSuiteLeaderboardData *)(v11 + qword_142401500);
        v17 = (UFG::StatGamePropertyManager *)UFG::StatAwardPropertyManager::Instance();
        PropertyData = UFG::StatGamePropertyManager::GetPropertyData(v17, v16);
        if ( Stat >= *((_DWORD *)&PropertyData->mFormatType + 1) )
          ++v8;
        if ( Stat >= SLODWORD(PropertyData[1].vfptr) )
          ++v9;
      }
      ++v10;
    }
    while ( v10 < dword_1424014F8 );
    if ( v9 >= 5 )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(40);
    if ( v9 >= 15 )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(41);
    if ( v9 >= 30 )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(42);
    if ( v8 >= 1 )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(43);
    if ( v8 >= 5 )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(44);
    if ( v8 >= 15 )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(45);
    if ( v8 >= 30 )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(46);
  }
}

// File Line: 638
// RVA: 0x4306E0
void __fastcall UFG::DataSynchronizer::SendBeatChallengeMessageIfNeeded(
        UFG::OSuiteLeaderboardData *pLBD,
        int score,
        bool isRace)
{
  bool v3; // di
  int v6; // r14d
  UFG::ProgressionTracker *v7; // rax
  UFG::OnlineManager *v8; // rsi
  UFG::SocialLogDataManager *v9; // rax
  UFG::qList<UFG::SocialLogData,UFG::SocialLogData,1,0> *List; // rax
  __int64 p_mNext; // rbx
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> **v12; // r15
  bool v13; // dl
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mNext; // rax
  bool v16; // cl
  bool v17; // al
  UFG::allocator::free_link *v18; // r15
  UFG::qString *srcOnlineName; // rsi
  UFG::OnlineId *srcOnlineId; // rdi
  unsigned __int64 v21; // rax
  __int64 v22; // rax
  __int64 v23; // rdi
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v24; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v25; // rax
  UFG::SocialLogDataManager *v26; // rax
  UFG::SocialLogDataManager *v27; // rax
  UFG::OSuiteMessenger *v28; // rax
  UFG::GameStatTracker *v29; // rax
  UFG::OSuiteDBLogger *v30; // rdi
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v31; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v32; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v33; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v34; // rax
  UFG::OnlineFriend frnd; // [rsp+50h] [rbp-B0h] BYREF
  UFG::OnlineId *p_m_cOnlineId; // [rsp+B0h] [rbp-50h]
  UFG::OnlineId result; // [rsp+B8h] [rbp-48h] BYREF
  UFG::OnlineId v38; // [rsp+D0h] [rbp-30h] BYREF
  __int64 v39; // [rsp+E8h] [rbp-18h]
  UFG::qString v40; // [rsp+F0h] [rbp-10h] BYREF
  char dest[32]; // [rsp+120h] [rbp+20h] BYREF
  UFG::OnlineManager *v42; // [rsp+1E0h] [rbp+E0h]
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> **i; // [rsp+1F8h] [rbp+F8h]

  if ( pLBD )
  {
    v39 = -2i64;
    v3 = isRace;
    v6 = 0;
    if ( pLBD->mFlow.mUID == -1
      || (v7 = UFG::ProgressionTracker::Instance(), pLBD->mFlow.mUID == UFG::ProgressionTracker::GetActiveFlow(v7)->mUID) )
    {
      if ( score )
      {
        v8 = UFG::OnlineManager::Instance();
        v42 = v8;
        v9 = UFG::SocialLogDataManager::Instance();
        List = UFG::SocialLogDataManager::GetList(v9);
        p_mNext = (__int64)&List->mNode.mNext[-2].mNext;
        v12 = &List[-2].mNode.mNext;
        for ( i = &List[-2].mNode.mNext;
              (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> **)p_mNext != v12;
              p_mNext = *(_QWORD *)(p_mNext + 32) - 24i64 )
        {
          v13 = 1;
          if ( *(_DWORD *)(p_mNext + 44) == 4 )
          {
            v6 |= 1u;
            if ( *(_QWORD *)(p_mNext + 144) == UFG::OnlineManager::GetOnlineId(v8, &result)->m_SteamId.m_steamid.m_unAll64Bits )
              v13 = 0;
          }
          if ( (v6 & 1) != 0 )
          {
            v6 &= ~1u;
            mPrev = result.mPrev;
            mNext = result.mNext;
            result.mPrev->mNext = result.mNext;
            mNext->mPrev = mPrev;
            result.mPrev = &result;
            result.mNext = &result;
          }
          if ( !v13 && *(_DWORD *)(p_mNext + 56) == pLBD->mLeaderboardId && !*(_DWORD *)(p_mNext + 192) )
          {
            frnd.mPrev = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
            frnd.mNext = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
            frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable;
            p_m_cOnlineId = &frnd.m_cOnlineId;
            frnd.m_cOnlineId.mPrev = &frnd.m_cOnlineId;
            frnd.m_cOnlineId.mNext = &frnd.m_cOnlineId;
            frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits &= 0xFF0FFFFF00000000ui64;
            HIBYTE(frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits) = 0;
            *((_DWORD *)&frnd.m_cOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
            UFG::qString::qString(&frnd.m_sOnlineName);
            if ( UFG::OnlineFriendManager::FindFriend(
                   (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **)&frnd,
                   (UFG::OnlineId *)(p_mNext + 64)) )
            {
              v16 = v3 && score < *(_DWORD *)(p_mNext + 60);
              v17 = !v3 && score > *(_DWORD *)(p_mNext + 60);
              if ( v16 || v17 )
              {
                v18 = UFG::qMalloc(0xD0ui64, "DataSynchronizer", 0i64);
                p_m_cOnlineId = (UFG::OnlineId *)v18;
                if ( v18 )
                {
                  srcOnlineName = UFG::OnlineManager::GetOnlineName(v8, &v40);
                  srcOnlineId = UFG::OnlineManager::GetOnlineId(v42, &v38);
                  v6 |= 6u;
                  v21 = UFG::OnlineUtil::CurrentTimeMillis();
                  UFG::SocialLogData_BeatChallenge::SocialLogData_BeatChallenge(
                    (UFG::SocialLogData_BeatChallenge *)v18,
                    v21,
                    pLBD->mLeaderboardId,
                    score,
                    srcOnlineId,
                    srcOnlineName,
                    &frnd.m_cOnlineId,
                    &frnd.m_sOnlineName);
                  v23 = v22;
                  v8 = v42;
                }
                else
                {
                  v23 = 0i64;
                }
                if ( (v6 & 4) != 0 )
                {
                  v6 &= ~4u;
                  v24 = v38.mPrev;
                  v25 = v38.mNext;
                  v38.mPrev->mNext = v38.mNext;
                  v25->mPrev = v24;
                  v38.mPrev = &v38;
                  v38.mNext = &v38;
                }
                if ( (v6 & 2) != 0 )
                {
                  v6 &= ~2u;
                  UFG::qString::~qString(&v40);
                }
                *(_DWORD *)(v23 + 192) = 1;
                v26 = UFG::SocialLogDataManager::Instance();
                UFG::SocialLogDataManager::AddToSaveData(v26, (UFG::SocialLogData *)v23);
                v27 = UFG::SocialLogDataManager::Instance();
                UFG::SocialLogDataManager::UpdateChallengeStatus(v27, (UFG::SocialLogData *)p_mNext);
                v28 = UFG::OSuiteMessenger::Instance();
                UFG::OSuiteMessenger::Send(v28, (UFG::OSuiteMessage *)v23, &frnd.m_cOnlineId, 0i64);
                v29 = UFG::GameStatTracker::Instance();
                UFG::GameStatTracker::ApplyDelta(v29, SocialChallengeBeaten, 1);
                v30 = UFG::OSuiteDBLogger::Instance();
                if ( UFG::OSuiteDBLogger::CreateMetric(v30, "SocialInteraction") )
                {
                  UFG::qSPrintf(dest, 128, "s_%s", "Event");
                  OSuite::ZMetric::SetProperty(v30->m_pMetric, dest, "Challenge Beaten");
                  UFG::OSuiteDBLogger::SubmitMetric(v30, 0);
                }
                v12 = i;
                v3 = isRace;
              }
            }
            frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable;
            UFG::qString::~qString(&frnd.m_sOnlineName);
            p_m_cOnlineId = &frnd.m_cOnlineId;
            v31 = frnd.m_cOnlineId.mPrev;
            v32 = frnd.m_cOnlineId.mNext;
            frnd.m_cOnlineId.mPrev->mNext = frnd.m_cOnlineId.mNext;
            v32->mPrev = v31;
            frnd.m_cOnlineId.mPrev = &frnd.m_cOnlineId;
            frnd.m_cOnlineId.mNext = &frnd.m_cOnlineId;
            v33 = frnd.mPrev;
            v34 = frnd.mNext;
            frnd.mPrev->mNext = frnd.mNext;
            v34->mPrev = v33;
            frnd.mPrev = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
            frnd.mNext = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
          }
        }
      }
    }
  }
}

// File Line: 708
// RVA: 0x42AD00
void __fastcall UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(UFG::OSuiteLeaderboardData *pLBD, int delta)
{
  UFG::ProgressionTracker *v4; // rax
  UFG::GameStatTracker *v5; // rax
  int v6; // ebx
  UFG::GameStatTracker *v7; // rax
  UFG::GameStatTracker *v8; // rax

  if ( pLBD )
  {
    if ( pLBD->mCategory == LeaderboardCategory_StatAward )
    {
      if ( pLBD->mFlow.mUID == -1
        || (v4 = UFG::ProgressionTracker::Instance(),
            pLBD->mFlow.mUID == UFG::ProgressionTracker::GetActiveFlow(v4)->mUID) )
      {
        v5 = UFG::GameStatTracker::Instance();
        v6 = UFG::GameStatTracker::GetStat(v5, LeaderboardScoreIntList, &pLBD->mLeaderboardName) + delta;
        v7 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v7, LeaderboardScoreIntList, &pLBD->mLeaderboardName, v6);
        v8 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v8, LeaderboardDirtyScoreBoolList, &pLBD->mLeaderboardName, 1);
        UFG::DataSynchronizer::UpdateStatAwardRankAndBringUpHudIfNeeded(pLBD, v6);
      }
    }
  }
}

// File Line: 732
// RVA: 0x42ADC0
void __fastcall UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(UFG::OSuiteLeaderboardData *lbd, float delta)
{
  UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(lbd, (int)(float)(delta * 1000.0));
}

// File Line: 738
// RVA: 0x430AF0
void __fastcall UFG::DataSynchronizer::SetMaxToGlobalSnapshot(UFG::OSuiteLeaderboardData *pLBD, int max)
{
  UFG::ProgressionTracker *v4; // rax
  UFG::GameStatTracker *v5; // rax
  UFG::GameStatTracker *v6; // rax
  UFG::GameStatTracker *v7; // rax

  if ( pLBD )
  {
    if ( pLBD->mCategory == LeaderboardCategory_StatAward )
    {
      if ( pLBD->mFlow.mUID == -1
        || (v4 = UFG::ProgressionTracker::Instance(),
            pLBD->mFlow.mUID == UFG::ProgressionTracker::GetActiveFlow(v4)->mUID) )
      {
        v5 = UFG::GameStatTracker::Instance();
        if ( max > (int)UFG::GameStatTracker::GetStat(v5, LeaderboardScoreIntList, &pLBD->mLeaderboardName) )
        {
          v6 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v6, LeaderboardScoreIntList, &pLBD->mLeaderboardName, max);
          v7 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v7, LeaderboardDirtyScoreBoolList, &pLBD->mLeaderboardName, 1);
          UFG::DataSynchronizer::UpdateStatAwardRankAndBringUpHudIfNeeded(pLBD, max);
        }
      }
    }
  }
}

// File Line: 763
// RVA: 0x430BA0
void __fastcall UFG::DataSynchronizer::SetMaxToGlobalSnapshot(UFG::OSuiteLeaderboardData *lbd, float max)
{
  UFG::DataSynchronizer::SetMaxToGlobalSnapshot(lbd, (int)(float)(max * 1000.0));
}

// File Line: 769
// RVA: 0x431700
void __fastcall UFG::DataSynchronizer::UpdateOptionSaveDataCallback(
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuite::ZOFeed *v2; // rax
  OSuite::ZAtomEntry *Entry; // rax
  OSuite::ZOEntry *v4; // r15
  UFG::OSuiteLeaderboardManager *v5; // rsi
  unsigned int i; // r14d
  UFG::OSuiteLeaderboardData *p; // rax
  __int64 v8; // rbp
  int mCategory; // edi
  __int64 mLeaderboardLocalId; // r8
  OSuite::ZOProperty *v11; // rax
  UFG::OSuiteLeaderboardData *v12; // rbx
  UFG::GameStatTracker *v13; // rax
  UFG::PersistentData::MapInt *MapInt; // rax
  int Status; // eax
  bool v16; // cc
  UFG::OSuiteLeaderboardData *v17; // rbx
  UFG::GameStatTracker *v18; // rax
  UFG::OSuiteLeaderboardData *v19; // rbx
  UFG::GameStatTracker *v20; // rax
  char dest[16]; // [rsp+20h] [rbp-38h] BYREF
  int outValue; // [rsp+60h] [rbp+8h] BYREF

  if ( pData->Status.eError )
  {
    UFG::DataSynchronizer::m_bIsOptionSaveDataSynchronized = 0;
  }
  else
  {
    v2 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOFeed>(pWebServiceClient, &pData->URL);
    if ( v2 )
    {
      Entry = OSuite::ZAtomFeed::GetEntry(v2, 0);
      v4 = (OSuite::ZOEntry *)Entry;
      if ( Entry )
      {
        if ( Entry->vfptr[1].__vecDelDtor(Entry, OSuite::ZOEntry::s_nClassId) )
        {
          v5 = UFG::OSuiteLeaderboardManager::Instance();
          for ( i = 0; i < v5->mLeaderboardData.size; ++i )
          {
            UFG::qMemSet(dest, 0, 0x10u);
            p = v5->mLeaderboardData.p;
            v8 = i;
            mCategory = p[v8].mCategory;
            mLeaderboardLocalId = (unsigned int)p[v8].mLeaderboardLocalId;
            if ( mCategory )
            {
              switch ( mCategory )
              {
                case 1:
                  UFG::qSPrintf(dest, "i32_lbsg%02d", mLeaderboardLocalId);
                  break;
                case 2:
                  UFG::qSPrintf(dest, "i32_lbm%02d", mLeaderboardLocalId);
                  break;
                case 3:
                  UFG::qSPrintf(dest, "i32_lbr%02d", mLeaderboardLocalId);
                  break;
                default:
                  continue;
              }
            }
            else
            {
              UFG::qSPrintf(dest, "i32_lbsa%02d", mLeaderboardLocalId);
            }
            outValue = 0;
            v11 = OSuite::ZOEntry::Property(v4, dest);
            if ( v11 )
            {
              OSuite::ZOProperty::GetValue(v11, &outValue);
              v12 = v5->mLeaderboardData.p;
              v13 = UFG::GameStatTracker::Instance();
              MapInt = UFG::GameStatTracker::GetMapInt(v13, LeaderboardScoreIntList);
              Status = UFG::PersistentData::MapInt::GetStatus(MapInt, &v12[v8].mLeaderboardName);
              if ( mCategory <= 2 )
              {
                v16 = Status <= outValue;
                if ( Status >= outValue )
                  goto LABEL_19;
              }
              else if ( Status && Status <= outValue )
              {
                v16 = outValue <= Status;
LABEL_19:
                if ( !v16 )
                {
                  v17 = v5->mLeaderboardData.p;
                  v18 = UFG::GameStatTracker::Instance();
                  UFG::GameStatTracker::SetStat(v18, LeaderboardDirtyScoreBoolList, &v17[v8].mLeaderboardName, 1);
                }
                continue;
              }
              v19 = v5->mLeaderboardData.p;
              v20 = UFG::GameStatTracker::Instance();
              UFG::GameStatTracker::SetStat(v20, LeaderboardScoreIntList, &v19[v8].mLeaderboardName, outValue);
            }
          }
          UFG::DataSynchronizer::UpdateRankingList();
        }
      }
    }
  }
}

// File Line: 869
// RVA: 0x431900
void UFG::DataSynchronizer::UpdateOptionSaveDataIfNeeded(void)
{
  UFG::OSuiteManager *v0; // rax
  void (__fastcall *v1)(OSuite::fastdelegate::detail::GenericClass *); // rax
  UFG::OSuiteLeaderboardManager *v2; // rax
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> callback; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::DataSynchronizer::m_bIsOptionSaveDataSynchronized )
  {
    v0 = UFG::OSuiteManager::Instance();
    if ( UFG::DataSynchronizer::s_bPastOptionLoad && v0->m_bConnected )
    {
      v1 = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>::InvokeStaticFunction;
      UFG::DataSynchronizer::m_bIsOptionSaveDataSynchronized = 1;
      callback.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)UFG::DataSynchronizer::UpdateOptionSaveDataCallback;
      if ( !UFG::DataSynchronizer::UpdateOptionSaveDataCallback )
        v1 = 0i64;
      callback.m_Closure.m_pFunction = v1;
      v2 = UFG::OSuiteLeaderboardManager::Instance();
      UFG::OSuiteLeaderboardManager::GetPlayerStats(v2, &callback);
    }
  }
}

