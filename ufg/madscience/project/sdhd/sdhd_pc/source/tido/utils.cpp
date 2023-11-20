// File Line: 30
// RVA: 0x1554F10
__int64 dynamic_initializer_for__UFG::VisualEffectAudioManager::sm_visualEffectTracks__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::VisualEffectAudioManager::sm_visualEffectTracks.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::VisualEffectAudioManager::sm_visualEffectTracks__);
}

// File Line: 37
// RVA: 0x5A18E0
void UFG::VisualEffectAudioManager::LoadProperties(void)
{
  UFG::qPropertySet *v0; // rax
  UFG::qPropertyList *v1; // rax
  UFG::qPropertyList *v2; // r9
  unsigned int v3; // eax
  char *v4; // rax
  UFG::qPropertySet *v5; // rbx
  UFG::qSymbol *v6; // rsi
  UFG::allocator::free_link *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rdi
  UFG::qPropertyList *v10; // r13
  unsigned int v11; // er12
  unsigned int v12; // esi
  __int64 *v13; // r14
  char *v14; // rax
  UFG::qPropertySet *v15; // rbx
  float *v16; // r15
  UFG::qWiseSymbol *v17; // rbp
  UFG::allocator::free_link *v18; // rax
  UFG::qWiseSymbol *v19; // rdi
  UFG::allocator::free_link *v20; // rcx
  UFG::qWiseSymbol *v21; // rax
  UFG::qWiseSymbol *v22; // rcx
  __int64 v23; // rax
  unsigned int v24; // [rsp+80h] [rbp+8h]
  UFG::qSymbol result; // [rsp+88h] [rbp+10h]
  unsigned int v26; // [rsp+90h] [rbp+18h]
  UFG::qPropertyList *v27; // [rsp+98h] [rbp+20h]

  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&UFG::VisualEffectAudioManager::sm_visualEffectTracks);
  UFG::qSymbol::create_from_string(&result, "Audio-VisualEffectAudio");
  v0 = UFG::PropertySetManager::GetPropertySet(&result);
  UFG::VisualEffectAudioManager::sm_propertySet = v0;
  v1 = UFG::qPropertySet::Get<UFG::qPropertyList>(v0, (UFG::qSymbol *)&TiDoSym_VisualEffectList.mUID, DEPTH_RECURSE);
  v2 = v1;
  v27 = v1;
  v26 = v1->mNumElements;
  v3 = 0;
  v24 = 0;
  if ( v26 )
  {
    do
    {
      v4 = UFG::qPropertyList::GetValuePtr(v2, 0x1Au, v3);
      if ( v4 && *(_QWORD *)v4 )
        v5 = (UFG::qPropertySet *)&v4[*(_QWORD *)v4];
      else
        v5 = 0i64;
      v6 = UFG::qPropertySet::Get<UFG::qSymbol>(v5, (UFG::qSymbol *)&TiDoSym_VisualEffectName.mUID, DEPTH_RECURSE);
      v7 = UFG::qMalloc(0x40ui64, "VisualEffectAudioTrack", 0i64);
      if ( v7 )
      {
        UFG::VisualEffectAudioTrack::VisualEffectAudioTrack((UFG::VisualEffectAudioTrack *)v7);
        v9 = v8;
      }
      else
      {
        v9 = 0i64;
      }
      *(UFG::qSymbol *)(v9 + 32) = (UFG::qSymbol)v6->mUID;
      *(UFG::qSymbol *)(v9 + 40) = (UFG::qSymbol)v6->mUID;
      UFG::qBaseTreeRB::Add(&UFG::VisualEffectAudioManager::sm_visualEffectTracks.mTree, (UFG::qBaseNodeRB *)(v9 + 8));
      v10 = UFG::qPropertySet::Get<UFG::qPropertyList>(v5, (UFG::qSymbol *)&TiDoSym_Tags.mUID, DEPTH_RECURSE);
      v11 = v10->mNumElements;
      v12 = 0;
      if ( v11 )
      {
        v13 = (__int64 *)(v9 + 48);
        do
        {
          v14 = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, v12);
          if ( v14 && *(_QWORD *)v14 )
            v15 = (UFG::qPropertySet *)&v14[*(_QWORD *)v14];
          else
            v15 = 0i64;
          v16 = UFG::qPropertySet::Get<float>(v15, (UFG::qSymbol *)&TiDoSym_TimeBegin.mUID, DEPTH_RECURSE);
          v17 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v15, (UFG::qSymbol *)&TiDoSym_SampleUid.mUID, DEPTH_RECURSE);
          v18 = UFG::qMalloc(0x28ui64, "VisualEffectAudioNode", 0i64);
          v19 = (UFG::qWiseSymbol *)v18;
          if ( v18 )
          {
            v20 = v18 + 1;
            v20->mNext = v20;
            v20[1].mNext = v20;
            v18->mNext = (UFG::allocator::free_link *)&UFG::VisualEffectAudioNode::`vftable';
            v18[3].mNext = 0i64;
            LODWORD(v18[4].mNext) = -1;
            _((AMD_HD3D *)0xFFFFFFFFi64);
            v21 = UFG::qWiseSymbol::get_null();
            UFG::qWiseSymbol::operator=(v19 + 8, v21);
            v19[9].mUID = 0;
          }
          else
          {
            v19 = 0i64;
          }
          v22 = v19 + 2;
          v23 = *v13;
          *(_QWORD *)(v23 + 8) = v19 + 2;
          *(_QWORD *)&v22->mUID = v23;
          *(_QWORD *)&v22[2].mUID = v13;
          *v13 = (__int64)&v19[2];
          v19[9].mUID = *(unsigned int *)v16;
          UFG::qWiseSymbol::operator=(v19 + 8, v17);
          ++v12;
        }
        while ( v12 < v11 );
      }
      v3 = v24 + 1;
      v24 = v3;
      v2 = v27;
    }
    while ( v3 < v26 );
  }
}v12 < v11 );
      }
      v3 = v24 + 1;
      v24 = v3;
      v2 = v27;
   

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
  return atexit(dynamic_atexit_destructor_for__UFG::DoorStateManager::sm_indoorState__);
}

// File Line: 168
// RVA: 0x1554DF0
__int64 dynamic_initializer_for__UFG::DoorStateManager::sm_outdoorState__()
{
  UFG::DoorStateManager::sm_outdoorState.mUID = UFG::qWiseSymbol::get_null()->mUID;
  _((AMD_HD3D *)UFG::DoorStateManager::sm_outdoorState.mUID);
  return atexit(dynamic_atexit_destructor_for__UFG::DoorStateManager::sm_outdoorState__);
}

// File Line: 169
// RVA: 0x1554CE0
__int64 dynamic_initializer_for__UFG::DoorStateManager::sm_doorMix__()
{
  UFG::DoorStateManager::sm_doorMix.mUID = UFG::qWiseSymbol::get_null()->mUID;
  _((AMD_HD3D *)UFG::DoorStateManager::sm_doorMix.mUID);
  return atexit(dynamic_atexit_destructor_for__UFG::DoorStateManager::sm_doorMix__);
}

// File Line: 171
// RVA: 0x1554D30
__int64 dynamic_initializer_for__UFG::DoorStateManager::sm_doorRegionName__()
{
  UFG::DoorStateManager::sm_doorRegionName.mUID = UFG::gNullQSymbol.mUID;
  return atexit(dynamic_atexit_destructor_for__UFG::DoorStateManager::sm_doorRegionName__);
}

// File Line: 172
// RVA: 0x1554D10
__int64 dynamic_initializer_for__UFG::DoorStateManager::sm_doorName__()
{
  UFG::DoorStateManager::sm_doorName.mUID = UFG::gNullQSymbol.mUID;
  return atexit(dynamic_atexit_destructor_for__UFG::DoorStateManager::sm_doorName__);
}

// File Line: 179
// RVA: 0x1554D50
__int64 dynamic_initializer_for__UFG::DoorStateManager::sm_doors__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::DoorStateManager::sm_doors.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::DoorStateManager::sm_doors__);
}

// File Line: 190
// RVA: 0x155CBE0
__int64 UFG::_dynamic_initializer_for__qws_MS_LOCATION__()
{
  UFG::qWiseSymbol::create_from_string(&qws_MS_LOCATION, "MS_LOCATION");
  return atexit(UFG::_dynamic_atexit_destructor_for__qws_MS_LOCATION__);
}

// File Line: 191
// RVA: 0x155CC10
__int64 UFG::_dynamic_initializer_for__qws_MS_NONE__()
{
  UFG::qWiseSymbol::create_from_string(&qws_MS_NONE, "None");
  return atexit(UFG::_dynamic_atexit_destructor_for__qws_MS_NONE__);
}

// File Line: 192
// RVA: 0x155A6C0
__int64 UFG::_dynamic_initializer_for__play_door_close__()
{
  UFG::qWiseSymbol::create_from_string(&play_door_close_0, "play_door_close");
  return atexit(UFG::_dynamic_atexit_destructor_for__play_door_close__);
}

// File Line: 193
// RVA: 0x155A6F0
__int64 UFG::_dynamic_initializer_for__play_door_open__()
{
  UFG::qWiseSymbol::create_from_string(&play_door_open_0, "play_door_open");
  return atexit(UFG::_dynamic_atexit_destructor_for__play_door_open__);
}

// File Line: 197
// RVA: 0x59E350
void __fastcall UFG::DoorStateManager::HandleDoorOpen(UFG::SimObject *door, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::SimObject *v2; // rbx
  UFG::TransformNodeComponent *v3; // rdi
  UFG::OneShotHandle pHandle; // [rsp+48h] [rbp+10h]

  v2 = door;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)door, a2) )
  {
    if ( v2 )
      v3 = v2->m_pTransformNodeComponent;
    else
      v3 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v3);
    pHandle.m_pOneShot = 0i64;
    UFG::OneShotPool::GetOneShotHandle(&pHandle, &v3->mWorldTransform);
    if ( UFG::OneShotHandle::IsValid(&pHandle) )
    {
      UFG::TidoGame::HandleDoorType(v2, &pHandle);
      UFG::OneShot::Play(pHandle.m_pOneShot, play_door_open_0.mUID);
    }
    if ( UFG::DoorStateManager::sm_active )
    {
      UFG::DoorStateManager::sm_open = 1;
      UFG::DoorStateManager::sm_inside = UFG::AudioTriggerRegion::sm_interiorTransitionCount > 0;
      UFG::DoorStateManager::sm_doorName.mUID = v2->m_Name.mUID;
      UFG::DoorStateManager::SetDoorMix();
    }
    UFG::OneShotHandle::Release(&pHandle);
  }
}

// File Line: 227
// RVA: 0x59E280
void __fastcall UFG::DoorStateManager::HandleDoorClose(UFG::SimObject *door, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::SimObject *v2; // rbx
  UFG::TransformNodeComponent *v3; // rdi
  UFG::OneShotHandle pHandle; // [rsp+48h] [rbp+10h]

  v2 = door;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)door, a2) )
  {
    if ( v2 )
      v3 = v2->m_pTransformNodeComponent;
    else
      v3 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v3);
    pHandle.m_pOneShot = 0i64;
    UFG::OneShotPool::GetOneShotHandle(&pHandle, &v3->mWorldTransform);
    if ( UFG::OneShotHandle::IsValid(&pHandle) )
    {
      UFG::TidoGame::HandleDoorType(v2, &pHandle);
      UFG::OneShot::Play(pHandle.m_pOneShot, play_door_close_0.mUID);
    }
    if ( UFG::DoorStateManager::sm_active && v2->m_Name.mUID == UFG::DoorStateManager::sm_doorName.mUID )
    {
      UFG::DoorStateManager::sm_open = 0;
      UFG::DoorStateManager::sm_inside = UFG::AudioTriggerRegion::sm_interiorTransitionCount > 0;
      UFG::DoorStateManager::sm_doorName.mUID = v2->m_Name.mUID;
      UFG::DoorStateManager::SetDoorMix();
    }
    UFG::OneShotHandle::Release(&pHandle);
  }
}

// File Line: 262
// RVA: 0x59E830
void UFG::DoorStateManager::HandleInOutTransition(void)
{
  bool v0; // al

  if ( UFG::DoorStateManager::sm_active )
  {
    v0 = UFG::AudioTriggerRegion::sm_interiorTransitionCount > 0;
    if ( UFG::DoorStateManager::sm_inside )
    {
      UFG::DoorStateManager::sm_inside = 0;
      if ( !v0 )
      {
LABEL_7:
        UFG::DoorStateManager::SetDoorMix();
        return;
      }
    }
    else if ( v0 )
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
  UFG::SimComponent *v0; // rax
  unsigned __int16 v1; // cx
  bool v2; // cl
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  UFG::DoorStateManager::sm_doorName.mUID = UFG::AudioTriggerRegion::CheckRegionForDoors(
                                              &result,
                                              &UFG::DoorStateManager::sm_doors)->mUID;
  v0 = (UFG::SimComponent *)UFG::Simulation::GetSimObject(&UFG::gSim, &UFG::DoorStateManager::sm_doorName);
  if ( v0 )
  {
    v1 = WORD2(v0[1].m_SafePointerList.mNode.mPrev);
    if ( (v1 >> 14) & 1 )
    {
      v0 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v0, UFG::DoorComponent::_TypeUID);
    }
    else if ( (v1 & 0x8000u) == 0 )
    {
      if ( (v1 >> 13) & 1 )
      {
        v0 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v0, UFG::DoorComponent::_TypeUID);
      }
      else if ( (v1 >> 12) & 1 )
      {
        v0 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v0, UFG::DoorComponent::_TypeUID);
      }
      else
      {
        v0 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v0, UFG::DoorComponent::_TypeUID);
      }
    }
    else
    {
      v0 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v0, UFG::DoorComponent::_TypeUID);
    }
  }
  v2 = 0;
  if ( v0 )
    v2 = UFG::DoorComponent::IsOpen((UFG::DoorComponent *)v0);
  if ( UFG::AudioTriggerRegion::sm_interiorTransitionCount <= 0
    || (UFG::DoorStateManager::sm_inside = 1, UFG::AudioTriggerRegion::sm_rainDrawOverride) )
  {
    UFG::DoorStateManager::sm_inside = 0;
  }
  UFG::DoorStateManager::sm_open = v2;
  UFG::DoorStateManager::sm_active = 1;
  UFG::DoorStateManager::SetDoorMix();
}

// File Line: 314
// RVA: 0x5A4000
void UFG::DoorStateManager::OnExitRegion(void)
{
  UFG::qWiseSymbol *v0; // rax
  UFG::qWiseSymbol *v1; // rax

  UFG::DoorStateManager::sm_active = 0;
  UFG::DoorStateManager::sm_doorName.mUID = UFG::gNullQSymbol.mUID;
  v0 = UFG::qWiseSymbol::get_null();
  UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_indoorState, v0);
  v1 = UFG::qWiseSymbol::get_null();
  UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_outdoorState, v1);
  UFG::DoorStateManager::sm_inside = UFG::AudioTriggerRegion::sm_interiorTransitionCount > 0;
  UFG::DoorStateManager::SetDoorMix();
}

// File Line: 328
// RVA: 0x5AABD0
void UFG::DoorStateManager::SetDoorMix(void)
{
  UFG::TiDoVtbl *v0; // rax

  if ( UFG::DoorStateManager::sm_open && UFG::DoorStateManager::sm_active )
  {
    v0 = UFG::TiDo::m_pInstance->vfptr;
    if ( UFG::DoorStateManager::sm_inside )
    {
      ((void (__fastcall *)(UFG::TiDo *, _QWORD, _QWORD))v0[1].CreateAudioEntityRegionData)(
        UFG::TiDo::m_pInstance,
        qws_MS_LOCATION.mUID,
        UFG::DoorStateManager::sm_indoorState.mUID);
      UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_doorMix, &UFG::DoorStateManager::sm_indoorState);
    }
    else
    {
      ((void (__fastcall *)(UFG::TiDo *, _QWORD, _QWORD))v0[1].CreateAudioEntityRegionData)(
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
  UFG::qVector3 *v2; // rdi
  UFG::qSymbol *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  UFG::qBaseNodeRB *v5; // rdx
  float v6; // xmm1_4
  float v7; // xmm2_4

  v2 = pos;
  v3 = name;
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
      LODWORD(v4[4].mNext) = (UFG::qSymbol)v3->mUID;
      v6 = v2->y;
      v7 = v2->z;
      HIDWORD(v4[4].mNext) = LODWORD(v2->x);
      *(float *)&v4[5].mNext = v6;
      *((float *)&v4[5].mNext + 1) = v7;
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
  return atexit(dynamic_atexit_destructor_for__UFG::AudioSurfaceTypeManager::sm_database__);
}

// File Line: 475
// RVA: 0x5A2120
void __fastcall UFG::AudioSurfaceTypeManager::LoadSurfaceBankInfo(const char *filename)
{
  const char *v1; // rdi
  Render::SkinningCacheNode *v2; // rax
  Illusion::Buffer **v3; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rdx
  SimpleXML::XMLDocument *v5; // rax
  SimpleXML::XMLDocument *v6; // r15
  SimpleXML::XMLNode *v7; // rax
  SimpleXML::XMLNode *v8; // r12
  char *v9; // rax
  UFG::qBaseTreeRB *v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rdi
  unsigned int v13; // ebx
  UFG::qBaseNodeRB *v14; // rdx
  SimpleXML::XMLNode *v15; // rbp
  char *v16; // rax
  char *v17; // rax
  UFG::qBaseTreeRB *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::allocator::free_link *v20; // rbx
  unsigned int v21; // esi
  UFG::qWiseSymbol *v22; // rax
  SimpleXML::XMLNode *i; // [rsp+30h] [rbp-58h]
  UFG::qSymbol v24; // [rsp+98h] [rbp+10h]
  UFG::qSymbol result; // [rsp+A0h] [rbp+18h]
  UFG::qWiseSymbol source; // [rsp+A8h] [rbp+20h]

  v1 = filename;
  if ( UFG::AudioSurfaceTypeManager::sm_database.mTree.mCount )
  {
    while ( 1 )
    {
      v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioSurfaceTypeManager::sm_database);
      if ( !v2 )
        break;
      v3 = &v2[-1].mCachedBufferPtr;
      if ( v2 == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      v4 = &v2->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::AudioSurfaceTypeManager::sm_database,
        v4);
      if ( v3 )
        ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v3)->mNode.mParent)(v3, 1i64);
      if ( !UFG::AudioSurfaceTypeManager::sm_database.mTree.mCount )
        goto LABEL_10;
    }
    v3 = 0i64;
LABEL_6:
    v4 = 0i64;
    goto LABEL_7;
  }
LABEL_10:
  v5 = SimpleXML::XMLDocument::Open(v1, 1ui64, 0i64);
  v6 = v5;
  v7 = SimpleXML::XMLDocument::GetNode(v5, "SurfaceBankMap", 0i64);
  v8 = SimpleXML::XMLDocument::GetChildNode(v6, "Surface", v7);
  for ( i = v8; v8; i = v8 )
  {
    v9 = SimpleXML::XMLNode::GetAttribute(v8, "name", 0i64);
    UFG::qSymbol::create_from_string(&result, v9);
    if ( !result.mUID
      || (v10 = UFG::qBaseTreeRB::Get(&UFG::AudioSurfaceTypeManager::sm_database.mTree, result.mUID)) == 0i64
      || v10 == (UFG::qBaseTreeRB *)8 )
    {
      v11 = UFG::qMemoryPool::Allocate(&g_AudioMemoryPool, 0x70ui64, "SurfaceBankNode", 0i64, 1u);
      v12 = v11;
      if ( v11 )
      {
        v13 = result.mUID;
        v11[1].mNext = 0i64;
        v11[2].mNext = 0i64;
        v11[3].mNext = 0i64;
        v11->mNext = (UFG::allocator::free_link *)&UFG::SurfaceBankNode::`vftable';
        UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&v11[5]);
        LODWORD(v12[4].mNext) = v13;
      }
      else
      {
        v12 = 0i64;
      }
      v14 = (UFG::qBaseNodeRB *)&v12[1];
      if ( !v12 )
        v14 = 0i64;
      UFG::qBaseTreeRB::Add(&UFG::AudioSurfaceTypeManager::sm_database.mTree, v14);
      v15 = SimpleXML::XMLDocument::GetChildNode(v6, "Bank", v8);
      if ( v15 )
      {
        do
        {
          v16 = SimpleXML::XMLNode::GetAttribute(v15, "footwear", &customWorldMapCaption);
          UFG::qSymbol::create_from_string(&v24, v16);
          v17 = SimpleXML::XMLNode::GetAttribute(v15, "bankId", &customWorldMapCaption);
          UFG::qWiseSymbol::create_from_string(&source, v17);
          if ( !v24.mUID
            || (v18 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&v12[5], v24.mUID)) == 0i64
            || v18 == (UFG::qBaseTreeRB *)8 )
          {
            v19 = UFG::qMemoryPool::Allocate(&g_AudioMemoryPool, 0x30ui64, "BankNode", 0i64, 1u);
            v20 = v19;
            if ( v19 )
            {
              v21 = v24.mUID;
              v19[1].mNext = 0i64;
              v19[2].mNext = 0i64;
              v19[3].mNext = 0i64;
              v19->mNext = (UFG::allocator::free_link *)&UFG::BankNode::`vftable';
              LODWORD(v19[5].mNext) = -1;
              _((AMD_HD3D *)0xFFFFFFFFi64);
              HIDWORD(v20[5].mNext) = -1;
              LODWORD(v20[4].mNext) = v21;
              v22 = UFG::qWiseSymbol::get_null();
              UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)&v20[5], v22);
              HIDWORD(v20[5].mNext) = UFG::gNullQSymbol;
            }
            else
            {
              v20 = 0i64;
            }
            HIDWORD(v20[5].mNext) = v24;
            UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)&v20[5], &source);
            UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)&v12[5], (UFG::qBaseNodeRB *)&v20[1]);
          }
          _((AMD_HD3D *)source.mUID);
          v15 = SimpleXML::XMLDocument::GetNode(v6, "Bank", v15);
        }
        while ( v15 );
        v8 = i;
      }
    }
    v8 = SimpleXML::XMLDocument::GetNode(v6, "Surface", v8);
  }
}

// File Line: 531
// RVA: 0x59D580
UFG::qWiseSymbol *__fastcall UFG::AudioSurfaceTypeManager::GetSurfaceBankId(UFG::qWiseSymbol *result, unsigned int surfaceId, unsigned int footwear)
{
  unsigned int v3; // esi
  unsigned int v4; // ebp
  UFG::qWiseSymbol *v5; // rdi
  signed __int64 v6; // rbx
  unsigned int v7; // edx
  UFG::qBaseTreeRB *v8; // rax
  signed __int64 v9; // rbp
  UFG::qBaseTreeRB *v10; // rax
  signed __int64 v11; // rax
  AMD_HD3D *v12; // rcx
  unsigned int v13; // edx
  UFG::qBaseTreeRB *v14; // rcx
  UFG::qBaseTreeRB *v15; // rax
  signed __int64 v16; // rcx
  UFG::qBaseTreeRB *v17; // rax
  AMD_HD3D *v18; // rcx

  v3 = footwear;
  v4 = surfaceId;
  v5 = result;
  v6 = 0i64;
  if ( !(_S38_1 & 1) )
  {
    _S38_1 |= 1u;
    UFG::qSymbol::create_from_string(&qSymbol_default, "default");
    atexit(UFG::AudioSurfaceTypeManager::GetSurfaceBankId_::_2_::_dynamic_atexit_destructor_for__qSymbol_default__);
  }
  v7 = qSymbol_default.mUID;
  if ( !v3 )
    v3 = qSymbol_default.mUID;
  if ( !v4 )
    goto LABEL_15;
  v8 = UFG::qBaseTreeRB::Get(&UFG::AudioSurfaceTypeManager::sm_database.mTree, v4);
  if ( !v8 || (v9 = (signed __int64)&v8[-1].mCount, v8 == (UFG::qBaseTreeRB *)8) )
  {
    v7 = qSymbol_default.mUID;
LABEL_15:
    if ( !v7 )
      goto LABEL_22;
    v15 = UFG::qBaseTreeRB::Get(&UFG::AudioSurfaceTypeManager::sm_database.mTree, v7);
    v16 = (signed __int64)&v15[-1].mCount;
    if ( !v15 )
      v16 = 0i64;
    v13 = qSymbol_default.mUID;
    if ( !qSymbol_default.mUID )
      goto LABEL_22;
    v14 = (UFG::qBaseTreeRB *)(v16 + 40);
    goto LABEL_20;
  }
  if ( !v3
    || (v10 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)(v9 + 40), v3)) == 0i64
    || (v11 = (signed __int64)&v10[-1].mCount) == 0 )
  {
    v13 = qSymbol_default.mUID;
    if ( !qSymbol_default.mUID )
    {
LABEL_22:
      v18 = (AMD_HD3D *)*(unsigned int *)(v6 + 40);
      v5->mUID = (unsigned int)v18;
      _(v18);
      return v5;
    }
    v14 = (UFG::qBaseTreeRB *)(v9 + 40);
LABEL_20:
    v17 = UFG::qBaseTreeRB::Get(v14, v13);
    if ( v17 )
      v6 = (signed __int64)&v17[-1].mCount;
    goto LABEL_22;
  }
  v12 = (AMD_HD3D *)*(unsigned int *)(v11 + 40);
  v5->mUID = (unsigned int)v12;
  _(v12);
  return v5;
}

