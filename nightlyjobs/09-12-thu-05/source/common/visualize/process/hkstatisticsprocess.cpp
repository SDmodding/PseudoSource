// File Line: 25
// RVA: 0xE78D10
hkProcess *__fastcall hkStatisticsProcess::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkStatisticsProcess *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkStatisticsProcess *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 112i64);
  if ( v3 && (hkStatisticsProcess::hkStatisticsProcess(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
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
void __fastcall hkStatisticsProcess::hkStatisticsProcess(
        hkStatisticsProcess *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkArray<char,hkContainerHeapAllocator> *p_m_infoBuffer; // rdi
  __int64 TicksPerSecond; // rax
  float v6; // xmm1_4
  int v7; // r9d
  int v8; // eax
  int v9; // eax
  __int64 v10; // rdi
  _QWORD **Value; // rax
  __int64 v12; // rax
  hkProcessContext **m_data; // rcx
  __int64 v14; // rdx
  char *v15; // r8
  hkProcessContext *v16; // rax
  hkArray<hkObjectSerialize::GlobalFixup,hkContainerHeapAllocator> globalFixups; // [rsp+40h] [rbp-29h] BYREF
  hkStreamWriter s; // [rsp+50h] [rbp-19h] BYREF
  hkArray<char,hkContainerHeapAllocator> *v19; // [rsp+60h] [rbp-9h]
  hkContainerHeapAllocator::Allocator *v20; // [rsp+68h] [rbp-1h]
  int m_size; // [rsp+70h] [rbp+7h]
  int v22; // [rsp+74h] [rbp+Bh]
  hkMonitorStreamFrameInfo data; // [rsp+78h] [rbp+Fh] BYREF
  int data_8; // [rsp+80h] [rbp+17h]
  __int64 data_12; // [rsp+84h] [rbp+1Bh]
  float data_20; // [rsp+8Ch] [rbp+23h]
  int data_24; // [rsp+90h] [rbp+27h]
  hkResult result; // [rsp+D0h] [rbp+67h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  p_m_infoBuffer = &this->m_infoBuffer;
  this->m_selectable.m_bool = 1;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkStatisticsProcess::`vftable{for `hkReferencedObject};
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkStatisticsProcess::`vftable{for `hkProcess};
  this->m_contexts.m_data = 0i64;
  this->m_contexts.m_size = 0;
  this->m_contexts.m_capacityAndFlags = 0x80000000;
  this->m_infoBuffer.m_data = 0i64;
  this->m_infoBuffer.m_size = 0;
  this->m_infoBuffer.m_capacityAndFlags = 0x80000000;
  this->m_strBuffer.m_data = 0i64;
  this->m_strBuffer.m_size = 0;
  this->m_strBuffer.m_capacityAndFlags = 0x80000000;
  hkMonitorStreamFrameInfo::hkMonitorStreamFrameInfo(&data);
  hkStringPtr::operator=(&data.m_heading, 0i64);
  data_12 = 1i64;
  data_8 = 0;
  TicksPerSecond = hkStopwatch::getTicksPerSecond();
  v6 = (float)(int)TicksPerSecond;
  if ( TicksPerSecond < 0 )
    v6 = v6 + 1.8446744e19;
  v7 = p_m_infoBuffer->m_size + 1;
  m_size = p_m_infoBuffer->m_size;
  globalFixups.m_data = 0i64;
  globalFixups.m_size = 0;
  globalFixups.m_capacityAndFlags = 0x80000000;
  data_20 = 1000.0 / v6;
  *(_DWORD *)&s.m_memSizeAndFlags = 0x1FFFF;
  s.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
  v19 = p_m_infoBuffer;
  data_24 = (int)FLOAT_1_0;
  v20 = &hkContainerHeapAllocator::s_alloc;
  v22 = 1;
  v8 = p_m_infoBuffer->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    if ( v7 < v9 )
      v7 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_infoBuffer->m_data, v7, 1);
    p_m_infoBuffer = v19;
  }
  p_m_infoBuffer->m_data[p_m_infoBuffer->m_size] = 0;
  hkStructureLayout::hkStructureLayout(
    (hkStructureLayout *)&result,
    (hkStructureLayout *)&hkStructureLayout::MsvcWin32LayoutRules);
  hkObjectSerialize::writeObject(
    &s,
    (hkStructureLayout *)&result,
    1ui64,
    (hkClass *)&data,
    &hkMonitorStreamFrameInfoClass,
    &globalFixups,
    0i64,
    (hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int>)2);
  s.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
  if ( !v22 )
  {
    v10 = (__int64)v19;
    if ( v19 )
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, __int64, __int64))(*Value[11] + 16i64))(Value[11], v10, 16i64);
    }
  }
  globalFixups.m_size = 0;
  s.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  if ( globalFixups.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      globalFixups.m_data,
      24 * (globalFixups.m_capacityAndFlags & 0x3FFFFFFF));
  if ( (this->m_contexts.m_capacityAndFlags & 0x3FFFFFFF) < contexts->m_size )
  {
    if ( this->m_contexts.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_contexts.m_data,
        8 * this->m_contexts.m_capacityAndFlags);
    result.m_enum = 8 * contexts->m_size;
    this->m_contexts.m_data = (hkProcessContext **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                     &hkContainerHeapAllocator::s_alloc,
                                                     &result);
    this->m_contexts.m_capacityAndFlags = result.m_enum / 8;
  }
  v12 = contexts->m_size;
  m_data = this->m_contexts.m_data;
  this->m_contexts.m_size = v12;
  v14 = v12;
  if ( (int)v12 > 0 )
  {
    v15 = (char *)((char *)contexts->m_data - (char *)m_data);
    do
    {
      v16 = *(hkProcessContext **)((char *)m_data++ + (_QWORD)v15);
      *(m_data - 1) = v16;
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
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // r8d

  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkStatisticsProcess::`vftable{for `hkReferencedObject};
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkStatisticsProcess::`vftable{for `hkProcess};
  m_capacityAndFlags = this->m_strBuffer.m_capacityAndFlags;
  this->m_strBuffer.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_strBuffer.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  this->m_strBuffer.m_data = 0i64;
  this->m_strBuffer.m_capacityAndFlags = 0x80000000;
  v3 = this->m_infoBuffer.m_capacityAndFlags;
  this->m_infoBuffer.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_infoBuffer.m_data,
      v3 & 0x3FFFFFFF);
  this->m_infoBuffer.m_data = 0i64;
  this->m_infoBuffer.m_capacityAndFlags = 0x80000000;
  v4 = this->m_contexts.m_capacityAndFlags;
  this->m_contexts.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_contexts.m_data,
      8 * v4);
  this->m_contexts.m_data = 0i64;
  this->m_contexts.m_capacityAndFlags = 0x80000000;
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkProcess::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 150
// RVA: 0xE78DA0
void __fastcall hkStatisticsProcess::step(hkStatisticsProcess *this, float frameTimeInMs)
{
  __int64 m_processHandler_low; // r11
  int v4; // edi
  _QWORD *v5; // r10
  void *v6; // r9
  __int64 v7; // r8
  __int64 v8; // rdx
  hkDebugDisplayHandler *m_displayHandler; // rbx
  hkDebugDisplayHandler *v10; // rcx
  __int64 v11; // r14
  hkDebugDisplayHandlerVtbl *vfptr; // rbx
  int v13; // eax
  _QWORD *v14; // rax
  __int64 v15; // rcx
  __int64 v16; // rdx
  __int64 v17; // r11
  __int64 v18; // rax
  hkDebugDisplayHandlerVtbl *v19; // rbx
  __int64 v20; // r8
  __int64 v21; // rcx
  hkResult *(__fastcall *skinGeometry)(hkDebugDisplayHandler *, hkResult *, unsigned __int64 *, int, hkMatrix4f *, int, hkMatrix4f *, int); // r8
  __int64 v23; // rdx
  __int64 v24; // rax
  __int64 *Value; // rax
  signed int m_storage; // ecx
  __int64 v27; // rdi
  __int64 v28; // rbx
  int v29; // ecx
  int v30; // r15d
  signed int v31; // edi
  _QWORD *v32; // rcx
  _QWORD *v33; // rdx
  __int64 v34; // rbx
  int v35; // eax
  int v36; // edx
  __int64 v37; // rcx
  _QWORD *v38; // rax
  int v39; // ebx
  int m_parent; // ecx
  const char *m_name; // r8
  hkMonitorStreamStringMap::StringMap *v42; // rax
  hkStringPtr *v43; // rdx
  int v44; // edx
  __int64 v45; // rcx
  _QWORD *v46; // rax
  int *p_m_infoBuffer; // rdx
  int v48; // eax
  int v49; // r9d
  int v50; // eax
  hkCustomAttributes *m_attributes; // rbx
  _QWORD **v52; // rax
  int v53; // ebx
  hkStringPtr *v54; // rdi
  __int64 v55; // r14
  int v56; // ebx
  int v57; // edi
  __int64 i; // rdi
  int v59; // ebx
  _QWORD *array; // [rsp+30h] [rbp-49h] BYREF
  hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flags; // [rsp+38h] [rbp-41h]
  int v62; // [rsp+3Ch] [rbp-3Dh]
  _QWORD *v63; // [rsp+40h] [rbp-39h] BYREF
  int addTextureSearchPath; // [rsp+48h] [rbp-31h]
  int v65; // [rsp+4Ch] [rbp-2Dh]
  hkClass data; // [rsp+50h] [rbp-29h] BYREF
  int m_size; // [rsp+A0h] [rbp+27h]
  int v68; // [rsp+A4h] [rbp+2Bh]
  hkResult result; // [rsp+E0h] [rbp+67h] BYREF

  if ( *(_QWORD *)&this->m_selectable.m_bool )
  {
    m_processHandler_low = SLODWORD(this->m_processHandler);
    v4 = 0x80000000;
    *(_QWORD *)&data.m_numDeclaredEnums = 0i64;
    data.m_declaredMembers = (hkClassMember *)0x8000000000000000i64;
    v5 = 0i64;
    array = 0i64;
    flags.m_storage = 0;
    v6 = 0i64;
    v63 = 0i64;
    addTextureSearchPath = 0;
    v7 = 0i64;
    v8 = 0i64;
    v62 = 0x80000000;
    v65 = 0x80000000;
    if ( m_processHandler_low <= 0 )
      goto LABEL_19;
    m_displayHandler = this->m_displayHandler;
    v10 = m_displayHandler;
    while ( *(int *)&v10->vfptr->gap8[16] <= 0 )
    {
      ++v8;
      v7 = (unsigned int)(v7 + 1);
      ++v10;
      if ( v8 >= m_processHandler_low )
        goto LABEL_19;
    }
    v11 = (int)v7;
    vfptr = m_displayHandler[v11].vfptr;
    v13 = *(_DWORD *)&vfptr->gap8[16];
    if ( v13 > 0 )
    {
      result.m_enum = 8 * v13;
      v14 = (_QWORD *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, __int64, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                        &hkContainerHeapAllocator::s_alloc,
                        &result,
                        v7,
                        0i64);
      v4 = v65;
      v6 = v63;
      v5 = v14;
      array = v14;
      v62 = result.m_enum / 8;
    }
    v15 = *(int *)&vfptr->gap8[16];
    v16 = 0i64;
    flags.m_storage = v15;
    v17 = *(_QWORD *)&vfptr->gap8[8];
    if ( (int)v15 > 0 )
    {
      do
      {
        v18 = *(_QWORD *)(v17 + 8 * v16++);
        v5[v16 - 1] = v18;
      }
      while ( v16 < v15 );
      v4 = v65;
      v6 = v63;
    }
    v19 = this->m_displayHandler[v11].vfptr;
    v20 = v4 & 0x3FFFFFFF;
    if ( (int)v20 < SLODWORD(v19->addTextureSearchPath) )
    {
      if ( v4 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v6, 8 * v4);
      result.m_enum = 8 * LODWORD(v19->addTextureSearchPath);
      v6 = (void *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, __int64, void *))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                     &hkContainerHeapAllocator::s_alloc,
                     &result,
                     v20,
                     v6);
      v63 = v6;
      v65 = result.m_enum / 8;
    }
    v21 = 0i64;
    addTextureSearchPath = (int)v19->addTextureSearchPath;
    skinGeometry = v19->skinGeometry;
    v23 = addTextureSearchPath;
    if ( addTextureSearchPath > 0 )
    {
      do
      {
        v24 = *((_QWORD *)skinGeometry + v21++);
        *((_QWORD *)v6 + v21 - 1) = v24;
      }
      while ( v21 < v23 );
    }
    if ( !flags.m_storage )
    {
LABEL_19:
      Value = (__int64 *)TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      m_storage = flags.m_storage;
      v27 = *Value;
      v28 = Value[1];
      if ( flags.m_storage == (v62 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
        m_storage = flags.m_storage;
      }
      array[m_storage] = v27;
      v29 = addTextureSearchPath;
      ++flags.m_storage;
      if ( addTextureSearchPath == (v65 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v63, 8);
        v29 = addTextureSearchPath;
      }
      v63[v29] = v28;
      ++addTextureSearchPath;
    }
    this->m_infoBuffer.m_size = 0;
    v30 = 0;
    *(_QWORD *)&data.m_objectSize = 0i64;
    data.m_declaredEnums = (hkClassEnum *)0xFFFFFFFF00000000i64;
    hkMonitorStreamStringMap::hkMonitorStreamStringMap((hkMonitorStreamStringMap *)&data);
    v31 = 0;
    if ( (int)flags.m_storage > 0 )
    {
      v32 = array;
      v33 = v63;
      v34 = 0i64;
      do
      {
        hkMonitorStreamAnalyzer::extractStringMap(
          (char *)v32[v34],
          (const char *)v33[v34],
          (hkPointerMap<void const *,char const *,hkContainerHeapAllocator> *)&data.m_objectSize);
        v33 = v63;
        v32 = array;
        v35 = v63[v34];
        ++v31;
        v30 += v35 - LODWORD(array[v34++]);
      }
      while ( v31 < (int)flags.m_storage );
    }
    v36 = 0;
    v37 = 0i64;
    if ( SHIDWORD(data.m_declaredEnums) >= 0 )
    {
      v38 = *(_QWORD **)&data.m_objectSize;
      do
      {
        if ( *v38 != -1i64 )
          break;
        ++v37;
        ++v36;
        v38 += 2;
      }
      while ( v37 <= SHIDWORD(data.m_declaredEnums) );
    }
    v39 = v36;
    if ( v36 <= SHIDWORD(data.m_declaredEnums) )
    {
      do
      {
        m_parent = (int)data.m_parent;
        if ( LODWORD(data.m_parent) == (HIDWORD(data.m_parent) & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&data.m_name, 16);
          m_parent = (int)data.m_parent;
        }
        m_name = data.m_name;
        v42 = (hkMonitorStreamStringMap::StringMap *)&data.m_name[16 * m_parent];
        if ( v42 )
        {
          hkMonitorStreamStringMap::StringMap::StringMap(v42);
          m_parent = (int)data.m_parent;
          m_name = data.m_name;
        }
        LODWORD(data.m_parent) = m_parent + 1;
        v43 = (hkStringPtr *)&m_name[16 * m_parent];
        v43->m_stringAndFlag = *(const char **)(*(_QWORD *)&data.m_objectSize + 16i64 * v39);
        hkStringPtr::operator=(v43 + 1, *(const char **)(*(_QWORD *)&data.m_objectSize + 16i64 * v39 + 8));
        v44 = v39 + 1;
        v45 = v39 + 1;
        if ( v45 <= SHIDWORD(data.m_declaredEnums) )
        {
          v46 = (_QWORD *)(*(_QWORD *)&data.m_objectSize + 16i64 * v44);
          do
          {
            if ( *v46 != -1i64 )
              break;
            ++v45;
            ++v44;
            v46 += 2;
          }
          while ( v45 <= SHIDWORD(data.m_declaredEnums) );
        }
        v39 = v44;
      }
      while ( v44 <= SHIDWORD(data.m_declaredEnums) );
    }
    p_m_infoBuffer = (int *)&this->m_infoBuffer;
    m_size = this->m_infoBuffer.m_size;
    LODWORD(data.m_defaults) = 0x1FFFF;
    *(_QWORD *)&data.m_numDeclaredMembers = &hkArrayStreamWriter::`vftable;
    data.m_attributes = (hkCustomAttributes *)&this->m_infoBuffer;
    *(_QWORD *)&data.m_flags.m_storage = &hkContainerHeapAllocator::s_alloc;
    v68 = 1;
    v48 = this->m_infoBuffer.m_capacityAndFlags & 0x3FFFFFFF;
    v49 = m_size + 1;
    if ( v48 < m_size + 1 )
    {
      v50 = 2 * v48;
      if ( v49 < v50 )
        v49 = v50;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_infoBuffer.m_data,
        v49,
        1);
      p_m_infoBuffer = (int *)data.m_attributes;
    }
    *(_BYTE *)(p_m_infoBuffer[2] + *(_QWORD *)p_m_infoBuffer) = 0;
    hkStructureLayout::hkStructureLayout(
      (hkStructureLayout *)&result,
      (hkStructureLayout *)&hkStructureLayout::MsvcWin32LayoutRules);
    hkObjectSerialize::writeObject(
      (hkStreamWriter *)&data.m_numDeclaredMembers,
      (hkStructureLayout *)&result,
      1ui64,
      &data,
      &hkMonitorStreamStringMapClass,
      (hkArray<hkObjectSerialize::GlobalFixup,hkContainerHeapAllocator> *)&data.m_numDeclaredEnums,
      0i64,
      (hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int>)2);
    *(_QWORD *)&data.m_numDeclaredMembers = &hkArrayStreamWriter::`vftable;
    if ( !v68 )
    {
      m_attributes = data.m_attributes;
      if ( data.m_attributes )
      {
        v52 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkCustomAttributes *, __int64))(*v52[11] + 16i64))(
          v52[11],
          m_attributes,
          16i64);
      }
    }
    v53 = LODWORD(data.m_parent) - 1;
    *(_QWORD *)&data.m_numDeclaredMembers = &hkBaseObject::`vftable;
    if ( LODWORD(data.m_parent) - 1 >= 0 )
    {
      v54 = (hkStringPtr *)&data.m_name[16 * v53 + 8];
      do
      {
        hkStringPtr::~hkStringPtr(v54);
        v54 -= 2;
        --v53;
      }
      while ( v53 >= 0 );
    }
    LODWORD(data.m_parent) = 0;
    if ( SHIDWORD(data.m_parent) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        (void *)data.m_name,
        16 * HIDWORD(data.m_parent));
    data.m_name = 0i64;
    HIDWORD(data.m_parent) = 0x80000000;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&data.m_objectSize,
      &hkContainerHeapAllocator::s_alloc);
    _((AMD_HD3D *)&data.m_objectSize);
    if ( v30 >= 1 )
    {
      v55 = (int)flags.m_storage;
      v56 = this->m_infoBuffer.m_size;
      v57 = this->m_contexts.m_size;
      hkOArchive::write32u(*(hkOArchive **)&this->m_selectable.m_bool, v30 + v57 + v56 + 4 * flags.m_storage + 13);
      hkOArchive::write8u(*(hkOArchive **)&this->m_selectable.m_bool, 10);
      hkOArchive::write32(*(hkOArchive **)&this->m_selectable.m_bool, v57);
      if ( v57 > 0 )
        hkOArchive::writeRaw(*(hkOArchive **)&this->m_selectable.m_bool, this->m_contexts.m_data, (unsigned int)v57);
      hkOArchive::write32(*(hkOArchive **)&this->m_selectable.m_bool, v56);
      if ( v56 > 0 )
        hkOArchive::writeRaw(*(hkOArchive **)&this->m_selectable.m_bool, this->m_infoBuffer.m_data, (unsigned int)v56);
      hkOArchive::write32(*(hkOArchive **)&this->m_selectable.m_bool, v55);
      for ( i = 0i64; i < v55; ++i )
      {
        v59 = LODWORD(v63[i]) - LODWORD(array[i]);
        hkOArchive::write32(*(hkOArchive **)&this->m_selectable.m_bool, v59);
        if ( v59 > 0 )
          hkOArchive::writeRaw(*(hkOArchive **)&this->m_selectable.m_bool, (const void *)array[i], (unsigned int)v59);
      }
    }
    addTextureSearchPath = 0;
    if ( v65 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v63, 8 * v65);
    v63 = 0i64;
    v65 = 0x80000000;
    flags.m_storage = 0;
    if ( v62 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v62);
    array = 0i64;
    LODWORD(data.m_declaredMembers) = 0;
    v62 = 0x80000000;
    if ( SHIDWORD(data.m_declaredMembers) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)&data.m_numDeclaredEnums,
        24 * (HIDWORD(data.m_declaredMembers) & 0x3FFFFFFF));
  }
}

