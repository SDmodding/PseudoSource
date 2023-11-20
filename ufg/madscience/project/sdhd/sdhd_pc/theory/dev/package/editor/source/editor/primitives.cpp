// File Line: 70
// RVA: 0x20A870
void __fastcall UFG::Editor::Primitive::FlatArrowFilled(UFG::Editor::DrawInterface *di, UFG::qVector3 *a, UFG::qVector3 *b, float halfWidth)
{
  UFG::qVector3 *v4; // rbx
  UFG::Editor::DrawInterface *v5; // rdi
  float v6; // xmm13_4
  float v7; // xmm12_4
  float v8; // xmm14_4
  __m128 v9; // xmm4
  float v10; // xmm8_4
  float v11; // xmm9_4
  float v12; // xmm6_4
  __m128 v13; // xmm1
  float v14; // xmm7_4
  float v15; // xmm2_4
  float v16; // xmm7_4
  float v17; // xmm1_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm15_4
  float v21; // xmm7_4
  float v22; // xmm0_4
  float v23; // xmm6_4
  float v24; // xmm9_4
  float v25; // xmm10_4
  float v26; // xmm6_4
  float v27; // xmm9_4
  float v28; // xmm10_4
  UFG::Editor::DrawInterfaceVtbl *v29; // rax
  signed int v30; // ST20_4
  UFG::Editor::DrawInterfaceVtbl *v31; // rax
  float v32; // xmm1_4
  float v33; // xmm0_4
  __int64 v34; // ST20_8
  unsigned __int64 v35; // [rsp+30h] [rbp-C8h]
  unsigned __int64 v36; // [rsp+38h] [rbp-C0h]
  unsigned __int64 v37; // [rsp+40h] [rbp-B8h]
  float v38; // [rsp+48h] [rbp-B0h]
  float v39; // [rsp+4Ch] [rbp-ACh]
  float v40; // [rsp+50h] [rbp-A8h]
  float v41; // [rsp+108h] [rbp+10h]

  v9 = (__m128)LODWORD(b->y);
  v4 = b;
  v5 = di;
  v6 = a->y;
  v7 = a->x;
  v8 = a->z;
  v9.m128_f32[0] = v9.m128_f32[0] - v6;
  v10 = b->x - a->x;
  v11 = b->z - v8;
  v12 = halfWidth;
  v13 = v9;
  v13.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v10 * v10)) + (float)(v11 * v11);
  LODWORD(v14) = (unsigned __int128)_mm_sqrt_ps(v13);
  if ( v14 >= 0.000099999997 )
  {
    if ( halfWidth < 0.0 )
      v12 = v14 * 0.039999999;
    if ( v14 >= (float)(v12 * 4.0) )
    {
      v15 = 1.0 / v14;
      v16 = v14 - (float)(v12 * 4.0);
      v17 = v15 * v9.m128_f32[0];
      LODWORD(v18) = v9.m128_i32[0] ^ _xmm[0];
      v19 = (float)(v16 * v17) + v6;
      v20 = (float)(v16 * (float)(v15 * v10)) + v7;
      v21 = (float)(v16 * (float)(v15 * v11)) + v8;
      v22 = (float)(v18 * v18) + (float)(v10 * v10);
      v41 = v19;
      if ( v22 <= 0.000099999997 )
      {
        v27 = v12;
        v28 = 0.0;
        v26 = 0.0;
      }
      else
      {
        v23 = v12 / fsqrt(v22);
        v24 = v23;
        v25 = v23;
        v26 = v23 * 0.0;
        v27 = v24 * v18;
        v28 = v25 * v10;
      }
      v29 = di->vfptr;
      v35 = __PAIR__(LODWORD(v6), LODWORD(v7));
      v36 = __PAIR__(LODWORD(v20), LODWORD(v8));
      v37 = __PAIR__(LODWORD(v21), LODWORD(v19));
      v30 = 2;
      ((void (__fastcall *)(UFG::Editor::DrawInterface *, signed __int64, signed __int64, unsigned __int64 *, signed int, UFG::qMatrix44 *, unsigned __int64, unsigned __int64, unsigned __int64))v29->Draw)(
        di,
        1i64,
        1i64,
        &v35,
        v30,
        &UFG::qMatrix44::msIdentity,
        __PAIR__(LODWORD(v6), LODWORD(v7)),
        __PAIR__(LODWORD(v20), LODWORD(v8)),
        __PAIR__(LODWORD(v21), LODWORD(v19)));
      v31 = v5->vfptr;
      v32 = v4->y;
      *(float *)&v35 = v4->x;
      v33 = v4->z;
      *((float *)&v35 + 1) = v32;
      LODWORD(v34) = 3;
      *(float *)&v36 = v33;
      *((float *)&v37 + 1) = v21 - v26;
      *((float *)&v36 + 1) = v20 - v27;
      *(float *)&v37 = v41 - v28;
      v38 = v20 + v27;
      v39 = v41 + v28;
      v40 = v21 + v26;
      ((void (__fastcall *)(UFG::Editor::DrawInterface *, signed __int64, signed __int64, unsigned __int64 *, __int64, UFG::qMatrix44 *, unsigned __int64, unsigned __int64, unsigned __int64, _QWORD, _QWORD))v31->Draw)(
        v5,
        3i64,
        1i64,
        &v35,
        v34,
        &UFG::qMatrix44::msIdentity,
        v35,
        v36,
        v37,
        *(_QWORD *)&v38,
        *(_QWORD *)&v40);
    }
  }
}

// File Line: 446
// RVA: 0x205890
void __fastcall UFG::Editor::Primitive::CircleSCR(UFG::Editor::DrawInterface *di, UFG::qVector3 *center, float radius)
{
  float v3; // xmm8_4
  UFG::Editor::DrawInterface *v4; // rsi
  signed int v5; // edi
  char *v6; // rbx
  float v7; // xmm9_4
  float v8; // xmm10_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  signed int v11; // ST20_4
  char v12; // [rsp+30h] [rbp-208h]
  char v13; // [rsp+38h] [rbp-200h]

  v3 = center->x;
  v4 = di;
  v5 = 0;
  v6 = &v13;
  v7 = center->y;
  v8 = center->z;
  do
  {
    v9 = (float)((float)v5 * 6.2831855) * 0.03125;
    *((float *)v6 - 2) = (float)(cosf(v9) * radius) + v3;
    v10 = sinf(v9);
    ++v5;
    *(float *)v6 = v8;
    v6 += 12;
    *((float *)v6 - 4) = (float)(v10 * radius) + v7;
  }
  while ( v5 < 33 );
  v11 = 33;
  v4->vfptr->DrawSCR(v4, PrimMode_LineStrip, 1u, &v12, v11);
}

