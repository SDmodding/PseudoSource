// File Line: 142
// RVA: 0xB05550
float __fastcall AK_FPMin_8(float fA, float fB)
{
  if ( fA >= fB )
    return fB;
  return fA;
}

// File Line: 148
// RVA: 0xB0A290
float __fastcall AK_FPMax_16(float fA, float fB)
{
  if ( fA <= fB )
    return fB;
  return fA;
}

// File Line: 154
// RVA: 0xB06FD0
void __fastcall AK_FPSetValGT_4(
        float in_fComparandA,
        float in_fComparandB,
        float *io_fVariableToSet,
        float in_fValueIfTrue)
{
  if ( in_fComparandA > in_fComparandB )
    *io_fVariableToSet = in_fValueIfTrue;
}

// File Line: 161
// RVA: 0xAF9830
void __fastcall AK_FPSetValGTE_2(
        float in_fComparandA,
        float in_fComparandB,
        float *io_fVariableToSet,
        float in_fValueIfTrue)
{
  if ( in_fComparandA >= in_fComparandB )
    *io_fVariableToSet = in_fValueIfTrue;
}

// File Line: 168
// RVA: 0xB07C70
void __fastcall AK_FPSetValLT_8(
        float in_fComparandA,
        float in_fComparandB,
        float *io_fVariableToSet,
        float in_fValueIfTrue)
{
  if ( in_fComparandA < in_fComparandB )
    *io_fVariableToSet = in_fValueIfTrue;
}

// File Line: 175
// RVA: 0xB09650
void __fastcall AK_FPSetValLTE_3(
        float in_fComparandA,
        float in_fComparandB,
        float *io_fVariableToSet,
        float in_fValueIfTrue)
{
  if ( in_fComparandA <= in_fComparandB )
    *io_fVariableToSet = in_fValueIfTrue;
}

