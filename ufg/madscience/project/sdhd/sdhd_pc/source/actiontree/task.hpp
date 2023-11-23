// File Line: 41
// RVA: 0x269E10
void __fastcall ITask::~ITask(ITask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rdx
  UFG::qNode<ITask,ITask> *mPrev; // rcx
  UFG::qNode<ITask,ITask> *mNext; // rax

  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v1 = &this->UFG::qNode<ITask,ITask>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

