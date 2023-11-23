// File Line: 34
// RVA: 0x946AC0
void __fastcall Scaleform::Render::TreeCacheText::TreeCacheText(
        Scaleform::Render::TreeCacheText *this,
        Scaleform::Render::TreeText *node,
        Scaleform::Render::Renderer2DImpl *prenderer2D,
        unsigned __int16 flags)
{
  Scaleform::Render::SKI_TextPrimitive *v8; // rbx
  Scaleform::Render::SortKeyInterfaceVtbl *vfptr; // rax
  Scaleform::Render::SortKey key; // [rsp+38h] [rbp-30h] BYREF

  if ( (flags & 0x200) != 0 )
  {
    v8 = &Scaleform::Render::SKI_TextPrimitive::Instance3D;
    key.pImpl = &Scaleform::Render::SKI_TextPrimitive::Instance3D;
    vfptr = Scaleform::Render::SKI_TextPrimitive::Instance3D.vfptr;
  }
  else
  {
    v8 = &Scaleform::Render::SKI_TextPrimitive::Instance;
    key.pImpl = &Scaleform::Render::SKI_TextPrimitive::Instance;
    vfptr = Scaleform::Render::SKI_TextPrimitive::Instance.vfptr;
  }
  key.Data = 0i64;
  vfptr->AddRef(v8, 0i64);
  Scaleform::Render::TreeCacheMeshBase::TreeCacheMeshBase(this, node, &key, prenderer2D, flags);
  v8->vfptr->Release(v8, 0i64);
  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheText::`vftable;
  this->pNextNoBatch = 0i64;
  Scaleform::Render::TextMeshProvider::TextMeshProvider(&this->TMProvider, this->pRenderer2D->pGlyphCache.pObject);
}

// File Line: 52
// RVA: 0x9BDB30
void __fastcall Scaleform::Render::TreeCacheText::UpdateChildSubtree(
        Scaleform::Render::TreeCacheText *this,
        Scaleform::Render::TreeNode::NodeData *data,
        unsigned __int16 depth)
{
  int v3; // r9d

  v3 = this->Flags & 0xFFBF | ((unsigned __int8)(2 * (this->Flags & 0x20)) | (unsigned __int8)this->pParent->Flags) & 0xC0;
  if ( data && (data->Flags & 0x200) != 0 )
    v3 |= 0x200u;
  if ( v3 != this->Flags )
    this->Flags = v3;
  if ( data )
    Scaleform::Render::TreeCacheNode::updateMaskCache(this, data, depth, 1);
}

// File Line: 83
// RVA: 0x9BE040
void __fastcall Scaleform::Render::TreeCacheText::UpdateDistanceFieldUniforms(Scaleform::Render::TreeCacheText *this)
{
  Scaleform::Render::TreeNode *pNode; // rcx
  __int64 v3; // rcx
  float v4; // xmm2_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  __m128 v7; // xmm2
  float v8; // xmm3_4
  __m128 v9; // xmm1
  float v10; // xmm0_4
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rdx
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // r8
  int v13; // ecx
  float pr[2]; // [rsp+30h] [rbp-40h] BYREF
  float pa[2]; // [rsp+38h] [rbp-38h] BYREF
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v16; // [rsp+40h] [rbp-30h]
  __int64 v17; // [rsp+48h] [rbp-28h]
  _QWORD v18[3]; // [rsp+50h] [rbp-20h] BYREF
  __int64 v19; // [rsp+68h] [rbp-8h]

  if ( (this->TMProvider.Flags & 0x200) != 0 )
  {
    pNode = this->pNode;
    *((float *)&v19 + 1) = FLOAT_9_0;
    memset(v18, 0, 20);
    LODWORD(v16) = 0;
    v3 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                + 8i64
                                * (unsigned int)((int)((_DWORD)pNode - ((unsigned int)pNode & 0xFFFFF000) - 56) / 56)
                                + 40) & 0xFFFFFFFFFFFFFFFEui64)
                   + 144);
    v4 = *(float *)(v3 + 264);
    if ( v4 > 0.0 )
    {
      v5 = v4 * 0.050000001;
      LODWORD(v16) = (_DWORD)FLOAT_1_0;
      v6 = FLOAT_3_0;
      if ( v5 <= 3.0 )
        v6 = v5;
      v7 = (__m128)*(unsigned int *)(v3 + 272);
      v7.m128_f32[0] = v7.m128_f32[0] * -0.050000001;
      v8 = *(float *)(v3 + 276) * -0.050000001;
      *(float *)&v18[2] = v6 * 18.0;
      v9 = v7;
      v18[0] = __PAIR64__(LODWORD(v8), v7.m128_u32[0]);
      v9.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v8 * v8);
      if ( v9.m128_f32[0] > 4.0 )
      {
        v10 = _mm_sqrt_ps(v9).m128_f32[0];
        *(float *)v18 = v7.m128_f32[0] * (float)(2.0 / v10);
        *((float *)v18 + 1) = v8 * (float)(2.0 / v10);
      }
      Scaleform::Render::Color::GetRGBAFloat((Scaleform::Render::Color *)(v3 + 284), pr, &pr[1], pa, &pa[1]);
    }
    pHandle = this->M.pHandle;
    if ( (pHandle->pHeader->Format & 8) == 0 )
      Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
        *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_QWORD *)(((unsigned __int64)pHandle & 0xFFFFFFFFFFFFF800ui64)
                                                                      + 0x20)
                                                          + 8i64),
        pHandle,
        (unsigned __int8)pHandle->pHeader->Format | 8);
    pHeader = this->M.pHandle->pHeader;
    v13 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[3];
    pHeader[v13 + 1].pHandle = *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)pr;
    *(_QWORD *)&pHeader[v13 + 1].RefCount = *(_QWORD *)pa;
    pHeader[v13 + 2].pHandle = v16;
    *(_QWORD *)&pHeader[v13 + 2].RefCount = v17;
    pHeader[v13 + 3].pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)v18[0];
    *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&pHeader[v13 + 3].RefCount = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&v18[1];
    *(_QWORD *)&pHeader[v13 + 4].RefCount = v19;
  }
}

// File Line: 116
// RVA: 0x9BFED0
void __fastcall Scaleform::Render::TreeCacheText::UpdateTransform(
        Scaleform::Render::TreeCacheText *this,
        Scaleform::Render::TreeNode::NodeData *nodeData,
        Scaleform::Render::TransformArgs *t,
        unsigned int flags)
{
  float y2; // xmm3_4
  float x2; // xmm2_4
  int y1_low; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float y1; // xmm0_4
  __int64 v14; // r15
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v15; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v16; // rdx
  int v17; // eax
  __int64 v18; // rcx
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  float v21; // xmm1_4
  float v22; // xmm0_4
  int v23; // ecx
  int v24; // edx
  Scaleform::Render::Bundle *v25; // rbx
  Scaleform::Render::Matrix4x4<float> *ViewProj; // r9
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v27; // rax
  Scaleform::Render::Matrix3x4<float> *v28; // r8
  float v29; // xmm0_4
  float v30; // xmm3_4
  float HeightRatio; // xmm2_4
  unsigned __int16 v32; // cx
  unsigned int meshGenFlags; // r13d
  unsigned int i; // r15d
  Scaleform::Render::TextMeshLayer *v35; // rbx
  Scaleform::Render::TextMeshEntry *v36; // rdx
  float SizeScale; // xmm3_4
  unsigned int v38; // r14d
  Scaleform::Render::Renderer2DImpl *pRenderer2D; // rcx
  Scaleform::Render::MeshKeyManager *pObject; // r12
  Scaleform::Render::ToleranceParams *p_Tolerances; // rdi
  Scaleform::Render::MeshKey *v42; // rcx
  Scaleform::Render::MeshKey *MatchingKey; // r14
  Scaleform::Render::MeshKey *v44; // rdi
  bool v45; // zf
  Scaleform::Render::MeshBase *v46; // rcx
  Scaleform::Render::MeshBase *v47; // rax
  Scaleform::Render::MeshBase *v48; // rdi
  Scaleform::Render::MeshKey *v49; // r14
  Scaleform::Render::MeshBase *v50; // rcx
  Scaleform::Render::Mesh *v51; // rdi
  Scaleform::Render::Mesh *v52; // rcx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  __int64 DataPageOffset; // rcx
  Scaleform::Render::Viewport vp; // [rsp+40h] [rbp-80h] BYREF
  float v57; // [rsp+6Ch] [rbp-54h]
  Scaleform::Render::Matrix2x4<float> m; // [rsp+70h] [rbp-50h] BYREF
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+90h] [rbp-30h] BYREF
  float v60; // [rsp+A0h] [rbp-20h]
  float v61; // [rsp+A4h] [rbp-1Ch]
  float v62; // [rsp+B0h] [rbp-10h]
  float v63; // [rsp+B4h] [rbp-Ch]
  __int64 v64; // [rsp+C0h] [rbp+0h]
  Scaleform::Render::MeshBase *v65; // [rsp+C8h] [rbp+8h]
  Scaleform::Render::Matrix4x4<float> Dst; // [rsp+D0h] [rbp+10h] BYREF
  float v67[36]; // [rsp+110h] [rbp+50h] BYREF
  Scaleform::Render::Matrix2x4<float> *p_m; // [rsp+1C0h] [rbp+100h]
  void *p; // [rsp+1C8h] [rbp+108h] BYREF
  unsigned int v70; // [rsp+1D0h] [rbp+110h]
  unsigned int v71; // [rsp+1D8h] [rbp+118h]

  v64 = -2i64;
  y2 = t->CullRect.y2;
  x2 = t->CullRect.x2;
  y1_low = LODWORD(t->CullRect.y1);
  vp.ScissorWidth = LODWORD(t->CullRect.x1);
  vp.ScissorHeight = y1_low;
  *(float *)&vp.Flags = x2;
  v57 = y2;
  Scaleform::Render::TreeCacheNode::updateCulling(
    this,
    nodeData,
    t,
    (Scaleform::Render::Rect<float> *)&vp.ScissorWidth,
    (Scaleform::Render::TransformFlags)(flags | 0x20));
  v11 = nodeData->AproxParentBounds.y2;
  v12 = nodeData->AproxParentBounds.x2;
  y1 = nodeData->AproxParentBounds.y1;
  this->SortParentBounds.x1 = nodeData->AproxParentBounds.x1;
  this->SortParentBounds.y1 = y1;
  this->SortParentBounds.x2 = v12;
  this->SortParentBounds.y2 = v11;
  this->Flags &= ~0x400u;
  ((void (__fastcall *)(Scaleform::Render::TreeCacheText *, Scaleform::Render::TransformArgs *, _QWORD))this->vfptr[1].__vecDelDtor)(
    this,
    t,
    flags);
  v14 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                               + 8i64
                               * (unsigned int)((int)(LODWORD(this->pNode) - ((__int64)this->pNode & 0xFFFFF000) - 56)
                                              / 56)
                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                  + 152);
  v70 = flags & 1;
  if ( (flags & 1) == 0 )
  {
LABEL_31:
    if ( (this->TMProvider.Flags & 0x40) != 0 )
    {
      v32 = this->Flags;
      if ( (v32 & 0x40) != 0 )
        meshGenFlags = 2;
      else
        meshGenFlags = (v32 & 0xC) == 4;
      if ( (v32 & 0x80u) != 0 )
        meshGenFlags |= 8u;
      for ( i = 0; i < this->TMProvider.vfptr->GetLayerCount(&this->TMProvider); ++i )
      {
        v35 = &this->TMProvider.Layers.Data.Data[(unsigned __int64)i];
        if ( ((v35->Type - 8) & 0xFFFFFFFB) == 0 )
        {
          v36 = &this->TMProvider.Entries.Data.Data[v35->Start];
          SizeScale = v35->SizeScale;
          *(float *)&vp.BufferWidth = this->TMProvider.HeightRatio * SizeScale;
          *(_QWORD *)&vp.BufferHeight = 0i64;
          *(_QWORD *)&vp.Top = 0i64;
          vp.Height = vp.BufferWidth;
          *(_QWORD *)&vp.ScissorLeft = 0i64;
          v38 = Scaleform::Render::TextMeshProvider::CalcVectorParams(
                  v35,
                  v36,
                  (Scaleform::Render::Matrix2x4<float> *)&vp,
                  SizeScale);
          pRenderer2D = this->pRenderer2D;
          pObject = pRenderer2D->pMeshKeyManager.pObject;
          p_Tolerances = &pRenderer2D->Tolerances;
          v42 = v35->pMeshKey.pObject;
          if ( !v42 || !Scaleform::Render::MeshKey::Match(v42, 0, v71, v67, p_Tolerances) )
          {
            MatchingKey = Scaleform::Render::MeshKeyManager::CreateMatchingKey(
                            pObject,
                            v35->pShape.pObject,
                            0,
                            v38,
                            v67,
                            p_Tolerances);
            v44 = v35->pMeshKey.pObject;
            if ( v44 )
            {
              v45 = v44->UseCount-- == 1;
              if ( v45 )
              {
                v46 = v44->pMesh.pObject;
                if ( !v46
                  || ((unsigned __int8 (__fastcall *)(Scaleform::Render::MeshBase *))v46->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(v46)
                  || (v44->Flags & 0x110) != 0 )
                {
                  Scaleform::Render::MeshKeySet::DestroyKey(v44->pKeySet, v44);
                }
              }
            }
            v35->pMeshKey.pObject = MatchingKey;
            if ( !MatchingKey->pMesh.pObject )
            {
              LODWORD(p) = 68;
              v47 = (Scaleform::Render::MeshBase *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this,
                                                     240i64,
                                                     &p);
              v48 = v47;
              v65 = v47;
              if ( v47 )
              {
                Scaleform::Render::MeshBase::MeshBase(
                  v47,
                  this->pRenderer2D,
                  v35->pMeshKey.pObject->pKeySet,
                  (Scaleform::Render::Matrix2x4<float> *)&vp,
                  0.0,
                  0,
                  meshGenFlags);
                v48->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Mesh::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>};
                v48->Scaleform::Render::MeshStagingNode::vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::Mesh::`vftable{for `Scaleform::Render::MeshStagingNode};
                v48[1].Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = 0i64;
                v48[1].pNext = (Scaleform::Render::MeshStagingNode *)1065353216;
                v48[1].StagingBufferSize = 0i64;
                LODWORD(v48[1].StagingBufferOffset) = 0;
                *(unsigned __int64 *)((char *)&v48[1].StagingBufferOffset + 4) = 1065353216i64;
                HIDWORD(v48[1].StagingBufferIndexOffset) = 0;
                LOBYTE(v48[1].PinCount) = 0;
              }
              else
              {
                v48 = 0i64;
              }
              v49 = v35->pMeshKey.pObject;
              v50 = v49->pMesh.pObject;
              if ( v50 && !_InterlockedDecrement(&v50->RefCount) )
                v50->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
                  v50,
                  1u);
              v49->pMesh.pObject = v48;
            }
            v51 = (Scaleform::Render::Mesh *)v35->pMeshKey.pObject->pMesh.pObject;
            if ( v51 )
              _InterlockedExchangeAdd(&v51->RefCount, 1u);
            v52 = v35->pMesh.pObject;
            if ( v52 && !_InterlockedDecrement(&v52->RefCount) )
              v52->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
                v52,
                1u);
            v35->pMesh.pObject = v51;
          }
        }
      }
    }
    if ( v70 && (this->TMProvider.Flags & 0x100) != 0 )
    {
      p_m = &m;
      pHandle = this->M.pHandle;
      *(_QWORD *)&m.M[0][0] = pHandle;
      if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
        ++pHandle->pHeader->RefCount;
      Scaleform::Render::TextMeshProvider::UpdateMaskClearBounds(
        &this->TMProvider,
        &result,
        (Scaleform::Render::MatrixPoolImpl::HMatrix)&m);
      if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      {
        pHeader = result.pHandle->pHeader;
        v45 = result.pHandle->pHeader->RefCount-- == 1;
        if ( v45 )
        {
          DataPageOffset = pHeader->DataPageOffset;
          *(_WORD *)((char *)&pHeader[1].RefCount + DataPageOffset + 2) += 16 * (unsigned __int8)pHeader->UnitSize;
          (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&pHeader[1].pHandle + DataPageOffset))[5].pHeader += (unsigned __int8)pHeader->UnitSize;
          Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(pHeader->pHandle);
          pHeader->pHandle = 0i64;
        }
      }
    }
    return;
  }
  if ( (*(_BYTE *)(v14 + 28) & 1) != 0 )
  {
    v15 = this->M.pHandle;
    v16 = v15->pHeader;
    if ( (v15->pHeader->Format & 0x10) == 0 )
    {
      v17 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v16->Format & 0xF].Offsets[4];
      v60 = *(float *)&v16[v17 + 1].pHandle;
      v61 = *((float *)&v16[v17 + 1].pHandle + 1);
      v62 = *(float *)&v16[v17 + 2].pHandle;
      v63 = *((float *)&v16[v17 + 2].pHandle + 1);
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v61 * 0.0) + v60) & _xmm) <= 0.000001
        || COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v63 * 0.0) + v62) & _xmm) <= 0.000001 )
      {
        v18 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v16->Format & 0xF].Offsets[4];
        *(_QWORD *)&m.M[0][0] = v16[v18 + 1].pHandle;
        LODWORD(m.M[0][2]) = v16[v18 + 1].RefCount;
        v19 = (__m128)*(unsigned int *)&v16[v18 + 1].DataPageOffset;
        m.M[1][0] = *(float *)&v16[v18 + 2].pHandle;
        *(_QWORD *)&m.M[1][1] = *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v16[v18 + 2].pHandle + 4);
        v20 = (__m128)*(unsigned int *)&v16[v18 + 2].DataPageOffset;
        v21 = FLOAT_N0_5;
        if ( v19.m128_f32[0] >= 0.0 )
          v22 = FLOAT_0_5;
        else
          v22 = FLOAT_N0_5;
        v19.m128_f32[0] = v19.m128_f32[0] + v22;
        v23 = (int)v19.m128_f32[0];
        if ( (int)v19.m128_f32[0] != 0x80000000 && (float)v23 != v19.m128_f32[0] )
          v19.m128_f32[0] = (float)(v23 - (_mm_movemask_ps(_mm_unpacklo_ps(v19, v19)) & 1));
        LODWORD(m.M[0][3]) = v19.m128_i32[0];
        if ( v20.m128_f32[0] >= 0.0 )
          v21 = FLOAT_0_5;
        v20.m128_f32[0] = v20.m128_f32[0] + v21;
        v24 = (int)v20.m128_f32[0];
        if ( (int)v20.m128_f32[0] != 0x80000000 && (float)v24 != v20.m128_f32[0] )
          v20.m128_f32[0] = (float)(v24 - (_mm_movemask_ps(_mm_unpacklo_ps(v20, v20)) & 1));
        LODWORD(m.M[1][3]) = v20.m128_i32[0];
        Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&this->M, &m);
      }
    }
  }
  v25 = this->SorterShapeNode.pBundle.pObject;
  if ( v25 && (this->TMProvider.Flags & 0x20) != 0 )
  {
    memset(&Dst, 0, sizeof(Dst));
    Dst.M[0][0] = 1.0;
    Dst.M[1][1] = 1.0;
    Dst.M[2][2] = 1.0;
    Dst.M[3][3] = 1.0;
    *(_QWORD *)&vp.BufferWidth = 0i64;
    *(_QWORD *)&vp.Left = 0i64;
    vp.Height = 1;
    vp.Width = 1;
    memset(&vp.ScissorLeft, 0, 20);
    if ( (this->M.pHandle->pHeader->Format & 0x10) != 0 && this->pRoot )
    {
      ViewProj = Scaleform::Render::TransformArgs::GetViewProj(t);
      v27 = this->M.pHandle;
      if ( (v27->pHeader->Format & 0x10) != 0 )
        v28 = (Scaleform::Render::Matrix3x4<float> *)&v27->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v27->pHeader->Format & 0xF].Offsets[4]
                                                                 + 1];
      else
        v28 = &Scaleform::Render::Matrix3x4<float>::Identity;
      Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&Dst, ViewProj, v28);
      vp = *(Scaleform::Render::Viewport *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pRoot->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode & 0xFFFFFFFFFFFFF000ui64)
                                                                   + 0x28)
                                                       + 8i64
                                                       * (unsigned int)((int)(LODWORD(this->pRoot->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode)
                                                                            - ((__int64)this->pRoot->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode & 0xFFFFF000)
                                                                            - 56)
                                                                      / 56)
                                                       + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                          + 160);
    }
    v29 = Scaleform::Render::TextMeshProvider::calcHeightRatio(&this->M, &Dst, &vp);
    v30 = FLOAT_0_85000002;
    if ( (*(_BYTE *)(v14 + 28) & 1) != 0 )
      v30 = FLOAT_0_99000001;
    HeightRatio = this->TMProvider.HeightRatio;
    if ( v29 < (float)(v30 * HeightRatio) || v29 > (float)(HeightRatio / v30) )
    {
      v25->vfptr[3].__vecDelDtor(v25, (unsigned int)&this->SorterShapeNode);
      Scaleform::Render::TextMeshProvider::Clear(&this->TMProvider);
      return;
    }
    goto LABEL_31;
  }
}

// File Line: 220
// RVA: 0x990860
void __fastcall Scaleform::Render::TreeCacheText::HandleChanges(
        Scaleform::Render::TreeCacheText *this,
        __int16 changeBits)
{
  char v2; // di
  Scaleform::Render::Bundle *pObject; // rcx
  Scaleform::Render::TreeCacheNode *pParent; // r8
  unsigned int v6; // r8d
  __int64 v7; // rdx

  v2 = changeBits;
  if ( (changeBits & 0x400) != 0 )
  {
    pObject = this->SorterShapeNode.pBundle.pObject;
    if ( pObject )
      pObject->vfptr[3].__vecDelDtor(pObject, (unsigned int)&this->SorterShapeNode);
    Scaleform::Render::TextMeshProvider::Clear(&this->TMProvider);
  }
  if ( (v2 & 0x20) != 0 )
  {
    pParent = this->pParent;
    if ( pParent )
    {
      v6 = pParent->Flags & 0xC;
      if ( v6 == 12 )
      {
        v7 = 12i64;
LABEL_12:
        this->vfptr->propagateEdgeAA(this, (Scaleform::Render::EdgeAAMode)v7);
        return;
      }
    }
    else
    {
      v6 = 4;
    }
    v7 = *(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                               + 8i64
                               * (unsigned int)((__int64)((__int64)&this->pNode[-1]
                                                        - ((unsigned __int64)this->pNode & 0xFFFFFFFFFFFFF000ui64))
                                              / 56)
                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                  + 10) & 0xC;
    if ( !(_DWORD)v7 )
      v7 = v6;
    goto LABEL_12;
  }
}

// File Line: 235
// RVA: 0x9E3550
void __fastcall Scaleform::Render::TreeCacheText::forceUpdateImages(Scaleform::Render::TreeCacheText *this)
{
  (*(void (__fastcall **)(Scaleform::Render::TreeCacheText *, __int64))this->vfptr->gap8)(this, 1024i64);
}

// File Line: 240
// RVA: 0x9EE0D0
void __fastcall Scaleform::Render::TreeCacheText::propagateEdgeAA(
        Scaleform::Render::TreeCacheText *this,
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
    Scaleform::Render::TextMeshProvider::Clear(&this->TMProvider);
  }
}

// File Line: 252
// RVA: 0x9EDE10
void __fastcall Scaleform::Render::TreeCacheText::propagate3DFlag(
        Scaleform::Render::TreeCacheText *this,
        __int16 parent3D)
{
  Scaleform::Render::SKI_TextPrimitive *v4; // rbx
  Scaleform::Render::SortKeyInterfaceVtbl *vfptr; // rax
  Scaleform::Render::Bundle *pObject; // rcx

  Scaleform::Render::BundleEntry::ClearBundle(&this->SorterShapeNode);
  if ( (parent3D & 0x200) != 0 )
  {
    v4 = &Scaleform::Render::SKI_TextPrimitive::Instance3D;
    vfptr = Scaleform::Render::SKI_TextPrimitive::Instance3D.vfptr;
  }
  else
  {
    v4 = &Scaleform::Render::SKI_TextPrimitive::Instance;
    vfptr = Scaleform::Render::SKI_TextPrimitive::Instance.vfptr;
  }
  vfptr->AddRef(v4, 0i64);
  v4->vfptr->AddRef(v4, 0i64);
  this->SorterShapeNode.Key.pImpl->vfptr->Release(this->SorterShapeNode.Key.pImpl, this->SorterShapeNode.Key.Data);
  this->SorterShapeNode.Key.pImpl = v4;
  this->SorterShapeNode.Key.Data = 0i64;
  v4->vfptr->Release(v4, 0i64);
  pObject = this->SorterShapeNode.pBundle.pObject;
  if ( pObject )
    pObject->vfptr[3].__vecDelDtor(pObject, (unsigned int)&this->SorterShapeNode);
  Scaleform::Render::TextMeshProvider::Clear(&this->TMProvider);
}

// File Line: 262
// RVA: 0x9EE200
void __fastcall Scaleform::Render::TreeCacheText::propagateMaskFlag(
        Scaleform::Render::TreeCacheText *this,
        unsigned int partOfMask)
{
  unsigned int v2; // r8d

  v2 = partOfMask | this->Flags & 0xFFBF;
  if ( v2 != this->Flags )
    this->Flags = v2;
}

// File Line: 284
// RVA: 0x968DE0
Scaleform::Render::TextMeshProvider *__fastcall Scaleform::Render::TreeCacheText::CreateMeshProvider(
        Scaleform::Render::TreeCacheText *this)
{
  Scaleform::Render::TreeNode *pNode; // rdx
  __int64 v3; // rax
  unsigned __int64 v4; // rdx
  Scaleform::Render::TextLayout *v5; // rsi
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rcx
  bool v7; // zf
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax
  Scaleform::Render::Matrix3x4<float> *v9; // rax
  __m128 v10; // xmm7
  __m128 v11; // xmm5
  __m128 v12; // xmm8
  Scaleform::Render::TextMeshProvider *result; // rax
  _BYTE v14[80]; // [rsp+68h] [rbp-80h] BYREF
  __m128 result_32; // [rsp+B8h] [rbp-30h]
  __m128 result_48; // [rsp+C8h] [rbp-20h]

  pNode = this->pNode;
  v3 = *(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28);
  v4 = (__int64)((unsigned __int128)((__int64)((__int64)&pNode[-1] - ((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64))
                                   * (__int128)0x4924924924924925i64) >> 64) >> 4;
  v5 = *(Scaleform::Render::TextLayout **)((*(_QWORD *)(v3 + 8 * ((unsigned int)v4 + (v4 >> 63)) + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                         + 152);
  if ( v5 && this->pRoot )
  {
    memset(&v14[8], 0, 0x40ui64);
    pHeader = this->M.pHandle->pHeader;
    *(_DWORD *)&v14[8] = 1065353216;
    v7 = (pHeader->Format & 0x10) == 0;
    *(_DWORD *)&v14[24] = 1065353216;
    *(_DWORD *)&v14[44] = 1065353216;
    if ( !v7 )
    {
      Scaleform::Render::TreeCacheNode::GetViewProj(this, (Scaleform::Render::Matrix4x4<float> *)&v14[48]);
      pHandle = this->M.pHandle;
      if ( (pHandle->pHeader->Format & 0x10) != 0 )
        v9 = (Scaleform::Render::Matrix3x4<float> *)&pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHandle->pHeader->Format & 0xF].Offsets[4]
                                                                    + 1];
      else
        v9 = &Scaleform::Render::Matrix3x4<float>::Identity;
      v10 = *(__m128 *)&v9->M[0][0];
      v11 = *(__m128 *)&v9->M[1][0];
      v12 = *(__m128 *)&v9->M[2][0];
      *(__m128 *)v14 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v14[64], *(__m128 *)&v14[64], 85), v11),
                             _mm_mul_ps(
                               _mm_shuffle_ps(*(__m128 *)&v14[64], *(__m128 *)&v14[64], 0),
                               *(__m128 *)&v9->M[0][0])),
                           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v14[64], *(__m128 *)&v14[64], 170), v12)),
                         _mm_and_ps(
                           *(__m128 *)&v14[64],
                           (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
      *(__m128 *)&v14[16] = _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(result_32, result_32, 85), v11),
                                  _mm_mul_ps(_mm_shuffle_ps(result_32, result_32, 0), v10)),
                                _mm_mul_ps(_mm_shuffle_ps(result_32, result_32, 170), v12)),
                              _mm_and_ps(
                                result_32,
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
      *(__m128 *)&v14[32] = _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(result_48, result_48, 85), v11),
                                  _mm_mul_ps(_mm_shuffle_ps(result_48, result_48, 0), v10)),
                                _mm_mul_ps(_mm_shuffle_ps(result_48, result_48, 170), v12)),
                              _mm_and_ps(
                                result_48,
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
    }
    Scaleform::Render::TextMeshProvider::CreateMeshData(&this->TMProvider, v5, this->pRenderer2D, &this->M);
  }
  if ( (this->TMProvider.Flags & 0x20) != 0 )
    this->vfptr[1].HandleRemoveNode(this);
  result = &this->TMProvider;
  if ( (this->TMProvider.Flags & 0x20) == 0 )
    return 0i64;
  return result;
}

