// File Line: 14
// RVA: 0xE4CE90
hkEnum<enum hkTagfileReader::FormatType,int> *__fastcall hkTagfileReader::detectFormat(
        hkEnum<enum hkTagfileReader::FormatType,int> *result,
        hkStreamReader *stream)
{
  int v4; // [rsp+20h] [rbp-18h] BYREF
  int v5; // [rsp+24h] [rbp-14h]
  int v6; // [rsp+48h] [rbp+10h]
  int v7; // [rsp+48h] [rbp+10h]

  if ( ((unsigned int (__fastcall *)(hkStreamReader *, int *, __int64))stream->vfptr[3].__vecDelDtor)(
         stream,
         &v4,
         16i64) == 16 )
  {
    if ( v4 == -894431970 && v5 == -804128050 )
      goto LABEL_7;
    HIBYTE(v6) = v4;
    LOBYTE(v6) = HIBYTE(v4);
    BYTE1(v6) = BYTE2(v4);
    BYTE2(v6) = BYTE1(v4);
    if ( v6 != -894431970 )
      goto LABEL_8;
    HIBYTE(v7) = v5;
    LOBYTE(v7) = HIBYTE(v5);
    BYTE1(v7) = BYTE2(v5);
    BYTE2(v7) = BYTE1(v5);
    if ( v7 == -804128050 )
    {
LABEL_7:
      result->m_storage = 2;
      return result;
    }
    else
    {
LABEL_8:
      result->m_storage = 1;
      return result;
    }
  }
  else
  {
    result->m_storage = 0;
    return result;
  }
}

