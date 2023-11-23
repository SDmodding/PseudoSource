// File Line: 26
// RVA: 0x9C540
void __fastcall UFG::HavokUserData::~HavokUserData(UFG::HavokUserData *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_simComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  p_simComponent = &this->simComponent;
  if ( this->simComponent.m_pPointer )
  {
    mPrev = p_simComponent->mPrev;
    mNext = p_simComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_simComponent->mPrev = p_simComponent;
    p_simComponent->mNext = p_simComponent;
  }
  p_simComponent->m_pPointer = 0i64;
  v4 = p_simComponent->mPrev;
  v5 = p_simComponent->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  p_simComponent->mPrev = p_simComponent;
  p_simComponent->mNext = p_simComponent;
}

// File Line: 47
// RVA: 0x9B4F0
void __fastcall UFG::BasePhysicsObject::~BasePhysicsObject(UFG::BasePhysicsObject *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_simComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable;
  p_simComponent = &this->mUserData.simComponent;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    mPrev = p_simComponent->mPrev;
    mNext = p_simComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_simComponent->mPrev = p_simComponent;
    p_simComponent->mNext = p_simComponent;
  }
  p_simComponent->m_pPointer = 0i64;
  v4 = p_simComponent->mPrev;
  v5 = p_simComponent->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  p_simComponent->mPrev = p_simComponent;
  p_simComponent->mNext = p_simComponent;
}

