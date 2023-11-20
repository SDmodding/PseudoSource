// File Line: 83
// RVA: 0x23D160
void __fastcall UFG::RegionPolygon::GetBoundingBox(UFG::RegionPolygon *this, UFG::qBox *pBox)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm1_4

  v2 = this->mBoundingBox.mMin.y;
  v3 = this->mBoundingBox.mMin.z;
  pBox->mMin.x = this->mBoundingBox.mMin.x;
  pBox->mMin.y = v2;
  pBox->mMin.z = v3;
  v4 = this->mBoundingBox.mMax.y;
  v5 = this->mBoundingBox.mMax.z;
  pBox->mMax.x = this->mBoundingBox.mMax.x;
  pBox->mMax.y = v4;
  pBox->mMax.z = v5;
}

// File Line: 85
// RVA: 0x23C0D0
float __fastcall UFG::RegionPolygon::GetAreaCrossSection(UFG::RegionPolygon *this)
{
  return (float)(this->mBoundingBox.mMax.y - this->mBoundingBox.mMin.y)
       * (float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x);
}

// File Line: 87
// RVA: 0x23DAD0
float __fastcall UFG::RegionPolygon::GetRadius(UFG::RegionPolygon *this)
{
  __m128 v1; // xmm2
  float v2; // xmm0_4

  v1 = (__m128)LODWORD(this->mBoundingBox.mMax.y);
  v2 = this->mBoundingBox.mMax.z - this->mBoundingBox.mMin.z;
  v1.m128_f32[0] = (float)((float)((float)(v1.m128_f32[0] - this->mBoundingBox.mMin.y)
                                 * (float)(v1.m128_f32[0] - this->mBoundingBox.mMin.y))
                         + (float)((float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x)
                                 * (float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x)))
                 + (float)(v2 * v2);
  return COERCE_FLOAT(_mm_sqrt_ps(v1)) * 0.5;
}

