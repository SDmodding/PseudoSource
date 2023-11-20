// File Line: 43
// RVA: 0x14753E0
__int64 UFG::_dynamic_initializer_for__gSceneLayerActivatedChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gSceneLayerActivatedChannel, "EVT_SCENE_LAYER_ACTIVATED", 0i64);
  return atexit(UFG::_dynamic_atexit_destructor_for__gSceneLayerActivatedChannel__);
}

// File Line: 44
// RVA: 0x1475410
__int64 UFG::_dynamic_initializer_for__gSceneLayerDeactivatedChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gSceneLayerDeactivatedChannel, "EVT_SCENE_LAYER_DEACTIVATED", 0i64);
  return atexit(UFG::_dynamic_atexit_destructor_for__gSceneLayerDeactivatedChannel__);
}

// File Line: 63
// RVA: 0x14755C0
__int64 UFG::_dynamic_initializer_for__smActivatingLayers__()
{
  return atexit(UFG::_dynamic_atexit_destructor_for__smActivatingLayers__);
}

// File Line: 71
// RVA: 0x2452B0
void __fastcall UFG::IncrementalActivateManager::Service(float fDelta)
{
  __int64 v1; // r15
  int v2; // ebp
  unsigned __int64 v3; // r15
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v4; // rbx
  UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *v5; // r14
  UFG::SceneLayerResource *v6; // rsi
  __int64 v7; // rax
  signed __int64 v8; // rcx
  _QWORD *v9; // rdx
  UFG::qPropertySet *v10; // rdi
  UFG::qMemoryPool *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::SceneObjectProperties *v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::Event *v15; // rdx
  unsigned int v16; // ecx
  UFG::allocator::free_link *v17; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v18; // rdx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v19; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v20; // rdx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v21; // rax
  char v22; // [rsp+88h] [rbp+10h]
  void *v23; // [rsp+90h] [rbp+18h]

  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v22);
  once_0 = 0;
  v1 = (unsigned int)UFG::qConvertMillisecsToTicks(UFG::gIncrementalActivateManager_MaxLayerActivateTimeMs);
  v2 = 0;
  v3 = UFG::qGetTicks() + v1;
  v4 = UFG::smActivatingLayers.mNode.mNext;
  if ( (UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *)UFG::smActivatingLayers.mNode.mNext != &UFG::smActivatingLayers )
  {
    do
    {
      v5 = (UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *)v4->mNext;
      v6 = (UFG::SceneLayerResource *)v4[1].mPrev;
      if ( v2 && UFG::qGetTicks() > v3 )
        break;
      ++v2;
      for ( ; LODWORD(v4[1].mNext) < v6->mPropertySetCount; ++LODWORD(v4[1].mNext) )
      {
        v7 = v6->mPropertySets.mOffset;
        if ( v7 )
          v8 = (signed __int64)&v6->mPropertySets + v7;
        else
          v8 = 0i64;
        v9 = (_QWORD *)(v8 + 8i64 * LODWORD(v4[1].mNext));
        v10 = (UFG::qPropertySet *)((char *)v9 + *v9);
        if ( !*v9 )
          v10 = 0i64;
        v11 = UFG::GetSimulationMemoryPool();
        v12 = UFG::qMemoryPool::Allocate(v11, 0xA8ui64, "SceneObjectProperties-Layer", 0i64, 1u);
        v23 = v12;
        if ( v12 )
          UFG::SceneObjectProperties::SceneObjectProperties((UFG::SceneObjectProperties *)v12, v10, v6);
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
        v16 = UFG::gSceneLayerActivatedChannel.mUID;
        v17 = v14 + 1;
        v17->mNext = v17;
        v17[1].mNext = v17;
        v15->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
        v15->m_EventUID = v16;
        v15->m_NamePTR = 0i64;
      }
      else
      {
        v15 = 0i64;
      }
      UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v15);
      v18 = v4->mPrev;
      v19 = v4->mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      v4->mPrev = v4;
      v4->mNext = v4;
      v23 = v4;
      v20 = v4->mPrev;
      v21 = v4->mNext;
      v20->mNext = v21;
      v21->mPrev = v20;
      v4->mPrev = v4;
      v4->mNext = v4;
      operator delete[](v4);
      v4 = &v5->mNode;
    }
    while ( v5 != &UFG::smActivatingLayers );
  }
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v22);
}

// File Line: 131
// RVA: 0x23BD30
char __fastcall UFG::IncrementalActivateManager::Flush()
{
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v0; // rbx
  UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *v1; // rbp
  UFG::SceneLayerResource *i; // rsi
  __int64 v3; // rax
  signed __int64 v4; // rcx
  _QWORD *v5; // rdx
  UFG::qPropertySet *v6; // rdi
  UFG::qMemoryPool *v7; // rax
  UFG::SceneObjectProperties *v8; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v9; // rcx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v10; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v11; // rcx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::Event *v14; // rdx
  unsigned int v15; // ecx
  UFG::allocator::free_link *v16; // rax
  char v18; // [rsp+60h] [rbp+8h]
  void *v19; // [rsp+68h] [rbp+10h]

  if ( (UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *)UFG::smActivatingLayers.mNode.mNext == &UFG::smActivatingLayers )
    return 0;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v18);
  v0 = UFG::smActivatingLayers.mNode.mNext;
  if ( (UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *)UFG::smActivatingLayers.mNode.mNext != &UFG::smActivatingLayers )
  {
    do
    {
      v1 = (UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *)v0->mNext;
      for ( i = (UFG::SceneLayerResource *)v0[1].mPrev; LODWORD(v0[1].mNext) < i->mPropertySetCount; ++LODWORD(v0[1].mNext) )
      {
        v3 = i->mPropertySets.mOffset;
        if ( v3 )
          v4 = (signed __int64)&i->mPropertySets + v3;
        else
          v4 = 0i64;
        v5 = (_QWORD *)(v4 + 8i64 * LODWORD(v0[1].mNext));
        if ( *v5 )
          v6 = (UFG::qPropertySet *)((char *)v5 + *v5);
        else
          v6 = 0i64;
        v7 = UFG::GetSimulationMemoryPool();
        v8 = (UFG::SceneObjectProperties *)UFG::qMemoryPool::Allocate(
                                             v7,
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
      v9 = v0->mPrev;
      v10 = v0->mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v0->mPrev = v0;
      v0->mNext = v0;
      v19 = v0;
      v11 = v0->mPrev;
      v12 = v0->mNext;
      v11->mNext = v12;
      v12->mPrev = v11;
      v0->mPrev = v0;
      v0->mNext = v0;
      operator delete[](v0);
      v0 = &v1->mNode;
    }
    while ( v1 != &UFG::smActivatingLayers );
  }
  v13 = UFG::qMalloc(0x38ui64, "layerActivatedEvent", 0i64);
  v14 = (UFG::Event *)v13;
  v19 = v13;
  if ( v13 )
  {
    v15 = UFG::gSceneLayerActivatedChannel.mUID;
    v16 = v13 + 1;
    v16->mNext = v16;
    v16[1].mNext = v16;
    v14->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
    v14->m_EventUID = v15;
    v14->m_NamePTR = 0i64;
  }
  else
  {
    v14 = 0i64;
  }
  UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v14);
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v18);
  return 1;
}

// File Line: 171
// RVA: 0x2398F0
void __fastcall UFG::IncrementalActivateManager::Activate(UFG::SceneLayerResource *pSceneLayerResource, bool forceSynchronous)
{
  bool v2; // bl
  UFG::SceneLayerResource *v3; // rbp
  UFG::allocator::free_link *v4; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v5; // rcx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v6; // rax
  unsigned int v7; // eax
  __int64 v8; // rdi
  __int64 v9; // rsi
  __int64 v10; // rax
  signed __int64 v11; // rcx
  signed __int64 v12; // rax
  __int64 v13; // rcx
  UFG::qPropertySet *v14; // rbx
  UFG::qMemoryPool *v15; // rax
  UFG::SceneObjectProperties *v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::Event *v18; // rdx
  unsigned int v19; // ecx
  UFG::allocator::free_link *v20; // rax
  char v21; // [rsp+70h] [rbp+18h]
  void *v22; // [rsp+78h] [rbp+20h]

  v2 = forceSynchronous;
  v3 = pSceneLayerResource;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v21);
  if ( !UFG::gIncrementalActivateManager_Active || v2 || (v3->mFlags >> 2) & 1 )
  {
    v7 = v3->mPropertySetCount;
    if ( v7 )
    {
      v8 = 0i64;
      v9 = v7;
      do
      {
        v10 = v3->mPropertySets.mOffset;
        if ( v10 )
          v11 = (signed __int64)&v3->mPropertySets + v10;
        else
          v11 = 0i64;
        v12 = v8 + v11;
        v13 = *(_QWORD *)(v8 + v11);
        if ( v13 )
          v14 = (UFG::qPropertySet *)(v13 + v12);
        else
          v14 = 0i64;
        v15 = UFG::GetSimulationMemoryPool();
        v16 = (UFG::SceneObjectProperties *)UFG::qMemoryPool::Allocate(
                                              v15,
                                              0xA8ui64,
                                              "SceneObjectProperties-Layer",
                                              0i64,
                                              1u);
        v22 = v16;
        if ( v16 )
          UFG::SceneObjectProperties::SceneObjectProperties(v16, v14, v3);
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
      v19 = UFG::gSceneLayerActivatedChannel.mUID;
      v20 = v17 + 1;
      v20->mNext = v20;
      v20[1].mNext = v20;
      v18->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
      v18->m_EventUID = v19;
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
      v4[2].mNext = (UFG::allocator::free_link *)v3;
      LODWORD(v4[3].mNext) = 0;
    }
    else
    {
      v5 = 0i64;
    }
    v6 = UFG::smActivatingLayers.mNode.mPrev;
    UFG::smActivatingLayers.mNode.mPrev->mNext = v5;
    v5->mPrev = v6;
    v5->mNext = (UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *)&UFG::smActivatingLayers;
    UFG::smActivatingLayers.mNode.mPrev = v5;
  }
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v21);
}

// File Line: 200
// RVA: 0x23A810
void __fastcall UFG::IncrementalActivateManager::Deactivate(UFG::SceneLayerResource *pSceneLayerResource, bool forceSynchronous)
{
  bool v2; // r12
  UFG::SceneLayerResource *v3; // r14
  UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *v4; // rcx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v5; // rdx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v6; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v7; // rdx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v8; // rax
  signed __int64 i; // rax
  signed __int64 v10; // rbx
  __int64 v11; // rcx
  _QWORD *v12; // rax
  UFG::SimObject *v13; // rbp
  char v14; // di
  UFG::qPropertySet *v15; // rcx
  UFG::SchemaDef *v16; // rax
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
  __int64 v29; // rcx
  UFG::TransformNodeComponent *v30; // rcx
  __int64 v31; // rax
  __int64 v32; // rax
  UFG::SceneObjectProperties **v33; // rdi
  unsigned __int64 j; // rsi
  UFG::allocator::free_link *v35; // rax
  UFG::Event *v36; // rdx
  unsigned int v37; // ecx
  UFG::allocator::free_link *v38; // rax

  v2 = forceSynchronous;
  v3 = pSceneLayerResource;
  v4 = (UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *)UFG::smActivatingLayers.mNode.mNext;
  if ( (UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *)UFG::smActivatingLayers.mNode.mNext != &UFG::smActivatingLayers )
  {
    while ( (UFG::SceneLayerResource *)v4[1].mNode.mPrev != v3 )
    {
      v4 = (UFG::qList<UFG::ActivatingLayer,UFG::ActivatingLayer,1,0> *)v4->mNode.mNext;
      if ( v4 == &UFG::smActivatingLayers )
        goto LABEL_6;
    }
    v5 = v4->mNode.mPrev;
    v6 = v4->mNode.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mNode.mPrev = &v4->mNode;
    v4->mNode.mNext = &v4->mNode;
    v7 = v4->mNode.mPrev;
    v8 = v4->mNode.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v4->mNode.mPrev = &v4->mNode;
    v4->mNode.mNext = &v4->mNode;
    operator delete[](v4);
  }
LABEL_6:
  for ( i = (signed __int64)&v3->mObjects.mNode.mNext[-4];
        (char *)i != &v3->mDebugName[28];
        i = (signed __int64)&v3->mObjects.mNode.mNext[-4] )
  {
    v10 = i + 64;
    v11 = *(_QWORD *)(i + 64);
    v12 = *(_QWORD **)(i + 72);
    *(_QWORD *)(v11 + 8) = v12;
    *v12 = v11;
    *(_QWORD *)v10 = v10;
    *(_QWORD *)(v10 + 8) = v10;
    if ( v2 )
    {
      UFG::SceneObjectProperties::Deactivate((UFG::SceneObjectProperties *)(v10 - 64), 4u);
      continue;
    }
    v13 = *(UFG::SimObject **)(v10 - 24);
    if ( !v13 )
      continue;
    v14 = 0;
    if ( (v13->m_Flags & 0x8000u) != 0 )
    {
      v14 = 1;
      goto LABEL_33;
    }
    v15 = *(UFG::qPropertySet **)(v10 + 80);
    if ( !v15 )
      v15 = *(UFG::qPropertySet **)(v10 + 88);
    v16 = UFG::PropertySetManager::GetSchemaForProperty(v15, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID);
    if ( v16 )
    {
      v17 = *(UFG::qPropertySet **)(v10 + 80);
      if ( !v17 )
        v17 = *(UFG::qPropertySet **)(v10 + 88);
      v18 = UFG::qPropertySet::Get<UFG::qPropertySet>(v17, &v16->mPropertyName, DEPTH_RECURSE);
    }
    else
    {
      v18 = *(UFG::qPropertySet **)(v10 + 80);
      if ( v18 )
        goto LABEL_21;
      v18 = *(UFG::qPropertySet **)(v10 + 88);
    }
    if ( !v18 )
      goto LABEL_52;
LABEL_21:
    v19 = UFG::qPropertySet::Get<unsigned long>(v18, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID, DEPTH_RECURSE);
    if ( !v19 || !((*v19 >> 2) & 1) )
    {
LABEL_52:
      v32 = *(unsigned int *)(v10 + 56);
      if ( (_DWORD)v32 )
      {
        v33 = *(UFG::SceneObjectProperties ***)(v10 + 64);
        for ( j = (unsigned __int64)&v33[v32]; (unsigned __int64)v33 < j; ++v33 )
          UFG::SceneObjectProperties::Deactivate(*v33);
      }
      UFG::SceneObjectProperties::mspDeactivateFunc((UFG::SceneObjectProperties *)(v10 - 64));
      UFG::SimObject::Destroy(v13);
      continue;
    }
    v20 = *(UFG::qPropertySet **)(v10 + 80);
    if ( !v20 )
      v20 = *(UFG::qPropertySet **)(v10 + 88);
    v21 = UFG::PropertySetManager::GetSchemaForProperty(v20, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID);
    if ( v21 )
    {
      v22 = *(UFG::qPropertySet **)(v10 + 80);
      if ( !v22 )
        v22 = *(UFG::qPropertySet **)(v10 + 88);
      v23 = UFG::qPropertySet::Get<UFG::qPropertySet>(v22, &v21->mPropertyName, DEPTH_RECURSE);
LABEL_31:
      if ( !v23 )
        goto LABEL_33;
      goto LABEL_32;
    }
    v23 = *(UFG::qPropertySet **)(v10 + 80);
    if ( !v23 )
    {
      v23 = *(UFG::qPropertySet **)(v10 + 88);
      goto LABEL_31;
    }
LABEL_32:
    UFG::qPropertySet::Get<unsigned long>(v23, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID, DEPTH_RECURSE);
LABEL_33:
    v24 = *(UFG::qPropertySet **)(v10 + 80);
    if ( !v24 )
      v24 = *(UFG::qPropertySet **)(v10 + 88);
    v25 = UFG::PropertySetManager::GetSchemaForProperty(v24, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID);
    if ( v25 )
    {
      v26 = *(UFG::qPropertySet **)(v10 + 80);
      if ( !v26 )
        v26 = *(UFG::qPropertySet **)(v10 + 88);
      v27 = UFG::qPropertySet::Get<UFG::qPropertySet>(v26, &v25->mPropertyName, DEPTH_RECURSE);
    }
    else
    {
      v27 = *(UFG::qPropertySet **)(v10 + 80);
      if ( v27 )
        goto LABEL_42;
      v27 = *(UFG::qPropertySet **)(v10 + 88);
    }
    if ( v27 )
    {
LABEL_42:
      v28 = UFG::qPropertySet::Get<unsigned long>(v27, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID, DEPTH_RECURSE);
      if ( v28 && (*v28 >> 2) & 1 )
      {
LABEL_45:
        *(_WORD *)(v10 - 32) |= 8u;
        if ( *(_QWORD *)(v10 + 48) )
        {
          v29 = *(_QWORD *)(v10 - 24);
          if ( v29 )
          {
            v30 = *(UFG::TransformNodeComponent **)(v29 + 88);
            if ( v30 )
            {
              if ( v30->mParent )
                UFG::TransformNodeComponent::SetParentKeepWorld(v30, 0i64, 0);
            }
          }
        }
        *(_QWORD *)(v10 + 40) = 0i64;
        v31 = *(_QWORD *)(v10 + 48);
        if ( v31 )
          *(_BYTE *)(v31 + 136) = 0;
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
    v37 = UFG::gSceneLayerDeactivatedChannel.mUID;
    v38 = v35 + 1;
    v38->mNext = v38;
    v38[1].mNext = v38;
    v36->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
    v36->m_EventUID = v37;
    v36->m_NamePTR = 0i64;
  }
  else
  {
    v36 = 0i64;
  }
  UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v36);
}

