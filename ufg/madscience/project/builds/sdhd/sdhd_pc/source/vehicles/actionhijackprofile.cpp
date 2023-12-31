// File Line: 42
// RVA: 0x67DBA0
void __fastcall UFG::ActionHijackProfile::InitFromPropertySet(
        UFG::ActionHijackProfile *this,
        UFG::qPropertySet *pActionHijackProfilePropertySet)
{
  unsigned int v4; // eax
  float *v5; // rsi
  float *v6; // rbp
  float *v7; // r14
  float *v8; // r15
  bool *v9; // r13
  bool *v10; // r12
  bool *v11; // rcx
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  bool v19; // al
  bool v20; // al
  bool v21; // al
  float *v22; // [rsp+78h] [rbp+10h]
  float *v23; // [rsp+80h] [rbp+18h]
  float *v24; // [rsp+88h] [rbp+20h]

  if ( pActionHijackProfilePropertySet )
  {
    this->mNode.mUID = pActionHijackProfilePropertySet->mName.mUID;
    v4 = _S23_3;
    if ( (_S23_3 & 1) == 0 )
    {
      _S23_3 |= 1u;
      UFG::qSymbol::create_from_string(&symDistanceAheadOfTargetMax, "DistanceAheadOfTargetMax");
      atexit(UFG::ActionHijackProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symDistanceAheadOfTargetMax__);
      v4 = _S23_3;
    }
    if ( (v4 & 2) == 0 )
    {
      _S23_3 = v4 | 2;
      UFG::qSymbol::create_from_string(&symDistanceBehindTargetMax, "DistanceBehindTargetMax");
      atexit(UFG::ActionHijackProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symDistanceBehindTargetMax__);
      v4 = _S23_3;
    }
    if ( (v4 & 4) == 0 )
    {
      _S23_3 = v4 | 4;
      UFG::qSymbol::create_from_string(&symDistanceToSideMax, "DistanceToSideMax");
      atexit(UFG::ActionHijackProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symDistanceToSideMax__);
      v4 = _S23_3;
    }
    if ( (v4 & 8) == 0 )
    {
      _S23_3 = v4 | 8;
      UFG::qSymbol::create_from_string(
        &symSpeedDifferenceModifiesDistanceAheadStart,
        "SpeedDifferenceModifiesDistanceAheadStart");
      atexit(UFG::ActionHijackProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symSpeedDifferenceModifiesDistanceAheadStart__);
      v4 = _S23_3;
    }
    if ( (v4 & 0x10) == 0 )
    {
      _S23_3 = v4 | 0x10;
      UFG::qSymbol::create_from_string(
        &symSpeedDifferenceModifiesDistanceAheadEnd,
        "SpeedDifferenceModifiesDistanceAheadEnd");
      atexit(UFG::ActionHijackProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symSpeedDifferenceModifiesDistanceAheadEnd__);
      v4 = _S23_3;
    }
    if ( (v4 & 0x20) == 0 )
    {
      _S23_3 = v4 | 0x20;
      UFG::qSymbol::create_from_string(&symOrientationDeltaRadMax, "OrientationDeltaRadMax");
      atexit(UFG::ActionHijackProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symOrientationDeltaRadMax__);
      v4 = _S23_3;
    }
    if ( (v4 & 0x40) == 0 )
    {
      _S23_3 = v4 | 0x40;
      UFG::qSymbol::create_from_string(&symVehicleSpeedMinKPH, "VehicleSpeedMinKPH");
      atexit(UFG::ActionHijackProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symVehicleSpeedMinKPH__);
      v4 = _S23_3;
    }
    if ( (v4 & 0x80u) == 0 )
    {
      _S23_3 = v4 | 0x80;
      UFG::qSymbol::create_from_string(&symCanActionHijackFrom, "CanActionHijackFrom");
      atexit(UFG::ActionHijackProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symCanActionHijackFrom__);
      v4 = _S23_3;
    }
    if ( (v4 & 0x100) == 0 )
    {
      _S23_3 = v4 | 0x100;
      UFG::qSymbol::create_from_string(&symCanActionHijackTo, "CanActionHijackTo");
      atexit(UFG::ActionHijackProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symCanActionHijackTo__);
      v4 = _S23_3;
    }
    if ( (v4 & 0x200) == 0 )
    {
      _S23_3 = v4 | 0x200;
      UFG::qSymbol::create_from_string(&symCanActionHijackClimb, "CanActionHijackClimb");
      atexit(UFG::ActionHijackProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symCanActionHijackClimb__);
    }
    v22 = UFG::qPropertySet::Get<float>(
            pActionHijackProfilePropertySet,
            (UFG::qArray<unsigned long,0> *)&symDistanceAheadOfTargetMax,
            DEPTH_RECURSE);
    v5 = UFG::qPropertySet::Get<float>(
           pActionHijackProfilePropertySet,
           (UFG::qArray<unsigned long,0> *)&symDistanceBehindTargetMax,
           DEPTH_RECURSE);
    v6 = UFG::qPropertySet::Get<float>(
           pActionHijackProfilePropertySet,
           (UFG::qArray<unsigned long,0> *)&symDistanceToSideMax,
           DEPTH_RECURSE);
    v7 = UFG::qPropertySet::Get<float>(
           pActionHijackProfilePropertySet,
           (UFG::qArray<unsigned long,0> *)&symSpeedDifferenceModifiesDistanceAheadStart,
           DEPTH_RECURSE);
    v8 = UFG::qPropertySet::Get<float>(
           pActionHijackProfilePropertySet,
           (UFG::qArray<unsigned long,0> *)&symSpeedDifferenceModifiesDistanceAheadEnd,
           DEPTH_RECURSE);
    v23 = UFG::qPropertySet::Get<float>(
            pActionHijackProfilePropertySet,
            (UFG::qArray<unsigned long,0> *)&symOrientationDeltaRadMax,
            DEPTH_RECURSE);
    v24 = UFG::qPropertySet::Get<float>(
            pActionHijackProfilePropertySet,
            (UFG::qArray<unsigned long,0> *)&symVehicleSpeedMinKPH,
            DEPTH_RECURSE);
    v9 = UFG::qPropertySet::Get<bool>(
           pActionHijackProfilePropertySet,
           (UFG::qArray<unsigned long,0> *)&symCanActionHijackFrom,
           DEPTH_RECURSE);
    v10 = UFG::qPropertySet::Get<bool>(
            pActionHijackProfilePropertySet,
            (UFG::qArray<unsigned long,0> *)&symCanActionHijackTo,
            DEPTH_RECURSE);
    v11 = UFG::qPropertySet::Get<bool>(
            pActionHijackProfilePropertySet,
            (UFG::qArray<unsigned long,0> *)&symCanActionHijackClimb,
            DEPTH_RECURSE);
    v12 = FLOAT_N1_0;
    if ( v22 )
      v13 = *v22 * *v22;
    else
      v13 = FLOAT_N1_0;
    this->m_fDistanceAheadOfTargetMax = v13;
    if ( v5 )
      v14 = *v5;
    else
      v14 = FLOAT_N1_0;
    this->m_fDistanceBehindTargetMax = v14;
    if ( v6 )
      v15 = *v6;
    else
      v15 = FLOAT_N1_0;
    this->m_fDistanceToSideMax = v15;
    if ( v7 )
      v16 = *v7;
    else
      v16 = FLOAT_N1_0;
    this->m_fSpeedDifferenceModifiesDistanceAheadStart = v16;
    if ( v8 )
      v17 = *v8;
    else
      v17 = FLOAT_N1_0;
    this->m_fSpeedDifferenceModifiesDistanceAheadEnd = v17;
    if ( v23 )
      v18 = (float)(*v23 * 3.1415927) * 0.0055555557;
    else
      v18 = FLOAT_N1_0;
    this->m_fOrientationDeltaRadMax = v18;
    if ( v24 )
      v12 = *v24;
    this->m_fVehicleSpeedMinKPH = v12;
    if ( v9 )
      v19 = *v9;
    else
      v19 = 0;
    this->m_bCanActionHijackFrom = v19;
    if ( v10 )
      v20 = *v10;
    else
      v20 = 0;
    this->m_bCanActionHijackTo = v20;
    if ( v11 )
      v21 = *v11;
    else
      v21 = 0;
    this->m_bCanActionHijackClimb = v21;
  }
}

// File Line: 95
// RVA: 0x67A460
float __fastcall UFG::ActionHijackProfile::GetDistanceSquaredMax(UFG::ActionHijackProfile *this)
{
  float ActionHijackDistanceMultiplier; // xmm0_4
  float m_fDistanceAheadOfTargetMax; // xmm6_4
  float v4; // xmm0_4
  float v5; // xmm0_4

  ActionHijackDistanceMultiplier = UFG::PlayerBuffTracker::GetActionHijackDistanceMultiplier();
  m_fDistanceAheadOfTargetMax = this->m_fDistanceAheadOfTargetMax;
  v4 = ActionHijackDistanceMultiplier * this->m_fDistanceBehindTargetMax;
  if ( m_fDistanceAheadOfTargetMax <= v4 )
    m_fDistanceAheadOfTargetMax = v4;
  v5 = UFG::PlayerBuffTracker::GetActionHijackDistanceMultiplier();
  return (float)((float)(v5 * this->m_fDistanceToSideMax) * (float)(v5 * this->m_fDistanceToSideMax))
       + (float)(m_fDistanceAheadOfTargetMax * m_fDistanceAheadOfTargetMax);
}

// File Line: 105
// RVA: 0x67A440
float __fastcall UFG::ActionHijackProfile::GetDistanceBehindTargetMax(UFG::ActionHijackProfile *this)
{
  return UFG::PlayerBuffTracker::GetActionHijackDistanceMultiplier() * this->m_fDistanceBehindTargetMax;
}

// File Line: 112
// RVA: 0x67A4B0
float __fastcall UFG::ActionHijackProfile::GetDistanceToSideMax(UFG::ActionHijackProfile *this)
{
  return UFG::PlayerBuffTracker::GetActionHijackDistanceMultiplier() * this->m_fDistanceToSideMax;
}

// File Line: 143
// RVA: 0x157AFD0
__int64 dynamic_initializer_for__UFG::ActionHijackProfiles::ms_ActionHijackProfilePool__()
{
  `eh vector constructor iterator(
    (char *)UFG::ActionHijackProfiles::ms_ActionHijackProfilePool.p,
    0x40ui64,
    10,
    (void (__fastcall *)(void *))hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>);
  UFG::ActionHijackProfiles::ms_ActionHijackProfilePool.size = 0;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ActionHijackProfiles::ms_ActionHijackProfilePool__);
}

// File Line: 145
// RVA: 0x157B020
__int64 dynamic_initializer_for__UFG::ActionHijackProfiles::ms_ActionHijackProfiles__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::ActionHijackProfiles::ms_ActionHijackProfiles.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ActionHijackProfiles::ms_ActionHijackProfiles__);
}

// File Line: 148
// RVA: 0x68C690
void UFG::ActionHijackProfiles::StaticInit(void)
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
  UFG::ActionHijackProfile *v9; // rbx
  char *v10; // rax
  char *v11; // rax
  char *v12; // rax
  char *v13; // rax
  UFG::qArray<unsigned long,0> name; // [rsp+40h] [rbp+8h] BYREF

  UFG::qSymbol::create_from_string((UFG::qSymbol *)&name.p, "Vehicles-ActionHijackProfile-manifest");
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
            size = UFG::ActionHijackProfiles::ms_ActionHijackProfilePool.size;
            if ( UFG::ActionHijackProfiles::ms_ActionHijackProfilePool.size >= 0xA )
            {
              v10 = UFG::qSymbol::as_cstr_dbg(v6);
              UFG::qPrintf("WARNING: ActionHijackProfile::StaticInit: Pool is Full (%d) Not Adding (%s)\n", 10i64, v10);
            }
            else
            {
              ++UFG::ActionHijackProfiles::ms_ActionHijackProfilePool.size;
              v9 = &UFG::ActionHijackProfiles::ms_ActionHijackProfilePool.p[(unsigned __int64)size];
              UFG::ActionHijackProfile::InitFromPropertySet(v9, v7);
              UFG::qBaseTreeRB::Add(&UFG::ActionHijackProfiles::ms_ActionHijackProfiles.mTree, &v9->mNode);
            }
          }
          else
          {
            v11 = UFG::qSymbol::as_cstr_dbg(v6);
            UFG::qPrintf("WARNING: ActionHijackProfile::StaticInit: Action Hijack Profile Not Found: %s\n", v11);
          }
        }
      }
    }
    else
    {
      v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name);
      UFG::qPrintf("WARNING: ActionHijackProfile::StaticInit: Property List Not Found: %s\n", v12);
    }
  }
  else
  {
    v13 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name.p);
    UFG::qPrintf("WARNING: ActionHijackProfile::StaticInit: Manifest File Not Found: %s\n", v13);
  }
}

