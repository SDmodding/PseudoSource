// File Line: 23
// RVA: 0x5F4A00
void __fastcall UFG::UIHKSecondaryObjective::Populate(
        UFG::UIHKSecondaryObjective *this,
        UFG::SecondaryObjective *objective)
{
  unsigned int mMaxProgress; // eax
  UFG::SecondaryObjective::eStatus mStatus; // eax
  UFG::SecondaryObjective::eStatus Status; // ecx

  if ( this->Progress != objective->mProgress
    || this->MaxProgress != objective->mMaxProgress
    || (unsigned int)UFG::qStringCompare(this->Caption.mData, objective->mCaption.mData, -1) )
  {
    UFG::qString::Set(&this->Caption, objective->mCaption.mData, objective->mCaption.mLength, 0i64, 0);
    this->Progress = objective->mProgress;
    mMaxProgress = objective->mMaxProgress;
    this->CaptionChanged = 1;
    this->MaxProgress = mMaxProgress;
  }
  mStatus = objective->mStatus;
  Status = this->Status;
  this->Status = objective->mStatus;
  this->StatusChanged |= Status != mStatus;
}

// File Line: 41
// RVA: 0x5C7F30
void __fastcall UFG::UIHKSecondaryObjectivesWidget::UIHKSecondaryObjectivesWidget(
        UFG::UIHKSecondaryObjectivesWidget *this)
{
  UFG::UIHKSecondaryObjective *p_mCopObjective; // rbx

  p_mCopObjective = &this->mCopObjective;
  UFG::qString::qString(&this->mCopObjective.Caption);
  *(_WORD *)&p_mCopObjective->CaptionChanged = 0;
  *(_QWORD *)&p_mCopObjective->Progress = 0i64;
  *(_QWORD *)&p_mCopObjective->HideTimer = 0i64;
  UFG::qString::qString(&this->mTriadObjective.Caption);
  *(_WORD *)&this->mTriadObjective.CaptionChanged = 0;
  *(_QWORD *)&this->mTriadObjective.Progress = 0i64;
  *(_QWORD *)&this->mTriadObjective.HideTimer = 0i64;
  UFG::UIHKSecondaryObjectivesWidget::Refresh(this);
}

// File Line: 64
// RVA: 0x61B7A0
void __fastcall UFG::UIHKSecondaryObjectivesWidget::UpdateObjective(
        UFG::UIHKSecondaryObjectivesWidget *this,
        UFG::UIScreen *pScreen,
        float elapsed,
        UFG::UIHKSecondaryObjective *objective,
        bool isCop)
{
  UFG::SecondaryObjective::eStatus Status; // r8d
  __int32 v9; // r8d
  __int32 v10; // r8d
  float v11; // xmm1_4
  UFG::SecondaryObjectiveTracker *p_mSecondaryObjectiveTracker; // rcx
  float v13; // xmm1_4

  if ( objective->StatusChanged )
  {
    Status = objective->Status;
    *(_WORD *)&objective->CaptionChanged = 0;
    if ( Status == STATUS_INACTIVE )
    {
      UFG::UIHKSecondaryObjectivesWidget::Flash_HideObjective(this, pScreen, isCop);
      objective->WidgetState = STATE_IDLE;
      goto LABEL_13;
    }
    v9 = Status - 1;
    if ( v9 )
    {
      v10 = v9 - 1;
      if ( v10 )
      {
        if ( v10 != 1 )
          goto LABEL_13;
        UFG::UIHKSecondaryObjectivesWidget::Flash_ShowObjective(this, pScreen, "$HUD_FAILED", 0, 0, isCop);
        objective->WidgetState = STATE_TEXT_INBOX;
      }
      else
      {
        UFG::UIHKSecondaryObjectivesWidget::Flash_ShowObjective(this, pScreen, "$HUD_SUCCESS", 0, 0, isCop);
        objective->WidgetState = STATE_TEXT_INBOX;
      }
      goto LABEL_12;
    }
  }
  else
  {
    if ( !objective->CaptionChanged )
      goto LABEL_13;
    objective->CaptionChanged = 0;
  }
  UFG::UIHKSecondaryObjectivesWidget::Flash_ShowObjective(
    this,
    pScreen,
    objective->Caption.mData,
    objective->Progress,
    objective->MaxProgress,
    isCop);
  objective->WidgetState = STATE_PHONE_CONTACTS;
LABEL_12:
  objective->HideTimer = 10.0;
LABEL_13:
  if ( objective->WidgetState == STATE_PHONE_CONTACTS )
  {
    v13 = objective->HideTimer - elapsed;
    objective->HideTimer = v13;
    if ( v13 <= 0.0 )
    {
      UFG::UIHKSecondaryObjectivesWidget::Flash_HideObjective(this, pScreen, isCop);
      objective->WidgetState = STATE_ROOT_MENU;
    }
  }
  else if ( objective->WidgetState == STATE_TEXT_INBOX )
  {
    v11 = objective->HideTimer - elapsed;
    objective->HideTimer = v11;
    if ( v11 <= 0.0 )
    {
      p_mSecondaryObjectiveTracker = &UFG::ProgressionTracker::Instance()->mSecondaryObjectiveTracker;
      if ( isCop )
        UFG::SecondaryObjectiveTracker::RemoveObjective(p_mSecondaryObjectiveTracker, 0);
      else
        UFG::SecondaryObjectiveTracker::RemoveObjective(p_mSecondaryObjectiveTracker, 1);
    }
  }
}

// File Line: 158
// RVA: 0x5FFF00
void __fastcall UFG::UIHKSecondaryObjectivesWidget::Refresh(UFG::UIHKSecondaryObjectivesWidget *this)
{
  UFG::ProgressionTracker *v2; // rbx
  UFG::SecondaryObjectiveTracker *Objective; // rdi
  UFG::SecondaryObjectiveTracker *v4; // rbx

  v2 = UFG::ProgressionTracker::Instance();
  Objective = UFG::SecondaryObjectiveTracker::GetObjective(&v2->mSecondaryObjectiveTracker, ID_COP_OBJECTIVE);
  v4 = UFG::SecondaryObjectiveTracker::GetObjective(&v2->mSecondaryObjectiveTracker, ID_TRIAD_OBJECTIVE);
  UFG::UIHKSecondaryObjective::Populate(&this->mCopObjective, Objective->mObjectives);
  UFG::UIHKSecondaryObjective::Populate(&this->mTriadObjective, v4->mObjectives);
}

// File Line: 170
// RVA: 0x5E4AD0
void __fastcall UFG::UIHKSecondaryObjectivesWidget::Flash_ShowObjective(
        UFG::UIHKSecondaryObjectivesWidget *this,
        UFG::UIScreen *pScreen,
        const char *caption,
        unsigned int progress,
        unsigned int maxProgress,
        bool isCop)
{
  Scaleform::GFx::Movie *pObject; // rdi
  char *mData; // rbx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-98h] BYREF
  char v11[16]; // [rsp+60h] [rbp-68h] BYREF
  __int64 v12; // [rsp+70h] [rbp-58h]
  int v13; // [rsp+78h] [rbp-50h]
  __int64 v14; // [rsp+80h] [rbp-48h]
  UFG::qString v15; // [rsp+90h] [rbp-38h] BYREF
  __int64 v16; // [rsp+B8h] [rbp-10h]

  if ( pScreen )
  {
    v16 = -2i64;
    pObject = pScreen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      UFG::qString::qString(&v15);
      if ( maxProgress )
        UFG::qString::Format(&v15, "%s %d/%d", caption, progress, maxProgress);
      else
        UFG::qString::Set(&v15, caption);
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      mData = v15.mData;
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
      if ( (v13 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v12 + 16i64))(v12, v11, v14);
        v12 = 0i64;
      }
      v13 = 2;
      LOBYTE(v14) = isCop;
      Scaleform::GFx::Movie::Invoke(pObject, "SecondaryObjective_Show", 0i64, &ptr, 2u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      UFG::qString::~qString(&v15);
    }
  }
}

// File Line: 198
// RVA: 0x5DBDA0
void __fastcall UFG::UIHKSecondaryObjectivesWidget::Flash_HideObjective(
        UFG::UIHKSecondaryObjectivesWidget *this,
        UFG::UIScreen *pScreen,
        bool isCop)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  if ( pScreen )
  {
    pObject = pScreen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (pargs.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = VT_Boolean;
      pargs.mValue.BValue = isCop;
      Scaleform::GFx::Movie::Invoke(pObject, "SecondaryObjective_Hide", 0i64, &pargs, 1u);
      `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

