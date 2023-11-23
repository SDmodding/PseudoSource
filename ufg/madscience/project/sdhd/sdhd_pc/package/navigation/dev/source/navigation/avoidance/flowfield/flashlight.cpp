// File Line: 66
// RVA: 0xFD080
void __fastcall UFG::FlashlightDisplay2(
        UFG::qVector3 *vPosition,
        UFG::qVector3 *vDirection,
        UFG::FlashlightParams *params,
        Render::View *pView,
        UFG::qColour *c)
{
  float v9; // xmm0_4
  float y; // xmm15_4
  __m128 x_low; // xmm14
  float v12; // xmm3_4
  float z; // xmm5_4
  float fMaxDistance; // xmm7_4
  float fDeadDistance; // xmm4_4
  __m128 v16; // xmm2
  float v17; // xmm6_4
  float v18; // xmm5_4
  float v19; // xmm15_4
  float v20; // xmm12_4
  float v21; // xmm14_4
  float v22; // xmm2_4
  float v23; // xmm11_4
  float v24; // xmm9_4
  float v25; // xmm0_4
  float v26; // xmm15_4
  float v27; // xmm8_4
  float v28; // xmm0_4
  float v29; // xmm14_4
  float v30; // xmm13_4
  float v31; // xmm10_4
  float v32; // xmm5_4
  float v33; // xmm10_4
  UFG::qVector3 aVerts; // [rsp+30h] [rbp-108h] BYREF
  float v35; // [rsp+3Ch] [rbp-FCh]
  float v36; // [rsp+40h] [rbp-F8h]
  float v37; // [rsp+44h] [rbp-F4h]
  float v38; // [rsp+48h] [rbp-F0h]
  float v39; // [rsp+4Ch] [rbp-ECh]
  float v40; // [rsp+50h] [rbp-E8h]
  UFG::qVector3 v41; // [rsp+58h] [rbp-E0h] BYREF
  UFG::qVector3 v42; // [rsp+64h] [rbp-D4h]
  float v43; // [rsp+70h] [rbp-C8h]
  float v44; // [rsp+74h] [rbp-C4h]
  float v45; // [rsp+78h] [rbp-C0h]
  float v46; // [rsp+140h] [rbp+8h]
  float v47; // [rsp+140h] [rbp+8h]

  v9 = tanf(params->fMaxRads);
  y = vDirection->y;
  x_low = (__m128)LODWORD(vDirection->x);
  v12 = 0.0;
  z = vDirection->z;
  fMaxDistance = params->fMaxDistance;
  fDeadDistance = params->fDeadDistance;
  v16 = x_low;
  v46 = fMaxDistance * v9;
  v16.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
  if ( v16.m128_f32[0] != 0.0 )
    v12 = 1.0 / _mm_sqrt_ps(v16).m128_f32[0];
  v17 = (float)(params->fDeadDistance * v9) * 0.5;
  v18 = z * v12;
  v19 = y * v12;
  v20 = (float)(v19 * UFG::qVector3::msDirUp.z) - (float)(v18 * UFG::qVector3::msDirUp.y);
  v21 = x_low.m128_f32[0] * v12;
  v22 = v18 * fDeadDistance;
  v23 = vPosition->y + (float)(v19 * fDeadDistance);
  v24 = (float)(v18 * UFG::qVector3::msDirUp.x) - (float)(v21 * UFG::qVector3::msDirUp.z);
  v25 = v19 * UFG::qVector3::msDirUp.x;
  v26 = (float)(v19 * fMaxDistance) + vPosition->y;
  v27 = (float)(v21 * UFG::qVector3::msDirUp.y) - v25;
  v28 = v21 * fDeadDistance;
  v29 = (float)(v21 * fMaxDistance) + vPosition->x;
  v30 = vPosition->x + v28;
  v31 = vPosition->z;
  v32 = (float)(v18 * fMaxDistance) + v31;
  v33 = v31 + v22;
  v47 = v46 * 0.5;
  aVerts.x = v29 - (float)(v47 * v20);
  aVerts.z = v32 - (float)(v47 * v27);
  aVerts.y = v26 - (float)(v47 * v24);
  v35 = v30 - (float)(v17 * v20);
  v36 = v23 - (float)(v17 * v24);
  v37 = v33 - (float)(v17 * v27);
  v38 = (float)(v17 * v20) + v30;
  v39 = (float)(v17 * v24) + v23;
  v40 = (float)(v17 * v27) + v33;
  v41.x = (float)(v47 * v20) + v29;
  v41.y = (float)(v47 * v24) + v26;
  v41.z = (float)(v47 * v27) + v32;
  v42 = aVerts;
  v43 = v38;
  v44 = v39;
  v45 = v40;
  Render::View::DrawDebugPrimTri(pView, &aVerts, c, &UFG::qMatrix44::msIdentity);
  Render::View::DrawDebugPrimTri(pView, &v41, c, &UFG::qMatrix44::msIdentity);
}

