// File Line: 37
// RVA: 0x537DA0
void __fastcall UFG::SubTargetingLocationDynamic::SubTargetingLocationWithCondition::InitFromPropertySet(
        UFG::SubTargetingLocationDynamic::SubTargetingLocationWithCondition *this,
        UFG::qPropertySet *pDynamicSubTargetingLocationPropertySet)
{
  unsigned int v4; // eax
  UFG::qSymbol *v5; // rdi
  UFG::qSymbol *v6; // rbp
  UFG::SubTargetingLocationDynamic::DynamicConditionEnum v7; // ebx
  UFG::qBaseTreeRB *v8; // rax
  const char **v9; // rdi

  if ( pDynamicSubTargetingLocationPropertySet )
  {
    v4 = _S48;
    if ( (_S48 & 1) == 0 )
    {
      _S48 |= 1u;
      UFG::qSymbol::create_from_string(&symSubTargetingLocationName, "SubTargetingLocationName");
      atexit(UFG::SubTargetingLocationDynamic::SubTargetingLocationWithCondition::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symSubTargetingLocationName__);
      v4 = _S48;
    }
    if ( (v4 & 2) == 0 )
    {
      _S48 = v4 | 2;
      UFG::qSymbol::create_from_string(&symDynamicConditionName, "Condition");
      atexit(UFG::SubTargetingLocationDynamic::SubTargetingLocationWithCondition::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symDynamicConditionName__);
    }
    v5 = UFG::qPropertySet::Get<UFG::qSymbol>(
           pDynamicSubTargetingLocationPropertySet,
           (UFG::qArray<unsigned long,0> *)&symSubTargetingLocationName,
           DEPTH_RECURSE);
    v6 = UFG::qPropertySet::Get<UFG::qSymbol>(
           pDynamicSubTargetingLocationPropertySet,
           (UFG::qArray<unsigned long,0> *)&symDynamicConditionName,
           DEPTH_RECURSE);
    v7 = DYNAMIC_CONDITION_INVALID;
    if ( v5 )
    {
      if ( v5->mUID )
        v8 = UFG::qBaseTreeRB::Get(&UFG::SubTargetingLocations::ms_SubTargetingLocations.mTree, v5->mUID);
      else
        v8 = 0i64;
      this->m_pSubTargetingLocation = (UFG::SubTargetingLocation *)v8;
    }
    if ( v6 )
    {
      v9 = UFG::SubTargetingLocationDynamic::ms_ConditionNames;
      do
      {
        if ( (unsigned int)UFG::qStringHash32(*v9, 0xFFFFFFFF) == v6->mUID )
          this->m_eDynamicCondition = v7;
        ++v7;
        ++v9;
      }
      while ( v7 < NUM_DYNAMIC_CONDITION_TYPES );
    }
    else
    {
      this->m_eDynamicCondition = DYNAMIC_CONDITION_ALWAYS;
    }
  }
}

// File Line: 94
// RVA: 0x537D10
void __fastcall UFG::SubTargetingLocationDynamic::InitFromPropertySet(
        UFG::SubTargetingLocationDynamic *this,
        UFG::qPropertyList *pSubTargetingLocationWithConditions)
{
  unsigned int v2; // ebx
  unsigned int mNumElements; // esi
  char *ValuePtr; // rax
  __int64 v7; // rcx
  UFG::qPropertySet *v8; // rdx
  UFG::SubTargetingLocationDynamic::SubTargetingLocationWithCondition *v9; // rcx

  v2 = 0;
  this->m_SubTargetingLocationsWithConditions.size = 0;
  if ( pSubTargetingLocationWithConditions )
  {
    mNumElements = pSubTargetingLocationWithConditions->mNumElements;
    if ( mNumElements )
    {
      do
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(pSubTargetingLocationWithConditions, 0x1Au, v2);
        if ( ValuePtr )
        {
          v7 = *(_QWORD *)ValuePtr;
          if ( *(_QWORD *)ValuePtr )
          {
            v8 = (UFG::qPropertySet *)&ValuePtr[v7];
            if ( &ValuePtr[v7] )
            {
              v9 = &this->m_SubTargetingLocationsWithConditions.p[this->m_SubTargetingLocationsWithConditions.size++];
              UFG::SubTargetingLocationDynamic::SubTargetingLocationWithCondition::InitFromPropertySet(v9, v8);
            }
          }
        }
        ++v2;
      }
      while ( v2 < mNumElements );
    }
  }
}

// File Line: 114
// RVA: 0x52FD50
UFG::SubTargetingLocation *__fastcall UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
        UFG::SubTargetingLocationDynamic *this,
        UFG::SimObject *pSimObject)
{
  __int64 size; // r15
  __int64 v3; // rsi
  unsigned int v6; // r11d
  char *v7; // r14
  int v8; // eax
  signed __int16 m_Flags; // cx
  unsigned int vfptr; // r8d
  unsigned int v11; // r9d
  UFG::SimComponentHolder *v12; // rdx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int v14; // r8d
  unsigned int v15; // r9d
  unsigned int v16; // r8d
  unsigned int v17; // r9d
  hkLocalFrameGroup *Texture; // rax
  UFG::SimObject *v19; // r9
  __int16 v20; // dx
  UFG::SimComponent *v21; // rax
  unsigned int v22; // r8d
  unsigned int v23; // r10d
  __int64 v24; // rdx
  unsigned int v25; // r8d
  unsigned int v26; // r10d
  signed __int16 v27; // cx
  unsigned int v28; // r8d
  unsigned int v29; // r9d
  UFG::SimComponentHolder *v30; // rdx
  UFG::VehicleOccupantComponent *ComponentOfType; // rax
  unsigned int v32; // r8d
  unsigned int v33; // r9d
  unsigned int v34; // r8d
  unsigned int v35; // r9d
  UFG::SimObject *Passenger; // rax
  __int16 v37; // dx
  unsigned int v38; // r8d
  unsigned int v39; // r10d
  unsigned int v40; // r8d
  unsigned int v41; // r10d
  UFG::SubTargetingLocation *result; // rax

  size = this->m_SubTargetingLocationsWithConditions.size;
  v3 = 0i64;
  if ( !this->m_SubTargetingLocationsWithConditions.size )
    return this->m_SubTargetingLocationsWithConditions.p[0].m_pSubTargetingLocation;
  v6 = UFG::VehicleOccupantComponent::_TypeUID;
  while ( 1 )
  {
    v7 = (char *)this + 16 * v3;
    v8 = *((_DWORD *)v7 + 2);
    if ( v8 == 1 )
      break;
    if ( v8 == 2 )
    {
      if ( !pSimObject )
        goto LABEL_103;
      m_Flags = pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        vfptr = (unsigned int)pSimObject[1].vfptr;
        v11 = pSimObject->m_Components.size;
        if ( vfptr < v11 )
        {
          v12 = &pSimObject->m_Components.p[vfptr];
          while ( (v12->m_TypeUID & 0xFE000000) != (v6 & 0xFE000000) || (v6 & ~v12->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            ++v12;
            if ( vfptr >= v11 )
              goto LABEL_12;
          }
          goto LABEL_13;
        }
LABEL_12:
        m_pComponent = 0i64;
LABEL_31:
        if ( m_pComponent )
        {
          Texture = Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)m_pComponent);
          v19 = (UFG::SimObject *)Texture;
          if ( !Texture )
            goto LABEL_102;
          v20 = WORD2(Texture[3].vfptr);
          if ( (v20 & 0x4000) != 0 )
          {
            v21 = *(UFG::SimComponent **)(*(_QWORD *)&Texture[4].m_memSizeAndFlags + 96i64);
            goto LABEL_100;
          }
          if ( v20 < 0 )
          {
            v21 = *(UFG::SimComponent **)(*(_QWORD *)&Texture[4].m_memSizeAndFlags + 96i64);
            goto LABEL_100;
          }
          if ( (v20 & 0x2000) != 0 )
          {
            v22 = *(_DWORD *)&Texture[5].m_memSizeAndFlags;
            v23 = (unsigned int)Texture[4].vfptr;
            if ( v22 < v23 )
            {
              v24 = *(_QWORD *)&Texture[4].m_memSizeAndFlags + 16i64 * v22;
              while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                   || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF) != 0 )
              {
                ++v22;
                v24 += 16i64;
                if ( v22 >= v23 )
                  goto LABEL_43;
              }
              goto LABEL_91;
            }
            goto LABEL_43;
          }
          if ( (v20 & 0x1000) != 0 )
          {
            v25 = *(_DWORD *)&Texture[5].m_memSizeAndFlags;
            v26 = (unsigned int)Texture[4].vfptr;
            if ( v25 < v26 )
            {
              v24 = *(_QWORD *)&Texture[4].m_memSizeAndFlags + 16i64 * v25;
              while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                   || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF) != 0 )
              {
                ++v25;
                v24 += 16i64;
                if ( v25 >= v26 )
                {
                  v21 = 0i64;
                  goto LABEL_100;
                }
              }
              goto LABEL_91;
            }
            goto LABEL_43;
          }
          goto LABEL_99;
        }
        goto LABEL_103;
      }
      if ( m_Flags < 0 )
      {
        m_pComponent = pSimObject->m_Components.p[30].m_pComponent;
        goto LABEL_31;
      }
      if ( (m_Flags & 0x2000) != 0 )
      {
        v14 = (unsigned int)pSimObject[1].vfptr;
        v15 = pSimObject->m_Components.size;
        if ( v14 >= v15 )
          goto LABEL_12;
        v12 = &pSimObject->m_Components.p[v14];
        while ( (v12->m_TypeUID & 0xFE000000) != (v6 & 0xFE000000) || (v6 & ~v12->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v14;
          ++v12;
          if ( v14 >= v15 )
          {
            m_pComponent = 0i64;
            goto LABEL_31;
          }
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(pSimObject, v6);
          v6 = UFG::VehicleOccupantComponent::_TypeUID;
          goto LABEL_31;
        }
        v16 = (unsigned int)pSimObject[1].vfptr;
        v17 = pSimObject->m_Components.size;
        if ( v16 >= v17 )
          goto LABEL_12;
        v12 = &pSimObject->m_Components.p[v16];
        while ( (v12->m_TypeUID & 0xFE000000) != (v6 & 0xFE000000) || (v6 & ~v12->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v16;
          ++v12;
          if ( v16 >= v17 )
          {
            m_pComponent = 0i64;
            goto LABEL_31;
          }
        }
      }
LABEL_13:
      m_pComponent = v12->m_pComponent;
      goto LABEL_31;
    }
    if ( (unsigned int)(v8 - 3) > 3 )
      return this->m_SubTargetingLocationsWithConditions.p[0].m_pSubTargetingLocation;
    if ( !pSimObject )
      goto LABEL_103;
    v27 = pSimObject->m_Flags;
    if ( (v27 & 0x4000) != 0 )
    {
      v28 = (unsigned int)pSimObject[1].vfptr;
      v29 = pSimObject->m_Components.size;
      if ( v28 >= v29 )
        goto LABEL_59;
      v30 = &pSimObject->m_Components.p[v28];
      while ( (v30->m_TypeUID & 0xFE000000) != (v6 & 0xFE000000) || (v6 & ~v30->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v28;
        ++v30;
        if ( v28 >= v29 )
          goto LABEL_59;
      }
LABEL_60:
      ComponentOfType = (UFG::VehicleOccupantComponent *)v30->m_pComponent;
      goto LABEL_78;
    }
    if ( v27 >= 0 )
    {
      if ( (v27 & 0x2000) != 0 )
      {
        v32 = (unsigned int)pSimObject[1].vfptr;
        v33 = pSimObject->m_Components.size;
        if ( v32 >= v33 )
          goto LABEL_59;
        v30 = &pSimObject->m_Components.p[v32];
        while ( (v30->m_TypeUID & 0xFE000000) != (v6 & 0xFE000000) || (v6 & ~v30->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v32;
          ++v30;
          if ( v32 >= v33 )
          {
            ComponentOfType = 0i64;
            goto LABEL_78;
          }
        }
        goto LABEL_60;
      }
      if ( (v27 & 0x1000) != 0 )
      {
        v34 = (unsigned int)pSimObject[1].vfptr;
        v35 = pSimObject->m_Components.size;
        if ( v34 >= v35 )
        {
LABEL_59:
          ComponentOfType = 0i64;
          goto LABEL_78;
        }
        v30 = &pSimObject->m_Components.p[v34];
        while ( (v30->m_TypeUID & 0xFE000000) != (v6 & 0xFE000000) || (v6 & ~v30->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v34;
          ++v30;
          if ( v34 >= v35 )
          {
            ComponentOfType = 0i64;
            goto LABEL_78;
          }
        }
        goto LABEL_60;
      }
      ComponentOfType = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(pSimObject, v6);
      v6 = UFG::VehicleOccupantComponent::_TypeUID;
    }
    else
    {
      ComponentOfType = (UFG::VehicleOccupantComponent *)pSimObject->m_Components.p[30].m_pComponent;
    }
LABEL_78:
    if ( ComponentOfType )
    {
      Passenger = UFG::VehicleOccupantComponent::GetPassenger(ComponentOfType, *((_DWORD *)v7 + 2) - 3, 1);
      v19 = Passenger;
      if ( !Passenger )
        goto LABEL_102;
      v37 = Passenger->m_Flags;
      if ( (v37 & 0x4000) != 0 )
      {
        v21 = Passenger->m_Components.p[6].m_pComponent;
        goto LABEL_100;
      }
      if ( v37 < 0 )
      {
        v21 = Passenger->m_Components.p[6].m_pComponent;
        goto LABEL_100;
      }
      if ( (v37 & 0x2000) != 0 )
      {
        v38 = (unsigned int)Passenger[1].vfptr;
        v39 = Passenger->m_Components.size;
        if ( v38 < v39 )
        {
          v24 = (__int64)&Passenger->m_Components.p[v38];
          while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
               || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v38;
            v24 += 16i64;
            if ( v38 >= v39 )
            {
              v21 = 0i64;
              goto LABEL_100;
            }
          }
          goto LABEL_91;
        }
LABEL_43:
        v21 = 0i64;
        goto LABEL_100;
      }
      if ( (v37 & 0x1000) != 0 )
      {
        v40 = (unsigned int)Passenger[1].vfptr;
        v41 = Passenger->m_Components.size;
        if ( v40 >= v41 )
          goto LABEL_43;
        v24 = (__int64)&Passenger->m_Components.p[v40];
        while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v40;
          v24 += 16i64;
          if ( v40 >= v41 )
          {
            v21 = 0i64;
            goto LABEL_100;
          }
        }
LABEL_91:
        v21 = *(UFG::SimComponent **)v24;
LABEL_100:
        if ( !v21 || !BYTE4(v21[1].m_BoundComponentHandles.mNode.mPrev) )
          break;
LABEL_102:
        v6 = UFG::VehicleOccupantComponent::_TypeUID;
        goto LABEL_103;
      }
LABEL_99:
      v21 = UFG::SimObject::GetComponentOfType(v19, UFG::HealthComponent::_TypeUID);
      goto LABEL_100;
    }
LABEL_103:
    if ( ++v3 >= size )
      return this->m_SubTargetingLocationsWithConditions.p[0].m_pSubTargetingLocation;
  }
  result = (UFG::SubTargetingLocation *)*((_QWORD *)v7 + 2);
  if ( !result )
    return this->m_SubTargetingLocationsWithConditions.p[0].m_pSubTargetingLocation;
  return result;
}

