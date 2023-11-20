// File Line: 42
// RVA: 0x1475360
void dynamic_initializer_for__gLayer_InFrustum_ActDistSqrd__()
{
  gLayer_InFrustum_ActDistSqrd = gLayer_InFrustum_ActivationDistance * gLayer_InFrustum_ActivationDistance;
}

// File Line: 45
// RVA: 0x1475380
void dynamic_initializer_for__gLayer_OutFrustum_ActDistSqrd__()
{
  gLayer_OutFrustum_ActDistSqrd = gLayer_OutFrustum_ActivationDistance * gLayer_OutFrustum_ActivationDistance;
}

// File Line: 55
// RVA: 0x1475330
__int64 UFG::_dynamic_initializer_for__gLayerTrapName__()
{
  UFG::qString::qString(&UFG::gLayerTrapName, "none");
  return atexit(UFG::_dynamic_atexit_destructor_for__gLayerTrapName__);
}

// File Line: 115
// RVA: 0x23D820
UFG::GeographicalLayerManager *__fastcall UFG::GeographicalLayerManager::GetInstance()
{
  if ( !(_S1_28 & 1) )
  {
    _S1_28 |= 1u;
    sInstance_0.mActiveLayers.mNode.mPrev = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&sInstance_0;
    unk_1423AA8E8 = &sInstance_0;
    stru_1423AA8F0.mNode.mPrev = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&stru_1423AA8F0;
    stru_1423AA8F0.mNode.mNext = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&stru_1423AA8F0;
    stru_1423AA900.mNode.mPrev = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&stru_1423AA900;
    stru_1423AA900.mNode.mNext = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&stru_1423AA900;
    unk_1423AA910 = -1;
    unk_1423AA914 = 1;
    atexit(UFG::GeographicalLayerManager::GetInstance_::_2_::_dynamic_atexit_destructor_for__sInstance__);
  }
  UFG::GeographicalLayerManager::mpInstance = &sInstance_0;
  return &sInstance_0;
}

// File Line: 129
// RVA: 0x2454B0
void __fastcall UFG::GeographicalLayerManager::SetActiveCategory(UFG::qSymbol *category)
{
  UFG::GeographicalLayerManager::mpInstance->mActiveCategory = (UFG::qSymbol)category->mUID;
  UFG::GeographicalLayerManager::mpInstance->mAllowImmediateActivation = 1;
}

// File Line: 140
// RVA: 0x23BFA0
UFG::qSymbol *__fastcall UFG::GeographicalLayerManager::GetActiveCategory()
{
  return &UFG::GeographicalLayerManager::mpInstance->mActiveCategory;
}

// File Line: 162
// RVA: 0x23A230
void __fastcall UFG::GeographicalLayerManager::ClearDeactivationTimers(UFG::GeographicalLayerManager *this)
{
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v1; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> **v2; // rcx
  signed __int64 i; // rax

  v1 = this->mActiveLayers.mNode.mNext;
  v2 = &this[-1].mInactiveLayers.mNode.mNext;
  for ( i = (signed __int64)&v1[-2];
        (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> **)i != v2;
        i = *(_QWORD *)(i + 40) - 32i64 )
  {
    *(_DWORD *)(i + 104) = 0;
  }
}

// File Line: 180
// RVA: 0x245D40
void __fastcall UFG::GeographicalLayerManager::TrackLayer(UFG::GeographicalLayerManager *this, UFG::SceneLayer *pSceneLayer)
{
  UFG::SceneLayer *v2; // r8
  UFG::GeographicalLayerManager *v3; // rdx
  unsigned int v4; // ecx
  bool v5; // zf
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v6; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v7; // rax

  v2 = pSceneLayer;
  v3 = this;
  v4 = v2->mFlags;
  if ( !((v2->mFlags >> 15) & 1) )
  {
    if ( (v4 >> 7) & 1 )
    {
      v5 = ((v4 >> 1) & 1) == 0;
      v6 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&v2->mPrev;
      if ( v5 )
        v3 = (UFG::GeographicalLayerManager *)((char *)v3 + 16);
    }
    else
    {
      v3 = (UFG::GeographicalLayerManager *)((char *)v3 + 32);
      v6 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&v2->mPrev;
    }
    v7 = v3->mActiveLayers.mNode.mPrev;
    v7->mNext = v6;
    v6->mPrev = v7;
    v6->mNext = &v3->mActiveLayers.mNode;
    v3->mActiveLayers.mNode.mPrev = v6;
    v2->mFlags |= 0x8000u;
  }
}

// File Line: 266
// RVA: 0x245960
__int64 __fastcall UFG::GeographicalLayerManager::TestForActivateOnList(UFG::GeographicalLayerManager *this, UFG::qList<UFG::SceneLayer,UFG::SceneLayer,1,0> *list, bool isActiveList, UFG::qVector3 *testPos)
{
  UFG::qVector3 *v4; // r12
  bool v5; // r13
  UFG::GeographicalLayerManager *v6; // rbx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v7; // r14
  char *v8; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v9; // r8
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v10; // rdx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v11; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v12; // rax
  unsigned int v13; // ecx
  bool v14; // zf
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v15; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v16; // rax
  UFG::qList<UFG::SceneLayer,UFG::SceneLayer,1,0> *v17; // rdx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v18; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v19; // rcx
  __int64 v20; // rdi
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v21; // rbx
  UFG::SceneLayerResource *v22; // rbx
  UFG::allocator::free_link *v23; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v24; // rcx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v25; // rax
  unsigned int v26; // eax
  __int64 v27; // rsi
  __int64 v28; // rbp
  __int64 v29; // rax
  signed __int64 v30; // rcx
  signed __int64 v31; // rax
  __int64 v32; // rcx
  UFG::qPropertySet *v33; // rdi
  UFG::qMemoryPool *v34; // rax
  UFG::SceneObjectProperties *v35; // rax
  UFG::allocator::free_link *v36; // rax
  UFG::Event *v37; // rdx
  unsigned int v38; // ecx
  UFG::allocator::free_link *v39; // rax
  char v41; // [rsp+30h] [rbp-58h]
  UFG::qList<UFG::SceneLayer,UFG::SceneLayer,1,0> *v42; // [rsp+38h] [rbp-50h]
  __int64 v43; // [rsp+40h] [rbp-48h]
  void *v44; // [rsp+48h] [rbp-40h]
  UFG::GeographicalLayerManager *v45; // [rsp+90h] [rbp+8h]
  unsigned __int8 v46; // [rsp+98h] [rbp+10h]
  bool v47; // [rsp+A0h] [rbp+18h]

  v47 = isActiveList;
  v45 = this;
  v43 = -2i64;
  v4 = testPos;
  v5 = isActiveList;
  v6 = this;
  v46 = 0;
  v7 = list->mNode.mPrev - 2;
  v42 = list - 2;
  if ( v7 != (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&list[-2] )
  {
    while ( 1 )
    {
      if ( ((LODWORD(v7[3].mPrev) >> 1) & 1) == v5 )
      {
        v19 = v7[4].mNext;
        if ( v19 )
          v20 = ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *, UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *, UFG::qVector3 *, bool))v19->mPrev[1].mPrev)(
                  v19,
                  v7,
                  v4,
                  v5);
        else
          LOBYTE(v20) = 0;
        if ( (_BYTE)v20 != v5 )
        {
          v21 = v7[2].mNext;
          UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)v7, v5 == 0, 0, 0);
          v7 = v21 - 2;
          v46 = 1;
        }
        if ( v5 )
        {
          if ( (_BYTE)v20 )
          {
            v22 = (UFG::SceneLayerResource *)&v7[4].mPrev[-6].mNext;
            if ( v22 != (UFG::SceneLayerResource *)&v7[-2] )
            {
              do
              {
                if ( !UFG::SceneLayer::sbManageSubLayerActivation
                  || (v22->mFlags >> 2) & 1
                  || UFG::SceneLayerResource::IsGeoInFrustrum(v22)
                  || UFG::SceneLayerResource::IsGeoClose(v22, v4, gLayer_OutFrustum_ActDistSqrd) )
                {
                  if ( !(v22->mFlags & 8) )
                  {
                    UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v41);
                    if ( !UFG::gIncrementalActivateManager_Active || (v22->mFlags >> 2) & 1 )
                    {
                      v26 = v22->mPropertySetCount;
                      if ( v26 )
                      {
                        v27 = 0i64;
                        v28 = v26;
                        do
                        {
                          v29 = v22->mPropertySets.mOffset;
                          if ( v29 )
                            v30 = (signed __int64)&v22->mPropertySets + v29;
                          else
                            v30 = 0i64;
                          v31 = v27 + v30;
                          v32 = *(_QWORD *)(v27 + v30);
                          if ( v32 )
                            v33 = (UFG::qPropertySet *)(v32 + v31);
                          else
                            v33 = 0i64;
                          v34 = UFG::GetSimulationMemoryPool();
                          v35 = (UFG::SceneObjectProperties *)UFG::qMemoryPool::Allocate(
                                                                v34,
                                                                0xA8ui64,
                                                                "SceneObjectProperties-Layer",
                                                                0i64,
                                                                1u);
                          v44 = v35;
                          if ( v35 )
                            UFG::SceneObjectProperties::SceneObjectProperties(v35, v33, v22);
                          if ( !v35->mpParent )
                            UFG::SceneObjectProperties::Activate(v35, 1u, 0i64, 0i64);
                          v27 += 8i64;
                          --v28;
                        }
                        while ( v28 );
                      }
                      v36 = UFG::qMalloc(0x38ui64, "layerActivatedEvent", 0i64);
                      v37 = (UFG::Event *)v36;
                      v44 = v36;
                      if ( v36 )
                      {
                        v38 = UFG::gSceneLayerActivatedChannel.mUID;
                        v39 = v36 + 1;
                        v39->mNext = v39;
                        v39[1].mNext = v39;
                        v37->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
                        v37->m_EventUID = v38;
                        v37->m_NamePTR = 0i64;
                      }
                      else
                      {
                        v37 = 0i64;
                      }
                      UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v37);
                    }
                    else
                    {
                      v23 = UFG::qMalloc(0x20ui64, "ActivatingLayer", 0i64);
                      v24 = (UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *)v23;
                      v44 = v23;
                      if ( v23 )
                      {
                        v23->mNext = v23;
                        v23[1].mNext = v23;
                        v23[2].mNext = (UFG::allocator::free_link *)v22;
                        LODWORD(v23[3].mNext) = 0;
                      }
                      else
                      {
                        v24 = 0i64;
                      }
                      v25 = UFG::smActivatingLayers.mNode.mPrev;
                      UFG::smActivatingLayers.mNode.mPrev->mNext = v24;
                      v24->mPrev = v25;
                      v24->mNext = (UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *)&UFG::smActivatingLayers;
                      UFG::smActivatingLayers.mNode.mPrev = v24;
                    }
                    UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v41);
                    v22->mFlags |= 8u;
                  }
                }
                else if ( v22->mFlags & 8
                       && !UFG::SceneLayerResource::IsGeoClose(v22, v4, gLayer_InFrustum_ActDistSqrd)
                       && v22->mFlags & 8 )
                {
                  UFG::IncrementalActivateManager::Deactivate(v22, 0);
                  v22->mFlags &= 0xFFFFFFF7;
                }
                v22 = (UFG::SceneLayerResource *)&v22->mNext[-6].mNext;
              }
              while ( v22 != (UFG::SceneLayerResource *)&v7[-2] );
              v5 = v47;
            }
          }
        }
        goto LABEL_56;
      }
      v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v7[1].mNext);
      UFG::qPrintf(
        "WARNING: Geographical layer '%s' was activated/deactivated outside of the geo manager's control\n",
        v8);
      v9 = v7;
      v7 = v7[2].mNext - 2;
      if ( (LODWORD(v9[3].mPrev) >> 15) & 1 )
      {
        v10 = v9 + 2;
        v11 = v9[2].mPrev;
        v12 = v9[2].mNext;
        v11->mNext = v12;
        v12->mPrev = v11;
        v10->mPrev = v10;
        v10->mNext = v10;
      }
      v13 = (unsigned int)v9[3].mPrev;
      if ( !((LODWORD(v9[3].mPrev) >> 15) & 1) )
        break;
LABEL_56:
      v7 = v7[2].mPrev - 2;
      v6 = v45;
      if ( v7 == (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)v42 )
        return v46;
    }
    if ( (v13 >> 7) & 1 )
    {
      v14 = ((v13 >> 1) & 1) == 0;
      v15 = v9 + 2;
      if ( !v14 )
      {
        v16 = v6->mActiveLayers.mNode.mPrev;
        v16->mNext = v15;
        v15->mPrev = v16;
        v9[2].mNext = &v6->mActiveLayers.mNode;
        v6->mActiveLayers.mNode.mPrev = v15;
LABEL_12:
        LODWORD(v9[3].mPrev) |= 0x8000u;
        goto LABEL_56;
      }
      v17 = &v6->mInactiveLayers;
    }
    else
    {
      v17 = &v6->mDisabledLayers;
      v15 = v9 + 2;
    }
    v18 = v17->mNode.mPrev;
    v18->mNext = v15;
    v15->mPrev = v18;
    v15->mNext = &v17->mNode;
    v17->mNode.mPrev = v15;
    goto LABEL_12;
  }
  return 0i64;
}

// File Line: 391
// RVA: 0x23ACD0
void __fastcall UFG::GeographicalLayerManager::DeactivateActiveGeoLayers(UFG::GeographicalLayerManager *this)
{
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v1; // rbp
  UFG::GeographicalLayerManager *v2; // rdi
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v3; // rbx
  char *v4; // rax
  signed __int64 v5; // rsi
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v6; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v7; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v8; // rdx
  unsigned int v9; // ecx
  bool v10; // zf
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v11; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v12; // rax
  UFG::qList<UFG::SceneLayer,UFG::SceneLayer,1,0> *v13; // rdx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v14; // rax

  v1 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)((char *)&this[-1].mInactiveLayers.mNode + 8);
  v2 = this;
  v3 = this->mActiveLayers.mNode.mPrev - 2;
  if ( v3 != (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&this[-1].mInactiveLayers.mNode.mNext )
  {
    while ( 1 )
    {
      if ( (LODWORD(v3[3].mPrev) >> 1) & 1 )
      {
        v5 = (signed __int64)&v3[2].mNext[-2];
        UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)v3, 0, 0, 0);
        goto LABEL_13;
      }
      v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3[1].mNext);
      UFG::qPrintf("WARNING: Geographical layer '%s' was alread deactivated outside of the geo manager's control\n", v4);
      v5 = (signed __int64)&v3[2].mNext[-2];
      if ( (LODWORD(v3[3].mPrev) >> 15) & 1 )
      {
        v6 = v3[2].mPrev;
        v7 = v3[2].mNext;
        v8 = v3 + 2;
        v6->mNext = v7;
        v7->mPrev = v6;
        v8->mPrev = v8;
        v8->mNext = v8;
      }
      v9 = (unsigned int)v3[3].mPrev;
      if ( (LODWORD(v3[3].mPrev) >> 15) & 1 )
        goto LABEL_13;
      if ( !((v9 >> 7) & 1) )
        break;
      v10 = ((v9 >> 1) & 1) == 0;
      v11 = v3 + 2;
      if ( v10 )
      {
        v13 = &v2->mInactiveLayers;
LABEL_11:
        v14 = v13->mNode.mPrev;
        v14->mNext = v11;
        v11->mPrev = v14;
        v11->mNext = &v13->mNode;
        v13->mNode.mPrev = v11;
        LODWORD(v3[3].mPrev) |= 0x8000u;
        goto LABEL_13;
      }
      v12 = v2->mActiveLayers.mNode.mPrev;
      v12->mNext = v11;
      v11->mPrev = v12;
      v3[2].mNext = &v2->mActiveLayers.mNode;
      v2->mActiveLayers.mNode.mPrev = v11;
      LODWORD(v3[3].mPrev) |= 0x8000u;
LABEL_13:
      v3 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)(*(_QWORD *)(v5 + 32) - 32i64);
      if ( v3 == v1 )
        return;
    }
    v13 = &v2->mDisabledLayers;
    v11 = v3 + 2;
    goto LABEL_11;
  }
}

// File Line: 424
// RVA: 0x246550
char __fastcall UFG::GeographicalLayerManager::Update(UFG::GeographicalLayerManager *this, float deltaTime, UFG::qVector3 *testPos)
{
  UFG::qVector3 *v3; // rsi
  UFG::GeographicalLayerManager *v4; // rdi
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v5; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> **v6; // rcx
  signed __int64 i; // rax
  char v8; // bl
  char v9; // al
  char v10; // bl

  v3 = testPos;
  v4 = this;
  if ( !this->mUpdateEnabled )
    return 0;
  if ( gImmediateAlways )
    this->mAllowImmediateActivation = 1;
  v5 = this->mActiveLayers.mNode.mNext;
  v6 = &this[-1].mInactiveLayers.mNode.mNext;
  for ( i = (signed __int64)&v5[-2];
        (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> **)i != v6;
        i = *(_QWORD *)(i + 40) - 32i64 )
  {
    *(float *)(i + 104) = *(float *)(i + 104) - deltaTime;
  }
  v8 = UFG::GeographicalLayerManager::TestForActivateOnList(v4, &v4->mActiveLayers, 1, testPos);
  v9 = UFG::GeographicalLayerManager::TestForActivateOnList(v4, &v4->mInactiveLayers, 0, v3);
  v4->mAllowImmediateActivation = 0;
  v10 = v9 | v8;
  UFG::IncrementalActivateManager::Service(deltaTime);
  return v10;
}

