// File Line: 17
// RVA: 0x1543790
__int64 dynamic_initializer_for__UFG::TriadWarsComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::TriadWarsComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::TriadWarsComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::TriadWarsComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::TriadWarsComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 20
// RVA: 0x5470D0
UFG::TriadWarsComponent *__fastcall UFG::TriadWarsComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rbx
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x88ui64, "TriadWarsComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::TriadWarsComponent::TriadWarsComponent((UFG::TriadWarsComponent *)v4, pSceneObj->m_NameUID);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, pSceneObj->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return (UFG::TriadWarsComponent *)v6;
}

// File Line: 28
// RVA: 0x51A0A0
void __fastcall UFG::TriadWarsComponent::TriadWarsComponent(UFG::TriadWarsComponent *this, unsigned int uid)
{
  UFG::SimComponent::SimComponent(this, uid);
  this->mPrev = &this->UFG::qNode<UFG::TriadWarsComponent,UFG::TriadWarsComponent>;
  this->mNext = &this->UFG::qNode<UFG::TriadWarsComponent,UFG::TriadWarsComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TriadWarsComponent::`vftable;
  UFG::SimComponent::AddType(this, UFG::TriadWarsComponent::_TriadWarsComponentTypeUID, "TriadWarsComponent");
  this->mGangMemberStatData = 0i64;
  this->mMeleeWeaponStatData = 0i64;
  this->mRangedWeaponStatData = 0i64;
  this->mThrownWeaponStatData = 0i64;
  this->mOwnerPlayerId = -1;
  this->mFightingClass = eFIGHTING_CLASS_NONE;
  this->mMeleeWeapon = NUM_MELEE_WEAPONS;
  this->mRangedWeapon = NUM_RANGED_WEAPONS;
  this->mThrownWeapon = NUM_THROWN_WEAPONS;
}

// File Line: 50
// RVA: 0x52D9D0
UFG::GangMemberStatData2 *__fastcall UFG::TriadWarsComponent::GetGangMemberStatData2(UFG::TriadWarsComponent *this)
{
  LOCALNAMESPACE::hkNativeResource *v2; // rax
  UFG::GangMemberStatData2 *result; // rax

  v2 = (LOCALNAMESPACE::hkNativeResource *)UFG::GameDB::Instance();
  result = (UFG::GangMemberStatData2 *)Scaleform::GFx::FontManagerStates::GetStateBagImpl(v2);
  if ( result )
    return (UFG::GangMemberStatData2 *)((char *)result + 72 * this->mFightingClass + 664);
  return result;
}

// File Line: 59
// RVA: 0x52EAA0
UFG::MeleeWeaponStatData2 *__fastcall UFG::TriadWarsComponent::GetMeleeWeaponStatData2(UFG::TriadWarsComponent *this)
{
  LOCALNAMESPACE::hkNativeResource *v3; // rax
  const char *StateBagImpl; // rax

  if ( this->mMeleeWeapon < NUM_MELEE_WEAPONS
    && (v3 = (LOCALNAMESPACE::hkNativeResource *)UFG::GameDB::Instance(),
        (StateBagImpl = Scaleform::GFx::FontManagerStates::GetStateBagImpl(v3)) != 0i64) )
  {
    return (UFG::MeleeWeaponStatData2 *)&StateBagImpl[196 * (this->mFightingClass != eFIGHTING_CLASS_ENFORCER)
                                                    + 268
                                                    + 16 * this->mMeleeWeapon];
  }
  else
  {
    return 0i64;
  }
}

// File Line: 71
// RVA: 0x52F980
UFG::RangedWeaponStatData2 *__fastcall UFG::TriadWarsComponent::GetRangedWeaponStatData2(UFG::TriadWarsComponent *this)
{
  LOCALNAMESPACE::hkNativeResource *v3; // rax
  const char *StateBagImpl; // rax

  if ( this->mRangedWeapon < NUM_RANGED_WEAPONS
    && (v3 = (LOCALNAMESPACE::hkNativeResource *)UFG::GameDB::Instance(),
        (StateBagImpl = Scaleform::GFx::FontManagerStates::GetStateBagImpl(v3)) != 0i64) )
  {
    return (UFG::RangedWeaponStatData2 *)&StateBagImpl[196 * (this->mFightingClass != eFIGHTING_CLASS_ENFORCER)
                                                     + 332
                                                     + 12 * this->mRangedWeapon];
  }
  else
  {
    return 0i64;
  }
}

// File Line: 83
// RVA: 0x530AF0
UFG::ThrownWeaponStatData2 *__fastcall UFG::TriadWarsComponent::GetThrownWeaponStatData2(UFG::TriadWarsComponent *this)
{
  LOCALNAMESPACE::hkNativeResource *v3; // rax
  const char *StateBagImpl; // rax

  if ( this->mThrownWeapon < NUM_THROWN_WEAPONS
    && (v3 = (LOCALNAMESPACE::hkNativeResource *)UFG::GameDB::Instance(),
        (StateBagImpl = Scaleform::GFx::FontManagerStates::GetStateBagImpl(v3)) != 0i64) )
  {
    return (UFG::ThrownWeaponStatData2 *)&StateBagImpl[196 * (this->mFightingClass != eFIGHTING_CLASS_ENFORCER)
                                                     + 404
                                                     + 12 * this->mThrownWeapon];
  }
  else
  {
    return 0i64;
  }
}

// File Line: 96
// RVA: 0x53F1A0
void __fastcall UFG::TriadWarsComponent::OnAttach(UFG::TriadWarsComponent *this, UFG::SimObject *simObject)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  unsigned int m_TypeUID; // ecx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *i; // rdx
  unsigned int v10; // r8d
  unsigned int v11; // r9d

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_6;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[3].m_pComponent;
    if ( !m_pComponent )
      goto LABEL_6;
    m_TypeUID = m_pComponent->m_TypeUID;
    if ( ((m_TypeUID ^ UFG::SimObjectCharacterPropertiesComponent::_TypeUID) & 0xFE000000) != 0
      || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_6;
    }
  }
  else
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        for ( i = &m_pSimObject->m_Components.p[vfptr];
              (i->m_TypeUID & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
           || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~i->m_TypeUID & 0x1FFFFFF) != 0;
              ++i )
        {
          if ( ++vfptr >= size )
          {
            this->mFightingClass = MEMORY[0xC4];
            return;
          }
        }
LABEL_15:
        this->mFightingClass = HIDWORD(i->m_pComponent[3].vfptr);
        return;
      }
      goto LABEL_6;
    }
    if ( (m_Flags & 0x1000) != 0 )
    {
      v10 = (unsigned int)m_pSimObject[1].vfptr;
      v11 = m_pSimObject->m_Components.size;
      if ( v10 < v11 )
      {
        for ( i = &m_pSimObject->m_Components.p[v10];
              (i->m_TypeUID & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
           || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~i->m_TypeUID & 0x1FFFFFF) != 0;
              ++i )
        {
          if ( ++v10 >= v11 )
          {
            this->mFightingClass = MEMORY[0xC4];
            return;
          }
        }
        goto LABEL_15;
      }
LABEL_6:
      this->mFightingClass = MEMORY[0xC4];
      return;
    }
    m_pComponent = UFG::SimObject::GetComponentOfType(
                     m_pSimObject,
                     UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
  }
  this->mFightingClass = HIDWORD(m_pComponent[3].vfptr);
}

// File Line: 103
// RVA: 0x54DA30
void __fastcall UFG::TriadWarsComponent::SetOwnerPlayerId(UFG::TriadWarsComponent *this, unsigned int id)
{
  int mFightingClass; // r8d
  UFG::SimObjectWeaponPropertiesComponent *v5; // rdi
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  UFG::SimComponentHolder *p; // rbx
  UFG::SimObject *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rbx
  unsigned int v15; // r8d
  unsigned int v16; // r10d
  __int64 v17; // rdx
  UFG::SimObject *v18; // rcx
  UFG::SimComponent *v19; // rsi
  __int16 v20; // dx
  unsigned int v21; // r8d
  unsigned int v22; // r10d
  UFG::SimComponentHolder *v23; // rbx
  __int64 v24; // rdx
  unsigned int v25; // r8d
  unsigned int v26; // r10d
  UFG::SimObjectProp *v27; // r9
  __int16 v28; // dx
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int v30; // r10d
  unsigned int v31; // ebx
  __int64 v32; // rdx
  UFG::SimObjectWeaponPropertiesComponent *v33; // rax
  unsigned int v34; // r8d
  unsigned int v35; // r10d
  unsigned int v36; // r8d
  unsigned int v37; // r10d
  UFG::SimObjectProp *v38; // rcx
  __int16 v39; // dx
  unsigned int v40; // r8d
  unsigned int v41; // r10d
  __int64 v42; // rdx
  UFG::SimObjectWeaponPropertiesComponent *v43; // rax
  unsigned int v44; // r8d
  unsigned int v45; // r10d
  unsigned int v46; // r8d
  unsigned int v47; // r10d
  UFG::SimObjectWeaponPropertiesComponent *v48; // rdx
  UFG::SimObjectProp *v49; // rcx
  __int16 v50; // dx
  unsigned int v51; // r8d
  unsigned int v52; // r10d
  __int64 v53; // rdx
  unsigned int v54; // r8d
  unsigned int v55; // r10d
  unsigned int v56; // r8d
  unsigned int v57; // r10d
  UFG::SimObjectProp *v58; // rcx
  __int16 v59; // dx
  unsigned int v60; // r8d
  unsigned int v61; // r10d
  UFG::SimComponentHolder *v62; // r11
  __int64 v63; // rdx
  unsigned int v64; // r8d
  unsigned int v65; // r10d
  UFG::SimObjectWeaponPropertiesComponent *v66; // rax
  unsigned int v67; // r8d
  unsigned int v68; // r10d
  UFG::allocator::free_link *v69; // [rsp+50h] [rbp+18h]
  UFG::allocator::free_link *v70; // [rsp+50h] [rbp+18h]

  if ( id != -1 )
  {
    UFG::TriadWarsComponent::DetachAll(this);
    mFightingClass = this->mFightingClass;
    v5 = 0i64;
    if ( mFightingClass != 1 )
    {
      this->mGangMemberStatData = UFG::PlaceholderGameDB::GetGangMemberStatDataForPlayerId(
                                    UFG::PlaceholderGameDB::ms_pSingleton,
                                    id,
                                    mFightingClass);
      m_pSimObject = this->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
          }
          else if ( (m_Flags & 0x1000) != 0 )
          {
            vfptr = (unsigned int)m_pSimObject[1].vfptr;
            size = m_pSimObject->m_Components.size;
            if ( vfptr >= size )
            {
LABEL_18:
              m_pComponent = 0i64;
            }
            else
            {
              p = m_pSimObject->m_Components.p;
              while ( (p[vfptr].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                   || (UFG::UELComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) != 0 )
              {
                if ( ++vfptr >= size )
                  goto LABEL_18;
              }
              m_pComponent = p[vfptr].m_pComponent;
            }
          }
          else
          {
            m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
        }
        if ( m_pComponent )
        {
          v69 = UFG::qMalloc(0x68ui64, UFG::gGlobalNewName, 0i64);
          *(_QWORD *)&m_pComponent[3].m_TypeUID = v69;
          v69->mNext = (UFG::allocator::free_link *)&this->mGangMemberStatData->locoSpeed;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_TypeUID + 8i64) = &this->mGangMemberStatData->grappleDamage;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_TypeUID + 16i64) = &this->mGangMemberStatData->mitigateWorldCollision;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_TypeUID + 24i64) = &this->mGangMemberStatData->mitigateExplosive;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_TypeUID + 32i64) = &this->mGangMemberStatData->mitigateBallistic;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_TypeUID + 40i64) = &this->mGangMemberStatData->mitigateUnarmedMelee;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_TypeUID + 48i64) = &this->mGangMemberStatData->mitigateArmedMelee;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_TypeUID + 56i64) = &this->mGangMemberStatData->mitigateGrapple;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_TypeUID + 64i64) = &this->mGangMemberStatData->maxHP;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_TypeUID + 72i64) = &this->mGangMemberStatData->minHP;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_TypeUID + 80i64) = &this->mGangMemberStatData->hpBoost;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_TypeUID + 88i64) = &this->mGangMemberStatData->koChance;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_TypeUID + 96i64) = &this->mGangMemberStatData->critChance;
        }
      }
      this->mMeleeWeaponStatData = UFG::PlaceholderGameDB::GetMeleeWeaponStatDataForPlayerId(
                                     UFG::PlaceholderGameDB::ms_pSingleton,
                                     id,
                                     "Unarmed",
                                     this->mFightingClass == eFIGHTING_CLASS_ENFORCER);
      v12 = this->m_pSimObject;
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 & 0x4000) != 0 )
        {
          ComponentOfType = v12->m_Components.p->m_pComponent;
        }
        else if ( v13 >= 0 )
        {
          if ( (v13 & 0x2000) != 0 )
          {
            ComponentOfType = v12->m_Components.p->m_pComponent;
          }
          else if ( (v13 & 0x1000) != 0 )
          {
            v15 = (unsigned int)v12[1].vfptr;
            v16 = v12->m_Components.size;
            if ( v15 >= v16 )
            {
LABEL_36:
              ComponentOfType = 0i64;
            }
            else
            {
              while ( 1 )
              {
                v17 = (__int64)&v12->m_Components.p[v15];
                if ( (*(_DWORD *)(v17 + 8) & 0xFE000000) == (UFG::UELComponent::_TypeUID & 0xFE000000)
                  && (UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF) == 0 )
                {
                  break;
                }
                if ( ++v15 >= v16 )
                  goto LABEL_36;
              }
              ComponentOfType = *(UFG::SimComponent **)v17;
            }
          }
          else
          {
            ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          ComponentOfType = v12->m_Components.p->m_pComponent;
        }
        if ( ComponentOfType )
        {
          v70 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
          *(_QWORD *)&ComponentOfType[3].m_Flags = v70;
          v70->mNext = (UFG::allocator::free_link *)&this->mMeleeWeaponStatData->damage;
          *(_QWORD *)(*(_QWORD *)&ComponentOfType[3].m_Flags + 8i64) = &this->mMeleeWeaponStatData->attackSpeed;
          *(_QWORD *)(*(_QWORD *)&ComponentOfType[3].m_Flags + 16i64) = &this->mMeleeWeaponStatData->durability;
          *(_QWORD *)(*(_QWORD *)&ComponentOfType[3].m_Flags + 24i64) = &this->mMeleeWeaponStatData->critChance;
        }
      }
    }
    this->mOwnerPlayerId = id;
    v18 = this->m_pSimObject;
    if ( !v18 )
      goto LABEL_41;
    v20 = v18->m_Flags;
    if ( (v20 & 0x4000) != 0 )
    {
      v19 = v18->m_Components.p[20].m_pComponent;
      goto LABEL_62;
    }
    if ( v20 < 0 )
    {
      v19 = v18->m_Components.p[20].m_pComponent;
      goto LABEL_62;
    }
    if ( (v20 & 0x2000) != 0 )
    {
      v21 = (unsigned int)v18[1].vfptr;
      v22 = v18->m_Components.size;
      if ( v21 < v22 )
      {
        v23 = v18->m_Components.p;
        while ( 1 )
        {
          v24 = v21;
          if ( (v23[v21].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
            && (UFG::TargetingSystemBaseComponent::_TypeUID & ~v23[v21].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v21 >= v22 )
            goto LABEL_41;
        }
LABEL_53:
        v19 = v23[v24].m_pComponent;
        goto LABEL_62;
      }
    }
    else
    {
      if ( (v20 & 0x1000) == 0 )
      {
        v19 = UFG::SimObject::GetComponentOfType(v18, UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_62:
        v27 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v19[1].m_Flags + 26i64)
                                     + *(_QWORD *)&v19[1].m_TypeUID
                                     + 40);
        if ( !v27 )
        {
          v31 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
          goto LABEL_90;
        }
        v28 = v27->m_Flags;
        if ( (v28 & 0x4000) != 0 )
        {
          mComponentTableEntryCount = v27->mComponentTableEntryCount;
          v30 = v27->m_Components.size;
          v31 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
          if ( mComponentTableEntryCount < v30 )
          {
            while ( 1 )
            {
              v32 = (__int64)&v27->m_Components.p[mComponentTableEntryCount];
              if ( (*(_DWORD *)(v32 + 8) & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                && (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF) == 0 )
              {
                break;
              }
              if ( ++mComponentTableEntryCount >= v30 )
                goto LABEL_70;
            }
LABEL_69:
            v33 = *(UFG::SimObjectWeaponPropertiesComponent **)v32;
            goto LABEL_87;
          }
          goto LABEL_70;
        }
        if ( v28 < 0 )
        {
          v34 = v27->mComponentTableEntryCount;
          v35 = v27->m_Components.size;
          v31 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
          if ( v34 < v35 )
          {
            while ( 1 )
            {
              v32 = (__int64)&v27->m_Components.p[v34];
              if ( (*(_DWORD *)(v32 + 8) & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                && (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF) == 0 )
              {
                goto LABEL_69;
              }
              if ( ++v34 >= v35 )
                goto LABEL_70;
            }
          }
          goto LABEL_70;
        }
        if ( (v28 & 0x2000) != 0 )
        {
          v33 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v27);
        }
        else
        {
          if ( (v28 & 0x1000) != 0 )
          {
            v36 = v27->mComponentTableEntryCount;
            v37 = v27->m_Components.size;
            v31 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
            if ( v36 < v37 )
            {
              do
              {
                v32 = (__int64)&v27->m_Components.p[v36];
                if ( (*(_DWORD *)(v32 + 8) & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                  && (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_69;
                }
              }
              while ( ++v36 < v37 );
            }
LABEL_70:
            v33 = 0i64;
            goto LABEL_87;
          }
          v33 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             v27,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
        v31 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
LABEL_87:
        if ( v33 )
          goto LABEL_171;
LABEL_90:
        v38 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v19[1].m_Flags + 25i64)
                                     + *(_QWORD *)&v19[1].m_TypeUID
                                     + 40);
        if ( !v38 )
          goto LABEL_116;
        v39 = v38->m_Flags;
        if ( (v39 & 0x4000) != 0 )
        {
          v40 = v38->mComponentTableEntryCount;
          v41 = v38->m_Components.size;
          if ( v40 < v41 )
          {
            while ( 1 )
            {
              v42 = (__int64)&v38->m_Components.p[v40];
              if ( (*(_DWORD *)(v42 + 8) & 0xFE000000) == (v31 & 0xFE000000)
                && (v31 & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF) == 0 )
              {
                break;
              }
              if ( ++v40 >= v41 )
                goto LABEL_98;
            }
LABEL_97:
            v43 = *(UFG::SimObjectWeaponPropertiesComponent **)v42;
            goto LABEL_114;
          }
          goto LABEL_98;
        }
        if ( v39 < 0 )
        {
          v44 = v38->mComponentTableEntryCount;
          v45 = v38->m_Components.size;
          if ( v44 < v45 )
          {
            while ( 1 )
            {
              v42 = (__int64)&v38->m_Components.p[v44];
              if ( (*(_DWORD *)(v42 + 8) & 0xFE000000) == (v31 & 0xFE000000)
                && (v31 & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF) == 0 )
              {
                goto LABEL_97;
              }
              if ( ++v44 >= v45 )
                goto LABEL_98;
            }
          }
          goto LABEL_98;
        }
        if ( (v39 & 0x2000) != 0 )
        {
          v43 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v38);
        }
        else
        {
          if ( (v39 & 0x1000) != 0 )
          {
            v46 = v38->mComponentTableEntryCount;
            v47 = v38->m_Components.size;
            if ( v46 < v47 )
            {
              do
              {
                v42 = (__int64)&v38->m_Components.p[v46];
                if ( (*(_DWORD *)(v42 + 8) & 0xFE000000) == (v31 & 0xFE000000)
                  && (v31 & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_97;
                }
              }
              while ( ++v46 < v47 );
            }
LABEL_98:
            v43 = 0i64;
            goto LABEL_114;
          }
          v43 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(v38, v31);
          v31 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
        }
LABEL_114:
        if ( v43 )
        {
LABEL_115:
          v48 = v43;
LABEL_170:
          UFG::TriadWarsComponent::OnEquip(this, v48);
          goto LABEL_171;
        }
LABEL_116:
        v49 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v19[1].m_Flags + 50i64)
                                     + *(_QWORD *)&v19[1].m_TypeUID
                                     + 40);
        if ( !v49 )
          goto LABEL_141;
        v50 = v49->m_Flags;
        if ( (v50 & 0x4000) != 0 )
        {
          v51 = v49->mComponentTableEntryCount;
          v52 = v49->m_Components.size;
          if ( v51 < v52 )
          {
            while ( 1 )
            {
              v53 = (__int64)&v49->m_Components.p[v51];
              if ( (*(_DWORD *)(v53 + 8) & 0xFE000000) == (v31 & 0xFE000000)
                && (v31 & ~*(_DWORD *)(v53 + 8) & 0x1FFFFFF) == 0 )
              {
                break;
              }
              if ( ++v51 >= v52 )
                goto LABEL_124;
            }
LABEL_123:
            v43 = *(UFG::SimObjectWeaponPropertiesComponent **)v53;
            goto LABEL_140;
          }
          goto LABEL_124;
        }
        if ( v50 < 0 )
        {
          v54 = v49->mComponentTableEntryCount;
          v55 = v49->m_Components.size;
          if ( v54 < v55 )
          {
            while ( 1 )
            {
              v53 = (__int64)&v49->m_Components.p[v54];
              if ( (*(_DWORD *)(v53 + 8) & 0xFE000000) == (v31 & 0xFE000000)
                && (v31 & ~*(_DWORD *)(v53 + 8) & 0x1FFFFFF) == 0 )
              {
                goto LABEL_123;
              }
              if ( ++v54 >= v55 )
                goto LABEL_124;
            }
          }
          goto LABEL_124;
        }
        if ( (v50 & 0x2000) != 0 )
        {
          v43 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v49);
        }
        else
        {
          if ( (v50 & 0x1000) != 0 )
          {
            v56 = v49->mComponentTableEntryCount;
            v57 = v49->m_Components.size;
            if ( v56 < v57 )
            {
              do
              {
                v53 = (__int64)&v49->m_Components.p[v56];
                if ( (*(_DWORD *)(v53 + 8) & 0xFE000000) == (v31 & 0xFE000000)
                  && (v31 & ~*(_DWORD *)(v53 + 8) & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_123;
                }
              }
              while ( ++v56 < v57 );
            }
LABEL_124:
            v43 = 0i64;
            goto LABEL_140;
          }
          v43 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(v49, v31);
          v31 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
        }
LABEL_140:
        if ( v43 )
          goto LABEL_115;
LABEL_141:
        v58 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v19[1].m_Flags + 51i64)
                                     + *(_QWORD *)&v19[1].m_TypeUID
                                     + 40);
        if ( !v58 )
          goto LABEL_171;
        v59 = v58->m_Flags;
        if ( (v59 & 0x4000) != 0 )
        {
          v60 = v58->mComponentTableEntryCount;
          v61 = v58->m_Components.size;
          if ( v60 >= v61 )
            goto LABEL_168;
          v62 = v58->m_Components.p;
          while ( 1 )
          {
            v63 = v60;
            if ( (v62[v60].m_TypeUID & 0xFE000000) == (v31 & 0xFE000000) && (v31 & ~v62[v60].m_TypeUID & 0x1FFFFFF) == 0 )
              goto LABEL_149;
            if ( ++v60 >= v61 )
              goto LABEL_168;
          }
        }
        if ( v59 < 0 )
        {
          v64 = v58->mComponentTableEntryCount;
          v65 = v58->m_Components.size;
          if ( v64 < v65 )
          {
            v62 = v58->m_Components.p;
            while ( 1 )
            {
              v63 = v64;
              if ( (v62[v64].m_TypeUID & 0xFE000000) == (v31 & 0xFE000000)
                && (v31 & ~v62[v64].m_TypeUID & 0x1FFFFFF) == 0 )
              {
                break;
              }
              if ( ++v64 >= v65 )
                goto LABEL_168;
            }
LABEL_149:
            v5 = (UFG::SimObjectWeaponPropertiesComponent *)v62[v63].m_pComponent;
            goto LABEL_168;
          }
          goto LABEL_168;
        }
        if ( (v59 & 0x2000) != 0 )
        {
          v66 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v58);
        }
        else
        {
          if ( (v59 & 0x1000) != 0 )
          {
            v67 = v58->mComponentTableEntryCount;
            v68 = v58->m_Components.size;
            if ( v67 < v68 )
            {
              v62 = v58->m_Components.p;
              do
              {
                v63 = v67;
                if ( (v62[v67].m_TypeUID & 0xFE000000) == (v31 & 0xFE000000)
                  && (v31 & ~v62[v67].m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_149;
                }
              }
              while ( ++v67 < v68 );
            }
LABEL_168:
            if ( v5 )
            {
              v48 = v5;
              goto LABEL_170;
            }
LABEL_171:
            UFG::TriadWarsComponent::InitializeTunables(this);
            return;
          }
          v66 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(v58, v31);
        }
        v5 = v66;
        goto LABEL_168;
      }
      v25 = (unsigned int)v18[1].vfptr;
      v26 = v18->m_Components.size;
      if ( v25 < v26 )
      {
        v23 = v18->m_Components.p;
        do
        {
          v24 = v25;
          if ( (v23[v25].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
            && (UFG::TargetingSystemBaseComponent::_TypeUID & ~v23[v25].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_53;
          }
        }
        while ( ++v25 < v26 );
      }
    }
LABEL_41:
    v19 = 0i64;
    goto LABEL_62;
  }
}

// File Line: 176
// RVA: 0x5255D0
void __fastcall UFG::TriadWarsComponent::DetachAll(UFG::TriadWarsComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  unsigned int v7; // r9d
  __int64 v8; // rdx
  UFG::SimObject *v9; // rcx
  __int16 v10; // dx
  UFG::SimComponent *v11; // rbx
  unsigned int v12; // r8d
  unsigned int v13; // r10d
  __int64 v14; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *v16; // rcx
  __int16 v17; // dx
  UFG::SimComponent *v18; // rbx
  unsigned int v19; // r8d
  unsigned int v20; // r10d
  __int64 v21; // rdx
  UFG::SimComponent *v22; // rax
  UFG::SimObject *v23; // rcx
  __int16 v24; // dx
  UFG::SimComponent *v25; // rbx
  unsigned int v26; // r8d
  unsigned int v27; // r10d
  __int64 v28; // rdx

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_20;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    else
    {
      if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        v7 = UFG::UELComponent::_TypeUID;
        if ( vfptr >= size )
        {
LABEL_14:
          m_pComponent = 0i64;
        }
        else
        {
          v8 = (__int64)&m_pSimObject->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || (UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v8 += 16i64;
            if ( vfptr >= size )
              goto LABEL_14;
          }
          m_pComponent = *(UFG::SimComponent **)v8;
        }
        goto LABEL_18;
      }
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::UELComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
  }
  v7 = UFG::UELComponent::_TypeUID;
LABEL_18:
  if ( !m_pComponent )
    goto LABEL_21;
  operator delete[](*(void **)&m_pComponent[3].m_TypeUID);
  *(_QWORD *)&m_pComponent[3].m_TypeUID = 0i64;
LABEL_20:
  v7 = UFG::UELComponent::_TypeUID;
LABEL_21:
  v9 = this->m_pSimObject;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 & 0x4000) != 0 )
    {
      v11 = v9->m_Components.p->m_pComponent;
    }
    else if ( v10 >= 0 )
    {
      if ( (v10 & 0x2000) != 0 )
      {
        v11 = v9->m_Components.p->m_pComponent;
      }
      else if ( (v10 & 0x1000) != 0 )
      {
        v12 = (unsigned int)v9[1].vfptr;
        v13 = v9->m_Components.size;
        if ( v12 >= v13 )
        {
LABEL_34:
          v11 = 0i64;
        }
        else
        {
          v14 = (__int64)&v9->m_Components.p[v12];
          while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (v7 & 0xFE000000)
               || (v7 & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v12;
            v14 += 16i64;
            if ( v12 >= v13 )
              goto LABEL_34;
          }
          v11 = *(UFG::SimComponent **)v14;
        }
      }
      else
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(v9, v7);
        v7 = UFG::UELComponent::_TypeUID;
        v11 = ComponentOfType;
      }
    }
    else
    {
      v11 = v9->m_Components.p->m_pComponent;
    }
    if ( v11 )
    {
      operator delete[](v11[3].m_pSimObject);
      v11[3].m_pSimObject = 0i64;
      v7 = UFG::UELComponent::_TypeUID;
    }
  }
  v16 = this->m_pSimObject;
  if ( v16 )
  {
    v17 = v16->m_Flags;
    if ( (v17 & 0x4000) != 0 )
    {
      v18 = v16->m_Components.p->m_pComponent;
    }
    else if ( v17 >= 0 )
    {
      if ( (v17 & 0x2000) != 0 )
      {
        v18 = v16->m_Components.p->m_pComponent;
      }
      else if ( (v17 & 0x1000) != 0 )
      {
        v19 = (unsigned int)v16[1].vfptr;
        v20 = v16->m_Components.size;
        if ( v19 >= v20 )
        {
LABEL_52:
          v18 = 0i64;
        }
        else
        {
          v21 = (__int64)&v16->m_Components.p[v19];
          while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (v7 & 0xFE000000)
               || (v7 & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v19;
            v21 += 16i64;
            if ( v19 >= v20 )
              goto LABEL_52;
          }
          v18 = *(UFG::SimComponent **)v21;
        }
      }
      else
      {
        v22 = UFG::SimObject::GetComponentOfType(v16, v7);
        v7 = UFG::UELComponent::_TypeUID;
        v18 = v22;
      }
    }
    else
    {
      v18 = v16->m_Components.p->m_pComponent;
    }
    if ( v18 )
    {
      operator delete[](*(void **)&v18[3].m_Flags);
      *(_QWORD *)&v18[3].m_Flags = 0i64;
      v7 = UFG::UELComponent::_TypeUID;
    }
  }
  v23 = this->m_pSimObject;
  if ( v23 )
  {
    v24 = v23->m_Flags;
    if ( (v24 & 0x4000) != 0 )
    {
      v25 = v23->m_Components.p->m_pComponent;
    }
    else if ( v24 >= 0 )
    {
      if ( (v24 & 0x2000) != 0 )
      {
        v25 = v23->m_Components.p->m_pComponent;
      }
      else if ( (v24 & 0x1000) != 0 )
      {
        v26 = (unsigned int)v23[1].vfptr;
        v27 = v23->m_Components.size;
        if ( v26 >= v27 )
        {
LABEL_70:
          v25 = 0i64;
        }
        else
        {
          v28 = (__int64)&v23->m_Components.p[v26];
          while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (v7 & 0xFE000000)
               || (v7 & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v26;
            v28 += 16i64;
            if ( v26 >= v27 )
              goto LABEL_70;
          }
          v25 = *(UFG::SimComponent **)v28;
        }
      }
      else
      {
        v25 = UFG::SimObject::GetComponentOfType(v23, v7);
      }
    }
    else
    {
      v25 = v23->m_Components.p->m_pComponent;
    }
    if ( v25 )
    {
      operator delete[](v25[3].m_pSimObject);
      v25[3].m_pSimObject = 0i64;
    }
  }
}

// File Line: 213
// RVA: 0x541290
// attributes: thunk
void __fastcall UFG::TriadWarsComponent::OnDetach(UFG::TriadWarsComponent *this, UFG::SimObject *simObject)
{
  UFG::TriadWarsComponent::DetachAll(this);
}

// File Line: 218
// RVA: 0x5414E0
void __fastcall UFG::TriadWarsComponent::OnEquip(
        UFG::TriadWarsComponent *this,
        UFG::SimObjectWeaponPropertiesComponent *pSOWPC)
{
  unsigned int mOwnerPlayerId; // r10d
  UFG::FireModeInfo *v4; // rcx
  unsigned int v5; // eax
  const char *v6; // r8
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimObject *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *ComponentOfType; // rsi
  unsigned int v11; // r8d
  unsigned int v12; // r9d
  UFG::SimComponentHolder *v13; // rsi
  UFG::SimObject *v14; // rcx
  __int16 v15; // dx
  unsigned int v16; // r8d
  unsigned int v17; // r9d
  UFG::SimComponentHolder *v18; // rsi
  unsigned int mSimObjectWeaponType; // eax
  const char *v20; // r8
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  unsigned int vfptr; // edx
  unsigned int size; // r8d
  UFG::SimComponentHolder *p; // r11
  UFG::allocator::free_link *v26; // rax
  UFG::allocator::free_link *v27; // [rsp+40h] [rbp+8h]

  mOwnerPlayerId = this->mOwnerPlayerId;
  if ( mOwnerPlayerId != -1 )
  {
    v4 = pSOWPC->mWeaponTypeInfo->mFireModes[pSOWPC->mFireMode];
    if ( v4->mProjectileSpawnBoneName.mUID == UFG::gNullQSymbolUC.mUID )
    {
      mSimObjectWeaponType = v4->mSimObjectWeaponType;
      if ( v4->mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_KNIFE.m_EnumValue
        || mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_CLEAVER.m_EnumValue
        || mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_STRAIGHT_SWORD.m_EnumValue
        || mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SWORD.m_EnumValue )
      {
        v20 = "Bladed";
        this->mMeleeWeapon = eMELEE_WEAPON_BLADED;
      }
      else if ( mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_BATON.m_EnumValue )
      {
        v20 = "Blunt";
        this->mMeleeWeapon = eMELEE_WEAPON_BLUNT;
      }
      else
      {
        if ( mSimObjectWeaponType != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_BROOM_FULL.m_EnumValue
          && mSimObjectWeaponType != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_LONG.m_EnumValue
          && mSimObjectWeaponType != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_POLEARM.m_EnumValue )
        {
          return;
        }
        v20 = "TwoHanded";
        this->mMeleeWeapon = eMELEE_WEAPON_TWOHANDED;
      }
      this->mThrownWeapon = NUM_THROWN_WEAPONS;
      this->mRangedWeapon = NUM_RANGED_WEAPONS;
      this->mMeleeWeaponStatData = UFG::PlaceholderGameDB::GetMeleeWeaponStatDataForPlayerId(
                                     UFG::PlaceholderGameDB::ms_pSingleton,
                                     mOwnerPlayerId,
                                     v20,
                                     this->mFightingClass == eFIGHTING_CLASS_ENFORCER);
      m_pSimObject = this->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
          }
          else if ( (m_Flags & 0x1000) != 0 )
          {
            vfptr = (unsigned int)m_pSimObject[1].vfptr;
            size = m_pSimObject->m_Components.size;
            if ( vfptr >= size )
            {
LABEL_75:
              m_pComponent = 0i64;
            }
            else
            {
              p = m_pSimObject->m_Components.p;
              while ( (p[vfptr].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                   || (UFG::UELComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) != 0 )
              {
                if ( ++vfptr >= size )
                  goto LABEL_75;
              }
              m_pComponent = p[vfptr].m_pComponent;
            }
          }
          else
          {
            m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
        }
        if ( m_pComponent )
          goto LABEL_78;
      }
    }
    else
    {
      v5 = v4->mSimObjectWeaponType;
      if ( v4->mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_PISTOL.m_EnumValue )
      {
        v6 = "Pistol";
        this->mRangedWeapon = eRANGED_WEAPON_PISTOL;
      }
      else if ( v5 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_RIFLE.m_EnumValue )
      {
        v6 = "Rifle";
        this->mRangedWeapon = eRANGED_WEAPON_RIFLE;
      }
      else if ( v5 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SHOTGUN.m_EnumValue )
      {
        v6 = "Shotgun";
        this->mRangedWeapon = eRANGED_WEAPON_SHOTGUN;
      }
      else if ( v5 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SMG.m_EnumValue )
      {
        v6 = "SMG";
        this->mRangedWeapon = eRANGED_WEAPON_SMG;
      }
      else
      {
        v6 = "Exotic";
        this->mRangedWeapon = eRANGED_WEAPON_EXOTIC;
      }
      this->mThrownWeapon = NUM_THROWN_WEAPONS;
      m_pComponent = 0i64;
      this->mMeleeWeapon = eMELEE_WEAPON_UNARMED;
      this->mRangedWeaponStatData = UFG::PlaceholderGameDB::GetRangedWeaponStatDataForPlayerId(
                                      UFG::PlaceholderGameDB::ms_pSingleton,
                                      mOwnerPlayerId,
                                      v6,
                                      this->mFightingClass == eFIGHTING_CLASS_ENFORCER);
      v8 = this->m_pSimObject;
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 & 0x4000) != 0 )
        {
          ComponentOfType = v8->m_Components.p->m_pComponent;
        }
        else if ( v9 >= 0 )
        {
          if ( (v9 & 0x2000) != 0 )
          {
            ComponentOfType = v8->m_Components.p->m_pComponent;
          }
          else if ( (v9 & 0x1000) != 0 )
          {
            v11 = (unsigned int)v8[1].vfptr;
            v12 = v8->m_Components.size;
            if ( v11 >= v12 )
            {
LABEL_27:
              ComponentOfType = 0i64;
            }
            else
            {
              v13 = v8->m_Components.p;
              while ( (v13[v11].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                   || (UFG::UELComponent::_TypeUID & ~v13[v11].m_TypeUID & 0x1FFFFFF) != 0 )
              {
                if ( ++v11 >= v12 )
                  goto LABEL_27;
              }
              ComponentOfType = v13[v11].m_pComponent;
            }
          }
          else
          {
            ComponentOfType = UFG::SimObject::GetComponentOfType(v8, UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          ComponentOfType = v8->m_Components.p->m_pComponent;
        }
        if ( ComponentOfType )
        {
          v27 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
          ComponentOfType[3].m_pSimObject = (UFG::SimObject *)v27;
          v27->mNext = (UFG::allocator::free_link *)&this->mRangedWeaponStatData->reloadSpeed;
          ComponentOfType[3].m_pSimObject->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mRangedWeaponStatData->accuracy;
          ComponentOfType[3].m_pSimObject->m_SafePointerList.mNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mRangedWeaponStatData->aimRecover;
        }
      }
      this->mMeleeWeaponStatData = UFG::PlaceholderGameDB::GetMeleeWeaponStatDataForPlayerId(
                                     UFG::PlaceholderGameDB::ms_pSingleton,
                                     this->mOwnerPlayerId,
                                     "Unarmed",
                                     this->mFightingClass == eFIGHTING_CLASS_ENFORCER);
      v14 = this->m_pSimObject;
      if ( v14 )
      {
        v15 = v14->m_Flags;
        if ( (v15 & 0x4000) != 0 )
        {
          m_pComponent = v14->m_Components.p->m_pComponent;
        }
        else if ( v15 >= 0 )
        {
          if ( (v15 & 0x2000) != 0 )
          {
            m_pComponent = v14->m_Components.p->m_pComponent;
          }
          else if ( (v15 & 0x1000) != 0 )
          {
            v16 = (unsigned int)v14[1].vfptr;
            v17 = v14->m_Components.size;
            if ( v16 < v17 )
            {
              v18 = v14->m_Components.p;
              while ( (v18[v16].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                   || (UFG::UELComponent::_TypeUID & ~v18[v16].m_TypeUID & 0x1FFFFFF) != 0 )
              {
                if ( ++v16 >= v17 )
                  goto LABEL_47;
              }
              m_pComponent = v18[v16].m_pComponent;
            }
          }
          else
          {
            m_pComponent = UFG::SimObject::GetComponentOfType(v14, UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          m_pComponent = v14->m_Components.p->m_pComponent;
        }
LABEL_47:
        if ( m_pComponent )
        {
LABEL_78:
          v26 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
          *(_QWORD *)&m_pComponent[3].m_Flags = v26;
          v26->mNext = (UFG::allocator::free_link *)&this->mMeleeWeaponStatData->damage;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_Flags + 8i64) = &this->mMeleeWeaponStatData->attackSpeed;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_Flags + 16i64) = &this->mMeleeWeaponStatData->durability;
          *(_QWORD *)(*(_QWORD *)&m_pComponent[3].m_Flags + 24i64) = &this->mMeleeWeaponStatData->critChance;
        }
      }
    }
  }
}

// File Line: 395
// RVA: 0x541EC0
void __fastcall UFG::TriadWarsComponent::OnUnEquip(
        UFG::TriadWarsComponent *this,
        UFG::SimObjectWeaponPropertiesComponent *pSOWPC)
{
  UFG::FireModeInfo *v3; // r9
  UFG::SimObject *v4; // r8
  __int16 v5; // cx
  UFG::SimComponent *v6; // rdi
  unsigned int v7; // ecx
  unsigned int v8; // r9d
  UFG::SimComponentHolder *v9; // rdi
  unsigned int mSimObjectWeaponType; // eax
  UFG::SimObject *m_pSimObject; // r8
  UFG::SimComponent *ComponentOfType; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rdi
  unsigned int vfptr; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rdi
  UFG::SimObject *v18; // rcx
  __int16 v19; // dx
  unsigned int v20; // edx
  unsigned int v21; // r9d
  UFG::SimComponentHolder *v22; // rdi
  UFG::allocator::free_link *v23; // [rsp+40h] [rbp+8h]

  if ( this->mOwnerPlayerId != -1 )
  {
    v3 = pSOWPC->mWeaponTypeInfo->mFireModes[pSOWPC->mFireMode];
    if ( v3->mProjectileSpawnBoneName.mUID == UFG::gNullQSymbolUC.mUID )
    {
      mSimObjectWeaponType = v3->mSimObjectWeaponType;
      if ( v3->mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_KNIFE.m_EnumValue
        || mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_CLEAVER.m_EnumValue
        || mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_STRAIGHT_SWORD.m_EnumValue
        || mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SWORD.m_EnumValue
        || mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_BATON.m_EnumValue
        || mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_BROOM_FULL.m_EnumValue
        || mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_LONG.m_EnumValue
        || mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_POLEARM.m_EnumValue )
      {
        m_pSimObject = this->m_pSimObject;
        ComponentOfType = 0i64;
        if ( m_pSimObject )
        {
          m_Flags = m_pSimObject->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 )
            {
              m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
            }
            else if ( (m_Flags & 0x1000) != 0 )
            {
              vfptr = (unsigned int)m_pSimObject[1].vfptr;
              size = m_pSimObject->m_Components.size;
              if ( vfptr >= size )
              {
LABEL_46:
                m_pComponent = 0i64;
              }
              else
              {
                p = m_pSimObject->m_Components.p;
                while ( (p[vfptr].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                     || (UFG::UELComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) != 0 )
                {
                  if ( ++vfptr >= size )
                    goto LABEL_46;
                }
                m_pComponent = p[vfptr].m_pComponent;
              }
            }
            else
            {
              m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::UELComponent::_TypeUID);
            }
          }
          else
          {
            m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
          }
          if ( m_pComponent )
          {
            operator delete[](*(void **)&m_pComponent[3].m_Flags);
            *(_QWORD *)&m_pComponent[3].m_Flags = 0i64;
          }
        }
        this->mMeleeWeaponStatData = UFG::PlaceholderGameDB::GetMeleeWeaponStatDataForPlayerId(
                                       UFG::PlaceholderGameDB::ms_pSingleton,
                                       this->mOwnerPlayerId,
                                       "Unarmed",
                                       this->mFightingClass == eFIGHTING_CLASS_ENFORCER);
        v18 = this->m_pSimObject;
        if ( v18 )
        {
          v19 = v18->m_Flags;
          if ( (v19 & 0x4000) != 0 )
          {
            ComponentOfType = v18->m_Components.p->m_pComponent;
          }
          else if ( v19 >= 0 )
          {
            if ( (v19 & 0x2000) != 0 )
            {
              ComponentOfType = v18->m_Components.p->m_pComponent;
            }
            else if ( (v19 & 0x1000) != 0 )
            {
              v20 = (unsigned int)v18[1].vfptr;
              v21 = v18->m_Components.size;
              if ( v20 < v21 )
              {
                v22 = v18->m_Components.p;
                while ( (v22[v20].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                     || (UFG::UELComponent::_TypeUID & ~v22[v20].m_TypeUID & 0x1FFFFFF) != 0 )
                {
                  if ( ++v20 >= v21 )
                    goto LABEL_66;
                }
                ComponentOfType = v22[v20].m_pComponent;
              }
            }
            else
            {
              ComponentOfType = UFG::SimObject::GetComponentOfType(v18, UFG::UELComponent::_TypeUID);
            }
          }
          else
          {
            ComponentOfType = v18->m_Components.p->m_pComponent;
          }
LABEL_66:
          if ( ComponentOfType )
          {
            v23 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
            *(_QWORD *)&ComponentOfType[3].m_Flags = v23;
            v23->mNext = (UFG::allocator::free_link *)&this->mMeleeWeaponStatData->damage;
            *(_QWORD *)(*(_QWORD *)&ComponentOfType[3].m_Flags + 8i64) = &this->mMeleeWeaponStatData->attackSpeed;
            *(_QWORD *)(*(_QWORD *)&ComponentOfType[3].m_Flags + 16i64) = &this->mMeleeWeaponStatData->durability;
            *(_QWORD *)(*(_QWORD *)&ComponentOfType[3].m_Flags + 24i64) = &this->mMeleeWeaponStatData->critChance;
          }
        }
      }
    }
    else
    {
      v4 = this->m_pSimObject;
      if ( v4 )
      {
        v5 = v4->m_Flags;
        if ( (v5 & 0x4000) != 0 )
        {
          v6 = v4->m_Components.p->m_pComponent;
        }
        else if ( v5 >= 0 )
        {
          if ( (v5 & 0x2000) != 0 )
          {
            v6 = v4->m_Components.p->m_pComponent;
          }
          else if ( (v5 & 0x1000) != 0 )
          {
            v7 = (unsigned int)v4[1].vfptr;
            v8 = v4->m_Components.size;
            if ( v7 >= v8 )
            {
LABEL_18:
              v6 = 0i64;
            }
            else
            {
              v9 = v4->m_Components.p;
              while ( (v9[v7].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                   || (UFG::UELComponent::_TypeUID & ~v9[v7].m_TypeUID & 0x1FFFFFF) != 0 )
              {
                if ( ++v7 >= v8 )
                  goto LABEL_18;
              }
              v6 = v9[v7].m_pComponent;
            }
          }
          else
          {
            v6 = UFG::SimObject::GetComponentOfType(v4, UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          v6 = v4->m_Components.p->m_pComponent;
        }
        if ( v6 )
        {
          operator delete[](v6[3].m_pSimObject);
          v6[3].m_pSimObject = 0i64;
        }
      }
      this->mRangedWeaponStatData = 0i64;
    }
  }
}

// File Line: 524
// RVA: 0x539490
void __fastcall UFG::TriadWarsComponent::InitializeTunables(UFG::TriadWarsComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::HealthComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  unsigned int v5; // edx
  unsigned int v6; // r8d
  __int64 v7; // rbx
  unsigned int vfptr; // edx
  unsigned int size; // r8d

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_2;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    m_pComponent = (UFG::HealthComponent *)m_pSimObject->m_Components.p[6].m_pComponent;
    goto LABEL_22;
  }
  if ( (m_Flags & 0x2000) == 0 )
  {
    if ( (m_Flags & 0x1000) == 0 )
    {
      m_pComponent = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(
                                               m_pSimObject,
                                               UFG::HealthComponent::_TypeUID);
      goto LABEL_22;
    }
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr >= size )
      goto LABEL_2;
    v7 = (__int64)&m_pSimObject->m_Components.p[vfptr];
    while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
         || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
    {
      ++vfptr;
      v7 += 16i64;
      if ( vfptr >= size )
      {
        m_pComponent = 0i64;
        goto LABEL_22;
      }
    }
LABEL_13:
    m_pComponent = *(UFG::HealthComponent **)v7;
    goto LABEL_22;
  }
  v5 = (unsigned int)m_pSimObject[1].vfptr;
  v6 = m_pSimObject->m_Components.size;
  if ( v5 < v6 )
  {
    v7 = (__int64)&m_pSimObject->m_Components.p[v5];
    while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
         || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
    {
      ++v5;
      v7 += 16i64;
      if ( v5 >= v6 )
      {
        m_pComponent = 0i64;
        goto LABEL_22;
      }
    }
    goto LABEL_13;
  }
LABEL_2:
  m_pComponent = 0i64;
LABEL_22:
  UFG::HealthComponent::SetMaxHealth(m_pComponent, (int)this->mGangMemberStatData->maxHP);
  UFG::HealthComponent::SetHealth(m_pComponent, (int)this->mGangMemberStatData->maxHP, 0i64);
}

