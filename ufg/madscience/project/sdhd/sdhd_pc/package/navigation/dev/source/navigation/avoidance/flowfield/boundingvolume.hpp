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
float __fastcall UFG::SphereVolume::GetClosestContact(
        UFG::SphereVolume *this,
        UFG::qVector3 *vFromPoint,
        UFG::qVector3 *vOutCPoint,
        UFG::qVector3 *vOutCNormal,
        float t)
{
  float v9; // xmm10_4
  float v10; // xmm11_4
  float v11; // xmm12_4
  float v12; // xmm3_4
  __m128 y_low; // xmm8
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
  float v28; // [rsp+20h] [rbp-88h] BYREF
  float v29; // [rsp+24h] [rbp-84h]
  float v30; // [rsp+28h] [rbp-80h]

  ((void (__fastcall *)(UFG::SphereVolume *, float *))this->vfptr->GetCenter)(this, &v28);
  y_low = (__m128)LODWORD(vFromPoint->y);
  v9 = v28;
  v10 = v29;
  v11 = v30;
  v12 = vFromPoint->x - v28;
  y_low.m128_f32[0] = y_low.m128_f32[0] - v29;
  v14 = vFromPoint->z - v30;
  v15 = y_low;
  v15.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v12 * v12)) + (float)(v14 * v14);
  v16 = _mm_sqrt_ps(v15).m128_f32[0];
  *(float *)&v17 = v16;
  if ( v16 < 0.0 )
    v17 = LODWORD(v16) ^ _xmm[0];
  if ( *(float *)&v17 < 0.001 )
  {
    vOutCPoint->x = v28;
    vOutCPoint->y = v10;
    vOutCPoint->z = v11;
  }
  else
  {
    v18 = (float)(1.0 / v16) * v14;
    v19 = (float)(1.0 / v16) * v12;
    v20 = (float)(1.0 / v16) * y_low.m128_f32[0];
    vOutCNormal->z = v18;
    vOutCNormal->x = v19;
    vOutCNormal->y = v20;
    v21 = (__m128)LODWORD(this->mMax.y);
    v22 = this->mMax.x - this->mMin.x;
    v23 = this->mMax.z - this->mMin.z;
    v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] - this->mMin.y) * (float)(v21.m128_f32[0] - this->mMin.y))
                            + (float)(v22 * v22))
                    + (float)(v23 * v23);
    v24 = _mm_sqrt_ps(v21).m128_f32[0] * 0.5;
    vOutCPoint->z = (float)(v24 * v18) + v11;
    vOutCPoint->x = (float)(v24 * v19) + v9;
    vOutCPoint->y = (float)(v24 * v20) + v10;
    v25 = (__m128)LODWORD(this->mMax.y);
    v26 = this->mMax.z - this->mMin.z;
    v25.m128_f32[0] = (float)((float)((float)(v25.m128_f32[0] - this->mMin.y) * (float)(v25.m128_f32[0] - this->mMin.y))
                            + (float)((float)(this->mMax.x - this->mMin.x) * (float)(this->mMax.x - this->mMin.x)))
                    + (float)(v26 * v26);
    return v16 + (float)(_mm_sqrt_ps(v25).m128_f32[0] * -0.5);
  }
  return v16;
}

