// File Line: 393
// RVA: 0x1625C0
void __fastcall UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::~intrusive_multi_rbtree<UFG::allocator::free_node>(UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *this)
{
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::clear(this);
}

// File Line: 415
// RVA: 0x180680
void __fastcall UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::clear(UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *this)
{
  UFG::intrusive_multi_rbtree_base::node_base *v1; // rax
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v2; // rdi
  UFG::allocator::free_node *i; // rdx
  unsigned __int64 v4; // rbx
  __int64 v5; // rax
  unsigned __int64 v6; // rcx
  _QWORD *j; // rax
  char v8; // al

  v1 = this->mHead.mChildren[0];
  v2 = this;
  for ( i = (UFG::allocator::free_node *)v1; v1 != v1->mChildren[1]; v1 = v1->mChildren[0] )
    i = (UFG::allocator::free_node *)v1;
  if ( i != (UFG::allocator::free_node *)this )
  {
    do
    {
      v4 = (unsigned __int64)i->mNeighbours[1];
      v5 = *(_QWORD *)(v4 + 32);
      v6 = *(_QWORD *)(v4 + 32) & 0xFFFFFFFFFFFFFFFCui64;
      if ( v6 )
      {
        v4 = *(_QWORD *)(v4 + 8);
        if ( v4 == *(_QWORD *)(v4 + 8) )
        {
          v4 = v6;
          if ( ((unsigned __int8)v5 >> 1) & 1 )
          {
            do
            {
              v8 = (unsigned __int8)*(_DWORD *)(v4 + 32) >> 1;
              v4 = *(_QWORD *)(v4 + 32) & 0xFFFFFFFFFFFFFFFCui64;
            }
            while ( v8 & 1 );
          }
        }
        else
        {
          for ( j = *(_QWORD **)v4; j != (_QWORD *)j[1]; j = (_QWORD *)*j )
            v4 = (unsigned __int64)j;
        }
      }
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(v2, i);
      i = (UFG::allocator::free_node *)v4;
    }
    while ( (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v4 != v2 );
  }
}

// File Line: 450
// RVA: 0x180C20
void __fastcall UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_insert(UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *this, UFG::allocator::free_node *node)
{
  UFG::intrusive_multi_rbtree_base::node_base *v2; // rax
  signed int v3; // er10
  UFG::allocator::free_node *v4; // r8
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v5; // r11
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v6; // rbx
  unsigned __int64 v7; // r9
  signed __int64 v8; // rdx
  unsigned __int64 v9; // rcx
  UFG::intrusive_multi_rbtree_base::node_base **v10; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v11; // rcx

  v2 = this->mHead.mChildren[0];
  v3 = 0;
  v4 = node;
  v5 = this;
  v6 = this;
  if ( (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)this->mHead.mChildren[0] == this )
  {
LABEL_7:
    v4->mNeighbours[0] = (UFG::intrusive_multi_rbtree_base::node_base *)v4->mChildren;
    v4->mNeighbours[1] = (UFG::intrusive_multi_rbtree_base::node_base *)v4->mChildren;
    v10 = &v6->mHead.mChildren[v3];
    v4->mChildren[0] = *v10;
    v4->mChildren[1] = *v10;
    v4->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v4->mParent & 1i64);
    v4->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v4->mParent | (unsigned __int64)v6 & 0xFFFFFFFFFFFFFFFCui64 | 2 * v3);
    *v10 = (UFG::intrusive_multi_rbtree_base::node_base *)v4->mChildren;
    v4->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v4->mParent | 1i64);
    UFG::intrusive_multi_rbtree_base::insert_fixup(
      (UFG::intrusive_multi_rbtree_base *)&v5->mHead,
      (UFG::intrusive_multi_rbtree_base::node_base *)v4->mChildren);
    return;
  }
  v7 = (_QWORD)node[-1].mNeighbours[1] & 0xFFFFFFFFFFFFFFFCui64;
  while ( 1 )
  {
    v8 = 1i64;
    v6 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v2;
    v9 = (_QWORD)v2[-1].mNeighbours[1] & 0xFFFFFFFFFFFFFFFCui64;
    v3 = 1;
    if ( v7 >= v9 )
      break;
    v3 = 0;
    v8 = 0i64;
LABEL_6:
    v2 = v2->mChildren[v8];
    if ( v2 == (UFG::intrusive_multi_rbtree_base::node_base *)v5 )
      goto LABEL_7;
  }
  if ( v7 > v9 )
    goto LABEL_6;
  v11 = v2->mNeighbours[0];
  v4->mNeighbours[1] = v2;
  v4->mNeighbours[0] = v11;
  v2->mNeighbours[0] = (UFG::intrusive_multi_rbtree_base::node_base *)v4->mChildren;
  v4->mNeighbours[0]->mNeighbours[1] = (UFG::intrusive_multi_rbtree_base::node_base *)v4->mChildren;
  v4->mChildren[0] = 0i64;
  v4->mChildren[1] = 0i64;
  v4->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)1;
}

// File Line: 472
// RVA: 0x180A00
void __fastcall UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *this, UFG::allocator::free_node *node)
{
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v2; // r11
  UFG::allocator::free_node *v3; // rcx
  UFG::allocator::free_node *v4; // r10
  UFG::intrusive_multi_rbtree_base::node_base *v5; // r8
  UFG::intrusive_multi_rbtree_base::node_base *v6; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v7; // rax
  unsigned __int64 v8; // rdx
  signed __int64 v9; // r8
  UFG::intrusive_multi_rbtree_base::node_base *v10; // rax
  UFG::intrusive_multi_rbtree_base::node_base *v11; // rax
  UFG::intrusive_multi_rbtree_base::node_base *v12; // rcx
  UFG::allocator::free_node *v13; // rax
  signed int v14; // edx
  UFG::allocator::free_node *i; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v16; // r8
  char v17; // di
  UFG::intrusive_multi_rbtree_base::node_base *v18; // rbx
  UFG::intrusive_multi_rbtree_base::node_base *v19; // r9
  char v20; // di
  signed __int64 v21; // r9
  unsigned __int64 v22; // r8
  unsigned __int64 v23; // r8
  UFG::intrusive_multi_rbtree_base::node_base *v24; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v25; // rcx

  v2 = this;
  v3 = (UFG::allocator::free_node *)node->mNeighbours[0];
  v4 = node;
  if ( v3 == node )
  {
    v12 = node->mChildren[1];
    v13 = node;
    v14 = 0;
    if ( v12 != (UFG::intrusive_multi_rbtree_base::node_base *)v2 )
    {
      if ( (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v4->mChildren[0] != v2 )
      {
        v13 = (UFG::allocator::free_node *)v12;
        for ( i = (UFG::allocator::free_node *)v12->mChildren[0];
              i != (UFG::allocator::free_node *)v2;
              i = (UFG::allocator::free_node *)i->mChildren[0] )
        {
          v13 = i;
        }
      }
      v14 = 1;
    }
    v16 = v13->mParent;
    v17 = (char)v13->mParent;
    v18 = v13->mChildren[v14];
    v19 = v13->mParent;
    v18->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v18->mParent & 1i64);
    v20 = v17 & 1;
    v21 = ((unsigned __int64)v19 >> 1) & 1;
    v18->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v18->mParent | (unsigned __int64)v16 & 0xFFFFFFFFFFFFFFFCui64 | 2 * (signed int)v21);
    *(_QWORD *)(((_QWORD)v13->mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (signed int)v21) = v18;
    if ( v13 != v4 )
    {
      v22 = LODWORD(v4->mParent);
      v13->mChildren[0] = v4->mChildren[0];
      v13->mChildren[1] = v4->mChildren[1];
      v23 = (v22 >> 1) & 1;
      v13->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v4->mParent & 0xFFFFFFFFFFFFFFFCui64 | (_QWORD)v13->mParent & 1 | (unsigned __int64)(2 * (signed int)v23));
      v24 = v4->mChildren[0];
      v24->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v24->mParent & 3i64);
      v24->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v24->mParent | (unsigned __int64)v13 & 0xFFFFFFFFFFFFFFFCui64);
      v4->mChildren[0]->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v4->mChildren[0]->mParent & 0xFFFFFFFFFFFFFFFDui64);
      v25 = v4->mChildren[1];
      v25->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v25->mParent & 3i64);
      v25->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v25->mParent | (unsigned __int64)v13 & 0xFFFFFFFFFFFFFFFCui64);
      v4->mChildren[1]->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v4->mChildren[1]->mParent | 2i64);
      *(_QWORD *)(((_QWORD)v4->mParent & 0xFFFFFFFFFFFFFFFCui64) + 8 * v23) = v13;
      v13->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v13->mParent ^ (LODWORD(v13->mParent) ^ LODWORD(v4->mParent)) & 1);
    }
    if ( !v20 )
      UFG::intrusive_multi_rbtree_base::erase_fixup((UFG::intrusive_multi_rbtree_base *)&v2->mHead, v18);
  }
  else
  {
    v5 = node->mParent;
    if ( (unsigned __int64)v5 & 0xFFFFFFFFFFFFFFFCui64 )
    {
      v8 = (unsigned __int64)node->mNeighbours[1];
      *(_QWORD *)v8 = v4->mChildren[0];
      v9 = ((unsigned __int64)v5 >> 1) & 1;
      *(_QWORD *)(v8 + 8) = v4->mChildren[1];
      *(_QWORD *)(v8 + 32) = *(_DWORD *)(v8 + 32) & 1 | (_QWORD)v4->mParent & 0xFFFFFFFFFFFFFFFCui64 | 2 * (signed int)v9;
      v10 = v4->mChildren[0];
      v10->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v10->mParent & 3i64);
      v10->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v10->mParent | v8 & 0xFFFFFFFFFFFFFFFCui64);
      v4->mChildren[0]->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v4->mChildren[0]->mParent & 0xFFFFFFFFFFFFFFFDui64);
      v11 = v4->mChildren[1];
      v11->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v11->mParent & 3i64);
      v11->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v11->mParent | v8 & 0xFFFFFFFFFFFFFFFCui64);
      v4->mChildren[1]->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v4->mChildren[1]->mParent | 2i64);
      *(_QWORD *)(((_QWORD)v4->mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (signed int)v9) = v8;
      *(_QWORD *)(v8 + 32) ^= (*(_DWORD *)(v8 + 32) ^ LODWORD(v4->mParent)) & 1;
      v4->mNeighbours[1]->mNeighbours[0] = v4->mNeighbours[0];
      v6 = v4->mNeighbours[0];
      v7 = v4->mNeighbours[1];
    }
    else
    {
      node->mNeighbours[1]->mNeighbours[0] = (UFG::intrusive_multi_rbtree_base::node_base *)v3->mChildren;
      v6 = node->mNeighbours[0];
      v7 = node->mNeighbours[1];
    }
    v6->mNeighbours[1] = v7;
  }
}

