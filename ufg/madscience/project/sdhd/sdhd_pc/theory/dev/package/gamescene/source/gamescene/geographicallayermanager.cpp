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
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gLayerTrapName__);
}

// File Line: 115
// RVA: 0x23D820
UFG::GeographicalLayerManager *__fastcall UFG::GeographicalLayerManager::GetInstance()
{
  if ( (_S1_28 & 1) == 0 )
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
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *mNext; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> **p_mNext; // rcx
  __int64 i; // rax

  mNext = this->mActiveLayers.mNode.mNext;
  p_mNext = &this[-1].mInactiveLayers.mNode.mNext;
  for ( i = (__int64)&mNext[-2];
        (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> **)i != p_mNext;
        i = *(_QWORD *)(i + 40) - 32i64 )
  {
    *(_DWORD *)(i + 104) = 0;
  }
}

// File Line: 180
// RVA: 0x245D40
void __fastcall UFG::GeographicalLayerManager::TrackLayer(
        UFG::GeographicalLayerManager *this,
        UFG::SceneLayer *pSceneLayer)
{
  unsigned int mFlags; // ecx
  bool v5; // zf
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v6; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *mPrev; // rax

  mFlags = pSceneLayer->mFlags;
  if ( (mFlags & 0x8000) == 0 )
  {
    if ( (mFlags & 0x80) != 0 )
    {
      v5 = (mFlags & 2) == 0;
      v6 = &pSceneLayer->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
      if ( v5 )
        this = (UFG::GeographicalLayerManager *)((char *)this + 16);
    }
    else
    {
      this = (UFG::GeographicalLayerManager *)((char *)this + 32);
      v6 = &pSceneLayer->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
    }
    mPrev = this->mActiveLayers.mNode.mPrev;
    mPrev->mNext = v6;
    v6->mPrev = mPrev;
    v6->mNext = &this->mActiveLayers.mNode;
    this->mActiveLayers.mNode.mPrev = v6;
    pSceneLayer->mFlags |= 0x8000u;
  }
}

// File Line: 266
// RVA: 0x245960
__int64 __fastcall UFG::GeographicalLayerManager::TestForActivateOnList(
        UFG::GeographicalLayerManager *this,
        UFG::qList<UFG::SceneLayer,UFG::SceneLayer,1,0> *list,
        unsigned __int8 isActiveList,
        UFG::qVector3 *testPos)
{
  unsigned __int8 v5; // r13
  UFG::GeographicalLayerManager *v6; // rbx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v7; // r14
  char *v8; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v9; // r8
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v10; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v11; // rax
  int v12; // ecx
  bool v13; // zf
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v14; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v15; // rax
  UFG::qList<UFG::SceneLayer,UFG::SceneLayer,1,0> *p_mInactiveLayers; // rdx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v17; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *mNext; // rcx
  char v19; // di
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v20; // rbx
  UFG::SceneLayerResource *p_mNext; // rbx
  UFG::allocator::free_link *v22; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v23; // rcx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *mPrev; // rax
  unsigned int mPropertySetCount; // eax
  __int64 v26; // rsi
  __int64 v27; // rbp
  __int64 mOffset; // rax
  char *v29; // rcx
  char *v30; // rax
  __int64 v31; // rcx
  UFG::qPropertySet *v32; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::SceneObjectProperties *v34; // rax
  UFG::allocator::free_link *v35; // rax
  UFG::Event *v36; // rdx
  unsigned int mUID; // ecx
  UFG::allocator::free_link *v38; // rax
  UFG::PropertyModificationCallbackSupress v40; // [rsp+30h] [rbp-58h] BYREF
  UFG::qList<UFG::SceneLayer,UFG::SceneLayer,1,0> *v41; // [rsp+38h] [rbp-50h]
  __int64 v42; // [rsp+40h] [rbp-48h]
  void *v43; // [rsp+48h] [rbp-40h]
  unsigned __int8 v45; // [rsp+98h] [rbp+10h]

  v42 = -2i64;
  v5 = isActiveList;
  v6 = this;
  v45 = 0;
  v7 = list->mNode.mPrev - 2;
  v41 = list - 2;
  if ( v7 != (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&list[-2] )
  {
    while ( 1 )
    {
      if ( (((__int64)v7[3].mPrev & 2) != 0) == v5 )
      {
        mNext = v7[4].mNext;
        if ( mNext )
          v19 = ((__int64 (__fastcall *)(UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *, UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *, UFG::qVector3 *, _QWORD))mNext->mPrev[1].mPrev)(
                  mNext,
                  v7,
                  testPos,
                  v5);
        else
          v19 = 0;
        if ( v19 != v5 )
        {
          v20 = v7[2].mNext;
          UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)v7, v5 == 0, NON_PERSISTENT, 0);
          v7 = v20 - 2;
          v45 = 1;
        }
        if ( v5 )
        {
          if ( v19 )
          {
            p_mNext = (UFG::SceneLayerResource *)&v7[4].mPrev[-6].mNext;
            if ( p_mNext != (UFG::SceneLayerResource *)&v7[-2] )
            {
              do
              {
                if ( !UFG::SceneLayer::sbManageSubLayerActivation
                  || (p_mNext->mFlags & 4) != 0
                  || UFG::SceneLayerResource::IsGeoInFrustrum(p_mNext)
                  || UFG::SceneLayerResource::IsGeoClose(p_mNext, testPos, gLayer_OutFrustum_ActDistSqrd) )
                {
                  if ( (p_mNext->mFlags & 8) == 0 )
                  {
                    UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(&v40);
                    if ( !UFG::gIncrementalActivateManager_Active || (p_mNext->mFlags & 4) != 0 )
                    {
                      mPropertySetCount = p_mNext->mPropertySetCount;
                      if ( mPropertySetCount )
                      {
                        v26 = 0i64;
                        v27 = mPropertySetCount;
                        do
                        {
                          mOffset = p_mNext->mPropertySets.mOffset;
                          if ( mOffset )
                            v29 = (char *)&p_mNext->mPropertySets + mOffset;
                          else
                            v29 = 0i64;
                          v30 = &v29[v26];
                          v31 = *(_QWORD *)&v29[v26];
                          if ( v31 )
                            v32 = (UFG::qPropertySet *)&v30[v31];
                          else
                            v32 = 0i64;
                          SimulationMemoryPool = UFG::GetSimulationMemoryPool();
                          v34 = (UFG::SceneObjectProperties *)UFG::qMemoryPool::Allocate(
                                                                SimulationMemoryPool,
                                                                0xA8ui64,
                                                                "SceneObjectProperties-Layer",
                                                                0i64,
                                                                1u);
                          v43 = v34;
                          if ( v34 )
                            UFG::SceneObjectProperties::SceneObjectProperties(v34, v32, p_mNext);
                          if ( !v34->mpParent )
                            UFG::SceneObjectProperties::Activate(v34, 1u, 0i64, 0i64);
                          v26 += 8i64;
                          --v27;
                        }
                        while ( v27 );
                      }
                      v35 = UFG::qMalloc(0x38ui64, "layerActivatedEvent", 0i64);
                      v36 = (UFG::Event *)v35;
                      v43 = v35;
                      if ( v35 )
                      {
                        mUID = UFG::gSceneLayerActivatedChannel.mUID;
                        v38 = v35 + 1;
                        v38->mNext = v38;
                        v38[1].mNext = v38;
                        v36->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
                        v36->m_EventUID = mUID;
                        v36->m_NamePTR = 0i64;
                      }
                      else
                      {
                        v36 = 0i64;
                      }
                      UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v36);
                    }
                    else
                    {
                      v22 = UFG::qMalloc(0x20ui64, "ActivatingLayer", 0i64);
                      v23 = (UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *)v22;
                      v43 = v22;
                      if ( v22 )
                      {
                        v22->mNext = v22;
                        v22[1].mNext = v22;
                        v22[2].mNext = (UFG::allocator::free_link *)p_mNext;
                        LODWORD(v22[3].mNext) = 0;
                      }
                      else
                      {
                        v23 = 0i64;
                      }
                      mPrev = UFG::smActivatingLayers.mNode.mPrev;
                      UFG::smActivatingLayers.mNode.mPrev->mNext = v23;
                      v23->mPrev = mPrev;
                      v23->mNext = (UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *)&UFG::smActivatingLayers;
                      UFG::smActivatingLayers.mNode.mPrev = v23;
                    }
                    UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(&v40);
                    p_mNext->mFlags |= 8u;
                  }
                }
                else if ( (p_mNext->mFlags & 8) != 0
                       && !UFG::SceneLayerResource::IsGeoClose(p_mNext, testPos, gLayer_InFrustum_ActDistSqrd)
                       && (p_mNext->mFlags & 8) != 0 )
                {
                  UFG::IncrementalActivateManager::Deactivate(p_mNext, 0);
                  p_mNext->mFlags &= ~8u;
                }
                p_mNext = (UFG::SceneLayerResource *)&p_mNext->mNext[-6].mNext;
              }
              while ( p_mNext != (UFG::SceneLayerResource *)&v7[-2] );
              v5 = isActiveList;
            }
          }
        }
        goto LABEL_56;
      }
      v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v7[1].mNext);
      UFG::qPrintf(
        "WARNING: Geographical layer %s was activated/deactivated outside of the geo managers control\n",
        v8);
      v9 = v7;
      v7 = v7[2].mNext - 2;
      if ( ((__int64)v9[3].mPrev & 0x8000) != 0 )
      {
        v10 = v9[2].mPrev;
        v11 = v9[2].mNext;
        v10->mNext = v11;
        v11->mPrev = v10;
        v9[2].mPrev = v9 + 2;
        v9[2].mNext = v9 + 2;
      }
      v12 = (int)v9[3].mPrev;
      if ( (v12 & 0x8000) == 0 )
        break;
LABEL_56:
      v7 = v7[2].mPrev - 2;
      v6 = this;
      if ( v7 == (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)v41 )
        return v45;
    }
    if ( (v12 & 0x80) != 0 )
    {
      v13 = (v12 & 2) == 0;
      v14 = v9 + 2;
      if ( !v13 )
      {
        v15 = v6->mActiveLayers.mNode.mPrev;
        v15->mNext = v14;
        v14->mPrev = v15;
        v9[2].mNext = &v6->mActiveLayers.mNode;
        v6->mActiveLayers.mNode.mPrev = v14;
LABEL_12:
        LODWORD(v9[3].mPrev) |= 0x8000u;
        goto LABEL_56;
      }
      p_mInactiveLayers = &v6->mInactiveLayers;
    }
    else
    {
      p_mInactiveLayers = &v6->mDisabledLayers;
      v14 = v9 + 2;
    }
    v17 = p_mInactiveLayers->mNode.mPrev;
    v17->mNext = v14;
    v14->mPrev = v17;
    v14->mNext = &p_mInactiveLayers->mNode;
    p_mInactiveLayers->mNode.mPrev = v14;
    goto LABEL_12;
  }
  return 0i64;
}

// File Line: 391
// RVA: 0x23ACD0
void __fastcall UFG::GeographicalLayerManager::DeactivateActiveGeoLayers(UFG::GeographicalLayerManager *this)
{
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *p_mNext; // rbp
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v3; // rbx
  char *v4; // rax
  __int64 v5; // rsi
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *mPrev; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *mNext; // rax
  int v8; // ecx
  bool v9; // zf
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v10; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v11; // rax
  UFG::qList<UFG::SceneLayer,UFG::SceneLayer,1,0> *p_mInactiveLayers; // rdx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v13; // rax

  p_mNext = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&this[-1].mInactiveLayers.mNode.mNext;
  v3 = this->mActiveLayers.mNode.mPrev - 2;
  if ( v3 != (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&this[-1].mInactiveLayers.mNode.mNext )
  {
    while ( 1 )
    {
      if ( ((__int64)v3[3].mPrev & 2) != 0 )
      {
        v5 = (__int64)&v3[2].mNext[-2];
        UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)v3, 0, NON_PERSISTENT, 0);
        goto LABEL_13;
      }
      v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3[1].mNext);
      UFG::qPrintf("WARNING: Geographical layer %s was alread deactivated outside of the geo managers control\n", v4);
      v5 = (__int64)&v3[2].mNext[-2];
      if ( ((__int64)v3[3].mPrev & 0x8000) != 0 )
      {
        mPrev = v3[2].mPrev;
        mNext = v3[2].mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v3[2].mPrev = v3 + 2;
        v3[2].mNext = v3 + 2;
      }
      v8 = (int)v3[3].mPrev;
      if ( (v8 & 0x8000) != 0 )
        goto LABEL_13;
      if ( (v8 & 0x80) == 0 )
        break;
      v9 = (v8 & 2) == 0;
      v10 = v3 + 2;
      if ( v9 )
      {
        p_mInactiveLayers = &this->mInactiveLayers;
LABEL_11:
        v13 = p_mInactiveLayers->mNode.mPrev;
        v13->mNext = v10;
        v10->mPrev = v13;
        v10->mNext = &p_mInactiveLayers->mNode;
        p_mInactiveLayers->mNode.mPrev = v10;
        LODWORD(v3[3].mPrev) |= 0x8000u;
        goto LABEL_13;
      }
      v11 = this->mActiveLayers.mNode.mPrev;
      v11->mNext = v10;
      v10->mPrev = v11;
      v3[2].mNext = &this->mActiveLayers.mNode;
      this->mActiveLayers.mNode.mPrev = v10;
      LODWORD(v3[3].mPrev) |= 0x8000u;
LABEL_13:
      v3 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)(*(_QWORD *)(v5 + 32) - 32i64);
      if ( v3 == p_mNext )
        return;
    }
    p_mInactiveLayers = &this->mDisabledLayers;
    v10 = v3 + 2;
    goto LABEL_11;
  }
}

// File Line: 424
// RVA: 0x246550
char __fastcall UFG::GeographicalLayerManager::Update(
        UFG::GeographicalLayerManager *this,
        float deltaTime,
        UFG::qVector3 *testPos)
{
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *mNext; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> **p_mNext; // rcx
  __int64 i; // rax
  char v8; // bl
  char v9; // al
  char v10; // bl

  if ( !this->mUpdateEnabled )
    return 0;
  if ( gImmediateAlways )
    this->mAllowImmediateActivation = 1;
  mNext = this->mActiveLayers.mNode.mNext;
  p_mNext = &this[-1].mInactiveLayers.mNode.mNext;
  for ( i = (__int64)&mNext[-2];
        (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> **)i != p_mNext;
        i = *(_QWORD *)(i + 40) - 32i64 )
  {
    *(float *)(i + 104) = *(float *)(i + 104) - deltaTime;
  }
  v8 = UFG::GeographicalLayerManager::TestForActivateOnList(this, &this->mActiveLayers, 1u, testPos);
  v9 = UFG::GeographicalLayerManager::TestForActivateOnList(this, &this->mInactiveLayers, 0, testPos);
  this->mAllowImmediateActivation = 0;
  v10 = v9 | v8;
  UFG::IncrementalActivateManager::Service(deltaTime);
  return v10;
}

