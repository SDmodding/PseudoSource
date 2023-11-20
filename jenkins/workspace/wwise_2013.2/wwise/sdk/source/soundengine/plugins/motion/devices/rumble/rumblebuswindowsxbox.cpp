// File Line: 11
// RVA: 0xACCFE0
void __fastcall RumbleMixBus::RumbleMixBus(RumbleMixBus *this)
{
  RumbleMixBus *v1; // rbx

  v1 = this;
  RumbleBusBase::RumbleBusBase((RumbleBusBase *)&this->vfptr);
  v1->vfptr = (AK::IAkPluginVtbl *)&RumbleMixBus::`vftable';
  v1->m_pRumbleDevice = 0i64;
  v1->m_oCurrent = 0i64;
}

// File Line: 16
// RVA: 0xACD020
int __fastcall RumbleMixBus::Init(RumbleMixBus *this, AK::IAkPluginMemAlloc *in_pAllocator, AkPlatformInitSettings *io_pPDSettings, char in_iPlayer, void *in_pDevice)
{
  char v5; // di
  AK::IAkPluginMemAlloc *v6; // rsi
  RumbleMixBus *v7; // rbx
  int result; // eax
  IAkRumbleController *v9; // rax

  v5 = in_iPlayer;
  v6 = in_pAllocator;
  v7 = this;
  result = RumbleBusBase::Init((RumbleBusBase *)&this->vfptr, in_pAllocator, io_pPDSettings, in_iPlayer, in_pDevice);
  if ( result == 1 )
  {
    v7->m_oCurrent = 0i64;
    v9 = RumbleDeviceHelper::InitRumbleController(v6, v5, in_pDevice);
    v7->m_pRumbleDevice = v9;
    result = 2 - (v9 != 0i64);
  }
  return result;
}

// File Line: 26
// RVA: 0xACD180
AKRESULT __fastcall RumbleMixBus::Term(RumbleMixBus *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  RumbleMixBus *v2; // rbx
  IAkRumbleController *v3; // rcx
  AK::IAkPluginMemAlloc *v4; // rdi

  v2 = this;
  v3 = this->m_pRumbleDevice;
  v4 = in_pAllocator;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Term)();
    v2->m_pRumbleDevice = 0i64;
  }
  return RumbleBusBase::Term((RumbleBusBase *)&v2->vfptr, v4);
}

// File Line: 36
// RVA: 0xACD0B0
_BOOL8 __fastcall RumbleMixBus::SendSample(RumbleMixBus *this)
{
  __int64 v1; // rax
  RumbleMixBus *v2; // rbx
  float v3; // xmm7_4
  float v4; // xmm6_4
  _BOOL8 result; // rax
  IAkRumbleController *v6; // rcx

  v1 = this->m_usReadBuffer;
  v2 = this;
  v3 = this->m_pData[v1];
  if ( v3 < 0.0 )
    v3 = 0.0;
  v4 = this->m_pData[v1 + 1];
  if ( v4 < 0.0 )
    v4 = 0.0;
  result = (float)(v4 + v3) == 0.0;
  this->m_bStopped = result;
  if ( v3 > 1.0 )
    v3 = *(float *)&FLOAT_1_0;
  if ( v4 > 1.0 )
    v4 = *(float *)&FLOAT_1_0;
  v6 = this->m_pRumbleDevice;
  if ( v6 && (v3 != v2->m_oCurrent.m_fLarge || v4 != v2->m_oCurrent.m_fSmall) )
  {
    if ( ((__int64 (*)(void))v6->vfptr->SetRumble)() == 77 )
    {
      v2->m_bStopped = 0;
    }
    else
    {
      v2->m_oCurrent.m_fLarge = v3;
      v2->m_oCurrent.m_fSmall = v4;
    }
    result = v2->m_bStopped;
  }
  return result;
}

// File Line: 77
// RVA: 0xACD090
bool __fastcall RumbleMixBus::IsActive(RumbleMixBus *this)
{
  IAkRumbleController *v1; // rcx
  bool result; // al

  v1 = this->m_pRumbleDevice;
  if ( v1 )
    result = ((__int64 (*)(void))v1->vfptr->IsActive)();
  else
    result = 0;
  return result;
}

