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
__int64 __fastcall mapping_info_unpack(
        vorbis_info_mapping *info,
        codec_setup_info *ci,
        int channels,
        oggpack_buffer *opb,
        CAkVorbisAllocator *VorbisAllocator)
{
  codec_setup_info *v5; // r12
  __int64 v8; // r15
  int v9; // esi
  int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // r8d
  coupling_step *pCurrentAddress; // rdx
  int v14; // edi
  int v15; // eax
  __int64 v16; // r12
  unsigned __int8 v17; // al
  int v18; // r13d
  unsigned __int8 v19; // al
  int v20; // ecx
  unsigned int v21; // r8d
  char *v22; // rdx
  __int64 v23; // rdi
  unsigned int v24; // ecx
  unsigned int v25; // r8d
  submap *v26; // rdx
  __int64 i; // rdi
  int bits; // [rsp+20h] [rbp-38h]

  v5 = ci;
  *(_QWORD *)&info->submaps = 0i64;
  info->chmuxlist = 0i64;
  info->submaplist = 0i64;
  *(_QWORD *)&info->coupling_steps = 0i64;
  info->coupling = 0i64;
  v8 = channels;
  if ( (unsigned int)oggpack_read(opb, 1) )
    info->submaps = oggpack_read(opb, 4) + 1;
  else
    info->submaps = 1;
  v9 = 0;
  if ( !(unsigned int)oggpack_read(opb, 1) )
    goto LABEL_16;
  v10 = oggpack_read(opb, 8) + 1;
  info->coupling_steps = v10;
  if ( 2 * v10
    && (v11 = (2 * v10 + 3) & 0xFFFFFFFC, v12 = v11 + VorbisAllocator->CurrentSize, v12 <= VorbisAllocator->MaxSize) )
  {
    pCurrentAddress = (coupling_step *)VorbisAllocator->pCurrentAddress;
    VorbisAllocator->CurrentSize = v12;
    VorbisAllocator->pCurrentAddress = &pCurrentAddress->mag + v11;
  }
  else
  {
    pCurrentAddress = 0i64;
  }
  info->coupling = pCurrentAddress;
  v14 = 0;
  if ( info->coupling_steps > 0 )
  {
    v15 = ilog(v8);
    v16 = 0i64;
    bits = v15;
    while ( 1 )
    {
      v17 = oggpack_read(opb, v15);
      info->coupling[v16].mag = v17;
      v18 = v17;
      v19 = oggpack_read(opb, bits);
      info->coupling[v16].ang = v19;
      if ( v18 == v19 || v18 >= (int)v8 || v19 >= (int)v8 )
        break;
      v15 = bits;
      ++v14;
      ++v16;
      if ( v14 >= info->coupling_steps )
      {
        v5 = ci;
        goto LABEL_16;
      }
    }
  }
  else
  {
LABEL_16:
    if ( (int)oggpack_read(opb, 2) <= 0 )
    {
      if ( info->submaps <= 1
        || (!(_DWORD)v8
         || (v20 = (v8 + 3) & 0xFFFFFFFC, v21 = v20 + VorbisAllocator->CurrentSize, v21 > VorbisAllocator->MaxSize)
          ? (v22 = 0i64)
          : (v22 = VorbisAllocator->pCurrentAddress,
             VorbisAllocator->CurrentSize = v21,
             VorbisAllocator->pCurrentAddress = &v22[v20]),
            info->chmuxlist = v22,
            v23 = 0i64,
            v8 <= 0) )
      {
LABEL_25:
        if ( 2 * info->submaps
          && (v24 = (2 * info->submaps + 3) & 0xFFFFFFFC,
              v25 = v24 + VorbisAllocator->CurrentSize,
              v25 <= VorbisAllocator->MaxSize) )
        {
          v26 = (submap *)VorbisAllocator->pCurrentAddress;
          VorbisAllocator->CurrentSize = v25;
          VorbisAllocator->pCurrentAddress = &v26->floor + v24;
        }
        else
        {
          v26 = 0i64;
        }
        info->submaplist = v26;
        if ( info->submaps <= 0 )
          return 0i64;
        for ( i = 0i64; ; ++i )
        {
          oggpack_read(opb, 8);
          info->submaplist[i].floor = oggpack_read(opb, 8);
          if ( info->submaplist[i].floor >= v5->floors )
            break;
          info->submaplist[i].residue = oggpack_read(opb, 8);
          if ( info->submaplist[i].residue >= v5->residues )
            break;
          if ( ++v9 >= info->submaps )
            return 0i64;
        }
      }
      else
      {
        while ( 1 )
        {
          info->chmuxlist[v23] = oggpack_read(opb, 4);
          if ( (unsigned __int8)info->chmuxlist[v23] >= info->submaps )
            break;
          if ( ++v23 >= v8 )
            goto LABEL_25;
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
  codec_setup_info *csi; // r9
  __int64 channels; // r8
  __int64 v4; // r12
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rax
  void *v9; // rsp
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax
  void *v12; // rsp
  __int64 v13; // rax
  int *v14; // r13
  void *v15; // rsp
  __int64 v16; // rax
  signed __int64 v17; // rax
  void *v18; // rsp
  int v19; // ebx
  void *v20; // rsp
  __int64 v21; // r14
  __int64 v22; // r13
  int *v23; // r12
  unsigned __int64 v24; // r13
  int v25; // eax
  __int64 v26; // rdx
  unsigned __int64 v27; // rcx
  __int64 v28; // rax
  void *v29; // rsp
  int *v30; // rax
  bool v31; // zf
  __int64 v32; // rax
  int v33; // r8d
  __int64 v34; // rdx
  coupling_step *coupling; // rcx
  int *v36; // r9
  int v37; // r14d
  __int64 v38; // r12
  __int64 v39; // rcx
  int v40; // r11d
  int v41; // r8d
  int *v42; // r9
  int *v43; // r10
  int **work; // rdx
  char *chmuxlist; // rax
  int v46; // eax
  __int64 i; // r10
  coupling_step *v48; // rcx
  int *v49; // rdx
  char *v50; // r9
  __int64 v51; // r8
  int v52; // eax
  int v53; // ecx
  int v54; // r15d
  __int64 v55; // r14
  int **v56; // r13
  char *v57; // r12
  int v58; // eax
  int **v59; // rdi
  int fit_value[2]; // [rsp+30h] [rbp+0h] BYREF
  int *v62; // [rsp+38h] [rbp+8h]
  int *v63; // [rsp+40h] [rbp+10h]
  int v64; // [rsp+A0h] [rbp+70h]
  int n; // [rsp+A8h] [rbp+78h]
  codec_setup_info *v66; // [rsp+B0h] [rbp+80h]

  csi = vd->csi;
  channels = vd->channels;
  v4 = csi->blocksizes[vd->state.W];
  v6 = 8 * channels;
  v7 = 8 * channels + 15;
  v66 = csi;
  n = csi->blocksizes[vd->state.W];
  if ( v7 <= 8 * channels )
    v7 = 0xFFFFFFFFFFFFFF0i64;
  v9 = alloca(v7 & 0xFFFFFFFFFFFFFFF0ui64);
  v10 = 4 * channels;
  v11 = 4 * channels + 15;
  if ( v11 <= 4 * channels )
    v11 = 0xFFFFFFFFFFFFFF0i64;
  v12 = alloca(v11 & 0xFFFFFFFFFFFFFFF0ui64);
  v13 = v10 + 15;
  v14 = fit_value;
  v62 = fit_value;
  if ( v10 + 15 <= v10 )
    v13 = 0xFFFFFFFFFFFFFF0i64;
  v15 = alloca(v13 & 0xFFFFFFFFFFFFFFF0ui64);
  v16 = v6 + 15;
  if ( v6 + 15 <= v6 )
    v16 = 0xFFFFFFFFFFFFFF0i64;
  v17 = v16 & 0xFFFFFFFFFFFFFFF0ui64;
  v18 = alloca(v17);
  v19 = 0;
  v20 = alloca(v17);
  v64 = 0;
  v21 = 0i64;
  v63 = fit_value;
  if ( (int)channels > 0 )
  {
    v22 = v4;
    v23 = fit_value;
    v24 = (unsigned __int64)(4 * v22) >> 1;
    *(_QWORD *)fit_value = (char *)vd - (char *)fit_value + 40;
    do
    {
      v25 = 0;
      if ( info->submaps > 1 )
        v25 = (unsigned __int8)info->chmuxlist[v21];
      v26 = (__int64)info->submaplist[v25].floor << 6;
      v27 = 4i64 * *(int *)((char *)&csi->floor_param->posts + v26);
      v28 = v27 + 15;
      if ( v27 + 15 <= v27 )
        v28 = 0xFFFFFFFFFFFFFF0i64;
      v29 = alloca(v28 & 0xFFFFFFFFFFFFFFF0ui64);
      *(_QWORD *)v23 = fit_value;
      v30 = floor1_inverse1(vd, (vorbis_info_floor1 *)((char *)csi->floor_param + v26), fit_value);
      *(_QWORD *)v23 = v30;
      v31 = v30 == 0i64;
      v32 = *(_QWORD *)fit_value;
      fit_value[v21] = !v31;
      memset(*(void **)((char *)v23 + v32), 0, (unsigned int)v24);
      csi = v66;
      ++v21;
      v23 += 2;
      ++v64;
    }
    while ( v64 < vd->channels );
    v14 = v62;
  }
  v33 = 0;
  if ( info->coupling_steps > 0 )
  {
    v34 = 0i64;
    do
    {
      coupling = info->coupling;
      v36 = &fit_value[(unsigned __int8)coupling[v34].mag];
      if ( *v36 || fit_value[(unsigned __int8)coupling[v34].ang] )
      {
        *v36 = 1;
        fit_value[(unsigned __int8)info->coupling[v34].ang] = 1;
      }
      ++v33;
      ++v34;
    }
    while ( v33 < info->coupling_steps );
  }
  v37 = 0;
  if ( info->submaps > 0 )
  {
    v38 = 0i64;
    do
    {
      v39 = 0i64;
      v40 = 0;
      v41 = 0;
      if ( vd->channels > 0 )
      {
        v42 = fit_value;
        v43 = v14;
        work = vd->work;
        do
        {
          chmuxlist = info->chmuxlist;
          if ( !chmuxlist || (unsigned __int8)chmuxlist[v39] == v37 )
          {
            ++v40;
            *v43++ = fit_value[v39] != 0;
            v42 += 2;
            *((_QWORD *)v42 - 1) = *work;
          }
          ++v41;
          ++v39;
          ++work;
        }
        while ( v41 < vd->channels );
      }
      res_inverse(vd, &v66->residue_param[info->submaplist[v38].residue], (int **)fit_value, v14, v40);
      ++v37;
      ++v38;
    }
    while ( v37 < info->submaps );
  }
  v46 = info->coupling_steps - 1;
  for ( i = v46; i >= 0; --i )
  {
    v48 = &info->coupling[i];
    v49 = vd->work[(unsigned __int8)v48->mag];
    if ( n / 2 > 0i64 )
    {
      v50 = (char *)((char *)vd->work[(unsigned __int8)v48->ang] - (char *)v49);
      v51 = n / 2;
      do
      {
        v52 = *v49;
        v53 = *(int *)((char *)v49 + (_QWORD)v50);
        if ( *v49 <= 0 )
        {
          if ( v53 <= 0 )
          {
            *(int *)((char *)v49 + (_QWORD)v50) = v52;
            *v49 = v52 - v53;
          }
          else
          {
            *(int *)((char *)v49 + (_QWORD)v50) = v52 + v53;
          }
        }
        else if ( v53 <= 0 )
        {
          *(int *)((char *)v49 + (_QWORD)v50) = v52;
          *v49 = v52 + v53;
        }
        else
        {
          *(int *)((char *)v49 + (_QWORD)v50) = v52 - v53;
        }
        ++v49;
        --v51;
      }
      while ( v51 );
    }
  }
  v54 = 0;
  v55 = 0i64;
  if ( vd->channels > 0 )
  {
    v56 = (int **)v63;
    v57 = (char *)((char *)vd - (char *)v63);
    do
    {
      v58 = 0;
      if ( info->submaps > 1 )
        v58 = (unsigned __int8)info->chmuxlist[v55];
      floor1_inverse2(
        vd,
        &v66->floor_param[(__int64)info->submaplist[v58].floor],
        *v56,
        *(int **)((char *)v56 + (_QWORD)v57 + 40));
      ++v54;
      ++v55;
      ++v56;
    }
    while ( v54 < vd->channels );
    if ( vd->channels > 0 )
    {
      v59 = vd->work;
      do
      {
        mdct_backward(n, (float *)*v59);
        ++v19;
        ++v59;
      }
      while ( v19 < vd->channels );
    }
  }
  return 0i64;
}

