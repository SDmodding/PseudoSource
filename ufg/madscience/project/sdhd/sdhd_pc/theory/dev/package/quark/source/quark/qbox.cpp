// File Line: 191
// RVA: 0x17D130
UFG::qBox *__fastcall UFG::qBox::SetRadius(UFG::qBox *this, float radius)
{
  float x; // xmm3_4
  float y; // xmm9_4
  float z; // xmm10_4
  float v5; // xmm11_4
  __m128 y_low; // xmm7
  float v7; // xmm8_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm6_4
  float v11; // xmm1_4
  float v12; // xmm10_4
  float v13; // xmm9_4
  __m128 v14; // xmm2
  float v15; // xmm6_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm1_4

  x = this->mMax.x;
  y_low = (__m128)LODWORD(this->mMax.y);
  y = this->mMin.y;
  z = this->mMin.z;
  v5 = this->mMin.x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - y;
  v7 = this->mMax.z - z;
  v8 = x - this->mMin.x;
  if ( v8 == 0.0 && y_low.m128_f32[0] == 0.0 && v7 == 0.0 )
  {
    v9 = radius * 0.57735026;
    LODWORD(v10) = COERCE_UNSIGNED_INT(radius * 0.57735026) ^ _xmm[0];
    this->mMax.x = x + (float)(radius * 0.57735026);
    v11 = (float)(radius * 0.57735026) + this->mMax.z;
    this->mMax.y = v9 + this->mMax.y;
    this->mMax.z = v11;
    this->mMin.x = v10 + v5;
    this->mMin.y = v10 + y;
    this->mMin.z = v10 + z;
  }
  else
  {
    v12 = z + this->mMax.z;
    v13 = y + this->mMax.y;
    v14 = y_low;
    this->mMin.x = v5 + x;
    this->mMin.y = v13;
    this->mMin.z = v12;
    v14.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v8 * v8)) + (float)(v7 * v7);
    v15 = radius / _mm_sqrt_ps(v14).m128_f32[0];
    v16 = this->mMin.x * 0.5;
    v17 = this->mMin.y * 0.5;
    this->mMin.x = v16;
    this->mMin.y = v17;
    this->mMin.z = v12 * 0.5;
    v18 = v15 * v8;
    v19 = v15 * y_low.m128_f32[0];
    v20 = v15 * v7;
    this->mMax.x = v18 + v16;
    this->mMax.y = v19 + v17;
    this->mMax.z = v20 + (float)(v12 * 0.5);
    v21 = this->mMin.y;
    this->mMin.x = this->mMin.x - v18;
    v22 = this->mMin.z - v20;
    this->mMin.y = v21 - v19;
    this->mMin.z = v22;
  }
  return this;
}

// File Line: 228
// RVA: 0x16CDF0
float __fastcall UFG::qBox::DistanceSqrPoint(UFG::qBox *this, UFG::qVector3 *pos)
{
  float x; // xmm1_4
  float v3; // xmm2_4
  float result; // xmm0_4
  float y; // xmm1_4
  float v6; // xmm2_4
  float z; // xmm1_4
  float v8; // xmm2_4

  x = pos->x;
  v3 = this->mMin.x;
  result = 0.0;
  if ( pos->x < this->mMin.x || (v3 = this->mMax.x, x > v3) )
    result = (float)(x - v3) * (float)(x - v3);
  y = pos->y;
  v6 = this->mMin.y;
  if ( y < v6 || (v6 = this->mMax.y, y > v6) )
    result = result + (float)((float)(y - v6) * (float)(y - v6));
  z = pos->z;
  v8 = this->mMin.z;
  if ( z < v8 )
    return result + (float)((float)(z - v8) * (float)(z - v8));
  v8 = this->mMax.z;
  if ( z > v8 )
    return result + (float)((float)(z - v8) * (float)(z - v8));
  return result;
}

// File Line: 295
// RVA: 0x1756E0
char __fastcall UFG::qBox::IsHitRay(
        UFG::qBox *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qBox::eFace *pFace,
        UFG::qVector3 *pHitPos)
{
  UFG::qBox::eFace v5; // r10d
  float x; // xmm8_4
  float v7; // xmm4_4
  int v8; // eax
  float y; // xmm9_4
  float v10; // xmm5_4
  float z; // xmm10_4
  float v12; // xmm6_4
  float v14; // xmm11_4
  float v15; // xmm14_4
  float v16; // xmm13_4
  float v17; // xmm15_4
  bool v18; // r8
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm4_4
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm12_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm3_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm0_4

  v5 = Face_none;
  if ( pFace )
    *pFace = Face_none;
  x = rayPos->x;
  v7 = this->mMin.x;
  if ( rayPos->x >= this->mMin.x )
    v8 = x > this->mMax.x;
  else
    v8 = 2;
  y = rayPos->y;
  v10 = this->mMin.y;
  if ( y >= v10 )
  {
    if ( y > this->mMax.y )
      v8 |= 4u;
  }
  else
  {
    v8 |= 8u;
  }
  z = rayPos->z;
  v12 = this->mMin.z;
  if ( z >= v12 )
  {
    if ( z > this->mMax.z )
      v8 |= 0x10u;
  }
  else
  {
    v8 |= 0x20u;
  }
  if ( v8 )
  {
    v14 = FLOAT_3_4028235e38;
    v15 = rayDir->y;
    v16 = rayDir->z;
    v17 = rayDir->x;
    v18 = !pFace && !pHitPos;
    if ( (v8 & 3) != 0 && v17 != 0.0 )
    {
      v19 = 1.0 / v17;
      if ( (v8 & 2) != 0 )
      {
        v20 = (float)(v7 - x) * v19;
        if ( v20 >= 0.0 )
        {
          v21 = (float)(v20 * v15) + y;
          v22 = (float)(v20 * v16) + z;
          if ( v10 <= v21 && v21 <= this->mMax.y && v12 <= v22 && v22 <= this->mMax.z )
          {
            if ( v18 )
              return 1;
            v14 = (float)(v7 - x) * v19;
            v5 = Face_min_x;
            if ( pHitPos )
            {
              pHitPos->x = v7;
              pHitPos->y = v21;
              pHitPos->z = v22;
            }
          }
        }
      }
      if ( (v8 & 1) != 0 )
      {
        v23 = (float)(this->mMax.x - x) * v19;
        if ( v23 >= 0.0 )
        {
          v24 = (float)(v23 * v15) + y;
          v25 = (float)(v23 * v16) + z;
          if ( v24 >= this->mMin.y && v24 <= this->mMax.y && v25 >= this->mMin.z && v25 <= this->mMax.z )
          {
            if ( v18 )
              return 1;
            v14 = (float)(this->mMax.x - x) * v19;
            v5 = Face_max_x;
            if ( pHitPos )
            {
              pHitPos->x = this->mMax.x;
              pHitPos->y = v24;
              pHitPos->z = v25;
            }
          }
        }
      }
    }
    if ( (v8 & 0xC) != 0 && v15 != 0.0 )
    {
      v26 = 1.0 / v15;
      if ( (v8 & 8) != 0 )
      {
        v27 = this->mMin.y;
        v28 = (float)(v27 - y) * v26;
        if ( v28 >= 0.0 )
        {
          v29 = (float)(v28 * v17) + x;
          v30 = (float)(v28 * v16) + z;
          if ( v29 >= this->mMin.x && v29 <= this->mMax.x && v30 >= this->mMin.z && v30 <= this->mMax.z )
          {
            if ( v18 )
              return 1;
            v14 = (float)(this->mMin.y - y) * v26;
            v5 = Face_min_y;
            if ( pHitPos )
            {
              pHitPos->x = v29;
              pHitPos->y = v27;
              pHitPos->z = v30;
            }
          }
        }
      }
      if ( (v8 & 4) != 0 )
      {
        v31 = this->mMax.y;
        v32 = (float)(v31 - y) * v26;
        if ( v32 >= 0.0 )
        {
          v33 = (float)(v32 * v17) + x;
          v34 = (float)(v32 * v16) + z;
          if ( v33 >= this->mMin.x && v33 <= this->mMax.x && v34 >= this->mMin.z && v34 <= this->mMax.z )
          {
            if ( v18 )
              return 1;
            v14 = (float)(this->mMax.y - y) * v26;
            v5 = Face_max_y;
            if ( pHitPos )
            {
              pHitPos->x = v33;
              pHitPos->y = v31;
              pHitPos->z = v34;
            }
          }
        }
      }
    }
    if ( (v8 & 0x30) != 0 && v16 != 0.0 )
    {
      v35 = 1.0 / v16;
      if ( (v8 & 0x20) != 0 )
      {
        v36 = this->mMin.z;
        v37 = (float)(v36 - z) * v35;
        if ( v37 >= 0.0 )
        {
          v38 = (float)(v37 * v17) + x;
          v39 = (float)(v37 * v15) + y;
          if ( v38 >= this->mMin.x && v38 <= this->mMax.x && v39 >= this->mMin.y && v39 <= this->mMax.y )
          {
            if ( v18 )
              return 1;
            v14 = (float)(this->mMin.z - z) * v35;
            v5 = Face_min_z;
            if ( pHitPos )
            {
              pHitPos->x = v38;
              pHitPos->y = v39;
              pHitPos->z = v36;
            }
          }
        }
      }
      if ( (v8 & 0x10) != 0 )
      {
        v40 = this->mMax.z;
        v41 = (float)(v40 - z) * v35;
        if ( v41 >= 0.0 )
        {
          v42 = (float)(v41 * v17) + x;
          v43 = (float)(v41 * v15) + y;
          if ( v42 >= this->mMin.x && v42 <= this->mMax.x && v43 >= this->mMin.y && v43 <= this->mMax.y )
          {
            if ( v18 )
              return 1;
            v14 = (float)(this->mMax.z - z) * v35;
            v5 = Face_max_z;
            if ( pHitPos )
            {
              pHitPos->x = v42;
              pHitPos->y = v43;
              pHitPos->z = v40;
            }
          }
        }
      }
    }
    if ( v14 == 3.4028235e38 )
      return 0;
    if ( pFace )
      *pFace = v5;
    return 1;
  }
  if ( pHitPos )
  {
    pHitPos->x = x;
    pHitPos->y = y;
    pHitPos->z = z;
  }
  return 1;
}

// File Line: 592
// RVA: 0x175B50
char __fastcall UFG::qBox::IsHitSeg(
        UFG::qBox *this,
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::qBox::eFace *pFace,
        UFG::qVector3 *pHitPos)
{
  UFG::qBox::eFace v5; // r11d
  float x; // xmm1_4
  float v10; // xmm0_4
  int v11; // r8d
  float y; // xmm2_4
  float v13; // xmm11_4
  float z; // xmm4_4
  float v15; // xmm10_4
  float v17; // xmm9_4
  int v18; // edx
  float v19; // xmm8_4
  float v20; // xmm7_4
  char v21; // r9
  float v22; // xmm3_4
  char v23; // dl
  float v24; // xmm9_4
  float v25; // xmm8_4
  float v26; // xmm7_4
  float v27; // xmm6_4
  float v28; // xmm0_4
  float v29; // xmm5_4
  float v30; // xmm2_4
  float v31; // xmm4_4
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm4_4
  float v36; // xmm5_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm5_4
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm12_4
  float v45; // xmm4_4
  float v46; // xmm0_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm4_4
  float v50; // xmm0_4
  float v51; // xmm2_4
  float v52; // xmm1_4

  v5 = Face_none;
  if ( pFace )
    *pFace = Face_none;
  x = start->x;
  v10 = this->mMin.x;
  if ( start->x >= this->mMin.x )
    v11 = x > this->mMax.x;
  else
    v11 = 2;
  y = start->y;
  v13 = this->mMin.y;
  if ( y >= v13 )
  {
    if ( y > this->mMax.y )
      v11 |= 4u;
  }
  else
  {
    v11 |= 8u;
  }
  z = start->z;
  v15 = this->mMin.z;
  if ( z >= v15 )
  {
    if ( z > this->mMax.z )
      v11 |= 0x10u;
  }
  else
  {
    v11 |= 0x20u;
  }
  if ( v11 )
  {
    v17 = end->x;
    if ( end->x >= v10 )
      v18 = v17 > this->mMax.x;
    else
      v18 = 2;
    v19 = end->y;
    if ( v19 >= v13 )
    {
      if ( v19 > this->mMax.y )
        v18 |= 4u;
    }
    else
    {
      v18 |= 8u;
    }
    v20 = end->z;
    if ( v20 >= v15 )
    {
      if ( v20 > this->mMax.z )
        v18 |= 0x10u;
    }
    else
    {
      v18 |= 0x20u;
    }
    if ( pFace || pHitPos )
    {
      v21 = 0;
    }
    else
    {
      v21 = 1;
      if ( !v18 )
        return 1;
    }
    if ( (v18 & v11) != 0 )
      return 0;
    v22 = FLOAT_3_4028235e38;
    v23 = v11 ^ v18;
    v24 = v17 - x;
    v25 = v19 - y;
    v26 = v20 - z;
    if ( (v23 & 3) != 0 )
    {
      v27 = 1.0 / v24;
      if ( (v23 & 2) != 0 )
      {
        v28 = (float)(v10 - x) * v27;
        v29 = (float)(v28 * v25) + y;
        v30 = (float)(v28 * v26) + z;
        if ( v13 <= v29 && v29 <= this->mMax.y && v15 <= v30 && v30 <= this->mMax.z )
        {
          if ( v21 )
            return 1;
          v22 = v28;
          v5 = Face_min_x;
          if ( pHitPos )
          {
            pHitPos->y = v29;
            pHitPos->z = v30;
            pHitPos->x = (float)(v28 * v24) + x;
          }
        }
      }
      if ( (v23 & 1) != 0 )
      {
        v31 = start->x;
        v32 = (float)(this->mMax.x - start->x) * v27;
        if ( v32 < v22 )
        {
          v33 = (float)(v32 * v25) + start->y;
          v34 = (float)(v32 * v26) + start->z;
          if ( v33 >= this->mMin.y && v33 <= this->mMax.y && v34 >= this->mMin.z && v34 <= this->mMax.z )
          {
            if ( v21 )
              return 1;
            v22 = (float)(this->mMax.x - start->x) * v27;
            v5 = Face_max_x;
            if ( pHitPos )
            {
              pHitPos->y = v33;
              pHitPos->z = v34;
              pHitPos->x = (float)(v32 * v24) + v31;
            }
          }
        }
      }
    }
    if ( (v23 & 0xC) != 0 )
    {
      v35 = 1.0 / v25;
      if ( (v23 & 8) != 0 )
      {
        v36 = start->y;
        v37 = (float)(this->mMin.y - v36) * v35;
        if ( v37 < v22 )
        {
          v38 = (float)(v37 * v24) + start->x;
          v39 = (float)(v37 * v26) + start->z;
          if ( v38 >= this->mMin.x && v38 <= this->mMax.x && v39 >= this->mMin.z && v39 <= this->mMax.z )
          {
            if ( v21 )
              return 1;
            v22 = (float)(this->mMin.y - v36) * v35;
            v5 = Face_min_y;
            if ( pHitPos )
            {
              pHitPos->x = v38;
              pHitPos->z = v39;
              pHitPos->y = (float)(v37 * v25) + v36;
            }
          }
        }
      }
      if ( (v23 & 4) != 0 )
      {
        v40 = start->y;
        v41 = (float)(this->mMax.y - v40) * v35;
        if ( v41 < v22 )
        {
          v42 = (float)(v41 * v24) + start->x;
          v43 = (float)(v41 * v26) + start->z;
          if ( v42 >= this->mMin.x && v42 <= this->mMax.x && v43 >= this->mMin.z && v43 <= this->mMax.z )
          {
            if ( v21 )
              return 1;
            v22 = (float)(this->mMax.y - v40) * v35;
            v5 = Face_max_y;
            if ( pHitPos )
            {
              pHitPos->x = v42;
              pHitPos->z = v43;
              pHitPos->y = (float)(v41 * v25) + v40;
            }
          }
        }
      }
    }
    if ( (v23 & 0x30) != 0 )
    {
      v44 = 1.0 / v26;
      if ( (v23 & 0x20) != 0 )
      {
        v45 = start->z;
        v46 = (float)(this->mMin.z - v45) * v44;
        if ( v46 < v22 )
        {
          v47 = (float)(v46 * v24) + start->x;
          v48 = (float)(v46 * v25) + start->y;
          if ( v47 >= this->mMin.x && v47 <= this->mMax.x && v48 >= this->mMin.y && v48 <= this->mMax.y )
          {
            if ( v21 )
              return 1;
            v22 = (float)(this->mMin.z - v45) * v44;
            v5 = Face_min_z;
            if ( pHitPos )
            {
              pHitPos->x = v47;
              pHitPos->y = v48;
              pHitPos->z = (float)(v46 * v26) + v45;
            }
          }
        }
      }
      if ( (v23 & 0x10) != 0 )
      {
        v49 = start->z;
        v50 = (float)(this->mMax.z - v49) * v44;
        if ( v50 < v22 )
        {
          v51 = (float)(v50 * v24) + start->x;
          v52 = (float)(v50 * v25) + start->y;
          if ( v51 >= this->mMin.x && v51 <= this->mMax.x && v52 >= this->mMin.y && v52 <= this->mMax.y )
          {
            if ( v21 )
              return 1;
            v22 = (float)(this->mMax.z - v49) * v44;
            v5 = Face_max_z;
            if ( pHitPos )
            {
              pHitPos->x = v51;
              pHitPos->y = v52;
              pHitPos->z = (float)(v50 * v26) + v49;
            }
          }
        }
      }
    }
    if ( v22 == 3.4028235e38 )
      return 0;
    if ( pFace )
      *pFace = v5;
    return 1;
  }
  if ( pHitPos )
  {
    pHitPos->x = x;
    pHitPos->y = y;
    pHitPos->z = z;
  }
  return 1;
}

// File Line: 987
// RVA: 0x17E9E0
void __fastcall UFG::qBox::TranslateFace(
        UFG::qBox *this,
        UFG::qBox::eFace face,
        UFG::qVector3 *delta,
        bool preventInversion)
{
  int v4; // edx
  float x; // xmm0_4
  float v6; // xmm0_4
  float y; // xmm0_4
  float v8; // xmm0_4
  float z; // xmm0_4
  float v10; // xmm0_4

  v4 = face - 1;
  if ( preventInversion )
  {
    switch ( v4 )
    {
      case 0:
        x = this->mMax.x + delta->x;
        if ( x <= this->mMin.x )
          x = this->mMin.x;
        this->mMax.x = x;
        break;
      case 1:
        v6 = delta->x + this->mMin.x;
        if ( v6 >= this->mMax.x )
          v6 = this->mMax.x;
        this->mMin.x = v6;
        break;
      case 3:
        y = delta->y + this->mMax.y;
        if ( y <= this->mMin.y )
          y = this->mMin.y;
        this->mMax.y = y;
        break;
      case 7:
        v8 = delta->y + this->mMin.y;
        if ( v8 >= this->mMax.y )
          v8 = this->mMax.y;
        this->mMin.y = v8;
        break;
      case 15:
        z = delta->z + this->mMax.z;
        if ( z <= this->mMin.z )
          z = this->mMin.z;
        this->mMax.z = z;
        break;
      case 31:
        v10 = delta->z + this->mMin.z;
        if ( v10 >= this->mMax.z )
          v10 = this->mMax.z;
        this->mMin.z = v10;
        break;
      default:
        return;
    }
  }
  else
  {
    switch ( v4 )
    {
      case 0:
        this->mMax.x = this->mMax.x + delta->x;
        break;
      case 1:
        this->mMin.x = delta->x + this->mMin.x;
        break;
      case 3:
        this->mMax.y = delta->y + this->mMax.y;
        break;
      case 7:
        this->mMin.y = delta->y + this->mMin.y;
        break;
      case 15:
        this->mMax.z = delta->z + this->mMax.z;
        break;
      case 31:
        this->mMin.z = delta->z + this->mMin.z;
        break;
      default:
        return;
    }
  }
}

// File Line: 1054
// RVA: 0x170410
UFG::qVector3 *__fastcall UFG::qBox::GetFaceCenter(UFG::qBox *this, UFG::qVector3 *result, UFG::qBox::eFace face)
{
  int v3; // r8d
  int v4; // r8d
  int v5; // r8d
  int v6; // r8d
  UFG::qVector3 *v7; // rax
  float x; // eax
  float y; // xmm0_4

  v3 = face - 1;
  if ( !v3 )
  {
    x = this->mMax.x;
    goto LABEL_13;
  }
  v4 = v3 - 1;
  if ( !v4 )
  {
    x = this->mMin.x;
LABEL_13:
    y = this->mMax.y;
    result->x = x;
    result->y = (float)(y + this->mMin.y) * 0.5;
    goto LABEL_14;
  }
  result->x = (float)(this->mMax.x + this->mMin.x) * 0.5;
  v5 = v4 - 2;
  if ( !v5 )
  {
    result->y = this->mMax.y;
    goto LABEL_14;
  }
  v6 = v5 - 4;
  if ( !v6 )
  {
    result->y = this->mMin.y;
LABEL_14:
    v7 = result;
    result->z = (float)(this->mMax.z + this->mMin.z) * 0.5;
    return v7;
  }
  result->y = (float)(this->mMax.y + this->mMin.y) * 0.5;
  if ( v6 == 24 )
    result->z = this->mMin.z;
  else
    result->z = this->mMax.z;
  return result;
}

// File Line: 1083
// RVA: 0x1704C0
UFG::qVector3 *__fastcall UFG::qBox::GetFaceNormal(UFG::qBox *this, UFG::qBox::eFace face)
{
  int v2; // edx
  int v3; // edx
  int v4; // edx
  int v5; // edx

  v2 = face - 1;
  if ( !v2 )
    return &UFG::qVector3::msAxisX;
  v3 = v2 - 1;
  if ( !v3 )
    return &UFG::qVector3::msAxisXNeg;
  v4 = v3 - 2;
  if ( !v4 )
    return &UFG::qVector3::msAxisY;
  v5 = v4 - 4;
  if ( !v5 )
    return &UFG::qVector3::msAxisYNeg;
  if ( v5 == 24 )
    return &UFG::qVector3::msAxisZNeg;
  return &UFG::qVector3::msAxisZ;
}

// File Line: 1120
// RVA: 0x1755E0
char __fastcall UFG::qBox::IsHitFaceBottomRay(
        UFG::qBox *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qVector3 *pHitPos)
{
  float z; // xmm3_4
  float x; // xmm2_4
  float v7; // xmm0_4
  float y; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  UFG::qVector3 plane_pos; // [rsp+30h] [rbp-58h] BYREF
  UFG::qVector3 pos; // [rsp+40h] [rbp-48h] BYREF
  UFG::qVector3 quad4; // [rsp+50h] [rbp-38h] BYREF
  UFG::qVector3 quad3; // [rsp+5Ch] [rbp-2Ch] BYREF
  UFG::qVector3 quad2; // [rsp+68h] [rbp-20h] BYREF

  z = this->mMin.z;
  x = this->mMax.x;
  v7 = this->mMin.x;
  quad4.y = this->mMax.y;
  quad3.y = quad4.y;
  y = this->mMin.y;
  quad4.x = x;
  quad4.z = z;
  quad3.x = v7;
  quad3.z = z;
  quad2.x = v7;
  quad2.y = y;
  quad2.z = z;
  plane_pos.x = x;
  plane_pos.y = y;
  plane_pos.z = z;
  if ( !UFG::qIntersectRayPlane(rayPos, rayDir, &UFG::qVector3::msDirUp, &plane_pos, &pos)
    || !UFG::qIsBoundPointQuad(&pos, &plane_pos, &quad2, &quad3, &quad4) )
  {
    return 0;
  }
  if ( pHitPos )
  {
    v10 = pos.y;
    pHitPos->x = pos.x;
    v11 = pos.z;
    pHitPos->y = v10;
    pHitPos->z = v11;
  }
  return 1;
}

// File Line: 1153
// RVA: 0x16B740
__int64 __fastcall UFG::qBox::CycleFaces(UFG::qBox::eFace face, bool forward)
{
  int v2; // ecx
  __int64 result; // rax

  v2 = face - 1;
  if ( forward )
  {
    switch ( v2 )
    {
      case 0:
        goto $LN14_2;
      case 1:
        goto $LN6_5;
      case 3:
        goto $LN11_6;
      case 7:
        goto $LN13_6;
      case 15:
        goto $LN15_8;
      case 31:
        goto $LN10_7;
      default:
        goto LABEL_10;
    }
  }
  switch ( v2 )
  {
    case 0:
$LN10_7:
      result = 16i64;
      break;
    case 1:
$LN14_2:
      result = 8i64;
      break;
    case 3:
$LN13_6:
      result = 2i64;
      break;
    case 7:
$LN15_8:
      result = 1i64;
      break;
    case 15:
$LN11_6:
      result = 32i64;
      break;
    case 31:
$LN6_5:
      result = 4i64;
      break;
    default:
LABEL_10:
      result = 0i64;
      break;
  }
  return result;
}

