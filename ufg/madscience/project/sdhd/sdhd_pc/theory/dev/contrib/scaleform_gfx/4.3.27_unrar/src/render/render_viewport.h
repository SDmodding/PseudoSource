// File Line: 135
// RVA: 0x92C6D0
char __fastcall Scaleform::Render::Viewport::GetClippedRect<int>(
        Scaleform::Render::Viewport *this,
        Scaleform::Render::Rect<int> *prect,
        bool orient)
{
  int Width; // eax
  int Height; // r8d
  int Top; // ebx
  int Left; // r11d
  int BufferWidth; // edi
  int BufferHeight; // esi
  int v9; // r10d
  int v10; // r9d
  int v11; // ebp
  int v12; // edi
  int ScissorLeft; // r11d
  int ScissorTop; // ebx
  int v15; // esi
  int v16; // ecx

  if ( !orient || (((this->Flags & 0x30) - 16) & 0xFFFFFFDF) != 0 )
  {
    Height = this->Height;
    Width = this->Width;
  }
  else
  {
    Width = this->Height;
    Height = this->Width;
  }
  Top = this->Top;
  Left = this->Left;
  BufferWidth = this->BufferWidth;
  BufferHeight = this->BufferHeight;
  v9 = Top + Height;
  v10 = Left + Width;
  if ( Top + Height < 0 || BufferHeight < Top || BufferWidth < Left || v10 < 0 )
  {
    *(_QWORD *)&prect->x1 = 0i64;
    *(_QWORD *)&prect->x2 = 0i64;
    return 0;
  }
  else
  {
    v11 = 0;
    if ( Left > 0 )
      v11 = this->Left;
    if ( v10 > BufferWidth )
      v10 = this->BufferWidth;
    v12 = 0;
    if ( Top > 0 )
      v12 = this->Top;
    prect->x1 = v11;
    if ( v9 > BufferHeight )
      v9 = BufferHeight;
    prect->x2 = v10;
    prect->y1 = v12;
    prect->y2 = v9;
    if ( (this->Flags & 4) == 0 )
      return 1;
    ScissorLeft = this->ScissorLeft;
    ScissorTop = this->ScissorTop;
    v15 = ScissorLeft + this->ScissorWidth;
    v16 = ScissorTop + this->ScissorHeight;
    if ( v9 >= ScissorTop && v16 >= v12 && v15 >= v11 && v10 >= ScissorLeft )
    {
      if ( v11 > ScissorLeft )
        ScissorLeft = v11;
      if ( v10 > v15 )
        v10 = v15;
      prect->x1 = ScissorLeft;
      if ( v12 > ScissorTop )
        ScissorTop = v12;
      prect->x2 = v10;
      if ( v9 > v16 )
        v9 = v16;
      prect->y1 = ScissorTop;
      prect->y2 = v9;
      return 1;
    }
    *(_QWORD *)&prect->x1 = 0i64;
    *(_QWORD *)&prect->x2 = 0i64;
    return 0;
  }
}

// File Line: 191
// RVA: 0x981A90
char __fastcall Scaleform::Render::Viewport::GetCullRectF(
        Scaleform::Render::Viewport *this,
        Scaleform::Render::Rect<float> *prect,
        bool orient)
{
  char result; // al
  float v6; // xmm3_4
  __m128i v7; // xmm1
  unsigned int v8; // eax
  __m128i v9; // xmm0
  Scaleform::Render::Rect<int> precta; // [rsp+20h] [rbp-18h] BYREF

  *(_QWORD *)&precta.x1 = 0i64;
  *(_QWORD *)&precta.x2 = 0i64;
  result = Scaleform::Render::Viewport::GetClippedRect<int>(this, &precta, orient);
  if ( result )
  {
    v6 = (float)(precta.y2 - this->Top);
    v7 = _mm_cvtsi32_si128(precta.y1 - this->Top);
    v8 = precta.x1 - this->Left;
    prect->x2 = (float)(precta.x2 - this->Left);
    prect->y2 = v6;
    v9 = _mm_cvtsi32_si128(v8);
    result = 1;
    LODWORD(prect->y1) = _mm_cvtepi32_ps(v7).m128_u32[0];
    LODWORD(prect->x1) = _mm_cvtepi32_ps(v9).m128_u32[0];
  }
  return result;
}

