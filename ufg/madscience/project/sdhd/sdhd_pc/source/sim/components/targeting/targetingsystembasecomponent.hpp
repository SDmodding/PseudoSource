// File Line: 58
// RVA: 0x51F860
UFG::ComponentIDDesc *__fastcall UFG::TargetingSystemBaseComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::TargetingSystemBaseComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::TargetingSystemBaseComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::TargetingSystemBaseComponent::_DescInit = 1;
    UFG::TargetingSystemBaseComponent::_TypeUID = UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildBitMask | (UFG::TargetingSystemBaseComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::TargetingSystemBaseComponent::_TargetingSystemBaseComponentTypeUID = UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildBitMask | (UFG::TargetingSystemBaseComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::TargetingSystemBaseComponent::_TypeIDesc;
}

// File Line: 109
// RVA: 0x54EE40
void __fastcall UFG::TargetingSystemBaseComponent::SetTargetLock(UFG::TargetingSystemBaseComponent *this, UFG::eTargetTypeEnum eTargetType, const bool bLock, const bool bDisableCollision)
{
  unsigned __int8 v4; // r9
  UFG::TargetingSimObject *v5; // rdx

  v4 = this->m_pTargetingMap->m_Map.p[eTargetType];
  if ( v4 )
  {
    v5 = &this->m_pTargets[v4];
    if ( (unsigned __int8)bLock ^ v5->m_bLock )
      v5->m_bLock = bLock;
  }
}

// File Line: 120
// RVA: 0x15DFB0
void __fastcall UFG::TargetingSystemBaseComponent::ClearTarget(UFG::TargetingSystemBaseComponent *this, UFG::eTargetTypeEnum eTargetType)
{
  UFG::TargetingSystemBaseComponent *v2; // rdi
  unsigned __int8 v3; // cl
  signed __int64 v4; // rbx

  v2 = this;
  v3 = this->m_pTargetingMap->m_Map.p[eTargetType];
  if ( v3 )
  {
    v4 = v3;
    UFG::TargetingSimObject::SetTarget(&v2->m_pTargets[v4], 0i64);
    UFG::TargetingSimObject::SetLock(&v2->m_pTargets[v4], 0);
  }
}

// File Line: 131
// RVA: 0x2E7E20
void __fastcall UFG::TargetingSystemBaseComponent::AssignTarget(UFG::TargetingSystemBaseComponent *this, UFG::eTargetTypeEnum eAssignTargetTo, UFG::SimObject *pSimObject)
{
  UFG::eTargetTypeEnum v3; // ebp
  UFG::TargetingSystemBaseComponent *v4; // rdi
  unsigned int v5; // ecx
  UFG::TargetingSimObject *v6; // rdx
  UFG::SimObject *v7; // rsi
  signed __int64 v8; // rbx

  v3 = eAssignTargetTo;
  v4 = this;
  v5 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[eAssignTargetTo];
  v6 = v4->m_pTargets;
  v7 = pSimObject;
  if ( v6[v5].m_pTarget.m_pPointer != pSimObject )
  {
    if ( (_BYTE)v5 )
    {
      v8 = v5;
      UFG::TargetingSimObject::SetTarget(&v6[v8], 0i64);
      UFG::TargetingSimObject::SetLock(&v4->m_pTargets[v8], 0);
    }
    UFG::TargetingSystemBaseComponent::SetTarget(v4, v3, v7);
  }
}

// File Line: 146
// RVA: 0x2E7D90
void __fastcall UFG::TargetingSystemBaseComponent::AssignTarget(UFG::TargetingSystemBaseComponent *this, UFG::eTargetTypeEnum eAssignTargetTo, UFG::eTargetTypeEnum eAssignTargetFrom)
{
  UFG::TargetingMap *v3; // r9
  __int64 v4; // rsi
  UFG::TargetingSimObject *v5; // rdx
  UFG::TargetingSystemBaseComponent *v6; // rdi
  UFG::SimObject *v7; // rbp
  signed __int64 v8; // rbx

  v3 = this->m_pTargetingMap;
  v4 = (unsigned int)eAssignTargetTo;
  v5 = this->m_pTargets;
  v6 = this;
  v7 = v5[(unsigned __int8)v3->m_Map.p[eAssignTargetFrom]].m_pTarget.m_pPointer;
  if ( v5[(unsigned __int8)v3->m_Map.p[v4]].m_pTarget.m_pPointer != v7 )
  {
    if ( v3->m_Map.p[v4] )
    {
      v8 = (unsigned __int8)v3->m_Map.p[v4];
      UFG::TargetingSimObject::SetTarget(&v5[v8], 0i64);
      UFG::TargetingSimObject::SetLock(&v6->m_pTargets[v8], 0);
    }
    UFG::TargetingSystemBaseComponent::SetTarget(v6, (UFG::eTargetTypeEnum)v4, v7);
  }
}

