// File Line: 23
// RVA: 0xD096E0
void __fastcall hkpShapeCollection::hkpShapeCollection(hkpShapeCollection *this, hkcdShapeType::ShapeTypeEnum type, hkpShapeCollection::CollectionType subType)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type.m_storage = type;
  *(_WORD *)&this->m_dispatchType.m_storage = 4;
  this->m_shapeInfoCodecType.m_storage = 0;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpShapeCollection::`vftable'{for `hkpShape'};
  this->vfptr = (hkpShapeContainerVtbl *)&hkpShapeCollection::`vftable'{for `hkpShapeContainer'};
  this->m_disableWelding.m_bool = 0;
  this->m_collectionType.m_storage = subType;
}

// File Line: 33
// RVA: 0xD09730
void __fastcall hkpShapeCollection::hkpShapeCollection(hkpShapeCollection *this, hkFinishLoadedObjectFlag flag)
{
  hkpShapeCollection *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = flag.m_finishing;
  v2 = this;
  hkpShape::hkpShape((hkpShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpShapeCollection::`vftable'{for `hkpShape'};
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpShapeCollection::`vftable'{for `hkpShapeContainer'};
  if ( v3 )
  {
    v2->m_type.m_storage = 18;
    v2->m_collectionType.m_storage = 3;
  }
}

// File Line: 42
// RVA: 0xD098D0
hkBool *__fastcall hkpShapeCollection::castRay(hkpShapeCollection *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpShapeCollection *v4; // rdi
  hkpShapeRayCastOutput *v5; // rbp
  hkpShapeRayCastInput *v6; // r14
  hkBool *v7; // r15
  _QWORD *v8; // rax
  unsigned __int64 v9; // rdx
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  signed int v14; // esi
  signed __int64 v15; // rbx
  unsigned int j; // edi
  __int64 v17; // rax
  hkpShapeContainerVtbl *v18; // rax
  signed __int64 v19; // rdi
  unsigned int i; // ebx
  __int64 v21; // rax
  _QWORD *v22; // rax
  _QWORD *v23; // rcx
  _QWORD *v24; // r8
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  _QWORD v28[2]; // [rsp+20h] [rbp-238h]
  char v29; // [rsp+30h] [rbp-228h]
  char v30; // [rsp+268h] [rbp+10h]
  char v31; // [rsp+270h] [rbp+18h]

  v4 = this;
  v5 = results;
  v6 = input;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v8[1];
  v11 = v8;
  if ( (unsigned __int64)v10 < v8[3] )
  {
    *v10 = "TtrcShpCollect";
    v12 = __rdtsc();
    v9 = (unsigned __int64)HIDWORD(v12) << 32;
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  ++v5->m_shapeKeyIndex;
  v14 = -1;
  if ( v6->m_rayShapeCollectionFilter )
  {
    v18 = v4->vfptr;
    v19 = (signed __int64)&v4->vfptr;
    for ( i = ((__int64 (__fastcall *)(signed __int64, unsigned __int64, _QWORD *))v18->getFirstKey)(v19, v9, v11);
          i != -1;
          i = (*(__int64 (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v19 + 24i64))(v19, i) )
    {
      LODWORD(v28[0]) = i;
      if ( *(_BYTE *)v6->m_rayShapeCollectionFilter->vfptr->isCollisionEnabled(
                       v6->m_rayShapeCollectionFilter,
                       (hkBool *)&v30,
                       v6,
                       (hkpShapeContainer *)v19,
                       v28[0]) )
      {
        v21 = (*(__int64 (__fastcall **)(signed __int64, _QWORD, char *))(*(_QWORD *)v19 + 40i64))(v19, i, &v29);
        if ( *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))(*(_QWORD *)v21 + 40i64))(
                         v21,
                         &v31,
                         v6,
                         v5) )
          v14 = i;
      }
    }
  }
  else
  {
    v15 = (signed __int64)&v4->vfptr;
    for ( j = ((__int64 (__fastcall *)(hkpShapeContainerVtbl **, unsigned __int64, _QWORD *))v4->vfptr->getFirstKey)(
                &v4->vfptr,
                v9,
                v11); j != -1; j = (*(__int64 (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v15 + 24i64))(v15, j) )
    {
      v17 = (*(__int64 (__fastcall **)(signed __int64, _QWORD, char *))(*(_QWORD *)v15 + 40i64))(v15, j, &v29);
      if ( *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))(*(_QWORD *)v17 + 40i64))(
                       v17,
                       &v30,
                       v6,
                       v5) )
        v14 = j;
    }
  }
  --v5->m_shapeKeyIndex;
  if ( v14 != -1 )
    v5->m_shapeKeys[v5->m_shapeKeyIndex] = v14;
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  v24 = v22;
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v25 = __rdtsc();
    v26 = (signed __int64)(v23 + 2);
    *(_DWORD *)(v26 - 8) = v25;
    v24[1] = v26;
  }
  v7->m_bool = v14 != -1;
  return v7;
}

// File Line: 87
// RVA: 0xD09780
void __fastcall hkpShapeCollection::getAabb(hkpShapeCollection *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkpShapeCollection *v4; // rdi
  hkAabb *v5; // rbx
  hkTransformf *v6; // rbp
  unsigned __int64 v7; // rdx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  signed __int64 v12; // rdi
  unsigned int i; // esi
  _QWORD *v14; // rax
  __m128 v15; // xmm1
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  __m128 v20; // [rsp+20h] [rbp-238h]
  __m128 v21; // [rsp+30h] [rbp-228h]
  char v22; // [rsp+40h] [rbp-218h]

  v4 = this;
  v5 = out;
  v6 = localToWorld;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TthkpShapeCollection::getAabb";
    v10 = __rdtsc();
    v7 = (unsigned __int64)HIDWORD(v10) << 32;
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v5->m_min = (hkVector4f)xmmword_141A712A0;
  v12 = (signed __int64)&v4->vfptr;
  v5->m_max.m_quad = _mm_xor_ps(
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                       v5->m_min.m_quad);
  for ( i = (*(__int64 (__fastcall **)(signed __int64, unsigned __int64, _QWORD *))(*(_QWORD *)v12 + 16i64))(
              v12,
              v7,
              v8); i != -1; i = (*(__int64 (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v12 + 24i64))(v12, i) )
  {
    v14 = (_QWORD *)(*(__int64 (__fastcall **)(signed __int64, _QWORD, char *))(*(_QWORD *)v12 + 40i64))(v12, i, &v22);
    (*(void (__fastcall **)(_QWORD *, hkTransformf *, _QWORD, __m128 *))(*v14 + 32i64))(v14, v6, *v14, &v20);
    v15 = _mm_max_ps(v5->m_max.m_quad, v21);
    v5->m_min.m_quad = _mm_min_ps(v5->m_min.m_quad, v20);
    v5->m_max.m_quad = v15;
  }
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v18 = __rdtsc();
    v19 = (signed __int64)(v17 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v16[1] = v19;
  }
}

// File Line: 106
// RVA: 0xD09C90
float __usercall hkpShapeCollection::getMaximumProjection@<xmm0>(hkpShapeCollection *this@<rcx>, hkVector4f *direction@<rdx>, float a3@<xmm0>)
{
  hkpShapeCollection *v3; // rbx
  hkVector4f *v4; // rsi
  _QWORD *v5; // rax
  unsigned __int64 v6; // rdx
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkpShapeContainerVtbl *v11; // rax
  float v12; // xmm6_4
  signed __int64 v13; // rbx
  unsigned int i; // edi
  __int64 v15; // rax
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  float result; // xmm0_4
  unsigned __int64 v19; // rax
  signed __int64 v20; // rcx
  char v21; // [rsp+20h] [rbp-218h]

  v3 = this;
  v4 = direction;
  v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v5[1];
  v8 = v5;
  if ( (unsigned __int64)v7 < v5[3] )
  {
    *v7 = "TthkpShapeCollection::getMaximumProjection";
    v9 = __rdtsc();
    v6 = (unsigned __int64)HIDWORD(v9) << 32;
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v3->vfptr;
  v12 = FLOAT_N3_40282e38;
  v13 = (signed __int64)&v3->vfptr;
  for ( i = ((__int64 (__fastcall *)(signed __int64, unsigned __int64, _QWORD *))v11->getFirstKey)(v13, v6, v8);
        i != -1;
        i = (*(__int64 (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v13 + 24i64))(v13, i) )
  {
    v15 = (*(__int64 (__fastcall **)(signed __int64, _QWORD, char *))(*(_QWORD *)v13 + 40i64))(v13, i, &v21);
    (*(void (__fastcall **)(__int64, hkVector4f *))(*(_QWORD *)v15 + 120i64))(v15, v4);
    v12 = fmaxf(v12, a3);
  }
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  result = v12;
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v19 = __rdtsc();
    v20 = (signed __int64)(v17 + 2);
    *(_DWORD *)(v20 - 8) = v19;
    v16[1] = v20;
  }
  return result;
}

// File Line: 123
// RVA: 0xD09AB0
void __fastcall hkpShapeCollection::castRayWithCollector(hkpShapeCollection *this, hkpShapeRayCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkpShapeCollection *v4; // rdi
  hkpRayHitCollector *v5; // r14
  hkpCdBody *v6; // rbp
  hkpShapeRayCastInput *v7; // rsi
  unsigned __int64 v8; // rdx
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  signed __int64 v13; // rbx
  unsigned int j; // edi
  __int64 v15; // rax
  __int64 v16; // rcx
  hkpShapeContainerVtbl *v17; // rax
  signed __int64 v18; // rdi
  unsigned int i; // ebx
  __int64 v20; // rax
  __int64 v21; // rcx
  _QWORD *v22; // rax
  _QWORD *v23; // rcx
  _QWORD *v24; // r8
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  __int64 v27; // [rsp+30h] [rbp-238h]
  unsigned int v28; // [rsp+38h] [rbp-230h]
  __int64 v29; // [rsp+40h] [rbp-228h]
  hkpCdBody *v30; // [rsp+48h] [rbp-220h]
  char v31; // [rsp+50h] [rbp-218h]
  char v32; // [rsp+278h] [rbp+10h]

  v4 = this;
  v5 = collector;
  v6 = cdBody;
  v7 = input;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtrcShpCollect";
    v11 = __rdtsc();
    v8 = (unsigned __int64)HIDWORD(v11) << 32;
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  if ( v7->m_rayShapeCollectionFilter )
  {
    v17 = v4->vfptr;
    v18 = (signed __int64)&v4->vfptr;
    for ( i = ((__int64 (__fastcall *)(signed __int64, unsigned __int64, _QWORD *))v17->getFirstKey)(v18, v8, v9);
          i != -1;
          i = (*(__int64 (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v18 + 24i64))(v18, i) )
    {
      if ( *(_BYTE *)((__int64 (__fastcall *)(hkpRayShapeCollectionFilter *, char *, hkpShapeRayCastInput *, signed __int64))v7->m_rayShapeCollectionFilter->vfptr->isCollisionEnabled)(
                       v7->m_rayShapeCollectionFilter,
                       &v32,
                       v7,
                       v18) )
      {
        v20 = (*(__int64 (__fastcall **)(signed __int64, _QWORD, char *))(*(_QWORD *)v18 + 40i64))(v18, i, &v31);
        v21 = (__int64)v6->m_motion;
        v30 = v6;
        v29 = v21;
        v27 = v20;
        v28 = i;
        (*(void (__fastcall **)(__int64, hkpShapeRayCastInput *, __int64 *, hkpRayHitCollector *))(*(_QWORD *)v20 + 48i64))(
          v20,
          v7,
          &v27,
          v5);
      }
    }
  }
  else
  {
    v13 = (signed __int64)&v4->vfptr;
    for ( j = ((__int64 (__fastcall *)(hkpShapeContainerVtbl **, unsigned __int64, _QWORD *))v4->vfptr->getFirstKey)(
                &v4->vfptr,
                v8,
                v9); j != -1; j = (*(__int64 (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v13 + 24i64))(v13, j) )
    {
      v15 = (*(__int64 (__fastcall **)(signed __int64, _QWORD, char *))(*(_QWORD *)v13 + 40i64))(v13, j, &v31);
      v16 = (__int64)v6->m_motion;
      v30 = v6;
      v29 = v16;
      v27 = v15;
      v28 = j;
      (*(void (__fastcall **)(__int64, hkpShapeRayCastInput *, __int64 *, hkpRayHitCollector *))(*(_QWORD *)v15 + 48i64))(
        v15,
        v7,
        &v27,
        v5);
    }
  }
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  v24 = v22;
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v25 = __rdtsc();
    v26 = (signed __int64)(v23 + 2);
    *(_DWORD *)(v26 - 8) = v25;
    v24[1] = v26;
  }
}

// File Line: 158
// RVA: 0xD09DC0
hkpShapeContainer *__fastcall hkpShapeCollection::getContainer(hkpShapeCollection *this)
{
  hkpShapeContainer *result; // rax

  if ( this )
    result = (hkpShapeContainer *)&this->vfptr;
  else
    result = 0i64;
  return result;
}

// File Line: 165
// RVA: 0xD09DF0
void __fastcall hkpShapeCollection::setWeldingInfo(hkpShapeCollection *this, unsigned int key, __int16 weldingInfo)
{
  ;
}

// File Line: 170
// RVA: 0xD09DE0
void __fastcall hkpShapeCollection::initWeldingInfo(hkpShapeCollection *this, hkpWeldingUtility::WeldingType weldingType)
{
  ;
}

