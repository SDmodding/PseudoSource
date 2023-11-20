// File Line: 51
// RVA: 0x12DF740
void __fastcall hkaiAbstractFaceCutter::hkaiAbstractFaceCutter(hkaiAbstractFaceCutter *this, bool useNewCutter)
{
  hkaiAbstractFaceCutter *v2; // rbx
  signed int v3; // edi
  bool v4; // si
  char *v5; // rcx
  hkLifoAllocator *v6; // rax
  int v7; // er8
  char *v8; // rdx
  int v9; // eax
  int v10; // eax
  int v11; // er9
  hkaiNewFaceCutter *v12; // rcx
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this;
  v3 = 1536;
  v4 = useNewCutter;
  this->m_buffer.m_capacityAndFlags = 2147483648;
  if ( useNewCutter )
    v3 = 352;
  v5 = 0i64;
  v2->m_buffer.m_data = 0i64;
  v2->m_buffer.m_size = 0;
  v2->m_buffer.m_initialCapacity = v3;
  if ( v3 )
  {
    v6 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (char *)v6->m_cur;
    v7 = (v3 + 127) & 0xFFFFFF80;
    v8 = &v5[v7];
    if ( v7 > v6->m_slabSize || v8 > v6->m_end )
      v5 = (char *)hkLifoAllocator::allocateFromNewSlab(v6, v7);
    else
      v6->m_cur = v8;
  }
  v2->m_buffer.m_data = v5;
  v2->m_buffer.m_localMemory = v5;
  v2->m_buffer.m_capacityAndFlags = v3 | 0x80000000;
  v2->m_useNewCutter = v4;
  v9 = v2->m_buffer.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < v3 )
  {
    v10 = 2 * v9;
    v11 = v3;
    if ( v3 < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, v11, 1);
  }
  v2->m_buffer.m_size = v3;
  v12 = (hkaiNewFaceCutter *)v2->m_buffer.m_data;
  if ( v2->m_useNewCutter )
  {
    if ( v12 )
      hkaiNewFaceCutter::hkaiNewFaceCutter(v12);
  }
  else if ( v12 )
  {
    hkaiFaceCutter::hkaiFaceCutter((hkaiFaceCutter *)v12);
  }
}

// File Line: 64
// RVA: 0x12DF850
void __fastcall hkaiAbstractFaceCutter::~hkaiAbstractFaceCutter(hkaiAbstractFaceCutter *this)
{
  bool v1; // zf
  hkaiAbstractFaceCutter *v2; // rdi
  char *v3; // rcx
  char *v4; // rsi
  signed int v5; // ebx
  hkLifoAllocator *v6; // rax
  int v7; // er8
  int v8; // er8

  v1 = this->m_useNewCutter == 0;
  v2 = this;
  v3 = this->m_buffer.m_data;
  if ( v1 )
    hkaiFaceCutter::~hkaiFaceCutter((hkaiFaceCutter *)v3);
  else
    hkaiNewFaceCutterUtil::State::~State((hkaiNewFaceCutterUtil::State *)v3);
  v4 = v2->m_buffer.m_localMemory;
  if ( v4 == v2->m_buffer.m_data )
    v2->m_buffer.m_size = 0;
  v5 = (v2->m_buffer.m_initialCapacity + 127) & 0xFFFFFF80;
  v6 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (v5 + 15) & 0xFFFFFFF0;
  if ( v5 > v6->m_slabSize || &v4[v7] != v6->m_cur || v6->m_firstNonLifoEnd == v4 )
    hkLifoAllocator::slowBlockFree(v6, v4, v7);
  else
    v6->m_cur = v4;
  v8 = v2->m_buffer.m_capacityAndFlags;
  v2->m_buffer.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_buffer.m_data,
      v8 & 0x3FFFFFFF);
  v2->m_buffer.m_data = 0i64;
  v2->m_buffer.m_capacityAndFlags = 2147483648;
}

// File Line: 78
// RVA: 0x12DF460
void __fastcall hkaiAbstractFaceCutter::reset(hkaiAbstractFaceCutter *this, unsigned int faceKey)
{
  JUMPOUT(this->m_useNewCutter != 0, hkaiNewFaceCutter::reset);
  hkaiFaceCutter::reset((hkaiFaceCutter *)this->m_buffer.m_data, faceKey);
}

// File Line: 83
// RVA: 0x12DF480
void __fastcall hkaiAbstractFaceCutter::setFace(hkaiAbstractFaceCutter *this, hkaiNavMeshInstance *origMesh, hkVector4f *up, bool isWallClimbing, unsigned int faceKey, hkSimdFloat32 *regionExpansion, hkArrayBase<hkVector4f> *faceVertsOut, hkArrayBase<int> *indexRemap)
{
  hkaiAbstractFaceCutter *v8; // rbx
  bool v9; // di
  hkVector4f *v10; // rsi
  hkaiNavMeshInstance *v11; // rbp
  _QWORD *v12; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r10
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx
  hkaiNewFaceCutter *v17; // rcx
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  signed __int64 v21; // rcx

  v8 = this;
  v9 = isWallClimbing;
  v10 = up;
  v11 = origMesh;
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  v14 = v12;
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "TtaddFaceLoop";
    v15 = __rdtsc();
    v16 = (signed __int64)(v13 + 2);
    *(_DWORD *)(v16 - 8) = v15;
    v14[1] = v16;
  }
  v17 = (hkaiNewFaceCutter *)v8->m_buffer.m_data;
  if ( v8->m_useNewCutter )
    hkaiNewFaceCutter::setFace(v17, v11, v10, v9, faceKey, regionExpansion, faceVertsOut, indexRemap);
  else
    hkaiFaceCutter::setFace((hkaiFaceCutter *)v17, v11, v10, v9, faceKey, regionExpansion, faceVertsOut, indexRemap);
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v20 = __rdtsc();
    v21 = (signed __int64)(v19 + 2);
    *(_DWORD *)(v21 - 8) = v20;
    v18[1] = v21;
  }
}

// File Line: 89
// RVA: 0x12DF580
__int64 __fastcall hkaiAbstractFaceCutter::addSilhouette(hkaiAbstractFaceCutter *this, hkVector4f *points, int loopSize, int materialId)
{
  hkaiAbstractFaceCutter *v4; // rbx
  int v5; // edi
  int v6; // esi
  hkVector4f *v7; // rbp
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkaiNewFaceCutter *v13; // rcx
  unsigned int v14; // eax
  unsigned int v15; // ebx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx

  v4 = this;
  v5 = materialId;
  v6 = loopSize;
  v7 = points;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtaddSilLoop";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = (hkaiNewFaceCutter *)v4->m_buffer.m_data;
  if ( v4->m_useNewCutter )
    v14 = hkaiNewFaceCutter::addSilhouette(v13, v7, v6, v5);
  else
    v14 = hkaiFaceCutter::addSilhouette((hkaiFaceCutter *)v13, v7, v6, v5);
  v15 = v14;
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v18 = __rdtsc();
    v19 = (signed __int64)(v17 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v16[1] = v19;
  }
  return v15;
}

// File Line: 95
// RVA: 0x12DF650
__int64 __fastcall hkaiAbstractFaceCutter::computeConvexDecomposition(hkaiAbstractFaceCutter *this, hkaiFaceCutResults *results, hkArrayBase<hkVector4f> *faceVertices, hkArrayBase<int> *indexRemap)
{
  hkaiAbstractFaceCutter *v4; // rbx
  hkArrayBase<int> *v5; // rdi
  hkArrayBase<hkVector4f> *v6; // rsi
  hkaiFaceCutResults *v7; // rbp
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkaiNewFaceCutter *v13; // rcx
  unsigned int v14; // eax
  unsigned int v15; // ebx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx

  v4 = this;
  v5 = indexRemap;
  v6 = faceVertices;
  v7 = results;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtcomputeCxDecompOfCutFace";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = (hkaiNewFaceCutter *)v4->m_buffer.m_data;
  if ( v4->m_useNewCutter )
    v14 = hkaiNewFaceCutter::computeConvexDecomposition(v13, v7, v6, v5);
  else
    v14 = hkaiFaceCutter::computeConvexDecomposition((hkaiFaceCutter *)v13, v7, v6, v5);
  v15 = v14;
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v18 = __rdtsc();
    v19 = (signed __int64)(v17 + 2);
    *(_DWORD *)(v19 - 8) = v18;
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

