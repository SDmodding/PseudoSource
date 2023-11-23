// File Line: 48
// RVA: 0x1452B50
__int64 Render::_dynamic_initializer_for__gFontInventory__()
{
  UFG::qResourceInventory::qResourceInventory(&Render::gFontInventory, "FontInventory", 0x69FCCB4Cu, 0x2A1BE612u, 0, 0);
  Render::gFontInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::FontInventory::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gFontInventory__);
}

// File Line: 57
// RVA: 0xA5C0
void __fastcall Render::FontInventory::Add(Render::FontInventory *this, Render::Font *resource_data)
{
  Render::Font::OnLoad(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 86
// RVA: 0xA8D0
void __fastcall Render::Font::OnLoad(Render::Font *this)
{
  Render::Font *v1; // rsi
  unsigned int v2; // eax
  int v3; // edi
  Illusion::Material *mMaterial; // rbx
  int v5; // edi
  Illusion::Material *v6; // rbx
  Illusion::Material *v7; // rbx
  Illusion::Material *v8; // rbx
  UFG::qResourceWarehouse *v9; // rax

  v1 = this;
  if ( this )
    UFG::qResourceData::qResourceData(this);
  else
    v1 = 0i64;
  v2 = UFG::qStringHash32("Font.Primitive", v1->mNode.mUID);
  v1->mMaterial = Illusion::Factory::NewMaterial("Font.Primitive", v2, 4u, 0i64, 0i64, 0i64);
  v3 = UFG::qStringHash32("SIMPLE", 0xFFFFFFFF);
  mMaterial = v1->mMaterial;
  LOWORD(mMaterial[1].mNode.mChild[0]) = 0;
  HIDWORD(mMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(mMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  mMaterial[1].mTypeUID = -1957338719;
  LODWORD(mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v3;
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
  LODWORD(v7[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v7[2].mNode.mUID = -1551679522;
  v8 = v1->mMaterial;
  LOWORD(v8[2].mTypeUID) = 0;
  HIDWORD(v8[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v8[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v8[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v8[2].mDebugName[28] = 1660426324;
  v9 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v9, v1->mMaterial);
}

// File Line: 113
// RVA: 0xADE0
void __fastcall Render::Font::PrintChar(
        Render::Font *this,
        Render::vDynamic **vertex_buffer,
        float *x,
        float *y,
        unsigned int colour,
        char ascii_char,
        int left_margin,
        float reciprocal_view_width,
        float reciprocal_view_height)
{
  __int16 v11; // r10
  __int64 v12; // rax
  char *v13; // rdx
  char *v14; // rbp
  __int16 v15; // cx
  __int16 v16; // r10
  __int16 v17; // ax
  float v18; // xmm0_4
  __int16 v19; // r9
  float v20; // xmm3_4
  float v21; // xmm1_4
  __int64 v22; // rdi
  float v23; // xmm0_4
  float v24; // xmm2_4
  __int64 mOffset; // rax
  char *v26; // r11

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
        mOffset = this->mGlyphTable.mOffset;
        if ( mOffset )
          v26 = (char *)&this->mGlyphTable + mOffset;
        else
          v26 = 0i64;
        *x = (float)*(unsigned __int16 *)&v26[48 * v11 + 42] + *x;
        break;
      default:
        if ( v11 >= 0 )
        {
          v12 = this->mGlyphTable.mOffset;
          if ( v12 )
            v13 = (char *)&this->mGlyphTable + v12;
          else
            v13 = 0i64;
          v14 = &v13[48 * v11];
          if ( vertex_buffer )
          {
            v15 = *((_WORD *)v14 + 10);
            v16 = *((_WORD *)v14 + 8);
            v17 = *((_WORD *)v14 + 9);
            v18 = *((float *)v14 + 7) + *y;
            v19 = *((_WORD *)v14 + 11);
            v20 = (float)(*((float *)v14 + 6) + *x) * reciprocal_view_width;
            v21 = (float)(reciprocal_view_width * *((float *)v14 + 8)) + v20;
            v22 = (__int64)*vertex_buffer;
            v23 = v18 * reciprocal_view_height;
            v24 = (float)(reciprocal_view_height * *((float *)v14 + 9)) + v23;
            *(float *)v22 = v20;
            *(float *)(v22 + 4) = v23;
            *(_DWORD *)(v22 + 8) = 0;
            *(_WORD *)(v22 + 12) = v16;
            *(_WORD *)(v22 + 14) = v17;
            *(_DWORD *)(v22 + 44) = colour;
            *(float *)(v22 + 96) = v21;
            *(float *)(v22 + 100) = v23;
            *(_DWORD *)(v22 + 104) = 0;
            *(_WORD *)(v22 + 108) = v15;
            *(_WORD *)(v22 + 110) = v17;
            *(_DWORD *)(v22 + 140) = colour;
            *(_DWORD *)(v22 + 200) = 0;
            *(float *)(v22 + 192) = v21;
            *(float *)(v22 + 196) = v24;
            *(_WORD *)(v22 + 204) = v15;
            *(_WORD *)(v22 + 206) = v19;
            *(_DWORD *)(v22 + 236) = colour;
            *(_DWORD *)(v22 + 56) = 0;
            *(float *)(v22 + 48) = v20;
            *(float *)(v22 + 52) = v24;
            *(_WORD *)(v22 + 60) = v16;
            *(_WORD *)(v22 + 62) = v19;
            *(_DWORD *)(v22 + 92) = colour;
            Render::vDynamic::operator=((Render::vDynamic *)(v22 + 144), (Render::vDynamic *)(v22 + 48));
            Render::vDynamic::operator=((Render::vDynamic *)(v22 + 240), (Render::vDynamic *)(v22 + 96));
            *vertex_buffer += 6;
          }
          *x = (float)*((unsigned __int16 *)v14 + 21) + *x;
        }
        break;
    }
  }
}

// File Line: 212
// RVA: 0xAAA0
void Render::Font::Print(
        Render::Font *this,
        Render::View *view,
        int int_x,
        int int_y,
        UFG::qColour *colour,
        char *format,
        ...)
{
  int v9; // eax
  char *v10; // rax
  Render::vDynamic *v11; // r15
  Render::vDynamic *v12; // rdi
  __int16 mNumGlyphs; // r12
  __int16 mNumKernings; // r13
  int v15; // ebp
  float reciprocal_view_width; // xmm7_4
  char *v17; // rsi
  __m128i v18; // xmm0
  char v19; // al
  float reciprocal_view_height; // xmm6_4
  char ascii_char; // di
  __int16 v22; // cx
  __int64 mOffset; // rax
  char *v24; // rdx
  __int16 v25; // ax
  __int64 v26; // rcx
  char v27; // r9
  char *v28; // rdx
  __int64 v29; // rcx
  int v30; // eax
  char *v31; // rdx
  int v32; // eax
  __int64 v33; // rdx
  float x; // [rsp+50h] [rbp-2088h] BYREF
  float y; // [rsp+54h] [rbp-2084h] BYREF
  Render::vDynamic *vertex_buffer; // [rsp+58h] [rbp-2080h] BYREF
  char *v37; // [rsp+60h] [rbp-2078h]
  char dest[8192]; // [rsp+70h] [rbp-2068h] BYREF
  va_list va; // [rsp+2110h] [rbp+38h] BYREF

  va_start(va, format);
  v9 = UFG::qVSPrintf(dest, 0x2000, format, va);
  if ( v9 )
  {
    v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 288 * v9, 0x10u);
    v11 = (Render::vDynamic *)v10;
    v37 = v10;
    if ( v10 )
    {
      vertex_buffer = (Render::vDynamic *)v10;
      v12 = (Render::vDynamic *)v10;
      mNumGlyphs = this->mNumGlyphs;
      mNumKernings = this->mNumKernings;
      v15 = (int)(float)(colour->r * 255.0) | (((int)(float)(colour->g * 255.0) | (((int)(float)(colour->b * 255.0) | ((int)(float)(colour->a * 255.0) << 8)) << 8)) << 8);
      x = (float)int_x;
      y = (float)int_y;
      reciprocal_view_width = 1.0 / (float)Render::View::GetTargetWidth(view);
      v17 = dest;
      v18 = _mm_cvtsi32_si128(Render::View::GetTargetHeight(view));
      v19 = dest[0];
      reciprocal_view_height = 1.0 / _mm_cvtepi32_ps(v18).m128_f32[0];
      if ( dest[0] )
      {
        do
        {
          ascii_char = v19;
          if ( v19 == -73 )
            ascii_char = 32;
          Render::Font::PrintChar(
            this,
            &vertex_buffer,
            &x,
            &y,
            v15,
            ascii_char,
            int_x,
            reciprocal_view_width,
            reciprocal_view_height);
          v22 = this->mAsciiToGlyph[ascii_char];
          if ( v22 >= 0 && v22 < mNumGlyphs )
          {
            mOffset = this->mGlyphTable.mOffset;
            v24 = mOffset ? (char *)&this->mGlyphTable + mOffset : 0i64;
            v25 = *(_WORD *)&v24[48 * v22 + 46];
            if ( v25 >= 0 && v25 < mNumKernings )
            {
              v26 = this->mKerningTable.mOffset;
              v27 = v17[1];
              if ( v26 )
                v28 = (char *)&this->mKerningTable + v26;
              else
                v28 = 0i64;
              v29 = 3i64 * v25;
              v30 = *(unsigned __int16 *)&v28[6 * v25];
              v31 = &v28[2 * v29];
              if ( v30 == ascii_char )
              {
                do
                {
                  if ( *((unsigned __int16 *)v31 + 1) >= v27 )
                    break;
                  v32 = *((unsigned __int16 *)v31 + 3);
                  v31 += 6;
                }
                while ( v32 == ascii_char );
              }
              if ( *((unsigned __int16 *)v31 + 1) == v27 )
                x = x + (float)*((__int16 *)v31 + 2);
            }
          }
          v19 = *++v17;
        }
        while ( v19 );
        v12 = vertex_buffer;
        v11 = (Render::vDynamic *)v37;
      }
      v33 = v12 - v11;
      if ( (_DWORD)v33 )
        Render::View::DrawDebugPrim(view, DebugPrim_Triangle, v11, v33);
    }
  }
}

// File Line: 292
// RVA: 0xA650
void Render::Font::Measure(Render::Font *this, int *w, int *h, const char *format, ...)
{
  float v7; // xmm6_4
  float mLineHeight; // xmm7_4
  char v9; // r8
  float v10; // xmm1_4
  float v11; // xmm2_4
  char *v12; // r11
  __int16 v13; // cx
  __int64 mOffset; // rax
  char *v15; // rdx
  __int16 v16; // cx
  __int64 v17; // rax
  char *v18; // rdx
  __int16 v19; // r9
  __int64 v20; // rax
  char v21; // r10
  char *v22; // rdx
  int v23; // eax
  char *v24; // rdx
  int v25; // eax
  float v26; // [rsp+20h] [rbp-2058h]
  float v27; // [rsp+24h] [rbp-2054h]
  char dest[8192]; // [rsp+30h] [rbp-2048h] BYREF
  va_list va; // [rsp+20A0h] [rbp+28h] BYREF

  va_start(va, format);
  v7 = 0.0;
  v27 = 0.0;
  mLineHeight = (float)this->mLineHeight;
  v26 = mLineHeight;
  if ( (unsigned int)UFG::qVSPrintf(dest, 0x2000, format, va) )
  {
    v9 = dest[0];
    v10 = 0.0;
    v11 = 0.0;
    v12 = dest;
    if ( dest[0] )
    {
      do
      {
        v13 = this->mAsciiToGlyph[v9];
        if ( v9 != -73 )
        {
          if ( v9 == 9 )
          {
            v10 = (float)((float)(v10 * 0.0099999998) + 1.0) * 100.0;
          }
          else if ( v9 == 10 || v9 == 13 )
          {
            v10 = 0.0;
            v11 = v11 + (float)this->mLineHeight;
          }
          else if ( v9 == 32 || v13 >= 0 )
          {
            mOffset = this->mGlyphTable.mOffset;
            if ( mOffset )
              v15 = (char *)&this->mGlyphTable + mOffset;
            else
              v15 = 0i64;
            v10 = v10 + (float)*(unsigned __int16 *)&v15[48 * v13 + 42];
          }
        }
        v16 = this->mAsciiToGlyph[v9];
        if ( v16 >= 0 && v16 < SLOWORD(this->mNumGlyphs) )
        {
          v17 = this->mGlyphTable.mOffset;
          v18 = v17 ? (char *)&this->mGlyphTable + v17 : 0i64;
          v19 = *(_WORD *)&v18[48 * v16 + 46];
          if ( v19 >= 0 && v19 < SLOWORD(this->mNumKernings) )
          {
            v20 = this->mKerningTable.mOffset;
            v21 = v12[1];
            if ( v20 )
              v22 = (char *)&this->mKerningTable + v20;
            else
              v22 = 0i64;
            v23 = *(unsigned __int16 *)&v22[6 * v19];
            v24 = &v22[6 * v19];
            if ( v23 == v9 )
            {
              do
              {
                if ( *((unsigned __int16 *)v24 + 1) >= v21 )
                  break;
                v25 = *((unsigned __int16 *)v24 + 3);
                v24 += 6;
              }
              while ( v25 == v9 );
            }
            if ( *((unsigned __int16 *)v24 + 1) == v21 )
              v10 = v10 + (float)*((__int16 *)v24 + 2);
          }
        }
        if ( v7 <= v10 )
          v7 = v10;
        if ( mLineHeight <= v11 )
          mLineHeight = v11;
        v9 = *++v12;
      }
      while ( v9 );
      v27 = v7;
      v26 = mLineHeight;
    }
    *w = (int)v27;
    *h = (int)v26;
  }
}

