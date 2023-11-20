// File Line: 12
// RVA: 0xC802D0
hkBool *__fastcall hkStreamWriter::seekTellSupported(hkStreamWriter *this, hkBool *result)
{
  result->m_bool = 0;
  return result;
}

// File Line: 17
// RVA: 0xC802E0
hkResult *__fastcall hkStreamWriter::seek(hkStreamWriter *this, hkResult *result, int offset, hkStreamWriter::SeekWhence whence)
{
  result->m_enum = 1;
  return result;
}

// File Line: 23
// RVA: 0xC802F0
signed __int64 __fastcall hkStreamWriter::tell(hkStreamWriter *this)
{
  return 0xFFFFFFFFi64;
}

