// File Line: 50
// RVA: 0x159C480
__int64 dynamic_initializer_for__Scaleform::Render::ImageGlyphVertex::Format__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::ImageGlyphVertex::Format__);
}

// File Line: 64
// RVA: 0x981A70
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::VectorGlyphShape::GetIdentityBounds(
        Scaleform::Render::VectorGlyphShape *this,
        Scaleform::Render::Rect<float> *result)
{
  result->x1 = *(float *)&this->pRaster.pObject;
  result->y1 = *((float *)&this->pRaster.pObject + 1);
  result->x2 = *((float *)&this->pRaster + 2);
  result->y2 = *((float *)&this->pRaster + 3);
  return result;
}

// File Line: 126
// RVA: 0x982370
bool __fastcall Scaleform::Render::VectorGlyphShape::GetData(
        Scaleform::Render::VectorGlyphShape *this,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::VertexOutput *verOut,
        char meshGenFlags)
{
  Scaleform::Render::Renderer2DImpl *pRenderer2D; // rbx
  Scaleform::Render::Matrix2x4<float> *p_ViewMatrix; // r12
  Scaleform::Render::MeshGenerator *p_MeshGen; // r13
  float v11; // xmm13_4
  float v12; // xmm2_4
  unsigned int CurveRecursionLimit; // eax
  float v14; // xmm0_4
  Scaleform::Render::Tessellator *p_mTess; // rbx
  unsigned int v16; // esi
  int v17; // eax
  Scaleform::Render::FontCacheHandle *pFont; // rcx
  int v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm8_4
  float v22; // xmm14_4
  float v23; // xmm15_4
  int v24; // xmm0_4
  Scaleform::Render::FontCacheHandle *pPrev; // rax
  char v26; // r14
  int v27; // eax
  float v28; // xmm13_4
  float v29; // xmm2_4
  int i; // eax
  float v31; // xmm2_4
  float v32; // xmm0_4
  float y3; // xmm5_4
  float v34; // xmm12_4
  float v35; // xmm11_4
  float y2; // xmm11_4
  float v37; // xmm9_4
  float v38; // xmm10_4
  float x4; // xmm8_4
  float v40; // xmm7_4
  float y4; // xmm7_4
  double v42; // xmm0_8
  float v43; // xmm6_4
  int v44; // ecx
  Scaleform::Render::VertexOutputVtbl *vfptr; // rax
  bool NullVectorMesh; // r12
  unsigned int v47; // r14d
  unsigned int j; // edi
  char *v49; // rdx
  char *v50; // r8
  __int64 v51; // r9
  __m128 v52; // xmm1
  int v53; // ecx
  __m128 v54; // xmm2
  int v55; // ecx
  unsigned __int64 v56; // rcx
  unsigned int v57; // r14d
  int v58; // edi
  float v59; // [rsp+60h] [rbp-A0h] BYREF
  float v60; // [rsp+64h] [rbp-9Ch]
  float x3; // [rsp+68h] [rbp-98h]
  float v62; // [rsp+6Ch] [rbp-94h]
  float v63; // [rsp+70h] [rbp-90h]
  float v64; // [rsp+74h] [rbp-8Ch]
  int v65; // [rsp+80h] [rbp-80h]
  float v66; // [rsp+90h] [rbp-70h]
  int v67; // [rsp+98h] [rbp-68h] BYREF
  __int64 v68; // [rsp+9Ch] [rbp-64h]
  __int64 v69; // [rsp+A4h] [rbp-5Ch]
  __int64 v70; // [rsp+ACh] [rbp-54h]
  __int64 v71; // [rsp+B4h] [rbp-4Ch]
  __int64 v72; // [rsp+BCh] [rbp-44h]
  int v73; // [rsp+C4h] [rbp-3Ch]
  int v74; // [rsp+C8h] [rbp-38h]
  char v75; // [rsp+CCh] [rbp-34h]
  int v76[4]; // [rsp+D0h] [rbp-30h] BYREF
  int v77[2]; // [rsp+E0h] [rbp-20h] BYREF
  Scaleform::Render::VertexFormat *v78; // [rsp+E8h] [rbp-18h]
  __int64 v79; // [rsp+F0h] [rbp-10h]
  __int64 v80; // [rsp+F8h] [rbp-8h]
  Scaleform::Render::ToleranceParams param; // [rsp+100h] [rbp+0h] BYREF
  Scaleform::Render::Matrix2x4<float> v82; // [rsp+150h] [rbp+50h] BYREF
  Scaleform::Render::TessMesh v83; // [rsp+170h] [rbp+70h] BYREF
  Scaleform::Render::Matrix2x4<float> v84; // [rsp+190h] [rbp+90h] BYREF
  unsigned __int16 v85[384]; // [rsp+1B0h] [rbp+B0h] BYREF
  char v86[4]; // [rsp+4B0h] [rbp+3B0h] BYREF
  char v87; // [rsp+4B4h] [rbp+3B4h] BYREF
  char v88[4]; // [rsp+AB0h] [rbp+9B0h] BYREF
  char v89; // [rsp+AB4h] [rbp+9B4h] BYREF
  float v90; // [rsp+1590h] [rbp+1490h]
  float v91; // [rsp+1598h] [rbp+1498h]

  pRenderer2D = mesh->pRenderer2D;
  p_ViewMatrix = &mesh->ViewMatrix;
  if ( ((__int64 (__fastcall *)(Scaleform::Render::FontCacheHandle *))this->Key.pFont->pPrev->pNext)(this->Key.pFont) )
    return Scaleform::Render::VectorGlyphShape::generateNullVectorMesh(
             (Scaleform::Render::VectorGlyphShape *)((char *)this - 16),
             verOut);
  p_MeshGen = &pRenderer2D->MeshGen;
  Scaleform::Render::MeshGenerator::Clear(&pRenderer2D->MeshGen);
  v11 = FLOAT_0_5;
  *(_OWORD *)&param.Epsilon = *(_OWORD *)&pRenderer2D->Tolerances.Epsilon;
  v12 = _mm_shuffle_ps(*(__m128 *)&param.Epsilon, *(__m128 *)&param.Epsilon, 85).m128_f32[0] * 2.0;
  *(_OWORD *)&param.FillLowerScale = *(_OWORD *)&pRenderer2D->Tolerances.FillLowerScale;
  *(_OWORD *)&param.StrokeLowerScale = *(_OWORD *)&pRenderer2D->Tolerances.StrokeLowerScale;
  *(_OWORD *)&param.Scale9LowerScale = *(_OWORD *)&pRenderer2D->Tolerances.Scale9LowerScale;
  *(_QWORD *)&param.MinDet3D = *(_QWORD *)&pRenderer2D->Tolerances.MinDet3D;
  CurveRecursionLimit = pRenderer2D->Tolerances.CurveRecursionLimit;
  param.CollinearityTolerance = param.CollinearityTolerance * 2.0;
  param.CurveTolerance = v12;
  param.CurveRecursionLimit = CurveRecursionLimit;
  if ( (meshGenFlags & 1) == 0 || (meshGenFlags & 2) != 0 )
    v14 = 0.0;
  else
    v14 = param.EdgeAAScale * 0.5;
  pRenderer2D->MeshGen.mTess.EdgeAAWidth = v14;
  p_mTess = &pRenderer2D->MeshGen.mTess;
  v16 = 0;
  p_MeshGen->mTess.EdgeAAFlag = v14 > 0.0;
  p_MeshGen->mTess.FillRule = FillNonZero;
  p_MeshGen->mTess.StrokerMode = 0;
  v17 = ((__int64 (__fastcall *)(Scaleform::Render::FontCacheHandle *))this->Key.pFont->pPrev[1].pManager)(this->Key.pFont);
  pFont = this->Key.pFont;
  v19 = SLODWORD(p_ViewMatrix->M[1][0]);
  v20 = p_ViewMatrix->M[1][1];
  v21 = p_ViewMatrix->M[1][3];
  v68 = 0i64;
  v69 = 0i64;
  v70 = 0i64;
  v22 = p_ViewMatrix->M[0][0];
  v23 = p_ViewMatrix->M[0][1];
  v74 = (int)FLOAT_1_0;
  v67 = v17;
  v71 = 0i64;
  v72 = 0i64;
  v24 = LODWORD(p_ViewMatrix->M[0][3]);
  v65 = v19;
  v90 = v20;
  v73 = 0;
  v75 = 0;
  pPrev = pFont->pPrev;
  v66 = *(float *)&v24;
  v91 = v21;
  v26 = 1;
  v27 = ((__int64 (__fastcall *)(Scaleform::Render::FontCacheHandle *, int *, float *, int *))pPrev[2].pPrev)(
          pFont,
          &v67,
          &v59,
          v76);
  if ( v27 )
  {
    v28 = v66;
    do
    {
      if ( !v26 && v27 == 2 )
        break;
      v26 = 0;
      if ( v76[0] == v76[1] )
      {
        ((void (__fastcall *)(Scaleform::Render::FontCacheHandle *, int *))this->Key.pFont->pPrev[2].pManager)(
          this->Key.pFont,
          &v67);
      }
      else
      {
        v29 = (float)(v60 * v20) + (float)(*(float *)&v19 * v59);
        v59 = (float)((float)(v60 * v23) + (float)(v59 * v22)) + v28;
        v60 = v29 + v21;
        ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(&p_MeshGen->mTess);
        for ( i = ((__int64 (__fastcall *)(Scaleform::Render::FontCacheHandle *, int *, float *))this->Key.pFont->pPrev[2].pNext)(
                    this->Key.pFont,
                    &v67,
                    &v59);
              i;
              i = ((__int64 (__fastcall *)(Scaleform::Render::FontCacheHandle *, int *, float *))this->Key.pFont->pPrev[2].pNext)(
                    this->Key.pFont,
                    &v67,
                    &v59) )
        {
          switch ( i )
          {
            case 1:
              v31 = (float)(v60 * v20) + (float)(*(float *)&v19 * v59);
              v59 = (float)((float)(v60 * v23) + (float)(v59 * v22)) + v28;
              v60 = v31 + v21;
              ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(&p_MeshGen->mTess);
              break;
            case 2:
              v32 = *(float *)&v19 * v59;
              v59 = (float)((float)(v60 * v23) + (float)(v59 * v22)) + v28;
              v60 = (float)((float)(v60 * v20) + v32) + v21;
              y3 = (float)((float)(v62 * v20) + (float)(*(float *)&v19 * x3)) + v21;
              x3 = (float)((float)(v62 * v23) + (float)(x3 * v22)) + v28;
              v62 = y3;
              Scaleform::Render::TessellateQuadCurve(&p_MeshGen->mTess, &param, v59, v60, x3, y3);
              break;
            case 3:
              v35 = (float)(v60 * v20) + (float)(*(float *)&v19 * v59);
              v59 = (float)((float)(v60 * v23) + (float)(v59 * v22)) + v28;
              v34 = v59;
              y2 = v35 + v21;
              v60 = y2;
              v37 = (float)((float)(v62 * v20) + (float)(*(float *)&v19 * x3)) + v21;
              x3 = (float)((float)(v62 * v23) + (float)(x3 * v22)) + v28;
              v38 = x3;
              v62 = v37;
              v40 = (float)(v64 * v90) + (float)(*(float *)&v19 * v63);
              v63 = (float)((float)(v64 * v23) + (float)(v63 * v22)) + v28;
              x4 = v63;
              y4 = v40 + v91;
              v64 = y4;
              v42 = ((double (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->GetLastX)(&p_MeshGen->mTess);
              v43 = *(float *)&v42;
              *(float *)&v42 = p_mTess->vfptr->GetLastY(&p_MeshGen->mTess);
              Scaleform::Render::TessellateCubicRecursively(
                &p_MeshGen->mTess,
                &param,
                (float)(param.CurveTolerance * 0.25) * (float)(param.CurveTolerance * 0.25),
                v43,
                *(float *)&v42,
                v34,
                y2,
                v38,
                v37,
                x4,
                y4,
                0);
              v19 = v65;
              v20 = v90;
              v21 = v91;
              break;
          }
        }
        ((void (__fastcall *)(Scaleform::Render::Tessellator *, __int64, _QWORD))p_mTess->vfptr->FinalizePath)(
          &p_MeshGen->mTess,
          1i64,
          0i64);
      }
      v27 = ((__int64 (__fastcall *)(Scaleform::Render::FontCacheHandle *, int *, float *, int *))this->Key.pFont->pPrev[2].pPrev)(
              this->Key.pFont,
              &v67,
              &v59,
              v76);
    }
    while ( v27 );
    v11 = FLOAT_0_5;
  }
  Scaleform::Render::Tessellator::Tessellate(&p_MeshGen->mTess, 0);
  if ( p_mTess->vfptr->GetMeshCount(&p_MeshGen->mTess) && p_mTess->vfptr->GetVertexCount(&p_MeshGen->mTess) )
  {
    *(_OWORD *)&v82.M[0][0] = _xmm;
    *(__m128 *)&v82.M[1][0] = _xmm;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v82, p_ViewMatrix);
    p_mTess->vfptr->Transform(&p_MeshGen->mTess, &v82);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *, Scaleform::Render::Matrix2x4<float> *))p_mTess->vfptr->StretchTo)(
      &p_MeshGen->mTess,
      &v84);
    v77[0] = p_mTess->vfptr->GetMeshVertexCount(&p_MeshGen->mTess, 0);
    v44 = 3
        * ((__int64 (__fastcall *)(Scaleform::Render::Tessellator *, _QWORD))p_mTess->vfptr->GetMeshTriangleCount)(
            &p_MeshGen->mTess,
            0i64);
    v78 = &Scaleform::Render::VertexXY16iCF32::Format;
    vfptr = verOut->vfptr;
    v77[1] = v44;
    v79 = 0i64;
    v80 = 0i64;
    NullVectorMesh = vfptr->BeginOutput(verOut, (Scaleform::Render::VertexOutput::Fill *)v77, 1u, &v84);
    if ( NullVectorMesh )
    {
      p_mTess->vfptr->GetMesh(&p_MeshGen->mTess, 0, &v83);
      v47 = 0;
      for ( j = p_mTess->vfptr->GetVertices(&p_MeshGen->mTess, &v83, (Scaleform::Render::TessVertex *)v88, 128u);
            j;
            j = p_mTess->vfptr->GetVertices(&p_MeshGen->mTess, &v83, (Scaleform::Render::TessVertex *)v88, 128u) )
      {
        v49 = &v87;
        v50 = &v89;
        v51 = j;
        do
        {
          v52 = (__m128)*((unsigned int *)v50 - 1);
          if ( v52.m128_f32[0] >= 0.0 )
            v52.m128_f32[0] = v52.m128_f32[0] + v11;
          else
            v52.m128_f32[0] = v52.m128_f32[0] - v11;
          v53 = (int)v52.m128_f32[0];
          if ( (int)v52.m128_f32[0] != 0x80000000 && (float)v53 != v52.m128_f32[0] )
            v52.m128_f32[0] = (float)(v53 - (_mm_movemask_ps(_mm_unpacklo_ps(v52, v52)) & 1));
          v54 = (__m128)*(unsigned int *)v50;
          *((_WORD *)v49 - 2) = (int)v52.m128_f32[0];
          if ( v54.m128_f32[0] >= 0.0 )
            v54.m128_f32[0] = v54.m128_f32[0] + v11;
          else
            v54.m128_f32[0] = v54.m128_f32[0] - v11;
          v55 = (int)v54.m128_f32[0];
          if ( (int)v54.m128_f32[0] != 0x80000000 && (float)v55 != v54.m128_f32[0] )
            v54.m128_f32[0] = (float)(v55 - (_mm_movemask_ps(_mm_unpacklo_ps(v54, v54)) & 1));
          v56 = *((unsigned __int16 *)v50 + 6);
          *(_DWORD *)v49 = -1;
          v49 += 12;
          v50 += 20;
          *((_WORD *)v49 - 7) = (int)v54.m128_f32[0];
          *(v49 - 8) = Scaleform::Render::Factors[v56 & 3];
          *(v49 - 7) = Scaleform::Render::Factors[(v56 >> 2) & 3];
          --v51;
        }
        while ( v51 );
        verOut->vfptr->SetVertices(verOut, 0, v47, v86, j);
        v47 += j;
      }
      v57 = p_mTess->vfptr->GetMeshTriangleCount(&p_MeshGen->mTess, HIDWORD(v80));
      if ( v57 )
      {
        do
        {
          v58 = 128;
          if ( v16 + 128 > v57 )
          {
            v58 = v57 - v16;
            if ( v57 == v16 )
              break;
          }
          p_mTess->vfptr->GetTrianglesI16(&p_MeshGen->mTess, HIDWORD(v80), v85, v16, v58);
          verOut->vfptr->SetIndices(verOut, 0, 3 * v16, v85, 3 * v58);
          v16 += v58;
        }
        while ( v16 < v57 );
      }
      verOut->vfptr->EndOutput(verOut);
    }
  }
  else
  {
    NullVectorMesh = Scaleform::Render::VectorGlyphShape::generateNullVectorMesh(
                       (Scaleform::Render::VectorGlyphShape *)((char *)this - 16),
                       verOut);
  }
  Scaleform::Render::MeshGenerator::Clear(p_MeshGen);
  return NullVectorMesh;
}

// File Line: 274
// RVA: 0x9838D0
void __fastcall Scaleform::Render::VectorGlyphShape::GetFillData(
        Scaleform::Render::VectorGlyphShape *this,
        Scaleform::Render::FillData *data,
        unsigned int layer,
        unsigned int fillIndex)
{
  Scaleform::Render::GradientData *v4; // [rsp+8h] [rbp-20h]

  data->Type = Fill_VColor;
  data->FillMode.Fill = 0;
  LODWORD(v4) = 0;
  data->PrimFill = PrimFill_VColor;
  data->pGradient = v4;
  data->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
}

// File Line: 313
// RVA: 0x946150
void __fastcall Scaleform::Render::TextMeshProvider::TextMeshProvider(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::GlyphCache *cache)
{
  Scaleform::MemoryHeap *pHeap; // r8
  Scaleform::MemoryHeap *v4; // rcx
  Scaleform::MemoryHeap *v5; // rcx

  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider::`vftable;
  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::TextMeshProvider::`vftable;
  this->pCache = cache;
  this->Flags = 0;
  pHeap = cache->pHeap;
  this->Notifiers.Data.Data = 0i64;
  this->Notifiers.Data.Size = 0i64;
  this->Notifiers.Data.Policy.Capacity = 0i64;
  this->Notifiers.Data.pHeap = pHeap;
  v4 = cache->pHeap;
  this->Entries.Data.Data = 0i64;
  this->Entries.Data.Size = 0i64;
  this->Entries.Data.Policy.Capacity = 0i64;
  this->Entries.Data.pHeap = v4;
  v5 = cache->pHeap;
  this->Layers.Data.Data = 0i64;
  this->Layers.Data.Size = 0i64;
  this->Layers.Data.Policy.Capacity = 0i64;
  this->Layers.Data.pHeap = v5;
  this->PinCount = 0i64;
  this->pBundle = 0i64;
  this->pBundleEntry = 0i64;
  this->HeightRatio = 0.0;
  *(_QWORD *)&this->ClipBox.x1 = 0i64;
  *(_QWORD *)&this->ClipBox.x2 = 0i64;
  *(_QWORD *)&this->ClearBox.x1 = 0i64;
  *(_QWORD *)&this->ClearBox.x2 = 0i64;
  *(_QWORD *)&this->Bounds.x1 = 0i64;
  *(_QWORD *)&this->Bounds.x2 = 0i64;
  this->pRenderer = 0i64;
  this->ClearBounds.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
}

// File Line: 317
// RVA: 0x94D2B0
void __fastcall Scaleform::Render::TextMeshProvider::~TextMeshProvider(Scaleform::Render::TextMeshProvider *this)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rdi
  Scaleform::Render::MatrixPoolImpl::EntryHandle v3; // rdi
  __int64 DataPageOffset; // rcx

  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::TextMeshProvider::`vftable;
  Scaleform::Render::TextMeshProvider::Clear(this);
  pHandle = this->ClearBounds.pHandle;
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
  Scaleform::ArrayDataDH<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataDH<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy>(&this->Layers.Data);
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy>(&this->Entries.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Notifiers.Data.Data);
  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider::`vftable;
}

// File Line: 323
// RVA: 0x960490
void __fastcall Scaleform::Render::TextMeshProvider::ClearEntries(
        Scaleform::Render::TextMeshProvider *this,
        __int64 a2,
        Scaleform::Render::TextNotifier *a3)
{
  unsigned __int64 v3; // rdi
  unsigned __int64 i; // r9
  Scaleform::Render::GlyphCache *pCache; // rdx
  __int64 v7; // rsi
  Scaleform::Render::TextMeshEntry *Data; // rcx
  Scaleform::Render::Font *pFont; // rcx

  v3 = 0i64;
  for ( i = 0i64;
        i < this->Notifiers.Data.Size;
        pCache->Queue.Notifiers.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,75> >::NodeType *)a3 )
  {
    pCache = this->pCache;
    a3 = this->Notifiers.Data.Data[i++];
    a3->pPrev->pNext = a3->pNext;
    a3->pNext->Scaleform::ListNode<Scaleform::Render::TextNotifier>::$99F3527AEFED05E3FF614A03D930FE0D::pPrev = a3->pPrev;
    a3->pPrev = (Scaleform::Render::TextNotifier *)-1i64;
    a3->pNext = (Scaleform::Render::TextNotifier *)-1i64;
    a3->pPrev = (Scaleform::Render::TextNotifier *)pCache->Queue.Notifiers.FirstEmptySlot;
  }
  ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TextNotifier **, Scaleform::Render::TextNotifier *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
    Scaleform::Memory::pGlobalHeap,
    this->Notifiers.Data.Data,
    a3,
    i);
  this->Notifiers.Data.Data = 0i64;
  this->Notifiers.Data.Size = 0i64;
  this->Notifiers.Data.Policy.Capacity = 0i64;
  if ( this->Entries.Data.Size )
  {
    v7 = 0i64;
    do
    {
      Data = this->Entries.Data.Data;
      if ( ((Data[v7].LayerType - 8) & 0xFFFB) == 0 )
      {
        pFont = Data[v7].EntryData.VectorData.pFont;
        if ( !_InterlockedDecrement(&pFont->RefCount) )
        {
          if ( pFont )
            pFont->vfptr->__vecDelDtor(pFont, 1u);
        }
      }
      ++v3;
      ++v7;
    }
    while ( v3 < this->Entries.Data.Size );
  }
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy>::ClearAndRelease(&this->Entries.Data);
  this->Flags &= 0xFFFFFE1F;
}

// File Line: 345
// RVA: 0x960030
void __fastcall Scaleform::Render::TextMeshProvider::Clear(Scaleform::Render::TextMeshProvider *this)
{
  unsigned int Flags; // ecx
  unsigned int v3; // ecx
  Scaleform::Render::TextPrimitiveBundle *pBundle; // rcx

  Flags = this->Flags;
  if ( (Flags & 6) != 0 )
  {
    v3 = Flags & 0xFFFFFFFD;
    this->Flags = v3;
    if ( (v3 & 6) == 4 )
    {
      this->Flags = v3 & 0xFFFFFFFB;
      Scaleform::Render::TextMeshProvider::UnpinSlots(this);
    }
    this->pPrev->pNext = this->pNext;
    this->pNext->pPrev = this->pPrev;
    this->pPrev = (Scaleform::Render::TextMeshProvider *)-1i64;
    this->pNext = (Scaleform::Render::TextMeshProvider *)-1i64;
  }
  pBundle = this->pBundle;
  if ( pBundle )
  {
    Scaleform::Render::TextPrimitiveBundle::removeEntryFromLayers(pBundle, this->pBundleEntry);
    this->pBundle = 0i64;
    this->pBundleEntry = 0i64;
  }
  Scaleform::Render::TextMeshProvider::ClearEntries(this);
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy>::ClearAndRelease(&this->Entries.Data);
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy>::ClearAndRelease(&this->Layers.Data);
}

// File Line: 389
// RVA: 0x988080
Scaleform::Render::Fence *__fastcall Scaleform::Render::TextMeshProvider::GetLatestFence(
        Scaleform::Render::TextMeshProvider *this)
{
  Scaleform::Render::TextMeshProvider *v1; // rax
  __int64 v2; // rbx
  unsigned __int64 v3; // r12
  __int64 v4; // r13
  Scaleform::Render::Mesh *pObject; // r15
  unsigned __int64 v6; // rbp
  unsigned __int64 Size; // rax
  $A76DB6A170CD9B60995E6D918C60C3B5 *v8; // rsi
  $A76DB6A170CD9B60995E6D918C60C3B5 *pData; // rcx
  $A76DB6A170CD9B60995E6D918C60C3B5 *v10; // rcx
  __int64 v11; // r8
  $A76DB6A170CD9B60995E6D918C60C3B5 *v12; // r14
  __int64 v13; // r14
  __int64 v14; // rax
  bool v15; // zf
  _QWORD *v16; // rcx
  __int64 v17; // rdi
  _QWORD *v18; // rcx
  _QWORD *v19; // rcx
  __int64 v20; // rdi
  _QWORD *v21; // rcx

  v1 = this;
  v2 = 0i64;
  v3 = 0i64;
  if ( this->Layers.Data.Size )
  {
    v4 = 0i64;
    do
    {
      pObject = v1->Layers.Data.Data[v4].pMesh.pObject;
      if ( pObject )
      {
        v6 = 0i64;
        Size = pObject->CacheItems.Size;
        if ( Size )
        {
          v8 = &pObject->CacheItems.8;
          do
          {
            if ( Size <= 2 )
              pData = &pObject->CacheItems.8;
            else
              pData = ($A76DB6A170CD9B60995E6D918C60C3B5 *)v8->AD.pData;
            if ( *(_QWORD *)(*((_QWORD *)&pData->AD.pData + v6) + 80i64) )
            {
              if ( !v2
                || (Size <= 2
                  ? (v10 = &pObject->CacheItems.8)
                  : (v10 = ($A76DB6A170CD9B60995E6D918C60C3B5 *)v8->AD.pData),
                    (v11 = **(_QWORD **)(*((_QWORD *)&v10->AD.pData + v6) + 80i64)) != 0
                 && (!*(_QWORD *)v2 || *(_QWORD *)(v11 + 24) > *(_QWORD *)(*(_QWORD *)v2 + 24i64))) )
              {
                if ( Size <= 2 )
                  v12 = &pObject->CacheItems.8;
                else
                  v12 = ($A76DB6A170CD9B60995E6D918C60C3B5 *)v8->AD.pData;
                v13 = *((_QWORD *)&v12->AD.pData + v6);
                v14 = *(_QWORD *)(v13 + 80);
                if ( v14 )
                  ++*(_WORD *)(v14 + 8);
                if ( v2 )
                {
                  v15 = (*(_WORD *)(v2 + 8))-- == 1;
                  if ( v15 )
                  {
                    v16 = *(_QWORD **)v2;
                    if ( *(_BYTE *)(v2 + 10) )
                    {
                      v17 = *v16;
                      (*(void (__fastcall **)(_QWORD *, _QWORD))(*v16 + 64i64))(v16, v16[2]);
                      v18 = *(_QWORD **)v2;
                      *v18 = *(_QWORD *)(v17 + 96);
                      *(_QWORD *)(v17 + 96) = v18;
                      *(_QWORD *)v2 = *(_QWORD *)(v17 + 136);
                      *(_QWORD *)(v17 + 136) = v2;
                    }
                    else
                    {
                      *(_QWORD *)v2 = v16[17];
                      v16[17] = v2;
                    }
                  }
                }
                v2 = *(_QWORD *)(v13 + 80);
              }
            }
            ++v6;
            Size = pObject->CacheItems.Size;
          }
          while ( v6 < Size );
        }
      }
      ++v3;
      ++v4;
      v1 = this;
    }
    while ( v3 < this->Layers.Data.Size );
  }
  if ( v2 )
  {
    v15 = (*(_WORD *)(v2 + 8))-- == 1;
    if ( v15 )
    {
      v19 = *(_QWORD **)v2;
      if ( *(_BYTE *)(v2 + 10) )
      {
        v20 = *v19;
        (*(void (__fastcall **)(_QWORD *, _QWORD))(*v19 + 64i64))(v19, v19[2]);
        v21 = *(_QWORD **)v2;
        *v21 = *(_QWORD *)(v20 + 96);
        *(_QWORD *)(v20 + 96) = v21;
        *(_QWORD *)v2 = *(_QWORD *)(v20 + 136);
        *(_QWORD *)(v20 + 136) = v2;
      }
      else
      {
        *(_QWORD *)v2 = v19[17];
        v19[17] = v2;
      }
    }
  }
  return (Scaleform::Render::Fence *)v2;
}

// File Line: 436
// RVA: 0x9545F0
void __fastcall Scaleform::Render::TextMeshProvider::AddNotifier(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TextNotifier *notifier)
{
  unsigned __int64 Size; // rax
  Scaleform::ArrayDH_POD<Scaleform::Render::TextNotifier *,2,Scaleform::ArrayDefaultPolicy> *p_Notifiers; // rbx
  unsigned __int64 v4; // rdi
  unsigned __int64 v6; // r8
  Scaleform::Render::TextNotifier **Data; // rax

  if ( notifier )
  {
    Size = this->Notifiers.Data.Size;
    p_Notifiers = &this->Notifiers;
    v4 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v4 > this->Notifiers.Data.Policy.Capacity )
      {
        v6 = v4 + (v4 >> 2);
        goto LABEL_7;
      }
    }
    else if ( v4 < this->Notifiers.Data.Policy.Capacity >> 1 )
    {
      v6 = Size + 1;
LABEL_7:
      Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Notifiers,
        this->Notifiers.Data.pHeap,
        v6);
    }
    Data = p_Notifiers->Data.Data;
    p_Notifiers->Data.Size = v4;
    Data[v4 - 1] = notifier;
    ++notifier->pSlot->PinCount;
  }
}

// File Line: 456
// RVA: 0x9BBC40
void __fastcall Scaleform::Render::TextMeshProvider::UnpinSlots(Scaleform::Render::TextMeshProvider *this)
{
  Scaleform::Render::Fence *LatestFence; // rax
  Scaleform::Render::Fence *v3; // rbx
  unsigned __int64 i; // rsi
  Scaleform::Render::GlyphSlot *pSlot; // rdi
  Scaleform::Render::FenceImpl *Data; // r8
  Scaleform::Render::Fence *pObject; // rax
  Scaleform::Render::FenceImpl *v8; // rax
  Scaleform::Render::Fence *v9; // rcx
  Scaleform::Render::FenceImpl *v11; // rcx
  Scaleform::Render::RenderSync *RSContext; // rdi
  Scaleform::Render::FenceImpl *v13; // rcx

  LatestFence = Scaleform::Render::TextMeshProvider::GetLatestFence(this);
  v3 = LatestFence;
  if ( LatestFence )
    ++LatestFence->RefCount;
  for ( i = 0i64; i < this->Notifiers.Data.Size; ++i )
  {
    pSlot = this->Notifiers.Data.Data[i]->pSlot;
    if ( v3 )
    {
      if ( v3->HasData )
      {
        Data = v3->Data;
        if ( v3->Data )
        {
          if ( Data->Parent )
          {
            if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::RenderSync *, __int64, unsigned __int64))Data->RSContext->vfptr[4].__vecDelDtor)(
                   Data->RSContext,
                   1i64,
                   Data->APIHandle) )
            {
              pObject = pSlot->SlotFence.pObject;
              if ( !pObject || v3->Data && ((v8 = pObject->Data) == 0i64 || v3->Data->FenceID > v8->FenceID) )
              {
                ++v3->RefCount;
                v9 = pSlot->SlotFence.pObject;
                if ( v9 )
                  Scaleform::Render::Fence::Release(v9);
                pSlot->SlotFence.pObject = v3;
              }
            }
          }
        }
      }
    }
    --pSlot->PinCount;
  }
  if ( v3 )
  {
    if ( v3->RefCount-- == 1 )
    {
      v11 = v3->Data;
      if ( v3->HasData )
      {
        RSContext = v11->RSContext;
        ((void (__fastcall *)(Scaleform::Render::FenceImpl *, unsigned __int64))v11->RSContext->FenceFrameAlloc.pHeapOrPtr)(
          v11,
          v11->APIHandle);
        v13 = v3->Data;
        v13->RSContext = (Scaleform::Render::RenderSync *)RSContext->FenceImplAlloc.FirstEmptySlot;
        RSContext->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v13;
        v3->Data = (Scaleform::Render::FenceImpl *)RSContext->FenceAlloc.FirstEmptySlot;
        RSContext->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)v3;
      }
      else
      {
        v3->Data = (Scaleform::Render::FenceImpl *)v11[4].Parent;
        v11[4].Parent = (Scaleform::Render::FenceFrame *)v3;
      }
    }
  }
}

// File Line: 470
// RVA: 0x989640
__int64 __fastcall Scaleform::Render::TextMeshProvider::GetMeshUseStatus(Scaleform::Render::TextMeshProvider *this)
{
  Scaleform::Render::MeshUseStatus v1; // esi
  unsigned __int64 i; // rdi
  Scaleform::Render::TextMeshLayer *v5; // rax
  Scaleform::Render::Mesh *pObject; // rcx
  Scaleform::Render::MeshUseStatus UseStatus; // eax

  v1 = MUS_Uncached;
  if ( this->PinCount )
    return 5i64;
  for ( i = 0i64; i < this->vfptr->GetLayerCount(this); ++i )
  {
    v5 = &this->Layers.Data.Data[(unsigned __int64)(unsigned int)i];
    if ( v5->Type > TextLayer_RasterText )
      break;
    if ( v5->Type >= TextLayer_Shadow )
    {
      pObject = v5->pMesh.pObject;
      if ( pObject )
      {
        UseStatus = Scaleform::Render::Mesh::GetUseStatus(pObject);
        if ( UseStatus > v1 )
          v1 = UseStatus;
      }
    }
  }
  return (unsigned int)v1;
}

// File Line: 493
// RVA: 0x9F0ED0
void __fastcall Scaleform::Render::TextMeshProvider::setMeshData(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TessBase *tess,
        Scaleform::Render::VertexOutput *verOut,
        const unsigned int *colors,
        Scaleform::Render::TextMeshProvider::VertexCountType *verCount)
{
  unsigned int i; // edi
  char *v9; // r10
  unsigned __int16 *v10; // r8
  __int64 v11; // r11
  __m128 v12; // xmm1
  int v13; // ecx
  __m128 v14; // xmm2
  int v15; // ecx
  unsigned __int64 v16; // r9
  unsigned int v17; // edi
  unsigned int v18; // esi
  unsigned int v19; // ebx
  char v20[32]; // [rsp+30h] [rbp-9D8h] BYREF
  char v21[384]; // [rsp+50h] [rbp-9B8h] BYREF
  char v22[4]; // [rsp+1D0h] [rbp-838h] BYREF
  char v23; // [rsp+1D4h] [rbp-834h] BYREF
  char v24[4]; // [rsp+4D0h] [rbp-538h] BYREF
  char v25; // [rsp+4D4h] [rbp-534h] BYREF

  tess->vfptr->GetMesh(tess, 0, (Scaleform::Render::TessMesh *)v20);
  for ( i = tess->vfptr->GetVertices(
              tess,
              (Scaleform::Render::TessMesh *)v20,
              (Scaleform::Render::TessVertex *)v24,
              64u);
        i;
        i = tess->vfptr->GetVertices(
              tess,
              (Scaleform::Render::TessMesh *)v20,
              (Scaleform::Render::TessVertex *)v24,
              64u) )
  {
    v9 = &v23;
    v10 = (unsigned __int16 *)&v25;
    v11 = i;
    do
    {
      v12 = (__m128)*((unsigned int *)v10 - 1);
      if ( v12.m128_f32[0] >= 0.0 )
        v12.m128_f32[0] = v12.m128_f32[0] + 0.5;
      else
        v12.m128_f32[0] = v12.m128_f32[0] - 0.5;
      v13 = (int)v12.m128_f32[0];
      if ( (int)v12.m128_f32[0] != 0x80000000 && (float)v13 != v12.m128_f32[0] )
        v12.m128_f32[0] = (float)(v13 - (_mm_movemask_ps(_mm_unpacklo_ps(v12, v12)) & 1));
      v14 = (__m128)*(unsigned int *)v10;
      *((_WORD *)v9 - 2) = (int)v12.m128_f32[0];
      if ( v14.m128_f32[0] >= 0.0 )
        v14.m128_f32[0] = v14.m128_f32[0] + 0.5;
      else
        v14.m128_f32[0] = v14.m128_f32[0] - 0.5;
      v15 = (int)v14.m128_f32[0];
      if ( (int)v14.m128_f32[0] != 0x80000000 && (float)v15 != v14.m128_f32[0] )
        v14.m128_f32[0] = (float)(v15 - (_mm_movemask_ps(_mm_unpacklo_ps(v14, v14)) & 1));
      v16 = v10[6];
      *((_WORD *)v9 - 1) = (int)v14.m128_f32[0];
      if ( (v16 & 0x10) != 0 )
        *(_DWORD *)v9 = ((colors[v10[4] - 1] | colors[v10[5] - 1]) >> 1) & 0x7F7F7F7F;
      else
        *(_DWORD *)v9 = colors[v10[((v16 >> 5) & 1) + 4] - 1];
      v9 += 12;
      v10 += 10;
      *(v9 - 8) = Scaleform::Render::Factors[v16 & 3];
      *(v9 - 7) = Scaleform::Render::Factors[((unsigned __int64)(unsigned __int16)v16 >> 2) & 3];
      --v11;
    }
    while ( v11 );
    verOut->vfptr->SetVertices(verOut, 0, verCount->VStart, v22, i);
    verCount->VStart += i;
  }
  v17 = 0;
  v18 = tess->vfptr->GetMeshTriangleCount(tess, 0);
  if ( v18 )
  {
    do
    {
      v19 = 64;
      if ( v17 + 64 > v18 )
      {
        v19 = v18 - v17;
        if ( v18 == v17 )
          break;
      }
      tess->vfptr->GetTrianglesI16(tess, 0, (unsigned __int16 *)v21, v17, v19);
      verOut->vfptr->SetIndices(verOut, 0, 3 * verCount->IStart, (unsigned __int16 *)v21, 3 * v19);
      verCount->IStart += v19;
      v17 += v19;
    }
    while ( v17 < v18 );
  }
}

// File Line: 553
// RVA: 0x9E5930
__int64 __fastcall Scaleform::Render::TextMeshProvider::generateSelection(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::Renderer2DImpl *ren,
        Scaleform::Render::VertexOutput *verOut,
        Scaleform::Render::TextMeshLayer *layer)
{
  Scaleform::Render::MeshGenerator *p_MeshGen; // rdi
  Scaleform::Render::Tessellator *p_mTess; // r14
  float Epsilon; // xmm0_4
  float v11; // xmm0_4
  unsigned int v12; // r13d
  __int64 v13; // rax
  __int64 v14; // rbx
  Scaleform::Render::TextMeshEntry *Data; // r15
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm9_4
  float y2; // xmm2_4
  float x2; // xmm1_4
  float y1; // xmm3_4
  float x1; // xmm0_4
  Scaleform::Render::VertexOutput *v24; // rbx
  unsigned __int8 NullVectorMesh; // r15
  unsigned __int64 MaxPages; // rax
  Scaleform::Render::LinearHeap::PageType *v27; // rbx
  unsigned __int64 v28; // rax
  Scaleform::Render::LinearHeap::PageType *v29; // rbx
  unsigned __int64 v30; // rax
  Scaleform::Render::LinearHeap::PageType *v31; // rbx
  unsigned __int64 v32; // rax
  Scaleform::Render::LinearHeap::PageType *v33; // rbx
  BOOL verCount; // [rsp+20h] [rbp-A8h]
  int v36[2]; // [rsp+30h] [rbp-98h] BYREF
  Scaleform::Render::VertexFormat *v37; // [rsp+38h] [rbp-90h]
  __int64 v38; // [rsp+40h] [rbp-88h]
  Scaleform::ArrayStaticBuffPOD<unsigned long,16,2> v39; // [rsp+48h] [rbp-80h] BYREF
  Scaleform::Render::ToleranceParams Tolerances; // [rsp+A8h] [rbp-20h]
  char v41[152]; // [rsp+F8h] [rbp+30h] BYREF
  Scaleform::Render::TextMeshProvider::VertexCountType v42; // [rsp+1A0h] [rbp+D8h] BYREF
  Scaleform::Render::VertexOutput *verOuta; // [rsp+1A8h] [rbp+E0h]
  Scaleform::Render::Matrix2x4<float> *m; // [rsp+1B8h] [rbp+F0h]
  int vars0; // [rsp+1C0h] [rbp+F8h]

  *(_QWORD *)&v39.Static[4] = -2i64;
  p_MeshGen = &ren->MeshGen;
  v42 = (Scaleform::Render::TextMeshProvider::VertexCountType)&ren->MeshGen;
  Scaleform::Render::MeshGenerator::Clear(&ren->MeshGen);
  p_mTess = &p_MeshGen->mTess;
  p_MeshGen->mTess.FillRule = FillNonZero;
  p_MeshGen->mTess.StrokerMode = 0;
  Epsilon = ren->Tolerances.Epsilon;
  p_MeshGen->mTess.Epsilon = Epsilon;
  p_MeshGen->mTess.HasEpsilon = Epsilon > 0.0;
  p_MeshGen->mTess.IntersectionEpsilon = ren->Tolerances.IntersectionEpsilon;
  v39.pHeap = Scaleform::Memory::pGlobalHeap;
  v39.Size = 0i64;
  v39.Reserved = 16i64;
  v39.Data = v39.Static;
  Tolerances = ren->Tolerances;
  if ( (vars0 & 1) == 0 || (vars0 & 2) != 0 )
    v11 = 0.0;
  else
    v11 = Tolerances.EdgeAAScale * 0.5;
  p_MeshGen->mTess.EdgeAAWidth = v11;
  p_MeshGen->mTess.EdgeAAFlag = v11 > 0.0;
  v12 = 0;
  if ( layer->Count )
  {
    do
    {
      v13 = v12 + layer->Start;
      v14 = v13;
      Data = this->Entries.Data.Data;
      v16 = Data[v13].EntryData.RasterData.Coord[3];
      v17 = Data[v13].EntryData.RasterData.Coord[2];
      v18 = Data[v13].EntryData.RasterData.Coord[1];
      v19 = Data[v13].EntryData.RasterData.Coord[0];
      if ( (this->Flags & 8) != 0 )
      {
        y2 = this->ClipBox.y2;
        x2 = this->ClipBox.x2;
        y1 = this->ClipBox.y1;
        x1 = this->ClipBox.x1;
      }
      else
      {
        y2 = this->Bounds.y2;
        x2 = this->Bounds.x2;
        y1 = this->Bounds.y1;
        x1 = this->Bounds.x1;
      }
      if ( v16 >= y1 && y2 >= v18 && x2 >= v19 && v17 >= x1 )
      {
        if ( v19 <= x1 )
          v19 = x1;
        if ( v17 > x2 )
          v17 = x2;
        if ( v18 <= y1 )
          v18 = y1;
        if ( v16 > y2 )
          v16 = y2;
        if ( v19 < v17 && v18 < v16 )
        {
          ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(p_mTess);
          ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(p_mTess);
          ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(p_mTess);
          ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(p_mTess);
        }
      }
      Scaleform::ArrayStaticBuffPOD<unsigned int,16,2>::PushBack(&v39, &Data[v14].mColor);
      p_mTess->vfptr->ClosePath(p_mTess);
      ++v12;
      LOBYTE(verCount) = 0;
      p_mTess->vfptr->FinalizePath(p_mTess, 0, v12, 0, verCount);
    }
    while ( v12 < layer->Count );
    p_MeshGen = (Scaleform::Render::MeshGenerator *)v42;
    verOut = verOuta;
  }
  Scaleform::Render::Tessellator::Tessellate(p_mTess, 0);
  if ( p_mTess->vfptr->GetMeshCount(p_mTess) && p_mTess->vfptr->GetVertexCount(p_mTess) )
  {
    *(_OWORD *)&v39.Size = _xmm;
    *(__m128 *)v39.Static = _xmm;
    Scaleform::Render::Matrix2x4<float>::SetInverse((Scaleform::Render::Matrix2x4<float> *)&v39.Size, m);
    p_mTess->vfptr->Transform(p_mTess, (Scaleform::Render::Matrix2x4<float> *)&v39.Size);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *, char *))p_mTess->vfptr->StretchTo)(p_mTess, v41);
    v36[0] = p_mTess->vfptr->GetMeshVertexCount(p_mTess, 0);
    v36[1] = 3
           * ((__int64 (__fastcall *)(Scaleform::Render::Tessellator *, _QWORD))p_mTess->vfptr->GetMeshTriangleCount)(
               p_mTess,
               0i64);
    v37 = &Scaleform::Render::VertexXY16iCF32::Format;
    v38 = 0i64;
    v39.pHeap = 0i64;
    v24 = verOuta;
    NullVectorMesh = verOuta->vfptr->BeginOutput(
                       verOuta,
                       (Scaleform::Render::VertexOutput::Fill *)v36,
                       1u,
                       (Scaleform::Render::Matrix2x4<float> *)v41);
    if ( NullVectorMesh )
    {
      v42 = 0i64;
      Scaleform::Render::TextMeshProvider::setMeshData(this, p_mTess, v24, v39.Data, &v42);
      v24->vfptr->EndOutput(v24);
    }
  }
  else
  {
    NullVectorMesh = Scaleform::Render::VectorGlyphShape::generateNullVectorMesh(
                       (Scaleform::Render::VectorGlyphShape *)this,
                       verOut);
  }
  (*((void (__fastcall **)(Scaleform::Render::Tessellator *))&p_mTess->vfptr->__vecDelDtor + 1))(p_mTess);
  (*((void (__fastcall **)(Scaleform::Render::Stroker *))&p_MeshGen->mStroker.vfptr->__vecDelDtor + 1))(&p_MeshGen->mStroker);
  (*((void (__fastcall **)(Scaleform::Render::StrokeSorter *))&p_MeshGen->mStrokeSorter.vfptr->__vecDelDtor + 1))(&p_MeshGen->mStrokeSorter);
  (*((void (__fastcall **)(Scaleform::Render::Hairliner *))&p_MeshGen->mHairliner.vfptr->__vecDelDtor + 1))(&p_MeshGen->mHairliner);
  (*((void (__fastcall **)(Scaleform::Render::StrokerAA *))&p_MeshGen->mStrokerAA.vfptr->__vecDelDtor + 1))(&p_MeshGen->mStrokerAA);
  MaxPages = p_MeshGen->Heap1.MaxPages;
  if ( MaxPages )
  {
    v27 = &p_MeshGen->Heap1.pPagePool[MaxPages - 1];
    do
    {
      --p_MeshGen->Heap1.MaxPages;
      if ( v27->pStart )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap1.pHeap->vfptr->Free)(p_MeshGen->Heap1.pHeap);
      --v27;
    }
    while ( p_MeshGen->Heap1.MaxPages );
    --p_MeshGen->Heap1.MaxPages;
    p_MeshGen->Heap1.pHeap->vfptr->Free(p_MeshGen->Heap1.pHeap, p_MeshGen->Heap1.pPagePool);
  }
  p_MeshGen->Heap1.pLastPage = 0i64;
  p_MeshGen->Heap1.pPagePool = 0i64;
  p_MeshGen->Heap1.MaxPages = 0i64;
  v28 = p_MeshGen->Heap2.MaxPages;
  if ( v28 )
  {
    v29 = &p_MeshGen->Heap2.pPagePool[v28 - 1];
    do
    {
      --p_MeshGen->Heap2.MaxPages;
      if ( v29->pStart )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap2.pHeap->vfptr->Free)(p_MeshGen->Heap2.pHeap);
      --v29;
    }
    while ( p_MeshGen->Heap2.MaxPages );
    --p_MeshGen->Heap2.MaxPages;
    p_MeshGen->Heap2.pHeap->vfptr->Free(p_MeshGen->Heap2.pHeap, p_MeshGen->Heap2.pPagePool);
  }
  p_MeshGen->Heap2.pLastPage = 0i64;
  p_MeshGen->Heap2.pPagePool = 0i64;
  p_MeshGen->Heap2.MaxPages = 0i64;
  v30 = p_MeshGen->Heap3.MaxPages;
  if ( v30 )
  {
    v31 = &p_MeshGen->Heap3.pPagePool[v30 - 1];
    do
    {
      --p_MeshGen->Heap3.MaxPages;
      if ( v31->pStart )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap3.pHeap->vfptr->Free)(p_MeshGen->Heap3.pHeap);
      --v31;
    }
    while ( p_MeshGen->Heap3.MaxPages );
    --p_MeshGen->Heap3.MaxPages;
    p_MeshGen->Heap3.pHeap->vfptr->Free(p_MeshGen->Heap3.pHeap, p_MeshGen->Heap3.pPagePool);
  }
  p_MeshGen->Heap3.pLastPage = 0i64;
  p_MeshGen->Heap3.pPagePool = 0i64;
  p_MeshGen->Heap3.MaxPages = 0i64;
  v32 = p_MeshGen->Heap4.MaxPages;
  if ( v32 )
  {
    v33 = &p_MeshGen->Heap4.pPagePool[v32 - 1];
    do
    {
      --p_MeshGen->Heap4.MaxPages;
      if ( v33->pStart )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap4.pHeap->vfptr->Free)(p_MeshGen->Heap4.pHeap);
      --v33;
    }
    while ( p_MeshGen->Heap4.MaxPages );
    --p_MeshGen->Heap4.MaxPages;
    p_MeshGen->Heap4.pHeap->vfptr->Free(p_MeshGen->Heap4.pHeap, p_MeshGen->Heap4.pPagePool);
  }
  p_MeshGen->Heap4.pLastPage = 0i64;
  p_MeshGen->Heap4.pPagePool = 0i64;
  p_MeshGen->Heap4.MaxPages = 0i64;
  if ( v39.Data != v39.Static )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return NullVectorMesh;
}

// File Line: 629
// RVA: 0x938040
void __fastcall Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(
        Scaleform::Render::CornerVertex v0,
        Scaleform::Render::CornerVertex v1,
        Scaleform::Render::CornerVertex v2,
        float width,
        float *x,
        float *y)
{
  __m128 y_low; // xmm9
  __m128 v8; // xmm13
  float v9; // xmm14_4
  __m128 v10; // xmm0
  float v11; // xmm6_4
  float v12; // xmm8_4
  float v13; // xmm3_4
  __m128 v14; // xmm0
  float v15; // xmm2_4

  y_low = (__m128)LODWORD(v2.y);
  y_low.m128_f32[0] = v2.y - v1.y;
  v8 = (__m128)LODWORD(v1.y);
  v9 = v1.x;
  v8.m128_f32[0] = v1.y - v0.y;
  *x = v1.x;
  *y = v1.y;
  v10 = v8;
  v10.m128_f32[0] = v8.m128_f32[0] * v8.m128_f32[0];
  v11 = (float)(v1.x - v2.x) * width;
  v8.m128_f32[0] = (float)(v1.y - v0.y) * width;
  v12 = (float)(v0.x - v1.x) * width;
  v10.m128_f32[0] = v10.m128_f32[0] + (float)((float)(v9 - v0.x) * (float)(v9 - v0.x));
  v13 = _mm_sqrt_ps(v10).m128_f32[0];
  v14 = y_low;
  v14.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)((float)(v2.x - v9) * (float)(v2.x - v9));
  v15 = _mm_sqrt_ps(v14).m128_f32[0];
  Scaleform::Render::Math2D::Intersection(
    v0.x + (float)(v8.m128_f32[0] * (float)(1.0 / v13)),
    (float)(v12 * (float)(1.0 / v13)) + v0.y,
    v1.x + (float)(v8.m128_f32[0] * (float)(1.0 / v13)),
    (float)(v12 * (float)(1.0 / v13)) + v1.y,
    (float)((float)((float)(v2.y - v1.y) * width) * (float)(1.0 / v15)) + v1.x,
    (float)(v11 * (float)(1.0 / v15)) + v1.y,
    v2.x + (float)((float)((float)(v2.y - v1.y) * width) * (float)(1.0 / v15)),
    (float)(v11 * (float)(1.0 / v15)) + v2.y,
    x,
    y,
    0.001);
}

// File Line: 650
// RVA: 0x9E52F0
char __fastcall Scaleform::Render::TextMeshProvider::generateRectangle(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::Renderer2DImpl *ren,
        Scaleform::Render::VertexOutput *verOut,
        Scaleform::Render::Matrix2x4<float> *mtx)
{
  int v4; // r14d
  Scaleform::Render::MeshGenerator *p_MeshGen; // r13
  Scaleform::Render::TextMeshProvider *v6; // rsi
  Scaleform::Render::Tessellator *p_mTess; // r15
  float Epsilon; // xmm0_4
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  __int128 v14; // xmm1
  float v15; // xmm0_4
  bool v16; // zf
  float v17; // xmm1_4
  float v18; // xmm10_4
  float v19; // xmm5_4
  float v20; // xmm2_4
  float v21; // xmm7_4
  float v22; // xmm3_4
  float v23; // xmm6_4
  float v24; // xmm11_4
  float v25; // xmm12_4
  float v26; // xmm13_4
  float v27; // xmm14_4
  float v28; // xmm15_4
  float v29; // xmm9_4
  float v30; // xmm10_4
  unsigned int v31; // xmm6_4
  unsigned int v32; // eax
  bool v34; // bl
  unsigned int colors[2]; // [rsp+40h] [rbp-88h] BYREF
  __m128 v36; // [rsp+48h] [rbp-80h] BYREF
  __int128 v37; // [rsp+58h] [rbp-70h]
  Scaleform::Render::Matrix2x4<float> v38; // [rsp+68h] [rbp-60h] BYREF
  __int128 v39; // [rsp+88h] [rbp-40h]
  __int64 v40; // [rsp+98h] [rbp-30h]
  unsigned int CurveRecursionLimit; // [rsp+A0h] [rbp-28h]
  char v42[248]; // [rsp+A8h] [rbp-20h] BYREF
  Scaleform::Render::TextMeshProvider *v43; // [rsp+1A8h] [rbp+E0h]
  Scaleform::Render::CornerVertex v1; // [rsp+1B0h] [rbp+E8h]
  Scaleform::Render::TextMeshProvider::VertexCountType verCount; // [rsp+1C0h] [rbp+F8h] BYREF
  Scaleform::Render::CornerVertex v2; // [rsp+1C8h] [rbp+100h]
  float y; // [rsp+1D0h] [rbp+108h] BYREF
  void *x; // [rsp+1D8h] [rbp+110h] BYREF
  char v49; // [rsp+1E0h] [rbp+118h]

  v49 = (char)this;
  v4 = (int)x;
  p_MeshGen = &ren->MeshGen;
  v6 = this;
  colors[1] = (unsigned int)x;
  *(float *)colors = y;
  Scaleform::Render::MeshGenerator::Clear(&ren->MeshGen);
  p_mTess = &p_MeshGen->mTess;
  p_MeshGen->mTess.FillRule = FillNonZero;
  p_MeshGen->mTess.StrokerMode = 0;
  Epsilon = ren->Tolerances.Epsilon;
  p_MeshGen->mTess.Epsilon = Epsilon;
  p_MeshGen->mTess.HasEpsilon = Epsilon > 0.0;
  p_MeshGen->mTess.IntersectionEpsilon = ren->Tolerances.IntersectionEpsilon;
  v12 = *(_OWORD *)&ren->Tolerances.Epsilon;
  v13 = *(_OWORD *)&ren->Tolerances.FillLowerScale;
  CurveRecursionLimit = ren->Tolerances.CurveRecursionLimit;
  v37 = v12;
  *(_OWORD *)&v38.M[0][0] = v13;
  v14 = *(_OWORD *)&ren->Tolerances.Scale9LowerScale;
  *(_OWORD *)&v38.M[1][0] = *(_OWORD *)&ren->Tolerances.StrokeLowerScale;
  v39 = v14;
  v40 = *(_QWORD *)&ren->Tolerances.MinDet3D;
  if ( (v49 & 1) == 0 || (v49 & 2) != 0 )
    v15 = 0.0;
  else
    v15 = *((float *)&v39 + 2) * 0.5;
  p_MeshGen->mTess.EdgeAAWidth = v15;
  v16 = LODWORD(y) == 0;
  p_MeshGen->mTess.EdgeAAFlag = v15 > 0.0;
  v17 = *(float *)(*(_QWORD *)&v2 + 4i64);
  v18 = mtx->M[1][0];
  v19 = mtx->M[0][0] * **(float **)&v2;
  v20 = *(float *)(*(_QWORD *)&v2 + 8i64);
  v21 = *(float *)(*(_QWORD *)&v2 + 12i64);
  v22 = mtx->M[1][3];
  v23 = mtx->M[0][3];
  v24 = (float)(v19 + (float)(mtx->M[0][1] * v17)) + v23;
  v25 = (float)((float)(v18 * **(float **)&v2) + (float)(mtx->M[1][1] * v17)) + v22;
  v26 = (float)((float)(mtx->M[0][0] * v20) + (float)(mtx->M[0][1] * v17)) + v23;
  v27 = (float)((float)(v18 * v20) + (float)(mtx->M[1][1] * v17)) + v22;
  v28 = (float)((float)(mtx->M[0][0] * v20) + (float)(mtx->M[0][1] * v21)) + v23;
  v29 = (float)((float)(mtx->M[0][1] * v21) + v19) + v23;
  v30 = (float)((float)(v18 * **(float **)&v2) + (float)(mtx->M[1][1] * v21)) + v22;
  *(float *)&x = (float)((float)(mtx->M[1][0] * v20) + (float)(mtx->M[1][1] * v21)) + v22;
  if ( v16 )
  {
    v31 = (unsigned int)x;
  }
  else
  {
    ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(&p_MeshGen->mTess);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(&p_MeshGen->mTess);
    v31 = (unsigned int)x;
    ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(&p_MeshGen->mTess);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(&p_MeshGen->mTess);
    p_mTess->vfptr->ClosePath(&p_MeshGen->mTess);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *, _QWORD, __int64))p_mTess->vfptr->FinalizePath)(
      &p_MeshGen->mTess,
      0i64,
      1i64);
  }
  if ( v4 )
  {
    ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(&p_MeshGen->mTess);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(&p_MeshGen->mTess);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(&p_MeshGen->mTess);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(&p_MeshGen->mTess);
    p_mTess->vfptr->ClosePath(&p_MeshGen->mTess);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *, _QWORD, __int64))p_mTess->vfptr->FinalizePath)(
      &p_MeshGen->mTess,
      0i64,
      2i64);
    v1 = (Scaleform::Render::CornerVertex)__PAIR64__(LODWORD(v25), LODWORD(v24));
    v2 = (Scaleform::Render::CornerVertex)__PAIR64__(LODWORD(v30), LODWORD(v29));
    Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(
      (Scaleform::Render::CornerVertex)__PAIR64__(LODWORD(v27), LODWORD(v26)),
      (Scaleform::Render::CornerVertex)__PAIR64__(LODWORD(v25), LODWORD(v24)),
      (Scaleform::Render::CornerVertex)__PAIR64__(LODWORD(v30), LODWORD(v29)),
      1.0,
      (float *)&x,
      &y);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(&p_MeshGen->mTess);
    Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(
      (Scaleform::Render::CornerVertex)__PAIR64__(LODWORD(v25), LODWORD(v24)),
      (Scaleform::Render::CornerVertex)__PAIR64__(LODWORD(v30), LODWORD(v29)),
      (Scaleform::Render::CornerVertex)__PAIR64__(v31, LODWORD(v28)),
      1.0,
      (float *)&x,
      &y);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(&p_MeshGen->mTess);
    Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(
      (Scaleform::Render::CornerVertex)__PAIR64__(LODWORD(v30), LODWORD(v29)),
      (Scaleform::Render::CornerVertex)__PAIR64__(v31, LODWORD(v28)),
      (Scaleform::Render::CornerVertex)__PAIR64__(LODWORD(v27), LODWORD(v26)),
      1.0,
      (float *)&x,
      &y);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(&p_MeshGen->mTess);
    Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(
      (Scaleform::Render::CornerVertex)__PAIR64__(v31, LODWORD(v28)),
      (Scaleform::Render::CornerVertex)__PAIR64__(LODWORD(v27), LODWORD(v26)),
      (Scaleform::Render::CornerVertex)__PAIR64__(LODWORD(v25), LODWORD(v24)),
      1.0,
      (float *)&x,
      &y);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(&p_MeshGen->mTess);
    p_mTess->vfptr->ClosePath(&p_MeshGen->mTess);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *, _QWORD, __int64))p_mTess->vfptr->FinalizePath)(
      &p_MeshGen->mTess,
      0i64,
      2i64);
    mtx = (Scaleform::Render::Matrix2x4<float> *)verCount;
    v6 = v43;
  }
  Scaleform::Render::Tessellator::Tessellate(&p_MeshGen->mTess, 0);
  *(_OWORD *)&v38.M[0][2] = _xmm;
  v36 = _xmm;
  Scaleform::Render::Matrix2x4<float>::SetInverse((Scaleform::Render::Matrix2x4<float> *)&v38.M[0][2], mtx);
  p_mTess->vfptr->Transform(&p_MeshGen->mTess, (Scaleform::Render::Matrix2x4<float> *)&v38.M[0][2]);
  ((void (__fastcall *)(Scaleform::Render::Tessellator *, char *))p_mTess->vfptr->StretchTo)(&p_MeshGen->mTess, v42);
  v36.m128_i32[0] = p_mTess->vfptr->GetMeshVertexCount(&p_MeshGen->mTess, 0);
  v32 = p_mTess->vfptr->GetMeshTriangleCount(&p_MeshGen->mTess, 0);
  v37 = 0ui64;
  v36.m128_u64[1] = (unsigned __int64)&Scaleform::Render::VertexXY16iCF32::Format;
  v36.m128_i32[1] = 3 * v32;
  if ( !v36.m128_i32[0] )
    return Scaleform::Render::VectorGlyphShape::generateNullVectorMesh(
             (Scaleform::Render::VectorGlyphShape *)v6,
             verOut);
  v34 = verOut->vfptr->BeginOutput(
          verOut,
          (Scaleform::Render::VertexOutput::Fill *)&v36,
          1u,
          (Scaleform::Render::Matrix2x4<float> *)v42);
  if ( v34 )
  {
    verCount = 0i64;
    Scaleform::Render::TextMeshProvider::setMeshData(v6, &p_MeshGen->mTess, verOut, colors, &verCount);
    verOut->vfptr->EndOutput(verOut);
  }
  Scaleform::Render::MeshGenerator::Clear(p_MeshGen);
  return v34;
}

// File Line: 731
// RVA: 0x9D5FC0
char __fastcall Scaleform::Render::TextMeshProvider::clipGlyphRect(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::Rect<float> *chr,
        Scaleform::Render::Rect<float> *tex)
{
  float y2; // xmm7_4
  float y1; // xmm0_4
  float x1; // xmm12_4
  float v6; // xmm2_4
  float v7; // xmm5_4
  float v8; // xmm13_4
  float x2; // xmm11_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm1_4
  float v13; // xmm6_4
  float v14; // xmm8_4
  float v15; // xmm6_4
  float v16; // xmm15_4
  float v17; // xmm14_4
  float v18; // xmm10_4
  float v19; // xmm9_4
  float v20; // xmm8_4
  float v22; // eax

  if ( (this->Flags & 8) == 0 )
    return 1;
  y2 = chr->y2;
  y1 = this->ClipBox.y1;
  x1 = chr->x1;
  v6 = y2;
  v7 = chr->x1;
  v8 = chr->y1;
  x2 = chr->x2;
  v10 = v8;
  v11 = x2;
  v12 = this->ClipBox.x1;
  v13 = this->ClipBox.x2;
  v14 = this->ClipBox.y2;
  if ( y2 >= y1 && v14 >= v8 && v13 >= v7 && x2 >= v12 )
  {
    if ( v7 <= v12 )
      v7 = this->ClipBox.x1;
    if ( x2 > v13 )
      v11 = this->ClipBox.x2;
    if ( v8 <= y1 )
      v10 = this->ClipBox.y1;
    if ( y2 > v14 )
      v6 = this->ClipBox.y2;
    if ( v7 < v11 && v10 < v6 )
    {
      if ( v7 != x1 || v11 != x2 || v10 != v8 || v6 != y2 )
      {
        v15 = tex->y2;
        v16 = tex->y1;
        v17 = tex->x1;
        v18 = tex->x2;
        v19 = v16;
        v20 = tex->x1;
        if ( x1 != v7 )
          v20 = (float)((float)((float)(v7 - x1) * (float)(v18 - v17)) / (float)(x2 - x1)) + v17;
        if ( v8 != v10 )
          v19 = (float)((float)((float)(v10 - v8) * (float)(v15 - v16)) / (float)(y2 - v8)) + v16;
        if ( x2 != v11 )
          v18 = v18 - (float)((float)((float)(x2 - v11) * (float)(v18 - v17)) / (float)(x2 - x1));
        if ( y2 != v6 )
          v15 = v15 - (float)((float)((float)(y2 - v6) * (float)(v15 - v16)) / (float)(y2 - v8));
        chr->x1 = v7;
        chr->y1 = v10;
        chr->x2 = v11;
        chr->y2 = v6;
        tex->y1 = v19;
        tex->x2 = v18;
        tex->x1 = v20;
        tex->y2 = v15;
      }
      return 1;
    }
  }
  chr->x1 = v12;
  v22 = chr->x1;
  chr->y1 = y1;
  chr->x2 = v22;
  chr->y2 = y1;
  tex->x2 = tex->x1;
  tex->y2 = tex->y1;
  return 0;
}

// File Line: 770
// RVA: 0x9E4EE0
char __fastcall Scaleform::Render::TextMeshProvider::generateRasterMesh(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::VertexOutput *verOut,
        Scaleform::Render::TextMeshLayer *layer)
{
  unsigned int Count; // ebx
  unsigned int v4; // r13d
  Scaleform::Render::TextMeshLayer *v6; // rsi
  Scaleform::Render::VectorGlyphShape *v7; // rdi
  Scaleform::Render::GlyphCache *pCache; // rax
  float ScaleU; // xmm6_4
  float ScaleV; // xmm7_4
  char result; // al
  int v12; // r15d
  unsigned int v13; // r12d
  unsigned int Start; // eax
  __int64 v15; // rbx
  __int64 v16; // rsi
  __int64 v17; // rcx
  Scaleform::Render::GlyphShape *pObject; // rax
  unsigned __int16 *v19; // rdx
  int v20; // edi
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  __m128i v24; // xmm0
  float v25; // xmm1_4
  float v26; // xmm2_4
  int y1_low; // xmm1_4
  int v28; // xmm2_4
  __int64 v29; // rcx
  __int64 v30; // rax
  int x1_low; // xmm4_4
  int v32; // xmm3_4
  int x2_low; // xmm1_4
  int y2_low; // xmm2_4
  __int64 v35; // rax
  __int64 v36; // rax
  __int64 v37; // rax
  Scaleform::Render::Rect<float> tex; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::Render::Rect<float> chr; // [rsp+40h] [rbp-C0h] BYREF
  unsigned int v40; // [rsp+50h] [rbp-B0h]
  int v41[2]; // [rsp+58h] [rbp-A8h] BYREF
  Scaleform::Render::VertexFormat *v42; // [rsp+60h] [rbp-A0h]
  __int64 v43; // [rsp+68h] [rbp-98h]
  __int64 v44; // [rsp+70h] [rbp-90h]
  __int16 v45[384]; // [rsp+80h] [rbp-80h] BYREF
  int v46[1280]; // [rsp+380h] [rbp+280h] BYREF
  unsigned int v48; // [rsp+17F8h] [rbp+16F8h]
  int v50; // [rsp+1808h] [rbp+1708h]

  Count = layer->Count;
  v4 = 0;
  v43 = 0i64;
  v44 = 0i64;
  v41[0] = 4 * Count;
  v6 = layer;
  v7 = (Scaleform::Render::VectorGlyphShape *)this;
  v41[1] = 6 * Count;
  v42 = &Scaleform::Render::RasterGlyphVertex::Format;
  pCache = this->pCache;
  v40 = Count;
  ScaleU = pCache->ScaleU;
  ScaleV = pCache->ScaleV;
  result = verOut->vfptr->BeginOutput(
             verOut,
             (Scaleform::Render::VertexOutput::Fill *)v41,
             1u,
             &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    v48 = 0;
    v12 = 0;
    v13 = 0;
    if ( Count )
    {
      v50 = 0;
      do
      {
        if ( v13 >= 0x40 )
        {
          verOut->vfptr->SetVertices(verOut, 0, 4 * v12, v46, 256u);
          verOut->vfptr->SetIndices(verOut, 0, v4, (unsigned __int16 *)v45, 384u);
          v13 = 0;
          v12 += 64;
          v4 += 384;
        }
        Start = v6->Start;
        v15 = 4 * v13;
        v16 = 6 * v13;
        v17 = 5i64 * (v48 + Start);
        pObject = v7->pShape.pObject;
        v19 = (unsigned __int16 *)*((_QWORD *)&pObject->Decoder.OneOverMultiplier + v17);
        v20 = HIDWORD((&pObject->vfptr)[v17]);
        v21 = *((float *)&pObject->pContainer + 2 * v17 + 1);
        chr.x1 = *((float *)&pObject->pContainer + 2 * v17);
        v22 = *((float *)&pObject->Decoder.Decoder.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data
              + 2 * v17);
        chr.y1 = v21;
        v23 = *((float *)&pObject->Decoder.Decoder.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data
              + 2 * v17
              + 1);
        chr.x2 = v22;
        LODWORD(pObject) = v19[24] + 1;
        chr.y2 = v23;
        v24 = _mm_cvtsi32_si128((unsigned int)v19[26] - 2);
        v25 = (float)(int)pObject * ScaleU;
        LODWORD(pObject) = v19[27];
        v26 = (float)(v19[25] + 1);
        tex.x1 = v25;
        tex.y1 = v26 * ScaleV;
        tex.x2 = (float)(_mm_cvtepi32_ps(v24).m128_f32[0] * ScaleU) + v25;
        tex.y2 = (float)((float)((int)pObject - 2) * ScaleV) + (float)(v26 * ScaleV);
        Scaleform::Render::TextMeshProvider::clipGlyphRect(this, &chr, &tex);
        y1_low = LODWORD(chr.y1);
        v28 = LODWORD(tex.y1);
        v29 = 5 * v15;
        v46[v29 + 2] = v20;
        v30 = 5i64 * (unsigned int)(v15 + 1);
        v24.m128i_i32[0] = LODWORD(chr.x2);
        x1_low = LODWORD(chr.x1);
        v32 = LODWORD(tex.x1);
        v46[v29 + 1] = y1_low;
        v46[v29 + 4] = v28;
        v46[v29] = x1_low;
        v46[v29 + 3] = v32;
        v46[v30 + 1] = y1_low;
        x2_low = LODWORD(tex.x2);
        v46[v30 + 2] = v20;
        v46[v30] = v24.m128i_i32[0];
        v46[v30 + 4] = v28;
        y2_low = LODWORD(chr.y2);
        v46[v30 + 3] = x2_low;
        v35 = 5i64 * (unsigned int)(v15 + 2);
        v46[v35] = v24.m128i_i32[0];
        v24.m128i_i32[0] = LODWORD(tex.y2);
        v46[v35 + 1] = y2_low;
        v46[v35 + 2] = v20;
        v46[v35 + 4] = v24.m128i_i32[0];
        v46[v35 + 3] = x2_low;
        v36 = 5i64 * (unsigned int)(v15 + 3);
        v46[v36] = x1_low;
        v46[v36 + 1] = y2_low;
        v46[v36 + 3] = v32;
        v46[v36 + 4] = v24.m128i_i32[0];
        v46[v36 + 2] = v20;
        v7 = (Scaleform::Render::VectorGlyphShape *)this;
        v45[v16] = v50;
        v45[(unsigned int)(v16 + 1)] = v50 + 1;
        v45[(unsigned int)(v16 + 2)] = v50 + 2;
        ++v13;
        v45[(unsigned int)(v16 + 3)] = v50 + 2;
        v45[(unsigned int)(v16 + 4)] = v50 + 3;
        v37 = (unsigned int)(v16 + 5);
        v6 = layer;
        v45[v37] = v50;
        v50 += 4;
        ++v48;
      }
      while ( v48 < v40 );
      if ( v13 )
      {
        verOut->vfptr->SetVertices(verOut, 0, 4 * v12, v46, 4 * v13);
        verOut->vfptr->SetIndices(verOut, 0, 6 * v12, (unsigned __int16 *)v45, 6 * v13);
        verOut->vfptr->EndOutput(verOut);
        return 1;
      }
      v7 = (Scaleform::Render::VectorGlyphShape *)this;
    }
    return Scaleform::Render::VectorGlyphShape::generateNullVectorMesh(v7, verOut);
  }
  return result;
}

// File Line: 844
// RVA: 0x9E4A00
bool __fastcall Scaleform::Render::TextMeshProvider::generatePackedMesh(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::VertexOutput *verOut,
        Scaleform::Render::TextMeshLayer *layer)
{
  unsigned int Count; // r14d
  Scaleform::Render::TextMeshProvider *v4; // r12
  unsigned int v5; // esi
  __int64 Start; // rax
  Scaleform::Render::GlyphNode *pGlyph; // rcx
  int v9; // eax
  Scaleform::Render::VertexOutput::Fill *v10; // rdx
  bool v11; // r13
  bool result; // al
  int v13; // r15d
  unsigned int v14; // ebx
  int v15; // r14d
  unsigned int v16; // r12d
  int *v17; // r9
  __int64 v18; // r13
  __int64 v19; // rdx
  Scaleform::Render::TextMeshEntry *Data; // rcx
  __int64 v21; // rsi
  float *v22; // rax
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  int x1_low; // xmm4_4
  int y1_low; // xmm1_4
  int v32; // xmm3_4
  int v33; // xmm2_4
  int x2_low; // xmm0_4
  int v35; // edx
  __int64 v36; // rax
  __int64 v37; // rcx
  int v38; // xmm1_4
  int y2_low; // xmm2_4
  __int64 v40; // rax
  int v41; // xmm0_4
  __int64 v42; // rax
  __int64 v43; // rcx
  __int64 v44; // rax
  int v45; // xmm1_4
  int v46; // xmm2_4
  __int64 v47; // rcx
  int v48; // xmm0_4
  __int64 v49; // rcx
  __int64 v50; // rax
  int *v51; // r9
  Scaleform::Render::Rect<float> tex; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::Render::Rect<float> chr; // [rsp+40h] [rbp-C0h] BYREF
  unsigned int v54; // [rsp+50h] [rbp-B0h]
  int mColor; // [rsp+54h] [rbp-ACh]
  int v56[2]; // [rsp+58h] [rbp-A8h] BYREF
  Scaleform::Render::VertexFormat *v57; // [rsp+60h] [rbp-A0h]
  __int64 v58; // [rsp+68h] [rbp-98h]
  __int64 v59; // [rsp+70h] [rbp-90h]
  int v60[2]; // [rsp+78h] [rbp-88h] BYREF
  Scaleform::Render::VertexFormat *v61; // [rsp+80h] [rbp-80h]
  __int64 v62; // [rsp+88h] [rbp-78h]
  __int64 v63; // [rsp+90h] [rbp-70h]
  __int16 v64[384]; // [rsp+A0h] [rbp-60h] BYREF
  int v65[1024]; // [rsp+3A0h] [rbp+2A0h] BYREF
  int v66[1282]; // [rsp+13A0h] [rbp+12A0h] BYREF
  bool v68; // [rsp+27F8h] [rbp+26F8h]
  unsigned int v70; // [rsp+2808h] [rbp+2708h]

  Count = layer->Count;
  v4 = this;
  v5 = 0;
  v58 = 0i64;
  v59 = 0i64;
  v62 = 0i64;
  v63 = 0i64;
  v56[0] = 4 * Count;
  v60[0] = 4 * Count;
  v56[1] = 6 * Count;
  v60[1] = 6 * Count;
  v61 = &Scaleform::Render::ImageGlyphVertex::Format;
  Start = layer->Start;
  v57 = &Scaleform::Render::RasterGlyphVertex::Format;
  pGlyph = this->Entries.Data.Data[Start].EntryData.RasterData.pGlyph;
  v54 = Count;
  v9 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&pGlyph->Param.BlurY + 32i64))(*(_QWORD *)&pGlyph->Param.BlurY);
  v10 = (Scaleform::Render::VertexOutput::Fill *)v56;
  v11 = v9 == 9;
  v68 = v9 == 9;
  if ( v9 != 9 )
    v10 = (Scaleform::Render::VertexOutput::Fill *)v60;
  result = verOut->vfptr->BeginOutput(verOut, v10, 1u, &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    v70 = 0;
    v13 = 0;
    v14 = 0;
    if ( Count )
    {
      v15 = 0;
      v16 = 0;
      while ( 1 )
      {
        if ( v14 >= 0x40 )
        {
          v17 = v66;
          if ( !v11 )
            v17 = v65;
          verOut->vfptr->SetVertices(verOut, 0, 4 * v13, v17, 256u);
          verOut->vfptr->SetIndices(verOut, 0, v16, (unsigned __int16 *)v64, 384u);
          v14 = 0;
          v13 += 64;
          v16 += 384;
        }
        v18 = 4 * v14;
        v19 = v5 + layer->Start;
        Data = this->Entries.Data.Data;
        v21 = 6 * v14;
        v22 = (float *)Data[v19].EntryData.RasterData.pGlyph;
        v23 = v22[9];
        tex.x1 = v22[8];
        v24 = v22[10];
        tex.y1 = v23;
        v25 = v22[11];
        tex.x2 = v24;
        v26 = Data[v19].EntryData.RasterData.Coord[0];
        mColor = Data[v19].mColor;
        tex.y2 = v25;
        v27 = Data[v19].EntryData.RasterData.Coord[1];
        chr.x1 = v26;
        v28 = Data[v19].EntryData.RasterData.Coord[2];
        chr.y1 = v27;
        v29 = Data[v19].EntryData.RasterData.Coord[3];
        chr.x2 = v28;
        chr.y2 = v29;
        Scaleform::Render::TextMeshProvider::clipGlyphRect(this, &chr, &tex);
        x1_low = LODWORD(chr.x1);
        y1_low = LODWORD(chr.y1);
        v32 = LODWORD(tex.x1);
        v33 = LODWORD(tex.y1);
        x2_low = LODWORD(chr.x2);
        if ( v68 )
        {
          v35 = mColor;
          v36 = 5i64 * (unsigned int)(v18 + 1);
          v37 = 5 * v18;
          v66[v37 + 2] = mColor;
          v66[v37 + 1] = y1_low;
          v66[v37 + 4] = v33;
          v66[v37] = x1_low;
          v66[v37 + 3] = v32;
          v66[v36 + 1] = y1_low;
          v38 = LODWORD(tex.x2);
          v66[v36 + 2] = v35;
          v66[v36] = x2_low;
          v66[v36 + 4] = v33;
          y2_low = LODWORD(chr.y2);
          v66[v36 + 3] = v38;
          v40 = 5i64 * (unsigned int)(v18 + 2);
          v66[v40] = x2_low;
          v41 = LODWORD(tex.y2);
          v66[v40 + 1] = y2_low;
          v66[v40 + 2] = v35;
          v66[v40 + 4] = v41;
          v66[v40 + 3] = v38;
          v42 = 5i64 * (unsigned int)(v18 + 3);
          v66[v42] = x1_low;
          v66[v42 + 1] = y2_low;
          v66[v42 + 3] = v32;
          v66[v42 + 2] = v35;
          v66[v42 + 4] = v41;
        }
        else
        {
          v43 = 2i64 * (unsigned int)(v18 + 1);
          v44 = 2i64 * (unsigned int)v18;
          v65[2 * v44 + 1] = LODWORD(chr.y1);
          v65[2 * v44 + 3] = v33;
          v65[2 * v44] = x1_low;
          v65[2 * v44 + 2] = v32;
          v65[2 * v43 + 1] = y1_low;
          v45 = LODWORD(tex.x2);
          v65[2 * v43] = x2_low;
          v65[2 * v43 + 3] = v33;
          v46 = LODWORD(chr.y2);
          v65[2 * v43 + 2] = v45;
          v47 = 2i64 * (unsigned int)(v18 + 2);
          v65[2 * v47] = x2_low;
          v48 = LODWORD(tex.y2);
          v65[2 * v47 + 1] = v46;
          v65[2 * v47 + 3] = v48;
          v65[2 * v47 + 2] = v45;
          v49 = 2i64 * (unsigned int)(v18 + 3);
          v65[2 * v49] = x1_low;
          v65[2 * v49 + 1] = v46;
          v65[2 * v49 + 2] = v32;
          v65[2 * v49 + 3] = v48;
        }
        v64[v21] = v15;
        v64[(unsigned int)(v21 + 1)] = v15 + 1;
        v64[(unsigned int)(v21 + 2)] = v15 + 2;
        ++v14;
        v64[(unsigned int)(v21 + 3)] = v15 + 2;
        v64[(unsigned int)(v21 + 4)] = v15 + 3;
        v50 = (unsigned int)(v21 + 5);
        v5 = v70 + 1;
        v64[v50] = v15;
        v15 += 4;
        v70 = v5;
        if ( v5 >= v54 )
          break;
        v11 = v68;
      }
      if ( v14 )
      {
        v51 = v66;
        if ( !v68 )
          v51 = v65;
        verOut->vfptr->SetVertices(verOut, 0, 4 * v13, v51, 4 * v14);
        verOut->vfptr->SetIndices(verOut, 0, 6 * v13, (unsigned __int16 *)v64, 6 * v14);
        goto LABEL_21;
      }
      v4 = this;
    }
    Scaleform::Render::VectorGlyphShape::generateNullVectorMesh((Scaleform::Render::VectorGlyphShape *)v4, verOut);
LABEL_21:
    verOut->vfptr->EndOutput(verOut);
    return 1;
  }
  return result;
}

// File Line: 924
// RVA: 0x9E4510
__int64 __fastcall Scaleform::Render::TextMeshProvider::generateImageMesh(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::VertexOutput *verOut,
        Scaleform::Render::TextMeshLayer *layer)
{
  Scaleform::Render::TextMeshEntry *Data; // rbx
  __int64 Start; // rax
  __int64 v6; // rdi
  float v8; // xmm8_4
  float v9; // xmm6_4
  float v10; // xmm3_4
  int v11; // xmm1_4
  Scaleform::Render::VertexOutputVtbl *vfptr; // rax
  __int64 result; // rax
  int v14[4]; // [rsp+30h] [rbp-B8h] BYREF
  char tex[24]; // [rsp+40h] [rbp-A8h] BYREF
  float v16; // [rsp+58h] [rbp-90h]
  int v17; // [rsp+5Ch] [rbp-8Ch]
  float v18; // [rsp+60h] [rbp-88h] BYREF
  float v19; // [rsp+64h] [rbp-84h]
  __int64 v20; // [rsp+68h] [rbp-80h] BYREF
  __int64 v21; // [rsp+70h] [rbp-78h]
  float v22; // [rsp+78h] [rbp-70h]
  float v23; // [rsp+7Ch] [rbp-6Ch]
  int v24; // [rsp+80h] [rbp-68h]
  int v25; // [rsp+84h] [rbp-64h]
  float v26; // [rsp+88h] [rbp-60h]
  int v27; // [rsp+8Ch] [rbp-5Ch]
  int v28; // [rsp+90h] [rbp-58h]
  __int64 v29; // [rsp+94h] [rbp-54h]
  int v30; // [rsp+9Ch] [rbp-4Ch]
  int v31; // [rsp+A0h] [rbp-48h]
  int v32; // [rsp+A4h] [rbp-44h]
  int v33[2]; // [rsp+A8h] [rbp-40h] BYREF
  Scaleform::Render::VertexFormat *v34; // [rsp+B0h] [rbp-38h]
  __int64 v35; // [rsp+B8h] [rbp-30h]
  __int64 v36; // [rsp+C0h] [rbp-28h]

  v14[0] = 0x10000;
  Data = this->Entries.Data.Data;
  v14[1] = 2;
  v14[2] = 196610;
  v33[0] = 4;
  v33[1] = 6;
  v35 = 0i64;
  v36 = 0i64;
  v34 = &Scaleform::Render::ImageGlyphVertex::Format;
  Start = layer->Start;
  v6 = Start;
  ((void (__fastcall *)(Scaleform::Render::GlyphNode *, float *, Scaleform::Render::TextureManager *))Data[Start].EntryData.RasterData.pGlyph->Param.pFont[5].pFont)(
    Data[Start].EntryData.RasterData.pGlyph,
    &v18,
    this->pCache->pTexMan);
  v8 = Data[v6].EntryData.RasterData.Coord[2] - Data[v6].EntryData.RasterData.Coord[0];
  v9 = Data[v6].EntryData.RasterData.Coord[3] - Data[v6].EntryData.RasterData.Coord[1];
  v10 = (float)((float)((float)(*(float *)&v21 + *((float *)&v21 + 1)) * 0.0) + v23)
      + Data[v6].EntryData.RasterData.Coord[1];
  *(float *)&tex[16] = (float)((float)((float)(v18 + v19) * 0.0) + *((float *)&v20 + 1))
                     + Data[v6].EntryData.RasterData.Coord[0];
  v16 = (float)((float)((float)(v18 * v8) + (float)(v19 * v9)) + *((float *)&v20 + 1))
      + Data[v6].EntryData.RasterData.Coord[0];
  *(float *)&v11 = (float)((float)((float)(*(float *)&v21 * v8) + (float)(*((float *)&v21 + 1) * v9)) + v23)
                 + Data[v6].EntryData.RasterData.Coord[1];
  *(float *)&tex[20] = v10;
  v17 = v11;
  *(float *)&tex[8] = (float)(v18 + v19) + *((float *)&v20 + 1);
  *(float *)tex = (float)((float)(v18 + v19) * 0.0) + *((float *)&v20 + 1);
  *(float *)&tex[4] = (float)((float)(*(float *)&v21 + *((float *)&v21 + 1)) * 0.0) + v23;
  *(float *)&tex[12] = (float)(*(float *)&v21 + *((float *)&v21 + 1)) + v23;
  Scaleform::Render::TextMeshProvider::clipGlyphRect(
    this,
    (Scaleform::Render::Rect<float> *)&tex[16],
    (Scaleform::Render::Rect<float> *)tex);
  v20 = *(_QWORD *)&tex[16];
  v21 = *(_QWORD *)tex;
  vfptr = verOut->vfptr;
  v22 = v16;
  v25 = *(_DWORD *)&tex[4];
  v26 = v16;
  v23 = *(float *)&tex[20];
  v27 = v17;
  v29 = *(_QWORD *)&tex[12];
  v30 = v17;
  v32 = *(_DWORD *)&tex[12];
  v24 = *(_DWORD *)&tex[8];
  v28 = *(_DWORD *)&tex[8];
  v31 = *(_DWORD *)tex;
  result = ((__int64 (__fastcall *)(Scaleform::Render::VertexOutput *, int *, __int64, Scaleform::Render::Matrix2x4<float> *))vfptr->BeginOutput)(
             verOut,
             v33,
             1i64,
             &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( (_BYTE)result )
  {
    verOut->vfptr->SetVertices(verOut, 0, 0, &v20, 4u);
    verOut->vfptr->SetIndices(verOut, 0, 0, (unsigned __int16 *)v14, 6u);
    verOut->vfptr->EndOutput(verOut);
    return 1i64;
  }
  return result;
}

// File Line: 969
// RVA: 0x9E6360
char __fastcall Scaleform::Render::TextMeshProvider::generateUnderlines(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::Renderer2DImpl *ren,
        Scaleform::Render::VertexOutput *verOut,
        Scaleform::Render::TextMeshLayer *layer)
{
  Scaleform::Render::MeshGenerator *p_MeshGen; // rdi
  bool v8; // al
  Scaleform::Render::StrokerAA *p_mStrokerAA; // rbx
  unsigned int v10; // r15d
  char v11; // r12
  __int64 v12; // rsi
  Scaleform::Render::TextMeshEntry *Data; // r14
  int v14; // eax
  __m128 v15; // xmm7
  float v16; // xmm4_4
  __m128 v17; // xmm6
  __m128 v18; // xmm9
  int v19; // ecx
  int v20; // ecx
  float i; // xmm12_4
  unsigned int Style; // edx
  int v23; // ecx
  int v24; // ecx
  float v25; // xmm9_4
  float v26; // xmm11_4
  unsigned __int64 MaxPages; // rax
  Scaleform::Render::LinearHeap::PageType *v28; // rbx
  unsigned __int64 v29; // rax
  Scaleform::Render::LinearHeap::PageType *v30; // rbx
  unsigned __int64 v31; // rax
  Scaleform::Render::LinearHeap::PageType *v32; // rbx
  unsigned __int64 v33; // rax
  Scaleform::Render::LinearHeap::PageType *v34; // rbx
  BOOL verCount; // [rsp+20h] [rbp-A8h]
  int v37[2]; // [rsp+30h] [rbp-98h] BYREF
  Scaleform::Render::VertexFormat *v38; // [rsp+38h] [rbp-90h]
  __int64 v39; // [rsp+40h] [rbp-88h]
  __int64 v40; // [rsp+48h] [rbp-80h]
  Scaleform::Render::Matrix2x4<float> v41; // [rsp+50h] [rbp-78h] BYREF
  Scaleform::ArrayStaticBuffPOD<unsigned long,16,2> v42; // [rsp+70h] [rbp-58h] BYREF
  Scaleform::Render::TextMeshProvider *v43; // [rsp+1A8h] [rbp+E0h]
  Scaleform::Render::TextMeshProvider::VertexCountType v44; // [rsp+1B0h] [rbp+E8h] BYREF
  Scaleform::Render::VertexOutput *v45; // [rsp+1B8h] [rbp+F0h]
  Scaleform::Render::Matrix2x4<float> *m; // [rsp+1C8h] [rbp+100h]
  int vars0; // [rsp+1D0h] [rbp+108h]

  *(_QWORD *)&v42.Static[4] = -2i64;
  v42.pHeap = Scaleform::Memory::pGlobalHeap;
  v42.Size = 0i64;
  v40 = 16i64;
  *(_QWORD *)&v42.Static[2] = v42.Static;
  p_MeshGen = &ren->MeshGen;
  Scaleform::Render::MeshGenerator::Clear(&ren->MeshGen);
  v8 = (vars0 & 1) != 0 && (vars0 & 2) == 0;
  LOBYTE(vars0) = v8;
  p_mStrokerAA = &p_MeshGen->mStrokerAA;
  *(_QWORD *)&p_MeshGen->mStrokerAA.StartLineCap = 0i64;
  p_MeshGen->mStrokerAA.LineJoin = MiterJoin;
  if ( v8 )
  {
    *(_QWORD *)&p_MeshGen->mStrokerAA.WidthLeft = 0i64;
    p_MeshGen->mStrokerAA.AaWidthRight = 0.95999998;
    p_MeshGen->mStrokerAA.AaWidthLeft = 0.95999998;
  }
  else
  {
    p_MeshGen->mStrokerAA.WidthRight = 0.5;
    p_MeshGen->mStrokerAA.WidthLeft = 0.5;
    *(_QWORD *)&p_MeshGen->mStrokerAA.AaWidthLeft = 0i64;
  }
  v10 = 0;
  if ( layer->Count )
  {
    v11 = vars0;
    do
    {
      v12 = v10 + layer->Start;
      Data = this->Entries.Data.Data;
      v14 = Data[v10 + layer->Start].EntryData.UnderlineData.Style - 1;
      if ( v11 )
      {
        if ( (v14 & 0xFFFFFFFD) != 0 )
        {
          *(_QWORD *)&p_MeshGen->mStrokerAA.WidthLeft = 0i64;
        }
        else
        {
          p_MeshGen->mStrokerAA.WidthRight = 1.0;
          p_MeshGen->mStrokerAA.WidthLeft = 1.0;
        }
        if ( Data[v12].EntryData.UnderlineData.Style == 5 )
        {
          p_MeshGen->mStrokerAA.WidthRight = 0.25;
          p_MeshGen->mStrokerAA.WidthLeft = 0.25;
        }
        if ( Data[v12].EntryData.UnderlineData.Style == 4 )
        {
          p_MeshGen->mStrokerAA.AaWidthRight = 0.5;
          p_MeshGen->mStrokerAA.AaWidthLeft = 0.5;
        }
        else
        {
          p_MeshGen->mStrokerAA.AaWidthRight = 0.95999998;
          p_MeshGen->mStrokerAA.AaWidthLeft = 0.95999998;
        }
      }
      else
      {
        if ( (v14 & 0xFFFFFFFD) != 0 )
        {
          p_MeshGen->mStrokerAA.WidthRight = 0.5;
          p_MeshGen->mStrokerAA.WidthLeft = 0.5;
        }
        else
        {
          p_MeshGen->mStrokerAA.WidthRight = 1.0;
          p_MeshGen->mStrokerAA.WidthLeft = 1.0;
        }
        if ( Data[v12].EntryData.UnderlineData.Style == 5 )
        {
          p_MeshGen->mStrokerAA.WidthRight = 0.75;
          p_MeshGen->mStrokerAA.WidthLeft = 0.75;
        }
        *(_QWORD *)&p_MeshGen->mStrokerAA.AaWidthLeft = 0i64;
      }
      p_MeshGen->mStrokerAA.StyleLeft = ++v10;
      p_MeshGen->mStrokerAA.StyleRight = v10;
      Scaleform::ArrayStaticBuffPOD<unsigned int,16,2>::PushBack(&v42, &Data[v12].mColor);
      v15 = (__m128)LODWORD(Data[v12].EntryData.RasterData.Coord[1]);
      v16 = Data[v12].EntryData.RasterData.Coord[2] * m->M[0][1];
      v17 = v15;
      v17.m128_f32[0] = (float)((float)(v15.m128_f32[0] * m->M[0][0]) + v16) + m->M[0][3];
      v15.m128_f32[0] = v15.m128_f32[0] + Data[v12].EntryData.RasterData.Coord[3];
      v18 = v15;
      v18.m128_f32[0] = (float)((float)(v15.m128_f32[0] * m->M[0][0]) + v16) + m->M[0][3];
      if ( Data[v12].EntryData.UnderlineData.Style <= 1 )
      {
        ((void (__fastcall *)(Scaleform::Render::StrokerAA *))p_mStrokerAA->vfptr->AddVertex)(&p_MeshGen->mStrokerAA);
        ((void (__fastcall *)(Scaleform::Render::StrokerAA *))p_mStrokerAA->vfptr->AddVertex)(&p_MeshGen->mStrokerAA);
        LOBYTE(verCount) = 0;
        p_mStrokerAA->vfptr->FinalizePath(&p_MeshGen->mStrokerAA, 0, 0, 0, verCount);
      }
      if ( Data[v12].EntryData.UnderlineData.Style - 2 <= 1 )
      {
        v19 = (int)v17.m128_f32[0];
        if ( (int)v17.m128_f32[0] != 0x80000000 && (float)v19 != v17.m128_f32[0] )
          v17 = (__m128)COERCE_UNSIGNED_INT((float)(v19 - (_mm_movemask_ps(_mm_unpacklo_ps(v17, v17)) & 1)));
        v17.m128_f32[0] = v17.m128_f32[0] - 0.5;
        v20 = (int)v18.m128_f32[0];
        if ( (int)v18.m128_f32[0] != 0x80000000 && (float)v20 != v18.m128_f32[0] )
          v18 = (__m128)COERCE_UNSIGNED_INT((float)(v20 - (_mm_movemask_ps(_mm_unpacklo_ps(v18, v18)) & 1)));
        v18.m128_f32[0] = v18.m128_f32[0] + 0.5;
        for ( i = v17.m128_f32[0]; i <= v18.m128_f32[0]; i = i + 5.0 )
        {
          ((void (__fastcall *)(Scaleform::Render::StrokerAA *))p_mStrokerAA->vfptr->AddVertex)(&p_MeshGen->mStrokerAA);
          ((void (__fastcall *)(Scaleform::Render::StrokerAA *))p_mStrokerAA->vfptr->AddVertex)(&p_MeshGen->mStrokerAA);
          LOBYTE(verCount) = 0;
          p_mStrokerAA->vfptr->FinalizePath(&p_MeshGen->mStrokerAA, 0, 0, 0, verCount);
        }
      }
      Style = Data[v12].EntryData.UnderlineData.Style;
      if ( Style - 4 <= 1 )
      {
        v23 = (int)v17.m128_f32[0];
        if ( (int)v17.m128_f32[0] != 0x80000000 && (float)v23 != v17.m128_f32[0] )
          v17.m128_f32[0] = (float)(v23 - (_mm_movemask_ps(_mm_unpacklo_ps(v17, v17)) & 1));
        v24 = (int)v18.m128_f32[0];
        if ( (int)v18.m128_f32[0] != 0x80000000 && (float)v24 != v18.m128_f32[0] )
          v18.m128_f32[0] = (float)(v24 - (_mm_movemask_ps(_mm_unpacklo_ps(v18, v18)) & 1));
        v25 = v18.m128_f32[0] + 1.0;
        v26 = FLOAT_4_0;
        if ( Style == 5 )
          v26 = FLOAT_6_0;
        for ( ; v17.m128_f32[0] <= v25; v17.m128_f32[0] = v17.m128_f32[0] + v26 )
        {
          ((void (__fastcall *)(Scaleform::Render::StrokerAA *))p_mStrokerAA->vfptr->AddVertex)(&p_MeshGen->mStrokerAA);
          ((void (__fastcall *)(Scaleform::Render::StrokerAA *))p_mStrokerAA->vfptr->AddVertex)(&p_MeshGen->mStrokerAA);
        }
        LOBYTE(verCount) = 0;
        p_mStrokerAA->vfptr->FinalizePath(&p_MeshGen->mStrokerAA, 0, 0, 0, verCount);
      }
      this = v43;
    }
    while ( v10 < layer->Count );
    verOut = v45;
  }
  if ( p_mStrokerAA->vfptr->GetVertexCount(&p_MeshGen->mStrokerAA) )
  {
    *(_OWORD *)&v41.M[0][0] = _xmm;
    *(__m128 *)&v41.M[1][0] = _xmm;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v41, m);
    p_mStrokerAA->vfptr->Transform(&p_MeshGen->mStrokerAA, &v41);
    ((void (__fastcall *)(Scaleform::Render::StrokerAA *, unsigned int *))p_mStrokerAA->vfptr->StretchTo)(
      &p_MeshGen->mStrokerAA,
      &v42.Static[8]);
    v37[0] = p_mStrokerAA->vfptr->GetMeshVertexCount(&p_MeshGen->mStrokerAA, 0);
    v37[1] = 3
           * ((__int64 (__fastcall *)(Scaleform::Render::StrokerAA *, _QWORD))p_mStrokerAA->vfptr->GetMeshTriangleCount)(
               &p_MeshGen->mStrokerAA,
               0i64);
    v38 = &Scaleform::Render::VertexXY16iCF32::Format;
    v39 = 0i64;
    v40 = 0i64;
    if ( verOut->vfptr->BeginOutput(
           verOut,
           (Scaleform::Render::VertexOutput::Fill *)v37,
           1u,
           (Scaleform::Render::Matrix2x4<float> *)&v42.Static[8]) )
    {
      v44 = 0i64;
      Scaleform::Render::TextMeshProvider::setMeshData(
        this,
        &p_MeshGen->mStrokerAA,
        verOut,
        *(const unsigned int **)&v42.Static[2],
        &v44);
      verOut->vfptr->EndOutput(verOut);
    }
  }
  else
  {
    Scaleform::Render::VectorGlyphShape::generateNullVectorMesh((Scaleform::Render::VectorGlyphShape *)this, verOut);
  }
  p_MeshGen->mStrokerAA.StyleLeft = 1;
  p_MeshGen->mStrokerAA.StyleRight = 1;
  (*((void (__fastcall **)(Scaleform::Render::Tessellator *))&p_MeshGen->mTess.vfptr->__vecDelDtor + 1))(&p_MeshGen->mTess);
  (*((void (__fastcall **)(Scaleform::Render::Stroker *))&p_MeshGen->mStroker.vfptr->__vecDelDtor + 1))(&p_MeshGen->mStroker);
  (*((void (__fastcall **)(Scaleform::Render::StrokeSorter *))&p_MeshGen->mStrokeSorter.vfptr->__vecDelDtor + 1))(&p_MeshGen->mStrokeSorter);
  (*((void (__fastcall **)(Scaleform::Render::Hairliner *))&p_MeshGen->mHairliner.vfptr->__vecDelDtor + 1))(&p_MeshGen->mHairliner);
  (*((void (__fastcall **)(Scaleform::Render::StrokerAA *))&p_mStrokerAA->vfptr->__vecDelDtor + 1))(&p_MeshGen->mStrokerAA);
  MaxPages = p_MeshGen->Heap1.MaxPages;
  if ( MaxPages )
  {
    v28 = &p_MeshGen->Heap1.pPagePool[MaxPages - 1];
    do
    {
      --p_MeshGen->Heap1.MaxPages;
      if ( v28->pStart )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap1.pHeap->vfptr->Free)(p_MeshGen->Heap1.pHeap);
      --v28;
    }
    while ( p_MeshGen->Heap1.MaxPages );
    --p_MeshGen->Heap1.MaxPages;
    p_MeshGen->Heap1.pHeap->vfptr->Free(p_MeshGen->Heap1.pHeap, p_MeshGen->Heap1.pPagePool);
  }
  p_MeshGen->Heap1.pLastPage = 0i64;
  p_MeshGen->Heap1.pPagePool = 0i64;
  p_MeshGen->Heap1.MaxPages = 0i64;
  v29 = p_MeshGen->Heap2.MaxPages;
  if ( v29 )
  {
    v30 = &p_MeshGen->Heap2.pPagePool[v29 - 1];
    do
    {
      --p_MeshGen->Heap2.MaxPages;
      if ( v30->pStart )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap2.pHeap->vfptr->Free)(p_MeshGen->Heap2.pHeap);
      --v30;
    }
    while ( p_MeshGen->Heap2.MaxPages );
    --p_MeshGen->Heap2.MaxPages;
    p_MeshGen->Heap2.pHeap->vfptr->Free(p_MeshGen->Heap2.pHeap, p_MeshGen->Heap2.pPagePool);
  }
  p_MeshGen->Heap2.pLastPage = 0i64;
  p_MeshGen->Heap2.pPagePool = 0i64;
  p_MeshGen->Heap2.MaxPages = 0i64;
  v31 = p_MeshGen->Heap3.MaxPages;
  if ( v31 )
  {
    v32 = &p_MeshGen->Heap3.pPagePool[v31 - 1];
    do
    {
      --p_MeshGen->Heap3.MaxPages;
      if ( v32->pStart )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap3.pHeap->vfptr->Free)(p_MeshGen->Heap3.pHeap);
      --v32;
    }
    while ( p_MeshGen->Heap3.MaxPages );
    --p_MeshGen->Heap3.MaxPages;
    p_MeshGen->Heap3.pHeap->vfptr->Free(p_MeshGen->Heap3.pHeap, p_MeshGen->Heap3.pPagePool);
  }
  p_MeshGen->Heap3.pLastPage = 0i64;
  p_MeshGen->Heap3.pPagePool = 0i64;
  p_MeshGen->Heap3.MaxPages = 0i64;
  v33 = p_MeshGen->Heap4.MaxPages;
  if ( v33 )
  {
    v34 = &p_MeshGen->Heap4.pPagePool[v33 - 1];
    do
    {
      --p_MeshGen->Heap4.MaxPages;
      if ( v34->pStart )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap4.pHeap->vfptr->Free)(p_MeshGen->Heap4.pHeap);
      --v34;
    }
    while ( p_MeshGen->Heap4.MaxPages );
    --p_MeshGen->Heap4.MaxPages;
    p_MeshGen->Heap4.pHeap->vfptr->Free(p_MeshGen->Heap4.pHeap, p_MeshGen->Heap4.pPagePool);
  }
  p_MeshGen->Heap4.pLastPage = 0i64;
  p_MeshGen->Heap4.pPagePool = 0i64;
  p_MeshGen->Heap4.MaxPages = 0i64;
  if ( *(Scaleform::Render::Matrix2x4<float> **)&v42.Static[2] != &v41 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return 1;
}age = 0i64;
  p_MeshGen->Heap4.pPagePool = 0i64;
  p_Me

// File Line: 1110
// RVA: 0x9BE7A0
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::TextMeshProvider::UpdateMaskClearBounds(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result,
        Scaleform::Render::MatrixPoolImpl::HMatrix viewMat)
{
  float y2; // xmm5_4
  float x2; // xmm4_4
  float y1; // xmm3_4
  float x1; // xmm2_4
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // r15
  int v11; // eax
  __int64 v12; // rcx
  float v13; // eax
  float v14; // edx
  float v15; // r8d
  float v16; // r9d
  unsigned int v17; // r10d
  unsigned int v18; // r11d
  unsigned int v19; // ebx
  unsigned int v20; // edi
  unsigned int v21; // esi
  unsigned int v22; // r14d
  unsigned int v23; // r15d
  unsigned int v24; // ecx
  __m128 v25; // xmm10
  __m128 v26; // xmm8
  Scaleform::Render::MatrixPoolImpl::HMatrix *p_ClearBounds; // rdi
  Scaleform::Render::MatrixPoolImpl::HMatrix *v28; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v29; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  bool v31; // zf
  __int64 DataPageOffset; // rcx
  __m128 v33; // xmm7
  __m128 v34; // xmm8
  Scaleform::Render::MatrixPoolImpl::HMatrix *v35; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v36; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v37; // rbx
  Scaleform::Render::MatrixPoolImpl::EntryHandle v38; // rbx
  __int64 v39; // rcx
  float src[4]; // [rsp+30h] [rbp-98h] BYREF
  __m256i v42; // [rsp+40h] [rbp-88h] BYREF
  Scaleform::Render::Matrix3x4<float> m[2]; // [rsp+60h] [rbp-68h] BYREF
  Scaleform::Render::MatrixPoolImpl::HMatrix resulta; // [rsp+118h] [rbp+50h] BYREF
  Scaleform::Render::MatrixPoolImpl::HMatrix *v45; // [rsp+120h] [rbp+58h]
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v46; // [rsp+128h] [rbp+60h]

  *(_OWORD *)&m[0].M[0][0] = _xmm;
  *(__m128 *)&m[0].M[1][0] = _xmm;
  y2 = this->ClearBox.y2;
  x2 = this->ClearBox.x2;
  y1 = this->ClearBox.y1;
  x1 = this->ClearBox.x1;
  *(_QWORD *)src = 0i64;
  *(_QWORD *)&src[2] = 1065353216i64;
  v42.m256i_i64[0] = 0x3F8000003F800000i64;
  v42.m256i_i64[3] = __PAIR64__(LODWORD(y1), LODWORD(x1));
  *(_QWORD *)&m[0].M[0][0] = __PAIR64__(LODWORD(y1), LODWORD(x2));
  *(_QWORD *)&m[0].M[0][2] = __PAIR64__(LODWORD(y2), LODWORD(x2));
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(
    (Scaleform::Render::Matrix2x4<float> *)m,
    src,
    (float *)&v42.m256i_i32[6]);
  pHandle = viewMat.pHandle->pHeader->pHandle;
  resulta.pHandle = pHandle;
  v11 = 2
      * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[HIBYTE(pHandle[1].pNext) & 0xF].Offsets[4];
  v12 = v11 * 8;
  if ( (HIBYTE(pHandle[1].pNext) & 0x10) == 0 )
  {
    v33 = _mm_and_ps(
            *(__m128 *)&pHandle[v11 + 4].pHeader,
            (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
    v34 = _mm_add_ps(
            _mm_mul_ps(
              *(__m128 *)&m[0].M[1][0],
              _mm_shuffle_ps(*(__m128 *)&pHandle[v11 + 4].pHeader, *(__m128 *)&pHandle[v11 + 4].pHeader, 85)),
            _mm_mul_ps(
              *(__m128 *)&m[0].M[0][0],
              _mm_shuffle_ps(*(__m128 *)&pHandle[v11 + 4].pHeader, *(__m128 *)&pHandle[v11 + 4].pHeader, 0)));
    *(__m128 *)&m[0].M[0][0] = _mm_and_ps(
                                 (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v,
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       *(__m128 *)&m[0].M[1][0],
                                       _mm_shuffle_ps(
                                         *(__m128 *)&pHandle[v11 + 2].pHeader,
                                         *(__m128 *)&pHandle[v11 + 2].pHeader,
                                         85)),
                                     _mm_mul_ps(
                                       *(__m128 *)&m[0].M[0][0],
                                       _mm_shuffle_ps(
                                         *(__m128 *)&pHandle[v11 + 2].pHeader,
                                         *(__m128 *)&pHandle[v11 + 2].pHeader,
                                         0))),
                                   _mm_and_ps(
                                     *(__m128 *)&pHandle[v11 + 2].pHeader,
                                     (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)));
    *(__m128 *)&m[0].M[1][0] = _mm_and_ps(
                                 (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v,
                                 _mm_add_ps(v34, v33));
    p_ClearBounds = &this->ClearBounds;
    if ( this->ClearBounds.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(p_ClearBounds, (Scaleform::Render::Matrix2x4<float> *)m);
      goto LABEL_12;
    }
    v35 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
            &this->pRenderer->MPool,
            &resulta,
            (Scaleform::Render::Matrix2x4<float> *)m,
            0);
    Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(p_ClearBounds, v35);
    v29 = resulta.pHandle;
    if ( resulta.pHandle == &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      goto LABEL_12;
    goto LABEL_4;
  }
  v13 = *(float *)&pHandle[v11 + 2].pHeader;
  v14 = *(float *)((char *)&pHandle[2].pNext + v12 + 4);
  v15 = *(float *)((char *)&pHandle[3].pHeader + v12);
  v16 = *(float *)((char *)&pHandle[3].pNext + v12 + 4);
  v17 = *(_DWORD *)((char *)&pHandle[4].pHeader + v12);
  v18 = *(_DWORD *)((char *)&pHandle[4].pNext + v12 + 4);
  v19 = *(_DWORD *)((char *)&pHandle[5].pHeader + v12);
  v20 = *(_DWORD *)((char *)&pHandle[5].pNext + v12 + 4);
  v21 = *(_DWORD *)((char *)&pHandle[6].pHeader + v12);
  v22 = *(_DWORD *)((char *)&pHandle[6].pNext + v12 + 4);
  v23 = *(_DWORD *)((char *)&pHandle[7].pHeader + v12);
  v24 = *(_DWORD *)((char *)&resulta.pHandle[7].pNext + v12 + 4);
  src[0] = v13;
  src[1] = v14;
  src[2] = v15;
  src[3] = v16;
  v42.m256i_i64[0] = __PAIR64__(v18, v17);
  v42.m256i_i64[1] = __PAIR64__(v20, v19);
  v42.m256i_i64[2] = __PAIR64__(v22, v21);
  v42.m256i_i64[3] = __PAIR64__(v24, v23);
  v25 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v42.m256i_i8, *(__m128 *)v42.m256i_i8, 0), *(__m128 *)&m[0].M[0][0]),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v42.m256i_i8, *(__m128 *)v42.m256i_i8, 85), *(__m128 *)&m[0].M[1][0])),
          _mm_and_ps(
            (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>::`2::v,
            *(__m128 *)v42.m256i_i8));
  v26 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(*(__m128 *)&v42.m256i_u64[2], *(__m128 *)&v42.m256i_u64[2], 0),
              *(__m128 *)&m[0].M[0][0]),
            _mm_mul_ps(
              _mm_shuffle_ps(*(__m128 *)&v42.m256i_u64[2], *(__m128 *)&v42.m256i_u64[2], 85),
              *(__m128 *)&m[0].M[1][0])),
          _mm_and_ps(
            (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>::`2::v,
            *(__m128 *)&v42.m256i_u64[2]));
  *(__m128 *)&m[0].M[0][0] = _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)src, *(__m128 *)src, 0), *(__m128 *)&m[0].M[0][0]),
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(*(__m128 *)src, *(__m128 *)src, 85),
                                   *(__m128 *)&m[0].M[1][0])),
                               _mm_and_ps(
                                 (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>::`2::v,
                                 *(__m128 *)src));
  *(__m128 *)&m[0].M[1][0] = v25;
  *(__m128 *)&v42.m256i_u64[1] = v26;
  p_ClearBounds = &this->ClearBounds;
  result = v45;
  if ( this->ClearBounds.pHandle == &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v28 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(&this->pRenderer->MPool, &resulta, m, 0x10u);
    Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(p_ClearBounds, v28);
    v29 = resulta.pHandle;
    if ( resulta.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
LABEL_4:
      pHeader = v29->pHeader;
      v31 = v29->pHeader->RefCount-- == 1;
      if ( v31 )
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
    Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix3D(p_ClearBounds, m);
  }
  viewMat.pHandle = v46;
LABEL_12:
  v36 = p_ClearBounds->pHandle;
  result->pHandle = p_ClearBounds->pHandle;
  if ( v36 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++v36->pHeader->RefCount;
  v37 = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)viewMat.pHandle->pHeader;
  if ( v37 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v38.pHeader = v37->pHeader;
    v31 = v38.pHeader->RefCount-- == 1;
    if ( v31 )
    {
      v39 = v38.pHeader->DataPageOffset;
      *(_WORD *)((char *)&v38.pHeader[1].RefCount + v39 + 2) += 16 * (unsigned __int8)v38.pHeader->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v38.pHeader[1].pHandle + v39))[5].pHeader += (unsigned __int8)v38.pHeader->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v38.pNext->pNext);
      v38.pHeader->pHandle = 0i64;
    }
  }
  return result;
}

// File Line: 1138
// RVA: 0x988C10
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::TextMeshProvider::GetMaskClearBounds(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax

  pHandle = this->ClearBounds.pHandle;
  result->pHandle = pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pHandle->pHeader->RefCount;
  return result;
}

// File Line: 1145
// RVA: 0x9E47D0
char __fastcall Scaleform::Render::TextMeshProvider::generateMask(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::VertexOutput *verOut,
        Scaleform::Render::TextMeshLayer *layer)
{
  __int64 Start; // r8
  Scaleform::Render::TextMeshEntry *Data; // rax
  int v6; // xmm3_4
  int v7; // xmm2_4
  float v8; // xmm0_4
  Scaleform::Render::VertexOutputVtbl *vfptr; // rax
  char result; // al
  float dst; // [rsp+30h] [rbp-19h] BYREF
  int v12; // [rsp+34h] [rbp-15h]
  int v13; // [rsp+38h] [rbp-11h]
  int v14; // [rsp+3Ch] [rbp-Dh]
  int v15; // [rsp+40h] [rbp-9h]
  float v16; // [rsp+44h] [rbp-5h]
  float src; // [rsp+48h] [rbp-1h] BYREF
  int v18; // [rsp+4Ch] [rbp+3h]
  int v19; // [rsp+50h] [rbp+7h]
  int v20; // [rsp+54h] [rbp+Bh]
  int v21; // [rsp+58h] [rbp+Fh]
  int v22; // [rsp+5Ch] [rbp+13h]
  int v23[2]; // [rsp+60h] [rbp+17h] BYREF
  Scaleform::Render::VertexFormat *v24; // [rsp+68h] [rbp+1Fh]
  __int64 v25; // [rsp+70h] [rbp+27h]
  __int64 v26; // [rsp+78h] [rbp+2Fh]
  Scaleform::Render::Matrix2x4<float> v27; // [rsp+80h] [rbp+37h] BYREF

  Start = layer->Start;
  Data = this->Entries.Data.Data;
  *(_OWORD *)&v27.M[0][0] = _xmm;
  *(__m128 *)&v27.M[1][0] = _xmm;
  v6 = LODWORD(Data[Start].EntryData.RasterData.Coord[2]);
  v7 = LODWORD(Data[Start].EntryData.RasterData.Coord[1]);
  src = -32764.0;
  v18 = -956303360;
  v19 = 1191180288;
  v20 = -956303360;
  v21 = 1191180288;
  v22 = 1191180288;
  v8 = Data[Start].EntryData.RasterData.Coord[0];
  v12 = v7;
  v13 = v6;
  dst = v8;
  v14 = v7;
  v15 = v6;
  v16 = Data[Start].EntryData.RasterData.Coord[3];
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v27, &src, &dst);
  v24 = &Scaleform::Render::VertexXY16i::Format;
  vfptr = verOut->vfptr;
  v25 = 0i64;
  v26 = 0i64;
  LODWORD(dst) = -2147188732;
  v12 = -2147188740;
  v13 = 2147254268;
  v14 = 2147254276;
  LODWORD(src) = 0x10000;
  v18 = 2;
  v19 = 196610;
  v23[0] = 4;
  v23[1] = 6;
  result = vfptr->BeginOutput(verOut, (Scaleform::Render::VertexOutput::Fill *)v23, 1u, &v27);
  if ( result )
  {
    verOut->vfptr->SetVertices(verOut, 0, 0, &dst, 4u);
    verOut->vfptr->SetIndices(verOut, 0, 0, (unsigned __int16 *)&src, 6u);
    verOut->vfptr->EndOutput(verOut);
    return 1;
  }
  return result;
}

// File Line: 1177
// RVA: 0x9E4950
char __fastcall Scaleform::Render::VectorGlyphShape::generateNullVectorMesh(
        Scaleform::Render::VectorGlyphShape *this,
        Scaleform::Render::VertexOutput *verOut)
{
  Scaleform::Render::VertexOutputVtbl *vfptr; // rax
  char result; // al
  __int64 v5; // [rsp+30h] [rbp-38h] BYREF
  __int16 v6; // [rsp+38h] [rbp-30h]
  int v7[2]; // [rsp+40h] [rbp-28h] BYREF
  Scaleform::Render::VertexFormat *v8; // [rsp+48h] [rbp-20h]
  __int64 v9; // [rsp+50h] [rbp-18h]
  __int64 v10; // [rsp+58h] [rbp-10h]
  __int16 v11; // [rsp+78h] [rbp+10h] BYREF
  int v12; // [rsp+7Ah] [rbp+12h]

  v8 = &Scaleform::Render::VertexXY16iCF32::Format;
  vfptr = verOut->vfptr;
  v5 = 0i64;
  v6 = 0;
  v12 = 0;
  v11 = 0;
  v9 = 0i64;
  v10 = 0i64;
  v7[0] = 1;
  v7[1] = 3;
  result = vfptr->BeginOutput(
             verOut,
             (Scaleform::Render::VertexOutput::Fill *)v7,
             1u,
             &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    verOut->vfptr->SetVertices(verOut, 0, 0, &v5, 1u);
    verOut->vfptr->SetIndices(verOut, 0, 0, (unsigned __int16 *)&v11, 3u);
    verOut->vfptr->EndOutput(verOut);
    return 1;
  }
  return result;
}

// File Line: 1205
// RVA: 0x982150
bool __fastcall Scaleform::Render::TextMeshProvider::GetData(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::VertexOutput *verOut,
        unsigned int meshGenFlags)
{
  Scaleform::Render::Renderer2DImpl *pRenderer2D; // rsi
  Scaleform::Render::TextMeshEntry *Data; // rdi
  __int64 Layer; // r8
  Scaleform::Render::TextMeshLayer *v8; // r8
  bool result; // al
  Scaleform::Render::Matrix2x4<float> mtx; // [rsp+40h] [rbp-28h] BYREF

  pRenderer2D = mesh->pRenderer2D;
  Data = this->Entries.Data.Data;
  Layer = mesh->Layer;
  mtx.M[0][0] = this->HeightRatio;
  mtx.M[1][1] = mtx.M[0][0];
  *(_OWORD *)&mtx.M[0][1] = 0ui64;
  v8 = &this->Layers.Data.Data[Layer];
  *(_QWORD *)&mtx.M[1][2] = 0i64;
  switch ( v8->Type )
  {
    case TextLayer_Background:
      result = Scaleform::Render::TextMeshProvider::generateRectangle(
                 this,
                 pRenderer2D,
                 verOut,
                 &mtx,
                 Data[v8->Start].EntryData.RasterData.Coord,
                 Data[v8->Start].mColor,
                 Data[v8->Start].EntryData.BackgroundData.BorderColor,
                 meshGenFlags);
      break;
    case TextLayer_Selection:
      result = Scaleform::Render::TextMeshProvider::generateSelection(this, pRenderer2D, verOut, v8, &mtx, meshGenFlags);
      break;
    case TextLayer_Shadow:
    case TextLayer_ShadowText:
    case TextLayer_RasterText:
      result = Scaleform::Render::TextMeshProvider::generateRasterMesh(this, verOut, v8);
      break;
    case TextLayer_PackedText:
    case TextLayer_PackedDFAText:
      result = Scaleform::Render::TextMeshProvider::generatePackedMesh(this, verOut, v8);
      break;
    case TextLayer_Images:
      result = Scaleform::Render::TextMeshProvider::generateImageMesh(this, verOut, v8);
      break;
    case TextLayer_Underline:
    case TextLayer_Underline_Masked:
      result = Scaleform::Render::TextMeshProvider::generateUnderlines(
                 this,
                 pRenderer2D,
                 verOut,
                 v8,
                 &mtx,
                 meshGenFlags);
      break;
    case TextLayer_Cursor:
      result = Scaleform::Render::TextMeshProvider::generateRectangle(
                 this,
                 pRenderer2D,
                 verOut,
                 &mtx,
                 Data[v8->Start].EntryData.RasterData.Coord,
                 Data[v8->Start].mColor,
                 0,
                 meshGenFlags);
      break;
    case TextLayer_Mask:
      result = Scaleform::Render::TextMeshProvider::generateMask(this, verOut, v8);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// File Line: 1263
// RVA: 0x9836C0
void __fastcall Scaleform::Render::TextMeshProvider::GetFillData(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::FillData *data,
        unsigned int layer,
        unsigned int fillIndex,
        char meshGenFlags)
{
  Scaleform::Render::TextMeshLayer *v6; // rdx
  char *v7; // rcx
  Scaleform::Render::GradientData *v8; // rax
  Scaleform::Render::GradientData *v9; // rcx
  Scaleform::Render::GradientData *v10; // rax
  Scaleform::Render::GradientData *pGlyph; // rdx
  Scaleform::Render::GradientData *v12; // [rsp+28h] [rbp-20h]

  if ( (meshGenFlags & 2) != 0 )
  {
    data->Type = Fill_Mask;
    data->PrimFill = PrimFill_Mask;
    LODWORD(v12) = 0;
    data->FillMode.Fill = 0;
    data->pGradient = v12;
    data->pVFormat = &Scaleform::Render::VertexXY16i::Format;
  }
  else
  {
    v6 = &this->Layers.Data.Data[(unsigned __int64)layer];
    switch ( v6->Type )
    {
      case TextLayer_Background:
      case TextLayer_Selection:
      case TextLayer_Shapes:
      case TextLayer_Underline:
      case TextLayer_Cursor:
      case TextLayer_Shapes_Masked:
      case TextLayer_Underline_Masked:
        data->Type = Fill_VColor;
        data->PrimFill = PrimFill_VColor;
        LODWORD(v12) = 0;
        data->FillMode.Fill = 0;
        data->pGradient = v12;
        data->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
        return;
      case TextLayer_Shadow:
      case TextLayer_ShadowText:
      case TextLayer_RasterText:
        v7 = (char *)this->pCache + 128 * (unsigned __int64)this->Entries.Data.Data[v6->Start].TextureId;
        v8 = (Scaleform::Render::GradientData *)*((_QWORD *)v7 + 31);
        if ( !v8 )
          v8 = (Scaleform::Render::GradientData *)*((_QWORD *)v7 + 32);
        data->Type = Fill_Image;
        data->pGradient = v8;
        data->FillMode.Fill = 3;
        goto LABEL_8;
      case TextLayer_PackedText:
        v9 = *(Scaleform::Render::GradientData **)&this->Entries.Data.Data[v6->Start].EntryData.RasterData.pGlyph->Param.BlurY;
        data->Type = Fill_Image;
        data->PrimFill = PrimFill_Texture_EAlpha;
        data->FillMode.Fill = 3;
        data->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
        data->pGradient = v9;
        if ( ((unsigned int (__fastcall *)(Scaleform::Render::GradientData *))v9->vfptr[4].__vecDelDtor)(v9) != 9 )
          goto LABEL_13;
LABEL_8:
        data->PrimFill = PrimFill_UVTextureAlpha_VColor;
        data->pVFormat = &Scaleform::Render::RasterGlyphVertex::Format;
        break;
      case TextLayer_PackedDFAText:
        v10 = *(Scaleform::Render::GradientData **)&this->Entries.Data.Data[v6->Start].EntryData.RasterData.pGlyph->Param.BlurY;
        data->Type = Fill_Image;
        data->FillMode.Fill = 3;
        data->pGradient = v10;
        data->PrimFill = PrimFill_UVTextureDFAlpha_VColor;
        data->pVFormat = &Scaleform::Render::RasterGlyphVertex::Format;
        return;
      case TextLayer_Images:
        pGlyph = (Scaleform::Render::GradientData *)this->Entries.Data.Data[v6->Start].EntryData.RasterData.pGlyph;
        data->Type = Fill_Image;
        data->FillMode.Fill = 3;
        data->pGradient = pGlyph;
LABEL_13:
        data->PrimFill = PrimFill_UVTexture;
        data->pVFormat = &Scaleform::Render::ImageGlyphVertex::Format;
        break;
      case TextLayer_Mask:
        data->Type = Fill_Mask;
        data->PrimFill = PrimFill_Mask;
        LODWORD(v12) = 0;
        data->FillMode.Fill = 0;
        data->pGradient = v12;
        data->pVFormat = &Scaleform::Render::VertexXY16i::Format;
        break;
      default:
        return;
    }
  }
}

// File Line: 1352
// RVA: 0x9CB330
void __fastcall Scaleform::Render::TextMeshProvider::addVectorGlyph(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        unsigned int color,
        Scaleform::Render::FontCacheHandle *font,
        unsigned __int16 glyphIndex,
        unsigned __int16 flags,
        float fontSize,
        float x,
        float y)
{
  Scaleform::Render::PrimitiveFill *pObject; // rsi
  Scaleform::Render::Font *pFont; // rbp
  Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4> *p_Entries; // rbx
  unsigned __int64 v12; // rdi
  Scaleform::Render::TmpTextMeshEntry *v13; // rdx
  __int64 v14; // r8
  __int64 v15; // [rsp+20h] [rbp-38h]
  __int64 v16; // [rsp+28h] [rbp-30h]
  __int64 v17; // [rsp+40h] [rbp-18h]

  LODWORD(v15) = 8;
  LODWORD(v16) = color;
  HIDWORD(v15) = storage->Entries.Size;
  pObject = this->pCache->pSolidFill.pObject;
  ++pObject->RefCount;
  _InterlockedExchangeAdd(&font->pFont->RefCount, 1u);
  pFont = font->pFont;
  p_Entries = &storage->Entries;
  *((float *)&v17 + 1) = fontSize;
  LOWORD(v17) = glyphIndex;
  v12 = storage->Entries.Size >> 6;
  WORD1(v17) = flags;
  if ( v12 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(p_Entries, v12);
  v13 = p_Entries->Pages[v12];
  v14 = p_Entries->Size & 0x3F;
  *(_QWORD *)&v13[v14].LayerType = v15;
  *(_QWORD *)&v13[v14].mColor = v16;
  v13[v14].pFill = pObject;
  v13[v14].EntryData.VectorData.pFont = pFont;
  *(_QWORD *)&v13[v14].EntryData.MaskData.Coord[2] = v17;
  v13[v14].EntryData.RasterData.pGlyph = (Scaleform::Render::GlyphNode *)__PAIR64__(LODWORD(y), LODWORD(x));
  ++p_Entries->Size;
}

// File Line: 1390
// RVA: 0x9C8D20
void __fastcall Scaleform::Render::TextMeshProvider::addSelection(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        unsigned int color,
        Scaleform::Render::Rect<float> *rect)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4> *p_Entries; // rbx
  Scaleform::Render::PrimitiveFill *pObject; // rsi
  unsigned __int64 v6; // rdi
  Scaleform::Render::TmpTextMeshEntry *v7; // rdx
  __int64 v8; // r8
  __int64 v9; // [rsp+20h] [rbp-38h]
  __int64 v10; // [rsp+28h] [rbp-30h]
  Scaleform::Render::Rect<float> v11; // [rsp+38h] [rbp-20h]
  Scaleform::Render::GlyphNode *v12; // [rsp+48h] [rbp-10h]

  p_Entries = &storage->Entries;
  LODWORD(v9) = 1;
  HIDWORD(v9) = storage->Entries.Size;
  LODWORD(v10) = color;
  pObject = this->pCache->pSolidFill.pObject;
  ++pObject->RefCount;
  v6 = storage->Entries.Size >> 6;
  v11 = *rect;
  if ( v6 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(p_Entries, v6);
  v7 = p_Entries->Pages[v6];
  v8 = p_Entries->Size & 0x3F;
  *(_QWORD *)&v7[v8].LayerType = v9;
  *(_QWORD *)&v7[v8].mColor = v10;
  v7[v8].pFill = pObject;
  *(Scaleform::Render::Rect<float> *)v7[v8].EntryData.RasterData.Coord = v11;
  v7[v8].EntryData.RasterData.pGlyph = v12;
  ++p_Entries->Size;
}

// File Line: 1424
// RVA: 0x9CB250
void __fastcall Scaleform::Render::TextMeshProvider::addUnderline(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        unsigned int color,
        unsigned int style,
        float x,
        float y,
        float len)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4> *p_Entries; // rbx
  Scaleform::Render::PrimitiveFill *pObject; // rsi
  unsigned __int64 v9; // rdi
  Scaleform::Render::TmpTextMeshEntry *v10; // rdx
  __int64 v11; // r8
  __int64 v12; // [rsp+20h] [rbp-38h]
  __int64 v13; // [rsp+28h] [rbp-30h]
  unsigned __int64 v14; // [rsp+38h] [rbp-20h]
  Scaleform::Render::GlyphNode *v15; // [rsp+48h] [rbp-10h]

  p_Entries = &storage->Entries;
  HIDWORD(v12) = storage->Entries.Size;
  pObject = this->pCache->pSolidFill.pObject;
  LODWORD(v12) = 9;
  LODWORD(v13) = color;
  ++pObject->RefCount;
  v14 = __PAIR64__(LODWORD(x), style);
  v9 = storage->Entries.Size >> 6;
  if ( v9 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(p_Entries, v9);
  v10 = p_Entries->Pages[v9];
  v11 = p_Entries->Size & 0x3F;
  *(_QWORD *)&v10[v11].LayerType = v12;
  *(_QWORD *)&v10[v11].mColor = v13;
  v10[v11].pFill = pObject;
  v10[v11].EntryData.VectorData.pFont = (Scaleform::Render::Font *)v14;
  *(_QWORD *)&v10[v11].EntryData.MaskData.Coord[2] = __PAIR64__(LODWORD(len), LODWORD(y));
  v10[v11].EntryData.RasterData.pGlyph = v15;
  ++p_Entries->Size;
}

// File Line: 1441
// RVA: 0x9C8870
void __fastcall Scaleform::Render::TextMeshProvider::addMask(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4> *p_Entries; // rbx
  Scaleform::Render::PrimitiveFill *pObject; // rsi
  unsigned __int64 v4; // rdi
  Scaleform::Render::TmpTextMeshEntry *v5; // rdx
  __int64 v6; // r8
  __int64 v7; // [rsp+20h] [rbp-38h]
  __int64 v8; // [rsp+28h] [rbp-30h]
  Scaleform::Render::Rect<float> ClipBox; // [rsp+38h] [rbp-20h]
  Scaleform::Render::GlyphNode *v10; // [rsp+48h] [rbp-10h]

  p_Entries = &storage->Entries;
  HIDWORD(v7) = storage->Entries.Size;
  LODWORD(v7) = 11;
  pObject = this->pCache->pMaskFill.pObject;
  LODWORD(v8) = 0;
  ++pObject->RefCount;
  v4 = storage->Entries.Size >> 6;
  ClipBox = this->ClipBox;
  if ( v4 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(p_Entries, v4);
  v5 = p_Entries->Pages[v4];
  v6 = p_Entries->Size & 0x3F;
  *(_QWORD *)&v5[v6].LayerType = v7;
  *(_QWORD *)&v5[v6].mColor = v8;
  v5[v6].pFill = pObject;
  *(Scaleform::Render::Rect<float> *)v5[v6].EntryData.RasterData.Coord = ClipBox;
  v5[v6].EntryData.RasterData.pGlyph = v10;
  ++p_Entries->Size;
}

// File Line: 1458
// RVA: 0x9C8470
void __fastcall Scaleform::Render::TextMeshProvider::addLayer(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        unsigned int type,
        unsigned int start,
        unsigned int count)
{
  unsigned int v9; // esi
  unsigned __int64 v10; // rdi
  Scaleform::Render::PrimitiveFill *pFill; // r15
  Scaleform::Render::TmpTextMeshLayer *v12; // rdx
  unsigned __int64 v13; // [rsp+20h] [rbp-48h]
  __int64 v14; // [rsp+28h] [rbp-40h]

  do
  {
    v9 = 16382;
    if ( count < 0x3FFE )
      v9 = count;
    v10 = storage->Layers.Size >> 4;
    v13 = __PAIR64__(start, type);
    pFill = storage->Entries.Pages[(unsigned __int64)start >> 6][start & 0x3F].pFill;
    LODWORD(v14) = v9;
    if ( v10 >= storage->Layers.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshLayer,4,4>::allocPage(&storage->Layers, v10);
    start += v9;
    v12 = &storage->Layers.Pages[v10][storage->Layers.Size & 0xF];
    *(_QWORD *)&v12->Type = v13;
    *(_QWORD *)&v12->Count = v14;
    v12->pFill = pFill;
    ++storage->Layers.Size;
    count -= v9;
  }
  while ( count );
}

// File Line: 1477
// RVA: 0x9C8550
void __fastcall Scaleform::Render::TextMeshProvider::addLayer(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        unsigned __int64 start,
        unsigned __int64 end)
{
  unsigned __int64 v4; // r14
  unsigned __int64 v6; // r12
  Scaleform::Render::TmpTextMeshEntry **Pages; // r11
  unsigned __int64 v8; // rdi
  __int64 v9; // rbx
  Scaleform::Render::TextMeshLayer *v10; // r8
  unsigned __int16 v11; // dx
  unsigned int v12; // ebp
  unsigned int v13; // r15d
  int v14; // esi
  Scaleform::Render::PrimitiveFill *pFill; // r12
  unsigned __int64 v16; // rdi
  Scaleform::Render::TmpTextMeshLayer *v17; // rdx
  unsigned int v18; // esi
  unsigned int v19; // r15d
  unsigned int v20; // r14d
  int v21; // ebp
  Scaleform::Render::PrimitiveFill *v22; // r12
  unsigned __int64 v23; // rdi
  Scaleform::Render::TmpTextMeshLayer *v24; // rdx
  unsigned __int64 v25; // [rsp+30h] [rbp-A8h]
  __int64 v26; // [rsp+40h] [rbp-98h]
  __int64 v27; // [rsp+48h] [rbp-90h]
  Scaleform::Render::TextMeshLayer v28; // [rsp+60h] [rbp-78h] BYREF
  unsigned __int64 v29; // [rsp+E8h] [rbp+10h]
  unsigned __int64 v30; // [rsp+F0h] [rbp+18h]

  v4 = start;
  v29 = start;
  v6 = 8 * (start >> 6);
  v25 = v6;
  Pages = storage->Entries.Pages;
  v8 = 48 * (start & 0x3F);
  v30 = v8;
  v9 = *(__int64 *)((char *)Pages + v6);
  if ( *(_WORD *)(v9 + v8) == 4
    && this->Layers.Data.Size
    && (v10 = &this->Layers.Data.Data[this->Layers.Data.Size], (unsigned int)(v10[-1].Type - 2) <= 1)
    && *(Scaleform::Render::PrimitiveFill **)(v9 + v8 + 16) == Pages[(unsigned __int64)v10[-1].Start >> 6][v10[-1].Start & 0x3F].pFill )
  {
    v10[-1].Type = TextLayer_ShadowText;
    v10[-1].Count += end - v4;
  }
  else
  {
    memset(&v28.pMesh, 0, 24);
    v28.M.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
    v28.pFill.pObject = 0i64;
    v11 = *(unsigned __int16 *)((char *)&(*(Scaleform::Render::TmpTextMeshEntry **)((char *)storage->Entries.Pages + v6))->LayerType
                              + v8);
    if ( ((v11 - 8) & 0xFFFB) != 0 )
    {
      if ( v11 == 7 )
      {
        for ( ; v4 < end; ++v4 )
        {
          v12 = 1;
          v13 = v4;
          do
          {
            v14 = 16382;
            if ( v12 < 0x3FFE )
              v14 = v12;
            LODWORD(v26) = 7;
            HIDWORD(v26) = v13;
            LODWORD(v27) = v14;
            pFill = storage->Entries.Pages[(unsigned __int64)v13 >> 6][v13 & 0x3F].pFill;
            v16 = storage->Layers.Size >> 4;
            if ( v16 >= storage->Layers.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshLayer,4,4>::allocPage(
                &storage->Layers,
                storage->Layers.Size >> 4);
            v17 = &storage->Layers.Pages[v16][storage->Layers.Size & 0xF];
            *(_QWORD *)&v17->Type = v26;
            *(_QWORD *)&v17->Count = v27;
            v17->pFill = pFill;
            ++storage->Layers.Size;
            v13 += v14;
            v12 -= v14;
          }
          while ( v12 );
        }
      }
      else
      {
        Scaleform::Render::TextMeshProvider::addLayer(this, storage, v11, v4, end - v4);
      }
    }
    else
    {
      for ( ; v4 < end; v6 = v25 )
      {
        v18 = 1;
        v19 = v4;
        v20 = *(unsigned __int16 *)((char *)&(*(Scaleform::Render::TmpTextMeshEntry **)((char *)storage->Entries.Pages
                                                                                      + v6))->LayerType
                                  + v8);
        do
        {
          v21 = 16382;
          if ( v18 < 0x3FFE )
            v21 = v18;
          LODWORD(v27) = v21;
          v22 = storage->Entries.Pages[(unsigned __int64)v19 >> 6][v19 & 0x3F].pFill;
          v23 = storage->Layers.Size >> 4;
          if ( v23 >= storage->Layers.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshLayer,4,4>::allocPage(
              &storage->Layers,
              storage->Layers.Size >> 4);
          v24 = &storage->Layers.Pages[v23][storage->Layers.Size & 0xF];
          *(_QWORD *)&v24->Type = __PAIR64__(v19, v20);
          *(_QWORD *)&v24->Count = v27;
          v24->pFill = v22;
          ++storage->Layers.Size;
          v19 += v21;
          v18 -= v21;
        }
        while ( v18 );
        v4 = v29 + 1;
        v29 = v4;
        v8 = v30;
      }
    }
    Scaleform::Render::TextMeshLayer::~TextMeshLayer(&v28);
  }
}

// File Line: 1528
// RVA: 0x9F2690
void __fastcall Scaleform::Render::TextMeshProvider::sortEntries(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage)
{
  unsigned __int64 v4; // r8
  unsigned __int64 v5; // rbx
  Scaleform::Render::TmpTextMeshEntry **Pages; // rdx
  Scaleform::Render::TmpTextMeshEntry *v7; // r11
  Scaleform::Render::TmpTextMeshEntry *v8; // rcx
  unsigned __int64 Size; // rbx
  Scaleform::ArrayDH<Scaleform::Render::TextMeshEntry,2,Scaleform::ArrayDefaultPolicy> *p_Entries; // r15
  unsigned __int64 v11; // r14
  __int64 v12; // rdx
  unsigned __int64 i; // rbx
  unsigned __int64 v14; // rbx
  Scaleform::ArrayDH<Scaleform::Render::TextMeshLayer,2,Scaleform::ArrayDefaultPolicy> *p_Layers; // r13
  unsigned __int64 v16; // rdi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v17; // r8
  Scaleform::Render::TextMeshLayer *v18; // rax
  unsigned __int64 j; // rbx
  unsigned __int64 v20; // r14
  __int64 v21; // rbx
  Scaleform::Render::TmpTextMeshEntry *v22; // rdi
  Scaleform::Render::TextMeshEntry *Data; // rbp
  Scaleform::Render::PrimitiveFill *pFill; // r12
  Scaleform::Render::PrimitiveFill *pObject; // rcx
  bool v26; // zf
  unsigned __int64 v27; // r15
  __int64 v28; // rbx
  Scaleform::Render::TmpTextMeshLayer *v29; // r12
  Scaleform::Render::TextMeshLayer *v30; // rdi
  Scaleform::Render::Mesh *v31; // rcx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // r14
  Scaleform::Render::MatrixPoolImpl::EntryHandle v33; // r14
  __int64 DataPageOffset; // rcx
  Scaleform::Render::PrimitiveFill *v35; // rbp
  Scaleform::Render::PrimitiveFill *v36; // rcx

  storage->Layers.Size = 0i64;
  Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>,Scaleform::Render::TextMeshProvider::CmpEntries>(
    &storage->Entries,
    0i64,
    storage->Entries.Size,
    (Scaleform::Render::TextMeshProvider::CmpEntries)this->pCache);
  v4 = 0i64;
  v5 = 0i64;
  if ( storage->Entries.Size )
  {
    do
    {
      Pages = storage->Entries.Pages;
      v7 = Pages[v5 >> 6];
      v8 = Pages[v4 >> 6];
      if ( (v8[v4 & 0x3F].LayerType != v7[v5 & 0x3F].LayerType || v8[v4 & 0x3F].pFill != v7[v5 & 0x3F].pFill) && v5 > v4 )
      {
        Scaleform::Render::TextMeshProvider::addLayer(this, storage, v4, v5);
        v4 = v5;
      }
      ++v5;
    }
    while ( v5 < storage->Entries.Size );
    if ( v5 > v4 )
      Scaleform::Render::TextMeshProvider::addLayer(this, storage, v4, v5);
  }
  Size = storage->Entries.Size;
  p_Entries = &this->Entries;
  v11 = this->Entries.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Entries.Data,
    (__int64 *)this->Entries.Data.pHeap,
    Size);
  if ( Size > v11 )
  {
    v12 = (__int64)&p_Entries->Data.Data[v11];
    for ( i = Size - v11; i; --i )
    {
      if ( v12 )
        *(_QWORD *)(v12 + 8) = 0i64;
      v12 += 40i64;
    }
  }
  v14 = storage->Layers.Size;
  p_Layers = &this->Layers;
  v16 = this->Layers.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &p_Layers->Data,
    (__int64 *)p_Layers->Data.pHeap,
    v14);
  v17 = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
  if ( v14 > v16 )
  {
    v18 = &p_Layers->Data.Data[v16];
    for ( j = v14 - v16; j; --j )
    {
      if ( v18 )
      {
        v18->pMesh.pObject = 0i64;
        v18->pMeshKey.pObject = 0i64;
        v18->pShape.pObject = 0i64;
        v18->M.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
        v18->pFill.pObject = 0i64;
      }
      ++v18;
    }
  }
  v20 = 0i64;
  if ( storage->Entries.Size )
  {
    v21 = 0i64;
    do
    {
      v22 = &storage->Entries.Pages[v20 >> 6][v20 & 0x3F];
      Data = p_Entries->Data.Data;
      Data[v21].LayerType = v22->LayerType;
      Data[v21].TextureId = v22->TextureId;
      Data[v21].mColor = v22->mColor;
      pFill = v22->pFill;
      pObject = Data[v21].pFill.pObject;
      if ( pObject )
      {
        v26 = pObject->RefCount-- == 1;
        if ( v26 )
          ((void (__fastcall *)(Scaleform::Render::PrimitiveFill *, __int64, Scaleform::Render::MatrixPoolImpl::EntryHandle *))pObject->vfptr->__vecDelDtor)(
            pObject,
            1i64,
            v17);
      }
      Data[v21].pFill.pObject = pFill;
      Data[v21].EntryData.VectorData.pFont = v22->EntryData.VectorData.pFont;
      *(_QWORD *)&Data[v21].EntryData.MaskData.Coord[2] = *(_QWORD *)&v22->EntryData.MaskData.Coord[2];
      Data[v21].EntryData.RasterData.pGlyph = v22->EntryData.RasterData.pGlyph;
      ++v20;
      ++v21;
    }
    while ( v20 < storage->Entries.Size );
  }
  v27 = 0i64;
  if ( storage->Layers.Size )
  {
    v28 = 0i64;
    do
    {
      v29 = storage->Layers.Pages[v27 >> 4];
      v30 = p_Layers->Data.Data;
      v30[v28].Type = v29[v27 & 0xF].Type;
      v30[v28].Start = v29[v27 & 0xF].Start;
      v30[v28].Count = v29[v27 & 0xF].Count;
      v31 = v30[v28].pMesh.pObject;
      if ( v31 && !_InterlockedDecrement(&v31->RefCount) )
        ((void (__fastcall *)(Scaleform::Render::Mesh *, __int64, Scaleform::Render::MatrixPoolImpl::EntryHandle *))v31->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor)(
          v31,
          1i64,
          &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle);
      v30[v28].pMesh.pObject = 0i64;
      pHandle = v30[v28].M.pHandle;
      if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      {
        v33.pHeader = pHandle->pHeader;
        v26 = v33.pHeader->RefCount-- == 1;
        if ( v26 )
        {
          DataPageOffset = v33.pHeader->DataPageOffset;
          *(_WORD *)((char *)&v33.pHeader[1].RefCount + DataPageOffset + 2) += 16
                                                                             * (unsigned __int8)v33.pHeader->UnitSize;
          (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v33.pHeader[1].pHandle + DataPageOffset))[5].pHeader += (unsigned __int8)v33.pHeader->UnitSize;
          Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v33.pNext->pNext);
          v33.pHeader->pHandle = 0i64;
        }
      }
      v30[v28].M.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
      v35 = v29[v27 & 0xF].pFill;
      if ( v35 )
        ++v35->RefCount;
      v36 = v30[v28].pFill.pObject;
      if ( v36 )
      {
        v26 = v36->RefCount-- == 1;
        if ( v26 )
          ((void (__fastcall *)(Scaleform::Render::PrimitiveFill *, __int64, Scaleform::Render::MatrixPoolImpl::EntryHandle *))v36->vfptr->__vecDelDtor)(
            v36,
            1i64,
            &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle);
      }
      v30[v28].pFill.pObject = v35;
      v30[v28].SizeScale = 1.0;
      ++v27;
      ++v28;
    }
    while ( v27 < storage->Layers.Size );
  }
}

// File Line: 1585
// RVA: 0x9C7B50
void __fastcall Scaleform::Render::TextMeshProvider::addImage(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        Scaleform::Render::GlyphRunData *data,
        Scaleform::Render::Image *img,
        float scaleX,
        float scaleY,
        float baseLine,
        bool snap)
{
  float NewLineX; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm0_4
  __m128 NewLineY_low; // xmm6
  int v15; // ecx
  Scaleform::Render::Texture *v16; // rdi
  Scaleform::Render::Texture *pObject; // rcx
  Scaleform::Render::Texture *v18; // rcx
  Scaleform::Render::PrimitiveFill *v19; // r14
  int *v20; // rax
  int *v21; // rax
  unsigned __int64 v22; // rdi
  __int64 v23; // r11
  Scaleform::Render::TmpTextMeshEntry *v24; // r10
  Scaleform::Render::PrimitiveFillData ptr; // [rsp+40h] [rbp-71h] BYREF
  __int64 v26; // [rsp+68h] [rbp-49h]
  __int64 v27; // [rsp+70h] [rbp-41h]
  unsigned __int64 v28; // [rsp+80h] [rbp-31h]
  __int64 v29; // [rsp+88h] [rbp-29h]
  char v30; // [rsp+F8h] [rbp+47h] BYREF
  char v31; // [rsp+100h] [rbp+4Fh] BYREF

  NewLineX = data->NewLineX;
  v12 = data->NewLineY - (float)(scaleY * baseLine);
  if ( snap )
  {
    NewLineY_low = (__m128)LODWORD(data->NewLineY);
    v13 = data->NewLineX;
    NewLineY_low.m128_f32[0] = (float)((float)((float)(NewLineY_low.m128_f32[0] * data->DirMtx.M[0][1])
                                             + (float)(v13 * data->DirMtx.M[0][0]))
                                     + data->DirMtx.M[0][3])
                             + 0.5;
    v15 = (int)NewLineY_low.m128_f32[0];
    if ( (int)NewLineY_low.m128_f32[0] != 0x80000000 && (float)v15 != NewLineY_low.m128_f32[0] )
      NewLineY_low.m128_f32[0] = (float)(v15 - (_mm_movemask_ps(_mm_unpacklo_ps(NewLineY_low, NewLineY_low)) & 1));
    NewLineX = (float)((float)(NewLineY_low.m128_f32[0] * data->InvMtx.M[0][0])
                     + (float)((float)((float)((float)(data->NewLineY * data->DirMtx.M[1][1])
                                             + (float)(v13 * data->DirMtx.M[1][0]))
                                     + data->DirMtx.M[1][3])
                             * data->InvMtx.M[0][1]))
             + data->InvMtx.M[0][3];
  }
  LODWORD(v26) = 7;
  HIDWORD(v26) = storage->Entries.Size;
  v16 = (Scaleform::Render::Texture *)img->vfptr[21].__vecDelDtor(img, this->pCache->pTexMan);
  *(_QWORD *)&ptr.Type = 11i64;
  `eh vector constructor iterator(
    ptr.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  ptr.pFormat = &Scaleform::Render::ImageGlyphVertex::Format;
  *(_WORD *)&ptr.FillModes[0].Fill = 3;
  if ( v16 )
    _InterlockedExchangeAdd(&v16->RefCount, 1u);
  pObject = ptr.Textures[0].pObject;
  if ( ptr.Textures[0].pObject && !_InterlockedDecrement(&ptr.Textures[0].pObject->RefCount) && pObject )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  ptr.Textures[0].pObject = v16;
  v18 = ptr.Textures[1].pObject;
  if ( ptr.Textures[1].pObject && !_InterlockedDecrement(&ptr.Textures[1].pObject->RefCount) && v18 )
    v18->vfptr->__vecDelDtor(v18, 1u);
  ptr.Textures[1].pObject = 0i64;
  v19 = Scaleform::Render::PrimitiveFillManager::CreateFill(this->pCache->pFillMan, &ptr);
  v28 = __PAIR64__(LODWORD(v12), LODWORD(NewLineX));
  v20 = (int *)img->vfptr[5].__vecDelDtor(img, &v30);
  *(float *)&v29 = (float)((float)*v20 * scaleX) + NewLineX;
  v21 = (int *)img->vfptr[5].__vecDelDtor(img, &v31);
  *((float *)&v29 + 1) = (float)((float)v21[1] * scaleY) + v12;
  v22 = storage->Entries.Size >> 6;
  if ( v22 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(
      &storage->Entries,
      storage->Entries.Size >> 6);
  v23 = storage->Entries.Size & 0x3F;
  v24 = storage->Entries.Pages[v22];
  *(_QWORD *)&v24[v23].LayerType = v26;
  *(_QWORD *)&v24[v23].mColor = v27;
  v24[v23].pFill = v19;
  v24[v23].EntryData.VectorData.pFont = (Scaleform::Render::Font *)v28;
  *(_QWORD *)&v24[v23].EntryData.MaskData.Coord[2] = v29;
  v24[v23].EntryData.RasterData.pGlyph = (Scaleform::Render::GlyphNode *)img;
  ++storage->Entries.Size;
  `eh vector destructor iterator(
    ptr.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
}

// File Line: 1613
// RVA: 0x9D21B0
float __fastcall Scaleform::Render::TextMeshProvider::calcHeightRatio(
        Scaleform::Render::MatrixPoolImpl::HMatrix *m,
        Scaleform::Render::Matrix4x4<float> *m4,
        Scaleform::Render::Viewport *vp)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // r9
  bool v4; // zf
  __int64 v5; // rax
  float v6; // xmm1_4
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm6_4
  float v10; // xmm3_4
  unsigned int RefCount; // xmm0_4
  float v12; // xmm1_4
  float Height; // xmm3_4
  float Width; // xmm2_4
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  float result; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  Scaleform::Render::Rect<float> bounds; // [rsp+30h] [rbp-19h] BYREF
  int v22; // [rsp+40h] [rbp-9h]
  int v23; // [rsp+44h] [rbp-5h]
  Scaleform::Render::Matrix2x4<float> v24; // [rsp+50h] [rbp+7h] BYREF
  __m128 dst[2]; // [rsp+70h] [rbp+27h] BYREF

  pHeader = m->pHandle->pHeader;
  v4 = (pHeader->Format & 0x10) == 0;
  v5 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[4];
  v6 = *(float *)&pHeader[v5 + 1].DataPageOffset;
  v7 = *(float *)&pHeader[v5 + 1].pHandle;
  v8 = *((float *)&pHeader[v5 + 1].pHandle + 1);
  v9 = *(float *)&pHeader[v5 + 2].pHandle;
  v10 = *((float *)&pHeader[v5 + 2].pHandle + 1);
  LODWORD(v24.M[0][2]) = pHeader[v5 + 1].RefCount;
  RefCount = pHeader[v5 + 2].RefCount;
  v24.M[0][3] = v6;
  v12 = *(float *)&pHeader[v5 + 2].DataPageOffset;
  *(_QWORD *)&v24.M[0][0] = __PAIR64__(LODWORD(v8), LODWORD(v7));
  v24.M[1][3] = v12;
  v24.M[1][0] = v9;
  *(_QWORD *)&v24.M[1][1] = __PAIR64__(RefCount, LODWORD(v10));
  if ( v4 )
  {
    v19 = Scaleform::Render::Math2D::LinePointDistance(
            0.0,
            0.0,
            (float)(v8 * 0.0) + v7,
            (float)(v10 * 0.0) + v9,
            (float)(v7 * 0.0) + v8,
            (float)(v9 * 0.0) + v10);
    result = FLOAT_9_9999999eN9;
    LODWORD(v20) = LODWORD(v19) & _xmm;
    if ( v20 >= 0.0000000099999999 )
      return v20;
  }
  else
  {
    Height = (float)vp->Height;
    Width = (float)vp->Width;
    bounds = (Scaleform::Render::Rect<float>)_xmm;
    Scaleform::Render::Matrix4x4<float>::TransformHomogeneousAndScaleCorners(m4, (__m128 *)&bounds, Width, Height, dst);
    *(_QWORD *)&bounds.x1 = 0i64;
    *(_QWORD *)&bounds.x2 = 1065353216i64;
    v22 = 1065353216;
    v23 = 1065353216;
    Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v24, &bounds.x1, dst[0].m128_f32);
    v15 = (__m128)LODWORD(v24.M[1][0]);
    v16 = (__m128)LODWORD(v24.M[1][1]);
    v15.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v24.M[0][0] * v24.M[0][0]);
    v16.m128_f32[0] = (float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v24.M[0][1] * v24.M[0][1]);
    if ( v16.m128_f32[0] >= v15.m128_f32[0] )
      v15 = v16;
    result = FLOAT_0_0000099999997;
    v18 = _mm_sqrt_ps(v15).m128_f32[0];
    if ( v18 >= 0.0000099999997 )
      return v18;
  }
  return result;
}

// File Line: 1652
// RVA: 0x9C8A90
void __fastcall Scaleform::Render::TextMeshProvider::addRasterGlyph(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        Scaleform::Render::TextLayerType type,
        Scaleform::Render::GlyphRunData *data,
        unsigned int color,
        Scaleform::Render::GlyphNode *node,
        float screenSize,
        bool snap,
        float stretch)
{
  float NewLineX; // xmm3_4
  unsigned __int16 w; // r8
  unsigned __int16 h; // dx
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm0_4
  float v20; // xmm9_4
  float ShadowOffsetX; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm7_4
  float v24; // xmm9_4
  float v25; // xmm6_4
  float v26; // xmm8_4
  float ShadowOffsetY; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  Scaleform::Render::PrimitiveFill *Fill; // rbp
  unsigned __int64 v31; // rsi
  Scaleform::Render::TmpTextMeshEntry *v32; // rdx
  __int64 v33; // r8
  __int64 v34; // [rsp+20h] [rbp-78h]
  __int64 v35; // [rsp+28h] [rbp-70h]
  Scaleform::Render::Font *v36; // [rsp+38h] [rbp-60h]
  float v37[4]; // [rsp+40h] [rbp-58h]

  NewLineX = data->NewLineX;
  if ( snap && ((data->pFont->Flags & 0x80) != 0 || (node->Param.Flags & 1) != 0 && (node->Param.Flags & 4) == 0) )
    NewLineX = Scaleform::Render::TextMeshProvider::snapX(this, data);
  w = node->mRect.w;
  if ( w > 1u )
  {
    h = node->mRect.h;
    if ( h > 1u )
    {
      v16 = (float)((float)node->Origin.x * 0.0625) + 1.0;
      v17 = (float)((float)node->Origin.y * 0.0625) + 1.0;
      v18 = (float)((float)w + v16) - 2.0;
      v19 = (float)node->Param.FontSize * 0.0625;
      v20 = (float)((float)h + v17) - 2.0;
      if ( v19 < 0.0000099999997 )
        v19 = FLOAT_0_0000099999997;
      ShadowOffsetX = 0.0;
      v22 = (float)((float)(screenSize * node->Scale) / v19) / data->HeightRatio;
      v23 = v17 * v22;
      v24 = v20 * v22;
      v25 = v16 * (float)(v22 / stretch);
      v26 = v18 * (float)(v22 / stretch);
      ShadowOffsetY = 0.0;
      if ( type == TextLayer_Shadow )
      {
        ShadowOffsetX = data->Param.ShadowOffsetX;
        ShadowOffsetY = data->Param.ShadowOffsetY;
      }
      v28 = ShadowOffsetY + data->NewLineY;
      v29 = ShadowOffsetX + NewLineX;
      HIDWORD(v34) = storage->Entries.Size;
      WORD1(v34) = node->pSlot->TextureId & 0x7FFF;
      LODWORD(v35) = color;
      LOWORD(v34) = type;
      Fill = Scaleform::Render::GlyphCache::GetFill(this->pCache, type, WORD1(v34));
      ++Fill->RefCount;
      v31 = storage->Entries.Size >> 6;
      if ( v31 >= storage->Entries.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(&storage->Entries, v31);
      v32 = storage->Entries.Pages[v31];
      v33 = storage->Entries.Size & 0x3F;
      *(_QWORD *)&v32[v33].LayerType = v34;
      *(_QWORD *)&v32[v33].mColor = v35;
      v32[v33].pFill = Fill;
      *((float *)&v36 + 1) = v23 + v28;
      *(float *)&v36 = v25 + v29;
      v32[v33].EntryData.VectorData.pFont = v36;
      v37[1] = v24 + v28;
      v37[0] = v26 + v29;
      *(_QWORD *)&v32[v33].EntryData.MaskData.Coord[2] = *(_QWORD *)v37;
      v32[v33].EntryData.RasterData.pGlyph = node;
      ++storage->Entries.Size;
    }
  }
}

// File Line: 1716
// RVA: 0x9CA350
void __fastcall Scaleform::Render::TextMeshProvider::addTextureGlyph(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        Scaleform::Render::GlyphNode *tgl,
        Scaleform::Render::GlyphRunData *data)
{
  float NewLineX; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm7_4
  float NewLineY; // xmm2_4
  float v14; // xmm8_4
  float v15; // xmm9_4
  float v16; // xmm6_4
  Scaleform::Render::Image *v17; // rcx
  Scaleform::Render::Texture *v18; // r14
  Scaleform::Render::Texture *pObject; // rcx
  Scaleform::Render::Texture *v20; // rcx
  Scaleform::Render::PrimitiveFill *v21; // r14
  Scaleform::Ptr<Scaleform::Render::Texture> *Textures; // rcx
  int v23; // eax
  Scaleform::Render::Image *v24; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // r8
  Scaleform::Render::TextureManager *pTexMan; // rdx
  Scaleform::Render::Texture *v27; // r14
  Scaleform::Render::Texture *v28; // rcx
  Scaleform::Render::Texture *v29; // rcx
  Scaleform::Render::Texture *v30; // r14
  Scaleform::Render::Texture *v31; // rcx
  Scaleform::Render::Texture *v32; // rcx
  unsigned __int64 v33; // rdi
  __int64 v34; // r8
  Scaleform::Render::TmpTextMeshEntry *v35; // rdx
  Scaleform::Render::PrimitiveFillData v36; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::Render::PrimitiveFillData initdata; // [rsp+58h] [rbp-80h] BYREF
  __int64 v38; // [rsp+80h] [rbp-58h]
  __int64 v39; // [rsp+88h] [rbp-50h]
  unsigned __int64 v40; // [rsp+98h] [rbp-40h]
  unsigned __int64 v41; // [rsp+A0h] [rbp-38h]
  __int64 v42; // [rsp+B0h] [rbp-28h]
  int v43[4]; // [rsp+130h] [rbp+58h] BYREF
  void *retaddr; // [rsp+148h] [rbp+70h]

  v42 = -2i64;
  NewLineX = data->NewLineX;
  (*(void (__fastcall **)(_QWORD, int *))(**(_QWORD **)&tgl->Param.BlurY + 40i64))(*(_QWORD *)&tgl->Param.BlurY, v43);
  v9 = data->FontSize / data->TexHeight;
  v10 = (float)v43[0] * v9;
  v11 = (float)v43[1] * v9;
  v12 = (float)((float)(*(float *)&tgl->pNext - *(float *)&tgl->mRect.x) * v10) + NewLineX;
  NewLineY = data->NewLineY;
  v14 = (float)((float)(*((float *)&tgl->pNext + 1) - *(float *)&tgl->mRect.w) * v11) + NewLineY;
  v15 = (float)((float)(*(float *)&tgl->pNex2 - *(float *)&tgl->mRect.x) * v10) + NewLineX;
  v16 = (float)((float)(*((float *)&tgl->pNex2 + 1) - *(float *)&tgl->mRect.w) * v11) + NewLineY;
  LODWORD(v38) = 5;
  HIDWORD(v38) = storage->Entries.Size;
  LODWORD(v39) = (_DWORD)retaddr;
  v17 = *(Scaleform::Render::Image **)&tgl->Param.BlurY;
  if ( (data->pFont->Flags & 0x10000) != 0 )
  {
    v18 = (Scaleform::Render::Texture *)v17->vfptr[21].__vecDelDtor(v17, (unsigned int)this->pCache->pTexMan);
    *(_QWORD *)&initdata.Type = 13i64;
    `eh vector constructor iterator(
      initdata.Textures,
      8ui64,
      2,
      (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
    initdata.pFormat = &Scaleform::Render::RasterGlyphVertex::Format;
    *(_WORD *)&initdata.FillModes[0].Fill = 3;
    if ( v18 )
      _InterlockedExchangeAdd(&v18->RefCount, 1u);
    pObject = initdata.Textures[0].pObject;
    if ( initdata.Textures[0].pObject && !_InterlockedDecrement(&initdata.Textures[0].pObject->RefCount) && pObject )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
    initdata.Textures[0].pObject = v18;
    v20 = initdata.Textures[1].pObject;
    if ( initdata.Textures[1].pObject && !_InterlockedDecrement(&initdata.Textures[1].pObject->RefCount) && v20 )
      v20->vfptr->__vecDelDtor(v20, 1u);
    initdata.Textures[1].pObject = 0i64;
    v21 = Scaleform::Render::PrimitiveFillManager::CreateFill(this->pCache->pFillMan, &initdata);
    LOWORD(v38) = 6;
    this->Flags |= 0x200u;
    Textures = initdata.Textures;
  }
  else
  {
    v23 = ((__int64 (__fastcall *)(Scaleform::Render::Image *))v17->vfptr[4].__vecDelDtor)(v17);
    v24 = *(Scaleform::Render::Image **)&tgl->Param.BlurY;
    vfptr = v24->vfptr;
    pTexMan = this->pCache->pTexMan;
    if ( v23 == 9 )
    {
      v27 = (Scaleform::Render::Texture *)vfptr[21].__vecDelDtor(v24, (unsigned int)pTexMan);
      *(_QWORD *)&v36.Type = 12i64;
      `eh vector constructor iterator(
        v36.Textures,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
      v36.pFormat = &Scaleform::Render::RasterGlyphVertex::Format;
      *(_WORD *)&v36.FillModes[0].Fill = 3;
      if ( v27 )
        _InterlockedExchangeAdd(&v27->RefCount, 1u);
      v28 = v36.Textures[0].pObject;
      if ( v36.Textures[0].pObject && !_InterlockedDecrement(&v36.Textures[0].pObject->RefCount) && v28 )
        v28->vfptr->__vecDelDtor(v28, 1u);
      v36.Textures[0].pObject = v27;
      v29 = v36.Textures[1].pObject;
      if ( v36.Textures[1].pObject && !_InterlockedDecrement(&v36.Textures[1].pObject->RefCount) && v29 )
        v29->vfptr->__vecDelDtor(v29, 1u);
      v36.Textures[1].pObject = 0i64;
      v21 = Scaleform::Render::PrimitiveFillManager::CreateFill(this->pCache->pFillMan, &v36);
      Textures = v36.Textures;
    }
    else
    {
      v30 = (Scaleform::Render::Texture *)vfptr[21].__vecDelDtor(v24, (unsigned int)pTexMan);
      *(_QWORD *)&initdata.Type = 11i64;
      `eh vector constructor iterator(
        initdata.Textures,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
      initdata.pFormat = &Scaleform::Render::ImageGlyphVertex::Format;
      *(_WORD *)&initdata.FillModes[0].Fill = 3;
      if ( v30 )
        _InterlockedExchangeAdd(&v30->RefCount, 1u);
      v31 = initdata.Textures[0].pObject;
      if ( initdata.Textures[0].pObject && !_InterlockedDecrement(&initdata.Textures[0].pObject->RefCount) && v31 )
        v31->vfptr->__vecDelDtor(v31, 1u);
      initdata.Textures[0].pObject = v30;
      v32 = initdata.Textures[1].pObject;
      if ( initdata.Textures[1].pObject && !_InterlockedDecrement(&initdata.Textures[1].pObject->RefCount) && v32 )
        v32->vfptr->__vecDelDtor(v32, 1u);
      initdata.Textures[1].pObject = 0i64;
      v21 = Scaleform::Render::PrimitiveFillManager::CreateFill(this->pCache->pFillMan, &initdata);
      Textures = initdata.Textures;
    }
  }
  `eh vector destructor iterator(
    Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
  v40 = __PAIR64__(LODWORD(v14), LODWORD(v12));
  v41 = __PAIR64__(LODWORD(v16), LODWORD(v15));
  v33 = storage->Entries.Size >> 6;
  if ( v33 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(
      &storage->Entries,
      storage->Entries.Size >> 6);
  v34 = storage->Entries.Size & 0x3F;
  v35 = storage->Entries.Pages[v33];
  *(_QWORD *)&v35[v34].LayerType = v38;
  *(_QWORD *)&v35[v34].mColor = v39;
  v35[v34].pFill = v21;
  v35[v34].EntryData.VectorData.pFont = (Scaleform::Render::Font *)v40;
  *(_QWORD *)&v35[v34].EntryData.MaskData.Coord[2] = v41;
  v35[v34].EntryData.RasterData.pGlyph = tgl;
  ++storage->Entries.Size;
}

// File Line: 1780
// RVA: 0x9C73D0
char __fastcall Scaleform::Render::TextMeshProvider::addGlyph(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        Scaleform::Render::GlyphRunData *data,
        unsigned int glyphIndex)
{
  double v8; // xmm7_8
  Scaleform::Render::TextureGlyph *v9; // rax
  Scaleform::Render::FontCacheHandle *pFontHandle; // r15
  unsigned __int16 Flags; // cx
  __int16 v13; // di
  unsigned __int16 v14; // di
  Scaleform::Render::GlyphCache *pCache; // r14
  __m128d v16; // xmm1
  int v17; // ecx
  unsigned int RasterSize; // ecx
  __int16 v19; // di
  unsigned __int16 v20; // di
  Scaleform::Render::Font *pFont; // rcx
  double v22; // xmm0_8
  float v23; // xmm6_4
  unsigned int v24; // r8d
  unsigned __int16 v25; // dx
  float stretch; // xmm6_4
  Scaleform::Render::GlyphCache *v27; // r14
  Scaleform::Render::GlyphNode *Glyph; // rax
  Scaleform::Render::GlyphNode *v29; // rdi
  Scaleform::Render::TextNotifier *Notifier; // rax
  Scaleform::Render::GlyphNode *v31; // rax
  Scaleform::Render::GlyphCache *v32; // rcx
  Scaleform::Render::GlyphCache::RasResult v33; // eax
  float v34; // xmm5_4
  float v35; // xmm8_4
  float v36; // xmm7_4
  float v37; // xmm0_4
  float v38; // xmm6_4
  char v39; // bl
  Scaleform::Render::ShapeDataInterface *pShape; // rcx
  char v41; // al
  unsigned __int16 v42; // di
  unsigned int ShadowColor; // r14d
  unsigned __int16 v44; // dx
  __int16 v45; // cx
  unsigned __int16 v46; // cx
  Scaleform::Render::GlyphCache *v47; // r15
  __m128d v48; // xmm1
  int v49; // ecx
  Scaleform::Render::GlyphNode *v50; // rax
  Scaleform::Render::GlyphNode *v51; // rdi
  Scaleform::Render::TextNotifier *v52; // rax
  Scaleform::Render::GlyphNode *v53; // rax
  char color; // [rsp+20h] [rbp-71h]
  Scaleform::Render::GlyphNode *node; // [rsp+28h] [rbp-69h]
  Scaleform::Render::Rect<float> needsVectorShape; // [rsp+38h] [rbp-59h] BYREF
  Scaleform::Render::GlyphParam gp; // [rsp+48h] [rbp-49h] BYREF
  char v58; // [rsp+E8h] [rbp+57h]
  unsigned __int16 glyphIndexa[2]; // [rsp+F0h] [rbp+5Fh]
  unsigned __int8 v60; // [rsp+F8h] [rbp+67h]
  unsigned __int8 vars0; // [rsp+100h] [rbp+6Fh]
  _BOOL8 retaddr; // [rsp+108h] [rbp+77h]

  v58 = 1;
  *(_QWORD *)&v8 = LODWORD(data->HeightRatio);
  *(float *)&v8 = *(float *)&v8 * data->FontSize;
  v9 = (Scaleform::Render::TextureGlyph *)data->pFont->vfptr[10].__vecDelDtor(data->pFont, glyphIndex);
  if ( !v9 )
    goto LABEL_8;
  if ( (data->pFont->Flags & 0x1000) == 0
    && *(float *)&v8 > (float)(this->pCache->Param.MaxRasterScale * data->TexHeight) )
  {
    v58 = 0;
LABEL_8:
    node = (Scaleform::Render::GlyphNode *)Scaleform::Render::GlyphCache::CreateGlyphShape(
                                             this->pCache,
                                             data,
                                             glyphIndex,
                                             *(float *)&v8,
                                             v60 | ((data->Param.TextParam.Flags & 8) != 0),
                                             vars0 | ((data->Param.TextParam.Flags & 0x10) != 0),
                                             data->Param.TextParam.Flags >> 12,
                                             0);
    gp = data->Param.TextParam;
    pFontHandle = data->pFontHandle;
    gp.pFont = pFontHandle;
    gp.GlyphIndex = glyphIndex;
    Flags = data->Param.TextParam.Flags;
    if ( v60 | ((Flags & 8) != 0) )
      v13 = gp.Flags | 8;
    else
      v13 = gp.Flags & 0xFFF7;
    if ( vars0 | ((Flags & 0x10) != 0) )
      v14 = v13 | 0x10;
    else
      v14 = v13 & 0xFFEF;
    gp.Flags = v14;
    pCache = this->pCache;
    v16 = 0i64;
    v16.m128d_f64[0] = (float)(Scaleform::Render::GlyphCache::GetCachedFontSize(pCache, &gp, v8, data->pRaster != 0i64)
                             * 16.0);
    v17 = (int)v16.m128d_f64[0];
    if ( (double)v17 != v16.m128d_f64[0] )
      v16.m128d_f64[0] = (double)(v17 - (_mm_movemask_pd(_mm_unpacklo_pd(v16, v16)) & 1));
    gp.FontSize = (int)v16.m128d_f64[0];
    RasterSize = data->RasterSize;
    if ( RasterSize )
      v19 = v14 | 0x200;
    else
      v19 = v14 & 0xFDFF;
    v20 = v19 & 0xFFFB;
    gp.Flags = v20;
    if ( (v20 & 1) != 0 && (v20 & 0x100) == 0 && !data->VectorSize && !RasterSize )
    {
      pFont = pFontHandle->pFont;
      if ( (pFont->Flags & 0x80) == 0
        && (float)((float)gp.BlurX * 0.0625) == 0.0
        && (float)((float)gp.BlurY * 0.0625) == 0.0 )
      {
        v22 = ((double (__fastcall *)(Scaleform::Render::Font *, _QWORD))pFont->vfptr[5].__vecDelDtor)(
                pFont,
                (unsigned __int16)glyphIndex);
        v23 = *(float *)&v22 * *(float *)&v8;
        *(float *)&v22 = ((float (__fastcall *)(Scaleform::Render::Font *))gp.pFont->pFont->vfptr[22].__vecDelDtor)(gp.pFont->pFont);
        pCache = this->pCache;
        if ( (float)((float)(v23 / *(float *)&v22) * 3.0) < (float)(int)pCache->Queue.MaxSlotHeight )
          gp.Flags |= 4u;
      }
    }
    if ( pCache->Scaleform::Render::GlyphCacheConfig::vfptr->GetParams(&pCache->Scaleform::Render::GlyphCacheConfig)->UseAutoFit
      && retaddr
      && (gp.Flags & 0xF000) == 0
      && (gp.Flags & 1) != 0
      && (gp.Flags & 2) != 0
      && *(float *)&v8 > 6.0
      && ((v24 = gp.pFont->pFont->Flags, (v24 & 0x2000) != 0) || (v24 & 0x10) != 0) )
    {
      v25 = gp.Flags | 2;
    }
    else
    {
      v25 = gp.Flags & 0xFFFD;
    }
    gp.Flags = v25;
    if ( (data->Param.ShadowParam.Flags & 0x20) != 0 )
    {
      if ( !color )
        goto LABEL_65;
    }
    else if ( !color )
    {
      if ( (v25 & 4) != 0 )
        stretch = FLOAT_2_5;
      else
        stretch = *(float *)&FLOAT_1_0;
      v27 = this->pCache;
      Glyph = Scaleform::Render::GlyphQueue::FindGlyph(&v27->Queue, &gp);
      v29 = Glyph;
      if ( Glyph )
      {
        Notifier = Scaleform::Render::GlyphQueue::CreateNotifier(&v27->Queue, Glyph, this);
        Scaleform::Render::TextMeshProvider::AddNotifier(this, Notifier);
        Scaleform::Render::TextMeshProvider::addRasterGlyph(
          this,
          storage,
          TextLayer_RasterText,
          data,
          data->mColor,
          v29,
          *(float *)&v8,
          retaddr,
          stretch);
        goto LABEL_65;
      }
      if ( gp.BlurX || gp.BlurY )
        v31 = Scaleform::Render::GlyphCache::RasterizeShadow(
                this->pCache,
                data,
                this,
                &gp,
                *(float *)&v8,
                data->pRaster);
      else
        v31 = Scaleform::Render::GlyphCache::RasterizeGlyph(this->pCache, data, this, &gp);
      if ( v31 )
      {
        Scaleform::Render::TextMeshProvider::addRasterGlyph(
          this,
          storage,
          TextLayer_RasterText,
          data,
          data->mColor,
          v31,
          *(float *)&v8,
          retaddr,
          stretch);
        goto LABEL_65;
      }
      v32 = this->pCache;
      v33 = v32->Result;
      switch ( v33 )
      {
        case Res_ShapeNotFound:
          v34 = data->FontSize * 0.25;
          v35 = data->FontSize * 0.5;
          v36 = data->NewLineY - (float)(v35 * 0.25);
          v37 = (float)(data->NewLineX + v34) + (float)(v34 * 0.5);
          v38 = (float)(data->NewLineY - v35) - (float)(v35 * 0.25);
          needsVectorShape.x1 = (float)(v34 * 0.5) + data->NewLineX;
          needsVectorShape.y1 = v38;
          needsVectorShape.x2 = v37;
          needsVectorShape.y2 = v36;
          Scaleform::Render::TextMeshProvider::addSelection(this, storage, data->mColor, &needsVectorShape);
LABEL_83:
          v39 = 1;
          goto LABEL_84;
        case Res_ShapeIsEmpty:
          goto LABEL_83;
        case Res_CacheFull:
          if ( !v32->Scaleform::Render::GlyphCacheConfig::vfptr->GetParams(&v32->Scaleform::Render::GlyphCacheConfig)->UseVectorOnFullCache )
          {
            v39 = 0;
            goto LABEL_84;
          }
          break;
        default:
          if ( (unsigned int)(v33 - 3) > 1 )
            goto LABEL_65;
          break;
      }
    }
    pShape = data->pShape;
    if ( pShape )
    {
      v41 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))pShape->vfptr[1].__vecDelDtor)(pShape);
      v42 = glyphIndexa[0];
      if ( !v41 )
      {
        Scaleform::Render::TextMeshProvider::addVectorGlyph(
          this,
          storage,
          data->mColor,
          data->pFontHandle,
          glyphIndexa[0],
          gp.Flags,
          data->FontSize,
          data->NewLineX,
          data->NewLineY);
        this->Flags |= 0x40u;
      }
      goto LABEL_66;
    }
LABEL_65:
    v42 = glyphIndexa[0];
LABEL_66:
    ShadowColor = data->Param.ShadowColor;
    if ( !ShadowColor || !v58 )
      goto LABEL_83;
    gp = data->Param.ShadowParam;
    gp.pFont = data->pFontHandle;
    v44 = data->Param.TextParam.Flags;
    if ( v60 | ((v44 & 8) != 0) )
      v45 = gp.Flags & 0xFFF4 | 8;
    else
      v45 = gp.Flags & 0xFFF4;
    if ( vars0 | ((v44 & 0x10) != 0) )
      v46 = v45 | 0x10;
    else
      v46 = v45 & 0xFFEF;
    gp.Flags = v46;
    v47 = this->pCache;
    v48 = 0i64;
    v48.m128d_f64[0] = (float)(Scaleform::Render::GlyphCache::GetCachedShadowSize(v47, v8, data->pRaster) * 16.0);
    v49 = (int)v48.m128d_f64[0];
    if ( (double)v49 != v48.m128d_f64[0] )
      v48.m128d_f64[0] = (double)(v49 - (_mm_movemask_pd(_mm_unpacklo_pd(v48, v48)) & 1));
    gp.FontSize = (int)v48.m128d_f64[0];
    gp.GlyphIndex = v42;
    v50 = Scaleform::Render::GlyphQueue::FindGlyph(&v47->Queue, &gp);
    v51 = v50;
    if ( v50 )
    {
      v52 = Scaleform::Render::GlyphQueue::CreateNotifier(&v47->Queue, v50, this);
      Scaleform::Render::TextMeshProvider::AddNotifier(this, v52);
      Scaleform::Render::TextMeshProvider::addRasterGlyph(
        this,
        storage,
        TextLayer_Shadow,
        data,
        ShadowColor,
        v51,
        *(float *)&v8,
        retaddr,
        1.0);
      goto LABEL_83;
    }
    v53 = Scaleform::Render::GlyphCache::RasterizeShadow(this->pCache, data, this, &gp, *(float *)&v8, data->pRaster);
    if ( v53 )
    {
      Scaleform::Render::TextMeshProvider::addRasterGlyph(
        this,
        storage,
        TextLayer_Shadow,
        data,
        ShadowColor,
        v53,
        *(float *)&v8,
        retaddr,
        1.0);
      goto LABEL_83;
    }
    if ( this->pCache->Result != Res_CacheFull )
      goto LABEL_83;
    v39 = 0;
LABEL_84:
    if ( node )
      (*(void (__fastcall **)(unsigned __int16 *))(*(_QWORD *)&node->Param.BlurY + 16i64))(&node->Param.BlurY);
    return v39;
  }
  if ( v9->pImage.pObject )
    Scaleform::Render::TextMeshProvider::addTextureGlyph(this, storage, v9, data, data->mColor);
  return 1;
}

// File Line: 1939
// RVA: 0x9F25F0
float __fastcall Scaleform::Render::TextMeshProvider::snapX(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::GlyphRunData *data)
{
  __m128 NewLineY_low; // xmm1
  int v3; // ecx

  NewLineY_low = (__m128)LODWORD(data->NewLineY);
  NewLineY_low.m128_f32[0] = (float)((float)((float)(NewLineY_low.m128_f32[0] * data->DirMtx.M[0][1])
                                           + (float)(data->NewLineX * data->DirMtx.M[0][0]))
                                   + data->DirMtx.M[0][3])
                           + 0.5;
  v3 = (int)NewLineY_low.m128_f32[0];
  if ( (int)NewLineY_low.m128_f32[0] != 0x80000000 && (float)v3 != NewLineY_low.m128_f32[0] )
    NewLineY_low.m128_f32[0] = (float)(v3 - (_mm_movemask_ps(_mm_unpacklo_ps(NewLineY_low, NewLineY_low)) & 1));
  return (float)((float)(NewLineY_low.m128_f32[0] * data->InvMtx.M[0][0])
               + (float)((float)((float)((float)(data->NewLineY * data->DirMtx.M[1][1])
                                       + (float)(data->NewLineX * data->DirMtx.M[1][0]))
                               + data->DirMtx.M[1][3])
                       * data->InvMtx.M[0][1]))
       + data->InvMtx.M[0][3];
}

// File Line: 1965
// RVA: 0x95CB80
__int64 __fastcall Scaleform::Render::TextMeshProvider::CalcVectorParams(
        Scaleform::Render::TextMeshLayer *layer,
        Scaleform::Render::TextMeshEntry *ent,
        Scaleform::Render::Matrix2x4<float> *scalingMtx,
        float sizeScale)
{
  __int64 v7; // r12
  __int64 v8; // rcx
  float y; // xmm1_4
  __int64 v10; // rcx
  unsigned int v11; // eax
  unsigned int v12; // edx
  float v13; // r8d
  int v14; // r10d
  int v15; // r11d
  int v16; // ebx
  int v17; // edi
  int v18; // esi
  int v19; // r14d
  int v20; // r15d
  __m128 v21; // xmm8
  Scaleform::Render::MatrixPoolImpl::HMatrix *p_M; // rdi
  Scaleform::Render::MatrixPoolImpl::HMatrix *v23; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  bool v25; // zf
  __int64 DataPageOffset; // rcx
  __int64 v27; // rcx
  float v28; // xmm9_4
  float v29; // xmm5_4
  float v30; // xmm10_4
  float v31; // xmm6_4
  float v32; // xmm7_4
  float v33; // xmm8_4
  float v34; // xmm9_4
  float v35; // xmm10_4
  Scaleform::Render::MatrixPoolImpl::HMatrix *v36; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v37; // rbx
  __int64 v38; // rcx
  __int64 v39; // rdx
  __m128 *v40; // rax
  __m128 v41; // xmm1
  unsigned int v42; // edi
  bool v43; // al
  __int64 v44; // rcx
  char v46[40]; // [rsp+28h] [rbp-79h] BYREF
  Scaleform::Render::Matrix3x4<float> v47; // [rsp+50h] [rbp-51h] BYREF
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+E8h] [rbp+47h] BYREF
  Scaleform::Render::Matrix2x4<float> *v49; // [rsp+F8h] [rbp+57h]
  __int64 **v50; // [rsp+108h] [rbp+67h]
  __int64 vars0; // [rsp+110h] [rbp+6Fh]
  void *retaddr; // [rsp+118h] [rbp+77h]

  v7 = **v50;
  v8 = *(_BYTE *)(v7 + 15) & 0xF;
  if ( (*(_BYTE *)(v7 + 15) & 0x10) != 0 )
  {
    *(float *)&v46[8] = sizeScale;
    *(_QWORD *)&v46[12] = 0i64;
    *(float *)&v46[28] = sizeScale;
    *(_DWORD *)&v46[32] = 0;
    y = ent->EntryData.VectorData.y;
    *(_QWORD *)&v46[20] = ent->EntryData.BackgroundData.BorderColor;
    *(float *)&v46[36] = y;
    v10 = 16
        * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8].Offsets[4];
    v11 = *(_DWORD *)(v10 + v7 + 16);
    v12 = *(_DWORD *)(v10 + v7 + 20);
    v13 = *(float *)(v10 + v7 + 24);
    v14 = *(_DWORD *)(v10 + v7 + 32);
    v15 = *(_DWORD *)(v10 + v7 + 36);
    v16 = *(_DWORD *)(v10 + v7 + 40);
    v17 = *(_DWORD *)(v10 + v7 + 44);
    v18 = *(_DWORD *)(v10 + v7 + 48);
    v19 = *(_DWORD *)(v10 + v7 + 52);
    v20 = *(_DWORD *)(v10 + v7 + 56);
    LODWORD(v10) = *(_DWORD *)(v10 + v7 + 60);
    *(_QWORD *)&v47.M[0][0] = __PAIR64__(v12, v11);
    v47.M[0][2] = v13;
    *(_DWORD *)v46 = v14;
    *(_DWORD *)&v46[4] = v15;
    *(_DWORD *)&v46[8] = v16;
    *(_DWORD *)&v46[12] = v17;
    *(_DWORD *)&v46[16] = v18;
    *(_DWORD *)&v46[20] = v19;
    *(_DWORD *)&v46[24] = v20;
    *(_DWORD *)&v46[28] = v10;
    v21 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v46[16], *(__m128 *)&v46[16], 0), *(__m128 *)&v46[8]),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v46[16], *(__m128 *)&v46[16], 85), *(__m128 *)&v46[24])),
            _mm_and_ps(
              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>::`2::v,
              *(__m128 *)&v46[16]));
    *(__m128 *)&v47.M[0][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&v47.M[0][0], *(__m128 *)&v47.M[0][0], 0),
                                    *(__m128 *)&v46[8]),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&v47.M[0][0], *(__m128 *)&v47.M[0][0], 85),
                                    *(__m128 *)&v46[24])),
                                _mm_and_ps(
                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>::`2::v,
                                  *(__m128 *)&v47.M[0][0]));
    *(__m128 *)v46 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v46, *(__m128 *)v46, 0), *(__m128 *)&v46[8]),
                         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v46, *(__m128 *)v46, 85), *(__m128 *)&v46[24])),
                       _mm_and_ps(
                         (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>::`2::v,
                         *(__m128 *)v46));
    *(__m128 *)&v46[16] = v21;
    p_M = (Scaleform::Render::MatrixPoolImpl::HMatrix *)&result.pHandle[5];
    if ( result.pHandle[5].pNext == &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
      v23 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
              (Scaleform::Render::MatrixPoolImpl::MatrixPool *)(vars0 + 3408),
              &result,
              &v47,
              0x10u);
      Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(p_M, v23);
      if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      {
        pHeader = result.pHandle->pHeader;
        v25 = result.pHandle->pHeader->RefCount-- == 1;
        if ( v25 )
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
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix3D(
        (Scaleform::Render::MatrixPoolImpl::HMatrix *)&result.pHandle[5],
        &v47);
    }
    scalingMtx = v49;
  }
  else
  {
    v27 = 16
        * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8].Offsets[4];
    v28 = *(float *)(v27 + v7 + 16);
    v29 = *(float *)(v27 + v7 + 20);
    v30 = *(float *)(v27 + v7 + 32);
    v31 = *(float *)(v27 + v7 + 36);
    v32 = *(float *)(v27 + v7 + 28)
        + (float)((float)(v28 * ent->EntryData.VectorData.x) + (float)(v29 * ent->EntryData.VectorData.y));
    v33 = *(float *)(v27 + v7 + 44)
        + (float)((float)(v30 * ent->EntryData.VectorData.x) + (float)(v31 * ent->EntryData.VectorData.y));
    *(float *)&v46[8] = (float)(v28 * sizeScale) + (float)(v29 * 0.0);
    *(float *)&v46[24] = (float)(v30 * sizeScale) + (float)(v31 * 0.0);
    v34 = v28 * 0.0;
    *(float *)&v46[12] = (float)(v29 * sizeScale) + v34;
    v35 = v30 * 0.0;
    *(float *)&v46[28] = (float)(v31 * sizeScale) + v35;
    *(_DWORD *)&v46[32] = 0;
    *(_DWORD *)&v46[16] = 0;
    *(float *)&v46[20] = v32 + (float)(v34 + (float)(v29 * 0.0));
    *(float *)&v46[36] = v33 + (float)(v35 + (float)(v31 * 0.0));
    p_M = &layer->M;
    if ( layer->M.pHandle == &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
      v36 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
              (Scaleform::Render::MatrixPoolImpl::MatrixPool *)(vars0 + 3408),
              &result,
              (Scaleform::Render::Matrix2x4<float> *)&v46[8],
              0);
      Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(p_M, v36);
      if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      {
        v37 = result.pHandle->pHeader;
        v25 = result.pHandle->pHeader->RefCount-- == 1;
        if ( v25 )
        {
          v38 = v37->DataPageOffset;
          *(_WORD *)((char *)&v37[1].RefCount + v38 + 2) += 16 * (unsigned __int8)v37->UnitSize;
          (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v37[1].pHandle + v38))[5].pHeader += (unsigned __int8)v37->UnitSize;
          Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v37->pHandle);
          v37->pHandle = 0i64;
        }
      }
    }
    else
    {
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(p_M, (Scaleform::Render::Matrix2x4<float> *)&v46[8]);
    }
  }
  LODWORD(result.pHandle) = ent->mColor;
  *(float *)&v46[24] = (float)BYTE2(result.pHandle) * 0.0039215689;
  *(float *)&v46[28] = (float)BYTE1(result.pHandle) * 0.0039215689;
  *(float *)&v46[32] = (float)LOBYTE(result.pHandle) * 0.0039215689;
  *(float *)&v46[36] = (float)BYTE3(result.pHandle) * 0.0039215689;
  v39 = **v50;
  if ( (*(_BYTE *)(v39 + 15) & 1) != 0 )
    v40 = (__m128 *)(v39
                   + 16
                   * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[*(_BYTE *)(v39 + 15) & 0xF].Offsets[0]
                   + 16i64);
  else
    v40 = (__m128 *)&Scaleform::Render::Cxform::Identity;
  v41 = _mm_mul_ps(*(__m128 *)&v46[24], *v40);
  *(__m128 *)&v46[8] = _mm_mul_ps((__m128)0i64, *v40);
  *(__m128 *)&v46[24] = _mm_add_ps(v40[1], v41);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(p_M, (Scaleform::Render::Cxform *)&v46[8]);
  v42 = 1;
  if ( ((unsigned __int8)retaddr & 1) != 0 )
    v42 = 65;
  if ( ((unsigned __int8)retaddr & 2) != 0 )
    v42 |= 0x80u;
  v43 = Scaleform::Render::MeshKey::CalcMatrixKey(scalingMtx, (float *)layer, 0i64);
  v44 = 3i64;
  if ( (v42 & 0x10) != 0 )
    v44 = 13i64;
  *((_DWORD *)&layer->Type + v44) = 0;
  if ( !v43 )
    v42 |= 0x8000u;
  return v42;
}

// File Line: 2007
// RVA: 0x9DED30
void __fastcall Scaleform::Render::TextMeshProvider::createVectorGlyph(
        Scaleform::Render::TextMeshProvider *this,
        unsigned int layerIdx,
        Scaleform::Render::Renderer2DImpl *ren,
        Scaleform::Render::MatrixPoolImpl::HMatrix *m)
{
  Scaleform::Render::TextMeshLayer *v6; // rsi
  Scaleform::Render::TextMeshEntry *v7; // r13
  Scaleform::Render::Font *pFont; // r14
  Scaleform::Render::GlyphCache *pCache; // rbx
  Scaleform::Render::HAL *pRenderer; // rcx
  Scaleform::Render::FontCacheHandleManager *pObject; // rcx
  Scaleform::Render::FontCacheHandle *v12; // rax
  Scaleform::Render::VectorGlyphShape *v13; // r15
  float v14; // xmm6_4
  unsigned int v15; // eax
  Scaleform::Render::MeshKey *MatchingKey; // r14
  Scaleform::Render::MeshKey *v17; // rbx
  Scaleform::Render::MeshBase *v19; // rcx
  Scaleform::Render::MeshProvider *v20; // r14
  Scaleform::Render::VectorGlyphShape *v21; // rcx
  char *v22; // rdi
  Scaleform::Render::MeshKey *v23; // r15
  Scaleform::Render::MeshBase *v24; // rcx
  Scaleform::Render::Mesh *v25; // rdi
  Scaleform::Render::Mesh *v26; // rcx
  Scaleform::Render::Matrix2x4<float> scalingMtx; // [rsp+40h] [rbp-80h] BYREF
  Scaleform::Render::GlyphRunData data; // [rsp+60h] [rbp-60h] BYREF
  int v29; // [rsp+1F8h] [rbp+138h] BYREF
  Scaleform::Render::VectorGlyphShape *v30; // [rsp+200h] [rbp+140h]
  unsigned int v31; // [rsp+210h] [rbp+150h]

  *(_QWORD *)&data.InvMtx.M[0][0] = -2i64;
  v6 = &this->Layers.Data.Data[(unsigned __int64)layerIdx];
  v7 = &this->Entries.Data.Data[v6->Start];
  *(_DWORD *)&data.Param.TextParam.BlurY = 0x100000;
  data.Param.ShadowParam.pFont = 0i64;
  *(_QWORD *)&scalingMtx.M[0][0] = 0i64;
  LODWORD(scalingMtx.M[0][2]) = 0x100000;
  *(_QWORD *)&scalingMtx.M[1][0] = 0i64;
  scalingMtx.M[1][2] = 0.0;
  *(_OWORD *)&data.Param.TextParam.pFont = 0i64;
  *(_OWORD *)&data.pFont = 0i64;
  *(_OWORD *)&data.FontSize = _xmm;
  *(__m128 *)&data.NomHeight = _xmm;
  *(_OWORD *)&data.NewLineY = _xmm;
  data.GlyphBounds = (Scaleform::Render::Rect<float>)_xmm;
  pFont = v7->EntryData.VectorData.pFont;
  *(_QWORD *)&data.Param.TextParam.BlurY = pFont;
  pCache = this->pCache;
  if ( !pCache->pFontHandleManager.pObject )
  {
    pRenderer = pCache->pRenderer;
    if ( !pRenderer
      || !((unsigned __int8 (__fastcall *)(Scaleform::Render::HAL *))pRenderer->vfptr[4].__vecDelDtor)(pRenderer) )
    {
      goto LABEL_7;
    }
    Scaleform::Render::GlyphCache::initialize(pCache);
  }
  pObject = pCache->pFontHandleManager.pObject;
  if ( !pObject )
  {
LABEL_7:
    v12 = 0i64;
    goto LABEL_8;
  }
  v12 = Scaleform::Render::FontCacheHandleManager::RegisterFont(pObject, pFont);
LABEL_8:
  data.Param.ShadowParam.pFont = v12;
  *(float *)&data.Param.ShadowParam.GlyphIndex = v7->EntryData.RasterData.Coord[3];
  memset(&data.Param.ShadowParam.Flags, 0, 20);
  LODWORD(data.Param.ShadowOffsetY) = v7->mColor;
  *((_DWORD *)&data.Param.ShadowOffsetY + 1) = v7->EntryData.BackgroundData.BorderColor;
  data.Bounds.x1 = v7->EntryData.VectorData.y;
  *(_OWORD *)&data.pFont = 0i64;
  *(_QWORD *)&data.DirMtx.M[0][0] = LODWORD(this->HeightRatio);
  LOWORD(scalingMtx.M[0][3]) = v7->EntryData.VectorData.Flags;
  v13 = Scaleform::Render::GlyphCache::CreateGlyphShape(
          this->pCache,
          &data,
          v7->EntryData.VectorData.GlyphIndex,
          0.0,
          (LOBYTE(scalingMtx.M[0][3]) & 8) != 0,
          (LOBYTE(scalingMtx.M[0][3]) & 0x10) != 0,
          LOWORD(scalingMtx.M[0][3]) >> 12,
          1);
  v30 = v13;
  LODWORD(data.DirMtx.M[0][1]) = v13->pShape.pObject->HintedSize;
  v14 = *(float *)&data.Param.ShadowParam.GlyphIndex / *(float *)&data.Param.ShadowColor;
  scalingMtx.M[0][0] = (float)(*(float *)&data.Param.ShadowParam.GlyphIndex / *(float *)&data.Param.ShadowColor)
                     * this->HeightRatio;
  *(_OWORD *)&scalingMtx.M[0][1] = 0ui64;
  scalingMtx.M[1][1] = scalingMtx.M[0][0];
  *(_QWORD *)&scalingMtx.M[1][2] = 0i64;
  v15 = Scaleform::Render::TextMeshProvider::CalcVectorParams(
          v6,
          v7,
          &scalingMtx,
          *(float *)&data.Param.ShadowParam.GlyphIndex / *(float *)&data.Param.ShadowColor);
  MatchingKey = Scaleform::Render::MeshKeyManager::CreateMatchingKey(
                  ren->pMeshKeyManager.pObject,
                  v13,
                  0,
                  v15,
                  data.InvMtx.M[1],
                  &ren->Tolerances);
  v17 = v6->pMeshKey.pObject;
  if ( v17 )
  {
    if ( v17->UseCount-- == 1 )
    {
      v19 = v17->pMesh.pObject;
      if ( !v19
        || ((unsigned __int8 (__fastcall *)(Scaleform::Render::MeshBase *))v19->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(v19)
        || (v17->Flags & 0x110) != 0 )
      {
        Scaleform::Render::MeshKeySet::DestroyKey(v17->pKeySet, v17);
      }
    }
  }
  v6->pMeshKey.pObject = MatchingKey;
  v20 = &v13->Scaleform::Render::MeshProvider;
  (*((void (__fastcall **)(Scaleform::Render::MeshProvider *))&v13->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->__vecDelDtor
   + 1))(&v13->Scaleform::Render::MeshProvider);
  v21 = v6->pShape.pObject;
  if ( v21 )
    v21->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->Release(&v21->Scaleform::Render::MeshProvider);
  v6->pShape.pObject = v13;
  v6->SizeScale = v14;
  if ( !v6->pMeshKey.pObject->pMesh.pObject )
  {
    v29 = 68;
    v22 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                    Scaleform::Memory::pGlobalHeap,
                    this,
                    240i64,
                    &v29);
    *(_QWORD *)&data.InvMtx.M[0][2] = v22;
    if ( v22 )
    {
      Scaleform::Render::MeshBase::MeshBase(
        (Scaleform::Render::MeshBase *)v22,
        ren,
        v6->pMeshKey.pObject->pKeySet,
        &scalingMtx,
        0.0,
        0,
        v31);
      *(_QWORD *)v22 = &Scaleform::Render::Mesh::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>};
      *((_QWORD *)v22 + 2) = &Scaleform::Render::Mesh::`vftable{for `Scaleform::Render::MeshStagingNode};
      *((_QWORD *)v22 + 20) = 0i64;
      *((_QWORD *)v22 + 24) = 1065353216i64;
      *((_QWORD *)v22 + 25) = 0i64;
      *((_DWORD *)v22 + 52) = 0;
      *(_QWORD *)(v22 + 212) = 1065353216i64;
      *((_DWORD *)v22 + 55) = 0;
      v22[224] = 0;
    }
    else
    {
      v22 = 0i64;
    }
    v23 = v6->pMeshKey.pObject;
    v24 = v23->pMesh.pObject;
    if ( v24 && !_InterlockedDecrement(&v24->RefCount) )
      v24->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
        v24,
        1u);
    v23->pMesh.pObject = (Scaleform::Render::MeshBase *)v22;
  }
  v25 = (Scaleform::Render::Mesh *)v6->pMeshKey.pObject->pMesh.pObject;
  if ( v25 )
    _InterlockedExchangeAdd(&v25->RefCount, 1u);
  v26 = v6->pMesh.pObject;
  if ( v26 && !_InterlockedDecrement(&v26->RefCount) )
    v26->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
      v26,
      1u);
  v6->pMesh.pObject = v25;
  v20->vfptr->Release(v20);
}

// File Line: 2062
// RVA: 0x967F10
char __fastcall Scaleform::Render::TextMeshProvider::CreateMeshData(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TextLayout *layout,
        Scaleform::Render::Renderer2DImpl *ren,
        Scaleform::Render::MatrixPoolImpl::HMatrix *m)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // r8
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rdx
  __int64 v9; // rcx
  float v10; // xmm4_4
  float v11; // xmm3_4
  float v12; // xmm5_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  char snap; // r15
  float y2; // xmm3_4
  float x2; // xmm2_4
  float y1; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  unsigned __int64 v25; // rbx
  float v26; // xmm9_4
  float v27; // xmm10_4
  float v28; // xmm8_4
  float v29; // xmm7_4
  Scaleform::Render::LinearHeap *pHeap; // r12
  float v31; // xmm6_4
  unsigned int MaxPages_high; // r13d
  char *v33; // rdx
  char MaxPages; // cl
  unsigned __int64 v35; // rsi
  size_t v36; // r8
  __int64 v37; // rbx
  float v38; // xmm0_4
  Scaleform::Render::PrimitiveFill *pObject; // r15
  char Size; // al
  unsigned __int64 v41; // rsi
  __int64 v42; // rdx
  Scaleform::Render::TmpTextMeshEntry *v43; // rcx
  __m128 v44; // xmm1
  int v45; // ecx
  __m128 v46; // xmm3
  int v47; // ecx
  Scaleform::Render::PrimitiveFill *v48; // r15
  char v49; // al
  unsigned __int64 v50; // rsi
  __int64 v51; // rdx
  Scaleform::Render::TmpTextMeshEntry *v52; // rcx
  Scaleform::Render::PrimitiveFill *v53; // r15
  char v54; // al
  unsigned __int64 v55; // rsi
  __int64 v56; // rdx
  Scaleform::Render::TmpTextMeshEntry *v57; // rcx
  unsigned int Flags; // eax
  char v59; // r14
  unsigned __int64 v60; // rsi
  Scaleform::Render::TmpTextMeshEntry *v61; // rbx
  float v62; // xmm6_4
  float v63; // xmm3_4
  float v64; // xmm2_4
  float v65; // xmm1_4
  float x1; // xmm0_4
  float v67; // xmm4_4
  float v68; // xmm2_4
  float v69; // xmm2_4
  unsigned __int64 v70; // r14
  __int64 v71; // rsi
  Scaleform::Render::MatrixPoolImpl::HMatrix *v72; // r12
  Scaleform::Render::Renderer2DImpl *v73; // r13
  Scaleform::Render::TextMeshLayer *v74; // r15
  char *v75; // rbx
  Scaleform::Render::Mesh *v76; // rcx
  unsigned __int64 v77; // r8
  Scaleform::Render::LinearHeap::PageType *v78; // rbx
  Scaleform::Render::TmpTextStorage storage; // [rsp+40h] [rbp-80h] BYREF
  Scaleform::Render::GlyphRunData data; // [rsp+C0h] [rbp+0h] BYREF
  Scaleform::Render::Matrix2x4<float> v82; // [rsp+1C0h] [rbp+100h] BYREF
  __int64 v83; // [rsp+1E0h] [rbp+120h]
  __int64 v84; // [rsp+1E8h] [rbp+128h]
  Scaleform::Render::PrimitiveFill *v85; // [rsp+1F0h] [rbp+130h]
  Scaleform::Render::Rect<float> Bounds; // [rsp+1F8h] [rbp+138h]
  Scaleform::Render::GlyphNode *v87; // [rsp+208h] [rbp+148h]
  __int64 v88; // [rsp+210h] [rbp+150h]
  __int64 v89; // [rsp+218h] [rbp+158h]
  Scaleform::Render::PrimitiveFill *v90; // [rsp+220h] [rbp+160h]
  unsigned __int64 v91; // [rsp+228h] [rbp+168h]
  unsigned __int64 v92; // [rsp+230h] [rbp+170h]
  Scaleform::Render::GlyphNode *v93; // [rsp+238h] [rbp+178h]
  __int64 v94; // [rsp+240h] [rbp+180h]
  __int64 v95; // [rsp+248h] [rbp+188h]
  Scaleform::Render::PrimitiveFill *v96; // [rsp+250h] [rbp+190h]
  unsigned __int64 v97; // [rsp+258h] [rbp+198h]
  unsigned __int64 v98; // [rsp+260h] [rbp+1A0h]
  Scaleform::Render::GlyphNode *v99; // [rsp+268h] [rbp+1A8h]
  Scaleform::Render::Matrix2x4<float> viewMatrix; // [rsp+270h] [rbp+1B0h] BYREF
  __int64 v101; // [rsp+290h] [rbp+1D0h]
  bool v102; // [rsp+358h] [rbp+298h]
  Scaleform::Render::Renderer2DImpl *prenderer; // [rsp+360h] [rbp+2A0h]
  Scaleform::Render::MatrixPoolImpl::HMatrix *other[3]; // [rsp+368h] [rbp+2A8h] BYREF
  unsigned int vars0; // [rsp+380h] [rbp+2C0h]

  v101 = -2i64;
  this->pRenderer = ren;
  storage.LHeap.pHeap = Scaleform::Memory::pGlobalHeap;
  storage.LHeap.Granularity = 0x2000i64;
  memset(&storage.LHeap.pPagePool, 0, 24);
  storage.Entries.pHeap = (Scaleform::Render::LinearHeap *)&storage;
  memset(&storage.Entries.Size, 0, 32);
  storage.Layers.pHeap = (Scaleform::Render::LinearHeap *)&storage;
  memset(&storage.Layers.Size, 0, 32);
  this->Flags &= 0xFFFFFF1F;
  pHandle = m->pHandle;
  pHeader = m->pHandle->pHeader;
  v9 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[4];
  v10 = *(float *)&pHeader[v9 + 1].pHandle;
  viewMatrix.M[0][0] = v10;
  v11 = *((float *)&pHeader[v9 + 1].pHandle + 1);
  *(_QWORD *)&viewMatrix.M[0][1] = *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&pHeader[v9 + 1].pHandle
                                                                                      + 4);
  viewMatrix.M[0][3] = *(float *)&pHeader[v9 + 1].DataPageOffset;
  v12 = *(float *)&pHeader[v9 + 2].pHandle;
  viewMatrix.M[1][0] = v12;
  v13 = *((float *)&pHeader[v9 + 2].pHandle + 1);
  *(_QWORD *)&viewMatrix.M[1][1] = *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&pHeader[v9 + 2].pHandle
                                                                                      + 4);
  viewMatrix.M[1][3] = *(float *)&pHeader[v9 + 2].DataPageOffset;
  snap = 0;
  if ( (pHeader->Format & 0x10) == 0 )
  {
    v14 = (float)(v13 * 0.0) + v12;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v11 * 0.0) + v10) & _xmm) <= 0.000001
      || COERCE_FLOAT(LODWORD(v14) & _xmm) <= 0.000001 )
    {
      snap = 1;
    }
  }
  LOBYTE(storage.LHeap.pHeap) = snap;
  *(_OWORD *)&data.DirMtx.M[0][0] = _xmm;
  *(__m128 *)&data.DirMtx.M[1][0] = _xmm;
  *(_OWORD *)&data.InvMtx.M[0][0] = _xmm;
  *(__m128 *)&data.InvMtx.M[1][0] = _xmm;
  *(_OWORD *)&data.Param.TextParam.pFont = *(_OWORD *)&layout->Param.TextParam.pFont;
  *(_OWORD *)&data.Param.TextParam.BlurY = *(_OWORD *)&layout->Param.TextParam.BlurY;
  *(_OWORD *)&data.Param.ShadowParam.GlyphIndex = *(_OWORD *)&layout->Param.ShadowParam.GlyphIndex;
  *(_OWORD *)&data.Param.ShadowColor = *(_OWORD *)&layout->Param.ShadowColor;
  y2 = layout->Bounds.y2;
  x2 = layout->Bounds.x2;
  y1 = layout->Bounds.y1;
  data.Bounds.x1 = layout->Bounds.x1;
  data.Bounds.y1 = y1;
  data.Bounds.x2 = x2;
  data.Bounds.y2 = y2;
  memset(&data.pFont, 0, 52);
  data.GlyphBounds = 0i64;
  data.DirMtx = *(Scaleform::Render::Matrix2x4<float> *)&pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHandle->pHeader->Format & 0xF].Offsets[4]
                                                                        + 1].pHandle;
  *(_OWORD *)&v82.M[0][0] = _xmm;
  *(__m128 *)&v82.M[1][0] = _xmm;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v82, &data.DirMtx);
  data.InvMtx = v82;
  data.HeightRatio = Scaleform::Render::TextMeshProvider::calcHeightRatio(
                       m,
                       (Scaleform::Render::Matrix4x4<float> *)other[1],
                       (Scaleform::Render::Viewport *)other[2]);
  data.HintedNomHeight = 0;
  this->HeightRatio = data.HeightRatio;
  if ( (m->pHandle->pHeader->Format & 0x10) != 0 )
  {
    data.Param.TextParam.Flags &= 0xFFFCu;
    data.Param.ShadowParam.Flags &= 0xFFFCu;
  }
  v19 = layout->Bounds.y2;
  v20 = layout->Bounds.x2;
  v21 = layout->Bounds.y1;
  this->Bounds.x1 = layout->Bounds.x1;
  this->Bounds.y1 = v21;
  this->Bounds.x2 = v20;
  this->Bounds.y2 = v19;
  this->Flags &= ~8u;
  v22 = layout->ClipBox.y2;
  v23 = layout->ClipBox.x2;
  v24 = layout->ClipBox.y1;
  this->ClipBox.x1 = layout->ClipBox.x1;
  this->ClipBox.y1 = v24;
  this->ClipBox.x2 = v23;
  this->ClipBox.y2 = v22;
  if ( v23 > this->ClipBox.x1 && v22 > v24 )
    this->Flags |= 8u;
  this->Flags |= 0x10u;
  v25 = 0i64;
  v102 = 1;
  v26 = *((float *)&storage.Entries.Size + 1);
  v27 = *(float *)&storage.Entries.Size;
  v28 = *((float *)&storage.Entries.pHeap + 1);
  v29 = *(float *)&storage.Entries.pHeap;
  pHeap = storage.Entries.pHeap;
  v31 = *((float *)&storage.LHeap.MaxPages + 1);
  MaxPages_high = HIDWORD(storage.LHeap.MaxPages);
  do
  {
    if ( v25 >= layout->DataSize )
      break;
    v33 = layout->Data.Data.Data;
    LOBYTE(storage.LHeap.MaxPages) = v33[v25];
    MaxPages = storage.LHeap.MaxPages;
    v35 = v25 + 1;
    v36 = TextLayout_RecordSizes[LOBYTE(storage.LHeap.MaxPages)] - 1;
    if ( TextLayout_RecordSizes[LOBYTE(storage.LHeap.MaxPages)] != 1 )
    {
      v37 = (unsigned int)v36;
      memmove((char *)&storage.LHeap.MaxPages + 1, &v33[v35], v36);
      v35 += v37;
      v26 = *((float *)&storage.Entries.Size + 1);
      v27 = *(float *)&storage.Entries.Size;
      v28 = *((float *)&storage.Entries.pHeap + 1);
      v29 = *(float *)&storage.Entries.pHeap;
      pHeap = storage.Entries.pHeap;
      v31 = *((float *)&storage.LHeap.MaxPages + 1);
      MaxPages_high = HIDWORD(storage.LHeap.MaxPages);
      MaxPages = storage.LHeap.MaxPages;
    }
    v25 = v35;
    if ( !v35 )
      break;
    switch ( MaxPages )
    {
      case 0:
        v102 = (storage.LHeap.MaxPages & 0x100) != 0
            || Scaleform::Render::TextMeshProvider::addGlyph(
                 this,
                 &storage,
                 &data,
                 WORD1(storage.LHeap.MaxPages),
                 (storage.LHeap.MaxPages & 0x200) != 0,
                 (storage.LHeap.MaxPages & 0x400) != 0,
                 snap,
                 vars0);
        v38 = data.NewLineX + v31;
        goto LABEL_48;
      case 1:
        data.mColor = MaxPages_high;
        break;
      case 2:
        LODWORD(v83) = 0;
        HIDWORD(v83) = storage.Entries.Size;
        LODWORD(v84) = MaxPages_high;
        pObject = this->pCache->pSolidFill.pObject;
        v85 = pObject;
        ++pObject->RefCount;
        Bounds = data.Bounds;
        LODWORD(v87) = storage.Entries.pHeap;
        Size = storage.Entries.Size;
        v41 = storage.Entries.Size >> 6;
        if ( storage.Entries.Size >> 6 >= storage.Entries.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(
            &storage.Entries,
            storage.Entries.Size >> 6);
          Size = storage.Entries.Size;
        }
        v42 = Size & 0x3F;
        v43 = storage.Entries.Pages[v41];
        *(_QWORD *)&v43[v42].LayerType = v83;
        *(_QWORD *)&v43[v42].mColor = v84;
        v43[v42].pFill = pObject;
        *(Scaleform::Render::Rect<float> *)v43[v42].EntryData.RasterData.Coord = Bounds;
        v43[v42].EntryData.RasterData.pGlyph = v87;
        ++storage.Entries.Size;
        break;
      case 3:
        data.NewLineX = v31;
        data.NewLineY = v29;
        if ( snap && (data.pFont && (data.pFont->Flags & 0x80) != 0 || (data.Param.TextParam.Flags & 1) != 0) )
        {
          v44 = (__m128)LODWORD(data.DirMtx.M[1][1]);
          v44.m128_f32[0] = (float)((float)((float)(data.DirMtx.M[1][1] * v29) + (float)(data.DirMtx.M[1][0] * v31))
                                  + data.DirMtx.M[1][3])
                          + 0.5;
          v45 = (int)v44.m128_f32[0];
          if ( (int)v44.m128_f32[0] != 0x80000000 && (float)v45 != v44.m128_f32[0] )
            v44.m128_f32[0] = (float)(v45 - (_mm_movemask_ps(_mm_unpacklo_ps(v44, v44)) & 1));
          data.NewLineY = (float)((float)(data.InvMtx.M[1][1] * v44.m128_f32[0])
                                + (float)((float)((float)((float)(data.DirMtx.M[0][1] * v29)
                                                        + (float)(data.DirMtx.M[0][0] * v31))
                                                + data.DirMtx.M[0][3])
                                        * data.InvMtx.M[1][0]))
                        + data.InvMtx.M[1][3];
        }
        break;
      case 4:
        data.pFont = (Scaleform::Render::Font *)pHeap;
        data.pFontHandle = Scaleform::Render::GlyphCache::RegisterFont(this->pCache, (Scaleform::Render::Font *)pHeap);
        data.FontSize = v31;
        data.TexHeight = ((float (__fastcall *)(Scaleform::Render::LinearHeap *))pHeap->pHeap->Info.Desc.HeapId)(pHeap);
        if ( snap && data.pFont && (data.pFont->Flags & 0x80) != 0 )
        {
          v46 = (__m128)LODWORD(data.DirMtx.M[1][1]);
          v46.m128_f32[0] = (float)((float)((float)(data.DirMtx.M[1][1] * data.NewLineY)
                                          + (float)(data.DirMtx.M[1][0] * data.NewLineX))
                                  + data.DirMtx.M[1][3])
                          + 0.5;
          v47 = (int)v46.m128_f32[0];
          if ( (int)v46.m128_f32[0] != 0x80000000 && (float)v47 != v46.m128_f32[0] )
            v46.m128_f32[0] = (float)(v47 - (_mm_movemask_ps(_mm_unpacklo_ps(v46, v46)) & 1));
          data.NewLineY = (float)((float)(data.InvMtx.M[1][1] * v46.m128_f32[0])
                                + (float)(data.InvMtx.M[1][0]
                                        * (float)((float)((float)(data.DirMtx.M[0][1] * data.NewLineY)
                                                        + (float)(data.DirMtx.M[0][0] * data.NewLineX))
                                                + data.DirMtx.M[0][3])))
                        + data.InvMtx.M[1][3];
        }
        break;
      case 5:
        LODWORD(v88) = 1;
        HIDWORD(v88) = storage.Entries.Size;
        LODWORD(v89) = MaxPages_high;
        v48 = this->pCache->pSolidFill.pObject;
        v90 = v48;
        ++v48->RefCount;
        v91 = __PAIR64__(LODWORD(v28), LODWORD(v29));
        v92 = __PAIR64__(LODWORD(v26), LODWORD(v27));
        v49 = storage.Entries.Size;
        v50 = storage.Entries.Size >> 6;
        if ( storage.Entries.Size >> 6 >= storage.Entries.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(
            &storage.Entries,
            storage.Entries.Size >> 6);
          v49 = storage.Entries.Size;
        }
        v51 = v49 & 0x3F;
        v52 = storage.Entries.Pages[v50];
        *(_QWORD *)&v52[v51].LayerType = v88;
        *(_QWORD *)&v52[v51].mColor = v89;
        v52[v51].pFill = v48;
        v52[v51].EntryData.VectorData.pFont = (Scaleform::Render::Font *)v91;
        *(_QWORD *)&v52[v51].EntryData.MaskData.Coord[2] = v92;
        v52[v51].EntryData.RasterData.pGlyph = v93;
        ++storage.Entries.Size;
        break;
      case 6:
        Scaleform::Render::TextMeshProvider::addUnderline(
          this,
          &storage,
          storage.Entries.Size,
          (Scaleform::Render::TextUnderlineStyle)WORD1(storage.LHeap.MaxPages),
          v31,
          v29,
          v28);
        this->Flags |= 0x80u;
        break;
      case 7:
        LODWORD(v94) = 10;
        HIDWORD(v94) = storage.Entries.Size;
        LODWORD(v95) = MaxPages_high;
        v53 = this->pCache->pSolidFill.pObject;
        v96 = v53;
        ++v53->RefCount;
        v97 = __PAIR64__(LODWORD(v28), LODWORD(v29));
        v98 = __PAIR64__(LODWORD(v26), LODWORD(v27));
        v54 = storage.Entries.Size;
        v55 = storage.Entries.Size >> 6;
        if ( storage.Entries.Size >> 6 >= storage.Entries.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(
            &storage.Entries,
            storage.Entries.Size >> 6);
          v54 = storage.Entries.Size;
        }
        v56 = v54 & 0x3F;
        v57 = storage.Entries.Pages[v55];
        *(_QWORD *)&v57[v56].LayerType = v94;
        *(_QWORD *)&v57[v56].mColor = v95;
        v57[v56].pFill = v53;
        v57[v56].EntryData.VectorData.pFont = (Scaleform::Render::Font *)v97;
        *(_QWORD *)&v57[v56].EntryData.MaskData.Coord[2] = v98;
        v57[v56].EntryData.RasterData.pGlyph = v99;
        ++storage.Entries.Size;
        break;
      case 8:
        Scaleform::Render::TextMeshProvider::addImage(
          this,
          &storage,
          &data,
          (Scaleform::Render::Image *)pHeap,
          v27,
          v26,
          *(float *)&storage.Entries.NumPages,
          snap);
        v38 = data.NewLineX + *((float *)&storage.Entries.NumPages + 1);
LABEL_48:
        data.NewLineX = v38;
        break;
      default:
        break;
    }
    snap = (char)storage.LHeap.pHeap;
  }
  while ( v102 );
  Flags = this->Flags;
  if ( (Flags & 8) != 0 && (Flags & 0xC0) != 0 )
  {
    Scaleform::Render::TextMeshProvider::addMask(this, &storage);
    v59 = 1;
    *(_QWORD *)&this->ClearBox.x1 = 0i64;
    *(_QWORD *)&this->ClearBox.x2 = 0i64;
    v60 = 0i64;
    if ( storage.Entries.Size )
    {
      while ( 1 )
      {
        v61 = &storage.Entries.Pages[v60 >> 6][v60 & 0x3F];
        *(_OWORD *)&storage.LHeap.pPagePool = 0i64;
        if ( v61->LayerType == 4 || v61->LayerType == 5 || v61->LayerType == 7 )
          break;
        if ( v61->LayerType == 8 )
        {
          v62 = v61->EntryData.RasterData.Coord[3]
              / ((float (__fastcall *)(Scaleform::Render::Font *))v61->EntryData.VectorData.pFont->vfptr[22].__vecDelDtor)(v61->EntryData.VectorData.pFont);
          ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, Scaleform::Render::LinearHeap::PageType **))v61->EntryData.VectorData.pFont->vfptr[7].__vecDelDtor)(
            v61->EntryData.VectorData.pFont,
            v61->EntryData.VectorData.GlyphIndex,
            &storage.LHeap.pPagePool);
          *(float *)&storage.LHeap.pPagePool = (float)(v62 * *(float *)&storage.LHeap.pPagePool)
                                             + v61->EntryData.VectorData.x;
          *((float *)&storage.LHeap.pPagePool + 1) = (float)(v62 * *((float *)&storage.LHeap.pPagePool + 1))
                                                   + v61->EntryData.VectorData.y;
          *(float *)&storage.LHeap.pLastPage = (float)(v62 * *(float *)&storage.LHeap.pLastPage)
                                             + v61->EntryData.VectorData.x;
          *((float *)&storage.LHeap.pLastPage + 1) = (float)(v62 * *((float *)&storage.LHeap.pLastPage + 1))
                                                   + v61->EntryData.VectorData.y;
          v61->LayerType = 12;
          v63 = *((float *)&storage.LHeap.pLastPage + 1);
          v64 = *(float *)&storage.LHeap.pLastPage;
          v65 = *((float *)&storage.LHeap.pPagePool + 1);
          x1 = *(float *)&storage.LHeap.pPagePool;
LABEL_59:
          if ( x1 < v64 && v65 < v63 )
          {
            if ( v59 )
            {
              this->ClearBox.x2 = v64;
              this->ClearBox.y2 = v63;
            }
            else
            {
              if ( this->ClearBox.x1 <= x1 )
                x1 = this->ClearBox.x1;
              v67 = this->ClearBox.x2;
              if ( v67 <= v64 )
                v67 = v64;
              if ( this->ClearBox.y1 <= v65 )
                v65 = this->ClearBox.y1;
              v68 = this->ClearBox.y2;
              if ( v68 <= v63 )
                v68 = v63;
              this->ClearBox.x2 = v67;
              this->ClearBox.y2 = v68;
            }
            this->ClearBox.y1 = v65;
            this->ClearBox.x1 = x1;
            v59 = 0;
          }
        }
        if ( v61->LayerType == 9 )
          v61->LayerType = 13;
        if ( ++v60 >= storage.Entries.Size )
          goto LABEL_76;
      }
      x1 = v61->EntryData.RasterData.Coord[0];
      *(float *)&storage.LHeap.pPagePool = x1;
      v65 = v61->EntryData.RasterData.Coord[1];
      *((float *)&storage.LHeap.pPagePool + 1) = v65;
      v64 = v61->EntryData.RasterData.Coord[2];
      *(float *)&storage.LHeap.pLastPage = v64;
      v63 = v61->EntryData.RasterData.Coord[3];
      *((float *)&storage.LHeap.pLastPage + 1) = v63;
      goto LABEL_59;
    }
LABEL_76:
    v69 = 1.0 / this->HeightRatio;
    this->ClearBox.x1 = this->ClearBox.x1 - v69;
    this->ClearBox.y1 = this->ClearBox.y1 - v69;
    this->ClearBox.x2 = v69 + this->ClearBox.x2;
    this->ClearBox.y2 = v69 + this->ClearBox.y2;
    this->Flags |= 0x100u;
  }
  Scaleform::Render::TextMeshProvider::UnpinSlots(this);
  this->Flags &= ~0x10u;
  Scaleform::Render::TextMeshProvider::sortEntries(this, &storage);
  v70 = 0i64;
  if ( this->Layers.Data.Size )
  {
    v71 = 0i64;
    v72 = other[0];
    v73 = prenderer;
    do
    {
      v74 = this->Layers.Data.Data;
      if ( ((v74[v71].Type - 8) & 0xFFFFFFFB) != 0 )
      {
        Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(&v74[v71].M, v72);
        LODWORD(other[0]) = 68;
        v75 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                        Scaleform::Memory::pGlobalHeap,
                        this,
                        240i64,
                        other);
        prenderer = (Scaleform::Render::Renderer2DImpl *)v75;
        if ( v75 )
        {
          Scaleform::Render::MeshBase::MeshBase(
            (Scaleform::Render::MeshBase *)v75,
            v73,
            this,
            &viewMatrix,
            0.0,
            v70,
            vars0);
          *(_QWORD *)v75 = &Scaleform::Render::Mesh::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>};
          *((_QWORD *)v75 + 2) = &Scaleform::Render::Mesh::`vftable{for `Scaleform::Render::MeshStagingNode};
          *((_QWORD *)v75 + 20) = 0i64;
          *((_QWORD *)v75 + 24) = 1065353216i64;
          *((_QWORD *)v75 + 25) = 0i64;
          *((_DWORD *)v75 + 52) = 0;
          *(_QWORD *)(v75 + 212) = 1065353216i64;
          *((_DWORD *)v75 + 55) = 0;
          v75[224] = 0;
        }
        else
        {
          v75 = 0i64;
        }
        v76 = v74[v71].pMesh.pObject;
        if ( v76 && !_InterlockedDecrement(&v76->RefCount) )
          v76->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
            v76,
            1u);
        v74[v71].pMesh.pObject = (Scaleform::Render::Mesh *)v75;
      }
      else
      {
        Scaleform::Render::TextMeshProvider::createVectorGlyph(this, v70, v73, v72, vars0);
        this->Flags |= 0x40u;
      }
      ++v70;
      ++v71;
    }
    while ( v70 < this->Layers.Data.Size );
  }
  this->Flags |= 0x20u;
  v77 = storage.LHeap.MaxPages;
  if ( storage.LHeap.MaxPages )
  {
    v78 = &storage.LHeap.pPagePool[storage.LHeap.MaxPages - 1];
    do
    {
      storage.LHeap.MaxPages = --v77;
      if ( v78->pStart )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))storage.LHeap.pHeap->vfptr->Free)(storage.LHeap.pHeap);
        v77 = storage.LHeap.MaxPages;
      }
      --v78;
    }
    while ( v77 );
    storage.LHeap.MaxPages = -1i64;
    storage.LHeap.pHeap->vfptr->Free(storage.LHeap.pHeap, storage.LHeap.pPagePool);
  }
  return 1;
}

