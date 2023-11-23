// File Line: 17
// RVA: 0x1AB0C0
void __fastcall DNA::Transaction::DoInternal(DNA::Transaction *this)
{
  DNA::ActionState::Enum *p_mState; // rdi
  UFG::qNode<DNA::IAction,DNA::IAction> **i; // rbx

  p_mState = &this->mState;
  if ( this->mState )
  {
    for ( i = &this->mActions.mNode.mNext[-1].mNext;
          i != (UFG::qNode<DNA::IAction,DNA::IAction> **)p_mState;
          i = &i[2][-1].mNext )
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
  DNA::ActionState::Enum *p_mState; // rdi
  DNA::Transaction *p_mNext; // rbx

  p_mState = &this->mState;
  p_mNext = (DNA::Transaction *)&this->mActions.mNode.mPrev[-1].mNext;
  if ( p_mNext != (DNA::Transaction *)&this->mState )
  {
    do
    {
      p_mNext->vfptr->UndoInternal(p_mNext);
      p_mNext->mState = F3_1Pt44_512;
      p_mNext = (DNA::Transaction *)&p_mNext->mPrev[-1].mNext;
    }
    while ( p_mNext != (DNA::Transaction *)p_mState );
  }
}

// File Line: 36
// RVA: 0x1AACB0
void __fastcall DNA::Transaction::AddAction(DNA::Transaction *this, DNA::IAction *action)
{
  UFG::qList<DNA::IAction,DNA::IAction,1,0> *p_mActions; // r14
  DNA::ActionState::Enum *p_mState; // rsi
  DNA::Transaction *p_mNext; // rbx
  UFG::qNode<DNA::IAction,DNA::IAction> *mPrev; // rax

  p_mActions = &this->mActions;
  p_mState = &this->mState;
  p_mNext = (DNA::Transaction *)&this->mActions.mNode.mPrev[-1].mNext;
  if ( p_mNext == (DNA::Transaction *)&this->mState )
  {
LABEL_4:
    mPrev = p_mActions->mNode.mPrev;
    mPrev->mNext = &action->UFG::qNode<DNA::IAction,DNA::IAction>;
    action->mPrev = mPrev;
    action->mNext = &p_mActions->mNode;
    p_mActions->mNode.mPrev = &action->UFG::qNode<DNA::IAction,DNA::IAction>;
    action->vfptr->DoInternal(action);
    action->mState = F5_1Pt2_512;
    this->mIsValid = 1;
  }
  else
  {
    while ( p_mNext->vfptr->TryToMerge(p_mNext, action) != 1 )
    {
      p_mNext = (DNA::Transaction *)&p_mNext->mPrev[-1].mNext;
      if ( p_mNext == (DNA::Transaction *)p_mState )
        goto LABEL_4;
    }
    if ( action )
      ((void (__fastcall *)(DNA::IAction *, __int64))action->vfptr->~IAction)(action, 1i64);
  }
}

// File Line: 66
// RVA: 0x1AAD60
void __fastcall DNA::ActionHistory::AppendAction(DNA::ActionHistory *this, DNA::IAction *action)
{
  unsigned int *p_mUID; // rsi
  UFG::qNode<DNA::IAction,DNA::IAction> *mPrev; // rdx
  UFG::qNode<DNA::IAction,DNA::IAction> *v6; // rcx
  UFG::qNode<DNA::IAction,DNA::IAction> *mNext; // rax
  DNA::Transaction *mTransaction; // rcx
  UFG::qNode<DNA::IAction,DNA::IAction> *v9; // rax

  if ( action->mIsValid )
  {
    if ( this->mCurrentNode )
    {
      p_mUID = &this->mNode.mUID;
      do
      {
        mPrev = this->mHistory.mNode.mPrev;
        if ( &mPrev[-1].mNext == (UFG::qNode<DNA::IAction,DNA::IAction> **)p_mUID
          || (UFG::qNode<DNA::IAction,DNA::IAction> **)this->mCurrentNode == &mPrev[-1].mNext )
        {
          break;
        }
        v6 = mPrev->mPrev;
        mNext = mPrev->mNext;
        v6->mNext = mNext;
        mNext->mPrev = v6;
        mPrev->mPrev = mPrev;
        mPrev->mNext = mPrev;
        if ( mPrev != (UFG::qNode<DNA::IAction,DNA::IAction> *)8 )
          ((void (__fastcall *)(UFG::qNode<DNA::IAction,DNA::IAction> **, __int64))mPrev[-1].mNext[2].mPrev)(
            &mPrev[-1].mNext,
            1i64);
      }
      while ( this->mCurrentNode );
    }
    mTransaction = this->mTransaction;
    if ( mTransaction )
    {
      DNA::Transaction::AddAction(mTransaction, action);
    }
    else
    {
      v9 = this->mHistory.mNode.mPrev;
      v9->mNext = &action->UFG::qNode<DNA::IAction,DNA::IAction>;
      action->mPrev = v9;
      action->mNext = &this->mHistory.mNode;
      this->mHistory.mNode.mPrev = &action->UFG::qNode<DNA::IAction,DNA::IAction>;
      this->mCurrentNode = action;
      action->vfptr->DoInternal(action);
      action->mState = F5_1Pt2_512;
    }
  }
  else
  {
    ((void (__fastcall *)(DNA::IAction *, __int64))action->vfptr->~IAction)(action, 1i64);
  }
}

// File Line: 116
// RVA: 0x1AAF50
void __fastcall DNA::ActionHistory::BeginTransaction(DNA::ActionHistory *this)
{
  UFG::allocator::free_link *v2; // rax
  DNA::Transaction *v3; // rdx

  if ( this->mTransactionCount )
  {
    ++this->mTransactionCount;
  }
  else
  {
    v2 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
    v3 = (DNA::Transaction *)v2;
    if ( v2 )
    {
      v2[1].mNext = v2 + 1;
      v2[2].mNext = v2 + 1;
      v2->mNext = (UFG::allocator::free_link *)&DNA::IAction::`vftable;
      LOBYTE(v2[3].mNext) = 1;
      HIDWORD(v2[3].mNext) = -764200325;
      LODWORD(v2[4].mNext) = 0;
      v2->mNext = (UFG::allocator::free_link *)&DNA::Transaction::`vftable;
      v2[5].mNext = v2 + 5;
      v2[6].mNext = v2 + 5;
      LOBYTE(v2[3].mNext) = 0;
    }
    else
    {
      v3 = 0i64;
    }
    this->mTransaction = v3;
    ++this->mTransactionCount;
  }
}

// File Line: 147
// RVA: 0x1AABC0
void __fastcall DNA::ActionManager::ActionManager(DNA::ActionManager *this)
{
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mHistory.mTree);
  UFG::qMutex::qMutex(&this->mMutex, &customCaption);
}

// File Line: 151
// RVA: 0x1AAE40
void __fastcall DNA::ActionManager::AppendAction(DNA::ActionManager *this, DNA::IAction *action, unsigned int id)
{
  DNA::IActionVtbl *vfptr; // rax
  _RTL_CRITICAL_SECTION *p_mMutex; // rbx
  DNA::ActionHistory *v8; // rdi
  UFG::allocator::free_link *v9; // rax

  if ( !action->mIsValid )
  {
    vfptr = action->vfptr;
LABEL_11:
    ((void (__fastcall *)(DNA::IAction *, __int64))vfptr->~IAction)(action, 1i64);
    return;
  }
  if ( id - 1 > 0xFFFFFFFD )
  {
    action->vfptr->DoInternal(action);
    action->mState = F5_1Pt2_512;
    vfptr = action->vfptr;
    goto LABEL_11;
  }
  p_mMutex = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  v8 = (DNA::ActionHistory *)UFG::qBaseTreeRB::Get(&this->mHistory.mTree, id);
  if ( !v8 )
  {
    v9 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
    v8 = (DNA::ActionHistory *)v9;
    if ( v9 )
    {
      v9->mNext = 0i64;
      v9[1].mNext = 0i64;
      v9[2].mNext = 0i64;
      LODWORD(v9[3].mNext) = id;
      v9[4].mNext = v9 + 4;
      v9[5].mNext = v9 + 4;
      v9[6].mNext = 0i64;
      v9[7].mNext = 0i64;
      LODWORD(v9[8].mNext) = 0;
    }
    else
    {
      v8 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&this->mHistory.mTree, &v8->mNode);
  }
  DNA::ActionHistory::AppendAction(v8, action);
  UFG::qMutex::Unlock(p_mMutex);
}

// File Line: 206
// RVA: 0x1AAFF0
void __fastcall DNA::ActionManager::BeginTransaction(DNA::ActionManager *this, unsigned int id)
{
  _RTL_CRITICAL_SECTION *p_mMutex; // rbx
  DNA::ActionHistory *v5; // rdi
  UFG::allocator::free_link *v6; // rax

  if ( id - 1 <= 0xFFFFFFFD )
  {
    p_mMutex = (_RTL_CRITICAL_SECTION *)&this->mMutex;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
    v5 = (DNA::ActionHistory *)UFG::qBaseTreeRB::Get(&this->mHistory.mTree, id);
    if ( !v5 )
    {
      v6 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
      v5 = (DNA::ActionHistory *)v6;
      if ( v6 )
      {
        v6->mNext = 0i64;
        v6[1].mNext = 0i64;
        v6[2].mNext = 0i64;
        LODWORD(v6[3].mNext) = id;
        v6[4].mNext = v6 + 4;
        v6[5].mNext = v6 + 4;
        v6[6].mNext = 0i64;
        v6[7].mNext = 0i64;
        LODWORD(v6[8].mNext) = 0;
      }
      else
      {
        v5 = 0i64;
      }
      UFG::qBaseTreeRB::Add(&this->mHistory.mTree, &v5->mNode);
    }
    DNA::ActionHistory::BeginTransaction(v5);
    UFG::qMutex::Unlock(p_mMutex);
  }
}

// File Line: 222
// RVA: 0x1AB110
void __fastcall DNA::ActionManager::EndTransaction(DNA::ActionManager *this, unsigned int id)
{
  DNA::ActionHistory *v2; // rax
  DNA::IAction *mTransaction; // rdx

  if ( id )
  {
    v2 = (DNA::ActionHistory *)UFG::qBaseTreeRB::Get(&this->mHistory.mTree, id);
    if ( v2 )
    {
      if ( v2->mTransactionCount-- == 1 )
      {
        mTransaction = v2->mTransaction;
        v2->mTransaction = 0i64;
        DNA::ActionHistory::AppendAction(v2, mTransaction);
      }
    }
  }
}

