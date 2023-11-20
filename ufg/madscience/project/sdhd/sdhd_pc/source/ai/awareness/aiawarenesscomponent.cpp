// File Line: 38
// RVA: 0x14B9510
__int64 dynamic_initializer_for__UFG::AIAwarenessComponent::s_AIAwarenessComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AIAwarenessComponent::s_AIAwarenessComponentList__);
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
  UFG::AIAwarenessComponent *v2; // r14
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *v3; // r15
  signed __int64 v4; // rsi
  UFG::qString *v5; // rax
  UFG::qString *v6; // rdi
  const char *v7; // rbx
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rdx
  UFG::allocator::free_link *v10; // rcx
  float v11; // xmm1_4
  float v12; // xmm2_4
  char v13; // cl
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rdx
  UFG::allocator::free_link *v16; // rcx
  float v17; // xmm1_4
  float v18; // xmm2_4
  char v19; // cl
  UFG::allocator::free_link *v20; // rbx
  float v21; // xmm0_4
  float v22; // xmm1_4
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *v23; // rax
  UFG::qSymbol result; // [rsp+90h] [rbp+18h]
  UFG::allocator::free_link *v25; // [rsp+98h] [rbp+20h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, nameUid);
  v3 = (UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIAwarenessComponent::`vftable';
  if ( !sInitialized )
  {
    v4 = 0i64;
    do
    {
      v5 = (UFG::qString *)UFG::qMalloc(0xB0ui64, "TEMPAwarenessProfile", 0i64);
      v6 = v5;
      v25 = (UFG::allocator::free_link *)v5;
      if ( v5 )
      {
        v7 = *(const char **)(v4 + 5402726688i64);
        UFG::qString::qString(v5);
        LODWORD(v6[1].mPrev) = -1;
        UFG::qString::Set(v6, v7);
        LODWORD(v6[1].mPrev) = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, v7)->mUID;
      }
      else
      {
        v6 = 0i64;
      }
      *(_QWORD *)(v4 + 5406253040i64) = v6;
      v4 += 8i64;
    }
    while ( v4 < 32 );
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
  v9 = v8;
  *(_QWORD *)&result.mUID = v8;
  if ( v8 )
  {
    LODWORD(v8->mNext) = 0;
    v8[1].mNext = 0i64;
    v8[4].mNext = 0i64;
    v8[5].mNext = 0i64;
    LODWORD(v8[6].mNext) = 1;
    v10 = v8 + 7;
    v25 = v10;
    v10->mNext = v10;
    v10[1].mNext = v10;
    v8[9].mNext = 0i64;
    v11 = UFG::qVector3::msAxisX.y;
    v12 = UFG::qVector3::msAxisX.z;
    HIDWORD(v8[11].mNext) = LODWORD(UFG::qVector3::msAxisX.x);
    *(float *)&v8[12].mNext = v11;
    *((float *)&v8[12].mNext + 1) = v12;
    LODWORD(v8[13].mNext) = 0;
    v8[26].mNext = 0i64;
    LODWORD(v8[28].mNext) = 0;
    v13 = byte_1423CE011;
    if ( !byte_1423CE011 )
      v13 = 1;
    byte_1423CE011 = v13;
  }
  else
  {
    v9 = 0i64;
  }
  v2->mpHeadEffector = (UFG::AIAwareness::Effector *)v9;
  v14 = UFG::qMalloc(0xE8ui64, "AwarenessEffector", 0i64);
  v15 = v14;
  *(_QWORD *)&result.mUID = v14;
  if ( v14 )
  {
    LODWORD(v14->mNext) = 1;
    v14[1].mNext = 0i64;
    v14[4].mNext = 0i64;
    v14[5].mNext = 0i64;
    LODWORD(v14[6].mNext) = 1;
    v16 = v14 + 7;
    v25 = v16;
    v16->mNext = v16;
    v16[1].mNext = v16;
    v14[9].mNext = 0i64;
    v17 = UFG::qVector3::msAxisX.y;
    v18 = UFG::qVector3::msAxisX.z;
    HIDWORD(v14[11].mNext) = LODWORD(UFG::qVector3::msAxisX.x);
    *(float *)&v14[12].mNext = v17;
    *((float *)&v14[12].mNext + 1) = v18;
    LODWORD(v14[13].mNext) = 0;
    v14[26].mNext = 0i64;
    LODWORD(v14[28].mNext) = 0;
    v19 = byte_1423CE011;
    if ( !byte_1423CE011 )
      v19 = 1;
    byte_1423CE011 = v19;
  }
  else
  {
    v15 = 0i64;
  }
  v2->mpEyeEffector = (UFG::AIAwareness::Effector *)v15;
  v20 = UFG::qMalloc(0x15E8ui64, "KnowledgeSpace", 0i64);
  *(_QWORD *)&result.mUID = v20;
  if ( v20 )
  {
    `eh vector constructor iterator'(
      v20,
      0x38ui64,
      100,
      (void (__fastcall *)(void *))UFG::AIAwareness::KnowledgeSpace::PositionCandidate::PositionCandidate);
    LODWORD(v20[700].mNext) = 0;
    BYTE4(v20[700].mNext) = 0;
  }
  else
  {
    v20 = 0i64;
  }
  v2->mpKnowledgeSpace = (UFG::AIAwareness::KnowledgeSpace *)v20;
  v21 = s_MaxCharacterAwarenessDistance;
  v2->mpHeadEffector->mMaxCharacterAwarenessDistance = s_MaxCharacterAwarenessDistance;
  v2->mpEyeEffector->mMaxCharacterAwarenessDistance = v21;
  v22 = s_MaxSpaceAwarenessDistance;
  v2->mpHeadEffector->mMaxSpaceAwarenessDistance = s_MaxSpaceAwarenessDistance;
  v2->mpEyeEffector->mMaxSpaceAwarenessDistance = v22;
  v2->mpHeadEffector->mpCurrentProfile = s_TEMPProfiles[0];
  v2->mpEyeEffector->mpCurrentProfile = s_TEMPProfiles[0];
  v2->mpHeadEffector->mpKnowledgeSpace = v2->mpKnowledgeSpace;
  v2->mpEyeEffector->mpKnowledgeSpace = v2->mpKnowledgeSpace;
  v23 = UFG::AIAwarenessComponent::s_AIAwarenessComponentList.mNode.mPrev;
  UFG::AIAwarenessComponent::s_AIAwarenessComponentList.mNode.mPrev->mNext = v3;
  v3->mPrev = v23;
  v2->mNext = (UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *)&UFG::AIAwarenessComponent::s_AIAwarenessComponentList;
  UFG::AIAwarenessComponent::s_AIAwarenessComponentList.mNode.mPrev = (UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::AIAwarenessComponent::_AIAwarenessComponentTypeUID,
    "AIAwarenessComponent");
}

// File Line: 228
// RVA: 0x39A470
void __fastcall UFG::AIAwarenessComponent::~AIAwarenessComponent(UFG::AIAwarenessComponent *this)
{
  UFG::AIAwarenessComponent *v1; // rbx
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *v2; // rdi
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *v3; // rcx
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *v4; // rax
  UFG::AIAwareness::Effector *v5; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::AIAwareness::Effector *v11; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::AIAwareness::KnowledgeSpace *v17; // rsi
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *v18; // rcx
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *v19; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIAwarenessComponent::`vftable';
  if ( this == UFG::AIAwarenessComponent::s_AIAwarenessComponentpCurrentIterator )
    UFG::AIAwarenessComponent::s_AIAwarenessComponentpCurrentIterator = (UFG::AIAwarenessComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->mpHeadEffector;
  if ( v5 )
  {
    v6 = &v5->mActiveSimObject;
    if ( v5->mActiveSimObject.m_pPointer )
    {
      v7 = v6->mPrev;
      v8 = v5->mActiveSimObject.mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v5->mActiveSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mActiveSimObject.mPrev;
    }
    v5->mActiveSimObject.m_pPointer = 0i64;
    v9 = v6->mPrev;
    v10 = v5->mActiveSimObject.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v5->mActiveSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mActiveSimObject.mPrev;
    operator delete[](v5);
  }
  v11 = v1->mpEyeEffector;
  if ( v11 )
  {
    v12 = &v11->mActiveSimObject;
    if ( v11->mActiveSimObject.m_pPointer )
    {
      v13 = v12->mPrev;
      v14 = v11->mActiveSimObject.mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
      v11->mActiveSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mActiveSimObject.mPrev;
    }
    v11->mActiveSimObject.m_pPointer = 0i64;
    v15 = v12->mPrev;
    v16 = v11->mActiveSimObject.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v11->mActiveSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mActiveSimObject.mPrev;
    operator delete[](v11);
  }
  v17 = v1->mpKnowledgeSpace;
  if ( v17 )
  {
    `eh vector destructor iterator'(
      v17,
      0x38ui64,
      100,
      (void (__fastcall *)(void *))UFG::AIAwareness::KnowledgeSpace::PositionCandidate::~PositionCandidate);
    operator delete[](v17);
  }
  v18 = v2->mPrev;
  v19 = v2->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 237
// RVA: 0x39AF20
void __fastcall UFG::AIAwarenessComponent::OnAttach(UFG::AIAwarenessComponent *this, UFG::SimObject *pObject)
{
  UFG::AIAwarenessComponent *v2; // rbx
  __int64 v3; // rax
  int v4; // ecx

  v2 = this;
  if ( !UFG::IsAnyLocalPlayer(pObject) || (v3 = s_PlayerProfileOverride, s_PlayerProfileOverride == -1) )
  {
    v4 = numAwarenessProfilesToRandomize;
    if ( numAwarenessProfilesToRandomize >= 4 )
      v4 = 4;
    numAwarenessProfilesToRandomize = v4;
    v3 = (signed int)UFG::qRandom(v4, &UFG::qDefaultSeed);
  }
  v2->mpCurrentProfile = s_TEMPProfiles[v3];
}

// File Line: 268
// RVA: 0x39AF80
UFG::SimComponent *__fastcall UFG::AIAwarenessComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rdi
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rbx
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0x78ui64, "AI::AIAwarenessComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::AIAwarenessComponent::AIAwarenessComponent((UFG::AIAwarenessComponent *)v4, v2->m_NameUID);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, v2->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return v6;
}

// File Line: 283
// RVA: 0x39BF60
void __fastcall UFG::AIAwarenessComponent::UpdateSensors(UFG::AIAwarenessComponent *this, float deltaTime)
{
  UFG::AIAwarenessComponent *v2; // r14
  UFG::SimObject *v3; // rdi
  unsigned __int16 v4; // dx
  UFG::SimObjectCVBase *v5; // rcx
  UFG::ActiveAIEntityComponent *v6; // rax
  hkMeshShape *v7; // r15
  float v8; // xmm6_4
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v9; // rbx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v10; // rbp
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v11; // rax
  UFG::SimObject *v12; // rax
  UFG::TransformNodeComponent *v13; // rsi
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *i; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v15; // rdx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v16; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v17; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v18; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v19; // rax
  __int64 v20; // [rsp+0h] [rbp-68h]
  __int64 v21; // [rsp+20h] [rbp-48h]
  UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList,0,0> list; // [rsp+28h] [rbp-40h]

  v21 = -2i64;
  v2 = this;
  v3 = this->m_pSimObject;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    v5 = (UFG::SimObjectCVBase *)this->m_pSimObject;
    if ( (v4 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v5);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v5->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      else
        v6 = (UFG::ActiveAIEntityComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)&v5->vfptr,
                                                                 UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::ActiveAIEntityComponent::_TypeUID));
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v5);
    }
    if ( v6 && v3->m_pTransformNodeComponent )
    {
      v7 = hkMemoryMeshBody::getMeshShape((hkMemoryMeshBody *)v6);
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
      list.mNode.mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list;
      list.mNode.mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list;
      UFG::NearbyCharacterManager::GetNearbyCharactersAll(
        UFG::NearbyCharacterManager::s_pInstance,
        &list,
        (UFG::qVector3 *)&v7[11]);
      v8 = s_MaxCharacterAwarenessDistance * s_MaxCharacterAwarenessDistance;
      v9 = list.mNode.mNext - 1;
      v10 = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)(&v20 + 3);
      if ( list.mNode.mNext - 1 != v10 )
      {
        do
        {
          v11 = v9[3].mPrev;
          if ( v11 )
          {
            v12 = (UFG::SimObject *)v11[2].mNext;
            v13 = v12 ? v12->m_pTransformNodeComponent : 0i64;
            if ( v12 != v3 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v13);
              if ( (float)((float)((float)((float)(*((float *)&v7[11].vfptr + 1) - v13->mWorldTransform.v3.y)
                                         * (float)(*((float *)&v7[11].vfptr + 1) - v13->mWorldTransform.v3.y))
                                 + (float)((float)(*(float *)&v7[11].vfptr - v13->mWorldTransform.v3.x)
                                         * (float)(*(float *)&v7[11].vfptr - v13->mWorldTransform.v3.x)))
                         + (float)((float)(*(float *)&v7[11].m_memSizeAndFlags - v13->mWorldTransform.v3.z)
                                 * (float)(*(float *)&v7[11].m_memSizeAndFlags - v13->mWorldTransform.v3.z))) < v8 )
                UFG::AIAwareness::KnowledgeSpace::AddTargetSimObject(
                  v2->mpKnowledgeSpace,
                  (UFG::SimObject *)v9[3].mPrev[2].mNext,
                  0);
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
  UFG::SimObject *v2; // rbx
  UFG::AIEntityComponent *v3; // rdi
  UFG::AIAwarenessComponent *v4; // rsi
  UFG::TransformNodeComponent *v5; // rbp

  v2 = this->m_pSimObject;
  v3 = 0i64;
  v4 = this;
  v5 = 0i64;
  if ( v2 )
  {
    v5 = v2->m_pTransformNodeComponent;
    v3 = (UFG::AIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                     this->m_pSimObject,
                                     UFG::ActiveAIEntityComponent::_TypeUID);
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  UFG::AIAwareness::Effector::Update(v4->mpHeadEffector, deltaTime, v2, (UFG::qVector3 *)&v5->mWorldTransform);
  UFG::AIAwareness::Effector::UpdateWithSameTarget(
    v4->mpEyeEffector,
    v4->mpHeadEffector,
    deltaTime,
    v2,
    &v4->mpHeadEffector->mForward);
  UFG::AIEntityComponent::SetHeadTrackingPosition(v3, &v4->mpHeadEffector->mActivePosition);
}

// File Line: 338
// RVA: 0x39A6E0
void __fastcall UFG::AIAwarenessComponent::AddTargetSimObject(UFG::AIAwarenessComponent *this, UFG::SimObject *pSimObject, UFG::AIAwareness::TargetPriority priority)
{
  UFG::AIAwareness::KnowledgeSpace::AddTargetSimObject(this->mpKnowledgeSpace, pSimObject, priority);
}

// File Line: 343
// RVA: 0x39AED0
void __fastcall UFG::AIAwarenessComponent::LockSimObject(UFG::AIAwarenessComponent *this, UFG::qSymbol *name)
{
  UFG::AIAwareness::KnowledgeSpace *v2; // r11
  int v3; // er9
  __int64 v4; // r10
  __int64 v5; // r8
  UFG::qSymbol *v6; // rax

  v2 = this->mpKnowledgeSpace;
  v3 = 0;
  v4 = v2->mNumPositionCandidates;
  v5 = 0i64;
  if ( v4 > 0 )
  {
    v6 = &v2->mPositionCandidates[0].mName;
    while ( v6[8].mUID != 1 || v6->mUID != name->mUID )
    {
      ++v5;
      ++v3;
      v6 += 14;
      if ( v5 >= v4 )
        return;
    }
    if ( v3 >= 0 )
      ++v2->mPositionCandidates[v3].mLockRefCount;
  }
}

// File Line: 348
// RVA: 0x39B500
void __fastcall UFG::AIAwarenessComponent::UnlockSimObject(UFG::AIAwarenessComponent *this, UFG::qSymbol *name)
{
  UFG::AIAwareness::KnowledgeSpace *v2; // r11
  __int64 v3; // r10
  int v4; // er9
  __int64 v5; // r8
  UFG::qSymbol *v6; // rcx
  signed __int64 v7; // rcx
  int v8; // eax

  v2 = this->mpKnowledgeSpace;
  v3 = v2->mNumPositionCandidates;
  v4 = 0;
  v5 = 0i64;
  if ( v3 > 0 )
  {
    v6 = &v2->mPositionCandidates[0].mName;
    while ( v6[8].mUID != 1 || v6->mUID != name->mUID )
    {
      ++v5;
      ++v4;
      v6 += 14;
      if ( v5 >= v3 )
        return;
    }
    if ( v4 >= 0 )
    {
      v7 = v4;
      v8 = v2->mPositionCandidates[v7].mLockRefCount - 1;
      if ( v8 < 0 )
        LOBYTE(v8) = 0;
      v2->mPositionCandidates[v7].mLockRefCount = v8;
    }
  }
}

// File Line: 353
// RVA: 0x39B570
void __fastcall UFG::AIAwarenessComponent::Update(UFG::AIAwarenessComponent *this, float deltaTime)
{
  UFG::AIAwarenessComponent *v2; // rbx
  UFG::AIEntityComponent *v3; // rax

  v2 = this;
  if ( this->mEnabled )
  {
    this->mpHeadEffector->mpCurrentProfile = this->mpCurrentProfile;
    this->mpEyeEffector->mpCurrentProfile = this->mpCurrentProfile;
    UFG::AIAwareness::KnowledgeSpace::Update(this->mpKnowledgeSpace, deltaTime);
    if ( s_EnableModule )
    {
      UFG::AIAwarenessComponent::UpdateSensors(v2, deltaTime);
      UFG::AIAwarenessComponent::UpdateEffectors(v2, deltaTime);
    }
  }
  else
  {
    v3 = (UFG::AIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                     this->m_pSimObject,
                                     UFG::ActiveAIEntityComponent::_TypeUID);
    if ( v3 )
      UFG::AIEntityComponent::StopHeadTracking(v3);
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

