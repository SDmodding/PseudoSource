// File Line: 529
// RVA: 0x25810
void __fastcall UFG::qTaskGroup::qTaskGroup(UFG::qTaskGroup *this, const char *task_group_name)
{
  UFG::qTask *p_mStartTask; // rcx

  this->mPrev = this;
  this->mNext = this;
  this->mTasks.mNode.mPrev = &this->mTasks.mNode;
  this->mTasks.mNode.mNext = &this->mTasks.mNode;
  this->mNumTasks = 0;
  p_mStartTask = &this->mStartTask;
  p_mStartTask->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = p_mStartTask;
  p_mStartTask->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = p_mStartTask;
  p_mStartTask->UFG::qNode<UFG::qTask,UFG::TaskPlat>::mPrev = &p_mStartTask->UFG::qNode<UFG::qTask,UFG::TaskPlat>;
  p_mStartTask->UFG::qNode<UFG::qTask,UFG::TaskPlat>::mNext = &p_mStartTask->UFG::qNode<UFG::qTask,UFG::TaskPlat>;
  p_mStartTask->mTaskGroup = 0i64;
  p_mStartTask->mFlags = 2;
  p_mStartTask->mSyncVars.i64 = 0i64;
  p_mStartTask->mSyncVars.v.mDependents = 0i64;
  p_mStartTask->mFunctionDeclData = 0i64;
  p_mStartTask->mSPUElfAddress = 0i64;
  p_mStartTask->mSPUFunction = 0i64;
  p_mStartTask->mPPUFunction = (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))-1i64;
  p_mStartTask->mParam0 = 0i64;
  p_mStartTask->mParam1 = 0i64;
  p_mStartTask->mParam2 = 0i64;
  p_mStartTask->mParam3 = 0i64;
  this->mEndTask.mPrev = &this->mEndTask;
  this->mEndTask.mNext = &this->mEndTask;
  this->mEndTask.mPrev = &this->mEndTask.UFG::qNode<UFG::qTask,UFG::TaskPlat>;
  this->mEndTask.mNext = &this->mEndTask.UFG::qNode<UFG::qTask,UFG::TaskPlat>;
  this->mEndTask.mTaskGroup = 0i64;
  this->mEndTask.mFlags = 2;
  this->mEndTask.mSyncVars.i64 = 0i64;
  this->mEndTask.mSyncVars.v.mDependents = 0i64;
  this->mEndTask.mFunctionDeclData = 0i64;
  this->mEndTask.mSPUElfAddress = 0i64;
  this->mEndTask.mSPUFunction = 0i64;
  this->mEndTask.mPPUFunction = (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))-2i64;
  this->mEndTask.mParam0 = 0i64;
  this->mEndTask.mParam1 = 0i64;
  this->mEndTask.mParam2 = 0i64;
  this->mEndTask.mParam3 = 0i64;
  this->mStartTask.mTaskGroup = this;
  this->mEndTask.mTaskGroup = this;
}

