// File Line: 21
// RVA: 0x152C170
__int64 UFG::GameStatAction::_dynamic_initializer_for__g_CopScoreEventAffectors__()
{
  `eh vector constructor iterator'(
    g_CopScoreEventAffectors,
    0x50ui64,
    11,
    (void (__fastcall *)(void *))UFG::ScoreAffector::ScoreAffector);
  return atexit(UFG::GameStatAction::_dynamic_atexit_destructor_for__g_CopScoreEventAffectors__);
}

// File Line: 22
// RVA: 0x152C1B0
__int64 UFG::GameStatAction::_dynamic_initializer_for__g_TriadScoreEventAffectors__()
{
  `eh vector constructor iterator'(
    g_TriadScoreEventAffectors,
    0x50ui64,
    14,
    (void (__fastcall *)(void *))UFG::ScoreAffector::ScoreAffector);
  return atexit(UFG::GameStatAction::_dynamic_atexit_destructor_for__g_TriadScoreEventAffectors__);
}

// File Line: 33
// RVA: 0x4ACE20
bool __fastcall UFG::GameStatAction::MissionScoring::IsTrackingCopScoring()
{
  unsigned int v0; // eax
  __int64 v1; // rbx

  v0 = _S19_1;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    v0 = _S19_1;
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v1 = unk_14240B6D0;
  if ( !(v0 & 1) )
  {
    _S19_1 = v0 | 1;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  return UFG::GameStatAction::MissionScoring::ms_TrackScoring
      && UFG::GameStatAction::MissionScoring::ms_TrackCopScoring
      && v1
      && !*(_BYTE *)(v1 + 331)
      && (!unk_14240B6D8 || !*(_BYTE *)(unk_14240B6D8 + 308i64));
}

// File Line: 44
// RVA: 0x4ACEF0
bool __fastcall UFG::GameStatAction::MissionScoring::IsTrackingTriadScoring()
{
  unsigned int v0; // eax
  __int64 v1; // rbx

  v0 = _S19_1;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    v0 = _S19_1;
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v1 = unk_14240B6D0;
  if ( !(v0 & 1) )
  {
    _S19_1 = v0 | 1;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  return UFG::GameStatAction::MissionScoring::ms_TrackScoring
      && UFG::GameStatAction::MissionScoring::ms_TrackTriadScoring
      && v1
      && !*(_BYTE *)(v1 + 331)
      && (!unk_14240B6D8 || !*(_BYTE *)(unk_14240B6D8 + 309i64));
}

// File Line: 66
// RVA: 0x4AB460
void __fastcall UFG::GameStatAction::InitializeAffector(UFG::qPropertySet *pProperties, UFG::ScoreAffector *affector, unsigned int hash)
{
  UFG::qPropertySet *v3; // rbx
  UFG::ScoreAffector *v4; // r14
  UFG::qSymbol *v5; // rax
  UFG::qPropertyList *v6; // rax
  UFG::qPropertyList *v7; // rsi
  unsigned int v8; // ebp
  unsigned int v9; // ebx
  char *v10; // rax
  UFG::qPropertySet *v11; // rdi
  UFG::qSymbol *v12; // rax
  UFG::qSymbol *v13; // rax
  UFG::qSymbol *v14; // rax
  UFG::qSymbol *v15; // rax
  char *v16; // rax
  const char *v17; // rdx
  UFG::qWiseSymbol v18; // [rsp+20h] [rbp-28h]
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+20h]

  v3 = pProperties;
  v4 = affector;
  UFG::qSymbol::qSymbol(&result, hash);
  v5 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v18, 0xACC932CE);
  v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, v5, DEPTH_RECURSE);
  v7 = v6;
  if ( v6 )
  {
    v8 = v6->mNumElements;
    v9 = 0;
    if ( v8 )
    {
      while ( 1 )
      {
        v10 = UFG::qPropertyList::GetValuePtr(v7, 0x1Au, v9);
        if ( v10 && *(_QWORD *)v10 )
          v11 = (UFG::qPropertySet *)&v10[*(_QWORD *)v10];
        else
          v11 = 0i64;
        if ( v11->mName.mUID == result.mUID )
          break;
        if ( ++v9 >= v8 )
          return;
      }
      v12 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v18, 0x63297AE9u);
      v4->mPoints = *UFG::qPropertySet::Get<float>(v11, v12, DEPTH_RECURSE);
      v13 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v18, 0x4E32B7F6u);
      v4->mMultiplierReduction = *UFG::qPropertySet::Get<float>(v11, v13, DEPTH_RECURSE);
      v14 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v18, 0x1169F74Du);
      v4->mMultiplierResetTimer = *UFG::qPropertySet::Get<float>(v11, v14, DEPTH_RECURSE);
      v15 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v18, 0xC65626FC);
      v16 = PropertyUtils::Get<char const *>(v11, v15, DEPTH_RECURSE);
      v17 = &customWorldMapCaption;
      if ( v16 )
        v17 = v16;
      UFG::qString::Set(&v4->mCaption, v17);
    }
  }
}

// File Line: 93
// RVA: 0x4AA900
void UFG::GameStatAction::MissionScoring::Initialize(void)
{
  UFG::qPropertySet *v0; // rbx
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h]

  UFG::qSymbol::qSymbol(&result, 0x7B75E554u);
  v0 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&result);
  UFG::GameStatAction::InitializeAffector(v0, g_CopScoreEventAffectors, 0xB6D126C9);
  UFG::GameStatAction::InitializeAffector(v0, &affector, 0xB57FEDF7);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142406230, 0x5CEA676Cu);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142406280, 0x51437BE6u);
  UFG::GameStatAction::InitializeAffector(v0, &stru_1424062D0, 0x424FA9D4u);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142406320, 0x88E47EBE);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142406370, 0xD536B433);
  UFG::GameStatAction::InitializeAffector(v0, &stru_1424063C0, 0xE2D6C5A2);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142406410, 0xAC71CDD1);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142406460, 0xE69819DF);
  UFG::GameStatAction::InitializeAffector(v0, &stru_1424064B0, 0xF50AAA9A);
  UFG::GameStatAction::InitializeAffector(v0, g_TriadScoreEventAffectors, 0x42FE2E2Du);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142407B80, 0x27351EB4u);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142407BD0, 0xDDA4ADBC);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142407C20, 0xECCADBCE);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142407C70, 0xC369DE2F);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142407CC0, 0x8119F47C);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142407D10, 0x770B5023u);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142407D60, 0xD168A494);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142407DB0, 0x8E4B8433);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142407E00, 0x44904A29u);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142407E50, 0x554FE044u);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142407EA0, 0x1A361BC2u);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142407EF0, 0xC8692B19);
  UFG::GameStatAction::InitializeAffector(v0, &stru_142407F40, 0x4CD068FBu);
}

// File Line: 126
// RVA: 0x4B0950
void __fastcall UFG::GameStatAction::MissionScoring::LogCopEvent(UFG::GameStatAction::MissionScoring::CopScoreEvent e, int customScore, const char *customCaption)
{
  const char *v3; // r14
  int v4; // ebp
  __int64 v5; // rdi
  UFG::ScoreAffector *v6; // rcx
  int v7; // ebx
  const char *v8; // rsi
  int v9; // edi
  int v10; // edi
  UFG::GameStatTracker *v11; // rax
  UFG::GameStatTracker *v12; // rbx

  v3 = customCaption;
  v4 = customScore;
  v5 = e;
  if ( UFG::GameStatAction::MissionScoring::IsTrackingCopScoring() )
  {
    v6 = &g_CopScoreEventAffectors[v5];
    v7 = (signed int)v6->mPoints;
    v8 = v6->mCaption.mData;
    v9 = v5 - 9;
    if ( v9 )
    {
      if ( v9 == 1 )
      {
        v7 = v4;
        v8 = v3;
      }
    }
    else
    {
      v7 = -v4;
      v8 = "$HUD_ScoreEvent_FailParkour";
    }
    v10 = (signed int)(float)((float)v7 * UFG::ScoreAffector::Trigger(v6));
    if ( v10 > 0 )
    {
      v11 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v11 + 6216) & 1) )
      {
        v11->mpSnapshots[0]->mInts[155].mValue += v10;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          v12 = &sGameStatTracker;
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          }
          if ( UFG::GameStatTracker::mspInstance )
            v12 = UFG::GameStatTracker::mspInstance;
          UFG::GameStatTracker::mspInstance = v12;
        }
      }
      UFG::UIHK_XPFlasherWidget::AddXP(UFG::UIHKScreenHud::XPFlasher, v10, XP_TYPE_COP, v8);
    }
  }
}

// File Line: 152
// RVA: 0x4B0A80
void __fastcall UFG::GameStatAction::MissionScoring::LogTriadEvent(UFG::GameStatAction::MissionScoring::TriadScoreEvent e, int customScore, const char *customCaption)
{
  const char *v3; // rbp
  int v4; // er14
  __int64 v5; // rbx
  UFG::ScoreAffector *v6; // rcx
  signed int v7; // edi
  const char *v8; // rsi
  int v9; // ebx
  int v10; // edi
  UFG::GameStatTracker *v11; // rax
  UFG::GameStatTracker *v12; // rbx

  v3 = customCaption;
  v4 = customScore;
  v5 = e;
  if ( UFG::GameStatAction::MissionScoring::IsTrackingTriadScoring() )
  {
    v6 = &g_TriadScoreEventAffectors[v5];
    v7 = (signed int)v6->mPoints;
    v8 = v6->mCaption.mData;
    v9 = v5 - 12;
    if ( !v9 || v9 == 1 )
    {
      v8 = v3;
      v7 = v4;
    }
    v10 = (signed int)(float)((float)v7 * UFG::ScoreAffector::Trigger(v6));
    if ( v10 > 0 )
    {
      v11 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v11 + 6216) & 1) )
      {
        v11->mpSnapshots[0]->mInts[156].mValue += v10;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          v12 = &sGameStatTracker;
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          }
          if ( UFG::GameStatTracker::mspInstance )
            v12 = UFG::GameStatTracker::mspInstance;
          UFG::GameStatTracker::mspInstance = v12;
        }
      }
      UFG::UIHK_XPFlasherWidget::AddXP(UFG::UIHKScreenHud::XPFlasher, v10, XP_TYPE_TRIAD, v8);
    }
  }
}

// File Line: 177
// RVA: 0x4BF920
void __fastcall UFG::GameStatAction::MissionScoring::StartTracking(UFG::qPropertySet *pProperties)
{
  UFG::qPropertySet *v1; // rbx
  UFG::qSymbol *v2; // rax
  bool *v3; // rax
  UFG::qSymbol *v4; // rax
  bool *v5; // rax
  UFG::qSymbol *v6; // rcx
  UFG::qSymbol *v7; // rax
  bool *v8; // rax
  bool *v9; // rcx
  UFG::qSymbol *v10; // rax
  bool *v11; // rax
  bool *v12; // rcx
  UFG::qSymbol *v13; // rax
  int *v14; // rax
  int *v15; // rcx
  UFG::qSymbol *v16; // rax
  int *v17; // rax
  int *v18; // rcx
  UFG::qSymbol *v19; // rax
  int *v20; // rax
  int *v21; // rcx
  UFG::qSymbol *v22; // rax
  float *v23; // rax
  float *v24; // rcx
  UFG::qSymbol *v25; // rax
  float *v26; // rax
  float *v27; // rcx
  UFG::GameStatTracker *v28; // rax
  UFG::SimObjectCharacter *v29; // rax
  UFG::SimComponent *v30; // rdi
  unsigned __int8 v31; // cl
  signed __int64 v32; // rbx
  UFG::ScoreAffector *v33; // rbx
  signed __int64 v34; // rdi
  UFG::ScoreAffector *v35; // rbx
  signed __int64 v36; // rdi
  UFG::qSymbol v37; // [rsp+30h] [rbp+8h]
  UFG::qSymbol result; // [rsp+38h] [rbp+10h]

  v1 = pProperties;
  if ( !sInitialized_0 )
  {
    sInitialized_0 = 1;
    UFG::GameStatAction::MissionScoring::Initialize();
  }
  if ( v1 )
  {
    LOBYTE(v37.mUID) = 0;
    v2 = UFG::qSymbol::create_from_string(&result, "FixedMissionScoring");
    v3 = UFG::qPropertySet::Get<bool>(v1, v2, DEPTH_RECURSE);
    if ( v3 && *v3 )
    {
      UFG::GameStatAction::MissionScoring::ms_TrackScoring = 0;
    }
    else
    {
      LOBYTE(v37.mUID) = 0;
      v4 = UFG::qSymbol::create_from_string(&result, "EnableMissionScoring");
      v5 = UFG::qPropertySet::Get<bool>(v1, v4, DEPTH_RECURSE);
      v6 = &v37;
      if ( v5 )
        v6 = (UFG::qSymbol *)v5;
      UFG::GameStatAction::MissionScoring::ms_TrackScoring = v6->mUID;
    }
    v7 = UFG::qSymbol::create_from_string(&v37, "EnableCopScoring");
    v8 = UFG::qPropertySet::Get<bool>(v1, v7, DEPTH_RECURSE);
    v9 = &UFG::GameStatAction::MissionScoring::ms_TrackCopScoring;
    if ( v8 )
      v9 = v8;
    UFG::GameStatAction::MissionScoring::ms_TrackCopScoring = *v9;
    v10 = UFG::qSymbol::create_from_string(&v37, "EnableTriadScoring");
    v11 = UFG::qPropertySet::Get<bool>(v1, v10, DEPTH_RECURSE);
    v12 = &UFG::GameStatAction::MissionScoring::ms_TrackTriadScoring;
    if ( v11 )
      v12 = v11;
    UFG::GameStatAction::MissionScoring::ms_TrackTriadScoring = *v12;
    v13 = UFG::qSymbol::create_from_string(&v37, "CopStartingScore");
    v14 = UFG::qPropertySet::Get<long>(v1, v13, DEPTH_RECURSE);
    v15 = &UFG::GameStatAction::MissionScoring::ms_CopStartingScore;
    if ( v14 )
      v15 = v14;
    UFG::GameStatAction::MissionScoring::ms_CopStartingScore = *v15;
    v16 = UFG::qSymbol::create_from_string(&v37, "TriadBaseScore");
    v17 = UFG::qPropertySet::Get<long>(v1, v16, DEPTH_RECURSE);
    v18 = &UFG::GameStatAction::MissionScoring::ms_TriadBaseScore;
    if ( v17 )
      v18 = v17;
    UFG::GameStatAction::MissionScoring::ms_TriadBaseScore = *v18;
    v19 = UFG::qSymbol::create_from_string(&v37, "MaxTriadScore");
    v20 = UFG::qPropertySet::Get<long>(v1, v19, DEPTH_RECURSE);
    v21 = &UFG::GameStatAction::MissionScoring::ms_MaxTriadScore;
    if ( v20 )
      v21 = v20;
    UFG::GameStatAction::MissionScoring::ms_MaxTriadScore = *v21;
    v22 = UFG::qSymbol::create_from_string(&v37, "TimeAttackTargetTime");
    v23 = UFG::qPropertySet::Get<float>(v1, v22, DEPTH_RECURSE);
    v24 = &UFG::GameStatAction::MissionScoring::ms_TimeAttackTargetTime;
    if ( v23 )
      v24 = v23;
    UFG::GameStatAction::MissionScoring::ms_TimeAttackTargetTime = *v24;
    v25 = UFG::qSymbol::create_from_string(&v37, "TimeAttackZeroTime");
    v26 = UFG::qPropertySet::Get<float>(v1, v25, DEPTH_RECURSE);
    v27 = &UFG::GameStatAction::MissionScoring::ms_TimeAttackZeroTime;
    if ( v26 )
      v27 = v26;
    UFG::GameStatAction::MissionScoring::ms_TimeAttackZeroTime = *v27;
    v28 = UFG::GameStatTracker::Instance();
    UFG::SimpleTimer::Resume(&v28->mpSnapshots[0]->mTimes[26].mTimer);
    if ( UFG::GetLocalPlayer() && (v29 = UFG::GetLocalPlayer()) != 0i64 )
      v30 = v29->m_Components.p[20].m_pComponent;
    else
      v30 = 0i64;
    if ( v30 )
    {
      v31 = *(_BYTE *)(*(_QWORD *)&v30[1].m_Flags + 89i64);
      if ( v31 )
      {
        v32 = 56i64 * v31;
        UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v32 + *(_QWORD *)&v30[1].m_TypeUID), 0i64);
        UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v32 + *(_QWORD *)&v30[1].m_TypeUID), 0);
      }
    }
  }
  else
  {
    UFG::GameStatAction::MissionScoring::ms_TrackScoring = 0;
    UFG::GameStatAction::MissionScoring::ms_TrackCopScoring = 0;
    UFG::GameStatAction::MissionScoring::ms_CopStartingScore = 0;
    UFG::GameStatAction::MissionScoring::ms_TriadBaseScore = 0;
    UFG::GameStatAction::MissionScoring::ms_MaxTriadScore = 0;
    UFG::GameStatAction::MissionScoring::ms_TimeAttackTargetTime = 0.0;
    UFG::GameStatAction::MissionScoring::ms_TimeAttackZeroTime = 0.0;
    UFG::GameStatAction::MissionScoring::ms_TrackTriadScoring = 0;
  }
  v33 = g_CopScoreEventAffectors;
  v34 = 11i64;
  do
  {
    UFG::ScoreAffector::Reset(v33);
    ++v33;
    --v34;
  }
  while ( v34 );
  v35 = g_TriadScoreEventAffectors;
  v36 = 14i64;
  do
  {
    UFG::ScoreAffector::Reset(v35);
    ++v35;
    --v36;
  }
  while ( v36 );
}

// File Line: 239
// RVA: 0x4A0AE0
void UFG::GameStatAction::MissionScoring::FinishedTracking(void)
{
  UFG::GameStatTracker *v0; // rbx

  UFG::GameStatAction::MissionScoring::ResetScore();
  UFG::GameStatAction::MissionScoring::ms_TrackScoring = 0;
  UFG::GameStatAction::MissionScoring::ms_TrackCopScoring = 0;
  UFG::GameStatAction::MissionScoring::ms_TrackTriadScoring = 0;
  UFG::GameStatAction::MissionScoring::ms_CopStartingScore = 0;
  UFG::GameStatAction::MissionScoring::ms_TriadBaseScore = 0;
  UFG::GameStatAction::MissionScoring::ms_MaxTriadScore = 0;
  UFG::GameStatAction::MissionScoring::ms_TimeAttackTargetTime = 0.0;
  UFG::GameStatAction::MissionScoring::ms_TimeAttackZeroTime = 0.0;
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
  UFG::SimpleTimer::Stop(&v0->mpSnapshots[0]->mTimes[26].mTimer);
}

// File Line: 257
// RVA: 0x4C42F0
void __fastcall UFG::GameStatAction::MissionScoring::Update(float deltaTime)
{
  UFG::ScoreAffector *v1; // rbx
  signed __int64 v2; // rdi
  float v3; // xmm6_4
  UFG::ScoreAffector *v4; // rbx
  signed __int64 v5; // rdi

  v1 = g_CopScoreEventAffectors;
  v2 = 11i64;
  v3 = deltaTime;
  do
  {
    UFG::ScoreAffector::Update(v1, v3);
    ++v1;
    --v2;
  }
  while ( v2 );
  v4 = g_TriadScoreEventAffectors;
  v5 = 14i64;
  do
  {
    UFG::ScoreAffector::Update(v4, v3);
    ++v4;
    --v5;
  }
  while ( v5 );
}

// File Line: 269
// RVA: 0x4B71D0
void UFG::GameStatAction::MissionScoring::ResetScore(void)
{
  unsigned int v0; // ecx
  UFG::GameStatTracker *v1; // rbx
  UFG::GameStatTracker *v2; // rdx
  UFG::GameStatTracker *v3; // rax
  UFG::GameStatTracker *v4; // rdx
  UFG::GameStatTracker *v5; // rax
  UFG::SimpleTimer *v6; // rbx
  UFG::qSymbol mapid; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v8; // [rsp+48h] [rbp+10h]

  v0 = _S12_6;
  v1 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v0 = _S12_6;
  }
  v2 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  if ( !(v0 & 1) )
  {
    _S12_6 = v0 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v0 = _S12_6;
    v2 = UFG::GameStatTracker::mspInstance;
  }
  v3 = &sGameStatTracker;
  if ( v2 )
    v3 = v2;
  UFG::GameStatTracker::mspInstance = v3;
  if ( !(v0 & 1) )
  {
    _S12_6 = v0 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v0 = _S12_6;
    v3 = UFG::GameStatTracker::mspInstance;
  }
  v4 = &sGameStatTracker;
  if ( v3 )
    v4 = v3;
  UFG::GameStatTracker::mspInstance = v4;
  if ( !(*((_BYTE *)v4 + 6216) & 1) )
  {
    v4->mpSnapshots[0]->mInts[155].mValue = 0;
    v8 = &mapid;
    mapid.mUID = UFG::gNullQSymbol.mUID;
    UFG::GameStatAction::PostStat::Achieve(PDT_INT, 155, (__int64)&mapid);
    v0 = _S12_6;
    v4 = UFG::GameStatTracker::mspInstance;
  }
  if ( !(v0 & 1) )
  {
    _S12_6 = v0 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v0 = _S12_6;
    v4 = UFG::GameStatTracker::mspInstance;
  }
  v5 = &sGameStatTracker;
  if ( v4 )
    v5 = v4;
  UFG::GameStatTracker::mspInstance = v5;
  if ( !(*((_BYTE *)v5 + 6216) & 1) )
  {
    v5->mpSnapshots[0]->mInts[156].mValue = 0;
    v8 = &mapid;
    mapid.mUID = UFG::gNullQSymbol.mUID;
    UFG::GameStatAction::PostStat::Achieve(PDT_INT, 156, (__int64)&mapid);
    v0 = _S12_6;
    v5 = UFG::GameStatTracker::mspInstance;
  }
  if ( !(v0 & 1) )
  {
    _S12_6 = v0 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v5 = UFG::GameStatTracker::mspInstance;
  }
  if ( v5 )
    v1 = v5;
  UFG::GameStatTracker::mspInstance = v1;
  v6 = (UFG::SimpleTimer *)v1->mpSnapshots[0];
  UFG::SimpleTimer::SetElapsedTime(v6 + 26, 0.0);
  UFG::SimpleTimer::Start(v6 + 26);
}

// File Line: 281
// RVA: 0x4A20B0
__int64 __fastcall UFG::GameStatAction::MissionScoring::GetCopScore(bool clamped)
{
  bool v1; // di
  UFG::GameStatTracker *v2; // rbx
  unsigned int v3; // ecx
  __int64 result; // rax

  v1 = clamped;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = UFG::GameStatAction::MissionScoring::ms_CopStartingScore - v2->mpSnapshots[0]->mInts[155].mValue;
  if ( !v1 )
    return v3;
  result = 0i64;
  if ( (signed int)v3 > 0 )
    result = v3;
  return result;
}

// File Line: 295
// RVA: 0x4A7040
__int64 __fastcall UFG::GameStatAction::MissionScoring::GetTriadScore(bool clamped)
{
  bool v1; // di
  UFG::GameStatTracker *v2; // rbx
  __int64 result; // rax
  float v4; // xmm0_4

  v1 = clamped;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  result = (unsigned int)(v2->mpSnapshots[0]->mInts[156].mValue + UFG::GameStatAction::MissionScoring::ms_TriadBaseScore);
  if ( v1 )
  {
    v4 = (float)(signed int)result;
    if ( (float)(signed int)result >= (float)UFG::GameStatAction::MissionScoring::ms_MaxTriadScore )
      v4 = (float)UFG::GameStatAction::MissionScoring::ms_MaxTriadScore;
    result = (unsigned int)(signed int)v4;
  }
  return result;
}

// File Line: 309
// RVA: 0x4A21D0
float __fastcall UFG::GameStatAction::MissionScoring::GetCopScorePercentage()
{
  signed int v0; // edx
  UFG::GameStatTracker *v2; // rbx
  int v3; // eax

  v0 = UFG::GameStatAction::MissionScoring::ms_CopStartingScore;
  if ( !UFG::GameStatAction::MissionScoring::ms_CopStartingScore )
    return 0.0;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v0 = UFG::GameStatAction::MissionScoring::ms_CopStartingScore;
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = 0;
  if ( v0 - v2->mpSnapshots[0]->mInts[155].mValue > 0 )
    v3 = v0 - v2->mpSnapshots[0]->mInts[155].mValue;
  return (float)v3 / (float)v0;
}

// File Line: 320
// RVA: 0x4A7190
float __fastcall UFG::GameStatAction::MissionScoring::GetTriadScorePercentage()
{
  float result; // xmm0_4

  if ( UFG::GameStatAction::MissionScoring::ms_MaxTriadScore )
    result = (float)(signed int)UFG::GameStatAction::MissionScoring::GetTriadScore(1)
           / (float)UFG::GameStatAction::MissionScoring::ms_MaxTriadScore;
  else
    result = 0.0;
  return result;
}

// File Line: 331
// RVA: 0x4A2140
__int64 __fastcall UFG::GameStatAction::MissionScoring::GetCopScoreBuffed()
{
  UFG::GameStatTracker *v0; // rbx
  int v1; // ecx
  signed int v2; // ebx

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
  v1 = UFG::GameStatAction::MissionScoring::ms_CopStartingScore - v0->mpSnapshots[0]->mInts[155].mValue;
  v2 = 0;
  if ( v1 > 0 )
    v2 = v1;
  return (unsigned int)(signed int)(float)((float)(UFG::PlayerBuffTracker::GetCopXPBonusPercent() + 1.0) * (float)v2);
}

// File Line: 337
// RVA: 0x4A70E0
__int64 __fastcall UFG::GameStatAction::MissionScoring::GetTriadScoreBuffed()
{
  UFG::GameStatTracker *v0; // rbx
  float v1; // xmm0_4

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
  v1 = (float)(v0->mpSnapshots[0]->mInts[156].mValue + UFG::GameStatAction::MissionScoring::ms_TriadBaseScore);
  if ( v1 >= (float)UFG::GameStatAction::MissionScoring::ms_MaxTriadScore )
    v1 = (float)UFG::GameStatAction::MissionScoring::ms_MaxTriadScore;
  return (unsigned int)(signed int)(float)((float)(UFG::PlayerBuffTracker::GetTriadXPBonusPercent() + 1.0)
                                         * (float)(signed int)v1);
}

// File Line: 343
// RVA: 0x4A6EA0
__int64 __fastcall UFG::GameStatAction::MissionScoring::GetTotalScoreUncapped()
{
  unsigned int v0; // ecx
  UFG::GameStatTracker *v1; // rbx
  UFG::GameStatTracker *v2; // r8
  int v3; // edi
  float v4; // xmm6_4
  float v5; // xmm8_4
  UFG::GameStatTracker *v6; // rax
  float v7; // xmm1_4
  float v8; // xmm2_4

  v0 = _S12_6;
  v1 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v0 = _S12_6;
  }
  v2 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = 0;
  if ( UFG::GameStatAction::MissionScoring::ms_CopStartingScore - v2->mpSnapshots[0]->mInts[155].mValue > 0 )
    v3 = UFG::GameStatAction::MissionScoring::ms_CopStartingScore - v2->mpSnapshots[0]->mInts[155].mValue;
  if ( !(v0 & 1) )
  {
    _S12_6 = v0 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v2 = UFG::GameStatTracker::mspInstance;
  }
  if ( v2 )
    v1 = v2;
  UFG::GameStatTracker::mspInstance = v1;
  v4 = (float)(v3 + v1->mpSnapshots[0]->mInts[156].mValue + UFG::GameStatAction::MissionScoring::ms_TriadBaseScore);
  v5 = (float)(UFG::GameStatAction::MissionScoring::ms_TimeAttackZeroTime
             - UFG::GameStatAction::MissionScoring::ms_TimeAttackTargetTime)
     * 60.0;
  if ( v5 > 0.0 )
  {
    v6 = UFG::GameStatTracker::Instance();
    v7 = (float)((float)(UFG::GameStatAction::MissionScoring::ms_TimeAttackZeroTime * 60.0)
               - UFG::SimpleTimer::GetElapsedSeconds(&v6->mpSnapshots[0]->mTimes[26].mTimer))
       / v5;
    if ( v7 <= 0.0 )
    {
      v7 = 0.0;
    }
    else
    {
      v8 = *(float *)&FLOAT_1_0;
      if ( v7 >= 1.0 )
        return (unsigned int)(signed int)(float)((float)(signed int)v4 * v8);
    }
    v8 = v7;
    return (unsigned int)(signed int)(float)((float)(signed int)v4 * v8);
  }
  return (unsigned int)(signed int)v4;
}

// File Line: 364
// RVA: 0x49A1B0
void __fastcall UFG::GameStatAction::MissionScoring::DeduceFaction(UFG::SimObject *pSimObject, bool *pIsCop, bool *pIsAmbient)
{
  UFG::SimObjectCVBase *v3; // rdi
  UFG::AiDriverComponent *v4; // rbx
  unsigned __int16 v5; // ax
  __int16 v6; // cx
  bool *v7; // r14
  bool *v8; // r15
  hkSimpleLocalFrame *v9; // rsi
  unsigned __int16 v10; // cx
  UFG::AiDriverComponent *v11; // rax
  hkLocalFrameGroup *v12; // rbx
  UFG::GameStatTracker *v13; // rax
  UFG::SimObject *v14; // rdx
  unsigned __int16 v15; // cx
  UFG::SimComponent *v16; // rax
  UFG::SimObjectGame *v17; // rcx
  bool v18; // zf

  v3 = (UFG::SimObjectCVBase *)pSimObject;
  LOBYTE(v4) = 0;
  v5 = pSimObject->m_Flags;
  v6 = v5 >> 14;
  v7 = pIsAmbient;
  v8 = pIsCop;
  if ( (v5 & 0x8000u) == 0 )
  {
    if ( v6 & 1 )
    {
      v13 = UFG::FactionInterface::Get();
      v14 = (UFG::SimObject *)&v3->vfptr;
      goto LABEL_24;
    }
  }
  else
  {
    if ( v6 & 1 )
      v9 = (hkSimpleLocalFrame *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                   (UFG::SimObjectGame *)&v3->vfptr,
                                   UFG::VehicleOccupantComponent::_TypeUID);
    else
      v9 = (hkSimpleLocalFrame *)v3->m_Components.p[30].m_pComponent;
    v10 = v3->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)&v3->vfptr,
                                          UFG::AiDriverComponent::_TypeUID);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v11 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)&v3->vfptr,
                                          UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        v11 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                          (UFG::SimObject *)&v3->vfptr,
                                          UFG::AiDriverComponent::_TypeUID);
      }
    }
    else
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    v4 = v11;
    if ( !v9 )
      goto LABEL_36;
    if ( Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v9) )
    {
      v12 = Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v9);
      v13 = UFG::FactionInterface::Get();
      v14 = (UFG::SimObject *)v12;
LABEL_24:
      LOBYTE(v4) = (unsigned int)UFG::FactionInterface::GetFaction(&v13->mFactionInterface, v14) == 17;
      goto LABEL_25;
    }
    if ( UFG::VehicleOccupantComponent::IsParked((UFG::VehicleOccupantComponent *)v9) )
    {
      LOBYTE(v4) = 1;
    }
    else
    {
LABEL_36:
      if ( v4 )
        LOBYTE(v4) = ((__int64 (__fastcall *)(UFG::AiDriverComponent *))v4->vfptr[16].__vecDelDtor)(v4);
    }
  }
LABEL_25:
  v15 = v3->m_Flags;
  if ( (v15 >> 14) & 1 || (v15 & 0x8000u) != 0 )
  {
    v16 = v3->m_Components.p[17].m_pComponent;
  }
  else
  {
    if ( (v15 >> 13) & 1 )
    {
      v17 = (UFG::SimObjectGame *)&v3->vfptr;
    }
    else
    {
      v18 = ((v15 >> 12) & 1) == 0;
      v17 = (UFG::SimObjectGame *)&v3->vfptr;
      if ( v18 )
      {
        v16 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CopUnitComponent::_TypeUID);
        goto LABEL_33;
      }
    }
    v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::CopUnitComponent::_TypeUID);
  }
LABEL_33:
  *v8 = v16 != 0i64;
  *v7 = (char)v4;
}

