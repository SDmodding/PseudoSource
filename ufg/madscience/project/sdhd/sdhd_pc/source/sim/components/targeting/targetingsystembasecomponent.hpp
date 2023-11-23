// File Line: 58
// RVA: 0x51F860
UFG::ComponentIDDesc *__fastcall UFG::TargetingSystemBaseComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::TargetingSystemBaseComponent::_DescInit )
  {
    UFG::TargetingSystemBaseComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::TargetingSystemBaseComponent::_DescInit = 1;
    UFG::TargetingSystemBaseComponent::_TypeUID = UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildBitMask | (UFG::TargetingSystemBaseComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::TargetingSystemBaseComponent::_TargetingSystemBaseComponentTypeUID = UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildBitMask | (UFG::TargetingSystemBaseComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::TargetingSystemBaseComponent::_TypeIDesc;
}

// File Line: 109
// RVA: 0x54EE40
void __fastcall UFG::TargetingSystemBaseComponent::SetTargetLock(
        UFG::TargetingSystemBaseComponent *this,
        UFG::eTargetTypeEnum eTargetType,
        bool bLock,
        const bool bDisableCollision)
{
  unsigned __int8 v4; // r9
  UFG::TargetingSimObject *v5; // rdx

  v4 = this->m_pTargetingMap->m_Map.p[eTargetType];
  if ( v4 )
  {
    v5 = &this->m_pTargets[v4];
    if ( bLock != v5->m_bLock )
      v5->m_bLock = bLock;
  }
}

// File Line: 120
// RVA: 0x15DFB0
void __fastcall UFG::TargetingSystemBaseComponent::ClearTarget(
        UFG::TargetingSystemBaseComponent *this,
        UFG::eTargetTypeEnum eTargetType)
{
  unsigned __int8 v3; // cl
  __int64 v4; // rbx

  v3 = this->m_pTargetingMap->m_Map.p[eTargetType];
  if ( v3 )
  {
    v4 = v3;
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v4], 0i64);
    UFG::TargetingSimObject::SetLock(&this->m_pTargets[v4], 0);
  }
}

// File Line: 131
// RVA: 0x2E7E20
void __fastcall UFG::TargetingSystemBaseComponent::AssignTarget(
        UFG::TargetingSystemBaseComponent *this,
        UFG::eTargetTypeEnum eAssignTargetTo,
        UFG::SimObject *pSimObject)
{
  unsigned int v5; // ecx
  UFG::TargetingSimObject *m_pTargets; // rdx
  __int64 v8; // rbx

  v5 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[eAssignTargetTo];
  m_pTargets = this->m_pTargets;
  if ( m_pTargets[v5].m_pTarget.m_pPointer != pSimObject )
  {
    if ( (_BYTE)v5 )
    {
      v8 = v5;
      UFG::TargetingSimObject::SetTarget(&m_pTargets[v8], 0i64);
      UFG::TargetingSimObject::SetLock(&this->m_pTargets[v8], 0);
    }
    UFG::TargetingSystemBaseComponent::SetTarget(this, eAssignTargetTo, pSimObject);
  }
}

// File Line: 146
// RVA: 0x2E7D90
void __fastcall UFG::TargetingSystemBaseComponent::AssignTarget(
        UFG::TargetingSystemBaseComponent *this,
        unsigned int eAssignTargetTo,
        unsigned int eAssignTargetFrom)
{
  UFG::TargetingMap *m_pTargetingMap; // r9
  __int64 v4; // rsi
  UFG::TargetingSimObject *m_pTargets; // rdx
  UFG::SimObject *m_pPointer; // rbp
  __int64 v8; // rbx

  m_pTargetingMap = this->m_pTargetingMap;
  v4 = eAssignTargetTo;
  m_pTargets = this->m_pTargets;
  m_pPointer = m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[eAssignTargetFrom]].m_pTarget.m_pPointer;
  if ( m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[v4]].m_pTarget.m_pPointer != m_pPointer )
  {
    if ( m_pTargetingMap->m_Map.p[v4] )
    {
      v8 = (unsigned __int8)m_pTargetingMap->m_Map.p[v4];
      UFG::TargetingSimObject::SetTarget(&m_pTargets[v8], 0i64);
      UFG::TargetingSimObject::SetLock(&this->m_pTargets[v8], 0);
    }
    UFG::TargetingSystemBaseComponent::SetTarget(this, (UFG::eTargetTypeEnum)v4, m_pPointer);
  }
}

