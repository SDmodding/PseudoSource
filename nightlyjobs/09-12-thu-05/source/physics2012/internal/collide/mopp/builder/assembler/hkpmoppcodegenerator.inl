// File Line: 40
// RVA: 0xDFE2B0
void __fastcall hkpMoppCodeGenerator::addCommand8(hkpMoppCodeGenerator *this, char code, char param)
{
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = param;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = code;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
}

// File Line: 47
// RVA: 0xDFE040
void __fastcall hkpMoppCodeGenerator::addCommand16(hkpMoppCodeGenerator *this, char code, __int16 param)
{
  char v3; // di^1

  v3 = HIBYTE(param);
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = param;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = v3;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = code;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
}

// File Line: 55
// RVA: 0xDFE0E0
void __fastcall hkpMoppCodeGenerator::addCommand24(hkpMoppCodeGenerator *this, char code, int param)
{
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = param;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = BYTE1(param);
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = BYTE2(param);
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = code;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
}

// File Line: 64
// RVA: 0xDFE320
void __fastcall hkpMoppCodeGenerator::addParam24(hkpMoppCodeGenerator *this, int param)
{
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = param;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = BYTE1(param);
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = BYTE2(param);
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
}

// File Line: 80
// RVA: 0xDFE1B0
void __fastcall hkpMoppCodeGenerator::addCommand32(hkpMoppCodeGenerator *this, char code, unsigned int param)
{
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = param;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = BYTE1(param);
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = BYTE2(param);
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = HIBYTE(param);
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  this->m_code[this->m_size - (__int64)this->m_pos++ - 1] = code;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
}

