// File Line: 34
// RVA: 0x946AC0
void __fastcall Scaleform::Render::TreeCacheText::TreeCacheText(Scaleform::Render::TreeCacheText *this, Scaleform::Render::TreeText *node, Scaleform::Render::Renderer2DImpl *prenderer2D, unsigned int flags)
{
  unsigned int v4; // ebp
  Scaleform::Render::Renderer2DImpl *v5; // r14
  Scaleform::Render::TreeText *v6; // r15
  Scaleform::Render::TreeCacheText *v7; // rsi
  Scaleform::Render::SKI_TextPrimitive *v8; // rbx
  Scaleform::Render::SortKeyInterfaceVtbl *v9; // rax
  Scaleform::Render::SortKey key; // [rsp+38h] [rbp-30h]

  v4 = flags;
  v5 = prenderer2D;
  v6 = node;
  v7 = this;
  if ( (flags >> 9) & 1 )
  {
    v8 = &Scaleform::Render::SKI_TextPrimitive::Instance3D;
    key.pImpl = (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_TextPrimitive::Instance3D;
    v9 = Scaleform::Render::SKI_TextPrimitive::Instance3D.vfptr;
  }
  else
  {
    v8 = &Scaleform::Render::SKI_TextPrimitive::Instance;
    key.pImpl = (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_TextPrimitive::Instance;
    v9 = Scaleform::Render::SKI_TextPrimitive::Instance.vfptr;
  }
  key.Data = 0i64;
  v9->AddRef((Scaleform::Render::SortKeyInterface *)&v8->vfptr, 0i64);
  Scaleform::Render::TreeCacheMeshBase::TreeCacheMeshBase(
    (Scaleform::Render::TreeCacheMeshBase *)&v7->vfptr,
    (Scaleform::Render::TreeNode *)&v6->0,
    &key,
    v5,
    v4);
  v8->vfptr->Release((Scaleform::Render::SortKeyInterface *)&v8->vfptr, 0i64);
  v7->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheText::`vftable';
  v7->pNextNoBatch = 0i64;
  Scaleform::Render::TextMeshProvider::TextMeshProvider(&v7->TMProvider, v7->pRenderer2D->pGlyphCache.pObject);
}

// File Line: 52
// RVA: 0x9BDB30
void __fastcall Scaleform::Render::TreeCacheText::UpdateChildSubtree(Scaleform::Render::TreeCacheText *this, Scaleform::Render::TreeNode::NodeData *data, unsigned __int16 depth)
{
  int v3; // er9

  v3 = (unsigned __int16)(this->Flags & 0xFFBF) | (unsigned __int8)((2 * (this->Flags & 0x20) | this->pParent->Flags) & 0xC0);
  if ( data && (data->Flags >> 9) & 1 )
    v3 |= 0x200u;
  if ( v3 != this->Flags )
    this->Flags = v3;
  if ( data )
    Scaleform::Render::TreeCacheNode::updateMaskCache((Scaleform::Render::TreeCacheNode *)&this->vfptr, data, depth, 1);
}

// File Line: 83
// RVA: 0x9BE040
void __fastcall Scaleform::Render::TreeCacheText::UpdateDistanceFieldUniforms(Scaleform::Render::TreeCacheText *this)
{
  Scaleform::Render::TreeCacheText *v1; // rbx
  Scaleform::Render::TreeNode *v2; // rcx
  __int64 v3; // rcx
  float v4; // xmm2_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  __m128 v7; // xmm2
  float v8; // xmm3_4
  __m128 v9; // xmm1
  float v10; // xmm0_4
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v11; // rdx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v12; // r8
  __int64 v13; // rdx
  float pr[2]; // [rsp+30h] [rbp-40h]
  float pa[2]; // [rsp+38h] [rbp-38h]
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v16; // [rsp+40h] [rbp-30h]
  __int64 v17; // [rsp+48h] [rbp-28h]
  float v18[6]; // [rsp+50h] [rbp-20h]
  __int64 v19; // [rsp+68h] [rbp-8h]

  v1 = this;
  if ( (this->TMProvider.Flags >> 9) & 1 )
  {
    v2 = this->pNode;
    *((float *)&v19 + 1) = FLOAT_9_0;
    *(_OWORD *)&v18[1] = 0ui64;
    v18[0] = 0.0;
    LODWORD(v16) = 0;
    v3 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                + 8
                                * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1] - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                                                     * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                 + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1]
                                                                                          - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 63))
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
      v18[4] = v6 * 18.0;
      v9 = v7;
      v18[0] = v7.m128_f32[0];
      v18[1] = v8;
      v9.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v8 * v8);
      if ( v9.m128_f32[0] > 4.0 )
      {
        LODWORD(v10) = (unsigned __int128)_mm_sqrt_ps(v9);
        v18[0] = v7.m128_f32[0] * (float)(2.0 / v10);
        v18[1] = v8 * (float)(2.0 / v10);
      }
      Scaleform::Render::Color::GetRGBAFloat((Scaleform::Render::Color *)(v3 + 284), pr, &pr[1], pa, &pa[1]);
    }
    v11 = v1->M.pHandle;
    if ( !(v11->pHeader->Format & 8) )
      Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
        *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_QWORD *)(((unsigned __int64)v11 & 0xFFFFFFFFFFFFF800ui64)
                                                                      + 0x20)
                                                          + 8i64),
        v11,
        (unsigned __int8)v11->pHeader->Format | 8);
    v12 = v1->M.pHandle->pHeader;
    v13 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v12->Format & 0xF].Offsets[3];
    v12[v13 + 1].pHandle = *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)pr;
    *(_QWORD *)&v12[v13 + 1].RefCount = *(_QWORD *)pa;
    v12[v13 + 2].pHandle = v16;
    *(_QWORD *)&v12[v13 + 2].RefCount = v17;
    v12[v13 + 3].pHandle = *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)v18;
    *(Scaleform::Render::MatrixPoolImpl::DataHeader *)((char *)&v12[v13 + 3] + 8) = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&v18[2];
    *(_QWORD *)&v12[v13 + 4].RefCount = v19;
  }
}

// File Line: 116
// RVA: 0x9BFED0
void __fastcall Scaleform::Render::TreeCacheText::UpdateTransform(Scaleform::Render::TreeCacheText *this, Scaleform::Render::TreeNode::NodeData *nodeData, Scaleform::Render::TransformArgs *t, Scaleform::Render::TransformFlags flags)
{
  Scaleform::Render::TransformFlags v4; // edi
  Scaleform::Render::TransformArgs *v5; // r14
  Scaleform::Render::TreeNode::NodeData *v6; // rbx
  Scaleform::Render::TreeCacheText *v7; // rsi
  float v8; // xmm3_4
  float v9; // xmm2_4
  int v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  __int64 v14; // r15
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v15; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v16; // rdx
  int v17; // eax
  __int64 v18; // rcx
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  float v21; // xmm1_4
  float v22; // xmm0_4
  signed int v23; // ecx
  signed int v24; // edx
  Scaleform::Render::Bundle *v25; // rbx
  Scaleform::Render::Matrix4x4<float> *v26; // r9
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v27; // rax
  Scaleform::Render::Matrix3x4<float> *v28; // r8
  unsigned __int64 v29; // r8
  unsigned __int64 v30; // rdx
  float v31; // xmm0_4
  float v32; // xmm3_4
  float v33; // xmm2_4
  unsigned __int16 v34; // cx
  unsigned int meshGenFlags; // er13
  unsigned int v36; // er15
  unsigned __int64 v37; // rbx
  Scaleform::Render::TextMeshEntry *v38; // rdx
  float v39; // xmm3_4
  Scaleform::Render::Renderer2DImpl *ren; // ST28_8
  unsigned int v41; // er14
  Scaleform::Render::Renderer2DImpl *v42; // rcx
  Scaleform::Render::MeshKeyManager *v43; // r12
  Scaleform::Render::ToleranceParams *v44; // rdi
  Scaleform::Render::MeshKey *v45; // rcx
  Scaleform::Render::MeshKey *v46; // r14
  Scaleform::Render::MeshKey *v47; // rdi
  bool v48; // zf
  Scaleform::Render::MeshBase *v49; // rcx
  Scaleform::Render::MeshBase *v50; // rax
  Scaleform::Render::MeshBase *v51; // rdi
  __int64 v52; // r14
  __int64 v53; // rcx
  __int64 v54; // rdi
  __int64 v55; // rcx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v56; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v57; // rbx
  __int64 v58; // rcx
  Scaleform::Render::Viewport vp; // [rsp+40h] [rbp-80h]
  float v60; // [rsp+6Ch] [rbp-54h]
  Scaleform::Render::Matrix2x4<float> m; // [rsp+70h] [rbp-50h]
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+90h] [rbp-30h]
  float v63; // [rsp+A0h] [rbp-20h]
  float v64; // [rsp+A4h] [rbp-1Ch]
  float v65; // [rsp+B0h] [rbp-10h]
  float v66; // [rsp+B4h] [rbp-Ch]
  __int64 v67; // [rsp+C0h] [rbp+0h]
  Scaleform::Render::MeshBase *v68; // [rsp+C8h] [rbp+8h]
  int Dst; // [rsp+D0h] [rbp+10h]
  int v70; // [rsp+E4h] [rbp+24h]
  int v71; // [rsp+F8h] [rbp+38h]
  int v72; // [rsp+10Ch] [rbp+4Ch]
  float v73; // [rsp+110h] [rbp+50h]
  Scaleform::Render::Matrix2x4<float> *v74; // [rsp+1C0h] [rbp+100h]
  void *p; // [rsp+1C8h] [rbp+108h]
  int v76; // [rsp+1D0h] [rbp+110h]
  unsigned int v77; // [rsp+1D8h] [rbp+118h]

  v67 = -2i64;
  v4 = flags;
  v5 = t;
  v6 = nodeData;
  v7 = this;
  v8 = t->CullRect.y2;
  v9 = t->CullRect.x2;
  v10 = LODWORD(t->CullRect.y1);
  vp.ScissorWidth = LODWORD(t->CullRect.x1);
  vp.ScissorHeight = v10;
  *(float *)&vp.Flags = v9;
  v60 = v8;
  Scaleform::Render::TreeCacheNode::updateCulling(
    (Scaleform::Render::TreeCacheNode *)&this->vfptr,
    nodeData,
    t,
    (Scaleform::Render::Rect<float> *)&vp.ScissorWidth,
    (Scaleform::Render::TransformFlags)(flags | 0x20));
  v11 = v6->AproxParentBounds.y2;
  v12 = v6->AproxParentBounds.x2;
  v13 = v6->AproxParentBounds.y1;
  v7->SortParentBounds.x1 = v6->AproxParentBounds.x1;
  v7->SortParentBounds.y1 = v13;
  v7->SortParentBounds.x2 = v12;
  v7->SortParentBounds.y2 = v11;
  v7->Flags &= 0xFBFFu;
  ((void (__fastcall *)(Scaleform::Render::TreeCacheText *, Scaleform::Render::TransformArgs *, _QWORD))v7->vfptr[1].__vecDelDtor)(
    v7,
    v5,
    (unsigned int)v4);
  v14 = *(_QWORD *)((*(_QWORD *)(*(_QWORD *)(((_QWORD)v7->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                               + 8
                               * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7->pNode[-1] - ((_QWORD)v7->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7->pNode[-1]
                                                                                         - ((_QWORD)v7->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                               + 40) & 0xFFFFFFFFFFFFFFFEui64)
                  + 152);
  v76 = v4 & 1;
  if ( !(v4 & 1) )
  {
LABEL_31:
    if ( (v7->TMProvider.Flags >> 6) & 1 )
    {
      v34 = v7->Flags;
      if ( v34 & 0x40 )
      {
        meshGenFlags = 2;
      }
      else
      {
        meshGenFlags = 0;
        if ( (v34 & 0xC) == 4 )
          meshGenFlags = 1;
      }
      if ( (v34 & 0x80u) != 0 )
        meshGenFlags |= 8u;
      v36 = 0;
      if ( ((unsigned int (*)(void))v7->TMProvider.vfptr->GetLayerCount)() )
      {
        do
        {
          v37 = (unsigned __int64)&v7->TMProvider.Layers.Data.Data[(unsigned __int64)v36];
          if ( !((*(_DWORD *)v37 - 8) & 0xFFFFFFFB) )
          {
            v38 = &v7->TMProvider.Entries.Data.Data[*(unsigned int *)(v37 + 4)];
            v39 = *(float *)(v37 + 56);
            *(float *)&vp.BufferWidth = v7->TMProvider.HeightRatio * v39;
            *(_QWORD *)&vp.BufferHeight = 0i64;
            *(_QWORD *)&vp.Top = 0i64;
            vp.Height = vp.BufferWidth;
            *(_QWORD *)&vp.ScissorLeft = 0i64;
            ren = v7->pRenderer2D;
            v41 = Scaleform::Render::TextMeshProvider::CalcVectorParams(
                    (Scaleform::Render::TextMeshLayer *)v37,
                    v38,
                    (Scaleform::Render::Matrix2x4<float> *)&vp,
                    v39);
            v42 = v7->pRenderer2D;
            v43 = v42->pMeshKeyManager.pObject;
            v44 = &v42->Tolerances;
            v45 = *(Scaleform::Render::MeshKey **)(v37 + 24);
            if ( !v45 || !Scaleform::Render::MeshKey::Match(v45, 0, v77, &v73, v44) )
            {
              v46 = Scaleform::Render::MeshKeyManager::CreateMatchingKey(
                      v43,
                      *(Scaleform::Render::MeshProvider_KeySupport **)(v37 + 32),
                      0,
                      v41,
                      &v73,
                      v44);
              v47 = *(Scaleform::Render::MeshKey **)(v37 + 24);
              if ( v47 )
              {
                v48 = v47->UseCount-- == 1;
                if ( v48 )
                {
                  v49 = v47->pMesh.pObject;
                  if ( !v49 || ((unsigned __int8 (*)(void))v49->vfptr[1].__vecDelDtor)() || v47->Flags & 0x110 )
                    Scaleform::Render::MeshKeySet::DestroyKey(v47->pKeySet, v47);
                }
              }
              *(_QWORD *)(v37 + 24) = v46;
              if ( !v46->pMesh.pObject )
              {
                LODWORD(p) = 68;
                v50 = (Scaleform::Render::MeshBase *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       v7,
                                                       240ui64,
                                                       (Scaleform::AllocInfo *)&p);
                v51 = v50;
                v68 = v50;
                if ( v50 )
                {
                  Scaleform::Render::MeshBase::MeshBase(
                    v50,
                    v7->pRenderer2D,
                    *(Scaleform::Render::MeshProvider **)(*(_QWORD *)(v37 + 24) + 16i64),
                    (Scaleform::Render::Matrix2x4<float> *)&vp,
                    0.0,
                    0,
                    meshGenFlags);
                  v51->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Mesh::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>'};
                  v51->vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::Mesh::`vftable'{for `Scaleform::Render::MeshStagingNode'};
                  v51[1].vfptr = 0i64;
                  v51[1].pNext = (Scaleform::Render::MeshStagingNode *)1065353216;
                  v51[1].StagingBufferSize = 0i64;
                  LODWORD(v51[1].StagingBufferOffset) = 0;
                  *(unsigned __int64 *)((char *)&v51[1].StagingBufferOffset + 4) = 1065353216i64;
                  HIDWORD(v51[1].StagingBufferIndexOffset) = 0;
                  LOBYTE(v51[1].PinCount) = 0;
                }
                else
                {
                  v51 = 0i64;
                }
                v52 = *(_QWORD *)(v37 + 24);
                v53 = *(_QWORD *)(v52 + 24);
                if ( v53 && !_InterlockedDecrement((volatile signed __int32 *)(v53 + 8)) && v53 )
                  (**(void (__fastcall ***)(__int64, signed __int64))v53)(v53, 1i64);
                *(_QWORD *)(v52 + 24) = v51;
              }
              v54 = *(_QWORD *)(*(_QWORD *)(v37 + 24) + 24i64);
              if ( v54 )
                _InterlockedExchangeAdd((volatile signed __int32 *)(v54 + 8), 1u);
              v55 = *(_QWORD *)(v37 + 16);
              if ( v55 && !_InterlockedDecrement((volatile signed __int32 *)(v55 + 8)) && v55 )
                (**(void (__fastcall ***)(__int64, signed __int64))v55)(v55, 1i64);
              *(_QWORD *)(v37 + 16) = v54;
            }
          }
          ++v36;
        }
        while ( v36 < ((unsigned int (*)(void))v7->TMProvider.vfptr->GetLayerCount)() );
      }
    }
    if ( v76 && (LOWORD(v7->TMProvider.Flags) >> 8) & 1 )
    {
      v74 = &m;
      v56 = v7->M.pHandle;
      *(_QWORD *)&m.M[0][0] = v56;
      if ( v56 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
        ++v56->pHeader->RefCount;
      Scaleform::Render::TextMeshProvider::UpdateMaskClearBounds(
        &v7->TMProvider,
        &result,
        (Scaleform::Render::MatrixPoolImpl::HMatrix)&m);
      if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      {
        v57 = result.pHandle->pHeader;
        v48 = result.pHandle->pHeader->RefCount == 1;
        --v57->RefCount;
        if ( v48 )
        {
          v58 = v57->DataPageOffset;
          *(_WORD *)((char *)&v57[1].RefCount + v58 + 2) += 16 * (unsigned __int8)v57->UnitSize;
          (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v57[1].pHandle + v58))[5].pHeader += (unsigned __int8)v57->UnitSize;
          Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v57->pHandle);
          v57->pHandle = 0i64;
        }
      }
    }
    return;
  }
  if ( *(_BYTE *)(v14 + 28) & 1 )
  {
    v15 = v7->M.pHandle;
    v16 = v15->pHeader;
    if ( !(v15->pHeader->Format & 0x10) )
    {
      v17 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v16->Format & 0xF].Offsets[4];
      v63 = *(float *)&v16[v17 + 1].pHandle;
      v64 = *((float *)&v16[v17 + 1].pHandle + 1);
      v65 = *(float *)&v16[v17 + 2].pHandle;
      v66 = *((float *)&v16[v17 + 2].pHandle + 1);
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v64 * 0.0) + v63) & _xmm) <= 0.000001
        || COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v66 * 0.0) + v65) & _xmm) <= 0.000001 )
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
        v23 = (signed int)v19.m128_f32[0];
        if ( (signed int)v19.m128_f32[0] != 0x80000000 && (float)v23 != v19.m128_f32[0] )
          v19.m128_f32[0] = (float)(v23 - (_mm_movemask_ps(_mm_unpacklo_ps(v19, v19)) & 1));
        LODWORD(m.M[0][3]) = v19.m128_i32[0];
        if ( v20.m128_f32[0] >= 0.0 )
          v21 = FLOAT_0_5;
        v20.m128_f32[0] = v20.m128_f32[0] + v21;
        v24 = (signed int)v20.m128_f32[0];
        if ( (signed int)v20.m128_f32[0] != 0x80000000 && (float)v24 != v20.m128_f32[0] )
          v20.m128_f32[0] = (float)(v24 - (_mm_movemask_ps(_mm_unpacklo_ps(v20, v20)) & 1));
        LODWORD(m.M[1][3]) = v20.m128_i32[0];
        Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&v7->M, &m);
      }
    }
  }
  v25 = v7->SorterShapeNode.pBundle.pObject;
  if ( v25 && (v7->TMProvider.Flags >> 5) & 1 )
  {
    memset(&Dst, 0, 0x40ui64);
    Dst = 1065353216;
    v70 = 1065353216;
    v71 = 1065353216;
    v72 = 1065353216;
    *(_QWORD *)&vp.BufferWidth = 0i64;
    *(_QWORD *)&vp.Left = 0i64;
    vp.Height = 1;
    vp.Width = 1;
    *(_QWORD *)&vp.ScissorWidth = 0i64;
    *(_QWORD *)&vp.ScissorLeft = 0i64;
    vp.Flags = 0;
    if ( v7->M.pHandle->pHeader->Format & 0x10 && v7->pRoot )
    {
      v26 = Scaleform::Render::TransformArgs::GetViewProj(v5);
      v27 = v7->M.pHandle;
      if ( v27->pHeader->Format & 0x10 )
        v28 = (Scaleform::Render::Matrix3x4<float> *)&v27->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v27->pHeader->Format & 0xF].Offsets[4]
                                                                 + 1];
      else
        v28 = &Scaleform::Render::Matrix3x4<float>::Identity;
      Scaleform::Render::Matrix4x4<float>::MultiplyMatrix((Scaleform::Render::Matrix4x4<float> *)&Dst, v26, v28);
      v29 = (_QWORD)v7->pRoot->pNode & 0xFFFFFFFFFFFFF000ui64;
      v30 = *(_QWORD *)(*(_QWORD *)(v29 + 0x28)
                      + 8
                      * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7->pRoot->pNode[-1]
                                                                                            - v29)
                                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                       + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7->pRoot->pNode[-1]
                                                                                - v29)
                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                      + 40) & 0xFFFFFFFFFFFFFFFEui64;
      vp.BufferWidth = *(_DWORD *)(v30 + 160);
      vp.BufferHeight = *(_DWORD *)(v30 + 164);
      vp.Left = *(_DWORD *)(v30 + 168);
      vp.Top = *(_DWORD *)(v30 + 172);
      vp.Width = *(_DWORD *)(v30 + 176);
      vp.Height = *(_DWORD *)(v30 + 180);
      vp.ScissorLeft = *(_DWORD *)(v30 + 184);
      vp.ScissorTop = *(_DWORD *)(v30 + 188);
      vp.ScissorWidth = *(_DWORD *)(v30 + 192);
      vp.ScissorHeight = *(_DWORD *)(v30 + 196);
      vp.Flags = *(_DWORD *)(v30 + 200);
    }
    v31 = Scaleform::Render::TextMeshProvider::calcHeightRatio(&v7->M, (Scaleform::Render::Matrix4x4<float> *)&Dst, &vp);
    v32 = FLOAT_0_85000002;
    if ( *(_BYTE *)(v14 + 28) & 1 )
      v32 = FLOAT_0_99000001;
    v33 = v7->TMProvider.HeightRatio;
    if ( v31 < (float)(v32 * v33) || v31 > (float)(v33 / v32) )
    {
      v25->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v25->vfptr, (unsigned int)&v7->SorterShapeNode);
      Scaleform::Render::TextMeshProvider::Clear(&v7->TMProvider);
      return;
    }
    goto LABEL_31;
  }
} FLOAT_0_99000001;
    v33 = v7->TMProvider.HeightRatio;
    if ( v31 < (float)(v32 * v33) || v31 > (float)(v33 / v32) )
    {
      v25->vfptr[3].__vecDelDtor((Scal

// File Line: 220
// RVA: 0x990860
void __fastcall Scaleform::Render::TreeCacheText::HandleChanges(Scaleform::Render::TreeCacheText *this, unsigned int changeBits)
{
  char v2; // di
  Scaleform::Render::TreeCacheText *v3; // rbx
  Scaleform::Render::Bundle *v4; // rcx
  Scaleform::Render::TreeCacheNode *v5; // r8
  unsigned int v6; // er8
  signed __int64 v7; // rdx

  v2 = changeBits;
  v3 = this;
  if ( _bittest((const signed int *)&changeBits, 0xAu) )
  {
    v4 = this->SorterShapeNode.pBundle.pObject;
    if ( v4 )
      v4->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, (unsigned int)&v3->SorterShapeNode);
    Scaleform::Render::TextMeshProvider::Clear(&v3->TMProvider);
  }
  if ( v2 & 0x20 )
  {
    v5 = v3->pParent;
    if ( v5 )
    {
      v6 = v5->Flags & 0xC;
      if ( v6 == 12 )
      {
        v7 = 12i64;
LABEL_12:
        v3->vfptr->propagateEdgeAA((Scaleform::Render::TreeCacheNode *)&v3->vfptr, (Scaleform::Render::EdgeAAMode)v7);
        return;
      }
    }
    else
    {
      v6 = 4;
    }
    v7 = *(_WORD *)((*(_QWORD *)(*(_QWORD *)(((_QWORD)v3->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                               + 8
                               * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3->pNode[-1]
                                                                                         - ((_QWORD)v3->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3->pNode[-1] - ((_QWORD)v3->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4))
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
  (*(void (__fastcall **)(Scaleform::Render::TreeCacheText *, signed __int64))this->vfptr->gap8)(this, 1024i64);
}

// File Line: 240
// RVA: 0x9EE0D0
void __fastcall Scaleform::Render::TreeCacheText::propagateEdgeAA(Scaleform::Render::TreeCacheText *this, Scaleform::Render::EdgeAAMode parentEdgeAA)
{
  Scaleform::Render::TreeCacheText *v2; // r9
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
    Scaleform::Render::TextMeshProvider::Clear(&v2->TMProvider);
  }
}

// File Line: 252
// RVA: 0x9EDE10
void __fastcall Scaleform::Render::TreeCacheText::propagate3DFlag(Scaleform::Render::TreeCacheText *this, unsigned int parent3D)
{
  unsigned int v2; // ebx
  Scaleform::Render::TreeCacheText *v3; // rdi
  Scaleform::Render::SKI_TextPrimitive *v4; // rbx
  Scaleform::Render::SortKeyInterfaceVtbl *v5; // rax
  Scaleform::Render::Bundle *v6; // rcx

  v2 = parent3D;
  v3 = this;
  Scaleform::Render::BundleEntry::ClearBundle(&this->SorterShapeNode);
  if ( (v2 >> 9) & 1 )
  {
    v4 = &Scaleform::Render::SKI_TextPrimitive::Instance3D;
    v5 = Scaleform::Render::SKI_TextPrimitive::Instance3D.vfptr;
  }
  else
  {
    v4 = &Scaleform::Render::SKI_TextPrimitive::Instance;
    v5 = Scaleform::Render::SKI_TextPrimitive::Instance.vfptr;
  }
  v5->AddRef((Scaleform::Render::SortKeyInterface *)&v4->vfptr, 0i64);
  v4->vfptr->AddRef((Scaleform::Render::SortKeyInterface *)&v4->vfptr, 0i64);
  v3->SorterShapeNode.Key.pImpl->vfptr->Release(v3->SorterShapeNode.Key.pImpl, v3->SorterShapeNode.Key.Data);
  v3->SorterShapeNode.Key.pImpl = (Scaleform::Render::SortKeyInterface *)&v4->vfptr;
  v3->SorterShapeNode.Key.Data = 0i64;
  v4->vfptr->Release((Scaleform::Render::SortKeyInterface *)&v4->vfptr, 0i64);
  v6 = v3->SorterShapeNode.pBundle.pObject;
  if ( v6 )
    v6->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v6->vfptr, (unsigned int)&v3->SorterShapeNode);
  Scaleform::Render::TextMeshProvider::Clear(&v3->TMProvider);
}

// File Line: 262
// RVA: 0x9EE200
void __fastcall Scaleform::Render::TreeCacheText::propagateMaskFlag(Scaleform::Render::TreeCacheText *this, unsigned int partOfMask)
{
  unsigned int v2; // er8

  v2 = partOfMask | (unsigned __int16)(this->Flags & 0xFFBF);
  if ( v2 != this->Flags )
    this->Flags = v2;
}

// File Line: 284
// RVA: 0x968DE0
Scaleform::Render::TextMeshProvider *__fastcall Scaleform::Render::TreeCacheText::CreateMeshProvider(Scaleform::Render::TreeCacheText *this)
{
  Scaleform::Render::TreeNode *v1; // rdx
  Scaleform::Render::TreeCacheText *v2; // rbx
  __int64 v3; // rax
  unsigned __int64 v4; // rdx
  Scaleform::Render::TextLayout *v5; // rsi
  Scaleform::Render::MatrixPoolImpl::DataHeader *v6; // rcx
  bool v7; // zf
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v8; // rax
  Scaleform::Render::Matrix3x4<float> *v9; // rax
  __m128 v10; // xmm7
  __m128 v11; // xmm5
  __m128 v12; // xmm8
  unsigned __int64 v13; // r8
  _DWORD *v14; // rdx
  int v15; // eax
  unsigned __int16 v16; // cx
  Scaleform::Render::TextMeshProvider *v17; // rax
  Scaleform::Render::Viewport v18; // [rsp+40h] [rbp-A8h]
  int v19; // [rsp+6Ch] [rbp-7Ch]
  __int64 v20; // [rsp+70h] [rbp-78h]
  __m128 v21; // [rsp+78h] [rbp-70h]
  __m128 v22; // [rsp+88h] [rbp-60h]
  Scaleform::Render::Matrix4x4<float> result; // [rsp+98h] [rbp-50h]

  v1 = this->pNode;
  v2 = this;
  v3 = *(_QWORD *)(((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64) + 0x28);
  v4 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1[-1]
                                                           - ((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64))
                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4;
  v5 = *(Scaleform::Render::TextLayout **)((*(_QWORD *)(v3 + 8 * ((unsigned int)v4 + (v4 >> 63)) + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                         + 152);
  if ( v5 && this->pRoot )
  {
    memset(&v20, 0, 0x40ui64);
    v6 = v2->M.pHandle->pHeader;
    LODWORD(v20) = 1065353216;
    v19 = 1065353216;
    v7 = (v6->Format & 0x10) == 0;
    v21.m128_i32[2] = 1065353216;
    v22.m128_i32[3] = 1065353216;
    *(_QWORD *)&v18.BufferWidth = 0i64;
    *(_QWORD *)&v18.Left = 0i64;
    v18.Height = 1;
    v18.Width = 1;
    *(_QWORD *)&v18.ScissorWidth = 0i64;
    *(_QWORD *)&v18.ScissorLeft = 0i64;
    v18.Flags = 0;
    if ( !v7 )
    {
      Scaleform::Render::TreeCacheNode::GetViewProj((Scaleform::Render::TreeCacheNode *)&v2->vfptr, &result);
      v8 = v2->M.pHandle;
      if ( v8->pHeader->Format & 0x10 )
        v9 = (Scaleform::Render::Matrix3x4<float> *)&v8->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->pHeader->Format & 0xF].Offsets[4]
                                                               + 1];
      else
        v9 = &Scaleform::Render::Matrix3x4<float>::Identity;
      v10 = *(__m128 *)&v9->M[0][0];
      v11 = *(__m128 *)&v9->M[1][0];
      v12 = *(__m128 *)&v9->M[2][0];
      v13 = (_QWORD)v2->pRoot->pNode & 0xFFFFFFFFFFFFF000ui64;
      v14 = (_DWORD *)(*(_QWORD *)(*(_QWORD *)(v13 + 0x28)
                                 + 8
                                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2->pRoot->pNode[-1] - v13)
                                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2->pRoot->pNode[-1]
                                                                                           - v13)
                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                 + 40) & 0xFFFFFFFFFFFFFFFEui64);
      v15 = v14[40];
      *(__m128 *)&v18.Flags = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&result.M[1][0], *(__m128 *)&result.M[1][0], 85),
                                      v11),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&result.M[1][0], *(__m128 *)&result.M[1][0], 0),
                                      v10)),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&result.M[1][0], *(__m128 *)&result.M[1][0], 170),
                                    v12)),
                                _mm_and_ps(
                                  *(__m128 *)&result.M[1][0],
                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
      v21 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&result.M[2][0], *(__m128 *)&result.M[2][0], 85), v11),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&result.M[2][0], *(__m128 *)&result.M[2][0], 0), v10)),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&result.M[2][0], *(__m128 *)&result.M[2][0], 170), v12)),
              _mm_and_ps(
                *(__m128 *)&result.M[2][0],
                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
      v22 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&result.M[3][0], *(__m128 *)&result.M[3][0], 85), v11),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&result.M[3][0], *(__m128 *)&result.M[3][0], 0), v10)),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&result.M[3][0], *(__m128 *)&result.M[3][0], 170), v12)),
              _mm_and_ps(
                *(__m128 *)&result.M[3][0],
                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
      v18.BufferWidth = v15;
      v18.BufferHeight = v14[41];
      v18.Left = v14[42];
      v18.Top = v14[43];
      v18.Width = v14[44];
      v18.Height = v14[45];
      v18.ScissorLeft = v14[46];
      v18.ScissorTop = v14[47];
      v18.ScissorWidth = v14[48];
      v18.ScissorHeight = v14[49];
      v18.Flags = v14[50];
    }
    v16 = v2->Flags;
    Scaleform::Render::TextMeshProvider::CreateMeshData(&v2->TMProvider, v5, v2->pRenderer2D, &v2->M);
  }
  if ( (v2->TMProvider.Flags >> 5) & 1 )
    v2->vfptr[1].HandleRemoveNode((Scaleform::Render::TreeCacheNode *)&v2->vfptr);
  v17 = &v2->TMProvider;
  if ( !((v2->TMProvider.Flags >> 5) & 1) )
    v17 = 0i64;
  return v17;
}

