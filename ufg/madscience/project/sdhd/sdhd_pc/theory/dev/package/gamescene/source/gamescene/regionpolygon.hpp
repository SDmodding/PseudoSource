// File Line: 83
// RVA: 0x23D160
void __fastcall UFG::RegionPolygon::GetBoundingBox(UFG::RegionPolygon *this, UFG::qBox *pBox)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm1_4

  y = this->mBoundingBox.mMin.y;
  z = this->mBoundingBox.mMin.z;
  pBox->mMin.x = this->mBoundingBox.mMin.x;
  pBox->mMin.y = y;
  pBox->mMin.z = z;
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
  __m128 y_low; // xmm2
  float v2; // xmm0_4

  y_low = (__m128)LODWORD(this->mBoundingBox.mMax.y);
  v2 = this->mBoundingBox.mMax.z - this->mBoundingBox.mMin.z;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->mBoundingBox.mMin.y)
                                    * (float)(y_low.m128_f32[0] - this->mBoundingBox.mMin.y))
                            + (float)((float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x)
                                    * (float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x)))
                    + (float)(v2 * v2);
  return _mm_sqrt_ps(y_low).m128_f32[0] * 0.5;
}

