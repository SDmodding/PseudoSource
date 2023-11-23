// File Line: 23
// RVA: 0x5379B0
void __fastcall UFG::SubTargetingLocation::InitFromPropertySet(
        UFG::SubTargetingLocation *this,
        UFG::qPropertySet *pSubTargetingLocationPropertySet)
{
  unsigned int v4; // eax
  UFG::qSymbolUC *v5; // rbx
  UFG::qVector3 *v6; // rdi
  float *v7; // r13
  float *v8; // r12
  float *v9; // r15
  UFG::qSymbol *v10; // rax
  UFG::qSymbolUC *v11; // rcx
  UFG::qVector3 *v12; // rcx
  float y; // xmm1_4
  float z; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v19; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF

  if ( pSubTargetingLocationPropertySet )
  {
    this->mNode.mUID = pSubTargetingLocationPropertySet->mName.mUID;
    v4 = _S47;
    if ( (_S47 & 1) == 0 )
    {
      _S47 |= 1u;
      UFG::qSymbol::create_from_string(&symBoneName, "BoneName");
      atexit(UFG::SubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symBoneName__);
      v4 = _S47;
    }
    if ( (v4 & 2) == 0 )
    {
      _S47 = v4 | 2;
      UFG::qSymbol::create_from_string(&symOffset, "Offset");
      atexit(UFG::SubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symOffset__);
      v4 = _S47;
    }
    if ( (v4 & 4) == 0 )
    {
      _S47 = v4 | 4;
      UFG::qSymbol::create_from_string(&symAccuracyRate, "AccuracyRate");
      atexit(UFG::SubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symAccuracyRate__);
      v4 = _S47;
    }
    if ( (v4 & 8) == 0 )
    {
      _S47 = v4 | 8;
      UFG::qSymbol::create_from_string(&symAccuracyPenalty, "AccuracyPenalty");
      atexit(UFG::SubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symAccuracyPenalty__);
      v4 = _S47;
    }
    if ( (v4 & 0x10) == 0 )
    {
      _S47 = v4 | 0x10;
      UFG::qSymbol::create_from_string(&symRadius, "Radius");
      atexit(UFG::SubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symRadius__);
      v4 = _S47;
    }
    if ( (v4 & 0x20) == 0 )
    {
      _S47 = v4 | 0x20;
      UFG::qSymbol::create_from_string(&symSubTargetType, "SubTargetType");
      atexit(UFG::SubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symSubTargetType__);
    }
    v5 = UFG::qPropertySet::Get<UFG::qSymbolUC>(
           pSubTargetingLocationPropertySet,
           (UFG::qArray<unsigned long,0> *)&symBoneName,
           DEPTH_RECURSE);
    v6 = UFG::qPropertySet::Get<UFG::qVector3>(
           pSubTargetingLocationPropertySet,
           (UFG::qArray<unsigned long,0> *)&symOffset,
           DEPTH_RECURSE);
    v7 = UFG::qPropertySet::Get<float>(
           pSubTargetingLocationPropertySet,
           (UFG::qArray<unsigned long,0> *)&symAccuracyRate,
           DEPTH_RECURSE);
    v8 = UFG::qPropertySet::Get<float>(
           pSubTargetingLocationPropertySet,
           (UFG::qArray<unsigned long,0> *)&symAccuracyPenalty,
           DEPTH_RECURSE);
    v9 = UFG::qPropertySet::Get<float>(
           pSubTargetingLocationPropertySet,
           (UFG::qArray<unsigned long,0> *)&symRadius,
           DEPTH_RECURSE);
    v10 = UFG::qPropertySet::Get<UFG::qSymbol>(
            pSubTargetingLocationPropertySet,
            (UFG::qArray<unsigned long,0> *)&symSubTargetType,
            DEPTH_RECURSE);
    v11 = &UFG::gNullQSymbolUC;
    if ( v5 )
      v11 = v5;
    this->m_symBoneName = (UFG::qSymbolUC)v11->mUID;
    v12 = &UFG::qVector3::msZero;
    if ( v6 )
      v12 = v6;
    y = v12->y;
    z = v12->z;
    this->m_vOffset.x = v12->x;
    this->m_vOffset.y = y;
    this->m_vOffset.z = z;
    v15 = FLOAT_N1_0;
    if ( v7 )
      v16 = *v7;
    else
      v16 = FLOAT_N1_0;
    this->m_fAccuracyRate = v16;
    if ( v8 )
      v17 = *v8;
    else
      v17 = FLOAT_N1_0;
    this->m_fAccuracyPenalty = v17;
    if ( v9 )
      v15 = *v9;
    this->m_fRadius = v15;
    if ( v10 )
    {
      pTrackEnumBinding.mPrev = &pTrackEnumBinding;
      pTrackEnumBinding.mNext = &pTrackEnumBinding;
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
        mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
        UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
        pTrackEnumBinding.mPrev = mPrev;
        pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
        UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
      }
      this->m_eTargetType = pTrackEnumBinding.m_EnumValue;
      v19 = pTrackEnumBinding.mPrev;
      mNext = pTrackEnumBinding.mNext;
      pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
      mNext->mPrev = v19;
      pTrackEnumBinding.mPrev = &pTrackEnumBinding;
      pTrackEnumBinding.mNext = &pTrackEnumBinding;
    }
    else
    {
      this->m_eTargetType = eTARGET_TYPE_INVALID;
    }
  }
}

// File Line: 93
// RVA: 0x1543900
__int64 dynamic_initializer_for__UFG::SubTargetingLocations::ms_SubTargetingLocationPool__()
{
  `eh vector constructor iterator(
    (char *)UFG::SubTargetingLocations::ms_SubTargetingLocationPool.p,
    0x40ui64,
    32,
    (void (__fastcall *)(void *))UFG::SubTargetingLocation::SubTargetingLocation);
  UFG::SubTargetingLocations::ms_SubTargetingLocationPool.size = 0;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SubTargetingLocations::ms_SubTargetingLocationPool__);
}

// File Line: 94
// RVA: 0x1543950
__int64 dynamic_initializer_for__UFG::SubTargetingLocations::ms_SubTargetingLocations__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::SubTargetingLocations::ms_SubTargetingLocations.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SubTargetingLocations::ms_SubTargetingLocations__);
}

// File Line: 97
// RVA: 0x550260
void UFG::SubTargetingLocations::StaticInit(void)
{
  UFG::qPropertySet *PropertySet; // rbx
  UFG::qPropertyList *v1; // rax
  UFG::qPropertyList *v2; // rbp
  unsigned int mNumElements; // esi
  unsigned int i; // edi
  UFG::qSymbol *v5; // rax
  UFG::qSymbolUC *v6; // rbx
  UFG::qPropertySet *v7; // rax
  unsigned int size; // ecx
  UFG::SubTargetingLocation *v9; // rbx
  char *v10; // rax
  char *v11; // rax
  char *v12; // rax
  char *v13; // rax
  UFG::qArray<unsigned long,0> name; // [rsp+40h] [rbp+8h] BYREF

  UFG::qSymbol::create_from_string((UFG::qSymbol *)&name.p, "Targeting-SubTargetingProfiles-Locations-manifest");
  PropertySet = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&name.p);
  if ( PropertySet )
  {
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&name, "archetypes");
    v1 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, &name, DEPTH_RECURSE);
    v2 = v1;
    if ( v1 )
    {
      mNumElements = v1->mNumElements;
      for ( i = 0; i < mNumElements; ++i )
      {
        v5 = UFG::qPropertyList::Get<UFG::qSymbol>(v2, i);
        v6 = (UFG::qSymbolUC *)v5;
        if ( v5 )
        {
          v7 = UFG::PropertySetManager::GetPropertySet(v5);
          if ( v7 )
          {
            size = UFG::SubTargetingLocations::ms_SubTargetingLocationPool.size;
            if ( UFG::SubTargetingLocations::ms_SubTargetingLocationPool.size >= 0x20 )
            {
              v10 = UFG::qSymbol::as_cstr_dbg(v6);
              UFG::qPrintf("WARNING: SubTargetingLocation::StaticInit: Pool is Full (%d) Not Adding (%s)\n", 32i64, v10);
            }
            else
            {
              ++UFG::SubTargetingLocations::ms_SubTargetingLocationPool.size;
              v9 = &UFG::SubTargetingLocations::ms_SubTargetingLocationPool.p[(unsigned __int64)size];
              UFG::SubTargetingLocation::InitFromPropertySet(v9, v7);
              UFG::qBaseTreeRB::Add(&UFG::SubTargetingLocations::ms_SubTargetingLocations.mTree, &v9->mNode);
            }
          }
          else
          {
            v11 = UFG::qSymbol::as_cstr_dbg(v6);
            UFG::qPrintf("WARNING: SubTargetingLocation::StaticInit: Profile Not Found: %s\n", v11);
          }
        }
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
    v13 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name.p);
    UFG::qPrintf("WARNING: SubTargetingLocation::StaticInit: Manifest File Not Found: %s\n", v13);
  }
}

