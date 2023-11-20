// File Line: 51
// RVA: 0x592F90
void __fastcall UFG::AudioTriggerRegionTag::AudioTriggerRegionTag(UFG::AudioTriggerRegionTag *this)
{
  UFG::AudioTriggerRegionTag *v1; // r15
  UFG::qNode<UFG::AudioTriggerRegionTag,UFG::AudioTriggerRegionTag> *v2; // rax

  v1 = this;
  v2 = (UFG::qNode<UFG::AudioTriggerRegionTag,UFG::AudioTriggerRegionTag> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::AudioTriggerRegionTagVtbl *)&UFG::AudioTriggerRegionTag::`vftable;
  this->mAudioUidOnEnter.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  v1->mAudioUidOnExit.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  v1->mAudioModeUidOnEnter.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  v1->mAudioModeUidOnExit.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  v1->mAudioType = 0;
  UFG::qWiseSymbol::set_null(&v1->mAudioUidOnEnter);
  UFG::qWiseSymbol::set_null(&v1->mAudioUidOnExit);
  UFG::qWiseSymbol::set_null(&v1->mAudioModeUidOnEnter);
  *(_QWORD *)&v1->mAudioRtpcValOnEnter = 0i64;
  v1->mAudioWetLevelOnEnter = 0.0;
  UFG::qWiseSymbol::set_null(&v1->mAudioModeUidOnExit);
  *(_QWORD *)&v1->mAudioRtpcValOnExit = 0i64;
  v1->mAudioWetLevelOnExit = 0.0;
}

// File Line: 103
// RVA: 0x59CA70
UFG::qWiseSymbol *__fastcall UFG::AudioTriggerRegionTag::FromPropertySet(UFG::qPropertySet *pSet)
{
  UFG::qPropertySet *v1; // rdi
  UFG::allocator::free_link *v2; // rax
  UFG::qWiseSymbol *v3; // rax
  UFG::qWiseSymbol *v4; // rbx
  unsigned int *v5; // rax
  UFG::qWiseSymbol *v6; // r14
  UFG::qWiseSymbol *v7; // rbp
  UFG::qWiseSymbol *v8; // rsi
  float *v9; // rax
  float *v10; // rax
  float *v11; // rax

  v1 = pSet;
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
  v5 = UFG::qPropertySet::Get<unsigned long>(v1, (UFG::qSymbol *)&TiDoSym_AudioType.mUID, DEPTH_RECURSE);
  if ( !v5 )
    v5 = &v4[6].mUID;
  v4[6].mUID = *v5;
  v6 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v1, (UFG::qSymbol *)&TiDoSym_OnEnterSymbol.mUID, DEPTH_RECURSE);
  v7 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v1, (UFG::qSymbol *)&TiDoSym_OnExitSymbol.mUID, DEPTH_RECURSE);
  v8 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v1, (UFG::qSymbol *)&TiDoSym_ModeUid.mUID, DEPTH_RECURSE);
  v9 = UFG::qPropertySet::Get<float>(v1, (UFG::qSymbol *)&TiDoSym_RtpcVal.mUID, DEPTH_RECURSE);
  if ( !v9 )
    v9 = (float *)&v4[10].mUID;
  v4[10].mUID = *(unsigned int *)v9;
  v10 = UFG::qPropertySet::Get<float>(v1, (UFG::qSymbol *)&TiDoSym_DryLevel.mUID, DEPTH_RECURSE);
  if ( !v10 )
    v10 = (float *)&v4[11].mUID;
  v4[11].mUID = *(unsigned int *)v10;
  v11 = UFG::qPropertySet::Get<float>(v1, (UFG::qSymbol *)&TiDoSym_WetLevel.mUID, DEPTH_RECURSE);
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

