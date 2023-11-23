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
  Scaleform::GFx::Movie *pObject; // rbx
  bool mVisible; // si
  long double mNumRacers; // xmm0_8
  Scaleform::GFx::Value v6; // [rsp+20h] [rbp-11h] BYREF
  Scaleform::GFx::Value value; // [rsp+50h] [rbp+1Fh] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Undefined;
    mVisible = this->mVisible;
    value.Type = VT_Boolean;
    value.mValue.BValue = mVisible;
    Scaleform::GFx::Movie::SetVariable(pObject, "_root.mc_RaceHUD.mc_RacePosition._visible", &value, 1i64);
    v6.pObjectInterface = 0i64;
    v6.Type = VT_ConvertString;
    mNumRacers = (double)(int)this->mNumRacers;
    v6.Type = VT_Number;
    v6.mValue.NValue = mNumRacers;
    Scaleform::GFx::Movie::SetVariable(
      pObject,
      "_root.mc_RaceHUD.mc_RacePosition.RacePositionTot.caption.text",
      &v6,
      1i64);
    if ( (v6.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v6.pObjectInterface->vfptr->gap8[8])(
        v6.pObjectInterface,
        &v6,
        v6.mValue);
      v6.pObjectInterface = 0i64;
    }
    v6.Type = VT_Undefined;
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

// File Line: 98
// RVA: 0x5E05C0
void __fastcall UFG::UIHKRacePositionWidget::Flash_SetPlayerPosition(
        UFG::UIHKRacePositionWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Value::ValueUnion v4; // xmm6_8
  double mNumRacers; // xmm6_8
  Scaleform::GFx::Movie *pObject; // rcx
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-78h] BYREF
  char v8[16]; // [rsp+70h] [rbp-48h] BYREF
  __int64 v9; // [rsp+80h] [rbp-38h]
  int v10; // [rsp+88h] [rbp-30h]
  double v11; // [rsp+90h] [rbp-28h]

  `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4.NValue = (double)(int)this->mPlayerRank;
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Number;
  pargs.mValue = v4;
  mNumRacers = (double)(int)this->mNumRacers;
  if ( (v10 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, v8, COERCE_DOUBLE(*(_QWORD *)&v11));
    v9 = 0i64;
  }
  v10 = 5;
  v11 = mNumRacers;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "Race_SetPlayerPosition", 0i64, &pargs, 2u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

