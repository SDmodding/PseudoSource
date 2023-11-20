// File Line: 23
// RVA: 0x5F4A00
void __fastcall UFG::UIHKSecondaryObjective::Populate(UFG::UIHKSecondaryObjective *this, UFG::SecondaryObjective *objective)
{
  UFG::SecondaryObjective *v2; // rdi
  UFG::UIHKSecondaryObjective *v3; // rbx
  unsigned int v4; // eax
  UFG::SecondaryObjective::eStatus v5; // eax
  UFG::SecondaryObjective::eStatus v6; // ecx

  v2 = objective;
  v3 = this;
  if ( *(_QWORD *)&this->Progress != *(_QWORD *)&objective->mProgress
    || (unsigned int)UFG::qStringCompare(this->Caption.mData, objective->mCaption.mData, -1) )
  {
    UFG::qString::Set(&v3->Caption, v2->mCaption.mData, v2->mCaption.mLength, 0i64, 0);
    v3->Progress = v2->mProgress;
    v4 = v2->mMaxProgress;
    v3->CaptionChanged = 1;
    v3->MaxProgress = v4;
  }
  v5 = v2->mStatus;
  v6 = v3->Status;
  v3->Status = v2->mStatus;
  v3->StatusChanged |= v6 != v5;
}

// File Line: 41
// RVA: 0x5C7F30
void __fastcall UFG::UIHKSecondaryObjectivesWidget::UIHKSecondaryObjectivesWidget(UFG::UIHKSecondaryObjectivesWidget *this)
{
  UFG::UIHKSecondaryObjectivesWidget *v1; // rdi
  UFG::UIHKSecondaryObjective *v2; // rbx

  v1 = this;
  v2 = &this->mCopObjective;
  UFG::qString::qString(&this->mCopObjective.Caption);
  *(_WORD *)&v2->CaptionChanged = 0;
  *(_QWORD *)&v2->Progress = 0i64;
  *(_QWORD *)&v2->HideTimer = 0i64;
  UFG::qString::qString(&v1->mTriadObjective.Caption);
  *(_WORD *)&v1->mTriadObjective.CaptionChanged = 0;
  *(_QWORD *)&v1->mTriadObjective.Progress = 0i64;
  *(_QWORD *)&v1->mTriadObjective.HideTimer = 0i64;
  UFG::UIHKSecondaryObjectivesWidget::Refresh(v1);
}

// File Line: 64
// RVA: 0x61B7A0
void __fastcall UFG::UIHKSecondaryObjectivesWidget::UpdateObjective(UFG::UIHKSecondaryObjectivesWidget *this, UFG::UIScreen *pScreen, float elapsed, UFG::UIHKSecondaryObjective *objective, bool isCop)
{
  UFG::UIHKSecondaryObjective *v5; // rbx
  UFG::UIScreen *v6; // rsi
  UFG::UIHKSecondaryObjectivesWidget *v7; // rbp
  UFG::SecondaryObjective::eStatus v8; // er8
  int v9; // er8
  int v10; // er8
  float v11; // xmm1_4
  UFG::SecondaryObjectiveTracker *v12; // rcx
  float v13; // xmm1_4

  v5 = objective;
  v6 = pScreen;
  v7 = this;
  if ( objective->StatusChanged )
  {
    v8 = objective->Status;
    *(_WORD *)&objective->CaptionChanged = 0;
    if ( v8 == STATUS_INACTIVE )
    {
      UFG::UIHKSecondaryObjectivesWidget::Flash_HideObjective(this, pScreen, isCop);
      v5->WidgetState = 0;
      goto LABEL_13;
    }
    v9 = v8 - 1;
    if ( v9 )
    {
      v10 = v9 - 1;
      if ( v10 )
      {
        if ( v10 != 1 )
          goto LABEL_13;
        UFG::UIHKSecondaryObjectivesWidget::Flash_ShowObjective(this, pScreen, "$HUD_FAILED", 0, 0, isCop);
        v5->WidgetState = 3;
      }
      else
      {
        UFG::UIHKSecondaryObjectivesWidget::Flash_ShowObjective(this, pScreen, "$HUD_SUCCESS", 0, 0, isCop);
        v5->WidgetState = 3;
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
  v5->WidgetState = 2;
LABEL_12:
  v5->HideTimer = 10.0;
LABEL_13:
  if ( v5->WidgetState == 2 )
  {
    v13 = v5->HideTimer - elapsed;
    v5->HideTimer = v13;
    if ( v13 <= 0.0 )
    {
      UFG::UIHKSecondaryObjectivesWidget::Flash_HideObjective(v7, v6, isCop);
      v5->WidgetState = 1;
    }
  }
  else if ( v5->WidgetState == 3 )
  {
    v11 = v5->HideTimer - elapsed;
    v5->HideTimer = v11;
    if ( v11 <= 0.0 )
    {
      v12 = &UFG::ProgressionTracker::Instance()->mSecondaryObjectiveTracker;
      if ( isCop )
        UFG::SecondaryObjectiveTracker::RemoveObjective(v12, 0);
      else
        UFG::SecondaryObjectiveTracker::RemoveObjective(v12, ID_TRIAD_OBJECTIVE);
    }
  }
}

// File Line: 158
// RVA: 0x5FFF00
void __fastcall UFG::UIHKSecondaryObjectivesWidget::Refresh(UFG::UIHKSecondaryObjectivesWidget *this)
{
  UFG::UIHKSecondaryObjectivesWidget *v1; // rsi
  UFG::ProgressionTracker *v2; // rbx
  UFG::SecondaryObjective *v3; // rdi
  UFG::SecondaryObjective *v4; // rbx

  v1 = this;
  v2 = UFG::ProgressionTracker::Instance();
  v3 = UFG::SecondaryObjectiveTracker::GetObjective(&v2->mSecondaryObjectiveTracker, 0);
  v4 = UFG::SecondaryObjectiveTracker::GetObjective(&v2->mSecondaryObjectiveTracker, ID_TRIAD_OBJECTIVE);
  UFG::UIHKSecondaryObjective::Populate(&v1->mCopObjective, v3);
  UFG::UIHKSecondaryObjective::Populate(&v1->mTriadObjective, v4);
}

// File Line: 170
// RVA: 0x5E4AD0
void __fastcall UFG::UIHKSecondaryObjectivesWidget::Flash_ShowObjective(UFG::UIHKSecondaryObjectivesWidget *this, UFG::UIScreen *pScreen, const char *caption, unsigned int progress, unsigned int maxProgress, bool isCop)
{
  unsigned int v6; // esi
  const char *v7; // rbx
  Scaleform::GFx::Movie *v8; // rdi
  char *v9; // rbx
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-A8h]
  char ptr; // [rsp+30h] [rbp-98h]
  __int64 v12; // [rsp+40h] [rbp-88h]
  unsigned int v13; // [rsp+48h] [rbp-80h]
  char *v14; // [rsp+50h] [rbp-78h]
  char v15; // [rsp+60h] [rbp-68h]
  __int64 v16; // [rsp+70h] [rbp-58h]
  unsigned int v17; // [rsp+78h] [rbp-50h]
  __int64 v18; // [rsp+80h] [rbp-48h]
  UFG::qString v19; // [rsp+90h] [rbp-38h]
  __int64 v20; // [rsp+B8h] [rbp-10h]

  if ( pScreen )
  {
    v20 = -2i64;
    v6 = progress;
    v7 = caption;
    v8 = pScreen->mRenderable->m_movie.pObject;
    if ( v8 )
    {
      UFG::qString::qString(&v19);
      if ( maxProgress )
      {
        LODWORD(pDtor) = maxProgress;
        UFG::qString::Format(&v19, "%s %d/%d", v7, v6, pDtor);
      }
      else
      {
        UFG::qString::Set(&v19, v7);
      }
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v9 = v19.mData;
      if ( (v13 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v12 + 16i64))(v12, &ptr, v14);
        v12 = 0i64;
      }
      v13 = 6;
      v14 = v9;
      if ( (v17 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, &v15, v18);
        v16 = 0i64;
      }
      v17 = 2;
      LOBYTE(v18) = isCop;
      Scaleform::GFx::Movie::Invoke(v8, "SecondaryObjective_Show", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      UFG::qString::~qString(&v19);
    }
  }
}

// File Line: 198
// RVA: 0x5DBDA0
void __fastcall UFG::UIHKSecondaryObjectivesWidget::Flash_HideObjective(UFG::UIHKSecondaryObjectivesWidget *this, UFG::UIScreen *pScreen, bool isCop)
{
  bool v3; // di
  Scaleform::GFx::Movie *v4; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  if ( pScreen )
  {
    v3 = isCop;
    v4 = pScreen->mRenderable->m_movie.pObject;
    if ( v4 )
    {
      `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = 2;
      pargs.mValue.BValue = v3;
      Scaleform::GFx::Movie::Invoke(v4, "SecondaryObjective_Hide", 0i64, &pargs, 1u);
      `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

