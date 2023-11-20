// File Line: 33
// RVA: 0x5C50F0
void __fastcall UFG::UIHKScreenFaceTracker::UIHKScreenFaceTracker(UFG::UIHKScreenFaceTracker *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = 0;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenFaceTracker::`vftable;
}

// File Line: 46
// RVA: 0x630B90
void __fastcall UFG::UIHKScreenFaceTracker::init(UFG::UIHKScreenFaceTracker *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenFaceTracker *v2; // rbx
  Scaleform::GFx::Movie *v3; // r15
  UFG::GameStatTracker *v4; // r12
  signed int v5; // ebx
  signed int v6; // edi
  int v7; // er14
  float v8; // xmm1_4
  unsigned int v9; // eax
  UFG::UIGfxTranslator *v10; // rcx
  const char *v11; // rax
  unsigned int v12; // eax
  UFG::UIGfxTranslator *v13; // rcx
  const char *v14; // r8
  char *v15; // rbx
  char *v16; // rbx
  int v17; // er13
  int i; // esi
  int v19; // er14
  signed int v20; // edi
  unsigned int v21; // eax
  UFG::UIGfxTranslator *v22; // rcx
  const char *v23; // rax
  char *v24; // rbx
  UFG::qString *v25; // rcx
  int v26; // ebx
  int v27; // eax
  unsigned int v28; // eax
  UFG::UIGfxTranslator *v29; // rcx
  const char *v30; // rax
  char *v31; // rbx
  unsigned int v32; // eax
  UFG::UIGfxTranslator *v33; // rcx
  const char *v34; // rax
  char *v35; // rbx
  unsigned int v36; // ebx
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
  void (__fastcall *pDtora)(void *); // [rsp+20h] [rbp-A8h]
  __int64 v51; // [rsp+28h] [rbp-A0h]
  __int64 v52; // [rsp+28h] [rbp-A0h]
  char ptr; // [rsp+30h] [rbp-98h]
  __int64 v54; // [rsp+40h] [rbp-88h]
  double v55; // [rsp+48h] [rbp-80h]
  double v56; // [rsp+50h] [rbp-78h]
  char v57; // [rsp+58h] [rbp-70h]
  char v58; // [rsp+60h] [rbp-68h]
  __int64 v59; // [rsp+68h] [rbp-60h]
  __int64 v60; // [rsp+70h] [rbp-58h]
  char *v61; // [rsp+78h] [rbp-50h]
  char v62; // [rsp+88h] [rbp-40h]
  __int64 v63; // [rsp+98h] [rbp-30h]
  unsigned int v64; // [rsp+A0h] [rbp-28h]
  long double v65; // [rsp+A8h] [rbp-20h]
  __int64 v66; // [rsp+B8h] [rbp-10h]
  UFG::qString v67; // [rsp+C0h] [rbp-8h]
  UFG::qString v68; // [rsp+E8h] [rbp+20h]
  UFG::qString v69; // [rsp+110h] [rbp+48h]
  UFG::qString v70; // [rsp+138h] [rbp+70h]
  UFG::qString v71; // [rsp+160h] [rbp+98h]
  UFG::qString v72; // [rsp+188h] [rbp+C0h]
  UFG::qString v73; // [rsp+1B0h] [rbp+E8h]
  UFG::qString v74; // [rsp+1D8h] [rbp+110h]
  unsigned int iDiffBetweenLevels; // [rsp+298h] [rbp+1D0h]
  unsigned int iExpTowardsNextLevel; // [rsp+2A8h] [rbp+1E0h]

  v66 = -2i64;
  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v3 = v2->mRenderable->m_movie.pObject;
  v4 = UFG::GameStatTracker::Instance();
  v5 = UFG::GameStatTracker::GetMaxStanding(v4);
  v6 = UFG::GameStatTracker::GetStat(v4, Standing);
  v7 = UFG::GameStatTracker::GetPercentageToNextFaceLevel(v4);
  UFG::GameStatTracker::GetStandingPointsSinceLastLevel(v4, &iExpTowardsNextLevel, &iDiffBetweenLevels);
  v8 = (float)((float)v6 / (float)v5) * 100.0;
  v9 = UFG::qStringHashUpper32("PAUSE_FACE_TOTAL", 0xFFFFFFFF);
  v10 = UFG::UIScreenManager::s_instance->m_translator;
  if ( !v10 || (v11 = (const char *)v10->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, v9)) == 0i64 )
    v11 = "PAUSE_FACE_TOTAL";
  LODWORD(v51) = (signed int)v8;
  LODWORD(pDtor) = v5;
  UFG::qString::qString(&v72, "%s %d / %d, %d%%", v11, (unsigned int)v6, pDtor, v51);
  v12 = UFG::qStringHashUpper32("PAUSE_TO_NEXT_LEVEL", 0xFFFFFFFF);
  v13 = UFG::UIScreenManager::s_instance->m_translator;
  if ( !v13 || (v14 = (const char *)v13->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v13->vfptr, v12)) == 0i64 )
    v14 = "PAUSE_TO_NEXT_LEVEL";
  LODWORD(v52) = v7;
  LODWORD(pDtora) = iDiffBetweenLevels;
  UFG::qString::qString(&v70, "%s %d / %d, %d%%", v14, iExpTowardsNextLevel, pDtora, v52);
  `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v15 = v72.mData;
  if ( (LODWORD(v55) >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v54 + 16i64))(
      v54,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v56));
    v54 = 0i64;
  }
  LODWORD(v55) = 6;
  v56 = *(double *)&v15;
  Scaleform::GFx::Movie::Invoke(v3, "SetTotalFace", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  v16 = v70.mData;
  if ( (LODWORD(v55) >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v54 + 16i64))(
      v54,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v56));
    v54 = 0i64;
  }
  LODWORD(v55) = 6;
  v56 = *(double *)&v16;
  Scaleform::GFx::Movie::Invoke(v3, "SetNextLevel", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  if ( (LODWORD(v55) >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v54 + 16i64))(
      v54,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v56));
    v54 = 0i64;
  }
  LODWORD(v55) = 5;
  v56 = (double)(signed int)v8;
  Scaleform::GFx::Movie::Invoke(v3, "SetFaceTrackerBarPercentage", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  v17 = UFG::GameStatTracker::GetFaceLevel(v4);
  for ( i = 1; i <= v17; ++i )
  {
    v19 = i - 1;
    v20 = 0;
    if ( i )
    {
      if ( i > 0 )
      {
        v26 = UFG::GameStatTracker::GetRageTimerForFaceLevel(v4, v19);
        v27 = UFG::GameStatTracker::GetRageTimerForFaceLevel(v4, i);
        if ( v26 >= 0 )
        {
          if ( v27 <= 0 || v27 <= v26 )
            goto LABEL_58;
          v32 = UFG::qStringHashUpper32("PAUSE_FACE_TRACKER_RAGE_TIMER_INCREASED", 0xFFFFFFFF);
          v33 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v33
            || (v34 = (const char *)v33->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v33->vfptr, v32)) == 0i64 )
          {
            v34 = "PAUSE_FACE_TRACKER_RAGE_TIMER_INCREASED";
          }
          UFG::qString::qString(&v69, v34);
          if ( (LODWORD(v55) >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v54 + 16i64))(
              v54,
              &ptr,
              COERCE_DOUBLE(*(_QWORD *)&v56));
            v54 = 0i64;
          }
          LODWORD(v55) = 5;
          v56 = (double)v19;
          if ( ((unsigned int)v61 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v60 + 16i64))(
              v60,
              &v58,
              COERCE_DOUBLE(*(_QWORD *)&v55));
            v60 = 0i64;
          }
          LODWORD(v61) = 5;
          v55 = 0.0;
          v35 = v69.mData;
          if ( ((unsigned int)v60 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v59 + 16i64))(v59, &v57, v61);
            v59 = 0i64;
          }
          LODWORD(v60) = 6;
          v61 = v35;
          if ( (v64 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v63 + 16i64))(
              v63,
              &v62,
              COERCE_LONG_DOUBLE(*(_QWORD *)&v65));
            v63 = 0i64;
          }
          v64 = 5;
          v65 = DOUBLE_1_0;
          Scaleform::GFx::Movie::Invoke(v3, "SetReward", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
          v20 = 1;
          v25 = &v69;
          goto LABEL_57;
        }
        if ( v27 > 0 )
        {
          v28 = UFG::qStringHashUpper32("PAUSE_FACE_TRACKER_RAGE_UNLOCKED", 0xFFFFFFFF);
          v29 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v29
            || (v30 = (const char *)v29->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v29->vfptr, v28)) == 0i64 )
          {
            v30 = "PAUSE_FACE_TRACKER_RAGE_UNLOCKED";
          }
          UFG::qString::qString(&v74, v30);
          if ( (LODWORD(v55) >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v54 + 16i64))(
              v54,
              &ptr,
              COERCE_DOUBLE(*(_QWORD *)&v56));
            v54 = 0i64;
          }
          LODWORD(v55) = 5;
          v56 = (double)v19;
          if ( ((unsigned int)v61 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v60 + 16i64))(
              v60,
              &v58,
              COERCE_DOUBLE(*(_QWORD *)&v55));
            v60 = 0i64;
          }
          LODWORD(v61) = 5;
          v55 = 0.0;
          v31 = v74.mData;
          if ( ((unsigned int)v60 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v59 + 16i64))(v59, &v57, v61);
            v59 = 0i64;
          }
          LODWORD(v60) = 6;
          v61 = v31;
          if ( (v64 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v63 + 16i64))(
              v63,
              &v62,
              COERCE_LONG_DOUBLE(*(_QWORD *)&v65));
            v63 = 0i64;
          }
          v64 = 5;
          v65 = 0.0;
          Scaleform::GFx::Movie::Invoke(v3, "SetReward", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
          v20 = 1;
          v25 = &v74;
          goto LABEL_57;
        }
      }
    }
    else if ( (signed int)UFG::GameStatTracker::GetRageTimerForFaceLevel(v4, 0) > 0 )
    {
      v21 = UFG::qStringHashUpper32("PAUSE_FACE_TRACKER_RAGE_UNLOCKED", 0xFFFFFFFF);
      v22 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v22
        || (v23 = (const char *)v22->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, v21)) == 0i64 )
      {
        v23 = "PAUSE_FACE_TRACKER_RAGE_UNLOCKED";
      }
      UFG::qString::qString(&v73, v23);
      if ( (LODWORD(v55) >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v54 + 16i64))(
          v54,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v56));
        v54 = 0i64;
      }
      LODWORD(v55) = 5;
      v56 = (double)v19;
      if ( ((unsigned int)v61 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v60 + 16i64))(
          v60,
          &v58,
          COERCE_DOUBLE(*(_QWORD *)&v55));
        v60 = 0i64;
      }
      LODWORD(v61) = 5;
      v55 = 0.0;
      v24 = v73.mData;
      if ( ((unsigned int)v60 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v59 + 16i64))(v59, &v57, v61);
        v59 = 0i64;
      }
      LODWORD(v60) = 6;
      v61 = v24;
      if ( (v64 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v63 + 16i64))(
          v63,
          &v62,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v65));
        v63 = 0i64;
      }
      v64 = 5;
      v65 = 0.0;
      Scaleform::GFx::Movie::Invoke(v3, "SetReward", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
      v20 = 1;
      v25 = &v73;
LABEL_57:
      UFG::qString::~qString(v25);
      goto LABEL_58;
    }
LABEL_58:
    v36 = UFG::GameStatTracker::GetDiscountForFaceLevel(v4, i);
    if ( (signed int)v36 > 0 )
    {
      v37 = UFG::qStringHashUpper32("PAUSE_FACE_TRACKER_PURCHASE_DISCOUNT", 0xFFFFFFFF);
      v38 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v38
        || (v39 = (const char *)v38->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v38->vfptr, v37)) == 0i64 )
      {
        v39 = "PAUSE_FACE_TRACKER_PURCHASE_DISCOUNT";
      }
      UFG::qString::qString(&v67, "%s %d%%", v39, v36);
      if ( (LODWORD(v55) >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v54 + 16i64))(
          v54,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v56));
        v54 = 0i64;
      }
      LODWORD(v55) = 5;
      v56 = (double)v19;
      if ( ((unsigned int)v61 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v60 + 16i64))(
          v60,
          &v58,
          COERCE_DOUBLE(*(_QWORD *)&v55));
        v60 = 0i64;
      }
      LODWORD(v61) = 5;
      v55 = (double)v20;
      v40 = v67.mData;
      if ( ((unsigned int)v60 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v59 + 16i64))(v59, &v57, v61);
        v59 = 0i64;
      }
      LODWORD(v60) = 6;
      v61 = v40;
      if ( (v64 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v63 + 16i64))(
          v63,
          &v62,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v65));
        v63 = 0i64;
      }
      v64 = 5;
      v65 = DOUBLE_2_0;
      Scaleform::GFx::Movie::Invoke(v3, "SetReward", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
      ++v20;
      UFG::qString::~qString(&v67);
    }
    if ( UFG::GameStatTracker::GetFavoursUnlockedForFaceLevel(v4, i) )
    {
      v41 = UFG::qStringHashUpper32("PAUSE_FACE_TRACKER_FAVOURS_UNLOCKED", 0xFFFFFFFF);
      v42 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v42
        || (v43 = (const char *)v42->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v42->vfptr, v41)) == 0i64 )
      {
        v43 = "PAUSE_FACE_TRACKER_FAVOURS_UNLOCKED";
      }
      UFG::qString::qString(&v71, v43);
      if ( (LODWORD(v55) >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v54 + 16i64))(
          v54,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v56));
        v54 = 0i64;
      }
      LODWORD(v55) = 5;
      v56 = (double)v19;
      if ( ((unsigned int)v61 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v60 + 16i64))(
          v60,
          &v58,
          COERCE_DOUBLE(*(_QWORD *)&v55));
        v60 = 0i64;
      }
      LODWORD(v61) = 5;
      v55 = (double)v20;
      v44 = v71.mData;
      if ( ((unsigned int)v60 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v59 + 16i64))(v59, &v57, v61);
        v59 = 0i64;
      }
      LODWORD(v60) = 6;
      v61 = v44;
      if ( (v64 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v63 + 16i64))(
          v63,
          &v62,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v65));
        v63 = 0i64;
      }
      v64 = 5;
      v65 = DOUBLE_3_0;
      Scaleform::GFx::Movie::Invoke(v3, "SetReward", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
      ++v20;
      UFG::qString::~qString(&v71);
    }
    if ( (signed int)UFG::GameStatTracker::GetNumSafeHousesUnlockedForFaceLevel(v4, i) > 0 )
    {
      v45 = UFG::qStringHashUpper32("PAUSE_FACE_TRACKER_SAFEHOUSE_UNLOCKED", 0xFFFFFFFF);
      v46 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v46
        || (v47 = (const char *)v46->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v46->vfptr, v45)) == 0i64 )
      {
        v47 = "PAUSE_FACE_TRACKER_SAFEHOUSE_UNLOCKED";
      }
      UFG::qString::qString(&v68, v47);
      if ( (LODWORD(v55) >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v54 + 16i64))(
          v54,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v56));
        v54 = 0i64;
      }
      LODWORD(v55) = 5;
      v56 = (double)v19;
      if ( ((unsigned int)v61 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v60 + 16i64))(
          v60,
          &v58,
          COERCE_DOUBLE(*(_QWORD *)&v55));
        v60 = 0i64;
      }
      LODWORD(v61) = 5;
      v55 = (double)v20;
      v48 = v68.mData;
      if ( ((unsigned int)v60 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v59 + 16i64))(v59, &v57, v61);
        v59 = 0i64;
      }
      LODWORD(v60) = 6;
      v61 = v48;
      if ( (v64 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v63 + 16i64))(
          v63,
          &v62,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v65));
        v63 = 0i64;
      }
      v64 = 5;
      v65 = DOUBLE_4_0;
      Scaleform::GFx::Movie::Invoke(v3, "SetReward", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
      UFG::qString::~qString(&v68);
    }
  }
  `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v70);
  UFG::qString::~qString(&v72);
}     v63,
          &v62,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v65));
        v63 = 0i64;
      }
      v64 = 5;
      v65 = DOUBLE_4_0;
      Sc

// File Line: 212
// RVA: 0x622A00
bool __fastcall UFG::UIHKScreenFaceTracker::handleMessage(UFG::UIHKScreenFaceTracker *this, unsigned int msgId, UFG::UIMessage *msg)
{
  if ( msgId != UI_HASH_BUTTON_BACK_PRESSED_30 )
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&this->vfptr, msgId, msg);
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xFFFFFFFF);
  return 1;
}

