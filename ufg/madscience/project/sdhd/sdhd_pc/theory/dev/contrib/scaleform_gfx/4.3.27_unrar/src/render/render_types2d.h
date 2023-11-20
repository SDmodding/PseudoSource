// File Line: 400
// RVA: 0x700B20
bool __fastcall Scaleform::Render::Rect<float>::IsNull(Scaleform::Render::Rect<float> *this)
{
  return this->x1 == this->x2 && this->y1 == this->y2;
}

// File Line: 401
// RVA: 0x7003B0
bool __fastcall Scaleform::Render::Rect<float>::IsEmpty(Scaleform::Render::Rect<float> *this)
{
  return this->x2 <= this->x1 || this->y2 <= this->y1;
}

// File Line: 656
// RVA: 0x8E6CA0
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::Rect<float>::Intersect(Scaleform::Render::Rect<float> *this, float left, float top, float right, float bottom)
{
  float v5; // xmm5_4
  float v6; // xmm6_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm7_4
  Scaleform::Render::Rect<float> *result; // rax

  v5 = this->y2;
  v6 = top;
  if ( v5 < top
    || (v7 = this->y1, v8 = bottom, bottom < v7)
    || (v9 = this->x1, right < this->x1)
    || (v10 = this->x2, v10 < left) )
  {
    *(_QWORD *)&this->x1 = 0i64;
    *(_QWORD *)&this->x2 = 0i64;
    result = this;
  }
  else
  {
    if ( v9 <= left )
      v9 = left;
    this->x1 = v9;
    if ( v10 <= right )
      right = v10;
    this->x2 = right;
    if ( v7 <= v6 )
      v7 = v6;
    this->y1 = v7;
    if ( v5 <= bottom )
      v8 = v5;
    this->y2 = v8;
    result = this;
  }
  return result;
}

// File Line: 748
// RVA: 0x996800
char __fastcall Scaleform::Render::Rect<float>::IntersectRect(Scaleform::Render::Rect<float> *this, Scaleform::Render::Rect<float> *pdest, Scaleform::Render::Rect<float> *r)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4

  if ( r->y1 > this->y2 )
    return 0;
  if ( this->y1 > r->y2 )
    return 0;
  v3 = this->x1;
  if ( this->x1 > r->x2 || r->x1 > this->x2 )
    return 0;
  if ( v3 <= r->x1 )
    v3 = r->x1;
  pdest->x1 = v3;
  v4 = r->x2;
  if ( this->x2 <= v4 )
    v4 = this->x2;
  pdest->x2 = v4;
  v5 = this->y1;
  if ( v5 <= r->y1 )
    v5 = r->y1;
  pdest->y1 = v5;
  v6 = r->y2;
  if ( this->y2 <= v6 )
    v6 = this->y2;
  pdest->y2 = v6;
  return 1;
}

