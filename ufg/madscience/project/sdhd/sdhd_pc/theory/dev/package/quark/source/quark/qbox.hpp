// File Line: 272
// RVA: 0x209CF0
UFG::qBox *__fastcall UFG::qBox::Enclose(UFG::qBox *this, UFG::qVector3 *pos)
{
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  UFG::qBox *result; // rax

  x = this->mMin.x;
  if ( this->mMin.x >= pos->x )
    x = pos->x;
  this->mMin.x = x;
  y = this->mMin.y;
  if ( y >= pos->y )
    y = pos->y;
  this->mMin.y = y;
  z = this->mMin.z;
  if ( z >= pos->z )
    z = pos->z;
  this->mMin.z = z;
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
  float x; // xmm10_4
  float v5; // xmm9_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm0_4
  float v11; // xmm7_4
  float v12; // xmm8_4

  x = this->mMax.x;
  v5 = this->mMin.x;
  if ( this->mMin.x > x || (y = this->mMin.y, y > this->mMax.y) || (z = this->mMin.z, z > this->mMax.z) )
  {
    v11 = this->mMin.y - this->mMax.y;
    v12 = this->mMin.z - this->mMax.z;
    result->x = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) * (float)(v5 - x)) + this->mMax.x;
    result->y = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) * v11) + this->mMax.y;
    v10 = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) * v12) + this->mMax.z;
  }
  else
  {
    v8 = this->mMax.y - y;
    v9 = this->mMax.z - z;
    result->x = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) * (float)(x - v5)) + this->mMin.x;
    result->y = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) * v8) + this->mMin.y;
    v10 = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) * v9) + this->mMin.z;
  }
  result->z = v10;
  return result;
}

