// File Line: 18
// RVA: 0xD17B90
void __fastcall hkpFastMeshShape::hkpFastMeshShape(hkpFastMeshShape *this, float radius, int numBitsForSubpartIndex)
{
  hkpMeshShape::hkpMeshShape(this, radius, numBitsForSubpartIndex);
  this->hkpMeshShape::hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpFastMeshShape::`vftable{for `hkpShape};
  this->hkpMeshShape::hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpFastMeshShape::`vftable{for `hkpShapeContainer};
}

// File Line: 25
// RVA: 0xD17BD0
void __fastcall hkpFastMeshShape::hkpFastMeshShape(hkpFastMeshShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpMeshShape::hkpMeshShape(this, flag);
  this->hkpMeshShape::hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpFastMeshShape::`vftable{for `hkpShape};
  this->hkpMeshShape::hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpFastMeshShape::`vftable{for `hkpShapeContainer};
  if ( flag.m_finishing )
    this->m_type.m_storage = 27;
}

// File Line: 36
// RVA: 0xD17C10
hkpShape *__fastcall hkpFastMeshShape::getChildShape(hkpFastMeshShape *this, unsigned int key, hkpShape *buffer)
{
  __int64 v3; // rsi
  int v6; // r9d
  unsigned __int16 *v7; // r11
  __int64 v8; // rcx
  __m128 *v9; // rbp
  __m128 *v10; // r8
  __m128 *v11; // r9
  unsigned __int16 v12; // cx
  int m_data_high; // xmm0_4
  unsigned __int8 m_data; // al
  hkpShape *result; // rax

  v3 = *(_QWORD *)&this->m_disableWelding.m_bool;
  v6 = *(_DWORD *)(v3 + 8);
  v7 = (unsigned __int16 *)(*(_QWORD *)(v3 + 16) + key * *(_DWORD *)(v3 + 28));
  v8 = (int)(key & *(_DWORD *)(v3 + 32));
  v9 = (__m128 *)(*(_QWORD *)v3 + v6 * *v7);
  v10 = (__m128 *)(*(_QWORD *)v3 + v6 * v7[v8 + 1]);
  v11 = (__m128 *)(*(_QWORD *)v3 + v6 * v7[(v8 ^ 1) + 1]);
  if ( this->m_numBitsForSubpartIndex )
    v12 = *(_WORD *)(this->m_scaling.m_quad.m128_u64[1] + 2i64 * (int)(key + *(_DWORD *)(v3 + 72)));
  else
    v12 = 0;
  if ( buffer )
  {
    m_data_high = HIDWORD(this->m_subparts.m_data);
    m_data = (unsigned __int8)this->m_subparts.m_data;
    *(_DWORD *)&buffer->m_memSizeAndFlags = 0x1FFFF;
    *(_DWORD *)&buffer->m_type.m_storage = 1026;
    buffer->m_userData = 0i64;
    LODWORD(buffer[1].vfptr) = m_data_high;
    buffer[1].m_memSizeAndFlags = v12;
    buffer[1].m_referenceCount = m_data;
    buffer[3].hkReferencedObject = 0i64;
    buffer->vfptr = (hkBaseObjectVtbl *)&hkpTriangleShape::`vftable;
  }
  else
  {
    buffer = 0i64;
  }
  result = buffer;
  *(__m128 *)&buffer[1].m_type.m_storage = _mm_mul_ps(*(__m128 *)&this->m_type.m_storage, *v9);
  buffer[2].hkReferencedObject = (hkReferencedObject)_mm_mul_ps(*(__m128 *)&this->m_type.m_storage, *v10);
  *(__m128 *)&buffer[2].m_type.m_storage = _mm_mul_ps(*v11, *(__m128 *)&this->m_type.m_storage);
  return result;
}

