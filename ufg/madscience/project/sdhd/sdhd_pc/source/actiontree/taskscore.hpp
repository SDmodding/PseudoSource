// File Line: 130
// RVA: 0x269090
void __fastcall SpawnTask::SpawnTask(SpawnTask *this)
{
  SpawnTask *v1; // rbx
  UFG::qNode<ITask,ITask> *v2; // rax
  UFG::qNode<SpawnTask,SpawnTask> *v3; // rax

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<SpawnTrack>::`vftable';
  v3 = (UFG::qNode<SpawnTask,SpawnTask> *)&this->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  this->vfptr = (ITaskVtbl *)&SpawnTask::`vftable';
  this->m_CallingActionContext = 0i64;
  ActionContext::ActionContext(&this->m_ActionContext);
  *(_WORD *)&v1->m_isParent = 0;
  ActionController::ActionController(&v1->m_ActionController);
}

