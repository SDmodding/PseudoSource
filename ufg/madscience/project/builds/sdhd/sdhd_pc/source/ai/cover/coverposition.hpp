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
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&this->m_pParkourHandle.mPrev;
  if ( this->m_pParkourHandle.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)pParkourHandle;
  if ( pParkourHandle )
  {
    v5 = pParkourHandle->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    v2->mNext = &pParkourHandle->m_SafePointerList.mNode;
    pParkourHandle->m_SafePointerList.mNode.mPrev = v2;
  }
}

// File Line: 140
// RVA: 0x399520
void __fastcall UFG::CoverPosition::ValidateNavPosition(UFG::CoverPosition *this)
{
  UFG::CoverPosition *v1; // rbx
  UFG::qVector3 *v2; // rax
  signed __int64 v3; // rcx
  float v4; // xmm1_4
  float v5; // xmm0_4
  char v6; // [rsp+20h] [rbp-18h]

  v1 = this;
  v2 = this->vfptr->GetSyncPos((UFG::CoverObjectBase *)this, (UFG::qVector3 *)&v6);
  v3 = (signed __int64)&v1->m_NavPosition;
  v4 = v2->z;
  v5 = v2->y;
  *(float *)(v3 + 8) = v2->x;
  *(float *)(v3 + 16) = v4;
  *(float *)(v3 + 12) = v5;
  *(_BYTE *)(v3 + 24) = 0;
  ((void (*)(void))v1->m_NavPosition.vfptr->Validate)();
}

// File Line: 145
// RVA: 0x387730
void __fastcall UFG::CoverPosition::SetNavPosition(UFG::CoverPosition *this, UFG::HavokNavPosition *otherNavPosition)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  bool v4; // al

  v2 = otherNavPosition->m_vPosition.y;
  v3 = otherNavPosition->m_vPosition.z;
  this->m_NavPosition.m_vPosition.x = otherNavPosition->m_vPosition.x;
  this->m_NavPosition.m_vPosition.y = v2;
  this->m_NavPosition.m_vPosition.z = v3;
  v4 = otherNavPosition->m_bValid;
  if ( v4 )
  {
    this->m_NavPosition.m_bValid = v4;
    this->m_NavPosition.m_hkvMeshPosition = otherNavPosition->m_hkvMeshPosition;
    this->m_NavPosition.m_packedKey = otherNavPosition->m_packedKey;
    this->m_NavPosition.m_aiMeshUid = otherNavPosition->m_aiMeshUid;
  }
  else
  {
    this->m_NavPosition.m_bValid = 0;
  }
}

