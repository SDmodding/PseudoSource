// File Line: 48
// RVA: 0x1452B50
__int64 Render::_dynamic_initializer_for__gFontInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Render::gFontInventory.vfptr,
    "FontInventory",
    0x69FCCB4Cu,
    0x2A1BE612u,
    0,
    0);
  Render::gFontInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FontInventory::`vftable';
  return atexit(Render::_dynamic_atexit_destructor_for__gFontInventory__);
}

// File Line: 57
// RVA: 0xA5C0
void __fastcall Render::FontInventory::Add(Render::FontInventory *this, UFG::qResourceData *resource_data)
{
  Render::FontInventory *v2; // rdi
  UFG::qResourceData *v3; // rbx

  v2 = this;
  v3 = resource_data;
  Render::Font::OnLoad((Render::Font *)resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v2->vfptr, v3);
}

// File Line: 86
// RVA: 0xA8D0
void __fastcall Render::Font::OnLoad(Render::Font *this)
{
  Render::Font *v1; // rsi
  unsigned int v2; // eax
  int v3; // edi
  Illusion::Material *v4; // rbx
  int v5; // edi
  Illusion::Material *v6; // rbx
  Illusion::Material *v7; // rbx
  Illusion::Material *v8; // rbx
  UFG::qResourceWarehouse *v9; // rax

  v1 = this;
  if ( this )
    UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  else
    v1 = 0i64;
  v2 = UFG::qStringHash32("Font.Primitive", v1->mNode.mUID);
  v1->mMaterial = Illusion::Factory::NewMaterial("Font.Primitive", v2, 4u, 0i64, 0i64, 0i64);
  v3 = UFG::qStringHash32("SIMPLE", 0xFFFFFFFF);
  v4 = v1->mMaterial;
  LOWORD(v4[1].mNode.mChild[0]) = 0;
  HIDWORD(v4[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v4[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v4[1].mTypeUID = -1957338719;
  LODWORD(v4[1].mResourceHandles.mNode.mNext) = v3;
  v5 = UFG::qStringHash32(v1->mTextureName, 0xFFFFFFFF);
  v6 = v1->mMaterial;
  *(_WORD *)&v6[1].mDebugName[12] = 0;
  *(_DWORD *)&v6[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v6[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v6[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v6[1].mStateBlockMask.mFlags[0]) = v5;
  v7 = v1->mMaterial;
  LOWORD(v7[1].mMaterialUser.mOffset) = 0;
  *(&v7[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v7[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v7[2].mResourceHandles.mNode.mPrev) = 315097330;
  v7[2].mNode.mUID = -1551679522;
  v8 = v1->mMaterial;
  LOWORD(v8[2].mTypeUID) = 0;
  HIDWORD(v8[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v8[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v8[2].0 + 22) = 1002903008;
  *(_DWORD *)&v8[2].mDebugName[28] = 1660426324;
  v9 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v9, (UFG::qResourceData *)&v1->mMaterial->mNode);
}

// File Line: 113
// RVA: 0xADE0
void __fastcall Render::Font::PrintChar(Render::Font *this, Render::vDynamic **vertex_buffer, float *x, float *y, const unsigned int colour, const char ascii_char, int left_margin, const float reciprocal_view_width, const float reciprocal_view_height)
{
  float *v9; // rsi
  Render::vDynamic **v10; // r14
  signed __int16 v11; // r10
  __int64 v12; // rax
  char *v13; // rdx
  signed __int64 v14; // rbp
  unsigned __int16 v15; // cx
  unsigned __int16 v16; // r10
  unsigned __int16 v17; // ax
  float v18; // xmm0_4
  unsigned __int16 v19; // r9
  float v20; // xmm3_4
  float v21; // xmm1_4
  Render::vDynamic *v22; // rdi
  float v23; // xmm0_4
  float v24; // xmm2_4
  signed __int64 v25; // rdx
  __int64 v26; // rax
  char *v27; // r11

  v9 = x;
  v10 = vertex_buffer;
  v11 = this->mAsciiToGlyph[ascii_char];
  if ( ascii_char != -73 )
  {
    switch ( ascii_char )
    {
      case 9:
        *x = (float)((float)((float)((float)(*x - (float)left_margin) * 0.0099999998) + 1.0) * 100.0)
           + (float)left_margin;
        break;
      case 10:
      case 13:
        *y = (float)this->mLineHeight + *y;
        *x = (float)left_margin;
        break;
      case 32:
        v26 = this->mGlyphTable.mOffset;
        if ( v26 )
          v27 = (char *)&this->mGlyphTable + v26;
        else
          v27 = 0i64;
        *x = (float)*(unsigned __int16 *)&v27[48 * v11 + 42] + *x;
        break;
      default:
        if ( v11 >= 0 )
        {
          v12 = this->mGlyphTable.mOffset;
          if ( v12 )
            v13 = (char *)&this->mGlyphTable + v12;
          else
            v13 = 0i64;
          v14 = (signed __int64)&v13[48 * v11];
          if ( v10 )
          {
            v15 = *(_WORD *)(v14 + 20);
            v16 = *(_WORD *)(v14 + 16);
            v17 = *(_WORD *)(v14 + 18);
            v18 = *(float *)(v14 + 28) + *y;
            v19 = *(_WORD *)(v14 + 22);
            v20 = (float)(*(float *)(v14 + 24) + *x) * reciprocal_view_width;
            v21 = (float)(reciprocal_view_width * *(float *)(v14 + 32)) + v20;
            v22 = *v10;
            v23 = v18 * reciprocal_view_height;
            v24 = (float)(reciprocal_view_height * *(float *)(v14 + 36)) + v23;
            v22->mPosition.x = v20;
            v22->mPosition.y = v23;
            v22->mPosition.z = 0.0;
            v25 = (signed __int64)&v22[1];
            v22->mTexCoord0[0] = v16;
            v22->mTexCoord0[1] = v17;
            v22->mColour = colour;
            v22[2].mPosition.x = v21;
            v22[2].mPosition.y = v23;
            v22[2].mPosition.z = 0.0;
            v22[2].mTexCoord0[0] = v15;
            v22[2].mTexCoord0[1] = v17;
            v22[2].mColour = colour;
            v22[4].mPosition.z = 0.0;
            v22[4].mPosition.x = v21;
            v22[4].mPosition.y = v24;
            v22[4].mTexCoord0[0] = v15;
            v22[4].mTexCoord0[1] = v19;
            v22[4].mColour = colour;
            *(_DWORD *)(v25 + 8) = 0;
            *(float *)v25 = v20;
            *(float *)(v25 + 4) = v24;
            v22[1].mTexCoord0[0] = v16;
            v22[1].mTexCoord0[1] = v19;
            v22[1].mColour = colour;
            Render::vDynamic::operator=(v22 + 3, v22 + 1);
            Render::vDynamic::operator=(v22 + 5, v22 + 2);
            *v10 += 6;
          }
          *v9 = (float)*(unsigned __int16 *)(v14 + 42) + *v9;
        }
        break;
    }
  }
}

// File Line: 212
// RVA: 0xAAA0
void Render::Font::Print(Render::Font *this, Render::View *view, int int_x, int int_y, UFG::qColour *colour, const char *format, ...)
{
  signed int left_margin; // er14
  int v7; // esi
  Render::Font *v8; // rbx
  int v9; // eax
  char *v10; // rax
  Render::vDynamic *v11; // r15
  Render::vDynamic *v12; // rdi
  signed __int16 v13; // r12
  __int16 v14; // r13
  int v15; // ebp
  float reciprocal_view_width; // xmm7_4
  char *v17; // rsi
  __m128i v18; // xmm0
  char v19; // al
  float reciprocal_view_height; // xmm6_4
  char ascii_char; // di
  signed __int16 v22; // cx
  __int64 v23; // rax
  signed __int64 v24; // rdx
  __int16 v25; // ax
  __int64 v26; // rcx
  char v27; // r9
  signed __int64 v28; // rdx
  signed __int64 v29; // rcx
  int v30; // eax
  signed __int64 v31; // rdx
  int v32; // eax
  unsigned __int64 v33; // rdx
  unsigned __int64 v34; // rdx
  Illusion::Material *v35; // ST20_8
  float x; // [rsp+50h] [rbp-2088h]
  float y; // [rsp+54h] [rbp-2084h]
  Render::vDynamic *vertex_buffer; // [rsp+58h] [rbp-2080h]
  char *v39; // [rsp+60h] [rbp-2078h]
  char dest; // [rsp+70h] [rbp-2068h]
  Render::View *v41; // [rsp+20E8h] [rbp+10h]
  va_list va; // [rsp+2110h] [rbp+38h]

  va_start(va, format);
  v41 = view;
  left_margin = int_x;
  v7 = int_y;
  v8 = this;
  v9 = UFG::qVSPrintf(&dest, 0x2000, format, va);
  if ( v9 )
  {
    v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 288 * v9, 0x10u);
    v11 = (Render::vDynamic *)v10;
    v39 = v10;
    if ( v10 )
    {
      vertex_buffer = (Render::vDynamic *)v10;
      v12 = (Render::vDynamic *)v10;
      v13 = v8->mNumGlyphs;
      v14 = v8->mNumKernings;
      v15 = (signed int)(float)(colour->r * 255.0) | (((signed int)(float)(colour->g * 255.0) | (((signed int)(float)(colour->b * 255.0) | ((signed int)(float)(colour->a * 255.0) << 8)) << 8)) << 8);
      x = (float)left_margin;
      y = (float)v7;
      reciprocal_view_width = 1.0 / (float)Render::View::GetTargetWidth(v41);
      v17 = &dest;
      v18 = _mm_cvtsi32_si128(Render::View::GetTargetHeight(v41));
      v19 = dest;
      reciprocal_view_height = 1.0 / COERCE_FLOAT(_mm_cvtepi32_ps(v18));
      if ( dest )
      {
        do
        {
          ascii_char = v19;
          if ( v19 == -73 )
            ascii_char = 32;
          Render::Font::PrintChar(
            v8,
            &vertex_buffer,
            &x,
            &y,
            v15,
            ascii_char,
            left_margin,
            reciprocal_view_width,
            reciprocal_view_height);
          v22 = v8->mAsciiToGlyph[ascii_char];
          if ( v22 >= 0 && v22 < v13 )
          {
            v23 = v8->mGlyphTable.mOffset;
            v24 = (signed __int64)(v23 ? (UFG::qOffset64<Render::Font::Glyph *> *)((char *)&v8->mGlyphTable + v23) : 0i64);
            v25 = *(_WORD *)(v24 + 48i64 * v22 + 46);
            if ( v25 >= 0 && v25 < v14 )
            {
              v26 = v8->mKerningTable.mOffset;
              v27 = v17[1];
              if ( v26 )
                v28 = (signed __int64)&v8->mKerningTable + v26;
              else
                v28 = 0i64;
              v29 = 3i64 * v25;
              v30 = *(unsigned __int16 *)(v28 + 6i64 * v25);
              v31 = v28 + 2 * v29;
              if ( v30 == ascii_char )
              {
                do
                {
                  if ( *(unsigned __int16 *)(v31 + 2) >= (signed int)v27 )
                    break;
                  v32 = *(unsigned __int16 *)(v31 + 6);
                  v31 += 6i64;
                }
                while ( v32 == ascii_char );
              }
              if ( *(unsigned __int16 *)(v31 + 2) == v27 )
                x = x + (float)*(signed __int16 *)(v31 + 4);
            }
          }
          v19 = (v17++)[1];
        }
        while ( v19 );
        v12 = vertex_buffer;
        v11 = (Render::vDynamic *)v39;
      }
      v33 = (signed __int64)((unsigned __int128)(((char *)v12 - (char *)v11) * (signed __int128)3074457345618258603i64) >> 64) >> 3;
      v34 = (v33 >> 63) + v33;
      if ( (_DWORD)v34 )
      {
        v35 = v8->mMaterial;
        Render::View::DrawDebugPrim(v41, DebugPrim_Triangle, v11, v34);
      }
    }
  }
}

// File Line: 292
// RVA: 0xA650
void Render::Font::Measure(Render::Font *this, int *w, int *h, const char *format, ...)
{
  Render::Font *v4; // rbx
  int *v5; // r14
  int *v6; // r15
  float v7; // xmm6_4
  float v8; // xmm7_4
  char v9; // r8
  float v10; // xmm1_4
  float v11; // xmm2_4
  char *v12; // r11
  signed __int16 v13; // cx
  __int64 v14; // rax
  signed __int64 v15; // rdx
  signed __int16 v16; // cx
  __int64 v17; // rax
  signed __int64 v18; // rdx
  __int16 v19; // r9
  __int64 v20; // rax
  char v21; // r10
  signed __int64 v22; // rdx
  int v23; // eax
  signed __int64 v24; // rdx
  int v25; // eax
  float v26; // [rsp+20h] [rbp-2058h]
  float v27; // [rsp+24h] [rbp-2054h]
  char dest; // [rsp+30h] [rbp-2048h]
  va_list va; // [rsp+20A0h] [rbp+28h]

  va_start(va, format);
  v4 = this;
  v5 = h;
  v6 = w;
  v7 = 0.0;
  v27 = 0.0;
  v8 = (float)this->mLineHeight;
  v26 = (float)this->mLineHeight;
  if ( (unsigned int)UFG::qVSPrintf(&dest, 0x2000, format, va) )
  {
    v9 = dest;
    v10 = 0.0;
    v11 = 0.0;
    v12 = &dest;
    if ( dest )
    {
      do
      {
        v13 = v4->mAsciiToGlyph[v9];
        if ( v9 != -73 )
        {
          if ( v9 == 9 )
          {
            v10 = (float)((float)(v10 * 0.0099999998) + 1.0) * 100.0;
          }
          else if ( v9 == 10 || v9 == 13 )
          {
            v10 = 0.0;
            v11 = v11 + (float)v4->mLineHeight;
          }
          else if ( v9 == 32 || v13 >= 0 )
          {
            v14 = v4->mGlyphTable.mOffset;
            if ( v14 )
              v15 = (signed __int64)&v4->mGlyphTable + v14;
            else
              v15 = 0i64;
            v10 = v10 + (float)*(unsigned __int16 *)(48i64 * v13 + v15 + 42);
          }
        }
        v16 = v4->mAsciiToGlyph[v9];
        if ( v16 >= 0 && v16 < SLOWORD(v4->mNumGlyphs) )
        {
          v17 = v4->mGlyphTable.mOffset;
          v18 = (signed __int64)(v17 ? (UFG::qOffset64<Render::Font::Glyph *> *)((char *)&v4->mGlyphTable + v17) : 0i64);
          v19 = *(_WORD *)(v18 + 48i64 * v16 + 46);
          if ( v19 >= 0 && v19 < SLOWORD(v4->mNumKernings) )
          {
            v20 = v4->mKerningTable.mOffset;
            v21 = v12[1];
            if ( v20 )
              v22 = (signed __int64)&v4->mKerningTable + v20;
            else
              v22 = 0i64;
            v23 = *(unsigned __int16 *)(v22 + 6i64 * v19);
            v24 = v22 + 6i64 * v19;
            if ( v23 == v9 )
            {
              do
              {
                if ( *(unsigned __int16 *)(v24 + 2) >= (signed int)v21 )
                  break;
                v25 = *(unsigned __int16 *)(v24 + 6);
                v24 += 6i64;
              }
              while ( v25 == v9 );
            }
            if ( *(unsigned __int16 *)(v24 + 2) == v21 )
              v10 = v10 + (float)*(signed __int16 *)(v24 + 4);
          }
        }
        if ( v7 <= v10 )
          v7 = v10;
        if ( v8 <= v11 )
          v8 = v11;
        v9 = (v12++)[1];
      }
      while ( v9 );
      v27 = v7;
      v26 = v8;
    }
    *v6 = (signed int)v27;
    *v5 = (signed int)v26;
  }
}

