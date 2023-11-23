// File Line: 43
// RVA: 0x4FBC0
float __fastcall UFG::Camera::GetNearPlane(UFG::Camera *this)
{
  float z; // xmm1_4
  float v3; // [rsp+8h] [rbp+8h]

  z = this->mProjection.v2.z;
  if ( z == 0.0 || z == this->mProjection.v2.w )
    return v3;
  else
    return this->mProjection.v3.z / z;
}

// File Line: 44
// RVA: 0x318C0
float __fastcall UFG::Camera::GetFarPlane(UFG::Camera *this)
{
  float z; // xmm1_4
  float w; // xmm2_4
  float v4; // [rsp+8h] [rbp+8h]

  z = this->mProjection.v2.z;
  w = this->mProjection.v2.w;
  if ( z == 0.0 || z == w )
    return v4;
  else
    return (float)(this->mProjection.v3.z - this->mProjection.v3.w) / (float)(z - w);
}

