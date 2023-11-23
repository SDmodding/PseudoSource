// File Line: 16
// RVA: 0x1566CD0
__int64 dynamic_initializer_for__UFG::UIHKMissionRewardsHeaderWidget::Title__()
{
  UFG::qString::qString(&UFG::UIHKMissionRewardsHeaderWidget::Title);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKMissionRewardsHeaderWidget::Title__);
}

// File Line: 17
// RVA: 0x1566AB0
__int64 dynamic_initializer_for__UFG::UIHKMissionRewardsHeaderWidget::Caption__()
{
  UFG::qString::qString(&UFG::UIHKMissionRewardsHeaderWidget::Caption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKMissionRewardsHeaderWidget::Caption__);
}

// File Line: 18
// RVA: 0x1566B60
__int64 dynamic_initializer_for__UFG::UIHKMissionRewardsHeaderWidget::GamesliceType__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKMissionRewardsHeaderWidget::GamesliceType__);
}

// File Line: 29
// RVA: 0x5C9910
void __fastcall UFG::UIHKMissionRewardsHeaderWidget::~UIHKMissionRewardsHeaderWidget(
        UFG::UIHKMissionRewardsHeaderWidget *this)
{
  this->vfptr = (UFG::UIHKMissionRewardsHeaderWidgetVtbl *)&UFG::UIHKMissionRewardsHeaderWidget::`vftable;
}

// File Line: 34
// RVA: 0x5EBE30
void __fastcall UFG::UIHKMissionRewardsHeaderWidget::HandleScreenInit(
        UFG::UIHKMissionRewardsHeaderWidget *this,
        UFG::UIScreen *screen)
{
  this->mState = STATE_NONE;
}

// File Line: 40
// RVA: 0x614F90
void __fastcall UFG::UIHKMissionRewardsHeaderWidget::Update(
        UFG::UIHKMissionRewardsHeaderWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  __int32 v4; // ecx
  __int32 v5; // ecx
  __int32 v6; // ecx
  __int32 v7; // ecx
  Scaleform::GFx::Movie *pObject; // rcx
  float v9; // xmm2_4
  float v10; // xmm2_4
  bool v11; // cc
  Scaleform::GFx::Movie *v12; // rcx
  float v13; // xmm2_4
  Scaleform::GFx::Movie *v14; // rcx

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
          pObject = screen->mRenderable->m_movie.pObject;
          if ( pObject )
            Scaleform::GFx::Movie::Invoke(pObject, "MissionRewards_UnloadHeader", 0i64, 0i64, 0);
          this->mState = STATE_NONE;
        }
      }
      else
      {
        v9 = elapsed + this->mTimer;
        this->mTimer = v9;
        if ( v9 > 20.0 )
          this->mState = STATE_SYNCED|STATE_WAITING;
      }
    }
    else
    {
      v10 = elapsed + this->mTimer;
      v11 = v10 <= this->Duration;
      this->mTimer = v10;
      if ( !v11 )
      {
        v12 = screen->mRenderable->m_movie.pObject;
        if ( v12 )
          Scaleform::GFx::Movie::Invoke(v12, "hideFaceLevelUp", 0i64, 0i64, 0);
        this->mState = STATE_DONE|STATE_WAITING;
      }
    }
  }
  else
  {
    v13 = elapsed + this->mTimer;
    v11 = v13 <= this->Duration;
    this->mTimer = v13;
    if ( !v11 )
    {
      v14 = screen->mRenderable->m_movie.pObject;
      if ( v14 )
        Scaleform::GFx::Movie::Invoke(v14, "hideMissionComplete", 0i64, 0i64, 0);
      this->mState = STATE_SYNCED;
    }
  }
}

// File Line: 106
// RVA: 0x5EABD0
void __fastcall UFG::UIHKMissionRewardsHeaderWidget::HandleMessage(
        UFG::UIHKMissionRewardsHeaderWidget *this,
        UFG::UIScreen *screen,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  Scaleform::GFx::Movie *pObject; // rcx

  switch ( this->mState )
  {
    case STATE_QUEUED:
      if ( msgId == UI_HASH_WIDGET_LOADED_20 )
      {
        UFG::UIHKMissionRewardsHeaderWidget::Flash_Show(this, screen);
        this->mState = STATE_EXECUTING;
      }
      break;
    case STATE_WAITING:
      if ( msgId == UI_HASH_WIDGET_LOADED_20 )
      {
        pObject = screen->mRenderable->m_movie.pObject;
        if ( pObject )
          Scaleform::GFx::Movie::Invoke(pObject, "showFaceLevelUp", 0i64, 0i64, 0);
        this->mState = STATE_DONE;
      }
      break;
    case STATE_SYNCED:
      if ( msgId == UI_HASH_REWARDS_COMPLETE_MSG_OUTRO_DONE_20 )
        this->mState = STATE_SYNCED|STATE_WAITING;
      break;
    default:
      if ( this->mState == (STATE_DONE|STATE_WAITING) && msgId == UI_HASH_FACE_LEVELUP_MSG_OUTRO_DONE_20 )
        this->mState = STATE_SYNCED|STATE_WAITING;
      break;
  }
}

// File Line: 151
// RVA: 0x611D60
void __fastcall UFG::UIHKMissionRewardsHeaderWidget::Start(
        UFG::UIHKMissionRewardsHeaderWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx

  if ( this->mState == STATE_NONE )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
      Scaleform::GFx::Movie::Invoke(pObject, "MissionRewards_LoadHeader", 0i64, 0i64, 0);
    *(_QWORD *)&this->mState = 1i64;
  }
}

// File Line: 166
// RVA: 0x611E50
void __fastcall UFG::UIHKMissionRewardsHeaderWidget::StartFaceLevelUp(
        UFG::UIHKMissionRewardsHeaderWidget *this,
        UFG::UIScreen *screen)
{
  UFG::UIHKMissionRewardsHeaderWidget::eState mState; // eax
  Scaleform::GFx::Movie *pObject; // rcx

  mState = this->mState;
  if ( mState == STATE_NONE || mState == (STATE_SYNCED|STATE_WAITING) )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
      Scaleform::GFx::Movie::Invoke(pObject, "MissionRewards_LoadHeader", 0i64, 0i64, 0);
    *(_QWORD *)&this->mState = 2i64;
  }
}

// File Line: 208
// RVA: 0x5E3140
void __fastcall UFG::UIHKMissionRewardsHeaderWidget::Flash_Show(
        UFG::UIHKMissionRewardsHeaderWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  char *mData; // rdi
  char *v4; // rdi
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h] BYREF
  char v6[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v7; // [rsp+80h] [rbp-28h]
  int v8; // [rsp+88h] [rbp-20h]
  char *v9; // [rsp+90h] [rbp-18h]

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    mData = UFG::UIHKMissionRewardsHeaderWidget::Caption.mData;
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_String;
    pargs.mValue.pString = mData;
    v4 = UFG::UIHKMissionRewardsHeaderWidget::Title.mData;
    if ( (v8 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v7 + 16i64))(v7, v6, v9);
      v7 = 0i64;
    }
    v8 = 6;
    v9 = v4;
    Scaleform::GFx::Movie::Invoke(pObject, "showMissionComplete", 0i64, &pargs, 2u);
    if ( UFG::UIHKMissionRewardsHeaderWidget::GamesliceType.mUID == qSymbol_Mission_20.mUID )
      UFG::TiDo::GetIsInstantiated();
    `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

