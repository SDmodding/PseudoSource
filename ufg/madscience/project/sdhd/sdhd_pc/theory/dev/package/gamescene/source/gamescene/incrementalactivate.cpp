// File Line: 43
// RVA: 0x14753E0
__int64 UFG::_dynamic_initializer_for__gSceneLayerActivatedChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gSceneLayerActivatedChannel, "EVT_SCENE_LAYER_ACTIVATED", 0i64);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSceneLayerActivatedChannel__);
}

// File Line: 44
// RVA: 0x1475410
__int64 UFG::_dynamic_initializer_for__gSceneLayerDeactivatedChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gSceneLayerDeactivatedChannel, "EVT_SCENE_LAYER_DEACTIVATED", 0i64);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSceneLayerDeactivatedChannel__);
}

// File Line: 63
// RVA: 0x14755C0
__int64 UFG::_dynamic_initializer_for__smActivatingLayers__()
{
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__smActivatingLayers__);
}

// File Line: 71
// RVA: 0x2452B0
void __fastcall UFG::IncrementalActivateManager::Service(float fDelta)
{
  __int64 v1; // r15
  int v2; // ebp
  unsigned __int64 v3; // r15
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *mNext; // rbx
  UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *v5; // r14
  UFG::SceneLayerResource *mPrev; // rsi
  __int64 mOffset; // rax
  char *v8; // rcx
  char *v9; // rdx
  UFG::qPropertySet *v10; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::SceneObjectProperties *v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::Event *v15; // rdx
  unsigned int mUID; // ecx
  UFG::allocator::free_link *v17; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v18; // rdx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v19; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v20; // rdx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v21; // rax
  UFG::PropertyModificationCallbackSupress v22; // [rsp+88h] [rbp+10h] BYREF
  void *v23; // [rsp+90h] [rbp+18h]

  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(&v22);
  once_0 = 0;
  v1 = (unsigned int)UFG::qConvertMillisecsToTicks(UFG::gIncrementalActivateManager_MaxLayerActivateTimeMs);
  v2 = 0;
  v3 = UFG::qGetTicks() + v1;
  mNext = UFG::smActivatingLayers.mNode.mNext;
  if ( (UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *)UFG::smActivatingLayers.mNode.mNext != &UFG::smActivatingLayers )
  {
    do
    {
      v5 = (UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *)mNext->mNext;
      mPrev = (UFG::SceneLayerResource *)mNext[1].mPrev;
      if ( v2 && UFG::qGetTicks() > v3 )
        break;
      ++v2;
      for ( ; LODWORD(mNext[1].mNext) < mPrev->mPropertySetCount; ++LODWORD(mNext[1].mNext) )
      {
        mOffset = mPrev->mPropertySets.mOffset;
        if ( mOffset )
          v8 = (char *)&mPrev->mPropertySets + mOffset;
        else
          v8 = 0i64;
        v9 = &v8[8 * LODWORD(mNext[1].mNext)];
        v10 = (UFG::qPropertySet *)&v9[*(_QWORD *)v9];
        if ( !*(_QWORD *)v9 )
          v10 = 0i64;
        SimulationMemoryPool = UFG::GetSimulationMemoryPool();
        v12 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xA8ui64, "SceneObjectProperties-Layer", 0i64, 1u);
        v23 = v12;
        if ( v12 )
          UFG::SceneObjectProperties::SceneObjectProperties((UFG::SceneObjectProperties *)v12, v10, mPrev);
        else
          v13 = 0i64;
        if ( !v13->mpParent )
          UFG::SceneObjectProperties::Activate(v13, 1u, 0i64, 0i64);
      }
      v14 = UFG::qMalloc(0x38ui64, "layerActivatedEvent", 0i64);
      v15 = (UFG::Event *)v14;
      v23 = v14;
      if ( v14 )
      {
        mUID = UFG::gSceneLayerActivatedChannel.mUID;
        v17 = v14 + 1;
        v17->mNext = v17;
        v17[1].mNext = v17;
        v15->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
        v15->m_EventUID = mUID;
        v15->m_NamePTR = 0i64;
      }
      else
      {
        v15 = 0i64;
      }
      UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v15);
      v18 = mNext->mPrev;
      v19 = mNext->mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      v23 = mNext;
      v20 = mNext->mPrev;
      v21 = mNext->mNext;
      v20->mNext = v21;
      v21->mPrev = v20;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      operator delete[](mNext);
      mNext = &v5->mNode;
    }
    while ( v5 != &UFG::smActivatingLayers );
  }
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(&v22);
}

// File Line: 131
// RVA: 0x23BD30
char __fastcall UFG::IncrementalActivateManager::Flush()
{
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *mNext; // rbx
  UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *v1; // rbp
  UFG::SceneLayerResource *i; // rsi
  __int64 mOffset; // rax
  char *v4; // rcx
  char *v5; // rdx
  UFG::qPropertySet *v6; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::SceneObjectProperties *v8; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *mPrev; // rcx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v10; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v11; // rcx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::Event *v14; // rdx
  unsigned int mUID; // ecx
  UFG::allocator::free_link *v16; // rax
  UFG::PropertyModificationCallbackSupress v18; // [rsp+60h] [rbp+8h] BYREF
  void *v19; // [rsp+68h] [rbp+10h]

  if ( (UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *)UFG::smActivatingLayers.mNode.mNext == &UFG::smActivatingLayers )
    return 0;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(&v18);
  mNext = UFG::smActivatingLayers.mNode.mNext;
  if ( (UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *)UFG::smActivatingLayers.mNode.mNext != &UFG::smActivatingLayers )
  {
    do
    {
      v1 = (UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *)mNext->mNext;
      for ( i = (UFG::SceneLayerResource *)mNext[1].mPrev;
            LODWORD(mNext[1].mNext) < i->mPropertySetCount;
            ++LODWORD(mNext[1].mNext) )
      {
        mOffset = i->mPropertySets.mOffset;
        if ( mOffset )
          v4 = (char *)&i->mPropertySets + mOffset;
        else
          v4 = 0i64;
        v5 = &v4[8 * LODWORD(mNext[1].mNext)];
        if ( *(_QWORD *)v5 )
          v6 = (UFG::qPropertySet *)&v5[*(_QWORD *)v5];
        else
          v6 = 0i64;
        SimulationMemoryPool = UFG::GetSimulationMemoryPool();
        v8 = (UFG::SceneObjectProperties *)UFG::qMemoryPool::Allocate(
                                             SimulationMemoryPool,
                                             0xA8ui64,
                                             "SceneObjectProperties-Layer",
                                             0i64,
                                             1u);
        v19 = v8;
        if ( v8 )
          UFG::SceneObjectProperties::SceneObjectProperties(v8, v6, i);
        if ( !v8->mpParent )
          UFG::SceneObjectProperties::Activate(v8, 1u, 0i64, 0i64);
      }
      mPrev = mNext->mPrev;
      v10 = mNext->mNext;
      mPrev->mNext = v10;
      v10->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      v19 = mNext;
      v11 = mNext->mPrev;
      v12 = mNext->mNext;
      v11->mNext = v12;
      v12->mPrev = v11;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      operator delete[](mNext);
      mNext = &v1->mNode;
    }
    while ( v1 != &UFG::smActivatingLayers );
  }
  v13 = UFG::qMalloc(0x38ui64, "layerActivatedEvent", 0i64);
  v14 = (UFG::Event *)v13;
  v19 = v13;
  if ( v13 )
  {
    mUID = UFG::gSceneLayerActivatedChannel.mUID;
    v16 = v13 + 1;
    v16->mNext = v16;
    v16[1].mNext = v16;
    v14->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
    v14->m_EventUID = mUID;
    v14->m_NamePTR = 0i64;
  }
  else
  {
    v14 = 0i64;
  }
  UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v14);
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(&v18);
  return 1;
}

// File Line: 171
// RVA: 0x2398F0
void __fastcall UFG::IncrementalActivateManager::Activate(
        UFG::SceneLayerResource *pSceneLayerResource,
        bool forceSynchronous)
{
  UFG::allocator::free_link *v4; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v5; // rcx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *mPrev; // rax
  unsigned int mPropertySetCount; // eax
  __int64 v8; // rdi
  __int64 v9; // rsi
  __int64 mOffset; // rax
  char *v11; // rcx
  char *v12; // rax
  __int64 v13; // rcx
  UFG::qPropertySet *v14; // rbx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::SceneObjectProperties *v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::Event *v18; // rdx
  unsigned int mUID; // ecx
  UFG::allocator::free_link *v20; // rax
  UFG::PropertyModificationCallbackSupress v21; // [rsp+70h] [rbp+18h] BYREF
  void *v22; // [rsp+78h] [rbp+20h]

  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(&v21);
  if ( !UFG::gIncrementalActivateManager_Active || forceSynchronous || (pSceneLayerResource->mFlags & 4) != 0 )
  {
    mPropertySetCount = pSceneLayerResource->mPropertySetCount;
    if ( mPropertySetCount )
    {
      v8 = 0i64;
      v9 = mPropertySetCount;
      do
      {
        mOffset = pSceneLayerResource->mPropertySets.mOffset;
        if ( mOffset )
          v11 = (char *)&pSceneLayerResource->mPropertySets + mOffset;
        else
          v11 = 0i64;
        v12 = &v11[v8];
        v13 = *(_QWORD *)&v11[v8];
        if ( v13 )
          v14 = (UFG::qPropertySet *)&v12[v13];
        else
          v14 = 0i64;
        SimulationMemoryPool = UFG::GetSimulationMemoryPool();
        v16 = (UFG::SceneObjectProperties *)UFG::qMemoryPool::Allocate(
                                              SimulationMemoryPool,
                                              0xA8ui64,
                                              "SceneObjectProperties-Layer",
                                              0i64,
                                              1u);
        v22 = v16;
        if ( v16 )
          UFG::SceneObjectProperties::SceneObjectProperties(v16, v14, pSceneLayerResource);
        if ( !v16->mpParent )
          UFG::SceneObjectProperties::Activate(v16, 1u, 0i64, 0i64);
        v8 += 8i64;
        --v9;
      }
      while ( v9 );
    }
    v17 = UFG::qMalloc(0x38ui64, "layerActivatedEvent", 0i64);
    v18 = (UFG::Event *)v17;
    v22 = v17;
    if ( v17 )
    {
      mUID = UFG::gSceneLayerActivatedChannel.mUID;
      v20 = v17 + 1;
      v20->mNext = v20;
      v20[1].mNext = v20;
      v18->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
      v18->m_EventUID = mUID;
      v18->m_NamePTR = 0i64;
    }
    else
    {
      v18 = 0i64;
    }
    UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v18);
  }
  else
  {
    v4 = UFG::qMalloc(0x20ui64, "ActivatingLayer", 0i64);
    v5 = (UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *)v4;
    v22 = v4;
    if ( v4 )
    {
      v4->mNext = v4;
      v4[1].mNext = v4;
      v4[2].mNext = (UFG::allocator::free_link *)pSceneLayerResource;
      LODWORD(v4[3].mNext) = 0;
    }
    else
    {
      v5 = 0i64;
    }
    mPrev = UFG::smActivatingLayers.mNode.mPrev;
    UFG::smActivatingLayers.mNode.mPrev->mNext = v5;
    v5->mPrev = mPrev;
    v5->mNext = (UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *)&UFG::smActivatingLayers;
    UFG::smActivatingLayers.mNode.mPrev = v5;
  }
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(&v21);
}

// File Line: 200
// RVA: 0x23A810
void __fastcall UFG::IncrementalActivateManager::Deactivate(
        UFG::SceneLayerResource *pSceneLayerResource,
        bool forceSynchronous)
{
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *mNext; // rcx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *mPrev; // rdx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v6; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v7; // rdx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v8; // rax
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *i; // rax
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v10; // rbx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v11; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v12; // rax
  UFG::SimObject *v13; // rbp
  char v14; // di
  UFG::qPropertySet *v15; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *v17; // rcx
  UFG::qPropertySet *v18; // rax
  unsigned int *v19; // rax
  UFG::qPropertySet *v20; // rcx
  UFG::SchemaDef *v21; // rax
  UFG::qPropertySet *v22; // rcx
  UFG::qPropertySet *v23; // rax
  UFG::qPropertySet *v24; // rcx
  UFG::SchemaDef *v25; // rax
  UFG::qPropertySet *v26; // rcx
  UFG::qPropertySet *v27; // rax
  unsigned int *v28; // rax
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v29; // rcx
  UFG::TransformNodeComponent *v30; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v31; // rax
  __int64 mNext_low; // rax
  UFG::SceneObjectProperties **v33; // rdi
  UFG::SceneObjectProperties **j; // rsi
  UFG::allocator::free_link *v35; // rax
  UFG::Event *v36; // rdx
  unsigned int mUID; // ecx
  UFG::allocator::free_link *v38; // rax

  mNext = UFG::smActivatingLayers.mNode.mNext;
  if ( (UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *)UFG::smActivatingLayers.mNode.mNext != &UFG::smActivatingLayers )
  {
    while ( (UFG::SceneLayerResource *)mNext[1].mPrev != pSceneLayerResource )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *)&UFG::smActivatingLayers )
        goto LABEL_6;
    }
    mPrev = mNext->mPrev;
    v6 = mNext->mNext;
    mPrev->mNext = v6;
    v6->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    v7 = mNext->mPrev;
    v8 = mNext->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    operator delete[](mNext);
  }
LABEL_6:
  for ( i = pSceneLayerResource->mObjects.mNode.mNext - 4;
        i != (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&pSceneLayerResource->mDebugName[28];
        i = pSceneLayerResource->mObjects.mNode.mNext - 4 )
  {
    v10 = i + 4;
    v11 = i[4].mPrev;
    v12 = i[4].mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = v10;
    v10->mNext = v10;
    if ( forceSynchronous )
    {
      UFG::SceneObjectProperties::Deactivate((UFG::SceneObjectProperties *)&v10[-4], 4u);
      continue;
    }
    v13 = (UFG::SimObject *)v10[-2].mNext;
    if ( !v13 )
      continue;
    v14 = 0;
    if ( (v13->m_Flags & 0x8000u) != 0 )
    {
      v14 = 1;
      goto LABEL_33;
    }
    v15 = (UFG::qPropertySet *)v10[5].mPrev;
    if ( !v15 )
      v15 = (UFG::qPropertySet *)v10[5].mNext;
    SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(
                          v15,
                          (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags);
    if ( SchemaForProperty )
    {
      v17 = (UFG::qPropertySet *)v10[5].mPrev;
      if ( !v17 )
        v17 = (UFG::qPropertySet *)v10[5].mNext;
      v18 = UFG::qPropertySet::Get<UFG::qPropertySet>(
              v17,
              (UFG::qArray<unsigned long,0> *)&SchemaForProperty->mPropertyName,
              DEPTH_RECURSE);
    }
    else
    {
      v18 = (UFG::qPropertySet *)v10[5].mPrev;
      if ( v18 )
        goto LABEL_21;
      v18 = (UFG::qPropertySet *)v10[5].mNext;
    }
    if ( !v18 )
      goto LABEL_52;
LABEL_21:
    v19 = UFG::qPropertySet::Get<unsigned long>(
            v18,
            (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags,
            DEPTH_RECURSE);
    if ( !v19 || (*v19 & 4) == 0 )
    {
LABEL_52:
      mNext_low = LODWORD(v10[3].mNext);
      if ( (_DWORD)mNext_low )
      {
        v33 = (UFG::SceneObjectProperties **)v10[4].mPrev;
        for ( j = &v33[mNext_low]; v33 < j; ++v33 )
          UFG::SceneObjectProperties::Deactivate(*v33);
      }
      UFG::SceneObjectProperties::mspDeactivateFunc((UFG::SceneObjectProperties *)&v10[-4]);
      UFG::SimObject::Destroy(v13);
      continue;
    }
    v20 = (UFG::qPropertySet *)v10[5].mPrev;
    if ( !v20 )
      v20 = (UFG::qPropertySet *)v10[5].mNext;
    v21 = UFG::PropertySetManager::GetSchemaForProperty(v20, (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags);
    if ( v21 )
    {
      v22 = (UFG::qPropertySet *)v10[5].mPrev;
      if ( !v22 )
        v22 = (UFG::qPropertySet *)v10[5].mNext;
      v23 = UFG::qPropertySet::Get<UFG::qPropertySet>(
              v22,
              (UFG::qArray<unsigned long,0> *)&v21->mPropertyName,
              DEPTH_RECURSE);
LABEL_31:
      if ( !v23 )
        goto LABEL_33;
      goto LABEL_32;
    }
    v23 = (UFG::qPropertySet *)v10[5].mPrev;
    if ( !v23 )
    {
      v23 = (UFG::qPropertySet *)v10[5].mNext;
      goto LABEL_31;
    }
LABEL_32:
    UFG::qPropertySet::Get<unsigned long>(v23, (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags, DEPTH_RECURSE);
LABEL_33:
    v24 = (UFG::qPropertySet *)v10[5].mPrev;
    if ( !v24 )
      v24 = (UFG::qPropertySet *)v10[5].mNext;
    v25 = UFG::PropertySetManager::GetSchemaForProperty(v24, (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags);
    if ( v25 )
    {
      v26 = (UFG::qPropertySet *)v10[5].mPrev;
      if ( !v26 )
        v26 = (UFG::qPropertySet *)v10[5].mNext;
      v27 = UFG::qPropertySet::Get<UFG::qPropertySet>(
              v26,
              (UFG::qArray<unsigned long,0> *)&v25->mPropertyName,
              DEPTH_RECURSE);
    }
    else
    {
      v27 = (UFG::qPropertySet *)v10[5].mPrev;
      if ( v27 )
        goto LABEL_42;
      v27 = (UFG::qPropertySet *)v10[5].mNext;
    }
    if ( v27 )
    {
LABEL_42:
      v28 = UFG::qPropertySet::Get<unsigned long>(
              v27,
              (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags,
              DEPTH_RECURSE);
      if ( v28 && (*v28 & 4) != 0 )
      {
LABEL_45:
        LOWORD(v10[-2].mPrev) |= 8u;
        if ( v10[3].mPrev )
        {
          v29 = v10[-2].mNext;
          if ( v29 )
          {
            v30 = (UFG::TransformNodeComponent *)v29[5].mNext;
            if ( v30 )
            {
              if ( v30->mParent )
                UFG::TransformNodeComponent::SetParentKeepWorld(v30, 0i64, eInheritXform_Full);
            }
          }
        }
        v10[2].mNext = 0i64;
        v31 = v10[3].mPrev;
        if ( v31 )
          LOBYTE(v31[8].mNext) = 0;
        continue;
      }
    }
    if ( v14 )
      goto LABEL_45;
  }
  v35 = UFG::qMalloc(0x38ui64, "layerDeactivatedEvent", 0i64);
  v36 = (UFG::Event *)v35;
  if ( v35 )
  {
    mUID = UFG::gSceneLayerDeactivatedChannel.mUID;
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

