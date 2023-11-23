// File Line: 123
// RVA: 0x946570
void __fastcall Scaleform::Render::TransformArgs::TransformArgs(
        Scaleform::Render::TransformArgs *this,
        Scaleform::Render::TransformArgs *copy,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  float x1; // eax
  float x2; // xmm1_4
  float y2; // xmm2_4

  x1 = copy->CullRect.x1;
  x2 = copy->CullRect.x2;
  y2 = copy->CullRect.y2;
  this->CullRect.y1 = copy->CullRect.y1;
  this->CullRect.x2 = x2;
  this->CullRect.x1 = x1;
  this->CullRect.y2 = y2;
  this->Mat = *mat;
  this->Cx = copy->Cx;
  this->viewState = copy->viewState;
  this->projState = copy->projState;
  this->bRecomputeViewProj = copy->bRecomputeViewProj;
  this->ViewProj = copy->ViewProj;
}

// File Line: 129
// RVA: 0x9466A0
void __fastcall Scaleform::Render::TransformArgs::TransformArgs(
        Scaleform::Render::TransformArgs *this,
        Scaleform::Render::TransformArgs *copy,
        Scaleform::Render::Matrix3x4<float> *mat)
{
  float x1; // eax
  float x2; // xmm1_4
  float y2; // xmm2_4

  x1 = copy->CullRect.x1;
  x2 = copy->CullRect.x2;
  y2 = copy->CullRect.y2;
  this->CullRect.y1 = copy->CullRect.y1;
  this->CullRect.x2 = x2;
  this->CullRect.x1 = x1;
  this->CullRect.y2 = y2;
  this->Mat3D = *mat;
  this->Mat = Scaleform::Render::Matrix2x4<float>::Identity;
  this->Cx = copy->Cx;
  this->viewState = copy->viewState;
  this->projState = copy->projState;
  this->bRecomputeViewProj = copy->bRecomputeViewProj;
  this->ViewProj = copy->ViewProj;
}

// File Line: 140
// RVA: 0x99FBA0
void __fastcall Scaleform::Render::TransformArgs::PrependMatrix3D(
        Scaleform::Render::TransformArgs *this,
        Scaleform::Render::Matrix3x4<float> *m)
{
  float v2; // eax
  Scaleform::Render::Matrix3x4<float> *p_Mat3D; // rcx
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+20h] [rbp-38h] BYREF

  v2 = this->Mat3D.M[0][0];
  p_Mat3D = &this->Mat3D;
  m1.M[0][0] = v2;
  *(_QWORD *)&m1.M[0][1] = *(_QWORD *)&p_Mat3D->M[0][1];
  m1.M[0][3] = p_Mat3D->M[0][3];
  *(_OWORD *)&m1.M[1][0] = *(_OWORD *)&p_Mat3D->M[1][0];
  *(_OWORD *)&m1.M[2][0] = *(_OWORD *)&p_Mat3D->M[2][0];
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(p_Mat3D, &m1, m);
}

// File Line: 142
// RVA: 0x988C60
void __fastcall Scaleform::Render::TransformArgs::GetMatrix3D(
        Scaleform::Render::TransformArgs *this,
        Scaleform::Render::TransformFlags flags,
        Scaleform::Render::Matrix3x4<float> *m)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4

  if ( (flags & 0x80u) == 0 )
  {
    v3 = this->Mat.M[0][1];
    v4 = this->Mat.M[0][2];
    v5 = this->Mat.M[1][2];
    v6 = this->Mat.M[1][3];
    v7 = this->Mat.M[0][3];
    v8 = this->Mat.M[1][0];
    v9 = this->Mat.M[1][1];
    m->M[0][0] = this->Mat.M[0][0];
    m->M[0][1] = v3;
    m->M[0][2] = v4;
    m->M[0][3] = v7;
    m->M[1][0] = v8;
    m->M[1][1] = v9;
    m->M[1][2] = v5;
    m->M[1][3] = v6;
    LODWORD(m->M[2][0]) = _xmm.m128_i32[0];
    LODWORD(m->M[2][1]) = _mm_shuffle_ps(_xmm, _xmm, 85).m128_u32[0];
    LODWORD(m->M[2][2]) = _mm_shuffle_ps(_xmm, _xmm, 170).m128_u32[0];
    LODWORD(m->M[2][3]) = _xmm.m128_i32[3];
  }
  else if ( (flags & 0x40) != 0 )
  {
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(m, &this->Mat3D, &this->Mat);
  }
  else
  {
    *m = this->Mat3D;
  }
}

// File Line: 155
// RVA: 0x98F330
Scaleform::Render::Matrix4x4<float> *__fastcall Scaleform::Render::TransformArgs::GetViewProj(
        Scaleform::Render::TransformArgs *this)
{
  Scaleform::Render::ViewMatrix3DState *viewState; // rcx
  Scaleform::Render::ProjectionMatrix3DState *projState; // rdx
  void *pData; // rcx
  __m128 v5; // xmm10
  __m128 v6; // xmm5
  int v7; // eax
  __m128 *v8; // rcx
  __m128 v9; // xmm4
  __m128 v10; // xmm8
  __m128i v11; // xmm11
  __m128 v12; // xmm3
  __m128i v13; // xmm9
  __m128i v14; // xmm3
  __m128i v15; // xmm2
  __m128 v17; // [rsp+18h] [rbp-79h]
  __m128 v18; // [rsp+38h] [rbp-59h]
  __m128 v19; // [rsp+48h] [rbp-49h]
  __m128 v20; // [rsp+58h] [rbp-39h]

  if ( !this->bRecomputeViewProj )
    return &this->ViewProj;
  viewState = this->viewState;
  if ( viewState && (projState = this->projState) != 0i64 )
  {
    pData = viewState->pData;
    v17 = (__m128)*((_OWORD *)pData + 1);
    v5 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v;
    v6 = *((__m128 *)pData + 2);
    v18.m128_u64[0] = *((_QWORD *)pData + 6);
    v18.m128_i32[2] = *((_DWORD *)pData + 14);
    v7 = *((_DWORD *)pData + 15);
    v8 = (__m128 *)projState->pData;
    v18.m128_i32[3] = v7;
    v19 = v8[1];
    v20 = v8[2];
    v9 = v8[3];
    v10 = v8[4];
    v11 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), v6),
                         _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v17)),
                       _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v18)),
                     _mm_and_ps(v19, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
    v12 = _mm_and_ps(v20, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
    LODWORD(this->ViewProj.M[0][0]) = _mm_cvtsi128_si32(v11);
    v13 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v6),
                         _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v17)),
                       _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v18)),
                     v12);
    v14 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v6),
                         _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v17)),
                       _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v18)),
                     _mm_and_ps(v9, v5));
    LODWORD(this->ViewProj.M[0][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v11, 4));
    LODWORD(this->ViewProj.M[0][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v11, 8));
    LODWORD(this->ViewProj.M[0][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v11, 12));
    v15 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), v6),
                         _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v17)),
                       _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), v18)),
                     _mm_and_ps(v10, v5));
    LODWORD(this->ViewProj.M[1][0]) = _mm_cvtsi128_si32(v13);
    LODWORD(this->ViewProj.M[1][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v13, 4));
    LODWORD(this->ViewProj.M[1][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v13, 8));
    LODWORD(this->ViewProj.M[1][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v13, 12));
    LODWORD(this->ViewProj.M[2][0]) = _mm_cvtsi128_si32(v14);
    LODWORD(this->ViewProj.M[2][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v14, 4));
    LODWORD(this->ViewProj.M[2][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v14, 8));
    LODWORD(this->ViewProj.M[2][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v14, 12));
    LODWORD(this->ViewProj.M[3][0]) = _mm_cvtsi128_si32(v15);
    LODWORD(this->ViewProj.M[3][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v15, 4));
    LODWORD(this->ViewProj.M[3][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v15, 8));
    LODWORD(this->ViewProj.M[3][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v15, 12));
    this->bRecomputeViewProj = 0;
    return &this->ViewProj;
  }
  else
  {
    memset(&this->ViewProj, 0, sizeof(this->ViewProj));
    this->ViewProj.M[0][0] = 1.0;
    this->ViewProj.M[1][1] = 1.0;
    this->ViewProj.M[2][2] = 1.0;
    this->ViewProj.M[3][3] = 1.0;
    this->bRecomputeViewProj = 0;
    return &this->ViewProj;
  }
}

// File Line: 185
// RVA: 0x9B5920
void __fastcall Scaleform::Render::TransformArgs::SetViewProj(
        Scaleform::Render::TransformArgs *this,
        Scaleform::Render::TreeNode::NodeData *data,
        Scaleform::Render::TransformArgs *t)
{
  unsigned __int16 Flags; // bp
  Scaleform::Render::StateBag *v6; // rdi
  Scaleform::Render::StateBag *v7; // r14

  if ( t )
  {
    this->viewState = t->viewState;
    this->projState = t->projState;
    this->bRecomputeViewProj = t->bRecomputeViewProj;
    this->ViewProj = t->ViewProj;
  }
  if ( data )
  {
    Flags = data->Flags;
    v6 = 0i64;
    if ( (Flags & 0x800) != 0 )
      v7 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::ViewMatrix3DState>(data);
    else
      v7 = 0i64;
    if ( (Flags & 0x1000) != 0 )
      v6 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::ProjectionMatrix3DState>(data);
    if ( v7 )
    {
      this->viewState = (Scaleform::Render::ViewMatrix3DState *)v7;
      this->bRecomputeViewProj = 1;
    }
    if ( v6 )
    {
      this->projState = (Scaleform::Render::ProjectionMatrix3DState *)v6;
      this->bRecomputeViewProj = 1;
    }
  }
}

// File Line: 392
// RVA: 0x98A7B0
__int64 __fastcall Scaleform::Render::TreeCacheNode::GetPatternChain(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::BundleEntryRange *range,
        unsigned int flags)
{
  __int64 result; // rax

  result = 0i64;
  range->pLast = 0i64;
  range->pFirst = 0i64;
  range->Length = 0;
  return result;
}

// File Line: 425
// RVA: 0x946850
void __fastcall Scaleform::Render::TreeCacheContainer::TreeCacheContainer(
        Scaleform::Render::TreeCacheContainer *this,
        Scaleform::Render::TreeNode *pnode,
        Scaleform::Render::Renderer2DImpl *prenderer2D,
        unsigned __int16 flags)
{
  float *p_x2; // rax

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
  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheContainer::`vftable;
  p_x2 = &this->SortParentBounds.x2;
  if ( this == (Scaleform::Render::TreeCacheContainer *)-112i64 )
    p_x2 = 0i64;
  this->Children.Root.pPrev = (Scaleform::Render::TreeCacheNode *)p_x2;
  this->Children.Root.pNext = (Scaleform::Render::TreeCacheNode *)p_x2;
  this->CachedChildPattern.pFirst = 0i64;
  this->CachedChildPattern.pLast = 0i64;
  this->CachedChildPattern.Length = 0x80000000;
}

// File Line: 481
// RVA: 0x9469C0
void __fastcall Scaleform::Render::TreeCacheRoot::TreeCacheRoot(
        Scaleform::Render::TreeCacheRoot *this,
        Scaleform::Render::Renderer2DImpl *prenderer2D,
        Scaleform::Render::HAL *phal,
        unsigned __int16 flags,
        Scaleform::Render::TreeRoot *pnode)
{
  Scaleform::MemoryHeap *v7; // rax
  Scaleform::Render::TreeCacheNode **v8; // rcx
  __int64 v9; // rdx

  Scaleform::Render::TreeCacheContainer::TreeCacheContainer(this, pnode, prenderer2D, flags);
  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheRoot::`vftable;
  this->pHAL = phal;
  *(_QWORD *)&this->ViewCullRect.x1 = 0i64;
  *(_QWORD *)&this->ViewCullRect.x2 = 0i64;
  this->pUpdateList = 0i64;
  *(_WORD *)&this->ViewValid = 0;
  this->DepthUpdatesChained = 0;
  v7 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  this->DepthUpdates.pDepth = this->DepthUpdates.ArrayReserve;
  this->DepthUpdates.DepthUsed = 0;
  this->DepthUpdates.DepthAvailable = 32;
  this->DepthUpdates.pHeap = v7;
  this->DepthUpdates.NullValue = 0i64;
  v8 = &this->DepthUpdates.ArrayReserve[1];
  v9 = 16i64;
  do
  {
    *(v8 - 1) = this->DepthUpdates.NullValue;
    *v8 = this->DepthUpdates.NullValue;
    v8 += 2;
    --v9;
  }
  while ( v9 );
  this->pRoot = this;
  this->CachedChildPattern.pLast = 0i64;
  this->CachedChildPattern.pFirst = 0i64;
  this->CachedChildPattern.Length = 0;
}

// File Line: 488
// RVA: 0x94D790
void __fastcall Scaleform::Render::TreeCacheRoot::~TreeCacheRoot(Scaleform::Render::TreeCacheRoot *this)
{
  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheRoot::`vftable;
  if ( this->pPrev )
  {
    this->pPrev->Scaleform::Render::TreeCacheContainer::Scaleform::Render::TreeCacheNode::pNext = this->pNext;
    this->pNext->Scaleform::Render::TreeCacheContainer::Scaleform::Render::TreeCacheNode::pPrev = this->pPrev;
    this->pPrev = (Scaleform::Render::TreeCacheNode *)-1i64;
    this->pNext = (Scaleform::Render::TreeCacheNode *)-1i64;
    this->pNext = 0i64;
    this->pPrev = 0i64;
  }
  if ( this->DepthUpdates.pDepth != this->DepthUpdates.ArrayReserve )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Render::TreeCacheContainer::~TreeCacheContainer(this);
}

// File Line: 580
// RVA: 0x9912E0
void __fastcall Scaleform::Render::TreeCacheMeshBase::HandleRemoveNode(Scaleform::Render::TreeCacheMeshBase *this)
{
  Scaleform::Render::TreeCacheNode *pMask; // rcx

  this->pRoot = 0i64;
  pMask = this->pMask;
  if ( pMask )
    pMask->vfptr->HandleRemoveNode(pMask);
  this->SorterShapeNode.Removed = 1;
}

// File Line: 605
// RVA: 0x9E7C20
bool __fastcall Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F>::grow(
        Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F> *this,
        unsigned __int64 reserve)
{
  unsigned __int64 v3; // rsi
  Scaleform::Render::Rect2F *v4; // rax
  Scaleform::Render::Rect2F *v5; // rdi

  v3 = (reserve + 31) & 0xFFFFFFFFFFFFFFE0ui64;
  v4 = (Scaleform::Render::Rect2F *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, unsigned __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                      Scaleform::Memory::pGlobalHeap,
                                      32 * v3,
                                      16i64);
  v5 = v4;
  if ( v4 )
  {
    memmove(v4, this->pData, 32 * this->Size);
    if ( this->pData != (Scaleform::Render::Rect2F *)((unsigned __int64)&this->DataReserve[15] & 0xFFFFFFFFFFFFFFF0ui64) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    this->pData = v5;
    this->Reserve = v3;
    LOBYTE(v4) = 1;
  }
  return (char)v4;
}

// File Line: 626
// RVA: 0x9483C0
void __fastcall Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F>::~FixedSizeArray<Scaleform::Render::Rect2F>(
        Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F> *this)
{
  Scaleform::Render::Rect2F *pData; // rdx

  pData = this->pData;
  this->Size = 0i64;
  if ( pData != (Scaleform::Render::Rect2F *)((unsigned __int64)&this->DataReserve[15] & 0xFFFFFFFFFFFFFFF0ui64) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

