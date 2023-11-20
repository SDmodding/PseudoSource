// File Line: 6
// RVA: 0xD8790
UFG::RoadNetworkWayfindingEdge *__fastcall UFG::RoadNetworkWayfindingList::GetEdge(UFG::RoadNetworkWayfindingList *this, unsigned int index)
{
  __int64 v2; // rax
  UFG::RoadNetworkWayfindingEdge *result; // rax

  v2 = this->mEdgeList.mOffset;
  if ( v2 )
    result = (UFG::RoadNetworkWayfindingEdge *)((char *)&this->mEdgeList.mOffset + 8 * index + v2);
  else
    result = (UFG::RoadNetworkWayfindingEdge *)(8i64 * index);
  return result;
}

// File Line: 13
// RVA: 0xDAE90
UFG::RoadNetworkWayfindingNode *__fastcall UFG::RoadNetworkWayfindingList::GetNode(UFG::RoadNetworkWayfindingList *this, unsigned int index)
{
  __int64 v2; // rax
  UFG::RoadNetworkWayfindingNode *result; // rax

  v2 = this->mNodeList.mOffset;
  if ( v2 )
    result = (UFG::RoadNetworkWayfindingNode *)((char *)&this->mNodeList.mOffset + 8 * (index - this->mNumEdges) + v2);
  else
    result = (UFG::RoadNetworkWayfindingNode *)(8i64 * (index - this->mNumEdges));
  return result;
}

// File Line: 22
// RVA: 0xDAEC0
__int64 __fastcall UFG::RoadNetworkWayfindingList::GetNodeEdge(UFG::RoadNetworkWayfindingList *this, unsigned int node_index, unsigned int which_edge)
{
  __int64 v3; // rax
  char *v4; // r9
  char *v5; // r10
  __int64 v6; // rax
  char *v7; // rdx

  v3 = this->mNodeList.mOffset;
  v4 = 0i64;
  if ( v3 )
    v5 = (char *)&this->mNodeList + v3;
  else
    v5 = 0i64;
  v6 = this->mNodeEdges.mOffset;
  v7 = &v5[8 * (node_index - this->mNumEdges)];
  if ( v6 )
    v4 = (char *)&this->mNodeEdges + v6;
  return *(unsigned int *)&v4[4 * (which_edge + *(_DWORD *)v7)];
}

