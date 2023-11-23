// File Line: 33
// RVA: 0x5C50F0
void __fastcall UFG::UIHKScreenFaceTracker::UIHKScreenFaceTracker(UFG::UIHKScreenFaceTracker *this)
{
  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = eDIM_INVALID;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenFaceTracker::`vftable;
}

// File Line: 46
// RVA: 0x630B90
void __fastcall UFG::UIHKScreenFaceTracker::init(UFG::UIHKScreenFaceTracker *this, UFG::UICommandData *data)
{
  Scaleform::GFx::Movie *pObject; // r15
  UFG::GameStatTracker *v4; // r12
  int MaxStanding; // ebx
  int Stat; // edi
  int PercentageToNextFaceLevel; // r14d
  float v8; // xmm1_4
  unsigned int v9; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v11; // rax
  unsigned int v12; // eax
  UFG::UIGfxTranslator *v13; // rcx
  const char *v14; // r8
  char *mData; // rbx
  char *v16; // rbx
  int FaceLevel; // r13d
  int i; // esi
  int v19; // r14d
  int v20; // edi
  unsigned int v21; // eax
  UFG::UIGfxTranslator *v22; // rcx
  const char *v23; // rax
  char *v24; // rbx
  UFG::qString *v25; // rcx
  int RageTimerForFaceLevel; // ebx
  int v27; // eax
  unsigned int v28; // eax
  UFG::UIGfxTranslator *v29; // rcx
  const char *v30; // rax
  char *v31; // rbx
  unsigned int v32; // eax
  UFG::UIGfxTranslator *v33; // rcx
  const char *v34; // rax
  char *v35; // rbx
  int DiscountForFaceLevel; // ebx
  unsigned int v37; // eax
  UFG::UIGfxTranslator *v38; // rcx
  const char *v39; // rax
  char *v40; // rbx
  unsigned int v41; // eax
  UFG::UIGfxTranslator *v42; // rcx
  const char *v43; // rax
  char *v44; // rbx
  unsigned int v45; // eax
  UFG::UIGfxTranslator *v46; // rcx
  const char *v47; // rax
  char *v48; // rbx
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-A8h]
  __int64 v50; // [rsp+28h] [rbp-A0h]
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-98h] BYREF
  char v52[8]; // [rsp+60h] [rbp-68h] BYREF
  __int64 v53; // [rsp+68h] [rbp-60h]
  __int64 v54; // [rsp+70h] [rbp-58h]
  __int64 v55; // [rsp+78h] [rbp-50h]
  char v56[16]; // [rsp+88h] [rbp-40h] BYREF
  __int64 v57; // [rsp+98h] [rbp-30h]
  int v58; // [rsp+A0h] [rbp-28h]
  long double v59; // [rsp+A8h] [rbp-20h]
  __int64 v60; // [rsp+B8h] [rbp-10h]
  UFG::qString v61; // [rsp+C0h] [rbp-8h] BYREF
  UFG::qString v62; // [rsp+E8h] [rbp+20h] BYREF
  UFG::qString v63; // [rsp+110h] [rbp+48h] BYREF
  UFG::qString v64; // [rsp+138h] [rbp+70h] BYREF
  UFG::qString v65; // [rsp+160h] [rbp+98h] BYREF
  UFG::qString v66; // [rsp+188h] [rbp+C0h] BYREF
  UFG::qString v67; // [rsp+1B0h] [rbp+E8h] BYREF
  UFG::qString v68; // [rsp+1D8h] [rbp+110h] BYREF
  unsigned int iDiffBetweenLevels[4]; // [rsp+298h] [rbp+1D0h] BYREF
  unsigned int iExpTowardsNextLevel[6]; // [rsp+2A8h] [rbp+1E0h] BYREF

  v60 = -2i64;
  UFG::UIScreen::init(this, data);
  pObject = this->mRenderable->m_movie.pObject;
  v4 = UFG::GameStatTracker::Instance();
  MaxStanding = UFG::GameStatTracker::GetMaxStanding(v4);
  Stat = UFG::GameStatTracker::GetStat(v4, Standing);
  PercentageToNextFaceLevel = UFG::GameStatTracker::GetPercentageToNextFaceLevel(v4);
  UFG::GameStatTracker::GetStandingPointsSinceLastLevel(v4, iExpTowardsNextLevel, iDiffBetweenLevels);
  v8 = (float)((float)Stat / (float)MaxStanding) * 100.0;
  v9 = UFG::qStringHashUpper32("PAUSE_FACE_TOTAL", -1);
  m_translator = UFG::UIScreenManager::s_instance->m_translator;
  if ( !m_translator || (v11 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v9)) == 0i64 )
    v11 = "PAUSE_FACE_TOTAL";
  UFG::qString::qString(&v66, "%s %d / %d, %d%%", v11, (unsigned int)Stat, MaxStanding, (int)v8);
  v12 = UFG::qStringHashUpper32("PAUSE_TO_NEXT_LEVEL", -1);
  v13 = UFG::UIScreenManager::s_instance->m_translator;
  if ( !v13 || (v14 = (const char *)v13->vfptr[5].__vecDelDtor(v13, v12)) == 0i64 )
    v14 = "PAUSE_TO_NEXT_LEVEL";
  LODWORD(v50) = PercentageToNextFaceLevel;
  LODWORD(pDtor) = iDiffBetweenLevels[0];
  UFG::qString::qString(&v64, "%s %d / %d, %d%%", v14, iExpTowardsNextLevel[0], pDtor, v50);
  `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  mData = v66.mData;
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = mData;
  Scaleform::GFx::Movie::Invoke(pObject, "SetTotalFace", 0i64, &ptr, 1u);
  v16 = v64.mData;
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = v16;
  Scaleform::GFx::Movie::Invoke(pObject, "SetNextLevel", 0i64, &ptr, 1u);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  ptr.mValue.NValue = (double)(int)v8;
  Scaleform::GFx::Movie::Invoke(pObject, "SetFaceTrackerBarPercentage", 0i64, &ptr, 1u);
  FaceLevel = UFG::GameStatTracker::GetFaceLevel(v4);
  for ( i = 1; i <= FaceLevel; ++i )
  {
    v19 = i - 1;
    v20 = 0;
    if ( i )
    {
      if ( i > 0 )
      {
        RageTimerForFaceLevel = UFG::GameStatTracker::GetRageTimerForFaceLevel(v4, v19);
        v27 = UFG::GameStatTracker::GetRageTimerForFaceLevel(v4, i);
        if ( RageTimerForFaceLevel >= 0 )
        {
          if ( v27 <= 0 || v27 <= RageTimerForFaceLevel )
            goto LABEL_58;
          v32 = UFG::qStringHashUpper32("PAUSE_FACE_TRACKER_RAGE_TIMER_INCREASED", -1);
          v33 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v33 || (v34 = (const char *)v33->vfptr[5].__vecDelDtor(v33, v32)) == 0i64 )
            v34 = "PAUSE_FACE_TRACKER_RAGE_TIMER_INCREASED";
          UFG::qString::qString(&v63, v34);
          if ( (ptr.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
              ptr.pObjectInterface,
              &ptr,
              ptr.mValue);
            ptr.pObjectInterface = 0i64;
          }
          ptr.Type = VT_Number;
          ptr.mValue.NValue = (double)v19;
          if ( (v55 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, _QWORD))(*(_QWORD *)v54 + 16i64))(v54, v52, *(_QWORD *)&ptr.Type);
            v54 = 0i64;
          }
          LODWORD(v55) = 5;
          *(_QWORD *)&ptr.Type = 0i64;
          v35 = v63.mData;
          if ( (v54 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, unsigned __int64 *, __int64))(*(_QWORD *)v53 + 16i64))(
              v53,
              &ptr.DataAux,
              v55);
            v53 = 0i64;
          }
          LODWORD(v54) = 6;
          v55 = (__int64)v35;
          if ( (v58 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v57 + 16i64))(
              v57,
              v56,
              COERCE_LONG_DOUBLE(*(_QWORD *)&v59));
            v57 = 0i64;
          }
          v58 = 5;
          v59 = DOUBLE_1_0;
          Scaleform::GFx::Movie::Invoke(pObject, "SetReward", 0i64, &ptr, 4u);
          v20 = 1;
          v25 = &v63;
          goto LABEL_57;
        }
        if ( v27 > 0 )
        {
          v28 = UFG::qStringHashUpper32("PAUSE_FACE_TRACKER_RAGE_UNLOCKED", -1);
          v29 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v29 || (v30 = (const char *)v29->vfptr[5].__vecDelDtor(v29, v28)) == 0i64 )
            v30 = "PAUSE_FACE_TRACKER_RAGE_UNLOCKED";
          UFG::qString::qString(&v68, v30);
          if ( (ptr.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
              ptr.pObjectInterface,
              &ptr,
              ptr.mValue);
            ptr.pObjectInterface = 0i64;
          }
          ptr.Type = VT_Number;
          ptr.mValue.NValue = (double)v19;
          if ( (v55 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, _QWORD))(*(_QWORD *)v54 + 16i64))(v54, v52, *(_QWORD *)&ptr.Type);
            v54 = 0i64;
          }
          LODWORD(v55) = 5;
          *(_QWORD *)&ptr.Type = 0i64;
          v31 = v68.mData;
          if ( (v54 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, unsigned __int64 *, __int64))(*(_QWORD *)v53 + 16i64))(
              v53,
              &ptr.DataAux,
              v55);
            v53 = 0i64;
          }
          LODWORD(v54) = 6;
          v55 = (__int64)v31;
          if ( (v58 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v57 + 16i64))(
              v57,
              v56,
              COERCE_LONG_DOUBLE(*(_QWORD *)&v59));
            v57 = 0i64;
          }
          v58 = 5;
          v59 = 0.0;
          Scaleform::GFx::Movie::Invoke(pObject, "SetReward", 0i64, &ptr, 4u);
          v20 = 1;
          v25 = &v68;
          goto LABEL_57;
        }
      }
    }
    else if ( (int)UFG::GameStatTracker::GetRageTimerForFaceLevel(v4, 0) > 0 )
    {
      v21 = UFG::qStringHashUpper32("PAUSE_FACE_TRACKER_RAGE_UNLOCKED", -1);
      v22 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v22 || (v23 = (const char *)v22->vfptr[5].__vecDelDtor(v22, v21)) == 0i64 )
        v23 = "PAUSE_FACE_TRACKER_RAGE_UNLOCKED";
      UFG::qString::qString(&v67, v23);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Number;
      ptr.mValue.NValue = (double)v19;
      if ( (v55 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, _QWORD))(*(_QWORD *)v54 + 16i64))(v54, v52, *(_QWORD *)&ptr.Type);
        v54 = 0i64;
      }
      LODWORD(v55) = 5;
      *(_QWORD *)&ptr.Type = 0i64;
      v24 = v67.mData;
      if ( (v54 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, unsigned __int64 *, __int64))(*(_QWORD *)v53 + 16i64))(v53, &ptr.DataAux, v55);
        v53 = 0i64;
      }
      LODWORD(v54) = 6;
      v55 = (__int64)v24;
      if ( (v58 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v57 + 16i64))(
          v57,
          v56,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v59));
        v57 = 0i64;
      }
      v58 = 5;
      v59 = 0.0;
      Scaleform::GFx::Movie::Invoke(pObject, "SetReward", 0i64, &ptr, 4u);
      v20 = 1;
      v25 = &v67;
LABEL_57:
      UFG::qString::~qString(v25);
    }
LABEL_58:
    DiscountForFaceLevel = UFG::GameStatTracker::GetDiscountForFaceLevel(v4, i);
    if ( DiscountForFaceLevel > 0 )
    {
      v37 = UFG::qStringHashUpper32("PAUSE_FACE_TRACKER_PURCHASE_DISCOUNT", -1);
      v38 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v38 || (v39 = (const char *)v38->vfptr[5].__vecDelDtor(v38, v37)) == 0i64 )
        v39 = "PAUSE_FACE_TRACKER_PURCHASE_DISCOUNT";
      UFG::qString::qString(&v61, "%s %d%%", v39, (unsigned int)DiscountForFaceLevel);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Number;
      ptr.mValue.NValue = (double)v19;
      if ( (v55 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, _QWORD))(*(_QWORD *)v54 + 16i64))(v54, v52, *(_QWORD *)&ptr.Type);
        v54 = 0i64;
      }
      LODWORD(v55) = 5;
      *(double *)&ptr.Type = (double)v20;
      v40 = v61.mData;
      if ( (v54 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, unsigned __int64 *, __int64))(*(_QWORD *)v53 + 16i64))(v53, &ptr.DataAux, v55);
        v53 = 0i64;
      }
      LODWORD(v54) = 6;
      v55 = (__int64)v40;
      if ( (v58 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v57 + 16i64))(
          v57,
          v56,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v59));
        v57 = 0i64;
      }
      v58 = 5;
      v59 = DOUBLE_2_0;
      Scaleform::GFx::Movie::Invoke(pObject, "SetReward", 0i64, &ptr, 4u);
      ++v20;
      UFG::qString::~qString(&v61);
    }
    if ( UFG::GameStatTracker::GetFavoursUnlockedForFaceLevel(v4, i) )
    {
      v41 = UFG::qStringHashUpper32("PAUSE_FACE_TRACKER_FAVOURS_UNLOCKED", -1);
      v42 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v42 || (v43 = (const char *)v42->vfptr[5].__vecDelDtor(v42, v41)) == 0i64 )
        v43 = "PAUSE_FACE_TRACKER_FAVOURS_UNLOCKED";
      UFG::qString::qString(&v65, v43);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Number;
      ptr.mValue.NValue = (double)v19;
      if ( (v55 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, _QWORD))(*(_QWORD *)v54 + 16i64))(v54, v52, *(_QWORD *)&ptr.Type);
        v54 = 0i64;
      }
      LODWORD(v55) = 5;
      *(double *)&ptr.Type = (double)v20;
      v44 = v65.mData;
      if ( (v54 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, unsigned __int64 *, __int64))(*(_QWORD *)v53 + 16i64))(v53, &ptr.DataAux, v55);
        v53 = 0i64;
      }
      LODWORD(v54) = 6;
      v55 = (__int64)v44;
      if ( (v58 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v57 + 16i64))(
          v57,
          v56,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v59));
        v57 = 0i64;
      }
      v58 = 5;
      v59 = DOUBLE_3_0;
      Scaleform::GFx::Movie::Invoke(pObject, "SetReward", 0i64, &ptr, 4u);
      ++v20;
      UFG::qString::~qString(&v65);
    }
    if ( (int)UFG::GameStatTracker::GetNumSafeHousesUnlockedForFaceLevel(v4, i) > 0 )
    {
      v45 = UFG::qStringHashUpper32("PAUSE_FACE_TRACKER_SAFEHOUSE_UNLOCKED", -1);
      v46 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v46 || (v47 = (const char *)v46->vfptr[5].__vecDelDtor(v46, v45)) == 0i64 )
        v47 = "PAUSE_FACE_TRACKER_SAFEHOUSE_UNLOCKED";
      UFG::qString::qString(&v62, v47);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Number;
      ptr.mValue.NValue = (double)v19;
      if ( (v55 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, _QWORD))(*(_QWORD *)v54 + 16i64))(v54, v52, *(_QWORD *)&ptr.Type);
        v54 = 0i64;
      }
      LODWORD(v55) = 5;
      *(double *)&ptr.Type = (double)v20;
      v48 = v62.mData;
      if ( (v54 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, unsigned __int64 *, __int64))(*(_QWORD *)v53 + 16i64))(v53, &ptr.DataAux, v55);
        v53 = 0i64;
      }
      LODWORD(v54) = 6;
      v55 = (__int64)v48;
      if ( (v58 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v57 + 16i64))(
          v57,
          v56,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v59));
        v57 = 0i64;
      }
      v58 = 5;
      v59 = DOUBLE_4_0;
      Scaleform::GFx::Movie::Invoke(pObject, "SetReward", 0i64, &ptr, 4u);
      UFG::qString::~qString(&v62);
    }
  }
  `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v64);
  UFG::qString::~qString(&v66);
}

// File Line: 212
// RVA: 0x622A00
bool __fastcall UFG::UIHKScreenFaceTracker::handleMessage(
        UFG::UIHKScreenFaceTracker *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  if ( msgId != UI_HASH_BUTTON_BACK_PRESSED_30 )
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
  return 1;
}

