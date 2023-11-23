// File Line: 28
// RVA: 0x160CC0
void __fastcall UFG::qBaseTreeRB::qBaseTreeRB(UFG::qBaseTreeRB *this)
{
  this->mRoot.mParent = 0i64;
  this->mRoot.mChild[0] = 0i64;
  this->mRoot.mChild[1] = 0i64;
  this->mNULL.mParent = 0i64;
  this->mNULL.mChild[0] = 0i64;
  this->mNULL.mChild[1] = 0i64;
  this->mNULL.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&this->mNULL | (__int64)this->mNULL.mParent & 1);
  this->mNULL.mChild[0] = &this->mNULL;
  this->mNULL.mChild[1] = &this->mNULL;
  this->mNULL.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)this->mNULL.mParent & ~1ui64);
  this->mNULL.mUID = 0;
  this->mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&this->mNULL | (__int64)this->mRoot.mParent & 1);
  this->mRoot.mChild[0] = &this->mNULL;
  this->mRoot.mChild[1] = &this->mNULL;
  this->mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)this->mRoot.mParent & ~1ui64);
  this->mRoot.mUID = -1;
  this->mCount = 0;
}

// File Line: 45
// RVA: 0x167DC0
void __fastcall UFG::qBaseTreeRB::~qBaseTreeRB(Render::Skinning *this)
{
  this->mSkinnedVertexBuffers.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&this->mSkinnedVertexBuffers.mTree.mNULL | (__int64)this->mSkinnedVertexBuffers.mTree.mRoot.mParent & 1);
  this->mSkinnedVertexBuffers.mTree.mRoot.mChild[0] = &this->mSkinnedVertexBuffers.mTree.mNULL;
  this->mSkinnedVertexBuffers.mTree.mRoot.mChild[1] = &this->mSkinnedVertexBuffers.mTree.mNULL;
  this->mSkinnedVertexBuffers.mTree.mCount = 0;
}

// File Line: 61
// RVA: 0x1652A0
void __fastcall UFG::qBaseTreeRB::Add(UFG::qBaseTreeRB *this, UFG::qBaseNodeRB *x)
{
  UFG::qBaseNodeRB *v2; // rbx
  unsigned __int64 v4; // rax
  __int64 v5; // rdx
  unsigned __int64 i; // rdx
  BOOL v7; // r9d
  __int64 v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 *v10; // rdx
  UFG::qBaseTreeRB *v11; // r8
  unsigned __int64 v12; // r8
  UFG::qBaseTreeRB *v13; // r8
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // rcx
  unsigned __int64 *v16; // rcx
  UFG::qBaseTreeRB *v17; // r8
  unsigned __int64 v18; // r8
  UFG::qBaseTreeRB *v19; // r8
  unsigned __int64 v20; // r8

  if ( x )
  {
    v2 = x;
    if ( ((unsigned __int64)x->mParent & 0xFFFFFFFFFFFFFFFEui64) == 0 )
    {
      UFG::qBaseTreeRB::AddHelper(this, x);
      v4 = (unsigned __int64)v2->mParent & 0xFFFFFFFFFFFFFFFEui64;
      v5 = *(_QWORD *)v4;
      v2->mParent = (UFG::qBaseNodeRB *)((unsigned __int64)v2->mParent | 1);
      for ( i = v5 & 0xFFFFFFFFFFFFFFFEui64; (*(_BYTE *)v4 & 1) != 0; i = *(_QWORD *)v4 & 0xFFFFFFFFFFFFFFFEui64 )
      {
        v7 = v4 == *(_QWORD *)(i + 8);
        v8 = 8i64 * (v4 == *(_QWORD *)(i + 8));
        v9 = *(_QWORD **)(v8 + i + 8);
        if ( (*(_BYTE *)v9 & 1) != 0 )
        {
          *(_QWORD *)v4 &= ~1ui64;
          *v9 &= ~1ui64;
          *(_QWORD *)i |= 1ui64;
          v2 = (UFG::qBaseNodeRB *)i;
        }
        else
        {
          if ( v2 == *(UFG::qBaseNodeRB **)(v8 + v4 + 8) )
          {
            v2 = (UFG::qBaseNodeRB *)v4;
            if ( v7 )
            {
              v10 = *(unsigned __int64 **)(v4 + 16);
              *(_QWORD *)(v4 + 16) = v10[1];
              v11 = (UFG::qBaseTreeRB *)v10[1];
              if ( v11 != (UFG::qBaseTreeRB *)&this->mNULL )
                v11->mRoot.mParent = (UFG::qBaseNodeRB *)(v4 | (__int64)v11->mRoot.mParent & 1);
              v12 = *(_QWORD *)v4 & 0xFFFFFFFFFFFFFFFEui64;
              *v10 = v12 | *(_DWORD *)v10 & 1;
              if ( v4 == *(_QWORD *)(v12 + 8) )
                *(_QWORD *)(v12 + 8) = v10;
              else
                *(_QWORD *)(v12 + 16) = v10;
              v10[1] = v4;
            }
            else
            {
              v10 = *(unsigned __int64 **)(v4 + 8);
              *(_QWORD *)(v4 + 8) = v10[2];
              v13 = (UFG::qBaseTreeRB *)v10[2];
              if ( &this->mNULL != (UFG::qBaseNodeRB *)v13 )
                v13->mRoot.mParent = (UFG::qBaseNodeRB *)(v4 | (__int64)v13->mRoot.mParent & 1);
              v14 = *(_QWORD *)v4 & 0xFFFFFFFFFFFFFFFEui64;
              *v10 = v14 | *(_DWORD *)v10 & 1;
              if ( v4 == *(_QWORD *)(v14 + 8) )
                *(_QWORD *)(v14 + 8) = v10;
              else
                *(_QWORD *)(v14 + 16) = v10;
              v10[2] = v4;
            }
            v15 = (unsigned __int64)v10 | *(_DWORD *)v4 & 1;
            *(_QWORD *)v4 = v15;
            v4 = v15 & 0xFFFFFFFFFFFFFFFEui64;
            i = *(_QWORD *)(v15 & 0xFFFFFFFFFFFFFFFEui64) & 0xFFFFFFFFFFFFFFFEui64;
          }
          *(_QWORD *)v4 &= ~1ui64;
          *(_QWORD *)i |= 1ui64;
          if ( v7 )
          {
            v16 = *(unsigned __int64 **)(i + 8);
            *(_QWORD *)(i + 8) = v16[2];
            v17 = (UFG::qBaseTreeRB *)v16[2];
            if ( &this->mNULL != (UFG::qBaseNodeRB *)v17 )
              v17->mRoot.mParent = (UFG::qBaseNodeRB *)(i | (__int64)v17->mRoot.mParent & 1);
            v18 = *(_QWORD *)i & 0xFFFFFFFFFFFFFFFEui64;
            *v16 = v18 | *(_DWORD *)v16 & 1;
            if ( i == *(_QWORD *)(v18 + 8) )
              *(_QWORD *)(v18 + 8) = v16;
            else
              *(_QWORD *)(v18 + 16) = v16;
            v16[2] = i;
          }
          else
          {
            v16 = *(unsigned __int64 **)(i + 16);
            *(_QWORD *)(i + 16) = v16[1];
            v19 = (UFG::qBaseTreeRB *)v16[1];
            if ( v19 != (UFG::qBaseTreeRB *)&this->mNULL )
              v19->mRoot.mParent = (UFG::qBaseNodeRB *)(i | (__int64)v19->mRoot.mParent & 1);
            v20 = *(_QWORD *)i & 0xFFFFFFFFFFFFFFFEui64;
            *v16 = v20 | *(_DWORD *)v16 & 1;
            if ( i == *(_QWORD *)(v20 + 8) )
              *(_QWORD *)(v20 + 8) = v16;
            else
              *(_QWORD *)(v20 + 16) = v16;
            v16[1] = i;
          }
          *(_QWORD *)i = (unsigned __int64)v16 | *(_DWORD *)i & 1;
        }
        v4 = (unsigned __int64)v2->mParent & 0xFFFFFFFFFFFFFFFEui64;
      }
      this->mRoot.mChild[0]->mParent = (UFG::qBaseNodeRB *)((unsigned __int64)this->mRoot.mChild[0]->mParent & ~1ui64);
      ++this->mCount;
    }
  }
}

// File Line: 129
// RVA: 0x166370
void __fastcall UFG::qBaseTreeRB::AddHelper(UFG::qBaseTreeRB *this, UFG::qBaseNodeRB *z)
{
  UFG::qBaseTreeRB *v2; // r9
  UFG::qBaseTreeRB *i; // r8

  v2 = this;
  z->mChild[0] = &this->mNULL;
  z->mChild[1] = &this->mNULL;
  for ( i = (UFG::qBaseTreeRB *)this->mRoot.mChild[0];
        i != (UFG::qBaseTreeRB *)&this->mNULL;
        i = (UFG::qBaseTreeRB *)i->mRoot.mChild[i->mRoot.mUID <= z->mUID] )
  {
    v2 = i;
  }
  z->mParent = (UFG::qBaseNodeRB *)((unsigned __int64)v2 | (__int64)z->mParent & 1);
  if ( v2 == this || v2->mRoot.mUID > z->mUID )
    v2->mRoot.mChild[0] = z;
  else
    v2->mRoot.mChild[1] = z;
}

// File Line: 165
// RVA: 0x17A0F0
void __fastcall UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        UFG::qBaseTreeVariableRB<unsigned __int64> *this,
        UFG::qBaseNodeVariableRB<unsigned __int64> *z)
{
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNULL; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *i; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v7; // r8
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *mParent; // r9
  UFG::qBaseNodeVariableRB<unsigned __int64> *v11; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v12; // rdx
  int v13; // r10d
  int v14; // eax
  unsigned __int64 v15; // r9
  char v16; // r10
  __int64 v17; // rax

  if ( z && ((unsigned __int64)z->mParent & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    p_mNULL = &this->mNULL;
    if ( z->mChild[0] == &this->mNULL || (v5 = z->mChild[1], v5 == p_mNULL) )
    {
      v5 = z;
    }
    else
    {
      for ( i = v5->mChild[0]; i != p_mNULL; i = i->mChild[0] )
        v5 = i;
    }
    v7 = v5->mChild[0];
    if ( v7 == p_mNULL )
      v7 = v5->mChild[1];
    v8 = (unsigned __int64)v5->mParent & 0xFFFFFFFFFFFFFFFEui64;
    v9 = v8 | (__int64)v7->mParent & 1;
    v7->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v9;
    if ( this == (UFG::qBaseTreeVariableRB<unsigned __int64> *)(v9 & 0xFFFFFFFFFFFFFFFEui64) )
      this->mRoot.mChild[0] = v7;
    else
      *(_QWORD *)(v8 + 8i64 * (v5 != *(UFG::qBaseNodeVariableRB<unsigned __int64> **)(v8 + 8)) + 8) = v7;
    if ( v5 == z )
    {
      if ( ((__int64)v5->mParent & 1) == 0 )
        UFG::qBaseTreeVariableRB<unsigned __int64>::RemoveHelper(this, v7);
      v5->mChild[0] = 0i64;
      v5->mChild[1] = 0i64;
      v5->mParent = 0i64;
    }
    else
    {
      mParent = z->mParent;
      v11 = z->mChild[0];
      v12 = z->mChild[1];
      v13 = (int)z->mParent;
      v14 = (int)v5->mParent;
      v5->mChild[0] = v11;
      v5->mChild[1] = v12;
      v15 = (unsigned __int64)mParent & 0xFFFFFFFFFFFFFFFEui64;
      v16 = v13 & 1;
      v5->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v15 | v14 & 1);
      v11->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)v5 | (__int64)v11->mParent & 1);
      v12->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)v5 | (__int64)v12->mParent & 1);
      if ( z == *(UFG::qBaseNodeVariableRB<unsigned __int64> **)(v15 + 8) )
        *(_QWORD *)(v15 + 8) = v5;
      else
        *(_QWORD *)(v15 + 16) = v5;
      v17 = v16 & 1;
      if ( ((__int64)v5->mParent & 1) != 0 )
      {
        v5->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)v5->mParent & ~1ui64);
        v5->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((__int64)v5->mParent | v17);
      }
      else
      {
        v5->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)v5->mParent & ~1ui64);
        v5->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((__int64)v5->mParent | v17);
        UFG::qBaseTreeVariableRB<unsigned __int64>::RemoveHelper(this, v7);
      }
      z->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((__int64)z->mParent & 1);
      z->mChild[0] = 0i64;
      z->mChild[1] = 0i64;
      z->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)z->mParent & ~1ui64);
    }
    --this->mCount;
  }
}

// File Line: 357
// RVA: 0x16EFB0
UFG::qBaseTreeRB *__fastcall UFG::qBaseTreeRB::Get(UFG::qBaseTreeRB *this, unsigned int uid)
{
  UFG::qBaseTreeRB *result; // rax
  bool i; // zf
  unsigned int mUID; // r8d
  UFG::qBaseTreeRB *j; // rcx

  result = this;
  for ( i = this == (UFG::qBaseTreeRB *)&this->mNULL; ; i = result == (UFG::qBaseTreeRB *)&this->mNULL )
  {
    if ( i )
      return 0i64;
    mUID = result->mRoot.mUID;
    if ( result != this && mUID == uid )
      break;
    if ( uid > mUID )
      result = (UFG::qBaseTreeRB *)result->mRoot.mChild[1];
    else
      result = (UFG::qBaseTreeRB *)result->mRoot.mChild[0];
  }
  for ( j = (UFG::qBaseTreeRB *)result->mRoot.mChild[0]; j; j = (UFG::qBaseTreeRB *)j->mRoot.mChild[0] )
  {
    if ( j->mRoot.mUID != uid )
      break;
    result = j;
  }
  return result;
}

// File Line: 394
// RVA: 0x16A9E0
bool __fastcall UFG::qBaseTreeRB::Contains(UFG::qBaseTreeRB *this, UFG::qBaseNodeRB *node)
{
  UFG::qBaseNodeRB *i; // rax

  if ( ((unsigned __int64)node->mParent & 0xFFFFFFFFFFFFFFFEui64) == 0 )
    return 0;
  for ( i = node->mChild[0]; i != node; i = i->mChild[0] )
    node = i;
  return node == &this->mNULL;
}

// File Line: 518
// RVA: 0x1725F0
UFG::qBaseNodeRB *__fastcall UFG::qBaseTreeRB::GetTail(UFG::qBaseTreeRB *this)
{
  UFG::qBaseNodeRB *v1; // rdx
  UFG::qBaseNodeRB *p_mNULL; // rcx
  UFG::qBaseNodeRB *i; // rax
  UFG::qBaseNodeRB *result; // rax

  v1 = this->mRoot.mChild[0];
  p_mNULL = &this->mNULL;
  for ( i = v1->mChild[1]; i != p_mNULL; i = i->mChild[1] )
    v1 = i;
  result = 0i64;
  if ( v1 != p_mNULL )
    return v1;
  return result;
}

// File Line: 534
// RVA: 0x171440
UFG::qBaseTreeRB *__fastcall UFG::qBaseTreeRB::GetNext(UFG::qBaseTreeRB *this, UFG::qBaseNodeRB *x)
{
  UFG::qBaseTreeRB *v2; // r8
  UFG::qBaseNodeRB *p_mNULL; // r9
  UFG::qBaseTreeRB *i; // rax
  UFG::qBaseTreeRB *result; // rax
  UFG::qBaseTreeRB *v7; // rcx

  v2 = (UFG::qBaseTreeRB *)x->mChild[1];
  p_mNULL = &this->mNULL;
  if ( &this->mNULL == (UFG::qBaseNodeRB *)v2 )
  {
    result = (UFG::qBaseTreeRB *)((unsigned __int64)x->mParent & 0xFFFFFFFFFFFFFFFEui64);
    if ( x == result->mRoot.mChild[1] )
    {
      do
      {
        v7 = result;
        result = (UFG::qBaseTreeRB *)((unsigned __int64)result->mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
      }
      while ( v7 == (UFG::qBaseTreeRB *)result->mRoot.mChild[1] );
    }
    if ( result == this )
      return 0i64;
  }
  else
  {
    for ( i = (UFG::qBaseTreeRB *)v2->mRoot.mChild[0];
          i != (UFG::qBaseTreeRB *)p_mNULL;
          i = (UFG::qBaseTreeRB *)i->mRoot.mChild[0] )
    {
      v2 = i;
    }
    return v2;
  }
  return result;
}

