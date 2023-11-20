// File Line: 37
// RVA: 0xABF280
void __fastcall mergesort(char *index, unsigned __int16 *vals, unsigned __int16 n)
{
  char *v3; // rbx
  unsigned __int64 v4; // r9
  signed __int64 v5; // r9
  void *v6; // rsp
  void *v7; // rsp
  signed int v8; // edi
  signed int v9; // er10
  unsigned __int16 v10; // dx
  int *v11; // r9
  signed int v12; // er11
  unsigned __int16 v13; // ax
  int v14; // ecx
  int v15; // er12
  signed int v16; // edx
  int v17; // ecx
  int v18; // edi
  signed __int64 v19; // r14
  __int64 v20; // r13
  char *v21; // r10
  char *v22; // r11
  __int64 v23; // rdi
  __int64 v24; // rsi
  __int64 v25; // rcx
  signed __int64 i; // r8
  char v27; // cl
  __int64 v28; // rdx
  __int64 j; // r8
  char v30; // cl
  __int64 v31; // rdx
  int v32; // ecx
  bool v33; // sf
  unsigned __int8 v34; // of
  __int64 v35; // rdx
  int *v36; // rax
  __int64 v37; // rcx
  int v38; // [rsp+20h] [rbp+0h]
  int v39; // [rsp+24h] [rbp+4h]
  char *v40; // [rsp+28h] [rbp+8h]
  char *v41; // [rsp+80h] [rbp+60h]
  unsigned __int16 *v42; // [rsp+88h] [rbp+68h]
  int v43; // [rsp+90h] [rbp+70h]
  signed int v44; // [rsp+98h] [rbp+78h]

  v42 = vals;
  v41 = index;
  v3 = index;
  v40 = index;
  v4 = n + 15i64;
  if ( v4 <= n )
    v4 = 1152921504606846960i64;
  v5 = v4 & 0xFFFFFFFFFFFFFFF0ui64;
  v6 = alloca(v5);
  v7 = alloca(v5);
  v8 = 1;
  v9 = n;
  v10 = 0;
  v11 = &v38;
  v44 = 1;
  v39 = n;
  if ( (signed int)n > 1 )
  {
    v12 = 1;
    v38 = 1;
    do
    {
      v13 = 0;
      if ( v12 < v9 )
      {
        v14 = 2 * v12;
        do
        {
          v15 = v13;
          v16 = v9;
          v17 = v13 + v14;
          v18 = v13 + v12;
          v19 = v18;
          v43 = v13 + v12;
          if ( v17 < v9 )
            v16 = v17;
          v20 = v16;
          if ( v13 < (signed __int64)v18 )
          {
            v21 = &v3[v18];
            v22 = &v3[v13];
            do
            {
              if ( v21 - v3 >= v16 )
                break;
              v23 = *v21;
              v24 = *v22;
              v25 = v13++;
              if ( v42[v24] >= v42[v23] )
              {
                *((_BYTE *)v11 + v25) = v23;
                v18 = v43 + 1;
                ++v21;
                ++v43;
              }
              else
              {
                v18 = v43;
                ++v15;
                *((_BYTE *)v11 + v25) = v24;
                ++v22;
              }
            }
            while ( v22 - v3 < v19 );
            v3 = v40;
            v9 = v39;
            v12 = v38;
          }
          for ( i = v15; i < v19; *((_BYTE *)v11 + v28) = v27 )
          {
            v27 = v3[i];
            v28 = v13;
            ++i;
            ++v13;
          }
          for ( j = v18; j < v20; *((_BYTE *)v11 + v31) = v30 )
          {
            v30 = v3[j];
            v31 = v13;
            ++j;
            ++v13;
          }
          v32 = v12 + v13;
          v34 = __OFSUB__(v32, v9);
          v33 = v32 - v9 < 0;
          v14 = 2 * v12;
        }
        while ( v33 ^ v34 );
        v8 = v44;
      }
      for ( ; v13 < v9; *((_BYTE *)v11 + v35) = v3[v35] )
        v35 = v13++;
      LOWORD(v8) = 2 * v8;
      v36 = (int *)v3;
      v3 = (char *)v11;
      v12 = (unsigned __int16)v8;
      v40 = (char *)v11;
      v11 = v36;
      v44 = v8;
      v10 = 0;
      v38 = (unsigned __int16)v8;
    }
    while ( (unsigned __int16)v8 < v9 );
  }
  if ( v11 == (int *)v41 && v9 > 0 )
  {
    do
    {
      v37 = v10++;
      *((_BYTE *)v11 + v37) = v3[v37];
    }
    while ( v10 < v9 );
  }
}

// File Line: 68
// RVA: 0xABE9D0
signed __int64 __fastcall floor1_info_unpack(vorbis_info_floor1 *info, codec_setup_info *ci, oggpack_buffer *opb, CAkVorbisAllocator *VorbisAllocator)
{
  codec_setup_info *v4; // r12
  vorbis_info_floor1 *v5; // rdi
  signed int v6; // esi
  int v7; // er14
  CAkVorbisAllocator *v8; // r15
  oggpack_buffer *v9; // r13
  int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // er8
  char *v13; // rdx
  int v14; // ebp
  int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // er8
  floor1class *v18; // rdx
  int v19; // ebp
  signed __int64 v20; // r14
  signed int v21; // esi
  signed __int64 v22; // rbx
  int v23; // eax
  int v24; // eax
  __int64 v25; // rdx
  int v26; // er10
  char *v27; // rcx
  __int64 v28; // rax
  int v29; // ecx
  unsigned int v30; // ecx
  unsigned int v31; // er9
  unsigned __int16 *v32; // r8
  unsigned int v33; // ecx
  unsigned int v34; // er8
  char *v35; // rdx
  unsigned int v36; // ecx
  unsigned int v37; // er8
  char *v38; // rdx
  unsigned int v39; // ecx
  unsigned int v40; // er8
  char *v41; // rdx
  bool v42; // zf
  bool v43; // sf
  int v44; // er8
  int v45; // er15
  int v46; // ebp
  signed __int64 v47; // rbx
  signed int v48; // er12
  signed __int64 v49; // r14
  signed __int64 v50; // rsi
  unsigned __int16 v51; // ax
  int v53; // edx
  int i; // ebp
  unsigned __int16 *v55; // rdx
  __int64 v56; // r14
  int v57; // er9
  int v58; // er10
  char v59; // bl
  char v60; // si
  int v61; // er8
  int j; // ecx
  int v63; // eax
  int v64; // [rsp+20h] [rbp-38h]
  int v65; // [rsp+60h] [rbp+8h]
  int v66; // [rsp+60h] [rbp+8h]

  v4 = ci;
  v5 = info;
  v6 = -1;
  v7 = 0;
  v8 = VorbisAllocator;
  v9 = opb;
  v10 = oggpack_read(opb, 5);
  v5->partitions = v10;
  if ( v10 && (v11 = (v10 + 3) & 0xFFFFFFFC, v12 = v11 + v8->CurrentSize, v12 <= v8->MaxSize) )
  {
    v13 = v8->pCurrentAddress;
    v8->CurrentSize = v12;
    v8->pCurrentAddress = &v13[v11];
  }
  else
  {
    v13 = 0i64;
  }
  v14 = 0;
  for ( v5->partitionclass = v13; v14 < v5->partitions; ++v14 )
  {
    v5->partitionclass[v14] = oggpack_read(v9, 4);
    if ( v6 < v5->partitionclass[v14] )
      v6 = v5->partitionclass[v14];
  }
  v65 = v6 + 1;
  v15 = 11 * (v6 + 1);
  if ( v15 && (v16 = (v15 + 3) & 0xFFFFFFFC, v17 = v16 + v8->CurrentSize, v17 <= v8->MaxSize) )
  {
    v18 = (floor1class *)v8->pCurrentAddress;
    v8->CurrentSize = v17;
    v8->pCurrentAddress = &v18->class_dim + v16;
  }
  else
  {
    v18 = 0i64;
  }
  v19 = 0;
  v5->Class = v18;
  if ( v6 + 1 > 0 )
  {
    while ( 1 )
    {
      v20 = v19;
      v5->Class[v20].class_dim = (unsigned __int64)oggpack_read(v9, 3) + 1;
      v5->Class[v20].class_subs = oggpack_read(v9, 2);
      if ( v9->headend < 0 )
        return 0xFFFFFFFFi64;
      if ( v5->Class[v20].class_subs )
      {
        v5->Class[v20].class_book = oggpack_read(v9, 8);
        if ( (unsigned __int8)v5->Class[v20].class_book >= v4->books )
          return 0xFFFFFFFFi64;
      }
      else
      {
        v5->Class[v20].class_book = 0;
      }
      if ( (unsigned __int8)v5->Class[v20].class_book >= v4->books )
        return 0xFFFFFFFFi64;
      v21 = 0;
      if ( 1 << v5->Class[v20].class_subs > 0 )
      {
        v22 = 11i64 * v19;
        do
        {
          v5->Class->class_subbook[v22] = (unsigned __int64)oggpack_read(v9, 8) - 1;
          v23 = (unsigned __int8)v5->Class->class_subbook[v22];
          if ( v23 >= v4->books && (_BYTE)v23 != -1 )
            return 0xFFFFFFFFi64;
          ++v21;
          ++v22;
        }
        while ( v21 < 1 << v5->Class[v20].class_subs );
      }
      if ( ++v19 >= v65 )
      {
        v7 = 0;
        break;
      }
    }
  }
  v5->mult = (unsigned __int64)oggpack_read(v9, 2) + 1;
  v24 = oggpack_read(v9, 4);
  v25 = (unsigned int)v5->partitions;
  v26 = v24;
  v66 = v24;
  if ( (signed int)v25 > 0 )
  {
    v27 = v5->partitionclass;
    do
    {
      v28 = *v27++;
      v7 += v5->Class[v28].class_dim;
      --v25;
    }
    while ( v25 );
  }
  v29 = 2 * (v7 + 2);
  if ( v29 && (v30 = (v29 + 3) & 0xFFFFFFFC, v31 = v30 + v8->CurrentSize, v31 <= v8->MaxSize) )
  {
    v32 = (unsigned __int16 *)v8->pCurrentAddress;
    v8->CurrentSize = v31;
    v8->pCurrentAddress = (char *)v32 + v30;
  }
  else
  {
    v32 = 0i64;
  }
  v5->postlist = v32;
  if ( v7 == -2 || (v33 = (v7 + 5) & 0xFFFFFFFC, v34 = v33 + v8->CurrentSize, v34 > v8->MaxSize) )
  {
    v35 = 0i64;
  }
  else
  {
    v35 = v8->pCurrentAddress;
    v8->CurrentSize = v34;
    v8->pCurrentAddress = &v35[v33];
  }
  v5->forward_index = v35;
  if ( v7 && (v36 = (v7 + 3) & 0xFFFFFFFC, v37 = v36 + v8->CurrentSize, v37 <= v8->MaxSize) )
  {
    v38 = v8->pCurrentAddress;
    v8->CurrentSize = v37;
    v8->pCurrentAddress = &v38[v36];
  }
  else
  {
    v38 = 0i64;
  }
  v5->loneighbor = v38;
  if ( v7 && (v39 = (v7 + 3) & 0xFFFFFFFC, v40 = v39 + v8->CurrentSize, v40 <= v8->MaxSize) )
  {
    v41 = v8->pCurrentAddress;
    v8->CurrentSize = v40;
    v8->pCurrentAddress = &v41[v39];
  }
  else
  {
    v41 = 0i64;
  }
  v42 = v5->partitions == 0;
  v43 = v5->partitions < 0;
  v5->hineighbor = v41;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v47 = 0i64;
  if ( !v43 && !v42 )
  {
    v48 = __ROL4__(1, v26);
    while ( 1 )
    {
      v44 += v5->Class[v5->partitionclass[v45]].class_dim;
      v49 = v44;
      v64 = v44;
      if ( v47 < v44 )
        break;
LABEL_53:
      if ( ++v45 >= v5->partitions )
        goto LABEL_54;
    }
    v50 = 2 * v47 + 4;
    while ( 1 )
    {
      v51 = oggpack_read(v9, v26);
      *(unsigned __int16 *)((char *)v5->postlist + v50) = v51;
      if ( v51 >= v48 )
        return 0xFFFFFFFFi64;
      v26 = v66;
      ++v47;
      ++v46;
      v50 += 2i64;
      if ( v47 >= v49 )
      {
        v44 = v64;
        goto LABEL_53;
      }
    }
  }
LABEL_54:
  if ( v9->headend < 0 )
    return 0xFFFFFFFFi64;
  *v5->postlist = 0;
  v5->postlist[1] = 1 << v26;
  v53 = 0;
  for ( v5->posts = v44 + 2; v53 < v5->posts; ++v53 )
    v5->forward_index[v53] = v53;
  mergesort(v5->forward_index, v5->postlist, v5->posts);
  for ( i = 0; i < v5->posts - 2; v5->hineighbor[v56] = v60 )
  {
    v55 = v5->postlist;
    v56 = i;
    v57 = v55[1];
    v58 = v55[i + 2];
    v59 = 0;
    v60 = 1;
    v61 = 0;
    for ( j = 0; j < i + 2; ++v55 )
    {
      v63 = *v55;
      if ( v63 > v61 && v63 < v58 )
      {
        v59 = j;
        v61 = *v55;
      }
      if ( v63 < v57 && v63 > v58 )
      {
        v60 = j;
        v57 = *v55;
      }
      ++j;
    }
    ++i;
    v5->loneighbor[v56] = v59;
  }
  return 0i64;
}

// File Line: 240
// RVA: 0xABF470
void __fastcall render_line(int x0, int x1, int y0, int y1, int *d)
{
  int v5; // er9
  __int64 v6; // rbp
  __int64 v7; // rdi
  int v8; // er10
  int v9; // er11
  int v10; // eax
  bool v11; // sf
  __int64 v12; // rbx
  __int64 v13; // r9
  int v14; // ecx
  __int64 v15; // rdx
  int v16; // er11
  __int64 v17; // r8
  int *v18; // rax
  unsigned __int64 v19; // rdi
  int v20; // ecx
  __int64 v21; // rdx
  int v22; // ecx
  __int64 v23; // rdx
  int v24; // ecx
  __int64 v25; // rdx
  __m128i v26; // xmm0
  signed __int64 v27; // rbx
  signed __int64 v28; // r9
  float *v29; // rax
  __m128i v30; // xmm0

  v5 = y1 - y0;
  v6 = x1;
  v7 = x0;
  v8 = x1 - x0;
  v9 = abs(v5);
  v10 = v5 / (x1 - x0);
  v11 = v5 < 0;
  v12 = v10;
  LODWORD(v13) = v10 - 1;
  if ( !v11 )
    LODWORD(v13) = v12 + 1;
  v14 = 0;
  v13 = (signed int)v13;
  v15 = y0;
  v16 = v9 - abs(v8 * v12);
  v17 = (signed int)v7 + 1;
  *(float *)&d[v7] = (float)d[v7] * fFLOOR_fromdB_LOOKUP[v15];
  if ( v17 < v6 )
  {
    if ( v6 - v17 >= 4 )
    {
      v18 = &d[v17 + 2];
      v19 = ((unsigned __int64)(v6 - v17 - 4) >> 2) + 1;
      v17 += 4 * v19;
      do
      {
        v20 = v16 + v14;
        if ( v20 < v8 )
        {
          v21 = v12 + v15;
        }
        else
        {
          v20 -= v8;
          v21 = v13 + v15;
        }
        v22 = v16 + v20;
        *((float *)v18 - 2) = (float)*(v18 - 2) * fFLOOR_fromdB_LOOKUP[v21];
        if ( v22 < v8 )
        {
          v23 = v12 + v21;
        }
        else
        {
          v22 -= v8;
          v23 = v13 + v21;
        }
        v24 = v16 + v22;
        *((float *)v18 - 1) = (float)*(v18 - 1) * fFLOOR_fromdB_LOOKUP[v23];
        if ( v24 < v8 )
        {
          v25 = v12 + v23;
        }
        else
        {
          v24 -= v8;
          v25 = v13 + v23;
        }
        v14 = v16 + v24;
        *(float *)v18 = (float)*v18 * fFLOOR_fromdB_LOOKUP[v25];
        if ( v14 < v8 )
        {
          v15 = v12 + v25;
        }
        else
        {
          v14 -= v8;
          v15 = v13 + v25;
        }
        v26 = _mm_cvtsi32_si128(v18[1]);
        v18 += 4;
        *((float *)v18 - 3) = COERCE_FLOAT(_mm_cvtepi32_ps(v26)) * fFLOOR_fromdB_LOOKUP[v15];
        --v19;
      }
      while ( v19 );
    }
    if ( v17 < v6 )
    {
      v27 = 4 * v12;
      v28 = 4 * v13;
      v29 = &fFLOOR_fromdB_LOOKUP[v15];
      do
      {
        v14 += v16;
        if ( v14 < v8 )
        {
          v29 = (float *)((char *)v29 + v27);
        }
        else
        {
          v14 -= v8;
          v29 = (float *)((char *)v29 + v28);
        }
        v30 = _mm_cvtsi32_si128(d[v17++]);
        *(float *)&d[v17 - 1] = COERCE_FLOAT(_mm_cvtepi32_ps(v30)) * *v29;
      }
      while ( v17 < v6 );
    }
  }
}

// File Line: 276
// RVA: 0xABEEA0
int *__fastcall floor1_inverse1(vorbis_dsp_state *vd, vorbis_info_floor1 *info, int *fit_value)
{
  vorbis_dsp_state *v3; // r13
  codebook *v4; // rdi
  vorbis_info_floor1 *v5; // r14
  int v6; // er15
  int *v7; // rsi
  unsigned int v8; // ebx
  int v9; // edx
  unsigned int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // eax
  signed __int64 v14; // rcx
  int v15; // edx
  signed int v16; // ebp
  signed int v17; // er8
  int v18; // esi
  signed __int64 v19; // r15
  char v20; // r12
  __int64 v21; // rbp
  signed int v22; // ebx
  __int64 v23; // rdi
  __int64 v24; // rax
  int *v25; // rbx
  __int64 v26; // rdx
  int v27; // eax
  signed __int64 v29; // rdi
  unsigned __int16 *v30; // r10
  __int64 v31; // rcx
  __int64 v32; // r8
  int v33; // ebx
  int v34; // eax
  int v35; // ebx
  int v36; // eax
  int v37; // edx
  int v38; // ecx
  int v39; // eax
  __int64 v40; // rcx
  __int64 v41; // rcx
  int v42; // [rsp+20h] [rbp-68h]
  __int64 v43; // [rsp+28h] [rbp-60h]
  codebook *v44; // [rsp+30h] [rbp-58h]
  __int64 v45; // [rsp+38h] [rbp-50h]
  signed int v46; // [rsp+90h] [rbp+8h]
  int v47; // [rsp+98h] [rbp+10h]
  int *v48; // [rsp+A0h] [rbp+18h]

  v48 = fit_value;
  v3 = vd;
  v4 = vd->csi->book_param;
  v5 = info;
  v6 = quant_look[info->mult - 1];
  v7 = fit_value;
  v44 = vd->csi->book_param;
  v42 = quant_look[info->mult - 1];
  if ( (unsigned int)oggpack_read(&vd->opb, 1) != 1 )
    return 0i64;
  v8 = v6 - 1;
  v9 = 0;
  v10 = v6 - 1;
  if ( v6 != 1 )
  {
    do
    {
      ++v9;
      v10 >>= 1;
    }
    while ( v10 );
  }
  v11 = oggpack_read(&v3->opb, v9);
  v12 = 0;
  *v7 = v11;
  if ( v6 != 1 )
  {
    do
    {
      ++v12;
      v8 >>= 1;
    }
    while ( v8 );
  }
  v13 = oggpack_read(&v3->opb, v12);
  v14 = 0i64;
  v15 = 0;
  v16 = 2;
  v7[1] = v13;
  v47 = 0;
  v43 = 0i64;
  v17 = 2;
  v46 = 2;
  if ( v5->partitions > 0 )
  {
    do
    {
      v18 = 0;
      v19 = v5->partitionclass[v14];
      v20 = v5->Class[v19].class_subs;
      v21 = v5->Class[v19].class_dim;
      v22 = 1 << v5->Class[v19].class_subs;
      if ( v5->Class[v19].class_subs )
      {
        v18 = ak_vorbis_book_decode(&v4[(unsigned __int8)v5->Class[v19].class_book], &v3->opb);
        if ( v18 == -1 )
          return 0i64;
        v15 = v47;
        v17 = v46;
      }
      v23 = 0i64;
      if ( v21 > 0 )
      {
        v24 = v22 - 1;
        v25 = &v48[v17];
        v45 = v24;
        do
        {
          v26 = (unsigned __int8)v5->Class[v19].class_subbook[v24 & v18];
          v18 >>= v20;
          if ( (_DWORD)v26 == 255 )
          {
            *v25 = 0;
          }
          else
          {
            v27 = ak_vorbis_book_decode(&v44[v26], &v3->opb);
            *v25 = v27;
            if ( v27 == -1 )
              return 0i64;
          }
          v24 = v45;
          ++v23;
          ++v25;
        }
        while ( v23 < v21 );
        v15 = v47;
        v17 = v46;
      }
      v4 = v44;
      ++v15;
      v17 += v21;
      v14 = v43 + 1;
      v47 = v15;
      ++v43;
      v46 = v17;
    }
    while ( v15 < v5->partitions );
    v7 = v48;
    v6 = v42;
    v16 = 2;
  }
  v29 = 2i64;
  if ( v5->posts > 2 )
  {
    do
    {
      v30 = v5->postlist;
      v31 = v5->loneighbor[v29 - 2];
      v32 = v5->hineighbor[v29 - 2];
      v33 = v7[v31] & 0x7FFF;
      v34 = (v30[v29] - v30[v31]) * abs((v7[v32] & 0x7FFF) - v33) / (v30[v32] - v30[v31]);
      if ( (v7[v32] & 0x7FFF) - v33 >= 0 )
        v35 = v34 + v33;
      else
        v35 = v33 - v34;
      v36 = v7[v29];
      v37 = v6 - v35;
      if ( v36 )
      {
        v38 = v35;
        if ( v37 < v35 )
          v38 = v6 - v35;
        if ( v36 < 2 * v38 )
        {
          if ( v36 & 1 )
            v39 = -((v36 + 1) >> 1);
          else
            v39 = v36 >> 1;
        }
        else if ( v37 <= v35 )
        {
          v39 = v37 - v36 - 1;
        }
        else
        {
          v39 = v36 - v35;
        }
        v7[v29] = v39 + v35;
        v40 = v5->loneighbor[v29 - 2];
        v7[v40] &= 0x7FFFu;
        v41 = v5->hineighbor[v29 - 2];
        v7[v41] &= 0x7FFFu;
      }
      else
      {
        v7[v29] = v35 | 0x8000;
      }
      ++v16;
      ++v29;
    }
    while ( v16 < v5->posts );
  }
  return v7;
}

// File Line: 364
// RVA: 0xABF190
signed __int64 __fastcall floor1_inverse2(vorbis_dsp_state *vd, vorbis_info_floor1 *info, int *fit_value, int *out)
{
  vorbis_info_floor1 *v4; // rbp
  int *d; // r12
  int *v6; // r15
  signed int v7; // esi
  int v8; // er10
  signed __int64 v9; // r14
  int v10; // er8
  __int64 v11; // rcx
  int v12; // ebx
  int v13; // ebx
  int v14; // edi
  signed __int64 result; // rax

  v4 = info;
  d = out;
  v6 = fit_value;
  if ( fit_value )
  {
    v7 = 1;
    v8 = 0;
    v9 = 1i64;
    v10 = *fit_value * info->mult;
    if ( info->posts > 1 )
    {
      do
      {
        v11 = v4->forward_index[v9];
        v12 = v6[v11] & 0x7FFF;
        if ( v12 == v6[v11] )
        {
          v13 = v4->mult * v12;
          v14 = v4->postlist[v11];
          render_line(v8, v14, v10, v13, d);
          v8 = v14;
          v10 = v13;
        }
        ++v7;
        ++v9;
      }
      while ( v7 < v4->posts );
    }
    result = 1i64;
  }
  else
  {
    memset(out, 0, (unsigned int)(4 * (vd->csi->blocksizes[vd->state.W] / 2)));
    result = 0i64;
  }
  return result;
}

