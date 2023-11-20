// File Line: 36
// RVA: 0x335EA0
void __fastcall UFG::CoverObjectParkour::~CoverObjectParkour(UFG::CoverObjectParkour *this)
{
  UFG::CoverObjectParkour *v1; // r8
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectParkour::`vftable;
  v2 = &this->m_pParkourHandle;
  if ( this->m_pParkourHandle.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectBase::`vftable;
}

// File Line: 97
// RVA: 0x35FF20
float __fastcall UFG::CoverObjectParkour::GetHeight(UFG::CoverObjectParkour *this)
{
  float result; // xmm0_4

  LODWORD(result) = LODWORD(this->m_fParkourSyncZOffset) ^ _xmm[0];
  return result;
}

