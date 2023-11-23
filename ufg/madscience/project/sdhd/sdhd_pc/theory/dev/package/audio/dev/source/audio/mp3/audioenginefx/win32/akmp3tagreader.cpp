// File Line: 137
// RVA: 0xA355E0
char *__fastcall AkMP3SyncToFirstFrame(char *in_pFile, AkMP3FrameHeader *io_hdr)
{
  char *v2; // r9
  unsigned __int8 v3; // r8
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax

  v2 = in_pFile + 4096;
  while ( in_pFile < v2 )
  {
    if ( *in_pFile == -1 )
    {
      v3 = in_pFile[1];
      if ( (v3 & 0xE0) == 0xE0 )
      {
        v4 = (v3 >> 3) & 3;
        io_hdr->uVersion = v4;
        if ( v4 != 1 )
        {
          v5 = ((unsigned __int8)in_pFile[1] >> 1) & 3;
          io_hdr->uLayer = v5;
          if ( v5 == 1 )
          {
            io_hdr->uProtection = in_pFile[1] & 1;
            v6 = (unsigned __int8)in_pFile[2] >> 4;
            io_hdr->uBitRate = v6;
            if ( v6 )
            {
              if ( v6 != 15 )
              {
                v7 = ((unsigned __int8)in_pFile[2] >> 2) & 3;
                io_hdr->uSampleRate = v7;
                if ( v7 != 3 )
                {
                  io_hdr->uPadding = ((unsigned __int8)in_pFile[2] >> 1) & 1;
                  io_hdr->uPrivate = in_pFile[2] & 1;
                  io_hdr->uChannelMode = (unsigned __int8)in_pFile[3] >> 6;
                  io_hdr->uModeExtension = ((unsigned __int8)in_pFile[3] >> 4) & 3;
                  io_hdr->uCopyright = ((unsigned __int8)in_pFile[3] >> 3) & 1;
                  io_hdr->uOriginal = ((unsigned __int8)in_pFile[3] >> 2) & 1;
                  v8 = in_pFile[3] & 3;
                  io_hdr->uEmphasis = v8;
                  if ( v8 != 2 )
                    return in_pFile;
                }
              }
            }
          }
        }
      }
    }
    ++in_pFile;
  }
  return 0i64;
}

// File Line: 176
// RVA: 0xA363D0
void __fastcall ReadTextField(char *in_pText, int in_iInTextLen, wchar_t *out_pText, int in_iOutTextLen)
{
  int v4; // eax
  char *v5; // rcx
  __int64 cchWideChar; // rdi
  wchar_t *lpWideCharStr; // rbx
  int v8; // r9d
  int v9; // eax
  int v10; // eax
  const char *v11; // r8
  UINT v12; // ecx
  wchar_t *v13; // rdx
  wchar_t *v14; // r8
  wchar_t v15; // ax
  unsigned __int64 v16; // r9
  wchar_t *v17; // rdx
  char *i; // r8
  __int16 v19; // ax
  int v20; // eax

  v4 = (unsigned __int8)*in_pText;
  v5 = in_pText + 1;
  cchWideChar = in_iOutTextLen;
  lpWideCharStr = out_pText;
  v8 = in_iInTextLen - 1;
  if ( v4 )
  {
    v9 = v4 - 1;
    if ( v9 )
    {
      v10 = v9 - 1;
      if ( v10 )
      {
        if ( v10 != 1 )
          return;
        v11 = v5;
        v12 = 65001;
        goto LABEL_23;
      }
    }
    else
    {
      if ( *v5 == -1 && v5[1] == -2 )
      {
        v13 = (wchar_t *)(v5 + 2);
        v14 = &out_pText[cchWideChar];
        v15 = *((_WORD *)v5 + 1);
        v16 = (unsigned __int64)&v5[2 * ((__int64)(v8 - 2) >> 1) + 2];
        if ( v15 )
        {
          do
          {
            if ( (unsigned __int64)v13 >= v16 )
              break;
            if ( lpWideCharStr >= v14 )
              goto LABEL_13;
            ++v13;
            *lpWideCharStr++ = v15;
            v15 = *v13;
          }
          while ( *v13 );
        }
        if ( lpWideCharStr >= v14 )
        {
LABEL_13:
          *(v14 - 1) = 0;
          return;
        }
        goto LABEL_14;
      }
      v5 += 2;
      v8 = in_iInTextLen - 3;
    }
    v17 = &out_pText[cchWideChar];
    for ( i = &v5[2 * ((__int64)v8 >> 1)]; *(_WORD *)v5; *(lpWideCharStr - 1) = __ROR2__(v19, 8) )
    {
      if ( v5 >= i )
        break;
      if ( lpWideCharStr >= v17 )
        goto LABEL_21;
      v19 = *(_WORD *)v5;
      v5 += 2;
      ++lpWideCharStr;
    }
    if ( lpWideCharStr >= v17 )
    {
LABEL_21:
      *(v17 - 1) = 0;
      return;
    }
LABEL_14:
    *lpWideCharStr = 0;
    return;
  }
  v11 = v5;
  v12 = 1252;
LABEL_23:
  v20 = MultiByteToWideChar(v12, 0, v11, v8, lpWideCharStr, cchWideChar);
  if ( v20 < (int)cchWideChar )
    lpWideCharStr[v20] = 0;
}

// File Line: 244
// RVA: 0xA34B10
char __fastcall AkMP3InfoRead(const char *in_tszFilename, AkMP3BaseInfo *out_info, AkMP3Tag *out_pTag)
{
  AkMP3BaseInfo *v4; // r13
  HANDLE FileA; // rax
  HANDLE v6; // rbx
  HANDLE FileMappingA; // rax
  void *v8; // rdi
  LPVOID v9; // rax
  char v10; // si
  char *v11; // r8
  char *v12; // rbx
  int v14; // eax
  int v15; // r15d
  _BYTE *v16; // rbx
  _BYTE *v17; // r13
  unsigned int v18; // edi
  char v19; // cl
  char v20; // al
  char v21; // al
  AkMP3Tag *wszTrack; // r8
  char v23; // al
  char v24; // al
  int v25; // ecx
  char *v26; // rbx
  char *v27; // r13
  unsigned int v28; // edi
  char v29; // cl
  char v30; // al
  char v31; // al
  AkMP3Tag *wszArtist; // r8
  char v33; // al
  char v34; // al
  char *v35; // r9
  char v36; // r10
  unsigned int uVersion; // edi
  int v38; // ecx
  unsigned int uChannelMode; // edx
  unsigned int v40; // eax
  unsigned int uBitRate; // r15d
  char *v42; // r9
  char v43; // al
  char v44; // r10
  unsigned int *v45; // r9
  unsigned __int32 v46; // r11d
  int v47; // eax
  unsigned int i; // edx
  DWORD FileSize; // eax
  unsigned int v50; // edi
  unsigned int v51; // ecx
  int v52; // eax
  int v53; // eax
  int v54; // eax
  char *v56; // [rsp+48h] [rbp-120h]
  HANDLE hObject; // [rsp+60h] [rbp-108h]
  LPCVOID lpBaseAddress; // [rsp+68h] [rbp-100h]
  AkMP3FrameHeader io_hdr; // [rsp+78h] [rbp-F0h] BYREF
  char Buffer[3]; // [rsp+B0h] [rbp-B8h] BYREF
  char v61[30]; // [rsp+B3h] [rbp-B5h] BYREF
  char v62[30]; // [rsp+D1h] [rbp-97h] BYREF
  char MultiByteStr[121]; // [rsp+EFh] [rbp-79h] BYREF
  unsigned int NumberOfBytesRead; // [rsp+180h] [rbp+18h] BYREF
  HANDLE hFile; // [rsp+188h] [rbp+20h]

  v4 = out_info;
  if ( out_pTag )
  {
    out_pTag->wszAlbum[0] = 0;
    out_pTag->wszArtist[0] = 0;
    out_pTag->wszTrack[0] = 0;
  }
  FileA = CreateFileA(in_tszFilename, 0x80000000, 1u, 0i64, 3u, 0x10000080u, 0i64);
  v6 = FileA;
  hFile = FileA;
  if ( !FileA )
    return 0;
  FileMappingA = CreateFileMappingA(FileA, 0i64, 2u, 0, 0, 0i64);
  v8 = FileMappingA;
  hObject = FileMappingA;
  if ( !FileMappingA )
  {
LABEL_152:
    CloseHandle(v6);
    return 0;
  }
  v9 = MapViewOfFile(FileMappingA, 4u, 0, 0, 0i64);
  lpBaseAddress = v9;
  if ( !v9 )
    goto $error_result;
  v10 = 0;
  v11 = (char *)v9;
  v56 = (char *)v9;
  v12 = (char *)v9;
LABEL_7:
  if ( *v12 == 73 && v12[1] == 68 && v12[2] == 51 )
  {
    v14 = (unsigned __int8)v12[3];
    if ( v14 == 2 )
    {
      v15 = (unsigned __int8)v12[9] | (((unsigned __int8)v12[8] | ((((unsigned __int8)v12[6] << 7) | (unsigned __int8)v12[7]) << 7)) << 7);
      if ( !out_pTag )
        goto LABEL_79;
      v16 = v12 + 10;
      v17 = v16;
      while ( 2 )
      {
        if ( v16 - v17 + 6 >= v15 )
          goto LABEL_78;
        v18 = (unsigned __int8)v16[5] | ((((unsigned __int8)v16[3] << 8) | (unsigned __int8)v16[4]) << 8);
        v19 = *v16;
        if ( *v16 || v16[1] || (v20 = 1, v16[2]) )
          v20 = 0;
        if ( v20 || !v18 )
          goto LABEL_78;
        if ( v19 != 84 || v16[1] != 84 || (v21 = 1, v16[2] != 50) )
          v21 = 0;
        if ( v21 )
        {
          wszTrack = (AkMP3Tag *)out_pTag->wszTrack;
          goto LABEL_41;
        }
        if ( v19 != 84 || v16[1] != 65 || (v23 = 1, v16[2] != 76) )
          v23 = 0;
        if ( v23 )
        {
          wszTrack = out_pTag;
          goto LABEL_41;
        }
        if ( v19 != 84 || v16[1] != 80 || (v24 = 1, v16[2] != 49) )
          v24 = 0;
        if ( v24 )
        {
          wszTrack = (AkMP3Tag *)out_pTag->wszArtist;
LABEL_41:
          ReadTextField(v16 + 6, v18, wszTrack->wszAlbum, 256);
          v10 = 1;
        }
        v16 += v18 + 6;
        continue;
      }
    }
    if ( (unsigned int)(v14 - 3) > 1 )
      goto LABEL_80;
    v25 = ((unsigned __int8)v12[5] >> 6) & 1;
    v15 = (unsigned __int8)v12[9] | (((unsigned __int8)v12[8] | ((((unsigned __int8)v12[6] << 7) | (unsigned __int8)v12[7]) << 7)) << 7);
    if ( !out_pTag )
      goto LABEL_79;
    v26 = v12 + 10;
    v27 = v26;
    if ( v25 )
      v26 += (((unsigned __int8)v26[2] | (((unsigned __int8)v26[1] | ((unsigned __int8)*v26 << 7)) << 7)) << 7) | (unsigned int)(unsigned __int8)v26[3];
    while ( 1 )
    {
      if ( v26 - v27 + 10 >= v15 )
        goto LABEL_78;
      v28 = (unsigned __int8)v26[7] | (((unsigned __int8)v26[6] | (((unsigned __int8)v26[5] | ((unsigned __int8)v26[4] << 7)) << 7)) << 7);
      v29 = *v26;
      if ( *v26 || v26[1] || v26[2] || (v30 = 1, v26[3]) )
        v30 = 0;
      if ( v30 || !v28 )
      {
LABEL_78:
        v11 = v56;
LABEL_79:
        v11 += (unsigned int)(v15 + 10);
        v56 = v11;
LABEL_80:
        v12 = v11;
        goto LABEL_7;
      }
      if ( v29 != 84 || v26[1] != 73 || v26[2] != 84 || (v31 = 1, v26[3] != 50) )
        v31 = 0;
      if ( v31 )
        break;
      if ( v29 != 84 || v26[1] != 65 || v26[2] != 76 || (v33 = 1, v26[3] != 66) )
        v33 = 0;
      if ( v33 )
      {
        wszArtist = out_pTag;
        goto LABEL_76;
      }
      if ( v29 != 84 || v26[1] != 80 || v26[2] != 69 || (v34 = 1, v26[3] != 49) )
        v34 = 0;
      if ( v34 )
      {
        wszArtist = (AkMP3Tag *)out_pTag->wszArtist;
        goto LABEL_76;
      }
LABEL_77:
      v26 += v28 + 10;
    }
    wszArtist = (AkMP3Tag *)out_pTag->wszTrack;
LABEL_76:
    ReadTextField(v26 + 10, v28, wszArtist->wszAlbum, 256);
    v10 = 1;
    goto LABEL_77;
  }
  v35 = AkMP3SyncToFirstFrame(v11, &io_hdr);
  if ( !v35 )
  {
    v4 = out_info;
    v6 = hFile;
    v8 = hObject;
$error_result:
    memset(v4, 0, sizeof(AkMP3BaseInfo));
    if ( lpBaseAddress )
      UnmapViewOfFile(lpBaseAddress);
    CloseHandle(v8);
    goto LABEL_152;
  }
  uVersion = io_hdr.uVersion;
  if ( io_hdr.uVersion )
  {
    if ( io_hdr.uVersion == 2 )
    {
      v38 = `AkMP3FrameHeader::GetSampleRate::`2::s_aSampleRatesMPEG2[io_hdr.uSampleRate];
    }
    else if ( io_hdr.uVersion == 3 )
    {
      v38 = `AkMP3FrameHeader::GetSampleRate::`2::s_aSampleRatesMPEG1[io_hdr.uSampleRate];
    }
    else
    {
      v38 = 0;
    }
  }
  else
  {
    v38 = `AkMP3FrameHeader::GetSampleRate::`2::s_aSampleRatesMPEG2_5[io_hdr.uSampleRate];
  }
  NumberOfBytesRead = v38;
  out_info->uSampleRate = v38;
  uChannelMode = io_hdr.uChannelMode;
  out_info->uNumChannels = (io_hdr.uChannelMode != 3) + 1;
  out_info->msDuration = 0;
  if ( !uVersion || uVersion == 2 )
  {
    uBitRate = io_hdr.uBitRate;
    v40 = `AkMP3FrameHeader::GetBitRate::`2::s_aBitRatesMPEG2[io_hdr.uBitRate];
  }
  else if ( uVersion == 3 )
  {
    uBitRate = io_hdr.uBitRate;
    v40 = `AkMP3FrameHeader::GetBitRate::`2::s_aBitRatesMPEG1[io_hdr.uBitRate];
  }
  else
  {
    v40 = 0;
    uBitRate = io_hdr.uBitRate;
  }
  out_info->uBitRate = v40;
  out_info->uFirstFrameOffset = (_DWORD)v35 - (_DWORD)lpBaseAddress;
  out_info->uMPEGStreamSize = 0;
  out_info->bToc = 0;
  if ( (uVersion & 1) != 0 )
  {
    if ( uChannelMode != 3 )
    {
      v42 = v35 + 36;
      goto LABEL_102;
    }
  }
  else if ( uChannelMode == 3 )
  {
    v42 = v35 + 13;
    goto LABEL_102;
  }
  v42 = v35 + 21;
LABEL_102:
  v43 = 0;
  if ( *v42 == 88 && v42[1] == 105 && v42[2] == 110 )
  {
    v43 = 0;
    if ( v42[3] == 103 )
      v43 = v36;
  }
  if ( *v42 == 73 && v42[1] == 110 && v42[2] == 102 && v42[3] == 111 || v43 )
  {
    v44 = _byteswap_ulong(*((_DWORD *)v42 + 1));
    v45 = (unsigned int *)(v42 + 8);
    if ( (v44 & 1) != 0 )
    {
      v46 = _byteswap_ulong(*v45);
      if ( (uVersion & 1) != 0 )
        v47 = 23040
            * v46
            / (((unsigned int)((1374389535 * (unsigned __int64)(unsigned __int16)v38) >> 32) >> 31)
             + (unsigned __int16)v38 / 0x32u);
      else
        v47 = 11520
            * v46
            / (((unsigned int)((1374389535 * (unsigned __int64)(unsigned __int16)v38) >> 32) >> 31)
             + (unsigned __int16)v38 / 0x32u);
      out_info->msDuration = v47;
      ++v45;
    }
    if ( (v44 & 2) != 0 )
      out_info->uMPEGStreamSize = _byteswap_ulong(*v45++);
    if ( (v44 & 4) != 0 )
    {
      out_info->bToc = 1;
      for ( i = 0; i < 0x64; ++i )
        out_info->aToc[i] = *((_BYTE *)v45 + i);
    }
  }
  FileSize = GetFileSize(hFile, 0i64);
  if ( !out_info->uMPEGStreamSize )
    out_info->uMPEGStreamSize = FileSize - out_info->uFirstFrameOffset;
  if ( !out_info->msDuration )
  {
    if ( uVersion && (v50 = uVersion - 2) != 0 )
    {
      if ( v50 == 1 )
        v51 = `AkMP3FrameHeader::GetBitRate::`2::s_aBitRatesMPEG1[uBitRate];
      else
        v51 = 0;
    }
    else
    {
      v51 = `AkMP3FrameHeader::GetBitRate::`2::s_aBitRatesMPEG2[uBitRate];
    }
    out_info->msDuration = out_info->uMPEGStreamSize / (v51 >> 3);
  }
  if ( lpBaseAddress )
    UnmapViewOfFile(lpBaseAddress);
  CloseHandle(hObject);
  if ( out_pTag )
  {
    if ( !v10 )
    {
      NumberOfBytesRead = SetFilePointer(hFile, -128, 0i64, 2u);
      if ( ReadFile(hFile, Buffer, 0x80u, &NumberOfBytesRead, 0i64) )
      {
        if ( NumberOfBytesRead == 128 && Buffer[0] == 84 && Buffer[1] == 65 && Buffer[2] == 71 )
        {
          v52 = MultiByteToWideChar(0x4E4u, 0, MultiByteStr, 30, out_pTag->wszAlbum, 256);
          if ( v52 < 256 )
            out_pTag->wszAlbum[v52] = 0;
          v53 = MultiByteToWideChar(0x4E4u, 0, v62, 30, out_pTag->wszArtist, 256);
          if ( v53 < 256 )
            out_pTag->wszArtist[v53] = 0;
          v54 = MultiByteToWideChar(0x4E4u, 0, v61, 30, out_pTag->wszTrack, 256);
          if ( v54 < 256 )
            out_pTag->wszTrack[v54] = 0;
        }
      }
    }
  }
  CloseHandle(hFile);
  return 1;
}

