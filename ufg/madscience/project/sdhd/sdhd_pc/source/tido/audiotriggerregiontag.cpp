// File Line: 51
// RVA: 0x592F90
void __fastcall UFG::AudioTriggerRegionTag::AudioTriggerRegionTag(UFG::AudioTriggerRegionTag *this)
{
  this->mPrev = &this->UFG::qNode<UFG::AudioTriggerRegionTag,UFG::AudioTriggerRegionTag>;
  this->mNext = &this->UFG::qNode<UFG::AudioTriggerRegionTag,UFG::AudioTriggerRegionTag>;
  this->vfptr = (UFG::AudioTriggerRegionTagVtbl *)&UFG::AudioTriggerRegionTag::`vftable;
  this->mAudioUidOnEnter.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  this->mAudioUidOnExit.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  this->mAudioModeUidOnEnter.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  this->mAudioModeUidOnExit.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  this->mAudioType = 0;
  UFG::qWiseSymbol::set_null(&this->mAudioUidOnEnter);
  UFG::qWiseSymbol::set_null(&this->mAudioUidOnExit);
  UFG::qWiseSymbol::set_null(&this->mAudioModeUidOnEnter);
  *(_QWORD *)&this->mAudioRtpcValOnEnter = 0i64;
  this->mAudioWetLevelOnEnter = 0.0;
  UFG::qWiseSymbol::set_null(&this->mAudioModeUidOnExit);
  *(_QWORD *)&this->mAudioRtpcValOnExit = 0i64;
  this->mAudioWetLevelOnExit = 0.0;
}

// File Line: 103
// RVA: 0x59CA70
UFG::qWiseSymbol *__fastcall UFG::AudioTriggerRegionTag::FromPropertySet(UFG::qPropertySet *pSet)
{
  UFG::allocator::free_link *v2; // rax
  UFG::qWiseSymbol *v3; // rax
  UFG::qWiseSymbol *v4; // rbx
  unsigned int *p_mUID; // rax
  UFG::qWiseSymbol *v6; // r14
  UFG::qWiseSymbol *v7; // rbp
  UFG::qWiseSymbol *v8; // rsi
  float *v9; // rax
  float *v10; // rax
  float *v11; // rax

  v2 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x48ui64, "AudioTriggerRegionTag.FromPropertySet", 0i64, 1u);
  if ( v2 )
  {
    UFG::AudioTriggerRegionTag::AudioTriggerRegionTag((UFG::AudioTriggerRegionTag *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  p_mUID = UFG::qPropertySet::Get<unsigned long>(
             pSet,
             (UFG::qArray<unsigned long,0> *)&TiDoSym_AudioType,
             DEPTH_RECURSE);
  if ( !p_mUID )
    p_mUID = &v4[6].mUID;
  v4[6].mUID = *p_mUID;
  v6 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(
         pSet,
         (UFG::qArray<unsigned long,0> *)&TiDoSym_OnEnterSymbol,
         DEPTH_RECURSE);
  v7 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(
         pSet,
         (UFG::qArray<unsigned long,0> *)&TiDoSym_OnExitSymbol,
         DEPTH_RECURSE);
  v8 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(pSet, (UFG::qArray<unsigned long,0> *)&TiDoSym_ModeUid, DEPTH_RECURSE);
  v9 = UFG::qPropertySet::Get<float>(pSet, (UFG::qArray<unsigned long,0> *)&TiDoSym_RtpcVal, DEPTH_RECURSE);
  if ( !v9 )
    v9 = (float *)&v4[10].mUID;
  v4[10].mUID = *(unsigned int *)v9;
  v10 = UFG::qPropertySet::Get<float>(pSet, (UFG::qArray<unsigned long,0> *)&TiDoSym_DryLevel, DEPTH_RECURSE);
  if ( !v10 )
    v10 = (float *)&v4[11].mUID;
  v4[11].mUID = *(unsigned int *)v10;
  v11 = UFG::qPropertySet::Get<float>(pSet, (UFG::qArray<unsigned long,0> *)&TiDoSym_WetLevel, DEPTH_RECURSE);
  if ( !v11 )
    v11 = (float *)&v4[12].mUID;
  v4[12].mUID = *(unsigned int *)v11;
  if ( v6 )
    UFG::qWiseSymbol::operator=(v4 + 7, v6);
  if ( v7 )
    UFG::qWiseSymbol::operator=(v4 + 8, v7);
  if ( v8 )
    UFG::qWiseSymbol::operator=(v4 + 9, v8);
  return v4;
}

