// File Line: 29
// RVA: 0xDFB150
void __fastcall hkpMoppDefaultAssembler::updateParams(hkpMoppDefaultAssembler *this, hkpMoppAssembler::hkpMoppAssemblerParams *ap)
{
  this->m_params.m_relativeFitToleranceOfInternalNodes = ap->m_relativeFitToleranceOfInternalNodes;
  this->m_params.m_absoluteFitToleranceOfInternalNodes = ap->m_absoluteFitToleranceOfInternalNodes;
  this->m_params.m_absoluteFitToleranceOfTriangles = ap->m_absoluteFitToleranceOfTriangles;
  this->m_params.m_absoluteFitToleranceOfAxisAlignedTriangles = ap->m_absoluteFitToleranceOfAxisAlignedTriangles;
  this->m_params.m_groupLevels = ap->m_groupLevels;
  this->m_params.m_interleavedBuildingEnabled.m_bool = ap->m_interleavedBuildingEnabled.m_bool;
}

// File Line: 40
// RVA: 0xDFADB0
void __fastcall hkpMoppDefaultAssembler::hkpMoppDefaultAssembler(hkpMoppDefaultAssembler *this, hkpMoppAssembler::hkpMoppAssemblerParams *ap, hkpMoppCodeGenerator *code, hkpMoppMediator *mediator)
{
  hkpMoppAssembler::hkpMoppAssemblerParams *v4; // r14
  hkpMoppDefaultAssembler *v5; // rdi
  unsigned int v6; // ebx
  hkpMoppMediator *v7; // rsi
  hkpMoppCodeGenerator *v8; // rbp
  hkpMoppSplittingPlaneDirection *v9; // rax
  hkpMoppSplittingPlaneDirection *v10; // rcx
  int v11; // eax
  signed int v12; // edx
  __int64 v13; // rcx
  hkpMoppSplittingPlaneDirection *v14; // rax
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  int v19; // [rsp+70h] [rbp+8h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppDefaultAssembler::`vftable';
  this->m_directions.m_data = 0i64;
  this->m_directions.m_size = 0;
  v4 = ap;
  v5 = this;
  v6 = 2147483648;
  this->m_directions.m_capacityAndFlags = 2147483648;
  v7 = mediator;
  v8 = code;
  v19 = 416;
  v9 = (hkpMoppSplittingPlaneDirection *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                           (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                           &v19);
  v5->m_directions.m_size = 13;
  v10 = v9;
  LODWORD(v9) = v19;
  v5->m_directions.m_data = v10;
  v11 = (signed int)v9 / 32;
  if ( v11 )
    v6 = v11;
  v5->m_directions.m_capacityAndFlags = v6;
  v5->m_params.m_relativeFitToleranceOfInternalNodes = 0.5;
  v5->m_params.m_absoluteFitToleranceOfInternalNodes = 0.2;
  v5->m_params.m_absoluteFitToleranceOfAxisAlignedTriangles = (hkVector4f)_xmm;
  v5->m_params.m_absoluteFitToleranceOfTriangles = 1.0;
  v5->m_params.m_groupLevels = 5;
  v5->m_params.m_interleavedBuildingEnabled.m_bool = 1;
  v5->m_directions.m_data->m_direction = (hkVector4f)_xmm;
  v5->m_directions.m_data[1].m_direction.m_quad = _xmm;
  v5->m_directions.m_data[2].m_direction.m_quad = _xmm;
  v5->m_directions.m_data->m_cost = 0.0;
  v5->m_directions.m_data[1].m_cost = 0.0;
  v5->m_directions.m_data[2].m_cost = 0.0;
  v5->m_directions.m_data[3].m_direction = (hkVector4f)_xmm;
  v5->m_directions.m_data[4].m_direction = (hkVector4f)_xmm;
  v5->m_directions.m_data[5].m_direction.m_quad = _xmm;
  v5->m_directions.m_data[3].m_cost = 0.2;
  v5->m_directions.m_data[4].m_cost = 0.2;
  v5->m_directions.m_data[5].m_cost = 0.2;
  v5->m_directions.m_data[6].m_direction = (hkVector4f)_xmm;
  v5->m_directions.m_data[7].m_direction = (hkVector4f)_xmm;
  v5->m_directions.m_data[8].m_direction = (hkVector4f)_xmm;
  v5->m_directions.m_data[6].m_cost = 0.25;
  v5->m_directions.m_data[7].m_cost = 0.25;
  v12 = 0;
  v13 = 0i64;
  v5->m_directions.m_data[8].m_cost = 0.25;
  v5->m_directions.m_data[9].m_direction = (hkVector4f)_xmm;
  v5->m_directions.m_data[10].m_direction = (hkVector4f)_xmm;
  v5->m_directions.m_data[11].m_direction = (hkVector4f)_xmm;
  v5->m_directions.m_data[12].m_direction = (hkVector4f)_xmm;
  v5->m_directions.m_data[9].m_cost = 0.30000001;
  v5->m_directions.m_data[10].m_cost = 0.31999999;
  v5->m_directions.m_data[11].m_cost = 0.31999999;
  v5->m_directions.m_data[12].m_cost = 0.34;
  do
  {
    v14 = v5->m_directions.m_data;
    ++v13;
    v15 = v14[v13 - 1].m_direction.m_quad;
    v16 = _mm_mul_ps(v15, v15);
    v17 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170));
    v18 = _mm_rsqrt_ps(v17);
    v14[v13 - 1].m_direction.m_quad = _mm_mul_ps(
                                        _mm_andnot_ps(
                                          _mm_cmpleps(v17, (__m128)0i64),
                                          _mm_mul_ps(
                                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                            _mm_mul_ps(*(__m128 *)_xmm, v18))),
                                        v15);
    *((_DWORD *)&v5->m_directions.m_data[v13] - 3) = v12++;
  }
  while ( v12 < 13 );
  hkpMoppDefaultAssembler::updateParams(v5, v4);
  v5->m_code = v8;
  v5->m_mediator = v7;
  v5->m_nodeMgr = 0i64;
}

// File Line: 96
// RVA: 0xDFB0E0
void __fastcall hkpMoppDefaultAssembler::~hkpMoppDefaultAssembler(hkpMoppDefaultAssembler *this)
{
  hkpMoppDefaultAssembler *v1; // rbx
  int v2; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppDefaultAssembler::`vftable';
  v2 = this->m_directions.m_capacityAndFlags;
  this->m_directions.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_directions.m_data,
      32 * v2);
  v1->m_directions.m_data = 0i64;
  v1->m_directions.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 101
// RVA: 0xDFDBB0
void __fastcall hkpMoppDefaultAssembler::releaseNode(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *node)
{
  hkpMoppTreeNode *v2; // rbx
  hkpMoppDefaultAssembler *v3; // rdi

  v2 = node;
  v3 = this;
  if ( !node->m_isTerminal.m_bool )
  {
    if ( this->m_params.m_interleavedBuildingEnabled.m_bool )
    {
      ((void (__fastcall *)(hkpMoppNodeMgr *, _QWORD))this->m_nodeMgr->vfptr[1].__first_virtual_table_function__)(
        this->m_nodeMgr,
        *(_QWORD *)&node[1].m_extents.m_extent[1]);
      ((void (__fastcall *)(hkpMoppNodeMgr *, _QWORD))v3->m_nodeMgr->vfptr[1].__first_virtual_table_function__)(
        v3->m_nodeMgr,
        *(_QWORD *)&v2[1].m_extents.m_extent[2]);
      v2[1].m_extents.m_extent[1] = 0i64;
      v2[1].m_extents.m_extent[2] = 0i64;
    }
  }
}

// File Line: 126
// RVA: 0xDFCF40
hkBool *__fastcall hkpMoppDefaultAssembler::shouldAssemble(hkpMoppDefaultAssembler *this, hkBool *result, hkpMoppTreeNode *currentNode, hkpMoppAssemblerNodeInfo *currentInfo)
{
  hkBool *v4; // rax

  if ( currentNode->m_numPrimitives < 22 || currentInfo->m_level > this->m_minDepthToBuild )
  {
    result->m_bool = 1;
    v4 = result;
  }
  else
  {
    result->m_bool = 0;
    v4 = result;
  }
  return v4;
}

// File Line: 143
// RVA: 0xDFC970
__int64 __fastcall hkpMoppDefaultAssembler::calcRescaleBits(hkpMoppDefaultAssembler *this, hkpMoppAssemblerNodeInfo *parentInfo, hkpMoppAssemblerNodeInfo *currentInfo)
{
  int v3; // eax
  int v4; // er8
  int v5; // ecx
  int v6; // eax
  __int64 result; // rax

  v3 = currentInfo->m_maxExtentsSignificantBits;
  v4 = parentInfo->m_currentBitsResolution;
  v5 = 0;
  v6 = v3 - 8;
  if ( v6 > 0 )
    v5 = v6;
  result = (unsigned int)(v4 - v5);
  if ( (signed int)result > v4 )
    result = (unsigned int)v4;
  return result;
}

// File Line: 172
// RVA: 0xDFC9A0
void __fastcall hkpMoppDefaultAssembler::recalcRescale(hkpMoppDefaultAssembler *this, hkpMoppAssemblerNodeInfo *parent, hkpMoppAssemblerNodeInfo *info, hkpMoppAssemblerRescaleCommand *cmd)
{
  hkpMoppAssemblerRescaleCommand *v4; // r12
  hkpMoppAssemblerNodeInfo *v5; // rdi
  hkpMoppAssemblerNodeInfo *v6; // rbx
  signed int v7; // eax
  signed int v8; // esi
  int *v9; // r14
  signed __int64 v10; // rbp
  signed __int64 v11; // r15
  int *v12; // rbx
  int *v13; // r11
  signed int v14; // eax
  int v15; // er9
  hkpMoppAssemblerRescaleCommand *v16; // [rsp+68h] [rbp+20h]

  v16 = cmd;
  v4 = cmd;
  v5 = info;
  v6 = parent;
  v7 = hkpMoppDefaultAssembler::calcRescaleBits(this, parent, info);
  v4->m_doRescale.m_bool = 0;
  if ( v7 <= 0 )
  {
    v5->m_currentBitsResolution = v6->m_currentBitsResolution;
    v5->m_accumOffset[0] = v6->m_accumOffset[0];
    v5->m_accumOffset[1] = v6->m_accumOffset[1];
    v5->m_accumOffset[2] = v6->m_accumOffset[2];
  }
  else
  {
    v8 = 4;
    v9 = &v6->m_currentBitsResolution;
    if ( v7 < 4 )
      v8 = v7;
    v10 = (char *)v6 - (char *)v4 + 32;
    v11 = (char *)v4 - (char *)v5 - 32;
$L_calc_bits:
    v12 = &v5->m_extents[0][1];
    v13 = v5->m_accumOffset;
    v5->m_currentBitsResolution = *v9 - v8;
    v14 = 0;
    while ( v14 < 3 )
    {
      v15 = (*(v12 - 1) - *(int *)((char *)v13 + v11 + v10)) >> *v9;
      *v13 = *(int *)((char *)v13 + v11 + v10) + (v15 << *v9);
      *(int *)((char *)v13 + v11) = v15;
      if ( (*v12 - *v13) >> v5->m_currentBitsResolution >= 255 )
      {
        --v8;
        goto $L_calc_bits;
      }
      ++v14;
      ++v13;
      v12 += 2;
    }
    v16->m_scaleCommand = v8;
    v16->m_doRescale.m_bool = 1;
  }
}

// File Line: 228
// RVA: 0xDFC710
__int64 __fastcall hkpMoppDefaultAssembler::preCalcScale(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode, hkpMoppAssemblerNodeInfo *parentInfo, hkpMoppAssemblerNodeInfo *currentInfo)
{
  bool v4; // zf
  int v5; // er11
  hkpMoppAssemblerNodeInfo *v6; // r10
  hkpMoppAssemblerNodeInfo *v7; // rdi
  hkpMoppTreeNode *v8; // rbx
  hkpMoppDefaultAssembler *v9; // rbp
  float v10; // xmm2_4
  int v11; // er8
  float *v12; // r9
  signed __int64 v13; // rdx
  float *v14; // rcx
  float v15; // xmm1_4
  unsigned int i; // ecx
  int v18; // eax
  hkpMoppExtent v19; // rax
  signed int v20; // ecx
  signed __int64 v21; // rdi
  hkpMoppTreeNode *v22; // rsi
  int v23; // eax
  int v24; // er9
  int v25; // edx
  __int64 v26; // r8
  __int64 v27; // rcx
  int v28; // eax
  bool v29; // sf
  unsigned __int8 v30; // of
  int v31; // [rsp+20h] [rbp-98h]
  __int64 v32; // [rsp+28h] [rbp-90h]
  int v33; // [rsp+30h] [rbp-88h]
  hkpMoppAssemblerRescaleCommand cmd; // [rsp+38h] [rbp-80h]
  hkpMoppAssemblerNodeInfo currentInfoa; // [rsp+50h] [rbp-68h]
  hkpMoppTreeNode *v36; // [rsp+C8h] [rbp+10h]
  hkpMoppAssemblerNodeInfo *parentInfoa; // [rsp+D8h] [rbp+20h]

  parentInfoa = currentInfo;
  v36 = currentNode;
  v4 = currentNode->m_isTerminal.m_bool == 0;
  v5 = currentInfo->m_maxExtentsSignificantBits;
  v6 = currentInfo;
  v7 = parentInfo;
  v8 = currentNode;
  v9 = this;
  v33 = currentInfo->m_maxExtentsSignificantBits;
  if ( v4 )
  {
    if ( !currentNode->m_assemblerData.m_scaleIsValid.m_bool && currentInfo->m_level < this->m_halfTreeDepth )
    {
      v18 = hkpMoppDefaultAssembler::calcRescaleBits(this, parentInfo, currentInfo);
      v6 = parentInfoa;
      if ( v18 > 2 )
        v8->m_assemblerData.m_rescaleCommandType.m_storage = 1;
    }
    if ( v8->m_assemblerData.m_rescaleCommandType.m_storage == 1 )
    {
      cmd.m_doRescale.m_bool = 0;
      hkpMoppDefaultAssembler::recalcRescale(v9, v7, v6, &cmd);
    }
    v19 = v8[1].m_extents.m_extent[1];
    v20 = 0x7FFFFFFF;
    v32 = -1i64;
    *(hkpMoppExtent *)&cmd.m_doRescale.m_bool = v19;
    *(hkpMoppExtent *)cmd.m_moppOffset = v8[1].m_extents.m_extent[2];
    v31 = 0x7FFFFFFF;
    v21 = 1i64;
    do
    {
      v22 = (hkpMoppTreeNode *)*((_QWORD *)&cmd.m_doRescale.m_bool + v21);
      if ( v22 )
      {
        hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(
          &currentInfoa,
          parentInfoa,
          *((hkpMoppTreeNode **)&cmd.m_doRescale.m_bool + v21),
          &v9->m_codeInfo);
        *((_DWORD *)&v32 + v21) = hkpMoppDefaultAssembler::preCalcScale(v9, v22, parentInfoa, &currentInfoa);
        v23 = currentInfoa.m_maxExtentsSignificantBits;
        if ( v31 < currentInfoa.m_maxExtentsSignificantBits )
          v23 = v31;
        v20 = v23;
        v31 = v23;
      }
      --v21;
    }
    while ( v21 >= 0 );
    v24 = v33;
    v25 = v20 + 2;
    if ( v33 + 2 < v20 + 2 )
      v25 = v33 + 2;
    v26 = 0i64;
    while ( 1 )
    {
      v27 = *((_QWORD *)&cmd.m_doRescale.m_bool + v26);
      v28 = *((_DWORD *)&v32 + v26);
      if ( v27 )
        break;
LABEL_43:
      if ( ++v26 >= 2 )
        return (unsigned int)v25;
    }
    if ( v36->m_assemblerData.m_scaleIsValid.m_bool )
    {
      if ( *(_BYTE *)(v27 + 61) )
      {
LABEL_39:
        if ( !*(_BYTE *)(v27 + 62) )
        {
          if ( v25 < v28 )
            v28 = v25;
          v25 = v28;
        }
        goto LABEL_43;
      }
      v30 = __OFSUB__(v28, v25);
      v29 = v28 - v25 < 0;
    }
    else
    {
      v30 = __OFSUB__(v28, v24);
      v29 = v28 - v24 < 0;
    }
    if ( v29 ^ v30 )
      *(_BYTE *)(v27 + 62) = 1;
    goto LABEL_39;
  }
  v10 = this->m_params.m_absoluteFitToleranceOfTriangles;
  v11 = 0;
  v12 = this->m_params.m_absoluteFitToleranceOfAxisAlignedTriangles.m_quad.m128_f32;
  v13 = 0i64;
  v14 = (float *)&v8->m_extents;
  do
  {
    if ( !v8->m_assemblerData.m_scaleIsValid.m_bool )
      v8->m_assemblerData.m_cutCommandType[v13].m_storage = 1;
    v15 = *v12;
    if ( (float)(v14[1] - *v14) < *v12 && v15 < v10 )
    {
      if ( (signed int)(float)(v15 * v9->m_codeInfo.m_offset.m_quad.m128_f32[3]) << 7 < __ROL4__(1, v5) )
      {
        if ( !v8->m_assemblerData.m_scaleIsValid.m_bool )
          v8->m_assemblerData.m_cutCommandType[v13].m_storage = 2;
      }
      else
      {
        v10 = *v12;
      }
    }
    ++v13;
    ++v12;
    v14 += 2;
  }
  while ( v13 < 3 );
  for ( i = (signed int)(float)((float)(v9->m_codeInfo.m_offset.m_quad.m128_f32[3] * 0.89999998) * v10); i; i >>= 1 )
    ++v11;
  if ( v11 + 6 > v5 )
    v5 = v11 + 6;
  return (unsigned int)v5;
}

// File Line: 392
// RVA: 0xDFCAC0
void __fastcall hkpMoppDefaultAssembler::fixScale(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode)
{
  for ( ; currentNode; currentNode = (hkpMoppTreeNode *)&currentNode->m_parent->m_parent )
  {
    if ( currentNode->m_assemblerData.m_scaleIsValid.m_bool )
      break;
    currentNode->m_assemblerData.m_scaleIsValid.m_bool = 1;
  }
}

// File Line: 422
// RVA: 0xDFCAE0
void __fastcall hkpMoppDefaultAssembler::calcTermCut(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode, hkpMoppAssemblerCutInfo *currentInfo)
{
  int *v3; // rsi
  signed __int64 v4; // rbx
  float *v5; // rdi
  float *v6; // rbp
  int *v7; // r10
  signed __int64 v8; // r8
  float *v9; // r9
  signed __int64 v10; // r11
  float v11; // xmm4_4
  float v12; // xmm2_4
  int v13; // eax
  int v14; // ecx
  signed int v15; // edx

  v3 = &currentInfo->m_currentBitsResolution;
  v4 = (char *)this - (char *)&currentNode->m_assemblerData;
  v5 = &this->m_params.m_absoluteFitToleranceOfTriangles;
  v6 = &this->m_codeInfo.m_offset.m_quad.m128_f32[3];
  v7 = currentNode->m_assemblerData.m_minCutPlanePosition;
  v8 = (char *)currentInfo - (char *)currentNode;
  v9 = (float *)&currentNode->m_extents;
  v10 = 3i64;
  do
  {
    v11 = *(float *)((char *)v7 + v4 + 116);
    v12 = fmaxf((float)(1 << *v3) / *v6, *v5);
    if ( (float)(v9[1] - *v9) < v11 )
      v12 = fminf(v12, v11);
    v13 = *(_DWORD *)((char *)v9 + v8 - 4);
    v14 = *(_DWORD *)((char *)v9 + v8);
    ++v7;
    v9 += 2;
    v15 = (signed int)(float)(*v6 * v12);
    *(v7 - 1) = v13 - v15;
    v7[2] = v14 + v15 + 1;
    --v10;
  }
  while ( v10 );
}

// File Line: 479
// RVA: 0xDFCC50
void __fastcall hkpMoppDefaultAssembler::preCalcCutPositions(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode, hkpMoppAssemblerCutInfo *parentInfo, hkpMoppAssemblerCutInfo *currentInfo)
{
  hkpMoppAssemblerCutInfo *v4; // rbp
  hkpMoppTreeNode *v5; // rdi
  hkpMoppDefaultAssembler *v6; // rsi
  int v7; // ecx
  int v8; // er8
  int v9; // ecx
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  bool v13; // zf
  int v14; // ecx
  int v15; // edx
  int v16; // ecx
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  __int64 v20; // rcx
  signed __int64 v21; // rdx
  int *v22; // rcx
  signed __int64 v23; // rax
  hkpMoppTreeNode *v24; // rsi
  signed __int64 v25; // r8
  int *v26; // r9
  int *v27; // rdx
  signed __int64 v28; // r10
  int v29; // eax
  char v30; // cl
  int v31; // ecx
  int v32; // ecx
  int pleft[2]; // [rsp+30h] [rbp-A8h]
  hkpMoppTreeNode *currentNodea; // [rsp+38h] [rbp-A0h]
  __int64 v35; // [rsp+40h] [rbp-98h]
  int pright; // [rsp+50h] [rbp-88h]
  hkpMoppAssemblerCutInfo currentInfoa; // [rsp+60h] [rbp-78h]
  hkpMoppDefaultAssembler *v38; // [rsp+E0h] [rbp+8h]
  HK_MOPP_SPLIT_DIRECTIONS v39; // [rsp+E8h] [rbp+10h]
  hkpMoppAssemblerCutInfo *v40; // [rsp+F8h] [rbp+20h]

  v40 = currentInfo;
  v38 = this;
  v4 = currentInfo;
  v5 = currentNode;
  v6 = this;
  if ( currentNode->m_assemblerData.m_isAssembled.m_bool )
    return;
  if ( currentNode->m_isTerminal.m_bool )
  {
    v7 = currentInfo->m_currentBitsResolution;
    v8 = (currentInfo->m_extents[0][1] >> v7) + 1;
    currentInfo->m_lowCutPlanePosition[0] = currentInfo->m_extents[0][0] >> v7 << v7;
    currentInfo->m_highCutPlanePosition[0] = v8 << v7;
    v9 = currentInfo->m_currentBitsResolution;
    v10 = currentInfo->m_extents[1][0] >> v9 << v9;
    currentInfo->m_highCutPlanePosition[1] = ((currentInfo->m_extents[1][1] >> v9) + 1) << v9;
    currentInfo->m_lowCutPlanePosition[1] = v10;
    v11 = currentInfo->m_currentBitsResolution;
    v12 = ((currentInfo->m_extents[2][1] >> v11) + 1) << v11;
    currentInfo->m_lowCutPlanePosition[2] = currentInfo->m_extents[2][0] >> v11 << v11;
    currentInfo->m_highCutPlanePosition[2] = v12;
    hkpMoppDefaultAssembler::calcTermCut(v6, v5, currentInfo);
    return;
  }
  v13 = currentNode->m_assemblerData.m_rescaleCommandType.m_storage == 1;
  LOBYTE(currentNodea) = 0;
  if ( v13 )
    hkpMoppDefaultAssembler::recalcRescale(
      this,
      (hkpMoppAssemblerNodeInfo *)&parentInfo->m_level,
      (hkpMoppAssemblerNodeInfo *)&currentInfo->m_level,
      (hkpMoppAssemblerRescaleCommand *)&currentNodea);
  v14 = v4->m_currentBitsResolution;
  v15 = ((v4->m_extents[0][1] >> v14) + 1) << v14;
  v4->m_lowCutPlanePosition[0] = v4->m_extents[0][0] >> v14 << v14;
  v4->m_highCutPlanePosition[0] = v15;
  v16 = v4->m_currentBitsResolution;
  v17 = v4->m_extents[1][0] >> v16 << v16;
  v4->m_highCutPlanePosition[1] = ((v4->m_extents[1][1] >> v16) + 1) << v16;
  v4->m_lowCutPlanePosition[1] = v17;
  v18 = v4->m_currentBitsResolution;
  v19 = ((v4->m_extents[2][1] >> v18) + 1) << v18;
  v4->m_lowCutPlanePosition[2] = v4->m_extents[2][0] >> v18 << v18;
  v4->m_highCutPlanePosition[2] = v19;
  v39 = hkpMoppDefaultAssembler::getSplitCode(v6, (hkVector4f *)v5[1].m_parent);
  hkpMoppDefaultAssembler::findPlanes(
    v6,
    (hkpMoppTreeInternalNode *)v5,
    (hkpMoppAssemblerNodeInfo *)&v4->m_level,
    pleft,
    &pright);
  v20 = (__int64)v5[1].m_extents.m_extent[1];
  currentNodea = (hkpMoppTreeNode *)v5[1].m_extents.m_extent[2];
  v35 = v20;
  v21 = 3i64;
  v22 = v5->m_assemblerData.m_maxCutPlanePosition;
  v23 = 0i64;
  do
  {
    *(v22 - 3) = 0;
    *v22 = 0x7FFFFFFF;
    ++v22;
    --v21;
  }
  while ( v21 );
  *(_QWORD *)pleft = 0i64;
  do
  {
    v24 = *(&currentNodea + v23);
    if ( !v24 )
      goto LABEL_35;
    hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(
      (hkpMoppAssemblerNodeInfo *)&currentInfoa.m_level,
      (hkpMoppAssemblerNodeInfo *)&v4->m_level,
      *(&currentNodea + v23),
      &v38->m_codeInfo);
    hkpMoppDefaultAssembler::preCalcCutPositions(v38, v24, v4, &currentInfoa);
    if ( v24 == currentNodea )
    {
      if ( (signed int)v39 <= 2i64 )
        v24->m_assemblerData.m_minCutPlanePosition[v39] = 0;
    }
    else if ( (signed int)v39 <= 2i64 )
    {
      v24->m_assemblerData.m_maxCutPlanePosition[v39] = 0x7FFFFFFF;
    }
    v25 = 0i64;
    v26 = &v4->m_extents[0][1];
    v27 = v24->m_assemblerData.m_minCutPlanePosition;
    v28 = (char *)v5 - (char *)&v24->m_assemblerData;
    do
    {
      v29 = v24->m_assemblerData.m_cutCommandType[v25].m_storage;
      if ( v29 == 1 )
      {
        if ( *v27 <= *(int *)((char *)v27 + (char *)v4 - (char *)v24)
          && v27[3] >= *(int *)((char *)v27 + (char *)v4 - (char *)&v24->m_assemblerData + 72) )
        {
          v30 = v5->m_assemblerData.m_cutCommandType[v25].m_storage;
          if ( v5->m_assemblerData.m_cutCommandType[v25].m_storage < 1 )
            v30 = 1;
          v5->m_assemblerData.m_cutCommandType[v25].m_storage = v30;
          goto LABEL_26;
        }
      }
      else if ( v29 == 2 && *v27 <= *(v26 - 1) && v27[3] >= *v26 )
      {
        v5->m_assemblerData.m_cutCommandType[v25].m_storage = 2;
LABEL_26:
        v24->m_assemblerData.m_cutCommandType[v25].m_storage = 0;
        goto LABEL_27;
      }
LABEL_27:
      if ( !v24->m_assemblerData.m_cutCommandType[v25].m_storage )
      {
        v31 = *v27;
        if ( *(int *)((char *)v27 + (char *)v5 - (char *)v24) > *v27 )
          v31 = *(int *)((char *)v27 + (char *)v5 - (char *)v24);
        *(int *)((char *)v27 + (char *)v5 - (char *)v24) = v31;
        v32 = v27[3];
        if ( *(int *)((char *)v27 + v28 + 72) < v32 )
          v32 = *(int *)((char *)v27 + v28 + 72);
        *(int *)((char *)v27 + v28 + 72) = v32;
      }
      ++v25;
      ++v27;
      v26 += 2;
    }
    while ( v25 < 3 );
    v4 = v40;
    v23 = *(_QWORD *)pleft;
LABEL_35:
    *(_QWORD *)pleft = ++v23;
  }
  while ( v23 < 2 );
}

// File Line: 615
// RVA: 0xDFB700
void __fastcall hkpMoppDefaultAssembler::initTopDown(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode, hkpMoppAssemblerNodeInfo *parentInfo, hkpMoppAssemblerNodeInfo *currentInfo, hkpMoppAssemblerRescaleCommand *rescaleCommandInfo)
{
  hkpMoppAssemblerNodeInfo *v5; // rbx
  hkpMoppAssemblerNodeInfo *v6; // rdi
  hkpMoppTreeNode *v7; // rbp
  hkpMoppDefaultAssembler *v8; // rsi

  v5 = currentInfo;
  v6 = parentInfo;
  v7 = currentNode;
  v8 = this;
  if ( currentNode->m_assemblerData.m_rescaleCommandType.m_storage == 1 )
    hkpMoppDefaultAssembler::recalcRescale(this, parentInfo, currentInfo, rescaleCommandInfo);
  hkpMoppDefaultAssembler::calcReoffset(v8, v7, v6, v5);
}

// File Line: 643
// RVA: 0xDFCF70
__int64 __fastcall hkpMoppDefaultAssembler::assemblesubNode(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode, hkpMoppAssemblerNodeInfo *parentInfo, hkpMoppAssemblerNodeInfo *currentInfo)
{
  hkpMoppAssemblerNodeInfo *v4; // rdi
  hkpMoppTreeNode *v5; // rsi
  hkpMoppDefaultAssembler *v6; // rbx
  __int64 v7; // rax
  int v8; // eax
  unsigned int v9; // ebp
  __int128 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  int v14; // ecx
  hkpMoppTreeNode *v15; // rax
  hkpMoppTreeNode *v16; // rax
  hkpMoppAssemblerNodeInfo *v17; // r8
  int v18; // [rsp+30h] [rbp-88h]
  int v19; // [rsp+30h] [rbp-88h]
  int v20; // [rsp+34h] [rbp-84h]
  hkpMoppAssemblerRescaleCommand rescaleCommandInfo; // [rsp+38h] [rbp-80h]
  hkpMoppAssemblerNodeInfo currentInfoa; // [rsp+50h] [rbp-68h]
  hkpMoppTreeNode *result; // [rsp+C8h] [rbp+10h]
  hkpMoppAssemblerNodeInfo *parentInfoa; // [rsp+D0h] [rbp+18h]

  parentInfoa = parentInfo;
  v4 = currentInfo;
  v5 = currentNode;
  v6 = this;
  if ( currentNode->m_assemblerData.m_isAssembled.m_bool )
    return 3i64;
  if ( currentInfo->m_level <= this->m_minDepthToBuild
    && !(currentInfo->m_level % this->m_params.m_groupLevels)
    && !currentInfo->m_ignoreBandControlCode.m_bool )
  {
    currentInfo->m_ignoreBandControlCode.m_bool = 1;
    v8 = this->m_minDepthToBuild;
    v9 = -1;
    v18 = this->m_minDepthToBuild;
    if ( !currentNode->m_assemblerData.m_isAssembled.m_bool )
    {
      do
      {
        v10 = *(_OWORD *)&v4->m_level;
        v11 = *(_OWORD *)&v4->m_extents[0][1];
        LODWORD(result) = v6->m_code->m_pos;
        *(_OWORD *)&currentInfoa.m_level = v10;
        v12 = *(_OWORD *)&v4->m_extents[2][1];
        *(_OWORD *)&currentInfoa.m_extents[0][1] = v11;
        v13 = *(_OWORD *)&v4->m_accumOffset[2];
        *(_OWORD *)&currentInfoa.m_extents[2][1] = v12;
        *(_QWORD *)currentInfoa.m_propertiesOffset = *(_QWORD *)v4->m_propertiesOffset;
        *(_OWORD *)&currentInfoa.m_accumOffset[2] = v13;
        v9 = hkpMoppDefaultAssembler::assemblesubNode(v6, v5, parentInfo, &currentInfoa);
        if ( v6->m_numNodesAssembled > v6->m_minAssembledElems )
          break;
        if ( (_DWORD)result == v6->m_code->m_pos )
        {
          v14 = v6->m_minDepthToBuild;
          if ( v14 < 0 )
            break;
          v6->m_minDepthToBuild = v14 - v6->m_params.m_groupLevels;
        }
        parentInfo = parentInfoa;
      }
      while ( !v5->m_assemblerData.m_isAssembled.m_bool );
      v8 = v18;
    }
    v6->m_minDepthToBuild = v8;
    v4->m_ignoreBandControlCode.m_bool = 0;
    return v9;
  }
  if ( currentNode->m_isTerminal.m_bool )
  {
    hkpMoppDefaultAssembler::fixScale(this, currentNode);
    if ( hkpMoppDefaultAssembler::shouldAssemble(v6, (hkBool *)&result, v5, v4)->m_bool )
      v7 = hkpMoppDefaultAssembler::assembleCutAndTerminalCommand(v6, v5, parentInfoa, v4);
    else
      v7 = 0xFFFFFFFFi64;
  }
  else
  {
    v9 = -1;
    rescaleCommandInfo.m_doRescale.m_bool = 0;
    rescaleCommandInfo.m_scaleCommand = -1;
    hkpMoppDefaultAssembler::initTopDown(this, currentNode, parentInfo, currentInfo, &rescaleCommandInfo);
    v15 = (hkpMoppTreeNode *)v5[1].m_extents.m_extent[2];
    v19 = -1;
    result = v15;
    if ( v15 )
    {
      hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(&currentInfoa, v4, v15, &v6->m_codeInfo);
      v19 = hkpMoppDefaultAssembler::assemblesubNode(v6, result, v4, &currentInfoa);
      if ( v19 >= 0 )
        hkpMoppDefaultAssembler::releaseNode(v6, result);
    }
    v16 = (hkpMoppTreeNode *)v5[1].m_extents.m_extent[1];
    result = v16;
    if ( !v16 )
      return v9;
    hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(&currentInfoa, v4, v16, &v6->m_codeInfo);
    v20 = hkpMoppDefaultAssembler::assemblesubNode(v6, result, v4, &currentInfoa);
    if ( v20 < 0 )
      return v9;
    hkpMoppDefaultAssembler::releaseNode(v6, result);
    if ( v19 < 0 || !hkpMoppDefaultAssembler::shouldAssemble(v6, (hkBool *)&result, v5, v4)->m_bool )
      return v9;
    v17 = parentInfoa;
    ++v6->m_numNodesAssembled;
    v7 = v19
       + v20
       + (unsigned int)hkpMoppDefaultAssembler::assembleNonTerminalCommand(v6, v5, v17, v4, &rescaleCommandInfo);
  }
  return v7;
}

// File Line: 786
// RVA: 0xDFB9D0
__int64 __fastcall hkpMoppDefaultAssembler::calcChunkPoints(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode, hkpMoppAssemblerNodeInfo *parentInfo, hkpMoppAssemblerNodeInfo *currentInfo, hkArray<unsigned int,hkContainerHeapAllocator> *terminalsOut)
{
  hkpMoppTreeNode *v5; // rsi
  hkpMoppDefaultAssembler *v6; // rdi
  int v7; // ebx
  unsigned int v8; // er8
  hkArray<unsigned int,hkContainerHeapAllocator> *v9; // rbx
  hkpPrimitiveCompressor *v10; // rcx
  hkpMoppAssemblerNodeInfo *v12; // rcx
  hkpMoppTreeNode *v13; // rdi
  int v14; // ebx
  hkpPrimitiveCompressor *v15; // rcx
  hkpMoppTreeNode *v16; // rdi
  hkpMoppTreeNode *v17; // r8
  hkpMoppTreeNode *v18; // rdx
  hkpMoppDefaultAssembler *v19; // rdi
  int v20; // ebx
  hkpPrimitiveCompressor *v21; // rcx
  int v22; // ebx
  int v23; // eax
  hkpPrimitiveCompressor *v24; // rcx
  int v25; // ebx
  hkpMoppCompilerChunkInfo *v26; // rax
  hkpMoppCompilerChunkInfo *v27; // rax
  int v28; // ecx
  hkArray<hkpMoppCompilerChunkInfo::Chunk,hkContainerHeapAllocator> *v29; // rbx
  signed __int64 v30; // r8
  hkpMoppExtent v31; // r10
  int v32; // edx
  int v33; // er11
  int v34; // ebx
  hkArray<unsigned int,hkContainerHeapAllocator> *v35; // rdi
  int v36; // [rsp+30h] [rbp-91h]
  int v37; // [rsp+34h] [rbp-8Dh]
  int v38; // [rsp+38h] [rbp-89h]
  int v39; // [rsp+3Ch] [rbp-85h]
  int v40; // [rsp+40h] [rbp-81h]
  hkArray<unsigned int,hkContainerHeapAllocator> v41; // [rsp+48h] [rbp-79h]
  hkArray<unsigned int,hkContainerHeapAllocator> v42; // [rsp+58h] [rbp-69h]
  hkArrayBase<unsigned int> v43; // [rsp+68h] [rbp-59h]
  hkpMoppTreeInternalNode *v44; // [rsp+78h] [rbp-49h]
  hkpMoppAssemblerRescaleCommand rescaleCommandInfo; // [rsp+80h] [rbp-41h]
  hkpMoppAssemblerNodeInfo currentInfoa; // [rsp+A0h] [rbp-21h]
  hkpMoppDefaultAssembler *v47; // [rsp+120h] [rbp+5Fh]
  unsigned int v48; // [rsp+120h] [rbp+5Fh]
  char v49; // [rsp+120h] [rbp+5Fh]
  hkpMoppCode::CodeInfo *codeInfo; // [rsp+128h] [rbp+67h]
  hkpMoppAssemblerNodeInfo *v51; // [rsp+130h] [rbp+6Fh]
  hkpMoppAssemblerNodeInfo *parentInfoa; // [rsp+138h] [rbp+77h]

  parentInfoa = currentInfo;
  v51 = parentInfo;
  v47 = this;
  v5 = currentNode;
  v6 = this;
  if ( this->m_chunkInfo->m_compressor )
    currentInfo->m_terminalOffset = parentInfo->m_terminalOffset;
  if ( currentNode->m_isTerminal.m_bool )
  {
    if ( this->m_chunkInfo->m_compressor )
      currentInfo->m_terminalOffset = (unsigned int)currentNode[1].m_parent->m_parent;
    v7 = this->m_code->m_pos;
    hkpMoppDefaultAssembler::assembleCutAndTerminalCommand(this, currentNode, parentInfo, currentInfo);
    v8 = v6->m_code->m_pos - v7;
    v9 = terminalsOut;
    v44 = v5[1].m_parent;
    v48 = v8;
    if ( terminalsOut->m_size == (terminalsOut->m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, terminalsOut, 4);
      v8 = v48;
    }
    v9->m_data[v9->m_size++] = (unsigned int)v44->m_parent;
    LODWORD(codeInfo) = v5[1].m_parent->m_parent;
    v10 = v6->m_chunkInfo->m_compressor;
    if ( v10 )
      v8 = (unsigned __int64)v10->vfptr->calcPrimitivesSize(v10, (const unsigned int *)&codeInfo, 1) + v48;
    return v8;
  }
  rescaleCommandInfo.m_doRescale.m_bool = 0;
  rescaleCommandInfo.m_scaleCommand = -1;
  hkpMoppDefaultAssembler::initTopDown(this, currentNode, parentInfo, currentInfo, &rescaleCommandInfo);
  v12 = parentInfoa;
  parentInfoa->m_terminalOffset = v51->m_terminalOffset;
  v13 = (hkpMoppTreeNode *)v5[1].m_extents.m_extent[2];
  v42.m_data = 0i64;
  v42.m_size = 0;
  v42.m_capacityAndFlags = 2147483648;
  codeInfo = &v47->m_codeInfo;
  hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(&currentInfoa, v12, v13, &v47->m_codeInfo);
  v14 = v47->m_code->m_pos;
  hkpMoppDefaultAssembler::calcChunkPoints(v47, v13, parentInfoa, &currentInfoa, &v42);
  v38 = v47->m_code->m_pos - v14;
  v37 = v47->m_code->m_pos - v14;
  v15 = v47->m_chunkInfo->m_compressor;
  if ( v15 && v42.m_size )
    v37 = v38
        + (unsigned __int64)((__int64 (__fastcall *)(hkpPrimitiveCompressor *, unsigned int *))v15->vfptr->calcPrimitivesSize)(
                              v15,
                              v42.m_data);
  v16 = (hkpMoppTreeNode *)v5[1].m_extents.m_extent[1];
  v17 = (hkpMoppTreeNode *)v5[1].m_extents.m_extent[1];
  v41.m_data = 0i64;
  v41.m_size = 0;
  v41.m_capacityAndFlags = 2147483648;
  hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(&currentInfoa, parentInfoa, v17, codeInfo);
  v18 = v16;
  v19 = v47;
  v20 = v47->m_code->m_pos;
  hkpMoppDefaultAssembler::calcChunkPoints(v47, v18, parentInfoa, &currentInfoa, &v41);
  v40 = v47->m_code->m_pos - v20;
  v39 = v47->m_code->m_pos - v20;
  v21 = v47->m_chunkInfo->m_compressor;
  if ( v21 && v41.m_size )
    v39 = v40
        + (unsigned __int64)((__int64 (__fastcall *)(hkpPrimitiveCompressor *, unsigned int *))v21->vfptr->calcPrimitivesSize)(
                              v21,
                              v41.m_data);
  v22 = v47->m_code->m_pos;
  hkpMoppDefaultAssembler::assembleNonTerminalCommand(v47, v5, v51, parentInfoa, &rescaleCommandInfo);
  v23 = v47->m_code->m_pos - v22;
  v43.m_capacityAndFlags = 2147483648;
  v36 = v23;
  v43.m_data = 0i64;
  v43.m_size = 0;
  hkArrayBase<unsigned int>::_insertAt(
    &v43,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    0,
    v42.m_data,
    v42.m_size);
  hkArrayBase<unsigned int>::_insertAt(
    &v43,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v43.m_size,
    v41.m_data,
    v41.m_size);
  v24 = v47->m_chunkInfo->m_compressor;
  v25 = v38 + v40 + v36;
  if ( v24 && v43.m_size )
    v25 += ((__int64 (__fastcall *)(hkpPrimitiveCompressor *, unsigned int *))v24->vfptr->calcPrimitivesSize)(
             v24,
             v43.m_data);
  v26 = v47->m_chunkInfo;
  LOBYTE(codeInfo) = 0;
  v49 = 0;
  if ( v25 >= v26->m_maxChunkSize - v26->m_safetySize )
  {
    do
    {
      v27 = v19->m_chunkInfo;
      v28 = v27->m_chunks.m_size;
      v29 = &v27->m_chunks;
      LODWORD(v27) = v27->m_chunks.m_capacityAndFlags;
      LODWORD(v44) = v28;
      if ( v29->m_size == ((unsigned int)v27 & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v29, 16);
      v30 = (signed __int64)&v29->m_data[v29->m_size++];
      if ( v39 <= v37 )
      {
        v31 = v5[1].m_extents.m_extent[2];
        v32 = v38;
        v33 = v37;
        v37 = 5;
        v49 = 1;
        if ( !(_BYTE)codeInfo )
        {
          v34 = v39 + 5;
          goto LABEL_30;
        }
        v25 = v36 + 10;
      }
      else
      {
        v31 = v5[1].m_extents.m_extent[1];
        v32 = v40;
        v33 = v39;
        v39 = 5;
        LOBYTE(codeInfo) = 1;
        if ( !v49 )
        {
          v34 = v37 + 5;
LABEL_30:
          v25 = v36 + v34;
          goto LABEL_31;
        }
        v25 = v36 + 10;
      }
LABEL_31:
      *(_DWORD *)(v30 + 8) = v33 + v19->m_chunkInfo->m_safetySize + 5;
      *(_DWORD *)(*(_QWORD *)&v31 + 68i64) = (_DWORD)v44;
      v19->m_code->m_pos += 5 - v32;
      if ( v49 )
        *(_DWORD *)(*(_QWORD *)&v5[1].m_extents.m_extent[2] + 96i64) += 5 - v32;
      *(_DWORD *)(*(_QWORD *)&v5[1].m_extents.m_extent[1] + 96i64) += 5 - v32;
      v5->m_assemblerData.m_assembledAddress += 5 - v32;
    }
    while ( v25 >= v19->m_chunkInfo->m_maxChunkSize - v19->m_chunkInfo->m_safetySize );
  }
  v35 = terminalsOut;
  terminalsOut->m_size = 0;
  if ( !v49 )
    hkArrayBase<unsigned int>::_insertAt(
      (hkArrayBase<unsigned int> *)&v35->m_data,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      0,
      v42.m_data,
      v42.m_size);
  if ( !(_BYTE)codeInfo )
    hkArrayBase<unsigned int>::_insertAt(
      (hkArrayBase<unsigned int> *)&v35->m_data,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v35->m_size,
      v41.m_data,
      v41.m_size);
  v43.m_size = 0;
  if ( v43.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v43.m_data,
      4 * v43.m_capacityAndFlags);
  v43.m_data = 0i64;
  v43.m_capacityAndFlags = 2147483648;
  v41.m_size = 0;
  if ( v41.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v41.m_data,
      4 * v41.m_capacityAndFlags);
  v41.m_data = 0i64;
  v41.m_capacityAndFlags = 2147483648;
  v42.m_size = 0;
  if ( v42.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v42.m_data,
      4 * v42.m_capacityAndFlags);
  return (unsigned int)v25;
}

// File Line: 968
// RVA: 0xDFBF00
__int64 __fastcall hkpMoppDefaultAssembler::calcTerminalIdsForChunks(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode, int chunkId, int currentId)
{
  hkpMoppTreeNode *v4; // rbx
  unsigned int v5; // edx
  int v6; // edi
  int v7; // esi
  hkpMoppDefaultAssembler *v8; // rbp
  hkpMoppCompilerChunkInfo *v9; // rsi
  __int64 v10; // rdx
  hkpMoppCodeReindexedTerminal *v11; // r8
  int v12; // eax
  int v14; // [rsp+50h] [rbp+18h]
  int v15; // [rsp+58h] [rbp+20h]

  v14 = chunkId;
  v4 = currentNode;
  v5 = currentId;
  v6 = currentId;
  v4->m_assemblerData.m_isAssembled.m_bool = 0;
  v7 = chunkId;
  v8 = this;
  v15 = currentId;
  if ( v4->m_assemblerData.m_chunkId >= 0 )
  {
    v6 = 0;
    v7 = v4->m_assemblerData.m_chunkId;
    v14 = v4->m_assemblerData.m_chunkId;
  }
  if ( this->m_chunkInfo->m_compressor )
    v4->m_minPrimitiveId = v6;
  if ( v4->m_isTerminal.m_bool )
  {
    if ( !this->m_chunkInfo->m_compressor )
      goto LABEL_12;
    LODWORD(v4[1].m_parent->m_extents.m_extent[0].m_min) = v4[1].m_parent->m_parent;
    v9 = this->m_chunkInfo;
    if ( v9->m_reindexInfo.m_size == (v9->m_reindexInfo.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v9->m_reindexInfo, 8);
    v10 = v9->m_reindexInfo.m_size;
    v11 = &v9->m_reindexInfo.m_data[v10];
    v9->m_reindexInfo.m_size = v10 + 1;
    v11->m_reindexedShapeKey = v6 | (v14 << 8);
    v11->m_origShapeKey = (unsigned int)v4[1].m_parent->m_parent;
    v4[1].m_parent->m_parent = (hkpMoppTreeInternalNode *)v6++;
  }
  else
  {
    v12 = hkpMoppDefaultAssembler::calcTerminalIdsForChunks(
            this,
            *(hkpMoppTreeNode **)&v4[1].m_extents.m_extent[2],
            v7,
            v6);
    v6 = hkpMoppDefaultAssembler::calcTerminalIdsForChunks(
           v8,
           *(hkpMoppTreeNode **)&v4[1].m_extents.m_extent[1],
           v7,
           v12);
  }
  v5 = v15;
LABEL_12:
  if ( v8->m_chunkInfo->m_compressor )
  {
    v4->m_minPrimitiveId = 0;
    v4->m_maxPrimitiveId = v6;
  }
  if ( v4->m_assemblerData.m_chunkId < 0 )
    v5 = v6;
  return v5;
}

// File Line: 1031
// RVA: 0xDFDC20
void __fastcall copyJumpCommandInfo(hkArray<hkpMoppCodeGenerator::JumpCommandInfo,hkContainerHeapAllocator> *newCommands, hkArray<hkpMoppCodeGenerator::JumpCommandInfo,hkContainerHeapAllocator> *originalCommands, int offset)
{
  int v3; // esi
  int v4; // er14
  hkArray<hkpMoppCodeGenerator::JumpCommandInfo,hkContainerHeapAllocator> *v5; // rdi
  hkArray<hkpMoppCodeGenerator::JumpCommandInfo,hkContainerHeapAllocator> *v6; // rbx
  __int64 v7; // rbp
  __int64 v8; // rdx
  hkpMoppCodeGenerator::JumpCommandInfo *v9; // r8

  v3 = 0;
  v4 = offset;
  v5 = originalCommands;
  v6 = newCommands;
  if ( originalCommands->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 8);
      v8 = v6->m_size;
      ++v3;
      v9 = &v6->m_data[v8];
      ++v7;
      v6->m_size = v8 + 1;
      v9->m_chunkId = *((_DWORD *)&v5->m_data[v7] - 1);
      v9->m_position = v4 + v5->m_data[v7 - 1].m_position;
    }
    while ( v3 < v5->m_size );
  }
}

// File Line: 1041
// RVA: 0xDFDCE0
__int64 __fastcall copyCodeAndEmbedTerminals(hkpMoppCompilerChunkInfo *chunkInfo, hkpMoppCodeGenerator *codeWithTerminals, hkpMoppCodeGenerator *codeWithoutTerminals, hkArray<unsigned int,hkContainerHeapAllocator> *terminals)
{
  hkpMoppCodeGenerator *v4; // r15
  int v5; // ebp
  hkpMoppCodeGenerator *v6; // rbx
  hkArray<unsigned int,hkContainerHeapAllocator> *v7; // r14
  hkpMoppCompilerChunkInfo *v8; // r12
  int v9; // er13
  __int64 v10; // rdi
  hkLifoAllocator *v11; // rax
  char *v12; // rdi
  int v13; // esi
  char *v14; // rcx
  hkLifoAllocator *v15; // rax
  int v16; // er8
  int v17; // esi
  int v18; // ecx
  __int64 v19; // rdi

  v4 = codeWithoutTerminals;
  v5 = -codeWithoutTerminals->m_pos & 3;
  v6 = codeWithTerminals;
  v7 = terminals;
  v8 = chunkInfo;
  if ( !chunkInfo->m_compressor )
    terminals->m_size = 0;
  if ( terminals->m_size )
  {
    v9 = ((__int64 (__fastcall *)(hkpPrimitiveCompressor *, unsigned int *))chunkInfo->m_compressor->vfptr->calcPrimitivesSize)(
           chunkInfo->m_compressor,
           terminals->m_data);
    if ( v9 > 0 )
    {
      v10 = (unsigned int)v9;
      do
      {
        v6->m_code[v6->m_size - (signed __int64)v6->m_pos++ - 1] = -51;
        if ( v6->m_pos >= v6->m_size )
          hkpMoppCodeGenerator::resize(v6);
        --v10;
      }
      while ( v10 );
    }
    v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (char *)v11->m_cur;
    v13 = (v9 + 127) & 0xFFFFFF80;
    v14 = &v12[v13];
    if ( v13 > v11->m_slabSize || v14 > v11->m_end )
      v12 = (char *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
    else
      v11->m_cur = v14;
    v8->m_compressor->vfptr->storePrimitives(v8->m_compressor, v7->m_data, v7->m_size, v12);
    hkString::memCpy(&v6->m_code[v6->m_size - v6->m_pos], v12, v9);
    v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (v13 + 15) & 0xFFFFFFF0;
    if ( v13 > v15->m_slabSize || &v12[v16] != v15->m_cur || v15->m_firstNonLifoEnd == v12 )
      hkLifoAllocator::slowBlockFree(v15, v12, v16);
    else
      v15->m_cur = v12;
  }
  v17 = v6->m_pos;
  v18 = v5 + v4->m_pos;
  if ( v18 > 0 )
  {
    v19 = (unsigned int)v18;
    do
    {
      v6->m_code[v6->m_size - (signed __int64)v6->m_pos++ - 1] = -51;
      if ( v6->m_pos >= v6->m_size )
        hkpMoppCodeGenerator::resize(v6);
      --v19;
    }
    while ( v19 );
  }
  hkString::memCpy(&v6->m_code[v6->m_size - v6->m_pos], &v4->m_code[v4->m_size - v4->m_pos], v4->m_pos);
  hkpMoppCodeGenerator::validateJumpCommands(v4);
  copyJumpCommandInfo(&v6->m_jumpCommands, &v4->m_jumpCommands, v6->m_pos - v4->m_pos);
  hkpMoppCodeGenerator::validateJumpCommands(v6);
  return (unsigned int)(v6->m_pos - v17);
}

// File Line: 1096
// RVA: 0xDFC020
void __fastcall hkpMoppDefaultAssembler::assembleSubNodeIntoChunks(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode, hkpMoppAssemblerNodeInfo *parentInfo, hkpMoppAssemblerNodeInfo *currentInfo, int chunkId, hkArray<unsigned int,hkContainerHeapAllocator> *terminalsOut)
{
  __int64 v6; // rax
  hkpMoppAssemblerNodeInfo *v7; // rsi
  hkpMoppTreeNode *v8; // rbx
  hkpMoppDefaultAssembler *v9; // rdi
  hkpMoppCompilerChunkInfo::Chunk *v10; // rbp
  int v11; // ecx
  _QWORD **v12; // rax
  hkpMoppCodeGenerator *v13; // rax
  hkpMoppCodeGenerator *v14; // rax
  hkpMoppTreeInternalNode *v15; // rdi
  hkpMoppTreeNode *v16; // rbx
  hkpMoppTreeNode *v17; // rbx
  int v18; // [rsp+30h] [rbp-98h]
  hkArray<unsigned int,hkContainerHeapAllocator> terminals; // [rsp+38h] [rbp-90h]
  hkpMoppCodeGenerator v20; // [rsp+50h] [rbp-78h]
  hkpMoppDefaultAssembler *v21; // [rsp+D0h] [rbp+8h]
  hkpMoppTreeNode *currentNodea; // [rsp+D8h] [rbp+10h]
  hkpMoppTreeNode *currentNodeb; // [rsp+D8h] [rbp+10h]
  hkpMoppAssemblerNodeInfo *parentInfoa; // [rsp+E0h] [rbp+18h]
  hkpMoppAssemblerNodeInfo *currentInfoa; // [rsp+E8h] [rbp+20h]

  currentInfoa = currentInfo;
  parentInfoa = parentInfo;
  currentNodea = currentNode;
  v21 = this;
  v6 = currentNode->m_assemblerData.m_chunkId;
  v7 = currentInfo;
  v8 = currentNode;
  v9 = this;
  v18 = v6;
  if ( (signed int)v6 <= 0 || currentInfo->m_ignoreBandControlCode.m_bool )
  {
    if ( currentNode->m_isTerminal.m_bool )
    {
      hkpMoppDefaultAssembler::assembleCutAndTerminalCommand(this, currentNode, parentInfo, currentInfo);
      v15 = v8[1].m_parent;
      if ( terminalsOut->m_size == (terminalsOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, terminalsOut, 4);
      terminalsOut->m_data[terminalsOut->m_size++] = LODWORD(v15->m_extents.m_extent[0].m_min);
    }
    else
    {
      LOBYTE(terminals.m_data) = 0;
      HIDWORD(terminals.m_data) = -1;
      hkpMoppDefaultAssembler::initTopDown(
        this,
        currentNode,
        parentInfo,
        currentInfo,
        (hkpMoppAssemblerRescaleCommand *)&terminals);
      v16 = (hkpMoppTreeNode *)v8[1].m_extents.m_extent[2];
      hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo((hkpMoppAssemblerNodeInfo *)&v20, v7, v16, &v9->m_codeInfo);
      hkpMoppDefaultAssembler::assembleSubNodeIntoChunks(
        v21,
        v16,
        currentInfoa,
        (hkpMoppAssemblerNodeInfo *)&v20,
        chunkId,
        terminalsOut);
      v17 = (hkpMoppTreeNode *)currentNodea[1].m_extents.m_extent[1];
      hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(
        (hkpMoppAssemblerNodeInfo *)&v20,
        currentInfoa,
        *(hkpMoppTreeNode **)&currentNodea[1].m_extents.m_extent[1],
        &v9->m_codeInfo);
      hkpMoppDefaultAssembler::assembleSubNodeIntoChunks(
        v21,
        v17,
        currentInfoa,
        (hkpMoppAssemblerNodeInfo *)&v20,
        chunkId,
        terminalsOut);
      hkpMoppDefaultAssembler::assembleNonTerminalCommand(
        v21,
        currentNodea,
        parentInfoa,
        currentInfoa,
        (hkpMoppAssemblerRescaleCommand *)&terminals);
    }
  }
  else
  {
    currentNodeb = (hkpMoppTreeNode *)this->m_code;
    v10 = &this->m_chunkInfo->m_chunks.m_data[v6];
    hkpMoppCodeGenerator::hkpMoppCodeGenerator(&v20, v10->m_codeSize);
    v9->m_code = &v20;
    terminals.m_data = 0i64;
    terminals.m_size = 0;
    v7->m_ignoreBandControlCode.m_bool = 1;
    terminals.m_capacityAndFlags = 2147483648;
    hkpMoppDefaultAssembler::assembleSubNodeIntoChunks(v9, v8, parentInfoa, v7, v18, &terminals);
    if ( v9->m_chunkInfo->m_compressor )
    {
      v11 = v9->m_code->m_pos + 5;
      hkpMoppDefaultAssembler::addDataOffset(v9, v11 + (-v11 & 3), terminals.m_size);
    }
    v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (hkpMoppCodeGenerator *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(
                                    v12[11],
                                    48i64);
    if ( v13 )
      hkpMoppCodeGenerator::hkpMoppCodeGenerator(v13, v10->m_codeSize);
    else
      v14 = 0i64;
    v10->m_code = v14;
    copyCodeAndEmbedTerminals(v9->m_chunkInfo, v14, v9->m_code, &terminals);
    v9->m_code->m_jumpCommands.m_size = 0;
    terminals.m_size = 0;
    if ( terminals.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        terminals.m_data,
        4 * terminals.m_capacityAndFlags);
    terminals.m_data = 0i64;
    terminals.m_capacityAndFlags = 2147483648;
    hkpMoppCodeGenerator::~hkpMoppCodeGenerator(&v20);
    v9->m_code = (hkpMoppCodeGenerator *)currentNodeb;
    hkpMoppDefaultAssembler::assembleJumpChunkCommand(v9, v8);
  }
}

// File Line: 1184
// RVA: 0xDFCBE0
void __fastcall hkpMoppDefaultAssembler::calcReoffset(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode, hkpMoppAssemblerNodeInfo *parentInfo, hkpMoppAssemblerNodeInfo *currentInfo)
{
  unsigned int v4; // eax
  unsigned int v5; // er10
  unsigned int v6; // ecx

  currentInfo->m_terminalOffset = parentInfo->m_terminalOffset;
  v4 = currentInfo->m_terminalSpread;
  v5 = currentNode->m_minPrimitiveId;
  v6 = v5 + currentInfo->m_terminalSpread - parentInfo->m_terminalOffset;
  if ( v6 >= 0x20
    && (v4 > 2 || v6 >= 0x100)
    && (v4 < 0x20 && parentInfo->m_terminalSpread >= 0x20
     || v4 < 0x100 && parentInfo->m_terminalSpread >= 0x100
     || v4 < 0x10000 && parentInfo->m_terminalSpread >= 0x10000) )
  {
    currentInfo->m_terminalOffset = v5;
  }
}

// File Line: 1215
// RVA: 0xDFD9A0
void __fastcall hkpMoppDefaultAssembler::addProperty(hkpMoppDefaultAssembler *this, int property, int value)
{
  if ( value < 0 )
    goto LABEL_9;
  if ( value < 256 )
  {
    hkpMoppCodeGenerator::addCommand8(this->m_code, property + 96, value);
    return;
  }
  if ( value >= 0x10000 )
LABEL_9:
    hkpMoppCodeGenerator::addCommand32(this->m_code, property + 104, value);
  else
    hkpMoppCodeGenerator::addCommand16(this->m_code, property + 100, value);
}

// File Line: 1236
// RVA: 0xDFD7B0
signed __int64 __fastcall hkpMoppDefaultAssembler::addJumpChunk(hkpMoppDefaultAssembler *this, int chunkId)
{
  hkpMoppCodeGenerator::addCommand32(this->m_code, 112, chunkId);
  return 5i64;
}

// File Line: 1242
// RVA: 0xDFD7E0
signed __int64 __fastcall hkpMoppDefaultAssembler::addDataOffset(hkpMoppDefaultAssembler *this, int offset, int numTerminals)
{
  hkpMoppDefaultAssembler *v3; // rdi
  hkpMoppCodeGenerator *v4; // rcx
  char v5; // bh
  int v6; // esi
  hkpMoppCodeGenerator *v7; // rcx

  v3 = this;
  v4 = this->m_code;
  v5 = BYTE1(numTerminals);
  v6 = offset;
  v4->m_code[v4->m_size - v4->m_pos++ - 1] = numTerminals;
  if ( v4->m_pos >= v4->m_size )
    hkpMoppCodeGenerator::resize(v4);
  v7 = v3->m_code;
  v7->m_code[v7->m_size - v7->m_pos++ - 1] = v5;
  if ( v7->m_pos >= v7->m_size )
    hkpMoppCodeGenerator::resize(v7);
  hkpMoppCodeGenerator::addCommand16(v3->m_code, 13, v6);
  return 5i64;
}

// File Line: 1250
// RVA: 0xDFD220
void __fastcall hkpMoppDefaultAssembler::addRescale(hkpMoppDefaultAssembler *this, hkpMoppAssemblerRescaleCommand *cmd)
{
  hkpMoppDefaultAssembler *v2; // rdi
  hkpMoppCodeGenerator *v3; // rcx
  hkpMoppAssemblerRescaleCommand *v4; // rbx
  hkpMoppCodeGenerator *v5; // rcx
  hkpMoppCodeGenerator *v6; // rcx
  hkpMoppCodeGenerator *v7; // rcx

  v2 = this;
  v3 = this->m_code;
  v4 = cmd;
  v3->m_code[v3->m_size - v3->m_pos++ - 1] = cmd->m_moppOffset[2];
  if ( v3->m_pos >= v3->m_size )
    hkpMoppCodeGenerator::resize(v3);
  v5 = v2->m_code;
  v5->m_code[v5->m_size - v5->m_pos++ - 1] = v4->m_moppOffset[1];
  if ( v5->m_pos >= v5->m_size )
    hkpMoppCodeGenerator::resize(v5);
  v6 = v2->m_code;
  v6->m_code[v6->m_size - v6->m_pos++ - 1] = v4->m_moppOffset[0];
  if ( v6->m_pos >= v6->m_size )
    hkpMoppCodeGenerator::resize(v6);
  v7 = v2->m_code;
  v7->m_code[v7->m_size - v7->m_pos++ - 1] = v4->m_scaleCommand;
  if ( v7->m_pos >= v7->m_size )
    hkpMoppCodeGenerator::resize(v7);
}

// File Line: 1258
// RVA: 0xDFD300
void __fastcall hkpMoppDefaultAssembler::addTermIdOffset(hkpMoppDefaultAssembler *this, unsigned int offset)
{
  hkpMoppCodeGenerator *v2; // rbx
  hkpMoppCodeGenerator *v3; // rcx

  if ( offset >= 0x100 )
  {
    v3 = this->m_code;
    if ( offset >= 0x10000 )
      hkpMoppCodeGenerator::addCommand32(v3, 11, offset);
    else
      hkpMoppCodeGenerator::addCommand16(v3, 10, offset);
  }
  else
  {
    v2 = this->m_code;
    v2->m_code[v2->m_size - (signed __int64)v2->m_pos++ - 1] = offset;
    if ( v2->m_pos >= v2->m_size )
      hkpMoppCodeGenerator::resize(v2);
    v2->m_code[v2->m_size - (signed __int64)v2->m_pos++ - 1] = 9;
    if ( v2->m_pos >= v2->m_size )
      hkpMoppCodeGenerator::resize(v2);
  }
}

// File Line: 1276
// RVA: 0xDFDA50
void __fastcall hkpMoppDefaultAssembler::addCut(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode, hkpMoppAssemblerNodeInfo *currentInfo)
{
  hkpMoppAssemblerNodeInfo *v3; // r13
  hkpMoppDefaultAssembler *v4; // rbp
  signed int v5; // edi
  hkEnum<enum hkpMoppAssemblerData::hkpCutCommandType,signed char> *v6; // rsi
  int *v7; // r14
  int *v8; // r15
  hkpMoppCodeGenerator *v9; // r9
  int v10; // ecx
  int v11; // ebx
  int v12; // ebx
  hkpMoppCodeGenerator *v13; // rcx
  hkpMoppCodeGenerator *v14; // rcx
  int v15; // ebx
  hkpMoppCodeGenerator *v16; // rcx

  v3 = currentInfo;
  v4 = this;
  v5 = 0;
  v6 = currentNode->m_assemblerData.m_cutCommandType;
  v7 = &currentInfo->m_extents[0][1];
  v8 = currentInfo->m_accumOffset;
  do
  {
    if ( v6->m_storage == 1 )
    {
      v9 = v4->m_code;
      v10 = v3->m_currentBitsResolution;
      v11 = *(v7 - 1) - *v8;
      v9->m_code[v9->m_size - v9->m_pos++ - 1] = ((*v7 - *v8) >> v10) + 1;
      v12 = v11 >> v10;
      if ( v9->m_pos >= v9->m_size )
        hkpMoppCodeGenerator::resize(v9);
      v13 = v4->m_code;
      v13->m_code[v13->m_size - v13->m_pos++ - 1] = v12;
      if ( v13->m_pos >= v13->m_size )
        hkpMoppCodeGenerator::resize(v13);
      v14 = v4->m_code;
      v14->m_code[v14->m_size - v14->m_pos++ - 1] = v5 + 38;
      if ( v14->m_pos >= v14->m_size )
        hkpMoppCodeGenerator::resize(v14);
    }
    if ( v6->m_storage == 2 )
    {
      v15 = *(v7 - 1);
      hkpMoppCodeGenerator::addParam24(v4->m_code, *v7 + 1);
      hkpMoppCodeGenerator::addParam24(v4->m_code, v15);
      v16 = v4->m_code;
      v16->m_code[v16->m_size - v16->m_pos++ - 1] = v5 + 41;
      if ( v16->m_pos >= v16->m_size )
        hkpMoppCodeGenerator::resize(v16);
    }
    ++v5;
    ++v8;
    ++v6;
    v7 += 2;
  }
  while ( v5 < 3 );
}

// File Line: 1310
// RVA: 0xDFD4B0
void __fastcall hkpMoppDefaultAssembler::addSplit(hkpMoppDefaultAssembler *this, int pright, int pleft, HK_MOPP_SPLIT_DIRECTIONS directionCode, int lpos, int rpos)
{
  int v6; // er14
  hkpMoppDefaultAssembler *v7; // rbx
  hkpMoppCodeGenerator *v8; // rcx
  char v9; // si
  char v10; // r12
  char v11; // r15
  int v12; // edi
  int v13; // ebp
  hkpMoppCodeGenerator *v14; // rcx
  hkpMoppCodeGenerator *v15; // rcx
  hkpMoppCodeGenerator *v16; // rcx
  hkpMoppCodeGenerator *v17; // rcx
  hkpMoppCodeGenerator *v18; // rcx
  char v19; // si
  hkpMoppCodeGenerator *v20; // rcx
  hkpMoppCodeGenerator *v21; // rcx
  hkpMoppCodeGenerator *v22; // rcx
  hkpMoppCodeGenerator *v23; // rcx
  hkpMoppCodeGenerator *v24; // rcx
  hkpMoppCodeGenerator *v25; // rcx

  LOBYTE(v6) = rpos;
  v7 = this;
  v8 = this->m_code;
  v9 = directionCode;
  v10 = pleft;
  v11 = pright;
  v12 = v8->m_pos - rpos;
  if ( (signed int)directionCode >= 3 )
    goto LABEL_40;
  v13 = v8->m_pos - lpos;
  if ( (v13 > 0 || v12 > 248) && v13 < 0x10000 && v12 < 0x10000 )
  {
    v8->m_code[v8->m_size - v8->m_pos++ - 1] = v12;
    if ( v8->m_pos >= v8->m_size )
      hkpMoppCodeGenerator::resize(v8);
    v14 = v7->m_code;
    v14->m_code[v14->m_size - v14->m_pos++ - 1] = BYTE1(v12);
    if ( v14->m_pos >= v14->m_size )
      hkpMoppCodeGenerator::resize(v14);
    v15 = v7->m_code;
    v15->m_code[v15->m_size - v15->m_pos++ - 1] = v13;
    if ( v15->m_pos >= v15->m_size )
      hkpMoppCodeGenerator::resize(v15);
    v16 = v7->m_code;
    v16->m_code[v16->m_size - v16->m_pos++ - 1] = BYTE1(v13);
    if ( v16->m_pos >= v16->m_size )
      hkpMoppCodeGenerator::resize(v16);
    v17 = v7->m_code;
    v17->m_code[v17->m_size - v17->m_pos++ - 1] = v11;
    if ( v17->m_pos >= v17->m_size )
      hkpMoppCodeGenerator::resize(v17);
    v18 = v7->m_code;
    v18->m_code[v18->m_size - v18->m_pos++ - 1] = v10;
    if ( v18->m_pos >= v18->m_size )
      hkpMoppCodeGenerator::resize(v18);
    v19 = v9 + 35;
    goto LABEL_36;
  }
  if ( pleft - pright != 1 )
  {
LABEL_40:
    if ( v12 > 251 )
    {
      hkpMoppDefaultAssembler::addJump(v7, rpos);
      v6 = v7->m_code->m_pos;
    }
    hkpMoppDefaultAssembler::addJump(v7, lpos);
    v22 = v7->m_code;
    v22->m_code[v22->m_size - v22->m_pos++ - 1] = LOBYTE(v22->m_pos) - v6;
    if ( v22->m_pos >= v22->m_size )
      hkpMoppCodeGenerator::resize(v22);
    v23 = v7->m_code;
    v23->m_code[v23->m_size - v23->m_pos++ - 1] = v11;
    if ( v23->m_pos >= v23->m_size )
      hkpMoppCodeGenerator::resize(v23);
    v24 = v7->m_code;
    v24->m_code[v24->m_size - v24->m_pos++ - 1] = v10;
    if ( v24->m_pos >= v24->m_size )
      hkpMoppCodeGenerator::resize(v24);
    v19 = v9 + 16;
  }
  else
  {
    if ( v12 > 251 )
    {
      hkpMoppDefaultAssembler::addJump(v7, rpos);
      v6 = v7->m_code->m_pos;
    }
    hkpMoppDefaultAssembler::addJump(v7, lpos);
    v20 = v7->m_code;
    v20->m_code[v20->m_size - v20->m_pos++ - 1] = LOBYTE(v20->m_pos) - v6;
    if ( v20->m_pos >= v20->m_size )
      hkpMoppCodeGenerator::resize(v20);
    v21 = v7->m_code;
    v21->m_code[v21->m_size - v21->m_pos++ - 1] = v11;
    if ( v21->m_pos >= v21->m_size )
      hkpMoppCodeGenerator::resize(v21);
    v19 = v9 + 32;
  }
LABEL_36:
  v25 = v7->m_code;
  v25->m_code[v25->m_size - v25->m_pos++ - 1] = v19;
  if ( v25->m_pos >= v25->m_size )
    hkpMoppCodeGenerator::resize(v25);
}

// File Line: 1380
// RVA: 0xDFD3B0
void __fastcall hkpMoppDefaultAssembler::checkAndAddProperties(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode, hkpMoppAssemblerNodeInfo *parentInfo, hkpMoppAssemblerNodeInfo *currentInfo)
{
  int v4; // er8

  if ( currentNode->m_parent )
  {
    if ( !currentInfo->m_propertiesSpread[0] )
    {
      if ( parentInfo->m_propertiesSpread[0] )
        hkpMoppDefaultAssembler::addProperty(this, 0, currentInfo->m_propertiesOffset[0]);
    }
  }
  else if ( !currentInfo->m_propertiesSpread[0] )
  {
    v4 = currentInfo->m_propertiesOffset[0];
    if ( v4 )
      hkpMoppDefaultAssembler::addProperty(this, 0, v4);
  }
}

// File Line: 1402
// RVA: 0xDFD880
__int64 __fastcall hkpMoppDefaultAssembler::addTerminals(hkpMoppDefaultAssembler *this, hkpMoppTreeTerminal *thisNode, hkpMoppAssemblerNodeInfo *parentInfo, hkpMoppAssemblerNodeInfo *currentInfo)
{
  hkpMoppAssemblerNodeInfo *v4; // r15
  hkpMoppDefaultAssembler *v5; // r14
  hkpMoppCodeGenerator *v6; // rcx
  hkpMoppTreeTerminal *v7; // rbp
  unsigned int v8; // er8
  int v9; // er12
  int *v10; // rsi
  int v11; // edi
  signed __int64 v12; // rbp
  unsigned int *v13; // rbx
  int v14; // er8

  v4 = parentInfo;
  v5 = this;
  v6 = this->m_code;
  v7 = thisNode;
  v8 = thisNode->m_primitive->m_primitiveID - currentInfo->m_terminalOffset;
  v9 = v6->m_pos;
  if ( v8 >= 0x20 )
  {
    if ( v8 >= 0x100 )
    {
      if ( v8 >= 0x10000 )
      {
        if ( v8 >= 0x1000000 )
          hkpMoppCodeGenerator::addCommand32(v6, 83, v8);
        else
          hkpMoppCodeGenerator::addCommand24(v6, 82, v8);
      }
      else
      {
        hkpMoppCodeGenerator::addCommand16(v6, 81, v8);
      }
    }
    else
    {
      hkpMoppCodeGenerator::addCommand8(v6, 80, v8);
    }
  }
  else
  {
    v6->m_code[v6->m_size - v9 - 1] = v8 + 48;
    if ( ++v6->m_pos >= v6->m_size )
      hkpMoppCodeGenerator::resize(v6);
  }
  v10 = &v7->m_numProperties;
  v11 = 0;
  if ( v7->m_numProperties > 0 )
  {
    v12 = (char *)v7 - (char *)v4;
    v13 = v4->m_propertiesSpread;
    do
    {
      v14 = *(unsigned int *)((char *)v13 + v12 - 16);
      if ( v14 && *v13 )
        hkpMoppDefaultAssembler::addProperty(v5, v11, v14);
      ++v11;
      ++v13;
    }
    while ( v11 < *v10 );
  }
  return (unsigned int)(v5->m_code->m_pos - v9);
}

// File Line: 1456
// RVA: 0xDFD9F0
void __fastcall hkpMoppDefaultAssembler::addJump(hkpMoppDefaultAssembler *this, unsigned int jumpPos)
{
  hkpMoppCodeGenerator *v2; // rcx
  signed int v3; // er8

  v2 = this->m_code;
  v3 = v2->m_pos - jumpPos;
  if ( v3 > 0 )
  {
    if ( v3 >= 255 )
    {
      if ( v3 >= 0xFFFF )
      {
        if ( v3 >= 0xFFFFFF )
          hkpMoppCodeGenerator::addCommand32(v2, 8, v3);
        else
          hkpMoppCodeGenerator::addCommand24(v2, 7, v3);
      }
      else
      {
        hkpMoppCodeGenerator::addCommand16(v2, 6, v3);
      }
    }
    else
    {
      hkpMoppCodeGenerator::addCommand8(v2, 5, v3);
    }
  }
}

// File Line: 1486
// RVA: 0xDFD3F0
signed __int64 __fastcall hkpMoppDefaultAssembler::getSplitCode(hkpMoppDefaultAssembler *this, hkVector4f *norm)
{
  float v2; // xmm2_4
  signed __int64 result; // rax
  float v4; // xmm1_4
  bool v5; // cf
  float v6; // xmm2_4
  float v7; // xmm1_4

  if ( norm->m_quad.m128_f32[0] <= 0.1 )
  {
    if ( norm->m_quad.m128_f32[1] <= 0.1 )
    {
      result = 2i64;
    }
    else
    {
      v7 = norm->m_quad.m128_f32[2];
      result = 1i64;
      if ( v7 <= 0.1 )
      {
        if ( v7 < -0.1 )
          result = 4i64;
      }
      else
      {
        result = 3i64;
      }
    }
  }
  else
  {
    v2 = norm->m_quad.m128_f32[2];
    result = 0i64;
    if ( v2 <= 0.1 )
    {
      v5 = v2 < -0.1;
      v6 = norm->m_quad.m128_f32[1];
      if ( v5 )
      {
        result = 6i64;
        if ( v6 <= 0.1 )
        {
          if ( v6 < -0.1 )
            result = 12i64;
        }
        else
        {
          result = 10i64;
        }
      }
      else if ( v6 <= 0.1 )
      {
        if ( v6 < -0.1 )
          result = 8i64;
      }
      else
      {
        result = 7i64;
      }
    }
    else
    {
      v4 = norm->m_quad.m128_f32[1];
      result = 5i64;
      if ( v4 <= 0.1 )
      {
        if ( v4 < -0.1 )
          result = 11i64;
      }
      else
      {
        result = 9i64;
      }
    }
  }
  return result;
}

// File Line: 1543
// RVA: 0xDFC310
void __fastcall hkpMoppDefaultAssembler::findPlanes(hkpMoppDefaultAssembler *this, hkpMoppTreeInternalNode *node, hkpMoppAssemblerNodeInfo *info, int *pleft, int *pright)
{
  hkpMoppSplittingPlaneDirection *v5; // rdi
  signed int v6; // er11
  hkpMoppAssemblerNodeInfo *v7; // rbp
  signed int v8; // er10
  signed int v9; // eax
  signed int v10; // esi
  float v11; // xmm0_4
  float v12; // xmm0_4
  double v13; // xmm6_8
  double v14; // xmm8_8
  float v15; // xmm3_4
  float v16; // xmm2_4
  int v17; // er8
  int v18; // ecx
  unsigned int v19; // xmm0_4
  __m128 v20; // xmm6
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  unsigned int v23; // xmm0_4
  __m128 v24; // xmm2
  __m128 v25; // xmm7
  int v26; // edx
  int v27; // eax
  int v28; // er8
  int v29; // eax
  signed int v30; // ecx
  int v31; // eax
  signed int v32; // edx
  int v33; // eax
  __m128i v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm4
  double v37; // xmm4_8
  double v38; // xmm7_8
  double v39; // xmm6_8
  double v40; // xmm8_8
  double v41; // xmm6_8
  double v42; // xmm8_8
  double v43; // xmm0_8
  int v44; // er8
  signed int v45; // edx
  unsigned int v46; // xmm0_4
  __m128 v47; // xmm2
  __m128 v48; // xmm3
  signed int v49; // ecx
  unsigned int v50; // xmm0_4
  __m128 v51; // xmm2
  __m128 v52; // xmm5
  int v53; // eax
  int v54; // ecx
  float v55; // [rsp+48h] [rbp+10h]

  v5 = node->m_plane;
  v6 = 0;
  v7 = info;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  if ( v5->m_direction.m_quad.m128_f32[0] != 0.0 )
  {
    v8 = 1;
    if ( v5->m_direction.m_quad.m128_f32[0] < 0.0 )
      v9 = 1;
  }
  v11 = v5->m_direction.m_quad.m128_f32[1];
  if ( v11 != 0.0 )
  {
    ++v8;
    v10 = 1;
    if ( v11 < 0.0 )
      ++v9;
  }
  v12 = v5->m_direction.m_quad.m128_f32[2];
  if ( v12 != 0.0 )
  {
    ++v8;
    v10 = 2;
    if ( v12 < 0.0 )
      ++v9;
  }
  v13 = node->m_planeRightPosition;
  v14 = node->m_planeLeftPosition;
  if ( v8 == 1 )
  {
    v15 = this->m_codeInfo.m_offset.m_quad.m128_f32[3];
    v16 = this->m_codeInfo.m_offset.m_quad.m128_f32[v10];
    v17 = info->m_accumOffset[v10];
    v18 = v7->m_currentBitsResolution;
    *(float *)&v19 = (v13 - v16) * v15;
    v20 = (__m128)v19;
    v21 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v19, 1u), 1u));
    v22 = _mm_sub_ps(
            _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v19, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23);
    *(float *)&v23 = (v14 - v16) * v15;
    v24 = _mm_sub_ps(
            _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v23, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23);
    v25 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v23, 1u), 1u));
    v26 = ((signed int)COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                             v21,
                                                             _mm_add_ps(
                                                               _mm_cvtepi32_ps((__m128i)_mm_cmpltps(v20, v22)),
                                                               v22)) | v21.m128_i32[0] & v20.m128_i32[0])
         - v17) >> v18;
    v27 = (signed int)COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                            v25,
                                                            _mm_add_ps(
                                                              _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v23, v24)),
                                                              v24)) | v25.m128_i32[0] & v23)
        - v17;
    v28 = 255;
    v29 = v27 >> v18;
    v30 = 0;
    v31 = v29 + 1;
    if ( v26 > 0 )
      v30 = v26;
    v32 = 0;
    if ( v31 > 0 )
      v32 = v31;
    v33 = 255;
    if ( v30 < 255 )
      v33 = v30;
    if ( v32 < 255 )
      v28 = v32;
    *pright = v33;
    *pleft = v28;
    if ( *pright < 0 )
      *pright = 0;
  }
  else
  {
    v55 = this->m_codeInfo.m_offset.m_quad.m128_f32[3];
    v34 = (__m128i)_mm_shuffle_ps((__m128)LODWORD(v55), (__m128)LODWORD(v55), 0);
    v35 = _mm_cmpeqps((__m128)v34, (__m128)0i64);
    v36 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_or_ps(
                  _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v34, 0x1Fu), 0x1Fu), (__m128)_xmm), v35),
                  _mm_andnot_ps(v35, _mm_div_ps(query.m_quad, (__m128)v34))),
                _mm_unpacklo_ps(
                  _mm_unpacklo_ps(
                    (__m128)COERCE_UNSIGNED_INT((float)info->m_accumOffset[0]),
                    (__m128)COERCE_UNSIGNED_INT((float)info->m_accumOffset[2])),
                  _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)info->m_accumOffset[1]), (__m128)0i64))),
              this->m_codeInfo.m_offset.m_quad),
            v5->m_direction.m_quad);
    v35.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 0)))
                    + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 170));
    v37 = DOUBLE_1_0;
    v38 = DOUBLE_1_0;
    *(double *)v34.m128i_i64 = 1.0 / (float)(1 << info->m_currentBitsResolution);
    v39 = (v13 - v35.m128_f32[0]) * v55 * *(double *)v34.m128i_i64;
    v40 = (v14 - v35.m128_f32[0]) * v55 * *(double *)v34.m128i_i64;
    if ( v8 == 2 )
    {
      v37 = DOUBLE_1_414213538169861;
      v38 = DOUBLE_0_5;
    }
    else if ( v8 == 3 )
    {
      v37 = DOUBLE_1_732050776481628;
      v38 = DOUBLE_0_3333333333333333;
    }
    v41 = v39 * v37;
    v42 = v40 * v37;
    if ( v9 )
    {
      v43 = (double)(255 * v9);
      v41 = v41 + v43;
      v42 = v42 + v43;
    }
    v44 = 255;
    v45 = 0;
    *(float *)&v46 = v38 * v41;
    v47 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v46, 1u), 1u));
    v48 = _mm_sub_ps(
            _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v46, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23);
    v49 = (signed int)COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                            v47,
                                                            _mm_add_ps(
                                                              _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v46, v48)),
                                                              v48)) | v47.m128_i32[0] & v46);
    *(float *)&v50 = v38 * v42;
    v51 = _mm_sub_ps(
            _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v50, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23);
    v52 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v50, 1u), 1u));
    v53 = (signed int)COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                            v52,
                                                            _mm_add_ps(
                                                              _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v50, v51)),
                                                              v51)) | v52.m128_i32[0] & v50)
        + 1;
    if ( v49 > 0 )
      v45 = v49;
    v54 = 255;
    if ( v53 > 0 )
      v6 = v53;
    if ( v45 < 255 )
      v54 = v45;
    if ( v6 < 255 )
      v44 = v6;
    *pright = v54;
    *pleft = v44;
  }
}

// File Line: 1673
// RVA: 0xDFB680
void __fastcall hkpMoppDefaultAssembler::getScaleInfo(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *rootNode, hkpMoppCode::CodeInfo *moppCodeInfo)
{
  float v3; // xmm4_4
  hkpMoppTreeNode::hkpMopp3DOPExtents *v4; // rax
  signed __int64 v5; // rcx
  float v6; // xmm0_4

  v3 = 0.0;
  v4 = &rootNode->m_extents;
  v5 = 3i64;
  moppCodeInfo->m_offset.m_quad = _mm_unpacklo_ps(
                                    _mm_unpacklo_ps(
                                      (__m128)LODWORD(rootNode->m_extents.m_extent[0].m_min),
                                      (__m128)LODWORD(rootNode->m_extents.m_extent[2].m_min)),
                                    _mm_unpacklo_ps(
                                      (__m128)LODWORD(rootNode->m_extents.m_extent[1].m_min),
                                      (__m128)0i64));
  do
  {
    v6 = v4->m_extent[0].m_max;
    v4 = (hkpMoppTreeNode::hkpMopp3DOPExtents *)((char *)v4 + 8);
    v3 = fmaxf(v3, v6 - v4[-1].m_extent[2].m_min);
    --v5;
  }
  while ( v5 );
  moppCodeInfo->m_offset.m_quad.m128_f32[3] = (float)(254.0 / v3) * 65536.0;
}

// File Line: 1694
// RVA: 0xDFB770
__int64 __fastcall hkpMoppDefaultAssembler::assembleCutAndTerminalCommand(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode, hkpMoppAssemblerNodeInfo *parentInfo, hkpMoppAssemblerNodeInfo *currentInfo)
{
  hkpMoppAssemblerNodeInfo *v4; // rsi
  hkpMoppAssemblerNodeInfo *v5; // rbx
  hkpMoppTreeTerminal *v6; // r14
  hkpMoppDefaultAssembler *v7; // rbp
  hkpMoppCodeGenerator *v8; // rax
  int v9; // edi
  int v10; // eax

  v4 = currentInfo;
  v5 = parentInfo;
  v6 = (hkpMoppTreeTerminal *)currentNode;
  v7 = this;
  hkpMoppDefaultAssembler::fixScale(this, currentNode);
  v8 = v7->m_code;
  ++v7->m_numNodesAssembled;
  v9 = v8->m_pos;
  hkpMoppDefaultAssembler::addTerminals(v7, v6, v5, v4);
  hkpMoppDefaultAssembler::addCut(v7, (hkpMoppTreeNode *)&v6->m_parent, v4);
  v6->m_assemblerData.m_assembledAddress = v7->m_code->m_pos;
  v10 = v7->m_code->m_pos;
  v6->m_assemblerData.m_isAssembled.m_bool = 1;
  return (unsigned int)(v10 - v9);
}

// File Line: 1714
// RVA: 0xDFB800
__int64 __fastcall hkpMoppDefaultAssembler::assembleNonTerminalCommand(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode, hkpMoppAssemblerNodeInfo *parentInfo, hkpMoppAssemblerNodeInfo *currentInfo, hkpMoppAssemblerRescaleCommand *rescaleCommandInfo)
{
  hkpMoppAssemblerNodeInfo *v5; // r14
  hkpMoppAssemblerNodeInfo *v6; // r15
  hkpMoppTreeNode *v7; // rbp
  hkpMoppDefaultAssembler *v8; // rsi
  int v9; // er12
  hkpMoppExtent v10; // rbx
  hkpMoppExtent v11; // rdi
  HK_MOPP_SPLIT_DIRECTIONS v12; // eax
  int pleft; // [rsp+60h] [rbp+8h]
  int pright; // [rsp+68h] [rbp+10h]

  v5 = currentInfo;
  v6 = parentInfo;
  v7 = currentNode;
  v8 = this;
  hkpMoppDefaultAssembler::fixScale(this, currentNode);
  v9 = v8->m_code->m_pos;
  hkpMoppDefaultAssembler::findPlanes(v8, (hkpMoppTreeInternalNode *)v7, v5, &pleft, &pright);
  v10 = v7[1].m_extents.m_extent[2];
  v11 = v7[1].m_extents.m_extent[1];
  v12 = hkpMoppDefaultAssembler::getSplitCode(v8, (hkVector4f *)v7[1].m_parent);
  hkpMoppDefaultAssembler::addSplit(
    v8,
    pright,
    pleft,
    v12,
    *(_DWORD *)(*(_QWORD *)&v11 + 96i64),
    *(_DWORD *)(*(_QWORD *)&v10 + 96i64));
  if ( v5->m_terminalOffset != v6->m_terminalOffset )
    hkpMoppDefaultAssembler::addTermIdOffset(v8, v5->m_terminalOffset - v6->m_terminalOffset);
  hkpMoppDefaultAssembler::checkAndAddProperties(v8, v7, v6, v5);
  hkpMoppDefaultAssembler::addCut(v8, v7, v5);
  if ( rescaleCommandInfo->m_doRescale.m_bool )
    hkpMoppDefaultAssembler::addRescale(v8, rescaleCommandInfo);
  v7->m_assemblerData.m_assembledAddress = v8->m_code->m_pos;
  v7->m_assemblerData.m_isAssembled.m_bool = 1;
  return (unsigned int)(v8->m_code->m_pos - v9);
}

// File Line: 1793
// RVA: 0xDFB910
__int64 __fastcall hkpMoppDefaultAssembler::assembleJumpChunkCommand(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *currentNode)
{
  hkpMoppTreeNode *v2; // rbp
  int v3; // er14
  hkpMoppDefaultAssembler *v4; // rsi
  int v5; // edi
  hkpMoppCodeGenerator *v6; // rbx
  __int64 v7; // r8
  hkpMoppCodeGenerator::JumpCommandInfo *v8; // r9
  int v9; // ecx

  v2 = currentNode;
  v3 = this->m_code->m_pos;
  v4 = this;
  hkpMoppDefaultAssembler::addJumpChunk(this, currentNode->m_assemblerData.m_chunkId);
  v5 = v4->m_code->m_pos;
  v2->m_assemblerData.m_assembledAddress = v5;
  v2->m_assemblerData.m_isAssembled.m_bool = 1;
  v6 = v4->m_code;
  if ( v6->m_jumpCommands.m_size == (v6->m_jumpCommands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_jumpCommands, 8);
  v7 = v6->m_jumpCommands.m_size;
  v8 = &v6->m_jumpCommands.m_data[v7];
  v6->m_jumpCommands.m_size = v7 + 1;
  v9 = v2->m_assemblerData.m_chunkId;
  v8->m_position = v5;
  v8->m_chunkId = v9;
  hkpMoppCodeGenerator::validateJumpCommands(v4->m_code);
  return (unsigned int)(v5 - v3);
}

// File Line: 1823
// RVA: 0xDFB190
void __fastcall hkpMoppDefaultAssembler::assemble(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *rootNode, hkpMoppNodeMgr *mgr, int minAssembledElems)
{
  hkpMoppTreeNode *v4; // rsi
  hkpMoppDefaultAssembler *v5; // rdi
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // eax
  signed int v10; // ebx
  int v11; // eax
  unsigned int *v12; // rdx
  __int64 v13; // r8
  unsigned int v14; // ecx
  unsigned int v15; // eax
  int v16; // ecx
  int v17; // er8
  char v18; // cl
  unsigned int v19; // eax
  signed __int64 v20; // r14
  int v21; // edx
  signed __int64 v22; // r9
  int v23; // er8
  unsigned int v24; // eax
  int v25; // ecx
  unsigned int v26; // eax
  int v27; // eax
  int v28; // eax
  unsigned int *v29; // rdx
  __int64 v30; // r8
  unsigned int v31; // ecx
  unsigned int v32; // eax
  int v33; // ecx
  int v34; // edx
  char v35; // cl
  unsigned int v36; // eax
  int v37; // edx
  unsigned int v38; // eax
  signed int v39; // ecx
  hkpMoppCompilerChunkInfo *v40; // rbx
  hkpMoppCodeGenerator *v41; // rbx
  int v42; // ecx
  hkpMoppCompilerChunkInfo *v43; // rcx
  hkReferencedObject *v44; // rcx
  signed __int64 v45; // rbx
  hkArray<unsigned int,hkContainerHeapAllocator> terminals; // [rsp+30h] [rbp-B0h]
  hkpMoppAssemblerNodeInfo parentInfo; // [rsp+40h] [rbp-A0h]
  int v48; // [rsp+88h] [rbp-58h]
  int v49; // [rsp+8Ch] [rbp-54h]
  int v50; // [rsp+90h] [rbp-50h]
  __int64 v51; // [rsp+94h] [rbp-4Ch]
  __int64 v52; // [rsp+9Ch] [rbp-44h]
  int v53; // [rsp+A4h] [rbp-3Ch]
  int v54; // [rsp+A8h] [rbp-38h]
  int v55; // [rsp+ACh] [rbp-34h]
  hkpMoppAssemblerNodeInfo currentInfo; // [rsp+D0h] [rbp-10h]
  hkpMoppAssemblerNodeInfo v57; // [rsp+130h] [rbp+50h]

  v4 = rootNode;
  v5 = this;
  this->m_nodeMgr = mgr;
  this->m_minAssembledElems = minAssembledElems;
  this->m_numNodesAssembled = 0;
  if ( rootNode )
  {
    ((void (__fastcall *)(hkpMoppDefaultAssembler *, hkpMoppTreeNode *, hkpMoppCode::CodeInfo *))this->vfptr[3].__vecDelDtor)(
      this,
      rootNode,
      &this->m_codeInfo);
    v5->m_minDepthToBuild = 0;
    v6 = v4->m_maxPrimitiveId;
    if ( v6 )
    {
      v7 = 0;
      do
      {
        ++v7;
        v6 >>= 1;
      }
      while ( v6 );
      v5->m_minDepthToBuild = v7;
    }
    v8 = v5->m_minDepthToBuild;
    v5->m_halfTreeDepth = v8 >> 1;
    v5->m_minDepthToBuild = v5->m_params.m_groupLevels * (v8 / v5->m_params.m_groupLevels + 2) - 1;
    hkpMoppAssemblerNodeInfo::updateExtents(&parentInfo, v4, &v5->m_codeInfo);
    v9 = v4->m_maxPrimitiveId - v4->m_minPrimitiveId;
    v10 = -1;
    *(_QWORD *)&parentInfo.m_currentBitsResolution = 16i64;
    parentInfo.m_terminalSpread = v9;
    v11 = v4->m_numProperties;
    *(_QWORD *)&parentInfo.m_accumOffset[1] = 0i64;
    parentInfo.m_level = -1;
    parentInfo.m_terminalOffset = 0;
    parentInfo.m_ignoreBandControlCode.m_bool = 0;
    parentInfo.m_numProperties = v11;
    if ( v11 > 0 )
    {
      v12 = v4->m_maxPropertyValue;
      v13 = (unsigned int)v11;
      do
      {
        v14 = *(v12 - 1);
        v15 = *v12;
        ++v12;
        *(unsigned int *)((char *)v12 + (char *)&parentInfo.m_maxExtentsSignificantBits - (char *)v4 - 4) = v14;
        *(unsigned int *)((char *)v12 + (char *)parentInfo.m_extents - (char *)v4 - 4) = v15 - v14;
        --v13;
      }
      while ( v13 );
    }
    v16 = parentInfo.m_extents[1][1] - parentInfo.m_extents[1][0];
    if ( parentInfo.m_extents[0][1] - parentInfo.m_extents[0][0] > parentInfo.m_extents[1][1]
                                                                 - parentInfo.m_extents[1][0] )
      v16 = parentInfo.m_extents[0][1] - parentInfo.m_extents[0][0];
    v17 = parentInfo.m_extents[2][1] - parentInfo.m_extents[2][0];
    if ( v16 > parentInfo.m_extents[2][1] - parentInfo.m_extents[2][0] )
      v17 = v16;
    v18 = 0;
    v19 = v17;
    if ( v17 )
    {
      do
      {
        ++v18;
        v19 >>= 1;
      }
      while ( v19 );
    }
    v20 = 3i64;
    v21 = -1;
    v22 = 3i64;
    v23 = __ROR4__(__ROL4__(1, v18), 4) + v17;
    do
    {
      v24 = v23;
      v25 = 0;
      if ( v23 )
      {
        do
        {
          ++v25;
          v24 >>= 1;
        }
        while ( v24 );
      }
      if ( v25 > v21 )
        v21 = v25;
      --v22;
    }
    while ( v22 );
    if ( v21 > 24 )
      v21 = 24;
    parentInfo.m_maxExtentsSignificantBits = v21;
    hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(&currentInfo, &parentInfo, v4, &v5->m_codeInfo);
    hkpMoppDefaultAssembler::preCalcScale(v5, v4, &parentInfo, &currentInfo);
    hkpMoppAssemblerNodeInfo::updateExtents((hkpMoppAssemblerNodeInfo *)((char *)&parentInfo + 48), v4, &v5->m_codeInfo);
    v26 = v4->m_maxPrimitiveId;
    v51 = 16i64;
    v27 = v26 - v4->m_minPrimitiveId;
    v52 = 0i64;
    parentInfo.m_accumOffset[2] = -1;
    v54 = v27;
    v28 = v4->m_numProperties;
    v53 = 0;
    LOBYTE(parentInfo.m_terminalOffset) = 0;
    v55 = v28;
    if ( v28 > 0 )
    {
      v29 = v4->m_maxPropertyValue;
      v30 = (unsigned int)v28;
      do
      {
        v31 = *(v29 - 1);
        v32 = *v29;
        ++v29;
        *(unsigned int *)((char *)v29 + (char *)&parentInfo.m_terminalSpread - (char *)v4 - 4) = v31;
        *(unsigned int *)((char *)v29 + (char *)&parentInfo.m_numProperties - (char *)v4 - 4) = v32 - v31;
        --v30;
      }
      while ( v30 );
    }
    v33 = v48 - parentInfo.m_propertiesSpread[0];
    if ( (signed int)(parentInfo.m_propertiesOffset[0] - parentInfo.m_numProperties) > (signed int)(v48
                                                                                                  - parentInfo.m_propertiesSpread[0]) )
      v33 = parentInfo.m_propertiesOffset[0] - parentInfo.m_numProperties;
    v34 = v50 - v49;
    if ( v33 > v50 - v49 )
      v34 = v33;
    v35 = 0;
    v36 = v34;
    if ( v34 )
    {
      do
      {
        ++v35;
        v36 >>= 1;
      }
      while ( v36 );
    }
    v37 = __ROR4__(__ROL4__(1, v35), 4) + v34;
    do
    {
      v38 = v37;
      v39 = 0;
      if ( v37 )
      {
        do
        {
          ++v39;
          v38 >>= 1;
        }
        while ( v38 );
      }
      if ( v39 > v10 )
        v10 = v39;
      --v20;
    }
    while ( v20 );
    if ( v10 > 24 )
      v10 = 24;
    parentInfo.m_terminalSpread = v10;
    hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(
      &currentInfo,
      (hkpMoppAssemblerNodeInfo *)((char *)&parentInfo + 48),
      v4,
      &v5->m_codeInfo);
    hkpMoppDefaultAssembler::preCalcCutPositions(
      v5,
      v4,
      (hkpMoppAssemblerCutInfo *)&parentInfo.m_accumOffset[2],
      (hkpMoppAssemblerCutInfo *)&currentInfo);
    hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(&v57, &parentInfo, v4, &v5->m_codeInfo);
    if ( v5->m_chunkInfo )
    {
      v4->m_assemblerData.m_chunkId = 0;
      v40 = v5->m_chunkInfo;
      if ( v40->m_chunks.m_size == (v40->m_chunks.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v40->m_chunks, 16);
      ++v40->m_chunks.m_size;
      v41 = v5->m_code;
      hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(
        (hkpMoppAssemblerNodeInfo *)((char *)&parentInfo + 48),
        &parentInfo,
        v4,
        &v5->m_codeInfo);
      terminals.m_data = 0i64;
      terminals.m_size = 0;
      terminals.m_capacityAndFlags = 2147483648;
      hkpMoppCodeGenerator::hkpMoppCodeGenerator((hkpMoppCodeGenerator *)&currentInfo, 0x100000);
      v5->m_code = (hkpMoppCodeGenerator *)&currentInfo;
      hkpMoppDefaultAssembler::calcChunkPoints(
        v5,
        v4,
        &parentInfo,
        (hkpMoppAssemblerNodeInfo *)((char *)&parentInfo + 48),
        &terminals);
      hkpMoppDefaultAssembler::calcTerminalIdsForChunks(v5, v4, v4->m_assemblerData.m_chunkId, 0);
      hkpMoppCodeGenerator::~hkpMoppCodeGenerator((hkpMoppCodeGenerator *)&currentInfo);
      terminals.m_size = 0;
      if ( terminals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          terminals.m_data,
          4 * terminals.m_capacityAndFlags);
      terminals.m_data = 0i64;
      terminals.m_size = 0;
      terminals.m_capacityAndFlags = 2147483648;
      hkpMoppCodeGenerator::hkpMoppCodeGenerator((hkpMoppCodeGenerator *)&currentInfo, 0x100000);
      v5->m_code = (hkpMoppCodeGenerator *)&currentInfo;
      hkpMoppDefaultAssembler::assembleSubNodeIntoChunks(
        v5,
        v4,
        &parentInfo,
        &v57,
        v4->m_assemblerData.m_chunkId,
        &terminals);
      if ( v5->m_chunkInfo->m_compressor )
      {
        v42 = v5->m_code->m_pos + 5;
        hkpMoppDefaultAssembler::addDataOffset(v5, v42 + (-v42 & 3), terminals.m_size);
      }
      v43 = v5->m_chunkInfo;
      v5->m_code = v41;
      copyCodeAndEmbedTerminals(v43, v41, (hkpMoppCodeGenerator *)&currentInfo, &terminals);
      v44 = (hkReferencedObject *)&v5->m_code->vfptr;
      v45 = (signed __int64)&v5->m_chunkInfo->m_chunks.m_data[v4->m_assemblerData.m_chunkId];
      *(_QWORD *)v45 = v44;
      hkReferencedObject::addReference(v44);
      *(_DWORD *)(v45 + 8) = v5->m_code->m_pos;
      hkpMoppCodeGenerator::~hkpMoppCodeGenerator((hkpMoppCodeGenerator *)&currentInfo);
      terminals.m_size = 0;
      if ( terminals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          terminals.m_data,
          4 * terminals.m_capacityAndFlags);
    }
    else
    {
      hkpMoppDefaultAssembler::assemblesubNode(v5, v4, &parentInfo, &v57);
    }
  }
}

