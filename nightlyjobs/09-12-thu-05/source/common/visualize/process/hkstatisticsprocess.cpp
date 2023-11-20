// File Line: 25
// RVA: 0xE78D10
hkProcess *__fastcall hkStatisticsProcess::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkStatisticsProcess *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkStatisticsProcess *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 112i64);
  if ( v3 && (hkStatisticsProcess::hkStatisticsProcess(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 30
// RVA: 0xE78D70
void hkStatisticsProcess::registerProcess(void)
{
  hkStatisticsProcess::m_tag = hkProcessFactory::registerProcess(
                                 hkSingleton<hkProcessFactory>::s_instance,
                                 "Statistics",
                                 hkStatisticsProcess::create);
}

// File Line: 36
// RVA: 0xE79460
void __fastcall hkStatisticsProcess::hkStatisticsProcess(hkStatisticsProcess *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  signed int *v2; // rdi
  hkStatisticsProcess *v3; // rbx
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v4; // rsi
  signed __int64 v5; // rax
  float v6; // xmm1_4
  int v7; // er9
  int v8; // eax
  int v9; // eax
  __int64 v10; // rdi
  _QWORD **v11; // rax
  __int64 v12; // rax
  hkProcessContext **v13; // rcx
  __int64 v14; // rdx
  char *v15; // r8
  hkProcessContext *v16; // rax
  hkArray<hkObjectSerialize::GlobalFixup,hkContainerHeapAllocator> globalFixups; // [rsp+40h] [rbp-29h]
  hkStreamWriter s; // [rsp+50h] [rbp-19h]
  signed int *v19; // [rsp+60h] [rbp-9h]
  hkContainerHeapAllocator::Allocator *v20; // [rsp+68h] [rbp-1h]
  int v21; // [rsp+70h] [rbp+7h]
  int v22; // [rsp+74h] [rbp+Bh]
  hkMonitorStreamFrameInfo data; // [rsp+78h] [rbp+Fh]
  hkResult result; // [rsp+D0h] [rbp+67h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = (signed int *)&this->m_infoBuffer;
  v3 = this;
  this->m_selectable.m_bool = 1;
  this->vfptr = (hkBaseObjectVtbl *)&hkStatisticsProcess::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkProcessVtbl *)&hkStatisticsProcess::`vftable'{for `hkProcess'};
  this->m_contexts.m_data = 0i64;
  this->m_contexts.m_size = 0;
  this->m_contexts.m_capacityAndFlags = 2147483648;
  *(_QWORD *)v2 = 0i64;
  v2[2] = 0;
  v2[3] = 2147483648;
  this->m_strBuffer.m_data = 0i64;
  this->m_strBuffer.m_size = 0;
  this->m_strBuffer.m_capacityAndFlags = 2147483648;
  v4 = contexts;
  hkMonitorStreamFrameInfo::hkMonitorStreamFrameInfo(&data);
  hkStringPtr::operator=(&data.m_heading, 0i64);
  *(_QWORD *)&data.m_indexOfTimer1 = 1i64;
  data.m_indexOfTimer0 = 0;
  v5 = hkStopwatch::getTicksPerSecond();
  v6 = (float)(signed int)v5;
  if ( v5 < 0 )
    v6 = v6 + 1.8446744e19;
  v7 = v2[2] + 1;
  v21 = v2[2];
  globalFixups.m_data = 0i64;
  globalFixups.m_size = 0;
  globalFixups.m_capacityAndFlags = 2147483648;
  data.m_timerFactor0 = 1000.0 / v6;
  *(_DWORD *)&s.m_memSizeAndFlags = 0x1FFFF;
  s.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable';
  v19 = v2;
  LODWORD(data.m_timerFactor1) = (_DWORD)FLOAT_1_0;
  v20 = &hkContainerHeapAllocator::s_alloc;
  v22 = 1;
  v8 = v2[3] & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    if ( v7 < v9 )
      v7 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, v7, 1);
    v2 = v19;
  }
  *(_BYTE *)(v2[2] + *(_QWORD *)v2) = 0;
  hkStructureLayout::hkStructureLayout((hkStructureLayout *)&result, &hkStructureLayout::MsvcWin32LayoutRules);
  hkObjectSerialize::writeObject(
    &s,
    (hkStructureLayout *)&result,
    1ui64,
    &data,
    &hkMonitorStreamFrameInfoClass,
    &globalFixups,
    0i64,
    (hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int>)2);
  s.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable';
  if ( !v22 )
  {
    v10 = (__int64)v19;
    if ( v19 )
    {
      v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v11[11] + 16i64))(v11[11], v10, 16i64);
    }
  }
  globalFixups.m_size = 0;
  s.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  if ( globalFixups.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      globalFixups.m_data,
      24 * (globalFixups.m_capacityAndFlags & 0x3FFFFFFF));
  if ( (v3->m_contexts.m_capacityAndFlags & 0x3FFFFFFF) < v4->m_size )
  {
    if ( v3->m_contexts.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3->m_contexts.m_data,
        8 * v3->m_contexts.m_capacityAndFlags);
    result.m_enum = 8 * v4->m_size;
    v3->m_contexts.m_data = (hkProcessContext **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                   (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                   (int *)&result);
    v3->m_contexts.m_capacityAndFlags = result.m_enum / 8;
  }
  v12 = v4->m_size;
  v13 = v3->m_contexts.m_data;
  v3->m_contexts.m_size = v12;
  v14 = v12;
  if ( (signed int)v12 > 0 )
  {
    v15 = (char *)((char *)v4->m_data - (char *)v13);
    do
    {
      v16 = *(hkProcessContext **)((char *)v13 + (_QWORD)v15);
      ++v13;
      *(v13 - 1) = v16;
      --v14;
    }
    while ( v14 );
  }
  hkStringPtr::~hkStringPtr(&data.m_heading);
}

// File Line: 62
// RVA: 0xE79720
void __fastcall hkStatisticsProcess::~hkStatisticsProcess(hkStatisticsProcess *this)
{
  hkStatisticsProcess *v1; // rbx
  int v2; // er8
  int v3; // er8
  int v4; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkStatisticsProcess::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkProcessVtbl *)&hkStatisticsProcess::`vftable'{for `hkProcess'};
  v2 = this->m_strBuffer.m_capacityAndFlags;
  this->m_strBuffer.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_strBuffer.m_data,
      v2 & 0x3FFFFFFF);
  v1->m_strBuffer.m_data = 0i64;
  v1->m_strBuffer.m_capacityAndFlags = 2147483648;
  v3 = v1->m_infoBuffer.m_capacityAndFlags;
  v1->m_infoBuffer.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_infoBuffer.m_data,
      v3 & 0x3FFFFFFF);
  v1->m_infoBuffer.m_data = 0i64;
  v1->m_infoBuffer.m_capacityAndFlags = 2147483648;
  v4 = v1->m_contexts.m_capacityAndFlags;
  v1->m_contexts.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_contexts.m_data,
      8 * v4);
  v1->m_contexts.m_data = 0i64;
  v1->m_contexts.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkProcessVtbl *)&hkProcess::`vftable';
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 150
// RVA: 0xE78DA0
void __fastcall hkStatisticsProcess::step(hkStatisticsProcess *this, float frameTimeInMs)
{
  hkStatisticsProcess *v2; // rsi
  __int64 v3; // r11
  signed int v4; // edi
  _QWORD *v5; // r10
  char *v6; // r9
  __int64 v7; // r8
  __int64 v8; // rdx
  hkDebugDisplayHandler *v9; // rbx
  hkDebugDisplayHandler *v10; // rcx
  signed __int64 v11; // r14
  hkDebugDisplayHandlerVtbl *v12; // rbx
  int v13; // eax
  _QWORD *v14; // rax
  __int64 v15; // rcx
  __int64 v16; // rdx
  __int64 v17; // r11
  __int64 v18; // rax
  hkDebugDisplayHandlerVtbl *v19; // rbx
  __int64 v20; // r8
  __int64 v21; // rcx
  hkResult *(__fastcall *v22)(hkDebugDisplayHandler *, hkResult *, unsigned __int64 *, int, hkMatrix4f *, int, hkMatrix4f *, int); // r8
  __int64 v23; // rdx
  __int64 v24; // rax
  __int64 *v25; // rax
  signed int v26; // ecx
  __int64 v27; // rdi
  __int64 v28; // rbx
  int v29; // ecx
  int v30; // er9
  signed int v31; // er15
  signed int v32; // edi
  char *v33; // rcx
  char *v34; // rdx
  unsigned __int64 v35; // rbx
  int v36; // eax
  int v37; // edx
  signed __int64 v38; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v39; // rax
  int v40; // ebx
  int v41; // ecx
  hkMonitorStreamStringMap::StringMap *v42; // r8
  hkMonitorStreamStringMap::StringMap *v43; // rax
  hkStringPtr *v44; // rdx
  int v45; // edx
  signed __int64 v46; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v47; // rax
  signed __int64 v48; // rdx
  int v49; // eax
  int v50; // er9
  int v51; // eax
  __int64 v52; // rbx
  _QWORD **v53; // rax
  int v54; // ebx
  hkStringPtr *v55; // rdi
  __int64 v56; // r14
  int v57; // ebx
  int v58; // edi
  __int64 i; // rdi
  int v60; // ebx
  char *array; // [rsp+30h] [rbp-49h]
  hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flags; // [rsp+38h] [rbp-41h]
  int v63; // [rsp+3Ch] [rbp-3Dh]
  char *v64; // [rsp+40h] [rbp-39h]
  int v65; // [rsp+48h] [rbp-31h]
  int v66; // [rsp+4Ch] [rbp-2Dh]
  hkMonitorStreamStringMap data; // [rsp+50h] [rbp-29h]
  hkPointerMap<void const *,char const *,hkContainerHeapAllocator> map; // [rsp+60h] [rbp-19h]
  hkArray<hkObjectSerialize::GlobalFixup,hkContainerHeapAllocator> globalFixups; // [rsp+70h] [rbp-9h]
  hkStreamWriter s; // [rsp+80h] [rbp+7h]
  hkArray<char,hkContainerHeapAllocator> *v71; // [rsp+90h] [rbp+17h]
  hkContainerHeapAllocator::Allocator *v72; // [rsp+98h] [rbp+1Fh]
  int v73; // [rsp+A0h] [rbp+27h]
  int v74; // [rsp+A4h] [rbp+2Bh]
  hkResult result; // [rsp+E0h] [rbp+67h]

  v2 = this;
  if ( *(_QWORD *)&this->m_selectable.m_bool )
  {
    v3 = SLODWORD(this->m_processHandler);
    v4 = 2147483648;
    globalFixups.m_capacityAndFlags = 2147483648;
    globalFixups.m_data = 0i64;
    globalFixups.m_size = 0;
    v5 = 0i64;
    array = 0i64;
    flags.m_storage = 0;
    v6 = 0i64;
    v64 = 0i64;
    v65 = 0;
    v7 = 0i64;
    v8 = 0i64;
    v63 = 2147483648;
    v66 = 2147483648;
    if ( v3 <= 0 )
      goto LABEL_19;
    v9 = this->m_displayHandler;
    v10 = this->m_displayHandler;
    while ( *(_DWORD *)&v10->vfptr->gap8[16] <= 0 )
    {
      ++v8;
      v7 = (unsigned int)(v7 + 1);
      ++v10;
      if ( v8 >= v3 )
        goto LABEL_19;
    }
    v11 = (signed int)v7;
    v12 = v9[v11].vfptr;
    v13 = *(_DWORD *)&v12->gap8[16];
    if ( v13 > 0 )
    {
      result.m_enum = 8 * v13;
      v14 = (_QWORD *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, __int64, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                        &hkContainerHeapAllocator::s_alloc,
                        &result,
                        v7,
                        0i64);
      v4 = v66;
      v6 = v64;
      v5 = v14;
      array = (char *)v14;
      v63 = result.m_enum / 8;
    }
    v15 = *(signed int *)&v12->gap8[16];
    v16 = 0i64;
    flags.m_storage = v15;
    v17 = *(_QWORD *)&v12->gap8[8];
    if ( (signed int)v15 > 0 )
    {
      do
      {
        v18 = *(_QWORD *)(v17 + 8 * v16++);
        v5[v16 - 1] = v18;
      }
      while ( v16 < v15 );
      v4 = v66;
      v6 = v64;
    }
    v19 = v2->m_displayHandler[v11].vfptr;
    v20 = v4 & 0x3FFFFFFF;
    if ( (signed int)v20 < SLODWORD(v19->addTextureSearchPath) )
    {
      if ( v4 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v6,
          8 * v4);
      result.m_enum = 8 * LODWORD(v19->addTextureSearchPath);
      v6 = (char *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, __int64, char *))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                     &hkContainerHeapAllocator::s_alloc,
                     &result,
                     v20,
                     v6);
      v64 = v6;
      v66 = result.m_enum / 8;
    }
    v21 = 0i64;
    v65 = (int)v19->addTextureSearchPath;
    v22 = v19->skinGeometry;
    v23 = v65;
    if ( v65 > 0 )
    {
      do
      {
        v24 = *((_QWORD *)v22 + v21++);
        *(_QWORD *)&v6[8 * v21 - 8] = v24;
      }
      while ( v21 < v23 );
    }
    if ( !flags.m_storage )
    {
LABEL_19:
      v25 = (__int64 *)TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v26 = flags.m_storage;
      v27 = *v25;
      v28 = v25[1];
      if ( flags.m_storage == (v63 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
        v26 = flags.m_storage;
      }
      *(_QWORD *)&array[8 * v26] = v27;
      v29 = v65;
      ++flags.m_storage;
      if ( v65 == (v66 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v64, 8);
        v29 = v65;
      }
      *(_QWORD *)&v64[8 * v29] = v28;
      ++v65;
    }
    if ( (v2->m_infoBuffer.m_capacityAndFlags & 0x3FFFFFFF) < 0 )
    {
      v30 = 0;
      if ( 2 * (v2->m_infoBuffer.m_capacityAndFlags & 0x3FFFFFFF) > 0 )
        v30 = 2 * (v2->m_infoBuffer.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v2->m_infoBuffer,
        v30,
        1);
    }
    v2->m_infoBuffer.m_size = 0;
    v31 = 0;
    map.m_map.m_elem = 0i64;
    map.m_map.m_numElems = 0;
    map.m_map.m_hashMod = -1;
    hkMonitorStreamStringMap::hkMonitorStreamStringMap(&data);
    v32 = 0;
    if ( (signed int)flags.m_storage > 0 )
    {
      v33 = array;
      v34 = v64;
      v35 = 0i64;
      do
      {
        hkMonitorStreamAnalyzer::extractStringMap(*(const char **)&v33[v35], *(const char **)&v34[v35], &map);
        v34 = v64;
        v33 = array;
        v36 = *(_DWORD *)&v64[v35];
        ++v32;
        v35 += 8i64;
        v31 += v36 - *(_DWORD *)&array[v35 - 8];
      }
      while ( v32 < (signed int)flags.m_storage );
    }
    v37 = 0;
    v38 = 0i64;
    if ( map.m_map.m_hashMod >= 0 )
    {
      v39 = map.m_map.m_elem;
      do
      {
        if ( v39->key != -1i64 )
          break;
        ++v38;
        ++v37;
        ++v39;
      }
      while ( v38 <= map.m_map.m_hashMod );
    }
    v40 = v37;
    if ( v37 <= map.m_map.m_hashMod )
    {
      do
      {
        v41 = data.m_map.m_size;
        if ( data.m_map.m_size == (data.m_map.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &data, 16);
          v41 = data.m_map.m_size;
        }
        v42 = data.m_map.m_data;
        v43 = &data.m_map.m_data[v41];
        if ( v43 )
        {
          hkMonitorStreamStringMap::StringMap::StringMap(v43);
          v41 = data.m_map.m_size;
          v42 = data.m_map.m_data;
        }
        data.m_map.m_size = v41 + 1;
        v44 = (hkStringPtr *)&v42[v41];
        v44->m_stringAndFlag = (const char *)map.m_map.m_elem[v40].key;
        hkStringPtr::operator=(v44 + 1, (const char *)map.m_map.m_elem[v40].val);
        v45 = v40 + 1;
        v46 = v40 + 1;
        if ( v46 <= map.m_map.m_hashMod )
        {
          v47 = &map.m_map.m_elem[v45];
          do
          {
            if ( v47->key != -1i64 )
              break;
            ++v46;
            ++v45;
            ++v47;
          }
          while ( v46 <= map.m_map.m_hashMod );
        }
        v40 = v45;
      }
      while ( v45 <= map.m_map.m_hashMod );
    }
    v48 = (signed __int64)&v2->m_infoBuffer;
    v73 = v2->m_infoBuffer.m_size;
    *(_DWORD *)&s.m_memSizeAndFlags = 0x1FFFF;
    s.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable';
    v71 = &v2->m_infoBuffer;
    v72 = &hkContainerHeapAllocator::s_alloc;
    v74 = 1;
    v49 = v2->m_infoBuffer.m_capacityAndFlags & 0x3FFFFFFF;
    v50 = v73 + 1;
    if ( v49 < v73 + 1 )
    {
      v51 = 2 * v49;
      if ( v50 < v51 )
        v50 = v51;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v2->m_infoBuffer,
        v50,
        1);
      v48 = (signed __int64)v71;
    }
    *(_BYTE *)(*(signed int *)(v48 + 8) + *(_QWORD *)v48) = 0;
    hkStructureLayout::hkStructureLayout((hkStructureLayout *)&result, &hkStructureLayout::MsvcWin32LayoutRules);
    hkObjectSerialize::writeObject(
      &s,
      (hkStructureLayout *)&result,
      1ui64,
      &data,
      &hkMonitorStreamStringMapClass,
      &globalFixups,
      0i64,
      (hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int>)2);
    s.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable';
    if ( !v74 )
    {
      v52 = (__int64)v71;
      if ( v71 )
      {
        v53 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v53[11] + 16i64))(v53[11], v52, 16i64);
      }
    }
    v54 = data.m_map.m_size - 1;
    s.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
    if ( data.m_map.m_size - 1 >= 0 )
    {
      v55 = &data.m_map.m_data[v54].m_string;
      do
      {
        hkStringPtr::~hkStringPtr(v55);
        v55 -= 2;
        --v54;
      }
      while ( v54 >= 0 );
    }
    data.m_map.m_size = 0;
    if ( data.m_map.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        data.m_map.m_data,
        16 * data.m_map.m_capacityAndFlags);
    data.m_map.m_data = 0i64;
    data.m_map.m_capacityAndFlags = 2147483648;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&map.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&map);
    if ( v31 >= 1 )
    {
      v56 = (signed int)flags.m_storage;
      v57 = v2->m_infoBuffer.m_size;
      v58 = v2->m_contexts.m_size;
      hkOArchive::write32u(*(hkOArchive **)&v2->m_selectable.m_bool, v31 + v58 + v57 + 4 * flags.m_storage + 13);
      hkOArchive::write8u(*(hkOArchive **)&v2->m_selectable.m_bool, 10);
      hkOArchive::write32(*(hkOArchive **)&v2->m_selectable.m_bool, v58);
      if ( v58 > 0 )
        hkOArchive::writeRaw(*(hkOArchive **)&v2->m_selectable.m_bool, v2->m_contexts.m_data, (unsigned int)v58);
      hkOArchive::write32(*(hkOArchive **)&v2->m_selectable.m_bool, v57);
      if ( v57 > 0 )
        hkOArchive::writeRaw(*(hkOArchive **)&v2->m_selectable.m_bool, v2->m_infoBuffer.m_data, (unsigned int)v57);
      hkOArchive::write32(*(hkOArchive **)&v2->m_selectable.m_bool, v56);
      for ( i = 0i64; i < v56; ++i )
      {
        v60 = *(_DWORD *)&v64[8 * i] - *(_DWORD *)&array[8 * i];
        hkOArchive::write32(*(hkOArchive **)&v2->m_selectable.m_bool, v60);
        if ( v60 > 0 )
          hkOArchive::writeRaw(
            *(hkOArchive **)&v2->m_selectable.m_bool,
            *(const void **)&array[8 * i],
            (unsigned int)v60);
      }
    }
    v65 = 0;
    if ( v66 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v64,
        8 * v66);
    v64 = 0i64;
    v66 = 2147483648;
    flags.m_storage = 0;
    if ( v63 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v63);
    array = 0i64;
    globalFixups.m_size = 0;
    v63 = 2147483648;
    if ( globalFixups.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        globalFixups.m_data,
        24 * (globalFixups.m_capacityAndFlags & 0x3FFFFFFF));
  }
}

