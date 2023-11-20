// File Line: 42
// RVA: 0xAC06E0
__int64 __fastcall decpack(int entry, int used_entry, int quantvals, codebook *b, oggpack_buffer *opb, int maptype)
{
  codebook *v6; // rsi
  int v7; // er9
  unsigned int v8; // edi
  int v9; // er11
  int v10; // er10
  int v11; // er9
  int v12; // er9
  __int64 result; // rax
  int v14; // ecx
  __int64 v15; // r8
  int v16; // edx
  int v17; // ecx
  __int64 v18; // r8
  __int64 v19; // rdx
  int i; // ebp
  int v21; // ebx

  v6 = b;
  v7 = b->dec_type;
  v8 = 0;
  v9 = quantvals;
  v10 = entry;
  if ( !v7 )
    return (unsigned int)entry;
  v11 = v7 - 1;
  if ( !v11 )
  {
    if ( maptype == 1 )
    {
      if ( v6->dim > 0 )
      {
        v17 = 0;
        v18 = (unsigned int)v6->dim;
        do
        {
          v19 = (unsigned int)(v10 >> 31);
          LODWORD(v19) = v10 % v9;
          v10 /= v9;
          LODWORD(v19) = *((unsigned __int16 *)v6->q_val + v19) << v17;
          v17 += v6->q_bits;
          v8 |= v19;
          --v18;
        }
        while ( v18 );
        return v8;
      }
    }
    else
    {
      for ( i = 0; i < v6->dim; v8 |= (unsigned int)oggpack_read(opb, v6->q_bits) << v21 )
        v21 = i++ * v6->q_bits;
    }
    return v8;
  }
  v12 = v11 - 1;
  if ( v12 )
  {
    if ( v12 == 1 )
      result = (unsigned int)used_entry;
    else
      result = 0i64;
  }
  else
  {
    if ( v6->dim > 0 )
    {
      v14 = 0;
      v15 = (unsigned int)v6->dim;
      do
      {
        v16 = v10 % v9 << v14;
        v14 += v6->q_pack;
        v10 /= v9;
        v8 |= v16;
        --v15;
      }
      while ( v15 );
    }
    result = v8;
  }
  return result;
}

// File Line: 127
// RVA: 0xAC02B0
signed __int64 __fastcall make_words(char *l, int n, unsigned int *r, int quantvals, codebook *b, oggpack_buffer *opb, int maptype)
{
  int v7; // er14
  signed int v8; // esi
  unsigned int *v9; // r15
  char *v10; // r13
  int v12; // eax
  int v13; // er10
  __int64 v14; // r13
  signed int v15; // ebx
  __int64 v16; // rdi
  unsigned int v17; // ebp
  unsigned int v18; // er9
  char v19; // r11
  __int64 v20; // r10
  int v21; // edx
  signed __int64 v22; // rcx
  int v23; // er14
  unsigned int v24; // eax
  __int64 v25; // rcx
  signed __int64 v26; // rdx
  int v27; // ecx
  int v28; // eax
  int v29; // er8
  signed int v30; // edx
  int *v31; // rax
  int v32; // er9
  int v33; // [rsp+30h] [rbp-D8h]
  int used_entry; // [rsp+34h] [rbp-D4h]
  int v35; // [rsp+40h] [rbp-C8h]
  int Dst[49]; // [rsp+44h] [rbp-C4h]
  char *v37; // [rsp+110h] [rbp+8h]
  int v38; // [rsp+118h] [rbp+10h]
  int quantvalsa; // [rsp+128h] [rbp+20h]

  quantvalsa = quantvals;
  v38 = n;
  v37 = l;
  v7 = 0;
  v8 = 0;
  v9 = r;
  v10 = l;
  used_entry = 0;
  if ( n < 2 )
  {
    *r = 2147483648;
    return 0i64;
  }
  v35 = 0;
  memset(Dst, 0, 0x80ui64);
  v12 = v38;
  v13 = 0;
  v33 = 0;
  if ( v38 <= 0 )
    return 0i64;
  while ( 1 )
  {
    v14 = *v10;
    if ( (_DWORD)v14 )
      break;
LABEL_29:
    ++v13;
    v10 = v37 + 1;
    v33 = v13;
    ++v37;
    if ( v13 >= v12 )
      return 0i64;
  }
  v15 = 0;
  v16 = v14;
  v17 = *(&v35 + v14);
  if ( !v7 || v17 )
  {
    v18 = v14 - 1;
    v19 = 0;
    if ( (signed int)v14 - 1 > 0 )
    {
      v19 = v14 - 1;
      v20 = v18;
      do
      {
        v21 = (v17 >> v18) & 1;
        if ( v15 < v8 )
        {
          v22 = v21 + 2i64 * v15;
          if ( !v9[v22] )
            v9[v22] = v8;
        }
        else
        {
          *(_QWORD *)&v9[2 * v15] = (unsigned int)++v8;
        }
        LOBYTE(v18) = v18 - 1;
        v15 = v9[v21 + 2i64 * v15];
        --v20;
      }
      while ( v20 );
      v13 = v33;
    }
    v23 = (v17 >> (v14 - v19 - 1)) & 1;
    if ( v15 >= v8 )
    {
      ++v8;
      v9[2 * v15 + 1] = 0;
    }
    v24 = decpack(v13, used_entry, quantvalsa, b, opb, maptype);
    v25 = v23;
    v7 = used_entry + 1;
    v26 = v25 + 2i64 * v15;
    ++used_entry;
    v27 = v14;
    v9[v26] = v24 | 0x80000000;
    if ( (signed int)v14 > 0 )
    {
      while ( 1 )
      {
        v28 = *(&v35 + v16);
        if ( v28 & 1 )
          break;
        --v16;
        --v27;
        Dst[v16] = v28 + 1;
        if ( v16 <= 0 )
          goto LABEL_24;
      }
      *(&v35 + v27) = 2 * *(&v35 + v27 - 1);
    }
LABEL_24:
    v29 = *(&v35 + v14);
    v30 = v14 + 1;
    if ( (signed int)v14 + 1 < 33 )
    {
      v31 = &v35 + v30;
      do
      {
        v32 = *v31;
        if ( (unsigned int)*v31 >> 1 != v17 )
          break;
        v29 *= 2;
        ++v30;
        ++v31;
        *(v31 - 1) = v29;
        v17 = v32;
      }
      while ( v30 < 33 );
    }
    v12 = v38;
    v13 = v33;
    goto LABEL_29;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 214
// RVA: 0xABFEA0
void __fastcall make_decode_table(codebook *s, char *lengthlist, int quantvals, oggpack_buffer *opb, int maptype, CAkVorbisAllocator *VorbisAllocator)
{
  int v6; // esi
  oggpack_buffer *v7; // r15
  int v8; // er12
  char *v9; // r13
  codebook *b; // rdi
  int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // edx
  unsigned int *v14; // r8
  int v15; // edx
  unsigned __int64 v16; // rcx
  signed __int64 v17; // rax
  signed __int64 v18; // rax
  void *v19; // rsp
  void *v20; // rsp
  unsigned int *v21; // rbx
  int v22; // ecx
  unsigned int v23; // ecx
  unsigned int v24; // edx
  char *v25; // r10
  bool v26; // zf
  __int64 v27; // rdx
  __int16 v28; // cx
  __int64 v29; // rdx
  char v30; // cl
  int v31; // ecx
  int v32; // er8
  int v33; // ecx
  __int64 v34; // rax
  unsigned int *v35; // r9
  unsigned __int64 v36; // r11
  int v37; // ecx
  char v38; // cl
  char v39; // cl
  char *v40; // r9
  char *v41; // r11
  char *v42; // r10
  unsigned int *v43; // rdx
  unsigned __int64 v44; // rdi
  int v45; // eax
  __int16 v46; // ax
  __int16 v47; // ax
  unsigned int r[8]; // [rsp+40h] [rbp+0h]

  v6 = 0;
  v7 = opb;
  v8 = quantvals;
  v9 = lengthlist;
  b = s;
  if ( s->dec_nodeb == 4 )
  {
    v11 = s->used_entries;
    if ( 8 * v11 == -4
      || (v12 = (8 * v11 + 7) & 0xFFFFFFFC, v13 = v12 + VorbisAllocator->CurrentSize, v13 > VorbisAllocator->MaxSize) )
    {
      v14 = 0i64;
    }
    else
    {
      v14 = (unsigned int *)VorbisAllocator->pCurrentAddress;
      VorbisAllocator->CurrentSize = v13;
      VorbisAllocator->pCurrentAddress = (char *)v14 + v12;
    }
    v15 = b->entries;
    b->dec_table = v14;
    make_words(v9, v15, v14, v8, b, opb, maptype);
  }
  v16 = 4i64 * (2 * b->used_entries - 2);
  v17 = v16 + 15;
  if ( v16 + 15 <= v16 )
    v17 = 1152921504606846960i64;
  v18 = v17 & 0xFFFFFFFFFFFFFFF0ui64;
  v19 = alloca(v18);
  v20 = alloca(v18);
  v21 = r;
  make_words(v9, b->entries, r, v8, b, v7, maptype);
  v22 = b->dec_nodeb * (b->used_entries * (b->dec_leafw + 1) - 2);
  if ( v22 && (v23 = (v22 + 3) & 0xFFFFFFFC, v24 = v23 + VorbisAllocator->CurrentSize, v24 <= VorbisAllocator->MaxSize) )
  {
    v25 = VorbisAllocator->pCurrentAddress;
    VorbisAllocator->CurrentSize = v24;
    VorbisAllocator->pCurrentAddress = &v25[v23];
  }
  else
  {
    v25 = 0i64;
  }
  v26 = b->dec_leafw == 1;
  b->dec_table = v25;
  if ( v26 )
  {
    if ( b->dec_nodeb == 1 )
    {
      v29 = 0i64;
      if ( 2 * b->used_entries - 2 > 0 )
      {
        do
        {
          v30 = HIBYTE(r[v29]);
          ++v6;
          ++v29;
          *((_BYTE *)b->dec_table + v29 - 1) = LOBYTE(r[v29 - 1]) | v30 & 0x80;
        }
        while ( v6 < 2 * b->used_entries - 2 );
      }
    }
    else if ( b->dec_nodeb == 2 && 2 * b->used_entries - 2 > 0 )
    {
      v27 = 0i64;
      do
      {
        v28 = *((_WORD *)v21 + 1);
        ++v6;
        ++v21;
        v27 += 2i64;
        *(_WORD *)((char *)b->dec_table + v27 - 2) = *((_WORD *)v21 - 2) | v28 & 0x8000;
      }
      while ( v6 < 2 * b->used_entries - 2 );
    }
  }
  else
  {
    v31 = b->used_entries;
    v32 = v31 + 2 * (v31 - 1);
    v33 = 2 * v31 - 4;
    v34 = v32;
    if ( b->dec_nodeb == 1 )
    {
      if ( v33 >= 0 )
      {
        v35 = &r[v33 + 1i64];
        v36 = (unsigned __int64)(unsigned int)(v33 + 2) >> 1;
        do
        {
          v37 = *(v35 - 1);
          if ( v37 >= 0 )
          {
            v39 = r[2 * v37];
            if ( (*v35 & 0x80000000) == 0 )
            {
              v34 -= 2i64;
              v32 -= 2;
              v25[v34] = v39;
              v25[v34 + 1] = r[2 * *v35];
            }
            else
            {
              v34 -= 3i64;
              v32 -= 3;
              v25[v34] = v39;
              v25[v34 + 1] = (*(_WORD *)v35 >> 8) | 0x80;
              v25[v34 + 2] = *(_BYTE *)v35;
            }
          }
          else
          {
            v38 = BYTE1(v37) | 0x80;
            if ( (*v35 & 0x80000000) == 0 )
            {
              v34 -= 3i64;
              v32 -= 3;
              v25[v34] = v38;
              v25[v34 + 1] = r[2 * *v35];
              v25[v34 + 2] = *((_BYTE *)v35 - 4);
            }
            else
            {
              v34 -= 4i64;
              v32 -= 4;
              v25[v34] = v38;
              v25[v34 + 1] = (*(_WORD *)v35 >> 8) | 0x80;
              v25[v34 + 2] = *((_BYTE *)v35 - 4);
              v25[v34 + 3] = *(_BYTE *)v35;
            }
          }
          *(v35 - 1) = v32;
          v35 -= 2;
          --v36;
        }
        while ( v36 );
      }
    }
    else if ( v33 >= 0 )
    {
      v40 = &v25[2 * v32];
      v41 = &v25[2 * (v32 + 2i64)];
      v42 = &v25[2 * v32 + 6];
      v43 = &r[v33 + 1i64];
      v44 = (unsigned __int64)(unsigned int)(v33 + 2) >> 1;
      do
      {
        v45 = *(v43 - 1);
        if ( v45 >= 0 )
        {
          v47 = r[2 * v45];
          if ( (*v43 & 0x80000000) == 0 )
          {
            v40 -= 4;
            v32 -= 2;
            v42 -= 4;
            *(_WORD *)v40 = v47;
            v41 -= 4;
            *((_WORD *)v40 + 1) = r[2 * *v43];
          }
          else
          {
            v40 -= 6;
            v41 -= 6;
            v32 -= 3;
            *(_WORD *)v40 = v47;
            v42 -= 6;
            *((_WORD *)v40 + 1) = *((_WORD *)v43 + 1) | 0x8000;
            *(_WORD *)v41 = *(_WORD *)v43;
          }
        }
        else
        {
          v46 = HIWORD(v45) | 0x8000;
          if ( (*v43 & 0x80000000) == 0 )
          {
            *((_WORD *)v40 - 3) = v46;
            v40 -= 6;
            v41 -= 6;
            v32 -= 3;
            v42 -= 6;
            *((_WORD *)v40 + 1) = r[2 * *v43];
            *(_WORD *)v41 = *((_WORD *)v43 - 2);
          }
          else
          {
            *((_WORD *)v40 - 4) = v46;
            v40 -= 8;
            v42 -= 8;
            v41 -= 8;
            v32 -= 4;
            *((_WORD *)v40 + 1) = *((_WORD *)v43 + 1) | 0x8000;
            *(_WORD *)v41 = *((_WORD *)v43 - 2);
            *(_WORD *)v42 = *(_WORD *)v43;
          }
        }
        *(v43 - 1) = v32;
        v43 -= 2;
        --v44;
      }
      while ( v44 );
    }
  }
}

// File Line: 380
// RVA: 0xAC0B90
void __fastcall vorbis_book_unpack(oggpack_buffer *opb, codebook *s, CAkVorbisAllocator *VorbisAllocator)
{
  int v3; // edi
  codebook *v4; // rbx
  CAkVorbisAllocator *v5; // rsi
  oggpack_buffer *v6; // r13
  int v7; // eax
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  void *v10; // rsp
  int v11; // er14
  int v12; // er12
  int v13; // esi
  char *v14; // rdi
  int v15; // eax
  int v16; // eax
  unsigned int v17; // er8
  int v18; // eax
  unsigned int m; // ecx
  signed int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int v23; // edx
  unsigned int n; // ecx
  int v25; // eax
  int ii; // eax
  int v27; // eax
  int v28; // edi
  char *v29; // rsi
  int v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // edi
  __int64 v34; // rsi
  int v35; // er14
  int v36; // edx
  unsigned int v37; // eax
  int v38; // eax
  int i; // ecx
  int v40; // eax
  int v41; // ecx
  unsigned int v42; // edx
  int v43; // eax
  int v44; // ecx
  int v45; // eax
  int v46; // ecx
  unsigned int v47; // edx
  int v48; // eax
  int v49; // ecx
  signed int v50; // er11
  int v51; // er10
  int v52; // ecx
  unsigned int v53; // eax
  int v54; // er9
  int v55; // edi
  int j; // er8
  signed int v57; // eax
  signed int v58; // ecx
  __int64 v59; // rdx
  unsigned int v60; // er15
  int v61; // ecx
  unsigned int v62; // edx
  unsigned __int64 v63; // rcx
  signed __int64 v64; // rcx
  void *v65; // rsp
  void *v66; // rsp
  signed __int64 v67; // rsi
  int v68; // eax
  signed int v69; // ecx
  signed int v70; // er9
  int v71; // eax
  int v72; // er8
  unsigned int v73; // eax
  int l; // ecx
  signed int v75; // eax
  int v76; // eax
  unsigned int v77; // ecx
  unsigned int v78; // er8
  char *v79; // rdx
  signed __int64 v80; // rsi
  unsigned int v81; // ecx
  unsigned int v82; // er8
  char *v83; // rdx
  signed __int64 v84; // rsi
  unsigned int v85; // ecx
  int v86; // eax
  int v87; // ecx
  unsigned int v88; // eax
  int v89; // er8
  int v90; // er9
  int v91; // eax
  signed int v92; // ecx
  int v93; // eax
  unsigned int v94; // eax
  int k; // ecx
  int v96; // eax
  int v97; // eax
  int v98; // ecx
  char v99[48]; // [rsp+30h] [rbp+0h]
  int maptype; // [rsp+78h] [rbp+48h]
  CAkVorbisAllocator *v101; // [rsp+80h] [rbp+50h]

  v101 = VorbisAllocator;
  v3 = 4;
  *(_QWORD *)&s->dim = 0i64;
  *(_QWORD *)&s->used_entries = 0i64;
  s->dec_table = 0i64;
  *(_QWORD *)&s->dec_nodeb = 0i64;
  *(_QWORD *)&s->dec_type = 0i64;
  *(_QWORD *)&s->q_minp = 0i64;
  *(_QWORD *)&s->q_delp = 0i64;
  *(_QWORD *)&s->q_pack = 0i64;
  v4 = s;
  s->q_val = 0i64;
  v5 = VorbisAllocator;
  v6 = opb;
  s->dim = oggpack_read(opb, 4);
  v7 = oggpack_read(v6, 14);
  v8 = v7;
  v4->entries = v7;
  v9 = v7 + 15i64;
  if ( v9 <= v8 )
    v9 = 1152921504606846960i64;
  v10 = alloca(v9);
  if ( (unsigned int)oggpack_read(v6, 1) )
  {
    v31 = oggpack_read(v6, 5);
    v32 = v4->entries;
    v12 = 0;
    v33 = 0;
    v34 = 0i64;
    v35 = v31 + 1;
    v4->used_entries = v32;
    if ( v32 > 0 )
    {
      do
      {
        v36 = 0;
        v37 = v4->entries - v33;
        if ( v4->entries != v33 )
        {
          do
          {
            ++v36;
            v37 >>= 1;
          }
          while ( v37 );
        }
        v38 = oggpack_read(v6, v36);
        for ( i = 0; i < v38; ++v34 )
        {
          if ( v33 >= v4->entries )
            break;
          ++i;
          v99[v34] = v35;
          ++v33;
        }
        v4->dec_maxlength = v35++;
      }
      while ( v33 < v4->entries );
    }
    goto LABEL_12;
  }
  v11 = oggpack_read(v6, 3);
  v12 = 0;
  if ( (unsigned int)oggpack_read(v6, 1) )
  {
    v13 = 0;
    if ( v4->entries <= 0 )
    {
LABEL_13:
      v5 = v101;
      goto LABEL_14;
    }
    v14 = v99;
    do
    {
      if ( (unsigned int)oggpack_read(v6, 1) )
      {
        v15 = oggpack_read(v6, v11);
        *v14 = v15 + 1;
        ++v4->used_entries;
        v16 = v15 + 1;
        if ( v16 > v4->dec_maxlength )
          v4->dec_maxlength = v16;
      }
      else
      {
        *v14 = 0;
      }
      ++v13;
      ++v14;
    }
    while ( v13 < v4->entries );
LABEL_12:
    v3 = 4;
    goto LABEL_13;
  }
  v27 = v4->entries;
  v28 = 0;
  v4->used_entries = v27;
  if ( v27 > 0 )
  {
    v29 = v99;
    do
    {
      v30 = (unsigned __int64)oggpack_read(v6, v11) + 1;
      *v29 = v30;
      if ( v30 > v4->dec_maxlength )
        v4->dec_maxlength = v30;
      ++v28;
      ++v29;
    }
    while ( v28 < v4->entries );
    goto LABEL_12;
  }
  v3 = 4;
LABEL_14:
  maptype = oggpack_read(v6, 1);
  if ( maptype )
  {
    v40 = oggpack_read(v6, 32);
    v41 = v40;
    v42 = v40 & 0x80000000;
    v43 = ((v40 >> 21) & 0x3FF) - 788;
    v4->q_minp = v43;
    v44 = v41 & 0x1FFFFF;
    if ( v44 )
    {
      if ( !_bittest(&v44, 0x1Eu) )
      {
        do
        {
          v44 *= 2;
          --v43;
        }
        while ( !_bittest(&v44, 0x1Eu) );
        v4->q_minp = v43;
      }
      if ( v42 )
        v44 = -v44;
    }
    else
    {
      v4->q_minp = -9999;
    }
    v4->q_min = v44;
    v45 = oggpack_read(v6, 32);
    v46 = v45;
    v47 = v45 & 0x80000000;
    v48 = ((v45 >> 21) & 0x3FF) - 788;
    v4->q_delp = v48;
    v49 = v46 & 0x1FFFFF;
    if ( v49 )
    {
      if ( !_bittest(&v49, 0x1Eu) )
      {
        do
        {
          v49 *= 2;
          --v48;
        }
        while ( !_bittest(&v49, 0x1Eu) );
        v4->q_delp = v48;
      }
      if ( v47 )
        v49 = -v49;
    }
    else
    {
      v4->q_delp = -9999;
    }
    v4->q_del = v49;
    v4->q_bits = (unsigned __int64)oggpack_read(v6, 4) + 1;
    oggpack_read(v6, 1);
    v50 = v4->q_bits;
    v51 = v4->entries;
    v4->q_delp += v50;
    v4->q_del >>= v50;
    v52 = 0;
    v53 = v51;
    if ( v51 )
    {
      do
      {
        ++v52;
        v53 >>= 1;
      }
      while ( v53 );
    }
    v54 = v4->dim;
    v55 = v51 >> (v52 - 1) * (v54 - 1) / v54;
    for ( j = v55 + 1; ; ++j )
    {
      while ( 1 )
      {
        v57 = 1;
        v58 = 1;
        if ( v54 > 0 )
        {
          v59 = (unsigned int)v4->dim;
          do
          {
            v57 *= v55;
            v58 *= j;
            --v59;
          }
          while ( v59 );
        }
        if ( v57 <= v51 )
          break;
        --v55;
        --j;
      }
      if ( v58 > v51 )
        break;
      ++v55;
    }
    v60 = v55 - 1;
    v61 = 0;
    v62 = v55 - 1;
    if ( v55 != 1 )
    {
      do
      {
        ++v61;
        v62 >>= 1;
      }
      while ( v62 );
    }
    if ( (v50 * v54 + 8) / 8 > 4 || (v50 * v54 + 8) / 8 > (v50 + 7) / 8 + (v61 * v54 + 8) / 8 )
    {
      if ( v50 > 8 )
      {
        if ( 2 * v55 && (v81 = (2 * v55 + 3) & 0xFFFFFFFC, v82 = v81 + v5->CurrentSize, v82 <= v5->MaxSize) )
        {
          v83 = v5->pCurrentAddress;
          v5->CurrentSize = v82;
          v5->pCurrentAddress = &v83[v81];
        }
        else
        {
          v83 = 0i64;
        }
        v4->q_val = v83;
        v84 = 0i64;
        if ( v55 > 0 )
        {
          do
            *((_WORD *)v4->q_val + ++v84 - 1) = oggpack_read(v6, v4->q_bits);
          while ( v84 < v55 );
        }
      }
      else
      {
        if ( v55 && (v77 = (v55 + 3) & 0xFFFFFFFC, v78 = v77 + v5->CurrentSize, v78 <= v5->MaxSize) )
        {
          v79 = v5->pCurrentAddress;
          v5->CurrentSize = v78;
          v5->pCurrentAddress = &v79[v77];
        }
        else
        {
          v79 = 0i64;
        }
        v4->q_val = v79;
        v80 = 0i64;
        if ( v55 > 0 )
        {
          do
            *((_BYTE *)v4->q_val + ++v80 - 1) = oggpack_read(v6, v4->q_bits);
          while ( v80 < v55 );
        }
      }
      v85 = v55 - 1;
      v86 = 0;
      if ( v55 != 1 )
      {
        do
        {
          ++v86;
          v85 >>= 1;
        }
        while ( v85 );
      }
      v4->q_pack = v86;
      v4->dec_type = 2;
      v87 = 0;
      v88 = v55 - 1;
      if ( v55 != 1 )
      {
        do
        {
          ++v87;
          v88 >>= 1;
        }
        while ( v88 );
      }
      v89 = v4->dim;
      v90 = 4;
      v91 = v87 * v4->dim;
      v92 = v4->used_entries;
      v93 = (v91 + 8) / 8;
      if ( v92 >= 2 )
      {
        if ( v93 == 3 )
          v93 = 4;
        v90 = v93;
        v94 = 3 * (v92 - 2);
        for ( k = 0; v94; v94 >>= 1 )
          ++k;
        if ( k + 1 <= 4 * v90 )
        {
          v96 = v90;
          v90 = 1;
          v97 = v96 / 2;
          if ( v97 )
            v90 = v97;
        }
      }
      v4->dec_nodeb = v90;
      v98 = 0;
      if ( v55 != 1 )
      {
        do
        {
          ++v98;
          v60 >>= 1;
        }
        while ( v60 );
      }
      LOBYTE(v12) = (v98 * v89 + 8) / 8 > v90;
      v4->dec_leafw = v12 + 1;
      make_decode_table(v4, v99, v55, v6, maptype, v101);
    }
    else
    {
      v63 = 2i64 * v55 + 15;
      if ( v63 <= 2i64 * v55 )
        v63 = 1152921504606846960i64;
      v64 = v63 & 0xFFFFFFFFFFFFFFF0ui64;
      v65 = alloca(v64);
      v66 = alloca(v64);
      v67 = 0i64;
      v4->q_val = v99;
      if ( v55 > 0 )
      {
        do
          *((_WORD *)v4->q_val + ++v67 - 1) = oggpack_read(v6, v4->q_bits);
        while ( v67 < v55 );
      }
      v68 = v4->dim;
      v69 = v4->used_entries;
      v4->dec_type = 1;
      v70 = 4;
      v71 = (v4->q_bits * v68 + 8) / 8;
      v72 = v71;
      if ( v69 >= 2 )
      {
        if ( v71 == 3 )
          v71 = 4;
        v70 = v71;
        v73 = 3 * (v69 - 2);
        for ( l = 0; v73; v73 >>= 1 )
          ++l;
        if ( l + 1 <= 4 * v70 )
        {
          v75 = v70;
          v70 = 1;
          v76 = v75 / 2;
          if ( v76 )
            v70 = v76;
        }
      }
      v4->dec_nodeb = v70;
      v4->dec_leafw = (v72 > v70) + 1;
      make_decode_table(v4, v99, v55, v6, maptype, v101);
      v4->q_val = 0i64;
    }
  }
  else
  {
    v17 = v4->entries;
    v18 = 0;
    for ( m = v17; m; m >>= 1 )
      ++v18;
    v20 = v4->used_entries;
    v21 = v18 / 8 + 1;
    if ( v20 >= 2 )
    {
      v22 = 3 * v20;
      v23 = 0;
      if ( v21 == 3 )
        v21 = 4;
      v3 = v21;
      for ( n = v22 - 6; n; n >>= 1 )
        ++v23;
      if ( v23 + 1 <= 4 * v21 )
      {
        v3 = 1;
        v25 = v21 / 2;
        if ( v25 )
          v3 = v25;
      }
    }
    v4->dec_nodeb = v3;
    for ( ii = 0; v17; v17 >>= 1 )
      ++ii;
    v4->dec_type = 0;
    v4->dec_leafw = (ii / 8 + 1 > v3) + 1;
    make_decode_table(v4, v99, 0, v6, 0, v5);
  }
}

// File Line: 546
// RVA: 0xAC0500
__int64 __fastcall decode_packed_entry_number(codebook *book, oggpack_buffer *b)
{
  int v2; // edi
  oggpack_buffer *v3; // rbp
  codebook *v4; // rsi
  signed int v5; // er14
  unsigned int v6; // ebx
  int v7; // eax
  int v8; // ecx
  int v9; // er9
  int v10; // eax
  int v11; // er8
  unsigned int v12; // ebx
  _BYTE *v13; // r11
  __int16 v14; // r10
  _WORD *v15; // rsi

  v2 = book->dec_maxlength;
  v3 = b;
  v4 = book;
  v5 = 0;
  v6 = 0;
  v7 = oggpack_look(b, book->dec_maxlength);
  v8 = v4->dec_nodeb;
  v9 = v7;
  v10 = v7 & 1;
  v11 = 0;
  if ( v8 != 1 )
  {
    if ( v8 == 2 )
    {
      if ( v4->dec_leafw == 1 )
      {
        if ( v2 > 0 )
        {
          while ( 1 )
          {
            LOWORD(v6) = *((_WORD *)v4->dec_table + v10 + 2 * v6);
            if ( v6 & 0x8000 )
              break;
            v9 >>= 1;
            ++v11;
            v10 = v9 & 1;
            if ( v11 >= v2 )
            {
              v12 = v6 & 0x7FFF;
              goto LABEL_34;
            }
          }
        }
        goto LABEL_15;
      }
      v15 = v4->dec_table;
      if ( v2 > 0 )
      {
        while ( !(v15[v10 + v6] & 0x8000) )
        {
          v9 >>= 1;
          ++v11;
          v6 = (unsigned __int16)v15[v10 + v6];
          v10 = v9 & 1;
          if ( v11 >= v2 )
            goto LABEL_33;
        }
        if ( !v10 || v15[v6] & 0x8000 )
          v5 = 1;
        v6 = ((unsigned __int16)v15[v10 + v6] << 16) | (unsigned __int16)v15[v5 + v10 + v6 + 1];
      }
    }
    else if ( v2 > 0 )
    {
      do
      {
        v6 = *((_DWORD *)v4->dec_table + v10 + 2 * v6);
        if ( (v6 & 0x80000000) != 0 )
          break;
        v9 >>= 1;
        ++v11;
        v10 = v9 & 1;
      }
      while ( v11 < v2 );
    }
LABEL_33:
    v12 = v6 & 0x7FFFFFFF;
    goto LABEL_34;
  }
  if ( v4->dec_leafw != 1 )
  {
    v13 = v4->dec_table;
    if ( v2 > 0 )
    {
      while ( 1 )
      {
        v14 = (unsigned __int8)v13[v10 + v6];
        if ( (v14 & 0x80u) != 0 )
          break;
        v9 >>= 1;
        ++v11;
        v6 = (unsigned __int8)v13[v10 + v6];
        v10 = v9 & 1;
        if ( v11 >= v2 )
        {
          v12 = v14 & 0x7FFF;
          goto LABEL_34;
        }
      }
      if ( !v10 || v13[v6] < 0 )
        v5 = 1;
      v6 = ((unsigned __int8)v13[v10 + v6] << 8) | (unsigned __int8)v13[v5 + 1 + v10 + v6];
    }
LABEL_15:
    v12 = v6 & 0x7FFF;
    goto LABEL_34;
  }
  if ( v2 > 0 )
  {
    do
    {
      LOBYTE(v6) = *((_BYTE *)v4->dec_table + 2 * v6 + v10);
      if ( (v6 & 0x80u) != 0 )
        break;
      v9 >>= 1;
      ++v11;
      v10 = v9 & 1;
    }
    while ( v11 < v2 );
  }
  v12 = v6 & 0x7F;
LABEL_34:
  oggpack_adv(v3, v11 + 1);
  return v12;
}

// File Line: 669
// RVA: 0xAC04F0
unsigned int __fastcall ak_vorbis_book_decode(codebook *book, oggpack_buffer *b)
{
  unsigned int result; // eax

  if ( book->dec_type )
    result = -1;
  else
    result = decode_packed_entry_number(book, b);
  return result;
}

// File Line: 766
// RVA: 0xAC07F0
void __fastcall vorbis_book_decodev_add(codebook *book, int *a, oggpack_buffer *b, int n, int point)
{
  oggpack_buffer *v5; // r13
  int *v6; // rbp
  codebook *v7; // r14
  __int64 v8; // rbx
  __int64 v9; // r15
  unsigned int v10; // eax
  __int64 v11; // rsi
  unsigned int v12; // edx
  int v13; // ecx
  __int64 v14; // r8
  int v15; // eax
  int v16; // ecx
  unsigned __int16 *v17; // r10
  signed int v18; // er9
  __int64 v19; // r8
  unsigned int v20; // eax
  __int64 v21; // r11
  int *v22; // r8
  __int64 v23; // rax
  __int64 v24; // r9
  __int64 v25; // rax
  int v26; // er9
  int v27; // ecx
  int v28; // er8
  int v29; // er9
  int v30; // er11
  signed int v31; // er10
  __int64 v32; // rdx
  int *v33; // rdx
  int v34; // eax
  int v35; // er8
  int v36; // eax
  __int64 v37; // rax
  int v38; // ecx
  int v39; // [rsp+1Ch] [rbp-4Ch]
  int v40[18]; // [rsp+20h] [rbp-48h]

  if ( n > 0 )
  {
    v5 = b;
    v6 = a;
    v7 = book;
    v8 = 0i64;
    v9 = n;
    do
    {
      v10 = decode_packed_entry_number(v7, v5);
      v11 = v7->dim;
      v12 = v10;
      if ( v7->dec_type == 1 )
      {
        v13 = v7->q_bits;
        v14 = 0i64;
        do
        {
          ++v14;
          v15 = v12 & ((1 << v13) - 1);
          v12 >>= v13;
          *(&v39 + v14) = v15;
        }
        while ( v14 < v11 );
      }
      else
      {
        v16 = v7->q_pack;
        v17 = (unsigned __int16 *)v7->q_val;
        v18 = 0;
        v19 = 0i64;
        v20 = (1 << v16) - 1;
        if ( v7->q_bits > 8 )
        {
          v24 = v20;
          do
          {
            v25 = v12;
            ++v19;
            v12 >>= v16;
            *(&v39 + v19) = v17[v24 & v25];
          }
          while ( v19 < v11 );
        }
        else
        {
          v21 = v20;
          v22 = v40;
          do
          {
            v23 = v12;
            ++v18;
            v12 >>= v16;
            ++v22;
            *(v22 - 1) = *((unsigned __int8 *)v17 + (v21 & v23));
          }
          while ( v18 < (signed int)v11 );
        }
      }
      v26 = v7->q_min;
      v27 = point - v7->q_minp;
      v28 = point - v7->q_delp;
      if ( point - v7->q_minp <= 0 )
        v29 = v26 << -(char)v27;
      else
        v29 = v26 >> v27;
      v30 = v7->q_del;
      v31 = 0;
      v32 = 0i64;
      if ( v28 <= 0 )
      {
        v35 = v7->q_delp - point;
        do
        {
          v36 = v40[v32++];
          *(&v39 + v32) = v29 + (v30 * v36 << v35);
        }
        while ( v32 < v11 );
      }
      else
      {
        v33 = v40;
        do
        {
          ++v31;
          v34 = *v33 * v30;
          ++v33;
          *(v33 - 1) = v29 + (v34 >> v28);
        }
        while ( v31 < (signed int)v11 );
      }
      v37 = 0i64;
      do
      {
        v38 = v40[v37++];
        v6[++v8 - 1] += v38;
      }
      while ( v37 < v11 );
    }
    while ( v8 < v9 );
  }
}

// File Line: 790
// RVA: 0xAC09A0
void __fastcall vorbis_book_decodevv_add_2ch(codebook *book, int **a, int offset, oggpack_buffer *b, int n, int point)
{
  int v6; // ebx
  int v7; // esi
  int v8; // er12
  int **v9; // r15
  codebook *i; // r14
  unsigned int v11; // eax
  __int64 v12; // rbp
  int v13; // er9
  signed int v14; // er8
  __int64 v15; // rdx
  int v16; // er9
  unsigned __int16 *v17; // r10
  signed int v18; // er8
  __int64 v19; // rdx
  int v20; // er11
  int *v21; // rdx
  int v22; // er9
  int v23; // ecx
  int v24; // er8
  int v25; // er9
  int v26; // er11
  signed int v27; // er10
  __int64 v28; // rdx
  int *v29; // rdx
  int v30; // eax
  int v31; // er8
  int v32; // eax
  __int64 v33; // r8
  int *v34; // rdx
  int v35; // [rsp+1Ch] [rbp-4Ch]
  int v36[18]; // [rsp+20h] [rbp-48h]
  oggpack_buffer *v37; // [rsp+88h] [rbp+20h]

  v37 = b;
  v6 = 0;
  v7 = offset;
  v8 = offset + n;
  v9 = a;
  for ( i = book; v7 < v8; b = v37 )
  {
    v11 = decode_packed_entry_number(i, b);
    v12 = i->dim;
    if ( i->dec_type == 1 )
    {
      v13 = i->q_bits;
      v14 = 1 << i->q_bits;
      v15 = 0i64;
      do
      {
        *(&v35 + ++v15) = v11 & (v14 - 1);
        v11 >>= v13;
      }
      while ( v15 < v12 );
    }
    else
    {
      v16 = i->q_pack;
      v17 = (unsigned __int16 *)i->q_val;
      v18 = 0;
      v19 = 0i64;
      v20 = (1 << i->q_pack) - 1;
      if ( i->q_bits > 8 )
      {
        do
        {
          *(&v35 + ++v19) = v17[v20 & v11];
          v11 >>= v16;
        }
        while ( v19 < v12 );
      }
      else
      {
        v21 = v36;
        do
        {
          ++v18;
          ++v21;
          *(v21 - 1) = *((unsigned __int8 *)v17 + (v20 & v11));
          v11 >>= v16;
        }
        while ( v18 < (signed int)v12 );
      }
    }
    v22 = i->q_min;
    v23 = point - i->q_minp;
    v24 = point - i->q_delp;
    if ( point - i->q_minp <= 0 )
      v25 = v22 << (LOBYTE(i->q_minp) - point);
    else
      v25 = v22 >> v23;
    v26 = i->q_del;
    v27 = 0;
    v28 = 0i64;
    if ( v24 <= 0 )
    {
      v31 = i->q_delp - point;
      do
      {
        v32 = v36[v28++];
        *(&v35 + v28) = v25 + (v26 * v32 << v31);
      }
      while ( v28 < v12 );
    }
    else
    {
      v29 = v36;
      do
      {
        v30 = *v29;
        ++v27;
        ++v29;
        *(v29 - 1) = v25 + (v26 * v30 >> v24);
      }
      while ( v27 < (signed int)v12 );
    }
    v33 = 0i64;
    do
    {
      ++v33;
      v34 = &v9[v6][v7];
      *v34 += *(&v35 + v33);
      v7 += v6 & 1;
      v6 = ((_BYTE)v6 - 1) & 1;
    }
    while ( v33 < v12 );
  }
}

