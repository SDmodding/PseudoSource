// File Line: 18
// RVA: 0xACD8B0
void __fastcall AkRumbleControllerXInput::AkRumbleControllerXInput(AkRumbleControllerXInput *this, char in_iPlayer)
{
  this->m_iPlayer = in_iPlayer;
  this->vfptr = (IAkRumbleControllerVtbl *)&AkRumbleControllerXInput::`vftable;
}

// File Line: 22
// RVA: 0xACD910
signed __int64 __fastcall AkRumbleControllerXInput::SetRumble(AkRumbleControllerXInput *this, float in_fLarge, float in_fSmall)
{
  DWORD v3; // ecx
  signed __int64 result; // rax
  XINPUT_VIBRATION pVibration; // [rsp+38h] [rbp+10h]

  if ( in_fLarge <= 0.40000001 )
  {
    if ( in_fLarge <= 0.05 )
      pVibration.wLeftMotorSpeed = 0;
    else
      pVibration.wLeftMotorSpeed = (signed int)(float)((float)(in_fLarge * 11468.626) + 5242.7998);
  }
  else
  {
    pVibration.wLeftMotorSpeed = (signed int)(float)((float)(in_fLarge * 75365.25) - 9830.25);
  }
  if ( in_fSmall <= 0.05 )
    pVibration.wRightMotorSpeed = 0;
  else
    pVibration.wRightMotorSpeed = (signed int)(float)((float)(in_fSmall * 57343.0) + 8192.0);
  v3 = XInputSetState_0((unsigned __int8)this->m_iPlayer, &pVibration);
  if ( !v3 )
    return 1i64;
  result = 77i64;
  if ( v3 != 170 )
    result = 2i64;
  return result;
}

// File Line: 72
// RVA: 0xACD8D0
bool __fastcall AkRumbleControllerXInput::IsActive(AkRumbleControllerXInput *this)
{
  XINPUT_CAPABILITIES pCapabilities; // [rsp+20h] [rbp-28h]

  return !XInputGetCapabilities_0((unsigned __int8)this->m_iPlayer, 1u, &pCapabilities)
      && (pCapabilities.Vibration.wLeftMotorSpeed || pCapabilities.Vibration.wRightMotorSpeed);
}

// File Line: 83
// RVA: 0xACD9E0
signed __int64 __fastcall AkRumbleControllerXInput::Term(AkRumbleControllerXInput *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rsi
  AkRumbleControllerXInput *v3; // rdi
  int v4; // eax
  unsigned __int64 v5; // rbx

  v2 = in_pAllocator;
  v3 = this;
  v4 = ((__int64 (*)(void))this->vfptr->SetRumble)();
  v5 = 0i64;
  do
  {
    if ( v4 != 77 )
      break;
    v4 = ((__int64 (__fastcall *)(AkRumbleControllerXInput *))v3->vfptr->SetRumble)(v3);
    ++v5;
  }
  while ( v5 < 0x2710 );
  v2->vfptr->Free(v2, v3);
  return 1i64;
}

