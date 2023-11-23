// File Line: 137
// RVA: 0x3A6D70
double __fastcall ERotation(TransformFloatParamRot axis, UFG::qMatrix44 *transform)
{
  int v2; // ecx
  double result; // xmm0_8
  unsigned int v4; // xmm1_4
  float y; // xmm2_4
  float x; // xmm2_4
  __int64 z_low; // xmm0_8
  float z; // xmm2_4

  if ( axis == TFP_RX )
  {
    z_low = LODWORD(transform->v1.z);
    v4 = (unsigned int)FLOAT_1_0;
    if ( *(float *)&z_low <= -1.0 )
    {
      z_low = LODWORD(FLOAT_N1_0);
    }
    else if ( *(float *)&z_low >= 1.0 )
    {
      z_low = (unsigned int)FLOAT_1_0;
    }
    z = transform->v2.z;
    if ( z <= -1.0 )
    {
      z = FLOAT_N1_0;
    }
    else if ( z >= 1.0 )
    {
      *(_QWORD *)&result = z_low ^ *(_QWORD *)_xmm;
      goto LABEL_10;
    }
    *(_QWORD *)&result = z_low ^ *(_QWORD *)_xmm;
    *(float *)&result = atan2f(*(float *)&result, z);
    return result;
  }
  v2 = axis - 1;
  if ( !v2 )
  {
    *(_QWORD *)&result = LODWORD(transform->v0.x);
    if ( *(float *)&result <= -1.0 )
    {
      *(_QWORD *)&result = LODWORD(FLOAT_N1_0);
    }
    else if ( *(float *)&result >= 1.0 )
    {
      *(_QWORD *)&result = (unsigned int)FLOAT_1_0;
    }
    x = transform->v2.x;
    if ( x <= -1.0 )
    {
      x = FLOAT_N1_0;
    }
    else if ( x >= 1.0 )
    {
      v4 = (unsigned int)FLOAT_1_0 ^ _xmm[0];
      goto LABEL_10;
    }
    v4 = LODWORD(x) ^ _xmm[0];
    goto LABEL_10;
  }
  if ( v2 != 1 )
    return 0.0;
  *(_QWORD *)&result = LODWORD(transform->v1.x);
  v4 = (unsigned int)FLOAT_1_0;
  if ( *(float *)&result <= -1.0 )
  {
    *(_QWORD *)&result = LODWORD(FLOAT_N1_0);
  }
  else if ( *(float *)&result >= 1.0 )
  {
    *(_QWORD *)&result = (unsigned int)FLOAT_1_0;
  }
  y = transform->v1.y;
  if ( y <= -1.0 )
  {
    y = FLOAT_N1_0;
    goto LABEL_13;
  }
  if ( y < 1.0 )
LABEL_13:
    v4 = LODWORD(y);
LABEL_10:
  *(float *)&result = atan2f(*(float *)&result, *(float *)&v4);
  return result;
}

// File Line: 273
// RVA: 0x3A6E80
float __fastcall EaseInOut(float param)
{
  float result; // xmm0_4

  result = (float)(sinf((float)(param * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  if ( result <= 0.0 )
    return 0.0;
  if ( result >= 1.0 )
    return *(float *)&FLOAT_1_0;
  return result;
}

// File Line: 291
// RVA: 0x2C2A30
const char *__fastcall TimePlotPoint::GetClassname(TimePlotPoint *this)
{
  return TimePlotPoint::sClassName;
}

// File Line: 296
// RVA: 0x2C98D0
float __fastcall TimePlotPoint::GetValue(TimePlotPoint *this)
{
  return this->mValue;
}

// File Line: 297
// RVA: 0x2DCCF0
void __fastcall TimePlotPoint::SetValue(TimePlotPoint *this, float value)
{
  this->mValue = value;
}

