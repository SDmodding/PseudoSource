// File Line: 16
// RVA: 0xE58840
hkResult *__fastcall hkPackfileHeader::readHeader(hkResult *result, hkStreamReader *stream, hkPackfileHeader *out)
{
  hkPackfileHeader *v3; // rdi
  hkResult *v4; // rbx
  hkResult *v5; // rax
  char dst; // [rsp+20h] [rbp-48h]

  v3 = out;
  v4 = result;
  if ( ((signed int (__fastcall *)(hkStreamReader *, hkPackfileHeader *, signed __int64))stream->vfptr[2].__vecDelDtor)(
         stream,
         out,
         64i64) < 64
    || (hkString::memSet(&dst, -1, 64), v3->m_magic[0] != 1474355287)
    || v3->m_magic[1] != 281067536 )
  {
    v4->m_enum = 1;
    v5 = v4;
  }
  else
  {
    v4->m_enum = 0;
    v5 = v4;
  }
  return v5;
}

// File Line: 32
// RVA: 0xE587E0
hkPackfileSectionHeader *__fastcall hkPackfileHeader::getSectionHeader(hkPackfileHeader *this, const void *packfileData, int i)
{
  signed int v4; // ecx
  signed int v5; // eax

  if ( !*((_DWORD *)packfileData + 5) )
    return 0i64;
  v4 = *((_DWORD *)packfileData + 3);
  if ( v4 <= 10 )
    return (hkPackfileSectionHeader *)((char *)packfileData + 48 * i + 64);
  v5 = 0;
  if ( v4 == 11 )
    v5 = 64;
  return (hkPackfileSectionHeader *)((char *)packfileData + i * v5 + 64);
}

// File Line: 82
// RVA: 0xE58830
hkPackfileSectionHeader *__fastcall hkPackfileHeader::getSectionHeader(hkPackfileHeader *this, void *packfileData, int i)
{
  return hkPackfileHeader::getSectionHeader(this, packfileData, i);
}

