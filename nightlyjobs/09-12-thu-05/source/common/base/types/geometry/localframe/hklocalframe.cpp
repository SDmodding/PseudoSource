// File Line: 13
// RVA: 0xC746B0
void __fastcall hkLocalFrame::getTransformToRoot(hkLocalFrame *this, hkTransformf *transform)
{
  hkTransformf *v2; // rdi
  hkLocalFrame *v3; // rbx
  bool v4; // zf
  hkBaseObjectVtbl *v5; // rax
  hkLocalFrame *v6; // rax
  hkTransformf bTc; // [rsp+20h] [rbp-88h]
  hkTransformf transforma; // [rsp+60h] [rbp-48h]

  v2 = transform;
  v3 = this;
  v4 = ((__int64 (*)(void))this->vfptr[4].__vecDelDtor)() == 0;
  v5 = v3->vfptr;
  if ( v4 )
  {
    ((void (__fastcall *)(hkLocalFrame *, hkTransformf *))v5[1].__first_virtual_table_function__)(v3, v2);
  }
  else
  {
    v6 = (hkLocalFrame *)((__int64 (__fastcall *)(hkLocalFrame *))v5[4].__vecDelDtor)(v3);
    hkLocalFrame::getTransformToRoot(v6, &transforma);
    ((void (__fastcall *)(hkLocalFrame *, hkTransformf *))v3->vfptr[1].__first_virtual_table_function__)(v3, &bTc);
    hkTransformf::setMul(v2, &transforma, &bTc);
  }
}

// File Line: 36
// RVA: 0xC74740
void __fastcall hkLocalFrame::getPositionInRoot(hkLocalFrame *this, hkVector4f *position)
{
  hkVector4f *v2; // rdi
  hkLocalFrame *v3; // rbx
  __int64 i; // rbx
  hkTransformf a; // [rsp+20h] [rbp-48h]

  v2 = position;
  v3 = this;
  ((void (*)(void))this->vfptr[2].__first_virtual_table_function__)();
  for ( i = ((__int64 (__fastcall *)(hkLocalFrame *))v3->vfptr[4].__vecDelDtor)(v3);
        i;
        i = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)i + 64i64))(i) )
  {
    (*(void (__fastcall **)(__int64, hkTransformf *))(*(_QWORD *)i + 24i64))(i, &a);
    hkVector4f::setTransformedPos(v2, &a, v2);
  }
}

// File Line: 51
// RVA: 0xC747B0
void __fastcall hkLocalFrame::getLocalPosition(hkLocalFrame *this, hkVector4f *position)
{
  hkVector4f *v2; // rbx
  char v3; // [rsp+20h] [rbp-48h]
  hkVector4f v4; // [rsp+50h] [rbp-18h]

  v2 = position;
  ((void (__fastcall *)(hkLocalFrame *, char *))this->vfptr[1].__first_virtual_table_function__)(this, &v3);
  *v2 = (hkVector4f)v4.m_quad;
}

// File Line: 62
// RVA: 0xC747E0
void __fastcall hkLocalFrame::getDescendants(hkLocalFrame *this, hkArrayBase<hkLocalFrame const *> *descendants, hkMemoryAllocator *a)
{
  hkMemoryAllocator *v3; // rbp
  hkArrayBase<hkLocalFrame const *> *v4; // rbx
  hkLocalFrame *v5; // rdi
  signed int i; // esi
  __int64 v7; // r14

  v3 = a;
  v4 = descendants;
  v5 = this;
  if ( ((unsigned int (*)(void))this->vfptr[5].__vecDelDtor)() )
  {
    for ( i = 0; i < ((signed int (__fastcall *)(hkLocalFrame *))v5->vfptr[5].__vecDelDtor)(v5); ++i )
    {
      v7 = ((__int64 (__fastcall *)(hkLocalFrame *, _QWORD))v5->vfptr[5].__first_virtual_table_function__)(
             v5,
             (unsigned int)i);
      if ( v7 )
      {
        if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(v3, v4, 8);
        v4->m_data[v4->m_size++] = (hkLocalFrame *)v7;
        (*(void (__fastcall **)(__int64, hkArrayBase<hkLocalFrame const *> *, hkMemoryAllocator *))(*(_QWORD *)v7
                                                                                                  + 112i64))(
          v7,
          v4,
          v3);
      }
    }
  }
}

// File Line: 83
// RVA: 0xC748A0
void __fastcall hkSimpleLocalFrame::~hkSimpleLocalFrame(hkSimpleLocalFrame *this)
{
  __int64 v1; // rsi
  __int64 v2; // rbx
  hkSimpleLocalFrame *v3; // rdi
  hkReferencedObject *v4; // rcx
  int v5; // er8

  v1 = this->m_children.m_size;
  v2 = 0i64;
  v3 = this;
  for ( this->vfptr = (hkBaseObjectVtbl *)&hkSimpleLocalFrame::`vftable; v2 < v1; ++v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v3->m_children.m_data[v2]->vfptr);
  v4 = (hkReferencedObject *)&v3->m_group->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  hkStringPtr::~hkStringPtr(&v3->m_name);
  v5 = v3->m_children.m_capacityAndFlags;
  v3->m_children.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v3->m_children.m_data,
      8 * v5);
  v3->m_children.m_data = 0i64;
  v3->m_children.m_capacityAndFlags = 2147483648;
  v3->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 98
// RVA: 0xC74960
void __fastcall hkSimpleLocalFrame::getLocalTransform(hkSimpleLocalFrame *this, hkTransformf *transform)
{
  transform->m_rotation.m_col0 = this->m_transform.m_rotation.m_col0;
  transform->m_rotation.m_col1 = this->m_transform.m_rotation.m_col1;
  transform->m_rotation.m_col2 = this->m_transform.m_rotation.m_col2;
  transform->m_translation = this->m_transform.m_translation;
}

// File Line: 103
// RVA: 0xC74990
void __fastcall hkSimpleLocalFrame::setLocalTransform(hkSimpleLocalFrame *this, hkTransformf *transform)
{
  this->m_transform.m_rotation.m_col0 = transform->m_rotation.m_col0;
  this->m_transform.m_rotation.m_col1 = transform->m_rotation.m_col1;
  this->m_transform.m_rotation.m_col2 = transform->m_rotation.m_col2;
  this->m_transform.m_translation = transform->m_translation;
}

// File Line: 108
// RVA: 0xC749C0
void __fastcall hkSimpleLocalFrame::getLocalPosition(hkSimpleLocalFrame *this, hkVector4f *position)
{
  *position = this->m_transform.m_translation;
}

// File Line: 113
// RVA: 0xC749D0
void __fastcall hkSimpleLocalFrame::getNearbyFrames(hkSimpleLocalFrame *this, hkVector4f *target, float maxDistance, hkLocalFrameCollector *collector)
{
  hkLocalFrameCollector *v4; // r14
  hkVector4f *v5; // rbx
  hkSimpleLocalFrame *v6; // rsi
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  __int64 v11; // r8
  int v12; // ebx
  __int64 v13; // rdi
  hkVector4f v14; // [rsp+20h] [rbp-28h]

  v4 = collector;
  v5 = target;
  v6 = this;
  v7 = _mm_sub_ps(target->m_quad, this->m_transform.m_translation.m_quad);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  if ( COERCE_FLOAT(
         _mm_andnot_ps(
           _mm_cmpleps(v9, (__m128)0i64),
           _mm_mul_ps(
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v10), v10)),
               _mm_mul_ps(*(__m128 *)_xmm, v10)),
             v9))) <= maxDistance )
    ((void (__fastcall *)(hkLocalFrameCollector *, hkSimpleLocalFrame *))collector->vfptr[1].__first_virtual_table_function__)(
      collector,
      this);
  if ( v6->m_children.m_size > 0 )
  {
    hkVector4f::setTransformedInversePos(&v14, &v6->m_transform, v5);
    v12 = 0;
    if ( v6->m_children.m_size > 0 )
    {
      v13 = 0i64;
      do
      {
        ((void (__fastcall *)(hkLocalFrame *, hkVector4f *, __int64, hkLocalFrameCollector *))v6->m_children.m_data[v13]->vfptr[3].__vecDelDtor)(
          v6->m_children.m_data[v13],
          &v14,
          v11,
          v4);
        ++v12;
        ++v13;
      }
      while ( v12 < v6->m_children.m_size );
    }
  }
}

// File Line: 139
// RVA: 0xC74B00
void __fastcall hkSimpleLocalFrame::setGroup(hkSimpleLocalFrame *this, hkLocalFrameGroup *group)
{
  hkLocalFrameGroup *v2; // rbx
  hkSimpleLocalFrame *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = group;
  v3 = this;
  if ( group )
    hkReferencedObject::addReference((hkReferencedObject *)&group->vfptr);
  v4 = (hkReferencedObject *)&v3->m_group->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_group = v2;
}

// File Line: 155
// RVA: 0xC74AD0
__int64 __fastcall hkSimpleLocalFrame::getNumChildFrames(hkSimpleLocalFrame *this)
{
  return (unsigned int)this->m_children.m_size;
}

// File Line: 160
// RVA: 0xC74AE0
hkLocalFrame *__fastcall hkSimpleLocalFrame::getChildFrame(hkSimpleLocalFrame *this, int i)
{
  return this->m_children.m_data[i];
}

