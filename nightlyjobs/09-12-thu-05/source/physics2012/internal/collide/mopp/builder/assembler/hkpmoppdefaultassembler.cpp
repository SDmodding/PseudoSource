// File Line: 29
// RVA: 0xDFB150
void __fastcall hkpMoppDefaultAssembler::updateParams(
        hkpMoppDefaultAssembler *this,
        hkpMoppAssembler::hkpMoppAssemblerParams *ap)
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
void __fastcall hkpMoppDefaultAssembler::hkpMoppDefaultAssembler(
        hkpMoppDefaultAssembler *this,
        hkpMoppAssembler::hkpMoppAssemblerParams *ap,
        hkpMoppCodeGenerator *code,
        hkpMoppMediator *mediator)
{
  int v6; // ebx
  hkpMoppSplittingPlaneDirection *v9; // rax
  hkpMoppSplittingPlaneDirection *v10; // rcx
  int v11; // eax
  int v12; // edx
  __int64 v13; // rcx
  hkpMoppSplittingPlaneDirection *m_data; // rax
  __m128 m_quad; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  int v19; // [rsp+70h] [rbp+8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppDefaultAssembler::`vftable;
  this->m_directions.m_data = 0i64;
  this->m_directions.m_size = 0;
  v6 = 0x80000000;
  this->m_directions.m_capacityAndFlags = 0x80000000;
  v19 = 416;
  v9 = (hkpMoppSplittingPlaneDirection *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                           &hkContainerHeapAllocator::s_alloc,
                                           &v19);
  this->m_directions.m_size = 13;
  v10 = v9;
  LODWORD(v9) = v19;
  this->m_directions.m_data = v10;
  v11 = (int)v9 / 32;
  if ( v11 )
    v6 = v11;
  this->m_directions.m_capacityAndFlags = v6;
  this->m_params.m_relativeFitToleranceOfInternalNodes = 0.5;
  this->m_params.m_absoluteFitToleranceOfInternalNodes = 0.2;
  this->m_params.m_absoluteFitToleranceOfAxisAlignedTriangles = (hkVector4f)_xmm;
  this->m_params.m_absoluteFitToleranceOfTriangles = 1.0;
  this->m_params.m_groupLevels = 5;
  this->m_params.m_interleavedBuildingEnabled.m_bool = 1;
  this->m_directions.m_data->m_direction = (hkVector4f)_xmm;
  this->m_directions.m_data[1].m_direction.m_quad = _xmm;
  this->m_directions.m_data[2].m_direction.m_quad = _xmm;
  this->m_directions.m_data->m_cost = 0.0;
  this->m_directions.m_data[1].m_cost = 0.0;
  this->m_directions.m_data[2].m_cost = 0.0;
  this->m_directions.m_data[3].m_direction = (hkVector4f)_xmm;
  this->m_directions.m_data[4].m_direction = (hkVector4f)_xmm;
  this->m_directions.m_data[5].m_direction.m_quad = _xmm;
  this->m_directions.m_data[3].m_cost = 0.2;
  this->m_directions.m_data[4].m_cost = 0.2;
  this->m_directions.m_data[5].m_cost = 0.2;
  this->m_directions.m_data[6].m_direction = (hkVector4f)_xmm;
  this->m_directions.m_data[7].m_direction = (hkVector4f)_xmm;
  this->m_directions.m_data[8].m_direction = (hkVector4f)_xmm;
  this->m_directions.m_data[6].m_cost = 0.25;
  this->m_directions.m_data[7].m_cost = 0.25;
  v12 = 0;
  v13 = 0i64;
  this->m_directions.m_data[8].m_cost = 0.25;
  this->m_directions.m_data[9].m_direction = (hkVector4f)_xmm;
  this->m_directions.m_data[10].m_direction = (hkVector4f)_xmm;
  this->m_directions.m_data[11].m_direction = (hkVector4f)_xmm;
  this->m_directions.m_data[12].m_direction = (hkVector4f)_xmm;
  this->m_directions.m_data[9].m_cost = 0.30000001;
  this->m_directions.m_data[10].m_cost = 0.31999999;
  this->m_directions.m_data[11].m_cost = 0.31999999;
  this->m_directions.m_data[12].m_cost = 0.34;
  do
  {
    m_data = this->m_directions.m_data;
    m_quad = m_data[v13++].m_direction.m_quad;
    v16 = _mm_mul_ps(m_quad, m_quad);
    v17 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170));
    v18 = _mm_rsqrt_ps(v17);
    m_data[v13 - 1].m_direction.m_quad = _mm_mul_ps(
                                           _mm_andnot_ps(
                                             _mm_cmple_ps(v17, (__m128)0i64),
                                             _mm_mul_ps(
                                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                               _mm_mul_ps(*(__m128 *)_xmm, v18))),
                                           m_quad);
    this->m_directions.m_data[v13 - 1].m_index = v12++;
  }
  while ( v12 < 13 );
  hkpMoppDefaultAssembler::updateParams(this, ap);
  this->m_code = code;
  this->m_mediator = mediator;
  this->m_nodeMgr = 0i64;
}is, a

// File Line: 96
// RVA: 0xDFB0E0
void __fastcall hkpMoppDefaultAssembler::~hkpMoppDefaultAssembler(hkpMoppDefaultAssembler *this)
{
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppDefaultAssembler::`vftable;
  m_capacityAndFlags = this->m_directions.m_capacityAndFlags;
  this->m_directions.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_directions.m_data,
      32 * m_capacityAndFlags);
  this->m_directions.m_data = 0i64;
  this->m_directions.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 101
// RVA: 0xDFDBB0
void __fastcall hkpMoppDefaultAssembler::releaseNode(hkpMoppDefaultAssembler *this, hkpMoppTreeNode *node)
{
  if ( !node->m_isTerminal.m_bool )
  {
    if ( this->m_params.m_interleavedBuildingEnabled.m_bool )
    {
      ((void (__fastcall *)(hkpMoppNodeMgr *, _QWORD))this->m_nodeMgr->vfptr[1].__first_virtual_table_function__)(
        this->m_nodeMgr,
        *(_QWORD *)&node[1].m_extents.m_extent[1]);
      ((void (__fastcall *)(hkpMoppNodeMgr *, _QWORD))this->m_nodeMgr->vfptr[1].__first_virtual_table_function__)(
        this->m_nodeMgr,
        *(_QWORD *)&node[1].m_extents.m_extent[2]);
      node[1].m_extents.m_extent[1] = 0i64;
      node[1].m_extents.m_extent[2] = 0i64;
    }
  }
}

// File Line: 126
// RVA: 0xDFCF40
hkBool *__fastcall hkpMoppDefaultAssembler::shouldAssemble(
        hkpMoppDefaultAssembler *this,
        hkBool *result,
        hkpMoppTreeNode *currentNode,
        hkpMoppAssemblerNodeInfo *currentInfo)
{
  if ( currentNode->m_numPrimitives < 22 || currentInfo->m_level > this->m_minDepthToBuild )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 143
// RVA: 0xDFC970
__int64 __fastcall hkpMoppDefaultAssembler::calcRescaleBits(
        hkpMoppDefaultAssembler *this,
        hkpMoppAssemblerNodeInfo *parentInfo,
        hkpMoppAssemblerNodeInfo *currentInfo)
{
  int m_maxExtentsSignificantBits; // eax
  int m_currentBitsResolution; // r8d
  int v5; // ecx
  int v6; // eax
  __int64 result; // rax

  m_maxExtentsSignificantBits = currentInfo->m_maxExtentsSignificantBits;
  m_currentBitsResolution = parentInfo->m_currentBitsResolution;
  v5 = 0;
  v6 = m_maxExtentsSignificantBits - 8;
  if ( v6 > 0 )
    v5 = v6;
  result = (unsigned int)(m_currentBitsResolution - v5);
  if ( (int)result > m_currentBitsResolution )
    return (unsigned int)m_currentBitsResolution;
  return result;
}

// File Line: 172
// RVA: 0xDFC9A0
void __fastcall hkpMoppDefaultAssembler::recalcRescale(
        hkpMoppDefaultAssembler *this,
        hkpMoppAssemblerNodeInfo *parent,
        hkpMoppAssemblerNodeInfo *info,
        hkpMoppAssemblerRescaleCommand *cmd)
{
  int v7; // eax
  int v8; // esi
  int *p_m_currentBitsResolution; // r14
  signed __int64 v10; // rbp
  signed __int64 v11; // r15
  int *v12; // rbx
  int *m_accumOffset; // r11
  int i; // eax
  int v15; // r9d

  v7 = hkpMoppDefaultAssembler::calcRescaleBits(this, parent, info);
  cmd->m_doRescale.m_bool = 0;
  if ( v7 <= 0 )
  {
    info->m_currentBitsResolution = parent->m_currentBitsResolution;
    info->m_accumOffset[0] = parent->m_accumOffset[0];
    info->m_accumOffset[1] = parent->m_accumOffset[1];
    info->m_accumOffset[2] = parent->m_accumOffset[2];
  }
  else
  {
    v8 = 4;
    p_m_currentBitsResolution = &parent->m_currentBitsResolution;
    if ( v7 < 4 )
      v8 = v7;
    v10 = (char *)parent - (char *)cmd + 32;
    v11 = (char *)cmd - (char *)info - 32;
$L_calc_bits:
    v12 = &info->m_extents[0][1];
    m_accumOffset = info->m_accumOffset;
    info->m_currentBitsResolution = *p_m_currentBitsResolution - v8;
    for ( i = 0; i < 3; ++i )
    {
      v15 = (*(v12 - 1) - *(int *)((char *)m_accumOffset + v11 + v10)) >> *p_m_currentBitsResolution;
      *m_accumOffset = *(int *)((char *)m_accumOffset + v11 + v10) + (v15 << *p_m_currentBitsResolution);
      *(int *)((char *)m_accumOffset + v11) = v15;
      if ( (*v12 - *m_accumOffset) >> info->m_currentBitsResolution >= 255 )
      {
        --v8;
        goto $L_calc_bits;
      }
      ++m_accumOffset;
      v12 += 2;
    }
    cmd->m_scaleCommand = v8;
    cmd->m_doRescale.m_bool = 1;
  }
}

// File Line: 228
// RVA: 0xDFC710
__int64 __fastcall hkpMoppDefaultAssembler::preCalcScale(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeNode *currentNode,
        hkpMoppAssemblerNodeInfo *parentInfo,
        hkpMoppAssemblerNodeInfo *currentInfo)
{
  bool v4; // zf
  int m_maxExtentsSignificantBits; // r11d
  hkpMoppAssemblerNodeInfo *v6; // r10
  float m_absoluteFitToleranceOfTriangles; // xmm2_4
  int v11; // r8d
  hkVector4f *p_m_absoluteFitToleranceOfAxisAlignedTriangles; // r9
  __int64 v13; // rdx
  int v14; // edi
  hkpMoppTreeNode::hkpMopp3DOPExtents *p_m_extents; // rcx
  float v16; // xmm1_4
  unsigned int j; // ecx
  int v19; // eax
  hkpMoppExtent v20; // rax
  int v21; // ecx
  __int64 i; // rdi
  hkpMoppTreeNode *v23; // rsi
  int v24; // eax
  int v25; // r9d
  int v26; // edx
  __int64 v27; // r8
  __int64 v28; // rcx
  int v29; // eax
  bool v30; // cc
  int v31; // [rsp+20h] [rbp-98h]
  __int64 v32; // [rsp+28h] [rbp-90h]
  int v33; // [rsp+30h] [rbp-88h]
  hkpMoppAssemblerRescaleCommand cmd; // [rsp+38h] [rbp-80h] BYREF
  hkpMoppAssemblerNodeInfo currentInfoa; // [rsp+50h] [rbp-68h] BYREF

  v4 = currentNode->m_isTerminal.m_bool == 0;
  m_maxExtentsSignificantBits = currentInfo->m_maxExtentsSignificantBits;
  v6 = currentInfo;
  v33 = m_maxExtentsSignificantBits;
  if ( v4 )
  {
    if ( !currentNode->m_assemblerData.m_scaleIsValid.m_bool && currentInfo->m_level < this->m_halfTreeDepth )
    {
      v19 = hkpMoppDefaultAssembler::calcRescaleBits(this, parentInfo, currentInfo);
      v6 = currentInfo;
      if ( v19 > 2 )
        currentNode->m_assemblerData.m_rescaleCommandType.m_storage = 1;
    }
    if ( currentNode->m_assemblerData.m_rescaleCommandType.m_storage == 1 )
    {
      cmd.m_doRescale.m_bool = 0;
      hkpMoppDefaultAssembler::recalcRescale(this, parentInfo, v6, &cmd);
    }
    v20 = currentNode[1].m_extents.m_extent[1];
    v21 = 0x7FFFFFFF;
    v32 = -1i64;
    *(hkpMoppExtent *)&cmd.m_doRescale.m_bool = v20;
    *(hkpMoppExtent *)cmd.m_moppOffset = currentNode[1].m_extents.m_extent[2];
    v31 = 0x7FFFFFFF;
    for ( i = 1i64; i >= 0; --i )
    {
      v23 = (hkpMoppTreeNode *)*((_QWORD *)&cmd.m_doRescale.m_bool + i);
      if ( v23 )
      {
        hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(
          &currentInfoa,
          currentInfo,
          *((hkpMoppTreeNode **)&cmd.m_doRescale.m_bool + i),
          &this->m_codeInfo);
        *((_DWORD *)&v32 + i) = hkpMoppDefaultAssembler::preCalcScale(this, v23, currentInfo, &currentInfoa);
        v24 = currentInfoa.m_maxExtentsSignificantBits;
        if ( v31 < currentInfoa.m_maxExtentsSignificantBits )
          v24 = v31;
        v21 = v24;
        v31 = v24;
      }
    }
    v25 = v33;
    v26 = v21 + 2;
    if ( v33 + 2 < v21 + 2 )
      v26 = v33 + 2;
    v27 = 0i64;
    while ( 1 )
    {
      v28 = *((_QWORD *)&cmd.m_doRescale.m_bool + v27);
      v29 = *((_DWORD *)&v32 + v27);
      if ( v28 )
        break;
LABEL_43:
      if ( ++v27 >= 2 )
        return (unsigned int)v26;
    }
    if ( currentNode->m_assemblerData.m_scaleIsValid.m_bool )
    {
      if ( *(_BYTE *)(v28 + 61) )
      {
LABEL_39:
        if ( !*(_BYTE *)(v28 + 62) )
        {
          if ( v26 < v29 )
            v29 = v26;
          v26 = v29;
        }
        goto LABEL_43;
      }
      v30 = v29 < v26;
    }
    else
    {
      v30 = v29 < v25;
    }
    if ( v30 )
      *(_BYTE *)(v28 + 62) = 1;
    goto LABEL_39;
  }
  m_absoluteFitToleranceOfTriangles = this->m_params.m_absoluteFitToleranceOfTriangles;
  v11 = 0;
  p_m_absoluteFitToleranceOfAxisAlignedTriangles = &this->m_params.m_absoluteFitToleranceOfAxisAlignedTriangles;
  v13 = 0i64;
  v14 = __ROL4__(1, m_maxExtentsSignificantBits);
  p_m_extents = &currentNode->m_extents;
  do
  {
    if ( !currentNode->m_assemblerData.m_scaleIsValid.m_bool )
      currentNode->m_assemblerData.m_cutCommandType[v13].m_storage = 1;
    v16 = p_m_absoluteFitToleranceOfAxisAlignedTriangles->m_quad.m128_f32[0];
    if ( (float)(p_m_extents->m_extent[0].m_max - p_m_extents->m_extent[0].m_min) < p_m_absoluteFitToleranceOfAxisAlignedTriangles->m_quad.m128_f32[0]
      && v16 < m_absoluteFitToleranceOfTriangles )
    {
      if ( (int)(float)(v16 * this->m_codeInfo.m_offset.m_quad.m128_f32[3]) << 7 < v14 )
      {
        if ( !currentNode->m_assemblerData.m_scaleIsValid.m_bool )
          currentNode->m_assemblerData.m_cutCommandType[v13].m_storage = 2;
      }
      else
      {
        m_absoluteFitToleranceOfTriangles = p_m_absoluteFitToleranceOfAxisAlignedTriangles->m_quad.m128_f32[0];
      }
    }
    ++v13;
    p_m_absoluteFitToleranceOfAxisAlignedTriangles = (hkVector4f *)((char *)p_m_absoluteFitToleranceOfAxisAlignedTriangles
                                                                  + 4);
    p_m_extents = (hkpMoppTreeNode::hkpMopp3DOPExtents *)((char *)p_m_extents + 8);
  }
  while ( v13 < 3 );
  for ( j = (int)(float)((float)(this->m_codeInfo.m_offset.m_quad.m128_f32[3] * 0.89999998)
                       * m_absoluteFitToleranceOfTriangles); j; j >>= 1 )
    ++v11;
  if ( v11 + 6 > m_maxExtentsSignificantBits )
    return (unsigned int)(v11 + 6);
  return (unsigned int)m_maxExtentsSignificantBits;
}

// File Line: 392
// RVA: 0xDFCAC0
void __fastcall hkpMoppDefaultAssembler::fixScale(hkpMoppDefaultAssembler *this, hkpMoppTreeInternalNode *currentNode)
{
  for ( ; currentNode; currentNode = currentNode->m_parent )
  {
    if ( currentNode->m_assemblerData.m_scaleIsValid.m_bool )
      break;
    currentNode->m_assemblerData.m_scaleIsValid.m_bool = 1;
  }
}

// File Line: 422
// RVA: 0xDFCAE0
void __fastcall hkpMoppDefaultAssembler::calcTermCut(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeNode *currentNode,
        hkpMoppAssemblerCutInfo *currentInfo)
{
  int *p_m_currentBitsResolution; // rsi
  signed __int64 v4; // rbx
  float *p_m_absoluteFitToleranceOfTriangles; // rdi
  float *v6; // rbp
  int *m_minCutPlanePosition; // r10
  signed __int64 v8; // r8
  hkpMoppTreeNode::hkpMopp3DOPExtents *p_m_extents; // r9
  __int64 v10; // r11
  float v11; // xmm4_4
  float v12; // xmm2_4
  int v13; // eax
  int v14; // ecx
  int v15; // edx

  p_m_currentBitsResolution = &currentInfo->m_currentBitsResolution;
  v4 = (char *)this - (char *)&currentNode->m_assemblerData;
  p_m_absoluteFitToleranceOfTriangles = &this->m_params.m_absoluteFitToleranceOfTriangles;
  v6 = &this->m_codeInfo.m_offset.m_quad.m128_f32[3];
  m_minCutPlanePosition = currentNode->m_assemblerData.m_minCutPlanePosition;
  v8 = (char *)currentInfo - (char *)currentNode;
  p_m_extents = &currentNode->m_extents;
  v10 = 3i64;
  do
  {
    v11 = *(float *)((char *)m_minCutPlanePosition + v4 + 116);
    v12 = fmaxf((float)(1 << *p_m_currentBitsResolution) / *v6, *p_m_absoluteFitToleranceOfTriangles);
    if ( (float)(p_m_extents->m_extent[0].m_max - p_m_extents->m_extent[0].m_min) < v11 )
      v12 = fminf(v12, v11);
    v13 = *(_DWORD *)((char *)p_m_extents->m_extent + v8 - 4);
    v14 = *(_DWORD *)((char *)&p_m_extents->m_extent[0].m_min + v8);
    ++m_minCutPlanePosition;
    p_m_extents = (hkpMoppTreeNode::hkpMopp3DOPExtents *)((char *)p_m_extents + 8);
    v15 = (int)(float)(*v6 * v12);
    *(m_minCutPlanePosition - 1) = v13 - v15;
    m_minCutPlanePosition[2] = v14 + v15 + 1;
    --v10;
  }
  while ( v10 );
}

// File Line: 479
// RVA: 0xDFCC50
void __fastcall hkpMoppDefaultAssembler::preCalcCutPositions(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeInternalNode *currentNode,
        hkpMoppAssemblerCutInfo *parentInfo,
        hkpMoppAssemblerCutInfo *currentInfo)
{
  hkpMoppAssemblerCutInfo *v4; // rbp
  int m_currentBitsResolution; // ecx
  int v8; // r8d
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
  hkpMoppExtent m_leftBranch; // rcx
  __int64 v21; // rdx
  int *m_maxCutPlanePosition; // rcx
  __int64 v23; // rax
  hkpMoppTreeNode *v24; // rsi
  __int64 v25; // r8
  int *v26; // r9
  int *m_minCutPlanePosition; // rdx
  char *v28; // r10
  int m_storage; // eax
  char v30; // cl
  int v31; // ecx
  int v32; // ecx
  int pleft[2]; // [rsp+30h] [rbp-A8h] BYREF
  _QWORD currentNodea[3]; // [rsp+38h] [rbp-A0h] BYREF
  int pright[4]; // [rsp+50h] [rbp-88h] BYREF
  hkpMoppAssemblerCutInfo currentInfoa; // [rsp+60h] [rbp-78h] BYREF
  HK_MOPP_SPLIT_DIRECTIONS SplitCode; // [rsp+E8h] [rbp+10h]

  v4 = currentInfo;
  if ( currentNode->m_assemblerData.m_isAssembled.m_bool )
    return;
  if ( currentNode->m_isTerminal.m_bool )
  {
    m_currentBitsResolution = currentInfo->m_currentBitsResolution;
    v8 = (currentInfo->m_extents[0][1] >> m_currentBitsResolution) + 1;
    currentInfo->m_lowCutPlanePosition[0] = currentInfo->m_extents[0][0] >> m_currentBitsResolution << m_currentBitsResolution;
    currentInfo->m_highCutPlanePosition[0] = v8 << m_currentBitsResolution;
    v9 = currentInfo->m_currentBitsResolution;
    v10 = currentInfo->m_extents[1][0] >> v9 << v9;
    currentInfo->m_highCutPlanePosition[1] = ((currentInfo->m_extents[1][1] >> v9) + 1) << v9;
    currentInfo->m_lowCutPlanePosition[1] = v10;
    v11 = currentInfo->m_currentBitsResolution;
    v12 = ((currentInfo->m_extents[2][1] >> v11) + 1) << v11;
    currentInfo->m_lowCutPlanePosition[2] = currentInfo->m_extents[2][0] >> v11 << v11;
    currentInfo->m_highCutPlanePosition[2] = v12;
    hkpMoppDefaultAssembler::calcTermCut(this, currentNode, currentInfo);
    return;
  }
  v13 = currentNode->m_assemblerData.m_rescaleCommandType.m_storage == 1;
  LOBYTE(currentNodea[0]) = 0;
  if ( v13 )
    hkpMoppDefaultAssembler::recalcRescale(
      this,
      parentInfo,
      currentInfo,
      (hkpMoppAssemblerRescaleCommand *)currentNodea);
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
  SplitCode = hkpMoppDefaultAssembler::getSplitCode(this, &currentNode->m_plane->m_direction);
  hkpMoppDefaultAssembler::findPlanes(this, currentNode, v4, pleft, pright);
  m_leftBranch = (hkpMoppExtent)currentNode->m_leftBranch;
  currentNodea[0] = currentNode->m_rightBranch;
  currentNodea[1] = m_leftBranch;
  v21 = 3i64;
  m_maxCutPlanePosition = currentNode->m_assemblerData.m_maxCutPlanePosition;
  v23 = 0i64;
  do
  {
    *(m_maxCutPlanePosition - 3) = 0;
    *m_maxCutPlanePosition++ = 0x7FFFFFFF;
    --v21;
  }
  while ( v21 );
  *(_QWORD *)pleft = 0i64;
  do
  {
    v24 = (hkpMoppTreeNode *)currentNodea[v23];
    if ( !v24 )
      goto LABEL_35;
    hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(
      &currentInfoa,
      v4,
      (hkpMoppTreeNode *)currentNodea[v23],
      &this->m_codeInfo);
    hkpMoppDefaultAssembler::preCalcCutPositions(this, v24, v4, &currentInfoa);
    if ( v24 == (hkpMoppTreeNode *)currentNodea[0] )
    {
      if ( (int)SplitCode <= HK_MOPP_SD_Z )
        v24->m_assemblerData.m_minCutPlanePosition[SplitCode] = 0;
    }
    else if ( (int)SplitCode <= HK_MOPP_SD_Z )
    {
      v24->m_assemblerData.m_maxCutPlanePosition[SplitCode] = 0x7FFFFFFF;
    }
    v25 = 0i64;
    v26 = &v4->m_extents[0][1];
    m_minCutPlanePosition = v24->m_assemblerData.m_minCutPlanePosition;
    v28 = (char *)((char *)currentNode - (char *)&v24->m_assemblerData);
    do
    {
      m_storage = v24->m_assemblerData.m_cutCommandType[v25].m_storage;
      if ( m_storage == 1 )
      {
        if ( *m_minCutPlanePosition <= *(int *)((char *)m_minCutPlanePosition + (char *)v4 - (char *)v24)
          && m_minCutPlanePosition[3] >= *(int *)((char *)m_minCutPlanePosition
                                                + (char *)v4
                                                - (char *)&v24->m_assemblerData
                                                + 72) )
        {
          v30 = currentNode->m_assemblerData.m_cutCommandType[v25].m_storage;
          if ( v30 < 1 )
            v30 = 1;
          currentNode->m_assemblerData.m_cutCommandType[v25].m_storage = v30;
          goto LABEL_26;
        }
      }
      else if ( m_storage == 2 && *m_minCutPlanePosition <= *(v26 - 1) && m_minCutPlanePosition[3] >= *v26 )
      {
        currentNode->m_assemblerData.m_cutCommandType[v25].m_storage = 2;
LABEL_26:
        v24->m_assemblerData.m_cutCommandType[v25].m_storage = 0;
      }
      if ( !v24->m_assemblerData.m_cutCommandType[v25].m_storage )
      {
        v31 = *m_minCutPlanePosition;
        if ( *(int *)((char *)m_minCutPlanePosition + (char *)currentNode - (char *)v24) > *m_minCutPlanePosition )
          v31 = *(int *)((char *)m_minCutPlanePosition + (char *)currentNode - (char *)v24);
        *(int *)((char *)m_minCutPlanePosition + (char *)currentNode - (char *)v24) = v31;
        v32 = m_minCutPlanePosition[3];
        if ( *(int *)((char *)m_minCutPlanePosition + (_QWORD)v28 + 72) < v32 )
          v32 = *(int *)((char *)m_minCutPlanePosition + (_QWORD)v28 + 72);
        *(int *)((char *)m_minCutPlanePosition + (_QWORD)v28 + 72) = v32;
      }
      ++v25;
      ++m_minCutPlanePosition;
      v26 += 2;
    }
    while ( v25 < 3 );
    v4 = currentInfo;
    v23 = *(_QWORD *)pleft;
LABEL_35:
    *(_QWORD *)pleft = ++v23;
  }
  while ( v23 < 2 );
}

// File Line: 615
// RVA: 0xDFB700
void __fastcall hkpMoppDefaultAssembler::initTopDown(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeNode *currentNode,
        hkpMoppAssemblerNodeInfo *parentInfo,
        hkpMoppAssemblerNodeInfo *currentInfo,
        hkpMoppAssemblerRescaleCommand *rescaleCommandInfo)
{
  if ( currentNode->m_assemblerData.m_rescaleCommandType.m_storage == 1 )
    hkpMoppDefaultAssembler::recalcRescale(this, parentInfo, currentInfo, rescaleCommandInfo);
  hkpMoppDefaultAssembler::calcReoffset(this, currentNode, parentInfo, currentInfo);
}

// File Line: 643
// RVA: 0xDFCF70
__int64 __fastcall hkpMoppDefaultAssembler::assemblesubNode(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeInternalNode *currentNode,
        hkpMoppAssemblerNodeInfo *parentInfo,
        hkpMoppAssemblerNodeInfo *currentInfo)
{
  int m_minDepthToBuild; // eax
  unsigned int v9; // ebp
  __int128 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  int v14; // ecx
  hkpMoppTreeNode *m_rightBranch; // rax
  hkpMoppTreeNode *m_leftBranch; // rax
  hkpMoppAssemblerNodeInfo *v17; // r8
  int v18; // [rsp+30h] [rbp-88h]
  int v19; // [rsp+30h] [rbp-88h]
  int v20; // [rsp+34h] [rbp-84h]
  hkpMoppAssemblerRescaleCommand rescaleCommandInfo; // [rsp+38h] [rbp-80h] BYREF
  hkpMoppAssemblerNodeInfo currentInfoa; // [rsp+50h] [rbp-68h] BYREF
  hkpMoppTreeNode *result; // [rsp+C8h] [rbp+10h] BYREF
  hkpMoppAssemblerNodeInfo *parentInfoa; // [rsp+D0h] [rbp+18h]

  parentInfoa = parentInfo;
  if ( currentNode->m_assemblerData.m_isAssembled.m_bool )
    return 3i64;
  if ( currentInfo->m_level <= this->m_minDepthToBuild
    && !(currentInfo->m_level % this->m_params.m_groupLevels)
    && !currentInfo->m_ignoreBandControlCode.m_bool )
  {
    currentInfo->m_ignoreBandControlCode.m_bool = 1;
    m_minDepthToBuild = this->m_minDepthToBuild;
    v9 = -1;
    v18 = m_minDepthToBuild;
    if ( !currentNode->m_assemblerData.m_isAssembled.m_bool )
    {
      do
      {
        v10 = *(_OWORD *)&currentInfo->m_level;
        v11 = *(_OWORD *)&currentInfo->m_extents[0][1];
        LODWORD(result) = this->m_code->m_pos;
        *(_OWORD *)&currentInfoa.m_level = v10;
        v12 = *(_OWORD *)&currentInfo->m_extents[2][1];
        *(_OWORD *)&currentInfoa.m_extents[0][1] = v11;
        v13 = *(_OWORD *)&currentInfo->m_accumOffset[2];
        *(_OWORD *)&currentInfoa.m_extents[2][1] = v12;
        *(_QWORD *)currentInfoa.m_propertiesOffset = *(_QWORD *)currentInfo->m_propertiesOffset;
        *(_OWORD *)&currentInfoa.m_accumOffset[2] = v13;
        v9 = hkpMoppDefaultAssembler::assemblesubNode(this, currentNode, parentInfo, &currentInfoa);
        if ( this->m_numNodesAssembled > this->m_minAssembledElems )
          break;
        if ( (_DWORD)result == this->m_code->m_pos )
        {
          v14 = this->m_minDepthToBuild;
          if ( v14 < 0 )
            break;
          this->m_minDepthToBuild = v14 - this->m_params.m_groupLevels;
        }
        parentInfo = parentInfoa;
      }
      while ( !currentNode->m_assemblerData.m_isAssembled.m_bool );
      m_minDepthToBuild = v18;
    }
    this->m_minDepthToBuild = m_minDepthToBuild;
    currentInfo->m_ignoreBandControlCode.m_bool = 0;
    return v9;
  }
  if ( !currentNode->m_isTerminal.m_bool )
  {
    v9 = -1;
    rescaleCommandInfo.m_doRescale.m_bool = 0;
    rescaleCommandInfo.m_scaleCommand = -1;
    hkpMoppDefaultAssembler::initTopDown(this, currentNode, parentInfo, currentInfo, &rescaleCommandInfo);
    m_rightBranch = currentNode->m_rightBranch;
    v19 = -1;
    result = m_rightBranch;
    if ( m_rightBranch )
    {
      hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(&currentInfoa, currentInfo, m_rightBranch, &this->m_codeInfo);
      v19 = hkpMoppDefaultAssembler::assemblesubNode(this, result, currentInfo, &currentInfoa);
      if ( v19 >= 0 )
        hkpMoppDefaultAssembler::releaseNode(this, result);
    }
    m_leftBranch = currentNode->m_leftBranch;
    result = m_leftBranch;
    if ( m_leftBranch )
    {
      hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(&currentInfoa, currentInfo, m_leftBranch, &this->m_codeInfo);
      v20 = hkpMoppDefaultAssembler::assemblesubNode(this, result, currentInfo, &currentInfoa);
      if ( v20 >= 0 )
      {
        hkpMoppDefaultAssembler::releaseNode(this, result);
        if ( v19 >= 0 )
        {
          if ( hkpMoppDefaultAssembler::shouldAssemble(this, (hkBool *)&result, currentNode, currentInfo)->m_bool )
          {
            v17 = parentInfoa;
            ++this->m_numNodesAssembled;
            return v19
                 + v20
                 + (unsigned int)hkpMoppDefaultAssembler::assembleNonTerminalCommand(
                                   this,
                                   currentNode,
                                   v17,
                                   currentInfo,
                                   &rescaleCommandInfo);
          }
        }
      }
    }
    return v9;
  }
  hkpMoppDefaultAssembler::fixScale(this, currentNode);
  if ( hkpMoppDefaultAssembler::shouldAssemble(this, (hkBool *)&result, currentNode, currentInfo)->m_bool )
    return hkpMoppDefaultAssembler::assembleCutAndTerminalCommand(
             this,
             (hkpMoppTreeTerminal *)currentNode,
             parentInfoa,
             currentInfo);
  else
    return 0xFFFFFFFFi64;
}

// File Line: 786
// RVA: 0xDFB9D0
__int64 __fastcall hkpMoppDefaultAssembler::calcChunkPoints(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeTerminal *currentNode,
        hkpMoppAssemblerNodeInfo *parentInfo,
        hkpMoppAssemblerNodeInfo *currentInfo,
        hkArray<unsigned int,hkContainerHeapAllocator> *terminalsOut)
{
  int m_pos; // ebx
  unsigned int v8; // r8d
  hkArray<unsigned int,hkContainerHeapAllocator> *v9; // rbx
  hkpPrimitiveCompressor *m_compressor; // rcx
  hkpMoppAssemblerNodeInfo *v12; // rcx
  hkpMoppTreeNode *v13; // rdi
  int v14; // ebx
  hkpPrimitiveCompressor *v15; // rcx
  hkpMoppTreeNode *v16; // rdi
  hkpMoppTreeNode *v17; // rdx
  hkpMoppDefaultAssembler *v18; // rdi
  int v19; // ebx
  hkpPrimitiveCompressor *v20; // rcx
  int v21; // ebx
  int v22; // eax
  hkpPrimitiveCompressor *v23; // rcx
  int v24; // ebx
  hkpMoppCompilerChunkInfo *m_chunkInfo; // rax
  hkpMoppCompilerChunkInfo *v26; // rax
  int m_size; // ecx
  hkArray<hkpMoppCompilerChunkInfo::Chunk,hkContainerHeapAllocator> *p_m_chunks; // rbx
  __int64 v29; // r8
  hkpMoppExtent v30; // r10
  int v31; // edx
  int v32; // r11d
  int v33; // ebx
  hkArray<unsigned int,hkContainerHeapAllocator> *v34; // rdi
  int v35; // [rsp+30h] [rbp-91h]
  int v36; // [rsp+34h] [rbp-8Dh]
  int v37; // [rsp+38h] [rbp-89h]
  int v38; // [rsp+3Ch] [rbp-85h]
  int v39; // [rsp+40h] [rbp-81h]
  hkArray<unsigned int,hkContainerHeapAllocator> v40; // [rsp+48h] [rbp-79h] BYREF
  hkArray<unsigned int,hkContainerHeapAllocator> v41; // [rsp+58h] [rbp-69h] BYREF
  hkArrayBase<unsigned int> v42; // [rsp+68h] [rbp-59h] BYREF
  hkpMoppTreeInternalNode *m_primitive; // [rsp+78h] [rbp-49h]
  hkpMoppAssemblerRescaleCommand rescaleCommandInfo; // [rsp+80h] [rbp-41h] BYREF
  hkpMoppAssemblerNodeInfo currentInfoa; // [rsp+A0h] [rbp-21h] BYREF
  unsigned int v47; // [rsp+120h] [rbp+5Fh]
  char v48; // [rsp+120h] [rbp+5Fh]
  hkpMoppCode::CodeInfo *codeInfo; // [rsp+128h] [rbp+67h] BYREF
  hkpMoppAssemblerNodeInfo *v50; // [rsp+130h] [rbp+6Fh]
  hkpMoppAssemblerNodeInfo *parentInfoa; // [rsp+138h] [rbp+77h]

  parentInfoa = currentInfo;
  v50 = parentInfo;
  if ( this->m_chunkInfo->m_compressor )
    currentInfo->m_terminalOffset = parentInfo->m_terminalOffset;
  if ( currentNode->m_isTerminal.m_bool )
  {
    if ( this->m_chunkInfo->m_compressor )
      currentInfo->m_terminalOffset = currentNode->m_primitive->m_primitiveID;
    m_pos = this->m_code->m_pos;
    hkpMoppDefaultAssembler::assembleCutAndTerminalCommand(this, currentNode, parentInfo, currentInfo);
    v8 = this->m_code->m_pos - m_pos;
    v9 = terminalsOut;
    m_primitive = (hkpMoppTreeInternalNode *)currentNode->m_primitive;
    v47 = v8;
    if ( terminalsOut->m_size == (terminalsOut->m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&terminalsOut->m_data, 4);
      v8 = v47;
    }
    v9->m_data[v9->m_size++] = (unsigned int)m_primitive->m_parent;
    LODWORD(codeInfo) = currentNode->m_primitive->m_primitiveID;
    m_compressor = this->m_chunkInfo->m_compressor;
    if ( m_compressor )
      return m_compressor->vfptr->calcPrimitivesSize(m_compressor, (const unsigned int *)&codeInfo, 1) + v47;
    return v8;
  }
  rescaleCommandInfo.m_doRescale.m_bool = 0;
  rescaleCommandInfo.m_scaleCommand = -1;
  hkpMoppDefaultAssembler::initTopDown(this, currentNode, parentInfo, currentInfo, &rescaleCommandInfo);
  v12 = parentInfoa;
  parentInfoa->m_terminalOffset = v50->m_terminalOffset;
  v13 = (hkpMoppTreeNode *)currentNode[1].m_extents.m_extent[1];
  v41.m_data = 0i64;
  v41.m_size = 0;
  v41.m_capacityAndFlags = 0x80000000;
  codeInfo = &this->m_codeInfo;
  hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(&currentInfoa, v12, v13, &this->m_codeInfo);
  v14 = this->m_code->m_pos;
  hkpMoppDefaultAssembler::calcChunkPoints(this, v13, parentInfoa, &currentInfoa, &v41);
  v37 = this->m_code->m_pos - v14;
  v36 = v37;
  v15 = this->m_chunkInfo->m_compressor;
  if ( v15 && v41.m_size )
    v36 = v37
        + ((__int64 (__fastcall *)(hkpPrimitiveCompressor *, unsigned int *))v15->vfptr->calcPrimitivesSize)(
            v15,
            v41.m_data);
  v16 = (hkpMoppTreeNode *)currentNode[1].m_extents.m_extent[0];
  v40.m_data = 0i64;
  v40.m_size = 0;
  v40.m_capacityAndFlags = 0x80000000;
  hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(&currentInfoa, parentInfoa, v16, codeInfo);
  v17 = v16;
  v18 = this;
  v19 = this->m_code->m_pos;
  hkpMoppDefaultAssembler::calcChunkPoints(this, v17, parentInfoa, &currentInfoa, &v40);
  v39 = this->m_code->m_pos - v19;
  v38 = v39;
  v20 = this->m_chunkInfo->m_compressor;
  if ( v20 && v40.m_size )
    v38 = v39
        + ((__int64 (__fastcall *)(hkpPrimitiveCompressor *, unsigned int *))v20->vfptr->calcPrimitivesSize)(
            v20,
            v40.m_data);
  v21 = this->m_code->m_pos;
  hkpMoppDefaultAssembler::assembleNonTerminalCommand(
    this,
    (hkpMoppTreeInternalNode *)currentNode,
    v50,
    parentInfoa,
    &rescaleCommandInfo);
  v22 = this->m_code->m_pos - v21;
  v42.m_capacityAndFlags = 0x80000000;
  v35 = v22;
  v42.m_data = 0i64;
  v42.m_size = 0;
  hkArrayBase<unsigned int>::_insertAt(&v42, &hkContainerHeapAllocator::s_alloc, 0, v41.m_data, v41.m_size);
  hkArrayBase<unsigned int>::_insertAt(&v42, &hkContainerHeapAllocator::s_alloc, v42.m_size, v40.m_data, v40.m_size);
  v23 = this->m_chunkInfo->m_compressor;
  v24 = v37 + v39 + v35;
  if ( v23 && v42.m_size )
    v24 += ((__int64 (__fastcall *)(hkpPrimitiveCompressor *, unsigned int *))v23->vfptr->calcPrimitivesSize)(
             v23,
             v42.m_data);
  m_chunkInfo = this->m_chunkInfo;
  LOBYTE(codeInfo) = 0;
  v48 = 0;
  if ( v24 >= m_chunkInfo->m_maxChunkSize - m_chunkInfo->m_safetySize )
  {
    do
    {
      v26 = v18->m_chunkInfo;
      m_size = v26->m_chunks.m_size;
      p_m_chunks = &v26->m_chunks;
      LODWORD(v26) = v26->m_chunks.m_capacityAndFlags;
      LODWORD(m_primitive) = m_size;
      if ( p_m_chunks->m_size == ((unsigned int)v26 & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_chunks->m_data, 16);
      v29 = (__int64)&p_m_chunks->m_data[p_m_chunks->m_size++];
      if ( v38 <= v36 )
      {
        v30 = currentNode[1].m_extents.m_extent[1];
        v31 = v37;
        v32 = v36;
        v36 = 5;
        v48 = 1;
        if ( !(_BYTE)codeInfo )
        {
          v33 = v38 + 5;
          goto LABEL_30;
        }
        v24 = v35 + 10;
      }
      else
      {
        v30 = currentNode[1].m_extents.m_extent[0];
        v31 = v39;
        v32 = v38;
        v38 = 5;
        LOBYTE(codeInfo) = 1;
        if ( !v48 )
        {
          v33 = v36 + 5;
LABEL_30:
          v24 = v35 + v33;
          goto LABEL_31;
        }
        v24 = v35 + 10;
      }
LABEL_31:
      *(_DWORD *)(v29 + 8) = v32 + v18->m_chunkInfo->m_safetySize + 5;
      *(_DWORD *)(*(_QWORD *)&v30 + 68i64) = (_DWORD)m_primitive;
      v18->m_code->m_pos += 5 - v31;
      if ( v48 )
        *(_DWORD *)(*(_QWORD *)&currentNode[1].m_extents.m_extent[1] + 96i64) += 5 - v31;
      *(_DWORD *)(*(_QWORD *)currentNode[1].m_extents.m_extent + 96i64) += 5 - v31;
      currentNode->m_assemblerData.m_assembledAddress += 5 - v31;
    }
    while ( v24 >= v18->m_chunkInfo->m_maxChunkSize - v18->m_chunkInfo->m_safetySize );
  }
  v34 = terminalsOut;
  terminalsOut->m_size = 0;
  if ( !v48 )
    hkArrayBase<unsigned int>::_insertAt(v34, &hkContainerHeapAllocator::s_alloc, 0, v41.m_data, v41.m_size);
  if ( !(_BYTE)codeInfo )
    hkArrayBase<unsigned int>::_insertAt(v34, &hkContainerHeapAllocator::s_alloc, v34->m_size, v40.m_data, v40.m_size);
  v42.m_size = 0;
  if ( v42.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v42.m_data,
      4 * v42.m_capacityAndFlags);
  v42.m_data = 0i64;
  v42.m_capacityAndFlags = 0x80000000;
  v40.m_size = 0;
  if ( v40.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v40.m_data,
      4 * v40.m_capacityAndFlags);
  v40.m_data = 0i64;
  v40.m_capacityAndFlags = 0x80000000;
  v41.m_size = 0;
  if ( v41.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v41.m_data,
      4 * v41.m_capacityAndFlags);
  return (unsigned int)v24;
}

// File Line: 968
// RVA: 0xDFBF00
__int64 __fastcall hkpMoppDefaultAssembler::calcTerminalIdsForChunks(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeNode *currentNode,
        int chunkId,
        unsigned int currentId)
{
  unsigned int v5; // edx
  unsigned int v6; // edi
  int m_chunkId; // esi
  hkpMoppCompilerChunkInfo *m_chunkInfo; // rsi
  __int64 m_size; // rdx
  hkpMoppCodeReindexedTerminal *v11; // r8
  int v12; // eax
  int v14; // [rsp+50h] [rbp+18h]

  v14 = chunkId;
  v5 = currentId;
  v6 = currentId;
  currentNode->m_assemblerData.m_isAssembled.m_bool = 0;
  m_chunkId = chunkId;
  if ( currentNode->m_assemblerData.m_chunkId >= 0 )
  {
    v6 = 0;
    m_chunkId = currentNode->m_assemblerData.m_chunkId;
    v14 = m_chunkId;
  }
  if ( this->m_chunkInfo->m_compressor )
    currentNode->m_minPrimitiveId = v6;
  if ( currentNode->m_isTerminal.m_bool )
  {
    if ( !this->m_chunkInfo->m_compressor )
      goto LABEL_12;
    LODWORD(currentNode[1].m_parent->m_extents.m_extent[0].m_min) = currentNode[1].m_parent->m_parent;
    m_chunkInfo = this->m_chunkInfo;
    if ( m_chunkInfo->m_reindexInfo.m_size == (m_chunkInfo->m_reindexInfo.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&m_chunkInfo->m_reindexInfo.m_data,
        8);
    m_size = m_chunkInfo->m_reindexInfo.m_size;
    v11 = &m_chunkInfo->m_reindexInfo.m_data[m_size];
    m_chunkInfo->m_reindexInfo.m_size = m_size + 1;
    v11->m_reindexedShapeKey = v6 | (v14 << 8);
    v11->m_origShapeKey = (unsigned int)currentNode[1].m_parent->m_parent;
    LODWORD(currentNode[1].m_parent->m_parent) = v6++;
  }
  else
  {
    v12 = hkpMoppDefaultAssembler::calcTerminalIdsForChunks(
            this,
            *(hkpMoppTreeNode **)&currentNode[1].m_extents.m_extent[2],
            m_chunkId,
            v6);
    v6 = hkpMoppDefaultAssembler::calcTerminalIdsForChunks(
           this,
           *(hkpMoppTreeNode **)&currentNode[1].m_extents.m_extent[1],
           m_chunkId,
           v12);
  }
  v5 = currentId;
LABEL_12:
  if ( this->m_chunkInfo->m_compressor )
  {
    currentNode->m_minPrimitiveId = 0;
    currentNode->m_maxPrimitiveId = v6;
  }
  if ( currentNode->m_assemblerData.m_chunkId < 0 )
    return v6;
  return v5;
}

// File Line: 1031
// RVA: 0xDFDC20
void __fastcall copyJumpCommandInfo(
        hkArray<hkpMoppCodeGenerator::JumpCommandInfo,hkContainerHeapAllocator> *newCommands,
        hkArray<hkpMoppCodeGenerator::JumpCommandInfo,hkContainerHeapAllocator> *originalCommands,
        int offset)
{
  int v3; // esi
  __int64 v7; // rbp
  __int64 m_size; // rdx
  hkpMoppCodeGenerator::JumpCommandInfo *v9; // r8

  v3 = 0;
  if ( originalCommands->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      if ( newCommands->m_size == (newCommands->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&newCommands->m_data, 8);
      m_size = newCommands->m_size;
      ++v3;
      v9 = &newCommands->m_data[m_size];
      ++v7;
      newCommands->m_size = m_size + 1;
      v9->m_chunkId = originalCommands->m_data[v7 - 1].m_chunkId;
      v9->m_position = offset + originalCommands->m_data[v7 - 1].m_position;
    }
    while ( v3 < originalCommands->m_size );
  }
}

// File Line: 1041
// RVA: 0xDFDCE0
__int64 __fastcall copyCodeAndEmbedTerminals(
        hkpMoppCompilerChunkInfo *chunkInfo,
        hkpMoppCodeGenerator *codeWithTerminals,
        hkpMoppCodeGenerator *codeWithoutTerminals,
        hkArray<unsigned int,hkContainerHeapAllocator> *terminals)
{
  int v5; // ebp
  signed int v9; // r13d
  __int64 v10; // rdi
  hkLifoAllocator *Value; // rax
  char *m_cur; // rdi
  int v13; // esi
  char *v14; // rcx
  hkLifoAllocator *v15; // rax
  int v16; // r8d
  int m_pos; // esi
  int v18; // ecx
  __int64 v19; // rdi

  v5 = -codeWithoutTerminals->m_pos & 3;
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
        codeWithTerminals->m_code[codeWithTerminals->m_size - (__int64)codeWithTerminals->m_pos++ - 1] = -51;
        if ( codeWithTerminals->m_pos >= codeWithTerminals->m_size )
          hkpMoppCodeGenerator::resize(codeWithTerminals);
        --v10;
      }
      while ( v10 );
    }
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v13 = (v9 + 127) & 0xFFFFFF80;
    v14 = &m_cur[v13];
    if ( v13 > Value->m_slabSize || v14 > Value->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v13);
    else
      Value->m_cur = v14;
    chunkInfo->m_compressor->vfptr->storePrimitives(
      chunkInfo->m_compressor,
      terminals->m_data,
      terminals->m_size,
      m_cur);
    hkString::memCpy(&codeWithTerminals->m_code[codeWithTerminals->m_size - codeWithTerminals->m_pos], m_cur, v9);
    v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (v13 + 15) & 0xFFFFFFF0;
    if ( v13 > v15->m_slabSize || &m_cur[v16] != v15->m_cur || v15->m_firstNonLifoEnd == m_cur )
      hkLifoAllocator::slowBlockFree(v15, m_cur, v16);
    else
      v15->m_cur = m_cur;
  }
  m_pos = codeWithTerminals->m_pos;
  v18 = v5 + codeWithoutTerminals->m_pos;
  if ( v18 > 0 )
  {
    v19 = (unsigned int)v18;
    do
    {
      codeWithTerminals->m_code[codeWithTerminals->m_size - (__int64)codeWithTerminals->m_pos++ - 1] = -51;
      if ( codeWithTerminals->m_pos >= codeWithTerminals->m_size )
        hkpMoppCodeGenerator::resize(codeWithTerminals);
      --v19;
    }
    while ( v19 );
  }
  hkString::memCpy(
    &codeWithTerminals->m_code[codeWithTerminals->m_size - codeWithTerminals->m_pos],
    &codeWithoutTerminals->m_code[codeWithoutTerminals->m_size - codeWithoutTerminals->m_pos],
    codeWithoutTerminals->m_pos);
  hkpMoppCodeGenerator::validateJumpCommands(codeWithoutTerminals);
  copyJumpCommandInfo(
    &codeWithTerminals->m_jumpCommands,
    &codeWithoutTerminals->m_jumpCommands,
    codeWithTerminals->m_pos - codeWithoutTerminals->m_pos);
  hkpMoppCodeGenerator::validateJumpCommands(codeWithTerminals);
  return (unsigned int)(codeWithTerminals->m_pos - m_pos);
}

// File Line: 1096
// RVA: 0xDFC020
void __fastcall hkpMoppDefaultAssembler::assembleSubNodeIntoChunks(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeTerminal *currentNode,
        hkpMoppAssemblerNodeInfo *parentInfo,
        hkpMoppAssemblerNodeInfo *currentInfo,
        int chunkId,
        hkArray<unsigned int,hkContainerHeapAllocator> *terminalsOut)
{
  __int64 m_chunkId; // rax
  hkpMoppCompilerChunkInfo::Chunk *v10; // rbp
  int v11; // ecx
  _QWORD **Value; // rax
  hkpMoppCodeGenerator *v13; // rax
  hkpMoppCodeGenerator *v14; // rax
  hkpMoppTreeInternalNode *m_primitive; // rdi
  hkpMoppTreeNode *v16; // rbx
  hkpMoppTreeNode *v17; // rbx
  int v18; // [rsp+30h] [rbp-98h]
  hkpMoppAssemblerRescaleCommand terminals; // [rsp+38h] [rbp-90h] BYREF
  hkpMoppAssemblerNodeInfo v20; // [rsp+50h] [rbp-78h] BYREF
  hkpMoppCodeGenerator *currentNodeb; // [rsp+D8h] [rbp+10h]

  m_chunkId = currentNode->m_assemblerData.m_chunkId;
  v18 = m_chunkId;
  if ( (int)m_chunkId <= 0 || currentInfo->m_ignoreBandControlCode.m_bool )
  {
    if ( currentNode->m_isTerminal.m_bool )
    {
      hkpMoppDefaultAssembler::assembleCutAndTerminalCommand(this, currentNode, parentInfo, currentInfo);
      m_primitive = (hkpMoppTreeInternalNode *)currentNode->m_primitive;
      if ( terminalsOut->m_size == (terminalsOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&terminalsOut->m_data, 4);
      terminalsOut->m_data[terminalsOut->m_size++] = LODWORD(m_primitive->m_extents.m_extent[0].m_min);
    }
    else
    {
      terminals.m_doRescale.m_bool = 0;
      terminals.m_scaleCommand = -1;
      hkpMoppDefaultAssembler::initTopDown(this, currentNode, parentInfo, currentInfo, &terminals);
      v16 = (hkpMoppTreeNode *)currentNode[1].m_extents.m_extent[1];
      hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(&v20, currentInfo, v16, &this->m_codeInfo);
      hkpMoppDefaultAssembler::assembleSubNodeIntoChunks(this, v16, currentInfo, &v20, chunkId, terminalsOut);
      v17 = (hkpMoppTreeNode *)currentNode[1].m_extents.m_extent[0];
      hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(&v20, currentInfo, v17, &this->m_codeInfo);
      hkpMoppDefaultAssembler::assembleSubNodeIntoChunks(this, v17, currentInfo, &v20, chunkId, terminalsOut);
      hkpMoppDefaultAssembler::assembleNonTerminalCommand(
        this,
        (hkpMoppTreeInternalNode *)currentNode,
        parentInfo,
        currentInfo,
        &terminals);
    }
  }
  else
  {
    currentNodeb = this->m_code;
    v10 = &this->m_chunkInfo->m_chunks.m_data[m_chunkId];
    hkpMoppCodeGenerator::hkpMoppCodeGenerator((hkpMoppCodeGenerator *)&v20, v10->m_codeSize);
    this->m_code = (hkpMoppCodeGenerator *)&v20;
    *(_QWORD *)&terminals.m_doRescale.m_bool = 0i64;
    terminals.m_moppOffset[0] = 0;
    currentInfo->m_ignoreBandControlCode.m_bool = 1;
    terminals.m_moppOffset[1] = 0x80000000;
    hkpMoppDefaultAssembler::assembleSubNodeIntoChunks(
      this,
      currentNode,
      parentInfo,
      currentInfo,
      v18,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)&terminals);
    if ( this->m_chunkInfo->m_compressor )
    {
      v11 = this->m_code->m_pos + 5;
      hkpMoppDefaultAssembler::addDataOffset(this, v11 + (-v11 & 3), terminals.m_moppOffset[0]);
    }
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (hkpMoppCodeGenerator *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
    if ( v13 )
      hkpMoppCodeGenerator::hkpMoppCodeGenerator(v13, v10->m_codeSize);
    else
      v14 = 0i64;
    v10->m_code = v14;
    copyCodeAndEmbedTerminals(
      this->m_chunkInfo,
      v14,
      this->m_code,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)&terminals);
    this->m_code->m_jumpCommands.m_size = 0;
    terminals.m_moppOffset[0] = 0;
    if ( terminals.m_moppOffset[1] >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)&terminals.m_doRescale.m_bool,
        4 * terminals.m_moppOffset[1]);
    *(_QWORD *)&terminals.m_doRescale.m_bool = 0i64;
    terminals.m_moppOffset[1] = 0x80000000;
    hkpMoppCodeGenerator::~hkpMoppCodeGenerator((hkpMoppCodeGenerator *)&v20);
    this->m_code = currentNodeb;
    hkpMoppDefaultAssembler::assembleJumpChunkCommand(this, currentNode);
  }
}

// File Line: 1184
// RVA: 0xDFCBE0
void __fastcall hkpMoppDefaultAssembler::calcReoffset(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeNode *currentNode,
        hkpMoppAssemblerNodeInfo *parentInfo,
        hkpMoppAssemblerNodeInfo *currentInfo)
{
  unsigned int m_terminalSpread; // eax
  unsigned int m_minPrimitiveId; // r10d
  unsigned int v6; // ecx

  currentInfo->m_terminalOffset = parentInfo->m_terminalOffset;
  m_terminalSpread = currentInfo->m_terminalSpread;
  m_minPrimitiveId = currentNode->m_minPrimitiveId;
  v6 = m_minPrimitiveId + m_terminalSpread - parentInfo->m_terminalOffset;
  if ( v6 >= 0x20
    && (m_terminalSpread > 2 || v6 >= 0x100)
    && (m_terminalSpread < 0x20 && parentInfo->m_terminalSpread >= 0x20
     || m_terminalSpread < 0x100 && parentInfo->m_terminalSpread >= 0x100
     || m_terminalSpread < 0x10000 && parentInfo->m_terminalSpread >= 0x10000) )
  {
    currentInfo->m_terminalOffset = m_minPrimitiveId;
  }
}

// File Line: 1215
// RVA: 0xDFD9A0
void __fastcall hkpMoppDefaultAssembler::addProperty(hkpMoppDefaultAssembler *this, int property, int value)
{
  if ( value < 0 )
    goto LABEL_6;
  if ( value < 256 )
  {
    hkpMoppCodeGenerator::addCommand8(this->m_code, property + 96, value);
    return;
  }
  if ( value >= 0x10000 )
LABEL_6:
    hkpMoppCodeGenerator::addCommand32(this->m_code, property + 104, value);
  else
    hkpMoppCodeGenerator::addCommand16(this->m_code, property + 100, value);
}

// File Line: 1236
// RVA: 0xDFD7B0
__int64 __fastcall hkpMoppDefaultAssembler::addJumpChunk(hkpMoppDefaultAssembler *this, unsigned int chunkId)
{
  hkpMoppCodeGenerator::addCommand32(this->m_code, 112, chunkId);
  return 5i64;
}

// File Line: 1242
// RVA: 0xDFD7E0
__int64 __fastcall hkpMoppDefaultAssembler::addDataOffset(
        hkpMoppDefaultAssembler *this,
        int offset,
        __int16 numTerminals)
{
  hkpMoppCodeGenerator *m_code; // rcx
  char v5; // bh
  hkpMoppCodeGenerator *v7; // rcx

  m_code = this->m_code;
  v5 = HIBYTE(numTerminals);
  m_code->m_code[m_code->m_size - m_code->m_pos++ - 1] = numTerminals;
  if ( m_code->m_pos >= m_code->m_size )
    hkpMoppCodeGenerator::resize(m_code);
  v7 = this->m_code;
  v7->m_code[v7->m_size - v7->m_pos++ - 1] = v5;
  if ( v7->m_pos >= v7->m_size )
    hkpMoppCodeGenerator::resize(v7);
  hkpMoppCodeGenerator::addCommand16(this->m_code, 13, offset);
  return 5i64;
}

// File Line: 1250
// RVA: 0xDFD220
void __fastcall hkpMoppDefaultAssembler::addRescale(hkpMoppDefaultAssembler *this, hkpMoppAssemblerRescaleCommand *cmd)
{
  hkpMoppCodeGenerator *m_code; // rcx
  hkpMoppCodeGenerator *v5; // rcx
  hkpMoppCodeGenerator *v6; // rcx
  hkpMoppCodeGenerator *v7; // rcx

  m_code = this->m_code;
  m_code->m_code[m_code->m_size - m_code->m_pos++ - 1] = cmd->m_moppOffset[2];
  if ( m_code->m_pos >= m_code->m_size )
    hkpMoppCodeGenerator::resize(m_code);
  v5 = this->m_code;
  v5->m_code[v5->m_size - v5->m_pos++ - 1] = cmd->m_moppOffset[1];
  if ( v5->m_pos >= v5->m_size )
    hkpMoppCodeGenerator::resize(v5);
  v6 = this->m_code;
  v6->m_code[v6->m_size - v6->m_pos++ - 1] = cmd->m_moppOffset[0];
  if ( v6->m_pos >= v6->m_size )
    hkpMoppCodeGenerator::resize(v6);
  v7 = this->m_code;
  v7->m_code[v7->m_size - v7->m_pos++ - 1] = cmd->m_scaleCommand;
  if ( v7->m_pos >= v7->m_size )
    hkpMoppCodeGenerator::resize(v7);
}

// File Line: 1258
// RVA: 0xDFD300
void __fastcall hkpMoppDefaultAssembler::addTermIdOffset(hkpMoppDefaultAssembler *this, unsigned int offset)
{
  hkpMoppCodeGenerator *v2; // rbx
  hkpMoppCodeGenerator *m_code; // rcx

  if ( offset >= 0x100 )
  {
    m_code = this->m_code;
    if ( offset >= 0x10000 )
      hkpMoppCodeGenerator::addCommand32(m_code, 11, offset);
    else
      hkpMoppCodeGenerator::addCommand16(m_code, 10, offset);
  }
  else
  {
    v2 = this->m_code;
    v2->m_code[v2->m_size - (__int64)v2->m_pos++ - 1] = offset;
    if ( v2->m_pos >= v2->m_size )
      hkpMoppCodeGenerator::resize(v2);
    v2->m_code[v2->m_size - (__int64)v2->m_pos++ - 1] = 9;
    if ( v2->m_pos >= v2->m_size )
      hkpMoppCodeGenerator::resize(v2);
  }
}

// File Line: 1276
// RVA: 0xDFDA50
void __fastcall hkpMoppDefaultAssembler::addCut(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeNode *currentNode,
        hkpMoppAssemblerNodeInfo *currentInfo)
{
  int v5; // edi
  hkEnum<enum hkpMoppAssemblerData::hkpCutCommandType,signed char> *m_cutCommandType; // rsi
  int *v7; // r14
  int *m_accumOffset; // r15
  hkpMoppCodeGenerator *m_code; // r9
  int m_currentBitsResolution; // ecx
  int v11; // ebx
  int v12; // ebx
  hkpMoppCodeGenerator *v13; // rcx
  hkpMoppCodeGenerator *v14; // rcx
  int v15; // ebx
  hkpMoppCodeGenerator *v16; // rcx

  v5 = 0;
  m_cutCommandType = currentNode->m_assemblerData.m_cutCommandType;
  v7 = &currentInfo->m_extents[0][1];
  m_accumOffset = currentInfo->m_accumOffset;
  do
  {
    if ( m_cutCommandType->m_storage == 1 )
    {
      m_code = this->m_code;
      m_currentBitsResolution = currentInfo->m_currentBitsResolution;
      v11 = *(v7 - 1) - *m_accumOffset;
      m_code->m_code[m_code->m_size - m_code->m_pos++ - 1] = ((*v7 - *m_accumOffset) >> m_currentBitsResolution) + 1;
      v12 = v11 >> m_currentBitsResolution;
      if ( m_code->m_pos >= m_code->m_size )
        hkpMoppCodeGenerator::resize(m_code);
      v13 = this->m_code;
      v13->m_code[v13->m_size - v13->m_pos++ - 1] = v12;
      if ( v13->m_pos >= v13->m_size )
        hkpMoppCodeGenerator::resize(v13);
      v14 = this->m_code;
      v14->m_code[v14->m_size - v14->m_pos++ - 1] = v5 + 38;
      if ( v14->m_pos >= v14->m_size )
        hkpMoppCodeGenerator::resize(v14);
    }
    if ( m_cutCommandType->m_storage == 2 )
    {
      v15 = *(v7 - 1);
      hkpMoppCodeGenerator::addParam24(this->m_code, *v7 + 1);
      hkpMoppCodeGenerator::addParam24(this->m_code, v15);
      v16 = this->m_code;
      v16->m_code[v16->m_size - v16->m_pos++ - 1] = v5 + 41;
      if ( v16->m_pos >= v16->m_size )
        hkpMoppCodeGenerator::resize(v16);
    }
    ++v5;
    ++m_accumOffset;
    ++m_cutCommandType;
    v7 += 2;
  }
  while ( v5 < 3 );
}

// File Line: 1310
// RVA: 0xDFD4B0
void __fastcall hkpMoppDefaultAssembler::addSplit(
        hkpMoppDefaultAssembler *this,
        int pright,
        int pleft,
        int directionCode,
        int lpos,
        int rpos)
{
  int m_pos; // r14d
  hkpMoppCodeGenerator *m_code; // rcx
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

  LOBYTE(m_pos) = rpos;
  m_code = this->m_code;
  v9 = directionCode;
  v10 = pleft;
  v11 = pright;
  v12 = m_code->m_pos - rpos;
  if ( directionCode >= 3 )
    goto LABEL_27;
  v13 = m_code->m_pos - lpos;
  if ( (v13 > 0 || v12 > 248) && v13 < 0x10000 && v12 < 0x10000 )
  {
    m_code->m_code[m_code->m_size - m_code->m_pos++ - 1] = v12;
    if ( m_code->m_pos >= m_code->m_size )
      hkpMoppCodeGenerator::resize(m_code);
    v14 = this->m_code;
    v14->m_code[v14->m_size - v14->m_pos++ - 1] = BYTE1(v12);
    if ( v14->m_pos >= v14->m_size )
      hkpMoppCodeGenerator::resize(v14);
    v15 = this->m_code;
    v15->m_code[v15->m_size - v15->m_pos++ - 1] = v13;
    if ( v15->m_pos >= v15->m_size )
      hkpMoppCodeGenerator::resize(v15);
    v16 = this->m_code;
    v16->m_code[v16->m_size - v16->m_pos++ - 1] = BYTE1(v13);
    if ( v16->m_pos >= v16->m_size )
      hkpMoppCodeGenerator::resize(v16);
    v17 = this->m_code;
    v17->m_code[v17->m_size - v17->m_pos++ - 1] = v11;
    if ( v17->m_pos >= v17->m_size )
      hkpMoppCodeGenerator::resize(v17);
    v18 = this->m_code;
    v18->m_code[v18->m_size - v18->m_pos++ - 1] = v10;
    if ( v18->m_pos >= v18->m_size )
      hkpMoppCodeGenerator::resize(v18);
    v19 = v9 + 35;
    goto LABEL_36;
  }
  if ( pleft - pright == 1 )
  {
    if ( v12 > 251 )
    {
      hkpMoppDefaultAssembler::addJump(this, rpos);
      m_pos = this->m_code->m_pos;
    }
    hkpMoppDefaultAssembler::addJump(this, lpos);
    v20 = this->m_code;
    v20->m_code[v20->m_size - v20->m_pos++ - 1] = LOBYTE(v20->m_pos) - m_pos;
    if ( v20->m_pos >= v20->m_size )
      hkpMoppCodeGenerator::resize(v20);
    v21 = this->m_code;
    v21->m_code[v21->m_size - v21->m_pos++ - 1] = v11;
    if ( v21->m_pos >= v21->m_size )
      hkpMoppCodeGenerator::resize(v21);
    v19 = v9 + 32;
  }
  else
  {
LABEL_27:
    if ( v12 > 251 )
    {
      hkpMoppDefaultAssembler::addJump(this, rpos);
      m_pos = this->m_code->m_pos;
    }
    hkpMoppDefaultAssembler::addJump(this, lpos);
    v22 = this->m_code;
    v22->m_code[v22->m_size - v22->m_pos++ - 1] = LOBYTE(v22->m_pos) - m_pos;
    if ( v22->m_pos >= v22->m_size )
      hkpMoppCodeGenerator::resize(v22);
    v23 = this->m_code;
    v23->m_code[v23->m_size - v23->m_pos++ - 1] = v11;
    if ( v23->m_pos >= v23->m_size )
      hkpMoppCodeGenerator::resize(v23);
    v24 = this->m_code;
    v24->m_code[v24->m_size - v24->m_pos++ - 1] = v10;
    if ( v24->m_pos >= v24->m_size )
      hkpMoppCodeGenerator::resize(v24);
    v19 = v9 + 16;
  }
LABEL_36:
  v25 = this->m_code;
  v25->m_code[v25->m_size - v25->m_pos++ - 1] = v19;
  if ( v25->m_pos >= v25->m_size )
    hkpMoppCodeGenerator::resize(v25);
}

// File Line: 1380
// RVA: 0xDFD3B0
void __fastcall hkpMoppDefaultAssembler::checkAndAddProperties(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeNode *currentNode,
        hkpMoppAssemblerNodeInfo *parentInfo,
        hkpMoppAssemblerNodeInfo *currentInfo)
{
  int v4; // r8d

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
__int64 __fastcall hkpMoppDefaultAssembler::addTerminals(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeTerminal *thisNode,
        hkpMoppAssemblerNodeInfo *parentInfo,
        hkpMoppAssemblerNodeInfo *currentInfo)
{
  hkpMoppCodeGenerator *m_code; // rcx
  unsigned int v8; // r8d
  int m_pos; // r12d
  int *p_m_numProperties; // rsi
  int v11; // edi
  signed __int64 v12; // rbp
  unsigned int *m_propertiesSpread; // rbx
  int v14; // r8d

  m_code = this->m_code;
  v8 = thisNode->m_primitive->m_primitiveID - currentInfo->m_terminalOffset;
  m_pos = m_code->m_pos;
  if ( v8 >= 0x20 )
  {
    if ( v8 >= 0x100 )
    {
      if ( v8 >= 0x10000 )
      {
        if ( v8 >= 0x1000000 )
          hkpMoppCodeGenerator::addCommand32(m_code, 83, v8);
        else
          hkpMoppCodeGenerator::addCommand24(m_code, 82, v8);
      }
      else
      {
        hkpMoppCodeGenerator::addCommand16(m_code, 81, v8);
      }
    }
    else
    {
      hkpMoppCodeGenerator::addCommand8(m_code, 80, v8);
    }
  }
  else
  {
    m_code->m_code[m_code->m_size - m_pos - 1] = v8 + 48;
    if ( ++m_code->m_pos >= m_code->m_size )
      hkpMoppCodeGenerator::resize(m_code);
  }
  p_m_numProperties = &thisNode->m_numProperties;
  v11 = 0;
  if ( thisNode->m_numProperties > 0 )
  {
    v12 = (char *)thisNode - (char *)parentInfo;
    m_propertiesSpread = parentInfo->m_propertiesSpread;
    do
    {
      v14 = *(unsigned int *)((char *)m_propertiesSpread + v12 - 16);
      if ( v14 && *m_propertiesSpread )
        hkpMoppDefaultAssembler::addProperty(this, v11, v14);
      ++v11;
      ++m_propertiesSpread;
    }
    while ( v11 < *p_m_numProperties );
  }
  return (unsigned int)(this->m_code->m_pos - m_pos);
}

// File Line: 1456
// RVA: 0xDFD9F0
void __fastcall hkpMoppDefaultAssembler::addJump(hkpMoppDefaultAssembler *this, unsigned int jumpPos)
{
  hkpMoppCodeGenerator *m_code; // rcx
  int v3; // r8d

  m_code = this->m_code;
  v3 = m_code->m_pos - jumpPos;
  if ( v3 > 0 )
  {
    if ( v3 >= 255 )
    {
      if ( v3 >= 0xFFFF )
      {
        if ( v3 >= 0xFFFFFF )
          hkpMoppCodeGenerator::addCommand32(m_code, 8, v3);
        else
          hkpMoppCodeGenerator::addCommand24(m_code, 7, v3);
      }
      else
      {
        hkpMoppCodeGenerator::addCommand16(m_code, 6, v3);
      }
    }
    else
    {
      hkpMoppCodeGenerator::addCommand8(m_code, 5, v3);
    }
  }
}

// File Line: 1486
// RVA: 0xDFD3F0
__int64 __fastcall hkpMoppDefaultAssembler::getSplitCode(hkpMoppDefaultAssembler *this, hkVector4f *norm)
{
  float v2; // xmm2_4
  __int64 result; // rax
  float v4; // xmm1_4
  bool v5; // cf
  float v6; // xmm2_4
  float v7; // xmm1_4

  if ( norm->m_quad.m128_f32[0] <= 0.1 )
  {
    if ( norm->m_quad.m128_f32[1] <= 0.1 )
    {
      return 2i64;
    }
    else
    {
      v7 = norm->m_quad.m128_f32[2];
      result = 1i64;
      if ( v7 <= 0.1 )
      {
        if ( v7 < -0.1 )
          return 4i64;
      }
      else
      {
        return 3i64;
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
            return 12i64;
        }
        else
        {
          return 10i64;
        }
      }
      else if ( v6 <= 0.1 )
      {
        if ( v6 < -0.1 )
          return 8i64;
      }
      else
      {
        return 7i64;
      }
    }
    else
    {
      v4 = norm->m_quad.m128_f32[1];
      result = 5i64;
      if ( v4 <= 0.1 )
      {
        if ( v4 < -0.1 )
          return 11i64;
      }
      else
      {
        return 9i64;
      }
    }
  }
  return result;
}

// File Line: 1543
// RVA: 0xDFC310
void __fastcall hkpMoppDefaultAssembler::findPlanes(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeInternalNode *node,
        hkpMoppAssemblerNodeInfo *info,
        int *pleft,
        int *pright)
{
  hkpMoppSplittingPlaneDirection *m_plane; // rdi
  int v6; // r11d
  int v8; // r10d
  int v9; // eax
  int v10; // esi
  float v11; // xmm0_4
  float v12; // xmm0_4
  double m_planeRightPosition; // xmm6_8
  double m_planeLeftPosition; // xmm8_8
  float v15; // xmm2_4
  double v16; // xmm1_8
  int v17; // r8d
  int m_currentBitsResolution; // ecx
  unsigned int v19; // xmm0_4
  __m128 v20; // xmm6
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  unsigned int v23; // xmm0_4
  unsigned int v24; // xmm3_4
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  int v27; // edx
  __m128 v28; // xmm0
  int v29; // eax
  int v30; // r8d
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  int v35; // eax
  __m128i v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm4
  double v39; // xmm4_8
  double v40; // xmm7_8
  double v41; // xmm6_8
  double v42; // xmm8_8
  double v43; // xmm6_8
  double v44; // xmm8_8
  double v45; // xmm0_8
  int v46; // r8d
  int v47; // edx
  unsigned int v48; // xmm0_4
  __m128 v49; // xmm2
  __m128 v50; // xmm3
  int v51; // ecx
  unsigned int v52; // xmm0_4
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  __m128 v55; // xmm0
  int v56; // eax
  int v57; // ecx
  float v58; // [rsp+48h] [rbp+10h]

  m_plane = node->m_plane;
  v6 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  if ( m_plane->m_direction.m_quad.m128_f32[0] != 0.0 )
  {
    v8 = 1;
    if ( m_plane->m_direction.m_quad.m128_f32[0] < 0.0 )
      v9 = 1;
  }
  v11 = m_plane->m_direction.m_quad.m128_f32[1];
  if ( v11 != 0.0 )
  {
    ++v8;
    v10 = 1;
    if ( v11 < 0.0 )
      ++v9;
  }
  v12 = m_plane->m_direction.m_quad.m128_f32[2];
  if ( v12 != 0.0 )
  {
    ++v8;
    v10 = 2;
    if ( v12 < 0.0 )
      ++v9;
  }
  m_planeRightPosition = node->m_planeRightPosition;
  m_planeLeftPosition = node->m_planeLeftPosition;
  if ( v8 == 1 )
  {
    v15 = this->m_codeInfo.m_offset.m_quad.m128_f32[v10];
    v16 = this->m_codeInfo.m_offset.m_quad.m128_f32[3];
    v17 = info->m_accumOffset[v10];
    m_currentBitsResolution = info->m_currentBitsResolution;
    *(float *)&v19 = (m_planeRightPosition - v15) * v16;
    v20 = (__m128)v19;
    v21 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v19, 1u), 1u));
    v22 = _mm_sub_ps(
            _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v19, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23);
    *(float *)&v23 = (m_planeLeftPosition - v15) * v16;
    v24 = v23;
    v25 = _mm_sub_ps(
            _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v23, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23);
    v26 = _mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v23, v25));
    v27 = ((int)COERCE_FLOAT(_mm_andnot_ps(v21, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps(v20, v22)), v22)).m128_u32[0] | v21.m128_i32[0] & v20.m128_i32[0])
         - v17) >> m_currentBitsResolution;
    v28 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v23, 1u), 1u));
    v29 = (int)COERCE_FLOAT(_mm_andnot_ps(v28, _mm_add_ps(v26, v25)).m128_u32[0] | v28.m128_i32[0] & v24) - v17;
    v30 = 255;
    v31 = v29 >> m_currentBitsResolution;
    v32 = 0;
    v33 = v31 + 1;
    if ( v27 > 0 )
      v32 = v27;
    v34 = 0;
    if ( v33 > 0 )
      v34 = v33;
    v35 = 255;
    if ( v32 < 255 )
      v35 = v32;
    if ( v34 < 255 )
      v30 = v34;
    *pright = v35;
    *pleft = v30;
    if ( *pright < 0 )
      *pright = 0;
  }
  else
  {
    v58 = this->m_codeInfo.m_offset.m_quad.m128_f32[3];
    v36 = (__m128i)_mm_shuffle_ps((__m128)LODWORD(v58), (__m128)LODWORD(v58), 0);
    v37 = _mm_cmpeq_ps((__m128)v36, (__m128)0i64);
    v38 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_or_ps(
                  _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v36, 0x1Fu), 0x1Fu), (__m128)_xmm), v37),
                  _mm_andnot_ps(v37, _mm_div_ps(query.m_quad, (__m128)v36))),
                _mm_unpacklo_ps(
                  _mm_unpacklo_ps(
                    (__m128)COERCE_UNSIGNED_INT((float)info->m_accumOffset[0]),
                    (__m128)COERCE_UNSIGNED_INT((float)info->m_accumOffset[2])),
                  _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)info->m_accumOffset[1]), (__m128)0i64))),
              this->m_codeInfo.m_offset.m_quad),
            m_plane->m_direction.m_quad);
    v37.m128_f32[0] = (float)(_mm_shuffle_ps(v38, v38, 85).m128_f32[0] + _mm_shuffle_ps(v38, v38, 0).m128_f32[0])
                    + _mm_shuffle_ps(v38, v38, 170).m128_f32[0];
    v39 = DOUBLE_1_0;
    v40 = DOUBLE_1_0;
    *(double *)v36.m128i_i64 = 1.0 / (float)(1 << info->m_currentBitsResolution);
    v41 = (m_planeRightPosition - v37.m128_f32[0]) * v58 * *(double *)v36.m128i_i64;
    v42 = (m_planeLeftPosition - v37.m128_f32[0]) * v58 * *(double *)v36.m128i_i64;
    if ( v8 == 2 )
    {
      v39 = DOUBLE_1_414213538169861;
      v40 = DOUBLE_0_5;
    }
    else if ( v8 == 3 )
    {
      v39 = DOUBLE_1_732050776481628;
      v40 = DOUBLE_0_3333333333333333;
    }
    v43 = v41 * v39;
    v44 = v42 * v39;
    if ( v9 )
    {
      v45 = (double)(255 * v9);
      v43 = v43 + v45;
      v44 = v44 + v45;
    }
    v46 = 255;
    v47 = 0;
    *(float *)&v48 = v40 * v43;
    v49 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v48, 1u), 1u));
    v50 = _mm_sub_ps(
            _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v48, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23);
    v51 = (int)COERCE_FLOAT(_mm_andnot_ps(
                              v49,
                              _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v48, v50)), v50)).m128_u32[0] | v49.m128_i32[0] & v48);
    *(float *)&v52 = v40 * v44;
    v50.m128_i32[0] = v52;
    v53 = _mm_sub_ps(
            _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v52, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23);
    v54 = _mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v52, v53));
    v55 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v52, 1u), 1u));
    v56 = (int)COERCE_FLOAT(_mm_andnot_ps(v55, _mm_add_ps(v54, v53)).m128_u32[0] | v55.m128_i32[0] & v50.m128_i32[0])
        + 1;
    if ( v51 > 0 )
      v47 = v51;
    v57 = 255;
    if ( v56 > 0 )
      v6 = v56;
    if ( v47 < 255 )
      v57 = v47;
    if ( v6 < 255 )
      v46 = v6;
    *pright = v57;
    *pleft = v46;
  }
}

// File Line: 1673
// RVA: 0xDFB680
void __fastcall hkpMoppDefaultAssembler::getScaleInfo(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeNode *rootNode,
        hkpMoppCode::CodeInfo *moppCodeInfo)
{
  float v3; // xmm4_4
  hkpMoppTreeNode::hkpMopp3DOPExtents *p_m_extents; // rax
  __int64 v5; // rcx
  float m_max; // xmm0_4

  v3 = 0.0;
  p_m_extents = &rootNode->m_extents;
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
    m_max = p_m_extents->m_extent[0].m_max;
    p_m_extents = (hkpMoppTreeNode::hkpMopp3DOPExtents *)((char *)p_m_extents + 8);
    v3 = fmaxf(v3, m_max - p_m_extents[-1].m_extent[2].m_min);
    --v5;
  }
  while ( v5 );
  moppCodeInfo->m_offset.m_quad.m128_f32[3] = (float)(254.0 / v3) * 65536.0;
}

// File Line: 1694
// RVA: 0xDFB770
__int64 __fastcall hkpMoppDefaultAssembler::assembleCutAndTerminalCommand(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeTerminal *currentNode,
        hkpMoppAssemblerNodeInfo *parentInfo,
        hkpMoppAssemblerNodeInfo *currentInfo)
{
  hkpMoppCodeGenerator *m_code; // rax
  int m_pos; // edi
  int v10; // eax

  hkpMoppDefaultAssembler::fixScale(this, currentNode);
  m_code = this->m_code;
  ++this->m_numNodesAssembled;
  m_pos = m_code->m_pos;
  hkpMoppDefaultAssembler::addTerminals(this, currentNode, parentInfo, currentInfo);
  hkpMoppDefaultAssembler::addCut(this, currentNode, currentInfo);
  currentNode->m_assemblerData.m_assembledAddress = this->m_code->m_pos;
  v10 = this->m_code->m_pos;
  currentNode->m_assemblerData.m_isAssembled.m_bool = 1;
  return (unsigned int)(v10 - m_pos);
}

// File Line: 1714
// RVA: 0xDFB800
__int64 __fastcall hkpMoppDefaultAssembler::assembleNonTerminalCommand(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeInternalNode *currentNode,
        hkpMoppAssemblerNodeInfo *parentInfo,
        hkpMoppAssemblerNodeInfo *currentInfo,
        hkpMoppAssemblerRescaleCommand *rescaleCommandInfo)
{
  int m_pos; // r12d
  hkpMoppExtent m_rightBranch; // rbx
  hkpMoppExtent m_leftBranch; // rdi
  HK_MOPP_SPLIT_DIRECTIONS SplitCode; // eax
  unsigned int v13; // edx
  int pleft; // [rsp+60h] [rbp+8h] BYREF
  int pright; // [rsp+68h] [rbp+10h] BYREF

  hkpMoppDefaultAssembler::fixScale(this, currentNode);
  m_pos = this->m_code->m_pos;
  hkpMoppDefaultAssembler::findPlanes(this, currentNode, currentInfo, &pleft, &pright);
  m_rightBranch = (hkpMoppExtent)currentNode->m_rightBranch;
  m_leftBranch = (hkpMoppExtent)currentNode->m_leftBranch;
  SplitCode = hkpMoppDefaultAssembler::getSplitCode(this, &currentNode->m_plane->m_direction);
  hkpMoppDefaultAssembler::addSplit(
    this,
    pright,
    pleft,
    SplitCode,
    *(_DWORD *)(*(_QWORD *)&m_leftBranch + 96i64),
    *(_DWORD *)(*(_QWORD *)&m_rightBranch + 96i64));
  v13 = currentInfo->m_terminalOffset - parentInfo->m_terminalOffset;
  if ( v13 )
    hkpMoppDefaultAssembler::addTermIdOffset(this, v13);
  hkpMoppDefaultAssembler::checkAndAddProperties(this, currentNode, parentInfo, currentInfo);
  hkpMoppDefaultAssembler::addCut(this, currentNode, currentInfo);
  if ( rescaleCommandInfo->m_doRescale.m_bool )
    hkpMoppDefaultAssembler::addRescale(this, rescaleCommandInfo);
  currentNode->m_assemblerData.m_assembledAddress = this->m_code->m_pos;
  currentNode->m_assemblerData.m_isAssembled.m_bool = 1;
  return (unsigned int)(this->m_code->m_pos - m_pos);
}

// File Line: 1793
// RVA: 0xDFB910
__int64 __fastcall hkpMoppDefaultAssembler::assembleJumpChunkCommand(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeNode *currentNode)
{
  int m_pos; // r14d
  int v5; // edi
  hkpMoppCodeGenerator *m_code; // rbx
  __int64 m_size; // r8
  hkpMoppCodeGenerator::JumpCommandInfo *v8; // r9
  int m_chunkId; // ecx

  m_pos = this->m_code->m_pos;
  hkpMoppDefaultAssembler::addJumpChunk(this, currentNode->m_assemblerData.m_chunkId);
  v5 = this->m_code->m_pos;
  currentNode->m_assemblerData.m_assembledAddress = v5;
  currentNode->m_assemblerData.m_isAssembled.m_bool = 1;
  m_code = this->m_code;
  if ( m_code->m_jumpCommands.m_size == (m_code->m_jumpCommands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_code->m_jumpCommands.m_data, 8);
  m_size = m_code->m_jumpCommands.m_size;
  v8 = &m_code->m_jumpCommands.m_data[m_size];
  m_code->m_jumpCommands.m_size = m_size + 1;
  m_chunkId = currentNode->m_assemblerData.m_chunkId;
  v8->m_position = v5;
  v8->m_chunkId = m_chunkId;
  hkpMoppCodeGenerator::validateJumpCommands(this->m_code);
  return (unsigned int)(v5 - m_pos);
}

// File Line: 1823
// RVA: 0xDFB190
void __fastcall hkpMoppDefaultAssembler::assemble(
        hkpMoppDefaultAssembler *this,
        hkpMoppTreeNode *rootNode,
        hkpMoppNodeMgr *mgr,
        int minAssembledElems)
{
  unsigned int m_maxPrimitiveId; // eax
  int v7; // ecx
  int m_minDepthToBuild; // ecx
  unsigned int v9; // eax
  signed int v10; // ebx
  int m_numProperties; // eax
  unsigned int *m_maxPropertyValue; // rdx
  __int64 v13; // r8
  unsigned int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // r8d
  char v18; // cl
  unsigned int v19; // eax
  __int64 v20; // r14
  int v21; // edx
  __int64 v22; // r9
  int v23; // r8d
  unsigned int v24; // eax
  int v25; // ecx
  unsigned int v26; // eax
  int v27; // eax
  int v28; // eax
  unsigned int *v29; // rdx
  __int64 v30; // r8
  unsigned int v31; // ecx
  int v32; // eax
  signed int v33; // ecx
  signed int v34; // edx
  char v35; // cl
  unsigned int v36; // eax
  int v37; // edx
  unsigned int v38; // eax
  signed int v39; // ecx
  hkpMoppCompilerChunkInfo *m_chunkInfo; // rbx
  hkpMoppCodeGenerator *m_code; // rbx
  int v42; // ecx
  hkpMoppCompilerChunkInfo *v43; // rcx
  hkpMoppCodeGenerator *v44; // rcx
  hkpMoppCompilerChunkInfo::Chunk *v45; // rbx
  hkArray<unsigned int,hkContainerHeapAllocator> terminals; // [rsp+30h] [rbp-B0h] BYREF
  hkpMoppAssemblerNodeInfo parentInfo; // [rsp+40h] [rbp-A0h] BYREF
  int v48; // [rsp+88h] [rbp-58h]
  int v49; // [rsp+8Ch] [rbp-54h]
  int v50; // [rsp+90h] [rbp-50h]
  __int64 v51; // [rsp+94h] [rbp-4Ch]
  __int64 v52; // [rsp+9Ch] [rbp-44h]
  int v53; // [rsp+A4h] [rbp-3Ch]
  int v54; // [rsp+A8h] [rbp-38h]
  int v55; // [rsp+ACh] [rbp-34h]
  hkpMoppAssemblerCutInfo currentInfo; // [rsp+D0h] [rbp-10h] BYREF
  hkpMoppAssemblerNodeInfo v57; // [rsp+130h] [rbp+50h] BYREF

  this->m_nodeMgr = mgr;
  this->m_minAssembledElems = minAssembledElems;
  this->m_numNodesAssembled = 0;
  if ( rootNode )
  {
    ((void (__fastcall *)(hkpMoppDefaultAssembler *, hkpMoppTreeNode *, hkpMoppCode::CodeInfo *))this->vfptr[3].__vecDelDtor)(
      this,
      rootNode,
      &this->m_codeInfo);
    this->m_minDepthToBuild = 0;
    m_maxPrimitiveId = rootNode->m_maxPrimitiveId;
    if ( m_maxPrimitiveId )
    {
      v7 = 0;
      do
      {
        ++v7;
        m_maxPrimitiveId >>= 1;
      }
      while ( m_maxPrimitiveId );
      this->m_minDepthToBuild = v7;
    }
    m_minDepthToBuild = this->m_minDepthToBuild;
    this->m_halfTreeDepth = m_minDepthToBuild >> 1;
    this->m_minDepthToBuild = this->m_params.m_groupLevels * (m_minDepthToBuild / this->m_params.m_groupLevels + 2) - 1;
    hkpMoppAssemblerNodeInfo::updateExtents(&parentInfo, rootNode, &this->m_codeInfo);
    v9 = rootNode->m_maxPrimitiveId - rootNode->m_minPrimitiveId;
    v10 = -1;
    *(_QWORD *)&parentInfo.m_currentBitsResolution = 16i64;
    parentInfo.m_terminalSpread = v9;
    m_numProperties = rootNode->m_numProperties;
    *(_QWORD *)&parentInfo.m_accumOffset[1] = 0i64;
    parentInfo.m_level = -1;
    parentInfo.m_terminalOffset = 0;
    parentInfo.m_ignoreBandControlCode.m_bool = 0;
    parentInfo.m_numProperties = m_numProperties;
    if ( m_numProperties > 0 )
    {
      m_maxPropertyValue = rootNode->m_maxPropertyValue;
      v13 = (unsigned int)m_numProperties;
      do
      {
        v14 = *(m_maxPropertyValue - 1);
        v15 = *m_maxPropertyValue++;
        *(unsigned int *)((char *)m_maxPropertyValue
                        + (char *)&parentInfo.m_maxExtentsSignificantBits
                        - (char *)rootNode
                        - 4) = v14;
        *(unsigned int *)((char *)m_maxPropertyValue + (char *)parentInfo.m_extents - (char *)rootNode - 4) = v15 - v14;
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
    hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(&currentInfo, &parentInfo, rootNode, &this->m_codeInfo);
    hkpMoppDefaultAssembler::preCalcScale(this, rootNode, &parentInfo, &currentInfo);
    hkpMoppAssemblerNodeInfo::updateExtents(
      (hkpMoppAssemblerNodeInfo *)&parentInfo.m_accumOffset[2],
      rootNode,
      &this->m_codeInfo);
    v26 = rootNode->m_maxPrimitiveId;
    v51 = 16i64;
    v27 = v26 - rootNode->m_minPrimitiveId;
    v52 = 0i64;
    parentInfo.m_accumOffset[2] = -1;
    v54 = v27;
    v28 = rootNode->m_numProperties;
    v53 = 0;
    LOBYTE(parentInfo.m_terminalOffset) = 0;
    v55 = v28;
    if ( v28 > 0 )
    {
      v29 = rootNode->m_maxPropertyValue;
      v30 = (unsigned int)v28;
      do
      {
        v31 = *(v29 - 1);
        v32 = *v29++;
        *(unsigned int *)((char *)v29 + (char *)&parentInfo.m_terminalSpread - (char *)rootNode - 4) = v31;
        *(unsigned int *)((char *)v29 + (char *)&parentInfo.m_numProperties - (char *)rootNode - 4) = v32 - v31;
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
      (hkpMoppAssemblerNodeInfo *)&parentInfo.m_accumOffset[2],
      rootNode,
      &this->m_codeInfo);
    hkpMoppDefaultAssembler::preCalcCutPositions(
      this,
      rootNode,
      (hkpMoppAssemblerCutInfo *)&parentInfo.m_accumOffset[2],
      &currentInfo);
    hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(&v57, &parentInfo, rootNode, &this->m_codeInfo);
    if ( this->m_chunkInfo )
    {
      rootNode->m_assemblerData.m_chunkId = 0;
      m_chunkInfo = this->m_chunkInfo;
      if ( m_chunkInfo->m_chunks.m_size == (m_chunkInfo->m_chunks.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_chunkInfo->m_chunks.m_data, 16);
      ++m_chunkInfo->m_chunks.m_size;
      m_code = this->m_code;
      hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(
        (hkpMoppAssemblerNodeInfo *)&parentInfo.m_accumOffset[2],
        &parentInfo,
        rootNode,
        &this->m_codeInfo);
      terminals.m_data = 0i64;
      terminals.m_size = 0;
      terminals.m_capacityAndFlags = 0x80000000;
      hkpMoppCodeGenerator::hkpMoppCodeGenerator((hkpMoppCodeGenerator *)&currentInfo, 0x100000u);
      this->m_code = (hkpMoppCodeGenerator *)&currentInfo;
      hkpMoppDefaultAssembler::calcChunkPoints(
        this,
        rootNode,
        &parentInfo,
        (hkpMoppAssemblerNodeInfo *)&parentInfo.m_accumOffset[2],
        &terminals);
      hkpMoppDefaultAssembler::calcTerminalIdsForChunks(this, rootNode, rootNode->m_assemblerData.m_chunkId, 0);
      hkpMoppCodeGenerator::~hkpMoppCodeGenerator((hkpMoppCodeGenerator *)&currentInfo);
      terminals.m_size = 0;
      if ( terminals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          terminals.m_data,
          4 * terminals.m_capacityAndFlags);
      terminals.m_data = 0i64;
      terminals.m_size = 0;
      terminals.m_capacityAndFlags = 0x80000000;
      hkpMoppCodeGenerator::hkpMoppCodeGenerator((hkpMoppCodeGenerator *)&currentInfo, 0x100000u);
      this->m_code = (hkpMoppCodeGenerator *)&currentInfo;
      hkpMoppDefaultAssembler::assembleSubNodeIntoChunks(
        this,
        rootNode,
        &parentInfo,
        &v57,
        rootNode->m_assemblerData.m_chunkId,
        &terminals);
      if ( this->m_chunkInfo->m_compressor )
      {
        v42 = this->m_code->m_pos + 5;
        hkpMoppDefaultAssembler::addDataOffset(this, v42 + (-v42 & 3), terminals.m_size);
      }
      v43 = this->m_chunkInfo;
      this->m_code = m_code;
      copyCodeAndEmbedTerminals(v43, m_code, (hkpMoppCodeGenerator *)&currentInfo, &terminals);
      v44 = this->m_code;
      v45 = &this->m_chunkInfo->m_chunks.m_data[rootNode->m_assemblerData.m_chunkId];
      v45->m_code = v44;
      hkReferencedObject::addReference(v44);
      v45->m_codeSize = this->m_code->m_pos;
      hkpMoppCodeGenerator::~hkpMoppCodeGenerator((hkpMoppCodeGenerator *)&currentInfo);
      terminals.m_size = 0;
      if ( terminals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          terminals.m_data,
          4 * terminals.m_capacityAndFlags);
    }
    else
    {
      hkpMoppDefaultAssembler::assemblesubNode(this, rootNode, &parentInfo, &v57);
    }
  }
}

