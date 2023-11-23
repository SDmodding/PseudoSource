// File Line: 32
// RVA: 0xC3EA10
void __fastcall hkaiSilhouetteRecorder::navMeshInstanceAdded(
        hkaiSilhouetteRecorder *this,
        hkaiWorld *world,
        hkaiNavMeshInstance *instance,
        hkaiNavMeshQueryMediator *mediator,
        hkaiDirectedGraphInstance *hierarchyGraph)
{
  hkaiWorld::ListenerVtbl *vfptr; // rax
  hkaiSilhouetteRecorder::InstanceLoadedEvent v9; // [rsp+20h] [rbp-38h] BYREF

  hkaiSilhouetteRecorder::connectWorld(this, world);
  hkaiSilhouetteRecorder::InstanceLoadedEvent::InstanceLoadedEvent(&v9);
  if ( instance )
    hkReferencedObject::addReference(instance);
  if ( v9.m_instance.m_pntr )
    hkReferencedObject::removeReference(v9.m_instance.m_pntr);
  v9.m_instance.m_pntr = instance;
  if ( mediator )
    hkReferencedObject::addReference(mediator);
  if ( v9.m_mediator.m_pntr )
    hkReferencedObject::removeReference(v9.m_mediator.m_pntr);
  v9.m_mediator.m_pntr = mediator;
  if ( hierarchyGraph )
    hkReferencedObject::addReference(hierarchyGraph);
  if ( v9.m_graph.m_pntr )
    hkReferencedObject::removeReference(v9.m_graph.m_pntr);
  vfptr = this->vfptr;
  v9.m_graph.m_pntr = hierarchyGraph;
  vfptr[1].postCharacterStepCallback(this, (hkaiWorld::CharacterStepCallbackContext *)&v9);
  hkaiSilhouetteRecorder::InstanceLoadedEvent::~InstanceLoadedEvent(&v9);
}

// File Line: 44
// RVA: 0xC3EAE0
void __fastcall hkaiSilhouetteRecorder::navMeshInstanceRemoved(
        hkaiSilhouetteRecorder *this,
        hkaiWorld *world,
        hkaiNavMeshInstance *instance,
        hkaiDirectedGraphInstance *hierarchyGraph)
{
  unsigned int m_sectionUid; // eax
  hkaiWorld::ListenerVtbl *vfptr; // rax
  void **v8; // [rsp+20h] [rbp-28h] BYREF
  int v9; // [rsp+28h] [rbp-20h]
  char v10; // [rsp+30h] [rbp-18h]
  unsigned int v11; // [rsp+38h] [rbp-10h]

  hkaiSilhouetteRecorder::connectWorld(this, world);
  v8 = &hkaiSilhouetteRecorder::InstanceUnloadedEvent::`vftable;
  m_sectionUid = instance->m_sectionUid;
  v9 = 0x1FFFF;
  v11 = m_sectionUid;
  vfptr = this->vfptr;
  v10 = 2;
  vfptr[1].postCharacterStepCallback(this, (hkaiWorld::CharacterStepCallbackContext *)&v8);
}

// File Line: 53
// RVA: 0xC3ED10
void __fastcall hkaiSilhouetteRecorder::preSilhouetteStepCallback(
        hkaiSilhouetteRecorder *this,
        hkaiWorld *world,
        unsigned int threading,
        hkBitField *sectionsToStep)
{
  __int64 m_size; // r12
  int v7; // ebx
  int v8; // r13d
  int v9; // r9d
  int v10; // edi
  hkRefPtr<hkaiSilhouetteGenerator> *v11; // rsi
  __int64 v12; // rbx
  hkReferencedObject *m_pntr; // rcx
  hkRefPtr<hkaiSilhouetteGenerator> *m_data; // r14
  hkRefPtr<hkaiSilhouetteGenerator> *v15; // r15
  __int64 i; // rbx
  hkReferencedObject *v17; // rcx
  hkReferencedObject *v18; // rcx
  hkaiSilhouetteGenerator *v19; // rax
  hkRefPtr<hkaiSilhouetteGenerator> *v20; // rbx
  __int64 v21; // r14
  char *v22; // r15
  hkaiWorld *v23; // rax
  hkArray<hkaiOverlapManagerSection,hkContainerHeapAllocator> *p_m_sections; // rbx
  __int64 v25; // r10
  int v26; // r8d
  hkaiOverlapManagerSection *v27; // r9
  hkaiOverlapManagerSection *v28; // rax
  _QWORD *v29; // r14
  __int64 v30; // r13
  int v31; // r12d
  _DWORD *v32; // r15
  int v33; // ebx
  int v34; // eax
  int v35; // eax
  int v36; // r9d
  __int64 v37; // rsi
  __int64 v38; // rbx
  hkReferencedObject *v39; // rcx
  hkReferencedObject **v40; // rbx
  __int64 v41; // r14
  __int64 v42; // r14
  __int64 v43; // rsi
  hkReferencedObject *v44; // rcx
  hkReferencedObject *v45; // rax
  hkReferencedObject **v46; // rbx
  __int64 v47; // r14
  __int64 v48; // r15
  __int64 m_enum; // rsi
  hkaiStreamingCollection *v50; // r15
  int v51; // esi
  int v52; // ecx
  __int64 v53; // r14
  __m128 *m_instancePtr; // rbx
  int v55; // eax
  hkTransformf *v56; // rax
  __m128 m_quad; // xmm1
  __int64 v58; // rbx
  __int64 v59; // [rsp+30h] [rbp-89h]
  hkaiSilhouetteRecorder::SilhouettesSteppedEvent array; // [rsp+40h] [rbp-79h] BYREF
  _DWORD *v61; // [rsp+B0h] [rbp-9h]
  _QWORD *v62; // [rsp+B8h] [rbp-1h]
  hkArray<hkaiOverlapManagerSection,hkContainerHeapAllocator> *v63; // [rsp+C0h] [rbp+7h]
  hkResult result; // [rsp+130h] [rbp+77h] BYREF
  hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > *__that; // [rsp+138h] [rbp+7Fh] BYREF

  __that = &sectionsToStep->m_storage;
  hkaiSilhouetteRecorder::connectWorld(this, world);
  hkaiSilhouetteRecorder::SilhouettesSteppedEvent::SilhouettesSteppedEvent(&array);
  m_size = world->m_silhouetteGenerators.m_size;
  array.m_stepThreading.m_storage = threading;
  v7 = array.m_generators.m_size;
  v8 = m_size;
  if ( (int)m_size > array.m_generators.m_size )
    v8 = array.m_generators.m_size;
  if ( (array.m_generators.m_capacityAndFlags & 0x3FFFFFFF) < (int)m_size )
  {
    v9 = m_size;
    if ( (int)m_size < 2 * (array.m_generators.m_capacityAndFlags & 0x3FFFFFFF) )
      v9 = 2 * (array.m_generators.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_generators, v9, 8);
  }
  v10 = 0;
  v11 = &array.m_generators.m_data[m_size];
  v12 = v7 - (int)m_size - 1;
  if ( (int)v12 >= 0 )
  {
    do
    {
      m_pntr = v11[v12].m_pntr;
      if ( m_pntr )
        hkReferencedObject::removeReference(m_pntr);
      v11[v12--].m_pntr = 0i64;
    }
    while ( v12 >= 0 );
  }
  m_data = world->m_silhouetteGenerators.m_data;
  v15 = array.m_generators.m_data;
  for ( i = 0i64; i < v8; v15[i - 1].m_pntr = v19 )
  {
    v17 = m_data[i].m_pntr;
    if ( v17 )
      hkReferencedObject::addReference(v17);
    v18 = v15[i].m_pntr;
    if ( v18 )
      hkReferencedObject::removeReference(v18);
    v19 = m_data[i++].m_pntr;
  }
  v20 = &world->m_silhouetteGenerators.m_data[v8];
  v21 = (int)m_size - v8;
  if ( (int)m_size - v8 > 0 )
  {
    v22 = (char *)((char *)&array.m_generators.m_data[v8] - (char *)v20);
    do
    {
      if ( (hkRefPtr<hkaiSilhouetteGenerator> *)((char *)v20 + (_QWORD)v22) )
      {
        if ( v20->m_pntr )
          hkReferencedObject::addReference(v20->m_pntr);
        *(hkRefPtr<hkaiSilhouetteGenerator> *)((char *)v20 + (_QWORD)v22) = (hkRefPtr<hkaiSilhouetteGenerator>)v20->m_pntr;
      }
      ++v20;
      --v21;
    }
    while ( v21 );
  }
  array.m_generators.m_size = m_size;
  if ( __that )
    hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>::operator=(
      &array.m_updatedSections.m_storage,
      __that);
  v23 = world;
  result.m_enum = HK_SUCCESS;
  p_m_sections = &world->m_overlapManager.m_pntr->m_sections;
  v63 = p_m_sections;
  if ( p_m_sections->m_size > 0 )
  {
    v25 = 0i64;
    v59 = 0i64;
    do
    {
      v26 = array.m_overlapManagerSections.m_size;
      if ( array.m_overlapManagerSections.m_size == (array.m_overlapManagerSections.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array.m_overlapManagerSections, 72);
        v26 = array.m_overlapManagerSections.m_size;
        v25 = v59;
      }
      v27 = array.m_overlapManagerSections.m_data;
      v28 = &array.m_overlapManagerSections.m_data[v26];
      if ( v28 )
      {
        v28->m_generatorDataMap = 0i64;
        v28->m_numOriginalFaces = 0;
        v28->m_generatorData.m_data = 0i64;
        v28->m_generatorData.m_size = 0;
        v28->m_generatorData.m_capacityAndFlags = 0x80000000;
        v28->m_faceToGeneratorsMap.m_data = 0i64;
        v28->m_faceToGeneratorsMap.m_size = 0;
        v28->m_faceToGeneratorsMap.m_capacityAndFlags = 0x80000000;
        v28->m_facePriorities.m_elem.m_data = 0i64;
        v28->m_facePriorities.m_elem.m_size = 0;
        v28->m_facePriorities.m_elem.m_capacityAndFlags = 0x80000000;
        v28->m_facePriorities.m_numElems = 0;
        v26 = array.m_overlapManagerSections.m_size;
        v27 = array.m_overlapManagerSections.m_data;
      }
      array.m_overlapManagerSections.m_size = v26 + 1;
      v27[array.m_overlapManagerSections.m_size - 1].m_numOriginalFaces = *(int *)((char *)&p_m_sections->m_data->m_numOriginalFaces
                                                                                 + v25);
      v29 = (hkRefPtr<hkaiOverlapManagerSection::GeneratorData> **)((char *)&p_m_sections->m_data->m_generatorData.m_data
                                                                  + v25);
      v30 = *((int *)v29 + 2);
      v31 = v30;
      v62 = v29;
      v32 = (_DWORD *)&array.m_overlapManagerSections.m_data[-1].m_generatorData
          + 16 * array.m_overlapManagerSections.m_size
          + 2 * array.m_overlapManagerSections.m_size;
      v61 = v32;
      v33 = v32[2];
      if ( (int)v30 > v33 )
        v31 = v32[2];
      v34 = v32[3] & 0x3FFFFFFF;
      if ( v34 >= (int)v30 )
      {
        LODWORD(__that) = 0;
      }
      else
      {
        v35 = 2 * v34;
        v36 = v30;
        if ( (int)v30 < v35 )
          v36 = v35;
        hkArrayUtil::_reserve((hkResult *)&__that, &hkContainerHeapAllocator::s_alloc, v32, v36, 8);
      }
      v37 = *(_QWORD *)v32 + 8 * v30;
      v38 = v33 - (int)v30 - 1;
      if ( (int)v38 >= 0 )
      {
        do
        {
          v39 = *(hkReferencedObject **)(v37 + 8 * v38);
          if ( v39 )
            hkReferencedObject::removeReference(v39);
          *(_QWORD *)(v37 + 8 * v38--) = 0i64;
        }
        while ( v38 >= 0 );
      }
      v40 = *(hkReferencedObject ***)v32;
      v41 = *v29;
      if ( v31 > 0 )
      {
        v42 = v41 - (_QWORD)v40;
        v43 = v31;
        do
        {
          v44 = *(hkReferencedObject **)((char *)v40 + v42);
          if ( v44 )
            hkReferencedObject::addReference(v44);
          if ( *v40 )
            hkReferencedObject::removeReference(*v40);
          v45 = *(hkReferencedObject **)((char *)v40++ + v42);
          *(v40 - 1) = v45;
          --v43;
        }
        while ( v43 );
      }
      v46 = (hkReferencedObject **)(*v62 + 8i64 * v31);
      v47 = (int)v30 - v31;
      if ( (int)v30 - v31 > 0 )
      {
        v48 = *(_QWORD *)v61 + 8i64 * v31 - (_QWORD)v46;
        do
        {
          if ( (hkReferencedObject **)((char *)v46 + v48) )
          {
            if ( *v46 )
              hkReferencedObject::addReference(*v46);
            *(hkReferencedObject **)((char *)v46 + v48) = *v46;
          }
          ++v46;
          --v47;
        }
        while ( v47 );
      }
      m_enum = result.m_enum;
      p_m_sections = v63;
      v61[2] = v30;
      hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::operator=(
        &array.m_overlapManagerSections.m_data[array.m_overlapManagerSections.m_size - 1].m_facePriorities,
        (hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *)((char *)&p_m_sections->m_data->m_facePriorities
                                                                                        + 64 * m_enum
                                                                                        + 8 * m_enum));
      v25 = v59 + 72;
      result.m_enum = m_enum + 1;
      v59 += 72i64;
    }
    while ( (int)m_enum + 1 < p_m_sections->m_size );
    v23 = world;
  }
  v50 = v23->m_streamingCollection.m_pntr;
  v51 = 0;
  if ( v50->m_instances.m_size > 0 )
  {
    v52 = array.m_instanceTransforms.m_size;
    v53 = 0i64;
    do
    {
      m_instancePtr = (__m128 *)v50->m_instances.m_data[v53].m_instancePtr;
      v55 = array.m_instanceTransforms.m_capacityAndFlags & 0x3FFFFFFF;
      if ( m_instancePtr )
      {
        if ( v52 == v55 )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array.m_instanceTransforms, 64);
          v52 = array.m_instanceTransforms.m_size;
        }
        v56 = &array.m_instanceTransforms.m_data[(__int64)v52];
        v56->m_rotation.m_col0.m_quad = m_instancePtr[7];
        v56->m_rotation.m_col1.m_quad = m_instancePtr[8];
        v56->m_rotation.m_col2.m_quad = m_instancePtr[9];
        m_quad = m_instancePtr[10];
      }
      else
      {
        if ( v52 == v55 )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array.m_instanceTransforms, 64);
          v52 = array.m_instanceTransforms.m_size;
        }
        v56 = &array.m_instanceTransforms.m_data[(__int64)v52];
        v56->m_rotation.m_col0 = (hkVector4f)transform.m_quad;
        v56->m_rotation.m_col1 = (hkVector4f)direction.m_quad;
        v56->m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
        m_quad = qi.m_vec.m_quad;
      }
      v56->m_translation.m_quad = m_quad;
      ++v51;
      v52 = array.m_instanceTransforms.m_size + 1;
      ++v53;
      ++array.m_instanceTransforms.m_size;
    }
    while ( v51 < v50->m_instances.m_size );
  }
  if ( array.m_generators.m_size > 0 )
  {
    v58 = 0i64;
    do
    {
      array.m_generators.m_data[v58].m_pntr->vfptr[6].__first_virtual_table_function__(array.m_generators.m_data[v58].m_pntr);
      ++v10;
      ++v58;
    }
    while ( v10 < array.m_generators.m_size );
  }
  this->vfptr[1].postCharacterStepCallback(this, (hkaiWorld::CharacterStepCallbackContext *)&array);
  hkaiSilhouetteRecorder::SilhouettesSteppedEvent::~SilhouettesSteppedEvent(&array);
}

// File Line: 101
// RVA: 0xC3EB40
void __fastcall hkaiSilhouetteRecorder::navVolumeAdded(
        hkaiSilhouetteRecorder *this,
        hkaiWorld *world,
        hkaiNavVolumeInstance *volume,
        hkaiNavVolumeMediator *mediator)
{
  hkaiWorld::ListenerVtbl *vfptr; // rax
  hkaiSilhouetteRecorder::VolumeLoadedEvent v8; // [rsp+20h] [rbp-38h] BYREF

  hkaiSilhouetteRecorder::connectWorld(this, world);
  hkaiSilhouetteRecorder::VolumeLoadedEvent::VolumeLoadedEvent(&v8);
  if ( volume )
    hkReferencedObject::addReference(volume);
  if ( v8.m_volume.m_pntr )
    hkReferencedObject::removeReference(v8.m_volume.m_pntr);
  v8.m_volume.m_pntr = volume;
  if ( mediator )
    hkReferencedObject::addReference(mediator);
  if ( v8.m_mediator.m_pntr )
    hkReferencedObject::removeReference(v8.m_mediator.m_pntr);
  vfptr = this->vfptr;
  v8.m_mediator.m_pntr = mediator;
  vfptr[1].postCharacterStepCallback(this, (hkaiWorld::CharacterStepCallbackContext *)&v8);
  hkaiSilhouetteRecorder::VolumeLoadedEvent::~VolumeLoadedEvent(&v8);
}

// File Line: 112
// RVA: 0xC3EBE0
void __fastcall hkaiSilhouetteRecorder::navVolumeRemoved(
        hkaiSilhouetteRecorder *this,
        hkaiWorld *world,
        hkaiNavVolumeInstance *volume)
{
  unsigned int m_sectionUid; // eax
  hkaiWorld::ListenerVtbl *vfptr; // rax
  void **v7; // [rsp+20h] [rbp-28h] BYREF
  int v8; // [rsp+28h] [rbp-20h]
  char v9; // [rsp+30h] [rbp-18h]
  unsigned int v10; // [rsp+38h] [rbp-10h]

  hkaiSilhouetteRecorder::connectWorld(this, world);
  v7 = &hkaiSilhouetteRecorder::VolumeUnloadedEvent::`vftable;
  m_sectionUid = volume->m_sectionUid;
  v8 = 0x1FFFF;
  v10 = m_sectionUid;
  vfptr = this->vfptr;
  v9 = 5;
  vfptr[1].postCharacterStepCallback(this, (hkaiWorld::CharacterStepCallbackContext *)&v7);
}

// File Line: 121
// RVA: 0xC3EC40
void __fastcall hkaiSilhouetteRecorder::graphAdded(
        hkaiSilhouetteRecorder *this,
        hkaiWorld *world,
        hkaiDirectedGraphInstance *graph)
{
  hkaiWorld::ListenerVtbl *vfptr; // rax
  hkaiSilhouetteRecorder::GraphLoadedEvent v6; // [rsp+20h] [rbp-28h] BYREF

  hkaiSilhouetteRecorder::connectWorld(this, world);
  hkaiSilhouetteRecorder::GraphLoadedEvent::GraphLoadedEvent(&v6);
  if ( graph )
    hkReferencedObject::addReference(graph);
  if ( v6.m_graph.m_pntr )
    hkReferencedObject::removeReference(v6.m_graph.m_pntr);
  vfptr = this->vfptr;
  v6.m_graph.m_pntr = graph;
  vfptr[1].postCharacterStepCallback(this, (hkaiWorld::CharacterStepCallbackContext *)&v6);
  hkaiSilhouetteRecorder::GraphLoadedEvent::~GraphLoadedEvent(&v6);
}

// File Line: 130
// RVA: 0xC3ECB0
void __fastcall hkaiSilhouetteRecorder::graphRemoved(
        hkaiSilhouetteRecorder *this,
        hkaiWorld *world,
        hkaiDirectedGraphInstance *graph)
{
  unsigned int m_sectionUid; // eax
  hkaiWorld::ListenerVtbl *vfptr; // rax
  void **v7; // [rsp+20h] [rbp-28h] BYREF
  int v8; // [rsp+28h] [rbp-20h]
  char v9; // [rsp+30h] [rbp-18h]
  unsigned int v10; // [rsp+38h] [rbp-10h]

  hkaiSilhouetteRecorder::connectWorld(this, world);
  v7 = &hkaiSilhouetteRecorder::GraphUnloadedEvent::`vftable;
  m_sectionUid = graph->m_sectionUid;
  v8 = 0x1FFFF;
  v10 = m_sectionUid;
  vfptr = this->vfptr;
  v9 = 7;
  vfptr[1].postCharacterStepCallback(this, (hkaiWorld::CharacterStepCallbackContext *)&v7);
}

// File Line: 140
// RVA: 0xC3F210
void __fastcall hkaiSilhouetteRecorder::connectWorld(hkaiSilhouetteRecorder *this, hkaiWorld *world)
{
  hkaiWorld::ListenerVtbl *vfptr; // rax
  hkaiSilhouetteRecorder::WorldConnectedEvent v5; // [rsp+20h] [rbp-28h] BYREF

  if ( !((unsigned __int8 (__fastcall *)(hkaiSilhouetteRecorder *))this->vfptr[1].__vecDelDtor)(this) )
  {
    (*(void (__fastcall **)(hkaiSilhouetteRecorder *, hkaiWorld *))this->vfptr[1].gap8)(this, world);
    hkaiSilhouetteRecorder::WorldConnectedEvent::WorldConnectedEvent(&v5);
    if ( world )
      hkReferencedObject::addReference(world);
    if ( v5.m_world.m_pntr )
      hkReferencedObject::removeReference(v5.m_world.m_pntr);
    vfptr = this->vfptr;
    v5.m_world.m_pntr = world;
    vfptr[1].postCharacterStepCallback(this, (hkaiWorld::CharacterStepCallbackContext *)&v5);
    hkaiSilhouetteRecorder::WorldConnectedEvent::~WorldConnectedEvent(&v5);
  }
}

// File Line: 159
// RVA: 0xC3E7E0
void __fastcall hkaiSilhouetteRecorder::applyEventToWorld(
        hkaiSilhouetteRecorder::ReplayEvent *e,
        hkRefPtr<hkaiWorld> *world,
        hkJobQueue *jobQueue,
        hkJobThreadPool *threadPool)
{
  hkBaseObjectVtbl *vfptr; // rcx
  hkaiStreamingCollection *m_pntr; // rbx
  int SectionIdByUid; // eax
  hkaiStreamingCollection::InstanceInfo *m_data; // rcx
  hkaiStreamingCollection *v12; // rbp
  int v13; // ebx
  __int64 v14; // r14
  hkaiNavMeshInstance *m_instancePtr; // rdx
  hkaiWorld *v16; // rcx
  int VolumeIdByUid; // eax
  int GraphIdByUid; // eax
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rbx

  switch ( e->m_eventType.m_storage )
  {
    case 0:
      vfptr = e[1].vfptr;
      if ( vfptr )
        hkReferencedObject::addReference((hkReferencedObject *)vfptr);
      if ( world->m_pntr )
        hkReferencedObject::removeReference(world->m_pntr);
      world->m_pntr = (hkaiWorld *)e[1].vfptr;
      break;
    case 1:
      hkaiWorld::loadNavMeshInstance(
        world->m_pntr,
        (hkaiNavMeshInstance *)e[1].vfptr,
        *(hkaiNavMeshQueryMediator **)&e[1].m_memSizeAndFlags,
        *(hkaiDirectedGraphInstance **)&e[1].m_eventType.m_storage);
      break;
    case 2:
      m_pntr = world->m_pntr->m_streamingCollection.m_pntr;
      SectionIdByUid = hkaiStreamingCollection::findSectionIdByUid(m_pntr, (unsigned int)e[1].vfptr);
      m_data = m_pntr->m_instances.m_data;
      if ( SectionIdByUid >= 0 )
        hkaiWorld::unloadNavMeshInstance(
          world->m_pntr,
          m_data[SectionIdByUid].m_instancePtr,
          m_data[SectionIdByUid].m_clusterGraphInstance);
      else
        hkaiWorld::unloadNavMeshInstance(world->m_pntr, m_data[SectionIdByUid].m_instancePtr, 0i64);
      break;
    case 3:
      hkaiWorld::forceSilhouetteInformation(
        world->m_pntr,
        (hkArray<hkRefPtr<hkaiSilhouetteGenerator>,hkContainerHeapAllocator> *)&e[1].m_memSizeAndFlags,
        (hkArray<hkaiOverlapManagerSection,hkContainerHeapAllocator> *)&e[2].m_eventType);
      v12 = world->m_pntr->m_streamingCollection.m_pntr;
      v13 = 0;
      if ( *(int *)&e[2].m_memSizeAndFlags > 0 )
      {
        v14 = 0i64;
        do
        {
          m_instancePtr = v12->m_instances.m_data[v14].m_instancePtr;
          if ( m_instancePtr )
            hkaiStreamingCollection::setSectionTransform(
              v12,
              m_instancePtr,
              (hkTransformf *)&e[2].vfptr[4 * (__int64)v13]);
          ++v13;
          ++v14;
        }
        while ( v13 < *(_DWORD *)&e[2].m_memSizeAndFlags );
      }
      v16 = world->m_pntr;
      if ( LODWORD(e[1].vfptr) )
        hkaiWorld::stepSilhouettesMT(v16, (hkBitField *)&e[3].m_memSizeAndFlags, jobQueue, threadPool);
      else
        hkaiWorld::stepSilhouettes(v16, 0i64);
      break;
    case 4:
      hkaiWorld::loadNavVolume(
        world->m_pntr,
        (hkaiNavVolumeInstance *)e[1].vfptr,
        *(hkaiNavVolumeMediator **)&e[1].m_memSizeAndFlags);
      break;
    case 5:
      VolumeIdByUid = hkaiStreamingCollection::findVolumeIdByUid(
                        world->m_pntr->m_streamingCollection.m_pntr,
                        (unsigned int)e[1].vfptr);
      hkaiWorld::unloadNavVolume(
        world->m_pntr,
        world->m_pntr->m_streamingCollection.m_pntr->m_instances.m_data[VolumeIdByUid].m_volumeInstancePtr);
      break;
    case 6:
      hkaiWorld::loadNavMeshGraph(world->m_pntr, (hkaiDirectedGraphInstance *)e[1].vfptr);
      break;
    case 7:
      GraphIdByUid = hkaiStreamingCollection::findGraphIdByUid(
                       world->m_pntr->m_streamingCollection.m_pntr,
                       (unsigned int)e[1].vfptr);
      if ( GraphIdByUid >= 0 )
        m_clusterGraphInstance = world->m_pntr->m_streamingCollection.m_pntr->m_instances.m_data[GraphIdByUid].m_clusterGraphInstance;
      else
        m_clusterGraphInstance = 0i64;
      hkaiWorld::unloadNavMeshGraph(world->m_pntr, m_clusterGraphInstance);
      break;
    default:
      return;
  }
}loadNavMeshGraph(world->m_pntr, m_clusterGraphInstance);
   

// File Line: 265
// RVA: 0xC3F4C0
void __fastcall hkaiSilhouetteReplayViewer::hkaiSilhouetteReplayViewer(
        hkaiSilhouetteReplayViewer *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiViewerBase::hkaiViewerBase(this, contexts);
  this->hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteReplayViewer::`vftable{for `hkReferencedObject};
  this->hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiSilhouetteReplayViewer::`vftable{for `hkProcess};
  this->hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiSilhouetteReplayViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiSilhouetteRecorder::hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiSilhouetteReplayViewer::`vftable;
  this->m_worldSent.m_bool = 0;
}

// File Line: 269
// RVA: 0xC3F510
void __fastcall hkaiSilhouetteReplayViewer::~hkaiSilhouetteReplayViewer(hkaiSilhouetteReplayViewer *this)
{
  int v1; // edi
  __int64 v3; // rsi
  hkaiViewerContext *m_pntr; // rdx

  v1 = 0;
  this->hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteReplayViewer::`vftable{for `hkReferencedObject};
  this->hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiSilhouetteReplayViewer::`vftable{for `hkProcess};
  this->hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiSilhouetteReplayViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiSilhouetteRecorder::hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiSilhouetteReplayViewer::`vftable;
  if ( this->m_context.m_pntr )
  {
    v3 = 0i64;
    do
    {
      m_pntr = this->m_context.m_pntr;
      if ( v1 >= m_pntr->m_worlds.m_size )
        break;
      hkaiSilhouetteReplayViewer::worldRemovedCallback(
        (hkaiSilhouetteReplayViewer *)&this->hkaiViewerContextWorldListener,
        m_pntr->m_worlds.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( this->m_context.m_pntr );
  }
  this->hkaiSilhouetteRecorder::hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable;
  hkaiViewerBase::~hkaiViewerBase(this);
}

// File Line: 277
// RVA: 0xC3F320
void __fastcall hkaiSilhouetteReplayViewer::init(hkaiSilhouetteReplayViewer *this)
{
  hkProcessHandler *m_processHandler; // rax
  int v2; // ebx
  __int64 v4; // rdi

  m_processHandler = this->m_processHandler;
  v2 = 0;
  if ( m_processHandler )
  {
    v4 = 0i64;
    do
    {
      if ( v2 >= SLODWORD(m_processHandler[22].vfptr) )
        break;
      ((void (__fastcall *)(hkDebugDisplayHandler **, _QWORD))this->m_displayHandler[1].vfptr)(
        &this->m_displayHandler,
        *(void *(__fastcall **)(hkProcessHandler *, unsigned int))((char *)&m_processHandler[21].vfptr->__vecDelDtor + v4));
      m_processHandler = this->m_processHandler;
      ++v2;
      v4 += 8i64;
    }
    while ( m_processHandler );
  }
}

// File Line: 285
// RVA: 0xC3F390
void __fastcall hkaiSilhouetteReplayViewer::worldAddedCallback(hkaiSilhouetteReplayViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiSilhouetteReplayViewer *)64 )
    hkaiWorld::addListener(w, 0i64);
  else
    hkaiWorld::addListener(w, (hkaiWorld::Listener *)&this->hkProcess);
}

// File Line: 290
// RVA: 0xC3F3C0
void __fastcall hkaiSilhouetteReplayViewer::worldRemovedCallback(hkaiSilhouetteReplayViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiSilhouetteReplayViewer *)64 )
    hkaiWorld::removeListener(w, 0i64);
  else
    hkaiWorld::removeListener(w, (hkaiWorld::Listener *)&this->hkProcess);
}

// File Line: 298
// RVA: 0xC3F290
void hkaiSilhouetteReplayViewer::registerViewer(void)
{
  hkaiSilhouetteReplayViewer::m_tag = hkProcessFactory::registerProcess(
                                        hkSingleton<hkProcessFactory>::s_instance,
                                        "AI - Silhouette Replay",
                                        hkaiSilhouetteReplayViewer::create);
}

// File Line: 303
// RVA: 0xC3F2C0
hkProcess *__fastcall hkaiSilhouetteReplayViewer::create(
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkaiSilhouetteReplayViewer *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiSilhouetteReplayViewer *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                       Value[11],
                                       96i64);
  if ( v3 && (hkaiSilhouetteReplayViewer::hkaiSilhouetteReplayViewer(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
}

// File Line: 308
// RVA: 0xC3F3F0
_BOOL8 __fastcall hkaiSilhouetteReplayViewer::isWorldInfoSent(hkaiSilhouetteReplayViewer *this, hkaiWorld *world)
{
  return LOBYTE(this->m_memSizeAndFlags) != 0;
}

// File Line: 313
// RVA: 0xC3F400
void __fastcall hkaiSilhouetteReplayViewer::sentWorldInfo(hkaiSilhouetteReplayViewer *this, hkaiWorld *world)
{
  LOBYTE(this->m_memSizeAndFlags) = 1;
}

// File Line: 318
// RVA: 0xC3F410
void __fastcall hkaiSilhouetteReplayViewer::sendEvent(
        hkaiSilhouetteReplayViewer *this,
        hkaiSilhouetteRecorder::ReplayEvent *e)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TthkaiSilhouetteReplayViewer::sendEvent";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  hkRemoteObjectProcess::sendObject((hkDisplaySerializeOStream *)this[-1].m_processHandler, e, SEND_OBJECT_TAGFILE);
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "Et";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    v8[1] = v11;
  }
}

// File Line: 328
// RVA: 0xC3E3E0
void __fastcall hkaiSilhouetteRecorder::InstanceLoadedEvent::InstanceLoadedEvent(
        hkaiSilhouetteRecorder::InstanceLoadedEvent *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_eventType.m_storage = 1;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::InstanceLoadedEvent::`vftable;
  this->m_instance.m_pntr = 0i64;
  this->m_mediator.m_pntr = 0i64;
  this->m_graph.m_pntr = 0i64;
}

// File Line: 335
// RVA: 0xC3E410
void __fastcall hkaiSilhouetteRecorder::InstanceLoadedEvent::InstanceLoadedEvent(
        hkaiSilhouetteRecorder::InstanceLoadedEvent *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::InstanceLoadedEvent::`vftable;
}

// File Line: 339
// RVA: 0xC3E430
void __fastcall hkaiSilhouetteRecorder::InstanceLoadedEvent::~InstanceLoadedEvent(
        hkaiSilhouetteRecorder::InstanceLoadedEvent *this)
{
  hkaiDirectedGraphInstance *m_pntr; // rcx
  hkaiNavMeshQueryMediator *v3; // rcx
  hkaiNavMeshInstance *v4; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::InstanceLoadedEvent::`vftable;
  m_pntr = this->m_graph.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_graph.m_pntr = 0i64;
  v3 = this->m_mediator.m_pntr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  this->m_mediator.m_pntr = 0i64;
  v4 = this->m_instance.m_pntr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  this->m_instance.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 345
// RVA: 0xC3E4A0
void __fastcall hkaiSilhouetteRecorder::SilhouettesSteppedEvent::SilhouettesSteppedEvent(
        hkaiSilhouetteRecorder::SilhouettesSteppedEvent *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_eventType.m_storage = 3;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::SilhouettesSteppedEvent::`vftable;
  this->m_generators.m_capacityAndFlags = 0x80000000;
  this->m_generators.m_data = 0i64;
  this->m_generators.m_size = 0;
  this->m_instanceTransforms.m_data = 0i64;
  this->m_instanceTransforms.m_size = 0;
  this->m_instanceTransforms.m_capacityAndFlags = 0x80000000;
  this->m_overlapManagerSections.m_data = 0i64;
  this->m_overlapManagerSections.m_size = 0;
  this->m_overlapManagerSections.m_capacityAndFlags = 0x80000000;
  this->m_updatedSections.m_storage.m_words.m_data = 0i64;
  this->m_updatedSections.m_storage.m_words.m_size = 0;
  this->m_updatedSections.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  this->m_updatedSections.m_storage.m_numBits = 0;
}

// File Line: 353
// RVA: 0xC3E500
void __fastcall hkaiSilhouetteRecorder::SilhouettesSteppedEvent::SilhouettesSteppedEvent(
        hkaiSilhouetteRecorder::SilhouettesSteppedEvent *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::SilhouettesSteppedEvent::`vftable;
}

// File Line: 357
// RVA: 0xC3E520
void __fastcall hkaiSilhouetteRecorder::SilhouettesSteppedEvent::~SilhouettesSteppedEvent(
        hkaiSilhouetteRecorder::SilhouettesSteppedEvent *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // edi
  hkaiOverlapManagerSection *v4; // rsi
  int v5; // eax
  int v6; // r8d
  hkRefPtr<hkaiSilhouetteGenerator> *m_data; // rsi
  int v8; // eax
  __int64 i; // rdi
  hkReferencedObject *m_pntr; // rcx
  int v11; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::SilhouettesSteppedEvent::`vftable;
  m_capacityAndFlags = this->m_updatedSections.m_storage.m_words.m_capacityAndFlags;
  this->m_updatedSections.m_storage.m_words.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_updatedSections.m_storage.m_words.m_data,
      4 * m_capacityAndFlags);
  this->m_updatedSections.m_storage.m_words.m_data = 0i64;
  this->m_updatedSections.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  v3 = this->m_overlapManagerSections.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &this->m_overlapManagerSections.m_data[v3];
    do
    {
      hkaiOverlapManagerSection::~hkaiOverlapManagerSection(v4--);
      --v3;
    }
    while ( v3 >= 0 );
  }
  v5 = this->m_overlapManagerSections.m_capacityAndFlags;
  this->m_overlapManagerSections.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_overlapManagerSections.m_data,
      72 * (v5 & 0x3FFFFFFF));
  this->m_overlapManagerSections.m_data = 0i64;
  this->m_overlapManagerSections.m_capacityAndFlags = 0x80000000;
  v6 = this->m_instanceTransforms.m_capacityAndFlags;
  this->m_instanceTransforms.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_instanceTransforms.m_data,
      v6 << 6);
  this->m_instanceTransforms.m_data = 0i64;
  this->m_instanceTransforms.m_capacityAndFlags = 0x80000000;
  m_data = this->m_generators.m_data;
  v8 = this->m_generators.m_size - 1;
  for ( i = v8; i >= 0; m_data[i--].m_pntr = 0i64 )
  {
    m_pntr = m_data[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  v11 = this->m_generators.m_capacityAndFlags;
  this->m_generators.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_generators.m_data,
      8 * v11);
  this->m_generators.m_data = 0i64;
  this->m_generators.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 363
// RVA: 0xC3E6A0
void __fastcall hkaiSilhouetteRecorder::VolumeLoadedEvent::VolumeLoadedEvent(
        hkaiSilhouetteRecorder::VolumeLoadedEvent *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_eventType.m_storage = 4;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::VolumeLoadedEvent::`vftable;
  this->m_volume.m_pntr = 0i64;
  this->m_mediator.m_pntr = 0i64;
}

// File Line: 370
// RVA: 0xC3E6D0
void __fastcall hkaiSilhouetteRecorder::VolumeLoadedEvent::VolumeLoadedEvent(
        hkaiSilhouetteRecorder::VolumeLoadedEvent *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::VolumeLoadedEvent::`vftable;
}

// File Line: 374
// RVA: 0xC3E6F0
void __fastcall hkaiSilhouetteRecorder::VolumeLoadedEvent::~VolumeLoadedEvent(
        hkaiSilhouetteRecorder::VolumeLoadedEvent *this)
{
  hkaiNavVolumeMediator *m_pntr; // rcx
  hkaiNavVolumeInstance *v3; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::VolumeLoadedEvent::`vftable;
  m_pntr = this->m_mediator.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_mediator.m_pntr = 0i64;
  v3 = this->m_volume.m_pntr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  this->m_volume.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 380
// RVA: 0xC3E750
void __fastcall hkaiSilhouetteRecorder::GraphLoadedEvent::GraphLoadedEvent(
        hkaiSilhouetteRecorder::GraphLoadedEvent *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_eventType.m_storage = 6;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::GraphLoadedEvent::`vftable;
  this->m_graph.m_pntr = 0i64;
}

// File Line: 386
// RVA: 0xC3E780
void __fastcall hkaiSilhouetteRecorder::GraphLoadedEvent::GraphLoadedEvent(
        hkaiSilhouetteRecorder::GraphLoadedEvent *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::GraphLoadedEvent::`vftable;
}

// File Line: 390
// RVA: 0xC3E7A0
void __fastcall hkaiSilhouetteRecorder::GraphLoadedEvent::~GraphLoadedEvent(
        hkaiSilhouetteRecorder::GraphLoadedEvent *this)
{
  hkaiDirectedGraphInstance *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::GraphLoadedEvent::`vftable;
  m_pntr = this->m_graph.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_graph.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 396
// RVA: 0xC3E350
void __fastcall hkaiSilhouetteRecorder::WorldConnectedEvent::WorldConnectedEvent(
        hkaiSilhouetteRecorder::WorldConnectedEvent *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_eventType.m_storage = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::WorldConnectedEvent::`vftable;
  this->m_world.m_pntr = 0i64;
}

// File Line: 401
// RVA: 0xC3E380
void __fastcall hkaiSilhouetteRecorder::WorldConnectedEvent::WorldConnectedEvent(
        hkaiSilhouetteRecorder::WorldConnectedEvent *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::WorldConnectedEvent::`vftable;
}

// File Line: 405
// RVA: 0xC3E3A0
void __fastcall hkaiSilhouetteRecorder::WorldConnectedEvent::~WorldConnectedEvent(
        hkaiSilhouetteRecorder::WorldConnectedEvent *this)
{
  hkaiWorld *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::WorldConnectedEvent::`vftable;
  m_pntr = this->m_world.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_world.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

