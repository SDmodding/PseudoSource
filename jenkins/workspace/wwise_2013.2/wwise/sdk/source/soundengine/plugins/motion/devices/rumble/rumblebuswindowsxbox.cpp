// File Line: 11
// RVA: 0xACCFE0
void __fastcall RumbleMixBus::RumbleMixBus(RumbleMixBus *this)
{
  RumbleBusBase::RumbleBusBase(this);
  this->vfptr = (AK::IAkPluginVtbl *)&RumbleMixBus::`vftable;
  this->m_pRumbleDevice = 0i64;
  this->m_oCurrent = 0i64;
}

// File Line: 16
// RVA: 0xACD020
int __fastcall RumbleMixBus::Init(
        RumbleMixBus *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AkPlatformInitSettings *io_pPDSettings,
        char in_iPlayer,
        void *in_pDevice)
{
  int result; // eax
  IAkRumbleController *inited; // rax

  result = RumbleBusBase::Init(this, in_pAllocator, io_pPDSettings, in_iPlayer, in_pDevice);
  if ( result == 1 )
  {
    this->m_oCurrent = 0i64;
    inited = RumbleDeviceHelper::InitRumbleController(in_pAllocator, in_iPlayer, in_pDevice);
    this->m_pRumbleDevice = inited;
    return 2 - (inited != 0i64);
  }
  return result;
}

// File Line: 26
// RVA: 0xACD180
AKRESULT __fastcall RumbleMixBus::Term(RumbleMixBus *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  IAkRumbleController *m_pRumbleDevice; // rcx

  m_pRumbleDevice = this->m_pRumbleDevice;
  if ( m_pRumbleDevice )
  {
    ((void (__fastcall *)(IAkRumbleController *))m_pRumbleDevice->vfptr->Term)(m_pRumbleDevice);
    this->m_pRumbleDevice = 0i64;
  }
  return RumbleBusBase::Term(this, in_pAllocator);
}

// File Line: 36
// RVA: 0xACD0B0
_BOOL8 __fastcall RumbleMixBus::SendSample(RumbleMixBus *this)
{
  __int64 m_usReadBuffer; // rax
  float v3; // xmm7_4
  float v4; // xmm6_4
  _BOOL8 result; // rax
  IAkRumbleController *m_pRumbleDevice; // rcx

  m_usReadBuffer = this->m_usReadBuffer;
  v3 = this->m_pData[m_usReadBuffer];
  if ( v3 < 0.0 )
    v3 = 0.0;
  v4 = this->m_pData[m_usReadBuffer + 1];
  if ( v4 < 0.0 )
    v4 = 0.0;
  result = (float)(v4 + v3) == 0.0;
  this->m_bStopped = result;
  if ( v3 > 1.0 )
    v3 = *(float *)&FLOAT_1_0;
  if ( v4 > 1.0 )
    v4 = *(float *)&FLOAT_1_0;
  m_pRumbleDevice = this->m_pRumbleDevice;
  if ( m_pRumbleDevice && (v3 != this->m_oCurrent.m_fLarge || v4 != this->m_oCurrent.m_fSmall) )
  {
    if ( ((unsigned __int64 (__fastcall *)(IAkRumbleController *))m_pRumbleDevice->vfptr->SetRumble)(m_pRumbleDevice) == 77 )
    {
      this->m_bStopped = 0;
    }
    else
    {
      this->m_oCurrent.m_fLarge = v3;
      this->m_oCurrent.m_fSmall = v4;
    }
    return this->m_bStopped;
  }
  return result;
}

// File Line: 77
// RVA: 0xACD090
bool __fastcall RumbleMixBus::IsActive(RumbleMixBus *this)
{
  IAkRumbleController *m_pRumbleDevice; // rcx

  m_pRumbleDevice = this->m_pRumbleDevice;
  return m_pRumbleDevice && m_pRumbleDevice->vfptr->IsActive(m_pRumbleDevice);
}

