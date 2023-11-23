// File Line: 155
// RVA: 0x141520
void __fastcall AK::StreamMgr::IAkLowLevelIOHook::~IAkLowLevelIOHook(AK::StreamMgr::IAkLowLevelIOHook *this)
{
  this->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&AK::StreamMgr::IAkLowLevelIOHook::`vftable;
}

// File Line: 275
// RVA: 0x1414F0
void __fastcall AK::StreamMgr::IAkIOHookDeferred::~IAkIOHookDeferred(AK::StreamMgr::IAkIOHookDeferred *this)
{
  this->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&AK::StreamMgr::IAkIOHookDeferred::`vftable;
  this->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&AK::StreamMgr::IAkLowLevelIOHook::`vftable;
}

// File Line: 384
// RVA: 0x1414E0
void __fastcall AK::StreamMgr::IAkFileLocationResolver::~IAkFileLocationResolver(
        AK::StreamMgr::IAkFileLocationResolver *this)
{
  this->vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&AK::StreamMgr::IAkFileLocationResolver::`vftable;
}

