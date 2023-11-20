// File Line: 66
// RVA: 0xFD080
void __fastcall UFG::FlashlightDisplay2(UFG::qVector3 *vPosition, UFG::qVector3 *vDirection, UFG::FlashlightParams *params, Render::View *pView, UFG::qColour *c)
{
  Render::View *v5; // rbp
  UFG::FlashlightParams *v6; // rbx
  UFG::qVector3 *v7; // rdi
  UFG::qVector3 *v8; // rsi
  float v9; // xmm0_4
  float v10; // xmm15_4
  __m128 v11; // xmm14
  float v12; // xmm3_4
  float v13; // xmm5_4
  float v14; // xmm7_4
  float v15; // xmm4_4
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
  float v30; // xmm4_4
  float v31; // xmm13_4
  float v32; // xmm0_4
  float v33; // xmm4_4
  UFG::qVector3 aVerts; // [rsp+30h] [rbp-108h]
  float v35; // [rsp+3Ch] [rbp-FCh]
  float v36; // [rsp+40h] [rbp-F8h]
  float v37; // [rsp+44h] [rbp-F4h]
  float v38; // [rsp+48h] [rbp-F0h]
  float v39; // [rsp+4Ch] [rbp-ECh]
  float v40; // [rsp+50h] [rbp-E8h]
  UFG::qVector3 v41; // [rsp+58h] [rbp-E0h]
  float v42; // [rsp+64h] [rbp-D4h]
  float v43; // [rsp+68h] [rbp-D0h]
  float v44; // [rsp+6Ch] [rbp-CCh]
  float v45; // [rsp+70h] [rbp-C8h]
  float v46; // [rsp+74h] [rbp-C4h]
  float v47; // [rsp+78h] [rbp-C0h]
  float v48; // [rsp+140h] [rbp+8h]
  float v49; // [rsp+140h] [rbp+8h]
  float v50; // [rsp+150h] [rbp+18h]

  v5 = pView;
  v6 = params;
  v7 = vDirection;
  v8 = vPosition;
  v9 = tanf(params->fMaxRads);
  v10 = v7->y;
  v11 = (__m128)LODWORD(v7->x);
  v12 = 0.0;
  v13 = v7->z;
  v14 = v6->fMaxDistance;
  v15 = v6->fDeadDistance;
  v16 = v11;
  v48 = v6->fMaxDistance * v9;
  v16.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v10 * v10)) + (float)(v13 * v13);
  if ( v16.m128_f32[0] != 0.0 )
    v12 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
  v17 = (float)(v6->fDeadDistance * v9) * 0.5;
  v18 = v13 * v12;
  v19 = v10 * v12;
  v20 = (float)(v19 * UFG::qVector3::msDirUp.z) - (float)(v18 * UFG::qVector3::msDirUp.y);
  v21 = v11.m128_f32[0] * v12;
  v22 = v18 * v15;
  v23 = v8->y + (float)(v19 * v15);
  v24 = (float)(v18 * UFG::qVector3::msDirUp.x) - (float)(v21 * UFG::qVector3::msDirUp.z);
  v25 = v19 * UFG::qVector3::msDirUp.x;
  v26 = (float)(v19 * v14) + v8->y;
  v27 = (float)(v21 * UFG::qVector3::msDirUp.y) - v25;
  v28 = v21 * v15;
  v29 = (float)(v21 * v14) + v8->x;
  v30 = v48 * 0.5;
  v31 = v8->x + v28;
  v32 = v8->z;
  v49 = v30;
  v33 = v30 * v20;
  v50 = (float)(v18 * v14) + v32;
  aVerts.x = v29 - v33;
  aVerts.z = v50 - (float)(v49 * v27);
  aVerts.y = v26 - (float)(v49 * v24);
  v35 = v31 - (float)(v17 * v20);
  v36 = v23 - (float)(v17 * v24);
  v37 = (float)(v32 + v22) - (float)(v17 * v27);
  v38 = (float)(v17 * v20) + v31;
  v39 = (float)(v17 * v24) + v23;
  v40 = (float)(v17 * v27) + (float)(v32 + v22);
  v41.x = v33 + v29;
  v41.y = (float)(v49 * v24) + v26;
  v41.z = (float)(v49 * v27) + v50;
  v42 = v29 - v33;
  v43 = v26 - (float)(v49 * v24);
  v44 = v50 - (float)(v49 * v27);
  v45 = (float)(v17 * v20) + v31;
  v46 = (float)(v17 * v24) + v23;
  v47 = (float)(v17 * v27) + (float)(v32 + v22);
  Render::View::DrawDebugPrimTri(v5, &aVerts, c, &UFG::qMatrix44::msIdentity);
  Render::View::DrawDebugPrimTri(v5, &v41, c, &UFG::qMatrix44::msIdentity);
}

