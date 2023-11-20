// File Line: 20
// RVA: 0xCED250
hkBool *__fastcall hkpCollidable::checkPerformance(hkpCollidable *this, hkBool *result)
{
  hkpCollidable *v2; // rdi
  hkpShape *v3; // rcx
  hkBool *v4; // rbx
  hkBool *v5; // rax
  char v6; // si
  char v7; // al
  char v8; // cl

  v2 = this;
  v3 = this->m_shape;
  v4 = result;
  if ( v3 )
  {
    v6 = 1;
    if ( v3->m_type.m_storage == 8 )
    {
      v6 = 1;
      if ( ((signed int (__fastcall *)(hkpShape *))v3[1].vfptr->__first_virtual_table_function__)(&v3[1]) > 100 )
        v6 = 0;
    }
    if ( v2->m_shape->m_type.m_storage == 27
      && ((signed int (__fastcall *)(hkpShape *))v2->m_shape[1].vfptr->__first_virtual_table_function__)(&v2->m_shape[1]) > 100 )
    {
      v6 = 0;
    }
    v7 = v2->m_shape->m_type.m_storage;
    if ( (v7 == 18 || v7 == 6)
      && ((signed int (__fastcall *)(hkpShape *))v2->m_shape[1].vfptr->__first_virtual_table_function__)(&v2->m_shape[1]) > 100 )
    {
      v6 = 0;
    }
    v8 = v6;
    v5 = v4;
    if ( v2->m_shape->m_type.m_storage == 14 )
      v8 = 0;
    v4->m_bool = v8;
  }
  else
  {
    result->m_bool = 0;
    v5 = result;
  }
  return v5;
}

// File Line: 77
// RVA: 0xCED320
void __fastcall hkpCollidable::BoundingVolumeData::BoundingVolumeData(hkpCollidable::BoundingVolumeData *this)
{
  hkpCollidable::BoundingVolumeData *v1; // rbx

  v1 = this;
  hkString::memSet(this, 0, 56);
  v1->m_min[0] = 1;
  v1->m_max[0] = 0;
}

// File Line: 84
// RVA: 0xCED350
void __fastcall hkpCollidable::BoundingVolumeData::deallocate(hkpCollidable::BoundingVolumeData *this)
{
  int v1; // edi
  hkAabbUint32 *v2; // rbx
  hkpCollidable::BoundingVolumeData *v3; // rsi
  _QWORD **v4; // rax
  unsigned int *v5; // rbx
  unsigned int v6; // edi
  _QWORD **v7; // rax

  v1 = this->m_capacityChildShapeAabbs;
  v2 = this->m_childShapeAabbs;
  v3 = this;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkAabbUint32 *, _QWORD))(*v4[11] + 16i64))(v4[11], v2, (unsigned int)(32 * v1));
  v5 = v3->m_childShapeKeys;
  v6 = (v3->m_capacityChildShapeAabbs + 3) & 0xFFFFFFFC;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, unsigned int *, _QWORD))(*v7[11] + 16i64))(v7[11], v5, 4 * v6);
  v3->m_childShapeAabbs = 0i64;
  v3->m_childShapeKeys = 0i64;
  *(_DWORD *)&v3->m_numChildShapeAabbs = 0;
}

// File Line: 95
// RVA: 0xCED3E0
void __fastcall hkpCollidable::BoundingVolumeData::allocate(hkpCollidable::BoundingVolumeData *this, int numChildShapes)
{
  hkpCollidable::BoundingVolumeData *v2; // rdi
  int v3; // ebx
  _QWORD **v4; // rax
  __int64 v5; // rax
  int v6; // ebx
  _QWORD **v7; // rax

  v2 = this;
  this->m_numChildShapeAabbs = numChildShapes;
  this->m_capacityChildShapeAabbs = numChildShapes;
  if ( numChildShapes )
  {
    v3 = (unsigned __int16)numChildShapes;
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v4[11] + 8i64))(v4[11], (unsigned int)(32 * v3));
    v6 = v2->m_capacityChildShapeAabbs;
    v2->m_childShapeAabbs = (hkAabbUint32 *)v5;
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v2->m_childShapeKeys = (unsigned int *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v7[11] + 8i64))(
                                             v7[11],
                                             4 * ((v6 + 3) & 0xFFFFFFFC));
  }
}

