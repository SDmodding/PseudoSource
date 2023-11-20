// File Line: 97
// RVA: 0x20E180
UFG::qVector3 *__fastcall UFG::Editor::Utility::NDC_To_World(UFG::qVector3 *result, UFG::Editor::View *view, UFG::qVector3 *ndc)
{
  UFG::Editor::Camera *v3; // rdi
  UFG::qVector3 *v4; // rbp
  UFG::qVector3 *v5; // rsi
  UFG::BaseCameraComponent *v6; // rax
  signed __int64 v7; // rax
  UFG::BaseCameraComponent *v8; // rcx
  UFG::qMatrix44 *v9; // rbx
  UFG::qMatrix44 *v10; // rax
  UFG::qVector3 *v11; // rax
  float v12; // xmm7_4
  float v13; // xmm4_4
  float v14; // xmm6_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  UFG::qMatrix44 d; // [rsp+20h] [rbp-B8h]
  UFG::qMatrix44 resulta; // [rsp+60h] [rbp-78h]

  v3 = view->mCamera;
  v4 = ndc;
  v5 = result;
  v6 = UFG::Director::Get()->mCurrentCamera;
  if ( v6 && (v7 = (signed __int64)&v6->mCamera) != 0 && !*(_BYTE *)(v7 + 256) )
  {
    v8 = UFG::Director::Get()->mCurrentCamera;
    if ( v8 )
      v9 = UFG::Camera::GetViewProjection(&v8->mCamera);
    else
      v9 = UFG::Camera::GetViewProjection(0i64);
  }
  else
  {
    v9 = &v3->mProj;
  }
  v10 = UFG::Editor::Camera::GetMatView(v3, &resulta);
  UFG::qMatrix44::operator*(v10, &d, v9);
  UFG::qInverse(&d, &d);
  v11 = v5;
  v12 = v4->z;
  v13 = v4->y;
  v14 = (float)((float)((float)(d.v1.y * v13) + (float)(d.v0.y * v4->x)) + (float)(d.v2.y * v12)) + d.v3.y;
  v15 = (float)((float)((float)(d.v1.z * v13) + (float)(d.v0.z * v4->x)) + (float)(d.v2.z * v12)) + d.v3.z;
  v16 = 1.0
      / (float)((float)((float)((float)(d.v1.w * v13) + (float)(d.v0.w * v4->x)) + (float)(d.v2.w * v12)) + d.v3.w);
  v5->x = (float)((float)((float)((float)(d.v1.x * v13) + (float)(d.v0.x * v4->x)) + (float)(d.v2.x * v12)) + d.v3.x)
        * v16;
  v5->y = v14 * v16;
  v5->z = v15 * v16;
  return v11;
}

// File Line: 157
// RVA: 0x2126B0
void __fastcall UFG::Editor::Utility::Round(float *r, float p)
{
  float *v2; // r8
  bool v3; // cf
  bool v4; // zf
  __m128 v5; // xmm2
  signed int v6; // edx
  signed int v7; // ecx

  v5 = (__m128)*(unsigned int *)r;
  v2 = r;
  v3 = v5.m128_f32[0] < 0.0;
  v4 = v5.m128_f32[0] == 0.0;
  v5.m128_f32[0] = v5.m128_f32[0] / p;
  if ( v3 || v4 )
  {
    v5.m128_f32[0] = v5.m128_f32[0] - 0.5;
    v7 = (signed int)v5.m128_f32[0];
    if ( (signed int)v5.m128_f32[0] != 0x80000000 && (float)v7 != v5.m128_f32[0] )
      v5.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1 ^ 1) + v7);
    *v2 = v5.m128_f32[0] * p;
  }
  else
  {
    v5.m128_f32[0] = v5.m128_f32[0] + 0.5;
    v6 = (signed int)v5.m128_f32[0];
    if ( (signed int)v5.m128_f32[0] != 0x80000000 && (float)v6 != v5.m128_f32[0] )
      v5.m128_f32[0] = (float)(v6 - (_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1));
    *r = v5.m128_f32[0] * p;
  }
}

// File Line: 270
// RVA: 0x209E60
void __fastcall UFG::Editor::Utility::FindMinimalBoundingSphere(UFG::qVector3 *center, float *radius, UFG::qVector3 *points, int numPoints)
{
  UFG::qVector3 *v4; // rbx
  float *v5; // r10
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  signed __int64 v10; // rdi
  signed __int64 v11; // r11
  float v12; // xmm15_4
  float v13; // xmm12_4
  float v14; // xmm13_4
  float v15; // xmm7_4
  float v16; // xmm11_4
  float v17; // xmm6_4
  float v18; // xmm8_4
  float v19; // xmm9_4
  float v20; // xmm10_4
  float *v21; // rax
  unsigned __int64 v22; // rdx
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float *v34; // rdx
  signed __int64 v35; // rax
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm14_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm7_4
  float *v43; // rax
  unsigned __int64 v44; // rdx
  __m128 v45; // xmm2
  float v46; // xmm5_4
  float v47; // xmm6_4
  float v48; // xmm4_4
  float v49; // xmm2_4
  __m128 v50; // xmm2
  float v51; // xmm5_4
  float v52; // xmm6_4
  float v53; // xmm4_4
  float v54; // xmm2_4
  __m128 v55; // xmm2
  float v56; // xmm5_4
  float v57; // xmm6_4
  float v58; // xmm4_4
  float v59; // xmm2_4
  __m128 v60; // xmm2
  float v61; // xmm5_4
  float v62; // xmm6_4
  float v63; // xmm0_4
  float v64; // xmm2_4
  signed __int64 v65; // r8
  float *v66; // rdx
  __m128 v67; // xmm2
  float v68; // xmm5_4
  float v69; // xmm6_4
  float v70; // xmm0_4
  float v71; // xmm2_4
  float v72; // [rsp+0h] [rbp-D8h]
  float v73; // [rsp+4h] [rbp-D4h]
  float v74; // [rsp+8h] [rbp-D0h]
  float v75; // [rsp+Ch] [rbp-CCh]
  float v76; // [rsp+10h] [rbp-C8h]
  float v77; // [rsp+14h] [rbp-C4h]
  float v78; // [rsp+F0h] [rbp+18h]

  v4 = points;
  v5 = radius;
  if ( points && numPoints >= 1 )
  {
    if ( numPoints == 1 )
    {
      v6 = points->y;
      v7 = points->z;
      center->x = points->x;
      center->y = v6;
      center->z = v7;
      *radius = 0.0;
    }
    else
    {
      v8 = FLOAT_1_0e32;
      v9 = FLOAT_N1_0e32;
      v10 = 0i64;
      v11 = 0i64;
      v78 = FLOAT_1_0e32;
      v73 = FLOAT_N1_0e32;
      v76 = FLOAT_N1_0e32;
      v75 = FLOAT_1_0e32;
      v77 = FLOAT_1_0e32;
      v72 = FLOAT_N1_0e32;
      v74 = FLOAT_N1_0e32;
      v12 = FLOAT_1_0e32;
      v13 = FLOAT_1_0e32;
      v14 = FLOAT_1_0e32;
      v15 = FLOAT_N1_0e32;
      v16 = FLOAT_N1_0e32;
      v17 = FLOAT_1_0e32;
      v18 = FLOAT_N1_0e32;
      v19 = FLOAT_1_0e32;
      v20 = FLOAT_N1_0e32;
      if ( numPoints >= 4i64 )
      {
        v21 = &points[1].z;
        v22 = ((unsigned __int64)(numPoints - 4i64) >> 2) + 1;
        v11 = 4 * v22;
        do
        {
          v23 = *(v21 - 5);
          if ( v8 > v23 )
          {
            v13 = *(v21 - 4);
            v14 = *(v21 - 3);
            v8 = *(v21 - 5);
          }
          if ( v9 < v23 )
          {
            v15 = *(v21 - 4);
            v16 = *(v21 - 3);
            v9 = *(v21 - 5);
          }
          v24 = *(v21 - 4);
          if ( v17 > v24 )
          {
            v12 = *(v21 - 5);
            v17 = *(v21 - 4);
            v78 = *(v21 - 3);
          }
          if ( v18 < v24 )
          {
            v73 = *(v21 - 5);
            v18 = *(v21 - 4);
            v76 = *(v21 - 3);
          }
          v25 = *(v21 - 3);
          if ( v19 > v25 )
          {
            v75 = *(v21 - 5);
            v77 = *(v21 - 4);
            v19 = *(v21 - 3);
          }
          if ( v20 < v25 )
          {
            v72 = *(v21 - 5);
            v74 = *(v21 - 4);
            v20 = *(v21 - 3);
          }
          v26 = *(v21 - 2);
          if ( v8 > v26 )
          {
            v13 = *(v21 - 1);
            v14 = *v21;
            v8 = *(v21 - 2);
          }
          if ( v9 < v26 )
          {
            v15 = *(v21 - 1);
            v16 = *v21;
            v9 = *(v21 - 2);
          }
          v27 = *(v21 - 1);
          if ( v17 > v27 )
          {
            v12 = *(v21 - 2);
            v17 = *(v21 - 1);
            v78 = *v21;
          }
          if ( v18 < v27 )
          {
            v73 = *(v21 - 2);
            v18 = *(v21 - 1);
            v76 = *v21;
          }
          if ( v19 > *v21 )
          {
            v75 = *(v21 - 2);
            v77 = *(v21 - 1);
            v19 = *v21;
          }
          if ( v20 < *v21 )
          {
            v72 = *(v21 - 2);
            v74 = *(v21 - 1);
            v20 = *v21;
          }
          v28 = v21[1];
          if ( v8 > v28 )
          {
            v13 = v21[2];
            v14 = v21[3];
            v8 = v21[1];
          }
          if ( v9 < v28 )
          {
            v15 = v21[2];
            v16 = v21[3];
            v9 = v21[1];
          }
          v29 = v21[2];
          if ( v17 > v29 )
          {
            v12 = v21[1];
            v17 = v21[2];
            v78 = v21[3];
          }
          if ( v18 < v29 )
          {
            v73 = v21[1];
            v18 = v21[2];
            v76 = v21[3];
          }
          v30 = v21[3];
          if ( v19 > v30 )
          {
            v75 = v21[1];
            v77 = v21[2];
            v19 = v21[3];
          }
          if ( v20 < v30 )
          {
            v72 = v21[1];
            v74 = v21[2];
            v20 = v21[3];
          }
          v31 = v21[4];
          if ( v8 > v31 )
          {
            v13 = v21[5];
            v14 = v21[6];
            v8 = v21[4];
          }
          if ( v9 < v31 )
          {
            v15 = v21[5];
            v16 = v21[6];
            v9 = v21[4];
          }
          v32 = v21[5];
          if ( v17 > v32 )
          {
            v12 = v21[4];
            v17 = v21[5];
            v78 = v21[6];
          }
          if ( v18 < v32 )
          {
            v73 = v21[4];
            v18 = v21[5];
            v76 = v21[6];
          }
          v33 = v21[6];
          if ( v19 > v33 )
          {
            v75 = v21[4];
            v77 = v21[5];
            v19 = v21[6];
          }
          if ( v20 < v33 )
          {
            v72 = v21[4];
            v74 = v21[5];
            v20 = v21[6];
          }
          v21 += 12;
          --v22;
        }
        while ( v22 );
      }
      if ( v11 < numPoints )
      {
        v34 = &points->x + v11 + 2 * (v11 + 1);
        v35 = numPoints - v11;
        do
        {
          v36 = *(v34 - 2);
          if ( v8 > v36 )
          {
            v13 = *(v34 - 1);
            v14 = *v34;
            v8 = *(v34 - 2);
          }
          if ( v9 < v36 )
          {
            v15 = *(v34 - 1);
            v16 = *v34;
            v9 = *(v34 - 2);
          }
          v37 = *(v34 - 1);
          if ( v17 > v37 )
          {
            v12 = *(v34 - 2);
            v17 = *(v34 - 1);
            v78 = *v34;
          }
          if ( v18 < v37 )
          {
            v73 = *(v34 - 2);
            v18 = *(v34 - 1);
            v76 = *v34;
          }
          if ( v19 > *v34 )
          {
            v75 = *(v34 - 2);
            v77 = *(v34 - 1);
            v19 = *v34;
          }
          if ( v20 < *v34 )
          {
            v72 = *(v34 - 2);
            v74 = *(v34 - 1);
            v20 = *v34;
          }
          v34 += 3;
          --v35;
        }
        while ( v35 );
      }
      v38 = (float)((float)((float)(v15 - v13) * (float)(v15 - v13)) + (float)((float)(v9 - v8) * (float)(v9 - v8)))
          + (float)((float)(v16 - v14) * (float)(v16 - v14));
      if ( (float)((float)((float)((float)(v18 - v17) * (float)(v18 - v17))
                         + (float)((float)(v73 - v12) * (float)(v73 - v12)))
                 + (float)((float)(v76 - v78) * (float)(v76 - v78))) > v38 )
      {
        v14 = v78;
        v9 = v73;
        v16 = v76;
        v38 = (float)((float)((float)(v18 - v17) * (float)(v18 - v17)) + (float)((float)(v73 - v12) * (float)(v73 - v12)))
            + (float)((float)(v76 - v78) * (float)(v76 - v78));
        v8 = v12;
        v13 = v17;
        v15 = v18;
      }
      if ( (float)((float)((float)((float)(v74 - v77) * (float)(v74 - v77))
                         + (float)((float)(v72 - v75) * (float)(v72 - v75)))
                 + (float)((float)(v20 - v19) * (float)(v20 - v19))) > v38 )
      {
        v8 = v75;
        v13 = v77;
        v9 = v72;
        v14 = v19;
        v16 = v20;
        v15 = v74;
      }
      v39 = (float)(v16 + v14) * 0.5;
      v40 = (float)(v9 + v8) * 0.5;
      v41 = (float)(v15 + v13) * 0.5;
      center->z = v39;
      center->x = v40;
      center->y = v41;
      v42 = (float)((float)((float)(v15 - v41) * (float)(v15 - v41)) + (float)((float)(v9 - v40) * (float)(v9 - v40)))
          + (float)((float)(v16 - v39) * (float)(v16 - v39));
      *v5 = fsqrt(v42);
      if ( numPoints >= 4i64 )
      {
        v43 = &points[1].z;
        v44 = ((unsigned __int64)(numPoints - 4i64) >> 2) + 1;
        v10 = 4 * v44;
        do
        {
          v45 = (__m128)*((unsigned int *)v43 - 4);
          v45.m128_f32[0] = (float)((float)((float)(v45.m128_f32[0] - center->y) * (float)(v45.m128_f32[0] - center->y))
                                  + (float)((float)(*(v43 - 5) - center->x) * (float)(*(v43 - 5) - center->x)))
                          + (float)((float)(*(v43 - 3) - center->z) * (float)(*(v43 - 3) - center->z));
          if ( v45.m128_f32[0] > v42 )
          {
            LODWORD(v46) = (unsigned __int128)_mm_sqrt_ps(v45);
            v47 = (float)(v46 + *v5) * 0.5;
            *v5 = v47;
            v48 = (float)(v47 * center->y) + (float)((float)(v46 - v47) * *(v43 - 4));
            v49 = (float)(1.0 / v46) * (float)((float)(v47 * center->z) + (float)((float)(v46 - v47) * *(v43 - 3)));
            center->x = (float)(1.0 / v46)
                      * (float)((float)(v47 * center->x) + (float)((float)(v46 - v47) * *(v43 - 5)));
            center->y = (float)(1.0 / v46) * v48;
            center->z = v49;
          }
          v50 = (__m128)*((unsigned int *)v43 - 1);
          v50.m128_f32[0] = (float)((float)((float)(v50.m128_f32[0] - center->y) * (float)(v50.m128_f32[0] - center->y))
                                  + (float)((float)(*(v43 - 2) - center->x) * (float)(*(v43 - 2) - center->x)))
                          + (float)((float)(*v43 - center->z) * (float)(*v43 - center->z));
          if ( v50.m128_f32[0] > v42 )
          {
            LODWORD(v51) = (unsigned __int128)_mm_sqrt_ps(v50);
            v52 = (float)(v51 + *v5) * 0.5;
            *v5 = v52;
            v53 = (float)(v52 * center->y) + (float)((float)(v51 - v52) * *(v43 - 1));
            v54 = (float)(1.0 / v51) * (float)((float)(v52 * center->z) + (float)((float)(v51 - v52) * *v43));
            center->x = (float)(1.0 / v51)
                      * (float)((float)(v52 * center->x) + (float)((float)(v51 - v52) * *(v43 - 2)));
            center->y = (float)(1.0 / v51) * v53;
            center->z = v54;
          }
          v55 = (__m128)*((unsigned int *)v43 + 2);
          v55.m128_f32[0] = (float)((float)((float)(v55.m128_f32[0] - center->y) * (float)(v55.m128_f32[0] - center->y))
                                  + (float)((float)(v43[1] - center->x) * (float)(v43[1] - center->x)))
                          + (float)((float)(v43[3] - center->z) * (float)(v43[3] - center->z));
          if ( v55.m128_f32[0] > v42 )
          {
            LODWORD(v56) = (unsigned __int128)_mm_sqrt_ps(v55);
            v57 = (float)(v56 + *v5) * 0.5;
            *v5 = v57;
            v58 = (float)(v57 * center->y) + (float)((float)(v56 - v57) * v43[2]);
            v59 = (float)(1.0 / v56) * (float)((float)(v57 * center->z) + (float)((float)(v56 - v57) * v43[3]));
            center->x = (float)(1.0 / v56) * (float)((float)(v57 * center->x) + (float)((float)(v56 - v57) * v43[1]));
            center->y = (float)(1.0 / v56) * v58;
            center->z = v59;
          }
          v60 = (__m128)*((unsigned int *)v43 + 5);
          v60.m128_f32[0] = (float)((float)((float)(v60.m128_f32[0] - center->y) * (float)(v60.m128_f32[0] - center->y))
                                  + (float)((float)(v43[4] - center->x) * (float)(v43[4] - center->x)))
                          + (float)((float)(v43[6] - center->z) * (float)(v43[6] - center->z));
          if ( v60.m128_f32[0] > v42 )
          {
            LODWORD(v61) = (unsigned __int128)_mm_sqrt_ps(v60);
            v62 = (float)(v61 + *v5) * 0.5;
            *v5 = v62;
            v63 = (float)(1.0 / v61) * (float)((float)(v62 * center->y) + (float)((float)(v61 - v62) * v43[5]));
            v64 = (float)(1.0 / v61) * (float)((float)(v62 * center->z) + (float)((float)(v61 - v62) * v43[6]));
            center->x = (float)(1.0 / v61) * (float)((float)(v62 * center->x) + (float)((float)(v61 - v62) * v43[4]));
            center->y = v63;
            center->z = v64;
          }
          v43 += 12;
          --v44;
        }
        while ( v44 );
      }
      if ( v10 < numPoints )
      {
        v65 = numPoints - v10;
        v66 = &v4->x + v10 + 2 * (v10 + 1);
        do
        {
          v67 = (__m128)*((unsigned int *)v66 - 1);
          v67.m128_f32[0] = (float)((float)((float)(v67.m128_f32[0] - center->y) * (float)(v67.m128_f32[0] - center->y))
                                  + (float)((float)(*(v66 - 2) - center->x) * (float)(*(v66 - 2) - center->x)))
                          + (float)((float)(*v66 - center->z) * (float)(*v66 - center->z));
          if ( v67.m128_f32[0] > v42 )
          {
            LODWORD(v68) = (unsigned __int128)_mm_sqrt_ps(v67);
            v69 = (float)(v68 + *v5) * 0.5;
            *v5 = v69;
            v70 = (float)(1.0 / v68) * (float)((float)(v69 * center->y) + (float)((float)(v68 - v69) * *(v66 - 1)));
            v71 = (float)(1.0 / v68) * (float)((float)(v69 * center->z) + (float)((float)(v68 - v69) * *v66));
            center->x = (float)(1.0 / v68)
                      * (float)((float)(v69 * center->x) + (float)((float)(v68 - v69) * *(v66 - 2)));
            center->y = v70;
            center->z = v71;
          }
          v66 += 3;
          --v65;
        }
        while ( v65 );
      }
    }
  }
  else
  {
    *radius = -1.0;
  }
}

// File Line: 463
// RVA: 0x205F90
UFG::qMatrix44 *__fastcall UFG::Editor::Utility::ComputeLocalMatrix(UFG::qMatrix44 *result, UFG::qPropertySet *obj, UFG::qMatrix44 *W)
{
  UFG::qPropertySet *v3; // rsi
  UFG::qMatrix44 *v4; // rdi
  UFG::qMatrix44 *v5; // rbx
  unsigned int *v6; // rax
  __int64 v7; // rax
  UFG::qPropertySet *v8; // rdx
  __int64 v9; // rax
  signed __int64 v10; // rdx
  UFG::qMatrix44 *v11; // rax
  __m128 v12; // ST20_16
  __m128 v13; // ST30_16
  __m128 v14; // ST40_16
  __m128 v15; // ST50_16
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // eax
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // eax
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // eax
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // eax
  float v42; // xmm2_4
  UFG::qMatrix44 resulta; // [rsp+60h] [rbp-A0h]
  UFG::qMatrix44 v45; // [rsp+A0h] [rbp-60h]
  UFG::qMatrix44 d; // [rsp+E0h] [rbp-20h]
  UFG::qMatrix44 m; // [rsp+120h] [rbp+20h]

  v3 = obj;
  v4 = W;
  v5 = result;
  v6 = UFG::qPropertySet::Get<unsigned long>(obj, (UFG::qSymbol *)&UFG::Editor::gsymXformParent.mUID, DEPTH_RECURSE);
  if ( v6 && *v6 )
  {
    v7 = v3->mOwner.mOffset;
    if ( v7 && (v8 = (UFG::qPropertySet *)((char *)&v3->mOwner + v7)) != 0i64 )
    {
      while ( !((v8->mFlags >> 1) & 1) )
      {
        v9 = v8->mOwner.mOffset;
        v10 = (signed __int64)&v8->mOwner;
        if ( v9 )
        {
          v8 = (UFG::qPropertySet *)(v9 + v10);
          if ( v8 )
            continue;
        }
        goto LABEL_8;
      }
      v11 = UFG::Editor::SceneManager::GetSceneObjectWorldMatrix(&resulta, v8);
    }
    else
    {
LABEL_8:
      v11 = &resulta;
      resulta = UFG::qMatrix44::msIdentity;
    }
    v12 = (__m128)v11->v0;
    v13 = (__m128)v11->v1;
    v14 = (__m128)v11->v2;
    v15 = (__m128)v11->v3;
    UFG::qInverseAffine(&d, v4);
    m.v0 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), (__m128)d.v0), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), (__m128)d.v1)),
                              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), (__m128)d.v2)),
                            _mm_mul_ps(_mm_shuffle_ps(v12, v12, 255), (__m128)d.v3));
    m.v1 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), (__m128)d.v0), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), (__m128)d.v1)),
                              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), (__m128)d.v2)),
                            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 255), (__m128)d.v3));
    m.v2 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), (__m128)d.v0), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), (__m128)d.v1)),
                              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), (__m128)d.v2)),
                            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), (__m128)d.v3));
    m.v3 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), (__m128)d.v0), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), (__m128)d.v1)),
                              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), (__m128)d.v2)),
                            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), (__m128)d.v3));
    UFG::qInverseAffine(&v45, &m);
    v16 = v45.v0.y;
    v5->v0.x = v45.v0.x;
    v17 = v45.v0.z;
    v5->v0.y = v16;
    v18 = v45.v0.w;
    v5->v0.z = v17;
    v19 = v45.v1.x;
    v5->v0.w = v18;
    v20 = v45.v1.y;
    v5->v1.x = v19;
    v21 = v45.v1.z;
    v5->v1.y = v20;
    v22 = v45.v1.w;
    v5->v1.z = v21;
    v23 = v45.v2.x;
    v5->v1.w = v22;
    v24 = v45.v2.y;
    v5->v2.x = v23;
    v25 = v45.v2.z;
    v5->v2.y = v24;
    v26 = v45.v2.w;
    v5->v2.z = v25;
    v27 = v45.v3.x;
    v5->v2.w = v26;
    v28 = v45.v3.y;
    v5->v3.x = v27;
    v29 = v45.v3.z;
    v5->v3.y = v28;
    v30 = v45.v3.w;
    v5->v3.z = v29;
    v5->v3.w = v30;
  }
  else
  {
    v31 = v4->v0.x;
    v32 = v4->v0.z;
    v33 = v4->v0.w;
    v5->v0.y = v4->v0.y;
    v5->v0.z = v32;
    v5->v0.x = v31;
    v5->v0.w = v33;
    v34 = v4->v1.z;
    v35 = v4->v1.x;
    v36 = v4->v1.w;
    v5->v1.y = v4->v1.y;
    v5->v1.z = v34;
    v5->v1.x = v35;
    v5->v1.w = v36;
    v37 = v4->v2.z;
    v38 = v4->v2.x;
    v39 = v4->v2.w;
    v5->v2.y = v4->v2.y;
    v5->v2.z = v37;
    v5->v2.x = v38;
    v5->v2.w = v39;
    v40 = v4->v3.z;
    v41 = v4->v3.x;
    v42 = v4->v3.w;
    v5->v3.y = v4->v3.y;
    v5->v3.z = v40;
    v5->v3.x = v41;
    v5->v3.w = v42;
  }
  return v5;
}

// File Line: 569
// RVA: 0x21EA70
UFG::qVector3 *__fastcall UFG::Editor::Utility::World_To_NDC(UFG::qVector3 *result, UFG::Editor::View *view, UFG::qVector3 *wld, UFG::qMatrix44 *modelMat, bool *negativePerspectiveDivide)
{
  UFG::Editor::Camera *v5; // rdi
  UFG::qMatrix44 *v6; // r14
  UFG::qVector3 *v7; // rbp
  UFG::Editor::View *v8; // rsi
  UFG::qVector3 *v9; // rbx
  UFG::BaseCameraComponent *v10; // rax
  signed __int64 v11; // rax
  UFG::BaseCameraComponent *v12; // rcx
  UFG::qMatrix44 *v13; // rdi
  UFG::qMatrix44 *v14; // rax
  UFG::qMatrix44 *v15; // rax
  float v16; // xmm2_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm8_4
  UFG::qVector3 *v22; // rax
  UFG::qMatrix44 v23; // [rsp+20h] [rbp-F8h]
  UFG::qMatrix44 resulta; // [rsp+60h] [rbp-B8h]
  UFG::qMatrix44 v25; // [rsp+A0h] [rbp-78h]

  v5 = view->mCamera;
  v6 = modelMat;
  v7 = wld;
  v8 = view;
  v9 = result;
  v10 = UFG::Director::Get()->mCurrentCamera;
  if ( v10 && (v11 = (signed __int64)&v10->mCamera) != 0 && !*(_BYTE *)(v11 + 256) )
  {
    v12 = UFG::Director::Get()->mCurrentCamera;
    if ( v12 )
      v13 = UFG::Camera::GetViewProjection(&v12->mCamera);
    else
      v13 = UFG::Camera::GetViewProjection(0i64);
  }
  else
  {
    v13 = &v5->mProj;
  }
  v14 = UFG::Editor::Camera::GetMatView(v8->mCamera, &resulta);
  v15 = UFG::qMatrix44::operator*(v6, &v25, v14);
  UFG::qMatrix44::operator*(v15, &v23, v13);
  v16 = v7->y;
  v17 = v7->z;
  v18 = (float)((float)((float)(v23.v1.x * v16) + (float)(v23.v0.x * v7->x)) + (float)(v23.v2.x * v17)) + v23.v3.x;
  v19 = (float)((float)((float)(v23.v1.y * v16) + (float)(v23.v0.y * v7->x)) + (float)(v23.v2.y * v17)) + v23.v3.y;
  v20 = (float)((float)((float)(v23.v1.z * v16) + (float)(v23.v0.z * v7->x)) + (float)(v23.v2.z * v17)) + v23.v3.z;
  v21 = (float)((float)((float)(v23.v1.w * v16) + (float)(v23.v0.w * v7->x)) + (float)(v23.v2.w * v17)) + v23.v3.w;
  if ( negativePerspectiveDivide )
    *negativePerspectiveDivide = v21 < 0.0;
  v22 = v9;
  v9->y = v19 * (float)(1.0 / v21);
  v9->z = v20 * (float)(1.0 / v21);
  v9->x = v18 * (float)(1.0 / v21);
  return v22;
}

// File Line: 605
// RVA: 0x207700
__int64 __fastcall UFG::Editor::Utility::DecomposeAffineEulerSmart_RoundedDegrees(UFG::qVector3 *soln, UFG::qMatrix44 *affine, bool biasPos)
{
  bool v3; // bl
  UFG::qMatrix44 *v4; // rdi
  UFG::qVector3 *v5; // rsi
  unsigned __int8 v6; // dl
  __m128 v7; // xmm5
  bool v8; // cf
  bool v9; // zf
  __m128 v10; // xmm8
  __m128 v11; // xmm6
  __m128 v12; // xmm7
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  signed int v15; // ecx
  int v16; // ecx
  signed int v17; // ecx
  float v18; // xmm8_4
  float v19; // xmm5_4
  signed int v20; // ecx
  int v21; // ecx
  signed int v22; // ecx
  float v23; // xmm5_4
  float v24; // xmm6_4
  signed int v25; // ecx
  int v26; // ecx
  signed int v27; // ecx
  float v28; // xmm6_4
  float v29; // xmm7_4
  signed int v30; // ecx
  int v31; // ecx
  signed int v32; // ecx
  float v33; // xmm7_4
  float v34; // xmm4_4
  signed int v35; // ecx
  int v36; // ecx
  signed int v37; // ecx
  float v38; // xmm4_4
  float v39; // xmm3_4
  signed int v40; // ecx
  int v41; // ecx
  signed int v42; // ecx
  float v43; // xmm8_4
  float v44; // xmm4_4
  float v45; // xmm7_4
  UFG::qVector3 *v46; // rcx
  float v47; // xmm6_4
  float v48; // xmm5_4
  UFG::qVector3 sol_a; // [rsp+20h] [rbp-78h]
  UFG::qVector3 sol_b; // [rsp+30h] [rbp-68h]

  v3 = biasPos;
  v4 = affine;
  v5 = soln;
  UFG::Editor::Utility::Round(&soln->x, 0.1);
  UFG::Editor::Utility::Round(&v5->y, 0.1);
  UFG::Editor::Utility::Round(&v5->z, 0.1);
  v6 = UFG::qDecomposeAffineEuler(&sol_a, &sol_b, v4, v3);
  v10 = (__m128)LODWORD(sol_a.x);
  v10.m128_f32[0] = (float)(sol_a.x * 180.0) * 0.31830987;
  v7 = (__m128)LODWORD(sol_a.y);
  v11 = (__m128)LODWORD(sol_a.z);
  v12 = (__m128)LODWORD(sol_b.x);
  v13 = (__m128)LODWORD(sol_b.y);
  v14 = (__m128)LODWORD(sol_b.z);
  v7.m128_f32[0] = (float)(sol_a.y * 180.0) * 0.31830987;
  v8 = v10.m128_f32[0] < 0.0;
  v9 = v10.m128_f32[0] == 0.0;
  v10.m128_f32[0] = v10.m128_f32[0] * 10.0;
  v11.m128_f32[0] = (float)(sol_a.z * 180.0) * 0.31830987;
  v12.m128_f32[0] = (float)(sol_b.x * 180.0) * 0.31830987;
  v13.m128_f32[0] = (float)(sol_b.y * 180.0) * 0.31830987;
  v14.m128_f32[0] = (float)(sol_b.z * 180.0) * 0.31830987;
  if ( v8 || v9 )
  {
    v10.m128_f32[0] = v10.m128_f32[0] - 0.5;
    v17 = (signed int)v10.m128_f32[0];
    if ( (signed int)v10.m128_f32[0] != 0x80000000 && (float)v17 != v10.m128_f32[0] )
    {
      v16 = (_mm_movemask_ps(_mm_unpacklo_ps(v10, v10)) & 1 ^ 1) + v17;
      goto LABEL_8;
    }
  }
  else
  {
    v10.m128_f32[0] = v10.m128_f32[0] + 0.5;
    v15 = (signed int)v10.m128_f32[0];
    if ( (signed int)v10.m128_f32[0] != 0x80000000 && (float)v15 != v10.m128_f32[0] )
    {
      v16 = v15 - (_mm_movemask_ps(_mm_unpacklo_ps(v10, v10)) & 1);
LABEL_8:
      v10.m128_f32[0] = (float)v16;
      goto LABEL_9;
    }
  }
LABEL_9:
  v18 = v10.m128_f32[0] * 0.1;
  v8 = v7.m128_f32[0] < 0.0;
  v9 = v7.m128_f32[0] == 0.0;
  v19 = v7.m128_f32[0] * 10.0;
  sol_a.x = v18;
  if ( v8 || v9 )
  {
    v7.m128_f32[0] = v19 - 0.5;
    v22 = (signed int)v7.m128_f32[0];
    if ( (signed int)v7.m128_f32[0] != 0x80000000 && (float)v22 != v7.m128_f32[0] )
    {
      v21 = (_mm_movemask_ps(_mm_unpacklo_ps(v7, v7)) & 1 ^ 1) + v22;
      goto LABEL_16;
    }
  }
  else
  {
    v7.m128_f32[0] = v19 + 0.5;
    v20 = (signed int)v7.m128_f32[0];
    if ( (signed int)v7.m128_f32[0] != 0x80000000 && (float)v20 != v7.m128_f32[0] )
    {
      v21 = v20 - (_mm_movemask_ps(_mm_unpacklo_ps(v7, v7)) & 1);
LABEL_16:
      v7.m128_f32[0] = (float)v21;
      goto LABEL_17;
    }
  }
LABEL_17:
  v23 = v7.m128_f32[0] * 0.1;
  v8 = v11.m128_f32[0] < 0.0;
  v9 = v11.m128_f32[0] == 0.0;
  v24 = v11.m128_f32[0] * 10.0;
  sol_a.y = v23;
  if ( v8 || v9 )
  {
    v11.m128_f32[0] = v24 - 0.5;
    v27 = (signed int)v11.m128_f32[0];
    if ( (signed int)v11.m128_f32[0] != 0x80000000 && (float)v27 != v11.m128_f32[0] )
    {
      v26 = (_mm_movemask_ps(_mm_unpacklo_ps(v11, v11)) & 1 ^ 1) + v27;
      goto LABEL_24;
    }
  }
  else
  {
    v11.m128_f32[0] = v24 + 0.5;
    v25 = (signed int)v11.m128_f32[0];
    if ( (signed int)v11.m128_f32[0] != 0x80000000 && (float)v25 != v11.m128_f32[0] )
    {
      v26 = v25 - (_mm_movemask_ps(_mm_unpacklo_ps(v11, v11)) & 1);
LABEL_24:
      v11.m128_f32[0] = (float)v26;
      goto LABEL_25;
    }
  }
LABEL_25:
  v28 = v11.m128_f32[0] * 0.1;
  v8 = v12.m128_f32[0] < 0.0;
  v9 = v12.m128_f32[0] == 0.0;
  v29 = v12.m128_f32[0] * 10.0;
  sol_a.z = v28;
  if ( v8 || v9 )
  {
    v12.m128_f32[0] = v29 - 0.5;
    v32 = (signed int)v12.m128_f32[0];
    if ( (signed int)v12.m128_f32[0] != 0x80000000 && (float)v32 != v12.m128_f32[0] )
    {
      v31 = (_mm_movemask_ps(_mm_unpacklo_ps(v12, v12)) & 1 ^ 1) + v32;
      goto LABEL_32;
    }
  }
  else
  {
    v12.m128_f32[0] = v29 + 0.5;
    v30 = (signed int)v12.m128_f32[0];
    if ( (signed int)v12.m128_f32[0] != 0x80000000 && (float)v30 != v12.m128_f32[0] )
    {
      v31 = v30 - (_mm_movemask_ps(_mm_unpacklo_ps(v12, v12)) & 1);
LABEL_32:
      v12.m128_f32[0] = (float)v31;
      goto LABEL_33;
    }
  }
LABEL_33:
  v33 = v12.m128_f32[0] * 0.1;
  v8 = v13.m128_f32[0] < 0.0;
  v9 = v13.m128_f32[0] == 0.0;
  v34 = v13.m128_f32[0] * 10.0;
  sol_b.x = v33;
  if ( v8 || v9 )
  {
    v13.m128_f32[0] = v34 - 0.5;
    v37 = (signed int)v13.m128_f32[0];
    if ( (signed int)v13.m128_f32[0] != 0x80000000 && (float)v37 != v13.m128_f32[0] )
    {
      v36 = (_mm_movemask_ps(_mm_unpacklo_ps(v13, v13)) & 1 ^ 1) + v37;
      goto LABEL_40;
    }
  }
  else
  {
    v13.m128_f32[0] = v34 + 0.5;
    v35 = (signed int)v13.m128_f32[0];
    if ( (signed int)v13.m128_f32[0] != 0x80000000 && (float)v35 != v13.m128_f32[0] )
    {
      v36 = v35 - (_mm_movemask_ps(_mm_unpacklo_ps(v13, v13)) & 1);
LABEL_40:
      v13.m128_f32[0] = (float)v36;
      goto LABEL_41;
    }
  }
LABEL_41:
  v38 = v13.m128_f32[0] * 0.1;
  v8 = v14.m128_f32[0] < 0.0;
  v9 = v14.m128_f32[0] == 0.0;
  v39 = v14.m128_f32[0] * 10.0;
  sol_b.y = v38;
  if ( v8 || v9 )
  {
    v14.m128_f32[0] = v39 - 0.5;
    v42 = (signed int)v14.m128_f32[0];
    if ( (signed int)v14.m128_f32[0] != 0x80000000 && (float)v42 != v14.m128_f32[0] )
    {
      v41 = (_mm_movemask_ps(_mm_unpacklo_ps(v14, v14)) & 1 ^ 1) + v42;
      goto LABEL_48;
    }
  }
  else
  {
    v14.m128_f32[0] = v39 + 0.5;
    v40 = (signed int)v14.m128_f32[0];
    if ( (signed int)v14.m128_f32[0] != 0x80000000 && (float)v40 != v14.m128_f32[0] )
    {
      v41 = v40 - (_mm_movemask_ps(_mm_unpacklo_ps(v14, v14)) & 1);
LABEL_48:
      v14.m128_f32[0] = (float)v41;
      goto LABEL_49;
    }
  }
LABEL_49:
  v43 = (float)(v18 - v5->x) * (float)(v18 - v5->x);
  v44 = (float)(v38 - v5->y) * (float)(v38 - v5->y);
  v45 = (float)(v33 - v5->x) * (float)(v33 - v5->x);
  v46 = &sol_a;
  v47 = v28 - v5->z;
  v48 = v23 - v5->y;
  sol_b.z = v14.m128_f32[0] * 0.1;
  if ( (float)((float)(v44 + v45) + (float)((float)(sol_b.z - v5->z) * (float)(sol_b.z - v5->z))) <= (float)((float)(v43 + (float)(v48 * v48)) + (float)(v47 * v47)) )
    v46 = &sol_b;
  v5->x = v46->x;
  v5->y = v46->y;
  v5->z = v46->z;
  return v6;
}

