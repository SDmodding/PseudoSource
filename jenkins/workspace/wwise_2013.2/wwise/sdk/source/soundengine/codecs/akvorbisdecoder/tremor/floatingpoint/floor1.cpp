// File Line: 37
// RVA: 0xABF280
void __fastcall mergesort(char *index, unsigned __int16 *vals, unsigned __int16 n)
{
  char *v3; // rbx
  unsigned __int64 v4; // r9
  void *v5; // rsp
  void *v6; // rsp
  int v7; // edi
  int v8; // r10d
  unsigned __int16 v9; // dx
  char *v10; // r9
  int v11; // r11d
  unsigned __int16 v12; // ax
  int v13; // ecx
  int v14; // r12d
  int v15; // edx
  int v16; // ecx
  int v17; // edi
  signed __int64 v18; // r14
  __int64 v19; // r13
  char *v20; // r10
  char *v21; // r11
  __int64 v22; // rdi
  __int64 v23; // rsi
  __int64 v24; // rcx
  signed __int64 i; // r8
  char v26; // cl
  __int64 v27; // rdx
  __int64 j; // r8
  char v29; // cl
  __int64 v30; // rdx
  __int64 v31; // rdx
  char *v32; // rax
  __int64 v33; // rcx
  int v34; // [rsp+20h] [rbp+0h] BYREF
  int v35; // [rsp+24h] [rbp+4h]
  char *v36; // [rsp+28h] [rbp+8h]
  int v39; // [rsp+90h] [rbp+70h]
  int v40; // [rsp+98h] [rbp+78h]

  v3 = index;
  v36 = index;
  v4 = n + 15i64;
  if ( v4 <= n )
    v4 = 0xFFFFFFFFFFFFFF0i64;
  v5 = alloca(v4 & 0xFFFFFFFFFFFFFFF0ui64);
  v6 = alloca(v4 & 0xFFFFFFFFFFFFFFF0ui64);
  v7 = 1;
  v8 = n;
  v9 = 0;
  v10 = (char *)&v34;
  v40 = 1;
  v35 = n;
  if ( n > 1u )
  {
    v11 = 1;
    v34 = 1;
    do
    {
      v12 = 0;
      if ( v11 < v8 )
      {
        v13 = 2 * v11;
        do
        {
          v14 = v12;
          v15 = v8;
          v16 = v12 + v13;
          v17 = v12 + v11;
          v18 = v17;
          v39 = v17;
          if ( v16 < v8 )
            v15 = v16;
          v19 = v15;
          if ( v12 < (__int64)v17 )
          {
            v20 = &v3[v17];
            v21 = &v3[v12];
            do
            {
              if ( v20 - v3 >= v15 )
                break;
              v22 = *v20;
              v23 = *v21;
              v24 = v12++;
              if ( vals[v23] >= vals[v22] )
              {
                v10[v24] = v22;
                v17 = v39 + 1;
                ++v20;
                ++v39;
              }
              else
              {
                v17 = v39;
                ++v14;
                v10[v24] = v23;
                ++v21;
              }
            }
            while ( v21 - v3 < v18 );
            v3 = v36;
            v8 = v35;
            v11 = v34;
          }
          for ( i = v14; i < v18; v10[v27] = v26 )
          {
            v26 = v3[i];
            v27 = v12;
            ++i;
            ++v12;
          }
          for ( j = v17; j < v19; v10[v30] = v29 )
          {
            v29 = v3[j];
            v30 = v12;
            ++j;
            ++v12;
          }
          v13 = 2 * v11;
        }
        while ( v11 + v12 < v8 );
        v7 = v40;
      }
      for ( ; v12 < v8; v10[v31] = v3[v31] )
        v31 = v12++;
      LOWORD(v7) = 2 * v7;
      v32 = v3;
      v3 = v10;
      v11 = (unsigned __int16)v7;
      v36 = v10;
      v10 = v32;
      v40 = v7;
      v9 = 0;
      v34 = (unsigned __int16)v7;
    }
    while ( (unsigned __int16)v7 < v8 );
  }
  if ( v10 == index && v8 > 0 )
  {
    do
    {
      v33 = v9++;
      v10[v33] = v3[v33];
    }
    while ( v9 < v8 );
  }
}

// File Line: 68
// RVA: 0xABE9D0
__int64 __fastcall floor1_info_unpack(
        vorbis_info_floor1 *info,
        codec_setup_info *ci,
        oggpack_buffer *opb,
        CAkVorbisAllocator *VorbisAllocator)
{
  int v6; // esi
  int v7; // r14d
  int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // r8d
  char *pCurrentAddress; // rdx
  int v14; // ebp
  int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // r8d
  floor1class *v18; // rdx
  int v19; // ebp
  __int64 v20; // r14
  int v21; // esi
  __int64 v22; // rbx
  int v23; // eax
  int v24; // eax
  __int64 partitions; // rdx
  int v26; // r10d
  char *partitionclass; // rcx
  __int64 v28; // rax
  int v29; // ecx
  unsigned int v30; // ecx
  unsigned int v31; // r9d
  unsigned __int16 *v32; // r8
  unsigned int v33; // ecx
  unsigned int v34; // r8d
  char *v35; // rdx
  unsigned int v36; // ecx
  unsigned int v37; // r8d
  char *v38; // rdx
  unsigned int v39; // ecx
  unsigned int v40; // r8d
  char *v41; // rdx
  bool v42; // cc
  int v43; // r8d
  int v44; // r15d
  int v45; // ebp
  __int64 v46; // rbx
  int v47; // r12d
  __int64 v48; // r14
  __int64 v49; // rsi
  unsigned __int16 v50; // ax
  int v52; // edx
  int i; // ebp
  unsigned __int16 *postlist; // rdx
  __int64 v55; // r14
  int v56; // r9d
  int v57; // r10d
  char v58; // bl
  char v59; // si
  int v60; // r8d
  int j; // ecx
  int v62; // eax
  int v63; // [rsp+20h] [rbp-38h]
  int v64; // [rsp+60h] [rbp+8h]
  int v65; // [rsp+60h] [rbp+8h]

  v6 = -1;
  v7 = 0;
  v10 = oggpack_read(opb, 5);
  info->partitions = v10;
  if ( v10 && (v11 = (v10 + 3) & 0xFFFFFFFC, v12 = v11 + VorbisAllocator->CurrentSize, v12 <= VorbisAllocator->MaxSize) )
  {
    pCurrentAddress = VorbisAllocator->pCurrentAddress;
    VorbisAllocator->CurrentSize = v12;
    VorbisAllocator->pCurrentAddress = &pCurrentAddress[v11];
  }
  else
  {
    pCurrentAddress = 0i64;
  }
  v14 = 0;
  for ( info->partitionclass = pCurrentAddress; v14 < info->partitions; ++v14 )
  {
    info->partitionclass[v14] = oggpack_read(opb, 4);
    if ( v6 < info->partitionclass[v14] )
      v6 = info->partitionclass[v14];
  }
  v64 = v6 + 1;
  v15 = 11 * (v6 + 1);
  if ( v15 && (v16 = (v15 + 3) & 0xFFFFFFFC, v17 = v16 + VorbisAllocator->CurrentSize, v17 <= VorbisAllocator->MaxSize) )
  {
    v18 = (floor1class *)VorbisAllocator->pCurrentAddress;
    VorbisAllocator->CurrentSize = v17;
    VorbisAllocator->pCurrentAddress = &v18->class_dim + v16;
  }
  else
  {
    v18 = 0i64;
  }
  v19 = 0;
  info->Class = v18;
  if ( v6 + 1 > 0 )
  {
    while ( 1 )
    {
      v20 = v19;
      info->Class[v20].class_dim = oggpack_read(opb, 3) + 1;
      info->Class[v20].class_subs = oggpack_read(opb, 2);
      if ( opb->headend < 0 )
        return 0xFFFFFFFFi64;
      if ( info->Class[v20].class_subs )
      {
        info->Class[v20].class_book = oggpack_read(opb, 8);
        if ( (unsigned __int8)info->Class[v20].class_book >= ci->books )
          return 0xFFFFFFFFi64;
      }
      else
      {
        info->Class[v20].class_book = 0;
      }
      if ( (unsigned __int8)info->Class[v20].class_book >= ci->books )
        return 0xFFFFFFFFi64;
      v21 = 0;
      if ( 1 << info->Class[v20].class_subs > 0 )
      {
        v22 = 11i64 * v19;
        do
        {
          info->Class->class_subbook[v22] = oggpack_read(opb, 8) - 1;
          v23 = (unsigned __int8)info->Class->class_subbook[v22];
          if ( v23 >= ci->books && (_BYTE)v23 != 0xFF )
            return 0xFFFFFFFFi64;
          ++v21;
          ++v22;
        }
        while ( v21 < 1 << info->Class[v20].class_subs );
      }
      if ( ++v19 >= v64 )
      {
        v7 = 0;
        break;
      }
    }
  }
  info->mult = oggpack_read(opb, 2) + 1;
  v24 = oggpack_read(opb, 4);
  partitions = (unsigned int)info->partitions;
  v26 = v24;
  v65 = v24;
  if ( (int)partitions > 0 )
  {
    partitionclass = info->partitionclass;
    do
    {
      v28 = *partitionclass++;
      v7 += info->Class[v28].class_dim;
      --partitions;
    }
    while ( partitions );
  }
  v29 = 2 * (v7 + 2);
  if ( v29 && (v30 = (v29 + 3) & 0xFFFFFFFC, v31 = v30 + VorbisAllocator->CurrentSize, v31 <= VorbisAllocator->MaxSize) )
  {
    v32 = (unsigned __int16 *)VorbisAllocator->pCurrentAddress;
    VorbisAllocator->CurrentSize = v31;
    VorbisAllocator->pCurrentAddress = (char *)v32 + v30;
  }
  else
  {
    v32 = 0i64;
  }
  info->postlist = v32;
  if ( v7 == -2
    || (v33 = (v7 + 5) & 0xFFFFFFFC, v34 = v33 + VorbisAllocator->CurrentSize, v34 > VorbisAllocator->MaxSize) )
  {
    v35 = 0i64;
  }
  else
  {
    v35 = VorbisAllocator->pCurrentAddress;
    VorbisAllocator->CurrentSize = v34;
    VorbisAllocator->pCurrentAddress = &v35[v33];
  }
  info->forward_index = v35;
  if ( v7 && (v36 = (v7 + 3) & 0xFFFFFFFC, v37 = v36 + VorbisAllocator->CurrentSize, v37 <= VorbisAllocator->MaxSize) )
  {
    v38 = VorbisAllocator->pCurrentAddress;
    VorbisAllocator->CurrentSize = v37;
    VorbisAllocator->pCurrentAddress = &v38[v36];
  }
  else
  {
    v38 = 0i64;
  }
  info->loneighbor = v38;
  if ( v7 && (v39 = (v7 + 3) & 0xFFFFFFFC, v40 = v39 + VorbisAllocator->CurrentSize, v40 <= VorbisAllocator->MaxSize) )
  {
    v41 = VorbisAllocator->pCurrentAddress;
    VorbisAllocator->CurrentSize = v40;
    VorbisAllocator->pCurrentAddress = &v41[v39];
  }
  else
  {
    v41 = 0i64;
  }
  v42 = info->partitions <= 0;
  info->hineighbor = v41;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0i64;
  if ( !v42 )
  {
    v47 = __ROL4__(1, v26);
    while ( 1 )
    {
      v43 += info->Class[info->partitionclass[v44]].class_dim;
      v48 = v43;
      v63 = v43;
      if ( v46 < v43 )
        break;
LABEL_53:
      if ( ++v44 >= info->partitions )
        goto LABEL_54;
    }
    v49 = 2 * v46 + 4;
    while ( 1 )
    {
      v50 = oggpack_read(opb, v26);
      *(unsigned __int16 *)((char *)info->postlist + v49) = v50;
      if ( v50 >= v47 )
        return 0xFFFFFFFFi64;
      v26 = v65;
      ++v46;
      ++v45;
      v49 += 2i64;
      if ( v46 >= v48 )
      {
        v43 = v63;
        goto LABEL_53;
      }
    }
  }
LABEL_54:
  if ( opb->headend < 0 )
    return 0xFFFFFFFFi64;
  *info->postlist = 0;
  info->postlist[1] = 1 << v26;
  v52 = 0;
  for ( info->posts = v43 + 2; v52 < info->posts; ++v52 )
    info->forward_index[v52] = v52;
  mergesort(info->forward_index, info->postlist, info->posts);
  for ( i = 0; i < info->posts - 2; info->hineighbor[v55] = v59 )
  {
    postlist = info->postlist;
    v55 = i;
    v56 = postlist[1];
    v57 = postlist[i + 2];
    v58 = 0;
    v59 = 1;
    v60 = 0;
    for ( j = 0; j < i + 2; ++postlist )
    {
      v62 = *postlist;
      if ( v62 > v60 && v62 < v57 )
      {
        v58 = j;
        v60 = *postlist;
      }
      if ( v62 < v56 && v62 > v57 )
      {
        v59 = j;
        v56 = *postlist;
      }
      ++j;
    }
    ++i;
    info->loneighbor[v55] = v58;
  }
  return 0i64;
}

// File Line: 240
// RVA: 0xABF470
void __fastcall render_line(int x0, int x1, int y0, int y1, int *d)
{
  int v5; // r9d
  __int64 v6; // rbp
  __int64 v7; // rdi
  int v8; // r10d
  unsigned int v9; // r11d
  int v10; // eax
  bool v11; // sf
  __int64 v12; // rbx
  int v13; // r9d
  int v14; // ecx
  __int64 v15; // rdx
  unsigned int v16; // r11d
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
  __int64 v27; // rbx
  __int64 v28; // r9
  float *v29; // rax
  __m128i v30; // xmm0

  v5 = y1 - y0;
  v6 = x1;
  v7 = x0;
  v8 = x1 - x0;
  v9 = abs32(v5);
  v10 = v5 / (x1 - x0);
  v11 = v5 < 0;
  v12 = v10;
  v13 = v10 - 1;
  if ( !v11 )
    v13 = v10 + 1;
  v14 = 0;
  v15 = y0;
  v16 = v9 - abs32(v8 * v10);
  v17 = (int)v7 + 1;
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
        *((float *)v18 - 3) = _mm_cvtepi32_ps(v26).m128_f32[0] * fFLOOR_fromdB_LOOKUP[v15];
        --v19;
      }
      while ( v19 );
    }
    if ( v17 < v6 )
    {
      v27 = 4 * v12;
      v28 = 4i64 * v13;
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
        *(float *)&d[v17 - 1] = _mm_cvtepi32_ps(v30).m128_f32[0] * *v29;
      }
      while ( v17 < v6 );
    }
  }
}

// File Line: 276
// RVA: 0xABEEA0
int *__fastcall floor1_inverse1(vorbis_dsp_state *vd, vorbis_info_floor1 *info, int *fit_value)
{
  codebook *book_param; // rdi
  int v6; // r15d
  int *v7; // rsi
  unsigned int v8; // ebx
  int v9; // edx
  unsigned int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // eax
  __int64 v14; // rcx
  int v15; // edx
  int v16; // ebp
  int v17; // r8d
  int v18; // esi
  __int64 v19; // r15
  char class_subs; // r12
  __int64 class_dim; // rbp
  __int64 v22; // rdi
  __int64 v23; // rax
  int *v24; // rbx
  __int64 v25; // rdx
  int v26; // eax
  __int64 v28; // rdi
  __int64 v29; // rcx
  __int64 v30; // r8
  int v31; // ebx
  __int64 v32; // kr00_8
  int v33; // eax
  int v34; // ebx
  int v35; // eax
  int v36; // edx
  int v37; // ecx
  int v38; // eax
  __int64 v39; // rcx
  __int64 v40; // rcx
  int v41; // [rsp+20h] [rbp-68h]
  __int64 v42; // [rsp+28h] [rbp-60h]
  codebook *v43; // [rsp+30h] [rbp-58h]
  int v44; // [rsp+90h] [rbp+8h]
  int v45; // [rsp+98h] [rbp+10h]

  book_param = vd->csi->book_param;
  v6 = quant_look[info->mult - 1];
  v7 = fit_value;
  v43 = book_param;
  v41 = v6;
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
  v11 = oggpack_read(&vd->opb, v9);
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
  v13 = oggpack_read(&vd->opb, v12);
  v14 = 0i64;
  v15 = 0;
  v16 = 2;
  v7[1] = v13;
  v45 = 0;
  v42 = 0i64;
  v17 = 2;
  v44 = 2;
  if ( info->partitions > 0 )
  {
    do
    {
      v18 = 0;
      v19 = info->partitionclass[v14];
      class_subs = info->Class[v19].class_subs;
      class_dim = info->Class[v19].class_dim;
      if ( class_subs )
      {
        v18 = ak_vorbis_book_decode(&book_param[(unsigned __int8)info->Class[v19].class_book], &vd->opb);
        if ( v18 == -1 )
          return 0i64;
        v15 = v45;
        v17 = v44;
      }
      v22 = 0i64;
      if ( class_dim > 0 )
      {
        v23 = (1 << class_subs) - 1;
        v24 = &fit_value[v17];
        do
        {
          v25 = (unsigned __int8)info->Class[v19].class_subbook[v23 & v18];
          v18 >>= class_subs;
          if ( (_DWORD)v25 == 255 )
          {
            *v24 = 0;
          }
          else
          {
            v26 = ak_vorbis_book_decode(&v43[v25], &vd->opb);
            *v24 = v26;
            if ( v26 == -1 )
              return 0i64;
          }
          v23 = (1 << class_subs) - 1;
          ++v22;
          ++v24;
        }
        while ( v22 < class_dim );
        v15 = v45;
        v17 = v44;
      }
      book_param = v43;
      ++v15;
      v17 += class_dim;
      v14 = v42 + 1;
      v45 = v15;
      ++v42;
      v44 = v17;
    }
    while ( v15 < info->partitions );
    v7 = fit_value;
    v6 = v41;
    v16 = 2;
  }
  v28 = 2i64;
  if ( info->posts > 2 )
  {
    do
    {
      v29 = info->loneighbor[v28 - 2];
      v30 = info->hineighbor[v28 - 2];
      v31 = v7[v29] & 0x7FFF;
      v32 = (v7[v30] & 0x7FFF) - v31;
      v33 = (int)((info->postlist[v28] - info->postlist[v29]) * ((HIDWORD(v32) ^ v32) - HIDWORD(v32)))
          / (info->postlist[v30] - info->postlist[v29]);
      if ( (v7[v30] & 0x7FFF) - v31 >= 0 )
        v34 = v33 + v31;
      else
        v34 = v31 - v33;
      v35 = v7[v28];
      v36 = v6 - v34;
      if ( v35 )
      {
        v37 = v34;
        if ( v36 < v34 )
          v37 = v6 - v34;
        if ( v35 < 2 * v37 )
        {
          if ( (v35 & 1) != 0 )
            v38 = -((v35 + 1) >> 1);
          else
            v38 = v35 >> 1;
        }
        else if ( v36 <= v34 )
        {
          v38 = v36 - v35 - 1;
        }
        else
        {
          v38 = v35 - v34;
        }
        v7[v28] = v38 + v34;
        v39 = info->loneighbor[v28 - 2];
        v7[v39] &= 0x7FFFu;
        v40 = info->hineighbor[v28 - 2];
        v7[v40] &= 0x7FFFu;
      }
      else
      {
        v7[v28] = v34 | 0x8000;
      }
      ++v16;
      ++v28;
    }
    while ( v16 < info->posts );
  }
  return v7;
}

// File Line: 364
// RVA: 0xABF190
__int64 __fastcall floor1_inverse2(vorbis_dsp_state *vd, vorbis_info_floor1 *info, int *fit_value, int *out)
{
  int v7; // esi
  int v8; // r10d
  __int64 v9; // r14
  int i; // r8d
  __int64 v11; // rcx
  int v12; // ebx
  int v13; // ebx
  int v14; // edi

  if ( fit_value )
  {
    v7 = 1;
    v8 = 0;
    v9 = 1i64;
    for ( i = *fit_value * info->mult; v7 < info->posts; ++v9 )
    {
      v11 = info->forward_index[v9];
      v12 = fit_value[v11] & 0x7FFF;
      if ( v12 == fit_value[v11] )
      {
        v13 = info->mult * v12;
        v14 = info->postlist[v11];
        render_line(v8, v14, i, v13, out);
        v8 = v14;
        i = v13;
      }
      ++v7;
    }
    return 1i64;
  }
  else
  {
    memset(out, 0, (unsigned int)(4 * (vd->csi->blocksizes[vd->state.W] / 2)));
    return 0i64;
  }
}

