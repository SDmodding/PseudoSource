// File Line: 95
// RVA: 0x39FF70
void __fastcall SkeletalAnimationHandle::~SkeletalAnimationHandle(SkeletalAnimationHandle *this)
{
  UFG::qSafePointer<SkeletalAnimation,SkeletalAnimation> *p_m_SkeletalAnimation; // rdx
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v7; // rcx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v8; // rax

  SkeletalAnimationHandle::Unbind(this);
  p_m_SkeletalAnimation = &this->m_SkeletalAnimation;
  if ( this->m_SkeletalAnimation.m_pPointer )
  {
    mPrev = p_m_SkeletalAnimation->mPrev;
    mNext = this->m_SkeletalAnimation.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_SkeletalAnimation->mPrev = p_m_SkeletalAnimation;
    this->m_SkeletalAnimation.mNext = &this->m_SkeletalAnimation;
  }
  this->m_SkeletalAnimation.m_pPointer = 0i64;
  v5 = p_m_SkeletalAnimation->mPrev;
  v6 = this->m_SkeletalAnimation.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_SkeletalAnimation->mPrev = p_m_SkeletalAnimation;
  this->m_SkeletalAnimation.mNext = &this->m_SkeletalAnimation;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 130
// RVA: 0x3AAC20
void __fastcall SkeletalAnimationHandle::Init(SkeletalAnimationHandle *this)
{
  unsigned int mUID; // edx
  char *v2; // rbx
  UFG::qBaseTreeRB *v4; // rax
  SkeletalAnimation *p_mNULL; // r8
  UFG::qSafePointer<SkeletalAnimation,SkeletalAnimation> *p_m_SkeletalAnimation; // rdx
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *v9; // rax
  SkeletalAnimation *m_pPointer; // rcx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *p_mNode; // rcx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v12; // rax
  SkeletalAnimation *v13; // rax
  __int64 mOffset; // rcx

  mUID = this->m_SkeletalAnimationName.mUID;
  v2 = 0i64;
  if ( !mUID
    || (v4 = UFG::qBaseTreeRB::Get(&AnimationDataBase::sAnimationDataBase->mAnimations.mTree, mUID),
        p_mNULL = (SkeletalAnimation *)&v4[-1].mNULL,
        !v4) )
  {
    p_mNULL = 0i64;
  }
  p_m_SkeletalAnimation = &this->m_SkeletalAnimation;
  if ( this->m_SkeletalAnimation.m_pPointer )
  {
    mPrev = p_m_SkeletalAnimation->mPrev;
    mNext = this->m_SkeletalAnimation.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_SkeletalAnimation->mPrev = p_m_SkeletalAnimation;
    this->m_SkeletalAnimation.mNext = &this->m_SkeletalAnimation;
  }
  this->m_SkeletalAnimation.m_pPointer = p_mNULL;
  if ( p_mNULL )
  {
    v9 = p_mNULL->m_SafePointerList.UFG::qSafePointerNode<SkeletalAnimation>::mNode.UFG::qSafePointerNode<SkeletalAnimation>::mPrev;
    v9->mNext = p_m_SkeletalAnimation;
    p_m_SkeletalAnimation->mPrev = v9;
    this->m_SkeletalAnimation.mNext = &p_mNULL->m_SafePointerList.UFG::qSafePointerNode<SkeletalAnimation>::mNode;
    p_mNULL->m_SafePointerList.UFG::qSafePointerNode<SkeletalAnimation>::mNode.UFG::qSafePointerNode<SkeletalAnimation>::mPrev = p_m_SkeletalAnimation;
  }
  m_pPointer = this->m_SkeletalAnimation.m_pPointer;
  if ( m_pPointer )
  {
    p_mNode = &m_pPointer->m_SkeletalAnimationHandles.mNode;
    v12 = p_mNode->mPrev;
    v12->mNext = this;
    this->mPrev = v12;
    this->mNext = p_mNode;
    p_mNode->mPrev = this;
    v13 = this->m_SkeletalAnimation.m_pPointer;
    ++v13->mRefCount;
    ++v13->mRefCountTotal;
    mOffset = v13->m_pAnimationGroup.mOffset;
    if ( mOffset )
      v2 = (char *)&v13->m_pAnimationGroup + mOffset;
    ++*((_DWORD *)v2 + 46);
    ++*((_DWORD *)v2 + 48);
  }
}

// File Line: 147
// RVA: 0x3B0380
void __fastcall SkeletalAnimationHandle::Unbind(SkeletalAnimationHandle *this)
{
  SkeletalAnimation *m_pPointer; // rbx
  __int64 mOffset; // rax
  AnimationGroup *v4; // rcx
  UFG::qSafePointer<SkeletalAnimation,SkeletalAnimation> *p_m_SkeletalAnimation; // rdx
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *mNext; // rax

  m_pPointer = this->m_SkeletalAnimation.m_pPointer;
  if ( m_pPointer )
  {
    mOffset = m_pPointer->m_pAnimationGroup.mOffset;
    if ( mOffset )
      v4 = (AnimationGroup *)((char *)&m_pPointer->m_pAnimationGroup + mOffset);
    else
      v4 = 0i64;
    --v4->mAnimRefCount;
    if ( !v4->mRefCount && !v4->mAnimRefCount )
      AnimationGroup::DestroyStreamHandle(v4);
    p_m_SkeletalAnimation = &this->m_SkeletalAnimation;
    --m_pPointer->mRefCount;
    if ( this->m_SkeletalAnimation.m_pPointer )
    {
      mPrev = p_m_SkeletalAnimation->mPrev;
      mNext = this->m_SkeletalAnimation.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_SkeletalAnimation->mPrev = p_m_SkeletalAnimation;
      this->m_SkeletalAnimation.mNext = &this->m_SkeletalAnimation;
    }
    this->m_SkeletalAnimation.m_pPointer = 0i64;
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gAnimTrackFactory__);
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
  this->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  UFG::qSafePointerNode<SkeletalAnimation>::qSafePointerNode<SkeletalAnimation>(&this->UFG::qSafePointerNode<SkeletalAnimation>);
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mPrev = &this->UFG::qNode<SkeletalAnimation,SkeletalAnimation>;
  this->mNext = &this->UFG::qNode<SkeletalAnimation,SkeletalAnimation>;
  this->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&SkeletalAnimation::`vftable{for `Expression::IMemberMap};
  this->UFG::qSafePointerNode<SkeletalAnimation>::vfptr = (UFG::qSafePointerNode<SkeletalAnimation>Vtbl *)&SkeletalAnimation::`vftable{for `UFG::qSafePointerNode<SkeletalAnimation>};
  UFG::qResourceHandle::qResourceHandle(&this->m_AnimationResourceHandle);
  this->m_AnimationResourceHandle.m_pSkeletalAnimationOwner = 0i64;
  this->m_AnimationResourceHandle.m_bUnloading = 0;
  this->m_pFallbackAnimation = 0i64;
  this->m_SkeletalAnimationHandles.mNode.mPrev = &this->m_SkeletalAnimationHandles.mNode;
  this->m_SkeletalAnimationHandles.mNode.mNext = &this->m_SkeletalAnimationHandles.mNode;
  *(_QWORD *)&this->mNameSymbol.mUID = -1i64;
  *(_QWORD *)&this->mRefCount = 0i64;
  *(_QWORD *)&this->mBlendMode = 0i64;
  this->mDurationCached = 3.4028235e38;
  this->mTracks.mOffset = 0i64;
  this->mMotionPhaseChannel.mOffset = 0i64;
}

// File Line: 315
// RVA: 0x39FD90
void __fastcall SkeletalAnimation::~SkeletalAnimation(SkeletalAnimation *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rsi
  __int64 mOffset; // rax
  __int64 v4; // rax
  char *v5; // rcx
  __int64 v6; // rax
  char *v7; // rcx
  __int64 v8; // rax
  char *v9; // rcx
  UFG::qList<SkeletalAnimationHandle,SkeletalAnimationList,0,0> *p_m_SkeletalAnimationHandles; // r8
  SkeletalAnimation *mNext; // rax
  Expression::IMemberMapVtbl *vfptr; // rdx
  Expression::IMemberMap *mResourceOwner; // rcx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *mPrev; // rcx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v15; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v17; // rax
  UFG::qNode<SkeletalAnimation,SkeletalAnimation> *v18; // rcx
  UFG::qNode<SkeletalAnimation,SkeletalAnimation> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v21; // rax

  this->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&SkeletalAnimation::`vftable{for `Expression::IMemberMap};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->UFG::qSafePointerNode<SkeletalAnimation>;
  this->UFG::qSafePointerNode<SkeletalAnimation>::vfptr = (UFG::qSafePointerNode<SkeletalAnimation>Vtbl *)&SkeletalAnimation::`vftable{for `UFG::qSafePointerNode<SkeletalAnimation>};
  mOffset = this->m_pAnimationGroup.mOffset;
  if ( mOffset && (UFG::qOffset64<AnimationGroup *> *)((char *)&this->m_pAnimationGroup + mOffset) )
  {
    v4 = this->m_pAnimationGroup.mOffset;
    if ( v4 )
      v5 = (char *)&this->m_pAnimationGroup + v4;
    else
      v5 = 0i64;
    BinPtrArray<UELNode,0,0>::Remove((BinPtrArray<ActionNode,0,0> *)(v5 + 120), (ActionNode *)this);
  }
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&AnimationDataBase::sAnimationDataBase->mAnimations,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->UFG::qNodeRB<SkeletalAnimation>);
  v6 = this->mTracks.mOffset;
  if ( v6 )
  {
    v7 = (char *)&this->mTracks + v6;
    if ( v7 )
      (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)v7 + 8i64))(v7, 1i64);
  }
  v8 = this->mMotionPhaseChannel.mOffset;
  if ( v8 )
  {
    v9 = (char *)&this->mMotionPhaseChannel + v8;
    if ( v9 )
      (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)v9 + 8i64))(v9, 1i64);
  }
  p_m_SkeletalAnimationHandles = &this->m_SkeletalAnimationHandles;
  mNext = (SkeletalAnimation *)this->m_SkeletalAnimationHandles.mNode.mNext;
  if ( mNext != (SkeletalAnimation *)&this->m_SkeletalAnimationHandles )
  {
    do
    {
      vfptr = mNext->Expression::IMemberMap::vfptr;
      mResourceOwner = mNext->mResourceOwner;
      vfptr->__vecDelDtor = (void *(__fastcall *)(Expression::IMemberMap *, unsigned int))mResourceOwner;
      mResourceOwner->vfptr = vfptr;
      mNext->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)mNext;
      mNext->mResourceOwner = mNext;
      mNext = (SkeletalAnimation *)this->m_SkeletalAnimationHandles.mNode.mNext;
    }
    while ( mNext != (SkeletalAnimation *)p_m_SkeletalAnimationHandles );
  }
  mPrev = p_m_SkeletalAnimationHandles->mNode.mPrev;
  v15 = this->m_SkeletalAnimationHandles.mNode.mNext;
  mPrev->mNext = v15;
  v15->mPrev = mPrev;
  p_m_SkeletalAnimationHandles->mNode.mPrev = &p_m_SkeletalAnimationHandles->mNode;
  this->m_SkeletalAnimationHandles.mNode.mNext = &this->m_SkeletalAnimationHandles.mNode;
  Inventory = `UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result )
  {
    v17 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v17, 0x53F1685Eu);
    `UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->m_AnimationResourceHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->m_AnimationResourceHandle);
  v18 = this->mPrev;
  v19 = this->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  this->mPrev = &this->UFG::qNode<SkeletalAnimation,SkeletalAnimation>;
  this->mNext = &this->UFG::qNode<SkeletalAnimation,SkeletalAnimation>;
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<SkeletalAnimation>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v2->m_SafePointerList);
  v20 = v2->m_SafePointerList.mNode.mPrev;
  v21 = v2->m_SafePointerList.mNode.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v2->m_SafePointerList.mNode.mPrev = &v2->m_SafePointerList.mNode;
  v2->m_SafePointerList.mNode.mNext = &v2->m_SafePointerList.mNode;
  this->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 335
// RVA: 0x3AE9C0
void __fastcall SkeletalAnimation::Serialize(SkeletalAnimation *this, IActionTreeSerializer *serializer)
{
  __int64 mOffset; // rax
  Expression::IMemberMap *v5; // rdx
  __int64 v6; // rax
  Expression::IMemberMap *v7; // rdx

  mOffset = this->mTracks.mOffset;
  if ( mOffset )
  {
    v5 = (Expression::IMemberMap *)((char *)&this->mTracks + mOffset);
    if ( v5 )
      IActionTreeSerializer::PushObjectToSerialize(serializer, v5);
  }
  v6 = this->mMotionPhaseChannel.mOffset;
  if ( v6 )
  {
    v7 = (Expression::IMemberMap *)((char *)&this->mMotionPhaseChannel + v6);
    if ( v7 )
      IActionTreeSerializer::PushObjectToSerialize(serializer, v7);
  }
}

// File Line: 390
// RVA: 0x3AC400
void __fastcall SkeletalAnimation::OnSave(SkeletalAnimation *this)
{
  __int64 mOffset; // rax
  MotionPhaseChannel *v2; // rcx

  mOffset = this->mMotionPhaseChannel.mOffset;
  if ( mOffset )
  {
    v2 = (MotionPhaseChannel *)((char *)&this->mMotionPhaseChannel + mOffset);
    if ( v2 )
      MotionPhaseChannel::Sort(v2);
  }
}

// File Line: 432
// RVA: 0x3AC000
void __fastcall SkeletalAnimation::OnLoad(SkeletalAnimation *this)
{
  UFG::qResourceData *mData; // rbx
  SkeletalAnimation *m_pFallbackAnimation; // rax
  UFG::qResourceData *v4; // rbx
  hkReferencedObject *v5; // rcx
  hkReferencedObject *v6; // rbx
  __int64 *v7; // rbp
  char v8; // di
  hkReferencedObject *v9; // rcx
  __int64 v10; // rbp
  hkReferencedObject *v11; // [rsp+58h] [rbp+10h] BYREF
  hkReferencedObject *v12; // [rsp+60h] [rbp+18h] BYREF

  mData = this->m_AnimationResourceHandle.mData;
  if ( mData )
  {
    mData = (UFG::qResourceData *)mData[1].mNode.mChild[0];
    if ( mData )
      goto LABEL_7;
  }
  m_pFallbackAnimation = this->m_pFallbackAnimation;
  if ( m_pFallbackAnimation )
  {
    v4 = m_pFallbackAnimation->m_AnimationResourceHandle.mData;
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
    mData = (UFG::qResourceData *)v4[1].mNode.mChild[0];
  }
  if ( !mData )
    goto LABEL_10;
LABEL_7:
  v5 = *(hkReferencedObject **)&mData->mNode.mUID;
  if ( v5 )
    hkReferencedObject::addReference(v5);
  v6 = *(hkReferencedObject **)&mData->mNode.mUID;
  v12 = v6;
  v7 = (__int64 *)&v12;
  v8 = 1;
  v9 = v11;
LABEL_11:
  v10 = *v7;
  if ( (v8 & 2) != 0 )
  {
    v8 &= ~2u;
    if ( v9 )
      hkReferencedObject::removeReference(v9);
    v11 = 0i64;
  }
  if ( (v8 & 1) != 0 )
  {
    if ( v6 )
      hkReferencedObject::removeReference(v6);
    v12 = 0i64;
  }
  if ( v10 )
    this->mDurationCached = *(float *)(v10 + 20);
  else
    this->mDurationCached = 3.4028235e38;
}

// File Line: 447
// RVA: 0x3AC430
void __fastcall SkeletalAnimation::OnUnload(SkeletalAnimation *this)
{
  UFG::qList<SkeletalAnimationHandle,SkeletalAnimationList,0,0> *p_m_SkeletalAnimationHandles; // rsi
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *mPrev; // rbx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v4; // rdx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *mNext; // rax
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v6; // rdi
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v7; // rax
  AnimationGroup *v8; // rcx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> **p_mNext; // rdx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v10; // rcx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v11; // rax

  p_m_SkeletalAnimationHandles = &this->m_SkeletalAnimationHandles;
  if ( (UFG::qList<SkeletalAnimationHandle,SkeletalAnimationList,0,0> *)this->m_SkeletalAnimationHandles.mNode.mNext == &this->m_SkeletalAnimationHandles )
  {
    this->mDurationCached = 3.4028235e38;
  }
  else
  {
    do
    {
      mPrev = p_m_SkeletalAnimationHandles->mNode.mPrev;
      v4 = p_m_SkeletalAnimationHandles->mNode.mPrev->mPrev;
      mNext = p_m_SkeletalAnimationHandles->mNode.mPrev->mNext;
      v4->mNext = mNext;
      mNext->mPrev = v4;
      mPrev->mPrev = mPrev;
      mPrev->mNext = mPrev;
      v6 = mPrev[2].mNext;
      if ( v6 )
      {
        v7 = v6[10].mPrev;
        if ( v7 )
          v8 = (AnimationGroup *)((char *)&v6[10] + (_QWORD)v7);
        else
          v8 = 0i64;
        --v8->mAnimRefCount;
        if ( !v8->mRefCount && !v8->mAnimRefCount )
          AnimationGroup::DestroyStreamHandle(v8);
        --LOWORD(v6[12].mPrev);
        p_mNext = &mPrev[1].mNext;
        if ( mPrev[2].mNext )
        {
          v10 = *p_mNext;
          v11 = mPrev[2].mPrev;
          v10->mNext = v11;
          v11->mPrev = v10;
          *p_mNext = (UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *)p_mNext;
          mPrev[2].mPrev = (UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *)((char *)mPrev + 24);
        }
        mPrev[2].mNext = 0i64;
      }
    }
    while ( (UFG::qList<SkeletalAnimationHandle,SkeletalAnimationList,0,0> *)p_m_SkeletalAnimationHandles->mNode.mNext != p_m_SkeletalAnimationHandles );
    this->mDurationCached = 3.4028235e38;
  }
}

// File Line: 1095
// RVA: 0x3A7A50
char __fastcall SkeletalAnimation::GetAnimationRootOrigin(SkeletalAnimation *this, UFG::qMatrix44 *outMatrix)
{
  UFG::qResourceData *mData; // rax
  SkeletalAnimation *m_pFallbackAnimation; // rcx
  UFG::qResourceData *v5; // rax
  __int16 *v6; // rcx
  char result; // al
  UFG::qVector4 v8; // xmm2
  int v9[8]; // [rsp+30h] [rbp-88h] BYREF
  hkQsTransformf v10; // [rsp+50h] [rbp-68h] BYREF
  char v11[56]; // [rsp+80h] [rbp-38h] BYREF

  mData = this->m_AnimationResourceHandle.mData;
  if ( !mData || (mData = (UFG::qResourceData *)mData[1].mNode.mChild[0]) == 0i64 )
  {
    m_pFallbackAnimation = this->m_pFallbackAnimation;
    if ( m_pFallbackAnimation )
    {
      v5 = m_pFallbackAnimation->m_AnimationResourceHandle.mData;
      if ( !v5 )
        goto LABEL_9;
      mData = (UFG::qResourceData *)v5[1].mNode.mChild[0];
    }
    if ( !mData )
      goto LABEL_9;
  }
  v6 = *(__int16 **)&mData->mNode.mUID;
  if ( v6[14] >= 7 )
  {
    (*(void (__fastcall **)(__int16 *, int *, __int64, char *, int, int *))(*(_QWORD *)v6 + 32i64))(
      v6,
      v9,
      1i64,
      v11,
      7,
      v9);
    v10.m_scale = (hkVector4f)query.m_quad;
    v10.m_rotation.m_vec.m_quad = _mm_unpacklo_ps(
                                    _mm_unpacklo_ps((__m128)(unsigned int)v9[3], (__m128)(unsigned int)v9[5]),
                                    _mm_unpacklo_ps((__m128)(unsigned int)v9[4], (__m128)(unsigned int)v9[6]));
    v10.m_translation.m_quad = _mm_unpacklo_ps(
                                 _mm_unpacklo_ps((__m128)(unsigned int)v9[0], (__m128)(unsigned int)v9[2]),
                                 _mm_unpacklo_ps((__m128)(unsigned int)v9[1], (__m128)0i64));
    hkQsTransformf::get4x4ColumnMajor(&v10, &outMatrix->v0.x);
    return 1;
  }
LABEL_9:
  v8 = 0i64;
  result = 0;
  v8.x = (float)1;
  outMatrix->v0 = v8;
  outMatrix->v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v8, (__m128)v8, 81);
  outMatrix->v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v8, (__m128)v8, 69);
  outMatrix->v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v8, (__m128)v8, 21);
  return result;
}

// File Line: 1154
// RVA: 0x3AE2B0
void __fastcall SkeletalAnimation::ResolveFallbackAnimation(
        SkeletalAnimation *this,
        SkeletalAnimation *pGlobalFallbackAnimation)
{
  UFG::qSymbolUC *p_mFallbackAnimSymbol; // rax
  SkeletalAnimation *p_mNULL; // rbx
  __int64 mOffset; // rax
  UFG::qSymbolUC *v7; // rax
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v9; // rax

  if ( (_S7_8 & 1) == 0 )
  {
    _S7_8 |= 1u;
    UFG::qSymbolUC::create_from_string(&symFallbackAnimSymbol_refpose, "refpose");
    atexit(SkeletalAnimation::ResolveFallbackAnimation_::_2_::_dynamic_atexit_destructor_for__symFallbackAnimSymbol_refpose__);
  }
  p_mFallbackAnimSymbol = &this->mFallbackAnimSymbol;
  p_mNULL = 0i64;
  if ( this->mFallbackAnimSymbol.mUID == -1 )
  {
    mOffset = this->m_pAnimationGroup.mOffset;
    if ( mOffset )
      v7 = (UFG::qSymbolUC *)((char *)&this->m_pAnimationGroup + mOffset);
    else
      v7 = 0i64;
    p_mFallbackAnimSymbol = v7 + 44;
  }
  mUID = p_mFallbackAnimSymbol->mUID;
  if ( p_mFallbackAnimSymbol->mUID == -1 )
    goto LABEL_15;
  if ( symFallbackAnimSymbol_refpose.mUID == mUID )
  {
    this->m_pFallbackAnimation = 0i64;
    return;
  }
  if ( mUID )
  {
    v9 = UFG::qBaseTreeRB::Get(&AnimationDataBase::sAnimationDataBase->mAnimations.mTree, mUID);
    if ( v9 )
      p_mNULL = (SkeletalAnimation *)&v9[-1].mNULL;
  }
  this->m_pFallbackAnimation = p_mNULL;
  if ( !p_mNULL )
LABEL_15:
    this->m_pFallbackAnimation = pGlobalFallbackAnimation;
}

