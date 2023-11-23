// File Line: 97
// RVA: 0xF8F00
float __fastcall RVO::distSqPointLineSegment(RVO::Vector2 *a, RVO::Vector2 *b, RVO::Vector2 *c)
{
  RVO::Vector2 *v6; // rbx
  RVO::Vector2 *v7; // rax
  float v8; // xmm6_4
  RVO::Vector2 *v9; // rax
  RVO::Vector2 *p_result; // rdx
  float v11; // xmm6_4
  RVO::Vector2 *v12; // r8
  RVO::Vector2 *v13; // rax
  RVO::Vector2 *v14; // rax
  RVO::Vector2 *v15; // rax
  RVO::Vector2 *v16; // rax
  RVO::Vector2 v18; // [rsp+20h] [rbp-38h] BYREF
  RVO::Vector2 v19; // [rsp+28h] [rbp-30h] BYREF
  RVO::Vector2 v20; // [rsp+30h] [rbp-28h] BYREF
  RVO::Vector2 result; // [rsp+78h] [rbp+20h] BYREF

  v6 = RVO::Vector2::operator-(b, &result, a);
  v7 = RVO::Vector2::operator-(c, &v18, a);
  v8 = (float)(v6->y_ * v7->y_) + (float)(v6->x_ * v7->x_);
  v9 = RVO::Vector2::operator-(b, &v19, a);
  p_result = &result;
  v11 = v8 / (float)((float)(v9->x_ * v9->x_) + (float)(v9->y_ * v9->y_));
  if ( v11 >= 0.0 )
  {
    if ( v11 <= 1.0 )
    {
      v13 = RVO::Vector2::operator-(b, &result, a);
      v14 = RVO::operator*(&v19, v11, v13);
      v15 = RVO::Vector2::operator+(a, &v18, v14);
      p_result = &v20;
      v12 = v15;
    }
    else
    {
      v12 = b;
    }
  }
  else
  {
    v12 = a;
  }
  v16 = RVO::Vector2::operator-(c, p_result, v12);
  return (float)(v16->x_ * v16->x_) + (float)(v16->y_ * v16->y_);
}

