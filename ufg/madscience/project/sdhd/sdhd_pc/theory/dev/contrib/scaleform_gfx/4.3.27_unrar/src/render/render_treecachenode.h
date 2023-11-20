// File Line: 123
// RVA: 0x946570
void __fastcall Scaleform::Render::TransformArgs::TransformArgs(Scaleform::Render::TransformArgs *this, Scaleform::Render::TransformArgs *copy, Scaleform::Render::Matrix2x4<float> *mat)
{
  float v3; // eax
  float v4; // xmm1_4
  float v5; // xmm2_4

  v3 = copy->CullRect.x1;
  v4 = copy->CullRect.x2;
  v5 = copy->CullRect.y2;
  this->CullRect.y1 = copy->CullRect.y1;
  this->CullRect.x2 = v4;
  this->CullRect.x1 = v3;
  this->CullRect.y2 = v5;
  this->Mat = *mat;
  *(_OWORD *)&this->Cx.M[0][0] = *(_OWORD *)&copy->Cx.M[0][0];
  *(_OWORD *)&this->Cx.M[1][0] = *(_OWORD *)&copy->Cx.M[1][0];
  this->viewState = copy->viewState;
  this->projState = copy->projState;
  this->bRecomputeViewProj = copy->bRecomputeViewProj;
  *(_OWORD *)&this->ViewProj.M[0][0] = *(_OWORD *)&copy->ViewProj.M[0][0];
  *(_OWORD *)&this->ViewProj.M[1][0] = *(_OWORD *)&copy->ViewProj.M[1][0];
  *(_OWORD *)&this->ViewProj.M[2][0] = *(_OWORD *)&copy->ViewProj.M[2][0];
  *(_OWORD *)&this->ViewProj.M[3][0] = *(_OWORD *)&copy->ViewProj.M[3][0];
}

// File Line: 129
// RVA: 0x9466A0
void __fastcall Scaleform::Render::TransformArgs::TransformArgs(Scaleform::Render::TransformArgs *this, Scaleform::Render::TransformArgs *copy, Scaleform::Render::Matrix3x4<float> *mat)
{
  float v3; // eax
  float v4; // xmm1_4
  float v5; // xmm2_4

  v3 = copy->CullRect.x1;
  v4 = copy->CullRect.x2;
  v5 = copy->CullRect.y2;
  this->CullRect.y1 = copy->CullRect.y1;
  this->CullRect.x2 = v4;
  this->CullRect.x1 = v3;
  this->CullRect.y2 = v5;
  this->Mat3D = *mat;
  *(_OWORD *)&this->Mat.M[0][0] = *(_OWORD *)&Scaleform::Render::Matrix2x4<float>::Identity.M[0][0];
  *(_OWORD *)&this->Mat.M[1][0] = *(_OWORD *)&Scaleform::Render::Matrix2x4<float>::Identity.M[1][0];
  *(_OWORD *)&this->Cx.M[0][0] = *(_OWORD *)&copy->Cx.M[0][0];
  *(_OWORD *)&this->Cx.M[1][0] = *(_OWORD *)&copy->Cx.M[1][0];
  this->viewState = copy->viewState;
  this->projState = copy->projState;
  this->bRecomputeViewProj = copy->bRecomputeViewProj;
  *(_OWORD *)&this->ViewProj.M[0][0] = *(_OWORD *)&copy->ViewProj.M[0][0];
  *(_OWORD *)&this->ViewProj.M[1][0] = *(_OWORD *)&copy->ViewProj.M[1][0];
  *(_OWORD *)&this->ViewProj.M[2][0] = *(_OWORD *)&copy->ViewProj.M[2][0];
  *(_OWORD *)&this->ViewProj.M[3][0] = *(_OWORD *)&copy->ViewProj.M[3][0];
}

// File Line: 140
// RVA: 0x99FBA0
void __fastcall Scaleform::Render::TransformArgs::PrependMatrix3D(Scaleform::Render::TransformArgs *this, Scaleform::Render::Matrix3x4<float> *m)
{
  float v2; // eax
  Scaleform::Render::Matrix3x4<float> *v3; // rcx
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+20h] [rbp-38h]

  v2 = this->Mat3D.M[0][0];
  v3 = &this->Mat3D;
  m1.M[0][0] = v2;
  *(_QWORD *)&m1.M[0][1] = *(_QWORD *)&v3->M[0][1];
  m1.M[0][3] = v3->M[0][3];
  *(_OWORD *)&m1.M[1][0] = *(_OWORD *)&v3->M[1][0];
  *(_OWORD *)&m1.M[2][0] = *(_OWORD *)&v3->M[2][0];
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(v3, &m1, m);
}

// File Line: 142
// RVA: 0x988C60
void __fastcall Scaleform::Render::TransformArgs::GetMatrix3D(Scaleform::Render::TransformArgs *this, Scaleform::Render::TransformFlags flags, Scaleform::Render::Matrix3x4<float> *m)
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
    LODWORD(m->M[2][1]) = (unsigned __int128)_mm_shuffle_ps(_xmm, _xmm, 85);
    LODWORD(m->M[2][2]) = (unsigned __int128)_mm_shuffle_ps(_xmm, _xmm, 170);
    m->M[2][3] = _xmm.m128_f32[3];
  }
  else if ( flags & 0x40 )
  {
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(m, &this->Mat3D, &this->Mat);
  }
  else
  {
    *(_OWORD *)&m->M[0][0] = *(_OWORD *)&this->Mat3D.M[0][0];
    *(_OWORD *)&m->M[1][0] = *(_OWORD *)&this->Mat3D.M[1][0];
    *(_OWORD *)&m->M[2][0] = *(_OWORD *)&this->Mat3D.M[2][0];
  }
}

// File Line: 155
// RVA: 0x98F330
Scaleform::Render::Matrix4x4<float> *__fastcall Scaleform::Render::TransformArgs::GetViewProj(Scaleform::Render::TransformArgs *this)
{
  Scaleform::Render::TransformArgs *v1; // rdi
  Scaleform::Render::ViewMatrix3DState *v2; // rcx
  Scaleform::Render::ProjectionMatrix3DState *v3; // rdx
  __m128 *v4; // rcx
  __m128 v5; // ST18_16
  __m128 v6; // xmm10
  __m128 v7; // xmm5
  __m128 v8; // ST38_16
  int v9; // eax
  char *v10; // rcx
  __m128 v11; // ST48_16
  __m128 v12; // ST58_16
  __m128 v13; // xmm4
  __m128 v14; // xmm8
  __m128i v15; // xmm11
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128i v18; // xmm9
  __m128i v19; // xmm3
  __m128i v20; // xmm2
  Scaleform::Render::Matrix4x4<float> *result; // rax

  v1 = this;
  if ( !this->bRecomputeViewProj )
    return &this->ViewProj;
  v2 = this->viewState;
  if ( v2 && (v3 = v1->projState) != 0i64 )
  {
    v4 = (__m128 *)v2->pData;
    v5.m128_u64[0] = v4[1].m128_u64[0];
    v6 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v;
    v5.m128_u64[1] = v4[1].m128_u64[1];
    v7 = v4[2];
    v8.m128_u64[0] = v4[3].m128_u64[0];
    v8.m128_i32[2] = v4[3].m128_i32[2];
    v9 = v4[3].m128_i32[3];
    v10 = (char *)v3->pData;
    v8.m128_i32[3] = v9;
    v11 = *((__m128 *)v10 + 1);
    v12.m128_i32[0] = *((_DWORD *)v10 + 8);
    *(unsigned __int64 *)((char *)v12.m128_u64 + 4) = *(_QWORD *)(v10 + 36);
    v12.m128_i32[3] = *((_DWORD *)v10 + 11);
    v13 = *((__m128 *)v10 + 3);
    v14 = *((__m128 *)v10 + 4);
    v15 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v7),
                         _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v5)),
                       _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v8)),
                     _mm_and_ps(v11, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
    v16 = *((__m128 *)v10 + 4);
    v17 = _mm_and_ps(v12, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v);
    LODWORD(v1->ViewProj.M[0][0]) = _mm_cvtsi128_si32(v15);
    v18 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), v7),
                         _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v5)),
                       _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v8)),
                     v17);
    v19 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v7),
                         _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v5)),
                       _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v8)),
                     _mm_and_ps(v13, v6));
    LODWORD(v1->ViewProj.M[0][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v15, 4));
    LODWORD(v1->ViewProj.M[0][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v15, 8));
    LODWORD(v1->ViewProj.M[0][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v15, 12));
    v20 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v7),
                         _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v5)),
                       _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v8)),
                     _mm_and_ps(v14, v6));
    LODWORD(v1->ViewProj.M[1][0]) = _mm_cvtsi128_si32(v18);
    LODWORD(v1->ViewProj.M[1][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v18, 4));
    LODWORD(v1->ViewProj.M[1][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v18, 8));
    LODWORD(v1->ViewProj.M[1][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v18, 12));
    LODWORD(v1->ViewProj.M[2][0]) = _mm_cvtsi128_si32(v19);
    LODWORD(v1->ViewProj.M[2][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v19, 4));
    LODWORD(v1->ViewProj.M[2][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v19, 8));
    LODWORD(v1->ViewProj.M[2][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v19, 12));
    LODWORD(v1->ViewProj.M[3][0]) = _mm_cvtsi128_si32(v20);
    LODWORD(v1->ViewProj.M[3][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v20, 4));
    LODWORD(v1->ViewProj.M[3][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v20, 8));
    LODWORD(v1->ViewProj.M[3][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v20, 12));
    v1->bRecomputeViewProj = 0;
    result = &v1->ViewProj;
  }
  else
  {
    memset(&v1->ViewProj, 0, 0x40ui64);
    v1->ViewProj.M[0][0] = 1.0;
    v1->ViewProj.M[1][1] = 1.0;
    v1->ViewProj.M[2][2] = 1.0;
    v1->ViewProj.M[3][3] = 1.0;
    v1->bRecomputeViewProj = 0;
    result = &v1->ViewProj;
  }
  return result;
}

// File Line: 185
// RVA: 0x9B5920
void __fastcall Scaleform::Render::TransformArgs::SetViewProj(Scaleform::Render::TransformArgs *this, Scaleform::Render::TreeNode::NodeData *data, Scaleform::Render::TransformArgs *t)
{
  Scaleform::Render::TreeNode::NodeData *v3; // rsi
  Scaleform::Render::TransformArgs *v4; // rbx
  unsigned __int16 v5; // bp
  Scaleform::Render::StateBag *v6; // rdi
  Scaleform::Render::StateBag *v7; // r14

  v3 = data;
  v4 = this;
  if ( t )
  {
    this->viewState = t->viewState;
    this->projState = t->projState;
    this->bRecomputeViewProj = t->bRecomputeViewProj;
    *(_OWORD *)&this->ViewProj.M[0][0] = *(_OWORD *)&t->ViewProj.M[0][0];
    *(_OWORD *)&this->ViewProj.M[1][0] = *(_OWORD *)&t->ViewProj.M[1][0];
    *(_OWORD *)&this->ViewProj.M[2][0] = *(_OWORD *)&t->ViewProj.M[2][0];
    *(_OWORD *)&this->ViewProj.M[3][0] = *(_OWORD *)&t->ViewProj.M[3][0];
  }
  if ( data )
  {
    v5 = data->Flags;
    v6 = 0i64;
    if ( (v5 >> 11) & 1 )
      v7 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::ViewMatrix3DState>(data);
    else
      v7 = 0i64;
    if ( (v5 >> 12) & 1 )
      v6 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::ProjectionMatrix3DState>(v3);
    if ( v7 )
    {
      v4->viewState = (Scaleform::Render::ViewMatrix3DState *)v7;
      v4->bRecomputeViewProj = 1;
    }
    if ( v6 )
    {
      v4->projState = (Scaleform::Render::ProjectionMatrix3DState *)v6;
      v4->bRecomputeViewProj = 1;
    }
  }
}

// File Line: 392
// RVA: 0x98A7B0
__int64 __fastcall Scaleform::Render::TreeCacheNode::GetPatternChain(Scaleform::Render::TreeCacheNode *this, Scaleform::Render::BundleEntryRange *range, unsigned int flags)
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
void __fastcall Scaleform::Render::TreeCacheContainer::TreeCacheContainer(Scaleform::Render::TreeCacheContainer *this, Scaleform::Render::TreeNode *pnode, Scaleform::Render::Renderer2DImpl *prenderer2D, unsigned int flags)
{
  Scaleform::Render::TreeCacheNode *v4; // rax

  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheNode::`vftable';
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
  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheContainer::`vftable';
  v4 = (Scaleform::Render::TreeCacheNode *)&this->SortParentBounds.x2;
  if ( this == (Scaleform::Render::TreeCacheContainer *)-112i64 )
    v4 = 0i64;
  this->Children.Root.pPrev = v4;
  this->Children.Root.pNext = v4;
  this->CachedChildPattern.pFirst = 0i64;
  this->CachedChildPattern.pLast = 0i64;
  this->CachedChildPattern.Length = 2147483648;
}

// File Line: 481
// RVA: 0x9469C0
void __fastcall Scaleform::Render::TreeCacheRoot::TreeCacheRoot(Scaleform::Render::TreeCacheRoot *this, Scaleform::Render::Renderer2DImpl *prenderer2D, Scaleform::Render::HAL *phal, unsigned int flags, Scaleform::Render::TreeRoot *pnode)
{
  Scaleform::Render::HAL *v5; // rbx
  Scaleform::Render::TreeCacheRoot *v6; // rdi
  Scaleform::MemoryHeap *v7; // rax
  Scaleform::Render::TreeCacheNode **v8; // rcx
  signed __int64 v9; // rdx

  v5 = phal;
  v6 = this;
  Scaleform::Render::TreeCacheContainer::TreeCacheContainer(
    (Scaleform::Render::TreeCacheContainer *)&this->vfptr,
    (Scaleform::Render::TreeNode *)&pnode->0,
    prenderer2D,
    flags);
  v6->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheRoot::`vftable';
  v6->pHAL = v5;
  *(_QWORD *)&v6->ViewCullRect.x1 = 0i64;
  *(_QWORD *)&v6->ViewCullRect.x2 = 0i64;
  v6->pUpdateList = 0i64;
  *(_WORD *)&v6->ViewValid = 0;
  v6->DepthUpdatesChained = 0;
  v7 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v6);
  v6->DepthUpdates.pDepth = v6->DepthUpdates.ArrayReserve;
  v6->DepthUpdates.DepthUsed = 0;
  v6->DepthUpdates.DepthAvailable = 32;
  v6->DepthUpdates.pHeap = v7;
  v6->DepthUpdates.NullValue = 0i64;
  v8 = &v6->DepthUpdates.ArrayReserve[1];
  v9 = 16i64;
  do
  {
    *(v8 - 1) = v6->DepthUpdates.NullValue;
    *v8 = v6->DepthUpdates.NullValue;
    v8 += 2;
    --v9;
  }
  while ( v9 );
  v6->pRoot = v6;
  v6->CachedChildPattern.pLast = 0i64;
  v6->CachedChildPattern.pFirst = 0i64;
  v6->CachedChildPattern.Length = 0;
}

// File Line: 488
// RVA: 0x94D790
void __fastcall Scaleform::Render::TreeCacheRoot::~TreeCacheRoot(Scaleform::Render::TreeCacheRoot *this)
{
  Scaleform::Render::TreeCacheRoot *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::Render::TreeCacheNodeVtbl *)&Scaleform::Render::TreeCacheRoot::`vftable';
  if ( this->pPrev )
  {
    this->pPrev->pNext = this->pNext;
    this->pNext->pPrev = this->pPrev;
    this->pPrev = (Scaleform::Render::TreeCacheNode *)-1i64;
    this->pNext = (Scaleform::Render::TreeCacheNode *)-1i64;
    this->pNext = 0i64;
    this->pPrev = 0i64;
  }
  if ( this->DepthUpdates.pDepth != this->DepthUpdates.ArrayReserve )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Render::TreeCacheContainer::~TreeCacheContainer((Scaleform::Render::TreeCacheContainer *)&v1->vfptr);
}

// File Line: 580
// RVA: 0x9912E0
void __fastcall Scaleform::Render::TreeCacheMeshBase::HandleRemoveNode(Scaleform::Render::TreeCacheMeshBase *this)
{
  Scaleform::Render::TreeCacheMeshBase *v1; // rbx
  Scaleform::Render::TreeCacheNode *v2; // rcx

  v1 = this;
  this->pRoot = 0i64;
  v2 = this->pMask;
  if ( v2 )
    ((void (*)(void))v2->vfptr->HandleRemoveNode)();
  v1->SorterShapeNode.Removed = 1;
}

// File Line: 605
// RVA: 0x9E7C20
bool __fastcall Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F>::grow(Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F> *this, unsigned __int64 reserve)
{
  Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F> *v2; // rbx
  unsigned __int64 v3; // rsi
  Scaleform::Render::Rect2F *v4; // rax
  Scaleform::Render::Rect2F *v5; // rdi

  v2 = this;
  v3 = (reserve + 31) & 0xFFFFFFFFFFFFFFE0ui64;
  v4 = (Scaleform::Render::Rect2F *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, unsigned __int64, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                      Scaleform::Memory::pGlobalHeap,
                                      32 * v3,
                                      16i64);
  v5 = v4;
  if ( v4 )
  {
    memmove(v4, v2->pData, 32 * v2->Size);
    if ( v2->pData != (Scaleform::Render::Rect2F *)((unsigned __int64)&v2->DataReserve[15] & 0xFFFFFFFFFFFFFFF0ui64) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v2->pData = v5;
    v2->Reserve = v3;
    LOBYTE(v4) = 1;
  }
  return (char)v4;
}

// File Line: 626
// RVA: 0x9483C0
void __fastcall Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F>::~FixedSizeArray<Scaleform::Render::Rect2F>(Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F> *this)
{
  Scaleform::Render::Rect2F *v1; // rdx

  v1 = this->pData;
  this->Size = 0i64;
  if ( v1 != (Scaleform::Render::Rect2F *)((unsigned __int64)&this->DataReserve[15] & 0xFFFFFFFFFFFFFFF0ui64) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

