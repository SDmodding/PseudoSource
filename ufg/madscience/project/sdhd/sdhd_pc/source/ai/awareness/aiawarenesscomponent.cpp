// File Line: 38
// RVA: 0x14B9510
__int64 dynamic_initializer_for__UFG::AIAwarenessComponent::s_AIAwarenessComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AIAwarenessComponent::s_AIAwarenessComponentList__);
}

// File Line: 39
// RVA: 0x14B94A0
__int64 dynamic_initializer_for__UFG::AIAwarenessComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::AIAwarenessComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::AIAwarenessComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::AIAwarenessComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::AIAwarenessComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 43
// RVA: 0x399920
void __fastcall UFG::AIAwarenessComponent::AIAwarenessComponent(UFG::AIAwarenessComponent *this, unsigned int nameUid)
{
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *v3; // r15
  __int64 i; // rsi
  UFG::qString *v5; // rax
  UFG::AIAwareness::Profile *v6; // rdi
  const char *v7; // rbx
  UFG::allocator::free_link *v8; // rax
  UFG::AIAwareness::Effector *v9; // rdx
  float y; // xmm1_4
  float z; // xmm2_4
  char v12; // cl
  UFG::allocator::free_link *v13; // rax
  UFG::AIAwareness::Effector *v14; // rdx
  float v15; // xmm1_4
  float v16; // xmm2_4
  char v17; // cl
  UFG::AIAwareness::KnowledgeSpace *v18; // rbx
  float v19; // xmm0_4
  float v20; // xmm1_4
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *mPrev; // rax
  void *result; // [rsp+90h] [rbp+18h] BYREF
  UFG::allocator::free_link *v23; // [rsp+98h] [rbp+20h]

  UFG::SimComponent::SimComponent(this, nameUid);
  v3 = &this->UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent>;
  this->mPrev = &this->UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent>;
  this->mNext = &this->UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIAwarenessComponent::`vftable;
  if ( !sInitialized )
  {
    for ( i = 0i64; i < 4; ++i )
    {
      v5 = (UFG::qString *)UFG::qMalloc(0xB0ui64, "TEMPAwarenessProfile", 0i64);
      v6 = (UFG::AIAwareness::Profile *)v5;
      v23 = (UFG::allocator::free_link *)v5;
      if ( v5 )
      {
        v7 = s_TEMP_AwarenessProfileNames[i];
        UFG::qString::qString(v5);
        v6->mSymbol.mUID = -1;
        UFG::qString::Set(&v6->mName, v7);
        v6->mSymbol = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, v7)->mUID;
      }
      else
      {
        v6 = 0i64;
      }
      s_TEMPProfiles[i] = v6;
    }
    s_TEMPProfiles[0]->mAIProperties[0].mWaitTimeMin = 1.0;
    s_TEMPProfiles[0]->mAIProperties[0].mWaitTimeMax = 1.5;
    s_TEMPProfiles[0]->mAIProperties[0].mNewTargetTimeMin = 2.0;
    s_TEMPProfiles[0]->mAIProperties[0].mNewTargetTimeMax = 3.0;
    s_TEMPProfiles[0]->mAIProperties[0].mMaxAngle = 45.0;
    s_TEMPProfiles[0]->mAIProperties[0].mPersonalSpaceScoreBonus = 2.0;
    s_TEMPProfiles[0]->mAIProperties[0].mPersonalSpaceMaxAngle = 100.0;
    s_TEMPProfiles[0]->mAIProperties[0].mPersonalSpaceDistance = 5.0;
    s_TEMPProfiles[0]->mAIProperties[0].mHeightOffsetAngle = 0.0;
    s_TEMPProfiles[0]->mAIProperties[0].mInvalidAngle = 120.0;
    s_TEMPProfiles[0]->mAIProperties[1].mWaitTimeMin = 0.5;
    s_TEMPProfiles[0]->mAIProperties[1].mWaitTimeMax = 0.80000001;
    s_TEMPProfiles[0]->mAIProperties[1].mNewTargetTimeMin = 0.5;
    s_TEMPProfiles[0]->mAIProperties[1].mNewTargetTimeMax = 0.80000001;
    s_TEMPProfiles[0]->mAIProperties[1].mMaxAngle = 2.0;
    s_TEMPProfiles[0]->mAIProperties[1].mPersonalSpaceScoreBonus = 2.0;
    s_TEMPProfiles[0]->mAIProperties[1].mPersonalSpaceMaxAngle = 10.0;
    s_TEMPProfiles[0]->mAIProperties[1].mPersonalSpaceDistance = 5.0;
    s_TEMPProfiles[0]->mAIProperties[1].mHeightOffsetAngle = 0.0;
    s_TEMPProfiles[0]->mAIProperties[1].mInvalidAngle = 45.0;
    s_TEMPProfiles[0]->mAnimationProperties.mEnableHeadTrack = 1;
    s_TEMPProfiles[0]->mAnimationProperties.mEnableEyeTrack = 1;
    s_TEMPProfiles[0]->mAnimationProperties.mEnableSpineTrack = 1;
    s_TEMPProfiles[0]->mAnimationProperties.mHeadTrackLimitX = 0.875;
    s_TEMPProfiles[0]->mAnimationProperties.mHeadTrackLimitY = 0.40000001;
    s_TEMPProfiles[0]->mAnimationProperties.mHeadTrackLimitZ = 0.40000001;
    s_TEMPProfiles[0]->mAnimationProperties.mEyeTrackLimitX = 0.050000001;
    s_TEMPProfiles[0]->mAnimationProperties.mEyeTrackLimitY = 0.30000001;
    s_TEMPProfiles[0]->mAnimationProperties.mEyeTrackLimitZ = 0.0;
    s_TEMPProfiles[0]->mAnimationProperties.mSpineTrackLimitX = 0.0;
    s_TEMPProfiles[0]->mAnimationProperties.mSpineTrackLimitY = 0.0;
    s_TEMPProfiles[0]->mAnimationProperties.mSpineTrackLimitZ = 0.69999999;
    s_TEMPProfiles[0]->mAnimationProperties.mHeadTrackGain = 0.050000001;
    s_TEMPProfiles[0]->mAnimationProperties.mEyeTrackGain = 0.30000001;
    s_TEMPProfiles[0]->mAnimationProperties.mSpineTrackGain = 0.025;
    *(_DWORD *)(qword_1423CDFF8 + 44) = 0;
    *(_DWORD *)(qword_1423CDFF8 + 48) = 1069547520;
    *(_DWORD *)(qword_1423CDFF8 + 52) = 1065353216;
    *(_DWORD *)(qword_1423CDFF8 + 56) = 1075838976;
    *(_DWORD *)(qword_1423CDFF8 + 60) = 1110704128;
    *(_DWORD *)(qword_1423CDFF8 + 64) = 0x40000000;
    *(_DWORD *)(qword_1423CDFF8 + 68) = 1120403456;
    *(_DWORD *)(qword_1423CDFF8 + 72) = 1084227584;
    *(_DWORD *)(qword_1423CDFF8 + 76) = 0;
    *(_DWORD *)(qword_1423CDFF8 + 80) = 1117782016;
    *(_DWORD *)(qword_1423CDFF8 + 84) = 1056964608;
    *(_DWORD *)(qword_1423CDFF8 + 88) = 1061997773;
    *(_DWORD *)(qword_1423CDFF8 + 92) = 1056964608;
    *(_DWORD *)(qword_1423CDFF8 + 96) = 1061997773;
    *(_DWORD *)(qword_1423CDFF8 + 100) = 1110704128;
    *(_DWORD *)(qword_1423CDFF8 + 104) = 0x40000000;
    *(_DWORD *)(qword_1423CDFF8 + 108) = 1114636288;
    *(_DWORD *)(qword_1423CDFF8 + 112) = 1084227584;
    *(_DWORD *)(qword_1423CDFF8 + 116) = 0;
    *(_DWORD *)(qword_1423CDFF8 + 120) = 1123024896;
    *(_BYTE *)(qword_1423CDFF8 + 124) = 1;
    *(_BYTE *)(qword_1423CDFF8 + 125) = 1;
    *(_BYTE *)(qword_1423CDFF8 + 126) = 1;
    *(_DWORD *)(qword_1423CDFF8 + 128) = 1063256064;
    *(_DWORD *)(qword_1423CDFF8 + 132) = 1053609165;
    *(_DWORD *)(qword_1423CDFF8 + 136) = 1053609165;
    *(_DWORD *)(qword_1423CDFF8 + 140) = 1041865114;
    *(_DWORD *)(qword_1423CDFF8 + 144) = 1050253722;
    *(_DWORD *)(qword_1423CDFF8 + 148) = 0;
    *(_DWORD *)(qword_1423CDFF8 + 152) = 0;
    *(_DWORD *)(qword_1423CDFF8 + 156) = 0;
    *(_DWORD *)(qword_1423CDFF8 + 160) = 1060320051;
    *(_DWORD *)(qword_1423CDFF8 + 164) = 1033476506;
    *(_DWORD *)(qword_1423CDFF8 + 168) = 1050253722;
    *(_DWORD *)(qword_1423CDFF8 + 172) = 1020054733;
    *(_DWORD *)(qword_1423CE000 + 44) = 0;
    *(_DWORD *)(qword_1423CE000 + 48) = 1056964608;
    *(_DWORD *)(qword_1423CE000 + 52) = 1069547520;
    *(_DWORD *)(qword_1423CE000 + 56) = 1077936128;
    *(_DWORD *)(qword_1423CE000 + 60) = 1114636288;
    *(_DWORD *)(qword_1423CE000 + 64) = 0x40000000;
    *(_DWORD *)(qword_1423CE000 + 68) = 1117782016;
    *(_DWORD *)(qword_1423CE000 + 72) = 1084227584;
    *(_DWORD *)(qword_1423CE000 + 76) = -1039400960;
    *(_DWORD *)(qword_1423CE000 + 80) = 1123024896;
    *(_DWORD *)(qword_1423CE000 + 84) = 1045220557;
    *(_DWORD *)(qword_1423CE000 + 88) = 1053609165;
    *(_DWORD *)(qword_1423CE000 + 92) = 0x40000000;
    *(_DWORD *)(qword_1423CE000 + 96) = 1077936128;
    *(_DWORD *)(qword_1423CE000 + 100) = 1117782016;
    *(_DWORD *)(qword_1423CE000 + 104) = 0x40000000;
    *(_DWORD *)(qword_1423CE000 + 108) = 1120403456;
    *(_DWORD *)(qword_1423CE000 + 112) = 1084227584;
    *(_DWORD *)(qword_1423CE000 + 116) = 0;
    *(_DWORD *)(qword_1423CE000 + 120) = 1123024896;
    *(_BYTE *)(qword_1423CE000 + 124) = 1;
    *(_BYTE *)(qword_1423CE000 + 125) = 1;
    *(_BYTE *)(qword_1423CE000 + 126) = 1;
    *(_DWORD *)(qword_1423CE000 + 128) = 1050253722;
    *(_DWORD *)(qword_1423CE000 + 132) = 1053609165;
    *(_DWORD *)(qword_1423CE000 + 136) = 1053609165;
    *(_DWORD *)(qword_1423CE000 + 140) = 1036831949;
    *(_DWORD *)(qword_1423CE000 + 144) = 1053609165;
    *(_DWORD *)(qword_1423CE000 + 148) = 0;
    *(_DWORD *)(qword_1423CE000 + 152) = 0;
    *(_DWORD *)(qword_1423CE000 + 156) = 0;
    *(_DWORD *)(qword_1423CE000 + 160) = 1045220557;
    *(_DWORD *)(qword_1423CE000 + 164) = 1036831949;
    *(_DWORD *)(qword_1423CE000 + 168) = 1050253722;
    *(_DWORD *)(qword_1423CE000 + 172) = 1020054733;
    *(_DWORD *)(qword_1423CE008 + 44) = 1065353216;
    *(_DWORD *)(qword_1423CE008 + 48) = 1069547520;
    *(_DWORD *)(qword_1423CE008 + 52) = 1077936128;
    *(_DWORD *)(qword_1423CE008 + 56) = 1082130432;
    *(_DWORD *)(qword_1423CE008 + 60) = 1110704128;
    *(_DWORD *)(qword_1423CE008 + 64) = 0x40000000;
    *(_DWORD *)(qword_1423CE008 + 68) = 1120403456;
    *(_DWORD *)(qword_1423CE008 + 72) = 1084227584;
    *(_DWORD *)(qword_1423CE008 + 76) = 1108082688;
    *(_DWORD *)(qword_1423CE008 + 80) = 1123024896;
    *(_DWORD *)(qword_1423CE008 + 84) = 1056964608;
    *(_DWORD *)(qword_1423CE008 + 88) = 1061997773;
    *(_DWORD *)(qword_1423CE008 + 92) = 1077936128;
    *(_DWORD *)(qword_1423CE008 + 96) = 1082130432;
    *(_DWORD *)(qword_1423CE008 + 100) = 1117782016;
    *(_DWORD *)(qword_1423CE008 + 104) = 0x40000000;
    *(_DWORD *)(qword_1423CE008 + 108) = 1117782016;
    *(_DWORD *)(qword_1423CE008 + 112) = 1084227584;
    *(_DWORD *)(qword_1423CE008 + 116) = 0;
    *(_DWORD *)(qword_1423CE008 + 120) = 1123024896;
    *(_BYTE *)(qword_1423CE008 + 124) = 1;
    *(_BYTE *)(qword_1423CE008 + 125) = 1;
    *(_BYTE *)(qword_1423CE008 + 126) = 1;
    *(_DWORD *)(qword_1423CE008 + 128) = 1063256064;
    *(_DWORD *)(qword_1423CE008 + 132) = 1053609165;
    *(_DWORD *)(qword_1423CE008 + 136) = 1053609165;
    *(_DWORD *)(qword_1423CE008 + 140) = 1041865114;
    *(_DWORD *)(qword_1423CE008 + 144) = 1050253722;
    *(_DWORD *)(qword_1423CE008 + 148) = 0;
    *(_DWORD *)(qword_1423CE008 + 152) = 0;
    *(_DWORD *)(qword_1423CE008 + 156) = 0;
    *(_DWORD *)(qword_1423CE008 + 160) = 1060320051;
    *(_DWORD *)(qword_1423CE008 + 164) = 1028443341;
    *(_DWORD *)(qword_1423CE008 + 168) = 1050253722;
    *(_DWORD *)(qword_1423CE008 + 172) = 1020054733;
    sInitialized = 1;
  }
  v8 = UFG::qMalloc(0xE8ui64, "AwarenessEffector", 0i64);
  v9 = (UFG::AIAwareness::Effector *)v8;
  result = v8;
  if ( v8 )
  {
    LODWORD(v8->mNext) = 0;
    v8[1].mNext = 0i64;
    v8[4].mNext = 0i64;
    v8[5].mNext = 0i64;
    LODWORD(v8[6].mNext) = 1;
    v23 = v8 + 7;
    v8[7].mNext = v8 + 7;
    v8[8].mNext = v8 + 7;
    v8[9].mNext = 0i64;
    y = UFG::qVector3::msAxisX.y;
    z = UFG::qVector3::msAxisX.z;
    HIDWORD(v8[11].mNext) = LODWORD(UFG::qVector3::msAxisX.x);
    *(float *)&v8[12].mNext = y;
    *((float *)&v8[12].mNext + 1) = z;
    LODWORD(v8[13].mNext) = 0;
    v8[26].mNext = 0i64;
    LODWORD(v8[28].mNext) = 0;
    v12 = byte_1423CE011;
    if ( !byte_1423CE011 )
      v12 = 1;
    byte_1423CE011 = v12;
  }
  else
  {
    v9 = 0i64;
  }
  this->mpHeadEffector = v9;
  v13 = UFG::qMalloc(0xE8ui64, "AwarenessEffector", 0i64);
  v14 = (UFG::AIAwareness::Effector *)v13;
  result = v13;
  if ( v13 )
  {
    LODWORD(v13->mNext) = 1;
    v13[1].mNext = 0i64;
    v13[4].mNext = 0i64;
    v13[5].mNext = 0i64;
    LODWORD(v13[6].mNext) = 1;
    v23 = v13 + 7;
    v13[7].mNext = v13 + 7;
    v13[8].mNext = v13 + 7;
    v13[9].mNext = 0i64;
    v15 = UFG::qVector3::msAxisX.y;
    v16 = UFG::qVector3::msAxisX.z;
    HIDWORD(v13[11].mNext) = LODWORD(UFG::qVector3::msAxisX.x);
    *(float *)&v13[12].mNext = v15;
    *((float *)&v13[12].mNext + 1) = v16;
    LODWORD(v13[13].mNext) = 0;
    v13[26].mNext = 0i64;
    LODWORD(v13[28].mNext) = 0;
    v17 = byte_1423CE011;
    if ( !byte_1423CE011 )
      v17 = 1;
    byte_1423CE011 = v17;
  }
  else
  {
    v14 = 0i64;
  }
  this->mpEyeEffector = v14;
  v18 = (UFG::AIAwareness::KnowledgeSpace *)UFG::qMalloc(0x15E8ui64, "KnowledgeSpace", 0i64);
  result = v18;
  if ( v18 )
  {
    `eh vector constructor iterator(
      v18,
      0x38ui64,
      100,
      (void (__fastcall *)(void *))UFG::AIAwareness::KnowledgeSpace::PositionCandidate::PositionCandidate);
    v18->mNumPositionCandidates = 0;
    v18->mHasOverridingTarget = 0;
  }
  else
  {
    v18 = 0i64;
  }
  this->mpKnowledgeSpace = v18;
  v19 = s_MaxCharacterAwarenessDistance;
  this->mpHeadEffector->mMaxCharacterAwarenessDistance = s_MaxCharacterAwarenessDistance;
  this->mpEyeEffector->mMaxCharacterAwarenessDistance = v19;
  v20 = s_MaxSpaceAwarenessDistance;
  this->mpHeadEffector->mMaxSpaceAwarenessDistance = s_MaxSpaceAwarenessDistance;
  this->mpEyeEffector->mMaxSpaceAwarenessDistance = v20;
  this->mpHeadEffector->mpCurrentProfile = s_TEMPProfiles[0];
  this->mpEyeEffector->mpCurrentProfile = s_TEMPProfiles[0];
  this->mpHeadEffector->mpKnowledgeSpace = this->mpKnowledgeSpace;
  this->mpEyeEffector->mpKnowledgeSpace = this->mpKnowledgeSpace;
  mPrev = UFG::AIAwarenessComponent::s_AIAwarenessComponentList.mNode.mPrev;
  UFG::AIAwarenessComponent::s_AIAwarenessComponentList.mNode.mPrev->mNext = v3;
  v3->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *)&UFG::AIAwarenessComponent::s_AIAwarenessComponentList;
  UFG::AIAwarenessComponent::s_AIAwarenessComponentList.mNode.mPrev = &this->UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent>;
  UFG::SimComponent::AddType(this, UFG::AIAwarenessComponent::_AIAwarenessComponentTypeUID, "AIAwarenessComponent");
}

// File Line: 228
// RVA: 0x39A470
void __fastcall UFG::AIAwarenessComponent::~AIAwarenessComponent(UFG::AIAwarenessComponent *this)
{
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *v2; // rdi
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *mPrev; // rcx
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *mNext; // rax
  UFG::AIAwareness::Effector *mpHeadEffector; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mActiveSimObject; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::AIAwareness::Effector *mpEyeEffector; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::AIAwareness::KnowledgeSpace *mpKnowledgeSpace; // rsi
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *v18; // rcx
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *v19; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIAwarenessComponent::`vftable;
  if ( this == UFG::AIAwarenessComponent::s_AIAwarenessComponentpCurrentIterator )
    UFG::AIAwarenessComponent::s_AIAwarenessComponentpCurrentIterator = (UFG::AIAwarenessComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  mpHeadEffector = this->mpHeadEffector;
  if ( mpHeadEffector )
  {
    p_mActiveSimObject = &mpHeadEffector->mActiveSimObject;
    if ( mpHeadEffector->mActiveSimObject.m_pPointer )
    {
      v7 = p_mActiveSimObject->mPrev;
      v8 = mpHeadEffector->mActiveSimObject.mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      p_mActiveSimObject->mPrev = p_mActiveSimObject;
      mpHeadEffector->mActiveSimObject.mNext = &mpHeadEffector->mActiveSimObject;
    }
    mpHeadEffector->mActiveSimObject.m_pPointer = 0i64;
    v9 = p_mActiveSimObject->mPrev;
    v10 = mpHeadEffector->mActiveSimObject.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    p_mActiveSimObject->mPrev = p_mActiveSimObject;
    mpHeadEffector->mActiveSimObject.mNext = &mpHeadEffector->mActiveSimObject;
    operator delete[](mpHeadEffector);
  }
  mpEyeEffector = this->mpEyeEffector;
  if ( mpEyeEffector )
  {
    v12 = &mpEyeEffector->mActiveSimObject;
    if ( mpEyeEffector->mActiveSimObject.m_pPointer )
    {
      v13 = v12->mPrev;
      v14 = mpEyeEffector->mActiveSimObject.mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v12->mPrev = v12;
      mpEyeEffector->mActiveSimObject.mNext = &mpEyeEffector->mActiveSimObject;
    }
    mpEyeEffector->mActiveSimObject.m_pPointer = 0i64;
    v15 = v12->mPrev;
    v16 = mpEyeEffector->mActiveSimObject.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v12->mPrev = v12;
    mpEyeEffector->mActiveSimObject.mNext = &mpEyeEffector->mActiveSimObject;
    operator delete[](mpEyeEffector);
  }
  mpKnowledgeSpace = this->mpKnowledgeSpace;
  if ( mpKnowledgeSpace )
  {
    `eh vector destructor iterator(
      mpKnowledgeSpace,
      0x38ui64,
      100,
      (void (__fastcall *)(void *))UFG::AIAwareness::KnowledgeSpace::PositionCandidate::~PositionCandidate);
    operator delete[](mpKnowledgeSpace);
  }
  v18 = v2->mPrev;
  v19 = v2->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}v = v18;
  v2->mPrev = v2;
  v2->mNext

// File Line: 237
// RVA: 0x39AF20
void __fastcall UFG::AIAwarenessComponent::OnAttach(UFG::AIAwarenessComponent *this, UFG::SimObjectCharacter *pObject)
{
  __int64 v3; // rax
  unsigned int v4; // ecx

  if ( !UFG::IsAnyLocalPlayer(pObject) || (v3 = s_PlayerProfileOverride, s_PlayerProfileOverride == -1) )
  {
    v4 = numAwarenessProfilesToRandomize;
    if ( numAwarenessProfilesToRandomize >= 4 )
      v4 = 4;
    numAwarenessProfilesToRandomize = v4;
    v3 = (int)UFG::qRandom(v4, (unsigned int *)&UFG::qDefaultSeed);
  }
  this->mpCurrentProfile = s_TEMPProfiles[v3];
}

// File Line: 268
// RVA: 0x39AF80
UFG::AIAwarenessComponent *__fastcall UFG::AIAwarenessComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rbx
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x78ui64, "AI::AIAwarenessComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::AIAwarenessComponent::AIAwarenessComponent((UFG::AIAwarenessComponent *)v4, pSceneObj->m_NameUID);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, pSceneObj->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return (UFG::AIAwarenessComponent *)v6;
}

// File Line: 283
// RVA: 0x39BF60
void __fastcall UFG::AIAwarenessComponent::UpdateSensors(UFG::AIAwarenessComponent *this, float deltaTime)
{
  UFG::SimObject *m_pSimObject; // rdi
  __int16 m_Flags; // dx
  UFG::SimObjectCVBase *v5; // rcx
  UFG::ActiveAIEntityComponent *v6; // rax
  hkMeshShape *MeshShape; // r15
  float v8; // xmm6_4
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v9; // rbx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v10; // rbp
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *mPrev; // rax
  UFG::SimObject *mNext; // rax
  UFG::TransformNodeComponent *v13; // rsi
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *i; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v15; // rdx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v16; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v17; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v18; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v19; // rax
  _QWORD v20[5]; // [rsp+0h] [rbp-68h] BYREF
  UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList,0,0> list; // [rsp+28h] [rbp-40h] BYREF

  v20[4] = -2i64;
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    v5 = (UFG::SimObjectCVBase *)this->m_pSimObject;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v5);
    else
      v6 = (UFG::ActiveAIEntityComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v5,
                                              UFG::ActiveAIEntityComponent::_TypeUID)
                                          : UFG::SimObject::GetComponentOfType(
                                              v5,
                                              UFG::ActiveAIEntityComponent::_TypeUID));
    if ( v6 && m_pSimObject->m_pTransformNodeComponent )
    {
      MeshShape = hkMemoryMeshBody::getMeshShape((hkMemoryMeshBody *)v6);
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)MeshShape);
      list.mNode.mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list;
      list.mNode.mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list;
      UFG::NearbyCharacterManager::GetNearbyCharactersAll(
        UFG::NearbyCharacterManager::s_pInstance,
        (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)&list,
        (UFG::qVector3 *)&MeshShape[11]);
      v8 = s_MaxCharacterAwarenessDistance * s_MaxCharacterAwarenessDistance;
      v9 = list.mNode.mNext - 1;
      v10 = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&v20[3];
      if ( list.mNode.mNext - 1 != v10 )
      {
        do
        {
          mPrev = v9[3].mPrev;
          if ( mPrev )
          {
            mNext = (UFG::SimObject *)mPrev[2].mNext;
            v13 = mNext ? mNext->m_pTransformNodeComponent : 0i64;
            if ( mNext != m_pSimObject )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v13);
              if ( (float)((float)((float)((float)(*((float *)&MeshShape[11].vfptr + 1) - v13->mWorldTransform.v3.y)
                                         * (float)(*((float *)&MeshShape[11].vfptr + 1) - v13->mWorldTransform.v3.y))
                                 + (float)((float)(*(float *)&MeshShape[11].vfptr - v13->mWorldTransform.v3.x)
                                         * (float)(*(float *)&MeshShape[11].vfptr - v13->mWorldTransform.v3.x)))
                         + (float)((float)(*(float *)&MeshShape[11].m_memSizeAndFlags - v13->mWorldTransform.v3.z)
                                 * (float)(*(float *)&MeshShape[11].m_memSizeAndFlags - v13->mWorldTransform.v3.z))) < v8 )
                UFG::AIAwareness::KnowledgeSpace::AddTargetSimObject(
                  this->mpKnowledgeSpace,
                  (UFG::SimObject *)v9[3].mPrev[2].mNext,
                  TARGETPRIORITY_AMBIENT);
            }
          }
          v9 = v9[1].mNext - 1;
        }
        while ( v9 != v10 );
      }
      for ( i = list.mNode.mNext - 1; list.mNode.mNext - 1 != v10; i = list.mNode.mNext - 1 )
      {
        v15 = i + 1;
        v16 = i[1].mPrev;
        v17 = i[1].mNext;
        v16->mNext = v17;
        v17->mPrev = v16;
        v15->mPrev = v15;
        v15->mNext = v15;
      }
      v18 = list.mNode.mPrev;
      v19 = list.mNode.mNext;
      list.mNode.mPrev->mNext = list.mNode.mNext;
      v19->mPrev = v18;
    }
  }
}

// File Line: 318
// RVA: 0x39BA70
void __fastcall UFG::AIAwarenessComponent::UpdateEffectors(UFG::AIAwarenessComponent *this, float deltaTime)
{
  UFG::SimObject *m_pSimObject; // rbx
  UFG::AIEntityComponent *ComponentOfType; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp

  m_pSimObject = this->m_pSimObject;
  ComponentOfType = 0i64;
  m_pTransformNodeComponent = 0i64;
  if ( m_pSimObject )
  {
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    ComponentOfType = (UFG::AIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                  this->m_pSimObject,
                                                  UFG::ActiveAIEntityComponent::_TypeUID);
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  UFG::AIAwareness::Effector::Update(
    this->mpHeadEffector,
    deltaTime,
    m_pSimObject,
    (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform);
  UFG::AIAwareness::Effector::UpdateWithSameTarget(
    this->mpEyeEffector,
    this->mpHeadEffector,
    deltaTime,
    m_pSimObject,
    &this->mpHeadEffector->mForward);
  UFG::AIEntityComponent::SetHeadTrackingPosition(ComponentOfType, &this->mpHeadEffector->mActivePosition);
}

// File Line: 338
// RVA: 0x39A6E0
void __fastcall UFG::AIAwarenessComponent::AddTargetSimObject(
        UFG::AIAwarenessComponent *this,
        UFG::SimObject *pSimObject,
        UFG::AIAwareness::TargetPriority priority)
{
  UFG::AIAwareness::KnowledgeSpace::AddTargetSimObject(this->mpKnowledgeSpace, pSimObject, priority);
}

// File Line: 343
// RVA: 0x39AED0
void __fastcall UFG::AIAwarenessComponent::LockSimObject(UFG::AIAwarenessComponent *this, UFG::qSymbol *name)
{
  UFG::AIAwareness::KnowledgeSpace *mpKnowledgeSpace; // r11
  int v3; // r9d
  __int64 mNumPositionCandidates; // r10
  __int64 v5; // r8
  UFG::qSymbol *i; // rax

  mpKnowledgeSpace = this->mpKnowledgeSpace;
  v3 = 0;
  mNumPositionCandidates = mpKnowledgeSpace->mNumPositionCandidates;
  v5 = 0i64;
  if ( mNumPositionCandidates > 0 )
  {
    for ( i = &mpKnowledgeSpace->mPositionCandidates[0].mName; i[8].mUID != 1 || i->mUID != name->mUID; i += 14 )
    {
      ++v5;
      ++v3;
      if ( v5 >= mNumPositionCandidates )
        return;
    }
    if ( v3 >= 0 )
      ++mpKnowledgeSpace->mPositionCandidates[v3].mLockRefCount;
  }
}

// File Line: 348
// RVA: 0x39B500
void __fastcall UFG::AIAwarenessComponent::UnlockSimObject(UFG::AIAwarenessComponent *this, UFG::qSymbol *name)
{
  UFG::AIAwareness::KnowledgeSpace *mpKnowledgeSpace; // r11
  __int64 mNumPositionCandidates; // r10
  int v4; // r9d
  __int64 v5; // r8
  UFG::qSymbol *i; // rcx
  __int64 v7; // rcx
  int v8; // eax

  mpKnowledgeSpace = this->mpKnowledgeSpace;
  mNumPositionCandidates = mpKnowledgeSpace->mNumPositionCandidates;
  v4 = 0;
  v5 = 0i64;
  if ( mNumPositionCandidates > 0 )
  {
    for ( i = &mpKnowledgeSpace->mPositionCandidates[0].mName; i[8].mUID != 1 || i->mUID != name->mUID; i += 14 )
    {
      ++v5;
      ++v4;
      if ( v5 >= mNumPositionCandidates )
        return;
    }
    if ( v4 >= 0 )
    {
      v7 = v4;
      v8 = mpKnowledgeSpace->mPositionCandidates[v7].mLockRefCount - 1;
      if ( v8 < 0 )
        LOBYTE(v8) = 0;
      mpKnowledgeSpace->mPositionCandidates[v7].mLockRefCount = v8;
    }
  }
}

// File Line: 353
// RVA: 0x39B570
void __fastcall UFG::AIAwarenessComponent::Update(UFG::AIAwarenessComponent *this, float deltaTime)
{
  UFG::AIEntityComponent *ComponentOfType; // rax

  if ( this->mEnabled )
  {
    this->mpHeadEffector->mpCurrentProfile = this->mpCurrentProfile;
    this->mpEyeEffector->mpCurrentProfile = this->mpCurrentProfile;
    UFG::AIAwareness::KnowledgeSpace::Update(this->mpKnowledgeSpace, deltaTime);
    if ( s_EnableModule )
    {
      UFG::AIAwarenessComponent::UpdateSensors(this, deltaTime);
      UFG::AIAwarenessComponent::UpdateEffectors(this, deltaTime);
    }
  }
  else
  {
    ComponentOfType = (UFG::AIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                  this->m_pSimObject,
                                                  UFG::ActiveAIEntityComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::AIEntityComponent::StopHeadTracking(ComponentOfType);
  }
}

// File Line: 402
// RVA: 0x39BB20
void __fastcall UFG::AIAwarenessComponent::UpdateIntentionsAll(float deltaTime)
{
  UFG::AIAwarenessComponent *v1; // rax

  v1 = (UFG::AIAwarenessComponent *)&UFG::AIAwarenessComponent::s_AIAwarenessComponentList.mNode.mNext[-4];
  for ( UFG::AIAwarenessComponent::s_AIAwarenessComponentpCurrentIterator = (UFG::AIAwarenessComponent *)&UFG::AIAwarenessComponent::s_AIAwarenessComponentList.mNode.mNext[-4];
        v1 != (UFG::AIAwarenessComponent *)(&UFG::AIAwarenessComponent::s_AIAwarenessComponentList - 4);
        UFG::AIAwarenessComponent::s_AIAwarenessComponentpCurrentIterator = v1 )
  {
    v1 = (UFG::AIAwarenessComponent *)&v1->mNext[-4];
  }
  UFG::AIAwarenessComponent::s_AIAwarenessComponentpCurrentIterator = 0i64;
}

// File Line: 414
// RVA: 0x39AEC0
_BOOL8 __fastcall UFG::AIAwarenessComponent::IsVisualTrackingEnabled()
{
  return s_EnableModule;
}

