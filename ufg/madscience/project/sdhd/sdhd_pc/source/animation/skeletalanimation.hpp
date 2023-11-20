// File Line: 120
// RVA: 0x2989C0
void __fastcall SkeletalAnimation::SkeletalAnimation(SkeletalAnimation *this, MemImageLoadFlag flag)
{
  SkeletalAnimation *v2; // rdi
  UFG::qNode<SkeletalAnimation,SkeletalAnimation> *v3; // rax
  UFG::qList<SkeletalAnimationHandle,SkeletalAnimationList,0,0> *v4; // [rsp+50h] [rbp+18h]

  v2 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  UFG::qSafePointerNode<SkeletalAnimation>::qSafePointerNode<SkeletalAnimation>((UFG::qSafePointerNode<SkeletalAnimation> *)&this->vfptr);
  v2->mNode.mParent = 0i64;
  v2->mNode.mChild[0] = 0i64;
  v2->mNode.mChild[1] = 0i64;
  v3 = (UFG::qNode<SkeletalAnimation,SkeletalAnimation> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (Expression::IMemberMapVtbl *)&SkeletalAnimation::`vftable{for `Expression::IMemberMap};
  v2->vfptr = (UFG::qSafePointerNode<SkeletalAnimation>Vtbl *)&SkeletalAnimation::`vftable{for `UFG::qSafePointerNode<SkeletalAnimation>};
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2->m_AnimationResourceHandle.mPrev);
  v2->m_AnimationResourceHandle.m_pSkeletalAnimationOwner = 0i64;
  v2->m_AnimationResourceHandle.m_bUnloading = 0;
  v4 = &v2->m_SkeletalAnimationHandles;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
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
    result = (TrackGroup *)((char *)result + (_QWORD)this + 176);
  return result;
}

// File Line: 159
// RVA: 0x2C31B0
MotionPhaseChannel *__fastcall SkeletalAnimation::GetMotionPhaseChannel(SkeletalAnimation *this)
{
  MotionPhaseChannel *result; // rax

  result = (MotionPhaseChannel *)this->mMotionPhaseChannel.mOffset;
  if ( result )
    result = (MotionPhaseChannel *)((char *)result + (_QWORD)this + 184);
  return result;
}

// File Line: 410
// RVA: 0x3A8290
float __fastcall SkeletalAnimation::GetDuration(SkeletalAnimation *this)
{
  float result; // xmm0_4
  UFG::qResourceData *v2; // rbx
  SkeletalAnimation *v3; // rax
  UFG::qResourceData *v4; // rbx
  hkReferencedObject *v5; // rcx
  hkReferencedObject *v6; // rbx
  __int64 *v7; // rsi
  char v8; // di
  hkReferencedObject *v9; // rcx
  __int64 v10; // rsi
  hkReferencedObject *v11; // [rsp+58h] [rbp+10h]
  hkReferencedObject *v12; // [rsp+60h] [rbp+18h]

  result = this->mDurationCached;
  if ( result != 3.4028235e38 )
    return result;
  v2 = this->m_AnimationResourceHandle.mData;
  if ( v2 )
  {
    v2 = (UFG::qResourceData *)v2[1].mNode.mChild[0];
    if ( v2 )
      goto LABEL_8;
  }
  v3 = this->m_pFallbackAnimation;
  if ( v3 )
  {
    v4 = v3->m_AnimationResourceHandle.mData;
    if ( !v4 )
      goto LABEL_11;
    v2 = (UFG::qResourceData *)v4[1].mNode.mChild[0];
  }
  if ( v2 )
  {
LABEL_8:
    v5 = *(hkReferencedObject **)&v2->mNode.mUID;
    if ( v5 )
      hkReferencedObject::addReference(v5);
    v6 = *(hkReferencedObject **)&v2->mNode.mUID;
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
    result = *(float *)(v10 + 20);
  else
    result = SkeletalAnimation::msTposeAnimPlayDuration;
  return result;
}

