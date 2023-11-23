// File Line: 97
// RVA: 0x20E180
UFG::qVector3 *__fastcall UFG::Editor::Utility::NDC_To_World(
        UFG::qVector3 *result,
        UFG::Editor::View *view,
        UFG::qVector3 *ndc)
{
  UFG::Editor::Camera *mCamera; // rdi
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax
  UFG::BaseCameraComponent *v8; // rcx
  UFG::qMatrix44 *ViewProjection; // rbx
  UFG::qMatrix44 *MatView; // rax
  UFG::qVector3 *v11; // rax
  float z; // xmm7_4
  float y; // xmm4_4
  float v14; // xmm6_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  UFG::qMatrix44 d; // [rsp+20h] [rbp-B8h] BYREF
  UFG::qMatrix44 resulta; // [rsp+60h] [rbp-78h] BYREF

  mCamera = view->mCamera;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera && (p_mCamera = &mCurrentCamera->mCamera) != 0i64 && !p_mCamera->bUseOverrideMatrices )
  {
    v8 = UFG::Director::Get()->mCurrentCamera;
    if ( v8 )
      ViewProjection = UFG::Camera::GetViewProjection(&v8->mCamera);
    else
      ViewProjection = UFG::Camera::GetViewProjection(0i64);
  }
  else
  {
    ViewProjection = &mCamera->mProj;
  }
  MatView = UFG::Editor::Camera::GetMatView(mCamera, &resulta);
  UFG::qMatrix44::operator*(MatView, &d, ViewProjection);
  UFG::qInverse(&d, &d);
  v11 = result;
  z = ndc->z;
  y = ndc->y;
  v14 = (float)((float)((float)(d.v1.y * y) + (float)(d.v0.y * ndc->x)) + (float)(d.v2.y * z)) + d.v3.y;
  v15 = (float)((float)((float)(d.v1.z * y) + (float)(d.v0.z * ndc->x)) + (float)(d.v2.z * z)) + d.v3.z;
  v16 = 1.0 / (float)((float)((float)((float)(d.v1.w * y) + (float)(d.v0.w * ndc->x)) + (float)(d.v2.w * z)) + d.v3.w);
  result->x = (float)((float)((float)((float)(d.v1.x * y) + (float)(d.v0.x * ndc->x)) + (float)(d.v2.x * z)) + d.v3.x)
            * v16;
  result->y = v14 * v16;
  result->z = v15 * v16;
  return v11;
}

// File Line: 157
// RVA: 0x2126B0
void __fastcall UFG::Editor::Utility::Round(float *r, float p)
{
  bool v3; // cc
  __m128 v4; // xmm2
  int v5; // edx
  int v6; // ecx

  v4 = (__m128)*(unsigned int *)r;
  v3 = v4.m128_f32[0] <= 0.0;
  v4.m128_f32[0] = v4.m128_f32[0] / p;
  if ( v3 )
  {
    v4.m128_f32[0] = v4.m128_f32[0] - 0.5;
    v6 = (int)v4.m128_f32[0];
    if ( (int)v4.m128_f32[0] != 0x80000000 && (float)v6 != v4.m128_f32[0] )
      v4.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v4, v4)) & 1) + v6);
    *r = v4.m128_f32[0] * p;
  }
  else
  {
    v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
    v5 = (int)v4.m128_f32[0];
    if ( (int)v4.m128_f32[0] != 0x80000000 && (float)v5 != v4.m128_f32[0] )
      v4.m128_f32[0] = (float)(v5 - (_mm_movemask_ps(_mm_unpacklo_ps(v4, v4)) & 1));
    *r = v4.m128_f32[0] * p;
  }
}

// File Line: 270
// RVA: 0x209E60
void __fastcall UFG::Editor::Utility::FindMinimalBoundingSphere(
        UFG::qVector3 *center,
        float *radius,
        UFG::qVector3 *points,
        int numPoints)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  __int64 v10; // rdi
  __int64 v11; // r11
  float v12; // xmm15_4
  float v13; // xmm12_4
  float v14; // xmm13_4
  float v15; // xmm7_4
  float v16; // xmm11_4
  float v17; // xmm6_4
  float v18; // xmm8_4
  float v19; // xmm9_4
  float v20; // xmm10_4
  float *p_z; // rax
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
  __int64 v35; // rax
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
  __int64 v65; // r8
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

  if ( points && numPoints >= 1 )
  {
    if ( numPoints == 1 )
    {
      y = points->y;
      z = points->z;
      center->x = points->x;
      center->y = y;
      center->z = z;
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
        p_z = &points[1].z;
        v22 = ((unsigned __int64)(numPoints - 4i64) >> 2) + 1;
        v11 = 4 * v22;
        do
        {
          v23 = *(p_z - 5);
          if ( v8 > v23 )
          {
            v13 = *(p_z - 4);
            v14 = *(p_z - 3);
            v8 = *(p_z - 5);
          }
          if ( v9 < v23 )
          {
            v15 = *(p_z - 4);
            v16 = *(p_z - 3);
            v9 = *(p_z - 5);
          }
          v24 = *(p_z - 4);
          if ( v17 > v24 )
          {
            v12 = *(p_z - 5);
            v17 = *(p_z - 4);
            v78 = *(p_z - 3);
          }
          if ( v18 < v24 )
          {
            v73 = *(p_z - 5);
            v18 = *(p_z - 4);
            v76 = *(p_z - 3);
          }
          v25 = *(p_z - 3);
          if ( v19 > v25 )
          {
            v75 = *(p_z - 5);
            v77 = *(p_z - 4);
            v19 = *(p_z - 3);
          }
          if ( v20 < v25 )
          {
            v72 = *(p_z - 5);
            v74 = *(p_z - 4);
            v20 = *(p_z - 3);
          }
          v26 = *(p_z - 2);
          if ( v8 > v26 )
          {
            v13 = *(p_z - 1);
            v14 = *p_z;
            v8 = *(p_z - 2);
          }
          if ( v9 < v26 )
          {
            v15 = *(p_z - 1);
            v16 = *p_z;
            v9 = *(p_z - 2);
          }
          v27 = *(p_z - 1);
          if ( v17 > v27 )
          {
            v12 = *(p_z - 2);
            v17 = *(p_z - 1);
            v78 = *p_z;
          }
          if ( v18 < v27 )
          {
            v73 = *(p_z - 2);
            v18 = *(p_z - 1);
            v76 = *p_z;
          }
          if ( v19 > *p_z )
          {
            v75 = *(p_z - 2);
            v77 = *(p_z - 1);
            v19 = *p_z;
          }
          if ( v20 < *p_z )
          {
            v72 = *(p_z - 2);
            v74 = *(p_z - 1);
            v20 = *p_z;
          }
          v28 = p_z[1];
          if ( v8 > v28 )
          {
            v13 = p_z[2];
            v14 = p_z[3];
            v8 = p_z[1];
          }
          if ( v9 < v28 )
          {
            v15 = p_z[2];
            v16 = p_z[3];
            v9 = p_z[1];
          }
          v29 = p_z[2];
          if ( v17 > v29 )
          {
            v12 = p_z[1];
            v17 = p_z[2];
            v78 = p_z[3];
          }
          if ( v18 < v29 )
          {
            v73 = p_z[1];
            v18 = p_z[2];
            v76 = p_z[3];
          }
          v30 = p_z[3];
          if ( v19 > v30 )
          {
            v75 = p_z[1];
            v77 = p_z[2];
            v19 = p_z[3];
          }
          if ( v20 < v30 )
          {
            v72 = p_z[1];
            v74 = p_z[2];
            v20 = p_z[3];
          }
          v31 = p_z[4];
          if ( v8 > v31 )
          {
            v13 = p_z[5];
            v14 = p_z[6];
            v8 = p_z[4];
          }
          if ( v9 < v31 )
          {
            v15 = p_z[5];
            v16 = p_z[6];
            v9 = p_z[4];
          }
          v32 = p_z[5];
          if ( v17 > v32 )
          {
            v12 = p_z[4];
            v17 = p_z[5];
            v78 = p_z[6];
          }
          if ( v18 < v32 )
          {
            v73 = p_z[4];
            v18 = p_z[5];
            v76 = p_z[6];
          }
          v33 = p_z[6];
          if ( v19 > v33 )
          {
            v75 = p_z[4];
            v77 = p_z[5];
            v19 = p_z[6];
          }
          if ( v20 < v33 )
          {
            v72 = p_z[4];
            v74 = p_z[5];
            v20 = p_z[6];
          }
          p_z += 12;
          --v22;
        }
        while ( v22 );
      }
      if ( v11 < numPoints )
      {
        v34 = &points->z + 2 * v11 + v11;
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
      *radius = fsqrt(v42);
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
            v46 = _mm_sqrt_ps(v45).m128_f32[0];
            v47 = (float)(v46 + *radius) * 0.5;
            *radius = v47;
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
            v51 = _mm_sqrt_ps(v50).m128_f32[0];
            v52 = (float)(v51 + *radius) * 0.5;
            *radius = v52;
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
            v56 = _mm_sqrt_ps(v55).m128_f32[0];
            v57 = (float)(v56 + *radius) * 0.5;
            *radius = v57;
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
            v61 = _mm_sqrt_ps(v60).m128_f32[0];
            v62 = (float)(v61 + *radius) * 0.5;
            *radius = v62;
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
        v66 = &points->z + 2 * v10 + v10;
        do
        {
          v67 = (__m128)*((unsigned int *)v66 - 1);
          v67.m128_f32[0] = (float)((float)((float)(v67.m128_f32[0] - center->y) * (float)(v67.m128_f32[0] - center->y))
                                  + (float)((float)(*(v66 - 2) - center->x) * (float)(*(v66 - 2) - center->x)))
                          + (float)((float)(*v66 - center->z) * (float)(*v66 - center->z));
          if ( v67.m128_f32[0] > v42 )
          {
            v68 = _mm_sqrt_ps(v67).m128_f32[0];
            v69 = (float)(v68 + *radius) * 0.5;
            *radius = v69;
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
UFG::qMatrix44 *__fastcall UFG::Editor::Utility::ComputeLocalMatrix(
        UFG::qMatrix44 *result,
        UFG::qPropertySet *obj,
        UFG::qMatrix44 *W)
{
  unsigned int *v6; // rax
  __int64 mOffset; // rax
  UFG::qPropertySet *v8; // rdx
  __int64 v9; // rax
  UFG::qOffset64<UFG::qPropertyCollection *> *p_mOwner; // rdx
  UFG::qMatrix44 *SceneObjectWorldMatrix; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  float v14; // xmm1_4
  float x; // xmm0_4
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
  float v27; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // eax
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // eax
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // eax
  float v38; // xmm2_4
  UFG::qVector4 v40; // [rsp+20h] [rbp-E0h]
  UFG::qVector4 v41; // [rsp+30h] [rbp-D0h]
  UFG::qVector4 v42; // [rsp+40h] [rbp-C0h]
  UFG::qVector4 v43; // [rsp+50h] [rbp-B0h]
  UFG::qMatrix44 resulta; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qMatrix44 v45; // [rsp+A0h] [rbp-60h] BYREF
  UFG::qMatrix44 d; // [rsp+E0h] [rbp-20h] BYREF
  UFG::qMatrix44 m; // [rsp+120h] [rbp+20h] BYREF

  v6 = UFG::qPropertySet::Get<unsigned long>(
         obj,
         (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymXformParent,
         DEPTH_RECURSE);
  if ( v6 && *v6 )
  {
    mOffset = obj->mOwner.mOffset;
    if ( mOffset && (v8 = (UFG::qPropertySet *)((char *)&obj->mOwner + mOffset)) != 0i64 )
    {
      while ( (v8->mFlags & 2) == 0 )
      {
        v9 = v8->mOwner.mOffset;
        p_mOwner = &v8->mOwner;
        if ( v9 )
        {
          v8 = (UFG::qPropertySet *)((char *)p_mOwner + v9);
          if ( v8 )
            continue;
        }
        goto LABEL_8;
      }
      SceneObjectWorldMatrix = UFG::Editor::SceneManager::GetSceneObjectWorldMatrix(&resulta, v8);
    }
    else
    {
LABEL_8:
      SceneObjectWorldMatrix = &resulta;
      resulta = UFG::qMatrix44::msIdentity;
    }
    v40 = SceneObjectWorldMatrix->v0;
    v41 = SceneObjectWorldMatrix->v1;
    v42 = SceneObjectWorldMatrix->v2;
    v43 = SceneObjectWorldMatrix->v3;
    UFG::qInverseAffine(&d, W);
    m.v0 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)v40, (__m128)v40, 0), (__m128)d.v0),
                                  (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)v40, (__m128)v40, 85), (__m128)d.v1)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)v40, (__m128)v40, 170), (__m128)d.v2)),
                            _mm_mul_ps(_mm_shuffle_ps((__m128)v40, (__m128)v40, 255), (__m128)d.v3));
    m.v1 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)v41, (__m128)v41, 0), (__m128)d.v0),
                                  (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)v41, (__m128)v41, 85), (__m128)d.v1)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)v41, (__m128)v41, 170), (__m128)d.v2)),
                            _mm_mul_ps(_mm_shuffle_ps((__m128)v41, (__m128)v41, 255), (__m128)d.v3));
    m.v2 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)v42, (__m128)v42, 0), (__m128)d.v0),
                                  (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)v42, (__m128)v42, 85), (__m128)d.v1)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)v42, (__m128)v42, 170), (__m128)d.v2)),
                            _mm_mul_ps(_mm_shuffle_ps((__m128)v42, (__m128)v42, 255), (__m128)d.v3));
    m.v3 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)v43, (__m128)v43, 0), (__m128)d.v0),
                                  (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)v43, (__m128)v43, 85), (__m128)d.v1)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)v43, (__m128)v43, 170), (__m128)d.v2)),
                            _mm_mul_ps(_mm_shuffle_ps((__m128)v43, (__m128)v43, 255), (__m128)d.v3));
    UFG::qInverseAffine(&v45, &m);
    y = v45.v0.y;
    result->v0.x = v45.v0.x;
    z = v45.v0.z;
    result->v0.y = y;
    v14 = v45.v0.w;
    result->v0.z = z;
    x = v45.v1.x;
    result->v0.w = v14;
    v16 = v45.v1.y;
    result->v1.x = x;
    v17 = v45.v1.z;
    result->v1.y = v16;
    v18 = v45.v1.w;
    result->v1.z = v17;
    v19 = v45.v2.x;
    result->v1.w = v18;
    v20 = v45.v2.y;
    result->v2.x = v19;
    v21 = v45.v2.z;
    result->v2.y = v20;
    v22 = v45.v2.w;
    result->v2.z = v21;
    v23 = v45.v3.x;
    result->v2.w = v22;
    v24 = v45.v3.y;
    result->v3.x = v23;
    v25 = v45.v3.z;
    result->v3.y = v24;
    v26 = v45.v3.w;
    result->v3.z = v25;
    result->v3.w = v26;
  }
  else
  {
    v27 = W->v0.x;
    v28 = W->v0.z;
    v29 = W->v0.w;
    result->v0.y = W->v0.y;
    result->v0.z = v28;
    result->v0.x = v27;
    result->v0.w = v29;
    v30 = W->v1.z;
    v31 = W->v1.x;
    v32 = W->v1.w;
    result->v1.y = W->v1.y;
    result->v1.z = v30;
    result->v1.x = v31;
    result->v1.w = v32;
    v33 = W->v2.z;
    v34 = W->v2.x;
    v35 = W->v2.w;
    result->v2.y = W->v2.y;
    result->v2.z = v33;
    result->v2.x = v34;
    result->v2.w = v35;
    v36 = W->v3.z;
    v37 = W->v3.x;
    v38 = W->v3.w;
    result->v3.y = W->v3.y;
    result->v3.z = v36;
    result->v3.x = v37;
    result->v3.w = v38;
  }
  return result;
}

// File Line: 569
// RVA: 0x21EA70
UFG::qVector3 *__fastcall UFG::Editor::Utility::World_To_NDC(
        UFG::qVector3 *result,
        UFG::Editor::View *view,
        UFG::qVector3 *wld,
        UFG::qMatrix44 *modelMat,
        bool *negativePerspectiveDivide)
{
  UFG::Editor::Camera *mCamera; // rdi
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax
  UFG::BaseCameraComponent *v12; // rcx
  UFG::qMatrix44 *ViewProjection; // rdi
  UFG::qMatrix44 *MatView; // rax
  UFG::qMatrix44 *v15; // rax
  float y; // xmm2_4
  float z; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm8_4
  UFG::qVector3 *v22; // rax
  UFG::qMatrix44 v23; // [rsp+20h] [rbp-F8h] BYREF
  UFG::qMatrix44 resulta; // [rsp+60h] [rbp-B8h] BYREF
  UFG::qMatrix44 v25; // [rsp+A0h] [rbp-78h] BYREF

  mCamera = view->mCamera;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera && (p_mCamera = &mCurrentCamera->mCamera) != 0i64 && !p_mCamera->bUseOverrideMatrices )
  {
    v12 = UFG::Director::Get()->mCurrentCamera;
    if ( v12 )
      ViewProjection = UFG::Camera::GetViewProjection(&v12->mCamera);
    else
      ViewProjection = UFG::Camera::GetViewProjection(0i64);
  }
  else
  {
    ViewProjection = &mCamera->mProj;
  }
  MatView = UFG::Editor::Camera::GetMatView(view->mCamera, &resulta);
  v15 = UFG::qMatrix44::operator*(modelMat, &v25, MatView);
  UFG::qMatrix44::operator*(v15, &v23, ViewProjection);
  y = wld->y;
  z = wld->z;
  v18 = (float)((float)((float)(v23.v1.x * y) + (float)(v23.v0.x * wld->x)) + (float)(v23.v2.x * z)) + v23.v3.x;
  v19 = (float)((float)((float)(v23.v1.y * y) + (float)(v23.v0.y * wld->x)) + (float)(v23.v2.y * z)) + v23.v3.y;
  v20 = (float)((float)((float)(v23.v1.z * y) + (float)(v23.v0.z * wld->x)) + (float)(v23.v2.z * z)) + v23.v3.z;
  v21 = (float)((float)((float)(v23.v1.w * y) + (float)(v23.v0.w * wld->x)) + (float)(v23.v2.w * z)) + v23.v3.w;
  if ( negativePerspectiveDivide )
    *negativePerspectiveDivide = v21 < 0.0;
  v22 = result;
  result->y = v19 * (float)(1.0 / v21);
  result->z = v20 * (float)(1.0 / v21);
  result->x = v18 * (float)(1.0 / v21);
  return v22;
}

// File Line: 605
// RVA: 0x207700
__int64 __fastcall UFG::Editor::Utility::DecomposeAffineEulerSmart_RoundedDegrees(
        UFG::qVector3 *soln,
        UFG::qMatrix44 *affine,
        bool biasPos)
{
  unsigned __int8 v6; // dl
  __m128 y_low; // xmm5
  bool v8; // cc
  __m128 x_low; // xmm8
  __m128 z_low; // xmm6
  __m128 v11; // xmm7
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  float v17; // xmm8_4
  float v18; // xmm5_4
  int v19; // ecx
  int v20; // ecx
  int v21; // ecx
  float v22; // xmm5_4
  float v23; // xmm6_4
  int v24; // ecx
  int v25; // ecx
  int v26; // ecx
  float v27; // xmm6_4
  float v28; // xmm7_4
  int v29; // ecx
  int v30; // ecx
  int v31; // ecx
  float v32; // xmm7_4
  float v33; // xmm4_4
  int v34; // ecx
  int v35; // ecx
  int v36; // ecx
  float v37; // xmm4_4
  float v38; // xmm3_4
  int v39; // ecx
  int v40; // ecx
  int v41; // ecx
  float v42; // xmm8_4
  float v43; // xmm4_4
  float v44; // xmm7_4
  UFG::qVector3 *p_sol_a; // rcx
  float v46; // xmm6_4
  float v47; // xmm5_4
  UFG::qVector3 sol_a; // [rsp+20h] [rbp-78h] BYREF
  UFG::qVector3 sol_b; // [rsp+30h] [rbp-68h] BYREF

  UFG::Editor::Utility::Round(&soln->x, 0.1);
  UFG::Editor::Utility::Round(&soln->y, 0.1);
  UFG::Editor::Utility::Round(&soln->z, 0.1);
  v6 = UFG::qDecomposeAffineEuler(&sol_a, &sol_b, affine, biasPos);
  x_low = (__m128)LODWORD(sol_a.x);
  x_low.m128_f32[0] = (float)(sol_a.x * 180.0) * 0.31830987;
  y_low = (__m128)LODWORD(sol_a.y);
  z_low = (__m128)LODWORD(sol_a.z);
  v11 = (__m128)LODWORD(sol_b.x);
  v12 = (__m128)LODWORD(sol_b.y);
  v13 = (__m128)LODWORD(sol_b.z);
  y_low.m128_f32[0] = (float)(sol_a.y * 180.0) * 0.31830987;
  v8 = x_low.m128_f32[0] <= 0.0;
  x_low.m128_f32[0] = x_low.m128_f32[0] * 10.0;
  z_low.m128_f32[0] = (float)(sol_a.z * 180.0) * 0.31830987;
  v11.m128_f32[0] = (float)(sol_b.x * 180.0) * 0.31830987;
  v12.m128_f32[0] = (float)(sol_b.y * 180.0) * 0.31830987;
  v13.m128_f32[0] = (float)(sol_b.z * 180.0) * 0.31830987;
  if ( v8 )
  {
    x_low.m128_f32[0] = x_low.m128_f32[0] - 0.5;
    v16 = (int)x_low.m128_f32[0];
    if ( (int)x_low.m128_f32[0] != 0x80000000 && (float)v16 != x_low.m128_f32[0] )
    {
      v15 = !(_mm_movemask_ps(_mm_unpacklo_ps(x_low, x_low)) & 1) + v16;
      goto LABEL_8;
    }
  }
  else
  {
    x_low.m128_f32[0] = x_low.m128_f32[0] + 0.5;
    v14 = (int)x_low.m128_f32[0];
    if ( (int)x_low.m128_f32[0] != 0x80000000 && (float)v14 != x_low.m128_f32[0] )
    {
      v15 = v14 - (_mm_movemask_ps(_mm_unpacklo_ps(x_low, x_low)) & 1);
LABEL_8:
      x_low.m128_f32[0] = (float)v15;
    }
  }
  v17 = x_low.m128_f32[0] * 0.1;
  v8 = y_low.m128_f32[0] <= 0.0;
  v18 = y_low.m128_f32[0] * 10.0;
  sol_a.x = v17;
  if ( v8 )
  {
    y_low.m128_f32[0] = v18 - 0.5;
    v21 = (int)y_low.m128_f32[0];
    if ( (int)y_low.m128_f32[0] != 0x80000000 && (float)v21 != y_low.m128_f32[0] )
    {
      v20 = !(_mm_movemask_ps(_mm_unpacklo_ps(y_low, y_low)) & 1) + v21;
      goto LABEL_16;
    }
  }
  else
  {
    y_low.m128_f32[0] = v18 + 0.5;
    v19 = (int)y_low.m128_f32[0];
    if ( (int)y_low.m128_f32[0] != 0x80000000 && (float)v19 != y_low.m128_f32[0] )
    {
      v20 = v19 - (_mm_movemask_ps(_mm_unpacklo_ps(y_low, y_low)) & 1);
LABEL_16:
      y_low.m128_f32[0] = (float)v20;
    }
  }
  v22 = y_low.m128_f32[0] * 0.1;
  v8 = z_low.m128_f32[0] <= 0.0;
  v23 = z_low.m128_f32[0] * 10.0;
  sol_a.y = v22;
  if ( v8 )
  {
    z_low.m128_f32[0] = v23 - 0.5;
    v26 = (int)z_low.m128_f32[0];
    if ( (int)z_low.m128_f32[0] != 0x80000000 && (float)v26 != z_low.m128_f32[0] )
    {
      v25 = !(_mm_movemask_ps(_mm_unpacklo_ps(z_low, z_low)) & 1) + v26;
      goto LABEL_24;
    }
  }
  else
  {
    z_low.m128_f32[0] = v23 + 0.5;
    v24 = (int)z_low.m128_f32[0];
    if ( (int)z_low.m128_f32[0] != 0x80000000 && (float)v24 != z_low.m128_f32[0] )
    {
      v25 = v24 - (_mm_movemask_ps(_mm_unpacklo_ps(z_low, z_low)) & 1);
LABEL_24:
      z_low.m128_f32[0] = (float)v25;
    }
  }
  v27 = z_low.m128_f32[0] * 0.1;
  v8 = v11.m128_f32[0] <= 0.0;
  v28 = v11.m128_f32[0] * 10.0;
  sol_a.z = v27;
  if ( v8 )
  {
    v11.m128_f32[0] = v28 - 0.5;
    v31 = (int)v11.m128_f32[0];
    if ( (int)v11.m128_f32[0] != 0x80000000 && (float)v31 != v11.m128_f32[0] )
    {
      v30 = !(_mm_movemask_ps(_mm_unpacklo_ps(v11, v11)) & 1) + v31;
      goto LABEL_32;
    }
  }
  else
  {
    v11.m128_f32[0] = v28 + 0.5;
    v29 = (int)v11.m128_f32[0];
    if ( (int)v11.m128_f32[0] != 0x80000000 && (float)v29 != v11.m128_f32[0] )
    {
      v30 = v29 - (_mm_movemask_ps(_mm_unpacklo_ps(v11, v11)) & 1);
LABEL_32:
      v11.m128_f32[0] = (float)v30;
    }
  }
  v32 = v11.m128_f32[0] * 0.1;
  v8 = v12.m128_f32[0] <= 0.0;
  v33 = v12.m128_f32[0] * 10.0;
  sol_b.x = v32;
  if ( v8 )
  {
    v12.m128_f32[0] = v33 - 0.5;
    v36 = (int)v12.m128_f32[0];
    if ( (int)v12.m128_f32[0] != 0x80000000 && (float)v36 != v12.m128_f32[0] )
    {
      v35 = !(_mm_movemask_ps(_mm_unpacklo_ps(v12, v12)) & 1) + v36;
      goto LABEL_40;
    }
  }
  else
  {
    v12.m128_f32[0] = v33 + 0.5;
    v34 = (int)v12.m128_f32[0];
    if ( (int)v12.m128_f32[0] != 0x80000000 && (float)v34 != v12.m128_f32[0] )
    {
      v35 = v34 - (_mm_movemask_ps(_mm_unpacklo_ps(v12, v12)) & 1);
LABEL_40:
      v12.m128_f32[0] = (float)v35;
    }
  }
  v37 = v12.m128_f32[0] * 0.1;
  v8 = v13.m128_f32[0] <= 0.0;
  v38 = v13.m128_f32[0] * 10.0;
  sol_b.y = v37;
  if ( v8 )
  {
    v13.m128_f32[0] = v38 - 0.5;
    v41 = (int)v13.m128_f32[0];
    if ( (int)v13.m128_f32[0] != 0x80000000 && (float)v41 != v13.m128_f32[0] )
    {
      v40 = !(_mm_movemask_ps(_mm_unpacklo_ps(v13, v13)) & 1) + v41;
      goto LABEL_48;
    }
  }
  else
  {
    v13.m128_f32[0] = v38 + 0.5;
    v39 = (int)v13.m128_f32[0];
    if ( (int)v13.m128_f32[0] != 0x80000000 && (float)v39 != v13.m128_f32[0] )
    {
      v40 = v39 - (_mm_movemask_ps(_mm_unpacklo_ps(v13, v13)) & 1);
LABEL_48:
      v13.m128_f32[0] = (float)v40;
    }
  }
  v42 = (float)(v17 - soln->x) * (float)(v17 - soln->x);
  v43 = (float)(v37 - soln->y) * (float)(v37 - soln->y);
  v44 = (float)(v32 - soln->x) * (float)(v32 - soln->x);
  p_sol_a = &sol_a;
  v46 = v27 - soln->z;
  v47 = v22 - soln->y;
  sol_b.z = v13.m128_f32[0] * 0.1;
  if ( (float)((float)(v43 + v44) + (float)((float)(sol_b.z - soln->z) * (float)(sol_b.z - soln->z))) <= (float)((float)(v42 + (float)(v47 * v47)) + (float)(v46 * v46)) )
    p_sol_a = &sol_b;
  soln->x = p_sol_a->x;
  soln->y = p_sol_a->y;
  soln->z = p_sol_a->z;
  return v6;
}

