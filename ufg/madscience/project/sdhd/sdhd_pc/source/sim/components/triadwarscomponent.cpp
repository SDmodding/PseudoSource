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
UFG::SimComponent *__fastcall UFG::TriadWarsComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rdi
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rbx
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0x88ui64, "TriadWarsComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::TriadWarsComponent::TriadWarsComponent((UFG::TriadWarsComponent *)v4, v2->m_NameUID);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, v2->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return v6;
}

// File Line: 28
// RVA: 0x51A0A0
void __fastcall UFG::TriadWarsComponent::TriadWarsComponent(UFG::TriadWarsComponent *this, unsigned int uid)
{
  UFG::TriadWarsComponent *v2; // rbx
  UFG::qNode<UFG::TriadWarsComponent,UFG::TriadWarsComponent> *v3; // rax

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, uid);
  v3 = (UFG::qNode<UFG::TriadWarsComponent,UFG::TriadWarsComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TriadWarsComponent::`vftable;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::TriadWarsComponent::_TriadWarsComponentTypeUID,
    "TriadWarsComponent");
  v2->mGangMemberStatData = 0i64;
  v2->mMeleeWeaponStatData = 0i64;
  v2->mRangedWeaponStatData = 0i64;
  v2->mThrownWeaponStatData = 0i64;
  v2->mOwnerPlayerId = -1;
  v2->mFightingClass = 1;
  v2->mMeleeWeapon = 4;
  v2->mRangedWeapon = 6;
  v2->mThrownWeapon = 5;
}

// File Line: 50
// RVA: 0x52D9D0
UFG::GangMemberStatData2 *__fastcall UFG::TriadWarsComponent::GetGangMemberStatData2(UFG::TriadWarsComponent *this)
{
  UFG::TriadWarsComponent *v1; // rbx
  LOCALNAMESPACE::hkNativeResource *v2; // rax
  UFG::GangMemberStatData2 *result; // rax

  v1 = this;
  v2 = (LOCALNAMESPACE::hkNativeResource *)UFG::GameDB::Instance();
  result = (UFG::GangMemberStatData2 *)Scaleform::GFx::FontManagerStates::GetStateBagImpl(v2);
  if ( result )
    result = (UFG::GangMemberStatData2 *)((char *)result + 8 * (9i64 * (signed int)v1->mFightingClass + 83));
  return result;
}

// File Line: 59
// RVA: 0x52EAA0
UFG::MeleeWeaponStatData2 *__fastcall UFG::TriadWarsComponent::GetMeleeWeaponStatData2(UFG::TriadWarsComponent *this)
{
  UFG::TriadWarsComponent *v1; // rbx
  UFG::MeleeWeaponStatData2 *result; // rax
  LOCALNAMESPACE::hkNativeResource *v3; // rax
  const char *v4; // rax

  v1 = this;
  if ( this->mMeleeWeapon < 4
    && (v3 = (LOCALNAMESPACE::hkNativeResource *)UFG::GameDB::Instance(),
        (v4 = Scaleform::GFx::FontManagerStates::GetStateBagImpl(v3)) != 0i64) )
  {
    result = (UFG::MeleeWeaponStatData2 *)&v4[196 * (v1->mFightingClass != 8) + 268 + 16 * v1->mMeleeWeapon];
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 71
// RVA: 0x52F980
UFG::RangedWeaponStatData2 *__fastcall UFG::TriadWarsComponent::GetRangedWeaponStatData2(UFG::TriadWarsComponent *this)
{
  UFG::TriadWarsComponent *v1; // rbx
  UFG::RangedWeaponStatData2 *result; // rax
  LOCALNAMESPACE::hkNativeResource *v3; // rax
  const char *v4; // rax

  v1 = this;
  if ( this->mRangedWeapon < 6
    && (v3 = (LOCALNAMESPACE::hkNativeResource *)UFG::GameDB::Instance(),
        (v4 = Scaleform::GFx::FontManagerStates::GetStateBagImpl(v3)) != 0i64) )
  {
    result = (UFG::RangedWeaponStatData2 *)&v4[196 * (v1->mFightingClass != 8) + 332 + 12 * v1->mRangedWeapon];
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 83
// RVA: 0x530AF0
UFG::ThrownWeaponStatData2 *__fastcall UFG::TriadWarsComponent::GetThrownWeaponStatData2(UFG::TriadWarsComponent *this)
{
  UFG::TriadWarsComponent *v1; // rbx
  UFG::ThrownWeaponStatData2 *result; // rax
  LOCALNAMESPACE::hkNativeResource *v3; // rax
  const char *v4; // rax

  v1 = this;
  if ( this->mThrownWeapon < 5
    && (v3 = (LOCALNAMESPACE::hkNativeResource *)UFG::GameDB::Instance(),
        (v4 = Scaleform::GFx::FontManagerStates::GetStateBagImpl(v3)) != 0i64) )
  {
    result = (UFG::ThrownWeaponStatData2 *)&v4[196 * (v1->mFightingClass != 8) + 404 + 12 * v1->mThrownWeapon];
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 96
// RVA: 0x53F1A0
void __fastcall UFG::TriadWarsComponent::OnAttach(UFG::TriadWarsComponent *this, UFG::SimObject *simObject)
{
  UFG::TriadWarsComponent *v2; // rbx
  UFG::SimObject *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  unsigned int v6; // ecx
  unsigned int v7; // er8
  unsigned int v8; // er9
  UFG::SimComponentHolder *v9; // rdx
  unsigned int v10; // er8
  unsigned int v11; // er9

  v2 = this;
  v3 = this->m_pSimObject;
  if ( !v3 )
    goto LABEL_6;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 || (v4 & 0x8000u) != 0 )
  {
    v5 = v3->m_Components.p[3].m_pComponent;
    if ( !v5 )
      goto LABEL_6;
    v6 = v5->m_TypeUID;
    if ( (v6 ^ UFG::SimObjectCharacterPropertiesComponent::_TypeUID) & 0xFE000000
      || UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v6 & 0x1FFFFFF )
    {
      goto LABEL_6;
    }
  }
  else
  {
    if ( (v4 >> 13) & 1 )
    {
      v7 = (unsigned int)v3[1].vfptr;
      v8 = v3->m_Components.size;
      if ( v7 < v8 )
      {
        v9 = &v3->m_Components.p[v7];
        while ( (v9->m_TypeUID & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v9->m_TypeUID & 0x1FFFFFF )
        {
          ++v7;
          ++v9;
          if ( v7 >= v8 )
          {
            v2->mFightingClass = MEMORY[0xC4];
            return;
          }
        }
LABEL_15:
        v2->mFightingClass = HIDWORD(v9->m_pComponent[3].vfptr);
        return;
      }
      goto LABEL_6;
    }
    if ( (v4 >> 12) & 1 )
    {
      v10 = (unsigned int)v3[1].vfptr;
      v11 = v3->m_Components.size;
      if ( v10 < v11 )
      {
        v9 = &v3->m_Components.p[v10];
        while ( (v9->m_TypeUID & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v9->m_TypeUID & 0x1FFFFFF )
        {
          ++v10;
          ++v9;
          if ( v10 >= v11 )
          {
            v2->mFightingClass = MEMORY[0xC4];
            return;
          }
        }
        goto LABEL_15;
      }
LABEL_6:
      v2->mFightingClass = MEMORY[0xC4];
      return;
    }
    v5 = UFG::SimObject::GetComponentOfType(v3, UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
  }
  v2->mFightingClass = HIDWORD(v5[3].vfptr);
}

// File Line: 103
// RVA: 0x54DA30
void __fastcall UFG::TriadWarsComponent::SetOwnerPlayerId(UFG::TriadWarsComponent *this, unsigned int id)
{
  unsigned int v2; // esi
  UFG::TriadWarsComponent *v3; // rbp
  UFG::eFightingClassEnum v4; // er8
  UFG::SimObjectWeaponPropertiesComponent *v5; // rdi
  UFG::SimObject *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rbx
  unsigned int v9; // er8
  unsigned int v10; // er10
  UFG::SimComponentHolder *v11; // rbx
  UFG::SimObject *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rbx
  unsigned int v15; // er8
  unsigned int v16; // er10
  signed __int64 v17; // rdx
  UFG::SimObject *v18; // rcx
  UFG::SimComponent *v19; // rsi
  unsigned __int16 v20; // dx
  unsigned int v21; // er8
  unsigned int v22; // er10
  UFG::SimComponentHolder *v23; // rbx
  signed __int64 v24; // rdx
  unsigned int v25; // er8
  unsigned int v26; // er10
  UFG::SimObjectProp *v27; // r9
  unsigned __int16 v28; // dx
  unsigned int v29; // er8
  unsigned int v30; // er10
  unsigned int v31; // ebx
  signed __int64 v32; // rdx
  UFG::SimObjectWeaponPropertiesComponent *v33; // rax
  unsigned int v34; // er8
  unsigned int v35; // er10
  unsigned int v36; // er8
  unsigned int v37; // er10
  UFG::SimObjectProp *v38; // rcx
  unsigned __int16 v39; // dx
  unsigned int v40; // er8
  unsigned int v41; // er10
  signed __int64 v42; // rdx
  UFG::SimObjectWeaponPropertiesComponent *v43; // rax
  unsigned int v44; // er8
  unsigned int v45; // er10
  unsigned int v46; // er8
  unsigned int v47; // er10
  UFG::SimObjectWeaponPropertiesComponent *v48; // rdx
  UFG::SimObjectProp *v49; // rcx
  unsigned __int16 v50; // dx
  unsigned int v51; // er8
  unsigned int v52; // er10
  signed __int64 v53; // rdx
  unsigned int v54; // er8
  unsigned int v55; // er10
  unsigned int v56; // er8
  unsigned int v57; // er10
  UFG::SimObjectProp *v58; // rcx
  unsigned __int16 v59; // dx
  unsigned int v60; // er8
  unsigned int v61; // er10
  UFG::SimComponentHolder *v62; // r11
  signed __int64 v63; // rdx
  unsigned int v64; // er8
  unsigned int v65; // er10
  UFG::SimObjectWeaponPropertiesComponent *v66; // rax
  unsigned int v67; // er8
  unsigned int v68; // er10
  UFG::allocator::free_link *v69; // [rsp+50h] [rbp+18h]
  UFG::allocator::free_link *v70; // [rsp+50h] [rbp+18h]

  if ( id != -1 )
  {
    v2 = id;
    v3 = this;
    UFG::TriadWarsComponent::DetachAll(this);
    v4 = v3->mFightingClass;
    v5 = 0i64;
    if ( v4 != 1 )
    {
      v3->mGangMemberStatData = UFG::PlaceholderGameDB::GetGangMemberStatDataForPlayerId(
                                  UFG::PlaceholderGameDB::ms_pSingleton,
                                  v2,
                                  v4);
      v6 = v3->m_pSimObject;
      if ( v6 )
      {
        v7 = v6->m_Flags;
        if ( (v7 >> 14) & 1 )
        {
          v8 = v6->m_Components.p->m_pComponent;
        }
        else if ( (v7 & 0x8000u) == 0 )
        {
          if ( (v7 >> 13) & 1 )
          {
            v8 = v6->m_Components.p->m_pComponent;
          }
          else if ( (v7 >> 12) & 1 )
          {
            v9 = (unsigned int)v6[1].vfptr;
            v10 = v6->m_Components.size;
            if ( v9 >= v10 )
            {
LABEL_18:
              v8 = 0i64;
            }
            else
            {
              v11 = v6->m_Components.p;
              while ( (v11[v9].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                   || UFG::UELComponent::_TypeUID & ~v11[v9].m_TypeUID & 0x1FFFFFF )
              {
                if ( ++v9 >= v10 )
                  goto LABEL_18;
              }
              v8 = v11[v9].m_pComponent;
            }
          }
          else
          {
            v8 = UFG::SimObject::GetComponentOfType(v6, UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          v8 = v6->m_Components.p->m_pComponent;
        }
        if ( v8 )
        {
          v69 = UFG::qMalloc(0x68ui64, UFG::gGlobalNewName, 0i64);
          *(_QWORD *)&v8[3].m_TypeUID = v69;
          v69->mNext = (UFG::allocator::free_link *)&v3->mGangMemberStatData->locoSpeed;
          *(_QWORD *)(*(_QWORD *)&v8[3].m_TypeUID + 8i64) = (char *)v3->mGangMemberStatData + 108;
          *(_QWORD *)(*(_QWORD *)&v8[3].m_TypeUID + 16i64) = (char *)v3->mGangMemberStatData + 112;
          *(_QWORD *)(*(_QWORD *)&v8[3].m_TypeUID + 24i64) = (char *)v3->mGangMemberStatData + 116;
          *(_QWORD *)(*(_QWORD *)&v8[3].m_TypeUID + 32i64) = (char *)v3->mGangMemberStatData + 120;
          *(_QWORD *)(*(_QWORD *)&v8[3].m_TypeUID + 40i64) = (char *)v3->mGangMemberStatData + 124;
          *(_QWORD *)(*(_QWORD *)&v8[3].m_TypeUID + 48i64) = (char *)v3->mGangMemberStatData + 128;
          *(_QWORD *)(*(_QWORD *)&v8[3].m_TypeUID + 56i64) = (char *)v3->mGangMemberStatData + 132;
          *(_QWORD *)(*(_QWORD *)&v8[3].m_TypeUID + 64i64) = (char *)v3->mGangMemberStatData + 136;
          *(_QWORD *)(*(_QWORD *)&v8[3].m_TypeUID + 72i64) = (char *)v3->mGangMemberStatData + 140;
          *(_QWORD *)(*(_QWORD *)&v8[3].m_TypeUID + 80i64) = (char *)v3->mGangMemberStatData + 144;
          *(_QWORD *)(*(_QWORD *)&v8[3].m_TypeUID + 88i64) = (char *)v3->mGangMemberStatData + 148;
          *(_QWORD *)(*(_QWORD *)&v8[3].m_TypeUID + 96i64) = (char *)v3->mGangMemberStatData + 152;
        }
      }
      v3->mMeleeWeaponStatData = UFG::PlaceholderGameDB::GetMeleeWeaponStatDataForPlayerId(
                                   UFG::PlaceholderGameDB::ms_pSingleton,
                                   v2,
                                   "Unarmed",
                                   v3->mFightingClass == 8);
      v12 = v3->m_pSimObject;
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 >> 14) & 1 )
        {
          v14 = v12->m_Components.p->m_pComponent;
        }
        else if ( (v13 & 0x8000u) == 0 )
        {
          if ( (v13 >> 13) & 1 )
          {
            v14 = v12->m_Components.p->m_pComponent;
          }
          else if ( (v13 >> 12) & 1 )
          {
            v15 = (unsigned int)v12[1].vfptr;
            v16 = v12->m_Components.size;
            if ( v15 >= v16 )
            {
LABEL_36:
              v14 = 0i64;
            }
            else
            {
              while ( 1 )
              {
                v17 = (signed __int64)&v12->m_Components.p[v15];
                if ( (*(_DWORD *)(v17 + 8) & 0xFE000000) == (UFG::UELComponent::_TypeUID & 0xFE000000)
                  && !(UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF) )
                {
                  break;
                }
                if ( ++v15 >= v16 )
                  goto LABEL_36;
              }
              v14 = *(UFG::SimComponent **)v17;
            }
          }
          else
          {
            v14 = UFG::SimObject::GetComponentOfType(v12, UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          v14 = v12->m_Components.p->m_pComponent;
        }
        if ( v14 )
        {
          v70 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
          *(_QWORD *)&v14[3].m_Flags = v70;
          v70->mNext = (UFG::allocator::free_link *)&v3->mMeleeWeaponStatData->damage;
          *(_QWORD *)(*(_QWORD *)&v14[3].m_Flags + 8i64) = (char *)v3->mMeleeWeaponStatData + 84;
          *(_QWORD *)(*(_QWORD *)&v14[3].m_Flags + 16i64) = (char *)v3->mMeleeWeaponStatData + 88;
          *(_QWORD *)(*(_QWORD *)&v14[3].m_Flags + 24i64) = (char *)v3->mMeleeWeaponStatData + 92;
        }
      }
    }
    v3->mOwnerPlayerId = v2;
    v18 = v3->m_pSimObject;
    if ( !v18 )
      goto LABEL_41;
    v20 = v18->m_Flags;
    if ( (v20 >> 14) & 1 )
    {
      v19 = v18->m_Components.p[20].m_pComponent;
      goto LABEL_62;
    }
    if ( (v20 & 0x8000u) != 0 )
    {
      v19 = v18->m_Components.p[20].m_pComponent;
      goto LABEL_62;
    }
    if ( (v20 >> 13) & 1 )
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
            && !(UFG::TargetingSystemBaseComponent::_TypeUID & ~v23[v21].m_TypeUID & 0x1FFFFFF) )
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
      if ( !((v20 >> 12) & 1) )
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
        if ( (v28 >> 14) & 1 )
        {
          v29 = v27->mComponentTableEntryCount;
          v30 = v27->m_Components.size;
          v31 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
          if ( v29 < v30 )
          {
            while ( 1 )
            {
              v32 = (signed __int64)&v27->m_Components.p[v29];
              if ( (*(_DWORD *)(v32 + 8) & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                && !(UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF) )
              {
                break;
              }
              if ( ++v29 >= v30 )
                goto LABEL_70;
            }
LABEL_69:
            v33 = *(UFG::SimObjectWeaponPropertiesComponent **)v32;
            goto LABEL_87;
          }
          goto LABEL_70;
        }
        if ( (v28 & 0x8000u) != 0 )
        {
          v34 = v27->mComponentTableEntryCount;
          v35 = v27->m_Components.size;
          v31 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
          if ( v34 < v35 )
          {
            while ( 1 )
            {
              v32 = (signed __int64)&v27->m_Components.p[v34];
              if ( (*(_DWORD *)(v32 + 8) & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                && !(UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF) )
              {
                goto LABEL_69;
              }
              if ( ++v34 >= v35 )
                goto LABEL_70;
            }
          }
          goto LABEL_70;
        }
        if ( (v28 >> 13) & 1 )
        {
          v33 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v27);
        }
        else
        {
          if ( (v28 >> 12) & 1 )
          {
            v36 = v27->mComponentTableEntryCount;
            v37 = v27->m_Components.size;
            v31 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
            if ( v36 < v37 )
            {
              do
              {
                v32 = (signed __int64)&v27->m_Components.p[v36];
                if ( (*(_DWORD *)(v32 + 8) & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                  && !(UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF) )
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
                                                             (UFG::SimObject *)&v27->vfptr,
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
        if ( (v39 >> 14) & 1 )
        {
          v40 = v38->mComponentTableEntryCount;
          v41 = v38->m_Components.size;
          if ( v40 < v41 )
          {
            while ( 1 )
            {
              v42 = (signed __int64)&v38->m_Components.p[v40];
              if ( (*(_DWORD *)(v42 + 8) & 0xFE000000) == (v31 & 0xFE000000)
                && !(v31 & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF) )
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
        if ( (v39 & 0x8000u) != 0 )
        {
          v44 = v38->mComponentTableEntryCount;
          v45 = v38->m_Components.size;
          if ( v44 < v45 )
          {
            while ( 1 )
            {
              v42 = (signed __int64)&v38->m_Components.p[v44];
              if ( (*(_DWORD *)(v42 + 8) & 0xFE000000) == (v31 & 0xFE000000)
                && !(v31 & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF) )
              {
                goto LABEL_97;
              }
              if ( ++v44 >= v45 )
                goto LABEL_98;
            }
          }
          goto LABEL_98;
        }
        if ( (v39 >> 13) & 1 )
        {
          v43 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v38);
        }
        else
        {
          if ( (v39 >> 12) & 1 )
          {
            v46 = v38->mComponentTableEntryCount;
            v47 = v38->m_Components.size;
            if ( v46 < v47 )
            {
              do
              {
                v42 = (signed __int64)&v38->m_Components.p[v46];
                if ( (*(_DWORD *)(v42 + 8) & 0xFE000000) == (v31 & 0xFE000000)
                  && !(v31 & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF) )
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
          v43 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v38->vfptr,
                                                             v31);
          v31 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
        }
LABEL_114:
        if ( v43 )
        {
LABEL_115:
          v48 = v43;
LABEL_170:
          UFG::TriadWarsComponent::OnEquip(v3, v48);
          goto LABEL_171;
        }
LABEL_116:
        v49 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v19[1].m_Flags + 50i64)
                                     + *(_QWORD *)&v19[1].m_TypeUID
                                     + 40);
        if ( !v49 )
          goto LABEL_141;
        v50 = v49->m_Flags;
        if ( (v50 >> 14) & 1 )
        {
          v51 = v49->mComponentTableEntryCount;
          v52 = v49->m_Components.size;
          if ( v51 < v52 )
          {
            while ( 1 )
            {
              v53 = (signed __int64)&v49->m_Components.p[v51];
              if ( (*(_DWORD *)(v53 + 8) & 0xFE000000) == (v31 & 0xFE000000)
                && !(v31 & ~*(_DWORD *)(v53 + 8) & 0x1FFFFFF) )
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
        if ( (v50 & 0x8000u) != 0 )
        {
          v54 = v49->mComponentTableEntryCount;
          v55 = v49->m_Components.size;
          if ( v54 < v55 )
          {
            while ( 1 )
            {
              v53 = (signed __int64)&v49->m_Components.p[v54];
              if ( (*(_DWORD *)(v53 + 8) & 0xFE000000) == (v31 & 0xFE000000)
                && !(v31 & ~*(_DWORD *)(v53 + 8) & 0x1FFFFFF) )
              {
                goto LABEL_123;
              }
              if ( ++v54 >= v55 )
                goto LABEL_124;
            }
          }
          goto LABEL_124;
        }
        if ( (v50 >> 13) & 1 )
        {
          v43 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v49);
        }
        else
        {
          if ( (v50 >> 12) & 1 )
          {
            v56 = v49->mComponentTableEntryCount;
            v57 = v49->m_Components.size;
            if ( v56 < v57 )
            {
              do
              {
                v53 = (signed __int64)&v49->m_Components.p[v56];
                if ( (*(_DWORD *)(v53 + 8) & 0xFE000000) == (v31 & 0xFE000000)
                  && !(v31 & ~*(_DWORD *)(v53 + 8) & 0x1FFFFFF) )
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
          v43 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v49->vfptr,
                                                             v31);
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
        if ( (v59 >> 14) & 1 )
        {
          v60 = v58->mComponentTableEntryCount;
          v61 = v58->m_Components.size;
          if ( v60 >= v61 )
            goto LABEL_168;
          v62 = v58->m_Components.p;
          while ( 1 )
          {
            v63 = v60;
            if ( (v62[v60].m_TypeUID & 0xFE000000) == (v31 & 0xFE000000) && !(v31 & ~v62[v60].m_TypeUID & 0x1FFFFFF) )
              goto LABEL_149;
            if ( ++v60 >= v61 )
              goto LABEL_168;
          }
        }
        if ( (v59 & 0x8000u) != 0 )
        {
          v64 = v58->mComponentTableEntryCount;
          v65 = v58->m_Components.size;
          if ( v64 < v65 )
          {
            v62 = v58->m_Components.p;
            while ( 1 )
            {
              v63 = v64;
              if ( (v62[v64].m_TypeUID & 0xFE000000) == (v31 & 0xFE000000) && !(v31 & ~v62[v64].m_TypeUID & 0x1FFFFFF) )
                break;
              if ( ++v64 >= v65 )
                goto LABEL_168;
            }
LABEL_149:
            v5 = (UFG::SimObjectWeaponPropertiesComponent *)v62[v63].m_pComponent;
            goto LABEL_168;
          }
          goto LABEL_168;
        }
        if ( (v59 >> 13) & 1 )
        {
          v66 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v58);
        }
        else
        {
          if ( (v59 >> 12) & 1 )
          {
            v67 = v58->mComponentTableEntryCount;
            v68 = v58->m_Components.size;
            if ( v67 < v68 )
            {
              v62 = v58->m_Components.p;
              do
              {
                v63 = v67;
                if ( (v62[v67].m_TypeUID & 0xFE000000) == (v31 & 0xFE000000) && !(v31 & ~v62[v67].m_TypeUID & 0x1FFFFFF) )
                  goto LABEL_149;
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
            UFG::TriadWarsComponent::InitializeTunables(v3);
            return;
          }
          v66 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v58->vfptr,
                                                             v31);
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
            && !(UFG::TargetingSystemBaseComponent::_TypeUID & ~v23[v25].m_TypeUID & 0x1FFFFFF) )
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
  UFG::TriadWarsComponent *v1; // rdi
  UFG::SimObject *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rbx
  unsigned int v5; // er8
  unsigned int v6; // er10
  unsigned int v7; // er9
  signed __int64 v8; // rdx
  UFG::SimObject *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rbx
  unsigned int v12; // er8
  unsigned int v13; // er10
  signed __int64 v14; // rdx
  UFG::SimComponent *v15; // rax
  UFG::SimObject *v16; // rcx
  unsigned __int16 v17; // dx
  UFG::SimComponent *v18; // rbx
  unsigned int v19; // er8
  unsigned int v20; // er10
  signed __int64 v21; // rdx
  UFG::SimComponent *v22; // rax
  UFG::SimObject *v23; // rcx
  unsigned __int16 v24; // dx
  UFG::SimComponent *v25; // rbx
  unsigned int v26; // er8
  unsigned int v27; // er10
  signed __int64 v28; // rdx

  v1 = this;
  v2 = this->m_pSimObject;
  if ( !v2 )
    goto LABEL_20;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = v2->m_Components.p->m_pComponent;
  }
  else if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
    {
      v4 = v2->m_Components.p->m_pComponent;
    }
    else
    {
      if ( (v3 >> 12) & 1 )
      {
        v5 = (unsigned int)v2[1].vfptr;
        v6 = v2->m_Components.size;
        v7 = UFG::UELComponent::_TypeUID;
        if ( v5 >= v6 )
        {
LABEL_14:
          v4 = 0i64;
        }
        else
        {
          v8 = (signed __int64)&v2->m_Components.p[v5];
          while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
          {
            ++v5;
            v8 += 16i64;
            if ( v5 >= v6 )
              goto LABEL_14;
          }
          v4 = *(UFG::SimComponent **)v8;
        }
        goto LABEL_18;
      }
      v4 = UFG::SimObject::GetComponentOfType(v2, UFG::UELComponent::_TypeUID);
    }
  }
  else
  {
    v4 = v2->m_Components.p->m_pComponent;
  }
  v7 = UFG::UELComponent::_TypeUID;
LABEL_18:
  if ( !v4 )
    goto LABEL_21;
  operator delete[](*(void **)&v4[3].m_TypeUID);
  *(_QWORD *)&v4[3].m_TypeUID = 0i64;
LABEL_20:
  v7 = UFG::UELComponent::_TypeUID;
LABEL_21:
  v9 = v1->m_pSimObject;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = v9->m_Components.p->m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = v9->m_Components.p->m_pComponent;
      }
      else if ( (v10 >> 12) & 1 )
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
          v14 = (signed __int64)&v9->m_Components.p[v12];
          while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (v7 & 0xFE000000) || v7 & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF )
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
        v15 = UFG::SimObject::GetComponentOfType(v9, v7);
        v7 = UFG::UELComponent::_TypeUID;
        v11 = v15;
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
  v16 = v1->m_pSimObject;
  if ( v16 )
  {
    v17 = v16->m_Flags;
    if ( (v17 >> 14) & 1 )
    {
      v18 = v16->m_Components.p->m_pComponent;
    }
    else if ( (v17 & 0x8000u) == 0 )
    {
      if ( (v17 >> 13) & 1 )
      {
        v18 = v16->m_Components.p->m_pComponent;
      }
      else if ( (v17 >> 12) & 1 )
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
          v21 = (signed __int64)&v16->m_Components.p[v19];
          while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (v7 & 0xFE000000) || v7 & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF )
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
  v23 = v1->m_pSimObject;
  if ( v23 )
  {
    v24 = v23->m_Flags;
    if ( (v24 >> 14) & 1 )
    {
      v25 = v23->m_Components.p->m_pComponent;
    }
    else if ( (v24 & 0x8000u) == 0 )
    {
      if ( (v24 >> 13) & 1 )
      {
        v25 = v23->m_Components.p->m_pComponent;
      }
      else if ( (v24 >> 12) & 1 )
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
          v28 = (signed __int64)&v23->m_Components.p[v26];
          while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (v7 & 0xFE000000) || v7 & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF )
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
void __fastcall UFG::TriadWarsComponent::OnDetach(UFG::TriadWarsComponent *this, UFG::SimObject *simObject)
{
  UFG::TriadWarsComponent::DetachAll(this);
}

// File Line: 218
// RVA: 0x5414E0
void __fastcall UFG::TriadWarsComponent::OnEquip(UFG::TriadWarsComponent *this, UFG::SimObjectWeaponPropertiesComponent *pSOWPC)
{
  UFG::TriadWarsComponent *v2; // rbx
  unsigned int v3; // er10
  UFG::FireModeInfo *v4; // rcx
  unsigned int v5; // eax
  const char *v6; // r8
  UFG::SimComponent *v7; // rdi
  UFG::SimObject *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rsi
  unsigned int v11; // er8
  unsigned int v12; // er9
  UFG::SimComponentHolder *v13; // rsi
  UFG::SimObject *v14; // rcx
  unsigned __int16 v15; // dx
  unsigned int v16; // er8
  unsigned int v17; // er9
  UFG::SimComponentHolder *v18; // rsi
  UFG::allocator::free_link *v19; // rax
  unsigned int v20; // eax
  const char *v21; // r8
  UFG::SimObject *v22; // rcx
  unsigned __int16 v23; // dx
  UFG::SimComponent *v24; // rsi
  unsigned int v25; // er8
  unsigned int v26; // er9
  UFG::SimComponentHolder *v27; // rsi
  UFG::SimObject *v28; // rcx
  unsigned __int16 v29; // dx
  unsigned int v30; // er8
  unsigned int v31; // er9
  UFG::SimComponentHolder *v32; // rsi
  unsigned int v33; // eax
  const char *v34; // r8
  UFG::SimObject *v35; // rcx
  unsigned __int16 v36; // dx
  unsigned int v37; // edx
  unsigned int v38; // er8
  UFG::SimComponentHolder *v39; // r11
  UFG::allocator::free_link *v40; // [rsp+40h] [rbp+8h]
  UFG::allocator::free_link *v41; // [rsp+40h] [rbp+8h]

  v2 = this;
  v3 = this->mOwnerPlayerId;
  if ( v3 != -1 )
  {
    v4 = pSOWPC->mWeaponTypeInfo->mFireModes[pSOWPC->mFireMode];
    if ( v4->mProjectileSpawnBoneName.mUID == UFG::gNullQSymbolUC.mUID )
    {
      if ( v4->mProjectileSpawnBoneName.mUID == UFG::gNullQSymbolUC.mUID || v4->mIsTwoHandedWeapon || pSOWPC->mIsBladed )
      {
        v33 = v4->mSimObjectWeaponType;
        if ( v4->mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_KNIFE.m_EnumValue
          || v33 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_CLEAVER.m_EnumValue
          || v33 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_STRAIGHT_SWORD.m_EnumValue
          || v33 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SWORD.m_EnumValue )
        {
          v34 = "Bladed";
          v2->mMeleeWeapon = 2;
        }
        else if ( v33 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_BATON.m_EnumValue )
        {
          v34 = "Blunt";
          v2->mMeleeWeapon = 1;
        }
        else
        {
          if ( v33 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_BROOM_FULL.m_EnumValue
            && v33 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_LONG.m_EnumValue
            && v33 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_POLEARM.m_EnumValue )
          {
            return;
          }
          v34 = "TwoHanded";
          v2->mMeleeWeapon = 3;
        }
        v2->mThrownWeapon = 5;
        v2->mRangedWeapon = 6;
        v2->mMeleeWeaponStatData = UFG::PlaceholderGameDB::GetMeleeWeaponStatDataForPlayerId(
                                     UFG::PlaceholderGameDB::ms_pSingleton,
                                     v3,
                                     v34,
                                     v2->mFightingClass == 8);
        v35 = v2->m_pSimObject;
        if ( v35 )
        {
          v36 = v35->m_Flags;
          if ( (v36 >> 14) & 1 )
          {
            v7 = v35->m_Components.p->m_pComponent;
          }
          else if ( (v36 & 0x8000u) == 0 )
          {
            if ( (v36 >> 13) & 1 )
            {
              v7 = v35->m_Components.p->m_pComponent;
            }
            else if ( (v36 >> 12) & 1 )
            {
              v37 = (unsigned int)v35[1].vfptr;
              v38 = v35->m_Components.size;
              if ( v37 >= v38 )
              {
LABEL_123:
                v7 = 0i64;
              }
              else
              {
                v39 = v35->m_Components.p;
                while ( (v39[v37].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                     || UFG::UELComponent::_TypeUID & ~v39[v37].m_TypeUID & 0x1FFFFFF )
                {
                  if ( ++v37 >= v38 )
                    goto LABEL_123;
                }
                v7 = v39[v37].m_pComponent;
              }
            }
            else
            {
              v7 = UFG::SimObject::GetComponentOfType(v35, UFG::UELComponent::_TypeUID);
            }
          }
          else
          {
            v7 = v35->m_Components.p->m_pComponent;
          }
          if ( v7 )
          {
            v19 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
            goto LABEL_127;
          }
        }
      }
      else if ( v4->mThrownSpeed > 0.0 )
      {
        v20 = v4->mSimObjectWeaponType;
        if ( v4->mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_GAS.m_EnumValue )
        {
          v21 = "Gas";
          v2->mThrownWeapon = 1;
        }
        else if ( v20 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_FRAG.m_EnumValue )
        {
          v21 = "Frag";
          v2->mThrownWeapon = 3;
        }
        else if ( v20 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_MOLOTOV.m_EnumValue )
        {
          v21 = "Molotov";
          v2->mThrownWeapon = 2;
        }
        else
        {
          v21 = "Flash";
          v2->mThrownWeapon = 4;
        }
        v7 = 0i64;
        v2->mMeleeWeapon = 0;
        v2->mRangedWeapon = 6;
        v2->mThrownWeaponStatData = UFG::PlaceholderGameDB::GetThrownWeaponStatDataForPlayerId(
                                      UFG::PlaceholderGameDB::ms_pSingleton,
                                      v3,
                                      v21,
                                      v2->mFightingClass == 8);
        v22 = v2->m_pSimObject;
        if ( v22 )
        {
          v23 = v22->m_Flags;
          if ( (v23 >> 14) & 1 )
          {
            v24 = v22->m_Components.p->m_pComponent;
          }
          else if ( (v23 & 0x8000u) == 0 )
          {
            if ( (v23 >> 13) & 1 )
            {
              v24 = v22->m_Components.p->m_pComponent;
            }
            else if ( (v23 >> 12) & 1 )
            {
              v25 = (unsigned int)v22[1].vfptr;
              v26 = v22->m_Components.size;
              if ( v25 >= v26 )
              {
LABEL_75:
                v24 = 0i64;
              }
              else
              {
                v27 = v22->m_Components.p;
                while ( (v27[v25].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                     || UFG::UELComponent::_TypeUID & ~v27[v25].m_TypeUID & 0x1FFFFFF )
                {
                  if ( ++v25 >= v26 )
                    goto LABEL_75;
                }
                v24 = v27[v25].m_pComponent;
              }
            }
            else
            {
              v24 = UFG::SimObject::GetComponentOfType(v22, UFG::UELComponent::_TypeUID);
            }
          }
          else
          {
            v24 = v22->m_Components.p->m_pComponent;
          }
          if ( v24 )
          {
            v41 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
            v24[3].m_BoundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v41;
            v41->mNext = (UFG::allocator::free_link *)&v2->mThrownWeaponStatData->radius;
            v24[3].m_BoundComponentHandles.mNode.mPrev->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mThrownWeaponStatData->duration;
            v24[3].m_BoundComponentHandles.mNode.mPrev[1].mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mThrownWeaponStatData->damage;
          }
        }
        v2->mMeleeWeaponStatData = UFG::PlaceholderGameDB::GetMeleeWeaponStatDataForPlayerId(
                                     UFG::PlaceholderGameDB::ms_pSingleton,
                                     v2->mOwnerPlayerId,
                                     "Unarmed",
                                     v2->mFightingClass == 8);
        v28 = v2->m_pSimObject;
        if ( v28 )
        {
          v29 = v28->m_Flags;
          if ( (v29 >> 14) & 1 )
          {
            v7 = v28->m_Components.p->m_pComponent;
          }
          else if ( (v29 & 0x8000u) == 0 )
          {
            if ( (v29 >> 13) & 1 )
            {
              v7 = v28->m_Components.p->m_pComponent;
            }
            else if ( (v29 >> 12) & 1 )
            {
              v30 = (unsigned int)v28[1].vfptr;
              v31 = v28->m_Components.size;
              if ( v30 < v31 )
              {
                v32 = v28->m_Components.p;
                while ( (v32[v30].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                     || UFG::UELComponent::_TypeUID & ~v32[v30].m_TypeUID & 0x1FFFFFF )
                {
                  if ( ++v30 >= v31 )
                    goto LABEL_95;
                }
                v7 = v32[v30].m_pComponent;
              }
            }
            else
            {
              v7 = UFG::SimObject::GetComponentOfType(v28, UFG::UELComponent::_TypeUID);
            }
          }
          else
          {
            v7 = v28->m_Components.p->m_pComponent;
          }
LABEL_95:
          if ( v7 )
          {
            v19 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
            goto LABEL_127;
          }
        }
      }
    }
    else
    {
      v5 = v4->mSimObjectWeaponType;
      if ( v4->mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_PISTOL.m_EnumValue )
      {
        v6 = "Pistol";
        v2->mRangedWeapon = 1;
      }
      else if ( v5 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_RIFLE.m_EnumValue )
      {
        v6 = "Rifle";
        v2->mRangedWeapon = 3;
      }
      else if ( v5 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SHOTGUN.m_EnumValue )
      {
        v6 = "Shotgun";
        v2->mRangedWeapon = 4;
      }
      else if ( v5 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SMG.m_EnumValue )
      {
        v6 = "SMG";
        v2->mRangedWeapon = 2;
      }
      else
      {
        v6 = "Exotic";
        v2->mRangedWeapon = 5;
      }
      v2->mThrownWeapon = 5;
      v7 = 0i64;
      v2->mMeleeWeapon = 0;
      v2->mRangedWeaponStatData = UFG::PlaceholderGameDB::GetRangedWeaponStatDataForPlayerId(
                                    UFG::PlaceholderGameDB::ms_pSingleton,
                                    v3,
                                    v6,
                                    v2->mFightingClass == 8);
      v8 = v2->m_pSimObject;
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = v8->m_Components.p->m_pComponent;
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
          {
            v10 = v8->m_Components.p->m_pComponent;
          }
          else if ( (v9 >> 12) & 1 )
          {
            v11 = (unsigned int)v8[1].vfptr;
            v12 = v8->m_Components.size;
            if ( v11 >= v12 )
            {
LABEL_27:
              v10 = 0i64;
            }
            else
            {
              v13 = v8->m_Components.p;
              while ( (v13[v11].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                   || UFG::UELComponent::_TypeUID & ~v13[v11].m_TypeUID & 0x1FFFFFF )
              {
                if ( ++v11 >= v12 )
                  goto LABEL_27;
              }
              v10 = v13[v11].m_pComponent;
            }
          }
          else
          {
            v10 = UFG::SimObject::GetComponentOfType(v8, UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          v10 = v8->m_Components.p->m_pComponent;
        }
        if ( v10 )
        {
          v40 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
          v10[3].m_pSimObject = (UFG::SimObject *)v40;
          v40->mNext = (UFG::allocator::free_link *)&v2->mRangedWeaponStatData->reloadSpeed;
          v10[3].m_pSimObject->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mRangedWeaponStatData->accuracy;
          v10[3].m_pSimObject->m_SafePointerList.mNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mRangedWeaponStatData->aimRecover;
        }
      }
      v2->mMeleeWeaponStatData = UFG::PlaceholderGameDB::GetMeleeWeaponStatDataForPlayerId(
                                   UFG::PlaceholderGameDB::ms_pSingleton,
                                   v2->mOwnerPlayerId,
                                   "Unarmed",
                                   v2->mFightingClass == 8);
      v14 = v2->m_pSimObject;
      if ( v14 )
      {
        v15 = v14->m_Flags;
        if ( (v15 >> 14) & 1 )
        {
          v7 = v14->m_Components.p->m_pComponent;
        }
        else if ( (v15 & 0x8000u) == 0 )
        {
          if ( (v15 >> 13) & 1 )
          {
            v7 = v14->m_Components.p->m_pComponent;
          }
          else if ( (v15 >> 12) & 1 )
          {
            v16 = (unsigned int)v14[1].vfptr;
            v17 = v14->m_Components.size;
            if ( v16 < v17 )
            {
              v18 = v14->m_Components.p;
              while ( (v18[v16].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                   || UFG::UELComponent::_TypeUID & ~v18[v16].m_TypeUID & 0x1FFFFFF )
              {
                if ( ++v16 >= v17 )
                  goto LABEL_47;
              }
              v7 = v18[v16].m_pComponent;
            }
          }
          else
          {
            v7 = UFG::SimObject::GetComponentOfType(v14, UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          v7 = v14->m_Components.p->m_pComponent;
        }
LABEL_47:
        if ( v7 )
        {
          v19 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
LABEL_127:
          *(_QWORD *)&v7[3].m_Flags = v19;
          v19->mNext = (UFG::allocator::free_link *)&v2->mMeleeWeaponStatData->damage;
          *(_QWORD *)(*(_QWORD *)&v7[3].m_Flags + 8i64) = (char *)v2->mMeleeWeaponStatData + 84;
          *(_QWORD *)(*(_QWORD *)&v7[3].m_Flags + 16i64) = (char *)v2->mMeleeWeaponStatData + 88;
          *(_QWORD *)(*(_QWORD *)&v7[3].m_Flags + 24i64) = (char *)v2->mMeleeWeaponStatData + 92;
          return;
        }
      }
    }
  }
}

// File Line: 395
// RVA: 0x541EC0
void __fastcall UFG::TriadWarsComponent::OnUnEquip(UFG::TriadWarsComponent *this, UFG::SimObjectWeaponPropertiesComponent *pSOWPC)
{
  UFG::TriadWarsComponent *v2; // rsi
  UFG::FireModeInfo *v3; // r9
  __int64 v4; // rax
  UFG::SimObject *v5; // r8
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rdi
  unsigned int v8; // ecx
  unsigned int v9; // er9
  UFG::SimComponentHolder *v10; // rdi
  __int64 v11; // rax
  UFG::SimObject *v12; // r8
  unsigned __int16 v13; // cx
  UFG::SimComponent *v14; // rdi
  unsigned int v15; // ecx
  unsigned int v16; // er9
  UFG::SimComponentHolder *v17; // rdi
  unsigned int v18; // eax
  UFG::SimObject *v19; // r8
  UFG::SimComponent *v20; // rbx
  unsigned __int16 v21; // cx
  UFG::SimComponent *v22; // rdi
  unsigned int v23; // ecx
  unsigned int v24; // er9
  UFG::SimComponentHolder *v25; // rdi
  UFG::SimObject *v26; // rcx
  unsigned __int16 v27; // dx
  unsigned int v28; // edx
  unsigned int v29; // er9
  UFG::SimComponentHolder *v30; // rdi
  UFG::allocator::free_link *v31; // [rsp+40h] [rbp+8h]

  v2 = this;
  if ( this->mOwnerPlayerId != -1 )
  {
    v3 = pSOWPC->mWeaponTypeInfo->mFireModes[pSOWPC->mFireMode];
    if ( v3->mProjectileSpawnBoneName.mUID == UFG::gNullQSymbolUC.mUID )
    {
      if ( v3->mProjectileSpawnBoneName.mUID == UFG::gNullQSymbolUC.mUID || v3->mIsTwoHandedWeapon || pSOWPC->mIsBladed )
      {
        v18 = v3->mSimObjectWeaponType;
        if ( v3->mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_KNIFE.m_EnumValue
          || v18 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_CLEAVER.m_EnumValue
          || v18 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_STRAIGHT_SWORD.m_EnumValue
          || v18 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SWORD.m_EnumValue
          || v18 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_BATON.m_EnumValue
          || v18 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_BROOM_FULL.m_EnumValue
          || v18 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_LONG.m_EnumValue
          || v18 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_POLEARM.m_EnumValue )
        {
          v19 = this->m_pSimObject;
          v20 = 0i64;
          if ( v19 )
          {
            v21 = v19->m_Flags;
            if ( (v21 >> 14) & 1 )
            {
              v22 = v19->m_Components.p->m_pComponent;
            }
            else if ( (v21 & 0x8000u) == 0 )
            {
              if ( (v21 >> 13) & 1 )
              {
                v22 = v19->m_Components.p->m_pComponent;
              }
              else if ( (v21 >> 12) & 1 )
              {
                v23 = (unsigned int)v19[1].vfptr;
                v24 = v19->m_Components.size;
                if ( v23 >= v24 )
                {
LABEL_70:
                  v22 = 0i64;
                }
                else
                {
                  v25 = v19->m_Components.p;
                  while ( (v25[v23].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                       || UFG::UELComponent::_TypeUID & ~v25[v23].m_TypeUID & 0x1FFFFFF )
                  {
                    if ( ++v23 >= v24 )
                      goto LABEL_70;
                  }
                  v22 = v25[v23].m_pComponent;
                }
              }
              else
              {
                v22 = UFG::SimObject::GetComponentOfType(v19, UFG::UELComponent::_TypeUID);
              }
            }
            else
            {
              v22 = v19->m_Components.p->m_pComponent;
            }
            if ( v22 )
            {
              operator delete[](*(void **)&v22[3].m_Flags);
              *(_QWORD *)&v22[3].m_Flags = 0i64;
            }
          }
          v2->mMeleeWeaponStatData = UFG::PlaceholderGameDB::GetMeleeWeaponStatDataForPlayerId(
                                       UFG::PlaceholderGameDB::ms_pSingleton,
                                       v2->mOwnerPlayerId,
                                       "Unarmed",
                                       v2->mFightingClass == 8);
          v26 = v2->m_pSimObject;
          if ( v26 )
          {
            v27 = v26->m_Flags;
            if ( (v27 >> 14) & 1 )
            {
              v20 = v26->m_Components.p->m_pComponent;
            }
            else if ( (v27 & 0x8000u) == 0 )
            {
              if ( (v27 >> 13) & 1 )
              {
                v20 = v26->m_Components.p->m_pComponent;
              }
              else if ( (v27 >> 12) & 1 )
              {
                v28 = (unsigned int)v26[1].vfptr;
                v29 = v26->m_Components.size;
                if ( v28 < v29 )
                {
                  v30 = v26->m_Components.p;
                  while ( (v30[v28].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                       || UFG::UELComponent::_TypeUID & ~v30[v28].m_TypeUID & 0x1FFFFFF )
                  {
                    if ( ++v28 >= v29 )
                      goto LABEL_90;
                  }
                  v20 = v30[v28].m_pComponent;
                }
              }
              else
              {
                v20 = UFG::SimObject::GetComponentOfType(v26, UFG::UELComponent::_TypeUID);
              }
            }
            else
            {
              v20 = v26->m_Components.p->m_pComponent;
            }
LABEL_90:
            if ( v20 )
            {
              v31 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
              *(_QWORD *)&v20[3].m_Flags = v31;
              v31->mNext = (UFG::allocator::free_link *)&v2->mMeleeWeaponStatData->damage;
              *(_QWORD *)(*(_QWORD *)&v20[3].m_Flags + 8i64) = (char *)v2->mMeleeWeaponStatData + 84;
              *(_QWORD *)(*(_QWORD *)&v20[3].m_Flags + 16i64) = (char *)v2->mMeleeWeaponStatData + 88;
              *(_QWORD *)(*(_QWORD *)&v20[3].m_Flags + 24i64) = (char *)v2->mMeleeWeaponStatData + 92;
            }
          }
        }
      }
      else if ( v3->mThrownSpeed > 0.0 )
      {
        v11 = v3->mSimObjectWeaponType;
        v12 = this->m_pSimObject;
        if ( v12 )
        {
          v13 = v12->m_Flags;
          if ( (v13 >> 14) & 1 )
          {
            v14 = v12->m_Components.p->m_pComponent;
          }
          else if ( (v13 & 0x8000u) == 0 )
          {
            if ( (v13 >> 13) & 1 )
            {
              v14 = v12->m_Components.p->m_pComponent;
            }
            else if ( (v13 >> 12) & 1 )
            {
              v15 = (unsigned int)v12[1].vfptr;
              v16 = v12->m_Components.size;
              if ( v15 >= v16 )
              {
LABEL_42:
                v14 = 0i64;
              }
              else
              {
                v17 = v12->m_Components.p;
                while ( (v17[v15].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                     || UFG::UELComponent::_TypeUID & ~v17[v15].m_TypeUID & 0x1FFFFFF )
                {
                  if ( ++v15 >= v16 )
                    goto LABEL_42;
                }
                v14 = v17[v15].m_pComponent;
              }
            }
            else
            {
              v14 = UFG::SimObject::GetComponentOfType(v12, UFG::UELComponent::_TypeUID);
            }
          }
          else
          {
            v14 = v12->m_Components.p->m_pComponent;
          }
          if ( v14 )
          {
            operator delete[](v14[3].m_BoundComponentHandles.mNode.mPrev);
            v14[3].m_BoundComponentHandles.mNode.mPrev = 0i64;
          }
        }
        v2->mThrownWeaponStatData = 0i64;
      }
    }
    else
    {
      v4 = v3->mSimObjectWeaponType;
      v5 = this->m_pSimObject;
      if ( v5 )
      {
        v6 = v5->m_Flags;
        if ( (v6 >> 14) & 1 )
        {
          v7 = v5->m_Components.p->m_pComponent;
        }
        else if ( (v6 & 0x8000u) == 0 )
        {
          if ( (v6 >> 13) & 1 )
          {
            v7 = v5->m_Components.p->m_pComponent;
          }
          else if ( (v6 >> 12) & 1 )
          {
            v8 = (unsigned int)v5[1].vfptr;
            v9 = v5->m_Components.size;
            if ( v8 >= v9 )
            {
LABEL_18:
              v7 = 0i64;
            }
            else
            {
              v10 = v5->m_Components.p;
              while ( (v10[v8].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                   || UFG::UELComponent::_TypeUID & ~v10[v8].m_TypeUID & 0x1FFFFFF )
              {
                if ( ++v8 >= v9 )
                  goto LABEL_18;
              }
              v7 = v10[v8].m_pComponent;
            }
          }
          else
          {
            v7 = UFG::SimObject::GetComponentOfType(v5, UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          v7 = v5->m_Components.p->m_pComponent;
        }
        if ( v7 )
        {
          operator delete[](v7[3].m_pSimObject);
          v7[3].m_pSimObject = 0i64;
        }
      }
      v2->mRangedWeaponStatData = 0i64;
    }
  }
}

// File Line: 524
// RVA: 0x539490
void __fastcall UFG::TriadWarsComponent::InitializeTunables(UFG::TriadWarsComponent *this)
{
  UFG::TriadWarsComponent *v1; // rdi
  UFG::SimObject *v2; // rcx
  UFG::HealthComponent *v3; // rbx
  unsigned __int16 v4; // dx
  unsigned int v5; // edx
  unsigned int v6; // er8
  signed __int64 v7; // rbx
  unsigned int v8; // edx
  unsigned int v9; // er8

  v1 = this;
  v2 = this->m_pSimObject;
  if ( !v2 )
    goto LABEL_2;
  v4 = v2->m_Flags;
  if ( (v4 >> 14) & 1 || (v4 & 0x8000u) != 0 )
  {
    v3 = (UFG::HealthComponent *)v2->m_Components.p[6].m_pComponent;
    goto LABEL_22;
  }
  if ( !((v4 >> 13) & 1) )
  {
    if ( !((v4 >> 12) & 1) )
    {
      v3 = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(v2, UFG::HealthComponent::_TypeUID);
      goto LABEL_22;
    }
    v8 = (unsigned int)v2[1].vfptr;
    v9 = v2->m_Components.size;
    if ( v8 >= v9 )
      goto LABEL_2;
    v7 = (signed __int64)&v2->m_Components.p[v8];
    while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
         || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
    {
      ++v8;
      v7 += 16i64;
      if ( v8 >= v9 )
      {
        v3 = 0i64;
        goto LABEL_22;
      }
    }
LABEL_13:
    v3 = *(UFG::HealthComponent **)v7;
    goto LABEL_22;
  }
  v5 = (unsigned int)v2[1].vfptr;
  v6 = v2->m_Components.size;
  if ( v5 < v6 )
  {
    v7 = (signed __int64)&v2->m_Components.p[v5];
    while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
         || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
    {
      ++v5;
      v7 += 16i64;
      if ( v5 >= v6 )
      {
        v3 = 0i64;
        goto LABEL_22;
      }
    }
    goto LABEL_13;
  }
LABEL_2:
  v3 = 0i64;
LABEL_22:
  UFG::HealthComponent::SetMaxHealth(v3, (signed int)v1->mGangMemberStatData->maxHP);
  UFG::HealthComponent::SetHealth(v3, (signed int)v1->mGangMemberStatData->maxHP, 0i64);
}

