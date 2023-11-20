// File Line: 17
// RVA: 0x1319780
void __fastcall hkMemoryMeshBody::hkMemoryMeshBody(hkMemoryMeshBody *this, hkMeshSystem *meshSystem, hkMeshShape *shape, hkMatrix4f *transform, hkIndexedTransformSetCinfo *transformSet)
{
  __int64 v5; // rsi
  hkMemoryMeshBody *v6; // r12
  hkMeshShape *v7; // r15
  hkIndexedTransformSetCinfo *v8; // rbx
  _QWORD **v9; // rax
  hkIndexedTransformSet *v10; // rax
  hkReferencedObject *v11; // rax
  hkReferencedObject *v12; // rbx
  hkReferencedObject *v13; // rcx
  int v14; // eax
  char *v15; // r8
  __int64 v16; // r14
  hkLifoAllocator *v17; // rax
  int v18; // edx
  char *v19; // rcx
  int v20; // ebx
  hkLifoAllocator *v21; // rax
  char *v22; // rdx
  int v23; // ecx
  LPVOID v24; // rax
  hkLifoAllocator *v25; // rcx
  hkReferencedObject **v26; // rax
  int v27; // edx
  signed int v28; // edi
  int v29; // ecx
  hkBaseObjectVtbl *v30; // rax
  int v31; // ecx
  __int64 v32; // rdi
  signed __int64 v33; // rax
  int v34; // er9
  __int64 v35; // rdi
  __int64 v36; // rsi
  hkReferencedObject **v37; // rbx
  __int64 v38; // rax
  int v39; // eax
  int v40; // eax
  int v41; // er9
  __int64 i; // rdi
  signed __int64 v43; // rbx
  hkReferencedObject *v44; // rbx
  int v45; // eax
  char *v46; // rdi
  signed int v47; // ebx
  hkLifoAllocator *v48; // rax
  int v49; // er8
  int v50; // eax
  char *v51; // rdi
  signed int v52; // ebx
  hkLifoAllocator *v53; // rax
  int v54; // er8
  int v55; // eax
  char *v56; // rdi
  signed int v57; // ebx
  hkLifoAllocator *v58; // rax
  int v59; // er8
  hkReferencedObject *v60; // rcx
  char *v61; // [rsp+30h] [rbp-B8h]
  int v62; // [rsp+38h] [rbp-B0h]
  int v63; // [rsp+3Ch] [rbp-ACh]
  void *v64; // [rsp+40h] [rbp-A8h]
  int v65; // [rsp+48h] [rbp-A0h]
  char *array; // [rsp+50h] [rbp-98h]
  int numObjects; // [rsp+58h] [rbp-90h]
  int v68; // [rsp+5Ch] [rbp-8Ch]
  void *v69; // [rsp+60h] [rbp-88h]
  void *p; // [rsp+68h] [rbp-80h]
  hkReferencedObject **objects; // [rsp+70h] [rbp-78h]
  int v72; // [rsp+78h] [rbp-70h]
  int v73; // [rsp+7Ch] [rbp-6Ch]
  hkReferencedObject *v74; // [rsp+98h] [rbp-50h]
  hkVertexFormat v75; // [rsp+B8h] [rbp-30h]
  hkVector4f *v76; // [rsp+210h] [rbp+128h]
  hkIndexedTransformSetCinfo *info; // [rsp+218h] [rbp+130h]
  hkMatrix4f *v78; // [rsp+228h] [rbp+140h]

  v78 = transform;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v5 = 0i64;
  v6 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryMeshBody::`vftable;
  this->m_transformSet.m_pntr = 0i64;
  this->m_shape.m_pntr = 0i64;
  this->m_vertexBuffers.m_data = 0i64;
  this->m_vertexBuffers.m_size = 0;
  this->m_vertexBuffers.m_capacityAndFlags = 2147483648;
  v7 = shape;
  hkStringPtr::hkStringPtr(&this->m_name);
  hkStringPtr::operator=(&v6->m_name, &customWorldMapCaption);
  v8 = info;
  if ( info )
  {
    v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (hkIndexedTransformSet *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(
                                     v9[11],
                                     104i64);
    if ( v10 )
    {
      hkIndexedTransformSet::hkIndexedTransformSet(v10, v8);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    if ( v12 )
      hkReferencedObject::addReference(v12);
    v13 = (hkReferencedObject *)&v6->m_transformSet.m_pntr->vfptr;
    if ( v13 )
      hkReferencedObject::removeReference(v13);
    v6->m_transformSet.m_pntr = (hkIndexedTransformSet *)v12;
    hkReferencedObject::removeReference(v12);
  }
  if ( v7 )
  {
    v14 = ((__int64 (__fastcall *)(hkMeshShape *))v7->vfptr[1].__first_virtual_table_function__)(v7);
    v16 = v14;
    array = 0i64;
    numObjects = 0;
    v68 = 2147483648;
    LODWORD(p) = v14;
    if ( v14 )
    {
      v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v15 = (char *)v17->m_cur;
      v18 = (8 * v16 + 127) & 0xFFFFFF80;
      v19 = &v15[v18];
      if ( v18 > v17->m_slabSize || v19 > v17->m_end )
      {
        v15 = (char *)hkLifoAllocator::allocateFromNewSlab(v17, v18);
        array = v15;
      }
      else
      {
        v17->m_cur = v19;
        array = v15;
      }
    }
    else
    {
      array = 0i64;
    }
    v20 = 0;
    v61 = 0i64;
    v63 = 2147483648;
    v69 = array;
    v62 = 0;
    v65 = v16;
    v68 = v16 | 0x80000000;
    if ( (_DWORD)v16 )
    {
      v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v22 = (char *)v21->m_cur;
      v23 = (8 * v16 + 127) & 0xFFFFFF80;
      v15 = &v22[v23];
      if ( v23 > v21->m_slabSize || v15 > v21->m_end )
      {
        v20 = v62;
        v22 = (char *)hkLifoAllocator::allocateFromNewSlab(v21, v23);
      }
      else
      {
        v21->m_cur = v15;
        v20 = v62;
      }
    }
    else
    {
      v22 = 0i64;
    }
    v61 = v22;
    v63 = v16 | 0x80000000;
    v64 = v22;
    objects = 0i64;
    v72 = 0;
    v73 = 2147483648;
    LODWORD(objects) = v16;
    if ( (_DWORD)v16 )
    {
      v24 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v25 = (hkLifoAllocator *)v24;
      v26 = (hkReferencedObject **)*((_QWORD *)v24 + 3);
      v27 = (8 * v16 + 127) & 0xFFFFFF80;
      v15 = (char *)v26 + v27;
      if ( v27 > v25->m_slabSize || v15 > v25->m_end )
      {
        v26 = (hkReferencedObject **)hkLifoAllocator::allocateFromNewSlab(v25, v27);
        v20 = v62;
        v22 = v61;
      }
      else
      {
        v25->m_cur = v15;
        v20 = v62;
        v22 = v61;
      }
    }
    else
    {
      v26 = 0i64;
    }
    v73 = v16 | 0x80000000;
    objects = v26;
    p = v26;
    v28 = 0;
    if ( (signed int)v16 > 0 )
    {
      do
      {
        LOBYTE(v15) = 2;
        ((void (__fastcall *)(hkMeshShape *, _QWORD, char *, int *))v7->vfptr[2].__vecDelDtor)(
          v7,
          (unsigned int)v28,
          v15,
          &v72);
        hkReferencedObject::addReference(v74);
        v29 = numObjects;
        if ( numObjects == (v68 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
          v29 = numObjects;
        }
        *(_QWORD *)&array[8 * v29] = v74;
        v30 = v7->vfptr;
        ++numObjects;
        ((void (__fastcall *)(hkMeshShape *, int *))v30[2].__first_virtual_table_function__)(v7, &v72);
        ++v28;
      }
      while ( v28 < (signed int)v16 );
      v20 = v62;
      v22 = v61;
    }
    if ( (signed int)v16 > 0 )
    {
      do
      {
        v31 = 0;
        v32 = *(_QWORD *)&array[8 * v5];
        v33 = 0i64;
        if ( v20 <= 0 )
          goto LABEL_40;
        while ( *(_QWORD *)&v22[8 * v33] != v32 )
        {
          ++v33;
          ++v31;
          if ( v33 >= v20 )
            goto LABEL_40;
        }
        if ( v31 < 0 )
        {
LABEL_40:
          if ( v20 == (v63 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v61, 8);
            v20 = v62;
            v22 = v61;
          }
          *(_QWORD *)&v22[8 * v20] = v32;
          v22 = v61;
          v20 = v62++ + 1;
        }
        ++v5;
      }
      while ( v5 < v16 );
    }
    if ( (v73 & 0x3FFFFFFF) < v20 )
    {
      v34 = v20;
      if ( v20 < 2 * (v73 & 0x3FFFFFFF) )
        v34 = 2 * (v73 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        (hkResult *)&info,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &objects,
        v34,
        8);
    }
    v72 = v20;
    hkVertexFormat::hkVertexFormat(&v75);
    v35 = 0i64;
    v36 = v20;
    if ( v20 > 0 )
    {
      do
      {
        v37 = &objects[v35];
        v38 = (*(__int64 (**)(void))(**(_QWORD **)&v61[8 * v35++] + 24i64))();
        *v37 = (hkReferencedObject *)v38;
      }
      while ( v35 < v36 );
    }
    v39 = v6->m_vertexBuffers.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v39 < (signed int)v16 )
    {
      v40 = 2 * v39;
      v41 = v16;
      if ( (signed int)v16 < v40 )
        v41 = v40;
      hkArrayUtil::_reserve(
        (hkResult *)&info,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v6->m_vertexBuffers,
        v41,
        8);
    }
    v6->m_vertexBuffers.m_size = v16;
    for ( i = 0i64; i < v16; v6->m_vertexBuffers.m_data[i - 1] = (hkMeshVertexBuffer *)v44 )
    {
      v43 = 0i64;
      if ( v62 <= 0i64 )
      {
LABEL_58:
        v43 = -1i64;
      }
      else
      {
        while ( *(_QWORD *)&v61[8 * v43] != *(_QWORD *)&array[8 * i] )
        {
          if ( ++v43 >= v62 )
            goto LABEL_58;
        }
      }
      v44 = objects[v43];
      hkReferencedObject::addReference(v44);
      ++i;
    }
    hkReferencedObject::removeReferences((hkReferencedObject *const *)array, numObjects, 8);
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
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        objects,
        8 * v73);
    v50 = v62;
    v51 = (char *)v64;
    objects = 0i64;
    v73 = 2147483648;
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
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v61,
        8 * v63);
    v55 = numObjects;
    v56 = (char *)v69;
    v61 = 0i64;
    v63 = 2147483648;
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
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v68);
  }
  v6->m_transform.m_col0 = (hkVector4f)v76->m_quad;
  v6->m_transform.m_col1 = (hkVector4f)v76[1].m_quad;
  v6->m_transform.m_col2 = (hkVector4f)v76[2].m_quad;
  v6->m_transform.m_col3 = (hkVector4f)v76[3].m_quad;
  if ( v7 )
    hkReferencedObject::addReference((hkReferencedObject *)&v7->vfptr);
  v60 = (hkReferencedObject *)&v6->m_shape.m_pntr->vfptr;
  if ( v60 )
    hkReferencedObject::removeReference(v60);
  v6->m_shape.m_pntr = v7;
}

// File Line: 94
// RVA: 0x1319F90
void __fastcall hkMemoryMeshBody::hkMemoryMeshBody(hkMemoryMeshBody *this, hkFinishLoadedObjectFlag flag)
{
  hkStringPtr *v2; // rcx

  v2 = &this->m_name;
  v2[-14].m_stringAndFlag = (const char *)&hkMemoryMeshBody::`vftable;
  hkStringPtr::hkStringPtr(v2, flag);
}

// File Line: 98
// RVA: 0x1319EB0
void __fastcall hkMemoryMeshBody::~hkMemoryMeshBody(hkMemoryMeshBody *this)
{
  hkMemoryMeshBody *v1; // rbx
  int v2; // esi
  __int64 v3; // rdi
  int v4; // er8
  hkReferencedObject *v5; // rcx
  hkReferencedObject *v6; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryMeshBody::`vftable;
  v1 = this;
  v2 = 0;
  if ( this->m_vertexBuffers.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_vertexBuffers.m_data[v3]->vfptr);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_vertexBuffers.m_size );
  }
  hkStringPtr::~hkStringPtr(&v1->m_name);
  v4 = v1->m_vertexBuffers.m_capacityAndFlags;
  v1->m_vertexBuffers.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_vertexBuffers.m_data,
      8 * v4);
  v1->m_vertexBuffers.m_data = 0i64;
  v1->m_vertexBuffers.m_capacityAndFlags = 2147483648;
  v5 = (hkReferencedObject *)&v1->m_shape.m_pntr->vfptr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v1->m_shape.m_pntr = 0i64;
  v6 = (hkReferencedObject *)&v1->m_transformSet.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v1->m_transformSet.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

