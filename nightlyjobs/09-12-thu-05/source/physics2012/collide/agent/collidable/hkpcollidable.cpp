// File Line: 20
// RVA: 0xCED250
hkBool *__fastcall hkpCollidable::checkPerformance(hkpCollidable *this, hkBool *result)
{
  hkpShape *m_shape; // rcx
  hkBool *v5; // rax
  bool v6; // si
  char m_storage; // al
  char v8; // cl

  m_shape = this->m_shape;
  if ( m_shape )
  {
    v6 = 1;
    if ( m_shape->m_type.m_storage == 8 )
      v6 = ((int (__fastcall *)(hkpShape *))m_shape[1].vfptr->__first_virtual_table_function__)(&m_shape[1]) <= 100;
    if ( this->m_shape->m_type.m_storage == 27
      && ((int (__fastcall *)(hkpShape *))this->m_shape[1].vfptr->__first_virtual_table_function__)(&this->m_shape[1]) > 100 )
    {
      v6 = 0;
    }
    m_storage = this->m_shape->m_type.m_storage;
    if ( (m_storage == 18 || m_storage == 6)
      && ((int (__fastcall *)(hkpShape *))this->m_shape[1].vfptr->__first_virtual_table_function__)(&this->m_shape[1]) > 100 )
    {
      v6 = 0;
    }
    v8 = v6;
    v5 = result;
    if ( this->m_shape->m_type.m_storage == 14 )
      v8 = 0;
    result->m_bool = v8;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
  return v5;
}

// File Line: 77
// RVA: 0xCED320
void __fastcall hkpCollidable::BoundingVolumeData::BoundingVolumeData(hkpCollidable::BoundingVolumeData *this)
{
  hkString::memSet(this, 0, 0x38u);
  this->m_min[0] = 1;
  this->m_max[0] = 0;
}

// File Line: 84
// RVA: 0xCED350
void __fastcall hkpCollidable::BoundingVolumeData::deallocate(hkpCollidable::BoundingVolumeData *this)
{
  int m_capacityChildShapeAabbs; // edi
  hkAabbUint32 *m_childShapeAabbs; // rbx
  _QWORD **Value; // rax
  unsigned int *m_childShapeKeys; // rbx
  unsigned int v6; // edi
  _QWORD **v7; // rax

  m_capacityChildShapeAabbs = this->m_capacityChildShapeAabbs;
  m_childShapeAabbs = this->m_childShapeAabbs;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkAabbUint32 *, _QWORD))(*Value[11] + 16i64))(
    Value[11],
    m_childShapeAabbs,
    (unsigned int)(32 * m_capacityChildShapeAabbs));
  m_childShapeKeys = this->m_childShapeKeys;
  v6 = (this->m_capacityChildShapeAabbs + 3) & 0xFFFFFFFC;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, unsigned int *, _QWORD))(*v7[11] + 16i64))(v7[11], m_childShapeKeys, 4 * v6);
  this->m_childShapeAabbs = 0i64;
  this->m_childShapeKeys = 0i64;
  *(_DWORD *)&this->m_numChildShapeAabbs = 0;
}

// File Line: 95
// RVA: 0xCED3E0
void __fastcall hkpCollidable::BoundingVolumeData::allocate(
        hkpCollidable::BoundingVolumeData *this,
        int numChildShapes)
{
  int v3; // ebx
  _QWORD **Value; // rax
  hkAabbUint32 *v5; // rax
  int m_capacityChildShapeAabbs; // ebx
  _QWORD **v7; // rax

  this->m_numChildShapeAabbs = numChildShapes;
  this->m_capacityChildShapeAabbs = numChildShapes;
  if ( numChildShapes )
  {
    v3 = (unsigned __int16)numChildShapes;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (hkAabbUint32 *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[11] + 8i64))(
                           Value[11],
                           (unsigned int)(32 * v3));
    m_capacityChildShapeAabbs = this->m_capacityChildShapeAabbs;
    this->m_childShapeAabbs = v5;
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    this->m_childShapeKeys = (unsigned int *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v7[11] + 8i64))(
                                               v7[11],
                                               4 * ((m_capacityChildShapeAabbs + 3) & 0xFFFFFFFC));
  }
}

