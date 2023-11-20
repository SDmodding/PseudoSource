// File Line: 32
// RVA: 0xC3EA10
void __fastcall hkaiSilhouetteRecorder::navMeshInstanceAdded(hkaiSilhouetteRecorder *this, hkaiWorld *world, hkaiNavMeshInstance *instance, hkaiNavMeshQueryMediator *mediator, hkaiDirectedGraphInstance *hierarchyGraph)
{
  hkaiNavMeshQueryMediator *v5; // rbx
  hkaiNavMeshInstance *v6; // rdi
  hkaiSilhouetteRecorder *v7; // rsi
  hkaiWorld::ListenerVtbl *v8; // rax
  hkaiSilhouetteRecorder::InstanceLoadedEvent v9; // [rsp+20h] [rbp-38h]

  v5 = mediator;
  v6 = instance;
  v7 = this;
  hkaiSilhouetteRecorder::connectWorld(this, world);
  hkaiSilhouetteRecorder::InstanceLoadedEvent::InstanceLoadedEvent(&v9);
  if ( v6 )
    hkReferencedObject::addReference((hkReferencedObject *)&v6->vfptr);
  if ( v9.m_instance.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v9.m_instance.m_pntr->vfptr);
  v9.m_instance.m_pntr = v6;
  if ( v5 )
    hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
  if ( v9.m_mediator.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v9.m_mediator.m_pntr->vfptr);
  v9.m_mediator.m_pntr = v5;
  if ( hierarchyGraph )
    hkReferencedObject::addReference((hkReferencedObject *)&hierarchyGraph->vfptr);
  if ( v9.m_graph.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v9.m_graph.m_pntr->vfptr);
  v8 = v7->vfptr;
  v9.m_graph.m_pntr = hierarchyGraph;
  v8[1].postCharacterStepCallback((hkaiWorld::Listener *)&v7->vfptr, (hkaiWorld::CharacterStepCallbackContext *)&v9);
  hkaiSilhouetteRecorder::InstanceLoadedEvent::~InstanceLoadedEvent(&v9);
}

// File Line: 44
// RVA: 0xC3EAE0
void __fastcall hkaiSilhouetteRecorder::navMeshInstanceRemoved(hkaiSilhouetteRecorder *this, hkaiWorld *world, hkaiNavMeshInstance *instance, hkaiDirectedGraphInstance *hierarchyGraph)
{
  hkaiNavMeshInstance *v4; // rbx
  hkaiSilhouetteRecorder *v5; // rdi
  int v6; // eax
  hkaiWorld::ListenerVtbl *v7; // rax
  void **v8; // [rsp+20h] [rbp-28h]
  int v9; // [rsp+28h] [rbp-20h]
  char v10; // [rsp+30h] [rbp-18h]
  int v11; // [rsp+38h] [rbp-10h]

  v4 = instance;
  v5 = this;
  hkaiSilhouetteRecorder::connectWorld(this, world);
  v8 = &hkaiSilhouetteRecorder::InstanceUnloadedEvent::`vftable;
  v6 = v4->m_sectionUid;
  v9 = 0x1FFFF;
  v11 = v6;
  v7 = v5->vfptr;
  v10 = 2;
  v7[1].postCharacterStepCallback((hkaiWorld::Listener *)&v5->vfptr, (hkaiWorld::CharacterStepCallbackContext *)&v8);
}

// File Line: 53
// RVA: 0xC3ED10
void __fastcall hkaiSilhouetteRecorder::preSilhouetteStepCallback(hkaiSilhouetteRecorder *this, hkaiWorld *world, hkaiWorld::StepThreading threading, hkBitField *sectionsToStep)
{
  unsigned int v4; // ebx
  hkaiWorld *v5; // r14
  __int64 v6; // r12
  int v7; // ebx
  int v8; // er13
  int v9; // er9
  int v10; // edi
  hkRefPtr<hkaiSilhouetteGenerator> *v11; // rsi
  __int64 v12; // rbx
  hkReferencedObject *v13; // rcx
  hkRefPtr<hkaiSilhouetteGenerator> *v14; // r14
  hkRefPtr<hkaiSilhouetteGenerator> *v15; // r15
  signed __int64 v16; // rbx
  hkReferencedObject *v17; // rcx
  hkReferencedObject *v18; // rcx
  hkaiSilhouetteGenerator *v19; // rax
  hkReferencedObject **v20; // rbx
  __int64 v21; // r14
  char *v22; // r15
  hkaiWorld *v23; // rax
  signed __int64 v24; // rbx
  signed __int64 v25; // r10
  int v26; // er8
  hkaiOverlapManagerSection *v27; // r9
  hkaiOverlapManagerSection *v28; // rax
  signed __int64 v29; // r14
  __int64 v30; // r13
  int v31; // er12
  hkPointerMap<hkaiSilhouetteGenerator const *,int,hkContainerHeapAllocator> **v32; // r15
  signed int v33; // ebx
  int v34; // eax
  int v35; // eax
  int v36; // er9
  signed __int64 v37; // rsi
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
  signed __int64 v48; // r15
  __int64 v49; // rsi
  hkaiStreamingCollection *v50; // r15
  int v51; // esi
  int v52; // ecx
  __int64 v53; // r14
  __m128 *v54; // rbx
  int v55; // eax
  hkTransformf *v56; // rax
  __m128 v57; // xmm1
  __int64 v58; // rbx
  signed __int64 v59; // [rsp+30h] [rbp-89h]
  hkaiSilhouetteRecorder::SilhouettesSteppedEvent array; // [rsp+40h] [rbp-79h]
  hkPointerMap<hkaiSilhouetteGenerator const *,int,hkContainerHeapAllocator> **v61; // [rsp+B0h] [rbp-9h]
  _QWORD *v62; // [rsp+B8h] [rbp-1h]
  __int64 v63; // [rsp+C0h] [rbp+7h]
  hkaiSilhouetteRecorder *v64; // [rsp+120h] [rbp+67h]
  hkaiWorld *v65; // [rsp+128h] [rbp+6Fh]
  hkResult result; // [rsp+130h] [rbp+77h]
  hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > *__that; // [rsp+138h] [rbp+7Fh]

  __that = &sectionsToStep->m_storage;
  v65 = world;
  v64 = this;
  v4 = threading;
  v5 = world;
  hkaiSilhouetteRecorder::connectWorld(this, world);
  hkaiSilhouetteRecorder::SilhouettesSteppedEvent::SilhouettesSteppedEvent(&array);
  v6 = v5->m_silhouetteGenerators.m_size;
  array.m_stepThreading.m_storage = v4;
  v7 = array.m_generators.m_size;
  v8 = v6;
  if ( (signed int)v6 > array.m_generators.m_size )
    v8 = array.m_generators.m_size;
  if ( (array.m_generators.m_capacityAndFlags & 0x3FFFFFFF) < (signed int)v6 )
  {
    v9 = v6;
    if ( (signed int)v6 < 2 * (array.m_generators.m_capacityAndFlags & 0x3FFFFFFF) )
      v9 = 2 * (array.m_generators.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_generators,
      v9,
      8);
  }
  v10 = 0;
  v11 = &array.m_generators.m_data[v6];
  v12 = v7 - (signed int)v6 - 1;
  if ( (signed int)v12 >= 0 )
  {
    do
    {
      v13 = (hkReferencedObject *)&v11[v12].m_pntr->vfptr;
      if ( v13 )
        hkReferencedObject::removeReference(v13);
      v11[v12--].m_pntr = 0i64;
    }
    while ( v12 >= 0 );
  }
  v14 = v5->m_silhouetteGenerators.m_data;
  v15 = array.m_generators.m_data;
  v16 = 0i64;
  if ( v8 > 0 )
  {
    do
    {
      v17 = (hkReferencedObject *)&v14[v16].m_pntr->vfptr;
      if ( v17 )
        hkReferencedObject::addReference(v17);
      v18 = (hkReferencedObject *)&v15[v16].m_pntr->vfptr;
      if ( v18 )
        hkReferencedObject::removeReference(v18);
      v19 = v14[v16++].m_pntr;
      v15[v16 - 1].m_pntr = v19;
    }
    while ( v16 < v8 );
  }
  v20 = (hkReferencedObject **)&v65->m_silhouetteGenerators.m_data[v8];
  v21 = (signed int)v6 - v8;
  if ( (signed int)v6 - v8 > 0 )
  {
    v22 = (char *)((char *)&array.m_generators.m_data[v8] - (char *)v20);
    do
    {
      if ( (hkReferencedObject **)((char *)v20 + (_QWORD)v22) )
      {
        if ( *v20 )
          hkReferencedObject::addReference(*v20);
        *(hkReferencedObject **)((char *)v20 + (_QWORD)v22) = *v20;
      }
      ++v20;
      --v21;
    }
    while ( v21 );
  }
  array.m_generators.m_size = v6;
  if ( __that )
    hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>::operator=(
      &array.m_updatedSections.m_storage,
      __that);
  v23 = v65;
  result.m_enum = 0;
  v24 = (signed __int64)&v65->m_overlapManager.m_pntr->m_sections;
  v63 = v24;
  if ( *(_DWORD *)(v24 + 8) > 0 )
  {
    v25 = 0i64;
    v59 = 0i64;
    do
    {
      v26 = array.m_overlapManagerSections.m_size;
      if ( array.m_overlapManagerSections.m_size == (array.m_overlapManagerSections.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &array.m_overlapManagerSections,
          72);
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
        v28->m_generatorData.m_capacityAndFlags = 2147483648;
        v28->m_faceToGeneratorsMap.m_data = 0i64;
        v28->m_faceToGeneratorsMap.m_size = 0;
        v28->m_faceToGeneratorsMap.m_capacityAndFlags = 2147483648;
        v28->m_facePriorities.m_elem.m_data = 0i64;
        v28->m_facePriorities.m_elem.m_size = 0;
        v28->m_facePriorities.m_elem.m_capacityAndFlags = 2147483648;
        v28->m_facePriorities.m_numElems = 0;
        v26 = array.m_overlapManagerSections.m_size;
        v27 = array.m_overlapManagerSections.m_data;
      }
      array.m_overlapManagerSections.m_size = v26 + 1;
      *((_DWORD *)&v27[array.m_overlapManagerSections.m_size] - 16) = *(_DWORD *)(v25 + *(_QWORD *)v24 + 8);
      v29 = v25 + *(_QWORD *)v24 + 16i64;
      v30 = *(signed int *)(v29 + 8);
      v31 = v30;
      v62 = (_QWORD *)(v25 + *(_QWORD *)v24 + 16i64);
      v32 = &array.m_overlapManagerSections.m_data->m_generatorDataMap
          + array.m_overlapManagerSections.m_size
          - 1
          + 8i64 * (array.m_overlapManagerSections.m_size - 1)
          + 2;
      v61 = v32;
      v33 = *((_DWORD *)v32 + 2);
      if ( (signed int)v30 > v33 )
        v31 = *((_DWORD *)v32 + 2);
      v34 = *((_DWORD *)v32 + 3) & 0x3FFFFFFF;
      if ( v34 >= (signed int)v30 )
      {
        LODWORD(__that) = 0;
      }
      else
      {
        v35 = 2 * v34;
        v36 = v30;
        if ( (signed int)v30 < v35 )
          v36 = v35;
        hkArrayUtil::_reserve(
          (hkResult *)&__that,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v32,
          v36,
          8);
      }
      v37 = (signed __int64)*v32 + 8 * v30;
      v38 = v33 - (signed int)v30 - 1;
      if ( (signed int)v38 >= 0 )
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
      v40 = (hkReferencedObject **)*v32;
      v41 = *(_QWORD *)v29;
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
          v45 = *(hkReferencedObject **)((char *)v40 + v42);
          ++v40;
          *(v40 - 1) = v45;
          --v43;
        }
        while ( v43 );
      }
      v46 = (hkReferencedObject **)(*v62 + 8i64 * v31);
      v47 = (signed int)v30 - v31;
      if ( (signed int)v30 - v31 > 0 )
      {
        v48 = (char *)*v61 + 8 * v31 - (char *)v46;
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
      v49 = result.m_enum;
      v24 = v63;
      *((_DWORD *)v61 + 2) = v30;
      hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::operator=(
        (hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *)(&array.m_overlapManagerSections.m_data->m_generatorDataMap
                                                                                        + 9i64
                                                                                        * (array.m_overlapManagerSections.m_size
                                                                                         - 1)
                                                                                        + 6),
        (hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *)(*(_QWORD *)v24
                                                                                        + 8 * (v49 + 8 * v49 + 6)));
      v25 = v59 + 72;
      result.m_enum = v49 + 1;
      v59 += 72i64;
    }
    while ( (signed int)v49 + 1 < *(_DWORD *)(v24 + 8) );
    v23 = v65;
  }
  v50 = v23->m_streamingCollection.m_pntr;
  v51 = 0;
  if ( v50->m_instances.m_size > 0 )
  {
    v52 = array.m_instanceTransforms.m_size;
    v53 = 0i64;
    do
    {
      v54 = (__m128 *)v50->m_instances.m_data[v53].m_instancePtr;
      v55 = array.m_instanceTransforms.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v54 )
      {
        if ( v52 == v55 )
        {
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &array.m_instanceTransforms,
            64);
          v52 = array.m_instanceTransforms.m_size;
        }
        v56 = &array.m_instanceTransforms.m_data[(signed __int64)v52];
        v56->m_rotation.m_col0.m_quad = v54[7];
        v56->m_rotation.m_col1.m_quad = v54[8];
        v56->m_rotation.m_col2.m_quad = v54[9];
        v57 = v54[10];
      }
      else
      {
        if ( v52 == v55 )
        {
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &array.m_instanceTransforms,
            64);
          v52 = array.m_instanceTransforms.m_size;
        }
        v56 = &array.m_instanceTransforms.m_data[(signed __int64)v52];
        v56->m_rotation.m_col0 = (hkVector4f)transform.m_quad;
        v56->m_rotation.m_col1 = (hkVector4f)direction.m_quad;
        v56->m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
        v57 = qi.m_vec.m_quad;
      }
      v56->m_translation.m_quad = v57;
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
      ((void (*)(void))array.m_generators.m_data[v58].m_pntr->vfptr[6].__first_virtual_table_function__)();
      ++v10;
      ++v58;
    }
    while ( v10 < array.m_generators.m_size );
  }
  v64->vfptr[1].postCharacterStepCallback(
    (hkaiWorld::Listener *)&v64->vfptr,
    (hkaiWorld::CharacterStepCallbackContext *)&array);
  hkaiSilhouetteRecorder::SilhouettesSteppedEvent::~SilhouettesSteppedEvent(&array);
}kContext *)&array);
  hkaiSilhouetteRecorder::SilhouettesSteppedEvent::~SilhouettesSteppedEvent(&array);
}

// File Line: 101
// RVA: 0xC3EB40
void __fastcall hkaiSilhouetteRecorder::navVolumeAdded(hkaiSilhouetteRecorder *this, hkaiWorld *world, hkaiNavVolumeInstance *volume, hkaiNavVolumeMediator *mediator)
{
  hkaiNavVolumeMediator *v4; // rbx
  hkaiNavVolumeInstance *v5; // rdi
  hkaiSilhouetteRecorder *v6; // rsi
  hkaiWorld::ListenerVtbl *v7; // rax
  hkaiSilhouetteRecorder::VolumeLoadedEvent v8; // [rsp+20h] [rbp-38h]

  v4 = mediator;
  v5 = volume;
  v6 = this;
  hkaiSilhouetteRecorder::connectWorld(this, world);
  hkaiSilhouetteRecorder::VolumeLoadedEvent::VolumeLoadedEvent(&v8);
  if ( v5 )
    hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
  if ( v8.m_volume.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v8.m_volume.m_pntr->vfptr);
  v8.m_volume.m_pntr = v5;
  if ( v4 )
    hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  if ( v8.m_mediator.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v8.m_mediator.m_pntr->vfptr);
  v7 = v6->vfptr;
  v8.m_mediator.m_pntr = v4;
  v7[1].postCharacterStepCallback((hkaiWorld::Listener *)&v6->vfptr, (hkaiWorld::CharacterStepCallbackContext *)&v8);
  hkaiSilhouetteRecorder::VolumeLoadedEvent::~VolumeLoadedEvent(&v8);
}

// File Line: 112
// RVA: 0xC3EBE0
void __fastcall hkaiSilhouetteRecorder::navVolumeRemoved(hkaiSilhouetteRecorder *this, hkaiWorld *world, hkaiNavVolumeInstance *volume)
{
  hkaiNavVolumeInstance *v3; // rbx
  hkaiSilhouetteRecorder *v4; // rdi
  int v5; // eax
  hkaiWorld::ListenerVtbl *v6; // rax
  void **v7; // [rsp+20h] [rbp-28h]
  int v8; // [rsp+28h] [rbp-20h]
  char v9; // [rsp+30h] [rbp-18h]
  int v10; // [rsp+38h] [rbp-10h]

  v3 = volume;
  v4 = this;
  hkaiSilhouetteRecorder::connectWorld(this, world);
  v7 = &hkaiSilhouetteRecorder::VolumeUnloadedEvent::`vftable;
  v5 = v3->m_sectionUid;
  v8 = 0x1FFFF;
  v10 = v5;
  v6 = v4->vfptr;
  v9 = 5;
  v6[1].postCharacterStepCallback((hkaiWorld::Listener *)&v4->vfptr, (hkaiWorld::CharacterStepCallbackContext *)&v7);
}

// File Line: 121
// RVA: 0xC3EC40
void __fastcall hkaiSilhouetteRecorder::graphAdded(hkaiSilhouetteRecorder *this, hkaiWorld *world, hkaiDirectedGraphInstance *graph)
{
  hkaiDirectedGraphInstance *v3; // rbx
  hkaiSilhouetteRecorder *v4; // rdi
  hkaiWorld::ListenerVtbl *v5; // rax
  hkaiSilhouetteRecorder::GraphLoadedEvent v6; // [rsp+20h] [rbp-28h]

  v3 = graph;
  v4 = this;
  hkaiSilhouetteRecorder::connectWorld(this, world);
  hkaiSilhouetteRecorder::GraphLoadedEvent::GraphLoadedEvent(&v6);
  if ( v3 )
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
  if ( v6.m_graph.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v6.m_graph.m_pntr->vfptr);
  v5 = v4->vfptr;
  v6.m_graph.m_pntr = v3;
  v5[1].postCharacterStepCallback((hkaiWorld::Listener *)&v4->vfptr, (hkaiWorld::CharacterStepCallbackContext *)&v6);
  hkaiSilhouetteRecorder::GraphLoadedEvent::~GraphLoadedEvent(&v6);
}

// File Line: 130
// RVA: 0xC3ECB0
void __fastcall hkaiSilhouetteRecorder::graphRemoved(hkaiSilhouetteRecorder *this, hkaiWorld *world, hkaiDirectedGraphInstance *graph)
{
  hkaiDirectedGraphInstance *v3; // rbx
  hkaiSilhouetteRecorder *v4; // rdi
  int v5; // eax
  hkaiWorld::ListenerVtbl *v6; // rax
  void **v7; // [rsp+20h] [rbp-28h]
  int v8; // [rsp+28h] [rbp-20h]
  char v9; // [rsp+30h] [rbp-18h]
  int v10; // [rsp+38h] [rbp-10h]

  v3 = graph;
  v4 = this;
  hkaiSilhouetteRecorder::connectWorld(this, world);
  v7 = &hkaiSilhouetteRecorder::GraphUnloadedEvent::`vftable;
  v5 = v3->m_sectionUid;
  v8 = 0x1FFFF;
  v10 = v5;
  v6 = v4->vfptr;
  v9 = 7;
  v6[1].postCharacterStepCallback((hkaiWorld::Listener *)&v4->vfptr, (hkaiWorld::CharacterStepCallbackContext *)&v7);
}

// File Line: 140
// RVA: 0xC3F210
void __fastcall hkaiSilhouetteRecorder::connectWorld(hkaiSilhouetteRecorder *this, hkaiWorld *world)
{
  hkaiWorld *v2; // rdi
  hkaiSilhouetteRecorder *v3; // rbx
  hkaiWorld::ListenerVtbl *v4; // rax
  hkaiSilhouetteRecorder::WorldConnectedEvent v5; // [rsp+20h] [rbp-28h]

  v2 = world;
  v3 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[1].__vecDelDtor)() )
  {
    (*(void (__fastcall **)(hkaiSilhouetteRecorder *, hkaiWorld *))v3->vfptr[1].gap8)(v3, v2);
    hkaiSilhouetteRecorder::WorldConnectedEvent::WorldConnectedEvent(&v5);
    if ( v2 )
      hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
    if ( v5.m_world.m_pntr )
      hkReferencedObject::removeReference((hkReferencedObject *)&v5.m_world.m_pntr->vfptr);
    v4 = v3->vfptr;
    v5.m_world.m_pntr = v2;
    v4[1].postCharacterStepCallback((hkaiWorld::Listener *)&v3->vfptr, (hkaiWorld::CharacterStepCallbackContext *)&v5);
    hkaiSilhouetteRecorder::WorldConnectedEvent::~WorldConnectedEvent(&v5);
  }
}

// File Line: 159
// RVA: 0xC3E7E0
void __fastcall hkaiSilhouetteRecorder::applyEventToWorld(hkaiSilhouetteRecorder::ReplayEvent *e, hkRefPtr<hkaiWorld> *world, hkJobQueue *jobQueue, hkJobThreadPool *threadPool)
{
  hkJobThreadPool *v4; // r15
  hkJobQueue *v5; // r12
  hkReferencedObject **v6; // rsi
  hkaiSilhouetteRecorder::ReplayEvent *v7; // rdi
  hkBaseObjectVtbl *v8; // rcx
  hkaiStreamingCollection *v9; // rbx
  int v10; // eax
  hkaiStreamingCollection::InstanceInfo *v11; // rcx
  hkaiStreamingCollection *v12; // rbp
  int v13; // ebx
  __int64 v14; // r14
  hkaiNavMeshInstance *v15; // rdx
  hkaiWorld *v16; // rcx
  int v17; // eax
  int v18; // eax
  hkaiDirectedGraphInstance *v19; // rbx

  v4 = threadPool;
  v5 = jobQueue;
  v6 = (hkReferencedObject **)world;
  v7 = e;
  switch ( e->m_eventType.m_storage )
  {
    case 0:
      v8 = e[1].vfptr;
      if ( v8 )
        hkReferencedObject::addReference((hkReferencedObject *)v8);
      if ( *v6 )
        hkReferencedObject::removeReference(*v6);
      *v6 = (hkReferencedObject *)v7[1].vfptr;
      break;
    case 1:
      hkaiWorld::loadNavMeshInstance(
        world->m_pntr,
        (hkaiNavMeshInstance *)e[1].vfptr,
        *(hkaiNavMeshQueryMediator **)&e[1].m_memSizeAndFlags,
        *(hkaiDirectedGraphInstance **)&e[1].m_eventType.m_storage);
      break;
    case 2:
      v9 = world->m_pntr->m_streamingCollection.m_pntr;
      v10 = hkaiStreamingCollection::findSectionIdByUid(
              world->m_pntr->m_streamingCollection.m_pntr,
              (unsigned int)e[1].vfptr);
      v11 = v9->m_instances.m_data;
      if ( v10 >= 0 )
        hkaiWorld::unloadNavMeshInstance((hkaiWorld *)*v6, v11[v10].m_instancePtr, v11[v10].m_clusterGraphInstance);
      else
        hkaiWorld::unloadNavMeshInstance((hkaiWorld *)*v6, v11[v10].m_instancePtr, 0i64);
      break;
    case 3:
      hkaiWorld::forceSilhouetteInformation(
        world->m_pntr,
        (hkArray<hkRefPtr<hkaiSilhouetteGenerator>,hkContainerHeapAllocator> *)&e[1].m_memSizeAndFlags,
        (hkArray<hkaiOverlapManagerSection,hkContainerHeapAllocator> *)&e[2].m_eventType);
      v12 = (hkaiStreamingCollection *)(*v6)[2].vfptr;
      v13 = 0;
      if ( *(_DWORD *)&v7[2].m_memSizeAndFlags > 0 )
      {
        v14 = 0i64;
        do
        {
          v15 = v12->m_instances.m_data[v14].m_instancePtr;
          if ( v15 )
            hkaiStreamingCollection::setSectionTransform(
              v12,
              v15,
              (hkTransformf *)&v7[2].vfptr[4 * (signed __int64)v13]);
          ++v13;
          ++v14;
        }
        while ( v13 < *(_DWORD *)&v7[2].m_memSizeAndFlags );
      }
      v16 = (hkaiWorld *)*v6;
      if ( LODWORD(v7[1].vfptr) )
        hkaiWorld::stepSilhouettesMT(v16, (hkBitField *)&v7[3].m_memSizeAndFlags, v5, v4);
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
      v17 = hkaiStreamingCollection::findVolumeIdByUid(
              world->m_pntr->m_streamingCollection.m_pntr,
              (unsigned int)e[1].vfptr);
      hkaiWorld::unloadNavVolume(
        (hkaiWorld *)*v6,
        *((hkaiNavVolumeInstance **)(*v6)[2].vfptr[2].__vecDelDtor + 6 * v17 + 1));
      break;
    case 6:
      hkaiWorld::loadNavMeshGraph(world->m_pntr, (hkaiDirectedGraphInstance *)e[1].vfptr);
      break;
    case 7:
      v18 = hkaiStreamingCollection::findGraphIdByUid(
              world->m_pntr->m_streamingCollection.m_pntr,
              (unsigned int)e[1].vfptr);
      if ( v18 >= 0 )
        v19 = (hkaiDirectedGraphInstance *)*((_QWORD *)(*v6)[2].vfptr[2].__vecDelDtor + 6 * v18 + 2);
      else
        v19 = 0i64;
      hkaiWorld::unloadNavMeshGraph((hkaiWorld *)*v6, v19);
      break;
    default:
      return;
  }
}

// File Line: 265
// RVA: 0xC3F4C0
void __fastcall hkaiSilhouetteReplayViewer::hkaiSilhouetteReplayViewer(hkaiSilhouetteReplayViewer *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiSilhouetteReplayViewer *v2; // rbx

  v2 = this;
  hkaiViewerBase::hkaiViewerBase((hkaiViewerBase *)&this->vfptr, contexts);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteReplayViewer::`vftable{for `hkReferencedObject};
  v2->vfptr = (hkProcessVtbl *)&hkaiSilhouetteReplayViewer::`vftable{for `hkProcess};
  v2->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiSilhouetteReplayViewer::`vftable{for `hkaiViewerContextWorldListener};
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiSilhouetteReplayViewer::`vftable;
  v2->m_worldSent.m_bool = 0;
}

// File Line: 269
// RVA: 0xC3F510
void __fastcall hkaiSilhouetteReplayViewer::~hkaiSilhouetteReplayViewer(hkaiSilhouetteReplayViewer *this)
{
  int v1; // edi
  hkaiSilhouetteReplayViewer *v2; // rbx
  __int64 v3; // rsi
  hkaiViewerContext *v4; // rdx

  v1 = 0;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteReplayViewer::`vftable{for `hkReferencedObject};
  this->vfptr = (hkProcessVtbl *)&hkaiSilhouetteReplayViewer::`vftable{for `hkProcess};
  this->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiSilhouetteReplayViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiSilhouetteReplayViewer::`vftable;
  if ( this->m_context.m_pntr )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->m_context.m_pntr;
      if ( v1 >= v4->m_worlds.m_size )
        break;
      hkaiSilhouetteReplayViewer::worldRemovedCallback(
        (hkaiSilhouetteReplayViewer *)((char *)v2 + 64),
        v4->m_worlds.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v2->m_context.m_pntr );
  }
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable;
  hkaiViewerBase::~hkaiViewerBase((hkaiViewerBase *)&v2->vfptr);
}

// File Line: 277
// RVA: 0xC3F320
void __fastcall hkaiSilhouetteReplayViewer::init(hkaiSilhouetteReplayViewer *this)
{
  hkProcessHandler *v1; // rax
  int v2; // ebx
  hkaiSilhouetteReplayViewer *v3; // rsi
  __int64 v4; // rdi

  v1 = this->m_processHandler;
  v2 = 0;
  v3 = this;
  if ( v1 )
  {
    v4 = 0i64;
    do
    {
      if ( v2 >= SLODWORD(v1[22].vfptr) )
        break;
      ((void (__fastcall *)(hkDebugDisplayHandler **, _QWORD))v3->m_displayHandler[1].vfptr)(
        &v3->m_displayHandler,
        *(void *(__fastcall **)(hkProcessHandler *, unsigned int))((char *)&v1[21].vfptr->__vecDelDtor + v4));
      v1 = v3->m_processHandler;
      ++v2;
      v4 += 8i64;
    }
    while ( v1 );
  }
}

// File Line: 285
// RVA: 0xC3F390
void __fastcall hkaiSilhouetteReplayViewer::worldAddedCallback(hkaiSilhouetteReplayViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiSilhouetteReplayViewer *)64 )
    hkaiWorld::addListener(w, 0i64);
  else
    hkaiWorld::addListener(w, (hkaiWorld::Listener *)&this->vfptr);
}

// File Line: 290
// RVA: 0xC3F3C0
void __fastcall hkaiSilhouetteReplayViewer::worldRemovedCallback(hkaiSilhouetteReplayViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiSilhouetteReplayViewer *)64 )
    hkaiWorld::removeListener(w, 0i64);
  else
    hkaiWorld::removeListener(w, (hkaiWorld::Listener *)&this->vfptr);
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
hkProcess *__fastcall hkaiSilhouetteReplayViewer::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkaiSilhouetteReplayViewer *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiSilhouetteReplayViewer *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                       v2[11],
                                       96i64);
  if ( v3 && (hkaiSilhouetteReplayViewer::hkaiSilhouetteReplayViewer(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
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
void __fastcall hkaiSilhouetteReplayViewer::sendEvent(hkaiSilhouetteReplayViewer *this, hkaiSilhouetteRecorder::ReplayEvent *e)
{
  hkaiSilhouetteReplayViewer *v2; // rdi
  hkaiSilhouetteRecorder::ReplayEvent *v3; // rbx
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx

  v2 = this;
  v3 = e;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TthkaiSilhouetteReplayViewer::sendEvent";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  hkRemoteObjectProcess::sendObject(
    (hkDisplaySerializeOStream *)v2[-1].m_processHandler,
    (hkReferencedObject *)&v3->vfptr,
    SEND_OBJECT_TAGFILE);
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "Et";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
}

// File Line: 328
// RVA: 0xC3E3E0
void __fastcall hkaiSilhouetteRecorder::InstanceLoadedEvent::InstanceLoadedEvent(hkaiSilhouetteRecorder::InstanceLoadedEvent *this)
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
void __fastcall hkaiSilhouetteRecorder::InstanceLoadedEvent::InstanceLoadedEvent(hkaiSilhouetteRecorder::InstanceLoadedEvent *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::InstanceLoadedEvent::`vftable;
}

// File Line: 339
// RVA: 0xC3E430
void __fastcall hkaiSilhouetteRecorder::InstanceLoadedEvent::~InstanceLoadedEvent(hkaiSilhouetteRecorder::InstanceLoadedEvent *this)
{
  hkaiSilhouetteRecorder::InstanceLoadedEvent *v1; // rbx
  hkaiDirectedGraphInstance *v2; // rcx
  hkReferencedObject *v3; // rcx
  hkReferencedObject *v4; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::InstanceLoadedEvent::`vftable;
  v2 = this->m_graph.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_graph.m_pntr = 0i64;
  v3 = (hkReferencedObject *)&v1->m_mediator.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_mediator.m_pntr = 0i64;
  v4 = (hkReferencedObject *)&v1->m_instance.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v1->m_instance.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 345
// RVA: 0xC3E4A0
void __fastcall hkaiSilhouetteRecorder::SilhouettesSteppedEvent::SilhouettesSteppedEvent(hkaiSilhouetteRecorder::SilhouettesSteppedEvent *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_eventType.m_storage = 3;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::SilhouettesSteppedEvent::`vftable;
  this->m_generators.m_capacityAndFlags = 2147483648;
  this->m_generators.m_data = 0i64;
  this->m_generators.m_size = 0;
  this->m_instanceTransforms.m_data = 0i64;
  this->m_instanceTransforms.m_size = 0;
  this->m_instanceTransforms.m_capacityAndFlags = 2147483648;
  this->m_overlapManagerSections.m_data = 0i64;
  this->m_overlapManagerSections.m_size = 0;
  this->m_overlapManagerSections.m_capacityAndFlags = 2147483648;
  this->m_updatedSections.m_storage.m_words.m_data = 0i64;
  this->m_updatedSections.m_storage.m_words.m_size = 0;
  this->m_updatedSections.m_storage.m_words.m_capacityAndFlags = 2147483648;
  this->m_updatedSections.m_storage.m_numBits = 0;
}

// File Line: 353
// RVA: 0xC3E500
void __fastcall hkaiSilhouetteRecorder::SilhouettesSteppedEvent::SilhouettesSteppedEvent(hkaiSilhouetteRecorder::SilhouettesSteppedEvent *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::SilhouettesSteppedEvent::`vftable;
}

// File Line: 357
// RVA: 0xC3E520
void __fastcall hkaiSilhouetteRecorder::SilhouettesSteppedEvent::~SilhouettesSteppedEvent(hkaiSilhouetteRecorder::SilhouettesSteppedEvent *this)
{
  hkaiSilhouetteRecorder::SilhouettesSteppedEvent *v1; // rbx
  int v2; // er8
  int v3; // edi
  hkaiOverlapManagerSection *v4; // rsi
  int v5; // eax
  int v6; // er8
  hkRefPtr<hkaiSilhouetteGenerator> *v7; // rsi
  int v8; // eax
  __int64 i; // rdi
  hkReferencedObject *v10; // rcx
  int v11; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::SilhouettesSteppedEvent::`vftable;
  v2 = this->m_updatedSections.m_storage.m_words.m_capacityAndFlags;
  this->m_updatedSections.m_storage.m_words.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_updatedSections.m_storage.m_words.m_data,
      4 * v2);
  v1->m_updatedSections.m_storage.m_words.m_data = 0i64;
  v1->m_updatedSections.m_storage.m_words.m_capacityAndFlags = 2147483648;
  v3 = v1->m_overlapManagerSections.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &v1->m_overlapManagerSections.m_data[v3];
    do
    {
      hkaiOverlapManagerSection::~hkaiOverlapManagerSection(v4);
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  v5 = v1->m_overlapManagerSections.m_capacityAndFlags;
  v1->m_overlapManagerSections.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_overlapManagerSections.m_data,
      72 * (v5 & 0x3FFFFFFF));
  v1->m_overlapManagerSections.m_data = 0i64;
  v1->m_overlapManagerSections.m_capacityAndFlags = 2147483648;
  v6 = v1->m_instanceTransforms.m_capacityAndFlags;
  v1->m_instanceTransforms.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_instanceTransforms.m_data,
      v6 << 6);
  v1->m_instanceTransforms.m_data = 0i64;
  v1->m_instanceTransforms.m_capacityAndFlags = 2147483648;
  v7 = v1->m_generators.m_data;
  v8 = v1->m_generators.m_size - 1;
  for ( i = v8; i >= 0; v7[i--].m_pntr = 0i64 )
  {
    v10 = (hkReferencedObject *)&v7[i].m_pntr->vfptr;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
  }
  v11 = v1->m_generators.m_capacityAndFlags;
  v1->m_generators.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_generators.m_data,
      8 * v11);
  v1->m_generators.m_data = 0i64;
  v1->m_generators.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 363
// RVA: 0xC3E6A0
void __fastcall hkaiSilhouetteRecorder::VolumeLoadedEvent::VolumeLoadedEvent(hkaiSilhouetteRecorder::VolumeLoadedEvent *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_eventType.m_storage = 4;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::VolumeLoadedEvent::`vftable;
  this->m_volume.m_pntr = 0i64;
  this->m_mediator.m_pntr = 0i64;
}

// File Line: 370
// RVA: 0xC3E6D0
void __fastcall hkaiSilhouetteRecorder::VolumeLoadedEvent::VolumeLoadedEvent(hkaiSilhouetteRecorder::VolumeLoadedEvent *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::VolumeLoadedEvent::`vftable;
}

// File Line: 374
// RVA: 0xC3E6F0
void __fastcall hkaiSilhouetteRecorder::VolumeLoadedEvent::~VolumeLoadedEvent(hkaiSilhouetteRecorder::VolumeLoadedEvent *this)
{
  hkaiSilhouetteRecorder::VolumeLoadedEvent *v1; // rbx
  hkaiNavVolumeMediator *v2; // rcx
  hkReferencedObject *v3; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::VolumeLoadedEvent::`vftable;
  v2 = this->m_mediator.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_mediator.m_pntr = 0i64;
  v3 = (hkReferencedObject *)&v1->m_volume.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_volume.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 380
// RVA: 0xC3E750
void __fastcall hkaiSilhouetteRecorder::GraphLoadedEvent::GraphLoadedEvent(hkaiSilhouetteRecorder::GraphLoadedEvent *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_eventType.m_storage = 6;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::GraphLoadedEvent::`vftable;
  this->m_graph.m_pntr = 0i64;
}

// File Line: 386
// RVA: 0xC3E780
void __fastcall hkaiSilhouetteRecorder::GraphLoadedEvent::GraphLoadedEvent(hkaiSilhouetteRecorder::GraphLoadedEvent *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::GraphLoadedEvent::`vftable;
}

// File Line: 390
// RVA: 0xC3E7A0
void __fastcall hkaiSilhouetteRecorder::GraphLoadedEvent::~GraphLoadedEvent(hkaiSilhouetteRecorder::GraphLoadedEvent *this)
{
  hkaiSilhouetteRecorder::GraphLoadedEvent *v1; // rbx
  hkaiDirectedGraphInstance *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::GraphLoadedEvent::`vftable;
  v2 = this->m_graph.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_graph.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 396
// RVA: 0xC3E350
void __fastcall hkaiSilhouetteRecorder::WorldConnectedEvent::WorldConnectedEvent(hkaiSilhouetteRecorder::WorldConnectedEvent *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_eventType.m_storage = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::WorldConnectedEvent::`vftable;
  this->m_world.m_pntr = 0i64;
}

// File Line: 401
// RVA: 0xC3E380
void __fastcall hkaiSilhouetteRecorder::WorldConnectedEvent::WorldConnectedEvent(hkaiSilhouetteRecorder::WorldConnectedEvent *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::WorldConnectedEvent::`vftable;
}

// File Line: 405
// RVA: 0xC3E3A0
void __fastcall hkaiSilhouetteRecorder::WorldConnectedEvent::~WorldConnectedEvent(hkaiSilhouetteRecorder::WorldConnectedEvent *this)
{
  hkaiSilhouetteRecorder::WorldConnectedEvent *v1; // rbx
  hkaiWorld *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteRecorder::WorldConnectedEvent::`vftable;
  v2 = this->m_world.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_world.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

