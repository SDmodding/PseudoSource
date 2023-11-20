// File Line: 529
// RVA: 0x25810
void __fastcall UFG::qTaskGroup::qTaskGroup(UFG::qTaskGroup *this, const char *task_group_name)
{
  UFG::qTaskGroup *v2; // rdx
  UFG::qTask *v3; // rcx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v4; // rax
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v5; // rax
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v6; // [rsp+30h] [rbp+18h]
  UFG::qTask *v7; // [rsp+30h] [rbp+18h]

  v2 = this;
  this->mPrev = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&this->mPrev;
  v6 = &this->mTasks;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  this->mNumTasks = 0;
  v3 = &this->mStartTask;
  v3->mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v3->mPrev;
  v4 = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->mTaskGroup = 0i64;
  v3->mFlags = 2;
  v3->mSyncVars.i64 = 0i64;
  v3->mSyncVars.v.mDependents = 0i64;
  v3->mFunctionDeclData = 0i64;
  v3->mSPUElfAddress = 0i64;
  v3->mSPUFunction = 0i64;
  v3->mPPUFunction = (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))-1i64;
  v3->mParam0 = 0i64;
  v3->mParam1 = 0i64;
  v3->mParam2 = 0i64;
  v3->mParam3 = 0i64;
  v7 = &v2->mEndTask;
  v7->mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v7->mPrev;
  v5 = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v2->mEndTask.mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v2->mEndTask.mTaskGroup = 0i64;
  v2->mEndTask.mFlags = 2;
  v2->mEndTask.mSyncVars.i64 = 0i64;
  v2->mEndTask.mSyncVars.v.mDependents = 0i64;
  v2->mEndTask.mFunctionDeclData = 0i64;
  v2->mEndTask.mSPUElfAddress = 0i64;
  v2->mEndTask.mSPUFunction = 0i64;
  v2->mEndTask.mPPUFunction = (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))-2i64;
  v2->mEndTask.mParam0 = 0i64;
  v2->mEndTask.mParam1 = 0i64;
  v2->mEndTask.mParam2 = 0i64;
  v2->mEndTask.mParam3 = 0i64;
  v2->mStartTask.mTaskGroup = v2;
  v2->mEndTask.mTaskGroup = v2;
}

