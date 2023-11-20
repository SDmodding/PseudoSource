// File Line: 10
// RVA: 0xBA5860
void __fastcall hkStringBuf::setLength(hkStringBuf *this, int length)
{
  __int64 v2; // rsi
  hkStringBuf *v3; // rbx
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = length;
  v3 = this;
  v4 = length + 1;
  v5 = this->m_string.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < length + 1 )
  {
    v6 = 2 * v5;
    v7 = length + 1;
    if ( v4 < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, this, v7, 1);
  }
  v3->m_string.m_size = v4;
  v3->m_string.m_data[v2] = 0;
}

