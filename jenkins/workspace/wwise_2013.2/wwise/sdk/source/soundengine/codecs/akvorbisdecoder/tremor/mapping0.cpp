// File Line: 33
// RVA: 0xABDFA0
__int64 __fastcall ilog(unsigned int v)
{
  __int64 result; // rax
  unsigned int i; // ecx

  result = 0i64;
  if ( v )
  {
    for ( i = v - 1; i; i >>= 1 )
      result = (unsigned int)(result + 1);
  }
  return result;
}

// File Line: 49
// RVA: 0xABDFC0
signed __int64 __fastcall mapping_info_unpack(vorbis_info_mapping *info, codec_setup_info *ci, int channels, oggpack_buffer *opb, CAkVorbisAllocator *VorbisAllocator)
{
  codec_setup_info *v5; // r12
  vorbis_info_mapping *v6; // rbx
  oggpack_buffer *v7; // rbp
  __int64 v8; // r15
  int v9; // esi
  int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // er8
  char *v13; // rdx
  int v14; // edi
  int v15; // eax
  __int64 v16; // r12
  unsigned __int8 v17; // al
  signed int v18; // er13
  unsigned __int8 v19; // al
  int v20; // ecx
  unsigned int v21; // er8
  char *v22; // rdx
  __int64 v23; // rdi
  unsigned int v24; // ecx
  unsigned int v25; // er8
  char *v26; // rdx
  __int64 v27; // rdi
  int bits; // [rsp+20h] [rbp-38h]
  codec_setup_info *v30; // [rsp+68h] [rbp+10h]

  v30 = ci;
  v5 = ci;
  v6 = info;
  *(_QWORD *)&info->submaps = 0i64;
  info->chmuxlist = 0i64;
  info->submaplist = 0i64;
  *(_QWORD *)&info->coupling_steps = 0i64;
  info->coupling = 0i64;
  v7 = opb;
  v8 = channels;
  if ( (unsigned int)oggpack_read(opb, 1) )
    v6->submaps = (unsigned __int64)oggpack_read(v7, 4) + 1;
  else
    v6->submaps = 1;
  v9 = 0;
  if ( !(unsigned int)oggpack_read(v7, 1) )
    goto LABEL_17;
  v10 = (unsigned __int64)oggpack_read(v7, 8) + 1;
  v6->coupling_steps = v10;
  if ( 2 * v10
    && (v11 = (2 * v10 + 3) & 0xFFFFFFFC, v12 = v11 + VorbisAllocator->CurrentSize, v12 <= VorbisAllocator->MaxSize) )
  {
    v13 = VorbisAllocator->pCurrentAddress;
    VorbisAllocator->CurrentSize = v12;
    VorbisAllocator->pCurrentAddress = &v13[v11];
  }
  else
  {
    v13 = 0i64;
  }
  v6->coupling = (coupling_step *)v13;
  v14 = 0;
  if ( v6->coupling_steps > 0 )
  {
    v15 = ilog(v8);
    v16 = 0i64;
    bits = v15;
    while ( 1 )
    {
      v17 = oggpack_read(v7, v15);
      v6->coupling[v16].mag = v17;
      v18 = v17;
      v19 = oggpack_read(v7, bits);
      v6->coupling[v16].ang = v19;
      if ( v18 < 0 || v18 == v19 || v18 >= (signed int)v8 || v19 >= (signed int)v8 )
        break;
      v15 = bits;
      ++v14;
      ++v16;
      if ( v14 >= v6->coupling_steps )
      {
        v5 = v30;
        goto LABEL_17;
      }
    }
  }
  else
  {
LABEL_17:
    if ( (signed int)oggpack_read(v7, 2) <= 0 )
    {
      if ( v6->submaps <= 1
        || (!(_DWORD)v8
         || (v20 = (v8 + 3) & 0xFFFFFFFC, v21 = v20 + VorbisAllocator->CurrentSize, v21 > VorbisAllocator->MaxSize) ? (v22 = 0i64) : (v22 = VorbisAllocator->pCurrentAddress, VorbisAllocator->CurrentSize = v21, VorbisAllocator->pCurrentAddress = &v22[v20]),
            v6->chmuxlist = v22,
            v23 = 0i64,
            v8 <= 0) )
      {
LABEL_26:
        if ( 2 * v6->submaps
          && (v24 = (2 * v6->submaps + 3) & 0xFFFFFFFC,
              v25 = v24 + VorbisAllocator->CurrentSize,
              v25 <= VorbisAllocator->MaxSize) )
        {
          v26 = VorbisAllocator->pCurrentAddress;
          VorbisAllocator->CurrentSize = v25;
          VorbisAllocator->pCurrentAddress = &v26[v24];
        }
        else
        {
          v26 = 0i64;
        }
        v6->submaplist = (submap *)v26;
        if ( v6->submaps <= 0 )
          return 0i64;
        v27 = 0i64;
        while ( 1 )
        {
          oggpack_read(v7, 8);
          v6->submaplist[v27].floor = oggpack_read(v7, 8);
          if ( v6->submaplist[v27].floor >= v5->floors )
            break;
          v6->submaplist[v27].residue = oggpack_read(v7, 8);
          if ( v6->submaplist[v27].residue >= v5->residues )
            break;
          ++v9;
          ++v27;
          if ( v9 >= v6->submaps )
            return 0i64;
        }
      }
      else
      {
        while ( 1 )
        {
          v6->chmuxlist[v23] = oggpack_read(v7, 4);
          if ( (unsigned __int8)v6->chmuxlist[v23] >= v6->submaps )
            break;
          if ( ++v23 >= v8 )
            goto LABEL_26;
        }
      }
    }
  }
  return 0xFFFFFFFFi64;
}

// File Line: 129
// RVA: 0xABE270
__int64 __fastcall mapping_inverse(vorbis_dsp_state *vd, vorbis_info_mapping *info)
{
  codec_setup_info *v2; // r9
  __int64 v3; // r8
  __int64 v4; // r12
  vorbis_info_mapping *v5; // rdi
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rax
  vorbis_dsp_state *v8; // rsi
  void *v9; // rsp
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax
  void *v12; // rsp
  signed __int64 v13; // rax
  int *v14; // r13
  void *v15; // rsp
  signed __int64 v16; // rax
  signed __int64 v17; // rax
  void *v18; // rsp
  int v19; // ebx
  void *v20; // rsp
  __int64 v21; // r14
  __int64 v22; // r13
  int *v23; // r12
  unsigned __int64 v24; // r13
  int v25; // eax
  signed __int64 v26; // rdx
  unsigned __int64 v27; // rcx
  signed __int64 v28; // rax
  void *v29; // rsp
  int *v30; // rax
  bool v31; // zf
  __int64 v32; // rax
  int v33; // er8
  __int64 v34; // rdx
  coupling_step *v35; // rcx
  int *v36; // r9
  int v37; // er14
  __int64 v38; // r12
  __int64 v39; // rcx
  int v40; // er11
  int v41; // er8
  int *v42; // r9
  int *v43; // r10
  int **v44; // rdx
  char *v45; // rax
  int v46; // eax
  __int64 i; // r10
  coupling_step *v48; // rcx
  char *v49; // rdx
  signed __int64 v50; // r9
  __int64 v51; // r8
  int v52; // eax
  int v53; // ecx
  int v54; // er15
  __int64 v55; // r14
  int **v56; // r13
  __int64 v57; // r12
  int v58; // eax
  float **v59; // rdi
  int fit_value[2]; // [rsp+30h] [rbp+0h]
  int *v62; // [rsp+38h] [rbp+8h]
  int *v63; // [rsp+40h] [rbp+10h]
  int v64; // [rsp+A0h] [rbp+70h]
  int n; // [rsp+A8h] [rbp+78h]
  codec_setup_info *v66; // [rsp+B0h] [rbp+80h]

  v2 = vd->csi;
  v3 = vd->channels;
  v4 = v2->blocksizes[vd->state.W];
  v5 = info;
  v6 = 8 * v3;
  v7 = 8 * v3 + 15;
  v8 = vd;
  v66 = vd->csi;
  n = v2->blocksizes[vd->state.W];
  if ( v7 <= 8 * v3 )
    v7 = 1152921504606846960i64;
  v9 = alloca(v7);
  v10 = 4 * v3;
  v11 = 4 * v3 + 15;
  if ( v11 <= 4 * v3 )
    v11 = 1152921504606846960i64;
  v12 = alloca(v11);
  v13 = v10 + 15;
  v14 = fit_value;
  v62 = fit_value;
  if ( v10 + 15 <= v10 )
    v13 = 1152921504606846960i64;
  v15 = alloca(v13);
  v16 = v6 + 15;
  if ( v6 + 15 <= v6 )
    v16 = 1152921504606846960i64;
  v17 = v16 & 0xFFFFFFFFFFFFFFF0ui64;
  v18 = alloca(v17);
  v19 = 0;
  v20 = alloca(v17);
  v64 = 0;
  v21 = 0i64;
  v63 = fit_value;
  if ( (signed int)v3 > 0 )
  {
    v22 = v4;
    v23 = fit_value;
    v24 = (unsigned __int64)(4 * v22) >> 1;
    *(_QWORD *)fit_value = (char *)v8 - (char *)fit_value + 40;
    do
    {
      v25 = 0;
      if ( v5->submaps > 1 )
        v25 = (unsigned __int8)v5->chmuxlist[v21];
      v26 = (signed __int64)v5->submaplist[v25].floor << 6;
      v27 = 4i64 * *(int *)((char *)&v2->floor_param->posts + v26);
      v28 = v27 + 15;
      if ( v27 + 15 <= v27 )
        v28 = 1152921504606846960i64;
      v29 = alloca(v28);
      *(_QWORD *)v23 = fit_value;
      v30 = floor1_inverse1(v8, (vorbis_info_floor1 *)((char *)v2->floor_param + v26), fit_value);
      *(_QWORD *)v23 = v30;
      v31 = v30 == 0i64;
      v32 = *(_QWORD *)fit_value;
      fit_value[v21] = !v31;
      memset(*(void **)((char *)v23 + v32), 0, (unsigned int)v24);
      v2 = v66;
      ++v21;
      v23 += 2;
      ++v64;
    }
    while ( v64 < v8->channels );
    v14 = v62;
  }
  v33 = 0;
  if ( v5->coupling_steps > 0 )
  {
    v34 = 0i64;
    do
    {
      v35 = v5->coupling;
      v36 = &fit_value[(unsigned __int8)v35[v34].mag];
      if ( *v36 || fit_value[(unsigned __int8)v35[v34].ang] )
      {
        *v36 = 1;
        fit_value[(unsigned __int8)v5->coupling[v34].ang] = 1;
      }
      ++v33;
      ++v34;
    }
    while ( v33 < v5->coupling_steps );
  }
  v37 = 0;
  if ( v5->submaps > 0 )
  {
    v38 = 0i64;
    do
    {
      v39 = 0i64;
      v40 = 0;
      v41 = 0;
      if ( v8->channels > 0 )
      {
        v42 = fit_value;
        v43 = v14;
        v44 = v8->work;
        do
        {
          v45 = v5->chmuxlist;
          if ( !v45 || (unsigned __int8)v45[v39] == v37 )
          {
            ++v40;
            ++v43;
            *(v43 - 1) = fit_value[v39] != 0;
            v42 += 2;
            *((_QWORD *)v42 - 1) = *v44;
          }
          ++v41;
          ++v39;
          ++v44;
        }
        while ( v41 < v8->channels );
      }
      res_inverse(v8, &v66->residue_param[v5->submaplist[v38].residue], (int **)fit_value, v14, v40);
      ++v37;
      ++v38;
    }
    while ( v37 < v5->submaps );
  }
  v46 = v5->coupling_steps - 1;
  for ( i = v46; i >= 0; --i )
  {
    v48 = &v5->coupling[i];
    v49 = (char *)v8->work[(unsigned __int8)v48->mag];
    if ( n / 2 > 0i64 )
    {
      v50 = (char *)v8->work[(unsigned __int8)v48->ang] - v49;
      v51 = n / 2;
      do
      {
        v52 = *(_DWORD *)v49;
        v53 = *(_DWORD *)&v49[v50];
        if ( *(_DWORD *)v49 <= 0 )
        {
          if ( v53 <= 0 )
          {
            *(_DWORD *)&v49[v50] = v52;
            *(_DWORD *)v49 = v52 - v53;
          }
          else
          {
            *(_DWORD *)&v49[v50] = v52 + v53;
          }
        }
        else if ( v53 <= 0 )
        {
          *(_DWORD *)&v49[v50] = v52;
          *(_DWORD *)v49 = v52 + v53;
        }
        else
        {
          *(_DWORD *)&v49[v50] = v52 - v53;
        }
        v49 += 4;
        --v51;
      }
      while ( v51 );
    }
  }
  v54 = 0;
  v55 = 0i64;
  if ( v8->channels > 0 )
  {
    v56 = (int **)v63;
    v57 = (char *)v8 - (char *)v63;
    do
    {
      v58 = 0;
      if ( v5->submaps > 1 )
        v58 = (unsigned __int8)v5->chmuxlist[v55];
      floor1_inverse2(
        v8,
        &v66->floor_param[(signed __int64)v5->submaplist[v58].floor],
        *v56,
        *(int **)((char *)v56 + v57 + 40));
      ++v54;
      ++v55;
      ++v56;
    }
    while ( v54 < v8->channels );
    if ( v8->channels > 0 )
    {
      v59 = (float **)v8->work;
      do
      {
        mdct_backward(n, *v59);
        ++v19;
        ++v59;
      }
      while ( v19 < v8->channels );
    }
  }
  return 0i64;
}

