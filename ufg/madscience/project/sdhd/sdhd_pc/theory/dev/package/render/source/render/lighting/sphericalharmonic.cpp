// File Line: 27
// RVA: 0x28BA0
void __fastcall Render::SphericalHarmonic::SphericalHarmonic(Render::SphericalHarmonic *this)
{
  Render::SphericalHarmonic *v1; // rbx

  v1 = this;
  UFG::qMemSet(this, 0, 0x24u);
  UFG::qMemSet(v1->mGreenCoefficients, 0, 0x24u);
  UFG::qMemSet(v1->mBlueCoefficients, 0, 0x24u);
  v1->mNumHelperLights = 0;
}

// File Line: 61
// RVA: 0x28BF0
void __fastcall Render::SphericalHarmonic::ComputeIrradianceConstants(Render::SphericalHarmonic *this, float *irr_const0, float *irr_const, const float *sh_coeffs)
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
  float v5; // xmm5_4
  float v6; // xmm9_4
  float v7; // xmm3_4
  float v8; // xmm6_4
  float v9; // xmm14_4
  float v10; // xmm13_4
  float v11; // xmm12_4
  float v12; // xmm8_4
  float v13; // xmm15_4
  float v14; // xmm11_4
  float v15; // xmm12_4
  float v16; // xmm11_4
  float v17; // xmm6_4
  float v18; // [rsp+0h] [rbp-D8h]
  float v19; // [rsp+4h] [rbp-D4h]
  float v20; // [rsp+8h] [rbp-D0h]
  float v21; // [rsp+Ch] [rbp-CCh]
  float v22; // [rsp+10h] [rbp-C8h]
  float v23; // [rsp+14h] [rbp-C4h]
  float v24; // [rsp+18h] [rbp-C0h]
  float v25; // [rsp+1Ch] [rbp-BCh]
  float v26; // [rsp+20h] [rbp-B8h]
  float v27; // [rsp+E0h] [rbp+8h]
  float v28; // [rsp+E8h] [rbp+10h]
  float v29; // [rsp+F0h] [rbp+18h]
  float v30; // [rsp+F8h] [rbp+20h]
  float za; // [rsp+100h] [rbp+28h]

  v5 = z;
  v6 = y;
  v7 = y * z;
  v8 = x * x;
  v25 = x * v6;
  v27 = (float)((float)(v6 * v6) - (float)((float)(x * x) * 3.0)) * v6;
  v9 = v5 * v5;
  v10 = (float)(v5 * v5) * 5.0;
  v11 = (float)(v5 * v5) * 7.0;
  v19 = (float)((float)((float)(v6 * v6) * 3.0) - (float)(x * x)) * x;
  v29 = v7 * x;
  za = (float)(v6 - x) * (float)(x + v6);
  v18 = (float)(v5 * v5) * (float)(v5 * v5);
  v20 = (float)((float)((float)(v6 * v6) - v8) - (float)(v25 * 2.0))
      * (float)((float)(v25 * 2.0) + (float)((float)(v6 * v6) - v8));
  v30 = za * v5;
  v12 = x * 1.0925485;
  v21 = v5 * 1.7701308;
  v13 = (float)(0.45294666 - (float)((float)(v5 * v5) * 6.3412533)) + (float)(v18 * 9.5118799);
  v14 = (float)(v11 - 3.0) * 0.66904652;
  *shOut = 0.28209481;
  v15 = v11 - 1.0;
  v16 = v14 * v5;
  v24 = (float)((float)((float)(v5 * 3.0) + 1.0) * 0.48923829) * (float)((float)(v5 * 3.0) - 1.0);
  v22 = (float)(v6 * v6) * (float)(v6 * v6);
  v28 = v8 * v8;
  v17 = (float)((float)(x * x) * -10.0) * (float)(v6 * v6);
  v26 = (float)((float)(v5 * v5) * 3.0) - 1.0;
  if ( order > 1 )
  {
    shOut[1] = v6 * -0.48860252;
    shOut[3] = x * -0.48860252;
    shOut[2] = v5 * 0.48860252;
    if ( order > 2 )
    {
      shOut[5] = v7 * -1.0925485;
      *((_DWORD *)shOut + 7) = COERCE_UNSIGNED_INT(v12 * v5) ^ _xmm[0];
      shOut[4] = v12 * v6;
      shOut[6] = (float)(v9 * 0.94617468) - 0.31539157;
      shOut[8] = za * -0.54627424;
      if ( order > 3 )
      {
        *((_DWORD *)shOut + 13) = COERCE_UNSIGNED_INT((float)((float)(v10 * 0.45704579) - 0.45704579) * x) ^ _xmm[0];
        *((_DWORD *)shOut + 11) = COERCE_UNSIGNED_INT((float)((float)(v10 * 0.45704579) - 0.45704579) * v6) ^ _xmm[0];
        shOut[9] = v27 * 0.5900436;
        shOut[10] = v29 * 2.8906114;
        shOut[12] = (float)(v10 - 3.0) * (float)(v5 * 0.37317634);
        shOut[14] = v30 * -1.4453057;
        shOut[15] = v19 * 0.5900436;
        if ( order > 4 )
        {
          shOut[23] = v21 * v19;
          v23 = za * (float)(x * v6);
          shOut[16] = v23 * -2.5033429;
          shOut[17] = v21 * v27;
          shOut[22] = (float)(v15 * -0.47308734) * za;
          *((_DWORD *)shOut + 19) = COERCE_UNSIGNED_INT(v16 * v6) ^ _xmm[0];
          shOut[18] = (float)(v15 * 0.94617468) * v25;
          *((_DWORD *)shOut + 21) = COERCE_UNSIGNED_INT(v16 * x) ^ _xmm[0];
          shOut[20] = (float)(0.31735665 - (float)(v9 * 3.1735663)) + (float)(v18 * 3.7024941);
          shOut[24] = v20 * 0.62583572;
          if ( order > 5 )
          {
            shOut[25] = (float)((float)((float)(v28 * 5.0) + v17) + v22) * (float)(v6 * -0.65638208);
            shOut[26] = (float)(v5 * -8.3026495) * v23;
            shOut[33] = v24 * v19;
            shOut[27] = v24 * v27;
            shOut[28] = (float)(v26 * 4.7935367) * v29;
            shOut[32] = (float)(v26 * -2.3967683) * v30;
            *((_DWORD *)shOut + 29) = COERCE_UNSIGNED_INT(v13 * v6) ^ _xmm[0];
            shOut[35] = (float)((float)(v17 + v28) + (float)(v22 * 5.0)) * (float)(x * -0.65638208);
            *((_DWORD *)shOut + 31) = COERCE_UNSIGNED_INT(v13 * x) ^ _xmm[0];
            shOut[30] = (float)((float)(15.0 - (float)(v9 * 70.0)) + (float)(v18 * 63.0)) * (float)(v5 * 0.11695033);
            shOut[34] = (float)(v5 * 2.0756624) * v20;
          }
        }
      }
    }
  }
}

// File Line: 193
// RVA: 0x28CD0
void __fastcall Render::SphericalHarmonic::EvalDirectionalLight(Render::SphericalHarmonic *this, UFG::qVector3 *direction, UFG::qColour *colour)
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
  float shOut; // [rsp+30h] [rbp-38h]
  float v15; // [rsp+34h] [rbp-34h]
  float v16; // [rsp+38h] [rbp-30h]
  float v17; // [rsp+3Ch] [rbp-2Ch]
  float v18; // [rsp+40h] [rbp-28h]
  float v19; // [rsp+44h] [rbp-24h]
  float v20; // [rsp+48h] [rbp-20h]
  float v21; // [rsp+4Ch] [rbp-1Ch]
  float v22; // [rsp+50h] [rbp-18h]

  SHEvalDirection(3, &shOut, direction->x, direction->y, direction->z);
  v3 = shOut;
  v4 = v15;
  v5 = v16;
  *v7 = (float)(shOut * *v6) + *v7;
  v7[9] = (float)(v3 * v6[1]) + v7[9];
  v7[18] = (float)(v3 * v6[2]) + v7[18];
  v7[1] = (float)(v4 * *v6) + v7[1];
  v7[10] = (float)(v4 * v6[1]) + v7[10];
  v7[19] = (float)(v4 * v6[2]) + v7[19];
  v8 = v17;
  v7[2] = (float)(v5 * *v6) + v7[2];
  v7[11] = (float)(v5 * v6[1]) + v7[11];
  v7[20] = (float)(v5 * v6[2]) + v7[20];
  v9 = v18;
  v7[3] = (float)(v8 * *v6) + v7[3];
  v7[12] = (float)(v8 * v6[1]) + v7[12];
  v7[21] = (float)(v8 * v6[2]) + v7[21];
  v10 = v19;
  v7[4] = (float)(v9 * *v6) + v7[4];
  v7[13] = (float)(v9 * v6[1]) + v7[13];
  v7[22] = (float)(v9 * v6[2]) + v7[22];
  v11 = v20;
  v7[5] = (float)(v10 * *v6) + v7[5];
  v7[14] = (float)(v10 * v6[1]) + v7[14];
  v7[23] = (float)(v10 * v6[2]) + v7[23];
  v12 = v21;
  v7[6] = (float)(v11 * *v6) + v7[6];
  v7[15] = (float)(v11 * v6[1]) + v7[15];
  v7[24] = (float)(v11 * v6[2]) + v7[24];
  v13 = v22;
  v7[7] = (float)(v12 * *v6) + v7[7];
  v7[16] = (float)(v12 * v6[1]) + v7[16];
  v7[25] = (float)(v12 * v6[2]) + v7[25];
  v7[8] = (float)(v13 * *v6) + v7[8];
  v7[17] = (float)(v13 * v6[1]) + v7[17];
  v7[26] = (float)(v13 * v6[2]) + v7[26];
}

