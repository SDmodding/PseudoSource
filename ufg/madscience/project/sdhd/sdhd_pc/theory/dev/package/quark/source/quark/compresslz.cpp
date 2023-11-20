// File Line: 289
// RVA: 0x16CF20
void __fastcall UFG::qEncoderContextLZ::Encode(UFG::qEncoderContextLZ *this, UFG::qContextLZ::EncodeType type, const char *ip, int len, int dis)
{
  char *v5; // r10
  signed __int64 v6; // rdx
  int v7; // er11
  int v8; // ebx
  signed int v9; // edx
  signed __int64 v10; // rax
  int v11; // er9
  int v12; // eax
  int v13; // eax
  __int64 v14; // rax
  int v15; // er8
  int v16; // er8

  v5 = &this->mOutput[this->mOutputPosition];
  if ( type )
  {
    v7 = (unsigned __int16)dis | (len << 16);
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
      v12 = dis >> 8;
      if ( v11 < 7 )
      {
        v6 = (signed __int64)(v5 + 2);
        *v5 = 32 * v11 | v12;
        v5[1] = dis;
      }
      else
      {
        v6 = (signed __int64)(v5 + 3);
        *v5 = v12 | 0xE0;
        *(_BYTE *)(v6 - 2) = dis;
        *(_BYTE *)(v6 - 1) = v11;
      }
      this->mCache.mCache[this->mCache.mCurrent] = v7;
      v13 = this->mCache.mCurrent + 1;
      LOBYTE(v8) = v13 != 32;
      this->mCache.mCurrent = v13 & ~(v8 - 1);
    }
    else
    {
      *v5 = v9 | 0x20;
      v6 = (signed __int64)(v5 + 1);
    }
  }
  else
  {
    v6 = (signed __int64)(v5 + 1);
    for ( *v5 = len - 1; len > 0; ++ip )
    {
      --len;
      *(_BYTE *)(++v6 - 1) = *ip;
    }
  }
  v14 = this->mCompressedLength;
  v15 = (_DWORD)ip - LODWORD(this->mInput) - LODWORD(this->mCompressedLength);
  this->mInPlacePosition = v14;
  v16 = v15 + 1;
  if ( v16 > this->mInPlacePadding )
    this->mInPlacePadding = v16;
  this->mOutputPosition += v6 - (_QWORD)v5;
  this->mCompressedLength = v6 + v14 - (_QWORD)v5;
}

// File Line: 378
// RVA: 0x16DBC0
char __fastcall UFG::qEncoderContextLZ::FinalFlush(UFG::qEncoderContextLZ *this)
{
  bool (__fastcall *v1)(void *, __int64, void *, __int64); // rax
  UFG::qEncoderContextLZ *v2; // rbx
  __int64 v3; // r9
  char result; // al
  __int64 v5; // rax
  __int64 v6; // rcx
  __int64 v7; // rax
  bool (__fastcall *v8)(void *, __int64, void *, __int64); // rax

  v1 = this->mFlushCallback;
  v2 = this;
  if ( !v1
    || (v3 = this->mOutputPosition, v3 <= 0)
    || (result = ((__int64 (__fastcall *)(void *, __int64, char *))v1)(
                   this->mCallbackParam,
                   this->mCompressedLength - v3,
                   this->mOutput)) != 0 )
  {
    v5 = v2->mCompressedLength;
    v6 = v2->mInputLength;
    v2->mHeader.mCompressedNumBytes = v5;
    if ( v5 > v6 )
      v2->mHeader.mInPlaceExtraNumBytes += v5 - v6;
    v7 = v2->mInPlacePosition + v2->mInPlacePadding;
    if ( v7 > v6 )
      v2->mHeader.mInPlaceExtraNumBytes += v7 - v6;
    UFG::qCompressHeader::EndianSwap(&v2->mHeader);
    v2->mHeader.mInPlaceExtraNumBytes += -(v2->mHeader.mInPlaceExtraNumBytes
                                         + LODWORD(v2->mHeader.mUncompressedNumBytes)
                                         - LODWORD(v2->mHeader.mCompressedNumBytes)) & 7;
    v8 = v2->mFlushCallback;
    if ( !v8 )
    {
      UFG::qMemCopy(v2->mOutput, &v2->mHeader, 0x40u);
      return 1;
    }
    result = v8(v2->mCallbackParam, 0i64, &v2->mHeader, 64i64);
    if ( result )
      return 1;
  }
  return result;
}

// File Line: 430
// RVA: 0x169B20
UFG::qEncoderContextLZ::Compress

// File Line: 625
// RVA: 0x182730
UFG::qCompressBufferedLZ

// File Line: 663
// RVA: 0x183080
__int64 __fastcall UFG::qDecompressLZ(UFG::qCompressHeader *input, __int64 input_length, void *output, __int64 output_length)
{
  char *v4; // r14
  UFG::qCompressHeader *v5; // rsi
  __int128 v6; // ST30_16
  int v7; // eax
  __int128 v8; // ST40_16
  __int128 v9; // xmm0
  int *v11; // rdi
  signed __int64 v12; // rcx
  int v13; // ebp
  char *v14; // rdi
  char *v15; // rbx
  char *v16; // r9
  unsigned __int8 v17; // al
  int j; // ecx
  unsigned __int8 v19; // r8
  unsigned int v20; // edx
  unsigned int v21; // ecx
  int v22; // er8
  int v23; // edx
  int v24; // eax
  int v25; // eax
  char *i; // rcx
  int v27[32]; // [rsp+60h] [rbp-98h]
  int v28; // [rsp+E0h] [rbp-18h]

  v4 = (char *)output;
  v5 = input;
  v6 = *(_OWORD *)&input->mCompressedNumBytes;
  v7 = _mm_cvtsi128_si32(*(__m128i *)&input->mID);
  v8 = *(_OWORD *)&input->mUncompressedChecksum;
  v9 = *(_OWORD *)&input->pad2;
  if ( v7 != PMCQ && v7 != QCMP )
    return -1i64;
  UFG::qCompressHeader::EndianSwap(input);
  v11 = v27;
  v12 = 32i64;
  v13 = 0;
  while ( v12 )
  {
    *v11 = 0;
    ++v11;
    --v12;
  }
  v28 = 0;
  v14 = v4;
  UFG::qCompressHeader::EndianSwap(v5);
  v15 = (char *)v5 + v5->mDataOffset;
  UFG::qCompressHeader::EndianSwap(v5);
  v16 = &v15[v5->mCompressedNumBytes - v5->mDataOffset];
  while ( v15 < v16 )
  {
    v17 = *v15++;
    if ( v17 >= 0x20u )
    {
      v19 = v17;
      v20 = (unsigned int)v17 >> 5;
      if ( v20 == 1 )
      {
        v21 = v27[v17 & 0x1F];
        v22 = (unsigned __int16)v21;
        v23 = v21 >> 16;
      }
      else
      {
        v24 = (unsigned __int8)*v15++;
        v22 = v24 | ((v19 & 0x1F) << 8);
        if ( v20 == 7 )
          v20 = (unsigned __int8)*v15++;
        v23 = v20 + 1;
        v27[v13] = (unsigned __int16)v22 | (v23 << 16);
        v25 = v28 + 1;
        v13 = v25 & ~((v25 != 32) - 1);
        v28 = v25 & ~((v25 != 32) - 1);
      }
      for ( i = &v14[-v22]; v23 > 0; ++i )
      {
        --v23;
        *(++v14 - 1) = *i;
      }
    }
    else
    {
      for ( j = v17 + 1; j > 0; ++v15 )
      {
        --j;
        *(++v14 - 1) = *v15;
      }
    }
  }
  return v14 - v4;
}

