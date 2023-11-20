// File Line: 137
// RVA: 0x3A6D70
void __fastcall ERotation(TransformFloatParamRot axis, UFG::qMatrix44 *transform)
{
  __int32 v2; // ecx
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm2_4

  if ( axis )
  {
    v2 = axis - 1;
    if ( v2 )
    {
      if ( v2 == 1 )
      {
        v3 = transform->v1.x;
        if ( v3 <= -1.0 )
        {
          v3 = FLOAT_N1_0;
        }
        else if ( v3 >= 1.0 )
        {
          v3 = *(float *)&FLOAT_1_0;
        }
        v4 = transform->v1.y;
        if ( v4 <= -1.0 )
        {
          v4 = FLOAT_N1_0;
        }
        else if ( v4 >= 1.0 )
        {
          atan2f(v3, 1.0);
          return;
        }
        atan2f(v3, v4);
      }
    }
    else
    {
      v5 = transform->v0.x;
      if ( transform->v0.x <= -1.0 )
      {
        v5 = FLOAT_N1_0;
      }
      else if ( v5 >= 1.0 )
      {
        v5 = *(float *)&FLOAT_1_0;
      }
      v6 = transform->v2.x;
      if ( v6 <= -1.0 )
      {
        v6 = FLOAT_N1_0;
      }
      else if ( v6 >= 1.0 )
      {
        atan2f(v5, COERCE_FLOAT((unsigned int)FLOAT_1_0 ^ _xmm[0]));
        return;
      }
      atan2f(v5, COERCE_FLOAT(LODWORD(v6) ^ _xmm[0]));
    }
  }
  else
  {
    v7 = transform->v1.z;
    if ( v7 <= -1.0 )
    {
      v7 = FLOAT_N1_0;
    }
    else if ( v7 >= 1.0 )
    {
      v7 = *(float *)&FLOAT_1_0;
    }
    v8 = transform->v2.z;
    if ( v8 <= -1.0 )
    {
      v8 = FLOAT_N1_0;
    }
    else if ( v8 >= 1.0 )
    {
      atan2f(COERCE_FLOAT(LODWORD(v7) ^ _xmm[0]), 1.0);
      return;
    }
    atan2f(COERCE_FLOAT(LODWORD(v7) ^ _xmm[0]), v8);
  }
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
    result = *(float *)&FLOAT_1_0;
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

