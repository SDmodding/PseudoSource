// File Line: 36
// RVA: 0x335EA0
void __fastcall UFG::CoverObjectParkour::~CoverObjectParkour(UFG::CoverObjectParkour *this)
{
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_m_pParkourHandle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v6; // rax

  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectParkour::`vftable;
  p_m_pParkourHandle = &this->m_pParkourHandle;
  if ( this->m_pParkourHandle.m_pPointer )
  {
    mPrev = p_m_pParkourHandle->mPrev;
    mNext = p_m_pParkourHandle->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pParkourHandle->mPrev = p_m_pParkourHandle;
    p_m_pParkourHandle->mNext = p_m_pParkourHandle;
  }
  p_m_pParkourHandle->m_pPointer = 0i64;
  v5 = p_m_pParkourHandle->mPrev;
  v6 = p_m_pParkourHandle->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pParkourHandle->mPrev = p_m_pParkourHandle;
  p_m_pParkourHandle->mNext = p_m_pParkourHandle;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectBase::`vftable;
}

// File Line: 97
// RVA: 0x35FF20
float __fastcall UFG::CoverObjectParkour::GetHeight(UFG::CoverObjectParkour *this)
{
  float result; // xmm0_4

  LODWORD(result) = LODWORD(this->m_fParkourSyncZOffset) ^ _xmm[0];
  return result;
}

