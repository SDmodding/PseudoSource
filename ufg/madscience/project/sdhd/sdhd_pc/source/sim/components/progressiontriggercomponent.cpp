// File Line: 39
// RVA: 0x154CA60
__int64 UFG::_dynamic_initializer_for__smProgressionTriggerComponent_UpdateList__()
{
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__smProgressionTriggerComponent_UpdateList__);
}

// File Line: 51
// RVA: 0x1543FC0
__int64 dynamic_initializer_for__UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentList__);
}

// File Line: 52
// RVA: 0x52CAC0
UFG::ComponentIDDesc *__fastcall UFG::ProgressionTriggerComponent::GetDesc(UFG::ProgressionTriggerComponent *this)
{
  return &UFG::ProgressionTriggerComponent::_TypeIDesc;
}

// File Line: 66
// RVA: 0x5186C0
void __fastcall UFG::ProgressionTriggerComponent::ProgressionTriggerComponent(
        UFG::ProgressionTriggerComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent>::mPrev = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent>;
  this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent>::mNext = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent>;
  this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mPrev = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>;
  this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mNext = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ProgressionTriggerComponent::`vftable;
  this->mpGameSlice = 0i64;
  this->mCallTimeout = 0i64;
  this->mCallFailTimeout = 0i64;
  *(_DWORD *)&this->mInsideActiveRegion = 0;
  *(_WORD *)&this->mRequiresTODWait = 0;
  this->mpRegionSceneObjects[0] = 0i64;
  this->mpTriggerRegions[0] = 0i64;
  this->mpRegionSceneObjects[1] = 0i64;
  this->mpTriggerRegions[1] = 0i64;
  this->mpRegionSceneObjects[2] = 0i64;
  this->mpTriggerRegions[2] = 0i64;
  this->mpRegionSceneObjects[3] = 0i64;
  this->mpTriggerRegions[3] = 0i64;
  this->mpRegionSceneObjects[4] = 0i64;
  this->mpTriggerRegions[4] = 0i64;
  mPrev = UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentList.mNode.mPrev;
  UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent>;
  this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent>::mNext = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *)&UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentList;
  UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentList.mNode.mPrev = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::ProgressionTriggerComponent::_ProgressionTriggerComponentTypeUID,
    "ProgressionTriggerComponent");
}

// File Line: 79
// RVA: 0x51C250
void __fastcall UFG::ProgressionTriggerComponent::~ProgressionTriggerComponent(UFG::ProgressionTriggerComponent *this)
{
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *v2; // rsi
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *mPrev; // rcx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *mNext; // rax
  UFG::SceneObjectProperties **mpRegionSceneObjects; // rbx
  __int64 v6; // rbp
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v7; // rcx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v8; // rax
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *v9; // rcx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *v10; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ProgressionTriggerComponent::`vftable;
  if ( this == UFG::gpCurrentProgressionTriggerComponent )
    UFG::gpCurrentProgressionTriggerComponent = (UFG::ProgressionTriggerComponent *)&UFG::gpCurrentProgressionTriggerComponent->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mPrev[-5];
  if ( this == UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentpCurrentIterator )
    UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentpCurrentIterator = (UFG::ProgressionTriggerComponent *)&this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent>::mPrev[-4];
  v2 = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent>;
  mPrev = this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  if ( this->mRegionsCreated )
  {
    mpRegionSceneObjects = this->mpRegionSceneObjects;
    v6 = 5i64;
    do
    {
      UFG::SceneObjectProperties::Deactivate(*mpRegionSceneObjects);
      *mpRegionSceneObjects++ = 0i64;
      --v6;
    }
    while ( v6 );
    this->mRegionsCreated = 0;
  }
  v7 = this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mPrev;
  v8 = this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mPrev = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>;
  this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mNext = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>;
  v9 = v2->mPrev;
  v10 = v2->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 101
// RVA: 0x55C1E0
void __fastcall UFG::ProgressionTriggerComponent::Update(UFG::ProgressionTriggerComponent *this, float deltaTime)
{
  UFG::PDATriggerParameters *mPDATriggerParameters; // rbp
  char v4; // si
  UFG::SimObjectCharacter *LocalPlayer; // rax
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *ComponentOfType; // rbx
  unsigned int v8; // edx
  unsigned int v9; // r9d
  __int64 v10; // rbx
  unsigned int mComponentTableEntryCount; // edx
  unsigned int size; // r9d
  unsigned int v13; // edx
  unsigned int v14; // r9d
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::SimObject *m_pSimObject; // rcx
  unsigned __int64 mCallTimeout; // rax
  unsigned __int64 mSimTimeMSec; // rbx
  UFG::UIHK_PDAWidget *v19; // rax
  UFG::UIHK_PDAWidget *v20; // rax
  unsigned __int64 mCallFailTimeout; // rcx
  unsigned __int64 v22; // rax
  UFG::GameSliceStreamer *v23; // rax

  if ( !this->mEnabled )
    return;
  mPDATriggerParameters = this->mpGameSlice->mPDATriggerParameters;
  if ( !mPDATriggerParameters || !mPDATriggerParameters->mIncoming )
    return;
  v4 = 0;
  if ( mPDATriggerParameters->mVehicleFilter.mUID == -1 )
    goto LABEL_36;
  LocalPlayer = UFG::GetLocalPlayer();
  if ( !LocalPlayer )
    goto LABEL_37;
  m_Flags = LocalPlayer->m_Flags;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        mComponentTableEntryCount = LocalPlayer->mComponentTableEntryCount;
        size = LocalPlayer->m_Components.size;
        if ( mComponentTableEntryCount < size )
        {
          v10 = (__int64)&LocalPlayer->m_Components.p[mComponentTableEntryCount];
          while ( (*(_DWORD *)(v10 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v10 + 8) & 0x1FFFFFF) != 0 )
          {
            ++mComponentTableEntryCount;
            v10 += 16i64;
            if ( mComponentTableEntryCount >= size )
            {
              ComponentOfType = 0i64;
              goto LABEL_31;
            }
          }
          goto LABEL_15;
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                 LocalPlayer,
                                                                 UFG::CharacterOccupantComponent::_TypeUID);
          goto LABEL_31;
        }
        v13 = LocalPlayer->mComponentTableEntryCount;
        v14 = LocalPlayer->m_Components.size;
        if ( v13 < v14 )
        {
          v10 = (__int64)&LocalPlayer->m_Components.p[v13];
          while ( (*(_DWORD *)(v10 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v10 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v13;
            v10 += 16i64;
            if ( v13 >= v14 )
            {
              ComponentOfType = 0i64;
              goto LABEL_31;
            }
          }
          goto LABEL_15;
        }
      }
    }
    else
    {
      v8 = LocalPlayer->mComponentTableEntryCount;
      v9 = LocalPlayer->m_Components.size;
      if ( v8 < v9 )
      {
        v10 = (__int64)&LocalPlayer->m_Components.p[v8];
        while ( (*(_DWORD *)(v10 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
             || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v10 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v8;
          v10 += 16i64;
          if ( v8 >= v9 )
            goto LABEL_14;
        }
LABEL_15:
        ComponentOfType = *(UFG::CharacterOccupantComponent **)v10;
        goto LABEL_31;
      }
    }
LABEL_14:
    ComponentOfType = 0i64;
    goto LABEL_31;
  }
  ComponentOfType = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent;
LABEL_31:
  if ( ComponentOfType )
  {
    if ( !UFG::CharacterOccupantComponent::IsEnteringOrExiting(ComponentOfType) )
    {
      m_pSimComponent = ComponentOfType->mCurrentVOC.m_pSimComponent;
      if ( m_pSimComponent )
      {
        m_pSimObject = m_pSimComponent->m_pSimObject;
        if ( m_pSimObject )
        {
          if ( UFG::SimObjectUtility::IsClassType(m_pSimObject, &mPDATriggerParameters->mVehicleFilter) )
LABEL_36:
            v4 = 1;
        }
      }
    }
  }
LABEL_37:
  mCallTimeout = this->mCallTimeout;
  mSimTimeMSec = UFG::Metrics::msInstance.mSimTimeMSec;
  if ( mCallTimeout )
  {
    if ( UFG::Metrics::msInstance.mSimTimeMSec > mCallTimeout || !v4 )
    {
      UFG::ProgressionTriggerComponent::DisablePDATrigger(this->mpGameSlice);
      UFG::ProgressionTriggerComponent::UnloadScripts(this);
      this->mCallFailTimeout = mSimTimeMSec + 10000;
      return;
    }
    v19 = UFG::UIHK_PDAWidget::Get();
    if ( v19 && UFG::UIHK_PDAWidget::HasAnswered(v19) )
    {
      UFG::ProgressionTriggerComponent::OnActivate(this);
LABEL_50:
      v23 = UFG::GameSliceStreamer::Instance();
      UFG::GameSliceStreamer::RequestStream(
        v23,
        (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)this->mpGameSlice);
    }
  }
  else if ( this->mInsideActiveRegion )
  {
    v20 = UFG::UIHK_PDAWidget::Get();
    if ( v20 )
    {
      if ( v4 )
      {
        mCallFailTimeout = this->mCallFailTimeout;
        if ( !mCallFailTimeout || mSimTimeMSec > mCallFailTimeout )
        {
          UFG::UIHK_PDAWidget::QueueIncomingPhoneCall(v20, mPDATriggerParameters->mContactName.mData, 0, 0, 0);
          v22 = UFG::Metrics::msInstance.mSimTimeMSec;
          this->mCallFailTimeout = 0i64;
          this->mCallTimeout = v22 + 15000;
          goto LABEL_50;
        }
      }
    }
  }
}

// File Line: 181
// RVA: 0x55E330
void __fastcall UFG::ProgressionTriggerComponent::UpdateAll(float deltaTime)
{
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v1; // rcx

  v1 = smProgressionTriggerComponent_UpdateList.mNode.mNext - 5;
  for ( UFG::gpCurrentProgressionTriggerComponent = (UFG::ProgressionTriggerComponent *)&smProgressionTriggerComponent_UpdateList.mNode.mNext[-5];
        v1 != (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *)(&smProgressionTriggerComponent_UpdateList
                                                                             - 5);
        UFG::gpCurrentProgressionTriggerComponent = (UFG::ProgressionTriggerComponent *)v1 )
  {
    ((void (__fastcall *)(UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *))v1->mPrev[7].mPrev)(v1);
    v1 = UFG::gpCurrentProgressionTriggerComponent->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mNext
       - 5;
  }
  UFG::gpCurrentProgressionTriggerComponent = 0i64;
}

// File Line: 202
// RVA: 0x5249F0
void __fastcall UFG::ProgressionTriggerComponent::CreateRegions(
        UFG::ProgressionTriggerComponent *this,
        UFG::TransformNodeComponent *pTransformNode)
{
  UFG::SimObjectCharacter *LocalPlayer; // rdi
  UFG::SceneObjectProperties *m_pSceneObj; // rbx
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *v8; // rcx
  UFG::qPropertySet *PropertySet; // r13
  float *v10; // rsi
  UFG::SceneObjectProperties **mpRegionSceneObjects; // rdi
  __int64 v12; // r14
  UFG::SceneObjectProperties *v13; // rax
  UFG::qPropertySet *WritableProperties; // rax
  UFG::qPropertySet *appended; // rbx
  UFG::SimObject *m_pSimObject; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rcx
  __int16 m_Flags; // cx
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  UFG::SimComponentHolder *p; // rbx
  __int64 v22; // rdx
  UFG::SimComponent *ComponentOfType; // rbx
  unsigned int v24; // r8d
  unsigned int v25; // r10d
  unsigned int v26; // r8d
  unsigned int v27; // r10d
  unsigned int v28; // r8d
  unsigned int v29; // r10d
  hkSeekableStreamReader *RCX; // rax
  hkSeekableStreamReader *v31; // rax
  __int64 i; // rsi
  UFG::TriggerRegion *v33; // rbx
  UFG::SimObject *v34; // rcx
  __int16 v35; // dx
  unsigned int v36; // r8d
  unsigned int v37; // r10d
  UFG::SimComponentHolder *v38; // rbx
  __int64 v39; // rdx
  UFG::RegionComponent *m_pComponent; // rbx
  unsigned int v41; // r8d
  unsigned int v42; // r10d
  unsigned int v43; // r8d
  unsigned int v44; // r10d
  unsigned int v45; // r8d
  unsigned int v46; // r10d
  UFG::TransformNodeComponent *v47; // rdi
  UFG::SimObjectCharacter *v48; // [rsp+20h] [rbp-68h]
  int v49[22]; // [rsp+30h] [rbp-58h] BYREF
  UFG::qSymbol result; // [rsp+90h] [rbp+8h] BYREF
  UFG::qSymbol name_a; // [rsp+A0h] [rbp+18h] BYREF
  UFG::qSymbol objName; // [rsp+A8h] [rbp+20h] BYREF

  LocalPlayer = UFG::GetLocalPlayer();
  v48 = LocalPlayer;
  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  v49[0] = *(int *)UFG::qPropertySet::Get<float>(
                     mpWritableProperties,
                     (UFG::qArray<unsigned long,0> *)&qSymbol_ActivateRadius,
                     DEPTH_RECURSE);
  mpConstProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpConstProperties )
    mpConstProperties = m_pSceneObj->mpConstProperties;
  v49[2] = *(int *)UFG::qPropertySet::Get<float>(
                     mpConstProperties,
                     (UFG::qArray<unsigned long,0> *)&qSymbol_DeactivateRadius,
                     DEPTH_RECURSE);
  v8 = m_pSceneObj->mpWritableProperties;
  if ( !v8 )
    v8 = m_pSceneObj->mpConstProperties;
  v49[1] = *(int *)UFG::qPropertySet::Get<float>(
                     v8,
                     (UFG::qArray<unsigned long,0> *)&qSymbol_TriggerRadius,
                     DEPTH_RECURSE);
  *(float *)&v49[3] = FLOAT_180_0;
  *(float *)&v49[4] = FLOAT_200_0;
  if ( !this->mRegionsCreated )
  {
    if ( (_S67 & 1) == 0 )
    {
      _S67 |= 1u;
      UFG::qSymbol::create_from_string(&triggerPropertySetSymbol_0, "object-logical-TriggerRegion");
      atexit(UFG::ProgressionTriggerComponent::CreateRegions_::_8_::_dynamic_atexit_destructor_for__triggerPropertySetSymbol__);
    }
    PropertySet = UFG::PropertySetManager::GetPropertySet(&triggerPropertySetSymbol_0);
    v10 = (float *)v49;
    mpRegionSceneObjects = this->mpRegionSceneObjects;
    v12 = 5i64;
    while ( 1 )
    {
      UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&result, &this->m_pSimObject->m_Name, "_");
      UFG::qSymbol::create_suffix(
        (UFG::qWiseSymbol *)&name_a,
        &result,
        *(char **)((char *)mpRegionSceneObjects + (char *)UFG::ProgressionTriggerRegionTypes - (char *)this - 96));
      UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&objName, &name_a, "_PTR");
      v13 = UFG::SceneObjectProperties::Create(&objName, 0i64, PropertySet);
      *mpRegionSceneObjects = v13;
      WritableProperties = UFG::SceneObjectProperties::GetWritableProperties(v13);
      appended = UFG::RegionComponent::PropertiesAppendDefaultProperty(WritableProperties);
      UFG::qPropertySet::Set<unsigned long>(appended, (UFG::qArray<unsigned long,0> *)&SimSym_Type, 2u);
      UFG::qPropertySet::Set<float>(appended, (UFG::qArray<unsigned long,0> *)&SimSym_Radius, *v10);
      UFG::SceneObjectProperties::Activate(*mpRegionSceneObjects, 1u, 0i64, 0i64);
      m_pSimObject = (*mpRegionSceneObjects)->m_pSimObject;
      if ( !m_pSimObject )
      {
LABEL_44:
        ComponentOfType = 0i64;
        goto LABEL_45;
      }
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
        UFG::TransformNodeComponent::SetParent(m_pTransformNodeComponent, pTransformNode, eInheritXform_Full);
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr >= size )
          goto LABEL_44;
        p = m_pSimObject->m_Components.p;
        while ( 1 )
        {
          v22 = vfptr;
          if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
            && (UFG::TriggerRegion::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++vfptr >= size )
            goto LABEL_44;
        }
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          v26 = (unsigned int)m_pSimObject[1].vfptr;
          v27 = m_pSimObject->m_Components.size;
          if ( v26 >= v27 )
            goto LABEL_44;
          p = m_pSimObject->m_Components.p;
          while ( 1 )
          {
            v22 = v26;
            if ( (p[v26].m_TypeUID & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
              && (UFG::TriggerRegion::_TypeUID & ~p[v26].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              break;
            }
            if ( ++v26 >= v27 )
              goto LABEL_44;
          }
        }
        else
        {
          if ( (m_Flags & 0x1000) == 0 )
          {
            ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::TriggerRegion::_TypeUID);
            goto LABEL_45;
          }
          v28 = (unsigned int)m_pSimObject[1].vfptr;
          v29 = m_pSimObject->m_Components.size;
          if ( v28 >= v29 )
            goto LABEL_44;
          p = m_pSimObject->m_Components.p;
          while ( 1 )
          {
            v22 = v28;
            if ( (p[v28].m_TypeUID & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
              && (UFG::TriggerRegion::_TypeUID & ~p[v28].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              break;
            }
            if ( ++v28 >= v29 )
              goto LABEL_44;
          }
        }
      }
      else
      {
        v24 = (unsigned int)m_pSimObject[1].vfptr;
        v25 = m_pSimObject->m_Components.size;
        if ( v24 >= v25 )
          goto LABEL_44;
        p = m_pSimObject->m_Components.p;
        while ( 1 )
        {
          v22 = v24;
          if ( (p[v24].m_TypeUID & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
            && (UFG::TriggerRegion::_TypeUID & ~p[v24].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v24 >= v25 )
            goto LABEL_44;
        }
      }
      ComponentOfType = p[v22].m_pComponent;
LABEL_45:
      mpRegionSceneObjects[5] = (UFG::SceneObjectProperties *)ComponentOfType;
      RCX = Assembly::GetRCX(this);
      ComponentOfType[3].m_BoundComponentHandles.mNode.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)UFG::ProgressionTriggerComponent::OnEnterTrigger;
      ComponentOfType[3].m_BoundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)RCX;
      v31 = Assembly::GetRCX(this);
      ComponentOfType[4].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)UFG::ProgressionTriggerComponent::OnExitTrigger;
      ComponentOfType[4].vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v31;
      ++mpRegionSceneObjects;
      ++v10;
      if ( !--v12 )
      {
        this->mRegionsCreated = 1;
        LocalPlayer = v48;
        break;
      }
    }
  }
  for ( i = 0i64; i < 5; ++i )
  {
    v33 = this->mpTriggerRegions[i];
    if ( !v33 )
      goto LABEL_87;
    if ( !LocalPlayer )
      goto LABEL_87;
    LOBYTE(result.mUID) = 0;
    UFG::TriggerRegion::TrackTarget(v33, LocalPlayer, (bool *)&result);
    if ( i )
      goto LABEL_87;
    v34 = v33->m_pSimObject;
    if ( !v34 )
      goto LABEL_87;
    v35 = v34->m_Flags;
    if ( (v35 & 0x4000) != 0 )
    {
      v36 = (unsigned int)v34[1].vfptr;
      v37 = v34->m_Components.size;
      if ( v36 >= v37 )
        goto LABEL_60;
      v38 = v34->m_Components.p;
      while ( 1 )
      {
        v39 = v36;
        if ( (v38[v36].m_TypeUID & 0xFE000000) == (UFG::RegionComponent::_TypeUID & 0xFE000000)
          && (UFG::RegionComponent::_TypeUID & ~v38[v36].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++v36 >= v37 )
          goto LABEL_60;
      }
    }
    else if ( v35 >= 0 )
    {
      if ( (v35 & 0x2000) != 0 )
      {
        v43 = (unsigned int)v34[1].vfptr;
        v44 = v34->m_Components.size;
        if ( v43 >= v44 )
          goto LABEL_60;
        v38 = v34->m_Components.p;
        while ( 1 )
        {
          v39 = v43;
          if ( (v38[v43].m_TypeUID & 0xFE000000) == (UFG::RegionComponent::_TypeUID & 0xFE000000)
            && (UFG::RegionComponent::_TypeUID & ~v38[v43].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v43 >= v44 )
            goto LABEL_60;
        }
      }
      else
      {
        if ( (v35 & 0x1000) == 0 )
        {
          m_pComponent = (UFG::RegionComponent *)UFG::SimObject::GetComponentOfType(v34, UFG::RegionComponent::_TypeUID);
          goto LABEL_83;
        }
        v45 = (unsigned int)v34[1].vfptr;
        v46 = v34->m_Components.size;
        if ( v45 >= v46 )
        {
LABEL_60:
          m_pComponent = 0i64;
          goto LABEL_83;
        }
        v38 = v34->m_Components.p;
        while ( 1 )
        {
          v39 = v45;
          if ( (v38[v45].m_TypeUID & 0xFE000000) == (UFG::RegionComponent::_TypeUID & 0xFE000000)
            && (UFG::RegionComponent::_TypeUID & ~v38[v45].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v45 >= v46 )
            goto LABEL_60;
        }
      }
    }
    else
    {
      v41 = (unsigned int)v34[1].vfptr;
      v42 = v34->m_Components.size;
      if ( v41 >= v42 )
        goto LABEL_60;
      v38 = v34->m_Components.p;
      while ( 1 )
      {
        v39 = v41;
        if ( (v38[v41].m_TypeUID & 0xFE000000) == (UFG::RegionComponent::_TypeUID & 0xFE000000)
          && (UFG::RegionComponent::_TypeUID & ~v38[v41].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++v41 >= v42 )
          goto LABEL_60;
      }
    }
    m_pComponent = (UFG::RegionComponent *)v38[v39].m_pComponent;
LABEL_83:
    if ( m_pComponent )
    {
      v47 = LocalPlayer->m_pTransformNodeComponent;
      if ( v47 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v47);
        if ( !UFG::RegionComponent::IsHitPoint(m_pComponent, (UFG::qVector3 *)&v47->mWorldTransform.v3) )
          this->mRequiresExitToActivate = 0;
      }
    }
LABEL_87:
    UFG::TriggerRegion::EnableHot(this->mpTriggerRegions[i], 1);
    LocalPlayer = v48;
  }
}       UFG::TransformNodeComponent::UpdateWorldTransform(v47);
        if ( !UFG::RegionComponent::IsHitPoint(m_pComponent, (UFG::qVector3 *)&v47->mWorldTransform.v3) )
          this->mRequiresExitToActivate = 0;
      }
    }
LABEL_87:
    UFG::TriggerRegion::EnableHot(this->mpTriggerRegions[i], 1);
    LocalPlayer 

// File Line: 331
// RVA: 0x534B30
void __fastcall UFG::ProgressionTriggerComponent::HandleSpawnPointSpawn(
        UFG::ProgressionTriggerComponent *this,
        bool enable)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *v6; // rdi
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v9; // rdx
  UFG::SpawnPoint *ComponentOfType; // rax
  unsigned int v11; // r8d
  unsigned int v12; // r9d
  unsigned int v13; // r8d
  unsigned int v14; // r9d
  unsigned int v15; // r8d
  unsigned int v16; // r9d
  UFG::SimObjectGame *v17; // rax
  UFG::SimObjectProp *v18; // rbx
  __int16 v19; // dx
  UFG::CharacterAnimationComponent *m_pComponent; // rcx
  UFG::CharacterAnimationComponent *v21; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int v23; // r9d
  __int64 v24; // rdx
  UFG::SceneObjectProperties *m_pSceneObj; // rbp
  UFG::qPropertySet *WritableProperties; // rsi
  UFG::qPropertySet *PropertySet; // rax
  __int16 v28; // cx
  unsigned int v29; // r8d
  unsigned int v30; // r9d
  __int64 v31; // rdx
  unsigned int v32; // r8d
  unsigned int v33; // r9d
  unsigned int v34; // r8d
  unsigned int v35; // r9d
  UFG::SimObject *ResourceMovieDef; // rax

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return;
  m_Flags = m_pSimObject->m_Flags;
  v6 = 0i64;
  if ( (m_Flags & 0x4000) != 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      v9 = (__int64)&m_pSimObject->m_Components.p[vfptr];
      while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || (UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        v9 += 16i64;
        if ( vfptr >= size )
          goto LABEL_8;
      }
LABEL_9:
      ComponentOfType = *(UFG::SpawnPoint **)v9;
      goto LABEL_32;
    }
    goto LABEL_8;
  }
  if ( m_Flags < 0 )
  {
    v11 = (unsigned int)m_pSimObject[1].vfptr;
    v12 = m_pSimObject->m_Components.size;
    if ( v11 < v12 )
    {
      v9 = (__int64)&m_pSimObject->m_Components.p[v11];
      while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || (UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v11;
        v9 += 16i64;
        if ( v11 >= v12 )
        {
          ComponentOfType = 0i64;
          goto LABEL_32;
        }
      }
      goto LABEL_9;
    }
LABEL_8:
    ComponentOfType = 0i64;
    goto LABEL_32;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v13 = (unsigned int)m_pSimObject[1].vfptr;
    v14 = m_pSimObject->m_Components.size;
    if ( v13 < v14 )
    {
      v9 = (__int64)&m_pSimObject->m_Components.p[v13];
      while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || (UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v13;
        v9 += 16i64;
        if ( v13 >= v14 )
        {
          ComponentOfType = 0i64;
          goto LABEL_32;
        }
      }
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v15 = (unsigned int)m_pSimObject[1].vfptr;
    v16 = m_pSimObject->m_Components.size;
    if ( v15 < v16 )
    {
      v9 = (__int64)&m_pSimObject->m_Components.p[v15];
      while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || (UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v15;
        v9 += 16i64;
        if ( v15 >= v16 )
        {
          ComponentOfType = 0i64;
          goto LABEL_32;
        }
      }
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  ComponentOfType = (UFG::SpawnPoint *)UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::SpawnPoint::_TypeUID);
LABEL_32:
  if ( !ComponentOfType )
    return;
  if ( !enable )
  {
    ResourceMovieDef = Scaleform::GFx::InteractiveObject::GetResourceMovieDef(ComponentOfType);
    if ( ResourceMovieDef )
      UFG::SimObject::Destroy(ResourceMovieDef);
    return;
  }
  v17 = UFG::SpawnPoint::Spawn(ComponentOfType, 0, 0);
  v18 = (UFG::SimObjectProp *)v17;
  if ( !v17 )
    return;
  UFG::SimObjectUtility::ReinitializeSimObject(v17, 1, 0);
  v19 = v18->m_Flags;
  if ( (v19 & 0x4000) != 0 )
  {
    m_pComponent = (UFG::CharacterAnimationComponent *)v18->m_Components.p[9].m_pComponent;
    if ( !m_pComponent
      || ((UFG::CharacterAnimationComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_39;
    }
    goto LABEL_57;
  }
  if ( v19 < 0 )
  {
    m_pComponent = (UFG::CharacterAnimationComponent *)v18->m_Components.p[9].m_pComponent;
    if ( !m_pComponent || ((UFG::CharacterAnimationComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_39;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
      m_pComponent = 0i64;
    goto LABEL_57;
  }
  if ( (v19 & 0x2000) != 0 )
  {
    v21 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v18);
LABEL_56:
    m_pComponent = v21;
    goto LABEL_57;
  }
  if ( (v19 & 0x1000) == 0 )
  {
    v21 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                v18,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_56;
  }
  mComponentTableEntryCount = v18->mComponentTableEntryCount;
  v23 = v18->m_Components.size;
  if ( mComponentTableEntryCount >= v23 )
  {
LABEL_39:
    m_pComponent = 0i64;
    goto LABEL_57;
  }
  v24 = (__int64)&v18->m_Components.p[mComponentTableEntryCount];
  while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF) != 0 )
  {
    ++mComponentTableEntryCount;
    v24 += 16i64;
    if ( mComponentTableEntryCount >= v23 )
    {
      m_pComponent = 0i64;
      goto LABEL_57;
    }
  }
  m_pComponent = *(UFG::CharacterAnimationComponent **)v24;
LABEL_57:
  if ( m_pComponent && this->mpGameSlice->mFaceActionType != 18 )
  {
    m_pSceneObj = v18->m_pSceneObj;
    WritableProperties = UFG::SceneObjectProperties::GetWritableProperties(m_pSceneObj);
    if ( !UFG::qPropertySet::GetParentFromName(
            WritableProperties,
            (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentFaceAction,
            DEPTH_RECURSE) )
    {
      PropertySet = UFG::PropertySetManager::CreateOrFindPropertySet(&SimSymX_propset_componentFaceAction);
      UFG::PSWrapper::AppendParentLocal(WritableProperties, PropertySet);
    }
    UFG::qPropertySet::Set<UFG::qSymbol>(
      WritableProperties,
      (UFG::qArray<unsigned long,0> *)&SimSym_FaceAction,
      &UFG::FaceActionEnumSymbols[this->mpGameSlice->mFaceActionType]);
    UFG::qPropertySet::Set<unsigned long>(
      WritableProperties,
      (UFG::qArray<unsigned long,0> *)&SimSym_PipsRequired,
      this->mpGameSlice->mMinPipLevel);
    UFG::qPropertySet::Set<bool>(WritableProperties, (UFG::qArray<unsigned long,0> *)&SimSym_Hidden, 0);
    UFG::qPropertySet::Set<bool>(WritableProperties, (UFG::qArray<unsigned long,0> *)&SimSym_RemoveOnCompletion, 1);
    v28 = v18->m_Flags;
    if ( (v28 & 0x4000) != 0 )
    {
      v6 = v18->m_Components.p[45].m_pComponent;
      goto LABEL_86;
    }
    if ( v28 < 0 )
    {
      v29 = v18->mComponentTableEntryCount;
      v30 = v18->m_Components.size;
      if ( v29 >= v30 )
        goto LABEL_86;
      v31 = (__int64)&v18->m_Components.p[v29];
      while ( (*(_DWORD *)(v31 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
           || (UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v31 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v29;
        v31 += 16i64;
        if ( v29 >= v30 )
          goto LABEL_86;
      }
      goto LABEL_70;
    }
    if ( (v28 & 0x2000) != 0 )
    {
      v32 = v18->mComponentTableEntryCount;
      v33 = v18->m_Components.size;
      if ( v32 < v33 )
      {
        v31 = (__int64)&v18->m_Components.p[v32];
        while ( (*(_DWORD *)(v31 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
             || (UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v31 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v32;
          v31 += 16i64;
          if ( v32 >= v33 )
            goto LABEL_86;
        }
LABEL_70:
        v6 = *(UFG::SimComponent **)v31;
      }
    }
    else if ( (v28 & 0x1000) != 0 )
    {
      v34 = v18->mComponentTableEntryCount;
      v35 = v18->m_Components.size;
      if ( v34 < v35 )
      {
        v31 = (__int64)&v18->m_Components.p[v34];
        while ( (*(_DWORD *)(v31 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
             || (UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v31 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v34;
          v31 += 16i64;
          if ( v34 >= v35 )
            goto LABEL_86;
        }
        goto LABEL_70;
      }
    }
    else
    {
      v6 = UFG::SimObject::GetComponentOfType(v18, UFG::FaceActionComponent::_TypeUID);
    }
LABEL_86:
    if ( v6 )
      v6->vfptr[12].__vecDelDtor(v6, (unsigned int)m_pSceneObj);
    else
      UFG::FaceActionComponent::CreateFaceActionComponent(m_pSceneObj);
  }
}

// File Line: 390
// RVA: 0x526790
void __fastcall UFG::ProgressionTriggerComponent::Enable(
        UFG::ProgressionTriggerComponent *this,
        UFG::GameSlice *pGameSlice)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::TransformNodeComponent *mNext; // rdx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v7; // rdx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *mPrev; // rcx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v9; // rax
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v10; // rax

  if ( !this->mEnabled )
  {
    m_pSimObject = this->m_pSimObject;
    this->mpGameSlice = pGameSlice;
    m_pSceneObj = m_pSimObject->m_pSceneObj;
    mpWritableProperties = m_pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = m_pSceneObj->mpConstProperties;
    UFG::qPropertySet::Get<char const *>(
      mpWritableProperties,
      (UFG::qArray<unsigned long,0> *)&qSymbol_IndicatorType,
      DEPTH_RECURSE);
    mNext = (UFG::TransformNodeComponent *)this->m_pSimObject;
    if ( mNext )
      mNext = (UFG::TransformNodeComponent *)mNext->mChildren.mNode.mNext;
    UFG::ProgressionTriggerComponent::CreateRegions(this, mNext);
    if ( !this->mRequiresExitToActivate )
      UFG::ProgressionTriggerComponent::EnableObjective(this);
    v7 = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>;
    if ( v7->mPrev != v7
      || this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mNext != &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> )
    {
      mPrev = v7->mPrev;
      v9 = this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mNext;
      mPrev->mNext = v9;
      v9->mPrev = mPrev;
      v7->mPrev = v7;
      this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mNext = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>;
    }
    v10 = smProgressionTriggerComponent_UpdateList.mNode.mPrev;
    smProgressionTriggerComponent_UpdateList.mNode.mPrev->mNext = v7;
    v7->mPrev = v10;
    this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mNext = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *)&smProgressionTriggerComponent_UpdateList;
    smProgressionTriggerComponent_UpdateList.mNode.mPrev = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>;
    this->mEnabled = 1;
  }
}

// File Line: 424
// RVA: 0x526D50
void __fastcall UFG::ProgressionTriggerComponent::EnableObjective(UFG::ProgressionTriggerComponent *this)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx
  char *v4; // rax
  UFG::ProgressionTracker *v5; // rax
  UFG::qString identifier; // [rsp+28h] [rbp-30h] BYREF

  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  v4 = UFG::qPropertySet::Get<char const *>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&qSymbol_Objective,
         DEPTH_RECURSE);
  if ( v4 )
  {
    if ( *v4 )
    {
      UFG::qString::qString(&identifier, v4);
      v5 = UFG::ProgressionTracker::Instance();
      UFG::ObjectiveTracker::UpdateStatus(&v5->mObjectiveTracker, &identifier, STATUS_ACTIVE, this->mpGameSlice);
      UFG::qString::~qString(&identifier);
    }
  }
}

// File Line: 436
// RVA: 0x526030
void __fastcall UFG::ProgressionTriggerComponent::Disable(UFG::ProgressionTriggerComponent *this, bool turnLayerOn)
{
  UFG::TriggerRegion **mpTriggerRegions; // rbx
  __int64 v5; // rsi
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx
  char *v8; // rax
  UFG::qString *v9; // rax
  UFG::qString *v10; // rbx
  UFG::ProgressionTracker *v11; // rax
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v12; // rdx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *mPrev; // rcx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *mNext; // rax
  UFG::qString v15; // [rsp+28h] [rbp-30h] BYREF

  if ( this->mEnabled )
  {
    mpTriggerRegions = this->mpTriggerRegions;
    v5 = 5i64;
    do
    {
      UFG::TriggerRegion::EnableHot(*mpTriggerRegions++, 0);
      --v5;
    }
    while ( v5 );
    if ( !this->mpGameSlice->mKeepTriggerObjectiveEnabled || !turnLayerOn )
    {
      m_pSceneObj = this->m_pSimObject->m_pSceneObj;
      mpWritableProperties = m_pSceneObj->mpWritableProperties;
      if ( !mpWritableProperties )
        mpWritableProperties = m_pSceneObj->mpConstProperties;
      v8 = UFG::qPropertySet::Get<char const *>(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&qSymbol_Objective,
             DEPTH_RECURSE);
      if ( v8 && *v8 )
      {
        UFG::qString::qString(&v15, v8);
        v10 = v9;
        v11 = UFG::ProgressionTracker::Instance();
        UFG::ObjectiveTracker::UpdateStatus(&v11->mObjectiveTracker, v10, STATUS_INACTIVE, this->mpGameSlice);
        UFG::qString::~qString(&v15);
      }
    }
    UFG::GameSlice::SetWaitingForTrigger(this->mpGameSlice, 0, turnLayerOn);
    if ( !turnLayerOn )
      UFG::ProgressionTriggerComponent::HandleSpawnPointSpawn(this, 0);
    v12 = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>;
    if ( v12->mPrev != v12
      || this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mNext != &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> )
    {
      if ( this == UFG::gpCurrentProgressionTriggerComponent )
        UFG::gpCurrentProgressionTriggerComponent = (UFG::ProgressionTriggerComponent *)&UFG::gpCurrentProgressionTriggerComponent->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mPrev[-5];
      mPrev = v12->mPrev;
      mNext = this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v12->mPrev = v12;
      this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mNext = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>;
    }
    this->mEnabled = 0;
  }
}

// File Line: 477
// RVA: 0x526530
void __fastcall UFG::ProgressionTriggerComponent::DisablePDATrigger(UFG::GameSlice *pGameSlice)
{
  UFG::PDATriggerParameters *mPDATriggerParameters; // rax
  UFG::ProgressionTriggerComponent *Component; // rbx
  UFG::UIHK_PDAWidget *v3; // rax
  UFG::PDATriggerTracker *p_mPDATriggerTracker; // rcx
  UFG::qSymbol identifier; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_identifier; // [rsp+48h] [rbp+10h]

  mPDATriggerParameters = pGameSlice->mPDATriggerParameters;
  if ( pGameSlice->mTriggerObjectName.mUID == -1 )
  {
    if ( mPDATriggerParameters )
    {
      p_identifier = &identifier;
      identifier.mUID = mPDATriggerParameters->mContactSymbol.mUID;
      p_mPDATriggerTracker = &UFG::ProgressionTracker::Instance()->mPDATriggerTracker;
      UFG::PDATriggerTracker::Remove(p_mPDATriggerTracker, &identifier.mUID);
    }
  }
  else if ( mPDATriggerParameters )
  {
    if ( mPDATriggerParameters->mIncoming )
    {
      Component = UFG::ProgressionTriggerComponent::GetComponent(pGameSlice);
      if ( Component )
      {
        v3 = UFG::UIHK_PDAWidget::Get();
        if ( v3 )
        {
          UFG::UIHK_PDAWidget::EndPhoneCall(v3, 1);
          Component->mCallTimeout = 0i64;
        }
      }
    }
  }
}

// File Line: 505
// RVA: 0x52B990
UFG::ProgressionTriggerComponent *__fastcall UFG::ProgressionTriggerComponent::GetComponent(UFG::GameSlice *pGameSlice)
{
  UFG::qBaseNodeRB *SimObject; // rax
  __int16 v2; // dx
  unsigned int mParent; // r9d
  unsigned int v4; // r10d
  _DWORD *i; // rdx
  unsigned int v7; // r9d
  unsigned int v8; // r10d
  unsigned int v9; // r9d
  unsigned int v10; // r10d
  unsigned int v11; // r9d
  unsigned int v12; // r10d

  if ( pGameSlice->mTriggerObjectName.mUID == -1 )
    return 0i64;
  SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, &pGameSlice->mTriggerObjectName);
  if ( !SimObject )
    return 0i64;
  v2 = WORD2(SimObject[2].mChild[0]);
  if ( (v2 & 0x4000) != 0 )
  {
    mParent = (unsigned int)SimObject[4].mParent;
    v4 = (unsigned int)SimObject[3].mParent;
    if ( mParent < v4 )
    {
      for ( i = (_DWORD *)SimObject[3].mChild[0] + 4 * mParent;
            (i[2] & 0xFE000000) != (UFG::ProgressionTriggerComponent::_TypeUID & 0xFE000000)
         || (UFG::ProgressionTriggerComponent::_TypeUID & ~i[2] & 0x1FFFFFF) != 0;
            i += 4 )
      {
        if ( ++mParent >= v4 )
          return 0i64;
      }
      return *(UFG::ProgressionTriggerComponent **)i;
    }
    return 0i64;
  }
  if ( v2 < 0 )
  {
    v7 = (unsigned int)SimObject[4].mParent;
    v8 = (unsigned int)SimObject[3].mParent;
    if ( v7 < v8 )
    {
      for ( i = (_DWORD *)SimObject[3].mChild[0] + 4 * v7;
            (i[2] & 0xFE000000) != (UFG::ProgressionTriggerComponent::_TypeUID & 0xFE000000)
         || (UFG::ProgressionTriggerComponent::_TypeUID & ~i[2] & 0x1FFFFFF) != 0;
            i += 4 )
      {
        if ( ++v7 >= v8 )
          return 0i64;
      }
      return *(UFG::ProgressionTriggerComponent **)i;
    }
    return 0i64;
  }
  if ( (v2 & 0x2000) != 0 )
  {
    v9 = (unsigned int)SimObject[4].mParent;
    v10 = (unsigned int)SimObject[3].mParent;
    if ( v9 < v10 )
    {
      for ( i = (_DWORD *)SimObject[3].mChild[0] + 4 * v9;
            (i[2] & 0xFE000000) != (UFG::ProgressionTriggerComponent::_TypeUID & 0xFE000000)
         || (UFG::ProgressionTriggerComponent::_TypeUID & ~i[2] & 0x1FFFFFF) != 0;
            i += 4 )
      {
        if ( ++v9 >= v10 )
          return 0i64;
      }
      return *(UFG::ProgressionTriggerComponent **)i;
    }
    return 0i64;
  }
  if ( (v2 & 0x1000) != 0 )
  {
    v11 = (unsigned int)SimObject[4].mParent;
    v12 = (unsigned int)SimObject[3].mParent;
    if ( v11 < v12 )
    {
      for ( i = (_DWORD *)SimObject[3].mChild[0] + 4 * v11;
            (i[2] & 0xFE000000) != (UFG::ProgressionTriggerComponent::_TypeUID & 0xFE000000)
         || (UFG::ProgressionTriggerComponent::_TypeUID & ~i[2] & 0x1FFFFFF) != 0;
            i += 4 )
      {
        if ( ++v11 >= v12 )
          return 0i64;
      }
      return *(UFG::ProgressionTriggerComponent **)i;
    }
    return 0i64;
  }
  return (UFG::ProgressionTriggerComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)SimObject,
                                               UFG::ProgressionTriggerComponent::_TypeUID);
}

// File Line: 524
// RVA: 0x53C060
char __fastcall UFG::ProgressionTriggerComponent::IsRestoring(UFG::GameSlice *pGameSlice)
{
  int v2; // ebx
  int NumChildren; // edi

  if ( pGameSlice->mState == STATE_RESTORING )
    return 0;
  v2 = 0;
  NumChildren = UFG::GameSlice::GetNumChildren(pGameSlice);
  if ( NumChildren <= 0 )
    return 0;
  while ( UFG::GameSlice::GetChild(pGameSlice, v2)->mState < STATE_RESTORING )
  {
    if ( ++v2 >= NumChildren )
      return 0;
  }
  return 1;
}

// File Line: 542
// RVA: 0x526E60
void __fastcall UFG::ProgressionTriggerComponent::EnableTrigger(UFG::GameSlice *pGameSlice)
{
  bool IsWaitingForTrigger; // di
  UFG::PDATriggerParameters *mPDATriggerParameters; // rsi
  UFG::ProgressionTriggerComponent *Component; // rax
  UFG::PDATriggerTracker *p_mPDATriggerTracker; // rcx
  UFG::ProgressionTracker *v6; // rax
  UFG::GameSlice *Parent; // rax
  UFG::GameSliceStreamer *v8; // rax
  UFG::qSymbol identifier; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_identifier; // [rsp+48h] [rbp+10h]

  IsWaitingForTrigger = 0;
  mPDATriggerParameters = pGameSlice->mPDATriggerParameters;
  if ( UFG::GameSlice::GetParent(pGameSlice) )
  {
    Parent = UFG::GameSlice::GetParent(pGameSlice);
    IsWaitingForTrigger = UFG::GameSlice::IsWaitingForTrigger(Parent);
    if ( IsWaitingForTrigger )
      goto LABEL_13;
    goto LABEL_12;
  }
  if ( pGameSlice->mTriggerObjectName.mUID != -1 )
  {
    if ( !UFG::ProgressionTriggerComponent::IsRestoring(pGameSlice) )
    {
      Component = UFG::ProgressionTriggerComponent::GetComponent(pGameSlice);
      if ( Component )
      {
        UFG::ProgressionTriggerComponent::Enable(Component, pGameSlice);
        IsWaitingForTrigger = 1;
        goto LABEL_13;
      }
    }
LABEL_12:
    v8 = UFG::GameSliceStreamer::Instance();
    UFG::GameSliceStreamer::RequestStream(
      v8,
      (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)pGameSlice);
    goto LABEL_13;
  }
  if ( !mPDATriggerParameters || UFG::ProgressionTriggerComponent::IsRestoring(pGameSlice) )
    goto LABEL_12;
  p_identifier = &identifier;
  identifier.mUID = mPDATriggerParameters->mContactSymbol.mUID;
  p_mPDATriggerTracker = &UFG::ProgressionTracker::Instance()->mPDATriggerTracker;
  UFG::PDATriggerTracker::Add(p_mPDATriggerTracker, &identifier.mUID, pGameSlice);
  if ( mPDATriggerParameters->mObjectiveName.mLength )
  {
    v6 = UFG::ProgressionTracker::Instance();
    UFG::ObjectiveTracker::UpdateStatus(
      &v6->mObjectiveTracker,
      &mPDATriggerParameters->mObjectiveName,
      STATUS_ACTIVE,
      pGameSlice);
  }
  IsWaitingForTrigger = 1;
LABEL_13:
  UFG::GameSlice::SetWaitingForTrigger(pGameSlice, IsWaitingForTrigger, 1);
}

// File Line: 594
// RVA: 0x5207E0
void __fastcall UFG::ProgressionTriggerComponent::ActiveateOnlyAfterExitFromRegion(UFG::GameSlice *pGameSlice)
{
  UFG::ProgressionTriggerComponent *Component; // rax

  Component = UFG::ProgressionTriggerComponent::GetComponent(pGameSlice);
  if ( Component )
    Component->mRequiresExitToActivate = 1;
}

// File Line: 603
// RVA: 0x5265C0
void __fastcall UFG::ProgressionTriggerComponent::DisableTrigger(UFG::GameSlice *pGameSlice, bool turnLayerOn)
{
  UFG::PDATriggerParameters *mPDATriggerParameters; // rax
  UFG::ProgressionTriggerComponent *Component; // rax
  UFG::PDATriggerTracker *p_mPDATriggerTracker; // rcx
  UFG::qSymbol identifier; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_identifier; // [rsp+50h] [rbp+18h]

  do
  {
    mPDATriggerParameters = pGameSlice->mPDATriggerParameters;
    if ( pGameSlice->mTriggerObjectName.mUID == -1 )
    {
      if ( mPDATriggerParameters )
      {
        p_identifier = &identifier;
        identifier.mUID = mPDATriggerParameters->mContactSymbol.mUID;
        p_mPDATriggerTracker = &UFG::ProgressionTracker::Instance()->mPDATriggerTracker;
        UFG::PDATriggerTracker::Remove(p_mPDATriggerTracker, &identifier.mUID);
      }
    }
    else
    {
      Component = UFG::ProgressionTriggerComponent::GetComponent(pGameSlice);
      if ( Component )
        UFG::ProgressionTriggerComponent::Disable(Component, turnLayerOn);
    }
    pGameSlice = UFG::GameSlice::GetParent(pGameSlice);
  }
  while ( pGameSlice );
}

// File Line: 630
// RVA: 0x53CD20
void __fastcall UFG::ProgressionTriggerComponent::OnActivate(
        UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *pGameSlice)
{
  UFG::PDATriggerParameters *mNext; // rdi
  UFG::ProgressionTriggerComponent *Component; // rax
  UFG::GameSliceStreamer *v4; // rax
  UFG::PDATriggerTracker *p_mPDATriggerTracker; // rcx
  UFG::qSymbol identifier; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_identifier; // [rsp+48h] [rbp+10h]

  mNext = (UFG::PDATriggerParameters *)pGameSlice[3].mNext;
  if ( HIDWORD(pGameSlice[10].mNext) == -1 )
  {
    if ( mNext )
    {
      v4 = UFG::GameSliceStreamer::Instance();
      UFG::GameSliceStreamer::RequestStream(v4, pGameSlice);
      p_identifier = &identifier;
      identifier.mUID = mNext->mContactSymbol.mUID;
      p_mPDATriggerTracker = &UFG::ProgressionTracker::Instance()->mPDATriggerTracker;
      UFG::PDATriggerTracker::Remove(p_mPDATriggerTracker, &identifier.mUID);
      UFG::GameSlice::SetWaitingForTrigger((UFG::GameSlice *)pGameSlice, 0, 1);
    }
  }
  else
  {
    Component = UFG::ProgressionTriggerComponent::GetComponent((UFG::GameSlice *)pGameSlice);
    if ( Component )
      UFG::ProgressionTriggerComponent::OnActivate(Component);
  }
}

// File Line: 653
// RVA: 0x535720
bool __fastcall UFG::ProgressionTriggerComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentProgressionTrigger,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 659
// RVA: 0x5453B0
UFG::ProgressionTriggerComponent *__fastcall UFG::ProgressionTriggerComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xD0ui64, "ProgressionTriggerComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::ProgressionTriggerComponent::ProgressionTriggerComponent(
      (UFG::ProgressionTriggerComponent *)v3,
      pSceneObj->m_NameUID);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v7, pSceneObj->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v7, v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v7);
  UFG::SimObjectModifier::~SimObjectModifier(&v7);
  return (UFG::ProgressionTriggerComponent *)v5;
}

// File Line: 699
// RVA: 0x52A2F0
void __fastcall UFG::ProgressionTriggerComponent::ForceOnEnter(UFG::ProgressionTriggerComponent *this)
{
  UFG::GameSliceStreamer *v2; // rax
  UFG::GameSlice *mpGameSlice; // rcx
  UFG::PDATriggerParameters *mPDATriggerParameters; // rax

  v2 = UFG::GameSliceStreamer::Instance();
  UFG::GameSliceStreamer::RequestStream(
    v2,
    (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)this->mpGameSlice);
  mpGameSlice = this->mpGameSlice;
  mPDATriggerParameters = mpGameSlice->mPDATriggerParameters;
  this->mInsideActiveRegion = 1;
  if ( !mPDATriggerParameters )
  {
    UFG::GameSlice::_EnableLayer(mpGameSlice);
    UFG::ProgressionTriggerComponent::HandleSpawnPointSpawn(this, 1);
  }
  if ( !this->mpGameSlice->mPDATriggerParameters )
    UFG::ProgressionTriggerComponent::OnActivate(this);
  *(_WORD *)&this->mWaitMenuActive = 0;
  this->mRequiresExitToActivate = 0;
}

// File Line: 709
// RVA: 0x5413D0
void __fastcall UFG::ProgressionTriggerComponent::OnEnterTrigger(
        UFG::ProgressionTriggerComponent *this,
        UFG::TriggerRegion *pTriggerRegion)
{
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *mpGameSlice; // rsi
  UFG::GameSliceStreamer *v5; // rax
  UFG::GameSlice *v6; // rsi
  UFG::ProgressionTracker *v7; // rax
  UFG::GameSlice *v8; // rcx
  UFG::PDATriggerParameters *mPDATriggerParameters; // rax
  UFG::GameSliceStreamer *v10; // rax

  if ( pTriggerRegion == this->mpTriggerRegions[3] )
  {
    mpGameSlice = (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)this->mpGameSlice;
    if ( !mpGameSlice[3].mNext )
    {
      v5 = UFG::GameSliceStreamer::Instance();
      UFG::GameSliceStreamer::RequestStream(v5, mpGameSlice);
    }
  }
  if ( !UFG::GameSlice::IsAllowedAtThisTimeOfDay(this->mpGameSlice) || this->mRequiresTODWait )
  {
    v6 = this->mpGameSlice;
    if ( v6->mPerformTimeShift && pTriggerRegion == this->mpTriggerRegions[1] )
    {
      *(_WORD *)&this->mWaitMenuActive = 257;
      v7 = UFG::ProgressionTracker::Instance();
      UFG::ProgressionTracker::EnableGameSliceTODWait(v7, v6, this);
    }
    this->mRequiresExitToActivate = 1;
  }
  if ( !this->mRequiresExitToActivate )
  {
    if ( pTriggerRegion == this->mpTriggerRegions[1] )
    {
      if ( !this->mpGameSlice->mPDATriggerParameters )
        UFG::ProgressionTriggerComponent::OnActivate(this);
    }
    else
    {
      if ( pTriggerRegion != this->mpTriggerRegions[0] )
        return;
      v8 = this->mpGameSlice;
      mPDATriggerParameters = v8->mPDATriggerParameters;
      this->mInsideActiveRegion = 1;
      if ( !mPDATriggerParameters )
      {
        UFG::GameSlice::_EnableLayer(v8);
        UFG::ProgressionTriggerComponent::HandleSpawnPointSpawn(this, 1);
      }
    }
    v10 = UFG::GameSliceStreamer::Instance();
    UFG::GameSliceStreamer::RequestStream(
      v10,
      (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)this->mpGameSlice);
  }
}

// File Line: 758
// RVA: 0x558650
UFG::ProgressionTriggerComponent::UnloadScripts

// File Line: 773
// RVA: 0x541D00
void __fastcall UFG::ProgressionTriggerComponent::OnExitTrigger(
        UFG::ProgressionTriggerComponent *this,
        UFG::TriggerRegion *pTriggerRegion)
{
  UFG::ProgressionTracker *v4; // rax
  UFG::GameSlice *mpGameSlice; // rcx

  if ( pTriggerRegion == this->mpTriggerRegions[4] && !this->mpGameSlice->mPDATriggerParameters )
    UFG::ProgressionTriggerComponent::UnloadScripts(this);
  if ( pTriggerRegion == this->mpTriggerRegions[1] && this->mWaitMenuActive )
  {
    this->mWaitMenuActive = 0;
    v4 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::EnableGameSliceTODWait(v4, 0i64, 0i64);
  }
  if ( pTriggerRegion == this->mpTriggerRegions[0] )
  {
    if ( this->mRequiresExitToActivate )
      UFG::ProgressionTriggerComponent::EnableObjective(this);
    this->mRequiresExitToActivate = 0;
    this->mRequiresTODWait = 0;
  }
  else if ( pTriggerRegion == this->mpTriggerRegions[2] )
  {
    mpGameSlice = this->mpGameSlice;
    if ( mpGameSlice->mPDATriggerParameters )
    {
      UFG::ProgressionTriggerComponent::DisablePDATrigger(mpGameSlice);
      UFG::ProgressionTriggerComponent::UnloadScripts(this);
    }
    else
    {
      UFG::GameSlice::_DisableLayer(mpGameSlice);
      UFG::ProgressionTriggerComponent::HandleSpawnPointSpawn(this, 0);
    }
    this->mInsideActiveRegion = 0;
  }
}

// File Line: 824
// RVA: 0x53CBC0
void __fastcall UFG::ProgressionTriggerComponent::OnActivate(UFG::ProgressionTriggerComponent *this)
{
  UFG::TriggerRegion **mpTriggerRegions; // rbx
  __int64 v3; // rsi
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx
  char *v6; // rax
  UFG::qString *v7; // rax
  UFG::qString *v8; // rbx
  UFG::ProgressionTracker *v9; // rax
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v10; // rdx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *mPrev; // rcx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *mNext; // rax
  UFG::qString v13; // [rsp+28h] [rbp-30h] BYREF

  if ( this->mEnabled )
  {
    mpTriggerRegions = this->mpTriggerRegions;
    v3 = 5i64;
    do
    {
      UFG::TriggerRegion::EnableHot(*mpTriggerRegions++, 0);
      --v3;
    }
    while ( v3 );
    if ( !this->mpGameSlice->mKeepTriggerObjectiveEnabled )
    {
      m_pSceneObj = this->m_pSimObject->m_pSceneObj;
      mpWritableProperties = m_pSceneObj->mpWritableProperties;
      if ( !mpWritableProperties )
        mpWritableProperties = m_pSceneObj->mpConstProperties;
      v6 = UFG::qPropertySet::Get<char const *>(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&qSymbol_Objective,
             DEPTH_RECURSE);
      if ( v6 && *v6 )
      {
        UFG::qString::qString(&v13, v6);
        v8 = v7;
        v9 = UFG::ProgressionTracker::Instance();
        UFG::ObjectiveTracker::UpdateStatus(&v9->mObjectiveTracker, v8, STATUS_INACTIVE, this->mpGameSlice);
        UFG::qString::~qString(&v13);
      }
    }
    UFG::GameSlice::SetWaitingForTrigger(this->mpGameSlice, 0, 1);
    v10 = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>;
    if ( v10->mPrev != v10
      || this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mNext != &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> )
    {
      if ( this == UFG::gpCurrentProgressionTriggerComponent )
        UFG::gpCurrentProgressionTriggerComponent = (UFG::ProgressionTriggerComponent *)&UFG::gpCurrentProgressionTriggerComponent->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mPrev[-5];
      mPrev = v10->mPrev;
      mNext = this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v10->mPrev = v10;
      this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>::mNext = &this->UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList>;
    }
    this->mEnabled = 0;
  }
  UFG::ProgressionTriggerComponent::DisablePDATrigger(this->mpGameSlice);
  UFG::GameSlice::_EnableLayer(this->mpGameSlice);
  UFG::GameSlice::StopDrivenVehicle(this->mpGameSlice);
  UFG::ProgressionTriggerComponent::HandleSpawnPointSpawn(this, 1);
}

