// File Line: 11
// RVA: 0x48A890
void __fastcall UFG::CaseInfo::CaseInfo(UFG::CaseInfo *this)
{
  this->mPropertySetName.mUID = -1;
  this->mDependents.size = 0;
  this->mStatus = InPlace;
  UFG::qSymbol::set_null(&this->mPropertySetName);
  this->mStatus = InPlace;
  this->mDependents.size = 0;
}

// File Line: 16
// RVA: 0x4902B0
void __fastcall UFG::CaseInfo::~CaseInfo(UFG::CaseInfo *this)
{
  UFG::qSymbol::set_null(&this->mPropertySetName);
  this->mStatus = InPlace;
  this->mDependents.size = 0;
  this->mDependents.size = 0;
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
  char v2; // r8
  char v3; // r10
  __int64 size; // rcx
  UFG::GameStatTracker *v5; // rsi
  __int64 v6; // rbx
  UFG::GameSlice **p; // rdx
  int mState; // eax
  unsigned int v9; // edx
  UFG::GameStatTracker *v10; // rcx
  UFG::PersistentData::MapInt *v11; // r8
  UFG::PersistentData::KeyValue *v12; // rax
  UFG::GameStatTracker *v13; // rcx
  UFG::PersistentData::MapInt *v14; // rcx
  UFG::PersistentData::KeyValue *v15; // rax
  UFG::GameStatTracker *v16; // rcx

  v2 = 1;
  v3 = 1;
  size = this->mDependents.size;
  v5 = &sGameStatTracker;
  v6 = 0i64;
  if ( !size )
    goto LABEL_39;
  p = this->mDependents.p;
  do
  {
    mState = (*p)->mState;
    if ( mState != 8 )
      v2 = 0;
    if ( mState >= 1 || (*p)->mCompletionCount > 0 )
      v3 = 0;
    ++p;
    --size;
  }
  while ( size );
  if ( v3 )
  {
LABEL_39:
    this->mStatus = InPlace;
    v9 = _S12_6;
  }
  else
  {
    v9 = _S12_6;
    if ( v2 )
    {
      if ( (_S12_6 & 1) == 0 )
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
      while ( v12->mKey.mUID != this->mPropertySetName.mUID )
      {
        v6 = (unsigned int)(v6 + 1);
        ++v12;
        if ( (unsigned int)v6 >= v11->mValues.size )
          goto LABEL_23;
      }
      if ( (_DWORD)v6 != -1 && v11->mValues.p[v6].mIntValue == 4 )
        this->mStatus = Closed;
      else
LABEL_23:
        this->mStatus = DockedBottom;
    }
    else
    {
      if ( (_S12_6 & 1) == 0 )
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
      while ( v15->mKey.mUID != this->mPropertySetName.mUID )
      {
        v6 = (unsigned int)(v6 + 1);
        ++v15;
        if ( (unsigned int)v6 >= v14->mValues.size )
          goto LABEL_36;
      }
      if ( (_DWORD)v6 != -1 && v14->mValues.p[v6].mIntValue == 2 )
      {
        this->mStatus = DockedTop;
      }
      else
      {
LABEL_36:
        if ( (unsigned int)(this->mDependents.p[0]->mState - 1) <= 1 )
          this->mStatus = Floating;
        else
          this->mStatus = DockedTop;
      }
    }
  }
  if ( (v9 & 1) == 0 )
  {
    _S12_6 = v9 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v16 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v16 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v16;
  if ( (*((_BYTE *)v16 + 6216) & 1) == 0 )
  {
    UFG::PersistentData::MapInt::SetStatus(v16->mpSnapshots[0]->mpMapInts[22], &this->mPropertySetName, this->mStatus);
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( (_S12_6 & 1) == 0 )
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
}ameStatTracker::mspInstance )
        v5 = UFG::Ga

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
  __int64 size; // rbx
  __int64 v4; // r11
  __int64 v5; // r10
  UFG::GameSlice **i; // r9
  __int64 v7; // rcx
  UFG::GameSlice **v8; // rax

  if ( pGameSlice->mType != 10 )
    return 0i64;
  while ( pGameSlice->mpParent || pGameSlice->mType <= TYPE_CULL )
    pGameSlice = pGameSlice->mpParent;
  size = this->mCases.size;
  v4 = 0i64;
  v5 = 0i64;
  if ( !this->mCases.size )
    return 0i64;
  for ( i = this->mCases.p[0].mDependents.p; ; i += 10 )
  {
    v7 = 0i64;
    if ( *((_DWORD *)i - 2) )
      break;
LABEL_11:
    ++v5;
    v4 = (unsigned int)(v4 + 1);
    if ( v5 >= size )
      return 0i64;
  }
  v8 = i;
  while ( pGameSlice != *v8 )
  {
    ++v7;
    ++v8;
    if ( v7 >= *((unsigned int *)i - 2) )
      goto LABEL_11;
  }
  return &this->mCases.p[v4];
}

