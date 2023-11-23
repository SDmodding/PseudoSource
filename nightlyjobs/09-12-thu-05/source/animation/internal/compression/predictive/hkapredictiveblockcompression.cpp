// File Line: 113
// RVA: 0xBABE70
// attributes: thunk
const char *__fastcall hkaPredictiveBlockCompression::decodeSingleFrame(
        const char *data,
        int whichFrame,
        __int16 *frameData)
{
  return hkaPredictiveBlockCompression::ScalarDecoder::decodeSingleFrame(data, whichFrame, frameData);
}

// File Line: 117
// RVA: 0xBABE80
// attributes: thunk
const char *__fastcall hkaPredictiveBlockCompression::decodeAdjacentFrames(
        const char *data,
        int whichFrame,
        __int16 *frameData)
{
  return hkaPredictiveBlockCompression::ScalarDecoder::decodeAdjacentFrames(data, whichFrame, frameData);
}

// File Line: 121
// RVA: 0xBABE60
// attributes: thunk
const char *__fastcall hkaPredictiveBlockCompression::decodeWholeBlock(
        const char *data,
        hkaPredictiveBlockCompression::Block *block)
{
  return hkaPredictiveBlockCompression::ScalarDecoder::decodeWholeBlock(data, block);
}

// File Line: 126
// RVA: 0xBABE50
// attributes: thunk
char *__fastcall hkaPredictiveBlockCompression::encodeBlock(
        hkaPredictiveBlockCompression::Block *data,
        int nframes,
        int nchannels,
        char *out)
{
  return hkaPredictiveBlockCompression::ScalarEncoder::encodeBlock(data, nframes, nchannels, out);
}

// File Line: 134
// RVA: 0xBAD710
__int16 __fastcall hkaPredictiveBlockCompression::signExtend(__int16 val, char width)
{
  return (__int16)(val << (16 - width)) >> (16 - width);
}

// File Line: 145
// RVA: 0xBAD730
bool __fastcall hkaPredictiveBlockCompression::ScalarEncoder::fitsIn(int value, int bitlen)
{
  if ( bitlen )
    return (unsigned int)((value >> (bitlen - 1)) + 1) <= 1;
  else
    return value == 0;
}

// File Line: 159
// RVA: 0xBAD760
void __fastcall hkaPredictiveBlockCompression::ScalarEncoder::writeBits(char *data, int *pos, int value, int nbits)
{
  int v5; // r11d
  int v6; // kr00_4
  int v7; // ebx
  int v8; // edx
  int v9; // eax
  int v10; // eax
  __int64 v11; // r8

  v5 = value;
  v6 = *pos;
  v7 = nbits;
  v8 = (*pos >> 31) & 7;
  v9 = ((v8 + v6) & 7) - v8;
  if ( v9 )
  {
    if ( 8 - v9 < nbits )
      nbits = 8 - v9;
    v7 -= nbits;
    data[(v8 + v6) >> 3] |= ((unsigned __int8)value & (unsigned __int8)((1 << (nbits & 0x1F)) - ((nbits >> 5) & 1) - 1)) << v9;
    v5 = value >> nbits;
    *pos += nbits;
  }
  v10 = (int)((((v7 >> 31) & 7) + v7) & 0xFFFFFFF8) / 8;
  if ( v10 > 0 )
  {
    v11 = (unsigned int)v10;
    v7 -= 8 * v10;
    do
    {
      data[*pos / 8] = v5;
      *pos += 8;
      v5 >>= 8;
      --v11;
    }
    while ( v11 );
  }
  if ( v7 > 0 )
  {
    data[*pos / 8] = v5 & ((1 << (v7 & 0x1F)) - ((v7 >> 5) & 1) - 1);
    *pos += v7;
  }
}

// File Line: 191
// RVA: 0xBAD880
__int64 __fastcall hkaPredictiveBlockCompression::ScalarEncoder::encodeSegment(__int16 *data, int nitems, char **out)
{
  int v3; // ebp
  __int64 v6; // r14
  __int64 v7; // r15
  int v8; // r9d
  int i; // ebx
  int v10; // edx
  __int64 result; // rax
  __int64 v12; // r9
  char *v13; // r8
  char v14; // cl
  char v15; // [rsp+1Fh] [rbp-29h] BYREF
  char dataa; // [rsp+20h] [rbp-28h] BYREF
  __int64 v17; // [rsp+21h] [rbp-27h]
  int v18; // [rsp+29h] [rbp-1Fh]
  __int16 v19; // [rsp+2Dh] [rbp-1Bh]
  char v20; // [rsp+2Fh] [rbp-19h]
  int pos; // [rsp+58h] [rbp+10h] BYREF

  v17 = 0i64;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v3 = 0;
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
      v8 = data[v6];
      for ( i = 0;
            !hkaPredictiveBlockCompression::ScalarEncoder::fitsIn(v8, i)
         || !hkaPredictiveBlockCompression::ScalarEncoder::fitsIn(data[v6 + 1], v10);
            ++i )
      {
        ;
      }
      hkaPredictiveBlockCompression::ScalarEncoder::writeBits(&dataa, &pos, i, 4);
      hkaPredictiveBlockCompression::ScalarEncoder::writeBits(&dataa, &pos, data[v6], i);
      hkaPredictiveBlockCompression::ScalarEncoder::writeBits(&dataa, &pos, data[v6 + 1], i);
      v6 += 2i64;
    }
    while ( v6 < v7 );
    v3 = pos;
  }
  result = (unsigned int)((v3 + 7) / 8);
  v12 = (int)result;
  if ( (int)result > 0 )
  {
    v13 = &v15 + (int)result;
    do
    {
      v14 = *v13--;
      *(*out)++ = v14;
      --v12;
    }
    while ( v12 );
  }
  return result;
}

// File Line: 237
// RVA: 0xBAD9E0
void __fastcall hkaPredictiveBlockCompression::ScalarEncoder::encodeTrackBlock(
        __int16 *data,
        int nitems,
        char **out,
        char *sizebyte)
{
  char v8; // bl
  char v9; // al

  if ( nitems <= 8 )
  {
    v8 = hkaPredictiveBlockCompression::ScalarEncoder::encodeSegment(data, nitems, out);
    *(*out)++ = 0;
    v9 = 1;
  }
  else
  {
    v8 = hkaPredictiveBlockCompression::ScalarEncoder::encodeSegment(data, 8, out);
    v9 = hkaPredictiveBlockCompression::ScalarEncoder::encodeSegment(data + 8, nitems - 8, out);
  }
  *sizebyte = (v9 - 1) | (16 * (v8 - 1));
}

// File Line: 259
// RVA: 0xBAD400
char *__fastcall hkaPredictiveBlockCompression::ScalarEncoder::encodeBlock(
        hkaPredictiveBlockCompression::Block *data,
        int nframes,
        unsigned int nchannels,
        char *out)
{
  char *v4; // r10
  __int64 v7; // r12
  __int64 v9; // r9
  __int64 v10; // rax
  __int128 v11; // xmm0
  __int128 v12; // xmm1
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  __int128 v15; // xmm0
  __int128 v16; // xmm1
  __int128 v17; // xmm0
  __int128 v18; // xmm1
  int v19; // r14d
  __int64 v20; // rdi
  char *v21; // r10
  __int64 i; // rax
  __int64 v23; // r11
  __int16 *v24; // rax
  __int16 v25; // cx
  __int16 v26; // dx
  __int16 v27; // r8
  __int16 v28; // cx
  __int16 v29; // r8
  __int16 v30; // cx
  __int64 j; // rax
  char *v32; // rbp
  char *v33; // rsi
  char *v34; // rbx
  __int16 *v35; // rdi
  __int64 v36; // rsi
  __int64 v37; // rax
  int v38; // r15d
  hkOstream *v39; // rax
  hkOstream *v40; // rax
  hkOstream *v41; // rax
  hkOstream *v42; // rax
  hkOstream *v43; // rax
  hkOstream *v44; // rax
  hkErrStream v46; // [rsp+20h] [rbp-248h] BYREF
  char Dst[512]; // [rsp+40h] [rbp-228h] BYREF
  char *outa; // [rsp+288h] [rbp+20h] BYREF

  v4 = Dst;
  v7 = nchannels;
  v9 = (__int64)Dst;
  if ( (((unsigned __int8)Dst | (unsigned __int8)data) & 0xF) != 0 )
  {
    memmove(Dst, data, 0x200ui64);
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
  v20 = (int)v7;
  if ( (int)v7 > 0 )
  {
    v21 = Dst;
    do
    {
      for ( i = 0i64; i < 16; ++i )
        *(_WORD *)&v21[2 * i] *= 4;
      v23 = 3i64;
      do
      {
        v24 = (__int16 *)(v21 + 26);
        v9 = 3i64;
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
      for ( j = 0i64; j < 16; ++j )
        *(__int16 *)&v21[2 * j] >>= 2;
      v21 += 32;
      --v20;
    }
    while ( v20 );
  }
  v32 = out;
  v33 = out + 16;
  outa = v33;
  if ( (int)v7 > 0 )
  {
    v34 = v32;
    v35 = (__int16 *)Dst;
    v36 = v7;
    v19 = v7;
    do
    {
      hkaPredictiveBlockCompression::ScalarEncoder::encodeTrackBlock(v35, nframes, &outa, v34++);
      v35 += 16;
      --v36;
    }
    while ( v36 );
    v33 = outa;
  }
  v37 = v19;
  if ( v19 < 16i64 )
  {
    do
    {
      v32[v37++] = 0;
      *(_WORD *)v33 = 0;
      v33 += 2;
    }
    while ( v37 < 16 );
  }
  ((void (__fastcall *)(hkError *, __int64, const char *, __int64))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    2553462578i64,
    "Predictive Block Compression",
    v9);
  hkErrStream::hkErrStream(&v46, Dst, 512);
  v38 = v7 * nframes;
  v39 = hkOstream::operator<<(&v46, "Block (");
  v40 = hkOstream::operator<<(v39, v38);
  v41 = hkOstream::operator<<(v40, " samples) compressed to ");
  v42 = hkOstream::operator<<(v41, (int)v33 - (int)out);
  v43 = hkOstream::operator<<(v42, " bytes (");
  v44 = hkOstream::operator<<(v43, 100 * (v33 - out) / (2 * v38));
  hkOstream::operator<<(v44, "% of original");
  hkError::messageReport(-1, Dst, "Compression\\Predictive\\hkaPredictiveBlockCompression.cpp", 309);
  hkOstream::~hkOstream(&v46);
  ((void (__fastcall *)(hkError *))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)(hkSingleton<hkError>::s_instance);
  return v33;
}

// File Line: 774
// RVA: 0xBADA70
void __fastcall hkaPredictiveBlockCompression::ScalarDecoder::copyBigEndianToUint64(
        unsigned __int64 *dest64,
        const char *sourceBigEndian)
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
  int v3; // edx
  char v4; // cl
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // rbx
  int v7; // edx
  char v8; // cl
  unsigned __int64 v9; // r11
  int v10; // edx
  unsigned __int64 v11; // [rsp+50h] [rbp+18h]
  unsigned __int64 v12; // [rsp+50h] [rbp+18h]
  unsigned __int64 v13; // [rsp+60h] [rbp+28h]

  LOBYTE(v13) = *(coded - 9);
  BYTE1(v13) = *(coded - 10);
  BYTE2(v13) = *(coded - 11);
  BYTE3(v13) = *(coded - 12);
  BYTE4(v13) = *(coded - 13);
  BYTE5(v13) = *(coded - 14);
  BYTE6(v13) = *(coded - 15);
  HIBYTE(v13) = *(coded - 16);
  LOBYTE(v11) = *(coded - 1);
  BYTE1(v11) = *(coded - 2);
  BYTE2(v11) = *(coded - 3);
  BYTE3(v11) = *(coded - 4);
  BYTE4(v11) = *(coded - 5);
  BYTE5(v11) = *(coded - 6);
  BYTE6(v11) = *(coded - 7);
  HIBYTE(v11) = *(coded - 8);
  if ( HK_flyingcolors_animation_1.m_bool
    || (hkaCheckKeycode(coded, decoded),
        hkaProcessFlyingColors(&HK_flyingcolors_animation_1),
        HK_flyingcolors_animation_1.m_bool) )
  {
    v3 = v11 & 0xF;
    *decoded = (__int16)((((int)v11 >> 2) & 0xFFFC) << (16 - (v3 + 2))) >> (16 - (v3 + 2));
    decoded[1] = (__int16)((4 * (unsigned __int16)((int)v11 >> (v3 + 4))) << (16 - (v3 + 2))) >> (16 - (v3 + 2));
    v4 = 2 * (v3 + 2);
    v5 = v13 >> v4;
    v6 = (v11 >> v4) | ((unsigned __int64)((unsigned int)v13 & ((1 << (v4 & 0x1F)) - (((2 * (v3 + 2)) >> 5) & 1) - 1)) << (64 - v4));
    v7 = v6 & 0xF;
    decoded[2] = (__int16)((((int)v6 >> 2) & 0xFFFC) << (16 - (v7 + 2))) >> (16 - (v7 + 2));
    decoded[3] = (__int16)((4 * (unsigned __int16)((int)v6 >> (v7 + 4))) << (16 - (v7 + 2))) >> (16 - (v7 + 2));
    v8 = 2 * (v7 + 2);
    v9 = (v6 >> v8) | ((unsigned __int64)((unsigned int)v5 & ((1 << (v8 & 0x1F)) - (((2 * (v7 + 2)) >> 5) & 1) - 1)) << (64 - v8));
    v10 = v9 & 0xF;
    decoded[4] = (__int16)((((int)v9 >> 2) & 0xFFFC) << (16 - (v10 + 2))) >> (16 - (v10 + 2));
    decoded[5] = (__int16)((4 * (unsigned __int16)((int)v9 >> (v10 + 4))) << (16 - (v10 + 2))) >> (16 - (v10 + 2));
    v12 = (v9 >> (2 * ((unsigned __int8)v10 + 2))) | (((v5 >> v8) & ((1 << ((2 * (v10 + 2)) & 0x1F))
                                                                   - (((2 * (v10 + 2)) >> 5) & 1u)
                                                                   - 1)) << (64 - 2 * ((unsigned __int8)v10 + 2)));
    decoded[6] = (__int16)((((int)v12 >> 2) & 0xFFFC) << (16 - ((v12 & 0xF) + 2))) >> (16 - ((v12 & 0xF) + 2));
    decoded[7] = (__int16)((4
                          * (unsigned __int16)((int)((v9 >> (2 * ((unsigned __int8)v10 + 2))) | (((v5 >> v8) & ((1 << ((2 * (v10 + 2)) & 0x1F)) - (((2 * (v10 + 2)) >> 5) & 1u) - 1)) << (64 - 2 * ((unsigned __int8)v10 + 2)))) >> ((v12 & 0xF) + 4))) << (16 - ((v12 & 0xF) + 2))) >> (16 - ((v12 & 0xF) + 2));
  }
}

// File Line: 838
// RVA: 0xBADD80
void __fastcall hkaPredictiveBlockCompression::ScalarDecoder::deltaDecode(__int16 *data)
{
  __int64 v1; // rdx

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
const char *__fastcall hkaPredictiveBlockCompression::ScalarDecoder::decodeWholeBlock(
        __int64 data,
        hkaPredictiveBlockCompression::Block *block)
{
  const char *v2; // r12
  const char *v3; // r14
  __int16 *v4; // rbx
  __int64 v5; // r13
  unsigned int v6; // eax
  int v7; // r15d
  const char *v8; // r14
  __int64 v9; // rdx
  char m_bool; // al
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
  int v21; // r9d
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
  int v32; // r9d
  unsigned __int64 v34; // [rsp+60h] [rbp+40h]
  unsigned __int64 v35; // [rsp+60h] [rbp+40h]
  unsigned __int64 v36; // [rsp+70h] [rbp+50h]
  unsigned __int64 v37; // [rsp+70h] [rbp+50h]

  v2 = (const char *)data;
  v3 = (const char *)(data + 16);
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
          (m_bool = HK_flyingcolors_animation_1.m_bool) != 0) )
    {
      v11 = v34 & 0xF;
      *(v4 - 10) = (__int16)((((int)v34 >> 2) & 0xFFFC) << (16 - (v11 + 2))) >> (16 - (v11 + 2));
      *(v4 - 9) = (__int16)((4 * (unsigned __int16)((int)v34 >> (v11 + 4))) << (16 - (v11 + 2))) >> (16 - (v11 + 2));
      v12 = 2 * (v11 + 2);
      v13 = v36 >> v12;
      v14 = (v34 >> v12) | ((unsigned __int64)((unsigned int)v36 & ((1 << (v12 & 0x1F))
                                                                  - (((2 * (v11 + 2)) >> 5) & 1)
                                                                  - 1)) << (64 - v12));
      v15 = v14 & 0xF;
      *(v4 - 8) = (__int16)((((int)v14 >> 2) & 0xFFFC) << (16 - (v15 + 2))) >> (16 - (v15 + 2));
      *(v4 - 7) = (__int16)((4 * (unsigned __int16)((int)v14 >> (v15 + 4))) << (16 - (v15 + 2))) >> (16 - (v15 + 2));
      v16 = 2 * (v15 + 2);
      v17 = (v14 >> v16) | ((unsigned __int64)((unsigned int)v13 & ((1 << (v16 & 0x1F))
                                                                  - (((2 * (v15 + 2)) >> 5) & 1)
                                                                  - 1)) << (64 - v16));
      v18 = v13 >> v16;
      v19 = v17 & 0xF;
      *(v4 - 6) = (__int16)((((int)v17 >> 2) & 0xFFFC) << (16 - (v19 + 2))) >> (16 - (v19 + 2));
      *(v4 - 5) = (__int16)((4 * (unsigned __int16)((int)v17 >> (v19 + 4))) << (16 - (v19 + 2))) >> (16 - (v19 + 2));
      v20 = v17 >> (2 * ((unsigned __int8)v19 + 2));
      v21 = v20 | (((unsigned int)v18 & ((1 << ((2 * (v19 + 2)) & 0x1F)) - (((2 * (v19 + 2)) >> 5) & 1) - 1)) << (64 - 2 * (v19 + 2)));
      v9 = ((unsigned __int8)v20 | (unsigned __int8)((unsigned __int64)((unsigned int)v18 & ((1 << ((2 * (v19 + 2)) & 0x1F))
                                                                                           - (((2 * (v19 + 2)) >> 5) & 1)
                                                                                           - 1)) << (64 - 2 * ((unsigned __int8)v19 + 2)))) & 0xF;
      *(v4 - 4) = (__int16)(((v21 >> 2) & 0xFFFC) << (16 - (v9 + 2))) >> (16 - (v9 + 2));
      *(v4 - 3) = (__int16)((4 * (unsigned __int16)(v21 >> (v9 + 4))) << (16 - (v9 + 2))) >> (16 - (v9 + 2));
      m_bool = HK_flyingcolors_animation_1.m_bool;
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
    if ( m_bool
      || (hkaCheckKeycode(*((unsigned __int8 *)v3 - 8), v9),
          hkaProcessFlyingColors(&HK_flyingcolors_animation_1),
          HK_flyingcolors_animation_1.m_bool) )
    {
      v22 = v35 & 0xF;
      *(v4 - 2) = (__int16)((((int)v35 >> 2) & 0xFFFC) << (16 - (v22 + 2))) >> (16 - (v22 + 2));
      *(v4 - 1) = (__int16)((4 * (unsigned __int16)((int)v35 >> (v22 + 4))) << (16 - (v22 + 2))) >> (16 - (v22 + 2));
      v23 = 2 * (v22 + 2);
      v24 = v37 >> v23;
      v25 = (v35 >> v23) | ((unsigned __int64)((unsigned int)v37 & ((1 << (v23 & 0x1F))
                                                                  - (((2 * (v22 + 2)) >> 5) & 1)
                                                                  - 1)) << (64 - v23));
      v26 = v25 & 0xF;
      *v4 = (__int16)((((int)v25 >> 2) & 0xFFFC) << (16 - (v26 + 2))) >> (16 - (v26 + 2));
      v4[1] = (__int16)((4 * (unsigned __int16)((int)v25 >> (v26 + 4))) << (16 - (v26 + 2))) >> (16 - (v26 + 2));
      v27 = 2 * (v26 + 2);
      v28 = (v25 >> v27) | ((unsigned __int64)((unsigned int)v24 & ((1 << (v27 & 0x1F))
                                                                  - (((2 * (v26 + 2)) >> 5) & 1)
                                                                  - 1)) << (64 - v27));
      v29 = v24 >> v27;
      v30 = v28 & 0xF;
      v4[2] = (__int16)((((int)v28 >> 2) & 0xFFFC) << (16 - (v30 + 2))) >> (16 - (v30 + 2));
      v4[3] = (__int16)((4 * (unsigned __int16)((int)v28 >> (v30 + 4))) << (16 - (v30 + 2))) >> (16 - (v30 + 2));
      v31 = v28 >> (2 * ((unsigned __int8)v30 + 2));
      v32 = v31 | (((unsigned int)v29 & ((1 << ((2 * (v30 + 2)) & 0x1F)) - (((2 * (v30 + 2)) >> 5) & 1) - 1)) << (64 - 2 * (v30 + 2)));
      block = (hkaPredictiveBlockCompression::Block *)(((unsigned __int8)v31 | (unsigned __int8)((unsigned __int64)((unsigned int)v29 & ((1 << ((2 * (v30 + 2)) & 0x1F)) - (((2 * (v30 + 2)) >> 5) & 1) - 1)) << (64 - 2 * ((unsigned __int8)v30 + 2)))) & 0xF);
      v4[4] = (__int16)(((v32 >> 2) & 0xFFFC) << (16 - ((_BYTE)block + 2))) >> (16 - ((_BYTE)block + 2));
      v4[5] = (__int16)((4 * (unsigned __int16)(v32 >> ((_BYTE)block + 4))) << (16 - ((_BYTE)block + 2))) >> (16 - ((_BYTE)block + 2));
    }
    data = 3i64;
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

// File Line: 879
// RVA: 0xBABE90
const char *__fastcall hkaPredictiveBlockCompression::ScalarDecoder::decodeSingleFrame(
        const char *data,
        int whichFrame,
        __int16 *out)
{
  __int16 v3; // di
  __int16 v4; // r13
  __int16 v5; // r12
  __int16 v6; // r15
  __int16 v7; // si
  const char *v8; // rbx
  unsigned int v9; // eax
  __int64 v10; // rcx
  const char *v11; // r14
  char m_bool; // al
  __int64 v13; // rdx
  int v14; // r10d
  int v15; // edx
  int v16; // r8d
  unsigned __int64 v17; // r11
  int v18; // edx
  int v19; // r10d
  char v20; // cl
  unsigned __int64 v21; // r10
  int v22; // edx
  int v23; // r9d
  int v24; // r9d
  int v25; // eax
  char v26; // r9
  int v27; // r14d
  unsigned __int64 v28; // rdi
  unsigned __int64 v29; // r11
  int v30; // eax
  int v31; // r9d
  char v32; // cl
  unsigned __int64 v33; // r10
  unsigned __int64 v34; // rdi
  int v35; // eax
  int v36; // r11d
  unsigned __int64 v37; // r10
  int v38; // r9d
  char v39; // dl
  int v40; // r9d
  int v41; // ecx
  int v42; // edx
  int v43; // r8d
  int v44; // r9d
  int v45; // r10d
  int v46; // ebx
  int v47; // eax
  int v48; // eax
  int v49; // ecx
  bool v50; // zf
  unsigned __int64 v52; // [rsp+20h] [rbp-49h]
  unsigned __int64 v53; // [rsp+20h] [rbp-49h]
  unsigned __int64 v54; // [rsp+28h] [rbp-41h]
  unsigned __int64 v55; // [rsp+28h] [rbp-41h]
  __int64 v56; // [rsp+28h] [rbp-41h]
  int v57; // [rsp+30h] [rbp-39h]
  int v58; // [rsp+34h] [rbp-35h]
  int v59; // [rsp+38h] [rbp-31h]
  int v60; // [rsp+3Ch] [rbp-2Dh]
  unsigned __int16 v61; // [rsp+40h] [rbp-29h] BYREF
  __int16 v62; // [rsp+42h] [rbp-27h]
  unsigned __int16 v63; // [rsp+44h] [rbp-25h]
  unsigned __int16 v64; // [rsp+46h] [rbp-23h]
  unsigned __int16 v65; // [rsp+48h] [rbp-21h]
  unsigned __int16 v66; // [rsp+4Ah] [rbp-1Fh]
  unsigned __int16 v67; // [rsp+4Ch] [rbp-1Dh]
  unsigned __int16 v68; // [rsp+4Eh] [rbp-1Bh]
  unsigned __int16 v69; // [rsp+50h] [rbp-19h]
  __int16 v70; // [rsp+52h] [rbp-17h]
  unsigned __int16 v71; // [rsp+54h] [rbp-15h]
  __int16 v72; // [rsp+56h] [rbp-13h]
  unsigned __int16 v73; // [rsp+58h] [rbp-11h]
  __int16 v74; // [rsp+5Ah] [rbp-Fh]
  __int16 v75; // [rsp+5Ch] [rbp-Dh]
  unsigned __int16 v76; // [rsp+5Eh] [rbp-Bh]
  int v77; // [rsp+60h] [rbp-9h]
  int v78; // [rsp+64h] [rbp-5h]
  int v79; // [rsp+68h] [rbp-1h]
  int v80; // [rsp+6Ch] [rbp+3h]
  int v81; // [rsp+70h] [rbp+7h]
  int v82; // [rsp+74h] [rbp+Bh]
  const char *v83; // [rsp+78h] [rbp+Fh]
  __int64 v84; // [rsp+80h] [rbp+17h]
  __int16 *v85; // [rsp+88h] [rbp+1Fh]
  int v86; // [rsp+D0h] [rbp+67h]
  const char *v87; // [rsp+D0h] [rbp+67h]
  int v89; // [rsp+E8h] [rbp+7Fh]

  v3 = v75;
  v4 = v74;
  v5 = v72;
  v6 = v70;
  v7 = v62;
  v77 = v71;
  v85 = (__int16 *)(&v61 + whichFrame);
  v59 = v67;
  v58 = v76;
  v82 = v73;
  v83 = data;
  v81 = v69;
  v8 = data + 16;
  v57 = v65;
  v84 = 16i64;
  v89 = v63;
  v78 = v68;
  v79 = v66;
  v80 = v64;
  v60 = v61;
  do
  {
    v9 = *(unsigned __int8 *)data;
    v10 = (v9 & 0xF) + 1;
    v86 = (v9 & 0xF) + 1;
    v11 = &v8[(v9 >> 4) + 1];
    LOBYTE(v54) = *(v11 - 9);
    BYTE1(v54) = *(v11 - 10);
    BYTE2(v54) = *(v11 - 11);
    BYTE3(v54) = *(v11 - 12);
    BYTE4(v54) = *(v11 - 13);
    BYTE5(v54) = *(v11 - 14);
    BYTE6(v54) = *(v11 - 15);
    HIBYTE(v54) = *(v11 - 16);
    LOBYTE(v52) = *(v11 - 1);
    BYTE1(v52) = *(v11 - 2);
    BYTE2(v52) = *(v11 - 3);
    BYTE3(v52) = *(v11 - 4);
    BYTE4(v52) = *(v11 - 5);
    BYTE5(v52) = *(v11 - 6);
    BYTE6(v52) = *(v11 - 7);
    HIBYTE(v52) = *(v11 - 8);
    m_bool = HK_flyingcolors_animation_1.m_bool;
    if ( HK_flyingcolors_animation_1.m_bool
      || (hkaCheckKeycode(v10, 0i64),
          hkaProcessFlyingColors(&HK_flyingcolors_animation_1),
          (m_bool = HK_flyingcolors_animation_1.m_bool) != 0) )
    {
      v14 = (int)v52 >> 2;
      v15 = v52 & 0xF;
      LOWORD(v14) = (__int16)((((int)v52 >> 2) & 0xFFFC) << (16 - (v15 + 2))) >> (16 - (v15 + 2));
      v60 = v14;
      v16 = 2 * (v15 + 2);
      v7 = (__int16)((4 * (unsigned __int16)((int)v52 >> (v15 + 4))) << (16 - (v15 + 2))) >> (16 - (v15 + 2));
      v17 = (v52 >> v16) | ((unsigned __int64)((unsigned int)v54 & ((1 << (v16 & 0x1F)) - ((v16 >> 5) & 1) - 1)) << (64 - (unsigned __int8)v16));
      v18 = v17 & 0xF;
      HIWORD(v89) = (unsigned int)((int)v17 >> 2) >> 16;
      LOWORD(v89) = (__int16)((((int)v17 >> 2) & 0xFFFC) << (16 - (v18 + 2))) >> (16 - (v18 + 2));
      v19 = (int)v17 >> (v18 + 4);
      LOWORD(v19) = (__int16)((4 * (_WORD)v19) << (16 - (v18 + 2))) >> (16 - (v18 + 2));
      v80 = v19;
      v20 = 2 * (v18 + 2);
      v21 = (v17 >> v20) | (((v54 >> v16) & ((1 << (v20 & 0x1F)) - (((2 * (v18 + 2)) >> 5) & 1u) - 1)) << (64 - v20));
      v22 = ((unsigned __int8)(v17 >> v20) | (unsigned __int8)(((v54 >> v16) & ((1 << (v20 & 0x1F))
                                                                              - (((2 * (v18 + 2)) >> 5) & 1u)
                                                                              - 1)) << (64 - v20))) & 0xF;
      HIWORD(v57) = (unsigned int)((int)v21 >> 2) >> 16;
      LOWORD(v57) = (__int16)((((int)v21 >> 2) & 0xFFFC) << (16 - (v22 + 2))) >> (16 - (v22 + 2));
      LODWORD(v17) = (int)v21 >> (v22 + 4);
      LOWORD(v17) = (__int16)((4 * (_WORD)v17) << (16 - (v22 + 2))) >> (16 - (v22 + 2));
      v79 = v17;
      v23 = (v21 >> (2 * ((unsigned __int8)v22 + 2))) | (((unsigned int)(v54 >> v16 >> v20) & ((1 << ((2 * (v22 + 2)) & 0x1F))
                                                                                             - (((2 * (v22 + 2)) >> 5) & 1)
                                                                                             - 1)) << (64 - 2 * (v22 + 2)));
      v13 = v23 & 0xF;
      LODWORD(v21) = v23 >> 2;
      LOWORD(v21) = (__int16)(((v23 >> 2) & 0xFFFC) << (16 - ((v23 & 0xF) + 2))) >> (16 - ((v23 & 0xF) + 2));
      v24 = v23 >> ((v23 & 0xF) + 4);
      v59 = v21;
      LOWORD(v24) = (__int16)((4 * (_WORD)v24) << (16 - (v13 + 2))) >> (16 - (v13 + 2));
      v78 = v24;
    }
    v87 = &v11[v86];
    LOBYTE(v55) = *(v87 - 9);
    BYTE1(v55) = *(v87 - 10);
    BYTE2(v55) = *(v87 - 11);
    BYTE3(v55) = *(v87 - 12);
    BYTE4(v55) = *(v87 - 13);
    BYTE5(v55) = *(v87 - 14);
    BYTE6(v55) = *(v87 - 15);
    HIBYTE(v55) = *(v87 - 16);
    LOBYTE(v53) = *(v87 - 1);
    BYTE1(v53) = *(v87 - 2);
    BYTE2(v53) = *(v87 - 3);
    BYTE3(v53) = *(v87 - 4);
    BYTE4(v53) = *(v87 - 5);
    BYTE5(v53) = *(v87 - 6);
    BYTE6(v53) = *(v87 - 7);
    HIBYTE(v53) = *(v87 - 8);
    if ( m_bool
      || (hkaCheckKeycode(*((unsigned __int8 *)v87 - 8), v13),
          hkaProcessFlyingColors(&HK_flyingcolors_animation_1),
          HK_flyingcolors_animation_1.m_bool) )
    {
      v25 = v53 & 0xF;
      v27 = (int)v53 >> 2;
      v26 = 2 * (v25 + 2);
      LOWORD(v27) = (__int16)((((int)v53 >> 2) & 0xFFFC) << (16 - (v25 + 2))) >> (16 - (v25 + 2));
      v6 = (__int16)((4 * (unsigned __int16)((int)v53 >> (v25 + 4))) << (16 - (v25 + 2))) >> (16 - (v25 + 2));
      v28 = v55 >> v26;
      v29 = (v53 >> v26) | ((unsigned __int64)((unsigned int)v55 & ((1 << (v26 & 0x1F))
                                                                  - (((2 * (v25 + 2)) >> 5) & 1)
                                                                  - 1)) << (64 - v26));
      v30 = v29 & 0xF;
      v31 = (int)v29 >> 2;
      LOWORD(v31) = (__int16)((((int)v29 >> 2) & 0xFFFC) << (16 - (v30 + 2))) >> (16 - (v30 + 2));
      v77 = v31;
      v5 = (__int16)((4 * (unsigned __int16)((int)v29 >> (v30 + 4))) << (16 - (v30 + 2))) >> (16 - (v30 + 2));
      v32 = 2 * (v30 + 2);
      v33 = (v29 >> v32) | ((unsigned __int64)((unsigned int)v28 & ((1 << (v32 & 0x1F))
                                                                  - (((2 * (v30 + 2)) >> 5) & 1)
                                                                  - 1)) << (64 - v32));
      v34 = v28 >> v32;
      v35 = v33 & 0xF;
      v36 = (int)v33 >> 2;
      LOWORD(v36) = (__int16)((((int)v33 >> 2) & 0xFFFC) << (16 - (v35 + 2))) >> (16 - (v35 + 2));
      v4 = (__int16)((4 * (unsigned __int16)((int)v33 >> (v35 + 4))) << (16 - (v35 + 2))) >> (16 - (v35 + 2));
      v37 = v33 >> (2 * ((unsigned __int8)v35 + 2));
      v38 = v37 | (((unsigned int)v34 & ((1 << ((2 * (v35 + 2)) & 0x1F)) - (((2 * (v35 + 2)) >> 5) & 1) - 1)) << (64 - 2 * (v35 + 2)));
      v39 = (v37 | ((unsigned __int64)((unsigned int)v34 & ((1 << ((2 * (v35 + 2)) & 0x1F))
                                                          - (((2 * (v35 + 2)) >> 5) & 1)
                                                          - 1)) << (64 - 2 * ((unsigned __int8)v35 + 2)))) & 0xF;
      v3 = (__int16)(((v38 >> 2) & 0xFFFC) << (16 - (v39 + 2))) >> (16 - (v39 + 2));
      v40 = v38 >> (v39 + 4);
      LOWORD(v40) = (__int16)((4 * (_WORD)v40) << (16 - (v39 + 2))) >> (16 - (v39 + 2));
      v58 = v40;
    }
    else
    {
      v27 = v81;
      v36 = v82;
    }
    v41 = v77;
    v42 = v80;
    v43 = v79;
    v44 = v78;
    v45 = v89;
    v46 = v57;
    v56 = 3i64;
    do
    {
      v7 += v60;
      HIWORD(v47) = HIWORD(v59);
      LOWORD(v45) = v7 + v45;
      LOWORD(v42) = v45 + v42;
      LOWORD(v46) = v42 + v46;
      LOWORD(v43) = v46 + v43;
      LOWORD(v47) = v43 + v59;
      LOWORD(v44) = v43 + v59 + v44;
      v59 = v47;
      LOWORD(v27) = v44 + v27;
      v6 += v27;
      LOWORD(v41) = v6 + v41;
      v5 += v41;
      LOWORD(v36) = v5 + v36;
      v4 += v36;
      v3 += v4;
      LOWORD(v58) = v3 + v58;
      --v56;
    }
    while ( v56 );
    HIWORD(v48) = HIWORD(v60);
    LOWORD(v41) = (__int16)v41 >> 2;
    LOWORD(v43) = (__int16)v43 >> 2;
    LOWORD(v48) = (__int16)v60 >> 2;
    v71 = v41;
    v77 = v41;
    HIWORD(v49) = HIWORD(v58);
    v60 = v48;
    v61 = v48;
    HIWORD(v48) = HIWORD(v59);
    LOWORD(v49) = (__int16)v58 >> 2;
    LOWORD(v42) = (__int16)v42 >> 2;
    LOWORD(v48) = (__int16)v59 >> 2;
    LOWORD(v46) = (__int16)v46 >> 2;
    LOWORD(v45) = (__int16)v45 >> 2;
    LOWORD(v44) = (__int16)v44 >> 2;
    LOWORD(v27) = (__int16)v27 >> 2;
    LOWORD(v36) = (__int16)v36 >> 2;
    v66 = v43;
    v76 = (__int16)v58 >> 2;
    v59 = v48;
    v67 = v48;
    v7 >>= 2;
    v6 >>= 2;
    v5 >>= 2;
    v4 >>= 2;
    v3 >>= 2;
    v79 = v43;
    v64 = v42;
    v65 = v46;
    v58 = v49;
    v62 = v7;
    data = v83 + 1;
    v50 = v84-- == 1;
    v63 = v45;
    v68 = v44;
    v69 = v27;
    v70 = v6;
    v72 = v5;
    v73 = v36;
    v74 = v4;
    v75 = v3;
    LOWORD(v48) = *v85;
    v80 = v42;
    *out = v48;
    v57 = v46;
    v8 = v87;
    ++out;
    v89 = v45;
    v78 = v44;
    v81 = v27;
    v82 = v36;
    v83 = data;
  }
  while ( !v50 );
  return v87;
}

// File Line: 897
// RVA: 0xBAC5F0
const char *__fastcall hkaPredictiveBlockCompression::ScalarDecoder::decodeAdjacentFrames(
        const char *data,
        int whichFrame,
        __int16 *out)
{
  __int16 v3; // di
  __int16 v4; // r13
  __int16 v5; // r12
  __int16 v6; // r15
  __int16 v7; // si
  const char *v8; // rbx
  unsigned int v9; // eax
  __int64 v10; // rcx
  const char *v11; // r14
  char m_bool; // al
  __int64 v13; // rdx
  int v14; // r10d
  int v15; // edx
  int v16; // r8d
  unsigned __int64 v17; // r11
  int v18; // edx
  int v19; // r10d
  char v20; // cl
  unsigned __int64 v21; // r10
  int v22; // edx
  int v23; // r9d
  int v24; // r9d
  int v25; // eax
  char v26; // r9
  int v27; // r14d
  unsigned __int64 v28; // rdi
  unsigned __int64 v29; // r11
  int v30; // eax
  int v31; // r9d
  char v32; // cl
  unsigned __int64 v33; // r10
  unsigned __int64 v34; // rdi
  int v35; // eax
  int v36; // r11d
  unsigned __int64 v37; // r10
  int v38; // r9d
  char v39; // dl
  int v40; // r9d
  int v41; // ecx
  int v42; // edx
  int v43; // r8d
  int v44; // r9d
  int v45; // r10d
  int v46; // ebx
  int v47; // eax
  int v48; // eax
  int v49; // ecx
  __int64 v50; // rcx
  bool v51; // zf
  unsigned __int64 v53; // [rsp+20h] [rbp-59h]
  unsigned __int64 v54; // [rsp+20h] [rbp-59h]
  unsigned __int64 v55; // [rsp+28h] [rbp-51h]
  unsigned __int64 v56; // [rsp+28h] [rbp-51h]
  __int64 v57; // [rsp+28h] [rbp-51h]
  int v58; // [rsp+30h] [rbp-49h]
  int v59; // [rsp+34h] [rbp-45h]
  int v60; // [rsp+38h] [rbp-41h]
  int v61; // [rsp+3Ch] [rbp-3Dh]
  unsigned __int16 v62; // [rsp+40h] [rbp-39h] BYREF
  __int16 v63; // [rsp+42h] [rbp-37h] BYREF
  unsigned __int16 v64; // [rsp+44h] [rbp-35h]
  unsigned __int16 v65; // [rsp+46h] [rbp-33h]
  unsigned __int16 v66; // [rsp+48h] [rbp-31h]
  unsigned __int16 v67; // [rsp+4Ah] [rbp-2Fh]
  unsigned __int16 v68; // [rsp+4Ch] [rbp-2Dh]
  unsigned __int16 v69; // [rsp+4Eh] [rbp-2Bh]
  unsigned __int16 v70; // [rsp+50h] [rbp-29h]
  __int16 v71; // [rsp+52h] [rbp-27h]
  unsigned __int16 v72; // [rsp+54h] [rbp-25h]
  __int16 v73; // [rsp+56h] [rbp-23h]
  unsigned __int16 v74; // [rsp+58h] [rbp-21h]
  __int16 v75; // [rsp+5Ah] [rbp-1Fh]
  __int16 v76; // [rsp+5Ch] [rbp-1Dh]
  unsigned __int16 v77; // [rsp+5Eh] [rbp-1Bh]
  int v78; // [rsp+60h] [rbp-19h]
  int v79; // [rsp+64h] [rbp-15h]
  int v80; // [rsp+68h] [rbp-11h]
  int v81; // [rsp+6Ch] [rbp-Dh]
  int v82; // [rsp+70h] [rbp-9h]
  int v83; // [rsp+74h] [rbp-5h]
  __int64 v84; // [rsp+78h] [rbp-1h]
  const char *v85; // [rsp+80h] [rbp+7h]
  __int16 *v86; // [rsp+88h] [rbp+Fh]
  __int16 *v87; // [rsp+90h] [rbp+17h]
  int v88; // [rsp+E0h] [rbp+67h]
  const char *v89; // [rsp+E0h] [rbp+67h]
  int v91; // [rsp+F8h] [rbp+7Fh]

  v3 = v76;
  v4 = v75;
  v5 = v73;
  v6 = v71;
  v7 = v63;
  v81 = v72;
  v60 = v68;
  v87 = &v63 + whichFrame;
  v59 = v77;
  v86 = (__int16 *)(&v62 + whichFrame);
  v83 = v74;
  v85 = data;
  v82 = v70;
  v8 = data + 16;
  v58 = v66;
  v84 = 16i64;
  v91 = v64;
  v79 = v69;
  v78 = v67;
  v80 = v65;
  v61 = v62;
  do
  {
    v9 = *(unsigned __int8 *)data;
    v10 = (v9 & 0xF) + 1;
    v88 = (v9 & 0xF) + 1;
    v11 = &v8[(v9 >> 4) + 1];
    LOBYTE(v55) = *(v11 - 9);
    BYTE1(v55) = *(v11 - 10);
    BYTE2(v55) = *(v11 - 11);
    BYTE3(v55) = *(v11 - 12);
    BYTE4(v55) = *(v11 - 13);
    BYTE5(v55) = *(v11 - 14);
    BYTE6(v55) = *(v11 - 15);
    HIBYTE(v55) = *(v11 - 16);
    LOBYTE(v53) = *(v11 - 1);
    BYTE1(v53) = *(v11 - 2);
    BYTE2(v53) = *(v11 - 3);
    BYTE3(v53) = *(v11 - 4);
    BYTE4(v53) = *(v11 - 5);
    BYTE5(v53) = *(v11 - 6);
    BYTE6(v53) = *(v11 - 7);
    HIBYTE(v53) = *(v11 - 8);
    m_bool = HK_flyingcolors_animation_1.m_bool;
    if ( HK_flyingcolors_animation_1.m_bool
      || (hkaCheckKeycode(v10, 0i64),
          hkaProcessFlyingColors(&HK_flyingcolors_animation_1),
          (m_bool = HK_flyingcolors_animation_1.m_bool) != 0) )
    {
      v14 = (int)v53 >> 2;
      v15 = v53 & 0xF;
      LOWORD(v14) = (__int16)((((int)v53 >> 2) & 0xFFFC) << (16 - (v15 + 2))) >> (16 - (v15 + 2));
      v61 = v14;
      v16 = 2 * (v15 + 2);
      v7 = (__int16)((4 * (unsigned __int16)((int)v53 >> (v15 + 4))) << (16 - (v15 + 2))) >> (16 - (v15 + 2));
      v17 = (v53 >> v16) | ((unsigned __int64)((unsigned int)v55 & ((1 << (v16 & 0x1F)) - ((v16 >> 5) & 1) - 1)) << (64 - (unsigned __int8)v16));
      v18 = v17 & 0xF;
      HIWORD(v91) = (unsigned int)((int)v17 >> 2) >> 16;
      LOWORD(v91) = (__int16)((((int)v17 >> 2) & 0xFFFC) << (16 - (v18 + 2))) >> (16 - (v18 + 2));
      v19 = (int)v17 >> (v18 + 4);
      LOWORD(v19) = (__int16)((4 * (_WORD)v19) << (16 - (v18 + 2))) >> (16 - (v18 + 2));
      v80 = v19;
      v20 = 2 * (v18 + 2);
      v21 = (v17 >> v20) | (((v55 >> v16) & ((1 << (v20 & 0x1F)) - (((2 * (v18 + 2)) >> 5) & 1u) - 1)) << (64 - v20));
      v22 = ((unsigned __int8)(v17 >> v20) | (unsigned __int8)(((v55 >> v16) & ((1 << (v20 & 0x1F))
                                                                              - (((2 * (v18 + 2)) >> 5) & 1u)
                                                                              - 1)) << (64 - v20))) & 0xF;
      HIWORD(v58) = (unsigned int)((int)v21 >> 2) >> 16;
      LOWORD(v58) = (__int16)((((int)v21 >> 2) & 0xFFFC) << (16 - (v22 + 2))) >> (16 - (v22 + 2));
      LODWORD(v17) = (int)v21 >> (v22 + 4);
      LOWORD(v17) = (__int16)((4 * (_WORD)v17) << (16 - (v22 + 2))) >> (16 - (v22 + 2));
      v78 = v17;
      v23 = (v21 >> (2 * ((unsigned __int8)v22 + 2))) | (((unsigned int)(v55 >> v16 >> v20) & ((1 << ((2 * (v22 + 2)) & 0x1F))
                                                                                             - (((2 * (v22 + 2)) >> 5) & 1)
                                                                                             - 1)) << (64 - 2 * (v22 + 2)));
      v13 = v23 & 0xF;
      LODWORD(v21) = v23 >> 2;
      LOWORD(v21) = (__int16)(((v23 >> 2) & 0xFFFC) << (16 - ((v23 & 0xF) + 2))) >> (16 - ((v23 & 0xF) + 2));
      v24 = v23 >> ((v23 & 0xF) + 4);
      v60 = v21;
      LOWORD(v24) = (__int16)((4 * (_WORD)v24) << (16 - (v13 + 2))) >> (16 - (v13 + 2));
      v79 = v24;
    }
    v89 = &v11[v88];
    LOBYTE(v56) = *(v89 - 9);
    BYTE1(v56) = *(v89 - 10);
    BYTE2(v56) = *(v89 - 11);
    BYTE3(v56) = *(v89 - 12);
    BYTE4(v56) = *(v89 - 13);
    BYTE5(v56) = *(v89 - 14);
    BYTE6(v56) = *(v89 - 15);
    HIBYTE(v56) = *(v89 - 16);
    LOBYTE(v54) = *(v89 - 1);
    BYTE1(v54) = *(v89 - 2);
    BYTE2(v54) = *(v89 - 3);
    BYTE3(v54) = *(v89 - 4);
    BYTE4(v54) = *(v89 - 5);
    BYTE5(v54) = *(v89 - 6);
    BYTE6(v54) = *(v89 - 7);
    HIBYTE(v54) = *(v89 - 8);
    if ( m_bool
      || (hkaCheckKeycode(*((unsigned __int8 *)v89 - 8), v13),
          hkaProcessFlyingColors(&HK_flyingcolors_animation_1),
          HK_flyingcolors_animation_1.m_bool) )
    {
      v25 = v54 & 0xF;
      v27 = (int)v54 >> 2;
      v26 = 2 * (v25 + 2);
      LOWORD(v27) = (__int16)((((int)v54 >> 2) & 0xFFFC) << (16 - (v25 + 2))) >> (16 - (v25 + 2));
      v6 = (__int16)((4 * (unsigned __int16)((int)v54 >> (v25 + 4))) << (16 - (v25 + 2))) >> (16 - (v25 + 2));
      v28 = v56 >> v26;
      v29 = (v54 >> v26) | ((unsigned __int64)((unsigned int)v56 & ((1 << (v26 & 0x1F))
                                                                  - (((2 * (v25 + 2)) >> 5) & 1)
                                                                  - 1)) << (64 - v26));
      v30 = v29 & 0xF;
      v31 = (int)v29 >> 2;
      LOWORD(v31) = (__int16)((((int)v29 >> 2) & 0xFFFC) << (16 - (v30 + 2))) >> (16 - (v30 + 2));
      v81 = v31;
      v5 = (__int16)((4 * (unsigned __int16)((int)v29 >> (v30 + 4))) << (16 - (v30 + 2))) >> (16 - (v30 + 2));
      v32 = 2 * (v30 + 2);
      v33 = (v29 >> v32) | ((unsigned __int64)((unsigned int)v28 & ((1 << (v32 & 0x1F))
                                                                  - (((2 * (v30 + 2)) >> 5) & 1)
                                                                  - 1)) << (64 - v32));
      v34 = v28 >> v32;
      v35 = v33 & 0xF;
      v36 = (int)v33 >> 2;
      LOWORD(v36) = (__int16)((((int)v33 >> 2) & 0xFFFC) << (16 - (v35 + 2))) >> (16 - (v35 + 2));
      v4 = (__int16)((4 * (unsigned __int16)((int)v33 >> (v35 + 4))) << (16 - (v35 + 2))) >> (16 - (v35 + 2));
      v37 = v33 >> (2 * ((unsigned __int8)v35 + 2));
      v38 = v37 | (((unsigned int)v34 & ((1 << ((2 * (v35 + 2)) & 0x1F)) - (((2 * (v35 + 2)) >> 5) & 1) - 1)) << (64 - 2 * (v35 + 2)));
      v39 = (v37 | ((unsigned __int64)((unsigned int)v34 & ((1 << ((2 * (v35 + 2)) & 0x1F))
                                                          - (((2 * (v35 + 2)) >> 5) & 1)
                                                          - 1)) << (64 - 2 * ((unsigned __int8)v35 + 2)))) & 0xF;
      v3 = (__int16)(((v38 >> 2) & 0xFFFC) << (16 - (v39 + 2))) >> (16 - (v39 + 2));
      v40 = v38 >> (v39 + 4);
      LOWORD(v40) = (__int16)((4 * (_WORD)v40) << (16 - (v39 + 2))) >> (16 - (v39 + 2));
      v59 = v40;
    }
    else
    {
      v27 = v82;
      v36 = v83;
    }
    v41 = v81;
    v42 = v80;
    v43 = v78;
    v44 = v79;
    v45 = v91;
    v46 = v58;
    v57 = 3i64;
    do
    {
      v7 += v61;
      HIWORD(v47) = HIWORD(v60);
      LOWORD(v45) = v7 + v45;
      LOWORD(v42) = v45 + v42;
      LOWORD(v46) = v42 + v46;
      LOWORD(v43) = v46 + v43;
      LOWORD(v47) = v43 + v60;
      LOWORD(v44) = v43 + v60 + v44;
      v60 = v47;
      LOWORD(v27) = v44 + v27;
      v6 += v27;
      LOWORD(v41) = v6 + v41;
      v5 += v41;
      LOWORD(v36) = v5 + v36;
      v4 += v36;
      v3 += v4;
      LOWORD(v59) = v3 + v59;
      --v57;
    }
    while ( v57 );
    HIWORD(v48) = HIWORD(v61);
    LOWORD(v41) = (__int16)v41 >> 2;
    LOWORD(v42) = (__int16)v42 >> 2;
    LOWORD(v48) = (__int16)v61 >> 2;
    v72 = v41;
    LOWORD(v43) = (__int16)v43 >> 2;
    v61 = v48;
    v62 = v48;
    HIWORD(v48) = HIWORD(v60);
    LOWORD(v48) = (__int16)v60 >> 2;
    v81 = v41;
    HIWORD(v49) = HIWORD(v59);
    LOWORD(v49) = (__int16)v59 >> 2;
    v65 = v42;
    LOWORD(v46) = (__int16)v46 >> 2;
    v67 = v43;
    v77 = (__int16)v59 >> 2;
    LOWORD(v45) = (__int16)v45 >> 2;
    LOWORD(v44) = (__int16)v44 >> 2;
    LOWORD(v27) = (__int16)v27 >> 2;
    LOWORD(v36) = (__int16)v36 >> 2;
    v60 = v48;
    v68 = v48;
    v66 = v46;
    v80 = v42;
    v7 >>= 2;
    v6 >>= 2;
    v5 >>= 2;
    v4 >>= 2;
    v3 >>= 2;
    v78 = v43;
    v63 = v7;
    v64 = v45;
    v69 = v44;
    v70 = v27;
    v71 = v6;
    v73 = v5;
    v74 = v36;
    v75 = v4;
    v76 = v3;
    v59 = v49;
    v50 = (__int64)v85;
    *out = *v86;
    LOWORD(v48) = *v87;
    data = (const char *)(v50 + 1);
    v51 = v84-- == 1;
    out[16] = v48;
    v58 = v46;
    v8 = v89;
    ++out;
    v91 = v45;
    v79 = v44;
    v82 = v27;
    v83 = v36;
    v85 = data;
  }
  while ( !v51 );
  return v89;
}

