// File Line: 24
// RVA: 0x1460D00
void UFG::_dynamic_initializer_for__hkvZero___0()
{
  hkvZero_0.m_quad = 0i64;
}

// File Line: 90
// RVA: 0xE6660
UFG::HavokNavPosition *__fastcall UFG::HavokNavPosition::operator=(UFG::HavokNavPosition *this, UFG::HavokNavPosition *other)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  bool v4; // al

  v2 = other->m_vPosition.y;
  v3 = other->m_vPosition.z;
  this->m_vPosition.x = other->m_vPosition.x;
  this->m_vPosition.y = v2;
  this->m_vPosition.z = v3;
  v4 = other->m_bValid;
  if ( v4 )
  {
    this->m_bValid = v4;
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
  unsigned int v1; // ebx
  unsigned int v2; // edi
  hkaiDynamicNavMeshQueryMediator *v3; // rax
  bool result; // al

  result = 0;
  if ( this->m_bValid )
  {
    v1 = this->m_packedKey;
    v2 = this->m_aiMeshUid;
    if ( v1 == -1
      || (v3 = (hkaiDynamicNavMeshQueryMediator *)hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr)) != 0i64
      && UFG::HavokAIUtilGame::IsFaceKeyValid(v3, v1, v2) )
    {
      result = 1;
    }
  }
  return result;
}

// File Line: 120
// RVA: 0xEF6F0
bool __fastcall UFG::HavokNavPosition::IsMeshPositionValid(UFG::HavokNavPosition *this)
{
  UFG::HavokNavPosition *v1; // rbx
  unsigned int v2; // edi
  unsigned int v3; // esi
  hkaiDynamicNavMeshQueryMediator *v4; // rax
  bool result; // al

  v1 = this;
  result = this->m_bValid
        && ((v2 = this->m_packedKey, v3 = this->m_aiMeshUid, v2 == -1)
         || (v4 = (hkaiDynamicNavMeshQueryMediator *)hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr)) != 0i64
         && UFG::HavokAIUtilGame::IsFaceKeyValid(v4, v2, v3))
        && v1->m_packedKey != -1
        && v1->m_aiMeshUid != -1;
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
  vMeshPosOut->x = this->m_hkvMeshPosition.m_quad.m128_f32[0];
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
  UFG::HavokNavPosition *v2; // rbx
  float v4; // [rsp+20h] [rbp-28h]
  float v5; // [rsp+24h] [rbp-24h]

  v2 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr->IsMeshPositionValid)() )
    return 0;
  v2->vfptr->GetMeshPosition((UFG::NavPositionBase *)&v2->vfptr, (UFG::qVector3 *)&v4);
  return (float)(fToleranceXY * fToleranceXY) > (float)((float)((float)(v2->m_vPosition.y - v5)
                                                              * (float)(v2->m_vPosition.y - v5))
                                                      + (float)((float)(v2->m_vPosition.x - v4)
                                                              * (float)(v2->m_vPosition.x - v4)));
}

