// File Line: 41
// RVA: 0xABE640
__int64 __fastcall vorbis_info_init(codec_setup_info *csi, char in_blocksize0, char in_blocksize1)
{
  int v3; // r9d
  int v4; // edx

  *(_QWORD *)csi->blocksizes = 0i64;
  *(_QWORD *)&csi->modes = 0i64;
  *(_QWORD *)&csi->floors = 0i64;
  *(_QWORD *)&csi->books = 0i64;
  csi->mode_param = 0i64;
  csi->map_param = 0i64;
  csi->floor_param = 0i64;
  csi->residue_param = 0i64;
  csi->book_param = 0i64;
  v3 = 1 << in_blocksize0;
  v4 = 1 << in_blocksize1;
  csi->blocksizes[0] = v3;
  csi->blocksizes[1] = 1 << in_blocksize1;
  if ( v3 < 64 || v4 < v3 || v4 > 0x2000 )
    return 4294967163i64;
  else
    return 0i64;
}

// File Line: 77
// RVA: 0xABE6A0
__int64 __fastcall vorbis_unpack_books(
        codec_setup_info *ci,
        int channels,
        oggpack_buffer *opb,
        CAkVorbisAllocator *VorbisAllocator)
{
  int v8; // esi
  int v9; // eax
  size_t v10; // r8
  unsigned int v11; // ecx
  unsigned int v12; // edx
  codebook *pCurrentAddress; // rbp
  int i; // ebp
  int v15; // eax
  int v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // edx
  unsigned int v19; // r8d
  vorbis_info_floor1 *v20; // rbp
  int v21; // ebp
  int v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // r8d
  char *v25; // rdx
  int v26; // ebp
  int v27; // eax
  unsigned int v28; // ecx
  unsigned int v29; // r8d
  char *v30; // rdx
  int v31; // ebp
  int v32; // eax
  unsigned int v33; // ecx
  unsigned int v34; // r8d
  vorbis_info_mode *v35; // rdx
  __int64 j; // rdi
  oggpack_buffer opba; // [rsp+30h] [rbp-38h] BYREF

  v8 = 0;
  v9 = oggpack_read(opb, 8) + 1;
  ci->books = v9;
  v10 = (unsigned int)(72 * v9);
  if ( (_DWORD)v10
    && (v11 = (v10 + 3) & 0xFFFFFFFC, v12 = v11 + VorbisAllocator->CurrentSize, v12 <= VorbisAllocator->MaxSize) )
  {
    pCurrentAddress = (codebook *)VorbisAllocator->pCurrentAddress;
    VorbisAllocator->CurrentSize = v12;
    VorbisAllocator->pCurrentAddress = (char *)pCurrentAddress + v11;
    if ( pCurrentAddress )
      memset(pCurrentAddress, 0, v10);
  }
  else
  {
    pCurrentAddress = 0i64;
  }
  ci->book_param = pCurrentAddress;
  for ( i = 0; i < ci->books; ++i )
  {
    v15 = oggpack_read(opb, 10);
    opba.headbit = 0;
    opba.headend = 874;
    opba.headptr = (char *)g_packedCodebooks[v15];
    vorbis_book_unpack(&opba, &ci->book_param[i], VorbisAllocator);
  }
  v16 = oggpack_read(opb, 6);
  ci->floors = v16 + 1;
  v17 = (v16 + 1) << 6;
  if ( v17 && (v18 = (v17 + 3) & 0xFFFFFFFC, v19 = v18 + VorbisAllocator->CurrentSize, v19 <= VorbisAllocator->MaxSize) )
  {
    v20 = (vorbis_info_floor1 *)VorbisAllocator->pCurrentAddress;
    VorbisAllocator->CurrentSize = v19;
    VorbisAllocator->pCurrentAddress = (char *)v20 + v18;
    if ( v20 )
      memset(v20, 0, v17);
  }
  else
  {
    v20 = 0i64;
  }
  ci->floor_param = v20;
  v21 = 0;
  if ( ci->floors <= 0 )
  {
LABEL_16:
    v22 = oggpack_read(opb, 6) + 1;
    ci->residues = v22;
    if ( 40 * v22
      && (v23 = (40 * v22 + 3) & 0xFFFFFFFC, v24 = v23 + VorbisAllocator->CurrentSize, v24 <= VorbisAllocator->MaxSize) )
    {
      v25 = VorbisAllocator->pCurrentAddress;
      VorbisAllocator->CurrentSize = v24;
      VorbisAllocator->pCurrentAddress = &v25[v23];
    }
    else
    {
      v25 = 0i64;
    }
    ci->residue_param = (vorbis_info_residue *)v25;
    v26 = 0;
    if ( ci->residues <= 0 )
    {
LABEL_23:
      v27 = oggpack_read(opb, 6) + 1;
      ci->maps = v27;
      if ( 40 * v27
        && (v28 = (40 * v27 + 3) & 0xFFFFFFFC, v29 = v28 + VorbisAllocator->CurrentSize, v29 <= VorbisAllocator->MaxSize) )
      {
        v30 = VorbisAllocator->pCurrentAddress;
        VorbisAllocator->CurrentSize = v29;
        VorbisAllocator->pCurrentAddress = &v30[v28];
      }
      else
      {
        v30 = 0i64;
      }
      ci->map_param = (vorbis_info_mapping *)v30;
      v31 = 0;
      if ( ci->maps <= 0 )
      {
LABEL_30:
        v32 = oggpack_read(opb, 6) + 1;
        ci->modes = v32;
        if ( 2 * v32
          && (v33 = (2 * v32 + 3) & 0xFFFFFFFC, v34 = v33 + VorbisAllocator->CurrentSize,
                                                v34 <= VorbisAllocator->MaxSize) )
        {
          v35 = (vorbis_info_mode *)VorbisAllocator->pCurrentAddress;
          VorbisAllocator->CurrentSize = v34;
          VorbisAllocator->pCurrentAddress = &v35->blockflag + v33;
        }
        else
        {
          v35 = 0i64;
        }
        ci->mode_param = v35;
        if ( ci->modes <= 0 )
          return 0i64;
        for ( j = 0i64; ; ++j )
        {
          ci->mode_param[j].blockflag = oggpack_read(opb, 1);
          ci->mode_param[j].mapping = oggpack_read(opb, 8);
          if ( (unsigned __int8)ci->mode_param[j].mapping >= ci->maps )
            break;
          if ( ++v8 >= ci->modes )
            return 0i64;
        }
      }
      else
      {
        while ( !(unsigned int)mapping_info_unpack(&ci->map_param[v31], ci, channels, opb, VorbisAllocator) )
        {
          if ( ++v31 >= ci->maps )
            goto LABEL_30;
        }
      }
    }
    else
    {
      while ( !res_unpack(&ci->residue_param[v26], ci, opb, VorbisAllocator) )
      {
        if ( ++v26 >= ci->residues )
          goto LABEL_23;
      }
    }
  }
  else
  {
    while ( !floor1_info_unpack(&ci->floor_param[(__int64)v21], ci, opb, VorbisAllocator) )
    {
      if ( ++v21 >= ci->floors )
        goto LABEL_16;
    }
  }
  return 4294967163i64;
}

