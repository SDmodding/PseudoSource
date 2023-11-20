// File Line: 40
// RVA: 0xDFE2B0
void __fastcall hkpMoppCodeGenerator::addCommand8(hkpMoppCodeGenerator *this, int code, int param)
{
  char v3; // di
  hkpMoppCodeGenerator *v4; // rbx

  v3 = code;
  v4 = this;
  this->m_code[this->m_size - (signed __int64)this->m_pos++ - 1] = param;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  v4->m_code[v4->m_size - (signed __int64)v4->m_pos++ - 1] = v3;
  if ( v4->m_pos >= v4->m_size )
    hkpMoppCodeGenerator::resize(v4);
}

// File Line: 47
// RVA: 0xDFE040
void __fastcall hkpMoppCodeGenerator::addCommand16(hkpMoppCodeGenerator *this, int code, int param)
{
  char v3; // di^1
  char v4; // si
  hkpMoppCodeGenerator *v5; // rbx

  v3 = BYTE1(param);
  v4 = code;
  this->m_code[this->m_size - (signed __int64)this->m_pos++ - 1] = param;
  v5 = this;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  v5->m_code[v5->m_size - (signed __int64)v5->m_pos++ - 1] = v3;
  if ( v5->m_pos >= v5->m_size )
    hkpMoppCodeGenerator::resize(v5);
  v5->m_code[v5->m_size - (signed __int64)v5->m_pos++ - 1] = v4;
  if ( v5->m_pos >= v5->m_size )
    hkpMoppCodeGenerator::resize(v5);
}

// File Line: 55
// RVA: 0xDFE0E0
void __fastcall hkpMoppCodeGenerator::addCommand24(hkpMoppCodeGenerator *this, int code, int param)
{
  int v3; // edi
  char v4; // si
  hkpMoppCodeGenerator *v5; // rbx

  v3 = param;
  v4 = code;
  this->m_code[this->m_size - (signed __int64)this->m_pos++ - 1] = param;
  v5 = this;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  v5->m_code[v5->m_size - (signed __int64)v5->m_pos++ - 1] = BYTE1(v3);
  if ( v5->m_pos >= v5->m_size )
    hkpMoppCodeGenerator::resize(v5);
  v5->m_code[v5->m_size - (signed __int64)v5->m_pos++ - 1] = BYTE2(v3);
  if ( v5->m_pos >= v5->m_size )
    hkpMoppCodeGenerator::resize(v5);
  v5->m_code[v5->m_size - (signed __int64)v5->m_pos++ - 1] = v4;
  if ( v5->m_pos >= v5->m_size )
    hkpMoppCodeGenerator::resize(v5);
}

// File Line: 64
// RVA: 0xDFE320
void __fastcall hkpMoppCodeGenerator::addParam24(hkpMoppCodeGenerator *this, int param)
{
  int v2; // edi
  hkpMoppCodeGenerator *v3; // rbx

  v2 = param;
  v3 = this;
  this->m_code[this->m_size - (signed __int64)this->m_pos++ - 1] = param;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  v3->m_code[v3->m_size - (signed __int64)v3->m_pos++ - 1] = BYTE1(v2);
  if ( v3->m_pos >= v3->m_size )
    hkpMoppCodeGenerator::resize(v3);
  v3->m_code[v3->m_size - (signed __int64)v3->m_pos++ - 1] = BYTE2(v2);
  if ( v3->m_pos >= v3->m_size )
    hkpMoppCodeGenerator::resize(v3);
}

// File Line: 80
// RVA: 0xDFE1B0
void __fastcall hkpMoppCodeGenerator::addCommand32(hkpMoppCodeGenerator *this, int code, unsigned int param)
{
  unsigned int v3; // edi
  char v4; // si
  hkpMoppCodeGenerator *v5; // rbx

  v3 = param;
  v4 = code;
  this->m_code[this->m_size - (signed __int64)this->m_pos++ - 1] = param;
  v5 = this;
  if ( this->m_pos >= this->m_size )
    hkpMoppCodeGenerator::resize(this);
  v5->m_code[v5->m_size - (signed __int64)v5->m_pos++ - 1] = BYTE1(v3);
  if ( v5->m_pos >= v5->m_size )
    hkpMoppCodeGenerator::resize(v5);
  v5->m_code[v5->m_size - (signed __int64)v5->m_pos++ - 1] = BYTE2(v3);
  if ( v5->m_pos >= v5->m_size )
    hkpMoppCodeGenerator::resize(v5);
  v5->m_code[v5->m_size - (signed __int64)v5->m_pos++ - 1] = HIBYTE(v3);
  if ( v5->m_pos >= v5->m_size )
    hkpMoppCodeGenerator::resize(v5);
  v5->m_code[v5->m_size - (signed __int64)v5->m_pos++ - 1] = v4;
  if ( v5->m_pos >= v5->m_size )
    hkpMoppCodeGenerator::resize(v5);
}

