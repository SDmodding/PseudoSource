// File Line: 21
// RVA: 0xACDA50
void __fastcall AkRumbleControllerDirectInput::AkRumbleControllerDirectInput(AkRumbleControllerDirectInput *this, IDirectInputDevice8W *in_pController)
{
  AkRumbleControllerDirectInput *v2; // rbx
  IDirectInputDevice8W *v3; // rcx

  v2 = this;
  this->m_pEffect = 0i64;
  this->m_pController = in_pController;
  this->vfptr = (IAkRumbleControllerVtbl *)&AkRumbleControllerDirectInput::`vftable;
  if ( !in_pController || AkRumbleControllerDirectInput::CreateEffect(this) )
  {
    Scaleform::Render::DICommand_ApplyFilter::GetType((CAkSwitchCntr *)L"Unable to initialise rumble on a direct input device.");
  }
  else
  {
    v3 = v2->m_pController;
    if ( v3 )
    {
      if ( ((unsigned int (*)(void))v3->vfptr[2].AddRef)() )
        Scaleform::Render::DICommand_ApplyFilter::GetType((CAkSwitchCntr *)L"Unable to acquire a direct input controler.");
    }
  }
}

// File Line: 41
// RVA: 0xACDAD0
__int64 __fastcall AkRumbleControllerDirectInput::CreateEffect(AkRumbleControllerDirectInput *this)
{
  IDirectInputDevice8W *v1; // rbx
  AkRumbleControllerDirectInput *v2; // rdi
  int Dst; // [rsp+30h] [rbp-50h]
  int v5; // [rsp+34h] [rbp-4Ch]
  int v6; // [rsp+38h] [rbp-48h]
  int v7; // [rsp+3Ch] [rbp-44h]
  int v8; // [rsp+40h] [rbp-40h]
  int v9; // [rsp+44h] [rbp-3Ch]
  int v10; // [rsp+48h] [rbp-38h]
  int v11; // [rsp+4Ch] [rbp-34h]
  int *v12; // [rsp+50h] [rbp-30h]
  __int64 *v13; // [rsp+58h] [rbp-28h]
  __int64 v14; // [rsp+60h] [rbp-20h]
  int v15; // [rsp+68h] [rbp-18h]
  int *v16; // [rsp+70h] [rbp-10h]
  int v17; // [rsp+78h] [rbp-8h]
  int v18; // [rsp+A0h] [rbp+20h]
  int v19; // [rsp+A8h] [rbp+28h]
  int v20; // [rsp+ACh] [rbp+2Ch]
  __int64 v21; // [rsp+B0h] [rbp+30h]

  v1 = this->m_pController;
  v2 = this;
  if ( !v1 )
    return 2147942487i64;
  v20 = 4;
  v19 = 0;
  v21 = 0i64;
  v18 = 0;
  memset(&Dst, 0, 0x50ui64);
  Dst = 80;
  v12 = &v19;
  v5 = 18;
  v13 = &v21;
  v6 = -1;
  v7 = 0;
  v8 = 10000;
  v9 = -1;
  v16 = &v18;
  v10 = 0;
  v11 = 2;
  v14 = 0i64;
  v15 = 4;
  v17 = 0;
  return ((__int64 (__fastcall *)(IDirectInputDevice8W *, GUID *, int *, IDirectInputEffect **, _QWORD))v1->vfptr[6].QueryInterface)(
           v1,
           &GUID_ConstantForce,
           &Dst,
           &v2->m_pEffect,
           0i64);
}

// File Line: 92
// RVA: 0xACDC20
signed __int64 __fastcall AkRumbleControllerDirectInput::SetRumble(AkRumbleControllerDirectInput *this, float in_fLarge, float in_fSmall)
{
  IDirectInputEffect *v3; // rdi
  __m128d v5; // xmm1
  int Dst; // [rsp+20h] [rbp-58h]
  int v7; // [rsp+24h] [rbp-54h]
  int v8; // [rsp+3Ch] [rbp-3Ch]
  int *v9; // [rsp+48h] [rbp-30h]
  __int64 v10; // [rsp+50h] [rbp-28h]
  int v11; // [rsp+58h] [rbp-20h]
  int *v12; // [rsp+60h] [rbp-18h]
  int v13; // [rsp+68h] [rbp-10h]
  int v14; // [rsp+80h] [rbp+8h]
  int v15; // [rsp+98h] [rbp+20h]
  int v16; // [rsp+9Ch] [rbp+24h]

  v3 = this->m_pEffect;
  if ( !v3 )
    return 2i64;
  v16 = (signed int)(float)(in_fLarge * 10000.0);
  v15 = (signed int)(float)(in_fSmall * 10000.0);
  v5 = (__m128d)COERCE_UNSIGNED_INT64((double)v15);
  v5.m128d_f64[0] = v5.m128d_f64[0] * v5.m128d_f64[0] + (double)v16 * (double)v16;
  v14 = (signed int)COERCE_DOUBLE(_mm_sqrt_pd(v5));
  memset(&Dst, 0, 0x50ui64);
  v9 = &v15;
  Dst = 80;
  v7 = 16;
  v8 = 2;
  v12 = &v14;
  v10 = 0i64;
  v11 = 4;
  v13 = 0;
  return (unsigned int)(v3->vfptr[2].QueryInterface((IUnknown *)&v3->vfptr, (_GUID *)&Dst, (void **)536871232) < 0) + 1;
}

// File Line: 124
// RVA: 0xACDBB0
signed __int64 __fastcall AkRumbleControllerDirectInput::IsActive(AkRumbleControllerDirectInput *this)
{
  AkRumbleControllerDirectInput *v1; // rbx
  IDirectInputDevice8W *v2; // rcx
  signed __int64 result; // rax
  int v4; // [rsp+20h] [rbp-38h]
  char v5; // [rsp+24h] [rbp-34h]

  v1 = this;
  ((void (*)(void))this->m_pController->vfptr[8].AddRef)();
  v2 = v1->m_pController;
  v4 = 44;
  if ( ((unsigned int (__fastcall *)(IDirectInputDevice8W *, int *))v2->vfptr[1].QueryInterface)(v2, &v4) )
    return 0i64;
  result = 0i64;
  if ( v5 & 1 )
    result = 1i64;
  return result;
}

// File Line: 139
// RVA: 0xACDD20
signed __int64 __fastcall AkRumbleControllerDirectInput::Term(AkRumbleControllerDirectInput *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  AkRumbleControllerDirectInput *v3; // rbx
  IDirectInputDevice8W *v4; // rcx
  IDirectInputEffect *v5; // rcx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr = (IAkRumbleControllerVtbl *)&AkRumbleControllerDirectInput::`vftable;
    v4 = this->m_pController;
    if ( v4 )
    {
      ((void (*)(void))v4->vfptr[2].Release)();
      v3->m_pController = 0i64;
    }
    v5 = v3->m_pEffect;
    if ( v5 )
    {
      ((void (*)(void))v5->vfptr->Release)();
      v3->m_pEffect = 0i64;
    }
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

