// File Line: 19
// RVA: 0x5C4420
void __fastcall UFG::UIHKMissionProgressSlotData::UIHKMissionProgressSlotData(UFG::UIHKMissionProgressSlotData *this)
{
  this->Changed = 1;
  this->State = 0;
  UFG::qString::qString(&this->Caption);
}

// File Line: 51
// RVA: 0x614D20
void __fastcall UFG::UIHKMissionProgressWidget::Update(UFG::UIHKMissionProgressWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rbp
  UFG::UIHKMissionProgressWidget *v3; // rsi
  Scaleform::GFx::Movie *v4; // rbx
  bool v5; // di
  unsigned int v6; // edi
  UFG::UIHKMissionProgressSlotData::eState *v7; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  if ( screen )
  {
    v2 = screen;
    v3 = this;
    if ( this->mChanged )
    {
      this->mChanged = 0;
      v4 = screen->mRenderable->m_movie.pObject;
      if ( v4 )
      {
        value.pObjectInterface = 0i64;
        value.Type = 0;
        v5 = this->mVisible;
        value.Type = 2;
        value.mValue.BValue = v5;
        Scaleform::GFx::Movie::SetVariable(v4, "mc_TallyList._visible", &value, 1i64);
        if ( v3->mVisible )
        {
          v6 = 0;
          v7 = &v3->mData[0].State;
          do
          {
            if ( *((_BYTE *)v7 - 4) )
            {
              *((_BYTE *)v7 - 4) = 0;
              UFG::UIHKMissionProgressWidget::Flash_UpdateSlot(v3, v2, v6, &v3->mData[v6]);
              if ( *v7 == 5 )
                *v7 = 3;
            }
            ++v6;
            v7 += 12;
          }
          while ( v6 < 4 );
        }
        if ( ((unsigned int)value.Type >> 6) & 1 )
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            *(_QWORD *)&value.mValue.NValue);
      }
    }
  }
}

// File Line: 87
// RVA: 0x5D50D0
void __fastcall UFG::UIHKMissionProgressWidget::Clear(UFG::UIHKMissionProgressWidget *this)
{
  UFG::UIHKMissionProgressWidget *v1; // rsi
  UFG::qString *v2; // rbx
  signed __int64 v3; // rdi

  v1 = this;
  v2 = &this->mData[0].Caption;
  v3 = 4i64;
  do
  {
    LOBYTE(v2[-1].mStringHash32) = 1;
    v2[-1].mStringHashUpper32 = 0;
    UFG::qString::Set(v2, &customWorldMapCaption);
    v2 = (UFG::qString *)((char *)v2 + 48);
    --v3;
  }
  while ( v3 );
  v1->mChanged = 1;
}

// File Line: 97
// RVA: 0x60C640
void __fastcall UFG::UIHKRacePositionWidget::SetVisible(UFG::UIHKRacePositionWidget *this, bool visible)
{
  bool v2; // zf

  v2 = this->mVisible == visible;
  this->mVisible = visible;
  this->mChanged |= !v2;
}

// File Line: 104
// RVA: 0x609FF0
void __fastcall UFG::UIHKMissionProgressWidget::SetText(UFG::UIHKMissionProgressWidget *this, const char *text, unsigned int slot)
{
  UFG::UIHKMissionProgressWidget *v3; // rbx
  UFG::qString *v4; // rcx
  signed __int64 v5; // r8

  if ( slot < 4 )
  {
    v3 = this;
    v4 = &this->mData[0].Caption;
    v5 = 48i64 * slot;
    *((_BYTE *)v4 + v5 - 8) = 1;
    UFG::qString::Set((UFG::qString *)((char *)v4 + v5), text);
    v3->mChanged = 1;
  }
}

// File Line: 114
// RVA: 0x609040
void __fastcall UFG::UIHKMissionProgressWidget::SetState(UFG::UIHKMissionProgressWidget *this, UFG::UIHKMissionProgressSlotData::eState state, unsigned int slot)
{
  __int64 v3; // r8
  bool v4; // zf

  if ( slot < 4 )
  {
    v3 = slot;
    v4 = this->mData[v3].State == state;
    this->mData[v3].State = state;
    this->mData[v3].Changed |= !v4;
    this->mChanged |= !v4;
  }
}

// File Line: 138
// RVA: 0x5E5D00
void __fastcall UFG::UIHKMissionProgressWidget::Flash_UpdateSlot(UFG::UIHKMissionProgressWidget *this, UFG::UIScreen *screen, int slotIndex, UFG::UIHKMissionProgressSlotData *slotData)
{
  UFG::UIHKMissionProgressSlotData *v4; // rbx
  int v5; // er14
  Scaleform::GFx::Movie *v6; // rdi
  bool v7; // si
  char *v8; // rsi
  const char *v9; // rbx
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-B8h]
  Scaleform::GFx::Value value; // [rsp+60h] [rbp-88h]
  unsigned int v12; // [rsp+90h] [rbp-58h]
  __int64 v13; // [rsp+98h] [rbp-50h]
  char ptr; // [rsp+A8h] [rbp-40h]
  __int64 v15; // [rsp+B8h] [rbp-30h]
  unsigned int v16; // [rsp+C0h] [rbp-28h]
  const char *v17; // [rsp+C8h] [rbp-20h]
  char v18; // [rsp+D8h] [rbp-10h]
  __int64 v19; // [rsp+E8h] [rbp+0h]
  unsigned int v20; // [rsp+F0h] [rbp+8h]
  double v21; // [rsp+F8h] [rbp+10h]
  UFG::qString v22; // [rsp+108h] [rbp+20h]
  __int64 v23; // [rsp+130h] [rbp+48h]

  v23 = -2i64;
  v4 = slotData;
  v5 = slotIndex;
  v6 = screen->mRenderable->m_movie.pObject;
  if ( v6 )
  {
    value.DataAux = 0i64;
    v12 = 0;
    v7 = slotData->Caption.mLength != 0;
    v12 = 2;
    LOBYTE(v13) = v7;
    value.pObjectInterface = 0i64;
    value.Type = 0;
    v8 = slotData->Caption.mData;
    value.Type = 6;
    value.pNext = (Scaleform::GFx::Value *)v8;
    UFG::qString::qString(&v22);
    UFG::qString::Format(&v22, "mc_TallyList.slot%d.text.htmlText", (unsigned int)v5);
    Scaleform::GFx::Movie::SetVariable(v6, v22.mData, &value, 1i64);
    pargs.pObjectInterface = 0i64;
    pargs.Type = 5;
    pargs.mValue.NValue = (double)v5;
    Scaleform::GFx::Movie::Invoke(v6, "TallyList_Resize", 0i64, &pargs, 1u);
    UFG::qString::Format(&v22, "mc_TallyList.slot%d._visible", (unsigned int)v5);
    Scaleform::GFx::Movie::SetVariable(v6, v22.mData, (Scaleform::GFx::Value *)((char *)&value + 24), 1i64);
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    switch ( v4->State )
    {
      case 3:
        v9 = "complete";
        break;
      case 4:
        v9 = "incomplete";
        break;
      case 5:
        v9 = "animate_complete";
        break;
      default:
        v9 = "normal";
        break;
    }
    if ( (v16 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v15 + 16i64))(v15, &ptr, v17);
      v15 = 0i64;
    }
    v16 = 6;
    v17 = v9;
    if ( (v20 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v19 + 16i64))(
        v19,
        &v18,
        COERCE_DOUBLE(*(_QWORD *)&v21));
      v19 = 0i64;
    }
    v20 = 5;
    v21 = (double)v5;
    Scaleform::GFx::Movie::Invoke(v6, "TallyList_SetType", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 0;
    UFG::qString::~qString(&v22);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.pNext);
      value.pObjectInterface = 0i64;
    }
    value.Type = 0;
    if ( (v12 >> 6) & 1 )
      (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, __int64))(*(_QWORD *)value.DataAux
                                                                                            + 16i64))(
        value.DataAux,
        &value.Type,
        v13);
  }
}

