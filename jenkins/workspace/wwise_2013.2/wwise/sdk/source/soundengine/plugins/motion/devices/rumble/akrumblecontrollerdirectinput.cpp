// File Line: 21
// RVA: 0xACDA50
void __fastcall AkRumbleControllerDirectInput::AkRumbleControllerDirectInput(
        AkRumbleControllerDirectInput *this,
        IDirectInputDevice8W *in_pController)
{
  IDirectInputDevice8W *m_pController; // rcx

  this->m_pEffect = 0i64;
  this->m_pController = in_pController;
  this->vfptr = (IAkRumbleControllerVtbl *)&AkRumbleControllerDirectInput::`vftable;
  if ( !in_pController || AkRumbleControllerDirectInput::CreateEffect(this) )
  {
    Scaleform::Render::DICommand_ApplyFilter::GetType((CAkSwitchCntr *)L"Unable to initialise rumble on a direct input device.");
  }
  else
  {
    m_pController = this->m_pController;
    if ( m_pController )
    {
      if ( m_pController->vfptr[2].AddRef(m_pController) )
        Scaleform::Render::DICommand_ApplyFilter::GetType((CAkSwitchCntr *)L"Unable to acquire a direct input controler.");
    }
  }
}

// File Line: 41
// RVA: 0xACDAD0
__int64 __fastcall AkRumbleControllerDirectInput::CreateEffect(AkRumbleControllerDirectInput *this)
{
  IDirectInputDevice8W *m_pController; // rbx
  _QWORD Dst[10]; // [rsp+30h] [rbp-50h] BYREF
  int v5; // [rsp+A0h] [rbp+20h] BYREF
  int v6; // [rsp+A8h] [rbp+28h] BYREF
  int v7; // [rsp+ACh] [rbp+2Ch]
  __int64 v8; // [rsp+B0h] [rbp+30h] BYREF

  m_pController = this->m_pController;
  if ( !m_pController )
    return 2147942487i64;
  v7 = 4;
  v6 = 0;
  v8 = 0i64;
  v5 = 0;
  memset(Dst, 0, sizeof(Dst));
  Dst[0] = 0x1200000050i64;
  Dst[4] = &v6;
  Dst[5] = &v8;
  Dst[1] = 0xFFFFFFFFi64;
  Dst[2] = -4294957296i64;
  Dst[8] = &v5;
  Dst[3] = 0x200000000i64;
  Dst[6] = 0i64;
  LODWORD(Dst[7]) = 4;
  LODWORD(Dst[9]) = 0;
  return ((__int64 (__fastcall *)(IDirectInputDevice8W *, GUID *, _QWORD *, IDirectInputEffect **, _QWORD))m_pController->vfptr[6].QueryInterface)(
           m_pController,
           &GUID_ConstantForce,
           Dst,
           &this->m_pEffect,
           0i64);
}

// File Line: 92
// RVA: 0xACDC20
__int64 __fastcall AkRumbleControllerDirectInput::SetRumble(
        AkRumbleControllerDirectInput *this,
        float in_fLarge,
        float in_fSmall)
{
  IDirectInputEffect *m_pEffect; // rdi
  __m128d v5; // xmm1
  _QWORD Dst[11]; // [rsp+20h] [rbp-58h] BYREF
  int v7; // [rsp+80h] [rbp+8h] BYREF
  int v8; // [rsp+98h] [rbp+20h] BYREF
  int v9; // [rsp+9Ch] [rbp+24h]

  m_pEffect = this->m_pEffect;
  if ( !m_pEffect )
    return 2i64;
  v9 = (int)(float)(in_fLarge * 10000.0);
  v8 = (int)(float)(in_fSmall * 10000.0);
  v5 = (__m128d)COERCE_UNSIGNED_INT64((double)v8);
  v5.m128d_f64[0] = v5.m128d_f64[0] * v5.m128d_f64[0] + (double)v9 * (double)v9;
  v7 = (int)_mm_sqrt_pd(v5).m128d_f64[0];
  memset(Dst, 0, 0x50ui64);
  Dst[5] = &v8;
  Dst[0] = 0x1000000050i64;
  HIDWORD(Dst[3]) = 2;
  Dst[8] = &v7;
  Dst[6] = 0i64;
  LODWORD(Dst[7]) = 4;
  LODWORD(Dst[9]) = 0;
  return (unsigned int)(m_pEffect->vfptr[2].QueryInterface(m_pEffect, (_GUID *)Dst, (void **)536871232) < 0) + 1;
}

// File Line: 124
// RVA: 0xACDBB0
_BOOL8 __fastcall AkRumbleControllerDirectInput::IsActive(AkRumbleControllerDirectInput *this)
{
  IDirectInputDevice8W *m_pController; // rcx
  int v4; // [rsp+20h] [rbp-38h] BYREF
  char v5; // [rsp+24h] [rbp-34h]

  this->m_pController->vfptr[8].AddRef(this->m_pController);
  m_pController = this->m_pController;
  v4 = 44;
  return !((unsigned int (__fastcall *)(IDirectInputDevice8W *, int *))m_pController->vfptr[1].QueryInterface)(
            m_pController,
            &v4)
      && (v5 & 1) != 0;
}

// File Line: 139
// RVA: 0xACDD20
__int64 __fastcall AkRumbleControllerDirectInput::Term(
        AkRumbleControllerDirectInput *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  IDirectInputDevice8W *m_pController; // rcx
  IDirectInputEffect *m_pEffect; // rcx

  if ( this )
  {
    this->vfptr = (IAkRumbleControllerVtbl *)&AkRumbleControllerDirectInput::`vftable;
    m_pController = this->m_pController;
    if ( m_pController )
    {
      m_pController->vfptr[2].Release(m_pController);
      this->m_pController = 0i64;
    }
    m_pEffect = this->m_pEffect;
    if ( m_pEffect )
    {
      m_pEffect->vfptr->Release(m_pEffect);
      this->m_pEffect = 0i64;
    }
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

