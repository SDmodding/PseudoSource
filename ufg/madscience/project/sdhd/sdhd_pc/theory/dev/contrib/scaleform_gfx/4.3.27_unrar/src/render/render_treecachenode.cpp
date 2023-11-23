// File Line: 53
// RVA: 0x94D6F0
void __fastcall Scaleform::Render::TreeCacheNode::~TreeCacheNode(Scaleform::Render::TreeCacheNode *this)
{
  Scaleform::Render::TreeCacheNode *pParent; // rcx
  Scaleform::Render::TreeCacheNode *pMask; // rcx
  Scaleform::Render::CacheEffect *pEffect; // rbx
  Scaleform::Render::CacheEffect *v5; // rcx

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
    pParent = this->pParent;
    if ( pParent )
    {
      pParent->pMask = 0i64;
      pParent->Flags &= ~0x10u;
    }
  }
  pMask = this->pMask;
  if ( pMask )
    Scaleform::Render::TreeCacheNode::RemoveFromParent(pMask);
  pEffect = this->Effects.pEffect;
  while ( pEffect )
  {
    v5 = pEffect;
    pEffect = pEffect->pNext;
    v5->vfptr->__vecDelDtor(v5, 1u);
  }
}

// File Line: 93
// RVA: 0x9BE630
void __fastcall Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::TreeCacheNode *pparent,
        Scaleform::Render::TreeCacheNode *pinsert,
        Scaleform::Render::TreeNode::NodeData *nodeData,
        unsigned __int16 depth)
{
  Scaleform::Render::TreeCacheNode *v5; // rdi
  Scaleform::Render::TreeCacheRoot *pRoot; // rcx
  int v11; // eax
  Scaleform::Render::TreeCacheNode *pMask; // rcx
  Scaleform::Render::TreeCacheNodeVtbl *vfptr; // rax
  int v14; // edi

  v5 = this->pParent;
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
        pRoot = v5->pRoot;
        v11 = 0x1000000;
        if ( (v5->UpdateFlags & 0x80000000) == 0 )
        {
          v5->pNextUpdate = pRoot->pUpdateList;
          pRoot->pUpdateList = v5;
          v11 = -2130706432;
        }
        v5->UpdateFlags |= v11;
      }
    }
  }
  if ( pinsert )
  {
    this->pPrev = pinsert->pNext->pPrev;
    this->pNext = pinsert->pNext;
    pinsert->pNext->pPrev = this;
    pinsert->pNext = this;
  }
  if ( nodeData )
  {
    if ( (nodeData->Flags & 0x20) != 0 )
    {
      pMask = pparent->pMask;
      if ( pMask && pMask != this )
        Scaleform::Render::TreeCacheNode::RemoveFromParent(pMask, pparent);
      pparent->Flags |= 0x10u;
      pparent->pMask = this;
      vfptr = this->vfptr;
      this->Flags |= 0x20u;
      vfptr->propagateMaskFlag(this, 64u);
    }
    v14 = pparent->Flags & 0x80;
    if ( Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::Scale9State>(nodeData) )
      v14 |= 0x80u;
    this->vfptr->propagateScale9Flag(this, v14);
    this->vfptr->propagateEdgeAA(this, (Scaleform::Render::EdgeAAMode)(pparent->Flags & 0xC));
  }
  this->pParent = pparent;
LABEL_24:
  this->Depth = depth;
  this->pRoot = pparent->pRoot;
  this->vfptr->UpdateChildSubtree(this, nodeData, depth + 1);
}

// File Line: 154
// RVA: 0x9A9C20
void __fastcall Scaleform::Render::TreeCacheNode::RemoveFromParent(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::TreeCacheNode *pNext)
{
  Scaleform::Render::TreeCacheNode *pPrev; // rcx
  __int64 v4; // r8
  Scaleform::Render::TreeCacheNode *pParent; // rax
  bool v6; // zf

  pPrev = this->pPrev;
  v4 = 0i64;
  if ( pPrev )
  {
    pPrev->pNext = this->pNext;
    pNext = this->pNext;
    pNext->pPrev = this->pPrev;
    this->pPrev = (Scaleform::Render::TreeCacheNode *)-1i64;
    this->pNext = (Scaleform::Render::TreeCacheNode *)-1i64;
  }
  else
  {
    pParent = this->pParent;
    if ( pParent )
    {
      pParent->pMask = 0i64;
      pParent->Flags &= ~0x10u;
      this->Flags &= ~0x20u;
    }
  }
  v6 = (this->Flags & 0x40) == 0;
  this->pPrev = 0i64;
  this->pNext = 0i64;
  this->pParent = 0i64;
  this->Depth = 0;
  if ( !v6 )
    ((void (__fastcall *)(Scaleform::Render::TreeCacheNode *, _QWORD, _QWORD))this->vfptr->propagateMaskFlag)(
      this,
      0i64,
      0i64);
  if ( SLOBYTE(this->Flags) < 0 )
    ((void (__fastcall *)(Scaleform::Render::TreeCacheNode *, _QWORD, __int64))this->vfptr->propagateScale9Flag)(
      this,
      0i64,
      v4);
  ((void (__fastcall *)(Scaleform::Render::TreeCacheNode *, Scaleform::Render::TreeCacheNode *, __int64))this->vfptr->HandleRemoveNode)(
    this,
    pNext,
    v4);
}

// File Line: 184
// RVA: 0x991310
void __fastcall Scaleform::Render::TreeCacheNode::HandleRemoveNode(Scaleform::Render::TreeCacheNode *this)
{
  Scaleform::Render::TreeCacheNode *pMask; // rcx

  this->pRoot = 0i64;
  pMask = this->pMask;
  if ( pMask )
    pMask->vfptr->HandleRemoveNode(pMask);
}

// File Line: 192
// RVA: 0x9BD840
void __fastcall Scaleform::Render::TreeCacheNode::UpdateChildSubtree(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::TreeNode::NodeData *data,
        unsigned __int16 depth)
{
  Scaleform::Render::StateData::Interface *pInterface; // r10
  unsigned __int16 v5; // r9
  Scaleform::Render::StateBag *p_States; // rax
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // r10
  _QWORD *v9; // rcx
  Scaleform::Render::TreeCacheNode *pParent; // rax

  pInterface = data->States.pInterface;
  v5 = this->Flags ^ ((unsigned __int8)this->Flags ^ (unsigned __int8)(2 * this->Flags)) & 0x40;
  p_States = &data->States;
  if ( pInterface )
  {
    if ( ((unsigned __int8)pInterface & 1) != 0 )
    {
      if ( ((unsigned __int64)pInterface & 0xFFFFFFFFFFFFFFFEui64) != qword_142451A50 )
        goto LABEL_13;
    }
    else
    {
      v7 = 0i64;
      v8 = (unsigned __int64)pInterface >> 1;
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
      p_States = (Scaleform::Render::StateBag *)(data->States.DataValue + 4 + 16 * v7);
    }
    if ( p_States )
      v5 |= 0x80u;
  }
LABEL_13:
  pParent = this->pParent;
  if ( pParent )
    v5 |= pParent->Flags & 0xC0;
  if ( (data->Flags & 0x200) != 0 )
    v5 |= 0x200u;
  this->Flags = v5;
  Scaleform::Render::TreeCacheNode::updateMaskCache(this, data, depth, 1);
}

// File Line: 210
// RVA: 0x9F9E70
void __fastcall Scaleform::Render::TreeCacheNode::updateMaskCache(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::TreeNode::NodeData *data,
        unsigned __int16 depth,
        bool updateSubtree)
{
  Scaleform::Render::TreeNode *pData; // r9
  unsigned __int64 v7; // rcx
  Scaleform::Render::TreeCacheNode *v8; // rax
  unsigned __int64 v9; // rcx
  Scaleform::Render::TreeCacheNode *pMask; // rcx
  Scaleform::Render::TreeCacheRoot *pRoot; // rcx
  int v12; // eax

  TCN_This = this;
  TCN_ThisData = data;
  if ( (data->Flags & 0x10) == 0 )
  {
    pMask = this->pMask;
    if ( !pMask )
      return;
    Scaleform::Render::TreeCacheNode::RemoveFromParent(pMask, (Scaleform::Render::TreeCacheNode *)data);
    goto $update_on_mask_change;
  }
  pData = (Scaleform::Render::TreeNode *)Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::MaskNodeState>(data)->pData;
  TCN_ChildNode = pData;
  if ( updateSubtree )
  {
    v7 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                   + 8i64 * (unsigned int)((int)((_DWORD)pData - ((unsigned int)pData & 0xFFFFF000) - 56) / 56)
                   + 40) & 0xFFFFFFFFFFFFFFFEui64;
    (*(void (__fastcall **)(unsigned __int64, Scaleform::Render::TreeCacheNode *, _QWORD))(*(_QWORD *)v7 + 48i64))(
      v7,
      this,
      0i64);
    return;
  }
  v8 = this->pMask;
  if ( pData->pRenderer != v8 || !v8 )
  {
    v9 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                   + 8i64 * (unsigned int)((int)((_DWORD)pData - ((unsigned int)pData & 0xFFFFF000) - 56) / 56)
                   + 40) & 0xFFFFFFFFFFFFFFFEui64;
    (*(void (__fastcall **)(unsigned __int64, Scaleform::Render::TreeCacheNode *, _QWORD))(*(_QWORD *)v9 + 48i64))(
      v9,
      this,
      0i64);
$update_on_mask_change:
    if ( this->pRoot && this->vfptr->IsPatternChainValid(this) )
    {
      pRoot = this->pRoot;
      v12 = 0x1000000;
      if ( (this->UpdateFlags & 0x80000000) == 0 )
      {
        this->pNextUpdate = pRoot->pUpdateList;
        pRoot->pUpdateList = this;
        v12 = -2130706432;
      }
      this->UpdateFlags |= v12;
    }
  }
}

// File Line: 255
// RVA: 0x9F9FE0
void __fastcall Scaleform::Render::TreeCacheNode::updateMaskTransform(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::TransformArgs *t,
        Scaleform::Render::TransformFlags flags)
{
  Scaleform::Render::TreeCacheNode *pMask; // r9
  Scaleform::Render::TreeNode::NodeData *v7; // rdi
  Scaleform::Render::Matrix3x4<float> *p_M34; // rdx

  pMask = this->pMask;
  if ( pMask )
  {
    v7 = (Scaleform::Render::TreeNode::NodeData *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pMask->pNode & 0xFFFFFFFFFFFFF000ui64)
                                                                         + 0x28)
                                                             + 8i64
                                                             * (unsigned int)((int)((int)&pMask->pNode[-1]
                                                                                  - ((__int64)pMask->pNode & 0xFFFFF000))
                                                                            / 56)
                                                             + 40) & 0xFFFFFFFFFFFFFFFEui64);
    p_M34 = &v7->M34;
    if ( (flags & 0x80u) != 0 )
      Scaleform::Render::TransformArgs::PrependMatrix3D(t, p_M34);
    else
      Scaleform::Render::Matrix2x4<float>::Prepend(&t->Mat, (Scaleform::Render::Matrix2x4<float> *)p_M34);
    this->pMask->vfptr->UpdateTransform(this->pMask, v7, t, flags);
  }
}

// File Line: 268
// RVA: 0x9F9970
void __fastcall Scaleform::Render::TreeCacheNode::updateEffectChain(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::BundleEntryRange *contentChain)
{
  Scaleform::Render::TreeCacheNode *pMask; // rcx
  Scaleform::Render::CacheEffectChain *p_Effects; // rcx
  Scaleform::Render::CacheEffect *pEffect; // rbx
  Scaleform::Render::CacheEffect *pNext; // rdx
  Scaleform::Render::BundleEntryRange *p_maskChain; // r8
  Scaleform::Render::CacheEffectChain *v9; // rcx
  Scaleform::Render::CacheEffect *v10; // rdx
  Scaleform::Render::BundleEntryRange maskChain; // [rsp+20h] [rbp-28h] BYREF

  pMask = this->pMask;
  if ( pMask )
  {
    memset(&maskChain, 0, 20);
    pMask->vfptr->GetPatternChain(pMask, &maskChain, 0);
    p_Effects = &this->Effects;
    pEffect = this->Effects.pEffect;
    if ( !pEffect )
      return;
    pNext = pEffect->pNext;
    if ( pNext )
      Scaleform::Render::CacheEffectChain::updateBundleChain(p_Effects, pNext, contentChain, &maskChain);
    p_maskChain = &maskChain;
  }
  else
  {
    v9 = &this->Effects;
    pEffect = this->Effects.pEffect;
    if ( !pEffect )
      return;
    v10 = pEffect->pNext;
    if ( v10 )
      Scaleform::Render::CacheEffectChain::updateBundleChain(v9, v10, contentChain, 0i64);
    p_maskChain = 0i64;
  }
  pEffect->vfptr->ChainNext(pEffect, contentChain, p_maskChain);
}

// File Line: 283
// RVA: 0x9EE1D0
void __fastcall Scaleform::Render::TreeCacheNode::propagateMaskFlag(
        Scaleform::Render::TreeCacheNode *this,
        __int16 partOfMask)
{
  this->Flags &= ~0x40u;
  this->Flags |= partOfMask;
}

// File Line: 287
// RVA: 0x9EE330
void __fastcall Scaleform::Render::TreeCacheNode::propagateScale9Flag(
        Scaleform::Render::TreeCacheNode *this,
        __int16 partOfScale9)
{
  unsigned __int64 *v4; // r8
  unsigned __int64 v5; // rdx
  __int64 v6; // rax
  __int64 v7; // r9
  unsigned __int64 v8; // rdx
  _QWORD *i; // rcx

  v4 = (unsigned __int64 *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                       + 8i64
                                       * (unsigned int)((int)(LODWORD(this->pNode)
                                                            - ((__int64)this->pNode & 0xFFFFF000)
                                                            - 56)
                                                      / 56)
                                       + 40) & 0xFFFFFFFFFFFFFFFEui64)
                          + 64);
  v5 = *v4;
  if ( !*v4 )
    goto LABEL_13;
  if ( (v5 & 1) != 0 )
  {
    if ( (v5 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A50 )
    {
LABEL_11:
      if ( v4 )
        partOfScale9 |= 0x80u;
    }
  }
  else
  {
    v6 = 0i64;
    v7 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                + 8i64
                                * (unsigned int)((int)(LODWORD(this->pNode) - ((__int64)this->pNode & 0xFFFFF000) - 56)
                                               / 56)
                                + 40) & 0xFFFFFFFFFFFFFFFEui64)
                   + 72)
       + 4i64;
    v8 = v5 >> 1;
    if ( v8 )
    {
      for ( i = (_QWORD *)(*(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64)
                                                              + 0x28)
                                                  + 8i64
                                                  * (unsigned int)((int)(LODWORD(this->pNode)
                                                                       - ((__int64)this->pNode & 0xFFFFF000)
                                                                       - 56)
                                                                 / 56)
                                                  + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                     + 72)
                         + 4i64); *i != qword_142451A50; i += 2 )
      {
        if ( ++v6 >= v8 )
        {
          this->Flags &= ~0x80u;
          this->Flags |= partOfScale9;
          return;
        }
      }
      v4 = (unsigned __int64 *)(v7 + 16 * v6);
      goto LABEL_11;
    }
  }
LABEL_13:
  this->Flags &= ~0x80u;
  this->Flags |= partOfScale9;
}

// File Line: 293
// RVA: 0x9EDFC0
void __fastcall Scaleform::Render::TreeCacheNode::propagateEdgeAA(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::EdgeAAMode parentEdgeAA)
{
  __int16 v2; // r11
  unsigned __int64 v3; // rdx
  __int16 v4; // ax

  v2 = parentEdgeAA;
  if ( parentEdgeAA == EdgeAA_Disable )
  {
    this->Flags &= 0xFFF3u;
    this->Flags |= 0xCu;
  }
  else
  {
    v3 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                   + 8i64
                   * (unsigned int)((__int64)((__int64)&this->pNode[-1]
                                            - ((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64))
                                  / 56)
                   + 40) & 0xFFFFFFFFFFFFFFFEui64;
    v4 = *(_WORD *)(v3 + 10) & 0xC;
    if ( (*(_WORD *)(v3 + 10) & 0xC) == 0 )
      v4 = v2;
    this->Flags &= 0xFFF3u;
    this->Flags |= v4;
  }
}

// File Line: 326
// RVA: 0x9F90C0
__int64 __fastcall Scaleform::Render::TreeCacheNode::updateCulling(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::TreeNode::NodeData *data,
        Scaleform::Render::TransformArgs *t,
        Scaleform::Render::Rect<float> *cullRect,
        Scaleform::Render::TransformFlags flags)
{
  Scaleform::Render::TransformFlags v5; // esi
  int v6; // r12d
  unsigned int v7; // eax
  char v8; // r13
  Scaleform::Render::TreeNode::NodeData *v11; // rdi
  unsigned int DataValue; // ecx
  int v14; // eax
  bool v15; // cl
  Scaleform::Render::CacheEffect *pEffect; // rdi
  Scaleform::Render::Matrix4x4<float> *viewProjMatrix; // rax
  int v18; // r9d
  char is3d; // di
  Scaleform::Render::TreeCacheRoot *v20; // rcx
  Scaleform::Render::Matrix4x4<float> *ViewProj; // rax
  Scaleform::Render::TreeCacheRoot *pRoot; // rcx
  Scaleform::Render::TreeCacheNode *pParent; // rdx
  __m128 v24; // xmm0
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // xmm3
  __m128 v29; // xmm0
  __m128 v30; // xmm2
  __m128 v31; // xmm0
  __m128 v32; // xmm3
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // xmm3
  __m128 v36; // xmm0
  Scaleform::Render::Rect<float> AproxLocalBounds; // xmm3
  __m128 v38; // xmm4
  __m128 v39; // xmm1
  __m128 v40; // xmm4
  __m128 v41; // xmm2
  __m128 v42; // xmm3
  __m128 v43; // xmm0
  __m128 v44; // xmm2
  __m128 v45; // xmm0
  __m128 v46; // xmm3
  __m128 v47; // xmm0
  __m128 v48; // xmm2
  __m128 v49; // xmm3
  Scaleform::Render::Matrix4x4<float> *v50; // rax
  __m128 v51; // xmm7
  __m128 v52; // xmm6
  __m128 v53; // xmm8
  __m128 v54; // xmm3
  __m128 v55; // xmm4
  __m128 v56; // xmm5
  __m128 v57; // xmm9
  __m128 v58; // xmm2
  __m128i v59; // xmm1
  __m128i v60; // xmm0
  float v61; // xmm0_4
  float v62; // xmm1_4
  Scaleform::Render::TreeCacheRoot *v63; // r9
  unsigned __int16 v64; // ax
  Scaleform::Render::TreeCacheNode *v65; // rdx
  unsigned __int16 v66; // ax
  Scaleform::Render::TreeCacheNode *v67; // rdx
  Scaleform::Render::TreeCacheNode *pMask; // rdi
  unsigned __int64 v69; // rbx
  Scaleform::Render::Rect<float> maskBounds; // [rsp+40h] [rbp-98h] BYREF
  char m[56]; // [rsp+50h] [rbp-88h] BYREF
  Scaleform::Render::TransformArgs ta; // [rsp+88h] [rbp-50h] BYREF
  unsigned int *v74; // [rsp+1F8h] [rbp+120h]
  Scaleform::Render::TreeNode::NodeData *dataa; // [rsp+200h] [rbp+128h]
  void *retaddr; // [rsp+218h] [rbp+140h]

  v5 = (int)retaddr;
  v6 = 0;
  v7 = (unsigned int)retaddr >> 7;
  v8 = 0;
  LOBYTE(v7) = ((unsigned __int8)retaddr & 0x80) != 0;
  v11 = data;
  LODWORD(v74) = v7;
  if ( ((unsigned __int8)retaddr & 0x10) == 0 )
    goto LABEL_52;
  maskBounds = 0i64;
  v15 = 0;
  if ( Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::BlendState>(data) )
  {
    DataValue = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::BlendState>(v11)->DataValue;
    if ( DataValue <= 0xE )
    {
      v14 = 24804;
      if ( _bittest(&v14, DataValue) )
        v15 = 1;
    }
  }
  if ( this->pMask || (v11->Flags & 0x400) != 0 || v15 )
    Scaleform::Render::TransformArgs::GetMatrix3D(
      t,
      (Scaleform::Render::TransformFlags)retaddr,
      (Scaleform::Render::Matrix3x4<float> *)m);
  if ( this->pMask )
  {
    pEffect = this->Effects.pEffect;
    *(_OWORD *)&m[24] = _xmm;
    *(__m128 *)&m[40] = _xmm;
    if ( pEffect )
    {
      while ( pEffect->vfptr->GetType(pEffect) != State_MaskNode )
      {
        pEffect = pEffect->pNext;
        if ( !pEffect )
          goto LABEL_15;
      }
      ViewProj = Scaleform::Render::TransformArgs::GetViewProj(t);
      LODWORD(retaddr) = Scaleform::Render::TreeCacheNode::calcMaskBounds(
                           this,
                           &maskBounds,
                           (Scaleform::Render::Matrix2x4<float> *)&m[24],
                           (Scaleform::Render::Matrix3x4<float> *)m,
                           ViewProj);
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(
        (Scaleform::Render::MatrixPoolImpl::HMatrix *)&pEffect[9].pNext,
        (Scaleform::Render::Matrix2x4<float> *)&m[24]);
      v18 = (int)retaddr;
      if ( (_DWORD)retaddr != LODWORD(pEffect[9].vfptr) )
      {
        pRoot = this->pRoot;
        this->UpdateFlags |= 0x40000u;
        if ( pRoot )
        {
          pParent = this->pParent;
          if ( pParent )
          {
            Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(pRoot, pParent, 0x1000000u);
            v18 = (int)retaddr;
          }
        }
      }
    }
    else
    {
LABEL_15:
      viewProjMatrix = Scaleform::Render::TransformArgs::GetViewProj(t);
      v18 = Scaleform::Render::TreeCacheNode::calcMaskBounds(
              this,
              &maskBounds,
              (Scaleform::Render::Matrix2x4<float> *)&m[24],
              (Scaleform::Render::Matrix3x4<float> *)m,
              viewProjMatrix);
    }
    is3d = (char)v74;
    if ( !(_BYTE)v74 )
    {
      v20 = this->pRoot;
      if ( v20 )
      {
        if ( (*(_BYTE *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v20->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                    + 8i64
                                    * (unsigned int)((int)((int)&v20->pNode[-1] - ((__int64)v20->pNode & 0xFFFFF000))
                                                   / 56)
                                    + 40) & 0xFFFFFFFFFFFFFFFEui64)
                       + 200) & 0x30) == 0
          && v18 )
        {
          if ( v18 == 1 )
          {
            v6 = 1;
            v8 = 1;
          }
          else
          {
            v24 = *(__m128 *)&t->Mat.M[1][0];
            v25 = *(__m128 *)&t->Mat.M[0][0];
            v26 = _mm_unpacklo_ps(v25, v24);
            v27 = _mm_shuffle_ps(v25, v24, 255);
            v28 = _mm_mul_ps(_mm_unpackhi_ps((__m128)maskBounds, (__m128)maskBounds), v26);
            v29 = _mm_mul_ps(_mm_unpacklo_ps((__m128)maskBounds, (__m128)maskBounds), v26);
            v30 = _mm_unpackhi_ps(v29, v28);
            v31 = _mm_unpacklo_ps(v29, v28);
            v32 = _mm_add_ps(v30, v31);
            v33 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 177), v30);
            v34 = _mm_min_ps(v32, v33);
            v35 = _mm_max_ps(v32, v33);
            maskBounds = (Scaleform::Render::Rect<float>)_mm_add_ps(
                                                           _mm_shuffle_ps(
                                                             _mm_min_ps(v34, _mm_shuffle_ps(v34, v34, 177)),
                                                             _mm_max_ps(v35, _mm_shuffle_ps(v35, v35, 177)),
                                                             136),
                                                           _mm_shuffle_ps(v27, v27, 136));
            if ( !Scaleform::Render::Rect<float>::IntersectRect(cullRect, cullRect, &maskBounds) )
            {
              v8 = 1;
              v6 = 1;
            }
          }
        }
      }
    }
  }
  else
  {
    is3d = (char)v74;
  }
  Scaleform::Render::TreeCacheNode::updateFilterCache(
    this,
    dataa,
    t,
    v5,
    cullRect,
    (Scaleform::Render::Matrix3x4<float> *)m,
    is3d);
  Scaleform::Render::TreeCacheNode::updateBlendCache(
    this,
    dataa,
    t,
    v5,
    cullRect,
    (Scaleform::Render::Matrix3x4<float> *)m);
  if ( (v5 & 0x20) != 0 )
  {
    if ( v8 )
    {
LABEL_35:
      v11 = dataa;
      goto LABEL_52;
    }
    if ( COERCE_FLOAT(LODWORD(t->Cx.M[0][3]) & _xmm) < 0.001
      && COERCE_FLOAT(LODWORD(t->Cx.M[1][3]) & _xmm) < 0.0039215689
      && (this->Flags & 0x40) == 0 )
    {
      v8 = 1;
      v6 = 2;
      goto LABEL_35;
    }
  }
  else if ( v8 )
  {
    goto LABEL_35;
  }
  if ( !this->pRoot )
    goto LABEL_35;
  if ( is3d )
  {
    Scaleform::Render::TransformArgs::GetMatrix3D(t, v5, (Scaleform::Render::Matrix3x4<float> *)m);
    v74 = (unsigned int *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pRoot->pNode & 0xFFFFFFFFFFFFF000ui64)
                                                  + 0x28)
                                      + 8i64
                                      * (unsigned int)((int)(LODWORD(this->pRoot->pNode)
                                                           - ((__int64)this->pRoot->pNode & 0xFFFFF000)
                                                           - 56)
                                                     / 56)
                                      + 40) & 0xFFFFFFFFFFFFFFFEui64)
                         + 160);
    v50 = Scaleform::Render::TransformArgs::GetViewProj(t);
    v51 = *(__m128 *)m;
    v52 = *(__m128 *)&m[16];
    v53 = *(__m128 *)&m[32];
    v54 = *(__m128 *)&v50->M[0][0];
    v55 = *(__m128 *)&v50->M[1][0];
    v56 = *(__m128 *)&v50->M[2][0];
    v57 = *(__m128 *)&v50->M[3][0];
    maskBounds = 0i64;
    *(_QWORD *)m = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v54, v54, 85), *(__m128 *)&m[16]),
                         _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), *(__m128 *)m)),
                       _mm_mul_ps(_mm_shuffle_ps(v54, v54, 170), *(__m128 *)&m[32])),
                     _mm_and_ps(v54, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)).m128_u64[0];
    v58 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v56, v56, 85), *(__m128 *)&m[16]),
            _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v51));
    *(_QWORD *)&m[24] = *(unsigned __int128 *)&_mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(_mm_shuffle_ps(v55, v55, 85), *(__m128 *)&m[16]),
                                                     _mm_mul_ps(_mm_shuffle_ps(v55, v55, 0), v51)),
                                                   _mm_mul_ps(_mm_shuffle_ps(v55, v55, 170), *(__m128 *)&m[32])),
                                                 _mm_and_ps(
                                                   v55,
                                                   (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)) >> 64;
    *(__m128 *)&m[32] = _mm_add_ps(
                          _mm_add_ps(v58, _mm_mul_ps(_mm_shuffle_ps(v56, v56, 170), *(__m128 *)&m[32])),
                          _mm_and_ps(
                            v56,
                            (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
    v11 = dataa;
    *(__m128 *)&m[8] = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v57, v57, 85), v52),
                             _mm_mul_ps(_mm_shuffle_ps(v57, v57, 0), v51)),
                           _mm_mul_ps(_mm_shuffle_ps(v57, v57, 170), v53)),
                         _mm_and_ps(
                           v57,
                           (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
    Scaleform::Render::Matrix4x4<float>::EncloseTransformHomogeneous(
      (Scaleform::Render::Matrix4x4<float> *)m,
      (__m128 *)&maskBounds,
      (__m128 *)&dataa->AproxLocalBounds);
    if ( (((v74[10] & 0x30) - 16) & 0xFFFFFFDF) != 0 )
    {
      v59 = _mm_cvtsi32_si128(v74[4]);
      v60 = _mm_cvtsi32_si128(v74[5]);
    }
    else
    {
      v59 = _mm_cvtsi32_si128(v74[5]);
      v60 = _mm_cvtsi32_si128(v74[4]);
    }
    v61 = _mm_cvtepi32_ps(v60).m128_f32[0];
    LODWORD(v62) = _mm_cvtepi32_ps(v59).m128_u32[0];
    if ( (float)((float)((float)(1.0 - maskBounds.y2) * v61) * 0.5) > cullRect->y2
      || (float)((float)((float)(1.0 - maskBounds.y1) * v61) * 0.5) < cullRect->y1
      || (float)((float)((float)(maskBounds.x2 + 1.0) * v62) * 0.5) < cullRect->x1
      || (float)((float)((float)(maskBounds.x1 + 1.0) * v62) * 0.5) > cullRect->x2 )
    {
      v6 = 5;
      v8 = 1;
    }
  }
  else
  {
    v36 = *(__m128 *)&t->Mat.M[1][0];
    v11 = dataa;
    AproxLocalBounds = dataa->AproxLocalBounds;
    v38 = *(__m128 *)&t->Mat.M[0][0];
    v39 = _mm_unpacklo_ps(v38, v36);
    v40 = _mm_shuffle_ps(v38, v36, 255);
    v41 = _mm_unpacklo_ps((__m128)AproxLocalBounds, (__m128)AproxLocalBounds);
    v42 = _mm_mul_ps(_mm_unpackhi_ps((__m128)AproxLocalBounds, (__m128)AproxLocalBounds), v39);
    v43 = _mm_mul_ps(v41, v39);
    v44 = _mm_unpackhi_ps(v43, v42);
    v45 = _mm_unpacklo_ps(v43, v42);
    v46 = _mm_add_ps(v44, v45);
    v47 = _mm_add_ps(_mm_shuffle_ps(v45, v45, 177), v44);
    v48 = _mm_min_ps(v46, v47);
    v49 = _mm_max_ps(v46, v47);
    maskBounds = (Scaleform::Render::Rect<float>)_mm_add_ps(
                                                   _mm_shuffle_ps(
                                                     _mm_min_ps(v48, _mm_shuffle_ps(v48, v48, 177)),
                                                     _mm_max_ps(v49, _mm_shuffle_ps(v49, v49, 177)),
                                                     136),
                                                   _mm_shuffle_ps(v40, v40, 136));
    if ( _mm_shuffle_ps((__m128)maskBounds, (__m128)maskBounds, 85).m128_f32[0] > cullRect->y2
      || maskBounds.y2 < cullRect->y1
      || maskBounds.x2 < cullRect->x1
      || maskBounds.x1 > cullRect->x2 )
    {
      v8 = 1;
      v6 = 3;
    }
  }
LABEL_52:
  v63 = this->pRoot;
  if ( v63
    && (*(_BYTE *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v63->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                              + 8i64
                              * (unsigned int)((int)(LODWORD(v63->pNode) - ((__int64)v63->pNode & 0xFFFFF000) - 56) / 56)
                              + 40) & 0xFFFFFFFFFFFFFFFEui64)
                 + 200) & 0x30) != 0
    || !v8
    || v6 == 5
    || v6 == 3 && (v11->Flags & 0x4000) != 0
    || this == v63 )
  {
    v66 = this->Flags;
    if ( (v66 & 2) != 0 )
    {
      this->Flags = v66 & 0xFFFD;
      if ( v63 )
      {
        v67 = this->pParent;
        if ( v67 )
          Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(v63, v67, 0x1000000u);
      }
    }
  }
  else
  {
    v64 = this->Flags;
    if ( (v64 & 2) == 0 )
    {
      this->Flags = v64 | 2;
      if ( v63 )
      {
        v65 = this->pParent;
        if ( v65 )
          Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(v63, v65, 0x1000000u);
      }
    }
    v5 &= ~0x10u;
  }
  if ( this->pMask )
  {
    if ( (v5 & 0x80u) != 0 )
    {
      Scaleform::Render::TransformArgs::GetMatrix3D(t, v5, (Scaleform::Render::Matrix3x4<float> *)m);
      Scaleform::Render::TransformArgs::TransformArgs(&ta, t, (Scaleform::Render::Matrix3x4<float> *)m);
      ta.Mat = Scaleform::Render::Matrix2x4<float>::Identity;
      Scaleform::Render::TreeCacheNode::updateMaskTransform(this, &ta, v5);
    }
    else
    {
      Scaleform::Render::TransformArgs::TransformArgs(&ta, t, &t->Mat);
      pMask = this->pMask;
      if ( pMask )
      {
        v69 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)pMask->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                        + 8i64
                        * (unsigned int)((int)(LODWORD(pMask->pNode) - ((__int64)pMask->pNode & 0xFFFFF000) - 56) / 56)
                        + 40) & 0xFFFFFFFFFFFFFFFEui64;
        Scaleform::Render::Matrix2x4<float>::Prepend(&ta.Mat, (Scaleform::Render::Matrix2x4<float> *)(v69 + 16));
        pMask->vfptr->UpdateTransform(pMask, (Scaleform::Render::TreeNode::NodeData *)v69, &ta, v5);
        return (unsigned int)v5;
      }
    }
  }
  return (unsigned int)v5;
}a *)v69, &ta, v5);
        return (unsigned int)v5;
      }
    }
  }
  return (unsigned int)v5;
}

// File Line: 514
// RVA: 0x9D1D50
bool __fastcall Scaleform::Render::TreeCacheNode::calcChildMaskBounds(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::Rect<float> *bounds,
        Scaleform::Render::TreeCacheNode *child)
{
  Scaleform::Render::TreeCacheNode *pMask; // rbp
  unsigned __int64 v6; // rbx
  Scaleform::Render::TreeCacheNode *v7; // r9
  bool v8; // al
  Scaleform::Render::TreeNode *pNode; // rcx
  unsigned int *v10; // rdx
  __m128i v11; // xmm5
  __m128i v12; // xmm2
  bool result; // al
  float v14; // xmm1_4
  float v15; // xmm3_4
  Scaleform::Render::TreeNode *v16; // rcx
  unsigned int v17; // xmm1_4
  unsigned int v18; // xmm0_4
  Scaleform::Render::TreeCacheNode *pParent; // rax
  unsigned __int64 v20; // rdx
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm7
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm4
  __m128 v27; // xmm7
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  __m128 v31; // xmm0
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm0
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  Scaleform::Render::Matrix2x4<float> pviewMatrix; // [rsp+20h] [rbp-58h] BYREF
  Scaleform::Render::Matrix2x4<float> v39; // [rsp+40h] [rbp-38h] BYREF

  pMask = child->pMask;
  v6 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)pMask->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                 + 8i64 * (unsigned int)((int)(LODWORD(pMask->pNode) - ((__int64)pMask->pNode & 0xFFFFF000) - 56) / 56)
                 + 40) & 0xFFFFFFFFFFFFFFFEui64;
  if ( *(float *)(v6 + 136) <= *(float *)(v6 + 128) || *(float *)(v6 + 140) <= *(float *)(v6 + 132) )
    return 0;
  v7 = this;
  v8 = (*(_WORD *)(v6 + 10) & 0x200) != 0;
  if ( this )
  {
    while ( !v8 )
    {
      pNode = v7->pNode;
      v7 = v7->pParent;
      v8 = (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                  + 8i64
                                  * (unsigned int)((int)((_DWORD)pNode - ((unsigned int)pNode & 0xFFFFF000) - 56) / 56)
                                  + 40) & 0xFFFFFFFFFFFFFFFEui64)
                     + 10) & 0x200) != 0;
      if ( !v7 )
        goto LABEL_6;
    }
    goto LABEL_7;
  }
LABEL_6:
  if ( v8 )
  {
LABEL_7:
    v10 = (unsigned int *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pRoot->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                     + 8i64
                                     * (unsigned int)((int)(LODWORD(this->pRoot->pNode)
                                                          - ((__int64)this->pRoot->pNode & 0xFFFFF000)
                                                          - 56)
                                                    / 56)
                                     + 40) & 0xFFFFFFFFFFFFFFFEui64);
    if ( (((v10[50] & 0x30) - 16) & 0xFFFFFFDF) != 0 )
    {
      v11 = _mm_cvtsi32_si128(v10[44]);
      v12 = _mm_cvtsi32_si128(v10[45]);
    }
    else
    {
      v11 = _mm_cvtsi32_si128(v10[45]);
      v12 = _mm_cvtsi32_si128(v10[44]);
    }
    result = 1;
    v14 = _mm_cvtepi32_ps(v12).m128_f32[0];
    v15 = _mm_cvtepi32_ps(v11).m128_f32[0];
    bounds->y1 = (float)(v14 * 0.0) * 0.5;
    bounds->x1 = (float)(v15 * 0.0) * 0.5;
    bounds->y2 = (float)(v14 * 2.0) * 0.5;
    bounds->x2 = (float)(v15 * 2.0) * 0.5;
    return result;
  }
  v16 = child->pNode;
  v17 = *(_DWORD *)(v6 + 20);
  pviewMatrix.M[0][0] = *(float *)(v6 + 16);
  *(_QWORD *)&pviewMatrix.M[0][1] = __PAIR64__(*(_DWORD *)(v6 + 24), v17);
  v18 = *(_DWORD *)(v6 + 32);
  pParent = pMask->pParent;
  pviewMatrix.M[0][3] = *(float *)(v6 + 28);
  *(_QWORD *)&pviewMatrix.M[1][0] = __PAIR64__(*(_DWORD *)(v6 + 36), v18);
  *(_QWORD *)&pviewMatrix.M[1][2] = *(_QWORD *)(v6 + 40);
  if ( pParent == this )
  {
    v24 = *(__m128 *)&pviewMatrix.M[1][0];
    v23 = *(__m128 *)&pviewMatrix.M[0][0];
  }
  else
  {
    if ( pParent == child )
    {
      v20 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v16 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                      + 8i64
                      * (unsigned int)((__int64)((__int64)&v16[-1] - ((unsigned __int64)v16 & 0xFFFFFFFFFFFFF000ui64))
                                     / 56)
                      + 40) & 0xFFFFFFFFFFFFFFFEui64;
      v21 = *(__m128 *)(v20 + 16);
      v22 = *(__m128 *)(v20 + 32);
    }
    else
    {
      Scaleform::Render::TreeCacheNode::CalcViewMatrix(pMask, &pviewMatrix);
      *(_OWORD *)&v39.M[0][0] = _xmm;
      *(__m128 *)&v39.M[1][0] = _xmm;
      Scaleform::Render::TreeCacheNode::CalcViewMatrix(this, &v39);
      v21 = *(__m128 *)&v39.M[0][0];
      v22 = *(__m128 *)&v39.M[1][0];
    }
    v23 = _mm_and_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), *(__m128 *)&pviewMatrix.M[1][0]),
                _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), *(__m128 *)&pviewMatrix.M[0][0])),
              _mm_and_ps(v21, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
            (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
    v24 = _mm_and_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), *(__m128 *)&pviewMatrix.M[1][0]),
                _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), *(__m128 *)&pviewMatrix.M[0][0])),
              _mm_and_ps(v22, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
            (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
  }
  v25 = *(__m128 *)(v6 + 112);
  v26 = v23;
  v27 = _mm_unpacklo_ps(v23, v24);
  v28 = _mm_shuffle_ps(v26, v24, 255);
  result = 1;
  v29 = _mm_mul_ps(_mm_unpacklo_ps(v25, v25), v27);
  v30 = _mm_mul_ps(_mm_unpackhi_ps(v25, v25), v27);
  v31 = _mm_unpacklo_ps(v29, v30);
  v32 = _mm_unpackhi_ps(v29, v30);
  v33 = _mm_add_ps(v32, v31);
  v34 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 177), v32);
  v35 = _mm_min_ps(v33, v34);
  v36 = _mm_max_ps(v33, v34);
  v37 = _mm_add_ps(
          _mm_shuffle_ps(
            _mm_min_ps(v35, _mm_shuffle_ps(v35, v35, 177)),
            _mm_max_ps(v36, _mm_shuffle_ps(v36, v36, 177)),
            136),
          _mm_shuffle_ps(v28, v28, 136));
  LODWORD(bounds->x1) = v37.m128_i32[0];
  LODWORD(bounds->y2) = _mm_shuffle_ps(v37, v37, 255).m128_u32[0];
  LODWORD(bounds->y1) = _mm_shuffle_ps(v37, v37, 85).m128_u32[0];
  LODWORD(bounds->x2) = _mm_shuffle_ps(v37, v37, 170).m128_u32[0];
  return result;
}

// File Line: 580
// RVA: 0x9B6F90
// local variable allocation has failed, the output may be wrong!
void __fastcall Scaleform::Render::SnapRectToPixels(Scaleform::Render::Rect<float> *rect, double numPixels)
{
  __m128 x1_low; // xmm2
  int v3; // edx
  __m128 y1_low; // xmm2
  int v5; // edx
  __m128 v6; // xmm3
  int v7; // edx
  int v8; // edx

  *(float *)&numPixels = *(float *)&numPixels * 20.0;
  x1_low = (__m128)LODWORD(rect->x1);
  x1_low.m128_f32[0] = x1_low.m128_f32[0] - *(float *)&numPixels;
  v3 = (int)x1_low.m128_f32[0];
  if ( (int)x1_low.m128_f32[0] != 0x80000000 && (float)v3 != x1_low.m128_f32[0] )
    x1_low.m128_f32[0] = (float)(v3 - (_mm_movemask_ps(_mm_unpacklo_ps(x1_low, x1_low)) & 1));
  LODWORD(rect->x1) = x1_low.m128_i32[0];
  y1_low = (__m128)LODWORD(rect->y1);
  y1_low.m128_f32[0] = y1_low.m128_f32[0] - *(float *)&numPixels;
  v5 = (int)y1_low.m128_f32[0];
  if ( (int)y1_low.m128_f32[0] != 0x80000000 && (float)v5 != y1_low.m128_f32[0] )
    y1_low.m128_f32[0] = (float)(v5 - (_mm_movemask_ps(_mm_unpacklo_ps(y1_low, y1_low)) & 1));
  v6 = *(__m128 *)&numPixels;
  LODWORD(rect->y1) = y1_low.m128_i32[0];
  v6.m128_f32[0] = *(float *)&numPixels + rect->x2;
  v7 = (int)v6.m128_f32[0];
  if ( (int)v6.m128_f32[0] != 0x80000000 && (float)v7 != v6.m128_f32[0] )
    v6.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v6, v6)) & 1) + v7);
  *(float *)&numPixels = *(float *)&numPixels + rect->y2;
  LODWORD(rect->x2) = v6.m128_i32[0];
  v8 = (int)*(float *)&numPixels;
  if ( (int)*(float *)&numPixels != 0x80000000 && (float)v8 != *(float *)&numPixels )
    *(float *)&numPixels = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(*(__m128 *)&numPixels, *(__m128 *)&numPixels)) & 1)
                                 + v8);
  rect->y2 = *(float *)&numPixels;
}

// File Line: 591
// RVA: 0x9D3230
__int64 __fastcall Scaleform::Render::TreeCacheNode::calcMaskBounds(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::Rect<float> *maskBounds,
        Scaleform::Render::Matrix2x4<float> *boundAreaMatrix,
        Scaleform::Render::Matrix3x4<float> *viewMatrix,
        Scaleform::Render::Matrix4x4<float> *viewProjMatrix)
{
  Scaleform::Render::TreeCacheNode *v5; // r11
  Scaleform::Render::TreeCacheNode *pMask; // rbx
  Scaleform::Render::TreeCacheRoot **p_pRoot; // r13
  __m128 *v11; // r15
  __m128 *v12; // r14
  __int64 result; // rax
  bool v14; // al
  Scaleform::Render::TreeNode *pNode; // rcx
  float v16; // xmm1_4
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  float v19; // xmm0_4
  float v20; // xmm1_4
  int v21; // xmm0_4
  float v22; // xmm1_4
  int v23; // xmm0_4
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm3
  __m128 v27; // xmm0
  __m128 v28; // xmm2
  __m128 v29; // xmm0
  __m128 v30; // xmm3
  __m128 v31; // xmm0
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm2
  float v36; // xmm4_4
  float v37; // xmm1_4
  float v38; // xmm3_4
  float v39; // xmm7_4
  float v40; // xmm0_4
  float v41; // xmm5_4
  float v42; // xmm6_4
  float x1; // xmm1_4
  float x2; // xmm0_4
  __m128 v45; // xmm2
  __m128 v46; // xmm5
  float v47; // xmm0_4
  float y1; // xmm1_4
  float y2; // xmm0_4
  __m128 v50; // xmm7
  __m128 v51; // xmm1
  __m128 v52; // xmm0
  __m128 v53; // xmm2
  __m128 v54; // xmm5
  __int64 v55; // rdx
  __int64 v56; // rax
  unsigned __int64 v57; // rbx
  float v58; // xmm3_4
  float v59; // xmm0_4
  float v60; // xmm2_4
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // xmm0_4
  float v64; // xmm1_4
  float v65; // xmm0_4
  float v66; // xmm2_4
  float v67; // xmm3_4
  float v68; // xmm7_4
  float v69; // xmm5_4
  float v70; // xmm11_4
  float v71; // xmm4_4
  float v72; // xmm0_4
  float v73; // xmm1_4
  float v74; // xmm0_4
  float v75; // xmm0_4
  float v76; // xmm1_4
  float v77; // xmm0_4
  Scaleform::Render::Rect<float> rect; // [rsp+20h] [rbp-E0h] BYREF
  __m128 v79; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::Matrix3x4<float> pviewMatrix; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::Render::Matrix4x4<float> Dst; // [rsp+70h] [rbp-90h] BYREF

  v5 = this;
  pMask = this->pMask;
  p_pRoot = &this->pRoot;
  v11 = (__m128 *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                             + 8i64
                             * (unsigned int)((int)((int)&this->pNode[-1] - ((__int64)this->pNode & 0xFFFFF000)) / 56)
                             + 40) & 0xFFFFFFFFFFFFFFFEui64);
  v12 = (__m128 *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pMask->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                             + 8i64
                             * (unsigned int)((int)(LODWORD(pMask->pNode) - ((__int64)pMask->pNode & 0xFFFFF000) - 56)
                                            / 56)
                             + 40) & 0xFFFFFFFFFFFFFFFEui64);
  if ( !this->pRoot )
    return 0i64;
  v14 = (v12->m128_i16[5] & 0x200) != 0;
  while ( !v14 )
  {
    pNode = v5->pNode;
    v5 = v5->pParent;
    v14 = (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                 + 8i64
                                 * (unsigned int)((int)((_DWORD)pNode - ((unsigned int)pNode & 0xFFFFF000) - 56) / 56)
                                 + 40) & 0xFFFFFFFFFFFFFFFEui64)
                    + 10) & 0x200) != 0;
    if ( !v5 )
    {
      if ( (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                  + 8i64
                                  * (unsigned int)((int)((_DWORD)pNode - ((unsigned int)pNode & 0xFFFFF000) - 56) / 56)
                                  + 40) & 0xFFFFFFFFFFFFFFFEui64)
                     + 10) & 0x200) == 0 )
      {
        v16 = viewMatrix->M[0][1];
        v17 = v12[7];
        pviewMatrix.M[0][0] = viewMatrix->M[0][0];
        *(_QWORD *)&pviewMatrix.M[0][1] = __PAIR64__(LODWORD(viewMatrix->M[0][2]), LODWORD(v16));
        v18 = _mm_unpacklo_ps(v17, v17);
        v19 = viewMatrix->M[1][0];
        pviewMatrix.M[0][3] = viewMatrix->M[0][3];
        *(_QWORD *)&pviewMatrix.M[1][0] = __PAIR64__(LODWORD(viewMatrix->M[1][1]), LODWORD(v19));
        *(_QWORD *)&pviewMatrix.M[1][2] = *(_QWORD *)&viewMatrix->M[1][2];
        v20 = v12[1].m128_f32[1];
        LODWORD(rect.x1) = v12[1].m128_i32[0];
        LODWORD(rect.x2) = v12[1].m128_i32[2];
        v21 = v12[2].m128_i32[0];
        rect.y1 = v20;
        v22 = v12[1].m128_f32[3];
        v79.m128_i32[0] = v21;
        v23 = v12[2].m128_i32[2];
        rect.y2 = v22;
        *(unsigned __int64 *)((char *)v79.m128_u64 + 4) = __PAIR64__(v23, v12[2].m128_i32[1]);
        v79.m128_i32[3] = v12[2].m128_i32[3];
        v24 = _mm_unpacklo_ps((__m128)rect, v79);
        v25 = _mm_shuffle_ps((__m128)rect, v79, 255);
        v26 = _mm_mul_ps(_mm_unpackhi_ps(v17, v17), v24);
        v27 = _mm_mul_ps(v18, v24);
        v28 = _mm_unpackhi_ps(v27, v26);
        v29 = _mm_unpacklo_ps(v27, v26);
        v30 = _mm_add_ps(v28, v29);
        v31 = _mm_add_ps(_mm_shuffle_ps(v29, v29, 177), v28);
        v32 = v30;
        v33 = _mm_max_ps(v30, v31);
        v34 = _mm_min_ps(v32, v31);
        rect = 0i64;
        v35 = _mm_add_ps(
                _mm_shuffle_ps(
                  _mm_min_ps(v34, _mm_shuffle_ps(v34, v34, 177)),
                  _mm_max_ps(v33, _mm_shuffle_ps(v33, v33, 177)),
                  136),
                _mm_shuffle_ps(v25, v25, 136));
        LODWORD(maskBounds->x1) = v35.m128_i32[0];
        v36 = _mm_shuffle_ps(v35, v35, 255).m128_f32[0];
        LODWORD(v37) = _mm_shuffle_ps(v35, v35, 85).m128_u32[0];
        LODWORD(v38) = _mm_shuffle_ps(v35, v35, 170).m128_u32[0];
        maskBounds->y1 = v37;
        maskBounds->x2 = v38;
        maskBounds->y2 = v36;
        v39 = v11[7].m128_f32[1];
        if ( v36 < v39 )
          return 1i64;
        v40 = v11[7].m128_f32[3];
        if ( v40 < v37 )
          return 1i64;
        v41 = v11[7].m128_f32[2];
        if ( v41 < v35.m128_f32[0] )
          return 1i64;
        v42 = v11[7].m128_f32[0];
        if ( v38 < v42 )
          return 1i64;
        if ( v35.m128_f32[0] <= v42 )
          LODWORD(rect.x1) = v35.m128_i32[0];
        else
          LODWORD(rect.x1) = v11[7].m128_i32[0];
        if ( v38 <= v41 )
          rect.x2 = v41;
        else
          rect.x2 = v38;
        if ( v37 <= v39 )
          rect.y1 = v37;
        else
          rect.y1 = v39;
        if ( v36 <= v40 )
          rect.y2 = v40;
        else
          rect.y2 = v36;
        Scaleform::Render::SnapRectToPixels(&rect, COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_8_0)));
        x1 = rect.x1;
        x2 = rect.x2;
        *(_QWORD *)&boundAreaMatrix->M[0][1] = 0i64;
        boundAreaMatrix->M[1][0] = 0.0;
        boundAreaMatrix->M[1][2] = 0.0;
        v45 = *(__m128 *)&pviewMatrix.M[0][0];
        v46 = *(__m128 *)&pviewMatrix.M[1][0];
        v47 = x2 - x1;
        boundAreaMatrix->M[0][3] = x1;
        y1 = rect.y1;
        result = 2i64;
        boundAreaMatrix->M[0][0] = v47;
        y2 = rect.y2;
        boundAreaMatrix->M[1][3] = y1;
        boundAreaMatrix->M[1][1] = y2 - y1;
        v50 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
        v51 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), *(__m128 *)&boundAreaMatrix->M[1][0]),
                  _mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), *(__m128 *)&boundAreaMatrix->M[0][0])),
                _mm_and_ps(v45, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
        v52 = _mm_mul_ps(_mm_shuffle_ps(v46, v46, 0), *(__m128 *)&boundAreaMatrix->M[0][0]);
        v53 = _mm_shuffle_ps(v46, v46, 85);
        v54 = _mm_and_ps(v46, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
        *(__m128 *)&boundAreaMatrix->M[0][0] = _mm_and_ps(
                                                 v51,
                                                 (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
        *(__m128 *)&boundAreaMatrix->M[1][0] = _mm_and_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(v53, *(__m128 *)&boundAreaMatrix->M[1][0]),
                                                     v52),
                                                   v54),
                                                 v50);
        return result;
      }
      break;
    }
  }
  memset(&Dst, 0, sizeof(Dst));
  Dst.M[0][0] = 1.0;
  Dst.M[1][1] = 1.0;
  Dst.M[2][2] = 1.0;
  Dst.M[3][3] = 1.0;
  memset(&pviewMatrix, 0, sizeof(pviewMatrix));
  pviewMatrix.M[0][0] = 1.0;
  pviewMatrix.M[1][1] = 1.0;
  pviewMatrix.M[2][2] = 1.0;
  Scaleform::Render::TreeCacheNode::CalcViewMatrix(pMask, &pviewMatrix, &Dst);
  v55 = (unsigned __int128)((__int64)((__int64)&(*p_pRoot)->pNode[-1]
                                    - ((unsigned __int64)(*p_pRoot)->pNode & 0xFFFFFFFFFFFFF000ui64))
                          * (__int128)0x4924924924924925i64) >> 64;
  v56 = *(_QWORD *)(((unsigned __int64)(*p_pRoot)->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28);
  rect = 0i64;
  v57 = *(_QWORD *)(v56 + 8 * ((unsigned int)(v55 >> 4) + ((unsigned __int64)v55 >> 63)) + 40) & 0xFFFFFFFFFFFFFFFEui64;
  *(__m128 *)&Dst.M[0][0] = _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&Dst.M[0][0], *(__m128 *)&Dst.M[0][0], 85),
                                    *(__m128 *)&pviewMatrix.M[1][0]),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&Dst.M[0][0], *(__m128 *)&Dst.M[0][0], 0),
                                    *(__m128 *)&pviewMatrix.M[0][0])),
                                _mm_mul_ps(
                                  _mm_shuffle_ps(*(__m128 *)&Dst.M[0][0], *(__m128 *)&Dst.M[0][0], 170),
                                  *(__m128 *)&pviewMatrix.M[2][0])),
                              _mm_and_ps(
                                *(__m128 *)&Dst.M[0][0],
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
  *(__m128 *)&Dst.M[1][0] = _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&Dst.M[1][0], *(__m128 *)&Dst.M[1][0], 85),
                                    *(__m128 *)&pviewMatrix.M[1][0]),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&Dst.M[1][0], *(__m128 *)&Dst.M[1][0], 0),
                                    *(__m128 *)&pviewMatrix.M[0][0])),
                                _mm_mul_ps(
                                  _mm_shuffle_ps(*(__m128 *)&Dst.M[1][0], *(__m128 *)&Dst.M[1][0], 170),
                                  *(__m128 *)&pviewMatrix.M[2][0])),
                              _mm_and_ps(
                                *(__m128 *)&Dst.M[1][0],
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
  *(__m128 *)&Dst.M[2][0] = _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&Dst.M[2][0], *(__m128 *)&Dst.M[2][0], 85),
                                    *(__m128 *)&pviewMatrix.M[1][0]),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&Dst.M[2][0], *(__m128 *)&Dst.M[2][0], 0),
                                    *(__m128 *)&pviewMatrix.M[0][0])),
                                _mm_mul_ps(
                                  _mm_shuffle_ps(*(__m128 *)&Dst.M[2][0], *(__m128 *)&Dst.M[2][0], 170),
                                  *(__m128 *)&pviewMatrix.M[2][0])),
                              _mm_and_ps(
                                *(__m128 *)&Dst.M[2][0],
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
  *(__m128 *)&Dst.M[3][0] = _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&Dst.M[3][0], *(__m128 *)&Dst.M[3][0], 85),
                                    *(__m128 *)&pviewMatrix.M[1][0]),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&Dst.M[3][0], *(__m128 *)&Dst.M[3][0], 0),
                                    *(__m128 *)&pviewMatrix.M[0][0])),
                                _mm_mul_ps(
                                  _mm_shuffle_ps(*(__m128 *)&Dst.M[3][0], *(__m128 *)&Dst.M[3][0], 170),
                                  *(__m128 *)&pviewMatrix.M[2][0])),
                              _mm_and_ps(
                                *(__m128 *)&Dst.M[3][0],
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
  Scaleform::Render::Matrix4x4<float>::EncloseTransformHomogeneous(&Dst, (__m128 *)&rect, v12 + 7);
  v58 = 1.0 - rect.y2;
  v59 = (float)*(int *)(v57 + 176);
  v60 = rect.x2 + 1.0;
  v61 = (float)*(int *)(v57 + 180);
  maskBounds->x1 = (float)((float)(rect.x1 + 1.0) * v59) * 0.5;
  v62 = (float)(v60 * v59) * 0.5;
  v63 = 1.0 - rect.y1;
  maskBounds->x2 = v62;
  maskBounds->y1 = (float)(v58 * v61) * 0.5;
  maskBounds->y2 = (float)(v63 * v61) * 0.5;
  rect = 0i64;
  Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&Dst, viewProjMatrix, viewMatrix);
  Scaleform::Render::Matrix4x4<float>::EncloseTransformHomogeneous(&Dst, (__m128 *)&rect, v11 + 7);
  v64 = (float)*(int *)(v57 + 176);
  v65 = (float)*(int *)(v57 + 180);
  v66 = (float)((float)(rect.x1 + 1.0) * v64) * 0.5;
  v67 = (float)((float)(1.0 - rect.y2) * v65) * 0.5;
  v68 = (float)((float)(rect.x2 + 1.0) * v64) * 0.5;
  v69 = maskBounds->y2;
  v70 = (float)((float)(1.0 - rect.y1) * v65) * 0.5;
  if ( v69 < v67 )
    return 1i64;
  v71 = maskBounds->y1;
  if ( v70 < v71 )
    return 1i64;
  if ( v68 < maskBounds->x1 )
    return 1i64;
  v72 = maskBounds->x2;
  if ( v72 < v66 )
    return 1i64;
  if ( maskBounds->x1 <= v66 )
    v66 = maskBounds->x1;
  if ( v72 <= v68 )
    v72 = (float)((float)(rect.x2 + 1.0) * v64) * 0.5;
  if ( v71 <= v67 )
    v67 = maskBounds->y1;
  if ( v69 <= v70 )
    v69 = v70;
  maskBounds->x1 = v66;
  maskBounds->y1 = v67;
  maskBounds->x2 = v72;
  maskBounds->y2 = v69;
  rect.x1 = v66;
  rect.y1 = v67;
  rect.x2 = v72;
  rect.y2 = v69;
  Scaleform::Render::SnapRectToPixels(&rect, COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_8_0)));
  v73 = rect.x1;
  v74 = rect.x2;
  *(_QWORD *)&boundAreaMatrix->M[0][1] = 0i64;
  boundAreaMatrix->M[1][0] = 0.0;
  boundAreaMatrix->M[1][2] = 0.0;
  v75 = v74 - v73;
  boundAreaMatrix->M[0][3] = v73;
  v76 = rect.y1;
  result = 2i64;
  boundAreaMatrix->M[0][0] = v75;
  v77 = rect.y2;
  boundAreaMatrix->M[1][3] = v76;
  boundAreaMatrix->M[1][1] = v77 - v76;
  return result;
}reaMatrix->M[1][3] = v76;
  boundAreaMatrix->M[1][1] = v77 - v76;
  return result;
}

// File Line: 677
// RVA: 0x9D1420
__int64 __fastcall Scaleform::Render::TreeCacheNode::calcCacheableBounds(
        Scaleform::Render::TreeCacheNode *this,
        __m128 *returnBounds,
        Scaleform::Render::Matrix2x4<float> *areaMatrix,
        Scaleform::Render::Matrix3x4<float> *viewMatrix,
        Scaleform::Render::Matrix4x4<float> *viewProjMatrix,
        Scaleform::Render::Rect<float> *cullRect)
{
  Scaleform::Render::TreeCacheNode *v6; // r11
  Scaleform::Render::TreeCacheRoot **p_pRoot; // rdi
  Scaleform::Render::TreeCacheRoot *pRoot; // r9
  unsigned __int64 v12; // rsi
  __int64 result; // rax
  bool v14; // al
  Scaleform::Render::TreeNode *pNode; // rcx
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // eax
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128 v29; // xmm0
  __m128 v30; // xmm2
  __m128 v31; // xmm0
  __m128 v32; // xmm3
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // xmm3
  __m128 y2_low; // xmm6
  __m128 x2_low; // xmm7
  __m128 y1_low; // xmm8
  __m128 x1_low; // xmm9
  Scaleform::Render::TreeNode *v40; // rcx
  unsigned __int64 v41; // rbx
  float v42; // xmm1_4
  float v43; // xmm0_4
  Scaleform::Render::TreeCacheRoot *v44; // rcx
  int v45; // edi
  Scaleform::Render::TreeNode *v46; // rdx
  __int64 v47; // rax
  unsigned __int64 v48; // rdx
  unsigned __int64 v49; // rbx
  int v50; // edx
  __m128i v51; // xmm1
  __int128 v52; // xmm0
  __m128 v53; // xmm1
  int v54; // eax
  __int128 v55; // xmm2
  __int128 v56; // xmm3
  unsigned int *v57; // rcx
  __m128 v58; // xmm10
  __int128 v59; // xmm11
  __int128 v60; // xmm13
  __int128 v61; // xmm12
  Scaleform::Render::StateBag *v62; // rax
  _QWORD *pData; // rsi
  unsigned int i; // ebx
  char v65; // dl
  int v66; // ecx
  int v67; // ecx
  int v68; // ecx
  int v69; // ecx
  __int128 v70; // [rsp+20h] [rbp-B9h] BYREF
  Scaleform::Render::Rect<float> pr; // [rsp+30h] [rbp-A9h] BYREF
  Scaleform::Render::Matrix4x4<float> v72; // [rsp+40h] [rbp-99h] BYREF

  v6 = this;
  p_pRoot = &this->pRoot;
  pRoot = this->pRoot;
  v12 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                  + 8i64 * (unsigned int)((int)((int)&this->pNode[-1] - ((__int64)this->pNode & 0xFFFFF000)) / 56)
                  + 40) & 0xFFFFFFFFFFFFFFFEui64;
  if ( !pRoot )
    return 0i64;
  v14 = (*(_WORD *)(v12 + 10) & 0x200) != 0;
  do
  {
    if ( v14 )
      break;
    pNode = v6->pNode;
    v6 = v6->pParent;
    v14 = (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                 + 8i64
                                 * (unsigned int)((int)((_DWORD)pNode - ((unsigned int)pNode & 0xFFFFF000) - 56) / 56)
                                 + 40) & 0xFFFFFFFFFFFFFFFEui64)
                    + 10) & 0x200) != 0;
  }
  while ( v6 );
  v70 = 0i64;
  pr = 0i64;
  if ( v14 )
  {
    v40 = pRoot->pNode;
    pr = 0i64;
    v41 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v40 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                    + 8i64 * (unsigned int)((int)((_DWORD)v40 - ((unsigned int)v40 & 0xFFFFF000) - 56) / 56)
                    + 40) & 0xFFFFFFFFFFFFFFFEui64;
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v72, viewProjMatrix, viewMatrix);
    Scaleform::Render::Matrix4x4<float>::EncloseTransformHomogeneous(&v72, (__m128 *)&pr, (__m128 *)(v12 + 112));
    y2_low = (__m128)(unsigned int)FLOAT_1_0;
    x1_low = (__m128)LODWORD(pr.x1);
    y1_low = (__m128)(unsigned int)FLOAT_1_0;
    x2_low = (__m128)LODWORD(pr.x2);
    v42 = (float)*(int *)(v41 + 176);
    x1_low.m128_f32[0] = (float)((float)(pr.x1 + 1.0) * v42) * 0.5;
    x2_low.m128_f32[0] = (float)((float)(pr.x2 + 1.0) * v42) * 0.5;
    v43 = (float)*(int *)(v41 + 180);
    y1_low.m128_f32[0] = (float)((float)(1.0 - pr.y2) * v43) * 0.5;
    y2_low.m128_f32[0] = (float)((float)(1.0 - pr.y1) * v43) * 0.5;
  }
  else
  {
    v16 = viewMatrix->M[0][1];
    v17 = *(float *)(v12 + 124);
    v18 = *(float *)(v12 + 112);
    v72.M[0][0] = viewMatrix->M[0][0];
    *(_QWORD *)&v72.M[0][1] = __PAIR64__(LODWORD(viewMatrix->M[0][2]), LODWORD(v16));
    v19 = viewMatrix->M[0][3];
    v72.M[1][0] = viewMatrix->M[1][0];
    v20 = viewMatrix->M[1][2];
    v72.M[0][3] = v19;
    v21 = viewMatrix->M[1][1];
    v72.M[1][2] = v20;
    v22 = *(float *)(v12 + 116);
    v72.M[1][1] = v21;
    v72.M[1][3] = viewMatrix->M[1][3];
    v23 = *(float *)(v12 + 120);
    returnBounds->m128_f32[3] = v17;
    returnBounds->m128_f32[0] = v18;
    returnBounds->m128_f32[1] = v22;
    returnBounds->m128_f32[2] = v23;
    v24 = *returnBounds;
    v25 = _mm_unpacklo_ps(*(__m128 *)&v72.M[0][0], *(__m128 *)&v72.M[1][0]);
    v26 = _mm_shuffle_ps(*(__m128 *)&v72.M[0][0], *(__m128 *)&v72.M[1][0], 255);
    v27 = _mm_unpacklo_ps(v24, v24);
    v28 = _mm_mul_ps(_mm_unpackhi_ps(v24, v24), v25);
    v29 = _mm_mul_ps(v27, v25);
    v30 = _mm_unpackhi_ps(v29, v28);
    v31 = _mm_unpacklo_ps(v29, v28);
    v32 = _mm_add_ps(v30, v31);
    v33 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 177), v30);
    v34 = _mm_min_ps(v32, v33);
    v35 = _mm_max_ps(v32, v33);
    pr = (Scaleform::Render::Rect<float>)_mm_add_ps(
                                           _mm_shuffle_ps(
                                             _mm_min_ps(v34, _mm_shuffle_ps(v34, v34, 177)),
                                             _mm_max_ps(v35, _mm_shuffle_ps(v35, v35, 177)),
                                             136),
                                           _mm_shuffle_ps(v26, v26, 136));
    y2_low = (__m128)LODWORD(pr.y2);
    x2_low = (__m128)LODWORD(pr.x2);
    y1_low = (__m128)LODWORD(pr.y1);
    x1_low = (__m128)LODWORD(pr.x1);
  }
  v44 = *p_pRoot;
  v45 = 0;
  v46 = v44->pNode;
  *(_QWORD *)&pr.x1 = 0i64;
  *(_QWORD *)&pr.x2 = 0i64;
  v47 = *(_QWORD *)(((unsigned __int64)v46 & 0xFFFFFFFFFFFFF000ui64) + 0x28);
  v48 = (__int64)((unsigned __int128)((__int64)((__int64)&v46[-1] - ((unsigned __int64)v46 & 0xFFFFFFFFFFFFF000ui64))
                                    * (__int128)0x4924924924924925i64) >> 64) >> 4;
  v49 = *(_QWORD *)(v47 + 8 * ((unsigned int)v48 + (v48 >> 63)) + 40) & 0xFFFFFFFFFFFFFFFEui64;
  if ( Scaleform::Render::Viewport::GetClippedRect<int>(
         (Scaleform::Render::Viewport *)(v49 + 160),
         (Scaleform::Render::Rect<int> *)&pr,
         1) )
  {
    v50 = *(_DWORD *)(v49 + 168);
    v51 = _mm_cvtsi32_si128(LODWORD(pr.y1) - *(_DWORD *)(v49 + 172));
    v52 = COERCE_UNSIGNED_INT((float)(LODWORD(pr.x1) - v50));
    *(float *)&v70 = (float)(LODWORD(pr.x1) - v50);
    v53 = _mm_cvtepi32_ps(v51);
    v54 = LODWORD(pr.y2) - *(_DWORD *)(v49 + 172);
    DWORD1(v70) = v53.m128_i32[0];
    v55 = COERCE_UNSIGNED_INT((float)(LODWORD(pr.x2) - v50));
    *((float *)&v70 + 2) = (float)(LODWORD(pr.x2) - v50);
    v56 = COERCE_UNSIGNED_INT((float)v54);
    *((float *)&v70 + 3) = (float)v54;
  }
  else
  {
    v56 = HIDWORD(v70);
    v55 = DWORD2(v70);
    v53 = (__m128)DWORD1(v70);
    v52 = (unsigned int)v70;
  }
  v57 = (unsigned int *)&v70;
  if ( cullRect )
    v57 = (unsigned int *)cullRect;
  v58 = (__m128)*v57;
  v59 = v57[1];
  v60 = v57[2];
  v61 = v57[3];
  if ( (((*(_DWORD *)(v49 + 200) & 0x30) - 16) & 0xFFFFFFDF) == 0 )
  {
    v58 = v53;
    v59 = v52;
    v60 = v56;
    v61 = v55;
  }
  LODWORD(pr.x1) = v58.m128_i32[0];
  LODWORD(pr.y1) = v59;
  LODWORD(pr.x2) = v60;
  LODWORD(pr.y2) = v61;
  v62 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::FilterState>((Scaleform::Render::TreeNode::NodeData *)v12);
  if ( v62 )
  {
    pData = v62->pData;
    if ( pData )
    {
      for ( i = 0; i < *((_DWORD *)pData + 6); ++i )
        Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
          *(Scaleform::Render::Filter **)(pData[2] + 8i64 * i),
          &pr);
    }
  }
  v65 = 1;
  *(float *)&v60 = *(float *)&v60 + 32.0;
  v58.m128_f32[0] = v58.m128_f32[0] - 32.0;
  *(float *)&v59 = *(float *)&v59 - 32.0;
  *(float *)&v61 = *(float *)&v61 + 32.0;
  if ( *(float *)&v60 < x2_low.m128_f32[0]
    || *(float *)&v61 < y2_low.m128_f32[0]
    || v58.m128_f32[0] > x1_low.m128_f32[0]
    || *(float *)&v59 > y1_low.m128_f32[0] )
  {
    v65 = 0;
    if ( *(float *)&v61 < y1_low.m128_f32[0]
      || y2_low.m128_f32[0] < *(float *)&v59
      || x2_low.m128_f32[0] < v58.m128_f32[0]
      || *(float *)&v60 < x1_low.m128_f32[0] )
    {
      return 0i64;
    }
    if ( v58.m128_f32[0] > x1_low.m128_f32[0] )
      x1_low = v58;
    if ( *(float *)&v60 <= x2_low.m128_f32[0] )
      x2_low = (__m128)v60;
    if ( *(float *)&v59 > y1_low.m128_f32[0] )
      y1_low = (__m128)v59;
    if ( *(float *)&v61 <= y2_low.m128_f32[0] )
      y2_low = (__m128)v61;
  }
  v66 = (int)x1_low.m128_f32[0];
  if ( (int)x1_low.m128_f32[0] != 0x80000000 && (float)v66 != x1_low.m128_f32[0] )
    x1_low.m128_f32[0] = (float)(v66 - (_mm_movemask_ps(_mm_unpacklo_ps(x1_low, x1_low)) & 1));
  v67 = (int)y1_low.m128_f32[0];
  if ( (int)y1_low.m128_f32[0] != 0x80000000 && (float)v67 != y1_low.m128_f32[0] )
    y1_low.m128_f32[0] = (float)(v67 - (_mm_movemask_ps(_mm_unpacklo_ps(y1_low, y1_low)) & 1));
  v68 = (int)x2_low.m128_f32[0];
  if ( (int)x2_low.m128_f32[0] != 0x80000000 && (float)v68 != x2_low.m128_f32[0] )
    x2_low.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(x2_low, x2_low)) & 1) + v68);
  v69 = (int)y2_low.m128_f32[0];
  if ( (int)y2_low.m128_f32[0] != 0x80000000 && (float)v69 != y2_low.m128_f32[0] )
    y2_low.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(y2_low, y2_low)) & 1) + v69);
  returnBounds->m128_i32[2] = x2_low.m128_i32[0];
  returnBounds->m128_i32[3] = y2_low.m128_i32[0];
  returnBounds->m128_i32[0] = x1_low.m128_i32[0];
  returnBounds->m128_i32[1] = y1_low.m128_i32[0];
  *(_QWORD *)&areaMatrix->M[0][1] = 0i64;
  areaMatrix->M[1][0] = 0.0;
  areaMatrix->M[1][2] = 0.0;
  LOBYTE(v45) = v65 != 0;
  areaMatrix->M[0][0] = x2_low.m128_f32[0] - x1_low.m128_f32[0];
  areaMatrix->M[1][1] = y2_low.m128_f32[0] - y1_low.m128_f32[0];
  LODWORD(areaMatrix->M[0][3]) = x1_low.m128_i32[0];
  result = (unsigned int)(v45 + 1);
  LODWORD(areaMatrix->M[1][3]) = y1_low.m128_i32[0];
  return result;
}

// File Line: 766
// RVA: 0x95D0E0
void __fastcall Scaleform::Render::TreeCacheNode::CalcViewMatrix(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::Matrix2x4<float> *pviewMatrix)
{
  Scaleform::Render::TreeCacheNode *pParent; // r9
  Scaleform::Render::TreeNode *pNode; // rcx
  __m128 v5; // xmm7
  unsigned __int64 v6; // rdx
  __m128 v7; // xmm5
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm5

  pParent = this->pParent;
  for ( *pviewMatrix = *(Scaleform::Render::Matrix2x4<float> *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64)
                                                                                       + 0x28)
                                                                           + 8i64
                                                                           * (unsigned int)((int)(LODWORD(this->pNode)
                                                                                                - ((__int64)this->pNode & 0xFFFFF000)
                                                                                                - 56)
                                                                                          / 56)
                                                                           + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                                              + 16);
        pParent;
        *(__m128 *)&pviewMatrix->M[1][0] = _mm_and_ps(
                                             _mm_add_ps(
                                               _mm_add_ps(_mm_mul_ps(v8, *(__m128 *)&pviewMatrix->M[1][0]), v9),
                                               v10),
                                             v5) )
  {
    pNode = pParent->pNode;
    pParent = pParent->pParent;
    v5 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
    v6 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                   + 8i64 * (unsigned int)((int)((_DWORD)pNode - ((unsigned int)pNode & 0xFFFFF000) - 56) / 56)
                   + 40) & 0xFFFFFFFFFFFFFFFEui64;
    v7 = *(__m128 *)(v6 + 32);
    v8 = _mm_shuffle_ps(v7, v7, 85);
    v9 = _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), *(__m128 *)&pviewMatrix->M[0][0]);
    v10 = _mm_and_ps(v7, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
    *(__m128 *)&pviewMatrix->M[0][0] = _mm_and_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(*(__m128 *)(v6 + 16), *(__m128 *)(v6 + 16), 85),
                                               *(__m128 *)&pviewMatrix->M[1][0]),
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(*(__m128 *)(v6 + 16), *(__m128 *)(v6 + 16), 0),
                                               *(__m128 *)&pviewMatrix->M[0][0])),
                                           _mm_and_ps(
                                             *(__m128 *)(v6 + 16),
                                             (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
                                         (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
  }
}

// File Line: 782
// RVA: 0x95D240
void __fastcall Scaleform::Render::TreeCacheNode::CalcViewMatrix(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::Matrix3x4<float> *pviewMatrix,
        Scaleform::Render::Matrix4x4<float> *pviewProj)
{
  Scaleform::Render::TreeNode *pNode; // rdx
  __int64 v7; // rax
  unsigned __int64 v8; // rdx
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rbx
  unsigned __int64 v11; // rcx
  Scaleform::Render::TreeCacheNode **p_pParent; // r10
  Scaleform::Render::TreeCacheNode *v13; // r10
  __m128 v14; // xmm8
  __m128 *v15; // r8
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm9
  __m128 v19; // xmm6
  __m128 v20; // xmm0
  Scaleform::Render::TreeNode *v21; // r9
  unsigned __int64 v22; // r8
  signed int v23; // r9d
  __int64 v24; // rax
  unsigned __int64 v25; // rdx
  __int64 v26; // r9
  unsigned __int64 v27; // rdx
  _QWORD *v28; // rax
  Scaleform::Render::TreeNode *v29; // r9
  unsigned __int64 *v30; // r8
  unsigned __int64 v31; // rdx
  __int64 v32; // r9
  unsigned __int64 v33; // rdx
  _QWORD *v34; // rax
  __m128 *v35; // rdx
  __m128 v36; // xmm10
  __m128 v37; // xmm6
  __m128 v38; // xmm5
  int v39; // eax
  __m128 *v40; // rdx
  __m128i v41; // xmm11
  __m128i v42; // xmm9
  __m128i v43; // xmm3
  __m128i v44; // xmm2
  __m256i v45; // [rsp+18h] [rbp-79h]
  __m128 v46; // [rsp+28h] [rbp-69h]
  __m128 v47; // [rsp+38h] [rbp-59h]
  __m128 v48; // [rsp+48h] [rbp-49h]
  __m128 v49; // [rsp+58h] [rbp-39h]
  __m128 v50; // [rsp+68h] [rbp-29h]

  pNode = this->pNode;
  if ( !pNode )
  {
    v9 = 0i64;
LABEL_6:
    v10 = 0i64;
    goto LABEL_7;
  }
  v7 = *(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28);
  v8 = (__int64)((unsigned __int128)((__int64)((__int64)&pNode[-1] - ((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64))
                                   * (__int128)0x4924924924924925i64) >> 64) >> 4;
  v9 = *(_QWORD *)(v7 + 8 * ((unsigned int)v8 + (v8 >> 63)) + 40) & 0xFFFFFFFFFFFFFFFEui64;
  if ( !v9 || (*(_WORD *)(v9 + 10) & 0x800) == 0 )
    goto LABEL_6;
  v10 = (unsigned __int64)Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::ViewMatrix3DState>((Scaleform::Render::TreeNode::NodeData *)v9);
LABEL_7:
  if ( v9 && (*(_WORD *)(v9 + 10) & 0x1000) != 0 )
    v11 = (unsigned __int64)Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::ProjectionMatrix3DState>((Scaleform::Render::TreeNode::NodeData *)v9);
  else
    v11 = 0i64;
  pviewMatrix->M[0][0] = *(float *)(v9 + 16);
  p_pParent = &this->pParent;
  pviewMatrix->M[0][1] = *(float *)(v9 + 20);
  pviewMatrix->M[0][2] = *(float *)(v9 + 24);
  pviewMatrix->M[0][3] = *(float *)(v9 + 28);
  pviewMatrix->M[1][0] = *(float *)(v9 + 32);
  pviewMatrix->M[1][1] = *(float *)(v9 + 36);
  pviewMatrix->M[1][2] = *(float *)(v9 + 40);
  pviewMatrix->M[1][3] = *(float *)(v9 + 44);
  pviewMatrix->M[2][0] = *(float *)(v9 + 48);
  pviewMatrix->M[2][1] = *(float *)(v9 + 52);
  pviewMatrix->M[2][2] = *(float *)(v9 + 56);
  pviewMatrix->M[2][3] = *(float *)(v9 + 60);
  while ( *p_pParent )
  {
    v13 = *p_pParent;
    v14 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v;
    v45.m256i_i32[2] = LODWORD(pviewMatrix->M[0][0]);
    v15 = (__m128 *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v13->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                               + 8i64
                               * (unsigned int)((int)(LODWORD(v13->pNode) - ((__int64)v13->pNode & 0xFFFFF000) - 56) / 56)
                               + 40) & 0xFFFFFFFFFFFFFFFEui64);
    v45.m256i_i32[3] = LODWORD(pviewMatrix->M[0][1]);
    v16 = v15[1];
    v17 = v15[2];
    v18 = v15[3];
    v45.m256i_i32[4] = LODWORD(pviewMatrix->M[0][2]);
    v19 = *(__m128 *)&v45.m256i_u64[1];
    v20 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), *(__m128 *)&v45.m256i_u64[1]);
    v45 = *(__m256i *)&pviewMatrix->M[1][0];
    *(__m128 *)&pviewMatrix->M[0][0] = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), *(__m128 *)v45.m256i_i8),
                                             v20),
                                           _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), *(__m128 *)&v45.m256i_u64[2])),
                                         _mm_and_ps(
                                           (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v,
                                           v16));
    *(__m128 *)&pviewMatrix->M[1][0] = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), *(__m128 *)v45.m256i_i8),
                                             _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v19)),
                                           _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), *(__m128 *)&v45.m256i_u64[2])),
                                         _mm_and_ps(v14, v17));
    *(__m128 *)&pviewMatrix->M[2][0] = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), *(__m128 *)v45.m256i_i8),
                                             _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v19)),
                                           _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), *(__m128 *)&v45.m256i_u64[2])),
                                         _mm_and_ps(v14, v18));
    if ( !v10 )
    {
      v21 = v13->pNode;
      if ( (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                  + 8i64
                                  * (unsigned int)((int)(LODWORD(v13->pNode) - ((unsigned int)v21 & 0xFFFFF000) - 56)
                                                 / 56)
                                  + 40) & 0xFFFFFFFFFFFFFFFEui64)
                     + 10) & 0x800) != 0 )
      {
        v22 = (unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64;
        v23 = (_DWORD)v21 - ((unsigned int)v21 & 0xFFFFF000) - 56;
        v24 = *(_QWORD *)(v22 + 40);
        v25 = *(_QWORD *)((*(_QWORD *)(v24 + 8i64 * (unsigned int)(v23 / 56) + 40) & 0xFFFFFFFFFFFFFFFEui64) + 64);
        if ( !v25 )
          goto LABEL_23;
        if ( (v25 & 1) != 0 )
        {
          if ( (v25 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A68 )
            v10 = (*(_QWORD *)(v24 + 8i64 * (unsigned int)(v23 / 56) + 40) & 0xFFFFFFFFFFFFFFFEui64) + 64;
        }
        else
        {
          v26 = *(_QWORD *)((*(_QWORD *)(v24 + 8i64 * (unsigned int)(v23 / 56) + 40) & 0xFFFFFFFFFFFFFFFEui64) + 72)
              + 4i64;
          v27 = v25 >> 1;
          if ( !v27 )
          {
LABEL_23:
            v10 = 0i64;
            goto LABEL_24;
          }
          v28 = (_QWORD *)v26;
          while ( *v28 != qword_142451A68 )
          {
            ++v10;
            v28 += 2;
            if ( v10 >= v27 )
              goto LABEL_23;
          }
          v10 = v26 + 16 * v10;
        }
      }
    }
LABEL_24:
    if ( !v11 )
    {
      v29 = v13->pNode;
      if ( (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v29 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                  + 8i64
                                  * (unsigned int)((int)(LODWORD(v13->pNode) - ((unsigned int)v29 & 0xFFFFF000) - 56)
                                                 / 56)
                                  + 40) & 0xFFFFFFFFFFFFFFFEui64)
                     + 10) & 0x1000) != 0 )
      {
        v30 = (unsigned __int64 *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v29 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                              + 8i64
                                              * (unsigned int)((int)((_DWORD)v29 - ((unsigned int)v29 & 0xFFFFF000) - 56)
                                                             / 56)
                                              + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                 + 64);
        v31 = *v30;
        if ( *v30 )
        {
          v11 = 0i64;
          if ( (v31 & 1) != 0 )
          {
            if ( (v31 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A70 )
              v11 = (*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v29 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                               + 8i64 * (unsigned int)((int)((_DWORD)v29 - ((unsigned int)v29 & 0xFFFFF000) - 56) / 56)
                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                  + 64;
            goto LABEL_37;
          }
          v32 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v29 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                       + 8i64
                                       * (unsigned int)((int)((_DWORD)v29 - ((unsigned int)v29 & 0xFFFFF000) - 56) / 56)
                                       + 40) & 0xFFFFFFFFFFFFFFFEui64)
                          + 72)
              + 4i64;
          v33 = v31 >> 1;
          if ( v33 )
          {
            v34 = (_QWORD *)(v30[1] + 4);
            while ( *v34 != qword_142451A70 )
            {
              ++v11;
              v34 += 2;
              if ( v11 >= v33 )
                goto LABEL_36;
            }
            v11 = v32 + 16 * v11;
            goto LABEL_37;
          }
        }
LABEL_36:
        v11 = 0i64;
      }
    }
LABEL_37:
    p_pParent = &v13->pParent;
  }
  if ( v10 && v11 )
  {
    v35 = *(__m128 **)(v10 + 8);
    v36 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v;
    v45.m256i_i64[1] = v35[1].m128_i64[0];
    v45.m256i_i32[4] = v35[1].m128_i32[2];
    v37 = *(__m128 *)&v45.m256i_u64[1];
    v38 = v35[2];
    v46.m128_u64[0] = v35[3].m128_u64[0];
    v46.m128_i32[2] = v35[3].m128_i32[2];
    v39 = v35[3].m128_i32[3];
    v40 = *(__m128 **)(v11 + 8);
    v46.m128_i32[3] = v39;
    v47 = v40[1];
    v48 = v40[2];
    v49 = v40[3];
    v41 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v47, v47, 85), v38),
                         _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), v37)),
                       _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), v46)),
                     _mm_and_ps(v47, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
    v50 = v40[4];
    LODWORD(pviewProj->M[0][0]) = _mm_cvtsi128_si32(v41);
    v42 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), v38),
                         _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), v37)),
                       _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), v46)),
                     _mm_and_ps(v48, v36));
    v43 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v49, v49, 85), v38),
                         _mm_mul_ps(_mm_shuffle_ps(v49, v49, 0), v37)),
                       _mm_mul_ps(_mm_shuffle_ps(v49, v49, 170), v46)),
                     _mm_and_ps(v49, v36));
    LODWORD(pviewProj->M[0][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v41, 4));
    LODWORD(pviewProj->M[0][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v41, 8));
    LODWORD(pviewProj->M[0][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v41, 12));
    v44 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), v38),
                         _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), v37)),
                       _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), v46)),
                     _mm_and_ps(v50, v36));
    LODWORD(pviewProj->M[1][0]) = _mm_cvtsi128_si32(v42);
    LODWORD(pviewProj->M[1][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v42, 4));
    LODWORD(pviewProj->M[1][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v42, 8));
    LODWORD(pviewProj->M[1][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v42, 12));
    LODWORD(pviewProj->M[2][0]) = _mm_cvtsi128_si32(v43);
    LODWORD(pviewProj->M[2][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v43, 4));
    LODWORD(pviewProj->M[2][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v43, 8));
    LODWORD(pviewProj->M[2][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v43, 12));
    LODWORD(pviewProj->M[3][0]) = _mm_cvtsi128_si32(v44);
    LODWORD(pviewProj->M[3][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v44, 4));
    LODWORD(pviewProj->M[3][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v44, 8));
    LODWORD(pviewProj->M[3][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v44, 12));
  }
  else
  {
    *pviewProj = Scaleform::Render::Matrix4x4<float>::Identity;
  }
}

// File Line: 832
// RVA: 0x95B900
void __fastcall Scaleform::Render::TreeCacheNode::CalcCxform(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::Cxform *dest)
{
  Scaleform::Render::TreeCacheNode *i; // r9
  Scaleform::Render::TreeNode *pNode; // rcx
  __m128 v5; // xmm3
  __m128 *v6; // rdx
  __m128 v7; // xmm1

  *dest = *(Scaleform::Render::Cxform *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64)
                                                                + 0x28)
                                                    + 8i64
                                                    * (unsigned int)((int)(LODWORD(this->pNode)
                                                                         - ((__int64)this->pNode & 0xFFFFF000)
                                                                         - 56)
                                                                   / 56)
                                                    + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                       + 80);
  for ( i = this->pParent; i; i = i->pParent )
  {
    pNode = i->pNode;
    if ( (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                + 8i64
                                * (unsigned int)((int)(LODWORD(i->pNode) - ((unsigned int)pNode & 0xFFFFF000) - 56) / 56)
                                + 40) & 0xFFFFFFFFFFFFFFFEui64)
                   + 10) & 0x400) != 0 )
      break;
    v5 = *(__m128 *)&dest->M[1][0];
    v6 = (__m128 *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                              + 8i64
                              * (unsigned int)((int)((_DWORD)pNode - ((unsigned int)pNode & 0xFFFFF000) - 56) / 56)
                              + 40) & 0xFFFFFFFFFFFFFFFEui64);
    v7 = _mm_mul_ps(v6[6], *(__m128 *)&dest->M[0][0]);
    *(__m128 *)&dest->M[0][0] = _mm_mul_ps(v6[5], *(__m128 *)&dest->M[0][0]);
    *(__m128 *)&dest->M[1][0] = _mm_add_ps(v5, v7);
  }
}

// File Line: 849
// RVA: 0x98F690
Scaleform::Render::Matrix4x4<float> *__fastcall Scaleform::Render::TreeCacheNode::GetViewProj(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::Matrix4x4<float> *result)
{
  Scaleform::Render::TreeNode *pNode; // rdx
  __int64 v5; // rax
  unsigned __int64 v6; // rdx
  Scaleform::Render::TreeNode::NodeData *v7; // rsi
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // rcx
  Scaleform::Render::TreeCacheNode **p_pParent; // rax
  Scaleform::Render::TreeCacheNode *v11; // rsi
  Scaleform::Render::TreeNode *v12; // r9
  unsigned __int64 v13; // r8
  signed int v14; // r9d
  __int64 v15; // rax
  unsigned __int64 *v16; // r8
  unsigned __int64 v17; // rdx
  __int64 v18; // r9
  unsigned __int64 v19; // rdx
  _QWORD *v20; // rax
  Scaleform::Render::TreeNode *v21; // r9
  unsigned __int64 v22; // rdx
  unsigned __int64 v23; // rdx
  _QWORD *v24; // rax
  void *v25; // rdx
  __m128 v26; // xmm10
  __m128 v27; // xmm6
  int v28; // eax
  __m128 *v29; // rdx
  __m128 v30; // xmm5
  __m128 v31; // xmm9
  Scaleform::Render::Matrix4x4<float> *v32; // rax
  __m128 v33; // [rsp+8h] [rbp-79h]
  __m128 v34; // [rsp+28h] [rbp-59h]
  __m128 v35; // [rsp+38h] [rbp-49h]
  __m128 v36; // [rsp+48h] [rbp-39h]

  pNode = this->pNode;
  if ( !pNode )
  {
    v7 = 0i64;
LABEL_6:
    v8 = 0i64;
    goto LABEL_7;
  }
  v5 = *(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28);
  v6 = (__int64)((unsigned __int128)((__int64)((__int64)&pNode[-1] - ((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64))
                                   * (__int128)0x4924924924924925i64) >> 64) >> 4;
  v7 = (Scaleform::Render::TreeNode::NodeData *)(*(_QWORD *)(v5 + 8 * ((unsigned int)v6 + (v6 >> 63)) + 40) & 0xFFFFFFFFFFFFFFFEui64);
  if ( !v7 || (v7->Flags & 0x800) == 0 )
    goto LABEL_6;
  v8 = (unsigned __int64)Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::ViewMatrix3DState>(v7);
LABEL_7:
  if ( v7 && (v7->Flags & 0x1000) != 0 )
    v9 = (unsigned __int64)Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::ProjectionMatrix3DState>(v7);
  else
    v9 = 0i64;
  p_pParent = &this->pParent;
  if ( this->pParent )
  {
    do
    {
      if ( v8 && v9 )
        break;
      v11 = *p_pParent;
      if ( !v8 )
      {
        v12 = v11->pNode;
        if ( (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                    + 8i64
                                    * (unsigned int)((int)(LODWORD(v11->pNode) - ((unsigned int)v12 & 0xFFFFF000) - 56)
                                                   / 56)
                                    + 40) & 0xFFFFFFFFFFFFFFFEui64)
                       + 10) & 0x800) != 0 )
        {
          v13 = (unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64;
          v14 = (_DWORD)v12 - ((unsigned int)v12 & 0xFFFFF000) - 56;
          v15 = *(_QWORD *)(v13 + 40);
          v16 = (unsigned __int64 *)((*(_QWORD *)(v15 + 8i64 * (unsigned int)(v14 / 56) + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                   + 64);
          v17 = *v16;
          if ( !*v16 )
            goto LABEL_25;
          if ( (v17 & 1) != 0 )
          {
            if ( (v17 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A68 )
              v8 = (*(_QWORD *)(v15 + 8i64 * (unsigned int)(v14 / 56) + 40) & 0xFFFFFFFFFFFFFFFEui64) + 64;
          }
          else
          {
            v18 = *(_QWORD *)((*(_QWORD *)(v15 + 8i64 * (unsigned int)(v14 / 56) + 40) & 0xFFFFFFFFFFFFFFFEui64) + 72)
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
                                    + 8i64
                                    * (unsigned int)((int)(LODWORD(v11->pNode) - ((unsigned int)v21 & 0xFFFFF000) - 56)
                                                   / 56)
                                    + 40) & 0xFFFFFFFFFFFFFFFEui64)
                       + 10) & 0x1000) != 0 )
        {
          v22 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                       + 8i64
                                       * (unsigned int)((int)((_DWORD)v21 - ((unsigned int)v21 & 0xFFFFF000) - 56) / 56)
                                       + 40) & 0xFFFFFFFFFFFFFFFEui64)
                          + 64);
          if ( v22 )
          {
            v9 = 0i64;
            if ( (v22 & 1) != 0 )
            {
              if ( (v22 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A70 )
                v9 = (*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                + 8i64 * (unsigned int)((int)((_DWORD)v21 - ((unsigned int)v21 & 0xFFFFF000) - 56) / 56)
                                + 40) & 0xFFFFFFFFFFFFFFFEui64)
                   + 64;
              goto LABEL_39;
            }
            v23 = v22 >> 1;
            if ( v23 )
            {
              v24 = (_QWORD *)(*(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64)
                                                                  + 0x28)
                                                      + 8i64
                                                      * (unsigned int)((int)((_DWORD)v21
                                                                           - ((unsigned int)v21 & 0xFFFFF000)
                                                                           - 56)
                                                                     / 56)
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
                                          + 8i64
                                          * (unsigned int)((int)((_DWORD)v21 - ((unsigned int)v21 & 0xFFFFF000) - 56)
                                                         / 56)
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
      p_pParent = &v11->pParent;
    }
    while ( v11->pParent );
  }
  if ( v8 && v9 )
  {
    v25 = *(void **)(v8 + 8);
    v33 = (__m128)*((_OWORD *)v25 + 1);
    v26 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v;
    v27 = *((__m128 *)v25 + 2);
    v34.m128_u64[0] = *((_QWORD *)v25 + 6);
    v34.m128_i32[2] = *((_DWORD *)v25 + 14);
    v28 = *((_DWORD *)v25 + 15);
    v29 = *(__m128 **)(v9 + 8);
    v34.m128_i32[3] = v28;
    v35 = v29[1];
    v36 = v29[2];
    v30 = v29[3];
    v31 = v29[4];
    v32 = result;
    *(__m128 *)&result->M[0][0] = _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_mul_ps(_mm_shuffle_ps(v35, v35, 85), v27),
                                        _mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), v33)),
                                      _mm_mul_ps(_mm_shuffle_ps(v35, v35, 170), v34)),
                                    _mm_and_ps(
                                      v35,
                                      (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
    *(__m128 *)&result->M[1][0] = _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_mul_ps(_mm_shuffle_ps(v36, v36, 85), v27),
                                        _mm_mul_ps(_mm_shuffle_ps(v36, v36, 0), v33)),
                                      _mm_mul_ps(_mm_shuffle_ps(v36, v36, 170), v34)),
                                    _mm_and_ps(v36, v26));
    *(__m128 *)&result->M[2][0] = _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v27),
                                        _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v33)),
                                      _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v34)),
                                    _mm_and_ps(v30, v26));
    *(__m128 *)&result->M[3][0] = _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), v27),
                                        _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v33)),
                                      _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v34)),
                                    _mm_and_ps(v31, v26));
  }
  else
  {
    *result = Scaleform::Render::Matrix4x4<float>::Identity;
    return result;
  }
  return v32;
}

// File Line: 877
// RVA: 0x9F9BB0
void __fastcall Scaleform::Render::TreeCacheNode::updateFilterCache(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::TreeNode::NodeData *data,
        Scaleform::Render::TransformArgs *t,
        Scaleform::Render::TransformFlags flags,
        Scaleform::Render::Rect<float> *cullRect,
        Scaleform::Render::Matrix3x4<float> *m3,
        bool is3d)
{
  __int16 v7; // bx
  Scaleform::Render::FilterEffect *pEffect; // rdi
  Scaleform::Render::Matrix4x4<float> *viewProjMatrix; // rax
  int v13; // r14d
  bool updated; // si
  __int128 v15; // xmm1
  bool v16; // r9
  Scaleform::Render::CacheEffectVtbl *vfptr; // rbx
  Scaleform::Render::StateBag *v18; // rax
  Scaleform::Render::Cxform returnBounds; // [rsp+30h] [rbp-58h] BYREF
  Scaleform::Render::Matrix2x4<float> areaMatrix; // [rsp+50h] [rbp-38h] BYREF

  v7 = flags;
  if ( (data->Flags & 0x400) != 0 && (flags & 0x203) != 0 )
  {
    pEffect = (Scaleform::Render::FilterEffect *)this->Effects.pEffect;
    *(_OWORD *)&areaMatrix.M[0][0] = _xmm;
    *(__m128 *)&areaMatrix.M[1][0] = _xmm;
    *(_OWORD *)&returnBounds.M[0][0] = 0i64;
    if ( pEffect )
    {
      while ( pEffect->vfptr->GetType(pEffect) != State_Filter )
      {
        pEffect = (Scaleform::Render::FilterEffect *)pEffect->pNext;
        if ( !pEffect )
          return;
      }
      viewProjMatrix = Scaleform::Render::TransformArgs::GetViewProj(t);
      v13 = Scaleform::Render::TreeCacheNode::calcCacheableBounds(
              this,
              (__m128 *)&returnBounds,
              &areaMatrix,
              m3,
              viewProjMatrix,
              cullRect);
      if ( v13 )
      {
        updated = 0;
        if ( (v7 & 2) != 0 )
        {
          v15 = *(_OWORD *)&t->Cx.M[1][0];
          *(_OWORD *)&returnBounds.M[0][0] = *(_OWORD *)&t->Cx.M[0][0];
          *(_OWORD *)&returnBounds.M[1][0] = v15;
          Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(&pEffect->BoundsMatrix, &returnBounds);
        }
        if ( (v7 & 1) != 0 )
        {
          v16 = is3d || v13 == 1;
          updated = Scaleform::Render::FilterEffect::UpdateMatrix(pEffect, &areaMatrix, &t->Mat, v16);
        }
        if ( updated || (v7 & 0x200) != 0 )
        {
          vfptr = pEffect->vfptr;
          v18 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::FilterState>(data);
          vfptr->Update(pEffect, (Scaleform::Render::State *)v18);
        }
      }
    }
  }
}

// File Line: 920
// RVA: 0x9F89B0
void __fastcall Scaleform::Render::TreeCacheNode::updateBlendCache(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::TreeNode::NodeData *data,
        Scaleform::Render::TransformArgs *t,
        Scaleform::Render::TransformFlags flags,
        Scaleform::Render::Rect<float> *cullRect,
        Scaleform::Render::Matrix3x4<float> *m3)
{
  Scaleform::Render::StateBag *p_States; // rax
  char v7; // di
  Scaleform::Render::StateData::Interface *pInterface; // rdx
  char *pData; // r9
  __int64 v12; // rax
  _QWORD *v13; // r9
  unsigned __int64 v14; // rdx
  _QWORD *i; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix *pEffect; // rbx
  Scaleform::Render::Matrix4x4<float> *viewProjMatrix; // rax
  Scaleform::Render::Rect<float> returnBounds; // [rsp+30h] [rbp-38h] BYREF
  Scaleform::Render::Matrix2x4<float> areaMatrix; // [rsp+40h] [rbp-28h] BYREF

  p_States = &data->States;
  v7 = flags;
  pInterface = data->States.pInterface;
  if ( pInterface )
  {
    if ( ((unsigned __int8)pInterface & 1) != 0 )
    {
      if ( ((unsigned __int64)pInterface & 0xFFFFFFFFFFFFFFFEui64) != qword_142451A48 )
        return;
    }
    else
    {
      pData = (char *)p_States->pData;
      v12 = 0i64;
      v13 = pData + 4;
      v14 = (unsigned __int64)pInterface >> 1;
      if ( !v14 )
        return;
      for ( i = v13; *i != qword_142451A48; i += 2 )
      {
        if ( ++v12 >= v14 )
          return;
      }
      p_States = (Scaleform::Render::StateBag *)&v13[2 * v12];
    }
    if ( p_States )
    {
      if ( (v7 & 3) != 0 )
      {
        pEffect = (Scaleform::Render::MatrixPoolImpl::HMatrix *)this->Effects.pEffect;
        *(_OWORD *)&areaMatrix.M[0][0] = _xmm;
        *(__m128 *)&areaMatrix.M[1][0] = _xmm;
        returnBounds = 0i64;
        if ( pEffect )
        {
          while ( ((unsigned int (__fastcall *)(Scaleform::Render::MatrixPoolImpl::HMatrix *))pEffect->pHandle[1].pHeader)(pEffect) != 1 )
          {
            pEffect = (Scaleform::Render::MatrixPoolImpl::HMatrix *)pEffect[1].pHandle;
            if ( !pEffect )
              return;
          }
          if ( (v7 & 1) != 0 )
          {
            viewProjMatrix = Scaleform::Render::TransformArgs::GetViewProj(t);
            if ( (unsigned int)Scaleform::Render::TreeCacheNode::calcCacheableBounds(
                                 this,
                                 (__m128 *)&returnBounds,
                                 &areaMatrix,
                                 m3,
                                 viewProjMatrix,
                                 cullRect) )
              Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(pEffect + 19, &areaMatrix);
          }
          Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(pEffect + 19, &t->Cx);
        }
      }
    }
  }
}

// File Line: 948
// RVA: 0x94D5D0
void __fastcall Scaleform::Render::TreeCacheContainer::~TreeCacheContainer(Scaleform::Render::TreeCacheContainer *this)
{
  Scaleform::Render::TreeCacheNode *i; // rcx
  float *p_x2; // rax
  Scaleform::Render::TreeCacheNode *pNext; // rdi

  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheContainer::`vftable;
  for ( i = this->Children.Root.pNext; ; i = pNext )
  {
    p_x2 = &this->SortParentBounds.x2;
    if ( this == (Scaleform::Render::TreeCacheContainer *)-112i64 )
      p_x2 = 0i64;
    if ( i == (Scaleform::Render::TreeCacheNode *)p_x2 )
      break;
    pNext = i->pNext;
    i->pParent = 0i64;
    i->pNext = 0i64;
    i->pPrev = 0i64;
    if ( i->pRoot )
      i->vfptr->HandleRemoveNode(i);
  }
  Scaleform::Render::TreeCacheNode::~TreeCacheNode(this);
}

// File Line: 973
// RVA: 0x9BF480
void __fastcall Scaleform::Render::TreeCacheContainer::UpdateTransform(
        Scaleform::Render::TreeCacheContainer *this,
        Scaleform::Render::TreeNode::NodeData *pbaseData,
        Scaleform::Render::TransformArgs *t,
        Scaleform::Render::TransformFlags flags)
{
  float x1; // xmm0_4
  float y1; // xmm1_4
  Scaleform::Render::ProjectionMatrix3DState *projState; // rax
  float x2; // xmm0_4
  float y2; // xmm1_4
  float v9; // xmm0_4
  Scaleform::Render::TransformFlags updated; // eax
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  Scaleform::Render::TransformFlags v17; // r12d
  Scaleform::Render::TreeCacheNode *pNext; // r14
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // rax
  __int64 v20; // rax
  char UpdateFlags; // si
  unsigned __int64 v22; // rdi
  int v23; // esi
  __m128 v24; // xmm4
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  unsigned int v27; // esi
  float v28; // xmm1_4
  float v29; // xmm0_4
  __m128 v30; // xmm6
  __m128 v31; // xmm5
  __m128 v32; // xmm7
  bool v33; // r15
  Scaleform::Render::StateBag *v34; // rax
  Scaleform::Render::FilterSet *pData; // rcx
  Scaleform::Render::StateBag *v36; // rax
  unsigned int DataValue; // eax
  int v38; // ecx
  __m128 v39; // xmm1
  Scaleform::Render::TreeCacheRoot *pRoot; // rax
  __m128 v41; // xmm1
  __m128 v42; // xmm0
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  Scaleform::Render::TransformArgs cullRect; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::Render::Matrix3x4<float> m; // [rsp+110h] [rbp+10h] BYREF
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *i; // [rsp+1C8h] [rbp+C8h]

  x1 = t->CullRect.x1;
  y1 = t->CullRect.y1;
  cullRect.viewState = t->viewState;
  projState = t->projState;
  cullRect.CullRect.x1 = x1;
  x2 = t->CullRect.x2;
  cullRect.CullRect.y1 = y1;
  cullRect.projState = projState;
  LOBYTE(projState) = t->bRecomputeViewProj;
  y2 = t->CullRect.y2;
  cullRect.CullRect.x2 = x2;
  v9 = t->ViewProj.M[0][0];
  cullRect.CullRect.y2 = y2;
  *(_QWORD *)&cullRect.ViewProj.M[0][0] = __PAIR64__(LODWORD(t->ViewProj.M[0][1]), LODWORD(v9));
  cullRect.bRecomputeViewProj = (char)projState;
  *(_QWORD *)&cullRect.ViewProj.M[0][2] = *(_QWORD *)&t->ViewProj.M[0][2];
  *(_OWORD *)&cullRect.ViewProj.M[1][0] = *(_OWORD *)&t->ViewProj.M[1][0];
  *(_OWORD *)&cullRect.ViewProj.M[2][0] = *(_OWORD *)&t->ViewProj.M[2][0];
  *(_OWORD *)&cullRect.ViewProj.M[3][0] = *(_OWORD *)&t->ViewProj.M[3][0];
  updated = Scaleform::Render::TreeCacheNode::updateCulling(this, pbaseData, t, &cullRect.CullRect, flags);
  v14 = pbaseData->AproxParentBounds.y2;
  v15 = pbaseData->AproxParentBounds.x2;
  v16 = pbaseData->AproxParentBounds.y1;
  v17 = updated;
  this->SortParentBounds.x1 = pbaseData->AproxParentBounds.x1;
  this->SortParentBounds.y1 = v16;
  this->SortParentBounds.x2 = v15;
  this->SortParentBounds.y2 = v14;
  this->Flags &= ~0x400u;
  pNext = this->Children.Root.pNext;
  p_Children = &this->Children;
  for ( i = &this->Children; ; p_Children = i )
  {
    v20 = p_Children ? (__int64)&p_Children[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::Render::TreeCacheNode *)v20 )
      break;
    UpdateFlags = pNext->UpdateFlags;
    v22 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNext->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                    + 8i64
                    * (unsigned int)((int)(LODWORD(pNext->pNode) - ((__int64)pNext->pNode & 0xFFFFF000) - 56) / 56)
                    + 40) & 0xFFFFFFFFFFFFFFFEui64;
    pNext->UpdateFlags &= 0xFFFFFFFC;
    v23 = v17 | UpdateFlags & 3;
    if ( (*(_WORD *)(v22 + 10) & 0x200) != 0 )
    {
      if ( (v17 & 0x40) != 0 )
      {
        Scaleform::Render::TransformArgs::GetMatrix3D(t, v17, &m);
        v23 &= ~0x40u;
        goto LABEL_16;
      }
      if ( (v17 & 0x80u) != 0 )
      {
        Scaleform::Render::TransformArgs::GetMatrix3D(t, v17, &m);
LABEL_16:
        v30 = *(__m128 *)(v22 + 16);
        v31 = *(__m128 *)(v22 + 32);
        v32 = *(__m128 *)(v22 + 48);
        *(__m128 *)&cullRect.Mat3D.M[0][0] = _mm_add_ps(
                                               _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(*(__m128 *)&m.M[0][0], *(__m128 *)&m.M[0][0], 85),
                                                     v31),
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(*(__m128 *)&m.M[0][0], *(__m128 *)&m.M[0][0], 0),
                                                     v30)),
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(*(__m128 *)&m.M[0][0], *(__m128 *)&m.M[0][0], 170),
                                                   v32)),
                                               _mm_and_ps(
                                                 (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v,
                                                 *(__m128 *)&m.M[0][0]));
        *(__m128 *)&cullRect.Mat3D.M[1][0] = _mm_add_ps(
                                               _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(*(__m128 *)&m.M[1][0], *(__m128 *)&m.M[1][0], 85),
                                                     v31),
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(*(__m128 *)&m.M[1][0], *(__m128 *)&m.M[1][0], 0),
                                                     v30)),
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(*(__m128 *)&m.M[1][0], *(__m128 *)&m.M[1][0], 170),
                                                   v32)),
                                               _mm_and_ps(
                                                 (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v,
                                                 *(__m128 *)&m.M[1][0]));
        *(__m128 *)&cullRect.Mat3D.M[2][0] = _mm_add_ps(
                                               _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(*(__m128 *)&m.M[2][0], *(__m128 *)&m.M[2][0], 85),
                                                     v31),
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(*(__m128 *)&m.M[2][0], *(__m128 *)&m.M[2][0], 0),
                                                     v30)),
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(*(__m128 *)&m.M[2][0], *(__m128 *)&m.M[2][0], 170),
                                                   v32)),
                                               _mm_and_ps(
                                                 (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v,
                                                 *(__m128 *)&m.M[2][0]));
      }
      v27 = v23 | 0x80;
      goto LABEL_18;
    }
    if ( (v17 & 0x40) != 0 )
    {
      v24 = *(__m128 *)(v22 + 16);
      v25 = *(__m128 *)(v22 + 32);
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&t->Mat.M[1][0], *(__m128 *)&t->Mat.M[1][0], 85), v25),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&t->Mat.M[1][0], *(__m128 *)&t->Mat.M[1][0], 0), v24)),
              _mm_and_ps(
                *(__m128 *)&t->Mat.M[1][0],
                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
      *(__m128 *)&cullRect.Mat.M[0][0] = _mm_and_ps(
                                           _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_shuffle_ps(
                                                   *(__m128 *)&t->Mat.M[0][0],
                                                   *(__m128 *)&t->Mat.M[0][0],
                                                   85),
                                                 v25),
                                               _mm_mul_ps(
                                                 _mm_shuffle_ps(
                                                   *(__m128 *)&t->Mat.M[0][0],
                                                   *(__m128 *)&t->Mat.M[0][0],
                                                   0),
                                                 v24)),
                                             _mm_and_ps(
                                               *(__m128 *)&t->Mat.M[0][0],
                                               (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
                                           (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
      *(__m128 *)&cullRect.Mat.M[1][0] = _mm_and_ps(
                                           v26,
                                           (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
    }
    else
    {
      cullRect.Mat = *(Scaleform::Render::Matrix2x4<float> *)(v22 + 16);
    }
    v27 = v23 | 0x40;
    if ( (v17 & 0x80u) != 0 )
    {
      v28 = t->Mat3D.M[0][1];
      cullRect.Mat3D.M[0][0] = t->Mat3D.M[0][0];
      *(_QWORD *)&cullRect.Mat3D.M[0][1] = __PAIR64__(LODWORD(t->Mat3D.M[0][2]), LODWORD(v28));
      v29 = t->Mat3D.M[1][0];
      cullRect.Mat3D.M[0][3] = t->Mat3D.M[0][3];
      *(_QWORD *)&cullRect.Mat3D.M[1][0] = __PAIR64__(LODWORD(t->Mat3D.M[1][1]), LODWORD(v29));
      *(_QWORD *)&cullRect.Mat3D.M[1][2] = *(_QWORD *)&t->Mat3D.M[1][2];
      *(_OWORD *)&cullRect.Mat3D.M[2][0] = *(_OWORD *)&t->Mat3D.M[2][0];
    }
LABEL_18:
    Scaleform::Render::TransformArgs::SetViewProj(&cullRect, (Scaleform::Render::TreeNode::NodeData *)v22, t);
    v33 = 1;
    if ( (pbaseData->Flags & 0x400) != 0 )
    {
      v34 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::FilterState>(pbaseData);
      if ( v34 )
      {
        pData = (Scaleform::Render::FilterSet *)v34->pData;
        if ( pData )
          v33 = Scaleform::Render::FilterSet::IsContributing(pData) == 0;
      }
      v27 |= 0x100u;
    }
    v36 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::BlendState>(pbaseData);
    if ( v36 )
    {
      DataValue = v36->DataValue;
      if ( DataValue <= 0xE )
      {
        v38 = 24804;
        if ( _bittest(&v38, DataValue) )
        {
          v27 |= 0x100u;
          if ( DataValue == 2 )
          {
            v27 |= 0x400u;
          }
          else if ( (v17 & 0x400) == 0 )
          {
            pRoot = this->pRoot;
            if ( pRoot )
              pRoot->EnableBlendTarget = 1;
          }
LABEL_28:
          *(_OWORD *)&cullRect.Cx.M[0][0] = *(_OWORD *)(v22 + 80);
          v39 = *(__m128 *)(v22 + 96);
          goto LABEL_29;
        }
      }
    }
    if ( !v33 )
      goto LABEL_28;
    v41 = *(__m128 *)&t->Cx.M[0][0];
    v42 = _mm_mul_ps(*(__m128 *)(v22 + 80), v41);
    v43 = _mm_mul_ps(*(__m128 *)(v22 + 96), v41);
    v44 = *(__m128 *)&t->Cx.M[1][0];
    *(__m128 *)&cullRect.Cx.M[0][0] = v42;
    v39 = _mm_add_ps(v44, v43);
LABEL_29:
    *(__m128 *)&cullRect.Cx.M[1][0] = v39;
    pNext->vfptr->UpdateTransform(
      pNext,
      (Scaleform::Render::TreeNode::NodeData *)v22,
      &cullRect,
      (Scaleform::Render::TransformFlags)v27);
    pNext = pNext->pNext;
  }
}43);
LABEL_29:
    *(__m128 *)&cullRect.Cx.M[1][0] = v39;
    pNext->vfptr->UpdateTransform(
      pNext,
     

// File Line: 1077
// RVA: 0x9901E0
void __fastcall Scaleform::Render::TreeCacheContainer::HandleChanges(
        Scaleform::Render::TreeCacheContainer *this,
        __int16 changeBits)
{
  Scaleform::Render::TreeCacheNode *pParent; // rcx
  unsigned int v5; // r8d
  __int64 v6; // rdx
  Scaleform::Render::TreeNode *pNode; // rcx
  char v8; // r9
  unsigned __int64 v9; // rdx
  unsigned __int64 v10; // r12
  __int64 v11; // rax
  unsigned __int64 v12; // r13
  Scaleform::Render::TreeCacheNode *pNext; // rbx
  __int64 i; // r14
  unsigned __int64 v15; // rcx
  __int64 v16; // r15
  __int64 v17; // rbp
  Scaleform::Render::TreeCacheContainer *v18; // rdi
  Scaleform::Render::TreeCacheNode *v19; // rdi
  Scaleform::Render::TreeCacheNode *p_x2; // rax
  Scaleform::Render::TreeCacheRoot *pRoot; // rcx
  int v22; // eax
  unsigned __int64 v23; // rcx
  __int64 v24; // rax
  __int64 v25; // rcx
  __int64 v26; // rdx
  int v27; // eax
  Scaleform::Render::TreeCacheNode *p_Children; // rax
  float *v29; // rax
  Scaleform::Render::TreeCacheNode *v30; // rdi
  Scaleform::Render::TreeCacheRoot *v31; // rcx
  int v32; // [rsp+20h] [rbp-38h]

  if ( (changeBits & 0x20) != 0 )
  {
    pParent = this->pParent;
    if ( pParent )
    {
      v5 = pParent->Flags & 0xC;
      if ( v5 == 12 )
      {
        v6 = 12i64;
LABEL_8:
        this->vfptr->propagateEdgeAA(this, (Scaleform::Render::EdgeAAMode)v6);
        goto LABEL_9;
      }
    }
    else
    {
      v5 = 4;
    }
    v6 = *(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                               + 8i64
                               * (unsigned int)((__int64)((__int64)&this->pNode[-1]
                                                        - ((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64))
                                              / 56)
                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                  + 10) & 0xC;
    if ( !(_DWORD)v6 )
      v6 = v5;
    goto LABEL_8;
  }
LABEL_9:
  if ( (changeBits & 0x300) != 0 )
  {
    pNode = this->pNode;
    v8 = 0;
    v9 = (__int64)((unsigned __int128)((__int64)((__int64)&pNode[-1] - ((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64))
                                     * (__int128)0x4924924924924925i64) >> 64) >> 4;
    v10 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                    + 8 * ((unsigned int)v9 + (v9 >> 63))
                    + 40) & 0xFFFFFFFFFFFFFFFEui64;
    v11 = *(_QWORD *)(v10 + 144);
    if ( v11 )
    {
      if ( (v11 & 1) != 0 )
        v12 = *(_QWORD *)((v11 & 0xFFFFFFFFFFFFFFFEui64) + 8);
      else
        v12 = (*(_QWORD *)(v10 + 152) != 0i64) + 1i64;
    }
    else
    {
      v12 = 0i64;
    }
    pNext = this->Children.Root.pNext;
    for ( i = 0i64; (unsigned int)i < v12; i = (unsigned int)(i + 1) )
    {
      if ( (*(_BYTE *)(v10 + 144) & 1) != 0 )
        v15 = (*(_QWORD *)(v10 + 144) & 0xFFFFFFFFFFFFFFFEui64) + 16;
      else
        v15 = v10 + 144;
      v16 = *(_QWORD *)(v15 + 8 * i);
      v17 = *(_QWORD *)(v16 + 24);
      if ( (Scaleform::Render::TreeCacheNode *)v17 == pNext )
      {
        pNext = pNext->pNext;
      }
      else
      {
        if ( !v17 )
          goto LABEL_34;
        v18 = *(Scaleform::Render::TreeCacheContainer **)(v17 + 48);
        if ( v18 != this || !*(_QWORD *)(v17 + 8) )
        {
          if ( v18 )
          {
            Scaleform::Render::TreeCacheNode::RemoveFromParent(*(Scaleform::Render::TreeCacheNode **)(v16 + 24));
            pRoot = v18->pRoot;
            if ( pRoot )
            {
              v22 = 0x1000000;
              if ( (v18->UpdateFlags & 0x80000000) == 0 )
              {
                v18->pNextUpdate = pRoot->pUpdateList;
                pRoot->pUpdateList = v18;
                v22 = -2130706432;
              }
              v18->UpdateFlags |= v22;
            }
          }
LABEL_34:
          v23 = *(_QWORD *)(*(_QWORD *)((v16 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                          + 8i64 * (unsigned int)((int)(v16 - (v16 & 0xFFFFF000) - 56) / 56)
                          + 40) & 0xFFFFFFFFFFFFFFFEui64;
          LOWORD(v32) = this->Depth + 1;
          v24 = (*(__int64 (__fastcall **)(unsigned __int64, Scaleform::Render::TreeCacheContainer *, Scaleform::Render::TreeCacheNode *, __int64, int))(*(_QWORD *)v23 + 48i64))(
                  v23,
                  this,
                  pNext->pPrev,
                  v16,
                  v32);
          v25 = v24;
          if ( v24 )
          {
            v26 = *(_QWORD *)(v24 + 24);
            if ( v26 )
            {
              v27 = 3;
              if ( *(int *)(v25 + 76) >= 0 )
              {
                *(_QWORD *)(v25 + 80) = *(_QWORD *)(v26 + 192);
                *(_QWORD *)(v26 + 192) = v25;
                v27 = -2147483645;
              }
              *(_DWORD *)(v25 + 76) |= v27;
            }
          }
          p_Children = (Scaleform::Render::TreeCacheNode *)&this->Children;
          v8 = 1;
          if ( this != (Scaleform::Render::TreeCacheContainer *)-112i64 )
            p_Children = (Scaleform::Render::TreeCacheContainer *)&this->SortParentBounds.x2;
          if ( pNext != p_Children && pNext->pParent != this )
          {
            pNext = this->Children.Root.pNext;
            LODWORD(i) = -1;
          }
          continue;
        }
        do
        {
          v19 = pNext->pNext;
          Scaleform::Render::TreeCacheNode::RemoveFromParent(pNext);
          pNext = v19;
          if ( v19 == (Scaleform::Render::TreeCacheNode *)v17 )
            break;
          p_x2 = (Scaleform::Render::TreeCacheNode *)&this->Children;
          if ( this != (Scaleform::Render::TreeCacheContainer *)-112i64 )
            p_x2 = (Scaleform::Render::TreeCacheContainer *)&this->SortParentBounds.x2;
        }
        while ( v19 != p_x2 );
        v8 = 1;
        LODWORD(i) = i - 1;
      }
    }
    while ( 1 )
    {
      v29 = this == (Scaleform::Render::TreeCacheContainer *)-112i64 ? 0i64 : &this->SortParentBounds.x2;
      if ( pNext == (Scaleform::Render::TreeCacheNode *)v29 )
        break;
      v30 = pNext->pNext;
      Scaleform::Render::TreeCacheNode::RemoveFromParent(pNext);
      pNext = v30;
      v8 = 1;
    }
    if ( v8 && this->vfptr->IsPatternChainValid(this) )
    {
      v31 = this->pRoot;
      if ( (this->UpdateFlags & 0x80000000) != 0 )
      {
        this->UpdateFlags |= 0x1000000u;
      }
      else
      {
        this->pNextUpdate = v31->pUpdateList;
        v31->pUpdateList = this;
        this->UpdateFlags |= 0x81000000;
      }
    }
  }
}

// File Line: 1183
// RVA: 0x991260
void __fastcall Scaleform::Render::TreeCacheContainer::HandleRemoveNode(Scaleform::Render::TreeCacheContainer *this)
{
  Scaleform::Render::TreeCacheNode *pMask; // rcx
  Scaleform::Render::TreeCacheNode *pNext; // rbx
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // rdi
  __int64 v5; // rax

  this->pRoot = 0i64;
  pMask = this->pMask;
  if ( pMask )
    pMask->vfptr->HandleRemoveNode(pMask);
  this->CachedChildPattern.pLast = 0i64;
  this->CachedChildPattern.pFirst = 0i64;
  this->CachedChildPattern.Length = 0x80000000;
  pNext = this->Children.Root.pNext;
  p_Children = &this->Children;
  while ( 1 )
  {
    v5 = p_Children ? (__int64)&p_Children[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::Render::TreeCacheNode *)v5 )
      break;
    pNext->vfptr->HandleRemoveNode(pNext);
    pNext = pNext->pNext;
  }
}

// File Line: 1201
// RVA: 0x9BD760
void __fastcall Scaleform::Render::TreeCacheContainer::UpdateChildSubtree(
        Scaleform::Render::TreeCacheContainer *this,
        Scaleform::Render::TreeNode::NodeData *pdata,
        unsigned __int16 depth)
{
  Scaleform::Render::TreeNodeArray *v5; // rbx
  Scaleform::Render::TreeCacheNode *pPrev; // r14
  unsigned __int64 i; // rdi
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rcx

  Scaleform::Render::TreeCacheNode::UpdateChildSubtree(this, pdata, depth);
  v5 = (Scaleform::Render::TreeNodeArray *)&pdata[1];
  pPrev = this->Children.Root.pNext->pPrev;
  for ( i = 0i64;
        i < Scaleform::Render::TreeNodeArray::GetSize(v5);
        pPrev = (Scaleform::Render::TreeCacheNode *)(*(__int64 (__fastcall **)(unsigned __int64, Scaleform::Render::TreeCacheContainer *, Scaleform::Render::TreeCacheNode *))(*(_QWORD *)v9 + 48i64))(
                                                      v9,
                                                      this,
                                                      pPrev) )
  {
    if ( ((__int64)v5->pNodes[0] & 1) != 0 )
      v8 = (v5->pData[0] & 0xFFFFFFFFFFFFFFFEui64) + 16;
    else
      v8 = (unsigned __int64)v5;
    v9 = *(_QWORD *)(*(_QWORD *)((*(_QWORD *)(v8 + 8 * i) & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                   + 8i64
                   * (unsigned int)((int)(*(_QWORD *)(v8 + 8 * i) - (*(_QWORD *)(v8 + 8 * i) & 0xFFFFF000) - 56) / 56)
                   + 40) & 0xFFFFFFFFFFFFFFFEui64;
    ++i;
  }
}

// File Line: 1216
// RVA: 0x9EE160
void __fastcall Scaleform::Render::TreeCacheContainer::propagateMaskFlag(
        Scaleform::Render::TreeCacheContainer *this,
        unsigned int partOfMask)
{
  Scaleform::Render::TreeCacheNode *pNext; // rbx
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // rdi
  __int64 v5; // rax

  pNext = this->Children.Root.pNext;
  this->Flags &= ~0x40u;
  this->Flags |= partOfMask;
  p_Children = &this->Children;
  while ( 1 )
  {
    v5 = p_Children ? (__int64)&p_Children[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::Render::TreeCacheNode *)v5 )
      break;
    if ( (pNext->Flags & 0x20) == 0 )
      pNext->vfptr->propagateMaskFlag(pNext, partOfMask);
    pNext = pNext->pNext;
  }
}

// File Line: 1231
// RVA: 0x9EE220
void __fastcall Scaleform::Render::TreeCacheContainer::propagateScale9Flag(
        Scaleform::Render::TreeCacheContainer *this,
        unsigned int partOfScale9)
{
  unsigned __int64 v4; // r9
  unsigned __int64 *v5; // r8
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rdx
  _QWORD *v9; // rcx
  unsigned __int16 Flags; // cx
  Scaleform::Render::TreeCacheNode *pNext; // rbx
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // rdi
  __int64 v13; // rax

  v4 = (unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64;
  v5 = (unsigned __int64 *)((*(_QWORD *)(*(_QWORD *)(v4 + 0x28)
                                       + 8i64 * (unsigned int)((LODWORD(this->pNode) - (int)v4 - 56) / 56)
                                       + 40) & 0xFFFFFFFFFFFFFFFEui64)
                          + 64);
  v6 = *v5;
  if ( *v5 )
  {
    if ( (v6 & 1) != 0 )
    {
      if ( (v6 & 0xFFFFFFFFFFFFFFFEui64) != qword_142451A50 )
        goto LABEL_13;
    }
    else
    {
      v7 = 0i64;
      v4 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                  + 8i64 * (unsigned int)((LODWORD(this->pNode) - (int)v4 - 56) / 56)
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
      partOfScale9 |= 0x80u;
  }
LABEL_13:
  Flags = this->Flags;
  if ( (Flags & 0x80) != partOfScale9 )
  {
    pNext = this->Children.Root.pNext;
    p_Children = &this->Children;
    WORD1(p_Children[-3].Root.pVoidNext) = partOfScale9 | Flags & 0xFF7F;
    while ( 1 )
    {
      v13 = p_Children ? (__int64)&p_Children[-1].Root.8 : 0i64;
      if ( pNext == (Scaleform::Render::TreeCacheNode *)v13 )
        break;
      ((void (__fastcall *)(Scaleform::Render::TreeCacheNode *, _QWORD, unsigned __int64 *, unsigned __int64))pNext->vfptr->propagateScale9Flag)(
        pNext,
        partOfScale9,
        v5,
        v4);
      pNext = pNext->pNext;
    }
  }
}

// File Line: 1249
// RVA: 0x9EDEF0
void __fastcall Scaleform::Render::TreeCacheContainer::propagateEdgeAA(
        Scaleform::Render::TreeCacheContainer *this,
        unsigned int parentEdgeAA)
{
  unsigned int v3; // edi
  unsigned __int16 Flags; // cx
  Scaleform::Render::TreeCacheNode *pNext; // rbx
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // rsi
  __int64 v7; // rax

  if ( parentEdgeAA == 12 )
  {
    v3 = 12;
  }
  else
  {
    v3 = *(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                               + 8i64
                               * (unsigned int)((__int64)((__int64)&this->pNode[-1]
                                                        - ((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64))
                                              / 56)
                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                  + 10) & 0xC;
    if ( !v3 )
      v3 = parentEdgeAA;
  }
  Flags = this->Flags;
  if ( (this->Flags & 0xC) != v3 )
  {
    pNext = this->Children.Root.pNext;
    p_Children = &this->Children;
    WORD1(p_Children[-3].Root.pVoidNext) = v3 | Flags & 0xFFF3;
    while ( 1 )
    {
      v7 = p_Children ? (__int64)&p_Children[-1].Root.8 : 0i64;
      if ( pNext == (Scaleform::Render::TreeCacheNode *)v7 )
        break;
      pNext->vfptr->propagateEdgeAA(pNext, (Scaleform::Render::EdgeAAMode)v3);
      pNext = pNext->pNext;
    }
  }
}

// File Line: 1264
// RVA: 0x9EDD90
void __fastcall Scaleform::Render::TreeCacheContainer::propagate3DFlag(
        Scaleform::Render::TreeCacheContainer *this,
        unsigned int parent3D)
{
  Scaleform::Render::TreeCacheNode *pNext; // rbx
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // rdi
  unsigned int v4; // esi
  __int64 v5; // rax

  if ( parent3D != 512 || (this->Flags & 0x200) == 0 )
  {
    pNext = this->Children.Root.pNext;
    p_Children = &this->Children;
    v4 = this->Flags & 0x200 | parent3D;
    while ( 1 )
    {
      v5 = p_Children ? (__int64)&p_Children[-1].Root.8 : 0i64;
      if ( pNext == (Scaleform::Render::TreeCacheNode *)v5 )
        break;
      pNext->vfptr->propagate3DFlag(pNext, v4);
      pNext = pNext->pNext;
    }
  }
}

// File Line: 1329
// RVA: 0x997280
char __fastcall Scaleform::Render::FixedSizeArrayRect2F::Intersects(
        Scaleform::Render::FixedSizeArrayRect2F *this,
        __m128 *bounds)
{
  unsigned int v3; // eax
  __m128 v4; // xmm2
  __m128 v5; // xmm5
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm6
  __m128 v9; // xmm4
  unsigned __int64 v10; // rcx
  unsigned __int64 Size; // r8
  bool HalfRect; // r10
  Scaleform::Render::Rect2F *pData; // rdx
  __m128 v14; // xmm1

  if ( bounds->m128_f32[2] > bounds->m128_f32[0] && bounds->m128_f32[3] > bounds->m128_f32[1] )
  {
    v3 = _S7_17;
    if ( (_S7_17 & 1) != 0 )
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
    if ( (v3 & 2) != 0 )
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
    if ( (v3 & 4) != 0 )
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
    v8 = _mm_shuffle_ps(v7, v7, 68);
    v9 = _mm_shuffle_ps(v7, v7, 238);
    v10 = 0i64;
    Size = this->Size;
    HalfRect = this->HalfRect;
    if ( HalfRect )
      --Size;
    if ( Size )
    {
      pData = this->pData;
      do
      {
        v14 = _mm_or_ps(_mm_cmple_ps(pData->r1, v8), _mm_cmple_ps(v9, pData->r0));
        if ( (_mm_movemask_ps(_mm_cmpeq_ps(_mm_and_ps(v5, v14), v4)) & 0xF) == 15
          || (_mm_movemask_ps(_mm_cmpeq_ps(_mm_and_ps(v6, v14), v4)) & 0xF) == 15 )
        {
          return 1;
        }
        ++v10;
        ++pData;
      }
      while ( v10 < Size );
    }
    if ( HalfRect
      && (_mm_movemask_ps(
            _mm_cmpeq_ps(
              _mm_and_ps(_mm_or_ps(_mm_cmple_ps(this->pData[v10].r1, v8), _mm_cmple_ps(v9, this->pData[v10].r0)), v5),
              v4)) & 0xF) == 15 )
    {
      return 1;
    }
  }
  return 0;
}

// File Line: 1387
// RVA: 0x95AF90
void __fastcall Scaleform::Render::TreeCacheContainer::BuildChildPattern(
        Scaleform::Render::TreeCacheContainer *this,
        Scaleform::Render::BundleEntryRange *pattern,
        unsigned int flags)
{
  char v6; // r15
  Scaleform::Render::TreeNode *pNode; // rcx
  unsigned __int64 v8; // r8
  __int64 v9; // rcx
  __int64 v10; // rax
  unsigned __int64 *v11; // r8
  unsigned __int64 v12; // rdx
  __int64 v13; // r9
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rdx
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  bool v18; // zf
  int v19; // eax
  Scaleform::Render::TreeCacheNode *pNext; // rsi
  Scaleform::Render::BundleEntry *pFirst; // rdi
  float y2; // xmm13_4
  float x2; // xmm11_4
  float y1; // xmm12_4
  float x1; // xmm10_4
  float *p_x2; // rax
  float v27; // xmm9_4
  float v28; // xmm7_4
  float v29; // xmm8_4
  float v30; // xmm6_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm3_4
  char v34; // al
  __int64 v35; // rcx
  __int64 v36; // rcx
  __int64 v37; // rax
  __m128 *v38; // rax
  Scaleform::Render::Rect<float> v39; // xmm1
  __m128 *v40; // rdx
  float v41; // xmm3_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  __m128 v45; // xmm5
  __m128 v46; // xmm4
  __m128 v47; // xmm2
  __m128 v48; // xmm4
  __m128 v49; // xmm0
  __m128 v50; // xmm2
  __m128 v51; // xmm3
  __m128 v52; // xmm1
  __m128 v53; // xmm4
  __m128 v54; // xmm3
  Scaleform::Render::Rect<float> v55; // xmm4
  Scaleform::Render::Rect<float> v56; // [rsp+20h] [rbp-A8h] BYREF
  Scaleform::Render::Rect<float> v57; // [rsp+30h] [rbp-98h]
  Scaleform::Render::Rect<float> bounds; // [rsp+40h] [rbp-88h] BYREF
  Scaleform::Render::BundleEntryRange other; // [rsp+50h] [rbp-78h] BYREF
  Scaleform::Render::BundleEntryRangeMatcher v60; // [rsp+70h] [rbp-58h] BYREF
  _BYTE v61[984]; // [rsp+E0h] [rbp+18h] BYREF
  __int64 v62; // [rsp+4B8h] [rbp+3F0h]
  __int64 v63; // [rsp+4C0h] [rbp+3F8h]
  _BYTE *v64; // [rsp+4C8h] [rbp+400h]
  char v65; // [rsp+4D0h] [rbp+408h]
  unsigned int mergeDepth; // [rsp+598h] [rbp+4D0h] BYREF
  _BYTE *v67; // [rsp+5A0h] [rbp+4D8h]
  char v68; // [rsp+5A8h] [rbp+4E0h]

  v60.pLastEntries[2] = (Scaleform::Render::BundleEntry *)-2i64;
  v62 = 0i64;
  v63 = 32i64;
  v67 = v61;
  v64 = v61;
  v65 = 0;
  pattern->pLast = 0i64;
  pattern->pFirst = 0i64;
  pattern->Length = 0;
  *(_OWORD *)&v60.pFirst = 0i64;
  bounds.x2 = 0.0;
  v60.pLastEntries[1] = 0i64;
  v6 = 0;
  v57 = 0i64;
  pNode = this->pNode;
  v8 = (unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64;
  v9 = (unsigned int)((int)((_DWORD)pNode - ((unsigned int)pNode & 0xFFFFF000) - 56) / 56);
  v10 = *(_QWORD *)(v8 + 40);
  v11 = (unsigned __int64 *)((*(_QWORD *)(v10 + 8 * v9 + 40) & 0xFFFFFFFFFFFFFFFEui64) + 64);
  v12 = *v11;
  if ( *v11 )
  {
    if ( (v12 & 1) != 0 )
    {
      if ( (v12 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A78 )
      {
LABEL_11:
        if ( v11 )
        {
          v17 = v11[1];
          if ( (*(_BYTE *)(v17 + 32) & 4) == 0 || (v18 = *(_BYTE *)(v17 + 28) == 0, v19 = 1, v18) )
            v19 = 0;
          flags |= v19;
        }
      }
    }
    else
    {
      v13 = *(_QWORD *)((*(_QWORD *)(v10 + 8 * v9 + 40) & 0xFFFFFFFFFFFFFFFEui64) + 72) + 4i64;
      v14 = 0i64;
      v15 = v12 >> 1;
      if ( v15 )
      {
        v16 = (_QWORD *)(v11[1] + 4);
        while ( *v16 != qword_142451A78 )
        {
          ++v14;
          v16 += 2;
          if ( v14 >= v15 )
            goto LABEL_16;
        }
        v11 = (unsigned __int64 *)(v13 + 16 * v14);
        goto LABEL_11;
      }
    }
  }
LABEL_16:
  v68 = flags & 1;
  pNext = this->Children.Root.pNext;
  pFirst = v60.pFirst;
  y2 = v57.y2;
  x2 = v57.x2;
  y1 = v57.y1;
  x1 = v57.x1;
  while ( 1 )
  {
    p_x2 = &this->SortParentBounds.x2;
    if ( this == (Scaleform::Render::TreeCacheContainer *)-112i64 )
      p_x2 = 0i64;
    if ( pNext == (Scaleform::Render::TreeCacheNode *)p_x2 )
      break;
    memset(&other, 0, 20);
    if ( !pNext->vfptr->GetPatternChain(pNext, &other, flags) )
      goto LABEL_96;
    if ( (other.Length & 0x7FFFFFFF) > 8 )
    {
      if ( pFirst )
      {
        if ( pattern->pFirst )
          pattern->pLast->pNextPattern = pFirst;
        else
          pattern->pFirst = pFirst;
        pattern->pLast = v60.pLast;
        pattern->Length += LODWORD(bounds.x2);
      }
      if ( other.pFirst )
      {
        if ( pattern->pFirst )
          pattern->pLast->pNextPattern = other.pFirst;
        else
          pattern->pFirst = other.pFirst;
        pattern->pLast = other.pLast;
        pattern->Length += other.Length;
      }
      v60.pLast = 0i64;
      pFirst = 0i64;
      v60.pFirst = 0i64;
      bounds.x2 = 0.0;
      v62 = 0i64;
      v65 = 0;
      goto LABEL_96;
    }
    v56 = 0i64;
    if ( pNext->pNode )
    {
      v27 = pNext->SortParentBounds.x1;
      v56.x1 = v27;
      v28 = pNext->SortParentBounds.y1;
      v56.y1 = v28;
      v29 = pNext->SortParentBounds.x2;
      v56.x2 = v29;
      v30 = pNext->SortParentBounds.y2;
      v56.y2 = v30;
    }
    else
    {
      v30 = v56.y2;
      v29 = v56.x2;
      v28 = v56.y1;
      v27 = v56.x1;
    }
    if ( (pNext->Flags & 0x410) == 0 )
      goto LABEL_71;
    if ( !pNext->pMask )
      goto LABEL_61;
    bounds = 0i64;
    if ( !Scaleform::Render::TreeCacheNode::calcChildMaskBounds(this, &bounds, pNext) )
      goto LABEL_61;
    if ( v6 )
    {
      x1 = bounds.x1;
      v57.x1 = bounds.x1;
      v31 = bounds.y1;
      y1 = bounds.y1;
      *(_QWORD *)&v57.y1 = *(_QWORD *)&bounds.y1;
      v32 = bounds.x2;
      x2 = bounds.x2;
      v33 = bounds.y2;
    }
    else
    {
      v6 = 1;
      if ( x1 > bounds.x1 )
      {
        x1 = bounds.x1;
        v57.x1 = bounds.x1;
      }
      v32 = bounds.x2;
      if ( x2 <= bounds.x2 )
      {
        x2 = bounds.x2;
        v57.x2 = bounds.x2;
      }
      v31 = bounds.y1;
      if ( y1 > bounds.y1 )
      {
        y1 = bounds.y1;
        v57.y1 = bounds.y1;
      }
      v33 = bounds.y2;
      if ( y2 > bounds.y2 )
        goto LABEL_49;
    }
    y2 = v33;
    v57.y2 = v33;
LABEL_49:
    if ( v27 >= v29 || v28 >= v30 )
    {
      v27 = bounds.x1;
      v56.x1 = bounds.x1;
      v28 = v31;
      v56.y1 = v31;
      v29 = v32;
      v56.x2 = v32;
    }
    else
    {
      if ( v27 > bounds.x1 )
      {
        v27 = bounds.x1;
        v56.x1 = bounds.x1;
      }
      if ( v29 <= v32 )
      {
        v29 = v32;
        v56.x2 = v32;
      }
      if ( v28 > v31 )
      {
        v28 = v31;
        v56.y1 = v31;
      }
      if ( v30 > v33 )
        goto LABEL_61;
    }
    v30 = v33;
    v56.y2 = v33;
LABEL_61:
    if ( v6 )
    {
      x1 = v27;
      *(_QWORD *)&v57.x1 = __PAIR64__(LODWORD(v28), LODWORD(v27));
      y1 = v28;
      x2 = v29;
      v57.x2 = v29;
LABEL_70:
      y2 = v30;
      v57.y2 = v30;
      goto LABEL_71;
    }
    v6 = 1;
    if ( x1 > v27 )
    {
      x1 = v27;
      v57.x1 = v27;
    }
    if ( x2 <= v29 )
    {
      x2 = v29;
      v57.x2 = v29;
    }
    if ( y1 > v28 )
    {
      y1 = v28;
      v57.y1 = v28;
    }
    if ( y2 <= v30 )
      goto LABEL_70;
LABEL_71:
    if ( pFirst )
    {
      if ( !v68 && (pNext->Flags & 0x200) == 0 )
      {
        if ( Scaleform::Render::FixedSizeArrayRect2F::Intersects(
               (Scaleform::Render::FixedSizeArrayRect2F *)&v60.pLastEntries[4],
               &v56) )
        {
          if ( (LODWORD(bounds.x2) & 0x7FFFFFFF) == 1
            && (other.Length & 0x7FFFFFFF) == 1
            && Scaleform::Render::SortKey::MatchSingleItemOverlap(&pFirst->Key, &other.pFirst->Key) )
          {
LABEL_80:
            mergeDepth = this->Depth;
            Scaleform::Render::BundleEntryRangeMatcher::Match(&v60, &other, &mergeDepth);
            v34 = v65;
            v35 = v62;
            v30 = v56.y2;
            v29 = v56.x2;
            v28 = v56.y1;
            v27 = v56.x1;
            goto LABEL_88;
          }
        }
        else
        {
          if ( Scaleform::Render::BundleEntryRangeMatcher::Match(&v60, &other, 0i64) )
            goto LABEL_80;
          pFirst = v60.pFirst;
        }
        v27 = v56.x1;
        v28 = v56.y1;
        v29 = v56.x2;
        v30 = v56.y2;
      }
      if ( pFirst )
      {
        if ( pattern->pFirst )
          pattern->pLast->pNextPattern = pFirst;
        else
          pattern->pFirst = pFirst;
        pattern->pLast = v60.pLast;
        pattern->Length += LODWORD(bounds.x2);
      }
    }
    *(_OWORD *)&v60.pFirst = *(_OWORD *)&other.pFirst;
    *(_QWORD *)&bounds.x2 = *(_QWORD *)&other.Length;
    v60.pLastEntries[1] = 0i64;
    v35 = 0i64;
    v62 = 0i64;
    v34 = 0;
    v65 = 0;
LABEL_88:
    if ( v27 >= v29 || v28 >= v30 )
      goto LABEL_92;
    if ( v34 )
    {
      v36 = 32 * v35;
      v37 = (__int64)v64;
      *(__m128 *)&v64[v36 - 32] = _mm_shuffle_ps(*(__m128 *)&v64[v36 - 32], (__m128)v56, 68);
      *(__m128 *)(v36 + v37 - 16) = _mm_shuffle_ps(*(__m128 *)(v36 + v37 - 16), (__m128)v56, 228);
      v65 = 0;
LABEL_92:
      pFirst = v60.pFirst;
      goto LABEL_96;
    }
    if ( v35 == v63 )
    {
      Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F>::grow(
        (Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F> *)&v60.pLastEntries[4],
        2 * v35);
      v35 = v62;
    }
    v38 = (__m128 *)&v64[32 * v35];
    v62 = v35 + 1;
    v39 = v56;
    *v38 = _mm_shuffle_ps((__m128)v56, *v38, 228);
    v38[1] = _mm_shuffle_ps((__m128)v39, v38[1], 238);
    v65 = 1;
    pFirst = v60.pFirst;
LABEL_96:
    pNext = pNext->pNext;
  }
  if ( pFirst )
  {
    if ( pattern->pFirst )
      pattern->pLast->pNextPattern = pFirst;
    else
      pattern->pFirst = pFirst;
    pattern->pLast = v60.pLast;
    pattern->Length += LODWORD(bounds.x2);
  }
  if ( v6 )
  {
    v40 = (__m128 *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                               + 8i64
                               * (unsigned int)((int)(LODWORD(this->pNode) - ((__int64)this->pNode & 0xFFFFF000) - 56)
                                              / 56)
                               + 40) & 0xFFFFFFFFFFFFFFFEui64);
    v41 = v40[7].m128_f32[0];
    v42 = v40[7].m128_f32[2];
    if ( v41 < v42 )
    {
      v43 = v40[7].m128_f32[1];
      v44 = v40[7].m128_f32[3];
      if ( v43 < v44 )
      {
        if ( x1 > v41 )
          LODWORD(v57.x1) = v40[7].m128_i32[0];
        if ( x2 <= v42 )
          v57.x2 = v42;
        if ( y1 > v43 )
          v57.y1 = v43;
        if ( y2 <= v44 )
          v57.y2 = v44;
      }
    }
    v45 = _mm_shuffle_ps(v40[1], v40[2], 255);
    v46 = _mm_unpacklo_ps(v40[1], v40[2]);
    v47 = _mm_mul_ps(v46, _mm_unpacklo_ps((__m128)v57, (__m128)v57));
    v48 = _mm_mul_ps(v46, _mm_unpackhi_ps((__m128)v57, (__m128)v57));
    v49 = _mm_unpacklo_ps(v47, v48);
    v50 = _mm_unpackhi_ps(v47, v48);
    v51 = _mm_add_ps(v50, v49);
    v52 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 177), v50);
    v53 = _mm_min_ps(v51, v52);
    v54 = _mm_max_ps(v51, v52);
    v55 = (Scaleform::Render::Rect<float>)_mm_add_ps(
                                            _mm_shuffle_ps(
                                              _mm_min_ps(v53, _mm_shuffle_ps(v53, v53, 177)),
                                              _mm_max_ps(v54, _mm_shuffle_ps(v54, v54, 177)),
                                              136),
                                            _mm_shuffle_ps(v45, v45, 136));
    v57 = v55;
    if ( v55.x1 != this->SortParentBounds.x1
      || v55.x2 != this->SortParentBounds.x2
      || v55.y1 != this->SortParentBounds.y1
      || v55.y2 != this->SortParentBounds.y2 )
    {
      this->SortParentBounds = v55;
      this->Flags |= 0x400u;
    }
  }
  ++BuildPatternCount;
  v62 = 0i64;
  if ( v64 != v67 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
} this->SortParentBounds.x1
      || v55.x2 != this->SortParentBounds.x2
      || v55.y1 != this->SortParentBounds.y1
      || v55.y2 != this->SortParentBounds.y2 )
    {
      this->SortParentBounds = v55;
      this->Flags |= 0x400u;
    }
  }
  ++BuildPatternCount;
  v62

// File Line: 1590
// RVA: 0x9BD4E0
void __fastcall Scaleform::Render::TreeCacheContainer::UpdateBundlePattern(
        Scaleform::Render::TreeCacheContainer *this,
        unsigned int flags)
{
  __int64 v4; // rbp
  Scaleform::Render::BundleEntry *pLast; // rsi
  Scaleform::Render::BundleEntry *pFirst; // rdi
  unsigned __int16 v7; // cx
  unsigned int v8; // eax
  Scaleform::Render::TreeCacheNode *pParent; // rcx
  Scaleform::Render::TreeCacheNode *v10; // rdx
  Scaleform::Render::TreeCacheRoot *pRoot; // rcx
  Scaleform::Render::BundleEntryRange pattern; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::Render::BundleEntryRange contentChain; // [rsp+38h] [rbp-20h] BYREF

  if ( this->vfptr->IsPatternChainValid(this) )
  {
    pattern.Length = 0x80000000;
    pattern.pFirst = 0i64;
    pattern.pLast = 0i64;
    Scaleform::Render::TreeCacheContainer::BuildChildPattern(this, &pattern, flags);
    v4 = *(_QWORD *)&pattern.Length;
    pLast = pattern.pLast;
    pFirst = pattern.pFirst;
    if ( this->Effects.pEffect && pattern.pFirst )
    {
      contentChain = pattern;
      Scaleform::Render::TreeCacheNode::updateEffectChain(this, &contentChain);
    }
    v7 = this->Flags;
    if ( (v7 & 3) != 1 && (v7 & 0x40) == 0 )
      goto LABEL_21;
    v8 = this->CachedChildPattern.Length & 0x7FFFFFFF;
    if ( v8 > 8
      && (pattern.Length & 0x7FFFFFFF) > 8
      && this->CachedChildPattern.pFirst == pFirst
      && this->CachedChildPattern.pLast == pLast )
    {
      if ( v8 == (pattern.Length & 0x7FFFFFFF) )
        goto LABEL_21;
      pParent = this->pParent;
      if ( !pParent )
        goto LABEL_21;
      if ( !pParent->vfptr->IsPatternChainValid(pParent) )
        goto LABEL_21;
      v10 = this->pParent;
      if ( (v10->UpdateFlags & 0x3000000) != 0 )
        goto LABEL_21;
      pRoot = this->pRoot;
      if ( !pRoot )
        goto LABEL_21;
    }
    else
    {
      pRoot = this->pRoot;
      if ( !pRoot )
      {
LABEL_21:
        this->CachedChildPattern.pFirst = pFirst;
        this->CachedChildPattern.pLast = pLast;
        *(_QWORD *)&this->CachedChildPattern.Length = v4;
        return;
      }
      v10 = this->pParent;
    }
    if ( v10 )
      Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(pRoot, v10, 0x1000000u);
    goto LABEL_21;
  }
}

// File Line: 1650
// RVA: 0x98A570
_BOOL8 __fastcall Scaleform::Render::TreeCacheContainer::GetPatternChain(
        Scaleform::Render::TreeCacheContainer *this,
        Scaleform::Render::BundleEntryRange *range,
        __int64 flags)
{
  unsigned __int16 v4; // cx
  _BOOL8 result; // rax
  unsigned int v7; // ebp
  Scaleform::Render::CacheEffect *pEffect; // rcx
  Scaleform::Render::BundleEntryRange *p_CachedChildPattern; // rsi

  v4 = this->Flags;
  if ( (v4 & 3) != 1 && (v4 & 0x40) == 0 )
  {
    result = 0i64;
    range->pLast = 0i64;
    range->pFirst = 0i64;
    range->Length = 0;
    return result;
  }
  v7 = this->UpdateFlags & 0x7E0000;
  if ( this->CachedChildPattern.Length == 0x80000000 )
  {
    p_CachedChildPattern = &this->CachedChildPattern;
    Scaleform::Render::TreeCacheContainer::BuildChildPattern(this, &this->CachedChildPattern, flags);
    goto LABEL_12;
  }
  if ( v7 )
  {
    p_CachedChildPattern = &this->CachedChildPattern;
    Scaleform::Render::BundleEntryRange::StripChainsByDepth(&this->CachedChildPattern, this->Depth);
LABEL_12:
    range->pFirst = p_CachedChildPattern->pFirst;
    range->pLast = p_CachedChildPattern->pLast;
    *(_QWORD *)&range->Length = *(_QWORD *)&p_CachedChildPattern->Length;
    if ( v7 )
    {
      Scaleform::Render::CacheEffectChain::UpdateEffects(&this->Effects, this, v7);
      this->UpdateFlags &= 0xFF81FFFF;
    }
    if ( p_CachedChildPattern->pFirst )
      Scaleform::Render::TreeCacheNode::updateEffectChain(this, range);
    return (range->Length & 0x7FFFFFFF) != 0;
  }
  if ( this->CachedChildPattern.pFirst )
  {
    pEffect = this->Effects.pEffect;
    if ( pEffect )
    {
      ((void (__fastcall *)(Scaleform::Render::CacheEffect *, Scaleform::Render::BundleEntryRange *, __int64))pEffect->vfptr->GetRange)(
        pEffect,
        range,
        flags);
      Scaleform::Render::BundleEntryRange::StripChainsByDepth(range, this->Depth);
    }
    else
    {
      *range = this->CachedChildPattern;
      Scaleform::Render::BundleEntryRange::StripChainsByDepth(range, this->Depth);
    }
  }
  return (range->Length & 0x7FFFFFFF) != 0;
}

// File Line: 1692
// RVA: 0x997C30
bool __fastcall Scaleform::Render::TreeCacheContainer::IsPatternChainValid(Scaleform::Render::TreeCacheContainer *this)
{
  return this->CachedChildPattern.Length != 0x80000000;
}

// File Line: 1697
// RVA: 0x9E3300
void __fastcall Scaleform::Render::TreeCacheContainer::forceUpdateImages(Scaleform::Render::TreeCacheContainer *this)
{
  Scaleform::Render::TreeCacheNode *pNext; // rbx
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // rdi
  __int64 v3; // rax

  pNext = this->Children.Root.pNext;
  p_Children = &this->Children;
  while ( 1 )
  {
    v3 = p_Children ? (__int64)&p_Children[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::Render::TreeCacheNode *)v3 )
      break;
    pNext->vfptr->forceUpdateImages(pNext);
    pNext = pNext->pNext;
  }
}

// File Line: 1710
// RVA: 0x95E0E0
void __fastcall Scaleform::Render::TreeCacheRoot::ChainUpdatesByDepth(Scaleform::Render::TreeCacheRoot *this)
{
  Scaleform::Render::TreeCacheNode *pUpdateList; // rbx
  Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *p_DepthUpdates; // rdi
  __int64 Depth; // rsi
  Scaleform::Render::TreeCacheNode *pNextUpdate; // rbp
  __int64 v6; // rdx
  unsigned int v7; // esi

  pUpdateList = this->pUpdateList;
  this->pUpdateList = 0i64;
  if ( pUpdateList )
  {
    p_DepthUpdates = &this->DepthUpdates;
    do
    {
      Depth = pUpdateList->Depth;
      pNextUpdate = pUpdateList->pNextUpdate;
      if ( (unsigned int)Depth < p_DepthUpdates->DepthAvailable
        || Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(p_DepthUpdates, Depth + 1) )
      {
        v6 = Depth;
        v7 = Depth + 1;
        pUpdateList->pNextUpdate = p_DepthUpdates->pDepth[v6];
        p_DepthUpdates->pDepth[v6] = pUpdateList;
        if ( p_DepthUpdates->DepthUsed < v7 )
          p_DepthUpdates->DepthUsed = v7;
      }
      pUpdateList = pNextUpdate;
    }
    while ( pNextUpdate );
    this->DepthUpdatesChained = 1;
  }
  else
  {
    this->DepthUpdatesChained = 1;
  }
}

// File Line: 1738
// RVA: 0x954B60
void __fastcall Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(
        Scaleform::Render::TreeCacheRoot *this,
        Scaleform::Render::TreeCacheNode *pnode,
        unsigned int flags)
{
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
    pnode->UpdateFlags |= flags | 0x80000000;
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
void __fastcall Scaleform::Render::TreeCacheRoot::HandleChanges(
        Scaleform::Render::TreeCacheRoot *this,
        __int16 changeBits)
{
  Scaleform::Render::TreeNode *pNode; // r9

  if ( (changeBits & 0x1000) != 0 )
  {
    pNode = this->pNode;
    if ( (*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                    + 8i64 * (unsigned int)((int)((_DWORD)pNode - ((unsigned int)pNode & 0xFFFFF000) - 56) / 56)
                    + 40) & 0xFFFFFFFFFFFFFFFEui64) != 0 )
      this->ViewValid = Scaleform::Render::Viewport::GetCullRectF(
                          (Scaleform::Render::Viewport *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64)
                                                                                 + 0x28)
                                                                     + 8i64
                                                                     * (unsigned int)((int)((_DWORD)pNode
                                                                                          - ((unsigned int)pNode & 0xFFFFF000)
                                                                                          - 56)
                                                                                    / 56)
                                                                     + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                                        + 160),
                          &this->ViewCullRect,
                          0);
  }
  Scaleform::Render::TreeCacheContainer::HandleChanges(this, changeBits & 0xEFFF);
}

// File Line: 1799
// RVA: 0x9C0700
void __fastcall Scaleform::Render::TreeCacheRoot::UpdateTreeData(Scaleform::Render::TreeCacheRoot *this)
{
  Scaleform::Render::TreeCacheRoot *v1; // r13
  unsigned int v2; // edx
  __int64 v3; // rcx
  int v4; // edi
  __int64 v5; // r15
  int v6; // ebx
  __int64 v7; // rax
  __int64 v8; // rdx
  __int16 v9; // ax
  __int64 v10; // r14
  unsigned __int64 v11; // rsi
  __int64 v12; // rdi
  unsigned __int64 v13; // r8
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // r8
  _QWORD *v16; // rdx
  __int64 v17; // rdi
  unsigned int v18; // ebx
  __int64 v19; // rcx
  __int64 v20; // rcx
  __int64 v21; // rax
  unsigned __int64 v22; // r8
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // r8
  _QWORD *v25; // rdx
  unsigned int v26; // ecx
  __m128 *v27; // rsi
  int v28; // r12d
  char v29; // r14
  bool v30; // r10
  __m128 *v31; // rax
  __m128 *v32; // rcx
  float y2; // xmm3_4
  float x2; // xmm2_4
  float y1; // xmm1_4
  __int16 v36; // r11
  unsigned __int64 v37; // r8
  unsigned __int64 v38; // rdx
  unsigned __int64 v39; // r8
  _QWORD *v40; // rcx
  unsigned __int64 v41; // r9
  unsigned __int64 v42; // rcx
  unsigned __int64 v43; // r9
  _QWORD *v44; // r8
  int v45; // eax
  unsigned int v46; // r12d
  __int16 v47; // r9
  unsigned __int64 v48; // rdx
  unsigned __int64 v49; // rdi
  unsigned __int64 v50; // rdx
  _QWORD *v51; // rcx
  unsigned __int64 v52; // rdx
  unsigned __int64 v53; // rbx
  unsigned __int64 v54; // rdx
  _QWORD *v55; // rcx
  __int64 v56; // r13
  __int16 v57; // cx
  __m128 *v58; // rsi
  __m128 *v59; // rax
  __m128 v60; // xmm13
  __m128 v61; // xmm12
  __m128 v62; // xmm12
  __m128 v63; // xmm11
  __m128 v64; // xmm0
  char v65; // r14
  __int64 v66; // r15
  unsigned __int64 v67; // r8
  unsigned __int64 v68; // rcx
  unsigned __int64 v69; // r8
  _QWORD *v70; // rdx
  __int64 v71; // r15
  unsigned int v72; // r14d
  __int64 v73; // rcx
  __int64 v74; // rcx
  __int64 v75; // rcx
  __int64 v76; // r14
  int v77; // eax
  unsigned int v78; // r8d
  __int64 v79; // r15
  unsigned int v80; // r8d
  __m128 *v81; // r14
  unsigned __int64 v82; // r8
  __int64 v83; // rax
  unsigned __int64 v84; // rcx
  unsigned __int64 v85; // r8
  _QWORD *v86; // rdx
  unsigned int v87; // ecx
  int v88; // edx
  __int64 v89; // rcx
  __int64 v90; // r15
  int v91; // edx
  unsigned int v92; // r8d
  __int64 v93; // r12
  unsigned int v94; // r8d
  __m128 v95; // xmm3
  unsigned __int64 v96; // rdx
  unsigned __int64 v97; // rdx
  _QWORD *v98; // rcx
  unsigned __int64 v99; // rdx
  unsigned __int64 v100; // rdx
  _QWORD *v101; // rcx
  __int64 v102; // rdi
  Scaleform::Render::TreeCacheNode *i; // rbx
  __int64 j; // r8
  __int64 pLast; // rax
  Scaleform::Render::BundleEntry *pFirst; // rbx
  Scaleform::Render::Bundle *pObject; // rax
  Scaleform::Render::Bundle *v108; // rdi
  unsigned int DepthUsed; // [rsp+30h] [rbp-90h]
  unsigned int v111; // [rsp+34h] [rbp-8Ch]
  __int128 v112; // [rsp+40h] [rbp-80h] BYREF
  __m128 v113; // [rsp+50h] [rbp-70h]
  __m128 v114; // [rsp+60h] [rbp-60h]
  __m128 v115; // [rsp+70h] [rbp-50h]
  char v116; // [rsp+90h] [rbp-30h]
  __m128 v117; // [rsp+A0h] [rbp-20h]
  __m128 v118; // [rsp+B0h] [rbp-10h]
  __m128 v119; // [rsp+C0h] [rbp+0h]
  __m128 v120; // [rsp+D0h] [rbp+10h]
  __int64 v121; // [rsp+E0h] [rbp+20h]
  Scaleform::Render::BundleEntry **p_pNextPattern; // [rsp+E8h] [rbp+28h] BYREF
  Scaleform::Render::BundleEntry **k; // [rsp+F0h] [rbp+30h]
  __int64 v124; // [rsp+F8h] [rbp+38h]
  __int64 v125; // [rsp+100h] [rbp+40h]
  __m128 v126; // [rsp+110h] [rbp+50h]
  __m128 v127; // [rsp+120h] [rbp+60h]
  __m128 v128; // [rsp+130h] [rbp+70h]
  __m128 v129; // [rsp+140h] [rbp+80h]
  __m128 v130; // [rsp+150h] [rbp+90h]
  __m128 v131; // [rsp+160h] [rbp+A0h]
  __m128 *v132; // [rsp+170h] [rbp+B0h]
  int v133[8]; // [rsp+180h] [rbp+C0h] BYREF
  __m128 v134; // [rsp+1A0h] [rbp+E0h]
  __int64 v135; // [rsp+1B0h] [rbp+F0h]
  Scaleform::Render::TreeCacheRoot *v136; // [rsp+2A0h] [rbp+1E0h]
  char v137; // [rsp+2A8h] [rbp+1E8h]
  unsigned int v138; // [rsp+2B0h] [rbp+1F0h]
  unsigned int v139; // [rsp+2B8h] [rbp+1F8h]

  v135 = -2i64;
  v1 = this;
  DepthUsed = this->DepthUpdates.DepthUsed;
  v2 = 0;
  v139 = 0;
  v3 = 0i64;
  v121 = 0i64;
  if ( !DepthUsed )
    goto LABEL_227;
  v4 = 24804;
  do
  {
    v5 = (__int64)v1->DepthUpdates.pDepth[v3];
    v125 = v5;
    if ( !v5 )
      goto LABEL_226;
    do
    {
      v6 = *(_DWORD *)(v5 + 76) & 3;
      if ( (*(_DWORD *)(v5 + 76) & 0x10000) != 0 )
      {
        v7 = *(_QWORD *)(v5 + 48);
        if ( v7 )
          v8 = *(_WORD *)(v7 + 74) & 0x80;
        else
          v8 = 0i64;
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)v5 + 48i64))(v5, v8, 128i64, 65023i64);
        *(_DWORD *)(v5 + 76) &= ~0x10000u;
        v6 |= 1u;
      }
      if ( (*(_DWORD *)(v5 + 76) & 0x2000) != 0 )
      {
        v9 = ((*(_WORD *)((*(_QWORD *)(*(_QWORD *)((*(_QWORD *)(v5 + 32) & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                     + 8i64
                                     * (unsigned int)((int)(*(_DWORD *)(v5 + 32)
                                                          - (*(_DWORD *)(v5 + 32) & 0xFFFFF000)
                                                          - 56)
                                                    / 56)
                                     + 40) & 0xFFFFFFFFFFFFFFFEui64)
                        + 10) >> 9) & 1) << 9;
        *(_WORD *)(v5 + 74) &= ~0x200u;
        *(_WORD *)(v5 + 74) |= v9;
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v5 + 64i64))(v5, 0i64);
        *(_DWORD *)(v5 + 76) &= ~0x2000u;
        v6 |= 1u;
      }
      if ( v6 )
        goto LABEL_49;
      v10 = v5;
      while ( 1 )
      {
        v11 = *(_QWORD *)(*(_QWORD *)((*(_QWORD *)(v10 + 32) & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                        + 8i64
                        * (unsigned int)((int)(*(_DWORD *)(v10 + 32) - (*(_DWORD *)(v10 + 32) & 0xFFFFF000) - 56) / 56)
                        + 40) & 0xFFFFFFFFFFFFFFFEui64;
        if ( (*(_WORD *)(v11 + 10) & 0x400) == 0 )
          goto LABEL_33;
        v12 = v11 + 64;
        v13 = *(_QWORD *)(v11 + 64);
        if ( !v13 )
          goto LABEL_32;
        if ( (v13 & 1) == 0 )
          break;
        if ( (v13 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A58 )
          goto LABEL_24;
LABEL_32:
        v4 = 24804;
LABEL_33:
        v21 = v11 + 64;
        v22 = *(_QWORD *)(v11 + 64);
        if ( v22 )
        {
          if ( (v22 & 1) != 0 )
          {
            if ( (v22 & 0xFFFFFFFFFFFFFFFEui64) != qword_142451A48 )
              goto LABEL_46;
          }
          else
          {
            v23 = 0i64;
            v24 = v22 >> 1;
            if ( !v24 )
              goto LABEL_46;
            v25 = (_QWORD *)(*(_QWORD *)(v11 + 72) + 4i64);
            while ( *v25 != qword_142451A48 )
            {
              ++v23;
              v25 += 2;
              if ( v23 >= v24 )
                goto LABEL_46;
            }
            v21 = *(_QWORD *)(v11 + 72) + 4i64 + 16 * v23;
          }
          if ( v21 )
          {
            v26 = *(_DWORD *)(v21 + 8);
            if ( v26 <= 0xE )
            {
              if ( _bittest(&v4, v26) )
                goto LABEL_48;
            }
          }
        }
LABEL_46:
        v10 = *(_QWORD *)(v10 + 48);
        if ( !v10 )
          goto LABEL_224;
      }
      v14 = 0i64;
      v15 = v13 >> 1;
      if ( !v15 )
        goto LABEL_32;
      v16 = (_QWORD *)(*(_QWORD *)(v11 + 72) + 4i64);
      while ( *v16 != qword_142451A58 )
      {
        ++v14;
        v16 += 2;
        if ( v14 >= v15 )
          goto LABEL_32;
      }
      v12 = *(_QWORD *)(v11 + 72) + 4i64 + 16 * v14;
LABEL_24:
      if ( !v12 )
        goto LABEL_32;
      v17 = *(_QWORD *)(v12 + 8);
      if ( !v17 )
        goto LABEL_32;
      if ( *(_BYTE *)(v17 + 41) )
        goto LABEL_48;
      v18 = 0;
      if ( !*(_QWORD *)(v17 + 24) )
        goto LABEL_32;
      v19 = 0i64;
      while ( 1 )
      {
        v20 = *(_QWORD *)(*(_QWORD *)(v17 + 16) + 8 * v19);
        if ( v20 )
        {
          if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v20 + 16i64))(v20) )
            break;
        }
        v19 = ++v18;
        if ( (unsigned __int64)v18 >= *(_QWORD *)(v17 + 24) )
          goto LABEL_32;
      }
LABEL_48:
      v6 = 512;
LABEL_49:
      v27 = (__m128 *)(*(_QWORD *)(*(_QWORD *)((*(_QWORD *)(v5 + 32) & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                 + 8i64
                                 * (unsigned int)((int)(*(_DWORD *)(v5 + 32) - (*(_DWORD *)(v5 + 32) & 0xFFFFF000) - 56)
                                                / 56)
                                 + 40) & 0xFFFFFFFFFFFFFFFEui64);
      v132 = v27;
      v28 = v6 | (v1->ViewValid ? 0x10 : 0);
      v29 = v6 != 0;
      v30 = (v27->m128_i16[5] & 0x200) != 0;
      if ( (v27->m128_i16[5] & 0x200) != 0 )
      {
        v31 = v27 + 1;
        v32 = (__m128 *)&Scaleform::Render::Matrix2x4<float>::Identity;
      }
      else
      {
        v31 = (__m128 *)&Scaleform::Render::Matrix3x4<float>::Identity;
        v32 = v27 + 1;
      }
      y2 = v1->ViewCullRect.y2;
      x2 = v1->ViewCullRect.x2;
      y1 = v1->ViewCullRect.y1;
      *(float *)&v112 = v1->ViewCullRect.x1;
      *(_QWORD *)((char *)&v112 + 4) = __PAIR64__(LODWORD(x2), LODWORD(y1));
      *((float *)&v112 + 3) = y2;
      v113 = *v31;
      v114 = v31[1];
      v115 = v31[2];
      v112 = 0i64;
      v116 = 0;
      v117 = *v32;
      v118 = v32[1];
      v119 = v27[5];
      v120 = v27[6];
      v36 = v27->m128_i16[5];
      if ( (v36 & 0x800) == 0 )
        goto LABEL_64;
      v37 = v27[4].m128_u64[0];
      if ( !v37 )
        goto LABEL_64;
      v38 = 0i64;
      if ( (v37 & 1) != 0 )
      {
        if ( (v37 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A68 )
          v38 = (unsigned __int64)&v27[4];
        goto LABEL_65;
      }
      v39 = v37 >> 1;
      if ( !v39 )
      {
LABEL_64:
        v38 = 0i64;
        goto LABEL_65;
      }
      v40 = (_QWORD *)(v27[4].m128_u64[1] + 4);
      while ( *v40 != qword_142451A68 )
      {
        ++v38;
        v40 += 2;
        if ( v38 >= v39 )
          goto LABEL_64;
      }
      v38 = v27[4].m128_u64[1] + 4 + 16 * v38;
LABEL_65:
      if ( (v36 & 0x1000) == 0 )
        goto LABEL_77;
      v41 = v27[4].m128_u64[0];
      if ( !v41 )
        goto LABEL_77;
      v42 = 0i64;
      if ( (v41 & 1) != 0 )
      {
        if ( (v41 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A70 )
          v42 = (unsigned __int64)&v27[4];
        goto LABEL_78;
      }
      v43 = v41 >> 1;
      if ( !v43 )
      {
LABEL_77:
        v42 = 0i64;
        goto LABEL_78;
      }
      v44 = (_QWORD *)(v27[4].m128_u64[1] + 4);
      while ( *v44 != qword_142451A70 )
      {
        ++v42;
        v44 += 2;
        if ( v42 >= v43 )
          goto LABEL_77;
      }
      v42 = v27[4].m128_u64[1] + 4 + 16 * v42;
LABEL_78:
      if ( v38 )
      {
        *(_QWORD *)&v112 = v38;
        v116 = 1;
      }
      if ( v42 )
      {
        *((_QWORD *)&v112 + 1) = v42;
        v116 = 1;
      }
      v45 = 64;
      if ( v30 )
        v45 = 128;
      v46 = v45 | v28;
      v138 = v46;
      v47 = v27->m128_i16[5];
      if ( (v47 & 0x800) == 0 )
        goto LABEL_96;
      v48 = v27[4].m128_u64[0];
      if ( !v48 )
        goto LABEL_96;
      v49 = 0i64;
      if ( (v48 & 1) != 0 )
      {
        if ( (v48 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A68 )
          v49 = (unsigned __int64)&v27[4];
        goto LABEL_97;
      }
      v50 = v48 >> 1;
      if ( !v50 )
      {
LABEL_96:
        v49 = 0i64;
        goto LABEL_97;
      }
      v51 = (_QWORD *)(v27[4].m128_u64[1] + 4);
      while ( *v51 != qword_142451A68 )
      {
        ++v49;
        v51 += 2;
        if ( v49 >= v50 )
          goto LABEL_96;
      }
      v49 = v27[4].m128_u64[1] + 4 + 16 * v49;
      if ( (v47 & 0x1000) == 0 )
        goto LABEL_109;
      v52 = v27[4].m128_u64[0];
      if ( !v52 )
        goto LABEL_109;
LABEL_97:
      v53 = 0i64;
      if ( (v52 & 1) != 0 )
      {
        if ( (v52 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A70 )
          v53 = (unsigned __int64)&v27[4];
        goto LABEL_110;
      }
      v54 = v52 >> 1;
      if ( v54 )
      {
        v55 = (_QWORD *)(v27[4].m128_u64[1] + 4);
        while ( *v55 != qword_142451A70 )
        {
          ++v53;
          v55 += 2;
          if ( v53 >= v54 )
            goto LABEL_109;
        }
        v53 = v27[4].m128_u64[1] + 4 + 16 * v53;
      }
      else
      {
LABEL_109:
        v53 = 0i64;
      }
LABEL_110:
      v56 = *(_QWORD *)(v5 + 48);
      if ( !v56 )
        goto LABEL_219;
      while ( 2 )
      {
        v57 = *(_WORD *)(v56 + 74);
        if ( (v57 & 3) != 1 && (v57 & 0x40) == 0 )
        {
          v46 &= ~0x10u;
          v138 = v46;
        }
        v58 = (__m128 *)(*(_QWORD *)(*(_QWORD *)((*(_QWORD *)(v56 + 32) & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                   + 8i64
                                   * (unsigned int)((int)(*(_DWORD *)(v56 + 32)
                                                        - (*(_DWORD *)(v56 + 32) & 0xFFFFF000)
                                                        - 56)
                                                  / 56)
                                   + 40) & 0xFFFFFFFFFFFFFFFEui64);
        if ( (v46 & 0x80u) == 0 )
        {
          if ( (v58->m128_i16[5] & 0x200) != 0 )
          {
            v113 = v117;
            v114 = v118;
            v115.m128_i32[0] = _xmm.m128_i32[0];
            v115.m128_i32[1] = _mm_shuffle_ps(_xmm, _xmm, 85).m128_u32[0];
            v115.m128_i32[2] = _mm_shuffle_ps(_xmm, _xmm, 170).m128_u32[0];
            v115.m128_i32[3] = _mm_shuffle_ps(_xmm, _xmm, 255).m128_u32[0];
            v129 = v117;
            v130 = v118;
            v131.m128_u64[0] = __PAIR64__(v115.m128_u32[1], _xmm.m128_u32[0]);
            v131.m128_u64[1] = v115.m128_u64[1];
            v62 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v58[2], v58[2], 0), v117),
                        _mm_mul_ps(_mm_shuffle_ps(v58[2], v58[2], 85), v118)),
                      _mm_mul_ps(_mm_shuffle_ps(v58[2], v58[2], 170), v131)),
                    _mm_and_ps(
                      (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v,
                      v58[2]));
            v63 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v58[3], v58[3], 0), v117),
                        _mm_mul_ps(_mm_shuffle_ps(v58[3], v58[3], 85), v118)),
                      _mm_mul_ps(_mm_shuffle_ps(v58[3], v58[3], 170), v131)),
                    _mm_and_ps(
                      (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v,
                      v58[3]));
            v113 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v58[1], v58[1], 0), v117),
                         _mm_mul_ps(_mm_shuffle_ps(v58[1], v58[1], 85), v118)),
                       _mm_mul_ps(_mm_shuffle_ps(v58[1], v58[1], 170), v131)),
                     _mm_and_ps(
                       v58[1],
                       (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
            v114 = v62;
            v115 = v63;
            v64 = (__m128)_xmm;
            v118 = _xmm;
            v46 = v46 & 0xFFFFFF3F | 0x80;
            v138 = v46;
          }
          else
          {
            v64 = _mm_and_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(v118, _mm_shuffle_ps(v58[1], v58[1], 85)),
                        _mm_mul_ps(v117, _mm_shuffle_ps(v58[1], v58[1], 0))),
                      _mm_and_ps(
                        v58[1],
                        (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
                    (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
            v118 = _mm_and_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(v118, _mm_shuffle_ps(v58[2], v58[2], 85)),
                         _mm_mul_ps(v117, _mm_shuffle_ps(v58[2], v58[2], 0))),
                       _mm_and_ps(
                         v58[2],
                         (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
                     (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
          }
          v117 = v64;
        }
        else
        {
          if ( (v58->m128_i16[5] & 0x200) != 0 )
          {
            v59 = v58 + 1;
          }
          else
          {
            v133[0] = v58[1].m128_i32[0];
            v133[1] = v58[1].m128_i32[1];
            v133[2] = v58[1].m128_i32[2];
            v133[3] = v58[1].m128_i32[3];
            v133[4] = v58[2].m128_i32[0];
            v133[5] = v58[2].m128_i32[1];
            v133[6] = v58[2].m128_i32[2];
            v133[7] = v58[2].m128_i32[3];
            v134 = _xmm;
            v59 = (__m128 *)v133;
          }
          v126 = v113;
          v127 = v114;
          v128 = v115;
          v60 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v59[1], v59[1], 0), v113),
                      _mm_mul_ps(_mm_shuffle_ps(v59[1], v59[1], 85), v114)),
                    _mm_mul_ps(_mm_shuffle_ps(v59[1], v59[1], 170), v115)),
                  _mm_and_ps((__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v, v59[1]));
          v61 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v59[2], v59[2], 0), v113),
                      _mm_mul_ps(_mm_shuffle_ps(v59[2], v59[2], 85), v114)),
                    _mm_mul_ps(_mm_shuffle_ps(v59[2], v59[2], 170), v115)),
                  _mm_and_ps((__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v, v59[2]));
          v113 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(*v59, *v59, 0), v113),
                       _mm_mul_ps(_mm_shuffle_ps(*v59, *v59, 85), v114)),
                     _mm_mul_ps(_mm_shuffle_ps(*v59, *v59, 170), v115)),
                   _mm_and_ps((__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v, *v59));
          v114 = v60;
          v115 = v61;
        }
        v65 = ((*(_BYTE *)(v56 + 76) & 3) != 0) | v29;
        v137 = v65;
        if ( (v58->m128_i16[5] & 0x400) == 0 )
          goto LABEL_158;
        v66 = (__int64)&v58[4];
        v67 = v58[4].m128_u64[0];
        if ( !v67 )
          goto LABEL_158;
        if ( (v67 & 1) != 0 )
        {
          if ( (v67 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A58 )
            goto LABEL_134;
          goto LABEL_158;
        }
        v68 = 0i64;
        v69 = v67 >> 1;
        if ( v69 )
        {
          v70 = (_QWORD *)(v58[4].m128_u64[1] + 4);
          while ( *v70 != qword_142451A58 )
          {
            ++v68;
            v70 += 2;
            if ( v68 >= v69 )
              goto LABEL_158;
          }
          v66 = 16 * v68 + v58[4].m128_u64[1] + 4;
LABEL_134:
          if ( v66 )
          {
            v71 = *(_QWORD *)(v66 + 8);
            if ( v71 )
            {
              if ( !*(_BYTE *)(v71 + 41) )
              {
                v72 = 0;
                if ( !*(_QWORD *)(v71 + 24) )
                  goto LABEL_158;
                v73 = 0i64;
                while ( 1 )
                {
                  v74 = *(_QWORD *)(*(_QWORD *)(v71 + 16) + 8 * v73);
                  if ( v74 )
                  {
                    if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v74 + 16i64))(v74) )
                      break;
                  }
                  v73 = ++v72;
                  if ( (unsigned __int64)v72 >= *(_QWORD *)(v71 + 24) )
                    goto LABEL_158;
                }
                v65 = v137;
              }
              if ( v65 )
              {
                *(_DWORD *)(v56 + 76) |= 0x1200000u;
                v75 = *(_QWORD *)(v56 + 24);
                if ( v75 )
                {
                  v76 = *(_QWORD *)(v56 + 48);
                  if ( v76 )
                  {
                    v77 = 0x1000000;
                    if ( *(int *)(v76 + 76) >= 0 )
                    {
                      if ( *(_BYTE *)(v75 + 202) )
                      {
                        v78 = *(unsigned __int16 *)(v76 + 72);
                        v138 = v78;
                        v79 = v75 + 208;
                        if ( v78 < *(_DWORD *)(v75 + 220) )
                        {
LABEL_152:
                          *(_QWORD *)(v76 + 80) = *(_QWORD *)(*(_QWORD *)v79 + 8i64 * v78);
                          *(_QWORD *)(*(_QWORD *)v79 + 8i64 * v78) = v76;
                          v80 = v78 + 1;
                          if ( *(_DWORD *)(v79 + 8) < v80 )
                            *(_DWORD *)(v79 + 8) = v80;
                        }
                        else if ( Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(
                                    (Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *)(v75 + 208),
                                    v78 + 1) )
                        {
                          v78 = v138;
                          goto LABEL_152;
                        }
                      }
                      else
                      {
                        *(_QWORD *)(v76 + 80) = *(_QWORD *)(v75 + 192);
                        *(_QWORD *)(v75 + 192) = v76;
                      }
                      v77 = -2130706432;
                    }
                    *(_DWORD *)(v76 + 76) |= v77;
                  }
                }
              }
              v46 |= 0x100u;
              v138 = v46;
            }
          }
        }
LABEL_158:
        v81 = v58 + 4;
        v82 = v58[4].m128_u64[0];
        if ( !v82 )
          goto LABEL_187;
        if ( (v82 & 1) != 0 )
        {
          if ( (v82 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A48 )
          {
            v83 = (__int64)&v58[4];
            goto LABEL_168;
          }
          goto LABEL_187;
        }
        v84 = 0i64;
        v85 = v82 >> 1;
        if ( v85 )
        {
          v86 = (_QWORD *)(v58[4].m128_u64[1] + 4);
          while ( *v86 != qword_142451A48 )
          {
            ++v84;
            v86 += 2;
            if ( v84 >= v85 )
              goto LABEL_187;
          }
          v83 = 16 * v84 + v58[4].m128_u64[1] + 4;
LABEL_168:
          v124 = v83;
          if ( v83 )
          {
            v87 = *(_DWORD *)(v83 + 8);
            if ( v87 <= 0xE )
            {
              v88 = 24804;
              if ( _bittest(&v88, v87) )
              {
                if ( v137 )
                {
                  *(_DWORD *)(v56 + 76) |= 0x1020000u;
                  v89 = *(_QWORD *)(v56 + 24);
                  if ( v89 )
                  {
                    v90 = *(_QWORD *)(v56 + 48);
                    if ( v90 )
                    {
                      v91 = 0x1000000;
                      if ( *(int *)(v90 + 76) >= 0 )
                      {
                        if ( *(_BYTE *)(v89 + 202) )
                        {
                          v92 = *(unsigned __int16 *)(v90 + 72);
                          v111 = v92;
                          v93 = v89 + 208;
                          if ( v92 < *(_DWORD *)(v89 + 220) )
                          {
LABEL_179:
                            *(_QWORD *)(v90 + 80) = *(_QWORD *)(*(_QWORD *)v93 + 8i64 * v92);
                            *(_QWORD *)(*(_QWORD *)v93 + 8i64 * v92) = v90;
                            v94 = v92 + 1;
                            if ( *(_DWORD *)(v93 + 8) < v94 )
                              *(_DWORD *)(v93 + 8) = v94;
                          }
                          else if ( Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(
                                      (Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *)(v89 + 208),
                                      v92 + 1) )
                          {
                            v92 = v111;
                            goto LABEL_179;
                          }
                          v46 = v138;
                        }
                        else
                        {
                          *(_QWORD *)(v90 + 80) = *(_QWORD *)(v89 + 192);
                          *(_QWORD *)(v89 + 192) = v90;
                        }
                        v91 = -2130706432;
                        v83 = v124;
                      }
                      *(_DWORD *)(v90 + 76) |= v91;
                    }
                  }
                }
                v46 |= 0x100u;
                v138 = v46;
                if ( *(_DWORD *)(v83 + 8) == 2 )
                {
                  v46 |= 0x400u;
                  v138 = v46;
                }
              }
            }
          }
        }
LABEL_187:
        if ( (v46 & 0x100) == 0 )
        {
          v95 = _mm_add_ps(v120, _mm_mul_ps(v58[6], v119));
          v119 = _mm_mul_ps(v119, v58[5]);
          v120 = v95;
        }
        if ( !v49 && (v58->m128_i16[5] & 0x800) != 0 )
        {
          v96 = v81->m128_u64[0];
          if ( !v81->m128_u64[0] )
            goto LABEL_202;
          if ( (v96 & 1) != 0 )
          {
            if ( (v96 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A68 )
              v49 = (unsigned __int64)&v58[4];
            goto LABEL_203;
          }
          v97 = v96 >> 1;
          if ( !v97 )
          {
LABEL_202:
            v49 = 0i64;
            goto LABEL_203;
          }
          v98 = (_QWORD *)(v58[4].m128_u64[1] + 4);
          while ( *v98 != qword_142451A68 )
          {
            ++v49;
            v98 += 2;
            if ( v49 >= v97 )
              goto LABEL_202;
          }
          v49 = v58[4].m128_u64[1] + 4 + 16 * v49;
        }
LABEL_203:
        if ( !v53 && (v58->m128_i16[5] & 0x1000) != 0 )
        {
          v99 = v81->m128_u64[0];
          if ( !v81->m128_u64[0] )
            goto LABEL_216;
          if ( (v99 & 1) != 0 )
          {
            if ( (v99 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A70 )
              v53 = (unsigned __int64)&v58[4];
            goto LABEL_217;
          }
          v100 = v99 >> 1;
          if ( !v100 )
          {
LABEL_216:
            v53 = 0i64;
            goto LABEL_217;
          }
          v101 = (_QWORD *)(v58[4].m128_u64[1] + 4);
          while ( *v101 != qword_142451A70 )
          {
            ++v53;
            v101 += 2;
            if ( v53 >= v100 )
              goto LABEL_216;
          }
          v53 = v58[4].m128_u64[1] + 4 + 16 * v53;
        }
LABEL_217:
        v56 = *(_QWORD *)(v56 + 48);
        v29 = v137;
        if ( v56 )
          continue;
        break;
      }
      v5 = v125;
      v27 = v132;
LABEL_219:
      if ( v49 )
      {
        *(_QWORD *)&v112 = v49;
        v116 = 1;
      }
      if ( v53 )
      {
        *((_QWORD *)&v112 + 1) = v53;
        v116 = 1;
      }
      (*(void (__fastcall **)(__int64, __m128 *, __int128 *, _QWORD))(*(_QWORD *)v5 + 32i64))(v5, v27, &v112, v46);
      *(_DWORD *)(v5 + 76) &= 0xFFFFFFFC;
      v1 = v136;
LABEL_224:
      v5 = *(_QWORD *)(v5 + 80);
      v125 = v5;
      v4 = 24804;
    }
    while ( v5 );
    v3 = v121;
    v2 = v139;
LABEL_226:
    v139 = ++v2;
    v121 = ++v3;
  }
  while ( v2 < DepthUsed );
LABEL_227:
  LODWORD(v102) = v1->DepthUpdates.DepthUsed;
  while ( (_DWORD)v102 )
  {
    v102 = (unsigned int)(v102 - 1);
    for ( i = v1->DepthUpdates.pDepth[v102]; i; i = i->pNextUpdate )
    {
      if ( (i->UpdateFlags & 0x3000000) != 0 )
      {
        i->vfptr->UpdateBundlePattern(i, 0);
        i->UpdateFlags &= 0xFCFFFFFF;
      }
      i->UpdateFlags &= ~0x80000000;
    }
  }
  for ( j = 0i64; (unsigned int)j < v1->DepthUpdates.DepthUsed; j = (unsigned int)(j + 1) )
    v1->DepthUpdates.pDepth[j] = v1->DepthUpdates.NullValue;
  v1->DepthUpdates.DepthUsed = 0;
  v1->DepthUpdatesChained = 0;
  pLast = (__int64)v1->CachedChildPattern.pLast;
  pFirst = v1->CachedChildPattern.pFirst;
  p_pNextPattern = &pFirst->pNextPattern;
  for ( k = (Scaleform::Render::BundleEntry **)pLast; pFirst; p_pNextPattern = &pFirst->pNextPattern )
  {
    pFirst->Key.pImpl->vfptr->UpdateBundleEntry(
      pFirst->Key.pImpl,
      pFirst->Key.Data,
      pFirst,
      v1,
      v1->pRenderer2D,
      (Scaleform::Render::BundleIterator *)&p_pNextPattern);
    if ( pFirst->pBundle.pObject )
    {
      pObject = pFirst->pBundle.pObject;
      if ( pObject )
        ++pObject->RefCount;
      v136 = (Scaleform::Render::TreeCacheRoot *)pFirst->pBundle.pObject;
      v108 = (Scaleform::Render::Bundle *)v136;
      if ( LOBYTE(v136->pParent) )
        Scaleform::Render::Bundle::UpdateChain((Scaleform::Render::Bundle *)v136, pFirst);
      if ( v108->RefCount-- == 1 )
        v108->vfptr->__vecDelDtor(v108, 1u);
    }
    if ( p_pNextPattern == k )
      break;
    pFirst = *p_pNextPattern;
  }
  ++BundlePatternFrameId;
}

// File Line: 2021
// RVA: 0x96F000
void __fastcall Scaleform::Render::TreeCacheRoot::Draw(Scaleform::Render::TreeCacheRoot *this)
{
  unsigned __int16 Flags; // cx
  Scaleform::Render::HAL *pObject; // rcx
  bool EnableBlendTarget; // al
  Scaleform::Render::Color *v5; // rdx
  Scaleform::Render::Viewport *v6; // rdi
  Scaleform::Render::HAL *v7; // rcx
  Scaleform::Render::HAL *v8; // rcx
  __int64 v9[3]; // [rsp+20h] [rbp-18h] BYREF
  Scaleform::Render::Color backgroundColor; // [rsp+40h] [rbp+8h] BYREF

  Flags = this->Flags;
  if ( (Flags & 3) == 1 || (Flags & 0x40) != 0 )
  {
    pObject = this->pRenderer2D->pHal.pObject;
    EnableBlendTarget = this->EnableBlendTarget;
    pObject->HALState &= ~0x800u;
    if ( EnableBlendTarget )
      pObject->HALState |= 0x800u;
    v5 = (Scaleform::Render::Color *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64)
                                                            + 0x28)
                                                + 8i64
                                                * (unsigned int)((int)(LODWORD(this->pNode)
                                                                     - ((__int64)this->pNode & 0xFFFFF000)
                                                                     - 56)
                                                               / 56)
                                                + 40) & 0xFFFFFFFFFFFFFFFEui64);
    v6 = (Scaleform::Render::Viewport *)&v5[40];
    if ( v5[40].Raw && v5[41].Raw )
    {
      v7 = this->pRenderer2D->pHal.pObject;
      backgroundColor = (Scaleform::Render::Color)v5[51].Raw;
      Scaleform::Render::HAL::BeginDisplay(v7, (int *)&backgroundColor.Raw, v6);
    }
    v8 = this->pRenderer2D->pHal.pObject;
    v9[0] = (__int64)this->CachedChildPattern.pFirst;
    v9[1] = (__int64)this->CachedChildPattern.pLast;
    v8->vfptr[32].__vecDelDtor(v8, (unsigned int)v9);
    if ( v6->BufferWidth )
    {
      if ( v6->BufferHeight )
        Scaleform::Render::HAL::EndDisplay(this->pRenderer2D->pHal.pObject);
    }
  }
}

// File Line: 2052
// RVA: 0x9468F0
void __fastcall Scaleform::Render::TreeCacheMeshBase::TreeCacheMeshBase(
        Scaleform::Render::TreeCacheMeshBase *this,
        Scaleform::Render::TreeNode *pnode,
        Scaleform::Render::SortKey *key,
        Scaleform::Render::Renderer2DImpl *prenderer2D,
        unsigned __int16 flags)
{
  Scaleform::Render::BundleEntry *p_SorterShapeNode; // rbx
  Scaleform::Render::SortKeyInterface *pImpl; // rcx

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
  p_SorterShapeNode = &this->SorterShapeNode;
  this->SorterShapeNode.pNextPattern = 0i64;
  this->SorterShapeNode.pChain = 0i64;
  *(_DWORD *)&this->SorterShapeNode.ChainHeight = 0;
  pImpl = key->pImpl;
  p_SorterShapeNode->Key = *key;
  ((void (__fastcall *)(Scaleform::Render::SortKeyInterface *))pImpl->vfptr->AddRef)(pImpl);
  p_SorterShapeNode->pBundle.pObject = 0i64;
  p_SorterShapeNode->pSourceNode = this;
  p_SorterShapeNode->Removed = 0;
  this->M.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
}

// File Line: 2056
// RVA: 0x94D660
void __fastcall Scaleform::Render::TreeCacheMeshBase::~TreeCacheMeshBase(Scaleform::Render::TreeCacheMeshBase *this)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rdi
  Scaleform::Render::MatrixPoolImpl::EntryHandle v3; // rdi
  __int64 DataPageOffset; // rcx

  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheMeshBase::`vftable;
  pHandle = this->M.pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v3.pHeader = pHandle->pHeader;
    if ( v3.pHeader->RefCount-- == 1 )
    {
      DataPageOffset = v3.pHeader->DataPageOffset;
      *(_WORD *)((char *)&v3.pHeader[1].RefCount + DataPageOffset + 2) += 16 * (unsigned __int8)v3.pHeader->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v3.pHeader[1].pHandle + DataPageOffset))[5].pHeader += (unsigned __int8)v3.pHeader->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v3.pNext->pNext);
      v3.pHeader->pHandle = 0i64;
    }
  }
  Scaleform::Render::BundleEntry::~BundleEntry(&this->SorterShapeNode);
  Scaleform::Render::TreeCacheNode::~TreeCacheNode(this);
}

// File Line: 2061
// RVA: 0x962450
void __fastcall Scaleform::Render::TreeCacheMeshBase::ComputeFinalMatrix(
        Scaleform::Render::TreeCacheMeshBase *this,
        Scaleform::Render::TransformArgs *t,
        Scaleform::Render::TransformFlags flags)
{
  char v3; // bp
  Scaleform::Render::MatrixPoolImpl::HMatrix *p_M; // rsi
  unsigned int formatBits; // r14d
  Scaleform::Render::Cxform *p_Cx; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v9; // rax
  Scaleform::Render::MatrixPoolImpl::HMatrix *v10; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  __int64 DataPageOffset; // rcx
  Scaleform::Render::Matrix3x4<float> m; // [rsp+40h] [rbp-58h] BYREF
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+A0h] [rbp+8h] BYREF

  v3 = flags;
  p_M = &this->M;
  if ( this->M.pHandle == &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    formatBits = 0;
    p_Cx = &t->Cx;
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
      Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(p_M, v10);
    }
    else
    {
      Scaleform::Render::TransformArgs::GetMatrix3D(t, flags, &m);
      v9 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
             &this->pRenderer2D->MPool,
             &result,
             &m,
             p_Cx,
             formatBits | 0x10);
      Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(p_M, v9);
    }
    if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
      pHeader = result.pHandle->pHeader;
      if ( result.pHandle->pHeader->RefCount-- == 1 )
      {
        DataPageOffset = pHeader->DataPageOffset;
        *(_WORD *)((char *)&pHeader[1].RefCount + DataPageOffset + 2) += 16 * (unsigned __int8)pHeader->UnitSize;
        (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&pHeader[1].pHandle + DataPageOffset))[5].pHeader += (unsigned __int8)pHeader->UnitSize;
        Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(pHeader->pHandle);
        pHeader->pHandle = 0i64;
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
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix3D(p_M, &m);
    }
    if ( (v3 & 2) != 0 )
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(p_M, &t->Cx);
  }
}

// File Line: 2102
// RVA: 0x98A6C0
bool __fastcall Scaleform::Render::TreeCacheMeshBase::GetPatternChain(
        Scaleform::Render::TreeCacheMeshBase *this,
        Scaleform::Render::BundleEntryRange *range,
        unsigned int __formal)
{
  unsigned __int16 Flags; // cx
  bool result; // al
  Scaleform::Render::CacheEffect *pEffect; // rcx
  Scaleform::Render::Bundle *pObject; // rax

  Flags = this->Flags;
  if ( (Flags & 3) == 1 || (Flags & 0x40) != 0 )
  {
    range->Length = 1;
    range->pLast = &this->SorterShapeNode;
    range->pFirst = &this->SorterShapeNode;
    pEffect = this->Effects.pEffect;
    this->SorterShapeNode.Removed = 0;
    if ( pEffect || (this->UpdateFlags & 0x7E0000) != 0 )
    {
      if ( (this->UpdateFlags & 0x7E0000) != 0 )
      {
        Scaleform::Render::CacheEffectChain::UpdateEffects(&this->Effects, this, this->UpdateFlags & 0x7E0000);
        Scaleform::Render::TreeCacheNode::updateEffectChain(this, range);
        this->UpdateFlags &= 0xFF81FFFF;
      }
      else if ( pEffect )
      {
        ((void (__fastcall *)(Scaleform::Render::CacheEffect *))pEffect->vfptr->GetRange)(pEffect);
      }
      Scaleform::Render::BundleEntryRange::StripChainsByDepth(range, this->Depth);
      return 1;
    }
    else
    {
      pObject = this->SorterShapeNode.pBundle.pObject;
      if ( pObject )
        pObject->NeedUpdate = 1;
      result = 1;
      this->SorterShapeNode.pChain = 0i64;
      this->SorterShapeNode.ChainHeight = 0;
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
void __fastcall Scaleform::Render::TreeCacheMeshBase::UpdateBundlePattern(
        Scaleform::Render::TreeCacheMeshBase *this,
        unsigned int __formal)
{
  Scaleform::Render::BundleEntryRange contentChain; // [rsp+20h] [rbp-28h] BYREF

  if ( this->pMask )
  {
    if ( this->Effects.pEffect )
    {
      contentChain.Length = 1;
      contentChain.pLast = &this->SorterShapeNode;
      contentChain.pFirst = &this->SorterShapeNode;
      Scaleform::Render::TreeCacheNode::updateEffectChain(this, &contentChain);
    }
  }
}

