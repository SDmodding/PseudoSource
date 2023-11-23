// File Line: 18
// RVA: 0xACD8B0
void __fastcall AkRumbleControllerXInput::AkRumbleControllerXInput(AkRumbleControllerXInput *this, char in_iPlayer)
{
  this->m_iPlayer = in_iPlayer;
  this->vfptr = (IAkRumbleControllerVtbl *)&AkRumbleControllerXInput::`vftable;
}

// File Line: 22
// RVA: 0xACD910
__int64 __fastcall AkRumbleControllerXInput::SetRumble(
        AkRumbleControllerXInput *this,
        float in_fLarge,
        float in_fSmall)
{
  DWORD v3; // ecx
  __int64 result; // rax
  XINPUT_VIBRATION pVibration; // [rsp+38h] [rbp+10h] BYREF

  if ( in_fLarge <= 0.40000001 )
  {
    if ( in_fLarge <= 0.05 )
      pVibration.wLeftMotorSpeed = 0;
    else
      pVibration.wLeftMotorSpeed = (int)(float)((float)(in_fLarge * 11468.626) + 5242.7998);
  }
  else
  {
    pVibration.wLeftMotorSpeed = (int)(float)((float)(in_fLarge * 75365.25) - 9830.25);
  }
  if ( in_fSmall <= 0.05 )
    pVibration.wRightMotorSpeed = 0;
  else
    pVibration.wRightMotorSpeed = (int)(float)((float)(in_fSmall * 57343.0) + 8192.0);
  v3 = XInputSetState_0((unsigned __int8)this->m_iPlayer, &pVibration);
  if ( !v3 )
    return 1i64;
  result = 77i64;
  if ( v3 != 170 )
    return 2i64;
  return result;
}

// File Line: 72
// RVA: 0xACD8D0
bool __fastcall AkRumbleControllerXInput::IsActive(AkRumbleControllerXInput *this)
{
  XINPUT_CAPABILITIES pCapabilities; // [rsp+20h] [rbp-28h] BYREF

  return !XInputGetCapabilities_0((unsigned __int8)this->m_iPlayer, 1u, &pCapabilities)
      && (pCapabilities.Vibration.wLeftMotorSpeed || pCapabilities.Vibration.wRightMotorSpeed);
}

// File Line: 83
// RVA: 0xACD9E0
__int64 __fastcall AkRumbleControllerXInput::Term(AkRumbleControllerXInput *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  int v4; // eax
  unsigned __int64 i; // rbx

  v4 = ((__int64 (__fastcall *)(AkRumbleControllerXInput *))this->vfptr->SetRumble)(this);
  for ( i = 0i64; i < 0x2710; ++i )
  {
    if ( v4 != 77 )
      break;
    v4 = ((__int64 (__fastcall *)(AkRumbleControllerXInput *))this->vfptr->SetRumble)(this);
  }
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

