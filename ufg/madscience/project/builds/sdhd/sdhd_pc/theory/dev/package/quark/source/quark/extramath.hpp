// File Line: 407
// RVA: 0x67A4D0
float __fastcall UFG::LinearGraph<float>::GetDomainValue(UFG::LinearGraph<float> *this, const float y)
{
  __int64 v2; // r8
  signed int v3; // eax
  signed int v4; // er9
  float v5; // xmm2_4
  float v6; // xmm1_4
  UFG::LinearGraph<float> *v7; // rdx
  const float *v8; // r10
  float *v9; // rcx
  __int64 v10; // rcx
  float v11; // xmm1_4
  const float *v12; // rax
  float v13; // xmm2_4
  float *v15; // rax
  float v16; // xmm1_4
  float v17; // xmm0_4
  float *v18; // rax

  v2 = this->nData;
  v3 = 1;
  v4 = 0;
  v5 = y;
  v6 = FLOAT_3_4028235e38;
  v7 = this;
  if ( (signed int)v2 <= 1 )
    goto LABEL_28;
  v8 = this->tRange;
  v9 = (float *)(v8 + 1);
  do
  {
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*v9 - v5) & _xmm) < v6 )
    {
      v4 = v3;
      LODWORD(v6) = COERCE_UNSIGNED_INT(*v9 - v5) & _xmm;
    }
    ++v3;
    ++v9;
  }
  while ( v3 < (signed int)v2 );
  if ( !v4 )
  {
LABEL_28:
    v15 = (float *)v7->tRange;
    v16 = v15[1];
    v17 = *v15;
    v18 = (float *)v7->fDomain;
    if ( v16 <= v17 )
    {
      if ( v5 < v17 )
        return (float)((float)(1.0 - (float)((float)(v5 - v17) / (float)(v16 - v17))) * *v18)
             + (float)((float)((float)(v5 - v17) / (float)(v16 - v17)) * v18[1]);
    }
    else if ( v5 > v17 )
    {
      return (float)((float)(1.0 - (float)((float)(v5 - v17) / (float)(v16 - v17))) * *v18)
           + (float)((float)((float)(v5 - v17) / (float)(v16 - v17)) * v18[1]);
    }
    return *v18;
  }
  v10 = v4;
  v11 = v8[v4];
  if ( v4 != (_DWORD)v2 - 1 )
  {
    if ( v5 <= v11 )
    {
      if ( v11 > v8[v4 + 1] )
        goto LABEL_17;
    }
    else if ( v11 < v8[v4 + 1] )
    {
LABEL_17:
      v10 = v4 + 1;
      v12 = v7->fDomain;
      v13 = (float)(v5 - v8[v10 - 1]) / (float)(v8[v10] - v8[v10 - 1]);
      return (float)((float)(1.0 - v13) * v12[v10 - 1]) + (float)(v13 * v12[v10]);
    }
    v12 = v7->fDomain;
    goto LABEL_10;
  }
  v12 = v7->fDomain;
  if ( v11 >= v8[v4 - 1] )
  {
    if ( v5 < v11 )
      goto LABEL_10;
  }
  else if ( v5 > v11 )
  {
LABEL_10:
    v13 = (float)(v5 - v8[v4 - 1]) / (float)(v11 - v8[v4 - 1]);
    return (float)((float)(1.0 - v13) * v12[v10 - 1]) + (float)(v13 * v12[v10]);
  }
  return v12[v2 - 1];
}

