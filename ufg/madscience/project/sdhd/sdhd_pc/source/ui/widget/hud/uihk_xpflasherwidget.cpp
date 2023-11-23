// File Line: 23
// RVA: 0x5C8810
void __fastcall UFG::UIHK_XPFlasherWidget::UIHK_XPFlasherWidget(UFG::UIHK_XPFlasherWidget *this)
{
  __int64 v2; // rdi
  UFG::qString *p_Caption; // rbx

  *(_QWORD *)&this->mState = 0i64;
  v2 = 3i64;
  `eh vector constructor iterator(
    this->mData,
    0x40ui64,
    3,
    (void (__fastcall *)(void *))UFG::UIHK_XPFlasherData::UIHK_XPFlasherData);
  p_Caption = &this->mData[0].Caption;
  do
  {
    p_Caption[-1].mData = 0i64;
    UFG::qString::Set(p_Caption, &customCaption);
    LOBYTE(p_Caption[1].mPrev) = 0;
    p_Caption = (UFG::qString *)((char *)p_Caption + 64);
    --v2;
  }
  while ( v2 );
}

// File Line: 57
// RVA: 0x619A50
void __fastcall UFG::UIHK_XPFlasherWidget::Update(
        UFG::UIHK_XPFlasherWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  unsigned int v5; // esi
  __int64 v6; // rdi
  char *mData; // r9
  int Total; // r8d
  UFG::qString *p_Caption; // rbx
  __int64 v10; // rdi

  v5 = 0;
  v6 = 0i64;
  this->mStateElapsed = elapsed + this->mStateElapsed;
  do
  {
    this->mData[v6].ChainMaxTimer = elapsed + this->mData[v6].ChainMaxTimer;
    if ( this->mData[v6].Changed )
    {
      this->mData[v6].Changed = 0;
      if ( this->mState != STATE_PHONE_CONTACTS )
        *(_QWORD *)&this->mState = 2i64;
      mData = this->mData[v6].Caption.mData;
      Total = this->mData[v6].Total;
      if ( v5 == 1 )
        UFG::UIHK_XPFlasherWidget::Flash_ShowCopXP(this, screen, Total, mData);
      else
        UFG::UIHK_XPFlasherWidget::Flash_ShowTriadXP(this, screen, Total, mData);
    }
    ++v5;
    ++v6;
  }
  while ( v5 < 3 );
  if ( this->mState == STATE_PHONE_CONTACTS && this->mStateElapsed > 2.0 )
  {
    *(_QWORD *)&this->mState = 1i64;
    UFG::UIHK_XPFlasherWidget::Flash_HideCopXP(this, screen);
    UFG::UIHK_XPFlasherWidget::Flash_HideTriadXP(this, screen);
    p_Caption = &this->mData[0].Caption;
    v10 = 3i64;
    do
    {
      p_Caption[-1].mData = 0i64;
      UFG::qString::Set(p_Caption, &customCaption);
      LOBYTE(p_Caption[1].mPrev) = 0;
      p_Caption = (UFG::qString *)((char *)p_Caption + 64);
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 109
// RVA: 0x5D3150
void __fastcall UFG::UIHK_XPFlasherWidget::AddXP(
        UFG::UIHK_XPFlasherWidget *this,
        int points,
        int type,
        const char *caption)
{
  __int64 v5; // rax

  v5 = (__int64)type << 6;
  *(int *)((char *)&this->mData[0].Total + v5) += points;
  *(&this->mData[0].Changed + v5) = 1;
  if ( points >= *(int *)((char *)&this->mData[0].ChainMax + v5)
    || *(float *)((char *)&this->mData[0].ChainMaxTimer + v5) > 1.0 )
  {
    *(int *)((char *)&this->mData[0].ChainMax + v5) = points;
    *(float *)((char *)&this->mData[0].ChainMaxTimer + v5) = 0.0;
    UFG::qString::Set((UFG::qString *)((char *)&this->mData[0].Caption + v5), caption);
  }
  if ( this->mState == STATE_PHONE_CONTACTS )
    this->mStateElapsed = 0.0;
}

// File Line: 138
// RVA: 0x5E4670
void __fastcall UFG::UIHK_XPFlasherWidget::Flash_ShowCopXP(
        UFG::UIHK_XPFlasherWidget *this,
        UFG::UIScreen *screen,
        int points,
        const char *caption)
{
  Scaleform::GFx::Movie *pObject; // rsi
  float CopScorePercentage; // xmm6_4
  Scaleform::GFx::Value ptr; // [rsp+28h] [rbp-59h] BYREF
  char v9[16]; // [rsp+58h] [rbp-29h] BYREF
  __int64 v10; // [rsp+68h] [rbp-19h]
  int v11; // [rsp+70h] [rbp-11h]
  const char *v12; // [rsp+78h] [rbp-9h]
  char v13[16]; // [rsp+88h] [rbp+7h] BYREF
  __int64 v14; // [rsp+98h] [rbp+17h]
  int v15; // [rsp+A0h] [rbp+1Fh]
  double v16; // [rsp+A8h] [rbp+27h]
  __int64 v17; // [rsp+B8h] [rbp+37h]

  v17 = -2i64;
  pObject = screen->mRenderable->m_movie.pObject;
  CopScorePercentage = UFG::GameStatAction::MissionScoring::GetCopScorePercentage();
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  ptr.mValue.NValue = (double)points;
  if ( (v11 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v10 + 16i64))(v10, v9, v12);
    v10 = 0i64;
  }
  v11 = 6;
  v12 = caption;
  if ( (v15 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v14 + 16i64))(v14, v13, COERCE_DOUBLE(*(_QWORD *)&v16));
    v14 = 0i64;
  }
  v15 = 5;
  v16 = CopScorePercentage;
  Scaleform::GFx::Movie::Invoke(pObject, "XPFlasher_ShowCopXP", 0i64, &ptr, 3u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 154
// RVA: 0x5E4E40
void __fastcall UFG::UIHK_XPFlasherWidget::Flash_ShowTriadXP(
        UFG::UIHK_XPFlasherWidget *this,
        UFG::UIScreen *screen,
        int points,
        const char *caption)
{
  Scaleform::GFx::Movie *pObject; // rsi
  float TriadScorePercentage; // xmm6_4
  Scaleform::GFx::Value ptr; // [rsp+28h] [rbp-59h] BYREF
  char v9[16]; // [rsp+58h] [rbp-29h] BYREF
  __int64 v10; // [rsp+68h] [rbp-19h]
  int v11; // [rsp+70h] [rbp-11h]
  const char *v12; // [rsp+78h] [rbp-9h]
  char v13[16]; // [rsp+88h] [rbp+7h] BYREF
  __int64 v14; // [rsp+98h] [rbp+17h]
  int v15; // [rsp+A0h] [rbp+1Fh]
  double v16; // [rsp+A8h] [rbp+27h]
  __int64 v17; // [rsp+B8h] [rbp+37h]

  v17 = -2i64;
  pObject = screen->mRenderable->m_movie.pObject;
  TriadScorePercentage = UFG::GameStatAction::MissionScoring::GetTriadScorePercentage();
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  ptr.mValue.NValue = (double)points;
  if ( (v11 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v10 + 16i64))(v10, v9, v12);
    v10 = 0i64;
  }
  v11 = 6;
  v12 = caption;
  if ( (v15 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v14 + 16i64))(v14, v13, COERCE_DOUBLE(*(_QWORD *)&v16));
    v14 = 0i64;
  }
  v15 = 5;
  v16 = TriadScorePercentage;
  Scaleform::GFx::Movie::Invoke(pObject, "XPFlasher_ShowTriadXP", 0i64, &ptr, 3u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 170
// RVA: 0x5DBCF0
void __fastcall UFG::UIHK_XPFlasherWidget::Flash_HideCopXP(UFG::UIHK_XPFlasherWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = VT_Boolean;
  value.mValue.BValue = 0;
  Scaleform::GFx::Movie::SetVariable(pObject, "mc_xpFlasher.mc_police._visible", &value, 1i64);
  if ( (value.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
}

// File Line: 180
// RVA: 0x5DBEC0
void __fastcall UFG::UIHK_XPFlasherWidget::Flash_HideTriadXP(UFG::UIHK_XPFlasherWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = VT_Boolean;
  value.mValue.BValue = 0;
  Scaleform::GFx::Movie::SetVariable(pObject, "mc_xpFlasher.mc_triad._visible", &value, 1i64);
  if ( (value.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
}

