// File Line: 106
// RVA: 0x35F610
UFG::qVector3 *__fastcall UFG::CoverObjectBase::GetFiringPosition(
        UFG::WayGraph *this,
        UFG::qVector3 *result,
        unsigned __int16 n)
{
  float y; // xmm1_4
  UFG::qVector3 *v4; // rax
  float z; // xmm0_4

  y = UFG::qVector3::msZero.y;
  v4 = result;
  result->x = UFG::qVector3::msZero.x;
  z = UFG::qVector3::msZero.z;
  result->y = y;
  result->z = z;
  return v4;
}

// File Line: 159
// RVA: 0x3625C0
float __fastcall UFG::CoverObjectBase::GetSideOffset(UFG::CoverObjectBase *this)
{
  float v1; // xmm0_4

  v1 = this->vfptr->GetHeight(this);
  if ( v1 <= 0.5 || v1 >= 1.6 )
    return UFG::CoverObjectBase::ms_fHighSideOffset;
  else
    return UFG::CoverObjectBase::ms_fLowSideOffset;
}

