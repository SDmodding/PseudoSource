// File Line: 43
// RVA: 0x4FBC0
float __fastcall UFG::Camera::GetNearPlane(UFG::Camera *this)
{
  float v1; // xmm1_4
  float result; // xmm0_4
  float v3; // [rsp+8h] [rbp+8h]

  v1 = this->mProjection.v2.z;
  if ( v1 == 0.0 || v1 == this->mProjection.v2.w )
    result = v3;
  else
    result = this->mProjection.v3.z / v1;
  return result;
}

// File Line: 44
// RVA: 0x318C0
float __fastcall UFG::Camera::GetFarPlane(UFG::Camera *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float result; // xmm0_4
  float v4; // [rsp+8h] [rbp+8h]

  v1 = this->mProjection.v2.z;
  v2 = this->mProjection.v2.w;
  if ( v1 == 0.0 || v1 == v2 )
    result = v4;
  else
    result = (float)(this->mProjection.v3.z - this->mProjection.v3.w) / (float)(v1 - v2);
  return result;
}

