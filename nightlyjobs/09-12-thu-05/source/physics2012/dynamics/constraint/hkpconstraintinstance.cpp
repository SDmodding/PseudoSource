// File Line: 48
// RVA: 0xD5F570
void __fastcall hkpConstraintInstance::hkpConstraintInstance(hkpConstraintInstance *this, hkpEntity *entityA, hkpEntity *entityB, hkpConstraintData *data, hkpConstraintInstance::ConstraintPriority priority)
{
  hkpConstraintInstance *v5; // rsi
  hkpEntity *v6; // rdi
  hkpEntity *v7; // rbx
  hkReferencedObject *v8; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_data = data;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConstraintInstance::`vftable;
  this->m_owner = 0i64;
  this->m_priority.m_storage = priority;
  *(_WORD *)&this->m_wantRuntime.m_bool = 1;
  this->m_listeners.m_data = 0i64;
  *(_DWORD *)&this->m_listeners.m_size = 2147483648;
  v5 = this;
  v6 = entityB;
  v7 = entityA;
  hkStringPtr::hkStringPtr(&this->m_name);
  v5->m_userData = 0i64;
  v5->m_internal = 0i64;
  v5->m_uid = -16;
  v5->m_entities[0] = v7;
  v5->m_entities[1] = v6;
  v5->m_constraintModifiers = 0i64;
  hkReferencedObject::lockAll();
  hkReferencedObject::addReference((hkReferencedObject *)&v5->m_entities[0]->vfptr);
  v8 = (hkReferencedObject *)&v5->m_entities[1]->vfptr;
  if ( v8 )
    hkReferencedObject::addReference(v8);
  hkReferencedObject::addReference((hkReferencedObject *)&v5->m_data->vfptr);
  hkReferencedObject::unlockAll();
}

// File Line: 86
// RVA: 0xD5F8B0
void __fastcall hkpConstraintInstance::hkpConstraintInstance(hkpConstraintInstance *this, hkpConstraintInstance::ConstraintPriority priority)
{
  hkpConstraintInstance *v2; // rbx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConstraintInstance::`vftable;
  this->m_owner = 0i64;
  this->m_constraintModifiers = 0i64;
  this->m_priority.m_storage = priority;
  *(_WORD *)&this->m_wantRuntime.m_bool = 1;
  v2 = this;
  this->m_listeners.m_data = 0i64;
  *(_DWORD *)&this->m_listeners.m_size = 2147483648;
  hkStringPtr::hkStringPtr(&this->m_name);
  v2->m_userData = 0i64;
  v2->m_internal = 0i64;
  v2->m_uid = -16;
}

// File Line: 91
// RVA: 0xD601F0
void __fastcall hkpConstraintInstance::setPriority(hkpConstraintInstance *this, hkpConstraintInstance::ConstraintPriority priority)
{
  hkConstraintInternal *v2; // rax

  v2 = this->m_internal;
  this->m_priority.m_storage = priority;
  if ( v2 )
    v2->m_priority.m_storage = priority;
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
hkStringPtr *__fastcall hkpConstraintInstance::clone(hkpConstraintInstance *this, hkpEntity *newEntityA, hkpEntity *newEntityB, hkpConstraintInstance::CloningMode mode)
{
  hkpEntity *v4; // rbp
  hkpEntity *v5; // rbx
  hkpConstraintInstance *v6; // rdi
  hkpConstraintData *v7; // rsi
  _QWORD **v8; // rax
  hkpConstraintInstance *v9; // rax
  hkStringPtr *v10; // rax
  hkStringPtr *v11; // rbx
  _QWORD **v12; // rax
  hkpConstraintInstance *v13; // rax
  hkStringPtr *v14; // rax
  _QWORD **v15; // rax
  hkpConstraintInstance *v16; // rax
  hkStringPtr *v17; // rax
  hkBool result; // [rsp+58h] [rbp+20h]

  v4 = newEntityB;
  v5 = newEntityA;
  v6 = this;
  if ( mode )
  {
    if ( mode == 1 )
    {
      v7 = hkpConstraintDataUtils::cloneIfCanHaveMotors(this->m_data);
      if ( !v7 )
      {
        v7 = v6->m_data;
        hkReferencedObject::addReference((hkReferencedObject *)&v6->m_data->vfptr);
      }
      v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v13 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(
                                       v12[11],
                                       112i64);
      if ( v13 )
      {
        hkpConstraintInstance::hkpConstraintInstance(
          v13,
          v5,
          v4,
          v7,
          (hkpConstraintInstance::ConstraintPriority)(unsigned __int8)v6->m_priority.m_storage);
        v11 = v14;
        hkReferencedObject::removeReference((hkReferencedObject *)&v7->vfptr);
        goto LABEL_14;
      }
      goto LABEL_10;
    }
  }
  else if ( hkpConstraintInstance::isConstrainedToWorld(this, &result)->m_bool )
  {
    v7 = hkpConstraintDataCloningUtil::deepClone(v6->m_data);
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 112i64);
    if ( v9 )
    {
      hkpConstraintInstance::hkpConstraintInstance(
        v9,
        v5,
        0i64,
        v7,
        (hkpConstraintInstance::ConstraintPriority)(unsigned __int8)v6->m_priority.m_storage);
      v11 = v10;
      hkReferencedObject::removeReference((hkReferencedObject *)&v7->vfptr);
      goto LABEL_14;
    }
LABEL_10:
    v11 = 0i64;
    hkReferencedObject::removeReference((hkReferencedObject *)&v7->vfptr);
    goto LABEL_14;
  }
  v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(
                                   v15[11],
                                   112i64);
  if ( v16 )
  {
    hkpConstraintInstance::hkpConstraintInstance(
      v16,
      v5,
      v4,
      v6->m_data,
      (hkpConstraintInstance::ConstraintPriority)(unsigned __int8)v6->m_priority.m_storage);
    v11 = v17;
  }
  else
  {
    v11 = 0i64;
  }
LABEL_14:
  hkStringPtr::operator=(v11 + 10, (const char *)((_QWORD)v6->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
  return v11;
}

// File Line: 178
// RVA: 0xD5F630
void __fastcall hkpConstraintInstance::~hkpConstraintInstance(hkpConstraintInstance *this)
{
  hkpConstraintInstance *v1; // r14
  hkReferencedObject *v2; // rcx
  hkReferencedObject *v3; // rcx
  hkpModifierConstraintAtom *v4; // rsi
  hkpModifierConstraintAtom *v5; // rdi
  unsigned int v6; // ebx
  _QWORD **v7; // rax
  hkReferencedObject *v8; // rcx
  unsigned __int16 v9; // di
  hkpConstraintListener **v10; // rbx
  _QWORD **v11; // rax

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConstraintInstance::`vftable;
  hkpConstraintCallbackUtil::fireConstraintDeleted(this);
  v2 = (hkReferencedObject *)&v1->m_entities[0]->vfptr;
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  v3 = (hkReferencedObject *)&v1->m_entities[1]->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v4 = v1->m_constraintModifiers;
  if ( v4 && v4->m_type.m_storage >= 0x1Eu )
  {
    do
    {
      v5 = v4;
      v4 = (hkpModifierConstraintAtom *)v4->m_child;
      v6 = v5->m_modifierAtomSize;
      v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpModifierConstraintAtom *, _QWORD))(*v7[11] + 16i64))(v7[11], v5, v6);
    }
    while ( v4->m_type.m_storage >= 0x1Eu );
  }
  v8 = (hkReferencedObject *)&v1->m_data->vfptr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  hkStringPtr::~hkStringPtr(&v1->m_name);
  v9 = v1->m_listeners.m_capacityAndFlags;
  if ( (v9 & 0x8000u) == 0 )
  {
    v10 = v1->m_listeners.m_data;
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpConstraintListener **, _QWORD))(*v11[11] + 16i64))(
      v11[11],
      v10,
      8 * (v9 & 0x3FFFu));
  }
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 219
// RVA: 0xD5FA60
void __fastcall hkpConstraintInstance::addConstraintListener(hkpConstraintInstance *this, hkpConstraintListener *listener)
{
  int v2; // er8
  hkSmallArray<hkpConstraintListener *> *v3; // rbx
  int v4; // eax
  hkpConstraintListener *v5; // rdi
  hkpConstraintListener **v6; // rcx

  v2 = this->m_listeners.m_size;
  v3 = &this->m_listeners;
  v4 = 0;
  v5 = listener;
  if ( v2 <= 0 )
    goto LABEL_5;
  v6 = v3->m_data;
  while ( *v6 )
  {
    ++v4;
    ++v6;
    if ( v4 >= v2 )
      goto LABEL_5;
  }
  if ( v4 < 0 )
  {
LABEL_5:
    if ( (_WORD)v2 == (v3->m_capacityAndFlags & 0x3FFF) )
      hkSmallArrayUtil::_reserveMore(v3, 8);
    v3->m_data[v3->m_size++] = v5;
  }
  else
  {
    v3->m_data[v4] = listener;
  }
}

// File Line: 235
// RVA: 0xD5FAF0
void __fastcall hkpConstraintInstance::removeConstraintListener(hkpConstraintInstance *this, hkpConstraintListener *listener)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpConstraintListener **v5; // rax

  v2 = this->m_listeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_listeners.m_data;
    while ( *v5 != listener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_listeners.m_data[v3] = 0i64;
}

// File Line: 243
// RVA: 0xD5FB40
void __fastcall hkpConstraintInstance::transform(hkpConstraintInstance *this, hkTransformf *transformation)
{
  hkTransformf *v2; // r15
  hkpConstraintInstance *v3; // r14
  hkVector4f *v4; // r14
  unsigned int v5; // eax
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  hkVector4f v9; // xmm1
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm1
  hkVector4f v12; // xmm1
  hkVector4f v13; // xmm3
  hkVector4f v14; // xmm2
  hkVector4f v15; // xmm0
  hkVector4f v16; // xmm1
  hkVector4f v17; // xmm1
  hkVector4f v18; // xmm4
  hkVector4f v19; // xmm5
  hkVector4f v20; // xmm2
  hkVector4f v21; // xmm3
  hkVector4f v22; // xmm0
  hkVector4f v23; // xmm1
  __m128i v24; // xmm1
  signed __int64 v25; // rcx
  __m128i v26; // xmm5
  __m128i v27; // xmm6
  __m128i v28; // xmm4
  __m128i v29; // xmm2
  __m128i v30; // xmm3
  __m128i v31; // xmm1
  hkVector4f v32; // xmm1
  hkVector4f v33; // xmm0
  hkVector4f v34; // xmm1
  hkVector4f v35; // xmm0
  hkVector4f v36; // xmm1
  hkVector4f v37; // xmm0
  hkVector4f v38; // xmm1
  int v39; // xmm6_4
  hkVector4f v40; // xmm7
  __m128 v41; // xmm0
  hkVector4f v42; // xmm1
  __m128i v43; // xmm2
  hkVector4f v44; // xmm0
  hkVector4f v45; // xmm1
  hkVector4f v46; // xmm0
  __m128i v47; // xmm1
  __m128i v48; // xmm0
  __m128i v49; // xmm1
  hkVector4f b; // [rsp+40h] [rbp-C0h]
  hkVector4f planeNormalB; // [rsp+50h] [rbp-B0h]
  hkVector4f steeringAxisB; // [rsp+60h] [rbp-A0h]
  hkVector4f axisA; // [rsp+70h] [rbp-90h]
  hkTransformf pivotA; // [rsp+80h] [rbp-80h]
  hkTransformf pivotB; // [rsp+C0h] [rbp-40h]
  hkVector4f axleA; // [rsp+100h] [rbp+0h]
  hkVector4f v57; // [rsp+110h] [rbp+10h]
  hkBool result; // [rsp+170h] [rbp+70h]

  v2 = transformation;
  v3 = this;
  if ( hkpConstraintInstance::isConstrainedToWorld(this, &result)->m_bool )
  {
    v4 = (hkVector4f *)v3->m_data;
    v5 = (*(__int64 (__fastcall **)(hkVector4f *))(v4->m_quad.m128_u64[0] + 24))(v4);
    while ( 2 )
    {
      switch ( v5 )
      {
        case 0u:
          hkVector4f::setTransformedPos(v4 + 4, v2, v4 + 4);
          hkpBallAndSocketConstraintData::setInBodySpace((hkpBallAndSocketConstraintData *)v4, v4 + 3, v4 + 4);
          return;
        case 1u:
          v12.m_quad = (__m128)v4[5];
          v13.m_quad = (__m128)v4[3];
          v14.m_quad = (__m128)v4[7];
          pivotB.m_rotation.m_col1 = (hkVector4f)v4[4].m_quad;
          pivotB.m_translation = (hkVector4f)v4[6].m_quad;
          v15.m_quad = (__m128)v4[8];
          pivotB.m_rotation.m_col2 = (hkVector4f)v12.m_quad;
          v16.m_quad = (__m128)v4[9];
          pivotA.m_rotation.m_col1 = (hkVector4f)v15.m_quad;
          pivotA.m_translation = (hkVector4f)v4[10].m_quad;
          pivotB.m_rotation.m_col0 = (hkVector4f)v13.m_quad;
          pivotA.m_rotation.m_col0 = (hkVector4f)v14.m_quad;
          pivotA.m_rotation.m_col2 = (hkVector4f)v16.m_quad;
          _mm_store_si128((__m128i *)&axisA, (__m128i)v13.m_quad);
          _mm_store_si128((__m128i *)&b, (__m128i)v14.m_quad);
          hkVector4f::setTransformedPos(&pivotA.m_translation, v2, &pivotA.m_translation);
          hkVector4f::setRotatedDir(&b, (hkMatrix3f *)&v2->m_rotation.m_col0, &b);
          hkpHingeConstraintData::setInBodySpace(
            (hkpHingeConstraintData *)v4,
            &pivotB.m_translation,
            &pivotA.m_translation,
            &axisA,
            &b);
          return;
        case 2u:
          v17.m_quad = (__m128)v4[6];
          v18.m_quad = (__m128)v4[3];
          v19.m_quad = (__m128)v4[4];
          v20.m_quad = (__m128)v4[7];
          v21.m_quad = (__m128)v4[8];
          pivotB.m_rotation.m_col2 = (hkVector4f)v4[5].m_quad;
          v22.m_quad = (__m128)v4[9];
          pivotB.m_translation = (hkVector4f)v17.m_quad;
          v23.m_quad = (__m128)v4[10];
          pivotA.m_rotation.m_col2 = (hkVector4f)v22.m_quad;
          pivotB.m_rotation.m_col0 = (hkVector4f)v18.m_quad;
          pivotA.m_translation = (hkVector4f)v23.m_quad;
          pivotB.m_rotation.m_col1 = (hkVector4f)v19.m_quad;
          pivotA.m_rotation.m_col0 = (hkVector4f)v20.m_quad;
          pivotA.m_rotation.m_col1 = (hkVector4f)v21.m_quad;
          _mm_store_si128((__m128i *)&steeringAxisB, (__m128i)v18.m_quad);
          _mm_store_si128((__m128i *)&planeNormalB, (__m128i)v20.m_quad);
          _mm_store_si128((__m128i *)&axisA, (__m128i)v19.m_quad);
          _mm_store_si128((__m128i *)&b, (__m128i)v21.m_quad);
          hkVector4f::setTransformedPos(&pivotA.m_translation, v2, &pivotA.m_translation);
          hkVector4f::setRotatedDir(&planeNormalB, (hkMatrix3f *)&v2->m_rotation.m_col0, &planeNormalB);
          hkVector4f::setRotatedDir(&b, (hkMatrix3f *)&v2->m_rotation.m_col0, &b);
          hkpLimitedHingeConstraintData::setInBodySpace(
            (hkpLimitedHingeConstraintData *)v4,
            &pivotB.m_translation,
            &pivotA.m_translation,
            &steeringAxisB,
            &planeNormalB,
            &axisA,
            &b);
          return;
        case 6u:
          v26 = (__m128i)v4[3];
          v27 = (__m128i)v4[4];
          v28 = (__m128i)v4[6];
          v29 = (__m128i)v4[7];
          v30 = (__m128i)v4[8];
          v31 = (__m128i)v4[10];
          pivotB.m_rotation.m_col2 = (hkVector4f)v4[5].m_quad;
          pivotB.m_rotation.m_col2 = (hkVector4f)v4[9].m_quad;
          _mm_store_si128((__m128i *)&v57, v26);
          _mm_store_si128((__m128i *)&axisA, v27);
          _mm_store_si128((__m128i *)&axleA, v28);
          _mm_store_si128((__m128i *)&b, v29);
          _mm_store_si128((__m128i *)&planeNormalB, v30);
          _mm_store_si128((__m128i *)&steeringAxisB, v31);
          hkVector4f::setTransformedPos(&steeringAxisB, v2, &steeringAxisB);
          hkVector4f::setRotatedDir(&b, (hkMatrix3f *)&v2->m_rotation.m_col0, &b);
          hkVector4f::setRotatedDir(&planeNormalB, (hkMatrix3f *)&v2->m_rotation.m_col0, &planeNormalB);
          hkpPrismaticConstraintData::setInBodySpace(
            (hkpPrismaticConstraintData *)v4,
            &axleA,
            &steeringAxisB,
            &v57,
            &b,
            &axisA,
            &planeNormalB);
          return;
        case 7u:
          v32.m_quad = (__m128)v4[4];
          pivotB.m_rotation.m_col0 = (hkVector4f)v4[3].m_quad;
          v33.m_quad = (__m128)v4[5];
          pivotB.m_rotation.m_col1 = (hkVector4f)v32.m_quad;
          v34.m_quad = (__m128)v4[6];
          pivotB.m_rotation.m_col2 = (hkVector4f)v33.m_quad;
          v35.m_quad = (__m128)v4[7];
          pivotB.m_translation = (hkVector4f)v34.m_quad;
          v36.m_quad = (__m128)v4[8];
          pivotA.m_rotation.m_col0 = (hkVector4f)v35.m_quad;
          v37.m_quad = (__m128)v4[9];
          pivotA.m_rotation.m_col1 = (hkVector4f)v36.m_quad;
          v38.m_quad = (__m128)v4[10];
          pivotA.m_rotation.m_col2 = (hkVector4f)v37.m_quad;
          pivotA.m_translation = (hkVector4f)v38.m_quad;
          hkVector4f::setTransformedPos(&pivotA.m_translation, v2, &pivotA.m_translation);
          hkVector4f::setRotatedDir(v4 + 8, (hkMatrix3f *)&v2->m_rotation.m_col0, v4 + 8);
          hkVector4f::setRotatedDir(v4 + 7, (hkMatrix3f *)&v2->m_rotation.m_col0, v4 + 7);
          hkpRagdollConstraintData::setInBodySpace(
            (hkpRagdollConstraintData *)v4,
            &pivotB.m_translation,
            &pivotA.m_translation,
            v4 + 4,
            v4 + 8,
            v4 + 3,
            v4 + 7);
          return;
        case 8u:
          v39 = v4[6].m_quad.m128_i32[1];
          v40.m_quad = (__m128)v4[3];
          _mm_store_si128((__m128i *)&steeringAxisB, (__m128i)v4[4].m_quad);
          hkVector4f::setTransformedPos(&steeringAxisB, v2, &steeringAxisB);
          v4[6].m_quad.m128_i32[1] = v39;
          v4[6].m_quad.m128_i32[2] = v39;
          v41 = steeringAxisB.m_quad;
          v4[3] = (hkVector4f)v40.m_quad;
          v4[4] = (hkVector4f)v41;
          return;
        case 9u:
          v42.m_quad = (__m128)v4[4];
          v43 = (__m128i)v4[6];
          pivotB.m_rotation.m_col0 = (hkVector4f)v4[3].m_quad;
          v44.m_quad = (__m128)v4[5];
          pivotB.m_rotation.m_col1 = (hkVector4f)v42.m_quad;
          v45.m_quad = (__m128)v4[8];
          pivotB.m_rotation.m_col2 = (hkVector4f)v44.m_quad;
          pivotB.m_rotation.m_col0 = (hkVector4f)v4[7].m_quad;
          v46.m_quad = (__m128)v4[9];
          pivotB.m_rotation.m_col1 = (hkVector4f)v45.m_quad;
          v47 = (__m128i)v4[10];
          pivotB.m_rotation.m_col2 = (hkVector4f)v46.m_quad;
          _mm_store_si128((__m128i *)&planeNormalB, (__m128i)v4[7].m_quad);
          v48 = (__m128i)v4[19];
          _mm_store_si128((__m128i *)&axisA, v47);
          v49 = (__m128i)v4[16];
          _mm_store_si128((__m128i *)&b, v48);
          _mm_store_si128((__m128i *)&v57, v43);
          _mm_store_si128((__m128i *)&axleA, v49);
          hkVector4f::setTransformedPos(&axisA, v2, &axisA);
          _mm_store_si128((__m128i *)&steeringAxisB, (__m128i)v4[20].m_quad);
          hkVector4f::setRotatedDir(&planeNormalB, (hkMatrix3f *)&v2->m_rotation.m_col0, &planeNormalB);
          hkVector4f::setRotatedDir(&b, (hkMatrix3f *)&v2->m_rotation.m_col0, &b);
          hkVector4f::setRotatedDir(&steeringAxisB, (hkMatrix3f *)&v2->m_rotation.m_col0, &steeringAxisB);
          hkpWheelConstraintData::setInBodySpace(
            (hkpWheelConstraintData *)v4,
            &v57,
            &axisA,
            &axleA,
            &b,
            &planeNormalB,
            &steeringAxisB);
          return;
        case 0xCu:
          v4 = (hkVector4f *)v4[4].m_quad.m128_u64[0];
          goto LABEL_6;
        case 0xDu:
          v4 = (hkVector4f *)hkpMalleableConstraintData::getWrappedConstraintData((hkpMalleableConstraintData *)v4);
LABEL_6:
          v5 = (*(__int64 (__fastcall **)(hkVector4f *))(v4->m_quad.m128_u64[0] + 24))(v4);
          if ( v5 > 0x18 )
            return;
          continue;
        case 0xEu:
          v24 = (__m128i)v4[10];
          v25 = (unsigned __int8)v4[11].m_quad.m128_i8[2] + 7i64;
          _mm_store_si128((__m128i *)&axisA, (__m128i)v4[6].m_quad);
          _mm_store_si128((__m128i *)&b, v24);
          _mm_store_si128((__m128i *)&planeNormalB, (__m128i)v4[v25].m_quad);
          hkVector4f::setTransformedPos(&b, v2, &b);
          hkVector4f::setRotatedDir(&planeNormalB, (hkMatrix3f *)&v2->m_rotation.m_col0, &planeNormalB);
          hkpPointToPlaneConstraintData::setInBodySpace((hkpPointToPlaneConstraintData *)v4, &axisA, &b, &planeNormalB);
          break;
        case 0x17u:
          v6.m_quad = (__m128)v4[4];
          pivotA.m_rotation.m_col0 = (hkVector4f)v4[3].m_quad;
          v7.m_quad = (__m128)v4[5];
          pivotA.m_rotation.m_col1 = (hkVector4f)v6.m_quad;
          v8.m_quad = (__m128)v4[6];
          pivotA.m_rotation.m_col2 = (hkVector4f)v7.m_quad;
          pivotA.m_translation = (hkVector4f)v8.m_quad;
          hkTransformf::setMul(&pivotB, v2, (hkTransformf *)&v4[7]);
          hkpFixedConstraintData::setInBodySpace((hkpFixedConstraintData *)v4, &pivotA, &pivotB);
          break;
        case 0x18u:
          v9.m_quad = (__m128)v4[4];
          pivotA.m_rotation.m_col0 = (hkVector4f)v4[3].m_quad;
          v10.m_quad = (__m128)v4[5];
          pivotA.m_rotation.m_col1 = (hkVector4f)v9.m_quad;
          v11.m_quad = (__m128)v4[6];
          pivotA.m_rotation.m_col2 = (hkVector4f)v10.m_quad;
          pivotA.m_translation = (hkVector4f)v11.m_quad;
          hkTransformf::setMul(&pivotB, v2, (hkTransformf *)&v4[7]);
          hkpDeformableFixedConstraintData::setInBodySpace((hkpDeformableFixedConstraintData *)v4, &pivotA, &pivotB);
          break;
        default:
          return;
      }
      break;
    }
  }
}

// File Line: 429
// RVA: 0xD60390
void __fastcall hkpConstraintInstance::pointNullsToFixedRigidBody(hkpConstraintInstance *this)
{
  hkpConstraintInstance *v1; // rsi
  _QWORD *v2; // rbx
  signed __int64 v3; // rdi
  __int64 v4; // rcx
  hkReferencedObject *v5; // rcx

  v1 = this;
  v2 = this->m_entities;
  v3 = 2i64;
  do
  {
    if ( !*v2 && v1->m_entities[0] != v1->m_entities[1] )
    {
      v4 = *(_QWORD *)(((_QWORD)v1->m_entities[0] ^ (_QWORD)v1->m_entities[1]) + 0x10i64);
      if ( v4 )
      {
        v5 = *(hkReferencedObject **)(v4 + 56);
        *v2 = v5;
        hkReferencedObject::addReference(v5);
      }
    }
    ++v2;
    --v3;
  }
  while ( v3 );
}

// File Line: 447
// RVA: 0xD5F980
hkBool *__fastcall hkpConstraintInstance::isConstrainedToWorld(hkpConstraintInstance *this, hkBool *result)
{
  hkpEntity *v2; // r8
  hkpWorld *v3; // rcx
  hkBool *v4; // rax

  v2 = this->m_entities[1];
  if ( !v2 || (v3 = this->m_entities[0]->m_world) != 0i64 && v2 == (hkpEntity *)v3->m_fixedRigidBody )
  {
    result->m_bool = 1;
    v4 = result;
  }
  else
  {
    result->m_bool = 0;
    v4 = result;
  }
  return v4;
}

// File Line: 452
// RVA: 0xD5F9D0
void __fastcall hkpConstraintInstance::getPivotsInWorld(hkpConstraintInstance *this, hkVector4f *pivotAinW, hkVector4f *pivotBinW)
{
  hkpConstraintInstance *v3; // rdi
  hkVector4f *v4; // rbp
  hkVector4f *v5; // rsi
  __m128 *v6; // rax
  hkpConstraintData *v7; // rcx
  hkVector4f *v8; // rax
  hkpEntity *v9; // rdx
  __m128 v10; // xmm0
  hkpEntity *v11; // rax
  hkTransformf *v12; // rbx
  hkVector4f b; // [rsp+20h] [rbp-28h]
  hkVector4f v14; // [rsp+30h] [rbp-18h]

  v3 = this;
  v4 = pivotBinW;
  v5 = pivotAinW;
  v6 = (__m128 *)hkpConstraintDataUtils::getPivotA(this->m_data);
  v7 = v3->m_data;
  b.m_quad = *v6;
  v8 = hkpConstraintDataUtils::getPivotB(v7);
  v9 = v3->m_entities[0];
  v10 = v8->m_quad;
  v11 = v3->m_entities[1];
  v14.m_quad = v10;
  v12 = (hkTransformf *)v11->m_collidable.m_motion;
  hkVector4f::setTransformedPos(v5, (hkTransformf *)v9->m_collidable.m_motion, &b);
  hkVector4f::setTransformedPos(v4, v12, &v14);
}

// File Line: 465
// RVA: 0xD60210
void __fastcall hkpConstraintInstance::setVirtualMassInverse(hkpConstraintInstance *this, hkVector4f *invMassA, hkVector4f *invMassB)
{
  hkVector4f *v3; // rsi
  hkVector4f *v4; // rdi
  hkpConstraintInstance *v5; // rbx
  hkpModifierConstraintAtom *v6; // rax
  _QWORD **v7; // rax
  __int64 v8; // rax

  v3 = invMassA;
  v4 = invMassB;
  v5 = this;
  v6 = hkpWorldConstraintUtil::findModifier(this, TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR|0x18);
  if ( v6 )
  {
    *(hkVector4f *)&v6[1].m_type.m_storage = (hkVector4f)v3->m_quad;
    *(hkVector4f *)&v6[1].m_modifierAtomSize = (hkVector4f)v4->m_quad;
  }
  else
  {
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 80i64);
    if ( v8 )
    {
      *(_WORD *)v8 = 31;
      *(_WORD *)(v8 + 16) = 80;
    }
    *(hkVector4f *)(v8 + 48) = (hkVector4f)v3->m_quad;
    *(hkVector4f *)(v8 + 64) = (hkVector4f)v4->m_quad;
    hkpWorldConstraintUtil::addModifier(v5, v5->m_owner, (hkpModifierConstraintAtom *)v8);
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
  hkBool *v2; // rbx

  v2 = result;
  result->m_bool = hkpWorldConstraintUtil::findModifier(this, (hkpConstraintAtom::AtomType)34) == 0i64;
  return v2;
}

// File Line: 513
// RVA: 0xD5F920
void __fastcall hkpConstraintInstance::replaceEntity(hkpConstraintInstance *this, hkpEntity *oldEntity, hkpEntity *newEntity)
{
  hkpConstraintInstance *v3; // rdi
  hkpEntity *v4; // rbx
  hkpEntity *v5; // rbp
  BOOL v6; // esi

  v3 = this;
  v4 = newEntity;
  v5 = oldEntity;
  v6 = oldEntity != this->m_entities[0];
  hkReferencedObject::addReference((hkReferencedObject *)&newEntity->vfptr);
  if ( v5 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v5->vfptr);
  v3->m_entities[v6] = v4;
}

// File Line: 529
// RVA: 0xD60400
void __fastcall hkpConstraintInstance::setFixedRigidBodyPointersToZero(hkpConstraintInstance *this, hkpWorld *world)
{
  hkpWorld *v2; // rsi
  hkReferencedObject **v3; // rbx
  signed __int64 v4; // rdi

  v2 = world;
  v3 = (hkReferencedObject **)this->m_entities;
  v4 = 2i64;
  do
  {
    if ( *v3 == (hkReferencedObject *)v2->m_fixedRigidBody )
    {
      hkReferencedObject::removeReference(*v3);
      *v3 = 0i64;
    }
    ++v3;
    --v4;
  }
  while ( v4 );
}

