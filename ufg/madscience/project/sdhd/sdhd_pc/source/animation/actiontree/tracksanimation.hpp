// File Line: 54
// RVA: 0x3152C0
void __fastcall AnimationTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x68ui64, "MemberMap::AnimationTrack", 0i64, 1u);
  if ( v0 )
    AnimationTrack::AnimationTrack((AnimationTrack *)v0);
}

// File Line: 144
// RVA: 0x2C0840
const char *__fastcall AnimationRefPoseTrack::GetClassname(AnimationRefPoseTrack *this)
{
  return AnimationRefPoseTrack::sClassName;
}

// File Line: 198
// RVA: 0x299B40
void __fastcall AnimationLockHighLODTrack::~AnimationLockHighLODTrack(AnimationLockHighLODTrack *this)
{
  AnimationLockHighLODTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationLockHighLODTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
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
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 200
// RVA: 0x2BDB90
__int64 __fastcall AnimationLockHighLODTrack::GetClassNameUID(AnimationLockHighLODTrack *this)
{
  return AnimationLockHighLODTrack::sClassNameUID;
}

// File Line: 212
// RVA: 0x30FEE0
void __fastcall UFG::GetInFormationComponent::operator delete(void *ptr, const char *name)
{
  UFG::qMemoryPool2::Free(&gActionTreeMemoryPool, ptr, 0i64);
}

// File Line: 217
// RVA: 0x29BF40
void __fastcall IBlendTreeControllerTrack::~IBlendTreeControllerTrack(IBlendTreeControllerTrack *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&IBlendTreeControllerTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 246
// RVA: 0x2BDD40
__int64 __fastcall BlendTreeControllerGroup::GetClassNameUID(BlendTreeControllerGroup *this)
{
  return BlendTreeControllerGroup::sClassNameUID;
}

// File Line: 314
// RVA: 0x30ED10
void __fastcall BlendTreeControllerTrackBase<BlendTreeControllerTargetDistancTask>::BlendTreeControllerTrackBase<BlendTreeControllerTargetDistancTask>(BlendTreeControllerTrackBase<BlendTreeControllerTargetDistancTask> *this)
{
  UFG::qSymbolUC result; // [rsp+48h] [rbp+10h]

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&IBlendTreeControllerTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&BlendTreeControllerTrackBase<BlendTreeControllerTargetDistancTask>::`vftable';
  this->mBlendTreeName.mUID = -1;
  this->mBlendTreeControlSocket.mValue = 0;
  this->mBlendTreeName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "none")->mUID;
}

// File Line: 319
// RVA: 0x298E20
void __fastcall BlendTreeControllerTrackBase<BlendTreeControllerTargetDistancTask>::~BlendTreeControllerTrackBase<BlendTreeControllerTargetDistancTask>(BlendTreeControllerTrackBase<BlendTreeControllerTargetDistancTask> *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&BlendTreeControllerTrackBase<BlendTreeControllerTargetDistancTask>::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&IBlendTreeControllerTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 350
// RVA: 0x2AFE70
void __fastcall BlendTreeControllerTrackBase<BlendTreeControllerTargetDistancTask>::CreateTask(BlendTreeControllerTrackBase<BlendTreeControllerTargetDistancTask> *this, const char *debugName)
{
  BlendTreeControllerTrackBase<BlendTreeControllerTargetDistancTask> *v2; // rbx
  BlendTreeControllerTargetDistancTask *v3; // rax

  v2 = this;
  v3 = (BlendTreeControllerTargetDistancTask *)UFG::qMemoryPool2::Allocate(
                                                 &gActionTreeMemoryPool,
                                                 0x48ui64,
                                                 debugName,
                                                 0i64,
                                                 1u);
  if ( v3 )
    BlendTreeControllerTargetDistancTask::BlendTreeControllerTargetDistancTask(v3);
  v3->m_Track = (IBlendTreeControllerTrack *)&v2->vfptr;
}

// File Line: 396
// RVA: 0x3106A0
void __usercall BlendTreeControllerTrackBase<BlendTreeControllerTask>::ApplySignal(BlendTreeControllerTrackBase<BlendTreeControllerTask> *this@<rcx>, PoseNode *playingNode@<rdx>, float signal@<xmm2>, __int64 forceInput@<r9>, __int64 a5@<r8>)
{
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  Expression::IMemberMapVtbl *v9; // rax
  void **v10; // [rsp+20h] [rbp-28h]
  char v11; // [rsp+28h] [rbp-20h]
  float v12; // [rsp+30h] [rbp-18h]

  if ( playingNode )
  {
    v5 = (unsigned __int8)this->mBlendTreeControlSocket.mValue - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        v7 = v6 - 1;
        if ( v7 )
        {
          v8 = v7 - 1;
          if ( v8 )
          {
            if ( v8 == 1 )
              ((void (__fastcall *)(PoseNode *, PoseNode *, __int64, __int64))playingNode->vfptr[3].FindWithOldPath)(
                playingNode,
                playingNode,
                a5,
                forceInput);
          }
          else
          {
            ((void (__fastcall *)(PoseNode *, PoseNode *, __int64, __int64))playingNode->vfptr[3].ResolveReferences)(
              playingNode,
              playingNode,
              a5,
              forceInput);
          }
        }
        else
        {
          v12 = signal;
          v10 = &BlendNode_SetBlendWeight::`vftable';
          v9 = playingNode->vfptr;
          v11 = 0;
          ((void (__fastcall *)(PoseNode *, void ***, __int64, __int64, void **, _QWORD, _QWORD))v9[1].FindWithOldPath)(
            playingNode,
            &v10,
            a5,
            forceInput,
            &BlendNode_SetBlendWeight::`vftable',
            *(_QWORD *)&v11,
            *(_QWORD *)&v12);
        }
      }
      else
      {
        ((void (__fastcall *)(PoseNode *, PoseNode *, _QWORD))playingNode->vfptr[3].GetClassname)(
          playingNode,
          playingNode,
          (unsigned __int8)forceInput);
      }
    }
    else
    {
      ((void (__fastcall *)(PoseNode *, PoseNode *, __int64, __int64))playingNode->vfptr[3].GetResourcePath)(
        playingNode,
        playingNode,
        a5,
        forceInput);
    }
  }
}

// File Line: 449
// RVA: 0x2BDD70
__int64 __fastcall BlendTreeControllerTrack::GetClassNameUID(BlendTreeControllerTrack *this)
{
  return BlendTreeControllerTrack::sClassNameUID;
}

// File Line: 474
// RVA: 0x2C0A00
const char *__fastcall BlendTreeControllerTargetPositionTrack::GetClassname(BlendTreeControllerTargetPositionTrack *this)
{
  return BlendTreeControllerTargetPositionTrack::sClassName;
}

// File Line: 493
// RVA: 0x311C30
BlendTreeControllerTargetDistancTrack *__fastcall BlendTreeControllerTargetDistancTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::BlendTreeControllerTargetDistancTrack",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  BlendTreeControllerTrackBase<BlendTreeControllerTargetDistancTask>::BlendTreeControllerTrackBase<BlendTreeControllerTargetDistancTask>((BlendTreeControllerTrackBase<BlendTreeControllerTargetDistancTask> *)v0);
  *(_QWORD *)v1 = &BlendTreeControllerTargetDistancTrack::`vftable';
  *((_QWORD *)v1 + 3) = 0i64;
  *((_DWORD *)v1 + 8) = 0x40000000;
  return (BlendTreeControllerTargetDistancTrack *)v1;
}

// File Line: 520
// RVA: 0x312550
__int64 __fastcall BlendTreeTrack::GetClassNameUID(BlendTreeTrack *this)
{
  return BlendTreeTrack::sClassNameUID;
}

// File Line: 562
// RVA: 0x312C70
void __fastcall ActionNodeImplementation::SetConditionGroup(ActionNodeImplementation *this, ConditionGroup *conditions)
{
  UFG::qOffset64<ConditionGroup *> *v2; // rcx

  v2 = &this->mConditions;
  if ( conditions )
    v2->mOffset = (char *)conditions - (char *)v2;
  else
    v2->mOffset = 0i64;
}

// File Line: 627
// RVA: 0x29D4B0
void __fastcall PoseDriverDisableTrack::~PoseDriverDisableTrack(PoseDriverDisableTrack *this)
{
  PoseDriverDisableTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriverDisableTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
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
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 629
// RVA: 0x31EFF0
void __fastcall PoseDriverDisableTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::PoseDriverDisableTrack", 0i64, 1u);
  if ( v0 )
    PoseDriverDisableTrack::PoseDriverDisableTrack((PoseDriverDisableTrack *)v0);
}

// File Line: 647
// RVA: 0x299A10
void __fastcall AnimationBankReferenceTrack::~AnimationBankReferenceTrack(AnimationBankReferenceTrack *this)
{
  AnimationBankReferenceTrack *v1; // rbx
  char *v2; // rcx
  ExpressionParameterFloat *v3; // rcx
  char *v4; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationBankReferenceTrack::`vftable';
  if ( !(~LOBYTE(this->m_AnimationBankName.mOffset) & 1) )
  {
    if ( this->m_AnimationBankName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v2 = (char *)&this->m_AnimationBankName + (this->m_AnimationBankName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v2 != BinString::sEmptyString )
        operator delete[](v2);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v3 = &v1->mMasterRate;
  if ( !(~LOBYTE(v1->mMasterRate.text.mOffset) & 1) )
  {
    if ( v3->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v4 = (char *)v3 + (v3->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v4 != BinString::sEmptyString )
        operator delete[](v4);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 649
// RVA: 0x2C0800
const char *__fastcall AnimationBankReferenceTrack::GetClassname(AnimationBankReferenceTrack *this)
{
  return AnimationBankReferenceTrack::sClassName;
}

// File Line: 673
// RVA: 0x299910
void __fastcall AnimationBankPriorityTrack::~AnimationBankPriorityTrack(AnimationBankPriorityTrack *this)
{
  AnimationBankPriorityTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationBankPriorityTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
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
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 675
// RVA: 0x2BDB50
__int64 __fastcall AnimationBankPriorityTrack::GetClassNameUID(AnimationBankPriorityTrack *this)
{
  return AnimationBankPriorityTrack::sClassNameUID;
}

// File Line: 701
// RVA: 0x31FDE0
void __fastcall ResourceOpportunityTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x58ui64, "MemberMap::ResourceOpportunityTrack", 0i64, 1u);
  if ( v0 )
    ResourceOpportunityTrack::ResourceOpportunityTrack((ResourceOpportunityTrack *)v0);
}

