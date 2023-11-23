// File Line: 86
// RVA: 0x98B5D0
Scaleform::Render::TreeShape::NodeData *__fastcall Scaleform::Render::TreeCacheShapeLayer::GetShapeNodeData(
        Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeNode *pNode; // rdx
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rdx

  pNode = this->pNode;
  if ( !pNode )
    pNode = this->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
  v2 = (unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64;
  v3 = (__int64)((unsigned __int128)((__int64)((__int64)&pNode[-1] - ((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64))
                                   * (__int128)0x4924924924924925i64) >> 64) >> 4;
  return (Scaleform::Render::TreeShape::NodeData *)(*(_QWORD *)(*(_QWORD *)(v2 + 40)
                                                              + 8 * ((unsigned int)v3 + (v3 >> 63))
                                                              + 40) & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 92
// RVA: 0x9895B0
Scaleform::Render::ShapeMeshProvider *__fastcall Scaleform::Render::TreeCacheShapeLayer::GetMeshProvider(
        Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeNode *pNode; // rdx
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rdx

  pNode = this->pNode;
  if ( !pNode )
    pNode = this->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
  v2 = (unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64;
  v3 = (__int64)((unsigned __int128)((__int64)((__int64)&pNode[-1] - ((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64))
                                   * (__int128)0x4924924924924925i64) >> 64) >> 4;
  return *(Scaleform::Render::ShapeMeshProvider **)((*(_QWORD *)(*(_QWORD *)(v2 + 40)
                                                               + 8 * ((unsigned int)v3 + (v3 >> 63))
                                                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                                  + 144);
}

// File Line: 186
// RVA: 0x9A0DE0
bool __fastcall Scaleform::Render::TreeShape::NodeData::PropagateUp(
        Scaleform::Render::TreeShape::NodeData *this,
        Scaleform::Render::ContextImpl::Entry *entry)
{
  float x1; // xmm8_4
  float x2; // xmm9_4
  float y1; // xmm6_4
  float y2; // xmm7_4
  Scaleform::Render::ShapeMeshProvider *pObject; // rcx
  float *v9; // rax
  Scaleform::Render::StateBag *v10; // rax
  _QWORD *pData; // rsi
  __int64 v12; // rbx
  __m128 v13; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm0
  __m128 v19; // xmm2
  __m128 v20; // xmm3
  __m128 v21; // xmm0
  __m128 v22; // xmm10
  __m128 v23; // xmm3
  __m128 v24; // xmm10
  float v25; // xmm11_4
  float v26; // xmm12_4
  float v27; // xmm13_4
  __int16 v28; // ax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::Rect<float> bounds; // [rsp+18h] [rbp-69h] BYREF
  Scaleform::Render::Rect<float> pr; // [rsp+28h] [rbp-59h] BYREF
  Scaleform::Render::Rect<float> v33; // [rsp+38h] [rbp-49h] BYREF
  Scaleform::Render::Rect<float> v34; // [rsp+48h] [rbp-39h] BYREF

  x1 = this->AproxLocalBounds.x1;
  x2 = this->AproxLocalBounds.x2;
  bounds = 0i64;
  pr = 0i64;
  v33 = 0i64;
  if ( x1 >= x2 || (y1 = this->AproxLocalBounds.y1, y2 = this->AproxLocalBounds.y2, y1 >= y2) )
  {
    pObject = this->pMeshProvider.pObject;
    if ( !pObject )
    {
      y2 = bounds.y2;
      x2 = bounds.x2;
      y1 = bounds.y1;
      x1 = bounds.x1;
      goto LABEL_16;
    }
    v9 = (float *)pObject->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->GetIdentityBounds(
                    &pObject->Scaleform::Render::MeshProvider,
                    &v34);
    x1 = *v9;
    y1 = v9[1];
    x2 = v9[2];
    y2 = v9[3];
  }
  bounds.y2 = y2;
  bounds.x2 = x2;
  bounds.y1 = y1;
  bounds.x1 = x1;
  if ( x1 >= x2 || y1 >= y2 )
    goto LABEL_16;
  v33.x1 = x1;
  v33.y1 = y1;
  v33.x2 = x2;
  v33.y2 = y2;
  v10 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::FilterState>(this);
  if ( v10 )
  {
    pData = v10->pData;
    if ( pData )
    {
      v12 = 0i64;
      if ( *((_DWORD *)pData + 6) )
      {
        do
        {
          Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
            *(Scaleform::Render::Filter **)(pData[2] + 8 * v12),
            &bounds);
          v12 = (unsigned int)(v12 + 1);
        }
        while ( (unsigned int)v12 < *((_DWORD *)pData + 6) );
        y2 = bounds.y2;
        x2 = bounds.x2;
        y1 = bounds.y1;
        x1 = bounds.x1;
      }
    }
  }
  if ( (this->Flags & 0x200) != 0 )
  {
    Scaleform::Render::Matrix3x4<float>::EncloseTransform(&this->M34, &pr, &bounds);
LABEL_16:
    v24.m128_i32[0] = LODWORD(pr.x1);
    v25 = pr.y1;
    v26 = pr.x2;
    v27 = pr.y2;
    goto LABEL_17;
  }
  v13 = *(__m128 *)&this->M34.M[0][0];
  v14 = _mm_unpacklo_ps(v13, *(__m128 *)&this->M34.M[1][0]);
  v15 = _mm_shuffle_ps(v13, *(__m128 *)&this->M34.M[1][0], 255);
  v16 = _mm_mul_ps(_mm_unpackhi_ps((__m128)bounds, (__m128)bounds), v14);
  v17 = _mm_mul_ps(_mm_unpacklo_ps((__m128)bounds, (__m128)bounds), v14);
  v18 = _mm_unpacklo_ps(v17, v16);
  v19 = _mm_unpackhi_ps(v17, v16);
  v20 = _mm_add_ps(v19, v18);
  v21 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v19);
  v22 = _mm_min_ps(v20, v21);
  v23 = _mm_max_ps(v20, v21);
  v24 = _mm_add_ps(
          _mm_shuffle_ps(
            _mm_min_ps(v22, _mm_shuffle_ps(v22, v22, 177)),
            _mm_max_ps(v23, _mm_shuffle_ps(v23, v23, 177)),
            136),
          _mm_shuffle_ps(v15, v15, 136));
  LODWORD(v25) = _mm_shuffle_ps(v24, v24, 85).m128_u32[0];
  LODWORD(v26) = _mm_shuffle_ps(v24, v24, 170).m128_u32[0];
  LODWORD(v27) = _mm_shuffle_ps(v24, v24, 255).m128_u32[0];
LABEL_17:
  if ( x1 == this->AproxLocalBounds.x1
    && x2 == this->AproxLocalBounds.x2
    && y1 == this->AproxLocalBounds.y1
    && y2 == this->AproxLocalBounds.y2
    && v24.m128_f32[0] == x1
    && v26 == x2
    && v25 == y1
    && v27 == y2 )
  {
    LOBYTE(v28) = 0;
  }
  else
  {
    WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(entry, 8u);
    *(float *)&WritableData[7].vfptr = x1;
    *((float *)&WritableData[7].vfptr + 1) = y1;
    *(float *)&WritableData[7].Type = x2;
    *(float *)(&WritableData[7].Flags + 1) = y2;
    LODWORD(WritableData[8].vfptr) = v24.m128_i32[0];
    *((float *)&WritableData[8].vfptr + 1) = v25;
    *(float *)&WritableData[8].Type = v26;
    *(float *)(&WritableData[8].Flags + 1) = v27;
    Scaleform::Render::TreeNode::NodeData::updateOriginalBoundState(
      (Scaleform::Render::TreeNode::NodeData *)WritableData,
      &v33);
    return this->Flags & 1;
  }
  return v28;
}

// File Line: 230
// RVA: 0x9F8DB0
Scaleform::Render::TreeCacheNode *__fastcall Scaleform::Render::TreeShape::NodeData::updateCache(
        Scaleform::Render::TreeShape::NodeData *this,
        Scaleform::Render::TreeCacheNode *pparent,
        Scaleform::Render::TreeCacheNode *pinsert,
        Scaleform::Render::TreeShape *pnode,
        unsigned __int16 depth)
{
  Scaleform::Render::TreeCacheNode *pRenderer; // rbx
  Scaleform::Render::ShapeMeshProvider *v10; // r13
  unsigned int v11; // ebx
  int v12; // eax
  int v13; // edx
  int v14; // edi
  Scaleform::Render::TreeCacheContainer *v15; // rax
  int v17; // [rsp+88h] [rbp+20h] BYREF

  pRenderer = pnode->pRenderer;
  if ( pRenderer )
    goto LABEL_18;
  v10 = *(Scaleform::Render::ShapeMeshProvider **)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pnode & 0xFFFFFFFFFFFFF000ui64)
                                                                          + 0x28)
                                                              + 8i64
                                                              * (unsigned int)((int)((_DWORD)pnode
                                                                                   - ((unsigned int)pnode & 0xFFFFF000)
                                                                                   - 56)
                                                                             / 56)
                                                              + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                                 + 144);
  v11 = v10->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->GetLayerCount(&v10->Scaleform::Render::MeshProvider);
  if ( !pparent )
  {
    v12 = 4;
LABEL_6:
    v13 = this->Flags & 0xC;
    if ( !v13 )
      v13 = v12;
    goto LABEL_8;
  }
  v12 = pparent->Flags & 0xC;
  if ( v12 != 12 )
    goto LABEL_6;
  v13 = 12;
LABEL_8:
  v14 = v13 | this->Flags & 0x221 | ((unsigned __int8)pparent->Flags | (unsigned __int8)(2 * (this->Flags & 0x20))) & 0xC0;
  if ( Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::Scale9State>(this) )
    v14 |= 0x80u;
  if ( v11 == 1 )
  {
    pRenderer = (Scaleform::Render::TreeCacheNode *)Scaleform::Render::TreeCacheShapeLayer::Create(
                                                      pparent,
                                                      v10,
                                                      0,
                                                      v14,
                                                      pnode,
                                                      this->MorphRatio);
  }
  else
  {
    v17 = 71;
    v15 = (Scaleform::Render::TreeCacheContainer *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     pparent,
                                                     160i64,
                                                     &v17);
    pRenderer = v15;
    if ( v15 )
    {
      Scaleform::Render::TreeCacheContainer::TreeCacheContainer(v15, pnode, pparent->pRenderer2D, v14);
      pRenderer->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheShape::`vftable;
    }
    else
    {
      pRenderer = 0i64;
    }
  }
  if ( !pRenderer )
    return 0i64;
  pnode->pRenderer = pRenderer;
LABEL_18:
  Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(pRenderer, pparent, pinsert, this, depth);
  return pRenderer;
}

// File Line: 268
// RVA: 0x960DE0
Scaleform::Render::TreeNode *__fastcall Scaleform::Render::TreeShape::NodeData::CloneCreate(
        Scaleform::Render::TreeShape::NodeData *this,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::TreeShape::NodeData *v4; // rax
  Scaleform::Render::ContextImpl::EntryData *v5; // rbx
  Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeShape::NodeData> src; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::Render::TreeShape::NodeData *v8; // [rsp+58h] [rbp+10h]
  Scaleform::Render::TreeShape::NodeData *v9; // [rsp+60h] [rbp+18h]

  v4 = (Scaleform::Render::TreeShape::NodeData *)context->pHeap->vfptr->Alloc(context->pHeap, 160i64, 0i64);
  v5 = v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    src.pC = this;
    Scaleform::Render::TreeShape::NodeData::NodeData(
      v4,
      (Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeShape::NodeData>)&src);
  }
  return (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::createEntryHelper(context, v5);
}

// File Line: 287
// RVA: 0x94D820
void __fastcall Scaleform::Render::TreeCacheShape::~TreeCacheShape(Scaleform::Render::TreeCacheShape *this)
{
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // rbx
  Scaleform::Render::TreeCacheNode *v3; // rax
  Scaleform::Render::TreeCacheNode *pNext; // rcx

  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheShape::`vftable;
  p_Children = &this->Children;
  while ( 1 )
  {
    v3 = (Scaleform::Render::TreeCacheNode *)&p_Children[-1].Root.8;
    if ( !p_Children )
      v3 = 0i64;
    if ( p_Children->Root.pNext == v3 )
      break;
    pNext = this->Children.Root.pNext;
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->pPrev = pNext->pPrev;
    pNext->pNext = (Scaleform::Render::TreeCacheNode *)-1i64;
    pNext->pPrev = 0i64;
    pNext->pParent = 0i64;
    pNext->vfptr->__vecDelDtor(pNext, 1u);
  }
  Scaleform::Render::TreeCacheContainer::~TreeCacheContainer(this);
}

// File Line: 302
// RVA: 0x9BFA50
void __fastcall Scaleform::Render::TreeCacheShape::UpdateTransform(
        Scaleform::Render::TreeCacheShape *this,
        Scaleform::Render::TreeNode::NodeData *shapeData,
        Scaleform::Render::TransformArgs *t,
        Scaleform::Render::TransformFlags flags)
{
  float y2; // xmm2_4
  float x2; // xmm1_4
  float y1; // xmm0_4
  signed __int32 v11; // esi
  Scaleform::Render::TreeCacheShapeLayer *pNext; // rbx
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // rdi
  __int64 v14; // rax
  Scaleform::Render::TransformArgs ta; // [rsp+30h] [rbp-E8h] BYREF

  Scaleform::Render::TransformArgs::TransformArgs(&ta, t, &t->Mat);
  if ( (flags & 0x80u) != 0 )
    ta.Mat3D = t->Mat3D;
  Scaleform::Render::TreeCacheNode::updateCulling(
    this,
    shapeData,
    t,
    &ta.CullRect,
    (Scaleform::Render::TransformFlags)(flags | 0x20));
  y2 = shapeData->AproxParentBounds.y2;
  x2 = shapeData->AproxParentBounds.x2;
  y1 = shapeData->AproxParentBounds.y1;
  this->SortParentBounds.x1 = shapeData->AproxParentBounds.x1;
  v11 = flags & 0xFFFFFFEF;
  this->SortParentBounds.y1 = y1;
  this->SortParentBounds.x2 = x2;
  this->SortParentBounds.y2 = y2;
  this->Flags &= ~0x400u;
  pNext = (Scaleform::Render::TreeCacheShapeLayer *)this->Children.Root.pNext;
  p_Children = &this->Children;
  while ( 1 )
  {
    v14 = p_Children ? (__int64)&p_Children[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::Render::TreeCacheShapeLayer *)v14 )
      break;
    Scaleform::Render::TreeCacheShapeLayer::UpdateTransform(
      pNext,
      shapeData,
      &ta,
      (Scaleform::Render::TransformFlags)v11);
    pNext = (Scaleform::Render::TreeCacheShapeLayer *)pNext->pNext;
  }
}

// File Line: 330
// RVA: 0x990620
void __fastcall Scaleform::Render::TreeCacheShape::HandleChanges(
        Scaleform::Render::TreeCacheShape *this,
        char changeBits)
{
  Scaleform::Render::TreeCacheNode *pParent; // rcx
  unsigned int v5; // r8d
  __int64 v6; // rdx
  Scaleform::Render::TreeCacheRoot *pRoot; // rcx
  int v8; // eax
  Scaleform::Render::TreeCacheShapeLayer *pNext; // rbx
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // rdi
  __int64 v11; // rax
  Scaleform::Render::TreeNode *pNode; // rcx

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
  if ( (changeBits & 0x10) != 0 )
  {
    pRoot = this->pRoot;
    if ( pRoot )
    {
      v8 = 1;
      if ( (this->UpdateFlags & 0x80000000) == 0 )
      {
        this->pNextUpdate = pRoot->pUpdateList;
        pRoot->pUpdateList = this;
        v8 = -2147483647;
      }
      this->UpdateFlags |= v8;
      pNext = (Scaleform::Render::TreeCacheShapeLayer *)this->Children.Root.pNext;
      p_Children = &this->Children;
      while ( 1 )
      {
        v11 = p_Children ? (__int64)&p_Children[-1].Root.8 : 0i64;
        if ( pNext == (Scaleform::Render::TreeCacheShapeLayer *)v11 )
          break;
        pNode = pNext->pNode;
        if ( !pNode )
          pNode = pNext->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
        if ( *(_BYTE *)(*(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                               + 8i64
                                               * (unsigned int)((int)((_DWORD)pNode
                                                                    - ((unsigned int)pNode & 0xFFFFF000)
                                                                    - 56)
                                                              / 56)
                                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                  + 144)
                      + 128i64) )
          Scaleform::Render::TreeCacheShapeLayer::updateSortKey(pNext);
        pNext = (Scaleform::Render::TreeCacheShapeLayer *)pNext->pNext;
      }
    }
  }
}

// File Line: 368
// RVA: 0x9BD910
void __fastcall Scaleform::Render::TreeCacheShape::UpdateChildSubtree(
        Scaleform::Render::TreeCacheShape *this,
        Scaleform::Render::TreeNode::NodeData *pdata,
        unsigned __int16 depth)
{
  Scaleform::Render::ShapeMeshProvider *vfptr; // r13
  unsigned int v7; // r15d
  float *p_x2; // rax
  unsigned int v9; // ebx
  Scaleform::Render::TreeCacheNode *i; // r14
  Scaleform::Render::TreeCacheNode *v11; // rax
  Scaleform::Render::TreeCacheNode *v12; // rbp
  Scaleform::Render::TreeCacheNode *j; // rcx
  float *v14; // rax

  Scaleform::Render::TreeCacheNode::UpdateChildSubtree(this, pdata, depth);
  vfptr = (Scaleform::Render::ShapeMeshProvider *)pdata[1].vfptr;
  v7 = vfptr->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->GetLayerCount(&vfptr->Scaleform::Render::MeshProvider);
  p_x2 = &this->SortParentBounds.x2;
  if ( this == (Scaleform::Render::TreeCacheShape *)-112i64 )
    p_x2 = 0i64;
  if ( (float *)this->Children.Root.pNext == p_x2 )
  {
    v9 = 0;
    for ( i = this->Children.Root.pNext->Scaleform::Render::TreeCacheContainer::pPrev; v9 < v7; ++v9 )
    {
      v11 = (Scaleform::Render::TreeCacheNode *)Scaleform::Render::TreeCacheShapeLayer::Create(
                                                  this,
                                                  vfptr,
                                                  v9,
                                                  this->Flags & 0xC | 1u,
                                                  0i64,
                                                  *(float *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64)
                                                                                    + 0x28)
                                                                        + 8i64
                                                                        * (unsigned int)((int)(LODWORD(this->pNode)
                                                                                             - ((__int64)this->pNode & 0xFFFFF000)
                                                                                             - 56)
                                                                                       / 56)
                                                                        + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                                           + 152));
      v12 = v11;
      if ( v11 )
      {
        Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(v11, this, i, 0i64, depth);
        i = v12;
      }
    }
  }
  else
  {
    for ( j = this->Children.Root.pNext; ; j = j->pNext )
    {
      v14 = &this->SortParentBounds.x2;
      if ( this == (Scaleform::Render::TreeCacheShape *)-112i64 )
        v14 = 0i64;
      if ( j == (Scaleform::Render::TreeCacheNode *)v14 )
        break;
      j->Depth = depth;
      j->pRoot = this->pRoot;
    }
  }
}

// File Line: 415
// RVA: 0x94D8C0
void __fastcall Scaleform::Render::TreeCacheShapeLayer::~TreeCacheShapeLayer(
        Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::Image *pObject; // rcx
  Scaleform::Render::MeshKey *v3; // rbx
  Scaleform::Render::MeshBase *v5; // rcx

  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheShapeLayer::`vftable;
  pObject = this->pGradient.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::Image *))pObject->vfptr[2].__vecDelDtor)(pObject);
  v3 = this->pMeshKey.pObject;
  if ( v3 )
  {
    if ( v3->UseCount-- == 1 )
    {
      v5 = v3->pMesh.pObject;
      if ( !v5
        || ((unsigned __int8 (__fastcall *)(Scaleform::Render::MeshBase *))v5->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(v5)
        || (v3->Flags & 0x110) != 0 )
      {
        Scaleform::Render::MeshKeySet::DestroyKey(v3->pKeySet, v3);
      }
    }
  }
  Scaleform::Render::TreeCacheMeshBase::~TreeCacheMeshBase(this);
}

// File Line: 423
// RVA: 0x965E40
Scaleform::Render::Image *__fastcall Scaleform::Render::TreeCacheShapeLayer::Create(
        Scaleform::Render::TreeCacheNode *pparent,
        Scaleform::Render::ShapeMeshProvider *provider,
        unsigned int drawLayer,
        unsigned int flags,
        Scaleform::Render::TreeShape *shapeNode,
        float morphRatio)
{
  unsigned __int16 v6; // bp
  Scaleform::Render::Image *v9; // rsi
  Scaleform::Render::Image *v10; // rax
  Scaleform::Render::Image *v11; // rdi
  Scaleform::Render::Image *pObject; // rbx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rcx
  int v15; // [rsp+40h] [rbp-48h] BYREF
  Scaleform::Ptr<Scaleform::Render::Image> v16[3]; // [rsp+48h] [rbp-40h] BYREF
  Scaleform::Render::SortKey key; // [rsp+60h] [rbp-28h] BYREF

  v16[1].pObject = (Scaleform::Render::Image *)-2i64;
  v6 = flags;
  v9 = 0i64;
  v16[0].pObject = 0i64;
  Scaleform::Render::TreeCacheShapeLayer::CreateSortKey(&key, pparent, provider, drawLayer, flags, v16, morphRatio);
  v15 = 71;
  v10 = (Scaleform::Render::Image *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                      Scaleform::Memory::pGlobalHeap,
                                      pparent,
                                      224i64,
                                      &v15);
  v11 = v10;
  v16[2].pObject = v10;
  if ( v10 )
  {
    Scaleform::Render::TreeCacheMeshBase::TreeCacheMeshBase(
      (Scaleform::Render::TreeCacheMeshBase *)v10,
      shapeNode,
      &key,
      pparent->pRenderer2D,
      v6);
    v11->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TreeCacheShapeLayer::`vftable;
    v11[4].pInverseMatrix = 0i64;
    v11[5].vfptr = 0i64;
    LOBYTE(v11[5].RefCount) = key.pImpl->Type == SortKey_MeshProvider;
    *((_DWORD *)&v11[5].RefCount + 1) = drawLayer;
  }
  else
  {
    v11 = 0i64;
  }
  pObject = v16[0].pObject;
  if ( v11 )
  {
    if ( v16[0].pObject )
      ((void (__fastcall *)(Scaleform::Render::Image *))v16[0].pObject->vfptr[1].__vecDelDtor)(v16[0].pObject);
    vfptr = v11[5].vfptr;
    if ( vfptr )
      (*((void (__fastcall **)(Scaleform::RefCountImplCoreVtbl *))vfptr->__vecDelDtor + 2))(vfptr);
    v11[5].vfptr = (Scaleform::RefCountImplCoreVtbl *)pObject;
    v9 = v11;
  }
  key.pImpl->vfptr->Release(key.pImpl, key.Data);
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::Image *))pObject->vfptr[2].__vecDelDtor)(pObject);
  return v9;
}

// File Line: 441
// RVA: 0x9694C0
Scaleform::Render::SortKey *__fastcall Scaleform::Render::TreeCacheShapeLayer::CreateSortKey(
        Scaleform::Render::SortKey *result,
        Scaleform::Render::TreeCacheNode *refNode,
        Scaleform::Render::ShapeMeshProvider *provider,
        unsigned int drawLayer,
        __int16 flags,
        Scaleform::Ptr<Scaleform::Render::Image> *gradientImage)
{
  unsigned int v9; // ebp
  Scaleform::Render::TreeCacheNode *v10; // rcx
  char v11; // si
  Scaleform::Render::MeshProvider *v12; // r15
  Scaleform::Render::SKI_ComplexPrimitive *v13; // rcx
  Scaleform::Render::SortKeyInterfaceVtbl *vfptr; // rax
  Scaleform::Render::TextureManager *v15; // rbx
  Scaleform::Render::Renderer2DImpl *pRenderer2D; // rdi
  Scaleform::Render::PrimitiveFill *v17; // rbx
  Scaleform::Render::FillData initdata; // [rsp+40h] [rbp-58h] BYREF

  v9 = (flags & 0xC) == 4;
  if ( (flags & 0x40) != 0 )
    v9 = 2;
  if ( (flags & 0x80u) != 0 )
    v9 |= 8u;
  v10 = refNode;
  v11 = (flags & 0x200) != 0;
  do
  {
    v11 |= (v10->Flags & 0x200) != 0;
    v10 = v10->pParent;
  }
  while ( v10 && !v11 );
  v12 = &provider->Scaleform::Render::MeshProvider;
  if ( provider->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->GetFillCount(
         &provider->Scaleform::Render::MeshProvider,
         drawLayer,
         v9) <= 1 )
  {
    v15 = (Scaleform::Render::TextureManager *)((__int64 (__fastcall *)(Scaleform::Render::HAL *))refNode->pRenderer2D->pHal.pObject->vfptr[61].__vecDelDtor)(refNode->pRenderer2D->pHal.pObject);
    pRenderer2D = refNode->pRenderer2D;
    initdata.Type = Fill_VColor;
    initdata.Color = 0;
    initdata.PrimFill = PrimFill_VColor_EAlpha;
    initdata.FillMode.Fill = 0;
    initdata.pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
    v12->vfptr->GetFillData(v12, &initdata, drawLayer, 0, v9);
    v17 = Scaleform::Render::PrimitiveFillManager::CreateFill(&pRenderer2D->FillManager, &initdata, gradientImage, v15);
    result->Data = v17;
    if ( v11 )
    {
      result->pImpl = &Scaleform::Render::SKI_Primitive::Instance3D;
      Scaleform::Render::SKI_Primitive::Instance3D.vfptr->AddRef(&Scaleform::Render::SKI_Primitive::Instance3D, v17);
    }
    else
    {
      result->pImpl = &Scaleform::Render::SKI_Primitive::Instance;
      Scaleform::Render::SKI_Primitive::Instance.vfptr->AddRef(&Scaleform::Render::SKI_Primitive::Instance, v17);
    }
    if ( v17 )
    {
      if ( v17->RefCount-- == 1 )
        v17->vfptr->__vecDelDtor(v17, 1u);
    }
  }
  else
  {
    result->Data = v12;
    if ( v11 )
    {
      v13 = &Scaleform::Render::SKI_ComplexPrimitive::Instance3D;
      result->pImpl = &Scaleform::Render::SKI_ComplexPrimitive::Instance3D;
      vfptr = Scaleform::Render::SKI_ComplexPrimitive::Instance3D.vfptr;
    }
    else
    {
      v13 = &Scaleform::Render::SKI_ComplexPrimitive::Instance;
      result->pImpl = &Scaleform::Render::SKI_ComplexPrimitive::Instance;
      vfptr = Scaleform::Render::SKI_ComplexPrimitive::Instance.vfptr;
    }
    vfptr->AddRef(v13, v12);
  }
  return result;
}

// File Line: 474
// RVA: 0x9FA700
void __fastcall Scaleform::Render::TreeCacheShapeLayer::updateSortKey(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeNode *pNode; // r9
  Scaleform::Render::SortKey *v3; // rbx
  Scaleform::Render::MeshKey *pObject; // rbx
  Scaleform::Render::MeshBase *v6; // rcx
  Scaleform::Render::TreeCacheRoot *pRoot; // rcx
  Scaleform::Render::TreeCacheNode *pParent; // rdx
  Scaleform::Render::SortKey result; // [rsp+48h] [rbp-20h] BYREF

  Scaleform::Render::BundleEntry::ClearBundle(&this->SorterShapeNode);
  pNode = this->pNode;
  if ( !pNode )
    pNode = this->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
  v3 = Scaleform::Render::TreeCacheShapeLayer::CreateSortKey(
         &result,
         this,
         *(Scaleform::Render::ShapeMeshProvider **)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64)
                                                                           + 0x28)
                                                               + 8i64
                                                               * (unsigned int)((int)((_DWORD)pNode
                                                                                    - ((unsigned int)pNode & 0xFFFFF000)
                                                                                    - 56)
                                                                              / 56)
                                                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                                  + 144),
         this->Layer,
         this->Flags,
         &this->pGradient);
  v3->pImpl->vfptr->AddRef(v3->pImpl, v3->Data);
  this->SorterShapeNode.Key.pImpl->vfptr->Release(this->SorterShapeNode.Key.pImpl, this->SorterShapeNode.Key.Data);
  this->SorterShapeNode.Key = *v3;
  result.pImpl->vfptr->Release(result.pImpl, result.Data);
  this->ComplexShape = this->SorterShapeNode.Key.pImpl->Type == SortKey_MeshProvider;
  pObject = this->pMeshKey.pObject;
  if ( pObject )
  {
    if ( pObject->UseCount-- == 1 )
    {
      v6 = pObject->pMesh.pObject;
      if ( !v6
        || ((unsigned __int8 (__fastcall *)(Scaleform::Render::MeshBase *))v6->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(v6)
        || (pObject->Flags & 0x110) != 0 )
      {
        Scaleform::Render::MeshKeySet::DestroyKey(pObject->pKeySet, pObject);
      }
    }
  }
  this->pMeshKey.pObject = 0i64;
  pRoot = this->pRoot;
  if ( pRoot )
  {
    pParent = this->pParent;
    if ( pParent )
      Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(pRoot, pParent, 0x1000001u);
  }
}

// File Line: 489
// RVA: 0x9FA8D0
void __fastcall Scaleform::Render::TreeCacheShapeLayer::updateSortKeyGradientMorph(
        Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeNode *pNode; // rdx
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rdx

  pNode = this->pNode;
  if ( !pNode )
    pNode = this->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
  v2 = (unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64;
  v3 = (__int64)((unsigned __int128)((__int64)((__int64)&pNode[-1] - ((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64))
                                   * (__int128)0x4924924924924925i64) >> 64) >> 4;
  if ( *(_BYTE *)(*(_QWORD *)((*(_QWORD *)(*(_QWORD *)(v2 + 40) + 8 * ((unsigned int)v3 + (v3 >> 63)) + 40) & 0xFFFFFFFFFFFFFFFEui64)
                            + 144)
                + 128i64) )
    Scaleform::Render::TreeCacheShapeLayer::updateSortKey(this);
}

// File Line: 495
// RVA: 0x9FAB40
void __fastcall Scaleform::Render::TreeCacheShapeLayer::updateTexture0Matrix(
        Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::Bundle *pObject; // rax
  Scaleform::Render::ShapeMeshProvider *MeshProvider; // rax
  unsigned __int16 Flags; // dx
  int v5; // ecx
  Scaleform::Render::Matrix2x4<float> m; // [rsp+30h] [rbp-28h] BYREF

  if ( !this->ComplexShape )
  {
    pObject = this->SorterShapeNode.pBundle.pObject;
    if ( pObject )
    {
      if ( *(_QWORD *)(*(_QWORD *)&pObject[1].NeedUpdate + 32i64) )
      {
        *(_OWORD *)&m.M[0][0] = _xmm;
        *(__m128 *)&m.M[1][0] = _xmm;
        MeshProvider = Scaleform::Render::TreeCacheShapeLayer::GetMeshProvider(this);
        Flags = this->Flags;
        if ( (Flags & 0x40) != 0 )
          v5 = 2;
        else
          v5 = (Flags & 0xC) == 4;
        if ( (Flags & 0x80u) != 0 )
          v5 |= 8u;
        MeshProvider->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->GetFillMatrix(
          &MeshProvider->Scaleform::Render::MeshProvider,
          this->pMeshKey.pObject->pMesh.pObject,
          &m,
          this->Layer,
          0,
          v5);
        Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(&this->M, &m, 0);
      }
    }
  }
}

// File Line: 517
// RVA: 0x9E3340
void __fastcall Scaleform::Render::TreeCacheShapeLayer::forceUpdateImages(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeNode *pNode; // rcx
  Scaleform::Render::SortKeyInterface *pImpl; // rcx
  Scaleform::Render::MeshKey *pObject; // rdi
  Scaleform::Render::MeshBase *v7; // rcx
  Scaleform::Render::TreeCacheRoot *pRoot; // rdx
  Scaleform::Render::TreeCacheNode *pParent; // rcx
  int v10; // eax
  Scaleform::Render::SortKey result; // [rsp+48h] [rbp-20h] BYREF

  if ( this->pNode )
    pNode = this->pNode;
  else
    pNode = this->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
  Scaleform::Render::TreeCacheShapeLayer::CreateSortKey(
    &result,
    this,
    *(Scaleform::Render::ShapeMeshProvider **)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64)
                                                                      + 0x28)
                                                          + 8i64
                                                          * (unsigned int)((int)((_DWORD)pNode
                                                                               - ((unsigned int)pNode & 0xFFFFF000)
                                                                               - 56)
                                                                         / 56)
                                                          + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                             + 144),
    this->Layer,
    this->Flags,
    &this->pGradient);
  if ( result.pImpl == this->SorterShapeNode.Key.pImpl && result.Data == this->SorterShapeNode.Key.Data )
  {
    if ( this->pMeshKey.pObject )
      Scaleform::Render::TreeCacheShapeLayer::updateTexture0Matrix(this);
  }
  else
  {
    Scaleform::Render::BundleEntry::ClearBundle(&this->SorterShapeNode);
    result.pImpl->vfptr->AddRef(result.pImpl, result.Data);
    this->SorterShapeNode.Key.pImpl->vfptr->Release(this->SorterShapeNode.Key.pImpl, this->SorterShapeNode.Key.Data);
    pImpl = result.pImpl;
    this->SorterShapeNode.Key = result;
    this->ComplexShape = pImpl->Type == SortKey_MeshProvider;
    pObject = this->pMeshKey.pObject;
    if ( pObject )
    {
      if ( pObject->UseCount-- == 1 )
      {
        v7 = pObject->pMesh.pObject;
        if ( !v7
          || ((unsigned __int8 (__fastcall *)(Scaleform::Render::MeshBase *))v7->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(v7)
          || (pObject->Flags & 0x110) != 0 )
        {
          Scaleform::Render::MeshKeySet::DestroyKey(pObject->pKeySet, pObject);
        }
      }
    }
    this->pMeshKey.pObject = 0i64;
    pRoot = this->pRoot;
    if ( pRoot )
    {
      pParent = this->pParent;
      if ( pParent )
      {
        v10 = 16778241;
        if ( (pParent->UpdateFlags & 0x80000000) == 0 )
        {
          pParent->pNextUpdate = pRoot->pUpdateList;
          pRoot->pUpdateList = pParent;
          v10 = -2130705407;
        }
        pParent->UpdateFlags |= v10;
      }
    }
  }
  result.pImpl->vfptr->Release(result.pImpl, result.Data);
}

// File Line: 551
// RVA: 0x990780
void __fastcall Scaleform::Render::TreeCacheShapeLayer::HandleChanges(
        Scaleform::Render::TreeCacheShapeLayer *this,
        char changeBits)
{
  Scaleform::Render::TreeCacheNode *pParent; // rcx
  unsigned int v5; // r8d
  __int64 v6; // rdx
  Scaleform::Render::TreeCacheRoot *pRoot; // rcx
  int v8; // eax

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
  if ( (changeBits & 0x10) != 0 )
  {
    pRoot = this->pRoot;
    if ( pRoot )
    {
      v8 = 1;
      if ( (this->UpdateFlags & 0x80000000) == 0 )
      {
        this->pNextUpdate = pRoot->pUpdateList;
        pRoot->pUpdateList = this;
        v8 = -2147483647;
      }
      this->UpdateFlags |= v8;
      Scaleform::Render::TreeCacheShapeLayer::updateSortKeyGradientMorph(this);
    }
  }
}

// File Line: 569
// RVA: 0x9BDA80
void __fastcall Scaleform::Render::TreeCacheShapeLayer::UpdateChildSubtree(
        Scaleform::Render::TreeCacheShapeLayer *this,
        Scaleform::Render::TreeNode::NodeData *data,
        unsigned __int16 depth)
{
  int Flags; // ebp
  int v7; // ebx

  Flags = this->Flags;
  v7 = Flags & 0xFFBF | ((unsigned __int8)(2 * (this->Flags & 0x20)) | (unsigned __int8)this->pParent->Flags) & 0xC0;
  if ( data )
  {
    if ( Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::Scale9State>(data) )
      v7 |= 0x80u;
    if ( (data->Flags & 0x200) != 0 )
      v7 |= 0x200u;
  }
  if ( v7 != Flags )
  {
    this->Flags = v7;
    Scaleform::Render::TreeCacheShapeLayer::updateSortKey(this);
  }
  if ( data )
    Scaleform::Render::TreeCacheNode::updateMaskCache(this, data, depth, 1);
}

// File Line: 593
// RVA: 0x9D3A40
__int64 __fastcall Scaleform::Render::TreeCacheShapeLayer::calcMeshKey(
        Scaleform::Render::TreeCacheShapeLayer *this,
        Scaleform::Render::ShapeMeshProvider *pmeshProvider,
        Scaleform::Render::Matrix2x4<float> *m,
        unsigned int drawLayer,
        float *keyData,
        Scaleform::Render::Scale9GridData *s9g,
        float morphRatio)
{
  unsigned int v7; // ebx
  unsigned int v11; // r14d
  Scaleform::Render::TreeCacheShapeLayer *pParent; // r11
  __m128 v13; // xmm6
  __m128 v14; // xmm7
  __m128 si128; // xmm8
  __m128 v16; // xmm9
  unsigned __int64 v17; // rbx
  __int64 v18; // r8
  unsigned __int64 v19; // rcx
  __int64 v20; // rax
  unsigned __int64 v21; // rax
  _QWORD *v22; // rdx
  __int64 v23; // rax
  Scaleform::Render::TreeCacheShapeLayer *v24; // r10
  Scaleform::Render::TreeCacheShapeLayer *v25; // rax
  unsigned __int64 v26; // rax
  unsigned __int64 v27; // rcx
  _QWORD *v28; // rdx
  __m128 v29; // xmm0
  float *v30; // rax
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  Scaleform::Render::StateBag *v37; // rax
  float *pData; // rax
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // eax
  __int64 v43; // rsi
  bool v44; // di
  unsigned int StrokeStyle; // edx
  Scaleform::Render::DashArray *pObject; // rcx
  Scaleform::Render::ComplexFill *v47; // rcx
  Scaleform::Render::TreeNode *pNode; // rcx
  Scaleform::Render::Matrix2x4<float> v50; // [rsp+30h] [rbp-B8h]
  Scaleform::Render::StrokeStyleType s1; // [rsp+50h] [rbp-98h] BYREF

  v7 = drawLayer;
  v11 = 1;
  if ( SLOBYTE(this->Flags) >= 0 )
    goto LABEL_45;
  pParent = this;
  if ( !this->pNode )
    pParent = (Scaleform::Render::TreeCacheShapeLayer *)this->pParent;
  v13 = (__m128)_xmm;
  *(_OWORD *)&v50.M[0][0] = _xmm;
  v14 = _xmm;
  *(__m128 *)&v50.M[1][0] = _xmm;
  if ( !pParent )
    goto LABEL_45;
  si128 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
  v16 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
  while ( 1 )
  {
    v17 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)pParent->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                    + 8i64
                    * (unsigned int)((int)(LODWORD(pParent->pNode) - ((__int64)pParent->pNode & 0xFFFFF000) - 56) / 56)
                    + 40) & 0xFFFFFFFFFFFFFFFEui64;
    v18 = v17 + 64;
    v19 = *(_QWORD *)(v17 + 64);
    if ( !v19 )
      goto LABEL_18;
    if ( (v19 & 1) != 0 )
    {
      if ( (v19 & 0xFFFFFFFFFFFFFFFEui64) != qword_142451A80 )
        goto LABEL_18;
      v20 = v17 + 64;
    }
    else
    {
      v21 = 0i64;
      if ( !(v19 >> 1) )
        goto LABEL_18;
      v22 = (_QWORD *)(*(_QWORD *)(v17 + 72) + 4i64);
      while ( *v22 != qword_142451A80 )
      {
        ++v21;
        v22 += 2;
        if ( v21 >= v19 >> 1 )
          goto LABEL_18;
      }
      v20 = *(_QWORD *)(v17 + 72) + 4i64 + 16 * v21;
    }
    if ( !v20 )
    {
LABEL_18:
      v23 = 0i64;
      goto LABEL_19;
    }
    v23 = *(_QWORD *)(v20 + 8);
LABEL_19:
    v24 = 0i64;
    if ( v23 )
    {
      v25 = *(Scaleform::Render::TreeCacheShapeLayer **)(v23 + 24);
      if ( v25 != (Scaleform::Render::TreeCacheShapeLayer *)2989 )
        v24 = v25;
    }
    if ( !v19 )
      goto LABEL_33;
    if ( (v19 & 1) == 0 )
      break;
    if ( (v19 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A50 )
      goto LABEL_32;
LABEL_33:
    v29 = v13;
    v13 = _mm_and_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v17 + 16), *(__m128 *)(v17 + 16), 0), v13),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v17 + 16), *(__m128 *)(v17 + 16), 85), v14)),
              _mm_and_ps(*(__m128 *)(v17 + 16), si128)),
            v16);
    *(__m128 *)&v50.M[0][0] = v13;
    v14 = _mm_and_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v17 + 32), *(__m128 *)(v17 + 32), 0), v29),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v17 + 32), *(__m128 *)(v17 + 32), 85), v14)),
              _mm_and_ps(*(__m128 *)(v17 + 32), si128)),
            v16);
    *(__m128 *)&v50.M[1][0] = v14;
    if ( v24 )
      pParent = v24;
    else
      pParent = (Scaleform::Render::TreeCacheShapeLayer *)pParent->pParent;
    if ( !pParent )
      goto LABEL_44;
  }
  v26 = 0i64;
  v27 = v19 >> 1;
  if ( !v27 )
    goto LABEL_33;
  v28 = (_QWORD *)(*(_QWORD *)(v17 + 72) + 4i64);
  while ( *v28 != qword_142451A50 )
  {
    ++v26;
    v28 += 2;
    if ( v26 >= v27 )
      goto LABEL_33;
  }
  v18 = *(_QWORD *)(v17 + 72) + 4i64 + 16 * v26;
LABEL_32:
  if ( !v18 )
    goto LABEL_33;
  v30 = *(float **)(v18 + 8);
  v31 = v30[7];
  v32 = v30[6];
  v33 = v30[5];
  s9g->S9Rect.x1 = v30[4];
  s9g->S9Rect.y1 = v33;
  s9g->S9Rect.x2 = v32;
  s9g->S9Rect.y2 = v31;
  v34 = *(float *)(v17 + 124);
  v35 = *(float *)(v17 + 120);
  v36 = *(float *)(v17 + 116);
  s9g->Bounds.x1 = *(float *)(v17 + 112);
  s9g->Bounds.y1 = v36;
  s9g->Bounds.x2 = v35;
  s9g->Bounds.y2 = v34;
  s9g->ShapeMtx = v50;
  s9g->Scale9Mtx = *(Scaleform::Render::Matrix2x4<float> *)(v17 + 16);
  s9g->ViewMtx = *m;
  v37 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::OrigNodeBoundsState>((Scaleform::Render::TreeNode::NodeData *)v17);
  if ( v37 )
  {
    pData = (float *)v37->pData;
    if ( pData )
      pData += 4;
    v39 = pData[3];
    v40 = pData[2];
    v41 = pData[1];
    v42 = *pData;
  }
  else
  {
    v39 = *(float *)(v17 + 124);
    v40 = *(float *)(v17 + 120);
    v41 = *(float *)(v17 + 116);
    v42 = *(float *)(v17 + 112);
  }
  s9g->Bounds.y2 = v39;
  s9g->Bounds.x2 = v40;
  s9g->Bounds.y1 = v41;
  s9g->Bounds.x1 = v42;
  v11 = 17;
LABEL_44:
  v7 = drawLayer;
LABEL_45:
  v43 = 3i64;
  if ( (v11 & 0x10) != 0 )
  {
    Scaleform::Render::Scale9GridData::MakeMeshKey(s9g, keyData);
  }
  else
  {
    v44 = Scaleform::Render::MeshKey::CalcMatrixKey(m, keyData, 0i64);
    StrokeStyle = pmeshProvider->DrawLayers.Data.Data[v7].StrokeStyle;
    if ( StrokeStyle )
    {
      v11 = 2;
      s1.pFill.pObject = 0i64;
      s1.pDashes.pObject = 0i64;
      Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(pmeshProvider, StrokeStyle, &s1, 0.0);
      if ( (s1.Flags & 1) != 0 )
        v11 = 3;
      if ( (s1.Flags & 6) == 0 )
        v11 |= 0x20u;
      pObject = s1.pDashes.pObject;
      if ( s1.pDashes.pObject && !_InterlockedDecrement(&s1.pDashes.pObject->RefCount) && pObject )
        pObject->vfptr->__vecDelDtor(pObject, 1u);
      v47 = s1.pFill.pObject;
      if ( s1.pFill.pObject && !_InterlockedDecrement(&s1.pFill.pObject->RefCount) && v47 )
        v47->vfptr->__vecDelDtor(v47, 1u);
    }
    if ( !v44 )
      v11 |= 0x8000u;
  }
  pNode = this->pNode;
  if ( !pNode )
    pNode = this->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
  if ( *(_BYTE *)(*(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                         + 8i64
                                         * (unsigned int)((int)((_DWORD)pNode - ((unsigned int)pNode & 0xFFFFF000) - 56)
                                                        / 56)
                                         + 40) & 0xFFFFFFFFFFFFFFFEui64)
                            + 144)
                + 128i64) )
    v11 |= 0x100u;
  if ( (v11 & 0x10) != 0 )
    v43 = 13i64;
  keyData[v43] = morphRatio;
  return v11;
}

// File Line: 677
// RVA: 0x9FA090
char __fastcall Scaleform::Render::TreeCacheShapeLayer::updateMeshKey(
        Scaleform::Render::TreeCacheShapeLayer *this,
        Scaleform::Render::Renderer2DImpl *r2D,
        Scaleform::Render::ShapeMeshProvider *provider,
        float morphRatio,
        Scaleform::Render::Matrix2x4<float> *viewMatrix,
        unsigned int meshGenFlags,
        unsigned int *meshKeyFlags)
{
  Scaleform::Render::Renderer2DImpl *v7; // r15
  Scaleform::Render::ToleranceParams *p_Tolerances; // rdi
  unsigned int Layer; // r13d
  Scaleform::Render::Scale9GridData *v11; // rsi
  int v12; // ebx
  unsigned int v13; // r12d
  Scaleform::Render::MeshKey *pObject; // rbx
  Scaleform::Render::MeshKeySet *pKeySet; // rax
  Scaleform::Render::MeshKey *pNext; // rdi
  Scaleform::List<Scaleform::Render::MeshKey,Scaleform::Render::MeshKey> *p_Meshes; // r15
  const char *v18; // rax
  const char *v19; // rbx
  Scaleform::Render::MeshKey *MatchingKey; // rax
  Scaleform::Render::ComplexMesh *v21; // rax
  Scaleform::Render::MeshBase *v22; // rax
  Scaleform::Render::MeshBase *v23; // r15
  Scaleform::Render::Mesh *v24; // rax
  Scaleform::Render::MeshBase *v25; // rax
  Scaleform::Render::MeshBase *v26; // rcx
  bool v27; // zf
  Scaleform::Render::Scale9GridData *v29; // rax
  Scaleform::Render::Scale9GridData *v30; // rax
  Scaleform::Render::MeshKey *v31; // rbx
  Scaleform::Render::MeshBase *v32; // rcx
  int v33; // [rsp+40h] [rbp-C0h] BYREF
  int v34; // [rsp+44h] [rbp-BCh] BYREF
  int v35; // [rsp+48h] [rbp-B8h] BYREF
  __int64 v36; // [rsp+50h] [rbp-B0h]
  Scaleform::Render::Scale9GridData *v37; // [rsp+58h] [rbp-A8h]
  __int64 v38; // [rsp+60h] [rbp-A0h]
  float keyData[20]; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::Render::Scale9GridData __that; // [rsp+C0h] [rbp-40h] BYREF
  unsigned int *meshKeyFlagsa; // [rsp+1D0h] [rbp+D0h]

  v36 = -2i64;
  v7 = r2D;
  p_Tolerances = &r2D->Tolerances;
  Layer = this->Layer;
  v11 = 0i64;
  v12 = 0;
  if ( (meshGenFlags & 1) != 0 )
    v12 = 64;
  if ( (meshGenFlags & 2) != 0 )
    v12 |= 0x80u;
  __that.RefCount = 1;
  __that.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Scale9GridData::`vftable;
  v13 = v12 | Scaleform::Render::TreeCacheShapeLayer::calcMeshKey(
                this,
                provider,
                viewMatrix,
                Layer,
                keyData,
                &__that,
                morphRatio);
  if ( meshKeyFlags )
    *meshKeyFlags = v13;
  pObject = this->pMeshKey.pObject;
  if ( !pObject )
  {
    MatchingKey = Scaleform::Render::MeshKeyManager::CreateMatchingKey(
                    v7->pMeshKeyManager.pObject,
                    provider,
                    Layer,
                    v13,
                    keyData,
                    p_Tolerances);
    goto LABEL_16;
  }
  if ( Scaleform::Render::MeshKey::Match(pObject, Layer, v13, keyData, p_Tolerances) )
    return 0;
  pKeySet = pObject->pKeySet;
  meshKeyFlagsa = (unsigned int *)pKeySet;
  pNext = pKeySet->Meshes.Root.pNext;
  p_Meshes = &pKeySet->Meshes;
  if ( pNext == (Scaleform::Render::MeshKey *)&pKeySet->Meshes )
  {
LABEL_14:
    MatchingKey = Scaleform::Render::MeshKeySet::CreateKey(pKeySet, keyData, v13);
    v7 = r2D;
LABEL_16:
    pNext = MatchingKey;
    goto LABEL_17;
  }
  while ( 1 )
  {
    v18 = (const char *)pNext->pMesh.pObject;
    _mm_prefetch(v18 + 128, 2);
    _mm_prefetch(v18 + 96, 2);
    _mm_prefetch(v18 + 64, 2);
    _mm_prefetch(v18 + 32, 2);
    _mm_prefetch(v18, 2);
    v19 = (const char *)pNext->pNext;
    _mm_prefetch(v19 + 32, 2);
    _mm_prefetch(v19, 2);
    if ( Scaleform::Render::MeshKey::Match(pNext, Layer, v13, keyData, &r2D->Tolerances) )
      break;
    pNext = (Scaleform::Render::MeshKey *)v19;
    if ( v19 == (const char *)p_Meshes )
    {
      pKeySet = (Scaleform::Render::MeshKeySet *)meshKeyFlagsa;
      goto LABEL_14;
    }
  }
  ++pNext->UseCount;
  v7 = r2D;
LABEL_17:
  if ( !pNext )
    return 0;
  if ( !pNext->pMesh.pObject )
  {
    v38 = 0i64;
    if ( this->ComplexShape )
    {
      v34 = 68;
      v21 = (Scaleform::Render::ComplexMesh *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                320i64,
                                                &v34);
      if ( v21 )
      {
        Scaleform::Render::ComplexMesh::ComplexMesh(
          v21,
          v7,
          pNext->pKeySet,
          &v7->FillManager,
          viewMatrix,
          morphRatio,
          Layer,
          meshGenFlags);
        v23 = v22;
      }
      else
      {
        v23 = 0i64;
      }
    }
    else
    {
      v33 = 68;
      v24 = (Scaleform::Render::Mesh *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         240i64,
                                         &v33);
      if ( v24 )
      {
        Scaleform::Render::Mesh::Mesh(v24, v7, pNext->pKeySet, viewMatrix, morphRatio, Layer, meshGenFlags);
        v23 = v25;
      }
      else
      {
        v23 = 0i64;
      }
    }
    v26 = pNext->pMesh.pObject;
    if ( v26 && !_InterlockedDecrement(&v26->RefCount) )
      v26->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
        v26,
        1u);
    pNext->pMesh.pObject = v23;
    if ( !v23 )
    {
      v27 = pNext->UseCount-- == 1;
      if ( v27 )
        Scaleform::Render::MeshKeySet::DestroyKey(pNext->pKeySet, pNext);
      return 0;
    }
    if ( (v13 & 0x10) != 0 )
    {
      v35 = 2;
      v29 = (Scaleform::Render::Scale9GridData *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   this,
                                                   144i64,
                                                   &v35);
      if ( v29 )
      {
        Scaleform::Render::Scale9GridData::Scale9GridData(v29, &__that);
        v11 = v30;
      }
      v37 = v11;
      Scaleform::Render::MeshBase::SetScale9Grid(pNext->pMesh.pObject, v11);
      if ( v11 && !_InterlockedDecrement(&v11->RefCount) )
        v11->vfptr->__vecDelDtor(v11, 1u);
    }
  }
  v31 = this->pMeshKey.pObject;
  if ( v31 )
  {
    v27 = v31->UseCount-- == 1;
    if ( v27 )
    {
      v32 = v31->pMesh.pObject;
      if ( !v32
        || ((unsigned __int8 (__fastcall *)(Scaleform::Render::MeshBase *))v32->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(v32)
        || (v31->Flags & 0x110) != 0 )
      {
        Scaleform::Render::MeshKeySet::DestroyKey(v31->pKeySet, v31);
      }
    }
  }
  this->pMeshKey.pObject = pNext;
  return 1;
}

// File Line: 750
// RVA: 0x9E7660
void __fastcall Scaleform::Render::TreeCacheShapeLayer::getShapeMatrixFrom3D(
        Scaleform::Render::TreeCacheShapeLayer *this,
        Scaleform::Render::TreeShape::NodeData *nd,
        Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::Render::Matrix4x4<float> *viewProj)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax
  Scaleform::Render::Renderer2DImpl *pRenderer2D; // rsi
  Scaleform::Render::Matrix3x4<float> *v10; // r8
  unsigned __int64 v11; // rdx
  float v12; // xmm5_4
  __m128 v13; // xmm2
  float v14; // xmm3_4
  float v15; // xmm0_4
  __m128 v16; // xmm0
  float MinScale3D; // xmm2_4
  Scaleform::Render::Rect<float> bounds; // [rsp+30h] [rbp-98h] BYREF
  float src; // [rsp+40h] [rbp-88h] BYREF
  __int64 v20; // [rsp+44h] [rbp-84h]
  __int64 v21; // [rsp+4Ch] [rbp-7Ch]
  float y2; // [rsp+54h] [rbp-74h]
  __m128 dst[2]; // [rsp+60h] [rbp-68h] BYREF
  Scaleform::Render::Matrix4x4<float> v24; // [rsp+80h] [rbp-48h] BYREF

  nd->pMeshProvider.pObject->vfptr->GetIdentityBounds(
    &nd->pMeshProvider.pObject->Scaleform::Render::MeshProvider,
    &bounds);
  pHandle = this->M.pHandle;
  pRenderer2D = this->pRenderer2D;
  if ( (pHandle->pHeader->Format & 0x10) != 0 )
    v10 = (Scaleform::Render::Matrix3x4<float> *)&pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHandle->pHeader->Format & 0xF].Offsets[4]
                                                                 + 1];
  else
    v10 = &Scaleform::Render::Matrix3x4<float>::Identity;
  Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v24, viewProj, v10);
  v11 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pRoot->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode & 0xFFFFFFFFFFFFF000ui64)
                              + 0x28)
                  + 8i64
                  * (unsigned int)((int)(LODWORD(this->pRoot->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode)
                                       - ((__int64)this->pRoot->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode & 0xFFFFF000)
                                       - 56)
                                 / 56)
                  + 40) & 0xFFFFFFFFFFFFFFFEui64;
  Scaleform::Render::Matrix4x4<float>::TransformHomogeneousAndScaleCorners(
    &v24,
    (__m128 *)&bounds,
    (float)*(int *)(v11 + 176),
    (float)*(int *)(v11 + 180),
    dst);
  src = bounds.x1;
  v20 = *(_QWORD *)&bounds.y1;
  y2 = bounds.y2;
  v21 = *(_QWORD *)&bounds.y1;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(mat, &src, dst[0].m128_f32);
  v12 = mat->M[1][1];
  v13 = (__m128)LODWORD(mat->M[1][0]);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(mat->M[0][0] * v12) - (float)(mat->M[0][1] * v13.m128_f32[0])) & _xmm) < pRenderer2D->Tolerances.MinDet3D )
  {
    v14 = mat->M[0][1] + mat->M[0][0];
    *(_QWORD *)&mat->M[0][1] = 0i64;
    *(_QWORD *)&mat->M[0][3] = 0i64;
    *(_QWORD *)&mat->M[1][2] = 0i64;
    v13.m128_f32[0] = (float)((float)((float)(v13.m128_f32[0] + v12) * 0.70710677)
                            * (float)((float)(v13.m128_f32[0] + v12) * 0.70710677))
                    + (float)((float)(v14 * 0.70710677) * (float)(v14 * 0.70710677));
    LODWORD(v15) = _mm_sqrt_ps(v13).m128_u32[0];
    mat->M[0][0] = v15;
    mat->M[1][1] = v15;
  }
  if ( nd->pMeshProvider.pObject->DrawLayers.Data.Data[this->Layer].StrokeStyle )
  {
    v16 = (__m128)LODWORD(mat->M[1][1]);
    v16.m128_f32[0] = (float)((float)((float)(v16.m128_f32[0] + mat->M[1][0]) * 0.70710677)
                            * (float)((float)(v16.m128_f32[0] + mat->M[1][0]) * 0.70710677))
                    + (float)((float)((float)(mat->M[0][1] + mat->M[0][0]) * 0.70710677)
                            * (float)((float)(mat->M[0][1] + mat->M[0][0]) * 0.70710677));
    MinScale3D = _mm_sqrt_ps(v16).m128_f32[0];
    if ( MinScale3D < pRenderer2D->Tolerances.MinScale3D )
      MinScale3D = pRenderer2D->Tolerances.MinScale3D;
    mat->M[0][0] = MinScale3D;
    mat->M[1][1] = MinScale3D;
    *(_QWORD *)&mat->M[0][1] = 0i64;
    *(_QWORD *)&mat->M[0][3] = 0i64;
    *(_QWORD *)&mat->M[1][2] = 0i64;
  }
}

// File Line: 783
// RVA: 0x9BFB90
void __fastcall Scaleform::Render::TreeCacheShapeLayer::UpdateTransform(
        Scaleform::Render::TreeCacheShapeLayer *this,
        Scaleform::Render::TreeShape::NodeData *nodeData,
        Scaleform::Render::TransformArgs *t,
        unsigned int flags)
{
  float y1; // xmm1_4
  float x1; // eax
  float x2; // xmm1_4
  float v11; // xmm0_4
  unsigned int meshGenFlags; // esi
  char v13; // r15
  Scaleform::Render::Matrix4x4<float> *ViewProj; // rax
  float v15; // xmm1_4
  float v16; // xmm0_4
  unsigned __int16 v17; // cx
  float v18; // xmm0_4
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  int v27; // ecx
  int v28; // edx
  Scaleform::Render::Bundle *pObject; // rcx
  Scaleform::Render::Matrix2x4<float> cullRect; // [rsp+40h] [rbp-30h] BYREF
  unsigned int meshKeyFlags; // [rsp+B8h] [rbp+48h] BYREF

  y1 = t->CullRect.y1;
  cullRect.M[0][0] = t->CullRect.x1;
  *(_QWORD *)&cullRect.M[0][1] = __PAIR64__(LODWORD(t->CullRect.x2), LODWORD(y1));
  cullRect.M[0][3] = t->CullRect.y2;
  Scaleform::Render::TreeCacheNode::updateCulling(
    this,
    nodeData,
    t,
    (Scaleform::Render::Rect<float> *)&cullRect,
    (Scaleform::Render::TransformFlags)(flags | 0x20));
  x1 = nodeData->AproxParentBounds.x1;
  x2 = nodeData->AproxParentBounds.x2;
  v11 = nodeData->AproxParentBounds.y1;
  this->SortParentBounds.y2 = nodeData->AproxParentBounds.y2;
  this->SortParentBounds.x1 = x1;
  this->SortParentBounds.y1 = v11;
  this->SortParentBounds.x2 = x2;
  this->Flags &= ~0x400u;
  ((void (__fastcall *)(Scaleform::Render::TreeCacheShapeLayer *, Scaleform::Render::TransformArgs *, _QWORD))this->vfptr[1].__vecDelDtor)(
    this,
    t,
    flags);
  if ( (flags & 1) != 0 && this->pMeshKey.pObject )
  {
    meshGenFlags = 0;
    v13 = 0;
    meshKeyFlags = 0;
    if ( (flags & 0x80u) != 0 && this->pRoot )
    {
      ViewProj = Scaleform::Render::TransformArgs::GetViewProj(t);
      Scaleform::Render::TreeCacheShapeLayer::getShapeMatrixFrom3D(this, nodeData, &cullRect, ViewProj);
    }
    else
    {
      v15 = t->Mat.M[0][1];
      cullRect.M[0][0] = t->Mat.M[0][0];
      *(_QWORD *)&cullRect.M[0][1] = __PAIR64__(LODWORD(t->Mat.M[0][2]), LODWORD(v15));
      v16 = t->Mat.M[1][0];
      cullRect.M[0][3] = t->Mat.M[0][3];
      *(_QWORD *)&cullRect.M[1][0] = __PAIR64__(LODWORD(t->Mat.M[1][1]), LODWORD(v16));
      *(_QWORD *)&cullRect.M[1][2] = *(_QWORD *)&t->Mat.M[1][2];
    }
    v17 = this->Flags;
    if ( (v17 & 0x40) != 0 )
    {
      meshGenFlags = 2;
    }
    else if ( (v17 & 0xC) == 4 )
    {
      meshGenFlags = 1;
    }
    if ( (v17 & 0x80u) != 0 )
      meshGenFlags |= 8u;
    if ( Scaleform::Render::TreeCacheShapeLayer::updateMeshKey(
           this,
           this->pRenderer2D,
           nodeData->pMeshProvider.pObject,
           nodeData->MorphRatio,
           &cullRect,
           meshGenFlags,
           &meshKeyFlags) )
    {
      v13 = 1;
      if ( nodeData->MorphRatio != 0.0 )
        Scaleform::Render::TreeCacheShapeLayer::updateTexture0Matrix(this);
    }
    if ( (this->M.pHandle->pHeader->Format & 0x10) == 0 && (meshKeyFlags & 7) == 3 )
    {
      v18 = t->Mat.M[0][0];
      v19 = (__m128)LODWORD(t->Mat.M[0][3]);
      v20 = (__m128)LODWORD(t->Mat.M[1][3]);
      cullRect.M[0][1] = t->Mat.M[0][1];
      v21 = t->Mat.M[1][0];
      cullRect.M[0][0] = v18;
      v22 = t->Mat.M[0][2];
      cullRect.M[1][0] = v21;
      v23 = t->Mat.M[1][2];
      cullRect.M[0][2] = v22;
      v24 = t->Mat.M[1][1];
      cullRect.M[1][2] = v23;
      v25 = FLOAT_N0_5;
      cullRect.M[1][1] = v24;
      if ( v19.m128_f32[0] >= 0.0 )
        v26 = FLOAT_0_5;
      else
        v26 = FLOAT_N0_5;
      v19.m128_f32[0] = v19.m128_f32[0] + v26;
      v27 = (int)v19.m128_f32[0];
      if ( (int)v19.m128_f32[0] != 0x80000000 && (float)v27 != v19.m128_f32[0] )
        v19.m128_f32[0] = (float)(v27 - (_mm_movemask_ps(_mm_unpacklo_ps(v19, v19)) & 1));
      LODWORD(cullRect.M[0][3]) = v19.m128_i32[0];
      if ( v20.m128_f32[0] >= 0.0 )
        v25 = FLOAT_0_5;
      v20.m128_f32[0] = v20.m128_f32[0] + v25;
      v28 = (int)v20.m128_f32[0];
      if ( (int)v20.m128_f32[0] != 0x80000000 && (float)v28 != v20.m128_f32[0] )
        v20.m128_f32[0] = (float)(v28 - (_mm_movemask_ps(_mm_unpacklo_ps(v20, v20)) & 1));
      LODWORD(cullRect.M[1][3]) = v20.m128_i32[0];
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&this->M, &cullRect);
    }
    pObject = this->SorterShapeNode.pBundle.pObject;
    if ( pObject )
    {
      if ( v13 )
        pObject->vfptr[3].__vecDelDtor(pObject, (unsigned int)&this->SorterShapeNode);
    }
  }
}

// File Line: 842
// RVA: 0x9892A0
Scaleform::Render::MeshStagingNode *__fastcall Scaleform::Render::TreeCacheShapeLayer::GetMesh(
        Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::MeshKey *pObject; // rax
  unsigned __int16 Flags; // cx
  unsigned int meshGenFlags; // edi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rdx
  Scaleform::Render::TreeShape::NodeData *ShapeNodeData; // rax
  int v8; // eax
  unsigned int pHandle_high; // xmm1_4
  unsigned int v10; // xmm0_4
  Scaleform::Render::TreeNode *pNode; // r10
  Scaleform::Render::TreeNode *v12; // rcx
  Scaleform::Render::Bundle *v13; // rax
  Scaleform::Render::ShapeMeshProvider *MeshProvider; // rax
  Scaleform::Render::MeshStagingNode *v15; // rax
  Scaleform::Render::Matrix2x4<float> mat; // [rsp+40h] [rbp-68h] BYREF
  Scaleform::Render::Matrix4x4<float> result; // [rsp+60h] [rbp-48h] BYREF

  if ( this->pRoot )
  {
    pObject = this->pMeshKey.pObject;
    if ( !pObject || !pObject->pMesh.pObject )
    {
      Flags = this->Flags;
      if ( (Flags & 0x40) != 0 )
        meshGenFlags = 2;
      else
        meshGenFlags = (Flags & 0xC) == 4;
      if ( (Flags & 0x80u) != 0 )
        meshGenFlags |= 8u;
      pHandle = this->M.pHandle;
      pHeader = pHandle->pHeader;
      if ( (pHandle->pHeader->Format & 0x10) != 0 )
      {
        Scaleform::Render::TreeCacheNode::GetViewProj(this, &result);
        ShapeNodeData = Scaleform::Render::TreeCacheShapeLayer::GetShapeNodeData(this);
        Scaleform::Render::TreeCacheShapeLayer::getShapeMatrixFrom3D(this, ShapeNodeData, &mat, &result);
      }
      else
      {
        v8 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[4];
        pHandle_high = HIDWORD(pHeader[v8 + 1].pHandle);
        mat.M[0][0] = *(float *)&pHeader[v8 + 1].pHandle;
        *(_QWORD *)&mat.M[0][1] = __PAIR64__(pHeader[v8 + 1].RefCount, pHandle_high);
        v10 = (unsigned int)pHeader[v8 + 2].pHandle;
        mat.M[0][3] = *(float *)&pHeader[v8 + 1].DataPageOffset;
        *(_QWORD *)&mat.M[1][0] = __PAIR64__(HIDWORD(pHeader[v8 + 2].pHandle), v10);
        *(_QWORD *)&mat.M[1][2] = *(_QWORD *)&pHeader[v8 + 2].RefCount;
      }
      pNode = this->pNode;
      if ( pNode )
        v12 = this->pNode;
      else
        v12 = this->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
      if ( !pNode )
        pNode = this->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
      Scaleform::Render::TreeCacheShapeLayer::updateMeshKey(
        this,
        this->pRenderer2D,
        *(Scaleform::Render::ShapeMeshProvider **)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64)
                                                                          + 0x28)
                                                              + 8i64
                                                              * (unsigned int)((int)((_DWORD)pNode
                                                                                   - ((unsigned int)pNode & 0xFFFFF000)
                                                                                   - 56)
                                                                             / 56)
                                                              + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                                 + 144),
        *(float *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                              + 8i64 * (unsigned int)((int)((_DWORD)v12 - ((unsigned int)v12 & 0xFFFFF000) - 56) / 56)
                              + 40) & 0xFFFFFFFFFFFFFFFEui64)
                 + 152),
        &mat,
        meshGenFlags,
        0i64);
      if ( !this->ComplexShape )
      {
        v13 = this->SorterShapeNode.pBundle.pObject;
        if ( v13 )
        {
          if ( *(_QWORD *)(*(_QWORD *)&v13[1].NeedUpdate + 32i64) )
          {
            *(_OWORD *)&mat.M[0][0] = _xmm;
            *(__m128 *)&mat.M[1][0] = _xmm;
            MeshProvider = Scaleform::Render::TreeCacheShapeLayer::GetMeshProvider(this);
            MeshProvider->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->GetFillMatrix(
              &MeshProvider->Scaleform::Render::MeshProvider,
              this->pMeshKey.pObject->pMesh.pObject,
              &mat,
              this->Layer,
              0,
              meshGenFlags);
            Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(&this->M, &mat, 0);
          }
        }
      }
    }
  }
  v15 = (Scaleform::Render::MeshStagingNode *)this->pMeshKey.pObject;
  if ( v15 )
    return (Scaleform::Render::MeshStagingNode *)v15->StagingBufferSize;
  return v15;
}

// File Line: 886
// RVA: 0x9A9F80
void __fastcall Scaleform::Render::TreeCacheShapeLayer::RemoveMesh(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::MeshKey *pObject; // rbx
  bool v3; // zf
  Scaleform::Render::MeshBase *v4; // rcx

  pObject = this->pMeshKey.pObject;
  if ( pObject && (v3 = pObject->UseCount == 1, --pObject->UseCount, v3) )
  {
    v4 = pObject->pMesh.pObject;
    if ( !v4
      || ((unsigned __int8 (__fastcall *)(Scaleform::Render::MeshBase *))v4->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(v4)
      || (pObject->Flags & 0x110) != 0 )
    {
      Scaleform::Render::MeshKeySet::DestroyKey(pObject->pKeySet, pObject);
    }
    this->pMeshKey.pObject = 0i64;
  }
  else
  {
    this->pMeshKey.pObject = 0i64;
  }
}

// File Line: 893
// RVA: 0x9EE1E0
void __fastcall Scaleform::Render::TreeCacheShapeLayer::propagateMaskFlag(
        Scaleform::Render::TreeCacheShapeLayer *this,
        unsigned int partOfMask)
{
  if ( (partOfMask | this->Flags & 0xFFBF) != this->Flags )
  {
    this->Flags = partOfMask | this->Flags & 0xFFBF;
    Scaleform::Render::TreeCacheShapeLayer::updateSortKey(this);
  }
}

// File Line: 903
// RVA: 0x9EE400
void __fastcall Scaleform::Render::TreeCacheShapeLayer::propagateScale9Flag(
        Scaleform::Render::TreeCacheShapeLayer *this,
        unsigned int partOfScale9)
{
  Scaleform::Render::TreeNode *pNode; // rcx
  unsigned int v5; // ecx

  pNode = this->pNode;
  if ( pNode
    && Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::Scale9State>((Scaleform::Render::TreeNode::NodeData *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28) + 8i64 * (unsigned int)((int)((_DWORD)pNode - ((unsigned int)pNode & 0xFFFFF000) - 56) / 56) + 40) & 0xFFFFFFFFFFFFFFFEui64)) )
  {
    partOfScale9 |= 0x80u;
  }
  v5 = partOfScale9 | this->Flags & 0xFF7F;
  if ( v5 != this->Flags )
  {
    this->Flags = v5;
    Scaleform::Render::TreeCacheShapeLayer::updateSortKey(this);
  }
}

// File Line: 916
// RVA: 0x9EE040
void __fastcall Scaleform::Render::TreeCacheShapeLayer::propagateEdgeAA(
        Scaleform::Render::TreeCacheShapeLayer *this,
        __int32 parentEdgeAA)
{
  Scaleform::Render::TreeNode *pNode; // rcx
  Scaleform::Render::EdgeAAMode v4; // r8d
  int v5; // eax

  pNode = this->pNode;
  v4 = parentEdgeAA;
  if ( pNode && parentEdgeAA != 12 )
  {
    v5 = *(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                               + 8i64
                               * (unsigned int)((__int64)((__int64)&pNode[-1]
                                                        - ((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64))
                                              / 56)
                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                  + 10) & 0xC;
    if ( !v5 )
      v5 = parentEdgeAA;
    v4 = v5;
  }
  if ( (this->Flags & 0xC) != v4 )
  {
    this->Flags = v4 | this->Flags & 0xFFF3;
    Scaleform::Render::TreeCacheShapeLayer::updateSortKey(this);
  }
}

// File Line: 928
// RVA: 0x9EDE00
// attributes: thunk
void __fastcall Scaleform::Render::TreeCacheShapeLayer::propagate3DFlag(
        Scaleform::Render::TreeCacheShapeLayer *this,
        unsigned int parent3D)
{
  Scaleform::Render::TreeCacheShapeLayer::updateSortKey(this);
}

