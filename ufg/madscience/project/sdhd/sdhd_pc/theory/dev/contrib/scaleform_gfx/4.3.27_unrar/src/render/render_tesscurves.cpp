// File Line: 30
// RVA: 0x9B9A00
char __fastcall Scaleform::Render::TestQuadCollinearity(
        Scaleform::Render::TessBase *con,
        Scaleform::Render::ToleranceParams *param,
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3)
{
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

  v10 = y3 - y1;
  v11 = x3 - x1;
  v12 = (float)(v10 * v10) + (float)(v11 * v11);
  LODWORD(v13) = COERCE_UNSIGNED_INT((float)((float)(x2 - x3) * v10) - (float)((float)(y2 - y3) * (float)(x3 - x1))) & _xmm;
  if ( (float)(v13 * v13) > (float)((float)((float)(param->CollinearityTolerance * 0.25)
                                          * (float)(param->CollinearityTolerance * 0.25))
                                  * v12) )
    return 0;
  if ( v12 == 0.0
    || (v14 = (float)((float)((float)(y2 - y1) * v10) + (float)((float)(x2 - x1) * v11)) / v12, v14 < 0.0)
    || v14 > 1.0 )
  {
    v15 = (__m128)LODWORD(y2);
    v16 = x2 - x1;
    v15.m128_f32[0] = y2 - y1;
    v17 = v15;
    v18 = (__m128)LODWORD(y3);
    v18.m128_f32[0] = y3 - y2;
    v17.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v16 * v16);
    v19 = _mm_sqrt_ps(v17).m128_f32[0];
    v20 = v18;
    v20.m128_f32[0] = (float)(v18.m128_f32[0] * v18.m128_f32[0]) + (float)((float)(x3 - x2) * (float)(x3 - x2));
    if ( (float)(_mm_sqrt_ps(v20).m128_f32[0] + v19) != 0.0 )
      ((void (__fastcall *)(Scaleform::Render::TessBase *))con->vfptr->AddVertex)(con);
  }
  ((void (__fastcall *)(Scaleform::Render::TessBase *))con->vfptr->AddVertex)(con);
  return 1;
}

// File Line: 92
// RVA: 0x9B97B0
void __fastcall Scaleform::Render::TessellateQuadRecursively(
        Scaleform::Render::TessBase *con,
        Scaleform::Render::ToleranceParams *param,
        float toleranceSq,
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        int level)
{
  float v12; // xmm10_4
  float v13; // xmm11_4
  float v14; // xmm12_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm1_4

  v12 = y1;
  v13 = x2;
  v14 = y2;
  v15 = x1;
  for ( LODWORD(v16) = COERCE_UNSIGNED_INT((float)((float)(y3 - y1) * (float)(x2 - x3)) - (float)((float)(x3 - x1)
                                                                                                * (float)(y2 - y3))) & _xmm;
        v16 != 0.0;
        LODWORD(v16) = COERCE_UNSIGNED_INT((float)((float)(y3 - v12) * (float)(v13 - x3)) - (float)((float)(x3 - v15)
                                                                                                  * (float)(v14 - y3))) & _xmm )
  {
    if ( (float)(v16 * v16) <= (float)((float)((float)((float)(y3 - v12) * (float)(y3 - v12))
                                             + (float)((float)(x3 - v15) * (float)(x3 - v15)))
                                     * toleranceSq) )
      break;
    if ( level >= (signed int)param->CurveRecursionLimit )
      break;
    ++level;
    v18 = (float)(v12 + v14) * 0.5;
    v19 = (float)(v15 + v13) * 0.5;
    v14 = (float)(v14 + y3) * 0.5;
    v13 = (float)(v13 + x3) * 0.5;
    Scaleform::Render::TessellateQuadRecursively(
      con,
      param,
      toleranceSq,
      v15,
      v12,
      v19,
      v18,
      (float)(v13 + v19) * 0.5,
      (float)(v14 + v18) * 0.5,
      level);
    v12 = (float)(v14 + v18) * 0.5;
    v15 = (float)(v13 + v19) * 0.5;
  }
  ((void (__fastcall *)(Scaleform::Render::TessBase *))con->vfptr->AddVertex)(con);
}

// File Line: 131
// RVA: 0x9B96A0
void __fastcall Scaleform::Render::TessellateQuadCurve(
        Scaleform::Render::TessBase *con,
        Scaleform::Render::ToleranceParams *param,
        float x2,
        float y2,
        float x3,
        float y3)
{
  double v8; // xmm0_8
  float v9; // xmm8_4
  double v10; // xmm0_8

  v8 = ((double (__fastcall *)(Scaleform::Render::TessBase *))con->vfptr->GetLastX)(con);
  v9 = *(float *)&v8;
  v10 = ((double (__fastcall *)(Scaleform::Render::TessBase *))con->vfptr->GetLastY)(con);
  if ( !Scaleform::Render::TestQuadCollinearity(con, param, v9, *(float *)&v10, x2, y2, x3, y3) )
    Scaleform::Render::TessellateQuadRecursively(
      con,
      param,
      (float)(param->CurveTolerance * 0.25) * (float)(param->CurveTolerance * 0.25),
      v9,
      *(float *)&v10,
      x2,
      y2,
      x3,
      y3,
      0);
}

// File Line: 159
// RVA: 0x9B9050
void __fastcall Scaleform::Render::TessellateCubicRecursively(
        Scaleform::Render::TessBase *con,
        Scaleform::Render::ToleranceParams *param,
        float toleranceSq,
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x4,
        float y4,
        int level)
{
  signed int v12; // edi
  float v22; // xmm5_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm1_4
  int v26; // edx
  int v27; // edx
  int v28; // edx
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm1_4
  bool v32; // cf
  float v33; // xmm6_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm6_4
  float v37; // xmm4_4
  float v38; // xmm7_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm4_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm0_4
  float v48; // [rsp+60h] [rbp-C8h]
  float v49; // [rsp+68h] [rbp-C0h]
  float v50; // [rsp+6Ch] [rbp-BCh]
  float v51; // [rsp+78h] [rbp-B0h]
  float v52; // [rsp+7Ch] [rbp-ACh]

  v12 = level;
  if ( level <= (signed int)param->CurveRecursionLimit )
  {
    while ( 1 )
    {
      v50 = (float)(x1 + x2) * 0.5;
      v49 = (float)(y1 + y2) * 0.5;
      v51 = (float)((float)((float)(y3 + y4) * 0.5) + (float)((float)(y2 + y3) * 0.5)) * 0.5;
      v52 = (float)((float)((float)(x3 + x4) * 0.5) + (float)((float)(x2 + x3) * 0.5)) * 0.5;
      v22 = x4 - x1;
      v23 = y4 - y1;
      v48 = (float)((float)((float)(y2 + y3) * 0.5) + v49) * 0.5;
      LODWORD(v24) = COERCE_UNSIGNED_INT((float)((float)(x2 - x4) * (float)(y4 - y1)) - (float)((float)(y2 - y4)
                                                                                              * (float)(x4 - x1))) & _xmm;
      LODWORD(v25) = COERCE_UNSIGNED_INT((float)((float)(x3 - x4) * (float)(y4 - y1)) - (float)((float)(y3 - y4)
                                                                                              * (float)(x4 - x1))) & _xmm;
      v26 = (v25 > 1.0e-10) + 2 * (v24 > 1.0e-10);
      if ( !v26 )
        break;
      v27 = v26 - 1;
      if ( v27 )
      {
        v28 = v27 - 1;
        if ( v28 )
        {
          if ( v28 != 1
            || (float)((float)(v25 + v24) * (float)(v25 + v24)) > (float)((float)((float)(v23 * v23) + (float)(v22 * v22))
                                                                        * toleranceSq) )
          {
            goto LABEL_40;
          }
          v29 = atan2f(y3 - y2, x3 - x2);
          LODWORD(v30) = COERCE_UNSIGNED_INT(v29 - atan2f(y2 - y1, x2 - x1)) & _xmm;
          LODWORD(v31) = COERCE_UNSIGNED_INT(atan2f(y4 - y3, x4 - x3) - v29) & _xmm;
          if ( v30 >= 3.1415927 )
            v30 = 6.2831855 - v30;
          if ( v31 >= 3.1415927 )
            v31 = 6.2831855 - v31;
          v32 = (float)(v31 + v30) < 0.25;
          goto LABEL_39;
        }
        if ( (float)(v24 * v24) > (float)((float)((float)(v23 * v23) + (float)(v22 * v22)) * toleranceSq) )
          goto LABEL_40;
        v33 = atan2f(y3 - y2, x3 - x2);
        v34 = x2 - x1;
        v35 = y2 - y1;
      }
      else
      {
        if ( (float)(v25 * v25) > (float)((float)((float)(v23 * v23) + (float)(v22 * v22)) * toleranceSq) )
          goto LABEL_40;
        v33 = atan2f(y4 - y3, x4 - x3);
        v34 = x3 - x2;
        v35 = y3 - y2;
      }
      LODWORD(v36) = COERCE_UNSIGNED_INT(v33 - atan2f(v35, v34)) & _xmm;
      if ( v36 >= 3.1415927 )
        v36 = 6.2831855 - v36;
      v32 = v36 < 0.25;
LABEL_39:
      if ( v32 )
        goto LABEL_42;
LABEL_40:
      Scaleform::Render::TessellateCubicRecursively(
        con,
        param,
        toleranceSq,
        x1,
        y1,
        v50,
        v49,
        (float)((float)((float)(x2 + x3) * 0.5) + v50) * 0.5,
        v48,
        (float)((float)((float)((float)((float)(x3 + x4) * 0.5) + (float)((float)(x2 + x3) * 0.5)) * 0.5)
              + (float)((float)((float)((float)(x2 + x3) * 0.5) + v50) * 0.5))
      * 0.5,
        (float)(v51 + v48) * 0.5,
        ++v12);
      x1 = (float)((float)((float)((float)((float)(x3 + x4) * 0.5) + (float)((float)(x2 + x3) * 0.5)) * 0.5)
                 + (float)((float)((float)((float)(x2 + x3) * 0.5) + v50) * 0.5))
         * 0.5;
      y3 = (float)(y3 + y4) * 0.5;
      x3 = (float)(x3 + x4) * 0.5;
      y2 = v51;
      x2 = v52;
      y1 = (float)(v51 + v48) * 0.5;
      if ( v12 > (signed int)param->CurveRecursionLimit )
        return;
    }
    v37 = (float)(v23 * v23) + (float)(v22 * v22);
    if ( v37 == 0.0 )
    {
      v38 = (float)((float)(y2 - y1) * (float)(y2 - y1)) + (float)((float)(x2 - x1) * (float)(x2 - x1));
      v39 = (float)((float)(y3 - y4) * (float)(y3 - y4)) + (float)((float)(x3 - x4) * (float)(x3 - x4));
LABEL_37:
      if ( v38 < toleranceSq )
        goto LABEL_42;
      v32 = v39 < toleranceSq;
      goto LABEL_39;
    }
    v40 = 1.0 / v37;
    v41 = (float)((float)((float)(x2 - x1) * v22) + (float)((float)(y2 - y1) * v23)) * (float)(1.0 / v37);
    v42 = (float)((float)((float)(x3 - x1) * v22) + (float)((float)(y3 - y1) * v23)) * v40;
    if ( v41 <= 0.0 )
      goto LABEL_26;
    if ( v41 < 1.0 && v42 > 0.0 && v42 < 1.0 )
    {
LABEL_42:
      ((void (__fastcall *)(Scaleform::Render::TessBase *))con->vfptr->AddVertex)(con);
      return;
    }
    if ( v41 > 0.0 )
    {
      if ( v41 < 1.0 )
      {
        v38 = (float)((float)((float)((float)(v41 * v23) + y1) - y2) * (float)((float)((float)(v41 * v23) + y1) - y2))
            + (float)((float)((float)((float)(v41 * v22) + x1) - x2) * (float)((float)((float)(v41 * v22) + x1) - x2));
        goto LABEL_31;
      }
      v43 = x4;
      v44 = y4;
    }
    else
    {
LABEL_26:
      v43 = x1;
      v44 = y1;
    }
    v38 = (float)((float)(v44 - y2) * (float)(v44 - y2)) + (float)((float)(v43 - x2) * (float)(v43 - x2));
LABEL_31:
    if ( v42 > 0.0 )
    {
      if ( v42 < 1.0 )
      {
        v47 = v42;
        v46 = (float)(v42 * v23) + y1;
        v45 = (float)(v47 * v22) + x1;
      }
      else
      {
        v45 = x4;
        v46 = y4;
      }
    }
    else
    {
      v45 = x1;
      v46 = y1;
    }
    v39 = (float)((float)(v46 - y3) * (float)(v46 - y3)) + (float)((float)(v45 - x3) * (float)(v45 - x3));
    goto LABEL_37;
  }
}

// File Line: 306
// RVA: 0x9B8F70
void __fastcall Scaleform::Render::TessellateCubicCurve(
        Scaleform::Render::TessBase *con,
        Scaleform::Render::ToleranceParams *param,
        float x2,
        float y2,
        float x3,
        float y3,
        float x4,
        float y4)
{
  double y1; // xmm0_8
  float v11; // xmm6_4

  y1 = ((double (__fastcall *)(Scaleform::Render::TessBase *))con->vfptr->GetLastX)(con);
  v11 = *(float *)&y1;
  *(float *)&y1 = con->vfptr->GetLastY(con);
  Scaleform::Render::TessellateCubicRecursively(
    con,
    param,
    (float)(param->CurveTolerance * 0.25) * (float)(param->CurveTolerance * 0.25),
    v11,
    *(float *)&y1,
    x2,
    y2,
    x3,
    y3,
    x4,
    y4,
    0);
}

