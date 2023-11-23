// File Line: 24
// RVA: 0x9900F0
void __fastcall Scaleform::Render::ScreenToWorld::GetWorldPoint(
        Scaleform::Render::ScreenToWorld *this,
        Scaleform::Render::Point<float> *ptOut)
{
  float y; // xmm1_4
  Scaleform::Render::Point3<float> ptOuta; // [rsp+20h] [rbp-18h] BYREF

  Scaleform::Render::ScreenToWorld::GetWorldPoint(this, &ptOuta);
  y = ptOuta.y;
  ptOut->x = ptOuta.x;
  ptOut->y = y;
}

// File Line: 32
// RVA: 0x98FC40
void __fastcall Scaleform::Render::ScreenToWorld::GetWorldPoint(
        Scaleform::Render::ScreenToWorld *this,
        Scaleform::Render::Point3<float> *ptOut)
{
  Scaleform::Render::Matrix4x4<float> *Inverse; // rbx
  float v5; // xmm4_4
  float v6; // xmm8_4
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm12_4
  float v11; // xmm15_4
  float v12; // xmm0_4
  float v13; // xmm10_4
  float v14; // xmm9_4
  float w; // xmm4_4
  float v16; // xmm4_4
  float v17; // xmm10_4
  float v18; // xmm2_4
  float v19; // xmm9_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  Scaleform::Render::Matrix4x4<float> v22; // [rsp+40h] [rbp-A8h] BYREF
  float po; // [rsp+80h] [rbp-68h] BYREF
  float v24; // [rsp+84h] [rbp-64h]
  float v25; // [rsp+88h] [rbp-60h]
  float v26; // [rsp+8Ch] [rbp-5Ch]
  Scaleform::Render::Matrix4x4<float> result; // [rsp+98h] [rbp-50h] BYREF
  float v28; // [rsp+1A8h] [rbp+C0h]
  void *retaddr; // [rsp+1B8h] [rbp+D0h]
  float v30; // [rsp+1C0h] [rbp+D8h]

  if ( 3.4028235e38 != this->Sx && 3.4028235e38 != this->Sy )
  {
    Scaleform::Render::Matrix4x4<float>::SetInverse(&this->MatInvProj, &this->MatProj);
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
      (Scaleform::Render::Matrix3x4<float> *)&v22,
      &this->MatView,
      &this->MatWorld);
    LODWORD(v22.M[3][0]) = _xmm;
    LODWORD(v22.M[3][2]) = _mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 170).m128_u32[0];
    v22.M[3][3] = *((float *)&_xmm + 3);
    LODWORD(v22.M[3][1]) = _mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 85).m128_u32[0];
    Inverse = Scaleform::Render::Matrix4x4<float>::GetInverse(&v22, &result);
    v5 = (float)(this->MatProj.M[3][1] + this->MatProj.M[3][0]) * 0.0;
    v6 = (float)(this->MatProj.M[2][1] + this->MatProj.M[2][0]) * 0.0;
    v7 = this->MatProj.M[2][2];
    v8 = this->MatProj.M[3][2];
    v9 = Inverse->M[3][1];
    v10 = Inverse->M[0][2];
    v11 = Inverse->M[1][2];
    v28 = Inverse->M[1][0];
    *(float *)&retaddr = Inverse->M[2][1];
    v12 = Inverse->M[3][0];
    v22.M[3][3] = Inverse->M[3][3];
    *(_QWORD *)&v22.M[3][0] = __PAIR64__(LODWORD(v9), LODWORD(v12));
    v22.M[3][2] = Inverse->M[3][2];
    v13 = (float)(v6 - (float)(v7 * 100.0)) + this->MatProj.M[2][3];
    v14 = (float)(v5 - (float)(v8 * 100.0)) + this->MatProj.M[3][3];
    w = (float)(v5 - (float)(v8 * 0.5)) + this->MatProj.M[3][3];
    Scaleform::Render::ScreenToWorld::VectorMult(
      this,
      &po,
      (const float *)&this->MatInvProj,
      w * this->Sx,
      w * this->Sy,
      w * (float)((float)(v6 - (float)(v7 * 0.5)) + this->MatProj.M[2][3]),
      w);
    Scaleform::Render::ScreenToWorld::VectorMult(
      this,
      v22.M[3],
      (const float *)&this->MatInvProj,
      v14 * this->Sx,
      v14 * this->Sy,
      v14 * v13,
      v14);
    v16 = (float)(v25 * v26) * Inverse->M[2][2];
    v30 = (float)((float)((float)(Inverse->M[0][1] * (float)(v24 * v26)) + (float)((float)(po * v26) * Inverse->M[0][0]))
                + (float)(v10 * (float)(v25 * v26)))
        + Inverse->M[0][3];
    v22.M[2][2] = (float)((float)((float)(v28 * (float)(po * v26)) + (float)((float)(v24 * v26) * Inverse->M[1][1]))
                        + (float)(v11 * (float)(v25 * v26)))
                + Inverse->M[1][3];
    v17 = (float)((float)((float)(*(float *)&retaddr * (float)(v24 * v26))
                        + (float)(Inverse->M[2][0] * (float)(po * v26)))
                + v16)
        + Inverse->M[2][3];
    v18 = 0.0;
    v19 = (float)((float)((float)((float)(*(float *)&retaddr * (float)(v22.M[3][1] * v22.M[3][3]))
                                + (float)(Inverse->M[2][0] * (float)(v22.M[3][0] * v22.M[3][3])))
                        + (float)((float)(v22.M[3][2] * v22.M[3][3]) * Inverse->M[2][2]))
                + Inverse->M[2][3])
        - v17;
    if ( v19 != 0.0 )
      LODWORD(v18) = COERCE_UNSIGNED_INT(v17 / v19) ^ _xmm[0];
    v20 = (float)(v18
                * (float)((float)((float)((float)((float)(Inverse->M[0][1] * (float)(v22.M[3][1] * v22.M[3][3]))
                                                + (float)((float)(v22.M[3][0] * v22.M[3][3]) * Inverse->M[0][0]))
                                        + (float)(v10 * (float)(v22.M[3][2] * v22.M[3][3])))
                                + Inverse->M[0][3])
                        - v30))
        + v30;
    v21 = (float)(v18
                * (float)((float)((float)((float)((float)(v28 * (float)(v22.M[3][0] * v22.M[3][3]))
                                                + (float)((float)(v22.M[3][1] * v22.M[3][3]) * Inverse->M[1][1]))
                                        + (float)(v11 * (float)(v22.M[3][2] * v22.M[3][3])))
                                + Inverse->M[1][3])
                        - v22.M[2][2]))
        + v22.M[2][2];
    ptOut->x = v20;
    this->LastX = v20;
    ptOut->y = v21;
    this->LastY = v21;
    ptOut->z = (float)(v18 * v19) + v17;
  }
}

// File Line: 85
// RVA: 0x9C1840
void __fastcall Scaleform::Render::ScreenToWorld::VectorMult(
        Scaleform::Render::ScreenToWorld *this,
        float *po,
        const float *pa,
        float x,
        float y,
        float z,
        float w)
{
  *po = (float)((float)((float)(y * pa[1]) + (float)(x * *pa)) + (float)(z * pa[2])) + (float)(w * pa[3]);
  po[1] = (float)((float)((float)(x * pa[4]) + (float)(y * pa[5])) + (float)(z * pa[6])) + (float)(w * pa[7]);
  po[2] = (float)((float)((float)(x * pa[8]) + (float)(y * pa[9])) + (float)(z * pa[10])) + (float)(w * pa[11]);
  po[3] = (float)((float)((float)(x * pa[12]) + (float)(y * pa[13])) + (float)(z * pa[14])) + (float)(w * pa[15]);
}

