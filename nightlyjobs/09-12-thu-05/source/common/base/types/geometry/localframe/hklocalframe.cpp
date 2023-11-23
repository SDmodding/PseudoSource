// File Line: 13
// RVA: 0xC746B0
void __fastcall hkLocalFrame::getTransformToRoot(hkLocalFrame *this, hkTransformf *transform)
{
  bool v4; // zf
  hkBaseObjectVtbl *vfptr; // rax
  hkLocalFrame *v6; // rax
  hkTransformf bTc; // [rsp+20h] [rbp-88h] BYREF
  hkTransformf transforma; // [rsp+60h] [rbp-48h] BYREF

  v4 = ((__int64 (__fastcall *)(hkLocalFrame *))this->vfptr[4].__vecDelDtor)(this) == 0;
  vfptr = this->vfptr;
  if ( v4 )
  {
    ((void (__fastcall *)(hkLocalFrame *, hkTransformf *))vfptr[1].__first_virtual_table_function__)(this, transform);
  }
  else
  {
    v6 = (hkLocalFrame *)((__int64 (__fastcall *)(hkLocalFrame *))vfptr[4].__vecDelDtor)(this);
    hkLocalFrame::getTransformToRoot(v6, &transforma);
    ((void (__fastcall *)(hkLocalFrame *, hkTransformf *))this->vfptr[1].__first_virtual_table_function__)(this, &bTc);
    hkTransformf::setMul(transform, &transforma, &bTc);
  }
}

// File Line: 36
// RVA: 0xC74740
void __fastcall hkLocalFrame::getPositionInRoot(hkLocalFrame *this, hkVector4f *position)
{
  __int64 i; // rbx
  hkTransformf a; // [rsp+20h] [rbp-48h] BYREF

  this->vfptr[2].__first_virtual_table_function__(this);
  for ( i = ((__int64 (__fastcall *)(hkLocalFrame *))this->vfptr[4].__vecDelDtor)(this);
        i;
        i = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)i + 64i64))(i) )
  {
    (*(void (__fastcall **)(__int64, hkTransformf *))(*(_QWORD *)i + 24i64))(i, &a);
    hkVector4f::setTransformedPos(position, &a, position);
  }
}

// File Line: 51
// RVA: 0xC747B0
void __fastcall hkLocalFrame::getLocalPosition(hkLocalFrame *this, hkVector4f *position)
{
  char v3[48]; // [rsp+20h] [rbp-48h] BYREF
  hkVector4f v4; // [rsp+50h] [rbp-18h]

  ((void (__fastcall *)(hkLocalFrame *, char *))this->vfptr[1].__first_virtual_table_function__)(this, v3);
  *position = (hkVector4f)v4.m_quad;
}

// File Line: 62
// RVA: 0xC747E0
void __fastcall hkLocalFrame::getDescendants(
        hkLocalFrame *this,
        hkArrayBase<hkLocalFrame const *> *descendants,
        hkMemoryAllocator *a)
{
  int i; // esi
  hkLocalFrame *v7; // r14

  if ( ((unsigned int (__fastcall *)(hkLocalFrame *))this->vfptr[5].__vecDelDtor)(this) )
  {
    for ( i = 0; i < ((int (__fastcall *)(hkLocalFrame *))this->vfptr[5].__vecDelDtor)(this); ++i )
    {
      v7 = (hkLocalFrame *)((__int64 (__fastcall *)(hkLocalFrame *, _QWORD))this->vfptr[5].__first_virtual_table_function__)(
                             this,
                             (unsigned int)i);
      if ( v7 )
      {
        if ( descendants->m_size == (descendants->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(a, (const void **)&descendants->m_data, 8);
        descendants->m_data[descendants->m_size++] = v7;
        ((void (__fastcall *)(hkLocalFrame *, hkArrayBase<hkLocalFrame const *> *, hkMemoryAllocator *))v7->vfptr[7].__vecDelDtor)(
          v7,
          descendants,
          a);
      }
    }
  }
}

// File Line: 83
// RVA: 0xC748A0
void __fastcall hkSimpleLocalFrame::~hkSimpleLocalFrame(hkSimpleLocalFrame *this)
{
  __int64 m_size; // rsi
  __int64 v2; // rbx
  hkLocalFrameGroup *m_group; // rcx
  int m_capacityAndFlags; // r8d

  m_size = this->m_children.m_size;
  v2 = 0i64;
  for ( this->vfptr = (hkBaseObjectVtbl *)&hkSimpleLocalFrame::`vftable; v2 < m_size; ++v2 )
    hkReferencedObject::removeReference(this->m_children.m_data[v2]);
  m_group = this->m_group;
  if ( m_group )
    hkReferencedObject::removeReference(m_group);
  hkStringPtr::~hkStringPtr(&this->m_name);
  m_capacityAndFlags = this->m_children.m_capacityAndFlags;
  this->m_children.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_children.m_data,
      8 * m_capacityAndFlags);
  this->m_children.m_data = 0i64;
  this->m_children.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 98
// RVA: 0xC74960
void __fastcall hkSimpleLocalFrame::getLocalTransform(hkSimpleLocalFrame *this, hkTransformf *transform)
{
  *transform = this->m_transform;
}

// File Line: 103
// RVA: 0xC74990
void __fastcall hkSimpleLocalFrame::setLocalTransform(hkSimpleLocalFrame *this, hkTransformf *transform)
{
  this->m_transform = *transform;
}

// File Line: 108
// RVA: 0xC749C0
void __fastcall hkSimpleLocalFrame::getLocalPosition(hkSimpleLocalFrame *this, hkVector4f *position)
{
  *position = this->m_transform.m_translation;
}

// File Line: 113
// RVA: 0xC749D0
void __fastcall hkSimpleLocalFrame::getNearbyFrames(
        hkSimpleLocalFrame *this,
        hkVector4f *target,
        float maxDistance,
        hkLocalFrameCollector *collector)
{
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  __int64 v11; // r8
  int v12; // ebx
  __int64 v13; // rdi
  hkVector4f v14; // [rsp+20h] [rbp-28h] BYREF

  v7 = _mm_sub_ps(target->m_quad, this->m_transform.m_translation.m_quad);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  if ( _mm_andnot_ps(
         _mm_cmple_ps(v9, (__m128)0i64),
         _mm_mul_ps(
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v10), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10)),
           v9)).m128_f32[0] <= maxDistance )
    ((void (__fastcall *)(hkLocalFrameCollector *, hkSimpleLocalFrame *))collector->vfptr[1].__first_virtual_table_function__)(
      collector,
      this);
  if ( this->m_children.m_size > 0 )
  {
    hkVector4f::setTransformedInversePos(&v14, &this->m_transform, target);
    v12 = 0;
    if ( this->m_children.m_size > 0 )
    {
      v13 = 0i64;
      do
      {
        ((void (__fastcall *)(hkLocalFrame *, hkVector4f *, __int64, hkLocalFrameCollector *))this->m_children.m_data[v13]->vfptr[3].__vecDelDtor)(
          this->m_children.m_data[v13],
          &v14,
          v11,
          collector);
        ++v12;
        ++v13;
      }
      while ( v12 < this->m_children.m_size );
    }
  }
}

// File Line: 139
// RVA: 0xC74B00
void __fastcall hkSimpleLocalFrame::setGroup(hkSimpleLocalFrame *this, hkLocalFrameGroup *group)
{
  hkLocalFrameGroup *m_group; // rcx

  if ( group )
    hkReferencedObject::addReference(group);
  m_group = this->m_group;
  if ( m_group )
    hkReferencedObject::removeReference(m_group);
  this->m_group = group;
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

