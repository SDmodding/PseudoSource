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
  Render::Skinning *v1; // rdi
  Render::SkinningCacheNode *v2; // rax
  Illusion::Buffer **v3; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rdx

  v1 = (Render::Skinning *)this;
  if ( this->mPDATriggers.mTree.mCount )
  {
    while ( 1 )
    {
      v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&v1->mSkinnedVertexBuffers);
      if ( !v2 )
        break;
      v3 = &v2[-1].mCachedBufferPtr;
      if ( v2 == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      v4 = &v2->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v1->mSkinnedVertexBuffers.mTree, v4);
      if ( v3 )
        ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v3)->mNode.mParent)(v3, 1i64);
      if ( !v1->mSkinnedVertexBuffers.mTree.mCount )
        goto LABEL_10;
    }
    v3 = 0i64;
LABEL_6:
    v4 = 0i64;
    goto LABEL_7;
  }
LABEL_10:
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)v1);
  UFG::qBaseTreeRB::~qBaseTreeRB(v1);
}

// File Line: 63
// RVA: 0x492740
UFG::PDATrigger *__fastcall UFG::PDATriggerTracker::Add(UFG::PDATriggerTracker *this, __int64 identifier, UFG::GameSlice *pGameSlice)
{
  UFG::GameSlice *v3; // rbp
  unsigned int *v4; // rsi
  UFG::PDATriggerTracker *v5; // rdi
  UFG::PDATrigger *v6; // rbx
  UFG::qBaseNodeRB *v7; // rdx
  unsigned int v8; // eax
  UFG::qSymbol identifiera; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *v11; // [rsp+58h] [rbp+10h]

  v3 = pGameSlice;
  v4 = (unsigned int *)identifier;
  v5 = this;
  v11 = &identifiera;
  identifiera.mUID = *(_DWORD *)identifier;
  UFG::PDATriggerTracker::Remove(this, (UFG::qSymbol)&identifiera);
  v6 = (UFG::PDATrigger *)UFG::qMalloc(0x40ui64, "PDATriggerTracker", 0i64);
  *(_QWORD *)&identifiera.mUID = v6;
  v7 = 0i64;
  if ( v6 )
  {
    v8 = *v4;
    v6->mNode.mParent = 0i64;
    v6->mNode.mChild[0] = 0i64;
    v6->mNode.mChild[1] = 0i64;
    v6->mNode.mUID = v8;
    v6->vfptr = (UFG::PDATriggerVtbl *)&UFG::PDATrigger::`vftable';
    v6->mSymbol.mUID = v8;
    v6->mpGameSlice = v3;
    v6->mTriggered = 0;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
    v7 = &v6->mNode;
  UFG::qBaseTreeRB::Add(&v5->mPDATriggers.mTree, v7);
  return v6;
}

// File Line: 71
// RVA: 0x4B63A0
void __fastcall UFG::PDATriggerTracker::Remove(UFG::PDATriggerTracker *this, __int64 identifier)
{
  unsigned int v2; // edx
  UFG::qBaseTreeVariableRB<unsigned __int64> *v3; // rbp
  UFG::qBaseTreeRB *v4; // rax
  signed __int64 v5; // rbx
  UFG::GameSlice *v6; // rdi
  UFG::PDATriggerParameters *v7; // rsi
  UFG::ProgressionTracker *v8; // rax

  v2 = *(_DWORD *)identifier;
  v3 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)this;
  if ( v2 )
  {
    v4 = UFG::qBaseTreeRB::Get(&this->mPDATriggers.mTree, v2);
    if ( v4 )
    {
      v5 = (signed __int64)&v4[-1].mCount;
      if ( v4 != (UFG::qBaseTreeRB *)8 )
      {
        v6 = *(UFG::GameSlice **)(v5 + 48);
        if ( v6 )
        {
          v7 = v6->mPDATriggerParameters;
          if ( v7->mObjectiveName.mLength )
          {
            v8 = UFG::ProgressionTracker::Instance();
            UFG::ObjectiveTracker::UpdateStatus(&v8->mObjectiveTracker, &v7->mObjectiveName, 0, v6);
          }
        }
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(v3, (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v5 + 8));
        (**(void (__fastcall ***)(signed __int64, signed __int64))v5)(v5, 1i64);
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
    result = (Render::SkinningCacheNode *)((char *)result - 8);
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
    result = (UFG::qBaseTreeRB *)((char *)result - 8);
  return result;
}

// File Line: 118
// RVA: 0x4ACFC0
bool __fastcall UFG::PDATriggerTracker::IsTriggered(UFG::PDATriggerTracker *this, __int64 identifier)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *v3; // rax
  signed __int64 v4; // rax
  bool result; // al

  v2 = *(_DWORD *)identifier;
  if ( v2
    && (v3 = UFG::qBaseTreeRB::Get(&this->mPDATriggers.mTree, v2)) != 0i64
    && (v4 = (signed __int64)&v3[-1].mCount) != 0 )
  {
    result = *(_BYTE *)(v4 + 56);
  }
  else
  {
    result = 0;
  }
  return result;
}

