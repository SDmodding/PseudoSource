// File Line: 101
// RVA: 0x883CB0
char __fastcall Scaleform::Render::HitTestFill<Scaleform::Render::Matrix2x4<float>>(
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::Matrix2x4<float> *trans,
        float x,
        float y)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  int v9; // esi
  int v10; // eax
  Scaleform::RefCountImplCoreVtbl *v11; // rax
  float v12; // xmm14_4
  float v13; // xmm13_4
  int v14; // eax
  float v15; // xmm6_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm0_4
  float v22; // xmm9_4
  float x3; // xmm11_4
  float v24; // xmm10_4
  float v25; // xmm0_4
  float y3; // xmm9_4
  float y2; // xmm8_4
  int v28; // eax
  float v29; // xmm8_4
  float v30; // xmm11_4
  float v31; // xmm5_4
  float v32; // xmm9_4
  float v33; // xmm6_4
  float v34; // xmm3_4
  float v35; // xmm7_4
  float v36; // xmm10_4
  float v37; // xmm4_4
  float v38; // xmm9_4
  int v40[2]; // [rsp+60h] [rbp-88h] BYREF
  float v41; // [rsp+68h] [rbp-80h]
  float v42; // [rsp+6Ch] [rbp-7Ch]
  float v43; // [rsp+70h] [rbp-78h] BYREF
  unsigned __int64 v44; // [rsp+74h] [rbp-74h]
  __int64 v45; // [rsp+7Ch] [rbp-6Ch]
  __int64 v46; // [rsp+84h] [rbp-64h]
  __int64 v47; // [rsp+8Ch] [rbp-5Ch]
  __int64 v48; // [rsp+94h] [rbp-54h]
  int v49; // [rsp+9Ch] [rbp-4Ch]
  int v50; // [rsp+A0h] [rbp-48h]
  char v51; // [rsp+A4h] [rbp-44h]
  void *retaddr; // [rsp+178h] [rbp+90h]

  LODWORD(v43) = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))shape->vfptr[6].__vecDelDtor)(shape);
  vfptr = shape->vfptr;
  v50 = (int)FLOAT_1_0;
  v44 = 0i64;
  v45 = 0i64;
  v46 = 0i64;
  v47 = 0i64;
  v48 = 0i64;
  v49 = 0;
  v51 = 0;
  v9 = 0;
  v10 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, float *, float *, int *))vfptr[8].__vecDelDtor)(
          shape,
          &v43,
          &v43,
          v40);
  if ( !v10 )
    return v9 != 0;
  while ( v10 != 2 )
  {
LABEL_5:
    v11 = shape->vfptr;
    if ( (v40[0] == 0) == (v40[1] == 0) )
    {
      v11[10].__vecDelDtor(shape, (unsigned int)&v43);
    }
    else
    {
      v12 = (float)((float)(*(float *)&v44 * trans->M[0][1]) + (float)(v43 * trans->M[0][0])) + trans->M[0][3];
      v13 = (float)((float)(v43 * trans->M[1][0]) + (float)(*(float *)&v44 * trans->M[1][1])) + trans->M[1][3];
      v43 = v12;
      *(float *)&v44 = v13;
      v14 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, float *, float *))v11[9].__vecDelDtor)(
              shape,
              &v43,
              &v43);
      if ( v14 )
      {
        while ( 1 )
        {
          if ( v14 == 1 )
          {
            v15 = v12;
            v16 = v13;
            v17 = (float)((float)(v43 * trans->M[1][0]) + (float)(*(float *)&v44 * trans->M[1][1])) + trans->M[1][3];
            v18 = (float)((float)(*(float *)&v44 * trans->M[0][1]) + (float)(v43 * trans->M[0][0])) + trans->M[0][3];
            v19 = v18;
            v20 = v17;
            v43 = v18;
            *(float *)&v44 = v17;
            if ( v13 > v17 )
            {
              v15 = v18;
              v19 = v12;
              v16 = v17;
              v20 = v13;
            }
            if ( y >= v16
              && y < v20
              && (float)((float)((float)(v20 - v16) * (float)(x - v19)) - (float)((float)(v19 - v15) * (float)(y - v20))) > 0.0 )
            {
              v9 ^= 1u;
            }
            v12 = v18;
            v13 = v17;
            goto LABEL_20;
          }
          if ( v14 == 2 )
            break;
          if ( v14 == 3 )
          {
            v29 = trans->M[0][1];
            v30 = trans->M[0][0];
            v31 = trans->M[0][0];
            v32 = trans->M[1][1];
            v33 = trans->M[1][0];
            v34 = trans->M[0][3];
            v35 = trans->M[1][3];
            v36 = (float)(v32 * *(float *)&v44) + (float)(v33 * v43);
            v43 = (float)((float)(trans->M[0][0] * v43) + (float)(v29 * *(float *)&v44)) + v34;
            *(float *)&v44 = v36 + v35;
            v37 = (float)(v32 * *(float *)&v45) + (float)(v33 * *((float *)&v44 + 1));
            v38 = (float)((float)(v32 * v42) + (float)(v33 * v41)) + v35;
            *((float *)&v44 + 1) = (float)((float)(v31 * *((float *)&v44 + 1)) + (float)(v29 * *(float *)&v45)) + v34;
            *(float *)&v45 = v37 + v35;
            v41 = (float)((float)(v30 * v41) + (float)(v29 * v42)) + v34;
            v42 = v38;
            v28 = Scaleform::Render::Math2D::CheckCubicIntersection(
                    v9,
                    v12,
                    v13,
                    v43,
                    v36 + v35,
                    *((float *)&v44 + 1),
                    v37 + v35,
                    v41,
                    v38,
                    *(float *)&retaddr,
                    y);
            v12 = v41;
            v13 = v42;
            x = *(float *)&retaddr;
            goto LABEL_19;
          }
LABEL_20:
          v14 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, float *, float *))shape->vfptr[9].__vecDelDtor)(
                  shape,
                  &v43,
                  &v43);
          if ( !v14 )
            goto LABEL_23;
        }
        v21 = trans->M[0][1];
        v22 = trans->M[1][1];
        x3 = (float)((float)(trans->M[0][0] * *((float *)&v44 + 1)) + (float)(v21 * *(float *)&v45)) + trans->M[0][3];
        v24 = (float)(trans->M[0][0] * v43) + (float)(v21 * *(float *)&v44);
        v25 = v22 * *(float *)&v44;
        y3 = (float)((float)(v22 * *(float *)&v45) + (float)(trans->M[1][0] * *((float *)&v44 + 1))) + trans->M[1][3];
        y2 = (float)((float)(trans->M[1][0] * v43) + v25) + trans->M[1][3];
        v43 = v24 + trans->M[0][3];
        v44 = __PAIR64__(LODWORD(x3), LODWORD(y2));
        *(float *)&v45 = y3;
        v28 = Scaleform::Render::Math2D::CheckQuadraticIntersection(v9, v12, v13, v43, y2, x3, y3, x, y);
        v12 = *((float *)&v44 + 1);
        v13 = *(float *)&v45;
LABEL_19:
        v9 = v28;
        goto LABEL_20;
      }
    }
LABEL_23:
    v10 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, float *, float *, int *))shape->vfptr[8].__vecDelDtor)(
            shape,
            &v43,
            &v43,
            v40);
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
__int64 __fastcall Scaleform::Render::AddStrokeToSorter<Scaleform::Render::TransformerBase>(
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::ShapePosInfo *pos,
        unsigned int strokeStyleIdx,
        Scaleform::Render::TransformerBase *trans)
{
  Scaleform::Render::StrokeSorter *v4; // rdi
  char v9; // r12
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  unsigned int v11; // xmm6_4
  int StartX; // xmm7_4
  int StartY; // xmm8_4
  int LastX; // xmm9_4
  int LastY; // xmm10_4
  unsigned int FillBase; // xmm11_4
  unsigned int StrokeBase; // xmm12_4
  unsigned int NumFillBits; // xmm13_4
  unsigned int NumStrokeBits; // xmm14_4
  unsigned int Fill0; // xmm15_4
  unsigned int i; // r15d
  int v22; // eax
  unsigned int v23; // r9d
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
  unsigned int v34; // xmm1_4
  float v35; // xmm0_4
  BOOL v37; // [rsp+20h] [rbp-89h]
  int v38; // [rsp+30h] [rbp-79h]
  char v39[8]; // [rsp+38h] [rbp-71h] BYREF
  int v40; // [rsp+40h] [rbp-69h]
  float x; // [rsp+48h] [rbp-61h] BYREF
  float y; // [rsp+4Ch] [rbp-5Dh] BYREF
  float v43; // [rsp+50h] [rbp-59h] BYREF
  float v44; // [rsp+54h] [rbp-55h] BYREF
  int v45; // [rsp+58h] [rbp-51h] BYREF
  int v46; // [rsp+5Ch] [rbp-4Dh] BYREF
  unsigned int Stroke; // [rsp+108h] [rbp+5Fh]
  float Sfactor; // [rsp+110h] [rbp+67h]
  __int64 v49; // [rsp+128h] [rbp+7Fh]

  v4 = (Scaleform::Render::StrokeSorter *)(v49 + 168);
  v9 = 1;
  (*(void (__fastcall **)(__int64))(*(_QWORD *)(v49 + 168) + 8i64))(v49 + 168);
  vfptr = shape->vfptr;
  v11 = pos->Pos;
  StartX = pos->StartX;
  StartY = pos->StartY;
  LastX = pos->LastX;
  LastY = pos->LastY;
  FillBase = pos->FillBase;
  StrokeBase = pos->StrokeBase;
  NumFillBits = pos->NumFillBits;
  NumStrokeBits = pos->NumStrokeBits;
  Fill0 = pos->Fill0;
  LODWORD(v49) = pos->Fill1;
  Stroke = pos->Stroke;
  Sfactor = pos->Sfactor;
  v38 = *(_DWORD *)&pos->Initialized;
  for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, char *))vfptr[8].__vecDelDtor)(
              shape,
              pos,
              &x,
              v39);
        i;
        i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, char *))v32[8].__vecDelDtor)(
              shape,
              pos,
              &x,
              v39) )
  {
    if ( i == 2 && !v9 )
      break;
    if ( v40 == strokeStyleIdx )
    {
      trans->vfptr->Transform(trans, &x, &y);
      Scaleform::Render::StrokeSorter::AddVertexNV(v4, x, y, 1u);
      v22 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *))shape->vfptr[9].__vecDelDtor)(
              shape,
              pos,
              &x);
      if ( v22 )
      {
        while ( v22 != 1 )
        {
          if ( v22 == 2 )
          {
            trans->vfptr->Transform(trans, &x, &y);
            trans->vfptr->Transform(trans, &v43, &v44);
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
            trans->vfptr->Transform(trans, &x, &y);
            trans->vfptr->Transform(trans, &v43, &v44);
            trans->vfptr->Transform(trans, (float *)&v45, (float *)&v46);
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
          v22 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *))shape->vfptr[9].__vecDelDtor)(
                  shape,
                  pos,
                  &x);
          if ( !v22 )
            goto LABEL_14;
        }
        trans->vfptr->Transform(trans, &x, &y);
        v23 = 1;
        v24 = y;
        v25 = x;
LABEL_12:
        Scaleform::Render::StrokeSorter::AddVertexNV(v4, v25, v24, v23);
        goto LABEL_13;
      }
LABEL_14:
      LOBYTE(v37) = 0;
      v4->vfptr->FinalizePath(v4, 0, 0, 0, v37);
    }
    else
    {
      shape->vfptr[10].__vecDelDtor(shape, (unsigned int)pos);
    }
    v32 = shape->vfptr;
    v11 = pos->Pos;
    StartX = pos->StartX;
    StartY = pos->StartY;
    LastX = pos->LastX;
    v9 = 0;
    LastY = pos->LastY;
    FillBase = pos->FillBase;
    StrokeBase = pos->StrokeBase;
    NumFillBits = pos->NumFillBits;
    NumStrokeBits = pos->NumStrokeBits;
    Fill0 = pos->Fill0;
    LODWORD(v49) = pos->Fill1;
    Stroke = pos->Stroke;
    Sfactor = pos->Sfactor;
    v38 = *(_DWORD *)&pos->Initialized;
  }
  v33 = v49;
  v34 = Stroke;
  pos->Pos = v11;
  pos->StartX = StartX;
  pos->StartY = StartY;
  pos->LastX = LastX;
  pos->LastY = LastY;
  pos->FillBase = FillBase;
  pos->StrokeBase = StrokeBase;
  pos->NumFillBits = NumFillBits;
  pos->NumStrokeBits = NumStrokeBits;
  pos->Fill0 = Fill0;
  pos->Fill1 = v33;
  v35 = Sfactor;
  pos->Stroke = v34;
  pos->Sfactor = v35;
  *(_DWORD *)&pos->Initialized = v38;
  Scaleform::Render::StrokeSorter::Sort(v4);
  return i;
}

// File Line: 260
// RVA: 0x92CE70
char __fastcall Scaleform::Render::HitTestRoundJoinStroke<Scaleform::Render::TransformerBase>(
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::ShapePosInfo *pos,
        unsigned int strokeStyleIdx,
        Scaleform::Render::TransformerBase *trans,
        float scaledWidth,
        float x,
        float y,
        Scaleform::Render::StrokeGenerator *gen,
        Scaleform::Render::ToleranceParams *tol)
{
  unsigned int v9; // r13d
  Scaleform::Render::VertexPath *p_mPath; // r14
  unsigned __int64 v11; // r15
  __int64 v12; // rsi
  unsigned int numVer; // r12d
  unsigned int v14; // ebx
  unsigned int v15; // r12d
  unsigned int v16; // ecx
  Scaleform::Render::StrokeSorter::PathType *v17; // rdx
  unsigned int v18; // eax
  Scaleform::Render::StrokeSorter::VertexType **Pages; // r8
  __int64 v20; // rdi
  unsigned __int8 v21; // al
  unsigned int v22; // ecx
  unsigned int v23; // eax
  float *p_x; // rcx
  unsigned int v25; // ecx
  Scaleform::Render::StrokeSorter::PathType *v26; // r8
  unsigned int v27; // eax
  unsigned int v28; // ecx
  Scaleform::Render::StrokeSorter::VertexType **v29; // r9
  unsigned int v30; // ebx
  char v31; // dl
  unsigned __int64 v32; // rax
  unsigned int v33; // ecx
  float *v34; // rdx
  unsigned int v35; // eax
  float *v36; // rcx

  Scaleform::Render::AddStrokeToSorter<Scaleform::Render::TransformerBase>(shape, pos, strokeStyleIdx, trans);
  v9 = 0;
  if ( !LODWORD(gen->mStrokeSorter.OutPaths.Size) )
    return 0;
  p_mPath = &gen->mPath;
  while ( 1 )
  {
    v11 = (unsigned __int64)v9 >> 4;
    v12 = v9 & 0xF;
    numVer = gen->mStrokeSorter.OutPaths.Pages[v11][v12].numVer;
    (*((void (__fastcall **)(Scaleform::Render::VertexPath *))&p_mPath->vfptr->__vecDelDtor + 1))(&gen->mPath);
    v14 = 0;
    v15 = numVer & 0xFFFFFFF;
    if ( v15 )
    {
      do
      {
        v16 = v14;
        v17 = gen->mStrokeSorter.OutPaths.Pages[v11];
        v18 = v17[v12].numVer & 0xFFFFFFF;
        if ( v14 >= v18 )
          v16 = v14 - v18;
        Pages = gen->mStrokeSorter.OutVertices.Pages;
        ++v14;
        v20 = (__int64)&Pages[(unsigned __int64)(v16 + v17[v12].start) >> 4][((_BYTE)v16 + LOBYTE(v17[v12].start)) & 0xF];
        v21 = *(_BYTE *)(v20 + 12);
        if ( v21 < 2u )
        {
          ((void (__fastcall *)(Scaleform::Render::VertexPath *))p_mPath->vfptr->AddVertex)(&gen->mPath);
        }
        else if ( v21 == 2 )
        {
          v22 = v14;
          v23 = v17[v12].numVer & 0xFFFFFFF;
          if ( v14 >= v23 )
            v22 = v14 - v23;
          ++v14;
          p_x = &Pages[(unsigned __int64)(v22 + v17[v12].start) >> 4][((_BYTE)v22 + (unsigned __int8)v17[v12].start) & 0xF].x;
          Scaleform::Render::TessellateQuadCurve(&gen->mPath, tol, *(float *)v20, *(float *)(v20 + 4), *p_x, p_x[1]);
        }
        if ( *(_BYTE *)(v20 + 12) == 3 )
        {
          v25 = v14;
          v26 = gen->mStrokeSorter.OutPaths.Pages[v11];
          v27 = v26[v12].numVer & 0xFFFFFFF;
          if ( v14 >= v27 )
            v25 = v14 - v27;
          v28 = v26[v12].start + v25;
          v29 = gen->mStrokeSorter.OutVertices.Pages;
          v30 = v14 + 1;
          v31 = v28;
          v32 = v28;
          v33 = v30;
          v34 = &v29[v32 >> 4][v31 & 0xF].x;
          v35 = v26[v12].numVer & 0xFFFFFFF;
          if ( v30 >= v35 )
            v33 = v30 - v35;
          v14 = v30 + 1;
          v36 = &v29[(unsigned __int64)(v33 + v26[v12].start) >> 4][((_BYTE)v33 + LOBYTE(v26[v12].start)) & 0xF].x;
          Scaleform::Render::TessellateCubicCurve(
            &gen->mPath,
            tol,
            *(float *)v20,
            *(float *)(v20 + 4),
            *v34,
            v34[1],
            *v36,
            v36[1]);
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
}y) )
      break;
    if ( ++v9 >= LODWORD(gen->mStrokeSorter.OutPaths.Size

// File Line: 302
// RVA: 0x92D250
__int64 __fastcall Scaleform::Render::HitTestSingleStroke<Scaleform::Render::TransformerBase>(
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::ShapePosInfo *pos,
        unsigned int strokeStyleIdx,
        Scaleform::Render::TransformerBase *trans,
        float x,
        float y,
        Scaleform::Render::StrokeGenerator *gen,
        Scaleform::Render::ToleranceParams *tol)
{
  unsigned int v12; // r12d
  __int16 v13; // ax
  int v14; // ecx
  float scaledWidth; // xmm2_4
  int v16; // ecx
  unsigned __int8 v17; // di
  Scaleform::Render::StrokerTypes::LineJoinType v18; // edx
  Scaleform::Render::StrokerTypes::LineCapType v19; // r9d
  Scaleform::Render::StrokerTypes::LineCapType v20; // r8d
  int v21; // eax
  Scaleform::Render::VertexPath *p_mPath; // r13
  unsigned __int64 v23; // r14
  __int64 v24; // rdi
  unsigned int v25; // ebp
  unsigned int v26; // ebx
  Scaleform::Render::StrokeSorter::PathType *v27; // rdx
  unsigned int v28; // eax
  unsigned int v29; // ecx
  Scaleform::Render::StrokeSorter::VertexType **Pages; // r10
  __int64 v31; // r8
  unsigned __int8 v32; // al
  unsigned int v33; // eax
  unsigned int v34; // ecx
  float *p_x; // rcx
  unsigned int v36; // eax
  unsigned int v37; // ecx
  float *v38; // r9
  unsigned int v39; // ebx
  unsigned int v40; // eax
  unsigned int v41; // ecx
  float *v42; // rdx
  void (__fastcall ***v43)(_QWORD, __int64); // rcx
  void (__fastcall ***v44)(_QWORD, __int64); // rcx
  float v46; // [rsp+58h] [rbp-70h] BYREF
  int v47; // [rsp+60h] [rbp-68h]
  float v48; // [rsp+64h] [rbp-64h]
  __int64 v49; // [rsp+70h] [rbp-58h]
  __int64 v50; // [rsp+78h] [rbp-50h]

  v12 = 0;
  v49 = 0i64;
  v50 = 0i64;
  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, float *))shape->vfptr[5].__vecDelDtor)(
    shape,
    strokeStyleIdx,
    &v46);
  v13 = v47;
  v14 = v47 & 6;
  if ( (v47 & 6) == 0 )
  {
    trans->vfptr->GetScale(trans);
    goto LABEL_7;
  }
  if ( v14 == 2 )
  {
    trans->vfptr->GetXScale(trans);
    goto LABEL_7;
  }
  if ( v14 == 4 )
  {
    trans->vfptr->GetYScale(trans);
LABEL_7:
    v13 = v47;
  }
  scaledWidth = v46 * 1.0;
  v16 = v13 & 0x30;
  if ( (v13 & 0x30) != 0 || (v13 & 0xC0) != 0 )
  {
    v18 = RoundJoin;
    v19 = RoundCap;
    v20 = RoundCap;
    if ( v16 == 16 )
    {
      v18 = BevelJoin;
    }
    else if ( v16 == 32 )
    {
      v18 = MiterJoin;
    }
    if ( (v13 & 0xC0) == 64 )
    {
      v19 = ButtCap;
    }
    else if ( (v13 & 0xC0) == 128 )
    {
      v19 = SquareCap;
    }
    v21 = v13 & 0x300;
    if ( v21 == 256 )
    {
      v20 = ButtCap;
    }
    else if ( v21 == 512 )
    {
      v20 = SquareCap;
    }
    gen->mStroker.Width = scaledWidth * 0.5;
    gen->mStroker.LineJoin = v18;
    gen->mStroker.StartLineCap = v19;
    gen->mStroker.EndLineCap = v20;
    gen->mStroker.MiterLimit = v48;
    gen->mStroker.CurveTolerance = tol->CurveTolerance;
    gen->mStroker.IntersectionEpsilon = tol->IntersectionEpsilon;
    Scaleform::Render::AddStrokeToSorter<Scaleform::Render::TransformerBase>(shape, pos, strokeStyleIdx, trans);
    (*((void (__fastcall **)(Scaleform::Render::Stroker *))&gen->mStroker.vfptr->__vecDelDtor + 1))(&gen->mStroker);
    if ( LODWORD(gen->mStrokeSorter.OutPaths.Size) )
    {
      p_mPath = &gen->mPath;
      while ( 1 )
      {
        (*((void (__fastcall **)(Scaleform::Render::VertexPath *))&p_mPath->vfptr->__vecDelDtor + 1))(p_mPath);
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
            Pages = gen->mStrokeSorter.OutVertices.Pages;
            v31 = (__int64)&Pages[(unsigned __int64)(v27[v24].start + v29) >> 4][(LOBYTE(v27[v24].start) + (_BYTE)v29) & 0xF];
            ++v26;
            v32 = *(_BYTE *)(v31 + 12);
            if ( v32 < 2u )
            {
              ((void (__fastcall *)(Scaleform::Render::Stroker *))gen->mStroker.vfptr->AddVertex)(&gen->mStroker);
            }
            else if ( v32 == 2 )
            {
              v33 = v27[v24].numVer & 0xFFFFFFF;
              v34 = v26;
              if ( v26 >= v33 )
                v34 = v26 - v33;
              p_x = &Pages[(unsigned __int64)(v34 + v27[v24].start) >> 4][((_BYTE)v34 + LOBYTE(v27[v24].start)) & 0xF].x;
              ++v26;
              Scaleform::Render::TessellateQuadCurve(
                &gen->mStroker,
                tol,
                *(float *)v31,
                *(float *)(v31 + 4),
                *p_x,
                p_x[1]);
            }
            else if ( v32 == 3 )
            {
              v36 = v27[v24].numVer & 0xFFFFFFF;
              v37 = v26;
              if ( v26 >= v36 )
                v37 = v26 - v36;
              v38 = &Pages[(unsigned __int64)(v37 + v27[v24].start) >> 4][((_BYTE)v37 + LOBYTE(v27[v24].start)) & 0xF].x;
              v39 = v26 + 1;
              v40 = v27[v24].numVer & 0xFFFFFFF;
              v41 = v39;
              if ( v39 >= v40 )
                v41 = v39 - v40;
              v42 = &Pages[(unsigned __int64)(v27[v24].start + v41) >> 4][(LOBYTE(v27[v24].start) + (_BYTE)v41) & 0xF].x;
              v26 = v39 + 1;
              Scaleform::Render::TessellateCubicCurve(
                &gen->mStroker,
                tol,
                *(float *)v31,
                *(float *)(v31 + 4),
                *v38,
                v38[1],
                *v42,
                v42[1]);
            }
          }
          while ( v26 < v25 );
          p_mPath = &gen->mPath;
        }
        Scaleform::Render::Stroker::GenerateStroke(&gen->mStroker, p_mPath);
        if ( Scaleform::Render::HitTestGeneralStroke(p_mPath, x, y) )
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
            shape,
            pos,
            strokeStyleIdx,
            trans,
            scaledWidth,
            x,
            y,
            gen,
            tol);
  }
  v43 = (void (__fastcall ***)(_QWORD, __int64))v50;
  if ( v50 && !_InterlockedDecrement((volatile signed __int32 *)(v50 + 8)) && v43 )
    (**v43)(v43, 1i64);
  v44 = (void (__fastcall ***)(_QWORD, __int64))v49;
  if ( v49 && !_InterlockedDecrement((volatile signed __int32 *)(v49 + 8)) && v44 )
    (**v44)(v44, 1i64);
  return v17;
}

// File Line: 399
// RVA: 0x92CAB0
__int64 __fastcall Scaleform::Render::HitTestLayerStrokes<Scaleform::Render::TransformerBase>(
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::ShapePosInfo *pos,
        Scaleform::Render::TransformerBase *trans,
        float x)
{
  Scaleform::MemoryHeap *pHeap; // rax
  char v8; // bl
  int v9; // eax
  unsigned __int64 Sfactor_low; // rsi
  __int64 v11; // r14
  unsigned int v12; // ebx
  __int64 v13; // rax
  __int64 v14; // rax
  unsigned __int8 v15; // bl
  int v17; // [rsp+1Ch] [rbp-7Dh]
  int xa; // [rsp+20h] [rbp-79h]
  int LastX; // [rsp+24h] [rbp-75h]
  int LastY; // [rsp+28h] [rbp-71h]
  unsigned int FillBase; // [rsp+2Ch] [rbp-6Dh]
  Scaleform::Render::StrokeGenerator *v22; // [rsp+30h] [rbp-69h]
  Scaleform::Render::ToleranceParams *v23; // [rsp+38h] [rbp-61h]
  Scaleform::Render::ShapePosInfo posa; // [rsp+40h] [rbp-59h] BYREF
  __int64 v25; // [rsp+78h] [rbp-21h]
  char v26[96]; // [rsp+80h] [rbp-19h] BYREF
  Scaleform::Render::TransformerBase *v27; // [rsp+F8h] [rbp+5Fh]
  void *retaddr; // [rsp+108h] [rbp+6Fh]
  Scaleform::Render::StrokeGenerator *v29; // [rsp+110h] [rbp+77h]
  Scaleform::Render::ToleranceParams *v30; // [rsp+118h] [rbp+7Fh]

  v25 = -2i64;
  pHeap = v29->Heap1.pHeap;
  *(_QWORD *)&posa.LastY = 32i64;
  *(_QWORD *)&posa.StrokeBase = &posa.FillBase;
  *(_QWORD *)&posa.NumStrokeBits = pHeap;
  v8 = 1;
  posa.Pos = pos->Pos;
  xa = pos->StartY;
  LastX = pos->LastX;
  LastY = pos->LastY;
  FillBase = pos->FillBase;
  v22 = *(Scaleform::Render::StrokeGenerator **)&pos->StrokeBase;
  v23 = *(Scaleform::Render::ToleranceParams **)&pos->NumStrokeBits;
  posa.Pos = pos->Fill1;
  posa.StartX = pos->Stroke;
  posa.StartY = LODWORD(pos->Sfactor);
  posa.LastX = *(_DWORD *)&pos->Initialized;
  v9 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, unsigned int *))shape->vfptr[8].__vecDelDtor)(
         shape,
         pos,
         v26,
         &posa.Fill1);
  if ( v9 )
  {
    while ( v9 != 2 || v8 )
    {
      if ( LODWORD(posa.Sfactor)
        && (LODWORD(posa.Sfactor) >= posa.LastY
         || (*(_DWORD *)(*(_QWORD *)&posa.StrokeBase + 4 * ((unsigned __int64)LODWORD(posa.Sfactor) >> 5)) & (1 << (LOBYTE(posa.Sfactor) & 0x1F))) == 0) )
      {
        if ( Scaleform::Render::HitTestSingleStroke<Scaleform::Render::TransformerBase>(
               shape,
               &posa,
               LODWORD(posa.Sfactor),
               trans,
               x,
               *(float *)&retaddr,
               v29,
               v30) )
        {
          v15 = 1;
          goto LABEL_21;
        }
        Sfactor_low = LODWORD(posa.Sfactor);
        if ( LODWORD(posa.Sfactor) >= posa.LastY )
        {
          v11 = (unsigned int)(posa.LastY + 31) >> 5;
          v12 = (unsigned int)(LODWORD(posa.Sfactor) + 32) >> 5;
          if ( v12 < 2 * (int)v11 )
            v12 = 2 * v11;
          if ( v12 > (unsigned int)v11 )
          {
            v13 = **(_QWORD **)&posa.NumStrokeBits;
            if ( *(Scaleform::Render::ShapePosInfo **)&posa.StrokeBase == (Scaleform::Render::ShapePosInfo *)&posa.FillBase )
            {
              *(_QWORD *)&posa.StrokeBase = (*(__int64 (__fastcall **)(_QWORD, __int64, _QWORD))(v13 + 80))(
                                              *(_QWORD *)&posa.NumStrokeBits,
                                              4i64 * v12,
                                              0i64);
              **(_DWORD **)&posa.StrokeBase = posa.FillBase;
              v14 = *(_QWORD *)&posa.StrokeBase;
            }
            else
            {
              v14 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(v13 + 88))(
                      *(_QWORD *)&posa.NumStrokeBits,
                      *(_QWORD *)&posa.StrokeBase,
                      4i64 * v12);
              *(_QWORD *)&posa.StrokeBase = v14;
            }
            memset((void *)(v14 + 4 * v11), 0, 4i64 * (v12 - (unsigned int)v11));
            posa.LastY = 32 * v12;
          }
        }
        *(_DWORD *)(*(_QWORD *)&posa.StrokeBase + 4 * (Sfactor_low >> 5)) |= 1 << (Sfactor_low & 0x1F);
        trans = v27;
      }
      shape->vfptr[10].__vecDelDtor(shape, (unsigned int)pos);
      v8 = 0;
      posa.Pos = pos->Pos;
      xa = pos->StartY;
      LastX = pos->LastX;
      LastY = pos->LastY;
      FillBase = pos->FillBase;
      v22 = *(Scaleform::Render::StrokeGenerator **)&pos->StrokeBase;
      v23 = *(Scaleform::Render::ToleranceParams **)&pos->NumStrokeBits;
      posa.Pos = pos->Fill1;
      posa.StartX = pos->Stroke;
      posa.StartY = LODWORD(pos->Sfactor);
      posa.LastX = *(_DWORD *)&pos->Initialized;
      v9 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, unsigned int *))shape->vfptr[8].__vecDelDtor)(
             shape,
             pos,
             v26,
             &posa.Fill1);
      if ( !v9 )
        break;
    }
  }
  pos->Pos = posa.Pos;
  pos->StartX = v17;
  pos->StartY = xa;
  pos->LastX = LastX;
  pos->LastY = LastY;
  pos->FillBase = FillBase;
  *(_QWORD *)&pos->StrokeBase = v22;
  *(_QWORD *)&pos->NumStrokeBits = v23;
  pos->Fill1 = posa.Pos;
  pos->Stroke = posa.StartX;
  LODWORD(pos->Sfactor) = posa.StartY;
  *(_DWORD *)&pos->Initialized = posa.LastX;
  v15 = 0;
LABEL_21:
  if ( *(Scaleform::Render::ShapePosInfo **)&posa.StrokeBase != (Scaleform::Render::ShapePosInfo *)&posa.FillBase )
    (*(void (__fastcall **)(_QWORD))(**(_QWORD **)&posa.NumStrokeBits + 96i64))(*(_QWORD *)&posa.NumStrokeBits);
  return v15;
}

// File Line: 445
// RVA: 0x92D0F0
char __fastcall Scaleform::Render::HitTestShapeStrokes<Scaleform::Render::TransformerBase>(
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::TransformerBase *trans,
        float x,
        float y)
{
  __int64 v5; // rdi
  __int64 v6; // rsi
  __int64 v7; // r14
  __int64 v8; // r15
  __int64 v9; // r12
  __int64 v10; // r13
  char v12[16]; // [rsp+8h] [rbp-69h] BYREF
  char v13[8]; // [rsp+18h] [rbp-59h] BYREF
  float ya; // [rsp+20h] [rbp-51h]
  Scaleform::Render::StrokeGenerator *v15; // [rsp+28h] [rbp-49h]
  Scaleform::Render::ShapePosInfo pos; // [rsp+30h] [rbp-41h] BYREF
  __int64 v17; // [rsp+C8h] [rbp+57h]
  Scaleform::Render::TransformerBase *transa; // [rsp+D0h] [rbp+5Fh]
  Scaleform::Render::StrokeGenerator *v19; // [rsp+E8h] [rbp+77h]

  pos.Pos = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))shape->vfptr[6].__vecDelDtor)(shape);
  LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
  memset(&pos.StartX, 0, 44);
  v5 = pos.Pos;
  v6 = 0i64;
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  pos.Initialized = 0;
  v17 = *(_QWORD *)&pos.Sfactor;
  if ( !((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, char *))shape->vfptr[8].__vecDelDtor)(
          shape,
          &pos,
          v13,
          v12) )
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
                            shape,
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
    if ( !((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *, char *))shape->vfptr[8].__vecDelDtor)(
            shape,
            &pos,
            v13,
            v12) )
      return 0;
  }
  return 1;
}

