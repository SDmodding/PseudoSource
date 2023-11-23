// File Line: 23
// RVA: 0xBD4CB0
void __fastcall hkaiCharacter::BehaviorListener::UserEdgeEntry::calcEntryPointWorld(
        hkaiCharacter::BehaviorListener::UserEdgeEntry *this,
        hkVector4f *entryPointWorldOut)
{
  hkVector4f::setTransformedPos(
    entryPointWorldOut,
    &this->m_world->m_streamingCollection.m_pntr->m_instances.m_data[this->m_entrySection].m_instancePtr->m_referenceFrame.m_transform,
    &this->m_entryPoint);
}

// File Line: 32
// RVA: 0xBD4CF0
void __fastcall hkaiCharacter::BehaviorListener::UserEdgeEntry::calcExitPointLocal(
        hkaiCharacter::BehaviorListener::UserEdgeEntry *this,
        hkVector4f *exitPointLocalOut)
{
  hkVector4f v4; // xmm1
  hkSimdFloat32 v5; // [rsp+20h] [rbp-58h] BYREF
  hkMatrix4f v6; // [rsp+30h] [rbp-48h] BYREF
  hkResult v7; // [rsp+80h] [rbp+8h] BYREF

  v7.m_enum = LODWORD(FLOAT_0_001);
  v5.m_real = _mm_shuffle_ps((__m128)(unsigned int)v7.m_enum, (__m128)(unsigned int)v7.m_enum, 0);
  __hkMatrix4UtilAlgo::setInverse(&v7, &this->m_edgeTransform, &v6, &v5);
  v4.m_quad = (__m128)this->m_entryPoint;
  exitPointLocalOut->m_quad = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 0), v6.m_col0.m_quad),
                                    v6.m_col3.m_quad),
                                  _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 85), v6.m_col1.m_quad)),
                                _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 170), v6.m_col2.m_quad));
}

// File Line: 40
// RVA: 0xBD4D80
void __fastcall hkaiCharacter::BehaviorListener::UserEdgeEntry::calcExitPointWorld(
        hkaiCharacter::BehaviorListener::UserEdgeEntry *this,
        hkVector4f *exitPointWorldOut)
{
  hkVector4f exitPointLocalOut; // [rsp+20h] [rbp-18h] BYREF

  hkaiCharacter::BehaviorListener::UserEdgeEntry::calcExitPointLocal(this, &exitPointLocalOut);
  hkVector4f::setTransformedPos(
    exitPointWorldOut,
    &this->m_world->m_streamingCollection.m_pntr->m_instances.m_data[this->m_oppositeSection].m_instancePtr->m_referenceFrame.m_transform,
    &exitPointLocalOut);
}

// File Line: 52
// RVA: 0xBD4DE0
void __fastcall hkaiCharacter::BehaviorListener::UserEdgeEntry::calcEntryEdgeDirectionWorld(
        hkaiCharacter::BehaviorListener::UserEdgeEntry *this,
        hkVector4f *entryEdgeDirectionWorldOut)
{
  hkVector4f::setRotatedDir(
    entryEdgeDirectionWorldOut,
    &this->m_world->m_streamingCollection.m_pntr->m_instances.m_data[this->m_entrySection].m_instancePtr->m_referenceFrame.m_transform.m_rotation,
    &this->m_entryEdgeDirection);
}

// File Line: 63
// RVA: 0xBD4E20
void __fastcall hkaiCharacter::BehaviorListener::UserEdgeEntry::calcExitEdgeDirectionLocal(
        hkaiCharacter::BehaviorListener::UserEdgeEntry *this,
        hkVector4f *exitEdgeDirectionLocalOut)
{
  hkSimdFloat32 v4; // [rsp+20h] [rbp-58h] BYREF
  hkMatrix4f v5; // [rsp+30h] [rbp-48h] BYREF
  hkResult v6; // [rsp+80h] [rbp+8h] BYREF

  v6.m_enum = LODWORD(FLOAT_0_001);
  v4.m_real = _mm_shuffle_ps((__m128)(unsigned int)v6.m_enum, (__m128)(unsigned int)v6.m_enum, 0);
  __hkMatrix4UtilAlgo::setInverse(&v6, &this->m_edgeTransform, &v5, &v4);
  exitEdgeDirectionLocalOut->m_quad = _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(
                                              this->m_entryEdgeDirection.m_quad,
                                              this->m_entryEdgeDirection.m_quad,
                                              85),
                                            v5.m_col1.m_quad),
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(
                                              this->m_entryEdgeDirection.m_quad,
                                              this->m_entryEdgeDirection.m_quad,
                                              0),
                                            v5.m_col0.m_quad)),
                                        _mm_mul_ps(
                                          _mm_shuffle_ps(
                                            this->m_entryEdgeDirection.m_quad,
                                            this->m_entryEdgeDirection.m_quad,
                                            170),
                                          v5.m_col2.m_quad));
}

// File Line: 74
// RVA: 0xBD4EB0
void __fastcall hkaiCharacter::BehaviorListener::UserEdgeEntry::calcExitEdgeDirectionWorld(
        hkaiCharacter::BehaviorListener::UserEdgeEntry *this,
        hkVector4f *exitEdgeDirectionWorldOut)
{
  hkVector4f exitEdgeDirectionLocalOut; // [rsp+20h] [rbp-18h] BYREF

  hkaiCharacter::BehaviorListener::UserEdgeEntry::calcExitEdgeDirectionLocal(this, &exitEdgeDirectionLocalOut);
  hkVector4f::setRotatedDir(
    exitEdgeDirectionWorldOut,
    &this->m_world->m_streamingCollection.m_pntr->m_instances.m_data[this->m_oppositeSection].m_instancePtr->m_referenceFrame.m_transform.m_rotation,
    &exitEdgeDirectionLocalOut);
}

// File Line: 95
// RVA: 0xBD4F10
void __fastcall hkaiCharacter::Cinfo::Cinfo(hkaiCharacter::Cinfo *this)
{
  this->m_initialPosition = (hkVector4f)aabbOut.m_quad;
  this->m_initialForward = (hkVector4f)aabbOut.m_quad;
  this->m_avoidanceProperties = 0i64;
  this->m_userData = 0i64;
  this->m_desiredSpeed = -1.0;
  this->m_up = (hkVector4f)aabbOut.m_quad;
  this->m_radius = -1.0;
}

// File Line: 116
// RVA: 0xBD4F60
void __fastcall hkaiCharacter::hkaiCharacter(hkaiCharacter *this, hkaiCharacter::Cinfo *cinfo)
{
  hkaiAvoidanceProperties *m_avoidanceProperties; // rsi

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiCharacter::`vftable;
  this->m_userData = cinfo->m_userData;
  this->m_position = cinfo->m_initialPosition;
  this->m_forward = cinfo->m_initialForward;
  this->m_currentNavMeshFace = -1;
  this->m_velocity = (hkVector4f)aabbOut.m_quad;
  this->m_radius = cinfo->m_radius;
  this->m_desiredSpeed = cinfo->m_desiredSpeed;
  this->m_costModifier.m_pntr = 0i64;
  this->m_edgeFilter.m_pntr = 0i64;
  this->m_hitFilter.m_pntr = 0i64;
  this->m_adaptiveRanger.m_curRange = 1.0;
  this->m_steeringFilter.m_pntr = 0i64;
  this->m_agentFilterInfo = 0;
  m_avoidanceProperties = cinfo->m_avoidanceProperties;
  if ( m_avoidanceProperties )
    hkReferencedObject::addReference(cinfo->m_avoidanceProperties);
  this->m_avoidanceProperties.m_pntr = m_avoidanceProperties;
  this->m_avoidanceState = 0.0;
  this->m_agentPriority = 1;
  this->m_avoidanceType = 1;
  this->m_avoidanceEnabledMask.m_storage = 7;
  this->m_state.m_storage = 3;
  this->m_behaviorListeners.m_data = 0i64;
  this->m_behaviorListeners.m_size = 0;
  this->m_behaviorListeners.m_capacityAndFlags = 0x80000000;
  this->m_up = cinfo->m_up;
}

// File Line: 181
// RVA: 0xBD5080
void __fastcall hkaiCharacter::hkaiCharacter(hkaiCharacter *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiCharacter::`vftable;
  this->m_hitFilter.m_pntr = 0i64;
  this->m_steeringFilter.m_pntr = 0i64;
  this->m_behaviorListeners.m_data = 0i64;
  this->m_behaviorListeners.m_size = 0;
  this->m_behaviorListeners.m_capacityAndFlags = 0x80000000;
}

// File Line: 205
// RVA: 0xBD50C0
void __fastcall hkaiCharacter::hkaiCharacter(hkaiCharacter *this, hkaiCharacter *other)
{
  hkaiAstarCostModifier *m_pntr; // rcx
  hkaiSpatialQueryHitFilter *v5; // rcx
  hkaiLocalSteeringFilter *v6; // rcx
  hkaiAvoidanceProperties *v7; // rcx
  int m_size; // eax
  __int64 v9; // rax
  hkaiCharacter::BehaviorListener **m_data; // rcx
  __int64 v11; // rdx
  char *v12; // r8
  hkaiCharacter::BehaviorListener *v13; // rax
  int v14; // [rsp+30h] [rbp+8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiCharacter::`vftable;
  this->m_userData = other->m_userData;
  this->m_position = other->m_position;
  this->m_forward = other->m_forward;
  this->m_velocity = other->m_velocity;
  this->m_up = other->m_up;
  this->m_currentNavMeshFace = other->m_currentNavMeshFace;
  this->m_radius = other->m_radius;
  this->m_desiredSpeed = other->m_desiredSpeed;
  this->m_adaptiveRanger.m_curRange = other->m_adaptiveRanger.m_curRange;
  m_pntr = other->m_costModifier.m_pntr;
  if ( m_pntr )
    hkReferencedObject::addReference(m_pntr);
  this->m_costModifier.m_pntr = other->m_costModifier.m_pntr;
  this->m_edgeFilter.m_pntr = 0i64;
  v5 = other->m_hitFilter.m_pntr;
  if ( v5 )
    hkReferencedObject::addReference(v5);
  this->m_hitFilter.m_pntr = other->m_hitFilter.m_pntr;
  v6 = other->m_steeringFilter.m_pntr;
  if ( v6 )
    hkReferencedObject::addReference(v6);
  this->m_steeringFilter.m_pntr = other->m_steeringFilter.m_pntr;
  this->m_agentFilterInfo = other->m_agentFilterInfo;
  v7 = other->m_avoidanceProperties.m_pntr;
  if ( v7 )
    hkReferencedObject::addReference(v7);
  this->m_avoidanceProperties.m_pntr = other->m_avoidanceProperties.m_pntr;
  this->m_avoidanceState = other->m_avoidanceState;
  this->m_agentPriority = other->m_agentPriority;
  this->m_avoidanceType = other->m_avoidanceType;
  this->m_avoidanceEnabledMask.m_storage = other->m_avoidanceEnabledMask.m_storage;
  this->m_state.m_storage = other->m_state.m_storage;
  this->m_behaviorListeners.m_data = 0i64;
  this->m_behaviorListeners.m_size = 0;
  this->m_behaviorListeners.m_capacityAndFlags = 0x80000000;
  m_size = other->m_behaviorListeners.m_size;
  if ( m_size > 0 )
  {
    v14 = 8 * m_size;
    this->m_behaviorListeners.m_data = (hkaiCharacter::BehaviorListener **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                                             &hkContainerHeapAllocator::s_alloc,
                                                                             &v14);
    this->m_behaviorListeners.m_capacityAndFlags = v14 / 8;
  }
  v9 = other->m_behaviorListeners.m_size;
  m_data = this->m_behaviorListeners.m_data;
  this->m_behaviorListeners.m_size = v9;
  v11 = v9;
  if ( (int)v9 > 0 )
  {
    v12 = (char *)((char *)other->m_behaviorListeners.m_data - (char *)m_data);
    do
    {
      v13 = *(hkaiCharacter::BehaviorListener **)((char *)m_data++ + (_QWORD)v12);
      *(m_data - 1) = v13;
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 211
// RVA: 0xBD52A0
void __fastcall hkaiCharacter::~hkaiCharacter(hkaiCharacter *this)
{
  int m_capacityAndFlags; // r8d
  hkaiAvoidanceProperties *m_pntr; // rcx
  hkaiLocalSteeringFilter *v4; // rcx
  hkaiSpatialQueryHitFilter *v5; // rcx
  hkaiAstarEdgeFilter *v6; // rcx
  hkaiAstarCostModifier *v7; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiCharacter::`vftable;
  m_capacityAndFlags = this->m_behaviorListeners.m_capacityAndFlags;
  this->m_behaviorListeners.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_behaviorListeners.m_data,
      8 * m_capacityAndFlags);
  this->m_behaviorListeners.m_data = 0i64;
  this->m_behaviorListeners.m_capacityAndFlags = 0x80000000;
  m_pntr = this->m_avoidanceProperties.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_avoidanceProperties.m_pntr = 0i64;
  v4 = this->m_steeringFilter.m_pntr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  this->m_steeringFilter.m_pntr = 0i64;
  v5 = this->m_hitFilter.m_pntr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  this->m_hitFilter.m_pntr = 0i64;
  v6 = this->m_edgeFilter.m_pntr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  this->m_edgeFilter.m_pntr = 0i64;
  v7 = this->m_costModifier.m_pntr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  this->m_costModifier.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 215
// RVA: 0xBD5500
void __fastcall hkaiCharacter::setAvoidanceState(hkaiCharacter *this, hkResult state)
{
  this->m_avoidanceState = (float)((float)(state.m_enum == HK_FAILURE) * 0.10000002)
                         + (float)(this->m_avoidanceState * 0.89999998);
}

// File Line: 221
// RVA: 0xBD5540
void __fastcall hkaiCharacter::checkDeterminism(hkaiCharacter *this)
{
  ;
}

// File Line: 242
// RVA: 0xBD53E0
void __fastcall hkaiCharacter::setCostModifier(hkaiCharacter *this, hkaiAstarCostModifier *mod)
{
  hkaiAstarCostModifier *m_pntr; // rcx

  if ( mod )
    hkReferencedObject::addReference(mod);
  m_pntr = this->m_costModifier.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_costModifier.m_pntr = mod;
}

// File Line: 247
// RVA: 0xBD5420
void __fastcall hkaiCharacter::setEdgeFilter(hkaiCharacter *this, hkaiAstarEdgeFilter *f)
{
  hkaiAstarEdgeFilter *m_pntr; // rcx

  if ( f )
    hkReferencedObject::addReference(f);
  m_pntr = this->m_edgeFilter.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_edgeFilter.m_pntr = f;
}

// File Line: 253
// RVA: 0xBD54B0
void __fastcall hkaiCharacter::setSteeringFilter(hkaiCharacter *this, hkaiLocalSteeringFilter *steeringFilter)
{
  hkaiLocalSteeringFilter *m_pntr; // rcx

  if ( steeringFilter )
    hkReferencedObject::addReference(steeringFilter);
  m_pntr = this->m_steeringFilter.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_steeringFilter.m_pntr = steeringFilter;
}

// File Line: 258
// RVA: 0xBD5460
void __fastcall hkaiCharacter::setQueryHitFilter(hkaiCharacter *this, hkaiSpatialQueryHitFilter *hitFilter)
{
  hkaiSpatialQueryHitFilter *m_pntr; // rcx

  if ( hitFilter )
    hkReferencedObject::addReference(hitFilter);
  m_pntr = this->m_hitFilter.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_hitFilter.m_pntr = hitFilter;
}

// File Line: 263
// RVA: 0xBD5390
void __fastcall hkaiCharacter::setAvoidanceProperties(hkaiCharacter *this, hkaiAvoidanceProperties *props)
{
  hkaiAvoidanceProperties *m_pntr; // rcx

  if ( props )
    hkReferencedObject::addReference(props);
  m_pntr = this->m_avoidanceProperties.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_avoidanceProperties.m_pntr = props;
}

// File Line: 268
// RVA: 0xBD5550
float __fastcall hkaiCharacter::getAngularVelocity(hkaiCharacter *this)
{
  return this->m_velocity.m_quad.m128_f32[3];
}

