// File Line: 25
// RVA: 0x939B30
void __fastcall Scaleform::Render::Cxform::Cxform(Scaleform::Render::Cxform *this)
{
  this->M[0][0] = 1.0;
  this->M[0][1] = 1.0;
  *(_QWORD *)&this->M[1][1] = 0i64;
  this->M[1][3] = 0.0;
  this->M[0][2] = 1.0;
  *(_QWORD *)&this->M[0][3] = 1065353216i64;
}

// File Line: 80
// RVA: 0x9B0BD0
void __fastcall Scaleform::Render::Cxform::SetIdentity(Scaleform::Render::Cxform *this)
{
  this->M[0][0] = 1.0;
  this->M[0][1] = 1.0;
  this->M[0][2] = 1.0;
  *(_OWORD *)&this->M[0][3] = 0x3F800000ui64;
  this->M[1][3] = 0.0;
}

// File Line: 130
// RVA: 0x997940
bool __fastcall Scaleform::Render::Cxform::IsIdentity(Scaleform::Render::Cxform *this)
{
  return 1.0 == this->M[0][0]
      && 1.0 == this->M[0][1]
      && 1.0 == this->M[0][2]
      && 1.0 == this->M[0][3]
      && this->M[1][0] == 0.0
      && this->M[1][1] == 0.0
      && this->M[1][2] == 0.0
      && this->M[1][3] == 0.0;
}

// File Line: 136
// RVA: 0x94E760
bool __fastcall Scaleform::Render::Cxform::operator==(Scaleform::Render::Cxform *this, Scaleform::Render::Cxform *x)
{
  return x->M[0][0] == this->M[0][0]
      && x->M[0][1] == this->M[0][1]
      && x->M[0][2] == this->M[0][2]
      && x->M[0][3] == this->M[0][3]
      && x->M[1][0] == this->M[1][0]
      && x->M[1][1] == this->M[1][1]
      && x->M[1][2] == this->M[1][2]
      && x->M[1][3] == this->M[1][3];
}

// File Line: 142
// RVA: 0x94EB20
bool __fastcall Scaleform::Render::Cxform::operator!=(Scaleform::Render::Cxform *this, Scaleform::Render::Cxform *x)
{
  char v2; // al

  if ( this->M[0][0] != x->M[0][0]
    || this->M[0][1] != x->M[0][1]
    || this->M[0][2] != x->M[0][2]
    || this->M[0][3] != x->M[0][3]
    || this->M[1][0] != x->M[1][0]
    || this->M[1][1] != x->M[1][1]
    || this->M[1][2] != x->M[1][2]
    || (v2 = 1, this->M[1][3] != x->M[1][3]) )
  {
    v2 = 0;
  }
  return v2 == 0;
}

// File Line: 252
// RVA: 0x99FB80
void __fastcall Scaleform::Render::Cxform::Prepend(Scaleform::Render::Cxform *this, Scaleform::Render::Cxform *c)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm1

  v2 = *(__m128 *)&this->M[1][0];
  v3 = _mm_mul_ps(*(__m128 *)&c->M[1][0], *(__m128 *)&this->M[0][0]);
  *(__m128 *)&this->M[0][0] = _mm_mul_ps(*(__m128 *)&c->M[0][0], *(__m128 *)&this->M[0][0]);
  *(__m128 *)&this->M[1][0] = _mm_add_ps(v2, v3);
}

// File Line: 267
// RVA: 0x958960
void __fastcall Scaleform::Render::Cxform::Append(Scaleform::Render::Cxform *this, Scaleform::Render::Cxform *c)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm1

  v2 = *(__m128 *)&c->M[1][0];
  v3 = _mm_mul_ps(*(__m128 *)&this->M[1][0], *(__m128 *)&c->M[0][0]);
  *(__m128 *)&this->M[0][0] = _mm_mul_ps(*(__m128 *)&this->M[0][0], *(__m128 *)&c->M[0][0]);
  *(__m128 *)&this->M[1][0] = _mm_add_ps(v2, v3);
}

// File Line: 297
// RVA: 0x99C770
void __fastcall Scaleform::Render::Cxform::Normalize(Scaleform::Render::Cxform *this)
{
  *(__m128 *)&this->M[1][0] = _mm_mul_ps(*(__m128 *)&this->M[1][0], tffinv);
}

