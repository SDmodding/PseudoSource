// File Line: 51
// RVA: 0x12DF740
void __fastcall hkaiAbstractFaceCutter::hkaiAbstractFaceCutter(hkaiAbstractFaceCutter *this, bool useNewCutter)
{
  int v3; // edi
  hkLifoAllocator *Value; // rax
  char *m_cur; // rcx
  int v7; // r8d
  char *v8; // rdx
  int v9; // eax
  int v10; // eax
  int v11; // r9d
  hkaiNewFaceCutter *m_data; // rcx
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  v3 = 1536;
  this->m_buffer.m_capacityAndFlags = 0x80000000;
  if ( useNewCutter )
    v3 = 352;
  this->m_buffer.m_data = 0i64;
  this->m_buffer.m_size = 0;
  this->m_buffer.m_initialCapacity = v3;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)Value->m_cur;
  v7 = (v3 + 127) & 0xFFFFFF80;
  v8 = &m_cur[v7];
  if ( v7 > Value->m_slabSize || v8 > Value->m_end )
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v7);
  else
    Value->m_cur = v8;
  this->m_buffer.m_data = m_cur;
  this->m_buffer.m_localMemory = m_cur;
  this->m_buffer.m_capacityAndFlags = v3 | 0x80000000;
  this->m_useNewCutter = useNewCutter;
  v9 = this->m_buffer.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < v3 )
  {
    v10 = 2 * v9;
    v11 = v3;
    if ( v3 < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_buffer.m_data, v11, 1);
  }
  this->m_buffer.m_size = v3;
  m_data = (hkaiNewFaceCutter *)this->m_buffer.m_data;
  if ( this->m_useNewCutter )
  {
    if ( m_data )
      hkaiNewFaceCutter::hkaiNewFaceCutter(m_data);
  }
  else if ( m_data )
  {
    hkaiFaceCutter::hkaiFaceCutter((hkaiFaceCutter *)m_data);
  }
}

// File Line: 64
// RVA: 0x12DF850
void __fastcall hkaiAbstractFaceCutter::~hkaiAbstractFaceCutter(hkaiAbstractFaceCutter *this)
{
  bool v1; // zf
  char *m_data; // rcx
  char *m_localMemory; // rsi
  signed int v5; // ebx
  hkLifoAllocator *Value; // rax
  int v7; // r8d
  int m_capacityAndFlags; // r8d

  v1 = !this->m_useNewCutter;
  m_data = this->m_buffer.m_data;
  if ( v1 )
    hkaiFaceCutter::~hkaiFaceCutter((hkaiFaceCutter *)m_data);
  else
    hkaiNewFaceCutterUtil::State::~State((hkaiNewFaceCutterUtil::State *)m_data);
  m_localMemory = this->m_buffer.m_localMemory;
  if ( m_localMemory == this->m_buffer.m_data )
    this->m_buffer.m_size = 0;
  v5 = (this->m_buffer.m_initialCapacity + 127) & 0xFFFFFF80;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (v5 + 15) & 0xFFFFFFF0;
  if ( v5 > Value->m_slabSize || &m_localMemory[v7] != Value->m_cur || Value->m_firstNonLifoEnd == m_localMemory )
    hkLifoAllocator::slowBlockFree(Value, m_localMemory, v7);
  else
    Value->m_cur = m_localMemory;
  m_capacityAndFlags = this->m_buffer.m_capacityAndFlags;
  this->m_buffer.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_buffer.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  this->m_buffer.m_data = 0i64;
  this->m_buffer.m_capacityAndFlags = 0x80000000;
}

// File Line: 78
// RVA: 0x12DF460
void __fastcall hkaiAbstractFaceCutter::reset(hkaiAbstractFaceCutter *this, unsigned int faceKey)
{
  bool v2; // zf
  char *m_data; // rcx

  v2 = !this->m_useNewCutter;
  m_data = this->m_buffer.m_data;
  if ( v2 )
    hkaiFaceCutter::reset((hkaiFaceCutter *)m_data, faceKey);
  else
    hkaiNewFaceCutter::reset((hkaiNewFaceCutter *)m_data, faceKey);
}

// File Line: 83
// RVA: 0x12DF480
void __fastcall hkaiAbstractFaceCutter::setFace(
        hkaiAbstractFaceCutter *this,
        hkaiNavMeshInstance *origMesh,
        hkVector4f *up,
        bool isWallClimbing,
        unsigned int faceKey,
        hkSimdFloat32 *regionExpansion,
        hkArrayBase<hkVector4f> *faceVertsOut,
        hkArrayBase<int> *indexRemap)
{
  _QWORD *Value; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r10
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  hkaiNewFaceCutter *m_data; // rcx
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  _QWORD *v21; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)Value[1];
  v14 = Value;
  if ( (unsigned __int64)v13 < Value[3] )
  {
    *v13 = "TtaddFaceLoop";
    v15 = __rdtsc();
    v16 = v13 + 2;
    *((_DWORD *)v16 - 2) = v15;
    v14[1] = v16;
  }
  m_data = (hkaiNewFaceCutter *)this->m_buffer.m_data;
  if ( this->m_useNewCutter )
    hkaiNewFaceCutter::setFace(m_data, origMesh, up, isWallClimbing, faceKey, regionExpansion, faceVertsOut, indexRemap);
  else
    hkaiFaceCutter::setFace(
      (hkaiFaceCutter *)m_data,
      origMesh,
      up,
      isWallClimbing,
      faceKey,
      regionExpansion,
      faceVertsOut,
      indexRemap);
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v20 = __rdtsc();
    v21 = v19 + 2;
    *((_DWORD *)v21 - 2) = v20;
    v18[1] = v21;
  }
}

// File Line: 89
// RVA: 0x12DF580
__int64 __fastcall hkaiAbstractFaceCutter::addSilhouette(
        hkaiAbstractFaceCutter *this,
        hkVector4f *points,
        int loopSize,
        int materialId)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkaiNewFaceCutter *m_data; // rcx
  unsigned int v14; // eax
  unsigned int v15; // ebx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtaddSilLoop";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  m_data = (hkaiNewFaceCutter *)this->m_buffer.m_data;
  if ( this->m_useNewCutter )
    v14 = hkaiNewFaceCutter::addSilhouette(m_data, points, loopSize, materialId);
  else
    v14 = hkaiFaceCutter::addSilhouette((hkaiFaceCutter *)m_data, points, loopSize, materialId);
  v15 = v14;
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v18 = __rdtsc();
    v19 = v17 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v16[1] = v19;
  }
  return v15;
}

// File Line: 95
// RVA: 0x12DF650
__int64 __fastcall hkaiAbstractFaceCutter::computeConvexDecomposition(
        hkaiAbstractFaceCutter *this,
        hkaiFaceCutResults *results,
        hkArrayBase<hkVector4f> *faceVertices,
        hkArrayBase<int> *indexRemap)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkaiNewFaceCutter *m_data; // rcx
  unsigned int v14; // eax
  unsigned int v15; // ebx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtcomputeCxDecompOfCutFace";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  m_data = (hkaiNewFaceCutter *)this->m_buffer.m_data;
  if ( this->m_useNewCutter )
    v14 = hkaiNewFaceCutter::computeConvexDecomposition(m_data, results, faceVertices, indexRemap);
  else
    v14 = hkaiFaceCutter::computeConvexDecomposition((hkaiFaceCutter *)m_data, results, faceVertices, indexRemap);
  v15 = v14;
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v18 = __rdtsc();
    v19 = v17 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v16[1] = v19;
  }
  return v15;
}

// File Line: 101
// RVA: 0x12DF720
hkVector4f *__fastcall hkaiAbstractFaceCutter::getUp(hkaiAbstractFaceCutter *this)
{
  hkVector4f *result; // rax

  result = (hkVector4f *)this->m_buffer.m_data;
  if ( !this->m_useNewCutter )
    result += 90;
  return result;
}

