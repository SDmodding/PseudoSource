// File Line: 26
// RVA: 0x9C540
void __fastcall UFG::HavokUserData::~HavokUserData(UFG::HavokUserData *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v1; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  v1 = &this->simComponent;
  if ( this->simComponent.m_pPointer )
  {
    v2 = v1->mPrev;
    v3 = v1->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  }
  v1->m_pPointer = 0i64;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
}

// File Line: 47
// RVA: 0x9B4F0
void __fastcall UFG::BasePhysicsObject::~BasePhysicsObject(UFG::BasePhysicsObject *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v1; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable';
  v1 = &this->mUserData.simComponent;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    v2 = v1->mPrev;
    v3 = v1->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  }
  v1->m_pPointer = 0i64;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
}

