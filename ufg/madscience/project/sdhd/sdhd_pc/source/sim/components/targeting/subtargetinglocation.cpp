// File Line: 23
// RVA: 0x5379B0
void __fastcall UFG::SubTargetingLocation::InitFromPropertySet(UFG::SubTargetingLocation *this, UFG::qPropertySet *pSubTargetingLocationPropertySet)
{
  UFG::qPropertySet *v2; // r14
  UFG::SubTargetingLocation *v3; // rsi
  unsigned int v4; // eax
  UFG::qSymbolUC *v5; // rbx
  UFG::qVector3 *v6; // rdi
  float *v7; // r13
  float *v8; // r12
  float *v9; // r15
  UFG::qSymbol *v10; // rax
  UFG::qSymbolUC *v11; // rcx
  UFG::qVector3 *v12; // rcx
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v18; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v19; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v20; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]

  if ( pSubTargetingLocationPropertySet )
  {
    v2 = pSubTargetingLocationPropertySet;
    v3 = this;
    this->mNode.mUID = pSubTargetingLocationPropertySet->mName.mUID;
    v4 = _S47;
    if ( !(_S47 & 1) )
    {
      _S47 |= 1u;
      UFG::qSymbol::create_from_string(&symBoneName, "BoneName");
      atexit(UFG::SubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symBoneName__);
      v4 = _S47;
    }
    if ( !(v4 & 2) )
    {
      _S47 = v4 | 2;
      UFG::qSymbol::create_from_string(&symOffset, "Offset");
      atexit(UFG::SubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symOffset__);
      v4 = _S47;
    }
    if ( !(v4 & 4) )
    {
      _S47 = v4 | 4;
      UFG::qSymbol::create_from_string(&symAccuracyRate, "AccuracyRate");
      atexit(UFG::SubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symAccuracyRate__);
      v4 = _S47;
    }
    if ( !(v4 & 8) )
    {
      _S47 = v4 | 8;
      UFG::qSymbol::create_from_string(&symAccuracyPenalty, "AccuracyPenalty");
      atexit(UFG::SubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symAccuracyPenalty__);
      v4 = _S47;
    }
    if ( !(v4 & 0x10) )
    {
      _S47 = v4 | 0x10;
      UFG::qSymbol::create_from_string(&symRadius, "Radius");
      atexit(UFG::SubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symRadius__);
      v4 = _S47;
    }
    if ( !(v4 & 0x20) )
    {
      _S47 = v4 | 0x20;
      UFG::qSymbol::create_from_string(&symSubTargetType, "SubTargetType");
      atexit(UFG::SubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symSubTargetType__);
    }
    v5 = UFG::qPropertySet::Get<UFG::qSymbolUC>(v2, &symBoneName, DEPTH_RECURSE);
    v6 = UFG::qPropertySet::Get<UFG::qVector3>(v2, &symOffset, DEPTH_RECURSE);
    v7 = UFG::qPropertySet::Get<float>(v2, &symAccuracyRate, DEPTH_RECURSE);
    v8 = UFG::qPropertySet::Get<float>(v2, &symAccuracyPenalty, DEPTH_RECURSE);
    v9 = UFG::qPropertySet::Get<float>(v2, &symRadius, DEPTH_RECURSE);
    v10 = UFG::qPropertySet::Get<UFG::qSymbol>(v2, &symSubTargetType, DEPTH_RECURSE);
    v11 = &UFG::gNullQSymbolUC;
    if ( v5 )
      v11 = v5;
    v3->m_symBoneName = (UFG::qSymbolUC)v11->mUID;
    v12 = &UFG::qVector3::msZero;
    if ( v6 )
      v12 = v6;
    v13 = v12->y;
    v14 = v12->z;
    v3->m_vOffset.x = v12->x;
    v3->m_vOffset.y = v13;
    v3->m_vOffset.z = v14;
    v15 = FLOAT_N1_0;
    if ( v7 )
      v16 = *v7;
    else
      v16 = FLOAT_N1_0;
    v3->m_fAccuracyRate = v16;
    if ( v8 )
      v17 = *v8;
    else
      v17 = FLOAT_N1_0;
    v3->m_fAccuracyPenalty = v17;
    if ( v9 )
      v15 = *v9;
    v3->m_fRadius = v15;
    if ( v10 )
    {
      pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.m_EnumSymbol.mUID = -1;
      pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v10->mUID;
      *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
      pTrackEnumBinding.m_uEnumUID = 0;
      if ( UFG::gTargetTypeEnum.m_enumLists.size )
      {
        TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
      }
      else
      {
        v18 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
        UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
        pTrackEnumBinding.mPrev = v18;
        pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
        UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      }
      v3->m_eTargetType = pTrackEnumBinding.m_EnumValue;
      v19 = pTrackEnumBinding.mPrev;
      v20 = pTrackEnumBinding.mNext;
      pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
      v20->mPrev = v19;
      pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    else
    {
      v3->m_eTargetType = 0;
    }
  }
}

// File Line: 93
// RVA: 0x1543900
__int64 dynamic_initializer_for__UFG::SubTargetingLocations::ms_SubTargetingLocationPool__()
{
  `eh vector constructor iterator(
    UFG::SubTargetingLocations::ms_SubTargetingLocationPool.p,
    0x40ui64,
    32,
    (void (__fastcall *)(void *))UFG::SubTargetingLocation::SubTargetingLocation);
  UFG::SubTargetingLocations::ms_SubTargetingLocationPool.size = 0;
  return atexit(dynamic_atexit_destructor_for__UFG::SubTargetingLocations::ms_SubTargetingLocationPool__);
}

// File Line: 94
// RVA: 0x1543950
__int64 dynamic_initializer_for__UFG::SubTargetingLocations::ms_SubTargetingLocations__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::SubTargetingLocations::ms_SubTargetingLocations.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::SubTargetingLocations::ms_SubTargetingLocations__);
}

// File Line: 97
// RVA: 0x550260
void UFG::SubTargetingLocations::StaticInit(void)
{
  UFG::qPropertySet *v0; // rbx
  UFG::qPropertyList *v1; // rax
  UFG::qPropertyList *v2; // rbp
  unsigned int v3; // esi
  unsigned int v4; // edi
  UFG::qSymbol *v5; // rax
  UFG::qSymbolUC *v6; // rbx
  UFG::qPropertySet *v7; // rax
  unsigned int v8; // ecx
  UFG::qBaseNodeRB *v9; // rbx
  char *v10; // rax
  char *v11; // rax
  char *v12; // rax
  char *v13; // rax
  UFG::qSymbol name; // [rsp+40h] [rbp+8h]
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  UFG::qSymbol::create_from_string(&result, "Targeting-SubTargetingProfiles-Locations-manifest");
  v0 = UFG::PropertySetManager::GetPropertySet(&result);
  if ( v0 )
  {
    UFG::qSymbol::create_from_string(&name, "archetypes");
    v1 = UFG::qPropertySet::Get<UFG::qPropertyList>(v0, &name, DEPTH_RECURSE);
    v2 = v1;
    if ( v1 )
    {
      v3 = v1->mNumElements;
      v4 = 0;
      if ( v3 )
      {
        do
        {
          v5 = UFG::qPropertyList::Get<UFG::qSymbol>(v2, v4);
          v6 = (UFG::qSymbolUC *)v5;
          if ( v5 )
          {
            v7 = UFG::PropertySetManager::GetPropertySet(v5);
            if ( v7 )
            {
              v8 = UFG::SubTargetingLocations::ms_SubTargetingLocationPool.size;
              if ( UFG::SubTargetingLocations::ms_SubTargetingLocationPool.size >= 0x20 )
              {
                v10 = UFG::qSymbol::as_cstr_dbg(v6);
                UFG::qPrintf(
                  "WARNING: SubTargetingLocation::StaticInit: Pool is Full (%d) Not Adding (%s)\n",
                  32i64,
                  v10);
              }
              else
              {
                ++UFG::SubTargetingLocations::ms_SubTargetingLocationPool.size;
                v9 = &UFG::SubTargetingLocations::ms_SubTargetingLocationPool.p[(unsigned __int64)v8].mNode;
                UFG::SubTargetingLocation::InitFromPropertySet(
                  &UFG::SubTargetingLocations::ms_SubTargetingLocationPool.p[(unsigned __int64)v8],
                  v7);
                UFG::qBaseTreeRB::Add(&UFG::SubTargetingLocations::ms_SubTargetingLocations.mTree, v9);
              }
            }
            else
            {
              v11 = UFG::qSymbol::as_cstr_dbg(v6);
              UFG::qPrintf("WARNING: SubTargetingLocation::StaticInit: Profile Not Found: %s\n", v11);
            }
          }
          ++v4;
        }
        while ( v4 < v3 );
      }
    }
    else
    {
      v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name);
      UFG::qPrintf("WARNING: SubTargetingLocation::StaticInit: Property List Not Found: %s\n", v12);
    }
  }
  else
  {
    v13 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&result);
    UFG::qPrintf("WARNING: SubTargetingLocation::StaticInit: Manifest File Not Found: %s\n", v13);
  }
}

