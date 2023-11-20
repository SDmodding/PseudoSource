// File Line: 31
// RVA: 0x203BD0
void __fastcall UFG::Editor::SmartHandle::~SmartHandle(UFG::Editor::SmartHandle *this)
{
  UFG::Editor::SmartHandle *v1; // rbx
  UFG::Editor::SmartHandleObject *v2; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v3; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v4; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v5; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v6; // rax

  v1 = this;
  v2 = this->mPtr;
  if ( v2 )
  {
    v3 = v1->mPrev;
    v4 = v1->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v1->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v1->mPrev;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v2->mSmartHandleList.mNode.mNext == &v2->mSmartHandleList
      && v2 )
    {
      v2->vfptr->__vecDelDtor(v2, 1u);
    }
    v1->mPtr = 0i64;
  }
  v1->mPtr = 0i64;
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v1->mPrev;
}

// File Line: 73
// RVA: 0x202ED0
void __fastcall UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::~TypedSmartHandle<2296309086,UFG::Editor::FnObject>(UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject> *this)
{
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject> *v1; // rbx
  UFG::Editor::SmartHandleObject *v2; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v3; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v4; // rax

  v1 = this;
  v2 = this->mPtr;
  if ( v2 )
  {
    v3 = v1->mPrev;
    v4 = v1->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v1->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v1->mPrev;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v2->mSmartHandleList.mNode.mNext == &v2->mSmartHandleList
      && v2 )
    {
      v2->vfptr->__vecDelDtor(v2, 1u);
    }
    v1->mPtr = 0i64;
  }
  v1->mPtr = 0i64;
  UFG::Editor::SmartHandle::~SmartHandle((UFG::Editor::SmartHandle *)&v1->mPrev);
}

// File Line: 79
// RVA: 0x20D610
void __fastcall UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::Init(UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject> *this, unsigned int id)
{
  unsigned int v2; // edi
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject> *v3; // rbx
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseTreeRB *v5; // rax
  signed __int64 v6; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v7; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v8; // rax

  v2 = id;
  v3 = this;
  if ( !(_S26 & 1) )
  {
    _S26 |= 1u;
    UFG::qBaseTreeRB::qBaseTreeRB(&sSmartWarehouse.mInventories.mTree);
    atexit(UFG::Editor::SmartWarehouse::Instance_::_2_::_dynamic_atexit_destructor_for__sSmartWarehouse__);
  }
  v4 = UFG::qBaseTreeRB::Get(&sSmartWarehouse.mInventories.mTree, 0x88DEE55E);
  if ( v4 )
  {
    if ( v2 )
    {
      v5 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)((char *)v4 + 40), v2);
      if ( v5 )
      {
        v6 = (signed __int64)&v5[-1].mCount;
        if ( v5 != (UFG::qBaseTreeRB *)8 && !v3->mPtr )
        {
          v3->mTypeId = *(_DWORD *)(v6 + 56);
          v3->mPtr = (UFG::Editor::SmartHandleObject *)v6;
          v7 = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)(v6 + 40);
          v8 = v7->mPrev;
          v8->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v3->mPrev;
          v3->mPrev = v8;
          v3->mNext = v7;
          v7->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v3->mPrev;
        }
      }
    }
  }
}

