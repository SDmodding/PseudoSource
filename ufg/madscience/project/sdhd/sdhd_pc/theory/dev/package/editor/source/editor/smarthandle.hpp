// File Line: 31
// RVA: 0x203BD0
void __fastcall UFG::Editor::SmartHandle::~SmartHandle(UFG::Editor::SmartHandle *this)
{
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v5; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v6; // rax

  mPtr = this->mPtr;
  if ( mPtr )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)mPtr->mSmartHandleList.mNode.mNext == &mPtr->mSmartHandleList )
      mPtr->vfptr->__vecDelDtor(mPtr, 1u);
    this->mPtr = 0i64;
  }
  this->mPtr = 0i64;
  v5 = this->mPrev;
  v6 = this->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 73
// RVA: 0x202ED0
void __fastcall UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::~TypedSmartHandle<2296309086,UFG::Editor::FnObject>(
        UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject> *this)
{
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax

  mPtr = this->mPtr;
  if ( mPtr )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)mPtr->mSmartHandleList.mNode.mNext == &mPtr->mSmartHandleList )
      mPtr->vfptr->__vecDelDtor(mPtr, 1u);
    this->mPtr = 0i64;
  }
  this->mPtr = 0i64;
  UFG::Editor::SmartHandle::~SmartHandle(this);
}

// File Line: 79
// RVA: 0x20D610
void __fastcall UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::Init(
        UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject> *this,
        unsigned int id)
{
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseTreeRB *v5; // rax
  UFG::Editor::SmartHandleObject *p_mCount; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax

  if ( (_S26 & 1) == 0 )
  {
    _S26 |= 1u;
    UFG::qBaseTreeRB::qBaseTreeRB(&sSmartWarehouse.mInventories.mTree);
    atexit(UFG::Editor::SmartWarehouse::Instance_::_2_::_dynamic_atexit_destructor_for__sSmartWarehouse__);
  }
  v4 = UFG::qBaseTreeRB::Get(&sSmartWarehouse.mInventories.mTree, 0x88DEE55E);
  if ( v4 )
  {
    if ( id )
    {
      v5 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)v4->mNULL.mChild, id);
      if ( v5 )
      {
        p_mCount = (UFG::Editor::SmartHandleObject *)&v5[-1].mCount;
        if ( v5 != (UFG::qBaseTreeRB *)8 && !this->mPtr )
        {
          this->mTypeId = p_mCount->mTypeId;
          this->mPtr = p_mCount;
          p_mNode = &p_mCount->mSmartHandleList.mNode;
          mPrev = p_mNode->mPrev;
          mPrev->mNext = this;
          this->mPrev = mPrev;
          this->mNext = p_mNode;
          p_mNode->mPrev = this;
        }
      }
    }
  }
}

