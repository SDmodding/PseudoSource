// File Line: 213
// RVA: 0x29CEA0
void __fastcall PairedGrappleTask::~PairedGrappleTask(PairedGrappleTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterPhysicsComponent> *p_mSlave; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&PairedGrappleTask::`vftable;
  p_mSlave = &this->mSlave;
  if ( this->mSlave.m_pPointer )
  {
    mPrev = p_mSlave->mPrev;
    mNext = p_mSlave->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mSlave->mPrev = p_mSlave;
    p_mSlave->mNext = p_mSlave;
  }
  p_mSlave->m_pPointer = 0i64;
  v5 = p_mSlave->mPrev;
  v6 = p_mSlave->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mSlave->mPrev = p_mSlave;
  p_mSlave->mNext = p_mSlave;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

