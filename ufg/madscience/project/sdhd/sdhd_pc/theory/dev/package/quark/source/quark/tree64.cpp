// File Line: 23
// RVA: 0x17BCD0
void __fastcall UFG::qTree64Base::BaseNode::Rotate(UFG::qTree64Base::BaseNode *this, UFG::qTree64Base::Side s)
{
  __int64 v3; // rdi
  int v4; // r10d
  int v5; // r11d
  unsigned __int64 v6; // r8
  unsigned __int64 *v7; // rdx
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rdx

  v3 = s;
  v4 = 1 - s;
  v5 = (LODWORD(this->mParent) >> 1) & 1;
  v6 = (unsigned __int64)this->mParent & 0xFFFFFFFFFFFFFFFCui64;
  v7 = &this->mUID + 1 - s;
  v8 = v7[2];
  v9 = (unsigned __int64)this & 0xFFFFFFFFFFFFFFFCui64;
  v10 = *(_QWORD *)(v8 + 8 * v3 + 16);
  v7[2] = v10;
  *(_QWORD *)(v10 + 8) &= 3ui64;
  *(_QWORD *)(v10 + 8) |= v9;
  v11 = v7[2];
  *(_QWORD *)(v11 + 8) &= ~2ui64;
  *(_QWORD *)(v11 + 8) |= 2 * v4;
  *(_QWORD *)(v8 + 8) &= 1ui64;
  *(_QWORD *)(v8 + 8) |= v6 | (2 * v5);
  *(_QWORD *)(((unsigned __int64)this->mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * v5 + 16) = v8;
  *(_QWORD *)(v8 + 8 * v3 + 16) = this;
  this->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)this->mParent & 1);
  this->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)this->mParent | v8 & 0xFFFFFFFFFFFFFFFCui64 | (2 * (int)v3));
}

// File Line: 71
// RVA: 0x18DF20
void __fastcall UFG::qTree64Base::BaseNode::switch_with(
        UFG::qTree64Base::BaseNode *this,
        UFG::qTree64Base::BaseNode *node)
{
  unsigned __int64 mParent_low; // r8
  __int64 v4; // r8
  UFG::qTree64Base::BaseNode *v5; // rax
  unsigned __int64 v6; // rcx
  UFG::qTree64Base::BaseNode *v7; // rax

  mParent_low = LODWORD(node->mParent);
  *(_OWORD *)this->mChildren = *(_OWORD *)node->mChildren;
  v4 = (mParent_low >> 1) & 1;
  this->mParent = (UFG::qTree64Base::BaseNode *)((__int64)this->mParent & 1 | (unsigned __int64)node->mParent & 0xFFFFFFFFFFFFFFFCui64 | (2 * (int)v4));
  v5 = node->mChildren[0];
  v5->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v5->mParent & 3);
  v6 = (unsigned __int64)this & 0xFFFFFFFFFFFFFFFCui64;
  v5->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v5->mParent | v6);
  node->mChildren[0]->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)node->mChildren[0]->mParent & ~2ui64);
  v7 = node->mChildren[1];
  v7->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v7->mParent & 3);
  v7->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v7->mParent | v6);
  node->mChildren[1]->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)node->mChildren[1]->mParent | 2);
  *(_QWORD *)(((unsigned __int64)node->mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (int)v4 + 16) = this;
  this->mParent = (UFG::qTree64Base::BaseNode *)((__int64)this->mParent ^ (LODWORD(this->mParent) ^ LODWORD(node->mParent)) & 1);
}

// File Line: 107
// RVA: 0x16AA20
bool __fastcall UFG::qTree64Base::Contains(UFG::qTree64Base *this, unsigned __int64 key)
{
  UFG::qTree64Base *v2; // rax

  v2 = (UFG::qTree64Base *)this->mHead.mChildren[0];
  while ( v2 != this )
  {
    if ( v2->mHead.mUID >= key )
    {
      if ( v2->mHead.mUID <= key )
        return v2 != 0i64;
      v2 = (UFG::qTree64Base *)v2->mHead.mChildren[0];
    }
    else
    {
      v2 = (UFG::qTree64Base *)v2->mHead.mChildren[1];
    }
  }
  v2 = 0i64;
  return v2 != 0i64;
}

// File Line: 115
// RVA: 0x16F0F0
UFG::qTree64Base *__fastcall UFG::qTree64Base::Get(UFG::qTree64Base *this, unsigned __int64 key)
{
  UFG::qTree64Base *result; // rax

  result = (UFG::qTree64Base *)this->mHead.mChildren[0];
  while ( result != this )
  {
    if ( result->mHead.mUID >= key )
    {
      if ( result->mHead.mUID <= key )
        return result;
      result = (UFG::qTree64Base *)result->mHead.mChildren[0];
    }
    else
    {
      result = (UFG::qTree64Base *)result->mHead.mChildren[1];
    }
  }
  return 0i64;
}

// File Line: 191
// RVA: 0x170B10
UFG::qTree64Base *__fastcall UFG::qTree64Base::GetHead(UFG::qTree64Base *this)
{
  UFG::qTree64Base *v1; // rdx
  UFG::qTree64Base *i; // rax

  v1 = (UFG::qTree64Base *)this->mHead.mChildren[0];
  if ( v1 == this )
    return 0i64;
  for ( i = (UFG::qTree64Base *)v1->mHead.mChildren[0]; i != this; i = (UFG::qTree64Base *)i->mHead.mChildren[0] )
    v1 = i;
  return v1;
}

// File Line: 233
// RVA: 0x1714A0
UFG::qTree64Base *__fastcall UFG::qTree64Base::GetNext(UFG::qTree64Base *this, UFG::qTree64Base::BaseNode *cur_node)
{
  UFG::qTree64Base *result; // rax
  UFG::qTree64Base::BaseNode *mParent; // rdx
  UFG::qTree64Base::BaseNode *v5; // rax
  UFG::qTree64Base *v6; // rcx
  UFG::qTree64Base *v7; // rax
  __int64 v8; // rcx
  char v9; // cl
  __int64 v10; // rcx

  result = (UFG::qTree64Base *)cur_node->mNeighbours[1];
  mParent = result->mHead.mParent;
  if ( ((unsigned __int64)mParent & 0xFFFFFFFFFFFFFFFCui64) == 0 )
    return result;
  v5 = result->mHead.mChildren[1];
  if ( v5 == v5->mChildren[1] )
  {
    v5 = (UFG::qTree64Base::BaseNode *)((unsigned __int64)mParent & 0xFFFFFFFFFFFFFFFCui64);
    if ( ((unsigned __int8)mParent & 2) != 0 )
    {
      do
      {
        v9 = (unsigned __int8)LODWORD(v5->mParent) >> 1;
        v5 = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v5->mParent & 0xFFFFFFFFFFFFFFFCui64);
      }
      while ( (v9 & 1) != 0 );
    }
  }
  else
  {
    v6 = (UFG::qTree64Base *)v5->mChildren[0];
    if ( v6 != (UFG::qTree64Base *)v6->mHead.mChildren[1] )
    {
      do
      {
        v7 = v6;
        v6 = (UFG::qTree64Base *)v6->mHead.mChildren[0];
      }
      while ( v6 != (UFG::qTree64Base *)v6->mHead.mChildren[1] );
      v8 = 0i64;
      if ( v7 != this )
        return v7;
      return (UFG::qTree64Base *)v8;
    }
  }
  v10 = 0i64;
  if ( v5 != (UFG::qTree64Base::BaseNode *)this )
    return (UFG::qTree64Base *)v5;
  return (UFG::qTree64Base *)v10;
}

// File Line: 320
// RVA: 0x165C90
void __fastcall UFG::qTree64Base::Add(UFG::qTree64Base *this, UFG::qTree64Base::BaseNode *node)
{
  UFG::qTree64Base *v3; // rdx
  UFG::qTree64Base *v5; // r10
  int v6; // r8d
  unsigned __int64 mUID; // r9
  __int64 v8; // rax
  UFG::qTree64Base::BaseNode *v9; // rdx
  UFG::qTree64Base::BaseNode *v10; // rax
  _QWORD *i; // rbx
  unsigned __int64 v12; // rdi
  __int64 v13; // rdx
  int v14; // r14d
  __int64 v15; // r15
  __int64 v16; // rcx
  UFG::qTree64Base::BaseNode *v17; // rax
  unsigned __int64 v18; // r10
  unsigned __int64 v19; // r11
  __int64 v20; // r10
  unsigned __int64 v21; // r8
  __int64 v22; // rbx
  __int64 v23; // rdx
  __int64 v24; // r8

  ++this->mCount;
  v3 = (UFG::qTree64Base *)this->mHead.mChildren[0];
  v5 = this;
  v6 = 0;
  if ( v3 != this )
  {
    mUID = node->mUID;
    do
    {
      v8 = 1i64;
      v5 = v3;
      v6 = 1;
      if ( mUID >= v3->mHead.mUID )
      {
        if ( mUID <= v3->mHead.mUID )
        {
          v17 = v3->mHead.mNeighbours[0];
          node->mNeighbours[1] = &v3->mHead;
          node->mNeighbours[0] = v17;
          v3->mHead.mNeighbours[0] = node;
          node->mNeighbours[0]->mNeighbours[1] = node;
          node->mChildren[0] = 0i64;
          node->mChildren[1] = 0i64;
          node->mParent = (UFG::qTree64Base::BaseNode *)1;
          return;
        }
      }
      else
      {
        v6 = 0;
        v8 = 0i64;
      }
      v3 = (UFG::qTree64Base *)v3->mHead.mChildren[v8];
    }
    while ( v3 != this );
  }
  v9 = v5->mHead.mChildren[v6];
  v5->mHead.mChildren[v6] = node;
  node->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)node->mParent & 1);
  node->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)node->mParent | (unsigned __int64)v5 & 0xFFFFFFFFFFFFFFFCui64 | (2 * v6));
  node->mNeighbours[0] = node;
  node->mNeighbours[1] = node;
  node->mChildren[0] = v9;
  node->mChildren[1] = v9;
  node->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)node->mParent | 1);
  v10 = (UFG::qTree64Base::BaseNode *)((unsigned __int64)node->mParent & 0xFFFFFFFFFFFFFFFCui64);
  for ( i = &v10->mParent; ((__int64)v10->mParent & 1) != 0; i = &v10->mParent )
  {
    v12 = *i & 0xFFFFFFFFFFFFFFFCui64;
    v13 = (*i >> 1) & 1i64;
    v14 = 1 - v13;
    v15 = 8i64 * (1 - (int)v13) + 16;
    v16 = *(_QWORD *)(v15 + v12);
    if ( (*(_BYTE *)(v16 + 8) & 1) != 0 )
    {
      node = (UFG::qTree64Base::BaseNode *)(*i & 0xFFFFFFFFFFFFFFFCui64);
      *i &= ~1ui64;
      *(_QWORD *)(v16 + 8) &= ~1ui64;
      *(_QWORD *)(v12 + 8) |= 1ui64;
      v10 = (UFG::qTree64Base::BaseNode *)(*(_QWORD *)(v12 + 8) & 0xFFFFFFFFFFFFFFFCui64);
    }
    else
    {
      if ( node == *(UFG::qTree64Base::BaseNode **)((char *)&v10->mUID + v15) )
      {
        node = v10;
        UFG::qTree64Base::BaseNode::Rotate(v10, (UFG::qTree64Base::Side)v13);
        v10 = (UFG::qTree64Base::BaseNode *)(*i & 0xFFFFFFFFFFFFFFFCui64);
      }
      v10->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v10->mParent & ~1ui64);
      *(_QWORD *)(v12 + 8) |= 1ui64;
      v18 = *(_QWORD *)(v12 + 8);
      v19 = v18 & 0xFFFFFFFFFFFFFFFCui64;
      v20 = (v18 >> 1) & 1;
      v21 = v12 + 8i64 * (1 - v14);
      v22 = *(_QWORD *)(v21 + 16);
      v23 = *(_QWORD *)(v15 + v22);
      *(_QWORD *)(v21 + 16) = v23;
      *(_QWORD *)(v23 + 8) &= 3ui64;
      *(_QWORD *)(v23 + 8) |= v12 & 0xFFFFFFFFFFFFFFFCui64;
      v24 = *(_QWORD *)(v21 + 16);
      *(_QWORD *)(v24 + 8) &= ~2ui64;
      *(_QWORD *)(v24 + 8) |= 2 * (1 - v14);
      *(_QWORD *)(v22 + 8) &= 1ui64;
      *(_QWORD *)(v22 + 8) |= v19 | (2 * (int)v20);
      *(_QWORD *)((*(_QWORD *)(v12 + 8) & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (int)v20 + 16) = v22;
      *(_QWORD *)(v15 + v22) = v12;
      *(_QWORD *)(v12 + 8) &= 1ui64;
      *(_QWORD *)(v12 + 8) |= v22 & 0xFFFFFFFFFFFFFFFCui64 | (2 * v14);
    }
  }
  this->mHead.mChildren[0]->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)this->mHead.mChildren[0]->mParent & ~1ui64);
}ldren[0]->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)this->mHead.mChi

// File Line: 395
// RVA: 0x17A580
void __fastcall UFG::qTree64Base::Remove(UFG::qTree64Base *this, UFG::qTree64Base *node)
{
  UFG::qTree64Base::BaseNode *v3; // rcx
  UFG::qTree64Base *v5; // rax
  int v6; // ecx
  UFG::qTree64Base *v7; // r9
  UFG::qTree64Base *i; // rax
  char mParent; // r10
  UFG::qTree64Base::BaseNode *v10; // rsi
  UFG::qTree64Base::BaseNode *v11; // r8
  unsigned __int64 v12; // rdx
  char v13; // r10
  __int64 v14; // r8
  unsigned __int64 mParent_low; // rdx
  __int64 v16; // rdx
  UFG::qTree64Base::BaseNode *v17; // rax
  UFG::qTree64Base::BaseNode *v18; // rax
  UFG::qTree64Base::BaseNode *v19; // rsi
  __int64 v20; // rbp
  __int64 v21; // r12
  UFG::qTree64Base::BaseNode *v22; // rbx
  unsigned __int64 *v23; // rdi
  UFG::qTree64Base::BaseNode *v24; // rdi

  if ( node )
  {
    --this->mCount;
    v3 = node->mHead.mNeighbours[0];
    if ( v3 == (UFG::qTree64Base::BaseNode *)node )
    {
      v5 = (UFG::qTree64Base *)node->mHead.mChildren[1];
      v6 = 0;
      v7 = node;
      if ( v5 != this )
      {
        if ( (UFG::qTree64Base *)node->mHead.mChildren[0] != this )
        {
          v7 = (UFG::qTree64Base *)node->mHead.mChildren[1];
          for ( i = (UFG::qTree64Base *)v5->mHead.mChildren[0]; i != this; i = (UFG::qTree64Base *)i->mHead.mChildren[0] )
            v7 = i;
        }
        v6 = 1;
      }
      mParent = (char)v7->mHead.mParent;
      v10 = v7->mHead.mChildren[v6];
      v11 = v7->mHead.mParent;
      v12 = (unsigned __int64)v11 & 0xFFFFFFFFFFFFFFFCui64;
      v10->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v10->mParent & 1);
      v13 = mParent & 1;
      v14 = ((unsigned __int64)v11 >> 1) & 1;
      v10->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v10->mParent | v12 | (2 * (int)v14));
      *(_QWORD *)(((unsigned __int64)v7->mHead.mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (int)v14 + 16) = v10;
      if ( v7 != node )
      {
        mParent_low = LODWORD(node->mHead.mParent);
        v7->mHead.mChildren[0] = node->mHead.mChildren[0];
        v7->mHead.mChildren[1] = node->mHead.mChildren[1];
        v16 = (mParent_low >> 1) & 1;
        v7->mHead.mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)node->mHead.mParent & 0xFFFFFFFFFFFFFFFCui64 | (__int64)v7->mHead.mParent & 1 | (unsigned __int64)(2 * (int)v16));
        v17 = node->mHead.mChildren[0];
        v17->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v17->mParent & 3);
        v17->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v17->mParent | (unsigned __int64)v7 & 0xFFFFFFFFFFFFFFFCui64);
        node->mHead.mChildren[0]->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)node->mHead.mChildren[0]->mParent & ~2ui64);
        v18 = node->mHead.mChildren[1];
        v18->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v18->mParent & 3);
        v18->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v18->mParent | (unsigned __int64)v7 & 0xFFFFFFFFFFFFFFFCui64);
        node->mHead.mChildren[1]->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)node->mHead.mChildren[1]->mParent | 2);
        *(_QWORD *)(((unsigned __int64)node->mHead.mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (int)v16 + 16) = v7;
        v7->mHead.mParent = (UFG::qTree64Base::BaseNode *)((__int64)v7->mHead.mParent ^ (LODWORD(v7->mHead.mParent) ^ LODWORD(node->mHead.mParent)) & 1);
      }
      if ( !v13 )
      {
        while ( ((__int64)v10->mParent & 1) == 0 )
        {
          if ( v10 == this->mHead.mChildren[0] )
            break;
          v19 = v10->mParent;
          v20 = ((unsigned __int64)v19 >> 1) & 1;
          v10 = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v19 & 0xFFFFFFFFFFFFFFFCui64);
          v21 = 8i64 * (1 - (int)v20) + 16;
          v22 = *(UFG::qTree64Base::BaseNode **)((char *)&v10->mUID + v21);
          if ( ((__int64)v22->mParent & 1) != 0 )
          {
            v22->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v22->mParent & ~1ui64);
            v10->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v10->mParent | 1);
            v22 = v22->mChildren[(int)v20];
            UFG::qTree64Base::BaseNode::Rotate(v10, (UFG::qTree64Base::Side)v20);
          }
          if ( ((__int64)v22->mChildren[0]->mParent & 1) != 0 || ((__int64)v22->mChildren[1]->mParent & 1) != 0 )
          {
            if ( (*(_BYTE *)(*(unsigned __int64 *)((char *)&v22->mUID + v21) + 8) & 1) == 0 )
            {
              v23 = &v22->mUID + (int)v20;
              *(_QWORD *)(v23[2] + 8) &= ~1ui64;
              v22->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v22->mParent | 1);
              v24 = (UFG::qTree64Base::BaseNode *)v23[2];
              UFG::qTree64Base::BaseNode::Rotate(v22, (UFG::qTree64Base::Side)(1 - v20));
              v22 = v24;
            }
            v22->mParent = (UFG::qTree64Base::BaseNode *)((__int64)v22->mParent ^ (LODWORD(v22->mParent) ^ LODWORD(v10->mParent)) & 1);
            v10->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v10->mParent & ~1ui64);
            *(_QWORD *)(*(unsigned __int64 *)((char *)&v22->mUID + v21) + 8) &= ~1ui64;
            UFG::qTree64Base::BaseNode::Rotate(v10, (UFG::qTree64Base::Side)v20);
            v10 = this->mHead.mChildren[0];
          }
          else
          {
            v22->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v22->mParent | 1);
          }
        }
        v10->mParent = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v10->mParent & ~1ui64);
      }
    }
    else if ( ((unsigned __int64)node->mHead.mParent & 0xFFFFFFFFFFFFFFFCui64) != 0 )
    {
      UFG::qTree64Base::BaseNode::switch_with(node->mHead.mNeighbours[1], &node->mHead);
      node->mHead.mNeighbours[1]->mNeighbours[0] = node->mHead.mNeighbours[0];
      node->mHead.mNeighbours[0]->mNeighbours[1] = node->mHead.mNeighbours[1];
    }
    else
    {
      node->mHead.mNeighbours[1]->mNeighbours[0] = v3;
      node->mHead.mNeighbours[0]->mNeighbours[1] = node->mHead.mNeighbours[1];
    }
  }
}

