// File Line: 24
// RVA: 0xB028C0
long double __fastcall GetTCScalar(long double timeInSamples)
{
  long double result; // xmm0_8

  if ( timeInSamples == 0.0 )
    return DOUBLE_1_0;
  result = 1.0 / timeInSamples;
  if ( 1.0 / timeInSamples > 1.0 )
    return DOUBLE_1_0;
  return result;
}

// File Line: 48
// RVA: 0xB02900
double __fastcall GetSoftKneeThreshold(double knee, double threshold)
{
  double result; // xmm0_8

  result = threshold - (1.0 - pow(threshold, 0.005)) * 0.0025;
  if ( knee < 0.0 )
    return result * (1.0 - (1.0 - threshold * threshold) * (knee * -0.1));
  return result;
}

// File Line: 68
// RVA: 0xB02980
void __fastcall GenerateCompressionTable(
        float *compressionTable,
        int tableSize,
        double threshold,
        long double ratio,
        double knee,
        long double *softThreshold)
{
  double v9; // xmm15_8
  __int16 v10; // bx
  int v11; // eax
  double v12; // xmm7_8
  double v13; // xmm2_8
  double v14; // xmm2_8
  double v15; // xmm0_8
  __int64 v16; // rax
  double SoftKneeThreshold; // [rsp+20h] [rbp-B8h]

  v9 = 1.0 / (double)tableSize;
  v10 = 0;
  SoftKneeThreshold = GetSoftKneeThreshold(knee, threshold);
  *softThreshold = SoftKneeThreshold;
  if ( tableSize > 0 )
  {
    v11 = 0;
    do
    {
      v12 = (double)v11 * v9;
      if ( knee > 0.0 )
      {
        pow(v12, 0.4);
        v12 = pow(v12, knee * 0.1 + 1.0) * (1.0 - v12) + v12 * v12;
        if ( knee > 10.0 )
          v12 = v12 * (1.0 - (1.0 - threshold) * 0.1 * (knee - 10.0) * v12);
      }
      v13 = 1.0 - pow(1.0 - v12, 0.5);
      if ( knee <= 0.0 )
        v14 = v13 / threshold;
      else
        v14 = v13 / SoftKneeThreshold;
      v15 = pow(v14 + 1.0, 1.0 / ratio - 1.0);
      v16 = v10++;
      *(float *)&v15 = v15;
      compressionTable[v16] = *(float *)&v15;
      v11 = v10;
    }
    while ( v10 < tableSize );
  }
}

// File Line: 127
// RVA: 0xB02B90
void __fastcall GenerateGCompressionTable(
        float *compressionTable,
        int tableSize,
        long double threshold,
        long double ratio,
        bool bypassed)
{
  double v8; // xmm8_8
  double v9; // xmm10_8
  int v10; // edi
  __int64 v11; // rbx
  float *v12; // rbx
  double v13; // xmm0_8
  float v14; // xmm1_4

  v8 = 1.0 / (double)tableSize;
  if ( bypassed )
  {
    v9 = DOUBLE_1_0;
    ratio = DOUBLE_1_0;
  }
  else
  {
    v9 = pow(10.0, threshold * 0.05);
  }
  v10 = 0;
  if ( tableSize >= 4 )
  {
    do
    {
      _vdecl_pow2();
      *(double *)&compressionTable[v10] = _vdecl_pow2();
      v11 = v10 + 2;
      _vdecl_pow2();
      v10 += 4;
      *(double *)&compressionTable[v11] = _vdecl_pow2();
    }
    while ( v10 < tableSize - (tableSize & 3) );
  }
  if ( v10 < tableSize )
  {
    v12 = &compressionTable[v10];
    do
    {
      v13 = pow(1.0 - (double)v10++ * v8, 0.5);
      ++v12;
      v14 = pow((1.0 - v13) * (1.0 / v9) + 1.0, 1.0 / ratio - 1.0);
      *(v12 - 1) = v14;
    }
    while ( v10 < tableSize );
  }
}

// File Line: 162
// RVA: 0xB02E90
void __fastcall GenerateGGateTable(
        float *gateTable,
        int tableSize,
        long double threshold,
        long double ratio,
        long double range,
        bool bypassed)
{
  double v9; // xmm9_8
  double v10; // xmm7_8
  int v11; // ebx
  double v12; // xmm8_8
  double v13; // xmm0_8
  double v14; // xmm0_8
  float v15; // xmm0_4

  v9 = 1.0 / (double)(tableSize - 1);
  if ( bypassed )
  {
    ratio = DOUBLE_1_0;
    v10 = DOUBLE_1_0;
  }
  else
  {
    v10 = pow(10.0, range * 0.05);
  }
  v11 = 0;
  if ( tableSize > 0 )
  {
    v12 = ratio - 1.0;
    do
    {
      v13 = pow(1.0 - (double)v11 * v9, 0.5);
      v14 = pow(1.0 - v13, v12);
      if ( v14 > 1.0 )
        v14 = DOUBLE_1_0;
      if ( v14 < v10 )
        v14 = v10;
      v15 = v14;
      ++v11;
      *gateTable++ = v15;
    }
    while ( v11 < tableSize );
  }
}

