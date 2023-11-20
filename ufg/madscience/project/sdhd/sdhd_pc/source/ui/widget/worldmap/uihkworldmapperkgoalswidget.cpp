// File Line: 47
// RVA: 0x612C10
void __fastcall UFG::UIHKWorldMapPerkGoalsWidget::ToggleOpen(UFG::UIHKWorldMapPerkGoalsWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKWorldMapPerkGoalsWidget *v2; // rbx
  UFG::UIHKWorldMapPerkGoalsWidget::eState v3; // eax
  Scaleform::GFx::Movie *v4; // rcx
  Scaleform::GFx::Movie *v5; // rcx

  v2 = this;
  if ( !this->mbToggleDisabled )
  {
    v3 = this->mState;
    if ( this->mState != 1 && v3 )
    {
      if ( v3 == 3 || v3 == 2 )
      {
        this->mState = 0;
        v4 = screen->mRenderable->m_movie.pObject;
        if ( v4 )
          Scaleform::GFx::Movie::Invoke(v4, "PerkGoals_Show", 0i64, 0i64, 0);
        *(_WORD *)&v2->mbIsHiding = 0;
      }
    }
    else
    {
      this->mState = 2;
      v5 = screen->mRenderable->m_movie.pObject;
      if ( v5 )
        Scaleform::GFx::Movie::Invoke(v5, "PerkGoals_Hide", 0i64, 0i64, 0);
    }
  }
}

// File Line: 101
// RVA: 0x6130C0
void __fastcall UFG::UIHKWorldMapPerkGoalsWidget::UnHide(UFG::UIHKWorldMapPerkGoalsWidget *this, UFG::UIScreen *screen)
{
  bool v2; // zf
  UFG::UIHKWorldMapPerkGoalsWidget *v3; // rbx
  UFG::UIHKWorldMapPerkGoalsWidget::eState v4; // eax
  Scaleform::GFx::Movie *v5; // rcx

  v2 = this->mbIsHiding == 0;
  v3 = this;
  this->mbToggleDisabled = 0;
  if ( !v2 )
  {
    v4 = this->mState;
    this->mbIsHiding = 0;
    if ( (unsigned int)(v4 - 2) <= 1 )
    {
      this->mState = 0;
      v5 = screen->mRenderable->m_movie.pObject;
      if ( v5 )
        Scaleform::GFx::Movie::Invoke(v5, "PerkGoals_Show", 0i64, 0i64, 0);
    }
    *(_WORD *)&v3->mbIsHiding = 0;
  }
}

// File Line: 147
// RVA: 0x5D91F0
void __fastcall UFG::UIHKWorldMapPerkGoalsWidget::Flash_AddGoal(UFG::UIHKWorldMapPerkGoalsWidget *this, UFG::UIScreen *screen, const char *name, bool completed)
{
  bool v4; // si
  const char *v5; // rbx
  Scaleform::GFx::Movie *v6; // r14
  __int64 v7; // rdi
  __int64 v8; // rdx
  UFG::UIGfxTranslator *v9; // rcx
  char ptr; // [rsp+30h] [rbp-B8h]
  __int64 v11; // [rsp+40h] [rbp-A8h]
  unsigned int v12; // [rsp+48h] [rbp-A0h]
  __int64 v13; // [rsp+50h] [rbp-98h]
  char v14; // [rsp+60h] [rbp-88h]
  __int64 v15; // [rsp+68h] [rbp-80h]
  __int64 v16; // [rsp+70h] [rbp-78h]
  unsigned int v17; // [rsp+78h] [rbp-70h]
  __int64 v18; // [rsp+88h] [rbp-60h]
  unsigned int v19; // [rsp+90h] [rbp-58h]
  __int64 v20; // [rsp+98h] [rbp-50h]
  char v21; // [rsp+A8h] [rbp-40h]
  __int64 v22; // [rsp+B8h] [rbp-30h]
  unsigned int v23; // [rsp+C0h] [rbp-28h]
  double v24; // [rsp+C8h] [rbp-20h]
  char v25; // [rsp+D8h] [rbp-10h]
  __int64 v26; // [rsp+E8h] [rbp+0h]
  unsigned int v27; // [rsp+F0h] [rbp+8h]
  double v28; // [rsp+F8h] [rbp+10h]
  __int64 v29; // [rsp+108h] [rbp+20h]
  char v30; // [rsp+158h] [rbp+70h]
  signed int v31; // [rsp+160h] [rbp+78h]
  signed int v32; // [rsp+168h] [rbp+80h]

  v29 = -2i64;
  v4 = completed;
  v5 = name;
  v6 = screen->mRenderable->m_movie.pObject;
  if ( v6 )
  {
    if ( name )
    {
      if ( *name == 36 )
        v5 = name + 1;
      v8 = (unsigned int)UFG::qStringHashUpper32(v5, 0xFFFFFFFF);
      v9 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v9 || (v7 = (__int64)v9->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, v8)) == 0 )
        v7 = (__int64)v5;
    }
    else
    {
      v7 = 0i64;
    }
    `eh vector constructor iterator(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v12 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v13);
      v11 = 0i64;
    }
    v12 = 6;
    v13 = v7;
    if ( (v17 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, &v14, v15);
      v16 = 0i64;
    }
    v17 = 2;
    LOBYTE(v15) = v4;
    if ( (v19 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v18 + 16i64))(v18, &v17, v20);
      v18 = 0i64;
    }
    v19 = 2;
    LOBYTE(v20) = v30;
    if ( (v23 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v22 + 16i64))(
        v22,
        &v21,
        COERCE_DOUBLE(*(_QWORD *)&v24));
      v22 = 0i64;
    }
    v23 = 5;
    v24 = (double)v31;
    if ( (v27 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v26 + 16i64))(
        v26,
        &v25,
        COERCE_DOUBLE(*(_QWORD *)&v28));
      v26 = 0i64;
    }
    v27 = 5;
    v28 = (double)v32;
    Scaleform::GFx::Movie::Invoke(v6, "PerkGoals_AddGoal", 0i64, (Scaleform::GFx::Value *)&ptr, 5u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

