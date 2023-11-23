// File Line: 24
// RVA: 0x1460D00
void UFG::_dynamic_initializer_for__hkvZero___0()
{
  hkvZero_0.m_quad = 0i64;
}

// File Line: 90
// RVA: 0xE6660
UFG::HavokNavPosition *__fastcall UFG::HavokNavPosition::operator=(
        UFG::HavokNavPosition *this,
        UFG::HavokNavPosition *other)
{
  float y; // xmm0_4
  float z; // xmm1_4
  bool m_bValid; // al

  y = other->m_vPosition.y;
  z = other->m_vPosition.z;
  this->m_vPosition.x = other->m_vPosition.x;
  this->m_vPosition.y = y;
  this->m_vPosition.z = z;
  m_bValid = other->m_bValid;
  if ( m_bValid )
  {
    this->m_bValid = m_bValid;
    this->m_hkvMeshPosition = other->m_hkvMeshPosition;
    this->m_packedKey = other->m_packedKey;
    this->m_aiMeshUid = other->m_aiMeshUid;
  }
  else
  {
    this->m_bValid = 0;
  }
  return this;
}

// File Line: 118
// RVA: 0xEE8E0
bool __fastcall UFG::HavokNavPosition::HasBeenValidated(UFG::HavokNavPosition *this)
{
  unsigned int m_packedKey; // ebx
  unsigned int m_aiMeshUid; // edi
  hkaiDynamicNavMeshQueryMediator *DynamicQueryMediator; // rax
  bool result; // al

  result = 0;
  if ( this->m_bValid )
  {
    m_packedKey = this->m_packedKey;
    m_aiMeshUid = this->m_aiMeshUid;
    if ( m_packedKey == -1 )
      return 1;
    DynamicQueryMediator = (hkaiDynamicNavMeshQueryMediator *)hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
    if ( DynamicQueryMediator )
    {
      if ( UFG::HavokAIUtilGame::IsFaceKeyValid(DynamicQueryMediator, m_packedKey, m_aiMeshUid) )
        return 1;
    }
  }
  return result;
}

// File Line: 120
// RVA: 0xEF6F0
bool __fastcall UFG::HavokNavPosition::IsMeshPositionValid(UFG::HavokNavPosition *this)
{
  unsigned int m_packedKey; // edi
  unsigned int m_aiMeshUid; // esi
  hkaiDynamicNavMeshQueryMediator *DynamicQueryMediator; // rax
  bool result; // al

  result = this->m_bValid
        && ((m_packedKey = this->m_packedKey, m_aiMeshUid = this->m_aiMeshUid, m_packedKey == -1)
         || (DynamicQueryMediator = (hkaiDynamicNavMeshQueryMediator *)hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr)) != 0i64
         && UFG::HavokAIUtilGame::IsFaceKeyValid(DynamicQueryMediator, m_packedKey, m_aiMeshUid))
        && this->m_packedKey != -1
        && this->m_aiMeshUid != -1;
  return result;
}

// File Line: 126
// RVA: 0xED0B0
void __fastcall UFG::HavokNavPosition::GetMeshPosition(UFG::HavokNavPosition *this, UFG::qVector3 *vMeshPosOut)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = this->m_hkvMeshPosition.m_quad.m128_f32[1];
  v3 = this->m_hkvMeshPosition.m_quad.m128_f32[2];
  LODWORD(vMeshPosOut->x) = this->m_hkvMeshPosition.m_quad.m128_i32[0];
  vMeshPosOut->y = v2;
  vMeshPosOut->z = v3;
}

// File Line: 130
// RVA: 0xEF4B0
void __fastcall UFG::HavokNavPosition::Invalidate(UFG::HavokNavPosition *this)
{
  this->m_bValid = 0;
}

// File Line: 135
// RVA: 0xF0E70
void __fastcall UFG::HavokNavPosition::SetInvalidMeshPosition(UFG::HavokNavPosition *this)
{
  this->m_bValid = 1;
  *(_QWORD *)&this->m_packedKey = -1i64;
}

// File Line: 152
// RVA: 0xEF770
bool __fastcall UFG::HavokNavPosition::IsOnMesh(UFG::HavokNavPosition *this, float fToleranceXY)
{
  float v4; // [rsp+20h] [rbp-28h] BYREF
  float v5; // [rsp+24h] [rbp-24h]

  if ( !this->vfptr->IsMeshPositionValid(this) )
    return 0;
  this->vfptr->GetMeshPosition(this, (UFG::qVector3 *)&v4);
  return (float)(fToleranceXY * fToleranceXY) > (float)((float)((float)(this->m_vPosition.y - v5)
                                                              * (float)(this->m_vPosition.y - v5))
                                                      + (float)((float)(this->m_vPosition.x - v4)
                                                              * (float)(this->m_vPosition.x - v4)));
}

