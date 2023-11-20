// File Line: 23
// RVA: 0x5C8810
void __fastcall UFG::UIHK_XPFlasherWidget::UIHK_XPFlasherWidget(UFG::UIHK_XPFlasherWidget *this)
{
  UFG::UIHK_XPFlasherWidget *v1; // rsi
  signed __int64 v2; // rdi
  signed __int64 v3; // rbx

  v1 = this;
  *(_QWORD *)&this->mState = 0i64;
  v2 = 3i64;
  `eh vector constructor iterator(
    this->mData,
    0x40ui64,
    3,
    (void (__fastcall *)(void *))UFG::UIHK_XPFlasherData::UIHK_XPFlasherData);
  v3 = (signed __int64)&v1->mData[0].Caption;
  do
  {
    *(_QWORD *)(v3 - 16) = 0i64;
    UFG::qString::Set((UFG::qString *)v3, &customWorldMapCaption);
    *(_BYTE *)(v3 + 40) = 0;
    v3 += 64i64;
    --v2;
  }
  while ( v2 );
}

// File Line: 57
// RVA: 0x619A50
void __fastcall UFG::UIHK_XPFlasherWidget::Update(UFG::UIHK_XPFlasherWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIScreen *v3; // rbp
  UFG::UIHK_XPFlasherWidget *v4; // rbx
  unsigned int v5; // esi
  __int64 v6; // rdi
  const char *v7; // r9
  int v8; // er8
  signed __int64 v9; // rbx
  signed __int64 v10; // rdi

  v3 = screen;
  v4 = this;
  v5 = 0;
  v6 = 0i64;
  this->mStateElapsed = elapsed + this->mStateElapsed;
  do
  {
    v4->mData[v6].ChainMaxTimer = elapsed + v4->mData[v6].ChainMaxTimer;
    if ( v4->mData[v6].Changed )
    {
      v4->mData[v6].Changed = 0;
      if ( v4->mState != 2 )
        *(_QWORD *)&v4->mState = 2i64;
      v7 = v4->mData[v6].Caption.mData;
      v8 = v4->mData[v6].Total;
      if ( v5 == 1 )
        UFG::UIHK_XPFlasherWidget::Flash_ShowCopXP(v4, v3, v8, v7);
      else
        UFG::UIHK_XPFlasherWidget::Flash_ShowTriadXP(v4, v3, v8, v7);
    }
    ++v5;
    ++v6;
  }
  while ( v5 < 3 );
  if ( v4->mState == 2 && v4->mStateElapsed > 2.0 )
  {
    *(_QWORD *)&v4->mState = 1i64;
    UFG::UIHK_XPFlasherWidget::Flash_HideCopXP(v4, v3);
    UFG::UIHK_XPFlasherWidget::Flash_HideTriadXP(v4, v3);
    v9 = (signed __int64)&v4->mData[0].Caption;
    v10 = 3i64;
    do
    {
      *(_QWORD *)(v9 - 16) = 0i64;
      UFG::qString::Set((UFG::qString *)v9, &customWorldMapCaption);
      *(_BYTE *)(v9 + 40) = 0;
      v9 += 64i64;
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 109
// RVA: 0x5D3150
void __fastcall UFG::UIHK_XPFlasherWidget::AddXP(UFG::UIHK_XPFlasherWidget *this, int points, UFG::UIHK_XPFlasherWidget::eXPTypes type, const char *caption)
{
  UFG::UIHK_XPFlasherWidget *v4; // rbx
  signed __int64 v5; // rax

  v4 = this;
  v5 = (signed __int64)(signed int)type << 6;
  *(int *)((char *)&this->mData[0].Total + v5) += points;
  *(&this->mData[0].Changed + v5) = 1;
  if ( points >= *(int *)((char *)&this->mData[0].ChainMax + v5)
    || *(float *)((char *)&this->mData[0].ChainMaxTimer + v5) > 1.0 )
  {
    *(int *)((char *)&this->mData[0].ChainMax + v5) = points;
    *(float *)((char *)&this->mData[0].ChainMaxTimer + v5) = 0.0;
    UFG::qString::Set((UFG::qString *)((char *)&this->mData[0].Caption + v5), caption);
  }
  if ( v4->mState == 2 )
    v4->mStateElapsed = 0.0;
}

// File Line: 138
// RVA: 0x5E4670
void __fastcall UFG::UIHK_XPFlasherWidget::Flash_ShowCopXP(UFG::UIHK_XPFlasherWidget *this, UFG::UIScreen *screen, int points, const char *caption)
{
  const char *v4; // rdi
  int v5; // ebx
  Scaleform::GFx::Movie *v6; // rsi
  float v7; // xmm6_4
  char ptr; // [rsp+28h] [rbp-59h]
  __int64 v9; // [rsp+38h] [rbp-49h]
  unsigned int v10; // [rsp+40h] [rbp-41h]
  double v11; // [rsp+48h] [rbp-39h]
  char v12; // [rsp+58h] [rbp-29h]
  __int64 v13; // [rsp+68h] [rbp-19h]
  unsigned int v14; // [rsp+70h] [rbp-11h]
  const char *v15; // [rsp+78h] [rbp-9h]
  char v16; // [rsp+88h] [rbp+7h]
  __int64 v17; // [rsp+98h] [rbp+17h]
  unsigned int v18; // [rsp+A0h] [rbp+1Fh]
  double v19; // [rsp+A8h] [rbp+27h]
  __int64 v20; // [rsp+B8h] [rbp+37h]

  v20 = -2i64;
  v4 = caption;
  v5 = points;
  v6 = screen->mRenderable->m_movie.pObject;
  v7 = UFG::GameStatAction::MissionScoring::GetCopScorePercentage();
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v10 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, &ptr, COERCE_DOUBLE(*(_QWORD *)&v11));
    v9 = 0i64;
  }
  v10 = 5;
  v11 = (double)v5;
  if ( (v14 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v13 + 16i64))(v13, &v12, v15);
    v13 = 0i64;
  }
  v14 = 6;
  v15 = v4;
  if ( (v18 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v17 + 16i64))(
      v17,
      &v16,
      COERCE_DOUBLE(*(_QWORD *)&v19));
    v17 = 0i64;
  }
  v18 = 5;
  v19 = v7;
  Scaleform::GFx::Movie::Invoke(v6, "XPFlasher_ShowCopXP", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 154
// RVA: 0x5E4E40
void __fastcall UFG::UIHK_XPFlasherWidget::Flash_ShowTriadXP(UFG::UIHK_XPFlasherWidget *this, UFG::UIScreen *screen, int points, const char *caption)
{
  const char *v4; // rdi
  int v5; // ebx
  Scaleform::GFx::Movie *v6; // rsi
  float v7; // xmm6_4
  char ptr; // [rsp+28h] [rbp-59h]
  __int64 v9; // [rsp+38h] [rbp-49h]
  unsigned int v10; // [rsp+40h] [rbp-41h]
  double v11; // [rsp+48h] [rbp-39h]
  char v12; // [rsp+58h] [rbp-29h]
  __int64 v13; // [rsp+68h] [rbp-19h]
  unsigned int v14; // [rsp+70h] [rbp-11h]
  const char *v15; // [rsp+78h] [rbp-9h]
  char v16; // [rsp+88h] [rbp+7h]
  __int64 v17; // [rsp+98h] [rbp+17h]
  unsigned int v18; // [rsp+A0h] [rbp+1Fh]
  double v19; // [rsp+A8h] [rbp+27h]
  __int64 v20; // [rsp+B8h] [rbp+37h]

  v20 = -2i64;
  v4 = caption;
  v5 = points;
  v6 = screen->mRenderable->m_movie.pObject;
  v7 = UFG::GameStatAction::MissionScoring::GetTriadScorePercentage();
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v10 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, &ptr, COERCE_DOUBLE(*(_QWORD *)&v11));
    v9 = 0i64;
  }
  v10 = 5;
  v11 = (double)v5;
  if ( (v14 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v13 + 16i64))(v13, &v12, v15);
    v13 = 0i64;
  }
  v14 = 6;
  v15 = v4;
  if ( (v18 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v17 + 16i64))(
      v17,
      &v16,
      COERCE_DOUBLE(*(_QWORD *)&v19));
    v17 = 0i64;
  }
  v18 = 5;
  v19 = v7;
  Scaleform::GFx::Movie::Invoke(v6, "XPFlasher_ShowTriadXP", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 170
// RVA: 0x5DBCF0
void __fastcall UFG::UIHK_XPFlasherWidget::Flash_HideCopXP(UFG::UIHK_XPFlasherWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v2 = screen->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = 2;
  value.mValue.BValue = 0;
  Scaleform::GFx::Movie::SetVariable(v2, "mc_xpFlasher.mc_police._visible", &value, 1i64);
  if ( ((unsigned int)value.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
}

// File Line: 180
// RVA: 0x5DBEC0
void __fastcall UFG::UIHK_XPFlasherWidget::Flash_HideTriadXP(UFG::UIHK_XPFlasherWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v2 = screen->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = 2;
  value.mValue.BValue = 0;
  Scaleform::GFx::Movie::SetVariable(v2, "mc_xpFlasher.mc_triad._visible", &value, 1i64);
  if ( ((unsigned int)value.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
}

