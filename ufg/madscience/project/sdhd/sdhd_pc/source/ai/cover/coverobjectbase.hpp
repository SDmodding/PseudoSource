// File Line: 146
// RVA: 0x27E150
bool __fastcall UFG::CoverObjectBase::IsHighCover(UFG::CoverObjectBase *this)
{
  double v2; // xmm0_8
  float v3; // xmm6_4
  float v4; // xmm0_4

  v2 = ((double (__fastcall *)(UFG::CoverObjectBase *))this->vfptr->GetHeight)(this);
  v3 = *(float *)&v2;
  v4 = this->vfptr->GetHeight(this);
  return (v4 <= 0.5 || v4 >= 1.6) && v3 > 1.5;
}

// File Line: 160
// RVA: 0x52D990
float __fastcall UFG::CoverObjectBase::GetFrontOffset(UFG::CoverObjectBase *this)
{
  float v1; // xmm0_4

  v1 = this->vfptr->GetHeight(this);
  if ( v1 <= 0.5 || v1 >= 1.6 )
    return UFG::CoverObjectBase::ms_fHighFrontOffset;
  else
    return UFG::CoverObjectBase::ms_fLowFrontOffset;
}

