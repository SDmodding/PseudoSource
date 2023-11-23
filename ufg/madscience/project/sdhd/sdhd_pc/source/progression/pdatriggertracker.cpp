// File Line: 24
// RVA: 0x4C8E00
void __fastcall UFG::PDATrigger::UseTrigger(UFG::PDATrigger *this)
{
  this->mTriggered = 1;
}

// File Line: 53
// RVA: 0x490E90
void __fastcall UFG::PDATriggerTracker::~PDATriggerTracker(UFG::PDATriggerTracker *this)
{
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx

  if ( this->mPDATriggers.mTree.mCount )
  {
    while ( 1 )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
      if ( !Head )
        break;
      p_mCachedBufferPtr = &Head[-1].mCachedBufferPtr;
      if ( Head == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      p_mNode = &Head->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)this, p_mNode);
      if ( p_mCachedBufferPtr )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mParent)(
          p_mCachedBufferPtr,
          1i64);
      if ( !this->mPDATriggers.mTree.mCount )
        goto LABEL_10;
    }
    p_mCachedBufferPtr = 0i64;
LABEL_6:
    p_mNode = 0i64;
    goto LABEL_7;
  }
LABEL_10:
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)this);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)this);
}

// File Line: 63
// RVA: 0x492740
UFG::PDATrigger *__fastcall UFG::PDATriggerTracker::Add(
        UFG::PDATriggerTracker *this,
        unsigned int *identifier,
        UFG::GameSlice *pGameSlice)
{
  UFG::PDATrigger *v6; // rbx
  UFG::qNodeRB<UFG::PDATrigger> *v7; // rdx
  unsigned int v8; // eax
  UFG::PDATrigger *identifiera; // [rsp+50h] [rbp+8h] BYREF
  UFG::PDATrigger **p_identifiera; // [rsp+58h] [rbp+10h]

  p_identifiera = &identifiera;
  LODWORD(identifiera) = *identifier;
  UFG::PDATriggerTracker::Remove(this, (UFG::qSymbol)&identifiera);
  v6 = (UFG::PDATrigger *)UFG::qMalloc(0x40ui64, "PDATriggerTracker", 0i64);
  identifiera = v6;
  v7 = 0i64;
  if ( v6 )
  {
    v8 = *identifier;
    v6->mNode.mParent = 0i64;
    v6->mNode.mChild[0] = 0i64;
    v6->mNode.mChild[1] = 0i64;
    v6->mNode.mUID = v8;
    v6->vfptr = (UFG::PDATriggerVtbl *)&UFG::PDATrigger::`vftable;
    v6->mSymbol.mUID = v8;
    v6->mpGameSlice = pGameSlice;
    v6->mTriggered = 0;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
    v7 = &v6->UFG::qNodeRB<UFG::PDATrigger>;
  UFG::qBaseTreeRB::Add(&this->mPDATriggers.mTree, &v7->mNode);
  return v6;
}

// File Line: 71
// RVA: 0x4B63A0
void __fastcall UFG::PDATriggerTracker::Remove(UFG::PDATriggerTracker *this, unsigned int *identifier)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *v4; // rax
  int *p_mCount; // rbx
  UFG::GameSlice *v6; // rdi
  UFG::PDATriggerParameters *mPDATriggerParameters; // rsi
  UFG::ProgressionTracker *v8; // rax

  v2 = *identifier;
  if ( v2 )
  {
    v4 = UFG::qBaseTreeRB::Get(&this->mPDATriggers.mTree, v2);
    if ( v4 )
    {
      p_mCount = &v4[-1].mCount;
      if ( v4 != (UFG::qBaseTreeRB *)8 )
      {
        v6 = (UFG::GameSlice *)*((_QWORD *)p_mCount + 6);
        if ( v6 )
        {
          mPDATriggerParameters = v6->mPDATriggerParameters;
          if ( mPDATriggerParameters->mObjectiveName.mLength )
          {
            v8 = UFG::ProgressionTracker::Instance();
            UFG::ObjectiveTracker::UpdateStatus(
              &v8->mObjectiveTracker,
              &mPDATriggerParameters->mObjectiveName,
              STATUS_INACTIVE,
              v6);
          }
        }
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)this,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)(p_mCount + 2));
        (**(void (__fastcall ***)(char *, __int64))p_mCount)((char *)p_mCount, 1i64);
      }
    }
  }
}

// File Line: 104
// RVA: 0x4A28B0
Render::SkinningCacheNode *__fastcall UFG::PDATriggerTracker::GetFirst(UFG::PDATriggerTracker *this)
{
  Render::SkinningCacheNode *result; // rax

  result = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
  if ( result )
    return (Render::SkinningCacheNode *)((char *)result - 8);
  return result;
}

// File Line: 110
// RVA: 0x4A5480
UFG::qBaseTreeRB *__fastcall UFG::PDATriggerTracker::GetNext(UFG::PDATriggerTracker *this, UFG::PDATrigger *pPrevious)
{
  UFG::qBaseTreeRB *result; // rax

  if ( pPrevious )
    pPrevious = (UFG::PDATrigger *)((char *)pPrevious + 8);
  result = UFG::qBaseTreeRB::GetNext(&this->mPDATriggers.mTree, (UFG::qBaseNodeRB *)pPrevious);
  if ( result )
    return (UFG::qBaseTreeRB *)((char *)result - 8);
  return result;
}

// File Line: 118
// RVA: 0x4ACFC0
char __fastcall UFG::PDATriggerTracker::IsTriggered(UFG::PDATriggerTracker *this, unsigned int *identifier)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *v3; // rax
  int *p_mCount; // rax

  v2 = *identifier;
  if ( v2 && (v3 = UFG::qBaseTreeRB::Get(&this->mPDATriggers.mTree, v2)) != 0i64 && (p_mCount = &v3[-1].mCount) != 0i64 )
    return *((_BYTE *)p_mCount + 56);
  else
    return 0;
}

