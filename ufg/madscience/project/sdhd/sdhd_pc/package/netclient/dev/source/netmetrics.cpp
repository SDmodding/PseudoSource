// File Line: 76
// RVA: 0x14671E0
unsigned __int64 dynamic_initializer_for__NetMetrics::mUpBandWidthData__()
{
  int v0; // edi
  float *p_mAverageUsage; // rbx
  unsigned __int64 result; // rax

  v0 = 39;
  p_mAverageUsage = &NetMetrics::mUpBandWidthData[0][0].mAverageUsage;
  do
  {
    *(p_mAverageUsage - 5) = 0.0;
    *(_QWORD *)(p_mAverageUsage - 1) = 0i64;
    result = UFG::qGetTicks();
    --v0;
    *(_QWORD *)(p_mAverageUsage - 3) = result;
    p_mAverageUsage += 6;
  }
  while ( v0 >= 0 );
  return result;
}

// File Line: 77
// RVA: 0x1467100
unsigned __int64 dynamic_initializer_for__NetMetrics::mDownBandWidthData__()
{
  int v0; // edi
  float *p_mAverageUsage; // rbx
  unsigned __int64 result; // rax

  v0 = 39;
  p_mAverageUsage = &NetMetrics::mDownBandWidthData[0][0].mAverageUsage;
  do
  {
    *(p_mAverageUsage - 5) = 0.0;
    *(_QWORD *)(p_mAverageUsage - 1) = 0i64;
    result = UFG::qGetTicks();
    --v0;
    *(_QWORD *)(p_mAverageUsage - 3) = result;
    p_mAverageUsage += 6;
  }
  while ( v0 >= 0 );
  return result;
}

