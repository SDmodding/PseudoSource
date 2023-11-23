// File Line: 26
// RVA: 0x619670
void __fastcall UFG::UIHK_PDAClockWidget::Update(UFG::UIHK_PDAClockWidget *this, UFG::UIScreen *screen)
{
  UFG::TimeOfDayManager *Instance; // rax
  float m_SecondsSinceMidnight; // xmm0_4
  unsigned int v6; // ebx
  int v7; // eax
  const char *v8; // rcx
  __int64 v9; // r8
  UFG::qString v10; // [rsp+38h] [rbp-30h] BYREF

  Instance = UFG::TimeOfDayManager::GetInstance();
  if ( Instance )
    m_SecondsSinceMidnight = Instance->m_SecondsSinceMidnight;
  else
    m_SecondsSinceMidnight = 0.0;
  v6 = (int)m_SecondsSinceMidnight;
  v7 = (int)m_SecondsSinceMidnight - this->mClockTime;
  if ( v7 < 0 )
    v7 = this->mClockTime - (int)m_SecondsSinceMidnight;
  if ( v7 >= 60 )
  {
    this->mClockTime = 60 * ((int)v6 / 60);
    UFG::qString::qString(&v10);
    v8 = "PM";
    if ( (int)(v6 / 0xE10) < 12 )
      v8 = "AM";
    v9 = (unsigned int)((int)(v6 / 0xE10) % -12);
    if ( !(_DWORD)v9 )
      v9 = 12i64;
    UFG::qString::Format(&v10, "%d:%02d %s", v9, v6 % 0xE10 / 0x3C, v8);
    UFG::UIHK_PDAClockWidget::Flash_SetTime(this, screen, v10.mData);
    UFG::qString::~qString(&v10);
  }
}

// File Line: 61
// RVA: 0x5E13F0
void __fastcall UFG::UIHK_PDAClockWidget::Flash_SetTime(
        UFG::UIHK_PDAClockWidget *this,
        UFG::UIScreen *screen,
        const char *timeStr)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_String;
    value.mValue.pString = timeStr;
    Scaleform::GFx::Movie::SetVariable(pObject, "mc_smartphone.mc_smartphoneStatus.tf_time.text", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

