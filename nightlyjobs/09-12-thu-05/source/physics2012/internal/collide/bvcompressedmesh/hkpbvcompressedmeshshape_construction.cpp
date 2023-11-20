// File Line: 29
// RVA: 0xDE82B0
void __fastcall hkpBvCompressedMeshShape::hkpBvCompressedMeshShape(hkpBvCompressedMeshShape *this, hkpBvCompressedMeshShapeCinfo *cInfo)
{
  char *v2; // rdi
  hkpBvCompressedMeshShape *v3; // r15
  hkpBvCompressedMeshShapeCinfo *v4; // rsi
  hkArray<hkStringPtr,hkContainerHeapAllocator> *v5; // rax
  __int64 v6; // r12
  int v7; // eax
  __int64 v8; // r14
  __int64 v9; // rbx
  int v10; // ecx
  unsigned int v11; // eax
  int v12; // ecx
  __int64 v13; // r13
  int v14; // ecx
  int v15; // eax
  unsigned int *v16; // r12
  int v17; // er15
  int v18; // ebx
  __int64 v19; // rdi
  unsigned int v20; // eax
  int v21; // ebx
  signed __int64 v22; // rdi
  unsigned int v23; // eax
  int v24; // er8
  __int64 v25; // rdi
  int v26; // ecx
  int v27; // eax
  int v28; // ebx
  __int64 v29; // rdi
  unsigned __int8 v30; // al
  _DWORD *v31; // rcx
  int v32; // ebx
  signed __int64 v33; // rdi
  unsigned __int8 v34; // al
  char *v35; // rcx
  int v36; // edx
  __int64 v37; // rcx
  int v38; // eax
  unsigned int *v39; // r15
  int v40; // er14
  hkStringPtr *v41; // rdi
  signed int v42; // edi
  unsigned int *v43; // rbx
  int v44; // er12
  int v45; // edi
  signed __int64 v46; // rbx
  int v47; // er8
  __int64 v48; // rdi
  int v49; // ecx
  int v50; // eax
  int v51; // edi
  hkStringPtr *v52; // rbx
  unsigned int *v53; // rdx
  __int64 v54; // r8
  int v55; // eax
  unsigned int *v56; // r12
  int v57; // er15
  int v58; // ebx
  __int64 v59; // rdi
  unsigned int v60; // eax
  __int64 v61; // r14
  int v62; // ebx
  signed __int64 v63; // rdi
  unsigned int v64; // eax
  int v65; // er8
  __int64 v66; // rdi
  int v67; // ecx
  int v68; // eax
  int v69; // ebx
  __int64 i; // rdi
  unsigned __int8 v71; // al
  _DWORD *v72; // rcx
  __int64 v73; // r14
  int v74; // ebx
  signed __int64 v75; // rdi
  unsigned __int8 v76; // al
  char *v77; // rcx
  int v78; // edx
  __int64 v79; // rcx
  char v80; // bl
  hkBool v81; // dl
  __int64 k; // rdi
  __int64 j; // rcx
  signed __int64 v84; // rcx
  int v85; // eax
  int v86; // er14
  int v87; // er9
  float v88; // xmm1_4
  float v89; // xmm1_4
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v90; // rcx
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v91; // rcx
  hkArray<unsigned int,hkContainerHeapAllocator> indices; // [rsp+30h] [rbp-D0h]
  char *v93; // [rsp+40h] [rbp-C0h]
  int v94; // [rsp+48h] [rbp-B8h]
  int v95; // [rsp+4Ch] [rbp-B4h]
  __int64 v96; // [rsp+50h] [rbp-B0h]
  hkArray<unsigned int,hkContainerHeapAllocator> values; // [rsp+58h] [rbp-A8h]
  hkcdStaticMeshTreeBase::BuildMapping mapping; // [rsp+68h] [rbp-98h]
  int v99; // [rsp+98h] [rbp-68h]
  hkpBvCompressedMeshShape_Internals::GeometryProvider baseProvider; // [rsp+A0h] [rbp-60h]
  hkcdStaticMeshTreeBase::BuildConfig baseConfig; // [rsp+C0h] [rbp-40h]
  hkArray<hkStringPtr,hkContainerHeapAllocator> *palette; // [rsp+F0h] [rbp-10h]
  hkpBvCompressedMeshShape *result; // [rsp+150h] [rbp+50h]
  unsigned int v104; // [rsp+158h] [rbp+58h]
  int v105; // [rsp+160h] [rbp+60h]

  result = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1041;
  v2 = 0i64;
  this->m_userData = 0i64;
  this->m_bvTreeType.m_storage = 3;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBvCompressedMeshShape::`vftable{for `hkpBvTreeShape};
  v3 = this;
  this->vfptr = (hkpShapeContainerVtbl *)&hkpBvCompressedMeshShape::`vftable{for `hkpShapeContainer};
  v4 = cInfo;
  this->m_convexRadius = cInfo->m_convexRadius;
  this->m_weldingType.m_storage = cInfo->m_weldingType;
  this->m_collisionFilterInfoPalette.m_data = 0i64;
  this->m_collisionFilterInfoPalette.m_size = 0;
  this->m_collisionFilterInfoPalette.m_capacityAndFlags = 2147483648;
  v5 = &this->m_userStringPalette;
  this->m_userDataPalette.m_data = 0i64;
  this->m_userDataPalette.m_size = 0;
  this->m_userDataPalette.m_capacityAndFlags = 2147483648;
  v5->m_data = 0i64;
  v5->m_size = 0;
  v5->m_capacityAndFlags = 2147483648;
  palette = &this->m_userStringPalette;
  v6 = cInfo->vfptr->getNumTriangles(cInfo);
  v7 = v4->vfptr->getNumConvexShapes(v4);
  v8 = v7;
  v9 = (unsigned int)(v7 + v6);
  v99 = v7;
  v104 = v7 + v6;
  if ( v3 != (hkpBvCompressedMeshShape *)-112i64 )
    hkpBvCompressedMeshShapeTree::hkpBvCompressedMeshShapeTree((hkpBvCompressedMeshShapeTree *)v3->m_tree);
  v10 = v9;
  v93 = 0i64;
  v94 = 0;
  v95 = 2147483648;
  if ( (_DWORD)v9 )
  {
    v105 = 4 * v9;
    v2 = (char *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                   (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                   &v105);
    v10 = v105 / 4;
  }
  v11 = 2147483648;
  v93 = v2;
  if ( v10 )
    v11 = v10;
  v12 = (unsigned __int8)v4->m_collisionFilterInfoMode.m_storage;
  v94 = v9;
  v95 = v11;
  v13 = v6;
  v96 = v8;
  if ( v12 )
  {
    v14 = v12 - 1;
    if ( v14 )
    {
      if ( v14 != 1 )
      {
        v3->m_hasPerPrimitiveCollisionFilterInfo.m_bool = 0;
        goto LABEL_30;
      }
      v3->m_hasPerPrimitiveCollisionFilterInfo.m_bool = 1;
      v15 = v9;
      if ( (_DWORD)v9 )
      {
        v105 = 4 * v9;
        v16 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                &v105);
        v15 = v105 / 4;
      }
      else
      {
        v16 = 0i64;
      }
      v17 = 2147483648;
      values.m_size = v9;
      if ( v15 )
        v17 = v15;
      v18 = 0;
      v19 = 0i64;
      values.m_capacityAndFlags = v17;
      for ( values.m_data = v16; v19 < v13; v16[v19 - 1] = v20 )
      {
        v20 = v4->vfptr->getTriangleCollisionFilterInfo(v4, v18);
        ++v19;
        ++v18;
      }
      v21 = 0;
      if ( v8 > 0 )
      {
        v22 = (signed __int64)&v16[v13];
        do
        {
          v23 = v4->vfptr->getConvexShapeCollisionFilterInfo(v4, v21++);
          v22 += 4i64;
          *(_DWORD *)(v22 - 4) = v23;
          --v8;
        }
        while ( v8 );
      }
      indices.m_data = 0i64;
      indices.m_size = 0;
      indices.m_capacityAndFlags = 2147483648;
      createIntPalette(&values, 8, &result->m_collisionFilterInfoPalette, &indices);
      v24 = 0;
      if ( v94 > 0 )
      {
        v25 = 0i64;
        do
        {
          ++v24;
          v26 = LOBYTE(indices.m_data[v25]);
          v27 = *(_DWORD *)&v93[v25 * 4];
          ++v25;
          *(_DWORD *)&v93[v25 * 4 - 4] = v27 & 0xFFFFFF00 | v26;
        }
        while ( v24 < v94 );
      }
      indices.m_size = 0;
      if ( indices.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          indices.m_data,
          4 * indices.m_capacityAndFlags);
      if ( v17 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v16,
          4 * v17);
      v3 = result;
      LODWORD(v6) = v13;
    }
    else
    {
      v28 = 0;
      v29 = 0i64;
      v3->m_hasPerPrimitiveCollisionFilterInfo.m_bool = 1;
      if ( (signed int)v6 > 0 )
      {
        do
        {
          v30 = v4->vfptr->getTriangleCollisionFilterInfo(v4, v28);
          v31 = v93;
          v31[++v29 - 1] &= 0xFFFFFF00;
          ++v28;
          v31[v29 - 1] |= v30;
        }
        while ( v29 < v6 );
      }
      v32 = 0;
      if ( v8 > 0 )
      {
        v33 = 4 * v6;
        do
        {
          v34 = v4->vfptr->getConvexShapeCollisionFilterInfo(v4, v32);
          v35 = v93;
          ++v32;
          *(_DWORD *)&v35[v33] &= 0xFFFFFF00;
          v33 += 4i64;
          *(_DWORD *)&v35[v33 - 4] |= v34;
          --v8;
        }
        while ( v8 );
      }
    }
    v9 = v104;
  }
  else
  {
    v36 = 0;
    v3->m_hasPerPrimitiveCollisionFilterInfo.m_bool = 0;
    if ( (signed int)v9 > 0 )
    {
      v37 = 0i64;
      do
      {
        ++v36;
        v37 += 4i64;
        v93[v37 - 4] = 0;
      }
      while ( v36 < v94 );
    }
  }
LABEL_30:
  if ( !v4->m_userDataMode.m_storage )
  {
    v3->m_hasPerPrimitiveUserData.m_bool = 0;
    v78 = 0;
    if ( v94 > 0 )
    {
      v79 = 0i64;
      do
      {
        ++v78;
        v79 += 4i64;
        v93[v79 - 3] = 0;
      }
      while ( v78 < v94 );
    }
    goto LABEL_99;
  }
  if ( v4->m_userDataMode.m_storage != 1 )
  {
    if ( v4->m_userDataMode.m_storage == 2 )
    {
      v3->m_hasPerPrimitiveUserData.m_bool = 1;
      v55 = v9;
      if ( (_DWORD)v9 )
      {
        v104 = 4 * v9;
        v56 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                (int *)&v104);
        v55 = (signed int)v104 / 4;
      }
      else
      {
        v56 = 0i64;
      }
      v57 = 2147483648;
      values.m_size = v9;
      if ( v55 )
        v57 = v55;
      v58 = 0;
      v59 = 0i64;
      values.m_capacityAndFlags = v57;
      for ( values.m_data = v56; v59 < v13; v56[v59 - 1] = v60 )
      {
        v60 = v4->vfptr->getTriangleUserData(v4, v58);
        ++v59;
        ++v58;
      }
      v61 = v96;
      v62 = 0;
      if ( v96 > 0 )
      {
        v63 = (signed __int64)&v56[v13];
        do
        {
          v64 = v4->vfptr->getConvexShapeUserData(v4, v62++);
          v63 += 4i64;
          *(_DWORD *)(v63 - 4) = v64;
          --v61;
        }
        while ( v61 );
      }
      indices.m_data = 0i64;
      indices.m_size = 0;
      indices.m_capacityAndFlags = 2147483648;
      createIntPalette(&values, 8, &result->m_userDataPalette, &indices);
      v65 = 0;
      if ( v94 > 0 )
      {
        v66 = 0i64;
        do
        {
          ++v65;
          v67 = LOBYTE(indices.m_data[v66]);
          v68 = *(_DWORD *)&v93[v66 * 4];
          ++v66;
          *(_DWORD *)&v93[v66 * 4 - 4] = v68 & 0xFFFF00FF | (v67 << 8);
        }
        while ( v65 < v94 );
      }
      indices.m_size = 0;
      if ( indices.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          indices.m_data,
          4 * indices.m_capacityAndFlags);
      if ( v57 < 0 )
        goto LABEL_72;
      v53 = v56;
      v54 = (unsigned int)(4 * v57);
    }
    else
    {
      if ( v4->m_userDataMode.m_storage != 3 )
      {
        v3->m_hasPerPrimitiveUserData.m_bool = 0;
LABEL_99:
        v73 = v96;
        goto LABEL_100;
      }
      v3->m_hasPerPrimitiveUserData.m_bool = 1;
      v38 = v9;
      if ( (_DWORD)v9 )
      {
        v105 = 8 * v9;
        v39 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                &v105);
        v38 = v105 / 8;
      }
      else
      {
        v39 = 0i64;
      }
      v40 = 2147483648;
      values.m_data = v39;
      if ( v38 )
        v40 = v38;
      values.m_size = v9;
      values.m_capacityAndFlags = v40;
      if ( (signed int)v9 > 0 )
      {
        v41 = (hkStringPtr *)v39;
        do
        {
          if ( v41 )
            hkStringPtr::hkStringPtr(v41);
          ++v41;
          --v9;
        }
        while ( v9 );
      }
      v42 = 0;
      if ( (signed int)v6 > 0 )
      {
        v43 = v39;
        do
        {
          v4->vfptr->getTriangleUserString(v4, v42++, (hkStringPtr *)v43);
          v43 += 2;
        }
        while ( v42 < (signed int)v6 );
      }
      v44 = v99;
      v45 = 0;
      if ( v99 > 0 )
      {
        v46 = (signed __int64)&v39[2 * v13];
        do
        {
          v4->vfptr->getConvexShapeUserString(v4, v45++, (hkStringPtr *)v46);
          v46 += 8i64;
        }
        while ( v45 < v44 );
      }
      indices.m_data = 0i64;
      indices.m_size = 0;
      indices.m_capacityAndFlags = 2147483648;
      createStringPalette((hkArray<hkStringPtr,hkContainerHeapAllocator> *)&values, 8, palette, &indices);
      v47 = 0;
      if ( v94 > 0 )
      {
        v48 = 0i64;
        do
        {
          ++v47;
          v49 = LOBYTE(indices.m_data[v48]);
          v50 = *(_DWORD *)&v93[v48 * 4];
          ++v48;
          *(_DWORD *)&v93[v48 * 4 - 4] = v50 & 0xFFFF00FF | (v49 << 8);
        }
        while ( v47 < v94 );
      }
      indices.m_size = 0;
      if ( indices.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          indices.m_data,
          4 * indices.m_capacityAndFlags);
      v51 = v104 - 1;
      if ( (signed int)(v104 - 1) >= 0 )
      {
        v52 = (hkStringPtr *)&v39[2 * v51];
        do
        {
          hkStringPtr::~hkStringPtr(v52);
          --v52;
          --v51;
        }
        while ( v51 >= 0 );
      }
      if ( v40 < 0 )
      {
LABEL_72:
        v3 = result;
        goto LABEL_99;
      }
      v53 = v39;
      v54 = (unsigned int)(8 * v40);
    }
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc, v53, v54);
    goto LABEL_72;
  }
  v3->m_hasPerPrimitiveUserData.m_bool = 1;
  v69 = 0;
  for ( i = 0i64; i < v13; v72[i - 1] |= v71 << 8 )
  {
    v71 = v4->vfptr->getTriangleUserData(v4, v69);
    v72 = v93;
    v72[++i - 1] &= 0xFFFF00FF;
    ++v69;
  }
  v73 = v96;
  v74 = 0;
  if ( v96 > 0 )
  {
    v75 = 4 * v13;
    do
    {
      v76 = v4->vfptr->getConvexShapeUserData(v4, v74);
      v77 = v93;
      ++v74;
      *(_DWORD *)&v77[v75] &= 0xFFFF00FF;
      v75 += 4i64;
      *(_DWORD *)&v77[v75 - 4] |= v76 << 8;
      --v73;
    }
    while ( v73 );
    goto LABEL_99;
  }
LABEL_100:
  v80 = v4->m_preserveVertexOrder.m_bool;
  if ( v4->m_weldingType == 6 )
  {
    for ( j = 0i64; j < v13; *(_WORD *)&v93[4 * j - 2] = 0 )
      ++j;
  }
  else
  {
    v81.m_bool = v4->m_weldOpenEdges.m_bool;
    v80 = 1;
    indices.m_data = 0i64;
    indices.m_size = 0;
    indices.m_capacityAndFlags = 2147483648;
    computeWeldingInfo(v4, v81, (hkArray<unsigned short,hkContainerHeapAllocator> *)&indices);
    for ( k = 0i64;
          k < v13;
          *(_DWORD *)&v93[4 * k - 4] = *(unsigned __int16 *)&v93[4 * k - 4] | (*((unsigned __int16 *)indices.m_data
                                                                               + k
                                                                               - 1) << 16) )
    {
      ++k;
    }
    indices.m_size = 0;
    if ( indices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        indices.m_data,
        2 * (indices.m_capacityAndFlags & 0x3FFFFFFF));
  }
  if ( v73 > 0 )
  {
    v84 = 4 * v13;
    do
    {
      v84 += 4i64;
      *(_WORD *)&v93[v84 - 2] = 0;
      --v73;
    }
    while ( v73 );
  }
  baseProvider.m_meshCInfo = v4;
  baseProvider.m_caches.m_data = 0i64;
  baseProvider.m_caches.m_size = 0;
  baseProvider.m_caches.m_capacityAndFlags = 2147483648;
  baseProvider.m_primitiveData = (hkArray<hkpBvCompressedMeshShape_Internals::PrimitiveData,hkContainerHeapAllocator> *)&v93;
  v85 = v4->vfptr->getNumConvexShapes(v4);
  v86 = v85;
  if ( (baseProvider.m_caches.m_capacityAndFlags & 0x3FFFFFFF) < v85 )
  {
    v87 = v85;
    if ( v85 < 2 * (baseProvider.m_caches.m_capacityAndFlags & 0x3FFFFFFF) )
      v87 = 2 * (baseProvider.m_caches.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &baseProvider.m_caches,
      v87,
      8);
  }
  if ( v86 - baseProvider.m_caches.m_size > 0 )
    memset(&baseProvider.m_caches.m_data[baseProvider.m_caches.m_size], 0, 8i64 * (v86 - baseProvider.m_caches.m_size));
  v88 = v4->m_vertexWeldingTolerance;
  baseConfig.m_convexRadius = v4->m_convexRadius;
  baseConfig.m_weldTolerance = v88;
  baseProvider.m_caches.m_size = v86;
  *(_WORD *)&baseConfig.m_globalOptimizations.m_bool = 256;
  baseConfig.m_forceConvexQuads.m_bool = 0;
  v89 = v4->m_maxVerticesError;
  baseConfig.m_degenerateTolerance = hkDefaultTriangleDegeneracyTolerance;
  baseConfig.m_vertexHasFlags.m_bool = 0;
  *(_QWORD *)&baseConfig.m_balanceThreshold = 0i64;
  *(_QWORD *)&baseConfig.m_pbd = 1i64;
  baseConfig.m_maxCompressionError = v89;
  baseConfig.m_weldVertices.m_bool = 1;
  baseConfig.m_preserveVertexOrder.m_bool = v80;
  mapping.m_triangleIndexToKey.m_data = 0i64;
  mapping.m_triangleIndexToKey.m_size = 0;
  mapping.m_triangleIndexToKey.m_capacityAndFlags = 2147483648;
  mapping.m_customIndexToKey.m_data = 0i64;
  mapping.m_customIndexToKey.m_size = 0;
  mapping.m_customIndexToKey.m_capacityAndFlags = 2147483648;
  mapping.m_triangleVertexRotations.m_data = 0i64;
  mapping.m_triangleVertexRotations.m_size = 0;
  mapping.m_triangleVertexRotations.m_capacityAndFlags = 2147483648;
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::build<hkpBvCompressedMeshShape_Internals::GeometryProvider>(
    (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)v3->m_tree,
    &baseConfig,
    &baseProvider,
    &mapping);
  v90 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v4->m_triangleIndexToShapeKeyMap;
  if ( v90 )
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      v90,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&mapping);
  v91 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v4->m_convexShapeIndexToShapeKeyMap;
  if ( v91 )
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      v91,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&mapping.m_customIndexToKey);
  mapping.m_triangleVertexRotations.m_size = 0;
  if ( mapping.m_triangleVertexRotations.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      mapping.m_triangleVertexRotations.m_data,
      mapping.m_triangleVertexRotations.m_capacityAndFlags & 0x3FFFFFFF);
  mapping.m_triangleVertexRotations.m_data = 0i64;
  mapping.m_triangleVertexRotations.m_capacityAndFlags = 2147483648;
  mapping.m_customIndexToKey.m_size = 0;
  if ( mapping.m_customIndexToKey.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      mapping.m_customIndexToKey.m_data,
      4 * mapping.m_customIndexToKey.m_capacityAndFlags);
  mapping.m_customIndexToKey.m_data = 0i64;
  mapping.m_customIndexToKey.m_capacityAndFlags = 2147483648;
  mapping.m_triangleIndexToKey.m_size = 0;
  if ( mapping.m_triangleIndexToKey.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      mapping.m_triangleIndexToKey.m_data,
      4 * mapping.m_triangleIndexToKey.m_capacityAndFlags);
  mapping.m_triangleIndexToKey.m_data = 0i64;
  mapping.m_triangleIndexToKey.m_capacityAndFlags = 2147483648;
  hkpBvCompressedMeshShape_Internals::GeometryProvider::~GeometryProvider(&baseProvider);
  v94 = 0;
  if ( v95 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v93,
      4 * v95);
}r *)&hkContainerHeapAllocator::s_alloc,
      v93,
      4 * v95);
}

// File Line: 294
// RVA: 0xDE8D40
void __fastcall hkpBvCompressedMeshShape::hkpBvCompressedMeshShape(hkpBvCompressedMeshShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpBvCompressedMeshShape *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = flag.m_finishing;
  v2 = this;
  hkpBvTreeShape::hkpBvTreeShape((hkpBvTreeShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpBvCompressedMeshShape::`vftable{for `hkpBvTreeShape};
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpBvCompressedMeshShape::`vftable{for `hkpShapeContainer};
  if ( v3 )
  {
    v2->m_type.m_storage = 17;
    v2->m_bvTreeType.m_storage = 3;
  }
}

// File Line: 303
// RVA: 0xDE8D90
void __fastcall hkpBvCompressedMeshShape::~hkpBvCompressedMeshShape(hkpBvCompressedMeshShape *this)
{
  hkpBvCompressedMeshShape *v1; // rdi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *v2; // rcx
  int v3; // ebx
  hkStringPtr *v4; // rsi
  int v5; // er8
  int v6; // er8
  int v7; // er8

  v1 = this;
  v2 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)this->m_tree;
  *(_QWORD *)&v2[-1].m_numPrimitiveKeys = &hkpBvCompressedMeshShape::`vftable{for `hkpBvTreeShape};
  *(_QWORD *)&v2[-1].m_primitives.m_size = &hkpBvCompressedMeshShape::`vftable{for `hkpShapeContainer};
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::~hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>(v2);
  v3 = v1->m_userStringPalette.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &v1->m_userStringPalette.m_data[v3];
    do
    {
      hkStringPtr::~hkStringPtr(v4);
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  v5 = v1->m_userStringPalette.m_capacityAndFlags;
  v1->m_userStringPalette.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_userStringPalette.m_data,
      8 * v5);
  v1->m_userStringPalette.m_data = 0i64;
  v1->m_userStringPalette.m_capacityAndFlags = 2147483648;
  v6 = v1->m_userDataPalette.m_capacityAndFlags;
  v1->m_userDataPalette.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_userDataPalette.m_data,
      4 * v6);
  v1->m_userDataPalette.m_data = 0i64;
  v1->m_userDataPalette.m_capacityAndFlags = 2147483648;
  v7 = v1->m_collisionFilterInfoPalette.m_capacityAndFlags;
  v1->m_collisionFilterInfoPalette.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_collisionFilterInfoPalette.m_data,
      4 * v7);
  v1->m_collisionFilterInfoPalette.m_data = 0i64;
  v1->m_collisionFilterInfoPalette.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 347
// RVA: 0xDE99E0
void __fastcall createPalette_hkStringPtr_hkStringMap_unsigned_int_hkContainerHeapAllocator___(hkArray<hkStringPtr,hkContainerHeapAllocator> *values, int indexSize, hkArray<hkStringPtr,hkContainerHeapAllocator> *palette, hkArray<unsigned int,hkContainerHeapAllocator> *indices)
{
  hkArray<hkStringPtr,hkContainerHeapAllocator> *v4; // r12
  char v5; // di
  hkArray<unsigned int,hkContainerHeapAllocator> *v6; // r13
  hkArray<hkStringPtr,hkContainerHeapAllocator> *v7; // rbx
  int v8; // eax
  signed int v9; // er15
  unsigned int v10; // esi
  int v11; // eax
  int v12; // er9
  __int64 v13; // r14
  int v14; // eax
  int v15; // eax
  int v16; // er9
  int v17; // ebp
  __int64 v18; // rdi
  Dummy *v19; // rax
  int v20; // er14
  hkStringPtr *v21; // r12
  hkStringPtr *v22; // rcx
  int v23; // edx
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> v24; // [rsp+30h] [rbp-58h]
  hkArray<hkStringPtr,hkContainerHeapAllocator> *v25; // [rsp+90h] [rbp+8h]
  hkResult result; // [rsp+98h] [rbp+10h]
  __int64 v27; // [rsp+A0h] [rbp+18h]

  v25 = values;
  v4 = values;
  v5 = indexSize;
  v6 = indices;
  v7 = palette;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v24,
    0);
  v8 = v7->m_capacityAndFlags & 0x3FFFFFFF;
  v9 = 1 << v5;
  v10 = 0;
  if ( v8 < 1 << v5 )
  {
    v11 = 2 * v8;
    v12 = 1 << v5;
    if ( v9 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v12, 8);
  }
  v13 = v4->m_size;
  v14 = v6->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v14 < (signed int)v13 )
  {
    v15 = 2 * v14;
    v16 = v13;
    if ( (signed int)v13 < v15 )
      v16 = v15;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v16, 4);
  }
  v6->m_size = v13;
  v17 = 0;
  v18 = 0i64;
  v27 = v13;
  if ( (signed int)v13 > 0 )
  {
    do
    {
      v19 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::findOrInsertKey(
              &v24,
              (_QWORD)v4->m_data[v18].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
              v10);
      v20 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
              (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v24,
              v19);
      if ( v20 == v10 )
      {
        if ( v10 == v9 )
        {
          v20 = v9 - 1;
        }
        else
        {
          v21 = &v4->m_data[v17];
          if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 8);
          v22 = &v7->m_data[v7->m_size];
          if ( v22 )
            hkStringPtr::hkStringPtr(v22, v21);
          ++v7->m_size;
          v4 = v25;
          ++v10;
        }
      }
      ++v18;
      ++v17;
      v6->m_data[v18 - 1] = v20;
    }
    while ( v18 < v27 );
  }
  v23 = v7->m_size;
  if ( v23 < (v7->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 8, 0i64, v23);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v24);
}

// File Line: 392
// RVA: 0xDE8F00
void __fastcall createIntPalette(hkArray<unsigned int,hkContainerHeapAllocator> *values, int indexSize, hkArray<unsigned int,hkContainerHeapAllocator> *palette, hkArray<unsigned int,hkContainerHeapAllocator> *indices)
{
  createPalette_unsigned_int_hkMap__anonymous_namespace_::MapKey32_int_A0x59affef2::MapOperationsMapKey32_hkContainerHeapAllocator___(
    values,
    indexSize,
    palette,
    indices);
}

// File Line: 397
// RVA: 0xDE8F10
void __fastcall createStringPalette(hkArray<hkStringPtr,hkContainerHeapAllocator> *values, int indexSize, hkArray<hkStringPtr,hkContainerHeapAllocator> *palette, hkArray<unsigned int,hkContainerHeapAllocator> *indices)
{
  createPalette_hkStringPtr_hkStringMap_unsigned_int_hkContainerHeapAllocator___(values, indexSize, palette, indices);
}

// File Line: 427
// RVA: 0xDE8F20
void __fastcall computeWeldingInfo(hkpBvCompressedMeshShapeCinfo *cinfo, hkBool weldOpenEdges, hkArray<unsigned short,hkContainerHeapAllocator> *weldingInfo)
{
  hkArray<unsigned short,hkContainerHeapAllocator> *v3; // rbx
  hkpBvCompressedMeshShapeCinfo *v4; // rdi
  int v5; // eax
  int v6; // ecx
  __int64 v7; // r13
  int v8; // ecx
  int v9; // er9
  signed int i; // er15
  unsigned int v11; // er14
  __m128 v12; // xmm6
  __m128 v13; // xmm7
  hkcdDynamicTree::CodecRawUint *v14; // rdx
  unsigned __int64 v15; // rbx
  hkcdDynamicTree::CodecRawUint *v16; // r9
  __int64 v17; // r12
  hkVector4f v18; // xmm7
  hkVector4f v19; // xmm8
  unsigned int v20; // edx
  __m128 *v21; // r10
  __int64 v22; // rax
  signed __int64 v23; // rsi
  __m128 v24; // xmm9
  __m128 v25; // xmm10
  signed __int64 v26; // rcx
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 *v29; // rcx
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm2
  __m128 v35; // xmm6
  __m128 v36; // xmm5
  __m128 v37; // xmm5
  unsigned __int64 v38; // r11
  float v39; // eax
  signed __int64 v40; // rcx
  __m128 v41; // xmm1
  unsigned int v42; // ecx
  unsigned int v43; // er15
  __m128 v44; // xmm6
  hkLifoAllocator *v45; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<NeighborsQuery> *v46; // r9
  hkcdDynamicTree::CodecRawUint *v47; // rcx
  unsigned __int64 v48; // rdx
  int v49; // eax
  char *v50; // rsi
  signed int v51; // ebx
  hkLifoAllocator *v52; // rax
  int v53; // er8
  __int64 v54; // r12
  int v55; // eax
  hkVector4f *v56; // r13
  signed int v57; // er14
  __int64 v58; // rsi
  signed __int64 v59; // rbx
  __int64 v60; // r15
  __int64 v61; // rbx
  unsigned __int16 v62; // ax
  __int64 v63; // rsi
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> v64; // [rsp+30h] [rbp-C8h]
  int v65; // [rsp+48h] [rbp-B0h]
  unsigned int branch[2]; // [rsp+4Ch] [rbp-ACh]
  hkcdDynamicTree::CodecRawUint *v67; // [rsp+58h] [rbp-A0h]
  int numNeighbors[2]; // [rsp+60h] [rbp-98h]
  hkcdDynamicTree::DefaultTree48Storage output; // [rsp+68h] [rbp-90h]
  unsigned int v70; // [rsp+90h] [rbp-68h]
  __int64 v71; // [rsp+98h] [rbp-60h]
  unsigned int v72; // [rsp+A0h] [rbp-58h]
  unsigned int v73; // [rsp+A4h] [rbp-54h]
  unsigned int v74; // [rsp+A8h] [rbp-50h]
  unsigned int v75; // [rsp+B0h] [rbp-48h]
  unsigned int v76; // [rsp+B4h] [rbp-44h]
  unsigned int v77; // [rsp+B8h] [rbp-40h]
  hkVector4f triangle; // [rsp+C8h] [rbp-30h]
  __m128 v79; // [rsp+D8h] [rbp-20h]
  __m128 v80; // [rsp+E8h] [rbp-10h]
  unsigned int v81; // [rsp+F8h] [rbp+0h]
  __int64 *v82; // [rsp+100h] [rbp+8h]
  hkcdTreeQueriesStacks::Dynamic<64,unsigned int> stackInstance; // [rsp+108h] [rbp+10h]
  __m128 v84; // [rsp+128h] [rbp+30h]
  void *retaddr; // [rsp+1D8h] [rbp+E0h]
  hkBool v86; // [rsp+1E0h] [rbp+E8h]
  __int64 *v87; // [rsp+1E8h] [rbp+F0h]
  hkArray<unsigned short,hkContainerHeapAllocator> *result; // [rsp+1F0h] [rbp+F8h]

  result = weldingInfo;
  LOBYTE(v87) = weldOpenEdges;
  v3 = weldingInfo;
  v4 = cinfo;
  v5 = ((__int64 (*)(void))cinfo->vfptr->getNumTriangles)();
  v6 = v3->m_capacityAndFlags & 0x3FFFFFFF;
  v7 = v5;
  if ( v6 < v5 )
  {
    v8 = 2 * v6;
    v9 = v5;
    if ( v5 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v3,
      v9,
      2);
  }
  v3->m_size = v7;
  v64.m_nodes.m_size = 0;
  v64.m_nodes.m_data = 0i64;
  v64.m_nodes.m_capacityAndFlags = 2147483648;
  v64.m_firstFree = 0;
  *(_QWORD *)branch = 0i64;
  v65 = 0;
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
    &v64,
    (hkResult *)&retaddr,
    2 * v7);
  for ( i = 0; i < (signed int)v7; ++i )
  {
    v4->vfptr->getIndices(v4, i, (int *)&output.m_root);
    v4->vfptr->getVertex(v4, output.m_root, &triangle);
    v4->vfptr->getVertex(v4, *(&output.m_root + 1), (hkVector4f *)&v79);
    v4->vfptr->getVertex(v4, v70, (hkVector4f *)&v80);
    v11 = v64.m_firstFree;
    v12 = _mm_max_ps(_mm_max_ps(triangle.m_quad, v79), v80);
    v13 = _mm_min_ps(_mm_min_ps(triangle.m_quad, v79), v80);
    if ( !v64.m_firstFree )
    {
      hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
        &v64,
        (hkResult *)&retaddr,
        v64.m_firstFree + 1);
      v11 = v64.m_firstFree;
    }
    v14 = v64.m_nodes.m_data;
    v64.m_firstFree = v64.m_nodes.m_data[v11].m_aabb.m_min.m_quad.m128_u32[0];
    v15 = v11;
    v64.m_nodes.m_data[v15].m_children[0] = 0;
    v14[v15].m_children[1] = i;
    v14[v15].m_aabb.m_min.m_quad = v13;
    v14[v15].m_aabb.m_max.m_quad = v12;
    v16 = v64.m_nodes.m_data;
    v17 = branch[1];
    v18.m_quad = (__m128)v64.m_nodes.m_data[v11].m_aabb.m_min;
    v19.m_quad = (__m128)v64.m_nodes.m_data[v11].m_aabb.m_max;
    if ( branch[1] )
    {
      v20 = v64.m_firstFree;
      if ( !v64.m_firstFree )
      {
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
          &v64,
          (hkResult *)&result,
          v64.m_firstFree + 1);
        v20 = v64.m_firstFree;
        v16 = v64.m_nodes.m_data;
      }
      v21 = &v16[v17].m_aabb.m_min.m_quad;
      v64.m_firstFree = v16[v20].m_aabb.m_min.m_quad.m128_u32[0];
      v22 = v21[2].m128_u32[1];
      v23 = (signed __int64)&v16[v20];
      if ( (_DWORD)v22 )
      {
        v24 = _mm_add_ps(v19.m_quad, v18.m_quad);
        v25 = _mm_sub_ps(v19.m_quad, v18.m_quad);
        do
        {
          v26 = v21[2].m128_u32[2];
          v27 = _mm_max_ps(v21[1], v19.m_quad);
          *v21 = _mm_min_ps(*v21, v18.m_quad);
          v21[1] = v27;
          v67 = &v16[v22];
          v28 = v67->m_aabb.m_max.m_quad;
          v29 = &v16[v26].m_aabb.m_min.m_quad;
          v16 = v64.m_nodes.m_data;
          v30 = v28;
          v31 = _mm_sub_ps(v28, v67->m_aabb.m_min.m_quad);
          *(_QWORD *)numNeighbors = v29;
          v32 = _mm_add_ps(v31, v25);
          v33 = _mm_sub_ps(_mm_add_ps(v30, v67->m_aabb.m_min.m_quad), v24);
          v34 = _mm_mul_ps(v33, v33);
          v35 = _mm_add_ps(_mm_sub_ps(v29[1], *v29), v25);
          v36 = _mm_sub_ps(_mm_add_ps(v29[1], *v29), v24);
          v37 = _mm_mul_ps(v36, v36);
          v21 = (__m128 *)*(&v67
                          + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 85))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 0)))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 170)))
                                   * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 85))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 0)))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 170))))));
          v22 = v21[2].m128_u32[1];
        }
        while ( (_DWORD)v22 );
      }
      v38 = ((unsigned __int64)((unsigned __int128)((v23 - (signed __int64)v16) * (signed __int128)3074457345618258603i64) >> 64) >> 63)
          + ((signed __int64)((unsigned __int128)((v23 - (signed __int64)v16) * (signed __int128)3074457345618258603i64) >> 64) >> 3);
      v39 = v21[2].m128_f32[0];
      if ( v39 == 0.0 )
        branch[1] = ((unsigned __int64)((unsigned __int128)((v23 - (signed __int64)v16)
                                                          * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                  + ((signed __int64)((unsigned __int128)((v23 - (signed __int64)v16)
                                                        * (signed __int128)3074457345618258603i64) >> 64) >> 3);
      else
        v16->m_children[(v16[LODWORD(v39)].m_children[1] == ((unsigned __int64)((unsigned __int128)(((char *)v21 - (char *)v16)
                                                                                                  * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                          + (unsigned int)((signed __int64)((unsigned __int128)(((char *)v21 - (char *)v16) * (signed __int128)3074457345618258603i64) >> 64) >> 3))
                      + 12i64 * LODWORD(v39)] = v38;
      *(float *)(v23 + 32) = v21[2].m128_f32[0];
      v40 = (char *)v21 - (char *)v64.m_nodes.m_data;
      *(_DWORD *)(v23 + 40) = v11;
      *(_DWORD *)(v23 + 36) = ((unsigned __int64)((unsigned __int128)(v40 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                            + ((signed __int64)((unsigned __int128)(v40 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
      v21[2].m128_i32[0] = v38;
      v64.m_nodes.m_data[v11].m_parent = v38;
      v41 = _mm_max_ps(v21[1], v19.m_quad);
      *(__m128 *)v23 = _mm_min_ps(*v21, v18.m_quad);
      *(__m128 *)(v23 + 16) = v41;
    }
    else
    {
      branch[1] = v11;
      v64.m_nodes.m_data[v11].m_parent = 0;
    }
    ++v65;
  }
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::rebuildBranchSAH(
    (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)&v64,
    branch[1],
    (hkBool)1,
    32,
    16);
  if ( branch[1] )
  {
    output.m_nodes.m_size = 0;
    output.m_nodes.m_data = 0i64;
    output.m_nodes.m_capacityAndFlags = 2147483648;
    *(_QWORD *)(&output.m_firstFree + 1) = 0i64;
    output.m_firstFree = 0;
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>>(
      (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)&v64,
      &output);
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&output,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v64);
    v42 = output.m_firstFree;
    output.m_firstFree = v64.m_firstFree;
    v64.m_firstFree = v42;
    branch[1] = 1;
    output.m_nodes.m_size = 0;
    if ( output.m_nodes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        output.m_nodes.m_data,
        48 * (output.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
  }
  LODWORD(retaddr) = 1028443341;
  v43 = 0;
  LODWORD(result) = 0;
  v71 = 0i64;
  v44 = _mm_shuffle_ps((__m128)0x3D4CCCCDu, (__m128)0x3D4CCCCDu, 0);
  *(_QWORD *)&output.m_root = v7;
  if ( (signed int)v7 > 0 )
  {
    do
    {
      v4->vfptr->getIndices(v4, v43, (int *)&v75);
      v4->vfptr->getVertex(v4, v75, &triangle);
      v4->vfptr->getVertex(v4, v76, (hkVector4f *)&v79);
      v4->vfptr->getVertex(v4, v77, (hkVector4f *)&v80);
      v82 = (__int64 *)&v67;
      v67 = 0i64;
      numNeighbors[0] = 0;
      numNeighbors[1] = 2147483648;
      v81 = v43;
      stackInstance.m_stack.m_data = &v81;
      output.m_nodes.m_data = 0i64;
      v84 = _mm_add_ps(_mm_max_ps(_mm_max_ps(triangle.m_quad, v79), v80), v44);
      output.m_nodes.m_size = 0;
      output.m_nodes.m_capacityAndFlags = 2147483648;
      output.m_firstFree = 64;
      *(__m128 *)&stackInstance.m_stack.m_localMemory = _mm_sub_ps(
                                                          _mm_min_ps(_mm_min_ps(triangle.m_quad, v79), v80),
                                                          v44);
      v45 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v47 = (hkcdDynamicTree::CodecRawUint *)v45->m_cur;
      v48 = (unsigned __int64)&v47[5].m_aabb.m_max;
      if ( v45->m_slabSize < 256 || (void *)v48 > v45->m_end )
        v47 = (hkcdDynamicTree::CodecRawUint *)hkLifoAllocator::allocateFromNewSlab(v45, 256);
      else
        v45->m_cur = (void *)v48;
      output.m_nodes.m_data = v47;
      *(_QWORD *)&output.m_firstFree = v47;
      output.m_nodes.m_capacityAndFlags = -2147483584;
      hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>,hkcdTreeQueriesStacks::Dynamic<64,unsigned int>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<`anonymous namespace::NeighborsQuery>>(
        (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v64,
        (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)&output.m_nodes,
        &stackInstance,
        v46);
      v49 = output.m_nodes.m_size;
      v50 = *(char **)&output.m_firstFree;
      if ( *(hkcdDynamicTree::CodecRawUint **)&output.m_firstFree == output.m_nodes.m_data )
        v49 = 0;
      output.m_nodes.m_size = v49;
      v51 = (4 * output.m_firstFree + 127) & 0xFFFFFF80;
      v52 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v53 = (v51 + 15) & 0xFFFFFFF0;
      if ( v51 > v52->m_slabSize || &v50[v53] != v52->m_cur || v52->m_firstNonLifoEnd == v50 )
        hkLifoAllocator::slowBlockFree(v52, v50, v53);
      else
        v52->m_cur = v50;
      output.m_nodes.m_size = 0;
      if ( output.m_nodes.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          output.m_nodes.m_data,
          4 * output.m_nodes.m_capacityAndFlags);
      v54 = (unsigned int)numNeighbors[0];
      v55 = 3 * numNeighbors[0];
      if ( 3 * numNeighbors[0] )
      {
        LODWORD(retaddr) = 48 * numNeighbors[0];
        v56 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                              (int *)&retaddr);
        v55 = (signed int)retaddr / 16;
      }
      else
      {
        v56 = 0i64;
      }
      v57 = 2147483648;
      if ( v55 )
        v57 = v55;
      if ( (signed int)v54 > 0 )
      {
        v58 = 0i64;
        v59 = (signed __int64)&v56[2];
        v60 = v54;
        do
        {
          v4->vfptr->getIndices(v4, v67->m_aabb.m_min.m_quad.m128_i32[v58], (int *)&v72);
          v4->vfptr->getVertex(v4, v72, (hkVector4f *)(v59 - 32));
          v4->vfptr->getVertex(v4, v73, (hkVector4f *)(v59 - 16));
          v4->vfptr->getVertex(v4, v74, (hkVector4f *)v59);
          v59 += 48i64;
          ++v58;
          --v60;
        }
        while ( v60 );
        v43 = (unsigned int)result;
      }
      v61 = *v87;
      v62 = hkpMeshWeldingUtility::computeTriangleWeldingInfo(&triangle, v56, v54, v86, 0.050000001);
      v63 = v71;
      *(_WORD *)(v61 + 2 * v71) = v62;
      if ( v57 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v56,
          16 * v57);
      numNeighbors[0] = 0;
      if ( numNeighbors[1] >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v67,
          4 * numNeighbors[1]);
      ++v43;
      v67 = 0i64;
      numNeighbors[1] = 2147483648;
      LODWORD(result) = v43;
      v71 = v63 + 1;
    }
    while ( v63 + 1 < *(_QWORD *)&output.m_root );
  }
  v64.m_nodes.m_size = 0;
  if ( v64.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v64.m_nodes.m_data,
      48 * (v64.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
}lloc,
      v64.m_nodes.m_data,
      48 * (v64.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
}

