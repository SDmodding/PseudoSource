// File Line: 24
// RVA: 0x9900F0
void __fastcall Scaleform::Render::ScreenToWorld::GetWorldPoint(Scaleform::Render::ScreenToWorld *this, Scaleform::Render::Point<float> *ptOut)
{
  Scaleform::Render::Point<float> *v2; // rbx
  float v3; // xmm1_4
  Scaleform::Render::Point3<float> ptOuta; // [rsp+20h] [rbp-18h]

  v2 = ptOut;
  Scaleform::Render::ScreenToWorld::GetWorldPoint(this, &ptOuta);
  v3 = ptOuta.y;
  v2->x = ptOuta.x;
  v2->y = v3;
}

// File Line: 32
// RVA: 0x98FC40
void __fastcall Scaleform::Render::ScreenToWorld::GetWorldPoint(Scaleform::Render::ScreenToWorld *this, Scaleform::Render::Point3<float> *ptOut)
{
  Scaleform::Render::Point3<float> *v2; // r15
  Scaleform::Render::ScreenToWorld *v3; // r14
  Scaleform::Render::Matrix4x4<float> *v4; // rbx
  float v5; // xmm4_4
  float v6; // xmm8_4
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm12_4
  float v11; // xmm15_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm10_4
  float v15; // xmm9_4
  float w; // xmm4_4
  float v17; // xmm4_4
  float v18; // xmm10_4
  float v19; // xmm2_4
  float v20; // xmm9_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  Scaleform::Render::Matrix3x4<float> v23; // [rsp+40h] [rbp-A8h]
  float v24; // [rsp+70h] [rbp-78h]
  float v25; // [rsp+74h] [rbp-74h]
  float v26; // [rsp+78h] [rbp-70h]
  float v27; // [rsp+7Ch] [rbp-6Ch]
  float po; // [rsp+80h] [rbp-68h]
  float v29; // [rsp+84h] [rbp-64h]
  float v30; // [rsp+88h] [rbp-60h]
  float v31; // [rsp+8Ch] [rbp-5Ch]
  Scaleform::Render::Matrix4x4<float> result; // [rsp+98h] [rbp-50h]
  float v33; // [rsp+1A8h] [rbp+C0h]
  float retaddr; // [rsp+1B8h] [rbp+D0h]
  float v35; // [rsp+1C0h] [rbp+D8h]

  v2 = ptOut;
  v3 = this;
  if ( 3.4028235e38 != this->Sx && 3.4028235e38 != this->Sy )
  {
    Scaleform::Render::Matrix4x4<float>::SetInverse(&this->MatInvProj, &this->MatProj);
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v23, &v3->MatView, &v3->MatWorld);
    v24 = *(float *)&_xmm;
    LODWORD(v26) = (unsigned __int128)_mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 170);
    v27 = *((float *)&_xmm + 3);
    LODWORD(v25) = (unsigned __int128)_mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 85);
    v4 = Scaleform::Render::Matrix4x4<float>::GetInverse((Scaleform::Render::Matrix4x4<float> *)&v23, &result);
    v5 = (float)(v3->MatProj.M[3][1] + v3->MatProj.M[3][0]) * 0.0;
    v6 = (float)(v3->MatProj.M[2][1] + v3->MatProj.M[2][0]) * 0.0;
    v7 = v3->MatProj.M[2][2];
    v8 = v3->MatProj.M[3][2];
    v9 = v4->M[3][1];
    v10 = v4->M[0][2];
    v11 = v4->M[1][2];
    v33 = v4->M[1][0];
    v12 = v4->M[2][1];
    v25 = v9;
    retaddr = v12;
    v13 = v4->M[3][0];
    v27 = v4->M[3][3];
    v24 = v13;
    v26 = v4->M[3][2];
    v14 = (float)(v6 - (float)(v7 * 100.0)) + v3->MatProj.M[2][3];
    v15 = (float)(v5 - (float)(v8 * 100.0)) + v3->MatProj.M[3][3];
    w = (float)(v5 - (float)(v8 * 0.5)) + v3->MatProj.M[3][3];
    Scaleform::Render::ScreenToWorld::VectorMult(
      v3,
      &po,
      (const float *)&v3->MatInvProj,
      w * v3->Sx,
      w * v3->Sy,
      w * (float)((float)(v6 - (float)(v7 * 0.5)) + v3->MatProj.M[2][3]),
      w);
    Scaleform::Render::ScreenToWorld::VectorMult(
      v3,
      &v24,
      (const float *)&v3->MatInvProj,
      v15 * v3->Sx,
      v15 * v3->Sy,
      v15 * v14,
      v15);
    v17 = (float)(v30 * v31) * v4->M[2][2];
    v35 = (float)((float)((float)(v4->M[0][1] * (float)(v29 * v31)) + (float)((float)(po * v31) * v4->M[0][0]))
                + (float)(v10 * (float)(v30 * v31)))
        + v4->M[0][3];
    v23.M[2][2] = (float)((float)((float)(v33 * (float)(po * v31)) + (float)((float)(v29 * v31) * v4->M[1][1]))
                        + (float)(v11 * (float)(v30 * v31)))
                + v4->M[1][3];
    v18 = (float)((float)((float)(retaddr * (float)(v29 * v31)) + (float)(v4->M[2][0] * (float)(po * v31))) + v17)
        + v4->M[2][3];
    v19 = 0.0;
    v20 = (float)((float)((float)((float)(retaddr * (float)(v25 * v27)) + (float)(v4->M[2][0] * (float)(v24 * v27)))
                        + (float)((float)(v26 * v27) * v4->M[2][2]))
                + v4->M[2][3])
        - v18;
    if ( v20 != 0.0 )
      LODWORD(v19) = COERCE_UNSIGNED_INT(v18 / v20) ^ _xmm[0];
    v21 = (float)(v19
                * (float)((float)((float)((float)((float)(v4->M[0][1] * (float)(v25 * v27))
                                                + (float)((float)(v24 * v27) * v4->M[0][0]))
                                        + (float)(v10 * (float)(v26 * v27)))
                                + v4->M[0][3])
                        - v35))
        + v35;
    v22 = (float)(v19
                * (float)((float)((float)((float)((float)(v33 * (float)(v24 * v27))
                                                + (float)((float)(v25 * v27) * v4->M[1][1]))
                                        + (float)(v11 * (float)(v26 * v27)))
                                + v4->M[1][3])
                        - v23.M[2][2]))
        + v23.M[2][2];
    v2->x = v21;
    v3->LastX = v21;
    v2->y = v22;
    v3->LastY = v22;
    v2->z = (float)(v19 * v20) + v18;
  }
}

// File Line: 85
// RVA: 0x9C1840
void __fastcall Scaleform::Render::ScreenToWorld::VectorMult(Scaleform::Render::ScreenToWorld *this, float *po, const float *pa, float x, float y, float z, float w)
{
  *po = (float)((float)((float)(y * pa[1]) + (float)(x * *pa)) + (float)(z * pa[2])) + (float)(w * pa[3]);
  po[1] = (float)((float)((float)(x * pa[4]) + (float)(y * pa[5])) + (float)(z * pa[6])) + (float)(w * pa[7]);
  po[2] = (float)((float)((float)(x * pa[8]) + (float)(y * pa[9])) + (float)(z * pa[10])) + (float)(w * pa[11]);
  po[3] = (float)((float)((float)(x * pa[12]) + (float)(y * pa[13])) + (float)(z * pa[14])) + (float)(w * pa[15]);
}

