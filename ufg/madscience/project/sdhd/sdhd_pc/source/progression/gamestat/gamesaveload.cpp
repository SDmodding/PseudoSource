// File Line: 168
// RVA: 0x4AB630
UFG::GameSaveLoad *__fastcall UFG::GameSaveLoad::Instance()
{
  if ( (_S13_4 & 1) == 0 )
  {
    _S13_4 |= 1u;
    UFG::GameSaveLoad::GameSaveLoad(&sGameSaveLoad);
    atexit(UFG::GameSaveLoad::Instance_::_2_::_dynamic_atexit_destructor_for__sGameSaveLoad__);
  }
  return &sGameSaveLoad;
}

// File Line: 183
// RVA: 0x48A940
void __fastcall UFG::GameSaveLoad::GameSaveLoad(UFG::GameSaveLoad *this)
{
  UFG::qString::qString(&this->mFlowSettings.m_Postfix);
  UFG::qString::qString(&this->mFlowSettings.m_SaveFileTitle);
  this->mFileContainer = 0i64;
  UFG::qString::qString(&this->mActiveFolderDisplayNamePS);
  this->m_iCurrentPhotoNum = 0;
  this->m_pCurrentPhoto = 0i64;
  this->m_iCurrentPhotoSize = 0;
  this->m_FirstLoad = 1;
  UFG::gGameSaveLoad = this;
  UFG::qString::Set(&this->mFlowSettings.m_Postfix, &customCaption);
  this->mFlowSettings.m_iNumSlots = 4;
  *(_QWORD *)&this->mStatus = 0i64;
  this->mActiveGameSlot = GAMESLOT_INVALID;
  memset(this->m_GameSlotHeaderInfo, 0, sizeof(this->m_GameSlotHeaderInfo));
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, 0xA1FC293D, 0xFFFFFFFF);
  UFG::qMemSet(this->m_bPhotoExists, 0, 1u);
}

// File Line: 220
// RVA: 0x4ACCF0
bool __fastcall UFG::GameSaveLoad::IsSaveAvaliable(UFG::GameSaveLoad *this)
{
  return this->mStatus == GSLS_NONE && (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 2) != 0;
}

// File Line: 253
// RVA: 0x4ACAC0
bool __fastcall UFG::GameSaveLoad::IsLoadAvaliable(UFG::GameSaveLoad *this)
{
  if ( this->mStatus )
    return 0;
  else
    return UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1;
}

// File Line: 286
// RVA: 0x4AEE30
char __fastcall UFG::GameSaveLoad::LoadSaveDataFileList(UFG::GameSaveLoad *this)
{
  if ( this->mStatus || (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) == 0 )
    return 0;
  this->mOperation = GSLS_OP_FILE_LIST;
  this->mStatus = GSLS_NONE;
  UFG::HDDmanager::HDDFileList(UFG::HDDmanager::mInstance, UFG::GameSaveLoad::SaveLoadDoneCallBack);
  return 1;
}

// File Line: 305
// RVA: 0x4B8260
char __fastcall UFG::GameSaveLoad::SaveAutoGameSlot(UFG::GameSaveLoad *this)
{
  if ( this->mStatus || (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 2) == 0 )
    return 0;
  UFG::GameSaveLoad::SaveDataStart(this, GAMESLOT_AUTOSAVE, DATATYPE_GAME);
  return 1;
}

// File Line: 320
// RVA: 0x4B8C20
char __fastcall UFG::GameSaveLoad::SaveGameSlot(UFG::GameSaveLoad *this, __int32 GameSlotNum)
{
  if ( this->mStatus || (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 2) == 0 )
    return 0;
  UFG::GameSaveLoad::SaveDataStart(this, GameSlotNum, DATATYPE_GAME);
  return 1;
}

// File Line: 333
// RVA: 0x4AE5E0
char __fastcall UFG::GameSaveLoad::LoadGameSlot(UFG::GameSaveLoad *this, UFG::GameSaveLoad::eGameSlotNum GameSlotNum)
{
  if ( this->mStatus || (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) == 0 || GameSlotNum == GAMESLOT_INVALID )
    return 0;
  UFG::GameSaveLoad::LoadDataStart(this, GameSlotNum, DATATYPE_GAME);
  return 1;
}

// File Line: 344
// RVA: 0x4A2050
__int64 __fastcall UFG::GameSaveLoad::GetContinueGameSlot(UFG::GameSaveLoad *this)
{
  unsigned int v1; // edx
  unsigned int v2; // r9d
  unsigned __int64 m_iTimeDateStamp; // rax
  unsigned int m_iNumSlots; // r10d
  unsigned __int64 *p_m_iTimeDateStamp; // rcx

  v1 = 0;
  v2 = -1;
  m_iTimeDateStamp = 0i64;
  if ( this->m_GameSlotHeaderInfo[4].m_State == SAVE_GAME_HEADER_STATE_VALID
    && this->m_GameSlotHeaderInfo[4].m_iTimeDateStamp )
  {
    v2 = 4;
    m_iTimeDateStamp = this->m_GameSlotHeaderInfo[4].m_iTimeDateStamp;
  }
  m_iNumSlots = this->mFlowSettings.m_iNumSlots;
  if ( m_iNumSlots )
  {
    p_m_iTimeDateStamp = &this->m_GameSlotHeaderInfo[0].m_iTimeDateStamp;
    do
    {
      if ( *((_DWORD *)p_m_iTimeDateStamp - 2) == 5 && *p_m_iTimeDateStamp > m_iTimeDateStamp )
      {
        v2 = v1;
        m_iTimeDateStamp = *p_m_iTimeDateStamp;
      }
      ++v1;
      p_m_iTimeDateStamp += 10;
    }
    while ( v1 < m_iNumSlots );
  }
  return v2;
}

// File Line: 375
// RVA: 0x4AE5A0
char __fastcall UFG::GameSaveLoad::LoadGameOptions(UFG::GameSaveLoad *this)
{
  if ( this->mStatus || (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) == 0 )
    return 0;
  UFG::GameSaveLoad::LoadDataStart(this, NUM_GAMESAVES, DATATYPE_OPTIONS);
  return 1;
}

// File Line: 388
// RVA: 0x4B8BE0
char __fastcall UFG::GameSaveLoad::SaveGameOptions(UFG::GameSaveLoad *this)
{
  if ( this->mStatus || (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 2) == 0 )
    return 0;
  UFG::GameSaveLoad::SaveDataStart(this, 5, DATATYPE_OPTIONS);
  return 1;
}

// File Line: 436
// RVA: 0x4AED30
char __fastcall UFG::GameSaveLoad::LoadPhoto(UFG::GameSaveLoad *this, unsigned int iPhotoNum)
{
  if ( this->mStatus || (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) == 0 || iPhotoNum )
    return 0;
  UFG::GameSaveLoad::LoadDataStart(this, GAMESLOT_PHOTO_FIRST, DATATYPE_PHOTO);
  return 1;
}

// File Line: 482
// RVA: 0x4A5930
_BOOL8 __fastcall UFG::GameSaveLoad::GetNumPhotosTaken(UFG::GameSaveLoad *this)
{
  return this->m_bPhotoExists[0];
}

// File Line: 499
// RVA: 0x49DAA0
bool __fastcall UFG::GameSaveLoad::DoesPhotoExists(UFG::GameSaveLoad *this, unsigned int iPhotoNum)
{
  return !iPhotoNum && this->m_bPhotoExists[0];
}

// File Line: 513
// RVA: 0x49AB30
char __fastcall UFG::GameSaveLoad::DeletePhoto(UFG::GameSaveLoad *this, unsigned int iPhotoNum)
{
  if ( this->mStatus
    || (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 2) == 0
    || iPhotoNum
    || !this->m_bPhotoExists[0] )
  {
    return 0;
  }
  this->m_iCurrentPhotoNum = 0;
  UFG::GameSaveLoad::DeleteDataStart(this, 6, 4);
  this->m_bPhotoExists[0] = 0;
  return 1;
}

// File Line: 545
// RVA: 0x49AA50
char __fastcall UFG::GameSaveLoad::DeleteGameData(UFG::GameSaveLoad *this, __int32 iGameSlotNum)
{
  if ( this->mStatus
    || (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 2) == 0
    || iGameSlotNum >= 5
    || this->m_GameSlotHeaderInfo[iGameSlotNum].m_State != SAVE_GAME_HEADER_STATE_VALID )
  {
    return 0;
  }
  UFG::GameSaveLoad::DeleteDataStart(this, iGameSlotNum, 2);
  return 1;
}

// File Line: 574
// RVA: 0x4BB700
void __fastcall UFG::GameSaveLoad::SetActiveFlow(UFG::GameSaveLoad *this, UFG::qArray<unsigned long,0> *flowId)
{
  UFG::qSymbol *v4; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v6; // rbx
  UFG::qArray<unsigned long,0> *v7; // rax
  char *v8; // rax
  const char *v9; // rsi
  const char *v10; // rdx
  UFG::qArray<unsigned long,0> *v11; // rax
  unsigned int *v12; // rax
  unsigned int v13; // eax
  UFG::qArray<unsigned long,0> *v14; // rax
  char *v15; // rax
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h] BYREF

  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v4 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, 0x3971E8ABu);
  PropertySet = UFG::PropertySetManager::FindPropertySet(v4);
  if ( PropertySet )
  {
    v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(PropertySet, flowId, DEPTH_RECURSE);
    if ( v6 )
    {
      v7 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::qSymbol(&result, 0xA7956F38);
      v8 = UFG::qPropertySet::Get<char const *>(v6, v7, DEPTH_RECURSE);
      v9 = &customCaption;
      v10 = &customCaption;
      if ( v8 )
        v10 = v8;
      UFG::qString::Set(&this->mFlowSettings.m_Postfix, v10);
      v11 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::qSymbol(&result, 0xAF4C7D0E);
      v12 = UFG::qPropertySet::Get<unsigned long>(v6, v11, DEPTH_RECURSE);
      if ( v12 )
        v13 = *v12;
      else
        v13 = 4;
      this->mFlowSettings.m_iNumSlots = v13;
      v14 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::qSymbol(&result, 0xF8A6816F);
      v15 = UFG::qPropertySet::Get<char const *>(v6, v14, DEPTH_RECURSE);
      if ( v15 )
        v9 = v15;
      UFG::qString::Set(&this->mFlowSettings.m_SaveFileTitle, v9);
      UFG::UIHKScreenHud::SetTexturePackForFlow(this->mFlowSettings.m_Postfix.mData);
    }
  }
}

// File Line: 604
// RVA: 0x4A67A0
__int64 __fastcall AimConstraintMultiLink::GetEffectorJoint(AimConstraintMultiLink *this)
{
  return (unsigned int)this->mEndJointID;
}

// File Line: 609
// RVA: 0x4A5A80
__int64 __fastcall UFG::GameSaveLoad::GetOperation(UFG::GameSaveLoad *this)
{
  return (unsigned int)this->mOperation;
}

// File Line: 641
// RVA: 0x4B2B30
void __fastcall UFG::GameSaveLoad::ProcessSaveDataFileList(UFG::GameSaveLoad *this)
{
  signed int v2; // ebx
  __int64 v3; // rdi
  UFG::GameSaveLoad::tsSaveGameHeaderInfo *m_GameSlotHeaderInfo; // r14
  UFG::qString *SlotFullFilename; // rax
  char IsFileNameInList; // al
  UFG::qString v7; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+60h] [rbp-38h] BYREF

  UFG::qString::qString(&v7);
  v2 = 0;
  v3 = 0i64;
  m_GameSlotHeaderInfo = this->m_GameSlotHeaderInfo;
  do
  {
    SlotFullFilename = UFG::GameSaveLoad::GetSlotFullFilename(this, &result, v2);
    UFG::qString::Set(&v7, SlotFullFilename->mData, SlotFullFilename->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
    IsFileNameInList = UFG::HDDmanager::IsFileNameInList(UFG::HDDmanager::mInstance, v7.mData);
    UFG::HDDmanager::mInstance->mSaveDataExists[v3] = IsFileNameInList;
    m_GameSlotHeaderInfo->m_State = (IsFileNameInList != 0) + 4;
    if ( (unsigned int)(v2 - 6) <= 1 )
      *((_BYTE *)&this->m_pCurrentPhoto + v3 + 6) = IsFileNameInList;
    ++v2;
    ++v3;
    ++m_GameSlotHeaderInfo;
  }
  while ( v2 < 8 );
  this->m_GameSlotHeaderInfo[6].m_State = SAVE_GAME_HEADER_STATE_UNKNOWN;
  *(_QWORD *)&this->mStatus = 0i64;
  UFG::qString::~qString(&v7);
}

// File Line: 694
// RVA: 0x4A6280
UFG::qString *__fastcall UFG::GameSaveLoad::GetSlotFullFilename(
        UFG::GameSaveLoad *this,
        UFG::qString *result,
        unsigned int slot_num)
{
  char *mData; // r8

  UFG::qString::qString(result);
  if ( slot_num == GAMESLOT_AUTOSAVE )
  {
    UFG::qString::Format(result, UFG::GameSlotFileNameAutoSave, this->mFlowSettings.m_Postfix.mData);
  }
  else if ( slot_num == NUM_GAMESAVES )
  {
    UFG::qString::Set(result, UFG::GameOptions);
  }
  else
  {
    mData = this->mFlowSettings.m_Postfix.mData;
    if ( slot_num > GAMESLOT_4 )
      UFG::qString::Format(result, UFG::GamePhotos, mData, slot_num - NUM_GAMESAVES, 1, -2i64);
    else
      UFG::qString::Format(result, UFG::GameSlotFileNames, mData, slot_num + GAMESLOT_2, 1, -2i64);
  }
  return result;
}

// File Line: 727
// RVA: 0x4A33C0
UFG::qString *__fastcall UFG::GameSaveLoad::GetGameSlotFullFilename(
        UFG::GameSaveLoad *this,
        UFG::qString *result,
        UFG::GameSaveLoad::eGameSlotNum GameSlotNum)
{
  char *mData; // r8

  UFG::qString::qString(result);
  mData = this->mFlowSettings.m_Postfix.mData;
  if ( GameSlotNum == GAMESLOT_AUTOSAVE )
    UFG::qString::Format(result, UFG::GameSlotFileNameAutoSave, mData);
  else
    UFG::qString::Format(result, UFG::GameSlotFileNames, mData, (unsigned int)(GameSlotNum + 1), 1, -2i64);
  return result;
}

// File Line: 745
// RVA: 0x4A3360
UFG::qString *__fastcall UFG::GameSaveLoad::GetGameOptionsFullFilename(UFG::GameSaveLoad *this, UFG::qString *result)
{
  UFG::qString::qString(result);
  UFG::qString::Set(result, UFG::GameOptions);
  return result;
}

// File Line: 755
// RVA: 0x4A5DC0
UFG::qString *__fastcall UFG::GameSaveLoad::GetPhotoFullFilename(
        UFG::GameSaveLoad *this,
        UFG::qString *result,
        unsigned int iPhotoNum)
{
  UFG::qString::qString(result);
  UFG::qString::Format(result, UFG::GamePhotos, iPhotoNum + 1);
  return result;
}

// File Line: 765
// RVA: 0x4B8C60
void __fastcall UFG::GameSaveLoad::SaveLoadDoneCallBack(UFG::errCode *err)
{
  UFG::GameSaveLoad *v2; // rax
  UFG::GameSaveLoad *v3; // rax
  bool v4; // zf
  UFG::GameSaveLoad *v5; // rax
  UFG::GameSaveLoad *v6; // rax
  UFG::GameSaveLoad *v7; // rax
  UFG::errCode v8[2]; // [rsp+30h] [rbp-18h] BYREF

  if ( err->eCode )
  {
    if ( (_S13_4 & 1) == 0 )
    {
      _S13_4 |= 1u;
      UFG::GameSaveLoad::GameSaveLoad(&sGameSaveLoad);
      atexit(UFG::GameSaveLoad::Instance_::_2_::_dynamic_atexit_destructor_for__sGameSaveLoad__);
    }
    dword_142409D88 = 3;
  }
  else
  {
    if ( (_S13_4 & 1) == 0 )
    {
      _S13_4 |= 1u;
      UFG::GameSaveLoad::GameSaveLoad(&sGameSaveLoad);
      atexit(UFG::GameSaveLoad::Instance_::_2_::_dynamic_atexit_destructor_for__sGameSaveLoad__);
    }
    dword_142409D88 = 2;
  }
  switch ( err->eType )
  {
    case eHDD_STATUS_SAVE:
      v8[0] = *err;
      v7 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::SaveDataEnd(v7, v8);
      break;
    case eHDD_STATUS_LOAD:
      v4 = UFG::GameSaveLoad::Instance()->mOperation == GSLS_OP_LOAD_HEADERS;
      v8[0] = *err;
      if ( v4 )
      {
        v5 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::LoadHeadersEnd(v5, v8);
      }
      else
      {
        v6 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::LoadDataEnd(v6, v8);
      }
      break;
    case eHDD_STATUS_DELETE:
      v8[0] = *err;
      v3 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::DeleteDataEnd(v3, v8);
      break;
    case eHDD_STATUS_FILELIST:
      v2 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::ProcessSaveDataFileList(v2);
      break;
  }
}

// File Line: 811
// RVA: 0x4BC460
void __fastcall UFG::GameSaveLoad::SetFileInfo(
        UFG::GameSaveLoad *this,
        UFG::HddSaveFile *pFile,
        UFG::GameSaveLoad::eSaveDataType eDataType,
        UFG::GameSaveLoad::eGameSlotNum eSlot)
{
  const char *v5; // rbx
  UFG::qString *v6; // rax
  UFG::qString *v7; // rbx
  UFG::qString *v8; // rcx
  float mValue; // xmm7_4
  UFG::GameStatTracker *v10; // rax
  float ElapsedSeconds; // xmm0_4
  UFG::qString *LocalizedTime; // rax
  const char *v13; // rbx
  UFG::qString *v14; // rax
  UFG::qString *v15; // rbx
  const char *SaveGameName; // rax
  const char *v17; // rax
  char *v18; // rdx
  char Dest[32]; // [rsp+38h] [rbp-C0h] BYREF
  UFG::qString v20; // [rsp+58h] [rbp-A0h] BYREF
  UFG::qString v21; // [rsp+80h] [rbp-78h] BYREF
  UFG::qString result; // [rsp+A8h] [rbp-50h] BYREF

  if ( eDataType == DATATYPE_OPTIONS )
  {
    v5 = UFG::UI::LocalizeText("COMMON_GAME_OPTIONS_FILE_TITLE_PS3");
    UFG::qString::Set(&pFile->mTitle, v5);
    UFG::qString::qString(&result, v5);
    v7 = v6;
    UFG::qString::Set(&pFile->mDescription, v6->mData, v6->mLength, 0i64, 0);
    v8 = v7;
  }
  else
  {
    UFG::GameStatAction::TemporaryData::Update();
    mValue = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[120].mValue;
    v10 = UFG::GameStatTracker::Instance();
    ElapsedSeconds = UFG::SimpleTimer::GetElapsedSeconds(&v10->mpSnapshots[0]->mTimes[2].mTimer);
    UFG::qString::qString(&v21);
    LocalizedTime = UFG::UIGfxTranslator::getLocalizedTime(
                      UFG::UIScreenManager::s_instance->m_translator,
                      &result,
                      ElapsedSeconds * 1000.0,
                      eTS_SECONDS);
    UFG::qString::Set(&v21, LocalizedTime->mData, LocalizedTime->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
    v13 = UFG::UI::LocalizeText("SAVELOAD_FILE_DESC_PS3");
    UFG::qString::qString(&v20);
    UFG::qString::Format(&v20, v13, v21.mData, (unsigned int)(int)mValue);
    UFG::qString::qString(&result, v20.mData);
    v15 = v14;
    UFG::qString::Set(&pFile->mDescription, v14->mData, v14->mLength, 0i64, 0);
    UFG::qString::~qString(v15);
    if ( (_S19_1 & 1) == 0 )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    SaveGameName = (const char *)UFG::ProgressionTracker::GetSaveGameName(&sProgressionTracker);
    if ( !SaveGameName )
      SaveGameName = UFG::UI::LocalizeText("$COMMON_UNKNOWN");
    strncpy(Dest, SaveGameName, 0x1Fui64);
    v17 = UFG::UI::LocalizeText(Dest);
    v18 = Dest;
    if ( v17 )
      v18 = (char *)v17;
    UFG::qString::Set(&pFile->mTitle, v18);
    UFG::qString::~qString(&v20);
    v8 = &v21;
  }
  UFG::qString::~qString(v8);
  UFG::qPrintf("Desc = %s\n", pFile->mDescription.mData);
  UFG::qPrintf("Title = %s\n", pFile->mTitle.mData);
}

// File Line: 894
// RVA: 0x4C7D20
void __fastcall UFG::GameSaveLoad::UpdateSaveGameTelemetry(UFG::GameSaveLoad *this, UFG::HddSaveFile *saveFile)
{
  int v2; // edi
  UFG::OSuiteDBLogger *v3; // rbx
  const char *SaveGameName; // rax
  char Dest[40]; // [rsp+28h] [rbp-B0h] BYREF
  char dest[128]; // [rsp+50h] [rbp-88h] BYREF

  v2 = saveFile->mUserData[1];
  v3 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v3, "Save") )
  {
    if ( (_S19_1 & 1) == 0 )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    SaveGameName = (const char *)UFG::ProgressionTracker::GetSaveGameName(&sProgressionTracker);
    if ( !SaveGameName )
      SaveGameName = UFG::UI::LocalizeText("$COMMON_UNKNOWN");
    strncpy(Dest, SaveGameName, 0x1Fui64);
    UFG::qSPrintf(dest, 128, "s_%s", "SaveName");
    OSuite::ZMetric::SetProperty(v3->m_pMetric, dest, Dest);
    UFG::qSPrintf(dest, 128, "i32_%s", "IsAutoSave");
    OSuite::ZMetric::SetProperty(v3->m_pMetric, dest, v2 == 4);
    UFG::OSuiteDBLogger::SubmitMetric(v3, 0);
  }
}

// File Line: 913
// RVA: 0x4C6820
void __fastcall UFG::GameSaveLoad::UpdateGameOptionsTelemetry(UFG::GameSaveLoad *this)
{
  unsigned int v1; // ecx
  UFG::GameStatTracker *v2; // rbx
  UFG::GameStatTracker *v3; // rdx
  UFG::GameStatTracker *v4; // r8
  UFG::GameStatTracker *v5; // rdx
  UFG::GameStatTracker *v6; // r8
  UFG::GameStatTracker *v7; // rdx
  UFG::GameStatTracker *v8; // r8
  UFG::GameStatTracker *v9; // rdx
  int v10; // r14d
  UFG::GameStatTracker *v11; // r8
  UFG::GameStatTracker *v12; // rdx
  UFG::GameStatTracker *v13; // r8
  bool v14; // r13
  UFG::GameStatTracker *v15; // rdx
  bool v16; // r12
  UFG::GameStatTracker *v17; // r8
  bool v18; // r15
  UFG::GameStatTracker *v19; // rdx
  bool v20; // si
  UFG::GameStatTracker *v21; // r8
  float v22; // xmm9_4
  UFG::GameStatTracker *v23; // rdx
  float v24; // xmm8_4
  UFG::GameStatTracker *v25; // r8
  float v26; // xmm7_4
  float v27; // xmm6_4
  UFG::OSuiteDBLogger *v28; // rdi
  int v29; // r14d
  UFG::Controller *v30; // rdx
  bool v31; // si
  int v32; // ebx
  UFG::qList<UFG::ActionRemapInfo,UFG::ActionRemapInfo,1,0> *p_mRemappableActions; // rdx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *i; // rcx
  bool mEnableFullscreen; // bl
  int mBackBufferHeight; // ebx
  int mBackBufferWidth; // ebx
  int mAAQuality; // ebx
  int mTextureDetailLevel; // ebx
  int mShadowRes; // ebx
  int GPUCount; // ebx
  int v42; // [rsp+20h] [rbp-E0h]
  int v43; // [rsp+24h] [rbp-DCh]
  int v44; // [rsp+28h] [rbp-D8h]
  int v45; // [rsp+2Ch] [rbp-D4h]
  int mValue; // [rsp+30h] [rbp-D0h]
  char dest[128]; // [rsp+40h] [rbp-C0h] BYREF
  __int64 v48; // [rsp+C0h] [rbp-40h]
  Render::RenderOutputParams outSettings; // [rsp+D0h] [rbp-30h] BYREF
  bool v50; // [rsp+1C8h] [rbp+C8h]
  bool v51; // [rsp+1D0h] [rbp+D0h]
  int i32Value; // [rsp+1D8h] [rbp+D8h]

  v48 = -2i64;
  v1 = _S12_6;
  v2 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
  }
  v3 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  i32Value = v3->mpSnapshots[0]->mInts[125].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v3 = UFG::GameStatTracker::mspInstance;
  }
  v4 = &sGameStatTracker;
  if ( v3 )
    v4 = v3;
  UFG::GameStatTracker::mspInstance = v4;
  mValue = v4->mpSnapshots[0]->mInts[127].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v4 = UFG::GameStatTracker::mspInstance;
  }
  v5 = &sGameStatTracker;
  if ( v4 )
    v5 = v4;
  UFG::GameStatTracker::mspInstance = v5;
  v42 = v5->mpSnapshots[0]->mInts[123].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v5 = UFG::GameStatTracker::mspInstance;
  }
  v6 = &sGameStatTracker;
  if ( v5 )
    v6 = v5;
  UFG::GameStatTracker::mspInstance = v6;
  v43 = v6->mpSnapshots[0]->mInts[124].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v6 = UFG::GameStatTracker::mspInstance;
  }
  v7 = &sGameStatTracker;
  if ( v6 )
    v7 = v6;
  UFG::GameStatTracker::mspInstance = v7;
  v44 = v7->mpSnapshots[0]->mInts[126].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v7 = UFG::GameStatTracker::mspInstance;
  }
  v8 = &sGameStatTracker;
  if ( v7 )
    v8 = v7;
  UFG::GameStatTracker::mspInstance = v8;
  v45 = v8->mpSnapshots[0]->mInts[128].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v8 = UFG::GameStatTracker::mspInstance;
  }
  v9 = &sGameStatTracker;
  if ( v8 )
    v9 = v8;
  UFG::GameStatTracker::mspInstance = v9;
  v10 = v9->mpSnapshots[0]->mInts[129].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v9 = UFG::GameStatTracker::mspInstance;
  }
  v11 = &sGameStatTracker;
  if ( v9 )
    v11 = v9;
  UFG::GameStatTracker::mspInstance = v11;
  v50 = v11->mpSnapshots[0]->mBools[34].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v11 = UFG::GameStatTracker::mspInstance;
  }
  v12 = &sGameStatTracker;
  if ( v11 )
    v12 = v11;
  UFG::GameStatTracker::mspInstance = v12;
  v51 = v12->mpSnapshots[0]->mBools[35].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v12 = UFG::GameStatTracker::mspInstance;
  }
  v13 = &sGameStatTracker;
  if ( v12 )
    v13 = v12;
  UFG::GameStatTracker::mspInstance = v13;
  v14 = v13->mpSnapshots[0]->mBools[36].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v13 = UFG::GameStatTracker::mspInstance;
  }
  v15 = &sGameStatTracker;
  if ( v13 )
    v15 = v13;
  UFG::GameStatTracker::mspInstance = v15;
  v16 = v15->mpSnapshots[0]->mBools[37].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v15 = UFG::GameStatTracker::mspInstance;
  }
  v17 = &sGameStatTracker;
  if ( v15 )
    v17 = v15;
  UFG::GameStatTracker::mspInstance = v17;
  v18 = v17->mpSnapshots[0]->mBools[38].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v17 = UFG::GameStatTracker::mspInstance;
  }
  v19 = &sGameStatTracker;
  if ( v17 )
    v19 = v17;
  UFG::GameStatTracker::mspInstance = v19;
  v20 = v19->mpSnapshots[0]->mBools[42].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v19 = UFG::GameStatTracker::mspInstance;
  }
  v21 = &sGameStatTracker;
  if ( v19 )
    v21 = v19;
  UFG::GameStatTracker::mspInstance = v21;
  v22 = v21->mpSnapshots[0]->mFloats[112].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v21 = UFG::GameStatTracker::mspInstance;
  }
  v23 = &sGameStatTracker;
  if ( v21 )
    v23 = v21;
  UFG::GameStatTracker::mspInstance = v23;
  v24 = v23->mpSnapshots[0]->mFloats[113].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v23 = UFG::GameStatTracker::mspInstance;
  }
  v25 = &sGameStatTracker;
  if ( v23 )
    v25 = v23;
  UFG::GameStatTracker::mspInstance = v25;
  v26 = v25->mpSnapshots[0]->mFloats[114].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v25 = UFG::GameStatTracker::mspInstance;
  }
  if ( v25 )
    v2 = v25;
  UFG::GameStatTracker::mspInstance = v2;
  v27 = v2->mpSnapshots[0]->mFloats[115].mValue;
  v28 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v28, "ConfigChange") )
  {
    UFG::qSPrintf(dest, 128, "i32_%s", "SFXVolume");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, i32Value);
    UFG::qSPrintf(dest, 128, "i32_%s", "MusicVolume");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, mValue);
    UFG::qSPrintf(dest, 128, "i32_%s", "DialogueVolume");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v44);
    UFG::qSPrintf(dest, 128, "i32_%s", "CarMusicVolume");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v45);
    UFG::qSPrintf(dest, 128, "i32_%s", "Brightness");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v42);
    UFG::qSPrintf(dest, 128, "i32_%s", "UIScale");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v43);
    UFG::qSPrintf(dest, 128, "i32_%s", "Subtitles");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v10);
    UFG::qSPrintf(dest, 128, "i32_%s", "Vibration");
    v29 = 0;
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v20);
    UFG::qSPrintf(dest, 128, "i32_%s", "HintsEnabled");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v50);
    UFG::qSPrintf(dest, 128, "i32_%s", "ContextualHelp");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v51);
    UFG::qSPrintf(dest, 128, "i32_%s", "EnableHUD");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v14);
    UFG::qSPrintf(dest, 128, "i32_%s", "YAxis");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v18);
    UFG::qSPrintf(dest, 128, "i32_%s", "XAxis");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v16);
    UFG::qSPrintf(dest, 128, "f_%s", "AimPitch");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v26);
    UFG::qSPrintf(dest, 128, "f_%s", "AimYaw");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v27);
    UFG::qSPrintf(dest, 128, "f_%s", "CameraPitch");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v22);
    UFG::qSPrintf(dest, 128, "f_%s", "CameraYaw");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v24);
    Render::RenderOutputParams::RenderOutputParams(&outSettings);
    Render::GetCurrentDisplaySettings(&outSettings);
    v30 = UFG::gInputSystem->mControllers[0];
    v31 = v30 && v30->m_IsKeyboardController;
    v32 = 0;
    if ( v31 )
    {
      p_mRemappableActions = &v30->mRemappableActions;
      for ( i = p_mRemappableActions->mNode.mNext;
            i != (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)p_mRemappableActions;
            i = i->mNext )
      {
        if ( LODWORD(i[3].mPrev) != HIDWORD(i[2].mNext) )
          ++v32;
      }
    }
    UFG::qSPrintf(dest, 128, "i32_%s", "Control");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v31);
    UFG::qSPrintf(dest, 128, "i32_%s", "DefaultKeyboard");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v32 == 0);
    UFG::qSPrintf(dest, 128, "i32_%s", "KeysRemapped");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v32);
    mEnableFullscreen = outSettings.mEnableFullscreen;
    UFG::qSPrintf(dest, 128, "i32_%s", "ScreenMode");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, mEnableFullscreen);
    mBackBufferHeight = outSettings.mDisplayMode.mBackBufferHeight;
    UFG::qSPrintf(dest, 128, "i32_%s", "ResolutionY");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, mBackBufferHeight);
    mBackBufferWidth = outSettings.mDisplayMode.mBackBufferWidth;
    UFG::qSPrintf(dest, 128, "i32_%s", "ResolutionX");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, mBackBufferWidth);
    LOBYTE(mBackBufferWidth) = outSettings.mEnableVSync;
    UFG::qSPrintf(dest, 128, "i32_%s", "VSync");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, (_BYTE)mBackBufferWidth == 1);
    mAAQuality = outSettings.mAAQuality;
    UFG::qSPrintf(dest, 128, "i32_%s", "QualityAA");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, mAAQuality);
    mTextureDetailLevel = outSettings.mTextureDetailLevel;
    UFG::qSPrintf(dest, 128, "i32_%s", "TextureDetailLevel");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, mTextureDetailLevel);
    mShadowRes = outSettings.mShadowRes;
    UFG::qSPrintf(dest, 128, "i32_%s", "HighQualityShadows");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, mShadowRes);
    GPUCount = Render::GetGPUCount();
    UFG::qSPrintf(dest, 128, "i32_%s", "SLI");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, GPUCount);
    LOBYTE(GPUCount) = outSettings.mEnable3D;
    UFG::qSPrintf(dest, 128, "i32_%s", "3D");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, (_BYTE)GPUCount == 1);
    LOBYTE(GPUCount) = outSettings.mEnableLowResBuffer;
    UFG::qSPrintf(dest, 128, "i32_%s", "EnableLowResBuffer");
    LOBYTE(v29) = (_BYTE)GPUCount == 1;
    OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v29);
    UFG::OSuiteDBLogger::SubmitMetric(v28, 0);
  }
}

// File Line: 1023
// RVA: 0x491D10
char __fastcall UFG::GameSaveLoad::AbortCurrentOperation(UFG::GameSaveLoad *this)
{
  UFG::GameSaveLoad::Operation mOperation; // edx
  __int32 v2; // edx

  mOperation = this->mOperation;
  if ( mOperation && (unsigned int)(this->mStatus - 2) <= 1 )
  {
    v2 = mOperation - 2;
    if ( !v2 )
    {
      this->mStatus = GSLS_FAIL;
      UFG::GameSaveLoad::LoadDataFinalize(this);
      return 1;
    }
    if ( v2 == 1 )
    {
      this->mStatus = GSLS_FAIL;
      UFG::GameSaveLoad::SaveDataFinalize(this);
      return 1;
    }
  }
  return 0;
}

// File Line: 1048
// RVA: 0x497B50
void __fastcall UFG::GameSaveLoad::ClearGameSlotHeaderInfo(UFG::GameSaveLoad *this)
{
  memset(this->m_GameSlotHeaderInfo, 0, sizeof(this->m_GameSlotHeaderInfo));
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, 0xA1FC293D, 0xFFFFFFFF);
}

// File Line: 1057
// RVA: 0x4AD5F0
char __fastcall UFG::GameSaveLoad::LoadAllHeaders(UFG::GameSaveLoad *this)
{
  UFG::GameSaveLoad::Operation mOperation; // eax
  char v3; // r8
  UFG::GameSaveLoad::tsSaveGameHeaderInfo *m_GameSlotHeaderInfo; // rcx
  __int64 v5; // r9
  bool v6; // cf
  bool v7; // zf
  unsigned int v8; // edx

  mOperation = this->mOperation;
  if ( mOperation == GSLS_OP_LOAD_HEADERS )
    return 1;
  if ( mOperation )
    return 0;
  v3 = 1;
  m_GameSlotHeaderInfo = this->m_GameSlotHeaderInfo;
  v5 = 8i64;
  do
  {
    v6 = m_GameSlotHeaderInfo->m_State == SAVE_GAME_HEADER_STATE_UNKNOWN;
    v7 = m_GameSlotHeaderInfo->m_State == SAVE_GAME_HEADER_STATE_LOADING;
    ++m_GameSlotHeaderInfo;
    v3 &= !v6 && !v7;
    --v5;
  }
  while ( v5 );
  if ( v3 )
  {
    UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, 0x7F3C2DD8u, 0xFFFFFFFF);
    v8 = -339696135;
    goto LABEL_12;
  }
  if ( this->mStatus || (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) == 0 )
  {
    UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, 0x7F3C2DD8u, 0xFFFFFFFF);
    UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, 0xEBC0A5F9, 0xFFFFFFFF);
    return 0;
  }
  this->m_GameSlotHeaderInfo[0].m_State = SAVE_GAME_HEADER_STATE_LOADING;
  this->m_GameSlotHeaderInfo[1].m_State = SAVE_GAME_HEADER_STATE_LOADING;
  this->m_GameSlotHeaderInfo[2].m_State = SAVE_GAME_HEADER_STATE_LOADING;
  this->m_GameSlotHeaderInfo[3].m_State = SAVE_GAME_HEADER_STATE_LOADING;
  this->m_GameSlotHeaderInfo[4].m_State = SAVE_GAME_HEADER_STATE_LOADING;
  this->m_GameSlotHeaderInfo[5].m_State = SAVE_GAME_HEADER_STATE_LOADING;
  this->m_GameSlotHeaderInfo[6].m_State = SAVE_GAME_HEADER_STATE_LOADING;
  this->m_GameSlotHeaderInfo[7].m_State = SAVE_GAME_HEADER_STATE_LOADING;
  this->mOperation = GSLS_OP_LOAD_HEADERS;
  this->mStatus = GSLS_WAITING;
  this->mActiveGameSlot = GAMESLOT_1;
  UFG::GameSaveLoad::LoadHeadersStart(this);
  v8 = 2134650328;
LABEL_12:
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, v8, 0xFFFFFFFF);
  return 1;
}

// File Line: 1135
// RVA: 0x4AEAC0
void __fastcall UFG::GameSaveLoad::LoadHeadersStart(UFG::GameSaveLoad *this)
{
  UFG::allocator::free_link *v2; // rax
  UFG::qString *SlotFullFilename; // rax
  UFG::HddSaveFile *v4; // rax
  UFG::qString v5; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+60h] [rbp-38h] BYREF

  this->mOperation = GSLS_OP_LOAD_HEADERS;
  this->mStatus = GSLS_WAITING;
  v2 = UFG::qMalloc(0x20ui64, "HddFileContainer", 0i64);
  if ( v2 )
    UFG::HddFileContainer::HddFileContainer((UFG::HddFileContainer *)v2);
  this->mFileContainer = (UFG::HddFileContainer *)v2;
  UFG::HDDmanager::mInstance->m_iSlotNum = this->mActiveGameSlot;
  UFG::qString::qString(&v5);
  SlotFullFilename = UFG::GameSaveLoad::GetSlotFullFilename(this, &result, this->mActiveGameSlot);
  UFG::qString::Set(&v5, SlotFullFilename->mData, SlotFullFilename->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  v4 = UFG::HddFileContainer::Add(this->mFileContainer, v5.mData, 0i64, 0x34u, HDD_FILE_TYPE_FIRST);
  v4->mUserData[0] = 1;
  v4->mUserData[1] = this->mActiveGameSlot;
  UFG::HDDmanager::HDDLoad(UFG::HDDmanager::mInstance, this->mFileContainer, UFG::GameSaveLoad::SaveLoadDoneCallBack);
  UFG::qString::~qString(&v5);
}

// File Line: 1169
// RVA: 0x4AE8C0
void __fastcall UFG::GameSaveLoad::LoadHeadersEnd(UFG::GameSaveLoad *this, UFG::errCode *err)
{
  UFG::eHDD_RETURN_CODE eCode; // r14d
  UFG::HddFileContainer *mFileContainer; // rax
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *mNext; // rbx
  char *mPrev; // rsi
  unsigned int file_data_size; // ebp
  __int64 mNext_high; // r15
  UFG::GameSaveLoad::SaveGameHeaderState v9; // r8d
  bool IsSaveGameValid; // al
  UFG::HddFileContainer *v11; // rsi
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v12; // rdx
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v13; // rax

  eCode = err->eCode;
  mFileContainer = this->mFileContainer;
  mNext = mFileContainer->FileList.mNode.mNext;
  if ( mNext != (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)&mFileContainer->FileList )
  {
    while ( 1 )
    {
      mPrev = (char *)mNext[7].mPrev;
      file_data_size = (unsigned int)mNext[6].mNext;
      mNext_high = SHIDWORD(mNext[7].mNext);
      if ( eCode == eHDD_RET_SUCCESS )
        break;
      switch ( eCode )
      {
        case eHDD_RET_NO_FILE:
          mPrev = 0i64;
          file_data_size = 0;
          v9 = SAVE_GAME_HEADER_STATE_EMPTY;
          break;
        case eHDD_RET_NOT_CREATED_BY_CURRENT_USER:
          goto LABEL_9;
        case eHDD_RET_INVALID_DEVICE:
          mPrev = 0i64;
          file_data_size = 0;
          v9 = SAVE_GAME_HEADER_STATE_INVALID_DEVICE;
          break;
        default:
          v9 = SAVE_GAME_HEADER_STATE_CORRUPT;
          break;
      }
LABEL_11:
      UFG::GameSaveLoad::UpdateGameSlotInfo(
        this,
        (UFG::GameSaveLoad::eGameSlotNum)mNext_high,
        v9,
        mPrev,
        file_data_size);
      UFG::HDDmanager::mInstance->mSaveDataExists[mNext_high] = this->m_GameSlotHeaderInfo[mNext_high].m_State > (unsigned int)SAVE_GAME_HEADER_STATE_LOADING;
      mNext = mNext->mNext;
      if ( mNext == &this->mFileContainer->FileList.mNode )
        goto LABEL_12;
    }
LABEL_9:
    IsSaveGameValid = UFG::GameSaveLoad::IsSaveGameValid(this, (__int64)mNext[7].mPrev, file_data_size);
    v9 = SAVE_GAME_HEADER_STATE_CORRUPT;
    if ( IsSaveGameValid )
      v9 = SAVE_GAME_HEADER_STATE_VALID;
    goto LABEL_11;
  }
LABEL_12:
  v11 = this->mFileContainer;
  if ( v11 )
  {
    UFG::qList<UFG::HddSaveFile,UFG::HddSaveFile,1,0>::DeleteNodes(&v11->FileList);
    v12 = v11->FileList.mNode.mPrev;
    v13 = v11->FileList.mNode.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->FileList.mNode.mPrev = &v11->FileList.mNode;
    v11->FileList.mNode.mNext = &v11->FileList.mNode;
    operator delete[](v11);
  }
  this->mFileContainer = 0i64;
  ++this->mActiveGameSlot;
  if ( eCode == eHDD_RET_INVALID_DEVICE )
  {
    memset(this->m_GameSlotHeaderInfo, 0, sizeof(this->m_GameSlotHeaderInfo));
    this->m_GameSlotHeaderInfo[0].m_State = SAVE_GAME_HEADER_STATE_INVALID_DEVICE;
    this->m_GameSlotHeaderInfo[1].m_State = SAVE_GAME_HEADER_STATE_INVALID_DEVICE;
    this->m_GameSlotHeaderInfo[2].m_State = SAVE_GAME_HEADER_STATE_INVALID_DEVICE;
    this->m_GameSlotHeaderInfo[3].m_State = SAVE_GAME_HEADER_STATE_INVALID_DEVICE;
    this->m_GameSlotHeaderInfo[4].m_State = SAVE_GAME_HEADER_STATE_INVALID_DEVICE;
    this->m_GameSlotHeaderInfo[5].m_State = SAVE_GAME_HEADER_STATE_INVALID_DEVICE;
    this->m_GameSlotHeaderInfo[6].m_State = SAVE_GAME_HEADER_STATE_INVALID_DEVICE;
    this->m_GameSlotHeaderInfo[7].m_State = SAVE_GAME_HEADER_STATE_INVALID_DEVICE;
  }
  else if ( this->mActiveGameSlot < NUM_GAMESLOTS )
  {
    UFG::GameSaveLoad::LoadHeadersStart(this);
    return;
  }
  *(_QWORD *)&this->mStatus = 0i64;
  this->mActiveGameSlot = GAMESLOT_INVALID;
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, 0xEBC0A5F9, 0xFFFFFFFF);
}

// File Line: 1380
// RVA: 0x4B8670
void __fastcall UFG::GameSaveLoad::SaveDataStart(
        UFG::GameSaveLoad *this,
        __int32 eSlot,
        UFG::GameSaveLoad::eSaveDataType eSaveType)
{
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  UFG::SimObjectCharacter *LocalPlayer; // rax
  float *m_pTransformNodeComponent; // rbx
  UFG::GameStatTracker *v11; // rax
  UFG::GameStatTracker *v12; // rax
  float ElapsedSeconds; // xmm6_4
  UFG::GameStatTracker *v14; // rax
  UFG::GameSnapshot *v15; // rax
  UFG::ProgressionTracker *v16; // rax
  char *v17; // rax
  UFG::HddFileContainer *v18; // rax
  char *v19; // rbx
  UFG::GameStatTracker *v20; // rax
  int v21; // edi
  char *v22; // rsi
  UFG::GameStatTracker *v23; // rax
  UFG::qString *GameOptionsFullFilename; // rax
  UFG::HddSaveFile *v25; // rax
  UFG::qString *v26; // rax
  UFG::qString *PhotoFullFilename; // rax
  UFG::HddSaveFile *v28; // rax
  UFG::qString *v29; // rax
  UFG::qString *GameSlotFullFilename; // rax
  char *v31; // rsi
  UFG::GameStatTracker *v32; // rax
  int v33; // edi
  char *v34; // r14
  UFG::GameStatTracker *v35; // rax
  unsigned int v36; // ebx
  UFG::HddSaveFile *v37; // rax
  UFG::qString *v38; // rax
  UFG::qString v39; // [rsp+8h] [rbp-61h] BYREF
  UFG::qString finalSize[3]; // [rsp+30h] [rbp-39h] BYREF
  char *ppBuffer; // [rsp+D0h] [rbp+67h] BYREF
  int iHeaderSaveSize; // [rsp+D8h] [rbp+6Fh] BYREF
  unsigned int bufferSize[6]; // [rsp+E0h] [rbp+77h] BYREF

  this->mOperation = GSLS_OP_SAVE;
  this->mStatus = GSLS_WAITING;
  if ( eSaveType == DATATYPE_GAME )
  {
    if ( (_S19_1 & 1) == 0 )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    UFG::ProgressionTracker::UpdateGameSlicesSnapshot(&sProgressionTracker);
    UFG::ProgressionTracker::BuildSavegameSnapshot(&sProgressionTracker);
    unk_14240B98C = 1;
    x = UFG::qVector3::msZero.x;
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    LocalPlayer = UFG::GetLocalPlayer();
    if ( LocalPlayer )
    {
      m_pTransformNodeComponent = (float *)LocalPlayer->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent);
        x = m_pTransformNodeComponent[44];
        y = m_pTransformNodeComponent[45];
        z = m_pTransformNodeComponent[46];
      }
    }
    v11 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v11 + 6216) & 1) == 0 )
    {
      v11->mpSnapshots[0]->mFloats[79].mValue = x;
      if ( (*((_BYTE *)v11 + 6216) & 1) == 0 )
        v11->mpSnapshots[0]->mFloats[80].mValue = y;
    }
    if ( (*((_BYTE *)v11 + 6216) & 1) == 0 )
      v11->mpSnapshots[0]->mFloats[81].mValue = z;
    v12 = UFG::GameStatTracker::Instance();
    ElapsedSeconds = UFG::SimpleTimer::GetElapsedSeconds(&v12->mSessionTimer);
    v14 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v14 + 6216) & 1) == 0 )
    {
      v15 = v14->mpSnapshots[0];
      if ( ElapsedSeconds > v15->mFloats[109].mValue )
        v15->mFloats[109].mValue = ElapsedSeconds;
    }
  }
  else
  {
    v16 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::BuildSavegameSnapshot(v16);
  }
  UFG::qString::qString(&v39);
  v17 = (char *)UFG::qMalloc(0x20ui64, "GameSaveLoad Container", 0i64);
  ppBuffer = v17;
  if ( v17 )
    UFG::HddFileContainer::HddFileContainer((UFG::HddFileContainer *)v17);
  else
    v18 = 0i64;
  this->mFileContainer = v18;
  UFG::HDDmanager::mInstance->m_iSlotNum = eSlot;
  if ( (unsigned int)(eSaveType - 1) <= 1 )
  {
    GameSlotFullFilename = UFG::GameSaveLoad::GetGameSlotFullFilename(
                             this,
                             finalSize,
                             (UFG::GameSaveLoad::eGameSlotNum)eSlot);
    UFG::qString::Set(&v39, GameSlotFullFilename->mData, GameSlotFullFilename->mLength, 0i64, 0);
    UFG::qString::~qString(finalSize);
    bufferSize[0] = 0;
    ppBuffer = 0i64;
    iHeaderSaveSize = 0;
    v31 = UFG::GameSaveLoad::SerializeHeaderData(this, 0xFFFFFFF8, 2u, &iHeaderSaveSize);
    v32 = UFG::GameStatTracker::Instance();
    v33 = iHeaderSaveSize;
    UFG::GameStatTracker::SerializeSnapshotByFilter(v32, 0xFFFFFFF8, 2u, iHeaderSaveSize, &ppBuffer, (int *)bufferSize);
    v34 = ppBuffer;
    UFG::qMemCopy(ppBuffer, v31, v33);
    v35 = UFG::GameStatTracker::Instance();
    v36 = bufferSize[0];
    UFG::GameStatTracker::Scramble(v35, *((_QWORD *)v34 + 1), v33, v34, bufferSize[0]);
    operator delete[](v31);
    v37 = UFG::HddFileContainer::Add(this->mFileContainer, v39.mData, v34, v36, HDD_FILE_TYPE_FIRST);
    v37->mUserData[0] = eSaveType;
    v37->mUserData[1] = eSlot;
    UFG::GameSaveLoad::SetFileInfo(this, v37, eSaveType, (UFG::GameSaveLoad::eGameSlotNum)eSlot);
    operator delete[](v34);
    if ( eSlot == 4 )
      v38 = UFG::GameSaveLoad::GetGameSlotFullFilename(this, finalSize, GAMESLOT_AUTOSAVE);
    else
      v38 = UFG::GameSaveLoad::GetGameSlotFullFilename(this, finalSize, (UFG::GameSaveLoad::eGameSlotNum)eSlot);
    UFG::qString::Set(&this->mActiveFolderDisplayNamePS, v38->mData, v38->mLength, 0i64, 0);
    goto LABEL_28;
  }
  if ( eSaveType == DATATYPE_OPTIONS )
  {
    bufferSize[0] = 0;
    ppBuffer = 0i64;
    iHeaderSaveSize = 0;
    v19 = UFG::GameSaveLoad::SerializeHeaderData(this, 4u, 2u, &iHeaderSaveSize);
    v20 = UFG::GameStatTracker::Instance();
    v21 = iHeaderSaveSize;
    UFG::GameStatTracker::SerializeSnapshotByFilter(v20, 4u, 2u, iHeaderSaveSize, &ppBuffer, (int *)bufferSize);
    v22 = ppBuffer;
    UFG::qMemCopy(ppBuffer, v19, v21);
    v23 = UFG::GameStatTracker::Instance();
    LODWORD(v19) = bufferSize[0];
    UFG::GameStatTracker::Scramble(v23, *((_QWORD *)v22 + 1), v21, v22, bufferSize[0]);
    GameOptionsFullFilename = UFG::GameSaveLoad::GetGameOptionsFullFilename(this, finalSize);
    UFG::qString::Set(&v39, GameOptionsFullFilename->mData, GameOptionsFullFilename->mLength, 0i64, 0);
    UFG::qString::~qString(finalSize);
    v25 = UFG::HddFileContainer::Add(this->mFileContainer, v39.mData, v22, (unsigned int)v19, HDD_FILE_TYPE_FIRST);
    v25->mUserData[0] = 3;
    v25->mUserData[1] = eSlot;
    UFG::GameSaveLoad::SetFileInfo(this, v25, DATATYPE_OPTIONS, GAMESLOT_INVALID);
    operator delete[](v22);
    v26 = UFG::GameSaveLoad::GetGameOptionsFullFilename(this, finalSize);
    UFG::qString::operator=(&this->mActiveFolderDisplayNamePS, v26);
LABEL_28:
    UFG::qString::~qString(finalSize);
    goto LABEL_29;
  }
  if ( eSaveType == DATATYPE_PHOTO )
  {
    PhotoFullFilename = UFG::GameSaveLoad::GetPhotoFullFilename(this, finalSize, this->m_iCurrentPhotoNum);
    UFG::qString::Set(&v39, PhotoFullFilename->mData, PhotoFullFilename->mLength, 0i64, 0);
    UFG::qString::~qString(finalSize);
    v28 = UFG::HddFileContainer::Add(
            this->mFileContainer,
            v39.mData,
            this->m_pCurrentPhoto,
            this->m_iCurrentPhotoSize,
            HDD_FILE_TYPE_FIRST);
    v28->mUserData[0] = 4;
    v28->mUserData[1] = eSlot;
    UFG::GameSaveLoad::SetFileInfo(this, v28, DATATYPE_PHOTO, GAMESLOT_INVALID);
    v29 = UFG::GameSaveLoad::GetPhotoFullFilename(this, finalSize, eSlot - 5);
    UFG::qString::operator=(&this->mActiveFolderDisplayNamePS, v29);
    goto LABEL_28;
  }
LABEL_29:
  this->mActiveGameSlot = eSlot;
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, 0xC3BE4B7B, 0xFFFFFFFF);
  UFG::GameSaveLoad::SaveDataRetry(this);
  UFG::qString::~qString(&v39);
}

// File Line: 1560
// RVA: 0x4B85E0
void __fastcall UFG::GameSaveLoad::SaveDataRetry(UFG::GameSaveLoad *this)
{
  UFG::qString *v2; // rax
  UFG::qString v3; // [rsp+38h] [rbp-30h] BYREF

  this->mStatus = GSLS_WAITING;
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_SAVELOAD_START_SAVING_4, 0xFFFFFFFF);
  UFG::qString::qString(&v3, &this->mActiveFolderDisplayNamePS);
  UFG::HDDmanager::HDDSave(
    UFG::HDDmanager::mInstance,
    this->mFileContainer,
    UFG::GameSaveLoad::SaveLoadDoneCallBack,
    v2,
    this->m_GameSlotHeaderInfo[this->mActiveGameSlot].m_State == SAVE_GAME_HEADER_STATE_CORRUPT);
}

// File Line: 1575
// RVA: 0x4B82A0
void __fastcall UFG::GameSaveLoad::SaveDataEnd(UFG::GameSaveLoad *this, UFG::errCode *err)
{
  UFG::eHDD_RETURN_CODE eCode; // r15d
  UFG::HddFileContainer *mFileContainer; // rax
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *mNext; // rdi
  int v6; // ebp
  signed int mNext_high; // esi
  UFG::qString *SlotFullFilename; // rax
  bool v9; // r14
  UFG::qString result; // [rsp+38h] [rbp-40h] BYREF

  eCode = err->eCode;
  if ( UFG::gFakeSaveFailure )
  {
    eCode = eHDD_RET_CORRUPT_FILE;
    UFG::gFakeInsufficientSpace = 0;
  }
  else if ( UFG::gFakeInsufficientSpace )
  {
    eCode = eHDD_RET_INSUFFICENT_SPACE;
  }
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_SAVELOAD_STOP_SAVING_4, 0xFFFFFFFF);
  mFileContainer = this->mFileContainer;
  mNext = mFileContainer->FileList.mNode.mNext;
  if ( mNext != (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)&mFileContainer->FileList )
  {
    do
    {
      UFG::qPrintf("File Name %s, File Size = %d \n", (const char *)mNext[3].mPrev, LODWORD(mNext[6].mNext));
      v6 = (int)mNext[7].mNext;
      mNext_high = HIDWORD(mNext[7].mNext);
      SlotFullFilename = UFG::GameSaveLoad::GetSlotFullFilename(this, &result, mNext_high);
      v9 = (unsigned int)UFG::qStringCompare((const char *)mNext[3].mPrev, SlotFullFilename->mData, -1) == 0;
      UFG::qString::~qString(&result);
      if ( eCode )
      {
        if ( eCode == eHDD_RET_INSUFFICENT_SPACE )
        {
          UFG::UIScreenManagerBase::queueMessage(
            UFG::UIScreenManager::s_instance,
            UI_HASH_NO_SPACE_FOR_SAVE_4,
            0xFFFFFFFF);
        }
        else if ( eCode == eHDD_RET_CORRUPT_FILE )
        {
          UFG::GameSaveLoad::UpdateGameSlotInfo(
            this,
            (UFG::GameSaveLoad::eGameSlotNum)mNext_high,
            SAVE_GAME_HEADER_STATE_CORRUPT,
            0i64,
            0);
          UFG::UIScreenManagerBase::queueMessage(
            UFG::UIScreenManager::s_instance,
            UI_HASH_CORRUPT_SAVE_SLOT_4,
            0xFFFFFFFF);
        }
        else
        {
          UFG::GameSaveLoad::UpdateGameSlotInfo(
            this,
            (UFG::GameSaveLoad::eGameSlotNum)mNext_high,
            SAVE_GAME_HEADER_STATE_INVALID_DEVICE,
            0i64,
            0);
          UFG::UIScreenManagerBase::queueMessage(
            UFG::UIScreenManager::s_instance,
            UI_HASH_SAVE_OPERATION_INVALID_DEVICE_4,
            0xFFFFFFFF);
        }
      }
      else if ( (unsigned int)(v6 - 1) <= 1 )
      {
        UFG::GameSaveLoad::UpdateSaveGameTelemetry(this, (UFG::HddSaveFile *)mNext);
        if ( v9 )
          UFG::GameSaveLoad::UpdateGameSlotInfo(
            this,
            (UFG::GameSaveLoad::eGameSlotNum)mNext_high,
            SAVE_GAME_HEADER_STATE_VALID,
            (char *)mNext[7].mPrev,
            (unsigned int)mNext[6].mNext);
      }
      else if ( v6 == 3 )
      {
        if ( v9 )
          UFG::GameSaveLoad::UpdateGameSlotInfo(
            this,
            (UFG::GameSaveLoad::eGameSlotNum)mNext_high,
            SAVE_GAME_HEADER_STATE_VALID,
            (char *)mNext[7].mPrev,
            0x34u);
      }
      else if ( v6 == 4 )
      {
        this->m_bPhotoExists[this->m_iCurrentPhotoNum] = 1;
        UFG::GameSaveLoad::UpdateGameSlotInfo(
          this,
          (UFG::GameSaveLoad::eGameSlotNum)mNext_high,
          SAVE_GAME_HEADER_STATE_VALID,
          0i64,
          0);
      }
      mNext = mNext->mNext;
    }
    while ( mNext != &this->mFileContainer->FileList.mNode );
  }
  if ( eCode == eHDD_RET_SUCCESS )
    UFG::GameSaveLoad::SaveDataFinalize(this);
}

// File Line: 1704
// RVA: 0x4B84B0
void __fastcall UFG::GameSaveLoad::SaveDataFinalize(UFG::GameSaveLoad *this)
{
  UFG::GameSaveLoad::Status mStatus; // eax
  bool v3; // bp
  bool v4; // r14
  UFG::HddFileContainer *mFileContainer; // rsi
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *mPrev; // rdx
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *mNext; // rax
  unsigned int v8; // edx

  mStatus = this->mStatus;
  v3 = mStatus == GSLS_SUCCESS && this->mActiveGameSlot != NUM_GAMESAVES;
  v4 = mStatus == GSLS_SUCCESS;
  UFG::HddFileContainer::EmptyContainer(this->mFileContainer);
  mFileContainer = this->mFileContainer;
  if ( mFileContainer )
  {
    UFG::qList<UFG::HddSaveFile,UFG::HddSaveFile,1,0>::DeleteNodes(&mFileContainer->FileList);
    mPrev = mFileContainer->FileList.mNode.mPrev;
    mNext = mFileContainer->FileList.mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    mFileContainer->FileList.mNode.mPrev = &mFileContainer->FileList.mNode;
    mFileContainer->FileList.mNode.mNext = &mFileContainer->FileList.mNode;
    operator delete[](mFileContainer);
  }
  this->mFileContainer = 0i64;
  UFG::qString::Set(&this->mActiveFolderDisplayNamePS, 0i64);
  this->mActiveGameSlot = GAMESLOT_INVALID;
  *(_QWORD *)&this->mStatus = 0i64;
  if ( v3 && (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 2) != 0 )
  {
    UFG::GameSaveLoad::SaveDataStart(this, NUM_GAMESAVES, DATATYPE_OPTIONS);
  }
  else
  {
    UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, 0xF601FBC2, 0xFFFFFFFF);
    v8 = 2006712458;
    if ( v4 )
      v8 = -663456200;
    UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, v8, 0xFFFFFFFF);
  }
}

// File Line: 1806
// RVA: 0x4ADC20
void __fastcall UFG::GameSaveLoad::LoadDataStart(
        UFG::GameSaveLoad *this,
        UFG::GameSaveLoad::eGameSlotNum eSlot,
        UFG::GameSaveLoad::eSaveDataType eSaveType)
{
  __int64 v4; // rsi
  UFG::allocator::free_link *v6; // rax
  UFG::HddFileContainer *v7; // rax
  UFG::qString *GameSlotFullFilename; // rax
  UFG::HddSaveFile *v9; // rax
  UFG::OSuiteDBLogger *v10; // rdi
  UFG::qString *GameOptionsFullFilename; // rax
  UFG::HddSaveFile *v12; // rax
  UFG::qString *PhotoFullFilename; // rax
  UFG::qString v14; // [rsp+30h] [rbp-E8h] BYREF
  UFG::qString result; // [rsp+58h] [rbp-C0h] BYREF
  __int64 v16; // [rsp+80h] [rbp-98h]
  char dest[128]; // [rsp+90h] [rbp-88h] BYREF

  v16 = -2i64;
  v4 = eSlot;
  UFG::qString::qString(&v14);
  UFG::HDDmanager::mInstance->m_iSlotNum = v4;
  v6 = UFG::qMalloc(0x20ui64, "User Pro Container", 0i64);
  if ( v6 )
    UFG::HddFileContainer::HddFileContainer((UFG::HddFileContainer *)v6);
  else
    v7 = 0i64;
  this->mFileContainer = v7;
  if ( eSaveType != DATATYPE_GAMESLOT_HEADER )
  {
    if ( eSaveType != DATATYPE_GAME )
    {
      if ( eSaveType == DATATYPE_OPTIONS )
      {
        GameOptionsFullFilename = UFG::GameSaveLoad::GetGameOptionsFullFilename(this, &result);
        UFG::qString::Set(&v14, GameOptionsFullFilename->mData, GameOptionsFullFilename->mLength, 0i64, 0);
        UFG::qString::~qString(&result);
        v12 = UFG::HddFileContainer::Add(this->mFileContainer, v14.mData, 0i64, 0x19000u, HDD_FILE_TYPE_FIRST);
        v12->mAdjustFileSize = 1;
        v12->mUserData[0] = 3;
      }
      else
      {
        if ( eSaveType != DATATYPE_PHOTO )
          goto LABEL_16;
        PhotoFullFilename = UFG::GameSaveLoad::GetPhotoFullFilename(
                              this,
                              &result,
                              UFG::HDDmanager::mInstance->m_iSlotNum - 6);
        UFG::qString::Set(&v14, PhotoFullFilename->mData, PhotoFullFilename->mLength, 0i64, 0);
        UFG::qString::~qString(&result);
        v12 = UFG::HddFileContainer::Add(this->mFileContainer, v14.mData, 0i64, 0x186A0u, HDD_FILE_TYPE_FIRST);
        v12->mAdjustFileSize = 1;
        v12->mUserData[0] = 4;
      }
      v12->mUserData[1] = v4;
      goto LABEL_16;
    }
    GameSlotFullFilename = UFG::GameSaveLoad::GetGameSlotFullFilename(
                             this,
                             &result,
                             (UFG::GameSaveLoad::eGameSlotNum)v4);
    UFG::qString::Set(&v14, GameSlotFullFilename->mData, GameSlotFullFilename->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
    v9 = UFG::HddFileContainer::Add(
           this->mFileContainer,
           v14.mData,
           0i64,
           this->m_GameSlotHeaderInfo[v4].m_iGameDataSize,
           HDD_FILE_TYPE_FIRST);
    v9->mUserData[0] = 2;
    v9->mUserData[1] = v4;
    v10 = UFG::OSuiteDBLogger::Instance();
    if ( UFG::OSuiteDBLogger::CreateMetric(v10, "SaveGameLoaded") )
    {
      UFG::qSPrintf(dest, 128, "s_%s", "SaveName");
      OSuite::ZMetric::SetProperty(v10->m_pMetric, dest, "Gameloaded");
      if ( this->m_FirstLoad )
      {
        UFG::qSPrintf(dest, 128, "i32_%s", "SessionFirstLoad");
        OSuite::ZMetric::SetProperty(v10->m_pMetric, dest, 1);
        this->m_FirstLoad = 0;
      }
      else
      {
        UFG::qSPrintf(dest, 128, "i32_%s", "SessionFirstLoad");
        OSuite::ZMetric::SetProperty(v10->m_pMetric, dest, 0);
      }
      UFG::OSuiteDBLogger::SubmitMetric(v10, 0);
    }
  }
LABEL_16:
  this->mOperation = GSLS_OP_LOAD;
  this->mStatus = GSLS_WAITING;
  this->mActiveGameSlot = v4;
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, 0xBA6593AF, 0xFFFFFFFF);
  UFG::HDDmanager::HDDLoad(UFG::HDDmanager::mInstance, this->mFileContainer, UFG::GameSaveLoad::SaveLoadDoneCallBack);
  UFG::qString::~qString(&v14);
}

// File Line: 1895
// RVA: 0x4AD730
void __fastcall UFG::GameSaveLoad::LoadDataEnd(UFG::GameSaveLoad *this, UFG::errCode *err)
{
  UFG::eHDD_RETURN_CODE eCode; // r12d
  char v4; // bp
  UFG::HddFileContainer *mFileContainer; // rax
  UFG::HddSaveFile *mNext; // r14
  void *mData; // rsi
  unsigned int bufferSize; // r15d
  int v9; // eax
  __int64 v10; // rdi
  __int64 v11; // rcx
  UFG::GameStatTracker *v12; // rax
  bool v13; // r13
  UFG::GameStatTracker *v14; // rax
  UFG::ProgressionTracker *v15; // rax
  unsigned int v16; // edx
  __int64 v17; // rcx
  UFG::GameStatTracker *v18; // rax
  UFG::GameStatTracker *v19; // rax
  UFG::allocator::free_link *v20; // r15
  UFG::allocator::free_link *v21; // rax
  unsigned int mFileSize; // edx

  eCode = err->eCode;
  v4 = 0;
  mFileContainer = this->mFileContainer;
  mNext = (UFG::HddSaveFile *)mFileContainer->FileList.mNode.mNext;
  if ( mNext == (UFG::HddSaveFile *)&mFileContainer->FileList )
  {
LABEL_35:
    UFG::GameSaveLoad::LoadDataFinalize(this);
    return;
  }
  do
  {
    UFG::qPrintf("File Name %s, File Size = %d \n", mNext->mFileName.mData, mNext->mFileSize);
    mData = mNext->mData;
    bufferSize = mNext->mFileSize;
    v9 = mNext->mUserData[0];
    v10 = mNext->mUserData[1];
    switch ( v9 )
    {
      case 1:
        break;
      case 2:
        if ( eCode )
        {
          v4 = 1;
          v11 = v10;
          if ( eCode == eHDD_RET_INVALID_DEVICE )
          {
            this->m_GameSlotHeaderInfo[v10].m_State = SAVE_GAME_HEADER_STATE_INVALID_DEVICE;
            UFG::UIScreenManagerBase::queueMessage(
              UFG::UIScreenManager::s_instance,
              UI_HASH_LOAD_OPERATION_INVALID_DEVICE_4,
              0xFFFFFFFF);
            break;
          }
          goto LABEL_14;
        }
        if ( !UFG::GameSaveLoad::IsSaveGameValid(this, (__int64)mNext->mData, bufferSize) )
        {
          v11 = v10;
          v4 = 1;
LABEL_14:
          this->m_GameSlotHeaderInfo[v11].m_State = SAVE_GAME_HEADER_STATE_CORRUPT;
          v16 = UI_HASH_CORRUPT_SAVE_SLOT_4;
LABEL_15:
          UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, v16, 0xFFFFFFFF);
          break;
        }
        v12 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::Reset(v12, 0);
        v13 = (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_9;
        v14 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::Descramble(v14, *((_QWORD *)mData + 1), 0x34u, (char *)mData, bufferSize);
        if ( (_S19_1 & 1) == 0 )
        {
          _S19_1 |= 1u;
          UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
          atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
        }
        UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
        if ( UFG::ProgressionTracker::LoadedProgression(&sProgressionTracker, 0x34, (char *)mData, bufferSize, v13) )
        {
          v15 = UFG::ProgressionTracker::Instance();
          UFG::ProgressionTracker::UpdateCompletionPercentage(v15);
        }
        else
        {
          this->m_GameSlotHeaderInfo[v10].m_State = SAVE_GAME_HEADER_STATE_CORRUPT;
          v4 = 1;
          UFG::UIScreenManagerBase::queueMessage(
            UFG::UIScreenManager::s_instance,
            UI_HASH_CORRUPT_SAVE_SLOT_4,
            0xFFFFFFFF);
        }
        break;
      case 3:
        if ( eCode )
        {
          v17 = v10;
          if ( eCode == eHDD_RET_NO_FILE )
          {
            this->m_GameSlotHeaderInfo[v10].m_State = SAVE_GAME_HEADER_STATE_EMPTY;
            break;
          }
          v4 = 1;
          if ( eCode == eHDD_RET_INVALID_DEVICE )
          {
            this->m_GameSlotHeaderInfo[v10].m_State = SAVE_GAME_HEADER_STATE_INVALID_DEVICE;
            v16 = UI_HASH_LOAD_OPERATION_INVALID_DEVICE_4;
            goto LABEL_15;
          }
        }
        else
        {
          if ( (unsigned int)UFG::GameSaveLoad::CheckVersion(this, (const char *)mNext->mData, 0x60001u) )
          {
            v18 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::Descramble(v18, *((_QWORD *)mData + 1), 0x34u, (char *)mData, bufferSize);
            v19 = UFG::GameStatTracker::Instance();
            if ( UFG::GameSnapshot::DeserializeByFilter(v19->mpSnapshots[0], 4u, 2u, (char *)mData + 52) )
            {
              UFG::GameSaveLoad::ApplyOptions(this);
              break;
            }
          }
          v17 = v10;
          v4 = 1;
        }
        this->m_GameSlotHeaderInfo[v17].m_State = SAVE_GAME_HEADER_STATE_CORRUPT;
        UFG::UIScreenManagerBase::queueMessage(
          UFG::UIScreenManager::s_instance,
          UI_HASH_CORRUPT_GAME_OPTIONS_4,
          0xFFFFFFFF);
        break;
      case 4:
        if ( eCode )
        {
          UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_CORRUPT_PHOTO_4, 0xFFFFFFFF);
        }
        else
        {
          v20 = UFG::qMalloc(mNext->mFileSize, "Photo", 0i64);
          UFG::qMemCopy(v20, mData, mNext->mFileSize);
          v21 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x50ui64, "GameSaveLoad", 0i64, 1u);
          if ( v21 )
          {
            mFileSize = mNext->mFileSize;
            v21[1].mNext = v21 + 1;
            v21[2].mNext = v21 + 1;
            v21->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
            LODWORD(v21[3].mNext) = -1;
            v21[4].mNext = 0i64;
            v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
            v21[5].mNext = (UFG::allocator::free_link *)UI_HASH_PHOTO_LOADED_14;
            v21[6].mNext = (UFG::allocator::free_link *)-1i64;
            LODWORD(v21[3].mNext) = 5;
            v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessageSaveLoad::`vftable;
            LODWORD(v21[7].mNext) = v10 - 6;
            v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePhotoLoaded::`vftable;
            v21[8].mNext = v20;
            LODWORD(v21[9].mNext) = mFileSize;
          }
          UFG::UIScreenManagerBase::queueMessageEx(UFG::UIScreenManager::s_instance, (UFG::UIMessage *)v21);
        }
        break;
    }
    mNext = (UFG::HddSaveFile *)mNext->mNext;
  }
  while ( mNext != (UFG::HddSaveFile *)&this->mFileContainer->FileList );
  if ( !v4 )
    goto LABEL_35;
}

// File Line: 2145
// RVA: 0x4ADB30
void __fastcall UFG::GameSaveLoad::LoadDataFinalize(UFG::GameSaveLoad *this)
{
  bool v2; // bp
  UFG::HddFileContainer *mFileContainer; // rsi
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *mPrev; // rdx
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *mNext; // rax
  unsigned int v6; // edx

  v2 = this->mStatus == GSLS_SUCCESS;
  UFG::HddFileContainer::EmptyContainer(this->mFileContainer);
  mFileContainer = this->mFileContainer;
  if ( mFileContainer )
  {
    UFG::qList<UFG::HddSaveFile,UFG::HddSaveFile,1,0>::DeleteNodes(&mFileContainer->FileList);
    mPrev = mFileContainer->FileList.mNode.mPrev;
    mNext = mFileContainer->FileList.mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    mFileContainer->FileList.mNode.mPrev = &mFileContainer->FileList.mNode;
    mFileContainer->FileList.mNode.mNext = &mFileContainer->FileList.mNode;
    operator delete[](mFileContainer);
  }
  this->mFileContainer = 0i64;
  UFG::qString::Set(&this->mActiveFolderDisplayNamePS, 0i64);
  this->mActiveGameSlot = GAMESLOT_INVALID;
  *(_QWORD *)&this->mStatus = 0i64;
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, 0xAB317A37, 0xFFFFFFFF);
  v6 = 1323471633;
  if ( v2 )
    v6 = 1552074461;
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, v6, 0xFFFFFFFF);
}

// File Line: 2181
// RVA: 0x49A7F0
void __fastcall UFG::GameSaveLoad::DeleteDataStart(UFG::GameSaveLoad *this, __int32 eSlot, int eSaveType)
{
  UFG::allocator::free_link *v6; // rax
  UFG::HddFileContainer *v7; // rax
  UFG::qString *GameOptionsFullFilename; // rax
  UFG::qString *PhotoFullFilename; // rax
  UFG::qString *GameSlotFullFilename; // rax
  UFG::HddSaveFile *v11; // rax
  UFG::qString v12; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+60h] [rbp-38h] BYREF

  UFG::qString::qString(&v12);
  UFG::HDDmanager::mInstance->m_iSlotNum = eSlot;
  v6 = UFG::qMalloc(0x20ui64, "User Pro Container", 0i64);
  if ( v6 )
    UFG::HddFileContainer::HddFileContainer((UFG::HddFileContainer *)v6);
  else
    v7 = 0i64;
  this->mFileContainer = v7;
  if ( (unsigned int)(eSaveType - 1) <= 1 )
  {
    GameSlotFullFilename = UFG::GameSaveLoad::GetGameSlotFullFilename(
                             this,
                             &result,
                             (UFG::GameSaveLoad::eGameSlotNum)eSlot);
    UFG::qString::Set(&v12, GameSlotFullFilename->mData, GameSlotFullFilename->mLength, 0i64, 0);
  }
  else if ( eSaveType == 3 )
  {
    GameOptionsFullFilename = UFG::GameSaveLoad::GetGameOptionsFullFilename(this, &result);
    UFG::qString::Set(&v12, GameOptionsFullFilename->mData, GameOptionsFullFilename->mLength, 0i64, 0);
  }
  else
  {
    if ( eSaveType != 4 )
      goto LABEL_12;
    PhotoFullFilename = UFG::GameSaveLoad::GetPhotoFullFilename(this, &result, this->m_iCurrentPhotoNum);
    UFG::qString::Set(&v12, PhotoFullFilename->mData, PhotoFullFilename->mLength, 0i64, 0);
  }
  UFG::qString::~qString(&result);
  v11 = UFG::HddFileContainer::Add(this->mFileContainer, v12.mData, 0i64, 0, HDD_FILE_TYPE_FIRST);
  if ( v11 )
  {
    v11->mUserData[0] = eSaveType;
    v11->mUserData[1] = eSlot;
  }
LABEL_12:
  this->mStatus = GSLS_WAITING;
  this->mOperation = GSLS_OP_DELETE;
  UFG::HDDmanager::HDDDelete(UFG::HDDmanager::mInstance, this->mFileContainer, UFG::GameSaveLoad::SaveLoadDoneCallBack);
  UFG::qString::~qString(&v12);
}

// File Line: 2237
// RVA: 0x49A620
void __fastcall UFG::GameSaveLoad::DeleteDataEnd(UFG::GameSaveLoad *this, UFG::errCode *err)
{
  UFG::HddFileContainer *mFileContainer; // rax
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *mNext; // rbx
  __int64 eCode; // rbp
  int mNext_high; // esi
  UFG::allocator::free_link *v7; // rax
  __int64 v8; // rcx
  UFG::HddFileContainer *v9; // rsi
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *mPrev; // rdx
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v11; // rax

  mFileContainer = this->mFileContainer;
  mNext = mFileContainer->FileList.mNode.mNext;
  eCode = err->eCode;
  if ( mNext != (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)&mFileContainer->FileList )
  {
    do
    {
      UFG::qPrintf("DeleteDataEnd: File Name %s, (Slot) %d \n", (const char *)mNext[3].mPrev, HIDWORD(mNext[7].mNext));
      if ( !eCode && LODWORD(mNext[7].mNext) == 4 )
      {
        mNext_high = HIDWORD(mNext[7].mNext);
        v7 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "GameSaveLoad", 0i64, 1u);
        if ( v7 )
        {
          v7[1].mNext = v7 + 1;
          v7[2].mNext = v7 + 1;
          v7->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
          LODWORD(v7[3].mNext) = -1;
          v7[4].mNext = 0i64;
          v7->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
          LODWORD(v7[5].mNext) = UI_HASH_PHOTO_DELETED_14;
          HIDWORD(v7[5].mNext) = 0;
          v7[6].mNext = (UFG::allocator::free_link *)-1i64;
          LODWORD(v7[3].mNext) = 5;
          v7->mNext = (UFG::allocator::free_link *)&UFG::UIMessageSaveLoad::`vftable;
          LODWORD(v7[7].mNext) = mNext_high - 6;
        }
        else
        {
          v7 = 0i64;
        }
        UFG::UIScreenManagerBase::queueMessageEx(UFG::UIScreenManager::s_instance, (UFG::UIMessage *)v7);
      }
      v8 = SHIDWORD(mNext[7].mNext);
      *(_QWORD *)&this->m_GameSlotHeaderInfo[v8].m_State = 4i64;
      this->m_GameSlotHeaderInfo[v8].m_iTimeDateStamp = 0i64;
      mNext = mNext->mNext;
    }
    while ( mNext != &this->mFileContainer->FileList.mNode );
  }
  UFG::HddFileContainer::EmptyContainer(this->mFileContainer);
  v9 = this->mFileContainer;
  if ( v9 )
  {
    UFG::qList<UFG::HddSaveFile,UFG::HddSaveFile,1,0>::DeleteNodes(&v9->FileList);
    mPrev = v9->FileList.mNode.mPrev;
    v11 = v9->FileList.mNode.mNext;
    mPrev->mNext = v11;
    v11->mPrev = mPrev;
    v9->FileList.mNode.mPrev = &v9->FileList.mNode;
    v9->FileList.mNode.mNext = &v9->FileList.mNode;
    operator delete[](v9);
  }
  this->mFileContainer = 0i64;
  *(_QWORD *)&this->mStatus = 0i64;
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_DELETE_GAME_COMPLETE_14, 0xFFFFFFFF);
}

// File Line: 2288
// RVA: 0x4C7750
void __fastcall UFG::GameSaveLoad::UpdateGameSlotInfo(
        UFG::GameSaveLoad *this,
        UFG::GameSaveLoad::eGameSlotNum eSlotNum,
        UFG::GameSaveLoad::SaveGameHeaderState state,
        char *file_data,
        unsigned int file_data_size)
{
  __int64 v6; // rbp
  bool IsSaveGameValid; // al
  char *v10; // rcx
  char *v11; // rbx

  v6 = eSlotNum;
  IsSaveGameValid = UFG::GameSaveLoad::IsSaveGameValid(this, (__int64)file_data, file_data_size);
  v10 = 0i64;
  if ( IsSaveGameValid )
    v10 = file_data;
  v11 = (char *)this + 80 * v6;
  *((_DWORD *)v11 + 24) = state;
  if ( v10 )
  {
    *((_DWORD *)v11 + 25) = *((_DWORD *)v10 + 12);
    *((_QWORD *)v11 + 13) = *((_QWORD *)v10 + 1);
    UFG::qMemCopy(v11 + 112, v10 + 16, 0x40u);
  }
  else
  {
    *((_DWORD *)v11 + 25) = 0;
    *((_QWORD *)v11 + 13) = 0i64;
    v11[112] = 0;
  }
  UFG::qPrintf(
    "[GameSaveLoad] Slot %d  State=%d  Size=%d  TimeStamp=0x%016x64  Mission=%s\n",
    (unsigned int)v6,
    *((unsigned int *)v11 + 24),
    *((unsigned int *)v11 + 25),
    *((_QWORD *)v11 + 13),
    v11 + 112);
}

// File Line: 2334
// RVA: 0x4ACD10
bool __fastcall UFG::GameSaveLoad::IsSaveGameValid(
        UFG::GameSaveLoad *this,
        __int64 file_data,
        unsigned int file_data_size)
{
  bool v5; // cl
  UFG::GameStatTracker *v6; // rax

  if ( !file_data || !file_data_size )
    return 0;
  v5 = file_data_size >= 0x34;
  if ( file_data_size >= 0x34 )
  {
    v5 = *(_BYTE *)file_data == 0x54
      && *(_BYTE *)(file_data + 2) == 0x30
      && *(_BYTE *)(file_data + 3) == 0x31
      && *(_BYTE *)(file_data + 1) == 0x43
      && (*(_DWORD *)(file_data + 4) & 0xFFFF0000) == 0x60000;
    if ( v5 && file_data_size > 52 )
    {
      v5 = *(_DWORD *)(file_data + 48) == file_data_size;
      if ( *(_DWORD *)(file_data + 48) == file_data_size )
      {
        v6 = UFG::GameStatTracker::Instance();
        return UFG::GameStatTracker::IsValidBuffer(
                 v6,
                 *(_QWORD *)(file_data + 8),
                 52u,
                 (char *)file_data,
                 file_data_size);
      }
    }
  }
  return v5;
}

// File Line: 2424
// RVA: 0x496C70
signed __int64 __fastcall UFG::GameSaveLoad::CheckVersion(
        UFG::GameSaveLoad *this,
        const char *data,
        unsigned int version)
{
  signed __int64 result; // rax
  int dest; // [rsp+48h] [rbp+20h] BYREF

  dest = 0;
  if ( (unsigned int)UFG::qStringCompare("TC01", data, 4) )
    return 0i64;
  UFG::qMemCopy(&dest, data + 4, 4u);
  result = 8i64;
  if ( ((version ^ dest) & 0xFFFF0000) != 0 )
    return 0i64;
  return result;
}

// File Line: 2503
// RVA: 0x4BB4D0
UFG::allocator::free_link *__fastcall UFG::GameSaveLoad::SerializeHeaderData(
        UFG::GameSaveLoad *this,
        unsigned int filterMask,
        unsigned int persistenceMask,
        int *iHeaderSaveSize)
{
  const char *SaveGameName; // rax
  UFG::allocator::free_link *v6; // rdi
  UFG::GameStatTracker *v7; // rbx
  __int64 source[2]; // [rsp+20h] [rbp-38h] BYREF
  char dest[40]; // [rsp+30h] [rbp-28h] BYREF
  int v11; // [rsp+78h] [rbp+20h] BYREF

  source[1] = -2i64;
  UFG::qMemSet(dest, 0, 0x20u);
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  SaveGameName = (const char *)UFG::ProgressionTracker::GetSaveGameName(&sProgressionTracker);
  if ( !SaveGameName )
    SaveGameName = UFG::UI::LocalizeText("$COMMON_UNKNOWN");
  strncpy(dest, SaveGameName, 0x1Fui64);
  *iHeaderSaveSize = 52;
  v6 = UFG::qMalloc(0x34ui64, "char", 0i64);
  source[0] = (__int64)UFG::qGetSystemTime();
  UFG::qMemCopy(v6, "TC01", 4u);
  UFG::qMemCopy((char *)&v6->mNext + 4, &SAVEGAME_VERSION_NUMBER, 4u);
  UFG::qMemCopy(&v6[1], source, 8u);
  UFG::qMemCopy(&v6[2], dest, 0x20u);
  v7 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v7 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v7;
  v11 = *iHeaderSaveSize + UFG::GameSnapshot::CalculateSerializeSize(v7->mpSnapshots[4], 0xFFFFFFF8, 2u);
  UFG::qMemCopy(&v6[6], &v11, 4u);
  return v6;
}

// File Line: 2562
// RVA: 0x4946E0
void __fastcall UFG::GameSaveLoad::ApplyOptions(UFG::GameSaveLoad *this)
{
  UFG::GameStatTracker *v2; // rdi
  UFG::GameStatTracker *v3; // rcx
  UFG::TiDo *v4; // rbx
  float mValue; // xmm6_4
  unsigned int v6; // eax
  UFG::GameStatTracker *v7; // rcx
  UFG::TiDo *v8; // rbx
  float v9; // xmm6_4
  unsigned int v10; // eax
  UFG::GameStatTracker *v11; // rcx
  UFG::TiDo *v12; // rbx
  float v13; // xmm6_4
  unsigned int v14; // eax
  UFG::GameStatTracker *v15; // rcx
  UFG::TiDo *v16; // rbx
  float v17; // xmm6_4
  unsigned int v18; // eax
  UFG::GameStatTracker *v19; // rcx
  UFG::GameStatTracker *v20; // rcx
  unsigned int v21; // ecx
  UFG::GameStatTracker *v22; // rdx
  UFG::GameStatTracker *v23; // rax
  unsigned int v24; // ecx
  UFG::GameStatTracker *v25; // rdx

  v2 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v3 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  v4 = UFG::TiDo::m_pInstance;
  mValue = (float)v3->mpSnapshots[0]->mInts[125].mValue;
  v6 = UFG::TiDo::CalcWwiseUid("master_sfx_volume");
  UFG::TiDo::SetWwiseRtpcValue(v4, v6, mValue, 0xFFFFFFFFFFFFFFFFui64);
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v7 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v7 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v7;
  v8 = UFG::TiDo::m_pInstance;
  v9 = (float)v7->mpSnapshots[0]->mInts[127].mValue;
  v10 = UFG::TiDo::CalcWwiseUid("master_music_volume");
  UFG::TiDo::SetWwiseRtpcValue(v8, v10, v9, 0xFFFFFFFFFFFFFFFFui64);
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v11 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v11 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v11;
  v12 = UFG::TiDo::m_pInstance;
  v13 = (float)v11->mpSnapshots[0]->mInts[126].mValue;
  v14 = UFG::TiDo::CalcWwiseUid("master_dialog_volume");
  UFG::TiDo::SetWwiseRtpcValue(v12, v14, v13, 0xFFFFFFFFFFFFFFFFui64);
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v15 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v15 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v15;
  v16 = UFG::TiDo::m_pInstance;
  v17 = (float)v15->mpSnapshots[0]->mInts[128].mValue;
  v18 = UFG::TiDo::CalcWwiseUid("master_radio_volume");
  UFG::TiDo::SetWwiseRtpcValue(v16, v18, v17, 0xFFFFFFFFFFFFFFFFui64);
  UFG::GameSaveLoad::ApplyRumble(this);
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v19 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v19 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v19;
  UFG::SubtitleManager::SetSubtitleMode((UFG::SubtitleManager::eSubtitleMode)v19->mpSnapshots[0]->mInts[129].mValue);
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v20 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v20 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v20;
  UFG::gUIViewportScale = UFG::UIHKScreenOptionsDisplay::ConvertScaleOption(v20->mpSnapshots[0]->mInts[124].mValue);
  v21 = _S12_6;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v21 = _S12_6;
  }
  v22 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v22 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v22;
  if ( (v21 & 1) == 0 )
  {
    _S12_6 = v21 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v22 = UFG::GameStatTracker::mspInstance;
  }
  v23 = &sGameStatTracker;
  if ( v22 )
    v23 = v22;
  UFG::GameStatTracker::mspInstance = v23;
  UFG::WheeledVehicleManager::SetTrueDirectionUpdateEnabled(
    UFG::WheeledVehicleManager::m_Instance,
    v23->mpSnapshots[0]->mBools[44].mValue);
  UFG::InputSystem::msPCKeyboardSwapMode = UFG::GameSaveLoad::GetKeyboardSwapMode(this);
  v24 = _S12_6;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v24 = _S12_6;
  }
  v25 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v25 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v25;
  UFG::InputSystem::msMouseSensitivity = (float)((float)(UFG::gMouseSensitivityMax - UFG::gMouseSensitivityMin)
                                               * v25->mpSnapshots[0]->mFloats[117].mValue)
                                       + UFG::gMouseSensitivityMin;
  if ( (v24 & 1) == 0 )
  {
    _S12_6 = v24 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v25 = UFG::GameStatTracker::mspInstance;
  }
  if ( v25 )
    v2 = v25;
  UFG::GameStatTracker::mspInstance = v2;
  UFG::InputSystem::msMouseInputRawDesired = v2->mpSnapshots[0]->mBools[46].mValue;
  UFG::LoadKeyboardRemap((UFG *)UFG::InputSystem::msMouseInputRawDesired);
}

// File Line: 2600
// RVA: 0x494B20
void __fastcall UFG::GameSaveLoad::ApplyRumble(UFG::GameSaveLoad *this)
{
  unsigned int v1; // ecx
  UFG::GameStatTracker *v2; // rbx
  UFG::GameStatTracker *v3; // rdx
  int mValue; // ecx
  int v5; // ecx
  bool v6; // dl

  v1 = _S12_6;
  v2 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
  }
  v3 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  if ( !v3->mpSnapshots[0]->mBools[42].mValue )
    goto LABEL_15;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v3 = UFG::GameStatTracker::mspInstance;
  }
  if ( v3 )
    v2 = v3;
  UFG::GameStatTracker::mspInstance = v2;
  mValue = v2->mpSnapshots[0]->mInts[133].mValue;
  v5 = mValue <= 0 ? UFG::GameStatTracker::Instance()->mpSnapshots[0]->mBools[45].mValue : mValue - 1;
  if ( v5 == 2 )
LABEL_15:
    v6 = 0;
  else
    v6 = 1;
  UFG::TiDo::SetRumbleEnabled(UFG::TiDo::m_pInstance, v6);
}

// File Line: 2606
// RVA: 0x4A43F0
__int64 __fastcall UFG::GameSaveLoad::GetKeyboardSwapMode(UFG::GameSaveLoad *this)
{
  UFG::GameStatTracker *v1; // rbx
  int mValue; // eax

  v1 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v1 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v1;
  mValue = v1->mpSnapshots[0]->mInts[133].mValue;
  if ( mValue <= 0 )
    return UFG::GameStatTracker::Instance()->mpSnapshots[0]->mBools[45].mValue;
  else
    return (unsigned int)(mValue - 1);
}

// File Line: 2620
// RVA: 0x4ACA20
_BOOL8 __fastcall UFG::GameSaveLoad::IsLaunchHeader(
        UFG::GameSaveLoad *this,
        UFG::GameSaveLoad::tsSaveGameHeaderInfo *header)
{
  bool v2; // bl
  UFG::qString v4; // [rsp+28h] [rbp-30h] BYREF

  UFG::qString::qString(&v4, header->m_szLastMissionStringID);
  v2 = !(unsigned int)UFG::qStringCompare(v4.mData, "$SGTITLE_WELCOME_TO_HONG_KONG", -1)
    || !(unsigned int)UFG::qStringCompare(v4.mData, "$SGTITLE_GOING_UNDER", -1)
    || !(unsigned int)UFG::qStringCompare(v4.mData, "$SGTITLE_VENDOR_FAVOR", -1)
    || !(unsigned int)UFG::qStringCompare(v4.mData, "$SGTITLE_VENDOR_EXTORTION", -1);
  UFG::qString::~qString(&v4);
  return v2;
}

