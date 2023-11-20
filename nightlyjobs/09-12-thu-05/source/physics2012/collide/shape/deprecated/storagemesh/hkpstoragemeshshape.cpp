// File Line: 17
// RVA: 0xD190F0
void __fastcall hkpStorageMeshShape::SubpartStorage::SubpartStorage(hkpStorageMeshShape::SubpartStorage *this, hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageMeshShape::SubpartStorage::`vftable;
}

// File Line: 22
// RVA: 0xD19040
void __fastcall hkpStorageMeshShape::hkpStorageMeshShape(hkpStorageMeshShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpStorageMeshShape *v2; // rbx
  int v3; // er8
  __int64 v4; // r9
  __int64 v5; // r10
  hkpMeshShape::Subpart *v6; // rax
  bool v7; // zf
  hkpStorageMeshShape::SubpartStorage *v8; // rdx
  const void *v9; // rcx
  const void *v10; // rcx
  int v11; // [rsp+38h] [rbp+10h]

  v11 = flag.m_finishing;
  v2 = this;
  hkpMeshShape::hkpMeshShape((hkpMeshShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShape};
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShapeContainer};
  if ( v11 )
  {
    v3 = 0;
    if ( v2->m_subparts.m_size > 0 )
    {
      v4 = 0i64;
      v5 = 0i64;
      do
      {
        v6 = v2->m_subparts.m_data;
        v7 = v6[v5].m_stridingType.m_storage == 1;
        v8 = v2->m_storage.m_data[v4];
        v6[v5].m_vertexBase = v8->m_vertices.m_data;
        if ( v7 )
          v9 = v8->m_indices16.m_data;
        else
          v9 = v8->m_indices32.m_data;
        v7 = v6[v5].m_materialIndexStridingType.m_storage == 1;
        v6[v5].m_indexBase = v9;
        if ( v7 )
          v10 = v8->m_materialIndices.m_data;
        else
          v10 = v8->m_materialIndices16.m_data;
        v6[v5].m_materialIndexBase = v10;
        ++v3;
        v6[v5].m_materialBase = (hkpMeshMaterial *)v8->m_materials.m_data;
        ++v5;
        ++v4;
      }
      while ( v3 < v2->m_subparts.m_size );
    }
  }
}

// File Line: 46
// RVA: 0xD18760
void __fastcall hkpStorageMeshShape::hkpStorageMeshShape(hkpStorageMeshShape *this, float radius, int numbits)
{
  hkpStorageMeshShape *v3; // rbx

  v3 = this;
  hkpMeshShape::hkpMeshShape((hkpMeshShape *)&this->vfptr, radius, numbits);
  v3->vfptr = (hkBaseObjectVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShape};
  v3->vfptr = (hkpShapeContainerVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShapeContainer};
  v3->m_storage.m_capacityAndFlags = 2147483648;
  v3->m_storage.m_data = 0i64;
  v3->m_storage.m_size = 0;
}

// File Line: 50
// RVA: 0xD18900
void __fastcall hkpStorageMeshShape::~hkpStorageMeshShape(hkpStorageMeshShape *this)
{
  int v1; // esi
  hkpStorageMeshShape *v2; // rbx
  __int64 v3; // rdi
  int v4; // er8

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShape};
  v2 = this;
  this->vfptr = (hkpShapeContainerVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShapeContainer};
  if ( this->m_storage.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_storage.m_data[v3]->vfptr);
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_storage.m_size );
  }
  v4 = v2->m_storage.m_capacityAndFlags;
  v2->m_storage.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_storage.m_data,
      8 * v4);
  v2->m_storage.m_data = 0i64;
  v2->m_storage.m_capacityAndFlags = 2147483648;
  hkpMeshShape::~hkpMeshShape((hkpMeshShape *)&v2->vfptr);
}

// File Line: 58
// RVA: 0xD19110
__int64 __fastcall storageMeshShape_numIndices(int stride, int numTri)
{
  int v2; // ecx

  v2 = stride - 1;
  if ( !v2 )
    return (unsigned int)(numTri + 2);
  if ( v2 == 1 )
    return (unsigned int)(2 * numTri + 1);
  return (unsigned int)(3 * numTri);
}

// File Line: 72
// RVA: 0xD187B0
void __fastcall hkpStorageMeshShape::hkpStorageMeshShape(hkpStorageMeshShape *this, hkpMeshShape *mesh)
{
  hkpMeshShape *v2; // rsi
  hkpStorageMeshShape *v3; // rdi
  int v4; // ebx
  int v5; // er8
  __int64 v6; // rax
  unsigned __int16 *v7; // rcx
  __int64 v8; // rdx
  char *v9; // r8
  unsigned __int16 v10; // ax
  int v11; // [rsp+30h] [rbp+8h]

  v2 = mesh;
  v3 = this;
  hkpMeshShape::hkpMeshShape((hkpMeshShape *)&this->vfptr, mesh->m_radius, mesh->m_numBitsForSubpartIndex);
  v4 = 0;
  v3->vfptr = (hkBaseObjectVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShape};
  v3->vfptr = (hkpShapeContainerVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShapeContainer};
  v3->m_storage.m_data = 0i64;
  v3->m_storage.m_size = 0;
  v3->m_storage.m_capacityAndFlags = 2147483648;
  v3->m_scaling = v2->m_scaling;
  v3->m_userData = v2->m_userData;
  for ( v3->m_disableWelding.m_bool = v2->m_disableWelding.m_bool; v4 < v2->m_subparts.m_size; ++v4 )
    hkpStorageMeshShape::addSubpart(v3, &v2->m_subparts.m_data[v4]);
  v5 = v3->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < v2->m_weldingInfo.m_size )
  {
    if ( v3->m_weldingInfo.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3->m_weldingInfo.m_data,
        2 * v5);
    v11 = 2 * v2->m_weldingInfo.m_size;
    v3->m_weldingInfo.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                     &v11);
    v3->m_weldingInfo.m_capacityAndFlags = v11 / 2;
  }
  v6 = v2->m_weldingInfo.m_size;
  v7 = v3->m_weldingInfo.m_data;
  v3->m_weldingInfo.m_size = v6;
  v8 = v6;
  if ( (signed int)v6 > 0 )
  {
    v9 = (char *)((char *)v2->m_weldingInfo.m_data - (char *)v7);
    do
    {
      v10 = *(unsigned __int16 *)((char *)v7 + (_QWORD)v9);
      ++v7;
      *(v7 - 1) = v10;
      --v8;
    }
    while ( v8 );
  }
  v3->m_weldingType.m_storage = v2->m_weldingType.m_storage;
}

// File Line: 115
// RVA: 0xD189D0
void __fastcall hkpStorageMeshShape::addSubpart(hkpStorageMeshShape *this, hkpMeshShape::Subpart *partIn)
{
  hkpMeshShape::Subpart *v2; // rbx
  hkpStorageMeshShape *v3; // r15
  int v4; // esi
  signed __int64 v5; // rcx
  __int64 v6; // rcx
  signed __int64 v7; // rdi
  _QWORD **v8; // rax
  __int64 v9; // rax
  __int64 v10; // r14
  hkArray<hkpStorageMeshShape::SubpartStorage *,hkContainerHeapAllocator> *v11; // r15
  signed int *v12; // r13
  __int64 v13; // rbp
  int v14; // er15
  int v15; // er9
  int v16; // eax
  int v17; // eax
  const float *v18; // rcx
  signed __int64 v19; // rdx
  int i; // er8
  __int64 v21; // rax
  signed int v22; // ecx
  unsigned __int64 v23; // rax
  unsigned __int64 v24; // rax
  int v25; // eax
  __int64 v26; // r15
  int v27; // er9
  int v28; // ecx
  int v29; // ebp
  int v30; // ecx
  __int64 v31; // rax
  _WORD *v32; // rcx
  _WORD *v33; // rdx
  int v34; // er8
  signed __int64 j; // r9
  unsigned __int64 v36; // rax
  int v37; // eax
  __int64 v38; // r15
  int v39; // er9
  int v40; // ecx
  int v41; // ebp
  int v42; // ecx
  __int64 v43; // rax
  _DWORD *v44; // rcx
  _DWORD *v45; // rdx
  int v46; // er8
  int v47; // eax
  _BYTE *v48; // r15
  int v49; // eax
  int v50; // er14
  __int64 v51; // r15
  int v52; // er9
  int v53; // eax
  int v54; // er8
  __int64 v55; // rcx
  _BYTE *k; // rdx
  int v57; // eax
  int v58; // er15
  __int64 v59; // rbp
  int v60; // er9
  int v61; // eax
  int v62; // er8
  signed __int64 v63; // rdx
  _WORD *l; // rcx
  int v65; // eax
  hkVector4f **v66; // r14
  int v67; // eax
  hkpMeshMaterial *v68; // r15
  hkVector4f *v69; // rax
  int v70; // er15
  __int64 v71; // rbp
  int v72; // er9
  int v73; // eax
  hkpMeshMaterial *v74; // rcx
  signed __int64 v75; // rdx
  hkResult result; // [rsp+60h] [rbp+8h]

  v2 = partIn;
  v3 = this;
  if ( this->m_subparts.m_size == (this->m_subparts.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->m_subparts, 80);
  v4 = 0;
  v5 = (signed __int64)&v3->m_subparts.m_data[v3->m_subparts.m_size];
  if ( v5 )
  {
    *(_BYTE *)(v5 + 25) = 1;
    *(_DWORD *)(v5 + 48) = 0;
    *(_DWORD *)(v5 + 64) = 0;
    *(_DWORD *)(v5 + 68) = 1;
    *(_QWORD *)(v5 + 56) = 0i64;
    *(_QWORD *)(v5 + 40) = 0i64;
    *(_DWORD *)(v5 + 72) = -1;
    *(_DWORD *)(v5 + 32) = 0;
  }
  v6 = v3->m_subparts.m_size;
  v3->m_subparts.m_size = v6 + 1;
  v7 = (signed __int64)&v3->m_subparts.m_data[v6];
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 112i64);
  v10 = v9;
  if ( v9 )
  {
    *(_DWORD *)(v9 + 8) = 0x1FFFF;
    *(_QWORD *)v9 = &hkpStorageMeshShape::SubpartStorage::`vftable;
    *(_QWORD *)(v9 + 16) = 0i64;
    *(_DWORD *)(v9 + 24) = 0;
    *(_DWORD *)(v9 + 28) = 2147483648;
    *(_QWORD *)(v9 + 32) = 0i64;
    *(_DWORD *)(v9 + 40) = 0;
    *(_DWORD *)(v9 + 44) = 2147483648;
    *(_QWORD *)(v9 + 48) = 0i64;
    *(_DWORD *)(v9 + 56) = 0;
    *(_DWORD *)(v9 + 60) = 2147483648;
    *(_QWORD *)(v9 + 64) = 0i64;
    *(_DWORD *)(v9 + 72) = 0;
    *(_DWORD *)(v9 + 76) = 2147483648;
    *(_QWORD *)(v9 + 80) = 0i64;
    *(_DWORD *)(v9 + 88) = 0;
    *(_DWORD *)(v9 + 92) = 2147483648;
    *(_QWORD *)(v9 + 96) = 0i64;
    *(_DWORD *)(v9 + 104) = 0;
    *(_DWORD *)(v9 + 108) = 2147483648;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = &v3->m_storage;
  if ( v11->m_size == (v11->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 8);
  v11->m_data[v11->m_size++] = (hkpStorageMeshShape::SubpartStorage *)v10;
  v12 = (signed int *)v11->m_data[v11->m_size - 1];
  v13 = v12[6];
  v14 = 3 * v2->m_numVertices;
  v15 = v14 + v13;
  v16 = v12[7] & 0x3FFFFFFF;
  if ( v16 < v14 + (signed int)v13 )
  {
    v17 = 2 * v16;
    if ( v15 < v17 )
      v15 = v17;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12 + 4, v15, 4);
  }
  v12[6] += v14;
  v18 = v2->m_vertexBase;
  v19 = *((_QWORD *)v12 + 2) + 4 * v13;
  for ( i = 0; i < v2->m_numVertices; v18 = (const float *)((char *)v18 + v2->m_vertexStriding) )
  {
    ++i;
    v19 += 12i64;
    *(float *)(v19 - 12) = *v18;
    *(float *)(v19 - 8) = v18[1];
    *(float *)(v19 - 4) = v18[2];
  }
  v21 = *((_QWORD *)v12 + 2);
  *(_DWORD *)(v7 + 8) = 12;
  v22 = 3;
  *(_QWORD *)v7 = v21;
  *(_DWORD *)(v7 + 12) = v2->m_numVertices;
  v23 = v2->m_indexStriding;
  if ( v2->m_stridingType.m_storage == 1 )
  {
    v24 = v23 >> 1;
    if ( (signed int)v24 <= 2 )
      v22 = v24;
    *(_DWORD *)(v7 + 28) = 2 * v22;
    v25 = storageMeshShape_numIndices(v24, v2->m_numTriangles);
    v26 = v12[10];
    v27 = v26 + v25;
    v28 = v12[11] & 0x3FFFFFFF;
    v29 = v25;
    if ( v28 < (signed int)v26 + v25 )
    {
      v30 = 2 * v28;
      if ( v27 < v30 )
        v27 = v30;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12 + 8, v27, 2);
    }
    v12[10] += v29;
    v31 = *((_QWORD *)v12 + 4);
    v32 = v2->m_indexBase;
    v33 = (_WORD *)(v31 + 2 * v26);
    v34 = 0;
    for ( j = v31 + 2 * v26; v34 < v2->m_numTriangles; v32 = (_WORD *)((char *)v32 + v2->m_indexStriding) )
    {
      ++v34;
      *v33 = *v32;
      v33[1] = v32[1];
      v33[2] = v32[2];
      v33 = (_WORD *)((char *)v33 + *(signed int *)(v7 + 28));
    }
  }
  else
  {
    v36 = v23 >> 2;
    if ( (signed int)v36 <= 2 )
      v22 = v36;
    *(_DWORD *)(v7 + 28) = 4 * v22;
    v37 = storageMeshShape_numIndices(v36, v2->m_numTriangles);
    v38 = v12[14];
    v39 = v38 + v37;
    v40 = v12[15] & 0x3FFFFFFF;
    v41 = v37;
    if ( v40 < (signed int)v38 + v37 )
    {
      v42 = 2 * v40;
      if ( v39 < v42 )
        v39 = v42;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12 + 12, v39, 4);
    }
    v12[14] += v41;
    v43 = *((_QWORD *)v12 + 6);
    v44 = v2->m_indexBase;
    v45 = (_DWORD *)(v43 + 4 * v38);
    v46 = 0;
    for ( j = v43 + 4 * v38; v46 < v2->m_numTriangles; v44 = (_DWORD *)((char *)v44 + v2->m_indexStriding) )
    {
      ++v46;
      *v45 = *v44;
      v45[1] = v44[1];
      v45[2] = v44[2];
      v45 = (_DWORD *)((char *)v45 + *(signed int *)(v7 + 28));
    }
  }
  *(_BYTE *)(v7 + 24) = v2->m_stridingType.m_storage;
  *(_DWORD *)(v7 + 36) = v2->m_numTriangles;
  v47 = v2->m_flipAlternateTriangles;
  *(_QWORD *)(v7 + 16) = j;
  *(_DWORD *)(v7 + 32) = v47;
  *(_BYTE *)(v7 + 25) = v2->m_materialIndexStridingType.m_storage;
  v48 = v2->m_materialIndexBase;
  if ( v48 )
  {
    if ( v2->m_materialIndexStridingType.m_storage == 1 )
    {
      v49 = v12[19] & 0x3FFFFFFF;
      if ( v2->m_materialIndexStriding )
      {
        v50 = v2->m_numTriangles;
        v51 = v12[18];
        v52 = v50 + v51;
        if ( v49 < v50 + (signed int)v51 )
        {
          v53 = 2 * v49;
          if ( v52 < v53 )
            v52 = v53;
          hkArrayUtil::_reserve(
            &result,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v12 + 16,
            v52,
            1);
        }
        v12[18] += v50;
        v54 = 0;
        v55 = *((_QWORD *)v12 + 8) + v51;
        *(_QWORD *)(v7 + 40) = v55;
        for ( k = v2->m_materialIndexBase; v54 < v2->m_numTriangles; k += v2->m_materialIndexStriding )
        {
          ++v54;
          *(_BYTE *)(++v55 - 1) = *k;
        }
      }
      else
      {
        if ( v12[18] == v49 )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12 + 16, 1);
        *(_BYTE *)(*((_QWORD *)v12 + 8) + v12[18]++) = *v48;
        *(_QWORD *)(v7 + 40) = *((_QWORD *)v12 + 8) + v12[18] - 1;
      }
    }
    else
    {
      v57 = v12[27] & 0x3FFFFFFF;
      if ( v2->m_materialIndexStriding )
      {
        v58 = v2->m_numTriangles;
        v59 = v12[26];
        v60 = v58 + v59;
        if ( v57 < v58 + (signed int)v59 )
        {
          v61 = 2 * v57;
          if ( v60 < v61 )
            v60 = v61;
          hkArrayUtil::_reserve(
            &result,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v12 + 24,
            v60,
            2);
        }
        v12[26] += v58;
        v62 = 0;
        v63 = *((_QWORD *)v12 + 12) + 2 * v59;
        *(_QWORD *)(v7 + 40) = v63;
        for ( l = v2->m_materialIndexBase; v62 < v2->m_numTriangles; l = (_WORD *)((char *)l
                                                                                 + v2->m_materialIndexStriding) )
        {
          ++v62;
          v63 += 2i64;
          *(_WORD *)(v63 - 2) = *l;
        }
      }
      else
      {
        if ( v12[26] == v57 )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12 + 24, 2);
        *(_WORD *)(*((_QWORD *)v12 + 12) + 2i64 * v12[26]++) = *(_WORD *)v48;
        *(_QWORD *)(v7 + 40) = *((_QWORD *)v12 + 12) + 2i64 * (v12[26] - 1);
      }
    }
    v65 = v2->m_materialIndexStriding;
    *(_DWORD *)(v7 + 48) = v65;
    if ( v65 )
    {
      if ( *(_BYTE *)(v7 + 25) == 1 )
      {
        *(_DWORD *)(v7 + 48) = 1;
      }
      else if ( *(_BYTE *)(v7 + 25) == 2 )
      {
        *(_DWORD *)(v7 + 48) = 2;
      }
    }
  }
  else
  {
    *(_QWORD *)(v7 + 40) = 0i64;
    *(_DWORD *)(v7 + 48) = 0;
  }
  if ( *(_QWORD *)(v7 + 40) )
  {
    v66 = (hkVector4f **)(v12 + 20);
    v67 = v12[23] & 0x3FFFFFFF;
    if ( v2->m_materialStriding )
    {
      v70 = v2->m_numMaterials;
      v71 = v12[22];
      v72 = v70 + v71;
      if ( v67 < v70 + (signed int)v71 )
      {
        v73 = 2 * v67;
        if ( v72 < v73 )
          v72 = v73;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12 + 20, v72, 4);
      }
      v12[22] += v70;
      v74 = v2->m_materialBase;
      v75 = (signed __int64)*v66 + 4 * v71;
      if ( v2->m_numMaterials > 0 )
      {
        do
        {
          ++v4;
          v75 += 4i64;
          *(hkpMeshMaterial *)(v75 - 4) = (hkpMeshMaterial)v74->m_filterInfo;
          v74 = (hkpMeshMaterial *)((char *)v74 + v2->m_materialStriding);
        }
        while ( v4 < v2->m_numMaterials );
      }
      *(_DWORD *)(v7 + 64) = 8;
      *(_DWORD *)(v7 + 68) = v2->m_numMaterials;
      v69 = *v66;
    }
    else
    {
      v68 = v2->m_materialBase;
      if ( v12[22] == v67 )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12 + 20, 4);
      LODWORD((*v66)->m_quad.m128_f32[v12[22]++]) = (hkpMeshMaterial)v68->m_filterInfo;
      *(_DWORD *)(v7 + 64) = 0;
      *(_DWORD *)(v7 + 68) = 1;
      v69 = *v66;
    }
  }
  else
  {
    v69 = &aabbOut;
    *(_DWORD *)(v7 + 68) = 1;
    *(_DWORD *)(v7 + 64) = 0;
    *(_QWORD *)(v7 + 40) = &aabbOut;
  }
  *(_QWORD *)(v7 + 56) = v69;
  *(_DWORD *)(v7 + 72) = v2->m_triangleOffset;
}

