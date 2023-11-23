// File Line: 70
// RVA: 0x20A870
void __fastcall UFG::Editor::Primitive::FlatArrowFilled(
        UFG::Editor::DrawInterface *di,
        UFG::qVector3 *a,
        UFG::qVector3 *b,
        float halfWidth)
{
  float y; // xmm13_4
  float z; // xmm14_4
  __m128 y_low; // xmm4
  float v9; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm6_4
  __m128 v12; // xmm1
  float v13; // xmm7_4
  float v14; // xmm2_4
  float v15; // xmm7_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm15_4
  float v20; // xmm7_4
  float v21; // xmm0_4
  float v22; // xmm10_4
  float v23; // xmm6_4
  float v24; // xmm9_4
  float v25; // xmm10_4
  UFG::Editor::DrawInterfaceVtbl *vfptr; // rax
  UFG::Editor::DrawInterfaceVtbl *v27; // rax
  float v28; // xmm1_4
  float v29; // xmm0_4
  float x; // [rsp+30h] [rbp-C8h] BYREF
  float v31; // [rsp+34h] [rbp-C4h]
  float v32; // [rsp+38h] [rbp-C0h]
  float v33; // [rsp+3Ch] [rbp-BCh]
  float v34; // [rsp+40h] [rbp-B8h]
  float v35; // [rsp+44h] [rbp-B4h]
  float v36; // [rsp+48h] [rbp-B0h]
  float v37; // [rsp+4Ch] [rbp-ACh]
  float v38; // [rsp+50h] [rbp-A8h]
  float v39; // [rsp+108h] [rbp+10h]

  y_low = (__m128)LODWORD(b->y);
  y = a->y;
  z = a->z;
  y_low.m128_f32[0] = y_low.m128_f32[0] - y;
  v9 = b->x - a->x;
  v10 = b->z - z;
  v11 = halfWidth;
  v12 = y_low;
  v12.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v9 * v9)) + (float)(v10 * v10);
  v13 = _mm_sqrt_ps(v12).m128_f32[0];
  if ( v13 >= 0.000099999997 )
  {
    if ( halfWidth < 0.0 )
      v11 = v13 * 0.039999999;
    if ( v13 >= (float)(v11 * 4.0) )
    {
      v14 = 1.0 / v13;
      v15 = v13 - (float)(v11 * 4.0);
      v16 = v14 * y_low.m128_f32[0];
      LODWORD(v17) = y_low.m128_i32[0] ^ _xmm[0];
      v18 = (float)(v15 * v16) + y;
      v19 = (float)(v15 * (float)(v14 * v9)) + a->x;
      v20 = (float)(v15 * (float)(v14 * v10)) + z;
      v21 = (float)(v17 * v17) + (float)(v9 * v9);
      v39 = v18;
      if ( v21 <= 0.000099999997 )
      {
        v24 = v11;
        v25 = 0.0;
        v23 = 0.0;
      }
      else
      {
        v22 = v11 / fsqrt(v21);
        v23 = v22 * 0.0;
        v24 = v22 * v17;
        v25 = v22 * v9;
      }
      vfptr = di->vfptr;
      x = a->x;
      v31 = y;
      v32 = z;
      v33 = v19;
      v34 = v18;
      v35 = v20;
      vfptr->Draw(di, PrimMode_LineStrip, 1u, &x, 2, &UFG::qMatrix44::msIdentity);
      v27 = di->vfptr;
      v28 = b->y;
      x = b->x;
      v29 = b->z;
      v31 = v28;
      v32 = v29;
      v35 = v20 - v23;
      v33 = v19 - v24;
      v34 = v39 - v25;
      v36 = v19 + v24;
      v37 = v39 + v25;
      v38 = v20 + v23;
      v27->Draw(di, PrimMode_TriStrip, 1u, &x, 3, &UFG::qMatrix44::msIdentity);
    }
  }
}

// File Line: 446
// RVA: 0x205890
void __fastcall UFG::Editor::Primitive::CircleSCR(UFG::Editor::DrawInterface *di, UFG::qVector3 *center, float radius)
{
  float x; // xmm8_4
  int v5; // edi
  char *v6; // rbx
  float y; // xmm9_4
  float z; // xmm10_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  char v11[8]; // [rsp+30h] [rbp-208h] BYREF
  char v12; // [rsp+38h] [rbp-200h] BYREF

  x = center->x;
  v5 = 0;
  v6 = &v12;
  y = center->y;
  z = center->z;
  do
  {
    v9 = (float)((float)v5 * 6.2831855) * 0.03125;
    *((float *)v6 - 2) = (float)(cosf(v9) * radius) + x;
    v10 = sinf(v9);
    ++v5;
    *(float *)v6 = z;
    v6 += 12;
    *((float *)v6 - 4) = (float)(v10 * radius) + y;
  }
  while ( v5 < 33 );
  di->vfptr->DrawSCR(di, PrimMode_LineStrip, 1u, v11, 33);
}

