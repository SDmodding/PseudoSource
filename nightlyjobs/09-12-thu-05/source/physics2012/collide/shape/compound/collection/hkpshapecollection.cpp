// File Line: 23
// RVA: 0xD096E0
void __fastcall hkpShapeCollection::hkpShapeCollection(
        hkpShapeCollection *this,
        hkcdShapeType::ShapeTypeEnum type,
        hkpShapeCollection::CollectionType subType)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type.m_storage = type;
  *(_WORD *)&this->m_dispatchType.m_storage = 4;
  this->m_shapeInfoCodecType.m_storage = 0;
  this->m_userData = 0i64;
  this->hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpShapeCollection::`vftable{for `hkpShape};
  this->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpShapeCollection::`vftable{for `hkpShapeContainer};
  this->m_disableWelding.m_bool = 0;
  this->m_collectionType.m_storage = subType;
}

// File Line: 33
// RVA: 0xD09730
void __fastcall hkpShapeCollection::hkpShapeCollection(hkpShapeCollection *this, hkFinishLoadedObjectFlag flag)
{
  hkpShape::hkpShape(this, flag);
  this->hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpShapeCollection::`vftable{for `hkpShape};
  this->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpShapeCollection::`vftable{for `hkpShapeContainer};
  if ( flag.m_finishing )
  {
    this->m_type.m_storage = 18;
    this->m_collectionType.m_storage = 3;
  }
}

// File Line: 42
// RVA: 0xD098D0
hkBool *__fastcall hkpShapeCollection::castRay(
        hkpShapeCollection *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // rax
  unsigned __int64 v9; // rdx
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  unsigned int v14; // esi
  hkpShapeContainer *v15; // rbx
  unsigned int j; // edi
  __int64 v17; // rax
  hkpShapeContainerVtbl *vfptr; // rax
  hkpShapeContainer *v19; // rdi
  unsigned int i; // ebx
  __int64 v21; // rax
  _QWORD *v22; // rax
  _QWORD *v23; // rcx
  _QWORD *v24; // r8
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  char v28[512]; // [rsp+30h] [rbp-228h] BYREF
  char v29; // [rsp+268h] [rbp+10h] BYREF
  char v30; // [rsp+270h] [rbp+18h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtrcShpCollect";
    v12 = __rdtsc();
    v9 = (unsigned __int64)HIDWORD(v12) << 32;
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  ++results->m_shapeKeyIndex;
  v14 = -1;
  if ( input->m_rayShapeCollectionFilter )
  {
    vfptr = this->hkpShapeContainer::vfptr;
    v19 = &this->hkpShapeContainer;
    for ( i = ((__int64 (__fastcall *)(hkpShapeContainer *, unsigned __int64, _QWORD *))vfptr->getFirstKey)(
                v19,
                v9,
                v11); i != -1; i = v19->vfptr->getNextKey(v19, i) )
    {
      if ( *(_BYTE *)input->m_rayShapeCollectionFilter->vfptr->isCollisionEnabled(
                       input->m_rayShapeCollectionFilter,
                       (hkBool *)&v29,
                       input,
                       v19,
                       i) )
      {
        v21 = (__int64)v19->vfptr->getChildShape(v19, i, (char (*)[512])v28);
        if ( *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))(*(_QWORD *)v21 + 40i64))(
                         v21,
                         &v30,
                         input,
                         results) )
          v14 = i;
      }
    }
  }
  else
  {
    v15 = &this->hkpShapeContainer;
    for ( j = ((__int64 (__fastcall *)(hkpShapeContainer *, unsigned __int64, _QWORD *))this->hkpShapeContainer::vfptr->getFirstKey)(
                &this->hkpShapeContainer,
                v9,
                v11); j != -1; j = v15->vfptr->getNextKey(v15, j) )
    {
      v17 = (__int64)v15->vfptr->getChildShape(v15, j, (char (*)[512])v28);
      if ( *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))(*(_QWORD *)v17 + 40i64))(
                       v17,
                       &v29,
                       input,
                       results) )
        v14 = j;
    }
  }
  --results->m_shapeKeyIndex;
  if ( v14 != -1 )
    results->m_shapeKeys[results->m_shapeKeyIndex] = v14;
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  v24 = v22;
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v25 = __rdtsc();
    v26 = v23 + 2;
    *((_DWORD *)v26 - 2) = v25;
    v24[1] = v26;
  }
  result->m_bool = v14 != -1;
  return result;
}

// File Line: 87
// RVA: 0xD09780
void __fastcall hkpShapeCollection::getAabb(
        hkpShapeCollection *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  unsigned __int64 v7; // rdx
  _QWORD *Value; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkpShapeContainer *v12; // rdi
  unsigned int i; // esi
  hkpShape *v14; // rax
  hkVector4f v15; // xmm1
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  __m128 v20[2]; // [rsp+20h] [rbp-238h] BYREF
  char v21[512]; // [rsp+40h] [rbp-218h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TthkpShapeCollection::getAabb";
    v10 = __rdtsc();
    v7 = (unsigned __int64)HIDWORD(v10) << 32;
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  out->m_min = (hkVector4f)xmmword_141A712A0;
  v12 = &this->hkpShapeContainer;
  out->m_max.m_quad = _mm_xor_ps(
                        (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                        out->m_min.m_quad);
  for ( i = ((__int64 (__fastcall *)(hkpShapeContainer *, unsigned __int64, LPVOID))v12->vfptr->getFirstKey)(
              v12,
              v7,
              Value); i != -1; i = v12->vfptr->getNextKey(v12, i) )
  {
    v14 = v12->vfptr->getChildShape(v12, i, (char (*)[512])v21);
    ((void (__fastcall *)(hkpShape *, hkTransformf *, hkBaseObjectVtbl *, __m128 *))v14->vfptr[2].__vecDelDtor)(
      v14,
      localToWorld,
      v14->vfptr,
      v20);
    v15.m_quad = _mm_max_ps(out->m_max.m_quad, v20[1]);
    out->m_min.m_quad = _mm_min_ps(out->m_min.m_quad, v20[0]);
    out->m_max = (hkVector4f)v15.m_quad;
  }
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v18 = __rdtsc();
    v19 = v17 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v16[1] = v19;
  }
}

// File Line: 106
// RVA: 0xD09C90
float __fastcall hkpShapeCollection::getMaximumProjection(hkpShapeCollection *this, hkVector4f *direction)
{
  _QWORD *Value; // rax
  unsigned __int64 v5; // rdx
  _QWORD *v6; // rcx
  _QWORD *v7; // r8
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpShapeContainerVtbl *vfptr; // rax
  float v11; // xmm6_4
  hkpShapeContainer *v12; // rbx
  unsigned int i; // edi
  __int64 v14; // rax
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  float result; // xmm0_4
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  char v20[512]; // [rsp+20h] [rbp-218h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = (_QWORD *)Value[1];
  v7 = Value;
  if ( (unsigned __int64)v6 < Value[3] )
  {
    *v6 = "TthkpShapeCollection::getMaximumProjection";
    v8 = __rdtsc();
    v5 = (unsigned __int64)HIDWORD(v8) << 32;
    v9 = v6 + 2;
    *((_DWORD *)v9 - 2) = v8;
    v7[1] = v9;
  }
  vfptr = this->hkpShapeContainer::vfptr;
  v11 = FLOAT_N3_40282e38;
  v12 = &this->hkpShapeContainer;
  for ( i = ((__int64 (__fastcall *)(hkpShapeContainer *, unsigned __int64, _QWORD *))vfptr->getFirstKey)(v12, v5, v7);
        i != -1;
        i = v12->vfptr->getNextKey(v12, i) )
  {
    v14 = (__int64)v12->vfptr->getChildShape(v12, i, (char (*)[512])v20);
    v11 = fmaxf(v11, (*(float (__fastcall **)(__int64, hkVector4f *))(*(_QWORD *)v14 + 120i64))(v14, direction));
  }
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  result = v11;
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v18 = __rdtsc();
    v19 = v16 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v15[1] = v19;
  }
  return result;
}

// File Line: 123
// RVA: 0xD09AB0
void __fastcall hkpShapeCollection::castRayWithCollector(
        hkpShapeCollection *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  unsigned __int64 v8; // rdx
  _QWORD *Value; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkpShapeContainer *v13; // rbx
  unsigned int j; // edi
  __int64 v15; // rax
  const void *v16; // rcx
  hkpShapeContainerVtbl *vfptr; // rax
  hkpShapeContainer *v18; // rdi
  unsigned int i; // ebx
  __int64 v20; // rax
  const void *m_motion; // rcx
  _QWORD *v22; // rax
  _QWORD *v23; // rcx
  _QWORD *v24; // r8
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  __int64 v27; // [rsp+30h] [rbp-238h] BYREF
  unsigned int v28; // [rsp+38h] [rbp-230h]
  const void *v29; // [rsp+40h] [rbp-228h]
  hkpCdBody *v30; // [rsp+48h] [rbp-220h]
  char v31[512]; // [rsp+50h] [rbp-218h] BYREF
  char v32; // [rsp+278h] [rbp+10h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtrcShpCollect";
    v11 = __rdtsc();
    v8 = (unsigned __int64)HIDWORD(v11) << 32;
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    Value[1] = v12;
  }
  if ( input->m_rayShapeCollectionFilter )
  {
    vfptr = this->hkpShapeContainer::vfptr;
    v18 = &this->hkpShapeContainer;
    for ( i = ((__int64 (__fastcall *)(hkpShapeContainer *, unsigned __int64, LPVOID))vfptr->getFirstKey)(
                v18,
                v8,
                Value); i != -1; i = v18->vfptr->getNextKey(v18, i) )
    {
      if ( *(_BYTE *)input->m_rayShapeCollectionFilter->vfptr->isCollisionEnabled(
                       input->m_rayShapeCollectionFilter,
                       (hkBool *)&v32,
                       input,
                       v18,
                       i) )
      {
        v20 = (__int64)v18->vfptr->getChildShape(v18, i, (char (*)[512])v31);
        m_motion = cdBody->m_motion;
        v30 = cdBody;
        v29 = m_motion;
        v27 = v20;
        v28 = i;
        (*(void (__fastcall **)(__int64, hkpShapeRayCastInput *, __int64 *, hkpRayHitCollector *))(*(_QWORD *)v20 + 48i64))(
          v20,
          input,
          &v27,
          collector);
      }
    }
  }
  else
  {
    v13 = &this->hkpShapeContainer;
    for ( j = ((__int64 (__fastcall *)(hkpShapeContainer *, unsigned __int64, _QWORD *))this->hkpShapeContainer::vfptr->getFirstKey)(
                &this->hkpShapeContainer,
                v8,
                Value); j != -1; j = v13->vfptr->getNextKey(v13, j) )
    {
      v15 = (__int64)v13->vfptr->getChildShape(v13, j, (char (*)[512])v31);
      v16 = cdBody->m_motion;
      v30 = cdBody;
      v29 = v16;
      v27 = v15;
      v28 = j;
      (*(void (__fastcall **)(__int64, hkpShapeRayCastInput *, __int64 *, hkpRayHitCollector *))(*(_QWORD *)v15 + 48i64))(
        v15,
        input,
        &v27,
        collector);
    }
  }
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  v24 = v22;
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v25 = __rdtsc();
    v26 = v23 + 2;
    *((_DWORD *)v26 - 2) = v25;
    v24[1] = v26;
  }
}

// File Line: 158
// RVA: 0xD09DC0
hkpShapeContainer *__fastcall hkpShapeCollection::getContainer(hkpShapeCollection *this)
{
  if ( this )
    return &this->hkpShapeContainer;
  else
    return 0i64;
}

// File Line: 165
// RVA: 0xD09DF0
void __fastcall hkpShapeCollection::setWeldingInfo(hkpShapeCollection *this, unsigned int key, __int16 weldingInfo)
{
  ;
}

// File Line: 170
// RVA: 0xD09DE0
void __fastcall hkpShapeCollection::initWeldingInfo(
        hkpShapeCollection *this,
        hkpWeldingUtility::WeldingType weldingType)
{
  ;
}

