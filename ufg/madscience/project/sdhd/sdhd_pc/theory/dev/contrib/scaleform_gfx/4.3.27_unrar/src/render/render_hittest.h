// File Line: 101
// RVA: 0x883CB0
char __fastcall Scaleform::Render::HitTestFill<Scaleform::Render::Matrix2x4<float>>(Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::Matrix2x4<float> *trans, float x, float y)
{
  float *v4; // rbx
  Scaleform::Render::ShapeDataInterface *v5; // rdi
  float v6; // xmm12_4
  float v7; // xmm15_4
  Scaleform::RefCountImplCoreVtbl *v8; // rax
  int v9; // esi
  int v10; // eax
  Scaleform::RefCountImplCoreVtbl *v11; // rax
  float v12; // xmm0_4
  float v13; // xmm14_4
  float v14; // xmm13_4
  int v15; // eax
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm7_4
  float v23; // xmm9_4
  float x3; // xmm11_4
  float v25; // xmm0_4
  float y3; // xmm9_4
  float y2; // xmm8_4
  int v28; // eax
  float v29; // xmm8_4
  float v30; // xmm11_4
  float v31; // xmm5_4
  float v32; // xmm9_4
  float v33; // xmm6_4
  float v34; // xmm4_4
  float v35; // xmm3_4
  float v36; // xmm7_4
  float v37; // xmm10_4
  float v38; // xmm4_4
  float v39; // xmm9_4
  int v41; // [rsp+60h] [rbp-88h]
  int v42; // [rsp+64h] [rbp-84h]
  float v43; // [rsp+68h] [rbp-80h]
  float v44; // [rsp+6Ch] [rbp-7Ch]
  float v45; // [rsp+70h] [rbp-78h]
  unsigned __int64 v46; // [rsp+74h] [rbp-74h]
  __int64 v47; // [rsp+7Ch] [rbp-6Ch]
  __int64 v48; // [rsp+84h] [rbp-64h]
  __int64 v49; // [rsp+8Ch] [rbp-5Ch]
  __int64 v50; // [rsp+94h] [rbp-54h]
  int v51; // [rsp+9Ch] [rbp-4Ch]
  int v52; // [rsp+A0h] [rbp-48h]
  char v53; // [rsp+A4h] [rbp-44h]
  void *retaddr; // [rsp+178h] [rbp+90h]

  v4 = (float *)trans;
  v5 = shape;
  v6 = x;
  v7 = y;
  LODWORD(v45) = ((__int64 (*)(void))shape->vfptr[6].__vecDelDtor)();
  v8 = v5->vfptr;
  v52 = (signed int)FLOAT_1_0;
  v46 = 0i64;
  v47 = 0i64;
  v48 = 0i64;
  v49 = 0i64;
  v50 = 0i64;
  v51 = 0;
  v53 = 0;
  v9 = 0;
  v10 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, float *, float *, int *))v8[8].__vecDelDtor)(
          v5,
          &v45,
          &v45,
          &v41);
  if ( !v10 )
    return v9 != 0;
  while ( v10 != 2 )
  {
LABEL_5:
    v11 = v5->vfptr;
    if ( (v41 == 0) == (v42 == 0) )
    {
      v11[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&v45);
    }
    else
    {
      v12 = v45 * *v4;
      v13 = (float)((float)(*(float *)&v46 * v4[1]) + v12) + v4[3];
      v14 = (float)((float)(v45 * v4[4]) + (float)(*(float *)&v46 * v4[5])) + v4[7];
      v45 = (float)((float)(*(float *)&v46 * v4[1]) + v12) + v4[3];
      *(float *)&v46 = v14;
      v15 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, float *, float *))v11[9].__vecDelDtor)(
              v5,
              &v45,
              &v45);
      if ( v15 )
      {
        while ( 1 )
        {
          if ( v15 == 1 )
          {
            v16 = v13;
            v17 = v14;
            v18 = (float)((float)(v45 * v4[4]) + (float)(*(float *)&v46 * v4[5])) + v4[7];
            v19 = (float)((float)(*(float *)&v46 * v4[1]) + (float)(v45 * *v4)) + v4[3];
            v20 = (float)((float)(*(float *)&v46 * v4[1]) + (float)(v45 * *v4)) + v4[3];
            v21 = v18;
            v45 = (float)((float)(*(float *)&v46 * v4[1]) + (float)(v45 * *v4)) + v4[3];
            *(float *)&v46 = v18;
            if ( v14 > v18 )
            {
              v16 = v19;
              v20 = v13;
              v17 = v18;
              v21 = v14;
            }
            if ( v7 >= v17
              && v7 < v21
              && (float)((float)((float)(v21 - v17) * (float)(v6 - v20))
                       - (float)((float)(v20 - v16) * (float)(v7 - v21))) > 0.0 )
            {
              v9 ^= 1u;
            }
            v13 = v19;
            v14 = v18;
            goto LABEL_20;
          }
          if ( v15 == 2 )
            break;
          if ( v15 == 3 )
          {
            v29 = v4[1];
            v30 = *v4;
            v31 = *v4;
            v32 = v4[5];
            v33 = v4[4];
            v34 = v4[5];
            v35 = v4[3];
            v36 = v4[7];
            v37 = (float)(v4[5] * *(float *)&v46) + (float)(v33 * v45);
            v45 = (float)((float)(*v4 * v45) + (float)(v4[1] * *(float *)&v46)) + v35;
            *(float *)&v46 = v37 + v36;
            v38 = (float)(v34 * *(float *)&v47) + (float)(v33 * *((float *)&v46 + 1));
            v39 = (float)((float)(v32 * v44) + (float)(v33 * v43)) + v36;
            *((float *)&v46 + 1) = (float)((float)(v31 * *((float *)&v46 + 1)) + (float)(v29 * *(float *)&v47)) + v35;
            *(float *)&v47 = v38 + v36;
            v43 = (float)((float)(v30 * v43) + (float)(v29 * v44)) + v35;
            v44 = v39;
            v28 = Scaleform::Render::Math2D::CheckCubicIntersection(
                    v9,
                    v13,
                    v14,
                    v45,
                    v37 + v36,
                    *((float *)&v46 + 1),
                    v38 + v36,
                    v43,
                    v39,
                    *(float *)&retaddr,
                    v7);
            v13 = v43;
            v14 = v44;
            v6 = *(float *)&retaddr;
            goto LABEL_19;
          }
LABEL_20:
          v15 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, float *, float *))v5->vfptr[9].__vecDelDtor)(
                  v5,
                  &v45,
                  &v45);
          if ( !v15 )
            goto LABEL_23;
        }
        v22 = v4[1];
        v23 = v4[5];
        x3 = (float)((float)(*v4 * *((float *)&v46 + 1)) + (float)(v22 * *(float *)&v47)) + v4[3];
        v25 = v23 * *(float *)&v46;
        y3 = (float)((float)(v23 * *(float *)&v47) + (float)(v4[4] * *((float *)&v46 + 1))) + v4[7];
        y2 = (float)((float)(v4[4] * v45) + v25) + v4[7];
        v45 = (float)((float)(*v4 * v45) + (float)(v22 * *(float *)&v46)) + v4[3];
        v46 = __PAIR__(LODWORD(x3), LODWORD(y2));
        *(float *)&v47 = y3;
        v28 = Scaleform::Render::Math2D::CheckQuadraticIntersection(v9, v13, v14, v45, y2, x3, y3, v6, v7);
        v13 = *((float *)&v46 + 1);
        v14 = *(float *)&v47;
LABEL_19:
        v9 = v28;
        goto LABEL_20;
      }
    }
LABEL_23:
    v10 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, float *, float *, int *))v5->vfptr[8].__vecDelDtor)(
            v5,
            &v45,
            &v45,
            &v41);
    if ( !v10 )
      return v9 != 0;
  }
  if ( !v9 )
  {
    v9 = 0;
    goto LABEL_5;
  }
  return 1;
}

// File Line: 183
// RVA: 0x929C70
__int64 __fastcall Scaleform::Render::AddStrokeToSorter<Scaleform::Render::TransformerBase>(Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::ShapePosInfo *pos, unsigned int strokeStyleIdx, Scaleform::Render::TransformerBase *trans)
{
  Scaleform::Render::StrokeSorter *v4; // rdi
  Scaleform::Render::ShapeDataInterface *v5; // r14
  Scaleform::Render::TransformerBase *v6; // rbx
  unsigned int v7; // er13
  Scaleform::Render::ShapePosInfo *v8; // rsi
  char v9; // r12
  Scaleform::RefCountImplCoreVtbl *v10; // rax
  unsigned int v11; // xmm6_4
  int v12; // xmm7_4
  int v13; // xmm8_4
  int v14; // xmm9_4
  int v15; // xmm10_4
  unsigned int v16; // xmm11_4
  unsigned int v17; // xmm12_4
  unsigned int v18; // xmm13_4
  unsigned int v19; // xmm14_4
  unsigned int v20; // xmm15_4
  unsigned int i; // er15
  int v22; // eax
  unsigned int v23; // er9
  float v24; // xmm2_4
  float v25; // xmm1_4
  int v26; // xmm6_4
  int v27; // xmm7_4
  int v28; // xmm8_4
  int v29; // xmm9_4
  float v30; // xmm6_4
  float v31; // xmm7_4
  Scaleform::RefCountImplCoreVtbl *v32; // rax
  unsigned int v33; // xmm0_4
  int v34; // xmm1_4
  int v35; // xmm0_4
  _BOOL8 v37[2]; // [rsp+20h] [rbp-89h]
  int v38; // [rsp+30h] [rbp-79h]
  char v39; // [rsp+38h] [rbp-71h]
  int v40; // [rsp+40h] [rbp-69h]
  float x; // [rsp+48h] [rbp-61h]
  float y; // [rsp+4Ch] [rbp-5Dh]
  float v43; // [rsp+50h] [rbp-59h]
  float v44; // [rsp+54h] [rbp-55h]
  int v45; // [rsp+58h] [rbp-51h]
  int v46; // [rsp+5Ch] [rbp-4Dh]
  int v47; // [rsp+108h] [rbp+5Fh]
  int v48; // [rsp+110h] [rbp+67h]
  __int64 v49; // [rsp+128h] [rbp+7Fh]

  v4 = (Scaleform::Render::StrokeSorter *)(v49 + 168);
  v5 = shape;
  v6 = trans;
  v7 = strokeStyleIdx;
  v8 = pos;
  v9 = 1;
  (*(void (__fastcall **)(__int64))(*(_QWORD *)(v49 + 168) + 8i64))(v49 + 168);
  v10 = v5->vfptr;
  v11 = v8->Pos;
  v12 = v8->StartX;
  v13 = v8->StartY;
  v14 = v8->LastX;
  v15 = v8->LastY;
  v16 = v8->FillBase;
  v17 = v8->StrokeBase;
  v18 = v8->NumFillBits;
  v19 = v8->NumStrokeBits;
  v20 = v8->Fill0;
  LODWORD(v49) = v8->Fill1;
  v47 = v8->Stroke;
  v48 = LODWORD(v8->Sfactor);
  v38 = *(_DWORD *)&v8->Initialized;
  for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, char *))v10[8].__vecDelDtor)(
              v5,
              v8,
              &x,
              &v39);
        i;
        i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, char *))v32[8].__vecDelDtor)(
              v5,
              v8,
              &x,
              &v39) )
  {
    if ( i == 2 && !v9 )
      break;
    if ( v40 == v7 )
    {
      v6->vfptr->Transform(v6, &x, &y);
      Scaleform::Render::StrokeSorter::AddVertexNV(v4, x, y, 1u);
      v22 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *))v5->vfptr[9].__vecDelDtor)(
              v5,
              v8,
              &x);
      if ( v22 )
      {
        while ( v22 != 1 )
        {
          if ( v22 == 2 )
          {
            v6->vfptr->Transform(v6, &x, &y);
            v6->vfptr->Transform(v6, &v43, &v44);
            *(float *)&v26 = v44;
            *(float *)&v27 = v43;
            Scaleform::Render::StrokeSorter::AddVertexNV(v4, x, y, 2u);
            v23 = 2;
            v24 = *(float *)&v26;
            v25 = *(float *)&v27;
            goto LABEL_12;
          }
          if ( v22 == 3 )
          {
            v6->vfptr->Transform(v6, &x, &y);
            v6->vfptr->Transform(v6, &v43, &v44);
            v6->vfptr->Transform(v6, (float *)&v45, (float *)&v46);
            v28 = v46;
            v29 = v45;
            v30 = v44;
            v31 = v43;
            Scaleform::Render::StrokeSorter::AddVertexNV(v4, x, y, 3u);
            Scaleform::Render::StrokeSorter::AddVertexNV(v4, v31, v30, 3u);
            v23 = 3;
            v24 = *(float *)&v28;
            v25 = *(float *)&v29;
            goto LABEL_12;
          }
LABEL_13:
          v22 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *))v5->vfptr[9].__vecDelDtor)(
                  v5,
                  v8,
                  &x);
          if ( !v22 )
            goto LABEL_14;
        }
        v6->vfptr->Transform(v6, &x, &y);
        v23 = 1;
        v24 = y;
        v25 = x;
LABEL_12:
        Scaleform::Render::StrokeSorter::AddVertexNV(v4, v25, v24, v23);
        goto LABEL_13;
      }
LABEL_14:
      LOBYTE(v37[0]) = 0;
      v4->vfptr->FinalizePath((Scaleform::Render::TessBase *)&v4->vfptr, 0, 0, 0, v37[0]);
    }
    else
    {
      v5->vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)v8);
    }
    v32 = v5->vfptr;
    v11 = v8->Pos;
    v12 = v8->StartX;
    v13 = v8->StartY;
    v14 = v8->LastX;
    v9 = 0;
    v15 = v8->LastY;
    v16 = v8->FillBase;
    v17 = v8->StrokeBase;
    v18 = v8->NumFillBits;
    v19 = v8->NumStrokeBits;
    v20 = v8->Fill0;
    LODWORD(v49) = v8->Fill1;
    v47 = v8->Stroke;
    v48 = LODWORD(v8->Sfactor);
    v38 = *(_DWORD *)&v8->Initialized;
  }
  v33 = v49;
  v34 = v47;
  v8->Pos = v11;
  v8->StartX = v12;
  v8->StartY = v13;
  v8->LastX = v14;
  v8->LastY = v15;
  v8->FillBase = v16;
  v8->StrokeBase = v17;
  v8->NumFillBits = v18;
  v8->NumStrokeBits = v19;
  v8->Fill0 = v20;
  v8->Fill1 = v33;
  v35 = v48;
  v8->Stroke = v34;
  LODWORD(v8->Sfactor) = v35;
  *(_DWORD *)&v8->Initialized = v38;
  Scaleform::Render::StrokeSorter::Sort(v4);
  return i;
}

// File Line: 260
// RVA: 0x92CE70
char __fastcall Scaleform::Render::HitTestRoundJoinStroke<Scaleform::Render::TransformerBase>(Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::ShapePosInfo *pos, unsigned int strokeStyleIdx, Scaleform::Render::TransformerBase *trans, float scaledWidth, float x, float y, Scaleform::Render::StrokeGenerator *gen, Scaleform::Render::ToleranceParams *tol)
{
  unsigned int v9; // er13
  Scaleform::Render::VertexPath *v10; // r14
  unsigned __int64 v11; // r15
  __int64 v12; // rsi
  unsigned int v13; // er12
  unsigned int v14; // ebx
  unsigned int v15; // er12
  int v16; // ecx
  Scaleform::Render::StrokeSorter::PathType *v17; // rdx
  unsigned int v18; // eax
  Scaleform::Render::StrokeSorter::VertexType **v19; // r8
  Scaleform::Render::StrokeSorter::VertexType *v20; // rdi
  char v21; // al
  int v22; // ecx
  unsigned int v23; // eax
  float *v24; // rcx
  __int128 v25; // xmm2
  __int128 v26; // xmm1
  int v27; // ecx
  Scaleform::Render::StrokeSorter::PathType *v28; // r8
  unsigned int v29; // eax
  unsigned int v30; // ecx
  Scaleform::Render::StrokeSorter::VertexType **v31; // r9
  unsigned int v32; // ebx
  char v33; // dl
  unsigned __int64 v34; // rax
  int v35; // ecx
  float *v36; // rdx
  unsigned int v37; // eax
  float *v38; // rcx

  Scaleform::Render::AddStrokeToSorter<Scaleform::Render::TransformerBase>(shape, pos, strokeStyleIdx, trans);
  v9 = 0;
  if ( !LODWORD(gen->mStrokeSorter.OutPaths.Size) )
    return 0;
  v10 = &gen->mPath;
  while ( 1 )
  {
    v11 = (unsigned __int64)v9 >> 4;
    v12 = v9 & 0xF;
    v13 = gen->mStrokeSorter.OutPaths.Pages[v11][v12].numVer;
    (*((void (__fastcall **)(Scaleform::Render::VertexPath *))&v10->vfptr->__vecDelDtor + 1))(&gen->mPath);
    v14 = 0;
    v15 = v13 & 0xFFFFFFF;
    if ( v15 )
    {
      do
      {
        v16 = v14;
        v17 = gen->mStrokeSorter.OutPaths.Pages[v11];
        v18 = v17[v12].numVer & 0xFFFFFFF;
        if ( v14 >= v18 )
          v16 = v14 - v18;
        v19 = gen->mStrokeSorter.OutVertices.Pages;
        ++v14;
        v20 = &v19[(unsigned __int64)(v16 + v17[v12].start) >> 4][((_BYTE)v16 + LOBYTE(v17[v12].start)) & 0xF];
        v21 = v20->segType;
        if ( (unsigned __int8)v21 < 2u )
        {
          v25 = LODWORD(v20->y);
          v26 = LODWORD(v20->x);
          ((void (__fastcall *)(Scaleform::Render::VertexPath *))v10->vfptr->AddVertex)(&gen->mPath);
        }
        else if ( v21 == 2 )
        {
          v22 = v14;
          v23 = v17[v12].numVer & 0xFFFFFFF;
          if ( v14 >= v23 )
            v22 = v14 - v23;
          ++v14;
          v24 = &v19[(unsigned __int64)(v22 + v17[v12].start) >> 4][((_BYTE)v22 + (unsigned __int8)v17[v12].start) & 0xF].x;
          Scaleform::Render::TessellateQuadCurve(
            (Scaleform::Render::TessBase *)&gen->mPath.vfptr,
            tol,
            v20->x,
            v20->y,
            *v24,
            v24[1]);
        }
        if ( v20->segType == 3 )
        {
          v27 = v14;
          v28 = gen->mStrokeSorter.OutPaths.Pages[v11];
          v29 = v28[v12].numVer & 0xFFFFFFF;
          if ( v14 >= v29 )
            v27 = v14 - v29;
          v30 = v28[v12].start + v27;
          v31 = gen->mStrokeSorter.OutVertices.Pages;
          v32 = v14 + 1;
          v33 = v30;
          v34 = v30;
          v35 = v32;
          v36 = &v31[v34 >> 4][v33 & 0xF].x;
          v37 = v28[v12].numVer & 0xFFFFFFF;
          if ( v32 >= v37 )
            v35 = v32 - v37;
          v14 = v32 + 1;
          v38 = &v31[(unsigned __int64)(v35 + v28[v12].start) >> 4][((_BYTE)v35 + LOBYTE(v28[v12].start)) & 0xF].x;
          Scaleform::Render::TessellateCubicCurve(
            (Scaleform::Render::TessBase *)&gen->mPath.vfptr,
            tol,
            v20->x,
            v20->y,
            *v36,
            v36[1],
            *v38,
            v38[1]);
        }
      }
      while ( v14 < v15 );
    }
    if ( Scaleform::Render::HitTestRoundStroke(&gen->mPath, scaledWidth, x, y) )
      break;
    if ( ++v9 >= LODWORD(gen->mStrokeSorter.OutPaths.Size) )
      return 0;
  }
  return 1;
}

// File Line: 302
// RVA: 0x92D250
__int64 __fastcall Scaleform::Render::HitTestSingleStroke<Scaleform::Render::TransformerBase>(Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::ShapePosInfo *pos, unsigned int strokeStyleIdx, Scaleform::Render::TransformerBase *trans, float x, float y, Scaleform::Render::StrokeGenerator *gen, Scaleform::Render::ToleranceParams *tol)
{
  Scaleform::Render::TransformerBase *v8; // rbx
  unsigned int v9; // ebp
  Scaleform::Render::ShapePosInfo *v10; // r14
  Scaleform::Render::ShapeDataInterface *v11; // rdi
  unsigned int v12; // er12
  __int16 v13; // ax
  int v14; // ecx
  float scaledWidth; // xmm2_4
  int v16; // ecx
  unsigned __int8 v17; // di
  Scaleform::Render::StrokerTypes::LineJoinType v18; // edx
  Scaleform::Render::StrokerTypes::LineCapType v19; // er9
  Scaleform::Render::StrokerTypes::LineCapType v20; // er8
  int v21; // eax
  Scaleform::Render::VertexPath *v22; // r13
  unsigned __int64 v23; // r14
  __int64 v24; // rdi
  unsigned int v25; // ebp
  unsigned int v26; // ebx
  Scaleform::Render::StrokeSorter::PathType *v27; // rdx
  unsigned int v28; // eax
  int v29; // ecx
  Scaleform::Render::StrokeSorter::VertexType **v30; // r10
  Scaleform::Render::StrokeSorter::VertexType *v31; // r8
  char v32; // al
  unsigned int v33; // eax
  int v34; // ecx
  float *v35; // rcx
  unsigned int v36; // eax
  int v37; // ecx
  float *v38; // r9
  unsigned int v39; // ebx
  unsigned int v40; // eax
  int v41; // ecx
  float *v42; // rdx
  __int128 v43; // xmm2
  __int128 v44; // xmm1
  void (__fastcall ***v45)(_QWORD, signed __int64); // rcx
  void (__fastcall ***v46)(_QWORD, signed __int64); // rcx
  float v48; // [rsp+58h] [rbp-70h]
  int v49; // [rsp+60h] [rbp-68h]
  float v50; // [rsp+64h] [rbp-64h]
  __int64 v51; // [rsp+70h] [rbp-58h]
  __int64 v52; // [rsp+78h] [rbp-50h]

  v8 = trans;
  v9 = strokeStyleIdx;
  v10 = pos;
  v11 = shape;
  v12 = 0;
  v51 = 0i64;
  v52 = 0i64;
  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, float *))shape->vfptr[5].__vecDelDtor)(
    shape,
    strokeStyleIdx,
    &v48);
  v13 = v49;
  v14 = v49 & 6;
  if ( !(v49 & 6) )
  {
    v8->vfptr->GetScale(v8);
    goto LABEL_7;
  }
  if ( v14 == 2 )
  {
    v8->vfptr->GetXScale(v8);
    goto LABEL_7;
  }
  if ( v14 == 4 )
  {
    v8->vfptr->GetYScale(v8);
LABEL_7:
    v13 = v49;
  }
  scaledWidth = v48 * 1.0;
  v16 = v13 & 0x30;
  if ( v13 & 0x30 || v13 & 0xC0 )
  {
    v18 = 2;
    v19 = 2;
    v20 = 2;
    if ( v16 == 16 )
    {
      v18 = 3;
    }
    else if ( v16 == 32 )
    {
      v18 = 0;
    }
    if ( (v13 & 0xC0) == 64 )
    {
      v19 = 0;
    }
    else if ( (v13 & 0xC0) == 128 )
    {
      v19 = 1;
    }
    v21 = v13 & 0x300;
    if ( v21 == 256 )
    {
      v20 = 0;
    }
    else if ( v21 == 512 )
    {
      v20 = 1;
    }
    gen->mStroker.Width = scaledWidth * 0.5;
    gen->mStroker.LineJoin = v18;
    gen->mStroker.StartLineCap = v19;
    gen->mStroker.EndLineCap = v20;
    gen->mStroker.MiterLimit = v50;
    gen->mStroker.CurveTolerance = tol->CurveTolerance;
    gen->mStroker.IntersectionEpsilon = tol->IntersectionEpsilon;
    Scaleform::Render::AddStrokeToSorter<Scaleform::Render::TransformerBase>(v11, v10, v9, v8);
    (*((void (__fastcall **)(Scaleform::Render::Stroker *))&gen->mStroker.vfptr->__vecDelDtor + 1))(&gen->mStroker);
    if ( LODWORD(gen->mStrokeSorter.OutPaths.Size) )
    {
      v22 = &gen->mPath;
      while ( 1 )
      {
        (*((void (__fastcall **)(Scaleform::Render::VertexPath *))&v22->vfptr->__vecDelDtor + 1))(v22);
        v23 = (unsigned __int64)v12 >> 4;
        v24 = v12 & 0xF;
        v25 = gen->mStrokeSorter.OutPaths.Pages[v23][v24].numVer & 0xFFFFFFF;
        v26 = 0;
        if ( v25 )
        {
          do
          {
            v27 = gen->mStrokeSorter.OutPaths.Pages[v23];
            v28 = v27[v24].numVer & 0xFFFFFFF;
            v29 = v26;
            if ( v26 >= v28 )
              v29 = v26 - v28;
            v30 = gen->mStrokeSorter.OutVertices.Pages;
            v31 = &v30[(unsigned __int64)(v27[v24].start + v29) >> 4][(LOBYTE(v27[v24].start) + (_BYTE)v29) & 0xF];
            ++v26;
            v32 = v31->segType;
            if ( (unsigned __int8)v32 < 2u )
            {
              v43 = LODWORD(v31->y);
              v44 = LODWORD(v31->x);
              ((void (__fastcall *)(Scaleform::Render::Stroker *))gen->mStroker.vfptr->AddVertex)(&gen->mStroker);
            }
            else if ( v32 == 2 )
            {
              v33 = v27[v24].numVer & 0xFFFFFFF;
              v34 = v26;
              if ( v26 >= v33 )
                v34 = v26 - v33;
              v35 = &v30[(unsigned __int64)(v34 + v27[v24].start) >> 4][((_BYTE)v34 + LOBYTE(v27[v24].start)) & 0xF].x;
              ++v26;
              Scaleform::Render::TessellateQuadCurve(
                (Scaleform::Render::TessBase *)&gen->mStroker.vfptr,
                tol,
                v31->x,
                v31->y,
                *v35,
                v35[1]);
            }
            else if ( v32 == 3 )
            {
              v36 = v27[v24].numVer & 0xFFFFFFF;
              v37 = v26;
              if ( v26 >= v36 )
                v37 = v26 - v36;
              v38 = &v30[(unsigned __int64)(v37 + v27[v24].start) >> 4][((_BYTE)v37 + LOBYTE(v27[v24].start)) & 0xF].x;
              v39 = v26 + 1;
              v40 = v27[v24].numVer & 0xFFFFFFF;
              v41 = v39;
              if ( v39 >= v40 )
                v41 = v39 - v40;
              v42 = &v30[(unsigned __int64)(v27[v24].start + v41) >> 4][(LOBYTE(v27[v24].start) + (_BYTE)v41) & 0xF].x;
              v26 = v39 + 1;
              Scaleform::Render::TessellateCubicCurve(
                (Scaleform::Render::TessBase *)&gen->mStroker.vfptr,
                tol,
                v31->x,
                v31->y,
                *v38,
                v38[1],
                *v42,
                v42[1]);
            }
          }
          while ( v26 < v25 );
          v22 = &gen->mPath;
        }
        Scaleform::Render::Stroker::GenerateStroke(&gen->mStroker, (Scaleform::Render::TessBase *)&v22->vfptr);
        if ( Scaleform::Render::HitTestGeneralStroke(v22, x, y) )
          break;
        if ( ++v12 >= LODWORD(gen->mStrokeSorter.OutPaths.Size) )
          goto LABEL_46;
      }
      v17 = 1;
    }
    else
    {
LABEL_46:
      v17 = 0;
    }
  }
  else
  {
    v17 = Scaleform::Render::HitTestRoundJoinStroke<Scaleform::Render::TransformerBase>(
            v11,
            v10,
            v9,
            v8,
            scaledWidth,
            x,
            y,
            gen,
            tol);
  }
  v45 = (void (__fastcall ***)(_QWORD, signed __int64))v52;
  if ( v52 && !_InterlockedDecrement((volatile signed __int32 *)(v52 + 8)) && v45 )
    (**v45)(v45, 1i64);
  v46 = (void (__fastcall ***)(_QWORD, signed __int64))v51;
  if ( v51 && !_InterlockedDecrement((volatile signed __int32 *)(v51 + 8)) && v46 )
    (**v46)(v46, 1i64);
  return v17;
}

// File Line: 399
// RVA: 0x92CAB0
__int64 __fastcall Scaleform::Render::HitTestLayerStrokes<Scaleform::Render::TransformerBase>(Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::ShapePosInfo *pos, Scaleform::Render::TransformerBase *trans, float x)
{
  Scaleform::Render::TransformerBase *v4; // rsi
  Scaleform::Render::ShapePosInfo *v5; // rdi
  Scaleform::Render::ShapeDataInterface *v6; // r15
  Scaleform::MemoryHeap *v7; // rax
  char v8; // bl
  int v9; // ST1C_4
  int v10; // eax
  unsigned __int64 v11; // rsi
  __int64 v12; // r14
  unsigned int v13; // ebx
  __int64 v14; // rax
  unsigned int *v15; // rax
  __int64 v16; // rax
  int v17; // ST1C_4
  unsigned __int8 v18; // bl
  int v20; // [rsp+1Ch] [rbp-7Dh]
  int xa; // [rsp+20h] [rbp-79h]
  int v22; // [rsp+24h] [rbp-75h]
  int v23; // [rsp+28h] [rbp-71h]
  unsigned int v24; // [rsp+2Ch] [rbp-6Dh]
  Scaleform::Render::StrokeGenerator *v25; // [rsp+30h] [rbp-69h]
  Scaleform::Render::ToleranceParams *v26; // [rsp+38h] [rbp-61h]
  Scaleform::Render::ShapePosInfo posa; // [rsp+40h] [rbp-59h]
  __int64 v28; // [rsp+78h] [rbp-21h]
  char v29; // [rsp+80h] [rbp-19h]
  Scaleform::Render::TransformerBase *v30; // [rsp+F8h] [rbp+5Fh]
  void *retaddr; // [rsp+108h] [rbp+6Fh]
  Scaleform::Render::StrokeGenerator *v32; // [rsp+110h] [rbp+77h]
  Scaleform::Render::ToleranceParams *v33; // [rsp+118h] [rbp+7Fh]

  v28 = -2i64;
  v4 = trans;
  v5 = pos;
  v6 = shape;
  v7 = v32->Heap1.pHeap;
  *(_QWORD *)&posa.LastY = 32i64;
  *(_QWORD *)&posa.StrokeBase = (char *)&posa + 20;
  *(_QWORD *)&posa.NumStrokeBits = v7;
  v8 = 1;
  posa.Pos = pos->Pos;
  v9 = pos->StartX;
  xa = pos->StartY;
  v22 = pos->LastX;
  v23 = pos->LastY;
  v24 = pos->FillBase;
  v25 = *(Scaleform::Render::StrokeGenerator **)&pos->StrokeBase;
  v26 = *(Scaleform::Render::ToleranceParams **)&pos->NumStrokeBits;
  posa.Pos = pos->Fill1;
  posa.StartX = pos->Stroke;
  posa.StartY = LODWORD(pos->Sfactor);
  posa.LastX = *(_DWORD *)&pos->Initialized;
  v10 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, unsigned int *))v6->vfptr[8].__vecDelDtor)(
          v6,
          pos,
          &v29,
          &posa.Fill1);
  if ( v10 )
  {
    while ( v10 != 2 || v8 )
    {
      if ( LODWORD(posa.Sfactor)
        && (LODWORD(posa.Sfactor) >= posa.LastY
         || !(*(_DWORD *)(*(_QWORD *)&posa.StrokeBase + 4 * ((unsigned __int64)LODWORD(posa.Sfactor) >> 5)) & (1 << (LOBYTE(posa.Sfactor) & 0x1F)))) )
      {
        if ( Scaleform::Render::HitTestSingleStroke<Scaleform::Render::TransformerBase>(
               v6,
               &posa,
               LODWORD(posa.Sfactor),
               v4,
               x,
               *(float *)&retaddr,
               v32,
               v33) )
        {
          v18 = 1;
          goto LABEL_21;
        }
        v11 = LODWORD(posa.Sfactor);
        if ( LODWORD(posa.Sfactor) >= posa.LastY )
        {
          v12 = (unsigned int)(posa.LastY + 31) >> 5;
          v13 = (unsigned int)(LODWORD(posa.Sfactor) + 32) >> 5;
          if ( v13 < 2 * (signed int)v12 )
            v13 = 2 * v12;
          if ( v13 > (unsigned int)v12 )
          {
            v14 = **(_QWORD **)&posa.NumStrokeBits;
            if ( *(Scaleform::Render::ShapePosInfo **)&posa.StrokeBase == (Scaleform::Render::ShapePosInfo *)&posa.FillBase )
            {
              v15 = (unsigned int *)(*(__int64 (__fastcall **)(_QWORD, signed __int64, _QWORD))(v14 + 80))(
                                      *(_QWORD *)&posa.NumStrokeBits,
                                      4i64 * v13,
                                      0i64);
              *(_QWORD *)&posa.StrokeBase = v15;
              *v15 = posa.FillBase;
              v16 = *(_QWORD *)&posa.StrokeBase;
            }
            else
            {
              v16 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, signed __int64))(v14 + 88))(
                      *(_QWORD *)&posa.NumStrokeBits,
                      *(_QWORD *)&posa.StrokeBase,
                      4i64 * v13);
              *(_QWORD *)&posa.StrokeBase = v16;
            }
            memset((void *)(v16 + 4 * v12), 0, 4i64 * (v13 - (unsigned int)v12));
            posa.LastY = 32 * v13;
          }
        }
        *(_DWORD *)(*(_QWORD *)&posa.StrokeBase + 4 * (v11 >> 5)) |= 1 << (v11 & 0x1F);
        v4 = v30;
      }
      v6->vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, (unsigned int)v5);
      v8 = 0;
      posa.Pos = v5->Pos;
      v17 = v5->StartX;
      xa = v5->StartY;
      v22 = v5->LastX;
      v23 = v5->LastY;
      v24 = v5->FillBase;
      v25 = *(Scaleform::Render::StrokeGenerator **)&v5->StrokeBase;
      v26 = *(Scaleform::Render::ToleranceParams **)&v5->NumStrokeBits;
      posa.Pos = v5->Fill1;
      posa.StartX = v5->Stroke;
      posa.StartY = LODWORD(v5->Sfactor);
      posa.LastX = *(_DWORD *)&v5->Initialized;
      v10 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, unsigned int *))v6->vfptr[8].__vecDelDtor)(
              v6,
              v5,
              &v29,
              &posa.Fill1);
      if ( !v10 )
        break;
    }
  }
  v5->Pos = posa.Pos;
  v5->StartX = v20;
  v5->StartY = xa;
  v5->LastX = v22;
  v5->LastY = v23;
  v5->FillBase = v24;
  *(_QWORD *)&v5->StrokeBase = v25;
  *(_QWORD *)&v5->NumStrokeBits = v26;
  v5->Fill1 = posa.Pos;
  v5->Stroke = posa.StartX;
  LODWORD(v5->Sfactor) = posa.StartY;
  *(_DWORD *)&v5->Initialized = posa.LastX;
  v18 = 0;
LABEL_21:
  if ( *(Scaleform::Render::ShapePosInfo **)&posa.StrokeBase != (Scaleform::Render::ShapePosInfo *)&posa.FillBase )
    (*(void (**)(void))(**(_QWORD **)&posa.NumStrokeBits + 96i64))();
  return v18;
}

// File Line: 445
// RVA: 0x92D0F0
char __fastcall Scaleform::Render::HitTestShapeStrokes<Scaleform::Render::TransformerBase>(Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::TransformerBase *trans, float x, float y)
{
  Scaleform::Render::ShapeDataInterface *v4; // rbx
  __int64 v5; // rdi
  __int64 v6; // rsi
  __int64 v7; // r14
  __int64 v8; // r15
  __int64 v9; // r12
  __int64 v10; // r13
  char v12; // [rsp+8h] [rbp-69h]
  char v13; // [rsp+18h] [rbp-59h]
  float ya; // [rsp+20h] [rbp-51h]
  Scaleform::Render::StrokeGenerator *v15; // [rsp+28h] [rbp-49h]
  Scaleform::Render::ShapePosInfo pos; // [rsp+30h] [rbp-41h]
  __int64 v17; // [rsp+C8h] [rbp+57h]
  Scaleform::Render::TransformerBase *transa; // [rsp+D0h] [rbp+5Fh]
  Scaleform::Render::StrokeGenerator *v19; // [rsp+E8h] [rbp+77h]

  v4 = shape;
  pos.Pos = ((__int64 (*)(void))shape->vfptr[6].__vecDelDtor)();
  LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
  *(_QWORD *)&pos.StartX = 0i64;
  v5 = pos.Pos;
  *(_QWORD *)&pos.LastX = 0i64;
  v6 = 0i64;
  *(_QWORD *)&pos.FillBase = 0i64;
  v7 = 0i64;
  *(_QWORD *)&pos.NumFillBits = 0i64;
  v8 = 0i64;
  *(_QWORD *)&pos.Fill0 = 0i64;
  v9 = 0i64;
  pos.Stroke = 0;
  v10 = 0i64;
  pos.Initialized = 0;
  v17 = *(_QWORD *)&pos.Sfactor;
  if ( !((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, char *))v4->vfptr[8].__vecDelDtor)(
          v4,
          &pos,
          &v13,
          &v12) )
    return 0;
  while ( 1 )
  {
    *(_QWORD *)&pos.Sfactor = v17;
    *(_QWORD *)&pos.Pos = v5;
    v15 = v19;
    *(_QWORD *)&pos.StartY = v6;
    *(_QWORD *)&pos.LastY = v7;
    ya = y;
    *(_QWORD *)&pos.StrokeBase = v8;
    *(_QWORD *)&pos.NumStrokeBits = v9;
    *(_QWORD *)&pos.Fill1 = v10;
    if ( (unsigned __int8)Scaleform::Render::HitTestLayerStrokes<Scaleform::Render::TransformerBase>(
                            v4,
                            &pos,
                            transa,
                            x) )
      break;
    v5 = *(_QWORD *)&pos.Pos;
    v6 = *(_QWORD *)&pos.StartY;
    v7 = *(_QWORD *)&pos.LastY;
    v8 = *(_QWORD *)&pos.StrokeBase;
    v9 = *(_QWORD *)&pos.NumStrokeBits;
    v10 = *(_QWORD *)&pos.Fill1;
    v17 = *(_QWORD *)&pos.Sfactor;
    if ( !((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, char *))v4->vfptr[8].__vecDelDtor)(
            v4,
            &pos,
            &v13,
            &v12) )
      return 0;
  }
  return 1;
}

