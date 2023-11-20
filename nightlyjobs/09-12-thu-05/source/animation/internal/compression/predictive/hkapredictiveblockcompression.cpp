// File Line: 113
// RVA: 0xBABE70
const char *__fastcall hkaPredictiveBlockCompression::decodeSingleFrame(const char *data, int whichFrame, __int16 *frameData)
{
  return hkaPredictiveBlockCompression::ScalarDecoder::decodeSingleFrame(data, whichFrame, frameData);
}

// File Line: 117
// RVA: 0xBABE80
const char *__fastcall hkaPredictiveBlockCompression::decodeAdjacentFrames(const char *data, int whichFrame, __int16 *frameData)
{
  return hkaPredictiveBlockCompression::ScalarDecoder::decodeAdjacentFrames(data, whichFrame, frameData);
}

// File Line: 121
// RVA: 0xBABE60
const char *__fastcall hkaPredictiveBlockCompression::decodeWholeBlock(const char *data, hkaPredictiveBlockCompression::Block *block)
{
  return hkaPredictiveBlockCompression::ScalarDecoder::decodeWholeBlock(data, block);
}

// File Line: 126
// RVA: 0xBABE50
char *__fastcall hkaPredictiveBlockCompression::encodeBlock(hkaPredictiveBlockCompression::Block *data, int nframes, int nchannels, char *out)
{
  return hkaPredictiveBlockCompression::ScalarEncoder::encodeBlock(data, nframes, nchannels, out);
}

// File Line: 134
// RVA: 0xBAD710
__int16 __fastcall hkaPredictiveBlockCompression::signExtend(__int16 val, int width)
{
  return (signed __int16)(val << (16 - width)) >> (16 - width);
}

// File Line: 145
// RVA: 0xBAD730
bool __fastcall hkaPredictiveBlockCompression::ScalarEncoder::fitsIn(int value, int bitlen)
{
  bool result; // al

  if ( bitlen )
    result = (unsigned int)(value >> (bitlen - 1)) >= 0xFFFFFFFF || value >> (bitlen - 1) == 0;
  else
    result = value == 0;
  return result;
}

// File Line: 159
// RVA: 0xBAD760
void __fastcall hkaPredictiveBlockCompression::ScalarEncoder::writeBits(char *data, int *pos, int value, int nbits)
{
  int v4; // er11
  int v5; // ebx
  int v6; // eax
  __int64 v7; // r8
  int v8; // eax
  __int64 v9; // r8

  v4 = value;
  v5 = nbits;
  v6 = *pos % -8;
  LODWORD(v7) = *pos / 8;
  if ( v6 )
  {
    v7 = (signed int)v7;
    if ( 8 - v6 < nbits )
      nbits = 8 - v6;
    v5 -= nbits;
    data[v7] |= ((unsigned __int8)v4 & (unsigned __int8)((1 << (nbits & 0x1F)) - ((nbits >> 5) & 1) - 1)) << v6;
    v4 >>= nbits;
    *pos += nbits;
  }
  v8 = (signed int)((((v5 >> 31) & 7) + v5) & 0xFFFFFFF8) / 8;
  if ( v8 > 0 )
  {
    v9 = (unsigned int)v8;
    v5 -= 8 * v8;
    do
    {
      data[*pos / 8] = v4;
      *pos += 8;
      v4 >>= 8;
      --v9;
    }
    while ( v9 );
  }
  if ( v5 > 0 )
  {
    data[*pos / 8] = v4 & ((1 << (v5 & 0x1F)) - ((v5 >> 5) & 1) - 1);
    *pos += v5;
  }
}

// File Line: 191
// RVA: 0xBAD880
__int64 __fastcall hkaPredictiveBlockCompression::ScalarEncoder::encodeSegment(__int16 *data, int nitems, char **out)
{
  int v3; // ebp
  char **v4; // rsi
  __int16 *v5; // rdi
  __int64 v6; // r14
  __int64 v7; // r15
  int v8; // er9
  int i; // ebx
  int v10; // edx
  __int64 result; // rax
  __int64 v12; // r9
  char *v13; // r8
  char v14; // cl
  char v15; // [rsp+1Fh] [rbp-29h]
  char dataa; // [rsp+20h] [rbp-28h]
  __int64 v17; // [rsp+21h] [rbp-27h]
  int v18; // [rsp+29h] [rbp-1Fh]
  __int16 v19; // [rsp+2Dh] [rbp-1Bh]
  char v20; // [rsp+2Fh] [rbp-19h]
  int pos; // [rsp+58h] [rbp+10h]

  v17 = 0i64;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v3 = 0;
  v4 = out;
  v5 = data;
  dataa = 0;
  pos = 0;
  if ( nitems % 2 )
    data[nitems] = 0;
  v6 = 0i64;
  v7 = nitems;
  if ( nitems > 0 )
  {
    do
    {
      v8 = v5[v6];
      for ( i = 0;
            !hkaPredictiveBlockCompression::ScalarEncoder::fitsIn(v8, i)
         || !hkaPredictiveBlockCompression::ScalarEncoder::fitsIn(v5[v6 + 1], v10);
            ++i )
      {
        ;
      }
      hkaPredictiveBlockCompression::ScalarEncoder::writeBits(&dataa, &pos, i, 4);
      hkaPredictiveBlockCompression::ScalarEncoder::writeBits(&dataa, &pos, v5[v6], i);
      hkaPredictiveBlockCompression::ScalarEncoder::writeBits(&dataa, &pos, v5[v6 + 1], i);
      v6 += 2i64;
    }
    while ( v6 < v7 );
    v3 = pos;
  }
  result = (v3 + 7) / 8;
  v12 = (signed int)result;
  if ( (signed int)result > 0 )
  {
    v13 = &v15 + (signed int)result;
    do
    {
      v14 = *v13--;
      *(*v4)++ = v14;
      --v12;
    }
    while ( v12 );
  }
  return result;
}

// File Line: 237
// RVA: 0xBAD9E0
void __fastcall hkaPredictiveBlockCompression::ScalarEncoder::encodeTrackBlock(__int16 *data, int nitems, char **out, char *sizebyte)
{
  char *v4; // r14
  char **v5; // rdi
  int v6; // esi
  __int16 *v7; // rbp
  char v8; // bl
  char v9; // al

  v4 = sizebyte;
  v5 = out;
  v6 = nitems;
  v7 = data;
  if ( nitems <= 8 )
  {
    v8 = hkaPredictiveBlockCompression::ScalarEncoder::encodeSegment(data, nitems, out);
    *(*v5)++ = 0;
    v9 = 1;
  }
  else
  {
    v8 = hkaPredictiveBlockCompression::ScalarEncoder::encodeSegment(data, 8, out);
    v9 = hkaPredictiveBlockCompression::ScalarEncoder::encodeSegment(v7 + 8, v6 - 8, v5);
  }
  *v4 = (v9 - 1) | 16 * (v8 - 1);
}

// File Line: 259
// RVA: 0xBAD400
char *__fastcall hkaPredictiveBlockCompression::ScalarEncoder::encodeBlock(hkaPredictiveBlockCompression::Block *data, int nframes, int nchannels, char *out)
{
  char *v4; // r10
  char *v5; // rsi
  char *v6; // r13
  __int64 v7; // r12
  int v8; // er15
  char *v9; // r9
  signed __int64 v10; // rax
  __int128 v11; // xmm0
  __int128 v12; // xmm1
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  __int128 v15; // xmm0
  __int128 v16; // xmm1
  __int128 v17; // xmm0
  __int128 v18; // xmm1
  int v19; // er14
  __int64 v20; // rdi
  char *v21; // r10
  signed __int64 v22; // rax
  signed __int64 v23; // r11
  __int16 *v24; // rax
  __int16 v25; // cx
  __int16 v26; // dx
  __int16 v27; // r8
  __int16 v28; // cx
  __int16 v29; // r8
  __int16 v30; // cx
  signed __int64 v31; // rax
  char *v32; // rbp
  char *v33; // rsi
  char *v34; // rbx
  __int16 *v35; // rdi
  __int64 v36; // rsi
  signed __int64 i; // rax
  int v38; // er15
  hkOstream *v39; // rax
  hkOstream *v40; // rax
  hkOstream *v41; // rax
  hkOstream *v42; // rax
  hkOstream *v43; // rax
  hkOstream *v44; // rax
  hkErrStream v46; // [rsp+20h] [rbp-248h]
  char Dst; // [rsp+40h] [rbp-228h]
  char *outa; // [rsp+288h] [rbp+20h]

  v4 = &Dst;
  v5 = out;
  v6 = out;
  v7 = (unsigned int)nchannels;
  v8 = nframes;
  v9 = &Dst;
  if ( ((unsigned __int8)&Dst | (unsigned __int8)data) & 0xF )
  {
    memmove(&Dst, data, 0x200ui64);
  }
  else
  {
    v10 = 4i64;
    do
    {
      v11 = *(_OWORD *)&data->data[0][0];
      v12 = *(_OWORD *)&data->data[0][8];
      v4 += 128;
      data = (hkaPredictiveBlockCompression::Block *)((char *)data + 128);
      *((_OWORD *)v4 - 8) = v11;
      v13 = *(_OWORD *)&data[-1].data[13][0];
      *((_OWORD *)v4 - 7) = v12;
      v14 = *(_OWORD *)&data[-1].data[13][8];
      *((_OWORD *)v4 - 6) = v13;
      v15 = *(_OWORD *)&data[-1].data[14][0];
      *((_OWORD *)v4 - 5) = v14;
      v16 = *(_OWORD *)&data[-1].data[14][8];
      *((_OWORD *)v4 - 4) = v15;
      v17 = *(_OWORD *)&data[-1].data[15][0];
      *((_OWORD *)v4 - 3) = v16;
      v18 = *(_OWORD *)&data[-1].data[15][8];
      *((_OWORD *)v4 - 2) = v17;
      *((_OWORD *)v4 - 1) = v18;
      --v10;
    }
    while ( v10 );
  }
  v19 = 0;
  v20 = (signed int)v7;
  if ( (signed int)v7 > 0 )
  {
    v21 = &Dst;
    do
    {
      v22 = 0i64;
      do
        *(_WORD *)&v21[2 * v22++] *= 4;
      while ( v22 < 16 );
      v23 = 3i64;
      do
      {
        v24 = (__int16 *)(v21 + 26);
        v9 = (char *)3;
        do
        {
          v25 = v24[1];
          v26 = *v24;
          v27 = *(v24 - 1);
          v24[2] -= v25;
          v24[1] = v25 - v26;
          v28 = *(v24 - 2);
          *v24 = v26 - v27;
          v29 = v27 - v28;
          v30 = v28 - *(v24 - 3);
          v24 -= 5;
          v24[4] = v29;
          v24[3] = v30;
          --v9;
        }
        while ( v9 );
        --v23;
      }
      while ( v23 );
      v31 = 0i64;
      do
        *(_WORD *)&v21[2 * v31++] >>= 2;
      while ( v31 < 16 );
      v21 += 32;
      --v20;
    }
    while ( v20 );
  }
  v32 = v5;
  v33 = v5 + 16;
  outa = v33;
  if ( (signed int)v7 > 0 )
  {
    v34 = v32;
    v35 = (__int16 *)&Dst;
    v36 = v7;
    v19 = v7;
    do
    {
      hkaPredictiveBlockCompression::ScalarEncoder::encodeTrackBlock(v35, v8, &outa, v34++);
      v35 += 16;
      --v36;
    }
    while ( v36 );
    v33 = outa;
  }
  for ( i = v19; i < 16; v33 += 2 )
  {
    v32[i++] = 0;
    *(_WORD *)v33 = 0;
  }
  ((void (__fastcall *)(hkError *, signed __int64, const char *, char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    2553462578i64,
    "Predictive Block Compression",
    v9);
  hkErrStream::hkErrStream(&v46, &Dst, 512);
  v38 = v7 * v8;
  v39 = hkOstream::operator<<((hkOstream *)&v46.vfptr, "Block (");
  v40 = hkOstream::operator<<(v39, v38);
  v41 = hkOstream::operator<<(v40, " samples) compressed to ");
  v42 = hkOstream::operator<<(v41, (signed int)v33 - (signed int)v6);
  v43 = hkOstream::operator<<(v42, " bytes (");
  v44 = hkOstream::operator<<(v43, 100 * (v33 - v6) / (2 * v38));
  hkOstream::operator<<(v44, "% of original");
  hkError::messageReport(-1, &Dst, "Compression\\Predictive\\hkaPredictiveBlockCompression.cpp", 309);
  hkOstream::~hkOstream((hkOstream *)&v46.vfptr);
  ((void (*)(void))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)();
  return v33;
}

// File Line: 774
// RVA: 0xBADA70
void __fastcall hkaPredictiveBlockCompression::ScalarDecoder::copyBigEndianToUint64(unsigned __int64 *dest64, const char *sourceBigEndian)
{
  *(_BYTE *)dest64 = sourceBigEndian[7];
  *((_BYTE *)dest64 + 1) = sourceBigEndian[6];
  *((_BYTE *)dest64 + 2) = sourceBigEndian[5];
  *((_BYTE *)dest64 + 3) = sourceBigEndian[4];
  *((_BYTE *)dest64 + 4) = sourceBigEndian[3];
  *((_BYTE *)dest64 + 5) = sourceBigEndian[2];
  *((_BYTE *)dest64 + 6) = sourceBigEndian[1];
  *((_BYTE *)dest64 + 7) = *sourceBigEndian;
}

// File Line: 795
// RVA: 0xBADAB0
void __fastcall hkaPredictiveBlockCompression::ScalarDecoder::decodeSegment(const char *coded, __int16 *decoded)
{
  __int16 *v2; // r12
  int v3; // edx
  char v4; // cl
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // rbx
  int v7; // edx
  char v8; // cl
  unsigned __int64 v9; // r11
  int v10; // edx
  int v11; // er8
  unsigned __int64 v12; // [rsp+50h] [rbp+18h]
  unsigned __int64 v13; // [rsp+50h] [rbp+18h]
  unsigned __int64 v14; // [rsp+60h] [rbp+28h]

  v2 = decoded;
  v14 = *((unsigned __int8 *)coded - 9);
  *(_DWORD *)((char *)&v14 + 1) = *((unsigned __int8 *)coded - 10);
  WORD1(v14) = *((unsigned __int8 *)coded - 11);
  BYTE3(v14) = *(coded - 12);
  BYTE4(v14) = *(coded - 13);
  *(_WORD *)((char *)&v14 + 5) = *((unsigned __int8 *)coded - 14);
  BYTE6(v14) = *(coded - 15);
  HIBYTE(v14) = *(coded - 16);
  v12 = *((unsigned __int8 *)coded - 1);
  *(_DWORD *)((char *)&v12 + 1) = *((unsigned __int8 *)coded - 2);
  WORD1(v12) = *((unsigned __int8 *)coded - 3);
  BYTE3(v12) = *(coded - 4);
  BYTE4(v12) = *(coded - 5);
  *(_WORD *)((char *)&v12 + 5) = *((unsigned __int8 *)coded - 6);
  BYTE6(v12) = *(coded - 7);
  HIBYTE(v12) = *(coded - 8);
  if ( HK_flyingcolors_animation_1.m_bool
    || (hkaCheckKeycode(coded, decoded),
        hkaProcessFlyingColors(&HK_flyingcolors_animation_1),
        HK_flyingcolors_animation_1.m_bool) )
  {
    v3 = v12 & 0xF;
    *v2 = (signed __int16)((((signed int)v12 >> 2) & 0xFFFC) << (16 - (v3 + 2))) >> (16 - (v3 + 2));
    v2[1] = (signed __int16)(4 * (unsigned __int16)((signed int)v12 >> (v3 + 4)) << (16 - (v3 + 2))) >> (16 - (v3 + 2));
    v4 = 2 * (v3 + 2);
    v5 = v14 >> v4;
    v6 = (v12 >> v4) | ((unsigned __int64)((unsigned int)v14 & ((1 << (2 * (v3 + 2) & 0x1F))
                                                              - ((2 * (v3 + 2) >> 5) & 1)
                                                              - 1)) << (64 - 2 * ((unsigned __int8)v3 + 2)));
    v7 = v6 & 0xF;
    v2[2] = (signed __int16)((((signed int)v6 >> 2) & 0xFFFC) << (16 - (v7 + 2))) >> (16 - (v7 + 2));
    v2[3] = (signed __int16)(4 * (unsigned __int16)((signed int)v6 >> (v7 + 4)) << (16 - (v7 + 2))) >> (16 - (v7 + 2));
    v8 = 2 * (v7 + 2);
    v9 = (v6 >> v8) | ((unsigned __int64)((unsigned int)v5 & ((1 << (2 * (v7 + 2) & 0x1F))
                                                            - ((2 * (v7 + 2) >> 5) & 1)
                                                            - 1)) << (64 - 2 * ((unsigned __int8)v7 + 2)));
    v10 = v9 & 0xF;
    v2[4] = (signed __int16)((((signed int)v9 >> 2) & 0xFFFC) << (16 - (v10 + 2))) >> (16 - (v10 + 2));
    v2[5] = (signed __int16)(4 * (unsigned __int16)((signed int)v9 >> (v10 + 4)) << (16 - (v10 + 2))) >> (16 - (v10 + 2));
    v11 = (v9 >> 2 * ((unsigned __int8)v10 + 2)) | (((v5 >> v8) & ((1 << (2 * (v10 + 2) & 0x1F))
                                                                 - ((2 * (v10 + 2) >> 5) & 1u)
                                                                 - 1)) << (64 - 2 * ((unsigned __int8)v10 + 2)));
    v13 = (v9 >> 2 * ((unsigned __int8)v10 + 2)) | (((v5 >> v8) & ((1 << (2 * (v10 + 2) & 0x1F))
                                                                 - ((2 * (v10 + 2) >> 5) & 1u)
                                                                 - 1)) << (64 - 2 * ((unsigned __int8)v10 + 2)));
    LOBYTE(v10) = v13 & 0xF;
    v2[6] = (signed __int16)((((signed int)v13 >> 2) & 0xFFFC) << (16 - (v10 + 2))) >> (16 - (v10 + 2));
    v2[7] = (signed __int16)(4 * (unsigned __int16)(v11 >> (v10 + 4)) << (16 - (v10 + 2))) >> (16 - (v10 + 2));
  }
}

// File Line: 838
// RVA: 0xBADD80
void __fastcall hkaPredictiveBlockCompression::ScalarDecoder::deltaDecode(__int16 *data)
{
  signed __int64 v1; // rdx

  v1 = 3i64;
  do
  {
    data[1] += *data;
    data[2] += data[1];
    data[3] += data[2];
    data[4] += data[3];
    data[5] += data[4];
    data[6] += data[5];
    data[7] += data[6];
    data[8] += data[7];
    data[9] += data[8];
    data[10] += data[9];
    data[11] += data[10];
    data[12] += data[11];
    data[13] += data[12];
    data[14] += data[13];
    data[15] += data[14];
    --v1;
  }
  while ( v1 );
  *data >>= 2;
  data[1] >>= 2;
  data[2] >>= 2;
  data[3] >>= 2;
  data[4] >>= 2;
  data[5] >>= 2;
  data[6] >>= 2;
  data[7] >>= 2;
  data[8] >>= 2;
  data[9] >>= 2;
  data[10] >>= 2;
  data[11] >>= 2;
  data[12] >>= 2;
  data[13] >>= 2;
  data[14] >>= 2;
  data[15] >>= 2;
}

// File Line: 862
// RVA: 0xBACD70
const char *__fastcall hkaPredictiveBlockCompression::ScalarDecoder::decodeWholeBlock(const char *data, hkaPredictiveBlockCompression::Block *block)
{
  const char *v2; // r12
  const char *v3; // r14
  __int16 *v4; // rbx
  signed __int64 v5; // r13
  unsigned int v6; // eax
  int v7; // er15
  const char *v8; // r14
  __int64 v9; // rdx
  char v10; // al
  int v11; // edx
  char v12; // cl
  unsigned __int64 v13; // rsi
  unsigned __int64 v14; // rdi
  int v15; // edx
  char v16; // cl
  unsigned __int64 v17; // r11
  unsigned __int64 v18; // rsi
  int v19; // edx
  unsigned __int64 v20; // r11
  int v21; // er9
  int v22; // edx
  char v23; // cl
  unsigned __int64 v24; // rsi
  unsigned __int64 v25; // rdi
  int v26; // edx
  char v27; // cl
  unsigned __int64 v28; // r11
  unsigned __int64 v29; // rsi
  int v30; // edx
  unsigned __int64 v31; // r11
  int v32; // er9
  unsigned __int64 v34; // [rsp+60h] [rbp+40h]
  unsigned __int64 v35; // [rsp+60h] [rbp+40h]
  unsigned __int64 v36; // [rsp+70h] [rbp+50h]
  unsigned __int64 v37; // [rsp+70h] [rbp+50h]

  v2 = data;
  v3 = data + 16;
  v4 = &block->data[0][10];
  v5 = 16i64;
  do
  {
    v6 = *(unsigned __int8 *)v2;
    v7 = (v6 & 0xF) + 1;
    v8 = &v3[(v6 >> 4) + 1];
    LOBYTE(v36) = *(v8 - 9);
    BYTE1(v36) = *(v8 - 10);
    BYTE2(v36) = *(v8 - 11);
    BYTE3(v36) = *(v8 - 12);
    BYTE4(v36) = *(v8 - 13);
    BYTE5(v36) = *(v8 - 14);
    BYTE6(v36) = *(v8 - 15);
    HIBYTE(v36) = *(v8 - 16);
    LOBYTE(v34) = *(v8 - 1);
    BYTE1(v34) = *(v8 - 2);
    BYTE2(v34) = *(v8 - 3);
    BYTE3(v34) = *(v8 - 4);
    BYTE4(v34) = *(v8 - 5);
    BYTE5(v34) = *(v8 - 6);
    BYTE6(v34) = *(v8 - 7);
    HIBYTE(v34) = *(v8 - 8);
    if ( HK_flyingcolors_animation_1.m_bool
      || (hkaCheckKeycode(data, block),
          hkaProcessFlyingColors(&HK_flyingcolors_animation_1),
          (v10 = HK_flyingcolors_animation_1.m_bool) != 0) )
    {
      v11 = v34 & 0xF;
      *(v4 - 10) = (signed __int16)((((signed int)v34 >> 2) & 0xFFFC) << (16 - (v11 + 2))) >> (16 - (v11 + 2));
      *(v4 - 9) = (signed __int16)(4 * (unsigned __int16)((signed int)v34 >> (v11 + 4)) << (16 - (v11 + 2))) >> (16 - (v11 + 2));
      v12 = 2 * (v11 + 2);
      v13 = v36 >> v12;
      v14 = (v34 >> v12) | ((unsigned __int64)((unsigned int)v36 & ((1 << (2 * (v11 + 2) & 0x1F))
                                                                  - ((2 * (v11 + 2) >> 5) & 1)
                                                                  - 1)) << (64 - 2 * ((unsigned __int8)v11 + 2)));
      v15 = v14 & 0xF;
      *(v4 - 8) = (signed __int16)((((signed int)v14 >> 2) & 0xFFFC) << (16 - (v15 + 2))) >> (16 - (v15 + 2));
      *(v4 - 7) = (signed __int16)(4 * (unsigned __int16)((signed int)v14 >> (v15 + 4)) << (16 - (v15 + 2))) >> (16 - (v15 + 2));
      v16 = 2 * (v15 + 2);
      v17 = (v14 >> v16) | ((unsigned __int64)((unsigned int)v13 & ((1 << (2 * (v15 + 2) & 0x1F))
                                                                  - ((2 * (v15 + 2) >> 5) & 1)
                                                                  - 1)) << (64 - 2 * ((unsigned __int8)v15 + 2)));
      v18 = v13 >> v16;
      v19 = v17 & 0xF;
      *(v4 - 6) = (signed __int16)((((signed int)v17 >> 2) & 0xFFFC) << (16 - (v19 + 2))) >> (16 - (v19 + 2));
      *(v4 - 5) = (signed __int16)(4 * (unsigned __int16)((signed int)v17 >> (v19 + 4)) << (16 - (v19 + 2))) >> (16 - (v19 + 2));
      v20 = v17 >> 2 * ((unsigned __int8)v19 + 2);
      v21 = v20 | (((unsigned int)v18 & ((1 << (2 * (v19 + 2) & 0x1F)) - ((2 * (v19 + 2) >> 5) & 1) - 1)) << (64 - 2 * (v19 + 2)));
      v9 = ((unsigned __int8)v20 | (unsigned __int8)((unsigned __int64)((unsigned int)v18 & ((1 << (2 * (v19 + 2) & 0x1F))
                                                                                           - ((2 * (v19 + 2) >> 5) & 1)
                                                                                           - 1)) << (64 - 2 * ((unsigned __int8)v19 + 2)))) & 0xF;
      *(v4 - 4) = (signed __int16)(((v21 >> 2) & 0xFFFC) << (16 - (v9 + 2))) >> (16 - (v9 + 2));
      *(v4 - 3) = (signed __int16)(4 * (unsigned __int16)(v21 >> (v9 + 4)) << (16 - (v9 + 2))) >> (16 - (v9 + 2));
      v10 = HK_flyingcolors_animation_1.m_bool;
    }
    v3 = &v8[v7];
    LOBYTE(v37) = *(v3 - 9);
    BYTE1(v37) = *(v3 - 10);
    BYTE2(v37) = *(v3 - 11);
    BYTE3(v37) = *(v3 - 12);
    BYTE4(v37) = *(v3 - 13);
    BYTE5(v37) = *(v3 - 14);
    BYTE6(v37) = *(v3 - 15);
    HIBYTE(v37) = *(v3 - 16);
    LOBYTE(v35) = *(v3 - 1);
    BYTE1(v35) = *(v3 - 2);
    BYTE2(v35) = *(v3 - 3);
    BYTE3(v35) = *(v3 - 4);
    BYTE4(v35) = *(v3 - 5);
    BYTE5(v35) = *(v3 - 6);
    BYTE6(v35) = *(v3 - 7);
    HIBYTE(v35) = *(v3 - 8);
    if ( v10
      || (hkaCheckKeycode(*((unsigned __int8 *)v3 - 8), v9),
          hkaProcessFlyingColors(&HK_flyingcolors_animation_1),
          HK_flyingcolors_animation_1.m_bool) )
    {
      v22 = v35 & 0xF;
      *(v4 - 2) = (signed __int16)((((signed int)v35 >> 2) & 0xFFFC) << (16 - (v22 + 2))) >> (16 - (v22 + 2));
      *(v4 - 1) = (signed __int16)(4 * (unsigned __int16)((signed int)v35 >> (v22 + 4)) << (16 - (v22 + 2))) >> (16 - (v22 + 2));
      v23 = 2 * (v22 + 2);
      v24 = v37 >> v23;
      v25 = (v35 >> v23) | ((unsigned __int64)((unsigned int)v37 & ((1 << (2 * (v22 + 2) & 0x1F))
                                                                  - ((2 * (v22 + 2) >> 5) & 1)
                                                                  - 1)) << (64 - 2 * ((unsigned __int8)v22 + 2)));
      v26 = v25 & 0xF;
      *v4 = (signed __int16)((((signed int)v25 >> 2) & 0xFFFC) << (16 - (v26 + 2))) >> (16 - (v26 + 2));
      v4[1] = (signed __int16)(4 * (unsigned __int16)((signed int)v25 >> (v26 + 4)) << (16 - (v26 + 2))) >> (16 - (v26 + 2));
      v27 = 2 * (v26 + 2);
      v28 = (v25 >> v27) | ((unsigned __int64)((unsigned int)v24 & ((1 << (2 * (v26 + 2) & 0x1F))
                                                                  - ((2 * (v26 + 2) >> 5) & 1)
                                                                  - 1)) << (64 - 2 * ((unsigned __int8)v26 + 2)));
      v29 = v24 >> v27;
      v30 = v28 & 0xF;
      v4[2] = (signed __int16)((((signed int)v28 >> 2) & 0xFFFC) << (16 - (v30 + 2))) >> (16 - (v30 + 2));
      v4[3] = (signed __int16)(4 * (unsigned __int16)((signed int)v28 >> (v30 + 4)) << (16 - (v30 + 2))) >> (16 - (v30 + 2));
      v31 = v28 >> 2 * ((unsigned __int8)v30 + 2);
      v32 = v31 | (((unsigned int)v29 & ((1 << (2 * (v30 + 2) & 0x1F)) - ((2 * (v30 + 2) >> 5) & 1) - 1)) << (64 - 2 * (v30 + 2)));
      block = (hkaPredictiveBlockCompression::Block *)(((unsigned __int8)v31 | (unsigned __int8)((unsigned __int64)((unsigned int)v29 & ((1 << (2 * (v30 + 2) & 0x1F)) - ((2 * (v30 + 2) >> 5) & 1) - 1)) << (64 - 2 * ((unsigned __int8)v30 + 2)))) & 0xF);
      v4[4] = (signed __int16)(((v32 >> 2) & 0xFFFC) << (16 - ((_BYTE)block + 2))) >> (16 - ((_BYTE)block + 2));
      v4[5] = (signed __int16)(4 * (unsigned __int16)(v32 >> ((_BYTE)block + 4)) << (16 - ((_BYTE)block + 2))) >> (16 - ((_BYTE)block + 2));
    }
    data = (const char *)3;
    do
    {
      *(v4 - 9) += *(v4 - 10);
      *(v4 - 8) += *(v4 - 9);
      *(v4 - 7) += *(v4 - 8);
      *(v4 - 6) += *(v4 - 7);
      *(v4 - 5) += *(v4 - 6);
      *(v4 - 4) += *(v4 - 5);
      *(v4 - 3) += *(v4 - 4);
      *(v4 - 2) += *(v4 - 3);
      *(v4 - 1) += *(v4 - 2);
      *v4 += *(v4 - 1);
      v4[1] += *v4;
      v4[2] += v4[1];
      v4[3] += v4[2];
      v4[4] += v4[3];
      v4[5] += v4[4];
      --data;
    }
    while ( data );
    *(v4 - 10) >>= 2;
    *(v4 - 9) >>= 2;
    *(v4 - 8) >>= 2;
    *(v4 - 7) >>= 2;
    *(v4 - 6) >>= 2;
    *(v4 - 5) >>= 2;
    *(v4 - 4) >>= 2;
    *(v4 - 3) >>= 2;
    *(v4 - 2) >>= 2;
    *(v4 - 1) >>= 2;
    *v4 >>= 2;
    v4[1] >>= 2;
    v4[2] >>= 2;
    v4[3] >>= 2;
    v4[4] >>= 2;
    v4[5] >>= 2;
    v4 += 16;
    ++v2;
    --v5;
  }
  while ( v5 );
  return v3;
}
    v4[5] >>= 2;
    v4 += 16;
    ++v2;
    --v5;
  }
  while ( v5 );
  return v3;
}

// File Line: 879
// RVA: 0xBABE90
const char *__fastcall hkaPredictiveBlockCompression::ScalarDecoder::decodeSingleFrame(const char *data, int whichFrame, __int16 *out)
{
  __int16 v3; // di
  __int16 v4; // r13
  __int16 v5; // r12
  __int16 v6; // r15
  __int16 v7; // si
  const char *v8; // rbx
  unsigned int v9; // ecx
  unsigned int v10; // eax
  __int64 v11; // rcx
  __int64 v12; // rax
  const char *v13; // r14
  char v14; // al
  unsigned __int64 v15; // rdx
  signed int v16; // er10
  int v17; // edx
  int v18; // er8
  unsigned __int64 v19; // r11
  signed int v20; // ecx
  int v21; // edx
  signed int v22; // er10
  unsigned __int64 v23; // r10
  int v24; // edx
  unsigned __int64 v25; // rdx
  int v26; // er9
  int v27; // er9
  char v28; // cl
  int v29; // eax
  char v30; // r9
  signed int v31; // er14
  unsigned __int64 v32; // rdi
  unsigned __int64 v33; // r11
  int v34; // eax
  signed int v35; // er9
  char v36; // cl
  unsigned __int64 v37; // r10
  unsigned __int64 v38; // rdi
  int v39; // eax
  signed int v40; // er11
  unsigned __int64 v41; // r10
  int v42; // er9
  char v43; // dl
  int v44; // er9
  int v45; // ecx
  unsigned int v46; // edx
  unsigned int v47; // er8
  int v48; // er9
  signed int v49; // er10
  int v50; // ebx
  int v51; // eax
  signed int v52; // eax
  int v53; // ecx
  bool v54; // zf
  unsigned __int64 v56; // [rsp+20h] [rbp-49h]
  unsigned __int64 v57; // [rsp+20h] [rbp-49h]
  unsigned __int64 v58; // [rsp+28h] [rbp-41h]
  unsigned __int64 v59; // [rsp+28h] [rbp-41h]
  signed __int64 v60; // [rsp+28h] [rbp-41h]
  int v61; // [rsp+30h] [rbp-39h]
  int v62; // [rsp+34h] [rbp-35h]
  int v63; // [rsp+38h] [rbp-31h]
  signed int v64; // [rsp+3Ch] [rbp-2Dh]
  unsigned __int16 v65; // [rsp+40h] [rbp-29h]
  __int16 v66; // [rsp+42h] [rbp-27h]
  unsigned __int16 v67; // [rsp+44h] [rbp-25h]
  unsigned __int16 v68; // [rsp+46h] [rbp-23h]
  unsigned __int16 v69; // [rsp+48h] [rbp-21h]
  unsigned __int16 v70; // [rsp+4Ah] [rbp-1Fh]
  unsigned __int16 v71; // [rsp+4Ch] [rbp-1Dh]
  unsigned __int16 v72; // [rsp+4Eh] [rbp-1Bh]
  unsigned __int16 v73; // [rsp+50h] [rbp-19h]
  __int16 v74; // [rsp+52h] [rbp-17h]
  unsigned __int16 v75; // [rsp+54h] [rbp-15h]
  __int16 v76; // [rsp+56h] [rbp-13h]
  unsigned __int16 v77; // [rsp+58h] [rbp-11h]
  __int16 v78; // [rsp+5Ah] [rbp-Fh]
  __int16 v79; // [rsp+5Ch] [rbp-Dh]
  unsigned __int16 v80; // [rsp+5Eh] [rbp-Bh]
  int v81; // [rsp+60h] [rbp-9h]
  int v82; // [rsp+64h] [rbp-5h]
  unsigned __int64 v83; // [rsp+68h] [rbp-1h]
  int v84; // [rsp+70h] [rbp+7h]
  int v85; // [rsp+74h] [rbp+Bh]
  const char *v86; // [rsp+78h] [rbp+Fh]
  __int64 v87; // [rsp+80h] [rbp+17h]
  __int16 *v88; // [rsp+88h] [rbp+1Fh]
  int v89; // [rsp+D0h] [rbp+67h]
  const char *v90; // [rsp+D0h] [rbp+67h]
  __int16 *v91; // [rsp+E0h] [rbp+77h]
  signed int v92; // [rsp+E8h] [rbp+7Fh]

  v91 = out;
  v3 = v79;
  v4 = v78;
  v5 = v76;
  v6 = v74;
  v7 = v66;
  v81 = v75;
  v88 = (__int16 *)(&v65 + whichFrame);
  v63 = v71;
  v62 = v80;
  v85 = v77;
  v86 = data;
  v84 = v73;
  v8 = data + 16;
  v61 = v69;
  v87 = 16i64;
  v92 = v67;
  v82 = v72;
  LODWORD(v83) = v70;
  HIDWORD(v83) = v68;
  v64 = v65;
  do
  {
    v9 = *(unsigned __int8 *)data;
    v10 = v9;
    v11 = (v9 & 0xF) + 1;
    v89 = v11;
    v12 = (signed int)((v10 >> 4) + 1);
    v13 = &v8[v12];
    LOBYTE(v58) = v8[v12 - 9];
    BYTE1(v58) = v8[v12 - 10];
    BYTE2(v58) = v8[v12 - 11];
    BYTE3(v58) = v8[v12 - 12];
    BYTE4(v58) = v8[v12 - 13];
    BYTE5(v58) = v8[v12 - 14];
    BYTE6(v58) = v8[v12 - 15];
    HIBYTE(v58) = v8[v12 - 16];
    LOBYTE(v56) = v8[v12 - 1];
    BYTE1(v56) = v8[v12 - 2];
    BYTE2(v56) = v8[v12 - 3];
    BYTE3(v56) = v8[v12 - 4];
    BYTE4(v56) = v8[v12 - 5];
    BYTE5(v56) = v8[v12 - 6];
    BYTE6(v56) = v8[v12 - 7];
    HIBYTE(v56) = v8[v12 - 8];
    v14 = HK_flyingcolors_animation_1.m_bool;
    if ( HK_flyingcolors_animation_1.m_bool
      || (hkaCheckKeycode(v11, 0i64),
          hkaProcessFlyingColors(&HK_flyingcolors_animation_1),
          (v14 = HK_flyingcolors_animation_1.m_bool) != 0) )
    {
      v16 = (signed int)v56 >> 2;
      v17 = v56 & 0xF;
      LOWORD(v16) = (signed __int16)((((signed int)v56 >> 2) & 0xFFFC) << (16 - (v17 + 2))) >> (16 - (v17 + 2));
      v64 = v16;
      v18 = 2 * (v17 + 2);
      v7 = (signed __int16)(4 * (unsigned __int16)((signed int)v56 >> (v17 + 4)) << (16 - (v17 + 2))) >> (16 - (v17 + 2));
      v19 = (v56 >> v18) | ((unsigned __int64)((unsigned int)v58 & ((1 << (v18 & 0x1F)) - ((v18 >> 5) & 1) - 1)) << (64 - (unsigned __int8)v18));
      v20 = (signed int)v19 >> 2;
      v21 = v19 & 0xF;
      LOWORD(v20) = ((signed int)v19 >> 2) & 0xFFFC;
      v92 = v20;
      LOWORD(v92) = (signed __int16)((_WORD)v20 << (16 - (v21 + 2))) >> (16 - (v21 + 2));
      v22 = (signed int)v19 >> (v21 + 4);
      LOWORD(v22) = (signed __int16)(4 * (_WORD)v22 << (16 - (v21 + 2))) >> (16 - (v21 + 2));
      HIDWORD(v83) = v22;
      LOBYTE(v20) = 2 * (v21 + 2);
      v23 = (v19 >> v20) | (((v58 >> v18) & ((1 << (2 * (v21 + 2) & 0x1F)) - ((2 * (v21 + 2) >> 5) & 1u) - 1)) << (64 - 2 * ((unsigned __int8)v21 + 2)));
      v24 = ((unsigned __int8)(v19 >> v20) | (unsigned __int8)(((v58 >> v18) & ((1 << (2 * (v21 + 2) & 0x1F))
                                                                              - ((2 * (v21 + 2) >> 5) & 1u)
                                                                              - 1)) << (64
                                                                                      - 2 * ((unsigned __int8)v21 + 2)))) & 0xF;
      HIWORD(v61) = (unsigned int)((signed int)v23 >> 2) >> 16;
      LOWORD(v61) = (signed __int16)((((signed int)v23 >> 2) & 0xFFFC) << (16 - (v24 + 2))) >> (16 - (v24 + 2));
      LODWORD(v19) = (signed int)v23 >> (v24 + 4);
      LOWORD(v19) = (signed __int16)(4 * (_WORD)v19 << (16 - (v24 + 2))) >> (16 - (v24 + 2));
      LODWORD(v83) = v19;
      v25 = (v23 >> 2 * ((unsigned __int8)v24 + 2)) | ((unsigned __int64)((unsigned int)(v58 >> v18 >> v20) & ((1 << (2 * (v24 + 2) & 0x1F)) - ((2 * (v24 + 2) >> 5) & 1) - 1)) << (64 - 2 * ((unsigned __int8)v24 + 2)));
      v26 = v25;
      v15 = v25 & 0xF;
      LODWORD(v23) = v26 >> 2;
      LOWORD(v23) = (signed __int16)(((v26 >> 2) & 0xFFFC) << (16 - (v15 + 2))) >> (16 - (v15 + 2));
      v27 = v26 >> (v15 + 4);
      v63 = v23;
      LOWORD(v27) = (signed __int16)(4 * (_WORD)v27 << (16 - (v15 + 2))) >> (16 - (v15 + 2));
      v82 = v27;
    }
    v28 = v13[v89 - 9];
    v90 = &v13[v89];
    LOBYTE(v59) = v28;
    BYTE1(v59) = *(v90 - 10);
    BYTE2(v59) = *(v90 - 11);
    BYTE3(v59) = *(v90 - 12);
    BYTE4(v59) = *(v90 - 13);
    BYTE5(v59) = *(v90 - 14);
    BYTE6(v59) = *(v90 - 15);
    HIBYTE(v59) = *(v90 - 16);
    LOBYTE(v57) = *(v90 - 1);
    BYTE1(v57) = *(v90 - 2);
    BYTE2(v57) = *(v90 - 3);
    BYTE3(v57) = *(v90 - 4);
    BYTE4(v57) = *(v90 - 5);
    BYTE5(v57) = *(v90 - 6);
    BYTE6(v57) = *(v90 - 7);
    HIBYTE(v57) = *(v90 - 8);
    if ( v14
      || (hkaCheckKeycode(*((unsigned __int8 *)v90 - 8), v15),
          hkaProcessFlyingColors(&HK_flyingcolors_animation_1),
          HK_flyingcolors_animation_1.m_bool) )
    {
      v29 = v57 & 0xF;
      v31 = (signed int)v57 >> 2;
      v30 = 2 * (v29 + 2);
      LOWORD(v31) = (signed __int16)((((signed int)v57 >> 2) & 0xFFFC) << (16 - (v29 + 2))) >> (16 - (v29 + 2));
      v6 = (signed __int16)(4 * (unsigned __int16)((signed int)v57 >> (v29 + 4)) << (16 - (v29 + 2))) >> (16 - (v29 + 2));
      v32 = v59 >> v30;
      v33 = (v57 >> v30) | ((unsigned __int64)((unsigned int)v59 & ((1 << (2 * (v29 + 2) & 0x1F))
                                                                  - ((2 * (v29 + 2) >> 5) & 1)
                                                                  - 1)) << (64 - 2 * ((unsigned __int8)v29 + 2)));
      v34 = v33 & 0xF;
      v35 = (signed int)v33 >> 2;
      LOWORD(v35) = (signed __int16)((((signed int)v33 >> 2) & 0xFFFC) << (16 - (v34 + 2))) >> (16 - (v34 + 2));
      v81 = v35;
      v5 = (signed __int16)(4 * (unsigned __int16)((signed int)v33 >> (v34 + 4)) << (16 - (v34 + 2))) >> (16 - (v34 + 2));
      v36 = 2 * (v34 + 2);
      v37 = (v33 >> v36) | ((unsigned __int64)((unsigned int)v32 & ((1 << (2 * (v34 + 2) & 0x1F))
                                                                  - ((2 * (v34 + 2) >> 5) & 1)
                                                                  - 1)) << (64 - 2 * ((unsigned __int8)v34 + 2)));
      v38 = v32 >> v36;
      v39 = v37 & 0xF;
      v40 = (signed int)v37 >> 2;
      LOWORD(v40) = (signed __int16)((((signed int)v37 >> 2) & 0xFFFC) << (16 - (v39 + 2))) >> (16 - (v39 + 2));
      v4 = (signed __int16)(4 * (unsigned __int16)((signed int)v37 >> (v39 + 4)) << (16 - (v39 + 2))) >> (16 - (v39 + 2));
      v41 = v37 >> 2 * ((unsigned __int8)v39 + 2);
      v42 = v41 | (((unsigned int)v38 & ((1 << (2 * (v39 + 2) & 0x1F)) - ((2 * (v39 + 2) >> 5) & 1) - 1)) << (64 - 2 * (v39 + 2)));
      v43 = (v41 | ((unsigned __int64)((unsigned int)v38 & ((1 << (2 * (v39 + 2) & 0x1F))
                                                          - ((2 * (v39 + 2) >> 5) & 1)
                                                          - 1)) << (64 - 2 * ((unsigned __int8)v39 + 2)))) & 0xF;
      v3 = (signed __int16)((((signed int)(v41 | (((unsigned int)v38 & ((1 << (2 * (v39 + 2) & 0x1F))
                                                                      - ((2 * (v39 + 2) >> 5) & 1)
                                                                      - 1)) << (64 - 2 * (v39 + 2)))) >> 2) & 0xFFFC) << (16 - (v43 + 2))) >> (16 - (v43 + 2));
      v44 = v42 >> (v43 + 4);
      LOWORD(v44) = (signed __int16)(4 * (_WORD)v44 << (16 - (v43 + 2))) >> (16 - (v43 + 2));
      v62 = v44;
    }
    else
    {
      v31 = v84;
      v40 = v85;
    }
    v45 = v81;
    v46 = HIDWORD(v83);
    v47 = v83;
    v48 = v82;
    v49 = v92;
    v50 = v61;
    v60 = 3i64;
    do
    {
      v7 += v64;
      HIWORD(v51) = HIWORD(v63);
      LOWORD(v49) = v7 + v49;
      LOWORD(v46) = v49 + v46;
      LOWORD(v50) = v46 + v50;
      LOWORD(v47) = v50 + v47;
      LOWORD(v51) = v47 + v63;
      LOWORD(v48) = v47 + v63 + v48;
      v63 = v51;
      LOWORD(v31) = v48 + v31;
      v6 += v31;
      LOWORD(v45) = v6 + v45;
      v5 += v45;
      LOWORD(v40) = v5 + v40;
      v4 += v40;
      v3 += v4;
      LOWORD(v62) = v3 + v62;
      --v60;
    }
    while ( v60 );
    HIWORD(v52) = HIWORD(v64);
    LOWORD(v45) = (signed __int16)v45 >> 2;
    LOWORD(v47) = (signed __int16)v47 >> 2;
    LOWORD(v52) = (signed __int16)v64 >> 2;
    v75 = v45;
    v81 = v45;
    HIWORD(v53) = HIWORD(v62);
    v64 = v52;
    v65 = v52;
    HIWORD(v52) = HIWORD(v63);
    LOWORD(v53) = (signed __int16)v62 >> 2;
    LOWORD(v46) = (signed __int16)v46 >> 2;
    LOWORD(v52) = (signed __int16)v63 >> 2;
    LOWORD(v50) = (signed __int16)v50 >> 2;
    LOWORD(v49) = (signed __int16)v49 >> 2;
    LOWORD(v48) = (signed __int16)v48 >> 2;
    LOWORD(v31) = (signed __int16)v31 >> 2;
    LOWORD(v40) = (signed __int16)v40 >> 2;
    v70 = v47;
    v80 = (signed __int16)v62 >> 2;
    v63 = v52;
    v71 = v52;
    v7 >>= 2;
    v6 >>= 2;
    v5 >>= 2;
    v4 >>= 2;
    v3 >>= 2;
    v83 = __PAIR__(v46, v47);
    v68 = v46;
    v69 = v50;
    v62 = v53;
    v66 = v7;
    data = v86 + 1;
    v54 = v87-- == 1;
    v67 = v49;
    v72 = v48;
    v73 = v31;
    v74 = v6;
    v76 = v5;
    v77 = v40;
    v78 = v4;
    v79 = v3;
    *v91 = *v88;
    v61 = v50;
    v8 = v90;
    ++v91;
    v92 = v49;
    v82 = v48;
    v84 = v31;
    v85 = v40;
    v86 = data;
  }
  while ( !v54 );
  return v90;
}

// File Line: 897
// RVA: 0xBAC5F0
const char *__fastcall hkaPredictiveBlockCompression::ScalarDecoder::decodeAdjacentFrames(const char *data, int whichFrame, __int16 *out)
{
  __int16 v3; // di
  __int16 v4; // r13
  __int16 v5; // r12
  __int16 v6; // r15
  __int16 v7; // si
  const char *v8; // rbx
  unsigned int v9; // ecx
  unsigned int v10; // eax
  __int64 v11; // rcx
  __int64 v12; // rax
  const char *v13; // r14
  char v14; // al
  unsigned __int64 v15; // rdx
  signed int v16; // er10
  int v17; // edx
  int v18; // er8
  unsigned __int64 v19; // r11
  signed int v20; // ecx
  int v21; // edx
  signed int v22; // er10
  unsigned __int64 v23; // r10
  int v24; // edx
  unsigned __int64 v25; // rdx
  int v26; // er9
  int v27; // er9
  char v28; // cl
  int v29; // eax
  char v30; // r9
  signed int v31; // er14
  unsigned __int64 v32; // rdi
  unsigned __int64 v33; // r11
  int v34; // eax
  signed int v35; // er9
  char v36; // cl
  unsigned __int64 v37; // r10
  unsigned __int64 v38; // rdi
  int v39; // eax
  signed int v40; // er11
  unsigned __int64 v41; // r10
  int v42; // er9
  char v43; // dl
  int v44; // er9
  int v45; // ecx
  int v46; // edx
  int v47; // er8
  int v48; // er9
  signed int v49; // er10
  int v50; // ebx
  int v51; // eax
  signed int v52; // eax
  int v53; // ecx
  __int64 v54; // rcx
  bool v55; // zf
  unsigned __int64 v57; // [rsp+20h] [rbp-59h]
  unsigned __int64 v58; // [rsp+20h] [rbp-59h]
  unsigned __int64 v59; // [rsp+28h] [rbp-51h]
  unsigned __int64 v60; // [rsp+28h] [rbp-51h]
  signed __int64 v61; // [rsp+28h] [rbp-51h]
  int v62; // [rsp+30h] [rbp-49h]
  int v63; // [rsp+34h] [rbp-45h]
  int v64; // [rsp+38h] [rbp-41h]
  signed int v65; // [rsp+3Ch] [rbp-3Dh]
  unsigned __int16 v66; // [rsp+40h] [rbp-39h]
  __int16 v67; // [rsp+42h] [rbp-37h]
  unsigned __int16 v68; // [rsp+44h] [rbp-35h]
  unsigned __int16 v69; // [rsp+46h] [rbp-33h]
  unsigned __int16 v70; // [rsp+48h] [rbp-31h]
  unsigned __int16 v71; // [rsp+4Ah] [rbp-2Fh]
  unsigned __int16 v72; // [rsp+4Ch] [rbp-2Dh]
  unsigned __int16 v73; // [rsp+4Eh] [rbp-2Bh]
  unsigned __int16 v74; // [rsp+50h] [rbp-29h]
  __int16 v75; // [rsp+52h] [rbp-27h]
  unsigned __int16 v76; // [rsp+54h] [rbp-25h]
  __int16 v77; // [rsp+56h] [rbp-23h]
  unsigned __int16 v78; // [rsp+58h] [rbp-21h]
  __int16 v79; // [rsp+5Ah] [rbp-1Fh]
  __int16 v80; // [rsp+5Ch] [rbp-1Dh]
  unsigned __int16 v81; // [rsp+5Eh] [rbp-1Bh]
  int v82; // [rsp+60h] [rbp-19h]
  int v83; // [rsp+64h] [rbp-15h]
  int v84; // [rsp+68h] [rbp-11h]
  int v85; // [rsp+6Ch] [rbp-Dh]
  int v86; // [rsp+70h] [rbp-9h]
  int v87; // [rsp+74h] [rbp-5h]
  __int64 v88; // [rsp+78h] [rbp-1h]
  const char *v89; // [rsp+80h] [rbp+7h]
  __int16 *v90; // [rsp+88h] [rbp+Fh]
  __int16 *v91; // [rsp+90h] [rbp+17h]
  int v92; // [rsp+E0h] [rbp+67h]
  const char *v93; // [rsp+E0h] [rbp+67h]
  __int16 *v94; // [rsp+F0h] [rbp+77h]
  signed int v95; // [rsp+F8h] [rbp+7Fh]

  v94 = out;
  v3 = v80;
  v4 = v79;
  v5 = v77;
  v6 = v75;
  v7 = v67;
  v85 = v76;
  v64 = v72;
  v91 = &v67 + whichFrame;
  v63 = v81;
  v90 = (__int16 *)(&v66 + whichFrame);
  v87 = v78;
  v89 = data;
  v86 = v74;
  v8 = data + 16;
  v62 = v70;
  v88 = 16i64;
  v95 = v68;
  v83 = v73;
  v82 = v71;
  v84 = v69;
  v65 = v66;
  do
  {
    v9 = *(unsigned __int8 *)data;
    v10 = v9;
    v11 = (v9 & 0xF) + 1;
    v92 = v11;
    v12 = (signed int)((v10 >> 4) + 1);
    v13 = &v8[v12];
    LOBYTE(v59) = v8[v12 - 9];
    BYTE1(v59) = v8[v12 - 10];
    BYTE2(v59) = v8[v12 - 11];
    BYTE3(v59) = v8[v12 - 12];
    BYTE4(v59) = v8[v12 - 13];
    BYTE5(v59) = v8[v12 - 14];
    BYTE6(v59) = v8[v12 - 15];
    HIBYTE(v59) = v8[v12 - 16];
    LOBYTE(v57) = v8[v12 - 1];
    BYTE1(v57) = v8[v12 - 2];
    BYTE2(v57) = v8[v12 - 3];
    BYTE3(v57) = v8[v12 - 4];
    BYTE4(v57) = v8[v12 - 5];
    BYTE5(v57) = v8[v12 - 6];
    BYTE6(v57) = v8[v12 - 7];
    HIBYTE(v57) = v8[v12 - 8];
    v14 = HK_flyingcolors_animation_1.m_bool;
    if ( HK_flyingcolors_animation_1.m_bool
      || (hkaCheckKeycode(v11, 0i64),
          hkaProcessFlyingColors(&HK_flyingcolors_animation_1),
          (v14 = HK_flyingcolors_animation_1.m_bool) != 0) )
    {
      v16 = (signed int)v57 >> 2;
      v17 = v57 & 0xF;
      LOWORD(v16) = (signed __int16)((((signed int)v57 >> 2) & 0xFFFC) << (16 - (v17 + 2))) >> (16 - (v17 + 2));
      v65 = v16;
      v18 = 2 * (v17 + 2);
      v7 = (signed __int16)(4 * (unsigned __int16)((signed int)v57 >> (v17 + 4)) << (16 - (v17 + 2))) >> (16 - (v17 + 2));
      v19 = (v57 >> v18) | ((unsigned __int64)((unsigned int)v59 & ((1 << (v18 & 0x1F)) - ((v18 >> 5) & 1) - 1)) << (64 - (unsigned __int8)v18));
      v20 = (signed int)v19 >> 2;
      v21 = v19 & 0xF;
      LOWORD(v20) = ((signed int)v19 >> 2) & 0xFFFC;
      v95 = v20;
      LOWORD(v95) = (signed __int16)((_WORD)v20 << (16 - (v21 + 2))) >> (16 - (v21 + 2));
      v22 = (signed int)v19 >> (v21 + 4);
      LOWORD(v22) = (signed __int16)(4 * (_WORD)v22 << (16 - (v21 + 2))) >> (16 - (v21 + 2));
      v84 = v22;
      LOBYTE(v20) = 2 * (v21 + 2);
      v23 = (v19 >> v20) | (((v59 >> v18) & ((1 << (2 * (v21 + 2) & 0x1F)) - ((2 * (v21 + 2) >> 5) & 1u) - 1)) << (64 - 2 * ((unsigned __int8)v21 + 2)));
      v24 = ((unsigned __int8)(v19 >> v20) | (unsigned __int8)(((v59 >> v18) & ((1 << (2 * (v21 + 2) & 0x1F))
                                                                              - ((2 * (v21 + 2) >> 5) & 1u)
                                                                              - 1)) << (64
                                                                                      - 2 * ((unsigned __int8)v21 + 2)))) & 0xF;
      HIWORD(v62) = (unsigned int)((signed int)v23 >> 2) >> 16;
      LOWORD(v62) = (signed __int16)((((signed int)v23 >> 2) & 0xFFFC) << (16 - (v24 + 2))) >> (16 - (v24 + 2));
      LODWORD(v19) = (signed int)v23 >> (v24 + 4);
      LOWORD(v19) = (signed __int16)(4 * (_WORD)v19 << (16 - (v24 + 2))) >> (16 - (v24 + 2));
      v82 = v19;
      v25 = (v23 >> 2 * ((unsigned __int8)v24 + 2)) | ((unsigned __int64)((unsigned int)(v59 >> v18 >> v20) & ((1 << (2 * (v24 + 2) & 0x1F)) - ((2 * (v24 + 2) >> 5) & 1) - 1)) << (64 - 2 * ((unsigned __int8)v24 + 2)));
      v26 = v25;
      v15 = v25 & 0xF;
      LODWORD(v23) = v26 >> 2;
      LOWORD(v23) = (signed __int16)(((v26 >> 2) & 0xFFFC) << (16 - (v15 + 2))) >> (16 - (v15 + 2));
      v27 = v26 >> (v15 + 4);
      v64 = v23;
      LOWORD(v27) = (signed __int16)(4 * (_WORD)v27 << (16 - (v15 + 2))) >> (16 - (v15 + 2));
      v83 = v27;
    }
    v28 = v13[v92 - 9];
    v93 = &v13[v92];
    LOBYTE(v60) = v28;
    BYTE1(v60) = *(v93 - 10);
    BYTE2(v60) = *(v93 - 11);
    BYTE3(v60) = *(v93 - 12);
    BYTE4(v60) = *(v93 - 13);
    BYTE5(v60) = *(v93 - 14);
    BYTE6(v60) = *(v93 - 15);
    HIBYTE(v60) = *(v93 - 16);
    LOBYTE(v58) = *(v93 - 1);
    BYTE1(v58) = *(v93 - 2);
    BYTE2(v58) = *(v93 - 3);
    BYTE3(v58) = *(v93 - 4);
    BYTE4(v58) = *(v93 - 5);
    BYTE5(v58) = *(v93 - 6);
    BYTE6(v58) = *(v93 - 7);
    HIBYTE(v58) = *(v93 - 8);
    if ( v14
      || (hkaCheckKeycode(*((unsigned __int8 *)v93 - 8), v15),
          hkaProcessFlyingColors(&HK_flyingcolors_animation_1),
          HK_flyingcolors_animation_1.m_bool) )
    {
      v29 = v58 & 0xF;
      v31 = (signed int)v58 >> 2;
      v30 = 2 * (v29 + 2);
      LOWORD(v31) = (signed __int16)((((signed int)v58 >> 2) & 0xFFFC) << (16 - (v29 + 2))) >> (16 - (v29 + 2));
      v6 = (signed __int16)(4 * (unsigned __int16)((signed int)v58 >> (v29 + 4)) << (16 - (v29 + 2))) >> (16 - (v29 + 2));
      v32 = v60 >> v30;
      v33 = (v58 >> v30) | ((unsigned __int64)((unsigned int)v60 & ((1 << (2 * (v29 + 2) & 0x1F))
                                                                  - ((2 * (v29 + 2) >> 5) & 1)
                                                                  - 1)) << (64 - 2 * ((unsigned __int8)v29 + 2)));
      v34 = v33 & 0xF;
      v35 = (signed int)v33 >> 2;
      LOWORD(v35) = (signed __int16)((((signed int)v33 >> 2) & 0xFFFC) << (16 - (v34 + 2))) >> (16 - (v34 + 2));
      v85 = v35;
      v5 = (signed __int16)(4 * (unsigned __int16)((signed int)v33 >> (v34 + 4)) << (16 - (v34 + 2))) >> (16 - (v34 + 2));
      v36 = 2 * (v34 + 2);
      v37 = (v33 >> v36) | ((unsigned __int64)((unsigned int)v32 & ((1 << (2 * (v34 + 2) & 0x1F))
                                                                  - ((2 * (v34 + 2) >> 5) & 1)
                                                                  - 1)) << (64 - 2 * ((unsigned __int8)v34 + 2)));
      v38 = v32 >> v36;
      v39 = v37 & 0xF;
      v40 = (signed int)v37 >> 2;
      LOWORD(v40) = (signed __int16)((((signed int)v37 >> 2) & 0xFFFC) << (16 - (v39 + 2))) >> (16 - (v39 + 2));
      v4 = (signed __int16)(4 * (unsigned __int16)((signed int)v37 >> (v39 + 4)) << (16 - (v39 + 2))) >> (16 - (v39 + 2));
      v41 = v37 >> 2 * ((unsigned __int8)v39 + 2);
      v42 = v41 | (((unsigned int)v38 & ((1 << (2 * (v39 + 2) & 0x1F)) - ((2 * (v39 + 2) >> 5) & 1) - 1)) << (64 - 2 * (v39 + 2)));
      v43 = (v41 | ((unsigned __int64)((unsigned int)v38 & ((1 << (2 * (v39 + 2) & 0x1F))
                                                          - ((2 * (v39 + 2) >> 5) & 1)
                                                          - 1)) << (64 - 2 * ((unsigned __int8)v39 + 2)))) & 0xF;
      v3 = (signed __int16)((((signed int)(v41 | (((unsigned int)v38 & ((1 << (2 * (v39 + 2) & 0x1F))
                                                                      - ((2 * (v39 + 2) >> 5) & 1)
                                                                      - 1)) << (64 - 2 * (v39 + 2)))) >> 2) & 0xFFFC) << (16 - (v43 + 2))) >> (16 - (v43 + 2));
      v44 = v42 >> (v43 + 4);
      LOWORD(v44) = (signed __int16)(4 * (_WORD)v44 << (16 - (v43 + 2))) >> (16 - (v43 + 2));
      v63 = v44;
    }
    else
    {
      v31 = v86;
      v40 = v87;
    }
    v45 = v85;
    v46 = v84;
    v47 = v82;
    v48 = v83;
    v49 = v95;
    v50 = v62;
    v61 = 3i64;
    do
    {
      v7 += v65;
      HIWORD(v51) = HIWORD(v64);
      LOWORD(v49) = v7 + v49;
      LOWORD(v46) = v49 + v46;
      LOWORD(v50) = v46 + v50;
      LOWORD(v47) = v50 + v47;
      LOWORD(v51) = v47 + v64;
      LOWORD(v48) = v47 + v64 + v48;
      v64 = v51;
      LOWORD(v31) = v48 + v31;
      v6 += v31;
      LOWORD(v45) = v6 + v45;
      v5 += v45;
      LOWORD(v40) = v5 + v40;
      v4 += v40;
      v3 += v4;
      LOWORD(v63) = v3 + v63;
      --v61;
    }
    while ( v61 );
    HIWORD(v52) = HIWORD(v65);
    LOWORD(v45) = (signed __int16)v45 >> 2;
    LOWORD(v46) = (signed __int16)v46 >> 2;
    LOWORD(v52) = (signed __int16)v65 >> 2;
    v76 = v45;
    LOWORD(v47) = (signed __int16)v47 >> 2;
    v65 = v52;
    v66 = v52;
    HIWORD(v52) = HIWORD(v64);
    LOWORD(v52) = (signed __int16)v64 >> 2;
    v85 = v45;
    HIWORD(v53) = HIWORD(v63);
    LOWORD(v53) = (signed __int16)v63 >> 2;
    v69 = v46;
    LOWORD(v50) = (signed __int16)v50 >> 2;
    v71 = v47;
    v81 = (signed __int16)v63 >> 2;
    LOWORD(v49) = (signed __int16)v49 >> 2;
    LOWORD(v48) = (signed __int16)v48 >> 2;
    LOWORD(v31) = (signed __int16)v31 >> 2;
    LOWORD(v40) = (signed __int16)v40 >> 2;
    v64 = v52;
    v72 = v52;
    v70 = v50;
    v84 = v46;
    v7 >>= 2;
    v6 >>= 2;
    v5 >>= 2;
    v4 >>= 2;
    v3 >>= 2;
    v82 = v47;
    v67 = v7;
    v68 = v49;
    v73 = v48;
    v74 = v31;
    v75 = v6;
    v77 = v5;
    v78 = v40;
    v79 = v4;
    v80 = v3;
    v63 = v53;
    v54 = (__int64)v89;
    *v94 = *v90;
    LOWORD(v52) = *v91;
    data = (const char *)(v54 + 1);
    v55 = v88-- == 1;
    v94[16] = v52;
    v62 = v50;
    v8 = v93;
    ++v94;
    v95 = v49;
    v83 = v48;
    v86 = v31;
    v87 = v40;
    v89 = data;
  }
  while ( !v55 );
  return v93;
}95 = v49;
    v83 = v48;
    v86 = v31;
    v87 = v40;
    v89 = data;
  }
  while ( !v55 );
  return v93;
}

