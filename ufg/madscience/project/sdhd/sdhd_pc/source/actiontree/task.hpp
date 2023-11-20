// File Line: 41
// RVA: 0x269E10
void __fastcall ITask::~ITask(ITask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rdx
  UFG::qNode<ITask,ITask> *v2; // rcx
  UFG::qNode<ITask,ITask> *v3; // rax

  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

