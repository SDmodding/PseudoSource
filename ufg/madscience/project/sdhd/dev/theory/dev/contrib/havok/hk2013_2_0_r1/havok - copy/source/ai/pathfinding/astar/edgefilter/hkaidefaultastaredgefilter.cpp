// File Line: 26
// RVA: 0xBE6F40
void __fastcall hkaiDefaultAstarEdgeFilter::hkaiDefaultAstarEdgeFilter(hkaiDefaultAstarEdgeFilter *this)
{
  hkaiDefaultAstarEdgeFilter *v1; // rdx
  unsigned int *v2; // rdi
  signed __int64 i; // rcx

  v1 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type.m_storage = 0;
  v2 = this->m_edgeMaskLookupTable;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDefaultAstarEdgeFilter::`vftable';
  for ( i = 32i64; i; --i )
  {
    *v2 = -1;
    ++v2;
  }
  v1->m_cellMaskLookupTable = -1;
}

// File Line: 42
// RVA: 0xBE7110
unsigned __int8 __fastcall hkaiDefaultAstarEdgeFilter::isEnabledByBitfield(hkaiDefaultAstarEdgeFilter *this, hkaiNavMeshInstance *mesh, hkaiAgentTraversalInfo *agentInfo, hkaiNavMeshEdgePairInfo *edgeInfo)
{
  unsigned int v4; // ecx

  v4 = this->m_edgeMaskLookupTable[*edgeInfo->m_outgoingEdgeInfo.m_edgeData & 0x1F];
  return _bittest((const signed int *)&v4, agentInfo->m_filterInfo);
}

// File Line: 49
// RVA: 0xBE70D0
bool __fastcall hkaiDefaultAstarEdgeFilter::isEnabled(hkaiDefaultAstarEdgeFilter *this, hkaiAstarEdgeFilter::NavMeshIsEnabledCallbackContext *context)
{
  hkaiNavMeshEdgePairInfo *v2; // r9
  bool result; // al

  v2 = context->m_edgeFaceInfo;
  if ( v2->m_outgoingEdgeInfo.m_edgeData )
    result = hkaiDefaultAstarEdgeFilter::isEnabledByBitfield(this, context->m_meshAccessor, context->m_agentInfo, v2);
  else
    result = 1;
  return result;
}

// File Line: 59
// RVA: 0xBE6FF0
void __fastcall hkaiDefaultAstarEdgeFilter::navMeshEnableUsingBitfield(hkaiDefaultAstarEdgeFilter *this, unsigned int agentBitsA, unsigned int edgeBitsB)
{
  signed int v3; // eax
  unsigned int *v4; // rcx
  signed __int64 v5; // r9
  int v6; // eax

  v3 = 1;
  v4 = &this->m_edgeMaskLookupTable[1];
  v5 = 16i64;
  do
  {
    if ( v3 & edgeBitsB )
      *(v4 - 1) |= agentBitsA;
    v6 = __ROL4__(v3, 1);
    if ( v6 & edgeBitsB )
      *v4 |= agentBitsA;
    v3 = __ROL4__(v6, 1);
    v4 += 2;
    --v5;
  }
  while ( v5 );
}

// File Line: 72
// RVA: 0xBE7030
void __fastcall hkaiDefaultAstarEdgeFilter::navMeshDisableUsingBitfield(hkaiDefaultAstarEdgeFilter *this, unsigned int agentBitsA, unsigned int edgeBitsB)
{
  signed int v3; // eax
  unsigned int *v4; // r9
  signed __int64 v5; // r10
  int v6; // eax

  v3 = 1;
  v4 = &this->m_edgeMaskLookupTable[1];
  v5 = 16i64;
  do
  {
    if ( v3 & edgeBitsB )
      *(v4 - 1) &= ~agentBitsA;
    v6 = __ROL4__(v3, 1);
    if ( v6 & edgeBitsB )
      *v4 &= ~agentBitsA;
    v3 = __ROL4__(v6, 1);
    v4 += 2;
    --v5;
  }
  while ( v5 );
}

// File Line: 85
// RVA: 0xBE6F90
void __fastcall hkaiDefaultAstarEdgeFilter::navMeshEnableBetween(hkaiDefaultAstarEdgeFilter *this, int agentCategory, int edgeCategory)
{
  hkaiDefaultAstarEdgeFilter::navMeshEnableUsingBitfield(this, 1 << agentCategory, 1 << edgeCategory);
}

// File Line: 93
// RVA: 0xBE6FC0
void __fastcall hkaiDefaultAstarEdgeFilter::navMeshDisableBetween(hkaiDefaultAstarEdgeFilter *this, int agentCategory, int edgeCategory)
{
  hkaiDefaultAstarEdgeFilter::navMeshDisableUsingBitfield(this, 1 << agentCategory, 1 << edgeCategory);
}

// File Line: 106
// RVA: 0xBE7130
unsigned __int8 __fastcall hkaiDefaultAstarEdgeFilter::isEnabledByBitfield(hkaiDefaultAstarEdgeFilter *this, hkaiNavVolumeInstance *volume, hkaiAgentTraversalInfo *agentInfo, hkaiNavVolumeCellPairInfo *edgeInfo)
{
  unsigned int v4; // edx
  unsigned int v6; // ecx

  v4 = edgeInfo->m_adjacentCellInfo.m_cell->m_data;
  if ( v4 >= 0x20 )
    return 1;
  v6 = this->m_cellMaskLookupTable;
  return _bittest((const signed int *)&v6, v4);
}

// File Line: 117
// RVA: 0xBE70F0
bool __fastcall hkaiDefaultAstarEdgeFilter::isEnabled(hkaiDefaultAstarEdgeFilter *this, hkaiAstarEdgeFilter::NavVolumeIsEnabledCallbackContext *context)
{
  hkaiNavVolumeCellPairInfo *v2; // r9
  bool result; // al

  v2 = context->m_cellEdgeInfo;
  if ( v2->m_adjacentCellInfo.m_cell )
    result = hkaiDefaultAstarEdgeFilter::isEnabledByBitfield(this, context->m_volumeAccessor, context->m_agentInfo, v2);
  else
    result = 1;
  return result;
}

// File Line: 126
// RVA: 0xBE70B0
void __fastcall hkaiDefaultAstarEdgeFilter::navVolumeEnableUsingBitfield(hkaiDefaultAstarEdgeFilter *this, unsigned int cellBits)
{
  this->m_cellMaskLookupTable |= cellBits;
}

// File Line: 131
// RVA: 0xBE70C0
void __fastcall hkaiDefaultAstarEdgeFilter::navVolumeDisableUsingBitfield(hkaiDefaultAstarEdgeFilter *this, unsigned int cellBits)
{
  this->m_cellMaskLookupTable &= ~cellBits;
}

// File Line: 136
// RVA: 0xBE7070
void __fastcall hkaiDefaultAstarEdgeFilter::navVolumeEnableBetween(hkaiDefaultAstarEdgeFilter *this, int cellCategory)
{
  hkaiDefaultAstarEdgeFilter::navVolumeEnableUsingBitfield(this, 1 << cellCategory);
}

// File Line: 142
// RVA: 0xBE7090
void __fastcall hkaiDefaultAstarEdgeFilter::navVolumeDisableBetween(hkaiDefaultAstarEdgeFilter *this, int cellCategory)
{
  hkaiDefaultAstarEdgeFilter::navVolumeDisableUsingBitfield(this, 1 << cellCategory);
}

