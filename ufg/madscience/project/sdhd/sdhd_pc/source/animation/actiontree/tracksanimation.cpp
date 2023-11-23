// File Line: 41
// RVA: 0x149F320
__int64 dynamic_initializer_for__animEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&animEnum, gAnimationPlayModeStringList, 8, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__animEnum__);
}

// File Line: 45
// RVA: 0x149F2F0
__int64 dynamic_initializer_for__animBlendEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&animBlendEnum, gAnimationBlendStringList, 2, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__animBlendEnum__);
}

// File Line: 47
// RVA: 0x149F450
__int64 dynamic_initializer_for__symNone__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("none", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symNone, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symNone__);
}

// File Line: 50
// RVA: 0x149F190
__int64 dynamic_initializer_for__AnimationTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AnimationTrack", 0xFFFFFFFF);
  AnimationTrack::sClassNameUID = result;
  return result;
}

// File Line: 93
// RVA: 0x30F290
void __fastcall AnimationTrack::AnimationTrack(AnimationTrack *this)
{
  ITrack::ITrack(this, AnimationTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AnimationTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationTrack::`vftable;
  this->mAnimation = 0i64;
  this->mStartFrame = 0.0;
  this->mEndFrame = -1.0;
  this->mBlendInTime = 0.33333334;
  this->mBlendOutTime = 0.33333334;
  *(_QWORD *)&this->mPlayRate = 1065353216i64;
  this->mWeightSetName.mUID = symNone.mUID;
  this->mAnimationName.mUID = -1;
  *(_DWORD *)&this->mAnimationPlayMode.mValue = 0x1000000;
  *(_WORD *)&this->mPhaseIn = 256;
  this->mResetMotionIntentionToFacing = 1;
  this->mMaster = 1;
  this->mAnimationName.mUID = symNone.mUID;
}

// File Line: 99
// RVA: 0x30FC20
void __fastcall AnimationTrack::~AnimationTrack(AnimationTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 130
// RVA: 0x312A00
void __fastcall AnimationTrack::ResolveReferences(AnimationTrack *this, ActionNode *pParent)
{
  SkeletalAnimation *mAnimation; // rax
  AnimationDataBase *Instance; // rax
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v6; // rax
  SkeletalAnimation *p_mNULL; // rax

  _((AMD_HD3D *)this);
  mAnimation = this->mAnimation;
  if ( mAnimation )
  {
    --mAnimation->mNumReferencesByAct;
    this->mAnimation = 0i64;
  }
  Instance = AnimationDataBase::GetInstance();
  mUID = this->mAnimationName.mUID;
  if ( mUID )
  {
    v6 = UFG::qBaseTreeRB::Get(&Instance->mAnimations.mTree, mUID);
    if ( v6 )
    {
      p_mNULL = (SkeletalAnimation *)&v6[-1].mNULL;
      if ( p_mNULL )
      {
        ++p_mNULL->mNumReferencesByAct;
        if ( this->mAnimationBlendMode.mValue == 1 )
          p_mNULL->mIsAdditivelyBlended = 1;
        this->mAnimation = p_mNULL;
      }
    }
  }
}

// File Line: 216
// RVA: 0x3129C0
void __fastcall AnimationTrack::RemoveReferences(AnimationTrack *this)
{
  SkeletalAnimation *mAnimation; // rax

  mAnimation = this->mAnimation;
  if ( mAnimation )
  {
    --mAnimation->mNumReferencesByAct;
    this->mAnimation = 0i64;
  }
}

// File Line: 258
// RVA: 0x149F150
__int64 dynamic_initializer_for__AnimationRefPoseTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AnimationRefPoseTrack", 0xFFFFFFFF);
  AnimationRefPoseTrack::sClassNameUID = result;
  return result;
}

// File Line: 286
// RVA: 0x30F180
void __fastcall AnimationRefPoseTrack::AnimationRefPoseTrack(AnimationRefPoseTrack *this)
{
  ITrack::ITrack(this, AnimationRefPoseTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AnimationRefPoseTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationRefPoseTrack::`vftable;
  this->mStartFrame = 0.0;
  this->mEndFrame = -1.0;
  this->mBlendInTime = 0.33333334;
  *(_QWORD *)&this->mBlendOutTime = 1051372203i64;
  this->mWeightSetName.mUID = symNone.mUID;
  *(_WORD *)&this->mPreserveMotion = 1;
  this->mMaster = 0;
}

// File Line: 292
// RVA: 0x30FAE0
void __fastcall AnimationRefPoseTrack::~AnimationRefPoseTrack(AnimationRefPoseTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationRefPoseTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 316
// RVA: 0x149F130
__int64 dynamic_initializer_for__AnimationLockHighLODTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AnimationLockHighLODTrack", 0xFFFFFFFF);
  AnimationLockHighLODTrack::sClassNameUID = result;
  return result;
}

// File Line: 323
// RVA: 0x30F0D0
void __fastcall AnimationLockHighLODTrack::AnimationLockHighLODTrack(AnimationLockHighLODTrack *this)
{
  ITrack::ITrack(this, AnimationLockHighLODTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AnimationLockHighLODTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationLockHighLODTrack::`vftable;
}

// File Line: 336
// RVA: 0x149F230
__int64 dynamic_initializer_for__BlendTreeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BlendTreeTrack", 0xFFFFFFFF);
  BlendTreeTrack::sClassNameUID = result;
  return result;
}

// File Line: 363
// RVA: 0x30F740
void __fastcall BlendTreeTrack::BlendTreeTrack(BlendTreeTrack *this)
{
  char *v2; // rax
  UFG::qOffset64<BlendTreeControllerGroup *> *p_mControllers; // rcx
  __int64 v4; // rax
  char *result; // [rsp+58h] [rbp+10h] BYREF

  ITrack::ITrack(this, BlendTreeTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<BlendTreeTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&BlendTreeTrack::`vftable;
  this->mBlendTreeName.mUID = -1;
  this->mWeightSetName.mUID = symNone.mUID;
  this->mBlendInTime = 0.33333334;
  *(_QWORD *)&this->mBlendOutTime = 1051372203i64;
  this->mEndFrame = -1.0;
  *(_WORD *)&this->mAnimationPlayMode.mValue = 0;
  this->mMaster = 1;
  this->mBlendTreeName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&result, "none")->mUID;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "BlendTreeControllerGroup", 0i64, 1u);
  result = v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = &Expression::IMemberMap::`vftable;
    *((_QWORD *)v2 + 1) = 0i64;
    *(_QWORD *)v2 = &BlendTreeControllerGroup::`vftable;
    *((_DWORD *)v2 + 4) = 0;
    *((_QWORD *)v2 + 3) = 0i64;
  }
  else
  {
    v2 = 0i64;
  }
  p_mControllers = &this->mControllers;
  if ( v2 )
    v4 = v2 - (char *)p_mControllers;
  else
    v4 = 0i64;
  p_mControllers->mOffset = v4;
  *(_WORD *)&this->mPlayPriority = 0;
}

// File Line: 392
// RVA: 0x30F700
void __fastcall BlendTreeTrack::BlendTreeTrack(BlendTreeTrack *this, MemImageLoadFlag flag)
{
  ITrack::ITrack(this, flag);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<BlendTreeTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&BlendTreeTrack::`vftable;
}

// File Line: 404
// RVA: 0x311D80
BlendTreeTrack *__fastcall BlendTreeTrack::CreateClone(BlendTreeTrack *this)
{
  char *v2; // rax
  BlendTreeTrack *v3; // rax
  BlendTreeTrack *v4; // rbx
  char *v5; // rax
  __int64 p_mControllers; // rcx

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x60ui64, "BlendTreeControllerGroup::CreateClone", 0i64, 1u);
  if ( v2 )
  {
    BlendTreeTrack::BlendTreeTrack((BlendTreeTrack *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  BlendTreeTrack::operator=(v4, this);
  v5 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "BlendTreeControllerGroup", 0i64, 1u);
  if ( v5 )
  {
    *(_QWORD *)v5 = &Expression::IMemberMap::`vftable;
    *((_QWORD *)v5 + 1) = 0i64;
    *(_QWORD *)v5 = &BlendTreeControllerGroup::`vftable;
    *((_DWORD *)v5 + 4) = 0;
    *((_QWORD *)v5 + 3) = 0i64;
  }
  p_mControllers = (__int64)&v4->mControllers;
  if ( v5 )
    v5 -= p_mControllers;
  *(_QWORD *)p_mControllers = v5;
  BlendTreeTrack::CopyFrom(v4, this);
  return v4;
}

// File Line: 443
// RVA: 0x311A90
void __fastcall BlendTreeTrack::CopyFrom(BlendTreeTrack *this, BlendTreeTrack *other_BlendTreeTrack)
{
  __int64 mOffset; // rax
  UFG::qOffset64<BlendTreeControllerGroup *> *p_mControllers; // r15
  char *v5; // rdx
  char *v6; // r12
  __int64 v7; // r14
  char *v8; // rcx
  __int64 v9; // rcx
  __int64 v10; // rbp
  __int64 v11; // rax
  BinPtrArray<ITrack,1,0> *v12; // rsi
  __int64 mCount; // rdi
  unsigned int v14; // ebx
  unsigned int v15; // edx
  __int64 v16; // rax
  char *v17; // rcx
  char *v18; // rcx

  mOffset = other_BlendTreeTrack->mControllers.mOffset;
  p_mControllers = &other_BlendTreeTrack->mControllers;
  if ( mOffset )
    v5 = (char *)p_mControllers + mOffset;
  else
    v5 = 0i64;
  v6 = &v5[*((_QWORD *)v5 + 3) + 24];
  v7 = 0i64;
  while ( 1 )
  {
    v8 = p_mControllers->mOffset ? (char *)p_mControllers + p_mControllers->mOffset : 0i64;
    if ( (unsigned int)v7 >= (*((_DWORD *)v8 + 4) & 0x7FFFFFFFu) )
      break;
    v9 = (__int64)&v6[8 * v7 + *(_QWORD *)&v6[8 * v7]];
    v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9);
    v11 = this->mControllers.mOffset;
    if ( v11 )
      v12 = (BinPtrArray<ITrack,1,0> *)((char *)&this->mControllers + v11);
    else
      v12 = 0i64;
    mCount = (unsigned int)v12[1].mCount;
    LODWORD(mCount) = mCount & 0x7FFFFFFF;
    v14 = mCount + 1;
    if ( (int)mCount + 1 > (unsigned int)mCount )
    {
      v15 = 1;
      if ( (_DWORD)mCount )
        v15 = 2 * mCount;
      for ( ; v15 < v14; v15 *= 2 )
        ;
      if ( v15 - v14 > 0x10000 )
        v15 = mCount + 65537;
      BinPtrArray<Condition,1,0>::Reallocate(v12 + 1, v15, "BinPtrArray.Add");
    }
    v12[1].mCount &= 0x80000000;
    v12[1].mCount |= v14 & 0x7FFFFFFF;
    v16 = v12[1].mData.mOffset;
    if ( v16 )
      v17 = (char *)&v12[1].mData + v16;
    else
      v17 = 0i64;
    v18 = &v17[8 * mCount];
    if ( v10 )
    {
      v7 = (unsigned int)(v7 + 1);
      *(_QWORD *)v18 = v10 - (_QWORD)v18;
    }
    else
    {
      *(_QWORD *)v18 = 0i64;
      v7 = (unsigned int)(v7 + 1);
    }
  }
}

// File Line: 460
// RVA: 0x30FD70
void __fastcall BlendTreeTrack::~BlendTreeTrack(BlendTreeTrack *this)
{
  __int64 mOffset; // rax
  char *v3; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v5; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&BlendTreeTrack::`vftable;
  mOffset = this->mControllers.mOffset;
  if ( mOffset )
  {
    v3 = (char *)&this->mControllers + mOffset;
    if ( v3 )
      (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)v3 + 8i64))(v3, 1i64);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (this->mMasterRate.text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v5 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v5 != BinString::sEmptyString )
      operator delete[](v5);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 608
// RVA: 0x312B20
void __fastcall BlendTreeTrack::Serialize(BlendTreeTrack *this, IActionTreeSerializer *serializer)
{
  __int64 mOffset; // rax
  char *v4; // rbx
  const char *v5; // rax

  mOffset = this->mControllers.mOffset;
  if ( mOffset )
  {
    v4 = (char *)&this->mControllers + mOffset;
    if ( v4 )
    {
      v5 = (const char *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v4 + 32i64))(v4);
      serializer->vfptr->_PushObjectToSerialize(
        serializer,
        v4,
        1u,
        (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
        v5,
        PRIORITY_MEDIUM,
        0,
        0i64,
        -1u,
        0i64);
    }
  }
}

// File Line: 635
// RVA: 0x149F410
const char *dynamic_initializer_for__sBlendTreeControllerTrackFactoryList__()
{
  const char *result; // rax

  sBlendTreeControllerTrackFactoryList[0].mClassName = BlendTreeControllerTrack::sClassName;
  sBlendTreeControllerTrackFactoryList[1].mClassName = BlendTreeControllerTargetPositionTrack::sClassName;
  sBlendTreeControllerTrackFactoryList[2].mClassName = BlendTreeControllerTargetDistancTrack::sClassName;
  result = BlendTreeControllerGroup::sClassName;
  sBlendTreeControllerTrackFactoryList[3].mClassName = BlendTreeControllerGroup::sClassName;
  return result;
}

// File Line: 640
// RVA: 0x149F380
__int64 dynamic_initializer_for__gBlendTreeControlerFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gBlendTreeControlerFactory,
    sBlendTreeControllerTrackFactoryList,
    sBlendTreeControllerTrackFactoryListNum);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gBlendTreeControlerFactory__);
}

// File Line: 642
// RVA: 0x149F1B0
__int64 dynamic_initializer_for__BlendTreeControllerGroup::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BlendTreeControllerGroup", 0xFFFFFFFF);
  BlendTreeControllerGroup::sClassNameUID = result;
  return result;
}

// File Line: 672
// RVA: 0x149F350
__int64 dynamic_initializer_for__blendTreeControlSocketEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &blendTreeControlSocketEnum,
    gBlendTreeControlSocketStringList,
    6,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__blendTreeControlSocketEnum__);
}

// File Line: 679
// RVA: 0x149F210
__int64 dynamic_initializer_for__BlendTreeControllerTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BlendTreeControllerTrack", 0xFFFFFFFF);
  BlendTreeControllerTrack::sClassNameUID = result;
  return result;
}

// File Line: 704
// RVA: 0x149F1F0
__int64 dynamic_initializer_for__BlendTreeControllerTargetPositionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BlendTreeControllerTargetPositionTrack", 0xFFFFFFFF);
  BlendTreeControllerTargetPositionTrack::sClassNameUID = result;
  return result;
}

// File Line: 725
// RVA: 0x149F1D0
__int64 dynamic_initializer_for__BlendTreeControllerTargetDistancTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BlendTreeControllerTargetDistancTrack", 0xFFFFFFFF);
  BlendTreeControllerTargetDistancTrack::sClassNameUID = result;
  return result;
}

// File Line: 752
// RVA: 0x149F2B0
__int64 dynamic_initializer_for__PoseDriverDisableTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PoseDriverDisableTrack", 0xFFFFFFFF);
  PoseDriverDisableTrack::sClassNameUID = result;
  return result;
}

// File Line: 759
// RVA: 0x30F900
void __fastcall PoseDriverDisableTrack::PoseDriverDisableTrack(PoseDriverDisableTrack *this)
{
  ITrack::ITrack(this, PoseDriverDisableTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<PoseDriverDisableTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriverDisableTrack::`vftable;
}

// File Line: 770
// RVA: 0x149F0D0
__int64 dynamic_initializer_for__AnimationBankReferenceTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AnimationBankReferenceTrack", 0xFFFFFFFF);
  AnimationBankReferenceTrack::sClassNameUID = result;
  return result;
}

// File Line: 782
// RVA: 0x30EF80
void __fastcall AnimationBankReferenceTrack::AnimationBankReferenceTrack(AnimationBankReferenceTrack *this)
{
  ITrack::ITrack(this, AnimationBankReferenceTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AnimationBankReferenceTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationBankReferenceTrack::`vftable;
  this->m_AnimationBankName.mOffset = 1i64;
  BinString::Set(&this->m_AnimationBankName, &customCaption);
  this->m_eAnimationPriority.mValue = 10;
}

// File Line: 796
// RVA: 0x149F0B0
__int64 dynamic_initializer_for__AnimationBankPriorityTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AnimationBankPriorityTrack", 0xFFFFFFFF);
  AnimationBankPriorityTrack::sClassNameUID = result;
  return result;
}

// File Line: 807
// RVA: 0x30EF30
void __fastcall AnimationBankPriorityTrack::AnimationBankPriorityTrack(AnimationBankPriorityTrack *this)
{
  ITrack::ITrack(this, AnimationBankPriorityTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AnimationBankPriorityTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationBankPriorityTrack::`vftable;
  this->m_AnimationBankSymbolUC.mUID = gStaticSymbolUC_none.mUID;
  this->m_eAnimationPriority.mValue = 10;
}

// File Line: 822
// RVA: 0x149F2D0
__int64 dynamic_initializer_for__ResourceOpportunityTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ResourceOpportunityTrack", 0xFFFFFFFF);
  ResourceOpportunityTrack::sClassNameUID = result;
  return result;
}

// File Line: 841
// RVA: 0x30F940
void __fastcall ResourceOpportunityTrack::ResourceOpportunityTrack(ResourceOpportunityTrack *this)
{
  NodeRefTrack<ResourceOpportunityTask>::NodeRefTrack<ResourceOpportunityTask>(
    this,
    ResourceOpportunityTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&ResourceOpportunityTrack::`vftable;
  *(_QWORD *)&this->mPriority = 0x10000i64;
  this->mTruthDuration = 0.0;
  *(_WORD *)&this->mPlayerAnimationPriority.mValue = 1807;
  this->mConditions.mOffset = 0i64;
}

// File Line: 856
// RVA: 0x30FE70
void __fastcall ResourceOpportunityTrack::~ResourceOpportunityTrack(ResourceOpportunityTrack *this)
{
  __int64 mOffset; // rax
  __int64 v3; // rax
  char *v4; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&ResourceOpportunityTrack::`vftable;
  mOffset = this->mConditions.mOffset;
  if ( mOffset && (UFG::qOffset64<ConditionGroup *> *)((char *)&this->mConditions + mOffset) )
  {
    v3 = this->mConditions.mOffset;
    if ( v3 )
    {
      v4 = (char *)&this->mConditions + v3;
      if ( v4 )
        (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)v4 + 8i64))(v4, 1i64);
    }
    this->mConditions.mOffset = 0i64;
  }
  NodeRefTrack<ResourceOpportunityTask>::~NodeRefTrack<ResourceOpportunityTask>(this);
}

// File Line: 870
// RVA: 0x311EE0
Expression::IMemberMap *__fastcall ResourceOpportunityTrack::CreateClone(ResourceOpportunityTrack *this)
{
  char *v2; // rax
  char *v3; // rbx
  ActionNodeReference *v4; // rdi
  char *v5; // r14
  __int64 v6; // rax
  char *v7; // rsi
  signed __int64 v8; // rsi
  __int64 mOffset; // rax
  char *v10; // rcx
  __int64 v11; // rax
  __int64 *v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rax
  ActionNodeReference *v15; // rdx

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x58ui64, "ResourceOpportunityTrack::CreateClone", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    NodeRefTrack<ResourceOpportunityTask>::NodeRefTrack<ResourceOpportunityTask>(
      (NodeRefTrack<ResourceOpportunityTask> *)v2,
      ResourceOpportunityTrack::sClassNameUID);
    *(_QWORD *)v3 = &ResourceOpportunityTrack::`vftable;
    *((_QWORD *)v3 + 9) = 0x10000i64;
    v4 = 0i64;
    *((_DWORD *)v3 + 20) = 0;
    *((_WORD *)v3 + 42) = 1807;
    *((_QWORD *)v3 + 8) = 0i64;
  }
  else
  {
    v4 = 0i64;
    v3 = 0i64;
  }
  v5 = v3 + 56;
  v6 = *((_QWORD *)v3 + 7);
  v7 = &v3[v6 + 56];
  if ( !v6 )
    v7 = 0i64;
  ResourceOpportunityTrack::operator=((ResourceOpportunityTrack *)v3, this);
  if ( v7 )
    v8 = v7 - v5;
  else
    v8 = 0i64;
  *(_QWORD *)v5 = v8;
  mOffset = this->mConditions.mOffset;
  if ( mOffset )
  {
    v10 = (char *)&this->mConditions + mOffset;
    if ( v10 )
    {
      v11 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v10 + 16i64))(v10);
      v12 = (__int64 *)(v3 + 64);
      if ( v11 )
        v13 = v11 - (_QWORD)v12;
      else
        v13 = 0i64;
      *v12 = v13;
    }
  }
  v14 = this->mActionNodeReference.mOffset;
  if ( v14 )
    v15 = (ActionNodeReference *)((char *)&this->mActionNodeReference + v14);
  else
    v15 = 0i64;
  if ( *(_QWORD *)v5 )
    v4 = (ActionNodeReference *)&v5[*(_QWORD *)v5];
  ActionNodeReference::CopyFrom(v4, v15);
  return (Expression::IMemberMap *)v3;
}

// File Line: 917
// RVA: 0x312A70
void __fastcall ResourceOpportunityTrack::ResolveReferences(ResourceOpportunityTrack *this, ActionNode *parent)
{
  __int64 v4; // rax
  __int64 v5; // rdi
  __int64 v6; // rbx
  __int64 v7; // r14
  __int64 v8; // rcx

  _((AMD_HD3D *)this);
  this->vfptr[2].FindWithOldPath(this, (const char *)parent);
  ((void (__fastcall *)(ResourceOpportunityTrack *, ActionNode *))this->vfptr[1].GetResourceOwner)(this, parent);
  v4 = ((__int64 (__fastcall *)(ResourceOpportunityTrack *))this->vfptr[2].__vecDelDtor)(this);
  v5 = v4;
  if ( v4 )
  {
    v6 = 0i64;
    v7 = v4 + *(_QWORD *)(v4 + 40) + 40i64;
    if ( (*(_DWORD *)(v4 + 32) & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v8 = *(_QWORD *)(v7 + 8 * v6) + v7 + 8 * v6;
        (*(void (__fastcall **)(__int64, ActionNode *))(*(_QWORD *)v8 + 120i64))(v8, parent);
        v6 = (unsigned int)(v6 + 1);
      }
      while ( (unsigned int)v6 < (*(_DWORD *)(v5 + 32) & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 946
// RVA: 0x3124F0
ActionPath *__fastcall ResourceOpportunityTrack::GetActionPath(ResourceOpportunityTrack *this)
{
  __int64 mOffset; // rax
  char *v2; // rax

  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset )
  {
    v2 = (char *)&this->mActionNodeReference + mOffset;
    if ( v2 )
      return (ActionPath *)(v2 + 56);
  }
  if ( (_S2_10 & 1) == 0 )
  {
    _S2_10 |= 1u;
    sNULL_0.mPath.mCount = 0;
    sNULL_0.mPath.mData.mOffset = 0i64;
    atexit(ResourceOpportunityTrack::GetActionPath_::_5_::_dynamic_atexit_destructor_for__sNULL__);
  }
  return &sNULL_0;
}

// File Line: 957
// RVA: 0x312BA0
void __fastcall ResourceOpportunityTrack::Serialize(OpportunityTrack *this, IActionTreeSerializer *serializer)
{
  __int64 mOffset; // rax
  char *v4; // rbx
  const char *v5; // rax

  mOffset = this->mConditions.mOffset;
  if ( mOffset )
  {
    v4 = (char *)&this->mConditions + mOffset;
    if ( v4 )
    {
      v5 = (const char *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v4 + 32i64))(v4);
      serializer->vfptr->_PushObjectToSerialize(
        serializer,
        v4,
        1u,
        (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
        v5,
        PRIORITY_MEDIUM,
        0,
        0i64,
        -1u,
        0i64);
    }
  }
}

