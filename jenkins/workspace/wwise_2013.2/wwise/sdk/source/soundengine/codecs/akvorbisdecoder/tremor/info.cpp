// File Line: 41
// RVA: 0xABE640
signed __int64 __fastcall vorbis_info_init(codec_setup_info *csi, int in_blocksize0, int in_blocksize1)
{
  signed int v3; // er9
  signed int v4; // edx
  signed __int64 result; // rax

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
    result = 4294967163i64;
  else
    result = 0i64;
  return result;
}

// File Line: 77
// RVA: 0xABE6A0
signed __int64 __fastcall vorbis_unpack_books(codec_setup_info *ci, int channels, oggpack_buffer *opb, CAkVorbisAllocator *VorbisAllocator)
{
  int v4; // er15
  codec_setup_info *v5; // rbx
  CAkVorbisAllocator *v6; // rdi
  oggpack_buffer *v7; // r14
  int v8; // esi
  int v9; // eax
  size_t v10; // r8
  unsigned int v11; // ecx
  unsigned int v12; // edx
  codebook *v13; // rbp
  int i; // ebp
  int v15; // eax
  int v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // edx
  unsigned int v19; // er8
  vorbis_info_floor1 *v20; // rbp
  int v21; // ebp
  int v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // er8
  char *v25; // rdx
  int v26; // ebp
  int v27; // eax
  unsigned int v28; // ecx
  unsigned int v29; // er8
  char *v30; // rdx
  int v31; // ebp
  int v32; // eax
  unsigned int v33; // ecx
  unsigned int v34; // er8
  vorbis_info_mode *v35; // rdx
  __int64 v36; // rdi
  oggpack_buffer opba; // [rsp+30h] [rbp-38h]

  v4 = channels;
  v5 = ci;
  v6 = VorbisAllocator;
  v7 = opb;
  v8 = 0;
  v9 = (unsigned __int64)oggpack_read(opb, 8) + 1;
  v5->books = v9;
  v10 = (unsigned int)(72 * v9);
  if ( (_DWORD)v10 && (v11 = (v10 + 3) & 0xFFFFFFFC, v12 = v11 + v6->CurrentSize, v12 <= v6->MaxSize) )
  {
    v13 = (codebook *)v6->pCurrentAddress;
    v6->CurrentSize = v12;
    v6->pCurrentAddress = (char *)v13 + v11;
    if ( v13 )
      memset(v13, 0, v10);
  }
  else
  {
    v13 = 0i64;
  }
  v5->book_param = v13;
  for ( i = 0; i < v5->books; ++i )
  {
    v15 = oggpack_read(v7, 10);
    opba.headbit = 0;
    opba.headend = 874;
    opba.headptr = (char *)g_packedCodebooks[v15];
    vorbis_book_unpack(&opba, &v5->book_param[i], v6);
  }
  v16 = oggpack_read(v7, 6);
  v5->floors = v16 + 1;
  v17 = (v16 + 1) << 6;
  if ( v17 && (v18 = (v17 + 3) & 0xFFFFFFFC, v19 = v18 + v6->CurrentSize, v19 <= v6->MaxSize) )
  {
    v20 = (vorbis_info_floor1 *)v6->pCurrentAddress;
    v6->CurrentSize = v19;
    v6->pCurrentAddress = (char *)v20 + v18;
    if ( v20 )
      memset(v20, 0, v17);
  }
  else
  {
    v20 = 0i64;
  }
  v5->floor_param = v20;
  v21 = 0;
  if ( v5->floors <= 0 )
  {
LABEL_16:
    v22 = (unsigned __int64)oggpack_read(v7, 6) + 1;
    v5->residues = v22;
    if ( 40 * v22 && (v23 = (40 * v22 + 3) & 0xFFFFFFFC, v24 = v23 + v6->CurrentSize, v24 <= v6->MaxSize) )
    {
      v25 = v6->pCurrentAddress;
      v6->CurrentSize = v24;
      v6->pCurrentAddress = &v25[v23];
    }
    else
    {
      v25 = 0i64;
    }
    v5->residue_param = (vorbis_info_residue *)v25;
    v26 = 0;
    if ( v5->residues <= 0 )
    {
LABEL_23:
      v27 = (unsigned __int64)oggpack_read(v7, 6) + 1;
      v5->maps = v27;
      if ( 40 * v27 && (v28 = (40 * v27 + 3) & 0xFFFFFFFC, v29 = v28 + v6->CurrentSize, v29 <= v6->MaxSize) )
      {
        v30 = v6->pCurrentAddress;
        v6->CurrentSize = v29;
        v6->pCurrentAddress = &v30[v28];
      }
      else
      {
        v30 = 0i64;
      }
      v5->map_param = (vorbis_info_mapping *)v30;
      v31 = 0;
      if ( v5->maps <= 0 )
      {
LABEL_30:
        v32 = (unsigned __int64)oggpack_read(v7, 6) + 1;
        v5->modes = v32;
        if ( 2 * v32 && (v33 = (2 * v32 + 3) & 0xFFFFFFFC, v34 = v33 + v6->CurrentSize, v34 <= v6->MaxSize) )
        {
          v35 = (vorbis_info_mode *)v6->pCurrentAddress;
          v6->CurrentSize = v34;
          v6->pCurrentAddress = &v35->blockflag + v33;
        }
        else
        {
          v35 = 0i64;
        }
        v5->mode_param = v35;
        if ( v5->modes <= 0 )
          return 0i64;
        v36 = 0i64;
        while ( 1 )
        {
          v5->mode_param[v36].blockflag = oggpack_read(v7, 1);
          v5->mode_param[v36].mapping = oggpack_read(v7, 8);
          if ( (unsigned __int8)v5->mode_param[v36].mapping >= v5->maps )
            break;
          ++v8;
          ++v36;
          if ( v8 >= v5->modes )
            return 0i64;
        }
      }
      else
      {
        while ( !(unsigned int)mapping_info_unpack(&v5->map_param[v31], v5, v4, v7, v6) )
        {
          if ( ++v31 >= v5->maps )
            goto LABEL_30;
        }
      }
    }
    else
    {
      while ( !res_unpack(&v5->residue_param[v26], v5, v7, v6) )
      {
        if ( ++v26 >= v5->residues )
          goto LABEL_23;
      }
    }
  }
  else
  {
    while ( !floor1_info_unpack(&v5->floor_param[(signed __int64)v21], v5, v7, v6) )
    {
      if ( ++v21 >= v5->floors )
        goto LABEL_16;
    }
  }
  return 4294967163i64;
}

