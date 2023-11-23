// File Line: 6
// RVA: 0xD8790
UFG::RoadNetworkWayfindingEdge *__fastcall UFG::RoadNetworkWayfindingList::GetEdge(
        UFG::RoadNetworkWayfindingList *this,
        unsigned int index)
{
  __int64 mOffset; // rax

  mOffset = this->mEdgeList.mOffset;
  if ( mOffset )
    return (UFG::RoadNetworkWayfindingEdge *)((char *)&this->mEdgeList + 8 * index + mOffset);
  else
    return (UFG::RoadNetworkWayfindingEdge *)(8i64 * index);
}

// File Line: 13
// RVA: 0xDAE90
UFG::RoadNetworkWayfindingNode *__fastcall UFG::RoadNetworkWayfindingList::GetNode(
        UFG::RoadNetworkWayfindingList *this,
        unsigned int index)
{
  __int64 mOffset; // rax

  mOffset = this->mNodeList.mOffset;
  if ( mOffset )
    return (UFG::RoadNetworkWayfindingNode *)((char *)&this->mNodeList + 8 * (index - this->mNumEdges) + mOffset);
  else
    return (UFG::RoadNetworkWayfindingNode *)(8i64 * (index - this->mNumEdges));
}

// File Line: 22
// RVA: 0xDAEC0
__int64 __fastcall UFG::RoadNetworkWayfindingList::GetNodeEdge(
        UFG::RoadNetworkWayfindingList *this,
        unsigned int node_index,
        unsigned int which_edge)
{
  __int64 mOffset; // rax
  char *v4; // r9
  char *v5; // r10
  __int64 v6; // rax
  char *v7; // rdx

  mOffset = this->mNodeList.mOffset;
  v4 = 0i64;
  if ( mOffset )
    v5 = (char *)&this->mNodeList + mOffset;
  else
    v5 = 0i64;
  v6 = this->mNodeEdges.mOffset;
  v7 = &v5[8 * (node_index - this->mNumEdges)];
  if ( v6 )
    v4 = (char *)&this->mNodeEdges + v6;
  return *(unsigned int *)&v4[4 * which_edge + 4 * *(_DWORD *)v7];
}

