// File Line: 41
// RVA: 0x149F320
__int64 dynamic_initializer_for__animEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&animEnum, gAnimationPlayModeStringList, 8, 0i64);
  return atexit(dynamic_atexit_destructor_for__animEnum__);
}

// File Line: 45
// RVA: 0x149F2F0
__int64 dynamic_initializer_for__animBlendEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&animBlendEnum, gAnimationBlendStringList, 2, 0i64);
  return atexit(dynamic_atexit_destructor_for__animBlendEnum__);
}

// File Line: 47
// RVA: 0x149F450
__int64 dynamic_initializer_for__symNone__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("none", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symNone, v0);
  return atexit(dynamic_atexit_destructor_for__symNone__);
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
  AnimationTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AnimationTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AnimationTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&AnimationTrack::`vftable;
  v1->mAnimation = 0i64;
  v1->mStartFrame = 0.0;
  v1->mEndFrame = -1.0;
  v1->mBlendInTime = 0.33333334;
  v1->mBlendOutTime = 0.33333334;
  *(_QWORD *)&v1->mPlayRate = 1065353216i64;
  v1->mWeightSetName.mUID = symNone.mUID;
  v1->mAnimationName.mUID = -1;
  *(_DWORD *)&v1->mAnimationPlayMode.mValue = 0x1000000;
  *(_WORD *)&v1->mPhaseIn = 256;
  v1->mResetMotionIntentionToFacing = 1;
  v1->mMaster = 1;
  v1->mAnimationName.mUID = symNone.mUID;
}

// File Line: 99
// RVA: 0x30FC20
void __fastcall AnimationTrack::~AnimationTrack(AnimationTrack *this)
{
  AnimationTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 130
// RVA: 0x312A00
void __fastcall AnimationTrack::ResolveReferences(AnimationTrack *this, ActionNode *pParent)
{
  AnimationTrack *v2; // rbx
  SkeletalAnimation *v3; // rax
  AnimationDataBase *v4; // rax
  unsigned int v5; // edx
  UFG::qBaseTreeRB *v6; // rax
  signed __int64 v7; // rax

  v2 = this;
  _((AMD_HD3D *)this);
  v3 = v2->mAnimation;
  if ( v3 )
  {
    --v3->mNumReferencesByAct;
    v2->mAnimation = 0i64;
  }
  v4 = AnimationDataBase::GetInstance();
  v5 = v2->mAnimationName.mUID;
  if ( v5 )
  {
    v6 = UFG::qBaseTreeRB::Get(&v4->mAnimations.mTree, v5);
    if ( v6 )
    {
      v7 = (signed __int64)&v6[-1].mNULL;
      if ( v7 )
      {
        ++*(_WORD *)(v7 + 196);
        if ( v2->mAnimationBlendMode.mValue == 1 )
          *(_BYTE *)(v7 + 198) = 1;
        v2->mAnimation = (SkeletalAnimation *)v7;
      }
    }
  }
}

// File Line: 216
// RVA: 0x3129C0
void __fastcall AnimationTrack::RemoveReferences(AnimationTrack *this)
{
  SkeletalAnimation *v1; // rax

  v1 = this->mAnimation;
  if ( v1 )
  {
    --v1->mNumReferencesByAct;
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
  AnimationRefPoseTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AnimationRefPoseTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AnimationRefPoseTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&AnimationRefPoseTrack::`vftable;
  v1->mStartFrame = 0.0;
  v1->mEndFrame = -1.0;
  v1->mBlendInTime = 0.33333334;
  *(_QWORD *)&v1->mBlendOutTime = 1051372203i64;
  v1->mWeightSetName.mUID = symNone.mUID;
  *(_WORD *)&v1->mPreserveMotion = 1;
  v1->mMaster = 0;
}

// File Line: 292
// RVA: 0x30FAE0
void __fastcall AnimationRefPoseTrack::~AnimationRefPoseTrack(AnimationRefPoseTrack *this)
{
  AnimationRefPoseTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationRefPoseTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  AnimationLockHighLODTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AnimationLockHighLODTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AnimationLockHighLODTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&AnimationLockHighLODTrack::`vftable;
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
  BlendTreeTrack *v1; // rbx
  char *v2; // rax
  UFG::qOffset64<BlendTreeControllerGroup *> *v3; // rcx
  signed __int64 v4; // rax
  UFG::qSymbolUC result; // [rsp+58h] [rbp+10h]

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, BlendTreeTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<BlendTreeTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&BlendTreeTrack::`vftable;
  v1->mBlendTreeName.mUID = -1;
  v1->mWeightSetName.mUID = symNone.mUID;
  v1->mBlendInTime = 0.33333334;
  *(_QWORD *)&v1->mBlendOutTime = 1051372203i64;
  v1->mEndFrame = -1.0;
  *(_WORD *)&v1->mAnimationPlayMode.mValue = 0;
  v1->mMaster = 1;
  v1->mBlendTreeName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "none")->mUID;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "BlendTreeControllerGroup", 0i64, 1u);
  *(_QWORD *)&result.mUID = v2;
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
  v3 = &v1->mControllers;
  if ( v2 )
    v4 = v2 - (char *)v3;
  else
    v4 = 0i64;
  v3->mOffset = v4;
  *(_WORD *)&v1->mPlayPriority = 0;
}

// File Line: 392
// RVA: 0x30F700
void __fastcall BlendTreeTrack::BlendTreeTrack(BlendTreeTrack *this, MemImageLoadFlag flag)
{
  BlendTreeTrack *v2; // rbx

  v2 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, flag);
  v2->vfptr = (Expression::IMemberMapVtbl *)&Track<BlendTreeTask>::`vftable;
  v2->vfptr = (Expression::IMemberMapVtbl *)&BlendTreeTrack::`vftable;
}

// File Line: 404
// RVA: 0x311D80
BlendTreeTrack *__fastcall BlendTreeTrack::CreateClone(BlendTreeTrack *this)
{
  BlendTreeTrack *v1; // rdi
  char *v2; // rax
  BlendTreeTrack *v3; // rax
  BlendTreeTrack *v4; // rbx
  char *v5; // rax
  signed __int64 v6; // rcx

  v1 = this;
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
  BlendTreeTrack::operator=(v4, v1);
  v5 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "BlendTreeControllerGroup", 0i64, 1u);
  if ( v5 )
  {
    *(_QWORD *)v5 = &Expression::IMemberMap::`vftable;
    *((_QWORD *)v5 + 1) = 0i64;
    *(_QWORD *)v5 = &BlendTreeControllerGroup::`vftable;
    *((_DWORD *)v5 + 4) = 0;
    *((_QWORD *)v5 + 3) = 0i64;
  }
  v6 = (signed __int64)&v4->mControllers;
  if ( v5 )
    v5 -= v6;
  *(_QWORD *)v6 = v5;
  BlendTreeTrack::CopyFrom(v4, v1);
  return v4;
}

// File Line: 443
// RVA: 0x311A90
void __fastcall BlendTreeTrack::CopyFrom(BlendTreeTrack *this, BlendTreeTrack *other_BlendTreeTrack)
{
  __int64 v2; // rax
  UFG::qOffset64<BlendTreeControllerGroup *> *v3; // r15
  BlendTreeTrack *v4; // r13
  char *v5; // rdx
  signed __int64 v6; // r12
  __int64 v7; // r14
  UFG::qOffset64<BlendTreeControllerGroup *> *v8; // rcx
  __int64 v9; // rbp
  __int64 v10; // rax
  BinPtrArray<ITrack,1,0> *v11; // rsi
  __int64 v12; // rdi
  unsigned int v13; // ebx
  unsigned int v14; // edx
  __int64 v15; // rax
  signed __int64 v16; // rcx
  _QWORD *v17; // rcx

  v2 = other_BlendTreeTrack->mControllers.mOffset;
  v3 = &other_BlendTreeTrack->mControllers;
  v4 = this;
  if ( v2 )
    v5 = (char *)v3 + v2;
  else
    v5 = 0i64;
  v6 = (signed __int64)&v5[*((_QWORD *)v5 + 3) + 24];
  v7 = 0i64;
  while ( 1 )
  {
    v8 = v3->mOffset ? (UFG::qOffset64<BlendTreeControllerGroup *> *)((char *)v3 + v3->mOffset) : 0i64;
    if ( (unsigned int)v7 >= (unsigned __int64)(v8[2].mOffset & 0x7FFFFFFF) )
      break;
    v9 = (*(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(v6 + 8 * v7) + v6 + 8 * v7) + 16i64))();
    v10 = v4->mControllers.mOffset;
    if ( v10 )
      v11 = (BinPtrArray<ITrack,1,0> *)((char *)&v4->mControllers + v10);
    else
      v11 = 0i64;
    v12 = (unsigned int)v11[1].mCount;
    LODWORD(v12) = v12 & 0x7FFFFFFF;
    v13 = v12 + 1;
    if ( (signed int)v12 + 1 > (unsigned int)v12 )
    {
      v14 = 1;
      if ( (_DWORD)v12 )
        v14 = 2 * v12;
      for ( ; v14 < v13; v14 *= 2 )
        ;
      if ( v14 - v13 > 0x10000 )
        v14 = v12 + 65537;
      BinPtrArray<Condition,1,0>::Reallocate(v11 + 1, v14, "BinPtrArray.Add");
    }
    v11[1].mCount &= 0x80000000;
    v11[1].mCount |= v13 & 0x7FFFFFFF;
    v15 = v11[1].mData.mOffset;
    if ( v15 )
      v16 = (signed __int64)&v11[1].mData + v15;
    else
      v16 = 0i64;
    v17 = (_QWORD *)(v16 + 8 * v12);
    if ( v9 )
    {
      v7 = (unsigned int)(v7 + 1);
      *v17 = v9 - (_QWORD)v17;
    }
    else
    {
      *v17 = 0i64;
      v7 = (unsigned int)(v7 + 1);
    }
  }
}

// File Line: 460
// RVA: 0x30FD70
void __fastcall BlendTreeTrack::~BlendTreeTrack(BlendTreeTrack *this)
{
  BlendTreeTrack *v1; // rbx
  __int64 v2; // rax
  char *v3; // rcx
  ExpressionParameterFloat *v4; // rcx
  char *v5; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&BlendTreeTrack::`vftable;
  v2 = this->mControllers.mOffset;
  if ( v2 )
  {
    v3 = (char *)&this->mControllers + v2;
    if ( v3 )
      (*(void (__fastcall **)(char *, signed __int64))(*(_QWORD *)v3 + 8i64))(v3, 1i64);
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v4 = &v1->mMasterRate;
  if ( !(~LOBYTE(v1->mMasterRate.text.mOffset) & 1) )
  {
    if ( v4->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v5 = (char *)v4 + (v4->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v5 != BinString::sEmptyString )
        operator delete[](v5);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 608
// RVA: 0x312B20
void __fastcall BlendTreeTrack::Serialize(BlendTreeTrack *this, IActionTreeSerializer *serializer)
{
  __int64 v2; // rax
  IActionTreeSerializer *v3; // rdi
  char *v4; // rbx
  __int64 v5; // rax
  signed int v6; // ST40_4
  unsigned int v7; // ST30_4
  signed int v8; // ST28_4

  v2 = this->mControllers.mOffset;
  v3 = serializer;
  if ( v2 )
  {
    v4 = (char *)&this->mControllers + v2;
    if ( v4 )
    {
      v5 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v4 + 32i64))(v4);
      v6 = -1;
      v7 = 0;
      v8 = 1;
      v3->vfptr->_PushObjectToSerialize(
        v3,
        v4,
        1u,
        (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
        (const char *)v5,
        (QUEUE_PRIORITY)v8,
        v7,
        0i64,
        v6,
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
  return atexit(dynamic_atexit_destructor_for__gBlendTreeControlerFactory__);
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
  return atexit(dynamic_atexit_destructor_for__blendTreeControlSocketEnum__);
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
  PoseDriverDisableTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, PoseDriverDisableTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<PoseDriverDisableTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&PoseDriverDisableTrack::`vftable;
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
  AnimationBankReferenceTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AnimationBankReferenceTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AnimationBankReferenceTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&AnimationBankReferenceTrack::`vftable;
  v1->m_AnimationBankName.mOffset = 1i64;
  BinString::Set(&v1->m_AnimationBankName, &customWorldMapCaption);
  v1->m_eAnimationPriority.mValue = 10;
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
  AnimationBankPriorityTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AnimationBankPriorityTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AnimationBankPriorityTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&AnimationBankPriorityTrack::`vftable;
  v1->m_AnimationBankSymbolUC.mUID = gStaticSymbolUC_none.mUID;
  v1->m_eAnimationPriority.mValue = 10;
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
  ResourceOpportunityTrack *v1; // rbx

  v1 = this;
  NodeRefTrack<ResourceOpportunityTask>::NodeRefTrack<ResourceOpportunityTask>(
    (NodeRefTrack<ResourceOpportunityTask> *)&this->vfptr,
    ResourceOpportunityTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ResourceOpportunityTrack::`vftable;
  *(_QWORD *)&v1->mPriority = 0x10000i64;
  v1->mTruthDuration = 0.0;
  *(_WORD *)&v1->mPlayerAnimationPriority.mValue = 1807;
  v1->mConditions.mOffset = 0i64;
}

// File Line: 856
// RVA: 0x30FE70
void __fastcall ResourceOpportunityTrack::~ResourceOpportunityTrack(ResourceOpportunityTrack *this)
{
  ResourceOpportunityTrack *v1; // rbx
  __int64 v2; // rax
  __int64 v3; // rax
  char *v4; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ResourceOpportunityTrack::`vftable;
  v2 = this->mConditions.mOffset;
  if ( v2 && (UFG::qOffset64<ConditionGroup *> *)((char *)&this->mConditions + v2) )
  {
    v3 = this->mConditions.mOffset;
    if ( v3 )
    {
      v4 = (char *)&this->mConditions + v3;
      if ( v4 )
        (*(void (__fastcall **)(char *, signed __int64))(*(_QWORD *)v4 + 8i64))(v4, 1i64);
    }
    v1->mConditions.mOffset = 0i64;
  }
  NodeRefTrack<ResourceOpportunityTask>::~NodeRefTrack<ResourceOpportunityTask>((NodeRefTrack<ResourceOpportunityTask> *)&v1->vfptr);
}

// File Line: 870
// RVA: 0x311EE0
Expression::IMemberMap *__fastcall ResourceOpportunityTrack::CreateClone(ResourceOpportunityTrack *this)
{
  ResourceOpportunityTrack *v1; // rbp
  char *v2; // rax
  char *v3; // rbx
  ActionNodeReference *v4; // rdi
  signed __int64 *v5; // r14
  __int64 v6; // rax
  signed __int64 v7; // rsi
  signed __int64 v8; // rsi
  __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // rax
  __int64 *v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rax
  ActionNodeReference *v15; // rdx

  v1 = this;
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
  v5 = (signed __int64 *)(v3 + 56);
  v6 = *((_QWORD *)v3 + 7);
  v7 = (signed __int64)&v3[v6 + 56];
  if ( !v6 )
    v7 = 0i64;
  ResourceOpportunityTrack::operator=((ResourceOpportunityTrack *)v3, v1);
  if ( v7 )
    v8 = v7 - (_QWORD)v5;
  else
    v8 = 0i64;
  *v5 = v8;
  v9 = v1->mConditions.mOffset;
  if ( v9 )
  {
    v10 = (signed __int64)&v1->mConditions + v9;
    if ( v10 )
    {
      v11 = (*(__int64 (**)(void))(*(_QWORD *)v10 + 16i64))();
      v12 = (__int64 *)(v3 + 64);
      if ( v11 )
        v13 = v11 - (_QWORD)v12;
      else
        v13 = 0i64;
      *v12 = v13;
    }
  }
  v14 = v1->mActionNodeReference.mOffset;
  if ( v14 )
    v15 = (ActionNodeReference *)((char *)&v1->mActionNodeReference + v14);
  else
    v15 = 0i64;
  if ( *v5 )
    v4 = (ActionNodeReference *)((char *)v5 + *v5);
  ActionNodeReference::CopyFrom(v4, v15);
  return (Expression::IMemberMap *)v3;
}

// File Line: 917
// RVA: 0x312A70
void __fastcall ResourceOpportunityTrack::ResolveReferences(ResourceOpportunityTrack *this, ActionNode *parent)
{
  ActionNode *v2; // rsi
  ResourceOpportunityTrack *v3; // rbx
  __int64 v4; // rax
  __int64 v5; // rdi
  __int64 v6; // rbx
  signed __int64 v7; // r14
  signed __int64 v8; // rcx

  v2 = parent;
  v3 = this;
  _((AMD_HD3D *)this);
  v3->vfptr[2].FindWithOldPath((Expression::IMemberMap *)&v3->vfptr, (const char *)v2);
  ((void (__fastcall *)(ResourceOpportunityTrack *, ActionNode *))v3->vfptr[1].GetResourceOwner)(v3, v2);
  v4 = ((__int64 (__fastcall *)(ResourceOpportunityTrack *))v3->vfptr[2].__vecDelDtor)(v3);
  v5 = v4;
  if ( v4 )
  {
    v6 = 0i64;
    v7 = v4 + *(_QWORD *)(v4 + 40) + 40i64;
    if ( *(_DWORD *)(v4 + 32) & 0x7FFFFFFF )
    {
      do
      {
        v8 = *(_QWORD *)(v7 + 8 * v6) + v7 + 8 * v6;
        (*(void (__fastcall **)(signed __int64, ActionNode *))(*(_QWORD *)v8 + 120i64))(v8, v2);
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
  __int64 v1; // rax
  char *v2; // rax

  v1 = this->mActionNodeReference.mOffset;
  if ( v1 )
  {
    v2 = (char *)&this->mActionNodeReference + v1;
    if ( v2 )
      return (ActionPath *)(v2 + 56);
  }
  if ( !(_S2_10 & 1) )
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
  __int64 v2; // rax
  IActionTreeSerializer *v3; // rdi
  char *v4; // rbx
  __int64 v5; // rax
  signed int v6; // ST40_4
  unsigned int v7; // ST30_4
  signed int v8; // ST28_4

  v2 = this->mConditions.mOffset;
  v3 = serializer;
  if ( v2 )
  {
    v4 = (char *)&this->mConditions + v2;
    if ( v4 )
    {
      v5 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v4 + 32i64))(v4);
      v6 = -1;
      v7 = 0;
      v8 = 1;
      v3->vfptr->_PushObjectToSerialize(
        v3,
        v4,
        1u,
        (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
        (const char *)v5,
        (QUEUE_PRIORITY)v8,
        v7,
        0i64,
        v6,
        0i64);
    }
  }
}

