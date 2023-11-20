// File Line: 31
// RVA: 0xABFC70
signed __int64 __fastcall res_unpack(vorbis_info_residue *info, codec_setup_info *ci, oggpack_buffer *opb, CAkVorbisAllocator *VorbisAllocator)
{
  codec_setup_info *v4; // r15
  vorbis_info_residue *v5; // rdi
  CAkVorbisAllocator *v6; // rbx
  oggpack_buffer *v7; // rbp
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  unsigned int v10; // er8
  char *v11; // rdx
  int v12; // eax
  int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // er8
  char *v16; // rdx
  signed int v17; // esi
  __int64 v18; // r14
  int v19; // ebx
  __int64 v20; // rsi
  signed int v21; // er14
  signed int v22; // ebx
  unsigned __int8 v23; // al
  signed __int64 result; // rax

  v4 = ci;
  v5 = info;
  *(_QWORD *)&info->type = 0i64;
  info->stagemasks = 0i64;
  info->stagebooks = 0i64;
  *(_QWORD *)&info->begin = 0i64;
  *(_QWORD *)&info->grouping = 0i64;
  v6 = VorbisAllocator;
  v7 = opb;
  info->type = oggpack_read(opb, 2);
  v5->begin = oggpack_read(v7, 24);
  v5->end = oggpack_read(v7, 24);
  v5->grouping = (unsigned __int64)oggpack_read(v7, 24) + 1;
  v5->partitions = (unsigned __int64)oggpack_read(v7, 6) + 1;
  v8 = oggpack_read(v7, 8);
  v5->groupbook = v8;
  if ( v8 >= v4->books )
    goto $errout;
  if ( v5->partitions && (v9 = (v5->partitions + 3) & 0xFFFFFFFC, v10 = v9 + v6->CurrentSize, v10 <= v6->MaxSize) )
  {
    v11 = v6->pCurrentAddress;
    v6->CurrentSize = v10;
    v6->pCurrentAddress = &v11[v9];
  }
  else
  {
    v11 = 0i64;
  }
  v12 = v5->partitions;
  v5->stagemasks = v11;
  v13 = 8 * v12;
  if ( v13 && (v14 = (v13 + 3) & 0xFFFFFFFC, v15 = v14 + v6->CurrentSize, v15 <= v6->MaxSize) )
  {
    v16 = v6->pCurrentAddress;
    v6->CurrentSize = v15;
    v6->pCurrentAddress = &v16[v14];
  }
  else
  {
    v16 = 0i64;
  }
  v17 = 0;
  v18 = 0i64;
  v5->stagebooks = v16;
  if ( v5->partitions > 0 )
  {
    do
    {
      v19 = oggpack_read(v7, 3);
      if ( (unsigned int)oggpack_read(v7, 1) )
        v19 |= 8 * (unsigned __int64)oggpack_read(v7, 5);
      ++v17;
      v5->stagemasks[++v18 - 1] = v19;
    }
    while ( v17 < v5->partitions );
  }
  v20 = 0i64;
  v21 = 0;
  if ( v5->partitions > 0 )
  {
    do
    {
      v22 = 0;
      do
      {
        if ( ((unsigned __int8)v5->stagemasks[v20] >> v22) & 1 )
        {
          v23 = oggpack_read(v7, 8);
          if ( v23 >= v4->books )
            goto $errout;
          v5->stagebooks[8 * v20 + v22] = v23;
          if ( v22 + 1 > v5->stages )
            v5->stages = v22 + 1;
        }
        else
        {
          v5->stagebooks[8 * v20 + v22] = -1;
        }
        ++v22;
      }
      while ( v22 < 8 );
      ++v21;
      ++v20;
    }
    while ( v21 < v5->partitions );
  }
  if ( v7->headend < 0 )
$errout:
    result = 1i64;
  else
    result = 0i64;
  return result;
}

// File Line: 98
// RVA: 0xABF640
__int64 __fastcall res_inverse(vorbis_dsp_state *vd, vorbis_info_residue *info, int **in, int *nonzero, int ch)
{
  vorbis_info_residue *v5; // r13
  codec_setup_info *v6; // rdx
  vorbis_dsp_state *v7; // r15
  int v8; // ecx
  codebook *v9; // rax
  __int64 v10; // r12
  int v11; // ebx
  bool v12; // sf
  unsigned __int8 v13; // of
  __int64 v14; // rax
  int v15; // edx
  __int64 v16; // r14
  int v17; // edx
  int v18; // edx
  int v19; // eax
  signed __int64 v20; // rcx
  __int64 v21; // rsi
  int **v22; // rdx
  int v23; // edi
  unsigned __int64 v24; // rcx
  signed __int64 v25; // rax
  void *v26; // rsp
  int *v27; // r9
  signed __int64 v28; // rcx
  int v29; // edx
  __int64 v30; // rax
  int v31; // ebx
  __int64 v32; // r11
  __int64 v33; // rax
  int v34; // ecx
  __int64 v35; // rsi
  signed __int64 v36; // rdx
  signed __int64 v37; // rcx
  __int64 v38; // rdi
  signed __int64 v39; // r9
  signed __int64 v40; // r10
  signed __int64 v41; // r8
  __int64 v42; // rdx
  _BYTE *v43; // rax
  __int64 v44; // rbx
  unsigned int v45; // er10
  __int64 v46; // r11
  char *v47; // r9
  unsigned int v48; // er8
  int v49; // eax
  int v50; // er9
  int v51; // edx
  int v52; // er12
  int v53; // er14
  int **v54; // rbx
  __int64 v55; // r8
  int v56; // eax
  int v57; // ebx
  int v58; // edx
  int v59; // edx
  __int64 v60; // rsi
  unsigned __int64 v61; // rcx
  signed __int64 v62; // rax
  void *v63; // rsp
  int v64; // ecx
  int v65; // er10
  signed __int64 v66; // rax
  int v67; // ecx
  __int64 v68; // r9
  __int64 v69; // rdx
  int v70; // er15
  int v71; // er14
  __int64 v72; // rbx
  int v73; // eax
  int v74; // er8
  __int64 v75; // rdi
  signed __int64 v76; // rdx
  char *v77; // rcx
  unsigned int v78; // er10
  char *v79; // r9
  __int64 v80; // r11
  unsigned int v81; // er8
  signed int v82; // esi
  int v83; // edi
  __int64 v84; // rcx
  int v85; // eax
  int v87; // [rsp+30h] [rbp+0h]
  int v88; // [rsp+34h] [rbp+4h]
  int n; // [rsp+38h] [rbp+8h]
  __int64 v90; // [rsp+40h] [rbp+10h]
  __int64 v91; // [rsp+48h] [rbp+18h]
  __int64 v92; // [rsp+50h] [rbp+20h]
  __int64 v93; // [rsp+58h] [rbp+28h]
  __int64 v94; // [rsp+60h] [rbp+30h]
  codebook *book; // [rsp+68h] [rbp+38h]
  codec_setup_info *v96; // [rsp+70h] [rbp+40h]
  __int64 v97; // [rsp+78h] [rbp+48h]
  __int64 v98[14]; // [rsp+80h] [rbp+50h]
  vorbis_dsp_state *b; // [rsp+100h] [rbp+D0h]
  int v100; // [rsp+108h] [rbp+D8h]
  int **a; // [rsp+110h] [rbp+E0h]

  a = in;
  b = vd;
  v5 = info;
  v6 = vd->csi;
  v7 = vd;
  v8 = v5->grouping;
  v9 = v6->book_param;
  v10 = v9[(unsigned __int8)v5->groupbook].dim;
  v11 = 0;
  v13 = __OFSUB__(v5->type, 2);
  v12 = v5->type - 2 < 0;
  book = &v9[(unsigned __int8)v5->groupbook];
  v14 = v7->state.W;
  v96 = v6;
  v15 = v6->blocksizes[v14];
  n = v8;
  v100 = v10;
  v16 = v10;
  v94 = v10;
  if ( !(v12 ^ v13) )
  {
    v57 = v5->begin;
    v58 = ch * v15 >> 1;
    if ( v5->end < v58 )
      v58 = v5->end;
    v59 = v58 - v57;
    if ( v59 <= 0 )
      return 0i64;
    v60 = v59 / v8;
    v61 = (signed int)v10 * (((signed int)v60 + (signed int)v10 - 1) / (signed int)v10);
    v62 = v61 + 15;
    if ( v61 + 15 <= v61 )
      v62 = 1152921504606846960i64;
    v63 = alloca(v62);
    v64 = 0;
    v65 = v57 / ch;
    v87 = v57 / ch;
    v66 = 0i64;
    if ( ch > 0 )
    {
      do
      {
        if ( nonzero[v66] )
          break;
        ++v66;
        ++v64;
      }
      while ( v66 < ch );
    }
    if ( v64 == ch )
      return 0i64;
    v67 = 0;
    v68 = 0i64;
    v88 = 0;
    v90 = 0i64;
    v69 = v60;
    v91 = v60;
    v70 = n / ch;
    if ( v5->stages <= 0 )
      return 0i64;
    while ( 1 )
    {
      v71 = 0;
      v72 = 0i64;
      if ( v69 > 0 )
      {
        v73 = v10;
        v74 = __ROL4__(1, v67);
        n = __ROL4__(1, v67);
        while ( 1 )
        {
          if ( !v67 )
          {
            v75 = v94;
            *((_BYTE *)&v87 + v94 + v72 - 1) = 1;
            if ( v75 - 2 >= 0 )
            {
              v76 = v75 - 1;
              v77 = (char *)&v87 + v72 + v75 - 2;
              do
              {
                --v77;
                v77[1] = v77[2] * v5->partitions;
                --v76;
              }
              while ( v76 );
            }
            v78 = ak_vorbis_book_decode(book, &b->opb);
            if ( v75 > 0 )
            {
              v79 = (char *)&v87 + v72;
              v80 = v75;
              do
              {
                v81 = *v79++;
                *(v79 - 1) = v78 / v81;
                v78 -= v81 * (char)(v78 / v81);
                --v80;
              }
              while ( v80 );
            }
            v65 = v87;
            v68 = v90;
            LOBYTE(v74) = n;
            v69 = v91;
            v73 = v75;
          }
          v82 = 0;
          if ( v73 > 0 )
            break;
LABEL_79:
          v68 = v90;
          v67 = v88;
          v65 = v87;
          if ( v72 >= v69 )
            goto LABEL_80;
        }
        v83 = v65 + v70 * v71;
        while ( v72 < v69 )
        {
          v84 = *((char *)&v87 + v72);
          if ( (unsigned __int8)v74 & v5->stagemasks[v84] )
          {
            vorbis_book_decodevv_add_2ch(
              &v96->book_param[(unsigned __int8)v5->stagebooks[8 * v84 + v68]],
              a,
              v83,
              &b->opb,
              v70,
              -8);
            v69 = v91;
            LOBYTE(v74) = n;
          }
          v73 = v10;
          v68 = v90;
          ++v82;
          ++v71;
          v83 += v70;
          ++v72;
          if ( v82 >= (signed int)v10 )
            goto LABEL_79;
        }
LABEL_80:
        v68 = v90;
        v67 = v88;
        v65 = v87;
      }
      v85 = v5->stages;
      ++v67;
      ++v68;
      v88 = v67;
      v90 = v68;
      if ( v67 >= v85 )
        return 0i64;
    }
  }
  v17 = v15 >> 1;
  if ( v5->end < v17 )
    v17 = v5->end;
  v18 = v17 - v5->begin;
  if ( v18 <= 0 )
    return 0i64;
  v19 = v18 / v8;
  v20 = 0i64;
  v21 = v19;
  if ( ch <= 0i64 )
    return 0i64;
  v22 = in;
  do
  {
    if ( nonzero[v20] )
    {
      ++v11;
      ++v22;
      *(v22 - 1) = in[v20];
    }
    ++v20;
  }
  while ( v20 < ch );
  if ( !v11 )
    return 0i64;
  v23 = v10 * ((v19 + (signed int)v10 - 1) / (signed int)v10);
  v24 = v11 * v23;
  v25 = v24 + 15;
  if ( v24 + 15 <= v24 )
    v25 = 1152921504606846960i64;
  v26 = alloca(v25);
  v27 = &v87;
  v28 = 1i64;
  v93 = v11;
  v98[0] = (__int64)&v87;
  if ( v11 > 1i64 )
  {
    v29 = v23;
    do
    {
      v30 = v29;
      ++v28;
      v29 += v23;
      *(&v97 + v28) = (__int64)v27 + v30;
      v27 = (int *)v98[0];
    }
    while ( v28 < v11 );
  }
  v31 = 0;
  v32 = 0i64;
  v33 = v21;
  v87 = 0;
  v92 = 0i64;
  v91 = v21;
  if ( v5->stages <= 0 )
    return 0i64;
  while ( 1 )
  {
    v34 = 0;
    v35 = 0i64;
    v88 = 0;
    if ( v33 > 0 )
      break;
LABEL_51:
    v56 = v5->stages;
    ++v31;
    ++v32;
    v87 = v31;
    v92 = v32;
    if ( v31 >= v56 )
      return 0i64;
    LODWORD(v10) = v100;
    v33 = v91;
    v27 = (int *)v98[0];
  }
  while ( v31 )
  {
    v38 = v93;
LABEL_36:
    v49 = 0;
    LODWORD(v90) = 0;
    if ( (signed int)v10 > 0 )
    {
      v50 = n;
      v51 = v100;
      v52 = n * v34;
      while ( v35 < v91 )
      {
        v53 = __ROL4__(1, v31);
        if ( v38 > 0 )
        {
          v54 = a;
          do
          {
            v55 = (*(char **)((char *)v54 + (char *)v98 - (char *)a))[v35];
            if ( (unsigned __int8)v53 & v5->stagemasks[v55] )
            {
              vorbis_book_decodev_add(
                &v96->book_param[(unsigned __int8)v5->stagebooks[8 * v55 + v32]],
                &(*v54)[v52 + v5->begin],
                &b->opb,
                v50,
                -8);
              v50 = n;
            }
            v32 = v92;
            ++v54;
            --v38;
          }
          while ( v38 );
          v49 = v90;
          v38 = v93;
          v51 = v100;
          v31 = v87;
        }
        v32 = v92;
        ++v49;
        v34 = v88 + 1;
        v52 += v50;
        ++v35;
        ++v88;
        LODWORD(v90) = v49;
        if ( v49 >= v51 )
        {
          v16 = v94;
          v7 = b;
          LODWORD(v10) = v94;
          goto LABEL_47;
        }
      }
      v16 = v94;
      v7 = b;
      goto LABEL_51;
    }
LABEL_47:
    v32 = v92;
    v27 = (int *)v98[0];
    if ( v35 >= v91 )
      goto LABEL_51;
  }
  *((_BYTE *)v27 + v16 + v35 - 1) = 1;
  if ( v16 - 2 >= 0 )
  {
    v36 = v16 - 1;
    v37 = (signed __int64)v27 + v35 + v16 - 2;
    do
    {
      --v37;
      *(_BYTE *)(v37 + 1) = *(_BYTE *)(v37 + 2) * v5->partitions;
      --v36;
    }
    while ( v36 );
  }
  v38 = v93;
  v39 = 1i64;
  if ( v93 > 1 )
  {
    v40 = v16 - 1;
    do
    {
      v41 = v16 - 1;
      if ( v40 >= 0 )
      {
        v42 = v40 + v35 + v98[v39];
        v43 = (_BYTE *)(v40 + v35 + *(&v97 + v39));
        do
        {
          --v41;
          *(_BYTE *)(--v42 + 1) = *v43--;
        }
        while ( v41 >= 0 );
      }
      ++v39;
    }
    while ( v39 < v38 );
  }
  v44 = 0i64;
  if ( v38 <= 0 )
  {
LABEL_35:
    v31 = v87;
    v34 = v88;
    goto LABEL_36;
  }
  while ( 1 )
  {
    v45 = ak_vorbis_book_decode(book, &v7->opb);
    if ( v7->opb.headend < 0 )
      return 0i64;
    if ( v16 > 0 )
    {
      v46 = v16;
      v47 = (char *)(v35 + v98[v44]);
      do
      {
        v48 = *v47++;
        *(v47 - 1) = v45 / v48;
        v45 -= v48 * (char)(v45 / v48);
        --v46;
      }
      while ( v46 );
    }
    if ( ++v44 >= v38 )
    {
      v32 = v92;
      goto LABEL_35;
    }
  }
}

