// File Line: 58
// RVA: 0x29B2C0
void __fastcall DamageTask::~DamageTask(DamageTask *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpSource; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&DamageTask::`vftable;
  p_mpSource = &this->mpSource;
  if ( this->mpSource.m_pPointer )
  {
    mPrev = p_mpSource->mPrev;
    mNext = p_mpSource->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpSource->mPrev = p_mpSource;
    p_mpSource->mNext = p_mpSource;
  }
  p_mpSource->m_pPointer = 0i64;
  v5 = p_mpSource->mPrev;
  v6 = p_mpSource->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mpSource->mPrev = p_mpSource;
  p_mpSource->mNext = p_mpSource;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

