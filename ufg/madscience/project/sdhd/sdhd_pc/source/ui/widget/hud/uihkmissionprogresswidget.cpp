// File Line: 19
// RVA: 0x5C4420
void __fastcall UFG::UIHKMissionProgressSlotData::UIHKMissionProgressSlotData(UFG::UIHKMissionProgressSlotData *this)
{
  this->Changed = 1;
  this->State = STATE_INVALID;
  UFG::qString::qString(&this->Caption);
}

// File Line: 51
// RVA: 0x614D20
void __fastcall UFG::UIHKMissionProgressWidget::Update(UFG::UIHKMissionProgressWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  bool mVisible; // di
  unsigned int v6; // edi
  UFG::UIHKMissionProgressSlotData::eState *p_State; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  if ( screen )
  {
    if ( this->mChanged )
    {
      this->mChanged = 0;
      pObject = screen->mRenderable->m_movie.pObject;
      if ( pObject )
      {
        value.pObjectInterface = 0i64;
        value.Type = VT_Undefined;
        mVisible = this->mVisible;
        value.Type = VT_Boolean;
        value.mValue.BValue = mVisible;
        Scaleform::GFx::Movie::SetVariable(pObject, "mc_TallyList._visible", &value, 1i64);
        if ( this->mVisible )
        {
          v6 = 0;
          p_State = &this->mData[0].State;
          do
          {
            if ( *((_BYTE *)p_State - 4) )
            {
              *((_BYTE *)p_State - 4) = 0;
              UFG::UIHKMissionProgressWidget::Flash_UpdateSlot(this, screen, v6, &this->mData[v6]);
              if ( *p_State == STATE_ANIMATE_COMPLETE )
                *p_State = STATE_COMPLETE;
            }
            ++v6;
            p_State += 12;
          }
          while ( v6 < 4 );
        }
        if ( (value.Type & 0x40) != 0 )
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            value.mValue);
      }
    }
  }
}

// File Line: 87
// RVA: 0x5D50D0
void __fastcall UFG::UIHKMissionProgressWidget::Clear(UFG::UIHKMissionProgressWidget *this)
{
  UFG::qString *p_Caption; // rbx
  __int64 v3; // rdi

  p_Caption = &this->mData[0].Caption;
  v3 = 4i64;
  do
  {
    LOBYTE(p_Caption[-1].mStringHash32) = 1;
    p_Caption[-1].mStringHashUpper32 = 0;
    UFG::qString::Set(p_Caption, &customCaption);
    p_Caption = (UFG::qString *)((char *)p_Caption + 48);
    --v3;
  }
  while ( v3 );
  this->mChanged = 1;
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
void __fastcall UFG::UIHKMissionProgressWidget::SetText(
        UFG::UIHKMissionProgressWidget *this,
        const char *text,
        unsigned int slot)
{
  UFG::qString *p_Caption; // rcx
  __int64 v5; // r8

  if ( slot < 4 )
  {
    p_Caption = &this->mData[0].Caption;
    v5 = 48i64 * slot;
    *((_BYTE *)p_Caption + v5 - 8) = 1;
    UFG::qString::Set((UFG::qString *)((char *)p_Caption + v5), text);
    this->mChanged = 1;
  }
}

// File Line: 114
// RVA: 0x609040
void __fastcall UFG::UIHKMissionProgressWidget::SetState(
        UFG::UIHKMissionProgressWidget *this,
        UFG::UIHKMissionProgressSlotData::eState state,
        unsigned int slot)
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
void __fastcall UFG::UIHKMissionProgressWidget::Flash_UpdateSlot(
        UFG::UIHKMissionProgressWidget *this,
        UFG::UIScreen *screen,
        unsigned int slotIndex,
        UFG::UIHKMissionProgressSlotData *slotData)
{
  Scaleform::GFx::Movie *pObject; // rdi
  bool v7; // si
  char *mData; // rsi
  const char *v9; // rbx
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::GFx::Value value; // [rsp+60h] [rbp-88h] BYREF
  int v12; // [rsp+90h] [rbp-58h]
  __int64 v13; // [rsp+98h] [rbp-50h]
  Scaleform::GFx::Value ptr; // [rsp+A8h] [rbp-40h] BYREF
  char v15[16]; // [rsp+D8h] [rbp-10h] BYREF
  __int64 v16; // [rsp+E8h] [rbp+0h]
  int v17; // [rsp+F0h] [rbp+8h]
  double v18; // [rsp+F8h] [rbp+10h]
  UFG::qString v19; // [rsp+108h] [rbp+20h] BYREF
  __int64 v20; // [rsp+130h] [rbp+48h]

  v20 = -2i64;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.DataAux = 0i64;
    v12 = 0;
    v7 = slotData->Caption.mLength != 0;
    v12 = 2;
    LOBYTE(v13) = v7;
    value.pObjectInterface = 0i64;
    value.Type = VT_Undefined;
    mData = slotData->Caption.mData;
    value.Type = VT_String;
    value.pNext = (Scaleform::GFx::Value *)mData;
    UFG::qString::qString(&v19);
    UFG::qString::Format(&v19, "mc_TallyList.slot%d.text.htmlText", slotIndex);
    Scaleform::GFx::Movie::SetVariable(pObject, v19.mData, &value, 1i64);
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (double)(int)slotIndex;
    Scaleform::GFx::Movie::Invoke(pObject, "TallyList_Resize", 0i64, &pargs, 1u);
    UFG::qString::Format(&v19, "mc_TallyList.slot%d._visible", slotIndex);
    Scaleform::GFx::Movie::SetVariable(pObject, v19.mData, (Scaleform::GFx::Value *)&value.Type, 1i64);
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    switch ( slotData->State )
    {
      case STATE_COMPLETE:
        v9 = "complete";
        break;
      case STATE_INCOMPLETE:
        v9 = "incomplete";
        break;
      case STATE_ANIMATE_COMPLETE:
        v9 = "animate_complete";
        break;
      default:
        v9 = "normal";
        break;
    }
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_String;
    ptr.mValue.pString = v9;
    if ( (v17 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v16 + 16i64))(
        v16,
        v15,
        COERCE_DOUBLE(*(_QWORD *)&v18));
      v16 = 0i64;
    }
    v17 = 5;
    v18 = (double)(int)slotIndex;
    Scaleform::GFx::Movie::Invoke(pObject, "TallyList_SetType", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Undefined;
    UFG::qString::~qString(&v19);
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.pNext);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Undefined;
    if ( (v12 & 0x40) != 0 )
      (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, __int64))(*(_QWORD *)value.DataAux
                                                                                            + 16i64))(
        value.DataAux,
        &value.Type,
        v13);
  }
}          

