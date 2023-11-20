// File Line: 49
// RVA: 0x643CD0
void __fastcall UFG::CrumbTrail::~CrumbTrail(UFG::CrumbTrail *this)
{
  UFG::Crumb *v1; // rcx
  float *v2; // rbx

  v1 = this->mTrail.mData;
  if ( v1 )
  {
    v2 = &v1[-1].fCurvature;
    `eh vector destructor iterator(v1, 0x20ui64, LODWORD(v1[-1].fCurvature), (void (__fastcall *)(void *))_);
    operator delete[](v2);
  }
}

