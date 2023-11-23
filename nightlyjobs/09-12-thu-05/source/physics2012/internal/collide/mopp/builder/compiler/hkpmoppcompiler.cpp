// File Line: 28
// RVA: 0xDB6C70
void __fastcall hkpMoppCompiler::hkpMoppCompiler(hkpMoppCompiler *this, hkpMoppMeshType meshType)
{
  hkpMoppSplitter::hkpMoppSplitParams::hkpMoppSplitParams(&this->m_splitParams, meshType);
  hkpMoppCostFunction::hkpMoppSplitCostParams::hkpMoppSplitCostParams(&this->m_splitCostParams, meshType);
  this->m_assemblerParams.m_relativeFitToleranceOfInternalNodes = 0.5;
  this->m_assemblerParams.m_absoluteFitToleranceOfAxisAlignedTriangles = (hkVector4f)_xmm;
  this->m_assemblerParams.m_absoluteFitToleranceOfInternalNodes = 0.2;
  this->m_assemblerParams.m_absoluteFitToleranceOfTriangles = 1.0;
  this->m_assemblerParams.m_groupLevels = 5;
  this->m_assemblerParams.m_interleavedBuildingEnabled.m_bool = 1;
  this->m_chunkInfo = 0i64;
}

// File Line: 36
// RVA: 0xDB6CE0
void __fastcall hkpMoppCompiler::~hkpMoppCompiler(hkpMoppCompiler *this)
{
  ;
}

// File Line: 40
// RVA: 0xDB6CF0
void __fastcall hkpMoppCompiler::setSplitParams(hkpMoppCompiler *this, hkpMoppSplitter::hkpMoppSplitParams *sp)
{
  this->m_splitParams = *sp;
}

// File Line: 45
// RVA: 0xDB6D20
void __fastcall hkpMoppCompiler::setCostParams(hkpMoppCompiler *this, hkpMoppCostFunction::hkpMoppSplitCostParams *sp)
{
  this->m_splitCostParams = *sp;
}

// File Line: 51
// RVA: 0xDB6D50
void __fastcall hkpMoppCompiler::setAssemblerParams(
        hkpMoppCompiler *this,
        hkpMoppAssembler::hkpMoppAssemblerParams *ap)
{
  this->m_assemblerParams.m_relativeFitToleranceOfInternalNodes = ap->m_relativeFitToleranceOfInternalNodes;
  this->m_assemblerParams.m_absoluteFitToleranceOfInternalNodes = ap->m_absoluteFitToleranceOfInternalNodes;
  this->m_assemblerParams.m_absoluteFitToleranceOfTriangles = ap->m_absoluteFitToleranceOfTriangles;
  this->m_assemblerParams.m_absoluteFitToleranceOfAxisAlignedTriangles = ap->m_absoluteFitToleranceOfAxisAlignedTriangles;
  this->m_assemblerParams.m_groupLevels = ap->m_groupLevels;
  this->m_assemblerParams.m_interleavedBuildingEnabled.m_bool = ap->m_interleavedBuildingEnabled.m_bool;
}

// File Line: 58
// RVA: 0xDB6D80
void __fastcall hkpMoppCompiler::enableInterleavedBuilding(hkpMoppCompiler *this, char enabledFlag)
{
  this->m_splitParams.m_interleavedBuildingEnabled.m_bool = enabledFlag;
  this->m_assemblerParams.m_interleavedBuildingEnabled.m_bool = enabledFlag;
}

// File Line: 64
// RVA: 0xDB6D90
__int64 __fastcall hkpMoppCompiler::calculateRequiredBufferSize(hkpMoppCompiler *this, hkpMoppMediator *mediator)
{
  int v3; // edx
  int v4; // eax

  v3 = this->m_splitParams.m_maxPrimitiveSplits
     + ((__int64 (__fastcall *)(hkpMoppMediator *))mediator->vfptr[2].__vecDelDtor)(mediator);
  v4 = 5 * v3;
  if ( this->m_splitParams.m_interleavedBuildingEnabled.m_bool )
    v3 = 4096;
  return (unsigned int)(264 * v3 + 4 * v4);
}

// File Line: 85
// RVA: 0xDB72C0
__int64 __fastcall readChunkIdFromCode(const char *PC)
{
  return *((unsigned __int8 *)PC + 4)
       + ((*((unsigned __int8 *)PC + 3) + ((*((unsigned __int8 *)PC + 2) + (*((unsigned __int8 *)PC + 1) << 8)) << 8)) << 8);
}

// File Line: 92
// RVA: 0xDB72F0
void __fastcall writeChunkOffsetIntoCode(char *PC, unsigned int offset)
{
  PC[4] = offset;
  PC[1] = HIBYTE(offset);
  PC[2] = BYTE2(offset);
  PC[3] = BYTE1(offset);
}

// File Line: 106
// RVA: 0xDB6DD0
hkpMoppCode *__fastcall hkpMoppCompiler::compile(
        hkpMoppCompiler *this,
        hkpMoppMediator *mediator,
        hkpMoppCompilerPrimitive *buffer,
        int bufferSize)
{
  int v8; // esi
  hkBaseObjectVtbl *vfptr; // rbx
  unsigned int v10; // edi
  __int64 v11; // rax
  int v12; // eax
  int v13; // edi
  hkpMoppCompilerPrimitive *v14; // rdi
  hkMemoryAllocator **Value; // rax
  __int64 v16; // rdx
  hkBaseObjectVtbl *v17; // rax
  hkpMoppTreeNode *v18; // rbx
  hkMemoryAllocator **v19; // rax
  hkpMoppCode *v20; // rsi
  hkpMoppCompilerChunkInfo *m_chunkInfo; // rcx
  hkpMoppCode *v22; // r15
  __int64 v23; // rsi
  _DWORD *v24; // rax
  int v25; // edi
  int v26; // r9d
  __int64 v27; // r8
  __int64 v28; // rdi
  hkpMoppCompilerChunkInfo *v29; // rax
  unsigned int m_maxChunkSize; // ecx
  unsigned int v31; // ecx
  int v32; // r15d
  __int64 v33; // r12
  hkpMoppCompilerChunkInfo::Chunk *m_data; // rbx
  hkpMoppCodeGenerator *m_code; // rdi
  __int64 v36; // r10
  int ChunkIdFromCode; // eax
  char *v38; // r9
  int v39; // r11d
  __int64 v40; // r10
  int v41; // ebx
  _QWORD **v42; // rax
  __int64 v43; // rax
  hkArray<unsigned char,hkContainerHeapAllocator> *p_m_data; // r13
  int v45; // eax
  int v46; // eax
  int v47; // r9d
  __int64 m_size; // rdi
  int v49; // eax
  char *v50; // rdi
  __int64 v51; // r12
  int v52; // r15d
  char *v53; // rdi
  hkpMoppCode *v54; // rbx
  _DWORD *array; // [rsp+30h] [rbp-D0h] BYREF
  int v57; // [rsp+38h] [rbp-C8h]
  int v58; // [rsp+3Ch] [rbp-C4h]
  hkpMoppTreeNode *v59; // [rsp+40h] [rbp-C0h]
  hkpMoppSplitter::hkpMoppScratchArea temp; // [rsp+48h] [rbp-B8h] BYREF
  hkpMoppCodeGenerator code; // [rsp+60h] [rbp-A0h] BYREF
  hkpMoppCostFunction costFunction; // [rsp+90h] [rbp-70h] BYREF
  hkpMoppDefaultAssembler v63; // [rsp+C0h] [rbp-40h] BYREF
  hkpMoppDefaultSplitter v64; // [rsp+160h] [rbp+60h] BYREF
  hkResult result; // [rsp+220h] [rbp+120h] BYREF
  hkpMoppCode *v66; // [rsp+228h] [rbp+128h]
  __int64 v67; // [rsp+230h] [rbp+130h]

  v8 = this->m_splitParams.m_maxPrimitiveSplits
     + ((__int64 (__fastcall *)(hkpMoppMediator *))mediator->vfptr[2].__vecDelDtor)(mediator);
  hkpMoppCodeGenerator::hkpMoppCodeGenerator(&code, 12 * v8);
  hkpMoppCostFunction::hkpMoppCostFunction(&costFunction, &this->m_splitCostParams);
  hkpMoppDefaultAssembler::hkpMoppDefaultAssembler(&v63, &this->m_assemblerParams, &code, mediator);
  vfptr = mediator->vfptr;
  v63.m_chunkInfo = this->m_chunkInfo;
  v10 = ((__int64 (__fastcall *)(hkpMoppDefaultAssembler *))v63.vfptr[1].__first_virtual_table_function__)(&v63);
  v11 = ((__int64 (__fastcall *)(hkpMoppDefaultAssembler *))v63.vfptr[2].__vecDelDtor)(&v63);
  ((void (__fastcall *)(hkpMoppMediator *, __int64, _QWORD))vfptr[1].__first_virtual_table_function__)(
    mediator,
    v11,
    v10);
  v12 = hkpMoppCompiler::calculateRequiredBufferSize(this, mediator);
  v13 = v12;
  if ( buffer && bufferSize >= v12 )
  {
    v14 = buffer;
  }
  else
  {
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (hkpMoppCompilerPrimitive *)hkMemoryRouter::easyAlloc(Value[11], v13);
  }
  v16 = v8;
  if ( this->m_splitParams.m_interleavedBuildingEnabled.m_bool )
    v8 = 4096;
  v17 = mediator->vfptr;
  temp.m_primitives = v14;
  temp.m_nodes = (hkpMoppTreeInternalNode *)&v14[v16];
  temp.m_terminals = (hkpMoppTreeTerminal *)&temp.m_nodes[v8];
  ((void (__fastcall *)(hkpMoppMediator *, hkpMoppCompilerPrimitive *))v17[2].__first_virtual_table_function__)(
    mediator,
    v14);
  hkpMoppDefaultSplitter::hkpMoppDefaultSplitter(&v64);
  v18 = hkpMoppDefaultSplitter::buildTree(&v64, mediator, &costFunction, &v63, &this->m_splitParams, &temp);
  v59 = v18;
  hkpMoppDefaultSplitter::~hkpMoppDefaultSplitter(&v64);
  if ( v14 != buffer )
  {
    v19 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::easyFree(v19[11], v14);
  }
  if ( v18 )
  {
    m_chunkInfo = this->m_chunkInfo;
    this->m_debugRootNode = v18;
    if ( m_chunkInfo )
    {
      v23 = 0i64;
      v58 = 0x80000000;
      v24 = 0i64;
      v57 = 0;
      array = 0i64;
      v25 = m_chunkInfo->m_chunks.m_size + 1;
      if ( v25 > 0 )
      {
        hkArrayUtil::_reserve(
          &result,
          &hkContainerTempAllocator::s_alloc,
          (const void **)&array,
          m_chunkInfo->m_chunks.m_size + 1,
          4);
        v24 = array;
      }
      v57 = v25;
      *v24 = 0;
      v26 = 0;
      if ( this->m_chunkInfo->m_chunks.m_size > 0 )
      {
        v27 = 0i64;
        v28 = 0i64;
        do
        {
          v29 = this->m_chunkInfo;
          if ( v29->m_compressor )
            m_maxChunkSize = v29->m_maxChunkSize;
          else
            m_maxChunkSize = (v29->m_chunks.m_data[v28].m_code->m_pos + 15) & 0xFFFFFFF0;
          ++v26;
          ++v28;
          v31 = array[v27++] + m_maxChunkSize;
          array[v27] = v31;
        }
        while ( v26 < this->m_chunkInfo->m_chunks.m_size );
      }
      v32 = 0;
      if ( this->m_chunkInfo->m_chunks.m_size > 0 )
      {
        v33 = 0i64;
        do
        {
          m_data = this->m_chunkInfo->m_chunks.m_data;
          m_code = m_data[v33].m_code;
          if ( m_code->m_jumpCommands.m_size > 0 )
          {
            v36 = 0i64;
            do
            {
              ChunkIdFromCode = readChunkIdFromCode(&m_data[v33].m_code->m_code[m_data[v33].m_code->m_size
                                                                              - (__int64)*(int *)((char *)&m_code->m_jumpCommands.m_data->m_position
                                                                                                + v36)]);
              writeChunkOffsetIntoCode(v38, array[ChunkIdFromCode]);
              v36 = v40 + 8;
            }
            while ( v39 + 1 < m_code->m_jumpCommands.m_size );
          }
          ++v32;
          ++v33;
        }
        while ( v32 < this->m_chunkInfo->m_chunks.m_size );
      }
      v41 = array[v57 - 1] + 3;
      v42 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v43 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v42[11] + 8i64))(v42[11], 64i64);
      v22 = (hkpMoppCode *)v43;
      v66 = (hkpMoppCode *)v43;
      if ( v43 )
      {
        *(_DWORD *)(v43 + 8) = 0x1FFFF;
        *(_QWORD *)v43 = &hkpMoppCode::`vftable;
        *(_QWORD *)(v43 + 32) = 0i64;
        *(_DWORD *)(v43 + 40) = 0;
        *(_DWORD *)(v43 + 44) = 0x80000000;
        *(_BYTE *)(v43 + 48) = 2;
        *(_OWORD *)(v43 + 16) = 0i64;
      }
      else
      {
        v22 = 0i64;
        v66 = 0i64;
      }
      p_m_data = &v22->m_data;
      if ( (v22->m_data.m_capacityAndFlags & 0x3FFFFFFF) < v41 )
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v22->m_data.m_data, v41, 1);
      v45 = v22->m_data.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v45 < v41 )
      {
        v46 = 2 * v45;
        v47 = v41;
        if ( v41 < v46 )
          v47 = v46;
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v22->m_data.m_data, v47, 1);
      }
      m_size = v22->m_data.m_size;
      v49 = v41 - m_size;
      v50 = &p_m_data->m_data[m_size];
      if ( v49 > 0 )
        memset(v50, 205, v49);
      v22->m_data.m_size = v41;
      if ( this->m_chunkInfo->m_chunks.m_size > 0 )
      {
        v51 = 0i64;
        v67 = 0i64;
        v52 = 0;
        do
        {
          v53 = &p_m_data->m_data[array[v23]];
          v54 = hkpMoppCodeGenerator::compileCode(this->m_chunkInfo->m_chunks.m_data[v51].m_code);
          hkString::memCpy(v53, v54->m_data.m_data, v54->m_data.m_size);
          v54->vfptr->__vecDelDtor(v54, 1u);
          hkReferencedObject::removeReference(this->m_chunkInfo->m_chunks.m_data[v51].m_code);
          ++v52;
          ++v23;
          ++v51;
        }
        while ( v52 < this->m_chunkInfo->m_chunks.m_size );
        v22 = v66;
      }
      v57 = 0;
      if ( v58 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v58);
      v18 = v59;
      array = 0i64;
      v58 = 0x80000000;
    }
    else
    {
      v22 = hkpMoppCodeGenerator::compileCode(&code);
    }
    ((void (__fastcall *)(hkpMoppDefaultAssembler *, hkpMoppTreeNode *, hkpMoppCode::CodeInfo *))v63.vfptr[3].__vecDelDtor)(
      &v63,
      v18,
      &v22->m_info);
    v20 = v22;
  }
  else
  {
    v20 = 0i64;
  }
  hkpMoppDefaultAssembler::~hkpMoppDefaultAssembler(&v63);
  costFunction.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  hkpMoppCodeGenerator::~hkpMoppCodeGenerator(&code);
  return v20;
}

