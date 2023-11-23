// File Line: 30
// RVA: 0x1554F10
__int64 dynamic_initializer_for__UFG::VisualEffectAudioManager::sm_visualEffectTracks__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::VisualEffectAudioManager::sm_visualEffectTracks.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::VisualEffectAudioManager::sm_visualEffectTracks__);
}

// File Line: 37
// RVA: 0x5A18E0
void UFG::VisualEffectAudioManager::LoadProperties(void)
{
  UFG::qPropertyList *v0; // r9
  unsigned int v1; // eax
  char *ValuePtr; // rax
  UFG::qPropertySet *v3; // rbx
  UFG::qSymbol *v4; // rsi
  UFG::allocator::free_link *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rdi
  UFG::qPropertyList *v8; // r13
  unsigned int v9; // r12d
  unsigned int v10; // esi
  UFG::allocator::free_link *v11; // r14
  char *v12; // rax
  UFG::qPropertySet *v13; // rbx
  float *v14; // r15
  UFG::qWiseSymbol *v15; // rbp
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // rdi
  UFG::qWiseSymbol *null; // rax
  UFG::allocator::free_link *mNext; // rax
  unsigned int i; // [rsp+80h] [rbp+8h]
  UFG::qSymbol result; // [rsp+88h] [rbp+10h] BYREF
  unsigned int mNumElements; // [rsp+90h] [rbp+18h]
  UFG::qPropertyList *v23; // [rsp+98h] [rbp+20h]

  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&UFG::VisualEffectAudioManager::sm_visualEffectTracks);
  UFG::qSymbol::create_from_string(&result, "Audio-VisualEffectAudio");
  UFG::VisualEffectAudioManager::sm_propertySet = UFG::PropertySetManager::GetPropertySet(&result);
  v0 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         UFG::VisualEffectAudioManager::sm_propertySet,
         (UFG::qArray<unsigned long,0> *)&TiDoSym_VisualEffectList,
         DEPTH_RECURSE);
  v23 = v0;
  mNumElements = v0->mNumElements;
  v1 = 0;
  for ( i = 0; v1 < mNumElements; v0 = v23 )
  {
    ValuePtr = UFG::qPropertyList::GetValuePtr(v0, 0x1Au, v1);
    if ( ValuePtr && *(_QWORD *)ValuePtr )
      v3 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
    else
      v3 = 0i64;
    v4 = UFG::qPropertySet::Get<UFG::qSymbol>(
           v3,
           (UFG::qArray<unsigned long,0> *)&TiDoSym_VisualEffectName,
           DEPTH_RECURSE);
    v5 = UFG::qMalloc(0x40ui64, "VisualEffectAudioTrack", 0i64);
    if ( v5 )
    {
      UFG::VisualEffectAudioTrack::VisualEffectAudioTrack((UFG::VisualEffectAudioTrack *)v5);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    *(UFG::qSymbol *)(v7 + 32) = (UFG::qSymbol)v4->mUID;
    *(UFG::qSymbol *)(v7 + 40) = (UFG::qSymbol)v4->mUID;
    UFG::qBaseTreeRB::Add(&UFG::VisualEffectAudioManager::sm_visualEffectTracks.mTree, (UFG::qBaseNodeRB *)(v7 + 8));
    v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, (UFG::qArray<unsigned long,0> *)&TiDoSym_Tags, DEPTH_RECURSE);
    v9 = v8->mNumElements;
    v10 = 0;
    if ( v9 )
    {
      v11 = (UFG::allocator::free_link *)(v7 + 48);
      do
      {
        v12 = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v10);
        if ( v12 && *(_QWORD *)v12 )
          v13 = (UFG::qPropertySet *)&v12[*(_QWORD *)v12];
        else
          v13 = 0i64;
        v14 = UFG::qPropertySet::Get<float>(v13, (UFG::qArray<unsigned long,0> *)&TiDoSym_TimeBegin, DEPTH_RECURSE);
        v15 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(
                v13,
                (UFG::qArray<unsigned long,0> *)&TiDoSym_SampleUid,
                DEPTH_RECURSE);
        v16 = UFG::qMalloc(0x28ui64, "VisualEffectAudioNode", 0i64);
        v17 = v16;
        if ( v16 )
        {
          v16[1].mNext = v16 + 1;
          v16[2].mNext = v16 + 1;
          v16->mNext = (UFG::allocator::free_link *)&UFG::VisualEffectAudioNode::`vftable;
          v16[3].mNext = 0i64;
          LODWORD(v16[4].mNext) = -1;
          _((AMD_HD3D *)0xFFFFFFFFi64);
          null = UFG::qWiseSymbol::get_null();
          UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)&v17[4], null);
          HIDWORD(v17[4].mNext) = 0;
        }
        else
        {
          v17 = 0i64;
        }
        mNext = v11->mNext;
        mNext[1].mNext = v17 + 1;
        v17[1].mNext = mNext;
        v17[2].mNext = v11;
        v11->mNext = v17 + 1;
        *((float *)&v17[4].mNext + 1) = *v14;
        UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)&v17[4], v15);
        ++v10;
      }
      while ( v10 < v9 );
    }
    v1 = i + 1;
    i = v1;
  }
}

// File Line: 108
// RVA: 0x5AF770
void __fastcall UFG::VisualEffectAudioManager::Update(float delta_sec)
{
  float v1; // xmm6_4
  UFG::qNode<UFG::VisualEffectAudioNode,UFG::VisualEffectAudioNode> **i; // rbx
  float v3; // xmm0_4

  if ( UFG::VisualEffectAudioManager::sm_isPlaying )
  {
    v1 = UFG::VisualEffectAudioManager::sm_playTime;
    UFG::VisualEffectAudioManager::sm_playTime = UFG::VisualEffectAudioManager::sm_playTime + delta_sec;
    for ( i = &UFG::VisualEffectAudioManager::sm_curTrack->m_nodes.mNode.mNext[-1].mNext;
          i != (UFG::qNode<UFG::VisualEffectAudioNode,UFG::VisualEffectAudioNode> **)&UFG::VisualEffectAudioManager::sm_curTrack->m_visualEffect;
          i = &i[2][-1].mNext )
    {
      v3 = *((float *)i + 9);
      if ( v1 <= v3 && v3 < UFG::VisualEffectAudioManager::sm_playTime )
      {
        UFG::OneShotHandle::StopAndRelease((UFG::OneShotHandle *)i + 3);
        UFG::OneShotPool::GetOneShotHandle((UFG::OneShotHandle *)i + 3, &UFG::qMatrix44::msIdentity);
        if ( UFG::OneShotHandle::IsValid((UFG::OneShotHandle *)i + 3) )
          UFG::OneShot::Play((UFG::OneShot *)i[3], *((_DWORD *)i + 8));
      }
    }
  }
}

// File Line: 167
// RVA: 0x1554D80
__int64 dynamic_initializer_for__UFG::DoorStateManager::sm_indoorState__()
{
  UFG::DoorStateManager::sm_indoorState.mUID = UFG::qWiseSymbol::get_null()->mUID;
  _((AMD_HD3D *)UFG::DoorStateManager::sm_indoorState.mUID);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DoorStateManager::sm_indoorState__);
}

// File Line: 168
// RVA: 0x1554DF0
__int64 dynamic_initializer_for__UFG::DoorStateManager::sm_outdoorState__()
{
  UFG::DoorStateManager::sm_outdoorState.mUID = UFG::qWiseSymbol::get_null()->mUID;
  _((AMD_HD3D *)UFG::DoorStateManager::sm_outdoorState.mUID);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DoorStateManager::sm_outdoorState__);
}

// File Line: 169
// RVA: 0x1554CE0
__int64 dynamic_initializer_for__UFG::DoorStateManager::sm_doorMix__()
{
  UFG::DoorStateManager::sm_doorMix.mUID = UFG::qWiseSymbol::get_null()->mUID;
  _((AMD_HD3D *)UFG::DoorStateManager::sm_doorMix.mUID);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DoorStateManager::sm_doorMix__);
}

// File Line: 171
// RVA: 0x1554D30
__int64 dynamic_initializer_for__UFG::DoorStateManager::sm_doorRegionName__()
{
  UFG::DoorStateManager::sm_doorRegionName.mUID = UFG::gNullQSymbol.mUID;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DoorStateManager::sm_doorRegionName__);
}

// File Line: 172
// RVA: 0x1554D10
__int64 dynamic_initializer_for__UFG::DoorStateManager::sm_doorName__()
{
  UFG::DoorStateManager::sm_doorName.mUID = UFG::gNullQSymbol.mUID;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DoorStateManager::sm_doorName__);
}

// File Line: 179
// RVA: 0x1554D50
__int64 dynamic_initializer_for__UFG::DoorStateManager::sm_doors__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::DoorStateManager::sm_doors.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DoorStateManager::sm_doors__);
}

// File Line: 190
// RVA: 0x155CBE0
__int64 UFG::_dynamic_initializer_for__qws_MS_LOCATION__()
{
  UFG::qWiseSymbol::create_from_string(&qws_MS_LOCATION, "MS_LOCATION");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qws_MS_LOCATION__);
}

// File Line: 191
// RVA: 0x155CC10
__int64 UFG::_dynamic_initializer_for__qws_MS_NONE__()
{
  UFG::qWiseSymbol::create_from_string(&qws_MS_NONE, "None");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qws_MS_NONE__);
}

// File Line: 192
// RVA: 0x155A6C0
__int64 UFG::_dynamic_initializer_for__play_door_close__()
{
  UFG::qWiseSymbol::create_from_string(&play_door_close_0, "play_door_close");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__play_door_close__);
}

// File Line: 193
// RVA: 0x155A6F0
__int64 UFG::_dynamic_initializer_for__play_door_open__()
{
  UFG::qWiseSymbol::create_from_string(&play_door_open_0, "play_door_open");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__play_door_open__);
}

// File Line: 197
// RVA: 0x59E350
void __fastcall UFG::DoorStateManager::HandleDoorOpen(UFG::SimObject *door, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::OneShotHandle pHandle; // [rsp+48h] [rbp+10h] BYREF

  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)door, a2) )
  {
    if ( door )
      m_pTransformNodeComponent = door->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    pHandle.m_pOneShot = 0i64;
    UFG::OneShotPool::GetOneShotHandle(&pHandle, &m_pTransformNodeComponent->mWorldTransform);
    if ( UFG::OneShotHandle::IsValid(&pHandle) )
    {
      UFG::TidoGame::HandleDoorType(door, &pHandle);
      UFG::OneShot::Play(pHandle.m_pOneShot, play_door_open_0.mUID);
    }
    if ( UFG::DoorStateManager::sm_active )
    {
      UFG::DoorStateManager::sm_open = 1;
      UFG::DoorStateManager::sm_inside = UFG::AudioTriggerRegion::sm_interiorTransitionCount > 0;
      UFG::DoorStateManager::sm_doorName.mUID = door->m_Name.mUID;
      UFG::DoorStateManager::SetDoorMix();
    }
    UFG::OneShotHandle::Release(&pHandle);
  }
}

// File Line: 227
// RVA: 0x59E280
void __fastcall UFG::DoorStateManager::HandleDoorClose(UFG::SimObject *door, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::OneShotHandle pHandle; // [rsp+48h] [rbp+10h] BYREF

  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)door, a2) )
  {
    if ( door )
      m_pTransformNodeComponent = door->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    pHandle.m_pOneShot = 0i64;
    UFG::OneShotPool::GetOneShotHandle(&pHandle, &m_pTransformNodeComponent->mWorldTransform);
    if ( UFG::OneShotHandle::IsValid(&pHandle) )
    {
      UFG::TidoGame::HandleDoorType(door, &pHandle);
      UFG::OneShot::Play(pHandle.m_pOneShot, play_door_close_0.mUID);
    }
    if ( UFG::DoorStateManager::sm_active && door->m_Name.mUID == UFG::DoorStateManager::sm_doorName.mUID )
    {
      UFG::DoorStateManager::sm_open = 0;
      UFG::DoorStateManager::sm_inside = UFG::AudioTriggerRegion::sm_interiorTransitionCount > 0;
      UFG::DoorStateManager::sm_doorName.mUID = door->m_Name.mUID;
      UFG::DoorStateManager::SetDoorMix();
    }
    UFG::OneShotHandle::Release(&pHandle);
  }
}

// File Line: 262
// RVA: 0x59E830
void UFG::DoorStateManager::HandleInOutTransition(void)
{
  if ( UFG::DoorStateManager::sm_active )
  {
    if ( UFG::DoorStateManager::sm_inside )
    {
      UFG::DoorStateManager::sm_inside = 0;
      if ( UFG::AudioTriggerRegion::sm_interiorTransitionCount <= 0 )
      {
LABEL_7:
        UFG::DoorStateManager::SetDoorMix();
        return;
      }
    }
    else if ( UFG::AudioTriggerRegion::sm_interiorTransitionCount > 0 )
    {
      UFG::DoorStateManager::sm_inside = 1;
      UFG::DoorStateManager::SetDoorMix();
      return;
    }
    UFG::DoorStateManager::sm_inside = UFG::AudioTriggerRegion::sm_interiorTransitionCount > 0;
    goto LABEL_7;
  }
}

// File Line: 294
// RVA: 0x5A3C80
void UFG::DoorStateManager::OnEnterRegion(void)
{
  UFG::SimComponent *SimObject; // rax
  __int16 v1; // cx
  bool IsOpen; // cl
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  UFG::DoorStateManager::sm_doorName.mUID = UFG::AudioTriggerRegion::CheckRegionForDoors(
                                              &result,
                                              (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::DoorStateManager::sm_doors)->mUID;
  SimObject = (UFG::SimComponent *)UFG::Simulation::GetSimObject(&UFG::gSim, &UFG::DoorStateManager::sm_doorName);
  if ( SimObject )
  {
    v1 = WORD2(SimObject[1].m_SafePointerList.mNode.mPrev);
    if ( (v1 & 0x4000) != 0 || v1 < 0 || (v1 & 0x2000) != 0 || (v1 & 0x1000) != 0 )
      SimObject = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)SimObject,
                    UFG::DoorComponent::_TypeUID);
    else
      SimObject = UFG::SimObject::GetComponentOfType((UFG::SimObject *)SimObject, UFG::DoorComponent::_TypeUID);
  }
  IsOpen = 0;
  if ( SimObject )
    IsOpen = UFG::DoorComponent::IsOpen((UFG::DoorComponent *)SimObject);
  if ( UFG::AudioTriggerRegion::sm_interiorTransitionCount <= 0
    || (UFG::DoorStateManager::sm_inside = 1, UFG::AudioTriggerRegion::sm_rainDrawOverride) )
  {
    UFG::DoorStateManager::sm_inside = 0;
  }
  UFG::DoorStateManager::sm_open = IsOpen;
  UFG::DoorStateManager::sm_active = 1;
  UFG::DoorStateManager::SetDoorMix();
}

// File Line: 314
// RVA: 0x5A4000
void UFG::DoorStateManager::OnExitRegion(void)
{
  UFG::qWiseSymbol *null; // rax
  UFG::qWiseSymbol *v1; // rax

  UFG::DoorStateManager::sm_active = 0;
  UFG::DoorStateManager::sm_doorName.mUID = UFG::gNullQSymbol.mUID;
  null = UFG::qWiseSymbol::get_null();
  UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_indoorState, null);
  v1 = UFG::qWiseSymbol::get_null();
  UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_outdoorState, v1);
  UFG::DoorStateManager::sm_inside = UFG::AudioTriggerRegion::sm_interiorTransitionCount > 0;
  UFG::DoorStateManager::SetDoorMix();
}

// File Line: 328
// RVA: 0x5AABD0
void UFG::DoorStateManager::SetDoorMix(void)
{
  UFG::TiDoVtbl *vfptr; // rax

  if ( UFG::DoorStateManager::sm_open && UFG::DoorStateManager::sm_active )
  {
    vfptr = UFG::TiDo::m_pInstance->vfptr;
    if ( UFG::DoorStateManager::sm_inside )
    {
      ((void (__fastcall *)(UFG::TiDo *, _QWORD, _QWORD))vfptr[1].CreateAudioEntityRegionData)(
        UFG::TiDo::m_pInstance,
        qws_MS_LOCATION.mUID,
        UFG::DoorStateManager::sm_indoorState.mUID);
      UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_doorMix, &UFG::DoorStateManager::sm_indoorState);
    }
    else
    {
      ((void (__fastcall *)(UFG::TiDo *, _QWORD, _QWORD))vfptr[1].CreateAudioEntityRegionData)(
        UFG::TiDo::m_pInstance,
        qws_MS_LOCATION.mUID,
        UFG::DoorStateManager::sm_outdoorState.mUID);
      UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_doorMix, &UFG::DoorStateManager::sm_outdoorState);
    }
  }
  else
  {
    ((void (__fastcall *)(UFG::TiDo *, _QWORD, _QWORD))UFG::TiDo::m_pInstance->vfptr[1].CreateAudioEntityRegionData)(
      UFG::TiDo::m_pInstance,
      qws_MS_LOCATION.mUID,
      UFG::AudioTriggerRegion::msActiveMixUid.mUID);
    UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_doorMix, &UFG::AudioTriggerRegion::msActiveMixUid);
  }
}

// File Line: 389
// RVA: 0x595F70
void __fastcall UFG::DoorStateManager::AddDoor(UFG::qSymbol *name, UFG::qVector3 *pos)
{
  UFG::allocator::free_link *v4; // rax
  UFG::qBaseNodeRB *v5; // rdx
  float y; // xmm1_4
  float z; // xmm2_4

  if ( !name->mUID || !UFG::qBaseTreeRB::Get(&UFG::DoorStateManager::sm_doors.mTree, name->mUID) )
  {
    v4 = UFG::qMalloc(0x30ui64, "AudioDoorManager.DoorNode", 0i64);
    v5 = (UFG::qBaseNodeRB *)v4;
    if ( v4 )
    {
      v4->mNext = 0i64;
      v4[1].mNext = 0i64;
      v4[2].mNext = 0i64;
      LODWORD(v4[4].mNext) = -1;
      LODWORD(v4[4].mNext) = (UFG::qSymbol)name->mUID;
      y = pos->y;
      z = pos->z;
      HIDWORD(v4[4].mNext) = LODWORD(pos->x);
      *(float *)&v4[5].mNext = y;
      *((float *)&v4[5].mNext + 1) = z;
      LODWORD(v4[3].mNext) = v4[4].mNext;
    }
    else
    {
      v5 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&UFG::DoorStateManager::sm_doors.mTree, v5);
  }
}

// File Line: 399
// RVA: 0x5A9F90
void __fastcall UFG::DoorStateManager::RemoveDoor(UFG::qSymbol *name)
{
  UFG::qBaseTreeRB *v1; // rax
  UFG::qBaseTreeRB *v2; // rbx

  if ( name->mUID )
  {
    v1 = UFG::qBaseTreeRB::Get(&UFG::DoorStateManager::sm_doors.mTree, name->mUID);
    v2 = v1;
    if ( v1 )
    {
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::DoorStateManager::sm_doors,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)v1);
      operator delete[](v2);
    }
  }
}

// File Line: 466
// RVA: 0x1554CA0
__int64 dynamic_initializer_for__UFG::AudioSurfaceTypeManager::sm_database__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::AudioSurfaceTypeManager::sm_database.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioSurfaceTypeManager::sm_database__);
}

// File Line: 475
// RVA: 0x5A2120
void __fastcall UFG::AudioSurfaceTypeManager::LoadSurfaceBankInfo(const char *filename)
{
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx
  SimpleXML::XMLDocument *v5; // r15
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLNode *ChildNode; // r12
  char *Attribute; // rax
  UFG::qBaseTreeRB *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdi
  unsigned int mUID; // ebx
  UFG::qBaseNodeRB *v13; // rdx
  SimpleXML::XMLNode *v14; // rbp
  char *v15; // rax
  char *v16; // rax
  UFG::qBaseTreeRB *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rbx
  unsigned int v20; // esi
  UFG::qWiseSymbol *null; // rax
  SimpleXML::XMLNode *i; // [rsp+30h] [rbp-58h]
  UFG::qSymbol v23; // [rsp+98h] [rbp+10h] BYREF
  UFG::qSymbol result; // [rsp+A0h] [rbp+18h] BYREF
  UFG::qWiseSymbol source; // [rsp+A8h] [rbp+20h] BYREF

  if ( UFG::AudioSurfaceTypeManager::sm_database.mTree.mCount )
  {
    while ( 1 )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioSurfaceTypeManager::sm_database);
      if ( !Head )
        break;
      p_mCachedBufferPtr = &Head[-1].mCachedBufferPtr;
      if ( Head == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      p_mNode = &Head->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::AudioSurfaceTypeManager::sm_database,
        p_mNode);
      if ( p_mCachedBufferPtr )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mParent)(
          p_mCachedBufferPtr,
          1i64);
      if ( !UFG::AudioSurfaceTypeManager::sm_database.mTree.mCount )
        goto LABEL_10;
    }
    p_mCachedBufferPtr = 0i64;
LABEL_6:
    p_mNode = 0i64;
    goto LABEL_7;
  }
LABEL_10:
  v5 = SimpleXML::XMLDocument::Open(filename, 1ui64, 0i64);
  Node = SimpleXML::XMLDocument::GetNode(v5, "SurfaceBankMap", 0i64);
  ChildNode = SimpleXML::XMLDocument::GetChildNode(v5, "Surface", Node);
  for ( i = ChildNode; ChildNode; i = ChildNode )
  {
    Attribute = SimpleXML::XMLNode::GetAttribute(ChildNode, "name", 0i64);
    UFG::qSymbol::create_from_string(&result, Attribute);
    if ( !result.mUID
      || (v9 = UFG::qBaseTreeRB::Get(&UFG::AudioSurfaceTypeManager::sm_database.mTree, result.mUID)) == 0i64
      || v9 == (UFG::qBaseTreeRB *)8 )
    {
      v10 = UFG::qMemoryPool::Allocate(&g_AudioMemoryPool, 0x70ui64, "SurfaceBankNode", 0i64, 1u);
      v11 = v10;
      if ( v10 )
      {
        mUID = result.mUID;
        v10[1].mNext = 0i64;
        v10[2].mNext = 0i64;
        v10[3].mNext = 0i64;
        v10->mNext = (UFG::allocator::free_link *)&UFG::SurfaceBankNode::`vftable;
        UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&v10[5]);
        LODWORD(v11[4].mNext) = mUID;
      }
      else
      {
        v11 = 0i64;
      }
      v13 = (UFG::qBaseNodeRB *)&v11[1];
      if ( !v11 )
        v13 = 0i64;
      UFG::qBaseTreeRB::Add(&UFG::AudioSurfaceTypeManager::sm_database.mTree, v13);
      v14 = SimpleXML::XMLDocument::GetChildNode(v5, "Bank", ChildNode);
      if ( v14 )
      {
        do
        {
          v15 = SimpleXML::XMLNode::GetAttribute(v14, "footwear", &customCaption);
          UFG::qSymbol::create_from_string(&v23, v15);
          v16 = SimpleXML::XMLNode::GetAttribute(v14, "bankId", &customCaption);
          UFG::qWiseSymbol::create_from_string(&source, v16);
          if ( !v23.mUID
            || (v17 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&v11[5], v23.mUID)) == 0i64
            || v17 == (UFG::qBaseTreeRB *)8 )
          {
            v18 = UFG::qMemoryPool::Allocate(&g_AudioMemoryPool, 0x30ui64, "BankNode", 0i64, 1u);
            v19 = v18;
            if ( v18 )
            {
              v20 = v23.mUID;
              v18[1].mNext = 0i64;
              v18[2].mNext = 0i64;
              v18[3].mNext = 0i64;
              v18->mNext = (UFG::allocator::free_link *)&UFG::BankNode::`vftable;
              LODWORD(v18[5].mNext) = -1;
              _((AMD_HD3D *)0xFFFFFFFFi64);
              HIDWORD(v19[5].mNext) = -1;
              LODWORD(v19[4].mNext) = v20;
              null = UFG::qWiseSymbol::get_null();
              UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)&v19[5], null);
              HIDWORD(v19[5].mNext) = UFG::gNullQSymbol;
            }
            else
            {
              v19 = 0i64;
            }
            HIDWORD(v19[5].mNext) = v23;
            UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)&v19[5], &source);
            UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)&v11[5], (UFG::qBaseNodeRB *)&v19[1]);
          }
          _((AMD_HD3D *)source.mUID);
          v14 = SimpleXML::XMLDocument::GetNode(v5, "Bank", v14);
        }
        while ( v14 );
        ChildNode = i;
      }
    }
    ChildNode = SimpleXML::XMLDocument::GetNode(v5, "Surface", ChildNode);
  }
}

// File Line: 531
// RVA: 0x59D580
UFG::qWiseSymbol *__fastcall UFG::AudioSurfaceTypeManager::GetSurfaceBankId(
        UFG::qWiseSymbol *result,
        unsigned int surfaceId,
        unsigned int footwear)
{
  int *v6; // rbx
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v8; // rax
  int *v9; // rbp
  UFG::qBaseTreeRB *v10; // rax
  int *v11; // rax
  AMD_HD3D *v12; // rcx
  unsigned int v13; // edx
  UFG::qBaseTreeRB *v14; // rcx
  UFG::qBaseTreeRB *v15; // rax
  int *p_mCount; // rcx
  UFG::qBaseTreeRB *v17; // rax
  AMD_HD3D *v18; // rcx

  v6 = 0i64;
  if ( (_S38_1 & 1) == 0 )
  {
    _S38_1 |= 1u;
    UFG::qSymbol::create_from_string(&qSymbol_default, "default");
    atexit(UFG::AudioSurfaceTypeManager::GetSurfaceBankId_::_2_::_dynamic_atexit_destructor_for__qSymbol_default__);
  }
  mUID = qSymbol_default.mUID;
  if ( !footwear )
    footwear = qSymbol_default.mUID;
  if ( !surfaceId )
    goto LABEL_15;
  v8 = UFG::qBaseTreeRB::Get(&UFG::AudioSurfaceTypeManager::sm_database.mTree, surfaceId);
  if ( !v8 || (v9 = &v8[-1].mCount, v8 == (UFG::qBaseTreeRB *)8) )
  {
    mUID = qSymbol_default.mUID;
LABEL_15:
    if ( !mUID )
      goto LABEL_22;
    v15 = UFG::qBaseTreeRB::Get(&UFG::AudioSurfaceTypeManager::sm_database.mTree, mUID);
    p_mCount = &v15[-1].mCount;
    if ( !v15 )
      p_mCount = 0i64;
    v13 = qSymbol_default.mUID;
    if ( !qSymbol_default.mUID )
      goto LABEL_22;
    v14 = (UFG::qBaseTreeRB *)(p_mCount + 10);
    goto LABEL_20;
  }
  if ( !footwear
    || (v10 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)(v9 + 10), footwear)) == 0i64
    || (v11 = &v10[-1].mCount) == 0i64 )
  {
    v13 = qSymbol_default.mUID;
    if ( !qSymbol_default.mUID )
    {
LABEL_22:
      v18 = (AMD_HD3D *)(unsigned int)v6[10];
      result->mUID = (unsigned int)v18;
      _(v18);
      return result;
    }
    v14 = (UFG::qBaseTreeRB *)(v9 + 10);
LABEL_20:
    v17 = UFG::qBaseTreeRB::Get(v14, v13);
    if ( v17 )
      v6 = &v17[-1].mCount;
    goto LABEL_22;
  }
  v12 = (AMD_HD3D *)(unsigned int)v11[10];
  result->mUID = (unsigned int)v12;
  _(v12);
  return result;
}

