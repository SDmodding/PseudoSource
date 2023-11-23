// File Line: 75
// RVA: 0x12FE560
hkUFloat8 *__fastcall hkUFloat8::operator=(hkUFloat8 *this, const long double *fv)
{
  float fva; // [rsp+38h] [rbp+10h] BYREF

  fva = *(double *)fv;
  return hkUFloat8::operator=(this, &fva);
}

// File Line: 80
// RVA: 0x12FE590
hkUFloat8 *__fastcall hkUFloat8::operator=(hkUFloat8 *this, float *fv)
{
  unsigned __int16 EncodedFloat; // ax
  float v5; // xmm6_4
  float v6; // xmm0_4
  int v8; // edi
  int v9; // esi
  int v10; // ebp
  int v11; // ebx
  unsigned __int16 v12; // ax
  float v13; // xmm0_4
  unsigned __int16 v14; // ax

  EncodedFloat = hkUFloat8::getEncodedFloat(1u);
  v5 = 0.0;
  if ( EncodedFloat )
    LODWORD(v6) = (EncodedFloat + 243712) << 12;
  else
    v6 = 0.0;
  if ( v6 <= *fv )
  {
    v8 = 0;
    v9 = 256;
    v10 = 6;
    v11 = 128;
    do
    {
      v12 = hkUFloat8::getEncodedFloat(v11);
      if ( v12 )
        LODWORD(v13) = (v12 + 243712) << 12;
      else
        v13 = 0.0;
      if ( v13 >= *fv )
        v9 = v11;
      else
        v8 = v11;
      v11 = (v9 + v8) >> 1;
      --v10;
    }
    while ( v10 >= 0 );
    v14 = hkUFloat8::getEncodedFloat(v11);
    if ( v14 )
      LODWORD(v5) = (v14 + 243712) << 12;
    if ( v5 < *fv && v11 < 255 )
      LOBYTE(v11) = v11 + 1;
    this->m_value = v11;
    return this;
  }
  else
  {
    this->m_value = 0;
    return this;
  }
}

