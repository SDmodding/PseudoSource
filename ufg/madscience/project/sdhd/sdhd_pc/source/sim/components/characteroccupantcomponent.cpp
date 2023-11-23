// File Line: 16
// RVA: 0x532760
__int64 __fastcall UFG::AIMarker::GetTypeSize(UFG::qReflectInventory<UFG::ConstraintDefBallAndSocket> *this)
{
  return 136i64;
}

// File Line: 27
// RVA: 0x5163E0
void __fastcall UFG::CharacterOccupantComponent::CharacterOccupantComponent(
        UFG::CharacterOccupantComponent *this,
        unsigned int name_uid,
        UFG::eTargetTypeEnum eTargetType)
{
  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList>;
  this->mNext = &this->UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterOccupantComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::VehicleOccupantComponent,0>::RebindingComponentHandle<UFG::VehicleOccupantComponent,0>(&this->mCurrentVOC);
  UFG::SimComponent::AddType(
    this,
    UFG::CharacterOccupantComponent::_CharacterOccupantComponentTypeUID,
    "CharacterOccupantComponent");
  this->mSeatIndex = 0;
  this->mTargetType = eTargetType;
}

// File Line: 35
// RVA: 0x51B0B0
void __fastcall UFG::CharacterOccupantComponent::~CharacterOccupantComponent(UFG::CharacterOccupantComponent *this)
{
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v2; // rbx
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *mPrev; // rdx
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *mNext; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v5; // rcx
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterOccupantComponent::`vftable;
  v2 = &this->UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList>;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList>;
  this->mNext = &this->UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList>;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mCurrentVOC);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 48
// RVA: 0x52C7A0
UFG::VehicleOccupantComponent *__fastcall UFG::CharacterOccupantComponent::GetCurrentVehicle(
        UFG::CharacterOccupantComponent *this)
{
  UFG::VehicleOccupantComponent *result; // rax

  result = (UFG::VehicleOccupantComponent *)this->mCurrentVOC.m_pSimComponent;
  if ( result )
    return (UFG::VehicleOccupantComponent *)result->m_pSimObject;
  return result;
}

// File Line: 53
// RVA: 0x54F4A0
void __fastcall UFG::CharacterOccupantComponent::SetVehicleOccupantComponent(
        UFG::CharacterOccupantComponent *this,
        UFG::VehicleOccupantComponent *pVOC,
        unsigned int seatIndex)
{
  UFG::RebindingComponentHandle<UFG::VehicleOccupantComponent,0>::Set(&this->mCurrentVOC, pVOC);
  this->mSeatIndex = seatIndex;
}

// File Line: 59
// RVA: 0x53FF20
void __fastcall UFG::CharacterOccupantComponent::OnDetach(UFG::CharacterOccupantComponent *this)
{
  if ( this->mCurrentVOC.m_pSimComponent )
    UFG::VehicleOccupantComponent::RemoveOccupant(
      (UFG::VehicleOccupantComponent *)this->mCurrentVOC.m_pSimComponent,
      this);
}

// File Line: 71
// RVA: 0x53A380
bool __fastcall UFG::CharacterOccupantComponent::IsEnteringOrExiting(UFG::CharacterOccupantComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterPhysicsComponent *ComponentOfType; // rax
  unsigned int v4; // r8d
  unsigned int v5; // r9d
  __int64 v6; // rdx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  unsigned int v9; // r8d
  unsigned int v10; // r9d

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr < size )
        {
          v6 = (__int64)&m_pSimObject->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v6 += 16i64;
            if ( vfptr >= size )
              goto LABEL_10;
          }
          goto LABEL_11;
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          ComponentOfType = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pSimObject,
                                                                UFG::CharacterPhysicsComponent::_TypeUID);
          return ComponentOfType && ComponentOfType->mDesiredCollisionModelType == CP_ENTER_EXIT_VEHICLE;
        }
        v9 = (unsigned int)m_pSimObject[1].vfptr;
        v10 = m_pSimObject->m_Components.size;
        if ( v9 < v10 )
        {
          v6 = (__int64)&m_pSimObject->m_Components.p[v9];
          while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v9;
            v6 += 16i64;
            if ( v9 >= v10 )
              goto LABEL_10;
          }
          goto LABEL_11;
        }
      }
    }
    else
    {
      v4 = (unsigned int)m_pSimObject[1].vfptr;
      v5 = m_pSimObject->m_Components.size;
      if ( v4 < v5 )
      {
        v6 = (__int64)&m_pSimObject->m_Components.p[v4];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
             || (UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v4;
          v6 += 16i64;
          if ( v4 >= v5 )
            goto LABEL_10;
        }
LABEL_11:
        ComponentOfType = *(UFG::CharacterPhysicsComponent **)v6;
        return ComponentOfType && ComponentOfType->mDesiredCollisionModelType == CP_ENTER_EXIT_VEHICLE;
      }
    }
LABEL_10:
    ComponentOfType = 0i64;
    return ComponentOfType && ComponentOfType->mDesiredCollisionModelType == CP_ENTER_EXIT_VEHICLE;
  }
  ComponentOfType = (UFG::CharacterPhysicsComponent *)m_pSimObject->m_Components.p[27].m_pComponent;
  return ComponentOfType && ComponentOfType->mDesiredCollisionModelType == CP_ENTER_EXIT_VEHICLE;
}

