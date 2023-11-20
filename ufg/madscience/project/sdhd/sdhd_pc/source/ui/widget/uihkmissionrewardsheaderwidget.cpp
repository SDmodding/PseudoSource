// File Line: 16
// RVA: 0x1566CD0
__int64 dynamic_initializer_for__UFG::UIHKMissionRewardsHeaderWidget::Title__()
{
  UFG::qString::qString(&UFG::UIHKMissionRewardsHeaderWidget::Title);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKMissionRewardsHeaderWidget::Title__);
}

// File Line: 17
// RVA: 0x1566AB0
__int64 dynamic_initializer_for__UFG::UIHKMissionRewardsHeaderWidget::Caption__()
{
  UFG::qString::qString(&UFG::UIHKMissionRewardsHeaderWidget::Caption);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKMissionRewardsHeaderWidget::Caption__);
}

// File Line: 18
// RVA: 0x1566B60
__int64 dynamic_initializer_for__UFG::UIHKMissionRewardsHeaderWidget::GamesliceType__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKMissionRewardsHeaderWidget::GamesliceType__);
}

// File Line: 29
// RVA: 0x5C9910
void __fastcall UFG::UIHKMissionRewardsHeaderWidget::~UIHKMissionRewardsHeaderWidget(UFG::UIHKMissionRewardsHeaderWidget *this)
{
  this->vfptr = (UFG::UIHKMissionRewardsHeaderWidgetVtbl *)&UFG::UIHKMissionRewardsHeaderWidget::`vftable';
}

// File Line: 34
// RVA: 0x5EBE30
void __fastcall UFG::UIHKMissionRewardsHeaderWidget::HandleScreenInit(UFG::UIHKMissionRewardsHeaderWidget *this, UFG::UIScreen *screen)
{
  this->mState = 0;
}

// File Line: 40
// RVA: 0x614F90
void __fastcall UFG::UIHKMissionRewardsHeaderWidget::Update(UFG::UIHKMissionRewardsHeaderWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIHKMissionRewardsHeaderWidget *v3; // rbx
  __int32 v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  Scaleform::GFx::Movie *v8; // rcx
  float v9; // xmm2_4
  float v10; // xmm2_4
  bool v11; // cf
  bool v12; // zf
  Scaleform::GFx::Movie *v13; // rcx
  float v14; // xmm2_4
  Scaleform::GFx::Movie *v15; // rcx

  v3 = this;
  v4 = this->mState - 3;
  if ( v4 )
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 && (v7 = v6 - 1) != 0 )
      {
        if ( v7 == 1 )
        {
          v8 = screen->mRenderable->m_movie.pObject;
          if ( v8 )
            Scaleform::GFx::Movie::Invoke(v8, "MissionRewards_UnloadHeader", 0i64, 0i64, 0);
          v3->mState = 0;
        }
      }
      else
      {
        v9 = elapsed + v3->mTimer;
        v3->mTimer = v9;
        if ( v9 > 20.0 )
          v3->mState = 7;
      }
    }
    else
    {
      v10 = elapsed + v3->mTimer;
      v11 = v10 < v3->Duration;
      v12 = v10 == v3->Duration;
      v3->mTimer = v10;
      if ( !v11 && !v12 )
      {
        v13 = screen->mRenderable->m_movie.pObject;
        if ( v13 )
          Scaleform::GFx::Movie::Invoke(v13, "hideFaceLevelUp", 0i64, 0i64, 0);
        v3->mState = 6;
      }
    }
  }
  else
  {
    v14 = elapsed + v3->mTimer;
    v11 = v14 < v3->Duration;
    v12 = v14 == v3->Duration;
    v3->mTimer = v14;
    if ( !v11 && !v12 )
    {
      v15 = screen->mRenderable->m_movie.pObject;
      if ( v15 )
        Scaleform::GFx::Movie::Invoke(v15, "hideMissionComplete", 0i64, 0i64, 0);
      v3->mState = 5;
    }
  }
}

// File Line: 106
// RVA: 0x5EABD0
void __fastcall UFG::UIHKMissionRewardsHeaderWidget::HandleMessage(UFG::UIHKMissionRewardsHeaderWidget *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIHKMissionRewardsHeaderWidget *v4; // rbx
  Scaleform::GFx::Movie *v5; // rcx

  v4 = this;
  switch ( this->mState )
  {
    case 1:
      if ( msgId == UI_HASH_WIDGET_LOADED_20 )
      {
        UFG::UIHKMissionRewardsHeaderWidget::Flash_Show(this, screen);
        v4->mState = 3;
      }
      break;
    case 2:
      if ( msgId == UI_HASH_WIDGET_LOADED_20 )
      {
        v5 = screen->mRenderable->m_movie.pObject;
        if ( v5 )
          Scaleform::GFx::Movie::Invoke(v5, "showFaceLevelUp", 0i64, 0i64, 0);
        v4->mState = 4;
      }
      break;
    case 5:
      if ( msgId == UI_HASH_REWARDS_COMPLETE_MSG_OUTRO_DONE_20 )
        this->mState = 7;
      break;
    default:
      if ( this->mState == 6 && msgId == UI_HASH_FACE_LEVELUP_MSG_OUTRO_DONE_20 )
        this->mState = 7;
      break;
  }
}

// File Line: 151
// RVA: 0x611D60
void __fastcall UFG::UIHKMissionRewardsHeaderWidget::Start(UFG::UIHKMissionRewardsHeaderWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKMissionRewardsHeaderWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // rcx

  v2 = this;
  if ( this->mState == STATE_NONE )
  {
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
      Scaleform::GFx::Movie::Invoke(v3, "MissionRewards_LoadHeader", 0i64, 0i64, 0);
    *(_QWORD *)&v2->mState = 1i64;
  }
}

// File Line: 166
// RVA: 0x611E50
void __fastcall UFG::UIHKMissionRewardsHeaderWidget::StartFaceLevelUp(UFG::UIHKMissionRewardsHeaderWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKMissionRewardsHeaderWidget::eState v2; // eax
  UFG::UIHKMissionRewardsHeaderWidget *v3; // rbx
  Scaleform::GFx::Movie *v4; // rcx

  v2 = this->mState;
  v3 = this;
  if ( v2 == STATE_NONE || v2 == 7 )
  {
    v4 = screen->mRenderable->m_movie.pObject;
    if ( v4 )
      Scaleform::GFx::Movie::Invoke(v4, "MissionRewards_LoadHeader", 0i64, 0i64, 0);
    *(_QWORD *)&v3->mState = 2i64;
  }
}

// File Line: 208
// RVA: 0x5E3140
void __fastcall UFG::UIHKMissionRewardsHeaderWidget::Flash_Show(UFG::UIHKMissionRewardsHeaderWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rbx
  char *v3; // rdi
  char *v4; // rdi
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h]
  char v6; // [rsp+70h] [rbp-38h]
  __int64 v7; // [rsp+80h] [rbp-28h]
  unsigned int v8; // [rsp+88h] [rbp-20h]
  char *v9; // [rsp+90h] [rbp-18h]

  v2 = screen->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    `eh vector constructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v3 = UFG::UIHKMissionRewardsHeaderWidget::Caption.mData;
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = v3;
    v4 = UFG::UIHKMissionRewardsHeaderWidget::Title.mData;
    if ( (v8 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v7 + 16i64))(v7, &v6, v9);
      v7 = 0i64;
    }
    v8 = 6;
    v9 = v4;
    Scaleform::GFx::Movie::Invoke(v2, "showMissionComplete", 0i64, &pargs, 2u);
    if ( UFG::UIHKMissionRewardsHeaderWidget::GamesliceType.mUID == qSymbol_Mission_20.mUID )
      UFG::TiDo::GetIsInstantiated();
    `eh vector destructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

