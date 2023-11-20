// File Line: 17
// RVA: 0x1AB0C0
void __fastcall DNA::Transaction::DoInternal(DNA::Transaction *this)
{
  DNA::ActionState::Enum *v1; // rdi
  UFG::qNode<DNA::IAction,DNA::IAction> **i; // rbx

  v1 = &this->mState;
  if ( this->mState )
  {
    for ( i = &this->mActions.mNode.mNext[-1].mNext; i != (UFG::qNode<DNA::IAction,DNA::IAction> **)v1; i = &i[2][-1].mNext )
    {
      ((void (__fastcall *)(UFG::qNode<DNA::IAction,DNA::IAction> **))(*i)[1].mPrev)(i);
      *((_DWORD *)i + 8) = 1;
    }
  }
}

// File Line: 28
// RVA: 0x1AB150
void __fastcall DNA::Transaction::UndoInternal(DNA::Transaction *this)
{
  DNA::ActionState::Enum *v1; // rdi
  DNA::Transaction *v2; // rbx

  v1 = &this->mState;
  v2 = (DNA::Transaction *)&this->mActions.mNode.mPrev[-1].mNext;
  if ( v2 != (DNA::Transaction *)&this->mState )
  {
    do
    {
      v2->vfptr->UndoInternal((DNA::IAction *)&v2->vfptr);
      v2->mState = 2;
      v2 = (DNA::Transaction *)&v2->mPrev[-1].mNext;
    }
    while ( v2 != (DNA::Transaction *)v1 );
  }
}

// File Line: 36
// RVA: 0x1AACB0
void __fastcall DNA::Transaction::AddAction(DNA::Transaction *this, DNA::IAction *action)
{
  UFG::qList<DNA::IAction,DNA::IAction,1,0> *v2; // r14
  DNA::ActionState::Enum *v3; // rsi
  DNA::Transaction *v4; // rbx
  DNA::IAction *v5; // rdi
  DNA::Transaction *v6; // rbp
  UFG::qNode<DNA::IAction,DNA::IAction> *v7; // rax
  UFG::qNode<DNA::IAction,DNA::IAction> *v8; // rcx

  v2 = &this->mActions;
  v3 = &this->mState;
  v4 = (DNA::Transaction *)&this->mActions.mNode.mPrev[-1].mNext;
  v5 = action;
  v6 = this;
  if ( v4 == (DNA::Transaction *)&this->mState )
  {
LABEL_4:
    v7 = v2->mNode.mPrev;
    v8 = (UFG::qNode<DNA::IAction,DNA::IAction> *)&v5->mPrev;
    v7->mNext = (UFG::qNode<DNA::IAction,DNA::IAction> *)&v5->mPrev;
    v8->mPrev = v7;
    v8->mNext = &v2->mNode;
    v2->mNode.mPrev = (UFG::qNode<DNA::IAction,DNA::IAction> *)&v5->mPrev;
    v5->vfptr->DoInternal(v5);
    v5->mState = 1;
    v6->mIsValid = 1;
  }
  else
  {
    while ( v4->vfptr->TryToMerge((DNA::IAction *)&v4->vfptr, v5) != 1 )
    {
      v4 = (DNA::Transaction *)&v4->mPrev[-1].mNext;
      if ( v4 == (DNA::Transaction *)v3 )
        goto LABEL_4;
    }
    if ( v5 )
      ((void (__fastcall *)(DNA::IAction *, signed __int64))v5->vfptr->~IAction)(v5, 1i64);
  }
}

// File Line: 66
// RVA: 0x1AAD60
void __fastcall DNA::ActionHistory::AppendAction(DNA::ActionHistory *this, DNA::IAction *action)
{
  DNA::IAction *v2; // rdi
  DNA::ActionHistory *v3; // rbx
  unsigned int *v4; // rsi
  UFG::qNode<DNA::IAction,DNA::IAction> *v5; // rdx
  UFG::qNode<DNA::IAction,DNA::IAction> *v6; // rcx
  UFG::qNode<DNA::IAction,DNA::IAction> *v7; // rax
  DNA::Transaction *v8; // rcx
  UFG::qNode<DNA::IAction,DNA::IAction> *v9; // rax
  UFG::qNode<DNA::IAction,DNA::IAction> *v10; // rcx

  v2 = action;
  v3 = this;
  if ( action->mIsValid )
  {
    if ( this->mCurrentNode )
    {
      v4 = &this->mNode.mUID;
      do
      {
        v5 = v3->mHistory.mNode.mPrev;
        if ( &v5[-1].mNext == (UFG::qNode<DNA::IAction,DNA::IAction> **)v4
          || (UFG::qNode<DNA::IAction,DNA::IAction> **)v3->mCurrentNode == &v5[-1].mNext )
        {
          break;
        }
        v6 = v5->mPrev;
        v7 = v5->mNext;
        v6->mNext = v7;
        v7->mPrev = v6;
        v5->mPrev = v5;
        v5->mNext = v5;
        if ( v5 != (UFG::qNode<DNA::IAction,DNA::IAction> *)8 )
          ((void (__fastcall *)(UFG::qNode<DNA::IAction,DNA::IAction> **, signed __int64))v5[-1].mNext[2].mPrev)(
            &v5[-1].mNext,
            1i64);
      }
      while ( v3->mCurrentNode );
    }
    v8 = v3->mTransaction;
    if ( v8 )
    {
      DNA::Transaction::AddAction(v8, v2);
    }
    else
    {
      v9 = v3->mHistory.mNode.mPrev;
      v10 = (UFG::qNode<DNA::IAction,DNA::IAction> *)&v2->mPrev;
      v9->mNext = (UFG::qNode<DNA::IAction,DNA::IAction> *)&v2->mPrev;
      v10->mPrev = v9;
      v10->mNext = &v3->mHistory.mNode;
      v3->mHistory.mNode.mPrev = (UFG::qNode<DNA::IAction,DNA::IAction> *)&v2->mPrev;
      v3->mCurrentNode = v2;
      v2->vfptr->DoInternal(v2);
      v2->mState = 1;
    }
  }
  else
  {
    ((void (__fastcall *)(DNA::IAction *, signed __int64))action->vfptr->~IAction)(action, 1i64);
  }
}

// File Line: 116
// RVA: 0x1AAF50
void __fastcall DNA::ActionHistory::BeginTransaction(DNA::ActionHistory *this)
{
  DNA::ActionHistory *v1; // rbx
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // rdx
  UFG::allocator::free_link *v4; // rcx
  UFG::allocator::free_link *v5; // [rsp+48h] [rbp+10h]

  v1 = this;
  if ( this->mTransactionCount )
  {
    ++this->mTransactionCount;
  }
  else
  {
    v2 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
    v3 = v2;
    if ( v2 )
    {
      v4 = v2 + 1;
      v4->mNext = v4;
      v4[1].mNext = v4;
      v2->mNext = (UFG::allocator::free_link *)&DNA::IAction::`vftable;
      LOBYTE(v2[3].mNext) = 1;
      HIDWORD(v2[3].mNext) = -764200325;
      LODWORD(v2[4].mNext) = 0;
      v2->mNext = (UFG::allocator::free_link *)&DNA::Transaction::`vftable;
      v5 = v2 + 5;
      v5->mNext = v5;
      v5[1].mNext = v5;
      LOBYTE(v2[3].mNext) = 0;
    }
    else
    {
      v3 = 0i64;
    }
    v1->mTransaction = (DNA::Transaction *)v3;
    ++v1->mTransactionCount;
  }
}

// File Line: 147
// RVA: 0x1AABC0
void __fastcall DNA::ActionManager::ActionManager(DNA::ActionManager *this)
{
  DNA::ActionManager *v1; // rbx

  v1 = this;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mHistory.mTree);
  UFG::qMutex::qMutex(&v1->mMutex, &customWorldMapCaption);
}

// File Line: 151
// RVA: 0x1AAE40
void __fastcall DNA::ActionManager::AppendAction(DNA::ActionManager *this, DNA::IAction *action, unsigned int id)
{
  unsigned int v3; // ebp
  DNA::IAction *v4; // rsi
  DNA::ActionManager *v5; // r14
  DNA::IActionVtbl *v6; // rax
  _RTL_CRITICAL_SECTION *v7; // rbx
  DNA::ActionHistory *v8; // rdi
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // ST28_8

  v3 = id;
  v4 = action;
  v5 = this;
  if ( !action->mIsValid )
  {
    v6 = action->vfptr;
LABEL_11:
    ((void (__fastcall *)(DNA::IAction *, signed __int64))v6->~IAction)(v4, 1i64);
    return;
  }
  if ( id - 1 > 0xFFFFFFFD )
  {
    action->vfptr->DoInternal(action);
    v4->mState = 1;
    v6 = v4->vfptr;
    goto LABEL_11;
  }
  v7 = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  v8 = (DNA::ActionHistory *)UFG::qBaseTreeRB::Get(&v5->mHistory.mTree, v3);
  if ( !v8 )
  {
    v9 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
    v8 = (DNA::ActionHistory *)v9;
    if ( v9 )
    {
      v9->mNext = 0i64;
      v9[1].mNext = 0i64;
      v9[2].mNext = 0i64;
      LODWORD(v9[3].mNext) = v3;
      v10 = v9 + 4;
      v10->mNext = v10;
      v10[1].mNext = v10;
      v9[6].mNext = 0i64;
      v9[7].mNext = 0i64;
      LODWORD(v9[8].mNext) = 0;
    }
    else
    {
      v8 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&v5->mHistory.mTree, &v8->mNode);
  }
  DNA::ActionHistory::AppendAction(v8, v4);
  UFG::qMutex::Unlock(v7);
}

// File Line: 206
// RVA: 0x1AAFF0
void __fastcall DNA::ActionManager::BeginTransaction(DNA::ActionManager *this, unsigned int id)
{
  unsigned int v2; // esi
  DNA::ActionManager *v3; // rbp
  _RTL_CRITICAL_SECTION *v4; // rbx
  DNA::ActionHistory *v5; // rdi
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // ST28_8

  v2 = id;
  v3 = this;
  if ( id - 1 <= 0xFFFFFFFD )
  {
    v4 = (_RTL_CRITICAL_SECTION *)&this->mMutex;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
    v5 = (DNA::ActionHistory *)UFG::qBaseTreeRB::Get(&v3->mHistory.mTree, v2);
    if ( !v5 )
    {
      v6 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
      v5 = (DNA::ActionHistory *)v6;
      if ( v6 )
      {
        v6->mNext = 0i64;
        v6[1].mNext = 0i64;
        v6[2].mNext = 0i64;
        LODWORD(v6[3].mNext) = v2;
        v7 = v6 + 4;
        v7->mNext = v7;
        v7[1].mNext = v7;
        v6[6].mNext = 0i64;
        v6[7].mNext = 0i64;
        LODWORD(v6[8].mNext) = 0;
      }
      else
      {
        v5 = 0i64;
      }
      UFG::qBaseTreeRB::Add(&v3->mHistory.mTree, &v5->mNode);
    }
    DNA::ActionHistory::BeginTransaction(v5);
    UFG::qMutex::Unlock(v4);
  }
}

// File Line: 222
// RVA: 0x1AB110
void __fastcall DNA::ActionManager::EndTransaction(DNA::ActionManager *this, unsigned int id)
{
  DNA::ActionHistory *v2; // rax
  bool v3; // zf
  DNA::IAction *v4; // rdx

  if ( id )
  {
    v2 = (DNA::ActionHistory *)UFG::qBaseTreeRB::Get(&this->mHistory.mTree, id);
    if ( v2 )
    {
      v3 = v2->mTransactionCount-- == 1;
      if ( v3 )
      {
        v4 = (DNA::IAction *)&v2->mTransaction->vfptr;
        v2->mTransaction = 0i64;
        DNA::ActionHistory::AppendAction(v2, v4);
      }
    }
  }
}

