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
  float v2; // xmm1_4
  float v3; // xmm0_4
  float v4; // xmm4_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm0_4

  hsv->a = rgb->a;
  v2 = rgb->r;
  v3 = rgb->g;
  if ( rgb->r >= v3 )
    v4 = rgb->g;
  else
    v4 = rgb->r;
  v5 = rgb->b;
  if ( v4 >= v5 )
    v4 = rgb->b;
  if ( v2 <= v3 )
    v2 = rgb->g;
  if ( v2 <= v5 )
    v2 = rgb->b;
  hsv->b = v2;
  v6 = v2 - v4;
  if ( v2 <= 0.0 || v6 == 0.0 )
  {
    *(_QWORD *)&hsv->r = 0i64;
    if ( v2 <= 0.0 )
    {
      v2 = 0.0;
    }
    else if ( v2 >= 1.0 )
    {
      LODWORD(hsv->b) = (_DWORD)FLOAT_1_0;
      return;
    }
    hsv->b = v2;
  }
  else
  {
    hsv->g = v6 / v2;
    v7 = rgb->r;
    v8 = rgb->g;
    if ( rgb->r < v2 )
    {
      if ( v8 < v2 )
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
  float v2; // xmm6_4
  float v3; // xmm3_4
  float v4; // xmm3_4
  float v5; // xmm5_4
  signed int v6; // er8
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm2_4
  int v11; // er8
  int v12; // er8
  int v13; // er8
  float v14; // eax
  float v15; // eax

  rgb->a = hsv->a;
  v2 = hsv->g;
  if ( v2 > 0.0 )
  {
    v3 = hsv->r;
    if ( hsv->r >= 360.0 )
      v3 = 0.0;
    v4 = v3 * 0.016666668;
    v5 = hsv->b;
    v6 = (signed int)v4;
    v7 = (float)(1.0 - v2) * v5;
    v8 = v4 - (float)(signed int)v4;
    v9 = (float)(1.0 - (float)(v2 * v8)) * v5;
    v10 = (float)(1.0 - (float)((float)(1.0 - v8) * v2)) * v5;
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
              rgb->r = v5;
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
      rgb->r = v5;
    }
  }
  else
  {
    rgb->r = hsv->b;
    rgb->g = hsv->b;
    rgb->b = hsv->b;
  }
}

