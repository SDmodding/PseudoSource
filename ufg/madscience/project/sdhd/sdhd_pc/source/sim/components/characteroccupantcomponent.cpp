// File Line: 16
// RVA: 0x532760
signed __int64 __fastcall UFG::AIMarker::GetTypeSize(UFG::qReflectInventory<UFG::ConstraintDefBallAndSocket> *this)
{
  return 136i64;
}

// File Line: 27
// RVA: 0x5163E0
void __fastcall UFG::CharacterOccupantComponent::CharacterOccupantComponent(UFG::CharacterOccupantComponent *this, unsigned int name_uid, UFG::eTargetTypeEnum eTargetType)
{
  UFG::eTargetTypeEnum v3; // ebx
  UFG::CharacterOccupantComponent *v4; // rdi
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v5; // rax

  v3 = eTargetType;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterOccupantComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::VehicleOccupantComponent,0>::RebindingComponentHandle<UFG::VehicleOccupantComponent,0>(&v4->mCurrentVOC);
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::CharacterOccupantComponent::_CharacterOccupantComponentTypeUID,
    "CharacterOccupantComponent");
  v4->mSeatIndex = 0;
  v4->mTargetType = v3;
}

// File Line: 35
// RVA: 0x51B0B0
void __fastcall UFG::CharacterOccupantComponent::~CharacterOccupantComponent(UFG::CharacterOccupantComponent *this)
{
  UFG::CharacterOccupantComponent *v1; // rdi
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v2; // rbx
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v3; // rdx
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v4; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v5; // rcx
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterOccupantComponent::`vftable;
  v2 = (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = this->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mCurrentVOC);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 48
// RVA: 0x52C7A0
UFG::VehicleOccupantComponent *__fastcall UFG::CharacterOccupantComponent::GetCurrentVehicle(UFG::CharacterOccupantComponent *this)
{
  UFG::VehicleOccupantComponent *result; // rax

  result = (UFG::VehicleOccupantComponent *)this->mCurrentVOC.m_pSimComponent;
  if ( result )
    result = (UFG::VehicleOccupantComponent *)result->m_pSimObject;
  return result;
}

// File Line: 53
// RVA: 0x54F4A0
void __fastcall UFG::CharacterOccupantComponent::SetVehicleOccupantComponent(UFG::CharacterOccupantComponent *this, UFG::VehicleOccupantComponent *pVOC, unsigned int seatIndex)
{
  UFG::CharacterOccupantComponent *v3; // rbx
  unsigned int v4; // edi

  v3 = this;
  v4 = seatIndex;
  UFG::RebindingComponentHandle<UFG::VehicleOccupantComponent,0>::Set(&this->mCurrentVOC, pVOC);
  v3->mSeatIndex = v4;
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
char __fastcall UFG::CharacterOccupantComponent::IsEnteringOrExiting(UFG::CharacterOccupantComponent *this)
{
  UFG::SimObject *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::CharacterPhysicsComponent *v3; // rax
  unsigned int v4; // er8
  unsigned int v5; // er9
  signed __int64 v6; // rdx
  unsigned int v7; // er8
  unsigned int v8; // er9
  unsigned int v9; // er8
  unsigned int v10; // er9

  v1 = this->m_pSimObject;
  if ( !v1 )
    return 0;
  v2 = v1->m_Flags;
  if ( !((v2 >> 14) & 1) )
  {
    if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v7 = (unsigned int)v1[1].vfptr;
        v8 = v1->m_Components.size;
        if ( v7 < v8 )
        {
          v6 = (signed __int64)&v1->m_Components.p[v7];
          while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
          {
            ++v7;
            v6 += 16i64;
            if ( v7 >= v8 )
              goto LABEL_10;
          }
          goto LABEL_11;
        }
      }
      else
      {
        if ( !((v2 >> 12) & 1) )
        {
          v3 = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                   v1,
                                                   UFG::CharacterPhysicsComponent::_TypeUID);
          goto LABEL_27;
        }
        v9 = (unsigned int)v1[1].vfptr;
        v10 = v1->m_Components.size;
        if ( v9 < v10 )
        {
          v6 = (signed __int64)&v1->m_Components.p[v9];
          while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
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
      v4 = (unsigned int)v1[1].vfptr;
      v5 = v1->m_Components.size;
      if ( v4 < v5 )
      {
        v6 = (signed __int64)&v1->m_Components.p[v4];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
             || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
        {
          ++v4;
          v6 += 16i64;
          if ( v4 >= v5 )
            goto LABEL_10;
        }
LABEL_11:
        v3 = *(UFG::CharacterPhysicsComponent **)v6;
        goto LABEL_27;
      }
    }
LABEL_10:
    v3 = 0i64;
    goto LABEL_27;
  }
  v3 = (UFG::CharacterPhysicsComponent *)v1->m_Components.p[27].m_pComponent;
LABEL_27:
  if ( v3 && v3->mDesiredCollisionModelType == CP_ENTER_EXIT_VEHICLE )
    return 1;
  return 0;
}

