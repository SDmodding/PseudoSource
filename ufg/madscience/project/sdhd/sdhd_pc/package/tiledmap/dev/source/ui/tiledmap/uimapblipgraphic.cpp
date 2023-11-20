// File Line: 54
// RVA: 0x14608B0
__int64 UFG::_dynamic_initializer_for__uid_FX_Feathered_Circle_2__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("FX_Feathered_Circle_2", 0xFFFFFFFF);
  uid_FX_Feathered_Circle_2 = result;
  return result;
}

// File Line: 55
// RVA: 0x14608D0
__int64 UFG::_dynamic_initializer_for__uid_HUD_Minimap_Outer_Ring__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("HUD_Minimap_Outer_Ring", 0xFFFFFFFF);
  uid_HUD_Minimap_Outer_Ring = result;
  return result;
}

// File Line: 56
// RVA: 0x1460870
__int64 UFG::_dynamic_initializer_for__uid_CopRadiusIndicator__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("CopRadiusIndicator", 0xFFFFFFFF);
  uid_CopRadiusIndicator = result;
  return result;
}

// File Line: 57
// RVA: 0x1460890
__int64 UFG::_dynamic_initializer_for__uid_CopRadiusPulse__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("CopRadiusPulse", 0xFFFFFFFF);
  uid_CopRadiusPulse = result;
  return result;
}

// File Line: 58
// RVA: 0x14608F0
__int64 UFG::_dynamic_initializer_for__uid_Icon_Minimap_TextureSheet__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Icon_Minimap_TextureSheet", 0xFFFFFFFF);
  uid_Icon_Minimap_TextureSheet = result;
  return result;
}

// File Line: 73
// RVA: 0xBB9B0
void __fastcall UFG::UIMapBlipGraphic::UIMapBlipGraphic(UFG::UIMapBlipGraphic *this)
{
  UFG::UIRenderQuad *v1; // rax

  this->mAnimateBlink = 0;
  *(_QWORD *)&this->mBlinkScale = 1065353216i64;
  this->mBlinkTimesMax = 5;
  this->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphic::`vftable';
  v1 = &this->mIconPoly;
  v1->Size = 10.0;
  v1->Matrix = 0i64;
  v1->Scale = 1.0;
  v1->Visible = 0;
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
  signed __int64 v2; // rdi

  v1 = (void **)&this->mPolys[1];
  v2 = 4i64;
  this->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphic::`vftable';
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
void __fastcall UFG::UIMapBlipGraphic::CalculateUVsFromIndex(UFG::UIMapBlipGraphic *this, UFG::UIMapBlipGraphic::eIconPolyComps polyType, int requestedTexturePageIndex)
{
  int v3; // ebx
  UFG::UIMapBlipGraphic *v4; // rdi
  __int64 v5; // rsi
  char *v6; // rdx
  unsigned int v7; // ecx
  float v8; // xmm0_4
  unsigned int v9; // eax

  v3 = requestedTexturePageIndex;
  v4 = this;
  v5 = (signed int)polyType;
  v6 = (char *)this->mPolys[polyType];
  if ( !v6 )
  {
    v6 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v6 + 13) = 1092616192;
    *((_QWORD *)v6 + 1) = 0i64;
    *((_DWORD *)v6 + 8) = 1065353216;
    v6[72] = 0;
    v4->mPolys[v5] = (UFG::UIRenderQuad *)v6;
  }
  switch ( v3 )
  {
    case 100:
      v9 = uid_FX_Feathered_Circle_2;
      goto LABEL_17;
    case 101:
      v9 = uid_HUD_Minimap_Outer_Ring;
      goto LABEL_17;
    case 102:
      v9 = uid_CopRadiusIndicator;
      goto LABEL_17;
    case 103:
      v9 = uid_CopRadiusPulse;
LABEL_17:
      *(_DWORD *)v6 = v9;
      goto LABEL_18;
  }
  *(_DWORD *)v6 = uid_Icon_Minimap_TextureSheet;
  if ( v3 >= 100 )
  {
LABEL_18:
    *((_QWORD *)v6 + 2) = 0i64;
    *((_DWORD *)v6 + 6) = 1065353216;
    *((_DWORD *)v6 + 7) = 1065353216;
    return;
  }
  v7 = v3;
  if ( v3 == 99 )
    v7 = 23;
  v8 = (float)(v7 >> 3) * 0.125;
  *((float *)v6 + 4) = (float)(v7 & 7) * 0.125;
  *((_DWORD *)v6 + 6) = 1040187392;
  if ( v3 == 99 )
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
void __fastcall UFG::UIMapBlipGraphic::RemovePoly(UFG::UIMapBlipGraphic *this, UFG::UIMapBlipGraphic::eIconPolyComps polyType)
{
  UFG::UIMapBlipGraphic *v2; // rbx
  __int64 v3; // rdi
  char *v4; // rax

  v2 = this;
  v3 = (signed int)polyType;
  v4 = (char *)this->mPolys[polyType];
  if ( !v4 )
  {
    v4 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v4 + 13) = 1092616192;
    *((_QWORD *)v4 + 1) = 0i64;
    *((_DWORD *)v4 + 8) = 1065353216;
    v4[72] = 0;
    v2->mPolys[v3] = (UFG::UIRenderQuad *)v4;
  }
  v4[72] = 0;
}

// File Line: 201
// RVA: 0xCB320
void __fastcall UFG::UIMapBlipGraphic::SetPos(UFG::UIMapBlipGraphic *this, UFG::UIMapBlipGraphic::eIconPolyComps polyType, float x, float y)
{
  UFG::UIMapBlipGraphic *v4; // rbx
  __int64 v5; // rdi
  char *v6; // rax

  v4 = this;
  v5 = (signed int)polyType;
  v6 = (char *)this->mPolys[polyType];
  if ( !v6 )
  {
    v6 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v6 + 13) = 1092616192;
    *((_QWORD *)v6 + 1) = 0i64;
    *((_DWORD *)v6 + 8) = 1065353216;
    v6[72] = 0;
    v4->mPolys[v5] = (UFG::UIRenderQuad *)v6;
  }
  *((float *)v6 + 9) = x;
  *((float *)v6 + 10) = y;
}

// File Line: 208
// RVA: 0xCB270
void __fastcall UFG::UIMapBlipGraphic::SetPolyOffset(UFG::UIMapBlipGraphic *this, UFG::UIMapBlipGraphic::eIconPolyComps polyType, __int16 x, __int16 y)
{
  __int16 v4; // si
  __int16 v5; // bp
  UFG::UIMapBlipGraphic *v6; // rbx
  __int64 v7; // rdi
  char *v8; // rdx

  v4 = y;
  v5 = x;
  v6 = this;
  v7 = (signed int)polyType;
  v8 = (char *)this->mPolys[polyType];
  if ( !v8 )
  {
    v8 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v8 + 13) = 1092616192;
    *((_QWORD *)v8 + 1) = 0i64;
    *((_DWORD *)v8 + 8) = 1065353216;
    v8[72] = 0;
    v6->mPolys[v7] = (UFG::UIRenderQuad *)v8;
  }
  *((float *)v8 + 11) = (float)v5;
  *((float *)v8 + 12) = (float)v4;
}

// File Line: 215
// RVA: 0xCB190
void __fastcall UFG::UIMapBlipGraphic::SetPolyInfo(UFG::UIMapBlipGraphic *this, UFG::UIMapBlipGraphic::eIconPolyComps polyType, float size, UFG::qColour *color, int texturePageIndex)
{
  UFG::qColour *v5; // r14
  __int64 v6; // rdi
  UFG::UIMapBlipGraphic *v7; // rbx
  char *v8; // r8

  v5 = color;
  v6 = (signed int)polyType;
  v7 = this;
  v8 = (char *)this->mPolys[polyType];
  if ( !v8 )
  {
    v8 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v8 + 13) = 1092616192;
    *((_QWORD *)v8 + 1) = 0i64;
    *((_DWORD *)v8 + 8) = 1065353216;
    v8[72] = 0;
    v7->mPolys[v6] = (UFG::UIRenderQuad *)v8;
  }
  *((_DWORD *)v8 + 14) = LODWORD(v5->r);
  *((_DWORD *)v8 + 15) = LODWORD(v5->g);
  *((_DWORD *)v8 + 16) = LODWORD(v5->b);
  *((_DWORD *)v8 + 17) = LODWORD(v5->a);
  *((float *)v8 + 13) = size;
  *(_QWORD *)(v8 + 36) = 0i64;
  *(_QWORD *)(v8 + 44) = 0i64;
  v8[72] = 1;
  UFG::UIMapBlipGraphic::SetAlpha(v7, (UFG::UIMapBlipGraphic::eIconPolyComps)v6, 1.0);
  if ( texturePageIndex != -1 )
    UFG::UIMapBlipGraphic::CalculateUVsFromIndex(v7, (UFG::UIMapBlipGraphic::eIconPolyComps)v6, texturePageIndex);
}

// File Line: 259
// RVA: 0xCA460
void __fastcall UFG::UIMapBlipGraphic::SetAlpha(UFG::UIMapBlipGraphic *this, UFG::UIMapBlipGraphic::eIconPolyComps polyType, float alpha)
{
  UFG::UIMapBlipGraphic *v3; // rbx
  __int64 v4; // rdi
  char *v5; // rax

  v3 = this;
  v4 = (signed int)polyType;
  v5 = (char *)this->mPolys[polyType];
  if ( !v5 )
  {
    v5 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v5 + 13) = 1092616192;
    *((_QWORD *)v5 + 1) = 0i64;
    *((_DWORD *)v5 + 8) = 1065353216;
    v5[72] = 0;
    v3->mPolys[v4] = (UFG::UIRenderQuad *)v5;
  }
  *((float *)v5 + 17) = alpha;
}

// File Line: 275
// RVA: 0xCB700
void __fastcall UFG::UIMapBlipGraphic::SetScale(UFG::UIMapBlipGraphic *this, UFG::UIMapBlipGraphic::eIconPolyComps polyType, float scale)
{
  UFG::UIMapBlipGraphic *v3; // rbx
  __int64 v4; // rdi
  char *v5; // rax

  v3 = this;
  v4 = (signed int)polyType;
  v5 = (char *)this->mPolys[polyType];
  if ( !v5 )
  {
    v5 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v5 + 13) = 1092616192;
    *((_QWORD *)v5 + 1) = 0i64;
    *((_DWORD *)v5 + 8) = 1065353216;
    v5[72] = 0;
    v3->mPolys[v4] = (UFG::UIRenderQuad *)v5;
  }
  *((float *)v5 + 8) = scale;
}

// File Line: 281
// RVA: 0xCA660
void __fastcall UFG::UIMapBlipGraphic::SetColor(UFG::UIMapBlipGraphic *this, UFG::UIMapBlipGraphic::eIconPolyComps polyType, UFG::qColour *color)
{
  UFG::qColour *v3; // rbx
  UFG::UIMapBlipGraphic *v4; // rdi
  __int64 v5; // rsi
  char *v6; // rdx

  v3 = color;
  v4 = this;
  v5 = (signed int)polyType;
  v6 = (char *)this->mPolys[polyType];
  if ( !v6 )
  {
    v6 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v6 + 13) = 1092616192;
    *((_QWORD *)v6 + 1) = 0i64;
    *((_DWORD *)v6 + 8) = 1065353216;
    v6[72] = 0;
    v4->mPolys[v5] = (UFG::UIRenderQuad *)v6;
  }
  *((_DWORD *)v6 + 14) = LODWORD(v3->r);
  *((_DWORD *)v6 + 15) = LODWORD(v3->g);
  *((_DWORD *)v6 + 16) = LODWORD(v3->b);
  *((_DWORD *)v6 + 17) = LODWORD(v3->a);
}

// File Line: 287
// RVA: 0xC67C0
void __fastcall UFG::UIMapBlipGraphic::QueueIconToRender(UFG::UIMapBlipGraphic *this, UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeClipped, UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeNotClipped, UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeDoubleClipped)
{
  UFG::qArray<UFG::UIRenderQuad,0> *v4; // rsi
  UFG::UIRenderQuad *v5; // rdx
  UFG::qArray<UFG::UIRenderQuad,0> *v6; // rbp
  UFG::qArray<UFG::UIRenderQuad,0> *v7; // rdi
  UFG::UIMapBlipGraphic *v8; // rbx
  UFG::UIRenderQuad *v9; // rdx
  UFG::UIRenderQuad *v10; // rdx
  UFG::UIRenderQuad *v11; // rdx
  UFG::UIRenderQuad *v12; // rax

  v4 = polyListNativeClipped;
  v5 = this->mPolys[1];
  v6 = polyListNativeDoubleClipped;
  v7 = polyListNativeNotClipped;
  v8 = this;
  if ( v5 && v5->Visible && v5->Color.a > 0.001 )
    UFG::qArray<UFG::UIRenderQuad,0>::Add(polyListNativeNotClipped, v5, "qArray.Add");
  v9 = v8->mPolys[0];
  if ( v9->Visible && v9->Color.a > 0.001 )
    UFG::qArray<UFG::UIRenderQuad,0>::Add(v7, v9, "qArray.Add");
  v10 = v8->mPolys[4];
  if ( v10 && v10->Visible && v10->Color.a > 0.001 )
    UFG::qArray<UFG::UIRenderQuad,0>::Add(v7, v10, "qArray.Add");
  v11 = v8->mPolys[2];
  if ( v11 )
  {
    if ( v11->Visible )
    {
      if ( v11->Color.a > 0.001 )
      {
        v12 = v8->mPolys[3];
        if ( v12 )
        {
          if ( v12->Visible && v12->Color.a > 0.001 )
          {
            UFG::qArray<UFG::UIRenderQuad,0>::Add(v6, v8->mPolys[3], "qArray.Add");
            UFG::qArray<UFG::UIRenderQuad,0>::Add(v6, v8->mPolys[2], "qArray.Add");
            v11 = v8->mPolys[3];
LABEL_22:
            UFG::qArray<UFG::UIRenderQuad,0>::Add(v4, v11, "qArray.Add");
            return;
          }
        }
      }
    }
    if ( v11 && v11->Visible && v11->Color.a > 0.001 )
      goto LABEL_22;
  }
}

// File Line: 322
// RVA: 0xCA4E0
void __fastcall UFG::UIMapBlipGraphic::SetBlink(UFG::UIMapBlipGraphic *this)
{
  UFG::UIMapBlipGraphic *v1; // rbx
  UFG::qColour v2; // xmm6
  float v3; // xmm7_4
  UFG::UIRenderQuad *v4; // rax
  UFG::UIRenderQuad *v5; // rcx
  char *v6; // [rsp+60h] [rbp+8h]
  char *v7; // [rsp+60h] [rbp+8h]
  char *v8; // [rsp+60h] [rbp+8h]

  v1 = this;
  if ( this->mAnimateBlink )
  {
    this->mBlinkTimesLooped = 0;
  }
  else
  {
    this->mAnimateBlink = 1;
    this->mBlinkScale = 0.050000001;
    v2 = this->mPolys[0]->Color;
    v3 = (float)dword_142034218;
    if ( !this->mPolys[1] )
    {
      v6 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v6 + 13) = 1092616192;
      *((_QWORD *)v6 + 1) = 0i64;
      *((_DWORD *)v6 + 8) = 1065353216;
      v6[72] = 0;
      v1->mPolys[1] = (UFG::UIRenderQuad *)v6;
    }
    v4 = v1->mPolys[1];
    v4->Color = v2;
    v4->Size = v3;
    *(_QWORD *)&v4->X = 0i64;
    *(_QWORD *)&v4->OffsetX = 0i64;
    v4->Visible = 1;
    if ( !v1->mPolys[1] )
    {
      v7 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v7 + 13) = 1092616192;
      *((_QWORD *)v7 + 1) = 0i64;
      *((_DWORD *)v7 + 8) = 1065353216;
      v7[72] = 0;
      v1->mPolys[1] = (UFG::UIRenderQuad *)v7;
    }
    v1->mPolys[1]->Color.a = 1.0;
    if ( !v1->mPolys[1] )
    {
      v8 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v8 + 13) = 1092616192;
      *((_QWORD *)v8 + 1) = 0i64;
      *((_DWORD *)v8 + 8) = 1065353216;
      v8[72] = 0;
      v1->mPolys[1] = (UFG::UIRenderQuad *)v8;
    }
    v5 = v1->mPolys[1];
    v5->TextureID = uid_CopRadiusPulse;
    *(_QWORD *)v5->UVs = 0i64;
    v5->UVs[2] = 1.0;
    v5->UVs[3] = 1.0;
    UFG::UIMapBlipGraphic::SetScale(v1, PulseAnimPoly, v1->mBlinkScale);
    v1->mBlinkTimesLooped = 0;
  }
}

// File Line: 338
// RVA: 0xCB980
void __fastcall UFG::UIMapBlipGraphic::StopBlink(UFG::UIMapBlipGraphic *this)
{
  UFG::UIMapBlipGraphic *v1; // rbx
  char *v2; // [rsp+40h] [rbp+8h]

  v1 = this;
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
      v1->mPolys[1] = (UFG::UIRenderQuad *)v2;
    }
    v1->mPolys[1]->Visible = 0;
  }
}

// File Line: 347
// RVA: 0xCD150
void __fastcall UFG::UIMapBlipGraphic::UpdateAnimation(UFG::UIMapBlipGraphic *this)
{
  UFG::UIMapBlipGraphic *v1; // rbx
  float v2; // xmm0_4
  float v3; // xmm2_4
  float v4; // xmm6_4

  v1 = this;
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
    v3 = this->mBlinkScale;
    v4 = 1.0 - (float)((float)(v3 - 1.2) * 0.35714287);
    if ( v4 >= 1.0 )
      v4 = *(float *)&FLOAT_1_0;
    UFG::UIMapBlipGraphic::SetScale(this, PulseAnimPoly, v3);
    UFG::UIMapBlipGraphic::SetAlpha(v1, PulseAnimPoly, v4);
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
      UFG::UIMapBlipGraphic::SetAlpha((UFG::UIMapBlipGraphic *)&this->vfptr, 0, 0.99000001);
      return;
    }
    this->mAlpha = v1;
    UFG::UIMapBlipGraphic::SetAlpha((UFG::UIMapBlipGraphic *)&this->vfptr, 0, v1);
  }
}

// File Line: 384
// RVA: 0xCD200
void __fastcall UFG::UIMapBlipGraphicCop::UpdateAnimation(UFG::UIMapBlipGraphicCop *this)
{
  UFG::UIMapBlipGraphicCop *v1; // rbx
  float v2; // xmm0_4
  UFG::qColour *v3; // r8
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm6_4
  float v9; // xmm5_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm5_4
  UFG::UIHKScreenHud *v17; // rax
  float v18; // xmm0_4

  v1 = this;
  v2 = sinf((float)(signed int)this->mFrameCount * 0.1);
  v3 = &v1->mColor;
  v1->mWeight = v2;
  if ( v2 <= 0.0 )
  {
    LODWORD(v12) = LODWORD(v2) & _xmm;
    v13 = UFG::qColour::Red.g * COERCE_FLOAT(LODWORD(v2) & _xmm);
    v14 = UFG::qColour::Red.b * COERCE_FLOAT(LODWORD(v2) & _xmm);
    v15 = (float)(1.0 - COERCE_FLOAT(LODWORD(v2) & _xmm)) * UFG::qColour::White.g;
    v16 = (float)(1.0 - COERCE_FLOAT(LODWORD(v2) & _xmm)) * UFG::qColour::White.b;
    v11 = UFG::qColour::Red.a + UFG::qColour::White.a;
    v3->r = (float)((float)(1.0 - v12) * UFG::qColour::White.r) + (float)(UFG::qColour::Red.r * v12);
    v1->mColor.g = v15 + v13;
    v1->mColor.b = v16 + v14;
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
    v3->r = v8 + v4;
    v1->mColor.g = v9 + v5;
    v1->mColor.b = v10 + v6;
  }
  v1->mColor.a = v11;
  UFG::UIMapBlipGraphic::SetColor((UFG::UIMapBlipGraphic *)&v1->vfptr, 0, v3);
  ++v1->mFrameCount;
  v17 = UFG::UIHKScreenHud::getInstance();
  if ( v17 )
  {
    v18 = UFG::UIHKScreenHud::GetMapZoomFactor(v17);
    UFG::UIMapBlipGraphic::SetScale((UFG::UIMapBlipGraphic *)&v1->vfptr, PulseAnimPoly, v18);
  }
}

// File Line: 474
// RVA: 0xC1540
UFG::UIMapBlipGraphic *__fastcall UFG::UIMapBlipGraphicFactory::GetNativeIconInstance(UFG::UIMapBlipGraphicFactory *this, UFG::qSymbol *type)
{
  signed int v2; // esi
  unsigned int v3; // eax
  char *v4; // rax
  UFG::UIMapBlipGraphic *v5; // rax
  UFG::UIMapBlipGraphic *v6; // rbx
  UFG::qColour v7; // xmm6
  UFG::UIRenderQuad *v8; // rcx
  UFG::UIRenderQuad *v9; // rcx
  char *v10; // rax
  signed __int64 v11; // rax
  UFG::qColour v12; // xmm6
  UFG::UIRenderQuad *v13; // rcx
  UFG::UIRenderQuad *v14; // rcx
  char *v15; // rax
  signed __int64 v16; // rax
  UFG::qColour v17; // xmm6
  UFG::UIRenderQuad *v18; // rcx
  UFG::UIRenderQuad *v19; // rcx
  char *v20; // rax
  signed __int64 v21; // rax
  char *v22; // rax
  signed __int64 v23; // rax
  UFG::qColour v24; // xmm0
  char *v25; // rax
  signed __int64 v26; // rax
  char *v27; // rax
  UFG::UIMapBlipGraphic *v28; // rax
  char *v29; // rax
  UFG::UIMapBlipGraphic *v30; // rax
  char *v31; // rax
  signed __int64 v32; // rax
  char *v33; // rax
  signed __int64 v34; // rax
  char *v35; // rax
  signed __int64 v36; // rax
  char *v37; // rax
  signed __int64 v38; // rax
  char *v39; // rax
  signed __int64 v40; // rax
  char *v41; // rax
  signed __int64 v42; // rax
  char *v43; // rax
  UFG::UIMapBlipGraphic *v44; // rax
  char *v45; // rax
  signed __int64 v46; // rax
  char *v47; // rax
  signed __int64 v48; // rax
  char *v49; // rax
  signed __int64 v50; // rax
  char *v51; // rax
  signed __int64 v52; // rax
  char *v53; // rax
  signed __int64 v54; // rax
  char *v55; // rax
  signed __int64 v56; // rax
  char *v57; // rax
  signed __int64 v58; // rax
  char *v59; // rax
  signed __int64 v60; // rax
  char *v61; // rax
  signed __int64 v62; // rax
  char *v63; // rax
  signed __int64 v64; // rax
  char *v65; // rax
  signed __int64 v66; // rax
  char *v67; // rax
  signed __int64 v68; // rax
  char *v69; // rax
  signed __int64 v70; // rax
  char *v71; // rax
  signed __int64 v72; // rax
  char *v73; // rax
  signed __int64 v74; // rax
  char *v75; // rax
  signed __int64 v76; // rax
  char *v77; // rax
  signed __int64 v78; // rax
  char *v79; // rax
  signed __int64 v80; // rax
  char *v81; // rax
  signed __int64 v82; // rax
  char *v83; // rax
  signed __int64 v84; // rax
  char *v85; // rax
  signed __int64 v86; // rax
  char *v87; // rax
  signed __int64 v88; // rax
  char *v89; // rax
  UFG::UIMapBlipGraphic *v90; // rax
  char *v91; // rax
  UFG::UIMapBlipGraphic *v92; // rax
  char *v93; // rax
  UFG::UIMapBlipGraphic *v94; // rax
  char *v95; // rax
  UFG::UIMapBlipGraphic *v96; // rax
  char *v97; // rax
  UFG::UIMapBlipGraphic *v98; // rax
  char *v99; // rax
  signed __int64 v100; // rax
  char *v101; // rax
  signed __int64 v102; // rax
  char *v103; // rax
  signed __int64 v104; // rax
  char *v105; // rax
  signed __int64 v106; // rax
  char *v107; // rax
  signed __int64 v108; // rax
  char *v109; // rax
  signed __int64 v110; // rax
  char *v111; // rax
  signed __int64 v112; // rax
  char *v113; // rax
  signed __int64 v114; // rax
  char *v115; // rax
  signed __int64 v116; // rax
  char *v117; // rax
  signed __int64 v118; // rax
  char *v119; // rax
  signed __int64 v120; // rax
  char *v121; // rax
  signed __int64 v122; // rax
  char *v123; // rax
  signed __int64 v124; // rax
  char *v125; // rax
  signed __int64 v126; // rax
  char *v127; // rax
  signed __int64 v128; // rax
  char *v129; // rax
  signed __int64 v130; // rax
  char *v131; // rax
  signed __int64 v132; // rax
  char *v133; // rax
  signed __int64 v134; // rax
  char *v135; // rax
  signed __int64 v136; // rax
  char *v137; // rax
  signed __int64 v138; // rax
  char *v139; // rax
  UFG::UIMapBlipGraphic *v140; // rax
  char *v141; // rax
  signed __int64 v142; // rax
  char *v143; // rax
  signed __int64 v144; // rax
  char *v145; // rax
  signed __int64 v146; // rax
  char *v147; // rax
  signed __int64 v148; // rax
  char *v149; // rax
  signed __int64 v150; // rax
  char *v151; // rax
  signed __int64 v152; // rax
  char *v153; // rax
  signed __int64 v154; // rax
  char *v155; // rax
  signed __int64 v156; // rax
  char *v157; // rax
  signed __int64 v158; // rax
  char *v159; // rax
  signed __int64 v160; // rax
  char *v161; // rax
  signed __int64 v162; // rax
  char *v163; // rax
  signed __int64 v164; // rax
  char *v165; // rax
  signed __int64 v166; // rax
  char *v167; // rax
  signed __int64 v168; // rax
  char *v169; // rax
  signed __int64 v170; // rax
  char *v171; // rax
  signed __int64 v172; // rax
  char *v173; // rax
  UFG::UIMapBlipGraphic *v174; // rax
  char *v175; // rax
  UFG::UIMapBlipGraphic *v176; // rax
  char *v177; // rax
  UFG::UIMapBlipGraphic *v178; // rax
  char *v179; // rax
  UFG::UIMapBlipGraphic *v180; // rax
  char *v181; // rax
  UFG::UIMapBlipGraphic *v182; // rax
  char *v183; // rax
  UFG::UIMapBlipGraphic *v184; // rax
  char *v185; // rax
  UFG::UIMapBlipGraphic *v186; // rax
  char *v187; // rax
  UFG::UIMapBlipGraphic *v188; // rax
  char *v189; // rax
  UFG::UIMapBlipGraphic *v190; // rax
  char *v191; // rax
  UFG::UIMapBlipGraphic *v192; // rax
  char *v193; // rax
  UFG::UIMapBlipGraphic *v194; // rax
  char *v195; // rax
  UFG::UIMapBlipGraphic *v196; // rax
  char *v197; // rax
  __int64 v198; // rax
  char *v199; // rax
  UFG::UIMapBlipGraphic *v200; // rax
  char *v201; // rax
  UFG::UIMapBlipGraphic *v202; // rax
  int v204; // [rsp+20h] [rbp-40h]
  UFG::qColour v205; // [rsp+40h] [rbp-20h]
  char *v206; // [rsp+78h] [rbp+18h]
  char *v207; // [rsp+78h] [rbp+18h]
  char *v208; // [rsp+78h] [rbp+18h]
  char *v209; // [rsp+78h] [rbp+18h]
  char *v210; // [rsp+78h] [rbp+18h]
  char *v211; // [rsp+78h] [rbp+18h]
  char *v212; // [rsp+78h] [rbp+18h]
  char *v213; // [rsp+78h] [rbp+18h]
  char *v214; // [rsp+78h] [rbp+18h]

  v2 = dword_142034218;
  v3 = type->mUID;
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
    if ( !v6->mPolys[0] )
    {
      v206 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v206 + 13) = 1092616192;
      *((_QWORD *)v206 + 1) = 0i64;
      *((_DWORD *)v206 + 8) = 1065353216;
      v206[72] = 0;
      v6->mPolys[0] = (UFG::UIRenderQuad *)v206;
    }
    v8 = v6->mPolys[0];
    v8->Color = v7;
    v8->Size = (float)v2;
    *(_QWORD *)&v8->X = 0i64;
    *(_QWORD *)&v8->OffsetX = 0i64;
    v8->Visible = 1;
    if ( !v6->mPolys[0] )
    {
      v207 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v207 + 13) = 1092616192;
      *((_QWORD *)v207 + 1) = 0i64;
      *((_DWORD *)v207 + 8) = 1065353216;
      v207[72] = 0;
      v6->mPolys[0] = (UFG::UIRenderQuad *)v207;
    }
    v6->mPolys[0]->Color.a = 1.0;
    if ( !v6->mPolys[0] )
    {
      v208 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v208 + 13) = 1092616192;
      *((_QWORD *)v208 + 1) = 0i64;
      *((_DWORD *)v208 + 8) = 1065353216;
      v208[72] = 0;
      v6->mPolys[0] = (UFG::UIRenderQuad *)v208;
    }
    v9 = v6->mPolys[0];
    v9->TextureID = uid_Icon_Minimap_TextureSheet;
    *(_QWORD *)v9->UVs = 0i64;
    v9->UVs[2] = 0.125;
    v9->UVs[3] = 0.125;
    return v6;
  }
  if ( v3 == UIBlipIcon_Waypoint.mUID )
  {
    v10 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
    v6 = (UFG::UIMapBlipGraphic *)v10;
    if ( v10 )
    {
      *(_QWORD *)v10 = &UFG::UIMapBlipGraphic::`vftable';
      v10[8] = 0;
      *(_QWORD *)(v10 + 12) = 1065353216i64;
      *((_DWORD *)v10 + 5) = 5;
      v11 = (signed __int64)(v10 + 64);
      *(_DWORD *)(v11 + 52) = 1092616192;
      *(_QWORD *)(v11 + 8) = 0i64;
      *(_DWORD *)(v11 + 32) = 1065353216;
      *(_BYTE *)(v11 + 72) = 0;
      v6->mPolys[0] = &v6->mIconPoly;
      v6->mPolys[1] = 0i64;
      v6->mPolys[2] = 0i64;
      v6->mPolys[3] = 0i64;
      v6->mPolys[4] = 0i64;
    }
    else
    {
      v6 = 0i64;
    }
    v12 = UFG::qColour::White;
    if ( !v6->mPolys[0] )
    {
      v209 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v209 + 13) = 1092616192;
      *((_QWORD *)v209 + 1) = 0i64;
      *((_DWORD *)v209 + 8) = 1065353216;
      v209[72] = 0;
      v6->mPolys[0] = (UFG::UIRenderQuad *)v209;
    }
    v13 = v6->mPolys[0];
    v13->Color = v12;
    v13->Size = (float)v2;
    *(_QWORD *)&v13->X = 0i64;
    *(_QWORD *)&v13->OffsetX = 0i64;
    v13->Visible = 1;
    if ( !v6->mPolys[0] )
    {
      v210 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v210 + 13) = 1092616192;
      *((_QWORD *)v210 + 1) = 0i64;
      *((_DWORD *)v210 + 8) = 1065353216;
      v210[72] = 0;
      v6->mPolys[0] = (UFG::UIRenderQuad *)v210;
    }
    v6->mPolys[0]->Color.a = 1.0;
    if ( !v6->mPolys[0] )
    {
      v211 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v211 + 13) = 1092616192;
      *((_QWORD *)v211 + 1) = 0i64;
      *((_DWORD *)v211 + 8) = 1065353216;
      v211[72] = 0;
      v6->mPolys[0] = (UFG::UIRenderQuad *)v211;
    }
    v14 = v6->mPolys[0];
    v14->TextureID = uid_Icon_Minimap_TextureSheet;
    *(_QWORD *)v14->UVs = 1052770304i64;
    v14->UVs[2] = 0.125;
    v14->UVs[3] = 0.125;
    return v6;
  }
  if ( v3 != UIBlipIcon_Safehouse.mUID )
  {
    if ( v3 == UIBlipIcon_Safehouse_Unlocked.mUID )
    {
      v20 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
      v6 = (UFG::UIMapBlipGraphic *)v20;
      if ( v20 )
      {
        *(_QWORD *)v20 = &UFG::UIMapBlipGraphic::`vftable';
        v20[8] = 0;
        *(_QWORD *)(v20 + 12) = 1065353216i64;
        *((_DWORD *)v20 + 5) = 5;
        v21 = (signed __int64)(v20 + 64);
        *(_DWORD *)(v21 + 52) = 1092616192;
        *(_QWORD *)(v21 + 8) = 0i64;
        *(_DWORD *)(v21 + 32) = 1065353216;
        *(_BYTE *)(v21 + 72) = 0;
        v6->mPolys[0] = &v6->mIconPoly;
        v6->mPolys[1] = 0i64;
        v6->mPolys[2] = 0i64;
        v6->mPolys[3] = 0i64;
        v6->mPolys[4] = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v204 = 12;
    }
    else
    {
      if ( v3 == UIBlipIcon_Undercover_Safehouse.mUID )
      {
        v22 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v22;
        if ( v22 )
        {
          *(_QWORD *)v22 = &UFG::UIMapBlipGraphic::`vftable';
          v22[8] = 0;
          *(_QWORD *)(v22 + 12) = 1065353216i64;
          *((_DWORD *)v22 + 5) = 5;
          v23 = (signed __int64)(v22 + 64);
          *(_DWORD *)(v23 + 52) = 1092616192;
          *(_QWORD *)(v23 + 8) = 0i64;
          *(_DWORD *)(v23 + 32) = 1065353216;
          *(_BYTE *)(v23 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveBlue;
        v204 = 12;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_TriadWars_Safehouse.mUID )
      {
        v25 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v25;
        if ( v25 )
        {
          *(_QWORD *)v25 = &UFG::UIMapBlipGraphic::`vftable';
          v25[8] = 0;
          *(_QWORD *)(v25 + 12) = 1065353216i64;
          *((_DWORD *)v25 + 5) = 5;
          v26 = (signed __int64)(v25 + 64);
          *(_DWORD *)(v26 + 52) = 1092616192;
          *(_QWORD *)(v26 + 8) = 0i64;
          *(_DWORD *)(v26 + 32) = 1065353216;
          *(_BYTE *)(v26 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::AmbientBlue;
        v204 = 12;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Mission_Start.mUID )
      {
        v27 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        if ( v27 )
        {
          UFG::UIMapBlipGraphicMissionObjective::UIMapBlipGraphicMissionObjective((UFG::UIMapBlipGraphicMissionObjective *)v27);
          v6 = v28;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveGreen;
        v204 = 4;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Mission_Objective.mUID )
      {
        v29 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        if ( v29 )
        {
          UFG::UIMapBlipGraphicMissionObjective::UIMapBlipGraphicMissionObjective((UFG::UIMapBlipGraphicMissionObjective *)v29);
          v6 = v30;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveGreen;
        v204 = 3;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Race_Start.mUID )
      {
        v31 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v31;
        if ( v31 )
        {
          *(_QWORD *)v31 = &UFG::UIMapBlipGraphic::`vftable';
          v31[8] = 0;
          *(_QWORD *)(v31 + 12) = 1065353216i64;
          *((_DWORD *)v31 + 5) = 5;
          v32 = (signed __int64)(v31 + 64);
          *(_DWORD *)(v32 + 52) = 1092616192;
          *(_QWORD *)(v32 + 8) = 0i64;
          *(_DWORD *)(v32 + 32) = 1065353216;
          *(_BYTE *)(v32 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveOrange;
        v204 = 22;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Race_Start_Flag.mUID )
      {
        v33 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v33;
        if ( v33 )
        {
          *(_QWORD *)v33 = &UFG::UIMapBlipGraphic::`vftable';
          v33[8] = 0;
          *(_QWORD *)(v33 + 12) = 1065353216i64;
          *((_DWORD *)v33 + 5) = 5;
          v34 = (signed __int64)(v33 + 64);
          *(_DWORD *)(v34 + 52) = 1092616192;
          *(_QWORD *)(v34 + 8) = 0i64;
          *(_DWORD *)(v34 + 32) = 1065353216;
          *(_BYTE *)(v34 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveOrange;
        v204 = 22;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Race_Objective.mUID )
      {
        v35 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v35;
        if ( v35 )
        {
          *(_QWORD *)v35 = &UFG::UIMapBlipGraphic::`vftable';
          v35[8] = 0;
          *(_QWORD *)(v35 + 12) = 1065353216i64;
          *((_DWORD *)v35 + 5) = 5;
          v36 = (signed __int64)(v35 + 64);
          *(_DWORD *)(v36 + 52) = 1092616192;
          *(_QWORD *)(v36 + 8) = 0i64;
          *(_DWORD *)(v36 + 32) = 1065353216;
          *(_BYTE *)(v36 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveRed;
        v204 = 14;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Race_End.mUID )
      {
        v37 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v37;
        if ( v37 )
        {
          *(_QWORD *)v37 = &UFG::UIMapBlipGraphic::`vftable';
          v37[8] = 0;
          *(_QWORD *)(v37 + 12) = 1065353216i64;
          *((_DWORD *)v37 + 5) = 5;
          v38 = (signed __int64)(v37 + 64);
          *(_DWORD *)(v38 + 52) = 1092616192;
          *(_QWORD *)(v38 + 8) = 0i64;
          *(_DWORD *)(v38 + 32) = 1065353216;
          *(_BYTE *)(v38 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveOrange;
        v204 = 22;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Cop_Event_Start.mUID )
      {
        v39 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v39;
        if ( v39 )
        {
          *(_QWORD *)v39 = &UFG::UIMapBlipGraphic::`vftable';
          v39[8] = 0;
          *(_QWORD *)(v39 + 12) = 1065353216i64;
          *((_DWORD *)v39 + 5) = 5;
          v40 = (signed __int64)(v39 + 64);
          *(_DWORD *)(v40 + 52) = 1092616192;
          *(_QWORD *)(v40 + 8) = 0i64;
          *(_DWORD *)(v40 + 32) = 1065353216;
          *(_BYTE *)(v40 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveBlue;
        v204 = 37;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Event_Start.mUID )
      {
        v41 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v41;
        if ( v41 )
        {
          *(_QWORD *)v41 = &UFG::UIMapBlipGraphic::`vftable';
          v41[8] = 0;
          *(_QWORD *)(v41 + 12) = 1065353216i64;
          *((_DWORD *)v41 + 5) = 5;
          v42 = (signed __int64)(v41 + 64);
          *(_DWORD *)(v42 + 52) = 1092616192;
          *(_QWORD *)(v42 + 8) = 0i64;
          *(_DWORD *)(v42 + 32) = 1065353216;
          *(_BYTE *)(v42 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveYellow;
        v204 = 36;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Event_Objective.mUID )
      {
        v43 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        if ( v43 )
        {
          UFG::UIMapBlipGraphicEventObjective::UIMapBlipGraphicEventObjective((UFG::UIMapBlipGraphicEventObjective *)v43);
          v6 = v44;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveYellow;
        v204 = 36;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Case_Start.mUID )
      {
        v45 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v45;
        if ( v45 )
        {
          *(_QWORD *)v45 = &UFG::UIMapBlipGraphic::`vftable';
          v45[8] = 0;
          *(_QWORD *)(v45 + 12) = 1065353216i64;
          *((_DWORD *)v45 + 5) = 5;
          v46 = (signed __int64)(v45 + 64);
          *(_DWORD *)(v46 + 52) = 1092616192;
          *(_QWORD *)(v46 + 8) = 0i64;
          *(_DWORD *)(v46 + 32) = 1065353216;
          *(_BYTE *)(v46 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveBlue;
        v204 = 35;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Case_Objective.mUID )
      {
        v47 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v47;
        if ( v47 )
        {
          *(_QWORD *)v47 = &UFG::UIMapBlipGraphic::`vftable';
          v47[8] = 0;
          *(_QWORD *)(v47 + 12) = 1065353216i64;
          *((_DWORD *)v47 + 5) = 5;
          v48 = (signed __int64)(v47 + 64);
          *(_DWORD *)(v48 + 52) = 1092616192;
          *(_QWORD *)(v48 + 8) = 0i64;
          *(_DWORD *)(v48 + 32) = 1065353216;
          *(_BYTE *)(v48 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveBlue;
        v204 = 35;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Job_Start.mUID )
      {
        v49 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v49;
        if ( v49 )
        {
          *(_QWORD *)v49 = &UFG::UIMapBlipGraphic::`vftable';
          v49[8] = 0;
          *(_QWORD *)(v49 + 12) = 1065353216i64;
          *((_DWORD *)v49 + 5) = 5;
          v50 = (signed __int64)(v49 + 64);
          *(_DWORD *)(v50 + 52) = 1092616192;
          *(_QWORD *)(v50 + 8) = 0i64;
          *(_DWORD *)(v50 + 32) = 1065353216;
          *(_BYTE *)(v50 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveOrange;
        v204 = 4;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Job_Objective.mUID )
      {
        v51 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v51;
        if ( v51 )
        {
          *(_QWORD *)v51 = &UFG::UIMapBlipGraphic::`vftable';
          v51[8] = 0;
          *(_QWORD *)(v51 + 12) = 1065353216i64;
          *((_DWORD *)v51 + 5) = 5;
          v52 = (signed __int64)(v51 + 64);
          *(_DWORD *)(v52 + 52) = 1092616192;
          *(_QWORD *)(v52 + 8) = 0i64;
          *(_DWORD *)(v52 + 32) = 1065353216;
          *(_BYTE *)(v52 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveOrange;
        v204 = 3;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Cop_Job.mUID )
      {
        v53 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v53;
        if ( v53 )
        {
          *(_QWORD *)v53 = &UFG::UIMapBlipGraphic::`vftable';
          v53[8] = 0;
          *(_QWORD *)(v53 + 12) = 1065353216i64;
          *((_DWORD *)v53 + 5) = 5;
          v54 = (signed __int64)(v53 + 64);
          *(_DWORD *)(v54 + 52) = 1092616192;
          *(_QWORD *)(v54 + 8) = 0i64;
          *(_DWORD *)(v54 + 32) = 1065353216;
          *(_BYTE *)(v54 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveYellow;
        v204 = 3;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Crime_Scene.mUID )
      {
        v55 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v55;
        if ( v55 )
        {
          *(_QWORD *)v55 = &UFG::UIMapBlipGraphic::`vftable';
          v55[8] = 0;
          *(_QWORD *)(v55 + 12) = 1065353216i64;
          *((_DWORD *)v55 + 5) = 5;
          v56 = (signed __int64)(v55 + 64);
          *(_DWORD *)(v56 + 52) = 1092616192;
          *(_QWORD *)(v56 + 8) = 0i64;
          *(_DWORD *)(v56 + 32) = 1065353216;
          *(_BYTE *)(v56 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveYellow;
        v204 = 3;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Enemy_Objective.mUID )
      {
        v57 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v57;
        if ( v57 )
        {
          *(_QWORD *)v57 = &UFG::UIMapBlipGraphic::`vftable';
          v57[8] = 0;
          *(_QWORD *)(v57 + 12) = 1065353216i64;
          *((_DWORD *)v57 + 5) = 5;
          v58 = (signed __int64)(v57 + 64);
          *(_DWORD *)(v58 + 52) = 1092616192;
          *(_QWORD *)(v58 + 8) = 0i64;
          *(_DWORD *)(v58 + 32) = 1065353216;
          *(_BYTE *)(v58 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveRed;
        v204 = 3;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Cop_Objective.mUID )
      {
        v59 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v59;
        if ( v59 )
        {
          *(_QWORD *)v59 = &UFG::UIMapBlipGraphic::`vftable';
          v59[8] = 0;
          *(_QWORD *)(v59 + 12) = 1065353216i64;
          *((_DWORD *)v59 + 5) = 5;
          v60 = (signed __int64)(v59 + 64);
          *(_DWORD *)(v60 + 52) = 1092616192;
          *(_QWORD *)(v60 + 8) = 0i64;
          *(_DWORD *)(v60 + 32) = 1065353216;
          *(_BYTE *)(v60 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveBlue;
        v204 = 3;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Triad_Wars.mUID )
      {
        v61 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v61;
        if ( v61 )
        {
          *(_QWORD *)v61 = &UFG::UIMapBlipGraphic::`vftable';
          v61[8] = 0;
          *(_QWORD *)(v61 + 12) = 1065353216i64;
          *((_DWORD *)v61 + 5) = 5;
          v62 = (signed __int64)(v61 + 64);
          *(_DWORD *)(v62 + 52) = 1092616192;
          *(_QWORD *)(v62 + 8) = 0i64;
          *(_DWORD *)(v62 + 32) = 1065353216;
          *(_BYTE *)(v62 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::AmbientBlue;
        v204 = 27;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_TransTerror_Start.mUID )
      {
        v63 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v63;
        if ( v63 )
        {
          *(_QWORD *)v63 = &UFG::UIMapBlipGraphic::`vftable';
          v63[8] = 0;
          *(_QWORD *)(v63 + 12) = 1065353216i64;
          *((_DWORD *)v63 + 5) = 5;
          v64 = (signed __int64)(v63 + 64);
          *(_DWORD *)(v64 + 52) = 1092616192;
          *(_QWORD *)(v64 + 8) = 0i64;
          *(_DWORD *)(v64 + 32) = 1065353216;
          *(_BYTE *)(v64 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::TransTerrorOrange;
        v204 = 14;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_TransTerror_Mission.mUID )
      {
        v65 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v65;
        if ( v65 )
        {
          *(_QWORD *)v65 = &UFG::UIMapBlipGraphic::`vftable';
          v65[8] = 0;
          *(_QWORD *)(v65 + 12) = 1065353216i64;
          *((_DWORD *)v65 + 5) = 5;
          v66 = (signed __int64)(v65 + 64);
          *(_DWORD *)(v66 + 52) = 1092616192;
          *(_QWORD *)(v66 + 8) = 0i64;
          *(_DWORD *)(v66 + 32) = 1065353216;
          *(_BYTE *)(v66 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::TransTerrorOrange;
        v204 = 3;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_TransTerror_Event.mUID )
      {
        v67 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v67;
        if ( v67 )
        {
          *(_QWORD *)v67 = &UFG::UIMapBlipGraphic::`vftable';
          v67[8] = 0;
          *(_QWORD *)(v67 + 12) = 1065353216i64;
          *((_DWORD *)v67 + 5) = 5;
          v68 = (signed __int64)(v67 + 64);
          *(_DWORD *)(v68 + 52) = 1092616192;
          *(_QWORD *)(v68 + 8) = 0i64;
          *(_DWORD *)(v68 + 32) = 1065353216;
          *(_BYTE *)(v68 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::TransTerrorOrange;
        v204 = 33;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Zodiac_Start.mUID )
      {
        v69 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v69;
        if ( v69 )
        {
          *(_QWORD *)v69 = &UFG::UIMapBlipGraphic::`vftable';
          v69[8] = 0;
          *(_QWORD *)(v69 + 12) = 1065353216i64;
          *((_DWORD *)v69 + 5) = 5;
          v70 = (signed __int64)(v69 + 64);
          *(_DWORD *)(v70 + 52) = 1092616192;
          *(_QWORD *)(v70 + 8) = 0i64;
          *(_DWORD *)(v70 + 32) = 1065353216;
          *(_BYTE *)(v70 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ZodiacOrange;
        v204 = 17;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Zodiac_Objective.mUID )
      {
        v71 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v71;
        if ( v71 )
        {
          *(_QWORD *)v71 = &UFG::UIMapBlipGraphic::`vftable';
          v71[8] = 0;
          *(_QWORD *)(v71 + 12) = 1065353216i64;
          *((_DWORD *)v71 + 5) = 5;
          v72 = (signed __int64)(v71 + 64);
          *(_DWORD *)(v72 + 52) = 1092616192;
          *(_QWORD *)(v72 + 8) = 0i64;
          *(_DWORD *)(v72 + 32) = 1065353216;
          *(_BYTE *)(v72 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ZodiacOrange;
        v204 = 3;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Zodiac_Event.mUID )
      {
        v73 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v73;
        if ( v73 )
        {
          *(_QWORD *)v73 = &UFG::UIMapBlipGraphic::`vftable';
          v73[8] = 0;
          *(_QWORD *)(v73 + 12) = 1065353216i64;
          *((_DWORD *)v73 + 5) = 5;
          v74 = (signed __int64)(v73 + 64);
          *(_DWORD *)(v74 + 52) = 1092616192;
          *(_QWORD *)(v74 + 8) = 0i64;
          *(_DWORD *)(v74 + 32) = 1065353216;
          *(_BYTE *)(v74 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveYellow;
        v204 = 3;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Zodiac_Enemy.mUID )
      {
        v75 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v75;
        if ( v75 )
        {
          *(_QWORD *)v75 = &UFG::UIMapBlipGraphic::`vftable';
          v75[8] = 0;
          *(_QWORD *)(v75 + 12) = 1065353216i64;
          *((_DWORD *)v75 + 5) = 5;
          v76 = (signed __int64)(v75 + 64);
          *(_DWORD *)(v76 + 52) = 1092616192;
          *(_QWORD *)(v76 + 8) = 0i64;
          *(_DWORD *)(v76 + 32) = 1065353216;
          *(_BYTE *)(v76 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v24 = UFG::ObjectiveRed;
        v204 = 1;
        goto LABEL_489;
      }
      if ( v3 == UIBlipIcon_Zodiac_Friendly.mUID )
      {
        v77 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
        v6 = (UFG::UIMapBlipGraphic *)v77;
        if ( v77 )
        {
          *(_QWORD *)v77 = &UFG::UIMapBlipGraphic::`vftable';
          v77[8] = 0;
          *(_QWORD *)(v77 + 12) = 1065353216i64;
          *((_DWORD *)v77 + 5) = 5;
          v78 = (signed __int64)(v77 + 64);
          *(_DWORD *)(v78 + 52) = 1092616192;
          *(_QWORD *)(v78 + 8) = 0i64;
          *(_DWORD *)(v78 + 32) = 1065353216;
          *(_BYTE *)(v78 + 72) = 0;
          v6->mPolys[0] = &v6->mIconPoly;
          v6->mPolys[1] = 0i64;
          v6->mPolys[2] = 0i64;
          v6->mPolys[3] = 0i64;
          v6->mPolys[4] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v204 = 3;
      }
      else
      {
        if ( v3 == UIBlipIcon_Lesser_Ghoul.mUID )
        {
          v79 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = (UFG::UIMapBlipGraphic *)v79;
          if ( v79 )
          {
            *(_QWORD *)v79 = &UFG::UIMapBlipGraphic::`vftable';
            v79[8] = 0;
            *(_QWORD *)(v79 + 12) = 1065353216i64;
            *((_DWORD *)v79 + 5) = 5;
            v80 = (signed __int64)(v79 + 64);
            *(_DWORD *)(v80 + 52) = 1092616192;
            *(_QWORD *)(v80 + 8) = 0i64;
            *(_DWORD *)(v80 + 32) = 1065353216;
            *(_BYTE *)(v80 + 72) = 0;
            v6->mPolys[0] = &v6->mIconPoly;
            v6->mPolys[1] = 0i64;
            v6->mPolys[2] = 0i64;
            v6->mPolys[3] = 0i64;
            v6->mPolys[4] = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v24 = GhostGreen;
          v204 = 32;
          goto LABEL_489;
        }
        if ( v3 == UIBlipIcon_Elite_Ghoul.mUID )
        {
          v81 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = (UFG::UIMapBlipGraphic *)v81;
          if ( v81 )
          {
            *(_QWORD *)v81 = &UFG::UIMapBlipGraphic::`vftable';
            v81[8] = 0;
            *(_QWORD *)(v81 + 12) = 1065353216i64;
            *((_DWORD *)v81 + 5) = 5;
            v82 = (signed __int64)(v81 + 64);
            *(_DWORD *)(v82 + 52) = 1092616192;
            *(_QWORD *)(v82 + 8) = 0i64;
            *(_DWORD *)(v82 + 32) = 1065353216;
            *(_BYTE *)(v82 + 72) = 0;
            v6->mPolys[0] = &v6->mIconPoly;
            v6->mPolys[1] = 0i64;
            v6->mPolys[2] = 0i64;
            v6->mPolys[3] = 0i64;
            v6->mPolys[4] = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v24 = GhostPurple;
          v204 = 32;
          goto LABEL_489;
        }
        if ( v3 == UIBlipIcon_Trapped_Ped.mUID )
        {
          v83 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = (UFG::UIMapBlipGraphic *)v83;
          if ( v83 )
          {
            *(_QWORD *)v83 = &UFG::UIMapBlipGraphic::`vftable';
            v83[8] = 0;
            *(_QWORD *)(v83 + 12) = 1065353216i64;
            *((_DWORD *)v83 + 5) = 5;
            v84 = (signed __int64)(v83 + 64);
            *(_DWORD *)(v84 + 52) = 1092616192;
            *(_QWORD *)(v84 + 8) = 0i64;
            *(_DWORD *)(v84 + 32) = 1065353216;
            *(_BYTE *)(v84 + 72) = 0;
            v6->mPolys[0] = &v6->mIconPoly;
            v6->mPolys[1] = 0i64;
            v6->mPolys[2] = 0i64;
            v6->mPolys[3] = 0i64;
            v6->mPolys[4] = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
          v24 = GhostGreen;
          v204 = 30;
          goto LABEL_489;
        }
        if ( v3 == UIBlipIcon_Hiding_Spot.mUID )
        {
          v85 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = (UFG::UIMapBlipGraphic *)v85;
          if ( v85 )
          {
            *(_QWORD *)v85 = &UFG::UIMapBlipGraphic::`vftable';
            v85[8] = 0;
            *(_QWORD *)(v85 + 12) = 1065353216i64;
            *((_DWORD *)v85 + 5) = 5;
            v86 = (signed __int64)(v85 + 64);
            *(_DWORD *)(v86 + 52) = 1092616192;
            *(_QWORD *)(v86 + 8) = 0i64;
            *(_DWORD *)(v86 + 32) = 1065353216;
            *(_BYTE *)(v86 + 72) = 0;
            v6->mPolys[0] = &v6->mIconPoly;
            v6->mPolys[1] = 0i64;
            v6->mPolys[2] = 0i64;
            v6->mPolys[3] = 0i64;
            v6->mPolys[4] = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
        }
        else if ( v3 == UIBlipIcon_Hiding_Spot_Garage.mUID )
        {
          v87 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
          v6 = (UFG::UIMapBlipGraphic *)v87;
          if ( v87 )
          {
            *(_QWORD *)v87 = &UFG::UIMapBlipGraphic::`vftable';
            v87[8] = 0;
            *(_QWORD *)(v87 + 12) = 1065353216i64;
            *((_DWORD *)v87 + 5) = 5;
            v88 = (signed __int64)(v87 + 64);
            *(_DWORD *)(v88 + 52) = 1092616192;
            *(_QWORD *)(v88 + 8) = 0i64;
            *(_DWORD *)(v88 + 32) = 1065353216;
            *(_BYTE *)(v88 + 72) = 0;
            v6->mPolys[0] = &v6->mIconPoly;
            v6->mPolys[1] = 0i64;
            v6->mPolys[2] = 0i64;
            v6->mPolys[3] = 0i64;
            v6->mPolys[4] = 0i64;
          }
          else
          {
            v6 = 0i64;
          }
        }
        else
        {
          if ( v3 == UIBlipIcon_Cop.mUID )
          {
            v89 = UFG::qMalloc(0xA8ui64, "UIMapBlipGraphicFactory", 0i64);
            if ( v89 )
            {
              UFG::UIMapBlipGraphicCop::UIMapBlipGraphicCop((UFG::UIMapBlipGraphicCop *)v89);
              v6 = v90;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::qColour::DogerBlue;
            v204 = 2;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Cop_OnFoot.mUID )
          {
            v91 = UFG::qMalloc(0xA8ui64, "UIMapBlipGraphicFactory", 0i64);
            if ( v91 )
            {
              UFG::UIMapBlipGraphicCop::UIMapBlipGraphicCop((UFG::UIMapBlipGraphicCop *)v91);
              v6 = v92;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::qColour::DogerBlue;
            v204 = 1;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Cop_OnFoot_Patrol.mUID )
          {
            v93 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            if ( v93 )
            {
              UFG::UIMapBlipGraphicEnemy::UIMapBlipGraphicEnemy((UFG::UIMapBlipGraphicEnemy *)v93);
              v6 = v94;
            }
            else
            {
              v6 = 0i64;
            }
            v205 = (UFG::qColour)_xmm;
            _mm_store_si128((__m128i *)&v205, (__m128i)_xmm);
            UFG::UIMapBlipGraphic::SetPolyInfo(v6, 0, (float)v2, &v205, 1);
            return v6;
          }
          if ( v3 == UIBlipIcon_Cop_Vehicle_Patrol.mUID )
          {
            v95 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            if ( v95 )
            {
              UFG::UIMapBlipGraphicEnemy::UIMapBlipGraphicEnemy((UFG::UIMapBlipGraphicEnemy *)v95);
              v6 = v96;
            }
            else
            {
              v6 = 0i64;
            }
            v205 = (UFG::qColour)_xmm;
            _mm_store_si128((__m128i *)&v205, (__m128i)_xmm);
            UFG::UIMapBlipGraphic::SetPolyInfo(v6, 0, (float)v2, &v205, 2);
            return v6;
          }
          if ( v3 == UIBlipIcon_Witness.mUID )
          {
            v97 = UFG::qMalloc(0x98ui64, "UIMapBlipGraphicFactory", 0i64);
            if ( v97 )
            {
              UFG::UIMapBlipGraphicWitness::UIMapBlipGraphicWitness((UFG::UIMapBlipGraphicWitness *)v97);
              v6 = v98;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 1;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Road_Block.mUID )
          {
            v99 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v99;
            if ( v99 )
            {
              *(_QWORD *)v99 = &UFG::UIMapBlipGraphic::`vftable';
              v99[8] = 0;
              *(_QWORD *)(v99 + 12) = 1065353216i64;
              *((_DWORD *)v99 + 5) = 5;
              v100 = (signed __int64)(v99 + 64);
              *(_DWORD *)(v100 + 52) = 1092616192;
              *(_QWORD *)(v100 + 8) = 0i64;
              *(_DWORD *)(v100 + 32) = 1065353216;
              *(_BYTE *)(v100 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 28;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Karaoke.mUID )
          {
            v101 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v101;
            if ( v101 )
            {
              *(_QWORD *)v101 = &UFG::UIMapBlipGraphic::`vftable';
              v101[8] = 0;
              *(_QWORD *)(v101 + 12) = 1065353216i64;
              *((_DWORD *)v101 + 5) = 5;
              v102 = (signed __int64)(v101 + 64);
              *(_DWORD *)(v102 + 52) = 1092616192;
              *(_QWORD *)(v102 + 8) = 0i64;
              *(_DWORD *)(v102 + 32) = 1065353216;
              *(_BYTE *)(v102 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 29;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Ferry.mUID )
          {
            v103 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v103;
            if ( v103 )
            {
              *(_QWORD *)v103 = &UFG::UIMapBlipGraphic::`vftable';
              v103[8] = 0;
              *(_QWORD *)(v103 + 12) = 1065353216i64;
              *((_DWORD *)v103 + 5) = 5;
              v104 = (signed __int64)(v103 + 64);
              *(_DWORD *)(v104 + 52) = 1092616192;
              *(_QWORD *)(v104 + 8) = 0i64;
              *(_DWORD *)(v104 + 32) = 1065353216;
              *(_BYTE *)(v104 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 8;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Bus_Stop.mUID )
          {
            v105 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v105;
            if ( v105 )
            {
              *(_QWORD *)v105 = &UFG::UIMapBlipGraphic::`vftable';
              v105[8] = 0;
              *(_QWORD *)(v105 + 12) = 1065353216i64;
              *((_DWORD *)v105 + 5) = 5;
              v106 = (signed __int64)(v105 + 64);
              *(_DWORD *)(v106 + 52) = 1092616192;
              *(_QWORD *)(v106 + 8) = 0i64;
              *(_DWORD *)(v106 + 32) = 1065353216;
              *(_BYTE *)(v106 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 9;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Pork_Bun_Vendor.mUID )
          {
            v107 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v107;
            if ( v107 )
            {
              *(_QWORD *)v107 = &UFG::UIMapBlipGraphic::`vftable';
              v107[8] = 0;
              *(_QWORD *)(v107 + 12) = 1065353216i64;
              *((_DWORD *)v107 + 5) = 5;
              v108 = (signed __int64)(v107 + 64);
              *(_DWORD *)(v108 + 52) = 1092616192;
              *(_QWORD *)(v108 + 8) = 0i64;
              *(_DWORD *)(v108 + 32) = 1065353216;
              *(_BYTE *)(v108 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 10;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Convenience_Store.mUID )
          {
            v109 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v109;
            if ( v109 )
            {
              *(_QWORD *)v109 = &UFG::UIMapBlipGraphic::`vftable';
              v109[8] = 0;
              *(_QWORD *)(v109 + 12) = 1065353216i64;
              *((_DWORD *)v109 + 5) = 5;
              v110 = (signed __int64)(v109 + 64);
              *(_DWORD *)(v110 + 52) = 1092616192;
              *(_QWORD *)(v110 + 8) = 0i64;
              *(_DWORD *)(v110 + 32) = 1065353216;
              *(_BYTE *)(v110 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 19;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Apothecary_Store.mUID )
          {
            v111 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v111;
            if ( v111 )
            {
              *(_QWORD *)v111 = &UFG::UIMapBlipGraphic::`vftable';
              v111[8] = 0;
              *(_QWORD *)(v111 + 12) = 1065353216i64;
              *((_DWORD *)v111 + 5) = 5;
              v112 = (signed __int64)(v111 + 64);
              *(_DWORD *)(v112 + 52) = 1092616192;
              *(_QWORD *)(v112 + 8) = 0i64;
              *(_DWORD *)(v112 + 32) = 1065353216;
              *(_BYTE *)(v112 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 18;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Clothing_Store.mUID )
          {
            v113 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v113;
            if ( v113 )
            {
              *(_QWORD *)v113 = &UFG::UIMapBlipGraphic::`vftable';
              v113[8] = 0;
              *(_QWORD *)(v113 + 12) = 1065353216i64;
              *((_DWORD *)v113 + 5) = 5;
              v114 = (signed __int64)(v113 + 64);
              *(_DWORD *)(v114 + 52) = 1092616192;
              *(_QWORD *)(v114 + 8) = 0i64;
              *(_DWORD *)(v114 + 32) = 1065353216;
              *(_BYTE *)(v114 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 11;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Exotic_Clothing_Store.mUID )
          {
            v115 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v115;
            if ( v115 )
            {
              *(_QWORD *)v115 = &UFG::UIMapBlipGraphic::`vftable';
              v115[8] = 0;
              *(_QWORD *)(v115 + 12) = 1065353216i64;
              *((_DWORD *)v115 + 5) = 5;
              v116 = (signed __int64)(v115 + 64);
              *(_DWORD *)(v116 + 52) = 1092616192;
              *(_QWORD *)(v116 + 8) = 0i64;
              *(_DWORD *)(v116 + 32) = 1065353216;
              *(_BYTE *)(v116 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::ExoticVendorGold;
            v204 = 11;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Gambling_Den.mUID )
          {
            v117 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v117;
            if ( v117 )
            {
              *(_QWORD *)v117 = &UFG::UIMapBlipGraphic::`vftable';
              v117[8] = 0;
              *(_QWORD *)(v117 + 12) = 1065353216i64;
              *((_DWORD *)v117 + 5) = 5;
              v118 = (signed __int64)(v117 + 64);
              *(_DWORD *)(v118 + 52) = 1092616192;
              *(_QWORD *)(v118 + 8) = 0i64;
              *(_DWORD *)(v118 + 32) = 1065353216;
              *(_BYTE *)(v118 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::ObjectiveOrange;
            v204 = 15;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Massage_Parlors.mUID )
          {
            v119 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v119;
            if ( v119 )
            {
              *(_QWORD *)v119 = &UFG::UIMapBlipGraphic::`vftable';
              v119[8] = 0;
              *(_QWORD *)(v119 + 12) = 1065353216i64;
              *((_DWORD *)v119 + 5) = 5;
              v120 = (signed __int64)(v119 + 64);
              *(_DWORD *)(v120 + 52) = 1092616192;
              *(_QWORD *)(v120 + 8) = 0i64;
              *(_DWORD *)(v120 + 32) = 1065353216;
              *(_BYTE *)(v120 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 16;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Martial_Arts_School.mUID )
          {
            v121 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v121;
            if ( v121 )
            {
              *(_QWORD *)v121 = &UFG::UIMapBlipGraphic::`vftable';
              v121[8] = 0;
              *(_QWORD *)(v121 + 12) = 1065353216i64;
              *((_DWORD *)v121 + 5) = 5;
              v122 = (signed __int64)(v121 + 64);
              *(_DWORD *)(v122 + 52) = 1092616192;
              *(_QWORD *)(v122 + 8) = 0i64;
              *(_DWORD *)(v122 + 32) = 1065353216;
              *(_BYTE *)(v122 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 17;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Martial_Arts_School_Objective.mUID )
          {
            v123 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v123;
            if ( v123 )
            {
              *(_QWORD *)v123 = &UFG::UIMapBlipGraphic::`vftable';
              v123[8] = 0;
              *(_QWORD *)(v123 + 12) = 1065353216i64;
              *((_DWORD *)v123 + 5) = 5;
              v124 = (signed __int64)(v123 + 64);
              *(_DWORD *)(v124 + 52) = 1092616192;
              *(_QWORD *)(v124 + 8) = 0i64;
              *(_DWORD *)(v124 + 32) = 1065353216;
              *(_BYTE *)(v124 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::ObjectiveGreen;
            v204 = 17;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Parking_Lot.mUID )
          {
            v125 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v125;
            if ( v125 )
            {
              *(_QWORD *)v125 = &UFG::UIMapBlipGraphic::`vftable';
              v125[8] = 0;
              *(_QWORD *)(v125 + 12) = 1065353216i64;
              *((_DWORD *)v125 + 5) = 5;
              v126 = (signed __int64)(v125 + 64);
              *(_DWORD *)(v126 + 52) = 1092616192;
              *(_QWORD *)(v126 + 8) = 0i64;
              *(_DWORD *)(v126 + 32) = 1065353216;
              *(_BYTE *)(v126 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 13;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Fight_Club.mUID )
          {
            v127 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v127;
            if ( v127 )
            {
              *(_QWORD *)v127 = &UFG::UIMapBlipGraphic::`vftable';
              v127[8] = 0;
              *(_QWORD *)(v127 + 12) = 1065353216i64;
              *((_DWORD *)v127 + 5) = 5;
              v128 = (signed __int64)(v127 + 64);
              *(_DWORD *)(v128 + 52) = 1092616192;
              *(_QWORD *)(v128 + 8) = 0i64;
              *(_DWORD *)(v128 + 32) = 1065353216;
              *(_BYTE *)(v128 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::ObjectiveOrange;
            v204 = 20;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Cock_Fighting.mUID )
          {
            v129 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v129;
            if ( v129 )
            {
              *(_QWORD *)v129 = &UFG::UIMapBlipGraphic::`vftable';
              v129[8] = 0;
              *(_QWORD *)(v129 + 12) = 1065353216i64;
              *((_DWORD *)v129 + 5) = 5;
              v130 = (signed __int64)(v129 + 64);
              *(_DWORD *)(v130 + 52) = 1092616192;
              *(_QWORD *)(v130 + 8) = 0i64;
              *(_DWORD *)(v130 + 32) = 1065353216;
              *(_BYTE *)(v130 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::ObjectiveOrange;
            v204 = 21;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Drunken_Dice.mUID )
          {
            v131 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v131;
            if ( v131 )
            {
              *(_QWORD *)v131 = &UFG::UIMapBlipGraphic::`vftable';
              v131[8] = 0;
              *(_QWORD *)(v131 + 12) = 1065353216i64;
              *((_DWORD *)v131 + 5) = 5;
              v132 = (signed __int64)(v131 + 64);
              *(_DWORD *)(v132 + 52) = 1092616192;
              *(_QWORD *)(v132 + 8) = 0i64;
              *(_DWORD *)(v132 + 32) = 1065353216;
              *(_BYTE *)(v132 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::ObjectiveOrange;
            v204 = 15;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Vehicle_Store.mUID )
          {
            v133 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v133;
            if ( v133 )
            {
              *(_QWORD *)v133 = &UFG::UIMapBlipGraphic::`vftable';
              v133[8] = 0;
              *(_QWORD *)(v133 + 12) = 1065353216i64;
              *((_DWORD *)v133 + 5) = 5;
              v134 = (signed __int64)(v133 + 64);
              *(_DWORD *)(v134 + 52) = 1092616192;
              *(_QWORD *)(v134 + 8) = 0i64;
              *(_DWORD *)(v134 + 32) = 1065353216;
              *(_BYTE *)(v134 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 14;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Owned_Vehicle.mUID )
          {
            v135 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v135;
            if ( v135 )
            {
              *(_QWORD *)v135 = &UFG::UIMapBlipGraphic::`vftable';
              v135[8] = 0;
              *(_QWORD *)(v135 + 12) = 1065353216i64;
              *((_DWORD *)v135 + 5) = 5;
              v136 = (signed __int64)(v135 + 64);
              *(_DWORD *)(v136 + 52) = 1092616192;
              *(_QWORD *)(v136 + 8) = 0i64;
              *(_DWORD *)(v136 + 32) = 1065353216;
              *(_BYTE *)(v136 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::AmbientGreen;
            v204 = 14;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Safehouse_Store.mUID )
          {
            v137 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v137;
            if ( v137 )
            {
              *(_QWORD *)v137 = &UFG::UIMapBlipGraphic::`vftable';
              v137[8] = 0;
              *(_QWORD *)(v137 + 12) = 1065353216i64;
              *((_DWORD *)v137 + 5) = 5;
              v138 = (signed __int64)(v137 + 64);
              *(_DWORD *)(v138 + 52) = 1092616192;
              *(_QWORD *)(v138 + 8) = 0i64;
              *(_DWORD *)(v138 + 32) = 1065353216;
              *(_BYTE *)(v138 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 26;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Enemy.mUID )
          {
            v139 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            if ( v139 )
            {
              UFG::UIMapBlipGraphicEnemy::UIMapBlipGraphicEnemy((UFG::UIMapBlipGraphicEnemy *)v139);
              v6 = v140;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::ObjectiveRed;
            v204 = 1;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Friendly.mUID )
          {
            v141 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v141;
            if ( v141 )
            {
              *(_QWORD *)v141 = &UFG::UIMapBlipGraphic::`vftable';
              v141[8] = 0;
              *(_QWORD *)(v141 + 12) = 1065353216i64;
              *((_DWORD *)v141 + 5) = 5;
              v142 = (signed __int64)(v141 + 64);
              *(_DWORD *)(v142 + 52) = 1092616192;
              *(_QWORD *)(v142 + 8) = 0i64;
              *(_DWORD *)(v142 + 32) = 1065353216;
              *(_BYTE *)(v142 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::ObjectiveGreen;
            v204 = 1;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Social.mUID )
          {
            v143 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v143;
            if ( v143 )
            {
              *(_QWORD *)v143 = &UFG::UIMapBlipGraphic::`vftable';
              v143[8] = 0;
              *(_QWORD *)(v143 + 12) = 1065353216i64;
              *((_DWORD *)v143 + 5) = 5;
              v144 = (signed __int64)(v143 + 64);
              *(_DWORD *)(v144 + 52) = 1092616192;
              *(_QWORD *)(v144 + 8) = 0i64;
              *(_DWORD *)(v144 + 32) = 1065353216;
              *(_BYTE *)(v144 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::ObjectiveYellow;
            v204 = 30;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Contact.mUID )
          {
            v145 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v145;
            if ( v145 )
            {
              *(_QWORD *)v145 = &UFG::UIMapBlipGraphic::`vftable';
              v145[8] = 0;
              *(_QWORD *)(v145 + 12) = 1065353216i64;
              *((_DWORD *)v145 + 5) = 5;
              v146 = (signed __int64)(v145 + 64);
              *(_DWORD *)(v146 + 52) = 1092616192;
              *(_QWORD *)(v146 + 8) = 0i64;
              *(_DWORD *)(v146 + 32) = 1065353216;
              *(_BYTE *)(v146 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 1;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Face_Character.mUID )
          {
            v147 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v147;
            if ( v147 )
            {
              *(_QWORD *)v147 = &UFG::UIMapBlipGraphic::`vftable';
              v147[8] = 0;
              *(_QWORD *)(v147 + 12) = 1065353216i64;
              *((_DWORD *)v147 + 5) = 5;
              v148 = (signed __int64)(v147 + 64);
              *(_DWORD *)(v148 + 52) = 1092616192;
              *(_QWORD *)(v148 + 8) = 0i64;
              *(_DWORD *)(v148 + 32) = 1065353216;
              *(_BYTE *)(v148 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::ObjectiveYellow;
            v204 = 30;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Story_Character.mUID )
          {
            v149 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v149;
            if ( v149 )
            {
              *(_QWORD *)v149 = &UFG::UIMapBlipGraphic::`vftable';
              v149[8] = 0;
              *(_QWORD *)(v149 + 12) = 1065353216i64;
              *((_DWORD *)v149 + 5) = 5;
              v150 = (signed __int64)(v149 + 64);
              *(_DWORD *)(v150 + 52) = 1092616192;
              *(_QWORD *)(v150 + 8) = 0i64;
              *(_DWORD *)(v150 + 32) = 1065353216;
              *(_BYTE *)(v150 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::ObjectiveGreen;
            v204 = 1;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Date_Character.mUID )
          {
            v151 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v151;
            if ( v151 )
            {
              *(_QWORD *)v151 = &UFG::UIMapBlipGraphic::`vftable';
              v151[8] = 0;
              *(_QWORD *)(v151 + 12) = 1065353216i64;
              *((_DWORD *)v151 + 5) = 5;
              v152 = (signed __int64)(v151 + 64);
              *(_DWORD *)(v152 + 52) = 1092616192;
              *(_QWORD *)(v152 + 8) = 0i64;
              *(_DWORD *)(v152 + 32) = 1065353216;
              *(_BYTE *)(v152 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::CharacterPink;
            v204 = 1;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Security_Camera.mUID )
          {
            v153 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v153;
            if ( v153 )
            {
              *(_QWORD *)v153 = &UFG::UIMapBlipGraphic::`vftable';
              v153[8] = 0;
              *(_QWORD *)(v153 + 12) = 1065353216i64;
              *((_DWORD *)v153 + 5) = 5;
              v154 = (signed __int64)(v153 + 64);
              *(_DWORD *)(v154 + 52) = 1092616192;
              *(_QWORD *)(v154 + 8) = 0i64;
              *(_DWORD *)(v154 + 32) = 1065353216;
              *(_BYTE *)(v154 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::qColour::Grey;
            v204 = 5;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Security_Camera_Collected.mUID )
          {
            v155 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v155;
            if ( v155 )
            {
              *(_QWORD *)v155 = &UFG::UIMapBlipGraphic::`vftable';
              v155[8] = 0;
              *(_QWORD *)(v155 + 12) = 1065353216i64;
              *((_DWORD *)v155 + 5) = 5;
              v156 = (signed __int64)(v155 + 64);
              *(_DWORD *)(v156 + 52) = 1092616192;
              *(_QWORD *)(v156 + 8) = 0i64;
              *(_DWORD *)(v156 + 32) = 1065353216;
              *(_BYTE *)(v156 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 5;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Shrine.mUID )
          {
            v157 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v157;
            if ( v157 )
            {
              *(_QWORD *)v157 = &UFG::UIMapBlipGraphic::`vftable';
              v157[8] = 0;
              *(_QWORD *)(v157 + 12) = 1065353216i64;
              *((_DWORD *)v157 + 5) = 5;
              v158 = (signed __int64)(v157 + 64);
              *(_DWORD *)(v158 + 52) = 1092616192;
              *(_QWORD *)(v158 + 8) = 0i64;
              *(_DWORD *)(v158 + 32) = 1065353216;
              *(_BYTE *)(v158 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::qColour::Grey;
            v204 = 6;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Shrine_Collected.mUID )
          {
            v159 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v159;
            if ( v159 )
            {
              *(_QWORD *)v159 = &UFG::UIMapBlipGraphic::`vftable';
              v159[8] = 0;
              *(_QWORD *)(v159 + 12) = 1065353216i64;
              *((_DWORD *)v159 + 5) = 5;
              v160 = (signed __int64)(v159 + 64);
              *(_DWORD *)(v160 + 52) = 1092616192;
              *(_QWORD *)(v160 + 8) = 0i64;
              *(_DWORD *)(v160 + 32) = 1065353216;
              *(_BYTE *)(v160 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 6;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Lockbox.mUID )
          {
            v161 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v161;
            if ( v161 )
            {
              *(_QWORD *)v161 = &UFG::UIMapBlipGraphic::`vftable';
              v161[8] = 0;
              *(_QWORD *)(v161 + 12) = 1065353216i64;
              *((_DWORD *)v161 + 5) = 5;
              v162 = (signed __int64)(v161 + 64);
              *(_DWORD *)(v162 + 52) = 1092616192;
              *(_QWORD *)(v162 + 8) = 0i64;
              *(_DWORD *)(v162 + 32) = 1065353216;
              *(_BYTE *)(v162 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::qColour::Grey;
            v204 = 7;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Lockbox_Collected.mUID )
          {
            v163 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v163;
            if ( v163 )
            {
              *(_QWORD *)v163 = &UFG::UIMapBlipGraphic::`vftable';
              v163[8] = 0;
              *(_QWORD *)(v163 + 12) = 1065353216i64;
              *((_DWORD *)v163 + 5) = 5;
              v164 = (signed __int64)(v163 + 64);
              *(_DWORD *)(v164 + 52) = 1092616192;
              *(_QWORD *)(v164 + 8) = 0i64;
              *(_DWORD *)(v164 + 32) = 1065353216;
              *(_BYTE *)(v164 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 7;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Melee_Upgrade.mUID )
          {
            v165 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v165;
            if ( v165 )
            {
              *(_QWORD *)v165 = &UFG::UIMapBlipGraphic::`vftable';
              v165[8] = 0;
              *(_QWORD *)(v165 + 12) = 1065353216i64;
              *((_DWORD *)v165 + 5) = 5;
              v166 = (signed __int64)(v165 + 64);
              *(_DWORD *)(v166 + 52) = 1092616192;
              *(_QWORD *)(v166 + 8) = 0i64;
              *(_DWORD *)(v166 + 32) = 1065353216;
              *(_BYTE *)(v166 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v24 = UFG::qColour::Grey;
            v204 = 25;
            goto LABEL_489;
          }
          if ( v3 == UIBlipIcon_Melee_Upgrade_Collected.mUID )
          {
            v167 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v167;
            if ( v167 )
            {
              *(_QWORD *)v167 = &UFG::UIMapBlipGraphic::`vftable';
              v167[8] = 0;
              *(_QWORD *)(v167 + 12) = 1065353216i64;
              *((_DWORD *)v167 + 5) = 5;
              v168 = (signed __int64)(v167 + 64);
              *(_DWORD *)(v168 + 52) = 1092616192;
              *(_QWORD *)(v168 + 8) = 0i64;
              *(_DWORD *)(v168 + 32) = 1065353216;
              *(_BYTE *)(v168 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
            v204 = 25;
            goto LABEL_488;
          }
          if ( v3 == UIBlipIcon_Tourist_Photo.mUID )
          {
            v169 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
            v6 = (UFG::UIMapBlipGraphic *)v169;
            if ( v169 )
            {
              *(_QWORD *)v169 = &UFG::UIMapBlipGraphic::`vftable';
              v169[8] = 0;
              *(_QWORD *)(v169 + 12) = 1065353216i64;
              *((_DWORD *)v169 + 5) = 5;
              v170 = (signed __int64)(v169 + 64);
              *(_DWORD *)(v170 + 52) = 1092616192;
              *(_QWORD *)(v170 + 8) = 0i64;
              *(_DWORD *)(v170 + 32) = 1065353216;
              *(_BYTE *)(v170 + 72) = 0;
              v6->mPolys[0] = &v6->mIconPoly;
              v6->mPolys[1] = 0i64;
              v6->mPolys[2] = 0i64;
              v6->mPolys[3] = 0i64;
              v6->mPolys[4] = 0i64;
            }
            else
            {
              v6 = 0i64;
            }
          }
          else
          {
            if ( v3 == UIBlipIcon_Jump.mUID )
            {
              v171 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
              v6 = (UFG::UIMapBlipGraphic *)v171;
              if ( v171 )
              {
                *(_QWORD *)v171 = &UFG::UIMapBlipGraphic::`vftable';
                v171[8] = 0;
                *(_QWORD *)(v171 + 12) = 1065353216i64;
                *((_DWORD *)v171 + 5) = 5;
                v172 = (signed __int64)(v171 + 64);
                *(_DWORD *)(v172 + 52) = 1092616192;
                *(_QWORD *)(v172 + 8) = 0i64;
                *(_DWORD *)(v172 + 32) = 1065353216;
                *(_BYTE *)(v172 + 72) = 0;
                v6->mPolys[0] = &v6->mIconPoly;
                v6->mPolys[1] = 0i64;
                v6->mPolys[2] = 0i64;
                v6->mPolys[3] = 0i64;
                v6->mPolys[4] = 0i64;
              }
              else
              {
                v6 = 0i64;
              }
              v24 = UFG::qColour::Grey;
              v204 = 24;
              goto LABEL_489;
            }
            if ( v3 == UIBlipIcon_Jump_Collected.mUID )
            {
              v173 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
              if ( v173 )
              {
                UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v173);
                v6 = v174;
              }
              else
              {
                v6 = 0i64;
              }
              v204 = 24;
              goto LABEL_488;
            }
            if ( v3 == UIBlipIcon_Tape_Recorder.mUID )
            {
              v175 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
              if ( v175 )
              {
                UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v175);
                v6 = v176;
              }
              else
              {
                v6 = 0i64;
              }
            }
            else if ( v3 == UIBlipIcon_Bug.mUID )
            {
              v177 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
              if ( v177 )
              {
                UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v177);
                v6 = v178;
              }
              else
              {
                v6 = 0i64;
              }
            }
            else
            {
              if ( v3 == UIBlipIcon_Ghost_Orb.mUID )
              {
                v179 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                if ( v179 )
                {
                  UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v179);
                  v6 = v180;
                }
                else
                {
                  v6 = 0i64;
                }
                v24 = UFG::qColour::Grey;
                v204 = 31;
                goto LABEL_489;
              }
              if ( v3 == UIBlipIcon_Ghost_Orb_Collected.mUID )
              {
                v181 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                if ( v181 )
                {
                  UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v181);
                  v6 = v182;
                }
                else
                {
                  v6 = 0i64;
                }
              }
              else
              {
                if ( v3 == UIBlipIcon_Fire_Statue.mUID )
                {
                  v183 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                  if ( v183 )
                  {
                    UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v183);
                    v6 = v184;
                  }
                  else
                  {
                    v6 = 0i64;
                  }
                  v24 = UFG::qColour::Grey;
                  v204 = 31;
                  goto LABEL_489;
                }
                if ( v3 == UIBlipIcon_Fire_Statue_Collected.mUID )
                {
                  v185 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                  if ( v185 )
                  {
                    UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v185);
                    v6 = v186;
                  }
                  else
                  {
                    v6 = 0i64;
                  }
                }
                else
                {
                  if ( v3 == UIBlipIcon_Evidence_Bag.mUID )
                  {
                    v187 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                    if ( v187 )
                    {
                      UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v187);
                      v6 = v188;
                    }
                    else
                    {
                      v6 = 0i64;
                    }
                    v24 = UFG::qColour::Grey;
                    v204 = 31;
                    goto LABEL_489;
                  }
                  if ( v3 == UIBlipIcon_Evidence_Bag_Collected.mUID )
                  {
                    v189 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                    if ( v189 )
                    {
                      UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v189);
                      v6 = v190;
                    }
                    else
                    {
                      v6 = 0i64;
                    }
                  }
                  else
                  {
                    if ( v3 == UIBlipIcon_Generic_Blip.mUID )
                    {
                      v191 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                      if ( v191 )
                      {
                        UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v191);
                        v6 = v192;
                      }
                      else
                      {
                        v6 = 0i64;
                      }
                      v204 = 3;
                      goto LABEL_488;
                    }
                    if ( v3 == UIBlipIcon_Up_Arrow.mUID )
                    {
                      v193 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                      if ( v193 )
                      {
                        UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v193);
                        v6 = v194;
                      }
                      else
                      {
                        v6 = 0i64;
                      }
                      v204 = 23;
                      goto LABEL_488;
                    }
                    if ( v3 == UIBlipIcon_Generic_Interactive_Object.mUID )
                    {
                      v195 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                      if ( v195 )
                      {
                        UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v195);
                        v6 = v196;
                      }
                      else
                      {
                        v6 = 0i64;
                      }
                      v204 = 3;
                      goto LABEL_488;
                    }
                    if ( v3 == UIBlipIcon_invisible_icon.mUID )
                    {
                      v197 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                      if ( !v197 )
                        return 0i64;
                      UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v197);
                      return (UFG::UIMapBlipGraphic *)v198;
                    }
                    if ( v3 == UIBlipIcon_Hijack.mUID )
                    {
                      v199 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                      if ( v199 )
                      {
                        UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v199);
                        v6 = v200;
                      }
                      else
                      {
                        v6 = 0i64;
                      }
                    }
                    else
                    {
                      v201 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                      if ( v201 )
                      {
                        UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v201);
                        v6 = v202;
                      }
                      else
                      {
                        v6 = 0i64;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        v204 = 31;
      }
    }
LABEL_488:
    v24 = UFG::qColour::White;
LABEL_489:
    v205 = v24;
    UFG::UIMapBlipGraphic::SetPolyInfo(v6, 0, (float)v2, &v205, v204);
    return v6;
  }
  v15 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
  v6 = (UFG::UIMapBlipGraphic *)v15;
  if ( v15 )
  {
    *(_QWORD *)v15 = &UFG::UIMapBlipGraphic::`vftable';
    v15[8] = 0;
    *(_QWORD *)(v15 + 12) = 1065353216i64;
    *((_DWORD *)v15 + 5) = 5;
    v16 = (signed __int64)(v15 + 64);
    *(_DWORD *)(v16 + 52) = 1092616192;
    *(_QWORD *)(v16 + 8) = 0i64;
    *(_DWORD *)(v16 + 32) = 1065353216;
    *(_BYTE *)(v16 + 72) = 0;
    v6->mPolys[0] = &v6->mIconPoly;
    v6->mPolys[1] = 0i64;
    v6->mPolys[2] = 0i64;
    v6->mPolys[3] = 0i64;
    v6->mPolys[4] = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  v17 = UFG::qColour::White;
  if ( !v6->mPolys[0] )
  {
    v212 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v212 + 13) = 1092616192;
    *((_QWORD *)v212 + 1) = 0i64;
    *((_DWORD *)v212 + 8) = 1065353216;
    v212[72] = 0;
    v6->mPolys[0] = (UFG::UIRenderQuad *)v212;
  }
  v18 = v6->mPolys[0];
  v18->Color = v17;
  v18->Size = (float)v2;
  *(_QWORD *)&v18->X = 0i64;
  *(_QWORD *)&v18->OffsetX = 0i64;
  v18->Visible = 1;
  if ( !v6->mPolys[0] )
  {
    v213 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v213 + 13) = 1092616192;
    *((_QWORD *)v213 + 1) = 0i64;
    *((_DWORD *)v213 + 8) = 1065353216;
    v213[72] = 0;
    v6->mPolys[0] = (UFG::UIRenderQuad *)v213;
  }
  v6->mPolys[0]->Color.a = 1.0;
  if ( !v6->mPolys[0] )
  {
    v214 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v214 + 13) = 1092616192;
    *((_QWORD *)v214 + 1) = 0i64;
    *((_DWORD *)v214 + 8) = 1065353216;
    v214[72] = 0;
    v6->mPolys[0] = (UFG::UIRenderQuad *)v214;
  }
  v19 = v6->mPolys[0];
  v19->TextureID = uid_Icon_Minimap_TextureSheet;
  v19->UVs[0] = 0.5;
  v19->UVs[1] = 0.125;
  v19->UVs[2] = 0.125;
  v19->UVs[3] = 0.125;
  return v6;
}
                    else
                    {
                      v201 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
                      if ( v201 )
                      {
                        UFG::UIMapBlipGraphic::UIMapBlipGraphic((UFG::UIMapBlipGraphic *)v201);
                        v6 = v202;
                      }
                      else
                      {
                        v6 = 0i64;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        v204 = 31;
      }
    }
LABEL_488:
    v24 = UFG::qColour::White;
LABEL_489:
    v205 = v24;
    UFG::UIMapBlipGraphic::SetPolyInfo(v6, 0, (float)v2, &v205, v204);
    return v6;
  }
  v15 = UFG::qMalloc(0x90ui64, "UIMapBlipGraphicFactory", 0i64);
  v6 = (UFG::UIMapBlipGraphic *)v15;
  if ( v15 )
  {
    *(_QWORD *)v15 = &UFG::UIMapBlipGraphic::`vftable';
    v15[8] = 0;
    *(_QWORD *)(v15 + 12) = 1065353216i64;
    *((_DWORD *)v15 + 5) = 5;
    v16 = (signed __int64)(v15 + 64);
    *(_DWORD *)(v16 + 52) = 1092616192;
    *(_QWORD *)(v16 + 8) = 0i64;
    *(_DWORD *)(v16 + 32) = 1065353216;
    *(_BYTE *)(v16 + 72) = 0;
    v6->mPolys[0] = &v6->mIconPoly;
    v6->mPolys[1] = 0i64;
    v6->mPolys[2] = 0i64;
    v6->mPolys[3] = 0i64;
    v6->mPolys[4] = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  v17 = UFG::qColour::White;
  if ( !v6->mPolys[0] )
  {
    v212 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v212 + 13) = 1092616192;
    *((_QWORD *)v212 + 1) = 0i64;
    *((_DWORD *)v212 + 8) = 1065353216;
    v212[72] = 0;
    v6->mPolys[0] = (UFG::UIRenderQuad *)v212;
  }
  v18 = v6->mPolys[0];
  v18->Color = v17;
  v18->Size = (float)v2;
  *(_QWORD *)&v18->X = 0i64;
  *(_QWORD *)&v18->OffsetX = 0i64;
  v18->Visible = 1;
  if ( !v6->mPolys[0] )
  {
    v213 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v213 + 13) = 1092616192;
   

// File Line: 984
// RVA: 0xBBC00
void __fastcall UFG::UIMapBlipGraphicPlayerArrow::UIMapBlipGraphicPlayerArrow(UFG::UIMapBlipGraphicPlayerArrow *this)
{
  UFG::UIMapBlipGraphicPlayerArrow *v1; // rbx
  UFG::UIRenderQuad *v2; // rax
  UFG::qVector4 *v3; // rdi
  UFG::qVector4 v4; // xmm1
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm3
  char *v7; // [rsp+48h] [rbp+10h]
  char *v8; // [rsp+48h] [rbp+10h]
  char *v9; // [rsp+48h] [rbp+10h]
  char *v10; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphic::`vftable';
  this->mAnimateBlink = 0;
  *(_QWORD *)&this->mBlinkScale = 1065353216i64;
  this->mBlinkTimesMax = 5;
  v2 = &this->mIconPoly;
  v2->Size = 10.0;
  v2->Matrix = 0i64;
  v2->Scale = 1.0;
  v2->Visible = 0;
  this->mPolys[0] = &this->mIconPoly;
  this->mPolys[1] = 0i64;
  this->mPolys[2] = 0i64;
  this->mPolys[3] = 0i64;
  this->mPolys[4] = 0i64;
  this->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphicPlayerArrow::`vftable';
  if ( !this->mPolys[0] )
  {
    v7 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v7 + 13) = 1092616192;
    *((_QWORD *)v7 + 1) = 0i64;
    *((_DWORD *)v7 + 8) = 1065353216;
    v7[72] = 0;
    v1->mPolys[0] = (UFG::UIRenderQuad *)v7;
  }
  v3 = &v1->mRotationMatrix.v0;
  v1->mPolys[0]->Matrix = &v1->mRotationMatrix;
  if ( !v1->mPolys[1] )
  {
    v8 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v8 + 13) = 1092616192;
    *((_QWORD *)v8 + 1) = 0i64;
    *((_DWORD *)v8 + 8) = 1065353216;
    v8[72] = 0;
    v1->mPolys[1] = (UFG::UIRenderQuad *)v8;
  }
  v1->mPolys[1]->Matrix = (UFG::qMatrix44 *)v3;
  if ( !v1->mPolys[2] )
  {
    v9 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v9 + 13) = 1092616192;
    *((_QWORD *)v9 + 1) = 0i64;
    *((_DWORD *)v9 + 8) = 1065353216;
    v9[72] = 0;
    v1->mPolys[2] = (UFG::UIRenderQuad *)v9;
  }
  v1->mPolys[2]->Matrix = (UFG::qMatrix44 *)v3;
  if ( !v1->mPolys[3] )
  {
    v10 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
    *((_DWORD *)v10 + 13) = 1092616192;
    *((_QWORD *)v10 + 1) = 0i64;
    *((_DWORD *)v10 + 8) = 1065353216;
    v10[72] = 0;
    v1->mPolys[3] = (UFG::UIRenderQuad *)v10;
  }
  v1->mPolys[3]->Matrix = (UFG::qMatrix44 *)v3;
  v4 = UFG::qMatrix44::msIdentity.v1;
  v5 = UFG::qMatrix44::msIdentity.v2;
  v6 = UFG::qMatrix44::msIdentity.v3;
  *v3 = UFG::qMatrix44::msIdentity.v0;
  v1->mRotationMatrix.v1 = v4;
  v1->mRotationMatrix.v2 = v5;
  v1->mRotationMatrix.v3 = v6;
}

// File Line: 994
// RVA: 0xCE4A0
void __fastcall UFG::UIMapBlipGraphicPlayerArrow::UpdateTransform(UFG::UIMapBlipGraphicPlayerArrow *this, float rot, int x, int y)
{
  UFG::UIMapBlipGraphicPlayerArrow *v4; // rsi
  int v5; // edi
  int v6; // ebx

  v4 = this;
  v5 = y;
  v6 = x;
  UFG::qRotationMatrixZ(&this->mRotationMatrix, (float)(rot * 3.1415927) * 0.0055555557);
  v4->mRotationMatrix.v3.z = 0.0;
  v4->mRotationMatrix.v3.w = 1.0;
  v4->mRotationMatrix.v3.x = (float)v6;
  v4->mRotationMatrix.v3.y = (float)v5;
}

