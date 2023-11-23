// File Line: 17
// RVA: 0x1319780
void __fastcall hkMemoryMeshBody::hkMemoryMeshBody(
        hkMemoryMeshBody *this,
        hkMeshSystem *meshSystem,
        hkMeshShape *shape,
        hkMatrix4f *transform,
        hkIndexedTransformSetCinfo *transformSet)
{
  hkVector4f *v5; // rbx
  __int64 v6; // rsi
  hkIndexedTransformSetCinfo *v9; // rbx
  _QWORD **Value; // rax
  hkIndexedTransformSet *v11; // rax
  hkIndexedTransformSet *v12; // rax
  hkIndexedTransformSet *v13; // rbx
  hkIndexedTransformSet *m_pntr; // rcx
  int v15; // eax
  char *m_cur; // r8
  __int64 v17; // r14
  hkLifoAllocator *v18; // rax
  int v19; // edx
  char *v20; // rcx
  int v21; // ebx
  hkLifoAllocator *v22; // rax
  _QWORD **v23; // rdx
  int v24; // ecx
  hkLifoAllocator *v25; // rcx
  hkReferencedObject **v26; // rax
  int v27; // edx
  int v28; // edi
  int v29; // ecx
  hkBaseObjectVtbl *vfptr; // rax
  int v31; // ecx
  _QWORD *v32; // rdi
  __int64 v33; // rax
  int v34; // r9d
  __int64 v35; // rdi
  __int64 i; // rsi
  hkReferencedObject **v37; // rbx
  __int64 v38; // rax
  int v39; // eax
  int v40; // eax
  int v41; // r9d
  __int64 j; // rdi
  __int64 v43; // rbx
  hkMeshVertexBuffer *v44; // rbx
  int v45; // eax
  char *v46; // rdi
  signed int v47; // ebx
  hkLifoAllocator *v48; // rax
  int v49; // r8d
  int v50; // eax
  char *v51; // rdi
  signed int v52; // ebx
  hkLifoAllocator *v53; // rax
  int v54; // r8d
  int v55; // eax
  char *v56; // rdi
  signed int v57; // ebx
  hkLifoAllocator *v58; // rax
  int v59; // r8d
  hkMeshShape *v60; // rcx
  _QWORD **v61; // [rsp+30h] [rbp-B8h] BYREF
  int v62; // [rsp+38h] [rbp-B0h]
  int v63; // [rsp+3Ch] [rbp-ACh]
  void *v64; // [rsp+40h] [rbp-A8h]
  int v65; // [rsp+48h] [rbp-A0h]
  void *array; // [rsp+50h] [rbp-98h] BYREF
  int numObjects; // [rsp+58h] [rbp-90h]
  int v68; // [rsp+5Ch] [rbp-8Ch]
  void *v69; // [rsp+60h] [rbp-88h]
  void *p; // [rsp+68h] [rbp-80h]
  hkReferencedObject **objects; // [rsp+70h] [rbp-78h] BYREF
  int v72; // [rsp+78h] [rbp-70h] BYREF
  int v73; // [rsp+7Ch] [rbp-6Ch]
  hkReferencedObject *v74; // [rsp+98h] [rbp-50h]
  hkVertexFormat v75; // [rsp+B8h] [rbp-30h] BYREF
  hkVector4f *v76; // [rsp+210h] [rbp+128h]
  hkIndexedTransformSetCinfo *info; // [rsp+218h] [rbp+130h] BYREF
  hkMatrix4f *v78; // [rsp+228h] [rbp+140h]

  v78 = transform;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v76 = v5;
  v6 = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryMeshBody::`vftable;
  this->m_transformSet.m_pntr = 0i64;
  this->m_shape.m_pntr = 0i64;
  this->m_vertexBuffers.m_data = 0i64;
  this->m_vertexBuffers.m_size = 0;
  this->m_vertexBuffers.m_capacityAndFlags = 0x80000000;
  hkStringPtr::hkStringPtr(&this->m_name);
  hkStringPtr::operator=(&this->m_name, &customCaption);
  v9 = info;
  if ( info )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkIndexedTransformSet *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 104i64);
    if ( v11 )
    {
      hkIndexedTransformSet::hkIndexedTransformSet(v11, v9);
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    if ( v13 )
      hkReferencedObject::addReference(v13);
    m_pntr = this->m_transformSet.m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
    this->m_transformSet.m_pntr = v13;
    hkReferencedObject::removeReference(v13);
  }
  if ( shape )
  {
    v15 = ((__int64 (__fastcall *)(hkMeshShape *))shape->vfptr[1].__first_virtual_table_function__)(shape);
    v17 = v15;
    array = 0i64;
    numObjects = 0;
    v68 = 0x80000000;
    LODWORD(p) = v15;
    if ( v15 )
    {
      v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (char *)v18->m_cur;
      v19 = (8 * v17 + 127) & 0xFFFFFF80;
      v20 = &m_cur[v19];
      if ( v19 > v18->m_slabSize || v20 > v18->m_end )
      {
        m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v18, v19);
        array = m_cur;
      }
      else
      {
        v18->m_cur = v20;
        array = m_cur;
      }
    }
    else
    {
      array = 0i64;
    }
    v21 = 0;
    v61 = 0i64;
    v63 = 0x80000000;
    v69 = array;
    v62 = 0;
    v65 = v17;
    v68 = v17 | 0x80000000;
    if ( (_DWORD)v17 )
    {
      v22 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v23 = (_QWORD **)v22->m_cur;
      v24 = (8 * v17 + 127) & 0xFFFFFF80;
      m_cur = (char *)v23 + v24;
      if ( v24 > v22->m_slabSize || m_cur > v22->m_end )
      {
        v21 = v62;
        v23 = (_QWORD **)hkLifoAllocator::allocateFromNewSlab(v22, v24);
      }
      else
      {
        v22->m_cur = m_cur;
        v21 = v62;
      }
    }
    else
    {
      v23 = 0i64;
    }
    v61 = v23;
    v63 = v17 | 0x80000000;
    v64 = v23;
    v72 = 0;
    v73 = 0x80000000;
    objects = (hkReferencedObject **)(unsigned int)v17;
    if ( (_DWORD)v17 )
    {
      v25 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v26 = (hkReferencedObject **)v25->m_cur;
      v27 = (8 * v17 + 127) & 0xFFFFFF80;
      m_cur = (char *)v26 + v27;
      if ( v27 > v25->m_slabSize || m_cur > v25->m_end )
      {
        v26 = (hkReferencedObject **)hkLifoAllocator::allocateFromNewSlab(v25, v27);
        v21 = v62;
        v23 = v61;
      }
      else
      {
        v25->m_cur = m_cur;
        v21 = v62;
        v23 = v61;
      }
    }
    else
    {
      v26 = 0i64;
    }
    v73 = v17 | 0x80000000;
    objects = v26;
    p = v26;
    v28 = 0;
    if ( (int)v17 > 0 )
    {
      do
      {
        LOBYTE(m_cur) = 2;
        ((void (__fastcall *)(hkMeshShape *, _QWORD, char *, int *))shape->vfptr[2].__vecDelDtor)(
          shape,
          (unsigned int)v28,
          m_cur,
          &v72);
        hkReferencedObject::addReference(v74);
        v29 = numObjects;
        if ( numObjects == (v68 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
          v29 = numObjects;
        }
        *((_QWORD *)array + v29) = v74;
        vfptr = shape->vfptr;
        ++numObjects;
        ((void (__fastcall *)(hkMeshShape *, int *))vfptr[2].__first_virtual_table_function__)(shape, &v72);
        ++v28;
      }
      while ( v28 < (int)v17 );
      v21 = v62;
      v23 = v61;
    }
    if ( (int)v17 > 0 )
    {
      do
      {
        v31 = 0;
        v32 = (_QWORD *)*((_QWORD *)array + v6);
        v33 = 0i64;
        if ( v21 <= 0 )
          goto LABEL_40;
        while ( v23[v33] != v32 )
        {
          ++v33;
          ++v31;
          if ( v33 >= v21 )
            goto LABEL_40;
        }
        if ( v31 < 0 )
        {
LABEL_40:
          if ( v21 == (v63 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v61, 8);
            v21 = v62;
            v23 = v61;
          }
          v23[v21] = v32;
          v23 = v61;
          v21 = ++v62;
        }
        ++v6;
      }
      while ( v6 < v17 );
    }
    if ( (v73 & 0x3FFFFFFF) < v21 )
    {
      v34 = v21;
      if ( v21 < 2 * (v73 & 0x3FFFFFFF) )
        v34 = 2 * (v73 & 0x3FFFFFFF);
      hkArrayUtil::_reserve((hkResult *)&info, &hkContainerHeapAllocator::s_alloc, (const void **)&objects, v34, 8);
    }
    v72 = v21;
    hkVertexFormat::hkVertexFormat(&v75);
    v35 = 0i64;
    for ( i = v21; v35 < i; *v37 = (hkReferencedObject *)v38 )
    {
      v37 = &objects[v35];
      v38 = (*(__int64 (__fastcall **)(_QWORD *))(*v61[v35] + 24i64))(v61[v35]);
      ++v35;
    }
    v39 = this->m_vertexBuffers.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v39 < (int)v17 )
    {
      v40 = 2 * v39;
      v41 = v17;
      if ( (int)v17 < v40 )
        v41 = v40;
      hkArrayUtil::_reserve(
        (hkResult *)&info,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_vertexBuffers.m_data,
        v41,
        8);
    }
    this->m_vertexBuffers.m_size = v17;
    for ( j = 0i64; j < v17; this->m_vertexBuffers.m_data[j - 1] = v44 )
    {
      v43 = 0i64;
      if ( v62 <= 0 )
      {
LABEL_58:
        v43 = -1i64;
      }
      else
      {
        while ( v61[v43] != *((_QWORD **)array + j) )
        {
          if ( ++v43 >= v62 )
            goto LABEL_58;
        }
      }
      v44 = (hkMeshVertexBuffer *)objects[v43];
      hkReferencedObject::addReference(v44);
      ++j;
    }
    hkReferencedObject::removeReferences((hkReferencedObject **)array, numObjects, 8);
    hkReferencedObject::removeReferences(objects, v72, 8);
    v45 = v72;
    v46 = (char *)p;
    if ( p == objects )
      v45 = 0;
    v72 = v45;
    v47 = (8 * (_DWORD)objects + 127) & 0xFFFFFF80;
    v48 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v49 = (v47 + 15) & 0xFFFFFFF0;
    if ( v47 > v48->m_slabSize || &v46[v49] != v48->m_cur || v48->m_firstNonLifoEnd == v46 )
      hkLifoAllocator::slowBlockFree(v48, v46, v49);
    else
      v48->m_cur = v46;
    v72 = 0;
    if ( v73 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, objects, 8 * v73);
    v50 = v62;
    v51 = (char *)v64;
    objects = 0i64;
    v73 = 0x80000000;
    if ( v64 == v61 )
      v50 = 0;
    v62 = v50;
    v52 = (8 * v65 + 127) & 0xFFFFFF80;
    v53 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v54 = (v52 + 15) & 0xFFFFFFF0;
    if ( v52 > v53->m_slabSize || &v51[v54] != v53->m_cur || v53->m_firstNonLifoEnd == v51 )
      hkLifoAllocator::slowBlockFree(v53, v51, v54);
    else
      v53->m_cur = v51;
    v62 = 0;
    if ( v63 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v61, 8 * v63);
    v55 = numObjects;
    v56 = (char *)v69;
    v61 = 0i64;
    v63 = 0x80000000;
    if ( v69 == array )
      v55 = 0;
    numObjects = v55;
    v57 = (8 * (_DWORD)p + 127) & 0xFFFFFF80;
    v58 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v59 = (v57 + 15) & 0xFFFFFFF0;
    if ( v57 > v58->m_slabSize || &v56[v59] != v58->m_cur || v58->m_firstNonLifoEnd == v56 )
      hkLifoAllocator::slowBlockFree(v58, v56, v59);
    else
      v58->m_cur = v56;
    numObjects = 0;
    if ( v68 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v68);
  }
  this->m_transform.m_col0 = (hkVector4f)v76->m_quad;
  this->m_transform.m_col1 = (hkVector4f)v76[1].m_quad;
  this->m_transform.m_col2 = (hkVector4f)v76[2].m_quad;
  this->m_transform.m_col3 = (hkVector4f)v76[3].m_quad;
  if ( shape )
    hkReferencedObject::addReference(shape);
  v60 = this->m_shape.m_pntr;
  if ( v60 )
    hkReferencedObject::removeReference(v60);
  this->m_shape.m_pntr = shape;
}

// File Line: 94
// RVA: 0x1319F90
void __fastcall hkMemoryMeshBody::hkMemoryMeshBody(hkMemoryMeshBody *this, hkFinishLoadedObjectFlag flag)
{
  hkStringPtr *p_m_name; // rcx

  p_m_name = &this->m_name;
  p_m_name[-14].m_stringAndFlag = (const char *)&hkMemoryMeshBody::`vftable;
  hkStringPtr::hkStringPtr(p_m_name, flag);
}

// File Line: 98
// RVA: 0x1319EB0
void __fastcall hkMemoryMeshBody::~hkMemoryMeshBody(hkMemoryMeshBody *this)
{
  int v2; // esi
  __int64 v3; // rdi
  int m_capacityAndFlags; // r8d
  hkMeshShape *m_pntr; // rcx
  hkIndexedTransformSet *v6; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryMeshBody::`vftable;
  v2 = 0;
  if ( this->m_vertexBuffers.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_vertexBuffers.m_data[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_vertexBuffers.m_size );
  }
  hkStringPtr::~hkStringPtr(&this->m_name);
  m_capacityAndFlags = this->m_vertexBuffers.m_capacityAndFlags;
  this->m_vertexBuffers.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_vertexBuffers.m_data,
      8 * m_capacityAndFlags);
  this->m_vertexBuffers.m_data = 0i64;
  this->m_vertexBuffers.m_capacityAndFlags = 0x80000000;
  m_pntr = this->m_shape.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_shape.m_pntr = 0i64;
  v6 = this->m_transformSet.m_pntr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  this->m_transformSet.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

