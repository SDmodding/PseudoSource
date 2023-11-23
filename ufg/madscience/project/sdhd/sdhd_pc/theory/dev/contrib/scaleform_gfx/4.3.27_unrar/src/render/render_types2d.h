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
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::Rect<float>::Intersect(
        Scaleform::Render::Rect<float> *this,
        float left,
        float top,
        float right,
        float bottom)
{
  float y2; // xmm5_4
  float y1; // xmm4_4
  float v8; // xmm0_4
  float x1; // xmm2_4
  float x2; // xmm7_4

  y2 = this->y2;
  if ( y2 < top
    || (y1 = this->y1, v8 = bottom, bottom < y1)
    || (x1 = this->x1, right < this->x1)
    || (x2 = this->x2, x2 < left) )
  {
    *(_QWORD *)&this->x1 = 0i64;
    *(_QWORD *)&this->x2 = 0i64;
    return this;
  }
  else
  {
    if ( x1 <= left )
      x1 = left;
    this->x1 = x1;
    if ( x2 <= right )
      right = x2;
    this->x2 = right;
    if ( y1 <= top )
      y1 = top;
    this->y1 = y1;
    if ( y2 <= bottom )
      v8 = y2;
    this->y2 = v8;
    return this;
  }
}

// File Line: 748
// RVA: 0x996800
char __fastcall Scaleform::Render::Rect<float>::IntersectRect(
        Scaleform::Render::Rect<float> *this,
        Scaleform::Render::Rect<float> *pdest,
        Scaleform::Render::Rect<float> *r)
{
  float x1; // xmm0_4
  float x2; // xmm1_4
  float y1; // xmm0_4
  float y2; // xmm0_4

  if ( r->y1 > this->y2 )
    return 0;
  if ( this->y1 > r->y2 )
    return 0;
  x1 = this->x1;
  if ( this->x1 > r->x2 || r->x1 > this->x2 )
    return 0;
  if ( x1 <= r->x1 )
    x1 = r->x1;
  pdest->x1 = x1;
  x2 = r->x2;
  if ( this->x2 <= x2 )
    x2 = this->x2;
  pdest->x2 = x2;
  y1 = this->y1;
  if ( y1 <= r->y1 )
    y1 = r->y1;
  pdest->y1 = y1;
  y2 = r->y2;
  if ( this->y2 <= y2 )
    y2 = this->y2;
  pdest->y2 = y2;
  return 1;
}

