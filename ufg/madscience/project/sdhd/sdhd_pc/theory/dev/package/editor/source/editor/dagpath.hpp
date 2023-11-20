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
  UFG::qString *result; // rax

  if ( this->mSubElements.size )
    result = this->mSubElements.p;
  else
    result = &UFG::Editor::DAGPath::sEmtpyString;
  return result;
}

// File Line: 102
// RVA: 0x20DAF0
void __fastcall UFG::Editor::DAGPath::InsertStart(UFG::Editor::DAGPath *this, UFG::qSymbol *sym)
{
  UFG::Editor::DAGPath *v2; // rbx
  UFG::Editor::SmartHandleObject *v3; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v4; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v5; // rdx

  v2 = this;
  UFG::qArray<UFG::qSymbol,0>::Insert(&this->mElements, 0, sym, "qArray.Insert");
  v3 = v2->mFnObject.mPtr;
  if ( v3 )
  {
    v4 = v2->mFnObject.mNext;
    v5 = v2->mFnObject.mPrev;
    v5->mNext = v4;
    v4->mPrev = v5;
    v2->mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v2->mFnObject.mPrev;
    v2->mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v2->mFnObject.mPrev;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v3->mSmartHandleList.mNode.mNext == &v3->mSmartHandleList )
    {
      if ( v3 )
        v3->vfptr->__vecDelDtor(v3, 1u);
    }
  }
  v2->mFnObject.mPtr = 0i64;
}

// File Line: 103
// RVA: 0x20DA90
void __fastcall UFG::Editor::DAGPath::InsertEnd(UFG::Editor::DAGPath *this, UFG::qSymbol *sym)
{
  UFG::Editor::DAGPath *v2; // rbx
  UFG::Editor::SmartHandleObject *v3; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v4; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v5; // rdx

  v2 = this;
  UFG::qArray<UFG::qSymbol,0>::Add(&this->mElements, sym, "qArray.Add");
  v3 = v2->mFnObject.mPtr;
  if ( v3 )
  {
    v4 = v2->mFnObject.mNext;
    v5 = v2->mFnObject.mPrev;
    v5->mNext = v4;
    v4->mPrev = v5;
    v2->mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v2->mFnObject.mPrev;
    v2->mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v2->mFnObject.mPrev;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v3->mSmartHandleList.mNode.mNext == &v3->mSmartHandleList )
    {
      if ( v3 )
        v3->vfptr->__vecDelDtor(v3, 1u);
    }
  }
  v2->mFnObject.mPtr = 0i64;
}

// File Line: 104
// RVA: 0x210AA0
void __fastcall UFG::Editor::DAGPath::RemoveEnd(UFG::Editor::DAGPath *this)
{
  unsigned int v1; // eax
  UFG::Editor::DAGPath *v2; // rbx
  UFG::Editor::SmartHandleObject *v3; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v4; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v5; // rdx

  v1 = this->mElements.size;
  v2 = this;
  if ( v1 > 1 )
    this->mElements.size = v1 - 1;
  else
    this->mElements.size = 0;
  v3 = this->mFnObject.mPtr;
  if ( v3 )
  {
    v4 = v2->mFnObject.mNext;
    v5 = v2->mFnObject.mPrev;
    v5->mNext = v4;
    v4->mPrev = v5;
    v2->mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v2->mFnObject.mPrev;
    v2->mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v2->mFnObject.mPrev;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v3->mSmartHandleList.mNode.mNext == &v3->mSmartHandleList )
    {
      if ( v3 )
        v3->vfptr->__vecDelDtor(v3, 1u);
    }
  }
  v2->mFnObject.mPtr = 0i64;
}

