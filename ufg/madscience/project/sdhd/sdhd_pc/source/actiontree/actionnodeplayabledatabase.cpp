// File Line: 32
// RVA: 0x2DCE00
void __fastcall ActionNode_BuildDatabase_Visitor::Visit(ActionNode_BuildDatabase_Visitor *this, ActionNodePlayable *node)
{
  ActionNodePlayable *v2; // rbx
  ActionNode_BuildDatabase_Visitor *v3; // rdi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rdx

  v2 = node;
  v3 = this;
  node->mUniqueID = ++sActionNode_UniqueID;
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
  v4[1].mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v2;
  v4->mUID = v2->mUniqueID;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Add(&v3->mRBTree->mTree, v4);
  ActionNode_Visitor::visit_children((ActionNode_Visitor *)&v3->vfptr, (ActionNode *)&v2->vfptr);
}

// File Line: 59
// RVA: 0x2DCEA0
void __fastcall ActionNodePlayableDataBase::buildDatabase(ActionNodePlayableDataBase *this)
{
  ActionNodePlayableDataBase *v1; // r14
  UFG::qBaseNodeVariableRB<unsigned __int64> *v2; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v3; // rax
  signed __int64 i; // rdi
  ActionNodePlayableDataBase *v5; // rbx
  unsigned __int64 v6; // rbp
  ActionNode *v7; // rcx
  ActionPath *v8; // rax
  char *v9; // rsi
  int v10; // edx
  ActionNodePlayableDataBase *v11; // rcx
  ActionNodePlayableDataBase *j; // rax
  ActionNodePlayableDataBase *v13; // rax
  ActionNodePlayableDataBase *v14; // rcx
  ActionPath result; // [rsp+28h] [rbp-40h]
  void **v16; // [rsp+38h] [rbp-30h]
  ActionNodePlayableDataBase *v17; // [rsp+40h] [rbp-28h]

  v1 = this;
  v16 = &ActionNode_BuildDatabase_Visitor::`vftable;
  v17 = this;
  if ( ActionNode::smRoot )
    ((void (__fastcall *)(ActionNode *, void ***))ActionNode::smRoot->vfptr[1].ResolveReferences)(
      ActionNode::smRoot,
      &v16);
  if ( sDumpEntries )
  {
    v2 = v1->mPlayables.mTree.mRoot.mChild[0];
    v3 = v2->mChild[0];
    for ( i = (signed __int64)&v1->mPlayables.mTree.mNULL;
          v3 != (UFG::qBaseNodeVariableRB<unsigned __int64> *)i;
          v3 = v3->mChild[0] )
    {
      v2 = v3;
    }
    v5 = 0i64;
    if ( v2 != (UFG::qBaseNodeVariableRB<unsigned __int64> *)i )
      v5 = (ActionNodePlayableDataBase *)v2;
    while ( v5 )
    {
      v6 = v5->mPlayables.mTree.mRoot.mUID;
      v7 = (ActionNode *)v5->mPlayables.mTree.mNULL.mParent;
      if ( v7 )
      {
        v8 = ActionNode::GetNameFullPath(v7, &result);
        v9 = ActionPath::GetString_DBG(v8);
        v10 = result.mPath.mCount;
        if ( result.mPath.mCount >= 0 )
        {
          if ( result.mPath.mData.mOffset
            && (UFG::qOffset64<ActionID *> *)((char *)&result.mPath.mData + result.mPath.mData.mOffset) )
          {
            operator delete[]((char *)&result.mPath.mData + result.mPath.mData.mOffset);
            v10 = result.mPath.mCount;
          }
          result.mPath.mData.mOffset = 0i64;
          result.mPath.mCount = v10 & 0x80000000;
        }
      }
      else
      {
        v9 = "EMPTY_NODE_ENTRY";
      }
      UFG::qPrintf("UID:%d:%s\n", v6, v9);
      v11 = (ActionNodePlayableDataBase *)v5->mPlayables.mTree.mRoot.mChild[1];
      if ( (ActionNodePlayableDataBase *)i == v11 )
      {
        v13 = (ActionNodePlayableDataBase *)((_QWORD)v5->mPlayables.mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
        if ( v5 == (ActionNodePlayableDataBase *)v13->mPlayables.mTree.mRoot.mChild[1] )
        {
          do
          {
            v14 = v13;
            v13 = (ActionNodePlayableDataBase *)((_QWORD)v13->mPlayables.mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
          }
          while ( v14 == (ActionNodePlayableDataBase *)v13->mPlayables.mTree.mRoot.mChild[1] );
        }
        v5 = v13;
        if ( v13 == v1 )
          v5 = 0i64;
      }
      else
      {
        for ( j = (ActionNodePlayableDataBase *)v11->mPlayables.mTree.mRoot.mChild[0];
              j != (ActionNodePlayableDataBase *)i;
              j = (ActionNodePlayableDataBase *)j->mPlayables.mTree.mRoot.mChild[0] )
        {
          v11 = j;
        }
        v5 = v11;
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
  _QWORD *v2; // rcx

  v0 = (ActionNodePlayableDataBase *)UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  v1 = v0;
  if ( v0 )
  {
    v0->mPlayables.mTree.mRoot.mParent = 0i64;
    v0->mPlayables.mTree.mRoot.8 = 0ui64;
    v2 = &v0->mPlayables.mTree.mNULL.mParent;
    *v2 = 0i64;
    v2[1] = 0i64;
    v2[2] = 0i64;
    *v2 = (unsigned __int64)&v0->mPlayables.mTree.mNULL | (_QWORD)v0->mPlayables.mTree.mNULL.mParent & 1;
    v0->mPlayables.mTree.mNULL.mChild[0] = &v0->mPlayables.mTree.mNULL;
    v0->mPlayables.mTree.mNULL.mChild[1] = &v0->mPlayables.mTree.mNULL;
    *v2 &= 0xFFFFFFFFFFFFFFFEui64;
    v0->mPlayables.mTree.mNULL.mUID = 0i64;
    v0->mPlayables.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&v0->mPlayables.mTree.mNULL | (_QWORD)v0->mPlayables.mTree.mRoot.mParent & 1);
    v0->mPlayables.mTree.mRoot.mChild[0] = &v0->mPlayables.mTree.mNULL;
    v0->mPlayables.mTree.mRoot.mChild[1] = &v0->mPlayables.mTree.mNULL;
    v0->mPlayables.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((_QWORD)v0->mPlayables.mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
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

