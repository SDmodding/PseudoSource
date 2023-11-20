// File Line: 23
// RVA: 0x17BCD0
void __fastcall UFG::qTree64Base::BaseNode::Rotate(UFG::qTree64Base::BaseNode *this, UFG::qTree64Base::Side s)
{
  UFG::qTree64Base::BaseNode *v2; // rsi
  __int64 v3; // rdi
  __int32 v4; // er10
  int v5; // er11
  unsigned __int64 v6; // r8
  unsigned __int64 *v7; // rdx
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rdx

  v2 = this;
  v3 = s;
  v4 = 1 - s;
  v5 = (LODWORD(this->mParent) >> 1) & 1;
  v6 = (_QWORD)this->mParent & 0xFFFFFFFFFFFFFFFCui64;
  v7 = &this->mUID + 1 - s;
  v8 = v7[2];
  v9 = (unsigned __int64)this & 0xFFFFFFFFFFFFFFFCui64;
  v10 = *(_QWORD *)(v8 + 8 * v3 + 16);
  v7[2] = v10;
  *(_QWORD *)(v10 + 8) &= 3ui64;
  *(_QWORD *)(v10 + 8) |= v9;
  v11 = v7[2];
  *(_QWORD *)(v11 + 8) &= 0xFFFFFFFFFFFFFFFDui64;
  *(_QWORD *)(v11 + 8) |= 2 * v4;
  *(_QWORD *)(v8 + 8) &= 1ui64;
  *(_QWORD *)(v8 + 8) |= v6 | 2 * v5;
  *(_QWORD *)(((_QWORD)v2->mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * v5 + 16) = v8;
  *(_QWORD *)(v8 + 8 * v3 + 16) = v2;
  v2->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v2->mParent & 1i64);
  v2->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v2->mParent | v8 & 0xFFFFFFFFFFFFFFFCui64 | 2 * (signed int)v3);
}

// File Line: 71
// RVA: 0x18DF20
void __fastcall UFG::qTree64Base::BaseNode::switch_with(UFG::qTree64Base::BaseNode *this, UFG::qTree64Base::BaseNode *node)
{
  unsigned __int64 v2; // r8
  UFG::qTree64Base::BaseNode *v3; // r9
  signed __int64 v4; // r8
  UFG::qTree64Base::BaseNode *v5; // rax
  unsigned __int64 v6; // rcx
  UFG::qTree64Base::BaseNode *v7; // rax

  v2 = LODWORD(node->mParent);
  v3 = this;
  this->mChildren[0] = node->mChildren[0];
  this->mChildren[1] = node->mChildren[1];
  v4 = (v2 >> 1) & 1;
  this->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)this->mParent & 1 | (_QWORD)node->mParent & 0xFFFFFFFFFFFFFFFCui64 | 2 * (signed int)v4);
  v5 = node->mChildren[0];
  v5->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v5->mParent & 3i64);
  v6 = (unsigned __int64)this & 0xFFFFFFFFFFFFFFFCui64;
  v5->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v5->mParent | v6);
  node->mChildren[0]->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)node->mChildren[0]->mParent & 0xFFFFFFFFFFFFFFFDui64);
  v7 = node->mChildren[1];
  v7->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v7->mParent & 3i64);
  v7->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v7->mParent | v6);
  node->mChildren[1]->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)node->mChildren[1]->mParent | 2i64);
  *(_QWORD *)(((_QWORD)node->mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (signed int)v4 + 16) = v3;
  v3->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v3->mParent ^ (LODWORD(v3->mParent) ^ LODWORD(node->mParent)) & 1);
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
  UFG::qTree64Base *v3; // r9
  UFG::qTree64Base::BaseNode *v4; // rdx
  unsigned __int64 v5; // r8
  UFG::qTree64Base::BaseNode *v6; // rax
  UFG::qTree64Base::BaseNode *v7; // rcx
  UFG::qTree64Base *v8; // rax
  UFG::qTree64Base *v9; // rcx
  char v10; // cl
  UFG::qTree64Base::BaseNode *v11; // rcx

  result = (UFG::qTree64Base *)cur_node->mNeighbours[1];
  v3 = this;
  v4 = result->mHead.mParent;
  v5 = (_QWORD)result->mHead.mParent & 0xFFFFFFFFFFFFFFFCui64;
  if ( !v5 )
    return result;
  v6 = result->mHead.mChildren[1];
  if ( v6 == v6->mChildren[1] )
  {
    v6 = (UFG::qTree64Base::BaseNode *)v5;
    if ( ((unsigned __int8)v4 >> 1) & 1 )
    {
      do
      {
        v10 = (unsigned __int8)LODWORD(v6->mParent) >> 1;
        v6 = (UFG::qTree64Base::BaseNode *)((_QWORD)v6->mParent & 0xFFFFFFFFFFFFFFFCui64);
      }
      while ( v10 & 1 );
    }
  }
  else
  {
    v7 = v6->mChildren[0];
    if ( v7 != v7->mChildren[1] )
    {
      do
      {
        v8 = (UFG::qTree64Base *)v7;
        v7 = v7->mChildren[0];
      }
      while ( v7 != v7->mChildren[1] );
      v9 = 0i64;
      if ( v8 != v3 )
        v9 = v8;
      return v9;
    }
  }
  v11 = 0i64;
  if ( v6 != (UFG::qTree64Base::BaseNode *)v3 )
    v11 = v6;
  return (UFG::qTree64Base *)v11;
}

// File Line: 320
// RVA: 0x165C90
void __fastcall UFG::qTree64Base::Add(UFG::qTree64Base *this, UFG::qTree64Base::BaseNode *node)
{
  UFG::qTree64Base::BaseNode *v2; // rsi
  UFG::qTree64Base *v3; // rdx
  UFG::qTree64Base *v4; // rbp
  UFG::qTree64Base *v5; // r10
  signed int v6; // er8
  unsigned __int64 v7; // r9
  signed __int64 v8; // rax
  UFG::qTree64Base::BaseNode *v9; // rdx
  UFG::qTree64Base::BaseNode *v10; // rax
  UFG::qTree64Base::BaseNode **i; // rbx
  unsigned __int64 v12; // rdi
  signed __int64 v13; // rdx
  int v14; // er14
  signed __int64 v15; // r15
  __int64 v16; // rcx
  UFG::qTree64Base::BaseNode *v17; // rax
  __int64 v18; // r11
  signed __int64 v19; // r10
  signed __int64 v20; // r8
  __int64 v21; // rbx
  __int64 v22; // rdx
  __int64 v23; // r8

  ++this->mCount;
  v2 = node;
  v3 = (UFG::qTree64Base *)this->mHead.mChildren[0];
  v4 = this;
  v5 = this;
  v6 = 0;
  if ( v3 != this )
  {
    v7 = v2->mUID;
    do
    {
      v8 = 1i64;
      v5 = v3;
      v6 = 1;
      if ( v7 >= v3->mHead.mUID )
      {
        if ( v7 <= v3->mHead.mUID )
        {
          v17 = v3->mHead.mNeighbours[0];
          v2->mNeighbours[1] = &v3->mHead;
          v2->mNeighbours[0] = v17;
          v3->mHead.mNeighbours[0] = v2;
          v2->mNeighbours[0]->mNeighbours[1] = v2;
          v2->mChildren[0] = 0i64;
          v2->mChildren[1] = 0i64;
          v2->mParent = (UFG::qTree64Base::BaseNode *)1;
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
  v5->mHead.mChildren[v6] = v2;
  v2->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v2->mParent & 1i64);
  v2->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v2->mParent | (unsigned __int64)v5 & 0xFFFFFFFFFFFFFFFCui64 | 2 * v6);
  v2->mNeighbours[0] = v2;
  v2->mNeighbours[1] = v2;
  v2->mChildren[0] = v9;
  v2->mChildren[1] = v9;
  v2->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v2->mParent | 1i64);
  v10 = (UFG::qTree64Base::BaseNode *)((_QWORD)v2->mParent & 0xFFFFFFFFFFFFFFFCui64);
  for ( i = &v10->mParent; (_QWORD)v10->mParent & 1; i = &v10->mParent )
  {
    v12 = (unsigned __int64)*i & 0xFFFFFFFFFFFFFFFCui64;
    v13 = ((unsigned __int64)*i >> 1) & 1;
    v14 = 1 - v13;
    v15 = 8i64 * (1 - (signed int)v13) + 16;
    v16 = *(_QWORD *)(v15 + v12);
    if ( *(_BYTE *)(v16 + 8) & 1 )
    {
      v2 = (UFG::qTree64Base::BaseNode *)((unsigned __int64)*i & 0xFFFFFFFFFFFFFFFCui64);
      *i = (UFG::qTree64Base::BaseNode *)((unsigned __int64)*i & 0xFFFFFFFFFFFFFFFEui64);
      *(_QWORD *)(v16 + 8) &= 0xFFFFFFFFFFFFFFFEui64;
      *(_QWORD *)(v12 + 8) |= 1ui64;
      v10 = (UFG::qTree64Base::BaseNode *)(*(_QWORD *)(v12 + 8) & 0xFFFFFFFFFFFFFFFCui64);
    }
    else
    {
      if ( v2 == *(UFG::qTree64Base::BaseNode **)((char *)&v10->mUID + v15) )
      {
        v2 = v10;
        UFG::qTree64Base::BaseNode::Rotate(v10, (UFG::qTree64Base::Side)v13);
        v10 = (UFG::qTree64Base::BaseNode *)((unsigned __int64)*i & 0xFFFFFFFFFFFFFFFCui64);
      }
      v10->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v10->mParent & 0xFFFFFFFFFFFFFFFEui64);
      *(_QWORD *)(v12 + 8) |= 1ui64;
      v18 = *(_QWORD *)(v12 + 8);
      v19 = (*(_QWORD *)(v12 + 8) >> 1) & 1i64;
      v20 = v12 + 8i64 * (1 - v14);
      v21 = *(_QWORD *)(v20 + 16);
      v22 = *(_QWORD *)(v15 + v21);
      *(_QWORD *)(v20 + 16) = v22;
      *(_QWORD *)(v22 + 8) &= 3ui64;
      *(_QWORD *)(v22 + 8) |= v12 & 0xFFFFFFFFFFFFFFFCui64;
      v23 = *(_QWORD *)(v20 + 16);
      *(_QWORD *)(v23 + 8) &= 0xFFFFFFFFFFFFFFFDui64;
      *(_QWORD *)(v23 + 8) |= 2 * (1 - v14);
      *(_QWORD *)(v21 + 8) &= 1ui64;
      *(_QWORD *)(v21 + 8) |= v18 & 0xFFFFFFFFFFFFFFFCui64 | 2 * (signed int)v19;
      *(_QWORD *)((*(_QWORD *)(v12 + 8) & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (signed int)v19 + 16) = v21;
      *(_QWORD *)(v15 + v21) = v12;
      *(_QWORD *)(v12 + 8) &= 1ui64;
      *(_QWORD *)(v12 + 8) |= v21 & 0xFFFFFFFFFFFFFFFCui64 | 2 * v14;
    }
  }
  v4->mHead.mChildren[0]->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v4->mHead.mChildren[0]->mParent & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 395
// RVA: 0x17A580
void __fastcall UFG::qTree64Base::Remove(UFG::qTree64Base *this, UFG::qTree64Base::BaseNode *node)
{
  UFG::qTree64Base *v2; // r14
  UFG::qTree64Base::BaseNode *v3; // rcx
  UFG::qTree64Base::BaseNode *v4; // rbx
  UFG::qTree64Base::BaseNode *v5; // rax
  signed int v6; // ecx
  UFG::qTree64Base *v7; // r9
  UFG::qTree64Base *i; // rax
  UFG::qTree64Base::BaseNode *v9; // rdx
  char v10; // r10
  UFG::qTree64Base::BaseNode *v11; // rsi
  UFG::qTree64Base::BaseNode *v12; // r8
  char v13; // r10
  signed __int64 v14; // r8
  unsigned __int64 v15; // rdx
  signed __int64 v16; // rdx
  UFG::qTree64Base::BaseNode *v17; // rax
  UFG::qTree64Base::BaseNode *v18; // rax
  UFG::qTree64Base::BaseNode *v19; // rbp
  UFG::qTree64Base::BaseNode *v20; // rsi
  signed __int64 v21; // rbp
  signed __int64 v22; // r12
  UFG::qTree64Base::BaseNode *v23; // rbx
  UFG::qTree64Base::BaseNode *v24; // rax
  UFG::qTree64Base::BaseNode *v25; // rdi

  if ( node )
  {
    --this->mCount;
    v2 = this;
    v3 = node->mNeighbours[0];
    v4 = node;
    if ( v3 == node )
    {
      v5 = node->mChildren[1];
      v6 = 0;
      v7 = (UFG::qTree64Base *)node;
      if ( v5 != (UFG::qTree64Base::BaseNode *)v2 )
      {
        if ( (UFG::qTree64Base *)node->mChildren[0] != v2 )
        {
          v7 = (UFG::qTree64Base *)node->mChildren[1];
          for ( i = (UFG::qTree64Base *)v5->mChildren[0]; i != v2; i = (UFG::qTree64Base *)i->mHead.mChildren[0] )
            v7 = i;
        }
        v6 = 1;
      }
      v9 = v7->mHead.mParent;
      v10 = (char)v7->mHead.mParent;
      v11 = v7->mHead.mChildren[v6];
      v12 = v7->mHead.mParent;
      v11->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v11->mParent & 1i64);
      v13 = v10 & 1;
      v14 = ((unsigned __int64)v12 >> 1) & 1;
      v11->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v11->mParent | (unsigned __int64)v9 & 0xFFFFFFFFFFFFFFFCui64 | 2 * (signed int)v14);
      *(_QWORD *)(((_QWORD)v7->mHead.mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (signed int)v14 + 16) = v11;
      if ( v7 != (UFG::qTree64Base *)v4 )
      {
        v15 = LODWORD(v4->mParent);
        v7->mHead.mChildren[0] = v4->mChildren[0];
        v7->mHead.mChildren[1] = v4->mChildren[1];
        v16 = (v15 >> 1) & 1;
        v7->mHead.mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v4->mParent & 0xFFFFFFFFFFFFFFFCui64 | (_QWORD)v7->mHead.mParent & 1 | (unsigned __int64)(2 * (signed int)v16));
        v17 = v4->mChildren[0];
        v17->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v17->mParent & 3i64);
        v17->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v17->mParent | (unsigned __int64)v7 & 0xFFFFFFFFFFFFFFFCui64);
        v4->mChildren[0]->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v4->mChildren[0]->mParent & 0xFFFFFFFFFFFFFFFDui64);
        v18 = v4->mChildren[1];
        v18->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v18->mParent & 3i64);
        v18->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v18->mParent | (unsigned __int64)v7 & 0xFFFFFFFFFFFFFFFCui64);
        v4->mChildren[1]->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v4->mChildren[1]->mParent | 2i64);
        *(_QWORD *)(((_QWORD)v4->mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (signed int)v16 + 16) = v7;
        v7->mHead.mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v7->mHead.mParent ^ (LODWORD(v7->mHead.mParent) ^ LODWORD(v4->mParent)) & 1);
      }
      if ( !v13 )
      {
        while ( !((_QWORD)v11->mParent & 1) )
        {
          if ( v11 == v2->mHead.mChildren[0] )
            break;
          v19 = v11->mParent;
          v20 = v19;
          v21 = ((unsigned __int64)v19 >> 1) & 1;
          v11 = (UFG::qTree64Base::BaseNode *)((unsigned __int64)v20 & 0xFFFFFFFFFFFFFFFCui64);
          v22 = 8i64 * (1 - (signed int)v21) + 16;
          v23 = *(UFG::qTree64Base::BaseNode **)((char *)&v11->mUID + v22);
          if ( (_QWORD)v23->mParent & 1 )
          {
            v23->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v23->mParent & 0xFFFFFFFFFFFFFFFEui64);
            v11->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v11->mParent | 1i64);
            v23 = v23->mChildren[(signed int)v21];
            UFG::qTree64Base::BaseNode::Rotate(v11, (UFG::qTree64Base::Side)v21);
          }
          if ( (_QWORD)v23->mChildren[0]->mParent & 1 || (_QWORD)v23->mChildren[1]->mParent & 1 )
          {
            if ( !(*(_BYTE *)(*(unsigned __int64 *)((char *)&v23->mUID + v22) + 8) & 1) )
            {
              v24 = v23->mChildren[(signed int)v21];
              v24->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v24->mParent & 0xFFFFFFFFFFFFFFFEui64);
              v23->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v23->mParent | 1i64);
              v25 = v23->mChildren[(signed int)v21];
              UFG::qTree64Base::BaseNode::Rotate(v23, (UFG::qTree64Base::Side)(1 - v21));
              v23 = v25;
            }
            v23->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v23->mParent ^ (LODWORD(v23->mParent) ^ LODWORD(v11->mParent)) & 1);
            v11->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v11->mParent & 0xFFFFFFFFFFFFFFFEui64);
            *(_QWORD *)(*(unsigned __int64 *)((char *)&v23->mUID + v22) + 8) &= 0xFFFFFFFFFFFFFFFEui64;
            UFG::qTree64Base::BaseNode::Rotate(v11, (UFG::qTree64Base::Side)v21);
            v11 = v2->mHead.mChildren[0];
          }
          else
          {
            v23->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v23->mParent | 1i64);
          }
        }
        v11->mParent = (UFG::qTree64Base::BaseNode *)((_QWORD)v11->mParent & 0xFFFFFFFFFFFFFFFEui64);
      }
    }
    else if ( (_QWORD)node->mParent & 0xFFFFFFFFFFFFFFFCui64 )
    {
      UFG::qTree64Base::BaseNode::switch_with(node->mNeighbours[1], node);
      v4->mNeighbours[1]->mNeighbours[0] = v4->mNeighbours[0];
      v4->mNeighbours[0]->mNeighbours[1] = v4->mNeighbours[1];
    }
    else
    {
      node->mNeighbours[1]->mNeighbours[0] = v3;
      node->mNeighbours[0]->mNeighbours[1] = node->mNeighbours[1];
    }
  }
}

