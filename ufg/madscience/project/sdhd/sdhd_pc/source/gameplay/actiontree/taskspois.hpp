// File Line: 46
// RVA: 0x29CDA0
void __fastcall POIManagementTask::~POIManagementTask(POIManagementTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *p_mpPOI; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&POIManagementTask::`vftable;
  p_mpPOI = &this->mpPOI;
  if ( this->mpPOI.m_pPointer )
  {
    mPrev = p_mpPOI->mPrev;
    mNext = p_mpPOI->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpPOI->mPrev = p_mpPOI;
    p_mpPOI->mNext = p_mpPOI;
  }
  p_mpPOI->m_pPointer = 0i64;
  v5 = p_mpPOI->mPrev;
  v6 = p_mpPOI->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mpPOI->mPrev = p_mpPOI;
  p_mpPOI->mNext = p_mpPOI;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

