// File Line: 68
// RVA: 0x606F00
void __fastcall UFG::UIHKRacePositionWidget::SetPlayerRank(UFG::UIHKRacePositionWidget *this, unsigned int rank)
{
  bool v2; // zf

  v2 = this->mPlayerRank == rank;
  this->mPlayerRank = rank;
  this->mChanged |= !v2;
}

// File Line: 75
// RVA: 0x606620
void __fastcall UFG::UIHKRacePositionWidget::SetNumRacers(UFG::UIHKRacePositionWidget *this, unsigned int numRacers)
{
  bool v2; // zf

  v2 = this->mNumRacers == numRacers;
  this->mNumRacers = numRacers;
  this->mChanged |= !v2;
}

// File Line: 82
// RVA: 0x5E1BC0
void __fastcall UFG::UIHKRacePositionWidget::Flash_SetVisible(UFG::UIHKRacePositionWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKRacePositionWidget *v2; // rdi
  Scaleform::GFx::Movie *v3; // rbx
  bool v4; // si
  signed int v5; // eax
  Scaleform::GFx::Value v6; // [rsp+20h] [rbp-11h]
  Scaleform::GFx::Value value; // [rsp+50h] [rbp+1Fh]

  v2 = this;
  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 0;
    v4 = this->mVisible;
    value.Type = 2;
    value.mValue.BValue = v4;
    Scaleform::GFx::Movie::SetVariable(v3, "_root.mc_RaceHUD.mc_RacePosition._visible", &value, 1i64);
    v6.pObjectInterface = 0i64;
    v6.Type = 134;
    v5 = v2->mNumRacers;
    v6.Type = 5;
    v6.mValue.NValue = (double)v5;
    Scaleform::GFx::Movie::SetVariable(v3, "_root.mc_RaceHUD.mc_RacePosition.RacePositionTot.caption.text", &v6, 1i64);
    if ( ((unsigned int)v6.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v6.pObjectInterface->vfptr->gap8[8])(
        v6.pObjectInterface,
        &v6,
        *(_QWORD *)&v6.mValue.NValue);
      v6.pObjectInterface = 0i64;
    }
    v6.Type = 0;
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 98
// RVA: 0x5E05C0
void __fastcall UFG::UIHKRacePositionWidget::Flash_SetPlayerPosition(UFG::UIHKRacePositionWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rdi
  UFG::UIHKRacePositionWidget *v3; // rbx
  double v4; // xmm6_8
  double v5; // xmm6_8
  Scaleform::GFx::Movie *v6; // rcx
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-78h]
  char v8; // [rsp+70h] [rbp-48h]
  __int64 v9; // [rsp+80h] [rbp-38h]
  unsigned int v10; // [rsp+88h] [rbp-30h]
  double v11; // [rsp+90h] [rbp-28h]

  v2 = screen;
  v3 = this;
  `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4 = (double)(signed int)v3->mPlayerRank;
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 5;
  pargs.mValue.NValue = v4;
  v5 = (double)(signed int)v3->mNumRacers;
  if ( (v10 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, &v8, COERCE_DOUBLE(*(_QWORD *)&v11));
    v9 = 0i64;
  }
  v10 = 5;
  v11 = v5;
  v6 = v2->mRenderable->m_movie.pObject;
  if ( v6 )
    Scaleform::GFx::Movie::Invoke(v6, "Race_SetPlayerPosition", 0i64, &pargs, 2u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

