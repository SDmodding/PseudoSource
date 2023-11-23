// File Line: 289
// RVA: 0x16CF20
void __fastcall UFG::qEncoderContextLZ::Encode(
        UFG::qEncoderContextLZ *this,
        UFG::qContextLZ::EncodeType type,
        const char *ip,
        int len,
        unsigned __int16 dis)
{
  char *v5; // r10
  _BYTE *v6; // rdx
  int v7; // r11d
  int v8; // ebx
  int v9; // edx
  __int64 v10; // rax
  int v11; // r9d
  int v12; // eax
  __int64 mCompressedLength; // rax
  int v14; // r8d
  int v15; // r8d

  v5 = &this->mOutput[this->mOutputPosition];
  if ( type )
  {
    v7 = dis | (len << 16);
    v8 = 0;
    v9 = 0;
    v10 = 0i64;
    while ( v7 != this->mCache.mCache[v10] )
    {
      ++v10;
      ++v9;
      if ( v10 >= 32 )
      {
        v9 = -1;
        break;
      }
    }
    v11 = len - 1;
    if ( v9 < 0 )
    {
      if ( v11 < 7 )
      {
        v6 = v5 + 2;
        *v5 = (32 * v11) | HIBYTE(dis);
        v5[1] = dis;
      }
      else
      {
        v6 = v5 + 3;
        *v5 = HIBYTE(dis) | 0xE0;
        v5[1] = dis;
        v5[2] = v11;
      }
      this->mCache.mCache[this->mCache.mCurrent] = v7;
      v12 = this->mCache.mCurrent + 1;
      LOBYTE(v8) = v12 != 32;
      this->mCache.mCurrent = v12 & ~(v8 - 1);
    }
    else
    {
      *v5 = v9 | 0x20;
      v6 = v5 + 1;
    }
  }
  else
  {
    v6 = v5 + 1;
    for ( *v5 = len - 1; len > 0; ++ip )
    {
      --len;
      *v6++ = *ip;
    }
  }
  mCompressedLength = this->mCompressedLength;
  v14 = (_DWORD)ip - LODWORD(this->mInput) - LODWORD(this->mCompressedLength);
  this->mInPlacePosition = mCompressedLength;
  v15 = v14 + 1;
  if ( v15 > this->mInPlacePadding )
    this->mInPlacePadding = v15;
  this->mOutputPosition += v6 - v5;
  this->mCompressedLength = (__int64)&v6[mCompressedLength - (_QWORD)v5];
}

// File Line: 378
// RVA: 0x16DBC0
char __fastcall UFG::qEncoderContextLZ::FinalFlush(UFG::qEncoderContextLZ *this)
{
  bool (__fastcall *mFlushCallback)(void *, __int64, void *, __int64); // rax
  __int64 mOutputPosition; // r9
  char result; // al
  __int64 mCompressedLength; // rax
  __int64 mInputLength; // rcx
  __int64 v7; // rax
  bool (__fastcall *v8)(void *, __int64, void *, __int64); // rax

  mFlushCallback = this->mFlushCallback;
  if ( !mFlushCallback
    || (mOutputPosition = this->mOutputPosition, mOutputPosition <= 0)
    || (result = ((__int64 (__fastcall *)(void *, __int64, char *))mFlushCallback)(
                   this->mCallbackParam,
                   this->mCompressedLength - mOutputPosition,
                   this->mOutput)) != 0 )
  {
    mCompressedLength = this->mCompressedLength;
    mInputLength = this->mInputLength;
    this->mHeader.mCompressedNumBytes = mCompressedLength;
    if ( mCompressedLength > mInputLength )
      this->mHeader.mInPlaceExtraNumBytes += mCompressedLength - mInputLength;
    v7 = this->mInPlacePosition + this->mInPlacePadding;
    if ( v7 > mInputLength )
      this->mHeader.mInPlaceExtraNumBytes += v7 - mInputLength;
    UFG::qCompressHeader::EndianSwap(&this->mHeader);
    this->mHeader.mInPlaceExtraNumBytes += -(this->mHeader.mInPlaceExtraNumBytes
                                           + LODWORD(this->mHeader.mUncompressedNumBytes)
                                           - LODWORD(this->mHeader.mCompressedNumBytes)) & 7;
    v8 = this->mFlushCallback;
    if ( !v8 )
    {
      UFG::qMemCopy(this->mOutput, &this->mHeader, 0x40u);
      return 1;
    }
    result = v8(this->mCallbackParam, 0i64, &this->mHeader, 64i64);
    if ( result )
      return 1;
  }
  return result;
}

// File Line: 430
// RVA: 0x169B20
bool __fastcall UFG::qEncoderContextLZ::Compress(UFG::qEncoderContextLZ *this)
{
  __int64 mInputLength; // rsi
  char *mInput; // rbx
  UFG::qEncoderContextLZ *v3; // rbp
  char *v4; // r15
  unsigned __int64 v5; // r12
  UFG::qCompressHeader *p_mHeader; // rdi
  char *v8; // rdi
  unsigned __int64 v9; // rdx
  unsigned __int64 v10; // r9
  unsigned int i; // r8d
  char v12; // al
  __int64 mOutputPosition; // rcx
  char *v14; // rdx
  char *n; // rcx
  __int64 v16; // rax
  int v17; // ebx
  int v18; // ebx
  int v19; // r14d
  char *v20; // rsi
  unsigned __int8 *v21; // rbx
  bool (__fastcall *mFlushCallback)(void *, __int64, void *, __int64); // rdi
  __int64 v23; // r9
  unsigned __int8 v24; // dl
  unsigned __int8 v25; // r8
  unsigned __int8 *v26; // rcx
  const char *v27; // r8
  int v28; // eax
  char *v29; // rdx
  _BYTE *v30; // rcx
  __int64 mCompressedLength; // rax
  int v32; // esi
  int v33; // esi
  unsigned __int8 v34; // dl
  unsigned __int64 v35; // r10
  int v36; // r15d
  int dis; // r12d
  __int64 v38; // r13
  unsigned int v39; // ecx
  int v40; // ecx
  _BYTE **v41; // r11
  _BYTE *v42; // rdi
  unsigned int v43; // r9d
  int v44; // eax
  _BYTE *v45; // rdx
  char v46; // cl
  int v47; // edx
  int v48; // r9d
  int v49; // eax
  int v50; // edi
  __int64 v51; // rdx
  char *v52; // rcx
  __int64 v53; // rax
  char *v54; // rdx
  _BYTE *v55; // rcx
  __int64 v56; // rax
  int v57; // esi
  int v58; // esi
  __int64 v59; // rdi
  unsigned int v60; // ecx
  unsigned __int64 v61; // rdx
  unsigned int v62; // eax
  unsigned int v63; // ecx
  unsigned int v64; // r8d
  char *v65; // rcx
  __int64 v66; // rax
  unsigned __int64 v67; // rdi
  __int64 v68; // rdx
  char *v69; // rcx
  __int64 v70; // rax
  int v71; // edx
  char *v72; // rdi
  _BYTE *v73; // rcx
  __int64 v74; // rax
  int v75; // esi
  int v76; // esi
  int v77; // r15d
  int v78; // edx
  char *v79; // rdi
  char *m; // rcx
  __int64 v81; // rax
  int v82; // esi
  int v83; // esi
  unsigned __int8 *v84; // rax
  signed __int64 v85; // rcx
  char *v86; // rdx
  char *j; // rcx
  __int64 v88; // rax
  int v89; // esi
  int v90; // esi
  char *v91; // rax
  __int64 v92; // rdx
  char *v93; // rdx
  unsigned __int8 *k; // rcx
  __int64 v95; // rax
  int v96; // ebx
  int v97; // ebx
  unsigned __int8 *v98; // [rsp+38h] [rbp-60h]
  unsigned __int64 v99; // [rsp+40h] [rbp-58h]
  int v100; // [rsp+48h] [rbp-50h]
  unsigned __int64 v102; // [rsp+B0h] [rbp+18h]
  char *v103; // [rsp+B8h] [rbp+20h]

  mInputLength = this->mInputLength;
  mInput = this->mInput;
  v3 = this;
  v4 = &mInput[mInputLength];
  v100 = (_DWORD)mInput + mInputLength;
  v5 = (unsigned __int64)&mInput[mInputLength - 2];
  v102 = v5;
  v99 = (unsigned __int64)&mInput[mInputLength - 16];
  if ( !mInputLength )
    return 0;
  p_mHeader = &this->mHeader;
  UFG::qMemSet(&this->mHeader, 0, 0x40u);
  p_mHeader->mID = 1363365200;
  *(_DWORD *)&p_mHeader->mType = 65537;
  p_mHeader->mDataOffset = 64;
  p_mHeader->mCompressedNumBytes = 0i64;
  p_mHeader->mUncompressedNumBytes = mInputLength;
  v8 = v3->mInput;
  v9 = -1i64;
  if ( v8 )
  {
    v10 = v3->mInputLength;
    for ( i = 0; i < v10; v9 = (v9 >> 8) ^ sCrcTable64[(unsigned __int8)(v9 ^ v12)] )
    {
      v12 = *v8;
      ++i;
      ++v8;
    }
  }
  v3->mOutputPosition += 64i64;
  v3->mCompressedLength += 64i64;
  mOutputPosition = v3->mOutputPosition;
  v3->mHeader.mUncompressedChecksum = v9;
  if ( mInputLength >= 4 )
  {
    memset64(v3->htab2, (unsigned __int64)mInput, 0x20000ui64);
    UFG::qMemSet(v3->hpos2, 0, 0x1000u);
    v19 = 2;
    v20 = mInput;
    v21 = (unsigned __int8 *)(mInput + 2);
    if ( v21 < (unsigned __int8 *)v4 - 16 )
    {
      while ( 1 )
      {
        mFlushCallback = v3->mFlushCallback;
        if ( mFlushCallback )
        {
          v23 = v3->mOutputPosition;
          if ( v23 )
          {
            if ( v23 + 36 >= v3->mOutputLength )
            {
              if ( !((unsigned __int8 (__fastcall *)(void *, __int64, char *))mFlushCallback)(
                      v3->mCallbackParam,
                      v3->mCompressedLength - v23,
                      v3->mOutput) )
                return 0;
              v3->mOutputPosition = 0i64;
            }
          }
        }
        v24 = *(v21 - 1);
        v25 = *v21;
        if ( v24 == *v21 && v24 == v21[1] && v24 == v21[2] )
        {
          v26 = (unsigned __int8 *)v5;
          v27 = (const char *)v21;
          if ( (unsigned __int64)(v21 + 252) < v5 )
            v26 = v21 + 252;
          if ( *v21 == v24 )
          {
            do
            {
              if ( v21 >= v26 )
                break;
              v28 = *++v21;
            }
            while ( v28 == v24 );
          }
          if ( v19 > 0 )
          {
            v29 = &v3->mOutput[v3->mOutputPosition];
            *v29 = v19 - 1;
            v30 = v29 + 1;
            do
            {
              --v19;
              *v30++ = *v20++;
            }
            while ( v19 > 0 );
            mCompressedLength = v3->mCompressedLength;
            v32 = (_DWORD)v20 - LODWORD(v3->mCompressedLength) - LODWORD(v3->mInput);
            v3->mInPlacePosition = mCompressedLength;
            v33 = v32 + 1;
            if ( v33 > v3->mInPlacePadding )
              v3->mInPlacePadding = v33;
            v3->mOutputPosition += v30 - v29;
            v3->mCompressedLength = (__int64)&v30[mCompressedLength - (_QWORD)v29];
          }
          UFG::qEncoderContextLZ::Encode(v3, TYPE_MATCH, v27, (_DWORD)v21 - (_DWORD)v27, 1);
          v20 = (char *)v21;
          v19 = 0;
        }
        else
        {
          v34 = v21[2];
          v35 = v5;
          if ( (unsigned __int64)(v21 + 252) < v5 )
            v35 = (unsigned __int64)(v21 + 252);
          v98 = v21 + 1;
          v36 = 0;
          dis = 0;
          v38 = 32i64;
          v39 = -63 * (v25 | ((v21[1] | (v21[2] << 8)) << 8));
          v40 = -7 * ((-8176 * ((v39 >> 17) ^ v39)) ^ (-511 * ((v39 >> 17) ^ v39)));
          v103 = (char *)v3
               + 256
               * (unsigned __int64)(((unsigned __int16)(((_WORD)v40 << 10) ^ v40) ^ (unsigned __int16)(((v40 << 10) ^ (unsigned int)v40) >> 15)) & 0xFFF);
          v41 = (_BYTE **)(v103 + 240);
          do
          {
            v42 = *v41;
            v43 = (_DWORD)v21 - (unsigned int)*v41;
            if ( v43 - 1 <= 0x1FFD )
            {
              if ( *v42 == v25 )
              {
                if ( v42[1] == v21[1] )
                {
                  if ( v42[2] == v34 )
                  {
                    if ( v42[3] == v21[3] )
                    {
                      v45 = v42 + 4;
                      v44 = 4;
                      if ( v42[4] == v21[4] )
                      {
                        do
                        {
                          if ( (unsigned __int64)&v21[v44] >= v35 )
                            break;
                          v46 = (v45++)[v21 - v42 + 1];
                          ++v44;
                        }
                        while ( *v45 == v46 );
                        v25 = *v21;
                      }
                    }
                    else
                    {
                      v44 = 3;
                    }
                  }
                  else
                  {
                    v44 = 2;
                  }
                }
                else
                {
                  v44 = 1;
                }
              }
              else
              {
                v44 = 0;
              }
              v47 = (v44 <= v36) - 1;
              v48 = v47 & v43;
              v49 = v47 & v44;
              v50 = v47;
              v34 = v21[2];
              dis = dis & ~v50 | v48;
              v36 = v36 & ~v50 | v49;
            }
            ++v41;
            --v38;
          }
          while ( v38 );
          v3 = this;
          v51 = 31i64;
          v52 = v103 + 488;
          do
          {
            v53 = *((_QWORD *)v52 - 1);
            --v51;
            v52 -= 8;
            *((_QWORD *)v52 + 1) = v53;
          }
          while ( v51 > 0 );
          *((_QWORD *)v103 + 30) = v21;
          if ( v36 < 3 )
          {
            ++v21;
            if ( ++v19 == 32 )
            {
              v71 = 32;
              v72 = &this->mOutput[this->mOutputPosition];
              *v72 = 31;
              v73 = v72 + 1;
              do
              {
                --v71;
                *v73++ = *v20++;
              }
              while ( v71 > 0 );
              v74 = this->mCompressedLength;
              v75 = (_DWORD)v20 - LODWORD(this->mCompressedLength) - LODWORD(this->mInput);
              this->mInPlacePosition = v74;
              v76 = v75 + 1;
              if ( v76 > this->mInPlacePadding )
                this->mInPlacePadding = v76;
              v20 = (char *)v98;
              this->mOutputPosition += v73 - v72;
              v19 = 0;
              this->mCompressedLength = (__int64)&v73[v74 - (_QWORD)v72];
            }
          }
          else
          {
            if ( v19 > 0 )
            {
              v54 = &this->mOutput[this->mOutputPosition];
              *v54 = v19 - 1;
              v55 = v54 + 1;
              do
              {
                --v19;
                *v55++ = *v20++;
              }
              while ( v19 > 0 );
              v56 = this->mCompressedLength;
              v57 = (_DWORD)v20 - LODWORD(this->mCompressedLength) - LODWORD(this->mInput);
              this->mInPlacePosition = v56;
              v58 = v57 + 1;
              if ( v58 > this->mInPlacePadding )
                this->mInPlacePadding = v58;
              this->mOutputPosition += v55 - v54;
              this->mCompressedLength = (__int64)&v55[v56 - (_QWORD)v54];
            }
            UFG::qEncoderContextLZ::Encode(this, TYPE_MATCH, (const char *)v21, v36, dis);
            v59 = 31i64;
            v21 += v36;
            v60 = (-7168
                 * ((-8176
                   * (((unsigned int)(-63 * (*(v21 - 2) | (*(unsigned __int16 *)(v21 - 1) << 8))) >> 17) ^ (-63 * (*(v21 - 2) | (*(unsigned __int16 *)(v21 - 1) << 8))))) ^ (-511 * (((unsigned int)(-63 * (*(v21 - 2) | (*(unsigned __int16 *)(v21 - 1) << 8))) >> 17) ^ (-63 * (*(v21 - 2) | (*(unsigned __int16 *)(v21 - 1) << 8))))))) ^ (-7 * ((-8176 * (((unsigned int)(-63 * (*(v21 - 2) | (*(unsigned __int16 *)(v21 - 1) << 8))) >> 17) ^ (-63 * (*(v21 - 2) | (*(unsigned __int16 *)(v21 - 1) << 8))))) ^ (-511 * (((unsigned int)(-63 * (*(v21 - 2) | (*(unsigned __int16 *)(v21 - 1) << 8))) >> 17) ^ (-63 * (*(v21 - 2) | (*(unsigned __int16 *)(v21 - 1) << 8)))))));
            v61 = (unsigned __int64)(((unsigned __int16)v60 ^ (unsigned __int16)(v60 >> 15)) & 0xFFF) << 8;
            v62 = -7168
                * ((-8176
                  * (((unsigned int)(-63 * (*(v21 - 1) | ((*v21 | (v21[1] << 8)) << 8))) >> 17) ^ (-63
                                                                                                 * (*(v21 - 1) | ((*v21 | (v21[1] << 8)) << 8))))) ^ (-511 * (((unsigned int)(-63 * (*(v21 - 1) | ((*v21 | (v21[1] << 8)) << 8))) >> 17) ^ (-63 * (*(v21 - 1) | ((*v21 | (v21[1] << 8)) << 8))))));
            v63 = v62 ^ (-7
                       * ((-8176
                         * (((unsigned int)(-63 * (*(v21 - 1) | ((*v21 | (v21[1] << 8)) << 8))) >> 17) ^ (-63 * (*(v21 - 1) | ((*v21 | (v21[1] << 8)) << 8))))) ^ (-511 * (((unsigned int)(-63 * (*(v21 - 1) | ((*v21 | (v21[1] << 8)) << 8))) >> 17) ^ (-63 * (*(v21 - 1) | ((*v21 | (v21[1] << 8)) << 8)))))));
            v64 = ((unsigned __int16)v63 ^ (unsigned __int16)(v63 >> 15)) & 0xFFF;
            v65 = (char *)&this->htab2[0][31] + v61;
            do
            {
              v66 = *((_QWORD *)v65 - 1);
              --v59;
              v65 -= 8;
              *((_QWORD *)v65 + 1) = v66;
            }
            while ( v59 > 0 );
            *(const char **)((char *)this->htab2[0] + v61) = (const char *)(v21 - 2);
            v67 = (unsigned __int64)v64 << 8;
            v68 = 31i64;
            v69 = (char *)&this->htab2[0][31] + v67;
            do
            {
              v70 = *((_QWORD *)v69 - 1);
              --v68;
              v69 -= 8;
              *((_QWORD *)v69 + 1) = v70;
            }
            while ( v68 > 0 );
            *(const char **)((char *)this->htab2[0] + v67) = (const char *)(v21 - 1);
            v20 = (char *)v21;
            v19 = 0;
          }
          v5 = v102;
        }
        if ( (unsigned __int64)v21 >= v99 )
        {
          LODWORD(v4) = v100;
          break;
        }
      }
    }
    v77 = (_DWORD)v4 - (_DWORD)v21;
    v78 = v77 + v19;
    if ( v77 + v19 > 32 )
    {
      v86 = &v3->mOutput[v3->mOutputPosition];
      *v86 = v19 - 1;
      for ( j = v86 + 1; v19 > 0; ++v20 )
      {
        --v19;
        *j++ = *v20;
      }
      v88 = v3->mCompressedLength;
      v89 = (_DWORD)v20 - LODWORD(v3->mCompressedLength) - LODWORD(v3->mInput);
      v3->mInPlacePosition = v88;
      v90 = v89 + 1;
      if ( v90 > v3->mInPlacePadding )
        v3->mInPlacePadding = v90;
      v91 = &j[v88 - (_QWORD)v86];
      v3->mOutputPosition += j - v86;
      v92 = v3->mOutputPosition;
      v3->mCompressedLength = (__int64)v91;
      v93 = &v3->mOutput[v92];
      *v93 = v77 - 1;
      for ( k = (unsigned __int8 *)(v93 + 1); v77 > 0; ++v21 )
      {
        --v77;
        *k++ = *v21;
      }
      v95 = v3->mCompressedLength;
      v96 = (_DWORD)v21 - LODWORD(v3->mCompressedLength) - LODWORD(v3->mInput);
      v3->mInPlacePosition = v95;
      v97 = v96 + 1;
      if ( v97 > v3->mInPlacePadding )
        v3->mInPlacePadding = v97;
      v84 = &k[v95 - (_QWORD)v93];
      v85 = k - (unsigned __int8 *)v93;
    }
    else
    {
      v79 = &v3->mOutput[v3->mOutputPosition];
      *v79 = v78 - 1;
      for ( m = v79 + 1; v78 > 0; ++v20 )
      {
        --v78;
        *m++ = *v20;
      }
      v81 = v3->mCompressedLength;
      v82 = (_DWORD)v20 - LODWORD(v3->mCompressedLength) - LODWORD(v3->mInput);
      v3->mInPlacePosition = v81;
      v83 = v82 + 1;
      if ( v83 > v3->mInPlacePadding )
        v3->mInPlacePadding = v83;
      v84 = (unsigned __int8 *)&m[v81 - (_QWORD)v79];
      v85 = m - v79;
    }
    v3->mOutputPosition += v85;
    v3->mCompressedLength = (__int64)v84;
    return UFG::qEncoderContextLZ::FinalFlush(v3);
  }
  else
  {
    v14 = &v3->mOutput[mOutputPosition];
    *v14 = mInputLength - 1;
    for ( n = v14 + 1; (int)mInputLength > 0; ++mInput )
    {
      LODWORD(mInputLength) = mInputLength - 1;
      *n++ = *mInput;
    }
    v16 = v3->mCompressedLength;
    v17 = (_DWORD)mInput - LODWORD(v3->mCompressedLength) - LODWORD(v3->mInput);
    v3->mInPlacePosition = v16;
    v18 = v17 + 1;
    if ( v18 > v3->mInPlacePadding )
      v3->mInPlacePadding = v18;
    v3->mOutputPosition += n - v14;
    v3->mCompressedLength = (__int64)&n[v16 - (_QWORD)v14];
    return UFG::qEncoderContextLZ::FinalFlush(v3);
  }
}

// File Line: 625
// RVA: 0x182730
UFG::qCompressBufferedLZ

// File Line: 663
// RVA: 0x183080
__int64 __fastcall UFG::qDecompressLZ(
        UFG::qCompressHeader *input,
        __int64 input_length,
        unsigned __int8 *output,
        __int64 output_length)
{
  int v6; // eax
  int *v8; // rdi
  __int64 v9; // rcx
  int v10; // ebp
  unsigned __int8 *v11; // rdi
  unsigned __int8 *v12; // rbx
  unsigned __int8 *v13; // r9
  unsigned __int8 v14; // al
  int j; // ecx
  unsigned __int8 v16; // r8
  int v17; // edx
  unsigned int v18; // ecx
  int v19; // r8d
  int v20; // edx
  int v21; // eax
  unsigned __int8 *i; // rcx
  int v23[32]; // [rsp+60h] [rbp-98h] BYREF
  int v24; // [rsp+E0h] [rbp-18h]

  v6 = _mm_cvtsi128_si32(*(__m128i *)&input->mID);
  if ( v6 != PMCQ && v6 != QCMP )
    return -1i64;
  UFG::qCompressHeader::EndianSwap(input);
  v8 = v23;
  v9 = 32i64;
  v10 = 0;
  while ( v9 )
  {
    *v8++ = 0;
    --v9;
  }
  v24 = 0;
  v11 = output;
  UFG::qCompressHeader::EndianSwap(input);
  v12 = (unsigned __int8 *)input + input->mDataOffset;
  UFG::qCompressHeader::EndianSwap(input);
  v13 = &v12[input->mCompressedNumBytes - input->mDataOffset];
  while ( v12 < v13 )
  {
    v14 = *v12++;
    if ( v14 >= 0x20u )
    {
      v16 = v14;
      v17 = v14 >> 5;
      if ( v17 == 1 )
      {
        v18 = v23[v14 & 0x1F];
        v19 = (unsigned __int16)v18;
        v20 = HIWORD(v18);
      }
      else
      {
        v21 = *v12++;
        v19 = v21 | ((v16 & 0x1F) << 8);
        if ( v17 == 7 )
          v17 = *v12++;
        v20 = v17 + 1;
        v23[v10] = (unsigned __int16)v19 | (v20 << 16);
        v10 = (v24 + 1) & ~((v24 != 31) - 1);
        v24 = v10;
      }
      for ( i = &v11[-v19]; v20 > 0; ++i )
      {
        --v20;
        *v11++ = *i;
      }
    }
    else
    {
      for ( j = v14 + 1; j > 0; ++v12 )
      {
        --j;
        *v11++ = *v12;
      }
    }
  }
  return v11 - output;
}

