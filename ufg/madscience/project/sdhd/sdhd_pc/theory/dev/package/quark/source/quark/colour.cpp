// File Line: 80
// RVA: 0x14677D0
__int64 dynamic_initializer_for__UFG::qColour::Missing__()
{
  UFG::qColour::Missing = UFG::qColour::Magenta;
  return *(_QWORD *)&UFG::qColour::Magenta.b;
}

// File Line: 82
// RVA: 0x1467770
__int64 dynamic_initializer_for__UFG::qColour::AxisX__()
{
  UFG::qColour::AxisX = UFG::qColour::Red;
  return *(_QWORD *)&UFG::qColour::Red.b;
}

// File Line: 83
// RVA: 0x1467790
__int64 dynamic_initializer_for__UFG::qColour::AxisY__()
{
  UFG::qColour::AxisY = UFG::qColour::Green;
  return *(_QWORD *)&UFG::qColour::Green.b;
}

// File Line: 84
// RVA: 0x14677B0
__int64 dynamic_initializer_for__UFG::qColour::AxisZ__()
{
  UFG::qColour::AxisZ = UFG::qColour::Blue;
  return *(_QWORD *)&UFG::qColour::Blue.b;
}

// File Line: 85
// RVA: 0x14677F0
__int64 dynamic_initializer_for__UFG::qColour::Plane__()
{
  UFG::qColour::Plane = UFG::qColour::Cyan;
  return *(_QWORD *)&UFG::qColour::Cyan.b;
}

// File Line: 86
// RVA: 0x1467750
__int64 dynamic_initializer_for__UFG::qColour::Active__()
{
  UFG::qColour::Active = UFG::qColour::Yellow;
  return *(_QWORD *)&UFG::qColour::Yellow.b;
}

// File Line: 90
// RVA: 0x182630
void __fastcall UFG::qColourRGBToHSV(UFG::qColour *hsv, UFG::qColour *rgb)
{
  float r; // xmm1_4
  float g; // xmm0_4
  float v4; // xmm4_4
  float b; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm0_4

  hsv->a = rgb->a;
  r = rgb->r;
  g = rgb->g;
  if ( rgb->r >= g )
    v4 = rgb->g;
  else
    v4 = rgb->r;
  b = rgb->b;
  if ( v4 >= b )
    v4 = rgb->b;
  if ( r <= g )
    r = rgb->g;
  if ( r <= b )
    r = rgb->b;
  hsv->b = r;
  v6 = r - v4;
  if ( r <= 0.0 || v6 == 0.0 )
  {
    *(_QWORD *)&hsv->r = 0i64;
    if ( r <= 0.0 )
    {
      r = 0.0;
    }
    else if ( r >= 1.0 )
    {
      LODWORD(hsv->b) = (_DWORD)FLOAT_1_0;
      return;
    }
    hsv->b = r;
  }
  else
  {
    hsv->g = v6 / r;
    v7 = rgb->r;
    v8 = rgb->g;
    if ( rgb->r < r )
    {
      if ( v8 < r )
        hsv->r = (float)((float)(v7 - v8) / v6) + 4.0;
      else
        hsv->r = (float)((float)(rgb->b - v7) / v6) + 2.0;
    }
    else
    {
      hsv->r = (float)(v8 - rgb->b) / v6;
    }
    v9 = hsv->r * 60.0;
    hsv->r = v9;
    if ( v9 < 0.0 )
      hsv->r = v9 + 360.0;
  }
}

// File Line: 121
// RVA: 0x1824E0
void __fastcall UFG::qColourHSVToRGB(UFG::qColour *rgb, UFG::qColour *hsv)
{
  float g; // xmm6_4
  float r; // xmm3_4
  float v4; // xmm3_4
  float b; // xmm5_4
  int v6; // r8d
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm2_4
  int v11; // r8d
  int v12; // r8d
  int v13; // r8d
  float v14; // eax
  float v15; // eax

  rgb->a = hsv->a;
  g = hsv->g;
  if ( g > 0.0 )
  {
    r = hsv->r;
    if ( hsv->r >= 360.0 )
      r = 0.0;
    v4 = r * 0.016666668;
    b = hsv->b;
    v6 = (int)v4;
    v7 = (float)(1.0 - g) * b;
    v8 = v4 - (float)(int)v4;
    v9 = (float)(1.0 - (float)(g * v8)) * b;
    v10 = (float)(1.0 - (float)((float)(1.0 - v8) * g)) * b;
    if ( v6 )
    {
      v11 = v6 - 1;
      if ( v11 )
      {
        v12 = v11 - 1;
        if ( v12 )
        {
          v13 = v12 - 1;
          if ( v13 )
          {
            rgb->g = v7;
            if ( v13 == 1 )
            {
              rgb->r = v10;
              rgb->b = hsv->b;
            }
            else
            {
              rgb->b = v9;
              rgb->r = b;
            }
          }
          else
          {
            rgb->r = v7;
            rgb->g = v9;
            rgb->b = hsv->b;
          }
        }
        else
        {
          rgb->r = v7;
          v14 = hsv->b;
          rgb->b = v10;
          rgb->g = v14;
        }
      }
      else
      {
        rgb->r = v9;
        v15 = hsv->b;
        rgb->b = v7;
        rgb->g = v15;
      }
    }
    else
    {
      rgb->g = v10;
      rgb->b = v7;
      rgb->r = b;
    }
  }
  else
  {
    rgb->r = hsv->b;
    rgb->g = hsv->b;
    rgb->b = hsv->b;
  }
}

