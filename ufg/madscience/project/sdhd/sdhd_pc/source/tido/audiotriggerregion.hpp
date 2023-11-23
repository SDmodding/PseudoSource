// File Line: 56
// RVA: 0x5940A0
void __fastcall UFG::AudioTriggerRegionEvent::~AudioTriggerRegionEvent(UFG::AudioTriggerRegionEvent *this)
{
  this->vfptr = (UFG::AudioTriggerRegionEventVtbl *)&UFG::AudioTriggerRegionEvent::`vftable;
  _((AMD_HD3D *)this->mAudioModeUid.mUID);
  _((AMD_HD3D *)this->mAudioUidOnExit.mUID);
  _((AMD_HD3D *)this->mAudioUidOnEnter.mUID);
}

// File Line: 81
// RVA: 0x595BB0
UFG::ComponentIDDesc *__fastcall UFG::AudioTriggerRegion::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::AudioTriggerRegion::_DescInit )
  {
    v0 = UFG::TriggerRegion::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::AudioTriggerRegion::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::AudioTriggerRegion::_TypeIDesc.mChildBitMask = v1;
    UFG::AudioTriggerRegion::_TypeIDesc.mChildren = 0;
    UFG::AudioTriggerRegion::_DescInit = 1;
    UFG::AudioTriggerRegion::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::AudioTriggerRegion::_AudioTriggerRegionTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::AudioTriggerRegion::_TypeIDesc;
}

// File Line: 106
// RVA: 0x59D6E0
__int64 __fastcall UFG::AudioTriggerRegion::GetType(Render::SimpleDrawableComponent *this)
{
  return 256i64;
}

// File Line: 140
// RVA: 0x59D3D0
char __fastcall UFG::AudioTriggerRegion::GetObstructionAndOcclusion(
        UFG::AudioTriggerRegion *this,
        float *obs,
        float *occ)
{
  *obs = this->m_obsValue;
  *occ = this->m_occValue;
  return 1;
}

