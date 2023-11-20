// File Line: 133
// RVA: 0x140C70
void __fastcall UFG::WwiseFilePackageLowLevelIODeferred::WwiseFilePackageLowLevelIODeferred(UFG::WwiseFilePackageLowLevelIODeferred *this)
{
  UFG::WwiseFilePackageLowLevelIODeferred *v1; // rbx

  v1 = this;
  UFG::WwiseDefaultIOHookDeferred::WwiseDefaultIOHookDeferred((UFG::WwiseDefaultIOHookDeferred *)&this->vfptr);
  v1->vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::`vftable'{for `AK::StreamMgr::IAkFileLocationResolver'};
  v1->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::`vftable'{for `AK::StreamMgr::IAkIOHookDeferred'};
  v1->vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::`vftable'{for `UFG::WwiseFileLocationBase'};
  v1->m_packages.m_pFirst = 0i64;
  v1->vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&UFG::WwiseFilePackageLowLevelIODeferred::`vftable'{for `AK::StreamMgr::IAkFileLocationResolver'};
  v1->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&UFG::WwiseFilePackageLowLevelIODeferred::`vftable'{for `AK::StreamMgr::IAkIOHookDeferred'};
  v1->vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseFilePackageLowLevelIODeferred::`vftable'{for `UFG::WwiseFileLocationBase'};
}

