// File Line: 22
// RVA: 0xB02590
void __fastcall LimiterUtilities::LimiterUtilities(LimiterUtilities *this, float lookAheadDelayFactor, float firLengthFactor)
{
  this->mLookAheadDelayFactor = lookAheadDelayFactor;
  this->mFIRLengthFactor = firLengthFactor;
}

// File Line: 28
// RVA: 0xB025B0
void __fastcall LimiterUtilities::~LimiterUtilities(LimiterUtilities *this)
{
  ;
}

// File Line: 34
// RVA: 0xB025C0
__int64 __fastcall LimiterUtilities::GetTotalLookAheadDelayLength(LimiterUtilities *this, long double sampleRate)
{
  return (unsigned int)((signed int)(this->mLookAheadDelayFactor * sampleRate)
                      + (signed int)(this->mFIRLengthFactor * sampleRate));
}

// File Line: 40
// RVA: 0xB025F0
__int64 __fastcall LimiterUtilities::GetLookAheadDelayLength(LimiterUtilities *this, long double sampleRate)
{
  return (unsigned int)(signed int)(this->mLookAheadDelayFactor * sampleRate);
}

// File Line: 46
// RVA: 0xB02610
__int64 __fastcall LimiterUtilities::GetFIRLength(LimiterUtilities *this, long double sampleRate)
{
  return (unsigned int)(signed int)(this->mFIRLengthFactor * sampleRate);
}

// File Line: 54
// RVA: 0xB02630
void __fastcall LimiterUtilities::GenerateExpTable(float *theExpTable, int theTableSize, long double theThreshold, long double theKnee)
{
  int v4; // esi
  float *v5; // rdi
  double v6; // xmm11_8
  double v7; // xmm14_8
  double v8; // xmm10_8
  signed int v9; // ebx
  double i; // xmm15_8
  double v11; // xmm1_8
  double v12; // xmm0_8
  double v13; // xmm6_8
  double v14; // xmm7_8
  double v15; // xmm0_8
  float v16; // xmm0_4

  v4 = theTableSize;
  v5 = theExpTable;
  v6 = 1.0 / (double)(theTableSize - 1);
  v7 = (1.0 - pow(theKnee * 0.01, 0.0005)) * 10000.0 + 2.0;
  v8 = pow(10.0, -theThreshold * 0.05);
  v9 = 0;
  for ( i = pow(10.0, -theThreshold * -0.5 * 0.05); v9 < v4; *(v5 - 1) = v16 )
  {
    v11 = (double)v9 * v6;
    if ( v11 <= 0.0 )
    {
      v15 = v8;
    }
    else
    {
      v12 = pow(1.0 - v11, 0.5);
      v13 = 1.0 - pow(1.0 - (1.0 - v12), 0.5);
      v14 = pow(v13, -0.9999);
      v15 = pow(v13, 1.0 / v7 - 1.0) + i;
      if ( v15 > v14 )
        v15 = v14;
    }
    if ( v15 < 1.0 )
      v15 = DOUBLE_1_0;
    if ( v15 > v8 )
      v15 = v8;
    v16 = v15;
    ++v9;
    ++v5;
  }
}

