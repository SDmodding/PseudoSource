// File Line: 27
// RVA: 0x15440E0
__int64 dynamic_initializer_for__UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentList__);
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
  signed __int64 v0; // rcx
  __int64 v1; // rax

  v0 = 91i64;
  v1 = UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_Map.size;
  do
  {
    UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_Map.p[v1] = 0;
    v1 = UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_Map.size++ + 1;
    --v0;
  }
  while ( v0 );
  UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_Map.p[0] = UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  ++UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemCraneComponent::ms_TargetingMap__);
}

// File Line: 44
// RVA: 0x5357E0
bool __fastcall UFG::TargetingSystemCraneComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentTargetingSystemCrane.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 50
// RVA: 0x5455E0
UFG::SimComponent *__fastcall UFG::TargetingSystemCraneComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *v4; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0xA0ui64, "TargetingSystemCraneComponent", 0i64, 1u);
  if ( v3 )
  {
    v4 = v1->mpWritableProperties;
    if ( !v4 )
      v4 = v1->mpConstProperties;
    UFG::TargetingSystemCraneComponent::TargetingSystemCraneComponent(
      (UFG::TargetingSystemCraneComponent *)v3,
      v1->m_NameUID,
      v4,
      0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return v6;
}

// File Line: 68
// RVA: 0x519990
void __fastcall UFG::TargetingSystemCraneComponent::TargetingSystemCraneComponent(UFG::TargetingSystemCraneComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, bool startSuspended)
{
  UFG::qPropertySet *v4; // rbx
  UFG::TargetingSystemCraneComponent *v5; // rdi
  UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *v6; // rdx
  UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *v7; // rax

  v4 = properties;
  v5 = this;
  UFG::TargetingSystemBaseComponent::TargetingSystemBaseComponent(
    (UFG::TargetingSystemBaseComponent *)&this->vfptr,
    &UFG::TargetingSystemCraneComponent::ms_TargetingMap,
    name_uid,
    properties);
  v6 = (UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemCraneComponent::`vftable'{for `UFG::SimComponent'};
  v5->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemCraneComponent::`vftable'{for `UFG::UpdateInterface'};
  v5->mProbeBone.mUID = -1;
  v5->mProbeBoneIndex = -1;
  v7 = UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentList.mNode.mPrev;
  UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *)&v5->mPrev;
  v6->mPrev = v7;
  v5->mNext = (UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *)&UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentList;
  UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentList.mNode.mPrev = (UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *)&v5->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::TargetingSystemCraneComponent::_TargetingSystemCraneComponentTypeUID,
    "TargetingSystemCraneComponent");
  UFG::TargetingSystemCraneComponent::InitFromPropertySet(v5, v4);
}

// File Line: 78
// RVA: 0x51CDA0
void __fastcall UFG::TargetingSystemCraneComponent::~TargetingSystemCraneComponent(UFG::TargetingSystemCraneComponent *this)
{
  UFG::TargetingSystemCraneComponent *v1; // r8
  UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *v2; // rdx
  UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *v3; // rcx
  UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *v4; // rax
  UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *v5; // rcx
  UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemCraneComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemCraneComponent::`vftable'{for `UFG::UpdateInterface'};
  if ( this == UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentpCurrentIterator )
    UFG::TargetingSystemCraneComponent::s_TargetingSystemCraneComponentpCurrentIterator = (UFG::TargetingSystemCraneComponent *)&this->mPrev[-8].mNext;
  v2 = (UFG::qNode<UFG::TargetingSystemCraneComponent,UFG::TargetingSystemCraneComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::TargetingSystemBaseComponent::~TargetingSystemBaseComponent((UFG::TargetingSystemBaseComponent *)&v1->vfptr);
}

// File Line: 87
// RVA: 0x538C60
void __fastcall UFG::TargetingSystemCraneComponent::InitFromPropertySet(UFG::TargetingSystemCraneComponent *this, UFG::qPropertySet *properties)
{
  UFG::qPropertySet *v2; // rbx
  UFG::TargetingSystemCraneComponent *v3; // rdi
  char *v4; // rax
  UFG::qVector3 *v5; // rax
  float v6; // xmm0_4
  float v7; // xmm1_4
  UFG::qSymbolUC result; // [rsp+38h] [rbp+10h]

  if ( properties )
  {
    v2 = properties;
    v3 = this;
    v4 = UFG::qPropertySet::Get<char const *>(properties, (UFG::qSymbol *)&SimSym_ProbeBone.mUID, DEPTH_RECURSE);
    v3->mProbeBone = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, v4)->mUID;
    v5 = UFG::qPropertySet::Get<UFG::qVector3>(v2, (UFG::qSymbol *)&SimSym_ProbeOffset.mUID, DEPTH_RECURSE);
    v6 = v5->y;
    v7 = v5->z;
    v3->mProbeOffset.x = v5->x;
    v3->mProbeOffset.y = v6;
    v3->mProbeOffset.z = v7;
    v3->mProbeLength = *UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&SimSym_ProbeLength.mUID, DEPTH_RECURSE);
  }
}

// File Line: 98
// RVA: 0x53EB20
void __fastcall UFG::TargetingSystemCraneComponent::OnAttach(UFG::TargetingSystemCraneComponent *this, UFG::SimObject *simObject)
{
  UFG::TargetingSystemCraneComponent *v2; // rbx
  UFG::SimComponent *v3; // rax
  __int64 v4; // rcx

  if ( simObject )
  {
    v2 = this;
    v3 = UFG::SimObject::GetComponentOfType(simObject, UFG::CharacterAnimationComponent::_TypeUID);
    if ( v3 )
    {
      v4 = *(_QWORD *)&v3[2].m_TypeUID;
      if ( v4 )
      {
        if ( *(_QWORD *)(v4 + 440) )
          v2->mProbeBoneIndex = Skeleton::GetBoneID(*(Skeleton **)(v4 + 480), v2->mProbeBone.mUID);
        else
          v2->mProbeBoneIndex = -1;
      }
    }
  }
}

// File Line: 110
// RVA: 0x55C890
void __fastcall UFG::TargetingSystemCraneComponent::Update(UFG::TargetingSystemCraneComponent *this, float delta_sec)
{
  UFG::TargetingSystemCraneComponent *v2; // rsi
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rax
  Creature *v5; // rcx
  int v6; // er8
  __m128 v7; // xmm8
  __m128 v8; // xmm7
  float v9; // xmm0_4
  __m128 v10; // xmm6
  hkpWorld *v11; // rbx
  int v12; // er12
  int v13; // er15
  int v14; // er8
  __int64 v15; // r14
  __int64 v16; // rdx
  hkpWorldObject *v17; // rdi
  unsigned __int64 v18; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v19; // rcx
  const char *v20; // rax
  UFG::qReflectObject *v21; // rax
  unsigned __int64 v22; // rax
  UFG::SimObject *v23; // rbx
  unsigned __int8 v24; // cl
  unsigned __int8 v25; // cl
  signed __int64 v26; // rbx
  __int64 v27; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-B8h]
  UFG::qReflectHandleBase v29; // [rsp+30h] [rbp-A8h]
  char v30; // [rsp+58h] [rbp-80h]
  int v31; // [rsp+5Ch] [rbp-7Ch]
  hkpWorldRayCastInput input; // [rsp+60h] [rbp-78h]
  int v33; // [rsp+90h] [rbp-48h]
  int v34; // [rsp+94h] [rbp-44h]
  unsigned __int64 *v35; // [rsp+3F8h] [rbp+320h]

  input.m_from.m_quad.m128_u64[1] = -2i64;
  v2 = this;
  v3 = *(UFG::SimObject **)&this[-1].mProbeBone.mUID;
  if ( !v3 )
    return;
  v4 = UFG::SimObject::GetComponentOfType(v3, UFG::CharacterAnimationComponent::_TypeUID);
  if ( !v4 )
    return;
  v5 = *(Creature **)&v4[2].m_TypeUID;
  if ( !v5 )
    return;
  v6 = HIDWORD(v2->m_pTargets);
  if ( v6 == -1 )
    return;
  Creature::GetTranslation(v5, &result, v6);
  v7 = (__m128)LODWORD(result.x);
  v8 = (__m128)LODWORD(result.y);
  v8.m128_f32[0] = result.y + *(float *)&v2->mNext;
  v9 = result.z + *((float *)&v2->mNext + 1);
  result.x = result.x + *((float *)&v2->mPrev + 1);
  v7.m128_f32[0] = result.x;
  LODWORD(result.y) = v8.m128_i32[0];
  result.z = v9;
  v10 = _mm_xor_ps((__m128)LODWORD(v2->m_pTargets), *(__m128 *)_xmm);
  v10.m128_f32[0] = v10.m128_f32[0] + v9;
  v11 = UFG::BasePhysicsSystem::mInstance->mWorld;
  hkpAllRayHitCollector::hkpAllRayHitCollector((hkpAllRayHitCollector *)&input.m_to.m_quad.m128_u16[4]);
  input.m_from.m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps((__m128)LODWORD(result.x), (__m128)LODWORD(result.z)),
                          _mm_unpacklo_ps((__m128)LODWORD(result.y), (__m128)0i64));
  input.m_to.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v7, v10), _mm_unpacklo_ps(v8, (__m128)0i64));
  v31 = 15;
  v30 = 0;
  hkpWorld::castRay(v11, &input, (hkpRayHitCollector *)&input.m_to.m_quad.m128_u16[4]);
  hkpAllRayHitCollector::sortHits((hkpAllRayHitCollector *)&input.m_to.m_quad.m128_u16[4]);
  v12 = UFG::qStringHashUpper32("CargoContainer", 0xFFFFFFFF);
  v13 = 0;
  v14 = v33;
  if ( v33 <= 0 )
  {
LABEL_24:
    v25 = *(_BYTE *)(*(_QWORD *)&v2->m_Flags + 68i64);
    if ( v25 )
    {
      v26 = 56i64 * v25;
      UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v26 + *(_QWORD *)&v2->m_TypeUID), 0i64);
      v27 = *(_QWORD *)&v2->m_TypeUID;
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
  v18 = UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid(v17);
  UFG::qReflectHandleBase::qReflectHandleBase(&v29);
  v20 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v19);
  v29.mTypeUID = UFG::qStringHash64(v20, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v29, v29.mTypeUID, v18);
  v21 = v29.mData;
  if ( !v29.mData )
  {
    UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v29);
    v21 = v29.mData;
  }
  if ( HIDWORD(v21[4].mBaseNode.mParent) != v12 )
    goto LABEL_31;
  v22 = v17->m_userData;
  if ( !v22 )
    goto LABEL_31;
  v23 = *(UFG::SimObject **)(v22 + 24);
  if ( v23 )
    v23 = (UFG::SimObject *)v23->mNode.mParent;
  if ( !v23
    || v23 == *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v2->m_Flags + 67i64)
                                 + *(_QWORD *)&v2->m_TypeUID
                                 + 40) )
  {
LABEL_31:
    UFG::qReflectHandleBase::~qReflectHandleBase(&v29);
    v14 = v33;
    goto LABEL_20;
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v29);
  v24 = *(_BYTE *)(*(_QWORD *)&v2->m_Flags + 68i64);
  if ( v24 )
    UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(*(_QWORD *)&v2->m_TypeUID + 56i64 * v24), v23);
LABEL_27:
  input.m_to.m_quad.m128_u64[1] = (unsigned __int64)&hkpAllRayHitCollector::`vftable';
  v35 = &input.m_userData;
  v33 = 0;
  if ( v34 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)input.m_userData,
      96 * (v34 & 0x3FFFFFFF));
}

