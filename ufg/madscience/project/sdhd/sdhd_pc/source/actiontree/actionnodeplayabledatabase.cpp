// File Line: 32
// RVA: 0x2DCE00
void __fastcall ActionNode_BuildDatabase_Visitor::Visit(
        ActionNode_BuildDatabase_Visitor *this,
        UFG::qBaseNodeVariableRB<unsigned __int64> *node)
{
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rdx

  HIDWORD(node[1].mParent) = ++sActionNode_UniqueID;
  v4 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  if ( v4 )
  {
    v4->mParent = 0i64;
    v4->mChild[0] = 0i64;
    v4->mChild[1] = 0i64;
    v4[1].mParent = 0i64;
  }
  else
  {
    v4 = 0i64;
  }
  v4[1].mParent = node;
  v4->mUID = HIDWORD(node[1].mParent);
  UFG::qBaseTreeVariableRB<unsigned __int64>::Add(&this->mRBTree->mTree, v4);
  ActionNode_Visitor::visit_children(this, (ActionNode *)node);
}

// File Line: 59
// RVA: 0x2DCEA0
void __fastcall ActionNodePlayableDataBase::buildDatabase(ActionNodePlayableDataBase *this)
{
  UFG::qBaseNodeVariableRB<unsigned __int64> *v2; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v3; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *i; // rdi
  ActionNodePlayableDataBase *v5; // rbx
  unsigned __int64 mUID; // rbp
  ActionNode *mParent; // rcx
  ActionPath *NameFullPath; // rax
  char *String_DBG; // rsi
  int mCount; // edx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v11; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *j; // rax
  ActionNodePlayableDataBase *v13; // rax
  ActionNodePlayableDataBase *v14; // rcx
  ActionPath result; // [rsp+28h] [rbp-40h] BYREF
  __int64 v16[6]; // [rsp+38h] [rbp-30h] BYREF

  v16[0] = (__int64)&ActionNode_BuildDatabase_Visitor::`vftable;
  v16[1] = (__int64)this;
  if ( ActionNode::smRoot )
    ((void (__fastcall *)(ActionNode *, __int64 *))ActionNode::smRoot->vfptr[1].ResolveReferences)(
      ActionNode::smRoot,
      v16);
  if ( sDumpEntries )
  {
    v2 = this->mPlayables.mTree.mRoot.mChild[0];
    v3 = v2->mChild[0];
    for ( i = &this->mPlayables.mTree.mNULL; v3 != i; v3 = v3->mChild[0] )
      v2 = v3;
    v5 = 0i64;
    if ( v2 != i )
      v5 = (ActionNodePlayableDataBase *)v2;
    while ( v5 )
    {
      mUID = v5->mPlayables.mTree.mRoot.mUID;
      mParent = (ActionNode *)v5->mPlayables.mTree.mNULL.mParent;
      if ( mParent )
      {
        NameFullPath = ActionNode::GetNameFullPath(mParent, &result);
        String_DBG = ActionPath::GetString_DBG(NameFullPath);
        mCount = result.mPath.mCount;
        if ( result.mPath.mCount >= 0 )
        {
          if ( result.mPath.mData.mOffset
            && (UFG::qOffset64<ActionID *> *)((char *)&result.mPath.mData + result.mPath.mData.mOffset) )
          {
            operator delete[]((char *)&result.mPath.mData + result.mPath.mData.mOffset);
            mCount = result.mPath.mCount;
          }
          result.mPath.mData.mOffset = 0i64;
          result.mPath.mCount = mCount & 0x80000000;
        }
      }
      else
      {
        String_DBG = "EMPTY_NODE_ENTRY";
      }
      UFG::qPrintf("UID:%d:%s\n", mUID, String_DBG);
      v11 = v5->mPlayables.mTree.mRoot.mChild[1];
      if ( i == v11 )
      {
        v13 = (ActionNodePlayableDataBase *)((unsigned __int64)v5->mPlayables.mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
        if ( v5 == (ActionNodePlayableDataBase *)v13->mPlayables.mTree.mRoot.mChild[1] )
        {
          do
          {
            v14 = v13;
            v13 = (ActionNodePlayableDataBase *)((unsigned __int64)v13->mPlayables.mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
          }
          while ( v14 == (ActionNodePlayableDataBase *)v13->mPlayables.mTree.mRoot.mChild[1] );
        }
        v5 = v13;
        if ( v13 == this )
          v5 = 0i64;
      }
      else
      {
        for ( j = v11->mChild[0]; j != i; j = j->mChild[0] )
          v11 = j;
        v5 = (ActionNodePlayableDataBase *)v11;
      }
    }
  }
}

// File Line: 93
// RVA: 0x2DC220
void ActionNodePlayableDataBase::Init(void)
{
  ActionNodePlayableDataBase *v0; // rax
  ActionNodePlayableDataBase *v1; // rdx

  v0 = (ActionNodePlayableDataBase *)UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  v1 = v0;
  if ( v0 )
  {
    v0->mPlayables.mTree.mRoot.mParent = 0i64;
    v0->mPlayables.mTree.mRoot.8 = 0ui64;
    v0->mPlayables.mTree.mNULL.mParent = 0i64;
    v0->mPlayables.mTree.mNULL.8 = 0ui64;
    v0->mPlayables.mTree.mNULL.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&v0->mPlayables.mTree.mNULL | (__int64)v0->mPlayables.mTree.mNULL.mParent & 1);
    v0->mPlayables.mTree.mNULL.mChild[0] = &v0->mPlayables.mTree.mNULL;
    v0->mPlayables.mTree.mNULL.mChild[1] = &v0->mPlayables.mTree.mNULL;
    v0->mPlayables.mTree.mNULL.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)v0->mPlayables.mTree.mNULL.mParent & ~1ui64);
    v0->mPlayables.mTree.mNULL.mUID = 0i64;
    v0->mPlayables.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&v0->mPlayables.mTree.mNULL | (__int64)v0->mPlayables.mTree.mRoot.mParent & 1);
    v0->mPlayables.mTree.mRoot.mChild[0] = &v0->mPlayables.mTree.mNULL;
    v0->mPlayables.mTree.mRoot.mChild[1] = &v0->mPlayables.mTree.mNULL;
    v0->mPlayables.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)v0->mPlayables.mTree.mRoot.mParent & ~1ui64);
    v0->mPlayables.mTree.mRoot.mUID = -1i64;
    v0->mPlayables.mTree.mCount = 0;
  }
  else
  {
    v1 = 0i64;
  }
  ActionNodePlayableDataBase::msActionNodePlayableDataBase = v1;
  ActionNodePlayableDataBase::buildDatabase(v1);
}

