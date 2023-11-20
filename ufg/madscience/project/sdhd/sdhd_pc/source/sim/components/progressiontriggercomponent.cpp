// File Line: 39
// RVA: 0x154CA60
__int64 UFG::_dynamic_initializer_for__smProgressionTriggerComponent_UpdateList__()
{
  return atexit(UFG::_dynamic_atexit_destructor_for__smProgressionTriggerComponent_UpdateList__);
}

// File Line: 51
// RVA: 0x1543FC0
__int64 dynamic_initializer_for__UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentList__);
}

// File Line: 52
// RVA: 0x52CAC0
UFG::ComponentIDDesc *__fastcall UFG::ProgressionTriggerComponent::GetDesc(UFG::ProgressionTriggerComponent *this)
{
  return &UFG::ProgressionTriggerComponent::_TypeIDesc;
}

// File Line: 66
// RVA: 0x5186C0
void __fastcall UFG::ProgressionTriggerComponent::ProgressionTriggerComponent(UFG::ProgressionTriggerComponent *this, unsigned int name_uid)
{
  UFG::ProgressionTriggerComponent *v2; // rbx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *v3; // rdx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v4; // rax
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *v5; // rax

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v4 = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *)&v2->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ProgressionTriggerComponent::`vftable;
  v2->mpGameSlice = 0i64;
  v2->mCallTimeout = 0i64;
  v2->mCallFailTimeout = 0i64;
  *(_DWORD *)&v2->mInsideActiveRegion = 0;
  *(_WORD *)&v2->mRequiresTODWait = 0;
  v2->mpRegionSceneObjects[0] = 0i64;
  v2->mpTriggerRegions[0] = 0i64;
  v2->mpRegionSceneObjects[1] = 0i64;
  v2->mpTriggerRegions[1] = 0i64;
  v2->mpRegionSceneObjects[2] = 0i64;
  v2->mpTriggerRegions[2] = 0i64;
  v2->mpRegionSceneObjects[3] = 0i64;
  v2->mpTriggerRegions[3] = 0i64;
  v2->mpRegionSceneObjects[4] = 0i64;
  v2->mpTriggerRegions[4] = 0i64;
  v5 = UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentList.mNode.mPrev;
  UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *)&v2->mPrev;
  v3->mPrev = v5;
  v2->mNext = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *)&UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentList;
  UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentList.mNode.mPrev = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::ProgressionTriggerComponent::_ProgressionTriggerComponentTypeUID,
    "ProgressionTriggerComponent");
}

// File Line: 79
// RVA: 0x51C250
void __fastcall UFG::ProgressionTriggerComponent::~ProgressionTriggerComponent(UFG::ProgressionTriggerComponent *this)
{
  UFG::ProgressionTriggerComponent *v1; // rdi
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *v2; // rsi
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *v3; // rcx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *v4; // rax
  UFG::SceneObjectProperties **v5; // rbx
  signed __int64 v6; // rbp
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v7; // rdx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v8; // rcx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v9; // rax
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *v10; // rcx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ProgressionTriggerComponent::`vftable;
  if ( this == UFG::gpCurrentProgressionTriggerComponent )
    UFG::gpCurrentProgressionTriggerComponent = (UFG::ProgressionTriggerComponent *)&UFG::gpCurrentProgressionTriggerComponent->mPrev[-5];
  if ( this == UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentpCurrentIterator )
    UFG::ProgressionTriggerComponent::s_ProgressionTriggerComponentpCurrentIterator = (UFG::ProgressionTriggerComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::ProgressionTriggerComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  if ( v1->mRegionsCreated )
  {
    v5 = v1->mpRegionSceneObjects;
    v6 = 5i64;
    do
    {
      UFG::SceneObjectProperties::Deactivate(*v5);
      *v5 = 0i64;
      ++v5;
      --v6;
    }
    while ( v6 );
    v1->mRegionsCreated = 0;
  }
  v7 = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 101
// RVA: 0x55C1E0
void __fastcall UFG::ProgressionTriggerComponent::Update(UFG::ProgressionTriggerComponent *this, float deltaTime)
{
  UFG::ProgressionTriggerComponent *v2; // rdi
  UFG::PDATriggerParameters *v3; // rbp
  char v4; // si
  UFG::SimObjectCharacter *v5; // rax
  unsigned __int16 v6; // dx
  UFG::CharacterOccupantComponent *v7; // rbx
  unsigned int v8; // edx
  unsigned int v9; // er9
  signed __int64 v10; // rbx
  unsigned int v11; // edx
  unsigned int v12; // er9
  unsigned int v13; // edx
  unsigned int v14; // er9
  UFG::SimComponent *v15; // rax
  UFG::SimObject *v16; // rcx
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // rbx
  UFG::UIHK_PDAWidget *v19; // rax
  UFG::UIHK_PDAWidget *v20; // rax
  unsigned __int64 v21; // rcx
  unsigned __int64 v22; // rax
  UFG::GameSliceStreamer *v23; // rax

  v2 = this;
  if ( !this->mEnabled )
    return;
  v3 = this->mpGameSlice->mPDATriggerParameters;
  if ( !v3 || !v3->mIncoming )
    return;
  v4 = 0;
  if ( v3->mVehicleFilter.mUID == -1 )
    goto LABEL_36;
  v5 = UFG::GetLocalPlayer();
  if ( !v5 )
    goto LABEL_37;
  v6 = v5->m_Flags;
  if ( !((v6 >> 14) & 1) )
  {
    if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v11 = v5->mComponentTableEntryCount;
        v12 = v5->m_Components.size;
        if ( v11 < v12 )
        {
          v10 = (signed __int64)&v5->m_Components.p[v11];
          while ( (*(_DWORD *)(v10 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v10 + 8) & 0x1FFFFFF )
          {
            ++v11;
            v10 += 16i64;
            if ( v11 >= v12 )
            {
              v7 = 0i64;
              goto LABEL_31;
            }
          }
          goto LABEL_15;
        }
      }
      else
      {
        if ( !((v6 >> 12) & 1) )
        {
          v7 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v5->vfptr,
                                                    UFG::CharacterOccupantComponent::_TypeUID);
          goto LABEL_31;
        }
        v13 = v5->mComponentTableEntryCount;
        v14 = v5->m_Components.size;
        if ( v13 < v14 )
        {
          v10 = (signed __int64)&v5->m_Components.p[v13];
          while ( (*(_DWORD *)(v10 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v10 + 8) & 0x1FFFFFF )
          {
            ++v13;
            v10 += 16i64;
            if ( v13 >= v14 )
            {
              v7 = 0i64;
              goto LABEL_31;
            }
          }
          goto LABEL_15;
        }
      }
    }
    else
    {
      v8 = v5->mComponentTableEntryCount;
      v9 = v5->m_Components.size;
      if ( v8 < v9 )
      {
        v10 = (signed __int64)&v5->m_Components.p[v8];
        while ( (*(_DWORD *)(v10 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
             || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v10 + 8) & 0x1FFFFFF )
        {
          ++v8;
          v10 += 16i64;
          if ( v8 >= v9 )
            goto LABEL_14;
        }
LABEL_15:
        v7 = *(UFG::CharacterOccupantComponent **)v10;
        goto LABEL_31;
      }
    }
LABEL_14:
    v7 = 0i64;
    goto LABEL_31;
  }
  v7 = (UFG::CharacterOccupantComponent *)v5->m_Components.p[44].m_pComponent;
LABEL_31:
  if ( v7 )
  {
    if ( !UFG::CharacterOccupantComponent::IsEnteringOrExiting(v7) )
    {
      v15 = v7->mCurrentVOC.m_pSimComponent;
      if ( v15 )
      {
        v16 = v15->m_pSimObject;
        if ( v16 )
        {
          if ( UFG::SimObjectUtility::IsClassType(v16, &v3->mVehicleFilter) )
          {
LABEL_36:
            v4 = 1;
            goto LABEL_37;
          }
        }
      }
    }
  }
LABEL_37:
  v17 = v2->mCallTimeout;
  v18 = UFG::Metrics::msInstance.mSimTimeMSec;
  if ( v17 )
  {
    if ( UFG::Metrics::msInstance.mSimTimeMSec > v17 || !v4 )
    {
      UFG::ProgressionTriggerComponent::DisablePDATrigger(v2->mpGameSlice);
      UFG::ProgressionTriggerComponent::UnloadScripts(v2);
      v2->mCallFailTimeout = v18 + 10000;
      return;
    }
    v19 = UFG::UIHK_PDAWidget::Get();
    if ( v19 && UFG::UIHK_PDAWidget::HasAnswered(v19) )
    {
      UFG::ProgressionTriggerComponent::OnActivate(v2);
LABEL_50:
      v23 = UFG::GameSliceStreamer::Instance();
      UFG::GameSliceStreamer::RequestStream(v23, v2->mpGameSlice);
      return;
    }
  }
  else if ( v2->mInsideActiveRegion )
  {
    v20 = UFG::UIHK_PDAWidget::Get();
    if ( v20 )
    {
      if ( v4 )
      {
        v21 = v2->mCallFailTimeout;
        if ( !v21 || v18 > v21 )
        {
          UFG::UIHK_PDAWidget::QueueIncomingPhoneCall(v20, v3->mContactName.mData, 0, 0, 0);
          v22 = UFG::Metrics::msInstance.mSimTimeMSec;
          v2->mCallFailTimeout = 0i64;
          v2->mCallTimeout = v22 + 15000;
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
    ((void (*)(void))v1->mPrev[7].mPrev)();
    v1 = UFG::gpCurrentProgressionTriggerComponent->mNext - 5;
  }
  UFG::gpCurrentProgressionTriggerComponent = 0i64;
}

// File Line: 202
// RVA: 0x5249F0
void __fastcall UFG::ProgressionTriggerComponent::CreateRegions(UFG::ProgressionTriggerComponent *this, UFG::TransformNodeComponent *pTransformNode)
{
  UFG::TransformNodeComponent *v2; // r15
  UFG::ProgressionTriggerComponent *v3; // rbp
  UFG::SimObjectCharacter *v4; // rdi
  UFG::SceneObjectProperties *v5; // rbx
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *v7; // rcx
  UFG::qPropertySet *v8; // rcx
  UFG::qPropertySet *v9; // r13
  float *v10; // rsi
  signed __int64 v11; // rdi
  signed __int64 v12; // r14
  UFG::SceneObjectProperties *v13; // rax
  UFG::qPropertySet *v14; // rax
  UFG::qPropertySet *v15; // rbx
  __int64 v16; // rbx
  UFG::TransformNodeComponent *v17; // rcx
  unsigned __int16 v18; // cx
  unsigned int v19; // er8
  unsigned int v20; // er10
  __int64 v21; // rbx
  signed __int64 v22; // rdx
  UFG::SimComponent *v23; // rbx
  unsigned int v24; // er8
  unsigned int v25; // er10
  unsigned int v26; // er8
  unsigned int v27; // er10
  unsigned int v28; // er8
  unsigned int v29; // er10
  hkSeekableStreamReader *v30; // rax
  hkSeekableStreamReader *v31; // rax
  signed __int64 v32; // rsi
  UFG::TriggerRegion *v33; // rbx
  UFG::SimObject *v34; // rcx
  unsigned __int16 v35; // dx
  unsigned int v36; // er8
  unsigned int v37; // er10
  UFG::SimComponentHolder *v38; // rbx
  signed __int64 v39; // rdx
  UFG::RegionComponent *v40; // rbx
  unsigned int v41; // er8
  unsigned int v42; // er10
  unsigned int v43; // er8
  unsigned int v44; // er10
  unsigned int v45; // er8
  unsigned int v46; // er10
  UFG::TransformNodeComponent *v47; // rdi
  UFG::SimObjectCharacter *v48; // [rsp+20h] [rbp-68h]
  int v49; // [rsp+30h] [rbp-58h]
  int v50; // [rsp+34h] [rbp-54h]
  int v51; // [rsp+38h] [rbp-50h]
  float v52; // [rsp+3Ch] [rbp-4Ch]
  float v53; // [rsp+40h] [rbp-48h]
  UFG::qSymbol result; // [rsp+90h] [rbp+8h]
  UFG::qSymbol name_a; // [rsp+A0h] [rbp+18h]
  UFG::qSymbol objName; // [rsp+A8h] [rbp+20h]

  v2 = pTransformNode;
  v3 = this;
  v4 = UFG::GetLocalPlayer();
  v48 = v4;
  v5 = v3->m_pSimObject->m_pSceneObj;
  v6 = v5->mpWritableProperties;
  if ( !v6 )
    v6 = v5->mpConstProperties;
  v49 = *(_DWORD *)UFG::qPropertySet::Get<float>(v6, (UFG::qSymbol *)&qSymbol_ActivateRadius.mUID, DEPTH_RECURSE);
  v7 = v5->mpWritableProperties;
  if ( !v7 )
    v7 = v5->mpConstProperties;
  v51 = *(_DWORD *)UFG::qPropertySet::Get<float>(v7, (UFG::qSymbol *)&qSymbol_DeactivateRadius.mUID, DEPTH_RECURSE);
  v8 = v5->mpWritableProperties;
  if ( !v8 )
    v8 = v5->mpConstProperties;
  v50 = *(_DWORD *)UFG::qPropertySet::Get<float>(v8, (UFG::qSymbol *)&qSymbol_TriggerRadius.mUID, DEPTH_RECURSE);
  v52 = FLOAT_180_0;
  v53 = FLOAT_200_0;
  if ( !v3->mRegionsCreated )
  {
    if ( !(_S67 & 1) )
    {
      _S67 |= 1u;
      UFG::qSymbol::create_from_string(&triggerPropertySetSymbol_0, "object-logical-TriggerRegion");
      atexit(UFG::ProgressionTriggerComponent::CreateRegions_::_8_::_dynamic_atexit_destructor_for__triggerPropertySetSymbol__);
    }
    v9 = UFG::PropertySetManager::GetPropertySet(&triggerPropertySetSymbol_0);
    v10 = (float *)&v49;
    v11 = (signed __int64)v3->mpRegionSceneObjects;
    v12 = 5i64;
    while ( 1 )
    {
      UFG::qSymbol::create_suffix(&result, &v3->m_pSimObject->m_Name, "_");
      UFG::qSymbol::create_suffix(
        &name_a,
        &result,
        *(const char **)((char *)UFG::ProgressionTriggerRegionTypes - (char *)v3 + v11 - 96));
      UFG::qSymbol::create_suffix(&objName, &name_a, "_PTR");
      v13 = UFG::SceneObjectProperties::Create(&objName, 0i64, v9);
      *(_QWORD *)v11 = v13;
      v14 = UFG::SceneObjectProperties::GetWritableProperties(v13);
      v15 = UFG::RegionComponent::PropertiesAppendDefaultProperty(v14);
      UFG::qPropertySet::Set<unsigned long>(v15, (UFG::qSymbol *)&SimSym_Type.mUID, 2u);
      UFG::qPropertySet::Set<float>(v15, (UFG::qSymbol *)&SimSym_Radius.mUID, *v10);
      UFG::SceneObjectProperties::Activate(*(UFG::SceneObjectProperties **)v11, 1u, 0i64, 0i64);
      v16 = *(_QWORD *)(*(_QWORD *)v11 + 40i64);
      if ( !v16 )
      {
LABEL_44:
        v23 = 0i64;
        goto LABEL_45;
      }
      v17 = *(UFG::TransformNodeComponent **)(v16 + 88);
      if ( v17 )
        UFG::TransformNodeComponent::SetParent(v17, v2, 0);
      v18 = *(_WORD *)(v16 + 76);
      if ( (v18 >> 14) & 1 )
      {
        v19 = *(_DWORD *)(v16 + 128);
        v20 = *(_DWORD *)(v16 + 96);
        if ( v19 >= v20 )
          goto LABEL_44;
        v21 = *(_QWORD *)(v16 + 104);
        while ( 1 )
        {
          v22 = 2i64 * v19;
          if ( (*(_DWORD *)(v21 + 16i64 * v19 + 8) & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
            && !(UFG::TriggerRegion::_TypeUID & ~*(_DWORD *)(v21 + 16i64 * v19 + 8) & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v19 >= v20 )
            goto LABEL_44;
        }
      }
      else if ( (v18 & 0x8000u) == 0 )
      {
        if ( (v18 >> 13) & 1 )
        {
          v26 = *(_DWORD *)(v16 + 128);
          v27 = *(_DWORD *)(v16 + 96);
          if ( v26 >= v27 )
            goto LABEL_44;
          v21 = *(_QWORD *)(v16 + 104);
          while ( 1 )
          {
            v22 = 2i64 * v26;
            if ( (*(_DWORD *)(v21 + 16i64 * v26 + 8) & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
              && !(UFG::TriggerRegion::_TypeUID & ~*(_DWORD *)(v21 + 16i64 * v26 + 8) & 0x1FFFFFF) )
            {
              break;
            }
            if ( ++v26 >= v27 )
              goto LABEL_44;
          }
        }
        else
        {
          if ( !((v18 >> 12) & 1) )
          {
            v23 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v16, UFG::TriggerRegion::_TypeUID);
            goto LABEL_45;
          }
          v28 = *(_DWORD *)(v16 + 128);
          v29 = *(_DWORD *)(v16 + 96);
          if ( v28 >= v29 )
            goto LABEL_44;
          v21 = *(_QWORD *)(v16 + 104);
          while ( 1 )
          {
            v22 = 2i64 * v28;
            if ( (*(_DWORD *)(v21 + 16i64 * v28 + 8) & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
              && !(UFG::TriggerRegion::_TypeUID & ~*(_DWORD *)(v21 + 16i64 * v28 + 8) & 0x1FFFFFF) )
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
        v24 = *(_DWORD *)(v16 + 128);
        v25 = *(_DWORD *)(v16 + 96);
        if ( v24 >= v25 )
          goto LABEL_44;
        v21 = *(_QWORD *)(v16 + 104);
        while ( 1 )
        {
          v22 = 2i64 * v24;
          if ( (*(_DWORD *)(v21 + 16i64 * v24 + 8) & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
            && !(UFG::TriggerRegion::_TypeUID & ~*(_DWORD *)(v21 + 16i64 * v24 + 8) & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v24 >= v25 )
            goto LABEL_44;
        }
      }
      v23 = *(UFG::SimComponent **)(v21 + 8 * v22);
LABEL_45:
      *(_QWORD *)(v11 + 40) = v23;
      v30 = Assembly::GetRCX(v3);
      v23[3].m_BoundComponentHandles.mNode.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)UFG::ProgressionTriggerComponent::OnEnterTrigger;
      v23[3].m_BoundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v30;
      v31 = Assembly::GetRCX(v3);
      v23[4].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)UFG::ProgressionTriggerComponent::OnExitTrigger;
      v23[4].vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v31;
      v11 += 8i64;
      ++v10;
      if ( !--v12 )
      {
        v3->mRegionsCreated = 1;
        v4 = v48;
        break;
      }
    }
  }
  v32 = 0i64;
  do
  {
    v33 = v3->mpTriggerRegions[v32];
    if ( !v33 )
      goto LABEL_87;
    if ( !v4 )
      goto LABEL_87;
    LOBYTE(result.mUID) = 0;
    UFG::TriggerRegion::TrackTarget(v33, (UFG::SimObject *)&v4->vfptr, (bool *)&result);
    if ( v32 )
      goto LABEL_87;
    v34 = v33->m_pSimObject;
    if ( !v34 )
      goto LABEL_87;
    v35 = v34->m_Flags;
    if ( (v35 >> 14) & 1 )
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
          && !(UFG::RegionComponent::_TypeUID & ~v38[v36].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v36 >= v37 )
          goto LABEL_60;
      }
    }
    else if ( (v35 & 0x8000u) == 0 )
    {
      if ( (v35 >> 13) & 1 )
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
            && !(UFG::RegionComponent::_TypeUID & ~v38[v43].m_TypeUID & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v43 >= v44 )
            goto LABEL_60;
        }
      }
      else
      {
        if ( !((v35 >> 12) & 1) )
        {
          v40 = (UFG::RegionComponent *)UFG::SimObject::GetComponentOfType(v34, UFG::RegionComponent::_TypeUID);
          goto LABEL_83;
        }
        v45 = (unsigned int)v34[1].vfptr;
        v46 = v34->m_Components.size;
        if ( v45 >= v46 )
        {
LABEL_60:
          v40 = 0i64;
          goto LABEL_83;
        }
        v38 = v34->m_Components.p;
        while ( 1 )
        {
          v39 = v45;
          if ( (v38[v45].m_TypeUID & 0xFE000000) == (UFG::RegionComponent::_TypeUID & 0xFE000000)
            && !(UFG::RegionComponent::_TypeUID & ~v38[v45].m_TypeUID & 0x1FFFFFF) )
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
          && !(UFG::RegionComponent::_TypeUID & ~v38[v41].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v41 >= v42 )
          goto LABEL_60;
      }
    }
    v40 = (UFG::RegionComponent *)v38[v39].m_pComponent;
LABEL_83:
    if ( v40 )
    {
      v47 = v4->m_pTransformNodeComponent;
      if ( v47 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v47);
        if ( !UFG::RegionComponent::IsHitPoint(v40, (UFG::qVector3 *)&v47->mWorldTransform.v3) )
          v3->mRequiresExitToActivate = 0;
      }
    }
LABEL_87:
    UFG::TriggerRegion::EnableHot(v3->mpTriggerRegions[v32++], 1);
    v4 = v48;
  }
  while ( v32 < 5 );
}

// File Line: 331
// RVA: 0x534B30
void __fastcall UFG::ProgressionTriggerComponent::HandleSpawnPointSpawn(UFG::ProgressionTriggerComponent *this, bool enable)
{
  UFG::ProgressionTriggerComponent *v2; // r14
  UFG::SimObject *v3; // rcx
  bool v4; // bl
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rdi
  unsigned int v7; // er8
  unsigned int v8; // er9
  signed __int64 v9; // rdx
  UFG::SpawnPoint *v10; // rax
  unsigned int v11; // er8
  unsigned int v12; // er9
  unsigned int v13; // er8
  unsigned int v14; // er9
  unsigned int v15; // er8
  unsigned int v16; // er9
  UFG::SimObjectGame *v17; // rax
  UFG::SimObjectProp *v18; // rbx
  unsigned __int16 v19; // dx
  UFG::CharacterAnimationComponent *v20; // rcx
  UFG::CharacterAnimationComponent *v21; // rax
  unsigned int v22; // er8
  unsigned int v23; // er9
  signed __int64 v24; // rdx
  UFG::SceneObjectProperties *v25; // rbp
  UFG::qPropertySet *v26; // rsi
  UFG::qPropertySet *v27; // rax
  unsigned __int16 v28; // cx
  unsigned int v29; // er8
  unsigned int v30; // er9
  signed __int64 v31; // rdx
  unsigned int v32; // er8
  unsigned int v33; // er9
  unsigned int v34; // er8
  unsigned int v35; // er9
  UFG::SimObject *v36; // rax

  v2 = this;
  v3 = this->m_pSimObject;
  v4 = enable;
  if ( !v3 )
    return;
  v5 = v3->m_Flags;
  v6 = 0i64;
  if ( (v5 >> 14) & 1 )
  {
    v7 = (unsigned int)v3[1].vfptr;
    v8 = v3->m_Components.size;
    if ( v7 < v8 )
    {
      v9 = (signed __int64)&v3->m_Components.p[v7];
      while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
      {
        ++v7;
        v9 += 16i64;
        if ( v7 >= v8 )
          goto LABEL_8;
      }
LABEL_9:
      v10 = *(UFG::SpawnPoint **)v9;
      goto LABEL_32;
    }
    goto LABEL_8;
  }
  if ( (v5 & 0x8000u) != 0 )
  {
    v11 = (unsigned int)v3[1].vfptr;
    v12 = v3->m_Components.size;
    if ( v11 < v12 )
    {
      v9 = (signed __int64)&v3->m_Components.p[v11];
      while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
      {
        ++v11;
        v9 += 16i64;
        if ( v11 >= v12 )
        {
          v10 = 0i64;
          goto LABEL_32;
        }
      }
      goto LABEL_9;
    }
LABEL_8:
    v10 = 0i64;
    goto LABEL_32;
  }
  if ( (v5 >> 13) & 1 )
  {
    v13 = (unsigned int)v3[1].vfptr;
    v14 = v3->m_Components.size;
    if ( v13 < v14 )
    {
      v9 = (signed __int64)&v3->m_Components.p[v13];
      while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
      {
        ++v13;
        v9 += 16i64;
        if ( v13 >= v14 )
        {
          v10 = 0i64;
          goto LABEL_32;
        }
      }
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  if ( (v5 >> 12) & 1 )
  {
    v15 = (unsigned int)v3[1].vfptr;
    v16 = v3->m_Components.size;
    if ( v15 < v16 )
    {
      v9 = (signed __int64)&v3->m_Components.p[v15];
      while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
      {
        ++v15;
        v9 += 16i64;
        if ( v15 >= v16 )
        {
          v10 = 0i64;
          goto LABEL_32;
        }
      }
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  v10 = (UFG::SpawnPoint *)UFG::SimObject::GetComponentOfType(v3, UFG::SpawnPoint::_TypeUID);
LABEL_32:
  if ( !v10 )
    return;
  if ( !v4 )
  {
    v36 = Scaleform::GFx::InteractiveObject::GetResourceMovieDef(v10);
    if ( v36 )
      UFG::SimObject::Destroy(v36);
    return;
  }
  v17 = UFG::SpawnPoint::Spawn(v10, 0, 0);
  v18 = (UFG::SimObjectProp *)v17;
  if ( !v17 )
    return;
  UFG::SimObjectUtility::ReinitializeSimObject((UFG::SimObject *)&v17->vfptr, 1, 0);
  v19 = v18->m_Flags;
  if ( (v19 >> 14) & 1 )
  {
    v20 = (UFG::CharacterAnimationComponent *)v18->m_Components.p[9].m_pComponent;
    if ( !v20
      || (UFG::CharacterAnimationComponent::_TypeUID ^ v20->m_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v20->m_TypeUID & 0x1FFFFFF )
    {
      goto LABEL_39;
    }
    goto LABEL_57;
  }
  if ( (v19 & 0x8000u) != 0 )
  {
    v20 = (UFG::CharacterAnimationComponent *)v18->m_Components.p[9].m_pComponent;
    if ( !v20 || (UFG::CharacterAnimationComponent::_TypeUID ^ v20->m_TypeUID) & 0xFE000000 )
      goto LABEL_39;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v20->m_TypeUID & 0x1FFFFFF )
      v20 = 0i64;
    goto LABEL_57;
  }
  if ( (v19 >> 13) & 1 )
  {
    v21 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v18);
LABEL_56:
    v20 = v21;
    goto LABEL_57;
  }
  if ( !((v19 >> 12) & 1) )
  {
    v21 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v18->vfptr,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_56;
  }
  v22 = v18->mComponentTableEntryCount;
  v23 = v18->m_Components.size;
  if ( v22 >= v23 )
  {
LABEL_39:
    v20 = 0i64;
    goto LABEL_57;
  }
  v24 = (signed __int64)&v18->m_Components.p[v22];
  while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF )
  {
    ++v22;
    v24 += 16i64;
    if ( v22 >= v23 )
    {
      v20 = 0i64;
      goto LABEL_57;
    }
  }
  v20 = *(UFG::CharacterAnimationComponent **)v24;
LABEL_57:
  if ( v20 && v2->mpGameSlice->mFaceActionType != 18 )
  {
    v25 = v18->m_pSceneObj;
    v26 = UFG::SceneObjectProperties::GetWritableProperties(v25);
    if ( !UFG::qPropertySet::GetParentFromName(
            v26,
            (UFG::qSymbol *)&SimSymX_propset_componentFaceAction.mUID,
            DEPTH_RECURSE) )
    {
      v27 = UFG::PropertySetManager::CreateOrFindPropertySet((UFG::qSymbol *)&SimSymX_propset_componentFaceAction.mUID);
      UFG::PSWrapper::AppendParentLocal(v26, v27);
    }
    UFG::qPropertySet::Set<UFG::qSymbol>(
      v26,
      (UFG::qSymbol *)&SimSym_FaceAction.mUID,
      (UFG::qSymbol *)&UFG::FaceActionEnumSymbols[v2->mpGameSlice->mFaceActionType].mUID);
    UFG::qPropertySet::Set<unsigned long>(v26, (UFG::qSymbol *)&SimSym_PipsRequired.mUID, v2->mpGameSlice->mMinPipLevel);
    UFG::qPropertySet::Set<bool>(v26, (UFG::qSymbol *)&SimSym_Hidden.mUID, 0);
    UFG::qPropertySet::Set<bool>(v26, (UFG::qSymbol *)&SimSym_RemoveOnCompletion.mUID, 1);
    v28 = v18->m_Flags;
    if ( (v28 >> 14) & 1 )
    {
      v6 = v18->m_Components.p[45].m_pComponent;
      goto LABEL_86;
    }
    if ( (v28 & 0x8000u) != 0 )
    {
      v29 = v18->mComponentTableEntryCount;
      v30 = v18->m_Components.size;
      if ( v29 >= v30 )
        goto LABEL_86;
      v31 = (signed __int64)&v18->m_Components.p[v29];
      while ( (*(_DWORD *)(v31 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
           || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v31 + 8) & 0x1FFFFFF )
      {
        ++v29;
        v31 += 16i64;
        if ( v29 >= v30 )
          goto LABEL_86;
      }
      goto LABEL_70;
    }
    if ( (v28 >> 13) & 1 )
    {
      v32 = v18->mComponentTableEntryCount;
      v33 = v18->m_Components.size;
      if ( v32 < v33 )
      {
        v31 = (signed __int64)&v18->m_Components.p[v32];
        while ( (*(_DWORD *)(v31 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
             || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v31 + 8) & 0x1FFFFFF )
        {
          ++v32;
          v31 += 16i64;
          if ( v32 >= v33 )
            goto LABEL_86;
        }
LABEL_70:
        v6 = *(UFG::SimComponent **)v31;
        goto LABEL_86;
      }
    }
    else if ( (v28 >> 12) & 1 )
    {
      v34 = v18->mComponentTableEntryCount;
      v35 = v18->m_Components.size;
      if ( v34 < v35 )
      {
        v31 = (signed __int64)&v18->m_Components.p[v34];
        while ( (*(_DWORD *)(v31 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
             || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v31 + 8) & 0x1FFFFFF )
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
      v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v18->vfptr, UFG::FaceActionComponent::_TypeUID);
    }
LABEL_86:
    if ( v6 )
      v6->vfptr[12].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v6->vfptr, (unsigned int)v25);
    else
      UFG::FaceActionComponent::CreateFaceActionComponent(v25);
  }
}

// File Line: 390
// RVA: 0x526790
void __fastcall UFG::ProgressionTriggerComponent::Enable(UFG::ProgressionTriggerComponent *this, UFG::GameSlice *pGameSlice)
{
  UFG::ProgressionTriggerComponent *v2; // rbx
  UFG::SimObject *v3; // rax
  UFG::SceneObjectProperties *v4; // rdx
  UFG::qPropertySet *v5; // rcx
  UFG::TransformNodeComponent *v6; // rdx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v7; // rdx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v8; // rcx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v9; // rax
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v10; // rax

  v2 = this;
  if ( !this->mEnabled )
  {
    v3 = this->m_pSimObject;
    this->mpGameSlice = pGameSlice;
    v4 = v3->m_pSceneObj;
    v5 = v4->mpWritableProperties;
    if ( !v5 )
      v5 = v4->mpConstProperties;
    UFG::qPropertySet::Get<char const *>(v5, (UFG::qSymbol *)&qSymbol_IndicatorType.mUID, DEPTH_RECURSE);
    v6 = (UFG::TransformNodeComponent *)v2->m_pSimObject;
    if ( v6 )
      v6 = (UFG::TransformNodeComponent *)v6->mChildren.mNode.mNext;
    UFG::ProgressionTriggerComponent::CreateRegions(v2, v6);
    if ( !v2->mRequiresExitToActivate )
      UFG::ProgressionTriggerComponent::EnableObjective(v2);
    v7 = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *)&v2->mPrev;
    if ( v7->mPrev != v7 || (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> **)v2->mNext != &v2->mPrev )
    {
      v8 = v7->mPrev;
      v9 = v2->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = v7;
      v2->mNext = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *)&v2->mPrev;
    }
    v10 = smProgressionTriggerComponent_UpdateList.mNode.mPrev;
    smProgressionTriggerComponent_UpdateList.mNode.mPrev->mNext = v7;
    v7->mPrev = v10;
    v2->mNext = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *)&smProgressionTriggerComponent_UpdateList;
    smProgressionTriggerComponent_UpdateList.mNode.mPrev = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *)&v2->mPrev;
    v2->mEnabled = 1;
  }
}

// File Line: 424
// RVA: 0x526D50
void __fastcall UFG::ProgressionTriggerComponent::EnableObjective(UFG::ProgressionTriggerComponent *this)
{
  UFG::ProgressionTriggerComponent *v1; // rbx
  UFG::SceneObjectProperties *v2; // rdx
  UFG::qPropertySet *v3; // rcx
  char *v4; // rax
  UFG::ProgressionTracker *v5; // rax
  UFG::qString identifier; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = this->m_pSimObject->m_pSceneObj;
  v3 = v2->mpWritableProperties;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v4 = UFG::qPropertySet::Get<char const *>(v3, (UFG::qSymbol *)&qSymbol_Objective.mUID, DEPTH_RECURSE);
  if ( v4 )
  {
    if ( *v4 )
    {
      UFG::qString::qString(&identifier, v4);
      v5 = UFG::ProgressionTracker::Instance();
      UFG::ObjectiveTracker::UpdateStatus(&v5->mObjectiveTracker, &identifier, STATUS_ACTIVE, v1->mpGameSlice);
      UFG::qString::~qString(&identifier);
    }
  }
}

// File Line: 436
// RVA: 0x526030
void __fastcall UFG::ProgressionTriggerComponent::Disable(UFG::ProgressionTriggerComponent *this, bool turnLayerOn)
{
  bool v2; // bp
  UFG::ProgressionTriggerComponent *v3; // rdi
  UFG::TriggerRegion **v4; // rbx
  signed __int64 v5; // rsi
  UFG::SceneObjectProperties *v6; // rdx
  UFG::qPropertySet *v7; // rcx
  char *v8; // rax
  UFG::qString *v9; // rax
  UFG::qString *v10; // rbx
  UFG::ProgressionTracker *v11; // rax
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v12; // rdx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v13; // rcx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v14; // rax
  UFG::qString v15; // [rsp+28h] [rbp-30h]

  v2 = turnLayerOn;
  v3 = this;
  if ( this->mEnabled )
  {
    v4 = this->mpTriggerRegions;
    v5 = 5i64;
    do
    {
      UFG::TriggerRegion::EnableHot(*v4, 0);
      ++v4;
      --v5;
    }
    while ( v5 );
    if ( !v3->mpGameSlice->mKeepTriggerObjectiveEnabled || !v2 )
    {
      v6 = v3->m_pSimObject->m_pSceneObj;
      v7 = v6->mpWritableProperties;
      if ( !v7 )
        v7 = v6->mpConstProperties;
      v8 = UFG::qPropertySet::Get<char const *>(v7, (UFG::qSymbol *)&qSymbol_Objective.mUID, DEPTH_RECURSE);
      if ( v8 && *v8 )
      {
        UFG::qString::qString(&v15, v8);
        v10 = v9;
        v11 = UFG::ProgressionTracker::Instance();
        UFG::ObjectiveTracker::UpdateStatus(&v11->mObjectiveTracker, v10, 0, v3->mpGameSlice);
        UFG::qString::~qString(&v15);
      }
    }
    UFG::GameSlice::SetWaitingForTrigger(v3->mpGameSlice, 0, v2);
    if ( !v2 )
      UFG::ProgressionTriggerComponent::HandleSpawnPointSpawn(v3, 0);
    v12 = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *)&v3->mPrev;
    if ( v12->mPrev != v12 || (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> **)v3->mNext != &v3->mPrev )
    {
      if ( v3 == UFG::gpCurrentProgressionTriggerComponent )
        UFG::gpCurrentProgressionTriggerComponent = (UFG::ProgressionTriggerComponent *)&UFG::gpCurrentProgressionTriggerComponent->mPrev[-5];
      v13 = v12->mPrev;
      v14 = v3->mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v12->mPrev = v12;
      v3->mNext = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *)&v3->mPrev;
    }
    v3->mEnabled = 0;
  }
}

// File Line: 477
// RVA: 0x526530
void __fastcall UFG::ProgressionTriggerComponent::DisablePDATrigger(UFG::GameSlice *pGameSlice)
{
  UFG::PDATriggerParameters *v1; // rax
  UFG::ProgressionTriggerComponent *v2; // rbx
  UFG::UIHK_PDAWidget *v3; // rax
  UFG::PDATriggerTracker *v4; // rcx
  UFG::qSymbol identifier; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v6; // [rsp+48h] [rbp+10h]

  v1 = pGameSlice->mPDATriggerParameters;
  if ( pGameSlice->mTriggerObjectName.mUID == -1 )
  {
    if ( v1 )
    {
      v6 = &identifier;
      identifier.mUID = v1->mContactSymbol.mUID;
      v4 = &UFG::ProgressionTracker::Instance()->mPDATriggerTracker;
      UFG::PDATriggerTracker::Remove(v4, (__int64)&identifier);
    }
  }
  else if ( v1 )
  {
    if ( v1->mIncoming )
    {
      v2 = UFG::ProgressionTriggerComponent::GetComponent(pGameSlice);
      if ( v2 )
      {
        v3 = UFG::UIHK_PDAWidget::Get();
        if ( v3 )
        {
          UFG::UIHK_PDAWidget::EndPhoneCall(v3, 1);
          v2->mCallTimeout = 0i64;
        }
      }
    }
  }
}

// File Line: 505
// RVA: 0x52B990
UFG::SimComponent *__fastcall UFG::ProgressionTriggerComponent::GetComponent(UFG::GameSlice *pGameSlice)
{
  UFG::qBaseNodeRB *v1; // rax
  unsigned __int16 v2; // dx
  unsigned int v3; // er9
  unsigned int v4; // er10
  _DWORD *v5; // rdx
  unsigned int v7; // er9
  unsigned int v8; // er10
  unsigned int v9; // er9
  unsigned int v10; // er10
  unsigned int v11; // er9
  unsigned int v12; // er10

  if ( pGameSlice->mTriggerObjectName.mUID == -1 )
    return 0i64;
  v1 = UFG::Simulation::GetSimObject(&UFG::gSim, &pGameSlice->mTriggerObjectName);
  if ( !v1 )
    return 0i64;
  v2 = WORD2(v1[2].mChild[0]);
  if ( (v2 >> 14) & 1 )
  {
    v3 = (unsigned int)v1[4].mParent;
    v4 = (unsigned int)v1[3].mParent;
    if ( v3 < v4 )
    {
      v5 = (_DWORD *)((char *)v1[3].mChild[0] + 16 * v3);
      while ( (v5[2] & 0xFE000000) != (UFG::ProgressionTriggerComponent::_TypeUID & 0xFE000000)
           || UFG::ProgressionTriggerComponent::_TypeUID & ~v5[2] & 0x1FFFFFF )
      {
        ++v3;
        v5 += 4;
        if ( v3 >= v4 )
          return 0i64;
      }
      return *(UFG::SimComponent **)v5;
    }
    return 0i64;
  }
  if ( (v2 & 0x8000u) != 0 )
  {
    v7 = (unsigned int)v1[4].mParent;
    v8 = (unsigned int)v1[3].mParent;
    if ( v7 < v8 )
    {
      v5 = (_DWORD *)((char *)v1[3].mChild[0] + 16 * v7);
      while ( (v5[2] & 0xFE000000) != (UFG::ProgressionTriggerComponent::_TypeUID & 0xFE000000)
           || UFG::ProgressionTriggerComponent::_TypeUID & ~v5[2] & 0x1FFFFFF )
      {
        ++v7;
        v5 += 4;
        if ( v7 >= v8 )
          return 0i64;
      }
      return *(UFG::SimComponent **)v5;
    }
    return 0i64;
  }
  if ( (v2 >> 13) & 1 )
  {
    v9 = (unsigned int)v1[4].mParent;
    v10 = (unsigned int)v1[3].mParent;
    if ( v9 < v10 )
    {
      v5 = (_DWORD *)((char *)v1[3].mChild[0] + 16 * v9);
      while ( (v5[2] & 0xFE000000) != (UFG::ProgressionTriggerComponent::_TypeUID & 0xFE000000)
           || UFG::ProgressionTriggerComponent::_TypeUID & ~v5[2] & 0x1FFFFFF )
      {
        ++v9;
        v5 += 4;
        if ( v9 >= v10 )
          return 0i64;
      }
      return *(UFG::SimComponent **)v5;
    }
    return 0i64;
  }
  if ( (v2 >> 12) & 1 )
  {
    v11 = (unsigned int)v1[4].mParent;
    v12 = (unsigned int)v1[3].mParent;
    if ( v11 < v12 )
    {
      v5 = (_DWORD *)((char *)v1[3].mChild[0] + 16 * v11);
      while ( (v5[2] & 0xFE000000) != (UFG::ProgressionTriggerComponent::_TypeUID & 0xFE000000)
           || UFG::ProgressionTriggerComponent::_TypeUID & ~v5[2] & 0x1FFFFFF )
      {
        ++v11;
        v5 += 4;
        if ( v11 >= v12 )
          return 0i64;
      }
      return *(UFG::SimComponent **)v5;
    }
    return 0i64;
  }
  return UFG::SimObject::GetComponentOfType((UFG::SimObject *)v1, UFG::ProgressionTriggerComponent::_TypeUID);
}

// File Line: 524
// RVA: 0x53C060
char __fastcall UFG::ProgressionTriggerComponent::IsRestoring(UFG::GameSlice *pGameSlice)
{
  UFG::GameSlice *v1; // rsi
  int v2; // ebx
  int v3; // edi

  v1 = pGameSlice;
  if ( pGameSlice->mState == 2 )
    return 0;
  v2 = 0;
  v3 = UFG::GameSlice::GetNumChildren(pGameSlice);
  if ( v3 <= 0 )
    return 0;
  while ( UFG::GameSlice::GetChild(v1, v2)->mState < 2 )
  {
    if ( ++v2 >= v3 )
      return 0;
  }
  return 1;
}

// File Line: 542
// RVA: 0x526E60
void __fastcall UFG::ProgressionTriggerComponent::EnableTrigger(UFG::GameSlice *pGameSlice)
{
  UFG::GameSlice *v1; // rbx
  bool v2; // di
  UFG::PDATriggerParameters *v3; // rsi
  UFG::ProgressionTriggerComponent *v4; // rax
  UFG::PDATriggerTracker *v5; // rcx
  UFG::ProgressionTracker *v6; // rax
  UFG::GameSlice *v7; // rax
  UFG::GameSliceStreamer *v8; // rax
  UFG::qSymbol identifier; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v10; // [rsp+48h] [rbp+10h]

  v1 = pGameSlice;
  v2 = 0;
  v3 = pGameSlice->mPDATriggerParameters;
  if ( UFG::GameSlice::GetParent(pGameSlice) )
  {
    v7 = UFG::GameSlice::GetParent(v1);
    v2 = UFG::GameSlice::IsWaitingForTrigger(v7);
    if ( v2 )
      goto LABEL_13;
    goto LABEL_12;
  }
  if ( v1->mTriggerObjectName.mUID != -1 )
  {
    if ( !UFG::ProgressionTriggerComponent::IsRestoring(v1) )
    {
      v4 = UFG::ProgressionTriggerComponent::GetComponent(v1);
      if ( v4 )
      {
        UFG::ProgressionTriggerComponent::Enable(v4, v1);
        v2 = 1;
        goto LABEL_13;
      }
    }
LABEL_12:
    v8 = UFG::GameSliceStreamer::Instance();
    UFG::GameSliceStreamer::RequestStream(v8, v1);
    goto LABEL_13;
  }
  if ( !v3 || UFG::ProgressionTriggerComponent::IsRestoring(v1) )
    goto LABEL_12;
  v10 = &identifier;
  identifier.mUID = v3->mContactSymbol.mUID;
  v5 = &UFG::ProgressionTracker::Instance()->mPDATriggerTracker;
  UFG::PDATriggerTracker::Add(v5, (__int64)&identifier, v1);
  if ( v3->mObjectiveName.mLength )
  {
    v6 = UFG::ProgressionTracker::Instance();
    UFG::ObjectiveTracker::UpdateStatus(&v6->mObjectiveTracker, &v3->mObjectiveName, STATUS_ACTIVE, v1);
  }
  v2 = 1;
LABEL_13:
  UFG::GameSlice::SetWaitingForTrigger(v1, v2, 1);
}

// File Line: 594
// RVA: 0x5207E0
void __fastcall UFG::ProgressionTriggerComponent::ActiveateOnlyAfterExitFromRegion(UFG::GameSlice *pGameSlice)
{
  UFG::ProgressionTriggerComponent *v1; // rax

  v1 = UFG::ProgressionTriggerComponent::GetComponent(pGameSlice);
  if ( v1 )
    v1->mRequiresExitToActivate = 1;
}

// File Line: 603
// RVA: 0x5265C0
void __fastcall UFG::ProgressionTriggerComponent::DisableTrigger(UFG::GameSlice *pGameSlice, bool turnLayerOn)
{
  bool v2; // di
  UFG::GameSlice *v3; // rbx
  UFG::PDATriggerParameters *v4; // rax
  UFG::ProgressionTriggerComponent *v5; // rax
  UFG::PDATriggerTracker *v6; // rcx
  UFG::qSymbol identifier; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v8; // [rsp+50h] [rbp+18h]

  v2 = turnLayerOn;
  v3 = pGameSlice;
  do
  {
    v4 = v3->mPDATriggerParameters;
    if ( v3->mTriggerObjectName.mUID == -1 )
    {
      if ( v4 )
      {
        v8 = &identifier;
        identifier.mUID = v4->mContactSymbol.mUID;
        v6 = &UFG::ProgressionTracker::Instance()->mPDATriggerTracker;
        UFG::PDATriggerTracker::Remove(v6, (__int64)&identifier);
      }
    }
    else
    {
      v5 = UFG::ProgressionTriggerComponent::GetComponent(v3);
      if ( v5 )
        UFG::ProgressionTriggerComponent::Disable(v5, v2);
    }
    v3 = UFG::GameSlice::GetParent(v3);
  }
  while ( v3 );
}

// File Line: 630
// RVA: 0x53CD20
void __fastcall UFG::ProgressionTriggerComponent::OnActivate(UFG::GameSlice *pGameSlice)
{
  UFG::GameSlice *v1; // rbx
  UFG::PDATriggerParameters *v2; // rdi
  UFG::ProgressionTriggerComponent *v3; // rax
  UFG::GameSliceStreamer *v4; // rax
  UFG::PDATriggerTracker *v5; // rcx
  UFG::qSymbol identifier; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v7; // [rsp+48h] [rbp+10h]

  v1 = pGameSlice;
  v2 = pGameSlice->mPDATriggerParameters;
  if ( pGameSlice->mTriggerObjectName.mUID == -1 )
  {
    if ( v2 )
    {
      v4 = UFG::GameSliceStreamer::Instance();
      UFG::GameSliceStreamer::RequestStream(v4, v1);
      v7 = &identifier;
      identifier.mUID = v2->mContactSymbol.mUID;
      v5 = &UFG::ProgressionTracker::Instance()->mPDATriggerTracker;
      UFG::PDATriggerTracker::Remove(v5, (__int64)&identifier);
      UFG::GameSlice::SetWaitingForTrigger(v1, 0, 1);
    }
  }
  else
  {
    v3 = (UFG::ProgressionTriggerComponent *)UFG::ProgressionTriggerComponent::GetComponent(pGameSlice);
    if ( v3 )
      UFG::ProgressionTriggerComponent::OnActivate(v3);
  }
}

// File Line: 653
// RVA: 0x535720
bool __fastcall UFG::ProgressionTriggerComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentProgressionTrigger.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 659
// RVA: 0x5453B0
UFG::SimComponent *__fastcall UFG::ProgressionTriggerComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rdi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0xD0ui64, "ProgressionTriggerComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::ProgressionTriggerComponent::ProgressionTriggerComponent((UFG::ProgressionTriggerComponent *)v3, v1->m_NameUID);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v7, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v7, v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v7);
  UFG::SimObjectModifier::~SimObjectModifier(&v7);
  return v5;
}

// File Line: 699
// RVA: 0x52A2F0
void __fastcall UFG::ProgressionTriggerComponent::ForceOnEnter(UFG::ProgressionTriggerComponent *this)
{
  UFG::ProgressionTriggerComponent *v1; // rbx
  UFG::GameSliceStreamer *v2; // rax
  UFG::GameSlice *v3; // rcx
  UFG::PDATriggerParameters *v4; // rax

  v1 = this;
  v2 = UFG::GameSliceStreamer::Instance();
  UFG::GameSliceStreamer::RequestStream(v2, v1->mpGameSlice);
  v3 = v1->mpGameSlice;
  v4 = v3->mPDATriggerParameters;
  v1->mInsideActiveRegion = 1;
  if ( !v4 )
  {
    UFG::GameSlice::_EnableLayer(v3);
    UFG::ProgressionTriggerComponent::HandleSpawnPointSpawn(v1, 1);
  }
  if ( !v1->mpGameSlice->mPDATriggerParameters )
    UFG::ProgressionTriggerComponent::OnActivate(v1);
  *(_WORD *)&v1->mWaitMenuActive = 0;
  v1->mRequiresExitToActivate = 0;
}

// File Line: 709
// RVA: 0x5413D0
void __fastcall UFG::ProgressionTriggerComponent::OnEnterTrigger(UFG::ProgressionTriggerComponent *this, UFG::TriggerRegion *pTriggerRegion)
{
  UFG::TriggerRegion *v2; // rdi
  UFG::ProgressionTriggerComponent *v3; // rbx
  UFG::GameSlice *v4; // rsi
  UFG::GameSliceStreamer *v5; // rax
  UFG::GameSlice *v6; // rsi
  UFG::ProgressionTracker *v7; // rax
  UFG::GameSlice *v8; // rcx
  UFG::PDATriggerParameters *v9; // rax
  UFG::GameSliceStreamer *v10; // rax

  v2 = pTriggerRegion;
  v3 = this;
  if ( pTriggerRegion == this->mpTriggerRegions[3] )
  {
    v4 = this->mpGameSlice;
    if ( !v4->mPDATriggerParameters )
    {
      v5 = UFG::GameSliceStreamer::Instance();
      UFG::GameSliceStreamer::RequestStream(v5, v4);
    }
  }
  if ( !UFG::GameSlice::IsAllowedAtThisTimeOfDay(v3->mpGameSlice) || v3->mRequiresTODWait )
  {
    v6 = v3->mpGameSlice;
    if ( v6->mPerformTimeShift && v2 == v3->mpTriggerRegions[1] )
    {
      *(_WORD *)&v3->mWaitMenuActive = 257;
      v7 = UFG::ProgressionTracker::Instance();
      UFG::ProgressionTracker::EnableGameSliceTODWait(v7, v6, v3);
    }
    v3->mRequiresExitToActivate = 1;
  }
  if ( !v3->mRequiresExitToActivate )
  {
    if ( v2 == v3->mpTriggerRegions[1] )
    {
      if ( !v3->mpGameSlice->mPDATriggerParameters )
        UFG::ProgressionTriggerComponent::OnActivate(v3);
    }
    else
    {
      if ( v2 != v3->mpTriggerRegions[0] )
        return;
      v8 = v3->mpGameSlice;
      v9 = v8->mPDATriggerParameters;
      v3->mInsideActiveRegion = 1;
      if ( !v9 )
      {
        UFG::GameSlice::_EnableLayer(v8);
        UFG::ProgressionTriggerComponent::HandleSpawnPointSpawn(v3, 1);
      }
    }
    v10 = UFG::GameSliceStreamer::Instance();
    UFG::GameSliceStreamer::RequestStream(v10, v3->mpGameSlice);
  }
}

// File Line: 758
// RVA: 0x558650
UFG::ProgressionTriggerComponent::UnloadScripts

// File Line: 773
// RVA: 0x541D00
void __fastcall UFG::ProgressionTriggerComponent::OnExitTrigger(UFG::ProgressionTriggerComponent *this, UFG::TriggerRegion *pTriggerRegion)
{
  UFG::TriggerRegion *v2; // rdi
  UFG::ProgressionTriggerComponent *v3; // rbx
  UFG::ProgressionTracker *v4; // rax
  UFG::GameSlice *v5; // rcx

  v2 = pTriggerRegion;
  v3 = this;
  if ( pTriggerRegion == this->mpTriggerRegions[4] && !this->mpGameSlice->mPDATriggerParameters )
    UFG::ProgressionTriggerComponent::UnloadScripts(this);
  if ( v2 == v3->mpTriggerRegions[1] && v3->mWaitMenuActive )
  {
    v3->mWaitMenuActive = 0;
    v4 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::EnableGameSliceTODWait(v4, 0i64, 0i64);
  }
  if ( v2 == v3->mpTriggerRegions[0] )
  {
    if ( v3->mRequiresExitToActivate )
      UFG::ProgressionTriggerComponent::EnableObjective(v3);
    v3->mRequiresExitToActivate = 0;
    v3->mRequiresTODWait = 0;
  }
  else if ( v2 == v3->mpTriggerRegions[2] )
  {
    v5 = v3->mpGameSlice;
    if ( v5->mPDATriggerParameters )
    {
      UFG::ProgressionTriggerComponent::DisablePDATrigger(v5);
      UFG::ProgressionTriggerComponent::UnloadScripts(v3);
    }
    else
    {
      UFG::GameSlice::_DisableLayer(v5);
      UFG::ProgressionTriggerComponent::HandleSpawnPointSpawn(v3, 0);
    }
    v3->mInsideActiveRegion = 0;
  }
}

// File Line: 824
// RVA: 0x53CBC0
void __fastcall UFG::ProgressionTriggerComponent::OnActivate(UFG::ProgressionTriggerComponent *this)
{
  UFG::ProgressionTriggerComponent *v1; // rdi
  UFG::TriggerRegion **v2; // rbx
  signed __int64 v3; // rsi
  UFG::SceneObjectProperties *v4; // rdx
  UFG::qPropertySet *v5; // rcx
  char *v6; // rax
  UFG::qString *v7; // rax
  UFG::qString *v8; // rbx
  UFG::ProgressionTracker *v9; // rax
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v10; // rdx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v11; // rcx
  UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *v12; // rax
  UFG::qString v13; // [rsp+28h] [rbp-30h]

  v1 = this;
  if ( this->mEnabled )
  {
    v2 = this->mpTriggerRegions;
    v3 = 5i64;
    do
    {
      UFG::TriggerRegion::EnableHot(*v2, 0);
      ++v2;
      --v3;
    }
    while ( v3 );
    if ( !v1->mpGameSlice->mKeepTriggerObjectiveEnabled )
    {
      v4 = v1->m_pSimObject->m_pSceneObj;
      v5 = v4->mpWritableProperties;
      if ( !v5 )
        v5 = v4->mpConstProperties;
      v6 = UFG::qPropertySet::Get<char const *>(v5, (UFG::qSymbol *)&qSymbol_Objective.mUID, DEPTH_RECURSE);
      if ( v6 && *v6 )
      {
        UFG::qString::qString(&v13, v6);
        v8 = v7;
        v9 = UFG::ProgressionTracker::Instance();
        UFG::ObjectiveTracker::UpdateStatus(&v9->mObjectiveTracker, v8, 0, v1->mpGameSlice);
        UFG::qString::~qString(&v13);
      }
    }
    UFG::GameSlice::SetWaitingForTrigger(v1->mpGameSlice, 0, 1);
    v10 = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *)&v1->mPrev;
    if ( v10->mPrev != v10 || (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> **)v1->mNext != &v1->mPrev )
    {
      if ( v1 == UFG::gpCurrentProgressionTriggerComponent )
        UFG::gpCurrentProgressionTriggerComponent = (UFG::ProgressionTriggerComponent *)&UFG::gpCurrentProgressionTriggerComponent->mPrev[-5];
      v11 = v10->mPrev;
      v12 = v1->mNext;
      v11->mNext = v12;
      v12->mPrev = v11;
      v10->mPrev = v10;
      v1->mNext = (UFG::qNode<UFG::ProgressionTriggerComponent,UFG::UpdateList> *)&v1->mPrev;
    }
    v1->mEnabled = 0;
  }
  UFG::ProgressionTriggerComponent::DisablePDATrigger(v1->mpGameSlice);
  UFG::GameSlice::_EnableLayer(v1->mpGameSlice);
  UFG::GameSlice::StopDrivenVehicle(v1->mpGameSlice);
  UFG::ProgressionTriggerComponent::HandleSpawnPointSpawn(v1, 1);
}

