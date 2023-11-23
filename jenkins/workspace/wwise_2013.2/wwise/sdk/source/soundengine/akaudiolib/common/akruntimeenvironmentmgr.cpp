// File Line: 29
// RVA: 0xA9AD30
AK::AkRuntimeEnvironmentMgr *__fastcall AK::AkRuntimeEnvironmentMgr::Instance()
{
  if ( (_S1_35 & 1) == 0 )
  {
    _S1_35 |= 1u;
    AK::AkRuntimeEnvironmentMgr::AkRuntimeEnvironmentMgr(&g_RuntimeEnvMgr);
    atexit(AK::AkRuntimeEnvironmentMgr::Instance_::_2_::_dynamic_atexit_destructor_for__g_RuntimeEnvMgr__);
  }
  return &g_RuntimeEnvMgr;
}

// File Line: 35
// RVA: 0xA9AC00
void __fastcall AK::AkRuntimeEnvironmentMgr::AkRuntimeEnvironmentMgr(AK::AkRuntimeEnvironmentMgr *this)
{
  __int16 v1; // r9
  int v4; // r10d

  v1 = 0;
  this->vfptr = (AK::IAkProcessorFeaturesVtbl *)&AK::AkRuntimeEnvironmentMgr::`vftable;
  *(_QWORD *)&this->ProcessorInfo.uSIMDProcessorSupport = 0i64;
  this->ProcessorInfo.uCacheLineSize = 0;
  _RAX = 0i64;
  v4 = 0;
  __asm { cpuid; Get CPU ID }
  if ( (int)_RAX >= 1 )
  {
    _RAX = 1i64;
    __asm { cpuid; Get CPU ID }
    v4 = _RDX;
    v1 = _RCX;
  }
  _RAX = 0x80000000i64;
  __asm { cpuid; Get CPU ID }
  if ( (unsigned int)_RAX < 0x80000006 )
  {
    this->ProcessorInfo.uCacheLineSize = 64;
    this->ProcessorInfo.uL2CacheSize = 1024;
  }
  else
  {
    _RAX = 2147483654i64;
    __asm { cpuid; Get CPU ID }
    this->ProcessorInfo.uCacheLineSize = (unsigned __int8)_RCX;
    this->ProcessorInfo.uL2CacheSize = WORD1(_RCX);
  }
  if ( (v4 & 0x2000000) != 0 )
    this->ProcessorInfo.uSIMDProcessorSupport |= 1u;
  if ( (v4 & 0x4000000) != 0 )
    this->ProcessorInfo.uSIMDProcessorSupport |= 2u;
  if ( (v1 & 1) != 0 )
    this->ProcessorInfo.uSIMDProcessorSupport |= 4u;
  if ( (v1 & 0x200) != 0 )
    this->ProcessorInfo.uSIMDProcessorSupport |= 8u;
}

// File Line: 76
// RVA: 0xA9AD20
bool __fastcall AK::AkRuntimeEnvironmentMgr::GetSIMDSupport(
        AK::AkRuntimeEnvironmentMgr *this,
        AK::AkSIMDProcessorSupport in_eSIMD)
{
  return (in_eSIMD & this->ProcessorInfo.uSIMDProcessorSupport) != 0;
}

// File Line: 81
// RVA: 0xA9AD10
__int64 __fastcall AK::AkRuntimeEnvironmentMgr::GetCacheSize(AK::AkRuntimeEnvironmentMgr *this)
{
  return this->ProcessorInfo.uL2CacheSize;
}

