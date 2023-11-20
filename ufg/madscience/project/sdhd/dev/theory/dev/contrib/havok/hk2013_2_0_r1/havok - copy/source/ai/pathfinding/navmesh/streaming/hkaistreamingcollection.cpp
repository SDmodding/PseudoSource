// File Line: 38
// RVA: 0xBBB2B0
void __fastcall hkaiStreamingCollection::hkaiStreamingCollection(hkaiStreamingCollection *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiStreamingCollection::`vftable;
}

// File Line: 44
// RVA: 0xBBB1E0
void __fastcall hkaiStreamingCollection::hkaiStreamingCollection(hkaiStreamingCollection *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiStreamingCollection::`vftable;
  this->m_isTemporary.m_bool = 0;
  this->m_tree.m_pntr = 0i64;
  this->m_instances.m_data = 0i64;
  this->m_instances.m_size = 0;
  this->m_instances.m_capacityAndFlags = 2147483648;
}

// File Line: 50
// RVA: 0xBBB2D0
void __fastcall hkaiStreamingCollection::init(hkaiStreamingCollection *this, hkaiNavMeshInstance *meshInstance, hkaiDirectedGraphInstance *clusterGraph, hkaiNavMeshQueryMediator *mediator)
{
  hkaiNavMeshQueryMediator *v4; // rbp
  hkaiDirectedGraphInstance *v5; // rsi
  hkaiNavMeshInstance *v6; // rdi
  hkaiStreamingCollection *v7; // r14
  int v8; // eax
  int v9; // eax
  int v10; // er9
  __int64 v11; // rax
  int v12; // ecx
  __int64 v13; // rdx
  signed __int64 v14; // rax
  char *v15; // rax
  hkAabb aabbOut; // [rsp+30h] [rbp-38h]
  hkResult result; // [rsp+70h] [rbp+8h]

  v4 = mediator;
  v5 = clusterGraph;
  v6 = meshInstance;
  v7 = this;
  hkaiStreamingCollection::clear(this);
  v8 = v7->m_instances.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < 1 )
  {
    v9 = 2 * v8;
    v10 = 1;
    if ( v9 > 1 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v7->m_instances,
      v10,
      48);
  }
  v11 = v7->m_instances.m_size;
  v12 = 1 - v11;
  v13 = 1 - (signed int)v11;
  v14 = 48 * v11 + 16;
  if ( v12 > 0 )
  {
    v15 = (char *)v7->m_instances.m_data + v14;
    do
    {
      if ( v15 != (char *)16 )
      {
        *((_QWORD *)v15 - 2) = 0i64;
        *((_QWORD *)v15 - 1) = 0i64;
        *(_QWORD *)v15 = 0i64;
        *((_QWORD *)v15 + 1) = 0i64;
        *((_QWORD *)v15 + 2) = 0i64;
        *((_DWORD *)v15 + 6) = -1;
      }
      v15 += 48;
      --v13;
    }
    while ( v13 );
  }
  v7->m_instances.m_size = 1;
  if ( v6 )
  {
    v6->m_runtimeId = 0;
    hkReferencedObject::addReference((hkReferencedObject *)&v6->vfptr);
  }
  v7->m_instances.m_data->m_instancePtr = v6;
  if ( v5 )
  {
    v5->m_runtimeId = 0;
    hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
  }
  v7->m_instances.m_data->m_clusterGraphInstance = v5;
  if ( v4 )
    hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  v7->m_instances.m_data->m_mediator = v4;
  hkaiNavMeshInstance::getAabb(v6, &aabbOut);
  hkaiStreamingCollection::addTreeNode(v7, 0, &aabbOut);
}

// File Line: 82
// RVA: 0xBBB420
void __fastcall hkaiStreamingCollection::init(hkaiStreamingCollection *this, hkaiNavVolumeInstance *vol, hkaiNavVolumeMediator *mediator)
{
  hkaiNavVolumeMediator *v3; // rsi
  hkaiNavVolumeInstance *v4; // rdi
  hkaiStreamingCollection *v5; // rbp
  int v6; // eax
  int v7; // eax
  int v8; // er9
  __int64 v9; // rax
  int v10; // ecx
  __int64 v11; // rdx
  signed __int64 v12; // rax
  char *v13; // rax
  __m128 *v14; // rax
  hkVector4f v15; // xmm2
  hkAabb instanceAabb; // [rsp+30h] [rbp-28h]
  hkResult result; // [rsp+60h] [rbp+8h]

  v3 = mediator;
  v4 = vol;
  v5 = this;
  hkaiStreamingCollection::clear(this);
  v6 = v5->m_instances.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < 1 )
  {
    v7 = 2 * v6;
    v8 = 1;
    if ( v7 > 1 )
      v8 = v7;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v5->m_instances,
      v8,
      48);
  }
  v9 = v5->m_instances.m_size;
  v10 = 1 - v9;
  v11 = 1 - (signed int)v9;
  v12 = 48 * v9 + 16;
  if ( v10 > 0 )
  {
    v13 = (char *)v5->m_instances.m_data + v12;
    do
    {
      if ( v13 != (char *)16 )
      {
        *((_QWORD *)v13 - 2) = 0i64;
        *((_QWORD *)v13 - 1) = 0i64;
        *(_QWORD *)v13 = 0i64;
        *((_QWORD *)v13 + 1) = 0i64;
        *((_QWORD *)v13 + 2) = 0i64;
        *((_DWORD *)v13 + 6) = -1;
      }
      v13 += 48;
      --v11;
    }
    while ( v11 );
  }
  v5->m_instances.m_size = 1;
  if ( v4 )
    hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  v5->m_instances.m_data->m_volumeInstancePtr = v4;
  if ( v3 )
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
  v5->m_instances.m_data->m_volumeMediator = v3;
  v14 = (__m128 *)v4->m_originalVolume.m_pntr;
  v15.m_quad = _mm_add_ps(v4->m_translation.m_quad, v14[5]);
  instanceAabb.m_min.m_quad = _mm_add_ps(v4->m_translation.m_quad, v14[4]);
  instanceAabb.m_max = (hkVector4f)v15.m_quad;
  hkaiStreamingCollection::addTreeNode(v5, 0, &instanceAabb);
}

// File Line: 107
// RVA: 0xBBB220
void __fastcall hkaiStreamingCollection::~hkaiStreamingCollection(hkaiStreamingCollection *this)
{
  hkaiStreamingCollection *v1; // rbx
  int v2; // eax
  hkReferencedObject *v3; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiStreamingCollection::`vftable;
  hkaiStreamingCollection::clear(this);
  v2 = v1->m_instances.m_capacityAndFlags;
  v1->m_instances.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_instances.m_data,
      48 * (v2 & 0x3FFFFFFF));
  v1->m_instances.m_data = 0i64;
  v1->m_instances.m_capacityAndFlags = 2147483648;
  v3 = (hkReferencedObject *)&v1->m_tree.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_tree.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 112
// RVA: 0xBBBC60
void __fastcall hkaiStreamingCollection::clear(hkaiStreamingCollection *this)
{
  hkaiStreamingCollection *v1; // rbp
  int v2; // edi
  __int64 v3; // rsi
  hkReferencedObject **v4; // rbx
  hkReferencedObject *v5; // rcx
  hkReferencedObject *v6; // rcx
  hkReferencedObject *v7; // rcx
  hkReferencedObject *v8; // rcx
  int v9; // er9
  int v10; // ecx
  __int64 v11; // rdx
  signed __int64 v12; // rax
  hkResult result; // [rsp+50h] [rbp+8h]

  v1 = this;
  if ( !this->m_isTemporary.m_bool )
  {
    v2 = 0;
    if ( this->m_instances.m_size > 0 )
    {
      v3 = 0i64;
      do
      {
        v4 = (hkReferencedObject **)&v1->m_instances.m_data[v3];
        if ( *v4 )
        {
          hkReferencedObject::removeReference(*v4);
          *v4 = 0i64;
        }
        v5 = v4[1];
        if ( v5 )
        {
          hkReferencedObject::removeReference(v5);
          v4[1] = 0i64;
        }
        v6 = v4[2];
        if ( v6 )
        {
          hkReferencedObject::removeReference(v6);
          v4[2] = 0i64;
        }
        v7 = v4[3];
        if ( v7 )
        {
          hkReferencedObject::removeReference(v7);
          v4[3] = 0i64;
        }
        v8 = v4[4];
        if ( v8 )
        {
          hkReferencedObject::removeReference(v8);
          v4[4] = 0i64;
        }
        ++v2;
        ++v3;
      }
      while ( v2 < v1->m_instances.m_size );
    }
  }
  if ( (v1->m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 0 )
  {
    v9 = 0;
    if ( 2 * (v1->m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 0 )
      v9 = 2 * (v1->m_instances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_instances,
      v9,
      48);
  }
  v10 = -v1->m_instances.m_size;
  v11 = v10;
  if ( v10 >= 0 && v1->m_instances.m_size != 0 )
  {
    v12 = (signed __int64)&v1->m_instances.m_data[v1->m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( v12 != 16 )
      {
        *(_QWORD *)(v12 - 16) = 0i64;
        *(_QWORD *)(v12 - 8) = 0i64;
        *(_QWORD *)v12 = 0i64;
        *(_QWORD *)(v12 + 8) = 0i64;
        *(_QWORD *)(v12 + 16) = 0i64;
        *(_DWORD *)(v12 + 24) = -1;
      }
      v12 += 48i64;
      --v11;
    }
    while ( v11 );
  }
  v1->m_instances.m_size = 0;
}

// File Line: 130
// RVA: 0xBBB550
void __fastcall hkaiStreamingCollection::addInstance(hkaiStreamingCollection *this, hkaiNavMeshInstance *instance, hkaiNavMeshQueryMediator *mediator, hkaiDirectedGraphInstance *clusterGraphInstance)
{
  int v4; // esi
  signed int v5; // er11
  hkaiDirectedGraphInstance *v6; // r14
  hkaiNavMeshQueryMediator *v7; // r12
  hkaiNavMeshInstance *v8; // rbp
  hkaiStreamingCollection *v9; // r15
  int v10; // ebx
  hkaiStreamingCollection::InstanceInfo *v11; // r10
  hkArray<hkaiStreamingCollection::InstanceInfo,hkContainerHeapAllocator> *v12; // rdi
  hkaiDirectedGraphInstance *v13; // rcx
  signed __int64 v14; // rcx
  hkReferencedObject *v15; // rcx
  hkReferencedObject *v16; // rcx
  hkReferencedObject *v17; // rcx
  hkAabb aabbOut; // [rsp+20h] [rbp-48h]

  v4 = this->m_instances.m_size;
  v5 = -1;
  v6 = clusterGraphInstance;
  v7 = mediator;
  v8 = instance;
  v9 = this;
  v10 = 0;
  if ( v4 <= 0 )
    goto LABEL_34;
  v11 = this->m_instances.m_data;
  v12 = &this->m_instances;
  while ( 1 )
  {
    v13 = v11->m_clusterGraphInstance;
    if ( v13 )
    {
      if ( v13->m_sectionUid == instance->m_sectionUid )
        break;
    }
    if ( v5 == -1 && !v11->m_instancePtr && !v11->m_volumeInstancePtr && !v13 )
      v5 = v10;
    ++v10;
    ++v11;
    if ( v10 >= v4 )
      goto LABEL_13;
  }
  if ( v10 != -1 )
    goto LABEL_20;
LABEL_13:
  if ( v5 == -1 )
  {
LABEL_34:
    v12 = &v9->m_instances;
    v10 = v4;
    if ( v9->m_instances.m_size == (v9->m_instances.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v9->m_instances, 48);
    v14 = (signed __int64)&v12->m_data[v9->m_instances.m_size];
    if ( v14 )
    {
      *(_QWORD *)v14 = 0i64;
      *(_QWORD *)(v14 + 8) = 0i64;
      *(_QWORD *)(v14 + 16) = 0i64;
      *(_QWORD *)(v14 + 24) = 0i64;
      *(_QWORD *)(v14 + 32) = 0i64;
      *(_DWORD *)(v14 + 40) = -1;
    }
    ++v9->m_instances.m_size;
  }
  else
  {
    v10 = v5;
  }
LABEL_20:
  v8->m_runtimeId = v10;
  hkReferencedObject::addReference((hkReferencedObject *)&v8->vfptr);
  v15 = (hkReferencedObject *)&v12->m_data[v10].m_instancePtr->vfptr;
  if ( v15 )
    hkReferencedObject::removeReference(v15);
  v12->m_data[v10].m_instancePtr = v8;
  if ( v7 )
    hkReferencedObject::addReference((hkReferencedObject *)&v7->vfptr);
  v16 = (hkReferencedObject *)&v12->m_data[v10].m_mediator->vfptr;
  if ( v16 )
    hkReferencedObject::removeReference(v16);
  v12->m_data[v10].m_mediator = v7;
  if ( v6 && !v12->m_data[v10].m_clusterGraphInstance )
  {
    v6->m_runtimeId = v10;
    hkReferencedObject::addReference((hkReferencedObject *)&v6->vfptr);
    v17 = (hkReferencedObject *)&v12->m_data[v10].m_clusterGraphInstance->vfptr;
    if ( v17 )
      hkReferencedObject::removeReference(v17);
    v12->m_data[v10].m_clusterGraphInstance = v6;
    hkaiStreamingManager::loadGraphInstance(v6, v9);
  }
  hkaiNavMeshInstance::getAabb(v8, &aabbOut);
  hkaiStreamingCollection::addTreeNode(v9, v10, &aabbOut);
}

// File Line: 206
// RVA: 0xBBB710
void __fastcall hkaiStreamingCollection::removeInstance(hkaiStreamingCollection *this, hkaiNavMeshInstance *instance, hkaiDirectedGraphInstance *clusterGraphInstance)
{
  __int64 v3; // rbp
  hkaiDirectedGraphInstance *v4; // rsi
  hkaiNavMeshInstance *v5; // r14
  hkaiStreamingCollection *v6; // rdi

  v3 = instance->m_runtimeId;
  v4 = clusterGraphInstance;
  v5 = instance;
  v6 = this;
  if ( (signed int)v3 >= 0 )
  {
    hkcdDynamicAabbTree::remove(this->m_tree.m_pntr, this->m_instances.m_data[v3].m_treeNode);
    v6->m_instances.m_data[v3].m_treeNode = -1;
    v5->m_runtimeId = -1;
    hkaiStreamingCollection::removeInstanceAt(v6, v3);
    if ( v4 )
    {
      hkaiStreamingManager::unloadGraphInstance(v4, v6);
      hkaiStreamingCollection::removeMeshGraph(v6, v4);
    }
  }
}

// File Line: 233
// RVA: 0xBBB7C0
void __fastcall hkaiStreamingCollection::removeInstanceAt(hkaiStreamingCollection *this, int idx)
{
  hkaiStreamingCollection *v2; // rdi
  signed __int64 v3; // rbx
  hkaiNavMeshInstance *v4; // rcx
  hkReferencedObject *v5; // rcx

  v2 = this;
  v3 = idx;
  v4 = this->m_instances.m_data[idx].m_instancePtr;
  if ( v4 )
  {
    hkReferencedObject::removeReference((hkReferencedObject *)&v4->vfptr);
    v2->m_instances.m_data[v3].m_instancePtr = 0i64;
  }
  v5 = (hkReferencedObject *)&v2->m_instances.m_data[v3].m_mediator->vfptr;
  if ( v5 )
  {
    hkReferencedObject::removeReference(v5);
    v2->m_instances.m_data[v3].m_mediator = 0i64;
  }
}

// File Line: 242
// RVA: 0xBBB830
void __fastcall hkaiStreamingCollection::addMeshGraph(hkaiStreamingCollection *this, hkaiDirectedGraphInstance *graphInstance)
{
  hkaiStreamingCollection *v2; // rbp
  __int64 v3; // rcx
  hkaiDirectedGraphInstance *v4; // rsi
  int v5; // edi
  __int64 v6; // r8
  hkaiStreamingCollection::InstanceInfo *v7; // rax
  hkArray<hkaiStreamingCollection::InstanceInfo,hkContainerHeapAllocator> *v8; // rbx
  signed __int64 v9; // rcx
  hkaiStreamingCollection::InstanceInfo *v10; // rax
  signed __int64 v11; // rdi
  hkReferencedObject *v12; // rcx

  v2 = this;
  v3 = this->m_instances.m_size;
  v4 = graphInstance;
  v5 = 0;
  v6 = 0i64;
  if ( (signed int)v3 <= 0 )
    goto LABEL_9;
  v7 = v2->m_instances.m_data;
  v8 = &v2->m_instances;
  while ( v7->m_instancePtr || v7->m_volumeInstancePtr || v7->m_clusterGraphInstance )
  {
    ++v6;
    ++v5;
    ++v7;
    if ( v6 >= v3 )
      goto LABEL_9;
  }
  if ( v5 == -1 )
  {
LABEL_9:
    v8 = &v2->m_instances;
    v5 = v3;
    if ( v2->m_instances.m_size == (v2->m_instances.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_instances, 48);
    v9 = (signed __int64)&v8->m_data[v2->m_instances.m_size];
    if ( v9 )
    {
      *(_QWORD *)v9 = 0i64;
      *(_QWORD *)(v9 + 8) = 0i64;
      *(_QWORD *)(v9 + 16) = 0i64;
      *(_QWORD *)(v9 + 24) = 0i64;
      *(_QWORD *)(v9 + 32) = 0i64;
      *(_DWORD *)(v9 + 40) = -1;
    }
    ++v2->m_instances.m_size;
  }
  v4->m_runtimeId = v5;
  hkaiStreamingManager::loadGraphInstance(v4, v2);
  hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  v10 = v8->m_data;
  v11 = v5;
  v12 = (hkReferencedObject *)&v8->m_data[v11].m_clusterGraphInstance->vfptr;
  if ( v12 )
  {
    hkReferencedObject::removeReference(v12);
    v10 = v8->m_data;
  }
  v10[v11].m_clusterGraphInstance = v4;
}

// File Line: 281
// RVA: 0xBBB950
void __fastcall hkaiStreamingCollection::removeMeshGraph(hkaiStreamingCollection *this, hkaiDirectedGraphInstance *clusterGraph)
{
  int v2; // edi
  hkaiDirectedGraphInstance *v3; // rbx
  hkaiStreamingCollection *v4; // rsi

  v2 = clusterGraph->m_runtimeId;
  v3 = clusterGraph;
  v4 = this;
  if ( v2 >= 0 )
  {
    hkaiStreamingManager::unloadGraphInstance(clusterGraph, this);
    v3->m_runtimeId = -1;
    hkaiStreamingCollection::removeMeshGraphAt(v4, v2);
  }
}

// File Line: 294
// RVA: 0xBBB9A0
void __fastcall hkaiStreamingCollection::removeMeshGraphAt(hkaiStreamingCollection *this, int idx)
{
  hkaiStreamingCollection *v2; // rdi
  signed __int64 v3; // rbx
  hkaiDirectedGraphInstance *v4; // rcx

  v2 = this;
  v3 = idx;
  v4 = this->m_instances.m_data[idx].m_clusterGraphInstance;
  if ( v4 )
  {
    hkReferencedObject::removeReference((hkReferencedObject *)&v4->vfptr);
    v2->m_instances.m_data[v3].m_clusterGraphInstance = 0i64;
  }
}

// File Line: 302
// RVA: 0xBBB9F0
void __fastcall hkaiStreamingCollection::addVolume(hkaiStreamingCollection *this, hkaiNavVolumeInstance *volumeInstance, hkaiNavVolumeMediator *mediator)
{
  hkaiStreamingCollection *v3; // rbp
  __int64 v4; // rcx
  hkaiNavVolumeMediator *v5; // r15
  hkaiNavVolumeInstance *v6; // r14
  int v7; // edi
  __int64 v8; // r9
  hkaiStreamingCollection::InstanceInfo *v9; // rax
  hkArray<hkaiStreamingCollection::InstanceInfo,hkContainerHeapAllocator> *v10; // rbx
  signed __int64 v11; // rcx
  hkReferencedObject *v12; // rcx
  hkReferencedObject *v13; // rcx
  __m128 *v14; // rax
  hkVector4f v15; // xmm2
  hkAabb instanceAabb; // [rsp+20h] [rbp-38h]

  v3 = this;
  v4 = this->m_instances.m_size;
  v5 = mediator;
  v6 = volumeInstance;
  v7 = 0;
  v8 = 0i64;
  if ( (signed int)v4 <= 0 )
    goto LABEL_9;
  v9 = v3->m_instances.m_data;
  v10 = &v3->m_instances;
  while ( v9->m_instancePtr || v9->m_volumeInstancePtr || v9->m_clusterGraphInstance )
  {
    ++v8;
    ++v7;
    ++v9;
    if ( v8 >= v4 )
      goto LABEL_9;
  }
  if ( v7 == -1 )
  {
LABEL_9:
    v10 = &v3->m_instances;
    v7 = v4;
    if ( v3->m_instances.m_size == (v3->m_instances.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_instances, 48);
    v11 = (signed __int64)&v10->m_data[v3->m_instances.m_size];
    if ( v11 )
    {
      *(_QWORD *)v11 = 0i64;
      *(_QWORD *)(v11 + 8) = 0i64;
      *(_QWORD *)(v11 + 16) = 0i64;
      *(_QWORD *)(v11 + 24) = 0i64;
      *(_QWORD *)(v11 + 32) = 0i64;
      *(_DWORD *)(v11 + 40) = -1;
    }
    ++v3->m_instances.m_size;
  }
  v6->m_runtimeId = v7;
  hkaiStreamingManager::loadVolumeInstance(v6, v3);
  hkReferencedObject::addReference((hkReferencedObject *)&v6->vfptr);
  v12 = (hkReferencedObject *)&v10->m_data[v7].m_volumeInstancePtr->vfptr;
  if ( v12 )
    hkReferencedObject::removeReference(v12);
  v10->m_data[v7].m_volumeInstancePtr = v6;
  if ( v5 )
    hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
  v13 = (hkReferencedObject *)&v10->m_data[v7].m_volumeMediator->vfptr;
  if ( v13 )
    hkReferencedObject::removeReference(v13);
  v10->m_data[v7].m_volumeMediator = v5;
  v14 = (__m128 *)v6->m_originalVolume.m_pntr;
  v15.m_quad = _mm_add_ps(v6->m_translation.m_quad, v14[5]);
  instanceAabb.m_min.m_quad = _mm_add_ps(v6->m_translation.m_quad, v14[4]);
  instanceAabb.m_max = (hkVector4f)v15.m_quad;
  hkaiStreamingCollection::addTreeNode(v3, v7, &instanceAabb);
}

// File Line: 347
// RVA: 0xBBBB60
void __fastcall hkaiStreamingCollection::removeVolume(hkaiStreamingCollection *this, hkaiNavVolumeInstance *volumeInstance)
{
  __int64 v2; // rsi
  hkaiNavVolumeInstance *v3; // rbp
  hkaiStreamingCollection *v4; // rbx

  v2 = volumeInstance->m_runtimeId;
  v3 = volumeInstance;
  v4 = this;
  hkcdDynamicAabbTree::remove(this->m_tree.m_pntr, this->m_instances.m_data[v2].m_treeNode);
  v4->m_instances.m_data[v2].m_treeNode = -1;
  if ( (signed int)v2 >= 0 )
  {
    hkaiStreamingManager::unloadVolumeInstance(v3, v4);
    v4->m_instances.m_data[v2].m_volumeInstancePtr->m_runtimeId = -1;
    hkaiStreamingCollection::removeVolumeAt(v4, v2);
  }
}

// File Line: 367
// RVA: 0xBBBBF0
void __fastcall hkaiStreamingCollection::removeVolumeAt(hkaiStreamingCollection *this, int idx)
{
  hkaiStreamingCollection *v2; // rdi
  signed __int64 v3; // rbx
  hkaiNavVolumeInstance *v4; // rcx
  hkReferencedObject *v5; // rcx

  v2 = this;
  v3 = idx;
  v4 = this->m_instances.m_data[idx].m_volumeInstancePtr;
  if ( v4 )
  {
    hkReferencedObject::removeReference((hkReferencedObject *)&v4->vfptr);
    v2->m_instances.m_data[v3].m_volumeInstancePtr = 0i64;
  }
  v5 = (hkReferencedObject *)&v2->m_instances.m_data[v3].m_volumeMediator->vfptr;
  if ( v5 )
  {
    hkReferencedObject::removeReference(v5);
    v2->m_instances.m_data[v3].m_volumeMediator = 0i64;
  }
}

// File Line: 378
// RVA: 0xBBBDB0
__int64 __fastcall hkaiStreamingCollection::getNumInstances(hkaiStreamingCollection *this)
{
  __int64 v1; // rdx
  __int64 result; // rax
  hkaiStreamingCollection::InstanceInfo *v3; // rcx

  v1 = this->m_instances.m_size;
  result = 0i64;
  if ( v1 > 0 )
  {
    v3 = this->m_instances.m_data;
    do
    {
      if ( v3->m_instancePtr )
        result = (unsigned int)(result + 1);
      ++v3;
      --v1;
    }
    while ( v1 );
  }
  return result;
}

// File Line: 391
// RVA: 0xBBBDE0
__int64 __fastcall hkaiStreamingCollection::getNumVolumes(hkaiStreamingCollection *this)
{
  __int64 v1; // rdx
  __int64 result; // rax
  hkaiNavVolumeInstance **v3; // rcx

  v1 = this->m_instances.m_size;
  result = 0i64;
  if ( v1 > 0 )
  {
    v3 = &this->m_instances.m_data->m_volumeInstancePtr;
    do
    {
      if ( *v3 )
        result = (unsigned int)(result + 1);
      v3 += 6;
      --v1;
    }
    while ( v1 );
  }
  return result;
}

// File Line: 404
// RVA: 0xBBBFC0
hkaiNavMesh::Face *__fastcall hkaiStreamingCollection::getFaceFromPacked(hkaiStreamingCollection::InstanceInfo *info, unsigned int faceKey)
{
  hkaiNavMeshInstance *v2; // rcx

  v2 = info[faceKey >> 22].m_instancePtr;
  return hkaiNavMeshInstance_get_hkaiNavMesh::Face__1(
           v2->m_originalFaces,
           v2->m_numOriginalFaces,
           &v2->m_instancedFaces,
           &v2->m_ownedFaces,
           &v2->m_faceMap,
           faceKey & 0x3FFFFF);
}

// File Line: 417
// RVA: 0xBBC010
void __fastcall hkaiStreamingCollection::getEdgePoints(hkaiStreamingCollection::InstanceInfo *info, unsigned int edgeKey, hkVector4f *ea, hkVector4f *eb)
{
  hkaiNavMeshInstance::getEdgePoints(info[edgeKey >> 22].m_instancePtr, edgeKey & 0x3FFFFF, ea, eb);
}

// File Line: 435
// RVA: 0xBBBE10
void __fastcall hkaiStreamingCollection::getGraphNodePositionFromPacked(hkaiStreamingCollection *this, unsigned int nodeKey, hkVector4f *posOut)
{
  hkaiDirectedGraphInstance *v3; // r10
  __m128 v4; // xmm1

  v3 = this->m_instances.m_data[nodeKey >> 22].m_clusterGraphInstance;
  v4 = v3->m_originalPositions[nodeKey & 0x3FFFFF].m_quad;
  posOut->m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), v3->m_transform.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), v3->m_transform.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v4, v4, 170), v3->m_transform.m_rotation.m_col2.m_quad)),
                     v3->m_transform.m_translation.m_quad);
}

// File Line: 442
// RVA: 0xBBBE80
void __fastcall hkaiStreamingCollection::getGraphNodePositionFromPacked(hkaiStreamingCollection::InstanceInfo *info, unsigned int nodeKey, hkVector4f *posOut)
{
  hkaiDirectedGraphInstance *v3; // r10
  __m128 v4; // xmm1

  v3 = info[nodeKey >> 22].m_clusterGraphInstance;
  v4 = v3->m_originalPositions[nodeKey & 0x3FFFFF].m_quad;
  posOut->m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), v3->m_transform.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), v3->m_transform.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v4, v4, 170), v3->m_transform.m_rotation.m_col2.m_quad)),
                     v3->m_transform.m_translation.m_quad);
}

// File Line: 449
// RVA: 0xBBBEF0
hkaiDirectedGraphExplicitCost::Node *__fastcall hkaiStreamingCollection::getNodeFromPacked(hkaiStreamingCollection::InstanceInfo *info, unsigned int nodeKey)
{
  return &info[nodeKey >> 22].m_clusterGraphInstance->m_originalNodes[nodeKey & 0x3FFFFF];
}

// File Line: 456
// RVA: 0xBBBF20
hkaiDirectedGraphExplicitCost::Edge *__fastcall hkaiStreamingCollection::getGraphEdgeFromPacked(hkaiStreamingCollection *this, unsigned int edgeKey)
{
  signed int v2; // er8
  hkaiDirectedGraphInstance *v3; // rax
  signed int v4; // ecx
  hkaiDirectedGraphExplicitCost::Edge *result; // rax

  v2 = edgeKey & 0x3FFFFF;
  v3 = this->m_instances.m_data[edgeKey >> 22].m_clusterGraphInstance;
  v4 = v3->m_numOriginalEdges;
  if ( (signed int)(edgeKey & 0x3FFFFF) >= v4 )
    result = &v3->m_ownedEdges.m_data[v2 - v4];
  else
    result = &v3->m_originalEdges[v2];
  return result;
}

// File Line: 463
// RVA: 0xBBBF70
hkaiDirectedGraphExplicitCost::Edge *__fastcall hkaiStreamingCollection::getGraphEdgeFromPacked(hkaiStreamingCollection::InstanceInfo *info, unsigned int edgeKey)
{
  signed int v2; // er8
  hkaiDirectedGraphInstance *v3; // rax
  signed int v4; // ecx
  hkaiDirectedGraphExplicitCost::Edge *result; // rax

  v2 = edgeKey & 0x3FFFFF;
  v3 = info[edgeKey >> 22].m_clusterGraphInstance;
  v4 = v3->m_numOriginalEdges;
  if ( (signed int)(edgeKey & 0x3FFFFF) >= v4 )
    result = &v3->m_ownedEdges.m_data[v2 - v4];
  else
    result = &v3->m_originalEdges[v2];
  return result;
}

// File Line: 471
// RVA: 0xBBC040
signed __int64 __fastcall hkaiStreamingCollection::findSectionIdByUid(hkaiStreamingCollection *this, unsigned int uid)
{
  __int64 v2; // r10
  unsigned int v3; // er9
  __int64 v4; // r8
  hkaiStreamingCollection::InstanceInfo *v5; // rax

  v2 = this->m_instances.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
    return 0xFFFFFFFFi64;
  v5 = this->m_instances.m_data;
  while ( !v5->m_instancePtr || v5->m_instancePtr->m_sectionUid != uid )
  {
    ++v4;
    ++v3;
    ++v5;
    if ( v4 >= v2 )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 487
// RVA: 0xBBC080
signed __int64 __fastcall hkaiStreamingCollection::findGraphIdByUid(hkaiStreamingCollection *this, unsigned int uid)
{
  __int64 v2; // r10
  unsigned int v3; // er9
  unsigned int v4; // ebx
  __int64 v5; // rax
  __int64 v6; // r8
  hkaiDirectedGraphInstance *v7; // rdx

  v2 = this->m_instances.m_size;
  v3 = 0;
  v4 = uid;
  v5 = 0i64;
  if ( v2 <= 0 )
    return 0xFFFFFFFFi64;
  v6 = 0i64;
  while ( 1 )
  {
    if ( v5 >= 0 )
    {
      v7 = this->m_instances.m_data[v6].m_clusterGraphInstance;
      if ( v7 )
      {
        if ( v7->m_sectionUid == v4 )
          break;
      }
    }
    ++v5;
    ++v3;
    ++v6;
    if ( v5 >= v2 )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 503
// RVA: 0xBBC0E0
signed __int64 __fastcall hkaiStreamingCollection::findVolumeIdByUid(hkaiStreamingCollection *this, unsigned int uid)
{
  __int64 v2; // r10
  unsigned int v3; // er9
  __int64 v4; // r8
  hkaiNavVolumeInstance **v5; // rax

  v2 = this->m_instances.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
    return 0xFFFFFFFFi64;
  v5 = &this->m_instances.m_data->m_volumeInstancePtr;
  while ( !*v5 || (*v5)->m_sectionUid != uid )
  {
    ++v4;
    ++v3;
    v5 += 6;
    if ( v4 >= v2 )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 519
// RVA: 0xBBC410
void __fastcall hkaiStreamingCollection::validate(hkaiStreamingCollection *collection, bool checkAabb, bool checkClearanceCaches)
{
  int v3; // edi
  bool v4; // bp
  bool v5; // r14
  hkaiStreamingCollection *v6; // rsi
  __int64 v7; // rbx
  hkaiNavMeshInstance *v8; // rcx
  hkaiDirectedGraphInstance *v9; // rcx

  v3 = 0;
  v4 = checkClearanceCaches;
  v5 = checkAabb;
  v6 = collection;
  if ( collection->m_instances.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v6->m_instances.m_data[v7].m_instancePtr;
      if ( v8 )
      {
        hkaiNavMeshUtils::validate(v8, v5, v4);
        v9 = v6->m_instances.m_data[v7].m_clusterGraphInstance;
        if ( v9 )
          hkaiDirectedGraphInstance::validate(v9);
      }
      ++v3;
      ++v7;
    }
    while ( v3 < v6->m_instances.m_size );
  }
}

// File Line: 614
// RVA: 0xBBC4A0
void __fastcall hkaiStreamingCollection::validateExternalEdges(hkaiStreamingCollection *collection, hkaiNavMeshInstance *instance)
{
  ;
}

// File Line: 723
// RVA: 0xBBC4B0
void __fastcall hkaiStreamingCollection::validateGraphInstance(hkaiStreamingCollection *manager, hkaiDirectedGraphInstance *graphInstance)
{
  ;
}

// File Line: 744
// RVA: 0xBBC2C0
void __fastcall hkaiStreamingCollection::setupTree(hkaiStreamingCollection *this)
{
  hkaiStreamingCollection *v1; // rdi
  _QWORD **v2; // rax
  hkcdDynamicAabbTree *v3; // rax
  hkcdDynamicAabbTree *v4; // rax
  hkcdDynamicAabbTree *v5; // rbx
  hkReferencedObject *v6; // rcx

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 32i64);
  if ( v3 )
  {
    hkcdDynamicAabbTree::hkcdDynamicAabbTree(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = (hkReferencedObject *)&v1->m_tree.m_pntr->vfptr;
  if ( v6 && v6 != (hkReferencedObject *)v5 )
    hkReferencedObject::removeReference(v6);
  v1->m_tree.m_pntr = v5;
}

// File Line: 749
// RVA: 0xBBC4C0
void __fastcall hkaiStreamingCollection::addTreeNode(hkaiStreamingCollection *this, int sectionIdx, hkAabb *instanceAabb)
{
  hkAabb *v3; // rsi
  __int64 v4; // rdi
  hkaiStreamingCollection *v5; // rbx

  v3 = instanceAabb;
  v4 = sectionIdx;
  v5 = this;
  if ( !this->m_tree.m_pntr )
    hkaiStreamingCollection::setupTree(this);
  v5->m_instances.m_data[v4].m_treeNode = hkcdDynamicAabbTree::insert(v5->m_tree.m_pntr, v3, v4);
}

// File Line: 763
// RVA: 0xBBC130
void __fastcall hkaiStreamingCollection::setSectionTransform(hkaiStreamingCollection *this, hkaiNavMeshInstance *meshInstance, hkTransformf *transform)
{
  hkaiStreamingCollection::setSectionTransform(this, meshInstance->m_runtimeId, transform);
}

// File Line: 768
// RVA: 0xBBC260
void __fastcall hkaiStreamingCollection::setVolumeTranslation(hkaiStreamingCollection *this, hkaiNavVolumeInstance *meshInstance, hkVector4f *translation)
{
  int v3; // edx
  hkTransformf transform; // [rsp+20h] [rbp-48h]

  v3 = meshInstance->m_runtimeId;
  transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
  transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  transform.m_translation = (hkVector4f)translation->m_quad;
  hkaiStreamingCollection::setSectionTransform(this, v3, &transform);
}

// File Line: 775
// RVA: 0xBBC150
void __fastcall hkaiStreamingCollection::setSectionTransform(hkaiStreamingCollection *this, int sectionIdx, hkTransformf *transform)
{
  hkaiStreamingCollection *v3; // rbp
  char v4; // si
  hkTransformf *v5; // rdi
  hkaiStreamingCollection::InstanceInfo *v6; // rbx
  hkaiNavMeshInstance *v7; // rcx
  hkaiDirectedGraphInstance *v8; // rax
  __m128 *v9; // rcx
  __m128 *v10; // rax
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  hkcdDynamicAabbTree *v13; // rcx
  hkAabb aabbOut; // [rsp+20h] [rbp-28h]

  v3 = this;
  v4 = 0;
  v5 = transform;
  v6 = &this->m_instances.m_data[sectionIdx];
  v7 = v6->m_instancePtr;
  if ( v6->m_instancePtr )
  {
    v4 = 1;
    v7->m_referenceFrame.m_transform.m_rotation.m_col0 = transform->m_rotation.m_col0;
    v7->m_referenceFrame.m_transform.m_rotation.m_col1 = transform->m_rotation.m_col1;
    v7->m_referenceFrame.m_transform.m_rotation.m_col2 = transform->m_rotation.m_col2;
    v7->m_referenceFrame.m_transform.m_translation = transform->m_translation;
    hkaiNavMeshInstance::getAabb(v7, &aabbOut);
  }
  v8 = v6->m_clusterGraphInstance;
  if ( v8 )
  {
    v8->m_transform.m_rotation.m_col0 = v5->m_rotation.m_col0;
    v8->m_transform.m_rotation.m_col1 = v5->m_rotation.m_col1;
    v8->m_transform.m_rotation.m_col2 = v5->m_rotation.m_col2;
    v8->m_transform.m_translation = v5->m_translation;
  }
  v9 = (__m128 *)v6->m_volumeInstancePtr;
  if ( v9 )
  {
    v10 = (__m128 *)v9[3].m128_u64[0];
    v11 = v5->m_translation.m_quad;
    v4 = 1;
    v9[7] = v11;
    v12 = v10[5];
    aabbOut.m_min.m_quad = _mm_add_ps(v11, v10[4]);
    aabbOut.m_max.m_quad = _mm_add_ps(v12, v9[7]);
  }
  v13 = v3->m_tree.m_pntr;
  if ( v13 )
  {
    if ( v4 )
      hkcdDynamicAabbTree::update(v13, v6->m_treeNode, &aabbOut);
  }
}

// File Line: 809
// RVA: 0xBBC330
bool __fastcall hkaiStreamingCollection::areKeysConsistent(hkaiStreamingCollection *this, unsigned int faceKey, unsigned int edgeKey)
{
  unsigned int v3; // er11
  __int64 v4; // r8
  hkaiNavMeshInstance *v5; // rcx
  bool result; // al
  int v7; // er10
  int index; // edx
  int v9; // er11
  hkaiNavMesh::Face *v10; // rax
  int v11; // er11
  int v12; // ecx

  v3 = edgeKey;
  v4 = faceKey >> 22;
  if ( (_DWORD)v4 != v3 >> 22 )
    return 0;
  v5 = this->m_instances.m_data[v4].m_instancePtr;
  if ( !v5 )
    return 1;
  v7 = v5->m_numOriginalFaces;
  index = faceKey & 0x3FFFFF;
  v9 = v3 & 0x3FFFFF;
  if ( index >= v7 + v5->m_ownedFaces.m_size || v9 >= v5->m_numOriginalEdges + v5->m_ownedEdges.m_size )
    return 0;
  v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__1(
          v5->m_originalFaces,
          v7,
          &v5->m_instancedFaces,
          &v5->m_ownedFaces,
          &v5->m_faceMap,
          index);
  result = 1;
  if ( v11 < v10->m_startEdgeIndex || v11 >= v10->m_startEdgeIndex + v10->m_numEdges )
  {
    v12 = v10->m_startUserEdgeIndex;
    if ( v11 < v12 || v11 >= v12 + v10->m_numUserEdges )
      result = 0;
  }
  return result;
}

