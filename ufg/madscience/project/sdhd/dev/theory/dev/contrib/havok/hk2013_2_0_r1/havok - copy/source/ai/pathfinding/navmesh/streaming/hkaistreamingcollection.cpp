// File Line: 38
// RVA: 0xBBB2B0
void __fastcall hkaiStreamingCollection::hkaiStreamingCollection(
        hkaiStreamingCollection *this,
        hkFinishLoadedObjectFlag f)
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
  this->m_instances.m_capacityAndFlags = 0x80000000;
}

// File Line: 50
// RVA: 0xBBB2D0
void __fastcall hkaiStreamingCollection::init(
        hkaiStreamingCollection *this,
        hkaiNavMeshInstance *meshInstance,
        hkaiDirectedGraphInstance *clusterGraph,
        hkaiNavMeshQueryMediator *mediator)
{
  __int64 m_size; // rax
  int v9; // ecx
  __int64 v10; // rdx
  __int64 v11; // rax
  char *v12; // rax
  hkAabb aabbOut; // [rsp+30h] [rbp-38h] BYREF
  hkResult result; // [rsp+70h] [rbp+8h] BYREF

  hkaiStreamingCollection::clear(this);
  if ( (this->m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_instances, 1, 48);
  m_size = this->m_instances.m_size;
  v9 = 1 - m_size;
  v10 = 1 - (int)m_size;
  v11 = 48 * m_size + 16;
  if ( v9 > 0 )
  {
    v12 = (char *)this->m_instances.m_data + v11;
    do
    {
      if ( v12 != (char *)16 )
      {
        *((_QWORD *)v12 - 2) = 0i64;
        *((_QWORD *)v12 - 1) = 0i64;
        *(_QWORD *)v12 = 0i64;
        *((_QWORD *)v12 + 1) = 0i64;
        *((_QWORD *)v12 + 2) = 0i64;
        *((_DWORD *)v12 + 6) = -1;
      }
      v12 += 48;
      --v10;
    }
    while ( v10 );
  }
  this->m_instances.m_size = 1;
  if ( meshInstance )
  {
    meshInstance->m_runtimeId = 0;
    hkReferencedObject::addReference(meshInstance);
  }
  this->m_instances.m_data->m_instancePtr = meshInstance;
  if ( clusterGraph )
  {
    clusterGraph->m_runtimeId = 0;
    hkReferencedObject::addReference(clusterGraph);
  }
  this->m_instances.m_data->m_clusterGraphInstance = clusterGraph;
  if ( mediator )
    hkReferencedObject::addReference(mediator);
  this->m_instances.m_data->m_mediator = mediator;
  hkaiNavMeshInstance::getAabb(meshInstance, &aabbOut);
  hkaiStreamingCollection::addTreeNode(this, 0, &aabbOut);
}

// File Line: 82
// RVA: 0xBBB420
void __fastcall hkaiStreamingCollection::init(
        hkaiStreamingCollection *this,
        hkaiNavVolumeInstance *vol,
        hkaiNavVolumeMediator *mediator)
{
  __int64 m_size; // rax
  int v7; // ecx
  __int64 v8; // rdx
  __int64 v9; // rax
  char *v10; // rax
  hkaiNavVolume *m_pntr; // rax
  hkVector4f v12; // xmm2
  hkAabb instanceAabb; // [rsp+30h] [rbp-28h] BYREF
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  hkaiStreamingCollection::clear(this);
  if ( (this->m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_instances, 1, 48);
  m_size = this->m_instances.m_size;
  v7 = 1 - m_size;
  v8 = 1 - (int)m_size;
  v9 = 48 * m_size + 16;
  if ( v7 > 0 )
  {
    v10 = (char *)this->m_instances.m_data + v9;
    do
    {
      if ( v10 != (char *)16 )
      {
        *((_QWORD *)v10 - 2) = 0i64;
        *((_QWORD *)v10 - 1) = 0i64;
        *(_QWORD *)v10 = 0i64;
        *((_QWORD *)v10 + 1) = 0i64;
        *((_QWORD *)v10 + 2) = 0i64;
        *((_DWORD *)v10 + 6) = -1;
      }
      v10 += 48;
      --v8;
    }
    while ( v8 );
  }
  this->m_instances.m_size = 1;
  if ( vol )
    hkReferencedObject::addReference(vol);
  this->m_instances.m_data->m_volumeInstancePtr = vol;
  if ( mediator )
    hkReferencedObject::addReference(mediator);
  this->m_instances.m_data->m_volumeMediator = mediator;
  m_pntr = vol->m_originalVolume.m_pntr;
  v12.m_quad = _mm_add_ps(vol->m_translation.m_quad, m_pntr->m_aabb.m_max.m_quad);
  instanceAabb.m_min.m_quad = _mm_add_ps(vol->m_translation.m_quad, m_pntr->m_aabb.m_min.m_quad);
  instanceAabb.m_max = (hkVector4f)v12.m_quad;
  hkaiStreamingCollection::addTreeNode(this, 0, &instanceAabb);
}

// File Line: 107
// RVA: 0xBBB220
void __fastcall hkaiStreamingCollection::~hkaiStreamingCollection(hkaiStreamingCollection *this)
{
  int m_capacityAndFlags; // eax
  hkcdDynamicAabbTree *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiStreamingCollection::`vftable;
  hkaiStreamingCollection::clear(this);
  m_capacityAndFlags = this->m_instances.m_capacityAndFlags;
  this->m_instances.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_instances.m_data,
      48 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_instances.m_data = 0i64;
  this->m_instances.m_capacityAndFlags = 0x80000000;
  m_pntr = this->m_tree.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_tree.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 112
// RVA: 0xBBBC60
void __fastcall hkaiStreamingCollection::clear(hkaiStreamingCollection *this)
{
  int v2; // edi
  __int64 v3; // rsi
  hkaiStreamingCollection::InstanceInfo *v4; // rbx
  hkReferencedObject *m_volumeInstancePtr; // rcx
  hkReferencedObject *m_clusterGraphInstance; // rcx
  hkReferencedObject *m_mediator; // rcx
  hkReferencedObject *m_volumeMediator; // rcx
  int v9; // ecx
  __int64 v10; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax

  if ( !this->m_isTemporary.m_bool )
  {
    v2 = 0;
    if ( this->m_instances.m_size > 0 )
    {
      v3 = 0i64;
      do
      {
        v4 = &this->m_instances.m_data[v3];
        if ( v4->m_instancePtr )
        {
          hkReferencedObject::removeReference(v4->m_instancePtr);
          v4->m_instancePtr = 0i64;
        }
        m_volumeInstancePtr = v4->m_volumeInstancePtr;
        if ( m_volumeInstancePtr )
        {
          hkReferencedObject::removeReference(m_volumeInstancePtr);
          v4->m_volumeInstancePtr = 0i64;
        }
        m_clusterGraphInstance = v4->m_clusterGraphInstance;
        if ( m_clusterGraphInstance )
        {
          hkReferencedObject::removeReference(m_clusterGraphInstance);
          v4->m_clusterGraphInstance = 0i64;
        }
        m_mediator = v4->m_mediator;
        if ( m_mediator )
        {
          hkReferencedObject::removeReference(m_mediator);
          v4->m_mediator = 0i64;
        }
        m_volumeMediator = v4->m_volumeMediator;
        if ( m_volumeMediator )
        {
          hkReferencedObject::removeReference(m_volumeMediator);
          v4->m_volumeMediator = 0i64;
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->m_instances.m_size );
    }
  }
  v9 = -this->m_instances.m_size;
  v10 = v9;
  if ( v9 >= 0 && this->m_instances.m_size != 0 )
  {
    p_m_clusterGraphInstance = &this->m_instances.m_data[this->m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( p_m_clusterGraphInstance != (hkaiDirectedGraphInstance **)16 )
      {
        *(p_m_clusterGraphInstance - 2) = 0i64;
        *(p_m_clusterGraphInstance - 1) = 0i64;
        *p_m_clusterGraphInstance = 0i64;
        p_m_clusterGraphInstance[1] = 0i64;
        p_m_clusterGraphInstance[2] = 0i64;
        *((_DWORD *)p_m_clusterGraphInstance + 6) = -1;
      }
      p_m_clusterGraphInstance += 6;
      --v10;
    }
    while ( v10 );
  }
  this->m_instances.m_size = 0;
}

// File Line: 130
// RVA: 0xBBB550
void __fastcall hkaiStreamingCollection::addInstance(
        hkaiStreamingCollection *this,
        hkaiNavMeshInstance *instance,
        hkaiNavMeshQueryMediator *mediator,
        hkaiDirectedGraphInstance *clusterGraphInstance)
{
  int m_size; // esi
  int v5; // r11d
  int v10; // ebx
  hkaiStreamingCollection::InstanceInfo *m_data; // r10
  hkArray<hkaiStreamingCollection::InstanceInfo,hkContainerHeapAllocator> *p_m_instances; // rdi
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rcx
  __int64 v14; // rcx
  hkReferencedObject *m_instancePtr; // rcx
  hkReferencedObject *m_mediator; // rcx
  hkReferencedObject *v17; // rcx
  hkAabb aabbOut; // [rsp+20h] [rbp-48h] BYREF

  m_size = this->m_instances.m_size;
  v5 = -1;
  v10 = 0;
  if ( m_size <= 0 )
    goto LABEL_15;
  m_data = this->m_instances.m_data;
  p_m_instances = &this->m_instances;
  while ( 1 )
  {
    m_clusterGraphInstance = m_data->m_clusterGraphInstance;
    if ( m_clusterGraphInstance )
    {
      if ( m_clusterGraphInstance->m_sectionUid == instance->m_sectionUid )
        break;
    }
    if ( v5 == -1 && !m_data->m_instancePtr && !m_data->m_volumeInstancePtr && !m_clusterGraphInstance )
      v5 = v10;
    ++v10;
    ++m_data;
    if ( v10 >= m_size )
      goto LABEL_13;
  }
  if ( v10 != -1 )
    goto LABEL_20;
LABEL_13:
  if ( v5 == -1 )
  {
LABEL_15:
    p_m_instances = &this->m_instances;
    v10 = m_size;
    if ( this->m_instances.m_size == (this->m_instances.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_instances, 48);
    v14 = (__int64)&p_m_instances->m_data[this->m_instances.m_size];
    if ( v14 )
    {
      *(_QWORD *)v14 = 0i64;
      *(_QWORD *)(v14 + 8) = 0i64;
      *(_QWORD *)(v14 + 16) = 0i64;
      *(_QWORD *)(v14 + 24) = 0i64;
      *(_QWORD *)(v14 + 32) = 0i64;
      *(_DWORD *)(v14 + 40) = -1;
    }
    ++this->m_instances.m_size;
  }
  else
  {
    v10 = v5;
  }
LABEL_20:
  instance->m_runtimeId = v10;
  hkReferencedObject::addReference(instance);
  m_instancePtr = p_m_instances->m_data[v10].m_instancePtr;
  if ( m_instancePtr )
    hkReferencedObject::removeReference(m_instancePtr);
  p_m_instances->m_data[v10].m_instancePtr = instance;
  if ( mediator )
    hkReferencedObject::addReference(mediator);
  m_mediator = p_m_instances->m_data[v10].m_mediator;
  if ( m_mediator )
    hkReferencedObject::removeReference(m_mediator);
  p_m_instances->m_data[v10].m_mediator = mediator;
  if ( clusterGraphInstance && !p_m_instances->m_data[v10].m_clusterGraphInstance )
  {
    clusterGraphInstance->m_runtimeId = v10;
    hkReferencedObject::addReference(clusterGraphInstance);
    v17 = p_m_instances->m_data[v10].m_clusterGraphInstance;
    if ( v17 )
      hkReferencedObject::removeReference(v17);
    p_m_instances->m_data[v10].m_clusterGraphInstance = clusterGraphInstance;
    hkaiStreamingManager::loadGraphInstance(clusterGraphInstance, this);
  }
  hkaiNavMeshInstance::getAabb(instance, &aabbOut);
  hkaiStreamingCollection::addTreeNode(this, v10, &aabbOut);
}

// File Line: 206
// RVA: 0xBBB710
void __fastcall hkaiStreamingCollection::removeInstance(
        hkaiStreamingCollection *this,
        hkaiNavMeshInstance *instance,
        hkaiDirectedGraphInstance *clusterGraphInstance)
{
  __int64 m_runtimeId; // rbp

  m_runtimeId = instance->m_runtimeId;
  if ( (int)m_runtimeId >= 0 )
  {
    hkcdDynamicAabbTree::remove(this->m_tree.m_pntr, this->m_instances.m_data[m_runtimeId].m_treeNode);
    this->m_instances.m_data[m_runtimeId].m_treeNode = -1;
    instance->m_runtimeId = -1;
    hkaiStreamingCollection::removeInstanceAt(this, m_runtimeId);
    if ( clusterGraphInstance )
    {
      hkaiStreamingManager::unloadGraphInstance(clusterGraphInstance, this);
      hkaiStreamingCollection::removeMeshGraph(this, clusterGraphInstance);
    }
  }
}

// File Line: 233
// RVA: 0xBBB7C0
void __fastcall hkaiStreamingCollection::removeInstanceAt(hkaiStreamingCollection *this, int idx)
{
  __int64 v3; // rbx
  hkaiNavMeshInstance *m_instancePtr; // rcx
  hkaiNavMeshQueryMediator *m_mediator; // rcx

  v3 = idx;
  m_instancePtr = this->m_instances.m_data[idx].m_instancePtr;
  if ( m_instancePtr )
  {
    hkReferencedObject::removeReference(m_instancePtr);
    this->m_instances.m_data[v3].m_instancePtr = 0i64;
  }
  m_mediator = this->m_instances.m_data[v3].m_mediator;
  if ( m_mediator )
  {
    hkReferencedObject::removeReference(m_mediator);
    this->m_instances.m_data[v3].m_mediator = 0i64;
  }
}

// File Line: 242
// RVA: 0xBBB830
void __fastcall hkaiStreamingCollection::addMeshGraph(
        hkaiStreamingCollection *this,
        hkaiDirectedGraphInstance *graphInstance)
{
  __int64 m_size; // rcx
  int v5; // edi
  __int64 v6; // r8
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  hkArray<hkaiStreamingCollection::InstanceInfo,hkContainerHeapAllocator> *p_m_instances; // rbx
  __int64 v9; // rcx
  hkaiStreamingCollection::InstanceInfo *v10; // rax
  __int64 v11; // rdi
  hkReferencedObject *m_clusterGraphInstance; // rcx

  m_size = this->m_instances.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( (int)m_size <= 0 )
    goto LABEL_9;
  m_data = this->m_instances.m_data;
  p_m_instances = &this->m_instances;
  while ( m_data->m_instancePtr || m_data->m_volumeInstancePtr || m_data->m_clusterGraphInstance )
  {
    ++v6;
    ++v5;
    ++m_data;
    if ( v6 >= m_size )
      goto LABEL_9;
  }
  if ( v5 == -1 )
  {
LABEL_9:
    p_m_instances = &this->m_instances;
    v5 = m_size;
    if ( this->m_instances.m_size == (this->m_instances.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_instances, 48);
    v9 = (__int64)&p_m_instances->m_data[this->m_instances.m_size];
    if ( v9 )
    {
      *(_QWORD *)v9 = 0i64;
      *(_QWORD *)(v9 + 8) = 0i64;
      *(_QWORD *)(v9 + 16) = 0i64;
      *(_QWORD *)(v9 + 24) = 0i64;
      *(_QWORD *)(v9 + 32) = 0i64;
      *(_DWORD *)(v9 + 40) = -1;
    }
    ++this->m_instances.m_size;
  }
  graphInstance->m_runtimeId = v5;
  hkaiStreamingManager::loadGraphInstance(graphInstance, this);
  hkReferencedObject::addReference(graphInstance);
  v10 = p_m_instances->m_data;
  v11 = v5;
  m_clusterGraphInstance = p_m_instances->m_data[v11].m_clusterGraphInstance;
  if ( m_clusterGraphInstance )
  {
    hkReferencedObject::removeReference(m_clusterGraphInstance);
    v10 = p_m_instances->m_data;
  }
  v10[v11].m_clusterGraphInstance = graphInstance;
}

// File Line: 281
// RVA: 0xBBB950
void __fastcall hkaiStreamingCollection::removeMeshGraph(
        hkaiStreamingCollection *this,
        hkaiDirectedGraphInstance *clusterGraph)
{
  int m_runtimeId; // edi

  m_runtimeId = clusterGraph->m_runtimeId;
  if ( m_runtimeId >= 0 )
  {
    hkaiStreamingManager::unloadGraphInstance(clusterGraph, this);
    clusterGraph->m_runtimeId = -1;
    hkaiStreamingCollection::removeMeshGraphAt(this, m_runtimeId);
  }
}

// File Line: 294
// RVA: 0xBBB9A0
void __fastcall hkaiStreamingCollection::removeMeshGraphAt(hkaiStreamingCollection *this, int idx)
{
  __int64 v3; // rbx
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rcx

  v3 = idx;
  m_clusterGraphInstance = this->m_instances.m_data[idx].m_clusterGraphInstance;
  if ( m_clusterGraphInstance )
  {
    hkReferencedObject::removeReference(m_clusterGraphInstance);
    this->m_instances.m_data[v3].m_clusterGraphInstance = 0i64;
  }
}

// File Line: 302
// RVA: 0xBBB9F0
void __fastcall hkaiStreamingCollection::addVolume(
        hkaiStreamingCollection *this,
        hkaiNavVolumeInstance *volumeInstance,
        hkaiNavVolumeMediator *mediator)
{
  __int64 m_size; // rcx
  int v7; // edi
  __int64 v8; // r9
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  hkArray<hkaiStreamingCollection::InstanceInfo,hkContainerHeapAllocator> *p_m_instances; // rbx
  __int64 v11; // rcx
  hkReferencedObject *m_volumeInstancePtr; // rcx
  hkReferencedObject *m_volumeMediator; // rcx
  hkaiNavVolume *m_pntr; // rax
  hkVector4f v15; // xmm2
  hkAabb instanceAabb; // [rsp+20h] [rbp-38h] BYREF

  m_size = this->m_instances.m_size;
  v7 = 0;
  v8 = 0i64;
  if ( (int)m_size <= 0 )
    goto LABEL_9;
  m_data = this->m_instances.m_data;
  p_m_instances = &this->m_instances;
  while ( m_data->m_instancePtr || m_data->m_volumeInstancePtr || m_data->m_clusterGraphInstance )
  {
    ++v8;
    ++v7;
    ++m_data;
    if ( v8 >= m_size )
      goto LABEL_9;
  }
  if ( v7 == -1 )
  {
LABEL_9:
    p_m_instances = &this->m_instances;
    v7 = m_size;
    if ( this->m_instances.m_size == (this->m_instances.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_instances, 48);
    v11 = (__int64)&p_m_instances->m_data[this->m_instances.m_size];
    if ( v11 )
    {
      *(_QWORD *)v11 = 0i64;
      *(_QWORD *)(v11 + 8) = 0i64;
      *(_QWORD *)(v11 + 16) = 0i64;
      *(_QWORD *)(v11 + 24) = 0i64;
      *(_QWORD *)(v11 + 32) = 0i64;
      *(_DWORD *)(v11 + 40) = -1;
    }
    ++this->m_instances.m_size;
  }
  volumeInstance->m_runtimeId = v7;
  hkaiStreamingManager::loadVolumeInstance(volumeInstance, this);
  hkReferencedObject::addReference(volumeInstance);
  m_volumeInstancePtr = p_m_instances->m_data[v7].m_volumeInstancePtr;
  if ( m_volumeInstancePtr )
    hkReferencedObject::removeReference(m_volumeInstancePtr);
  p_m_instances->m_data[v7].m_volumeInstancePtr = volumeInstance;
  if ( mediator )
    hkReferencedObject::addReference(mediator);
  m_volumeMediator = p_m_instances->m_data[v7].m_volumeMediator;
  if ( m_volumeMediator )
    hkReferencedObject::removeReference(m_volumeMediator);
  p_m_instances->m_data[v7].m_volumeMediator = mediator;
  m_pntr = volumeInstance->m_originalVolume.m_pntr;
  v15.m_quad = _mm_add_ps(volumeInstance->m_translation.m_quad, m_pntr->m_aabb.m_max.m_quad);
  instanceAabb.m_min.m_quad = _mm_add_ps(volumeInstance->m_translation.m_quad, m_pntr->m_aabb.m_min.m_quad);
  instanceAabb.m_max = (hkVector4f)v15.m_quad;
  hkaiStreamingCollection::addTreeNode(this, v7, &instanceAabb);
}

// File Line: 347
// RVA: 0xBBBB60
void __fastcall hkaiStreamingCollection::removeVolume(
        hkaiStreamingCollection *this,
        hkaiNavVolumeInstance *volumeInstance)
{
  __int64 m_runtimeId; // rsi

  m_runtimeId = volumeInstance->m_runtimeId;
  hkcdDynamicAabbTree::remove(this->m_tree.m_pntr, this->m_instances.m_data[m_runtimeId].m_treeNode);
  this->m_instances.m_data[m_runtimeId].m_treeNode = -1;
  if ( (int)m_runtimeId >= 0 )
  {
    hkaiStreamingManager::unloadVolumeInstance(volumeInstance, this);
    this->m_instances.m_data[m_runtimeId].m_volumeInstancePtr->m_runtimeId = -1;
    hkaiStreamingCollection::removeVolumeAt(this, m_runtimeId);
  }
}

// File Line: 367
// RVA: 0xBBBBF0
void __fastcall hkaiStreamingCollection::removeVolumeAt(hkaiStreamingCollection *this, int idx)
{
  __int64 v3; // rbx
  hkaiNavVolumeInstance *m_volumeInstancePtr; // rcx
  hkaiNavVolumeMediator *m_volumeMediator; // rcx

  v3 = idx;
  m_volumeInstancePtr = this->m_instances.m_data[idx].m_volumeInstancePtr;
  if ( m_volumeInstancePtr )
  {
    hkReferencedObject::removeReference(m_volumeInstancePtr);
    this->m_instances.m_data[v3].m_volumeInstancePtr = 0i64;
  }
  m_volumeMediator = this->m_instances.m_data[v3].m_volumeMediator;
  if ( m_volumeMediator )
  {
    hkReferencedObject::removeReference(m_volumeMediator);
    this->m_instances.m_data[v3].m_volumeMediator = 0i64;
  }
}

// File Line: 378
// RVA: 0xBBBDB0
__int64 __fastcall hkaiStreamingCollection::getNumInstances(hkaiStreamingCollection *this)
{
  __int64 m_size; // rdx
  __int64 result; // rax
  hkaiStreamingCollection::InstanceInfo *m_data; // rcx

  m_size = this->m_instances.m_size;
  result = 0i64;
  if ( m_size > 0 )
  {
    m_data = this->m_instances.m_data;
    do
    {
      if ( m_data->m_instancePtr )
        result = (unsigned int)(result + 1);
      ++m_data;
      --m_size;
    }
    while ( m_size );
  }
  return result;
}

// File Line: 391
// RVA: 0xBBBDE0
__int64 __fastcall hkaiStreamingCollection::getNumVolumes(hkaiStreamingCollection *this)
{
  __int64 m_size; // rdx
  __int64 result; // rax
  hkaiNavVolumeInstance **p_m_volumeInstancePtr; // rcx

  m_size = this->m_instances.m_size;
  result = 0i64;
  if ( m_size > 0 )
  {
    p_m_volumeInstancePtr = &this->m_instances.m_data->m_volumeInstancePtr;
    do
    {
      if ( *p_m_volumeInstancePtr )
        result = (unsigned int)(result + 1);
      p_m_volumeInstancePtr += 6;
      --m_size;
    }
    while ( m_size );
  }
  return result;
}

// File Line: 404
// RVA: 0xBBBFC0
hkaiNavMesh::Face *__fastcall hkaiStreamingCollection::getFaceFromPacked(
        hkaiStreamingCollection::InstanceInfo *info,
        unsigned int faceKey)
{
  hkaiNavMeshInstance *m_instancePtr; // rcx

  m_instancePtr = info[faceKey >> 22].m_instancePtr;
  return hkaiNavMeshInstance_get_hkaiNavMesh::Face__1(
           m_instancePtr->m_originalFaces,
           m_instancePtr->m_numOriginalFaces,
           &m_instancePtr->m_instancedFaces,
           &m_instancePtr->m_ownedFaces,
           &m_instancePtr->m_faceMap,
           faceKey & 0x3FFFFF);
}

// File Line: 417
// RVA: 0xBBC010
void __fastcall hkaiStreamingCollection::getEdgePoints(
        hkaiStreamingCollection::InstanceInfo *info,
        unsigned int edgeKey,
        hkVector4f *ea,
        hkVector4f *eb)
{
  hkaiNavMeshInstance::getEdgePoints(info[edgeKey >> 22].m_instancePtr, edgeKey & 0x3FFFFF, ea, eb);
}

// File Line: 435
// RVA: 0xBBBE10
void __fastcall hkaiStreamingCollection::getGraphNodePositionFromPacked(
        hkaiStreamingCollection *this,
        unsigned int nodeKey,
        hkVector4f *posOut)
{
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // r10
  __m128 m_quad; // xmm1

  m_clusterGraphInstance = this->m_instances.m_data[nodeKey >> 22].m_clusterGraphInstance;
  m_quad = m_clusterGraphInstance->m_originalPositions[nodeKey & 0x3FFFFF].m_quad;
  posOut->m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(m_quad, m_quad, 85),
                           m_clusterGraphInstance->m_transform.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(
                           _mm_shuffle_ps(m_quad, m_quad, 0),
                           m_clusterGraphInstance->m_transform.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(
                         _mm_shuffle_ps(m_quad, m_quad, 170),
                         m_clusterGraphInstance->m_transform.m_rotation.m_col2.m_quad)),
                     m_clusterGraphInstance->m_transform.m_translation.m_quad);
}

// File Line: 442
// RVA: 0xBBBE80
void __fastcall hkaiStreamingCollection::getGraphNodePositionFromPacked(
        hkaiStreamingCollection::InstanceInfo *info,
        unsigned int nodeKey,
        hkVector4f *posOut)
{
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // r10
  __m128 m_quad; // xmm1

  m_clusterGraphInstance = info[nodeKey >> 22].m_clusterGraphInstance;
  m_quad = m_clusterGraphInstance->m_originalPositions[nodeKey & 0x3FFFFF].m_quad;
  posOut->m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(m_quad, m_quad, 85),
                           m_clusterGraphInstance->m_transform.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(
                           _mm_shuffle_ps(m_quad, m_quad, 0),
                           m_clusterGraphInstance->m_transform.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(
                         _mm_shuffle_ps(m_quad, m_quad, 170),
                         m_clusterGraphInstance->m_transform.m_rotation.m_col2.m_quad)),
                     m_clusterGraphInstance->m_transform.m_translation.m_quad);
}

// File Line: 449
// RVA: 0xBBBEF0
hkaiDirectedGraphExplicitCost::Node *__fastcall hkaiStreamingCollection::getNodeFromPacked(
        hkaiStreamingCollection::InstanceInfo *info,
        unsigned int nodeKey)
{
  return &info[nodeKey >> 22].m_clusterGraphInstance->m_originalNodes[nodeKey & 0x3FFFFF];
}

// File Line: 456
// RVA: 0xBBBF20
hkaiDirectedGraphExplicitCost::Edge *__fastcall hkaiStreamingCollection::getGraphEdgeFromPacked(
        hkaiStreamingCollection *this,
        unsigned int edgeKey)
{
  signed int v2; // r8d
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rax
  signed int m_numOriginalEdges; // ecx

  v2 = edgeKey & 0x3FFFFF;
  m_clusterGraphInstance = this->m_instances.m_data[edgeKey >> 22].m_clusterGraphInstance;
  m_numOriginalEdges = m_clusterGraphInstance->m_numOriginalEdges;
  if ( (int)(edgeKey & 0x3FFFFF) >= m_numOriginalEdges )
    return &m_clusterGraphInstance->m_ownedEdges.m_data[v2 - m_numOriginalEdges];
  else
    return &m_clusterGraphInstance->m_originalEdges[v2];
}

// File Line: 463
// RVA: 0xBBBF70
hkaiDirectedGraphExplicitCost::Edge *__fastcall hkaiStreamingCollection::getGraphEdgeFromPacked(
        hkaiStreamingCollection::InstanceInfo *info,
        unsigned int edgeKey)
{
  signed int v2; // r8d
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rax
  signed int m_numOriginalEdges; // ecx

  v2 = edgeKey & 0x3FFFFF;
  m_clusterGraphInstance = info[edgeKey >> 22].m_clusterGraphInstance;
  m_numOriginalEdges = m_clusterGraphInstance->m_numOriginalEdges;
  if ( (int)(edgeKey & 0x3FFFFF) >= m_numOriginalEdges )
    return &m_clusterGraphInstance->m_ownedEdges.m_data[v2 - m_numOriginalEdges];
  else
    return &m_clusterGraphInstance->m_originalEdges[v2];
}

// File Line: 471
// RVA: 0xBBC040
__int64 __fastcall hkaiStreamingCollection::findSectionIdByUid(hkaiStreamingCollection *this, unsigned int uid)
{
  __int64 m_size; // r10
  unsigned int v3; // r9d
  __int64 v4; // r8
  hkaiStreamingCollection::InstanceInfo *i; // rax

  m_size = this->m_instances.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = this->m_instances.m_data; !i->m_instancePtr || i->m_instancePtr->m_sectionUid != uid; ++i )
  {
    ++v4;
    ++v3;
    if ( v4 >= m_size )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 487
// RVA: 0xBBC080
__int64 __fastcall hkaiStreamingCollection::findGraphIdByUid(hkaiStreamingCollection *this, unsigned int uid)
{
  __int64 m_size; // r10
  unsigned int v3; // r9d
  __int64 v5; // rax
  __int64 i; // r8
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rdx

  m_size = this->m_instances.m_size;
  v3 = 0;
  v5 = 0i64;
  if ( m_size <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = 0i64; ; ++i )
  {
    if ( v5 >= 0 )
    {
      m_clusterGraphInstance = this->m_instances.m_data[i].m_clusterGraphInstance;
      if ( m_clusterGraphInstance )
      {
        if ( m_clusterGraphInstance->m_sectionUid == uid )
          break;
      }
    }
    ++v5;
    ++v3;
    if ( v5 >= m_size )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 503
// RVA: 0xBBC0E0
__int64 __fastcall hkaiStreamingCollection::findVolumeIdByUid(hkaiStreamingCollection *this, unsigned int uid)
{
  __int64 m_size; // r10
  unsigned int v3; // r9d
  __int64 v4; // r8
  hkaiNavVolumeInstance **i; // rax

  m_size = this->m_instances.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = &this->m_instances.m_data->m_volumeInstancePtr; !*i || (*i)->m_sectionUid != uid; i += 6 )
  {
    ++v4;
    ++v3;
    if ( v4 >= m_size )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 519
// RVA: 0xBBC410
void __fastcall hkaiStreamingCollection::validate(
        hkaiStreamingCollection *collection,
        bool checkAabb,
        bool checkClearanceCaches)
{
  int v3; // edi
  __int64 v7; // rbx
  hkaiNavMeshInstance *m_instancePtr; // rcx
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rcx

  v3 = 0;
  if ( collection->m_instances.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      m_instancePtr = collection->m_instances.m_data[v7].m_instancePtr;
      if ( m_instancePtr )
      {
        hkaiNavMeshUtils::validate(m_instancePtr, checkAabb, checkClearanceCaches);
        m_clusterGraphInstance = collection->m_instances.m_data[v7].m_clusterGraphInstance;
        if ( m_clusterGraphInstance )
          hkaiDirectedGraphInstance::validate(m_clusterGraphInstance);
      }
      ++v3;
      ++v7;
    }
    while ( v3 < collection->m_instances.m_size );
  }
}

// File Line: 614
// RVA: 0xBBC4A0
void __fastcall hkaiStreamingCollection::validateExternalEdges(
        hkaiStreamingCollection *collection,
        hkaiNavMeshInstance *instance)
{
  ;
}

// File Line: 723
// RVA: 0xBBC4B0
void __fastcall hkaiStreamingCollection::validateGraphInstance(
        hkaiStreamingCollection *manager,
        hkaiDirectedGraphInstance *graphInstance)
{
  ;
}

// File Line: 744
// RVA: 0xBBC2C0
void __fastcall hkaiStreamingCollection::setupTree(hkaiStreamingCollection *this)
{
  _QWORD **Value; // rax
  hkcdDynamicAabbTree *v3; // rax
  hkcdDynamicAabbTree *v4; // rax
  hkcdDynamicAabbTree *v5; // rbx
  hkcdDynamicAabbTree *m_pntr; // rcx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  if ( v3 )
  {
    hkcdDynamicAabbTree::hkcdDynamicAabbTree(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  m_pntr = this->m_tree.m_pntr;
  if ( m_pntr && m_pntr != v5 )
    hkReferencedObject::removeReference(m_pntr);
  this->m_tree.m_pntr = v5;
}

// File Line: 749
// RVA: 0xBBC4C0
void __fastcall hkaiStreamingCollection::addTreeNode(
        hkaiStreamingCollection *this,
        int sectionIdx,
        hkAabb *instanceAabb)
{
  __int64 v4; // rdi

  v4 = sectionIdx;
  if ( !this->m_tree.m_pntr )
    hkaiStreamingCollection::setupTree(this);
  this->m_instances.m_data[v4].m_treeNode = hkcdDynamicAabbTree::insert(this->m_tree.m_pntr, instanceAabb, v4);
}

// File Line: 763
// RVA: 0xBBC130
void __fastcall hkaiStreamingCollection::setSectionTransform(
        hkaiStreamingCollection *this,
        hkaiNavMeshInstance *meshInstance,
        hkTransformf *transform)
{
  hkaiStreamingCollection::setSectionTransform(this, meshInstance->m_runtimeId, transform);
}

// File Line: 768
// RVA: 0xBBC260
void __fastcall hkaiStreamingCollection::setVolumeTranslation(
        hkaiStreamingCollection *this,
        hkaiNavVolumeInstance *meshInstance,
        hkVector4f *translation)
{
  int m_runtimeId; // edx
  hkTransformf transform; // [rsp+20h] [rbp-48h] BYREF

  m_runtimeId = meshInstance->m_runtimeId;
  transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
  transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  transform.m_translation = (hkVector4f)translation->m_quad;
  hkaiStreamingCollection::setSectionTransform(this, m_runtimeId, &transform);
}

// File Line: 775
// RVA: 0xBBC150
void __fastcall hkaiStreamingCollection::setSectionTransform(
        hkaiStreamingCollection *this,
        int sectionIdx,
        hkTransformf *transform)
{
  char v4; // si
  hkaiStreamingCollection::InstanceInfo *v6; // rbx
  hkaiNavMeshInstance *m_instancePtr; // rcx
  hkVector4f *m_clusterGraphInstance; // rax
  __m128 *m_volumeInstancePtr; // rcx
  __m128 *v10; // rax
  hkVector4f v11; // xmm1
  __m128 v12; // xmm0
  hkcdDynamicAabbTree *m_pntr; // rcx
  hkAabb aabbOut; // [rsp+20h] [rbp-28h] BYREF

  v4 = 0;
  v6 = &this->m_instances.m_data[sectionIdx];
  m_instancePtr = v6->m_instancePtr;
  if ( v6->m_instancePtr )
  {
    v4 = 1;
    m_instancePtr->m_referenceFrame.m_transform = *transform;
    hkaiNavMeshInstance::getAabb(m_instancePtr, &aabbOut);
  }
  m_clusterGraphInstance = (hkVector4f *)v6->m_clusterGraphInstance;
  if ( m_clusterGraphInstance )
  {
    m_clusterGraphInstance[13] = transform->m_rotation.m_col0;
    m_clusterGraphInstance[14] = transform->m_rotation.m_col1;
    m_clusterGraphInstance[15] = transform->m_rotation.m_col2;
    m_clusterGraphInstance[16] = transform->m_translation;
  }
  m_volumeInstancePtr = (__m128 *)v6->m_volumeInstancePtr;
  if ( m_volumeInstancePtr )
  {
    v10 = (__m128 *)m_volumeInstancePtr[3].m128_u64[0];
    v11.m_quad = (__m128)transform->m_translation;
    v4 = 1;
    m_volumeInstancePtr[7] = v11.m_quad;
    v12 = v10[5];
    aabbOut.m_min.m_quad = _mm_add_ps(v11.m_quad, v10[4]);
    aabbOut.m_max.m_quad = _mm_add_ps(v12, m_volumeInstancePtr[7]);
  }
  m_pntr = this->m_tree.m_pntr;
  if ( m_pntr )
  {
    if ( v4 )
      hkcdDynamicAabbTree::update(m_pntr, v6->m_treeNode, &aabbOut);
  }
}

// File Line: 809
// RVA: 0xBBC330
bool __fastcall hkaiStreamingCollection::areKeysConsistent(
        hkaiStreamingCollection *this,
        unsigned int faceKey,
        unsigned int edgeKey)
{
  __int64 v4; // r8
  hkaiNavMeshInstance *m_instancePtr; // rcx
  bool result; // al
  int m_numOriginalFaces; // r10d
  int index; // edx
  signed int v9; // r11d
  hkaiNavMesh::Face *v10; // rax
  int v11; // r11d
  int m_startUserEdgeIndex; // ecx

  v4 = faceKey >> 22;
  if ( (_DWORD)v4 != edgeKey >> 22 )
    return 0;
  m_instancePtr = this->m_instances.m_data[v4].m_instancePtr;
  if ( !m_instancePtr )
    return 1;
  m_numOriginalFaces = m_instancePtr->m_numOriginalFaces;
  index = faceKey & 0x3FFFFF;
  v9 = edgeKey & 0x3FFFFF;
  if ( index >= m_numOriginalFaces + m_instancePtr->m_ownedFaces.m_size
    || v9 >= m_instancePtr->m_numOriginalEdges + m_instancePtr->m_ownedEdges.m_size )
  {
    return 0;
  }
  v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__1(
          m_instancePtr->m_originalFaces,
          m_numOriginalFaces,
          &m_instancePtr->m_instancedFaces,
          &m_instancePtr->m_ownedFaces,
          &m_instancePtr->m_faceMap,
          index);
  result = 1;
  if ( v11 < v10->m_startEdgeIndex || v11 >= v10->m_startEdgeIndex + v10->m_numEdges )
  {
    m_startUserEdgeIndex = v10->m_startUserEdgeIndex;
    if ( v11 < m_startUserEdgeIndex || v11 >= m_startUserEdgeIndex + v10->m_numUserEdges )
      return 0;
  }
  return result;
}

