// File Line: 11
// RVA: 0x48A890
void __fastcall UFG::CaseInfo::CaseInfo(UFG::CaseInfo *this)
{
  UFG::CaseInfo *v1; // rbx

  v1 = this;
  this->mPropertySetName.mUID = -1;
  this->mDependents.size = 0;
  this->mStatus = 0;
  UFG::qSymbol::set_null(&this->mPropertySetName);
  v1->mStatus = 0;
  v1->mDependents.size = 0;
}

// File Line: 16
// RVA: 0x4902B0
void __fastcall UFG::CaseInfo::~CaseInfo(UFG::CaseInfo *this)
{
  UFG::CaseInfo *v1; // rbx

  v1 = this;
  UFG::qSymbol::set_null(&this->mPropertySetName);
  v1->mStatus = 0;
  v1->mDependents.size = 0;
  v1->mDependents.size = 0;
}

// File Line: 28
// RVA: 0x4ACAE0
bool __fastcall UFG::CaseInfo::IsOpened(UFG::CaseInfo *this)
{
  return (unsigned int)(this->mStatus - 2) <= 1;
}

// File Line: 43
// RVA: 0x4C8600
void __fastcall UFG::CaseInfo::UpdateStatus(UFG::CaseInfo *this)
{
  UFG::CaseInfo *v1; // rdi
  char v2; // r8
  char v3; // r10
  __int64 v4; // rcx
  UFG::GameStatTracker *v5; // rsi
  __int64 v6; // rbx
  signed __int64 v7; // rdx
  signed int v8; // eax
  unsigned int v9; // edx
  UFG::GameStatTracker *v10; // rcx
  UFG::PersistentData::MapInt *v11; // r8
  UFG::PersistentData::KeyValue *v12; // rax
  UFG::GameStatTracker *v13; // rcx
  UFG::PersistentData::MapInt *v14; // rcx
  UFG::PersistentData::KeyValue *v15; // rax
  UFG::GameStatTracker *v16; // rcx

  v1 = this;
  v2 = 1;
  v3 = 1;
  v4 = this->mDependents.size;
  v5 = &sGameStatTracker;
  v6 = 0i64;
  if ( v4 <= 0 )
    goto LABEL_53;
  v7 = (signed __int64)v1->mDependents.p;
  do
  {
    v8 = *(_DWORD *)(*(_QWORD *)v7 + 264i64);
    if ( v8 != 8 )
      v2 = 0;
    if ( v8 >= 1 || *(_WORD *)(*(_QWORD *)v7 + 364i64) > 0 )
      v3 = 0;
    v7 += 8i64;
    --v4;
  }
  while ( v4 );
  if ( v3 )
  {
LABEL_53:
    v1->mStatus = 0;
    v9 = _S12_6;
  }
  else
  {
    v9 = _S12_6;
    if ( v2 )
    {
      if ( !(_S12_6 & 1) )
      {
        _S12_6 |= 1u;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        v9 = _S12_6;
      }
      v10 = &sGameStatTracker;
      if ( UFG::GameStatTracker::mspInstance )
        v10 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v10;
      v11 = v10->mpSnapshots[0]->mpMapInts[22];
      if ( !v11->mValues.size )
        goto LABEL_23;
      v12 = v11->mValues.p;
      while ( v12->mKey.mUID != v1->mPropertySetName.mUID )
      {
        v6 = (unsigned int)(v6 + 1);
        ++v12;
        if ( (unsigned int)v6 >= v11->mValues.size )
          goto LABEL_23;
      }
      if ( (_DWORD)v6 != -1 && v11->mValues.p[v6].mIntValue == 4 )
        v1->mStatus = 4;
      else
LABEL_23:
        v1->mStatus = 3;
    }
    else
    {
      if ( !(_S12_6 & 1) )
      {
        _S12_6 |= 1u;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        v9 = _S12_6;
      }
      v13 = &sGameStatTracker;
      if ( UFG::GameStatTracker::mspInstance )
        v13 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v13;
      v14 = v13->mpSnapshots[0]->mpMapInts[22];
      if ( !v14->mValues.size )
        goto LABEL_36;
      v15 = v14->mValues.p;
      while ( v15->mKey.mUID != v1->mPropertySetName.mUID )
      {
        v6 = (unsigned int)(v6 + 1);
        ++v15;
        if ( (unsigned int)v6 >= v14->mValues.size )
          goto LABEL_36;
      }
      if ( (_DWORD)v6 != -1 && v14->mValues.p[v6].mIntValue == 2 )
      {
        v1->mStatus = 2;
      }
      else
      {
LABEL_36:
        if ( (unsigned int)(v1->mDependents.p[0]->mState - 1) <= 1 )
          v1->mStatus = 1;
        else
          v1->mStatus = 2;
      }
    }
  }
  if ( !(v9 & 1) )
  {
    _S12_6 = v9 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v16 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v16 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v16;
  if ( !(*((_BYTE *)v16 + 6216) & 1) )
  {
    UFG::PersistentData::MapInt::SetStatus(v16->mpSnapshots[0]->mpMapInts[22], &v1->mPropertySetName, v1->mStatus);
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( !(_S12_6 & 1) )
      {
        _S12_6 |= 1u;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      }
      if ( UFG::GameStatTracker::mspInstance )
        v5 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v5;
    }
  }
}:GameStatTracker::mspInstance )
        v5 = UFG::GameS

// File Line: 128
// RVA: 0x4902E0
void __fastcall UFG::CaseTracker::~CaseTracker(UFG::CaseTracker *this)
{
  this->mCases.size = 0;
  this->mCases.size = 0;
  `eh vector destructor iterator(this->mCases.p, 0x50ui64, 20, (void (__fastcall *)(void *))UFG::CaseInfo::~CaseInfo);
}

// File Line: 220
// RVA: 0x4A1E40
UFG::CaseInfo *__fastcall UFG::CaseTracker::GetCase(UFG::CaseTracker *this, UFG::GameSlice *pGameSlice)
{
  UFG::CaseTracker *v2; // rdi
  __int64 v3; // rbx
  __int64 v4; // r11
  __int64 v5; // r10
  UFG::GameSlice **v6; // r9
  __int64 v7; // r8
  __int64 v8; // rcx
  UFG::GameSlice **v9; // rax

  v2 = this;
  if ( pGameSlice->mType != 10 )
    return 0i64;
  while ( pGameSlice->mpParent || pGameSlice->mType <= 0 )
    pGameSlice = pGameSlice->mpParent;
  v3 = this->mCases.size;
  v4 = 0i64;
  v5 = 0i64;
  if ( v3 <= 0 )
    return 0i64;
  v6 = this->mCases.p[0].mDependents.p;
  while ( 1 )
  {
    v7 = *((unsigned int *)v6 - 2);
    v8 = 0i64;
    if ( v7 > 0 )
      break;
LABEL_11:
    ++v5;
    v4 = (unsigned int)(v4 + 1);
    v6 += 10;
    if ( v5 >= v3 )
      return 0i64;
  }
  v9 = v6;
  while ( pGameSlice != *v9 )
  {
    ++v8;
    ++v9;
    if ( v8 >= v7 )
      goto LABEL_11;
  }
  return &v2->mCases.p[v4];
}

