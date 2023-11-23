// File Line: 42
// RVA: 0xAC06E0
__int64 __fastcall decpack(
        unsigned int entry,
        unsigned int used_entry,
        int quantvals,
        codebook *b,
        oggpack_buffer *opb,
        int maptype)
{
  int dec_type; // r9d
  unsigned int v8; // edi
  int v10; // r10d
  int v11; // r9d
  int v12; // r9d
  int v14; // ecx
  __int64 v15; // r8
  int v16; // edx
  int v17; // ecx
  __int64 dim; // r8
  __int64 v19; // rdx
  int i; // ebp
  char v21; // bl

  dec_type = b->dec_type;
  v8 = 0;
  v10 = entry;
  if ( !dec_type )
    return entry;
  v11 = dec_type - 1;
  if ( !v11 )
  {
    if ( maptype == 1 )
    {
      if ( b->dim > 0 )
      {
        v17 = 0;
        dim = (unsigned int)b->dim;
        do
        {
          v19 = (unsigned int)(v10 >> 31);
          LODWORD(v19) = v10 % quantvals;
          v10 /= quantvals;
          LODWORD(v19) = *((unsigned __int16 *)b->q_val + v19) << v17;
          v17 += b->q_bits;
          v8 |= v19;
          --dim;
        }
        while ( dim );
        return v8;
      }
    }
    else
    {
      for ( i = 0; i < b->dim; v8 |= (unsigned int)oggpack_read(opb, b->q_bits) << v21 )
        v21 = i++ * b->q_bits;
    }
    return v8;
  }
  v12 = v11 - 1;
  if ( v12 )
  {
    if ( v12 == 1 )
      return used_entry;
    else
      return 0i64;
  }
  else
  {
    if ( b->dim > 0 )
    {
      v14 = 0;
      v15 = (unsigned int)b->dim;
      do
      {
        v16 = (v10 % quantvals) << v14;
        v14 += b->q_pack;
        v10 /= quantvals;
        v8 |= v16;
        --v15;
      }
      while ( v15 );
    }
    return v8;
  }
}

// File Line: 127
// RVA: 0xAC02B0
__int64 __fastcall make_words(
        char *l,
        int n,
        unsigned int *r,
        int quantvals,
        codebook *b,
        oggpack_buffer *opb,
        int maptype)
{
  int v7; // r14d
  signed int v8; // esi
  char *v10; // r13
  int v12; // eax
  int v13; // r10d
  __int64 v14; // r13
  signed int v15; // ebx
  __int64 v16; // rdi
  unsigned int v17; // ebp
  unsigned int v18; // r9d
  char v19; // r11
  __int64 v20; // r10
  int v21; // edx
  __int64 v22; // rcx
  int v23; // r14d
  unsigned int v24; // eax
  __int64 v25; // rcx
  __int64 v26; // rdx
  int v27; // ecx
  int v28; // eax
  int v29; // r8d
  int v30; // edx
  int *v31; // rax
  int v32; // r9d
  int v33; // [rsp+30h] [rbp-D8h]
  int used_entry; // [rsp+34h] [rbp-D4h]
  int v35; // [rsp+40h] [rbp-C8h] BYREF
  int Dst[49]; // [rsp+44h] [rbp-C4h] BYREF
  char *v37; // [rsp+110h] [rbp+8h]

  v37 = l;
  v7 = 0;
  v8 = 0;
  v10 = l;
  used_entry = 0;
  if ( n < 2 )
  {
    *r = 0x80000000;
    return 0i64;
  }
  v35 = 0;
  memset(Dst, 0, 0x80ui64);
  v12 = n;
  v13 = 0;
  v33 = 0;
  if ( n <= 0 )
    return 0i64;
  while ( 1 )
  {
    v14 = *v10;
    if ( (_DWORD)v14 )
      break;
LABEL_28:
    ++v13;
    v10 = v37 + 1;
    v33 = v13;
    ++v37;
    if ( v13 >= v12 )
      return 0i64;
  }
  v15 = 0;
  v16 = v14;
  v17 = Dst[v14 - 1];
  if ( !v7 || v17 )
  {
    v18 = v14 - 1;
    v19 = 0;
    if ( (int)v14 - 1 > 0 )
    {
      v19 = v14 - 1;
      v20 = v18;
      do
      {
        v21 = (v17 >> v18) & 1;
        if ( v15 < v8 )
        {
          v22 = v21 + 2i64 * v15;
          if ( !r[v22] )
            r[v22] = v8;
        }
        else
        {
          *(_QWORD *)&r[2 * v15] = (unsigned int)++v8;
        }
        LOBYTE(v18) = v18 - 1;
        v15 = r[2 * v15 + v21];
        --v20;
      }
      while ( v20 );
      v13 = v33;
    }
    v23 = (v17 >> (v14 - v19 - 1)) & 1;
    if ( v15 >= v8 )
    {
      ++v8;
      r[2 * v15 + 1] = 0;
    }
    v24 = decpack(v13, used_entry, quantvals, b, opb, maptype);
    v25 = v23;
    v7 = used_entry + 1;
    v26 = v25 + 2i64 * v15;
    ++used_entry;
    v27 = v14;
    r[v26] = v24 | 0x80000000;
    if ( (int)v14 > 0 )
    {
      while ( 1 )
      {
        v28 = Dst[v16 - 1];
        if ( (v28 & 1) != 0 )
          break;
        --v16;
        --v27;
        Dst[v16] = v28 + 1;
        if ( v16 <= 0 )
          goto LABEL_23;
      }
      Dst[v27 - 1] = 2 * Dst[v27 - 2];
    }
LABEL_23:
    v29 = Dst[v14 - 1];
    v30 = v14 + 1;
    if ( (int)v14 + 1 < 33 )
    {
      v31 = &Dst[v30 - 1];
      do
      {
        v32 = *v31;
        if ( (unsigned int)*v31 >> 1 != v17 )
          break;
        v29 *= 2;
        ++v30;
        *v31++ = v29;
        v17 = v32;
      }
      while ( v30 < 33 );
    }
    v12 = n;
    v13 = v33;
    goto LABEL_28;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 214
// RVA: 0xABFEA0
void __fastcall make_decode_table(
        codebook *s,
        char *lengthlist,
        int quantvals,
        oggpack_buffer *opb,
        int maptype,
        CAkVorbisAllocator *VorbisAllocator)
{
  int v6; // esi
  int used_entries; // eax
  unsigned int v12; // ecx
  unsigned int v13; // edx
  char *pCurrentAddress; // r8
  int entries; // edx
  unsigned __int64 v16; // rcx
  __int64 v17; // rax
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
  int v32; // r8d
  int v33; // ecx
  __int64 v34; // rax
  unsigned int *v35; // r9
  unsigned __int64 v36; // r11
  int v37; // ecx
  char v38; // cl
  char v39; // cl
  char *v40; // r9
  char *v41; // r11
  _WORD *v42; // r10
  unsigned int *v43; // rdx
  unsigned __int64 v44; // rdi
  int v45; // eax
  __int16 v46; // ax
  __int16 v47; // ax
  unsigned int r[8]; // [rsp+40h] [rbp+0h] BYREF

  v6 = 0;
  if ( s->dec_nodeb == 4 )
  {
    used_entries = s->used_entries;
    if ( 8 * used_entries == -4
      || (v12 = (8 * used_entries + 7) & 0xFFFFFFFC,
          v13 = v12 + VorbisAllocator->CurrentSize,
          v13 > VorbisAllocator->MaxSize) )
    {
      pCurrentAddress = 0i64;
    }
    else
    {
      pCurrentAddress = VorbisAllocator->pCurrentAddress;
      VorbisAllocator->CurrentSize = v13;
      VorbisAllocator->pCurrentAddress = &pCurrentAddress[v12];
    }
    entries = s->entries;
    s->dec_table = pCurrentAddress;
    make_words(lengthlist, entries, (unsigned int *)pCurrentAddress, quantvals, s, opb, maptype);
  }
  v16 = 4i64 * (2 * s->used_entries - 2);
  v17 = v16 + 15;
  if ( v16 + 15 <= v16 )
    v17 = 0xFFFFFFFFFFFFFF0i64;
  v18 = v17 & 0xFFFFFFFFFFFFFFF0ui64;
  v19 = alloca(v18);
  v20 = alloca(v18);
  v21 = r;
  make_words(lengthlist, s->entries, r, quantvals, s, opb, maptype);
  v22 = s->dec_nodeb * (s->used_entries * (s->dec_leafw + 1) - 2);
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
  v26 = s->dec_leafw == 1;
  s->dec_table = v25;
  if ( v26 )
  {
    if ( s->dec_nodeb == 1 )
    {
      v29 = 0i64;
      if ( 2 * s->used_entries - 2 > 0 )
      {
        do
        {
          v30 = HIBYTE(r[v29]);
          ++v6;
          ++v29;
          *((_BYTE *)s->dec_table + v29 - 1) = LOBYTE(r[v29 - 1]) | v30 & 0x80;
        }
        while ( v6 < 2 * s->used_entries - 2 );
      }
    }
    else if ( s->dec_nodeb == 2 && 2 * s->used_entries - 2 > 0 )
    {
      v27 = 0i64;
      do
      {
        v28 = *((_WORD *)v21 + 1);
        ++v6;
        ++v21;
        v27 += 2i64;
        *(_WORD *)((char *)s->dec_table + v27 - 2) = *((_WORD *)v21 - 2) | v28 & 0x8000;
      }
      while ( v6 < 2 * s->used_entries - 2 );
    }
  }
  else
  {
    v31 = s->used_entries;
    v32 = v31 + 2 * (v31 - 1);
    v33 = 2 * v31 - 4;
    v34 = v32;
    if ( s->dec_nodeb == 1 )
    {
      if ( v33 >= 0 )
      {
        v35 = &r[v33 + 1];
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
              v25[v34 + 1] = BYTE1(*v35) | 0x80;
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
              v25[v34 + 1] = BYTE1(*v35) | 0x80;
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
      v41 = &v25[2 * v32 + 4];
      v42 = v40 + 6;
      v43 = &r[v33 + 1];
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
            v42 -= 2;
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
            v42 -= 3;
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
            v42 -= 3;
            *((_WORD *)v40 + 1) = r[2 * *v43];
            *(_WORD *)v41 = *((_WORD *)v43 - 2);
          }
          else
          {
            *((_WORD *)v40 - 4) = v46;
            v40 -= 8;
            v42 -= 4;
            v41 -= 8;
            v32 -= 4;
            *((_WORD *)v40 + 1) = *((_WORD *)v43 + 1) | 0x8000;
            *(_WORD *)v41 = *((_WORD *)v43 - 2);
            *v42 = *(_WORD *)v43;
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
  CAkVorbisAllocator *v5; // rsi
  int v7; // eax
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  void *v10; // rsp
  int v11; // r14d
  int v12; // r12d
  int v13; // esi
  char *v14; // rdi
  int v15; // eax
  int v16; // eax
  unsigned int v17; // r8d
  int v18; // eax
  unsigned int kk; // ecx
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int v23; // edx
  unsigned int mm; // ecx
  int v25; // eax
  int nn; // eax
  int v27; // eax
  int v28; // edi
  char *v29; // rsi
  int v30; // eax
  int v31; // eax
  int entries; // ecx
  int v33; // edi
  __int64 v34; // rsi
  int v35; // r14d
  int v36; // edx
  unsigned int i; // eax
  int v38; // eax
  int j; // ecx
  int v40; // ecx
  unsigned int v41; // edx
  int v42; // eax
  int v43; // ecx
  int v44; // ecx
  unsigned int v45; // edx
  int v46; // eax
  int v47; // ecx
  int q_bits; // r11d
  int v49; // r10d
  int v50; // ecx
  unsigned int v51; // eax
  int dim; // r9d
  int v53; // edi
  int k; // r8d
  int v55; // eax
  int v56; // ecx
  __int64 v57; // rdx
  unsigned int v58; // r15d
  int v59; // ecx
  unsigned int v60; // edx
  unsigned __int64 v61; // rcx
  signed __int64 v62; // rcx
  void *v63; // rsp
  void *v64; // rsp
  __int64 v65; // rsi
  int v66; // eax
  int v67; // ecx
  int v68; // r9d
  int v69; // eax
  int v70; // r8d
  unsigned int v71; // eax
  int jj; // ecx
  int v73; // eax
  int v74; // eax
  unsigned int v75; // ecx
  unsigned int v76; // r8d
  char *v77; // rdx
  __int64 n; // rsi
  unsigned int v79; // ecx
  unsigned int v80; // r8d
  char *pCurrentAddress; // rdx
  __int64 m; // rsi
  unsigned int v83; // ecx
  int v84; // eax
  int v85; // ecx
  unsigned int v86; // eax
  int v87; // r8d
  int v88; // r9d
  int v89; // eax
  int used_entries; // ecx
  int v91; // eax
  unsigned int v92; // eax
  int ii; // ecx
  int v94; // eax
  int v95; // eax
  int v96; // ecx
  char v97[48]; // [rsp+30h] [rbp+0h] BYREF
  int maptype; // [rsp+78h] [rbp+48h]

  v3 = 4;
  *(_QWORD *)&s->dim = 0i64;
  *(_QWORD *)&s->used_entries = 0i64;
  s->dec_table = 0i64;
  *(_QWORD *)&s->dec_nodeb = 0i64;
  *(_QWORD *)&s->dec_type = 0i64;
  *(_QWORD *)&s->q_minp = 0i64;
  *(_QWORD *)&s->q_delp = 0i64;
  *(_QWORD *)&s->q_pack = 0i64;
  s->q_val = 0i64;
  v5 = VorbisAllocator;
  s->dim = oggpack_read(opb, 4);
  v7 = oggpack_read(opb, 14);
  v8 = v7;
  s->entries = v7;
  v9 = v7 + 15i64;
  if ( v9 <= v8 )
    v9 = 0xFFFFFFFFFFFFFF0i64;
  v10 = alloca(v9 & 0xFFFFFFFFFFFFFFF0ui64);
  if ( (unsigned int)oggpack_read(opb, 1) )
  {
    v31 = oggpack_read(opb, 5);
    entries = s->entries;
    v12 = 0;
    v33 = 0;
    v34 = 0i64;
    v35 = v31 + 1;
    s->used_entries = entries;
    if ( entries > 0 )
    {
      do
      {
        v36 = 0;
        for ( i = s->entries - v33; i; i >>= 1 )
          ++v36;
        v38 = oggpack_read(opb, v36);
        for ( j = 0; j < v38; ++v34 )
        {
          if ( v33 >= s->entries )
            break;
          ++j;
          v97[v34] = v35;
          ++v33;
        }
        s->dec_maxlength = v35++;
      }
      while ( v33 < s->entries );
    }
    goto LABEL_12;
  }
  v11 = oggpack_read(opb, 3);
  v12 = 0;
  if ( (unsigned int)oggpack_read(opb, 1) )
  {
    v13 = 0;
    if ( s->entries <= 0 )
    {
LABEL_13:
      v5 = VorbisAllocator;
      goto LABEL_14;
    }
    v14 = v97;
    do
    {
      if ( (unsigned int)oggpack_read(opb, 1) )
      {
        v15 = oggpack_read(opb, v11);
        *v14 = v15 + 1;
        ++s->used_entries;
        v16 = v15 + 1;
        if ( v16 > s->dec_maxlength )
          s->dec_maxlength = v16;
      }
      else
      {
        *v14 = 0;
      }
      ++v13;
      ++v14;
    }
    while ( v13 < s->entries );
LABEL_12:
    v3 = 4;
    goto LABEL_13;
  }
  v27 = s->entries;
  v28 = 0;
  s->used_entries = v27;
  if ( v27 > 0 )
  {
    v29 = v97;
    do
    {
      v30 = oggpack_read(opb, v11) + 1;
      *v29 = v30;
      if ( v30 > s->dec_maxlength )
        s->dec_maxlength = v30;
      ++v28;
      ++v29;
    }
    while ( v28 < s->entries );
    goto LABEL_12;
  }
  v3 = 4;
LABEL_14:
  maptype = oggpack_read(opb, 1);
  if ( maptype )
  {
    v40 = oggpack_read(opb, 32);
    v41 = v40 & 0x80000000;
    v42 = ((v40 >> 21) & 0x3FF) - 788;
    s->q_minp = v42;
    v43 = v40 & 0x1FFFFF;
    if ( v43 )
    {
      if ( (v43 & 0x40000000) == 0 )
      {
        do
        {
          v43 *= 2;
          --v42;
        }
        while ( (v43 & 0x40000000) == 0 );
        s->q_minp = v42;
      }
      if ( v41 )
        v43 = -v43;
    }
    else
    {
      s->q_minp = -9999;
    }
    s->q_min = v43;
    v44 = oggpack_read(opb, 32);
    v45 = v44 & 0x80000000;
    v46 = ((v44 >> 21) & 0x3FF) - 788;
    s->q_delp = v46;
    v47 = v44 & 0x1FFFFF;
    if ( v47 )
    {
      if ( (v47 & 0x40000000) == 0 )
      {
        do
        {
          v47 *= 2;
          --v46;
        }
        while ( (v47 & 0x40000000) == 0 );
        s->q_delp = v46;
      }
      if ( v45 )
        v47 = -v47;
    }
    else
    {
      s->q_delp = -9999;
    }
    s->q_del = v47;
    s->q_bits = oggpack_read(opb, 4) + 1;
    oggpack_read(opb, 1);
    q_bits = s->q_bits;
    v49 = s->entries;
    s->q_delp += q_bits;
    s->q_del >>= q_bits;
    v50 = 0;
    v51 = v49;
    if ( v49 )
    {
      do
      {
        ++v50;
        v51 >>= 1;
      }
      while ( v51 );
    }
    dim = s->dim;
    v53 = v49 >> ((v50 - 1) * (dim - 1) / dim);
    for ( k = v53 + 1; ; ++k )
    {
      while ( 1 )
      {
        v55 = 1;
        v56 = 1;
        if ( dim > 0 )
        {
          v57 = (unsigned int)s->dim;
          do
          {
            v55 *= v53;
            v56 *= k;
            --v57;
          }
          while ( v57 );
        }
        if ( v55 <= v49 )
          break;
        --v53;
        --k;
      }
      if ( v56 > v49 )
        break;
      ++v53;
    }
    v58 = v53 - 1;
    v59 = 0;
    v60 = v53 - 1;
    if ( v53 != 1 )
    {
      do
      {
        ++v59;
        v60 >>= 1;
      }
      while ( v60 );
    }
    if ( (q_bits * dim + 8) / 8 > 4 || (q_bits * dim + 8) / 8 > (q_bits + 7) / 8 + (v59 * dim + 8) / 8 )
    {
      if ( q_bits > 8 )
      {
        if ( 2 * v53 && (v79 = (2 * v53 + 3) & 0xFFFFFFFC, v80 = v79 + v5->CurrentSize, v80 <= v5->MaxSize) )
        {
          pCurrentAddress = v5->pCurrentAddress;
          v5->CurrentSize = v80;
          v5->pCurrentAddress = &pCurrentAddress[v79];
        }
        else
        {
          pCurrentAddress = 0i64;
        }
        s->q_val = pCurrentAddress;
        for ( m = 0i64; m < v53; *((_WORD *)s->q_val + m - 1) = oggpack_read(opb, s->q_bits) )
          ++m;
      }
      else
      {
        if ( v53 && (v75 = (v53 + 3) & 0xFFFFFFFC, v76 = v75 + v5->CurrentSize, v76 <= v5->MaxSize) )
        {
          v77 = v5->pCurrentAddress;
          v5->CurrentSize = v76;
          v5->pCurrentAddress = &v77[v75];
        }
        else
        {
          v77 = 0i64;
        }
        s->q_val = v77;
        for ( n = 0i64; n < v53; *((_BYTE *)s->q_val + n++) = oggpack_read(opb, s->q_bits) )
          ;
      }
      v83 = v53 - 1;
      v84 = 0;
      if ( v53 != 1 )
      {
        do
        {
          ++v84;
          v83 >>= 1;
        }
        while ( v83 );
      }
      s->q_pack = v84;
      s->dec_type = 2;
      v85 = 0;
      v86 = v53 - 1;
      if ( v53 != 1 )
      {
        do
        {
          ++v85;
          v86 >>= 1;
        }
        while ( v86 );
      }
      v87 = s->dim;
      v88 = 4;
      v89 = v85 * s->dim;
      used_entries = s->used_entries;
      v91 = (v89 + 8) / 8;
      if ( used_entries >= 2 )
      {
        if ( v91 == 3 )
          v91 = 4;
        v88 = v91;
        v92 = 3 * (used_entries - 2);
        for ( ii = 0; v92; v92 >>= 1 )
          ++ii;
        if ( ii + 1 <= 4 * v88 )
        {
          v94 = v88;
          v88 = 1;
          v95 = v94 / 2;
          if ( v95 )
            v88 = v95;
        }
      }
      s->dec_nodeb = v88;
      v96 = 0;
      if ( v53 != 1 )
      {
        do
        {
          ++v96;
          v58 >>= 1;
        }
        while ( v58 );
      }
      LOBYTE(v12) = (v96 * v87 + 8) / 8 > v88;
      s->dec_leafw = v12 + 1;
      make_decode_table(s, v97, v53, opb, maptype, VorbisAllocator);
    }
    else
    {
      v61 = 2i64 * v53 + 15;
      if ( v61 <= 2i64 * v53 )
        v61 = 0xFFFFFFFFFFFFFF0i64;
      v62 = v61 & 0xFFFFFFFFFFFFFFF0ui64;
      v63 = alloca(v62);
      v64 = alloca(v62);
      v65 = 0i64;
      for ( s->q_val = v97; v65 < v53; *((_WORD *)s->q_val + v65 - 1) = oggpack_read(opb, s->q_bits) )
        ++v65;
      v66 = s->dim;
      v67 = s->used_entries;
      s->dec_type = 1;
      v68 = 4;
      v69 = (s->q_bits * v66 + 8) / 8;
      v70 = v69;
      if ( v67 >= 2 )
      {
        if ( v69 == 3 )
          v69 = 4;
        v68 = v69;
        v71 = 3 * (v67 - 2);
        for ( jj = 0; v71; v71 >>= 1 )
          ++jj;
        if ( jj + 1 <= 4 * v68 )
        {
          v73 = v68;
          v68 = 1;
          v74 = v73 / 2;
          if ( v74 )
            v68 = v74;
        }
      }
      s->dec_nodeb = v68;
      s->dec_leafw = (v70 > v68) + 1;
      make_decode_table(s, v97, v53, opb, maptype, VorbisAllocator);
      s->q_val = 0i64;
    }
  }
  else
  {
    v17 = s->entries;
    v18 = 0;
    for ( kk = v17; kk; kk >>= 1 )
      ++v18;
    v20 = s->used_entries;
    v21 = v18 / 8 + 1;
    if ( v20 >= 2 )
    {
      v22 = 3 * v20;
      v23 = 0;
      if ( v21 == 3 )
        v21 = 4;
      v3 = v21;
      for ( mm = v22 - 6; mm; mm >>= 1 )
        ++v23;
      if ( v23 + 1 <= 4 * v21 )
      {
        v3 = 1;
        v25 = v21 / 2;
        if ( v25 )
          v3 = v25;
      }
    }
    s->dec_nodeb = v3;
    for ( nn = 0; v17; v17 >>= 1 )
      ++nn;
    s->dec_type = 0;
    s->dec_leafw = (nn / 8 + 1 > v3) + 1;
    make_decode_table(s, v97, 0, opb, 0, v5);
  }
}

// File Line: 546
// RVA: 0xAC0500
__int64 __fastcall decode_packed_entry_number(codebook *book, oggpack_buffer *b)
{
  int dec_maxlength; // edi
  int v5; // r14d
  int v6; // ebx
  int v7; // eax
  int dec_nodeb; // ecx
  int v9; // r9d
  int v10; // eax
  int v11; // r8d
  unsigned int v12; // ebx
  char *v13; // r11
  __int16 v14; // r10
  _WORD *dec_table; // rsi
  int v16; // r10d

  dec_maxlength = book->dec_maxlength;
  v5 = 0;
  v6 = 0;
  v7 = oggpack_look(b, dec_maxlength);
  dec_nodeb = book->dec_nodeb;
  v9 = v7;
  v10 = v7 & 1;
  v11 = 0;
  if ( dec_nodeb != 1 )
  {
    if ( dec_nodeb == 2 )
    {
      if ( book->dec_leafw == 1 )
      {
        if ( dec_maxlength > 0 )
        {
          while ( 1 )
          {
            LOWORD(v6) = *((_WORD *)book->dec_table + (unsigned int)(v10 + 2 * v6));
            if ( (v6 & 0x8000) != 0 )
              break;
            v9 >>= 1;
            ++v11;
            v10 = v9 & 1;
            if ( v11 >= dec_maxlength )
            {
              v12 = v6 & 0x7FFF;
              goto LABEL_34;
            }
          }
        }
        goto LABEL_15;
      }
      dec_table = book->dec_table;
      if ( dec_maxlength > 0 )
      {
        while ( 1 )
        {
          v16 = (unsigned __int16)dec_table[v10 + v6];
          if ( (v16 & 0x8000) != 0 )
            break;
          v9 >>= 1;
          ++v11;
          v6 = (unsigned __int16)dec_table[v10 + v6];
          v10 = v9 & 1;
          if ( v11 >= dec_maxlength )
            goto LABEL_33;
        }
        if ( !v10 || (dec_table[v6] & 0x8000) != 0 )
          v5 = 1;
        v6 = (v16 << 16) | (unsigned __int16)dec_table[v5 + v10 + v6 + 1];
      }
    }
    else if ( dec_maxlength > 0 )
    {
      do
      {
        v6 = *((_DWORD *)book->dec_table + (unsigned int)(v10 + 2 * v6));
        if ( v6 < 0 )
          break;
        v9 >>= 1;
        ++v11;
        v10 = v9 & 1;
      }
      while ( v11 < dec_maxlength );
    }
LABEL_33:
    v12 = v6 & 0x7FFFFFFF;
    goto LABEL_34;
  }
  if ( book->dec_leafw != 1 )
  {
    v13 = (char *)book->dec_table;
    if ( dec_maxlength > 0 )
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
        if ( v11 >= dec_maxlength )
        {
          v12 = v14 & 0x7FFF;
          goto LABEL_34;
        }
      }
      if ( !v10 || v13[v6] < 0 )
        v5 = 1;
      LOWORD(v6) = (v14 << 8) | (unsigned __int8)v13[v5 + v10 + v6 + 1];
    }
LABEL_15:
    v12 = v6 & 0x7FFF;
    goto LABEL_34;
  }
  if ( dec_maxlength > 0 )
  {
    do
    {
      LOBYTE(v6) = *((_BYTE *)book->dec_table + (unsigned int)(v10 + 2 * v6));
      if ( (v6 & 0x80u) != 0 )
        break;
      v9 >>= 1;
      ++v11;
      v10 = v9 & 1;
    }
    while ( v11 < dec_maxlength );
  }
  v12 = v6 & 0x7F;
LABEL_34:
  oggpack_adv(b, v11 + 1);
  return v12;
}

// File Line: 669
// RVA: 0xAC04F0
unsigned int __fastcall ak_vorbis_book_decode(codebook *book, oggpack_buffer *b)
{
  if ( book->dec_type )
    return -1;
  else
    return decode_packed_entry_number(book, b);
}

// File Line: 766
// RVA: 0xAC07F0
void __fastcall vorbis_book_decodev_add(codebook *book, int *a, oggpack_buffer *b, int n, int point)
{
  __int64 v8; // rbx
  __int64 v9; // r15
  unsigned int v10; // eax
  __int64 dim; // rsi
  unsigned int v12; // edx
  int q_bits; // ecx
  __int64 v14; // r8
  int v15; // eax
  int q_pack; // ecx
  unsigned __int16 *q_val; // r10
  int v18; // r9d
  __int64 v19; // r8
  unsigned int v20; // eax
  __int64 v21; // r11
  int *v22; // r8
  __int64 v23; // rax
  __int64 v24; // r9
  __int64 v25; // rax
  int q_min; // r9d
  int v27; // ecx
  int v28; // r8d
  int v29; // r9d
  int q_del; // r11d
  int v31; // r10d
  __int64 v32; // rdx
  int *v33; // rdx
  int v34; // eax
  int v35; // r8d
  int v36; // eax
  __int64 v37; // rax
  int v38; // ecx
  int v40[18]; // [rsp+20h] [rbp-48h] BYREF

  if ( n > 0 )
  {
    v8 = 0i64;
    v9 = n;
    do
    {
      v10 = decode_packed_entry_number(book, b);
      dim = book->dim;
      v12 = v10;
      if ( book->dec_type == 1 )
      {
        q_bits = book->q_bits;
        v14 = 0i64;
        do
        {
          ++v14;
          v15 = v12 & ((1 << q_bits) - 1);
          v12 >>= q_bits;
          v40[v14 - 1] = v15;
        }
        while ( v14 < dim );
      }
      else
      {
        q_pack = book->q_pack;
        q_val = (unsigned __int16 *)book->q_val;
        v18 = 0;
        v19 = 0i64;
        v20 = (1 << q_pack) - 1;
        if ( book->q_bits > 8 )
        {
          v24 = v20;
          do
          {
            v25 = v12;
            ++v19;
            v12 >>= q_pack;
            v40[v19 - 1] = q_val[v24 & v25];
          }
          while ( v19 < dim );
        }
        else
        {
          v21 = v20;
          v22 = v40;
          do
          {
            v23 = v12;
            ++v18;
            v12 >>= q_pack;
            *v22++ = *((unsigned __int8 *)q_val + (v21 & v23));
          }
          while ( v18 < (int)dim );
        }
      }
      q_min = book->q_min;
      v27 = point - book->q_minp;
      v28 = point - book->q_delp;
      if ( v27 <= 0 )
        v29 = q_min << -(char)v27;
      else
        v29 = q_min >> v27;
      q_del = book->q_del;
      v31 = 0;
      v32 = 0i64;
      if ( v28 <= 0 )
      {
        v35 = book->q_delp - point;
        do
        {
          v36 = v40[v32++];
          v40[v32 - 1] = v29 + ((q_del * v36) << v35);
        }
        while ( v32 < dim );
      }
      else
      {
        v33 = v40;
        do
        {
          ++v31;
          v34 = *v33++ * q_del;
          *(v33 - 1) = v29 + (v34 >> v28);
        }
        while ( v31 < (int)dim );
      }
      v37 = 0i64;
      do
      {
        v38 = v40[v37++];
        a[v8++] += v38;
      }
      while ( v37 < dim );
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
  int i; // r12d
  unsigned int v11; // eax
  __int64 dim; // rbp
  int q_bits; // r9d
  __int64 v14; // rdx
  int q_pack; // r9d
  unsigned __int16 *q_val; // r10
  int v17; // r8d
  __int64 v18; // rdx
  int v19; // r11d
  int *v20; // rdx
  int q_min; // r9d
  int v22; // ecx
  int v23; // r8d
  int v24; // r9d
  int q_del; // r11d
  int v26; // r10d
  __int64 v27; // rdx
  int *v28; // rdx
  int v29; // eax
  int v30; // r8d
  int v31; // eax
  __int64 v32; // r8
  int *v33; // rdx
  int v35[18]; // [rsp+20h] [rbp-48h] BYREF
  oggpack_buffer *v36; // [rsp+88h] [rbp+20h]

  v36 = b;
  v6 = 0;
  v7 = offset;
  for ( i = offset + n; v7 < i; b = v36 )
  {
    v11 = decode_packed_entry_number(book, b);
    dim = book->dim;
    if ( book->dec_type == 1 )
    {
      q_bits = book->q_bits;
      v14 = 0i64;
      do
      {
        v35[v14++] = v11 & ((1 << q_bits) - 1);
        v11 >>= q_bits;
      }
      while ( v14 < dim );
    }
    else
    {
      q_pack = book->q_pack;
      q_val = (unsigned __int16 *)book->q_val;
      v17 = 0;
      v18 = 0i64;
      v19 = (1 << q_pack) - 1;
      if ( book->q_bits > 8 )
      {
        do
        {
          v35[v18++] = q_val[v19 & v11];
          v11 >>= q_pack;
        }
        while ( v18 < dim );
      }
      else
      {
        v20 = v35;
        do
        {
          ++v17;
          *v20++ = *((unsigned __int8 *)q_val + (v19 & v11));
          v11 >>= q_pack;
        }
        while ( v17 < (int)dim );
      }
    }
    q_min = book->q_min;
    v22 = point - book->q_minp;
    v23 = point - book->q_delp;
    if ( v22 <= 0 )
      v24 = q_min << -(char)v22;
    else
      v24 = q_min >> v22;
    q_del = book->q_del;
    v26 = 0;
    v27 = 0i64;
    if ( v23 <= 0 )
    {
      v30 = book->q_delp - point;
      do
      {
        v31 = v35[v27++];
        v35[v27 - 1] = v24 + ((q_del * v31) << v30);
      }
      while ( v27 < dim );
    }
    else
    {
      v28 = v35;
      do
      {
        v29 = *v28;
        ++v26;
        *v28++ = v24 + ((q_del * v29) >> v23);
      }
      while ( v26 < (int)dim );
    }
    v32 = 0i64;
    do
    {
      ++v32;
      v33 = &a[v6][v7];
      *v33 += v35[v32 - 1];
      v7 += v6 & 1;
      v6 = ((_BYTE)v6 - 1) & 1;
    }
    while ( v32 < dim );
  }
}

