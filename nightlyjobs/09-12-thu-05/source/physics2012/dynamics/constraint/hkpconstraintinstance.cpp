// File Line: 48
// RVA: 0xD5F570
void __fastcall hkpConstraintInstance::hkpConstraintInstance(
        hkpConstraintInstance *this,
        hkpEntity *entityA,
        hkpEntity *entityB,
        hkpConstraintData *data,
        hkpConstraintInstance::ConstraintPriority priority)
{
  hkpEntity *v8; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_data = data;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConstraintInstance::`vftable;
  this->m_owner = 0i64;
  this->m_priority.m_storage = priority;
  *(_WORD *)&this->m_wantRuntime.m_bool = 1;
  this->m_listeners.m_data = 0i64;
  *(_DWORD *)&this->m_listeners.m_size = 0x80000000;
  hkStringPtr::hkStringPtr(&this->m_name);
  this->m_userData = 0i64;
  this->m_internal = 0i64;
  this->m_uid = -16;
  this->m_entities[0] = entityA;
  this->m_entities[1] = entityB;
  this->m_constraintModifiers = 0i64;
  hkReferencedObject::lockAll();
  hkReferencedObject::addReference(this->m_entities[0]);
  v8 = this->m_entities[1];
  if ( v8 )
    hkReferencedObject::addReference(v8);
  hkReferencedObject::addReference(this->m_data);
  hkReferencedObject::unlockAll();
}

// File Line: 86
// RVA: 0xD5F8B0
void __fastcall hkpConstraintInstance::hkpConstraintInstance(
        hkpConstraintInstance *this,
        hkpConstraintInstance::ConstraintPriority priority)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConstraintInstance::`vftable;
  this->m_owner = 0i64;
  this->m_constraintModifiers = 0i64;
  this->m_priority.m_storage = priority;
  *(_WORD *)&this->m_wantRuntime.m_bool = 1;
  this->m_listeners.m_data = 0i64;
  *(_DWORD *)&this->m_listeners.m_size = 0x80000000;
  hkStringPtr::hkStringPtr(&this->m_name);
  this->m_userData = 0i64;
  this->m_internal = 0i64;
  this->m_uid = -16;
}

// File Line: 91
// RVA: 0xD601F0
void __fastcall hkpConstraintInstance::setPriority(
        hkpConstraintInstance *this,
        hkpConstraintInstance::ConstraintPriority priority)
{
  hkConstraintInternal *m_internal; // rax

  m_internal = this->m_internal;
  this->m_priority.m_storage = priority;
  if ( m_internal )
    m_internal->m_priority.m_storage = priority;
}

// File Line: 100
// RVA: 0xD5F9B0
hkpSimulationIsland *__fastcall hkpConstraintInstance::getSimulationIsland(hkpConstraintInstance *this)
{
  hkpEntity *v1; // rax

  v1 = this->m_entities[0];
  if ( v1->m_motion.m_type.m_storage == 5 )
    v1 = this->m_entities[1];
  return v1->m_simulationIsland;
}

// File Line: 110
// RVA: 0xD60340
void __fastcall hkpConstraintInstance::entityAddedCallback(hkpConstraintInstance *this, hkpEntity *entity)
{
  ;
}

// File Line: 115
// RVA: 0xD60380
void __fastcall hkpConstraintInstance::entityDeletedCallback(hkpConstraintInstance *this, hkpEntity *entity)
{
  ;
}

// File Line: 120
// RVA: 0xD60350
void __fastcall hkpConstraintInstance::entityRemovedCallback(hkpConstraintInstance *this, hkpEntity *entity)
{
  if ( this->m_owner )
    hkpWorldOperationUtil::removeConstraintImmediately(entity->m_world, this, DO_FIRE_CALLBACKS);
}

// File Line: 131
// RVA: 0xD5F730
hkStringPtr *__fastcall hkpConstraintInstance::clone(
        hkpConstraintInstance *this,
        hkpEntity *newEntityA,
        hkpEntity *newEntityB,
        hkpConstraintInstance::CloningMode mode)
{
  hkpConstraintData *m_data; // rsi
  _QWORD **v8; // rax
  hkpConstraintInstance *v9; // rax
  hkStringPtr *v10; // rax
  hkStringPtr *v11; // rbx
  _QWORD **Value; // rax
  hkpConstraintInstance *v13; // rax
  hkStringPtr *v14; // rax
  _QWORD **v15; // rax
  hkpConstraintInstance *v16; // rax
  hkStringPtr *v17; // rax
  hkBool result; // [rsp+58h] [rbp+20h] BYREF

  if ( mode )
  {
    if ( mode == CLONE_DATAS_WITH_MOTORS )
    {
      m_data = hkpConstraintDataUtils::cloneIfCanHaveMotors(this->m_data);
      if ( !m_data )
      {
        m_data = this->m_data;
        hkReferencedObject::addReference(m_data);
      }
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v13 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                       Value[11],
                                       112i64);
      if ( v13 )
      {
        hkpConstraintInstance::hkpConstraintInstance(
          v13,
          newEntityA,
          newEntityB,
          m_data,
          (hkpConstraintInstance::ConstraintPriority)(unsigned __int8)this->m_priority.m_storage);
        v11 = v14;
        hkReferencedObject::removeReference(m_data);
        goto LABEL_14;
      }
      goto LABEL_10;
    }
  }
  else if ( hkpConstraintInstance::isConstrainedToWorld(this, &result)->m_bool )
  {
    m_data = hkpConstraintDataCloningUtil::deepClone(this->m_data);
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v8[11] + 8i64))(v8[11], 112i64);
    if ( v9 )
    {
      hkpConstraintInstance::hkpConstraintInstance(
        v9,
        newEntityA,
        0i64,
        m_data,
        (hkpConstraintInstance::ConstraintPriority)(unsigned __int8)this->m_priority.m_storage);
      v11 = v10;
      hkReferencedObject::removeReference(m_data);
      goto LABEL_14;
    }
LABEL_10:
    v11 = 0i64;
    hkReferencedObject::removeReference(m_data);
    goto LABEL_14;
  }
  v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v15[11] + 8i64))(v15[11], 112i64);
  if ( v16 )
  {
    hkpConstraintInstance::hkpConstraintInstance(
      v16,
      newEntityA,
      newEntityB,
      this->m_data,
      (hkpConstraintInstance::ConstraintPriority)(unsigned __int8)this->m_priority.m_storage);
    v11 = v17;
  }
  else
  {
    v11 = 0i64;
  }
LABEL_14:
  hkStringPtr::operator=(
    v11 + 10,
    (const char *)((unsigned __int64)this->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
  return v11;
}

// File Line: 178
// RVA: 0xD5F630
void __fastcall hkpConstraintInstance::~hkpConstraintInstance(hkpConstraintInstance *this)
{
  hkpEntity *v2; // rcx
  hkpEntity *v3; // rcx
  hkpModifierConstraintAtom *m_constraintModifiers; // rsi
  hkpModifierConstraintAtom *v5; // rdi
  unsigned int m_modifierAtomSize; // ebx
  _QWORD **Value; // rax
  hkpConstraintData *m_data; // rcx
  signed __int16 m_capacityAndFlags; // di
  hkpConstraintListener **v10; // rbx
  _QWORD **v11; // rax

  this->vfptr = (hkBaseObjectVtbl *)&hkpConstraintInstance::`vftable;
  hkpConstraintCallbackUtil::fireConstraintDeleted(this);
  v2 = this->m_entities[0];
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  v3 = this->m_entities[1];
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  m_constraintModifiers = this->m_constraintModifiers;
  if ( m_constraintModifiers && m_constraintModifiers->m_type.m_storage >= 0x1Eu )
  {
    do
    {
      v5 = m_constraintModifiers;
      m_constraintModifiers = (hkpModifierConstraintAtom *)m_constraintModifiers->m_child;
      m_modifierAtomSize = v5->m_modifierAtomSize;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpModifierConstraintAtom *, _QWORD))(*Value[11] + 16i64))(
        Value[11],
        v5,
        m_modifierAtomSize);
    }
    while ( m_constraintModifiers->m_type.m_storage >= 0x1Eu );
  }
  m_data = this->m_data;
  if ( m_data )
    hkReferencedObject::removeReference(m_data);
  hkStringPtr::~hkStringPtr(&this->m_name);
  m_capacityAndFlags = this->m_listeners.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
  {
    v10 = this->m_listeners.m_data;
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpConstraintListener **, _QWORD))(*v11[11] + 16i64))(
      v11[11],
      v10,
      8 * (m_capacityAndFlags & 0x3FFFu));
  }
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 219
// RVA: 0xD5FA60
void __fastcall hkpConstraintInstance::addConstraintListener(
        hkpConstraintInstance *this,
        hkpConstraintListener *listener)
{
  int m_size; // r8d
  hkSmallArray<hkpConstraintListener *> *p_m_listeners; // rbx
  int v4; // eax
  hkpConstraintListener **m_data; // rcx

  m_size = this->m_listeners.m_size;
  p_m_listeners = &this->m_listeners;
  v4 = 0;
  if ( !this->m_listeners.m_size )
    goto LABEL_5;
  m_data = p_m_listeners->m_data;
  while ( *m_data )
  {
    ++v4;
    ++m_data;
    if ( v4 >= m_size )
      goto LABEL_5;
  }
  if ( v4 >= 0 )
  {
    p_m_listeners->m_data[v4] = listener;
  }
  else
  {
LABEL_5:
    if ( (_WORD)m_size == (p_m_listeners->m_capacityAndFlags & 0x3FFF) )
      hkSmallArrayUtil::_reserveMore(p_m_listeners, 8);
    p_m_listeners->m_data[p_m_listeners->m_size++] = listener;
  }
}

// File Line: 235
// RVA: 0xD5FAF0
void __fastcall hkpConstraintInstance::removeConstraintListener(
        hkpConstraintInstance *this,
        hkpConstraintListener *listener)
{
  int v2; // r9d
  __int64 v3; // r8
  hkpConstraintListener **m_data; // rax

  v2 = 0;
  v3 = 0i64;
  if ( this->m_listeners.m_size )
  {
    m_data = this->m_listeners.m_data;
    while ( *m_data != listener )
    {
      ++v3;
      ++v2;
      ++m_data;
      if ( v3 >= this->m_listeners.m_size )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v2 = -1;
  }
  this->m_listeners.m_data[v2] = 0i64;
}

// File Line: 243
// RVA: 0xD5FB40
void __fastcall hkpConstraintInstance::transform(hkpConstraintInstance *this, hkTransformf *transformation)
{
  hkpConstraintData *m_data; // r14
  unsigned int v5; // eax
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  hkVector4f v9; // xmm1
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm1
  hkVector4f v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  hkVector4f v15; // xmm0
  hkVector4f v16; // xmm1
  hkVector4f v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  hkVector4f v22; // xmm0
  hkVector4f v23; // xmm1
  __m128 v24; // xmm1
  __int64 v25; // rcx
  __m128 v26; // xmm5
  __m128 v27; // xmm6
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  hkVector4f v32; // xmm1
  hkVector4f v33; // xmm0
  hkVector4f v34; // xmm1
  hkVector4f v35; // xmm0
  hkVector4f v36; // xmm1
  hkVector4f v37; // xmm0
  hkVector4f v38; // xmm1
  int vfptr_high; // xmm6_4
  hkReferencedObject v40; // xmm7
  __m128 m_quad; // xmm0
  hkVector4f v42; // xmm1
  __m128 v43; // xmm2
  hkVector4f v44; // xmm0
  hkVector4f v45; // xmm1
  hkVector4f v46; // xmm0
  __m128 v47; // xmm1
  __m128 v48; // xmm0
  __m128 v49; // xmm1
  hkVector4f b; // [rsp+40h] [rbp-C0h] BYREF
  hkVector4f planeNormalB; // [rsp+50h] [rbp-B0h] BYREF
  hkVector4f steeringAxisB; // [rsp+60h] [rbp-A0h] BYREF
  hkVector4f axisA; // [rsp+70h] [rbp-90h] BYREF
  hkTransformf pivotA; // [rsp+80h] [rbp-80h] BYREF
  hkTransformf pivotB; // [rsp+C0h] [rbp-40h] BYREF
  hkVector4f axleA; // [rsp+100h] [rbp+0h] BYREF
  hkVector4f v57; // [rsp+110h] [rbp+10h] BYREF
  hkBool result; // [rsp+170h] [rbp+70h] BYREF

  if ( hkpConstraintInstance::isConstrainedToWorld(this, &result)->m_bool )
  {
    m_data = this->m_data;
    v5 = ((__int64 (__fastcall *)(hkpConstraintData *))m_data->vfptr[1].__first_virtual_table_function__)(m_data);
    while ( 2 )
    {
      switch ( v5 )
      {
        case 0u:
          hkVector4f::setTransformedPos(
            (hkVector4f *)&m_data[2].m_userData,
            transformation,
            (hkVector4f *)&m_data[2].m_userData);
          hkpBallAndSocketConstraintData::setInBodySpace(
            (hkpBallAndSocketConstraintData *)m_data,
            (hkVector4f *)&m_data[2],
            (hkVector4f *)&m_data[2].m_userData);
          return;
        case 1u:
          v12.m_quad = *(__m128 *)&m_data[3].m_memSizeAndFlags;
          v13 = (__m128)m_data[2].hkReferencedObject;
          v14 = *(__m128 *)&m_data[4].m_userData;
          pivotB.m_rotation.m_col1 = *(hkVector4f *)&m_data[2].m_userData;
          pivotB.m_translation = (hkVector4f)m_data[4].hkReferencedObject;
          v15.m_quad = *(__m128 *)&m_data[5].m_memSizeAndFlags;
          pivotB.m_rotation.m_col2 = (hkVector4f)v12.m_quad;
          v16.m_quad = (__m128)m_data[6].hkReferencedObject;
          pivotA.m_rotation.m_col1 = (hkVector4f)v15.m_quad;
          pivotA.m_translation = *(hkVector4f *)&m_data[6].m_userData;
          pivotB.m_rotation.m_col0.m_quad = v13;
          pivotA.m_rotation.m_col0.m_quad = v14;
          pivotA.m_rotation.m_col2 = (hkVector4f)v16.m_quad;
          axisA.m_quad = v13;
          b.m_quad = v14;
          hkVector4f::setTransformedPos(&pivotA.m_translation, transformation, &pivotA.m_translation);
          hkVector4f::setRotatedDir(&b, &transformation->m_rotation, &b);
          hkpHingeConstraintData::setInBodySpace(
            (hkpHingeConstraintData *)m_data,
            &pivotB.m_translation,
            &pivotA.m_translation,
            &axisA,
            &b);
          return;
        case 2u:
          v17.m_quad = (__m128)m_data[4].hkReferencedObject;
          v18 = (__m128)m_data[2].hkReferencedObject;
          v19 = *(__m128 *)&m_data[2].m_userData;
          v20 = *(__m128 *)&m_data[4].m_userData;
          v21 = *(__m128 *)&m_data[5].m_memSizeAndFlags;
          pivotB.m_rotation.m_col2 = *(hkVector4f *)&m_data[3].m_memSizeAndFlags;
          v22.m_quad = (__m128)m_data[6].hkReferencedObject;
          pivotB.m_translation = (hkVector4f)v17.m_quad;
          v23.m_quad = *(__m128 *)&m_data[6].m_userData;
          pivotA.m_rotation.m_col2 = (hkVector4f)v22.m_quad;
          pivotB.m_rotation.m_col0.m_quad = v18;
          pivotA.m_translation = (hkVector4f)v23.m_quad;
          pivotB.m_rotation.m_col1.m_quad = v19;
          pivotA.m_rotation.m_col0.m_quad = v20;
          pivotA.m_rotation.m_col1.m_quad = v21;
          steeringAxisB.m_quad = v18;
          planeNormalB.m_quad = v20;
          axisA.m_quad = v19;
          b.m_quad = v21;
          hkVector4f::setTransformedPos(&pivotA.m_translation, transformation, &pivotA.m_translation);
          hkVector4f::setRotatedDir(&planeNormalB, &transformation->m_rotation, &planeNormalB);
          hkVector4f::setRotatedDir(&b, &transformation->m_rotation, &b);
          hkpLimitedHingeConstraintData::setInBodySpace(
            (hkpLimitedHingeConstraintData *)m_data,
            &pivotB.m_translation,
            &pivotA.m_translation,
            &steeringAxisB,
            &planeNormalB,
            &axisA,
            &b);
          return;
        case 6u:
          v26 = (__m128)m_data[2].hkReferencedObject;
          v27 = *(__m128 *)&m_data[2].m_userData;
          v28 = (__m128)m_data[4].hkReferencedObject;
          v29 = *(__m128 *)&m_data[4].m_userData;
          v30 = *(__m128 *)&m_data[5].m_memSizeAndFlags;
          v31 = *(__m128 *)&m_data[6].m_userData;
          pivotB.m_rotation.m_col2 = *(hkVector4f *)&m_data[3].m_memSizeAndFlags;
          pivotB.m_rotation.m_col2 = (hkVector4f)m_data[6].hkReferencedObject;
          v57.m_quad = v26;
          axisA.m_quad = v27;
          axleA.m_quad = v28;
          b.m_quad = v29;
          planeNormalB.m_quad = v30;
          steeringAxisB.m_quad = v31;
          hkVector4f::setTransformedPos(&steeringAxisB, transformation, &steeringAxisB);
          hkVector4f::setRotatedDir(&b, &transformation->m_rotation, &b);
          hkVector4f::setRotatedDir(&planeNormalB, &transformation->m_rotation, &planeNormalB);
          hkpPrismaticConstraintData::setInBodySpace(
            (hkpPrismaticConstraintData *)m_data,
            &axleA,
            &steeringAxisB,
            &v57,
            &b,
            &axisA,
            &planeNormalB);
          return;
        case 7u:
          v32.m_quad = *(__m128 *)&m_data[2].m_userData;
          pivotB.m_rotation.m_col0 = (hkVector4f)m_data[2].hkReferencedObject;
          v33.m_quad = *(__m128 *)&m_data[3].m_memSizeAndFlags;
          pivotB.m_rotation.m_col1 = (hkVector4f)v32.m_quad;
          v34.m_quad = (__m128)m_data[4].hkReferencedObject;
          pivotB.m_rotation.m_col2 = (hkVector4f)v33.m_quad;
          v35.m_quad = *(__m128 *)&m_data[4].m_userData;
          pivotB.m_translation = (hkVector4f)v34.m_quad;
          v36.m_quad = *(__m128 *)&m_data[5].m_memSizeAndFlags;
          pivotA.m_rotation.m_col0 = (hkVector4f)v35.m_quad;
          v37.m_quad = (__m128)m_data[6].hkReferencedObject;
          pivotA.m_rotation.m_col1 = (hkVector4f)v36.m_quad;
          v38.m_quad = *(__m128 *)&m_data[6].m_userData;
          pivotA.m_rotation.m_col2 = (hkVector4f)v37.m_quad;
          pivotA.m_translation = (hkVector4f)v38.m_quad;
          hkVector4f::setTransformedPos(&pivotA.m_translation, transformation, &pivotA.m_translation);
          hkVector4f::setRotatedDir(
            (hkVector4f *)&m_data[5].m_memSizeAndFlags,
            &transformation->m_rotation,
            (hkVector4f *)&m_data[5].m_memSizeAndFlags);
          hkVector4f::setRotatedDir(
            (hkVector4f *)&m_data[4].m_userData,
            &transformation->m_rotation,
            (hkVector4f *)&m_data[4].m_userData);
          hkpRagdollConstraintData::setInBodySpace(
            (hkpRagdollConstraintData *)m_data,
            &pivotB.m_translation,
            &pivotA.m_translation,
            (hkVector4f *)&m_data[2].m_userData,
            (hkVector4f *)&m_data[5].m_memSizeAndFlags,
            (hkVector4f *)&m_data[2],
            (hkVector4f *)&m_data[4].m_userData);
          return;
        case 8u:
          vfptr_high = HIDWORD(m_data[4].vfptr);
          v40 = m_data[2].hkReferencedObject;
          steeringAxisB.m_quad = *(__m128 *)&m_data[2].m_userData;
          hkVector4f::setTransformedPos(&steeringAxisB, transformation, &steeringAxisB);
          HIDWORD(m_data[4].vfptr) = vfptr_high;
          *(_DWORD *)&m_data[4].m_memSizeAndFlags = vfptr_high;
          m_quad = steeringAxisB.m_quad;
          m_data[2].hkReferencedObject = v40;
          *(__m128 *)&m_data[2].m_userData = m_quad;
          return;
        case 9u:
          v42.m_quad = *(__m128 *)&m_data[2].m_userData;
          v43 = (__m128)m_data[4].hkReferencedObject;
          pivotB.m_rotation.m_col0 = (hkVector4f)m_data[2].hkReferencedObject;
          v44.m_quad = *(__m128 *)&m_data[3].m_memSizeAndFlags;
          pivotB.m_rotation.m_col1 = (hkVector4f)v42.m_quad;
          v45.m_quad = *(__m128 *)&m_data[5].m_memSizeAndFlags;
          pivotB.m_rotation.m_col2 = (hkVector4f)v44.m_quad;
          pivotB.m_rotation.m_col0 = *(hkVector4f *)&m_data[4].m_userData;
          v46.m_quad = (__m128)m_data[6].hkReferencedObject;
          pivotB.m_rotation.m_col1 = (hkVector4f)v45.m_quad;
          v47 = *(__m128 *)&m_data[6].m_userData;
          pivotB.m_rotation.m_col2 = (hkVector4f)v46.m_quad;
          planeNormalB.m_quad = *(__m128 *)&m_data[4].m_userData;
          v48 = *(__m128 *)&m_data[12].m_userData;
          axisA.m_quad = v47;
          v49 = *(__m128 *)&m_data[10].m_userData;
          b.m_quad = v48;
          v57.m_quad = v43;
          axleA.m_quad = v49;
          hkVector4f::setTransformedPos(&axisA, transformation, &axisA);
          steeringAxisB.m_quad = *(__m128 *)&m_data[13].m_memSizeAndFlags;
          hkVector4f::setRotatedDir(&planeNormalB, &transformation->m_rotation, &planeNormalB);
          hkVector4f::setRotatedDir(&b, &transformation->m_rotation, &b);
          hkVector4f::setRotatedDir(&steeringAxisB, &transformation->m_rotation, &steeringAxisB);
          hkpWheelConstraintData::setInBodySpace(
            (hkpWheelConstraintData *)m_data,
            &v57,
            &axisA,
            &axleA,
            &b,
            &planeNormalB,
            &steeringAxisB);
          return;
        case 0xCu:
          m_data = (hkpConstraintData *)m_data[2].m_userData;
          goto LABEL_6;
        case 0xDu:
          m_data = hkpMalleableConstraintData::getWrappedConstraintData((hkpMalleableConstraintData *)m_data);
LABEL_6:
          v5 = ((__int64 (__fastcall *)(hkpConstraintData *))m_data->vfptr[1].__first_virtual_table_function__)(m_data);
          if ( v5 > 0x18 )
            return;
          continue;
        case 0xEu:
          v24 = *(__m128 *)&m_data[6].m_userData;
          v25 = LOBYTE(m_data[7].m_referenceCount) + 7i64;
          axisA.m_quad = (__m128)m_data[4].hkReferencedObject;
          b.m_quad = v24;
          planeNormalB.m_quad = (__m128)*((_OWORD *)&m_data->hkReferencedObject + v25);
          hkVector4f::setTransformedPos(&b, transformation, &b);
          hkVector4f::setRotatedDir(&planeNormalB, &transformation->m_rotation, &planeNormalB);
          hkpPointToPlaneConstraintData::setInBodySpace(
            (hkpPointToPlaneConstraintData *)m_data,
            &axisA,
            &b,
            &planeNormalB);
          return;
        case 0x17u:
          v6.m_quad = *(__m128 *)&m_data[2].m_userData;
          pivotA.m_rotation.m_col0 = (hkVector4f)m_data[2].hkReferencedObject;
          v7.m_quad = *(__m128 *)&m_data[3].m_memSizeAndFlags;
          pivotA.m_rotation.m_col1 = (hkVector4f)v6.m_quad;
          v8.m_quad = (__m128)m_data[4].hkReferencedObject;
          pivotA.m_rotation.m_col2 = (hkVector4f)v7.m_quad;
          pivotA.m_translation = (hkVector4f)v8.m_quad;
          hkTransformf::setMul(&pivotB, transformation, (hkTransformf *)&m_data[4].m_userData);
          hkpFixedConstraintData::setInBodySpace((hkpFixedConstraintData *)m_data, &pivotA, &pivotB);
          return;
        case 0x18u:
          v9.m_quad = *(__m128 *)&m_data[2].m_userData;
          pivotA.m_rotation.m_col0 = (hkVector4f)m_data[2].hkReferencedObject;
          v10.m_quad = *(__m128 *)&m_data[3].m_memSizeAndFlags;
          pivotA.m_rotation.m_col1 = (hkVector4f)v9.m_quad;
          v11.m_quad = (__m128)m_data[4].hkReferencedObject;
          pivotA.m_rotation.m_col2 = (hkVector4f)v10.m_quad;
          pivotA.m_translation = (hkVector4f)v11.m_quad;
          hkTransformf::setMul(&pivotB, transformation, (hkTransformf *)&m_data[4].m_userData);
          hkpDeformableFixedConstraintData::setInBodySpace((hkpDeformableFixedConstraintData *)m_data, &pivotA, &pivotB);
          return;
        default:
          return;
      }
    }
  }
}

// File Line: 429
// RVA: 0xD60390
void __fastcall hkpConstraintInstance::pointNullsToFixedRigidBody(hkpConstraintInstance *this)
{
  hkpEntity **m_entities; // rbx
  __int64 v3; // rdi
  __int64 v4; // rcx
  hkReferencedObject *v5; // rcx

  m_entities = this->m_entities;
  v3 = 2i64;
  do
  {
    if ( !*m_entities && this->m_entities[0] != this->m_entities[1] )
    {
      v4 = *(_QWORD *)(((__int64)this->m_entities[0] ^ (__int64)this->m_entities[1]) + 0x10);
      if ( v4 )
      {
        v5 = *(hkReferencedObject **)(v4 + 56);
        *m_entities = (hkpEntity *)v5;
        hkReferencedObject::addReference(v5);
      }
    }
    ++m_entities;
    --v3;
  }
  while ( v3 );
}

// File Line: 447
// RVA: 0xD5F980
hkBool *__fastcall hkpConstraintInstance::isConstrainedToWorld(hkpConstraintInstance *this, hkBool *result)
{
  hkpEntity *v2; // r8
  hkpWorld *m_world; // rcx

  v2 = this->m_entities[1];
  if ( !v2 || (m_world = this->m_entities[0]->m_world) != 0i64 && v2 == m_world->m_fixedRigidBody )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 452
// RVA: 0xD5F9D0
void __fastcall hkpConstraintInstance::getPivotsInWorld(
        hkpConstraintInstance *this,
        hkVector4f *pivotAinW,
        hkVector4f *pivotBinW)
{
  __m128 *PivotA; // rax
  hkpConstraintData *m_data; // rcx
  hkVector4f *PivotB; // rax
  hkpEntity *v9; // rdx
  __m128 m_quad; // xmm0
  hkpEntity *v11; // rax
  hkTransformf *m_motion; // rbx
  hkVector4f b; // [rsp+20h] [rbp-28h] BYREF
  hkVector4f v14; // [rsp+30h] [rbp-18h] BYREF

  PivotA = (__m128 *)hkpConstraintDataUtils::getPivotA(this->m_data);
  m_data = this->m_data;
  b.m_quad = *PivotA;
  PivotB = hkpConstraintDataUtils::getPivotB(m_data);
  v9 = this->m_entities[0];
  m_quad = PivotB->m_quad;
  v11 = this->m_entities[1];
  v14.m_quad = m_quad;
  m_motion = (hkTransformf *)v11->m_collidable.m_motion;
  hkVector4f::setTransformedPos(pivotAinW, (hkTransformf *)v9->m_collidable.m_motion, &b);
  hkVector4f::setTransformedPos(pivotBinW, m_motion, &v14);
}

// File Line: 465
// RVA: 0xD60210
void __fastcall hkpConstraintInstance::setVirtualMassInverse(
        hkpConstraintInstance *this,
        hkVector4f *invMassA,
        hkVector4f *invMassB)
{
  hkVector4f *Modifier; // rax
  _QWORD **Value; // rax
  __int64 v8; // rax

  Modifier = (hkVector4f *)hkpWorldConstraintUtil::findModifier(this, TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR|0x18);
  if ( Modifier )
  {
    Modifier[3] = (hkVector4f)invMassA->m_quad;
    Modifier[4] = (hkVector4f)invMassB->m_quad;
  }
  else
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
    if ( v8 )
    {
      *(_WORD *)v8 = 31;
      *(_WORD *)(v8 + 16) = 80;
    }
    *(hkVector4f *)(v8 + 48) = (hkVector4f)invMassA->m_quad;
    *(hkVector4f *)(v8 + 64) = (hkVector4f)invMassB->m_quad;
    hkpWorldConstraintUtil::addModifier(this, this->m_owner, (hkpModifierConstraintAtom *)v8);
  }
}

// File Line: 484
// RVA: 0xD602D0
void __fastcall hkpConstraintInstance::enable(hkpConstraintInstance *this)
{
  hkpResponseModifier::enableConstraint(this, this->m_owner);
}

// File Line: 490
// RVA: 0xD602C0
void __fastcall hkpConstraintInstance::disable(hkpConstraintInstance *this)
{
  hkpResponseModifier::disableConstraint(this, this->m_owner);
}

// File Line: 496
// RVA: 0xD602E0
void __fastcall hkpConstraintInstance::setEnabled(hkpConstraintInstance *this, hkBool state)
{
  if ( state.m_bool )
    hkpConstraintInstance::enable(this);
  else
    hkpConstraintInstance::disable(this);
}

// File Line: 508
// RVA: 0xD60310
hkBool *__fastcall hkpConstraintInstance::isEnabled(hkpConstraintInstance *this, hkBool *result)
{
  result->m_bool = hkpWorldConstraintUtil::findModifier(this, (hkpConstraintAtom::AtomType)34) == 0i64;
  return result;
}

// File Line: 513
// RVA: 0xD5F920
void __fastcall hkpConstraintInstance::replaceEntity(
        hkpConstraintInstance *this,
        hkpEntity *oldEntity,
        hkpEntity *newEntity)
{
  BOOL v6; // esi

  v6 = oldEntity != this->m_entities[0];
  hkReferencedObject::addReference(newEntity);
  if ( oldEntity )
    hkReferencedObject::removeReference(oldEntity);
  this->m_entities[v6] = newEntity;
}

// File Line: 529
// RVA: 0xD60400
void __fastcall hkpConstraintInstance::setFixedRigidBodyPointersToZero(hkpConstraintInstance *this, hkpWorld *world)
{
  hkReferencedObject **m_entities; // rbx
  __int64 v4; // rdi

  m_entities = this->m_entities;
  v4 = 2i64;
  do
  {
    if ( *m_entities == world->m_fixedRigidBody )
    {
      hkReferencedObject::removeReference(*m_entities);
      *m_entities = 0i64;
    }
    ++m_entities;
    --v4;
  }
  while ( v4 );
}

