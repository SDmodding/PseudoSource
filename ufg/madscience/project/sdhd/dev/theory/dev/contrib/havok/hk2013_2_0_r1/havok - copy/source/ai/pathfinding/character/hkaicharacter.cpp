// File Line: 23
// RVA: 0xBD4CB0
void __fastcall hkaiCharacter::BehaviorListener::UserEdgeEntry::calcEntryPointWorld(hkaiCharacter::BehaviorListener::UserEdgeEntry *this, hkVector4f *entryPointWorldOut)
{
  hkVector4f::setTransformedPos(
    entryPointWorldOut,
    &this->m_world->m_streamingCollection.m_pntr->m_instances.m_data[this->m_entrySection].m_instancePtr->m_referenceFrame.m_transform,
    &this->m_entryPoint);
}

// File Line: 32
// RVA: 0xBD4CF0
void __fastcall hkaiCharacter::BehaviorListener::UserEdgeEntry::calcExitPointLocal(hkaiCharacter::BehaviorListener::UserEdgeEntry *this, hkVector4f *exitPointLocalOut)
{
  hkVector4f *v2; // rdi
  hkaiCharacter::BehaviorListener::UserEdgeEntry *v3; // rbx
  __m128 v4; // xmm1
  __m128 v5; // [rsp+20h] [rbp-58h]
  __m128 v6; // [rsp+30h] [rbp-48h]
  __m128 v7; // [rsp+40h] [rbp-38h]
  __m128 v8; // [rsp+50h] [rbp-28h]
  __m128 v9; // [rsp+60h] [rbp-18h]
  unsigned int v10; // [rsp+80h] [rbp+8h]

  v2 = exitPointLocalOut;
  v3 = this;
  v10 = LODWORD(FLOAT_0_001);
  v5 = _mm_shuffle_ps((__m128)v10, (__m128)v10, 0);
  __hkMatrix4UtilAlgo::setInverse((hkResult *)&v10, &this->m_edgeTransform, (hkMatrix4f *)&v6, (hkSimdFloat32 *)&v5);
  v4 = v3->m_entryPoint.m_quad;
  v2->m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), v6), v9),
                   _mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), v7)),
                 _mm_mul_ps(_mm_shuffle_ps(v4, v4, 170), v8));
}

// File Line: 40
// RVA: 0xBD4D80
void __fastcall hkaiCharacter::BehaviorListener::UserEdgeEntry::calcExitPointWorld(hkaiCharacter::BehaviorListener::UserEdgeEntry *this, hkVector4f *exitPointWorldOut)
{
  hkVector4f *v2; // rdi
  hkaiCharacter::BehaviorListener::UserEdgeEntry *v3; // rbx
  hkVector4f exitPointLocalOut; // [rsp+20h] [rbp-18h]

  v2 = exitPointWorldOut;
  v3 = this;
  hkaiCharacter::BehaviorListener::UserEdgeEntry::calcExitPointLocal(this, &exitPointLocalOut);
  hkVector4f::setTransformedPos(
    v2,
    &v3->m_world->m_streamingCollection.m_pntr->m_instances.m_data[v3->m_oppositeSection].m_instancePtr->m_referenceFrame.m_transform,
    &exitPointLocalOut);
}

// File Line: 52
// RVA: 0xBD4DE0
void __fastcall hkaiCharacter::BehaviorListener::UserEdgeEntry::calcEntryEdgeDirectionWorld(hkaiCharacter::BehaviorListener::UserEdgeEntry *this, hkVector4f *entryEdgeDirectionWorldOut)
{
  hkVector4f::setRotatedDir(
    entryEdgeDirectionWorldOut,
    (hkMatrix3f *)&this->m_world->m_streamingCollection.m_pntr->m_instances.m_data[this->m_entrySection].m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col0,
    &this->m_entryEdgeDirection);
}

// File Line: 63
// RVA: 0xBD4E20
void __fastcall hkaiCharacter::BehaviorListener::UserEdgeEntry::calcExitEdgeDirectionLocal(hkaiCharacter::BehaviorListener::UserEdgeEntry *this, hkVector4f *exitEdgeDirectionLocalOut)
{
  hkVector4f *v2; // rdi
  hkaiCharacter::BehaviorListener::UserEdgeEntry *v3; // rbx
  __m128 v4; // [rsp+20h] [rbp-58h]
  __m128 v5; // [rsp+30h] [rbp-48h]
  __m128 v6; // [rsp+40h] [rbp-38h]
  __m128 v7; // [rsp+50h] [rbp-28h]
  unsigned int v8; // [rsp+80h] [rbp+8h]

  v2 = exitEdgeDirectionLocalOut;
  v3 = this;
  v8 = LODWORD(FLOAT_0_001);
  v4 = _mm_shuffle_ps((__m128)v8, (__m128)v8, 0);
  __hkMatrix4UtilAlgo::setInverse((hkResult *)&v8, &this->m_edgeTransform, (hkMatrix4f *)&v5, (hkSimdFloat32 *)&v4);
  v2->m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v3->m_entryEdgeDirection.m_quad, v3->m_entryEdgeDirection.m_quad, 85), v6),
                   _mm_mul_ps(_mm_shuffle_ps(v3->m_entryEdgeDirection.m_quad, v3->m_entryEdgeDirection.m_quad, 0), v5)),
                 _mm_mul_ps(_mm_shuffle_ps(v3->m_entryEdgeDirection.m_quad, v3->m_entryEdgeDirection.m_quad, 170), v7));
}

// File Line: 74
// RVA: 0xBD4EB0
void __fastcall hkaiCharacter::BehaviorListener::UserEdgeEntry::calcExitEdgeDirectionWorld(hkaiCharacter::BehaviorListener::UserEdgeEntry *this, hkVector4f *exitEdgeDirectionWorldOut)
{
  hkVector4f *v2; // rdi
  hkaiCharacter::BehaviorListener::UserEdgeEntry *v3; // rbx
  hkVector4f exitEdgeDirectionLocalOut; // [rsp+20h] [rbp-18h]

  v2 = exitEdgeDirectionWorldOut;
  v3 = this;
  hkaiCharacter::BehaviorListener::UserEdgeEntry::calcExitEdgeDirectionLocal(this, &exitEdgeDirectionLocalOut);
  hkVector4f::setRotatedDir(
    v2,
    (hkMatrix3f *)&v3->m_world->m_streamingCollection.m_pntr->m_instances.m_data[v3->m_oppositeSection].m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col0,
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
  hkaiCharacter::Cinfo *v2; // rdi
  hkaiCharacter *v3; // rbx
  hkaiAvoidanceProperties *v4; // rsi

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiCharacter::`vftable;
  v2 = cinfo;
  this->m_userData = cinfo->m_userData;
  v3 = this;
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
  v4 = cinfo->m_avoidanceProperties;
  if ( v4 )
    hkReferencedObject::addReference((hkReferencedObject *)&cinfo->m_avoidanceProperties->vfptr);
  v3->m_avoidanceProperties.m_pntr = v4;
  v3->m_avoidanceState = 0.0;
  v3->m_agentPriority = 1;
  v3->m_avoidanceType = 1;
  v3->m_avoidanceEnabledMask.m_storage = 7;
  v3->m_state.m_storage = 3;
  v3->m_behaviorListeners.m_data = 0i64;
  v3->m_behaviorListeners.m_size = 0;
  v3->m_behaviorListeners.m_capacityAndFlags = 2147483648;
  v3->m_up = v2->m_up;
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
  this->m_behaviorListeners.m_capacityAndFlags = 2147483648;
}

// File Line: 205
// RVA: 0xBD50C0
void __fastcall hkaiCharacter::hkaiCharacter(hkaiCharacter *this, hkaiCharacter *other)
{
  hkaiCharacter *v2; // rbx
  hkaiCharacter *v3; // rdi
  hkaiAstarCostModifier *v4; // rcx
  hkReferencedObject *v5; // rcx
  hkReferencedObject *v6; // rcx
  hkReferencedObject *v7; // rcx
  int v8; // eax
  __int64 v9; // rax
  hkaiCharacter::BehaviorListener **v10; // rcx
  __int64 v11; // rdx
  char *v12; // r8
  hkaiCharacter::BehaviorListener *v13; // rax
  int v14; // [rsp+30h] [rbp+8h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiCharacter::`vftable;
  v3 = other;
  this->m_userData = other->m_userData;
  this->m_position = other->m_position;
  this->m_forward = other->m_forward;
  this->m_velocity = other->m_velocity;
  this->m_up = other->m_up;
  this->m_currentNavMeshFace = other->m_currentNavMeshFace;
  this->m_radius = other->m_radius;
  this->m_desiredSpeed = other->m_desiredSpeed;
  this->m_adaptiveRanger.m_curRange = other->m_adaptiveRanger.m_curRange;
  v4 = other->m_costModifier.m_pntr;
  if ( v4 )
    hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  v2->m_costModifier.m_pntr = v3->m_costModifier.m_pntr;
  v2->m_edgeFilter.m_pntr = 0i64;
  v5 = (hkReferencedObject *)&v3->m_hitFilter.m_pntr->vfptr;
  if ( v5 )
    hkReferencedObject::addReference(v5);
  v2->m_hitFilter.m_pntr = v3->m_hitFilter.m_pntr;
  v6 = (hkReferencedObject *)&v3->m_steeringFilter.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::addReference(v6);
  v2->m_steeringFilter.m_pntr = v3->m_steeringFilter.m_pntr;
  v2->m_agentFilterInfo = v3->m_agentFilterInfo;
  v7 = (hkReferencedObject *)&v3->m_avoidanceProperties.m_pntr->vfptr;
  if ( v7 )
    hkReferencedObject::addReference(v7);
  v2->m_avoidanceProperties.m_pntr = v3->m_avoidanceProperties.m_pntr;
  v2->m_avoidanceState = v3->m_avoidanceState;
  v2->m_agentPriority = v3->m_agentPriority;
  v2->m_avoidanceType = v3->m_avoidanceType;
  v2->m_avoidanceEnabledMask.m_storage = v3->m_avoidanceEnabledMask.m_storage;
  v2->m_state.m_storage = v3->m_state.m_storage;
  v2->m_behaviorListeners.m_data = 0i64;
  v2->m_behaviorListeners.m_size = 0;
  v2->m_behaviorListeners.m_capacityAndFlags = 2147483648;
  v8 = v3->m_behaviorListeners.m_size;
  if ( v8 > 0 )
  {
    v14 = 8 * v8;
    v2->m_behaviorListeners.m_data = (hkaiCharacter::BehaviorListener **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                                           (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                                           &v14);
    v2->m_behaviorListeners.m_capacityAndFlags = v14 / 8;
  }
  v9 = v3->m_behaviorListeners.m_size;
  v10 = v2->m_behaviorListeners.m_data;
  v2->m_behaviorListeners.m_size = v9;
  v11 = v9;
  if ( (signed int)v9 > 0 )
  {
    v12 = (char *)((char *)v3->m_behaviorListeners.m_data - (char *)v10);
    do
    {
      v13 = *(hkaiCharacter::BehaviorListener **)((char *)v10 + (_QWORD)v12);
      ++v10;
      *(v10 - 1) = v13;
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 211
// RVA: 0xBD52A0
void __fastcall hkaiCharacter::~hkaiCharacter(hkaiCharacter *this)
{
  hkaiCharacter *v1; // rbx
  int v2; // er8
  hkReferencedObject *v3; // rcx
  hkReferencedObject *v4; // rcx
  hkReferencedObject *v5; // rcx
  hkReferencedObject *v6; // rcx
  hkReferencedObject *v7; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiCharacter::`vftable;
  v2 = this->m_behaviorListeners.m_capacityAndFlags;
  this->m_behaviorListeners.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_behaviorListeners.m_data,
      8 * v2);
  v1->m_behaviorListeners.m_data = 0i64;
  v1->m_behaviorListeners.m_capacityAndFlags = 2147483648;
  v3 = (hkReferencedObject *)&v1->m_avoidanceProperties.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_avoidanceProperties.m_pntr = 0i64;
  v4 = (hkReferencedObject *)&v1->m_steeringFilter.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v1->m_steeringFilter.m_pntr = 0i64;
  v5 = (hkReferencedObject *)&v1->m_hitFilter.m_pntr->vfptr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v1->m_hitFilter.m_pntr = 0i64;
  v6 = (hkReferencedObject *)&v1->m_edgeFilter.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v1->m_edgeFilter.m_pntr = 0i64;
  v7 = (hkReferencedObject *)&v1->m_costModifier.m_pntr->vfptr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v1->m_costModifier.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 215
// RVA: 0xBD5500
void __fastcall hkaiCharacter::setAvoidanceState(hkaiCharacter *this, hkResult state)
{
  this->m_avoidanceState = (float)((float)(state.m_enum == 1) * 0.10000002)
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
  hkaiAstarCostModifier *v2; // rbx
  hkaiCharacter *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = mod;
  v3 = this;
  if ( mod )
    hkReferencedObject::addReference((hkReferencedObject *)&mod->vfptr);
  v4 = (hkReferencedObject *)&v3->m_costModifier.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_costModifier.m_pntr = v2;
}

// File Line: 247
// RVA: 0xBD5420
void __fastcall hkaiCharacter::setEdgeFilter(hkaiCharacter *this, hkaiAstarEdgeFilter *f)
{
  hkaiAstarEdgeFilter *v2; // rbx
  hkaiCharacter *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = f;
  v3 = this;
  if ( f )
    hkReferencedObject::addReference((hkReferencedObject *)&f->vfptr);
  v4 = (hkReferencedObject *)&v3->m_edgeFilter.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_edgeFilter.m_pntr = v2;
}

// File Line: 253
// RVA: 0xBD54B0
void __fastcall hkaiCharacter::setSteeringFilter(hkaiCharacter *this, hkaiLocalSteeringFilter *steeringFilter)
{
  hkaiLocalSteeringFilter *v2; // rbx
  hkaiCharacter *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = steeringFilter;
  v3 = this;
  if ( steeringFilter )
    hkReferencedObject::addReference((hkReferencedObject *)&steeringFilter->vfptr);
  v4 = (hkReferencedObject *)&v3->m_steeringFilter.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_steeringFilter.m_pntr = v2;
}

// File Line: 258
// RVA: 0xBD5460
void __fastcall hkaiCharacter::setQueryHitFilter(hkaiCharacter *this, hkaiSpatialQueryHitFilter *hitFilter)
{
  hkaiSpatialQueryHitFilter *v2; // rbx
  hkaiCharacter *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = hitFilter;
  v3 = this;
  if ( hitFilter )
    hkReferencedObject::addReference((hkReferencedObject *)&hitFilter->vfptr);
  v4 = (hkReferencedObject *)&v3->m_hitFilter.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_hitFilter.m_pntr = v2;
}

// File Line: 263
// RVA: 0xBD5390
void __fastcall hkaiCharacter::setAvoidanceProperties(hkaiCharacter *this, hkaiAvoidanceProperties *props)
{
  hkaiAvoidanceProperties *v2; // rbx
  hkaiCharacter *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = props;
  v3 = this;
  if ( props )
    hkReferencedObject::addReference((hkReferencedObject *)&props->vfptr);
  v4 = (hkReferencedObject *)&v3->m_avoidanceProperties.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_avoidanceProperties.m_pntr = v2;
}

// File Line: 268
// RVA: 0xBD5550
float __fastcall hkaiCharacter::getAngularVelocity(hkaiCharacter *this)
{
  return this->m_velocity.m_quad.m128_f32[3];
}

