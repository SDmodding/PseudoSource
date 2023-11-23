// File Line: 407
// RVA: 0x67A4D0
float __fastcall UFG::LinearGraph<float>::GetDomainValue(UFG::LinearGraph<float> *this, float y)
{
  __int64 nData; // r8
  int v3; // eax
  int v4; // r9d
  float v6; // xmm1_4
  const float *tRange; // r10
  float *v9; // rcx
  __int64 v10; // rcx
  float v11; // xmm1_4
  const float *v12; // rax
  float v13; // xmm2_4
  const float *v15; // rax
  float v16; // xmm1_4
  float v17; // xmm0_4
  const float *fDomain; // rax

  nData = this->nData;
  v3 = 1;
  v4 = 0;
  v6 = FLOAT_3_4028235e38;
  if ( (int)nData <= 1 )
    goto LABEL_21;
  tRange = this->tRange;
  v9 = (float *)(tRange + 1);
  do
  {
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*v9 - y) & _xmm) < v6 )
    {
      v4 = v3;
      LODWORD(v6) = COERCE_UNSIGNED_INT(*v9 - y) & _xmm;
    }
    ++v3;
    ++v9;
  }
  while ( v3 < (int)nData );
  if ( !v4 )
  {
LABEL_21:
    v15 = this->tRange;
    v16 = v15[1];
    v17 = *v15;
    fDomain = this->fDomain;
    if ( v16 <= v17 )
    {
      if ( y < v17 )
        return (float)((float)(1.0 - (float)((float)(y - v17) / (float)(v16 - v17))) * *fDomain)
             + (float)((float)((float)(y - v17) / (float)(v16 - v17)) * fDomain[1]);
    }
    else if ( y > v17 )
    {
      return (float)((float)(1.0 - (float)((float)(y - v17) / (float)(v16 - v17))) * *fDomain)
           + (float)((float)((float)(y - v17) / (float)(v16 - v17)) * fDomain[1]);
    }
    return *fDomain;
  }
  v10 = v4;
  v11 = tRange[v4];
  if ( v4 != (_DWORD)nData - 1 )
  {
    if ( y <= v11 )
    {
      if ( v11 > tRange[v4 + 1] )
        goto LABEL_17;
    }
    else if ( v11 < tRange[v4 + 1] )
    {
LABEL_17:
      v10 = v4 + 1;
      v12 = this->fDomain;
      v13 = (float)(y - tRange[v10 - 1]) / (float)(tRange[v10] - tRange[v10 - 1]);
      return (float)((float)(1.0 - v13) * v12[v10 - 1]) + (float)(v13 * v12[v10]);
    }
    v12 = this->fDomain;
    goto LABEL_10;
  }
  v12 = this->fDomain;
  if ( v11 >= tRange[v4 - 1] )
  {
    if ( y < v11 )
      goto LABEL_10;
  }
  else if ( y > v11 )
  {
LABEL_10:
    v13 = (float)(y - tRange[v4 - 1]) / (float)(v11 - tRange[v4 - 1]);
    return (float)((float)(1.0 - v13) * v12[v10 - 1]) + (float)(v13 * v12[v10]);
  }
  return v12[nData - 1];
}

