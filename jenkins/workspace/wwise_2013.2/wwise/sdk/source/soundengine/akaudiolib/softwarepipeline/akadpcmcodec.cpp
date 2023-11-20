// File Line: 89
// RVA: 0xAA0320
char __fastcall CAkADPCMCodec::Decode(char *pbSrc, char *pbDst, unsigned int cBlocks, unsigned int nBlockAlignment, unsigned int nChannels)
{
  unsigned int v5; // er15
  char *v6; // r11
  char *v7; // rbp
  signed __int64 v8; // rsi
  int v9; // ecx
  int v10; // er9
  signed int v11; // edi
  _BYTE *v12; // r14
  char *v13; // r11
  unsigned int v14; // eax
  unsigned int v15; // ebx
  int v16; // er8
  int v17; // eax
  int v18; // er10
  signed int v19; // eax
  int v20; // er8
  __int64 v21; // rbx
  char *v22; // r11
  int v23; // eax
  signed int v24; // eax
  int v25; // eax
  int v26; // ecx
  signed __int16 v27; // ax
  __int64 v29; // [rsp+48h] [rbp+10h]
  int v30; // [rsp+50h] [rbp+18h]

  v5 = cBlocks;
  v6 = pbDst;
  v7 = pbSrc;
  if ( cBlocks )
  {
    v8 = 2i64 * nChannels;
    v29 = nBlockAlignment;
    do
    {
      v9 = (unsigned __int8)v7[2];
      v10 = *(signed __int16 *)v7;
      v11 = 31;
      v30 = v5 - 1;
      *(_WORD *)v6 = *(_WORD *)v7;
      v12 = v7 + 4;
      v13 = &v6[v8];
      do
      {
        v14 = (unsigned __int8)*v12++;
        v15 = v14;
        v16 = v14 & 0xF;
        v17 = (signed int)((2 * (v14 & 7) + 1) * CAkADPCMCodec::m_asStep[v9]) / 8;
        if ( v16 & 8 )
          v17 = -v17;
        v18 = v17 + v10;
        if ( (signed __int16)(v17 + v10) != v17 + v10 )
        {
          v19 = 0x7FFF;
          if ( v18 < -32768 )
            v19 = -32768;
          v18 = v19;
        }
        v20 = v9 + CAkADPCMCodec::m_asNextStep[v16];
        if ( v20 >= 0 )
        {
          if ( v20 >= 89 )
            v20 = 88;
        }
        else
        {
          v20 = 0;
        }
        v21 = v15 >> 4;
        *(_WORD *)v13 = v18;
        v22 = &v13[v8];
        v23 = (signed int)((2 * (v21 & 7) + 1) * CAkADPCMCodec::m_asStep[v20]) / 8;
        if ( v21 & 8 )
          v23 = (signed int)((2 * (v21 & 7) + 1) * CAkADPCMCodec::m_asStep[v20]) / -8;
        v10 = v23 + v18;
        if ( (signed __int16)(v23 + v18) != v23 + v18 )
        {
          v24 = 0x7FFF;
          if ( v10 < -32768 )
            v24 = -32768;
          v10 = v24;
        }
        v9 = v20 + CAkADPCMCodec::m_asNextStep[v21];
        if ( v9 >= 0 )
        {
          if ( v9 >= 89 )
            v9 = 88;
        }
        else
        {
          v9 = 0;
        }
        *(_WORD *)v22 = v10;
        v13 = &v22[v8];
        --v11;
      }
      while ( v11 );
      --v5;
      v25 = (2 * (*v12 & 7) + 1) * CAkADPCMCodec::m_asStep[v9] / 8;
      if ( *v12 & 8 )
        v25 = (2 * (*v12 & 7) + 1) * CAkADPCMCodec::m_asStep[v9] / -8;
      v26 = v25 + v10;
      if ( (signed __int16)(v25 + v10) != v25 + v10 )
      {
        v27 = 0x7FFF;
        if ( v26 < -32768 )
          v27 = -32768;
        LOWORD(v26) = v27;
      }
      *(_WORD *)v13 = v26;
      v7 += v29;
      v6 = &v13[v8];
    }
    while ( v30 );
  }
  return 1;
}

