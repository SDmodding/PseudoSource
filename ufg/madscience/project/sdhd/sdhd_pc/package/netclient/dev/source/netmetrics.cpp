// File Line: 76
// RVA: 0x14671E0
unsigned __int64 dynamic_initializer_for__NetMetrics::mUpBandWidthData__()
{
  signed int v0; // edi
  char *v1; // rbx
  unsigned __int64 result; // rax

  v0 = 39;
  v1 = (char *)&NetMetrics::mUpBandWidthData[0][0].mAverageUsage;
  do
  {
    *((_DWORD *)v1 - 5) = 0;
    *(_QWORD *)(v1 - 4) = 0i64;
    result = UFG::qGetTicks();
    --v0;
    *(_QWORD *)(v1 - 12) = result;
    v1 += 24;
  }
  while ( v0 >= 0 );
  return result;
}

// File Line: 77
// RVA: 0x1467100
unsigned __int64 dynamic_initializer_for__NetMetrics::mDownBandWidthData__()
{
  signed int v0; // edi
  char *v1; // rbx
  unsigned __int64 result; // rax

  v0 = 39;
  v1 = (char *)&NetMetrics::mDownBandWidthData[0][0].mAverageUsage;
  do
  {
    *((_DWORD *)v1 - 5) = 0;
    *(_QWORD *)(v1 - 4) = 0i64;
    result = UFG::qGetTicks();
    --v0;
    *(_QWORD *)(v1 - 12) = result;
    v1 += 24;
  }
  while ( v0 >= 0 );
  return result;
}

