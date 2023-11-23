// File Line: 30
// RVA: 0xA63970
__int64 __fastcall CAkEnvironmentsMgr::Init(CAkEnvironmentsMgr *this)
{
  *(_DWORD *)&this->m_bCurveEnabled[0][0] = 0;
  return 1i64;
}

// File Line: 38
// RVA: 0xA63A60
__int64 __fastcall CAkEnvironmentsMgr::Term(CAkEnvironmentsMgr *this)
{
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> (*ConversionTable)[2]; // rbx
  __int64 v2; // rsi
  __int64 v3; // rdi

  ConversionTable = this->ConversionTable;
  v2 = 2i64;
  do
  {
    v3 = 2i64;
    do
    {
      if ( (*ConversionTable)[0].m_pArrayGraphPoints )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, (*ConversionTable)[0].m_pArrayGraphPoints);
        (*ConversionTable)[0].m_pArrayGraphPoints = 0i64;
      }
      *(_QWORD *)&(*ConversionTable)[0].m_ulArraySize = 0i64;
      ConversionTable = (CAkConversionTable<AkRTPCGraphPointBase<float>,float> (*)[2])((char *)ConversionTable + 16);
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
__int64 __fastcall CAkEnvironmentsMgr::SetObsOccCurve(
        CAkEnvironmentsMgr *this,
        CAkEnvironmentsMgr::eCurveXType in_x,
        CAkEnvironmentsMgr::eCurveYType in_y,
        unsigned int in_ulNbPoints,
        AkRTPCGraphPointBase<float> *in_paPoints,
        AkCurveScaling in_eScaling)
{
  __int64 v8; // rdi
  __int64 result; // rax

  v8 = in_x;
  result = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
             &this->ConversionTable[v8][in_y],
             in_paPoints,
             in_ulNbPoints,
             in_eScaling);
  if ( (_DWORD)result == 1 && in_y == CurveVol )
  {
    CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Linearize(this->ConversionTable[v8]);
    return 1i64;
  }
  return result;
}

