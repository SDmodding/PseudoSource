// File Line: 77
// RVA: 0x20CCB0
UFG::qSymbol *__fastcall UFG::Editor::DAGPath::GetSystemName(UFG::Editor::DAGPath *this, UFG::qSymbol *result)
{
  result->mUID = (unsigned int)this->mSystemName;
  return result;
}

// File Line: 95
// RVA: 0x20CC90
UFG::qString *__fastcall UFG::Editor::DAGPath::GetSubElement(UFG::Editor::DAGPath *this)
{
  if ( this->mSubElements.size )
    return this->mSubElements.p;
  else
    return &UFG::Editor::DAGPath::sEmtpyString;
}

// File Line: 102
// RVA: 0x20DAF0
void __fastcall UFG::Editor::DAGPath::InsertStart(UFG::Editor::DAGPath *this, UFG::qSymbol *sym)
{
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rdx

  UFG::qArray<UFG::qSymbol,0>::Insert(&this->mElements, 0, sym, "qArray.Insert");
  mPtr = this->mFnObject.mPtr;
  if ( mPtr )
  {
    mNext = this->mFnObject.mNext;
    mPrev = this->mFnObject.mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mFnObject.mPrev = &this->mFnObject;
    this->mFnObject.mNext = &this->mFnObject;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)mPtr->mSmartHandleList.mNode.mNext == &mPtr->mSmartHandleList )
      mPtr->vfptr->__vecDelDtor(mPtr, 1u);
  }
  this->mFnObject.mPtr = 0i64;
}

// File Line: 103
// RVA: 0x20DA90
void __fastcall UFG::Editor::DAGPath::InsertEnd(UFG::Editor::DAGPath *this, UFG::qSymbol *sym)
{
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rdx

  UFG::qArray<UFG::qSymbol,0>::Add(&this->mElements, sym, "qArray.Add");
  mPtr = this->mFnObject.mPtr;
  if ( mPtr )
  {
    mNext = this->mFnObject.mNext;
    mPrev = this->mFnObject.mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mFnObject.mPrev = &this->mFnObject;
    this->mFnObject.mNext = &this->mFnObject;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)mPtr->mSmartHandleList.mNode.mNext == &mPtr->mSmartHandleList )
      mPtr->vfptr->__vecDelDtor(mPtr, 1u);
  }
  this->mFnObject.mPtr = 0i64;
}

// File Line: 104
// RVA: 0x210AA0
void __fastcall UFG::Editor::DAGPath::RemoveEnd(UFG::Editor::DAGPath *this)
{
  unsigned int size; // eax
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rdx

  size = this->mElements.size;
  if ( size > 1 )
    this->mElements.size = size - 1;
  else
    this->mElements.size = 0;
  mPtr = this->mFnObject.mPtr;
  if ( mPtr )
  {
    mNext = this->mFnObject.mNext;
    mPrev = this->mFnObject.mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mFnObject.mPrev = &this->mFnObject;
    this->mFnObject.mNext = &this->mFnObject;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)mPtr->mSmartHandleList.mNode.mNext == &mPtr->mSmartHandleList )
      mPtr->vfptr->__vecDelDtor(mPtr, 1u);
  }
  this->mFnObject.mPtr = 0i64;
}

