// File Line: 54
// RVA: 0x14608B0
__int64 UFG::_dynamic_initializer_for__uid_FX_Feathered_Circle_2__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("FX_Feathered_Circle_2", -1);
  uid_FX_Feathered_Circle_2 = result;
  return result;
}

// File Line: 55
// RVA: 0x14608D0
__int64 UFG::_dynamic_initializer_for__uid_HUD_Minimap_Outer_Ring__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("HUD_Minimap_Outer_Ring", -1);
  uid_HUD_Minimap_Outer_Ring = result;
  return result;
}

// File Line: 56
// RVA: 0x1460870
__int64 UFG::_dynamic_initializer_for__uid_CopRadiusIndicator__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("CopRadiusIndicator", -1);
  uid_CopRadiusIndicator = result;
  return result;
}

// File Line: 57
// RVA: 0x1460890
__int64 UFG::_dynamic_initializer_for__uid_CopRadiusPulse__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("CopRadiusPulse", -1);
  uid_CopRadiusPulse = result;
  return result;
}

// File Line: 58
// RVA: 0x14608F0
__int64 UFG::_dynamic_initializer_for__uid_Icon_Minimap_TextureSheet__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Icon_Minimap_TextureSheet", -1);
  uid_Icon_Minimap_TextureSheet = result;
  return result;
}

// File Line: 73
// RVA: 0xBB9B0
void __fastcall UFG::UIMapBlipGraphic::UIMapBlipGraphic(UFG::UIMapBlipGraphic *this)
{
  this->mAnimateBlink = 0;
  *(_QWORD *)&this->mBlinkScale = 1065353216i64;
  this->mBlinkTimesMax = 5;
  this->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphic::`vftable;
  this->mIconPoly.Size = 10.0;
  this->mIconPoly.Matrix = 0i64;
  this->mIconPoly.Scale = 1.0;
  this->mIconPoly.Visible = 0;
  this->mPolys[0] = &this->mIconPoly;
  this->mPolys[1] = 0i64;
  this->mPolys[2] = 0i64;
  this->mPolys[3] = 0i64;
  this->mPolys[4] = 0i64;
}

// File Line: 83
// RVA: 0xBD700
void __fastcall UFG::UIMapBlipGraphic::~UIMapBlipGraphic(UFG::UIMapBlipGraphic *this)
{
  void **v1; // rbx
  __int64 v2; // rdi

  v1 = (void **)&this->mPolys[1];
  v2 = 4i64;
  this->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphic::`vftable;
  do
  {
    if ( *v1 )
    {
      operator delete[](*v1);
      *v1 = 0i64;
    }
    ++v1;
    --v2;
  }
  while ( v2 );
}

// File Line: 95
// RVA: 0xBE560
void __fastcall UFG::UIMapBlipGraphic::CalculateUVsFromIndex(
        UFG::UIMapBlipGraphic *this,
        UFG::UIMapBlipGraphic::eIconPolyComps polyType,
        int requestedTexturePageIndex)
{
  __int64 v5; // rsi
  char *v6; // rdx
  unsigned int v7; // ecx
  float v8; // xmm0_4
  unsigned int v9; // eax

  v5 = polyType;
  v6 = (char *)this->mPolys[polyType];
  if ( !v6 )
  {
    v6 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v6 + 13) = 1092616192;
    *((_QWORD *)v6 + 1) = 0i64;
    *((_DWORD *)v6 + 8) = 1065353216;
    v6[72] = 0;
    this->mPolys[v5] = (UFG::UIRenderQuad *)v6;
  }
  switch ( requestedTexturePageIndex )
  {
    case d:
      v9 = uid_FX_Feathered_Circle_2;
      goto LABEL_17;
    case e:
      v9 = uid_HUD_Minimap_Outer_Ring;
      goto LABEL_17;
    case f:
      v9 = uid_CopRadiusIndicator;
      goto LABEL_17;
    case g:
      v9 = uid_CopRadiusPulse;
LABEL_17:
      *(_DWORD *)v6 = v9;
      goto LABEL_18;
  }
  *(_DWORD *)v6 = uid_Icon_Minimap_TextureSheet;
  if ( requestedTexturePageIndex >= 100 )
  {
LABEL_18:
    *((_QWORD *)v6 + 2) = 0i64;
    *((_DWORD *)v6 + 6) = 1065353216;
    *((_DWORD *)v6 + 7) = 1065353216;
    return;
  }
  v7 = requestedTexturePageIndex;
  if ( requestedTexturePageIndex == 99 )
    v7 = 23;
  v8 = (float)(v7 >> 3) * 0.125;
  *((float *)v6 + 4) = (float)(v7 & 7) * 0.125;
  *((_DWORD *)v6 + 6) = 1040187392;
  if ( requestedTexturePageIndex == 99 )
  {
    *((float *)v6 + 5) = v8 + 0.125;
    *((_DWORD *)v6 + 7) = -1107296256;
  }
  else
  {
    *((float *)v6 + 5) = v8;
    *((_DWORD *)v6 + 7) = 1040187392;
  }
}

// File Line: 165
// RVA: 0xCDBF0
void __fastcall UFG::UIMapBlipGraphic::UpdateLocation(UFG::UIMapBlipGraphic *this, float x, float y)
{
  UFG::UIRenderQuad *v3; // rax
  UFG::UIRenderQuad *v4; // rax
  UFG::UIRenderQuad *v5; // rax

  v3 = this->mPolys[0];
  if ( v3 )
  {
    v3->X = x + v3->OffsetX;
    this->mPolys[0]->Y = y + this->mPolys[0]->OffsetY;
  }
  v4 = this->mPolys[1];
  if ( v4 )
  {
    v4->X = x + v4->OffsetX;
    this->mPolys[1]->Y = y + this->mPolys[1]->OffsetY;
  }
  v5 = this->mPolys[2];
  if ( v5 )
  {
    v5->X = x + v5->OffsetX;
    this->mPolys[2]->Y = y + this->mPolys[2]->OffsetY;
  }
  if ( this->mPolys[3] )
  {
    this->mPolys[3]->X = x + this->mPolys[3]->OffsetX;
    this->mPolys[3]->Y = y + this->mPolys[3]->OffsetY;
  }
  if ( this->mPolys[4] )
  {
    this->mPolys[4]->X = x + this->mPolys[4]->OffsetX;
    this->mPolys[4]->Y = y + this->mPolys[4]->OffsetY;
  }
}

// File Line: 182
// RVA: 0xC72C0
void __fastcall UFG::UIMapBlipGraphic::RemovePoly(
        UFG::UIMapBlipGraphic *this,
        UFG::UIMapBlipGraphic::eIconPolyComps polyType)
{
  __int64 v3; // rdi
  char *v4; // rax

  v3 = polyType;
  v4 = (char *)this->mPolys[polyType];
  if ( !v4 )
  {
    v4 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v4 + 13) = 1092616192;
    *((_QWORD *)v4 + 1) = 0i64;
    *((_DWORD *)v4 + 8) = 1065353216;
    v4[72] = 0;
    this->mPolys[v3] = (UFG::UIRenderQuad *)v4;
  }
  v4[72] = 0;
}

// File Line: 201
// RVA: 0xCB320
void __fastcall UFG::UIMapBlipGraphic::SetPos(
        UFG::UIMapBlipGraphic *this,
        UFG::UIMapBlipGraphic::eIconPolyComps polyType,
        float x,
        float y)
{
  __int64 v5; // rdi
  char *v6; // rax

  v5 = polyType;
  v6 = (char *)this->mPolys[polyType];
  if ( !v6 )
  {
    v6 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v6 + 13) = 1092616192;
    *((_QWORD *)v6 + 1) = 0i64;
    *((_DWORD *)v6 + 8) = 1065353216;
    v6[72] = 0;
    this->mPolys[v5] = (UFG::UIRenderQuad *)v6;
  }
  *((float *)v6 + 9) = x;
  *((float *)v6 + 10) = y;
}

// File Line: 208
// RVA: 0xCB270
void __fastcall UFG::UIMapBlipGraphic::SetPolyOffset(
        UFG::UIMapBlipGraphic *this,
        UFG::UIMapBlipGraphic::eIconPolyComps polyType,
        __int16 x,
        __int16 y)
{
  __int64 v7; // rdi
  char *v8; // rdx

  v7 = polyType;
  v8 = (char *)this->mPolys[polyType];
  if ( !v8 )
  {
    v8 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v8 + 13) = 1092616192;
    *((_QWORD *)v8 + 1) = 0i64;
    *((_DWORD *)v8 + 8) = 1065353216;
    v8[72] = 0;
    this->mPolys[v7] = (UFG::UIRenderQuad *)v8;
  }
  *((float *)v8 + 11) = (float)x;
  *((float *)v8 + 12) = (float)y;
}

// File Line: 215
// RVA: 0xCB190
void __fastcall UFG::UIMapBlipGraphic::SetPolyInfo(
        UFG::UIMapBlipGraphic *this,
        UFG::UIMapBlipGraphic::eIconPolyComps polyType,
        float size,
        UFG::qColour *color,
        int texturePageIndex)
{
  __int64 v6; // rdi
  char *v8; // r8

  v6 = polyType;
  v8 = (char *)this->mPolys[polyType];
  if ( !v8 )
  {
    v8 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v8 + 13) = 1092616192;
    *((_QWORD *)v8 + 1) = 0i64;
    *((_DWORD *)v8 + 8) = 1065353216;
    v8[72] = 0;
    this->mPolys[v6] = (UFG::UIRenderQuad *)v8;
  }
  *((_DWORD *)v8 + 14) = LODWORD(color->r);
  *((_DWORD *)v8 + 15) = LODWORD(color->g);
  *((_DWORD *)v8 + 16) = LODWORD(color->b);
  *((_DWORD *)v8 + 17) = LODWORD(color->a);
  *((float *)v8 + 13) = size;
  *(_QWORD *)(v8 + 36) = 0i64;
  *(_QWORD *)(v8 + 44) = 0i64;
  v8[72] = 1;
  UFG::UIMapBlipGraphic::SetAlpha(this, (UFG::UIMapBlipGraphic::eIconPolyComps)v6, 1.0);
  if ( texturePageIndex != -1 )
    UFG::UIMapBlipGraphic::CalculateUVsFromIndex(this, (UFG::UIMapBlipGraphic::eIconPolyComps)v6, texturePageIndex);
}

// File Line: 259
// RVA: 0xCA460
void __fastcall UFG::UIMapBlipGraphic::SetAlpha(
        UFG::UIMapBlipGraphic *this,
        UFG::UIMapBlipGraphic::eIconPolyComps polyType,
        float alpha)
{
  __int64 v4; // rdi
  char *v5; // rax

  v4 = polyType;
  v5 = (char *)this->mPolys[polyType];
  if ( !v5 )
  {
    v5 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v5 + 13) = 1092616192;
    *((_QWORD *)v5 + 1) = 0i64;
    *((_DWORD *)v5 + 8) = 1065353216;
    v5[72] = 0;
    this->mPolys[v4] = (UFG::UIRenderQuad *)v5;
  }
  *((float *)v5 + 17) = alpha;
}

// File Line: 275
// RVA: 0xCB700
void __fastcall UFG::UIMapBlipGraphic::SetScale(
        UFG::UIMapBlipGraphic *this,
        UFG::UIMapBlipGraphic::eIconPolyComps polyType,
        float scale)
{
  __int64 v4; // rdi
  char *v5; // rax

  v4 = polyType;
  v5 = (char *)this->mPolys[polyType];
  if ( !v5 )
  {
    v5 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v5 + 13) = 1092616192;
    *((_QWORD *)v5 + 1) = 0i64;
    *((_DWORD *)v5 + 8) = 1065353216;
    v5[72] = 0;
    this->mPolys[v4] = (UFG::UIRenderQuad *)v5;
  }
  *((float *)v5 + 8) = scale;
}

// File Line: 281
// RVA: 0xCA660
void __fastcall UFG::UIMapBlipGraphic::SetColor(
        UFG::UIMapBlipGraphic *this,
        UFG::UIMapBlipGraphic::eIconPolyComps polyType,
        UFG::qColour *color)
{
  __int64 v5; // rsi
  char *v6; // rdx

  v5 = polyType;
  v6 = (char *)this->mPolys[polyType];
  if ( !v6 )
  {
    v6 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v6 + 13) = 1092616192;
    *((_QWORD *)v6 + 1) = 0i64;
    *((_DWORD *)v6 + 8) = 1065353216;
    v6[72] = 0;
    this->mPolys[v5] = (UFG::UIRenderQuad *)v6;
  }
  *((_DWORD *)v6 + 14) = LODWORD(color->r);
  *((_DWORD *)v6 + 15) = LODWORD(color->g);
  *((_DWORD *)v6 + 16) = LODWORD(color->b);
  *((_DWORD *)v6 + 17) = LODWORD(color->a);
}

// File Line: 287
// RVA: 0xC67C0
void __fastcall UFG::UIMapBlipGraphic::QueueIconToRender(
        UFG::UIMapBlipGraphic *this,
        UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeClipped,
        UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeNotClipped,
        UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeDoubleClipped)
{
  UFG::UIRenderQuad *v5; // rdx
  UFG::UIRenderQuad *v9; // rdx
  UFG::UIRenderQuad *v10; // rdx
  UFG::UIRenderQuad *v11; // rdx
  UFG::UIRenderQuad *v12; // rax

  v5 = this->mPolys[1];
  if ( v5 && v5->Visible && v5->Color.a > 0.001 )
    UFG::qArray<UFG::UIRenderQuad,0>::Add(polyListNativeNotClipped, v5, "qArray.Add");
  v9 = this->mPolys[0];
  if ( v9->Visible && v9->Color.a > 0.001 )
    UFG::qArray<UFG::UIRenderQuad,0>::Add(polyListNativeNotClipped, v9, "qArray.Add");
  v10 = this->mPolys[4];
  if ( v10 && v10->Visible && v10->Color.a > 0.001 )
    UFG::qArray<UFG::UIRenderQuad,0>::Add(polyListNativeNotClipped, v10, "qArray.Add");
  v11 = this->mPolys[2];
  if ( v11 )
  {
    if ( v11->Visible && v11->Color.a > 0.001 )
    {
      v12 = this->mPolys[3];
      if ( v12 )
      {
        if ( v12->Visible && v12->Color.a > 0.001 )
        {
          UFG::qArray<UFG::UIRenderQuad,0>::Add(polyListNativeDoubleClipped, this->mPolys[3], "qArray.Add");
          UFG::qArray<UFG::UIRenderQuad,0>::Add(polyListNativeDoubleClipped, this->mPolys[2], "qArray.Add");
          v11 = this->mPolys[3];
LABEL_21:
          UFG::qArray<UFG::UIRenderQuad,0>::Add(polyListNativeClipped, v11, "qArray.Add");
          return;
        }
      }
    }
    if ( v11->Visible && v11->Color.a > 0.001 )
      goto LABEL_21;
  }
}

// File Line: 322
// RVA: 0xCA4E0
void __fastcall UFG::UIMapBlipGraphic::SetBlink(UFG::UIMapBlipGraphic *this)
{
  UFG::qColour Color; // xmm6
  float v3; // xmm7_4
  UFG::UIRenderQuad *v4; // rax
  UFG::UIRenderQuad *v5; // rcx
  char *v6; // [rsp+60h] [rbp+8h]
  char *v7; // [rsp+60h] [rbp+8h]
  char *v8; // [rsp+60h] [rbp+8h]

  if ( this->mAnimateBlink )
  {
    this->mBlinkTimesLooped = 0;
  }
  else
  {
    this->mAnimateBlink = 1;
    this->mBlinkScale = 0.050000001;
    Color = this->mPolys[0]->Color;
    v3 = (float)dword_142034218;
    if ( !this->mPolys[1] )
    {
      v6 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v6 + 13) = 1092616192;
      *((_QWORD *)v6 + 1) = 0i64;
      *((_DWORD *)v6 + 8) = 1065353216;
      v6[72] = 0;
      this->mPolys[1] = (UFG::UIRenderQuad *)v6;
    }
    v4 = this->mPolys[1];
    v4->Color = Color;
    v4->Size = v3;
    *(_QWORD *)&v4->X = 0i64;
    *(_QWORD *)&v4->OffsetX = 0i64;
    v4->Visible = 1;
    if ( !this->mPolys[1] )
    {
      v7 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v7 + 13) = 1092616192;
      *((_QWORD *)v7 + 1) = 0i64;
      *((_DWORD *)v7 + 8) = 1065353216;
      v7[72] = 0;
      this->mPolys[1] = (UFG::UIRenderQuad *)v7;
    }
    this->mPolys[1]->Color.a = 1.0;
    if ( !this->mPolys[1] )
    {
      v8 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v8 + 13) = 1092616192;
      *((_QWORD *)v8 + 1) = 0i64;
      *((_DWORD *)v8 + 8) = 1065353216;
      v8[72] = 0;
      this->mPolys[1] = (UFG::UIRenderQuad *)v8;
    }
    v5 = this->mPolys[1];
    v5->TextureID = uid_CopRadiusPulse;
    *(_QWORD *)v5->UVs = 0i64;
    v5->UVs[2] = 1.0;
    v5->UVs[3] = 1.0;
    UFG::UIMapBlipGraphic::SetScale(this, PulseAnimPoly, this->mBlinkScale);
    this->mBlinkTimesLooped = 0;
  }
}

// File Line: 338
// RVA: 0xCB980
void __fastcall UFG::UIMapBlipGraphic::StopBlink(UFG::UIMapBlipGraphic *this)
{
  char *v2; // [rsp+40h] [rbp+8h]

  if ( this->mAnimateBlink )
  {
    this->mAnimateBlink = 0;
    if ( !this->mPolys[1] )
    {
      v2 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v2 + 13) = 1092616192;
      *((_QWORD *)v2 + 1) = 0i64;
      *((_DWORD *)v2 + 8) = 1065353216;
      v2[72] = 0;
      this->mPolys[1] = (UFG::UIRenderQuad *)v2;
    }
    this->mPolys[1]->Visible = 0;
  }
}

// File Line: 347
// RVA: 0xCD150
void __fastcall UFG::UIMapBlipGraphic::UpdateAnimation(UFG::UIMapBlipGraphic *this)
{
  float v2; // xmm0_4
  float mBlinkScale; // xmm2_4
  float v4; // xmm6_4

  if ( this->mAnimateBlink )
  {
    v2 = this->mBlinkScale + 0.12;
    this->mBlinkScale = v2;
    if ( v2 > 4.0 )
    {
      if ( ++this->mBlinkTimesLooped >= this->mBlinkTimesMax )
      {
        this->mAnimateBlink = 0;
        UFG::UIMapBlipGraphic::RemovePoly(this, PulseAnimPoly);
        return;
      }
      this->mBlinkScale = 0.050000001;
    }
    mBlinkScale = this->mBlinkScale;
    v4 = 1.0 - (float)((float)(mBlinkScale - 1.2) * 0.35714287);
    if ( v4 >= 1.0 )
      v4 = *(float *)&FLOAT_1_0;
    UFG::UIMapBlipGraphic::SetScale(this, PulseAnimPoly, mBlinkScale);
    UFG::UIMapBlipGraphic::SetAlpha(this, PulseAnimPoly, v4);
  }
}

// File Line: 373
// RVA: 0xCD3A0
void __fastcall UFG::UIMapBlipGraphicWitness::UpdateAnimation(UFG::UIMapBlipGraphicWitness *this)
{
  float v1; // xmm0_4

  if ( this->mPulse )
  {
    v1 = this->mAlpha - rampVal;
    if ( v1 <= 0.001 )
    {
      v1 = FLOAT_0_001;
    }
    else if ( v1 >= 0.99000001 )
    {
      this->mAlpha = FLOAT_0_99000001;
      UFG::UIMapBlipGraphic::SetAlpha(this, IconPoly, 0.99000001);
      return;
    }
    this->mAlpha = v1;
    UFG::UIMapBlipGraphic::SetAlpha(this, IconPoly, v1);
  }
}

// File Line: 384
// RVA: 0xCD200
void __fastcall UFG::UIMapBlipGraphicCop::UpdateAnimation(UFG::UIMapBlipGraphicCop *this)
{
  float v2; // xmm0_4
  UFG::qColour *p_mColor; // r8
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm6_4
  float v9; // xmm5_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm3_4
  float v17; // xmm5_4
  float v18; // xmm4_4
  UFG::UIHKScreenHud *Instance; // rax
  float MapZoomFactor; // xmm0_4

  v2 = sinf((float)(int)this->mFrameCount * 0.1);
  p_mColor = &this->mColor;
  this->mWeight = v2;
  if ( v2 <= 0.0 )
  {
    v12 = UFG::qColour::Red.g * COERCE_FLOAT(LODWORD(v2) & _xmm);
    v13 = 1.0 - COERCE_FLOAT(LODWORD(v2) & _xmm);
    v14 = UFG::qColour::Red.b * COERCE_FLOAT(LODWORD(v2) & _xmm);
    v15 = v13 * UFG::qColour::White.r;
    v16 = v13 * UFG::qColour::White.g;
    v17 = v13 * UFG::qColour::White.b;
    v18 = v15 + (float)(UFG::qColour::Red.r * COERCE_FLOAT(LODWORD(v2) & _xmm));
    v11 = UFG::qColour::Red.a + UFG::qColour::White.a;
    p_mColor->r = v18;
    this->mColor.g = v16 + v12;
    this->mColor.b = v17 + v14;
  }
  else
  {
    v4 = UFG::qColour::DogerBlue.r * v2;
    v5 = UFG::qColour::DogerBlue.g * v2;
    v6 = UFG::qColour::DogerBlue.b * v2;
    v7 = 1.0 - v2;
    v8 = UFG::qColour::White.r * v7;
    v9 = UFG::qColour::White.g * v7;
    v10 = UFG::qColour::White.b * v7;
    v11 = UFG::qColour::White.a + UFG::qColour::DogerBlue.a;
    p_mColor->r = v8 + v4;
    this->mColor.g = v9 + v5;
    this->mColor.b = v10 + v6;
  }
  this->mColor.a = v11;
  UFG::UIMapBlipGraphic::SetColor(this, IconPoly, p_mColor);
  ++this->mFrameCount;
  Instance = UFG::UIHKScreenHud::getInstance();
  if ( Instance )
  {
    MapZoomFactor = UFG::UIHKScreenHud::GetMapZoomFactor(Instance);
    UFG::UIMapBlipGraphic::SetScale(this, PulseAnimPoly, MapZoomFactor);
  }
}

// File Line: 474
// RVA: 0xC1540
UFG::UIMapBlipGraphic *__fastcall UFG::UIMapBlipGraphicFactory::GetNativeIconInstance(
        UFG::UIMapBlipGraphicFactory *this,
        UFG::qSymbol *type)
{
  int v2; // esi
  unsigned int mUID; // eax
  char *v4; // rax
  char *v5; // rax
  char *v6; // rbx
  UFG::qColour v7; // xmm6
  __int64 v8; // rcx
  __int64 v9; // rcx
  char *v10; // rax
  UFG::qColour v11; // xmm6
  __int64 v12; // rcx
  __int64 v13; // rcx
  char *v14; // rax
  UFG::qColour v15; // xmm6
  __int64 v16; // rcx
  _DWORD *v17; // rcx
  char *v18; // rax
  char *v19; // rax
  UFG::qColour v20; // xmm0
  char *v21; // rax
  char *v22; // rax
  char *v23; // rax
  char *v24; // rax
  char *v25; // rax
  char *v26; // rax
  char *v27; // rax
  char *v28; // rax
  char *v29; // rax
  char *v30; // rax
  char *v31; // rax
  char *v32; // rax
  char *v33; // rax
  char *v34; // rax
  char *v35; // rax
  char *v36; // rax
  char *v37; // rax
  char *v38; // rax
  char *v39; // rax
  char *v40; // rax
  char *v41; // rax
  char *v42; // rax
  char *v43; // rax
  char *v44; // rax
  char *v45; // rax
  char *v46; // rax
  char *v47; // rax
  char *v48; // rax
  char *v49; // rax
  char *v50; // rax
  char *v51; // rax
  char *v52; // rax
  char *v53; // rax
  char *v54; // rax
  char *v55; // rax
  char *v56; // rax
  char *v57; // rax
  char *v58; // rax
  char *v59; // rax
  char *v60; // rax
  char *v61; // rax
  char *v62; // rax
  char *v63; // rax
  char *v64; // rax
  char *v65; // rax
  char *v66; // rax
  char *v67; // rax
  char *v68; // rax
  char *v69; // rax
  char *v70; // rax
  char *v71; // rax
  char *v72; // rax
  char *v73; // rax
  char *v74; // rax
  char *v75; // rax
  char *v76; // rax
  char *v77; // rax
  char *v78; // rax
  char *v79; // rax
  char *v80; // rax
  char *v81; // rax
  char *v82; // rax
  char *v83; // rax
  char *v84; // rax
  char *v85; // rax
  char *v86; // rax
  char *v87; // rax
  char *v88; // rax
  char *v89; // rax
  char *v90; // rax
  char *v91; // rax
  char *v92; // rax
  char *v93; // rax
  char *v94; // rax
  char *v95; // rax
  char *v96; // rax
  char *v97; // rax
  char *v98; // rax
  char *v99; // rax
  char *v100; // rax
  char *v101; // rax
  char *v102; // rax
  char *v103; // rax
  char *v104; // rax
  char *v105; // rax
  char *v106; // rax
  char *v107; // rax
  char *v108; // rax
  char *v109; // rax
  char *v110; // rax
  char *v111; // rax
  char *v112; // rax
  char *v113; // rax
  char *v114; // rax
  char *v115; // rax
  char *v116; // rax
  char *v117; // rax
  __int64 v118; // rax
  char *v119; // rax
  int v121; // [rsp+20h] [rbp-40h]
  __int128 v122; // [rsp+40h] [rbp-20h] BYREF
  char *v123; // [rsp+78h] [rbp+18h]
  char *v124; // [rsp+78h] [rbp+18h]
  char *v125; // [rsp+78h] [rbp+18h]
  char *v126; // [rsp+78h] [rbp+18h]
  char *v127; // [rsp+78h] [rbp+18h]
  char *v128; // [rsp+78h] [rbp+18h]
  char *v129; // [rsp+78h] [rbp+18h]
  char *v130; // [rsp+78h] [rbp+18h]
  char *v131; // [rsp+78h] [rbp+18h]

  v2 = dword_142034218;
  mUID = type->mUID;
  if ( type->mUID == UIBlipIcon_Player_Arrow.mUID )
  {
    v4 = UFG::qMalloc(0xD0ui64, "UIMapBlipGraphicFactory", 0i64);
    if ( v4 )
    {
      UFG::UIMapBlipGraphicPlayerArrow::UIMapBlipGraphicPlayerArrow((UFG::UIMapBlipGraphicPlayerArrow *)v4);
      v6 = v5;
    }
    else
    {
      v6 = 0i64;
    }
    v7 = UFG::qColour::White;
    if ( !*((_QWORD *)v6 + 3) )
    {
      v123 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v123 + 13) = 1092616192;
      *((_QWORD *)v123 + 1) = 0i64;
      *((_DWORD *)v123 + 8) = 1065353216;
      v123[72] = 0;
      *((_QWORD *)v6 + 3) = v123;
    }
    v8 = *((_QWORD *)v6 + 3);
    *(UFG::qColour *)(v8 + 56) = v7;
    *(float *)(v8 + 52) = (float)v2;
    *(_QWORD *)(v8 + 36) = 0i64;
    *(_QWORD *)(v8 + 44) = 0i64;
    *(_BYTE *)(v8 + 72) = 1;
    if ( !*((_QWORD *)v6 + 3) )
    {
      v124 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v124 + 13) = 1092616192;
      *((_QWORD *)v124 + 1) = 0i64;
      *((_DWORD *)v124 + 8) = 1065353216;
      v124[72] = 0;
      *((_QWORD *)v6 + 3) = v124;
    }
    *(_DWORD *)(*((_QWORD *)v6 + 3) + 68i64) = 1065353216;
    if ( !*((_QWORD *)v6 + 3) )
    {
      v125 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v125 + 13) = 1092616192;
      *((_QWORD *)v125 + 1) = 0i64;
      *((_DWORD *)v125 + 8) = 1065353216;
      v125[72] = 0;
      *((_QWORD *)v6 + 3) = v125;
    }
    v9 = *((_QWORD *)v6 + 3);
    *(_DWORD *)v9 = uid_Icon_Minimap_TextureSheet;
    *(_QWORD *)(v9 + 16) = 0i64;
    *(_DWORD *)(v9 + 24) = 1040187392;
    *(_DWORD *)(v9 + 28) = 1040187392;
    return (UFG::UIMapBlipGraphic *)v6;
  }
  if ( mUID == UIBlipIcon_Waypoint.mUID )
  {
    v10 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
    v6 = v10;
    if ( v10 )
    {
      *(_QWORD *)v10 = &UFG::UIMapBlipGraphic::`vftable;
      v10[8] = 0;
      *(_QWORD *)(v10 + 12) = 1065353216i64;
      *((_DWORD *)v10 + 5) = 5;
      *((_DWORD *)v10 + 29) = 1092616192;
      *((_QWORD *)v10 + 9) = 0i64;
      *((_DWORD *)v10 + 24) = 1065353216;
      v10[136] = 0;
      *((_QWORD *)v10 + 3) = v10 + 64;
      *((_QWORD *)v10 + 4) = 0i64;
      *((_QWORD *)v10 + 5) = 0i64;
      *((_QWORD *)v10 + 6) = 0i64;
      *((_QWORD *)v10 + 7) = 0i64;
    }
    else
    {
      v6 = 0i64;
    }
    v11 = UFG::qColour::White;
    if ( !*((_QWORD *)v6 + 3) )
    {
      v126 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v126 + 13) = 1092616192;
      *((_QWORD *)v126 + 1) = 0i64;
      *((_DWORD *)v126 + 8) = 1065353216;
      v126[72] = 0;
      *((_QWORD *)v6 + 3) = v126;
    }
    v12 = *((_QWORD *)v6 + 3);
    *(UFG::qColour *)(v12 + 56) = v11;
    *(float *)(v12 + 52) = (float)v2;
    *(_QWORD *)(v12 + 36) = 0i64;
    *(_QWORD *)(v12 + 44) = 0i64;
    *(_BYTE *)(v12 + 72) = 1;
    if ( !*((_QWORD *)v6 + 3) )
    {
      v127 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v127 + 13) = 1092616192;
      *((_QWORD *)v127 + 1) = 0i64;
      *((_DWORD *)v127 + 8) = 1065353216;
      v127[72] = 0;
      *((_QWORD *)v6 + 3) = v127;
    }
    *(_DWORD *)(*((_QWORD *)v6 + 3) + 68i64) = 1065353216;
    if ( !*((_QWORD *)v6 + 3) )
    {
      v128 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v128 + 13) = 1092616192;
      *((_QWORD *)v128 + 1) = 0i64;
      *((_DWORD *)v128 + 8) = 1065353216;
      v128[72] = 0;
      *((_QWORD *)v6 + 3) = v128;
    }
    v13 = *((_QWORD *)v6 + 3);
    *(_DWORD *)v13 = uid_Icon_Minimap_TextureSheet;
    *(_QWORD *)(v13 + 16) = 1052770304i64;
    *(_DWORD *)(v13 + 24) = 1040187392;
    *(_DWORD *)(v13 + 28) = 1040187392;
    return (UFG::UIMapBlipGraphic *)v6;
  }
  if ( mUID != UIBlipIcon_Safehouse.mUID )
  {
    if ( mUID == UIBlipIcon_Safehouse_Unlocked.mUID )
    {
      v18 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v18;
      if ( v18 )
      {
        *(_QWORD *)v18 = &UFG::UIMapBlipGraphic::`vftable;
        v18[8] = 0;
        *(_QWORD *)(v18 + 12) = 1065353216i64;
        *((_DWORD *)v18 + 5) = 5;
        *((_DWORD *)v18 + 29) = 1092616192;
        *((_QWORD *)v18 + 9) = 0i64;
        *((_DWORD *)v18 + 24) = 1065353216;
        v18[136] = 0;
        *((_QWORD *)v18 + 3) = v18 + 64;
        *((_QWORD *)v18 + 4) = 0i64;
        *((_QWORD *)v18 + 5) = 0i64;
        *((_QWORD *)v18 + 6) = 0i64;
        *((_QWORD *)v18 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v121 = 12;
      goto LABEL_474;
    }
    if ( mUID == UIBlipIcon_Undercover_Safehouse.mUID )
    {
      v19 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v19;
      if ( v19 )
      {
        *(_QWORD *)v19 = &UFG::UIMapBlipGraphic::`vftable;
        v19[8] = 0;
        *(_QWORD *)(v19 + 12) = 1065353216i64;
        *((_DWORD *)v19 + 5) = 5;
        *((_DWORD *)v19 + 29) = 1092616192;
        *((_QWORD *)v19 + 9) = 0i64;
        *((_DWORD *)v19 + 24) = 1065353216;
        v19[136] = 0;
        *((_QWORD *)v19 + 3) = v19 + 64;
        *((_QWORD *)v19 + 4) = 0i64;
        *((_QWORD *)v19 + 5) = 0i64;
        *((_QWORD *)v19 + 6) = 0i64;
        *((_QWORD *)v19 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveBlue;
      v121 = 12;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_TriadWars_Safehouse.mUID )
    {
      v21 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v21;
      if ( v21 )
      {
        *(_QWORD *)v21 = &UFG::UIMapBlipGraphic::`vftable;
        v21[8] = 0;
        *(_QWORD *)(v21 + 12) = 1065353216i64;
        *((_DWORD *)v21 + 5) = 5;
        *((_DWORD *)v21 + 29) = 1092616192;
        *((_QWORD *)v21 + 9) = 0i64;
        *((_DWORD *)v21 + 24) = 1065353216;
        v21[136] = 0;
        *((_QWORD *)v21 + 3) = v21 + 64;
        *((_QWORD *)v21 + 4) = 0i64;
        *((_QWORD *)v21 + 5) = 0i64;
        *((_QWORD *)v21 + 6) = 0i64;
        *((_QWORD *)v21 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::AmbientBlue;
      v121 = 12;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Mission_Start.mUID )
    {
      v22 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      if ( v22 )
      {
        UFG::UIMapBlipGraphicMissionObjective::UIMapBlipGraphicMissionObjective((UFG::UIMapBlipGraphicMissionObjective *)v22);
        v6 = v23;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveGreen;
      v121 = 4;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Mission_Objective.mUID )
    {
      v24 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      if ( v24 )
      {
        UFG::UIMapBlipGraphicMissionObjective::UIMapBlipGraphicMissionObjective((UFG::UIMapBlipGraphicMissionObjective *)v24);
        v6 = v25;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveGreen;
      v121 = 3;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Race_Start.mUID )
    {
      v26 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v26;
      if ( v26 )
      {
        *(_QWORD *)v26 = &UFG::UIMapBlipGraphic::`vftable;
        v26[8] = 0;
        *(_QWORD *)(v26 + 12) = 1065353216i64;
        *((_DWORD *)v26 + 5) = 5;
        *((_DWORD *)v26 + 29) = 1092616192;
        *((_QWORD *)v26 + 9) = 0i64;
        *((_DWORD *)v26 + 24) = 1065353216;
        v26[136] = 0;
        *((_QWORD *)v26 + 3) = v26 + 64;
        *((_QWORD *)v26 + 4) = 0i64;
        *((_QWORD *)v26 + 5) = 0i64;
        *((_QWORD *)v26 + 6) = 0i64;
        *((_QWORD *)v26 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveOrange;
      v121 = 22;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Race_Start_Flag.mUID )
    {
      v27 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v27;
      if ( v27 )
      {
        *(_QWORD *)v27 = &UFG::UIMapBlipGraphic::`vftable;
        v27[8] = 0;
        *(_QWORD *)(v27 + 12) = 1065353216i64;
        *((_DWORD *)v27 + 5) = 5;
        *((_DWORD *)v27 + 29) = 1092616192;
        *((_QWORD *)v27 + 9) = 0i64;
        *((_DWORD *)v27 + 24) = 1065353216;
        v27[136] = 0;
        *((_QWORD *)v27 + 3) = v27 + 64;
        *((_QWORD *)v27 + 4) = 0i64;
        *((_QWORD *)v27 + 5) = 0i64;
        *((_QWORD *)v27 + 6) = 0i64;
        *((_QWORD *)v27 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveOrange;
      v121 = 22;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Race_Objective.mUID )
    {
      v28 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v28;
      if ( v28 )
      {
        *(_QWORD *)v28 = &UFG::UIMapBlipGraphic::`vftable;
        v28[8] = 0;
        *(_QWORD *)(v28 + 12) = 1065353216i64;
        *((_DWORD *)v28 + 5) = 5;
        *((_DWORD *)v28 + 29) = 1092616192;
        *((_QWORD *)v28 + 9) = 0i64;
        *((_DWORD *)v28 + 24) = 1065353216;
        v28[136] = 0;
        *((_QWORD *)v28 + 3) = v28 + 64;
        *((_QWORD *)v28 + 4) = 0i64;
        *((_QWORD *)v28 + 5) = 0i64;
        *((_QWORD *)v28 + 6) = 0i64;
        *((_QWORD *)v28 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveRed;
      v121 = 14;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Race_End.mUID )
    {
      v29 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v29;
      if ( v29 )
      {
        *(_QWORD *)v29 = &UFG::UIMapBlipGraphic::`vftable;
        v29[8] = 0;
        *(_QWORD *)(v29 + 12) = 1065353216i64;
        *((_DWORD *)v29 + 5) = 5;
        *((_DWORD *)v29 + 29) = 1092616192;
        *((_QWORD *)v29 + 9) = 0i64;
        *((_DWORD *)v29 + 24) = 1065353216;
        v29[136] = 0;
        *((_QWORD *)v29 + 3) = v29 + 64;
        *((_QWORD *)v29 + 4) = 0i64;
        *((_QWORD *)v29 + 5) = 0i64;
        *((_QWORD *)v29 + 6) = 0i64;
        *((_QWORD *)v29 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveOrange;
      v121 = 22;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Cop_Event_Start.mUID )
    {
      v30 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v30;
      if ( v30 )
      {
        *(_QWORD *)v30 = &UFG::UIMapBlipGraphic::`vftable;
        v30[8] = 0;
        *(_QWORD *)(v30 + 12) = 1065353216i64;
        *((_DWORD *)v30 + 5) = 5;
        *((_DWORD *)v30 + 29) = 1092616192;
        *((_QWORD *)v30 + 9) = 0i64;
        *((_DWORD *)v30 + 24) = 1065353216;
        v30[136] = 0;
        *((_QWORD *)v30 + 3) = v30 + 64;
        *((_QWORD *)v30 + 4) = 0i64;
        *((_QWORD *)v30 + 5) = 0i64;
        *((_QWORD *)v30 + 6) = 0i64;
        *((_QWORD *)v30 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveBlue;
      v121 = 37;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Event_Start.mUID )
    {
      v31 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v31;
      if ( v31 )
      {
        *(_QWORD *)v31 = &UFG::UIMapBlipGraphic::`vftable;
        v31[8] = 0;
        *(_QWORD *)(v31 + 12) = 1065353216i64;
        *((_DWORD *)v31 + 5) = 5;
        *((_DWORD *)v31 + 29) = 1092616192;
        *((_QWORD *)v31 + 9) = 0i64;
        *((_DWORD *)v31 + 24) = 1065353216;
        v31[136] = 0;
        *((_QWORD *)v31 + 3) = v31 + 64;
        *((_QWORD *)v31 + 4) = 0i64;
        *((_QWORD *)v31 + 5) = 0i64;
        *((_QWORD *)v31 + 6) = 0i64;
        *((_QWORD *)v31 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveYellow;
      v121 = 36;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Event_Objective.mUID )
    {
      v32 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      if ( v32 )
      {
        UFG::UIMapBlipGraphicEventObjective::UIMapBlipGraphicEventObjective((UFG::UIMapBlipGraphicEventObjective *)v32);
        v6 = v33;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveYellow;
      v121 = 36;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Case_Start.mUID )
    {
      v34 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v34;
      if ( v34 )
      {
        *(_QWORD *)v34 = &UFG::UIMapBlipGraphic::`vftable;
        v34[8] = 0;
        *(_QWORD *)(v34 + 12) = 1065353216i64;
        *((_DWORD *)v34 + 5) = 5;
        *((_DWORD *)v34 + 29) = 1092616192;
        *((_QWORD *)v34 + 9) = 0i64;
        *((_DWORD *)v34 + 24) = 1065353216;
        v34[136] = 0;
        *((_QWORD *)v34 + 3) = v34 + 64;
        *((_QWORD *)v34 + 4) = 0i64;
        *((_QWORD *)v34 + 5) = 0i64;
        *((_QWORD *)v34 + 6) = 0i64;
        *((_QWORD *)v34 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveBlue;
      v121 = 35;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Case_Objective.mUID )
    {
      v35 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v35;
      if ( v35 )
      {
        *(_QWORD *)v35 = &UFG::UIMapBlipGraphic::`vftable;
        v35[8] = 0;
        *(_QWORD *)(v35 + 12) = 1065353216i64;
        *((_DWORD *)v35 + 5) = 5;
        *((_DWORD *)v35 + 29) = 1092616192;
        *((_QWORD *)v35 + 9) = 0i64;
        *((_DWORD *)v35 + 24) = 1065353216;
        v35[136] = 0;
        *((_QWORD *)v35 + 3) = v35 + 64;
        *((_QWORD *)v35 + 4) = 0i64;
        *((_QWORD *)v35 + 5) = 0i64;
        *((_QWORD *)v35 + 6) = 0i64;
        *((_QWORD *)v35 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveBlue;
      v121 = 35;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Job_Start.mUID )
    {
      v36 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v36;
      if ( v36 )
      {
        *(_QWORD *)v36 = &UFG::UIMapBlipGraphic::`vftable;
        v36[8] = 0;
        *(_QWORD *)(v36 + 12) = 1065353216i64;
        *((_DWORD *)v36 + 5) = 5;
        *((_DWORD *)v36 + 29) = 1092616192;
        *((_QWORD *)v36 + 9) = 0i64;
        *((_DWORD *)v36 + 24) = 1065353216;
        v36[136] = 0;
        *((_QWORD *)v36 + 3) = v36 + 64;
        *((_QWORD *)v36 + 4) = 0i64;
        *((_QWORD *)v36 + 5) = 0i64;
        *((_QWORD *)v36 + 6) = 0i64;
        *((_QWORD *)v36 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveOrange;
      v121 = 4;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Job_Objective.mUID )
    {
      v37 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v37;
      if ( v37 )
      {
        *(_QWORD *)v37 = &UFG::UIMapBlipGraphic::`vftable;
        v37[8] = 0;
        *(_QWORD *)(v37 + 12) = 1065353216i64;
        *((_DWORD *)v37 + 5) = 5;
        *((_DWORD *)v37 + 29) = 1092616192;
        *((_QWORD *)v37 + 9) = 0i64;
        *((_DWORD *)v37 + 24) = 1065353216;
        v37[136] = 0;
        *((_QWORD *)v37 + 3) = v37 + 64;
        *((_QWORD *)v37 + 4) = 0i64;
        *((_QWORD *)v37 + 5) = 0i64;
        *((_QWORD *)v37 + 6) = 0i64;
        *((_QWORD *)v37 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveOrange;
      v121 = 3;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Cop_Job.mUID )
    {
      v38 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v38;
      if ( v38 )
      {
        *(_QWORD *)v38 = &UFG::UIMapBlipGraphic::`vftable;
        v38[8] = 0;
        *(_QWORD *)(v38 + 12) = 1065353216i64;
        *((_DWORD *)v38 + 5) = 5;
        *((_DWORD *)v38 + 29) = 1092616192;
        *((_QWORD *)v38 + 9) = 0i64;
        *((_DWORD *)v38 + 24) = 1065353216;
        v38[136] = 0;
        *((_QWORD *)v38 + 3) = v38 + 64;
        *((_QWORD *)v38 + 4) = 0i64;
        *((_QWORD *)v38 + 5) = 0i64;
        *((_QWORD *)v38 + 6) = 0i64;
        *((_QWORD *)v38 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveYellow;
      v121 = 3;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Crime_Scene.mUID )
    {
      v39 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v39;
      if ( v39 )
      {
        *(_QWORD *)v39 = &UFG::UIMapBlipGraphic::`vftable;
        v39[8] = 0;
        *(_QWORD *)(v39 + 12) = 1065353216i64;
        *((_DWORD *)v39 + 5) = 5;
        *((_DWORD *)v39 + 29) = 1092616192;
        *((_QWORD *)v39 + 9) = 0i64;
        *((_DWORD *)v39 + 24) = 1065353216;
        v39[136] = 0;
        *((_QWORD *)v39 + 3) = v39 + 64;
        *((_QWORD *)v39 + 4) = 0i64;
        *((_QWORD *)v39 + 5) = 0i64;
        *((_QWORD *)v39 + 6) = 0i64;
        *((_QWORD *)v39 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveYellow;
      v121 = 3;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Enemy_Objective.mUID )
    {
      v40 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v40;
      if ( v40 )
      {
        *(_QWORD *)v40 = &UFG::UIMapBlipGraphic::`vftable;
        v40[8] = 0;
        *(_QWORD *)(v40 + 12) = 1065353216i64;
        *((_DWORD *)v40 + 5) = 5;
        *((_DWORD *)v40 + 29) = 1092616192;
        *((_QWORD *)v40 + 9) = 0i64;
        *((_DWORD *)v40 + 24) = 1065353216;
        v40[136] = 0;
        *((_QWORD *)v40 + 3) = v40 + 64;
        *((_QWORD *)v40 + 4) = 0i64;
        *((_QWORD *)v40 + 5) = 0i64;
        *((_QWORD *)v40 + 6) = 0i64;
        *((_QWORD *)v40 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveRed;
      v121 = 3;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Cop_Objective.mUID )
    {
      v41 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v41;
      if ( v41 )
      {
        *(_QWORD *)v41 = &UFG::UIMapBlipGraphic::`vftable;
        v41[8] = 0;
        *(_QWORD *)(v41 + 12) = 1065353216i64;
        *((_DWORD *)v41 + 5) = 5;
        *((_DWORD *)v41 + 29) = 1092616192;
        *((_QWORD *)v41 + 9) = 0i64;
        *((_DWORD *)v41 + 24) = 1065353216;
        v41[136] = 0;
        *((_QWORD *)v41 + 3) = v41 + 64;
        *((_QWORD *)v41 + 4) = 0i64;
        *((_QWORD *)v41 + 5) = 0i64;
        *((_QWORD *)v41 + 6) = 0i64;
        *((_QWORD *)v41 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveBlue;
      v121 = 3;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Triad_Wars.mUID )
    {
      v42 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v42;
      if ( v42 )
      {
        *(_QWORD *)v42 = &UFG::UIMapBlipGraphic::`vftable;
        v42[8] = 0;
        *(_QWORD *)(v42 + 12) = 1065353216i64;
        *((_DWORD *)v42 + 5) = 5;
        *((_DWORD *)v42 + 29) = 1092616192;
        *((_QWORD *)v42 + 9) = 0i64;
        *((_DWORD *)v42 + 24) = 1065353216;
        v42[136] = 0;
        *((_QWORD *)v42 + 3) = v42 + 64;
        *((_QWORD *)v42 + 4) = 0i64;
        *((_QWORD *)v42 + 5) = 0i64;
        *((_QWORD *)v42 + 6) = 0i64;
        *((_QWORD *)v42 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::AmbientBlue;
      v121 = 27;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_TransTerror_Start.mUID )
    {
      v43 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v43;
      if ( v43 )
      {
        *(_QWORD *)v43 = &UFG::UIMapBlipGraphic::`vftable;
        v43[8] = 0;
        *(_QWORD *)(v43 + 12) = 1065353216i64;
        *((_DWORD *)v43 + 5) = 5;
        *((_DWORD *)v43 + 29) = 1092616192;
        *((_QWORD *)v43 + 9) = 0i64;
        *((_DWORD *)v43 + 24) = 1065353216;
        v43[136] = 0;
        *((_QWORD *)v43 + 3) = v43 + 64;
        *((_QWORD *)v43 + 4) = 0i64;
        *((_QWORD *)v43 + 5) = 0i64;
        *((_QWORD *)v43 + 6) = 0i64;
        *((_QWORD *)v43 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::TransTerrorOrange;
      v121 = 14;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_TransTerror_Mission.mUID )
    {
      v44 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v44;
      if ( v44 )
      {
        *(_QWORD *)v44 = &UFG::UIMapBlipGraphic::`vftable;
        v44[8] = 0;
        *(_QWORD *)(v44 + 12) = 1065353216i64;
        *((_DWORD *)v44 + 5) = 5;
        *((_DWORD *)v44 + 29) = 1092616192;
        *((_QWORD *)v44 + 9) = 0i64;
        *((_DWORD *)v44 + 24) = 1065353216;
        v44[136] = 0;
        *((_QWORD *)v44 + 3) = v44 + 64;
        *((_QWORD *)v44 + 4) = 0i64;
        *((_QWORD *)v44 + 5) = 0i64;
        *((_QWORD *)v44 + 6) = 0i64;
        *((_QWORD *)v44 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::TransTerrorOrange;
      v121 = 3;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_TransTerror_Event.mUID )
    {
      v45 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v45;
      if ( v45 )
      {
        *(_QWORD *)v45 = &UFG::UIMapBlipGraphic::`vftable;
        v45[8] = 0;
        *(_QWORD *)(v45 + 12) = 1065353216i64;
        *((_DWORD *)v45 + 5) = 5;
        *((_DWORD *)v45 + 29) = 1092616192;
        *((_QWORD *)v45 + 9) = 0i64;
        *((_DWORD *)v45 + 24) = 1065353216;
        v45[136] = 0;
        *((_QWORD *)v45 + 3) = v45 + 64;
        *((_QWORD *)v45 + 4) = 0i64;
        *((_QWORD *)v45 + 5) = 0i64;
        *((_QWORD *)v45 + 6) = 0i64;
        *((_QWORD *)v45 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::TransTerrorOrange;
      v121 = 33;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Zodiac_Start.mUID )
    {
      v46 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v46;
      if ( v46 )
      {
        *(_QWORD *)v46 = &UFG::UIMapBlipGraphic::`vftable;
        v46[8] = 0;
        *(_QWORD *)(v46 + 12) = 1065353216i64;
        *((_DWORD *)v46 + 5) = 5;
        *((_DWORD *)v46 + 29) = 1092616192;
        *((_QWORD *)v46 + 9) = 0i64;
        *((_DWORD *)v46 + 24) = 1065353216;
        v46[136] = 0;
        *((_QWORD *)v46 + 3) = v46 + 64;
        *((_QWORD *)v46 + 4) = 0i64;
        *((_QWORD *)v46 + 5) = 0i64;
        *((_QWORD *)v46 + 6) = 0i64;
        *((_QWORD *)v46 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ZodiacOrange;
      v121 = 17;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Zodiac_Objective.mUID )
    {
      v47 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v47;
      if ( v47 )
      {
        *(_QWORD *)v47 = &UFG::UIMapBlipGraphic::`vftable;
        v47[8] = 0;
        *(_QWORD *)(v47 + 12) = 1065353216i64;
        *((_DWORD *)v47 + 5) = 5;
        *((_DWORD *)v47 + 29) = 1092616192;
        *((_QWORD *)v47 + 9) = 0i64;
        *((_DWORD *)v47 + 24) = 1065353216;
        v47[136] = 0;
        *((_QWORD *)v47 + 3) = v47 + 64;
        *((_QWORD *)v47 + 4) = 0i64;
        *((_QWORD *)v47 + 5) = 0i64;
        *((_QWORD *)v47 + 6) = 0i64;
        *((_QWORD *)v47 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ZodiacOrange;
      v121 = 3;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Zodiac_Event.mUID )
    {
      v48 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v48;
      if ( v48 )
      {
        *(_QWORD *)v48 = &UFG::UIMapBlipGraphic::`vftable;
        v48[8] = 0;
        *(_QWORD *)(v48 + 12) = 1065353216i64;
        *((_DWORD *)v48 + 5) = 5;
        *((_DWORD *)v48 + 29) = 1092616192;
        *((_QWORD *)v48 + 9) = 0i64;
        *((_DWORD *)v48 + 24) = 1065353216;
        v48[136] = 0;
        *((_QWORD *)v48 + 3) = v48 + 64;
        *((_QWORD *)v48 + 4) = 0i64;
        *((_QWORD *)v48 + 5) = 0i64;
        *((_QWORD *)v48 + 6) = 0i64;
        *((_QWORD *)v48 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveYellow;
      v121 = 3;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Zodiac_Enemy.mUID )
    {
      v49 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v49;
      if ( v49 )
      {
        *(_QWORD *)v49 = &UFG::UIMapBlipGraphic::`vftable;
        v49[8] = 0;
        *(_QWORD *)(v49 + 12) = 1065353216i64;
        *((_DWORD *)v49 + 5) = 5;
        *((_DWORD *)v49 + 29) = 1092616192;
        *((_QWORD *)v49 + 9) = 0i64;
        *((_DWORD *)v49 + 24) = 1065353216;
        v49[136] = 0;
        *((_QWORD *)v49 + 3) = v49 + 64;
        *((_QWORD *)v49 + 4) = 0i64;
        *((_QWORD *)v49 + 5) = 0i64;
        *((_QWORD *)v49 + 6) = 0i64;
        *((_QWORD *)v49 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = UFG::ObjectiveRed;
      v121 = 1;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Zodiac_Friendly.mUID )
    {
      v50 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v50;
      if ( v50 )
      {
        *(_QWORD *)v50 = &UFG::UIMapBlipGraphic::`vftable;
        v50[8] = 0;
        *(_QWORD *)(v50 + 12) = 1065353216i64;
        *((_DWORD *)v50 + 5) = 5;
        *((_DWORD *)v50 + 29) = 1092616192;
        *((_QWORD *)v50 + 9) = 0i64;
        *((_DWORD *)v50 + 24) = 1065353216;
        v50[136] = 0;
        *((_QWORD *)v50 + 3) = v50 + 64;
        *((_QWORD *)v50 + 4) = 0i64;
        *((_QWORD *)v50 + 5) = 0i64;
        *((_QWORD *)v50 + 6) = 0i64;
        *((_QWORD *)v50 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v121 = 3;
      goto LABEL_474;
    }
    if ( mUID == UIBlipIcon_Lesser_Ghoul.mUID )
    {
      v51 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v51;
      if ( v51 )
      {
        *(_QWORD *)v51 = &UFG::UIMapBlipGraphic::`vftable;
        v51[8] = 0;
        *(_QWORD *)(v51 + 12) = 1065353216i64;
        *((_DWORD *)v51 + 5) = 5;
        *((_DWORD *)v51 + 29) = 1092616192;
        *((_QWORD *)v51 + 9) = 0i64;
        *((_DWORD *)v51 + 24) = 1065353216;
        v51[136] = 0;
        *((_QWORD *)v51 + 3) = v51 + 64;
        *((_QWORD *)v51 + 4) = 0i64;
        *((_QWORD *)v51 + 5) = 0i64;
        *((_QWORD *)v51 + 6) = 0i64;
        *((_QWORD *)v51 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = GhostGreen;
      v121 = 32;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Elite_Ghoul.mUID )
    {
      v52 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v52;
      if ( v52 )
      {
        *(_QWORD *)v52 = &UFG::UIMapBlipGraphic::`vftable;
        v52[8] = 0;
        *(_QWORD *)(v52 + 12) = 1065353216i64;
        *((_DWORD *)v52 + 5) = 5;
        *((_DWORD *)v52 + 29) = 1092616192;
        *((_QWORD *)v52 + 9) = 0i64;
        *((_DWORD *)v52 + 24) = 1065353216;
        v52[136] = 0;
        *((_QWORD *)v52 + 3) = v52 + 64;
        *((_QWORD *)v52 + 4) = 0i64;
        *((_QWORD *)v52 + 5) = 0i64;
        *((_QWORD *)v52 + 6) = 0i64;
        *((_QWORD *)v52 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = GhostPurple;
      v121 = 32;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Trapped_Ped.mUID )
    {
      v53 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v53;
      if ( v53 )
      {
        *(_QWORD *)v53 = &UFG::UIMapBlipGraphic::`vftable;
        v53[8] = 0;
        *(_QWORD *)(v53 + 12) = 1065353216i64;
        *((_DWORD *)v53 + 5) = 5;
        *((_DWORD *)v53 + 29) = 1092616192;
        *((_QWORD *)v53 + 9) = 0i64;
        *((_DWORD *)v53 + 24) = 1065353216;
        v53[136] = 0;
        *((_QWORD *)v53 + 3) = v53 + 64;
        *((_QWORD *)v53 + 4) = 0i64;
        *((_QWORD *)v53 + 5) = 0i64;
        *((_QWORD *)v53 + 6) = 0i64;
        *((_QWORD *)v53 + 7) = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = GhostGreen;
      v121 = 30;
      goto LABEL_475;
    }
    if ( mUID == UIBlipIcon_Hiding_Spot.mUID )
    {
      v54 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v54;
      if ( v54 )
        goto LABEL_403;
      v6 = 0i64;
    }
    else
    {
      if ( mUID != UIBlipIcon_Hiding_Spot_Garage.mUID )
      {
        if ( mUID == UIBlipIcon_Cop.mUID )
        {
          v55 = UFG::qMalloc(0xA8ui64, "UIMapBlipGraphicFactory", 0i64);
          if ( v55 )
          {
            UFG::UIMapBlipGraphicCop::UIMapBlipGraphicCop((UFG::UIMapBlipGraphicCop *)v55);
            v6 = v56;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::qColour::DogerBlue;
          v121 = 2;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Cop_OnFoot.mUID )
        {
          v57 = UFG::qMalloc(0xA8ui64, "UIMapBlipGraphicFactory", 0i64);
          if ( v57 )
          {
            UFG::UIMapBlipGraphicCop::UIMapBlipGraphicCop((UFG::UIMapBlipGraphicCop *)v57);
            v6 = v58;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::qColour::DogerBlue;
          v121 = 1;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Cop_OnFoot_Patrol.mUID )
        {
          v59 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          if ( v59 )
          {
            UFG::UIMapBlipGraphicEnemy::UIMapBlipGraphicEnemy((UFG::UIMapBlipGraphicEnemy *)v59);
            v6 = v60;
          }
          else
          {
            v6 = 0i64;
          }
          v122 = _xmm;
          UFG::UIMapBlipGraphic::SetPolyInfo((UFG::UIMapBlipGraphic *)v6, IconPoly, (float)v2, (UFG::qColour *)&v122, 1);
          return (UFG::UIMapBlipGraphic *)v6;
        }
        if ( mUID == UIBlipIcon_Cop_Vehicle_Patrol.mUID )
        {
          v61 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          if ( v61 )
          {
            UFG::UIMapBlipGraphicEnemy::UIMapBlipGraphicEnemy((UFG::UIMapBlipGraphicEnemy *)v61);
            v6 = v62;
          }
          else
          {
            v6 = 0i64;
          }
          v122 = _xmm;
          UFG::UIMapBlipGraphic::SetPolyInfo((UFG::UIMapBlipGraphic *)v6, IconPoly, (float)v2, (UFG::qColour *)&v122, 2);
          return (UFG::UIMapBlipGraphic *)v6;
        }
        if ( mUID == UIBlipIcon_Witness.mUID )
        {
          v63 = UFG::qMalloc(0x98ui64, "UIMapBlipGraphicFactory", 0i64);
          if ( v63 )
          {
            UFG::UIMapBlipGraphicWitness::UIMapBlipGraphicWitness((UFG::UIMapBlipGraphicWitness *)v63);
            v6 = v64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 1;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Road_Block.mUID )
        {
          v65 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v65;
          if ( v65 )
          {
            *(_QWORD *)v65 = &UFG::UIMapBlipGraphic::`vftable;
            v65[8] = 0;
            *(_QWORD *)(v65 + 12) = 1065353216i64;
            *((_DWORD *)v65 + 5) = 5;
            *((_DWORD *)v65 + 29) = 1092616192;
            *((_QWORD *)v65 + 9) = 0i64;
            *((_DWORD *)v65 + 24) = 1065353216;
            v65[136] = 0;
            *((_QWORD *)v65 + 3) = v65 + 64;
            *((_QWORD *)v65 + 4) = 0i64;
            *((_QWORD *)v65 + 5) = 0i64;
            *((_QWORD *)v65 + 6) = 0i64;
            *((_QWORD *)v65 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 28;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Karaoke.mUID )
        {
          v66 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v66;
          if ( v66 )
          {
            *(_QWORD *)v66 = &UFG::UIMapBlipGraphic::`vftable;
            v66[8] = 0;
            *(_QWORD *)(v66 + 12) = 1065353216i64;
            *((_DWORD *)v66 + 5) = 5;
            *((_DWORD *)v66 + 29) = 1092616192;
            *((_QWORD *)v66 + 9) = 0i64;
            *((_DWORD *)v66 + 24) = 1065353216;
            v66[136] = 0;
            *((_QWORD *)v66 + 3) = v66 + 64;
            *((_QWORD *)v66 + 4) = 0i64;
            *((_QWORD *)v66 + 5) = 0i64;
            *((_QWORD *)v66 + 6) = 0i64;
            *((_QWORD *)v66 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 29;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Ferry.mUID )
        {
          v67 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v67;
          if ( v67 )
          {
            *(_QWORD *)v67 = &UFG::UIMapBlipGraphic::`vftable;
            v67[8] = 0;
            *(_QWORD *)(v67 + 12) = 1065353216i64;
            *((_DWORD *)v67 + 5) = 5;
            *((_DWORD *)v67 + 29) = 1092616192;
            *((_QWORD *)v67 + 9) = 0i64;
            *((_DWORD *)v67 + 24) = 1065353216;
            v67[136] = 0;
            *((_QWORD *)v67 + 3) = v67 + 64;
            *((_QWORD *)v67 + 4) = 0i64;
            *((_QWORD *)v67 + 5) = 0i64;
            *((_QWORD *)v67 + 6) = 0i64;
            *((_QWORD *)v67 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 8;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Bus_Stop.mUID )
        {
          v68 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v68;
          if ( v68 )
          {
            *(_QWORD *)v68 = &UFG::UIMapBlipGraphic::`vftable;
            v68[8] = 0;
            *(_QWORD *)(v68 + 12) = 1065353216i64;
            *((_DWORD *)v68 + 5) = 5;
            *((_DWORD *)v68 + 29) = 1092616192;
            *((_QWORD *)v68 + 9) = 0i64;
            *((_DWORD *)v68 + 24) = 1065353216;
            v68[136] = 0;
            *((_QWORD *)v68 + 3) = v68 + 64;
            *((_QWORD *)v68 + 4) = 0i64;
            *((_QWORD *)v68 + 5) = 0i64;
            *((_QWORD *)v68 + 6) = 0i64;
            *((_QWORD *)v68 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 9;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Pork_Bun_Vendor.mUID )
        {
          v69 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v69;
          if ( v69 )
          {
            *(_QWORD *)v69 = &UFG::UIMapBlipGraphic::`vftable;
            v69[8] = 0;
            *(_QWORD *)(v69 + 12) = 1065353216i64;
            *((_DWORD *)v69 + 5) = 5;
            *((_DWORD *)v69 + 29) = 1092616192;
            *((_QWORD *)v69 + 9) = 0i64;
            *((_DWORD *)v69 + 24) = 1065353216;
            v69[136] = 0;
            *((_QWORD *)v69 + 3) = v69 + 64;
            *((_QWORD *)v69 + 4) = 0i64;
            *((_QWORD *)v69 + 5) = 0i64;
            *((_QWORD *)v69 + 6) = 0i64;
            *((_QWORD *)v69 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 10;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Convenience_Store.mUID )
        {
          v70 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v70;
          if ( v70 )
          {
            *(_QWORD *)v70 = &UFG::UIMapBlipGraphic::`vftable;
            v70[8] = 0;
            *(_QWORD *)(v70 + 12) = 1065353216i64;
            *((_DWORD *)v70 + 5) = 5;
            *((_DWORD *)v70 + 29) = 1092616192;
            *((_QWORD *)v70 + 9) = 0i64;
            *((_DWORD *)v70 + 24) = 1065353216;
            v70[136] = 0;
            *((_QWORD *)v70 + 3) = v70 + 64;
            *((_QWORD *)v70 + 4) = 0i64;
            *((_QWORD *)v70 + 5) = 0i64;
            *((_QWORD *)v70 + 6) = 0i64;
            *((_QWORD *)v70 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 19;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Apothecary_Store.mUID )
        {
          v71 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v71;
          if ( v71 )
          {
            *(_QWORD *)v71 = &UFG::UIMapBlipGraphic::`vftable;
            v71[8] = 0;
            *(_QWORD *)(v71 + 12) = 1065353216i64;
            *((_DWORD *)v71 + 5) = 5;
            *((_DWORD *)v71 + 29) = 1092616192;
            *((_QWORD *)v71 + 9) = 0i64;
            *((_DWORD *)v71 + 24) = 1065353216;
            v71[136] = 0;
            *((_QWORD *)v71 + 3) = v71 + 64;
            *((_QWORD *)v71 + 4) = 0i64;
            *((_QWORD *)v71 + 5) = 0i64;
            *((_QWORD *)v71 + 6) = 0i64;
            *((_QWORD *)v71 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 18;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Clothing_Store.mUID )
        {
          v72 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v72;
          if ( v72 )
          {
            *(_QWORD *)v72 = &UFG::UIMapBlipGraphic::`vftable;
            v72[8] = 0;
            *(_QWORD *)(v72 + 12) = 1065353216i64;
            *((_DWORD *)v72 + 5) = 5;
            *((_DWORD *)v72 + 29) = 1092616192;
            *((_QWORD *)v72 + 9) = 0i64;
            *((_DWORD *)v72 + 24) = 1065353216;
            v72[136] = 0;
            *((_QWORD *)v72 + 3) = v72 + 64;
            *((_QWORD *)v72 + 4) = 0i64;
            *((_QWORD *)v72 + 5) = 0i64;
            *((_QWORD *)v72 + 6) = 0i64;
            *((_QWORD *)v72 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 11;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Exotic_Clothing_Store.mUID )
        {
          v73 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v73;
          if ( v73 )
          {
            *(_QWORD *)v73 = &UFG::UIMapBlipGraphic::`vftable;
            v73[8] = 0;
            *(_QWORD *)(v73 + 12) = 1065353216i64;
            *((_DWORD *)v73 + 5) = 5;
            *((_DWORD *)v73 + 29) = 1092616192;
            *((_QWORD *)v73 + 9) = 0i64;
            *((_DWORD *)v73 + 24) = 1065353216;
            v73[136] = 0;
            *((_QWORD *)v73 + 3) = v73 + 64;
            *((_QWORD *)v73 + 4) = 0i64;
            *((_QWORD *)v73 + 5) = 0i64;
            *((_QWORD *)v73 + 6) = 0i64;
            *((_QWORD *)v73 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::ExoticVendorGold;
          v121 = 11;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Gambling_Den.mUID )
        {
          v74 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v74;
          if ( v74 )
          {
            *(_QWORD *)v74 = &UFG::UIMapBlipGraphic::`vftable;
            v74[8] = 0;
            *(_QWORD *)(v74 + 12) = 1065353216i64;
            *((_DWORD *)v74 + 5) = 5;
            *((_DWORD *)v74 + 29) = 1092616192;
            *((_QWORD *)v74 + 9) = 0i64;
            *((_DWORD *)v74 + 24) = 1065353216;
            v74[136] = 0;
            *((_QWORD *)v74 + 3) = v74 + 64;
            *((_QWORD *)v74 + 4) = 0i64;
            *((_QWORD *)v74 + 5) = 0i64;
            *((_QWORD *)v74 + 6) = 0i64;
            *((_QWORD *)v74 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::ObjectiveOrange;
          v121 = 15;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Massage_Parlors.mUID )
        {
          v75 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v75;
          if ( v75 )
          {
            *(_QWORD *)v75 = &UFG::UIMapBlipGraphic::`vftable;
            v75[8] = 0;
            *(_QWORD *)(v75 + 12) = 1065353216i64;
            *((_DWORD *)v75 + 5) = 5;
            *((_DWORD *)v75 + 29) = 1092616192;
            *((_QWORD *)v75 + 9) = 0i64;
            *((_DWORD *)v75 + 24) = 1065353216;
            v75[136] = 0;
            *((_QWORD *)v75 + 3) = v75 + 64;
            *((_QWORD *)v75 + 4) = 0i64;
            *((_QWORD *)v75 + 5) = 0i64;
            *((_QWORD *)v75 + 6) = 0i64;
            *((_QWORD *)v75 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 16;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Martial_Arts_School.mUID )
        {
          v76 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v76;
          if ( v76 )
          {
            *(_QWORD *)v76 = &UFG::UIMapBlipGraphic::`vftable;
            v76[8] = 0;
            *(_QWORD *)(v76 + 12) = 1065353216i64;
            *((_DWORD *)v76 + 5) = 5;
            *((_DWORD *)v76 + 29) = 1092616192;
            *((_QWORD *)v76 + 9) = 0i64;
            *((_DWORD *)v76 + 24) = 1065353216;
            v76[136] = 0;
            *((_QWORD *)v76 + 3) = v76 + 64;
            *((_QWORD *)v76 + 4) = 0i64;
            *((_QWORD *)v76 + 5) = 0i64;
            *((_QWORD *)v76 + 6) = 0i64;
            *((_QWORD *)v76 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 17;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Martial_Arts_School_Objective.mUID )
        {
          v77 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v77;
          if ( v77 )
          {
            *(_QWORD *)v77 = &UFG::UIMapBlipGraphic::`vftable;
            v77[8] = 0;
            *(_QWORD *)(v77 + 12) = 1065353216i64;
            *((_DWORD *)v77 + 5) = 5;
            *((_DWORD *)v77 + 29) = 1092616192;
            *((_QWORD *)v77 + 9) = 0i64;
            *((_DWORD *)v77 + 24) = 1065353216;
            v77[136] = 0;
            *((_QWORD *)v77 + 3) = v77 + 64;
            *((_QWORD *)v77 + 4) = 0i64;
            *((_QWORD *)v77 + 5) = 0i64;
            *((_QWORD *)v77 + 6) = 0i64;
            *((_QWORD *)v77 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::ObjectiveGreen;
          v121 = 17;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Parking_Lot.mUID )
        {
          v78 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v78;
          if ( v78 )
          {
            *(_QWORD *)v78 = &UFG::UIMapBlipGraphic::`vftable;
            v78[8] = 0;
            *(_QWORD *)(v78 + 12) = 1065353216i64;
            *((_DWORD *)v78 + 5) = 5;
            *((_DWORD *)v78 + 29) = 1092616192;
            *((_QWORD *)v78 + 9) = 0i64;
            *((_DWORD *)v78 + 24) = 1065353216;
            v78[136] = 0;
            *((_QWORD *)v78 + 3) = v78 + 64;
            *((_QWORD *)v78 + 4) = 0i64;
            *((_QWORD *)v78 + 5) = 0i64;
            *((_QWORD *)v78 + 6) = 0i64;
            *((_QWORD *)v78 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 13;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Fight_Club.mUID )
        {
          v79 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v79;
          if ( v79 )
          {
            *(_QWORD *)v79 = &UFG::UIMapBlipGraphic::`vftable;
            v79[8] = 0;
            *(_QWORD *)(v79 + 12) = 1065353216i64;
            *((_DWORD *)v79 + 5) = 5;
            *((_DWORD *)v79 + 29) = 1092616192;
            *((_QWORD *)v79 + 9) = 0i64;
            *((_DWORD *)v79 + 24) = 1065353216;
            v79[136] = 0;
            *((_QWORD *)v79 + 3) = v79 + 64;
            *((_QWORD *)v79 + 4) = 0i64;
            *((_QWORD *)v79 + 5) = 0i64;
            *((_QWORD *)v79 + 6) = 0i64;
            *((_QWORD *)v79 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::ObjectiveOrange;
          v121 = 20;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Cock_Fighting.mUID )
        {
          v80 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v80;
          if ( v80 )
          {
            *(_QWORD *)v80 = &UFG::UIMapBlipGraphic::`vftable;
            v80[8] = 0;
            *(_QWORD *)(v80 + 12) = 1065353216i64;
            *((_DWORD *)v80 + 5) = 5;
            *((_DWORD *)v80 + 29) = 1092616192;
            *((_QWORD *)v80 + 9) = 0i64;
            *((_DWORD *)v80 + 24) = 1065353216;
            v80[136] = 0;
            *((_QWORD *)v80 + 3) = v80 + 64;
            *((_QWORD *)v80 + 4) = 0i64;
            *((_QWORD *)v80 + 5) = 0i64;
            *((_QWORD *)v80 + 6) = 0i64;
            *((_QWORD *)v80 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::ObjectiveOrange;
          v121 = 21;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Drunken_Dice.mUID )
        {
          v81 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v81;
          if ( v81 )
          {
            *(_QWORD *)v81 = &UFG::UIMapBlipGraphic::`vftable;
            v81[8] = 0;
            *(_QWORD *)(v81 + 12) = 1065353216i64;
            *((_DWORD *)v81 + 5) = 5;
            *((_DWORD *)v81 + 29) = 1092616192;
            *((_QWORD *)v81 + 9) = 0i64;
            *((_DWORD *)v81 + 24) = 1065353216;
            v81[136] = 0;
            *((_QWORD *)v81 + 3) = v81 + 64;
            *((_QWORD *)v81 + 4) = 0i64;
            *((_QWORD *)v81 + 5) = 0i64;
            *((_QWORD *)v81 + 6) = 0i64;
            *((_QWORD *)v81 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::ObjectiveOrange;
          v121 = 15;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Vehicle_Store.mUID )
        {
          v82 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v82;
          if ( v82 )
          {
            *(_QWORD *)v82 = &UFG::UIMapBlipGraphic::`vftable;
            v82[8] = 0;
            *(_QWORD *)(v82 + 12) = 1065353216i64;
            *((_DWORD *)v82 + 5) = 5;
            *((_DWORD *)v82 + 29) = 1092616192;
            *((_QWORD *)v82 + 9) = 0i64;
            *((_DWORD *)v82 + 24) = 1065353216;
            v82[136] = 0;
            *((_QWORD *)v82 + 3) = v82 + 64;
            *((_QWORD *)v82 + 4) = 0i64;
            *((_QWORD *)v82 + 5) = 0i64;
            *((_QWORD *)v82 + 6) = 0i64;
            *((_QWORD *)v82 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 14;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Owned_Vehicle.mUID )
        {
          v83 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v83;
          if ( v83 )
          {
            *(_QWORD *)v83 = &UFG::UIMapBlipGraphic::`vftable;
            v83[8] = 0;
            *(_QWORD *)(v83 + 12) = 1065353216i64;
            *((_DWORD *)v83 + 5) = 5;
            *((_DWORD *)v83 + 29) = 1092616192;
            *((_QWORD *)v83 + 9) = 0i64;
            *((_DWORD *)v83 + 24) = 1065353216;
            v83[136] = 0;
            *((_QWORD *)v83 + 3) = v83 + 64;
            *((_QWORD *)v83 + 4) = 0i64;
            *((_QWORD *)v83 + 5) = 0i64;
            *((_QWORD *)v83 + 6) = 0i64;
            *((_QWORD *)v83 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::AmbientGreen;
          v121 = 14;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Safehouse_Store.mUID )
        {
          v84 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v84;
          if ( v84 )
          {
            *(_QWORD *)v84 = &UFG::UIMapBlipGraphic::`vftable;
            v84[8] = 0;
            *(_QWORD *)(v84 + 12) = 1065353216i64;
            *((_DWORD *)v84 + 5) = 5;
            *((_DWORD *)v84 + 29) = 1092616192;
            *((_QWORD *)v84 + 9) = 0i64;
            *((_DWORD *)v84 + 24) = 1065353216;
            v84[136] = 0;
            *((_QWORD *)v84 + 3) = v84 + 64;
            *((_QWORD *)v84 + 4) = 0i64;
            *((_QWORD *)v84 + 5) = 0i64;
            *((_QWORD *)v84 + 6) = 0i64;
            *((_QWORD *)v84 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 26;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Enemy.mUID )
        {
          v85 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          if ( v85 )
          {
            UFG::UIMapBlipGraphicEnemy::UIMapBlipGraphicEnemy((UFG::UIMapBlipGraphicEnemy *)v85);
            v6 = v86;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::ObjectiveRed;
          v121 = 1;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Friendly.mUID )
        {
          v87 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v87;
          if ( v87 )
          {
            *(_QWORD *)v87 = &UFG::UIMapBlipGraphic::`vftable;
            v87[8] = 0;
            *(_QWORD *)(v87 + 12) = 1065353216i64;
            *((_DWORD *)v87 + 5) = 5;
            *((_DWORD *)v87 + 29) = 1092616192;
            *((_QWORD *)v87 + 9) = 0i64;
            *((_DWORD *)v87 + 24) = 1065353216;
            v87[136] = 0;
            *((_QWORD *)v87 + 3) = v87 + 64;
            *((_QWORD *)v87 + 4) = 0i64;
            *((_QWORD *)v87 + 5) = 0i64;
            *((_QWORD *)v87 + 6) = 0i64;
            *((_QWORD *)v87 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::ObjectiveGreen;
          v121 = 1;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Social.mUID )
        {
          v88 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v88;
          if ( v88 )
          {
            *(_QWORD *)v88 = &UFG::UIMapBlipGraphic::`vftable;
            v88[8] = 0;
            *(_QWORD *)(v88 + 12) = 1065353216i64;
            *((_DWORD *)v88 + 5) = 5;
            *((_DWORD *)v88 + 29) = 1092616192;
            *((_QWORD *)v88 + 9) = 0i64;
            *((_DWORD *)v88 + 24) = 1065353216;
            v88[136] = 0;
            *((_QWORD *)v88 + 3) = v88 + 64;
            *((_QWORD *)v88 + 4) = 0i64;
            *((_QWORD *)v88 + 5) = 0i64;
            *((_QWORD *)v88 + 6) = 0i64;
            *((_QWORD *)v88 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::ObjectiveYellow;
          v121 = 30;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Contact.mUID )
        {
          v89 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v89;
          if ( v89 )
          {
            *(_QWORD *)v89 = &UFG::UIMapBlipGraphic::`vftable;
            v89[8] = 0;
            *(_QWORD *)(v89 + 12) = 1065353216i64;
            *((_DWORD *)v89 + 5) = 5;
            *((_DWORD *)v89 + 29) = 1092616192;
            *((_QWORD *)v89 + 9) = 0i64;
            *((_DWORD *)v89 + 24) = 1065353216;
            v89[136] = 0;
            *((_QWORD *)v89 + 3) = v89 + 64;
            *((_QWORD *)v89 + 4) = 0i64;
            *((_QWORD *)v89 + 5) = 0i64;
            *((_QWORD *)v89 + 6) = 0i64;
            *((_QWORD *)v89 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 1;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Face_Character.mUID )
        {
          v90 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v90;
          if ( v90 )
          {
            *(_QWORD *)v90 = &UFG::UIMapBlipGraphic::`vftable;
            v90[8] = 0;
            *(_QWORD *)(v90 + 12) = 1065353216i64;
            *((_DWORD *)v90 + 5) = 5;
            *((_DWORD *)v90 + 29) = 1092616192;
            *((_QWORD *)v90 + 9) = 0i64;
            *((_DWORD *)v90 + 24) = 1065353216;
            v90[136] = 0;
            *((_QWORD *)v90 + 3) = v90 + 64;
            *((_QWORD *)v90 + 4) = 0i64;
            *((_QWORD *)v90 + 5) = 0i64;
            *((_QWORD *)v90 + 6) = 0i64;
            *((_QWORD *)v90 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::ObjectiveYellow;
          v121 = 30;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Story_Character.mUID )
        {
          v91 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v91;
          if ( v91 )
          {
            *(_QWORD *)v91 = &UFG::UIMapBlipGraphic::`vftable;
            v91[8] = 0;
            *(_QWORD *)(v91 + 12) = 1065353216i64;
            *((_DWORD *)v91 + 5) = 5;
            *((_DWORD *)v91 + 29) = 1092616192;
            *((_QWORD *)v91 + 9) = 0i64;
            *((_DWORD *)v91 + 24) = 1065353216;
            v91[136] = 0;
            *((_QWORD *)v91 + 3) = v91 + 64;
            *((_QWORD *)v91 + 4) = 0i64;
            *((_QWORD *)v91 + 5) = 0i64;
            *((_QWORD *)v91 + 6) = 0i64;
            *((_QWORD *)v91 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::ObjectiveGreen;
          v121 = 1;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Date_Character.mUID )
        {
          v92 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v92;
          if ( v92 )
          {
            *(_QWORD *)v92 = &UFG::UIMapBlipGraphic::`vftable;
            v92[8] = 0;
            *(_QWORD *)(v92 + 12) = 1065353216i64;
            *((_DWORD *)v92 + 5) = 5;
            *((_DWORD *)v92 + 29) = 1092616192;
            *((_QWORD *)v92 + 9) = 0i64;
            *((_DWORD *)v92 + 24) = 1065353216;
            v92[136] = 0;
            *((_QWORD *)v92 + 3) = v92 + 64;
            *((_QWORD *)v92 + 4) = 0i64;
            *((_QWORD *)v92 + 5) = 0i64;
            *((_QWORD *)v92 + 6) = 0i64;
            *((_QWORD *)v92 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::CharacterPink;
          v121 = 1;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Security_Camera.mUID )
        {
          v93 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v93;
          if ( v93 )
          {
            *(_QWORD *)v93 = &UFG::UIMapBlipGraphic::`vftable;
            v93[8] = 0;
            *(_QWORD *)(v93 + 12) = 1065353216i64;
            *((_DWORD *)v93 + 5) = 5;
            *((_DWORD *)v93 + 29) = 1092616192;
            *((_QWORD *)v93 + 9) = 0i64;
            *((_DWORD *)v93 + 24) = 1065353216;
            v93[136] = 0;
            *((_QWORD *)v93 + 3) = v93 + 64;
            *((_QWORD *)v93 + 4) = 0i64;
            *((_QWORD *)v93 + 5) = 0i64;
            *((_QWORD *)v93 + 6) = 0i64;
            *((_QWORD *)v93 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::qColour::Grey;
          v121 = 5;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Security_Camera_Collected.mUID )
        {
          v94 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v94;
          if ( v94 )
          {
            *(_QWORD *)v94 = &UFG::UIMapBlipGraphic::`vftable;
            v94[8] = 0;
            *(_QWORD *)(v94 + 12) = 1065353216i64;
            *((_DWORD *)v94 + 5) = 5;
            *((_DWORD *)v94 + 29) = 1092616192;
            *((_QWORD *)v94 + 9) = 0i64;
            *((_DWORD *)v94 + 24) = 1065353216;
            v94[136] = 0;
            *((_QWORD *)v94 + 3) = v94 + 64;
            *((_QWORD *)v94 + 4) = 0i64;
            *((_QWORD *)v94 + 5) = 0i64;
            *((_QWORD *)v94 + 6) = 0i64;
            *((_QWORD *)v94 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 5;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Shrine.mUID )
        {
          v95 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v95;
          if ( v95 )
          {
            *(_QWORD *)v95 = &UFG::UIMapBlipGraphic::`vftable;
            v95[8] = 0;
            *(_QWORD *)(v95 + 12) = 1065353216i64;
            *((_DWORD *)v95 + 5) = 5;
            *((_DWORD *)v95 + 29) = 1092616192;
            *((_QWORD *)v95 + 9) = 0i64;
            *((_DWORD *)v95 + 24) = 1065353216;
            v95[136] = 0;
            *((_QWORD *)v95 + 3) = v95 + 64;
            *((_QWORD *)v95 + 4) = 0i64;
            *((_QWORD *)v95 + 5) = 0i64;
            *((_QWORD *)v95 + 6) = 0i64;
            *((_QWORD *)v95 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::qColour::Grey;
          v121 = 6;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Shrine_Collected.mUID )
        {
          v96 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v96;
          if ( v96 )
          {
            *(_QWORD *)v96 = &UFG::UIMapBlipGraphic::`vftable;
            v96[8] = 0;
            *(_QWORD *)(v96 + 12) = 1065353216i64;
            *((_DWORD *)v96 + 5) = 5;
            *((_DWORD *)v96 + 29) = 1092616192;
            *((_QWORD *)v96 + 9) = 0i64;
            *((_DWORD *)v96 + 24) = 1065353216;
            v96[136] = 0;
            *((_QWORD *)v96 + 3) = v96 + 64;
            *((_QWORD *)v96 + 4) = 0i64;
            *((_QWORD *)v96 + 5) = 0i64;
            *((_QWORD *)v96 + 6) = 0i64;
            *((_QWORD *)v96 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 6;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Lockbox.mUID )
        {
          v97 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v97;
          if ( v97 )
          {
            *(_QWORD *)v97 = &UFG::UIMapBlipGraphic::`vftable;
            v97[8] = 0;
            *(_QWORD *)(v97 + 12) = 1065353216i64;
            *((_DWORD *)v97 + 5) = 5;
            *((_DWORD *)v97 + 29) = 1092616192;
            *((_QWORD *)v97 + 9) = 0i64;
            *((_DWORD *)v97 + 24) = 1065353216;
            v97[136] = 0;
            *((_QWORD *)v97 + 3) = v97 + 64;
            *((_QWORD *)v97 + 4) = 0i64;
            *((_QWORD *)v97 + 5) = 0i64;
            *((_QWORD *)v97 + 6) = 0i64;
            *((_QWORD *)v97 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::qColour::Grey;
          v121 = 7;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Lockbox_Collected.mUID )
        {
          v98 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v98;
          if ( v98 )
          {
            *(_QWORD *)v98 = &UFG::UIMapBlipGraphic::`vftable;
            v98[8] = 0;
            *(_QWORD *)(v98 + 12) = 1065353216i64;
            *((_DWORD *)v98 + 5) = 5;
            *((_DWORD *)v98 + 29) = 1092616192;
            *((_QWORD *)v98 + 9) = 0i64;
            *((_DWORD *)v98 + 24) = 1065353216;
            v98[136] = 0;
            *((_QWORD *)v98 + 3) = v98 + 64;
            *((_QWORD *)v98 + 4) = 0i64;
            *((_QWORD *)v98 + 5) = 0i64;
            *((_QWORD *)v98 + 6) = 0i64;
            *((_QWORD *)v98 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 7;
          goto LABEL_474;
        }
        if ( mUID == UIBlipIcon_Melee_Upgrade.mUID )
        {
          v99 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v99;
          if ( v99 )
          {
            *(_QWORD *)v99 = &UFG::UIMapBlipGraphic::`vftable;
            v99[8] = 0;
            *(_QWORD *)(v99 + 12) = 1065353216i64;
            *((_DWORD *)v99 + 5) = 5;
            *((_DWORD *)v99 + 29) = 1092616192;
            *((_QWORD *)v99 + 9) = 0i64;
            *((_DWORD *)v99 + 24) = 1065353216;
            v99[136] = 0;
            *((_QWORD *)v99 + 3) = v99 + 64;
            *((_QWORD *)v99 + 4) = 0i64;
            *((_QWORD *)v99 + 5) = 0i64;
            *((_QWORD *)v99 + 6) = 0i64;
            *((_QWORD *)v99 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v20 = UFG::qColour::Grey;
          v121 = 25;
          goto LABEL_475;
        }
        if ( mUID == UIBlipIcon_Melee_Upgrade_Collected.mUID )
        {
          v100 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = v100;
          if ( v100 )
          {
            *(_QWORD *)v100 = &UFG::UIMapBlipGraphic::`vftable;
            v100[8] = 0;
            *(_QWORD *)(v100 + 12) = 1065353216i64;
            *((_DWORD *)v100 + 5) = 5;
            *((_DWORD *)v100 + 29) = 1092616192;
            *((_QWORD *)v100 + 9) = 0i64;
            *((_DWORD *)v100 + 24) = 1065353216;
            v100[136] = 0;
            *((_QWORD *)v100 + 3) = v100 + 64;
            *((_QWORD *)v100 + 4) = 0i64;
            *((_QWORD *)v100 + 5) = 0i64;
            *((_QWORD *)v100 + 6) = 0i64;
            *((_QWORD *)v100 + 7) = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v121 = 25;
          goto LABEL_474;
        }
        if ( mUID != UIBlipIcon_Tourist_Photo.mUID )
        {
          if ( mUID == UIBlipIcon_Jump.mUID )
          {
            v101 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = v101;
            if ( v101 )
            {
              *(_QWORD *)v101 = &UFG::UIMapBlipGraphic::`vftable;
              v101[8] = 0;
              *(_QWORD *)(v101 + 12) = 1065353216i64;
              *((_DWORD *)v101 + 5) = 5;
              *((_DWORD *)v101 + 29) = 1092616192;
              *((_QWORD *)v101 + 9) = 0i64;
              *((_DWORD *)v101 + 24) = 1065353216;
              v101[136] = 0;
              *((_QWORD *)v101 + 3) = v101 + 64;
              *((_QWORD *)v101 + 4) = 0i64;
              *((_QWORD *)v101 + 5) = 0i64;
              *((_QWORD *)v101 + 6) = 0i64;
              *((_QWORD *)v101 + 7) = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v20 = UFG::qColour::Grey;
            v121 = 24;
            goto LABEL_475;
          }
          if ( mUID == UIBlipIcon_Jump_Collected.mUID )
          {
            v102 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            if ( v102 )
            {
              UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v102);
              v6 = v103;
            }
            else
            {
              v6 = 0i64;
            }
            v121 = 24;
            goto LABEL_474;
          }
          if ( mUID == UIBlipIcon_Tape_Recorder.mUID )
          {
            v104 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            if ( !v104 )
            {
              v6 = 0i64;
              goto LABEL_473;
            }
          }
          else if ( mUID == UIBlipIcon_Bug.mUID )
          {
            v104 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            if ( !v104 )
            {
              v6 = 0i64;
              goto LABEL_473;
            }
          }
          else
          {
            if ( mUID == UIBlipIcon_Ghost_Orb.mUID )
            {
              v105 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
              if ( v105 )
              {
                UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v105);
                v6 = v106;
              }
              else
              {
                v6 = 0i64;
              }
              v20 = UFG::qColour::Grey;
              v121 = 31;
              goto LABEL_475;
            }
            if ( mUID == UIBlipIcon_Ghost_Orb_Collected.mUID )
            {
              v104 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
              if ( !v104 )
              {
                v6 = 0i64;
                goto LABEL_473;
              }
            }
            else
            {
              if ( mUID == UIBlipIcon_Fire_Statue.mUID )
              {
                v107 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                if ( v107 )
                {
                  UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v107);
                  v6 = v108;
                }
                else
                {
                  v6 = 0i64;
                }
                v20 = UFG::qColour::Grey;
                v121 = 31;
                goto LABEL_475;
              }
              if ( mUID == UIBlipIcon_Fire_Statue_Collected.mUID )
              {
                v104 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                if ( !v104 )
                {
                  v6 = 0i64;
                  goto LABEL_473;
                }
              }
              else
              {
                if ( mUID == UIBlipIcon_Evidence_Bag.mUID )
                {
                  v109 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                  if ( v109 )
                  {
                    UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v109);
                    v6 = v110;
                  }
                  else
                  {
                    v6 = 0i64;
                  }
                  v20 = UFG::qColour::Grey;
                  v121 = 31;
                  goto LABEL_475;
                }
                if ( mUID == UIBlipIcon_Evidence_Bag_Collected.mUID )
                {
                  v104 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                  if ( !v104 )
                  {
                    v6 = 0i64;
                    goto LABEL_473;
                  }
                }
                else
                {
                  if ( mUID == UIBlipIcon_Generic_Blip.mUID )
                  {
                    v111 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                    if ( v111 )
                    {
                      UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v111);
                      v6 = v112;
                    }
                    else
                    {
                      v6 = 0i64;
                    }
                    v121 = 3;
                    goto LABEL_474;
                  }
                  if ( mUID == UIBlipIcon_Up_Arrow.mUID )
                  {
                    v113 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                    if ( v113 )
                    {
                      UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v113);
                      v6 = v114;
                    }
                    else
                    {
                      v6 = 0i64;
                    }
                    v121 = 23;
                    goto LABEL_474;
                  }
                  if ( mUID == UIBlipIcon_Generic_Interactive_Object.mUID )
                  {
                    v115 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                    if ( v115 )
                    {
                      UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v115);
                      v6 = v116;
                    }
                    else
                    {
                      v6 = 0i64;
                    }
                    v121 = 3;
                    goto LABEL_474;
                  }
                  if ( mUID == UIBlipIcon_invisible_icon.mUID )
                  {
                    v117 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                    if ( !v117 )
                      return 0i64;
                    UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v117);
                    return (UFG::UIMapBlipGraphic *)v118;
                  }
                  if ( mUID == UIBlipIcon_Hijack.mUID )
                  {
                    v104 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                    if ( !v104 )
                    {
                      v6 = 0i64;
                      goto LABEL_473;
                    }
                  }
                  else
                  {
                    v104 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                    if ( !v104 )
                    {
                      v6 = 0i64;
                      goto LABEL_473;
                    }
                  }
                }
              }
            }
          }
          UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v104);
          v6 = v119;
          goto LABEL_473;
        }
        v54 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = v54;
        if ( !v54 )
        {
          v6 = 0i64;
          goto LABEL_473;
        }
        goto LABEL_403;
      }
      v54 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = v54;
      if ( v54 )
      {
LABEL_403:
        *(_QWORD *)v54 = &UFG::UIMapBlipGraphic::`vftable;
        v54[8] = 0;
        *(_QWORD *)(v54 + 12) = 1065353216i64;
        *((_DWORD *)v54 + 5) = 5;
        *((_DWORD *)v6 + 29) = 1092616192;
        *((_QWORD *)v6 + 9) = 0i64;
        *((_DWORD *)v6 + 24) = 1065353216;
        v6[136] = 0;
        *((_QWORD *)v6 + 3) = v6 + 64;
        *((_QWORD *)v6 + 4) = 0i64;
        *((_QWORD *)v6 + 5) = 0i64;
        *((_QWORD *)v6 + 6) = 0i64;
        *((_QWORD *)v6 + 7) = 0i64;
        goto LABEL_473;
      }
      v6 = 0i64;
    }
LABEL_473:
    v121 = 31;
LABEL_474:
    v20 = UFG::qColour::White;
LABEL_475:
    v122 = (__int128)v20;
    UFG::UIMapBlipGraphic::SetPolyInfo((UFG::UIMapBlipGraphic *)v6, IconPoly, (float)v2, (UFG::qColour *)&v122, v121);
    return (UFG::UIMapBlipGraphic *)v6;
  }
  v14 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
  v6 = v14;
  if ( v14 )
  {
    *(_QWORD *)v14 = &UFG::UIMapBlipGraphic::`vftable;
    v14[8] = 0;
    *(_QWORD *)(v14 + 12) = 1065353216i64;
    *((_DWORD *)v14 + 5) = 5;
    *((_DWORD *)v14 + 29) = 1092616192;
    *((_QWORD *)v14 + 9) = 0i64;
    *((_DWORD *)v14 + 24) = 1065353216;
    v14[136] = 0;
    *((_QWORD *)v14 + 3) = v14 + 64;
    *((_QWORD *)v14 + 4) = 0i64;
    *((_QWORD *)v14 + 5) = 0i64;
    *((_QWORD *)v14 + 6) = 0i64;
    *((_QWORD *)v14 + 7) = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  v15 = UFG::qColour::White;
  if ( !*((_QWORD *)v6 + 3) )
  {
    v129 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v129 + 13) = 1092616192;
    *((_QWORD *)v129 + 1) = 0i64;
    *((_DWORD *)v129 + 8) = 1065353216;
    v129[72] = 0;
    *((_QWORD *)v6 + 3) = v129;
  }
  v16 = *((_QWORD *)v6 + 3);
  *(UFG::qColour *)(v16 + 56) = v15;
  *(float *)(v16 + 52) = (float)v2;
  *(_QWORD *)(v16 + 36) = 0i64;
  *(_QWORD *)(v16 + 44) = 0i64;
  *(_BYTE *)(v16 + 72) = 1;
  if ( !*((_QWORD *)v6 + 3) )
  {
    v130 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v130 + 13) = 1092616192;
    *((_QWORD *)v130 + 1) = 0i64;
    *((_DWORD *)v130 + 8) = 1065353216;
    v130[72] = 0;
    *((_QWORD *)v6 + 3) = v130;
  }
  *(_DWORD *)(*((_QWORD *)v6 + 3) + 68i64) = 1065353216;
  if ( !*((_QWORD *)v6 + 3) )
  {
    v131 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v131 + 13) = 1092616192;
    *((_QWORD *)v131 + 1) = 0i64;
    *((_DWORD *)v131 + 8) = 1065353216;
    v131[72] = 0;
    *((_QWORD *)v6 + 3) = v131;
  }
  v17 = (_DWORD *)*((_QWORD *)v6 + 3);
  *v17 = uid_Icon_Minimap_TextureSheet;
  v17[4] = 1056964608;
  v17[5] = 1040187392;
  v17[6] = 1040187392;
  v17[7] = 1040187392;
  return (UFG::UIMapBlipGraphic *)v6;
} 1056964608;
  v17[5] = 1040187392;
  v17[6] = 1040187392;
  v17[7] = 1040187392;
  return (UFG::UIMapBlipGraphic *)v6;
}

// File Line: 984
// RVA: 0xBBC00
void __fastcall UFG::UIMapBlipGraphicPlayerArrow::UIMapBlipGraphicPlayerArrow(UFG::UIMapBlipGraphicPlayerArrow *this)
{
  UFG::qMatrix44 *p_mRotationMatrix; // rdi
  UFG::qVector4 v3; // xmm1
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm3
  char *v6; // [rsp+48h] [rbp+10h]
  char *v7; // [rsp+48h] [rbp+10h]
  char *v8; // [rsp+48h] [rbp+10h]
  char *v9; // [rsp+48h] [rbp+10h]

  this->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphic::`vftable;
  this->mAnimateBlink = 0;
  *(_QWORD *)&this->mBlinkScale = 1065353216i64;
  this->mBlinkTimesMax = 5;
  this->mIconPoly.Size = 10.0;
  this->mIconPoly.Matrix = 0i64;
  this->mIconPoly.Scale = 1.0;
  this->mIconPoly.Visible = 0;
  this->mPolys[0] = &this->mIconPoly;
  this->mPolys[1] = 0i64;
  this->mPolys[2] = 0i64;
  this->mPolys[3] = 0i64;
  this->mPolys[4] = 0i64;
  this->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphicPlayerArrow::`vftable;
  if ( !this->mPolys[0] )
  {
    v6 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v6 + 13) = 1092616192;
    *((_QWORD *)v6 + 1) = 0i64;
    *((_DWORD *)v6 + 8) = 1065353216;
    v6[72] = 0;
    this->mPolys[0] = (UFG::UIRenderQuad *)v6;
  }
  p_mRotationMatrix = &this->mRotationMatrix;
  this->mPolys[0]->Matrix = &this->mRotationMatrix;
  if ( !this->mPolys[1] )
  {
    v7 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v7 + 13) = 1092616192;
    *((_QWORD *)v7 + 1) = 0i64;
    *((_DWORD *)v7 + 8) = 1065353216;
    v7[72] = 0;
    this->mPolys[1] = (UFG::UIRenderQuad *)v7;
  }
  this->mPolys[1]->Matrix = p_mRotationMatrix;
  if ( !this->mPolys[2] )
  {
    v8 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v8 + 13) = 1092616192;
    *((_QWORD *)v8 + 1) = 0i64;
    *((_DWORD *)v8 + 8) = 1065353216;
    v8[72] = 0;
    this->mPolys[2] = (UFG::UIRenderQuad *)v8;
  }
  this->mPolys[2]->Matrix = p_mRotationMatrix;
  if ( !this->mPolys[3] )
  {
    v9 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v9 + 13) = 1092616192;
    *((_QWORD *)v9 + 1) = 0i64;
    *((_DWORD *)v9 + 8) = 1065353216;
    v9[72] = 0;
    this->mPolys[3] = (UFG::UIRenderQuad *)v9;
  }
  this->mPolys[3]->Matrix = p_mRotationMatrix;
  v3 = UFG::qMatrix44::msIdentity.v1;
  v4 = UFG::qMatrix44::msIdentity.v2;
  v5 = UFG::qMatrix44::msIdentity.v3;
  p_mRotationMatrix->v0 = UFG::qMatrix44::msIdentity.v0;
  this->mRotationMatrix.v1 = v3;
  this->mRotationMatrix.v2 = v4;
  this->mRotationMatrix.v3 = v5;
}

// File Line: 994
// RVA: 0xCE4A0
void __fastcall UFG::UIMapBlipGraphicPlayerArrow::UpdateTransform(
        UFG::UIMapBlipGraphicPlayerArrow *this,
        float rot,
        int x,
        int y)
{
  UFG::qRotationMatrixZ(&this->mRotationMatrix, (float)(rot * 3.1415927) * 0.0055555557);
  this->mRotationMatrix.v3.z = 0.0;
  this->mRotationMatrix.v3.w = 1.0;
  this->mRotationMatrix.v3.x = (float)x;
  this->mRotationMatrix.v3.y = (float)y;
}

