// File Line: 24
// RVA: 0xFD780
UFG::qVector3 *__fastcall UFG::BoundingVolume::GetCenter(UFG::BoundingVolume *this, UFG::qVector3 *result, float t)
{
  UFG::qVector3 *v3; // rax
  float v4; // xmm2_4
  float v5; // xmm1_4

  v3 = result;
  v4 = (float)(this->mMax.y + this->mMin.y) * 0.5;
  v5 = this->mMax.z + this->mMin.z;
  result->x = (float)(this->mMax.x + this->mMin.x) * 0.5;
  result->y = v4;
  result->z = v5 * 0.5;
  return v3;
}

// File Line: 62
// RVA: 0xFD7D0
float __fastcall UFG::SphereVolume::GetClosestContact(UFG::SphereVolume *this, UFG::qVector3 *vFromPoint, UFG::qVector3 *vOutCPoint, UFG::qVector3 *vOutCNormal, float t)
{
  UFG::qVector3 *v5; // rbp
  UFG::qVector3 *v6; // rdi
  UFG::SphereVolume *v7; // rsi
  UFG::qVector3 *v8; // rbx
  float v9; // xmm10_4
  float v10; // xmm11_4
  float v11; // xmm12_4
  float v12; // xmm3_4
  __m128 v13; // xmm8
  float v14; // xmm9_4
  __m128 v15; // xmm2
  float v16; // xmm7_4
  int v17; // xmm0_4
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  __m128 v21; // xmm2
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  __m128 v25; // xmm3
  float v26; // xmm1_4
  float v28; // [rsp+20h] [rbp-88h]
  float v29; // [rsp+24h] [rbp-84h]
  float v30; // [rsp+28h] [rbp-80h]

  v5 = vOutCNormal;
  v6 = vOutCPoint;
  v7 = this;
  v8 = vFromPoint;
  ((void (__fastcall *)(UFG::SphereVolume *, float *))this->vfptr->GetCenter)(this, &v28);
  v13 = (__m128)LODWORD(v8->y);
  v9 = v28;
  v10 = v29;
  v11 = v30;
  v12 = v8->x - v28;
  v13.m128_f32[0] = v13.m128_f32[0] - v29;
  v14 = v8->z - v30;
  v15 = v13;
  v15.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v12 * v12)) + (float)(v14 * v14);
  LODWORD(v16) = (unsigned __int128)_mm_sqrt_ps(v15);
  *(float *)&v17 = v16;
  if ( v16 < 0.0 )
    v17 = LODWORD(v16) ^ _xmm[0];
  if ( *(float *)&v17 < 0.001 )
  {
    v6->x = v28;
    v6->y = v10;
    v6->z = v11;
  }
  else
  {
    v18 = (float)(1.0 / v16) * v14;
    v19 = (float)(1.0 / v16) * v12;
    v20 = (float)(1.0 / v16) * v13.m128_f32[0];
    v5->z = v18;
    v5->x = v19;
    v5->y = v20;
    v21 = (__m128)LODWORD(v7->mMax.y);
    v22 = v7->mMax.x - v7->mMin.x;
    v23 = v7->mMax.z - v7->mMin.z;
    v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] - v7->mMin.y) * (float)(v21.m128_f32[0] - v7->mMin.y))
                            + (float)(v22 * v22))
                    + (float)(v23 * v23);
    v24 = COERCE_FLOAT(_mm_sqrt_ps(v21)) * 0.5;
    v6->z = (float)(v24 * v18) + v11;
    v6->x = (float)(v24 * v19) + v9;
    v6->y = (float)(v24 * v20) + v10;
    v25 = (__m128)LODWORD(v7->mMax.y);
    v26 = v7->mMax.z - v7->mMin.z;
    v25.m128_f32[0] = (float)((float)((float)(v25.m128_f32[0] - v7->mMin.y) * (float)(v25.m128_f32[0] - v7->mMin.y))
                            + (float)((float)(v7->mMax.x - v7->mMin.x) * (float)(v7->mMax.x - v7->mMin.x)))
                    + (float)(v26 * v26);
    v16 = v16 + (float)(COERCE_FLOAT(_mm_sqrt_ps(v25)) * -0.5);
  }
  return v16;
}

