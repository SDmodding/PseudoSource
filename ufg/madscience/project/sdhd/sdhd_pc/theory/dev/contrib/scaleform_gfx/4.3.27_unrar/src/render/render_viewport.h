// File Line: 135
// RVA: 0x92C6D0
bool __fastcall Scaleform::Render::Viewport::GetClippedRect<int>(Scaleform::Render::Viewport *this, Scaleform::Render::Rect<int> *prect, bool orient)
{
  int v3; // eax
  int v4; // er8
  int v5; // ebx
  int v6; // er11
  int v7; // edi
  int v8; // esi
  int v9; // er10
  int v10; // er9
  int v11; // ebp
  int v12; // edi
  int v13; // er11
  int v14; // ebx
  int v15; // esi
  int v16; // ecx
  bool result; // al

  if ( !orient || ((this->Flags & 0x30) - 16) & 0xFFFFFFDF )
  {
    v4 = this->Height;
    v3 = this->Width;
  }
  else
  {
    v3 = this->Height;
    v4 = this->Width;
  }
  v5 = this->Top;
  v6 = this->Left;
  v7 = this->BufferWidth;
  v8 = this->BufferHeight;
  v9 = v5 + v4;
  v10 = v6 + v3;
  if ( v5 + v4 < 0 || v8 < v5 || v7 < v6 || v10 < 0 )
  {
    *(_QWORD *)&prect->x1 = 0i64;
    *(_QWORD *)&prect->x2 = 0i64;
    result = 0;
  }
  else
  {
    v11 = 0;
    if ( v6 > 0 )
      v11 = this->Left;
    if ( v10 > v7 )
      v10 = this->BufferWidth;
    v12 = 0;
    if ( v5 > 0 )
      v12 = this->Top;
    prect->x1 = v11;
    if ( v9 > v8 )
      v9 = v8;
    prect->x2 = v10;
    prect->y1 = v12;
    prect->y2 = v9;
    if ( !(this->Flags & 4) )
      return 1;
    v13 = this->ScissorLeft;
    v14 = this->ScissorTop;
    v15 = v13 + this->ScissorWidth;
    v16 = v14 + this->ScissorHeight;
    if ( v9 >= v14 && v16 >= v12 && v15 >= v11 && v10 >= v13 )
    {
      if ( v11 > v13 )
        v13 = v11;
      if ( v10 > v15 )
        v10 = v15;
      prect->x1 = v13;
      if ( v12 > v14 )
        v14 = v12;
      prect->x2 = v10;
      if ( v9 > v16 )
        v9 = v16;
      prect->y1 = v14;
      prect->y2 = v9;
      return 1;
    }
    *(_QWORD *)&prect->x1 = 0i64;
    *(_QWORD *)&prect->x2 = 0i64;
    result = 0;
  }
  return result;
}

// File Line: 191
// RVA: 0x981A90
bool __fastcall Scaleform::Render::Viewport::GetCullRectF(Scaleform::Render::Viewport *this, Scaleform::Render::Rect<float> *prect, bool orient)
{
  Scaleform::Render::Rect<float> *v3; // rbx
  Scaleform::Render::Viewport *v4; // rdi
  bool result; // al
  float v6; // xmm3_4
  __m128i v7; // xmm1
  unsigned int v8; // eax
  __m128i v9; // xmm0
  Scaleform::Render::Rect<int> precta; // [rsp+20h] [rbp-18h]

  v3 = prect;
  v4 = this;
  *(_QWORD *)&precta.x1 = 0i64;
  *(_QWORD *)&precta.x2 = 0i64;
  result = Scaleform::Render::Viewport::GetClippedRect<int>(this, &precta, orient);
  if ( result )
  {
    v6 = (float)(precta.y2 - v4->Top);
    v7 = _mm_cvtsi32_si128(precta.y1 - v4->Top);
    v8 = precta.x1 - v4->Left;
    v3->x2 = (float)(precta.x2 - v4->Left);
    v3->y2 = v6;
    v9 = _mm_cvtsi32_si128(v8);
    result = 1;
    LODWORD(v3->y1) = (unsigned __int128)_mm_cvtepi32_ps(v7);
    LODWORD(v3->x1) = (unsigned __int128)_mm_cvtepi32_ps(v9);
  }
  return result;
}

