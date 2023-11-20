// File Line: 36
// RVA: 0x39F410
void __fastcall Attachment::~Attachment(Attachment *this)
{
  Attachment *v1; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<Creature,Creature> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<Attachment,Attachment> *v17; // rdx
  UFG::qNode<Attachment,Attachment> *v18; // rcx
  UFG::qNode<Attachment,Attachment> *v19; // rax

  v1 = this;
  this->vfptr = (AttachmentVtbl *)&Attachment::`vftable';
  v2 = &this->mAttachedSimObject;
  if ( this->mAttachedSimObject.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = &v1->mRootCreature;
  if ( v1->mRootCreature.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mRootCreature.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mRootCreature.mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v1->mRootCreature.mPrev;
  }
  v1->mRootCreature.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mRootCreature.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mRootCreature.mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v1->mRootCreature.mPrev;
  v12 = &v1->mRootSimObject;
  if ( v1->mRootSimObject.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->mRootSimObject.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->mRootSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mRootSimObject.mPrev;
  }
  v1->mRootSimObject.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->mRootSimObject.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->mRootSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mRootSimObject.mPrev;
  v17 = (UFG::qNode<Attachment,Attachment> *)&v1->mPrev;
  v18 = v1->mPrev;
  v19 = v1->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v17->mPrev = v17;
  v17->mNext = v17;
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
  float v2; // xmm3_4
  float v3; // xmm0_4

  v2 = this->mBlendRate;
  if ( v2 != 0.0 )
  {
    v3 = (float)(v2 * timeDelta) + this->mBlendWeight;
    this->mBlendWeight = v3;
    if ( v2 <= 0.0 )
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
void __fastcall AttachmentCreatureToTransformNode::~AttachmentCreatureToTransformNode(AttachmentCreatureToTransformNode *this)
{
  AttachmentCreatureToTransformNode *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax

  v1 = this;
  this->vfptr = (AttachmentVtbl *)&AttachmentCreatureToTransformNode::`vftable';
  v2 = &this->mAttachedCharacterAnimationComponent;
  if ( this->mAttachedCharacterAnimationComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = &v1->mTransformNodeComponentRoot;
  if ( v1->mTransformNodeComponentRoot.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mTransformNodeComponentRoot.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mTransformNodeComponentRoot.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mTransformNodeComponentRoot.mPrev;
  }
  v1->mTransformNodeComponentRoot.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mTransformNodeComponentRoot.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mTransformNodeComponentRoot.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mTransformNodeComponentRoot.mPrev;
  Attachment::~Attachment((Attachment *)&v1->vfptr);
}

// File Line: 140
// RVA: 0x39F510
void __fastcall AttachmentCreature::~AttachmentCreature(AttachmentCreature *this)
{
  AttachmentCreature *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this;
  this->vfptr = (AttachmentVtbl *)&AttachmentCreature::`vftable';
  v2 = &this->mAttachedCharacterAnimationComponent;
  if ( this->mAttachedCharacterAnimationComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  Attachment::~Attachment((Attachment *)&v1->vfptr);
}

// File Line: 181
// RVA: 0x3A8390
TwoLinkIKsolver *__fastcall AttachmentCreatureEffectorToCreatureReverse::GetEffector(AttachmentCreatureEffectorToCreatureReverse *this)
{
  return this->mEffector;
}

// File Line: 182
// RVA: 0x3A83A0
__int64 __fastcall AttachmentCreatureEffectorToCreatureReverse::GetEffectorFollowJoint(AttachmentCreatureEffectorToCreatureReverse *this)
{
  return (unsigned int)this->mFollowJoint;
}

// File Line: 203
// RVA: 0x39DA90
void __fastcall AttachmentCreatureToHandle::AttachmentCreatureToHandle(AttachmentCreatureToHandle *this)
{
  UFG::qNode<Attachment,Attachment> *v1; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rax
  UFG::qSafePointer<Creature,Creature> *v3; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v5; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *v7; // rax

  v1 = (UFG::qNode<Attachment,Attachment> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (AttachmentVtbl *)&Attachment::`vftable';
  *(_WORD *)&this->mPositionOnly = 0;
  this->mUseRubberBand = 0;
  this->attachedJoint = 0;
  v2 = &this->mRootSimObject;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mRootSimObject.m_pPointer = 0i64;
  v3 = &this->mRootCreature;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->mRootCreature.m_pPointer = 0i64;
  v4 = &this->mAttachedSimObject;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->mAttachedSimObject.m_pPointer = 0i64;
  this->vfptr = (AttachmentVtbl *)&AttachmentCreatureToHandle::`vftable';
  v5 = &this->mParkourHandle;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->mParkourHandle.m_pPointer = 0i64;
  v6 = &this->mParkourSimObject;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  this->mParkourSimObject.m_pPointer = 0i64;
  v7 = &this->mAttachedCharacterAnimationComponent;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  this->mAttachedCharacterAnimationComponent.m_pPointer = 0i64;
  this->mUpdatedPose = 0;
}

