// File Line: 95
// RVA: 0x39FF70
void __fastcall SkeletalAnimationHandle::~SkeletalAnimationHandle(SkeletalAnimationHandle *this)
{
  SkeletalAnimationHandle *v1; // rbx
  UFG::qSafePointer<SkeletalAnimation,SkeletalAnimation> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v7; // rcx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v8; // rax

  v1 = this;
  SkeletalAnimationHandle::Unbind(this);
  v2 = &v1->m_SkeletalAnimation;
  if ( v1->m_SkeletalAnimation.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v1->m_SkeletalAnimation.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v1->m_SkeletalAnimation.mNext = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v1->m_SkeletalAnimation.mPrev;
  }
  v1->m_SkeletalAnimation.m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v1->m_SkeletalAnimation.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->m_SkeletalAnimation.mNext = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v1->m_SkeletalAnimation.mPrev;
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mPrev = (UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *)&v1->mPrev;
}

// File Line: 130
// RVA: 0x3AAC20
void __fastcall SkeletalAnimationHandle::Init(SkeletalAnimationHandle *this)
{
  unsigned int v1; // edx
  signed __int64 v2; // rbx
  SkeletalAnimationHandle *v3; // rdi
  UFG::qBaseTreeRB *v4; // rax
  signed __int64 v5; // r8
  UFG::qSafePointer<SkeletalAnimation,SkeletalAnimation> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *v9; // rax
  SkeletalAnimation *v10; // rcx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v11; // rcx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v12; // rax
  SkeletalAnimation *v13; // rax
  __int64 v14; // rcx

  v1 = this->m_SkeletalAnimationName.mUID;
  v2 = 0i64;
  v3 = this;
  if ( !v1
    || (v4 = UFG::qBaseTreeRB::Get(&AnimationDataBase::sAnimationDataBase->mAnimations.mTree, v1),
        v5 = (signed __int64)&v4[-1].mNULL,
        !v4) )
  {
    v5 = 0i64;
  }
  v6 = &v3->m_SkeletalAnimation;
  if ( v3->m_SkeletalAnimation.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v3->m_SkeletalAnimation.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v3->m_SkeletalAnimation.mNext = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v3->m_SkeletalAnimation.mPrev;
  }
  v3->m_SkeletalAnimation.m_pPointer = (SkeletalAnimation *)v5;
  if ( v5 )
  {
    v9 = *(UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> **)(v5 + 24);
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mPrev = v9;
    v3->m_SkeletalAnimation.mNext = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)(v5 + 24);
    *(_QWORD *)(v5 + 24) = v6;
  }
  v10 = v3->m_SkeletalAnimation.m_pPointer;
  if ( v10 )
  {
    v11 = &v10->m_SkeletalAnimationHandles.mNode;
    v12 = v11->mPrev;
    v12->mNext = (UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *)&v3->mPrev;
    v3->mPrev = v12;
    v3->mNext = v11;
    v11->mPrev = (UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *)&v3->mPrev;
    v13 = v3->m_SkeletalAnimation.m_pPointer;
    ++v13->mRefCount;
    ++v13->mRefCountTotal;
    v14 = v13->m_pAnimationGroup.mOffset;
    if ( v14 )
      v2 = (signed __int64)&v13->m_pAnimationGroup + v14;
    ++*(_DWORD *)(v2 + 184);
    ++*(_DWORD *)(v2 + 192);
  }
}

// File Line: 147
// RVA: 0x3B0380
void __fastcall SkeletalAnimationHandle::Unbind(SkeletalAnimationHandle *this)
{
  SkeletalAnimation *v1; // rbx
  SkeletalAnimationHandle *v2; // rdi
  __int64 v3; // rax
  AnimationGroup *v4; // rcx
  UFG::qSafePointer<SkeletalAnimation,SkeletalAnimation> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *v7; // rax

  v1 = this->m_SkeletalAnimation.m_pPointer;
  v2 = this;
  if ( v1 )
  {
    v3 = v1->m_pAnimationGroup.mOffset;
    if ( v3 )
      v4 = (AnimationGroup *)((char *)&v1->m_pAnimationGroup + v3);
    else
      v4 = 0i64;
    --v4->mAnimRefCount;
    if ( !v4->mRefCount && !v4->mAnimRefCount )
      AnimationGroup::DestroyStreamHandle(v4);
    v5 = &v2->m_SkeletalAnimation;
    --v1->mRefCount;
    if ( v2->m_SkeletalAnimation.m_pPointer )
    {
      v6 = v5->mPrev;
      v7 = v2->m_SkeletalAnimation.mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v5->mPrev;
      v2->m_SkeletalAnimation.mNext = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v2->m_SkeletalAnimation.mPrev;
    }
    v2->m_SkeletalAnimation.m_pPointer = 0i64;
  }
}

// File Line: 205
// RVA: 0x14BF2B0
const char *dynamic_initializer_for__sAnimTrackFactoryList__()
{
  const char *result; // rax

  sAnimTrackFactoryList[0].mClassName = PrintTrack::sClassName;
  sAnimTrackFactoryList[1].mClassName = PlayEffectTrack::sClassName;
  sAnimTrackFactoryList[2].mClassName = RumbleTrack::sClassName;
  sAnimTrackFactoryList[3].mClassName = DoorStateTrack::sClassName;
  sAnimTrackFactoryList[4].mClassName = AudioTrack::sClassName;
  sAnimTrackFactoryList[5].mClassName = AudioTrackSimple::sClassName;
  sAnimTrackFactoryList[6].mClassName = AudioTrackSurfaceDetection::sClassName;
  sAnimTrackFactoryList[7].mClassName = AudioTrackSoundbankIO::sClassName;
  sAnimTrackFactoryList[8].mClassName = AudioTrackMusicState::sClassName;
  sAnimTrackFactoryList[9].mClassName = DialogueTrack::sClassName;
  sAnimTrackFactoryList[10].mClassName = DialogueTrackWeaponImpact::sClassName;
  sAnimTrackFactoryList[11].mClassName = FootStepLeftEffectTrack::sClassName;
  sAnimTrackFactoryList[12].mClassName = FootStepRightEffectTrack::sClassName;
  sAnimTrackFactoryList[13].mClassName = CollisionEffectTrack::sClassName;
  sAnimTrackFactoryList[14].mClassName = EffectSurfaceCollisionTrack::sClassName;
  result = PoliceScannerAudioEventTrack::sClassName;
  sAnimTrackFactoryList[15].mClassName = PoliceScannerAudioEventTrack::sClassName;
  return result;
}

// File Line: 211
// RVA: 0x14BCE20
__int64 dynamic_initializer_for__gAnimTrackFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(&gAnimTrackFactory, sAnimTrackFactoryList, sAnimTrackFactoryListNum);
  return atexit(dynamic_atexit_destructor_for__gAnimTrackFactory__);
}

// File Line: 217
// RVA: 0x14B9970
__int64 dynamic_initializer_for__SkeletalAnimation::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SkeletalAnimation", 0xFFFFFFFF);
  SkeletalAnimation::sClassNameUID = result;
  return result;
}

// File Line: 275
// RVA: 0x39E610
void __fastcall SkeletalAnimation::SkeletalAnimation(SkeletalAnimation *this)
{
  SkeletalAnimation *v1; // rdi
  UFG::qNode<SkeletalAnimation,SkeletalAnimation> *v2; // rax
  UFG::qList<SkeletalAnimationHandle,SkeletalAnimationList,0,0> *v3; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  UFG::qSafePointerNode<SkeletalAnimation>::qSafePointerNode<SkeletalAnimation>((UFG::qSafePointerNode<SkeletalAnimation> *)&this->vfptr);
  v1->mNode.mParent = 0i64;
  v1->mNode.mChild[0] = 0i64;
  v1->mNode.mChild[1] = 0i64;
  v2 = (UFG::qNode<SkeletalAnimation,SkeletalAnimation> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (Expression::IMemberMapVtbl *)&SkeletalAnimation::`vftable'{for `Expression::IMemberMap'};
  v1->vfptr = (UFG::qSafePointerNode<SkeletalAnimation>Vtbl *)&SkeletalAnimation::`vftable'{for `UFG::qSafePointerNode<SkeletalAnimation>'};
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->m_AnimationResourceHandle.mPrev);
  v1->m_AnimationResourceHandle.m_pSkeletalAnimationOwner = 0i64;
  v1->m_AnimationResourceHandle.m_bUnloading = 0;
  v1->m_pFallbackAnimation = 0i64;
  v3 = &v1->m_SkeletalAnimationHandles;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  *(_QWORD *)&v1->mNameSymbol.mUID = -1i64;
  *(_QWORD *)&v1->mRefCount = 0i64;
  *(_QWORD *)&v1->mBlendMode = 0i64;
  v1->mDurationCached = 3.4028235e38;
  v1->mTracks.mOffset = 0i64;
  v1->mMotionPhaseChannel.mOffset = 0i64;
}

// File Line: 315
// RVA: 0x39FD90
void __fastcall SkeletalAnimation::~SkeletalAnimation(SkeletalAnimation *this)
{
  SkeletalAnimation *v1; // rdi
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rsi
  __int64 v3; // rax
  __int64 v4; // rax
  char *v5; // rcx
  __int64 v6; // rax
  signed __int64 v7; // rcx
  __int64 v8; // rax
  signed __int64 v9; // rcx
  UFG::qList<SkeletalAnimationHandle,SkeletalAnimationList,0,0> *v10; // r8
  UFG::qList<SkeletalAnimationHandle,SkeletalAnimationList,0,0> *v11; // rax
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v12; // rdx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v13; // rcx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v14; // rcx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v15; // rax
  UFG::qResourceInventory *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  UFG::qNode<SkeletalAnimation,SkeletalAnimation> *v18; // rdx
  UFG::qNode<SkeletalAnimation,SkeletalAnimation> *v19; // rcx
  UFG::qNode<SkeletalAnimation,SkeletalAnimation> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v22; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SkeletalAnimation::`vftable'{for `Expression::IMemberMap'};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->vfptr;
  this->vfptr = (UFG::qSafePointerNode<SkeletalAnimation>Vtbl *)&SkeletalAnimation::`vftable'{for `UFG::qSafePointerNode<SkeletalAnimation>'};
  v3 = this->m_pAnimationGroup.mOffset;
  if ( v3 && (UFG::qOffset64<AnimationGroup *> *)((char *)&this->m_pAnimationGroup + v3) )
  {
    v4 = this->m_pAnimationGroup.mOffset;
    if ( v4 )
      v5 = (char *)&this->m_pAnimationGroup + v4;
    else
      v5 = 0i64;
    BinPtrArray<UELNode,0,0>::Remove((BinPtrArray<ActionNode,0,0> *)(v5 + 120), (ActionNode *)v1);
  }
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&AnimationDataBase::sAnimationDataBase->mAnimations,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v1->mNode);
  v6 = v1->mTracks.mOffset;
  if ( v6 )
  {
    v7 = (signed __int64)&v1->mTracks + v6;
    if ( v7 )
      (*(void (__fastcall **)(signed __int64, signed __int64))(*(_QWORD *)v7 + 8i64))(v7, 1i64);
  }
  v8 = v1->mMotionPhaseChannel.mOffset;
  if ( v8 )
  {
    v9 = (signed __int64)&v1->mMotionPhaseChannel + v8;
    if ( v9 )
      (*(void (__fastcall **)(signed __int64, signed __int64))(*(_QWORD *)v9 + 8i64))(v9, 1i64);
  }
  v10 = &v1->m_SkeletalAnimationHandles;
  v11 = (UFG::qList<SkeletalAnimationHandle,SkeletalAnimationList,0,0> *)v1->m_SkeletalAnimationHandles.mNode.mNext;
  if ( v11 != &v1->m_SkeletalAnimationHandles )
  {
    do
    {
      v12 = v11->mNode.mPrev;
      v13 = v11->mNode.mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      v11->mNode.mPrev = &v11->mNode;
      v11->mNode.mNext = &v11->mNode;
      v11 = (UFG::qList<SkeletalAnimationHandle,SkeletalAnimationList,0,0> *)v1->m_SkeletalAnimationHandles.mNode.mNext;
    }
    while ( v11 != v10 );
  }
  v14 = v10->mNode.mPrev;
  v15 = v1->m_SkeletalAnimationHandles.mNode.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v10->mNode.mPrev = &v10->mNode;
  v1->m_SkeletalAnimationHandles.mNode.mNext = &v1->m_SkeletalAnimationHandles.mNode;
  v16 = `UFG::qGetResourceInventory<UFG::AnimationResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AnimationResource>'::`2'::result )
  {
    v17 = UFG::qResourceWarehouse::Instance();
    v16 = UFG::qResourceWarehouse::GetInventory(v17, 0x53F1685Eu);
    `UFG::qGetResourceInventory<UFG::AnimationResource>'::`2'::result = v16;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->m_AnimationResourceHandle.mPrev, v16);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->m_AnimationResourceHandle.mPrev);
  v18 = (UFG::qNode<SkeletalAnimation,SkeletalAnimation> *)&v1->mPrev;
  v19 = v1->mPrev;
  v20 = v1->mNext;
  v19->mNext = v20;
  v20->mPrev = v19;
  v18->mPrev = v18;
  v18->mNext = v18;
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<SkeletalAnimation>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v2->m_SafePointerList);
  v21 = v2->m_SafePointerList.mNode.mPrev;
  v22 = v2->m_SafePointerList.mNode.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v2->m_SafePointerList.mNode.mPrev = &v2->m_SafePointerList.mNode;
  v2->m_SafePointerList.mNode.mNext = &v2->m_SafePointerList.mNode;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 335
// RVA: 0x3AE9C0
void __fastcall SkeletalAnimation::Serialize(SkeletalAnimation *this, IActionTreeSerializer *serializer)
{
  __int64 v2; // rax
  IActionTreeSerializer *v3; // rbx
  SkeletalAnimation *v4; // rdi
  Expression::IMemberMap *v5; // rdx
  __int64 v6; // rax
  Expression::IMemberMap *v7; // rdx

  v2 = this->mTracks.mOffset;
  v3 = serializer;
  v4 = this;
  if ( v2 )
  {
    v5 = (Expression::IMemberMap *)((char *)&this->mTracks + v2);
    if ( v5 )
      IActionTreeSerializer::PushObjectToSerialize(v3, v5);
  }
  v6 = v4->mMotionPhaseChannel.mOffset;
  if ( v6 )
  {
    v7 = (Expression::IMemberMap *)((char *)&v4->mMotionPhaseChannel + v6);
    if ( v7 )
      IActionTreeSerializer::PushObjectToSerialize(v3, v7);
  }
}

// File Line: 390
// RVA: 0x3AC400
void __fastcall SkeletalAnimation::OnSave(SkeletalAnimation *this)
{
  __int64 v1; // rax

  v1 = this->mMotionPhaseChannel.mOffset;
  if ( v1 )
    JUMPOUT((char *)&this->mMotionPhaseChannel + v1, 0i64, MotionPhaseChannel::Sort);
}

// File Line: 432
// RVA: 0x3AC000
void __fastcall SkeletalAnimation::OnLoad(SkeletalAnimation *this)
{
  SkeletalAnimation *v1; // rsi
  UFG::qResourceData *v2; // rbx
  SkeletalAnimation *v3; // rax
  UFG::qResourceData *v4; // rbx
  hkReferencedObject *v5; // rcx
  hkReferencedObject *v6; // rbx
  __int64 *v7; // rbp
  char v8; // di
  hkReferencedObject *v9; // rcx
  __int64 v10; // rbp
  hkReferencedObject *v11; // [rsp+58h] [rbp+10h]
  hkReferencedObject *v12; // [rsp+60h] [rbp+18h]

  v1 = this;
  v2 = this->m_AnimationResourceHandle.mData;
  if ( v2 )
  {
    v2 = (UFG::qResourceData *)v2[1].mNode.mChild[0];
    if ( v2 )
      goto LABEL_7;
  }
  v3 = this->m_pFallbackAnimation;
  if ( v3 )
  {
    v4 = v3->m_AnimationResourceHandle.mData;
    if ( !v4 )
    {
LABEL_10:
      v9 = 0i64;
      v11 = 0i64;
      v7 = (__int64 *)&v11;
      v8 = 2;
      v6 = v12;
      goto LABEL_11;
    }
    v2 = (UFG::qResourceData *)v4[1].mNode.mChild[0];
  }
  if ( !v2 )
    goto LABEL_10;
LABEL_7:
  v5 = *(hkReferencedObject **)&v2->mNode.mUID;
  if ( v5 )
    hkReferencedObject::addReference(v5);
  v6 = *(hkReferencedObject **)&v2->mNode.mUID;
  v12 = v6;
  v7 = (__int64 *)&v12;
  v8 = 1;
  v9 = v11;
LABEL_11:
  v10 = *v7;
  if ( v8 & 2 )
  {
    v8 &= 0xFDu;
    if ( v9 )
      hkReferencedObject::removeReference(v9);
    v11 = 0i64;
  }
  if ( v8 & 1 )
  {
    if ( v6 )
      hkReferencedObject::removeReference(v6);
    v12 = 0i64;
  }
  if ( v10 )
    v1->mDurationCached = *(float *)(v10 + 20);
  else
    v1->mDurationCached = 3.4028235e38;
}

// File Line: 447
// RVA: 0x3AC430
void __fastcall SkeletalAnimation::OnUnload(SkeletalAnimation *this)
{
  char **v1; // rsi
  SkeletalAnimation *v2; // rbp
  char *v3; // rbx
  __int64 v4; // rdx
  _QWORD *v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rax
  AnimationGroup *v8; // rcx
  __int64 *v9; // rdx
  __int64 v10; // rcx
  _QWORD *v11; // rax

  v1 = (char **)&this->m_SkeletalAnimationHandles;
  v2 = this;
  if ( (UFG::qList<SkeletalAnimationHandle,SkeletalAnimationList,0,0> *)this->m_SkeletalAnimationHandles.mNode.mNext == &this->m_SkeletalAnimationHandles )
  {
    this->mDurationCached = 3.4028235e38;
  }
  else
  {
    do
    {
      v3 = *v1;
      v4 = *(_QWORD *)*v1;
      v5 = (_QWORD *)*((_QWORD *)*v1 + 1);
      *(_QWORD *)(v4 + 8) = v5;
      *v5 = v4;
      *(_QWORD *)v3 = v3;
      *((_QWORD *)v3 + 1) = v3;
      v6 = *((_QWORD *)v3 + 5);
      if ( v6 )
      {
        v7 = *(_QWORD *)(v6 + 160);
        if ( v7 )
          v8 = (AnimationGroup *)(v7 + v6 + 160);
        else
          v8 = 0i64;
        --v8->mAnimRefCount;
        if ( !v8->mRefCount && !v8->mAnimRefCount )
          AnimationGroup::DestroyStreamHandle(v8);
        --*(_WORD *)(v6 + 192);
        v9 = (__int64 *)(v3 + 24);
        if ( *((_QWORD *)v3 + 5) )
        {
          v10 = *v9;
          v11 = (_QWORD *)*((_QWORD *)v3 + 4);
          *(_QWORD *)(v10 + 8) = v11;
          *v11 = v10;
          *v9 = (__int64)v9;
          *((_QWORD *)v3 + 4) = v3 + 24;
        }
        *((_QWORD *)v3 + 5) = 0i64;
      }
    }
    while ( v1[1] != (char *)v1 );
    v2->mDurationCached = 3.4028235e38;
  }
}

// File Line: 1095
// RVA: 0x3A7A50
char __fastcall SkeletalAnimation::GetAnimationRootOrigin(SkeletalAnimation *this, UFG::qMatrix44 *outMatrix)
{
  UFG::qResourceData *v2; // rax
  UFG::qMatrix44 *v3; // rbx
  SkeletalAnimation *v4; // rcx
  UFG::qResourceData *v5; // rax
  _WORD *v6; // rcx
  signed int v7; // ST20_4
  char result; // al
  UFG::qVector4 v9; // xmm2
  unsigned int v10; // [rsp+30h] [rbp-88h]
  unsigned int v11; // [rsp+34h] [rbp-84h]
  unsigned int v12; // [rsp+38h] [rbp-80h]
  unsigned int v13; // [rsp+3Ch] [rbp-7Ch]
  unsigned int v14; // [rsp+40h] [rbp-78h]
  unsigned int v15; // [rsp+44h] [rbp-74h]
  unsigned int v16; // [rsp+48h] [rbp-70h]
  hkQsTransformf v17; // [rsp+50h] [rbp-68h]
  char v18; // [rsp+80h] [rbp-38h]

  v2 = this->m_AnimationResourceHandle.mData;
  v3 = outMatrix;
  if ( !v2 || (v2 = (UFG::qResourceData *)v2[1].mNode.mChild[0]) == 0i64 )
  {
    v4 = this->m_pFallbackAnimation;
    if ( v4 )
    {
      v5 = v4->m_AnimationResourceHandle.mData;
      if ( !v5 )
        goto LABEL_9;
      v2 = (UFG::qResourceData *)v5[1].mNode.mChild[0];
    }
    if ( !v2 )
      goto LABEL_9;
  }
  v6 = *(_WORD **)&v2->mNode.mUID;
  if ( v6[14] >= 7 )
  {
    v7 = 7;
    (*(void (__fastcall **)(_WORD *, unsigned int *, signed __int64, char *, signed int, unsigned int *))(*(_QWORD *)v6 + 32i64))(
      v6,
      &v10,
      1i64,
      &v18,
      v7,
      &v10);
    v17.m_scale = (hkVector4f)query.m_quad;
    v17.m_rotation.m_vec.m_quad = _mm_unpacklo_ps(
                                    _mm_unpacklo_ps((__m128)v13, (__m128)v15),
                                    _mm_unpacklo_ps((__m128)v14, (__m128)v16));
    v17.m_translation.m_quad = _mm_unpacklo_ps(
                                 _mm_unpacklo_ps((__m128)v10, (__m128)v12),
                                 _mm_unpacklo_ps((__m128)v11, (__m128)0i64));
    hkQsTransformf::get4x4ColumnMajor(&v17, &v3->v0.x);
    return 1;
  }
LABEL_9:
  v9 = 0i64;
  result = 0;
  v9.x = (float)1;
  outMatrix->v0 = v9;
  outMatrix->v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v9, (__m128)v9, 81);
  outMatrix->v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v9, (__m128)v9, 69);
  outMatrix->v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v9, (__m128)v9, 21);
  return result;
}

// File Line: 1154
// RVA: 0x3AE2B0
void __fastcall SkeletalAnimation::ResolveFallbackAnimation(SkeletalAnimation *this, SkeletalAnimation *pGlobalFallbackAnimation)
{
  SkeletalAnimation *v2; // rsi
  SkeletalAnimation *v3; // rdi
  unsigned int *v4; // rax
  signed __int64 v5; // rbx
  __int64 v6; // rax
  signed __int64 v7; // rax
  unsigned int v8; // edx
  UFG::qBaseTreeRB *v9; // rax

  v2 = pGlobalFallbackAnimation;
  v3 = this;
  if ( !(_S7_8 & 1) )
  {
    _S7_8 |= 1u;
    UFG::qSymbolUC::create_from_string(&symFallbackAnimSymbol_refpose, "refpose");
    atexit(SkeletalAnimation::ResolveFallbackAnimation_::_2_::_dynamic_atexit_destructor_for__symFallbackAnimSymbol_refpose__);
  }
  v4 = &v3->mFallbackAnimSymbol.mUID;
  v5 = 0i64;
  if ( v3->mFallbackAnimSymbol.mUID == -1 )
  {
    v6 = v3->m_pAnimationGroup.mOffset;
    if ( v6 )
      v7 = (signed __int64)&v3->m_pAnimationGroup + v6;
    else
      v7 = 0i64;
    v4 = (unsigned int *)(v7 + 176);
  }
  v8 = *v4;
  if ( *v4 == -1 )
    goto LABEL_18;
  if ( symFallbackAnimSymbol_refpose.mUID == v8 )
  {
    v3->m_pFallbackAnimation = 0i64;
    return;
  }
  if ( v8 )
  {
    v9 = UFG::qBaseTreeRB::Get(&AnimationDataBase::sAnimationDataBase->mAnimations.mTree, v8);
    if ( v9 )
      v5 = (signed __int64)&v9[-1].mNULL;
  }
  v3->m_pFallbackAnimation = (SkeletalAnimation *)v5;
  if ( !v5 )
LABEL_18:
    v3->m_pFallbackAnimation = v2;
}

