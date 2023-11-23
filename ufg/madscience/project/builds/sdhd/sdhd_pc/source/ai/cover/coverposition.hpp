// File Line: 55
// RVA: 0x36B8D0
bool __fastcall UFG::CoverPosition::IsParkour(UFG::CoverPosition *this)
{
  return this->m_bInbetweenParkourLine || this->m_pParkourHandle.m_pPointer;
}

// File Line: 95
// RVA: 0x3879B0
void __fastcall UFG::CoverPosition::SetParkourHandle(UFG::CoverPosition *this, UFG::ParkourHandle *pParkourHandle)
{
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_m_pParkourHandle; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rax

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
  p_m_pParkourHandle->m_pPointer = pParkourHandle;
  if ( pParkourHandle )
  {
    v5 = pParkourHandle->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev;
    v5->mNext = p_m_pParkourHandle;
    p_m_pParkourHandle->mPrev = v5;
    p_m_pParkourHandle->mNext = &pParkourHandle->m_SafePointerList.mNode;
    pParkourHandle->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev = p_m_pParkourHandle;
  }
}

// File Line: 140
// RVA: 0x399520
void __fastcall UFG::CoverPosition::ValidateNavPosition(UFG::CoverPosition *this)
{
  UFG::qVector3 *v2; // rax
  float z; // xmm1_4
  float y; // xmm0_4
  char v5[24]; // [rsp+20h] [rbp-18h] BYREF

  v2 = this->vfptr->GetSyncPos(this, v5);
  z = v2->z;
  y = v2->y;
  this->m_NavPosition.m_vPosition.x = v2->x;
  this->m_NavPosition.m_vPosition.z = z;
  this->m_NavPosition.m_vPosition.y = y;
  this->m_NavPosition.m_bValid = 0;
  ((void (__fastcall *)(UFG::HavokNavPosition *))this->m_NavPosition.vfptr->Validate)(&this->m_NavPosition);
}

// File Line: 145
// RVA: 0x387730
void __fastcall UFG::CoverPosition::SetNavPosition(UFG::CoverPosition *this, UFG::HavokNavPosition *otherNavPosition)
{
  float y; // xmm0_4
  float z; // xmm1_4
  bool m_bValid; // al

  y = otherNavPosition->m_vPosition.y;
  z = otherNavPosition->m_vPosition.z;
  this->m_NavPosition.m_vPosition.x = otherNavPosition->m_vPosition.x;
  this->m_NavPosition.m_vPosition.y = y;
  this->m_NavPosition.m_vPosition.z = z;
  m_bValid = otherNavPosition->m_bValid;
  if ( m_bValid )
  {
    this->m_NavPosition.m_bValid = m_bValid;
    this->m_NavPosition.m_hkvMeshPosition = otherNavPosition->m_hkvMeshPosition;
    this->m_NavPosition.m_packedKey = otherNavPosition->m_packedKey;
    this->m_NavPosition.m_aiMeshUid = otherNavPosition->m_aiMeshUid;
  }
  else
  {
    this->m_NavPosition.m_bValid = 0;
  }
}

