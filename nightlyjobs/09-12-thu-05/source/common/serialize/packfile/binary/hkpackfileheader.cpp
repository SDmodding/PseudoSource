// File Line: 16
// RVA: 0xE58840
hkResult *__fastcall hkPackfileHeader::readHeader(hkResult *result, hkStreamReader *stream, hkPackfileHeader *out)
{
  char dst[72]; // [rsp+20h] [rbp-48h] BYREF

  if ( ((int (__fastcall *)(hkStreamReader *, hkPackfileHeader *, __int64))stream->vfptr[2].__vecDelDtor)(
         stream,
         out,
         64i64) >= 64
    && (hkString::memSet(dst, -1, 0x40u), out->m_magic[0] == 1474355287)
    && out->m_magic[1] == 281067536 )
  {
    result->m_enum = HK_SUCCESS;
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 32
// RVA: 0xE587E0
hkPackfileSectionHeader *__fastcall hkPackfileHeader::getSectionHeader(
        hkPackfileHeader *this,
        _DWORD *packfileData,
        int i)
{
  int v4; // ecx
  int v5; // eax

  if ( !packfileData[5] )
    return 0i64;
  v4 = packfileData[3];
  if ( v4 <= 10 )
    return (hkPackfileSectionHeader *)&packfileData[12 * i + 16];
  v5 = 0;
  if ( v4 == 11 )
    v5 = 64;
  return (hkPackfileSectionHeader *)((char *)packfileData + i * v5 + 64);
}

// File Line: 82
// RVA: 0xE58830
// attributes: thunk
hkPackfileSectionHeader *__fastcall hkPackfileHeader::getSectionHeader(
        hkPackfileHeader *this,
        _DWORD *packfileData,
        int i)
{
  return ?getSectionHeader@hkPackfileHeader@@QEBAPEBVhkPackfileSectionHeader@@PEBXH@Z(this, packfileData, i);
}

