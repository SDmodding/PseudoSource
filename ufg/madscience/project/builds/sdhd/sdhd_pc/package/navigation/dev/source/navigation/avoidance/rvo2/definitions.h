// File Line: 97
// RVA: 0xF8F00
float __fastcall RVO::distSqPointLineSegment(RVO::Vector2 *a, RVO::Vector2 *b, RVO::Vector2 *c)
{
  RVO::Vector2 *v3; // rbp
  RVO::Vector2 *v4; // rdi
  RVO::Vector2 *v5; // rsi
  RVO::Vector2 *v6; // rbx
  RVO::Vector2 *v7; // rax
  float v8; // xmm6_4
  RVO::Vector2 *v9; // rax
  RVO::Vector2 *v10; // rdx
  float v11; // xmm6_4
  RVO::Vector2 *v12; // r8
  RVO::Vector2 *v13; // rax
  RVO::Vector2 *v14; // rax
  RVO::Vector2 *v15; // rax
  RVO::Vector2 *v16; // rax
  RVO::Vector2 v18; // [rsp+20h] [rbp-38h]
  RVO::Vector2 v19; // [rsp+28h] [rbp-30h]
  RVO::Vector2 v20; // [rsp+30h] [rbp-28h]
  RVO::Vector2 result; // [rsp+78h] [rbp+20h]

  v3 = b;
  v4 = c;
  v5 = a;
  v6 = RVO::Vector2::operator-(b, &result, a);
  v7 = RVO::Vector2::operator-(v4, &v18, v5);
  v8 = (float)(v6->y_ * v7->y_) + (float)(v6->x_ * v7->x_);
  v9 = RVO::Vector2::operator-(v3, &v19, v5);
  v10 = &result;
  v11 = v8 / (float)((float)(v9->x_ * v9->x_) + (float)(v9->y_ * v9->y_));
  if ( v11 >= 0.0 )
  {
    if ( v11 <= 1.0 )
    {
      v13 = RVO::Vector2::operator-(v3, &result, v5);
      v14 = RVO::operator*(&v19, v11, v13);
      v15 = RVO::Vector2::operator+(v5, &v18, v14);
      v10 = &v20;
      v12 = v15;
    }
    else
    {
      v12 = v3;
    }
  }
  else
  {
    v12 = v5;
  }
  v16 = RVO::Vector2::operator-(v4, v10, v12);
  return (float)(v16->x_ * v16->x_) + (float)(v16->y_ * v16->y_);
}

