// File Line: 30
// RVA: 0x9B9A00
char __fastcall Scaleform::Render::TestQuadCollinearity(Scaleform::Render::TessBase *con, Scaleform::Render::ToleranceParams *param, float x1, float y1, float x2, float y2, float x3, float y3)
{
  Scaleform::Render::TessBase *v8; // rbx
  float v9; // xmm12_4
  float v10; // xmm6_4
  float v11; // xmm5_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  __m128 v15; // xmm6
  float v16; // xmm5_4
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  float v19; // xmm7_4
  __m128 v20; // xmm1

  v8 = con;
  v9 = y1;
  v10 = y3 - y1;
  v11 = x3 - x1;
  v12 = (float)(v10 * v10) + (float)(v11 * v11);
  LODWORD(v13) = COERCE_UNSIGNED_INT((float)((float)(x2 - x3) * v10) - (float)((float)(y2 - y3) * (float)(x3 - x1))) & _xmm;
  if ( (float)(v13 * v13) > (float)((float)((float)(param->CollinearityTolerance * 0.25)
                                          * (float)(param->CollinearityTolerance * 0.25))
                                  * v12) )
    return 0;
  if ( v12 == 0.0
    || (v14 = (float)((float)((float)(y2 - v9) * v10) + (float)((float)(x2 - x1) * v11)) / v12, v14 < 0.0)
    || v14 > 1.0 )
  {
    v15 = (__m128)LODWORD(y2);
    v16 = x2 - x1;
    v15.m128_f32[0] = y2 - v9;
    v17 = v15;
    v18 = (__m128)LODWORD(y3);
    v18.m128_f32[0] = y3 - y2;
    v17.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v16 * v16);
    LODWORD(v19) = (unsigned __int128)_mm_sqrt_ps(v17);
    v20 = v18;
    v20.m128_f32[0] = (float)(v18.m128_f32[0] * v18.m128_f32[0]) + (float)((float)(x3 - x2) * (float)(x3 - x2));
    if ( (float)(COERCE_FLOAT(_mm_sqrt_ps(v20)) + v19) != 0.0 )
      ((void (*)(void))con->vfptr->AddVertex)();
  }
  ((void (__fastcall *)(Scaleform::Render::TessBase *))v8->vfptr->AddVertex)(v8);
  return 1;
}

// File Line: 92
// RVA: 0x9B97B0
void __fastcall Scaleform::Render::TessellateQuadRecursively(Scaleform::Render::TessBase *con, Scaleform::Render::ToleranceParams *param, float toleranceSq, float x1, float y1, float x2, float y2, float x3, float y3, int level)
{
  Scaleform::Render::ToleranceParams *v10; // rdi
  Scaleform::Render::TessBase *v11; // rsi
  float v12; // xmm10_4
  float v13; // xmm11_4
  float v14; // xmm12_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  int v17; // ebx
  float v18; // xmm0_4
  float v19; // xmm1_4

  v10 = param;
  v11 = con;
  v12 = y1;
  v13 = x2;
  v14 = y2;
  v15 = x1;
  LODWORD(v16) = COERCE_UNSIGNED_INT((float)((float)(y3 - y1) * (float)(x2 - x3)) - (float)((float)(x3 - x1)
                                                                                          * (float)(y2 - y3))) & _xmm;
  if ( v16 != 0.0 )
  {
    v17 = level;
    do
    {
      if ( (float)(v16 * v16) <= (float)((float)((float)((float)(y3 - v12) * (float)(y3 - v12))
                                               + (float)((float)(x3 - v15) * (float)(x3 - v15)))
                                       * toleranceSq) )
        break;
      if ( v17 >= (signed int)v10->CurveRecursionLimit )
        break;
      ++v17;
      v18 = (float)(v12 + v14) * 0.5;
      v19 = (float)(v15 + v13) * 0.5;
      v14 = (float)(v14 + y3) * 0.5;
      v13 = (float)(v13 + x3) * 0.5;
      Scaleform::Render::TessellateQuadRecursively(
        v11,
        v10,
        toleranceSq,
        v15,
        v12,
        v19,
        v18,
        (float)(v13 + v19) * 0.5,
        (float)(v14 + v18) * 0.5,
        v17);
      v12 = (float)(v14 + v18) * 0.5;
      v15 = (float)(v13 + v19) * 0.5;
      LODWORD(v16) = COERCE_UNSIGNED_INT((float)((float)(y3 - v12) * (float)(v13 - x3)) - (float)((float)(x3 - v15)
                                                                                                * (float)(v14 - y3))) & _xmm;
    }
    while ( v16 != 0.0 );
  }
  ((void (__fastcall *)(Scaleform::Render::TessBase *))v11->vfptr->AddVertex)(v11);
}

// File Line: 131
// RVA: 0x9B96A0
void __usercall Scaleform::Render::TessellateQuadCurve(Scaleform::Render::TessBase *con@<rcx>, Scaleform::Render::ToleranceParams *param@<rdx>, float x2@<xmm2>, float y2@<xmm3>, float a5@<xmm0>, float x3, float y3)
{
  Scaleform::Render::ToleranceParams *v7; // rdi
  Scaleform::Render::TessBase *v8; // rbx

  v7 = param;
  v8 = con;
  ((void (*)(void))con->vfptr->GetLastX)();
  v8->vfptr->GetLastY(v8);
  if ( !Scaleform::Render::TestQuadCollinearity(v8, v7, a5, a5, x2, y2, x3, y3) )
    Scaleform::Render::TessellateQuadRecursively(
      v8,
      v7,
      (float)(v7->CurveTolerance * 0.25) * (float)(v7->CurveTolerance * 0.25),
      a5,
      a5,
      x2,
      y2,
      x3,
      y3,
      0);
}

// File Line: 159
// RVA: 0x9B9050
void __fastcall Scaleform::Render::TessellateCubicRecursively(Scaleform::Render::TessBase *con, Scaleform::Render::ToleranceParams *param, float toleranceSq, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int level)
{
  int v12; // edi
  Scaleform::Render::ToleranceParams *v13; // rsi
  Scaleform::Render::TessBase *v14; // rbx
  float v15; // xmm11_4
  float v16; // xmm13_4
  float v17; // xmm7_4
  float v18; // xmm9_4
  float v19; // xmm10_4
  float v20; // xmm8_4
  float v21; // xmm12_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm1_4
  int v28; // edx
  int v29; // edx
  int v30; // edx
  float v31; // xmm6_4
  float v32; // xmm7_4
  float v33; // xmm1_4
  bool v34; // cf
  float v35; // xmm6_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm6_4
  float v39; // xmm4_4
  float v40; // xmm7_4
  float v41; // xmm2_4
  float v42; // xmm1_4
  float v43; // xmm4_4
  float v44; // xmm2_4
  float v45; // xmm1_4
  float v46; // xmm0_4
  float v47; // xmm0_4
  float v48; // xmm2_4
  float v49; // xmm0_4
  float v50; // [rsp+60h] [rbp-C8h]
  float v51; // [rsp+64h] [rbp-C4h]
  float v52; // [rsp+68h] [rbp-C0h]
  float v53; // [rsp+6Ch] [rbp-BCh]
  float v54; // [rsp+78h] [rbp-B0h]
  float v55; // [rsp+7Ch] [rbp-ACh]
  int levela; // [rsp+188h] [rbp+60h]

  v12 = level;
  v13 = param;
  v14 = con;
  v15 = x1;
  v16 = toleranceSq;
  if ( level <= (signed int)param->CurveRecursionLimit )
  {
    v17 = y2;
    v18 = y3;
    v19 = x3;
    v20 = x2;
    v21 = y1;
    while ( 1 )
    {
      v53 = (float)(v15 + v20) * 0.5;
      v22 = (float)(v21 + v17) * 0.5;
      v52 = v22;
      v23 = (float)((float)((float)(v17 + v18) * 0.5) + v22) * 0.5;
      v54 = (float)((float)((float)(v18 + y4) * 0.5) + (float)((float)(v17 + v18) * 0.5)) * 0.5;
      v55 = (float)((float)((float)(v19 + x4) * 0.5) + (float)((float)(v20 + v19) * 0.5)) * 0.5;
      v24 = x4 - v15;
      v25 = y4 - v21;
      v51 = (float)((float)((float)(v20 + v19) * 0.5) + v53) * 0.5;
      v50 = v23;
      *(float *)&levela = (float)(v54 + v23) * 0.5;
      LODWORD(v26) = COERCE_UNSIGNED_INT((float)((float)(v20 - x4) * (float)(y4 - v21)) - (float)((float)(v17 - y4)
                                                                                                * (float)(x4 - v15))) & _xmm;
      LODWORD(v27) = COERCE_UNSIGNED_INT((float)((float)(v19 - x4) * (float)(y4 - v21)) - (float)((float)(v18 - y4)
                                                                                                * (float)(x4 - v15))) & _xmm;
      v28 = (v27 > 1.0e-10) + 2 * (v26 > 1.0e-10);
      if ( !v28 )
        break;
      v29 = v28 - 1;
      if ( v29 )
      {
        v30 = v29 - 1;
        if ( v30 )
        {
          if ( v30 != 1
            || (float)((float)(v27 + v26) * (float)(v27 + v26)) > (float)((float)((float)(v25 * v25) + (float)(v24 * v24))
                                                                        * v16) )
          {
            goto LABEL_41;
          }
          v31 = atan2f(v18 - v17, v19 - v20);
          LODWORD(v32) = COERCE_UNSIGNED_INT(v31 - atan2f(v17 - v21, v20 - v15)) & _xmm;
          LODWORD(v33) = COERCE_UNSIGNED_INT(atan2f(y4 - v18, x4 - v19) - v31) & _xmm;
          if ( v32 >= 3.1415927 )
            v32 = 6.2831855 - v32;
          if ( v33 >= 3.1415927 )
            v33 = 6.2831855 - v33;
          v34 = (float)(v33 + v32) < 0.25;
          goto LABEL_40;
        }
        if ( (float)(v26 * v26) > (float)((float)((float)(v25 * v25) + (float)(v24 * v24)) * v16) )
          goto LABEL_41;
        v35 = atan2f(v18 - v17, v19 - v20);
        v36 = v20 - v15;
        v37 = v17 - v21;
      }
      else
      {
        if ( (float)(v27 * v27) > (float)((float)((float)(v25 * v25) + (float)(v24 * v24)) * v16) )
          goto LABEL_41;
        v35 = atan2f(y4 - v18, x4 - v19);
        v36 = v19 - v20;
        v37 = v18 - v17;
      }
      LODWORD(v38) = COERCE_UNSIGNED_INT(v35 - atan2f(v37, v36)) & _xmm;
      if ( v38 >= 3.1415927 )
        v38 = 6.2831855 - v38;
      v34 = v38 < 0.25;
LABEL_40:
      if ( v34 )
        goto LABEL_43;
LABEL_41:
      Scaleform::Render::TessellateCubicRecursively(
        v14,
        v13,
        v16,
        v15,
        v21,
        v53,
        v52,
        v51,
        v50,
        (float)((float)((float)((float)((float)(v19 + x4) * 0.5) + (float)((float)(v20 + v19) * 0.5)) * 0.5) + v51)
      * 0.5,
        *(float *)&levela,
        ++v12);
      v15 = (float)((float)((float)((float)((float)(v19 + x4) * 0.5) + (float)((float)(v20 + v19) * 0.5)) * 0.5) + v51)
          * 0.5;
      v18 = (float)(v18 + y4) * 0.5;
      v19 = (float)(v19 + x4) * 0.5;
      v17 = v54;
      v20 = v55;
      v21 = *(float *)&levela;
      if ( v12 > (signed int)v13->CurveRecursionLimit )
        return;
    }
    v39 = (float)(v25 * v25) + (float)(v24 * v24);
    if ( v39 == 0.0 )
    {
      v40 = (float)((float)(v17 - v21) * (float)(v17 - v21)) + (float)((float)(v20 - v15) * (float)(v20 - v15));
      v41 = (float)((float)(v18 - y4) * (float)(v18 - y4)) + (float)((float)(v19 - x4) * (float)(v19 - x4));
LABEL_38:
      if ( v40 < v16 )
        goto LABEL_43;
      v34 = v41 < v16;
      goto LABEL_40;
    }
    v42 = 1.0 / v39;
    v43 = (float)((float)((float)(v20 - v15) * v24) + (float)((float)(v17 - v21) * v25)) * (float)(1.0 / v39);
    v44 = (float)((float)((float)(v19 - v15) * v24) + (float)((float)(v18 - v21) * v25)) * v42;
    if ( v43 <= 0.0 )
      goto LABEL_46;
    if ( v43 < 1.0 && v44 > 0.0 && v44 < 1.0 )
    {
LABEL_43:
      ((void (__fastcall *)(Scaleform::Render::TessBase *))v14->vfptr->AddVertex)(v14);
      return;
    }
    if ( v43 > 0.0 )
    {
      if ( v43 < 1.0 )
      {
        v40 = (float)((float)((float)((float)(v43 * v25) + v21) - v17) * (float)((float)((float)(v43 * v25) + v21) - v17))
            + (float)((float)((float)((float)(v43 * v24) + v15) - v20) * (float)((float)((float)(v43 * v24) + v15) - v20));
        goto LABEL_32;
      }
      v45 = x4;
      v46 = y4;
    }
    else
    {
LABEL_46:
      v45 = v15;
      v46 = v21;
    }
    v40 = (float)((float)(v46 - v17) * (float)(v46 - v17)) + (float)((float)(v45 - v20) * (float)(v45 - v20));
LABEL_32:
    if ( v44 > 0.0 )
    {
      if ( v44 < 1.0 )
      {
        v49 = v44;
        v48 = (float)(v44 * v25) + v21;
        v47 = (float)(v49 * v24) + v15;
      }
      else
      {
        v47 = x4;
        v48 = y4;
      }
    }
    else
    {
      v47 = v15;
      v48 = v21;
    }
    v41 = (float)((float)(v48 - v18) * (float)(v48 - v18)) + (float)((float)(v47 - v19) * (float)(v47 - v19));
    goto LABEL_38;
  }
}

// File Line: 306
// RVA: 0x9B8F70
void __usercall Scaleform::Render::TessellateCubicCurve(Scaleform::Render::TessBase *con@<rcx>, Scaleform::Render::ToleranceParams *param@<rdx>, float x2@<xmm2>, float y2@<xmm3>, float y1@<xmm0>, float x3, float y3, float x4, float y4)
{
  Scaleform::Render::ToleranceParams *v9; // rbx
  Scaleform::Render::TessBase *v10; // rdi

  v9 = param;
  v10 = con;
  ((void (*)(void))con->vfptr->GetLastX)();
  v10->vfptr->GetLastY(v10);
  Scaleform::Render::TessellateCubicRecursively(
    v10,
    v9,
    (float)(v9->CurveTolerance * 0.25) * (float)(v9->CurveTolerance * 0.25),
    y1,
    y1,
    x2,
    y2,
    x3,
    y3,
    x4,
    y4,
    0);
}

