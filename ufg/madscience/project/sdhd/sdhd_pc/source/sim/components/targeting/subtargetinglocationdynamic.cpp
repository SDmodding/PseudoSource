// File Line: 37
// RVA: 0x537DA0
void __fastcall UFG::SubTargetingLocationDynamic::SubTargetingLocationWithCondition::InitFromPropertySet(UFG::SubTargetingLocationDynamic::SubTargetingLocationWithCondition *this, UFG::qPropertySet *pDynamicSubTargetingLocationPropertySet)
{
  UFG::qPropertySet *v2; // rbx
  UFG::SubTargetingLocationDynamic::SubTargetingLocationWithCondition *v3; // rsi
  unsigned int v4; // eax
  UFG::qSymbol *v5; // rdi
  UFG::qSymbol *v6; // rbp
  signed int v7; // ebx
  UFG::qBaseTreeRB *v8; // rax
  const char **v9; // rdi

  if ( pDynamicSubTargetingLocationPropertySet )
  {
    v2 = pDynamicSubTargetingLocationPropertySet;
    v3 = this;
    v4 = _S48;
    if ( !(_S48 & 1) )
    {
      _S48 |= 1u;
      UFG::qSymbol::create_from_string(&symSubTargetingLocationName, "SubTargetingLocationName");
      atexit(UFG::SubTargetingLocationDynamic::SubTargetingLocationWithCondition::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symSubTargetingLocationName__);
      v4 = _S48;
    }
    if ( !(v4 & 2) )
    {
      _S48 = v4 | 2;
      UFG::qSymbol::create_from_string(&symDynamicConditionName, "Condition");
      atexit(UFG::SubTargetingLocationDynamic::SubTargetingLocationWithCondition::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symDynamicConditionName__);
    }
    v5 = UFG::qPropertySet::Get<UFG::qSymbol>(v2, &symSubTargetingLocationName, DEPTH_RECURSE);
    v6 = UFG::qPropertySet::Get<UFG::qSymbol>(v2, &symDynamicConditionName, DEPTH_RECURSE);
    v7 = 0;
    if ( v5 )
    {
      if ( v5->mUID )
        v8 = UFG::qBaseTreeRB::Get(&UFG::SubTargetingLocations::ms_SubTargetingLocations.mTree, v5->mUID);
      else
        v8 = 0i64;
      v3->m_pSubTargetingLocation = (UFG::SubTargetingLocation *)v8;
    }
    if ( v6 )
    {
      v9 = UFG::SubTargetingLocationDynamic::ms_ConditionNames;
      do
      {
        if ( (unsigned int)UFG::qStringHash32(*v9, 0xFFFFFFFF) == v6->mUID )
          v3->m_eDynamicCondition = v7;
        ++v7;
        ++v9;
      }
      while ( v7 < 7 );
    }
    else
    {
      v3->m_eDynamicCondition = 1;
    }
  }
}

// File Line: 94
// RVA: 0x537D10
void __fastcall UFG::SubTargetingLocationDynamic::InitFromPropertySet(UFG::SubTargetingLocationDynamic *this, UFG::qPropertyList *pSubTargetingLocationWithConditions)
{
  unsigned int v2; // ebx
  UFG::qPropertyList *v3; // rbp
  UFG::SubTargetingLocationDynamic *v4; // rdi
  unsigned int v5; // esi
  char *v6; // rax
  __int64 v7; // rcx
  UFG::qPropertySet *v8; // rdx
  UFG::SubTargetingLocationDynamic::SubTargetingLocationWithCondition *v9; // rcx

  v2 = 0;
  v3 = pSubTargetingLocationWithConditions;
  v4 = this;
  this->m_SubTargetingLocationsWithConditions.size = 0;
  if ( pSubTargetingLocationWithConditions )
  {
    v5 = pSubTargetingLocationWithConditions->mNumElements;
    if ( v5 )
    {
      do
      {
        v6 = UFG::qPropertyList::GetValuePtr(v3, 0x1Au, v2);
        if ( v6 )
        {
          v7 = *(_QWORD *)v6;
          if ( *(_QWORD *)v6 )
          {
            v8 = (UFG::qPropertySet *)&v6[v7];
            if ( &v6[v7] )
            {
              v9 = &v4->m_SubTargetingLocationsWithConditions.p[v4->m_SubTargetingLocationsWithConditions.size++];
              UFG::SubTargetingLocationDynamic::SubTargetingLocationWithCondition::InitFromPropertySet(v9, v8);
            }
          }
        }
        ++v2;
      }
      while ( v2 < v5 );
    }
  }
}

// File Line: 114
// RVA: 0x52FD50
UFG::SubTargetingLocation *__fastcall UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(UFG::SubTargetingLocationDynamic *this, UFG::SimObject *pSimObject)
{
  __int64 v2; // r15
  __int64 v3; // rsi
  UFG::SimObject *v4; // rdi
  UFG::SubTargetingLocationDynamic *v5; // rbp
  unsigned int v6; // er11
  signed __int64 v7; // r14
  int v8; // eax
  unsigned __int16 v9; // cx
  unsigned int v10; // er8
  unsigned int v11; // er9
  signed __int64 v12; // rdx
  hkSimpleLocalFrame *v13; // rax
  unsigned int v14; // er8
  unsigned int v15; // er9
  unsigned int v16; // er8
  unsigned int v17; // er9
  hkLocalFrameGroup *v18; // rax
  UFG::SimObject *v19; // r9
  unsigned __int16 v20; // dx
  UFG::SimComponent *v21; // rax
  unsigned int v22; // er8
  unsigned int v23; // er10
  signed __int64 v24; // rdx
  unsigned int v25; // er8
  unsigned int v26; // er10
  unsigned __int16 v27; // cx
  unsigned int v28; // er8
  unsigned int v29; // er9
  signed __int64 v30; // rdx
  UFG::VehicleOccupantComponent *v31; // rax
  unsigned int v32; // er8
  unsigned int v33; // er9
  unsigned int v34; // er8
  unsigned int v35; // er9
  UFG::SimObject *v36; // rax
  unsigned __int16 v37; // dx
  unsigned int v38; // er8
  unsigned int v39; // er10
  unsigned int v40; // er8
  unsigned int v41; // er10
  UFG::SubTargetingLocation *result; // rax

  v2 = this->m_SubTargetingLocationsWithConditions.size;
  v3 = 0i64;
  v4 = pSimObject;
  v5 = this;
  if ( v2 <= 0 )
    return v5->m_SubTargetingLocationsWithConditions.p[0].m_pSubTargetingLocation;
  v6 = UFG::VehicleOccupantComponent::_TypeUID;
  while ( 1 )
  {
    v7 = (signed __int64)v5 + 16 * v3;
    v8 = *(_DWORD *)(v7 + 8);
    if ( v8 == 1 )
      break;
    if ( v8 == 2 )
    {
      if ( !v4 )
        goto LABEL_103;
      v9 = v4->m_Flags;
      if ( (v9 >> 14) & 1 )
      {
        v10 = (unsigned int)v4[1].vfptr;
        v11 = v4->m_Components.size;
        if ( v10 < v11 )
        {
          v12 = (signed __int64)&v4->m_Components.p[v10];
          while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (v6 & 0xFE000000) || v6 & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
          {
            ++v10;
            v12 += 16i64;
            if ( v10 >= v11 )
              goto LABEL_12;
          }
          goto LABEL_13;
        }
LABEL_12:
        v13 = 0i64;
LABEL_31:
        if ( v13 )
        {
          v18 = Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v13);
          v19 = (UFG::SimObject *)v18;
          if ( !v18 )
            goto LABEL_102;
          v20 = WORD2(v18[3].vfptr);
          if ( (v20 >> 14) & 1 )
          {
            v21 = *(UFG::SimComponent **)(*(_QWORD *)&v18[4].m_memSizeAndFlags + 96i64);
            goto LABEL_100;
          }
          if ( (v20 & 0x8000u) != 0 )
          {
            v21 = *(UFG::SimComponent **)(*(_QWORD *)&v18[4].m_memSizeAndFlags + 96i64);
            goto LABEL_100;
          }
          if ( (v20 >> 13) & 1 )
          {
            v22 = *(_DWORD *)&v18[5].m_memSizeAndFlags;
            v23 = (unsigned int)v18[4].vfptr;
            if ( v22 < v23 )
            {
              v24 = *(_QWORD *)&v18[4].m_memSizeAndFlags + 16i64 * v22;
              while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                   || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF )
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
          if ( (v20 >> 12) & 1 )
          {
            v25 = *(_DWORD *)&v18[5].m_memSizeAndFlags;
            v26 = (unsigned int)v18[4].vfptr;
            if ( v25 < v26 )
            {
              v24 = *(_QWORD *)&v18[4].m_memSizeAndFlags + 16i64 * v25;
              while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                   || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF )
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
      if ( (v9 & 0x8000u) != 0 )
      {
        v13 = (hkSimpleLocalFrame *)v4->m_Components.p[30].m_pComponent;
        goto LABEL_31;
      }
      if ( (v9 >> 13) & 1 )
      {
        v14 = (unsigned int)v4[1].vfptr;
        v15 = v4->m_Components.size;
        if ( v14 >= v15 )
          goto LABEL_12;
        v12 = (signed __int64)&v4->m_Components.p[v14];
        while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (v6 & 0xFE000000) || v6 & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
        {
          ++v14;
          v12 += 16i64;
          if ( v14 >= v15 )
          {
            v13 = 0i64;
            goto LABEL_31;
          }
        }
      }
      else
      {
        if ( !((v9 >> 12) & 1) )
        {
          v13 = (hkSimpleLocalFrame *)UFG::SimObject::GetComponentOfType(v4, v6);
          v6 = UFG::VehicleOccupantComponent::_TypeUID;
          goto LABEL_31;
        }
        v16 = (unsigned int)v4[1].vfptr;
        v17 = v4->m_Components.size;
        if ( v16 >= v17 )
          goto LABEL_12;
        v12 = (signed __int64)&v4->m_Components.p[v16];
        while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (v6 & 0xFE000000) || v6 & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
        {
          ++v16;
          v12 += 16i64;
          if ( v16 >= v17 )
          {
            v13 = 0i64;
            goto LABEL_31;
          }
        }
      }
LABEL_13:
      v13 = *(hkSimpleLocalFrame **)v12;
      goto LABEL_31;
    }
    if ( (unsigned int)(v8 - 3) > 3 )
      return v5->m_SubTargetingLocationsWithConditions.p[0].m_pSubTargetingLocation;
    if ( !v4 )
      goto LABEL_103;
    v27 = v4->m_Flags;
    if ( (v27 >> 14) & 1 )
    {
      v28 = (unsigned int)v4[1].vfptr;
      v29 = v4->m_Components.size;
      if ( v28 >= v29 )
        goto LABEL_59;
      v30 = (signed __int64)&v4->m_Components.p[v28];
      while ( (*(_DWORD *)(v30 + 8) & 0xFE000000) != (v6 & 0xFE000000) || v6 & ~*(_DWORD *)(v30 + 8) & 0x1FFFFFF )
      {
        ++v28;
        v30 += 16i64;
        if ( v28 >= v29 )
          goto LABEL_59;
      }
LABEL_60:
      v31 = *(UFG::VehicleOccupantComponent **)v30;
      goto LABEL_78;
    }
    if ( (v27 & 0x8000u) == 0 )
    {
      if ( (v27 >> 13) & 1 )
      {
        v32 = (unsigned int)v4[1].vfptr;
        v33 = v4->m_Components.size;
        if ( v32 >= v33 )
          goto LABEL_59;
        v30 = (signed __int64)&v4->m_Components.p[v32];
        while ( (*(_DWORD *)(v30 + 8) & 0xFE000000) != (v6 & 0xFE000000) || v6 & ~*(_DWORD *)(v30 + 8) & 0x1FFFFFF )
        {
          ++v32;
          v30 += 16i64;
          if ( v32 >= v33 )
          {
            v31 = 0i64;
            goto LABEL_78;
          }
        }
        goto LABEL_60;
      }
      if ( (v27 >> 12) & 1 )
      {
        v34 = (unsigned int)v4[1].vfptr;
        v35 = v4->m_Components.size;
        if ( v34 >= v35 )
        {
LABEL_59:
          v31 = 0i64;
          goto LABEL_78;
        }
        v30 = (signed __int64)&v4->m_Components.p[v34];
        while ( (*(_DWORD *)(v30 + 8) & 0xFE000000) != (v6 & 0xFE000000) || v6 & ~*(_DWORD *)(v30 + 8) & 0x1FFFFFF )
        {
          ++v34;
          v30 += 16i64;
          if ( v34 >= v35 )
          {
            v31 = 0i64;
            goto LABEL_78;
          }
        }
        goto LABEL_60;
      }
      v31 = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(v4, v6);
      v6 = UFG::VehicleOccupantComponent::_TypeUID;
    }
    else
    {
      v31 = (UFG::VehicleOccupantComponent *)v4->m_Components.p[30].m_pComponent;
    }
LABEL_78:
    if ( v31 )
    {
      v36 = UFG::VehicleOccupantComponent::GetPassenger(v31, *(_DWORD *)(v7 + 8) - 3, 1);
      v19 = v36;
      if ( !v36 )
        goto LABEL_102;
      v37 = v36->m_Flags;
      if ( (v37 >> 14) & 1 )
      {
        v21 = v36->m_Components.p[6].m_pComponent;
        goto LABEL_100;
      }
      if ( (v37 & 0x8000u) != 0 )
      {
        v21 = v36->m_Components.p[6].m_pComponent;
        goto LABEL_100;
      }
      if ( (v37 >> 13) & 1 )
      {
        v38 = (unsigned int)v36[1].vfptr;
        v39 = v36->m_Components.size;
        if ( v38 < v39 )
        {
          v24 = (signed __int64)&v36->m_Components.p[v38];
          while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
               || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF )
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
      if ( (v37 >> 12) & 1 )
      {
        v40 = (unsigned int)v36[1].vfptr;
        v41 = v36->m_Components.size;
        if ( v40 >= v41 )
          goto LABEL_43;
        v24 = (signed __int64)&v36->m_Components.p[v40];
        while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF )
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
    if ( ++v3 >= v2 )
      return v5->m_SubTargetingLocationsWithConditions.p[0].m_pSubTargetingLocation;
  }
  result = *(UFG::SubTargetingLocation **)(v7 + 16);
  if ( !result )
    return v5->m_SubTargetingLocationsWithConditions.p[0].m_pSubTargetingLocation;
  return result;
}

