// File Line: 50
// RVA: 0x159C480
__int64 dynamic_initializer_for__Scaleform::Render::ImageGlyphVertex::Format__()
{
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::ImageGlyphVertex::Format__);
}

// File Line: 64
// RVA: 0x981A70
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::VectorGlyphShape::GetIdentityBounds(Scaleform::Render::VectorGlyphShape *this, Scaleform::Render::Rect<float> *result)
{
  result->x1 = *(float *)&this->pRaster.pObject;
  result->y1 = *((float *)&this->pRaster.pObject + 1);
  result->x2 = *((float *)&this->pRaster + 2);
  result->y2 = *((float *)&this->pRaster + 3);
  return result;
}

// File Line: 126
// RVA: 0x982370
bool __fastcall Scaleform::Render::VectorGlyphShape::GetData(Scaleform::Render::VectorGlyphShape *this, Scaleform::Render::MeshBase *mesh, Scaleform::Render::VertexOutput *verOut, unsigned int meshGenFlags)
{
  Scaleform::Render::Renderer2DImpl *v4; // rbx
  Scaleform::Render::VectorGlyphShape *v5; // rdi
  char v6; // si
  Scaleform::Render::VertexOutput *v7; // r15
  Scaleform::Render::Matrix2x4<float> *v8; // r12
  Scaleform::Render::MeshGenerator *v10; // r13
  __m128 v11; // xmm2
  float v12; // xmm13_4
  unsigned int v13; // eax
  float v14; // xmm0_4
  signed __int64 v15; // rbx
  unsigned int v16; // esi
  int v17; // eax
  Scaleform::Render::FontCacheHandle *v18; // rcx
  int v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm8_4
  float v22; // xmm14_4
  float v23; // xmm15_4
  int v24; // xmm0_4
  Scaleform::Render::FontCacheHandle *v25; // rax
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
  float v40; // xmm0_4
  float v41; // xmm7_4
  float y4; // xmm7_4
  int v43; // ecx
  Scaleform::Render::VertexOutput v44; // rax
  bool v45; // r12
  unsigned int v46; // er14
  unsigned int j; // edi
  char *v48; // rdx
  char *v49; // r8
  __int64 v50; // r9
  __m128 v51; // xmm1
  signed int v52; // ecx
  __m128 v53; // xmm2
  signed int v54; // ecx
  unsigned __int64 v55; // rcx
  unsigned int v56; // er14
  int v57; // edi
  __int64 v58; // ST20_8
  __int64 x3; // [rsp+20h] [rbp-E0h]
  float v60; // [rsp+60h] [rbp-A0h]
  float v61; // [rsp+64h] [rbp-9Ch]
  float v62; // [rsp+68h] [rbp-98h]
  float v63; // [rsp+6Ch] [rbp-94h]
  float v64; // [rsp+70h] [rbp-90h]
  float v65; // [rsp+74h] [rbp-8Ch]
  int v66; // [rsp+80h] [rbp-80h]
  float v67; // [rsp+90h] [rbp-70h]
  int v68; // [rsp+98h] [rbp-68h]
  __int64 v69; // [rsp+9Ch] [rbp-64h]
  __int64 v70; // [rsp+A4h] [rbp-5Ch]
  __int64 v71; // [rsp+ACh] [rbp-54h]
  __int64 v72; // [rsp+B4h] [rbp-4Ch]
  __int64 v73; // [rsp+BCh] [rbp-44h]
  int v74; // [rsp+C4h] [rbp-3Ch]
  int v75; // [rsp+C8h] [rbp-38h]
  char v76; // [rsp+CCh] [rbp-34h]
  int v77; // [rsp+D0h] [rbp-30h]
  int v78; // [rsp+D4h] [rbp-2Ch]
  int v79; // [rsp+E0h] [rbp-20h]
  int v80; // [rsp+E4h] [rbp-1Ch]
  Scaleform::Render::VertexFormat *v81; // [rsp+E8h] [rbp-18h]
  __int64 v82; // [rsp+F0h] [rbp-10h]
  __int64 v83; // [rsp+F8h] [rbp-8h]
  Scaleform::Render::ToleranceParams param; // [rsp+100h] [rbp+0h]
  Scaleform::Render::Matrix2x4<float> v85; // [rsp+150h] [rbp+50h]
  char v86; // [rsp+170h] [rbp+70h]
  Scaleform::Render::Matrix2x4<float> v87; // [rsp+190h] [rbp+90h]
  unsigned __int16 v88[384]; // [rsp+1B0h] [rbp+B0h]
  char v89; // [rsp+4B0h] [rbp+3B0h]
  char v90; // [rsp+4B4h] [rbp+3B4h]
  char v91; // [rsp+AB0h] [rbp+9B0h]
  char v92; // [rsp+AB4h] [rbp+9B4h]
  float v93; // [rsp+1590h] [rbp+1490h]
  float v94; // [rsp+1598h] [rbp+1498h]

  v4 = mesh->pRenderer2D;
  v5 = this;
  v6 = meshGenFlags;
  v7 = verOut;
  v8 = &mesh->ViewMatrix;
  if ( ((unsigned __int8 (*)(void))this->Key.pFont->pPrev->pNext)() )
    return Scaleform::Render::VectorGlyphShape::generateNullVectorMesh(
             (Scaleform::Render::VectorGlyphShape *)((char *)v5 - 16),
             v7);
  v10 = &v4->MeshGen;
  Scaleform::Render::MeshGenerator::Clear(&v4->MeshGen);
  v12 = FLOAT_0_5;
  *(_OWORD *)&param.Epsilon = *(_OWORD *)&v4->Tolerances.Epsilon;
  v11 = *(__m128 *)&param.Epsilon;
  *(_OWORD *)&param.FillLowerScale = *(_OWORD *)&v4->Tolerances.FillLowerScale;
  *(_OWORD *)&param.StrokeLowerScale = *(_OWORD *)&v4->Tolerances.StrokeLowerScale;
  *(_OWORD *)&param.Scale9LowerScale = *(_OWORD *)&v4->Tolerances.Scale9LowerScale;
  *(_QWORD *)&param.MinDet3D = *(_QWORD *)&v4->Tolerances.MinDet3D;
  v13 = v4->Tolerances.CurveRecursionLimit;
  param.CollinearityTolerance = param.CollinearityTolerance * 2.0;
  param.CurveTolerance = COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) * 2.0;
  param.CurveRecursionLimit = v13;
  if ( !(v6 & 1) || v6 & 2 )
    v14 = 0.0;
  else
    v14 = param.EdgeAAScale * 0.5;
  v4->MeshGen.mTess.EdgeAAWidth = v14;
  v15 = (signed __int64)&v4->MeshGen.mTess;
  v16 = 0;
  *(_BYTE *)(v15 + 944) = v14 > 0.0;
  *(_DWORD *)(v15 + 24) = 0;
  *(_BYTE *)(v15 + 33) = 0;
  v17 = ((__int64 (*)(void))v5->Key.pFont->pPrev[1].pManager)();
  v18 = v5->Key.pFont;
  v19 = SLODWORD(v8->M[1][0]);
  v20 = v8->M[1][1];
  v21 = v8->M[1][3];
  v69 = 0i64;
  v70 = 0i64;
  v71 = 0i64;
  v22 = v8->M[0][0];
  v23 = v8->M[0][1];
  v75 = (signed int)FLOAT_1_0;
  v68 = v17;
  v72 = 0i64;
  v73 = 0i64;
  v24 = LODWORD(v8->M[0][3]);
  v66 = v19;
  v93 = v20;
  v74 = 0;
  v76 = 0;
  v25 = v18->pPrev;
  v67 = *(float *)&v24;
  v94 = v21;
  v26 = 1;
  v27 = ((__int64 (__fastcall *)(Scaleform::Render::FontCacheHandle *, int *, float *, int *))v25[2].pPrev)(
          v18,
          &v68,
          &v60,
          &v77);
  if ( v27 )
  {
    v28 = v67;
    do
    {
      if ( !v26 && v27 == 2 )
        break;
      v26 = 0;
      if ( v77 == v78 )
      {
        ((void (__fastcall *)(Scaleform::Render::FontCacheHandle *, int *))v5->Key.pFont->pPrev[2].pManager)(
          v5->Key.pFont,
          &v68);
      }
      else
      {
        v29 = (float)(v61 * v20) + (float)(*(float *)&v19 * v60);
        v60 = (float)((float)(v61 * v23) + (float)(v60 * v22)) + v28;
        v61 = v29 + v21;
        (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v15 + 32i64))(&v10->mTess);
        for ( i = ((__int64 (__fastcall *)(Scaleform::Render::FontCacheHandle *, int *, float *))v5->Key.pFont->pPrev[2].pNext)(
                    v5->Key.pFont,
                    &v68,
                    &v60);
              i;
              i = ((__int64 (__fastcall *)(Scaleform::Render::FontCacheHandle *, int *, float *))v5->Key.pFont->pPrev[2].pNext)(
                    v5->Key.pFont,
                    &v68,
                    &v60) )
        {
          switch ( i )
          {
            case 1:
              v31 = (float)(v61 * v20) + (float)(*(float *)&v19 * v60);
              v60 = (float)((float)(v61 * v23) + (float)(v60 * v22)) + v28;
              v61 = v31 + v21;
              (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v15 + 32i64))(&v10->mTess);
              break;
            case 2:
              v32 = *(float *)&v19 * v60;
              v60 = (float)((float)(v61 * v23) + (float)(v60 * v22)) + v28;
              v61 = (float)((float)(v61 * v20) + v32) + v21;
              y3 = (float)((float)(v63 * v20) + (float)(*(float *)&v19 * v62)) + v21;
              v62 = (float)((float)(v63 * v23) + (float)(v62 * v22)) + v28;
              v63 = y3;
              Scaleform::Render::TessellateQuadCurve(
                (Scaleform::Render::TessBase *)&v10->mTess.vfptr,
                &param,
                v60,
                v61,
                v62,
                y3);
              break;
            case 3:
              v35 = (float)(v61 * v20) + (float)(*(float *)&v19 * v60);
              v60 = (float)((float)(v61 * v23) + (float)(v60 * v22)) + v28;
              v34 = v60;
              y2 = v35 + v21;
              v61 = y2;
              v37 = (float)((float)(v63 * v20) + (float)(*(float *)&v19 * v62)) + v21;
              v62 = (float)((float)(v63 * v23) + (float)(v62 * v22)) + v28;
              v38 = v62;
              v63 = v37;
              v40 = *(float *)&v19 * v64;
              v41 = (float)(v65 * v93) + (float)(*(float *)&v19 * v64);
              v64 = (float)((float)(v65 * v23) + (float)(v64 * v22)) + v28;
              x4 = v64;
              y4 = v41 + v94;
              v65 = y4;
              (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v15 + 16i64))(&v10->mTess);
              (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v15 + 24i64))(&v10->mTess);
              Scaleform::Render::TessellateCubicRecursively(
                (Scaleform::Render::TessBase *)&v10->mTess.vfptr,
                &param,
                (float)(param.CurveTolerance * 0.25) * (float)(param.CurveTolerance * 0.25),
                v40,
                v40,
                v34,
                y2,
                v38,
                v37,
                x4,
                y4,
                0);
              v19 = v66;
              v20 = v93;
              v21 = v94;
              break;
          }
        }
        (*(void (__fastcall **)(Scaleform::Render::Tessellator *, signed __int64, _QWORD))(*(_QWORD *)v15 + 48i64))(
          &v10->mTess,
          1i64,
          0i64);
      }
      v27 = ((__int64 (__fastcall *)(Scaleform::Render::FontCacheHandle *, int *, float *, int *))v5->Key.pFont->pPrev[2].pPrev)(
              v5->Key.pFont,
              &v68,
              &v60,
              &v77);
    }
    while ( v27 );
    v12 = FLOAT_0_5;
  }
  Scaleform::Render::Tessellator::Tessellate(&v10->mTess, 0);
  if ( (*(unsigned int (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v15 + 80i64))(&v10->mTess)
    && (*(unsigned int (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v15 + 72i64))(&v10->mTess) )
  {
    *(_OWORD *)&v85.M[0][0] = _xmm;
    *(__m128 *)&v85.M[1][0] = _xmm;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v85, v8);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *, Scaleform::Render::Matrix2x4<float> *))(*(_QWORD *)v15 + 56i64))(
      &v10->mTess,
      &v85);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *, Scaleform::Render::Matrix2x4<float> *))(*(_QWORD *)v15 + 64i64))(
      &v10->mTess,
      &v87);
    v79 = (*(__int64 (__fastcall **)(Scaleform::Render::Tessellator *, _QWORD))(*(_QWORD *)v15 + 88i64))(
            &v10->mTess,
            0i64);
    v43 = 3
        * (unsigned __int64)(*(__int64 (__fastcall **)(Scaleform::Render::Tessellator *, _QWORD))(*(_QWORD *)v15 + 96i64))(
                              &v10->mTess,
                              0i64);
    v81 = &Scaleform::Render::VertexXY16iCF32::Format;
    v44.vfptr = v7->vfptr;
    v80 = v43;
    v82 = 0i64;
    v83 = 0i64;
    v45 = v44.vfptr->BeginOutput(v7, (Scaleform::Render::VertexOutput::Fill *)&v79, 1u, &v87);
    if ( v45 )
    {
      (*(void (__fastcall **)(Scaleform::Render::Tessellator *, _QWORD, char *))(*(_QWORD *)v15 + 104i64))(
        &v10->mTess,
        0i64,
        &v86);
      v46 = 0;
      for ( j = (*(__int64 (__fastcall **)(Scaleform::Render::Tessellator *, char *, char *, signed __int64))(*(_QWORD *)v15 + 112i64))(
                  &v10->mTess,
                  &v86,
                  &v91,
                  128i64);
            j;
            j = (*(__int64 (__fastcall **)(Scaleform::Render::Tessellator *, char *, char *, signed __int64))(*(_QWORD *)v15 + 112i64))(
                  &v10->mTess,
                  &v86,
                  &v91,
                  128i64) )
      {
        if ( j )
        {
          v48 = &v90;
          v49 = &v92;
          v50 = j;
          do
          {
            v51 = (__m128)*((unsigned int *)v49 - 1);
            if ( v51.m128_f32[0] >= 0.0 )
              v51.m128_f32[0] = v51.m128_f32[0] + v12;
            else
              v51.m128_f32[0] = v51.m128_f32[0] - v12;
            v52 = (signed int)v51.m128_f32[0];
            if ( (signed int)v51.m128_f32[0] != 0x80000000 && (float)v52 != v51.m128_f32[0] )
              v51.m128_f32[0] = (float)(v52 - (_mm_movemask_ps(_mm_unpacklo_ps(v51, v51)) & 1));
            v53 = (__m128)*(unsigned int *)v49;
            *((_WORD *)v48 - 2) = (signed int)v51.m128_f32[0];
            if ( v53.m128_f32[0] >= 0.0 )
              v53.m128_f32[0] = v53.m128_f32[0] + v12;
            else
              v53.m128_f32[0] = v53.m128_f32[0] - v12;
            v54 = (signed int)v53.m128_f32[0];
            if ( (signed int)v53.m128_f32[0] != 0x80000000 && (float)v54 != v53.m128_f32[0] )
              v53.m128_f32[0] = (float)(v54 - (_mm_movemask_ps(_mm_unpacklo_ps(v53, v53)) & 1));
            v55 = *((unsigned __int16 *)v49 + 6);
            *(_DWORD *)v48 = -1;
            v48 += 12;
            v49 += 20;
            *((_WORD *)v48 - 7) = (signed int)v53.m128_f32[0];
            *(v48 - 8) = Scaleform::Render::Factors[v55 & 3];
            *(v48 - 7) = Scaleform::Render::Factors[(v55 >> 2) & 3];
            --v50;
          }
          while ( v50 );
        }
        LODWORD(x3) = j;
        v7->vfptr->SetVertices(v7, 0, v46, &v89, x3);
        v46 += j;
      }
      v56 = (*(__int64 (__fastcall **)(Scaleform::Render::Tessellator *, _QWORD))(*(_QWORD *)v15 + 96i64))(
              &v10->mTess,
              HIDWORD(v83));
      if ( v56 )
      {
        do
        {
          v57 = 128;
          if ( v16 + 128 > v56 )
          {
            v57 = v56 - v16;
            if ( v56 == v16 )
              break;
          }
          LODWORD(x3) = v57;
          (*(void (__fastcall **)(Scaleform::Render::Tessellator *, _QWORD, unsigned __int16 *, _QWORD, __int64))(*(_QWORD *)v15 + 120i64))(
            &v10->mTess,
            HIDWORD(v83),
            v88,
            v16,
            x3);
          LODWORD(v58) = 3 * v57;
          v7->vfptr->SetIndices(v7, 0, 3 * v16, v88, v58);
          v16 += v57;
        }
        while ( v16 < v56 );
      }
      v7->vfptr->EndOutput(v7);
    }
  }
  else
  {
    v45 = Scaleform::Render::VectorGlyphShape::generateNullVectorMesh(
            (Scaleform::Render::VectorGlyphShape *)((char *)v5 - 16),
            v7);
  }
  Scaleform::Render::MeshGenerator::Clear(v10);
  return v45;
}

// File Line: 274
// RVA: 0x9838D0
void __fastcall Scaleform::Render::VectorGlyphShape::GetFillData(Scaleform::Render::VectorGlyphShape *this, Scaleform::Render::FillData *data, unsigned int layer, unsigned int fillIndex)
{
  Scaleform::Render::GradientData *v4; // [rsp+8h] [rbp-20h]

  data->Type = 3;
  data->FillMode.Fill = 0;
  LODWORD(v4) = 0;
  data->PrimFill = 3;
  data->pGradient = v4;
  data->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
}

// File Line: 313
// RVA: 0x946150
void __fastcall Scaleform::Render::TextMeshProvider::TextMeshProvider(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::GlyphCache *cache)
{
  Scaleform::Render::TextMeshProvider *v2; // r9
  Scaleform::MemoryHeap *v3; // r8
  Scaleform::ArrayDH_POD<Scaleform::Render::TextNotifier *,2,Scaleform::ArrayDefaultPolicy> *v4; // rax
  Scaleform::MemoryHeap *v5; // rcx
  Scaleform::ArrayDH<Scaleform::Render::TextMeshEntry,2,Scaleform::ArrayDefaultPolicy> *v6; // rax
  Scaleform::MemoryHeap *v7; // rcx
  Scaleform::ArrayDH<Scaleform::Render::TextMeshLayer,2,Scaleform::ArrayDefaultPolicy> *v8; // rax

  v2 = this;
  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider::`vftable';
  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::TextMeshProvider::`vftable';
  this->pCache = cache;
  this->Flags = 0;
  v3 = cache->pHeap;
  v4 = &this->Notifiers;
  v4->Data.Data = 0i64;
  v4->Data.Size = 0i64;
  v4->Data.Policy.Capacity = 0i64;
  this->Notifiers.Data.pHeap = v3;
  v5 = cache->pHeap;
  v6 = &v2->Entries;
  v6->Data.Data = 0i64;
  v6->Data.Size = 0i64;
  v6->Data.Policy.Capacity = 0i64;
  v2->Entries.Data.pHeap = v5;
  v7 = cache->pHeap;
  v8 = &v2->Layers;
  v8->Data.Data = 0i64;
  v8->Data.Size = 0i64;
  v8->Data.Policy.Capacity = 0i64;
  v2->Layers.Data.pHeap = v7;
  v2->PinCount = 0i64;
  v2->pBundle = 0i64;
  v2->pBundleEntry = 0i64;
  v2->HeightRatio = 0.0;
  *(_QWORD *)&v2->ClipBox.x1 = 0i64;
  *(_QWORD *)&v2->ClipBox.x2 = 0i64;
  *(_QWORD *)&v2->ClearBox.x1 = 0i64;
  *(_QWORD *)&v2->ClearBox.x2 = 0i64;
  *(_QWORD *)&v2->Bounds.x1 = 0i64;
  *(_QWORD *)&v2->Bounds.x2 = 0i64;
  v2->pRenderer = 0i64;
  v2->ClearBounds.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
}

// File Line: 317
// RVA: 0x94D2B0
void __fastcall Scaleform::Render::TextMeshProvider::~TextMeshProvider(Scaleform::Render::TextMeshProvider *this)
{
  Scaleform::Render::TextMeshProvider *v1; // rbx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v2; // rdi
  Scaleform::Render::MatrixPoolImpl::EntryHandle v3; // rdi
  bool v4; // zf
  __int64 v5; // rcx

  v1 = this;
  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::TextMeshProvider::`vftable';
  Scaleform::Render::TextMeshProvider::Clear(this);
  v2 = v1->ClearBounds.pHandle;
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
  Scaleform::ArrayDataDH<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataDH<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy>(&v1->Layers.Data);
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy> *)&v1->Entries.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Notifiers.Data.Data);
  v1->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider::`vftable';
}

// File Line: 323
// RVA: 0x960490
void __fastcall Scaleform::Render::TextMeshProvider::ClearEntries(Scaleform::Render::TextMeshProvider *this, __int64 a2, Scaleform::Render::TextNotifier *a3)
{
  unsigned __int64 v3; // rdi
  Scaleform::Render::TextMeshProvider *v4; // rbx
  unsigned __int64 v5; // r9
  Scaleform::Render::GlyphCache *v6; // rdx
  __int64 v7; // rsi
  Scaleform::Render::TextMeshEntry *v8; // rcx
  Scaleform::Render::Font *v9; // rcx

  v3 = 0i64;
  v4 = this;
  v5 = 0i64;
  if ( this->Notifiers.Data.Size )
  {
    do
    {
      v6 = this->pCache;
      a3 = this->Notifiers.Data.Data[++v5 - 1];
      a3->pPrev->pNext = a3->pNext;
      a3->pNext->pPrev = a3->pPrev;
      a3->pPrev = (Scaleform::Render::TextNotifier *)-1i64;
      a3->pNext = (Scaleform::Render::TextNotifier *)-1i64;
      a3->pPrev = (Scaleform::Render::TextNotifier *)v6->Queue.Notifiers.FirstEmptySlot;
      v6->Queue.Notifiers.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,75> >::NodeType *)a3;
    }
    while ( v5 < this->Notifiers.Data.Size );
  }
  ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TextNotifier **, Scaleform::Render::TextNotifier *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
    Scaleform::Memory::pGlobalHeap,
    this->Notifiers.Data.Data,
    a3,
    v5);
  v4->Notifiers.Data.Data = 0i64;
  v4->Notifiers.Data.Size = 0i64;
  v4->Notifiers.Data.Policy.Capacity = 0i64;
  if ( v4->Entries.Data.Size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v4->Entries.Data.Data;
      if ( !((v8[v7].LayerType - 8) & 0xFFFB) )
      {
        v9 = v8[v7].EntryData.VectorData.pFont;
        if ( !_InterlockedDecrement(&v9->RefCount) )
        {
          if ( v9 )
            v9->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, 1u);
        }
      }
      ++v3;
      ++v7;
    }
    while ( v3 < v4->Entries.Data.Size );
  }
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy>::ClearAndRelease((Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy> *)&v4->Entries.Data.Data);
  v4->Flags &= 0xFFFFFE1F;
}

// File Line: 345
// RVA: 0x960030
void __fastcall Scaleform::Render::TextMeshProvider::Clear(Scaleform::Render::TextMeshProvider *this)
{
  Scaleform::Render::TextMeshProvider *v1; // rbx
  unsigned int v2; // ecx
  unsigned int v3; // ecx
  Scaleform::Render::TextPrimitiveBundle *v4; // rcx

  v1 = this;
  v2 = this->Flags;
  if ( v2 & 6 )
  {
    v3 = v2 & 0xFFFFFFFD;
    v1->Flags = v3;
    if ( (v3 & 6) == 4 )
    {
      v1->Flags = v3 & 0xFFFFFFFB;
      Scaleform::Render::TextMeshProvider::UnpinSlots(v1);
    }
    v1->pPrev->pNext = v1->pNext;
    v1->pNext->pPrev = v1->pPrev;
    v1->pPrev = (Scaleform::Render::TextMeshProvider *)-1i64;
    v1->pNext = (Scaleform::Render::TextMeshProvider *)-1i64;
  }
  v4 = v1->pBundle;
  if ( v4 )
  {
    Scaleform::Render::TextPrimitiveBundle::removeEntryFromLayers(v4, v1->pBundleEntry);
    v1->pBundle = 0i64;
    v1->pBundleEntry = 0i64;
  }
  Scaleform::Render::TextMeshProvider::ClearEntries(v1);
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy>::ClearAndRelease((Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy> *)&v1->Entries.Data.Data);
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy>::ClearAndRelease((Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy> *)&v1->Layers.Data.Data);
}

// File Line: 389
// RVA: 0x988080
Scaleform::Render::Fence *__fastcall Scaleform::Render::TextMeshProvider::GetLatestFence(Scaleform::Render::TextMeshProvider *this)
{
  Scaleform::Render::TextMeshProvider *v1; // rax
  __int64 v2; // rbx
  unsigned __int64 v3; // r12
  __int64 v4; // r13
  Scaleform::Render::Mesh *v5; // r15
  unsigned __int64 v6; // rbp
  unsigned __int64 v7; // rax
  signed __int64 *v8; // rsi
  signed __int64 v9; // rcx
  signed __int64 v10; // rcx
  __int64 v11; // r8
  signed __int64 v12; // r14
  __int64 v13; // r14
  __int64 v14; // rax
  bool v15; // zf
  _QWORD *v16; // rcx
  __int64 v17; // rdi
  _QWORD *v18; // rcx
  _QWORD *v19; // rcx
  __int64 v20; // rdi
  _QWORD *v21; // rcx
  Scaleform::Render::TextMeshProvider *v23; // [rsp+70h] [rbp+8h]

  v23 = this;
  v1 = this;
  v2 = 0i64;
  v3 = 0i64;
  if ( this->Layers.Data.Size )
  {
    v4 = 0i64;
    do
    {
      v5 = v1->Layers.Data.Data[v4].pMesh.pObject;
      if ( v5 )
      {
        v6 = 0i64;
        v7 = v5->CacheItems.Size;
        if ( v7 )
        {
          v8 = (signed __int64 *)&v5->CacheItems.8;
          do
          {
            if ( v7 <= 2 )
              v9 = (signed __int64)&v5->CacheItems.8;
            else
              v9 = *v8;
            if ( *(_QWORD *)(*(_QWORD *)(v9 + 8 * v6) + 80i64) )
            {
              if ( !v2
                || (v7 <= 2 ? (v10 = (signed __int64)&v5->CacheItems.8) : (v10 = *v8),
                    (v11 = **(_QWORD **)(*(_QWORD *)(v10 + 8 * v6) + 80i64)) != 0
                 && (!*(_QWORD *)v2 || *(_QWORD *)(v11 + 24) > *(_QWORD *)(*(_QWORD *)v2 + 24i64))) )
              {
                if ( v7 <= 2 )
                  v12 = (signed __int64)&v5->CacheItems.8;
                else
                  v12 = *v8;
                v13 = *(_QWORD *)(v12 + 8 * v6);
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
            v7 = v5->CacheItems.Size;
          }
          while ( v6 < v7 );
        }
      }
      ++v3;
      ++v4;
      v1 = v23;
    }
    while ( v3 < v23->Layers.Data.Size );
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
void __fastcall Scaleform::Render::TextMeshProvider::AddNotifier(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::TextNotifier *notifier)
{
  unsigned __int64 v2; // rax
  Scaleform::ArrayDH_POD<Scaleform::Render::TextNotifier *,2,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::TextNotifier *v5; // rsi
  unsigned __int64 v6; // r8
  Scaleform::Render::TextNotifier **v7; // rax

  if ( notifier )
  {
    v2 = this->Notifiers.Data.Size;
    v3 = &this->Notifiers;
    v4 = v2 + 1;
    v5 = notifier;
    if ( v2 + 1 >= v2 )
    {
      if ( v4 > this->Notifiers.Data.Policy.Capacity )
      {
        v6 = v4 + (v4 >> 2);
        goto LABEL_7;
      }
    }
    else if ( v4 < this->Notifiers.Data.Policy.Capacity >> 1 )
    {
      v6 = v2 + 1;
LABEL_7:
      Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Notifiers,
        this->Notifiers.Data.pHeap,
        v6);
      goto LABEL_8;
    }
LABEL_8:
    v7 = v3->Data.Data;
    v3->Data.Size = v4;
    v7[v4 - 1] = v5;
    ++v5->pSlot->PinCount;
  }
}

// File Line: 456
// RVA: 0x9BBC40
void __fastcall Scaleform::Render::TextMeshProvider::UnpinSlots(Scaleform::Render::TextMeshProvider *this)
{
  Scaleform::Render::TextMeshProvider *v1; // rbp
  Scaleform::Render::Fence *v2; // rax
  Scaleform::Render::Fence *v3; // rbx
  unsigned __int64 v4; // rsi
  Scaleform::Render::GlyphSlot *v5; // rdi
  Scaleform::Render::FenceImpl *v6; // r8
  Scaleform::Render::Fence *v7; // rax
  Scaleform::Render::FenceImpl *v8; // rax
  Scaleform::Render::Fence *v9; // rcx
  bool v10; // zf
  Scaleform::Render::FenceImpl *v11; // rcx
  Scaleform::Render::RenderSync *v12; // rdi
  Scaleform::Render::FenceImpl *v13; // rcx

  v1 = this;
  v2 = Scaleform::Render::TextMeshProvider::GetLatestFence(this);
  v3 = v2;
  if ( v2 )
    ++v2->RefCount;
  v4 = 0i64;
  if ( v1->Notifiers.Data.Size )
  {
    do
    {
      v5 = v1->Notifiers.Data.Data[v4]->pSlot;
      if ( v3 )
      {
        if ( v3->HasData )
        {
          v6 = v3->Data;
          if ( v3->Data )
          {
            if ( v6->Parent )
            {
              if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::RenderSync *, signed __int64, unsigned __int64))v6->RSContext->vfptr[4].__vecDelDtor)(
                     v6->RSContext,
                     1i64,
                     v6->APIHandle) )
              {
                v7 = v5->SlotFence.pObject;
                if ( !v7 || v3->Data && ((v8 = v7->Data) == 0i64 || v3->Data->FenceID > v8->FenceID) )
                {
                  ++v3->RefCount;
                  v9 = v5->SlotFence.pObject;
                  if ( v9 )
                    Scaleform::Render::Fence::Release(v9);
                  v5->SlotFence.pObject = v3;
                }
              }
            }
          }
        }
      }
      --v5->PinCount;
      ++v4;
    }
    while ( v4 < v1->Notifiers.Data.Size );
  }
  if ( v3 )
  {
    v10 = v3->RefCount-- == 1;
    if ( v10 )
    {
      v11 = v3->Data;
      if ( v3->HasData )
      {
        v12 = v11->RSContext;
        ((void (__fastcall *)(Scaleform::Render::FenceImpl *, unsigned __int64))v11->RSContext->FenceFrameAlloc.pHeapOrPtr)(
          v11,
          v11->APIHandle);
        v13 = v3->Data;
        v13->RSContext = (Scaleform::Render::RenderSync *)v12->FenceImplAlloc.FirstEmptySlot;
        v12->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v13;
        v3->Data = (Scaleform::Render::FenceImpl *)v12->FenceAlloc.FirstEmptySlot;
        v12->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)v3;
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
signed __int64 __fastcall Scaleform::Render::TextMeshProvider::GetMeshUseStatus(Scaleform::Render::TextMeshProvider *this)
{
  Scaleform::Render::MeshUseStatus v1; // esi
  Scaleform::Render::TextMeshProvider *v2; // rbx
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // rax
  Scaleform::Render::Mesh *v6; // rcx
  Scaleform::Render::MeshUseStatus v7; // eax

  v1 = 0;
  v2 = this;
  if ( this->PinCount )
    return 5i64;
  v4 = 0i64;
  if ( ((unsigned int (*)(void))this->vfptr->GetLayerCount)() )
  {
    do
    {
      v5 = (unsigned __int64)&v2->Layers.Data.Data[(unsigned __int64)(unsigned int)v4];
      if ( *(_DWORD *)v5 > 4 )
        break;
      if ( *(_DWORD *)v5 >= 2 )
      {
        v6 = *(Scaleform::Render::Mesh **)(v5 + 16);
        if ( v6 )
        {
          v7 = Scaleform::Render::Mesh::GetUseStatus(v6);
          if ( v7 > v1 )
            v1 = v7;
        }
      }
      ++v4;
    }
    while ( v4 < v2->vfptr->GetLayerCount((Scaleform::Render::MeshProvider *)&v2->vfptr) );
  }
  return (unsigned int)v1;
}

// File Line: 493
// RVA: 0x9F0ED0
void __fastcall Scaleform::Render::TextMeshProvider::setMeshData(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::TessBase *tess, Scaleform::Render::VertexOutput *verOut, const unsigned int *colors, Scaleform::Render::TextMeshProvider::VertexCountType *verCount)
{
  Scaleform::Render::TessBase *v5; // r14
  Scaleform::Render::VertexOutput *v6; // rbp
  const unsigned int *v7; // rbx
  unsigned int i; // edi
  char *v9; // r10
  unsigned __int16 *v10; // r8
  __int64 v11; // r11
  __m128 v12; // xmm1
  signed int v13; // ecx
  __m128 v14; // xmm2
  signed int v15; // ecx
  unsigned __int64 v16; // r9
  unsigned int v17; // edi
  unsigned int v18; // esi
  int v19; // ebx
  __int64 v20; // ST20_8
  _QWORD v21[2]; // [rsp+20h] [rbp-9E8h]
  char v22; // [rsp+30h] [rbp-9D8h]
  char v23; // [rsp+50h] [rbp-9B8h]
  char v24; // [rsp+1D0h] [rbp-838h]
  char v25; // [rsp+1D4h] [rbp-834h]
  char v26; // [rsp+4D0h] [rbp-538h]
  char v27; // [rsp+4D4h] [rbp-534h]

  v5 = tess;
  v6 = verOut;
  v7 = colors;
  tess->vfptr->GetMesh(tess, 0, (Scaleform::Render::TessMesh *)&v22);
  for ( i = v5->vfptr->GetVertices(v5, (Scaleform::Render::TessMesh *)&v22, (Scaleform::Render::TessVertex *)&v26, 64u);
        i;
        i = v5->vfptr->GetVertices(v5, (Scaleform::Render::TessMesh *)&v22, (Scaleform::Render::TessVertex *)&v26, 64u) )
  {
    if ( i )
    {
      v9 = &v25;
      v10 = (unsigned __int16 *)&v27;
      v11 = i;
      do
      {
        v12 = (__m128)*((unsigned int *)v10 - 1);
        if ( v12.m128_f32[0] >= 0.0 )
          v12.m128_f32[0] = v12.m128_f32[0] + 0.5;
        else
          v12.m128_f32[0] = v12.m128_f32[0] - 0.5;
        v13 = (signed int)v12.m128_f32[0];
        if ( (signed int)v12.m128_f32[0] != 0x80000000 && (float)v13 != v12.m128_f32[0] )
          v12.m128_f32[0] = (float)(v13 - (_mm_movemask_ps(_mm_unpacklo_ps(v12, v12)) & 1));
        v14 = (__m128)*(unsigned int *)v10;
        *((_WORD *)v9 - 2) = (signed int)v12.m128_f32[0];
        if ( v14.m128_f32[0] >= 0.0 )
          v14.m128_f32[0] = v14.m128_f32[0] + 0.5;
        else
          v14.m128_f32[0] = v14.m128_f32[0] - 0.5;
        v15 = (signed int)v14.m128_f32[0];
        if ( (signed int)v14.m128_f32[0] != 0x80000000 && (float)v15 != v14.m128_f32[0] )
          v14.m128_f32[0] = (float)(v15 - (_mm_movemask_ps(_mm_unpacklo_ps(v14, v14)) & 1));
        v16 = v10[6];
        *((_WORD *)v9 - 1) = (signed int)v14.m128_f32[0];
        if ( v16 & 0x10 )
          *(_DWORD *)v9 = ((v7[v10[4] - 1] | v7[v10[5] - 1]) >> 1) & 0x7F7F7F7F;
        else
          *(_DWORD *)v9 = v7[v10[((v16 >> 5) & 1) + 4] - 1];
        v9 += 12;
        v10 += 10;
        *(v9 - 8) = Scaleform::Render::Factors[v16 & 3];
        *(v9 - 7) = Scaleform::Render::Factors[((unsigned __int64)(unsigned __int16)v16 >> 2) & 3];
        --v11;
      }
      while ( v11 );
    }
    LODWORD(v21[0]) = i;
    v6->vfptr->SetVertices(v6, 0, verCount->VStart, &v24, v21[0]);
    verCount->VStart += i;
  }
  v17 = 0;
  v18 = v5->vfptr->GetMeshTriangleCount(v5, 0);
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
      LODWORD(v21[0]) = v19;
      v5->vfptr->GetTrianglesI16(v5, 0, (unsigned __int16 *)&v23, v17, v21[0]);
      LODWORD(v20) = 3 * v19;
      v6->vfptr->SetIndices(v6, 0, 3 * verCount->IStart, (unsigned __int16 *)&v23, v20);
      verCount->IStart += v19;
      v17 += v19;
    }
    while ( v17 < v18 );
  }
}

// File Line: 553
// RVA: 0x9E5930
__int64 __fastcall Scaleform::Render::TextMeshProvider::generateSelection(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::Renderer2DImpl *ren, Scaleform::Render::VertexOutput *verOut, Scaleform::Render::TextMeshLayer *layer)
{
  Scaleform::Render::TextMeshLayer *v4; // r12
  Scaleform::Render::VertexOutput *v5; // r15
  Scaleform::Render::Renderer2DImpl *v6; // rbx
  Scaleform::Render::TextMeshProvider *v7; // rsi
  Scaleform::Render::MeshGenerator *v8; // rdi
  Scaleform::Render::Tessellator *v9; // r14
  float v10; // xmm0_4
  float v11; // xmm0_4
  unsigned int v12; // er13
  float *v13; // rdi
  signed __int64 v14; // rax
  signed __int64 v15; // rbx
  Scaleform::Render::TextMeshEntry *v16; // r15
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm8_4
  float v20; // xmm9_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm7_4
  float v31; // xmm1_4
  float v32; // xmm6_4
  Scaleform::Render::VertexOutput *v33; // rbx
  unsigned __int8 v34; // r15
  unsigned __int64 v35; // rax
  char **v36; // rbx
  unsigned __int64 v37; // rax
  char **v38; // rbx
  unsigned __int64 v39; // rax
  char **v40; // rbx
  unsigned __int64 v41; // rax
  char **v42; // rbx
  Scaleform::Render::TextMeshProvider::VertexCountType *verCount; // [rsp+20h] [rbp-A8h]
  unsigned int v45; // [rsp+30h] [rbp-98h]
  int v46; // [rsp+34h] [rbp-94h]
  Scaleform::Render::VertexFormat *v47; // [rsp+38h] [rbp-90h]
  __int64 v48; // [rsp+40h] [rbp-88h]
  Scaleform::ArrayStaticBuffPOD<unsigned long,16,2> v49; // [rsp+48h] [rbp-80h]
  __int128 v50; // [rsp+A8h] [rbp-20h]
  __int128 v51; // [rsp+B8h] [rbp-10h]
  __int128 v52; // [rsp+C8h] [rbp+0h]
  __int128 v53; // [rsp+D8h] [rbp+10h]
  __int64 v54; // [rsp+E8h] [rbp+20h]
  unsigned int v55; // [rsp+F0h] [rbp+28h]
  char v56; // [rsp+F8h] [rbp+30h]
  Scaleform::Render::TextMeshProvider::VertexCountType v57; // [rsp+1A0h] [rbp+D8h]
  Scaleform::Render::VertexOutput *verOuta; // [rsp+1A8h] [rbp+E0h]
  Scaleform::Render::Matrix2x4<float> *m; // [rsp+1B8h] [rbp+F0h]
  int vars0; // [rsp+1C0h] [rbp+F8h]

  *(_QWORD *)&v49.Static[4] = -2i64;
  v4 = layer;
  v5 = verOut;
  v6 = ren;
  v7 = this;
  v8 = &ren->MeshGen;
  v57 = (Scaleform::Render::TextMeshProvider::VertexCountType)&ren->MeshGen;
  Scaleform::Render::MeshGenerator::Clear(&ren->MeshGen);
  v9 = &v8->mTess;
  v9->FillRule = 0;
  v9->StrokerMode = 0;
  v10 = v6->Tolerances.Epsilon;
  v9->Epsilon = v10;
  v9->HasEpsilon = v10 > 0.0;
  v9->IntersectionEpsilon = v6->Tolerances.IntersectionEpsilon;
  v49.pHeap = Scaleform::Memory::pGlobalHeap;
  v49.Size = 0i64;
  v49.Reserved = 16i64;
  v49.Data = v49.Static;
  v50 = *(_OWORD *)&v6->Tolerances.Epsilon;
  v51 = *(_OWORD *)&v6->Tolerances.FillLowerScale;
  v52 = *(_OWORD *)&v6->Tolerances.StrokeLowerScale;
  v53 = *(_OWORD *)&v6->Tolerances.Scale9LowerScale;
  v54 = *(_QWORD *)&v6->Tolerances.MinDet3D;
  v55 = v6->Tolerances.CurveRecursionLimit;
  if ( !(vars0 & 1) || vars0 & 2 )
    v11 = 0.0;
  else
    v11 = *((float *)&v53 + 2) * 0.5;
  v8->mTess.EdgeAAWidth = v11;
  v8->mTess.EdgeAAFlag = v11 > 0.0;
  v12 = 0;
  if ( v4->Count > 0 )
  {
    v13 = (float *)m;
    do
    {
      v14 = v12 + v4->Start;
      v15 = v14;
      v16 = v7->Entries.Data.Data;
      v17 = v16[v14].EntryData.RasterData.Coord[3];
      v18 = v16[v14].EntryData.RasterData.Coord[2];
      v19 = v16[v14].EntryData.RasterData.Coord[1];
      v20 = v16[v14].EntryData.RasterData.Coord[0];
      if ( v7->Flags & 8 )
      {
        v21 = v7->ClipBox.y2;
        v22 = v7->ClipBox.x2;
        v23 = v7->ClipBox.y1;
        v24 = v7->ClipBox.x1;
      }
      else
      {
        v21 = v7->Bounds.y2;
        v22 = v7->Bounds.x2;
        v23 = v7->Bounds.y1;
        v24 = v7->Bounds.x1;
      }
      if ( v17 >= v23 && v21 >= v19 && v22 >= v20 && v18 >= v24 )
      {
        if ( v20 <= v24 )
          v20 = v24;
        if ( v18 > v22 )
          v18 = v22;
        if ( v19 <= v23 )
          v19 = v23;
        if ( v17 > v21 )
          v17 = v21;
        if ( v20 < v18 && v19 < v17 )
        {
          v25 = (float)((float)(v19 * v13[5]) + (float)(v20 * v13[4])) + v13[7];
          v26 = (float)((float)(v20 * *v13) + (float)(v19 * v13[1])) + v13[3];
          ((void (__fastcall *)(Scaleform::Render::Tessellator *))v9->vfptr->AddVertex)(v9);
          v27 = (float)((float)(v18 * v13[4]) + (float)(v19 * v13[5])) + v13[7];
          v28 = (float)((float)(v18 * *v13) + (float)(v19 * v13[1])) + v13[3];
          ((void (__fastcall *)(Scaleform::Render::Tessellator *))v9->vfptr->AddVertex)(v9);
          v29 = (float)((float)(v17 * v13[5]) + (float)(v18 * v13[4])) + v13[7];
          v30 = (float)((float)(v18 * *v13) + (float)(v17 * v13[1])) + v13[3];
          ((void (__fastcall *)(Scaleform::Render::Tessellator *))v9->vfptr->AddVertex)(v9);
          v31 = (float)((float)(v20 * *v13) + (float)(v17 * v13[1])) + v13[3];
          v32 = (float)((float)(v17 * v13[5]) + (float)(v20 * v13[4])) + v13[7];
          ((void (__fastcall *)(Scaleform::Render::Tessellator *))v9->vfptr->AddVertex)(v9);
        }
      }
      Scaleform::ArrayStaticBuffPOD<unsigned int,16,2>::PushBack(&v49, &v16[v15].mColor);
      v9->vfptr->ClosePath((Scaleform::Render::TessBase *)&v9->vfptr);
      ++v12;
      LOBYTE(verCount) = 0;
      v9->vfptr->FinalizePath((Scaleform::Render::TessBase *)&v9->vfptr, 0, v12, 0, (bool)verCount);
    }
    while ( v12 < v4->Count );
    v8 = (Scaleform::Render::MeshGenerator *)v57;
    v5 = verOuta;
  }
  Scaleform::Render::Tessellator::Tessellate(v9, 0);
  if ( v9->vfptr->GetMeshCount((Scaleform::Render::TessBase *)&v9->vfptr)
    && v9->vfptr->GetVertexCount((Scaleform::Render::TessBase *)&v9->vfptr) )
  {
    *(_OWORD *)&v49.Size = _xmm;
    *(__m128 *)v49.Static = _xmm;
    Scaleform::Render::Matrix2x4<float>::SetInverse((Scaleform::Render::Matrix2x4<float> *)&v49.Size, m);
    v9->vfptr->Transform((Scaleform::Render::TessBase *)&v9->vfptr, (Scaleform::Render::Matrix2x4<float> *)&v49.Size);
    ((void (__fastcall *)(Scaleform::Render::Tessellator *, char *))v9->vfptr->StretchTo)(v9, &v56);
    v45 = v9->vfptr->GetMeshVertexCount((Scaleform::Render::TessBase *)&v9->vfptr, 0);
    v46 = 3 * (unsigned __int64)v9->vfptr->GetMeshTriangleCount((Scaleform::Render::TessBase *)&v9->vfptr, 0);
    v47 = &Scaleform::Render::VertexXY16iCF32::Format;
    v48 = 0i64;
    v49.pHeap = 0i64;
    v33 = verOuta;
    v34 = verOuta->vfptr->BeginOutput(
            verOuta,
            (Scaleform::Render::VertexOutput::Fill *)&v45,
            1u,
            (Scaleform::Render::Matrix2x4<float> *)&v56);
    if ( v34 )
    {
      v57 = 0i64;
      Scaleform::Render::TextMeshProvider::setMeshData(
        v7,
        (Scaleform::Render::TessBase *)&v9->vfptr,
        v33,
        v49.Data,
        &v57);
      v33->vfptr->EndOutput(v33);
    }
  }
  else
  {
    v34 = Scaleform::Render::VectorGlyphShape::generateNullVectorMesh((Scaleform::Render::VectorGlyphShape *)v7, v5);
  }
  (*((void (__fastcall **)(Scaleform::Render::Tessellator *))&v9->vfptr->__vecDelDtor + 1))(v9);
  (*((void (**)(void))&v8->mStroker.vfptr->__vecDelDtor + 1))();
  (*((void (**)(void))&v8->mStrokeSorter.vfptr->__vecDelDtor + 1))();
  (*((void (**)(void))&v8->mHairliner.vfptr->__vecDelDtor + 1))();
  (*((void (**)(void))&v8->mStrokerAA.vfptr->__vecDelDtor + 1))();
  v35 = v8->Heap1.MaxPages;
  if ( v35 )
  {
    v36 = &v8->Heap1.pPagePool->pStart + 3 * v35 - 3;
    do
    {
      --v8->Heap1.MaxPages;
      if ( *v36 )
        ((void (*)(void))v8->Heap1.pHeap->vfptr->Free)();
      v36 -= 3;
    }
    while ( v8->Heap1.MaxPages );
    --v8->Heap1.MaxPages;
    v8->Heap1.pHeap->vfptr->Free(v8->Heap1.pHeap, v8->Heap1.pPagePool);
  }
  v8->Heap1.pLastPage = 0i64;
  v8->Heap1.pPagePool = 0i64;
  v8->Heap1.MaxPages = 0i64;
  v37 = v8->Heap2.MaxPages;
  if ( v37 )
  {
    v38 = &v8->Heap2.pPagePool->pStart + 3 * v37 - 3;
    do
    {
      --v8->Heap2.MaxPages;
      if ( *v38 )
        ((void (*)(void))v8->Heap2.pHeap->vfptr->Free)();
      v38 -= 3;
    }
    while ( v8->Heap2.MaxPages );
    --v8->Heap2.MaxPages;
    v8->Heap2.pHeap->vfptr->Free(v8->Heap2.pHeap, v8->Heap2.pPagePool);
  }
  v8->Heap2.pLastPage = 0i64;
  v8->Heap2.pPagePool = 0i64;
  v8->Heap2.MaxPages = 0i64;
  v39 = v8->Heap3.MaxPages;
  if ( v39 )
  {
    v40 = &v8->Heap3.pPagePool->pStart + 3 * v39 - 3;
    do
    {
      --v8->Heap3.MaxPages;
      if ( *v40 )
        ((void (*)(void))v8->Heap3.pHeap->vfptr->Free)();
      v40 -= 3;
    }
    while ( v8->Heap3.MaxPages );
    --v8->Heap3.MaxPages;
    v8->Heap3.pHeap->vfptr->Free(v8->Heap3.pHeap, v8->Heap3.pPagePool);
  }
  v8->Heap3.pLastPage = 0i64;
  v8->Heap3.pPagePool = 0i64;
  v8->Heap3.MaxPages = 0i64;
  v41 = v8->Heap4.MaxPages;
  if ( v41 )
  {
    v42 = &v8->Heap4.pPagePool->pStart + 3 * v41 - 3;
    do
    {
      --v8->Heap4.MaxPages;
      if ( *v42 )
        ((void (*)(void))v8->Heap4.pHeap->vfptr->Free)();
      v42 -= 3;
    }
    while ( v8->Heap4.MaxPages );
    --v8->Heap4.MaxPages;
    v8->Heap4.pHeap->vfptr->Free(v8->Heap4.pHeap, v8->Heap4.pPagePool);
  }
  v8->Heap4.pLastPage = 0i64;
  v8->Heap4.pPagePool = 0i64;
  v8->Heap4.MaxPages = 0i64;
  if ( v49.Data != v49.Static )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return v34;
}

// File Line: 629
// RVA: 0x938040
void __fastcall Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(Scaleform::Render::CornerVertex v0, Scaleform::Render::CornerVertex v1, Scaleform::Render::CornerVertex v2, float width, float *x, float *y)
{
  __m128 v6; // xmm9
  float v7; // xmm5_4
  __m128 v8; // xmm13
  float v9; // xmm14_4
  __m128 v10; // xmm0
  float v11; // xmm6_4
  float v12; // xmm8_4
  float v13; // xmm3_4
  __m128 v14; // xmm0
  float v15; // xmm2_4

  v6 = (__m128)LODWORD(v2.y);
  v7 = width;
  v6.m128_f32[0] = v2.y - v1.y;
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
  LODWORD(v13) = (unsigned __int128)_mm_sqrt_ps(v10);
  v14 = v6;
  v14.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)((float)(v2.x - v9) * (float)(v2.x - v9));
  LODWORD(v15) = (unsigned __int128)_mm_sqrt_ps(v14);
  Scaleform::Render::Math2D::Intersection(
    v0.x + (float)(v8.m128_f32[0] * (float)(1.0 / v13)),
    (float)(v12 * (float)(1.0 / v13)) + v0.y,
    v1.x + (float)(v8.m128_f32[0] * (float)(1.0 / v13)),
    (float)(v12 * (float)(1.0 / v13)) + v1.y,
    (float)((float)((float)(v2.y - v1.y) * v7) * (float)(1.0 / v15)) + v1.x,
    (float)(v11 * (float)(1.0 / v15)) + v1.y,
    v2.x + (float)((float)((float)(v2.y - v1.y) * v7) * (float)(1.0 / v15)),
    (float)(v11 * (float)(1.0 / v15)) + v2.y,
    x,
    y,
    0.001);
}

// File Line: 650
// RVA: 0x9E52F0
char __fastcall Scaleform::Render::TextMeshProvider::generateRectangle(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::Renderer2DImpl *ren, Scaleform::Render::VertexOutput *verOut, Scaleform::Render::Matrix2x4<float> *mtx)
{
  int v4; // er14
  Scaleform::Render::MeshGenerator *v5; // r13
  Scaleform::Render::TextMeshProvider *v6; // rsi
  Scaleform::Render::Matrix2x4<float> *v7; // rdi
  Scaleform::Render::VertexOutput *v8; // r12
  Scaleform::Render::Renderer2DImpl *v9; // rbx
  signed __int64 v10; // r15
  float v11; // xmm0_4
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
  int v32; // eax
  bool v34; // bl
  unsigned int colors; // [rsp+40h] [rbp-88h]
  int v36; // [rsp+44h] [rbp-84h]
  __m128 v37; // [rsp+48h] [rbp-80h]
  __int128 v38; // [rsp+58h] [rbp-70h]
  Scaleform::Render::Matrix2x4<float> v39; // [rsp+68h] [rbp-60h]
  __int128 v40; // [rsp+88h] [rbp-40h]
  __int64 v41; // [rsp+98h] [rbp-30h]
  unsigned int v42; // [rsp+A0h] [rbp-28h]
  char v43; // [rsp+A8h] [rbp-20h]
  Scaleform::Render::TextMeshProvider *v44; // [rsp+1A8h] [rbp+E0h]
  Scaleform::Render::CornerVertex v1; // [rsp+1B0h] [rbp+E8h]
  Scaleform::Render::TextMeshProvider::VertexCountType verCount; // [rsp+1C0h] [rbp+F8h]
  Scaleform::Render::CornerVertex v2; // [rsp+1C8h] [rbp+100h]
  float y; // [rsp+1D0h] [rbp+108h]
  void *x; // [rsp+1D8h] [rbp+110h]
  Scaleform::Render::TextMeshProvider *v50; // [rsp+1E0h] [rbp+118h]

  v50 = this;
  v4 = (signed int)x;
  v5 = &ren->MeshGen;
  v6 = this;
  v7 = mtx;
  v8 = verOut;
  v9 = ren;
  v36 = (signed int)x;
  colors = LODWORD(y);
  Scaleform::Render::MeshGenerator::Clear(&ren->MeshGen);
  v10 = (signed __int64)&v5->mTess;
  *(_DWORD *)(v10 + 24) = 0;
  *(_BYTE *)(v10 + 33) = 0;
  v11 = v9->Tolerances.Epsilon;
  *(float *)(v10 + 28) = v11;
  *(_BYTE *)(v10 + 32) = v11 > 0.0;
  *(float *)(v10 + 948) = v9->Tolerances.IntersectionEpsilon;
  v12 = *(_OWORD *)&v9->Tolerances.Epsilon;
  v13 = *(_OWORD *)&v9->Tolerances.FillLowerScale;
  v42 = v9->Tolerances.CurveRecursionLimit;
  v38 = v12;
  *(_OWORD *)&v39.M[0][0] = v13;
  v14 = *(_OWORD *)&v9->Tolerances.Scale9LowerScale;
  *(_OWORD *)&v39.M[1][0] = *(_OWORD *)&v9->Tolerances.StrokeLowerScale;
  v40 = v14;
  v41 = *(_QWORD *)&v9->Tolerances.MinDet3D;
  if ( !((unsigned __int8)v50 & 1) || (unsigned __int8)v50 & 2 )
    v15 = 0.0;
  else
    v15 = *((float *)&v40 + 2) * 0.5;
  v5->mTess.EdgeAAWidth = v15;
  v16 = LODWORD(y) == 0;
  v5->mTess.EdgeAAFlag = v15 > 0.0;
  v17 = *(float *)(*(_QWORD *)&v2 + 4i64);
  v18 = v7->M[1][0];
  v19 = v7->M[0][0] * **(float **)&v2;
  v20 = *(float *)(*(_QWORD *)&v2 + 8i64);
  v21 = *(float *)(*(_QWORD *)&v2 + 12i64);
  v22 = v7->M[1][3];
  v23 = v7->M[0][3];
  v24 = (float)(v19 + (float)(v7->M[0][1] * v17)) + v23;
  v25 = (float)((float)(v18 * **(float **)&v2) + (float)(v7->M[1][1] * v17)) + v22;
  v26 = (float)((float)(v7->M[0][0] * v20) + (float)(v7->M[0][1] * v17)) + v23;
  v27 = (float)((float)(v7->M[1][0] * v20) + (float)(v7->M[1][1] * v17)) + v22;
  v28 = (float)((float)(v7->M[0][0] * v20) + (float)(v7->M[0][1] * v21)) + v23;
  v29 = (float)((float)(v7->M[0][1] * v21) + v19) + v23;
  v30 = (float)((float)(v18 * **(float **)&v2) + (float)(v7->M[1][1] * v21)) + v22;
  *(float *)&x = (float)((float)(v7->M[1][0] * v20) + (float)(v7->M[1][1] * v21)) + v22;
  if ( v16 )
  {
    v31 = (unsigned int)x;
  }
  else
  {
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 32i64))(&v5->mTess);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 32i64))(&v5->mTess);
    v31 = (unsigned int)x;
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 32i64))(&v5->mTess);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 32i64))(&v5->mTess);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 40i64))(&v5->mTess);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *, _QWORD, signed __int64))(*(_QWORD *)v10 + 48i64))(
      &v5->mTess,
      0i64,
      1i64);
  }
  if ( v4 )
  {
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 32i64))(&v5->mTess);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 32i64))(&v5->mTess);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 32i64))(&v5->mTess);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 32i64))(&v5->mTess);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 40i64))(&v5->mTess);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *, _QWORD, signed __int64))(*(_QWORD *)v10 + 48i64))(
      &v5->mTess,
      0i64,
      2i64);
    v1 = (Scaleform::Render::CornerVertex)__PAIR__(LODWORD(v25), LODWORD(v24));
    v2 = (Scaleform::Render::CornerVertex)__PAIR__(LODWORD(v30), LODWORD(v29));
    Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(
      (Scaleform::Render::CornerVertex)__PAIR__(LODWORD(v27), LODWORD(v26)),
      (Scaleform::Render::CornerVertex)__PAIR__(LODWORD(v25), LODWORD(v24)),
      (Scaleform::Render::CornerVertex)__PAIR__(LODWORD(v30), LODWORD(v29)),
      1.0,
      (float *)&x,
      &y);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 32i64))(&v5->mTess);
    Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(
      (Scaleform::Render::CornerVertex)__PAIR__(LODWORD(v25), LODWORD(v24)),
      (Scaleform::Render::CornerVertex)__PAIR__(LODWORD(v30), LODWORD(v29)),
      (Scaleform::Render::CornerVertex)__PAIR__(v31, LODWORD(v28)),
      1.0,
      (float *)&x,
      &y);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 32i64))(&v5->mTess);
    Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(
      (Scaleform::Render::CornerVertex)__PAIR__(LODWORD(v30), LODWORD(v29)),
      (Scaleform::Render::CornerVertex)__PAIR__(v31, LODWORD(v28)),
      (Scaleform::Render::CornerVertex)__PAIR__(LODWORD(v27), LODWORD(v26)),
      1.0,
      (float *)&x,
      &y);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 32i64))(&v5->mTess);
    Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(
      (Scaleform::Render::CornerVertex)__PAIR__(v31, LODWORD(v28)),
      (Scaleform::Render::CornerVertex)__PAIR__(LODWORD(v27), LODWORD(v26)),
      (Scaleform::Render::CornerVertex)__PAIR__(LODWORD(v25), LODWORD(v24)),
      1.0,
      (float *)&x,
      &y);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 32i64))(&v5->mTess);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *))(*(_QWORD *)v10 + 40i64))(&v5->mTess);
    (*(void (__fastcall **)(Scaleform::Render::Tessellator *, _QWORD, signed __int64))(*(_QWORD *)v10 + 48i64))(
      &v5->mTess,
      0i64,
      2i64);
    v7 = (Scaleform::Render::Matrix2x4<float> *)verCount;
    v6 = v44;
  }
  Scaleform::Render::Tessellator::Tessellate(&v5->mTess, 0);
  *(_OWORD *)&v39.M[0][2] = _xmm;
  v37 = _xmm;
  Scaleform::Render::Matrix2x4<float>::SetInverse((Scaleform::Render::Matrix2x4<float> *)((char *)&v39 + 8), v7);
  (*(void (__fastcall **)(Scaleform::Render::Tessellator *, float *))(*(_QWORD *)v10 + 56i64))(&v5->mTess, &v39.M[0][2]);
  (*(void (__fastcall **)(Scaleform::Render::Tessellator *, char *))(*(_QWORD *)v10 + 64i64))(&v5->mTess, &v43);
  v37.m128_i32[0] = (*(__int64 (__fastcall **)(Scaleform::Render::Tessellator *, _QWORD))(*(_QWORD *)v10 + 88i64))(
                      &v5->mTess,
                      0i64);
  v32 = (*(__int64 (__fastcall **)(Scaleform::Render::Tessellator *, _QWORD))(*(_QWORD *)v10 + 96i64))(&v5->mTess, 0i64);
  v38 = 0ui64;
  v37.m128_u64[1] = (unsigned __int64)&Scaleform::Render::VertexXY16iCF32::Format;
  v37.m128_i32[1] = 3 * v32;
  if ( !v37.m128_i32[0] )
    return Scaleform::Render::VectorGlyphShape::generateNullVectorMesh((Scaleform::Render::VectorGlyphShape *)v6, v8);
  v34 = v8->vfptr->BeginOutput(
          v8,
          (Scaleform::Render::VertexOutput::Fill *)&v37,
          1u,
          (Scaleform::Render::Matrix2x4<float> *)&v43);
  if ( v34 )
  {
    verCount = 0i64;
    Scaleform::Render::TextMeshProvider::setMeshData(
      v6,
      (Scaleform::Render::TessBase *)&v5->mTess.vfptr,
      v8,
      &colors,
      &verCount);
    v8->vfptr->EndOutput(v8);
  }
  Scaleform::Render::MeshGenerator::Clear(v5);
  return v34;
}

// File Line: 731
// RVA: 0x9D5FC0
char __fastcall Scaleform::Render::TextMeshProvider::clipGlyphRect(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::Rect<float> *chr, Scaleform::Render::Rect<float> *tex)
{
  float v3; // xmm7_4
  float v4; // xmm0_4
  float v5; // xmm12_4
  float v6; // xmm2_4
  float v7; // xmm5_4
  float v8; // xmm13_4
  float v9; // xmm11_4
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

  if ( !(this->Flags & 8) )
    return 1;
  v3 = chr->y2;
  v4 = this->ClipBox.y1;
  v5 = chr->x1;
  v6 = chr->y2;
  v7 = chr->x1;
  v8 = chr->y1;
  v9 = chr->x2;
  v10 = chr->y1;
  v11 = chr->x2;
  v12 = this->ClipBox.x1;
  v13 = this->ClipBox.x2;
  v14 = this->ClipBox.y2;
  if ( v6 >= v4 && v14 >= v10 && v13 >= v7 && v11 >= v12 )
  {
    if ( v7 <= v12 )
      v7 = this->ClipBox.x1;
    if ( v11 > v13 )
      v11 = this->ClipBox.x2;
    if ( v10 <= v4 )
      v10 = this->ClipBox.y1;
    if ( v6 > v14 )
      v6 = this->ClipBox.y2;
    if ( v7 < v11 && v10 < v6 )
    {
      if ( v7 != v5 || v11 != v9 || v10 != v8 || v6 != v3 )
      {
        v15 = tex->y2;
        v16 = tex->y1;
        v17 = tex->x1;
        v18 = tex->x2;
        v19 = tex->y1;
        v20 = tex->x1;
        if ( v5 != v7 )
          v20 = (float)((float)((float)(v7 - v5) * (float)(v18 - v17)) / (float)(v9 - v5)) + v17;
        if ( v8 != v10 )
          v19 = (float)((float)((float)(v10 - v8) * (float)(v15 - v16)) / (float)(v3 - v8)) + v16;
        if ( v9 != v11 )
          v18 = v18 - (float)((float)((float)(v9 - v11) * (float)(v18 - v17)) / (float)(v9 - v5));
        if ( v3 != v6 )
          v15 = v15 - (float)((float)((float)(v3 - v6) * (float)(v15 - v16)) / (float)(v3 - v8));
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
  chr->y1 = v4;
  chr->x2 = v22;
  chr->y2 = v4;
  tex->x2 = tex->x1;
  tex->y2 = tex->y1;
  return 0;
}

// File Line: 770
// RVA: 0x9E4EE0
char __fastcall Scaleform::Render::TextMeshProvider::generateRasterMesh(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::VertexOutput *verOut, Scaleform::Render::TextMeshLayer *layer)
{
  unsigned int v3; // ebx
  unsigned int v4; // er13
  Scaleform::Render::VertexOutput *v5; // r14
  Scaleform::Render::TextMeshLayer *v6; // rsi
  Scaleform::Render::VectorGlyphShape *v7; // rdi
  Scaleform::Render::GlyphCache *v8; // rax
  float v9; // xmm6_4
  float v10; // xmm7_4
  char result; // al
  int v12; // er15
  unsigned int v13; // er12
  __int64 v14; // ST20_8
  unsigned int v15; // eax
  __int64 v16; // rbx
  __int64 v17; // rsi
  signed __int64 v18; // rcx
  Scaleform::Render::GlyphShape *v19; // rax
  unsigned __int16 *v20; // rdx
  int v21; // edi
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  __m128i v25; // xmm0
  float v26; // xmm1_4
  float v27; // xmm2_4
  int v28; // xmm1_4
  int v29; // xmm2_4
  signed __int64 v30; // rcx
  signed __int64 v31; // rax
  int v32; // xmm4_4
  int v33; // xmm3_4
  int v34; // xmm1_4
  int v35; // xmm2_4
  signed __int64 v36; // rax
  signed __int64 v37; // rax
  __int64 v38; // rax
  __int64 v39; // ST20_8
  __int64 v40[2]; // [rsp+20h] [rbp-E0h]
  Scaleform::Render::Rect<float> tex; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::Rect<float> chr; // [rsp+40h] [rbp-C0h]
  unsigned int v43; // [rsp+50h] [rbp-B0h]
  unsigned int v44; // [rsp+58h] [rbp-A8h]
  unsigned int v45; // [rsp+5Ch] [rbp-A4h]
  Scaleform::Render::VertexFormat *v46; // [rsp+60h] [rbp-A0h]
  __int64 v47; // [rsp+68h] [rbp-98h]
  __int64 v48; // [rsp+70h] [rbp-90h]
  __int16 v49[384]; // [rsp+80h] [rbp-80h]
  int v50; // [rsp+380h] [rbp+280h]
  int v51; // [rsp+384h] [rbp+284h]
  int v52; // [rsp+388h] [rbp+288h]
  int v53; // [rsp+38Ch] [rbp+28Ch]
  int v54[1276]; // [rsp+390h] [rbp+290h]
  Scaleform::Render::TextMeshProvider *v55; // [rsp+17F0h] [rbp+16F0h]
  unsigned int v56; // [rsp+17F8h] [rbp+16F8h]
  Scaleform::Render::TextMeshLayer *v57; // [rsp+1800h] [rbp+1700h]
  int v58; // [rsp+1808h] [rbp+1708h]

  v57 = layer;
  v55 = this;
  v3 = layer->Count;
  v4 = 0;
  v5 = verOut;
  v47 = 0i64;
  v48 = 0i64;
  v44 = 4 * v3;
  v6 = layer;
  v7 = (Scaleform::Render::VectorGlyphShape *)this;
  v45 = 6 * v3;
  v46 = &Scaleform::Render::RasterGlyphVertex::Format;
  v8 = this->pCache;
  v43 = v3;
  v9 = v8->ScaleU;
  v10 = v8->ScaleV;
  result = verOut->vfptr->BeginOutput(
             verOut,
             (Scaleform::Render::VertexOutput::Fill *)&v44,
             1u,
             &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    v56 = 0;
    v12 = 0;
    v13 = 0;
    if ( v3 )
    {
      v58 = 0;
      do
      {
        if ( v13 >= 0x40 )
        {
          LODWORD(v40[0]) = 256;
          v5->vfptr->SetVertices(v5, 0, 4 * v12, &v50, v40[0]);
          LODWORD(v14) = 384;
          v5->vfptr->SetIndices(v5, 0, v4, (unsigned __int16 *)v49, v14);
          v13 = 0;
          v12 += 64;
          v4 += 384;
        }
        v15 = v6->Start;
        v16 = 4 * v13;
        v17 = 6 * v13;
        v18 = 5i64 * (v56 + v15);
        v19 = v7->pShape.pObject;
        v20 = (unsigned __int16 *)*((_QWORD *)&v19->Decoder.OneOverMultiplier + v18);
        v21 = HIDWORD((&v19->vfptr)[v18]);
        v22 = *((float *)&v19->pContainer + 2 * v18 + 1);
        chr.x1 = *((float *)&v19->pContainer + 2 * v18);
        v23 = *((float *)&v19->Decoder.Decoder.Data + 2 * v18);
        chr.y1 = v22;
        v24 = *((float *)&v19->Decoder.Decoder.Data + 2 * v18 + 1);
        chr.x2 = v23;
        LODWORD(v19) = v20[24] + 1;
        chr.y2 = v24;
        v25 = _mm_cvtsi32_si128((unsigned int)v20[26] - 2);
        v26 = (float)(signed int)v19 * v9;
        LODWORD(v19) = v20[27];
        v27 = (float)(v20[25] + 1);
        tex.x1 = v26;
        tex.y1 = v27 * v10;
        tex.x2 = (float)(COERCE_FLOAT(_mm_cvtepi32_ps(v25)) * v9) + v26;
        tex.y2 = (float)((float)((signed int)v19 - 2) * v10) + (float)(v27 * v10);
        Scaleform::Render::TextMeshProvider::clipGlyphRect(v55, &chr, &tex);
        v28 = LODWORD(chr.y1);
        v29 = LODWORD(tex.y1);
        v30 = 5 * v16;
        *(&v52 + v30) = v21;
        v31 = 5i64 * (unsigned int)(v16 + 1);
        v25.m128i_i32[0] = LODWORD(chr.x2);
        v32 = LODWORD(chr.x1);
        v33 = LODWORD(tex.x1);
        *(&v51 + v30) = v28;
        v54[v30] = v29;
        *(&v50 + v30) = v32;
        *(&v53 + v30) = v33;
        *(&v51 + v31) = v28;
        v34 = LODWORD(tex.x2);
        *(&v52 + v31) = v21;
        *(&v50 + v31) = v25.m128i_i32[0];
        v54[v31] = v29;
        v35 = LODWORD(chr.y2);
        *(&v53 + v31) = v34;
        v36 = 5i64 * (unsigned int)(v16 + 2);
        *(&v50 + v36) = v25.m128i_i32[0];
        v25.m128i_i32[0] = LODWORD(tex.y2);
        *(&v51 + v36) = v35;
        *(&v52 + v36) = v21;
        v54[v36] = v25.m128i_i32[0];
        *(&v53 + v36) = v34;
        v37 = 5i64 * (unsigned int)(v16 + 3);
        *(&v50 + v37) = v32;
        *(&v51 + v37) = v35;
        *(&v53 + v37) = v33;
        v54[v37] = v25.m128i_i32[0];
        *(&v52 + v37) = v21;
        v7 = (Scaleform::Render::VectorGlyphShape *)v55;
        v49[v17] = v58;
        v49[(unsigned int)(v17 + 1)] = v58 + 1;
        v49[(unsigned int)(v17 + 2)] = v58 + 2;
        ++v13;
        v49[(unsigned int)(v17 + 3)] = v58 + 2;
        v49[(unsigned int)(v17 + 4)] = v58 + 3;
        v38 = (unsigned int)(v17 + 5);
        v6 = v57;
        v49[v38] = v58;
        v58 += 4;
        ++v56;
      }
      while ( v56 < v43 );
      if ( v13 )
      {
        LODWORD(v40[0]) = 4 * v13;
        v5->vfptr->SetVertices(v5, 0, 4 * v12, &v50, v40[0]);
        LODWORD(v39) = 6 * v13;
        v5->vfptr->SetIndices(v5, 0, 6 * v12, (unsigned __int16 *)v49, v39);
        v5->vfptr->EndOutput(v5);
        return 1;
      }
      v7 = (Scaleform::Render::VectorGlyphShape *)v55;
    }
    result = Scaleform::Render::VectorGlyphShape::generateNullVectorMesh(v7, v5);
  }
  return result;
}

// File Line: 844
// RVA: 0x9E4A00
char __fastcall Scaleform::Render::TextMeshProvider::generatePackedMesh(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::VertexOutput *verOut, Scaleform::Render::TextMeshLayer *layer)
{
  unsigned int v3; // er14
  Scaleform::Render::TextMeshProvider *v4; // r12
  unsigned int v5; // esi
  __int64 v6; // rax
  Scaleform::Render::GlyphNode *v7; // rcx
  Scaleform::Render::VertexOutput *v8; // rdi
  int v9; // eax
  int *v10; // rdx
  bool v11; // r13
  char result; // al
  int v13; // er15
  unsigned int v14; // ebx
  int v15; // er14
  unsigned int v16; // er12
  int *v17; // r9
  __int64 v18; // ST20_8
  __int64 v19; // r13
  signed __int64 v20; // rdx
  Scaleform::Render::TextMeshEntry *v21; // rcx
  __int64 v22; // rsi
  float *v23; // rax
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  int v31; // xmm4_4
  int v32; // xmm1_4
  int v33; // xmm3_4
  int v34; // xmm2_4
  int v35; // xmm0_4
  int v36; // edx
  signed __int64 v37; // rax
  signed __int64 v38; // rcx
  int v39; // xmm1_4
  int v40; // xmm2_4
  signed __int64 v41; // rax
  int v42; // xmm0_4
  signed __int64 v43; // rax
  signed __int64 v44; // rcx
  signed __int64 v45; // rax
  int v46; // xmm1_4
  int v47; // xmm2_4
  signed __int64 v48; // rcx
  int v49; // xmm0_4
  signed __int64 v50; // rcx
  __int64 v51; // rax
  int *v52; // r9
  __int64 v53; // ST20_8
  __int64 v54[2]; // [rsp+20h] [rbp-E0h]
  Scaleform::Render::Rect<float> tex; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::Rect<float> chr; // [rsp+40h] [rbp-C0h]
  unsigned int v57; // [rsp+50h] [rbp-B0h]
  int v58; // [rsp+54h] [rbp-ACh]
  unsigned int v59; // [rsp+58h] [rbp-A8h]
  unsigned int v60; // [rsp+5Ch] [rbp-A4h]
  Scaleform::Render::VertexFormat *v61; // [rsp+60h] [rbp-A0h]
  __int64 v62; // [rsp+68h] [rbp-98h]
  __int64 v63; // [rsp+70h] [rbp-90h]
  unsigned int v64; // [rsp+78h] [rbp-88h]
  unsigned int v65; // [rsp+7Ch] [rbp-84h]
  Scaleform::Render::VertexFormat *v66; // [rsp+80h] [rbp-80h]
  __int64 v67; // [rsp+88h] [rbp-78h]
  __int64 v68; // [rsp+90h] [rbp-70h]
  __int16 v69[384]; // [rsp+A0h] [rbp-60h]
  int v70; // [rsp+3A0h] [rbp+2A0h]
  int v71; // [rsp+3A4h] [rbp+2A4h]
  int v72; // [rsp+3A8h] [rbp+2A8h]
  int v73[1021]; // [rsp+3ACh] [rbp+2ACh]
  int v74; // [rsp+13A0h] [rbp+12A0h]
  int v75; // [rsp+13A4h] [rbp+12A4h]
  int v76; // [rsp+13A8h] [rbp+12A8h]
  int v77; // [rsp+13ACh] [rbp+12ACh]
  int v78[1278]; // [rsp+13B0h] [rbp+12B0h]
  Scaleform::Render::TextMeshProvider *v79; // [rsp+27F0h] [rbp+26F0h]
  bool v80; // [rsp+27F8h] [rbp+26F8h]
  Scaleform::Render::TextMeshLayer *v81; // [rsp+2800h] [rbp+2700h]
  unsigned int v82; // [rsp+2808h] [rbp+2708h]

  v81 = layer;
  v79 = this;
  v3 = layer->Count;
  v4 = this;
  v5 = 0;
  v62 = 0i64;
  v63 = 0i64;
  v67 = 0i64;
  v68 = 0i64;
  v59 = 4 * v3;
  v64 = 4 * v3;
  v60 = 6 * v3;
  v65 = 6 * v3;
  v66 = &Scaleform::Render::ImageGlyphVertex::Format;
  v6 = layer->Start;
  v61 = &Scaleform::Render::RasterGlyphVertex::Format;
  v7 = this->Entries.Data.Data[v6].EntryData.RasterData.pGlyph;
  v8 = verOut;
  v57 = v3;
  v9 = (*(__int64 (**)(void))(**(_QWORD **)&v7->Param.BlurY + 32i64))();
  v10 = (int *)&v59;
  v11 = v9 == 9;
  v80 = v9 == 9;
  if ( v9 != 9 )
    v10 = (int *)&v64;
  result = v8->vfptr->BeginOutput(
             v8,
             (Scaleform::Render::VertexOutput::Fill *)v10,
             1u,
             &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    v82 = 0;
    v13 = 0;
    v14 = 0;
    if ( v3 )
    {
      v15 = 0;
      v16 = 0;
      while ( 1 )
      {
        if ( v14 >= 0x40 )
        {
          v17 = &v74;
          LODWORD(v54[0]) = 256;
          if ( !v11 )
            v17 = &v70;
          v8->vfptr->SetVertices(v8, 0, 4 * v13, v17, v54[0]);
          LODWORD(v18) = 384;
          v8->vfptr->SetIndices(v8, 0, v16, (unsigned __int16 *)v69, v18);
          v14 = 0;
          v13 += 64;
          v16 += 384;
        }
        v19 = 4 * v14;
        v20 = v5 + v81->Start;
        v21 = v79->Entries.Data.Data;
        v22 = 6 * v14;
        v23 = (float *)v21[v20].EntryData.RasterData.pGlyph;
        v24 = v23[9];
        tex.x1 = v23[8];
        v25 = v23[10];
        tex.y1 = v24;
        v26 = v23[11];
        tex.x2 = v25;
        v27 = v21[v20].EntryData.RasterData.Coord[0];
        v58 = v21[v20].mColor;
        tex.y2 = v26;
        v28 = v21[v20].EntryData.RasterData.Coord[1];
        chr.x1 = v27;
        v29 = v21[v20].EntryData.RasterData.Coord[2];
        chr.y1 = v28;
        v30 = v21[v20].EntryData.RasterData.Coord[3];
        chr.x2 = v29;
        chr.y2 = v30;
        Scaleform::Render::TextMeshProvider::clipGlyphRect(v79, &chr, &tex);
        v31 = LODWORD(chr.x1);
        v32 = LODWORD(chr.y1);
        v33 = LODWORD(tex.x1);
        v34 = LODWORD(tex.y1);
        v35 = LODWORD(chr.x2);
        if ( v80 )
        {
          v36 = v58;
          v37 = 5i64 * (unsigned int)(v19 + 1);
          v38 = 5 * v19;
          *(&v76 + v38) = v58;
          *(&v75 + v38) = v32;
          v78[v38] = v34;
          *(&v74 + v38) = v31;
          *(&v77 + v38) = v33;
          *(&v75 + v37) = v32;
          v39 = LODWORD(tex.x2);
          *(&v76 + v37) = v36;
          *(&v74 + v37) = v35;
          v78[v37] = v34;
          v40 = LODWORD(chr.y2);
          *(&v77 + v37) = v39;
          v41 = 5i64 * (unsigned int)(v19 + 2);
          *(&v74 + v41) = v35;
          v42 = LODWORD(tex.y2);
          *(&v75 + v41) = v40;
          *(&v76 + v41) = v36;
          v78[v41] = v42;
          *(&v77 + v41) = v39;
          v43 = 5i64 * (unsigned int)(v19 + 3);
          *(&v74 + v43) = v31;
          *(&v75 + v43) = v40;
          *(&v77 + v43) = v33;
          *(&v76 + v43) = v36;
          v78[v43] = v42;
        }
        else
        {
          v44 = 2i64 * (unsigned int)(v19 + 1);
          v45 = 2i64 * (unsigned int)v19;
          *(&v71 + 2 * v45) = LODWORD(chr.y1);
          v73[2 * v45] = v34;
          *(&v70 + 2 * v45) = v31;
          *(&v72 + 2 * v45) = v33;
          *(&v71 + 2 * v44) = v32;
          v46 = LODWORD(tex.x2);
          *(&v70 + 2 * v44) = v35;
          v73[2 * v44] = v34;
          v47 = LODWORD(chr.y2);
          *(&v72 + 2 * v44) = v46;
          v48 = 2i64 * (unsigned int)(v19 + 2);
          *(&v70 + 2 * v48) = v35;
          v49 = LODWORD(tex.y2);
          *(&v71 + 2 * v48) = v47;
          v73[2 * v48] = v49;
          *(&v72 + 2 * v48) = v46;
          v50 = 2i64 * (unsigned int)(v19 + 3);
          *(&v70 + 2 * v50) = v31;
          *(&v71 + 2 * v50) = v47;
          *(&v72 + 2 * v50) = v33;
          v73[2 * v50] = v49;
        }
        v69[v22] = v15;
        v69[(unsigned int)(v22 + 1)] = v15 + 1;
        v69[(unsigned int)(v22 + 2)] = v15 + 2;
        ++v14;
        v69[(unsigned int)(v22 + 3)] = v15 + 2;
        v69[(unsigned int)(v22 + 4)] = v15 + 3;
        v51 = (unsigned int)(v22 + 5);
        v5 = v82 + 1;
        v69[v51] = v15;
        v15 += 4;
        v82 = v5;
        if ( v5 >= v57 )
          break;
        v11 = v80;
      }
      if ( v14 )
      {
        v52 = &v74;
        if ( !v80 )
          v52 = &v70;
        LODWORD(v54[0]) = 4 * v14;
        v8->vfptr->SetVertices(v8, 0, 4 * v13, v52, v54[0]);
        LODWORD(v53) = 6 * v14;
        v8->vfptr->SetIndices(v8, 0, 6 * v13, (unsigned __int16 *)v69, v53);
        goto LABEL_21;
      }
      v4 = v79;
    }
    Scaleform::Render::VectorGlyphShape::generateNullVectorMesh((Scaleform::Render::VectorGlyphShape *)v4, v8);
LABEL_21:
    v8->vfptr->EndOutput(v8);
    result = 1;
  }
  return result;
}

// File Line: 924
// RVA: 0x9E4510
__int64 __fastcall Scaleform::Render::TextMeshProvider::generateImageMesh(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::VertexOutput *verOut, Scaleform::Render::TextMeshLayer *layer)
{
  Scaleform::Render::TextMeshProvider *v3; // rsi
  Scaleform::Render::TextMeshEntry *v4; // rbx
  signed __int64 v5; // rax
  signed __int64 v6; // rdi
  Scaleform::Render::VertexOutput *v7; // r14
  float v8; // xmm8_4
  float v9; // xmm6_4
  float v10; // xmm3_4
  int v11; // xmm1_4
  Scaleform::Render::VertexOutputVtbl *v12; // rax
  __int64 result; // rax
  signed int v14; // ST20_4
  __int64 v15; // ST20_8
  int v16; // [rsp+30h] [rbp-B8h]
  int v17; // [rsp+34h] [rbp-B4h]
  int v18; // [rsp+38h] [rbp-B0h]
  char tex[20]; // [rsp+40h] [rbp-A8h]
  float v20; // [rsp+54h] [rbp-94h]
  int v21; // [rsp+58h] [rbp-90h]
  int v22; // [rsp+5Ch] [rbp-8Ch]
  float v23; // [rsp+60h] [rbp-88h]
  float v24; // [rsp+64h] [rbp-84h]
  __int64 v25; // [rsp+68h] [rbp-80h]
  __int64 v26; // [rsp+70h] [rbp-78h]
  int v27; // [rsp+78h] [rbp-70h]
  float v28; // [rsp+7Ch] [rbp-6Ch]
  int v29; // [rsp+80h] [rbp-68h]
  int v30; // [rsp+84h] [rbp-64h]
  int v31; // [rsp+88h] [rbp-60h]
  int v32; // [rsp+8Ch] [rbp-5Ch]
  int v33; // [rsp+90h] [rbp-58h]
  __int64 v34; // [rsp+94h] [rbp-54h]
  int v35; // [rsp+9Ch] [rbp-4Ch]
  int v36; // [rsp+A0h] [rbp-48h]
  int v37; // [rsp+A4h] [rbp-44h]
  int v38; // [rsp+A8h] [rbp-40h]
  int v39; // [rsp+ACh] [rbp-3Ch]
  Scaleform::Render::VertexFormat *v40; // [rsp+B0h] [rbp-38h]
  __int64 v41; // [rsp+B8h] [rbp-30h]
  __int64 v42; // [rsp+C0h] [rbp-28h]

  v3 = this;
  v16 = 0x10000;
  v4 = this->Entries.Data.Data;
  v17 = 2;
  v18 = 196610;
  v38 = 4;
  v39 = 6;
  v41 = 0i64;
  v42 = 0i64;
  v40 = &Scaleform::Render::ImageGlyphVertex::Format;
  v5 = layer->Start;
  v6 = v5;
  v7 = verOut;
  ((void (__fastcall *)(Scaleform::Render::GlyphNode *, float *, Scaleform::Render::TextureManager *))v4[v5].EntryData.RasterData.pGlyph->Param.pFont[5].pFont)(
    v4[v5].EntryData.RasterData.pGlyph,
    &v23,
    this->pCache->pTexMan);
  v8 = v4[v6].EntryData.RasterData.Coord[2] - v4[v6].EntryData.RasterData.Coord[0];
  v9 = v4[v6].EntryData.RasterData.Coord[3] - v4[v6].EntryData.RasterData.Coord[1];
  v10 = (float)((float)((float)(*(float *)&v26 + *((float *)&v26 + 1)) * 0.0) + v28)
      + v4[v6].EntryData.RasterData.Coord[1];
  *(float *)&tex[16] = (float)((float)((float)(v23 + v24) * 0.0) + *((float *)&v25 + 1))
                     + v4[v6].EntryData.RasterData.Coord[0];
  *(float *)&v21 = (float)((float)((float)(v23 * v8) + (float)(v24 * v9)) + *((float *)&v25 + 1))
                 + v4[v6].EntryData.RasterData.Coord[0];
  *(float *)&v11 = (float)((float)((float)(*(float *)&v26 * v8) + (float)(*((float *)&v26 + 1) * v9)) + v28)
                 + v4[v6].EntryData.RasterData.Coord[1];
  v20 = v10;
  v22 = v11;
  *(float *)&tex[8] = (float)(v23 + v24) + *((float *)&v25 + 1);
  *(float *)tex = (float)((float)(v23 + v24) * 0.0) + *((float *)&v25 + 1);
  *(float *)&tex[4] = (float)((float)(*(float *)&v26 + *((float *)&v26 + 1)) * 0.0) + v28;
  *(float *)&tex[12] = (float)(*(float *)&v26 + *((float *)&v26 + 1)) + v28;
  Scaleform::Render::TextMeshProvider::clipGlyphRect(
    v3,
    (Scaleform::Render::Rect<float> *)&tex[16],
    (Scaleform::Render::Rect<float> *)tex);
  v25 = *(_QWORD *)&tex[16];
  v26 = *(_QWORD *)tex;
  v12 = v7->vfptr;
  v27 = v21;
  v30 = *(_DWORD *)&tex[4];
  v31 = v21;
  v28 = v20;
  v32 = v22;
  v34 = *(_QWORD *)&tex[12];
  v35 = v22;
  v37 = *(_DWORD *)&tex[12];
  v29 = *(_DWORD *)&tex[8];
  v33 = *(_DWORD *)&tex[8];
  v36 = *(_DWORD *)tex;
  result = v12->BeginOutput(
             v7,
             (Scaleform::Render::VertexOutput::Fill *)&v38,
             1u,
             &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( (_BYTE)result )
  {
    v14 = 4;
    v7->vfptr->SetVertices(v7, 0, 0, &v25, v14);
    LODWORD(v15) = 6;
    v7->vfptr->SetIndices(v7, 0, 0, (unsigned __int16 *)&v16, v15);
    v7->vfptr->EndOutput(v7);
    result = 1i64;
  }
  return result;
} (unsigned __int16 *)&

// File Line: 969
// RVA: 0x9E6360
char __fastcall Scaleform::Render::TextMeshProvider::generateUnderlines(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::Renderer2DImpl *ren, Scaleform::Render::VertexOutput *verOut, Scaleform::Render::TextMeshLayer *layer)
{
  Scaleform::Render::TextMeshLayer *v4; // r13
  Scaleform::Render::VertexOutput *v5; // r12
  Scaleform::Render::TextMeshProvider *v6; // r14
  Scaleform::Render::MeshGenerator *v7; // rdi
  bool v8; // al
  signed __int64 v9; // rbx
  unsigned int v10; // er15
  char v11; // r12
  signed __int64 v12; // rsi
  Scaleform::Render::TextMeshEntry *v13; // r14
  int v14; // eax
  __m128 v15; // xmm7
  float v16; // xmm4_4
  __m128 v17; // xmm6
  float v18; // xmm5_4
  float v19; // xmm8_4
  __m128 v20; // xmm9
  signed int v21; // ecx
  signed int v22; // ecx
  float i; // xmm12_4
  float v24; // edx
  signed int v25; // ecx
  signed int v26; // ecx
  float v27; // xmm9_4
  float v28; // xmm11_4
  unsigned __int64 v29; // rax
  char **v30; // rbx
  unsigned __int64 v31; // rax
  char **v32; // rbx
  unsigned __int64 v33; // rax
  char **v34; // rbx
  unsigned __int64 v35; // rax
  char **v36; // rbx
  Scaleform::Render::TextMeshProvider::VertexCountType *verCount; // [rsp+20h] [rbp-A8h]
  int v39; // [rsp+30h] [rbp-98h]
  int v40; // [rsp+34h] [rbp-94h]
  Scaleform::Render::VertexFormat *v41; // [rsp+38h] [rbp-90h]
  __int64 v42; // [rsp+40h] [rbp-88h]
  __int64 v43; // [rsp+48h] [rbp-80h]
  Scaleform::Render::Matrix2x4<float> v44; // [rsp+50h] [rbp-78h]
  Scaleform::ArrayStaticBuffPOD<unsigned long,16,2> v45; // [rsp+70h] [rbp-58h]
  Scaleform::Render::TextMeshProvider *v46; // [rsp+1A8h] [rbp+E0h]
  Scaleform::Render::TextMeshProvider::VertexCountType v47; // [rsp+1B0h] [rbp+E8h]
  Scaleform::Render::VertexOutput *v48; // [rsp+1B8h] [rbp+F0h]
  Scaleform::Render::Matrix2x4<float> *m; // [rsp+1C8h] [rbp+100h]
  int vars0; // [rsp+1D0h] [rbp+108h]

  *(_QWORD *)&v45.Static[4] = -2i64;
  v4 = layer;
  v5 = verOut;
  v6 = this;
  v45.pHeap = Scaleform::Memory::pGlobalHeap;
  v45.Size = 0i64;
  v43 = 16i64;
  *(_QWORD *)&v45.Static[2] = (char *)&v45 + 24;
  v7 = &ren->MeshGen;
  Scaleform::Render::MeshGenerator::Clear(&ren->MeshGen);
  v8 = vars0 & 1 && !(vars0 & 2);
  LOBYTE(vars0) = v8;
  v9 = (signed __int64)&v7->mStrokerAA;
  *(_QWORD *)&v7->mStrokerAA.StartLineCap = 0i64;
  v7->mStrokerAA.LineJoin = 0;
  if ( v8 )
  {
    *(_QWORD *)&v7->mStrokerAA.WidthLeft = 0i64;
    v7->mStrokerAA.AaWidthRight = 0.95999998;
    v7->mStrokerAA.AaWidthLeft = 0.95999998;
  }
  else
  {
    v7->mStrokerAA.WidthRight = 0.5;
    v7->mStrokerAA.WidthLeft = 0.5;
    *(_QWORD *)&v7->mStrokerAA.AaWidthLeft = 0i64;
  }
  v10 = 0;
  if ( v4->Count > 0 )
  {
    v11 = vars0;
    do
    {
      v12 = v10 + v4->Start;
      v13 = v6->Entries.Data.Data;
      v14 = v13[v10 + v4->Start].EntryData.UnderlineData.Style - 1;
      if ( v11 )
      {
        if ( v14 & 0xFFFFFFFD )
        {
          *(_QWORD *)&v7->mStrokerAA.WidthLeft = 0i64;
        }
        else
        {
          v7->mStrokerAA.WidthRight = 1.0;
          v7->mStrokerAA.WidthLeft = 1.0;
        }
        if ( v13[v12].EntryData.UnderlineData.Style == 5 )
        {
          v7->mStrokerAA.WidthRight = 0.25;
          v7->mStrokerAA.WidthLeft = 0.25;
        }
        if ( v13[v12].EntryData.UnderlineData.Style == 4 )
        {
          v7->mStrokerAA.AaWidthRight = 0.5;
          v7->mStrokerAA.AaWidthLeft = 0.5;
        }
        else
        {
          v7->mStrokerAA.AaWidthRight = 0.95999998;
          v7->mStrokerAA.AaWidthLeft = 0.95999998;
        }
      }
      else
      {
        if ( v14 & 0xFFFFFFFD )
        {
          v7->mStrokerAA.WidthRight = 0.5;
          v7->mStrokerAA.WidthLeft = 0.5;
        }
        else
        {
          v7->mStrokerAA.WidthRight = 1.0;
          v7->mStrokerAA.WidthLeft = 1.0;
        }
        if ( v13[v12].EntryData.UnderlineData.Style == 5 )
        {
          v7->mStrokerAA.WidthRight = 0.75;
          v7->mStrokerAA.WidthLeft = 0.75;
        }
        *(_QWORD *)&v7->mStrokerAA.AaWidthLeft = 0i64;
      }
      v7->mStrokerAA.StyleLeft = ++v10;
      v7->mStrokerAA.StyleRight = v10;
      Scaleform::ArrayStaticBuffPOD<unsigned int,16,2>::PushBack(&v45, &v13[v12].mColor);
      v15 = (__m128)LODWORD(v13[v12].EntryData.BackgroundData.Coord[1]);
      v16 = v13[v12].EntryData.RasterData.Coord[2] * m->M[0][1];
      v17 = (__m128)LODWORD(v13[v12].EntryData.BackgroundData.Coord[1]);
      v17.m128_f32[0] = (float)((float)(v17.m128_f32[0] * m->M[0][0]) + v16) + m->M[0][3];
      v18 = v13[v12].EntryData.RasterData.Coord[2] * m->M[1][1];
      v19 = (float)((float)(v13[v12].EntryData.RasterData.Coord[1] * m->M[1][0]) + v18) + m->M[1][3];
      v15.m128_f32[0] = v15.m128_f32[0] + v13[v12].EntryData.RasterData.Coord[3];
      v20 = v15;
      v20.m128_f32[0] = (float)((float)(v15.m128_f32[0] * m->M[0][0]) + v16) + m->M[0][3];
      v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] * m->M[1][0]) + v18) + m->M[1][3];
      if ( v13[v12].EntryData.UnderlineData.Style <= 1 )
      {
        (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v9 + 32i64))(&v7->mStrokerAA.vfptr);
        (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v9 + 32i64))(&v7->mStrokerAA.vfptr);
        LOBYTE(verCount) = 0;
        (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **, _QWORD, _QWORD, _QWORD, Scaleform::Render::TextMeshProvider::VertexCountType *))(*(_QWORD *)v9 + 48i64))(
          &v7->mStrokerAA.vfptr,
          0i64,
          0i64,
          0i64,
          verCount);
      }
      if ( v13[v12].EntryData.UnderlineData.Style - 2 <= 1 )
      {
        v21 = (signed int)v17.m128_f32[0];
        if ( (signed int)v17.m128_f32[0] != 0x80000000 && (float)v21 != v17.m128_f32[0] )
          v17 = (__m128)COERCE_UNSIGNED_INT((float)(v21 - (_mm_movemask_ps(_mm_unpacklo_ps(v17, v17)) & 1)));
        v17.m128_f32[0] = v17.m128_f32[0] - 0.5;
        v22 = (signed int)v20.m128_f32[0];
        if ( (signed int)v20.m128_f32[0] != 0x80000000 && (float)v22 != v20.m128_f32[0] )
          v20 = (__m128)COERCE_UNSIGNED_INT((float)(v22 - (_mm_movemask_ps(_mm_unpacklo_ps(v20, v20)) & 1)));
        v20.m128_f32[0] = v20.m128_f32[0] + 0.5;
        for ( i = v17.m128_f32[0]; i <= v20.m128_f32[0]; i = i + 5.0 )
        {
          (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v9 + 32i64))(&v7->mStrokerAA.vfptr);
          (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v9 + 32i64))(&v7->mStrokerAA.vfptr);
          LOBYTE(verCount) = 0;
          (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **, _QWORD, _QWORD, _QWORD, Scaleform::Render::TextMeshProvider::VertexCountType *))(*(_QWORD *)v9 + 48i64))(
            &v7->mStrokerAA.vfptr,
            0i64,
            0i64,
            0i64,
            verCount);
        }
      }
      v24 = v13[v12].EntryData.RasterData.Coord[0];
      if ( (unsigned int)(LODWORD(v24) - 4) <= 1 )
      {
        v25 = (signed int)v17.m128_f32[0];
        if ( (signed int)v17.m128_f32[0] != 0x80000000 && (float)v25 != v17.m128_f32[0] )
          v17.m128_f32[0] = (float)(v25 - (_mm_movemask_ps(_mm_unpacklo_ps(v17, v17)) & 1));
        v26 = (signed int)v20.m128_f32[0];
        if ( (signed int)v20.m128_f32[0] != 0x80000000 && (float)v26 != v20.m128_f32[0] )
          v20.m128_f32[0] = (float)(v26 - (_mm_movemask_ps(_mm_unpacklo_ps(v20, v20)) & 1));
        v27 = v20.m128_f32[0] + 1.0;
        v28 = FLOAT_4_0;
        if ( LODWORD(v24) == 5 )
          v28 = FLOAT_6_0;
        for ( ; v17.m128_f32[0] <= v27; v17.m128_f32[0] = v17.m128_f32[0] + v28 )
        {
          (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v9 + 32i64))(&v7->mStrokerAA.vfptr);
          (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v9 + 32i64))(&v7->mStrokerAA.vfptr);
        }
        LOBYTE(verCount) = 0;
        (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **, _QWORD, _QWORD, _QWORD, Scaleform::Render::TextMeshProvider::VertexCountType *))(*(_QWORD *)v9 + 48i64))(
          &v7->mStrokerAA.vfptr,
          0i64,
          0i64,
          0i64,
          verCount);
      }
      v6 = v46;
    }
    while ( v10 < v4->Count );
    v5 = v48;
  }
  if ( (*(unsigned int (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v9 + 72i64))(&v7->mStrokerAA.vfptr) )
  {
    *(_OWORD *)&v44.M[0][0] = _xmm;
    *(__m128 *)&v44.M[1][0] = _xmm;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v44, m);
    (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **, Scaleform::Render::Matrix2x4<float> *))(*(_QWORD *)v9 + 56i64))(
      &v7->mStrokerAA.vfptr,
      &v44);
    (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **, unsigned int *))(*(_QWORD *)v9 + 64i64))(
      &v7->mStrokerAA.vfptr,
      &v45.Static[8]);
    v39 = (*(__int64 (__fastcall **)(Scaleform::Render::TessBaseVtbl **, _QWORD))(*(_QWORD *)v9 + 88i64))(
            &v7->mStrokerAA.vfptr,
            0i64);
    v40 = 3
        * (unsigned __int64)(*(__int64 (__fastcall **)(Scaleform::Render::TessBaseVtbl **, _QWORD))(*(_QWORD *)v9 + 96i64))(
                              &v7->mStrokerAA.vfptr,
                              0i64);
    v41 = &Scaleform::Render::VertexXY16iCF32::Format;
    v42 = 0i64;
    v43 = 0i64;
    if ( v5->vfptr->BeginOutput(
           v5,
           (Scaleform::Render::VertexOutput::Fill *)&v39,
           1u,
           (Scaleform::Render::Matrix2x4<float> *)&v45.Static[8]) )
    {
      v47 = 0i64;
      Scaleform::Render::TextMeshProvider::setMeshData(
        v6,
        (Scaleform::Render::TessBase *)&v7->mStrokerAA.vfptr,
        v5,
        *(const unsigned int **)&v45.Static[2],
        &v47);
      v5->vfptr->EndOutput(v5);
    }
  }
  else
  {
    Scaleform::Render::VectorGlyphShape::generateNullVectorMesh((Scaleform::Render::VectorGlyphShape *)v6, v5);
  }
  v7->mStrokerAA.StyleLeft = 1;
  v7->mStrokerAA.StyleRight = 1;
  (*((void (**)(void))&v7->mTess.vfptr->__vecDelDtor + 1))();
  (*((void (**)(void))&v7->mStroker.vfptr->__vecDelDtor + 1))();
  (*((void (**)(void))&v7->mStrokeSorter.vfptr->__vecDelDtor + 1))();
  (*((void (**)(void))&v7->mHairliner.vfptr->__vecDelDtor + 1))();
  (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v9 + 8i64))(&v7->mStrokerAA.vfptr);
  v29 = v7->Heap1.MaxPages;
  if ( v29 )
  {
    v30 = &v7->Heap1.pPagePool->pStart + 3 * v29 - 3;
    do
    {
      --v7->Heap1.MaxPages;
      if ( *v30 )
        ((void (*)(void))v7->Heap1.pHeap->vfptr->Free)();
      v30 -= 3;
    }
    while ( v7->Heap1.MaxPages );
    --v7->Heap1.MaxPages;
    v7->Heap1.pHeap->vfptr->Free(v7->Heap1.pHeap, v7->Heap1.pPagePool);
  }
  v7->Heap1.pLastPage = 0i64;
  v7->Heap1.pPagePool = 0i64;
  v7->Heap1.MaxPages = 0i64;
  v31 = v7->Heap2.MaxPages;
  if ( v31 )
  {
    v32 = &v7->Heap2.pPagePool->pStart + 3 * v31 - 3;
    do
    {
      --v7->Heap2.MaxPages;
      if ( *v32 )
        ((void (*)(void))v7->Heap2.pHeap->vfptr->Free)();
      v32 -= 3;
    }
    while ( v7->Heap2.MaxPages );
    --v7->Heap2.MaxPages;
    v7->Heap2.pHeap->vfptr->Free(v7->Heap2.pHeap, v7->Heap2.pPagePool);
  }
  v7->Heap2.pLastPage = 0i64;
  v7->Heap2.pPagePool = 0i64;
  v7->Heap2.MaxPages = 0i64;
  v33 = v7->Heap3.MaxPages;
  if ( v33 )
  {
    v34 = &v7->Heap3.pPagePool->pStart + 3 * v33 - 3;
    do
    {
      --v7->Heap3.MaxPages;
      if ( *v34 )
        ((void (*)(void))v7->Heap3.pHeap->vfptr->Free)();
      v34 -= 3;
    }
    while ( v7->Heap3.MaxPages );
    --v7->Heap3.MaxPages;
    v7->Heap3.pHeap->vfptr->Free(v7->Heap3.pHeap, v7->Heap3.pPagePool);
  }
  v7->Heap3.pLastPage = 0i64;
  v7->Heap3.pPagePool = 0i64;
  v7->Heap3.MaxPages = 0i64;
  v35 = v7->Heap4.MaxPages;
  if ( v35 )
  {
    v36 = &v7->Heap4.pPagePool->pStart + 3 * v35 - 3;
    do
    {
      --v7->Heap4.MaxPages;
      if ( *v36 )
        ((void (*)(void))v7->Heap4.pHeap->vfptr->Free)();
      v36 -= 3;
    }
    while ( v7->Heap4.MaxPages );
    --v7->Heap4.MaxPages;
    v7->Heap4.pHeap->vfptr->Free(v7->Heap4.pHeap, v7->Heap4.pPagePool);
  }
  v7->Heap4.pLastPage = 0i64;
  v7->Heap4.pPagePool = 0i64;
  v7->Heap4.MaxPages = 0i64;
  if ( *(Scaleform::Render::Matrix2x4<float> **)&v45.Static[2] != &v44 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return 1;
}

// File Line: 1110
// RVA: 0x9BE7A0
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::TextMeshProvider::UpdateMaskClearBounds(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::MatrixPoolImpl::HMatrix *result, Scaleform::Render::MatrixPoolImpl::HMatrix viewMat)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v3; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v4; // r12
  Scaleform::Render::TextMeshProvider *v5; // r13
  float v6; // xmm5_4
  float v7; // xmm4_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v10; // r15
  int v11; // eax
  __int64 v12; // rcx
  float v13; // eax
  float v14; // edx
  float v15; // er8
  float v16; // er9
  unsigned int v17; // er10
  unsigned int v18; // er11
  unsigned int v19; // ebx
  unsigned int v20; // edi
  float v21; // esi
  float v22; // er14
  float v23; // er15
  float v24; // ecx
  __m128 v25; // xmm10
  __int128 v26; // xmm8
  Scaleform::Render::MatrixPoolImpl::HMatrix *v27; // rdi
  Scaleform::Render::MatrixPoolImpl::HMatrix *v28; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v29; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v30; // rbx
  bool v31; // zf
  __int64 v32; // rcx
  __m128 v33; // xmm7
  __m128 v34; // xmm8
  Scaleform::Render::MatrixPoolImpl::HMatrix *v35; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v36; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v37; // rbx
  Scaleform::Render::MatrixPoolImpl::EntryHandle v38; // rbx
  __int64 v39; // rcx
  float src[4]; // [rsp+30h] [rbp-98h]
  __m128 v42; // [rsp+40h] [rbp-88h]
  float dst[4]; // [rsp+50h] [rbp-78h]
  Scaleform::Render::Matrix2x4<float> m; // [rsp+60h] [rbp-68h]
  Scaleform::Render::MatrixPoolImpl::HMatrix resulta; // [rsp+118h] [rbp+50h]
  Scaleform::Render::MatrixPoolImpl::HMatrix *v46; // [rsp+120h] [rbp+58h]
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v47; // [rsp+128h] [rbp+60h]

  v3 = viewMat.pHandle;
  v4 = result;
  v5 = this;
  *(_OWORD *)&m.M[0][0] = _xmm;
  *(__m128 *)&m.M[1][0] = _xmm;
  v6 = this->ClearBox.y2;
  v7 = this->ClearBox.x2;
  v8 = this->ClearBox.y1;
  v9 = this->ClearBox.x1;
  *(_QWORD *)src = 0i64;
  *(_QWORD *)&src[2] = 1065353216i64;
  v42.m128_u64[0] = 4575657222473777152i64;
  dst[2] = v9;
  dst[3] = v8;
  *(_QWORD *)&m.M[0][0] = __PAIR__(LODWORD(v8), LODWORD(v7));
  *(_QWORD *)&m.M[0][2] = __PAIR__(LODWORD(v6), LODWORD(v7));
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&m, src, &dst[2]);
  v10 = v3->pHeader->pHandle;
  resulta.pHandle = v10;
  v11 = 2
      * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[HIBYTE(v10[1].pNext) & 0xF].Offsets[4];
  v12 = v11 * 8;
  if ( !(HIBYTE(v10[1].pNext) & 0x10) )
  {
    v33 = _mm_and_ps(
            *(__m128 *)&v10[v11 + 4].pHeader,
            (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v);
    v34 = _mm_add_ps(
            _mm_mul_ps(
              *(__m128 *)&m.M[1][0],
              _mm_shuffle_ps(*(__m128 *)&v10[v11 + 4].pHeader, *(__m128 *)&v10[v11 + 4].pHeader, 85)),
            _mm_mul_ps(
              *(__m128 *)&m.M[0][0],
              _mm_shuffle_ps(*(__m128 *)&v10[v11 + 4].pHeader, *(__m128 *)&v10[v11 + 4].pHeader, 0)));
    *(__m128 *)&m.M[0][0] = _mm_and_ps(
                              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v,
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    *(__m128 *)&m.M[1][0],
                                    _mm_shuffle_ps(
                                      *(__m128 *)&v10[v11 + 2].pHeader,
                                      *(__m128 *)&v10[v11 + 2].pHeader,
                                      85)),
                                  _mm_mul_ps(
                                    *(__m128 *)&m.M[0][0],
                                    _mm_shuffle_ps(
                                      *(__m128 *)&v10[v11 + 2].pHeader,
                                      *(__m128 *)&v10[v11 + 2].pHeader,
                                      0))),
                                _mm_and_ps(
                                  *(__m128 *)&v10[v11 + 2].pHeader,
                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v)));
    *(__m128 *)&m.M[1][0] = _mm_and_ps(
                              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v,
                              _mm_add_ps(v34, v33));
    v27 = &v5->ClearBounds;
    if ( v5->ClearBounds.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(v27, &m);
      goto LABEL_12;
    }
    v35 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(&v5->pRenderer->MPool, &resulta, &m, 0);
    Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(v27, v35);
    v29 = resulta.pHandle;
    if ( resulta.pHandle == &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      goto LABEL_12;
    goto LABEL_4;
  }
  v13 = *(float *)&v10[v11 + 2].pHeader;
  v14 = *(float *)((char *)&v10[2].pNext + v12 + 4);
  v15 = *(float *)((char *)&v10[3].pHeader + v12);
  v16 = *(float *)((char *)&v10[3].pNext + v12 + 4);
  v17 = *(_DWORD *)((char *)&v10[4].pHeader + v12);
  v18 = *(_DWORD *)((char *)&v10[4].pNext + v12 + 4);
  v19 = *(_DWORD *)((char *)&v10[5].pHeader + v12);
  v20 = *(_DWORD *)((char *)&v10[5].pNext + v12 + 4);
  v21 = *(float *)((char *)&v10[6].pHeader + v12);
  v22 = *(float *)((char *)&v10[6].pNext + v12 + 4);
  v23 = *(float *)((char *)&v10[7].pHeader + v12);
  v24 = *(float *)((char *)&resulta.pHandle[7].pNext + v12 + 4);
  src[0] = v13;
  src[1] = v14;
  src[2] = v15;
  src[3] = v16;
  v42.m128_u64[0] = __PAIR__(v18, v17);
  v42.m128_u64[1] = __PAIR__(v20, v19);
  dst[0] = v21;
  dst[1] = v22;
  dst[2] = v23;
  dst[3] = v24;
  v25 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), *(__m128 *)&m.M[0][0]),
            _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), *(__m128 *)&m.M[1][0])),
          _mm_and_ps((__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>'::`2'::v, v42));
  v26 = (__int128)_mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)dst, *(__m128 *)dst, 0), *(__m128 *)&m.M[0][0]),
                      _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)dst, *(__m128 *)dst, 85), *(__m128 *)&m.M[1][0])),
                    _mm_and_ps(
                      (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>'::`2'::v,
                      *(__m128 *)dst));
  *(__m128 *)&m.M[0][0] = _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)src, *(__m128 *)src, 0), *(__m128 *)&m.M[0][0]),
                              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)src, *(__m128 *)src, 85), *(__m128 *)&m.M[1][0])),
                            _mm_and_ps(
                              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>'::`2'::v,
                              *(__m128 *)src));
  *(__m128 *)&m.M[1][0] = v25;
  *(__m128 *)((char *)&v42 + 8) = (__m128)v26;
  v27 = &v5->ClearBounds;
  v4 = v46;
  if ( v5->ClearBounds.pHandle == &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v28 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
            &v5->pRenderer->MPool,
            &resulta,
            (Scaleform::Render::Matrix3x4<float> *)&m,
            0x10u);
    Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(v27, v28);
    v29 = resulta.pHandle;
    if ( resulta.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
LABEL_4:
      v30 = v29->pHeader;
      v31 = v29->pHeader->RefCount == 1;
      --v30->RefCount;
      if ( v31 )
      {
        v32 = v30->DataPageOffset;
        *(_WORD *)((char *)&v30[1].RefCount + v32 + 2) += 16 * (unsigned __int8)v30->UnitSize;
        (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v30[1].pHandle + v32))[5].pHeader += (unsigned __int8)v30->UnitSize;
        Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v30->pHandle);
        v30->pHandle = 0i64;
      }
      goto LABEL_11;
    }
  }
  else
  {
    Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix3D(v27, (Scaleform::Render::Matrix3x4<float> *)&m);
  }
LABEL_11:
  v3 = v47;
LABEL_12:
  v36 = v27->pHandle;
  v4->pHandle = v27->pHandle;
  if ( v36 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++v36->pHeader->RefCount;
  v37 = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)v3->pHeader;
  if ( v37 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v38.pHeader = v37->pHeader;
    v31 = v38.pHeader->RefCount-- == 1;
    if ( v31 )
    {
      v39 = v38.pHeader->DataPageOffset;
      *(_WORD *)((char *)&v38.pHeader[1].RefCount + v39 + 2) += 16 * (unsigned __int8)v38.pHeader->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v38.pHeader[1].pHandle + v39))[5].pHeader += (unsigned __int8)v38.pHeader->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v38.pHeader->pHandle);
      v38.pHeader->pHandle = 0i64;
    }
  }
  return v4;
}

// File Line: 1138
// RVA: 0x988C10
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::TextMeshProvider::GetMaskClearBounds(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::MatrixPoolImpl::HMatrix *result)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v2; // rax

  v2 = this->ClearBounds.pHandle;
  result->pHandle = v2;
  if ( v2 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++v2->pHeader->RefCount;
  return result;
}

// File Line: 1145
// RVA: 0x9E47D0
char __fastcall Scaleform::Render::TextMeshProvider::generateMask(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::VertexOutput *verOut, Scaleform::Render::TextMeshLayer *layer)
{
  Scaleform::Render::VertexOutput *v3; // rbx
  signed __int64 v4; // r8
  Scaleform::Render::TextMeshEntry *v5; // rax
  int v6; // xmm3_4
  int v7; // xmm2_4
  float v8; // xmm0_4
  Scaleform::Render::VertexOutputVtbl *v9; // rax
  char result; // al
  signed int v11; // ST20_4
  __int64 v12; // ST20_8
  float dst; // [rsp+30h] [rbp-19h]
  int v14; // [rsp+34h] [rbp-15h]
  int v15; // [rsp+38h] [rbp-11h]
  int v16; // [rsp+3Ch] [rbp-Dh]
  int v17; // [rsp+40h] [rbp-9h]
  float v18; // [rsp+44h] [rbp-5h]
  float src; // [rsp+48h] [rbp-1h]
  int v20; // [rsp+4Ch] [rbp+3h]
  int v21; // [rsp+50h] [rbp+7h]
  int v22; // [rsp+54h] [rbp+Bh]
  int v23; // [rsp+58h] [rbp+Fh]
  int v24; // [rsp+5Ch] [rbp+13h]
  int v25; // [rsp+60h] [rbp+17h]
  int v26; // [rsp+64h] [rbp+1Bh]
  Scaleform::Render::VertexFormat *v27; // [rsp+68h] [rbp+1Fh]
  __int64 v28; // [rsp+70h] [rbp+27h]
  __int64 v29; // [rsp+78h] [rbp+2Fh]
  Scaleform::Render::Matrix2x4<float> v30; // [rsp+80h] [rbp+37h]

  v3 = verOut;
  v4 = layer->Start;
  v5 = this->Entries.Data.Data;
  *(_OWORD *)&v30.M[0][0] = _xmm;
  *(__m128 *)&v30.M[1][0] = _xmm;
  v6 = LODWORD(v5[v4].EntryData.MaskData.Coord[2]);
  v7 = LODWORD(v5[v4].EntryData.BackgroundData.Coord[1]);
  src = -32764.0;
  v20 = -956303360;
  v21 = 1191180288;
  v22 = -956303360;
  v23 = 1191180288;
  v24 = 1191180288;
  v8 = v5[v4].EntryData.RasterData.Coord[0];
  v14 = v7;
  v15 = v6;
  dst = v8;
  v16 = v7;
  v17 = v6;
  v18 = v5[v4].EntryData.RasterData.Coord[3];
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v30, &src, &dst);
  v27 = &Scaleform::Render::VertexXY16i::Format;
  v9 = v3->vfptr;
  v28 = 0i64;
  v29 = 0i64;
  LODWORD(dst) = -2147188732;
  v14 = -2147188740;
  v15 = 2147254268;
  v16 = 2147254276;
  LODWORD(src) = 0x10000;
  v20 = 2;
  v21 = 196610;
  v25 = 4;
  v26 = 6;
  result = v9->BeginOutput(v3, (Scaleform::Render::VertexOutput::Fill *)&v25, 1u, &v30);
  if ( result )
  {
    v11 = 4;
    v3->vfptr->SetVertices(v3, 0, 0, &dst, v11);
    LODWORD(v12) = 6;
    v3->vfptr->SetIndices(v3, 0, 0, (unsigned __int16 *)&src, v12);
    v3->vfptr->EndOutput(v3);
    result = 1;
  }
  return result;
}

// File Line: 1177
// RVA: 0x9E4950
char __fastcall Scaleform::Render::VectorGlyphShape::generateNullVectorMesh(Scaleform::Render::VectorGlyphShape *this, Scaleform::Render::VertexOutput *verOut)
{
  Scaleform::Render::VertexOutput *v2; // rbx
  Scaleform::Render::VertexOutputVtbl *v3; // rax
  char result; // al
  signed int v5; // ST20_4
  __int64 v6; // ST20_8
  __int64 v7; // [rsp+30h] [rbp-38h]
  __int16 v8; // [rsp+38h] [rbp-30h]
  int v9; // [rsp+40h] [rbp-28h]
  int v10; // [rsp+44h] [rbp-24h]
  Scaleform::Render::VertexFormat *v11; // [rsp+48h] [rbp-20h]
  __int64 v12; // [rsp+50h] [rbp-18h]
  __int64 v13; // [rsp+58h] [rbp-10h]
  __int16 v14; // [rsp+78h] [rbp+10h]
  int v15; // [rsp+7Ah] [rbp+12h]

  v2 = verOut;
  v11 = &Scaleform::Render::VertexXY16iCF32::Format;
  v3 = verOut->vfptr;
  v7 = 0i64;
  v8 = 0;
  v15 = 0;
  v14 = 0;
  v12 = 0i64;
  v13 = 0i64;
  v9 = 1;
  v10 = 3;
  result = v3->BeginOutput(
             verOut,
             (Scaleform::Render::VertexOutput::Fill *)&v9,
             1u,
             &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    v5 = 1;
    v2->vfptr->SetVertices(v2, 0, 0, &v7, v5);
    LODWORD(v6) = 3;
    v2->vfptr->SetIndices(v2, 0, 0, (unsigned __int16 *)&v14, v6);
    v2->vfptr->EndOutput(v2);
    result = 1;
  }
  return result;
}

// File Line: 1205
// RVA: 0x982150
bool __fastcall Scaleform::Render::TextMeshProvider::GetData(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::MeshBase *mesh, Scaleform::Render::VertexOutput *verOut, unsigned int meshGenFlags)
{
  Scaleform::Render::Renderer2DImpl *v4; // rsi
  Scaleform::Render::TextMeshEntry *v5; // rdi
  Scaleform::Render::VertexOutput *v6; // r11
  __int64 v7; // r8
  Scaleform::Render::TextMeshLayer *v8; // r8
  bool result; // al
  Scaleform::Render::Matrix2x4<float> mtx; // [rsp+40h] [rbp-28h]

  v4 = mesh->pRenderer2D;
  v5 = this->Entries.Data.Data;
  v6 = verOut;
  v7 = mesh->Layer;
  mtx.M[0][0] = this->HeightRatio;
  mtx.M[1][1] = mtx.M[0][0];
  *(_OWORD *)&mtx.M[0][1] = 0ui64;
  v8 = &this->Layers.Data.Data[v7];
  *(_QWORD *)&mtx.M[1][2] = 0i64;
  switch ( v8->Type )
  {
    case 0:
      result = Scaleform::Render::TextMeshProvider::generateRectangle(
                 this,
                 v4,
                 v6,
                 &mtx,
                 v5[v8->Start].EntryData.RasterData.Coord,
                 v5[v8->Start].mColor,
                 v5[v8->Start].EntryData.BackgroundData.BorderColor,
                 meshGenFlags);
      break;
    case 1:
      result = Scaleform::Render::TextMeshProvider::generateSelection(this, v4, v6, v8, &mtx, meshGenFlags);
      break;
    case 2:
    case 3:
    case 4:
      result = Scaleform::Render::TextMeshProvider::generateRasterMesh(this, v6, v8);
      break;
    case 5:
    case 6:
      result = Scaleform::Render::TextMeshProvider::generatePackedMesh(this, v6, v8);
      break;
    case 7:
      result = Scaleform::Render::TextMeshProvider::generateImageMesh(this, v6, v8);
      break;
    case 9:
    case 0xD:
      result = Scaleform::Render::TextMeshProvider::generateUnderlines(this, v4, v6, v8, &mtx, meshGenFlags);
      break;
    case 0xA:
      result = Scaleform::Render::TextMeshProvider::generateRectangle(
                 this,
                 v4,
                 v6,
                 &mtx,
                 v5[v8->Start].EntryData.RasterData.Coord,
                 v5[v8->Start].mColor,
                 0,
                 meshGenFlags);
      break;
    case 0xB:
      result = Scaleform::Render::TextMeshProvider::generateMask(this, v6, v8);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// File Line: 1263
// RVA: 0x9836C0
void __fastcall Scaleform::Render::TextMeshProvider::GetFillData(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::FillData *data, unsigned int layer, unsigned int fillIndex, unsigned int meshGenFlags)
{
  Scaleform::Render::FillData *v5; // rbx
  Scaleform::Render::TextMeshLayer *v6; // rdx
  char *v7; // rcx
  Scaleform::Render::GradientData *v8; // rax
  Scaleform::Render::GradientData *v9; // rcx
  Scaleform::Render::GradientData *v10; // rax
  Scaleform::Render::GlyphNode *v11; // rdx
  Scaleform::Render::GradientData *v12; // [rsp+28h] [rbp-20h]

  v5 = data;
  if ( meshGenFlags & 2 )
  {
    data->Type = 1;
    data->PrimFill = 1;
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
      case 0:
      case 1:
      case 8:
      case 9:
      case 0xA:
      case 0xC:
      case 0xD:
        v5->Type = 3;
        v5->PrimFill = 3;
        LODWORD(v12) = 0;
        v5->FillMode.Fill = 0;
        v5->pGradient = v12;
        v5->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
        return;
      case 2:
      case 3:
      case 4:
        v7 = (char *)this->pCache + 128 * (unsigned __int64)this->Entries.Data.Data[v6->Start].TextureId;
        v8 = (Scaleform::Render::GradientData *)*((_QWORD *)v7 + 31);
        if ( !v8 )
          v8 = (Scaleform::Render::GradientData *)*((_QWORD *)v7 + 32);
        v5->Type = 4;
        v5->pGradient = v8;
        v5->FillMode.Fill = 3;
        goto LABEL_8;
      case 5:
        v9 = *(Scaleform::Render::GradientData **)&this->Entries.Data.Data[v6->Start].EntryData.RasterData.pGlyph->Param.BlurY;
        v5->Type = 4;
        v5->PrimFill = 6;
        v5->FillMode.Fill = 3;
        v5->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
        v5->pGradient = v9;
        if ( ((unsigned int (*)(void))v9->vfptr[4].__vecDelDtor)() != 9 )
          goto LABEL_13;
LABEL_8:
        v5->PrimFill = 12;
        v5->pVFormat = &Scaleform::Render::RasterGlyphVertex::Format;
        break;
      case 6:
        v10 = *(Scaleform::Render::GradientData **)&this->Entries.Data.Data[v6->Start].EntryData.RasterData.pGlyph->Param.BlurY;
        v5->Type = 4;
        v5->FillMode.Fill = 3;
        v5->pGradient = v10;
        v5->PrimFill = 13;
        v5->pVFormat = &Scaleform::Render::RasterGlyphVertex::Format;
        break;
      case 7:
        v11 = this->Entries.Data.Data[v6->Start].EntryData.RasterData.pGlyph;
        v5->Type = 4;
        v5->FillMode.Fill = 3;
        v5->pGradient = (Scaleform::Render::GradientData *)v11;
LABEL_13:
        v5->PrimFill = 11;
        v5->pVFormat = &Scaleform::Render::ImageGlyphVertex::Format;
        break;
      case 0xB:
        v5->Type = 1;
        v5->PrimFill = 1;
        LODWORD(v12) = 0;
        v5->FillMode.Fill = 0;
        v5->pGradient = v12;
        v5->pVFormat = &Scaleform::Render::VertexXY16i::Format;
        break;
      default:
        return;
    }
  }
}

// File Line: 1352
// RVA: 0x9CB330
void __fastcall Scaleform::Render::TextMeshProvider::addVectorGlyph(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::TmpTextStorage *storage, unsigned int color, Scaleform::Render::FontCacheHandle *font, unsigned __int16 glyphIndex, unsigned __int16 flags, float fontSize, float x, float y)
{
  Scaleform::Render::PrimitiveFill *v9; // rsi
  Scaleform::Render::Font *v10; // rbp
  Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4> *v11; // rbx
  unsigned __int64 v12; // rdi
  Scaleform::Render::TmpTextMeshEntry *v13; // rdx
  signed __int64 v14; // r8
  __int64 v15; // [rsp+20h] [rbp-38h]
  __int64 v16; // [rsp+28h] [rbp-30h]
  __int64 v17; // [rsp+40h] [rbp-18h]

  LODWORD(v15) = 8;
  LODWORD(v16) = color;
  HIDWORD(v15) = storage->Entries.Size;
  v9 = this->pCache->pSolidFill.pObject;
  ++v9->RefCount;
  _InterlockedExchangeAdd(&font->pFont->RefCount, 1u);
  v10 = font->pFont;
  v11 = &storage->Entries;
  *((float *)&v17 + 1) = fontSize;
  LOWORD(v17) = glyphIndex;
  v12 = storage->Entries.Size >> 6;
  WORD1(v17) = flags;
  if ( v12 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(v11, v12);
  v13 = v11->Pages[v12];
  v14 = v11->Size & 0x3F;
  *(_QWORD *)&v13[v14].LayerType = v15;
  *(_QWORD *)&v13[v14].mColor = v16;
  v13[v14].pFill = v9;
  v13[v14].EntryData.VectorData.pFont = v10;
  *(_QWORD *)&v13[v14].EntryData.MaskData.Coord[2] = v17;
  v13[v14].EntryData.RasterData.pGlyph = (Scaleform::Render::GlyphNode *)__PAIR__(LODWORD(y), LODWORD(x));
  ++v11->Size;
}

// File Line: 1390
// RVA: 0x9C8D20
void __fastcall Scaleform::Render::TextMeshProvider::addSelection(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::TmpTextStorage *storage, unsigned int color, Scaleform::Render::Rect<float> *rect)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4> *v4; // rbx
  Scaleform::Render::PrimitiveFill *v5; // rsi
  unsigned __int64 v6; // rdi
  Scaleform::Render::TmpTextMeshEntry *v7; // rdx
  signed __int64 v8; // r8
  __int64 v9; // [rsp+20h] [rbp-38h]
  __int64 v10; // [rsp+28h] [rbp-30h]
  Scaleform::Render::Font *v11; // [rsp+38h] [rbp-20h]
  __int64 v12; // [rsp+40h] [rbp-18h]
  Scaleform::Render::GlyphNode *v13; // [rsp+48h] [rbp-10h]

  v4 = &storage->Entries;
  LODWORD(v9) = 1;
  HIDWORD(v9) = storage->Entries.Size;
  LODWORD(v10) = color;
  v5 = this->pCache->pSolidFill.pObject;
  ++v5->RefCount;
  v6 = storage->Entries.Size >> 6;
  v11 = *(Scaleform::Render::Font **)&rect->x1;
  v12 = *(_QWORD *)&rect->x2;
  if ( v6 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(v4, v6);
  v7 = v4->Pages[v6];
  v8 = v4->Size & 0x3F;
  *(_QWORD *)&v7[v8].LayerType = v9;
  *(_QWORD *)&v7[v8].mColor = v10;
  v7[v8].pFill = v5;
  v7[v8].EntryData.VectorData.pFont = v11;
  *(_QWORD *)&v7[v8].EntryData.MaskData.Coord[2] = v12;
  v7[v8].EntryData.RasterData.pGlyph = v13;
  ++v4->Size;
}

// File Line: 1424
// RVA: 0x9CB250
void __fastcall Scaleform::Render::TextMeshProvider::addUnderline(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::TmpTextStorage *storage, unsigned int color, Scaleform::Render::TextUnderlineStyle style, float x, float y, float len)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4> *v7; // rbx
  Scaleform::Render::PrimitiveFill *v8; // rsi
  unsigned __int64 v9; // rdi
  Scaleform::Render::TmpTextMeshEntry *v10; // rdx
  signed __int64 v11; // r8
  __int64 v12; // [rsp+20h] [rbp-38h]
  __int64 v13; // [rsp+28h] [rbp-30h]
  unsigned __int64 v14; // [rsp+38h] [rbp-20h]
  Scaleform::Render::GlyphNode *v15; // [rsp+48h] [rbp-10h]

  v7 = &storage->Entries;
  HIDWORD(v12) = storage->Entries.Size;
  v8 = this->pCache->pSolidFill.pObject;
  LODWORD(v12) = 9;
  LODWORD(v13) = color;
  ++v8->RefCount;
  v14 = __PAIR__(LODWORD(x), style);
  v9 = storage->Entries.Size >> 6;
  if ( v9 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(v7, v9);
  v10 = v7->Pages[v9];
  v11 = v7->Size & 0x3F;
  *(_QWORD *)&v10[v11].LayerType = v12;
  *(_QWORD *)&v10[v11].mColor = v13;
  v10[v11].pFill = v8;
  v10[v11].EntryData.VectorData.pFont = (Scaleform::Render::Font *)v14;
  *(_QWORD *)&v10[v11].EntryData.MaskData.Coord[2] = __PAIR__(LODWORD(len), LODWORD(y));
  v10[v11].EntryData.RasterData.pGlyph = v15;
  ++v7->Size;
}

// File Line: 1441
// RVA: 0x9C8870
void __fastcall Scaleform::Render::TextMeshProvider::addMask(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::TmpTextStorage *storage)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4> *v2; // rbx
  Scaleform::Render::PrimitiveFill *v3; // rsi
  unsigned __int64 v4; // rdi
  Scaleform::Render::TmpTextMeshEntry *v5; // rdx
  signed __int64 v6; // r8
  __int64 v7; // [rsp+20h] [rbp-38h]
  __int64 v8; // [rsp+28h] [rbp-30h]
  Scaleform::Render::Font *v9; // [rsp+38h] [rbp-20h]
  __int64 v10; // [rsp+40h] [rbp-18h]
  Scaleform::Render::GlyphNode *v11; // [rsp+48h] [rbp-10h]

  v2 = &storage->Entries;
  HIDWORD(v7) = storage->Entries.Size;
  LODWORD(v7) = 11;
  v3 = this->pCache->pMaskFill.pObject;
  LODWORD(v8) = 0;
  ++v3->RefCount;
  v4 = storage->Entries.Size >> 6;
  v9 = *(Scaleform::Render::Font **)&this->ClipBox.x1;
  v10 = *(_QWORD *)&this->ClipBox.x2;
  if ( v4 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(v2, v4);
  v5 = v2->Pages[v4];
  v6 = v2->Size & 0x3F;
  *(_QWORD *)&v5[v6].LayerType = v7;
  *(_QWORD *)&v5[v6].mColor = v8;
  v5[v6].pFill = v3;
  v5[v6].EntryData.VectorData.pFont = v9;
  *(_QWORD *)&v5[v6].EntryData.MaskData.Coord[2] = v10;
  v5[v6].EntryData.RasterData.pGlyph = v11;
  ++v2->Size;
}

// File Line: 1458
// RVA: 0x9C8470
void __fastcall Scaleform::Render::TextMeshProvider::addLayer(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::TmpTextStorage *storage, Scaleform::Render::TextLayerType type, unsigned int start, unsigned int count)
{
  unsigned int v5; // ebp
  unsigned int v6; // er14
  Scaleform::Render::TextLayerType v7; // er12
  Scaleform::Render::TmpTextStorage *v8; // r13
  signed int v9; // esi
  unsigned __int64 v10; // rdi
  Scaleform::Render::PrimitiveFill *v11; // r15
  unsigned __int64 *v12; // rdx
  unsigned __int64 v13; // [rsp+20h] [rbp-48h]
  unsigned __int64 v14; // [rsp+28h] [rbp-40h]

  v5 = count;
  v6 = start;
  v7 = type;
  v8 = storage;
  do
  {
    v9 = 16382;
    if ( v5 < 0x3FFE )
      v9 = v5;
    v10 = v8->Layers.Size >> 4;
    v13 = __PAIR__(v6, v7);
    v11 = v8->Entries.Pages[(unsigned __int64)v6 >> 6][v6 & 0x3F].pFill;
    LODWORD(v14) = v9;
    if ( v10 >= v8->Layers.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshLayer,4,4>::allocPage(&v8->Layers, v10);
    v6 += v9;
    v12 = (unsigned __int64 *)&v8->Layers.Pages[v10][v8->Layers.Size & 0xF];
    *v12 = v13;
    v12[1] = v14;
    v12[2] = (unsigned __int64)v11;
    ++v8->Layers.Size;
    v5 -= v9;
  }
  while ( v5 );
}

// File Line: 1477
// RVA: 0x9C8550
void __fastcall Scaleform::Render::TextMeshProvider::addLayer(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::TmpTextStorage *storage, unsigned __int64 start, unsigned __int64 end)
{
  unsigned __int64 v4; // r14
  Scaleform::Render::TmpTextStorage *v5; // r13
  unsigned __int64 v6; // r12
  Scaleform::Render::TmpTextMeshEntry **v7; // r11
  unsigned __int64 v8; // rax
  signed __int64 v9; // rdi
  __int64 v10; // rbx
  Scaleform::Render::TextMeshLayer *v11; // r8
  unsigned __int16 v12; // dx
  unsigned int v13; // ebp
  unsigned int v14; // er15
  signed int v15; // esi
  Scaleform::Render::PrimitiveFill *v16; // r12
  unsigned __int64 v17; // rdi
  Scaleform::Render::TmpTextMeshLayer *v18; // rdx
  unsigned int v19; // esi
  unsigned int v20; // er15
  unsigned int v21; // er14
  signed int v22; // ebp
  Scaleform::Render::PrimitiveFill *v23; // r12
  unsigned __int64 v24; // rdi
  Scaleform::Render::TmpTextMeshLayer *v25; // rdx
  unsigned __int64 v26; // [rsp+30h] [rbp-A8h]
  __int64 v27; // [rsp+40h] [rbp-98h]
  __int64 v28; // [rsp+48h] [rbp-90h]
  Scaleform::Render::TextMeshLayer v29; // [rsp+60h] [rbp-78h]
  unsigned __int64 v30; // [rsp+E8h] [rbp+10h]
  signed __int64 v31; // [rsp+F0h] [rbp+18h]
  unsigned __int64 v32; // [rsp+F8h] [rbp+20h]

  v32 = end;
  v4 = start;
  v30 = start;
  v5 = storage;
  v6 = 8 * (start >> 6);
  v26 = v6;
  v7 = storage->Entries.Pages;
  v8 = start & 0x3F;
  v9 = 48 * v8;
  v31 = 48 * v8;
  v10 = *(__int64 *)((char *)v7 + v6);
  if ( *(_WORD *)(v10 + 48 * v8) == 4
    && this->Layers.Data.Size
    && (v11 = &this->Layers.Data.Data[this->Layers.Data.Size], (unsigned int)(v11[-1].Type - 2) <= 1)
    && *(Scaleform::Render::PrimitiveFill **)(v10 + v9 + 16) == v7[(unsigned __int64)v11[-1].Start >> 6][v11[-1].Start & 0x3F].pFill )
  {
    v11[-1].Type = 3;
    v11[-1].Count += end - v4;
  }
  else
  {
    v29.pMesh.pObject = 0i64;
    v29.pMeshKey.pObject = 0i64;
    v29.pShape.pObject = 0i64;
    v29.M.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
    v29.pFill.pObject = 0i64;
    v12 = *(unsigned __int16 *)((char *)&(*(Scaleform::Render::TmpTextMeshEntry **)((char *)storage->Entries.Pages + v6))->LayerType
                              + v9);
    if ( (v12 - 8) & 0xFFFB )
    {
      if ( v12 == 7 )
      {
        if ( v4 < end )
        {
          do
          {
            v13 = 1;
            v14 = v4;
            do
            {
              v15 = 16382;
              if ( v13 < 0x3FFE )
                v15 = v13;
              LODWORD(v27) = 7;
              HIDWORD(v27) = v14;
              LODWORD(v28) = v15;
              v16 = v5->Entries.Pages[(unsigned __int64)v14 >> 6][v14 & 0x3F].pFill;
              v17 = v5->Layers.Size >> 4;
              if ( v17 >= v5->Layers.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshLayer,4,4>::allocPage(
                  &v5->Layers,
                  v5->Layers.Size >> 4);
              v18 = &v5->Layers.Pages[v17][v5->Layers.Size & 0xF];
              *(_QWORD *)&v18->Type = v27;
              *(_QWORD *)&v18->Count = v28;
              v18->pFill = v16;
              ++v5->Layers.Size;
              v14 += v15;
              v13 -= v15;
            }
            while ( v13 );
            ++v4;
          }
          while ( v4 < v32 );
        }
      }
      else
      {
        Scaleform::Render::TextMeshProvider::addLayer(this, v5, (Scaleform::Render::TextLayerType)v12, v4, end - v4);
      }
    }
    else if ( v4 < end )
    {
      do
      {
        v19 = 1;
        v20 = v4;
        v21 = *(unsigned __int16 *)((char *)&(*(Scaleform::Render::TmpTextMeshEntry **)((char *)v5->Entries.Pages + v6))->LayerType
                                  + v9);
        do
        {
          v22 = 16382;
          if ( v19 < 0x3FFE )
            v22 = v19;
          LODWORD(v28) = v22;
          v23 = v5->Entries.Pages[(unsigned __int64)v20 >> 6][v20 & 0x3F].pFill;
          v24 = v5->Layers.Size >> 4;
          if ( v24 >= v5->Layers.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshLayer,4,4>::allocPage(
              &v5->Layers,
              v5->Layers.Size >> 4);
          v25 = &v5->Layers.Pages[v24][v5->Layers.Size & 0xF];
          *(_QWORD *)&v25->Type = __PAIR__(v20, v21);
          *(_QWORD *)&v25->Count = v28;
          v25->pFill = v23;
          ++v5->Layers.Size;
          v20 += v22;
          v19 -= v22;
        }
        while ( v19 );
        v4 = v30 + 1;
        v30 = v4;
        v9 = v31;
        v6 = v26;
      }
      while ( v4 < v32 );
    }
    Scaleform::Render::TextMeshLayer::~TextMeshLayer(&v29);
  }
}

// File Line: 1528
// RVA: 0x9F2690
void __fastcall Scaleform::Render::TextMeshProvider::sortEntries(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::TmpTextStorage *storage)
{
  Scaleform::Render::TmpTextStorage *v2; // rsi
  Scaleform::Render::TextMeshProvider *v3; // rdi
  unsigned __int64 v4; // r8
  unsigned __int64 v5; // rbx
  Scaleform::Render::TmpTextMeshEntry **v6; // rdx
  Scaleform::Render::TmpTextMeshEntry *v7; // r11
  Scaleform::Render::TmpTextMeshEntry *v8; // rcx
  unsigned __int64 v9; // rbx
  Scaleform::ArrayDH<Scaleform::Render::TextMeshEntry,2,Scaleform::ArrayDefaultPolicy> *v10; // r15
  unsigned __int64 v11; // r14
  signed __int64 v12; // rdx
  unsigned __int64 i; // rbx
  unsigned __int64 v14; // rbx
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy> *v15; // r13
  unsigned __int64 v16; // rdi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v17; // r8
  Scaleform::Render::TextMeshLayer *v18; // rax
  unsigned __int64 j; // rbx
  unsigned __int64 v20; // r14
  __int64 v21; // rbx
  signed __int64 v22; // rdi
  Scaleform::Render::TextMeshEntry *v23; // rbp
  Scaleform::Render::PrimitiveFill *v24; // r12
  Scaleform::Render::PrimitiveFill *v25; // rcx
  bool v26; // zf
  unsigned __int64 v27; // r15
  __int64 v28; // rbx
  Scaleform::Render::TmpTextMeshLayer *v29; // r12
  Scaleform::Render::TextMeshLayer *v30; // rdi
  Scaleform::Render::Mesh *v31; // rcx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v32; // r14
  Scaleform::Render::MatrixPoolImpl::EntryHandle v33; // r14
  __int64 v34; // rcx
  Scaleform::Render::PrimitiveFill *v35; // rbp
  Scaleform::Render::PrimitiveFill *v36; // rcx

  v2 = storage;
  v3 = this;
  storage->Layers.Size = 0i64;
  Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>,Scaleform::Render::TextMeshProvider::CmpEntries>(
    &storage->Entries,
    0i64,
    storage->Entries.Size,
    (Scaleform::Render::TextMeshProvider::CmpEntries)this->pCache);
  v4 = 0i64;
  v5 = 0i64;
  if ( v2->Entries.Size > 0 )
  {
    do
    {
      v6 = v2->Entries.Pages;
      v7 = v6[v5 >> 6];
      v8 = v6[v4 >> 6];
      if ( (v8[v4 & 0x3F].LayerType != v7[v5 & 0x3F].LayerType || v8[v4 & 0x3F].pFill != v7[v5 & 0x3F].pFill) && v5 > v4 )
      {
        Scaleform::Render::TextMeshProvider::addLayer(v3, v2, v4, v5);
        v4 = v5;
      }
      ++v5;
    }
    while ( v5 < v2->Entries.Size );
    if ( v5 > v4 )
      Scaleform::Render::TextMeshProvider::addLayer(v3, v2, v4, v5);
  }
  v9 = v2->Entries.Size;
  v10 = &v3->Entries;
  v11 = v3->Entries.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy> *)&v3->Entries.Data.Data,
    v3->Entries.Data.pHeap,
    v2->Entries.Size);
  if ( v9 > v11 )
  {
    v12 = (signed __int64)&v10->Data.Data[v11];
    for ( i = v9 - v11; i; --i )
    {
      if ( v12 )
        *(_QWORD *)(v12 + 8) = 0i64;
      v12 += 40i64;
    }
  }
  v14 = v2->Layers.Size;
  v15 = (Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy> *)&v3->Layers.Data.Data;
  v16 = v3->Layers.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    v15,
    v15[1].Data,
    v2->Layers.Size);
  v17 = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
  if ( v14 > v16 )
  {
    v18 = &v15->Data[v16];
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
  if ( v2->Entries.Size > 0 )
  {
    v21 = 0i64;
    do
    {
      v22 = (signed __int64)&v2->Entries.Pages[v20 >> 6][v20 & 0x3F];
      v23 = v10->Data.Data;
      v23[v21].LayerType = *(_WORD *)v22;
      v23[v21].TextureId = *(_WORD *)(v22 + 2);
      v23[v21].mColor = *(_DWORD *)(v22 + 8);
      v24 = *(Scaleform::Render::PrimitiveFill **)(v22 + 16);
      v25 = v23[v21].pFill.pObject;
      if ( v25 )
      {
        v26 = v25->RefCount-- == 1;
        if ( v26 )
          ((void (__fastcall *)(Scaleform::Render::PrimitiveFill *, signed __int64, Scaleform::Render::MatrixPoolImpl::EntryHandle *))v25->vfptr->__vecDelDtor)(
            v25,
            1i64,
            v17);
      }
      v23[v21].pFill.pObject = v24;
      v23[v21].EntryData.VectorData.pFont = *(Scaleform::Render::Font **)(v22 + 24);
      *(_QWORD *)&v23[v21].EntryData.MaskData.Coord[2] = *(_QWORD *)(v22 + 32);
      v23[v21].EntryData.RasterData.pGlyph = *(Scaleform::Render::GlyphNode **)(v22 + 40);
      ++v20;
      ++v21;
    }
    while ( v20 < v2->Entries.Size );
  }
  v27 = 0i64;
  if ( v2->Layers.Size )
  {
    v28 = 0i64;
    do
    {
      v29 = v2->Layers.Pages[v27 >> 4];
      v30 = v15->Data;
      v30[v28].Type = v29[v27 & 0xF].Type;
      v30[v28].Start = v29[v27 & 0xF].Start;
      v30[v28].Count = v29[v27 & 0xF].Count;
      v31 = v30[v28].pMesh.pObject;
      if ( v31 && !_InterlockedDecrement(&v31->RefCount) && v31 )
        ((void (__fastcall *)(Scaleform::Render::Mesh *, signed __int64, Scaleform::Render::MatrixPoolImpl::EntryHandle *))v31->vfptr->__vecDelDtor)(
          v31,
          1i64,
          &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle);
      v30[v28].pMesh.pObject = 0i64;
      v32 = v30[v28].M.pHandle;
      if ( v32 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      {
        v33.pHeader = v32->pHeader;
        v26 = v33.pHeader->RefCount-- == 1;
        if ( v26 )
        {
          v34 = v33.pHeader->DataPageOffset;
          *(_WORD *)((char *)&v33.pHeader[1].RefCount + v34 + 2) += 16 * (unsigned __int8)v33.pHeader->UnitSize;
          (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v33.pHeader[1].pHandle + v34))[5].pHeader += (unsigned __int8)v33.pHeader->UnitSize;
          Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v33.pHeader->pHandle);
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
          ((void (__fastcall *)(Scaleform::Render::PrimitiveFill *, signed __int64, Scaleform::Render::MatrixPoolImpl::EntryHandle *))v36->vfptr->__vecDelDtor)(
            v36,
            1i64,
            &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle);
      }
      v30[v28].pFill.pObject = v35;
      v30[v28].SizeScale = 1.0;
      ++v27;
      ++v28;
    }
    while ( v27 < v2->Layers.Size );
  }
}

// File Line: 1585
// RVA: 0x9C7B50
void __fastcall Scaleform::Render::TextMeshProvider::addImage(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::TmpTextStorage *storage, Scaleform::Render::GlyphRunData *data, Scaleform::Render::Image *img)
{
  Scaleform::Render::Image *v4; // rsi
  Scaleform::Render::TmpTextStorage *v5; // r15
  Scaleform::Render::TextMeshProvider *v6; // r14
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm0_4
  __m128 v10; // xmm6
  signed int v11; // ecx
  Scaleform::Render::Texture *v12; // rdi
  Scaleform::Render::Texture *v13; // rcx
  Scaleform::Render::Texture *v14; // rcx
  Scaleform::Render::PrimitiveFill *v15; // r14
  signed int *v16; // rax
  signed int v17; // ecx
  unsigned __int64 v18; // rdi
  signed __int64 v19; // r11
  Scaleform::Render::TmpTextMeshEntry *v20; // r10
  Scaleform::Render::PrimitiveFillData initdata; // [rsp+8h] [rbp-71h]
  __int64 v22; // [rsp+30h] [rbp-49h]
  __int64 v23; // [rsp+38h] [rbp-41h]
  unsigned __int64 v24; // [rsp+48h] [rbp-31h]
  __int64 v25; // [rsp+50h] [rbp-29h]
  char v26; // [rsp+C0h] [rbp+47h]
  char v27; // [rsp+C8h] [rbp+4Fh]
  float v28; // [rsp+E0h] [rbp+67h]
  float vars0; // [rsp+E8h] [rbp+6Fh]
  void *retaddr; // [rsp+F0h] [rbp+77h]
  char v31; // [rsp+F8h] [rbp+7Fh]

  v4 = img;
  v5 = storage;
  v6 = this;
  v7 = data->NewLineX;
  v8 = data->NewLineY - (float)(vars0 * *(float *)&retaddr);
  if ( v31 )
  {
    v10 = (__m128)LODWORD(data->NewLineY);
    v9 = data->NewLineX;
    v10.m128_f32[0] = (float)((float)((float)(v10.m128_f32[0] * data->DirMtx.M[0][1])
                                    + (float)(v9 * data->DirMtx.M[0][0]))
                            + data->DirMtx.M[0][3])
                    + 0.5;
    v11 = (signed int)v10.m128_f32[0];
    if ( (signed int)v10.m128_f32[0] != 0x80000000 && (float)v11 != v10.m128_f32[0] )
      v10.m128_f32[0] = (float)(v11 - (_mm_movemask_ps(_mm_unpacklo_ps(v10, v10)) & 1));
    v7 = (float)((float)(v10.m128_f32[0] * data->InvMtx.M[0][0])
               + (float)((float)((float)((float)(data->NewLineY * data->DirMtx.M[1][1])
                                       + (float)(v9 * data->DirMtx.M[1][0]))
                               + data->DirMtx.M[1][3])
                       * data->InvMtx.M[0][1]))
       + data->InvMtx.M[0][3];
  }
  LODWORD(v22) = 7;
  HIDWORD(v22) = storage->Entries.Size;
  v12 = (Scaleform::Render::Texture *)img->vfptr[21].__vecDelDtor(
                                        (Scaleform::RefCountImplCore *)img,
                                        (unsigned int)v6->pCache->pTexMan);
  initdata.pFormat = (Scaleform::Render::VertexFormat *)Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>;
  `eh vector constructor iterator'(
    initdata.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  initdata.pFormat = &Scaleform::Render::ImageGlyphVertex::Format;
  *(_WORD *)&initdata.FillModes[0].Fill = 3;
  if ( v12 )
    _InterlockedExchangeAdd(&v12->RefCount, 1u);
  v13 = initdata.Textures[0].pObject;
  if ( initdata.Textures[0].pObject && !_InterlockedDecrement(&initdata.Textures[0].pObject->RefCount) && v13 )
    v13->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v13->vfptr, 1u);
  initdata.Textures[0].pObject = v12;
  v14 = initdata.Textures[1].pObject;
  if ( initdata.Textures[1].pObject && !_InterlockedDecrement(&initdata.Textures[1].pObject->RefCount) && v14 )
    v14->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v14->vfptr, 1u);
  initdata.Textures[1].pObject = 0i64;
  v15 = Scaleform::Render::PrimitiveFillManager::CreateFill(v6->pCache->pFillMan, &initdata);
  v24 = __PAIR__(LODWORD(v8), LODWORD(v7));
  v16 = (signed int *)v4->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, (unsigned int)&v26);
  *(float *)&v25 = (float)((float)*v16 * v28) + v7;
  v17 = *(_DWORD *)((__int64)v4->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, (unsigned int)&v27) + 4);
  *((float *)&v25 + 1) = (float)((float)v17 * vars0) + v8;
  v18 = v5->Entries.Size >> 6;
  if ( v18 >= v5->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(
      &v5->Entries,
      v5->Entries.Size >> 6);
  v19 = v5->Entries.Size & 0x3F;
  v20 = v5->Entries.Pages[v18];
  *(_QWORD *)&v20[v19].LayerType = v22;
  *(_QWORD *)&v20[v19].mColor = v23;
  v20[v19].pFill = v15;
  v20[v19].EntryData.VectorData.pFont = (Scaleform::Render::Font *)v24;
  *(_QWORD *)&v20[v19].EntryData.MaskData.Coord[2] = v25;
  v20[v19].EntryData.RasterData.pGlyph = (Scaleform::Render::GlyphNode *)v4;
  ++v5->Entries.Size;
  `eh vector destructor iterator'(
    initdata.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
}

// File Line: 1613
// RVA: 0x9D21B0
float __fastcall Scaleform::Render::TextMeshProvider::calcHeightRatio(Scaleform::Render::MatrixPoolImpl::HMatrix *m, Scaleform::Render::Matrix4x4<float> *m4, Scaleform::Render::Viewport *vp)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *v3; // r9
  bool v4; // zf
  __int64 v5; // rax
  float v6; // xmm1_4
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm6_4
  float v10; // xmm3_4
  unsigned int v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  float result; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  Scaleform::Render::Rect<float> bounds; // [rsp+30h] [rbp-19h]
  int v22; // [rsp+40h] [rbp-9h]
  int v23; // [rsp+44h] [rbp-5h]
  Scaleform::Render::Matrix2x4<float> v24; // [rsp+50h] [rbp+7h]
  float dst; // [rsp+70h] [rbp+27h]

  v3 = m->pHandle->pHeader;
  v4 = (m->pHandle->pHeader->Format & 0x10) == 0;
  v5 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[m->pHandle->pHeader->Format & 0xF].Offsets[4];
  v6 = *(float *)&v3[v5 + 1].DataPageOffset;
  v7 = *(float *)&v3[v5 + 1].pHandle;
  v8 = *((float *)&v3[v5 + 1].pHandle + 1);
  v9 = *(float *)&v3[v5 + 2].pHandle;
  v10 = *((float *)&v3[v5 + 2].pHandle + 1);
  LODWORD(v24.M[0][2]) = v3[v5 + 1].RefCount;
  v11 = v3[v5 + 2].RefCount;
  v24.M[0][3] = v6;
  v12 = *(float *)&v3[v5 + 2].DataPageOffset;
  *(_QWORD *)&v24.M[0][0] = __PAIR__(LODWORD(v8), LODWORD(v7));
  v24.M[1][3] = v12;
  v24.M[1][0] = v9;
  *(_QWORD *)&v24.M[1][1] = __PAIR__(v11, LODWORD(v10));
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
      result = v20;
  }
  else
  {
    v13 = (float)vp->Height;
    v14 = (float)vp->Width;
    bounds = (Scaleform::Render::Rect<float>)_xmm;
    Scaleform::Render::Matrix4x4<float>::TransformHomogeneousAndScaleCorners(m4, &bounds, v14, v13, &dst);
    *(_QWORD *)&bounds.x1 = 0i64;
    *(_QWORD *)&bounds.x2 = 1065353216i64;
    v22 = 1065353216;
    v23 = 1065353216;
    Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v24, &bounds.x1, &dst);
    v15 = (__m128)LODWORD(v24.M[1][0]);
    v16 = (__m128)LODWORD(v24.M[1][1]);
    v15.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v24.M[0][0] * v24.M[0][0]);
    v16.m128_f32[0] = (float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v24.M[0][1] * v24.M[0][1]);
    if ( v16.m128_f32[0] >= v15.m128_f32[0] )
      v15 = v16;
    result = FLOAT_0_0000099999997;
    LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v15);
    if ( v18 >= 0.0000099999997 )
      result = v18;
  }
  return result;
}

// File Line: 1652
// RVA: 0x9C8A90
void __fastcall Scaleform::Render::TextMeshProvider::addRasterGlyph(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::TmpTextStorage *storage, Scaleform::Render::TextLayerType type, Scaleform::Render::GlyphRunData *data, unsigned int color, Scaleform::Render::GlyphNode *node, float screenSize, bool snap, float stretch)
{
  float v9; // xmm3_4
  Scaleform::Render::GlyphRunData *v10; // rdi
  Scaleform::Render::TextLayerType v11; // ebp
  Scaleform::Render::TmpTextStorage *v12; // r14
  Scaleform::Render::TextMeshProvider *v13; // rsi
  unsigned __int16 v14; // r8
  unsigned __int16 v15; // dx
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm0_4
  float v20; // xmm9_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm7_4
  float v24; // xmm9_4
  float v25; // xmm6_4
  float v26; // xmm8_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  Scaleform::Render::PrimitiveFill *v30; // rbp
  Scaleform::Render::Font *v31; // ST38_8
  __int64 v32; // ST40_8
  unsigned __int64 v33; // rsi
  Scaleform::Render::TmpTextMeshEntry *v34; // rdx
  signed __int64 v35; // r8
  __int64 v36; // [rsp+20h] [rbp-78h]
  __int64 v37; // [rsp+28h] [rbp-70h]

  v9 = data->NewLineX;
  v10 = data;
  v11 = type;
  v12 = storage;
  v13 = this;
  if ( snap && ((data->pFont->Flags >> 7) & 1 || node->Param.Flags & 1 && !(node->Param.Flags & 4)) )
    v9 = Scaleform::Render::TextMeshProvider::snapX(this, data);
  v14 = node->mRect.w;
  if ( v14 > 1u )
  {
    v15 = node->mRect.h;
    if ( v15 > 1u )
    {
      v16 = (float)((float)node->Origin.x * 0.0625) + 1.0;
      v17 = (float)((float)node->Origin.y * 0.0625) + 1.0;
      v18 = (float)((float)v14 + v16) - 2.0;
      v19 = (float)node->Param.FontSize * 0.0625;
      v20 = (float)((float)v15 + v17) - 2.0;
      if ( v19 < 0.0000099999997 )
        v19 = FLOAT_0_0000099999997;
      v21 = 0.0;
      v22 = (float)((float)(screenSize * node->Scale) / v19) / v10->HeightRatio;
      v23 = v17 * v22;
      v24 = v20 * v22;
      v25 = v16 * (float)(v22 / stretch);
      v26 = v18 * (float)(v22 / stretch);
      v27 = 0.0;
      if ( v11 == 2 )
      {
        v21 = v10->Param.ShadowOffsetX;
        v27 = v10->Param.ShadowOffsetY;
      }
      v28 = v27 + v10->NewLineY;
      v29 = v21 + v9;
      HIDWORD(v36) = v12->Entries.Size;
      LODWORD(v36) = __PAIR__(node->pSlot->TextureId, (unsigned __int16)v11) & 0x7FFFFFFF;
      LODWORD(v37) = color;
      v30 = Scaleform::Render::GlyphCache::GetFill(v13->pCache, v11, WORD1(v36));
      ++v30->RefCount;
      v33 = v12->Entries.Size >> 6;
      if ( v33 >= v12->Entries.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(&v12->Entries, v33);
      v34 = v12->Entries.Pages[v33];
      v35 = v12->Entries.Size & 0x3F;
      *(_QWORD *)&v34[v35].LayerType = v36;
      *(_QWORD *)&v34[v35].mColor = v37;
      v34[v35].pFill = v30;
      *((float *)&v31 + 1) = v23 + v28;
      *(float *)&v31 = v25 + v29;
      v34[v35].EntryData.VectorData.pFont = v31;
      *((float *)&v32 + 1) = v24 + v28;
      *(float *)&v32 = v26 + v29;
      *(_QWORD *)&v34[v35].EntryData.MaskData.Coord[2] = v32;
      v34[v35].EntryData.RasterData.pGlyph = node;
      ++v12->Entries.Size;
    }
  }
}

// File Line: 1716
// RVA: 0x9CA350
void __fastcall Scaleform::Render::TextMeshProvider::addTextureGlyph(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::TmpTextStorage *storage, Scaleform::Render::TextureGlyph *tgl, Scaleform::Render::GlyphRunData *data)
{
  Scaleform::Render::GlyphRunData *v4; // rbx
  Scaleform::Render::TextureGlyph *v5; // r15
  Scaleform::Render::TmpTextStorage *v6; // r13
  Scaleform::Render::TextMeshProvider *v7; // rsi
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm7_4
  float v13; // xmm2_4
  float v14; // xmm8_4
  float v15; // xmm9_4
  float v16; // xmm6_4
  Scaleform::Render::Image *v17; // rcx
  Scaleform::Render::Texture *v18; // r14
  Scaleform::Render::Texture *v19; // rcx
  Scaleform::Render::Texture *v20; // rcx
  Scaleform::Render::PrimitiveFill *v21; // r14
  Scaleform::Ptr<Scaleform::Render::Texture> *v22; // rcx
  int v23; // eax
  Scaleform::Render::Image *v24; // rcx
  Scaleform::RefCountImplCoreVtbl *v25; // r8
  Scaleform::Render::TextureManager *v26; // rdx
  Scaleform::Render::Texture *v27; // r14
  Scaleform::Render::Texture *v28; // rcx
  Scaleform::Render::Texture *v29; // rcx
  Scaleform::Render::Texture *v30; // r14
  Scaleform::Render::Texture *v31; // rcx
  Scaleform::Render::Texture *v32; // rcx
  unsigned __int64 v33; // rdi
  signed __int64 v34; // r8
  Scaleform::Render::TmpTextMeshEntry *v35; // rdx
  Scaleform::Render::PrimitiveFillData v36; // [rsp+30h] [rbp-A8h]
  Scaleform::Render::PrimitiveFillData initdata; // [rsp+58h] [rbp-80h]
  __int64 v38; // [rsp+80h] [rbp-58h]
  __int64 v39; // [rsp+88h] [rbp-50h]
  unsigned __int64 v40; // [rsp+98h] [rbp-40h]
  unsigned __int64 v41; // [rsp+A0h] [rbp-38h]
  __int64 v42; // [rsp+B0h] [rbp-28h]
  int v43; // [rsp+130h] [rbp+58h]
  int v44; // [rsp+134h] [rbp+5Ch]
  void *retaddr; // [rsp+148h] [rbp+70h]

  v42 = -2i64;
  v4 = data;
  v5 = tgl;
  v6 = storage;
  v7 = this;
  v8 = data->NewLineX;
  tgl->pImage.pObject->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)tgl->pImage.pObject, (unsigned int)&v43);
  v9 = v4->FontSize / v4->TexHeight;
  v10 = (float)v43 * v9;
  v11 = (float)v44 * v9;
  v12 = (float)((float)(v5->UvBounds.x1 - v5->UvOrigin.x) * v10) + v8;
  v13 = v4->NewLineY;
  v14 = (float)((float)(v5->UvBounds.y1 - v5->UvOrigin.y) * v11) + v13;
  v15 = (float)((float)(v5->UvBounds.x2 - v5->UvOrigin.x) * v10) + v8;
  v16 = (float)((float)(v5->UvBounds.y2 - v5->UvOrigin.y) * v11) + v13;
  LODWORD(v38) = 5;
  HIDWORD(v38) = v6->Entries.Size;
  LODWORD(v39) = (_DWORD)retaddr;
  v17 = v5->pImage.pObject;
  if ( v4->pFont->Flags & 0x10000 )
  {
    v18 = (Scaleform::Render::Texture *)v17->vfptr[21].__vecDelDtor(
                                          (Scaleform::RefCountImplCore *)&v17->vfptr,
                                          (unsigned int)v7->pCache->pTexMan);
    *(_QWORD *)&initdata.Type = 13i64;
    `eh vector constructor iterator'(
      initdata.Textures,
      8ui64,
      2,
      (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
    initdata.pFormat = &Scaleform::Render::RasterGlyphVertex::Format;
    *(_WORD *)&initdata.FillModes[0].Fill = 3;
    if ( v18 )
      _InterlockedExchangeAdd(&v18->RefCount, 1u);
    v19 = initdata.Textures[0].pObject;
    if ( initdata.Textures[0].pObject && !_InterlockedDecrement(&initdata.Textures[0].pObject->RefCount) && v19 )
      v19->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v19->vfptr, 1u);
    initdata.Textures[0].pObject = v18;
    v20 = initdata.Textures[1].pObject;
    if ( initdata.Textures[1].pObject && !_InterlockedDecrement(&initdata.Textures[1].pObject->RefCount) && v20 )
      v20->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v20->vfptr, 1u);
    initdata.Textures[1].pObject = 0i64;
    v21 = Scaleform::Render::PrimitiveFillManager::CreateFill(v7->pCache->pFillMan, &initdata);
    LOWORD(v38) = 6;
    v7->Flags |= 0x200u;
    v22 = initdata.Textures;
  }
  else
  {
    v23 = ((__int64 (*)(void))v17->vfptr[4].__vecDelDtor)();
    v24 = v5->pImage.pObject;
    v25 = v24->vfptr;
    v26 = v7->pCache->pTexMan;
    if ( v23 == 9 )
    {
      v27 = (Scaleform::Render::Texture *)v25[21].__vecDelDtor(
                                            (Scaleform::RefCountImplCore *)&v24->vfptr,
                                            (unsigned int)v26);
      *(_QWORD *)&v36.Type = 12i64;
      `eh vector constructor iterator'(
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
        v28->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v28->vfptr, 1u);
      v36.Textures[0].pObject = v27;
      v29 = v36.Textures[1].pObject;
      if ( v36.Textures[1].pObject && !_InterlockedDecrement(&v36.Textures[1].pObject->RefCount) && v29 )
        v29->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v29->vfptr, 1u);
      v36.Textures[1].pObject = 0i64;
      v21 = Scaleform::Render::PrimitiveFillManager::CreateFill(v7->pCache->pFillMan, &v36);
      v22 = v36.Textures;
    }
    else
    {
      v30 = (Scaleform::Render::Texture *)v25[21].__vecDelDtor(
                                            (Scaleform::RefCountImplCore *)&v24->vfptr,
                                            (unsigned int)v26);
      *(_QWORD *)&initdata.Type = 11i64;
      `eh vector constructor iterator'(
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
        v31->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v31->vfptr, 1u);
      initdata.Textures[0].pObject = v30;
      v32 = initdata.Textures[1].pObject;
      if ( initdata.Textures[1].pObject && !_InterlockedDecrement(&initdata.Textures[1].pObject->RefCount) && v32 )
        v32->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v32->vfptr, 1u);
      initdata.Textures[1].pObject = 0i64;
      v21 = Scaleform::Render::PrimitiveFillManager::CreateFill(v7->pCache->pFillMan, &initdata);
      v22 = initdata.Textures;
    }
  }
  `eh vector destructor iterator'(
    v22,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
  v40 = __PAIR__(LODWORD(v14), LODWORD(v12));
  v41 = __PAIR__(LODWORD(v16), LODWORD(v15));
  v33 = v6->Entries.Size >> 6;
  if ( v33 >= v6->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(
      &v6->Entries,
      v6->Entries.Size >> 6);
  v34 = v6->Entries.Size & 0x3F;
  v35 = v6->Entries.Pages[v33];
  *(_QWORD *)&v35[v34].LayerType = v38;
  *(_QWORD *)&v35[v34].mColor = v39;
  v35[v34].pFill = v21;
  v35[v34].EntryData.VectorData.pFont = (Scaleform::Render::Font *)v40;
  *(_QWORD *)&v35[v34].EntryData.MaskData.Coord[2] = v41;
  v35[v34].EntryData.RasterData.pGlyph = (Scaleform::Render::GlyphNode *)v5;
  ++v6->Entries.Size;
}

// File Line: 1780
// RVA: 0x9C73D0
char __usercall Scaleform::Render::TextMeshProvider::addGlyph@<al>(Scaleform::Render::TextMeshProvider *this@<rcx>, Scaleform::Render::TmpTextStorage *storage@<rdx>, Scaleform::Render::GlyphRunData *data@<r8>, unsigned int glyphIndex@<r9d>, float a5@<xmm0>)
{
  unsigned int v5; // er12
  Scaleform::Render::GlyphRunData *v6; // rbx
  Scaleform::Render::TmpTextStorage *v7; // r13
  Scaleform::Render::TextMeshProvider *v8; // rsi
  float v9; // xmm7_4
  Scaleform::Render::TextureGlyph *v10; // rax
  unsigned __int8 v12; // r14
  unsigned __int8 v13; // di
  Scaleform::Render::FontCacheHandle *v14; // r15
  unsigned __int16 v15; // cx
  __int16 v16; // di
  unsigned __int16 v17; // di
  Scaleform::Render::GlyphCache *v18; // r14
  __m128d v19; // xmm1
  __int64 v20; // rcx
  unsigned int v21; // ecx
  __int16 v22; // di
  unsigned __int16 v23; // di
  Scaleform::Render::Font *v24; // rcx
  unsigned int v25; // er8
  unsigned __int16 v26; // dx
  float v27; // xmm6_4
  Scaleform::Render::GlyphCache *v28; // r14
  Scaleform::Render::GlyphNode *v29; // rax
  Scaleform::Render::GlyphNode *v30; // rdi
  Scaleform::Render::TextNotifier *v31; // rax
  Scaleform::Render::GlyphNode *v32; // rax
  Scaleform::Render::GlyphCache *v33; // rcx
  Scaleform::Render::GlyphCache::RasResult v34; // eax
  float v35; // xmm5_4
  float v36; // xmm8_4
  float v37; // xmm7_4
  float v38; // xmm0_4
  float v39; // xmm6_4
  char v40; // bl
  Scaleform::Render::ShapeDataInterface *v41; // rcx
  char v42; // al
  unsigned __int16 v43; // di
  unsigned int v44; // er14
  unsigned __int16 v45; // dx
  __int16 v46; // cx
  unsigned __int16 v47; // cx
  Scaleform::Render::GlyphCache *v48; // r15
  __m128d v49; // xmm1
  __int64 v50; // rcx
  Scaleform::Render::GlyphNode *v51; // rax
  Scaleform::Render::GlyphNode *v52; // rdi
  Scaleform::Render::TextNotifier *v53; // rax
  Scaleform::Render::GlyphNode *v54; // rax
  char color; // [rsp+20h] [rbp-71h]
  Scaleform::Render::GlyphNode *node; // [rsp+28h] [rbp-69h]
  bool needsVectorShape[4]; // [rsp+38h] [rbp-59h]
  float v58; // [rsp+3Ch] [rbp-55h]
  float stretch; // [rsp+40h] [rbp-51h]
  float v60; // [rsp+44h] [rbp-4Dh]
  Scaleform::Render::GlyphParam gp; // [rsp+48h] [rbp-49h]
  char v62; // [rsp+E8h] [rbp+57h]
  unsigned __int16 glyphIndexa[2]; // [rsp+F0h] [rbp+5Fh]
  unsigned __int8 v64; // [rsp+F8h] [rbp+67h]
  unsigned __int8 vars0; // [rsp+100h] [rbp+6Fh]
  _BOOL8 retaddr; // [rsp+108h] [rbp+77h]

  v5 = glyphIndex;
  v6 = data;
  v7 = storage;
  v8 = this;
  v62 = 1;
  v9 = data->HeightRatio * data->FontSize;
  v10 = (Scaleform::Render::TextureGlyph *)data->pFont->vfptr[10].__vecDelDtor(
                                             (Scaleform::RefCountImplCore *)data->pFont,
                                             glyphIndex);
  if ( !v10 )
    goto LABEL_8;
  if ( !((v6->pFont->Flags >> 12) & 1) )
  {
    a5 = v8->pCache->Param.MaxRasterScale * v6->TexHeight;
    if ( v9 > a5 )
    {
      v62 = 0;
LABEL_8:
      v12 = vars0;
      v13 = v64;
      node = (Scaleform::Render::GlyphNode *)Scaleform::Render::GlyphCache::CreateGlyphShape(
                                               v8->pCache,
                                               v6,
                                               v5,
                                               v9,
                                               a5,
                                               v64 | ((unsigned __int8)v6->Param.TextParam.Flags >> 3) & 1u,
                                               vars0 | ((unsigned __int8)v6->Param.TextParam.Flags >> 4) & 1u,
                                               (unsigned int)v6->Param.TextParam.Flags >> 12,
                                               0);
      gp.pFont = v6->Param.TextParam.pFont;
      *(_QWORD *)&gp.GlyphIndex = *(_QWORD *)&v6->Param.TextParam.GlyphIndex;
      *(_QWORD *)&gp.BlurY = *(_QWORD *)&v6->Param.TextParam.BlurY;
      v14 = v6->pFontHandle;
      gp.pFont = v6->pFontHandle;
      gp.GlyphIndex = v5;
      v15 = v6->Param.TextParam.Flags;
      if ( v13 | ((unsigned __int8)v15 >> 3) & 1 )
        v16 = gp.Flags | 8;
      else
        v16 = gp.Flags & 0xFFF7;
      if ( v12 | ((unsigned __int8)v15 >> 4) & 1 )
        v17 = v16 | 0x10;
      else
        v17 = v16 & 0xFFEF;
      gp.Flags = v17;
      v18 = v8->pCache;
      v19 = 0i64;
      v19.m128d_f64[0] = (float)(Scaleform::Render::GlyphCache::GetCachedFontSize(
                                   v8->pCache,
                                   &gp,
                                   v9,
                                   v6->pRaster != 0i64)
                               * 16.0);
      v20 = (unsigned int)(signed int)v19.m128d_f64[0];
      if ( v20 != 0x8000000000000000i64 && (double)(signed int)v20 != v19.m128d_f64[0] )
        v19.m128d_f64[0] = (double)(signed int)(v20 - (_mm_movemask_pd(_mm_unpckl_pd(v19, v19)) & 1));
      gp.FontSize = (signed int)v19.m128d_f64[0];
      v21 = v6->RasterSize;
      if ( v21 )
        v22 = v17 | 0x200;
      else
        v22 = v17 & 0xFDFF;
      v23 = v22 & 0xFFFB;
      gp.Flags = v23;
      if ( v23 & 1 )
      {
        if ( !(v23 & 0x100) && !v6->VectorSize && !v21 )
        {
          v24 = v14->pFont;
          if ( !((v24->Flags >> 7) & 1)
            && (float)((float)gp.BlurX * 0.0625) == 0.0
            && (float)((float)gp.BlurY * 0.0625) == 0.0 )
          {
            v24->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v24->vfptr, (unsigned __int16)v5);
            ((void (*)(void))gp.pFont->pFont->vfptr[22].__vecDelDtor)();
            v18 = v8->pCache;
            if ( (float)((float)((float)(0.0 * v9) / 0.0) * 3.0) < (float)(signed int)v18->Queue.MaxSlotHeight )
              gp.Flags |= 4u;
          }
        }
      }
      if ( *(_BYTE *)(((__int64 (*)(void))v18->vfptr->GetParams)() + 52)
        && (_BYTE)retaddr
        && !(gp.Flags & 0xF000)
        && gp.Flags & 1
        && (LOBYTE(gp.Flags) >> 1) & 1
        && v9 > 6.0
        && ((v25 = gp.pFont->pFont->Flags, (v25 >> 13) & 1) || (v25 >> 4) & 1) )
      {
        v26 = gp.Flags | 2;
      }
      else
      {
        v26 = gp.Flags & 0xFFFD;
      }
      gp.Flags = v26;
      if ( (LOBYTE(v6->Param.ShadowParam.Flags) >> 5) & 1 )
      {
        if ( !color )
          goto LABEL_65;
      }
      else if ( !color )
      {
        if ( v26 & 4 )
          v27 = FLOAT_2_5;
        else
          v27 = *(float *)&FLOAT_1_0;
        v28 = v8->pCache;
        v29 = Scaleform::Render::GlyphQueue::FindGlyph(&v28->Queue, &gp);
        v30 = v29;
        if ( v29 )
        {
          v31 = Scaleform::Render::GlyphQueue::CreateNotifier(&v28->Queue, v29, v8);
          Scaleform::Render::TextMeshProvider::AddNotifier(v8, v31);
          Scaleform::Render::TextMeshProvider::addRasterGlyph(
            v8,
            v7,
            TextLayer_RasterText,
            v6,
            v6->mColor,
            v30,
            v9,
            retaddr,
            v27);
          goto LABEL_65;
        }
        if ( gp.BlurX || gp.BlurY )
          v32 = Scaleform::Render::GlyphCache::RasterizeShadow(v8->pCache, v6, v8, &gp, v9, v6->pRaster);
        else
          v32 = Scaleform::Render::GlyphCache::RasterizeGlyph(v8->pCache, v6, v8, &gp);
        if ( v32 )
        {
          Scaleform::Render::TextMeshProvider::addRasterGlyph(
            v8,
            v7,
            TextLayer_RasterText,
            v6,
            v6->mColor,
            v32,
            v9,
            retaddr,
            v27);
          goto LABEL_65;
        }
        v33 = v8->pCache;
        v34 = v33->Result;
        switch ( v34 )
        {
          case 2:
            v35 = v6->FontSize * 0.25;
            v36 = v6->FontSize * 0.5;
            v37 = v6->NewLineY - (float)(v36 * 0.25);
            v38 = (float)(v6->NewLineX + v35) + (float)(v35 * 0.5);
            v39 = (float)(v6->NewLineY - v36) - (float)(v36 * 0.25);
            *(float *)needsVectorShape = (float)(v35 * 0.5) + v6->NewLineX;
            v58 = v39;
            stretch = v38;
            v60 = v37;
            Scaleform::Render::TextMeshProvider::addSelection(
              v8,
              v7,
              v6->mColor,
              (Scaleform::Render::Rect<float> *)needsVectorShape);
LABEL_83:
            v40 = 1;
            goto LABEL_84;
          case 1:
            goto LABEL_83;
          case 5:
            if ( !*(_BYTE *)(((__int64 (*)(void))v33->vfptr->GetParams)() + 53) )
            {
              v40 = 0;
              goto LABEL_84;
            }
            break;
          default:
            if ( (unsigned int)(v34 - 3) > 1 )
              goto LABEL_65;
            break;
        }
      }
      v41 = v6->pShape;
      if ( v41 )
      {
        v42 = ((__int64 (*)(void))v41->vfptr[1].__vecDelDtor)();
        v43 = glyphIndexa[0];
        if ( !v42 )
        {
          Scaleform::Render::TextMeshProvider::addVectorGlyph(
            v8,
            v7,
            v6->mColor,
            v6->pFontHandle,
            glyphIndexa[0],
            gp.Flags,
            v6->FontSize,
            v6->NewLineX,
            v6->NewLineY);
          v8->Flags |= 0x40u;
        }
        goto LABEL_66;
      }
LABEL_65:
      v43 = glyphIndexa[0];
LABEL_66:
      v44 = v6->Param.ShadowColor;
      if ( !v44 || !v62 )
        goto LABEL_83;
      gp.pFont = v6->Param.ShadowParam.pFont;
      *(_QWORD *)&gp.GlyphIndex = *(_QWORD *)&v6->Param.ShadowParam.GlyphIndex;
      *(_QWORD *)&gp.BlurY = *(_QWORD *)&v6->Param.ShadowParam.BlurY;
      gp.pFont = v6->pFontHandle;
      v45 = v6->Param.TextParam.Flags;
      if ( v64 | ((unsigned __int8)v45 >> 3) & 1 )
        v46 = gp.Flags & 0xFFFC | 8;
      else
        v46 = gp.Flags & 0xFFF4;
      if ( vars0 | ((unsigned __int8)v45 >> 4) & 1 )
        v47 = v46 | 0x10;
      else
        v47 = v46 & 0xFFEF;
      gp.Flags = v47;
      v48 = v8->pCache;
      v49 = 0i64;
      v49.m128d_f64[0] = (float)(Scaleform::Render::GlyphCache::GetCachedShadowSize(v8->pCache, v9, v6->pRaster) * 16.0);
      v50 = (unsigned int)(signed int)v49.m128d_f64[0];
      if ( v50 != 0x8000000000000000i64 && (double)(signed int)v50 != v49.m128d_f64[0] )
        v49.m128d_f64[0] = (double)(signed int)(v50 - (_mm_movemask_pd(_mm_unpckl_pd(v49, v49)) & 1));
      gp.FontSize = (signed int)v49.m128d_f64[0];
      gp.GlyphIndex = v43;
      v51 = Scaleform::Render::GlyphQueue::FindGlyph(&v48->Queue, &gp);
      v52 = v51;
      if ( v51 )
      {
        v53 = Scaleform::Render::GlyphQueue::CreateNotifier(&v48->Queue, v51, v8);
        Scaleform::Render::TextMeshProvider::AddNotifier(v8, v53);
        Scaleform::Render::TextMeshProvider::addRasterGlyph(v8, v7, TextLayer_Shadow, v6, v44, v52, v9, retaddr, 1.0);
        goto LABEL_83;
      }
      v54 = Scaleform::Render::GlyphCache::RasterizeShadow(v8->pCache, v6, v8, &gp, v9, v6->pRaster);
      if ( v54 )
      {
        Scaleform::Render::TextMeshProvider::addRasterGlyph(v8, v7, TextLayer_Shadow, v6, v44, v54, v9, retaddr, 1.0);
        goto LABEL_83;
      }
      if ( v8->pCache->Result != 5 )
        goto LABEL_83;
      v40 = 0;
LABEL_84:
      if ( node )
        (*(void (**)(void))(*(_QWORD *)&node->Param.BlurY + 16i64))();
      return v40;
    }
  }
  if ( v10->pImage.pObject )
    Scaleform::Render::TextMeshProvider::addTextureGlyph(v8, v7, v10, v6, v6->mColor);
  return 1;
}

// File Line: 1939
// RVA: 0x9F25F0
float __fastcall Scaleform::Render::TextMeshProvider::snapX(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::GlyphRunData *data)
{
  __m128 v2; // xmm1
  signed int v3; // ecx

  v2 = (__m128)LODWORD(data->NewLineY);
  v2.m128_f32[0] = (float)((float)((float)(v2.m128_f32[0] * data->DirMtx.M[0][1])
                                 + (float)(data->NewLineX * data->DirMtx.M[0][0]))
                         + data->DirMtx.M[0][3])
                 + 0.5;
  v3 = (signed int)v2.m128_f32[0];
  if ( (signed int)v2.m128_f32[0] != 0x80000000 && (float)v3 != v2.m128_f32[0] )
    v2.m128_f32[0] = (float)(v3 - (_mm_movemask_ps(_mm_unpacklo_ps(v2, v2)) & 1));
  return (float)((float)(v2.m128_f32[0] * data->InvMtx.M[0][0])
               + (float)((float)((float)((float)(data->NewLineY * data->DirMtx.M[1][1])
                                       + (float)(data->NewLineX * data->DirMtx.M[1][0]))
                               + data->DirMtx.M[1][3])
                       * data->InvMtx.M[0][1]))
       + data->InvMtx.M[0][3];
}

// File Line: 1965
// RVA: 0x95CB80
__int64 __fastcall Scaleform::Render::TextMeshProvider::CalcVectorParams(Scaleform::Render::TextMeshLayer *layer, Scaleform::Render::TextMeshEntry *ent, Scaleform::Render::Matrix2x4<float> *scalingMtx, float sizeScale)
{
  float v4; // xmm11_4
  Scaleform::Render::Matrix2x4<float> *v5; // r14
  Scaleform::Render::TextMeshEntry *v6; // r13
  Scaleform::Render::TextMeshLayer *v7; // rdx
  __int64 v8; // r12
  __int64 v9; // rcx
  float v10; // xmm1_4
  __int64 v11; // rcx
  unsigned int v12; // eax
  unsigned int v13; // edx
  float v14; // er8
  int v15; // er9
  int v16; // er10
  int v17; // er11
  int v18; // ebx
  int v19; // edi
  int v20; // esi
  int v21; // er14
  int v22; // er15
  __m128 v23; // xmm8
  Scaleform::Render::MatrixPoolImpl::HMatrix *v24; // rdi
  Scaleform::Render::MatrixPoolImpl::HMatrix *v25; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v26; // rbx
  bool v27; // zf
  __int64 v28; // rcx
  __int64 v29; // rcx
  float v30; // xmm9_4
  float v31; // xmm5_4
  float v32; // xmm10_4
  float v33; // xmm6_4
  float v34; // xmm7_4
  float v35; // xmm8_4
  float v36; // xmm3_4
  float v37; // xmm9_4
  float v38; // xmm10_4
  Scaleform::Render::MatrixPoolImpl::HMatrix *v39; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v40; // rbx
  __int64 v41; // rcx
  __int64 v42; // rdx
  __m128 *v43; // rax
  __m128 v44; // xmm1
  unsigned int v45; // edi
  bool v46; // al
  signed __int64 v47; // rcx
  char v49[36]; // [rsp+28h] [rbp-79h]
  float v50; // [rsp+4Ch] [rbp-55h]
  Scaleform::Render::Matrix3x4<float> v51; // [rsp+50h] [rbp-51h]
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+E8h] [rbp+47h]
  Scaleform::Render::Matrix2x4<float> *v53; // [rsp+F8h] [rbp+57h]
  __int64 **v54; // [rsp+108h] [rbp+67h]
  __int64 vars0; // [rsp+110h] [rbp+6Fh]
  void *retaddr; // [rsp+118h] [rbp+77h]
  float *key; // [rsp+120h] [rbp+7Fh]

  key = (float *)layer;
  v4 = sizeScale;
  v5 = scalingMtx;
  v6 = ent;
  v7 = layer;
  v8 = **v54;
  v9 = *(_BYTE *)(v8 + 15) & 0xF;
  if ( *(_BYTE *)(v8 + 15) & 0x10 )
  {
    *(float *)&v49[8] = sizeScale;
    *(_QWORD *)&v49[12] = 0i64;
    *(float *)&v49[28] = sizeScale;
    *(_DWORD *)&v49[32] = 0;
    v10 = v6->EntryData.VectorData.y;
    *(_QWORD *)&v49[20] = v6->EntryData.BackgroundData.BorderColor;
    v50 = v10;
    v11 = 16
        * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v9].Offsets[4];
    v12 = *(_DWORD *)(v11 + v8 + 16);
    v13 = *(_DWORD *)(v11 + v8 + 20);
    v14 = *(float *)(v11 + v8 + 24);
    v15 = *(_DWORD *)(v11 + v8 + 28);
    v16 = *(_DWORD *)(v11 + v8 + 32);
    v17 = *(_DWORD *)(v11 + v8 + 36);
    v18 = *(_DWORD *)(v11 + v8 + 40);
    v19 = *(_DWORD *)(v11 + v8 + 44);
    v20 = *(_DWORD *)(v11 + v8 + 48);
    v21 = *(_DWORD *)(v11 + v8 + 52);
    v22 = *(_DWORD *)(v11 + v8 + 56);
    LODWORD(v11) = *(_DWORD *)(v11 + v8 + 60);
    *(_QWORD *)&v51.M[0][0] = __PAIR__(v13, v12);
    v51.M[0][2] = v14;
    *(_DWORD *)v49 = v16;
    *(_DWORD *)&v49[4] = v17;
    *(_DWORD *)&v49[8] = v18;
    *(_DWORD *)&v49[12] = v19;
    *(_DWORD *)&v49[16] = v20;
    *(_DWORD *)&v49[20] = v21;
    *(_DWORD *)&v49[24] = v22;
    *(_QWORD *)&v49[28] = (unsigned int)v11;
    v23 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v49[16], *(__m128 *)&v49[16], 0), *(__m128 *)&v49[8]),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v49[16], *(__m128 *)&v49[16], 85), *(__m128 *)&v49[24])),
            _mm_and_ps(
              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>'::`2'::v,
              *(__m128 *)&v49[16]));
    *(__m128 *)&v51.M[0][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&v51.M[0][0], *(__m128 *)&v51.M[0][0], 0),
                                    *(__m128 *)&v49[8]),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&v51.M[0][0], *(__m128 *)&v51.M[0][0], 85),
                                    *(__m128 *)&v49[24])),
                                _mm_and_ps(
                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>'::`2'::v,
                                  *(__m128 *)&v51.M[0][0]));
    *(__m128 *)v49 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v49, *(__m128 *)v49, 0), *(__m128 *)&v49[8]),
                         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v49, *(__m128 *)v49, 85), *(__m128 *)&v49[24])),
                       _mm_and_ps(
                         (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>'::`2'::v,
                         *(__m128 *)v49));
    *(__m128 *)&v49[16] = v23;
    v24 = (Scaleform::Render::MatrixPoolImpl::HMatrix *)&result.pHandle[5];
    if ( result.pHandle[5].pNext == &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
      v25 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
              (Scaleform::Render::MatrixPoolImpl::MatrixPool *)(vars0 + 3408),
              &result,
              &v51,
              0x10u);
      Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(v24, v25);
      if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      {
        v26 = result.pHandle->pHeader;
        v27 = result.pHandle->pHeader->RefCount == 1;
        --v26->RefCount;
        if ( v27 )
        {
          v28 = v26->DataPageOffset;
          *(_WORD *)((char *)&v26[1].RefCount + v28 + 2) += 16 * (unsigned __int8)v26->UnitSize;
          (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v26[1].pHandle + v28))[5].pHeader += (unsigned __int8)v26->UnitSize;
          Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v26->pHandle);
          v26->pHandle = 0i64;
        }
      }
    }
    else
    {
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix3D(
        (Scaleform::Render::MatrixPoolImpl::HMatrix *)&result.pHandle[5],
        &v51);
    }
    v5 = v53;
  }
  else
  {
    v29 = 16
        * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v9].Offsets[4];
    v30 = *(float *)(v29 + v8 + 16);
    v31 = *(float *)(v29 + v8 + 20);
    v32 = *(float *)(v29 + v8 + 32);
    v33 = *(float *)(v29 + v8 + 36);
    v34 = *(float *)(v29 + v8 + 28)
        + (float)((float)(*(float *)(v29 + v8 + 16) * v6->EntryData.VectorData.x)
                + (float)(*(float *)(v29 + v8 + 20) * v6->EntryData.VectorData.y));
    v35 = *(float *)(v29 + v8 + 44)
        + (float)((float)(*(float *)(v29 + v8 + 32) * v6->EntryData.VectorData.x)
                + (float)(*(float *)(v29 + v8 + 36) * v6->EntryData.VectorData.y));
    v36 = *(float *)(v29 + v8 + 20) * 0.0;
    *(float *)&v49[8] = (float)(*(float *)(v29 + v8 + 16) * v4) + v36;
    *(float *)&v49[24] = (float)(v32 * v4) + (float)(v33 * 0.0);
    v37 = v30 * 0.0;
    *(float *)&v49[12] = (float)(v31 * v4) + v37;
    v38 = v32 * 0.0;
    *(float *)&v49[28] = (float)(v33 * v4) + v38;
    *(_DWORD *)&v49[32] = 0;
    *(_DWORD *)&v49[16] = 0;
    *(float *)&v49[20] = v34 + (float)(v37 + v36);
    v50 = v35 + (float)(v38 + (float)(v33 * 0.0));
    v24 = &v7->M;
    if ( v7->M.pHandle == &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
      v39 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
              (Scaleform::Render::MatrixPoolImpl::MatrixPool *)(vars0 + 3408),
              &result,
              (Scaleform::Render::Matrix2x4<float> *)&v49[8],
              0);
      Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(v24, v39);
      if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      {
        v40 = result.pHandle->pHeader;
        v27 = result.pHandle->pHeader->RefCount == 1;
        --v40->RefCount;
        if ( v27 )
        {
          v41 = v40->DataPageOffset;
          *(_WORD *)((char *)&v40[1].RefCount + v41 + 2) += 16 * (unsigned __int8)v40->UnitSize;
          (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v40[1].pHandle + v41))[5].pHeader += (unsigned __int8)v40->UnitSize;
          Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v40->pHandle);
          v40->pHandle = 0i64;
        }
      }
    }
    else
    {
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(v24, (Scaleform::Render::Matrix2x4<float> *)&v49[8]);
    }
  }
  LODWORD(result.pHandle) = v6->mColor;
  *(float *)&v49[24] = (float)BYTE2(result.pHandle) * 0.0039215689;
  *(float *)&v49[28] = (float)BYTE1(result.pHandle) * 0.0039215689;
  *(float *)&v49[32] = (float)LOBYTE(result.pHandle) * 0.0039215689;
  v50 = (float)BYTE3(result.pHandle) * 0.0039215689;
  v42 = **v54;
  if ( *(_BYTE *)(v42 + 15) & 1 )
    v43 = (__m128 *)(v42
                   + 16
                   * (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[*(_BYTE *)(v42 + 15) & 0xF].Offsets[0]
                   + 16i64);
  else
    v43 = (__m128 *)&Scaleform::Render::Cxform::Identity;
  v44 = _mm_mul_ps(*(__m128 *)&v49[24], *v43);
  *(__m128 *)&v49[8] = _mm_mul_ps((__m128)0i64, *v43);
  *(__m128 *)&v49[24] = _mm_add_ps(v43[1], v44);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(v24, (Scaleform::Render::Cxform *)&v49[8]);
  v45 = 1;
  if ( (unsigned __int8)retaddr & 1 )
    v45 = 65;
  if ( (unsigned __int8)retaddr & 2 )
    v45 |= 0x80u;
  v46 = Scaleform::Render::MeshKey::CalcMatrixKey(v5, key, 0i64);
  v47 = 3i64;
  if ( v45 & 0x10 )
    v47 = 13i64;
  key[v47] = 0.0;
  if ( !v46 )
    v45 |= 0x8000u;
  return v45;
}

// File Line: 2007
// RVA: 0x9DED30
void __fastcall Scaleform::Render::TextMeshProvider::createVectorGlyph(Scaleform::Render::TextMeshProvider *this, unsigned int layerIdx, Scaleform::Render::Renderer2DImpl *ren, Scaleform::Render::MatrixPoolImpl::HMatrix *m)
{
  Scaleform::Render::Renderer2DImpl *v4; // r12
  Scaleform::Render::TextMeshProvider *v5; // rdi
  Scaleform::Render::TextMeshLayer *v6; // rsi
  Scaleform::Render::TextMeshEntry *v7; // r13
  Scaleform::Render::Font *v8; // r14
  Scaleform::Render::GlyphCache *v9; // rbx
  Scaleform::Render::HAL *v10; // rcx
  Scaleform::Render::FontCacheHandleManager *v11; // rcx
  Scaleform::Render::FontCacheHandle *v12; // rax
  Scaleform::Render::VectorGlyphShape *v13; // r15
  float v14; // xmm6_4
  unsigned int v15; // eax
  Scaleform::Render::MeshKey *v16; // r14
  Scaleform::Render::MeshKey *v17; // rbx
  bool v18; // zf
  Scaleform::Render::MeshBase *v19; // rcx
  signed __int64 v20; // r14
  Scaleform::Render::VectorGlyphShape *v21; // rcx
  char *v22; // rdi
  Scaleform::Render::MeshKey *v23; // r15
  Scaleform::Render::MeshBase *v24; // rcx
  Scaleform::Render::Mesh *v25; // rdi
  Scaleform::Render::Mesh *v26; // rcx
  Scaleform::Render::Matrix2x4<float> scalingMtx; // [rsp+40h] [rbp-80h]
  Scaleform::Render::GlyphRunData data; // [rsp+60h] [rbp-60h]
  int v29; // [rsp+1F8h] [rbp+138h]
  Scaleform::Render::VectorGlyphShape *v30; // [rsp+200h] [rbp+140h]
  unsigned int v31; // [rsp+210h] [rbp+150h]

  *(_QWORD *)&data.InvMtx.M[0][0] = -2i64;
  v4 = ren;
  v5 = this;
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
  v8 = v7->EntryData.VectorData.pFont;
  *(_QWORD *)&data.Param.TextParam.BlurY = v7->EntryData.VectorData.pFont;
  v9 = this->pCache;
  if ( !v9->pFontHandleManager.pObject )
  {
    v10 = v9->pRenderer;
    if ( !v10 || !((unsigned __int8 (*)(void))v10->vfptr[4].__vecDelDtor)() )
      goto LABEL_7;
    Scaleform::Render::GlyphCache::initialize(v9);
  }
  v11 = v9->pFontHandleManager.pObject;
  if ( !v11 )
  {
LABEL_7:
    v12 = 0i64;
    goto LABEL_8;
  }
  v12 = Scaleform::Render::FontCacheHandleManager::RegisterFont(v11, v8);
LABEL_8:
  data.Param.ShadowParam.pFont = v12;
  *(float *)&data.Param.ShadowParam.GlyphIndex = v7->EntryData.RasterData.Coord[3];
  *(_QWORD *)&data.Param.ShadowParam.Flags = 0i64;
  *(_QWORD *)(&data.Param.ShadowParam.BlurStrength + 1) = 0i64;
  data.Param.ShadowOffsetX = 0.0;
  LODWORD(data.Param.ShadowOffsetY) = v7->mColor;
  *((_DWORD *)&data.Param.ShadowOffsetY + 1) = LODWORD(v7->EntryData.VectorData.x);
  data.Bounds.x1 = v7->EntryData.VectorData.y;
  *(_OWORD *)&data.pFont = 0i64;
  *(_QWORD *)&data.DirMtx.M[0][0] = LODWORD(v5->HeightRatio);
  LOWORD(scalingMtx.M[0][3]) = v7->EntryData.VectorData.Flags;
  v13 = Scaleform::Render::GlyphCache::CreateGlyphShape(
          v5->pCache,
          &data,
          v7->EntryData.VectorData.GlyphIndex,
          0.0,
          0.0,
          (LOBYTE(scalingMtx.M[0][3]) >> 3) & 1,
          (LOBYTE(scalingMtx.M[0][3]) >> 4) & 1,
          (unsigned int)LOWORD(scalingMtx.M[0][3]) >> 12,
          1);
  v30 = v13;
  LODWORD(data.DirMtx.M[0][1]) = v13->pShape.pObject->HintedSize;
  v14 = *(float *)&data.Param.ShadowParam.GlyphIndex / *(float *)&data.Param.ShadowColor;
  scalingMtx.M[0][0] = (float)(*(float *)&data.Param.ShadowParam.GlyphIndex / *(float *)&data.Param.ShadowColor)
                     * v5->HeightRatio;
  *(_OWORD *)&scalingMtx.M[0][1] = 0ui64;
  scalingMtx.M[1][1] = scalingMtx.M[0][0];
  *(_QWORD *)&scalingMtx.M[1][2] = 0i64;
  v15 = Scaleform::Render::TextMeshProvider::CalcVectorParams(
          v6,
          v7,
          &scalingMtx,
          *(float *)&data.Param.ShadowParam.GlyphIndex / *(float *)&data.Param.ShadowColor);
  v16 = Scaleform::Render::MeshKeyManager::CreateMatchingKey(
          v4->pMeshKeyManager.pObject,
          (Scaleform::Render::MeshProvider_KeySupport *)&v13->vfptr,
          0,
          v15,
          data.InvMtx.M[1],
          &v4->Tolerances);
  v17 = v6->pMeshKey.pObject;
  if ( v17 )
  {
    v18 = v17->UseCount-- == 1;
    if ( v18 )
    {
      v19 = v17->pMesh.pObject;
      if ( !v19 || ((unsigned __int8 (*)(void))v19->vfptr[1].__vecDelDtor)() || v17->Flags & 0x110 )
        Scaleform::Render::MeshKeySet::DestroyKey(v17->pKeySet, v17);
    }
  }
  v6->pMeshKey.pObject = v16;
  v20 = (signed __int64)&v13->vfptr;
  (*((void (__fastcall **)(Scaleform::Render::MeshProviderVtbl **))&v13->vfptr->__vecDelDtor + 1))(&v13->vfptr);
  v21 = v6->pShape.pObject;
  if ( v21 )
    ((void (*)(void))v21->vfptr->Release)();
  v6->pShape.pObject = v13;
  v6->SizeScale = v14;
  if ( !v6->pMeshKey.pObject->pMesh.pObject )
  {
    v29 = 68;
    v22 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                    Scaleform::Memory::pGlobalHeap,
                    v5,
                    240ui64,
                    (Scaleform::AllocInfo *)&v29);
    *(_QWORD *)&data.InvMtx.M[0][2] = v22;
    if ( v22 )
    {
      Scaleform::Render::MeshBase::MeshBase(
        (Scaleform::Render::MeshBase *)v22,
        v4,
        (Scaleform::Render::MeshProvider *)&v6->pMeshKey.pObject->pKeySet->vfptr,
        &scalingMtx,
        0.0,
        0,
        v31);
      *(_QWORD *)v22 = &Scaleform::Render::Mesh::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>'};
      *((_QWORD *)v22 + 2) = &Scaleform::Render::Mesh::`vftable'{for `Scaleform::Render::MeshStagingNode'};
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
    if ( v24 && !_InterlockedDecrement(&v24->RefCount) && v24 )
      v24->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v24->vfptr, 1u);
    v23->pMesh.pObject = (Scaleform::Render::MeshBase *)v22;
  }
  v25 = (Scaleform::Render::Mesh *)v6->pMeshKey.pObject->pMesh.pObject;
  if ( v25 )
    _InterlockedExchangeAdd(&v25->RefCount, 1u);
  v26 = v6->pMesh.pObject;
  if ( v26 && !_InterlockedDecrement(&v26->RefCount) && v26 )
    v26->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v26->vfptr, 1u);
  v6->pMesh.pObject = v25;
  (*(void (__fastcall **)(signed __int64))(*(_QWORD *)v20 + 16i64))(v20);
}

// File Line: 2062
// RVA: 0x967F10
char __fastcall Scaleform::Render::TextMeshProvider::CreateMeshData(Scaleform::Render::TextMeshProvider *this, Scaleform::Render::TextLayout *layout, Scaleform::Render::Renderer2DImpl *ren, Scaleform::Render::MatrixPoolImpl::HMatrix *m)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *v4; // rbx
  Scaleform::Render::TextLayout *v5; // r14
  Scaleform::Render::TextMeshProvider *v6; // rdi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v7; // r8
  Scaleform::Render::MatrixPoolImpl::DataHeader *v8; // rdx
  __int64 v9; // rcx
  float v10; // xmm4_4
  float v11; // xmm3_4
  float v12; // xmm5_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  char snap; // r15
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  Scaleform::Render::MatrixPoolImpl::DataHeader *v19; // rdx
  int v20; // eax
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  unsigned __int64 v27; // rbx
  float v28; // xmm9_4
  float v29; // xmm10_4
  float v30; // xmm8_4
  float v31; // xmm7_4
  Scaleform::Render::LinearHeap *v32; // r12
  float v33; // xmm6_4
  unsigned int v34; // er13
  char *v35; // rdx
  char v36; // cl
  signed __int64 v37; // rsi
  size_t v38; // r8
  __int64 v39; // rbx
  __int64 v40; // r15
  char v41; // al
  unsigned __int64 v42; // rsi
  signed __int64 v43; // rdx
  Scaleform::Render::TmpTextMeshEntry *v44; // rcx
  __m128 v45; // xmm1
  signed int v46; // ecx
  float v47; // xmm2_4
  float v48; // xmm4_4
  __m128 v49; // xmm3
  signed int v50; // ecx
  __int64 v51; // r15
  char v52; // al
  unsigned __int64 v53; // rsi
  signed __int64 v54; // rdx
  Scaleform::Render::TmpTextMeshEntry *v55; // rcx
  __int64 v56; // r15
  char v57; // al
  unsigned __int64 v58; // rsi
  signed __int64 v59; // rdx
  Scaleform::Render::TmpTextMeshEntry *v60; // rcx
  unsigned int v61; // eax
  char v62; // r14
  unsigned __int64 v63; // rsi
  Scaleform::Render::TmpTextMeshEntry *v64; // rbx
  float v65; // xmm6_4
  float v66; // xmm3_4
  float v67; // xmm2_4
  float v68; // xmm1_4
  float v69; // xmm0_4
  float v70; // xmm4_4
  float v71; // xmm2_4
  float v72; // xmm2_4
  unsigned __int64 v73; // r14
  __int64 v74; // rsi
  Scaleform::Render::MatrixPoolImpl::HMatrix *v75; // r12
  Scaleform::Render::Renderer2DImpl *v76; // r13
  Scaleform::Render::TextMeshLayer *v77; // r15
  char *v78; // rbx
  Scaleform::Render::Mesh *v79; // rcx
  unsigned __int64 v80; // r8
  Scaleform::Render::LinearHeap::PageType *v81; // rbx
  Scaleform::Render::TmpTextStorage storage; // [rsp+40h] [rbp-80h]
  Scaleform::Render::GlyphRunData data; // [rsp+C0h] [rbp+0h]
  Scaleform::Render::Matrix2x4<float> v85; // [rsp+1C0h] [rbp+100h]
  __int64 v86; // [rsp+1E0h] [rbp+120h]
  __int64 v87; // [rsp+1E8h] [rbp+128h]
  __int64 v88; // [rsp+1F0h] [rbp+130h]
  Scaleform::Render::Font *v89; // [rsp+1F8h] [rbp+138h]
  __int64 v90; // [rsp+200h] [rbp+140h]
  Scaleform::Render::GlyphNode *v91; // [rsp+208h] [rbp+148h]
  __int64 v92; // [rsp+210h] [rbp+150h]
  __int64 v93; // [rsp+218h] [rbp+158h]
  __int64 v94; // [rsp+220h] [rbp+160h]
  unsigned __int64 v95; // [rsp+228h] [rbp+168h]
  unsigned __int64 v96; // [rsp+230h] [rbp+170h]
  Scaleform::Render::GlyphNode *v97; // [rsp+238h] [rbp+178h]
  __int64 v98; // [rsp+240h] [rbp+180h]
  __int64 v99; // [rsp+248h] [rbp+188h]
  __int64 v100; // [rsp+250h] [rbp+190h]
  unsigned __int64 v101; // [rsp+258h] [rbp+198h]
  unsigned __int64 v102; // [rsp+260h] [rbp+1A0h]
  Scaleform::Render::GlyphNode *v103; // [rsp+268h] [rbp+1A8h]
  Scaleform::Render::Matrix2x4<float> viewMatrix; // [rsp+270h] [rbp+1B0h]
  __int64 v105; // [rsp+290h] [rbp+1D0h]
  bool v106; // [rsp+358h] [rbp+298h]
  Scaleform::Render::Renderer2DImpl *prenderer; // [rsp+360h] [rbp+2A0h]
  Scaleform::Render::MatrixPoolImpl::HMatrix *other; // [rsp+368h] [rbp+2A8h]
  Scaleform::Render::Matrix4x4<float> *v109; // [rsp+370h] [rbp+2B0h]
  Scaleform::Render::Viewport *v110; // [rsp+378h] [rbp+2B8h]
  unsigned int vars0; // [rsp+380h] [rbp+2C0h]

  v105 = -2i64;
  v4 = m;
  v5 = layout;
  v6 = this;
  this->pRenderer = ren;
  storage.LHeap.pHeap = Scaleform::Memory::pGlobalHeap;
  storage.LHeap.Granularity = 0x2000i64;
  _mm_store_si128((__m128i *)&storage.LHeap.pPagePool, (__m128i)0i64);
  storage.LHeap.MaxPages = 0i64;
  storage.Entries.pHeap = (Scaleform::Render::LinearHeap *)&storage;
  storage.Entries.Size = 0i64;
  storage.Entries.NumPages = 0i64;
  storage.Entries.MaxPages = 0i64;
  storage.Entries.Pages = 0i64;
  storage.Layers.pHeap = (Scaleform::Render::LinearHeap *)&storage;
  storage.Layers.Size = 0i64;
  storage.Layers.NumPages = 0i64;
  storage.Layers.MaxPages = 0i64;
  storage.Layers.Pages = 0i64;
  this->Flags &= 0xFFFFFF1F;
  v7 = m->pHandle;
  v8 = m->pHandle->pHeader;
  v9 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->Format & 0xF].Offsets[4];
  v10 = *(float *)&v8[v9 + 1].pHandle;
  viewMatrix.M[0][0] = *(float *)&v8[v9 + 1].pHandle;
  v11 = *((float *)&v8[v9 + 1].pHandle + 1);
  *(_QWORD *)&viewMatrix.M[0][1] = *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v8[v9 + 1].pHandle + 4);
  viewMatrix.M[0][3] = *(float *)&v8[v9 + 1].DataPageOffset;
  v12 = *(float *)&v8[v9 + 2].pHandle;
  viewMatrix.M[1][0] = *(float *)&v8[v9 + 2].pHandle;
  v13 = *((float *)&v8[v9 + 2].pHandle + 1);
  *(_QWORD *)&viewMatrix.M[1][1] = *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v8[v9 + 2].pHandle + 4);
  viewMatrix.M[1][3] = *(float *)&v8[v9 + 2].DataPageOffset;
  snap = 0;
  if ( !(v8->Format & 0x10) )
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
  *(_OWORD *)&data.Param.TextParam.pFont = *(_OWORD *)&v5->Param.TextParam.pFont;
  *(_OWORD *)&data.Param.TextParam.BlurY = *(_OWORD *)&v5->Param.TextParam.BlurY;
  *(_OWORD *)&data.Param.ShadowParam.GlyphIndex = *(_OWORD *)&v5->Param.ShadowParam.GlyphIndex;
  *(_OWORD *)&data.Param.ShadowColor = *(_OWORD *)&v5->Param.ShadowColor;
  v16 = v5->Bounds.y2;
  v17 = v5->Bounds.x2;
  v18 = v5->Bounds.y1;
  data.Bounds.x1 = v5->Bounds.x1;
  data.Bounds.y1 = v18;
  data.Bounds.x2 = v17;
  data.Bounds.y2 = v16;
  _mm_store_si128((__m128i *)&data.pFont, (__m128i)0i64);
  *(_QWORD *)&data.FontSize = 0i64;
  *(_QWORD *)&data.RasterSize = 0i64;
  *(_QWORD *)&data.NomHeight = 0i64;
  *(_QWORD *)&data.mColor = 0i64;
  data.NewLineY = 0.0;
  data.GlyphBounds = 0i64;
  v19 = v7->pHeader;
  v20 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v7->pHeader->Format & 0xF].Offsets[4];
  data.DirMtx.M[0][0] = *(float *)&v7->pHeader[v20 + 1].pHandle;
  *(_QWORD *)&data.DirMtx.M[0][1] = *(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v19[v20 + 1].pHandle
                                                                                       + 4);
  data.DirMtx.M[0][3] = *(float *)&v19[v20 + 1].DataPageOffset;
  *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&data.DirMtx.M[1][0] = v19[v20 + 2];
  *(_OWORD *)&v85.M[0][0] = _xmm;
  *(__m128 *)&v85.M[1][0] = _xmm;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v85, &data.DirMtx);
  data.InvMtx = v85;
  data.HeightRatio = Scaleform::Render::TextMeshProvider::calcHeightRatio(v4, v109, v110);
  data.HintedNomHeight = 0;
  v6->HeightRatio = data.HeightRatio;
  if ( v4->pHandle->pHeader->Format & 0x10 )
  {
    data.Param.TextParam.Flags &= 0xFFFCu;
    data.Param.ShadowParam.Flags &= 0xFFFCu;
  }
  v21 = v5->Bounds.y2;
  v22 = v5->Bounds.x2;
  v23 = v5->Bounds.y1;
  v6->Bounds.x1 = v5->Bounds.x1;
  v6->Bounds.y1 = v23;
  v6->Bounds.x2 = v22;
  v6->Bounds.y2 = v21;
  v6->Flags &= 0xFFFFFFF7;
  v24 = v5->ClipBox.y2;
  v25 = v5->ClipBox.x2;
  v26 = v5->ClipBox.y1;
  v6->ClipBox.x1 = v5->ClipBox.x1;
  v6->ClipBox.y1 = v26;
  v6->ClipBox.x2 = v25;
  v6->ClipBox.y2 = v24;
  if ( v25 > v6->ClipBox.x1 && v24 > v26 )
    v6->Flags |= 8u;
  v6->Flags |= 0x10u;
  v27 = 0i64;
  v106 = 1;
  v28 = *((float *)&storage.Entries.Size + 1);
  v29 = *(float *)&storage.Entries.Size;
  v30 = *((float *)&storage.Entries.pHeap + 1);
  v31 = *(float *)&storage.Entries.pHeap;
  v32 = storage.Entries.pHeap;
  v33 = *((float *)&storage.LHeap.MaxPages + 1);
  v34 = HIDWORD(storage.LHeap.MaxPages);
  do
  {
    if ( v27 >= v5->DataSize )
      break;
    v35 = v5->Data.Data.Data;
    LOBYTE(storage.LHeap.MaxPages) = v35[v27];
    v36 = storage.LHeap.MaxPages;
    v37 = v27 + 1;
    v38 = TextLayout_RecordSizes[LOBYTE(storage.LHeap.MaxPages)] - 1;
    if ( TextLayout_RecordSizes[LOBYTE(storage.LHeap.MaxPages)] != 1 )
    {
      v39 = (unsigned int)v38;
      memmove((char *)&storage.LHeap.MaxPages + 1, &v35[v37], v38);
      v37 += v39;
      v28 = *((float *)&storage.Entries.Size + 1);
      v29 = *(float *)&storage.Entries.Size;
      v30 = *((float *)&storage.Entries.pHeap + 1);
      v31 = *(float *)&storage.Entries.pHeap;
      v32 = storage.Entries.pHeap;
      v33 = *((float *)&storage.LHeap.MaxPages + 1);
      v34 = HIDWORD(storage.LHeap.MaxPages);
      v36 = storage.LHeap.MaxPages;
    }
    v27 = v37;
    if ( !v37 )
      break;
    switch ( v36 )
    {
      case 0:
        if ( storage.LHeap.MaxPages & 0x100 )
          v106 = 1;
        else
          v106 = Scaleform::Render::TextMeshProvider::addGlyph(
                   v6,
                   &storage,
                   &data,
                   WORD1(storage.LHeap.MaxPages),
                   (BYTE1(storage.LHeap.MaxPages) >> 1) & 1,
                   (BYTE1(storage.LHeap.MaxPages) >> 2) & 1,
                   snap,
                   vars0);
        v26 = data.NewLineX + v33;
        goto LABEL_48;
      case 1:
        data.mColor = v34;
        break;
      case 2:
        LODWORD(v86) = 0;
        HIDWORD(v86) = storage.Entries.Size;
        LODWORD(v87) = v34;
        v40 = (__int64)v6->pCache->pSolidFill.pObject;
        v88 = v40;
        ++*(_DWORD *)(v40 + 8);
        v89 = *(Scaleform::Render::Font **)&data.Bounds.x1;
        v26 = data.Bounds.x2;
        v90 = *(_QWORD *)&data.Bounds.x2;
        LODWORD(v91) = storage.Entries.pHeap;
        v41 = storage.Entries.Size;
        v42 = storage.Entries.Size >> 6;
        if ( storage.Entries.Size >> 6 >= storage.Entries.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(
            &storage.Entries,
            storage.Entries.Size >> 6);
          v41 = storage.Entries.Size;
        }
        v43 = v41 & 0x3F;
        v44 = storage.Entries.Pages[v42];
        *(_QWORD *)&v44[v43].LayerType = v86;
        *(_QWORD *)&v44[v43].mColor = v87;
        v44[v43].pFill = (Scaleform::Render::PrimitiveFill *)v40;
        v44[v43].EntryData.VectorData.pFont = v89;
        *(_QWORD *)&v44[v43].EntryData.MaskData.Coord[2] = v90;
        v44[v43].EntryData.RasterData.pGlyph = v91;
        ++storage.Entries.Size;
        break;
      case 3:
        data.NewLineX = v33;
        data.NewLineY = v31;
        if ( snap && (data.pFont && (data.pFont->Flags >> 7) & 1 || data.Param.TextParam.Flags & 1) )
        {
          v45 = (__m128)LODWORD(data.DirMtx.M[1][1]);
          v45.m128_f32[0] = (float)((float)((float)(data.DirMtx.M[1][1] * v31) + (float)(data.DirMtx.M[1][0] * v33))
                                  + data.DirMtx.M[1][3])
                          + 0.5;
          v46 = (signed int)v45.m128_f32[0];
          if ( (signed int)v45.m128_f32[0] != 0x80000000 && (float)v46 != v45.m128_f32[0] )
            v45.m128_f32[0] = (float)(v46 - (_mm_movemask_ps(_mm_unpacklo_ps(v45, v45)) & 1));
          v47 = (float)((float)((float)(data.DirMtx.M[0][1] * v31) + (float)(data.DirMtx.M[0][0] * v33))
                      + data.DirMtx.M[0][3])
              * data.InvMtx.M[1][0];
          v26 = (float)((float)(data.InvMtx.M[1][1] * v45.m128_f32[0]) + v47) + data.InvMtx.M[1][3];
          data.NewLineY = (float)((float)(data.InvMtx.M[1][1] * v45.m128_f32[0]) + v47) + data.InvMtx.M[1][3];
        }
        break;
      case 4:
        data.pFont = (Scaleform::Render::Font *)v32;
        data.pFontHandle = Scaleform::Render::GlyphCache::RegisterFont(v6->pCache, (Scaleform::Render::Font *)v32);
        data.FontSize = v33;
        ((void (__fastcall *)(Scaleform::Render::LinearHeap *))v32->pHeap->Info.Desc.HeapId)(v32);
        data.TexHeight = v26;
        if ( snap && data.pFont && (data.pFont->Flags >> 7) & 1 )
        {
          v48 = (float)((float)(data.DirMtx.M[0][1] * data.NewLineY) + (float)(data.DirMtx.M[0][0] * data.NewLineX))
              + data.DirMtx.M[0][3];
          v49 = (__m128)LODWORD(data.DirMtx.M[1][1]);
          v49.m128_f32[0] = (float)((float)((float)(data.DirMtx.M[1][1] * data.NewLineY)
                                          + (float)(data.DirMtx.M[1][0] * data.NewLineX))
                                  + data.DirMtx.M[1][3])
                          + 0.5;
          v50 = (signed int)v49.m128_f32[0];
          if ( (signed int)v49.m128_f32[0] != 0x80000000 && (float)v50 != v49.m128_f32[0] )
            v49.m128_f32[0] = (float)(v50 - (_mm_movemask_ps(_mm_unpacklo_ps(v49, v49)) & 1));
          v26 = data.InvMtx.M[1][0] * v48;
          data.NewLineY = (float)((float)(data.InvMtx.M[1][1] * v49.m128_f32[0]) + (float)(data.InvMtx.M[1][0] * v48))
                        + data.InvMtx.M[1][3];
        }
        break;
      case 5:
        LODWORD(v92) = 1;
        HIDWORD(v92) = storage.Entries.Size;
        LODWORD(v93) = v34;
        v51 = (__int64)v6->pCache->pSolidFill.pObject;
        v94 = v51;
        ++*(_DWORD *)(v51 + 8);
        v95 = __PAIR__(LODWORD(v30), LODWORD(v31));
        v96 = __PAIR__(LODWORD(v28), LODWORD(v29));
        v52 = storage.Entries.Size;
        v53 = storage.Entries.Size >> 6;
        if ( storage.Entries.Size >> 6 >= storage.Entries.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(
            &storage.Entries,
            storage.Entries.Size >> 6);
          v52 = storage.Entries.Size;
        }
        v54 = v52 & 0x3F;
        v55 = storage.Entries.Pages[v53];
        *(_QWORD *)&v55[v54].LayerType = v92;
        *(_QWORD *)&v55[v54].mColor = v93;
        v55[v54].pFill = (Scaleform::Render::PrimitiveFill *)v51;
        v55[v54].EntryData.VectorData.pFont = (Scaleform::Render::Font *)v95;
        *(_QWORD *)&v55[v54].EntryData.MaskData.Coord[2] = v96;
        v55[v54].EntryData.RasterData.pGlyph = v97;
        ++storage.Entries.Size;
        break;
      case 6:
        Scaleform::Render::TextMeshProvider::addUnderline(
          v6,
          &storage,
          storage.Entries.Size,
          (Scaleform::Render::TextUnderlineStyle)WORD1(storage.LHeap.MaxPages),
          v33,
          v31,
          v30);
        v6->Flags |= 0x80u;
        break;
      case 7:
        LODWORD(v98) = 10;
        HIDWORD(v98) = storage.Entries.Size;
        LODWORD(v99) = v34;
        v56 = (__int64)v6->pCache->pSolidFill.pObject;
        v100 = v56;
        ++*(_DWORD *)(v56 + 8);
        v101 = __PAIR__(LODWORD(v30), LODWORD(v31));
        v102 = __PAIR__(LODWORD(v28), LODWORD(v29));
        v57 = storage.Entries.Size;
        v58 = storage.Entries.Size >> 6;
        if ( storage.Entries.Size >> 6 >= storage.Entries.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(
            &storage.Entries,
            storage.Entries.Size >> 6);
          v57 = storage.Entries.Size;
        }
        v59 = v57 & 0x3F;
        v60 = storage.Entries.Pages[v58];
        *(_QWORD *)&v60[v59].LayerType = v98;
        *(_QWORD *)&v60[v59].mColor = v99;
        v60[v59].pFill = (Scaleform::Render::PrimitiveFill *)v56;
        v60[v59].EntryData.VectorData.pFont = (Scaleform::Render::Font *)v101;
        *(_QWORD *)&v60[v59].EntryData.MaskData.Coord[2] = v102;
        v60[v59].EntryData.RasterData.pGlyph = v103;
        ++storage.Entries.Size;
        break;
      case 8:
        Scaleform::Render::TextMeshProvider::addImage(
          v6,
          &storage,
          &data,
          (Scaleform::Render::Image *)v32,
          v29,
          v28,
          *(float *)&storage.Entries.NumPages,
          snap);
        v26 = data.NewLineX + *((float *)&storage.Entries.NumPages + 1);
LABEL_48:
        data.NewLineX = v26;
        break;
      default:
        break;
    }
    snap = (char)storage.LHeap.pHeap;
  }
  while ( v106 );
  v61 = v6->Flags;
  if ( v61 & 8 && v61 & 0xC0 )
  {
    Scaleform::Render::TextMeshProvider::addMask(v6, &storage);
    v62 = 1;
    *(_QWORD *)&v6->ClearBox.x1 = 0i64;
    *(_QWORD *)&v6->ClearBox.x2 = 0i64;
    v63 = 0i64;
    if ( storage.Entries.Size )
    {
      while ( 1 )
      {
        v64 = &storage.Entries.Pages[v63 >> 6][v63 & 0x3F];
        *(_OWORD *)&storage.LHeap.pPagePool = 0i64;
        if ( v64->LayerType == 4 || v64->LayerType == 5 || v64->LayerType == 7 )
          break;
        if ( v64->LayerType == 8 )
        {
          ((void (*)(void))v64->EntryData.VectorData.pFont->vfptr[22].__vecDelDtor)();
          v65 = v64->EntryData.RasterData.Coord[3] / 0.0;
          ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, Scaleform::Render::LinearHeap::PageType **))v64->EntryData.VectorData.pFont->vfptr[7].__vecDelDtor)(
            v64->EntryData.VectorData.pFont,
            v64->EntryData.VectorData.GlyphIndex,
            &storage.LHeap.pPagePool);
          *(float *)&storage.LHeap.pPagePool = (float)(v65 * *(float *)&storage.LHeap.pPagePool)
                                             + v64->EntryData.VectorData.x;
          *((float *)&storage.LHeap.pPagePool + 1) = (float)(v65 * *((float *)&storage.LHeap.pPagePool + 1))
                                                   + v64->EntryData.VectorData.y;
          *(float *)&storage.LHeap.pLastPage = (float)(v65 * *(float *)&storage.LHeap.pLastPage)
                                             + v64->EntryData.VectorData.x;
          *((float *)&storage.LHeap.pLastPage + 1) = (float)(v65 * *((float *)&storage.LHeap.pLastPage + 1))
                                                   + v64->EntryData.VectorData.y;
          v64->LayerType = 12;
          v66 = *((float *)&storage.LHeap.pLastPage + 1);
          v67 = *(float *)&storage.LHeap.pLastPage;
          v68 = *((float *)&storage.LHeap.pPagePool + 1);
          v69 = *(float *)&storage.LHeap.pPagePool;
LABEL_59:
          if ( v69 < v67 && v68 < v66 )
          {
            if ( v62 )
            {
              v6->ClearBox.x2 = v67;
              v6->ClearBox.y2 = v66;
            }
            else
            {
              if ( v6->ClearBox.x1 <= v69 )
                v69 = v6->ClearBox.x1;
              v70 = v6->ClearBox.x2;
              if ( v70 <= v67 )
                v70 = v67;
              if ( v6->ClearBox.y1 <= v68 )
                v68 = v6->ClearBox.y1;
              v71 = v6->ClearBox.y2;
              if ( v71 <= v66 )
                v71 = v66;
              v6->ClearBox.x2 = v70;
              v6->ClearBox.y2 = v71;
            }
            v6->ClearBox.y1 = v68;
            v6->ClearBox.x1 = v69;
            v62 = 0;
          }
        }
        if ( v64->LayerType == 9 )
          v64->LayerType = 13;
        if ( ++v63 >= storage.Entries.Size )
          goto LABEL_76;
      }
      v69 = v64->EntryData.RasterData.Coord[0];
      *(float *)&storage.LHeap.pPagePool = v64->EntryData.RasterData.Coord[0];
      v68 = v64->EntryData.RasterData.Coord[1];
      HIDWORD(storage.LHeap.pPagePool) = LODWORD(v64->EntryData.RasterData.Coord[1]);
      v67 = v64->EntryData.RasterData.Coord[2];
      *(float *)&storage.LHeap.pLastPage = v64->EntryData.RasterData.Coord[2];
      v66 = v64->EntryData.RasterData.Coord[3];
      HIDWORD(storage.LHeap.pLastPage) = LODWORD(v64->EntryData.RasterData.Coord[3]);
      goto LABEL_59;
    }
LABEL_76:
    v72 = 1.0 / v6->HeightRatio;
    v6->ClearBox.x1 = v6->ClearBox.x1 - v72;
    v6->ClearBox.y1 = v6->ClearBox.y1 - v72;
    v6->ClearBox.x2 = v72 + v6->ClearBox.x2;
    v6->ClearBox.y2 = v72 + v6->ClearBox.y2;
    v6->Flags |= 0x100u;
  }
  Scaleform::Render::TextMeshProvider::UnpinSlots(v6);
  v6->Flags &= 0xFFFFFFEF;
  Scaleform::Render::TextMeshProvider::sortEntries(v6, &storage);
  v73 = 0i64;
  if ( v6->Layers.Data.Size )
  {
    v74 = 0i64;
    v75 = other;
    v76 = prenderer;
    do
    {
      v77 = v6->Layers.Data.Data;
      if ( (v77[v74].Type - 8) & 0xFFFFFFFB )
      {
        Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(&v77[v74].M, v75);
        LODWORD(other) = 68;
        v78 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                        Scaleform::Memory::pGlobalHeap,
                        v6,
                        240ui64,
                        (Scaleform::AllocInfo *)&other);
        prenderer = (Scaleform::Render::Renderer2DImpl *)v78;
        if ( v78 )
        {
          Scaleform::Render::MeshBase::MeshBase(
            (Scaleform::Render::MeshBase *)v78,
            v76,
            (Scaleform::Render::MeshProvider *)&v6->vfptr,
            &viewMatrix,
            0.0,
            v73,
            vars0);
          *(_QWORD *)v78 = &Scaleform::Render::Mesh::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>'};
          *((_QWORD *)v78 + 2) = &Scaleform::Render::Mesh::`vftable'{for `Scaleform::Render::MeshStagingNode'};
          *((_QWORD *)v78 + 20) = 0i64;
          *((_QWORD *)v78 + 24) = 1065353216i64;
          *((_QWORD *)v78 + 25) = 0i64;
          *((_DWORD *)v78 + 52) = 0;
          *(_QWORD *)(v78 + 212) = 1065353216i64;
          *((_DWORD *)v78 + 55) = 0;
          v78[224] = 0;
        }
        else
        {
          v78 = 0i64;
        }
        v79 = v77[v74].pMesh.pObject;
        if ( v79 && !_InterlockedDecrement(&v79->RefCount) && v79 )
          v79->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v79->vfptr, 1u);
        v77[v74].pMesh.pObject = (Scaleform::Render::Mesh *)v78;
      }
      else
      {
        Scaleform::Render::TextMeshProvider::createVectorGlyph(v6, v73, v76, v75, vars0);
        v6->Flags |= 0x40u;
      }
      ++v73;
      ++v74;
    }
    while ( v73 < v6->Layers.Data.Size );
  }
  v6->Flags |= 0x20u;
  v80 = storage.LHeap.MaxPages;
  if ( storage.LHeap.MaxPages )
  {
    v81 = &storage.LHeap.pPagePool[storage.LHeap.MaxPages - 1];
    do
    {
      storage.LHeap.MaxPages = --v80;
      if ( v81->pStart )
      {
        ((void (*)(void))storage.LHeap.pHeap->vfptr->Free)();
        v80 = storage.LHeap.MaxPages;
      }
      --v81;
    }
    while ( v80 );
    storage.LHeap.MaxPages = -1i64;
    storage.LHeap.pHeap->vfptr->Free(storage.LHeap.pHeap, storage.LHeap.pPagePool);
  }
  return 1;
}

