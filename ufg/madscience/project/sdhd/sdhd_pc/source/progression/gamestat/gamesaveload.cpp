// File Line: 168
// RVA: 0x4AB630
UFG::GameSaveLoad *__fastcall UFG::GameSaveLoad::Instance()
{
  if ( !(_S13_4 & 1) )
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
  UFG::GameSaveLoad *v1; // rbx

  v1 = this;
  UFG::qString::qString(&this->mFlowSettings.m_Postfix);
  UFG::qString::qString(&v1->mFlowSettings.m_SaveFileTitle);
  v1->mFileContainer = 0i64;
  UFG::qString::qString(&v1->mActiveFolderDisplayNamePS);
  v1->m_iCurrentPhotoNum = 0;
  v1->m_pCurrentPhoto = 0i64;
  v1->m_iCurrentPhotoSize = 0;
  v1->m_FirstLoad = 1;
  UFG::gGameSaveLoad = v1;
  UFG::qString::Set(&v1->mFlowSettings.m_Postfix, &customWorldMapCaption);
  v1->mFlowSettings.m_iNumSlots = 4;
  *(_QWORD *)&v1->mStatus = 0i64;
  v1->mActiveGameSlot = -1;
  memset(v1->m_GameSlotHeaderInfo, 0, 0x280ui64);
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xA1FC293D,
    0xFFFFFFFF);
  UFG::qMemSet(v1->m_bPhotoExists, 0, 1u);
}

// File Line: 220
// RVA: 0x4ACCF0
bool __fastcall UFG::GameSaveLoad::IsSaveAvaliable(UFG::GameSaveLoad *this)
{
  bool result; // al

  if ( this->mStatus )
    result = 0;
  else
    result = (UFG::HDDmanager::mInstance->m_eSaveLoadPermission >> 1) & 1;
  return result;
}

// File Line: 253
// RVA: 0x4ACAC0
bool __fastcall UFG::GameSaveLoad::IsLoadAvaliable(UFG::GameSaveLoad *this)
{
  bool result; // al

  if ( this->mStatus )
    result = 0;
  else
    result = UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1;
  return result;
}

// File Line: 286
// RVA: 0x4AEE30
char __fastcall UFG::GameSaveLoad::LoadSaveDataFileList(UFG::GameSaveLoad *this)
{
  if ( this->mStatus || !(UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) )
    return 0;
  this->mOperation = 5;
  this->mStatus = 0;
  UFG::HDDmanager::HDDFileList(UFG::HDDmanager::mInstance, UFG::GameSaveLoad::SaveLoadDoneCallBack);
  return 1;
}

// File Line: 305
// RVA: 0x4B8260
char __fastcall UFG::GameSaveLoad::SaveAutoGameSlot(UFG::GameSaveLoad *this)
{
  if ( this->mStatus || !((UFG::HDDmanager::mInstance->m_eSaveLoadPermission >> 1) & 1) )
    return 0;
  UFG::GameSaveLoad::SaveDataStart(this, GAMESLOT_AUTOSAVE, DATATYPE_GAME);
  return 1;
}

// File Line: 320
// RVA: 0x4B8C20
char __fastcall UFG::GameSaveLoad::SaveGameSlot(UFG::GameSaveLoad *this, UFG::GameSaveLoad::eGameSlotNum GameSlotNum)
{
  if ( this->mStatus || !((UFG::HDDmanager::mInstance->m_eSaveLoadPermission >> 1) & 1) )
    return 0;
  UFG::GameSaveLoad::SaveDataStart(this, GameSlotNum, DATATYPE_GAME);
  return 1;
}

// File Line: 333
// RVA: 0x4AE5E0
char __fastcall UFG::GameSaveLoad::LoadGameSlot(UFG::GameSaveLoad *this, UFG::GameSaveLoad::eGameSlotNum GameSlotNum)
{
  if ( this->mStatus || !(UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) || GameSlotNum == -1 )
    return 0;
  UFG::GameSaveLoad::LoadDataStart(this, GameSlotNum, DATATYPE_GAME);
  return 1;
}

// File Line: 344
// RVA: 0x4A2050
__int64 __fastcall UFG::GameSaveLoad::GetContinueGameSlot(UFG::GameSaveLoad *this)
{
  unsigned int v1; // edx
  unsigned int v2; // er9
  unsigned __int64 v3; // rax
  unsigned int v4; // er10
  unsigned __int64 *v5; // rcx

  v1 = 0;
  v2 = -1;
  v3 = 0i64;
  if ( this->m_GameSlotHeaderInfo[4].m_State == 5 && this->m_GameSlotHeaderInfo[4].m_iTimeDateStamp )
  {
    v2 = 4;
    v3 = this->m_GameSlotHeaderInfo[4].m_iTimeDateStamp;
  }
  v4 = this->mFlowSettings.m_iNumSlots;
  if ( v4 )
  {
    v5 = &this->m_GameSlotHeaderInfo[0].m_iTimeDateStamp;
    do
    {
      if ( *((_DWORD *)v5 - 2) == 5 && *v5 > v3 )
      {
        v2 = v1;
        v3 = *v5;
      }
      ++v1;
      v5 += 10;
    }
    while ( v1 < v4 );
  }
  return v2;
}

// File Line: 375
// RVA: 0x4AE5A0
char __fastcall UFG::GameSaveLoad::LoadGameOptions(UFG::GameSaveLoad *this)
{
  if ( this->mStatus || !(UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) )
    return 0;
  UFG::GameSaveLoad::LoadDataStart(this, NUM_GAMESAVES, DATATYPE_OPTIONS);
  return 1;
}

// File Line: 388
// RVA: 0x4B8BE0
char __fastcall UFG::GameSaveLoad::SaveGameOptions(UFG::GameSaveLoad *this)
{
  if ( this->mStatus || !((UFG::HDDmanager::mInstance->m_eSaveLoadPermission >> 1) & 1) )
    return 0;
  UFG::GameSaveLoad::SaveDataStart(this, NUM_GAMESAVES, DATATYPE_OPTIONS);
  return 1;
}

// File Line: 436
// RVA: 0x4AED30
char __fastcall UFG::GameSaveLoad::LoadPhoto(UFG::GameSaveLoad *this, unsigned int iPhotoNum)
{
  if ( this->mStatus || !(UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) || iPhotoNum >= 1 )
    return 0;
  UFG::GameSaveLoad::LoadDataStart(this, (UFG::GameSaveLoad::eGameSlotNum)(iPhotoNum + 6), DATATYPE_PHOTO);
  return 1;
}

// File Line: 482
// RVA: 0x4A5930
signed __int64 __fastcall UFG::GameSaveLoad::GetNumPhotosTaken(UFG::GameSaveLoad *this)
{
  signed __int64 result; // rax

  result = 0i64;
  if ( this->m_bPhotoExists[0] )
    result = 1i64;
  return result;
}

// File Line: 499
// RVA: 0x49DAA0
bool __fastcall UFG::GameSaveLoad::DoesPhotoExists(UFG::GameSaveLoad *this, unsigned int iPhotoNum)
{
  bool result; // al

  if ( iPhotoNum < 1 )
    result = this->m_bPhotoExists[iPhotoNum];
  else
    result = 0;
  return result;
}

// File Line: 513
// RVA: 0x49AB30
char __fastcall UFG::GameSaveLoad::DeletePhoto(UFG::GameSaveLoad *this, unsigned int iPhotoNum)
{
  char *v2; // rbx

  if ( this->mStatus )
    return 0;
  if ( !((UFG::HDDmanager::mInstance->m_eSaveLoadPermission >> 1) & 1) )
    return 0;
  if ( iPhotoNum >= 1 )
    return 0;
  v2 = (char *)this + iPhotoNum;
  if ( !v2[804] )
    return 0;
  this->m_iCurrentPhotoNum = iPhotoNum;
  UFG::GameSaveLoad::DeleteDataStart(this, (UFG::GameSaveLoad::eGameSlotNum)(iPhotoNum + 6), DATATYPE_PHOTO);
  v2[804] = 0;
  return 1;
}

// File Line: 545
// RVA: 0x49AA50
char __fastcall UFG::GameSaveLoad::DeleteGameData(UFG::GameSaveLoad *this, unsigned int iGameSlotNum)
{
  if ( this->mStatus
    || !((UFG::HDDmanager::mInstance->m_eSaveLoadPermission >> 1) & 1)
    || (signed int)iGameSlotNum >= 5
    || this->m_GameSlotHeaderInfo[iGameSlotNum].m_State != 5 )
  {
    return 0;
  }
  UFG::GameSaveLoad::DeleteDataStart(this, (UFG::GameSaveLoad::eGameSlotNum)iGameSlotNum, DATATYPE_GAME);
  return 1;
}

// File Line: 574
// RVA: 0x4BB700
void __fastcall UFG::GameSaveLoad::SetActiveFlow(UFG::GameSaveLoad *this, UFG::qSymbol *flowId)
{
  UFG::qSymbol *v2; // rbx
  UFG::GameSaveLoad *v3; // rdi
  UFG::qSymbol *v4; // rax
  UFG::qPropertySet *v5; // rax
  UFG::qPropertySet *v6; // rbx
  UFG::qSymbol *v7; // rax
  char *v8; // rax
  const char *v9; // rsi
  const char *v10; // rdx
  UFG::qSymbol *v11; // rax
  unsigned int *v12; // rax
  signed int v13; // eax
  UFG::qSymbol *v14; // rax
  char *v15; // rax
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h]

  v2 = flowId;
  v3 = this;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v4 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, 0x3971E8ABu);
  v5 = UFG::PropertySetManager::FindPropertySet(v4);
  if ( v5 )
  {
    v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(v5, v2, DEPTH_RECURSE);
    if ( v6 )
    {
      v7 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, 0xA7956F38);
      v8 = UFG::qPropertySet::Get<char const *>(v6, v7, DEPTH_RECURSE);
      v9 = &customWorldMapCaption;
      v10 = &customWorldMapCaption;
      if ( v8 )
        v10 = v8;
      UFG::qString::Set(&v3->mFlowSettings.m_Postfix, v10);
      v11 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, 0xAF4C7D0E);
      v12 = UFG::qPropertySet::Get<unsigned long>(v6, v11, DEPTH_RECURSE);
      if ( v12 )
        v13 = *v12;
      else
        v13 = 4;
      v3->mFlowSettings.m_iNumSlots = v13;
      v14 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, 0xF8A6816F);
      v15 = UFG::qPropertySet::Get<char const *>(v6, v14, DEPTH_RECURSE);
      if ( v15 )
        v9 = v15;
      UFG::qString::Set(&v3->mFlowSettings.m_SaveFileTitle, v9);
      UFG::UIHKScreenHud::SetTexturePackForFlow(v3->mFlowSettings.m_Postfix.mData);
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
  UFG::GameSaveLoad *v1; // rsi
  UFG::GameSaveLoad::eGameSlotNum v2; // ebx
  __int64 v3; // rdi
  UFG::GameSaveLoad::tsSaveGameHeaderInfo *v4; // r14
  UFG::qString *v5; // rax
  char v6; // al
  UFG::qString v7; // [rsp+38h] [rbp-60h]
  UFG::qString result; // [rsp+60h] [rbp-38h]

  v1 = this;
  UFG::qString::qString(&v7);
  v2 = 0;
  v3 = 0i64;
  v4 = v1->m_GameSlotHeaderInfo;
  do
  {
    v5 = UFG::GameSaveLoad::GetSlotFullFilename(v1, &result, v2);
    UFG::qString::Set(&v7, v5->mData, v5->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
    v6 = UFG::HDDmanager::IsFileNameInList(UFG::HDDmanager::mInstance, v7.mData);
    UFG::HDDmanager::mInstance->mSaveDataExists[v3] = v6;
    v4->m_State = (v6 != 0) + 4;
    if ( v2 - 6 <= 1 )
      *((_BYTE *)&v1->m_pCurrentPhoto + v3 + 6) = v6;
    ++v2;
    ++v3;
    ++v4;
  }
  while ( (signed int)v2 < 8 );
  v1->m_GameSlotHeaderInfo[6].m_State = 0;
  *(_QWORD *)&v1->mStatus = 0i64;
  UFG::qString::~qString(&v7);
}

// File Line: 694
// RVA: 0x4A6280
UFG::qString *__fastcall UFG::GameSaveLoad::GetSlotFullFilename(UFG::GameSaveLoad *this, UFG::qString *result, UFG::GameSaveLoad::eGameSlotNum slot_num)
{
  UFG::GameSaveLoad::eGameSlotNum v3; // edi
  UFG::qString *v4; // rbx
  UFG::GameSaveLoad *v5; // rsi
  __int64 v6; // r9
  const char *v7; // rdx
  __int64 v9; // [rsp+20h] [rbp-18h]

  v3 = slot_num;
  v4 = result;
  v5 = this;
  UFG::qString::qString(result);
  LODWORD(v9) = 1;
  if ( v3 == GAMESLOT_AUTOSAVE )
  {
    UFG::qString::Format(v4, UFG::GameSlotFileNameAutoSave, v5->mFlowSettings.m_Postfix.mData);
  }
  else if ( v3 == NUM_GAMESAVES )
  {
    UFG::qString::Set(v4, UFG::GameOptions);
  }
  else
  {
    if ( v3 > GAMESLOT_4 )
    {
      v6 = v3 - NUM_GAMESAVES;
      v7 = UFG::GamePhotos;
    }
    else
    {
      v6 = v3 + GAMESLOT_2;
      v7 = UFG::GameSlotFileNames;
    }
    UFG::qString::Format(v4, v7, v5->mFlowSettings.m_Postfix.mData, v6, v9, -2i64);
  }
  return v4;
}

// File Line: 727
// RVA: 0x4A33C0
UFG::qString *__fastcall UFG::GameSaveLoad::GetGameSlotFullFilename(UFG::GameSaveLoad *this, UFG::qString *result, UFG::GameSaveLoad::eGameSlotNum GameSlotNum)
{
  UFG::GameSaveLoad::eGameSlotNum v3; // esi
  UFG::qString *v4; // rbx
  UFG::GameSaveLoad *v5; // rdi
  char *v6; // r8
  __int64 v8; // [rsp+20h] [rbp-18h]

  v3 = GameSlotNum;
  v4 = result;
  v5 = this;
  UFG::qString::qString(result);
  LODWORD(v8) = 1;
  v6 = v5->mFlowSettings.m_Postfix.mData;
  if ( v3 == 4 )
    UFG::qString::Format(v4, UFG::GameSlotFileNameAutoSave, v6);
  else
    UFG::qString::Format(v4, UFG::GameSlotFileNames, v6, v3 + 1, v8, -2i64);
  return v4;
}

// File Line: 745
// RVA: 0x4A3360
UFG::qString *__fastcall UFG::GameSaveLoad::GetGameOptionsFullFilename(UFG::GameSaveLoad *this, UFG::qString *result)
{
  UFG::qString *v2; // rbx

  v2 = result;
  UFG::qString::qString(result);
  UFG::qString::Set(v2, UFG::GameOptions);
  return v2;
}

// File Line: 755
// RVA: 0x4A5DC0
UFG::qString *__fastcall UFG::GameSaveLoad::GetPhotoFullFilename(UFG::GameSaveLoad *this, UFG::qString *result, unsigned int iPhotoNum)
{
  unsigned int v3; // ebx
  UFG::qString *v4; // rdi

  v3 = iPhotoNum;
  v4 = result;
  UFG::qString::qString(result);
  UFG::qString::Format(v4, UFG::GamePhotos, v3 + 1);
  return v4;
}

// File Line: 765
// RVA: 0x4B8C60
void __fastcall UFG::GameSaveLoad::SaveLoadDoneCallBack(UFG::errCode *err)
{
  UFG::errCode *v1; // rbx
  UFG::GameSaveLoad *v2; // rax
  UFG::GameSaveLoad *v3; // rax
  bool v4; // zf
  UFG::GameSaveLoad *v5; // rax
  UFG::GameSaveLoad *v6; // rax
  UFG::GameSaveLoad *v7; // rax
  UFG::eHDD_RETURN_CODE v8; // [rsp+30h] [rbp-18h]
  unsigned int v9; // [rsp+34h] [rbp-14h]
  UFG::eHDD_STATUS v10; // [rsp+38h] [rbp-10h]

  v1 = err;
  if ( err->eCode )
  {
    if ( !(_S13_4 & 1) )
    {
      _S13_4 |= 1u;
      UFG::GameSaveLoad::GameSaveLoad(&sGameSaveLoad);
      atexit(UFG::GameSaveLoad::Instance_::_2_::_dynamic_atexit_destructor_for__sGameSaveLoad__);
    }
    dword_142409D88 = 3;
  }
  else
  {
    if ( !(_S13_4 & 1) )
    {
      _S13_4 |= 1u;
      UFG::GameSaveLoad::GameSaveLoad(&sGameSaveLoad);
      atexit(UFG::GameSaveLoad::Instance_::_2_::_dynamic_atexit_destructor_for__sGameSaveLoad__);
    }
    dword_142409D88 = 2;
  }
  switch ( v1->eType )
  {
    case eHDD_STATUS_SAVE:
      v8 = v1->eCode;
      v9 = v1->errArg;
      v10 = v1->eType;
      v7 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::SaveDataEnd(v7, (UFG::errCode *)&v8);
      break;
    case eHDD_STATUS_LOAD:
      v4 = UFG::GameSaveLoad::Instance()->mOperation == GSLS_OP_LOAD_HEADERS;
      v8 = v1->eCode;
      v9 = v1->errArg;
      v10 = v1->eType;
      if ( v4 )
      {
        v5 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::LoadHeadersEnd(v5, (UFG::errCode *)&v8);
      }
      else
      {
        v6 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::LoadDataEnd(v6, (UFG::errCode *)&v8);
      }
      break;
    case eHDD_STATUS_DELETE:
      v8 = v1->eCode;
      v9 = v1->errArg;
      v10 = v1->eType;
      v3 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::DeleteDataEnd(v3, (UFG::errCode *)&v8);
      break;
    case eHDD_STATUS_FILELIST:
      v2 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::ProcessSaveDataFileList(v2);
      break;
  }
}

// File Line: 811
// RVA: 0x4BC460
void __fastcall UFG::GameSaveLoad::SetFileInfo(UFG::GameSaveLoad *this, UFG::HddSaveFile *pFile, UFG::GameSaveLoad::eSaveDataType eDataType, UFG::GameSaveLoad::eGameSlotNum eSlot)
{
  UFG::HddSaveFile *v4; // rdi
  const char *v5; // rbx
  UFG::qString *v6; // rax
  UFG::qString *v7; // rbx
  UFG::qString *v8; // rcx
  __int128 v9; // xmm7
  UFG::GameStatTracker *v10; // rax
  float v11; // xmm0_4
  UFG::qString *v12; // rax
  const char *v13; // rbx
  UFG::qString *v14; // rax
  UFG::qString *v15; // rbx
  char *v16; // rax
  const char *v17; // rax
  char *v18; // rdx
  char Dest; // [rsp+38h] [rbp-C0h]
  UFG::qString v20; // [rsp+58h] [rbp-A0h]
  UFG::qString v21; // [rsp+80h] [rbp-78h]
  UFG::qString result; // [rsp+A8h] [rbp-50h]

  v4 = pFile;
  if ( eDataType == 3 )
  {
    v5 = UFG::UI::LocalizeText("COMMON_GAME_OPTIONS_FILE_TITLE_PS3");
    UFG::qString::Set(&v4->mTitle, v5);
    UFG::qString::qString(&result, v5);
    v7 = v6;
    UFG::qString::Set(&v4->mDescription, v6->mData, v6->mLength, 0i64, 0);
    v8 = v7;
  }
  else
  {
    UFG::GameStatAction::TemporaryData::Update();
    v9 = LODWORD(UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[120].mValue);
    v10 = UFG::GameStatTracker::Instance();
    v11 = UFG::SimpleTimer::GetElapsedSeconds(&v10->mpSnapshots[0]->mTimes[2].mTimer);
    UFG::qString::qString(&v21);
    v12 = UFG::UIGfxTranslator::getLocalizedTime(
            UFG::UIScreenManager::s_instance->m_translator,
            &result,
            v11 * 1000.0,
            eTS_SECONDS);
    UFG::qString::Set(&v21, v12->mData, v12->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
    v13 = UFG::UI::LocalizeText("SAVELOAD_FILE_DESC_PS3");
    UFG::qString::qString(&v20);
    UFG::qString::Format(&v20, v13, v21.mData, (unsigned int)(signed int)*(float *)&v9);
    UFG::qString::qString(&result, v20.mData);
    v15 = v14;
    UFG::qString::Set(&v4->mDescription, v14->mData, v14->mLength, 0i64, 0);
    UFG::qString::~qString(v15);
    if ( !(_S19_1 & 1) )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    v16 = UFG::ProgressionTracker::GetSaveGameName(&sProgressionTracker);
    if ( !v16 )
      v16 = (char *)UFG::UI::LocalizeText("$COMMON_UNKNOWN");
    strncpy(&Dest, v16, 0x1Fui64);
    v17 = UFG::UI::LocalizeText(&Dest);
    v18 = &Dest;
    if ( v17 )
      v18 = (char *)v17;
    UFG::qString::Set(&v4->mTitle, v18);
    UFG::qString::~qString(&v20);
    v8 = &v21;
  }
  UFG::qString::~qString(v8);
  UFG::qPrintf("Desc = %s\n", v4->mDescription.mData);
  UFG::qPrintf("Title = %s\n", v4->mTitle.mData);
}

// File Line: 894
// RVA: 0x4C7D20
void __fastcall UFG::GameSaveLoad::UpdateSaveGameTelemetry(UFG::GameSaveLoad *this, UFG::HddSaveFile *saveFile)
{
  int v2; // edi
  UFG::OSuiteDBLogger *v3; // rbx
  char *v4; // rax
  char Dest; // [rsp+28h] [rbp-B0h]
  char dest; // [rsp+50h] [rbp-88h]

  v2 = saveFile->mUserData[1];
  v3 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v3, "Save") )
  {
    if ( !(_S19_1 & 1) )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    v4 = UFG::ProgressionTracker::GetSaveGameName(&sProgressionTracker);
    if ( !v4 )
      v4 = (char *)UFG::UI::LocalizeText("$COMMON_UNKNOWN");
    strncpy(&Dest, v4, 0x1Fui64);
    UFG::qSPrintf(&dest, 128, "s_%s", "SaveName", -2i64);
    OSuite::ZMetric::SetProperty(v3->m_pMetric, &dest, &Dest);
    UFG::qSPrintf(&dest, 128, "i32_%s", "IsAutoSave");
    OSuite::ZMetric::SetProperty(v3->m_pMetric, &dest, v2 == 4);
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
  int v10; // er14
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
  int v29; // ST20_4
  int v30; // ST24_4
  int v31; // er14
  UFG::Controller *v32; // rdx
  bool v33; // si
  int v34; // ebx
  signed __int64 v35; // rdx
  __int64 i; // rcx
  bool v37; // bl
  int v38; // ebx
  int v39; // ebx
  int v40; // ebx
  int v41; // ebx
  int v42; // ebx
  int v43; // ebx
  __int64 v44; // [rsp+20h] [rbp-E0h]
  int v45; // [rsp+28h] [rbp-D8h]
  int v46; // [rsp+2Ch] [rbp-D4h]
  int v47; // [rsp+30h] [rbp-D0h]
  char dest; // [rsp+40h] [rbp-C0h]
  __int64 v49; // [rsp+C0h] [rbp-40h]
  Render::RenderOutputParams outSettings; // [rsp+D0h] [rbp-30h]
  bool v51; // [rsp+1C8h] [rbp+C8h]
  bool v52; // [rsp+1D0h] [rbp+D0h]
  int i32Value; // [rsp+1D8h] [rbp+D8h]

  v49 = -2i64;
  v1 = _S12_6;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
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
  if ( !(v1 & 1) )
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
  v47 = v4->mpSnapshots[0]->mInts[127].mValue;
  if ( !(v1 & 1) )
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
  LODWORD(v44) = v5->mpSnapshots[0]->mInts[123].mValue;
  if ( !(v1 & 1) )
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
  HIDWORD(v44) = v6->mpSnapshots[0]->mInts[124].mValue;
  if ( !(v1 & 1) )
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
  v45 = v7->mpSnapshots[0]->mInts[126].mValue;
  if ( !(v1 & 1) )
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
  v46 = v8->mpSnapshots[0]->mInts[128].mValue;
  if ( !(v1 & 1) )
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
  if ( !(v1 & 1) )
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
  v51 = v11->mpSnapshots[0]->mBools[34].mValue;
  if ( !(v1 & 1) )
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
  v52 = v12->mpSnapshots[0]->mBools[35].mValue;
  if ( !(v1 & 1) )
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
  if ( !(v1 & 1) )
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
  if ( !(v1 & 1) )
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
  if ( !(v1 & 1) )
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
  if ( !(v1 & 1) )
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
  if ( !(v1 & 1) )
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
  if ( !(v1 & 1) )
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
  if ( !(v1 & 1) )
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
    UFG::qSPrintf(&dest, 128, "i32_%s", "SFXVolume", v44);
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, i32Value);
    UFG::qSPrintf(&dest, 128, "i32_%s", "MusicVolume");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v47);
    UFG::qSPrintf(&dest, 128, "i32_%s", "DialogueVolume");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v45);
    UFG::qSPrintf(&dest, 128, "i32_%s", "CarMusicVolume");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v46);
    UFG::qSPrintf(&dest, 128, "i32_%s", "Brightness");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v29);
    UFG::qSPrintf(&dest, 128, "i32_%s", "UIScale");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v30);
    UFG::qSPrintf(&dest, 128, "i32_%s", "Subtitles");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v10);
    UFG::qSPrintf(&dest, 128, "i32_%s", "Vibration");
    v31 = 0;
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v20 == 1);
    UFG::qSPrintf(&dest, 128, "i32_%s", "HintsEnabled");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v51 == 1);
    UFG::qSPrintf(&dest, 128, "i32_%s", "ContextualHelp");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v52 == 1);
    UFG::qSPrintf(&dest, 128, "i32_%s", "EnableHUD");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v14 == 1);
    UFG::qSPrintf(&dest, 128, "i32_%s", "YAxis");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v18 == 1);
    UFG::qSPrintf(&dest, 128, "i32_%s", "XAxis");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v16 == 1);
    UFG::qSPrintf(&dest, 128, "f_%s", "AimPitch");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v26);
    UFG::qSPrintf(&dest, 128, "f_%s", "AimYaw");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v27);
    UFG::qSPrintf(&dest, 128, "f_%s", "CameraPitch");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v22);
    UFG::qSPrintf(&dest, 128, "f_%s", "CameraYaw");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v24);
    Render::RenderOutputParams::RenderOutputParams(&outSettings);
    Render::GetCurrentDisplaySettings(&outSettings);
    v32 = UFG::gInputSystem->mControllers[0];
    v33 = v32 && v32->m_IsKeyboardController;
    v34 = 0;
    if ( v33 )
    {
      v35 = (signed __int64)&v32->mRemappableActions;
      for ( i = *(_QWORD *)(v35 + 8); i != v35; i = *(_QWORD *)(i + 8) )
      {
        if ( *(_DWORD *)(i + 48) != *(_DWORD *)(i + 44) )
          ++v34;
      }
    }
    UFG::qSPrintf(&dest, 128, "i32_%s", "Control");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v33 == 1);
    UFG::qSPrintf(&dest, 128, "i32_%s", "DefaultKeyboard");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v34 == 0);
    UFG::qSPrintf(&dest, 128, "i32_%s", "KeysRemapped");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v34);
    v37 = outSettings.mEnableFullscreen;
    UFG::qSPrintf(&dest, 128, "i32_%s", "ScreenMode");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v37 == 1);
    v38 = outSettings.mDisplayMode.mBackBufferHeight;
    UFG::qSPrintf(&dest, 128, "i32_%s", "ResolutionY");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v38);
    v39 = outSettings.mDisplayMode.mBackBufferWidth;
    UFG::qSPrintf(&dest, 128, "i32_%s", "ResolutionX");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v39);
    LOBYTE(v39) = outSettings.mEnableVSync;
    UFG::qSPrintf(&dest, 128, "i32_%s", "VSync");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, (_BYTE)v39 == 1);
    v40 = outSettings.mAAQuality;
    UFG::qSPrintf(&dest, 128, "i32_%s", "QualityAA");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v40);
    v41 = outSettings.mTextureDetailLevel;
    UFG::qSPrintf(&dest, 128, "i32_%s", "TextureDetailLevel");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v41);
    v42 = outSettings.mShadowRes;
    UFG::qSPrintf(&dest, 128, "i32_%s", "HighQualityShadows");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v42);
    v43 = Render::GetGPUCount();
    UFG::qSPrintf(&dest, 128, "i32_%s", "SLI");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v43);
    LOBYTE(v43) = outSettings.mEnable3D;
    UFG::qSPrintf(&dest, 128, "i32_%s", "3D");
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, (_BYTE)v43 == 1);
    LOBYTE(v43) = outSettings.mEnableLowResBuffer;
    UFG::qSPrintf(&dest, 128, "i32_%s", "EnableLowResBuffer");
    LOBYTE(v31) = (_BYTE)v43 == 1;
    OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v31);
    UFG::OSuiteDBLogger::SubmitMetric(v28, 0);
  }
}

// File Line: 1023
// RVA: 0x491D10
char __fastcall UFG::GameSaveLoad::AbortCurrentOperation(UFG::GameSaveLoad *this)
{
  UFG::GameSaveLoad::Operation v1; // edx
  int v2; // edx

  v1 = this->mOperation;
  if ( v1 && (unsigned int)(this->mStatus - 2) <= 1 )
  {
    v2 = v1 - 2;
    if ( !v2 )
    {
      this->mStatus = 3;
      UFG::GameSaveLoad::LoadDataFinalize(this);
      return 1;
    }
    if ( v2 == 1 )
    {
      this->mStatus = 3;
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
  memset(this->m_GameSlotHeaderInfo, 0, 0x280ui64);
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xA1FC293D,
    0xFFFFFFFF);
}

// File Line: 1057
// RVA: 0x4AD5F0
char __fastcall UFG::GameSaveLoad::LoadAllHeaders(UFG::GameSaveLoad *this)
{
  UFG::GameSaveLoad::Operation v1; // eax
  UFG::GameSaveLoad *v2; // rdx
  char v3; // r8
  UFG::GameSaveLoad::tsSaveGameHeaderInfo *v4; // rcx
  signed __int64 v5; // r9
  bool v6; // cf
  bool v7; // zf
  unsigned int v8; // edx

  v1 = this->mOperation;
  v2 = this;
  if ( v1 == 1 )
    return 1;
  if ( v1 )
    return 0;
  v3 = 1;
  v4 = this->m_GameSlotHeaderInfo;
  v5 = 8i64;
  do
  {
    v6 = v4->m_State < 1u;
    v7 = v4->m_State == 1;
    ++v4;
    v3 &= !v6 && !v7;
    --v5;
  }
  while ( v5 );
  if ( v3 )
  {
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0x7F3C2DD8u,
      0xFFFFFFFF);
    v8 = -339696135;
    goto LABEL_12;
  }
  if ( v2->mStatus || !(UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) )
  {
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0x7F3C2DD8u,
      0xFFFFFFFF);
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xEBC0A5F9,
      0xFFFFFFFF);
    return 0;
  }
  v2->m_GameSlotHeaderInfo[0].m_State = 1;
  v2->m_GameSlotHeaderInfo[1].m_State = 1;
  v2->m_GameSlotHeaderInfo[2].m_State = 1;
  v2->m_GameSlotHeaderInfo[3].m_State = 1;
  v2->m_GameSlotHeaderInfo[4].m_State = 1;
  v2->m_GameSlotHeaderInfo[5].m_State = 1;
  v2->m_GameSlotHeaderInfo[6].m_State = 1;
  v2->m_GameSlotHeaderInfo[7].m_State = 1;
  v2->mOperation = 1;
  v2->mStatus = 1;
  v2->mActiveGameSlot = 0;
  UFG::GameSaveLoad::LoadHeadersStart(v2);
  v8 = 2134650328;
LABEL_12:
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    v8,
    0xFFFFFFFF);
  return 1;
}

// File Line: 1135
// RVA: 0x4AEAC0
void __fastcall UFG::GameSaveLoad::LoadHeadersStart(UFG::GameSaveLoad *this)
{
  UFG::GameSaveLoad *v1; // rbx
  UFG::allocator::free_link *v2; // rax
  UFG::qString *v3; // rax
  UFG::HddSaveFile *v4; // rax
  UFG::qString v5; // [rsp+38h] [rbp-60h]
  UFG::qString result; // [rsp+60h] [rbp-38h]

  v1 = this;
  this->mOperation = 1;
  this->mStatus = 1;
  v2 = UFG::qMalloc(0x20ui64, "HddFileContainer", 0i64);
  if ( v2 )
    UFG::HddFileContainer::HddFileContainer((UFG::HddFileContainer *)v2);
  v1->mFileContainer = (UFG::HddFileContainer *)v2;
  UFG::HDDmanager::mInstance->m_iSlotNum = v1->mActiveGameSlot;
  UFG::qString::qString(&v5);
  v3 = UFG::GameSaveLoad::GetSlotFullFilename(v1, &result, v1->mActiveGameSlot);
  UFG::qString::Set(&v5, v3->mData, v3->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  v4 = UFG::HddFileContainer::Add(v1->mFileContainer, v5.mData, 0i64, 0x34u, 0);
  v4->mUserData[0] = 1;
  v4->mUserData[1] = v1->mActiveGameSlot;
  UFG::HDDmanager::HDDLoad(UFG::HDDmanager::mInstance, v1->mFileContainer, UFG::GameSaveLoad::SaveLoadDoneCallBack);
  UFG::qString::~qString(&v5);
}

// File Line: 1169
// RVA: 0x4AE8C0
void __fastcall UFG::GameSaveLoad::LoadHeadersEnd(UFG::GameSaveLoad *this, UFG::errCode *err)
{
  UFG::GameSaveLoad *v2; // rdi
  UFG::eHDD_RETURN_CODE v3; // er14
  UFG::HddFileContainer *v4; // rax
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v5; // rbx
  char *v6; // rsi
  unsigned int file_data_size; // ebp
  __int64 v8; // r15
  UFG::GameSaveLoad::SaveGameHeaderState v9; // er8
  bool v10; // al
  UFG::HddFileContainer *v11; // rsi
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v12; // rdx
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v13; // rax

  v2 = this;
  v3 = err->eCode;
  v4 = this->mFileContainer;
  v5 = v4->FileList.mNode.mNext;
  if ( v5 != (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)&v4->FileList )
  {
    while ( 1 )
    {
      v6 = (char *)v5[7].mPrev;
      file_data_size = (unsigned int)v5[6].mNext;
      v8 = SHIDWORD(v5[7].mNext);
      if ( v3 == eHDD_RET_SUCCESS )
        break;
      switch ( v3 )
      {
        case 3:
          v6 = 0i64;
          file_data_size = 0;
          v9 = 4;
          break;
        case 4:
          goto LABEL_9;
        case 5:
          v6 = 0i64;
          file_data_size = 0;
          v9 = 2;
          break;
        default:
          v9 = 3;
          break;
      }
LABEL_11:
      UFG::GameSaveLoad::UpdateGameSlotInfo(v2, (UFG::GameSaveLoad::eGameSlotNum)v8, v9, v6, file_data_size);
      UFG::HDDmanager::mInstance->mSaveDataExists[v8] = v2->m_GameSlotHeaderInfo[v8].m_State > 1u;
      v5 = v5->mNext;
      if ( v5 == &v2->mFileContainer->FileList.mNode )
        goto LABEL_12;
    }
LABEL_9:
    v10 = UFG::GameSaveLoad::IsSaveGameValid(v2, (__int64)v5[7].mPrev, file_data_size);
    v9 = 3;
    if ( v10 )
      v9 = 5;
    goto LABEL_11;
  }
LABEL_12:
  v11 = v2->mFileContainer;
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
  v2->mFileContainer = 0i64;
  ++v2->mActiveGameSlot;
  if ( v3 == 5 )
  {
    memset(v2->m_GameSlotHeaderInfo, 0, 0x280ui64);
    v2->m_GameSlotHeaderInfo[0].m_State = 2;
    v2->m_GameSlotHeaderInfo[1].m_State = 2;
    v2->m_GameSlotHeaderInfo[2].m_State = 2;
    v2->m_GameSlotHeaderInfo[3].m_State = 2;
    v2->m_GameSlotHeaderInfo[4].m_State = 2;
    v2->m_GameSlotHeaderInfo[5].m_State = 2;
    v2->m_GameSlotHeaderInfo[6].m_State = 2;
    v2->m_GameSlotHeaderInfo[7].m_State = 2;
  }
  else if ( (signed int)v2->mActiveGameSlot < 8 )
  {
    UFG::GameSaveLoad::LoadHeadersStart(v2);
    return;
  }
  *(_QWORD *)&v2->mStatus = 0i64;
  v2->mActiveGameSlot = -1;
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xEBC0A5F9,
    0xFFFFFFFF);
}

// File Line: 1380
// RVA: 0x4B8670
void __fastcall UFG::GameSaveLoad::SaveDataStart(UFG::GameSaveLoad *this, UFG::GameSaveLoad::eGameSlotNum eSlot, UFG::GameSaveLoad::eSaveDataType eSaveType)
{
  UFG::GameSaveLoad::eSaveDataType v3; // er12
  unsigned int v4; // er13
  UFG::GameSaveLoad *v5; // r15
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm8_4
  UFG::SimObjectCharacter *v9; // rax
  float *v10; // rbx
  UFG::GameStatTracker *v11; // rax
  UFG::GameStatTracker *v12; // rax
  float v13; // xmm6_4
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
  UFG::qString *v24; // rax
  UFG::HddSaveFile *v25; // rax
  UFG::qString *v26; // rax
  UFG::qString *v27; // rax
  UFG::HddSaveFile *v28; // rax
  UFG::qString *v29; // rax
  UFG::qString *v30; // rax
  char *v31; // rsi
  UFG::GameStatTracker *v32; // rax
  int v33; // edi
  char *v34; // r14
  UFG::GameStatTracker *v35; // rax
  unsigned int v36; // ebx
  UFG::HddSaveFile *v37; // rax
  UFG::qString *v38; // rax
  UFG::qString v39; // [rsp+8h] [rbp-61h]
  int *finalSize; // [rsp+30h] [rbp-39h]
  char *ppBuffer; // [rsp+D0h] [rbp+67h]
  int iHeaderSaveSize; // [rsp+D8h] [rbp+6Fh]
  unsigned int bufferSize; // [rsp+E0h] [rbp+77h]

  v3 = eSaveType;
  v4 = eSlot;
  v5 = this;
  this->mOperation = 3;
  this->mStatus = 1;
  if ( eSaveType == 2 )
  {
    if ( !(_S19_1 & 1) )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    UFG::ProgressionTracker::UpdateGameSlicesSnapshot(&sProgressionTracker);
    UFG::ProgressionTracker::BuildSavegameSnapshot(&sProgressionTracker);
    unk_14240B98C = 1;
    v6 = UFG::qVector3::msZero.x;
    v7 = UFG::qVector3::msZero.y;
    v8 = UFG::qVector3::msZero.z;
    v9 = UFG::GetLocalPlayer();
    if ( v9 )
    {
      v10 = (float *)v9->m_pTransformNodeComponent;
      if ( v10 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v9->m_pTransformNodeComponent);
        v6 = v10[44];
        v7 = v10[45];
        v8 = v10[46];
      }
    }
    v11 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v11 + 6216) & 1) )
    {
      v11->mpSnapshots[0]->mFloats[79].mValue = v6;
      if ( !(*((_BYTE *)v11 + 6216) & 1) )
        v11->mpSnapshots[0]->mFloats[80].mValue = v7;
    }
    if ( !(*((_BYTE *)v11 + 6216) & 1) )
      v11->mpSnapshots[0]->mFloats[81].mValue = v8;
    v12 = UFG::GameStatTracker::Instance();
    v13 = UFG::SimpleTimer::GetElapsedSeconds(&v12->mSessionTimer);
    v14 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v14 + 6216) & 1) )
    {
      v15 = v14->mpSnapshots[0];
      if ( v13 > v15->mFloats[109].mValue )
        v15->mFloats[109].mValue = v13;
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
  v5->mFileContainer = v18;
  UFG::HDDmanager::mInstance->m_iSlotNum = v4;
  if ( (unsigned int)(v3 - 1) <= 1 )
  {
    v30 = UFG::GameSaveLoad::GetGameSlotFullFilename(
            v5,
            (UFG::qString *)&finalSize,
            (UFG::GameSaveLoad::eGameSlotNum)v4);
    UFG::qString::Set(&v39, v30->mData, v30->mLength, 0i64, 0);
    UFG::qString::~qString((UFG::qString *)&finalSize);
    bufferSize = 0;
    ppBuffer = 0i64;
    iHeaderSaveSize = 0;
    v31 = UFG::GameSaveLoad::SerializeHeaderData(v5, 0xFFFFFFF8, 2u, &iHeaderSaveSize);
    v32 = UFG::GameStatTracker::Instance();
    v33 = iHeaderSaveSize;
    UFG::GameStatTracker::SerializeSnapshotByFilter(v32, 0xFFFFFFF8, 2u, iHeaderSaveSize, &ppBuffer, (int *)&bufferSize);
    v34 = ppBuffer;
    UFG::qMemCopy(ppBuffer, v31, v33);
    v35 = UFG::GameStatTracker::Instance();
    v36 = bufferSize;
    UFG::GameStatTracker::Scramble(v35, *((_QWORD *)v34 + 1), v33, v34, bufferSize);
    operator delete[](v31);
    v39.mStringHash32 = 0;
    v37 = UFG::HddFileContainer::Add(v5->mFileContainer, v39.mData, v34, v36, 0);
    v37->mUserData[0] = v3;
    v37->mUserData[1] = v4;
    UFG::GameSaveLoad::SetFileInfo(v5, v37, v3, (UFG::GameSaveLoad::eGameSlotNum)v4);
    operator delete[](v34);
    if ( v4 == 4 )
      v38 = UFG::GameSaveLoad::GetGameSlotFullFilename(v5, (UFG::qString *)&finalSize, GAMESLOT_AUTOSAVE);
    else
      v38 = UFG::GameSaveLoad::GetGameSlotFullFilename(
              v5,
              (UFG::qString *)&finalSize,
              (UFG::GameSaveLoad::eGameSlotNum)v4);
    UFG::qString::Set(&v5->mActiveFolderDisplayNamePS, v38->mData, v38->mLength, 0i64, 0);
    goto LABEL_28;
  }
  if ( v3 == 3 )
  {
    bufferSize = 0;
    ppBuffer = 0i64;
    iHeaderSaveSize = 0;
    v19 = UFG::GameSaveLoad::SerializeHeaderData(v5, 4u, 2u, &iHeaderSaveSize);
    v20 = UFG::GameStatTracker::Instance();
    v21 = iHeaderSaveSize;
    UFG::GameStatTracker::SerializeSnapshotByFilter(v20, 4u, 2u, iHeaderSaveSize, &ppBuffer, (int *)&bufferSize);
    v22 = ppBuffer;
    UFG::qMemCopy(ppBuffer, v19, v21);
    v23 = UFG::GameStatTracker::Instance();
    LODWORD(v19) = bufferSize;
    UFG::GameStatTracker::Scramble(v23, *((_QWORD *)v22 + 1), v21, v22, bufferSize);
    v24 = UFG::GameSaveLoad::GetGameOptionsFullFilename(v5, (UFG::qString *)&finalSize);
    UFG::qString::Set(&v39, v24->mData, v24->mLength, 0i64, 0);
    UFG::qString::~qString((UFG::qString *)&finalSize);
    v39.mStringHash32 = 0;
    v25 = UFG::HddFileContainer::Add(v5->mFileContainer, v39.mData, v22, (unsigned int)v19, 0);
    v25->mUserData[0] = 3;
    v25->mUserData[1] = v4;
    UFG::GameSaveLoad::SetFileInfo(v5, v25, DATATYPE_OPTIONS, GAMESLOT_INVALID);
    operator delete[](v22);
    v26 = UFG::GameSaveLoad::GetGameOptionsFullFilename(v5, (UFG::qString *)&finalSize);
    UFG::qString::operator=(&v5->mActiveFolderDisplayNamePS, v26);
LABEL_28:
    UFG::qString::~qString((UFG::qString *)&finalSize);
    goto LABEL_29;
  }
  if ( v3 == 4 )
  {
    v27 = UFG::GameSaveLoad::GetPhotoFullFilename(v5, (UFG::qString *)&finalSize, v5->m_iCurrentPhotoNum);
    UFG::qString::Set(&v39, v27->mData, v27->mLength, 0i64, 0);
    UFG::qString::~qString((UFG::qString *)&finalSize);
    v39.mStringHash32 = 0;
    v28 = UFG::HddFileContainer::Add(v5->mFileContainer, v39.mData, v5->m_pCurrentPhoto, v5->m_iCurrentPhotoSize, 0);
    v28->mUserData[0] = 4;
    v28->mUserData[1] = v4;
    UFG::GameSaveLoad::SetFileInfo(v5, v28, DATATYPE_PHOTO, GAMESLOT_INVALID);
    v29 = UFG::GameSaveLoad::GetPhotoFullFilename(v5, (UFG::qString *)&finalSize, v4 - 5);
    UFG::qString::operator=(&v5->mActiveFolderDisplayNamePS, v29);
    goto LABEL_28;
  }
LABEL_29:
  v5->mActiveGameSlot = v4;
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xC3BE4B7B,
    0xFFFFFFFF);
  UFG::GameSaveLoad::SaveDataRetry(v5);
  UFG::qString::~qString(&v39);
}

// File Line: 1560
// RVA: 0x4B85E0
void __fastcall UFG::GameSaveLoad::SaveDataRetry(UFG::GameSaveLoad *this)
{
  UFG::GameSaveLoad *v1; // rbx
  UFG::qString *v2; // rax
  UFG::qString v3; // [rsp+38h] [rbp-30h]

  v1 = this;
  this->mStatus = 1;
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_SAVELOAD_START_SAVING_4,
    0xFFFFFFFF);
  UFG::qString::qString(&v3, &v1->mActiveFolderDisplayNamePS);
  UFG::HDDmanager::HDDSave(
    UFG::HDDmanager::mInstance,
    v1->mFileContainer,
    UFG::GameSaveLoad::SaveLoadDoneCallBack,
    v2,
    v1->m_GameSlotHeaderInfo[v1->mActiveGameSlot].m_State == 3);
}

// File Line: 1575
// RVA: 0x4B82A0
void __fastcall UFG::GameSaveLoad::SaveDataEnd(UFG::GameSaveLoad *this, UFG::errCode *err)
{
  UFG::GameSaveLoad *v2; // rbx
  UFG::eHDD_RETURN_CODE v3; // er15
  UFG::HddFileContainer *v4; // rax
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v5; // rdi
  int v6; // ebp
  UFG::GameSaveLoad::eGameSlotNum v7; // esi
  UFG::qString *v8; // rax
  bool v9; // r14
  signed int file_data_size; // [rsp+20h] [rbp-58h]
  UFG::qString result; // [rsp+38h] [rbp-40h]

  v2 = this;
  v3 = err->eCode;
  if ( UFG::gFakeSaveFailure )
  {
    v3 = 2;
    UFG::gFakeInsufficientSpace = 0;
  }
  else if ( UFG::gFakeInsufficientSpace )
  {
    v3 = 1;
  }
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_SAVELOAD_STOP_SAVING_4,
    0xFFFFFFFF);
  v4 = v2->mFileContainer;
  v5 = v4->FileList.mNode.mNext;
  if ( v5 != (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)&v4->FileList )
  {
    do
    {
      UFG::qPrintf("File Name '%s', File Size = %d \n", v5[3].mPrev, LODWORD(v5[6].mNext));
      v6 = (int)v5[7].mNext;
      v7 = HIDWORD(v5[7].mNext);
      v8 = UFG::GameSaveLoad::GetSlotFullFilename(v2, &result, (UFG::GameSaveLoad::eGameSlotNum)HIDWORD(v5[7].mNext));
      v9 = (unsigned int)UFG::qStringCompare((const char *)v5[3].mPrev, v8->mData, -1) == 0;
      UFG::qString::~qString(&result);
      if ( v3 )
      {
        if ( v3 == 1 )
        {
          UFG::UIScreenManagerBase::queueMessage(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            UI_HASH_NO_SPACE_FOR_SAVE_4,
            0xFFFFFFFF);
        }
        else if ( v3 == 2 )
        {
          UFG::GameSaveLoad::UpdateGameSlotInfo(v2, v7, SAVE_GAME_HEADER_STATE_CORRUPT, 0i64, 0);
          UFG::UIScreenManagerBase::queueMessage(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            UI_HASH_CORRUPT_SAVE_SLOT_4,
            0xFFFFFFFF);
        }
        else
        {
          UFG::GameSaveLoad::UpdateGameSlotInfo(v2, v7, SAVE_GAME_HEADER_STATE_INVALID_DEVICE, 0i64, 0);
          UFG::UIScreenManagerBase::queueMessage(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            UI_HASH_SAVE_OPERATION_INVALID_DEVICE_4,
            0xFFFFFFFF);
        }
        goto LABEL_21;
      }
      if ( (unsigned int)(v6 - 1) <= 1 )
      {
        UFG::GameSaveLoad::UpdateSaveGameTelemetry(v2, (UFG::HddSaveFile *)v5);
        if ( v9 )
        {
          file_data_size = (signed int)v5[6].mNext;
          goto LABEL_20;
        }
      }
      else
      {
        if ( v6 != 3 )
        {
          if ( v6 == 4 )
          {
            v2->m_bPhotoExists[v2->m_iCurrentPhotoNum] = 1;
            UFG::GameSaveLoad::UpdateGameSlotInfo(v2, v7, SAVE_GAME_HEADER_STATE_VALID, 0i64, 0);
          }
          goto LABEL_21;
        }
        if ( v9 )
        {
          file_data_size = 52;
LABEL_20:
          UFG::GameSaveLoad::UpdateGameSlotInfo(
            v2,
            v7,
            SAVE_GAME_HEADER_STATE_VALID,
            (char *)v5[7].mPrev,
            file_data_size);
          goto LABEL_21;
        }
      }
LABEL_21:
      v5 = v5->mNext;
    }
    while ( v5 != &v2->mFileContainer->FileList.mNode );
  }
  if ( v3 == eHDD_RET_SUCCESS )
    UFG::GameSaveLoad::SaveDataFinalize(v2);
}

// File Line: 1704
// RVA: 0x4B84B0
void __fastcall UFG::GameSaveLoad::SaveDataFinalize(UFG::GameSaveLoad *this)
{
  UFG::GameSaveLoad *v1; // rdi
  UFG::GameSaveLoad::Status v2; // eax
  bool v3; // bp
  bool v4; // r14
  UFG::HddFileContainer *v5; // rsi
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v6; // rdx
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v7; // rax
  unsigned int v8; // edx

  v1 = this;
  v2 = this->mStatus;
  v3 = v2 == 2 && this->mActiveGameSlot != 5;
  v4 = v2 == 2;
  UFG::HddFileContainer::EmptyContainer(this->mFileContainer);
  v5 = v1->mFileContainer;
  if ( v5 )
  {
    UFG::qList<UFG::HddSaveFile,UFG::HddSaveFile,1,0>::DeleteNodes(&v5->FileList);
    v6 = v5->FileList.mNode.mPrev;
    v7 = v5->FileList.mNode.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->FileList.mNode.mPrev = &v5->FileList.mNode;
    v5->FileList.mNode.mNext = &v5->FileList.mNode;
    operator delete[](v5);
  }
  v1->mFileContainer = 0i64;
  UFG::qString::Set(&v1->mActiveFolderDisplayNamePS, 0i64);
  v1->mActiveGameSlot = -1;
  *(_QWORD *)&v1->mStatus = 0i64;
  if ( v3 == 1 && (UFG::HDDmanager::mInstance->m_eSaveLoadPermission >> 1) & 1 )
  {
    UFG::GameSaveLoad::SaveDataStart(v1, NUM_GAMESAVES, DATATYPE_OPTIONS);
  }
  else
  {
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xF601FBC2,
      0xFFFFFFFF);
    v8 = 2006712458;
    if ( v4 )
      v8 = -663456200;
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      v8,
      0xFFFFFFFF);
  }
}

// File Line: 1806
// RVA: 0x4ADC20
void __fastcall UFG::GameSaveLoad::LoadDataStart(UFG::GameSaveLoad *this, UFG::GameSaveLoad::eGameSlotNum eSlot, UFG::GameSaveLoad::eSaveDataType eSaveType)
{
  UFG::GameSaveLoad::eSaveDataType v3; // edi
  __int64 v4; // rsi
  UFG::GameSaveLoad *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::HddFileContainer *v7; // rax
  UFG::qString *v8; // rax
  UFG::HddSaveFile *v9; // rax
  UFG::OSuiteDBLogger *v10; // rdi
  UFG::qString *v11; // rax
  UFG::HddSaveFile *v12; // rax
  UFG::qString *v13; // rax
  UFG::qString v14; // [rsp+30h] [rbp-E8h]
  UFG::qString result; // [rsp+58h] [rbp-C0h]
  __int64 v16; // [rsp+80h] [rbp-98h]
  char dest; // [rsp+90h] [rbp-88h]

  v16 = -2i64;
  v3 = eSaveType;
  v4 = (signed int)eSlot;
  v5 = this;
  UFG::qString::qString(&v14);
  UFG::HDDmanager::mInstance->m_iSlotNum = v4;
  v6 = UFG::qMalloc(0x20ui64, "User Pro Container", 0i64);
  if ( v6 )
    UFG::HddFileContainer::HddFileContainer((UFG::HddFileContainer *)v6);
  else
    v7 = 0i64;
  v5->mFileContainer = v7;
  if ( v3 != 1 )
  {
    if ( v3 != 2 )
    {
      if ( v3 == 3 )
      {
        v11 = UFG::GameSaveLoad::GetGameOptionsFullFilename(v5, &result);
        UFG::qString::Set(&v14, v11->mData, v11->mLength, 0i64, 0);
        UFG::qString::~qString(&result);
        v12 = UFG::HddFileContainer::Add(v5->mFileContainer, v14.mData, 0i64, 0x19000u, 0);
        v12->mAdjustFileSize = 1;
        v12->mUserData[0] = 3;
      }
      else
      {
        if ( v3 != 4 )
          goto LABEL_16;
        v13 = UFG::GameSaveLoad::GetPhotoFullFilename(v5, &result, UFG::HDDmanager::mInstance->m_iSlotNum - 6);
        UFG::qString::Set(&v14, v13->mData, v13->mLength, 0i64, 0);
        UFG::qString::~qString(&result);
        v12 = UFG::HddFileContainer::Add(v5->mFileContainer, v14.mData, 0i64, 0x186A0u, 0);
        v12->mAdjustFileSize = 1;
        v12->mUserData[0] = 4;
      }
      v12->mUserData[1] = v4;
      goto LABEL_16;
    }
    v8 = UFG::GameSaveLoad::GetGameSlotFullFilename(v5, &result, (UFG::GameSaveLoad::eGameSlotNum)v4);
    UFG::qString::Set(&v14, v8->mData, v8->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
    v9 = UFG::HddFileContainer::Add(
           v5->mFileContainer,
           v14.mData,
           0i64,
           v5->m_GameSlotHeaderInfo[v4].m_iGameDataSize,
           0);
    v9->mUserData[0] = 2;
    v9->mUserData[1] = v4;
    v10 = UFG::OSuiteDBLogger::Instance();
    if ( UFG::OSuiteDBLogger::CreateMetric(v10, "SaveGameLoaded") )
    {
      UFG::qSPrintf(&dest, 128, "s_%s", "SaveName");
      OSuite::ZMetric::SetProperty(v10->m_pMetric, &dest, "Gameloaded");
      if ( v5->m_FirstLoad )
      {
        UFG::qSPrintf(&dest, 128, "i32_%s", "SessionFirstLoad");
        OSuite::ZMetric::SetProperty(v10->m_pMetric, &dest, 1);
        v5->m_FirstLoad = 0;
      }
      else
      {
        UFG::qSPrintf(&dest, 128, "i32_%s", "SessionFirstLoad");
        OSuite::ZMetric::SetProperty(v10->m_pMetric, &dest, 0);
      }
      UFG::OSuiteDBLogger::SubmitMetric(v10, 0);
    }
  }
LABEL_16:
  v5->mOperation = 2;
  v5->mStatus = 1;
  v5->mActiveGameSlot = v4;
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xBA6593AF,
    0xFFFFFFFF);
  UFG::HDDmanager::HDDLoad(UFG::HDDmanager::mInstance, v5->mFileContainer, UFG::GameSaveLoad::SaveLoadDoneCallBack);
  UFG::qString::~qString(&v14);
}

// File Line: 1895
// RVA: 0x4AD730
void __fastcall UFG::GameSaveLoad::LoadDataEnd(UFG::GameSaveLoad *this, UFG::errCode *err)
{
  UFG::GameSaveLoad *v2; // rbx
  UFG::eHDD_RETURN_CODE v3; // er12
  char v4; // bp
  UFG::HddFileContainer *v5; // rax
  UFG::HddSaveFile *v6; // r14
  void *v7; // rsi
  unsigned int bufferSize; // er15
  int v9; // eax
  signed __int64 v10; // rdi
  signed __int64 v11; // rcx
  UFG::GameStatTracker *v12; // rax
  bool v13; // r13
  UFG::GameStatTracker *v14; // rax
  UFG::ProgressionTracker *v15; // rax
  unsigned int v16; // edx
  signed __int64 v17; // rcx
  UFG::GameStatTracker *v18; // rax
  UFG::GameStatTracker *v19; // rax
  UFG::allocator::free_link *v20; // r15
  UFG::allocator::free_link *v21; // rax
  unsigned int v22; // edx
  UFG::allocator::free_link *v23; // rcx

  v2 = this;
  v3 = err->eCode;
  v4 = 0;
  v5 = this->mFileContainer;
  v6 = (UFG::HddSaveFile *)v5->FileList.mNode.mNext;
  if ( v6 == (UFG::HddSaveFile *)&v5->FileList )
  {
LABEL_36:
    UFG::GameSaveLoad::LoadDataFinalize(v2);
    return;
  }
  do
  {
    UFG::qPrintf("File Name '%s', File Size = %d \n", v6->mFileName.mData, v6->mFileSize);
    v7 = v6->mData;
    bufferSize = v6->mFileSize;
    v9 = v6->mUserData[0];
    v10 = v6->mUserData[1];
    switch ( v9 )
    {
      case 1:
        break;
      case 2:
        if ( v3 )
        {
          v4 = 1;
          v11 = v10;
          if ( v3 == 5 )
          {
            v2->m_GameSlotHeaderInfo[v10].m_State = 2;
            UFG::UIScreenManagerBase::queueMessage(
              (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
              UI_HASH_LOAD_OPERATION_INVALID_DEVICE_4,
              0xFFFFFFFF);
            break;
          }
          goto LABEL_15;
        }
        if ( !UFG::GameSaveLoad::IsSaveGameValid(v2, (__int64)v6->mData, bufferSize) )
        {
          v11 = v10;
          v4 = 1;
LABEL_15:
          v2->m_GameSlotHeaderInfo[v11].m_State = 3;
          v16 = UI_HASH_CORRUPT_SAVE_SLOT_4;
LABEL_16:
          UFG::UIScreenManagerBase::queueMessage(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            v16,
            0xFFFFFFFF);
          break;
        }
        v12 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::Reset(v12, 0);
        v13 = (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_9;
        v14 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::Descramble(v14, *((_QWORD *)v7 + 1), 0x34u, (char *)v7, bufferSize);
        if ( !(_S19_1 & 1) )
        {
          _S19_1 |= 1u;
          UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
          atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
        }
        UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
        if ( UFG::ProgressionTracker::LoadedProgression(&sProgressionTracker, 0x34, (char *)v7, bufferSize, v13) )
        {
          v15 = UFG::ProgressionTracker::Instance();
          UFG::ProgressionTracker::UpdateCompletionPercentage(v15);
        }
        else
        {
          v2->m_GameSlotHeaderInfo[v10].m_State = 3;
          v4 = 1;
          UFG::UIScreenManagerBase::queueMessage(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            UI_HASH_CORRUPT_SAVE_SLOT_4,
            0xFFFFFFFF);
        }
        break;
      case 3:
        if ( v3 )
        {
          v17 = v10;
          if ( v3 == 3 )
          {
            v2->m_GameSlotHeaderInfo[v10].m_State = 4;
            break;
          }
          v4 = 1;
          if ( v3 == 5 )
          {
            v2->m_GameSlotHeaderInfo[v10].m_State = 2;
            v16 = UI_HASH_LOAD_OPERATION_INVALID_DEVICE_4;
            goto LABEL_16;
          }
        }
        else
        {
          if ( (unsigned int)UFG::GameSaveLoad::CheckVersion(v2, v6->mData, 0x60001u) )
          {
            v18 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::Descramble(v18, *((_QWORD *)v7 + 1), 0x34u, (char *)v7, bufferSize);
            v19 = UFG::GameStatTracker::Instance();
            if ( UFG::GameSnapshot::DeserializeByFilter(v19->mpSnapshots[0], 4u, 2u, (char *)v7 + 52) )
            {
              UFG::GameSaveLoad::ApplyOptions(v2);
              break;
            }
          }
          v17 = v10;
          v4 = 1;
        }
        v2->m_GameSlotHeaderInfo[v17].m_State = 3;
        UFG::UIScreenManagerBase::queueMessage(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          UI_HASH_CORRUPT_GAME_OPTIONS_4,
          0xFFFFFFFF);
        break;
      case 4:
        if ( v3 )
        {
          UFG::UIScreenManagerBase::queueMessage(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            UI_HASH_CORRUPT_PHOTO_4,
            0xFFFFFFFF);
        }
        else
        {
          v20 = UFG::qMalloc(v6->mFileSize, "Photo", 0i64);
          UFG::qMemCopy(v20, v7, v6->mFileSize);
          v21 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x50ui64, "GameSaveLoad", 0i64, 1u);
          if ( v21 )
          {
            v22 = v6->mFileSize;
            v23 = v21 + 1;
            v23->mNext = v23;
            v23[1].mNext = v23;
            v21->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable';
            LODWORD(v21[3].mNext) = -1;
            v21[4].mNext = 0i64;
            v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable';
            v21[5].mNext = (UFG::allocator::free_link *)UI_HASH_PHOTO_LOADED_14;
            v21[6].mNext = (UFG::allocator::free_link *)-1i64;
            LODWORD(v21[3].mNext) = 5;
            v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessageSaveLoad::`vftable';
            LODWORD(v21[7].mNext) = v10 - 6;
            v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePhotoLoaded::`vftable';
            v21[8].mNext = v20;
            LODWORD(v21[9].mNext) = v22;
          }
          UFG::UIScreenManagerBase::queueMessageEx(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            (UFG::UIMessage *)v21);
        }
        break;
    }
    v6 = (UFG::HddSaveFile *)v6->mNext;
  }
  while ( v6 != (UFG::HddSaveFile *)&v2->mFileContainer->FileList );
  if ( !v4 )
    goto LABEL_36;
}

// File Line: 2145
// RVA: 0x4ADB30
void __fastcall UFG::GameSaveLoad::LoadDataFinalize(UFG::GameSaveLoad *this)
{
  UFG::GameSaveLoad *v1; // rdi
  bool v2; // bp
  UFG::HddFileContainer *v3; // rsi
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v4; // rdx
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v5; // rax
  unsigned int v6; // edx

  v1 = this;
  v2 = this->mStatus == 2;
  UFG::HddFileContainer::EmptyContainer(this->mFileContainer);
  v3 = v1->mFileContainer;
  if ( v3 )
  {
    UFG::qList<UFG::HddSaveFile,UFG::HddSaveFile,1,0>::DeleteNodes(&v3->FileList);
    v4 = v3->FileList.mNode.mPrev;
    v5 = v3->FileList.mNode.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->FileList.mNode.mPrev = &v3->FileList.mNode;
    v3->FileList.mNode.mNext = &v3->FileList.mNode;
    operator delete[](v3);
  }
  v1->mFileContainer = 0i64;
  UFG::qString::Set(&v1->mActiveFolderDisplayNamePS, 0i64);
  v1->mActiveGameSlot = -1;
  *(_QWORD *)&v1->mStatus = 0i64;
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xAB317A37,
    0xFFFFFFFF);
  v6 = 1323471633;
  if ( v2 )
    v6 = 1552074461;
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    v6,
    0xFFFFFFFF);
}

// File Line: 2181
// RVA: 0x49A7F0
void __fastcall UFG::GameSaveLoad::DeleteDataStart(UFG::GameSaveLoad *this, UFG::GameSaveLoad::eGameSlotNum eSlot, UFG::GameSaveLoad::eSaveDataType eSaveType)
{
  UFG::GameSaveLoad::eSaveDataType v3; // edi
  unsigned int v4; // esi
  UFG::GameSaveLoad *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::HddFileContainer *v7; // rax
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  UFG::qString *v10; // rax
  UFG::HddSaveFile *v11; // rax
  UFG::qString v12; // [rsp+38h] [rbp-60h]
  UFG::qString result; // [rsp+60h] [rbp-38h]

  v3 = eSaveType;
  v4 = eSlot;
  v5 = this;
  UFG::qString::qString(&v12);
  UFG::HDDmanager::mInstance->m_iSlotNum = v4;
  v6 = UFG::qMalloc(0x20ui64, "User Pro Container", 0i64);
  if ( v6 )
    UFG::HddFileContainer::HddFileContainer((UFG::HddFileContainer *)v6);
  else
    v7 = 0i64;
  v5->mFileContainer = v7;
  if ( (unsigned int)(v3 - 1) <= 1 )
  {
    v10 = UFG::GameSaveLoad::GetGameSlotFullFilename(v5, &result, (UFG::GameSaveLoad::eGameSlotNum)v4);
    UFG::qString::Set(&v12, v10->mData, v10->mLength, 0i64, 0);
  }
  else if ( v3 == 3 )
  {
    v8 = UFG::GameSaveLoad::GetGameOptionsFullFilename(v5, &result);
    UFG::qString::Set(&v12, v8->mData, v8->mLength, 0i64, 0);
  }
  else
  {
    if ( v3 != 4 )
      goto LABEL_12;
    v9 = UFG::GameSaveLoad::GetPhotoFullFilename(v5, &result, v5->m_iCurrentPhotoNum);
    UFG::qString::Set(&v12, v9->mData, v9->mLength, 0i64, 0);
  }
  UFG::qString::~qString(&result);
  v11 = UFG::HddFileContainer::Add(v5->mFileContainer, v12.mData, 0i64, 0, 0);
  if ( v11 )
  {
    v11->mUserData[0] = v3;
    v11->mUserData[1] = v4;
  }
LABEL_12:
  v5->mStatus = 1;
  v5->mOperation = 4;
  UFG::HDDmanager::HDDDelete(UFG::HDDmanager::mInstance, v5->mFileContainer, UFG::GameSaveLoad::SaveLoadDoneCallBack);
  UFG::qString::~qString(&v12);
}

// File Line: 2237
// RVA: 0x49A620
void __fastcall UFG::GameSaveLoad::DeleteDataEnd(UFG::GameSaveLoad *this, UFG::errCode *err)
{
  UFG::GameSaveLoad *v2; // rdi
  UFG::HddFileContainer *v3; // rax
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v4; // rbx
  __int64 v5; // rbp
  int v6; // esi
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rcx
  signed __int64 v9; // rcx
  UFG::HddFileContainer *v10; // rsi
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v11; // rdx
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v12; // rax

  v2 = this;
  v3 = this->mFileContainer;
  v4 = v3->FileList.mNode.mNext;
  v5 = err->eCode;
  if ( v4 != (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)&v3->FileList )
  {
    do
    {
      UFG::qPrintf("DeleteDataEnd: File Name '%s', (Slot) %d \n", v4[3].mPrev, HIDWORD(v4[7].mNext));
      if ( !v5 && LODWORD(v4[7].mNext) == 4 )
      {
        v6 = HIDWORD(v4[7].mNext);
        v7 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "GameSaveLoad", 0i64, 1u);
        if ( v7 )
        {
          v8 = v7 + 1;
          v8->mNext = v8;
          v8[1].mNext = v8;
          v7->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable';
          LODWORD(v7[3].mNext) = -1;
          v7[4].mNext = 0i64;
          v7->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable';
          LODWORD(v7[5].mNext) = UI_HASH_PHOTO_DELETED_14;
          HIDWORD(v7[5].mNext) = 0;
          v7[6].mNext = (UFG::allocator::free_link *)-1i64;
          LODWORD(v7[3].mNext) = 5;
          v7->mNext = (UFG::allocator::free_link *)&UFG::UIMessageSaveLoad::`vftable';
          LODWORD(v7[7].mNext) = v6 - 6;
        }
        else
        {
          v7 = 0i64;
        }
        UFG::UIScreenManagerBase::queueMessageEx(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          (UFG::UIMessage *)v7);
      }
      v9 = SHIDWORD(v4[7].mNext);
      *(_QWORD *)&v2->m_GameSlotHeaderInfo[v9].m_State = 4i64;
      v2->m_GameSlotHeaderInfo[v9].m_iTimeDateStamp = 0i64;
      v4 = v4->mNext;
    }
    while ( v4 != &v2->mFileContainer->FileList.mNode );
  }
  UFG::HddFileContainer::EmptyContainer(v2->mFileContainer);
  v10 = v2->mFileContainer;
  if ( v10 )
  {
    UFG::qList<UFG::HddSaveFile,UFG::HddSaveFile,1,0>::DeleteNodes(&v10->FileList);
    v11 = v10->FileList.mNode.mPrev;
    v12 = v10->FileList.mNode.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->FileList.mNode.mPrev = &v10->FileList.mNode;
    v10->FileList.mNode.mNext = &v10->FileList.mNode;
    operator delete[](v10);
  }
  v2->mFileContainer = 0i64;
  *(_QWORD *)&v2->mStatus = 0i64;
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_DELETE_GAME_COMPLETE_14,
    0xFFFFFFFF);
}

// File Line: 2288
// RVA: 0x4C7750
void __fastcall UFG::GameSaveLoad::UpdateGameSlotInfo(UFG::GameSaveLoad *this, UFG::GameSaveLoad::eGameSlotNum eSlotNum, UFG::GameSaveLoad::SaveGameHeaderState state, char *file_data, unsigned int file_data_size)
{
  UFG::GameSaveLoad::SaveGameHeaderState v5; // esi
  __int64 v6; // rbp
  char *v7; // rbx
  UFG::GameSaveLoad *v8; // rdi
  bool v9; // al
  char *v10; // rcx
  signed __int64 v11; // rbx

  v5 = state;
  v6 = (signed int)eSlotNum;
  v7 = file_data;
  v8 = this;
  v9 = UFG::GameSaveLoad::IsSaveGameValid(this, (__int64)file_data, file_data_size);
  v10 = 0i64;
  if ( v9 )
    v10 = v7;
  v11 = (signed __int64)v8 + 80 * v6;
  *(_DWORD *)(v11 + 96) = v5;
  if ( v10 )
  {
    *(_DWORD *)(v11 + 100) = *((_DWORD *)v10 + 12);
    *(_QWORD *)(v11 + 104) = *((_QWORD *)v10 + 1);
    UFG::qMemCopy((void *)(v11 + 112), v10 + 16, 0x40u);
  }
  else
  {
    *(_DWORD *)(v11 + 100) = 0;
    *(_QWORD *)(v11 + 104) = 0i64;
    *(_BYTE *)(v11 + 112) = 0;
  }
  UFG::qPrintf(
    "[GameSaveLoad] Slot %d  State=%d  Size=%d  TimeStamp=0x%016x64  Mission='%s'\n",
    (unsigned int)v6,
    *(unsigned int *)(v11 + 96),
    *(unsigned int *)(v11 + 100),
    *(_QWORD *)(v11 + 104),
    v11 + 112);
}

// File Line: 2334
// RVA: 0x4ACD10
bool __fastcall UFG::GameSaveLoad::IsSaveGameValid(UFG::GameSaveLoad *this, __int64 file_data, unsigned int file_data_size)
{
  unsigned int bufferSize; // ebx
  __int64 v4; // rdi
  bool v5; // cl
  UFG::GameStatTracker *v6; // rax

  bufferSize = file_data_size;
  v4 = file_data;
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
        v5 = UFG::GameStatTracker::IsValidBuffer(v6, *(_QWORD *)(v4 + 8), 52u, (char *)v4, bufferSize);
      }
    }
  }
  return v5;
}

// File Line: 2424
// RVA: 0x496C70
signed __int64 __fastcall UFG::GameSaveLoad::CheckVersion(UFG::GameSaveLoad *this, void *data, unsigned int version)
{
  unsigned int v3; // edi
  char *v4; // rbx
  signed __int64 result; // rax
  int dest; // [rsp+48h] [rbp+20h]

  v3 = version;
  v4 = (char *)data;
  dest = 0;
  if ( (unsigned int)UFG::qStringCompare("TC01", (const char *)data, 4) )
    return 0i64;
  UFG::qMemCopy(&dest, v4 + 4, 4u);
  result = 8i64;
  if ( (v3 ^ dest) & 0xFFFF0000 )
    result = 0i64;
  return result;
}

// File Line: 2503
// RVA: 0x4BB4D0
UFG::allocator::free_link *__fastcall UFG::GameSaveLoad::SerializeHeaderData(UFG::GameSaveLoad *this, unsigned int filterMask, unsigned int persistenceMask, int *iHeaderSaveSize)
{
  int *v4; // rsi
  char *v5; // rax
  UFG::allocator::free_link *v6; // rdi
  UFG::GameStatTracker *v7; // rbx
  _FILETIME source; // [rsp+20h] [rbp-38h]
  __int64 v10; // [rsp+28h] [rbp-30h]
  char dest; // [rsp+30h] [rbp-28h]
  int v12; // [rsp+78h] [rbp+20h]

  v10 = -2i64;
  v4 = iHeaderSaveSize;
  UFG::qMemSet(&dest, 0, 0x20u);
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v5 = UFG::ProgressionTracker::GetSaveGameName(&sProgressionTracker);
  if ( !v5 )
    v5 = (char *)UFG::UI::LocalizeText("$COMMON_UNKNOWN");
  strncpy(&dest, v5, 0x1Fui64);
  *v4 = 52;
  v6 = UFG::qMalloc(0x34ui64, "char", 0i64);
  source = UFG::qGetSystemTime();
  UFG::qMemCopy(v6, "TC01", 4u);
  UFG::qMemCopy((char *)&v6->mNext + 4, &SAVEGAME_VERSION_NUMBER, 4u);
  UFG::qMemCopy(&v6[1], &source, 8u);
  UFG::qMemCopy(&v6[2], &dest, 0x20u);
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
  v12 = *v4 + (unsigned __int64)UFG::GameSnapshot::CalculateSerializeSize(v7->mpSnapshots[4], 0xFFFFFFF8, 2u);
  UFG::qMemCopy(&v6[6], &v12, 4u);
  return v6;
}

// File Line: 2562
// RVA: 0x4946E0
void __fastcall UFG::GameSaveLoad::ApplyOptions(UFG::GameSaveLoad *this)
{
  UFG::GameSaveLoad *v1; // rsi
  UFG::GameStatTracker *v2; // rdi
  UFG::GameStatTracker *v3; // rcx
  UFG::TiDo *v4; // rbx
  float v5; // xmm6_4
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

  v1 = this;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
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
  v5 = (float)v3->mpSnapshots[0]->mInts[125].mValue;
  v6 = UFG::TiDo::CalcWwiseUid("master_sfx_volume");
  UFG::TiDo::SetWwiseRtpcValue(v4, v6, v5, 0xFFFFFFFFFFFFFFFFui64);
  if ( !(_S12_6 & 1) )
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
  if ( !(_S12_6 & 1) )
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
  if ( !(_S12_6 & 1) )
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
  UFG::GameSaveLoad::ApplyRumble(v1);
  if ( !(_S12_6 & 1) )
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
  if ( !(_S12_6 & 1) )
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
  if ( !(_S12_6 & 1) )
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
  if ( !(v21 & 1) )
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
  UFG::InputSystem::msPCKeyboardSwapMode = UFG::GameSaveLoad::GetKeyboardSwapMode(v1);
  v24 = _S12_6;
  if ( !(_S12_6 & 1) )
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
  if ( !(v24 & 1) )
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
  int v4; // ecx
  int v5; // ecx
  bool v6; // dl

  v1 = _S12_6;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
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
    goto LABEL_19;
  if ( !(v1 & 1) )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v3 = UFG::GameStatTracker::mspInstance;
  }
  if ( v3 )
    v2 = v3;
  UFG::GameStatTracker::mspInstance = v2;
  v4 = v2->mpSnapshots[0]->mInts[133].mValue;
  v5 = v4 <= 0 ? (unsigned __int8)UFG::GameStatTracker::Instance()->mpSnapshots[0]->mBools[45].mValue : v4 - 1;
  if ( v5 != 2 )
    v6 = 1;
  else
LABEL_19:
    v6 = 0;
  UFG::TiDo::SetRumbleEnabled(UFG::TiDo::m_pInstance, v6);
}

// File Line: 2606
// RVA: 0x4A43F0
__int64 __fastcall UFG::GameSaveLoad::GetKeyboardSwapMode(UFG::GameSaveLoad *this)
{
  UFG::GameStatTracker *v1; // rbx
  int v2; // eax
  __int64 result; // rax

  v1 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v1 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v1;
  v2 = v1->mpSnapshots[0]->mInts[133].mValue;
  if ( v2 <= 0 )
    result = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mBools[45].mValue;
  else
    result = (unsigned int)(v2 - 1);
  return result;
}

// File Line: 2620
// RVA: 0x4ACA20
_BOOL8 __fastcall UFG::GameSaveLoad::IsLaunchHeader(UFG::GameSaveLoad *this, UFG::GameSaveLoad::tsSaveGameHeaderInfo *header)
{
  bool v2; // bl
  UFG::qString v4; // [rsp+28h] [rbp-30h]

  UFG::qString::qString(&v4, header->m_szLastMissionStringID);
  v2 = !(unsigned int)UFG::qStringCompare(v4.mData, "$SGTITLE_WELCOME_TO_HONG_KONG", -1)
    || !(unsigned int)UFG::qStringCompare(v4.mData, "$SGTITLE_GOING_UNDER", -1)
    || !(unsigned int)UFG::qStringCompare(v4.mData, "$SGTITLE_VENDOR_FAVOR", -1)
    || !(unsigned int)UFG::qStringCompare(v4.mData, "$SGTITLE_VENDOR_EXTORTION", -1);
  UFG::qString::~qString(&v4);
  return v2;
}

