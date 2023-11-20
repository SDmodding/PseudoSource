// File Line: 47
// RVA: 0x9C260
void __fastcall UFG::DestructionEvent::~DestructionEvent(UFG::DestructionEvent *this)
{
  UFG::DestructionEvent *v1; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::Event,UFG::Event> *v12; // rdx
  UFG::qNode<UFG::Event,UFG::Event> *v13; // rcx
  UFG::qNode<UFG::Event,UFG::Event> *v14; // rax

  v1 = this;
  this->vfptr = (UFG::EventVtbl *)&UFG::DestructionEvent::`vftable;
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&this->objectProperty.mPrev);
  v2 = &v1->mBreakingBody;
  if ( v1->mBreakingBody.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v1->mBreakingBody.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v1->mBreakingBody.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mBreakingBody.mPrev;
  }
  v1->mBreakingBody.m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v1->mBreakingBody.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->mBreakingBody.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mBreakingBody.mPrev;
  v7 = &v1->mCollidingComponent;
  if ( v1->mCollidingComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mCollidingComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mCollidingComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mCollidingComponent.mPrev;
  }
  v1->mCollidingComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mCollidingComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mCollidingComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mCollidingComponent.mPrev;
  v1->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  v12 = (UFG::qNode<UFG::Event,UFG::Event> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

