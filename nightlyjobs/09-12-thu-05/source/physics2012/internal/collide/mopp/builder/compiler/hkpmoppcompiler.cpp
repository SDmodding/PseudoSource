// File Line: 28
// RVA: 0xDB6C70
void __fastcall hkpMoppCompiler::hkpMoppCompiler(hkpMoppCompiler *this, hkpMoppMeshType meshType)
{
  hkpMoppCompiler *v2; // rdi
  hkpMoppMeshType v3; // ebx

  v2 = this;
  v3 = meshType;
  hkpMoppSplitter::hkpMoppSplitParams::hkpMoppSplitParams(&this->m_splitParams, meshType);
  hkpMoppCostFunction::hkpMoppSplitCostParams::hkpMoppSplitCostParams(&v2->m_splitCostParams, v3);
  v2->m_assemblerParams.m_relativeFitToleranceOfInternalNodes = 0.5;
  v2->m_assemblerParams.m_absoluteFitToleranceOfAxisAlignedTriangles = (hkVector4f)_xmm;
  v2->m_assemblerParams.m_absoluteFitToleranceOfInternalNodes = 0.2;
  v2->m_assemblerParams.m_absoluteFitToleranceOfTriangles = 1.0;
  v2->m_assemblerParams.m_groupLevels = 5;
  v2->m_assemblerParams.m_interleavedBuildingEnabled.m_bool = 1;
  v2->m_chunkInfo = 0i64;
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
  this->m_splitParams.m_tolerance = sp->m_tolerance;
  this->m_splitParams.m_maxPrimitiveSplits = sp->m_maxPrimitiveSplits;
  this->m_splitParams.m_maxPrimitiveSplitsPerNode = sp->m_maxPrimitiveSplitsPerNode;
  this->m_splitParams.m_minRangeMaxListCheck = sp->m_minRangeMaxListCheck;
  this->m_splitParams.m_checkAllEveryN = sp->m_checkAllEveryN;
  *(_DWORD *)&this->m_splitParams.m_interleavedBuildingEnabled.m_bool = *(_DWORD *)&sp->m_interleavedBuildingEnabled.m_bool;
}

// File Line: 45
// RVA: 0xDB6D20
void __fastcall hkpMoppCompiler::setCostParams(hkpMoppCompiler *this, hkpMoppCostFunction::hkpMoppSplitCostParams *sp)
{
  this->m_splitCostParams.m_weightPrimitiveSplit = sp->m_weightPrimitiveSplit;
  this->m_splitCostParams.m_weightPlaneDistance = sp->m_weightPlaneDistance;
  this->m_splitCostParams.m_weightNumUnbalancedTriangles = sp->m_weightNumUnbalancedTriangles;
  this->m_splitCostParams.m_weightPlanePosition = sp->m_weightPlanePosition;
  this->m_splitCostParams.m_weightPrimitiveIdSpread = sp->m_weightPrimitiveIdSpread;
  this->m_splitCostParams.m_queryErrorTolerance = sp->m_queryErrorTolerance;
}

// File Line: 51
// RVA: 0xDB6D50
void __fastcall hkpMoppCompiler::setAssemblerParams(hkpMoppCompiler *this, hkpMoppAssembler::hkpMoppAssemblerParams *ap)
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
void __fastcall hkpMoppCompiler::enableInterleavedBuilding(hkpMoppCompiler *this, bool enabledFlag)
{
  this->m_splitParams.m_interleavedBuildingEnabled.m_bool = enabledFlag;
  this->m_assemblerParams.m_interleavedBuildingEnabled.m_bool = enabledFlag;
}

// File Line: 64
// RVA: 0xDB6D90
__int64 __fastcall hkpMoppCompiler::calculateRequiredBufferSize(hkpMoppCompiler *this, hkpMoppMediator *mediator)
{
  hkpMoppCompiler *v2; // rbx
  signed int v3; // edx
  int v4; // eax

  v2 = this;
  v3 = this->m_splitParams.m_maxPrimitiveSplits
     + (unsigned __int64)((__int64 (__fastcall *)(hkpMoppMediator *))mediator->vfptr[2].__vecDelDtor)(mediator);
  v4 = 5 * v3;
  if ( v2->m_splitParams.m_interleavedBuildingEnabled.m_bool )
    v3 = 4096;
  return (unsigned int)(264 * v3 + 4 * v4);
}

// File Line: 85
// RVA: 0xDB72C0
__int64 __fastcall readChunkIdFromCode(const char *PC)
{
  return *((unsigned __int8 *)PC + 4)
       + ((*((unsigned __int8 *)PC + 3)
         + ((*((unsigned __int8 *)PC + 2) + ((unsigned int)*((unsigned __int8 *)PC + 1) << 8)) << 8)) << 8);
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
hkpMoppCode *__fastcall hkpMoppCompiler::compile(hkpMoppCompiler *this, hkpMoppMediator *mediator, char *buffer, int bufferSize)
{
  hkpMoppCompiler *v4; // r14
  int v5; // er13
  char *v6; // r12
  hkpMoppMediator *v7; // r15
  signed int v8; // esi
  hkBaseObjectVtbl *v9; // rbx
  unsigned int v10; // edi
  __int64 v11; // rax
  int v12; // eax
  int v13; // edi
  hkpMoppCompilerPrimitive *v14; // rdi
  hkMemoryAllocator **v15; // rax
  signed __int64 v16; // rdx
  hkBaseObjectVtbl *v17; // rax
  hkpMoppTreeNode *v18; // rbx
  hkMemoryAllocator **v19; // rax
  hkpMoppCode *v20; // rsi
  hkpMoppCompilerChunkInfo *v21; // rcx
  hkpMoppCode *v22; // r15
  __int64 v23; // rsi
  _DWORD *v24; // rax
  int v25; // edi
  int v26; // er9
  int v27; // er9
  __int64 v28; // r8
  __int64 v29; // rdi
  hkpMoppCompilerChunkInfo *v30; // rax
  unsigned int v31; // ecx
  int v32; // ecx
  int v33; // er15
  __int64 v34; // r12
  hkpMoppCompilerChunkInfo::Chunk *v35; // rbx
  hkpMoppCodeGenerator *v36; // rdi
  signed __int64 v37; // r10
  int v38; // eax
  char *v39; // r9
  int v40; // er11
  __int64 v41; // r10
  int v42; // ebx
  _QWORD **v43; // rax
  __int64 v44; // rax
  hkArray<unsigned char,hkContainerHeapAllocator> *v45; // r13
  int v46; // eax
  int v47; // eax
  int v48; // er9
  __int64 v49; // rcx
  int v50; // eax
  char *v51; // rdi
  unsigned __int64 v52; // rcx
  __int64 v53; // r12
  int v54; // er15
  char *v55; // rdi
  hkpMoppCode *v56; // rbx
  _DWORD *array; // [rsp+30h] [rbp-D0h]
  int v59; // [rsp+38h] [rbp-C8h]
  int v60; // [rsp+3Ch] [rbp-C4h]
  hkpMoppTreeNode *v61; // [rsp+40h] [rbp-C0h]
  hkpMoppSplitter::hkpMoppScratchArea temp; // [rsp+48h] [rbp-B8h]
  hkpMoppCodeGenerator code; // [rsp+60h] [rbp-A0h]
  hkpMoppCostFunction costFunction; // [rsp+90h] [rbp-70h]
  hkpMoppDefaultAssembler v65; // [rsp+C0h] [rbp-40h]
  hkpMoppDefaultSplitter v66; // [rsp+160h] [rbp+60h]
  hkResult result; // [rsp+220h] [rbp+120h]
  hkpMoppCode *v68; // [rsp+228h] [rbp+128h]
  __int64 v69; // [rsp+230h] [rbp+130h]

  v4 = this;
  v5 = bufferSize;
  v6 = buffer;
  v7 = mediator;
  v8 = this->m_splitParams.m_maxPrimitiveSplits
     + (unsigned __int64)((__int64 (__fastcall *)(hkpMoppMediator *))mediator->vfptr[2].__vecDelDtor)(mediator);
  hkpMoppCodeGenerator::hkpMoppCodeGenerator(&code, 12 * v8);
  hkpMoppCostFunction::hkpMoppCostFunction(&costFunction, &v4->m_splitCostParams);
  hkpMoppDefaultAssembler::hkpMoppDefaultAssembler(&v65, &v4->m_assemblerParams, &code, v7);
  v9 = v7->vfptr;
  v65.m_chunkInfo = v4->m_chunkInfo;
  v10 = ((__int64 (__fastcall *)(hkpMoppDefaultAssembler *))v65.vfptr[1].__first_virtual_table_function__)(&v65);
  v11 = ((__int64 (__fastcall *)(hkpMoppDefaultAssembler *))v65.vfptr[2].__vecDelDtor)(&v65);
  ((void (__fastcall *)(hkpMoppMediator *, __int64, _QWORD))v9[1].__first_virtual_table_function__)(v7, v11, v10);
  v12 = hkpMoppCompiler::calculateRequiredBufferSize(v4, v7);
  v13 = v12;
  if ( v6 && v5 >= v12 )
  {
    v14 = (hkpMoppCompilerPrimitive *)v6;
  }
  else
  {
    v15 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (hkpMoppCompilerPrimitive *)hkMemoryRouter::easyAlloc(v15[11], v13);
  }
  v16 = v8;
  if ( v4->m_splitParams.m_interleavedBuildingEnabled.m_bool )
    v8 = 4096;
  v17 = v7->vfptr;
  temp.m_primitives = v14;
  temp.m_nodes = (hkpMoppTreeInternalNode *)&v14[v16];
  temp.m_terminals = (hkpMoppTreeTerminal *)&temp.m_nodes[v8];
  ((void (__fastcall *)(hkpMoppMediator *, hkpMoppCompilerPrimitive *))v17[2].__first_virtual_table_function__)(v7, v14);
  hkpMoppDefaultSplitter::hkpMoppDefaultSplitter(&v66);
  v18 = hkpMoppDefaultSplitter::buildTree(
          &v66,
          v7,
          &costFunction,
          (hkpMoppAssembler *)&v65.vfptr,
          &v4->m_splitParams,
          &temp);
  v61 = v18;
  hkpMoppDefaultSplitter::~hkpMoppDefaultSplitter(&v66);
  if ( v14 != (hkpMoppCompilerPrimitive *)v6 )
  {
    v19 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::easyFree(v19[11], v14);
  }
  if ( v18 )
  {
    v21 = v4->m_chunkInfo;
    v4->m_debugRootNode = v18;
    if ( v21 )
    {
      v23 = 0i64;
      v60 = 2147483648;
      v24 = 0i64;
      v59 = 0;
      array = 0i64;
      v25 = v21->m_chunks.m_size + 1;
      if ( v25 > 0 )
      {
        v26 = v21->m_chunks.m_size + 1;
        if ( v25 < 0 )
          v26 = 0;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v26, 4);
        v24 = array;
      }
      v59 = v25;
      *v24 = 0;
      v27 = 0;
      if ( v4->m_chunkInfo->m_chunks.m_size > 0 )
      {
        v28 = 0i64;
        v29 = 0i64;
        do
        {
          v30 = v4->m_chunkInfo;
          if ( v30->m_compressor )
            v31 = v30->m_maxChunkSize;
          else
            v31 = (v30->m_chunks.m_data[v29].m_code->m_pos + 15) & 0xFFFFFFF0;
          ++v27;
          ++v29;
          v32 = array[v28] + v31;
          ++v28;
          array[v28] = v32;
        }
        while ( v27 < v4->m_chunkInfo->m_chunks.m_size );
      }
      v33 = 0;
      if ( v4->m_chunkInfo->m_chunks.m_size > 0 )
      {
        v34 = 0i64;
        do
        {
          v35 = v4->m_chunkInfo->m_chunks.m_data;
          v36 = v35[v34].m_code;
          if ( v36->m_jumpCommands.m_size > 0 )
          {
            v37 = 0i64;
            do
            {
              v38 = readChunkIdFromCode(&v35[v34].m_code->m_code[v35[v34].m_code->m_size
                                                               - (signed __int64)*(int *)((char *)&v36->m_jumpCommands.m_data->m_position
                                                                                        + v37)]);
              writeChunkOffsetIntoCode(v39, array[v38]);
              v37 = v41 + 8;
            }
            while ( v40 + 1 < v36->m_jumpCommands.m_size );
          }
          ++v33;
          ++v34;
        }
        while ( v33 < v4->m_chunkInfo->m_chunks.m_size );
      }
      v42 = array[v59 - 1] + 3;
      v43 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v44 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v43[11] + 8i64))(v43[11], 64i64);
      v22 = (hkpMoppCode *)v44;
      v68 = (hkpMoppCode *)v44;
      if ( v44 )
      {
        *(_DWORD *)(v44 + 8) = 0x1FFFF;
        *(_QWORD *)v44 = &hkpMoppCode::`vftable';
        *(_QWORD *)(v44 + 32) = 0i64;
        *(_DWORD *)(v44 + 40) = 0;
        *(_DWORD *)(v44 + 44) = 2147483648;
        *(_BYTE *)(v44 + 48) = 2;
        *(_OWORD *)(v44 + 16) = 0i64;
      }
      else
      {
        v22 = 0i64;
        v68 = 0i64;
      }
      v45 = &v22->m_data;
      if ( (v22->m_data.m_capacityAndFlags & 0x3FFFFFFF) < v42 )
        hkArrayUtil::_reserve(
          &result,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v22->m_data,
          v42,
          1);
      v46 = v22->m_data.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v46 < v42 )
      {
        v47 = 2 * v46;
        v48 = v42;
        if ( v42 < v47 )
          v48 = v47;
        hkArrayUtil::_reserve(
          &result,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v22->m_data,
          v48,
          1);
      }
      v49 = v22->m_data.m_size;
      v50 = v42 - v49;
      v51 = &v45->m_data[v49];
      v52 = v42 - (signed int)v49;
      if ( v50 > 0 )
        memset(v51, 205, v52);
      v22->m_data.m_size = v42;
      if ( v4->m_chunkInfo->m_chunks.m_size > 0 )
      {
        v53 = 0i64;
        v69 = 0i64;
        v54 = 0;
        do
        {
          v55 = &v45->m_data[*(_DWORD *)((char *)array + v23)];
          v56 = hkpMoppCodeGenerator::compileCode(v4->m_chunkInfo->m_chunks.m_data[v53].m_code);
          hkString::memCpy(v55, v56->m_data.m_data, v56->m_data.m_size);
          v56->vfptr->__vecDelDtor((hkBaseObject *)&v56->vfptr, 1u);
          hkReferencedObject::removeReference((hkReferencedObject *)&v4->m_chunkInfo->m_chunks.m_data[v53].m_code->vfptr);
          ++v54;
          v23 += 4i64;
          ++v53;
        }
        while ( v54 < v4->m_chunkInfo->m_chunks.m_size );
        v22 = v68;
        LODWORD(v23) = 0;
      }
      v59 = v23;
      if ( v60 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          4 * v60);
      v18 = v61;
      array = 0i64;
      v60 = 2147483648;
    }
    else
    {
      v22 = hkpMoppCodeGenerator::compileCode(&code);
    }
    ((void (__fastcall *)(hkpMoppDefaultAssembler *, hkpMoppTreeNode *, hkpMoppCode::CodeInfo *))v65.vfptr[3].__vecDelDtor)(
      &v65,
      v18,
      &v22->m_info);
    v20 = v22;
  }
  else
  {
    v20 = 0i64;
  }
  hkpMoppDefaultAssembler::~hkpMoppDefaultAssembler(&v65);
  costFunction.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  hkpMoppCodeGenerator::~hkpMoppCodeGenerator(&code);
  return v20;
}

