// File Line: 47
// RVA: 0x9C260
void __fastcall UFG::DestructionEvent::~DestructionEvent(UFG::DestructionEvent *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *p_mBreakingBody; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_mCollidingComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::Event,UFG::Event> *v12; // rcx
  UFG::qNode<UFG::Event,UFG::Event> *v13; // rax

  this->vfptr = (UFG::EventVtbl *)&UFG::DestructionEvent::`vftable;
  UFG::qReflectHandleBase::~qReflectHandleBase(&this->objectProperty);
  p_mBreakingBody = &this->mBreakingBody;
  if ( this->mBreakingBody.m_pPointer )
  {
    mPrev = p_mBreakingBody->mPrev;
    mNext = this->mBreakingBody.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mBreakingBody->mPrev = p_mBreakingBody;
    this->mBreakingBody.mNext = &this->mBreakingBody;
  }
  this->mBreakingBody.m_pPointer = 0i64;
  v5 = p_mBreakingBody->mPrev;
  v6 = this->mBreakingBody.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mBreakingBody->mPrev = p_mBreakingBody;
  this->mBreakingBody.mNext = &this->mBreakingBody;
  p_mCollidingComponent = &this->mCollidingComponent;
  if ( this->mCollidingComponent.m_pPointer )
  {
    v8 = p_mCollidingComponent->mPrev;
    v9 = this->mCollidingComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mCollidingComponent->mPrev = p_mCollidingComponent;
    this->mCollidingComponent.mNext = &this->mCollidingComponent;
  }
  this->mCollidingComponent.m_pPointer = 0i64;
  v10 = p_mCollidingComponent->mPrev;
  v11 = this->mCollidingComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mCollidingComponent->mPrev = p_mCollidingComponent;
  this->mCollidingComponent.mNext = &this->mCollidingComponent;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
}

