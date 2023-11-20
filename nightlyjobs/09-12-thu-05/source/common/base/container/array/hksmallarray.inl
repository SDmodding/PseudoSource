// File Line: 241
// RVA: 0xD8E060
void __fastcall hkSmallArray<hkConstraintInternal>::insertAt(hkSmallArray<hkConstraintInternal> *this, int index, hkConstraintInternal *p, int numtoinsert)
{
  int v4; // er14
  __int64 v5; // rbp
  int v6; // edi
  __int64 v7; // rbx
  int v8; // eax
  int v9; // er14
  hkConstraintInternal *v10; // r15
  hkSmallArray<hkConstraintInternal> *v11; // rsi
  int v12; // eax
  int v13; // edx
  __int64 v14; // rcx
  __int64 v15; // rbx

  v4 = this->m_size;
  v5 = numtoinsert;
  v6 = v4 + numtoinsert;
  v7 = index;
  v8 = this->m_capacityAndFlags & 0x3FFF;
  v9 = v4 - index;
  v10 = p;
  v11 = this;
  if ( v6 > v8 && v8 < v6 )
  {
    v12 = 2 * v8;
    v13 = v6;
    if ( v6 < v12 )
      v13 = v12;
    hkSmallArrayUtil::_reserve(this, v13, 64);
  }
  v14 = v7 + v5;
  v15 = v7 << 6;
  hkMemUtil::memCpyBackwards(&v11->m_data[v14], (char *)v11->m_data + v15, v9 << 6);
  hkMemUtil::memCpyBackwards((char *)v11->m_data + v15, v10, (_DWORD)v5 << 6);
  v11->m_size = v6;
}

// File Line: 258
// RVA: 0xD8E050
void __fastcall hkSmallArray<hkConstraintInternal>::insertAt(hkSmallArray<hkConstraintInternal> *this, int i, hkConstraintInternal *t)
{
  hkSmallArray<hkConstraintInternal>::insertAt(this, i, t, 1);
}

