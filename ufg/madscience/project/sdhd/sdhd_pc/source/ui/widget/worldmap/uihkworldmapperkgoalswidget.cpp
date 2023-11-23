// File Line: 47
// RVA: 0x612C10
void __fastcall UFG::UIHKWorldMapPerkGoalsWidget::ToggleOpen(
        UFG::UIHKWorldMapPerkGoalsWidget *this,
        UFG::UIScreen *screen)
{
  UFG::UIHKWorldMapPerkGoalsWidget::eState mState; // eax
  Scaleform::GFx::Movie *v4; // rcx
  Scaleform::GFx::Movie *pObject; // rcx

  if ( !this->mbToggleDisabled )
  {
    mState = this->mState;
    if ( this->mState < (unsigned int)STATE_DANGER )
    {
      this->mState = STATE_DANGER;
      pObject = screen->mRenderable->m_movie.pObject;
      if ( pObject )
        Scaleform::GFx::Movie::Invoke(pObject, "PerkGoals_Hide", 0i64, 0i64, 0);
    }
    else if ( mState == STATE_COMPLETE || mState == STATE_DANGER )
    {
      this->mState = STATE_INVALID;
      v4 = screen->mRenderable->m_movie.pObject;
      if ( v4 )
        Scaleform::GFx::Movie::Invoke(v4, "PerkGoals_Show", 0i64, 0i64, 0);
      *(_WORD *)&this->mbIsHiding = 0;
    }
  }
}

// File Line: 101
// RVA: 0x6130C0
void __fastcall UFG::UIHKWorldMapPerkGoalsWidget::UnHide(UFG::UIHKWorldMapPerkGoalsWidget *this, UFG::UIScreen *screen)
{
  bool v2; // zf
  UFG::UIHKWorldMapPerkGoalsWidget::eState mState; // eax
  Scaleform::GFx::Movie *pObject; // rcx

  v2 = !this->mbIsHiding;
  this->mbToggleDisabled = 0;
  if ( !v2 )
  {
    mState = this->mState;
    this->mbIsHiding = 0;
    if ( (unsigned int)(mState - 2) <= 1 )
    {
      this->mState = STATE_INVALID;
      pObject = screen->mRenderable->m_movie.pObject;
      if ( pObject )
        Scaleform::GFx::Movie::Invoke(pObject, "PerkGoals_Show", 0i64, 0i64, 0);
    }
    *(_WORD *)&this->mbIsHiding = 0;
  }
}

// File Line: 147
// RVA: 0x5D91F0
void __fastcall UFG::UIHKWorldMapPerkGoalsWidget::Flash_AddGoal(
        UFG::UIHKWorldMapPerkGoalsWidget *this,
        UFG::UIScreen *screen,
        const char *name,
        bool completed)
{
  const char *v5; // rbx
  Scaleform::GFx::Movie *pObject; // r14
  Scaleform::GFx::Value::ValueUnion v7; // rdi
  __int64 v8; // rdx
  UFG::UIGfxTranslator *m_translator; // rcx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-B8h] BYREF
  char v11[8]; // [rsp+60h] [rbp-88h] BYREF
  __int64 v12; // [rsp+68h] [rbp-80h]
  __int64 v13; // [rsp+70h] [rbp-78h]
  int v14[4]; // [rsp+78h] [rbp-70h] BYREF
  __int64 v15; // [rsp+88h] [rbp-60h]
  int v16; // [rsp+90h] [rbp-58h]
  __int64 v17; // [rsp+98h] [rbp-50h]
  char v18[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v19; // [rsp+B8h] [rbp-30h]
  int v20; // [rsp+C0h] [rbp-28h]
  double v21; // [rsp+C8h] [rbp-20h]
  char v22[16]; // [rsp+D8h] [rbp-10h] BYREF
  __int64 v23; // [rsp+E8h] [rbp+0h]
  int v24; // [rsp+F0h] [rbp+8h]
  double v25; // [rsp+F8h] [rbp+10h]
  __int64 v26; // [rsp+108h] [rbp+20h]
  char v27; // [rsp+158h] [rbp+70h]
  int v28; // [rsp+160h] [rbp+78h]
  int v29; // [rsp+168h] [rbp+80h]

  v26 = -2i64;
  v5 = name;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    if ( name )
    {
      if ( *name == 36 )
        v5 = name + 1;
      v8 = (unsigned int)UFG::qStringHashUpper32(v5, -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v7.pString = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v8)) == 0i64 )
        v7.pString = v5;
    }
    else
    {
      v7.pString = 0i64;
    }
    `eh vector constructor iterator(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_String;
    ptr.mValue = v7;
    if ( (v14[0] & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v13 + 16i64))(v13, v11, v12);
      v13 = 0i64;
    }
    v14[0] = 2;
    LOBYTE(v12) = completed;
    if ( (v16 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v15 + 16i64))(v15, v14, v17);
      v15 = 0i64;
    }
    v16 = 2;
    LOBYTE(v17) = v27;
    if ( (v20 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v19 + 16i64))(
        v19,
        v18,
        COERCE_DOUBLE(*(_QWORD *)&v21));
      v19 = 0i64;
    }
    v20 = 5;
    v21 = (double)v28;
    if ( (v24 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v23 + 16i64))(
        v23,
        v22,
        COERCE_DOUBLE(*(_QWORD *)&v25));
      v23 = 0i64;
    }
    v24 = 5;
    v25 = (double)v29;
    Scaleform::GFx::Movie::Invoke(pObject, "PerkGoals_AddGoal", 0i64, &ptr, 5u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

