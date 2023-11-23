// File Line: 40
// RVA: 0x781E0
void __fastcall TransformAABB2(UFG::qMatrix44 *m, UFG::qVector3 *min, UFG::qVector3 *max)
{
  float x; // eax
  float z; // xmm2_4
  float *p_z; // rcx
  float y; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // eax
  float v13; // xmm1_4
  __int64 v14; // rax
  __int64 v15; // r9
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  int v26[4]; // [rsp+0h] [rbp-28h]
  int v27[6]; // [rsp+10h] [rbp-18h]

  x = m->v3.x;
  z = m->v3.z;
  p_z = &m->v0.z;
  y = min->y;
  v26[0] = LODWORD(min->x);
  v26[2] = LODWORD(min->z);
  v7 = max->y;
  *(float *)&v26[1] = y;
  v8 = max->x;
  *(float *)&v27[1] = v7;
  v9 = p_z[11];
  *(float *)v27 = v8;
  v10 = max->z;
  min->y = v9;
  min->x = x;
  min->z = z;
  v11 = p_z[11];
  *(float *)&v27[2] = v10;
  v12 = p_z[10];
  v13 = p_z[12];
  max->y = v11;
  max->x = v12;
  v14 = 0i64;
  v15 = 3i64;
  max->z = v13;
  do
  {
    v16 = *(float *)&v26[v14];
    v17 = *(float *)&v27[v14];
    v18 = *(p_z - 2);
    v19 = v18 * v17;
    v20 = v18 * v16;
    if ( v20 >= v19 )
    {
      min->x = v19 + min->x;
      max->x = v20 + max->x;
    }
    else
    {
      min->x = v20 + min->x;
      max->x = v19 + max->x;
    }
    v21 = *(p_z - 1);
    v22 = v21 * v17;
    v23 = v21 * v16;
    if ( v23 >= v22 )
    {
      min->y = v22 + min->y;
      max->y = v23 + max->y;
    }
    else
    {
      min->y = v23 + min->y;
      max->y = v22 + max->y;
    }
    v24 = *p_z * v17;
    v25 = *p_z * v16;
    if ( v25 >= v24 )
    {
      min->z = v24 + min->z;
      max->z = v25 + max->z;
    }
    else
    {
      min->z = v25 + min->z;
      max->z = v24 + max->z;
    }
    p_z += 4;
    ++v14;
    --v15;
  }
  while ( v15 );
}

// File Line: 78
// RVA: 0x77F20
__int64 __fastcall ClipToSlab(
        UFG::qVector3 *inpts,
        UFG::qVector3 *outpts,
        unsigned int numpts,
        UFG::qMatrix44 *mat,
        float width,
        unsigned int axis)
{
  __int64 v6; // r10
  int v7; // r11d
  int v11; // xmm8_4
  float v12; // xmm13_4
  unsigned int v13; // ebp
  __int64 v14; // rdx
  __int64 v15; // r9
  float x; // xmm10_4
  float y; // xmm11_4
  float z; // xmm12_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm9_4
  float v22; // xmm3_4
  int v23; // eax
  float v24; // xmm2_4
  int v25; // edx
  float v27; // xmm1_4
  float v28; // xmm1_4
  __int64 v29; // rcx
  float v30; // xmm6_4
  float v31; // xmm6_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  __int64 v34; // rcx
  float v35; // xmm4_4
  float v36; // xmm5_4

  v6 = 0i64;
  v7 = 0;
  if ( numpts )
  {
    v11 = LODWORD(width) ^ _xmm[0];
    do
    {
      v12 = *(&mat->v0.z + 4 * axis);
      v13 = v7 + 1;
      v14 = (v7 + 1) % numpts;
      v15 = v14;
      x = inpts[v7].x;
      y = inpts[v7].y;
      z = inpts[v7].z;
      v19 = inpts[(unsigned int)v14].x;
      v20 = inpts[(unsigned int)v14].y;
      v21 = inpts[(unsigned int)v14].z;
      v22 = (float)((float)(*(&mat->v0.x + 4 * axis) * x) + (float)(*(&mat->v0.y + 4 * axis) * y)) + (float)(z * v12);
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
      v24 = (float)((float)(*(&mat->v0.x + 4 * axis) * v19) + (float)(*(&mat->v0.y + 4 * axis) * v20))
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
      if ( v23 )
      {
        if ( v23 == v25 )
          goto LABEL_26;
        if ( v23 == 1 )
          LODWORD(v27) = LODWORD(width) ^ _xmm[0];
        else
          v27 = width;
        v28 = (float)(v27 - v22) / (float)(v24 - v22);
        if ( (_DWORD)v6 == 32 )
          return 0i64;
        z = z + (float)((float)(v21 - z) * v28);
        y = y + (float)((float)(v20 - y) * v28);
        x = x + (float)((float)(v19 - x) * v28);
      }
      else if ( (_DWORD)v6 == 32 )
      {
        return 0i64;
      }
      v29 = v6;
      v6 = (unsigned int)(v6 + 1);
      outpts[v29].z = z;
      outpts[v29].y = y;
      outpts[v29].x = x;
      if ( v25 == 1 )
      {
        LODWORD(v30) = LODWORD(width) ^ _xmm[0];
      }
      else
      {
        if ( v25 != 2 )
          goto LABEL_26;
        v30 = width;
      }
      v31 = (float)(v30 - v22) / (float)(v24 - v22);
      if ( (_DWORD)v6 == 32 )
        return 0i64;
      v32 = inpts[v7].z;
      v33 = inpts[v7].y;
      v34 = v6;
      v6 = (unsigned int)(v6 + 1);
      v35 = v33 + (float)((float)(inpts[v15].y - v33) * v31);
      v36 = inpts[v7].x + (float)((float)(inpts[v15].x - inpts[v7].x) * v31);
      outpts[v34].z = v32 + (float)((float)(inpts[v15].z - v32) * v31);
      outpts[v34].y = v35;
      outpts[v34].x = v36;
LABEL_26:
      ++v7;
    }
    while ( v13 < numpts );
  }
  return (unsigned int)v6;
}

