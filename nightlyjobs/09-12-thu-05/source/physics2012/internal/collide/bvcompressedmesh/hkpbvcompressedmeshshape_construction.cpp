// File Line: 29
// RVA: 0xDE82B0
void __fastcall hkpBvCompressedMeshShape::hkpBvCompressedMeshShape(
        hkpBvCompressedMeshShape *this,
        hkpBvCompressedMeshShapeCinfo *cInfo)
{
  char *v2; // rdi
  hkpBvCompressedMeshShape *v3; // r15
  __int64 v5; // r12
  int v6; // eax
  __int64 v7; // r14
  __int64 v8; // rbx
  int v9; // ecx
  unsigned int v10; // eax
  int m_storage; // ecx
  __int64 v12; // r13
  int v13; // ecx
  int v14; // eax
  unsigned int *v15; // r12
  int v16; // r15d
  int v17; // ebx
  __int64 v18; // rdi
  unsigned int v19; // eax
  int v20; // ebx
  unsigned int *v21; // rdi
  unsigned int v22; // eax
  int v23; // r8d
  __int64 v24; // rdi
  int v25; // ecx
  int v26; // eax
  int v27; // ebx
  __int64 v28; // rdi
  unsigned __int8 v29; // al
  _DWORD *v30; // rcx
  int v31; // ebx
  __int64 v32; // rdi
  unsigned __int8 v33; // al
  char *v34; // rcx
  int v35; // edx
  __int64 v36; // rcx
  int v37; // eax
  unsigned int *v38; // r15
  int v39; // r14d
  hkStringPtr *v40; // rdi
  int v41; // edi
  hkStringPtr *v42; // rbx
  int v43; // r12d
  int v44; // edi
  hkStringPtr *v45; // rbx
  int v46; // r8d
  __int64 v47; // rdi
  int v48; // ecx
  int v49; // eax
  int v50; // edi
  hkStringPtr *v51; // rbx
  unsigned int *v52; // rdx
  __int64 v53; // r8
  int v54; // eax
  unsigned int *v55; // r12
  int v56; // r15d
  int v57; // ebx
  __int64 v58; // rdi
  unsigned int v59; // eax
  __int64 v60; // r14
  int v61; // ebx
  unsigned int *v62; // rdi
  unsigned int v63; // eax
  int v64; // r8d
  __int64 v65; // rdi
  int v66; // ecx
  int v67; // eax
  int v68; // ebx
  __int64 i; // rdi
  unsigned __int8 v70; // al
  _DWORD *v71; // rcx
  __int64 v72; // r14
  int v73; // ebx
  __int64 v74; // rdi
  unsigned __int8 v75; // al
  char *v76; // rcx
  int v77; // edx
  __int64 v78; // rcx
  char m_bool; // bl
  char v80; // dl
  __int64 k; // rdi
  __int64 j; // rcx
  __int64 v83; // rcx
  int v84; // eax
  int v85; // r14d
  int v86; // r9d
  float m_vertexWeldingTolerance; // xmm1_4
  float m_maxVerticesError; // xmm1_4
  hkArray<unsigned int,hkContainerHeapAllocator> *m_triangleIndexToShapeKeyMap; // rcx
  hkArray<unsigned int,hkContainerHeapAllocator> *m_convexShapeIndexToShapeKeyMap; // rcx
  hkArray<unsigned int,hkContainerHeapAllocator> indices; // [rsp+30h] [rbp-D0h] BYREF
  char *v92; // [rsp+40h] [rbp-C0h] BYREF
  int v93; // [rsp+48h] [rbp-B8h]
  int v94; // [rsp+4Ch] [rbp-B4h]
  __int64 v95; // [rsp+50h] [rbp-B0h]
  hkArray<unsigned int,hkContainerHeapAllocator> values; // [rsp+58h] [rbp-A8h] BYREF
  hkcdStaticMeshTreeBase::BuildMapping mapping; // [rsp+68h] [rbp-98h] BYREF
  int v98; // [rsp+98h] [rbp-68h]
  hkpBvCompressedMeshShape_Internals::GeometryProvider baseProvider; // [rsp+A0h] [rbp-60h] BYREF
  hkcdStaticMeshTreeBase::BuildConfig baseConfig; // [rsp+C0h] [rbp-40h] BYREF
  hkArray<hkStringPtr,hkContainerHeapAllocator> *palette; // [rsp+F0h] [rbp-10h]
  hkpBvCompressedMeshShape *result; // [rsp+150h] [rbp+50h] BYREF
  unsigned int v103; // [rsp+158h] [rbp+58h] BYREF
  int v104; // [rsp+160h] [rbp+60h] BYREF

  result = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1041;
  v2 = 0i64;
  this->m_userData = 0i64;
  this->m_bvTreeType.m_storage = 3;
  this->hkpBvTreeShape::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpBvCompressedMeshShape::`vftable{for `hkpBvTreeShape};
  v3 = this;
  this->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpBvCompressedMeshShape::`vftable{for `hkpShapeContainer};
  this->m_convexRadius = cInfo->m_convexRadius;
  this->m_weldingType.m_storage = cInfo->m_weldingType;
  this->m_collisionFilterInfoPalette.m_data = 0i64;
  this->m_collisionFilterInfoPalette.m_size = 0;
  this->m_collisionFilterInfoPalette.m_capacityAndFlags = 0x80000000;
  this->m_userDataPalette.m_data = 0i64;
  this->m_userDataPalette.m_size = 0;
  this->m_userDataPalette.m_capacityAndFlags = 0x80000000;
  this->m_userStringPalette.m_data = 0i64;
  this->m_userStringPalette.m_size = 0;
  this->m_userStringPalette.m_capacityAndFlags = 0x80000000;
  palette = &this->m_userStringPalette;
  v5 = cInfo->vfptr->getNumTriangles(cInfo);
  v6 = cInfo->vfptr->getNumConvexShapes(cInfo);
  v7 = v6;
  v8 = (unsigned int)(v6 + v5);
  v98 = v6;
  v103 = v6 + v5;
  if ( v3 != (hkpBvCompressedMeshShape *)-112i64 )
    hkpBvCompressedMeshShapeTree::hkpBvCompressedMeshShapeTree((hkpBvCompressedMeshShapeTree *)v3->m_tree);
  v9 = v8;
  v92 = 0i64;
  v93 = 0;
  v94 = 0x80000000;
  if ( (_DWORD)v8 )
  {
    v104 = 4 * v8;
    v2 = (char *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v104);
    v9 = v104 / 4;
  }
  v10 = 0x80000000;
  v92 = v2;
  if ( v9 )
    v10 = v9;
  m_storage = (unsigned __int8)cInfo->m_collisionFilterInfoMode.m_storage;
  v93 = v8;
  v94 = v10;
  v12 = v5;
  v95 = v7;
  if ( m_storage )
  {
    v13 = m_storage - 1;
    if ( v13 )
    {
      if ( v13 != 1 )
      {
        v3->m_hasPerPrimitiveCollisionFilterInfo.m_bool = 0;
        goto LABEL_30;
      }
      v3->m_hasPerPrimitiveCollisionFilterInfo.m_bool = 1;
      v14 = v8;
      if ( (_DWORD)v8 )
      {
        v104 = 4 * v8;
        v15 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                &hkContainerHeapAllocator::s_alloc,
                                &v104);
        v14 = v104 / 4;
      }
      else
      {
        v15 = 0i64;
      }
      v16 = 0x80000000;
      values.m_size = v8;
      if ( v14 )
        v16 = v14;
      v17 = 0;
      v18 = 0i64;
      values.m_capacityAndFlags = v16;
      for ( values.m_data = v15; v18 < v12; v15[v18 - 1] = v19 )
      {
        v19 = cInfo->vfptr->getTriangleCollisionFilterInfo(cInfo, v17);
        ++v18;
        ++v17;
      }
      v20 = 0;
      if ( v7 > 0 )
      {
        v21 = &v15[v12];
        do
        {
          v22 = cInfo->vfptr->getConvexShapeCollisionFilterInfo(cInfo, v20++);
          *v21++ = v22;
          --v7;
        }
        while ( v7 );
      }
      indices.m_data = 0i64;
      indices.m_size = 0;
      indices.m_capacityAndFlags = 0x80000000;
      createIntPalette(&values, 8, &result->m_collisionFilterInfoPalette, &indices);
      v23 = 0;
      if ( v93 > 0 )
      {
        v24 = 0i64;
        do
        {
          ++v23;
          v25 = LOBYTE(indices.m_data[v24]);
          v26 = *(_DWORD *)&v92[v24 * 4];
          *(_DWORD *)&v92[++v24 * 4 - 4] = v26 & 0xFFFFFF00 | v25;
        }
        while ( v23 < v93 );
      }
      indices.m_size = 0;
      if ( indices.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          indices.m_data,
          4 * indices.m_capacityAndFlags);
      if ( v16 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v15, 4 * v16);
      v3 = result;
      LODWORD(v5) = v12;
    }
    else
    {
      v27 = 0;
      v28 = 0i64;
      v3->m_hasPerPrimitiveCollisionFilterInfo.m_bool = 1;
      if ( (int)v5 > 0 )
      {
        do
        {
          v29 = cInfo->vfptr->getTriangleCollisionFilterInfo(cInfo, v27);
          v30 = v92;
          ++v28;
          *(_DWORD *)&v92[4 * v28 - 4] &= 0xFFFFFF00;
          ++v27;
          v30[v28 - 1] |= v29;
        }
        while ( v28 < v5 );
      }
      v31 = 0;
      if ( v7 > 0 )
      {
        v32 = 4 * v5;
        do
        {
          v33 = cInfo->vfptr->getConvexShapeCollisionFilterInfo(cInfo, v31);
          v34 = v92;
          ++v31;
          *(_DWORD *)&v92[v32] &= 0xFFFFFF00;
          v32 += 4i64;
          *(_DWORD *)&v34[v32 - 4] |= v33;
          --v7;
        }
        while ( v7 );
      }
    }
    v8 = v103;
  }
  else
  {
    v35 = 0;
    v3->m_hasPerPrimitiveCollisionFilterInfo.m_bool = 0;
    if ( (int)v8 > 0 )
    {
      v36 = 0i64;
      do
      {
        ++v35;
        v36 += 4i64;
        v92[v36 - 4] = 0;
      }
      while ( v35 < v93 );
    }
  }
LABEL_30:
  if ( !cInfo->m_userDataMode.m_storage )
  {
    v3->m_hasPerPrimitiveUserData.m_bool = 0;
    v77 = 0;
    if ( v93 > 0 )
    {
      v78 = 0i64;
      do
      {
        ++v77;
        v78 += 4i64;
        v92[v78 - 3] = 0;
      }
      while ( v77 < v93 );
    }
    goto LABEL_99;
  }
  if ( cInfo->m_userDataMode.m_storage != 1 )
  {
    if ( cInfo->m_userDataMode.m_storage == 2 )
    {
      v3->m_hasPerPrimitiveUserData.m_bool = 1;
      v54 = v8;
      if ( (_DWORD)v8 )
      {
        v103 = 4 * v8;
        v55 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                &hkContainerHeapAllocator::s_alloc,
                                &v103);
        v54 = (int)v103 / 4;
      }
      else
      {
        v55 = 0i64;
      }
      v56 = 0x80000000;
      values.m_size = v8;
      if ( v54 )
        v56 = v54;
      v57 = 0;
      v58 = 0i64;
      values.m_capacityAndFlags = v56;
      for ( values.m_data = v55; v58 < v12; v55[v58 - 1] = v59 )
      {
        v59 = cInfo->vfptr->getTriangleUserData(cInfo, v57);
        ++v58;
        ++v57;
      }
      v60 = v95;
      v61 = 0;
      if ( v95 > 0 )
      {
        v62 = &v55[v12];
        do
        {
          v63 = cInfo->vfptr->getConvexShapeUserData(cInfo, v61++);
          *v62++ = v63;
          --v60;
        }
        while ( v60 );
      }
      indices.m_data = 0i64;
      indices.m_size = 0;
      indices.m_capacityAndFlags = 0x80000000;
      createIntPalette(&values, 8, &result->m_userDataPalette, &indices);
      v64 = 0;
      if ( v93 > 0 )
      {
        v65 = 0i64;
        do
        {
          ++v64;
          v66 = LOBYTE(indices.m_data[v65]);
          v67 = *(_DWORD *)&v92[v65 * 4];
          *(_DWORD *)&v92[++v65 * 4 - 4] = v67 & 0xFFFF00FF | (v66 << 8);
        }
        while ( v64 < v93 );
      }
      indices.m_size = 0;
      if ( indices.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          indices.m_data,
          4 * indices.m_capacityAndFlags);
      if ( v56 < 0 )
        goto LABEL_72;
      v52 = v55;
      v53 = (unsigned int)(4 * v56);
    }
    else
    {
      if ( cInfo->m_userDataMode.m_storage != 3 )
      {
        v3->m_hasPerPrimitiveUserData.m_bool = 0;
LABEL_99:
        v72 = v95;
        goto LABEL_100;
      }
      v3->m_hasPerPrimitiveUserData.m_bool = 1;
      v37 = v8;
      if ( (_DWORD)v8 )
      {
        v104 = 8 * v8;
        v38 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                &hkContainerHeapAllocator::s_alloc,
                                &v104);
        v37 = v104 / 8;
      }
      else
      {
        v38 = 0i64;
      }
      v39 = 0x80000000;
      values.m_data = v38;
      if ( v37 )
        v39 = v37;
      values.m_size = v8;
      values.m_capacityAndFlags = v39;
      if ( (int)v8 > 0 )
      {
        v40 = (hkStringPtr *)v38;
        do
        {
          if ( v40 )
            hkStringPtr::hkStringPtr(v40);
          ++v40;
          --v8;
        }
        while ( v8 );
      }
      v41 = 0;
      if ( (int)v5 > 0 )
      {
        v42 = (hkStringPtr *)v38;
        do
          cInfo->vfptr->getTriangleUserString(cInfo, v41++, v42++);
        while ( v41 < (int)v5 );
      }
      v43 = v98;
      v44 = 0;
      if ( v98 > 0 )
      {
        v45 = (hkStringPtr *)&v38[2 * v12];
        do
          cInfo->vfptr->getConvexShapeUserString(cInfo, v44++, v45++);
        while ( v44 < v43 );
      }
      indices.m_data = 0i64;
      indices.m_size = 0;
      indices.m_capacityAndFlags = 0x80000000;
      createStringPalette((hkArray<hkStringPtr,hkContainerHeapAllocator> *)&values, 8, palette, &indices);
      v46 = 0;
      if ( v93 > 0 )
      {
        v47 = 0i64;
        do
        {
          ++v46;
          v48 = LOBYTE(indices.m_data[v47]);
          v49 = *(_DWORD *)&v92[v47 * 4];
          *(_DWORD *)&v92[++v47 * 4 - 4] = v49 & 0xFFFF00FF | (v48 << 8);
        }
        while ( v46 < v93 );
      }
      indices.m_size = 0;
      if ( indices.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          indices.m_data,
          4 * indices.m_capacityAndFlags);
      v50 = v103 - 1;
      if ( (int)(v103 - 1) >= 0 )
      {
        v51 = (hkStringPtr *)&v38[2 * v50];
        do
        {
          hkStringPtr::~hkStringPtr(v51--);
          --v50;
        }
        while ( v50 >= 0 );
      }
      if ( v39 < 0 )
      {
LABEL_72:
        v3 = result;
        goto LABEL_99;
      }
      v52 = v38;
      v53 = (unsigned int)(8 * v39);
    }
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v52, v53);
    goto LABEL_72;
  }
  v3->m_hasPerPrimitiveUserData.m_bool = 1;
  v68 = 0;
  for ( i = 0i64; i < v12; v71[i - 1] |= v70 << 8 )
  {
    v70 = cInfo->vfptr->getTriangleUserData(cInfo, v68);
    v71 = v92;
    ++i;
    *(_DWORD *)&v92[4 * i - 4] &= 0xFFFF00FF;
    ++v68;
  }
  v72 = v95;
  v73 = 0;
  if ( v95 > 0 )
  {
    v74 = 4 * v12;
    do
    {
      v75 = cInfo->vfptr->getConvexShapeUserData(cInfo, v73);
      v76 = v92;
      ++v73;
      *(_DWORD *)&v92[v74] &= 0xFFFF00FF;
      v74 += 4i64;
      *(_DWORD *)&v76[v74 - 4] |= v75 << 8;
      --v72;
    }
    while ( v72 );
    goto LABEL_99;
  }
LABEL_100:
  m_bool = cInfo->m_preserveVertexOrder.m_bool;
  if ( cInfo->m_weldingType == WELDING_TYPE_NONE )
  {
    for ( j = 0i64; j < v12; *(_WORD *)&v92[4 * j - 2] = 0 )
      ++j;
  }
  else
  {
    v80 = cInfo->m_weldOpenEdges.m_bool;
    m_bool = 1;
    indices.m_data = 0i64;
    indices.m_size = 0;
    indices.m_capacityAndFlags = 0x80000000;
    computeWeldingInfo(cInfo, (hkBool)v80, (hkArray<unsigned short,hkContainerHeapAllocator> *)&indices);
    for ( k = 0i64;
          k < v12;
          *(_DWORD *)&v92[4 * k - 4] = *(unsigned __int16 *)&v92[4 * k - 4] | (*((unsigned __int16 *)indices.m_data
                                                                               + k
                                                                               - 1) << 16) )
    {
      ++k;
    }
    indices.m_size = 0;
    if ( indices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        indices.m_data,
        2 * (indices.m_capacityAndFlags & 0x3FFFFFFF));
  }
  if ( v72 > 0 )
  {
    v83 = 4 * v12;
    do
    {
      v83 += 4i64;
      *(_WORD *)&v92[v83 - 2] = 0;
      --v72;
    }
    while ( v72 );
  }
  baseProvider.m_meshCInfo = cInfo;
  baseProvider.m_caches.m_data = 0i64;
  baseProvider.m_caches.m_size = 0;
  baseProvider.m_caches.m_capacityAndFlags = 0x80000000;
  baseProvider.m_primitiveData = (hkArray<hkpBvCompressedMeshShape_Internals::PrimitiveData,hkContainerHeapAllocator> *)&v92;
  v84 = cInfo->vfptr->getNumConvexShapes(cInfo);
  v85 = v84;
  if ( (baseProvider.m_caches.m_capacityAndFlags & 0x3FFFFFFF) < v84 )
  {
    v86 = v84;
    if ( v84 < 2 * (baseProvider.m_caches.m_capacityAndFlags & 0x3FFFFFFF) )
      v86 = 2 * (baseProvider.m_caches.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&baseProvider.m_caches.m_data,
      v86,
      8);
  }
  if ( v85 - baseProvider.m_caches.m_size > 0 )
    memset(&baseProvider.m_caches.m_data[baseProvider.m_caches.m_size], 0, 8i64 * (v85 - baseProvider.m_caches.m_size));
  m_vertexWeldingTolerance = cInfo->m_vertexWeldingTolerance;
  baseConfig.m_convexRadius = cInfo->m_convexRadius;
  baseConfig.m_weldTolerance = m_vertexWeldingTolerance;
  baseProvider.m_caches.m_size = v85;
  *(_WORD *)&baseConfig.m_globalOptimizations.m_bool = 256;
  baseConfig.m_forceConvexQuads.m_bool = 0;
  m_maxVerticesError = cInfo->m_maxVerticesError;
  baseConfig.m_degenerateTolerance = hkDefaultTriangleDegeneracyTolerance;
  baseConfig.m_vertexHasFlags.m_bool = 0;
  *(_QWORD *)&baseConfig.m_balanceThreshold = 0i64;
  *(_QWORD *)&baseConfig.m_pbd = 1i64;
  baseConfig.m_maxCompressionError = m_maxVerticesError;
  baseConfig.m_weldVertices.m_bool = 1;
  baseConfig.m_preserveVertexOrder.m_bool = m_bool;
  mapping.m_triangleIndexToKey.m_data = 0i64;
  mapping.m_triangleIndexToKey.m_size = 0;
  mapping.m_triangleIndexToKey.m_capacityAndFlags = 0x80000000;
  mapping.m_customIndexToKey.m_data = 0i64;
  mapping.m_customIndexToKey.m_size = 0;
  mapping.m_customIndexToKey.m_capacityAndFlags = 0x80000000;
  mapping.m_triangleVertexRotations.m_data = 0i64;
  mapping.m_triangleVertexRotations.m_size = 0;
  mapping.m_triangleVertexRotations.m_capacityAndFlags = 0x80000000;
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::build<hkpBvCompressedMeshShape_Internals::GeometryProvider>(
    (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)v3->m_tree,
    &baseConfig,
    &baseProvider,
    &mapping);
  m_triangleIndexToShapeKeyMap = cInfo->m_triangleIndexToShapeKeyMap;
  if ( m_triangleIndexToShapeKeyMap )
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)m_triangleIndexToShapeKeyMap,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&mapping);
  m_convexShapeIndexToShapeKeyMap = cInfo->m_convexShapeIndexToShapeKeyMap;
  if ( m_convexShapeIndexToShapeKeyMap )
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)m_convexShapeIndexToShapeKeyMap,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&mapping.m_customIndexToKey);
  mapping.m_triangleVertexRotations.m_size = 0;
  if ( mapping.m_triangleVertexRotations.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      mapping.m_triangleVertexRotations.m_data,
      mapping.m_triangleVertexRotations.m_capacityAndFlags & 0x3FFFFFFF);
  mapping.m_triangleVertexRotations.m_data = 0i64;
  mapping.m_triangleVertexRotations.m_capacityAndFlags = 0x80000000;
  mapping.m_customIndexToKey.m_size = 0;
  if ( mapping.m_customIndexToKey.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      mapping.m_customIndexToKey.m_data,
      4 * mapping.m_customIndexToKey.m_capacityAndFlags);
  mapping.m_customIndexToKey.m_data = 0i64;
  mapping.m_customIndexToKey.m_capacityAndFlags = 0x80000000;
  mapping.m_triangleIndexToKey.m_size = 0;
  if ( mapping.m_triangleIndexToKey.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      mapping.m_triangleIndexToKey.m_data,
      4 * mapping.m_triangleIndexToKey.m_capacityAndFlags);
  mapping.m_triangleIndexToKey.m_data = 0i64;
  mapping.m_triangleIndexToKey.m_capacityAndFlags = 0x80000000;
  hkpBvCompressedMeshShape_Internals::GeometryProvider::~GeometryProvider(&baseProvider);
  v93 = 0;
  if ( v94 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v92, 4 * v94);
}r->bufFree(&hkContainerHeapAllocator::s_alloc, v92, 4 * v94);
}

// File Line: 294
// RVA: 0xDE8D40
void __fastcall hkpBvCompressedMeshShape::hkpBvCompressedMeshShape(
        hkpBvCompressedMeshShape *this,
        hkFinishLoadedObjectFlag flag)
{
  hkpBvTreeShape::hkpBvTreeShape(this, flag);
  this->hkpBvTreeShape::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpBvCompressedMeshShape::`vftable{for `hkpBvTreeShape};
  this->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpBvCompressedMeshShape::`vftable{for `hkpShapeContainer};
  if ( flag.m_finishing )
  {
    this->m_type.m_storage = 17;
    this->m_bvTreeType.m_storage = 3;
  }
}

// File Line: 303
// RVA: 0xDE8D90
void __fastcall hkpBvCompressedMeshShape::~hkpBvCompressedMeshShape(hkpBvCompressedMeshShape *this)
{
  char *m_tree; // rcx
  int v3; // ebx
  hkStringPtr *v4; // rsi
  int m_capacityAndFlags; // r8d
  int v6; // r8d
  int v7; // r8d

  m_tree = this->m_tree;
  *((_QWORD *)m_tree - 14) = &hkpBvCompressedMeshShape::`vftable{for `hkpBvTreeShape};
  *((_QWORD *)m_tree - 9) = &hkpBvCompressedMeshShape::`vftable{for `hkpShapeContainer};
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::~hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>((hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)m_tree);
  v3 = this->m_userStringPalette.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &this->m_userStringPalette.m_data[v3];
    do
    {
      hkStringPtr::~hkStringPtr(v4--);
      --v3;
    }
    while ( v3 >= 0 );
  }
  m_capacityAndFlags = this->m_userStringPalette.m_capacityAndFlags;
  this->m_userStringPalette.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_userStringPalette.m_data,
      8 * m_capacityAndFlags);
  this->m_userStringPalette.m_data = 0i64;
  this->m_userStringPalette.m_capacityAndFlags = 0x80000000;
  v6 = this->m_userDataPalette.m_capacityAndFlags;
  this->m_userDataPalette.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_userDataPalette.m_data,
      4 * v6);
  this->m_userDataPalette.m_data = 0i64;
  this->m_userDataPalette.m_capacityAndFlags = 0x80000000;
  v7 = this->m_collisionFilterInfoPalette.m_capacityAndFlags;
  this->m_collisionFilterInfoPalette.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_collisionFilterInfoPalette.m_data,
      4 * v7);
  this->m_collisionFilterInfoPalette.m_data = 0i64;
  this->m_collisionFilterInfoPalette.m_capacityAndFlags = 0x80000000;
  this->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  this->hkpBvTreeShape::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 347
// RVA: 0xDE99E0
void __fastcall createPalette_hkStringPtr_hkStringMap_unsigned_int_hkContainerHeapAllocator___(
        hkArray<hkStringPtr,hkContainerHeapAllocator> *values,
        char indexSize,
        hkArray<hkStringPtr,hkContainerHeapAllocator> *palette,
        hkArray<unsigned int,hkContainerHeapAllocator> *indices)
{
  hkArray<hkStringPtr,hkContainerHeapAllocator> *v4; // r12
  int v8; // eax
  int v9; // r15d
  unsigned int v10; // esi
  int v11; // eax
  int v12; // r9d
  __int64 m_size; // r14
  int v14; // eax
  int v15; // eax
  int v16; // r9d
  int v17; // ebp
  __int64 v18; // rdi
  Dummy *inserted; // rax
  unsigned int Value; // r14d
  hkStringPtr *v21; // r12
  hkStringPtr *v22; // rcx
  int v23; // edx
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> v24; // [rsp+30h] [rbp-58h] BYREF
  hkResult result; // [rsp+98h] [rbp+10h] BYREF
  __int64 v27; // [rsp+A0h] [rbp+18h]

  v4 = values;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v24,
    0);
  v8 = palette->m_capacityAndFlags & 0x3FFFFFFF;
  v9 = 1 << indexSize;
  v10 = 0;
  if ( v8 < 1 << indexSize )
  {
    v11 = 2 * v8;
    v12 = 1 << indexSize;
    if ( v9 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&palette->m_data, v12, 8);
  }
  m_size = v4->m_size;
  v14 = indices->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v14 < (int)m_size )
  {
    v15 = 2 * v14;
    v16 = v4->m_size;
    if ( (int)m_size < v15 )
      v16 = v15;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&indices->m_data, v16, 4);
  }
  indices->m_size = m_size;
  v17 = 0;
  v18 = 0i64;
  v27 = m_size;
  if ( (int)m_size > 0 )
  {
    do
    {
      inserted = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::findOrInsertKey(
                   &v24,
                   (const char *)((unsigned __int64)v4->m_data[v18].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                   v10);
      Value = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v24,
                inserted);
      if ( Value == v10 )
      {
        if ( v10 == v9 )
        {
          Value = v9 - 1;
        }
        else
        {
          v21 = &v4->m_data[v17];
          if ( palette->m_size == (palette->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&palette->m_data, 8);
          v22 = &palette->m_data[palette->m_size];
          if ( v22 )
            hkStringPtr::hkStringPtr(v22, v21);
          ++palette->m_size;
          v4 = values;
          ++v10;
        }
      }
      ++v18;
      ++v17;
      indices->m_data[v18 - 1] = Value;
    }
    while ( v18 < v27 );
  }
  v23 = palette->m_size;
  if ( v23 < (palette->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)&palette->m_data, 8, 0i64, v23);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v24);
}

// File Line: 392
// RVA: 0xDE8F00
// attributes: thunk
void __fastcall createIntPalette(
        hkArray<unsigned int,hkContainerHeapAllocator> *values,
        int indexSize,
        hkArray<unsigned int,hkContainerHeapAllocator> *palette,
        hkArray<unsigned int,hkContainerHeapAllocator> *indices)
{
  createPalette_unsigned_int_hkMap__anonymous_namespace_::MapKey32_int_A0x59affef2::MapOperationsMapKey32_hkContainerHeapAllocator___(
    values,
    indexSize,
    palette,
    indices);
}

// File Line: 397
// RVA: 0xDE8F10
// attributes: thunk
void __fastcall createStringPalette(
        hkArray<hkStringPtr,hkContainerHeapAllocator> *values,
        int indexSize,
        hkArray<hkStringPtr,hkContainerHeapAllocator> *palette,
        hkArray<unsigned int,hkContainerHeapAllocator> *indices)
{
  createPalette_hkStringPtr_hkStringMap_unsigned_int_hkContainerHeapAllocator___(values, indexSize, palette, indices);
}

// File Line: 427
// RVA: 0xDE8F20
void __fastcall computeWeldingInfo(
        hkpBvCompressedMeshShapeCinfo *cinfo,
        hkBool weldOpenEdges,
        hkArray<unsigned short,hkContainerHeapAllocator> *weldingInfo)
{
  int v5; // eax
  int v6; // ecx
  __int64 v7; // r13
  int v8; // ecx
  int v9; // r9d
  int i; // r15d
  unsigned int m_firstFree; // r14d
  __m128 v12; // xmm6
  __m128 v13; // xmm7
  hkcdDynamicTree::CodecRawUint *m_data; // rdx
  unsigned __int64 v15; // rbx
  hkcdDynamicTree::CodecRawUint *v16; // r9
  __int64 m_root; // r12
  hkVector4f v18; // xmm7
  hkVector4f v19; // xmm8
  unsigned int v20; // edx
  __m128 *p_m_quad; // r10
  __int64 v22; // rax
  hkcdDynamicTree::CodecRawUint *v23; // rsi
  __m128 v24; // xmm9
  __m128 v25; // xmm10
  __int64 v26; // rcx
  __m128 v27; // xmm1
  __m128 *v28; // rcx
  __m128 m_quad; // xmm2
  __m128 v30; // xmm3
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm2
  __m128 v34; // xmm6
  __m128 v35; // xmm5
  __m128 v36; // xmm5
  __int64 v37; // r11
  int v38; // eax
  signed __int64 v39; // rcx
  __m128 v40; // xmm1
  unsigned int v41; // ecx
  int v42; // r15d
  __m128 v43; // xmm6
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<NeighborsQuery> *v45; // r9
  hkcdDynamicTree::CodecRawUint *m_cur; // rcx
  hkVector4f *p_m_max; // rdx
  int m_size; // eax
  char *v49; // rsi
  signed int v50; // ebx
  hkLifoAllocator *v51; // rax
  int v52; // r8d
  __int64 v53; // r12
  int v54; // eax
  hkVector4f *v55; // r13
  int v56; // r14d
  __int64 v57; // rsi
  hkVector4f *v58; // rbx
  __int64 v59; // r15
  __int64 v60; // rbx
  unsigned __int16 v61; // ax
  __int64 v62; // rsi
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> v63; // [rsp+30h] [rbp-C8h] BYREF
  hkcdDynamicTree::CodecRawUint *v64; // [rsp+58h] [rbp-A0h] BYREF
  int numNeighbors[2]; // [rsp+60h] [rbp-98h]
  hkcdDynamicTree::DefaultTree48Storage output; // [rsp+68h] [rbp-90h] BYREF
  int v67; // [rsp+90h] [rbp-68h]
  __int64 v68; // [rsp+98h] [rbp-60h]
  int v69[4]; // [rsp+A0h] [rbp-58h] BYREF
  int v70[6]; // [rsp+B0h] [rbp-48h] BYREF
  hkVector4f triangle; // [rsp+C8h] [rbp-30h] BYREF
  __m128 v72; // [rsp+D8h] [rbp-20h] BYREF
  __m128 v73; // [rsp+E8h] [rbp-10h] BYREF
  int v74; // [rsp+F8h] [rbp+0h] BYREF
  __int64 *v75; // [rsp+100h] [rbp+8h]
  hkcdTreeQueriesStacks::Dynamic<64,unsigned int> stackInstance; // [rsp+108h] [rbp+10h] BYREF
  __m128 v77; // [rsp+128h] [rbp+30h]
  void *retaddr; // [rsp+1D8h] [rbp+E0h] BYREF
  hkBool v79; // [rsp+1E0h] [rbp+E8h]
  __int64 *v80; // [rsp+1E8h] [rbp+F0h]
  hkArray<unsigned short,hkContainerHeapAllocator> *result; // [rsp+1F0h] [rbp+F8h] BYREF

  result = weldingInfo;
  LOBYTE(v80) = weldOpenEdges;
  v5 = cinfo->vfptr->getNumTriangles(cinfo);
  v6 = weldingInfo->m_capacityAndFlags & 0x3FFFFFFF;
  v7 = v5;
  if ( v6 < v5 )
  {
    v8 = 2 * v6;
    v9 = v5;
    if ( v5 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&weldingInfo->m_data,
      v9,
      2);
  }
  weldingInfo->m_size = v7;
  v63.m_nodes.m_size = 0;
  v63.m_nodes.m_data = 0i64;
  v63.m_nodes.m_capacityAndFlags = 0x80000000;
  v63.m_firstFree = 0;
  *(_QWORD *)&v63.m_path = 0i64;
  v63.m_numLeaves = 0;
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
    &v63,
    (hkResult *)&retaddr,
    2 * v7);
  for ( i = 0; i < (int)v7; ++i )
  {
    cinfo->vfptr->getIndices(cinfo, i, (int *)&output.m_root);
    cinfo->vfptr->getVertex(cinfo, output.m_root, &triangle);
    cinfo->vfptr->getVertex(cinfo, *(&output.m_root + 1), (hkVector4f *)&v72);
    cinfo->vfptr->getVertex(cinfo, v67, (hkVector4f *)&v73);
    m_firstFree = v63.m_firstFree;
    v12 = _mm_max_ps(_mm_max_ps(triangle.m_quad, v72), v73);
    v13 = _mm_min_ps(_mm_min_ps(triangle.m_quad, v72), v73);
    if ( !v63.m_firstFree )
    {
      hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
        &v63,
        (hkResult *)&retaddr,
        1);
      m_firstFree = v63.m_firstFree;
    }
    m_data = v63.m_nodes.m_data;
    v63.m_firstFree = v63.m_nodes.m_data[m_firstFree].m_aabb.m_min.m_quad.m128_u32[0];
    v15 = m_firstFree;
    v63.m_nodes.m_data[v15].m_children[0] = 0;
    m_data[v15].m_children[1] = i;
    m_data[v15].m_aabb.m_min.m_quad = v13;
    m_data[v15].m_aabb.m_max.m_quad = v12;
    v16 = v63.m_nodes.m_data;
    m_root = v63.m_root;
    v18.m_quad = (__m128)v63.m_nodes.m_data[m_firstFree].m_aabb.m_min;
    v19.m_quad = (__m128)v63.m_nodes.m_data[m_firstFree].m_aabb.m_max;
    if ( v63.m_root )
    {
      v20 = v63.m_firstFree;
      if ( !v63.m_firstFree )
      {
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
          &v63,
          (hkResult *)&result,
          1);
        v20 = v63.m_firstFree;
        v16 = v63.m_nodes.m_data;
      }
      p_m_quad = &v16[m_root].m_aabb.m_min.m_quad;
      v63.m_firstFree = v16[v20].m_aabb.m_min.m_quad.m128_u32[0];
      v22 = p_m_quad[2].m128_u32[1];
      v23 = &v16[v20];
      if ( (_DWORD)v22 )
      {
        v24 = _mm_add_ps(v19.m_quad, v18.m_quad);
        v25 = _mm_sub_ps(v19.m_quad, v18.m_quad);
        do
        {
          v26 = p_m_quad[2].m128_u32[2];
          v27 = _mm_max_ps(p_m_quad[1], v19.m_quad);
          *p_m_quad = _mm_min_ps(*p_m_quad, v18.m_quad);
          p_m_quad[1] = v27;
          v64 = &v16[v22];
          v28 = &v16[v26].m_aabb.m_min.m_quad;
          v16 = v63.m_nodes.m_data;
          m_quad = v64->m_aabb.m_max.m_quad;
          v30 = _mm_sub_ps(m_quad, v64->m_aabb.m_min.m_quad);
          *(_QWORD *)numNeighbors = v28;
          v31 = _mm_add_ps(v30, v25);
          v32 = _mm_sub_ps(_mm_add_ps(m_quad, v64->m_aabb.m_min.m_quad), v24);
          v33 = _mm_mul_ps(v32, v32);
          v34 = _mm_add_ps(_mm_sub_ps(v28[1], *v28), v25);
          v35 = _mm_sub_ps(_mm_add_ps(v28[1], *v28), v24);
          v36 = _mm_mul_ps(v35, v35);
          p_m_quad = *(__m128 **)&numNeighbors[2
                                             * ((float)((float)((float)(_mm_shuffle_ps(v33, v33, 85).m128_f32[0]
                                                                      + _mm_shuffle_ps(v33, v33, 0).m128_f32[0])
                                                              + _mm_shuffle_ps(v33, v33, 170).m128_f32[0])
                                                      * (float)((float)(_mm_shuffle_ps(v31, v31, 85).m128_f32[0]
                                                                      + _mm_shuffle_ps(v31, v31, 0).m128_f32[0])
                                                              + _mm_shuffle_ps(v31, v31, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v36, v36, 85).m128_f32[0] + _mm_shuffle_ps(v36, v36, 0).m128_f32[0]) + _mm_shuffle_ps(v36, v36, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v34, v34, 85).m128_f32[0] + _mm_shuffle_ps(v34, v34, 0).m128_f32[0]) + _mm_shuffle_ps(v34, v34, 170).m128_f32[0])))
                                             - 2];
          v22 = p_m_quad[2].m128_u32[1];
        }
        while ( (_DWORD)v22 );
      }
      v37 = v23 - v16;
      v38 = p_m_quad[2].m128_i32[0];
      if ( v38 )
        v16[v38].m_children[v16[v38].m_children[1] == (unsigned int)(((char *)p_m_quad - (char *)v16) / 48)] = v37;
      else
        v63.m_root = v23 - v16;
      v23->m_parent = p_m_quad[2].m128_u32[0];
      v39 = (char *)p_m_quad - (char *)v63.m_nodes.m_data;
      v23->m_children[1] = m_firstFree;
      v23->m_children[0] = v39 / 48;
      p_m_quad[2].m128_i32[0] = v37;
      v63.m_nodes.m_data[m_firstFree].m_parent = v37;
      v40 = _mm_max_ps(p_m_quad[1], v19.m_quad);
      v23->m_aabb.m_min.m_quad = _mm_min_ps(*p_m_quad, v18.m_quad);
      v23->m_aabb.m_max.m_quad = v40;
    }
    else
    {
      v63.m_root = m_firstFree;
      v63.m_nodes.m_data[m_firstFree].m_parent = 0;
    }
    ++v63.m_numLeaves;
  }
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::rebuildBranchSAH(&v63, v63.m_root, (hkBool)1, 32, 16);
  if ( v63.m_root )
  {
    output.m_nodes.m_size = 0;
    output.m_nodes.m_data = 0i64;
    output.m_nodes.m_capacityAndFlags = 0x80000000;
    *(_QWORD *)(&output.m_firstFree + 1) = 0i64;
    output.m_firstFree = 0;
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>>(
      &v63,
      &output);
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&output,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v63);
    v41 = output.m_firstFree;
    output.m_firstFree = v63.m_firstFree;
    v63.m_firstFree = v41;
    v63.m_root = 1;
    output.m_nodes.m_size = 0;
    if ( output.m_nodes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        output.m_nodes.m_data,
        48 * (output.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
  }
  LODWORD(retaddr) = 1028443341;
  v42 = 0;
  LODWORD(result) = 0;
  v68 = 0i64;
  v43 = _mm_shuffle_ps((__m128)0x3D4CCCCDu, (__m128)0x3D4CCCCDu, 0);
  *(_QWORD *)&output.m_root = v7;
  if ( (int)v7 > 0 )
  {
    do
    {
      cinfo->vfptr->getIndices(cinfo, v42, v70);
      cinfo->vfptr->getVertex(cinfo, v70[0], &triangle);
      cinfo->vfptr->getVertex(cinfo, v70[1], (hkVector4f *)&v72);
      cinfo->vfptr->getVertex(cinfo, v70[2], (hkVector4f *)&v73);
      v75 = (__int64 *)&v64;
      v64 = 0i64;
      numNeighbors[0] = 0;
      numNeighbors[1] = 0x80000000;
      v74 = v42;
      stackInstance.m_stack.m_data = (unsigned int *)&v74;
      output.m_nodes.m_data = 0i64;
      v77 = _mm_add_ps(_mm_max_ps(_mm_max_ps(triangle.m_quad, v72), v73), v43);
      output.m_nodes.m_size = 0;
      output.m_nodes.m_capacityAndFlags = 0x80000000;
      output.m_firstFree = 64;
      *(__m128 *)&stackInstance.m_stack.m_localMemory = _mm_sub_ps(
                                                          _mm_min_ps(_mm_min_ps(triangle.m_quad, v72), v73),
                                                          v43);
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (hkcdDynamicTree::CodecRawUint *)Value->m_cur;
      p_m_max = &m_cur[5].m_aabb.m_max;
      if ( Value->m_slabSize < 256 || p_m_max > Value->m_end )
        m_cur = (hkcdDynamicTree::CodecRawUint *)hkLifoAllocator::allocateFromNewSlab(Value, 256);
      else
        Value->m_cur = p_m_max;
      output.m_nodes.m_data = m_cur;
      *(_QWORD *)&output.m_firstFree = m_cur;
      output.m_nodes.m_capacityAndFlags = -2147483584;
      hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>,hkcdTreeQueriesStacks::Dynamic<64,unsigned int>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<`anonymous namespace::NeighborsQuery>>(
        (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v63,
        &output,
        &stackInstance,
        v45);
      m_size = output.m_nodes.m_size;
      v49 = *(char **)&output.m_firstFree;
      if ( *(hkcdDynamicTree::CodecRawUint **)&output.m_firstFree == output.m_nodes.m_data )
        m_size = 0;
      output.m_nodes.m_size = m_size;
      v50 = (4 * output.m_firstFree + 127) & 0xFFFFFF80;
      v51 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v52 = (v50 + 15) & 0xFFFFFFF0;
      if ( v50 > v51->m_slabSize || &v49[v52] != v51->m_cur || v51->m_firstNonLifoEnd == v49 )
        hkLifoAllocator::slowBlockFree(v51, v49, v52);
      else
        v51->m_cur = v49;
      output.m_nodes.m_size = 0;
      if ( output.m_nodes.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          output.m_nodes.m_data,
          4 * output.m_nodes.m_capacityAndFlags);
      v53 = (unsigned int)numNeighbors[0];
      v54 = 3 * numNeighbors[0];
      if ( 3 * numNeighbors[0] )
      {
        LODWORD(retaddr) = 48 * numNeighbors[0];
        v55 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                              &hkContainerHeapAllocator::s_alloc,
                              &retaddr);
        v54 = (int)retaddr / 16;
      }
      else
      {
        v55 = 0i64;
      }
      v56 = 0x80000000;
      if ( v54 )
        v56 = v54;
      if ( (int)v53 > 0 )
      {
        v57 = 0i64;
        v58 = v55 + 2;
        v59 = v53;
        do
        {
          cinfo->vfptr->getIndices(cinfo, v64->m_aabb.m_min.m_quad.m128_u32[v57], v69);
          cinfo->vfptr->getVertex(cinfo, v69[0], &v58[-2]);
          cinfo->vfptr->getVertex(cinfo, v69[1], &v58[-1]);
          cinfo->vfptr->getVertex(cinfo, v69[2], v58);
          v58 += 3;
          ++v57;
          --v59;
        }
        while ( v59 );
        v42 = (int)result;
      }
      v60 = *v80;
      v61 = hkpMeshWeldingUtility::computeTriangleWeldingInfo(&triangle, v55, v53, v79, 0.050000001);
      v62 = v68;
      *(_WORD *)(v60 + 2 * v68) = v61;
      if ( v56 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v55, 16 * v56);
      numNeighbors[0] = 0;
      if ( numNeighbors[1] >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v64, 4 * numNeighbors[1]);
      ++v42;
      v64 = 0i64;
      numNeighbors[1] = 0x80000000;
      LODWORD(result) = v42;
      v68 = v62 + 1;
    }
    while ( v62 + 1 < *(__int64 *)&output.m_root );
  }
  v63.m_nodes.m_size = 0;
  if ( v63.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v63.m_nodes.m_data,
      48 * (v63.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
}

