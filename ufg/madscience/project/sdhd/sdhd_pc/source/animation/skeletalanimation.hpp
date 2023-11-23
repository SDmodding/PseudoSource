// File Line: 120
// RVA: 0x2989C0
void __fastcall SkeletalAnimation::SkeletalAnimation(SkeletalAnimation *this, MemImageLoadFlag flag)
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
  this->m_SkeletalAnimationHandles.mNode.mPrev = &this->m_SkeletalAnimationHandles.mNode;
  this->m_SkeletalAnimationHandles.mNode.mNext = &this->m_SkeletalAnimationHandles.mNode;
}

// File Line: 123
// RVA: 0x2BF740
__int64 __fastcall SkeletalAnimation::GetClassNameUID(SkeletalAnimation *this)
{
  return SkeletalAnimation::sClassNameUID;
}

// File Line: 158
// RVA: 0x2C32A0
TrackGroup *__fastcall SkeletalAnimation::GetTrackGroup(SkeletalAnimation *this)
{
  TrackGroup *result; // rax

  result = (TrackGroup *)this->mTracks.mOffset;
  if ( result )
    return (TrackGroup *)((char *)result + (_QWORD)this + 176);
  return result;
}

// File Line: 159
// RVA: 0x2C31B0
MotionPhaseChannel *__fastcall SkeletalAnimation::GetMotionPhaseChannel(SkeletalAnimation *this)
{
  MotionPhaseChannel *result; // rax

  result = (MotionPhaseChannel *)this->mMotionPhaseChannel.mOffset;
  if ( result )
    return (MotionPhaseChannel *)((char *)result + (_QWORD)this + 184);
  return result;
}

// File Line: 410
// RVA: 0x3A8290
float __fastcall SkeletalAnimation::GetDuration(SkeletalAnimation *this)
{
  float result; // xmm0_4
  UFG::qResourceData *mData; // rbx
  SkeletalAnimation *m_pFallbackAnimation; // rax
  UFG::qResourceData *v4; // rbx
  hkReferencedObject *v5; // rcx
  hkReferencedObject *v6; // rbx
  __int64 *v7; // rsi
  char v8; // di
  hkReferencedObject *v9; // rcx
  __int64 v10; // rsi
  hkReferencedObject *v11; // [rsp+58h] [rbp+10h] BYREF
  hkReferencedObject *v12; // [rsp+60h] [rbp+18h] BYREF

  result = this->mDurationCached;
  if ( result != 3.4028235e38 )
    return result;
  mData = this->m_AnimationResourceHandle.mData;
  if ( mData )
  {
    mData = (UFG::qResourceData *)mData[1].mNode.mChild[0];
    if ( mData )
      goto LABEL_8;
  }
  m_pFallbackAnimation = this->m_pFallbackAnimation;
  if ( m_pFallbackAnimation )
  {
    v4 = m_pFallbackAnimation->m_AnimationResourceHandle.mData;
    if ( !v4 )
      goto LABEL_11;
    mData = (UFG::qResourceData *)v4[1].mNode.mChild[0];
  }
  if ( mData )
  {
LABEL_8:
    v5 = *(hkReferencedObject **)&mData->mNode.mUID;
    if ( v5 )
      hkReferencedObject::addReference(v5);
    v6 = *(hkReferencedObject **)&mData->mNode.mUID;
    v12 = v6;
    v7 = (__int64 *)&v12;
    v8 = 1;
    v9 = v11;
    goto LABEL_12;
  }
LABEL_11:
  v9 = 0i64;
  v11 = 0i64;
  v7 = (__int64 *)&v11;
  v8 = 2;
  v6 = v12;
LABEL_12:
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
    return *(float *)(v10 + 20);
  else
    return SkeletalAnimation::msTposeAnimPlayDuration;
}

