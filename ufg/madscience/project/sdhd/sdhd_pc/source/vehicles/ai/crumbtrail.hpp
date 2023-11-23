// File Line: 49
// RVA: 0x643CD0
void __fastcall UFG::CrumbTrail::~CrumbTrail(UFG::CrumbTrail *this)
{
  UFG::Crumb *mData; // rcx
  float *p_fCurvature; // rbx

  mData = this->mTrail.mData;
  if ( mData )
  {
    p_fCurvature = &mData[-1].fCurvature;
    `eh vector destructor iterator(mData, 0x20ui64, LODWORD(mData[-1].fCurvature), (void (__fastcall *)(void *))_);
    operator delete[](p_fCurvature);
  }
}

