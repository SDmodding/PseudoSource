// File Line: 272
// RVA: 0x209CF0
UFG::qBox *__fastcall UFG::qBox::Enclose(UFG::qBox *this, UFG::qVector3 *pos)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  UFG::qBox *result; // rax

  v2 = this->mMin.x;
  if ( this->mMin.x >= pos->x )
    v2 = pos->x;
  this->mMin.x = v2;
  v3 = this->mMin.y;
  if ( v3 >= pos->y )
    v3 = pos->y;
  this->mMin.y = v3;
  v4 = this->mMin.z;
  if ( v4 >= pos->z )
    v4 = pos->z;
  this->mMin.z = v4;
  v5 = this->mMax.x;
  if ( v5 <= pos->x )
    v5 = pos->x;
  this->mMax.x = v5;
  v6 = this->mMax.y;
  if ( v6 <= pos->y )
    v6 = pos->y;
  this->mMax.y = v6;
  v7 = this->mMax.z;
  v8 = pos->z;
  result = this;
  if ( v7 <= v8 )
    this->mMax.z = v8;
  else
    this->mMax.z = v7;
  return result;
}

// File Line: 329
// RVA: 0x23DF00
UFG::qVector3 *__fastcall UFG::qBox::GetRandomPosition(UFG::qBox *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rdi
  UFG::qBox *v3; // rbx
  float v4; // xmm10_4
  float v5; // xmm9_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm0_4
  float v11; // xmm7_4
  float v12; // xmm8_4

  v2 = result;
  v3 = this;
  v4 = this->mMax.x;
  v5 = this->mMin.x;
  if ( this->mMin.x > v4 || (v6 = this->mMin.y, v6 > this->mMax.y) || (v7 = this->mMin.z, v7 > this->mMax.z) )
  {
    v11 = this->mMin.y - this->mMax.y;
    v12 = this->mMin.z - this->mMax.z;
    result->x = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) * (float)(v5 - v4)) + this->mMax.x;
    v2->y = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) * v11) + v3->mMax.y;
    v10 = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) * v12) + v3->mMax.z;
  }
  else
  {
    v8 = this->mMax.y - v6;
    v9 = this->mMax.z - v7;
    result->x = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) * (float)(v4 - v5)) + this->mMin.x;
    v2->y = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) * v8) + v3->mMin.y;
    v10 = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed) * v9) + v3->mMin.z;
  }
  v2->z = v10;
  return v2;
}

