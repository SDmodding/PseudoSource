// File Line: 137
// RVA: 0xA355E0
char *__fastcall AkMP3SyncToFirstFrame(char *in_pFile, AkMP3FrameHeader *io_hdr)
{
  char *v2; // r9
  unsigned __int8 v3; // r8
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  int v8; // eax

  v2 = in_pFile + 4096;
  while ( in_pFile < v2 )
  {
    if ( *in_pFile == -1 )
    {
      v3 = in_pFile[1];
      if ( (v3 & 0xE0) == -32 )
      {
        v4 = ((unsigned int)v3 >> 3) & 3;
        io_hdr->uVersion = v4;
        if ( v4 != 1 )
        {
          v5 = ((unsigned int)(unsigned __int8)in_pFile[1] >> 1) & 3;
          io_hdr->uLayer = v5;
          if ( v5 == 1 )
          {
            io_hdr->uProtection = in_pFile[1] & 1;
            v6 = (unsigned int)(unsigned __int8)in_pFile[2] >> 4;
            io_hdr->uBitRate = v6;
            if ( v6 )
            {
              if ( v6 != 15 )
              {
                v7 = ((unsigned int)(unsigned __int8)in_pFile[2] >> 2) & 3;
                io_hdr->uSampleRate = v7;
                if ( v7 != 3 )
                {
                  io_hdr->uPadding = ((unsigned int)(unsigned __int8)in_pFile[2] >> 1) & 1;
                  io_hdr->uPrivate = in_pFile[2] & 1;
                  io_hdr->uChannelMode = (unsigned int)(unsigned __int8)in_pFile[3] >> 6;
                  io_hdr->uModeExtension = ((unsigned int)(unsigned __int8)in_pFile[3] >> 4) & 3;
                  io_hdr->uCopyright = ((unsigned int)(unsigned __int8)in_pFile[3] >> 3) & 1;
                  io_hdr->uOriginal = ((unsigned int)(unsigned __int8)in_pFile[3] >> 2) & 1;
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
  int v8; // er9
  int v9; // eax
  int v10; // eax
  const char *v11; // r8
  UINT v12; // ecx
  wchar_t *v13; // rdx
  wchar_t *v14; // r8
  wchar_t v15; // ax
  unsigned __int64 v16; // r9
  wchar_t *v17; // rdx
  unsigned __int64 i; // r8
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
        v16 = (unsigned __int64)&v5[2 * ((signed __int64)(v8 - 2) >> 1) + 2];
        if ( v15 )
        {
          do
          {
            if ( (unsigned __int64)v13 >= v16 )
              break;
            if ( lpWideCharStr >= v14 )
              goto LABEL_13;
            ++v13;
            *lpWideCharStr = v15;
            ++lpWideCharStr;
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
    for ( i = (unsigned __int64)&v5[2 * ((signed __int64)v8 >> 1)]; *(_WORD *)v5; *(lpWideCharStr - 1) = __ROR2__(v19, 8) )
    {
      if ( (unsigned __int64)v5 >= i )
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
  if ( v20 < (signed int)cchWideChar )
    lpWideCharStr[v20] = 0;
}

// File Line: 244
// RVA: 0xA34B10
char __fastcall AkMP3InfoRead(const char *in_tszFilename, AkMP3BaseInfo *out_info, AkMP3Tag *out_pTag)
{
  AkMP3Tag *v3; // r12
  AkMP3BaseInfo *v4; // r13
  HANDLE v5; // rax
  HANDLE v6; // rbx
  HANDLE v7; // rax
  void *v8; // rdi
  LPVOID v9; // rax
  char v10; // si
  char *v11; // r8
  char *v12; // rbx
  bool v13; // al
  int v14; // eax
  int v15; // er15
  _BYTE *v16; // rbx
  _BYTE *v17; // r13
  unsigned int v18; // edi
  char v19; // cl
  char v20; // al
  char v21; // al
  wchar_t *v22; // r8
  char v23; // al
  char v24; // al
  unsigned int v25; // ecx
  char *v26; // rbx
  char *v27; // r13
  unsigned int v28; // edi
  char v29; // cl
  char v30; // al
  char v31; // al
  wchar_t *v32; // r8
  char v33; // al
  char v34; // al
  char *v35; // r9
  char v36; // r10
  unsigned int v37; // edi
  unsigned int v38; // ecx
  __int16 v39; // ax
  unsigned int v40; // edx
  int v41; // eax
  unsigned int v42; // er15
  _BYTE *v43; // r9
  char v44; // al
  unsigned int *v45; // r9
  char v46; // r10
  unsigned int *v47; // r9
  unsigned __int32 v48; // er11
  signed __int64 v49; // kr00_8
  unsigned int v50; // eax
  unsigned int i; // edx
  DWORD v52; // eax
  int v53; // edi
  unsigned int v54; // ecx
  int v55; // eax
  int v56; // eax
  int v57; // eax
  char *v59; // [rsp+48h] [rbp-120h]
  HANDLE hObject; // [rsp+60h] [rbp-108h]
  LPCVOID lpBaseAddress; // [rsp+68h] [rbp-100h]
  AkMP3FrameHeader io_hdr; // [rsp+78h] [rbp-F0h]
  char Buffer; // [rsp+B0h] [rbp-B8h]
  char v64; // [rsp+B1h] [rbp-B7h]
  char v65; // [rsp+B2h] [rbp-B6h]
  char v66; // [rsp+B3h] [rbp-B5h]
  char v67; // [rsp+D1h] [rbp-97h]
  char MultiByteStr; // [rsp+EFh] [rbp-79h]
  AkMP3BaseInfo *v69; // [rsp+178h] [rbp+10h]
  unsigned int NumberOfBytesRead; // [rsp+180h] [rbp+18h]
  HANDLE hFile; // [rsp+188h] [rbp+20h]

  v69 = out_info;
  v3 = out_pTag;
  v4 = out_info;
  if ( out_pTag )
  {
    out_pTag->wszAlbum[0] = 0;
    out_pTag->wszArtist[0] = 0;
    out_pTag->wszTrack[0] = 0;
  }
  v5 = CreateFileA(in_tszFilename, 0x80000000, 1u, 0i64, 3u, 0x10000080u, 0i64);
  v6 = v5;
  hFile = v5;
  if ( !v5 )
    return 0;
  v7 = CreateFileMappingA(v5, 0i64, 2u, 0, 0, 0i64);
  v8 = v7;
  hObject = v7;
  if ( !v7 )
  {
LABEL_152:
    CloseHandle(v6);
    return 0;
  }
  v9 = MapViewOfFile(v7, 4u, 0, 0, 0i64);
  lpBaseAddress = v9;
  if ( !v9 )
    goto $error_result;
  v10 = 0;
  v11 = (char *)v9;
  v59 = (char *)v9;
  v12 = (char *)v9;
LABEL_7:
  v13 = *v12 == 73 && v12[1] == 68 && v12[2] == 51;
  if ( v13 )
  {
    v14 = (unsigned __int8)v12[3];
    if ( v14 == 2 )
    {
      v15 = (unsigned __int8)v12[9] | (((unsigned __int8)v12[8] | ((((unsigned __int8)v12[6] << 7) | (unsigned __int8)v12[7]) << 7)) << 7);
      if ( !v3 )
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
          v22 = v3->wszTrack;
          goto LABEL_41;
        }
        if ( v19 != 84 || v16[1] != 65 || (v23 = 1, v16[2] != 76) )
          v23 = 0;
        if ( v23 )
        {
          v22 = (wchar_t *)v3;
          goto LABEL_41;
        }
        if ( v19 != 84 || v16[1] != 80 || (v24 = 1, v16[2] != 49) )
          v24 = 0;
        if ( v24 )
        {
          v22 = v3->wszArtist;
LABEL_41:
          ReadTextField(v16 + 6, v18, v22, 256);
          v10 = 1;
        }
        v16 += v18 + 6;
        continue;
      }
    }
    if ( (unsigned int)(v14 - 3) > 1 )
      goto LABEL_80;
    v25 = ((unsigned int)(unsigned __int8)v12[5] >> 6) & 1;
    v15 = (unsigned __int8)v12[9] | (((unsigned __int8)v12[8] | ((((unsigned __int8)v12[6] << 7) | (unsigned __int8)v12[7]) << 7)) << 7);
    if ( !v3 )
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
        v11 = v59;
LABEL_79:
        v11 += (unsigned int)(v15 + 10);
        v59 = v11;
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
        v32 = (wchar_t *)v3;
        goto LABEL_76;
      }
      if ( v29 != 84 || v26[1] != 80 || v26[2] != 69 || (v34 = 1, v26[3] != 49) )
        v34 = 0;
      if ( v34 )
      {
        v32 = v3->wszArtist;
        goto LABEL_76;
      }
LABEL_77:
      v26 += v28 + 10;
    }
    v32 = v3->wszTrack;
LABEL_76:
    ReadTextField(v26 + 10, v28, v32, 256);
    v10 = 1;
    goto LABEL_77;
  }
  v35 = AkMP3SyncToFirstFrame(v11, &io_hdr);
  if ( !v35 )
  {
    v4 = v69;
    v6 = hFile;
    v8 = hObject;
$error_result:
    memset(v4, 0, 0x7Cui64);
    if ( lpBaseAddress )
      UnmapViewOfFile(lpBaseAddress);
    CloseHandle(v8);
    goto LABEL_152;
  }
  v37 = io_hdr.uVersion;
  if ( io_hdr.uVersion )
  {
    if ( io_hdr.uVersion == 2 )
    {
      v38 = `AkMP3FrameHeader::GetSampleRate'::`2'::s_aSampleRatesMPEG2[io_hdr.uSampleRate];
    }
    else if ( io_hdr.uVersion == 3 )
    {
      v38 = `AkMP3FrameHeader::GetSampleRate'::`2'::s_aSampleRatesMPEG1[io_hdr.uSampleRate];
    }
    else
    {
      v38 = 0;
    }
  }
  else
  {
    v38 = `AkMP3FrameHeader::GetSampleRate'::`2'::s_aSampleRatesMPEG2_5[io_hdr.uSampleRate];
  }
  NumberOfBytesRead = v38;
  v69->uSampleRate = v38;
  HIBYTE(v39) = 0;
  v40 = io_hdr.uChannelMode;
  LOBYTE(v39) = io_hdr.uChannelMode != 3;
  v69->uNumChannels = v39 + 1;
  v69->msDuration = 0;
  if ( v37 && v37 != 2 )
  {
    if ( v37 == 3 )
    {
      v42 = io_hdr.uBitRate;
      v41 = `AkMP3FrameHeader::GetBitRate'::`2'::s_aBitRatesMPEG1[io_hdr.uBitRate];
    }
    else
    {
      v41 = 0;
      v42 = io_hdr.uBitRate;
    }
  }
  else
  {
    v42 = io_hdr.uBitRate;
    v41 = `AkMP3FrameHeader::GetBitRate'::`2'::s_aBitRatesMPEG2[io_hdr.uBitRate];
  }
  v69->uBitRate = v41;
  v69->uFirstFrameOffset = (_DWORD)v35 - (_DWORD)lpBaseAddress;
  v69->uMPEGStreamSize = 0;
  v69->bToc = 0;
  if ( v37 & 1 )
  {
    if ( v40 != 3 )
    {
      v43 = v35 + 36;
      goto LABEL_102;
    }
  }
  else if ( v40 == 3 )
  {
    v43 = v35 + 13;
    goto LABEL_102;
  }
  v43 = v35 + 21;
LABEL_102:
  v44 = 0;
  if ( *v43 == 88 && v43[1] == 105 && v43[2] == 110 )
  {
    v44 = 0;
    if ( v43[3] == 103 )
      v44 = v36;
  }
  if ( *v43 == 73 && v43[1] == 110 && v43[2] == 102 && v43[3] == 111 || v44 )
  {
    v45 = (unsigned int *)(v43 + 4);
    v46 = _byteswap_ulong(*v45);
    v47 = v45 + 1;
    if ( v46 & 1 )
    {
      v48 = _byteswap_ulong(*v47);
      v49 = 1374389535i64 * (unsigned __int16)v38;
      if ( v37 & 1 )
        v50 = 23040 * v48 / ((HIDWORD(v49) >> 31) + (SHIDWORD(v49) >> 4));
      else
        v50 = 11520 * v48 / ((HIDWORD(v49) >> 31) + (SHIDWORD(v49) >> 4));
      v69->msDuration = v50;
      ++v47;
    }
    if ( v46 & 2 )
    {
      v69->uMPEGStreamSize = _byteswap_ulong(*v47);
      ++v47;
    }
    if ( v46 & 4 )
    {
      v69->bToc = 1;
      for ( i = 0; i < 0x64; ++i )
        v69->aToc[i] = *((_BYTE *)v47 + i);
    }
  }
  v52 = GetFileSize(hFile, 0i64);
  if ( !v69->uMPEGStreamSize )
    v69->uMPEGStreamSize = v52 - v69->uFirstFrameOffset;
  if ( !v69->msDuration )
  {
    if ( v37 && (v53 = v37 - 2) != 0 )
    {
      if ( v53 == 1 )
        v54 = `AkMP3FrameHeader::GetBitRate'::`2'::s_aBitRatesMPEG1[v42];
      else
        v54 = 0;
    }
    else
    {
      v54 = `AkMP3FrameHeader::GetBitRate'::`2'::s_aBitRatesMPEG2[v42];
    }
    v69->msDuration = v69->uMPEGStreamSize / (v54 >> 3);
  }
  if ( lpBaseAddress )
    UnmapViewOfFile(lpBaseAddress);
  CloseHandle(hObject);
  if ( v3 )
  {
    if ( !v10 )
    {
      NumberOfBytesRead = SetFilePointer(hFile, -128, 0i64, 2u);
      if ( ReadFile(hFile, &Buffer, 0x80u, &NumberOfBytesRead, 0i64) )
      {
        if ( NumberOfBytesRead == 128 && Buffer == 84 && v64 == 65 && v65 == 71 )
        {
          v55 = MultiByteToWideChar(0x4E4u, 0, &MultiByteStr, 30, v3->wszAlbum, 256);
          if ( v55 < 256 )
            v3->wszAlbum[v55] = 0;
          v56 = MultiByteToWideChar(0x4E4u, 0, &v67, 30, v3->wszArtist, 256);
          if ( v56 < 256 )
            v3->wszArtist[v56] = 0;
          v57 = MultiByteToWideChar(0x4E4u, 0, &v66, 30, v3->wszTrack, 256);
          if ( v57 < 256 )
            v3->wszTrack[v57] = 0;
        }
      }
    }
  }
  CloseHandle(hFile);
  return 1;
}

