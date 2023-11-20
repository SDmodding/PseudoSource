// File Line: 106
// RVA: 0x35F610
UFG::qVector3 *__fastcall UFG::CoverObjectBase::GetFiringPosition(UFG::WayGraph *this, UFG::qVector3 *result, unsigned __int16 n)
{
  float v3; // xmm1_4
  UFG::qVector3 *v4; // rax
  float v5; // xmm0_4

  v3 = UFG::qVector3::msZero.y;
  v4 = result;
  result->x = UFG::qVector3::msZero.x;
  v5 = UFG::qVector3::msZero.z;
  result->y = v3;
  result->z = v5;
  return v4;
}

// File Line: 159
// RVA: 0x3625C0
float __usercall UFG::CoverObjectBase::GetSideOffset@<xmm0>(UFG::CoverObjectBase *this@<rcx>, float a2@<xmm0>)
{
  float result; // xmm0_4

  ((void (*)(void))this->vfptr->GetHeight)();
  if ( a2 <= 0.5 || a2 >= 1.6 )
    result = UFG::CoverObjectBase::ms_fHighSideOffset;
  else
    result = UFG::CoverObjectBase::ms_fLowSideOffset;
  return result;
}

