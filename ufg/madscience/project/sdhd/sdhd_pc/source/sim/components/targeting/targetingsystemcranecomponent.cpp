// File Line: 27
// RVA: 0x15440E0
__int64 dynamic_initializer_for__UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentList__);
}

// File Line: 28
// RVA: 0x1543610
__int64 dynamic_initializer_for__UFG::TargetingSystemCraneComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::TargetingSystemCraneComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::TargetingSystemCraneComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::TargetingSystemCraneComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::TargetingSystemCraneComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 30
// RVA: 0x1543A10
__int64 dynamic_initializer_for__UFG::TargetingSystemCraneComponent::ms_TargetingMap__()
{
  __int64 v0; // rcx
  __int64 size; // rax

  v0 = 91i64;
  size = UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_Map.size;
  do
  {
    UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_Map.p[size] = 0;
    size = ++UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_Map.size;
    --v0;
  }
  while ( v0 );
  UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_Map.p[0] = UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  ++UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemCraneComponent::ms_TargetingMap__);
}

// File Line: 44
// RVA: 0x5357E0
bool __fastcall UFG::TargetingSystemCraneComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentTargetingSystemCrane,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 50
// RVA: 0x5455E0
UFG::TargetingSystemCraneComponent *__fastcall UFG::TargetingSystemCraneComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xA0ui64, "TargetingSystemCraneComponent", 0i64, 1u);
  if ( v3 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::TargetingSystemCraneComponent::TargetingSystemCraneComponent(
      (UFG::TargetingSystemCraneComponent *)v3,
      pSceneObj->m_NameUID,
      mpWritableProperties,
      0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, pSceneObj->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return (UFG::TargetingSystemCraneComponent *)v6;
}

// File Line: 68
// RVA: 0x519990
void __fastcall UFG::TargetingSystemCraneComponent::TargetingSystemCraneComponent(
        UFG::TargetingSystemCraneComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        bool startSuspended)
{
  UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *mPrev; // rax

  UFG::TargetingSystemBaseComponent::TargetingSystemBaseComponent(
    this,
    &UFG::TargetingSystemCraneComponent::ms_TargetingMap,
    name_uid,
    properties);
  this->UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent>::mPrev = &this->UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent>;
  this->UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent>::mNext = &this->UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent>;
  this->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemCraneComponent::`vftable{for `UFG::SimComponent};
  this->UFG::TargetingSystemBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemCraneComponent::`vftable{for `UFG::UpdateInterface};
  this->mProbeBone.mUID = -1;
  this->mProbeBoneIndex = -1;
  mPrev = UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentList.mNode.mPrev;
  UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent>;
  this->UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent>::mNext = (UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *)&UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentList;
  UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentList.mNode.mPrev = &this->UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::TargetingSystemCraneComponent::_TargetingSystemCraneComponentTypeUID,
    "TargetingSystemCraneComponent");
  UFG::TargetingSystemCraneComponent::InitFromPropertySet(this, properties);
}

// File Line: 78
// RVA: 0x51CDA0
void __fastcall UFG::TargetingSystemCraneComponent::~TargetingSystemCraneComponent(
        UFG::TargetingSystemCraneComponent *this)
{
  UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *v2; // rdx
  UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *mPrev; // rcx
  UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *mNext; // rax
  UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *v5; // rcx
  UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *v6; // rax

  this->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemCraneComponent::`vftable{for `UFG::SimComponent};
  this->UFG::TargetingSystemBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemCraneComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentpCurrentIterator )
    UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentpCurrentIterator = (UFG::TargetingSystemCraneComponent *)&this->UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent>::mPrev[-8].mNext;
  v2 = &this->UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent>;
  mPrev = this->UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::TargetingSystemBaseComponent::~TargetingSystemBaseComponent(this);
}

// File Line: 87
// RVA: 0x538C60
void __fastcall UFG::TargetingSystemCraneComponent::InitFromPropertySet(
        UFG::TargetingSystemCraneComponent *this,
        UFG::qPropertySet *properties)
{
  char *v4; // rax
  UFG::qVector3 *v5; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qSymbolUC result; // [rsp+38h] [rbp+10h] BYREF

  if ( properties )
  {
    v4 = UFG::qPropertySet::Get<char const *>(
           properties,
           (UFG::qArray<unsigned long,0> *)&SimSym_ProbeBone,
           DEPTH_RECURSE);
    this->mProbeBone = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, v4)->mUID;
    v5 = UFG::qPropertySet::Get<UFG::qVector3>(
           properties,
           (UFG::qArray<unsigned long,0> *)&SimSym_ProbeOffset,
           DEPTH_RECURSE);
    y = v5->y;
    z = v5->z;
    this->mProbeOffset.x = v5->x;
    this->mProbeOffset.y = y;
    this->mProbeOffset.z = z;
    this->mProbeLength = *UFG::qPropertySet::Get<float>(
                            properties,
                            (UFG::qArray<unsigned long,0> *)&SimSym_ProbeLength,
                            DEPTH_RECURSE);
  }
}

// File Line: 98
// RVA: 0x53EB20
void __fastcall UFG::TargetingSystemCraneComponent::OnAttach(
        UFG::TargetingSystemCraneComponent *this,
        UFG::SimObject *simObject)
{
  UFG::SimComponent *ComponentOfType; // rax
  __int64 v4; // rcx

  if ( simObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(simObject, UFG::CharacterAnimationComponent::_TypeUID);
    if ( ComponentOfType )
    {
      v4 = *(_QWORD *)&ComponentOfType[2].m_TypeUID;
      if ( v4 )
      {
        if ( *(_QWORD *)(v4 + 440) )
          this->mProbeBoneIndex = Skeleton::GetBoneID(*(Skeleton **)(v4 + 480), this->mProbeBone.mUID);
        else
          this->mProbeBoneIndex = -1;
      }
    }
  }
}

// File Line: 110
// RVA: 0x55C890
void __fastcall UFG::TargetingSystemCraneComponent::Update(UFG::TargetingSystemCraneComponent *this, float delta_sec)
{
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  Creature *v5; // rcx
  int m_pTargets_high; // r8d
  __m128 x_low; // xmm8
  __m128 y_low; // xmm7
  float v9; // xmm0_4
  __m128 v10; // xmm6
  hkpWorld *mWorld; // rbx
  int v12; // r12d
  int v13; // r15d
  int v14; // r8d
  __int64 v15; // r14
  __int64 v16; // rdx
  hkpWorldObject *v17; // rdi
  unsigned __int64 ObjectPropertiesHandleUid; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v19; // rcx
  const char *TypeName; // rax
  UFG::qReflectObject *mData; // rax
  unsigned __int64 m_userData; // rax
  UFG::SimObject *mParent; // rbx
  unsigned __int8 v24; // cl
  unsigned __int8 v25; // cl
  __int64 v26; // rbx
  __int64 v27; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-B8h] BYREF
  UFG::qReflectHandleBase v29; // [rsp+30h] [rbp-A8h] BYREF
  char v30; // [rsp+58h] [rbp-80h]
  int v31; // [rsp+5Ch] [rbp-7Ch]
  hkpWorldRayCastInput input; // [rsp+60h] [rbp-78h] BYREF
  int v33; // [rsp+90h] [rbp-48h]
  int v34; // [rsp+94h] [rbp-44h]
  unsigned __int64 *p_m_userData; // [rsp+3F8h] [rbp+320h]

  input.m_from.m_quad.m128_u64[1] = -2i64;
  v3 = *(UFG::SimObject **)&this[-1].mProbeBone.mUID;
  if ( !v3 )
    return;
  ComponentOfType = UFG::SimObject::GetComponentOfType(v3, UFG::CharacterAnimationComponent::_TypeUID);
  if ( !ComponentOfType )
    return;
  v5 = *(Creature **)&ComponentOfType[2].m_TypeUID;
  if ( !v5 )
    return;
  m_pTargets_high = HIDWORD(this->m_pTargets);
  if ( m_pTargets_high == -1 )
    return;
  Creature::GetTranslation(v5, &result, m_pTargets_high);
  x_low = (__m128)LODWORD(result.x);
  y_low = (__m128)LODWORD(result.y);
  y_low.m128_f32[0] = result.y
                    + *(float *)&this->UFG::TargetingSystemBaseComponent::UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent>::mNext;
  v9 = result.z
     + *((float *)&this->UFG::TargetingSystemBaseComponent::UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent>::mNext
       + 1);
  result.x = result.x
           + *((float *)&this->UFG::TargetingSystemBaseComponent::UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent>::mPrev
             + 1);
  x_low.m128_f32[0] = result.x;
  LODWORD(result.y) = y_low.m128_i32[0];
  result.z = v9;
  v10 = _mm_xor_ps((__m128)LODWORD(this->m_pTargets), *(__m128 *)_xmm);
  v10.m128_f32[0] = v10.m128_f32[0] + v9;
  mWorld = UFG::BasePhysicsSystem::mInstance->mWorld;
  hkpAllRayHitCollector::hkpAllRayHitCollector((hkpAllRayHitCollector *)&input.m_to.m_quad.m128_u16[4]);
  input.m_from.m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps((__m128)LODWORD(result.x), (__m128)LODWORD(result.z)),
                          _mm_unpacklo_ps((__m128)LODWORD(result.y), (__m128)0i64));
  input.m_to.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, v10), _mm_unpacklo_ps(y_low, (__m128)0i64));
  v31 = 15;
  v30 = 0;
  hkpWorld::castRay(mWorld, &input, (hkpRayHitCollector *)&input.m_to.m_quad.m128_u16[4]);
  hkpAllRayHitCollector::sortHits((hkpAllRayHitCollector *)&input.m_to.m_quad.m128_u16[4]);
  v12 = UFG::qStringHashUpper32("CargoContainer", -1);
  v13 = 0;
  v14 = v33;
  if ( v33 <= 0 )
  {
LABEL_24:
    v25 = *(_BYTE *)(*(_QWORD *)&this->m_Flags + 68i64);
    if ( v25 )
    {
      v26 = 56i64 * v25;
      UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v26 + *(_QWORD *)&this->m_TypeUID), 0i64);
      v27 = *(_QWORD *)&this->m_TypeUID;
      if ( *(_BYTE *)(v26 + v27 + 49) )
        *(_BYTE *)(v26 + v27 + 49) = 0;
    }
    goto LABEL_27;
  }
  v15 = 0i64;
  while ( 1 )
  {
    v16 = *(_QWORD *)(input.m_userData + v15 + 80);
    if ( v16 )
      break;
LABEL_20:
    ++v13;
    v15 += 96i64;
    if ( v13 >= v14 )
      goto LABEL_24;
  }
  if ( *(_BYTE *)(v16 + 40) == 1 )
    v17 = (hkpWorldObject *)(v16 + *(char *)(v16 + 32));
  else
    v17 = 0i64;
  ObjectPropertiesHandleUid = UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid(v17);
  UFG::qReflectHandleBase::qReflectHandleBase(&v29);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v19);
  v29.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v29, v29.mTypeUID, ObjectPropertiesHandleUid);
  mData = v29.mData;
  if ( !v29.mData )
  {
    UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v29);
    mData = v29.mData;
  }
  if ( HIDWORD(mData[4].mBaseNode.mParent) != v12 )
    goto LABEL_19;
  m_userData = v17->m_userData;
  if ( !m_userData )
    goto LABEL_19;
  mParent = *(UFG::SimObject **)(m_userData + 24);
  if ( mParent )
    mParent = (UFG::SimObject *)mParent->mNode.mParent;
  if ( !mParent
    || mParent == *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&this->m_Flags + 67i64)
                                     + *(_QWORD *)&this->m_TypeUID
                                     + 40) )
  {
LABEL_19:
    UFG::qReflectHandleBase::~qReflectHandleBase(&v29);
    v14 = v33;
    goto LABEL_20;
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v29);
  v24 = *(_BYTE *)(*(_QWORD *)&this->m_Flags + 68i64);
  if ( v24 )
    UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(*(_QWORD *)&this->m_TypeUID + 56i64 * v24), mParent);
LABEL_27:
  input.m_to.m_quad.m128_u64[1] = (unsigned __int64)&hkpAllRayHitCollector::`vftable;
  p_m_userData = &input.m_userData;
  v33 = 0;
  if ( v34 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      (void *)input.m_userData,
      96 * (v34 & 0x3FFFFFFF));
}

