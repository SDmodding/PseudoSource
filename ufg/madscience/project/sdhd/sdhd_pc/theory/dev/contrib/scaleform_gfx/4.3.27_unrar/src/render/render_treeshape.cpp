// File Line: 86
// RVA: 0x98B5D0
Scaleform::Render::TreeShape::NodeData *__fastcall Scaleform::Render::TreeCacheShapeLayer::GetShapeNodeData(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeNode *v1; // rdx
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rdx

  v1 = this->pNode;
  if ( !v1 )
    v1 = this->pParent->pNode;
  v2 = (unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64;
  v3 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1[-1]
                                                           - ((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64))
                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4;
  return (Scaleform::Render::TreeShape::NodeData *)(*(_QWORD *)(*(_QWORD *)(v2 + 40)
                                                              + 8 * ((unsigned int)v3 + (v3 >> 63))
                                                              + 40) & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 92
// RVA: 0x9895B0
Scaleform::Render::ShapeMeshProvider *__fastcall Scaleform::Render::TreeCacheShapeLayer::GetMeshProvider(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeNode *v1; // rdx
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rdx

  v1 = this->pNode;
  if ( !v1 )
    v1 = this->pParent->pNode;
  v2 = (unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64;
  v3 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1[-1]
                                                           - ((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64))
                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4;
  return *(Scaleform::Render::ShapeMeshProvider **)((*(_QWORD *)(*(_QWORD *)(v2 + 40)
                                                               + 8 * ((unsigned int)v3 + (v3 >> 63))
                                                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                                  + 144);
}

// File Line: 186
// RVA: 0x9A0DE0
bool __fastcall Scaleform::Render::TreeShape::NodeData::PropagateUp(Scaleform::Render::TreeShape::NodeData *this, Scaleform::Render::ContextImpl::Entry *entry)
{
  float v2; // xmm8_4
  Scaleform::Render::ContextImpl::Entry *v3; // r14
  Scaleform::Render::TreeShape::NodeData *v4; // rdi
  float v5; // xmm9_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  Scaleform::Render::ShapeMeshProvider *v8; // rcx
  float *v9; // rax
  Scaleform::Render::StateBag *v10; // rax
  _QWORD *v11; // rsi
  __int64 v12; // rbx
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm10
  __m128 v24; // xmm3
  __m128 v25; // xmm10
  float v26; // xmm11_4
  float v27; // xmm12_4
  float v28; // xmm13_4
  __int16 v29; // ax
  Scaleform::Render::ContextImpl::EntryData *v30; // rax
  Scaleform::Render::Rect<float> bounds; // [rsp+18h] [rbp-69h]
  Scaleform::Render::Rect<float> pr; // [rsp+28h] [rbp-59h]
  Scaleform::Render::Rect<float> v34; // [rsp+38h] [rbp-49h]
  char v35; // [rsp+48h] [rbp-39h]

  v2 = this->AproxLocalBounds.x1;
  v3 = entry;
  v4 = this;
  v5 = this->AproxLocalBounds.x2;
  bounds = 0i64;
  pr = 0i64;
  v34 = 0i64;
  if ( v2 >= v5 || (v6 = this->AproxLocalBounds.y1, v7 = this->AproxLocalBounds.y2, v6 >= v7) )
  {
    v8 = this->pMeshProvider.pObject;
    if ( !v8 )
    {
      v7 = bounds.y2;
      v5 = bounds.x2;
      v6 = bounds.y1;
      v2 = bounds.x1;
      goto LABEL_16;
    }
    v9 = (float *)v8->vfptr->GetIdentityBounds(
                    (Scaleform::Render::MeshProvider *)&v8->vfptr,
                    (Scaleform::Render::Rect<float> *)&v35);
    v2 = *v9;
    v6 = v9[1];
    v5 = v9[2];
    v7 = v9[3];
  }
  bounds.y2 = v7;
  bounds.x2 = v5;
  bounds.y1 = v6;
  bounds.x1 = v2;
  if ( v2 >= v5 || v6 >= v7 )
    goto LABEL_16;
  v34.x1 = v2;
  v34.y1 = v6;
  v34.x2 = v5;
  v34.y2 = v7;
  v10 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::FilterState>((Scaleform::Render::TreeNode::NodeData *)&v4->vfptr);
  if ( v10 )
  {
    v11 = v10->pData;
    if ( v11 )
    {
      v12 = 0i64;
      if ( *((_DWORD *)v11 + 6) )
      {
        do
        {
          Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
            *(Scaleform::Render::Filter **)(v11[2] + 8 * v12),
            &bounds);
          v12 = (unsigned int)(v12 + 1);
        }
        while ( (unsigned int)v12 < *((_DWORD *)v11 + 6) );
        v7 = bounds.y2;
        v5 = bounds.x2;
        v6 = bounds.y1;
        v2 = bounds.x1;
      }
    }
  }
  if ( (v4->Flags >> 9) & 1 )
  {
    Scaleform::Render::Matrix3x4<float>::EncloseTransform(&v4->M34, &pr, &bounds);
LABEL_16:
    v25.m128_i32[0] = LODWORD(pr.x1);
    v26 = pr.y1;
    v27 = pr.x2;
    v28 = pr.y2;
    goto LABEL_17;
  }
  v13 = *(__m128 *)&v4->M34.M[0][0];
  v14 = v13;
  v15 = _mm_unpacklo_ps(v13, *(__m128 *)&v4->M34.M[1][0]);
  v16 = _mm_shuffle_ps(v14, *(__m128 *)&v4->M34.M[1][0], 255);
  v17 = _mm_mul_ps(_mm_unpackhi_ps((__m128)bounds, (__m128)bounds), v15);
  v18 = _mm_mul_ps(_mm_unpacklo_ps((__m128)bounds, (__m128)bounds), v15);
  v19 = _mm_unpacklo_ps(v18, v17);
  v20 = _mm_unpackhi_ps(v18, v17);
  v21 = _mm_add_ps(v20, v19);
  v22 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v20);
  v23 = _mm_min_ps(v21, v22);
  v24 = _mm_max_ps(v21, v22);
  v25 = _mm_add_ps(
          _mm_shuffle_ps(
            _mm_min_ps(v23, _mm_shuffle_ps(v23, v23, 177)),
            _mm_max_ps(v24, _mm_shuffle_ps(v24, v24, 177)),
            136),
          _mm_shuffle_ps(v16, v16, 136));
  LODWORD(v26) = (unsigned __int128)_mm_shuffle_ps(v25, v25, 85);
  LODWORD(v27) = (unsigned __int128)_mm_shuffle_ps(v25, v25, 170);
  LODWORD(v28) = (unsigned __int128)_mm_shuffle_ps(v25, v25, 255);
LABEL_17:
  if ( v2 != v4->AproxLocalBounds.x1
    || v5 != v4->AproxLocalBounds.x2
    || v6 != v4->AproxLocalBounds.y1
    || v7 != v4->AproxLocalBounds.y2
    || v25.m128_f32[0] != v2
    || v27 != v5
    || v26 != v6
    || v28 != v7 )
  {
    v30 = Scaleform::Render::ContextImpl::Entry::getWritableData(v3, 8u);
    *(float *)&v30[7].vfptr = v2;
    *((float *)&v30[7].vfptr + 1) = v6;
    *(float *)&v30[7].Type = v5;
    *(float *)(&v30[7].Flags + 1) = v7;
    LODWORD(v30[8].vfptr) = v25.m128_i32[0];
    *((float *)&v30[8].vfptr + 1) = v26;
    *(float *)&v30[8].Type = v27;
    *(float *)(&v30[8].Flags + 1) = v28;
    Scaleform::Render::TreeNode::NodeData::updateOriginalBoundState((Scaleform::Render::TreeNode::NodeData *)v30, &v34);
    v29 = v4->Flags & 1;
  }
  else
  {
    LOBYTE(v29) = 0;
  }
  return v29;
}

// File Line: 230
// RVA: 0x9F8DB0
Scaleform::Render::TreeCacheMeshBase *__fastcall Scaleform::Render::TreeShape::NodeData::updateCache(Scaleform::Render::TreeShape::NodeData *this, Scaleform::Render::TreeCacheNode *pparent, Scaleform::Render::TreeCacheNode *pinsert, Scaleform::Render::TreeNode *pnode, unsigned __int16 depth)
{
  Scaleform::Render::TreeShape *shapeNode; // rbp
  Scaleform::Render::TreeCacheNode *v6; // r15
  Scaleform::Render::TreeCacheNode *v7; // rsi
  Scaleform::Render::TreeShape::NodeData *v8; // r14
  Scaleform::Render::TreeCacheMeshBase *v9; // rbx
  Scaleform::Render::ShapeMeshProvider *v10; // r13
  int v11; // ebx
  int v12; // eax
  int v13; // edx
  int v14; // edi
  Scaleform::Render::TreeCacheContainer *v15; // rax
  int v17; // [rsp+88h] [rbp+20h]

  shapeNode = (Scaleform::Render::TreeShape *)pnode;
  v6 = pinsert;
  v7 = pparent;
  v8 = this;
  v9 = (Scaleform::Render::TreeCacheMeshBase *)pnode->pRenderer;
  if ( v9 )
    goto LABEL_19;
  v10 = *(Scaleform::Render::ShapeMeshProvider **)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pnode & 0xFFFFFFFFFFFFF000ui64)
                                                                          + 0x28)
                                                              + 8
                                                              * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&pnode[-1] - ((unsigned __int64)pnode & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                               + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&pnode[-1] - ((unsigned __int64)pnode & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                              + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                                 + 144);
  v11 = ((__int64 (*)(void))v10->vfptr->GetLayerCount)();
  if ( !v7 )
  {
    v12 = 4;
LABEL_6:
    v13 = v8->Flags & 0xC;
    if ( !v13 )
      v13 = v12;
    goto LABEL_8;
  }
  v12 = v7->Flags & 0xC;
  if ( v12 != 12 )
    goto LABEL_6;
  v13 = 12;
LABEL_8:
  v14 = v13 | v8->Flags & 0x221 | ((unsigned __int8)v7->Flags | (unsigned __int8)(2 * (v8->Flags & 0x20))) & 0xC0;
  if ( Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::Scale9State>((Scaleform::Render::TreeNode::NodeData *)&v8->vfptr) )
    v14 |= 0x80u;
  if ( v11 == 1 )
  {
    v9 = Scaleform::Render::TreeCacheShapeLayer::Create(v7, v10, 0, v14, shapeNode, v8->MorphRatio);
  }
  else
  {
    v17 = 71;
    v15 = (Scaleform::Render::TreeCacheContainer *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     v7,
                                                     160ui64,
                                                     (Scaleform::AllocInfo *)&v17);
    v9 = (Scaleform::Render::TreeCacheMeshBase *)v15;
    if ( v15 )
    {
      Scaleform::Render::TreeCacheContainer::TreeCacheContainer(
        v15,
        (Scaleform::Render::TreeNode *)&shapeNode->0,
        v7->pRenderer2D,
        v14);
      v9->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheShape::`vftable';
    }
    else
    {
      v9 = 0i64;
    }
  }
  if ( !v9 )
    return 0i64;
  shapeNode->pRenderer = (Scaleform::Render::TreeCacheNode *)&v9->vfptr;
LABEL_19:
  Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(
    (Scaleform::Render::TreeCacheNode *)&v9->vfptr,
    v7,
    v6,
    (Scaleform::Render::TreeNode::NodeData *)&v8->vfptr,
    depth);
  return v9;
}

// File Line: 268
// RVA: 0x960DE0
Scaleform::Render::ContextImpl::Entry *__fastcall Scaleform::Render::TreeShape::NodeData::CloneCreate(Scaleform::Render::TreeShape::NodeData *this, Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::ContextImpl::Context *v2; // rdi
  Scaleform::Render::TreeShape::NodeData *v3; // rsi
  Scaleform::Render::TreeShape::NodeData *v4; // rax
  Scaleform::Render::ContextImpl::EntryData *v5; // rbx
  Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeShape::NodeData> src; // [rsp+50h] [rbp+8h]
  Scaleform::Render::TreeShape::NodeData *v8; // [rsp+58h] [rbp+10h]
  Scaleform::Render::TreeShape::NodeData *v9; // [rsp+60h] [rbp+18h]

  v2 = context;
  v3 = this;
  v4 = (Scaleform::Render::TreeShape::NodeData *)context->pHeap->vfptr->Alloc(context->pHeap, 160ui64, 0i64);
  v5 = (Scaleform::Render::ContextImpl::EntryData *)&v4->vfptr;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    src.pC = v3;
    Scaleform::Render::TreeShape::NodeData::NodeData(
      v4,
      (Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeShape::NodeData>)&src);
  }
  return Scaleform::Render::ContextImpl::Context::createEntryHelper(v2, v5);
}

// File Line: 287
// RVA: 0x94D820
void __fastcall Scaleform::Render::TreeCacheShape::~TreeCacheShape(Scaleform::Render::TreeCacheShape *this)
{
  Scaleform::Render::TreeCacheShape *v1; // rdi
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *v2; // rbx
  signed __int64 v3; // rax
  Scaleform::Render::TreeCacheNode *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheShape::`vftable';
  v2 = &this->Children;
  while ( 1 )
  {
    v3 = (signed __int64)&v2[-1].Root.8;
    if ( !v2 )
      v3 = 0i64;
    if ( v2->Root.pNext == (Scaleform::Render::TreeCacheNode *)v3 )
      break;
    v4 = v1->Children.Root.pNext;
    v4->pPrev->pNext = v4->pNext;
    v4->pNext->pPrev = v4->pPrev;
    v4->pNext = (Scaleform::Render::TreeCacheNode *)-1i64;
    v4->pPrev = 0i64;
    v4->pParent = 0i64;
    v4->vfptr->__vecDelDtor(v4, 1u);
  }
  Scaleform::Render::TreeCacheContainer::~TreeCacheContainer((Scaleform::Render::TreeCacheContainer *)&v1->vfptr);
}

// File Line: 302
// RVA: 0x9BFA50
void __fastcall Scaleform::Render::TreeCacheShape::UpdateTransform(Scaleform::Render::TreeCacheShape *this, Scaleform::Render::TreeNode::NodeData *shapeData, Scaleform::Render::TransformArgs *t, Scaleform::Render::TransformFlags flags)
{
  Scaleform::Render::TransformArgs *v4; // rbx
  Scaleform::Render::TreeCacheShape *v5; // rdi
  Scaleform::Render::TreeNode::NodeData *v6; // rbp
  Scaleform::Render::TransformFlags v7; // esi
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  signed int v11; // esi
  Scaleform::Render::TreeCacheShapeLayer *v12; // rbx
  signed __int64 v13; // rdi
  signed __int64 v14; // rax
  Scaleform::Render::TransformArgs ta; // [rsp+30h] [rbp-E8h]

  v4 = t;
  v5 = this;
  v6 = shapeData;
  v7 = flags;
  Scaleform::Render::TransformArgs::TransformArgs(&ta, t, &t->Mat);
  if ( (v7 & 0x80u) != 0 )
  {
    *(_OWORD *)&ta.Mat3D.M[0][0] = *(_OWORD *)&v4->Mat3D.M[0][0];
    *(_OWORD *)&ta.Mat3D.M[1][0] = *(_OWORD *)&v4->Mat3D.M[1][0];
    *(_OWORD *)&ta.Mat3D.M[2][0] = *(_OWORD *)&v4->Mat3D.M[2][0];
  }
  Scaleform::Render::TreeCacheNode::updateCulling(
    (Scaleform::Render::TreeCacheNode *)&v5->vfptr,
    v6,
    v4,
    &ta.CullRect,
    (Scaleform::Render::TransformFlags)(v7 | 0x20));
  v8 = v6->AproxParentBounds.y2;
  v9 = v6->AproxParentBounds.x2;
  v10 = v6->AproxParentBounds.y1;
  v5->SortParentBounds.x1 = v6->AproxParentBounds.x1;
  v11 = v7 & 0xFFFFFFEF;
  v5->SortParentBounds.y1 = v10;
  v5->SortParentBounds.x2 = v9;
  v5->SortParentBounds.y2 = v8;
  v5->Flags &= 0xFBFFu;
  v12 = (Scaleform::Render::TreeCacheShapeLayer *)v5->Children.Root.pNext;
  v13 = (signed __int64)&v5->Children;
  while ( 1 )
  {
    v14 = v13 ? v13 - 8 : 0i64;
    if ( v12 == (Scaleform::Render::TreeCacheShapeLayer *)v14 )
      break;
    Scaleform::Render::TreeCacheShapeLayer::UpdateTransform(v12, v6, &ta, (Scaleform::Render::TransformFlags)v11);
    v12 = (Scaleform::Render::TreeCacheShapeLayer *)v12->pNext;
  }
}

// File Line: 330
// RVA: 0x990620
void __fastcall Scaleform::Render::TreeCacheShape::HandleChanges(Scaleform::Render::TreeCacheShape *this, unsigned int changeBits)
{
  char v2; // bl
  Scaleform::Render::TreeCacheShape *v3; // rdi
  Scaleform::Render::TreeCacheNode *v4; // rcx
  unsigned int v5; // er8
  signed __int64 v6; // rdx
  Scaleform::Render::TreeCacheRoot *v7; // rcx
  signed int v8; // eax
  Scaleform::Render::TreeCacheShapeLayer *v9; // rbx
  signed __int64 v10; // rdi
  signed __int64 v11; // rax
  Scaleform::Render::TreeNode *v12; // rcx

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
  if ( v2 & 0x10 )
  {
    v7 = v3->pRoot;
    if ( v7 )
    {
      v8 = 1;
      if ( (v3->UpdateFlags & 0x80000000) == 0 )
      {
        v3->pNextUpdate = v7->pUpdateList;
        v7->pUpdateList = (Scaleform::Render::TreeCacheNode *)&v3->vfptr;
        v8 = -2147483647;
      }
      v3->UpdateFlags |= v8;
      v9 = (Scaleform::Render::TreeCacheShapeLayer *)v3->Children.Root.pNext;
      v10 = (signed __int64)&v3->Children;
      while ( 1 )
      {
        v11 = v10 ? v10 - 8 : 0i64;
        if ( v9 == (Scaleform::Render::TreeCacheShapeLayer *)v11 )
          break;
        v12 = v9->pNode;
        if ( !v12 )
          v12 = v9->pParent->pNode;
        if ( *(_BYTE *)(*(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                               + 8
                                               * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v12[-1] - ((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v12[-1] - ((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64))
                                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                  + 144)
                      + 128i64) )
          Scaleform::Render::TreeCacheShapeLayer::updateSortKey(v9);
        v9 = (Scaleform::Render::TreeCacheShapeLayer *)v9->pNext;
      }
    }
  }
}

// File Line: 368
// RVA: 0x9BD910
void __fastcall Scaleform::Render::TreeCacheShape::UpdateChildSubtree(Scaleform::Render::TreeCacheShape *this, Scaleform::Render::TreeNode::NodeData *pdata, unsigned __int16 depth)
{
  unsigned __int16 v3; // si
  Scaleform::Render::TreeNode::NodeData *v4; // rbx
  Scaleform::Render::TreeCacheShape *v5; // rdi
  Scaleform::Render::ShapeMeshProvider *v6; // r13
  unsigned int v7; // er15
  signed __int64 v8; // rax
  unsigned int v9; // ebx
  Scaleform::Render::TreeCacheNode *v10; // r14
  unsigned __int64 v11; // rdx
  Scaleform::Render::TreeCacheMeshBase *v12; // rax
  Scaleform::Render::TreeCacheMeshBase *v13; // rbp
  Scaleform::Render::TreeCacheNode *i; // rcx
  signed __int64 v15; // rax

  v3 = depth;
  v4 = pdata;
  v5 = this;
  Scaleform::Render::TreeCacheNode::UpdateChildSubtree((Scaleform::Render::TreeCacheNode *)&this->vfptr, pdata, depth);
  v6 = (Scaleform::Render::ShapeMeshProvider *)v4[1].vfptr;
  v7 = v6->vfptr->GetLayerCount((Scaleform::Render::MeshProvider *)&v6->vfptr);
  v8 = (signed __int64)&v5->SortParentBounds.x2;
  if ( v5 == (Scaleform::Render::TreeCacheShape *)-112i64 )
    v8 = 0i64;
  if ( v5->Children.Root.pNext == (Scaleform::Render::TreeCacheNode *)v8 )
  {
    v9 = 0;
    v10 = v5->Children.Root.pNext->pPrev;
    if ( v7 )
    {
      do
      {
        v11 = (unsigned __int128)((signed __int64)((signed __int64)&v5->pNode[-1]
                                                 - ((_QWORD)v5->pNode & 0xFFFFFFFFFFFFF000ui64))
                                * (signed __int128)5270498306774157605i64) >> 64;
        v12 = Scaleform::Render::TreeCacheShapeLayer::Create(
                (Scaleform::Render::TreeCacheNode *)&v5->vfptr,
                v6,
                v9,
                v5->Flags & 0xC | 1u,
                0i64,
                *(float *)((*(_QWORD *)(*(_QWORD *)(((_QWORD)v5->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                      + 8 * ((unsigned int)((signed __int64)v11 >> 4) + (v11 >> 63))
                                      + 40) & 0xFFFFFFFFFFFFFFFEui64)
                         + 152));
        v13 = v12;
        if ( v12 )
        {
          Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(
            (Scaleform::Render::TreeCacheNode *)&v12->vfptr,
            (Scaleform::Render::TreeCacheNode *)&v5->vfptr,
            v10,
            0i64,
            v3);
          v10 = (Scaleform::Render::TreeCacheNode *)&v13->vfptr;
        }
        ++v9;
      }
      while ( v9 < v7 );
    }
  }
  else
  {
    for ( i = v5->Children.Root.pNext; ; i = i->pNext )
    {
      v15 = (signed __int64)&v5->SortParentBounds.x2;
      if ( v5 == (Scaleform::Render::TreeCacheShape *)-112i64 )
        v15 = 0i64;
      if ( i == (Scaleform::Render::TreeCacheNode *)v15 )
        break;
      i->Depth = v3;
      i->pRoot = v5->pRoot;
    }
  }
}

// File Line: 415
// RVA: 0x94D8C0
void __fastcall Scaleform::Render::TreeCacheShapeLayer::~TreeCacheShapeLayer(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeCacheShapeLayer *v1; // rdi
  Scaleform::Render::Image *v2; // rcx
  Scaleform::Render::MeshKey *v3; // rbx
  bool v4; // zf
  Scaleform::Render::MeshBase *v5; // rcx

  v1 = this;
  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheShapeLayer::`vftable';
  v2 = this->pGradient.pObject;
  if ( v2 )
    ((void (__cdecl *)(Scaleform::Render::Image *))v2->vfptr[2].__vecDelDtor)(v2);
  v3 = v1->pMeshKey.pObject;
  if ( v3 )
  {
    v4 = v3->UseCount-- == 1;
    if ( v4 )
    {
      v5 = v3->pMesh.pObject;
      if ( !v5
        || ((unsigned __int8 (__cdecl *)(Scaleform::Render::MeshBase *))v5->vfptr[1].__vecDelDtor)(v5)
        || v3->Flags & 0x110 )
      {
        Scaleform::Render::MeshKeySet::DestroyKey(v3->pKeySet, v3);
      }
    }
  }
  Scaleform::Render::TreeCacheMeshBase::~TreeCacheMeshBase((Scaleform::Render::TreeCacheMeshBase *)&v1->vfptr);
}

// File Line: 423
// RVA: 0x965E40
Scaleform::Render::TreeCacheMeshBase *__fastcall Scaleform::Render::TreeCacheShapeLayer::Create(Scaleform::Render::TreeCacheNode *pparent, Scaleform::Render::ShapeMeshProvider *provider, unsigned int drawLayer, unsigned int flags, Scaleform::Render::TreeShape *shapeNode, float morphRatio)
{
  unsigned int v6; // ebp
  unsigned int v7; // er14
  Scaleform::Render::TreeCacheNode *v8; // rbx
  Scaleform::Render::TreeCacheMeshBase *v9; // rsi
  Scaleform::Render::TreeCacheMeshBase *v10; // rax
  Scaleform::Render::TreeCacheMeshBase *v11; // rdi
  __int64 v12; // rbx
  Scaleform::Render::TreeCacheNode *v13; // rcx
  int v15; // [rsp+40h] [rbp-48h]
  __int64 v16; // [rsp+48h] [rbp-40h]
  __int64 v17; // [rsp+50h] [rbp-38h]
  Scaleform::Render::TreeCacheMeshBase *v18; // [rsp+58h] [rbp-30h]
  Scaleform::Render::SortKey key; // [rsp+60h] [rbp-28h]

  v17 = -2i64;
  v6 = flags;
  v7 = drawLayer;
  v8 = pparent;
  v9 = 0i64;
  v16 = 0i64;
  Scaleform::Render::TreeCacheShapeLayer::CreateSortKey(
    &key,
    pparent,
    provider,
    drawLayer,
    flags,
    (Scaleform::Ptr<Scaleform::Render::Image> *)&v16,
    morphRatio);
  v15 = 71;
  v10 = (Scaleform::Render::TreeCacheMeshBase *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  v8,
                                                  224ui64,
                                                  (Scaleform::AllocInfo *)&v15);
  v11 = v10;
  v18 = v10;
  if ( v10 )
  {
    Scaleform::Render::TreeCacheMeshBase::TreeCacheMeshBase(
      v10,
      (Scaleform::Render::TreeNode *)&shapeNode->0,
      &key,
      v8->pRenderer2D,
      v6);
    v11->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheShapeLayer::`vftable';
    v11[1].vfptr = 0i64;
    v11[1].pPrev = 0i64;
    LOBYTE(v11[1].pNext) = key.pImpl->Type == 2;
    HIDWORD(v11[1].pVoidNext) = v7;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = v16;
  if ( v11 )
  {
    if ( v16 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v16 + 8i64))(v16);
    v13 = v11[1].pPrev;
    if ( v13 )
      ((void (*)(void))v13->vfptr->UpdateChildSubtree)();
    v11[1].pPrev = (Scaleform::Render::TreeCacheNode *)v12;
    v9 = v11;
  }
  key.pImpl->vfptr->Release(key.pImpl, key.Data);
  if ( v12 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v12 + 16i64))(v12);
  return v9;
}

// File Line: 441
// RVA: 0x9694C0
Scaleform::Render::SortKey *__fastcall Scaleform::Render::TreeCacheShapeLayer::CreateSortKey(Scaleform::Render::SortKey *result, Scaleform::Render::TreeCacheNode *refNode, Scaleform::Render::ShapeMeshProvider *provider, unsigned int drawLayer, unsigned int flags, Scaleform::Ptr<Scaleform::Render::Image> *gradientImage)
{
  unsigned int v6; // er12
  Scaleform::Render::TreeCacheNode *v7; // rdi
  Scaleform::Render::SortKey *v8; // r14
  unsigned int v9; // ebp
  Scaleform::Render::TreeCacheNode *v10; // rcx
  char v11; // si
  Scaleform::Render::MeshProvider *v12; // r15
  Scaleform::Render::SKI_ComplexPrimitive *v13; // rcx
  Scaleform::Render::SortKeyInterfaceVtbl *v14; // rax
  Scaleform::Render::TextureManager *v15; // rbx
  Scaleform::Render::Renderer2DImpl *v16; // rdi
  Scaleform::Render::PrimitiveFill *v17; // rbx
  bool v18; // zf
  Scaleform::Render::FillData initdata; // [rsp+40h] [rbp-58h]

  v6 = drawLayer;
  v7 = refNode;
  v8 = result;
  v9 = 0;
  if ( (flags & 0xC) == 4 )
    v9 = 1;
  if ( flags & 0x40 )
    v9 = 2;
  if ( (flags & 0x80u) != 0 )
    v9 |= 8u;
  v10 = refNode;
  v11 = (flags >> 9) & 1;
  do
  {
    v11 |= (v10->Flags >> 9) & 1;
    v10 = v10->pParent;
  }
  while ( v10 && !v11 );
  v12 = (Scaleform::Render::MeshProvider *)&provider->vfptr;
  if ( provider->vfptr->GetFillCount((Scaleform::Render::MeshProvider *)&provider->vfptr, drawLayer, v9) <= 1 )
  {
    v15 = (Scaleform::Render::TextureManager *)((__int64 (*)(void))v7->pRenderer2D->pHal.pObject->vfptr[61].__vecDelDtor)();
    v16 = v7->pRenderer2D;
    initdata.Type = 3;
    initdata.Color = 0;
    initdata.PrimFill = 4;
    initdata.FillMode.Fill = 0;
    initdata.pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
    v12->vfptr->GetFillData(v12, &initdata, v6, 0, v9);
    v17 = Scaleform::Render::PrimitiveFillManager::CreateFill(&v16->FillManager, &initdata, gradientImage, v15);
    v8->Data = v17;
    if ( v11 )
    {
      v8->pImpl = (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Primitive::Instance3D;
      Scaleform::Render::SKI_Primitive::Instance3D.vfptr->AddRef(
        (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Primitive::Instance3D,
        v17);
    }
    else
    {
      v8->pImpl = (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Primitive::Instance;
      Scaleform::Render::SKI_Primitive::Instance.vfptr->AddRef(
        (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Primitive::Instance,
        v17);
    }
    if ( v17 )
    {
      v18 = v17->RefCount-- == 1;
      if ( v18 )
        v17->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v17->vfptr, 1u);
    }
  }
  else
  {
    v8->Data = v12;
    if ( v11 )
    {
      v13 = &Scaleform::Render::SKI_ComplexPrimitive::Instance3D;
      v8->pImpl = (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ComplexPrimitive::Instance3D;
      v14 = Scaleform::Render::SKI_ComplexPrimitive::Instance3D.vfptr;
    }
    else
    {
      v13 = &Scaleform::Render::SKI_ComplexPrimitive::Instance;
      v8->pImpl = (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ComplexPrimitive::Instance;
      v14 = Scaleform::Render::SKI_ComplexPrimitive::Instance.vfptr;
    }
    v14->AddRef((Scaleform::Render::SortKeyInterface *)&v13->vfptr, v12);
  }
  return v8;
}

// File Line: 474
// RVA: 0x9FA700
void __fastcall Scaleform::Render::TreeCacheShapeLayer::updateSortKey(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeCacheShapeLayer *v1; // rdi
  Scaleform::Render::TreeNode *v2; // r9
  Scaleform::Render::TreeNode *v3; // rcx
  int v4; // xmm0_4
  Scaleform::Render::SortKey *v5; // rbx
  Scaleform::Render::MeshKey *v6; // rbx
  bool v7; // zf
  Scaleform::Render::MeshBase *v8; // rcx
  Scaleform::Render::TreeCacheRoot *v9; // rcx
  Scaleform::Render::TreeCacheNode *v10; // rdx
  Scaleform::Render::SortKey result; // [rsp+48h] [rbp-20h]

  v1 = this;
  Scaleform::Render::BundleEntry::ClearBundle(&this->SorterShapeNode);
  v2 = v1->pNode;
  if ( v2 )
    v3 = v1->pNode;
  else
    v3 = v1->pParent->pNode;
  v4 = *(_DWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                              + 8
                              * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1] - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64))
                                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                               + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1]
                                                                                        - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64))
                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                              + 40) & 0xFFFFFFFFFFFFFFFEui64)
                 + 152);
  if ( !v2 )
    v2 = v1->pParent->pNode;
  v5 = Scaleform::Render::TreeCacheShapeLayer::CreateSortKey(
         &result,
         (Scaleform::Render::TreeCacheNode *)&v1->vfptr,
         *(Scaleform::Render::ShapeMeshProvider **)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64)
                                                                           + 0x28)
                                                               + 8
                                                               * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1] - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                                + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1] - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                                  + 144),
         v1->Layer,
         v1->Flags,
         &v1->pGradient);
  v5->pImpl->vfptr->AddRef(v5->pImpl, v5->Data);
  v1->SorterShapeNode.Key.pImpl->vfptr->Release(v1->SorterShapeNode.Key.pImpl, v1->SorterShapeNode.Key.Data);
  v1->SorterShapeNode.Key.pImpl = v5->pImpl;
  v1->SorterShapeNode.Key.Data = v5->Data;
  result.pImpl->vfptr->Release(result.pImpl, result.Data);
  v1->ComplexShape = v1->SorterShapeNode.Key.pImpl->Type == 2;
  v6 = v1->pMeshKey.pObject;
  if ( v6 )
  {
    v7 = v6->UseCount-- == 1;
    if ( v7 )
    {
      v8 = v6->pMesh.pObject;
      if ( !v8 || ((unsigned __int8 (*)(void))v8->vfptr[1].__vecDelDtor)() || v6->Flags & 0x110 )
        Scaleform::Render::MeshKeySet::DestroyKey(v6->pKeySet, v6);
    }
  }
  v1->pMeshKey.pObject = 0i64;
  v9 = v1->pRoot;
  if ( v9 )
  {
    v10 = v1->pParent;
    if ( v10 )
      Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(v9, v10, 0x1000001u);
  }
}

// File Line: 489
// RVA: 0x9FA8D0
void __fastcall Scaleform::Render::TreeCacheShapeLayer::updateSortKeyGradientMorph(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeNode *v1; // rdx
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rdx

  v1 = this->pNode;
  if ( !v1 )
    v1 = this->pParent->pNode;
  v2 = (unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64;
  v3 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1[-1]
                                                           - ((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64))
                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4;
  if ( *(_BYTE *)(*(_QWORD *)((*(_QWORD *)(*(_QWORD *)(v2 + 40) + 8 * ((unsigned int)v3 + (v3 >> 63)) + 40) & 0xFFFFFFFFFFFFFFFEui64)
                            + 144)
                + 128i64) )
    Scaleform::Render::TreeCacheShapeLayer::updateSortKey(this);
}

// File Line: 495
// RVA: 0x9FAB40
void __fastcall Scaleform::Render::TreeCacheShapeLayer::updateTexture0Matrix(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeCacheShapeLayer *v1; // rbx
  Scaleform::Render::Bundle *v2; // rax
  Scaleform::Render::ShapeMeshProvider *v3; // rax
  unsigned __int16 v4; // dx
  signed int v5; // ecx
  Scaleform::Render::Matrix2x4<float> m; // [rsp+30h] [rbp-28h]

  v1 = this;
  if ( !this->ComplexShape )
  {
    v2 = this->SorterShapeNode.pBundle.pObject;
    if ( v2 )
    {
      if ( *(_QWORD *)(*(_QWORD *)&v2[1].NeedUpdate + 32i64) )
      {
        *(_OWORD *)&m.M[0][0] = _xmm;
        *(__m128 *)&m.M[1][0] = _xmm;
        v3 = Scaleform::Render::TreeCacheShapeLayer::GetMeshProvider(this);
        v4 = v1->Flags;
        if ( v4 & 0x40 )
        {
          v5 = 2;
        }
        else
        {
          v5 = 0;
          if ( (v4 & 0xC) == 4 )
            v5 = 1;
        }
        if ( (v4 & 0x80u) != 0 )
          v5 |= 8u;
        ((void (__fastcall *)(Scaleform::Render::MeshProviderVtbl **, Scaleform::Render::MeshBase *, Scaleform::Render::Matrix2x4<float> *, _QWORD, _DWORD, signed int, _QWORD, _QWORD, _QWORD, _QWORD))v3->vfptr->GetFillMatrix)(
          &v3->vfptr,
          v1->pMeshKey.pObject->pMesh.pObject,
          &m,
          v1->Layer,
          0,
          v5,
          *(_QWORD *)&m.M[0][0],
          *(_QWORD *)&m.M[0][2],
          *(_QWORD *)&m.M[1][0],
          *(_QWORD *)&m.M[1][2]);
        Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(&v1->M, &m, 0);
      }
    }
  }
}

// File Line: 517
// RVA: 0x9E3340
void __fastcall Scaleform::Render::TreeCacheShapeLayer::forceUpdateImages(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeCacheShapeLayer *v1; // rbx
  Scaleform::Render::TreeNode *v2; // r10
  Scaleform::Render::TreeNode *v3; // rcx
  __int128 v4; // xmm0
  Scaleform::Render::SortKeyInterface *v5; // rcx
  Scaleform::Render::MeshKey *v6; // rdi
  bool v7; // zf
  Scaleform::Render::MeshBase *v8; // rcx
  Scaleform::Render::TreeCacheRoot *v9; // rdx
  Scaleform::Render::TreeCacheNode *v10; // rcx
  signed int v11; // eax
  Scaleform::Render::SortKey result; // [rsp+48h] [rbp-20h]

  v1 = this;
  v2 = this->pNode;
  if ( v2 )
    v3 = this->pNode;
  else
    v3 = this->pParent->pNode;
  if ( !v2 )
    v2 = v1->pParent->pNode;
  v4 = *(unsigned int *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                    + 8
                                    * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1] - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                     + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1]
                                                                                              - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                    + 40) & 0xFFFFFFFFFFFFFFFEui64)
                       + 152);
  Scaleform::Render::TreeCacheShapeLayer::CreateSortKey(
    &result,
    (Scaleform::Render::TreeCacheNode *)&v1->vfptr,
    *(Scaleform::Render::ShapeMeshProvider **)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64)
                                                                      + 0x28)
                                                          + 8
                                                          * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1] - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                           + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1] - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                          + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                             + 144),
    v1->Layer,
    v1->Flags,
    &v1->pGradient);
  if ( result.pImpl != v1->SorterShapeNode.Key.pImpl || result.Data != v1->SorterShapeNode.Key.Data )
  {
    Scaleform::Render::BundleEntry::ClearBundle(&v1->SorterShapeNode);
    result.pImpl->vfptr->AddRef(result.pImpl, result.Data);
    v1->SorterShapeNode.Key.pImpl->vfptr->Release(v1->SorterShapeNode.Key.pImpl, v1->SorterShapeNode.Key.Data);
    v5 = result.pImpl;
    v1->SorterShapeNode.Key = result;
    v1->ComplexShape = v5->Type == 2;
    v6 = v1->pMeshKey.pObject;
    if ( v6 )
    {
      v7 = v6->UseCount-- == 1;
      if ( v7 )
      {
        v8 = v6->pMesh.pObject;
        if ( !v8 || ((unsigned __int8 (*)(void))v8->vfptr[1].__vecDelDtor)() || v6->Flags & 0x110 )
          Scaleform::Render::MeshKeySet::DestroyKey(v6->pKeySet, v6);
      }
    }
    v1->pMeshKey.pObject = 0i64;
    v9 = v1->pRoot;
    if ( v9 )
    {
      v10 = v1->pParent;
      if ( v10 )
      {
        v11 = 16778241;
        if ( (v10->UpdateFlags & 0x80000000) == 0 )
        {
          v10->pNextUpdate = v9->pUpdateList;
          v9->pUpdateList = v10;
          v11 = -2130705407;
        }
        v10->UpdateFlags |= v11;
      }
    }
  }
  else if ( v1->pMeshKey.pObject )
  {
    Scaleform::Render::TreeCacheShapeLayer::updateTexture0Matrix(v1);
  }
  result.pImpl->vfptr->Release(result.pImpl, result.Data);
}

// File Line: 551
// RVA: 0x990780
void __fastcall Scaleform::Render::TreeCacheShapeLayer::HandleChanges(Scaleform::Render::TreeCacheShapeLayer *this, unsigned int changeBits)
{
  char v2; // di
  Scaleform::Render::TreeCacheShapeLayer *v3; // rbx
  Scaleform::Render::TreeCacheNode *v4; // rcx
  unsigned int v5; // er8
  signed __int64 v6; // rdx
  Scaleform::Render::TreeCacheRoot *v7; // rcx
  signed int v8; // eax

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
  if ( v2 & 0x10 )
  {
    v7 = v3->pRoot;
    if ( v7 )
    {
      v8 = 1;
      if ( (v3->UpdateFlags & 0x80000000) == 0 )
      {
        v3->pNextUpdate = v7->pUpdateList;
        v7->pUpdateList = (Scaleform::Render::TreeCacheNode *)&v3->vfptr;
        v8 = -2147483647;
      }
      v3->UpdateFlags |= v8;
      Scaleform::Render::TreeCacheShapeLayer::updateSortKeyGradientMorph(v3);
    }
  }
}

// File Line: 569
// RVA: 0x9BDA80
void __fastcall Scaleform::Render::TreeCacheShapeLayer::UpdateChildSubtree(Scaleform::Render::TreeCacheShapeLayer *this, Scaleform::Render::TreeNode::NodeData *data, unsigned __int16 depth)
{
  int v3; // ebp
  unsigned __int16 v4; // r14
  Scaleform::Render::TreeNode::NodeData *v5; // rdi
  Scaleform::Render::TreeCacheShapeLayer *v6; // rsi
  unsigned int v7; // ebx

  v3 = this->Flags;
  v4 = depth;
  v5 = data;
  v6 = this;
  v7 = v3 & 0xFFFFFFBF | (unsigned __int8)((2 * (this->Flags & 0x20) | this->pParent->Flags) & 0xC0);
  if ( data )
  {
    if ( Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::Scale9State>(data) )
      v7 |= 0x80u;
    if ( (v5->Flags >> 9) & 1 )
      v7 |= 0x200u;
  }
  if ( v7 != v3 )
  {
    v6->Flags = v7;
    Scaleform::Render::TreeCacheShapeLayer::updateSortKey(v6);
  }
  if ( v5 )
    Scaleform::Render::TreeCacheNode::updateMaskCache((Scaleform::Render::TreeCacheNode *)&v6->vfptr, v5, v4, 1);
}

// File Line: 593
// RVA: 0x9D3A40
__int64 __fastcall Scaleform::Render::TreeCacheShapeLayer::calcMeshKey(Scaleform::Render::TreeCacheShapeLayer *this, Scaleform::Render::ShapeMeshProvider *pmeshProvider, Scaleform::Render::Matrix2x4<float> *m, unsigned int drawLayer, float *keyData, Scaleform::Render::Scale9GridData *s9g, float morphRatio)
{
  unsigned int v7; // ebx
  Scaleform::Render::Matrix2x4<float> *v8; // r12
  Scaleform::Render::ShapeMeshProvider *v9; // r13
  Scaleform::Render::TreeCacheShapeLayer *v10; // r15
  unsigned int v11; // er14
  Scaleform::Render::TreeCacheShapeLayer *v12; // r11
  __m128 v13; // xmm6
  __m128 v14; // xmm7
  __m128 v15; // xmm8
  __m128 v16; // xmm9
  unsigned __int64 v17; // rbx
  signed __int64 v18; // r8
  unsigned __int64 v19; // rcx
  signed __int64 v20; // rax
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
  float *v38; // rax
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // eax
  signed __int64 v43; // rsi
  bool v44; // di
  unsigned int v45; // edx
  Scaleform::Render::DashArray *v46; // rcx
  Scaleform::Render::ComplexFill *v47; // rcx
  Scaleform::Render::TreeNode *v48; // rcx
  __int128 v50; // [rsp+30h] [rbp-B8h]
  __m128 v51; // [rsp+40h] [rbp-A8h]
  Scaleform::Render::StrokeStyleType s1; // [rsp+50h] [rbp-98h]
  unsigned int v53; // [rsp+108h] [rbp+20h]

  v53 = drawLayer;
  v7 = drawLayer;
  v8 = m;
  v9 = pmeshProvider;
  v10 = this;
  v11 = 1;
  if ( SLOBYTE(this->Flags) >= 0 )
    goto LABEL_45;
  v12 = this;
  if ( !this->pNode )
    v12 = (Scaleform::Render::TreeCacheShapeLayer *)this->pParent;
  v13 = (__m128)_xmm;
  v50 = _xmm;
  v14 = _xmm;
  v51 = _xmm;
  if ( !v12 )
    goto LABEL_45;
  v15 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v);
  v16 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v);
  while ( 1 )
  {
    v17 = *(_QWORD *)(*(_QWORD *)(((_QWORD)v12->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                    + 8
                    * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v12->pNode[-1]
                                                                                          - ((_QWORD)v12->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                     + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v12->pNode[-1]
                                                                              - ((_QWORD)v12->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                    + 40) & 0xFFFFFFFFFFFFFFFEui64;
    v18 = v17 + 64;
    v19 = *(_QWORD *)(v17 + 64);
    if ( !v19 )
      goto LABEL_18;
    if ( v19 & 1 )
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
    if ( !(v19 & 1) )
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
              _mm_and_ps(*(__m128 *)(v17 + 16), v15)),
            v16);
    v50 = (__int128)v13;
    v14 = _mm_and_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v17 + 32), *(__m128 *)(v17 + 32), 0), v29),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v17 + 32), *(__m128 *)(v17 + 32), 85), v14)),
              _mm_and_ps(*(__m128 *)(v17 + 32), v15)),
            v16);
    v51 = v14;
    if ( v24 )
      v12 = v24;
    else
      v12 = (Scaleform::Render::TreeCacheShapeLayer *)v12->pParent;
    if ( !v12 )
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
  *(_OWORD *)&s9g->ShapeMtx.M[0][0] = v50;
  *(__m128 *)&s9g->ShapeMtx.M[1][0] = v51;
  *(_OWORD *)&s9g->Scale9Mtx.M[0][0] = *(_OWORD *)(v17 + 16);
  *(_OWORD *)&s9g->Scale9Mtx.M[1][0] = *(_OWORD *)(v17 + 32);
  *(_OWORD *)&s9g->ViewMtx.M[0][0] = *(_OWORD *)&v8->M[0][0];
  *(_OWORD *)&s9g->ViewMtx.M[1][0] = *(_OWORD *)&v8->M[1][0];
  v37 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::OrigNodeBoundsState>((Scaleform::Render::TreeNode::NodeData *)v17);
  if ( v37 )
  {
    v38 = (float *)v37->pData;
    if ( v38 )
      v38 += 4;
    v39 = v38[3];
    v40 = v38[2];
    v41 = v38[1];
    v42 = *v38;
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
  v7 = v53;
LABEL_45:
  v43 = 3i64;
  if ( v11 & 0x10 )
  {
    Scaleform::Render::Scale9GridData::MakeMeshKey(s9g, keyData);
  }
  else
  {
    v44 = Scaleform::Render::MeshKey::CalcMatrixKey(v8, keyData, 0i64);
    v45 = v9->DrawLayers.Data.Data[v7].StrokeStyle;
    if ( v45 )
    {
      v11 = 2;
      s1.pFill.pObject = 0i64;
      s1.pDashes.pObject = 0i64;
      Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(v9, v45, &s1, 0.0);
      if ( s1.Flags & 1 )
        v11 = 3;
      if ( !(s1.Flags & 6) )
        v11 |= 0x20u;
      v46 = s1.pDashes.pObject;
      if ( s1.pDashes.pObject && !_InterlockedDecrement(&s1.pDashes.pObject->RefCount) && v46 )
        v46->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v46->vfptr, 1u);
      v47 = s1.pFill.pObject;
      if ( s1.pFill.pObject && !_InterlockedDecrement(&s1.pFill.pObject->RefCount) && v47 )
        v47->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v47->vfptr, 1u);
    }
    if ( !v44 )
      v11 |= 0x8000u;
  }
  v48 = v10->pNode;
  if ( !v48 )
    v48 = v10->pParent->pNode;
  if ( *(_BYTE *)(*(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v48 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                         + 8
                                         * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v48[-1] - ((unsigned __int64)v48 & 0xFFFFFFFFFFFFF000ui64))
                                                                                              * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                          + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v48[-1] - ((unsigned __int64)v48 & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                         + 40) & 0xFFFFFFFFFFFFFFFEui64)
                            + 144)
                + 128i64) )
    v11 |= 0x100u;
  if ( v11 & 0x10 )
    v43 = 13i64;
  keyData[v43] = morphRatio;
  return v11;
}

// File Line: 677
// RVA: 0x9FA090
char __fastcall Scaleform::Render::TreeCacheShapeLayer::updateMeshKey(Scaleform::Render::TreeCacheShapeLayer *this, Scaleform::Render::Renderer2DImpl *r2D, Scaleform::Render::ShapeMeshProvider *provider, float morphRatio, Scaleform::Render::Matrix2x4<float> *viewMatrix, unsigned int meshGenFlags, unsigned int *meshKeyFlags)
{
  Scaleform::Render::Renderer2DImpl *v7; // r15
  Scaleform::Render::TreeCacheShapeLayer *v8; // r14
  Scaleform::Render::ToleranceParams *v9; // rdi
  unsigned int v10; // er13
  Scaleform::Render::Scale9GridData *v11; // rsi
  signed int v12; // ebx
  unsigned int v13; // er12
  Scaleform::Render::MeshKey *v14; // rbx
  Scaleform::Render::MeshKeySet *v15; // rax
  Scaleform::Render::MeshKey *v16; // rdi
  signed __int64 v17; // r15
  Scaleform::Render::MeshKey *v20; // rax
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
  int v33; // [rsp+40h] [rbp-C0h]
  int v34; // [rsp+44h] [rbp-BCh]
  int v35; // [rsp+48h] [rbp-B8h]
  __int64 v36; // [rsp+50h] [rbp-B0h]
  Scaleform::Render::Scale9GridData *v37; // [rsp+58h] [rbp-A8h]
  __int64 v38; // [rsp+60h] [rbp-A0h]
  float keyData; // [rsp+70h] [rbp-90h]
  Scaleform::Render::Scale9GridData __that; // [rsp+C0h] [rbp-40h]
  Scaleform::Render::Renderer2DImpl *renderer; // [rsp+1A8h] [rbp+A8h]
  Scaleform::Render::ShapeMeshProvider *providera; // [rsp+1B0h] [rbp+B0h]
  unsigned int *meshKeyFlagsa; // [rsp+1D0h] [rbp+D0h]

  providera = provider;
  renderer = r2D;
  v36 = -2i64;
  v7 = r2D;
  v8 = this;
  v9 = &r2D->Tolerances;
  v10 = this->Layer;
  v11 = 0i64;
  v12 = 0;
  if ( meshGenFlags & 1 )
    v12 = 64;
  if ( meshGenFlags & 2 )
    v12 |= 0x80u;
  __that.RefCount = 1;
  __that.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Scale9GridData::`vftable';
  v13 = v12 | (unsigned __int64)Scaleform::Render::TreeCacheShapeLayer::calcMeshKey(
                                  this,
                                  provider,
                                  viewMatrix,
                                  v10,
                                  &keyData,
                                  &__that,
                                  morphRatio);
  if ( meshKeyFlags )
    *meshKeyFlags = v13;
  v14 = v8->pMeshKey.pObject;
  if ( !v14 )
  {
    v20 = Scaleform::Render::MeshKeyManager::CreateMatchingKey(
            v7->pMeshKeyManager.pObject,
            (Scaleform::Render::MeshProvider_KeySupport *)&providera->vfptr,
            v10,
            v13,
            &keyData,
            v9);
    goto LABEL_16;
  }
  if ( Scaleform::Render::MeshKey::Match(v14, v10, v13, &keyData, v9) )
    return 0;
  v15 = v14->pKeySet;
  meshKeyFlagsa = (unsigned int *)v15;
  v16 = v15->Meshes.Root.pNext;
  v17 = (signed __int64)&v15->Meshes;
  if ( v16 == (Scaleform::Render::MeshKey *)&v15->Meshes )
  {
LABEL_14:
    v20 = Scaleform::Render::MeshKeySet::CreateKey(v15, &keyData, v13);
    v7 = renderer;
LABEL_16:
    v16 = v20;
    goto LABEL_17;
  }
  while ( 1 )
  {
    _RAX = v16->pMesh.pObject;
    __asm
    {
      prefetcht1 byte ptr [rax+80h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+60h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+40h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+20h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax]; Prefetch to all cache levels
    }
    _RBX = v16->pNext;
    __asm
    {
      prefetcht1 byte ptr [rbx+20h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rbx]; Prefetch to all cache levels
    }
    if ( Scaleform::Render::MeshKey::Match(v16, v10, v13, &keyData, &renderer->Tolerances) )
      break;
    v16 = _RBX;
    if ( _RBX == (Scaleform::Render::MeshKey *)v17 )
    {
      v15 = (Scaleform::Render::MeshKeySet *)meshKeyFlagsa;
      goto LABEL_14;
    }
  }
  ++v16->UseCount;
  v7 = renderer;
LABEL_17:
  if ( !v16 )
    return 0;
  if ( !v16->pMesh.pObject )
  {
    v38 = 0i64;
    if ( v8->ComplexShape )
    {
      v34 = 68;
      v21 = (Scaleform::Render::ComplexMesh *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                v8,
                                                320ui64,
                                                (Scaleform::AllocInfo *)&v34);
      if ( v21 )
      {
        Scaleform::Render::ComplexMesh::ComplexMesh(
          v21,
          v7,
          (Scaleform::Render::MeshProvider *)&v16->pKeySet->vfptr,
          &v7->FillManager,
          viewMatrix,
          morphRatio,
          v10,
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
                                         v8,
                                         240ui64,
                                         (Scaleform::AllocInfo *)&v33);
      if ( v24 )
      {
        Scaleform::Render::Mesh::Mesh(
          v24,
          v7,
          (Scaleform::Render::MeshProvider *)&v16->pKeySet->vfptr,
          viewMatrix,
          morphRatio,
          v10,
          meshGenFlags);
        v23 = v25;
      }
      else
      {
        v23 = 0i64;
      }
    }
    v26 = v16->pMesh.pObject;
    if ( v26 && !_InterlockedDecrement(&v26->RefCount) && v26 )
      v26->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v26->vfptr, 1u);
    v16->pMesh.pObject = v23;
    if ( !v23 )
    {
      v27 = v16->UseCount-- == 1;
      if ( v27 )
        Scaleform::Render::MeshKeySet::DestroyKey(v16->pKeySet, v16);
      return 0;
    }
    if ( v13 & 0x10 )
    {
      v35 = 2;
      v29 = (Scaleform::Render::Scale9GridData *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   v8,
                                                   144ui64,
                                                   (Scaleform::AllocInfo *)&v35);
      if ( v29 )
      {
        Scaleform::Render::Scale9GridData::Scale9GridData(v29, &__that);
        v11 = v30;
      }
      v37 = v11;
      Scaleform::Render::MeshBase::SetScale9Grid(v16->pMesh.pObject, v11);
      if ( v11 && !_InterlockedDecrement(&v11->RefCount) )
        v11->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, 1u);
    }
  }
  v31 = v8->pMeshKey.pObject;
  if ( v31 )
  {
    v27 = v31->UseCount-- == 1;
    if ( v27 )
    {
      v32 = v31->pMesh.pObject;
      if ( !v32 || ((unsigned __int8 (*)(void))v32->vfptr[1].__vecDelDtor)() || v31->Flags & 0x110 )
        Scaleform::Render::MeshKeySet::DestroyKey(v31->pKeySet, v31);
    }
  }
  v8->pMeshKey.pObject = v16;
  return 1;
}

// File Line: 750
// RVA: 0x9E7660
void __fastcall Scaleform::Render::TreeCacheShapeLayer::getShapeMatrixFrom3D(Scaleform::Render::TreeCacheShapeLayer *this, Scaleform::Render::TreeShape::NodeData *nd, Scaleform::Render::Matrix2x4<float> *mat, Scaleform::Render::Matrix4x4<float> *viewProj)
{
  Scaleform::Render::TreeCacheShapeLayer *v4; // rdi
  Scaleform::Render::TreeShape::NodeData *v5; // rbp
  Scaleform::Render::Matrix4x4<float> *v6; // r14
  Scaleform::Render::Matrix2x4<float> *v7; // rbx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v8; // rax
  Scaleform::Render::Renderer2DImpl *v9; // rsi
  Scaleform::Render::Matrix3x4<float> *v10; // r8
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // rdx
  float v13; // xmm5_4
  __m128 v14; // xmm2
  float v15; // xmm3_4
  float v16; // xmm0_4
  __m128 v17; // xmm0
  float v18; // xmm2_4
  Scaleform::Render::Rect<float> bounds; // [rsp+30h] [rbp-98h]
  float src; // [rsp+40h] [rbp-88h]
  __int64 v21; // [rsp+44h] [rbp-84h]
  __int64 v22; // [rsp+4Ch] [rbp-7Ch]
  float v23; // [rsp+54h] [rbp-74h]
  float dst; // [rsp+60h] [rbp-68h]
  Scaleform::Render::Matrix4x4<float> v25; // [rsp+80h] [rbp-48h]

  v4 = this;
  v5 = nd;
  v6 = viewProj;
  v7 = mat;
  nd->pMeshProvider.pObject->vfptr->GetIdentityBounds(
    (Scaleform::Render::MeshProvider *)&nd->pMeshProvider.pObject->vfptr,
    &bounds);
  v8 = v4->M.pHandle;
  v9 = v4->pRenderer2D;
  if ( v8->pHeader->Format & 0x10 )
    v10 = (Scaleform::Render::Matrix3x4<float> *)&v8->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->pHeader->Format & 0xF].Offsets[4]
                                                            + 1];
  else
    v10 = &Scaleform::Render::Matrix3x4<float>::Identity;
  Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v25, v6, v10);
  v11 = (_QWORD)v4->pRoot->pNode & 0xFFFFFFFFFFFFF000ui64;
  v12 = *(_QWORD *)(*(_QWORD *)(v11 + 0x28)
                  + 8
                  * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4->pRoot->pNode[-1]
                                                                                        - v11)
                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                   + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4->pRoot->pNode[-1] - v11)
                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                  + 40) & 0xFFFFFFFFFFFFFFFEui64;
  Scaleform::Render::Matrix4x4<float>::TransformHomogeneousAndScaleCorners(
    &v25,
    &bounds,
    (float)*(signed int *)(v12 + 176),
    (float)*(signed int *)(v12 + 180),
    &dst);
  src = bounds.x1;
  v21 = *(_QWORD *)&bounds.y1;
  v23 = bounds.y2;
  v22 = *(_QWORD *)&bounds.y1;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(v7, &src, &dst);
  v13 = v7->M[1][1];
  v14 = (__m128)LODWORD(v7->M[1][0]);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v7->M[0][0] * v13) - (float)(v7->M[0][1] * v14.m128_f32[0])) & _xmm) < v9->Tolerances.MinDet3D )
  {
    v15 = v7->M[0][1] + v7->M[0][0];
    *(_QWORD *)&v7->M[0][1] = 0i64;
    *(_QWORD *)&v7->M[0][3] = 0i64;
    *(_QWORD *)&v7->M[1][2] = 0i64;
    v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] + v13) * 0.70710677)
                            * (float)((float)(v14.m128_f32[0] + v13) * 0.70710677))
                    + (float)((float)(v15 * 0.70710677) * (float)(v15 * 0.70710677));
    LODWORD(v16) = (unsigned __int128)_mm_sqrt_ps(v14);
    v7->M[0][0] = v16;
    v7->M[1][1] = v16;
  }
  if ( v5->pMeshProvider.pObject->DrawLayers.Data.Data[v4->Layer].StrokeStyle )
  {
    v17 = (__m128)LODWORD(v7->M[1][1]);
    v17.m128_f32[0] = (float)((float)((float)(v17.m128_f32[0] + v7->M[1][0]) * 0.70710677)
                            * (float)((float)(v17.m128_f32[0] + v7->M[1][0]) * 0.70710677))
                    + (float)((float)((float)(v7->M[0][1] + v7->M[0][0]) * 0.70710677)
                            * (float)((float)(v7->M[0][1] + v7->M[0][0]) * 0.70710677));
    LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v17);
    if ( v18 < v9->Tolerances.MinScale3D )
      v18 = v9->Tolerances.MinScale3D;
    v7->M[0][0] = v18;
    v7->M[1][1] = v18;
    *(_QWORD *)&v7->M[0][1] = 0i64;
    *(_QWORD *)&v7->M[0][3] = 0i64;
    *(_QWORD *)&v7->M[1][2] = 0i64;
  }
}

// File Line: 783
// RVA: 0x9BFB90
void __fastcall Scaleform::Render::TreeCacheShapeLayer::UpdateTransform(Scaleform::Render::TreeCacheShapeLayer *this, Scaleform::Render::TreeNode::NodeData *nodeData, Scaleform::Render::TransformArgs *t, Scaleform::Render::TransformFlags flags)
{
  float v4; // xmm1_4
  Scaleform::Render::TransformFlags v5; // er12
  Scaleform::Render::TransformArgs *v6; // rbx
  Scaleform::Render::TreeNode::NodeData *v7; // r14
  Scaleform::Render::TreeCacheShapeLayer *v8; // rdi
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  unsigned int meshGenFlags; // esi
  char v15; // r15
  Scaleform::Render::Matrix4x4<float> *v16; // rax
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  int v20; // xmm0_4
  int v21; // xmm1_4
  int v22; // xmm0_4
  int v23; // xmm1_4
  unsigned __int16 v24; // cx
  float v25; // xmm0_4
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  int v28; // xmm1_4
  float v29; // xmm0_4
  int v30; // xmm1_4
  int v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  signed int v34; // ecx
  signed int v35; // edx
  Scaleform::Render::Bundle *v36; // rcx
  Scaleform::Render::Rect<float> cullRect; // [rsp+40h] [rbp-30h]
  int v38; // [rsp+50h] [rbp-20h]
  int v39; // [rsp+54h] [rbp-1Ch]
  int v40; // [rsp+58h] [rbp-18h]
  int v41; // [rsp+5Ch] [rbp-14h]
  unsigned int meshKeyFlags; // [rsp+B8h] [rbp+48h]

  v4 = t->CullRect.y1;
  v5 = flags;
  v6 = t;
  v7 = nodeData;
  v8 = this;
  cullRect.x1 = t->CullRect.x1;
  v9 = t->CullRect.x2;
  cullRect.y1 = v4;
  v10 = t->CullRect.y2;
  cullRect.x2 = v9;
  cullRect.y2 = v10;
  Scaleform::Render::TreeCacheNode::updateCulling(
    (Scaleform::Render::TreeCacheNode *)&this->vfptr,
    nodeData,
    t,
    &cullRect,
    (Scaleform::Render::TransformFlags)(flags | 0x20));
  v11 = v7->AproxParentBounds.x1;
  v12 = v7->AproxParentBounds.x2;
  v13 = v7->AproxParentBounds.y1;
  v8->SortParentBounds.y2 = v7->AproxParentBounds.y2;
  v8->SortParentBounds.x1 = v11;
  v8->SortParentBounds.y1 = v13;
  v8->SortParentBounds.x2 = v12;
  v8->Flags &= 0xFBFFu;
  ((void (__fastcall *)(Scaleform::Render::TreeCacheShapeLayer *, Scaleform::Render::TransformArgs *, _QWORD))v8->vfptr[1].__vecDelDtor)(
    v8,
    v6,
    (unsigned int)v5);
  if ( v5 & 1 && v8->pMeshKey.pObject )
  {
    meshGenFlags = 0;
    v15 = 0;
    meshKeyFlags = 0;
    if ( (v5 & 0x80u) != 0 && v8->pRoot )
    {
      v16 = Scaleform::Render::TransformArgs::GetViewProj(v6);
      Scaleform::Render::TreeCacheShapeLayer::getShapeMatrixFrom3D(
        v8,
        (Scaleform::Render::TreeShape::NodeData *)v7,
        (Scaleform::Render::Matrix2x4<float> *)&cullRect,
        v16);
    }
    else
    {
      v17 = v6->Mat.M[0][1];
      cullRect.x1 = v6->Mat.M[0][0];
      v18 = v6->Mat.M[0][2];
      cullRect.y1 = v17;
      v19 = v6->Mat.M[0][3];
      cullRect.x2 = v18;
      v20 = LODWORD(v6->Mat.M[1][0]);
      cullRect.y2 = v19;
      v21 = LODWORD(v6->Mat.M[1][1]);
      v38 = v20;
      v22 = LODWORD(v6->Mat.M[1][2]);
      v39 = v21;
      v23 = LODWORD(v6->Mat.M[1][3]);
      v40 = v22;
      v41 = v23;
    }
    v24 = v8->Flags;
    if ( v24 & 0x40 )
    {
      meshGenFlags = 2;
    }
    else if ( (v24 & 0xC) == 4 )
    {
      meshGenFlags = 1;
    }
    if ( (v24 & 0x80u) != 0 )
      meshGenFlags |= 8u;
    if ( Scaleform::Render::TreeCacheShapeLayer::updateMeshKey(
           v8,
           v8->pRenderer2D,
           (Scaleform::Render::ShapeMeshProvider *)v7[1].vfptr,
           *(float *)&v7[1].Type,
           (Scaleform::Render::Matrix2x4<float> *)&cullRect,
           meshGenFlags,
           &meshKeyFlags) )
    {
      v15 = 1;
      if ( 0.0 != *(float *)&v7[1].Type )
        Scaleform::Render::TreeCacheShapeLayer::updateTexture0Matrix(v8);
    }
    if ( !(v8->M.pHandle->pHeader->Format & 0x10) && (meshKeyFlags & 7) == 3 )
    {
      v25 = v6->Mat.M[0][0];
      v26 = (__m128)LODWORD(v6->Mat.M[0][3]);
      v27 = (__m128)LODWORD(v6->Mat.M[1][3]);
      cullRect.y1 = v6->Mat.M[0][1];
      v28 = LODWORD(v6->Mat.M[1][0]);
      cullRect.x1 = v25;
      v29 = v6->Mat.M[0][2];
      v38 = v28;
      v30 = LODWORD(v6->Mat.M[1][2]);
      cullRect.x2 = v29;
      v31 = LODWORD(v6->Mat.M[1][1]);
      v40 = v30;
      v32 = FLOAT_N0_5;
      v39 = v31;
      if ( v26.m128_f32[0] >= 0.0 )
        v33 = FLOAT_0_5;
      else
        v33 = FLOAT_N0_5;
      v26.m128_f32[0] = v26.m128_f32[0] + v33;
      v34 = (signed int)v26.m128_f32[0];
      if ( (signed int)v26.m128_f32[0] != 0x80000000 && (float)v34 != v26.m128_f32[0] )
        v26.m128_f32[0] = (float)(v34 - (_mm_movemask_ps(_mm_unpacklo_ps(v26, v26)) & 1));
      LODWORD(cullRect.y2) = v26.m128_i32[0];
      if ( v27.m128_f32[0] >= 0.0 )
        v32 = FLOAT_0_5;
      v27.m128_f32[0] = v27.m128_f32[0] + v32;
      v35 = (signed int)v27.m128_f32[0];
      if ( (signed int)v27.m128_f32[0] != 0x80000000 && (float)v35 != v27.m128_f32[0] )
        v27.m128_f32[0] = (float)(v35 - (_mm_movemask_ps(_mm_unpacklo_ps(v27, v27)) & 1));
      v41 = v27.m128_i32[0];
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&v8->M, (Scaleform::Render::Matrix2x4<float> *)&cullRect);
    }
    v36 = v8->SorterShapeNode.pBundle.pObject;
    if ( v36 )
    {
      if ( v15 )
        v36->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v36->vfptr, (unsigned int)&v8->SorterShapeNode);
    }
  }
}

// File Line: 842
// RVA: 0x9892A0
Scaleform::Render::MeshStagingNode *__fastcall Scaleform::Render::TreeCacheShapeLayer::GetMesh(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeCacheShapeLayer *v1; // rbx
  Scaleform::Render::MeshKey *v2; // rax
  unsigned __int16 v3; // cx
  unsigned int v4; // edi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v5; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v6; // rdx
  Scaleform::Render::TreeShape::NodeData *v7; // rax
  int v8; // eax
  unsigned int v9; // xmm1_4
  unsigned int v10; // xmm0_4
  Scaleform::Render::TreeNode *v11; // r10
  Scaleform::Render::TreeNode *v12; // rcx
  Scaleform::Render::Bundle *v13; // rax
  Scaleform::Render::ShapeMeshProvider *v14; // rax
  Scaleform::Render::MeshStagingNode *v15; // rax
  Scaleform::Render::Matrix2x4<float> *viewMatrix; // [rsp+20h] [rbp-88h]
  __int64 meshGenFlags; // [rsp+28h] [rbp-80h]
  Scaleform::Render::Matrix2x4<float> mat; // [rsp+40h] [rbp-68h]
  Scaleform::Render::Matrix4x4<float> result; // [rsp+60h] [rbp-48h]

  v1 = this;
  if ( this->pRoot )
  {
    v2 = this->pMeshKey.pObject;
    if ( !v2 || !v2->pMesh.pObject )
    {
      v3 = this->Flags;
      if ( v3 & 0x40 )
      {
        v4 = 2;
      }
      else
      {
        v4 = 0;
        if ( (v3 & 0xC) == 4 )
          v4 = 1;
      }
      if ( (v3 & 0x80u) != 0 )
        v4 |= 8u;
      v5 = v1->M.pHandle;
      v6 = v5->pHeader;
      if ( v5->pHeader->Format & 0x10 )
      {
        Scaleform::Render::TreeCacheNode::GetViewProj((Scaleform::Render::TreeCacheNode *)&v1->vfptr, &result);
        v7 = Scaleform::Render::TreeCacheShapeLayer::GetShapeNodeData(v1);
        Scaleform::Render::TreeCacheShapeLayer::getShapeMatrixFrom3D(v1, v7, &mat, &result);
      }
      else
      {
        v8 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v6->Format & 0xF].Offsets[4];
        v9 = HIDWORD(v6[v8 + 1].pHandle);
        mat.M[0][0] = *(float *)&v6[v8 + 1].pHandle;
        *(_QWORD *)&mat.M[0][1] = __PAIR__(v6[v8 + 1].RefCount, v9);
        v10 = (unsigned int)v6[v8 + 2].pHandle;
        mat.M[0][3] = *(float *)&v6[v8 + 1].DataPageOffset;
        *(_QWORD *)&mat.M[1][0] = __PAIR__(HIDWORD(v6[v8 + 2].pHandle), v10);
        *(_QWORD *)&mat.M[1][2] = *(_QWORD *)&v6[v8 + 2].RefCount;
      }
      v11 = v1->pNode;
      if ( v11 )
        v12 = v1->pNode;
      else
        v12 = v1->pParent->pNode;
      if ( !v11 )
        v11 = v1->pParent->pNode;
      Scaleform::Render::TreeCacheShapeLayer::updateMeshKey(
        v1,
        v1->pRenderer2D,
        *(Scaleform::Render::ShapeMeshProvider **)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v11 & 0xFFFFFFFFFFFFF000ui64)
                                                                          + 0x28)
                                                              + 8
                                                              * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v11[-1] - ((unsigned __int64)v11 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                               + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v11[-1] - ((unsigned __int64)v11 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                              + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                                 + 144),
        *(float *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                              + 8
                              * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v12[-1] - ((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64))
                                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                               + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v12[-1]
                                                                                        - ((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64))
                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                              + 40) & 0xFFFFFFFFFFFFFFFEui64)
                 + 152),
        &mat,
        v4,
        0i64);
      if ( !v1->ComplexShape )
      {
        v13 = v1->SorterShapeNode.pBundle.pObject;
        if ( v13 )
        {
          if ( *(_QWORD *)(*(_QWORD *)&v13[1].NeedUpdate + 32i64) )
          {
            *(_OWORD *)&mat.M[0][0] = _xmm;
            *(__m128 *)&mat.M[1][0] = _xmm;
            v14 = Scaleform::Render::TreeCacheShapeLayer::GetMeshProvider(v1);
            LODWORD(meshGenFlags) = v4;
            LODWORD(viewMatrix) = 0;
            v14->vfptr->GetFillMatrix(
              (Scaleform::Render::MeshProvider *)&v14->vfptr,
              v1->pMeshKey.pObject->pMesh.pObject,
              &mat,
              v1->Layer,
              (unsigned int)viewMatrix,
              meshGenFlags);
            Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(&v1->M, &mat, 0);
          }
        }
      }
    }
  }
  v15 = (Scaleform::Render::MeshStagingNode *)v1->pMeshKey.pObject;
  if ( v15 )
    v15 = (Scaleform::Render::MeshStagingNode *)v15->StagingBufferSize;
  return v15;
}

// File Line: 886
// RVA: 0x9A9F80
void __fastcall Scaleform::Render::TreeCacheShapeLayer::RemoveMesh(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::MeshKey *v1; // rbx
  Scaleform::Render::TreeCacheShapeLayer *v2; // rdi
  bool v3; // zf
  Scaleform::Render::MeshBase *v4; // rcx

  v1 = this->pMeshKey.pObject;
  v2 = this;
  if ( v1 && (v3 = v1->UseCount == 1, --v1->UseCount, v3) )
  {
    v4 = v1->pMesh.pObject;
    if ( !v4 || ((unsigned __int8 (*)(void))v4->vfptr[1].__vecDelDtor)() || v1->Flags & 0x110 )
      Scaleform::Render::MeshKeySet::DestroyKey(v1->pKeySet, v1);
    v2->pMeshKey.pObject = 0i64;
  }
  else
  {
    this->pMeshKey.pObject = 0i64;
  }
}

// File Line: 893
// RVA: 0x9EE1E0
void __fastcall Scaleform::Render::TreeCacheShapeLayer::propagateMaskFlag(Scaleform::Render::TreeCacheShapeLayer *this, unsigned int partOfMask)
{
  if ( (partOfMask | this->Flags & 0xFFBF) != this->Flags )
  {
    this->Flags = partOfMask | this->Flags & 0xFFBF;
    Scaleform::Render::TreeCacheShapeLayer::updateSortKey(this);
  }
}

// File Line: 903
// RVA: 0x9EE400
void __fastcall Scaleform::Render::TreeCacheShapeLayer::propagateScale9Flag(Scaleform::Render::TreeCacheShapeLayer *this, unsigned int partOfScale9)
{
  Scaleform::Render::TreeCacheShapeLayer *v2; // rbx
  Scaleform::Render::TreeNode *v3; // rcx
  unsigned int v4; // edi
  int v5; // ecx

  v2 = this;
  v3 = this->pNode;
  v4 = partOfScale9;
  if ( v3
    && Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::Scale9State>((Scaleform::Render::TreeNode::NodeData *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64) + 0x28) + 8 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1] - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4) + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1] - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 63)) + 40) & 0xFFFFFFFFFFFFFFFEui64)) )
  {
    v4 |= 0x80u;
  }
  v5 = v4 | (unsigned __int16)(v2->Flags & 0xFF7F);
  if ( v5 != v2->Flags )
  {
    v2->Flags = v5;
    Scaleform::Render::TreeCacheShapeLayer::updateSortKey(v2);
  }
}

// File Line: 916
// RVA: 0x9EE040
void __fastcall Scaleform::Render::TreeCacheShapeLayer::propagateEdgeAA(Scaleform::Render::TreeCacheShapeLayer *this, Scaleform::Render::EdgeAAMode parentEdgeAA)
{
  Scaleform::Render::TreeCacheShapeLayer *v2; // r9
  Scaleform::Render::TreeNode *v3; // rcx
  Scaleform::Render::EdgeAAMode v4; // er8
  unsigned __int64 v5; // rdx
  int v6; // eax

  v2 = this;
  v3 = this->pNode;
  v4 = parentEdgeAA;
  if ( v3 )
  {
    v5 = ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1]
                                                                - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64))
                                               * (signed __int128)5270498306774157605i64) >> 64) >> 63)
       + ((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1]
                                                              - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64))
                                             * (signed __int128)5270498306774157605i64) >> 64) >> 4);
    if ( v4 != 12 )
    {
      v6 = *(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                 + 8i64 * (unsigned int)v5
                                 + 40) & 0xFFFFFFFFFFFFFFFEui64)
                    + 10) & 0xC;
      if ( !v6 )
        v6 = v4;
      v4 = v6;
    }
  }
  if ( (v2->Flags & 0xC) != v4 )
  {
    v2->Flags = v4 | v2->Flags & 0xFFF3;
    Scaleform::Render::TreeCacheShapeLayer::updateSortKey(v2);
  }
}

// File Line: 928
// RVA: 0x9EDE00
void __fastcall Scaleform::Render::TreeCacheShapeLayer::propagate3DFlag(Scaleform::Render::TreeCacheShapeLayer *this, unsigned int parent3D)
{
  Scaleform::Render::TreeCacheShapeLayer::updateSortKey(this);
}

