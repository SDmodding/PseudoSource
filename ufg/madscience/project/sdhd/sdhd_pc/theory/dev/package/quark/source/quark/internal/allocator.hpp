// File Line: 393
// RVA: 0x1625C0
// attributes: thunk
void __fastcall UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::~intrusive_multi_rbtree<UFG::allocator::free_node>(
        UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *this)
{
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::clear(this);
}

// File Line: 415
// RVA: 0x180680
void __fastcall UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::clear(
        UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *this)
{
  UFG::intrusive_multi_rbtree_base::node_base *v1; // rax
  UFG::allocator::free_node *i; // rdx
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v4; // rbx
  UFG::intrusive_multi_rbtree_base::node_base *mParent; // rax
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *j; // rax
  char v7; // al

  v1 = this->mHead.mChildren[0];
  for ( i = (UFG::allocator::free_node *)v1; v1 != v1->mChildren[1]; v1 = v1->mChildren[0] )
    i = (UFG::allocator::free_node *)v1;
  if ( i != (UFG::allocator::free_node *)this )
  {
    do
    {
      v4 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)i->mNeighbours[1];
      mParent = v4->mHead.mParent;
      if ( ((unsigned __int64)mParent & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      {
        v4 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v4->mHead.mChildren[1];
        if ( v4 == (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v4->mHead.mChildren[1] )
        {
          v4 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)((unsigned __int64)mParent & 0xFFFFFFFFFFFFFFFCui64);
          if ( ((unsigned __int8)mParent & 2) != 0 )
          {
            do
            {
              v7 = (unsigned __int8)LODWORD(v4->mHead.mParent) >> 1;
              v4 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)((unsigned __int64)v4->mHead.mParent & 0xFFFFFFFFFFFFFFFCui64);
            }
            while ( (v7 & 1) != 0 );
          }
        }
        else
        {
          for ( j = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v4->mHead.mChildren[0];
                j != (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)j->mHead.mChildren[1];
                j = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)j->mHead.mChildren[0] )
          {
            v4 = j;
          }
        }
      }
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(this, i);
      i = (UFG::allocator::free_node *)v4;
    }
    while ( v4 != this );
  }
}

// File Line: 450
// RVA: 0x180C20
void __fastcall UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_insert(
        UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *this,
        UFG::allocator::free_node *node)
{
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v2; // rax
  int v3; // r10d
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v6; // rbx
  unsigned __int64 v7; // r9
  __int64 v8; // rdx
  unsigned __int64 v9; // rcx
  UFG::intrusive_multi_rbtree_base::node_base **v10; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v11; // rcx

  v2 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)this->mHead.mChildren[0];
  v3 = 0;
  v6 = this;
  if ( (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)this->mHead.mChildren[0] == this )
  {
LABEL_7:
    node->mNeighbours[0] = node;
    node->mNeighbours[1] = node;
    v10 = &v6->mHead.mChildren[v3];
    node->mChildren[0] = *v10;
    node->mChildren[1] = *v10;
    node->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)node->mParent & 1);
    node->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)node->mParent | (unsigned __int64)v6 & 0xFFFFFFFFFFFFFFFCui64 | (2 * v3));
    *v10 = node;
    node->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)node->mParent | 1);
    UFG::intrusive_multi_rbtree_base::insert_fixup(this, node);
    return;
  }
  v7 = (unsigned __int64)node[-1].mNeighbours[1] & 0xFFFFFFFFFFFFFFFCui64;
  while ( 1 )
  {
    v8 = 1i64;
    v6 = v2;
    v9 = (unsigned __int64)v2[-1].mHead.mNeighbours[1] & 0xFFFFFFFFFFFFFFFCui64;
    v3 = 1;
    if ( v7 >= v9 )
      break;
    v3 = 0;
    v8 = 0i64;
LABEL_6:
    v2 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v2->mHead.mChildren[v8];
    if ( v2 == this )
      goto LABEL_7;
  }
  if ( v7 > v9 )
    goto LABEL_6;
  v11 = v2->mHead.mNeighbours[0];
  node->mNeighbours[1] = &v2->mHead;
  node->mNeighbours[0] = v11;
  v2->mHead.mNeighbours[0] = node;
  node->mNeighbours[0]->mNeighbours[1] = node;
  node->mChildren[0] = 0i64;
  node->mChildren[1] = 0i64;
  node->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)1;
}

// File Line: 472
// RVA: 0x180A00
void __fastcall UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(
        UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *this,
        UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *node)
{
  UFG::allocator::free_node *v3; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v5; // r8
  UFG::intrusive_multi_rbtree_base::node_base *v6; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v7; // rax
  unsigned __int64 v8; // rdx
  __int64 v9; // r8
  UFG::intrusive_multi_rbtree_base::node_base *v10; // rax
  UFG::intrusive_multi_rbtree_base::node_base *v11; // rax
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v12; // rcx
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v13; // rax
  int v14; // edx
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *i; // rcx
  char mParent; // di
  UFG::intrusive_multi_rbtree_base::node_base *v17; // rbx
  UFG::intrusive_multi_rbtree_base::node_base *v18; // r9
  unsigned __int64 v19; // r8
  char v20; // di
  __int64 v21; // r9
  unsigned __int64 mParent_low; // r8
  UFG::intrusive_multi_rbtree_base::node_base *v23; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v24; // rcx

  v3 = (UFG::allocator::free_node *)node->mHead.mNeighbours[0];
  if ( v3 == (UFG::allocator::free_node *)node )
  {
    v12 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)node->mHead.mChildren[1];
    v13 = node;
    v14 = 0;
    if ( v12 != this )
    {
      if ( (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)node->mHead.mChildren[0] != this )
      {
        v13 = v12;
        for ( i = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v12->mHead.mChildren[0];
              i != this;
              i = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)i->mHead.mChildren[0] )
        {
          v13 = i;
        }
      }
      v14 = 1;
    }
    mParent = (char)v13->mHead.mParent;
    v17 = v13->mHead.mChildren[v14];
    v18 = v13->mHead.mParent;
    v19 = (unsigned __int64)v18 & 0xFFFFFFFFFFFFFFFCui64;
    v17->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v17->mParent & 1);
    v20 = mParent & 1;
    v21 = ((unsigned __int64)v18 >> 1) & 1;
    v17->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v17->mParent | v19 | (2 * (int)v21));
    *(_QWORD *)(((unsigned __int64)v13->mHead.mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (int)v21) = v17;
    if ( v13 != node )
    {
      mParent_low = LODWORD(node->mHead.mParent);
      v13->mHead.mChildren[0] = node->mHead.mChildren[0];
      v13->mHead.mChildren[1] = node->mHead.mChildren[1];
      LODWORD(mParent_low) = (mParent_low >> 1) & 1;
      v13->mHead.mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)node->mHead.mParent & 0xFFFFFFFFFFFFFFFCui64 | (__int64)v13->mHead.mParent & 1 | (unsigned __int64)(2 * (int)mParent_low));
      v23 = node->mHead.mChildren[0];
      v23->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v23->mParent & 3);
      v23->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v23->mParent | (unsigned __int64)v13 & 0xFFFFFFFFFFFFFFFCui64);
      node->mHead.mChildren[0]->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)node->mHead.mChildren[0]->mParent & ~2ui64);
      v24 = node->mHead.mChildren[1];
      v24->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v24->mParent & 3);
      v24->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v24->mParent | (unsigned __int64)v13 & 0xFFFFFFFFFFFFFFFCui64);
      node->mHead.mChildren[1]->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)node->mHead.mChildren[1]->mParent | 2);
      *(_QWORD *)(((unsigned __int64)node->mHead.mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (int)mParent_low) = v13;
      v13->mHead.mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((__int64)v13->mHead.mParent ^ (LODWORD(v13->mHead.mParent) ^ LODWORD(node->mHead.mParent)) & 1);
    }
    if ( !v20 )
      UFG::intrusive_multi_rbtree_base::erase_fixup(this, v17);
  }
  else
  {
    v5 = node->mHead.mParent;
    if ( ((unsigned __int64)v5 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
    {
      v8 = (unsigned __int64)node->mHead.mNeighbours[1];
      *(_QWORD *)v8 = node->mHead.mChildren[0];
      v9 = ((unsigned __int64)v5 >> 1) & 1;
      *(_QWORD *)(v8 + 8) = node->mHead.mChildren[1];
      *(_QWORD *)(v8 + 32) = *(_DWORD *)(v8 + 32) & 1 | (unsigned __int64)node->mHead.mParent & 0xFFFFFFFFFFFFFFFCui64 | (2 * (int)v9);
      v10 = node->mHead.mChildren[0];
      v10->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v10->mParent & 3);
      v10->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v10->mParent | v8 & 0xFFFFFFFFFFFFFFFCui64);
      node->mHead.mChildren[0]->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)node->mHead.mChildren[0]->mParent & ~2ui64);
      v11 = node->mHead.mChildren[1];
      v11->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v11->mParent & 3);
      v11->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v11->mParent | v8 & 0xFFFFFFFFFFFFFFFCui64);
      node->mHead.mChildren[1]->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)node->mHead.mChildren[1]->mParent | 2);
      *(_QWORD *)(((unsigned __int64)node->mHead.mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (int)v9) = v8;
      *(_QWORD *)(v8 + 32) ^= (*(_DWORD *)(v8 + 32) ^ LODWORD(node->mHead.mParent)) & 1;
      node->mHead.mNeighbours[1]->mNeighbours[0] = node->mHead.mNeighbours[0];
      v6 = node->mHead.mNeighbours[0];
      v7 = node->mHead.mNeighbours[1];
    }
    else
    {
      node->mHead.mNeighbours[1]->mNeighbours[0] = v3;
      v6 = node->mHead.mNeighbours[0];
      v7 = node->mHead.mNeighbours[1];
    }
    v6->mNeighbours[1] = v7;
  }
}

