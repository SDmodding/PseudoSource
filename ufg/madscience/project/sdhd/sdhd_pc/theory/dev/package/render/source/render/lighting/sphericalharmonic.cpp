// File Line: 27
// RVA: 0x28BA0
void __fastcall Render::SphericalHarmonic::SphericalHarmonic(Render::SphericalHarmonic *this)
{
  UFG::qMemSet(this, 0, 0x24u);
  UFG::qMemSet(this->mGreenCoefficients, 0, 0x24u);
  UFG::qMemSet(this->mBlueCoefficients, 0, 0x24u);
  this->mNumHelperLights = 0;
}

// File Line: 61
// RVA: 0x28BF0
void __fastcall Render::SphericalHarmonic::ComputeIrradianceConstants(
        Render::SphericalHarmonic *this,
        float *irr_const0,
        float *irr_const,
        const float *sh_coeffs)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm1_4

  *irr_const0 = (float)(*sh_coeffs * 0.88622701) - (float)(sh_coeffs[6] * 0.24770799);
  *irr_const = sh_coeffs[8] * 0.42904299;
  irr_const[1] = sh_coeffs[8] * -0.42904299;
  v4 = sh_coeffs[6];
  irr_const[3] = 0.0;
  irr_const[2] = v4 * 0.74312502;
  irr_const[4] = sh_coeffs[4] * 0.85808599;
  irr_const[5] = sh_coeffs[7] * 0.85808599;
  v5 = sh_coeffs[5];
  irr_const[7] = 0.0;
  irr_const[6] = v5 * 0.85808599;
  irr_const[8] = sh_coeffs[3] * 1.0233279;
  irr_const[9] = sh_coeffs[1] * 1.0233279;
  v6 = sh_coeffs[2];
  irr_const[11] = 0.0;
  irr_const[10] = v6 * 1.0233279;
}

// File Line: 90
// RVA: 0x28F50
void __fastcall SHEvalDirection(int order, float *shOut, float x, float y, float z)
{
  float v7; // xmm3_4
  float v8; // xmm14_4
  float v9; // xmm13_4
  float v10; // xmm12_4
  float v11; // xmm8_4
  float v12; // xmm15_4
  float v13; // xmm11_4
  float v14; // xmm12_4
  float v15; // xmm11_4
  float v16; // xmm6_4
  float v17; // [rsp+0h] [rbp-D8h]
  float v18; // [rsp+4h] [rbp-D4h]
  float v19; // [rsp+8h] [rbp-D0h]
  float v20; // [rsp+Ch] [rbp-CCh]
  float v21; // [rsp+10h] [rbp-C8h]
  float v22; // [rsp+14h] [rbp-C4h]
  float v23; // [rsp+18h] [rbp-C0h]
  float v24; // [rsp+20h] [rbp-B8h]
  float v25; // [rsp+E0h] [rbp+8h]
  float v26; // [rsp+E8h] [rbp+10h]
  float v27; // [rsp+F0h] [rbp+18h]
  float v28; // [rsp+F8h] [rbp+20h]
  float za; // [rsp+100h] [rbp+28h]

  v7 = y * z;
  v25 = (float)((float)(y * y) - (float)((float)(x * x) * 3.0)) * y;
  v8 = z * z;
  v9 = (float)(z * z) * 5.0;
  v10 = (float)(z * z) * 7.0;
  v18 = (float)((float)((float)(y * y) * 3.0) - (float)(x * x)) * x;
  v27 = v7 * x;
  za = (float)(y - x) * (float)(x + y);
  v17 = (float)(z * z) * (float)(z * z);
  v19 = (float)((float)((float)(y * y) - (float)(x * x)) - (float)((float)(x * y) * 2.0))
      * (float)((float)((float)(x * y) * 2.0) + (float)((float)(y * y) - (float)(x * x)));
  v28 = za * z;
  v11 = x * 1.0925485;
  v20 = z * 1.7701308;
  v12 = (float)(0.45294666 - (float)((float)(z * z) * 6.3412533)) + (float)(v17 * 9.5118799);
  v13 = (float)(v10 - 3.0) * 0.66904652;
  *shOut = 0.28209481;
  v14 = v10 - 1.0;
  v15 = v13 * z;
  v23 = (float)((float)((float)(z * 3.0) + 1.0) * 0.48923829) * (float)((float)(z * 3.0) - 1.0);
  v21 = (float)(y * y) * (float)(y * y);
  v26 = (float)(x * x) * (float)(x * x);
  v16 = (float)((float)(x * x) * -10.0) * (float)(y * y);
  v24 = (float)((float)(z * z) * 3.0) - 1.0;
  if ( order > 1 )
  {
    shOut[1] = y * -0.48860252;
    shOut[3] = x * -0.48860252;
    shOut[2] = z * 0.48860252;
    if ( order > 2 )
    {
      shOut[5] = v7 * -1.0925485;
      *((_DWORD *)shOut + 7) = COERCE_UNSIGNED_INT(v11 * z) ^ _xmm[0];
      shOut[4] = v11 * y;
      shOut[6] = (float)(v8 * 0.94617468) - 0.31539157;
      shOut[8] = za * -0.54627424;
      if ( order > 3 )
      {
        *((_DWORD *)shOut + 13) = COERCE_UNSIGNED_INT((float)((float)(v9 * 0.45704579) - 0.45704579) * x) ^ _xmm[0];
        *((_DWORD *)shOut + 11) = COERCE_UNSIGNED_INT((float)((float)(v9 * 0.45704579) - 0.45704579) * y) ^ _xmm[0];
        shOut[9] = v25 * 0.5900436;
        shOut[10] = v27 * 2.8906114;
        shOut[12] = (float)(v9 - 3.0) * (float)(z * 0.37317634);
        shOut[14] = v28 * -1.4453057;
        shOut[15] = v18 * 0.5900436;
        if ( order > 4 )
        {
          shOut[23] = v20 * v18;
          v22 = (float)((float)(y - x) * (float)(x + y)) * (float)(x * y);
          shOut[16] = v22 * -2.5033429;
          shOut[17] = v20 * v25;
          shOut[22] = (float)(v14 * -0.47308734) * za;
          *((_DWORD *)shOut + 19) = COERCE_UNSIGNED_INT(v15 * y) ^ _xmm[0];
          shOut[18] = (float)(v14 * 0.94617468) * (float)(x * y);
          *((_DWORD *)shOut + 21) = COERCE_UNSIGNED_INT(v15 * x) ^ _xmm[0];
          shOut[20] = (float)(0.31735665 - (float)(v8 * 3.1735663)) + (float)(v17 * 3.7024941);
          shOut[24] = v19 * 0.62583572;
          if ( order > 5 )
          {
            shOut[25] = (float)((float)((float)(v26 * 5.0) + v16) + v21) * (float)(y * -0.65638208);
            shOut[26] = (float)(z * -8.3026495) * v22;
            shOut[33] = v23 * v18;
            shOut[27] = v23 * v25;
            shOut[28] = (float)(v24 * 4.7935367) * v27;
            shOut[32] = (float)(v24 * -2.3967683) * v28;
            *((_DWORD *)shOut + 29) = COERCE_UNSIGNED_INT(v12 * y) ^ _xmm[0];
            shOut[35] = (float)((float)(v16 + v26) + (float)(v21 * 5.0)) * (float)(x * -0.65638208);
            *((_DWORD *)shOut + 31) = COERCE_UNSIGNED_INT(v12 * x) ^ _xmm[0];
            shOut[30] = (float)((float)(15.0 - (float)(v8 * 70.0)) + (float)(v17 * 63.0)) * (float)(z * 0.11695033);
            shOut[34] = (float)(z * 2.0756624) * v19;
          }
        }
      }
    }
  }
}

// File Line: 193
// RVA: 0x28CD0
void __fastcall Render::SphericalHarmonic::EvalDirectionalLight(
        Render::SphericalHarmonic *this,
        UFG::qVector3 *direction,
        UFG::qColour *colour)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float *v6; // r8
  float *v7; // r9
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float shOut[14]; // [rsp+30h] [rbp-38h] BYREF

  SHEvalDirection(3, shOut, direction->x, direction->y, direction->z);
  v3 = shOut[0];
  v4 = shOut[1];
  v5 = shOut[2];
  *v7 = (float)(shOut[0] * *v6) + *v7;
  v7[9] = (float)(v3 * v6[1]) + v7[9];
  v7[18] = (float)(v3 * v6[2]) + v7[18];
  v7[1] = (float)(v4 * *v6) + v7[1];
  v7[10] = (float)(v4 * v6[1]) + v7[10];
  v7[19] = (float)(v4 * v6[2]) + v7[19];
  v8 = shOut[3];
  v7[2] = (float)(v5 * *v6) + v7[2];
  v7[11] = (float)(v5 * v6[1]) + v7[11];
  v7[20] = (float)(v5 * v6[2]) + v7[20];
  v9 = shOut[4];
  v7[3] = (float)(v8 * *v6) + v7[3];
  v7[12] = (float)(v8 * v6[1]) + v7[12];
  v7[21] = (float)(v8 * v6[2]) + v7[21];
  v10 = shOut[5];
  v7[4] = (float)(v9 * *v6) + v7[4];
  v7[13] = (float)(v9 * v6[1]) + v7[13];
  v7[22] = (float)(v9 * v6[2]) + v7[22];
  v11 = shOut[6];
  v7[5] = (float)(v10 * *v6) + v7[5];
  v7[14] = (float)(v10 * v6[1]) + v7[14];
  v7[23] = (float)(v10 * v6[2]) + v7[23];
  v12 = shOut[7];
  v7[6] = (float)(v11 * *v6) + v7[6];
  v7[15] = (float)(v11 * v6[1]) + v7[15];
  v7[24] = (float)(v11 * v6[2]) + v7[24];
  v13 = shOut[8];
  v7[7] = (float)(v12 * *v6) + v7[7];
  v7[16] = (float)(v12 * v6[1]) + v7[16];
  v7[25] = (float)(v12 * v6[2]) + v7[25];
  v7[8] = (float)(v13 * *v6) + v7[8];
  v7[17] = (float)(v13 * v6[1]) + v7[17];
  v7[26] = (float)(v13 * v6[2]) + v7[26];
}

