// File Line: 130
// RVA: 0x269090
void __fastcall SpawnTask::SpawnTask(SpawnTask *this)
{
  this->Task<SpawnTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<SpawnTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<SpawnTrack>::`vftable;
  this->UFG::qNode<SpawnTask,SpawnTask>::mPrev = &this->UFG::qNode<SpawnTask,SpawnTask>;
  this->UFG::qNode<SpawnTask,SpawnTask>::mNext = &this->UFG::qNode<SpawnTask,SpawnTask>;
  this->vfptr = (ITaskVtbl *)&SpawnTask::`vftable;
  this->m_CallingActionContext = 0i64;
  ActionContext::ActionContext(&this->m_ActionContext);
  *(_WORD *)&this->m_isParent = 0;
  ActionController::ActionController(&this->m_ActionController);
}

