// File Line: 40
// RVA: 0x781E0
void __fastcall TransformAABB2(UFG::qMatrix44 *m, UFG::qVector3 *min, UFG::qVector3 *max)
{
  float v3; // eax
  float v4; // xmm2_4
  float *v5; // rcx
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // eax
  float v13; // xmm1_4
  __int64 v14; // rax
  signed __int64 v15; // r9
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // [rsp+0h] [rbp-28h]
  float v29; // [rsp+4h] [rbp-24h]
  float v30; // [rsp+8h] [rbp-20h]
  float v31; // [rsp+10h] [rbp-18h]
  float v32; // [rsp+14h] [rbp-14h]
  float v33; // [rsp+18h] [rbp-10h]

  v3 = m->v3.x;
  v4 = m->v3.z;
  v5 = &m->v0.z;
  v6 = min->y;
  v28 = min->x;
  v30 = min->z;
  v7 = max->y;
  v29 = v6;
  v8 = max->x;
  v32 = v7;
  v9 = v5[11];
  v31 = v8;
  v10 = max->z;
  min->y = v9;
  min->x = v3;
  min->z = v4;
  v11 = v5[11];
  v33 = v10;
  v12 = v5[10];
  v13 = v5[12];
  max->y = v11;
  max->x = v12;
  v14 = 0i64;
  v15 = 3i64;
  max->z = v13;
  do
  {
    v16 = *(v5 - 2);
    v17 = *(float *)((char *)&v28 + v14);
    v18 = *(float *)((char *)&v31 + v14);
    v19 = v16;
    v20 = v16 * v18;
    v21 = v19 * v17;
    if ( v21 >= v20 )
    {
      min->x = v20 + min->x;
      max->x = v21 + max->x;
    }
    else
    {
      min->x = v21 + min->x;
      max->x = v20 + max->x;
    }
    v22 = *(v5 - 1);
    v23 = v22;
    v24 = v22 * v18;
    v25 = v23 * v17;
    if ( v25 >= v24 )
    {
      min->y = v24 + min->y;
      max->y = v25 + max->y;
    }
    else
    {
      min->y = v25 + min->y;
      max->y = v24 + max->y;
    }
    v26 = *v5 * v18;
    v27 = *v5 * v17;
    if ( v27 >= v26 )
    {
      min->z = v26 + min->z;
      max->z = v27 + max->z;
    }
    else
    {
      min->z = v27 + min->z;
      max->z = v26 + max->z;
    }
    v5 += 4;
    v14 += 4i64;
    --v15;
  }
  while ( v15 );
}

// File Line: 78
// RVA: 0x77F20
__int64 __fastcall ClipToSlab(UFG::qVector3 *inpts, UFG::qVector3 *outpts, unsigned int numpts, UFG::qMatrix44 *mat, float width, unsigned int axis)
{
  signed __int64 v6; // r10
  int v7; // er11
  UFG::qMatrix44 *v8; // r15
  UFG::qVector3 *v9; // rbx
  UFG::qVector3 *v10; // rdi
  int v11; // xmm8_4
  float v12; // xmm13_4
  unsigned int v13; // ebp
  signed __int64 v14; // rdx
  signed __int64 v15; // r9
  float v16; // xmm10_4
  float v17; // xmm11_4
  float v18; // xmm12_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm9_4
  float v22; // xmm3_4
  signed int v23; // eax
  float v24; // xmm2_4
  signed int v25; // edx
  float v27; // xmm1_4
  float v28; // xmm1_4
  signed __int64 v29; // rcx
  float v30; // xmm6_4
  float v31; // xmm6_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  signed __int64 v34; // rcx
  float v35; // xmm4_4
  float v36; // xmm5_4

  v6 = 0i64;
  v7 = 0;
  v8 = mat;
  v9 = outpts;
  v10 = inpts;
  if ( numpts )
  {
    v11 = LODWORD(width) ^ _xmm[0];
    while ( 1 )
    {
      v12 = *(&v8->v0.z + 4 * axis);
      v13 = v7 + 1;
      v14 = (v7 + 1) % numpts;
      v15 = v14;
      v16 = v10[v7].x;
      v17 = v10[v7].y;
      v18 = v10[v7].z;
      v19 = v10[(unsigned int)v14].x;
      v20 = v10[(unsigned int)v14].y;
      v21 = v10[(unsigned int)v14].z;
      v22 = (float)((float)(*(&v8->v0.x + 4 * axis) * v16) + (float)(*(&v8->v0.y + 4 * axis) * v17))
          + (float)(v10[v7].z * v12);
      if ( v22 >= *(float *)&v11 )
      {
        v23 = 0;
        if ( v22 > width )
          v23 = 2;
      }
      else
      {
        v23 = 1;
      }
      v24 = (float)((float)(*(&v8->v0.x + 4 * axis) * v19) + (float)(*(&v8->v0.y + 4 * axis) * v20))
          + (float)(v21 * v12);
      if ( v24 >= *(float *)&v11 )
      {
        v25 = 0;
        if ( v24 > width )
          v25 = 2;
      }
      else
      {
        v25 = 1;
      }
      if ( !v23 )
        break;
      if ( v23 == v25 )
        goto LABEL_28;
      if ( v23 == 1 )
      {
        LODWORD(v27) = LODWORD(width) ^ _xmm[0];
        goto LABEL_19;
      }
      if ( v23 == 2 )
      {
        v27 = width;
LABEL_19:
        v28 = (float)(v27 - v22) / (float)(v24 - v22);
        if ( (_DWORD)v6 == 32 )
          return 0i64;
        v18 = v18 + (float)((float)(v21 - v18) * v28);
        v17 = v17 + (float)((float)(v20 - v17) * v28);
        v16 = v16 + (float)((float)(v19 - v16) * v28);
LABEL_21:
        v29 = v6;
        v6 = (unsigned int)(v6 + 1);
        v9[v29].z = v18;
        v9[v29].y = v17;
        v9[v29].x = v16;
      }
      if ( v25 == 1 )
      {
        LODWORD(v30) = LODWORD(width) ^ _xmm[0];
      }
      else
      {
        if ( v25 != 2 )
          goto LABEL_28;
        v30 = width;
      }
      v31 = (float)(v30 - v22) / (float)(v24 - v22);
      if ( (_DWORD)v6 == 32 )
        return 0i64;
      v32 = v10[v7].z;
      v33 = v10[v7].y;
      v34 = v6;
      v6 = (unsigned int)(v6 + 1);
      v35 = v33 + (float)((float)(v10[v15].y - v33) * v31);
      v36 = v10[v7].x + (float)((float)(v10[v15].x - v10[v7].x) * v31);
      v9[v34].z = v32 + (float)((float)(v10[v15].z - v32) * v31);
      v9[v34].y = v35;
      v9[v34].x = v36;
LABEL_28:
      ++v7;
      if ( v13 >= numpts )
        return (unsigned int)v6;
    }
    if ( (_DWORD)v6 == 32 )
      return 0i64;
    goto LABEL_21;
  }
  return (unsigned int)v6;
}

