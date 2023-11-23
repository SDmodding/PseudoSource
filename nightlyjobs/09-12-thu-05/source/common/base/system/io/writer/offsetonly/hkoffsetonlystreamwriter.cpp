// File Line: 14
// RVA: 0x1300460
void __fastcall hkOffsetOnlyStreamWriter::hkOffsetOnlyStreamWriter(hkOffsetOnlyStreamWriter *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkOffsetOnlyStreamWriter::`vftable;
  *(_QWORD *)&this->m_offset = 0i64;
}

// File Line: 18
// RVA: 0x1300490
hkBool *__fastcall hkOffsetOnlyStreamWriter::isOk(hkOffsetOnlyStreamWriter *this, hkBool *result)
{
  result->m_bool = 1;
  return result;
}

// File Line: 23
// RVA: 0x13004A0
__int64 __fastcall hkOffsetOnlyStreamWriter::write(
        hkOffsetOnlyStreamWriter *this,
        const void *__formal,
        unsigned int n)
{
  int m_eofOffset; // edx
  __int64 result; // rax

  m_eofOffset = this->m_eofOffset;
  this->m_offset += n;
  result = n;
  if ( this->m_offset > m_eofOffset )
    m_eofOffset = this->m_offset;
  this->m_eofOffset = m_eofOffset;
  return result;
}

// File Line: 30
// RVA: 0x13004C0
hkBool *__fastcall hkOffsetOnlyStreamWriter::seekTellSupported(hkOffsetOnlyStreamWriter *this, hkBool *result)
{
  result->m_bool = 1;
  return result;
}

// File Line: 35
// RVA: 0x13004D0
hkResult *__fastcall hkOffsetOnlyStreamWriter::seek(
        hkOffsetOnlyStreamWriter *this,
        hkResult *result,
        int offset,
        hkStreamWriter::SeekWhence whence)
{
  int v5; // r9d
  int m_eofOffset; // ecx
  hkResult *v7; // rax

  if ( whence )
  {
    v5 = whence - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
        this->m_offset = this->m_eofOffset - offset;
    }
    else
    {
      this->m_offset += offset;
    }
  }
  else
  {
    this->m_offset = offset;
  }
  m_eofOffset = this->m_eofOffset;
  result->m_enum = HK_SUCCESS;
  v7 = result;
  if ( this->m_offset > m_eofOffset )
    m_eofOffset = this->m_offset;
  this->m_eofOffset = m_eofOffset;
  return v7;
}

// File Line: 56
// RVA: 0x1300520
__int64 __fastcall hkOffsetOnlyStreamWriter::tell(hkOffsetOnlyStreamWriter *this)
{
  return (unsigned int)this->m_offset;
}

