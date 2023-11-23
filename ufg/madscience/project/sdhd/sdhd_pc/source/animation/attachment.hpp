// File Line: 36
// RVA: 0x39F410
void __fastcall Attachment::~Attachment(Attachment *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mAttachedSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<Creature,Creature> *p_mRootCreature; // rdx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mRootSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<Attachment,Attachment> *v17; // rcx
  UFG::qNode<Attachment,Attachment> *v18; // rax

  this->vfptr = (AttachmentVtbl *)&Attachment::`vftable;
  p_mAttachedSimObject = &this->mAttachedSimObject;
  if ( this->mAttachedSimObject.m_pPointer )
  {
    mPrev = p_mAttachedSimObject->mPrev;
    mNext = p_mAttachedSimObject->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAttachedSimObject->mPrev = p_mAttachedSimObject;
    p_mAttachedSimObject->mNext = p_mAttachedSimObject;
  }
  p_mAttachedSimObject->m_pPointer = 0i64;
  v5 = p_mAttachedSimObject->mPrev;
  v6 = p_mAttachedSimObject->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mAttachedSimObject->mPrev = p_mAttachedSimObject;
  p_mAttachedSimObject->mNext = p_mAttachedSimObject;
  p_mRootCreature = &this->mRootCreature;
  if ( this->mRootCreature.m_pPointer )
  {
    v8 = p_mRootCreature->mPrev;
    v9 = this->mRootCreature.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mRootCreature->mPrev = p_mRootCreature;
    this->mRootCreature.mNext = &this->mRootCreature;
  }
  this->mRootCreature.m_pPointer = 0i64;
  v10 = p_mRootCreature->mPrev;
  v11 = this->mRootCreature.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mRootCreature->mPrev = p_mRootCreature;
  this->mRootCreature.mNext = &this->mRootCreature;
  p_mRootSimObject = &this->mRootSimObject;
  if ( this->mRootSimObject.m_pPointer )
  {
    v13 = p_mRootSimObject->mPrev;
    v14 = this->mRootSimObject.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_mRootSimObject->mPrev = p_mRootSimObject;
    this->mRootSimObject.mNext = &this->mRootSimObject;
  }
  this->mRootSimObject.m_pPointer = 0i64;
  v15 = p_mRootSimObject->mPrev;
  v16 = this->mRootSimObject.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_mRootSimObject->mPrev = p_mRootSimObject;
  this->mRootSimObject.mNext = &this->mRootSimObject;
  v17 = this->mPrev;
  v18 = this->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->mPrev = &this->UFG::qNode<Attachment,Attachment>;
  this->mNext = &this->UFG::qNode<Attachment,Attachment>;
}

// File Line: 75
// RVA: 0x3AEF00
void __fastcall Attachment::SetBlendIn(Attachment *this, float blendInTime)
{
  if ( blendInTime > 0.0 )
  {
    this->mBlendWeight = 0.0;
    this->mBlendRate = 1.0 / blendInTime;
  }
  else
  {
    this->mBlendRate = 1.0;
    this->mBlendWeight = 1.0;
  }
}

// File Line: 109
// RVA: 0x3B0AF0
bool __fastcall Attachment::Update(Attachment *this, float timeDelta)
{
  float mBlendRate; // xmm3_4
  float v3; // xmm0_4

  mBlendRate = this->mBlendRate;
  if ( mBlendRate != 0.0 )
  {
    v3 = (float)(mBlendRate * timeDelta) + this->mBlendWeight;
    this->mBlendWeight = v3;
    if ( mBlendRate <= 0.0 )
    {
      if ( v3 <= 0.0 )
        this->mBlendWeight = 0.0;
    }
    else if ( v3 > 1.0 )
    {
      this->mBlendWeight = 1.0;
      return this->mBlendWeight > 0.0;
    }
  }
  return this->mBlendWeight > 0.0;
}

// File Line: 124
// RVA: 0x51AD10
void __fastcall AttachmentCreatureToTransformNode::~AttachmentCreatureToTransformNode(
        AttachmentCreatureToTransformNode *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *p_mAttachedCharacterAnimationComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mTransformNodeComponentRoot; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax

  this->vfptr = (AttachmentVtbl *)&AttachmentCreatureToTransformNode::`vftable;
  p_mAttachedCharacterAnimationComponent = &this->mAttachedCharacterAnimationComponent;
  if ( this->mAttachedCharacterAnimationComponent.m_pPointer )
  {
    mPrev = p_mAttachedCharacterAnimationComponent->mPrev;
    mNext = p_mAttachedCharacterAnimationComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAttachedCharacterAnimationComponent->mPrev = p_mAttachedCharacterAnimationComponent;
    p_mAttachedCharacterAnimationComponent->mNext = p_mAttachedCharacterAnimationComponent;
  }
  p_mAttachedCharacterAnimationComponent->m_pPointer = 0i64;
  v5 = p_mAttachedCharacterAnimationComponent->mPrev;
  v6 = p_mAttachedCharacterAnimationComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mAttachedCharacterAnimationComponent->mPrev = p_mAttachedCharacterAnimationComponent;
  p_mAttachedCharacterAnimationComponent->mNext = p_mAttachedCharacterAnimationComponent;
  p_mTransformNodeComponentRoot = &this->mTransformNodeComponentRoot;
  if ( this->mTransformNodeComponentRoot.m_pPointer )
  {
    v8 = p_mTransformNodeComponentRoot->mPrev;
    v9 = this->mTransformNodeComponentRoot.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mTransformNodeComponentRoot->mPrev = p_mTransformNodeComponentRoot;
    this->mTransformNodeComponentRoot.mNext = &this->mTransformNodeComponentRoot;
  }
  this->mTransformNodeComponentRoot.m_pPointer = 0i64;
  v10 = p_mTransformNodeComponentRoot->mPrev;
  v11 = this->mTransformNodeComponentRoot.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mTransformNodeComponentRoot->mPrev = p_mTransformNodeComponentRoot;
  this->mTransformNodeComponentRoot.mNext = &this->mTransformNodeComponentRoot;
  Attachment::~Attachment(this);
}

// File Line: 140
// RVA: 0x39F510
void __fastcall AttachmentCreature::~AttachmentCreature(AttachmentCreature *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *p_mAttachedCharacterAnimationComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  this->vfptr = (AttachmentVtbl *)&AttachmentCreature::`vftable;
  p_mAttachedCharacterAnimationComponent = &this->mAttachedCharacterAnimationComponent;
  if ( this->mAttachedCharacterAnimationComponent.m_pPointer )
  {
    mPrev = p_mAttachedCharacterAnimationComponent->mPrev;
    mNext = p_mAttachedCharacterAnimationComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAttachedCharacterAnimationComponent->mPrev = p_mAttachedCharacterAnimationComponent;
    p_mAttachedCharacterAnimationComponent->mNext = p_mAttachedCharacterAnimationComponent;
  }
  p_mAttachedCharacterAnimationComponent->m_pPointer = 0i64;
  v5 = p_mAttachedCharacterAnimationComponent->mPrev;
  v6 = p_mAttachedCharacterAnimationComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mAttachedCharacterAnimationComponent->mPrev = p_mAttachedCharacterAnimationComponent;
  p_mAttachedCharacterAnimationComponent->mNext = p_mAttachedCharacterAnimationComponent;
  Attachment::~Attachment(this);
}

// File Line: 181
// RVA: 0x3A8390
TwoLinkIKsolver *__fastcall AttachmentCreatureEffectorToCreatureReverse::GetEffector(
        AttachmentCreatureEffectorToCreatureReverse *this)
{
  return this->mEffector;
}

// File Line: 182
// RVA: 0x3A83A0
__int64 __fastcall AttachmentCreatureEffectorToCreatureReverse::GetEffectorFollowJoint(
        AttachmentCreatureEffectorToCreatureReverse *this)
{
  return (unsigned int)this->mFollowJoint;
}

// File Line: 203
// RVA: 0x39DA90
void __fastcall AttachmentCreatureToHandle::AttachmentCreatureToHandle(AttachmentCreatureToHandle *this)
{
  this->mPrev = &this->UFG::qNode<Attachment,Attachment>;
  this->mNext = &this->UFG::qNode<Attachment,Attachment>;
  this->vfptr = (AttachmentVtbl *)&Attachment::`vftable;
  *(_WORD *)&this->mPositionOnly = 0;
  this->mUseRubberBand = 0;
  this->attachedJoint = 0;
  this->mRootSimObject.Attachment::mPrev = &this->mRootSimObject;
  this->mRootSimObject.mNext = &this->mRootSimObject;
  this->mRootSimObject.m_pPointer = 0i64;
  this->mRootCreature.Attachment::mPrev = &this->mRootCreature;
  this->mRootCreature.mNext = &this->mRootCreature;
  this->mRootCreature.m_pPointer = 0i64;
  this->mAttachedSimObject.Attachment::mPrev = &this->mAttachedSimObject;
  this->mAttachedSimObject.mNext = &this->mAttachedSimObject;
  this->mAttachedSimObject.m_pPointer = 0i64;
  this->vfptr = (AttachmentVtbl *)&AttachmentCreatureToHandle::`vftable;
  this->mParkourHandle.mPrev = &this->mParkourHandle;
  this->mParkourHandle.mNext = &this->mParkourHandle;
  this->mParkourHandle.m_pPointer = 0i64;
  this->mParkourSimObject.mPrev = &this->mParkourSimObject;
  this->mParkourSimObject.mNext = &this->mParkourSimObject;
  this->mParkourSimObject.m_pPointer = 0i64;
  this->mAttachedCharacterAnimationComponent.mPrev = &this->mAttachedCharacterAnimationComponent;
  this->mAttachedCharacterAnimationComponent.mNext = &this->mAttachedCharacterAnimationComponent;
  this->mAttachedCharacterAnimationComponent.m_pPointer = 0i64;
  this->mUpdatedPose = 0;
}

