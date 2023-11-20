// File Line: 29
// RVA: 0xA9AD30
AK::AkRuntimeEnvironmentMgr *__fastcall AK::AkRuntimeEnvironmentMgr::Instance()
{
  if ( !(_S1_35 & 1) )
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
  int v1; // er9
  AK::AkRuntimeEnvironmentMgr *v2; // r8
  int v4; // er10

  v1 = 0;
  v2 = this;
  this->vfptr = (AK::IAkProcessorFeaturesVtbl *)&AK::AkRuntimeEnvironmentMgr::`vftable';
  *(_QWORD *)&this->ProcessorInfo.uSIMDProcessorSupport = 0i64;
  this->ProcessorInfo.uCacheLineSize = 0;
  _RAX = 0i64;
  v4 = 0;
  __asm { cpuid; Get CPU ID }
  if ( (signed int)_RAX >= 1 )
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
    v2->ProcessorInfo.uCacheLineSize = 64;
    v2->ProcessorInfo.uL2CacheSize = 1024;
  }
  else
  {
    _RAX = 2147483654i64;
    __asm { cpuid; Get CPU ID }
    v2->ProcessorInfo.uCacheLineSize = (unsigned __int8)_RCX;
    v2->ProcessorInfo.uL2CacheSize = WORD1(_RCX);
  }
  if ( _bittest(&v4, 0x19u) )
    v2->ProcessorInfo.uSIMDProcessorSupport |= 1u;
  if ( _bittest(&v4, 0x1Au) )
    v2->ProcessorInfo.uSIMDProcessorSupport |= 2u;
  if ( v1 & 1 )
    v2->ProcessorInfo.uSIMDProcessorSupport |= 4u;
  if ( _bittest(&v1, 9u) )
    v2->ProcessorInfo.uSIMDProcessorSupport |= 8u;
}

// File Line: 76
// RVA: 0xA9AD20
bool __fastcall AK::AkRuntimeEnvironmentMgr::GetSIMDSupport(AK::AkRuntimeEnvironmentMgr *this, AK::AkSIMDProcessorSupport in_eSIMD)
{
  return (in_eSIMD & this->ProcessorInfo.uSIMDProcessorSupport) != 0;
}

// File Line: 81
// RVA: 0xA9AD10
__int64 __fastcall AK::AkRuntimeEnvironmentMgr::GetCacheSize(AK::AkRuntimeEnvironmentMgr *this)
{
  return this->ProcessorInfo.uL2CacheSize;
}

