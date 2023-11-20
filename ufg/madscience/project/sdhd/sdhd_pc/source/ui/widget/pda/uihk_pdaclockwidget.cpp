// File Line: 26
// RVA: 0x619670
void __fastcall UFG::UIHK_PDAClockWidget::Update(UFG::UIHK_PDAClockWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rsi
  UFG::UIHK_PDAClockWidget *v3; // rdi
  UFG::TimeOfDayManager *v4; // rax
  float v5; // xmm0_4
  unsigned int v6; // ebx
  int v7; // eax
  const char *v8; // rcx
  signed __int64 v9; // r8
  UFG::qString v10; // [rsp+38h] [rbp-30h]

  v2 = screen;
  v3 = this;
  v4 = UFG::TimeOfDayManager::GetInstance();
  if ( v4 )
    v5 = v4->m_SecondsSinceMidnight;
  else
    v5 = 0.0;
  v6 = (signed int)v5;
  v7 = (signed int)v5 - v3->mClockTime;
  if ( v7 < 0 )
    v7 = v3->mClockTime - (signed int)v5;
  if ( v7 >= 60 )
  {
    v3->mClockTime = 60 * ((signed int)v6 / 60);
    UFG::qString::qString(&v10);
    v8 = "PM";
    if ( (signed int)(v6 / 0xE10) < 12 )
      v8 = "AM";
    v9 = (unsigned int)((signed int)(v6 / 0xE10) % -12);
    if ( !(_DWORD)v9 )
      v9 = 12i64;
    UFG::qString::Format(&v10, "%d:%02d %s", v9, v6 % 0xE10 / 0x3C, v8);
    UFG::UIHK_PDAClockWidget::Flash_SetTime(v3, v2, v10.mData);
    UFG::qString::~qString(&v10);
  }
}

// File Line: 61
// RVA: 0x5E13F0
void __fastcall UFG::UIHK_PDAClockWidget::Flash_SetTime(UFG::UIHK_PDAClockWidget *this, UFG::UIScreen *screen, const char *timeStr)
{
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 6;
    *(_QWORD *)&value.mValue.NValue = timeStr;
    Scaleform::GFx::Movie::SetVariable(v3, "mc_smartphone.mc_smartphoneStatus.tf_time.text", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

