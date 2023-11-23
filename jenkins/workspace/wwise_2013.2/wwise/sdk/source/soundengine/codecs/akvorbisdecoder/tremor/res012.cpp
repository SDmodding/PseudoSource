// File Line: 31
// RVA: 0xABFC70
_BOOL8 __fastcall res_unpack(
        vorbis_info_residue *info,
        codec_setup_info *ci,
        oggpack_buffer *opb,
        CAkVorbisAllocator *VorbisAllocator)
{
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  unsigned int v10; // r8d
  char *pCurrentAddress; // rdx
  int partitions; // eax
  int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // r8d
  char *v16; // rdx
  int v17; // esi
  __int64 v18; // r14
  char v19; // bl
  __int64 v20; // rsi
  int i; // r14d
  int j; // ebx
  unsigned __int8 v23; // al

  *(_QWORD *)&info->type = 0i64;
  info->stagemasks = 0i64;
  info->stagebooks = 0i64;
  *(_QWORD *)&info->begin = 0i64;
  *(_QWORD *)&info->grouping = 0i64;
  info->type = oggpack_read(opb, 2);
  info->begin = oggpack_read(opb, 24);
  info->end = oggpack_read(opb, 24);
  info->grouping = oggpack_read(opb, 24) + 1;
  info->partitions = oggpack_read(opb, 6) + 1;
  v8 = oggpack_read(opb, 8);
  info->groupbook = v8;
  if ( v8 >= ci->books )
    return 1i64;
  if ( info->partitions
    && (v9 = (info->partitions + 3) & 0xFFFFFFFC,
        v10 = v9 + VorbisAllocator->CurrentSize,
        v10 <= VorbisAllocator->MaxSize) )
  {
    pCurrentAddress = VorbisAllocator->pCurrentAddress;
    VorbisAllocator->CurrentSize = v10;
    VorbisAllocator->pCurrentAddress = &pCurrentAddress[v9];
  }
  else
  {
    pCurrentAddress = 0i64;
  }
  partitions = info->partitions;
  info->stagemasks = pCurrentAddress;
  v13 = 8 * partitions;
  if ( v13 && (v14 = (v13 + 3) & 0xFFFFFFFC, v15 = v14 + VorbisAllocator->CurrentSize, v15 <= VorbisAllocator->MaxSize) )
  {
    v16 = VorbisAllocator->pCurrentAddress;
    VorbisAllocator->CurrentSize = v15;
    VorbisAllocator->pCurrentAddress = &v16[v14];
  }
  else
  {
    v16 = 0i64;
  }
  v17 = 0;
  v18 = 0i64;
  for ( info->stagebooks = v16; v17 < info->partitions; info->stagemasks[v18++] = v19 )
  {
    v19 = oggpack_read(opb, 3);
    if ( (unsigned int)oggpack_read(opb, 1) )
      v19 |= 8 * oggpack_read(opb, 5);
    ++v17;
  }
  v20 = 0i64;
  for ( i = 0; i < info->partitions; ++v20 )
  {
    for ( j = 0; j < 8; ++j )
    {
      if ( (((unsigned __int8)info->stagemasks[v20] >> j) & 1) != 0 )
      {
        v23 = oggpack_read(opb, 8);
        if ( v23 >= ci->books )
          return 1i64;
        info->stagebooks[8 * v20 + j] = v23;
        if ( j + 1 > info->stages )
          info->stages = j + 1;
      }
      else
      {
        info->stagebooks[8 * v20 + j] = -1;
      }
    }
    ++i;
  }
  return opb->headend < 0;
}

// File Line: 98
// RVA: 0xABF640
__int64 __fastcall res_inverse(vorbis_dsp_state *vd, vorbis_info_residue *info, int **in, int *nonzero, int ch)
{
  codec_setup_info *csi; // rdx
  vorbis_dsp_state *v7; // r15
  int grouping; // ecx
  codebook *book_param; // rax
  __int64 dim; // r12
  int v11; // ebx
  bool v12; // cc
  __int64 W; // rax
  int v14; // edx
  __int64 v15; // r14
  int v16; // edx
  int v17; // edx
  int v18; // eax
  __int64 v19; // rcx
  __int64 v20; // rsi
  int **v21; // rdx
  int v22; // edi
  unsigned __int64 v23; // rcx
  __int64 v24; // rax
  void *v25; // rsp
  int *v26; // r9
  __int64 v27; // rcx
  int v28; // edx
  __int64 v29; // rax
  int v30; // ebx
  __int64 v31; // r11
  __int64 v32; // rax
  int v33; // ecx
  __int64 v34; // rsi
  __int64 v35; // rdx
  char *v36; // rcx
  __int64 v37; // rdi
  __int64 v38; // r9
  __int64 v39; // r10
  __int64 v40; // r8
  _BYTE *v41; // rdx
  _BYTE *v42; // rax
  __int64 v43; // rbx
  unsigned int v44; // r10d
  __int64 v45; // r11
  char *v46; // r9
  unsigned int v47; // r8d
  int v48; // eax
  int v49; // r9d
  int v50; // edx
  int v51; // r12d
  unsigned __int8 v52; // r14
  int **v53; // rbx
  __int64 v54; // r8
  int v55; // eax
  int begin; // ebx
  int end; // edx
  int v58; // edx
  __int64 v59; // rsi
  unsigned __int64 v60; // rcx
  __int64 v61; // rax
  void *v62; // rsp
  int v63; // ecx
  int v64; // r10d
  __int64 i; // rax
  int v66; // ecx
  __int64 v67; // r9
  __int64 v68; // rdx
  int v69; // r15d
  int v70; // r14d
  __int64 v71; // rbx
  int v72; // eax
  int v73; // r8d
  __int64 v74; // rdi
  __int64 v75; // rdx
  char *v76; // rcx
  unsigned int v77; // r10d
  char *v78; // r9
  __int64 v79; // r11
  unsigned int v80; // r8d
  int v81; // esi
  int v82; // edi
  __int64 v83; // rcx
  int stages; // eax
  int v86; // [rsp+30h] [rbp+0h] BYREF
  int v87; // [rsp+34h] [rbp+4h]
  int n; // [rsp+38h] [rbp+8h]
  __int64 v89; // [rsp+40h] [rbp+10h]
  __int64 v90; // [rsp+48h] [rbp+18h]
  __int64 v91; // [rsp+50h] [rbp+20h]
  __int64 v92; // [rsp+58h] [rbp+28h]
  __int64 v93; // [rsp+60h] [rbp+30h]
  codebook *book; // [rsp+68h] [rbp+38h]
  codec_setup_info *v95; // [rsp+70h] [rbp+40h]
  __int64 v97[14]; // [rsp+80h] [rbp+50h] BYREF
  int v99; // [rsp+108h] [rbp+D8h]

  csi = vd->csi;
  v7 = vd;
  grouping = info->grouping;
  book_param = csi->book_param;
  dim = book_param[(unsigned __int8)info->groupbook].dim;
  v11 = 0;
  v12 = info->type < 2;
  book = &book_param[(unsigned __int8)info->groupbook];
  W = v7->state.W;
  v95 = csi;
  v14 = csi->blocksizes[W];
  n = grouping;
  v99 = dim;
  v15 = dim;
  v93 = dim;
  if ( !v12 )
  {
    begin = info->begin;
    end = (ch * v14) >> 1;
    if ( info->end < end )
      end = info->end;
    v58 = end - begin;
    if ( v58 <= 0 )
      return 0i64;
    v59 = v58 / grouping;
    v60 = (int)dim * (((int)v59 + (int)dim - 1) / (int)dim);
    v61 = v60 + 15;
    if ( v60 + 15 <= v60 )
      v61 = 0xFFFFFFFFFFFFFF0i64;
    v62 = alloca(v61 & 0xFFFFFFFFFFFFFFF0ui64);
    v63 = 0;
    v64 = begin / ch;
    v86 = begin / ch;
    for ( i = 0i64; i < ch; ++v63 )
    {
      if ( nonzero[i] )
        break;
      ++i;
    }
    if ( v63 == ch )
      return 0i64;
    v66 = 0;
    v67 = 0i64;
    v87 = 0;
    v89 = 0i64;
    v68 = v59;
    v90 = v59;
    v69 = n / ch;
    if ( info->stages <= 0 )
      return 0i64;
    while ( 1 )
    {
      v70 = 0;
      v71 = 0i64;
      if ( v68 > 0 )
      {
        v72 = dim;
        v73 = __ROL4__(1, v66);
        n = v73;
        while ( 1 )
        {
          if ( !v66 )
          {
            v74 = v93;
            *((_BYTE *)&v86 + v93 + v71 - 1) = 1;
            if ( v74 - 2 >= 0 )
            {
              v75 = v74 - 1;
              v76 = (char *)&v86 + v71 + v74 - 2;
              do
              {
                --v76;
                v76[1] = v76[2] * info->partitions;
                --v75;
              }
              while ( v75 );
            }
            v77 = ak_vorbis_book_decode(book, &vd->opb);
            if ( v74 > 0 )
            {
              v78 = (char *)&v86 + v71;
              v79 = v74;
              do
              {
                v80 = *v78++;
                *(v78 - 1) = v77 / v80;
                v77 -= v80 * (char)(v77 / v80);
                --v79;
              }
              while ( v79 );
            }
            v64 = v86;
            v67 = v89;
            LOBYTE(v73) = n;
            v68 = v90;
            v72 = v74;
          }
          v81 = 0;
          if ( v72 > 0 )
            break;
LABEL_79:
          v67 = v89;
          v66 = v87;
          v64 = v86;
          if ( v71 >= v68 )
            goto LABEL_80;
        }
        v82 = v64 + v69 * v70;
        while ( v71 < v68 )
        {
          v83 = *((char *)&v86 + v71);
          if ( ((unsigned __int8)v73 & info->stagemasks[v83]) != 0 )
          {
            vorbis_book_decodevv_add_2ch(
              &v95->book_param[(unsigned __int8)info->stagebooks[8 * v83 + v67]],
              in,
              v82,
              &vd->opb,
              v69,
              -8);
            v68 = v90;
            LOBYTE(v73) = n;
          }
          v72 = dim;
          v67 = v89;
          ++v81;
          ++v70;
          v82 += v69;
          ++v71;
          if ( v81 >= (int)dim )
            goto LABEL_79;
        }
LABEL_80:
        v67 = v89;
        v66 = v87;
        v64 = v86;
      }
      stages = info->stages;
      ++v66;
      ++v67;
      v87 = v66;
      v89 = v67;
      if ( v66 >= stages )
        return 0i64;
    }
  }
  v16 = v14 >> 1;
  if ( info->end < v16 )
    v16 = info->end;
  v17 = v16 - info->begin;
  if ( v17 <= 0 )
    return 0i64;
  v18 = v17 / grouping;
  v19 = 0i64;
  v20 = v18;
  if ( ch <= 0i64 )
    return 0i64;
  v21 = in;
  do
  {
    if ( nonzero[v19] )
    {
      ++v11;
      *v21++ = in[v19];
    }
    ++v19;
  }
  while ( v19 < ch );
  if ( !v11 )
    return 0i64;
  v22 = dim * ((v18 + (int)dim - 1) / (int)dim);
  v23 = v11 * v22;
  v24 = v23 + 15;
  if ( v23 + 15 <= v23 )
    v24 = 0xFFFFFFFFFFFFFF0i64;
  v25 = alloca(v24 & 0xFFFFFFFFFFFFFFF0ui64);
  v26 = &v86;
  v27 = 1i64;
  v92 = v11;
  v97[0] = (__int64)&v86;
  if ( v11 > 1i64 )
  {
    v28 = v22;
    do
    {
      v29 = v28;
      ++v27;
      v28 += v22;
      v97[v27 - 1] = (__int64)v26 + v29;
      v26 = (int *)v97[0];
    }
    while ( v27 < v11 );
  }
  v30 = 0;
  v31 = 0i64;
  v32 = v20;
  v86 = 0;
  v91 = 0i64;
  v90 = v20;
  if ( info->stages <= 0 )
    return 0i64;
  while ( 1 )
  {
    v33 = 0;
    v34 = 0i64;
    v87 = 0;
    if ( v32 > 0 )
      break;
LABEL_51:
    v55 = info->stages;
    ++v30;
    ++v31;
    v86 = v30;
    v91 = v31;
    if ( v30 >= v55 )
      return 0i64;
    LODWORD(dim) = v99;
    v32 = v90;
    v26 = (int *)v97[0];
  }
  while ( v30 )
  {
    v37 = v92;
LABEL_36:
    v48 = 0;
    LODWORD(v89) = 0;
    if ( (int)dim > 0 )
    {
      v49 = n;
      v50 = v99;
      v51 = n * v33;
      while ( v34 < v90 )
      {
        v52 = __ROL4__(1, v30);
        if ( v37 > 0 )
        {
          v53 = in;
          do
          {
            v54 = (*(char **)((char *)v53 + (char *)v97 - (char *)in))[v34];
            if ( (v52 & info->stagemasks[v54]) != 0 )
            {
              vorbis_book_decodev_add(
                &v95->book_param[(unsigned __int8)info->stagebooks[8 * v54 + v31]],
                &(*v53)[v51 + info->begin],
                &vd->opb,
                v49,
                -8);
              v49 = n;
            }
            v31 = v91;
            ++v53;
            --v37;
          }
          while ( v37 );
          v48 = v89;
          v37 = v92;
          v50 = v99;
          v30 = v86;
        }
        v31 = v91;
        ++v48;
        v33 = v87 + 1;
        v51 += v49;
        ++v34;
        ++v87;
        LODWORD(v89) = v48;
        if ( v48 >= v50 )
        {
          v15 = v93;
          v7 = vd;
          LODWORD(dim) = v93;
          goto LABEL_47;
        }
      }
      v15 = v93;
      v7 = vd;
      goto LABEL_51;
    }
LABEL_47:
    v31 = v91;
    v26 = (int *)v97[0];
    if ( v34 >= v90 )
      goto LABEL_51;
  }
  *((_BYTE *)v26 + v15 + v34 - 1) = 1;
  if ( v15 - 2 >= 0 )
  {
    v35 = v15 - 1;
    v36 = (char *)v26 + v34 + v15 - 2;
    do
    {
      --v36;
      v36[1] = v36[2] * info->partitions;
      --v35;
    }
    while ( v35 );
  }
  v37 = v92;
  v38 = 1i64;
  if ( v92 > 1 )
  {
    v39 = v15 - 1;
    do
    {
      v40 = v15 - 1;
      if ( v39 >= 0 )
      {
        v41 = (_BYTE *)(v39 + v34 + v97[v38]);
        v42 = (_BYTE *)(v39 + v34 + v97[v38 - 1]);
        do
        {
          --v40;
          *v41-- = *v42--;
        }
        while ( v40 >= 0 );
      }
      ++v38;
    }
    while ( v38 < v37 );
  }
  v43 = 0i64;
  if ( v37 <= 0 )
  {
LABEL_35:
    v30 = v86;
    v33 = v87;
    goto LABEL_36;
  }
  while ( 1 )
  {
    v44 = ak_vorbis_book_decode(book, &v7->opb);
    if ( v7->opb.headend < 0 )
      return 0i64;
    if ( v15 > 0 )
    {
      v45 = v15;
      v46 = (char *)(v34 + v97[v43]);
      do
      {
        v47 = *v46++;
        *(v46 - 1) = v44 / v47;
        v44 -= v47 * (char)(v44 / v47);
        --v45;
      }
      while ( v45 );
    }
    if ( ++v43 >= v37 )
    {
      v31 = v91;
      goto LABEL_35;
    }
  }
}

