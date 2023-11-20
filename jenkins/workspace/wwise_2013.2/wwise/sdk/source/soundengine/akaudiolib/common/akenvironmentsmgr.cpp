// File Line: 30
// RVA: 0xA63970
signed __int64 __fastcall CAkEnvironmentsMgr::Init(CAkEnvironmentsMgr *this)
{
  *(_DWORD *)&this->m_bCurveEnabled[0][0] = 0;
  return 1i64;
}

// File Line: 38
// RVA: 0xA63A60
signed __int64 __fastcall CAkEnvironmentsMgr::Term(CAkEnvironmentsMgr *this)
{
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> (*v1)[2]; // rbx
  signed __int64 v2; // rsi
  signed __int64 v3; // rdi

  v1 = this->ConversionTable;
  v2 = 2i64;
  do
  {
    v3 = 2i64;
    do
    {
      if ( (*v1)[0].m_pArrayGraphPoints )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, (*v1)[0].m_pArrayGraphPoints);
        (*v1)[0].m_pArrayGraphPoints = 0i64;
      }
      *(_QWORD *)&(*v1)[0].m_ulArraySize = 0i64;
      v1 = (CAkConversionTable<AkRTPCGraphPointBase<float>,float> (*)[2])((char *)v1 + 16);
      --v3;
    }
    while ( v3 );
    --v2;
  }
  while ( v2 );
  return 1i64;
}

// File Line: 51
// RVA: 0xA639E0
signed __int64 __fastcall CAkEnvironmentsMgr::SetObsOccCurve(CAkEnvironmentsMgr *this, CAkEnvironmentsMgr::eCurveXType in_x, CAkEnvironmentsMgr::eCurveYType in_y, unsigned int in_ulNbPoints, AkRTPCGraphPointBase<float> *in_paPoints, AkCurveScaling in_eScaling)
{
  CAkEnvironmentsMgr::eCurveYType v6; // esi
  CAkEnvironmentsMgr *v7; // rbp
  signed __int64 v8; // rdi
  signed __int64 result; // rax
  unsigned int v10; // ebx

  v6 = in_y;
  v7 = this;
  v8 = in_x;
  result = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
             (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)this->ConversionTable + v8 * 2 + (signed int)in_y,
             in_paPoints,
             in_ulNbPoints,
             in_eScaling);
  v10 = result;
  if ( (_DWORD)result == 1 && v6 == CurveVol )
  {
    CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Linearize(v7->ConversionTable[v8]);
    result = v10;
  }
  return result;
}

