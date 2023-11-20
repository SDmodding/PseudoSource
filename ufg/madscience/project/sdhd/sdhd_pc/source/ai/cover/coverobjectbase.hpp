// File Line: 146
// RVA: 0x27E150
bool __usercall UFG::CoverObjectBase::IsHighCover@<al>(UFG::CoverObjectBase *this@<rcx>, float a2@<xmm0>)
{
  UFG::CoverObjectBase *v2; // rbx

  v2 = this;
  ((void (*)(void))this->vfptr->GetHeight)();
  v2->vfptr->GetHeight(v2);
  return (a2 <= 0.5 || a2 >= 1.6) && a2 > 1.5;
}

// File Line: 160
// RVA: 0x52D990
float __usercall UFG::CoverObjectBase::GetFrontOffset@<xmm0>(UFG::CoverObjectBase *this@<rcx>, float a2@<xmm0>)
{
  float result; // xmm0_4

  ((void (*)(void))this->vfptr->GetHeight)();
  if ( a2 <= 0.5 || a2 >= 1.6 )
    result = UFG::CoverObjectBase::ms_fHighFrontOffset;
  else
    result = UFG::CoverObjectBase::ms_fLowFrontOffset;
  return result;
}

