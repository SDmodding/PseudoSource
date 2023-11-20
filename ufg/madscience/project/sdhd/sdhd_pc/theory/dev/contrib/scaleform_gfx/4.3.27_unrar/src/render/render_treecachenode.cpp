// File Line: 53
// RVA: 0x94D6F0
void __fastcall Scaleform::Render::TreeCacheNode::~TreeCacheNode(Scaleform::Render::TreeCacheNode *this)
{
  Scaleform::Render::TreeCacheNode *v1; // rbx
  Scaleform::Render::TreeCacheNode *v2; // rcx
  Scaleform::Render::TreeCacheNode *v3; // rcx
  Scaleform::Render::CacheEffect *v4; // rbx
  Scaleform::Render::CacheEffect *v5; // rcx

  v1 = this;
  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheNode::`vftable;
  if ( this->pPrev )
  {
    this->pPrev->pNext = this->pNext;
    this->pNext->pPrev = this->pPrev;
    this->pPrev = (Scaleform::Render::TreeCacheNode *)-1i64;
    this->pNext = (Scaleform::Render::TreeCacheNode *)-1i64;
  }
  else
  {
    v2 = this->pParent;
    if ( v2 )
    {
      v2->pMask = 0i64;
      v2->Flags &= 0xFFEFu;
    }
  }
  v3 = v1->pMask;
  if ( v3 )
    Scaleform::Render::TreeCacheNode::RemoveFromParent(v3);
  v4 = v1->Effects.pEffect;
  while ( v4 )
  {
    v5 = v4;
    v4 = v4->pNext;
    v5->vfptr->__vecDelDtor(v5, 1u);
  }
}

// File Line: 93
// RVA: 0x9BE630
void __fastcall Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::TreeCacheNode *pparent, Scaleform::Render::TreeCacheNode *pinsert, Scaleform::Render::TreeNode::NodeData *nodeData, unsigned __int16 depth)
{
  Scaleform::Render::TreeCacheNode *v5; // rdi
  Scaleform::Render::TreeNode::NodeData *v6; // r14
  Scaleform::Render::TreeCacheNode *v7; // rbp
  Scaleform::Render::TreeCacheNode *v8; // rsi
  Scaleform::Render::TreeCacheNode *v9; // rbx
  Scaleform::Render::TreeCacheRoot *v10; // rcx
  signed int v11; // eax
  Scaleform::Render::TreeCacheNode *v12; // rcx
  Scaleform::Render::TreeCacheNodeVtbl *v13; // rax
  unsigned int v14; // edi

  v5 = this->pParent;
  v6 = nodeData;
  v7 = pinsert;
  v8 = pparent;
  v9 = this;
  if ( v5 == pparent )
  {
    if ( pinsert )
    {
      if ( pparent->pMask != this )
        goto LABEL_24;
    }
    else if ( pparent->pMask == this )
    {
      goto LABEL_24;
    }
  }
  if ( v5 )
  {
    Scaleform::Render::TreeCacheNode::RemoveFromParent(this, pparent);
    if ( v5->pRoot )
    {
      if ( v5->vfptr->IsPatternChainValid(v5) )
      {
        v10 = v5->pRoot;
        v11 = 0x1000000;
        if ( (v5->UpdateFlags & 0x80000000) == 0 )
        {
          v5->pNextUpdate = v10->pUpdateList;
          v10->pUpdateList = v5;
          v11 = -2130706432;
        }
        v5->UpdateFlags |= v11;
      }
    }
  }
  if ( v7 )
  {
    v9->pPrev = v7->pNext->pPrev;
    v9->pNext = v7->pNext;
    v7->pNext->pPrev = v9;
    v7->pNext = v9;
  }
  if ( v6 )
  {
    if ( (LOBYTE(v6->Flags) >> 5) & 1 )
    {
      v12 = v8->pMask;
      if ( v12 && v12 != v9 )
        Scaleform::Render::TreeCacheNode::RemoveFromParent(v12, pparent);
      v8->Flags |= 0x10u;
      v8->pMask = v9;
      v13 = v9->vfptr;
      v9->Flags |= 0x20u;
      v13->propagateMaskFlag(v9, 64u);
    }
    v14 = v8->Flags & 0x80;
    if ( Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::Scale9State>(v6) )
      v14 |= 0x80u;
    v9->vfptr->propagateScale9Flag(v9, v14);
    v9->vfptr->propagateEdgeAA(v9, (Scaleform::Render::EdgeAAMode)(v8->Flags & 0xC));
  }
  v9->pParent = v8;
LABEL_24:
  v9->Depth = depth;
  v9->pRoot = v8->pRoot;
  v9->vfptr->UpdateChildSubtree(v9, v6, depth + 1);
}

// File Line: 154
// RVA: 0x9A9C20
void __fastcall Scaleform::Render::TreeCacheNode::RemoveFromParent(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::TreeCacheNode *a2)
{
  Scaleform::Render::TreeCacheNode *v2; // rbx
  Scaleform::Render::TreeCacheNode *v3; // rcx
  __int64 v4; // r8
  Scaleform::Render::TreeCacheNode *v5; // rax
  bool v6; // zf

  v2 = this;
  v3 = this->pPrev;
  v4 = 0i64;
  if ( v3 )
  {
    v3->pNext = v2->pNext;
    a2 = v2->pNext;
    a2->pPrev = v2->pPrev;
    v2->pPrev = (Scaleform::Render::TreeCacheNode *)-1i64;
    v2->pNext = (Scaleform::Render::TreeCacheNode *)-1i64;
  }
  else
  {
    v5 = v2->pParent;
    if ( v5 )
    {
      v5->pMask = 0i64;
      v5->Flags &= 0xFFEFu;
      v2->Flags &= 0xFFDFu;
    }
  }
  v6 = (v2->Flags & 0x40) == 0;
  v2->pPrev = 0i64;
  v2->pNext = 0i64;
  v2->pParent = 0i64;
  v2->Depth = 0;
  if ( !v6 )
    ((void (__fastcall *)(Scaleform::Render::TreeCacheNode *, _QWORD, _QWORD))v2->vfptr->propagateMaskFlag)(
      v2,
      0i64,
      0i64);
  if ( SLOBYTE(v2->Flags) < 0 )
    ((void (__fastcall *)(Scaleform::Render::TreeCacheNode *, _QWORD, __int64))v2->vfptr->propagateScale9Flag)(
      v2,
      0i64,
      v4);
  ((void (__fastcall *)(Scaleform::Render::TreeCacheNode *, Scaleform::Render::TreeCacheNode *, __int64))v2->vfptr->HandleRemoveNode)(
    v2,
    a2,
    v4);
}

// File Line: 184
// RVA: 0x991310
void __fastcall Scaleform::Render::TreeCacheNode::HandleRemoveNode(Scaleform::Render::TreeCacheNode *this)
{
  Scaleform::Render::TreeCacheNode *v1; // rcx

  this->pRoot = 0i64;
  v1 = this->pMask;
  if ( v1 )
    ((void (*)(void))v1->vfptr->HandleRemoveNode)();
}

// File Line: 192
// RVA: 0x9BD840
void __fastcall Scaleform::Render::TreeCacheNode::UpdateChildSubtree(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::TreeNode::NodeData *data, unsigned __int16 depth)
{
  Scaleform::Render::StateData::Interface *v3; // r10
  Scaleform::Render::TreeCacheNode *v4; // r11
  int v5; // er9
  Scaleform::Render::StateBag *v6; // rax
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // r10
  _QWORD *v9; // rcx
  Scaleform::Render::TreeCacheNode *v10; // rax

  v3 = data->States.pInterface;
  v4 = this;
  v5 = this->Flags ^ ((unsigned __int8)this->Flags ^ (unsigned __int8)(2 * this->Flags)) & 0x40;
  v6 = &data->States;
  if ( v3 )
  {
    if ( (unsigned __int8)v3 & 1 )
    {
      if ( ((unsigned __int64)v3 & 0xFFFFFFFFFFFFFFFEui64) != qword_142451A50 )
        goto LABEL_13;
    }
    else
    {
      v7 = 0i64;
      v8 = (unsigned __int64)v3 >> 1;
      if ( !v8 )
        goto LABEL_13;
      v9 = (_QWORD *)(data->States.DataValue + 4);
      while ( *v9 != qword_142451A50 )
      {
        ++v7;
        v9 += 2;
        if ( v7 >= v8 )
          goto LABEL_13;
      }
      v6 = (Scaleform::Render::StateBag *)(data->States.DataValue + 4 + 16 * v7);
    }
    if ( v6 )
      v5 |= 0x80u;
  }
LABEL_13:
  v10 = v4->pParent;
  if ( v10 )
    v5 |= v10->Flags & 0xC0;
  if ( (data->Flags >> 9) & 1 )
    LOWORD(v5) = v5 | 0x200;
  v4->Flags = v5;
  Scaleform::Render::TreeCacheNode::updateMaskCache(v4, data, depth, 1);
}

// File Line: 210
// RVA: 0x9F9E70
void __fastcall Scaleform::Render::TreeCacheNode::updateMaskCache(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::TreeNode::NodeData *data, unsigned __int16 depth, bool updateSubtree)
{
  bool v4; // di
  Scaleform::Render::TreeCacheNode *v5; // rbx
  Scaleform::Render::StateBag *v6; // rax
  Scaleform::Render::TreeCacheNode **v7; // r9
  unsigned __int64 v8; // rcx
  Scaleform::Render::TreeCacheNode *v9; // rax
  unsigned __int64 v10; // rcx
  Scaleform::Render::TreeCacheNode *v11; // rcx
  Scaleform::Render::TreeCacheRoot *v12; // rcx
  signed int v13; // eax

  TCN_This = this;
  TCN_ThisData = data;
  v4 = updateSubtree;
  v5 = this;
  if ( !((LOBYTE(data->Flags) >> 4) & 1) )
  {
    v11 = this->pMask;
    if ( !v11 )
      return;
    Scaleform::Render::TreeCacheNode::RemoveFromParent(v11, (Scaleform::Render::TreeCacheNode *)data);
    goto $update_on_mask_change;
  }
  v6 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::MaskNodeState>(data);
  v7 = (Scaleform::Render::TreeCacheNode **)v6->pData;
  TCN_ChildNode = (Scaleform::Render::TreeNode *)v6->pData;
  if ( v4 )
  {
    v8 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                   + 8
                   * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((char *)v7
                                                                                         - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64)
                                                                                         - 56)
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                    + ((unsigned __int64)((unsigned __int128)((signed __int64)((char *)v7
                                                                             - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64)
                                                                             - 56)
                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                   + 40) & 0xFFFFFFFFFFFFFFFEui64;
    (*(void (__fastcall **)(unsigned __int64, Scaleform::Render::TreeCacheNode *, _QWORD))(*(_QWORD *)v8 + 48i64))(
      v8,
      v5,
      0i64);
    return;
  }
  v9 = v5->pMask;
  if ( v7[3] != v9 || !v9 )
  {
    v10 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                    + 8
                    * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((char *)v7
                                                                                          - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64)
                                                                                          - 56)
                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                     + ((unsigned __int64)((unsigned __int128)((signed __int64)((char *)v7
                                                                              - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64)
                                                                              - 56)
                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                    + 40) & 0xFFFFFFFFFFFFFFFEui64;
    (*(void (__fastcall **)(unsigned __int64, Scaleform::Render::TreeCacheNode *, _QWORD))(*(_QWORD *)v10 + 48i64))(
      v10,
      v5,
      0i64);
$update_on_mask_change:
    if ( v5->pRoot && v5->vfptr->IsPatternChainValid(v5) )
    {
      v12 = v5->pRoot;
      v13 = 0x1000000;
      if ( (v5->UpdateFlags & 0x80000000) == 0 )
      {
        v5->pNextUpdate = v12->pUpdateList;
        v12->pUpdateList = v5;
        v13 = -2130706432;
      }
      v5->UpdateFlags |= v13;
    }
  }
}

// File Line: 255
// RVA: 0x9F9FE0
void __fastcall Scaleform::Render::TreeCacheNode::updateMaskTransform(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::TransformArgs *t, Scaleform::Render::TransformFlags flags)
{
  Scaleform::Render::TreeCacheNode *v3; // r9
  Scaleform::Render::TransformFlags v4; // ebp
  Scaleform::Render::TransformArgs *v5; // rbx
  Scaleform::Render::TreeCacheNode *v6; // rsi
  Scaleform::Render::TreeNode *v7; // r9
  unsigned __int64 v8; // rdi
  Scaleform::Render::Matrix3x4<float> *v9; // rdx

  v3 = this->pMask;
  v4 = flags;
  v5 = t;
  v6 = this;
  if ( v3 )
  {
    v7 = v3->pNode;
    v8 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                   + 8
                   * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1]
                                                                                         - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                    + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1]
                                                                             - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                   + 40) & 0xFFFFFFFFFFFFFFFEui64;
    v9 = (Scaleform::Render::Matrix3x4<float> *)(v8 + 16);
    if ( (flags & 0x80u) != 0 )
      Scaleform::Render::TransformArgs::PrependMatrix3D(v5, v9);
    else
      Scaleform::Render::Matrix2x4<float>::Prepend(&v5->Mat, (Scaleform::Render::Matrix2x4<float> *)v9);
    v6->pMask->vfptr->UpdateTransform(v6->pMask, (Scaleform::Render::TreeNode::NodeData *)v8, v5, v4);
  }
}

// File Line: 268
// RVA: 0x9F9970
void __fastcall Scaleform::Render::TreeCacheNode::updateEffectChain(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::BundleEntryRange *contentChain)
{
  Scaleform::Render::TreeCacheNode *v2; // rbx
  Scaleform::Render::TreeCacheNode *v3; // rcx
  Scaleform::Render::BundleEntryRange *v4; // rdi
  Scaleform::Render::CacheEffectChain *v5; // rcx
  Scaleform::Render::CacheEffect *v6; // rbx
  Scaleform::Render::CacheEffect *v7; // rdx
  Scaleform::Render::BundleEntryRange *v8; // r8
  Scaleform::Render::CacheEffectChain *v9; // rcx
  Scaleform::Render::CacheEffect *v10; // rdx
  Scaleform::Render::BundleEntryRange maskChain; // [rsp+20h] [rbp-28h]

  v2 = this;
  v3 = this->pMask;
  v4 = contentChain;
  if ( v3 )
  {
    maskChain.pFirst = 0i64;
    maskChain.pLast = 0i64;
    maskChain.Length = 0;
    v3->vfptr->GetPatternChain(v3, &maskChain, 0);
    v5 = &v2->Effects;
    v6 = v2->Effects.pEffect;
    if ( !v6 )
      return;
    v7 = v6->pNext;
    if ( v7 )
      Scaleform::Render::CacheEffectChain::updateBundleChain(v5, v7, v4, &maskChain);
    v8 = &maskChain;
  }
  else
  {
    v9 = &v2->Effects;
    v6 = v2->Effects.pEffect;
    if ( !v6 )
      return;
    v10 = v6->pNext;
    if ( v10 )
      Scaleform::Render::CacheEffectChain::updateBundleChain(v9, v10, v4, 0i64);
    v8 = 0i64;
  }
  v6->vfptr->ChainNext(v6, v4, v8);
}

// File Line: 283
// RVA: 0x9EE1D0
void __fastcall Scaleform::Render::TreeCacheNode::propagateMaskFlag(Scaleform::Render::TreeCacheNode *this, unsigned int partOfMask)
{
  this->Flags &= 0xFFBFu;
  this->Flags |= partOfMask;
}

// File Line: 287
// RVA: 0x9EE330
void __fastcall Scaleform::Render::TreeCacheNode::propagateScale9Flag(Scaleform::Render::TreeCacheNode *this, unsigned int partOfScale9)
{
  Scaleform::Render::TreeCacheNode *v2; // r10
  __int16 v3; // r11
  unsigned __int64 *v4; // r8
  unsigned __int64 v5; // rdx
  unsigned __int64 v6; // rax
  signed __int64 v7; // r9
  unsigned __int64 v8; // rdx
  _QWORD *v9; // rcx

  v2 = this;
  v3 = partOfScale9;
  v4 = (unsigned __int64 *)((*(_QWORD *)(*(_QWORD *)(((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                       + 8
                                       * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pNode[-1] - ((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                        + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pNode[-1]
                                                                                                 - ((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                       + 40) & 0xFFFFFFFFFFFFFFFEui64)
                          + 64);
  v5 = *v4;
  if ( !*v4 )
    goto LABEL_13;
  if ( v5 & 1 )
  {
    if ( (v5 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A50 )
    {
LABEL_11:
      if ( v4 )
        v3 |= 0x80u;
      goto LABEL_13;
    }
  }
  else
  {
    v6 = 0i64;
    v7 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                + 8
                                * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pNode[-1] - ((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                     * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                 + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pNode[-1]
                                                                                          - ((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                + 40) & 0xFFFFFFFFFFFFFFFEui64)
                   + 72)
       + 4i64;
    v8 = v5 >> 1;
    if ( v8 )
    {
      v9 = (_QWORD *)(*(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                             + 8
                                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pNode[-1] - ((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pNode[-1] - ((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                             + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                + 72)
                    + 4i64);
      while ( *v9 != qword_142451A50 )
      {
        ++v6;
        v9 += 2;
        if ( v6 >= v8 )
        {
          v2->Flags &= 0xFF7Fu;
          v2->Flags |= v3;
          return;
        }
      }
      v4 = (unsigned __int64 *)(v7 + 16 * v6);
      goto LABEL_11;
    }
  }
LABEL_13:
  v2->Flags &= 0xFF7Fu;
  v2->Flags |= v3;
}

// File Line: 293
// RVA: 0x9EDFC0
void __fastcall Scaleform::Render::TreeCacheNode::propagateEdgeAA(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::EdgeAAMode parentEdgeAA)
{
  int v2; // eax

  if ( parentEdgeAA == 12 )
  {
    this->Flags &= 0xFFF3u;
    this->Flags |= 0xCu;
  }
  else
  {
    v2 = *(_WORD *)((*(_QWORD *)(*(_QWORD *)(((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                               + 8
                               * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pNode[-1]
                                                                                         - ((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pNode[-1] - ((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                  + 10) & 0xC;
    if ( !v2 )
      LOWORD(v2) = parentEdgeAA;
    this->Flags &= 0xFFF3u;
    this->Flags |= v2;
  }
}

// File Line: 326
// RVA: 0x9F90C0
__int64 __fastcall Scaleform::Render::TreeCacheNode::updateCulling(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::TreeNode::NodeData *data, Scaleform::Render::TransformArgs *t, Scaleform::Render::Rect<float> *cullRect, Scaleform::Render::TransformFlags flags)
{
  Scaleform::Render::TransformFlags v5; // esi
  signed int v6; // er12
  unsigned int v7; // eax
  char v8; // r13
  Scaleform::Render::TransformArgs *v9; // r14
  Scaleform::Render::Rect<float> *v10; // r15
  Scaleform::Render::TreeNode::NodeData *v11; // rdi
  Scaleform::Render::TreeCacheNode *v12; // rbx
  unsigned int v13; // ecx
  signed int v14; // eax
  bool v15; // cl
  Scaleform::Render::CacheEffect *v16; // rdi
  Scaleform::Render::Matrix4x4<float> *viewProjMatrix; // rax
  int v18; // er9
  char is3d; // di
  Scaleform::Render::TreeCacheRoot *v20; // rcx
  Scaleform::Render::TreeNode *v21; // rcx
  Scaleform::Render::Matrix4x4<float> *v22; // rax
  Scaleform::Render::TreeCacheRoot *v23; // rcx
  Scaleform::Render::TreeCacheNode *v24; // rdx
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm4
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  __m128 v32; // xmm0
  __m128 v33; // xmm2
  __m128 v34; // xmm0
  __m128 v35; // xmm3
  __m128 v36; // xmm0
  __m128 v37; // xmm2
  __m128 v38; // xmm3
  __m128 v39; // xmm0
  __m128 v40; // xmm1
  Scaleform::Render::Rect<float> v41; // xmm3
  __m128 v42; // xmm4
  __m128 v43; // xmm1
  __m128 v44; // xmm4
  __m128 v45; // xmm2
  __m128 v46; // xmm3
  __m128 v47; // xmm0
  __m128 v48; // xmm2
  __m128 v49; // xmm0
  __m128 v50; // xmm3
  __m128 v51; // xmm0
  __m128 v52; // xmm2
  __m128 v53; // xmm3
  unsigned __int64 v54; // r8
  Scaleform::Render::Matrix4x4<float> *v55; // rax
  __m128 v56; // xmm7
  __m128 v57; // xmm6
  __m128 v58; // xmm8
  __m128 v59; // xmm3
  __m128 v60; // xmm4
  __m128 v61; // xmm5
  __m128 v62; // xmm9
  __m128 v63; // xmm2
  __m128i v64; // xmm1
  __m128i v65; // xmm0
  float v66; // xmm0_4
  float v67; // xmm1_4
  Scaleform::Render::TreeCacheRoot *v68; // r9
  unsigned __int64 v69; // rdx
  unsigned __int16 v70; // ax
  Scaleform::Render::TreeCacheNode *v71; // rdx
  unsigned __int16 v72; // ax
  Scaleform::Render::TreeCacheNode *v73; // rdx
  Scaleform::Render::TreeCacheNode *v74; // rdi
  signed __int128 v75; // ax
  unsigned __int64 v76; // rbx
  Scaleform::Render::Rect<float> maskBounds; // [rsp+40h] [rbp-98h]
  Scaleform::Render::Matrix3x4<float> m; // [rsp+50h] [rbp-88h]
  Scaleform::Render::TransformArgs ta; // [rsp+88h] [rbp-50h]
  unsigned int *v81; // [rsp+1F8h] [rbp+120h]
  Scaleform::Render::TreeNode::NodeData *dataa; // [rsp+200h] [rbp+128h]
  void *retaddr; // [rsp+218h] [rbp+140h]

  v5 = (signed int)retaddr;
  v6 = 0;
  v7 = (unsigned int)retaddr >> 7;
  v8 = 0;
  v9 = t;
  LOBYTE(v7) = ((unsigned int)retaddr >> 7) & 1;
  v10 = cullRect;
  v11 = data;
  LODWORD(v81) = v7;
  v12 = this;
  if ( !((unsigned __int8)retaddr & 0x10) )
    goto LABEL_53;
  maskBounds = 0i64;
  v15 = 0;
  if ( Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::BlendState>(data) )
  {
    v13 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::BlendState>(v11)->DataValue;
    if ( v13 <= 0xE )
    {
      v14 = 24804;
      if ( _bittest(&v14, v13) )
        v15 = 1;
    }
  }
  if ( v12->pMask || (v11->Flags >> 10) & 1 || v15 )
    Scaleform::Render::TransformArgs::GetMatrix3D(v9, (Scaleform::Render::TransformFlags)retaddr, &m);
  if ( v12->pMask )
  {
    v16 = v12->Effects.pEffect;
    *(_OWORD *)&m.M[1][2] = _xmm;
    *(__m128 *)&m.M[2][2] = _xmm;
    if ( !v16 )
      goto LABEL_15;
    while ( v16->vfptr->GetType(v16) != 4 )
    {
      v16 = v16->pNext;
      if ( !v16 )
        goto LABEL_15;
    }
    if ( v16 )
    {
      v22 = Scaleform::Render::TransformArgs::GetViewProj(v9);
      LODWORD(retaddr) = Scaleform::Render::TreeCacheNode::calcMaskBounds(
                           v12,
                           &maskBounds,
                           (Scaleform::Render::Matrix2x4<float> *)&m.M[1][2],
                           &m,
                           v22);
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(
        (Scaleform::Render::MatrixPoolImpl::HMatrix *)&v16[9].pNext,
        (Scaleform::Render::Matrix2x4<float> *)&m.M[1][2]);
      v18 = (signed int)retaddr;
      if ( (_DWORD)retaddr != LODWORD(v16[9].vfptr) )
      {
        v23 = v12->pRoot;
        v12->UpdateFlags |= 0x40000u;
        if ( v23 )
        {
          v24 = v12->pParent;
          if ( v24 )
          {
            Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(v23, v24, 0x1000000u);
            v18 = (signed int)retaddr;
          }
        }
      }
    }
    else
    {
LABEL_15:
      viewProjMatrix = Scaleform::Render::TransformArgs::GetViewProj(v9);
      v18 = Scaleform::Render::TreeCacheNode::calcMaskBounds(
              v12,
              &maskBounds,
              (Scaleform::Render::Matrix2x4<float> *)&m.M[1][2],
              &m,
              viewProjMatrix);
    }
    is3d = (char)v81;
    if ( !(_BYTE)v81 )
    {
      v20 = v12->pRoot;
      if ( v20 )
      {
        v21 = v20->pNode;
        if ( !(*(_BYTE *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                     + 8
                                     * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v21[-1] - ((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64))
                                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                      + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v21[-1]
                                                                                               - ((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64))
                                                                              * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                     + 40) & 0xFFFFFFFFFFFFFFFEui64)
                        + 200) & 0x30) )
        {
          if ( v18 )
          {
            if ( v18 == 1 )
            {
              v6 = 1;
              v8 = 1;
            }
            else
            {
              v25 = *(__m128 *)&v9->Mat.M[1][0];
              v26 = *(__m128 *)&v9->Mat.M[0][0];
              v27 = v26;
              v28 = _mm_unpacklo_ps(v26, v25);
              v29 = _mm_shuffle_ps(v27, v25, 255);
              v30 = _mm_mul_ps(_mm_unpacklo_ps((__m128)maskBounds, (__m128)maskBounds), v28);
              v31 = _mm_mul_ps(_mm_unpackhi_ps((__m128)maskBounds, (__m128)maskBounds), v28);
              v32 = v30;
              v33 = _mm_unpackhi_ps(v30, v31);
              v34 = _mm_unpacklo_ps(v32, v31);
              v35 = _mm_add_ps(v33, v34);
              v36 = _mm_add_ps(_mm_shuffle_ps(v34, v34, 177), v33);
              v37 = _mm_min_ps(v35, v36);
              v38 = _mm_max_ps(v35, v36);
              maskBounds = (Scaleform::Render::Rect<float>)_mm_add_ps(
                                                             _mm_shuffle_ps(
                                                               _mm_min_ps(v37, _mm_shuffle_ps(v37, v37, 177)),
                                                               _mm_max_ps(v38, _mm_shuffle_ps(v38, v38, 177)),
                                                               136),
                                                             _mm_shuffle_ps(v29, v29, 136));
              if ( !Scaleform::Render::Rect<float>::IntersectRect(v10, v10, &maskBounds) )
              {
                v8 = 1;
                v6 = 1;
              }
            }
          }
        }
      }
    }
  }
  else
  {
    is3d = (char)v81;
  }
  Scaleform::Render::TreeCacheNode::updateFilterCache(v12, dataa, v9, v5, v10, &m, is3d);
  Scaleform::Render::TreeCacheNode::updateBlendCache(v12, dataa, v9, v5, v10, &m);
  if ( v5 & 0x20 )
  {
    if ( v8 )
    {
LABEL_36:
      v11 = dataa;
      goto LABEL_53;
    }
    if ( COERCE_FLOAT(LODWORD(v9->Cx.M[0][3]) & _xmm) < 0.001
      && COERCE_FLOAT(LODWORD(v9->Cx.M[1][3]) & _xmm) < 0.0039215689
      && !(v12->Flags & 0x40) )
    {
      v8 = 1;
      v6 = 2;
      goto LABEL_36;
    }
  }
  else if ( v8 )
  {
    goto LABEL_36;
  }
  if ( !v12->pRoot )
    goto LABEL_36;
  if ( is3d )
  {
    Scaleform::Render::TransformArgs::GetMatrix3D(v9, v5, &m);
    v54 = (_QWORD)v12->pRoot->pNode & 0xFFFFFFFFFFFFF000ui64;
    v81 = (unsigned int *)((*(_QWORD *)(*(_QWORD *)(v54 + 0x28)
                                      + 8
                                      * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v12->pRoot->pNode[-1] - v54)
                                                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                       + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v12->pRoot->pNode[-1]
                                                                                                - v54)
                                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                      + 40) & 0xFFFFFFFFFFFFFFFEui64)
                         + 160);
    v55 = Scaleform::Render::TransformArgs::GetViewProj(v9);
    v56 = *(__m128 *)&m.M[0][0];
    v57 = *(__m128 *)&m.M[1][0];
    v58 = *(__m128 *)&m.M[2][0];
    v59 = *(__m128 *)&v55->M[0][0];
    v60 = *(__m128 *)&v55->M[1][0];
    v61 = *(__m128 *)&v55->M[2][0];
    v62 = *(__m128 *)&v55->M[3][0];
    maskBounds = 0i64;
    *(__m128 *)&m.M[0][0] = _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v59, v59, 85), *(__m128 *)&m.M[1][0]),
                                  _mm_mul_ps(_mm_shuffle_ps(v59, v59, 0), *(__m128 *)&m.M[0][0])),
                                _mm_mul_ps(_mm_shuffle_ps(v59, v59, 170), *(__m128 *)&m.M[2][0])),
                              _mm_and_ps(
                                v59,
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
    v63 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v61, v61, 85), *(__m128 *)&m.M[1][0]),
            _mm_mul_ps(_mm_shuffle_ps(v61, v61, 0), v56));
    *(__m128 *)&m.M[1][0] = _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v60, v60, 85), *(__m128 *)&m.M[1][0]),
                                  _mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), v56)),
                                _mm_mul_ps(_mm_shuffle_ps(v60, v60, 170), *(__m128 *)&m.M[2][0])),
                              _mm_and_ps(
                                v60,
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
    *(__m128 *)&m.M[2][0] = _mm_add_ps(
                              _mm_add_ps(v63, _mm_mul_ps(_mm_shuffle_ps(v61, v61, 170), *(__m128 *)&m.M[2][0])),
                              _mm_and_ps(
                                v61,
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
    v11 = dataa;
    *(__m128 *)&m.M[0][2] = _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v62, v62, 85), v57),
                                  _mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), v56)),
                                _mm_mul_ps(_mm_shuffle_ps(v62, v62, 170), v58)),
                              _mm_and_ps(
                                v62,
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
    Scaleform::Render::Matrix4x4<float>::EncloseTransformHomogeneous(
      (Scaleform::Render::Matrix4x4<float> *)&m,
      &maskBounds,
      &dataa->AproxLocalBounds);
    if ( ((v81[10] & 0x30) - 16) & 0xFFFFFFDF )
    {
      v64 = _mm_cvtsi32_si128(v81[4]);
      v65 = _mm_cvtsi32_si128(v81[5]);
    }
    else
    {
      v64 = _mm_cvtsi32_si128(v81[5]);
      v65 = _mm_cvtsi32_si128(v81[4]);
    }
    LODWORD(v66) = (unsigned __int128)_mm_cvtepi32_ps(v65);
    LODWORD(v67) = (unsigned __int128)_mm_cvtepi32_ps(v64);
    if ( (float)((float)((float)(1.0 - maskBounds.y2) * v66) * 0.5) > v10->y2
      || (float)((float)((float)(1.0 - maskBounds.y1) * v66) * 0.5) < v10->y1
      || (float)((float)((float)(maskBounds.x2 + 1.0) * v67) * 0.5) < v10->x1
      || (float)((float)((float)(maskBounds.x1 + 1.0) * v67) * 0.5) > v10->x2 )
    {
      v6 = 5;
      v8 = 1;
    }
  }
  else
  {
    v39 = *(__m128 *)&v9->Mat.M[1][0];
    v40 = *(__m128 *)&v9->Mat.M[0][0];
    v11 = dataa;
    v41 = dataa->AproxLocalBounds;
    v42 = v40;
    v43 = _mm_unpacklo_ps(v40, v39);
    v44 = _mm_shuffle_ps(v42, v39, 255);
    v45 = _mm_mul_ps(_mm_unpacklo_ps((__m128)v41, (__m128)v41), v43);
    v46 = _mm_mul_ps(_mm_unpackhi_ps((__m128)v41, (__m128)v41), v43);
    v47 = v45;
    v48 = _mm_unpackhi_ps(v45, v46);
    v49 = _mm_unpacklo_ps(v47, v46);
    v50 = _mm_add_ps(v48, v49);
    v51 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 177), v48);
    v52 = _mm_min_ps(v50, v51);
    v53 = _mm_max_ps(v50, v51);
    maskBounds = (Scaleform::Render::Rect<float>)_mm_add_ps(
                                                   _mm_shuffle_ps(
                                                     _mm_min_ps(v52, _mm_shuffle_ps(v52, v52, 177)),
                                                     _mm_max_ps(v53, _mm_shuffle_ps(v53, v53, 177)),
                                                     136),
                                                   _mm_shuffle_ps(v44, v44, 136));
    if ( COERCE_FLOAT(_mm_shuffle_ps((__m128)maskBounds, (__m128)maskBounds, 85)) > v10->y2
      || maskBounds.y2 < v10->y1
      || maskBounds.x2 < v10->x1
      || maskBounds.x1 > v10->x2 )
    {
      v8 = 1;
      v6 = 3;
    }
  }
LABEL_53:
  v68 = v12->pRoot;
  if ( v68
    && (v69 = (unsigned __int128)((signed __int64)((signed __int64)&v68->pNode[-1]
                                                 - ((_QWORD)v68->pNode & 0xFFFFFFFFFFFFF000ui64))
                                * (signed __int128)5270498306774157605i64) >> 64,
        *(_BYTE *)((*(_QWORD *)(*(_QWORD *)(((_QWORD)v68->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                              + 8 * ((unsigned int)((signed __int64)v69 >> 4) + (v69 >> 63))
                              + 40) & 0xFFFFFFFFFFFFFFFEui64)
                 + 200) & 0x30)
    || !v8
    || v6 == 5
    || v6 == 3 && v11->Flags & 0x4000
    || v12 == (Scaleform::Render::TreeCacheNode *)v68 )
  {
    v72 = v12->Flags;
    if ( v72 & 2 )
    {
      v12->Flags = v72 & 0xFFFD;
      if ( v68 )
      {
        v73 = v12->pParent;
        if ( v73 )
          Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(v68, v73, 0x1000000u);
      }
    }
  }
  else
  {
    v70 = v12->Flags;
    if ( !(v70 & 2) )
    {
      v12->Flags = v70 | 2;
      if ( v68 )
      {
        v71 = v12->pParent;
        if ( v71 )
          Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(v68, v71, 0x1000000u);
      }
    }
    v5 &= 0xFFFFFFEF;
  }
  if ( v12->pMask )
  {
    if ( (v5 & 0x80u) != 0 )
    {
      Scaleform::Render::TransformArgs::GetMatrix3D(v9, v5, &m);
      Scaleform::Render::TransformArgs::TransformArgs(&ta, v9, &m);
      ta.Mat = Scaleform::Render::Matrix2x4<float>::Identity;
      Scaleform::Render::TreeCacheNode::updateMaskTransform(v12, &ta, v5);
    }
    else
    {
      Scaleform::Render::TransformArgs::TransformArgs(&ta, v9, &v9->Mat);
      v74 = v12->pMask;
      if ( v74 )
      {
        v75 = (signed __int64)((signed __int64)&v74->pNode[-1] - ((_QWORD)v74->pNode & 0xFFFFFFFFFFFFF000ui64))
            * (signed __int128)5270498306774157605i64;
        v76 = *(_QWORD *)(*(_QWORD *)(((_QWORD)v74->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                        + 8i64
                        * ((unsigned int)(*((_QWORD *)&v75 + 1) >> 4) + (unsigned int)(*((_QWORD *)&v75 + 1) >> 63))
                        + 40) & 0xFFFFFFFFFFFFFFFEui64;
        Scaleform::Render::Matrix2x4<float>::Prepend(&ta.Mat, (Scaleform::Render::Matrix2x4<float> *)(v76 + 16));
        v74->vfptr->UpdateTransform(v74, (Scaleform::Render::TreeNode::NodeData *)v76, &ta, v5);
        return (unsigned int)v5;
      }
    }
  }
  return (unsigned int)v5;
}

// File Line: 514
// RVA: 0x9D1D50
char __fastcall Scaleform::Render::TreeCacheNode::calcChildMaskBounds(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::Rect<float> *bounds, Scaleform::Render::TreeCacheNode *child)
{
  Scaleform::Render::TreeCacheNode *v3; // rbp
  Scaleform::Render::TreeCacheNode *v4; // rsi
  Scaleform::Render::Rect<float> *v5; // rdi
  Scaleform::Render::TreeCacheNode *v6; // r11
  signed __int64 v7; // r9
  unsigned __int64 v8; // rbx
  Scaleform::Render::TreeCacheNode *v9; // r9
  char v10; // al
  Scaleform::Render::TreeNode *v11; // rcx
  unsigned __int64 v12; // r8
  unsigned int *v13; // rdx
  __m128i v14; // xmm5
  __m128i v15; // xmm2
  char result; // al
  float v17; // xmm1_4
  float v18; // xmm3_4
  Scaleform::Render::TreeNode *v19; // rcx
  unsigned int v20; // xmm1_4
  unsigned __int64 v21; // r8
  unsigned int v22; // xmm0_4
  Scaleform::Render::TreeCacheNode *v23; // rax
  unsigned __int64 v24; // rdx
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm7
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm4
  __m128 v31; // xmm7
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm0
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm0
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  __m128 v41; // xmm3
  Scaleform::Render::Matrix2x4<float> pviewMatrix; // [rsp+20h] [rbp-58h]
  Scaleform::Render::Matrix2x4<float> v43; // [rsp+40h] [rbp-38h]

  v3 = child->pMask;
  v4 = this;
  v5 = bounds;
  v6 = child;
  v7 = (signed __int64)&v3->pNode[-1] - ((_QWORD)v3->pNode & 0xFFFFFFFFFFFFF000ui64);
  v8 = *(_QWORD *)(*(_QWORD *)(((_QWORD)v3->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)(v7 * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)(v7 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40) & 0xFFFFFFFFFFFFFFFEui64;
  if ( *(float *)(v8 + 136) <= *(float *)(v8 + 128) || *(float *)(v8 + 140) <= *(float *)(v8 + 132) )
    return 0;
  v9 = this;
  v10 = (*(_WORD *)(v8 + 10) >> 9) & 1;
  if ( this )
  {
    while ( !v10 )
    {
      v11 = v9->pNode;
      v9 = v9->pParent;
      v10 = (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v11 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                   + 8
                                   * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v11[-1] - ((unsigned __int64)v11 & 0xFFFFFFFFFFFFF000ui64))
                                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                    + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v11[-1]
                                                                                             - ((unsigned __int64)v11 & 0xFFFFFFFFFFFFF000ui64))
                                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                   + 40) & 0xFFFFFFFFFFFFFFFEui64)
                      + 10) >> 9) & 1;
      if ( !v9 )
        goto LABEL_6;
    }
    goto LABEL_7;
  }
LABEL_6:
  if ( v10 )
  {
LABEL_7:
    v12 = (_QWORD)v4->pRoot->pNode & 0xFFFFFFFFFFFFF000ui64;
    v13 = (unsigned int *)(*(_QWORD *)(*(_QWORD *)(v12 + 0x28)
                                     + 8
                                     * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4->pRoot->pNode[-1] - v12)
                                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                      + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4->pRoot->pNode[-1]
                                                                                               - v12)
                                                                              * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                     + 40) & 0xFFFFFFFFFFFFFFFEui64);
    if ( ((v13[50] & 0x30) - 16) & 0xFFFFFFDF )
    {
      v14 = _mm_cvtsi32_si128(v13[44]);
      v15 = _mm_cvtsi32_si128(v13[45]);
    }
    else
    {
      v14 = _mm_cvtsi32_si128(v13[45]);
      v15 = _mm_cvtsi32_si128(v13[44]);
    }
    result = 1;
    LODWORD(v17) = (unsigned __int128)_mm_cvtepi32_ps(v15);
    LODWORD(v18) = (unsigned __int128)_mm_cvtepi32_ps(v14);
    v5->y1 = (float)(v17 * 0.0) * 0.5;
    v5->x1 = (float)(v18 * 0.0) * 0.5;
    v5->y2 = (float)(v17 * 2.0) * 0.5;
    v5->x2 = (float)(v18 * 2.0) * 0.5;
    return result;
  }
  v19 = child->pNode;
  v20 = *(_DWORD *)(v8 + 20);
  v21 = (_QWORD)child->pNode & 0xFFFFFFFFFFFFF000ui64;
  pviewMatrix.M[0][0] = *(float *)(v8 + 16);
  *(_QWORD *)&pviewMatrix.M[0][1] = __PAIR__(*(_DWORD *)(v8 + 24), v20);
  v22 = *(_DWORD *)(v8 + 32);
  v23 = v3->pParent;
  pviewMatrix.M[0][3] = *(float *)(v8 + 28);
  *(_QWORD *)&pviewMatrix.M[1][0] = __PAIR__(*(_DWORD *)(v8 + 36), v22);
  *(_QWORD *)&pviewMatrix.M[1][2] = *(_QWORD *)(v8 + 40);
  if ( v23 == v4 )
  {
    v28 = *(__m128 *)&pviewMatrix.M[1][0];
    v27 = *(__m128 *)&pviewMatrix.M[0][0];
  }
  else
  {
    if ( v23 == v6 )
    {
      v24 = *(_QWORD *)(*(_QWORD *)(v21 + 40)
                      + 8
                      * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v19[-1] - v21)
                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                       + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v19[-1]
                                                                                            - v21)
                                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                      + 40) & 0xFFFFFFFFFFFFFFFEui64;
      v25 = *(__m128 *)(v24 + 16);
      v26 = *(__m128 *)(v24 + 32);
    }
    else
    {
      Scaleform::Render::TreeCacheNode::CalcViewMatrix(v3, &pviewMatrix);
      *(_OWORD *)&v43.M[0][0] = _xmm;
      *(__m128 *)&v43.M[1][0] = _xmm;
      Scaleform::Render::TreeCacheNode::CalcViewMatrix(v4, &v43);
      v25 = *(__m128 *)&v43.M[0][0];
      v26 = *(__m128 *)&v43.M[1][0];
    }
    v27 = _mm_and_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), *(__m128 *)&pviewMatrix.M[1][0]),
                _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), *(__m128 *)&pviewMatrix.M[0][0])),
              _mm_and_ps(v25, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
            (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
    v28 = _mm_and_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), *(__m128 *)&pviewMatrix.M[1][0]),
                _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), *(__m128 *)&pviewMatrix.M[0][0])),
              _mm_and_ps(v26, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
            (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
  }
  v29 = *(__m128 *)(v8 + 112);
  v30 = v27;
  v31 = _mm_unpacklo_ps(v27, v28);
  v32 = _mm_shuffle_ps(v30, v28, 255);
  result = 1;
  v33 = _mm_mul_ps(_mm_unpacklo_ps(v29, v29), v31);
  v34 = _mm_mul_ps(_mm_unpackhi_ps(v29, v29), v31);
  v35 = _mm_unpacklo_ps(v33, v34);
  v36 = _mm_unpackhi_ps(v33, v34);
  v37 = _mm_add_ps(v36, v35);
  v38 = _mm_add_ps(_mm_shuffle_ps(v35, v35, 177), v36);
  v39 = _mm_min_ps(v37, v38);
  v40 = _mm_max_ps(v37, v38);
  v41 = _mm_add_ps(
          _mm_shuffle_ps(
            _mm_min_ps(v39, _mm_shuffle_ps(v39, v39, 177)),
            _mm_max_ps(v40, _mm_shuffle_ps(v40, v40, 177)),
            136),
          _mm_shuffle_ps(v32, v32, 136));
  LODWORD(v5->x1) = v41.m128_i32[0];
  LODWORD(v5->y2) = (unsigned __int128)_mm_shuffle_ps(v41, v41, 255);
  LODWORD(v5->y1) = (unsigned __int128)_mm_shuffle_ps(v41, v41, 85);
  LODWORD(v5->x2) = (unsigned __int128)_mm_shuffle_ps(v41, v41, 170);
  return result;
}

// File Line: 580
// RVA: 0x9B6F90
int Scaleform::Render::SnapRectToPixels(...)
{
  __m128 v2; // xmm2
  signed int v3; // edx
  __m128 v4; // xmm2
  signed int v5; // edx
  __m128 v6; // xmm3
  signed int v7; // edx
  signed int v8; // edx

  *(float *)&numPixels = *(float *)&numPixels * 20.0;
  v2 = (__m128)LODWORD(rect->x1);
  v2.m128_f32[0] = v2.m128_f32[0] - *(float *)&numPixels;
  v3 = (signed int)v2.m128_f32[0];
  if ( (signed int)v2.m128_f32[0] != 0x80000000 && (float)v3 != v2.m128_f32[0] )
    v2.m128_f32[0] = (float)(v3 - (_mm_movemask_ps(_mm_unpacklo_ps(v2, v2)) & 1));
  LODWORD(rect->x1) = v2.m128_i32[0];
  v4 = (__m128)LODWORD(rect->y1);
  v4.m128_f32[0] = v4.m128_f32[0] - *(float *)&numPixels;
  v5 = (signed int)v4.m128_f32[0];
  if ( (signed int)v4.m128_f32[0] != 0x80000000 && (float)v5 != v4.m128_f32[0] )
    v4.m128_f32[0] = (float)(v5 - (_mm_movemask_ps(_mm_unpacklo_ps(v4, v4)) & 1));
  v6 = (__m128)numPixels;
  LODWORD(rect->y1) = v4.m128_i32[0];
  v6.m128_f32[0] = *(float *)&numPixels + rect->x2;
  v7 = (signed int)v6.m128_f32[0];
  if ( (signed int)v6.m128_f32[0] != 0x80000000 && (float)v7 != v6.m128_f32[0] )
    v6.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v6, v6)) & 1 ^ 1) + v7);
  *(float *)&numPixels = *(float *)&numPixels + rect->y2;
  LODWORD(rect->x2) = v6.m128_i32[0];
  v8 = (signed int)*(float *)&numPixels;
  if ( (signed int)*(float *)&numPixels != 0x80000000 && (float)v8 != *(float *)&numPixels )
    *(float *)&numPixels = (float)((_mm_movemask_ps(_mm_unpacklo_ps((__m128)numPixels, (__m128)numPixels)) & 1 ^ 1) + v8);
  LODWORD(rect->y2) = numPixels;
}

// File Line: 591
// RVA: 0x9D3230
signed __int64 __fastcall Scaleform::Render::TreeCacheNode::calcMaskBounds(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::Rect<float> *maskBounds, Scaleform::Render::Matrix2x4<float> *boundAreaMatrix, Scaleform::Render::Matrix3x4<float> *viewMatrix, Scaleform::Render::Matrix4x4<float> *viewProjMatrix)
{
  Scaleform::Render::TreeCacheNode *v5; // r11
  Scaleform::Render::TreeNode *v6; // rcx
  Scaleform::Render::Rect<float> *v7; // rsi
  Scaleform::Render::TreeCacheNode *v8; // rbx
  Scaleform::Render::Matrix3x4<float> *v9; // r12
  Scaleform::Render::Matrix2x4<float> *v10; // rdi
  signed __int64 v11; // r13
  Scaleform::Render::Rect<float> *v12; // r15
  unsigned __int64 v13; // r14
  signed __int64 result; // rax
  char v15; // al
  Scaleform::Render::TreeNode *v16; // rcx
  float v17; // xmm1_4
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  float v20; // xmm0_4
  float v21; // xmm1_4
  int v22; // xmm0_4
  float v23; // xmm1_4
  unsigned int v24; // xmm0_4
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm0
  __m128 v30; // xmm2
  __m128 v31; // xmm0
  __m128 v32; // xmm3
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm2
  float v38; // xmm4_4
  float v39; // xmm1_4
  float v40; // xmm3_4
  float v41; // xmm7_4
  float v42; // xmm0_4
  float v43; // xmm5_4
  float v44; // xmm6_4
  float v45; // xmm1_4
  float v46; // xmm0_4
  __m128 v47; // xmm2
  __m128 v48; // xmm5
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  __m128 v52; // xmm7
  __m128 v53; // xmm1
  __m128 v54; // xmm0
  __m128 v55; // xmm2
  __m128 v56; // xmm5
  unsigned __int64 v57; // rdx
  __int64 v58; // rax
  unsigned __int64 v59; // rbx
  float v60; // xmm3_4
  float v61; // xmm0_4
  float v62; // xmm2_4
  float v63; // xmm1_4
  float v64; // xmm2_4
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm0_4
  float v68; // xmm2_4
  float v69; // xmm3_4
  float v70; // xmm7_4
  float v71; // xmm5_4
  float v72; // xmm11_4
  float v73; // xmm4_4
  float v74; // xmm0_4
  float v75; // xmm1_4
  float v76; // xmm0_4
  float v77; // xmm0_4
  float v78; // xmm1_4
  float v79; // xmm0_4
  Scaleform::Render::Rect<float> rect; // [rsp+20h] [rbp-E0h]
  __m128 v81; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::Matrix3x4<float> pviewMatrix; // [rsp+40h] [rbp-C0h]
  __m128 Dst; // [rsp+70h] [rbp-90h]
  __m128 v84; // [rsp+80h] [rbp-80h]
  __m128 v85; // [rsp+90h] [rbp-70h]
  __m128 v86; // [rsp+A0h] [rbp-60h]

  v5 = this;
  v6 = this->pNode;
  v7 = maskBounds;
  v8 = v5->pMask;
  v9 = viewMatrix;
  v10 = boundAreaMatrix;
  v11 = (signed __int64)&v5->pRoot;
  v12 = (Scaleform::Render::Rect<float> *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                                     + 8
                                                     * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v6[-1] - ((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                      + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v6[-1] - ((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64))
                                                                                              * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                     + 40) & 0xFFFFFFFFFFFFFFFEui64);
  v13 = *(_QWORD *)(*(_QWORD *)(((_QWORD)v8->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                  + 8
                  * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v8->pNode[-1]
                                                                                        - ((_QWORD)v8->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                   + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v8->pNode[-1]
                                                                            - ((_QWORD)v8->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                  + 40) & 0xFFFFFFFFFFFFFFFEui64;
  if ( !v5->pRoot )
    return 0i64;
  v15 = (*(_WORD *)(v13 + 10) >> 9) & 1;
  while ( !v15 )
  {
    v16 = v5->pNode;
    v5 = v5->pParent;
    v15 = (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v16 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                 + 8
                                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v16[-1] - ((unsigned __int64)v16 & 0xFFFFFFFFFFFFF000ui64))
                                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v16[-1]
                                                                                           - ((unsigned __int64)v16 & 0xFFFFFFFFFFFFF000ui64))
                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                 + 40) & 0xFFFFFFFFFFFFFFFEui64)
                    + 10) >> 9) & 1;
    if ( !v5 )
    {
      if ( !v15 )
      {
        v17 = viewMatrix->M[0][1];
        v18 = *(__m128 *)(v13 + 112);
        pviewMatrix.M[0][0] = viewMatrix->M[0][0];
        *(_QWORD *)&pviewMatrix.M[0][1] = __PAIR__(LODWORD(viewMatrix->M[0][2]), LODWORD(v17));
        v19 = _mm_unpacklo_ps(v18, v18);
        v20 = viewMatrix->M[1][0];
        pviewMatrix.M[0][3] = viewMatrix->M[0][3];
        *(_QWORD *)&pviewMatrix.M[1][0] = __PAIR__(LODWORD(viewMatrix->M[1][1]), LODWORD(v20));
        *(_QWORD *)&pviewMatrix.M[1][2] = *(_QWORD *)&viewMatrix->M[1][2];
        v21 = *(float *)(v13 + 20);
        rect.x1 = *(float *)(v13 + 16);
        rect.x2 = *(float *)(v13 + 24);
        v22 = *(_DWORD *)(v13 + 32);
        rect.y1 = v21;
        v23 = *(float *)(v13 + 28);
        v81.m128_i32[0] = v22;
        v24 = *(_DWORD *)(v13 + 40);
        rect.y2 = v23;
        *(unsigned __int64 *)((char *)v81.m128_u64 + 4) = __PAIR__(v24, *(_DWORD *)(v13 + 36));
        v81.m128_i32[3] = *(_DWORD *)(v13 + 44);
        v25 = _mm_unpacklo_ps((__m128)rect, v81);
        v26 = _mm_shuffle_ps((__m128)rect, v81, 255);
        v27 = _mm_mul_ps(_mm_unpackhi_ps(v18, v18), v25);
        v28 = _mm_mul_ps(v19, v25);
        v29 = v28;
        v30 = _mm_unpackhi_ps(v28, v27);
        v31 = _mm_unpacklo_ps(v29, v27);
        v32 = _mm_add_ps(v30, v31);
        v33 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 177), v30);
        v34 = v32;
        v35 = _mm_max_ps(v32, v33);
        v36 = _mm_min_ps(v34, v33);
        rect = 0i64;
        v37 = _mm_add_ps(
                _mm_shuffle_ps(
                  _mm_min_ps(v36, _mm_shuffle_ps(v36, v36, 177)),
                  _mm_max_ps(v35, _mm_shuffle_ps(v35, v35, 177)),
                  136),
                _mm_shuffle_ps(v26, v26, 136));
        LODWORD(maskBounds->x1) = v37.m128_i32[0];
        LODWORD(v38) = (unsigned __int128)_mm_shuffle_ps(v37, v37, 255);
        LODWORD(v39) = (unsigned __int128)_mm_shuffle_ps(v37, v37, 85);
        LODWORD(v40) = (unsigned __int128)_mm_shuffle_ps(v37, v37, 170);
        maskBounds->y1 = v39;
        maskBounds->x2 = v40;
        maskBounds->y2 = v38;
        v41 = v12[7].y1;
        if ( v38 < v41 )
          return 1i64;
        v42 = v12[7].y2;
        if ( v42 < v39 )
          return 1i64;
        v43 = v12[7].x2;
        if ( v43 < v37.m128_f32[0] )
          return 1i64;
        v44 = v12[7].x1;
        if ( v40 < v44 )
          return 1i64;
        if ( v37.m128_f32[0] <= v44 )
          LODWORD(rect.x1) = v37.m128_i32[0];
        else
          rect.x1 = v12[7].x1;
        if ( v40 <= v43 )
          rect.x2 = v43;
        else
          rect.x2 = v40;
        if ( v39 <= v41 )
          rect.y1 = v39;
        else
          rect.y1 = v41;
        if ( v38 <= v42 )
          rect.y2 = v42;
        else
          rect.y2 = v38;
        Scaleform::Render::SnapRectToPixels(&rect, 8.0);
        v45 = rect.x1;
        v46 = rect.x2;
        *(_QWORD *)&v10->M[0][1] = 0i64;
        v10->M[1][0] = 0.0;
        v10->M[1][2] = 0.0;
        v47 = *(__m128 *)&pviewMatrix.M[0][0];
        v48 = *(__m128 *)&pviewMatrix.M[1][0];
        v49 = v46 - v45;
        v10->M[0][3] = v45;
        v50 = rect.y1;
        result = 2i64;
        v10->M[0][0] = v49;
        v51 = rect.y2;
        v10->M[1][3] = v50;
        v10->M[1][1] = v51 - v50;
        v52 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
        v53 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v47, v47, 85), *(__m128 *)&v10->M[1][0]),
                  _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), *(__m128 *)&v10->M[0][0])),
                _mm_and_ps(v47, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
        v54 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), *(__m128 *)&v10->M[0][0]);
        v55 = _mm_shuffle_ps(v48, v48, 85);
        v56 = _mm_and_ps(v48, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
        *(__m128 *)&v10->M[0][0] = _mm_and_ps(
                                     v53,
                                     (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
        *(__m128 *)&v10->M[1][0] = _mm_and_ps(
                                     _mm_add_ps(_mm_add_ps(_mm_mul_ps(v55, *(__m128 *)&v10->M[1][0]), v54), v56),
                                     v52);
        return result;
      }
      break;
    }
  }
  memset(&Dst, 0, 0x40ui64);
  Dst.m128_i32[0] = 1065353216;
  v84.m128_i32[1] = 1065353216;
  v85.m128_i32[2] = 1065353216;
  v86.m128_i32[3] = 1065353216;
  memset(&pviewMatrix, 0, 0x30ui64);
  pviewMatrix.M[0][0] = 1.0;
  pviewMatrix.M[1][1] = 1.0;
  pviewMatrix.M[2][2] = 1.0;
  Scaleform::Render::TreeCacheNode::CalcViewMatrix(v8, &pviewMatrix, (Scaleform::Render::Matrix4x4<float> *)&Dst);
  v57 = (unsigned __int128)((signed __int64)(*(_QWORD *)(*(_QWORD *)v11 + 32i64)
                                           - (*(_QWORD *)(*(_QWORD *)v11 + 32i64) & 0xFFFFFFFFFFFFF000ui64)
                                           - 56)
                          * (signed __int128)5270498306774157605i64) >> 64;
  v58 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)v11 + 32i64) & 0xFFFFFFFFFFFFF000ui64) + 0x28);
  rect = 0i64;
  v59 = *(_QWORD *)(v58 + 8 * ((unsigned int)((signed __int64)v57 >> 4) + (v57 >> 63)) + 40) & 0xFFFFFFFFFFFFFFFEui64;
  Dst = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(Dst, Dst, 85), *(__m128 *)&pviewMatrix.M[1][0]),
              _mm_mul_ps(_mm_shuffle_ps(Dst, Dst, 0), *(__m128 *)&pviewMatrix.M[0][0])),
            _mm_mul_ps(_mm_shuffle_ps(Dst, Dst, 170), *(__m128 *)&pviewMatrix.M[2][0])),
          _mm_and_ps(Dst, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
  v84 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v84, v84, 85), *(__m128 *)&pviewMatrix.M[1][0]),
              _mm_mul_ps(_mm_shuffle_ps(v84, v84, 0), *(__m128 *)&pviewMatrix.M[0][0])),
            _mm_mul_ps(_mm_shuffle_ps(v84, v84, 170), *(__m128 *)&pviewMatrix.M[2][0])),
          _mm_and_ps(v84, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
  v85 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v85, v85, 85), *(__m128 *)&pviewMatrix.M[1][0]),
              _mm_mul_ps(_mm_shuffle_ps(v85, v85, 0), *(__m128 *)&pviewMatrix.M[0][0])),
            _mm_mul_ps(_mm_shuffle_ps(v85, v85, 170), *(__m128 *)&pviewMatrix.M[2][0])),
          _mm_and_ps(v85, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
  v86 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v86, v86, 85), *(__m128 *)&pviewMatrix.M[1][0]),
              _mm_mul_ps(_mm_shuffle_ps(v86, v86, 0), *(__m128 *)&pviewMatrix.M[0][0])),
            _mm_mul_ps(_mm_shuffle_ps(v86, v86, 170), *(__m128 *)&pviewMatrix.M[2][0])),
          _mm_and_ps(v86, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
  Scaleform::Render::Matrix4x4<float>::EncloseTransformHomogeneous(
    (Scaleform::Render::Matrix4x4<float> *)&Dst,
    &rect,
    (Scaleform::Render::Rect<float> *)(v13 + 112));
  v60 = 1.0 - rect.y2;
  v61 = (float)*(signed int *)(v59 + 176);
  v62 = rect.x2 + 1.0;
  v63 = (float)*(signed int *)(v59 + 180);
  v7->x1 = (float)((float)(rect.x1 + 1.0) * v61) * 0.5;
  v64 = (float)(v62 * v61) * 0.5;
  v65 = 1.0 - rect.y1;
  v7->x2 = v64;
  v7->y1 = (float)(v60 * v63) * 0.5;
  v7->y2 = (float)(v65 * v63) * 0.5;
  rect = 0i64;
  Scaleform::Render::Matrix4x4<float>::MultiplyMatrix((Scaleform::Render::Matrix4x4<float> *)&Dst, viewProjMatrix, v9);
  Scaleform::Render::Matrix4x4<float>::EncloseTransformHomogeneous(
    (Scaleform::Render::Matrix4x4<float> *)&Dst,
    &rect,
    v12 + 7);
  v66 = (float)*(signed int *)(v59 + 176);
  v67 = (float)*(signed int *)(v59 + 180);
  v68 = (float)((float)(rect.x1 + 1.0) * v66) * 0.5;
  v69 = (float)((float)(1.0 - rect.y2) * v67) * 0.5;
  v70 = (float)((float)(rect.x2 + 1.0) * v66) * 0.5;
  v71 = v7->y2;
  v72 = (float)((float)(1.0 - rect.y1) * v67) * 0.5;
  if ( v71 < v69 )
    return 1i64;
  v73 = v7->y1;
  if ( v72 < v73 )
    return 1i64;
  if ( v70 < v7->x1 )
    return 1i64;
  v74 = v7->x2;
  if ( v74 < v68 )
    return 1i64;
  if ( v7->x1 <= v68 )
    v68 = v7->x1;
  if ( v74 <= v70 )
    v74 = (float)((float)(rect.x2 + 1.0) * v66) * 0.5;
  if ( v73 <= v69 )
    v69 = v7->y1;
  if ( v71 <= v72 )
    v71 = v72;
  v7->x1 = v68;
  v7->y1 = v69;
  v7->x2 = v74;
  v7->y2 = v71;
  rect.x1 = v68;
  rect.y1 = v69;
  rect.x2 = v74;
  rect.y2 = v71;
  Scaleform::Render::SnapRectToPixels(&rect, 8.0);
  v75 = rect.x1;
  v76 = rect.x2;
  *(_QWORD *)&v10->M[0][1] = 0i64;
  v10->M[1][0] = 0.0;
  v10->M[1][2] = 0.0;
  v77 = v76 - v75;
  v10->M[0][3] = v75;
  v78 = rect.y1;
  result = 2i64;
  v10->M[0][0] = v77;
  v79 = rect.y2;
  v10->M[1][3] = v78;
  v10->M[1][1] = v79 - v78;
  return result;
}

// File Line: 677
// RVA: 0x9D1420
__int64 __fastcall Scaleform::Render::TreeCacheNode::calcCacheableBounds(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::Rect<float> *returnBounds, Scaleform::Render::Matrix2x4<float> *areaMatrix, Scaleform::Render::Matrix3x4<float> *viewMatrix, Scaleform::Render::Matrix4x4<float> *viewProjMatrix, Scaleform::Render::Rect<float> *cullRect)
{
  Scaleform::Render::TreeCacheNode *v6; // r11
  Scaleform::Render::TreeNode *v7; // rcx
  Scaleform::Render::Rect<float> *v8; // r15
  Scaleform::Render::TreeCacheRoot **v9; // rdi
  Scaleform::Render::Matrix3x4<float> *v10; // r12
  Scaleform::Render::TreeCacheRoot *v11; // r9
  Scaleform::Render::Matrix2x4<float> *v12; // r14
  unsigned __int64 v13; // rsi
  __int64 result; // rax
  char v15; // al
  Scaleform::Render::TreeNode *v16; // rcx
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // eax
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  Scaleform::Render::Rect<float> v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm0
  __m128 v33; // xmm3
  __m128 v34; // xmm0
  __m128 v35; // xmm2
  __m128 v36; // xmm3
  __m128 v37; // xmm6
  __m128 v38; // xmm7
  __m128 v39; // xmm8
  __m128 v40; // xmm9
  Scaleform::Render::TreeNode *v41; // rcx
  unsigned __int64 v42; // rbx
  float v43; // xmm1_4
  float v44; // xmm0_4
  Scaleform::Render::TreeCacheRoot *v45; // rcx
  int v46; // edi
  Scaleform::Render::TreeNode *v47; // rdx
  __int64 v48; // rax
  unsigned __int64 v49; // rdx
  unsigned __int64 v50; // rbx
  int v51; // edx
  __m128i v52; // xmm1
  __int128 v53; // xmm0
  __m128 v54; // xmm1
  int v55; // eax
  __int128 v56; // xmm2
  __int128 v57; // xmm3
  unsigned int *v58; // rcx
  __m128 v59; // xmm10
  __int128 v60; // xmm11
  __int128 v61; // xmm13
  __int128 v62; // xmm12
  Scaleform::Render::StateBag *v63; // rax
  _QWORD *v64; // rsi
  unsigned int i; // ebx
  char v66; // dl
  signed int v67; // ecx
  signed int v68; // ecx
  signed int v69; // ecx
  signed int v70; // ecx
  __int128 v71; // [rsp+20h] [rbp-B9h]
  Scaleform::Render::Rect<float> pr; // [rsp+30h] [rbp-A9h]
  Scaleform::Render::Matrix4x4<float> v73; // [rsp+40h] [rbp-99h]

  v6 = this;
  v7 = this->pNode;
  v8 = returnBounds;
  v9 = &v6->pRoot;
  v10 = viewMatrix;
  v11 = v6->pRoot;
  v12 = areaMatrix;
  v13 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                  + 8
                  * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1]
                                                                                        - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                   + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1]
                                                                            - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                  + 40) & 0xFFFFFFFFFFFFFFFEui64;
  if ( !v11 )
    return 0i64;
  v15 = (*(_WORD *)(v13 + 10) >> 9) & 1;
  do
  {
    if ( v15 )
      break;
    v16 = v6->pNode;
    v6 = v6->pParent;
    v15 = (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v16 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                 + 8
                                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v16[-1] - ((unsigned __int64)v16 & 0xFFFFFFFFFFFFF000ui64))
                                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v16[-1]
                                                                                           - ((unsigned __int64)v16 & 0xFFFFFFFFFFFFF000ui64))
                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                 + 40) & 0xFFFFFFFFFFFFFFFEui64)
                    + 10) >> 9) & 1;
  }
  while ( v6 );
  v71 = 0i64;
  pr = 0i64;
  if ( v15 )
  {
    v41 = v11->pNode;
    pr = 0i64;
    v42 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v41 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                    + 8
                    * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v41[-1]
                                                                                          - ((unsigned __int64)v41 & 0xFFFFFFFFFFFFF000ui64))
                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                     + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v41[-1]
                                                                              - ((unsigned __int64)v41 & 0xFFFFFFFFFFFFF000ui64))
                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                    + 40) & 0xFFFFFFFFFFFFFFFEui64;
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v73, viewProjMatrix, v10);
    Scaleform::Render::Matrix4x4<float>::EncloseTransformHomogeneous(
      &v73,
      &pr,
      (Scaleform::Render::Rect<float> *)(v13 + 112));
    v37 = (__m128)(unsigned int)FLOAT_1_0;
    v40 = (__m128)LODWORD(pr.x1);
    v39 = (__m128)(unsigned int)FLOAT_1_0;
    v38 = (__m128)LODWORD(pr.x2);
    v43 = (float)*(signed int *)(v42 + 176);
    v40.m128_f32[0] = (float)((float)(pr.x1 + 1.0) * v43) * 0.5;
    v38.m128_f32[0] = (float)((float)(pr.x2 + 1.0) * v43) * 0.5;
    v44 = (float)*(signed int *)(v42 + 180);
    v39.m128_f32[0] = (float)((float)(1.0 - pr.y2) * v44) * 0.5;
    v37.m128_f32[0] = (float)((float)(1.0 - pr.y1) * v44) * 0.5;
  }
  else
  {
    v17 = v10->M[0][1];
    v18 = *(float *)(v13 + 124);
    v19 = *(float *)(v13 + 112);
    v73.M[0][0] = v10->M[0][0];
    *(_QWORD *)&v73.M[0][1] = __PAIR__(LODWORD(v10->M[0][2]), LODWORD(v17));
    v20 = v10->M[0][3];
    v73.M[1][0] = v10->M[1][0];
    v21 = v10->M[1][2];
    v73.M[0][3] = v20;
    v22 = v10->M[1][1];
    v73.M[1][2] = v21;
    v23 = *(float *)(v13 + 116);
    v73.M[1][1] = v22;
    v73.M[1][3] = v10->M[1][3];
    v24 = *(float *)(v13 + 120);
    returnBounds->y2 = v18;
    returnBounds->x1 = v19;
    returnBounds->y1 = v23;
    returnBounds->x2 = v24;
    v25 = *returnBounds;
    v26 = _mm_unpacklo_ps(*(__m128 *)&v73.M[0][0], *(__m128 *)&v73.M[1][0]);
    v27 = _mm_shuffle_ps(*(__m128 *)&v73.M[0][0], *(__m128 *)&v73.M[1][0], 255);
    v28 = _mm_mul_ps(_mm_unpacklo_ps((__m128)v25, (__m128)v25), v26);
    v29 = _mm_mul_ps(_mm_unpackhi_ps((__m128)v25, (__m128)v25), v26);
    v30 = v28;
    v31 = _mm_unpackhi_ps(v28, v29);
    v32 = _mm_unpacklo_ps(v30, v29);
    v33 = _mm_add_ps(v31, v32);
    v34 = _mm_add_ps(_mm_shuffle_ps(v32, v32, 177), v31);
    v35 = _mm_min_ps(v33, v34);
    v36 = _mm_max_ps(v33, v34);
    pr = (Scaleform::Render::Rect<float>)_mm_add_ps(
                                           _mm_shuffle_ps(
                                             _mm_min_ps(v35, _mm_shuffle_ps(v35, v35, 177)),
                                             _mm_max_ps(v36, _mm_shuffle_ps(v36, v36, 177)),
                                             136),
                                           _mm_shuffle_ps(v27, v27, 136));
    v37 = (__m128)LODWORD(pr.y2);
    v38 = (__m128)LODWORD(pr.x2);
    v39 = (__m128)LODWORD(pr.y1);
    v40 = (__m128)LODWORD(pr.x1);
  }
  v45 = *v9;
  v46 = 0;
  v47 = v45->pNode;
  *(_QWORD *)&pr.x1 = 0i64;
  *(_QWORD *)&pr.x2 = 0i64;
  v48 = *(_QWORD *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFF000ui64) + 0x28);
  v49 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v47[-1]
                                                            - ((unsigned __int64)v47 & 0xFFFFFFFFFFFFF000ui64))
                                           * (signed __int128)5270498306774157605i64) >> 64) >> 4;
  v50 = *(_QWORD *)(v48 + 8 * ((unsigned int)v49 + (v49 >> 63)) + 40) & 0xFFFFFFFFFFFFFFFEui64;
  if ( Scaleform::Render::Viewport::GetClippedRect<int>(
         (Scaleform::Render::Viewport *)(v50 + 160),
         (Scaleform::Render::Rect<int> *)&pr,
         1) )
  {
    v51 = *(_DWORD *)(v50 + 168);
    v52 = _mm_cvtsi32_si128(LODWORD(pr.y1) - *(_DWORD *)(v50 + 172));
    v53 = COERCE_UNSIGNED_INT((float)(LODWORD(pr.x1) - *(_DWORD *)(v50 + 168)));
    *(float *)&v71 = (float)(LODWORD(pr.x1) - *(_DWORD *)(v50 + 168));
    v54 = _mm_cvtepi32_ps(v52);
    v55 = LODWORD(pr.y2) - *(_DWORD *)(v50 + 172);
    DWORD1(v71) = v54.m128_i32[0];
    v56 = COERCE_UNSIGNED_INT((float)(LODWORD(pr.x2) - v51));
    *((float *)&v71 + 2) = (float)(LODWORD(pr.x2) - v51);
    v57 = COERCE_UNSIGNED_INT((float)v55);
    *((float *)&v71 + 3) = (float)v55;
  }
  else
  {
    v57 = HIDWORD(v71);
    v56 = DWORD2(v71);
    v54 = (__m128)DWORD1(v71);
    v53 = (unsigned int)v71;
  }
  v58 = (unsigned int *)&v71;
  if ( cullRect )
    v58 = (unsigned int *)cullRect;
  v59 = (__m128)*v58;
  v60 = v58[1];
  v61 = v58[2];
  v62 = v58[3];
  if ( !(((*(_DWORD *)(v50 + 200) & 0x30) - 16) & 0xFFFFFFDF) )
  {
    v59 = v54;
    v60 = v53;
    v61 = v57;
    v62 = v56;
  }
  LODWORD(pr.x1) = v59.m128_i32[0];
  LODWORD(pr.y1) = v60;
  LODWORD(pr.x2) = v61;
  LODWORD(pr.y2) = v62;
  v63 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::FilterState>((Scaleform::Render::TreeNode::NodeData *)v13);
  if ( v63 )
  {
    v64 = v63->pData;
    if ( v64 )
    {
      for ( i = 0; i < *((_DWORD *)v64 + 6); ++i )
        Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
          *(Scaleform::Render::Filter **)(v64[2] + 8i64 * i),
          &pr);
    }
  }
  v66 = 1;
  *(float *)&v61 = *(float *)&v61 + 32.0;
  v59.m128_f32[0] = v59.m128_f32[0] - 32.0;
  *(float *)&v60 = *(float *)&v60 - 32.0;
  *(float *)&v62 = *(float *)&v62 + 32.0;
  if ( *(float *)&v61 < v38.m128_f32[0]
    || *(float *)&v62 < v37.m128_f32[0]
    || v59.m128_f32[0] > v40.m128_f32[0]
    || *(float *)&v60 > v39.m128_f32[0] )
  {
    v66 = 0;
    if ( *(float *)&v62 < v39.m128_f32[0]
      || v37.m128_f32[0] < *(float *)&v60
      || v38.m128_f32[0] < v59.m128_f32[0]
      || *(float *)&v61 < v40.m128_f32[0] )
    {
      return 0i64;
    }
    if ( v59.m128_f32[0] > v40.m128_f32[0] )
      v40 = v59;
    if ( *(float *)&v61 <= v38.m128_f32[0] )
      v38 = (__m128)v61;
    if ( *(float *)&v60 > v39.m128_f32[0] )
      v39 = (__m128)v60;
    if ( *(float *)&v62 <= v37.m128_f32[0] )
      v37 = (__m128)v62;
  }
  v67 = (signed int)v40.m128_f32[0];
  if ( (signed int)v40.m128_f32[0] != 0x80000000 && (float)v67 != v40.m128_f32[0] )
    v40.m128_f32[0] = (float)(v67 - (_mm_movemask_ps(_mm_unpacklo_ps(v40, v40)) & 1));
  v68 = (signed int)v39.m128_f32[0];
  if ( (signed int)v39.m128_f32[0] != 0x80000000 && (float)v68 != v39.m128_f32[0] )
    v39.m128_f32[0] = (float)(v68 - (_mm_movemask_ps(_mm_unpacklo_ps(v39, v39)) & 1));
  v69 = (signed int)v38.m128_f32[0];
  if ( (signed int)v38.m128_f32[0] != 0x80000000 && (float)v69 != v38.m128_f32[0] )
    v38.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v38, v38)) & 1 ^ 1) + v69);
  v70 = (signed int)v37.m128_f32[0];
  if ( (signed int)v37.m128_f32[0] != 0x80000000 && (float)v70 != v37.m128_f32[0] )
    v37.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v37, v37)) & 1 ^ 1) + v70);
  LODWORD(v8->x2) = v38.m128_i32[0];
  LODWORD(v8->y2) = v37.m128_i32[0];
  LODWORD(v8->x1) = v40.m128_i32[0];
  LODWORD(v8->y1) = v39.m128_i32[0];
  *(_QWORD *)&v12->M[0][1] = 0i64;
  v12->M[1][0] = 0.0;
  v12->M[1][2] = 0.0;
  LOBYTE(v46) = v66 != 0;
  v12->M[0][0] = v38.m128_f32[0] - v40.m128_f32[0];
  v12->M[1][1] = v37.m128_f32[0] - v39.m128_f32[0];
  LODWORD(v12->M[0][3]) = v40.m128_i32[0];
  result = (unsigned int)(v46 + 1);
  LODWORD(v12->M[1][3]) = v39.m128_i32[0];
  return result;
}

// File Line: 766
// RVA: 0x95D0E0
void __fastcall Scaleform::Render::TreeCacheNode::CalcViewMatrix(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::Matrix2x4<float> *pviewMatrix)
{
  __m128 *v2; // r11
  signed __int64 v3; // r8
  Scaleform::Render::TreeCacheNode *v4; // r9
  _DWORD *v5; // rdx
  Scaleform::Render::TreeNode *v6; // rcx
  __m128 v7; // xmm7
  __m128 *v8; // rdx
  __m128 v9; // xmm5
  __m128 v10; // xmm2
  __m128 v11; // xmm0
  __m128 v12; // xmm5

  v2 = (__m128 *)pviewMatrix;
  v3 = (signed __int64)&this->pNode[-1] - ((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64);
  v4 = this->pParent;
  v5 = (_DWORD *)(*(_QWORD *)(*(_QWORD *)(((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                            + 8
                            * ((unsigned int)((signed __int64)((unsigned __int128)(v3
                                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                             + ((unsigned __int64)((unsigned __int128)(v3 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                            + 40) & 0xFFFFFFFFFFFFFFFEui64);
  LODWORD(v2->m128_u64[0]) = v5[4];
  HIDWORD(v2->m128_u64[0]) = v5[5];
  LODWORD(v2->m128_u64[1]) = v5[6];
  HIDWORD(v2->m128_u64[1]) = v5[7];
  v2[1].m128_i32[0] = v5[8];
  v2[1].m128_i32[1] = v5[9];
  v2[1].m128_i32[2] = v5[10];
  for ( v2[1].m128_i32[3] = v5[11]; v4; v2[1] = _mm_and_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v10, v2[1]), v11), v12), v7) )
  {
    v6 = v4->pNode;
    v4 = v4->pParent;
    v7 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
    v8 = (__m128 *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                              + 8
                              * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v6[-1] - ((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64))
                                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                               + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v6[-1]
                                                                                        - ((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64))
                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                              + 40) & 0xFFFFFFFFFFFFFFFEui64);
    v9 = v8[2];
    v10 = _mm_shuffle_ps(v8[2], v9, 85);
    v11 = _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), *v2);
    v12 = _mm_and_ps(v9, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
    *v2 = _mm_and_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v8[1], v8[1], 85), v2[1]),
                _mm_mul_ps(_mm_shuffle_ps(v8[1], v8[1], 0), *v2)),
              _mm_and_ps(v8[1], (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
            (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
  }
}

// File Line: 782
// RVA: 0x95D240
void __fastcall Scaleform::Render::TreeCacheNode::CalcViewMatrix(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::Matrix3x4<float> *pviewMatrix, Scaleform::Render::Matrix4x4<float> *pviewProj)
{
  Scaleform::Render::Matrix3x4<float> *v3; // rdi
  Scaleform::Render::TreeNode *v4; // rdx
  Scaleform::Render::Matrix4x4<float> *v5; // r14
  Scaleform::Render::TreeCacheNode *v6; // r15
  __int64 v7; // rax
  unsigned __int64 v8; // rdx
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rbx
  unsigned __int64 v11; // rcx
  Scaleform::Render::TreeCacheNode **v12; // r10
  Scaleform::Render::TreeCacheNode *v13; // r10
  __m128 v14; // xmm8
  __m128 *v15; // r8
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm9
  float v19; // ST14_4
  __m128 v20; // xmm6
  __m128 v21; // xmm0
  Scaleform::Render::TreeNode *v22; // r9
  unsigned __int64 v23; // r8
  signed __int64 v24; // r9
  __int64 v25; // rax
  unsigned __int64 v26; // rdx
  signed __int64 v27; // r9
  unsigned __int64 v28; // rdx
  _QWORD *v29; // rax
  Scaleform::Render::TreeNode *v30; // r9
  unsigned __int64 *v31; // r8
  unsigned __int64 v32; // rdx
  signed __int64 v33; // r9
  unsigned __int64 v34; // rdx
  _QWORD *v35; // rax
  __m128 *v36; // rdx
  __m128 v37; // xmm10
  float v38; // ST14_4
  __m128 v39; // xmm6
  __m128 v40; // xmm5
  __m128 v41; // ST28_16
  int v42; // eax
  __int64 v43; // rdx
  __m128 v44; // ST38_16
  __m128 v45; // ST48_16
  __m128 v46; // ST58_16
  __m128i v47; // xmm11
  __m128 v48; // ST68_16
  __m128i v49; // xmm9
  __m128i v50; // xmm3
  __m128i v51; // xmm2
  __m256i v52; // [rsp+18h] [rbp-79h]

  v3 = pviewMatrix;
  v4 = this->pNode;
  v5 = pviewProj;
  v6 = this;
  if ( !v4 )
  {
    v9 = 0i64;
LABEL_6:
    v10 = 0i64;
    goto LABEL_7;
  }
  v7 = *(_QWORD *)(((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64) + 0x28);
  v8 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1]
                                                           - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64))
                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4;
  v9 = *(_QWORD *)(v7 + 8 * ((unsigned int)v8 + (v8 >> 63)) + 40) & 0xFFFFFFFFFFFFFFFEui64;
  if ( !v9 || !((*(_WORD *)(v9 + 10) >> 11) & 1) )
    goto LABEL_6;
  v10 = (unsigned __int64)Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::ViewMatrix3DState>((Scaleform::Render::TreeNode::NodeData *)v9);
LABEL_7:
  if ( v9 && (*(_WORD *)(v9 + 10) >> 12) & 1 )
    v11 = (unsigned __int64)Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::ProjectionMatrix3DState>((Scaleform::Render::TreeNode::NodeData *)v9);
  else
    v11 = 0i64;
  v3->M[0][0] = *(float *)(v9 + 16);
  v12 = &v6->pParent;
  v3->M[0][1] = *(float *)(v9 + 20);
  v3->M[0][2] = *(float *)(v9 + 24);
  v3->M[0][3] = *(float *)(v9 + 28);
  v3->M[1][0] = *(float *)(v9 + 32);
  v3->M[1][1] = *(float *)(v9 + 36);
  v3->M[1][2] = *(float *)(v9 + 40);
  v3->M[1][3] = *(float *)(v9 + 44);
  v3->M[2][0] = *(float *)(v9 + 48);
  v3->M[2][1] = *(float *)(v9 + 52);
  v3->M[2][2] = *(float *)(v9 + 56);
  v3->M[2][3] = *(float *)(v9 + 60);
  if ( v6->pParent )
  {
    do
    {
      v13 = *v12;
      v14 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v;
      v52.m256i_i32[2] = LODWORD(v3->M[0][0]);
      v15 = (__m128 *)(*(_QWORD *)(*(_QWORD *)(((_QWORD)v13->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                 + 8
                                 * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v13->pNode[-1]
                                                                                           - ((_QWORD)v13->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                  + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v13->pNode[-1] - ((_QWORD)v13->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                 + 40) & 0xFFFFFFFFFFFFFFFEui64);
      v52.m256i_i32[3] = LODWORD(v3->M[0][1]);
      v16 = v15[1];
      v17 = v15[2];
      v18 = v15[3];
      v52.m256i_i32[4] = LODWORD(v3->M[0][2]);
      v19 = v3->M[0][3];
      v20 = *(__m128 *)&v52.m256i_u64[1];
      v52.m256i_i32[0] = LODWORD(v3->M[1][0]);
      v21 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), *(__m128 *)&v52.m256i_u64[1]);
      *(__int64 *)((char *)v52.m256i_i64 + 4) = *(_QWORD *)&v3->M[1][1];
      v52.m256i_i32[3] = LODWORD(v3->M[1][3]);
      v52.m256i_i64[2] = *(_QWORD *)&v3->M[2][0];
      v52.m256i_i64[3] = *(_QWORD *)&v3->M[2][2];
      *(__m128 *)&v3->M[0][0] = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), *(__m128 *)v52.m256i_i8), v21),
                                    _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), *(__m128 *)&v52.m256i_u64[2])),
                                  _mm_and_ps(
                                    (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v,
                                    v16));
      *(__m128 *)&v3->M[1][0] = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), *(__m128 *)v52.m256i_i8),
                                      _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v20)),
                                    _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), *(__m128 *)&v52.m256i_u64[2])),
                                  _mm_and_ps(v14, v17));
      *(__m128 *)&v3->M[2][0] = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), *(__m128 *)v52.m256i_i8),
                                      _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v20)),
                                    _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), *(__m128 *)&v52.m256i_u64[2])),
                                  _mm_and_ps(v14, v18));
      if ( !v10 )
      {
        v22 = v13->pNode;
        if ( (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v22 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                    + 8
                                    * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v13->pNode[-1]
                                                                                              - ((unsigned __int64)v22 & 0xFFFFFFFFFFFFF000ui64))
                                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                     + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v13->pNode[-1] - ((unsigned __int64)v22 & 0xFFFFFFFFFFFFF000ui64))
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                    + 40) & 0xFFFFFFFFFFFFFFFEui64)
                       + 10) >> 11) & 1 )
        {
          v23 = (unsigned __int64)v22 & 0xFFFFFFFFFFFFF000ui64;
          v24 = (signed __int64)&v22[-1] - ((unsigned __int64)v22 & 0xFFFFFFFFFFFFF000ui64);
          v25 = *(_QWORD *)(v23 + 40);
          v26 = *(_QWORD *)((*(_QWORD *)(v25
                                       + 8
                                       * (((unsigned __int64)((unsigned __int128)(v24
                                                                                * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                        + (unsigned int)((signed __int64)((unsigned __int128)(v24
                                                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                       + 40) & 0xFFFFFFFFFFFFFFFEui64)
                          + 64);
          if ( !v26 )
            goto LABEL_23;
          if ( v26 & 1 )
          {
            if ( (v26 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A68 )
              v10 = (*(_QWORD *)(v25
                               + 8
                               * (((unsigned __int64)((unsigned __int128)(v24 * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                + (unsigned int)((signed __int64)((unsigned __int128)(v24
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                  + 64;
          }
          else
          {
            v27 = *(_QWORD *)((*(_QWORD *)(v25
                                         + 8
                                         * (((unsigned __int64)((unsigned __int128)(v24
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                          + (unsigned int)((signed __int64)((unsigned __int128)(v24
                                                                                              * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                         + 40) & 0xFFFFFFFFFFFFFFFEui64)
                            + 72)
                + 4i64;
            v28 = v26 >> 1;
            if ( !v28 )
            {
LABEL_23:
              v10 = 0i64;
              goto LABEL_24;
            }
            v29 = (_QWORD *)v27;
            while ( *v29 != qword_142451A68 )
            {
              ++v10;
              v29 += 2;
              if ( v10 >= v28 )
                goto LABEL_23;
            }
            v10 = v27 + 16 * v10;
          }
        }
      }
LABEL_24:
      if ( !v11 )
      {
        v30 = v13->pNode;
        if ( (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v30 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                    + 8
                                    * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v13->pNode[-1]
                                                                                              - ((unsigned __int64)v30 & 0xFFFFFFFFFFFFF000ui64))
                                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                     + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v13->pNode[-1] - ((unsigned __int64)v30 & 0xFFFFFFFFFFFFF000ui64))
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                    + 40) & 0xFFFFFFFFFFFFFFFEui64)
                       + 10) >> 12) & 1 )
        {
          v31 = (unsigned __int64 *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v30 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                                + 8
                                                * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v30[-1] - ((unsigned __int64)v30 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                 + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v30[-1] - ((unsigned __int64)v30 & 0xFFFFFFFFFFFFF000ui64))
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                   + 64);
          v32 = *v31;
          if ( *v31 )
          {
            v11 = 0i64;
            if ( v32 & 1 )
            {
              if ( (v32 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A70 )
                v11 = (*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v30 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                 + 8
                                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v30[-1] - ((unsigned __int64)v30 & 0xFFFFFFFFFFFFF000ui64))
                                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v30[-1]
                                                                                           - ((unsigned __int64)v30 & 0xFFFFFFFFFFFFF000ui64))
                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                 + 40) & 0xFFFFFFFFFFFFFFFEui64)
                    + 64;
              goto LABEL_37;
            }
            v33 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v30 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                         + 8
                                         * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v30[-1] - ((unsigned __int64)v30 & 0xFFFFFFFFFFFFF000ui64))
                                                                                              * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                          + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v30[-1] - ((unsigned __int64)v30 & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                         + 40) & 0xFFFFFFFFFFFFFFFEui64)
                            + 72)
                + 4i64;
            v34 = v32 >> 1;
            if ( v34 )
            {
              v35 = (_QWORD *)(v31[1] + 4);
              while ( *v35 != qword_142451A70 )
              {
                ++v11;
                v35 += 2;
                if ( v11 >= v34 )
                  goto LABEL_36;
              }
              v11 = v33 + 16 * v11;
              goto LABEL_37;
            }
          }
LABEL_36:
          v11 = 0i64;
        }
      }
LABEL_37:
      v12 = &v13->pParent;
    }
    while ( *v12 );
  }
  if ( v10 && v11 )
  {
    v36 = *(__m128 **)(v10 + 8);
    v37 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v;
    v52.m256i_i64[1] = v36[1].m128_i64[0];
    v52.m256i_i32[4] = v36[1].m128_i32[2];
    v38 = v36[1].m128_f32[3];
    v39 = *(__m128 *)&v52.m256i_u64[1];
    v40 = v36[2];
    v41.m128_u64[0] = v36[3].m128_u64[0];
    v41.m128_i32[2] = v36[3].m128_i32[2];
    v42 = v36[3].m128_i32[3];
    v43 = *(_QWORD *)(v11 + 8);
    v41.m128_i32[3] = v42;
    v44 = *(__m128 *)(v43 + 16);
    v45.m128_i32[0] = *(_DWORD *)(v43 + 32);
    *(unsigned __int64 *)((char *)v45.m128_u64 + 4) = *(_QWORD *)(v43 + 36);
    v45.m128_i32[3] = *(_DWORD *)(v43 + 44);
    v46.m128_u64[0] = *(_QWORD *)(v43 + 48);
    v47 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v44, v44, 85), v40),
                         _mm_mul_ps(_mm_shuffle_ps(v44, v44, 0), v39)),
                       _mm_mul_ps(_mm_shuffle_ps(v44, v44, 170), v41)),
                     _mm_and_ps(v44, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
    v46.m128_u64[1] = *(_QWORD *)(v43 + 56);
    v48 = *(__m128 *)(v43 + 64);
    LODWORD(v5->M[0][0]) = _mm_cvtsi128_si32(v47);
    v49 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), v40),
                         _mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), v39)),
                       _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), v41)),
                     _mm_and_ps(v45, v37));
    v50 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), v40),
                         _mm_mul_ps(_mm_shuffle_ps(v46, v46, 0), v39)),
                       _mm_mul_ps(_mm_shuffle_ps(v46, v46, 170), v41)),
                     _mm_and_ps(v46, v37));
    LODWORD(v5->M[0][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v47, 4));
    LODWORD(v5->M[0][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v47, 8));
    LODWORD(v5->M[0][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v47, 12));
    v51 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), v40),
                         _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), v39)),
                       _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), v41)),
                     _mm_and_ps(v48, v37));
    LODWORD(v5->M[1][0]) = _mm_cvtsi128_si32(v49);
    LODWORD(v5->M[1][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v49, 4));
    LODWORD(v5->M[1][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v49, 8));
    LODWORD(v5->M[1][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v49, 12));
    LODWORD(v5->M[2][0]) = _mm_cvtsi128_si32(v50);
    LODWORD(v5->M[2][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v50, 4));
    LODWORD(v5->M[2][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v50, 8));
    LODWORD(v5->M[2][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v50, 12));
    LODWORD(v5->M[3][0]) = _mm_cvtsi128_si32(v51);
    LODWORD(v5->M[3][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v51, 4));
    LODWORD(v5->M[3][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v51, 8));
    LODWORD(v5->M[3][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v51, 12));
  }
  else
  {
    *(_OWORD *)&v5->M[0][0] = *(_OWORD *)&Scaleform::Render::Matrix4x4<float>::Identity.M[0][0];
    *(_OWORD *)&v5->M[1][0] = *(_OWORD *)&Scaleform::Render::Matrix4x4<float>::Identity.M[1][0];
    *(_OWORD *)&v5->M[2][0] = *(_OWORD *)&Scaleform::Render::Matrix4x4<float>::Identity.M[2][0];
    *(_OWORD *)&v5->M[3][0] = *(_OWORD *)&Scaleform::Render::Matrix4x4<float>::Identity.M[3][0];
  }
}

// File Line: 832
// RVA: 0x95B900
void __fastcall Scaleform::Render::TreeCacheNode::CalcCxform(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::Cxform *dest)
{
  Scaleform::Render::Cxform *v2; // r11
  signed __int64 v3; // r8
  unsigned __int64 v4; // rdx
  Scaleform::Render::TreeCacheNode *i; // r9
  Scaleform::Render::TreeNode *v6; // rcx
  __m128 v7; // xmm3
  __m128 *v8; // rdx
  __m128 v9; // xmm1

  v2 = dest;
  v3 = (signed __int64)&this->pNode[-1] - ((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64);
  v4 = *(_QWORD *)(*(_QWORD *)(((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)(v3 * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)(v3 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40) & 0xFFFFFFFFFFFFFFFEui64;
  *(_OWORD *)&v2->M[0][0] = *(_OWORD *)(v4 + 80);
  *(_OWORD *)&v2->M[1][0] = *(_OWORD *)(v4 + 96);
  for ( i = this->pParent; i; i = i->pParent )
  {
    v6 = i->pNode;
    if ( (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                + 8
                                * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&i->pNode[-1]
                                                                                          - ((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64))
                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                 + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&i->pNode[-1] - ((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64))
                                                                                     * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                + 40) & 0xFFFFFFFFFFFFFFFEui64)
                   + 10) >> 10) & 1 )
      break;
    v7 = *(__m128 *)&v2->M[1][0];
    v8 = (__m128 *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                              + 8
                              * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v6[-1] - ((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64))
                                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                               + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v6[-1]
                                                                                        - ((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64))
                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                              + 40) & 0xFFFFFFFFFFFFFFFEui64);
    v9 = _mm_mul_ps(v8[6], *(__m128 *)&v2->M[0][0]);
    *(__m128 *)&v2->M[0][0] = _mm_mul_ps(v8[5], *(__m128 *)&v2->M[0][0]);
    *(__m128 *)&v2->M[1][0] = _mm_add_ps(v7, v9);
  }
}

// File Line: 849
// RVA: 0x98F690
Scaleform::Render::Matrix4x4<float> *__fastcall Scaleform::Render::TreeCacheNode::GetViewProj(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::Matrix4x4<float> *result)
{
  Scaleform::Render::Matrix4x4<float> *v2; // rdi
  Scaleform::Render::TreeNode *v3; // rdx
  Scaleform::Render::TreeCacheNode *v4; // r14
  __int64 v5; // rax
  unsigned __int64 v6; // rdx
  Scaleform::Render::TreeNode::NodeData *v7; // rsi
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // rcx
  Scaleform::Render::TreeCacheNode **v10; // rax
  Scaleform::Render::TreeCacheNode *v11; // rsi
  Scaleform::Render::TreeNode *v12; // r9
  unsigned __int64 v13; // r8
  signed __int64 v14; // r9
  __int64 v15; // rax
  unsigned __int64 *v16; // r8
  unsigned __int64 v17; // rdx
  signed __int64 v18; // r9
  unsigned __int64 v19; // rdx
  _QWORD *v20; // rax
  Scaleform::Render::TreeNode *v21; // r9
  unsigned __int64 v22; // rdx
  unsigned __int64 v23; // rdx
  _QWORD *v24; // rax
  __m128 *v25; // rdx
  __m128 v26; // ST08_16
  __m128 v27; // xmm10
  __m128 v28; // xmm6
  __m128 v29; // ST28_16
  int v30; // eax
  __int64 v31; // rdx
  __m128 v32; // ST38_16
  __m128 v33; // ST48_16
  __m128 v34; // xmm5
  __m128 v35; // xmm9
  Scaleform::Render::Matrix4x4<float> *v36; // rax

  v2 = result;
  v3 = this->pNode;
  v4 = this;
  if ( !v3 )
  {
    v7 = 0i64;
LABEL_6:
    v8 = 0i64;
    goto LABEL_7;
  }
  v5 = *(_QWORD *)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64) + 0x28);
  v6 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1]
                                                           - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64))
                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4;
  v7 = (Scaleform::Render::TreeNode::NodeData *)(*(_QWORD *)(v5 + 8 * ((unsigned int)v6 + (v6 >> 63)) + 40) & 0xFFFFFFFFFFFFFFFEui64);
  if ( !v7 || !((v7->Flags >> 11) & 1) )
    goto LABEL_6;
  v8 = (unsigned __int64)Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::ViewMatrix3DState>(v7);
LABEL_7:
  if ( v7 && (v7->Flags >> 12) & 1 )
    v9 = (unsigned __int64)Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::ProjectionMatrix3DState>(v7);
  else
    v9 = 0i64;
  v10 = &v4->pParent;
  if ( v4->pParent )
  {
    do
    {
      if ( v8 && v9 )
        break;
      v11 = *v10;
      if ( !v8 )
      {
        v12 = v11->pNode;
        if ( (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                    + 8
                                    * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v11->pNode[-1]
                                                                                              - ((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64))
                                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                     + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v11->pNode[-1] - ((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64))
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                    + 40) & 0xFFFFFFFFFFFFFFFEui64)
                       + 10) >> 11) & 1 )
        {
          v13 = (unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64;
          v14 = (signed __int64)&v12[-1] - ((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64);
          v15 = *(_QWORD *)(v13 + 40);
          v16 = (unsigned __int64 *)((*(_QWORD *)(v15
                                                + 8
                                                * (((unsigned __int64)((unsigned __int128)(v14
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                                 + (unsigned int)((signed __int64)((unsigned __int128)(v14 * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                                + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                   + 64);
          v17 = *v16;
          if ( !*v16 )
            goto LABEL_25;
          if ( v17 & 1 )
          {
            if ( (v17 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A68 )
              v8 = (*(_QWORD *)(v15
                              + 8
                              * (((unsigned __int64)((unsigned __int128)(v14 * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                               + (unsigned int)((signed __int64)((unsigned __int128)(v14
                                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                              + 40) & 0xFFFFFFFFFFFFFFFEui64)
                 + 64;
          }
          else
          {
            v18 = *(_QWORD *)((*(_QWORD *)(v15
                                         + 8
                                         * (((unsigned __int64)((unsigned __int128)(v14
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                          + (unsigned int)((signed __int64)((unsigned __int128)(v14
                                                                                              * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                         + 40) & 0xFFFFFFFFFFFFFFFEui64)
                            + 72)
                + 4i64;
            v19 = v17 >> 1;
            if ( !v19 )
            {
LABEL_25:
              v8 = 0i64;
              goto LABEL_26;
            }
            v20 = (_QWORD *)(v16[1] + 4);
            while ( *v20 != qword_142451A68 )
            {
              ++v8;
              v20 += 2;
              if ( v8 >= v19 )
                goto LABEL_25;
            }
            v8 = v18 + 16 * v8;
          }
        }
      }
LABEL_26:
      if ( !v9 )
      {
        v21 = v11->pNode;
        if ( (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                    + 8
                                    * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v11->pNode[-1]
                                                                                              - ((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64))
                                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                     + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v11->pNode[-1] - ((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64))
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                    + 40) & 0xFFFFFFFFFFFFFFFEui64)
                       + 10) >> 12) & 1 )
        {
          v22 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                       + 8
                                       * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v21[-1] - ((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64))
                                                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                        + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v21[-1]
                                                                                                 - ((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64))
                                                                                * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                       + 40) & 0xFFFFFFFFFFFFFFFEui64)
                          + 64);
          if ( v22 )
          {
            v9 = 0i64;
            if ( v22 & 1 )
            {
              if ( (v22 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A70 )
                v9 = (*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                + 8
                                * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v21[-1] - ((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64))
                                                                                     * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                 + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v21[-1]
                                                                                          - ((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64))
                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                + 40) & 0xFFFFFFFFFFFFFFFEui64)
                   + 64;
              goto LABEL_39;
            }
            v23 = v22 >> 1;
            if ( v23 )
            {
              v24 = (_QWORD *)(*(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64)
                                                                  + 0x28)
                                                      + 8
                                                      * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v21[-1] - ((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                       + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v21[-1] - ((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64))
                                                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                      + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                         + 72)
                             + 4i64);
              while ( *v24 != qword_142451A70 )
              {
                ++v9;
                v24 += 2;
                if ( v9 >= v23 )
                  goto LABEL_38;
              }
              v9 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                          + 8
                                          * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v21[-1] - ((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64))
                                                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                           + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v21[-1] - ((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64))
                                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                          + 40) & 0xFFFFFFFFFFFFFFFEui64)
                             + 72)
                 + 4i64
                 + 16 * v9;
              goto LABEL_39;
            }
          }
LABEL_38:
          v9 = 0i64;
        }
      }
LABEL_39:
      v10 = &v11->pParent;
    }
    while ( v11->pParent );
  }
  if ( v8 && v9 )
  {
    v25 = *(__m128 **)(v8 + 8);
    v26.m128_u64[0] = v25[1].m128_u64[0];
    v27 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v;
    v26.m128_u64[1] = v25[1].m128_u64[1];
    v28 = v25[2];
    v29.m128_u64[0] = v25[3].m128_u64[0];
    v29.m128_i32[2] = v25[3].m128_i32[2];
    v30 = v25[3].m128_i32[3];
    v31 = *(_QWORD *)(v9 + 8);
    v29.m128_i32[3] = v30;
    v32 = *(__m128 *)(v31 + 16);
    v33.m128_i32[0] = *(_DWORD *)(v31 + 32);
    *(unsigned __int64 *)((char *)v33.m128_u64 + 4) = *(_QWORD *)(v31 + 36);
    v33.m128_i32[3] = *(_DWORD *)(v31 + 44);
    v34 = *(__m128 *)(v31 + 48);
    v35 = *(__m128 *)(v31 + 64);
    v36 = v2;
    *(__m128 *)&v2->M[0][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), v28),
                                    _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v26)),
                                  _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), v29)),
                                _mm_and_ps(
                                  v32,
                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
    *(__m128 *)&v2->M[1][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), v28),
                                    _mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), v26)),
                                  _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), v29)),
                                _mm_and_ps(v33, v27));
    *(__m128 *)&v2->M[2][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), v28),
                                    _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), v26)),
                                  _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), v29)),
                                _mm_and_ps(v34, v27));
    *(__m128 *)&v2->M[3][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v35, v35, 85), v28),
                                    _mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), v26)),
                                  _mm_mul_ps(_mm_shuffle_ps(v35, v35, 170), v29)),
                                _mm_and_ps(v35, v27));
  }
  else
  {
    *(_OWORD *)&v2->M[0][0] = *(_OWORD *)&Scaleform::Render::Matrix4x4<float>::Identity.M[0][0];
    *(_OWORD *)&v2->M[1][0] = *(_OWORD *)&Scaleform::Render::Matrix4x4<float>::Identity.M[1][0];
    *(_OWORD *)&v2->M[2][0] = *(_OWORD *)&Scaleform::Render::Matrix4x4<float>::Identity.M[2][0];
    *(_OWORD *)&v2->M[3][0] = *(_OWORD *)&Scaleform::Render::Matrix4x4<float>::Identity.M[3][0];
    v36 = v2;
  }
  return v36;
}

// File Line: 877
// RVA: 0x9F9BB0
void __fastcall Scaleform::Render::TreeCacheNode::updateFilterCache(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::TreeNode::NodeData *data, Scaleform::Render::TransformArgs *t, Scaleform::Render::TransformFlags flags, Scaleform::Render::Rect<float> *cullRect, Scaleform::Render::Matrix3x4<float> *m3, bool is3d)
{
  Scaleform::Render::TransformFlags v7; // ebx
  Scaleform::Render::TransformArgs *v8; // rbp
  Scaleform::Render::TreeNode::NodeData *v9; // r15
  Scaleform::Render::TreeCacheNode *v10; // rsi
  Scaleform::Render::FilterEffect *v11; // rdi
  Scaleform::Render::Matrix4x4<float> *viewProjMatrix; // rax
  int v13; // er14
  bool v14; // si
  __int128 v15; // xmm1
  bool v16; // r9
  Scaleform::Render::CacheEffectVtbl *v17; // rbx
  Scaleform::Render::StateBag *v18; // rax
  Scaleform::Render::Rect<float> returnBounds; // [rsp+30h] [rbp-58h]
  __int128 v20; // [rsp+40h] [rbp-48h]
  Scaleform::Render::Matrix2x4<float> areaMatrix; // [rsp+50h] [rbp-38h]

  v7 = flags;
  v8 = t;
  v9 = data;
  v10 = this;
  if ( (data->Flags >> 10) & 1 )
  {
    if ( flags & 0x203 )
    {
      v11 = (Scaleform::Render::FilterEffect *)this->Effects.pEffect;
      *(_OWORD *)&areaMatrix.M[0][0] = _xmm;
      *(__m128 *)&areaMatrix.M[1][0] = _xmm;
      returnBounds = 0i64;
      if ( v11 )
      {
        while ( v11->vfptr->GetType((Scaleform::Render::CacheEffect *)&v11->vfptr) != 3 )
        {
          v11 = (Scaleform::Render::FilterEffect *)v11->pNext;
          if ( !v11 )
            return;
        }
        if ( v11 )
        {
          viewProjMatrix = Scaleform::Render::TransformArgs::GetViewProj(v8);
          v13 = Scaleform::Render::TreeCacheNode::calcCacheableBounds(
                  v10,
                  &returnBounds,
                  &areaMatrix,
                  m3,
                  viewProjMatrix,
                  cullRect);
          if ( v13 )
          {
            v14 = 0;
            if ( v7 & 2 )
            {
              v15 = *(_OWORD *)&v8->Cx.M[1][0];
              returnBounds = *(Scaleform::Render::Rect<float> *)&v8->Cx.M[0][0];
              v20 = v15;
              Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(
                &v11->BoundsMatrix,
                (Scaleform::Render::Cxform *)&returnBounds);
            }
            if ( v7 & 1 )
            {
              v16 = is3d || v13 == 1;
              v14 = Scaleform::Render::FilterEffect::UpdateMatrix(v11, &areaMatrix, &v8->Mat, v16);
            }
            if ( v14 | ((unsigned int)v7 >> 9) & 1 )
            {
              v17 = v11->vfptr;
              v18 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::FilterState>(v9);
              v17->Update((Scaleform::Render::CacheEffect *)&v11->vfptr, (Scaleform::Render::State *)v18);
            }
          }
        }
      }
    }
  }
}

// File Line: 920
// RVA: 0x9F89B0
void __fastcall Scaleform::Render::TreeCacheNode::updateBlendCache(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::TreeNode::NodeData *data, Scaleform::Render::TransformArgs *t, Scaleform::Render::TransformFlags flags, Scaleform::Render::Rect<float> *cullRect, Scaleform::Render::Matrix3x4<float> *m3)
{
  Scaleform::Render::StateBag *v6; // rax
  char v7; // di
  Scaleform::Render::TransformArgs *v8; // rsi
  Scaleform::Render::StateData::Interface *v9; // rdx
  Scaleform::Render::TreeCacheNode *v10; // rbp
  char *v11; // r9
  unsigned __int64 v12; // rax
  signed __int64 v13; // r9
  unsigned __int64 v14; // rdx
  _QWORD *v15; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v16; // rbx
  Scaleform::Render::Matrix4x4<float> *viewProjMatrix; // rax
  Scaleform::Render::Rect<float> returnBounds; // [rsp+30h] [rbp-38h]
  Scaleform::Render::Matrix2x4<float> areaMatrix; // [rsp+40h] [rbp-28h]

  v6 = &data->States;
  v7 = flags;
  v8 = t;
  v9 = data->States.pInterface;
  v10 = this;
  if ( v9 )
  {
    if ( (unsigned __int8)v9 & 1 )
    {
      if ( ((unsigned __int64)v9 & 0xFFFFFFFFFFFFFFFEui64) != qword_142451A48 )
        return;
    }
    else
    {
      v11 = (char *)v6->pData;
      v12 = 0i64;
      v13 = (signed __int64)(v11 + 4);
      v14 = (unsigned __int64)v9 >> 1;
      if ( !v14 )
        return;
      v15 = (_QWORD *)v13;
      while ( *v15 != qword_142451A48 )
      {
        ++v12;
        v15 += 2;
        if ( v12 >= v14 )
          return;
      }
      v6 = (Scaleform::Render::StateBag *)(v13 + 16 * v12);
    }
    if ( v6 )
    {
      if ( v7 & 3 )
      {
        v16 = (Scaleform::Render::MatrixPoolImpl::HMatrix *)v10->Effects.pEffect;
        *(_OWORD *)&areaMatrix.M[0][0] = _xmm;
        *(__m128 *)&areaMatrix.M[1][0] = _xmm;
        returnBounds = 0i64;
        if ( v16 )
        {
          while ( ((unsigned int (__fastcall *)(Scaleform::Render::MatrixPoolImpl::HMatrix *))v16->pHandle[1].pHeader)(v16) != 1 )
          {
            v16 = (Scaleform::Render::MatrixPoolImpl::HMatrix *)v16[1].pHandle;
            if ( !v16 )
              return;
          }
          if ( v16 )
          {
            if ( v7 & 1 )
            {
              viewProjMatrix = Scaleform::Render::TransformArgs::GetViewProj(v8);
              if ( (unsigned int)Scaleform::Render::TreeCacheNode::calcCacheableBounds(
                                   v10,
                                   &returnBounds,
                                   &areaMatrix,
                                   m3,
                                   viewProjMatrix,
                                   cullRect) )
                Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(v16 + 19, &areaMatrix);
            }
            Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(v16 + 19, &v8->Cx);
          }
        }
      }
    }
  }
}

// File Line: 948
// RVA: 0x94D5D0
void __fastcall Scaleform::Render::TreeCacheContainer::~TreeCacheContainer(Scaleform::Render::TreeCacheContainer *this)
{
  Scaleform::Render::TreeCacheContainer *v1; // rsi
  Scaleform::Render::TreeCacheNode *i; // rcx
  signed __int64 v3; // rax
  Scaleform::Render::TreeCacheNode *v4; // rdi

  v1 = this;
  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheContainer::`vftable;
  for ( i = this->Children.Root.pNext; ; i = v4 )
  {
    v3 = (signed __int64)&v1->SortParentBounds.x2;
    if ( v1 == (Scaleform::Render::TreeCacheContainer *)-112i64 )
      v3 = 0i64;
    if ( i == (Scaleform::Render::TreeCacheNode *)v3 )
      break;
    v4 = i->pNext;
    i->pParent = 0i64;
    i->pNext = 0i64;
    i->pPrev = 0i64;
    if ( i->pRoot )
      ((void (__cdecl *)(Scaleform::Render::TreeCacheNode *))i->vfptr->HandleRemoveNode)(i);
  }
  Scaleform::Render::TreeCacheNode::~TreeCacheNode((Scaleform::Render::TreeCacheNode *)&v1->vfptr);
}

// File Line: 973
// RVA: 0x9BF480
void __fastcall Scaleform::Render::TreeCacheContainer::UpdateTransform(Scaleform::Render::TreeCacheContainer *this, Scaleform::Render::TreeNode::NodeData *pbaseData, Scaleform::Render::TransformArgs *t, Scaleform::Render::TransformFlags flags)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  Scaleform::Render::ProjectionMatrix3DState *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  Scaleform::Render::TransformArgs *v10; // rbx
  Scaleform::Render::TreeNode::NodeData *v11; // r13
  Scaleform::Render::TreeCacheContainer *v12; // rdi
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  Scaleform::Render::TransformFlags v28; // eax
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  Scaleform::Render::TransformFlags v32; // er12
  Scaleform::Render::TreeCacheNode *v33; // r14
  signed __int64 v34; // rax
  signed __int64 v35; // rax
  char v36; // si
  unsigned __int64 v37; // rdi
  int v38; // esi
  __m128 v39; // xmm4
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  unsigned int v42; // esi
  float v43; // xmm1_4
  float v44; // xmm0_4
  __m128 v45; // xmm6
  __m128 v46; // xmm5
  __m128 v47; // xmm7
  char v48; // r15
  Scaleform::Render::StateBag *v49; // rax
  Scaleform::Render::FilterSet *v50; // rcx
  Scaleform::Render::StateBag *v51; // rax
  unsigned int v52; // eax
  signed int v53; // ecx
  __m128 v54; // xmm1
  Scaleform::Render::TreeCacheRoot *v55; // rax
  __m128 v56; // xmm1
  __m128 v57; // xmm0
  __m128 v58; // xmm2
  __m128 v59; // xmm1
  Scaleform::Render::Rect<float> cullRect; // [rsp+30h] [rbp-D0h]
  __m128 v61; // [rsp+40h] [rbp-C0h]
  __m128 v62; // [rsp+50h] [rbp-B0h]
  __m128 v63; // [rsp+60h] [rbp-A0h]
  Scaleform::Render::ViewMatrix3DState *v64; // [rsp+70h] [rbp-90h]
  Scaleform::Render::ProjectionMatrix3DState *v65; // [rsp+78h] [rbp-88h]
  float v66; // [rsp+80h] [rbp-80h]
  float v67; // [rsp+84h] [rbp-7Ch]
  float v68; // [rsp+88h] [rbp-78h]
  float v69; // [rsp+8Ch] [rbp-74h]
  float v70; // [rsp+90h] [rbp-70h]
  float v71; // [rsp+94h] [rbp-6Ch]
  float v72; // [rsp+98h] [rbp-68h]
  float v73; // [rsp+9Ch] [rbp-64h]
  float v74; // [rsp+A0h] [rbp-60h]
  float v75; // [rsp+A4h] [rbp-5Ch]
  float v76; // [rsp+A8h] [rbp-58h]
  float v77; // [rsp+ACh] [rbp-54h]
  float v78; // [rsp+B0h] [rbp-50h]
  float v79; // [rsp+B4h] [rbp-4Ch]
  float v80; // [rsp+B8h] [rbp-48h]
  float v81; // [rsp+BCh] [rbp-44h]
  char v82; // [rsp+C0h] [rbp-40h]
  __m128 v83; // [rsp+D0h] [rbp-30h]
  __m128 v84; // [rsp+E0h] [rbp-20h]
  __m128 v85; // [rsp+F0h] [rbp-10h]
  __m128 v86; // [rsp+100h] [rbp+0h]
  Scaleform::Render::Matrix3x4<float> m; // [rsp+110h] [rbp+10h]
  Scaleform::Render::TreeCacheContainer *v88; // [rsp+1C0h] [rbp+C0h]
  signed __int64 i; // [rsp+1C8h] [rbp+C8h]

  v88 = this;
  v4 = t->CullRect.x1;
  v5 = t->CullRect.y1;
  v64 = t->viewState;
  v6 = t->projState;
  cullRect.x1 = v4;
  v7 = t->CullRect.x2;
  cullRect.y1 = v5;
  v65 = v6;
  LOBYTE(v6) = t->bRecomputeViewProj;
  v8 = t->CullRect.y2;
  cullRect.x2 = v7;
  v9 = t->ViewProj.M[0][0];
  v10 = t;
  v11 = pbaseData;
  v12 = this;
  cullRect.y2 = v8;
  v13 = t->ViewProj.M[0][1];
  v66 = v9;
  v82 = (char)v6;
  v14 = t->ViewProj.M[0][2];
  v67 = v13;
  v15 = t->ViewProj.M[0][3];
  v68 = v14;
  v16 = t->ViewProj.M[1][0];
  v69 = v15;
  v17 = t->ViewProj.M[1][1];
  v70 = v16;
  v18 = t->ViewProj.M[1][2];
  v71 = v17;
  v19 = t->ViewProj.M[1][3];
  v72 = v18;
  v20 = t->ViewProj.M[2][0];
  v73 = v19;
  v21 = t->ViewProj.M[2][1];
  v74 = v20;
  v22 = t->ViewProj.M[2][2];
  v75 = v21;
  v23 = t->ViewProj.M[2][3];
  v76 = v22;
  v24 = t->ViewProj.M[3][0];
  v77 = v23;
  v25 = t->ViewProj.M[3][1];
  v78 = v24;
  v26 = t->ViewProj.M[3][2];
  v79 = v25;
  v27 = t->ViewProj.M[3][3];
  v80 = v26;
  v81 = v27;
  v28 = Scaleform::Render::TreeCacheNode::updateCulling(
          (Scaleform::Render::TreeCacheNode *)&this->vfptr,
          pbaseData,
          t,
          &cullRect,
          flags);
  v29 = v11->AproxParentBounds.y2;
  v30 = v11->AproxParentBounds.x2;
  v31 = v11->AproxParentBounds.y1;
  v32 = v28;
  v12->SortParentBounds.x1 = v11->AproxParentBounds.x1;
  v12->SortParentBounds.y1 = v31;
  v12->SortParentBounds.x2 = v30;
  v12->SortParentBounds.y2 = v29;
  v12->Flags &= 0xFBFFu;
  v33 = v12->Children.Root.pNext;
  v34 = (signed __int64)&v12->Children;
  for ( i = (signed __int64)&v12->Children; ; v34 = i )
  {
    v35 = v34 ? v34 - 8 : 0i64;
    if ( v33 == (Scaleform::Render::TreeCacheNode *)v35 )
      break;
    v36 = v33->UpdateFlags;
    v37 = *(_QWORD *)(*(_QWORD *)(((_QWORD)v33->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                    + 8
                    * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v33->pNode[-1]
                                                                                          - ((_QWORD)v33->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                     + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v33->pNode[-1]
                                                                              - ((_QWORD)v33->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                    + 40) & 0xFFFFFFFFFFFFFFFEui64;
    v33->UpdateFlags &= 0xFFFFFFFC;
    v38 = v32 | v36 & 3;
    if ( (*(_WORD *)(v37 + 10) >> 9) & 1 )
    {
      if ( v32 & 0x40 )
      {
        Scaleform::Render::TransformArgs::GetMatrix3D(v10, v32, &m);
        v38 &= 0xFFFFFFBF;
        goto LABEL_16;
      }
      if ( (v32 & 0x80u) != 0 )
      {
        Scaleform::Render::TransformArgs::GetMatrix3D(v10, v32, &m);
LABEL_16:
        v45 = *(__m128 *)(v37 + 16);
        v46 = *(__m128 *)(v37 + 32);
        v47 = *(__m128 *)(v37 + 48);
        v61 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m.M[0][0], *(__m128 *)&m.M[0][0], 85), v46),
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m.M[0][0], *(__m128 *)&m.M[0][0], 0), v45)),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m.M[0][0], *(__m128 *)&m.M[0][0], 170), v47)),
                _mm_and_ps(
                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v,
                  *(__m128 *)&m.M[0][0]));
        v62 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m.M[1][0], *(__m128 *)&m.M[1][0], 85), v46),
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m.M[1][0], *(__m128 *)&m.M[1][0], 0), v45)),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m.M[1][0], *(__m128 *)&m.M[1][0], 170), v47)),
                _mm_and_ps(
                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v,
                  *(__m128 *)&m.M[1][0]));
        v63 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m.M[2][0], *(__m128 *)&m.M[2][0], 85), v46),
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m.M[2][0], *(__m128 *)&m.M[2][0], 0), v45)),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m.M[2][0], *(__m128 *)&m.M[2][0], 170), v47)),
                _mm_and_ps(
                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v,
                  *(__m128 *)&m.M[2][0]));
      }
      v42 = v38 | 0x80;
      goto LABEL_18;
    }
    if ( v32 & 0x40 )
    {
      v39 = *(__m128 *)(v37 + 16);
      v40 = *(__m128 *)(v37 + 32);
      v41 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v10->Mat.M[1][0], *(__m128 *)&v10->Mat.M[1][0], 85), v40),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v10->Mat.M[1][0], *(__m128 *)&v10->Mat.M[1][0], 0), v39)),
              _mm_and_ps(
                *(__m128 *)&v10->Mat.M[1][0],
                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
      v83 = _mm_and_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v10->Mat.M[0][0], *(__m128 *)&v10->Mat.M[0][0], 85), v40),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v10->Mat.M[0][0], *(__m128 *)&v10->Mat.M[0][0], 0), v39)),
                _mm_and_ps(
                  *(__m128 *)&v10->Mat.M[0][0],
                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
      v84 = _mm_and_ps(
              v41,
              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
    }
    else
    {
      v83 = *(__m128 *)(v37 + 16);
      v84 = *(__m128 *)(v37 + 32);
    }
    v42 = v38 | 0x40;
    if ( (v32 & 0x80u) != 0 )
    {
      v43 = v10->Mat3D.M[0][1];
      v61.m128_i32[0] = LODWORD(v10->Mat3D.M[0][0]);
      *(unsigned __int64 *)((char *)v61.m128_u64 + 4) = __PAIR__(LODWORD(v10->Mat3D.M[0][2]), LODWORD(v43));
      v44 = v10->Mat3D.M[1][0];
      v61.m128_i32[3] = LODWORD(v10->Mat3D.M[0][3]);
      v62.m128_u64[0] = __PAIR__(LODWORD(v10->Mat3D.M[1][1]), LODWORD(v44));
      v62.m128_u64[1] = *(_QWORD *)&v10->Mat3D.M[1][2];
      v63 = *(__m128 *)&v10->Mat3D.M[2][0];
    }
LABEL_18:
    Scaleform::Render::TransformArgs::SetViewProj(
      (Scaleform::Render::TransformArgs *)&cullRect,
      (Scaleform::Render::TreeNode::NodeData *)v37,
      v10);
    v48 = 1;
    if ( (v11->Flags >> 10) & 1 )
    {
      v49 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::FilterState>(v11);
      if ( v49 )
      {
        v50 = (Scaleform::Render::FilterSet *)v49->pData;
        if ( v50 )
        {
          v48 = 1;
          if ( Scaleform::Render::FilterSet::IsContributing(v50) )
            v48 = 0;
        }
      }
      v42 |= 0x100u;
    }
    v51 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::BlendState>(v11);
    if ( v51 )
    {
      v52 = v51->DataValue;
      if ( v52 <= 0xE )
      {
        v53 = 24804;
        if ( _bittest(&v53, v52) )
        {
          v42 |= 0x100u;
          if ( v52 == 2 )
          {
            v42 |= 0x400u;
          }
          else if ( !_bittest((const signed int *)&v32, 0xAu) )
          {
            v55 = v88->pRoot;
            if ( v55 )
              v55->EnableBlendTarget = 1;
          }
LABEL_29:
          v85 = *(__m128 *)(v37 + 80);
          v54 = *(__m128 *)(v37 + 96);
          goto LABEL_30;
        }
      }
    }
    if ( !v48 )
      goto LABEL_29;
    v56 = *(__m128 *)&v10->Cx.M[0][0];
    v57 = _mm_mul_ps(*(__m128 *)(v37 + 80), v56);
    v58 = _mm_mul_ps(*(__m128 *)(v37 + 96), v56);
    v59 = *(__m128 *)&v10->Cx.M[1][0];
    v85 = v57;
    v54 = _mm_add_ps(v59, v58);
LABEL_30:
    v86 = v54;
    v33->vfptr->UpdateTransform(
      v33,
      (Scaleform::Render::TreeNode::NodeData *)v37,
      (Scaleform::Render::TransformArgs *)&cullRect,
      (Scaleform::Render::TransformFlags)v42);
    v33 = v33->pNext;
  }
}

// File Line: 1077
// RVA: 0x9901E0
void __fastcall Scaleform::Render::TreeCacheContainer::HandleChanges(Scaleform::Render::TreeCacheContainer *this, unsigned int changeBits)
{
  __int16 v2; // bx
  Scaleform::Render::TreeCacheContainer *v3; // rsi
  Scaleform::Render::TreeCacheNode *v4; // rcx
  unsigned int v5; // er8
  signed __int64 v6; // rdx
  Scaleform::Render::TreeNode *v7; // rcx
  char v8; // r9
  unsigned __int64 v9; // rdx
  unsigned __int64 v10; // r12
  __int64 v11; // rax
  unsigned __int64 v12; // r13
  Scaleform::Render::TreeCacheNode *v13; // rbx
  __int64 v14; // r14
  signed __int64 v15; // rcx
  __int64 v16; // r15
  Scaleform::Render::TreeCacheNode *v17; // rbp
  Scaleform::Render::TreeCacheContainer *v18; // rdi
  Scaleform::Render::TreeCacheNode *v19; // rdi
  signed __int64 v20; // rax
  Scaleform::Render::TreeCacheRoot *v21; // rcx
  signed int v22; // eax
  unsigned __int64 v23; // rcx
  __int64 v24; // rax
  __int64 v25; // rcx
  __int64 v26; // rdx
  signed int v27; // eax
  signed __int64 v28; // rax
  signed __int64 v29; // rax
  Scaleform::Render::TreeCacheNode *v30; // rdi
  Scaleform::Render::TreeCacheRoot *v31; // rcx
  __int64 v32[2]; // [rsp+20h] [rbp-38h]

  v2 = changeBits;
  v3 = this;
  if ( changeBits & 0x20 )
  {
    v4 = this->pParent;
    if ( v4 )
    {
      v5 = v4->Flags & 0xC;
      if ( v5 == 12 )
      {
        v6 = 12i64;
LABEL_8:
        v3->vfptr->propagateEdgeAA((Scaleform::Render::TreeCacheNode *)&v3->vfptr, (Scaleform::Render::EdgeAAMode)v6);
        goto LABEL_9;
      }
    }
    else
    {
      v5 = 4;
    }
    v6 = *(_WORD *)((*(_QWORD *)(*(_QWORD *)(((_QWORD)v3->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                               + 8
                               * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3->pNode[-1]
                                                                                         - ((_QWORD)v3->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3->pNode[-1] - ((_QWORD)v3->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                  + 10) & 0xC;
    if ( !(_DWORD)v6 )
      v6 = v5;
    goto LABEL_8;
  }
LABEL_9:
  if ( v2 & 0x300 )
  {
    v7 = v3->pNode;
    v8 = 0;
    v9 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1]
                                                             - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                            * (signed __int128)5270498306774157605i64) >> 64) >> 4;
    v10 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                    + 8 * ((unsigned int)v9 + (v9 >> 63))
                    + 40) & 0xFFFFFFFFFFFFFFFEui64;
    v11 = *(_QWORD *)(v10 + 144);
    if ( v11 )
    {
      if ( v11 & 1 )
        v12 = *(_QWORD *)((v11 & 0xFFFFFFFFFFFFFFFEui64) + 8);
      else
        v12 = (*(_QWORD *)(v10 + 152) != 0i64) + 1i64;
    }
    else
    {
      v12 = 0i64;
    }
    v13 = v3->Children.Root.pNext;
    v14 = 0i64;
    if ( v12 )
    {
      do
      {
        if ( *(_BYTE *)(v10 + 144) & 1 )
          v15 = (*(_QWORD *)(v10 + 144) & 0xFFFFFFFFFFFFFFFEui64) + 16;
        else
          v15 = v10 + 144;
        v16 = *(_QWORD *)(v15 + 8 * v14);
        v17 = *(Scaleform::Render::TreeCacheNode **)(v16 + 24);
        if ( v17 == v13 )
        {
          v13 = v13->pNext;
        }
        else
        {
          if ( !v17 )
            goto LABEL_34;
          v18 = (Scaleform::Render::TreeCacheContainer *)v17->pParent;
          if ( v18 != v3 || !v17->pPrev )
          {
            if ( v18 )
            {
              Scaleform::Render::TreeCacheNode::RemoveFromParent(*(Scaleform::Render::TreeCacheNode **)(v16 + 24));
              v21 = v18->pRoot;
              if ( v21 )
              {
                v22 = 0x1000000;
                if ( (v18->UpdateFlags & 0x80000000) == 0 )
                {
                  v18->pNextUpdate = v21->pUpdateList;
                  v21->pUpdateList = (Scaleform::Render::TreeCacheNode *)&v18->vfptr;
                  v22 = -2130706432;
                }
                v18->UpdateFlags |= v22;
              }
            }
LABEL_34:
            v23 = *(_QWORD *)(*(_QWORD *)((v16 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                            + 8
                            * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v16
                                                                                                  - (v16 & 0xFFFFFFFFFFFFF000ui64)
                                                                                                  - 56)
                                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                             + ((unsigned __int64)((unsigned __int128)((signed __int64)(v16
                                                                                      - (v16 & 0xFFFFFFFFFFFFF000ui64)
                                                                                      - 56)
                                                                     * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                            + 40) & 0xFFFFFFFFFFFFFFFEui64;
            LOWORD(v32[0]) = v3->Depth + 1;
            v24 = (*(__int64 (__fastcall **)(unsigned __int64, Scaleform::Render::TreeCacheContainer *, Scaleform::Render::TreeCacheNode *, __int64, __int64))(*(_QWORD *)v23 + 48i64))(
                    v23,
                    v3,
                    v13->pPrev,
                    v16,
                    v32[0]);
            v25 = v24;
            if ( v24 )
            {
              v26 = *(_QWORD *)(v24 + 24);
              if ( v26 )
              {
                v27 = 3;
                if ( *(_DWORD *)(v25 + 76) >= 0 )
                {
                  *(_QWORD *)(v25 + 80) = *(_QWORD *)(v26 + 192);
                  *(_QWORD *)(v26 + 192) = v25;
                  v27 = -2147483645;
                }
                *(_DWORD *)(v25 + 76) |= v27;
              }
            }
            v28 = (signed __int64)&v3->Children;
            v8 = 1;
            if ( v3 != (Scaleform::Render::TreeCacheContainer *)-112i64 )
              v28 = (signed __int64)&v3->SortParentBounds.x2;
            if ( v13 != (Scaleform::Render::TreeCacheNode *)v28
              && (Scaleform::Render::TreeCacheContainer *)v13->pParent != v3 )
            {
              v13 = v3->Children.Root.pNext;
              LODWORD(v14) = -1;
            }
            goto LABEL_44;
          }
          do
          {
            v19 = v13->pNext;
            Scaleform::Render::TreeCacheNode::RemoveFromParent(v13);
            v13 = v19;
            if ( v19 == v17 )
              break;
            v20 = (signed __int64)&v3->Children;
            if ( v3 != (Scaleform::Render::TreeCacheContainer *)-112i64 )
              v20 = (signed __int64)&v3->SortParentBounds.x2;
          }
          while ( v19 != (Scaleform::Render::TreeCacheNode *)v20 );
          v8 = 1;
          LODWORD(v14) = v14 - 1;
        }
LABEL_44:
        v14 = (unsigned int)(v14 + 1);
      }
      while ( (unsigned int)v14 < v12 );
    }
    while ( 1 )
    {
      v29 = (signed __int64)(v3 == (Scaleform::Render::TreeCacheContainer *)-112i64 ? 0i64 : (Scaleform::Render::TreeCacheContainer *)&v3->SortParentBounds.x2);
      if ( v13 == (Scaleform::Render::TreeCacheNode *)v29 )
        break;
      v30 = v13->pNext;
      Scaleform::Render::TreeCacheNode::RemoveFromParent(v13);
      v13 = v30;
      v8 = 1;
    }
    if ( v8 && v3->vfptr->IsPatternChainValid((Scaleform::Render::TreeCacheNode *)&v3->vfptr) )
    {
      v31 = v3->pRoot;
      if ( (v3->UpdateFlags & 0x80000000) != 0 )
      {
        v3->UpdateFlags |= 0x1000000u;
      }
      else
      {
        v3->pNextUpdate = v31->pUpdateList;
        v31->pUpdateList = (Scaleform::Render::TreeCacheNode *)&v3->vfptr;
        v3->UpdateFlags |= 0x81000000;
      }
    }
  }
}

// File Line: 1183
// RVA: 0x991260
void __fastcall Scaleform::Render::TreeCacheContainer::HandleRemoveNode(Scaleform::Render::TreeCacheContainer *this)
{
  Scaleform::Render::TreeCacheContainer *v1; // rdi
  Scaleform::Render::TreeCacheNode *v2; // rcx
  Scaleform::Render::TreeCacheNode *v3; // rbx
  signed __int64 v4; // rdi
  signed __int64 v5; // rax

  v1 = this;
  this->pRoot = 0i64;
  v2 = this->pMask;
  if ( v2 )
    ((void (*)(void))v2->vfptr->HandleRemoveNode)();
  v1->CachedChildPattern.pLast = 0i64;
  v1->CachedChildPattern.pFirst = 0i64;
  v1->CachedChildPattern.Length = 2147483648;
  v3 = v1->Children.Root.pNext;
  v4 = (signed __int64)&v1->Children;
  while ( 1 )
  {
    v5 = v4 ? v4 - 8 : 0i64;
    if ( v3 == (Scaleform::Render::TreeCacheNode *)v5 )
      break;
    v3->vfptr->HandleRemoveNode(v3);
    v3 = v3->pNext;
  }
}

// File Line: 1201
// RVA: 0x9BD760
void __fastcall Scaleform::Render::TreeCacheContainer::UpdateChildSubtree(Scaleform::Render::TreeCacheContainer *this, Scaleform::Render::TreeNode::NodeData *pdata, unsigned __int16 depth)
{
  Scaleform::Render::TreeNode::NodeData *v3; // rbx
  Scaleform::Render::TreeCacheContainer *v4; // rsi
  Scaleform::Render::TreeNodeArray *v5; // rbx
  __int64 v6; // r14
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // rax
  __int64 v9; // r9
  unsigned __int64 v10; // rcx

  v3 = pdata;
  v4 = this;
  Scaleform::Render::TreeCacheNode::UpdateChildSubtree((Scaleform::Render::TreeCacheNode *)&this->vfptr, pdata, depth);
  v5 = (Scaleform::Render::TreeNodeArray *)&v3[1];
  v6 = (__int64)v4->Children.Root.pNext->pPrev;
  v7 = 0i64;
  if ( Scaleform::Render::TreeNodeArray::GetSize(v5) )
  {
    do
    {
      if ( (_QWORD)v5->pNodes[0] & 1 )
        v8 = (v5->pData[0] & 0xFFFFFFFFFFFFFFFEui64) + 16;
      else
        v8 = (unsigned __int64)v5;
      v9 = *(_QWORD *)(v8 + 8 * v7);
      v10 = *(_QWORD *)(*(_QWORD *)((v9 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                      + 8
                      * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v9
                                                                                            - (v9 & 0xFFFFFFFFFFFFF000ui64)
                                                                                            - 56)
                                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                       + ((unsigned __int64)((unsigned __int128)((signed __int64)(v9 - (v9 & 0xFFFFFFFFFFFFF000ui64) - 56)
                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                      + 40) & 0xFFFFFFFFFFFFFFFEui64;
      ++v7;
      v6 = (*(__int64 (__fastcall **)(unsigned __int64, Scaleform::Render::TreeCacheContainer *, __int64))(*(_QWORD *)v10 + 48i64))(
             v10,
             v4,
             v6);
    }
    while ( v7 < Scaleform::Render::TreeNodeArray::GetSize(v5) );
  }
}

// File Line: 1216
// RVA: 0x9EE160
void __fastcall Scaleform::Render::TreeCacheContainer::propagateMaskFlag(Scaleform::Render::TreeCacheContainer *this, unsigned int partOfMask)
{
  Scaleform::Render::TreeCacheNode *v2; // rbx
  unsigned int v3; // esi
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *v4; // rdi
  signed __int64 v5; // rax

  v2 = this->Children.Root.pNext;
  v3 = partOfMask;
  this->Flags &= 0xFFBFu;
  this->Flags |= partOfMask;
  v4 = &this->Children;
  while ( 1 )
  {
    v5 = (signed __int64)(v4 ? &v4[-1].Root.8 : 0i64);
    if ( v2 == (Scaleform::Render::TreeCacheNode *)v5 )
      break;
    if ( !((LOBYTE(v2->Flags) >> 5) & 1) )
      v2->vfptr->propagateMaskFlag(v2, v3);
    v2 = v2->pNext;
  }
}

// File Line: 1231
// RVA: 0x9EE220
void __fastcall Scaleform::Render::TreeCacheContainer::propagateScale9Flag(Scaleform::Render::TreeCacheContainer *this, unsigned int partOfScale9)
{
  Scaleform::Render::TreeCacheContainer *v2; // rdi
  unsigned int v3; // esi
  unsigned __int64 v4; // r9
  unsigned __int64 *v5; // r8
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rdx
  _QWORD *v9; // rcx
  unsigned __int16 v10; // cx
  Scaleform::Render::TreeCacheNode *v11; // rbx
  signed __int64 v12; // rdi
  signed __int64 v13; // rax

  v2 = this;
  v3 = partOfScale9;
  v4 = (_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64;
  v5 = (unsigned __int64 *)((*(_QWORD *)(*(_QWORD *)(v4 + 0x28)
                                       + 8
                                       * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pNode[-1] - v4)
                                                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                        + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pNode[-1]
                                                                                                 - v4)
                                                                                * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                       + 40) & 0xFFFFFFFFFFFFFFFEui64)
                          + 64);
  v6 = *v5;
  if ( *v5 )
  {
    if ( v6 & 1 )
    {
      if ( (v6 & 0xFFFFFFFFFFFFFFFEui64) != qword_142451A50 )
        goto LABEL_13;
    }
    else
    {
      v7 = 0i64;
      v4 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                  + 8
                                  * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pNode[-1] - v4)
                                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                   + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pNode[-1]
                                                                                            - v4)
                                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                  + 40) & 0xFFFFFFFFFFFFFFFEui64)
                     + 72)
         + 4i64;
      v8 = v6 >> 1;
      if ( !v8 )
        goto LABEL_13;
      v5 = (unsigned __int64 *)qword_142451A50;
      v9 = (_QWORD *)v4;
      while ( *v9 != qword_142451A50 )
      {
        ++v7;
        v9 += 2;
        if ( v7 >= v8 )
          goto LABEL_13;
      }
      v5 = (unsigned __int64 *)(v4 + 16 * v7);
    }
    if ( v5 )
      v3 |= 0x80u;
  }
LABEL_13:
  v10 = v2->Flags;
  if ( (v2->Flags & 0x80) != v3 )
  {
    v11 = v2->Children.Root.pNext;
    v12 = (signed __int64)&v2->Children;
    *(_WORD *)(v12 - 38) = v3 | v10 & 0xFF7F;
    while ( 1 )
    {
      v13 = v12 ? v12 - 8 : 0i64;
      if ( v11 == (Scaleform::Render::TreeCacheNode *)v13 )
        break;
      ((void (__fastcall *)(Scaleform::Render::TreeCacheNode *, _QWORD, unsigned __int64 *, unsigned __int64))v11->vfptr->propagateScale9Flag)(
        v11,
        v3,
        v5,
        v4);
      v11 = v11->pNext;
    }
  }
}

// File Line: 1249
// RVA: 0x9EDEF0
void __fastcall Scaleform::Render::TreeCacheContainer::propagateEdgeAA(Scaleform::Render::TreeCacheContainer *this, Scaleform::Render::EdgeAAMode parentEdgeAA)
{
  Scaleform::Render::TreeCacheContainer *v2; // rsi
  signed __int64 v3; // r8
  unsigned int v4; // edi
  unsigned __int16 v5; // cx
  Scaleform::Render::TreeCacheNode *v6; // rbx
  signed __int64 v7; // rsi
  signed __int64 v8; // rax

  v2 = this;
  if ( parentEdgeAA == 12 )
  {
    v4 = 12;
  }
  else
  {
    v3 = (signed __int64)&this->pNode[-1] - ((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64);
    v4 = *(_WORD *)((*(_QWORD *)(*(_QWORD *)(((_QWORD)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                               + 8
                               * (((unsigned __int64)((unsigned __int128)(v3 * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                + (unsigned int)((signed __int64)((unsigned __int128)(v3
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                  + 10) & 0xC;
    if ( !v4 )
      v4 = parentEdgeAA;
  }
  v5 = this->Flags;
  if ( (v2->Flags & 0xC) != v4 )
  {
    v6 = v2->Children.Root.pNext;
    v7 = (signed __int64)&v2->Children;
    *(_WORD *)(v7 - 38) = v4 | v5 & 0xFFF3;
    while ( 1 )
    {
      v8 = v7 ? v7 - 8 : 0i64;
      if ( v6 == (Scaleform::Render::TreeCacheNode *)v8 )
        break;
      v6->vfptr->propagateEdgeAA(v6, (Scaleform::Render::EdgeAAMode)v4);
      v6 = v6->pNext;
    }
  }
}

// File Line: 1264
// RVA: 0x9EDD90
void __fastcall Scaleform::Render::TreeCacheContainer::propagate3DFlag(Scaleform::Render::TreeCacheContainer *this, unsigned int parent3D)
{
  Scaleform::Render::TreeCacheNode *v2; // rbx
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *v3; // rdi
  unsigned int v4; // esi
  signed __int64 v5; // rax

  if ( parent3D != 512 || !(this->Flags & 0x200) )
  {
    v2 = this->Children.Root.pNext;
    v3 = &this->Children;
    v4 = this->Flags & 0x200 | parent3D;
    while ( 1 )
    {
      v5 = (signed __int64)(v3 ? &v3[-1].Root.8 : 0i64);
      if ( v2 == (Scaleform::Render::TreeCacheNode *)v5 )
        break;
      v2->vfptr->propagate3DFlag(v2, v4);
      v2 = v2->pNext;
    }
  }
}

// File Line: 1329
// RVA: 0x997280
char __fastcall Scaleform::Render::FixedSizeArrayRect2F::Intersects(Scaleform::Render::FixedSizeArrayRect2F *this, Scaleform::Render::Rect<float> *bounds)
{
  Scaleform::Render::FixedSizeArrayRect2F *v2; // r9
  unsigned int v3; // eax
  __m128 v4; // xmm2
  __m128 v5; // xmm5
  __m128 v6; // xmm3
  Scaleform::Render::Rect<float> v7; // xmm4
  __m128 v8; // xmm6
  __m128 v9; // xmm4
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // r8
  bool v12; // r10
  __m128 *v13; // rdx
  __m128 v14; // xmm1

  v2 = this;
  if ( bounds->x2 > bounds->x1 && bounds->y2 > bounds->y1 )
  {
    v3 = _S7_17;
    if ( _S7_17 & 1 )
    {
      v4 = c0000;
    }
    else
    {
      v3 = _S7_17 | 1;
      _S7_17 |= 1u;
      v4 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>::`2::v;
      c0000 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>::`2::v;
    }
    if ( v3 & 2 )
    {
      v5 = c1100;
    }
    else
    {
      v3 |= 2u;
      _S7_17 = v3;
      v5 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,0>::`2::v;
      c1100 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,0>::`2::v;
    }
    if ( v3 & 4 )
    {
      v6 = c0011;
    }
    else
    {
      _S7_17 = v3 | 4;
      v6 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>::`2::v;
      c0011 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>::`2::v;
    }
    v7 = *bounds;
    v8 = _mm_shuffle_ps((__m128)v7, (__m128)v7, 68);
    v9 = _mm_shuffle_ps((__m128)v7, (__m128)v7, 238);
    v10 = 0i64;
    v11 = v2->Size;
    v12 = v2->HalfRect;
    if ( v12 )
      --v11;
    if ( v11 )
    {
      v13 = &v2->pData->r0;
      do
      {
        v14 = _mm_or_ps(_mm_cmpleps(v13[1], v8), _mm_cmpleps(v9, *v13));
        if ( (_mm_movemask_ps(_mm_cmpeqps(_mm_and_ps(v5, v14), v4)) & 0xF) == 15
          || (_mm_movemask_ps(_mm_cmpeqps(_mm_and_ps(v6, v14), v4)) & 0xF) == 15 )
        {
          return 1;
        }
        ++v10;
        v13 += 2;
      }
      while ( v10 < v11 );
    }
    if ( v12
      && (_mm_movemask_ps(
            _mm_cmpeqps(
              _mm_and_ps(_mm_or_ps(_mm_cmpleps(v2->pData[v10].r1, v8), _mm_cmpleps(v9, v2->pData[v10].r0)), v5),
              v4)) & 0xF) == 15 )
    {
      return 1;
    }
  }
  return 0;
}

// File Line: 1387
// RVA: 0x95AF90
void __fastcall Scaleform::Render::TreeCacheContainer::BuildChildPattern(Scaleform::Render::TreeCacheContainer *this, Scaleform::Render::BundleEntryRange *pattern, unsigned int flags)
{
  unsigned int v3; // er12
  Scaleform::Render::BundleEntryRange *v4; // rbx
  Scaleform::Render::TreeCacheContainer *v5; // r14
  char v6; // r15
  Scaleform::Render::TreeNode *v7; // rcx
  unsigned __int64 *v8; // r8
  unsigned __int64 v9; // rdx
  signed __int64 v10; // r9
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rdx
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  bool v15; // zf
  signed int v16; // eax
  Scaleform::Render::TreeCacheNode *v17; // rsi
  Scaleform::Render::BundleEntry *v18; // rdi
  float v19; // xmm13_4
  float v20; // xmm11_4
  float v21; // xmm12_4
  float v22; // xmm10_4
  signed __int64 v23; // rax
  float v24; // xmm9_4
  float v25; // xmm7_4
  float v26; // xmm8_4
  float v27; // xmm6_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm3_4
  char v31; // al
  __int64 v32; // rcx
  signed __int64 v33; // rcx
  unsigned __int64 v34; // rax
  __m128 *v35; // rax
  Scaleform::Render::Rect<float> v36; // xmm1
  __m128 *v37; // rdx
  float v38; // xmm3_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  __m128 v42; // xmm5
  __m128 v43; // xmm4
  __m128 v44; // xmm2
  __m128 v45; // xmm4
  __m128 v46; // xmm0
  __m128 v47; // xmm2
  __m128 v48; // xmm3
  __m128 v49; // xmm1
  __m128 v50; // xmm4
  __m128 v51; // xmm3
  __m128 v52; // xmm4
  float v53; // xmm2_4
  Scaleform::Render::Rect<float> v54; // [rsp+20h] [rbp-A8h]
  __m128 v55; // [rsp+30h] [rbp-98h]
  Scaleform::Render::Rect<float> bounds; // [rsp+40h] [rbp-88h]
  Scaleform::Render::BundleEntryRange other; // [rsp+50h] [rbp-78h]
  Scaleform::Render::BundleEntryRangeMatcher v58; // [rsp+70h] [rbp-58h]
  char v59; // [rsp+EFh] [rbp+27h]
  __int64 v60; // [rsp+4B8h] [rbp+3F0h]
  __int64 v61; // [rsp+4C0h] [rbp+3F8h]
  unsigned __int64 v62; // [rsp+4C8h] [rbp+400h]
  char v63; // [rsp+4D0h] [rbp+408h]
  unsigned int mergeDepth; // [rsp+598h] [rbp+4D0h]
  unsigned __int64 v65; // [rsp+5A0h] [rbp+4D8h]
  char v66; // [rsp+5A8h] [rbp+4E0h]

  v58.pLastEntries[2] = (Scaleform::Render::BundleEntry *)-2i64;
  v3 = flags;
  v4 = pattern;
  v5 = this;
  v60 = 0i64;
  v61 = 32i64;
  v65 = (unsigned __int64)&v59 & 0xFFFFFFFFFFFFFFF0ui64;
  v62 = (unsigned __int64)&v59 & 0xFFFFFFFFFFFFFFF0ui64;
  v63 = 0;
  pattern->pLast = 0i64;
  pattern->pFirst = 0i64;
  pattern->Length = 0;
  _mm_store_si128((__m128i *)&v58, (__m128i)0i64);
  bounds.x2 = 0.0;
  v58.pLastEntries[1] = 0i64;
  v6 = 0;
  v55 = 0i64;
  v7 = this->pNode;
  v8 = (unsigned __int64 *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                       + 8
                                       * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1] - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                        + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1]
                                                                                                 - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                                * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                       + 40) & 0xFFFFFFFFFFFFFFFEui64)
                          + 64);
  v9 = *v8;
  if ( *v8 )
  {
    if ( v9 & 1 )
    {
      if ( (v9 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A78 )
      {
LABEL_11:
        if ( v8 )
        {
          v14 = v8[1];
          if ( !(*(_BYTE *)(v14 + 32) & 4) || (v15 = *(_BYTE *)(v14 + 28) == 0, v16 = 1, v15) )
            v16 = 0;
          v3 |= v16;
        }
        goto LABEL_16;
      }
    }
    else
    {
      v10 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                   + 8
                                   * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1] - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                    + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1]
                                                                                             - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                   + 40) & 0xFFFFFFFFFFFFFFFEui64)
                      + 72)
          + 4i64;
      v11 = 0i64;
      v12 = v9 >> 1;
      if ( v12 )
      {
        v13 = (_QWORD *)(*(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                                + 8
                                                * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1] - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                 + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1] - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                   + 72)
                       + 4i64);
        while ( *v13 != qword_142451A78 )
        {
          ++v11;
          v13 += 2;
          if ( v11 >= v12 )
            goto LABEL_16;
        }
        v8 = (unsigned __int64 *)(v10 + 16 * v11);
        goto LABEL_11;
      }
    }
  }
LABEL_16:
  v66 = v3 & 1;
  v17 = v5->Children.Root.pNext;
  v18 = v58.pFirst;
  v19 = v55.m128_f32[3];
  v20 = v55.m128_f32[2];
  v21 = v55.m128_f32[1];
  v22 = v55.m128_f32[0];
  while ( 1 )
  {
    v23 = (signed __int64)&v5->SortParentBounds.x2;
    if ( v5 == (Scaleform::Render::TreeCacheContainer *)-112i64 )
      v23 = 0i64;
    if ( v17 == (Scaleform::Render::TreeCacheNode *)v23 )
      break;
    other.pFirst = 0i64;
    other.pLast = 0i64;
    other.Length = 0;
    if ( !v17->vfptr->GetPatternChain(v17, &other, v3) )
      goto LABEL_96;
    if ( (other.Length & 0x7FFFFFFF) > 8 )
    {
      if ( v18 )
      {
        if ( v4->pFirst )
          v4->pLast->pNextPattern = v18;
        else
          v4->pFirst = v18;
        v4->pLast = v58.pLast;
        v4->Length += LODWORD(bounds.x2);
      }
      if ( other.pFirst )
      {
        if ( v4->pFirst )
          v4->pLast->pNextPattern = other.pFirst;
        else
          v4->pFirst = other.pFirst;
        v4->pLast = other.pLast;
        v4->Length += other.Length;
      }
      v58.pLast = 0i64;
      v18 = 0i64;
      v58.pFirst = 0i64;
      bounds.x2 = 0.0;
      v60 = 0i64;
      v63 = 0;
      goto LABEL_96;
    }
    v54 = 0i64;
    if ( v17->pNode )
    {
      v24 = v17->SortParentBounds.x1;
      v54.x1 = v17->SortParentBounds.x1;
      v25 = v17->SortParentBounds.y1;
      v54.y1 = v17->SortParentBounds.y1;
      v26 = v17->SortParentBounds.x2;
      v54.x2 = v17->SortParentBounds.x2;
      v27 = v17->SortParentBounds.y2;
      v54.y2 = v17->SortParentBounds.y2;
    }
    else
    {
      v27 = v54.y2;
      v26 = v54.x2;
      v25 = v54.y1;
      v24 = v54.x1;
    }
    if ( !(v17->Flags & 0x410) )
      goto LABEL_71;
    if ( !v17->pMask )
      goto LABEL_61;
    bounds = 0i64;
    if ( !Scaleform::Render::TreeCacheNode::calcChildMaskBounds(
            (Scaleform::Render::TreeCacheNode *)&v5->vfptr,
            &bounds,
            v17) )
      goto LABEL_61;
    if ( v6 )
    {
      v22 = bounds.x1;
      v55.m128_i32[0] = LODWORD(bounds.x1);
      v28 = bounds.y1;
      v21 = bounds.y1;
      *(unsigned __int64 *)((char *)v55.m128_u64 + 4) = *(_QWORD *)&bounds.y1;
      v29 = bounds.x2;
      v20 = bounds.x2;
      v30 = bounds.y2;
    }
    else
    {
      v6 = 1;
      if ( v22 > bounds.x1 )
      {
        v22 = bounds.x1;
        v55.m128_i32[0] = LODWORD(bounds.x1);
      }
      v29 = bounds.x2;
      if ( v20 <= bounds.x2 )
      {
        v20 = bounds.x2;
        v55.m128_i32[2] = LODWORD(bounds.x2);
      }
      v28 = bounds.y1;
      if ( v21 > bounds.y1 )
      {
        v21 = bounds.y1;
        v55.m128_i32[1] = LODWORD(bounds.y1);
      }
      v30 = bounds.y2;
      if ( v19 > bounds.y2 )
        goto LABEL_49;
    }
    v19 = v30;
    v55.m128_f32[3] = v30;
LABEL_49:
    if ( v24 >= v26 || v25 >= v27 )
    {
      v24 = bounds.x1;
      v54.x1 = bounds.x1;
      v25 = v28;
      v54.y1 = v28;
      v26 = v29;
      v54.x2 = v29;
    }
    else
    {
      if ( v24 > bounds.x1 )
      {
        v24 = bounds.x1;
        v54.x1 = bounds.x1;
      }
      if ( v26 <= v29 )
      {
        v26 = v29;
        v54.x2 = v29;
      }
      if ( v25 > v28 )
      {
        v25 = v28;
        v54.y1 = v28;
      }
      if ( v27 > v30 )
        goto LABEL_61;
    }
    v27 = v30;
    v54.y2 = v30;
LABEL_61:
    if ( v6 )
    {
      v22 = v24;
      v55.m128_u64[0] = __PAIR__(LODWORD(v25), LODWORD(v24));
      v21 = v25;
      v20 = v26;
      v55.m128_f32[2] = v26;
LABEL_70:
      v19 = v27;
      v55.m128_f32[3] = v27;
      goto LABEL_71;
    }
    v6 = 1;
    if ( v22 > v24 )
    {
      v22 = v24;
      v55.m128_f32[0] = v24;
    }
    if ( v20 <= v26 )
    {
      v20 = v26;
      v55.m128_f32[2] = v26;
    }
    if ( v21 > v25 )
    {
      v21 = v25;
      v55.m128_f32[1] = v25;
    }
    if ( v19 <= v27 )
      goto LABEL_70;
LABEL_71:
    if ( v18 )
    {
      if ( !v66 && !((v17->Flags >> 9) & 1) )
      {
        if ( Scaleform::Render::FixedSizeArrayRect2F::Intersects(
               (Scaleform::Render::FixedSizeArrayRect2F *)&v58.pLastEntries[4],
               &v54) )
        {
          if ( (LODWORD(bounds.x2) & 0x7FFFFFFF) == 1
            && (other.Length & 0x7FFFFFFF) == 1
            && Scaleform::Render::SortKey::MatchSingleItemOverlap(&v18->Key, &other.pFirst->Key) )
          {
LABEL_80:
            mergeDepth = v5->Depth;
            Scaleform::Render::BundleEntryRangeMatcher::Match(&v58, &other, &mergeDepth);
            v31 = v63;
            v32 = v60;
            v27 = v54.y2;
            v26 = v54.x2;
            v25 = v54.y1;
            v24 = v54.x1;
            goto LABEL_88;
          }
        }
        else
        {
          if ( Scaleform::Render::BundleEntryRangeMatcher::Match(&v58, &other, 0i64) )
            goto LABEL_80;
          v18 = v58.pFirst;
        }
        v24 = v54.x1;
        v25 = v54.y1;
        v26 = v54.x2;
        v27 = v54.y2;
      }
      if ( v18 )
      {
        if ( v4->pFirst )
          v4->pLast->pNextPattern = v18;
        else
          v4->pFirst = v18;
        v4->pLast = v58.pLast;
        v4->Length += LODWORD(bounds.x2);
      }
    }
    *(_OWORD *)&v58.pFirst = *(_OWORD *)&other.pFirst;
    *(_QWORD *)&bounds.x2 = *(_QWORD *)&other.Length;
    v58.pLastEntries[1] = 0i64;
    v32 = 0i64;
    v60 = 0i64;
    v31 = 0;
    v63 = 0;
LABEL_88:
    if ( v24 >= v26 || v25 >= v27 )
      goto LABEL_92;
    if ( v31 )
    {
      v33 = 32 * v32;
      v34 = v62;
      *(__m128 *)(v33 + v62 - 32) = _mm_shuffle_ps(*(__m128 *)(v33 + v62 - 32), (__m128)v54, 68);
      *(__m128 *)(v33 + v34 - 16) = _mm_shuffle_ps(*(__m128 *)(v33 + v34 - 16), (__m128)v54, 228);
      v63 = 0;
LABEL_92:
      v18 = v58.pFirst;
      goto LABEL_96;
    }
    if ( v32 == v61 )
    {
      Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F>::grow(
        (Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F> *)&v58.pLastEntries[4],
        2 * v32);
      v32 = v60;
    }
    v35 = (__m128 *)(v62 + 32 * v32);
    v60 = v32 + 1;
    v36 = v54;
    *v35 = _mm_shuffle_ps((__m128)v54, *v35, 228);
    v35[1] = _mm_shuffle_ps((__m128)v36, v35[1], 238);
    v63 = 1;
    v18 = v58.pFirst;
LABEL_96:
    v17 = v17->pNext;
  }
  if ( v18 )
  {
    if ( v4->pFirst )
      v4->pLast->pNextPattern = v18;
    else
      v4->pFirst = v18;
    v4->pLast = v58.pLast;
    v4->Length += LODWORD(bounds.x2);
  }
  if ( v6 )
  {
    v37 = (__m128 *)(*(_QWORD *)(*(_QWORD *)(((_QWORD)v5->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                               + 8
                               * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v5->pNode[-1] - ((_QWORD)v5->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v5->pNode[-1]
                                                                                         - ((_QWORD)v5->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                               + 40) & 0xFFFFFFFFFFFFFFFEui64);
    v38 = v37[7].m128_f32[0];
    v39 = v37[7].m128_f32[2];
    if ( v38 < v39 )
    {
      v40 = v37[7].m128_f32[1];
      v41 = v37[7].m128_f32[3];
      if ( v40 < v41 )
      {
        if ( v22 > v38 )
          v55.m128_i32[0] = v37[7].m128_i32[0];
        if ( v20 <= v39 )
          v55.m128_f32[2] = v39;
        if ( v21 > v40 )
          v55.m128_f32[1] = v40;
        if ( v19 <= v41 )
          v55.m128_f32[3] = v41;
      }
    }
    v42 = _mm_shuffle_ps(v37[1], v37[2], 255);
    v43 = _mm_unpacklo_ps(v37[1], v37[2]);
    v44 = _mm_mul_ps(v43, _mm_unpacklo_ps(v55, v55));
    v45 = _mm_mul_ps(v43, _mm_unpackhi_ps(v55, v55));
    v46 = _mm_unpacklo_ps(v44, v45);
    v47 = _mm_unpackhi_ps(v44, v45);
    v48 = _mm_add_ps(v47, v46);
    v49 = _mm_add_ps(_mm_shuffle_ps(v46, v46, 177), v47);
    v50 = _mm_min_ps(v48, v49);
    v51 = _mm_max_ps(v48, v49);
    v52 = _mm_add_ps(
            _mm_shuffle_ps(
              _mm_min_ps(v50, _mm_shuffle_ps(v50, v50, 177)),
              _mm_max_ps(v51, _mm_shuffle_ps(v51, v51, 177)),
              136),
            _mm_shuffle_ps(v42, v42, 136));
    v55 = v52;
    v53 = v55.m128_f32[1];
    if ( v52.m128_f32[0] != v5->SortParentBounds.x1
      || v52.m128_f32[2] != v5->SortParentBounds.x2
      || v55.m128_f32[1] != v5->SortParentBounds.y1
      || v52.m128_f32[3] != v5->SortParentBounds.y2 )
    {
      LODWORD(v5->SortParentBounds.x1) = v52.m128_i32[0];
      v5->SortParentBounds.y1 = v53;
      v5->SortParentBounds.x2 = v52.m128_f32[2];
      v5->SortParentBounds.y2 = v52.m128_f32[3];
      v5->Flags |= 0x400u;
    }
  }
  ++BuildPatternCount;
  v60 = 0i64;
  if ( v62 != v65 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 1590
// RVA: 0x9BD4E0
void __fastcall Scaleform::Render::TreeCacheContainer::UpdateBundlePattern(Scaleform::Render::TreeCacheContainer *this, unsigned int flags)
{
  unsigned int v2; // edi
  Scaleform::Render::TreeCacheContainer *v3; // rbx
  __int64 v4; // rbp
  __int128 v5; // di
  unsigned __int16 v6; // cx
  unsigned int v7; // eax
  Scaleform::Render::TreeCacheNode *v8; // rcx
  Scaleform::Render::TreeCacheNode *v9; // rdx
  Scaleform::Render::TreeCacheRoot *v10; // rcx
  Scaleform::Render::BundleEntryRange pattern; // [rsp+20h] [rbp-38h]
  Scaleform::Render::BundleEntryRange contentChain; // [rsp+38h] [rbp-20h]

  v2 = flags;
  v3 = this;
  if ( ((unsigned __int8 (*)(void))this->vfptr->IsPatternChainValid)() )
  {
    pattern.Length = 2147483648;
    *(_OWORD *)&pattern.pFirst = 0ui64;
    Scaleform::Render::TreeCacheContainer::BuildChildPattern(v3, &pattern, v2);
    v4 = *(_QWORD *)&pattern.Length;
    v5 = *(_OWORD *)&pattern.pFirst;
    if ( v3->Effects.pEffect && pattern.pFirst )
    {
      contentChain = pattern;
      Scaleform::Render::TreeCacheNode::updateEffectChain((Scaleform::Render::TreeCacheNode *)&v3->vfptr, &contentChain);
    }
    v6 = v3->Flags;
    if ( (v6 & 3) != 1 && !(v6 & 0x40) )
      goto LABEL_20;
    v7 = v3->CachedChildPattern.Length & 0x7FFFFFFF;
    if ( v7 <= 8 || (pattern.Length & 0x7FFFFFFF) <= 8 || *(_OWORD *)&v3->CachedChildPattern.pFirst != v5 )
    {
      v10 = v3->pRoot;
      if ( !v10 )
      {
LABEL_20:
        *(_OWORD *)&v3->CachedChildPattern.pFirst = v5;
        *(_QWORD *)&v3->CachedChildPattern.Length = v4;
        return;
      }
      v9 = v3->pParent;
    }
    else
    {
      if ( v7 == (pattern.Length & 0x7FFFFFFF) )
        goto LABEL_20;
      v8 = v3->pParent;
      if ( !v8 )
        goto LABEL_20;
      if ( !((unsigned __int8 (*)(void))v8->vfptr->IsPatternChainValid)() )
        goto LABEL_20;
      v9 = v3->pParent;
      if ( v9->UpdateFlags & 0x3000000 )
        goto LABEL_20;
      v10 = v3->pRoot;
      if ( !v10 )
        goto LABEL_20;
    }
    if ( v9 )
      Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(v10, v9, 0x1000000u);
    goto LABEL_20;
  }
}

// File Line: 1650
// RVA: 0x98A570
_BOOL8 __fastcall Scaleform::Render::TreeCacheContainer::GetPatternChain(Scaleform::Render::TreeCacheContainer *this, Scaleform::Render::BundleEntryRange *range, __int64 flags)
{
  Scaleform::Render::TreeCacheContainer *v3; // rbx
  unsigned __int16 v4; // cx
  Scaleform::Render::BundleEntryRange *v5; // rdi
  _BOOL8 result; // rax
  int v7; // ebp
  Scaleform::Render::CacheEffect *v8; // rcx
  Scaleform::Render::BundleEntryRange *v9; // rsi

  v3 = this;
  v4 = this->Flags;
  v5 = range;
  if ( (v4 & 3) != 1 && !(v4 & 0x40) )
  {
    result = 0i64;
    range->pLast = 0i64;
    range->pFirst = 0i64;
    range->Length = 0;
    return result;
  }
  v7 = v3->UpdateFlags & 0x7E0000;
  if ( v3->CachedChildPattern.Length == 0x80000000 )
  {
    v9 = &v3->CachedChildPattern;
    Scaleform::Render::TreeCacheContainer::BuildChildPattern(v3, &v3->CachedChildPattern, flags);
    goto LABEL_12;
  }
  if ( v7 )
  {
    v9 = &v3->CachedChildPattern;
    Scaleform::Render::BundleEntryRange::StripChainsByDepth(&v3->CachedChildPattern, v3->Depth);
LABEL_12:
    v5->pFirst = v9->pFirst;
    v5->pLast = v9->pLast;
    *(_QWORD *)&v5->Length = *(_QWORD *)&v9->Length;
    if ( v7 )
    {
      Scaleform::Render::CacheEffectChain::UpdateEffects(
        &v3->Effects,
        (Scaleform::Render::TreeCacheNode *)&v3->vfptr,
        v7);
      v3->UpdateFlags &= 0xFF81FFFF;
    }
    if ( v9->pFirst )
      Scaleform::Render::TreeCacheNode::updateEffectChain((Scaleform::Render::TreeCacheNode *)&v3->vfptr, v5);
    return (v5->Length & 0x7FFFFFFF) != 0;
  }
  if ( v3->CachedChildPattern.pFirst )
  {
    v8 = v3->Effects.pEffect;
    if ( v8 )
    {
      ((void (__fastcall *)(Scaleform::Render::CacheEffect *, Scaleform::Render::BundleEntryRange *, __int64))v8->vfptr->GetRange)(
        v8,
        range,
        flags);
      Scaleform::Render::BundleEntryRange::StripChainsByDepth(v5, v3->Depth);
    }
    else
    {
      range->pFirst = v3->CachedChildPattern.pFirst;
      range->pLast = v3->CachedChildPattern.pLast;
      *(_QWORD *)&range->Length = *(_QWORD *)&v3->CachedChildPattern.Length;
      Scaleform::Render::BundleEntryRange::StripChainsByDepth(range, v3->Depth);
    }
  }
  return (v5->Length & 0x7FFFFFFF) != 0;
}

// File Line: 1692
// RVA: 0x997C30
bool __fastcall Scaleform::Render::TreeCacheContainer::IsPatternChainValid(Scaleform::Render::TreeCacheContainer *this)
{
  return this->CachedChildPattern.Length != 2147483648;
}

// File Line: 1697
// RVA: 0x9E3300
void __fastcall Scaleform::Render::TreeCacheContainer::forceUpdateImages(Scaleform::Render::TreeCacheContainer *this)
{
  Scaleform::Render::TreeCacheNode *v1; // rbx
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *v2; // rdi
  signed __int64 v3; // rax

  v1 = this->Children.Root.pNext;
  v2 = &this->Children;
  while ( 1 )
  {
    v3 = (signed __int64)(v2 ? &v2[-1].Root.8 : 0i64);
    if ( v1 == (Scaleform::Render::TreeCacheNode *)v3 )
      break;
    v1->vfptr->forceUpdateImages(v1);
    v1 = v1->pNext;
  }
}

// File Line: 1710
// RVA: 0x95E0E0
void __fastcall Scaleform::Render::TreeCacheRoot::ChainUpdatesByDepth(Scaleform::Render::TreeCacheRoot *this)
{
  Scaleform::Render::TreeCacheNode *v1; // rbx
  Scaleform::Render::TreeCacheRoot *v2; // r14
  Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *v3; // rdi
  signed __int64 v4; // rsi
  Scaleform::Render::TreeCacheNode *v5; // rbp
  signed __int64 v6; // rdx
  unsigned int v7; // esi

  v1 = this->pUpdateList;
  v2 = this;
  this->pUpdateList = 0i64;
  if ( v1 )
  {
    v3 = &this->DepthUpdates;
    do
    {
      v4 = v1->Depth;
      v5 = v1->pNextUpdate;
      if ( (unsigned int)v4 < v3->DepthAvailable
        || Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(v3, v4 + 1) )
      {
        v6 = v4;
        v7 = v4 + 1;
        v1->pNextUpdate = v3->pDepth[v6];
        v3->pDepth[v6] = v1;
        if ( v3->DepthUsed < v7 )
          v3->DepthUsed = v7;
      }
      v1 = v5;
    }
    while ( v5 );
    v2->DepthUpdatesChained = 1;
  }
  else
  {
    this->DepthUpdatesChained = 1;
  }
}

// File Line: 1738
// RVA: 0x954B60
void __fastcall Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(Scaleform::Render::TreeCacheRoot *this, Scaleform::Render::TreeCacheNode *pnode, unsigned int flags)
{
  unsigned int v3; // edi
  Scaleform::Render::TreeCacheNode *v4; // rbx

  v3 = flags;
  v4 = pnode;
  if ( (pnode->UpdateFlags & 0x80000000) != 0 )
  {
    pnode->UpdateFlags |= flags;
  }
  else if ( this->DepthUpdatesChained )
  {
    Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::Link(
      &this->DepthUpdates,
      pnode->Depth,
      &pnode->pNextUpdate,
      pnode);
    v4->UpdateFlags |= v3 | 0x80000000;
  }
  else
  {
    pnode->pNextUpdate = this->pUpdateList;
    this->pUpdateList = pnode;
    pnode->UpdateFlags |= flags | 0x80000000;
  }
}

// File Line: 1758
// RVA: 0x990550
void __fastcall Scaleform::Render::TreeCacheRoot::HandleChanges(Scaleform::Render::TreeCacheRoot *this, unsigned int changeBits)
{
  unsigned int v2; // ebx
  Scaleform::Render::TreeCacheRoot *v3; // rdi
  Scaleform::Render::TreeNode *v4; // r9

  v2 = changeBits;
  v3 = this;
  if ( _bittest((const signed int *)&changeBits, 0xCu) )
  {
    v4 = this->pNode;
    if ( *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                   + 8
                   * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1]
                                                                             - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64))
                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                    + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1]
                                                                                         - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                   + 40) & 0xFFFFFFFFFFFFFFFEui64 )
      this->ViewValid = Scaleform::Render::Viewport::GetCullRectF(
                          (Scaleform::Render::Viewport *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64)
                                                                                 + 0x28)
                                                                     + 8
                                                                     * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1] - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                                      + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1] - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                                     + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                                        + 160),
                          &this->ViewCullRect,
                          0);
  }
  Scaleform::Render::TreeCacheContainer::HandleChanges(
    (Scaleform::Render::TreeCacheContainer *)&v3->vfptr,
    v2 & 0xFFFFEFFF);
}

// File Line: 1799
// RVA: 0x9C0700
void __fastcall Scaleform::Render::TreeCacheRoot::UpdateTreeData(Scaleform::Render::TreeCacheRoot *this)
{
  Scaleform::Render::TreeCacheRoot *v1; // r13
  unsigned int v2; // edx
  __int64 v3; // rcx
  signed int v4; // edi
  signed __int64 v5; // r9
  __int64 v6; // r15
  int v7; // ebx
  __int64 v8; // rax
  __int64 v9; // rdx
  __int16 v10; // ax
  __int64 v11; // r14
  unsigned __int64 v12; // r8
  signed __int64 v13; // rdx
  unsigned __int64 v14; // rsi
  signed __int64 v15; // rdi
  unsigned __int64 v16; // r8
  unsigned __int64 v17; // r8
  unsigned __int64 v18; // rcx
  __int64 v19; // rdi
  unsigned int v20; // ebx
  __int64 v21; // rcx
  __int64 v22; // rcx
  signed __int64 v23; // rax
  unsigned __int64 v24; // r8
  unsigned __int64 v25; // rcx
  unsigned __int64 v26; // r8
  _QWORD *v27; // rdx
  unsigned int v28; // ecx
  unsigned __int64 v29; // rsi
  int v30; // er12
  char v31; // r14
  char v32; // r10
  __int128 *v33; // rax
  __int128 *v34; // rcx
  float v35; // xmm3_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  unsigned __int16 v38; // r11
  unsigned __int64 v39; // r8
  unsigned __int64 v40; // rdx
  unsigned __int64 v41; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // r9
  unsigned __int64 v44; // rcx
  unsigned __int64 v45; // r9
  _QWORD *v46; // r8
  signed int v47; // eax
  unsigned int v48; // er12
  unsigned __int16 v49; // r9
  unsigned __int64 v50; // rdx
  unsigned __int64 v51; // rdi
  unsigned __int64 v52; // rdx
  _QWORD *v53; // rcx
  unsigned __int64 v54; // rdx
  unsigned __int64 v55; // rbx
  unsigned __int64 v56; // rdx
  _QWORD *v57; // rcx
  __int64 v58; // r13
  __int16 v59; // cx
  __m128 *v60; // rsi
  __int16 v61; // ax
  __m128 *v62; // rax
  __m128 v63; // xmm13
  __m128 v64; // xmm12
  int v65; // xmm0_4
  __m128 v66; // xmm12
  __m128 v67; // xmm11
  __m128 v68; // xmm0
  char v69; // r14
  signed __int64 v70; // r15
  unsigned __int64 v71; // r8
  unsigned __int64 v72; // rcx
  unsigned __int64 v73; // r8
  _QWORD *v74; // rdx
  __int64 v75; // r15
  unsigned int v76; // er14
  __int64 v77; // rcx
  __int64 v78; // rcx
  __int64 v79; // rcx
  __int64 v80; // r14
  signed int v81; // eax
  unsigned int v82; // er8
  signed __int64 v83; // r15
  unsigned int v84; // er8
  __m128 *v85; // r14
  unsigned __int64 v86; // r8
  signed __int64 v87; // rax
  unsigned __int64 v88; // rcx
  unsigned __int64 v89; // r8
  _QWORD *v90; // rdx
  unsigned int v91; // ecx
  signed int v92; // edx
  __int64 v93; // rcx
  __int64 v94; // r15
  signed int v95; // edx
  unsigned int v96; // er8
  signed __int64 v97; // r12
  unsigned int v98; // er8
  __m128 v99; // xmm3
  unsigned __int64 v100; // rdx
  unsigned __int64 v101; // rdx
  _QWORD *v102; // rcx
  unsigned __int64 v103; // rdx
  unsigned __int64 v104; // rdx
  _QWORD *v105; // rcx
  __int64 v106; // rdi
  Scaleform::Render::TreeCacheNode *i; // rbx
  __int64 v108; // r8
  __int64 v109; // rax
  __int64 v110; // rbx
  __int64 v111; // rax
  Scaleform::Render::Bundle *v112; // rdi
  bool v113; // zf
  unsigned int v114; // [rsp+30h] [rbp-90h]
  unsigned int v115; // [rsp+34h] [rbp-8Ch]
  __int128 v116; // [rsp+40h] [rbp-80h]
  __m128 v117; // [rsp+50h] [rbp-70h]
  __m128 v118; // [rsp+60h] [rbp-60h]
  __m128 v119; // [rsp+70h] [rbp-50h]
  char v120; // [rsp+90h] [rbp-30h]
  __m128 v121; // [rsp+A0h] [rbp-20h]
  __m128 v122; // [rsp+B0h] [rbp-10h]
  __m128 v123; // [rsp+C0h] [rbp+0h]
  __m128 v124; // [rsp+D0h] [rbp+10h]
  __int64 v125; // [rsp+E0h] [rbp+20h]
  __int64 *v126; // [rsp+E8h] [rbp+28h]
  __int64 *j; // [rsp+F0h] [rbp+30h]
  __int64 v128; // [rsp+F8h] [rbp+38h]
  __int64 v129; // [rsp+100h] [rbp+40h]
  __m128 v130; // [rsp+110h] [rbp+50h]
  __m128 v131; // [rsp+120h] [rbp+60h]
  __m128 v132; // [rsp+130h] [rbp+70h]
  __m128 v133; // [rsp+140h] [rbp+80h]
  __m128 v134; // [rsp+150h] [rbp+90h]
  __m128 v135; // [rsp+160h] [rbp+A0h]
  unsigned __int64 v136; // [rsp+170h] [rbp+B0h]
  int v137; // [rsp+180h] [rbp+C0h]
  int v138; // [rsp+184h] [rbp+C4h]
  int v139; // [rsp+188h] [rbp+C8h]
  int v140; // [rsp+18Ch] [rbp+CCh]
  int v141; // [rsp+190h] [rbp+D0h]
  int v142; // [rsp+194h] [rbp+D4h]
  int v143; // [rsp+198h] [rbp+D8h]
  int v144; // [rsp+19Ch] [rbp+DCh]
  __m128 v145; // [rsp+1A0h] [rbp+E0h]
  __int64 v146; // [rsp+1B0h] [rbp+F0h]
  Scaleform::Render::Bundle *v147; // [rsp+2A0h] [rbp+1E0h]
  char v148; // [rsp+2A8h] [rbp+1E8h]
  unsigned int v149; // [rsp+2B0h] [rbp+1F0h]
  unsigned int v150; // [rsp+2B8h] [rbp+1F8h]

  v146 = -2i64;
  v1 = this;
  v114 = this->DepthUpdates.DepthUsed;
  v2 = 0;
  v150 = 0;
  v3 = 0i64;
  v125 = 0i64;
  if ( !v114 )
    goto LABEL_227;
  v4 = 24804;
  v5 = 65023i64;
  do
  {
    v6 = (__int64)v1->DepthUpdates.pDepth[v3];
    v129 = v6;
    if ( !v6 )
      goto LABEL_226;
    do
    {
      v7 = *(_DWORD *)(v6 + 76) & 3;
      if ( *(_DWORD *)(v6 + 76) & 0x10000 )
      {
        v8 = *(_QWORD *)(v6 + 48);
        if ( v8 )
          v9 = *(_WORD *)(v8 + 74) & 0x80;
        else
          v9 = 0i64;
        (*(void (__fastcall **)(__int64, __int64, signed __int64, signed __int64))(*(_QWORD *)v6 + 48i64))(
          v6,
          v9,
          128i64,
          65023i64);
        *(_DWORD *)(v6 + 76) &= 0xFFFEFFFF;
        v7 |= 1u;
        v5 = 65023i64;
      }
      if ( *(_DWORD *)(v6 + 76) & 0x2000 )
      {
        v10 = ((*(_WORD *)((*(_QWORD *)(*(_QWORD *)((*(_QWORD *)(v6 + 32) & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                      + 8
                                      * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(*(_QWORD *)(v6 + 32) - (*(_QWORD *)(v6 + 32) & 0xFFFFFFFFFFFFF000ui64) - 56)
                                                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                       + ((unsigned __int64)((unsigned __int128)((signed __int64)(*(_QWORD *)(v6 + 32)
                                                                                                - (*(_QWORD *)(v6 + 32) & 0xFFFFFFFFFFFFF000ui64)
                                                                                                - 56)
                                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                      + 40) & 0xFFFFFFFFFFFFFFFEui64)
                         + 10) >> 9) & 1) << 9;
        *(_WORD *)(v6 + 74) &= 0xFDFFu;
        *(_WORD *)(v6 + 74) |= v10;
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v6 + 64i64))(v6, 0i64);
        *(_DWORD *)(v6 + 76) &= 0xFFFFDFFF;
        v7 |= 1u;
      }
      if ( v7 )
        goto LABEL_49;
      v11 = v6;
      while ( 1 )
      {
        v12 = *(_QWORD *)(v11 + 32) & 0xFFFFFFFFFFFFF000ui64;
        v13 = (signed __int64)((unsigned __int128)((signed __int64)(*(_QWORD *)(v11 + 32) - v12 - 56)
                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 4;
        v14 = *(_QWORD *)(*(_QWORD *)(v12 + 0x28)
                        + 8
                        * ((unsigned int)v13
                         + ((unsigned __int64)((unsigned __int128)((signed __int64)(*(_QWORD *)(v11 + 32) - v12 - 56)
                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                        + 40) & 0xFFFFFFFFFFFFFFFEui64;
        if ( !((*(_WORD *)(v14 + 10) >> 10) & 1) )
          goto LABEL_33;
        v15 = v14 + 64;
        v16 = *(_QWORD *)(v14 + 64);
        if ( !v16 )
          goto LABEL_32;
        if ( !(v16 & 1) )
          break;
        v17 = v16 & 0xFFFFFFFFFFFFFFFEui64;
        if ( v17 == qword_142451A58 )
          goto LABEL_24;
LABEL_32:
        v4 = 24804;
LABEL_33:
        v23 = v14 + 64;
        v24 = *(_QWORD *)(v14 + 64);
        if ( v24 )
        {
          if ( v24 & 1 )
          {
            if ( (v24 & 0xFFFFFFFFFFFFFFFEui64) != qword_142451A48 )
              goto LABEL_46;
          }
          else
          {
            v5 = *(_QWORD *)(v14 + 72) + 4i64;
            v25 = 0i64;
            v26 = v24 >> 1;
            if ( !v26 )
              goto LABEL_46;
            v27 = (_QWORD *)(*(_QWORD *)(v14 + 72) + 4i64);
            while ( *v27 != qword_142451A48 )
            {
              ++v25;
              v27 += 2;
              if ( v25 >= v26 )
                goto LABEL_46;
            }
            v23 = v5 + 16 * v25;
          }
          if ( v23 )
          {
            v28 = *(_DWORD *)(v23 + 8);
            if ( v28 <= 0xE )
            {
              if ( _bittest(&v4, v28) )
                goto LABEL_48;
            }
          }
        }
LABEL_46:
        v11 = *(_QWORD *)(v11 + 48);
        if ( !v11 )
          goto LABEL_224;
      }
      v5 = *(_QWORD *)(v14 + 72) + 4i64;
      v18 = 0i64;
      v17 = v16 >> 1;
      if ( !v17 )
        goto LABEL_32;
      v13 = *(_QWORD *)(v14 + 72) + 4i64;
      while ( *(_QWORD *)v13 != qword_142451A58 )
      {
        ++v18;
        v13 += 16i64;
        if ( v18 >= v17 )
          goto LABEL_32;
      }
      v15 = v5 + 16 * v18;
LABEL_24:
      if ( !v15 )
        goto LABEL_32;
      v19 = *(_QWORD *)(v15 + 8);
      if ( !v19 )
        goto LABEL_32;
      if ( *(_BYTE *)(v19 + 41) )
        goto LABEL_48;
      v20 = 0;
      if ( !*(_QWORD *)(v19 + 24) )
        goto LABEL_32;
      v21 = 0i64;
      while ( 1 )
      {
        v22 = *(_QWORD *)(*(_QWORD *)(v19 + 16) + 8 * v21);
        if ( v22 )
        {
          if ( (*(unsigned __int8 (__fastcall **)(__int64, signed __int64, unsigned __int64, signed __int64))(*(_QWORD *)v22 + 16i64))(
                 v22,
                 v13,
                 v17,
                 v5) )
          {
            break;
          }
        }
        v21 = ++v20;
        if ( (unsigned __int64)v20 >= *(_QWORD *)(v19 + 24) )
          goto LABEL_32;
      }
LABEL_48:
      v7 = 512;
LABEL_49:
      v29 = *(_QWORD *)(*(_QWORD *)((*(_QWORD *)(v6 + 32) & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                      + 8
                      * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(*(_QWORD *)(v6 + 32)
                                                                                            - (*(_QWORD *)(v6 + 32) & 0xFFFFFFFFFFFFF000ui64)
                                                                                            - 56)
                                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                       + ((unsigned __int64)((unsigned __int128)((signed __int64)(*(_QWORD *)(v6 + 32)
                                                                                - (*(_QWORD *)(v6 + 32) & 0xFFFFFFFFFFFFF000ui64)
                                                                                - 56)
                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                      + 40) & 0xFFFFFFFFFFFFFFFEui64;
      v136 = v29;
      v30 = v7 | (v1->ViewValid != 0 ? 0x10 : 0);
      v31 = v7 != 0;
      v32 = (*(_WORD *)(v29 + 10) >> 9) & 1;
      if ( v32 )
      {
        v33 = (__int128 *)(v29 + 16);
        v34 = (__int128 *)&Scaleform::Render::Matrix2x4<float>::Identity;
      }
      else
      {
        v33 = (__int128 *)&Scaleform::Render::Matrix3x4<float>::Identity;
        v34 = (__int128 *)(v29 + 16);
      }
      v35 = v1->ViewCullRect.y2;
      v36 = v1->ViewCullRect.x2;
      v37 = v1->ViewCullRect.y1;
      *(float *)&v116 = v1->ViewCullRect.x1;
      *(_QWORD *)((char *)&v116 + 4) = __PAIR__(LODWORD(v36), LODWORD(v37));
      *((float *)&v116 + 3) = v35;
      v117 = (__m128)*v33;
      v118 = (__m128)v33[1];
      v119 = (__m128)v33[2];
      _mm_store_si128((__m128i *)&v116, (__m128i)0i64);
      v120 = 0;
      v121 = (__m128)*v34;
      v122 = (__m128)v34[1];
      v123 = *(__m128 *)(v29 + 80);
      v124 = *(__m128 *)(v29 + 96);
      v38 = *(_WORD *)(v29 + 10);
      if ( !((v38 >> 11) & 1) )
        goto LABEL_64;
      v39 = *(_QWORD *)(v29 + 64);
      if ( !v39 )
        goto LABEL_64;
      v40 = 0i64;
      if ( v39 & 1 )
      {
        if ( (v39 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A68 )
          v40 = v29 + 64;
        goto LABEL_65;
      }
      v41 = v39 >> 1;
      if ( !v41 )
      {
LABEL_64:
        v40 = 0i64;
        goto LABEL_65;
      }
      v42 = (_QWORD *)(*(_QWORD *)(v29 + 72) + 4i64);
      while ( *v42 != qword_142451A68 )
      {
        ++v40;
        v42 += 2;
        if ( v40 >= v41 )
          goto LABEL_64;
      }
      v40 = *(_QWORD *)(v29 + 72) + 4i64 + 16 * v40;
LABEL_65:
      if ( !((v38 >> 12) & 1) )
        goto LABEL_77;
      v43 = *(_QWORD *)(v29 + 64);
      if ( !v43 )
        goto LABEL_77;
      v44 = 0i64;
      if ( v43 & 1 )
      {
        if ( (v43 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A70 )
          v44 = v29 + 64;
        goto LABEL_78;
      }
      v45 = v43 >> 1;
      if ( !v45 )
      {
LABEL_77:
        v44 = 0i64;
        goto LABEL_78;
      }
      v46 = (_QWORD *)(*(_QWORD *)(v29 + 72) + 4i64);
      while ( *v46 != qword_142451A70 )
      {
        ++v44;
        v46 += 2;
        if ( v44 >= v45 )
          goto LABEL_77;
      }
      v44 = *(_QWORD *)(v29 + 72) + 4i64 + 16 * v44;
LABEL_78:
      if ( v40 )
      {
        *(_QWORD *)&v116 = v40;
        v120 = 1;
      }
      if ( v44 )
      {
        *((_QWORD *)&v116 + 1) = v44;
        v120 = 1;
      }
      v47 = 64;
      if ( v32 )
        v47 = 128;
      v48 = v47 | v30;
      v149 = v48;
      v49 = *(_WORD *)(v29 + 10);
      if ( !((v49 >> 11) & 1) )
        goto LABEL_96;
      v50 = *(_QWORD *)(v29 + 64);
      if ( !v50 )
        goto LABEL_96;
      v51 = 0i64;
      if ( v50 & 1 )
      {
        if ( (v50 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A68 )
          v51 = v29 + 64;
        goto LABEL_97;
      }
      v52 = v50 >> 1;
      if ( !v52 )
      {
LABEL_96:
        v51 = 0i64;
        goto LABEL_97;
      }
      v53 = (_QWORD *)(*(_QWORD *)(v29 + 72) + 4i64);
      while ( *v53 != qword_142451A68 )
      {
        ++v51;
        v53 += 2;
        if ( v51 >= v52 )
          goto LABEL_96;
      }
      v51 = *(_QWORD *)(v29 + 72) + 4i64 + 16 * v51;
      if ( !((v49 >> 12) & 1) )
        goto LABEL_109;
      v54 = *(_QWORD *)(v29 + 64);
      if ( !v54 )
        goto LABEL_109;
LABEL_97:
      v55 = 0i64;
      if ( v54 & 1 )
      {
        if ( (v54 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A70 )
          v55 = v29 + 64;
        goto LABEL_110;
      }
      v56 = v54 >> 1;
      if ( v56 )
      {
        v57 = (_QWORD *)(*(_QWORD *)(v29 + 72) + 4i64);
        while ( *v57 != qword_142451A70 )
        {
          ++v55;
          v57 += 2;
          if ( v55 >= v56 )
            goto LABEL_109;
        }
        v55 = *(_QWORD *)(v29 + 72) + 4i64 + 16 * v55;
      }
      else
      {
LABEL_109:
        v55 = 0i64;
      }
LABEL_110:
      v58 = *(_QWORD *)(v6 + 48);
      if ( !v58 )
        goto LABEL_219;
      while ( 2 )
      {
        v59 = *(_WORD *)(v58 + 74);
        if ( (v59 & 3) != 1 && !(v59 & 0x40) )
        {
          v48 &= 0xFFFFFFEF;
          v149 = v48;
        }
        v60 = (__m128 *)(*(_QWORD *)(*(_QWORD *)((*(_QWORD *)(v58 + 32) & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                   + 8
                                   * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(*(_QWORD *)(v58 + 32) - (*(_QWORD *)(v58 + 32) & 0xFFFFFFFFFFFFF000ui64) - 56)
                                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                    + ((unsigned __int64)((unsigned __int128)((signed __int64)(*(_QWORD *)(v58 + 32)
                                                                                             - (*(_QWORD *)(v58 + 32) & 0xFFFFFFFFFFFFF000ui64)
                                                                                             - 56)
                                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                   + 40) & 0xFFFFFFFFFFFFFFFEui64);
        v61 = WORD1(v60->m128_u64[1]) >> 9;
        if ( (v48 & 0x80u) == 0 )
        {
          if ( v61 & 1 )
          {
            v117 = v121;
            v118 = v122;
            v119.m128_i32[0] = _xmm.m128_i32[0];
            v119.m128_i32[1] = (unsigned __int128)_mm_shuffle_ps(_xmm, _xmm, 85);
            v119.m128_i32[2] = (unsigned __int128)_mm_shuffle_ps(_xmm, _xmm, 170);
            v65 = (unsigned __int128)_mm_shuffle_ps(_xmm, _xmm, 255);
            v119.m128_i32[3] = v65;
            v133 = v121;
            v134 = v122;
            v135.m128_u64[0] = __PAIR__(v119.m128_u32[1], _xmm.m128_u32[0]);
            v135.m128_u64[1] = __PAIR__(v65, v119.m128_u32[2]);
            v66 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v60[2], v60[2], 0), v121),
                        _mm_mul_ps(_mm_shuffle_ps(v60[2], v60[2], 85), v122)),
                      _mm_mul_ps(_mm_shuffle_ps(v60[2], v60[2], 170), v135)),
                    _mm_and_ps(
                      (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v,
                      v60[2]));
            v67 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v60[3], v60[3], 0), v121),
                        _mm_mul_ps(_mm_shuffle_ps(v60[3], v60[3], 85), v122)),
                      _mm_mul_ps(_mm_shuffle_ps(v60[3], v60[3], 170), v135)),
                    _mm_and_ps(
                      (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v,
                      v60[3]));
            v117 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v60[1], v60[1], 0), v121),
                         _mm_mul_ps(_mm_shuffle_ps(v60[1], v60[1], 85), v122)),
                       _mm_mul_ps(_mm_shuffle_ps(v60[1], v60[1], 170), v135)),
                     _mm_and_ps(
                       v60[1],
                       (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
            v118 = v66;
            v119 = v67;
            v68 = (__m128)_xmm;
            v122 = _xmm;
            v48 = v48 & 0xFFFFFFBF | 0x80;
            v149 = v48;
          }
          else
          {
            v68 = _mm_and_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(v122, _mm_shuffle_ps(v60[1], v60[1], 85)),
                        _mm_mul_ps(v121, _mm_shuffle_ps(v60[1], v60[1], 0))),
                      _mm_and_ps(
                        v60[1],
                        (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
                    (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
            v122 = _mm_and_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(v122, _mm_shuffle_ps(v60[2], v60[2], 85)),
                         _mm_mul_ps(v121, _mm_shuffle_ps(v60[2], v60[2], 0))),
                       _mm_and_ps(
                         v60[2],
                         (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
                     (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
          }
          v121 = v68;
        }
        else
        {
          if ( v61 & 1 )
          {
            v62 = v60 + 1;
          }
          else
          {
            v137 = v60[1].m128_i32[0];
            v138 = v60[1].m128_i32[1];
            v139 = v60[1].m128_i32[2];
            v140 = v60[1].m128_i32[3];
            v141 = v60[2].m128_i32[0];
            v142 = v60[2].m128_i32[1];
            v143 = v60[2].m128_i32[2];
            v144 = v60[2].m128_i32[3];
            v145 = _xmm;
            v62 = (__m128 *)&v137;
          }
          v130 = v117;
          v131 = v118;
          v132 = v119;
          v63 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v62[1], v62[1], 0), v117),
                      _mm_mul_ps(_mm_shuffle_ps(v62[1], v62[1], 85), v118)),
                    _mm_mul_ps(_mm_shuffle_ps(v62[1], v62[1], 170), v119)),
                  _mm_and_ps((__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v, v62[1]));
          v64 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v62[2], v62[2], 0), v117),
                      _mm_mul_ps(_mm_shuffle_ps(v62[2], v62[2], 85), v118)),
                    _mm_mul_ps(_mm_shuffle_ps(v62[2], v62[2], 170), v119)),
                  _mm_and_ps((__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v, v62[2]));
          v117 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(*v62, *v62, 0), v117),
                       _mm_mul_ps(_mm_shuffle_ps(*v62, *v62, 85), v118)),
                     _mm_mul_ps(_mm_shuffle_ps(*v62, *v62, 170), v119)),
                   _mm_and_ps((__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v, *v62));
          v118 = v63;
          v119 = v64;
        }
        v69 = ((*(_BYTE *)(v58 + 76) & 3) != 0) | v31;
        v148 = v69;
        if ( !((WORD1(v60->m128_u64[1]) >> 10) & 1) )
          goto LABEL_158;
        v70 = (signed __int64)&v60[4];
        v71 = v60[4].m128_u64[0];
        if ( !v71 )
          goto LABEL_158;
        if ( v71 & 1 )
        {
          if ( (v71 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A58 )
            goto LABEL_134;
          goto LABEL_158;
        }
        v72 = 0i64;
        v73 = v71 >> 1;
        if ( v73 )
        {
          v74 = (_QWORD *)(v60[4].m128_u64[1] + 4);
          while ( *v74 != qword_142451A58 )
          {
            ++v72;
            v74 += 2;
            if ( v72 >= v73 )
              goto LABEL_158;
          }
          v70 = 16 * v72 + v60[4].m128_u64[1] + 4;
LABEL_134:
          if ( v70 )
          {
            v75 = *(_QWORD *)(v70 + 8);
            if ( v75 )
            {
              if ( !*(_BYTE *)(v75 + 41) )
              {
                v76 = 0;
                if ( !*(_QWORD *)(v75 + 24) )
                  goto LABEL_158;
                v77 = 0i64;
                while ( 1 )
                {
                  v78 = *(_QWORD *)(*(_QWORD *)(v75 + 16) + 8 * v77);
                  if ( v78 )
                  {
                    if ( (*(unsigned __int8 (**)(void))(*(_QWORD *)v78 + 16i64))() )
                      break;
                  }
                  v77 = ++v76;
                  if ( (unsigned __int64)v76 >= *(_QWORD *)(v75 + 24) )
                    goto LABEL_158;
                }
                v69 = v148;
              }
              if ( v69 )
              {
                *(_DWORD *)(v58 + 76) |= 0x1200000u;
                v79 = *(_QWORD *)(v58 + 24);
                if ( v79 )
                {
                  v80 = *(_QWORD *)(v58 + 48);
                  if ( v80 )
                  {
                    v81 = 0x1000000;
                    if ( *(_DWORD *)(v80 + 76) >= 0 )
                    {
                      if ( *(_BYTE *)(v79 + 202) )
                      {
                        v82 = *(unsigned __int16 *)(v80 + 72);
                        v149 = v82;
                        v83 = v79 + 208;
                        if ( v82 < *(_DWORD *)(v79 + 220) )
                        {
LABEL_152:
                          *(_QWORD *)(v80 + 80) = *(_QWORD *)(*(_QWORD *)v83 + 8i64 * v82);
                          *(_QWORD *)(*(_QWORD *)v83 + 8i64 * v82) = v80;
                          v84 = v82 + 1;
                          if ( *(_DWORD *)(v83 + 8) < v84 )
                            *(_DWORD *)(v83 + 8) = v84;
                        }
                        else if ( Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(
                                    (Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *)(v79 + 208),
                                    v82 + 1) )
                        {
                          v82 = v149;
                          goto LABEL_152;
                        }
                      }
                      else
                      {
                        *(_QWORD *)(v80 + 80) = *(_QWORD *)(v79 + 192);
                        *(_QWORD *)(v79 + 192) = v80;
                      }
                      v81 = -2130706432;
                    }
                    *(_DWORD *)(v80 + 76) |= v81;
                  }
                }
              }
              v48 |= 0x100u;
              v149 = v48;
              goto LABEL_158;
            }
          }
        }
LABEL_158:
        v85 = v60 + 4;
        v86 = v60[4].m128_u64[0];
        if ( !v86 )
          goto LABEL_187;
        if ( v86 & 1 )
        {
          if ( (v86 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A48 )
          {
            v87 = (signed __int64)&v60[4];
            goto LABEL_168;
          }
          goto LABEL_187;
        }
        v88 = 0i64;
        v89 = v86 >> 1;
        if ( v89 )
        {
          v90 = (_QWORD *)(v60[4].m128_u64[1] + 4);
          while ( *v90 != qword_142451A48 )
          {
            ++v88;
            v90 += 2;
            if ( v88 >= v89 )
              goto LABEL_187;
          }
          v87 = 16 * v88 + v60[4].m128_u64[1] + 4;
LABEL_168:
          v128 = v87;
          if ( v87 )
          {
            v91 = *(_DWORD *)(v87 + 8);
            if ( v91 <= 0xE )
            {
              v92 = 24804;
              if ( _bittest(&v92, v91) )
              {
                if ( v148 )
                {
                  *(_DWORD *)(v58 + 76) |= 0x1020000u;
                  v93 = *(_QWORD *)(v58 + 24);
                  if ( v93 )
                  {
                    v94 = *(_QWORD *)(v58 + 48);
                    if ( v94 )
                    {
                      v95 = 0x1000000;
                      if ( *(_DWORD *)(v94 + 76) >= 0 )
                      {
                        if ( *(_BYTE *)(v93 + 202) )
                        {
                          v96 = *(unsigned __int16 *)(v94 + 72);
                          v115 = v96;
                          v97 = v93 + 208;
                          if ( v96 < *(_DWORD *)(v93 + 220) )
                          {
LABEL_179:
                            *(_QWORD *)(v94 + 80) = *(_QWORD *)(*(_QWORD *)v97 + 8i64 * v96);
                            *(_QWORD *)(*(_QWORD *)v97 + 8i64 * v96) = v94;
                            v98 = v96 + 1;
                            if ( *(_DWORD *)(v97 + 8) < v98 )
                              *(_DWORD *)(v97 + 8) = v98;
                          }
                          else if ( Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(
                                      (Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *)(v93 + 208),
                                      v96 + 1) )
                          {
                            v96 = v115;
                            goto LABEL_179;
                          }
                          v48 = v149;
                        }
                        else
                        {
                          *(_QWORD *)(v94 + 80) = *(_QWORD *)(v93 + 192);
                          *(_QWORD *)(v93 + 192) = v94;
                        }
                        v95 = -2130706432;
                        v87 = v128;
                      }
                      *(_DWORD *)(v94 + 76) |= v95;
                    }
                  }
                }
                v48 |= 0x100u;
                v149 = v48;
                if ( *(_DWORD *)(v87 + 8) == 2 )
                {
                  v48 |= 0x400u;
                  v149 = v48;
                }
                goto LABEL_187;
              }
            }
          }
        }
LABEL_187:
        if ( !_bittest((const signed int *)&v48, 8u) )
        {
          v99 = _mm_add_ps(v124, _mm_mul_ps(v60[6], v123));
          v123 = _mm_mul_ps(v123, v60[5]);
          v124 = v99;
        }
        if ( !v51 && (WORD1(v60->m128_u64[1]) >> 11) & 1 )
        {
          v100 = v85->m128_u64[0];
          if ( !v85->m128_u64[0] )
            goto LABEL_202;
          if ( v100 & 1 )
          {
            if ( (v100 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A68 )
              v51 = (unsigned __int64)&v60[4];
            goto LABEL_203;
          }
          v101 = v100 >> 1;
          if ( !v101 )
          {
LABEL_202:
            v51 = 0i64;
            goto LABEL_203;
          }
          v102 = (_QWORD *)(v60[4].m128_u64[1] + 4);
          while ( *v102 != qword_142451A68 )
          {
            ++v51;
            v102 += 2;
            if ( v51 >= v101 )
              goto LABEL_202;
          }
          v51 = v60[4].m128_u64[1] + 4 + 16 * v51;
        }
LABEL_203:
        if ( !v55 && (WORD1(v60->m128_u64[1]) >> 12) & 1 )
        {
          v103 = v85->m128_u64[0];
          if ( !v85->m128_u64[0] )
            goto LABEL_216;
          if ( v103 & 1 )
          {
            if ( (v103 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A70 )
              v55 = (unsigned __int64)&v60[4];
            goto LABEL_217;
          }
          v104 = v103 >> 1;
          if ( !v104 )
          {
LABEL_216:
            v55 = 0i64;
            goto LABEL_217;
          }
          v105 = (_QWORD *)(v60[4].m128_u64[1] + 4);
          while ( *v105 != qword_142451A70 )
          {
            ++v55;
            v105 += 2;
            if ( v55 >= v104 )
              goto LABEL_216;
          }
          v55 = v60[4].m128_u64[1] + 4 + 16 * v55;
        }
LABEL_217:
        v58 = *(_QWORD *)(v58 + 48);
        v31 = v148;
        if ( v58 )
          continue;
        break;
      }
      v6 = v129;
      v29 = v136;
LABEL_219:
      if ( v51 )
      {
        *(_QWORD *)&v116 = v51;
        v120 = 1;
      }
      if ( v55 )
      {
        *((_QWORD *)&v116 + 1) = v55;
        v120 = 1;
      }
      (*(void (__fastcall **)(__int64, unsigned __int64, __int128 *, _QWORD))(*(_QWORD *)v6 + 32i64))(
        v6,
        v29,
        &v116,
        v48);
      *(_DWORD *)(v6 + 76) &= 0xFFFFFFFC;
      v1 = (Scaleform::Render::TreeCacheRoot *)v147;
LABEL_224:
      v6 = *(_QWORD *)(v6 + 80);
      v129 = v6;
      v4 = 24804;
      v5 = 65023i64;
    }
    while ( v6 );
    v3 = v125;
    v2 = v150;
LABEL_226:
    v150 = ++v2;
    v125 = ++v3;
  }
  while ( v2 < v114 );
LABEL_227:
  LODWORD(v106) = v1->DepthUpdates.DepthUsed;
  while ( (_DWORD)v106 )
  {
    v106 = (unsigned int)(v106 - 1);
    for ( i = v1->DepthUpdates.pDepth[v106]; i; i = i->pNextUpdate )
    {
      if ( i->UpdateFlags & 0x3000000 )
      {
        i->vfptr->UpdateBundlePattern(i, 0);
        i->UpdateFlags &= 0xFCFFFFFF;
      }
      i->UpdateFlags &= 0x7FFFFFFFu;
    }
  }
  v108 = 0i64;
  if ( v1->DepthUpdates.DepthUsed )
  {
    do
    {
      v1->DepthUpdates.pDepth[v108] = v1->DepthUpdates.NullValue;
      v108 = (unsigned int)(v108 + 1);
    }
    while ( (unsigned int)v108 < v1->DepthUpdates.DepthUsed );
  }
  v1->DepthUpdates.DepthUsed = 0;
  v1->DepthUpdatesChained = 0;
  v109 = (__int64)v1->CachedChildPattern.pLast;
  v110 = (__int64)v1->CachedChildPattern.pFirst;
  v126 = (__int64 *)v110;
  for ( j = (__int64 *)v109; v110; v126 = (__int64 *)v110 )
  {
    (*(void (__fastcall **)(_QWORD, _QWORD, __int64, Scaleform::Render::TreeCacheRoot *, Scaleform::Render::Renderer2DImpl *, __int64 **))(**(_QWORD **)(v110 + 24) + 32i64))(
      *(_QWORD *)(v110 + 24),
      *(_QWORD *)(v110 + 32),
      v110,
      v1,
      v1->pRenderer2D,
      &v126);
    if ( *(_QWORD *)(v110 + 40) )
    {
      v111 = *(_QWORD *)(v110 + 40);
      if ( v111 )
        ++*(_DWORD *)(v111 + 8);
      v147 = *(Scaleform::Render::Bundle **)(v110 + 40);
      v112 = v147;
      if ( v147->NeedUpdate )
        Scaleform::Render::Bundle::UpdateChain(v147, (Scaleform::Render::BundleEntry *)v110);
      v113 = v112->RefCount-- == 1;
      if ( v113 )
        v112->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v112->vfptr, 1u);
    }
    if ( v126 == j )
      break;
    v110 = *v126;
  }
  ++BundlePatternFrameId;
}

// File Line: 2021
// RVA: 0x96F000
void __fastcall Scaleform::Render::TreeCacheRoot::Draw(Scaleform::Render::TreeCacheRoot *this)
{
  Scaleform::Render::TreeCacheRoot *v1; // rbx
  unsigned __int16 v2; // cx
  Scaleform::Render::HAL *v3; // rcx
  bool v4; // al
  Scaleform::Render::Color *v5; // rdx
  Scaleform::Render::Viewport *v6; // rdi
  Scaleform::Render::HAL *v7; // rcx
  Scaleform::Render::HAL *v8; // rcx
  Scaleform::Render::BundleEntry *v9; // [rsp+20h] [rbp-18h]
  Scaleform::Render::BundleEntry *v10; // [rsp+28h] [rbp-10h]
  Scaleform::Render::Color backgroundColor; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = this->Flags;
  if ( (v2 & 3) == 1 || v2 & 0x40 )
  {
    v3 = v1->pRenderer2D->pHal.pObject;
    v4 = v1->EnableBlendTarget;
    v3->HALState &= 0xFFFFF7FF;
    if ( v4 )
      v3->HALState |= 0x800u;
    v5 = (Scaleform::Render::Color *)(*(_QWORD *)(*(_QWORD *)(((_QWORD)v1->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                                + 8
                                                * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1->pNode[-1] - ((_QWORD)v1->pNode & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                 + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1->pNode[-1] - ((_QWORD)v1->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                + 40) & 0xFFFFFFFFFFFFFFFEui64);
    v6 = (Scaleform::Render::Viewport *)&v5[40];
    if ( v5[40].Raw && v5[41].Raw )
    {
      v7 = v1->pRenderer2D->pHal.pObject;
      backgroundColor = (Scaleform::Render::Color)v5[51].Raw;
      Scaleform::Render::HAL::BeginDisplay(v7, (__int64)&backgroundColor, v6);
    }
    v8 = v1->pRenderer2D->pHal.pObject;
    v9 = v1->CachedChildPattern.pFirst;
    v10 = v1->CachedChildPattern.pLast;
    v8->vfptr[32].__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, (unsigned int)&v9);
    if ( v6->BufferWidth )
    {
      if ( v6->BufferHeight )
        Scaleform::Render::HAL::EndDisplay(v1->pRenderer2D->pHal.pObject);
    }
  }
}

// File Line: 2052
// RVA: 0x9468F0
void __fastcall Scaleform::Render::TreeCacheMeshBase::TreeCacheMeshBase(Scaleform::Render::TreeCacheMeshBase *this, Scaleform::Render::TreeNode *pnode, Scaleform::Render::SortKey *key, Scaleform::Render::Renderer2DImpl *prenderer2D, unsigned int flags)
{
  Scaleform::Render::TreeCacheMeshBase *v5; // rdi
  Scaleform::Render::SortKeyInterface *v6; // rcx
  Scaleform::Render::BundleEntry *v7; // [rsp+48h] [rbp+10h]

  v5 = this;
  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheNode::`vftable;
  this->pRoot = 0i64;
  this->pNode = pnode;
  this->pRenderer2D = prenderer2D;
  this->pParent = 0i64;
  this->Effects.pEffect = 0i64;
  this->pMask = 0i64;
  this->Depth = 0;
  this->Flags = flags;
  this->UpdateFlags = 8257536;
  this->pNextUpdate = 0i64;
  *(_QWORD *)&this->SortParentBounds.x1 = 0i64;
  *(_QWORD *)&this->SortParentBounds.x2 = 0i64;
  this->pNext = 0i64;
  this->pPrev = 0i64;
  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheMeshBase::`vftable;
  v7 = &this->SorterShapeNode;
  *(_OWORD *)&v7->pNextPattern = 0ui64;
  *(_DWORD *)&v7->ChainHeight = 0;
  v6 = key->pImpl;
  v7->Key = *key;
  ((void (__cdecl *)(Scaleform::Render::SortKeyInterface *))v6->vfptr->AddRef)(v6);
  v7->pBundle.pObject = 0i64;
  v7->pSourceNode = (Scaleform::Render::TreeCacheNode *)&v5->vfptr;
  v7->Removed = 0;
  v5->M.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
}

// File Line: 2056
// RVA: 0x94D660
void __fastcall Scaleform::Render::TreeCacheMeshBase::~TreeCacheMeshBase(Scaleform::Render::TreeCacheMeshBase *this)
{
  Scaleform::Render::TreeCacheMeshBase *v1; // rbx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v2; // rdi
  Scaleform::Render::MatrixPoolImpl::EntryHandle v3; // rdi
  bool v4; // zf
  __int64 v5; // rcx

  v1 = this;
  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheMeshBase::`vftable;
  v2 = this->M.pHandle;
  if ( v2 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v3.pHeader = v2->pHeader;
    v4 = v3.pHeader->RefCount-- == 1;
    if ( v4 )
    {
      v5 = v3.pHeader->DataPageOffset;
      *(_WORD *)((char *)&v3.pHeader[1].RefCount + v5 + 2) += 16 * (unsigned __int8)v3.pHeader->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v3.pHeader[1].pHandle + v5))[5].pHeader += (unsigned __int8)v3.pHeader->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v3.pHeader->pHandle);
      v3.pHeader->pHandle = 0i64;
    }
  }
  Scaleform::Render::BundleEntry::~BundleEntry(&v1->SorterShapeNode);
  Scaleform::Render::TreeCacheNode::~TreeCacheNode((Scaleform::Render::TreeCacheNode *)&v1->vfptr);
}

// File Line: 2061
// RVA: 0x962450
void __fastcall Scaleform::Render::TreeCacheMeshBase::ComputeFinalMatrix(Scaleform::Render::TreeCacheMeshBase *this, Scaleform::Render::TransformArgs *t, Scaleform::Render::TransformFlags flags)
{
  char v3; // bp
  Scaleform::Render::TransformArgs *v4; // rdi
  Scaleform::Render::TreeCacheMeshBase *v5; // r15
  Scaleform::Render::MatrixPoolImpl::HMatrix *v6; // rsi
  unsigned int formatBits; // er14
  Scaleform::Render::Cxform *v8; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v9; // rax
  Scaleform::Render::MatrixPoolImpl::HMatrix *v10; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v11; // rbx
  bool v12; // zf
  __int64 v13; // rcx
  Scaleform::Render::Matrix3x4<float> m; // [rsp+40h] [rbp-58h]
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+A0h] [rbp+8h]

  v3 = flags;
  v4 = t;
  v5 = this;
  v6 = &this->M;
  if ( this->M.pHandle == &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    formatBits = 0;
    v8 = &t->Cx;
    if ( Scaleform::Render::Cxform::Identity.M[0][0] != t->Cx.M[0][0]
      || Scaleform::Render::Cxform::Identity.M[0][1] != t->Cx.M[0][1]
      || Scaleform::Render::Cxform::Identity.M[0][2] != t->Cx.M[0][2]
      || Scaleform::Render::Cxform::Identity.M[0][3] != t->Cx.M[0][3]
      || Scaleform::Render::Cxform::Identity.M[1][0] != t->Cx.M[1][0]
      || Scaleform::Render::Cxform::Identity.M[1][1] != t->Cx.M[1][1]
      || Scaleform::Render::Cxform::Identity.M[1][2] != t->Cx.M[1][2]
      || Scaleform::Render::Cxform::Identity.M[1][3] != t->Cx.M[1][3] )
    {
      formatBits = 1;
    }
    if ( (flags & 0x80u) == 0 )
    {
      v10 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
              &this->pRenderer2D->MPool,
              &result,
              &t->Mat,
              &t->Cx,
              formatBits);
      Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(v6, v10);
    }
    else
    {
      Scaleform::Render::TransformArgs::GetMatrix3D(t, flags, &m);
      v9 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
             &v5->pRenderer2D->MPool,
             &result,
             &m,
             v8,
             formatBits | 0x10);
      Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(v6, v9);
    }
    if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
      v11 = result.pHandle->pHeader;
      v12 = result.pHandle->pHeader->RefCount == 1;
      --v11->RefCount;
      if ( v12 )
      {
        v13 = v11->DataPageOffset;
        *(_WORD *)((char *)&v11[1].RefCount + v13 + 2) += 16 * (unsigned __int8)v11->UnitSize;
        (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v11[1].pHandle + v13))[5].pHeader += (unsigned __int8)v11->UnitSize;
        Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v11->pHandle);
        v11->pHandle = 0i64;
      }
    }
  }
  else
  {
    if ( (flags & 0x80u) == 0 )
    {
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&this->M, &t->Mat);
    }
    else
    {
      Scaleform::Render::TransformArgs::GetMatrix3D(t, flags, &m);
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix3D(v6, &m);
    }
    if ( v3 & 2 )
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(v6, &v4->Cx);
  }
}

// File Line: 2102
// RVA: 0x98A6C0
char __fastcall Scaleform::Render::TreeCacheMeshBase::GetPatternChain(Scaleform::Render::TreeCacheMeshBase *this, Scaleform::Render::BundleEntryRange *range, unsigned int __formal)
{
  Scaleform::Render::TreeCacheMeshBase *v3; // rbx
  unsigned __int16 v4; // cx
  Scaleform::Render::BundleEntryRange *v5; // rdi
  char result; // al
  Scaleform::Render::CacheEffect *v7; // rcx
  Scaleform::Render::Bundle *v8; // rax
  __int64 v9; // r8

  v3 = this;
  v4 = this->Flags;
  v5 = range;
  if ( (v4 & 3) == 1 || v4 & 0x40 )
  {
    range->Length = 1;
    range->pLast = &v3->SorterShapeNode;
    range->pFirst = &v3->SorterShapeNode;
    v7 = v3->Effects.pEffect;
    v3->SorterShapeNode.Removed = 0;
    if ( v7 || v3->UpdateFlags & 0x7E0000 )
    {
      v9 = v3->UpdateFlags & 0x7E0000;
      if ( v3->UpdateFlags & 0x7E0000 )
      {
        Scaleform::Render::CacheEffectChain::UpdateEffects(
          &v3->Effects,
          (Scaleform::Render::TreeCacheNode *)&v3->vfptr,
          v9);
        Scaleform::Render::TreeCacheNode::updateEffectChain((Scaleform::Render::TreeCacheNode *)&v3->vfptr, v5);
        v3->UpdateFlags &= 0xFF81FFFF;
      }
      else if ( v7 )
      {
        ((void (__fastcall *)(Scaleform::Render::CacheEffect *, Scaleform::Render::BundleEntryRange *, __int64))v7->vfptr->GetRange)(
          v7,
          range,
          v9);
      }
      Scaleform::Render::BundleEntryRange::StripChainsByDepth(v5, v3->Depth);
      result = 1;
    }
    else
    {
      v8 = v3->SorterShapeNode.pBundle.pObject;
      if ( v8 )
        v8->NeedUpdate = 1;
      result = 1;
      v3->SorterShapeNode.pChain = 0i64;
      v3->SorterShapeNode.ChainHeight = 0;
    }
  }
  else
  {
    result = 0;
    range->pLast = 0i64;
    range->pFirst = 0i64;
    range->Length = 0;
  }
  return result;
}

// File Line: 2145
// RVA: 0x9BD620
void __fastcall Scaleform::Render::TreeCacheMeshBase::UpdateBundlePattern(Scaleform::Render::TreeCacheMeshBase *this, unsigned int __formal)
{
  Scaleform::Render::BundleEntryRange contentChain; // [rsp+20h] [rbp-28h]

  if ( this->pMask )
  {
    if ( this->Effects.pEffect )
    {
      contentChain.Length = 1;
      contentChain.pLast = &this->SorterShapeNode;
      contentChain.pFirst = &this->SorterShapeNode;
      Scaleform::Render::TreeCacheNode::updateEffectChain(
        (Scaleform::Render::TreeCacheNode *)&this->vfptr,
        &contentChain);
    }
  }
}

