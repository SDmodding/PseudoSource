// File Line: 79
// RVA: 0xF65B0
RVO::Vector2 *__fastcall RVO::Vector2::operator-(RVO::Vector2 *this, RVO::Vector2 *result)
{
  RVO::Vector2 *v2; // rax

  v2 = result;
  LODWORD(result->x_) = LODWORD(this->x_) ^ _xmm[0];
  LODWORD(result->y_) = LODWORD(this->y_) ^ _xmm[0];
  return v2;
}

// File Line: 81
// RVA: 0xF6560
RVO::Vector2 *__fastcall RVO::Vector2::operator*(RVO::Vector2 *this, RVO::Vector2 *result, float s)
{
  RVO::Vector2 *v3; // rax
  float v4; // xmm0_4

  v3 = result;
  v4 = s * this->x_;
  result->y_ = s * this->y_;
  result->x_ = v4;
  return v3;
}

// File Line: 82
// RVA: 0xF6610
RVO::Vector2 *__fastcall RVO::Vector2::operator/(RVO::Vector2 *this, RVO::Vector2 *result, float s)
{
  RVO::Vector2 *v3; // rax
  float v4; // xmm0_4

  v3 = result;
  v4 = (float)(1.0 / s) * this->x_;
  result->y_ = (float)(1.0 / s) * this->y_;
  result->x_ = v4;
  return v3;
}

// File Line: 83
// RVA: 0xF65E0
RVO::Vector2 *__fastcall RVO::Vector2::operator+(RVO::Vector2 *this, RVO::Vector2 *result, RVO::Vector2 *vector)
{
  RVO::Vector2 *v3; // rax
  float v4; // xmm1_4

  v3 = result;
  v4 = vector->y_ + this->y_;
  result->x_ = vector->x_ + this->x_;
  result->y_ = v4;
  return v3;
}

// File Line: 84
// RVA: 0xF6580
RVO::Vector2 *__fastcall RVO::Vector2::operator-(RVO::Vector2 *this, RVO::Vector2 *result, RVO::Vector2 *vector)
{
  RVO::Vector2 *v3; // rax
  float v4; // xmm1_4

  v3 = result;
  v4 = this->y_ - vector->y_;
  result->x_ = this->x_ - vector->x_;
  result->y_ = v4;
  return v3;
}

// File Line: 100
// RVA: 0xF6540
RVO::Vector2 *__fastcall RVO::operator*(RVO::Vector2 *result, float s, RVO::Vector2 *vector)
{
  RVO::Vector2 *v3; // rax
  float v4; // xmm0_4

  v3 = result;
  v4 = s * vector->x_;
  result->y_ = s * vector->y_;
  result->x_ = v4;
  return v3;
}

// File Line: 104
// RVA: 0xF9D00
RVO::Vector2 *__fastcall RVO::normalize(RVO::Vector2 *result, RVO::Vector2 *vector)
{
  __m128 x_low; // xmm1

  x_low = (__m128)LODWORD(vector->x_);
  x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(vector->y_ * vector->y_);
  RVO::Vector2::operator/(vector, result, _mm_sqrt_ps(x_low).m128_f32[0]);
  return result;
}

