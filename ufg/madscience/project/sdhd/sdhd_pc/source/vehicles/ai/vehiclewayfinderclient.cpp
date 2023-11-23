// File Line: 21
// RVA: 0x643320
void __fastcall UFG::VehicleWayFinderClient::VehicleWayFinderClient(
        UFG::VehicleWayFinderClient *this,
        UFG::RoadNetworkGuide *guide,
        unsigned int laneFlags)
{
  UFG::WayFinderClient::WayFinderClient(this);
  this->vfptr = (UFG::WayFinderClientVtbl *)&UFG::VehicleWayFinderClient::`vftable;
  this->m_RoadNetworkType = 0;
  this->m_LaneFlags = laneFlags;
  this->m_RoadGuide = guide;
  this->m_AllowFootPaths = 0;
  UFG::VehicleWayFinderClient::SetLaneFlagsFromGuide(this, guide);
}

// File Line: 26
// RVA: 0x647A70
bool __fastcall UFG::VehicleWayFinderClient::CanTurnAround(UFG::VehicleWayFinderClient *this)
{
  UFG::RoadNetworkGuide *m_RoadGuide; // rcx
  UFG::SimObjectCVBase *m_SimObj; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax

  m_RoadGuide = this->m_RoadGuide;
  if ( m_RoadGuide
    && (m_SimObj = (UFG::SimObjectCVBase *)m_RoadGuide->m_SimObj) != 0i64
    && ((m_Flags = m_SimObj->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_SimObj))
      : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_SimObj,
                                                         UFG::AiDriverComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_SimObj,
                                                         UFG::AiDriverComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    return ComponentOfTypeHK->m_bCanTurnAround;
  }
  else
  {
    return 0;
  }
}

// File Line: 37
// RVA: 0x651220
__int64 __fastcall UFG::VehicleWayFinderClient::GetWayEdge(UFG::VehicleWayFinderClient *this, UFG::WayGraph *graph)
{
  UFG::RoadNetworkGuide *m_RoadGuide; // rcx
  UFG::RoadNetworkLocation *Name; // rax
  UFG::RoadNetworkNode *RoadNetworkNode; // rdi

  m_RoadGuide = this->m_RoadGuide;
  if ( !m_RoadGuide || !m_RoadGuide->m_Attached )
    return this->m_CurrWayEdge;
  Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(m_RoadGuide);
  RoadNetworkNode = UFG::RoadNetworkLocation::GetRoadNetworkNode(Name);
  if ( RoadNetworkNode->mType.mValue == 1 )
    return graph->vfptr->GetNumEdges(graph) + RoadNetworkNode->mIndex;
  else
    return RoadNetworkNode->mIndex;
}

// File Line: 51
// RVA: 0x6512A0
__int64 __fastcall UFG::VehicleWayFinderClient::GetWayNode(UFG::VehicleWayFinderClient *this, UFG::WayGraph *graph)
{
  UFG::RoadNetworkGuide *m_RoadGuide; // rcx
  UFG::RoadNetworkConnection *NextConnection; // rax
  __int64 mOffset; // rdx
  int v8; // ecx
  _QWORD *v9; // rax
  char *v10; // rbx

  m_RoadGuide = this->m_RoadGuide;
  if ( !m_RoadGuide || !m_RoadGuide->m_Attached )
    return this->m_CurrWayNode;
  NextConnection = UFG::RoadNetworkGuide::GetNextConnection(m_RoadGuide);
  if ( !NextConnection )
    return 0xFFFFi64;
  mOffset = NextConnection->mGate.mOffset;
  v8 = 0;
  if ( mOffset )
    v9 = (__int64 *)((char *)&NextConnection->mGate.mOffset + mOffset);
  else
    v9 = 0i64;
  v10 = (char *)v9 + *v9;
  if ( !*v9 )
    v10 = 0i64;
  if ( *(_WORD *)v10 == 1 )
    v8 = graph->vfptr->GetNumEdges(graph);
  return (unsigned int)(v8 + *((_DWORD *)v10 + 6));
}

// File Line: 64
// RVA: 0x64EF40
UFG::qVector3 *__fastcall UFG::VehicleWayFinderClient::GetPosition(
        UFG::VehicleWayFinderClient *this,
        UFG::qVector3 *result)
{
  UFG::RoadNetworkGuide *m_RoadGuide; // rax
  UFG::RoadNetworkLocation *Name; // rax
  UFG::qVector3 *v5; // rax
  float y; // xmm0_4
  float z; // xmm1_4

  m_RoadGuide = this->m_RoadGuide;
  if ( m_RoadGuide && m_RoadGuide->m_Attached )
  {
    Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(this->m_RoadGuide);
    UFG::RoadNetworkLocation::GetPos(Name, result);
    return result;
  }
  else
  {
    y = this->m_CurrPos.y;
    z = this->m_CurrPos.z;
    result->x = this->m_CurrPos.x;
    v5 = result;
    result->y = y;
    result->z = z;
  }
  return v5;
}

// File Line: 72
// RVA: 0x64DA50
UFG::qVector3 *__fastcall UFG::VehicleWayFinderClient::GetDirection(
        UFG::VehicleWayFinderClient *this,
        UFG::qVector3 *result)
{
  UFG::RoadNetworkGuide *m_RoadGuide; // rax
  UFG::RoadNetworkLocation *Name; // rax
  UFG::qVector3 *v5; // rax
  float y; // xmm0_4
  float z; // xmm1_4

  m_RoadGuide = this->m_RoadGuide;
  if ( m_RoadGuide && m_RoadGuide->m_Attached )
  {
    Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(this->m_RoadGuide);
    UFG::RoadNetworkLocation::GetTangent(Name, result);
    return result;
  }
  else
  {
    y = this->m_CurrDir.y;
    z = this->m_CurrDir.z;
    result->x = this->m_CurrDir.x;
    v5 = result;
    result->y = y;
    result->z = z;
  }
  return v5;
}

// File Line: 80
// RVA: 0x647990
bool __fastcall UFG::VehicleWayFinderClient::CanGo(
        UFG::VehicleWayFinderClient *this,
        UFG::RoadNetworkGraph *graph,
        unsigned __int16 from_edge,
        unsigned __int16 to_edge,
        unsigned __int16 thru_node)
{
  UFG::RoadNetworkResource *pRoadNetworkResource; // rbx
  UFG::RoadNetworkSegment *Segment; // r14
  UFG::RoadNetworkSegment *v12; // rax

  if ( graph->vfptr->IsEdge(graph, thru_node) || to_edge == this->vfptr->GetWayEdge(this, graph) )
    return 1;
  pRoadNetworkResource = graph->pRoadNetworkResource;
  Segment = UFG::RoadNetworkResource::GetSegment(pRoadNetworkResource, to_edge);
  v12 = UFG::RoadNetworkResource::GetSegment(pRoadNetworkResource, from_edge);
  return (this->m_AllowFootPaths || (*(_DWORD *)&v12->mBits & 2) != 0 || (*(_DWORD *)&Segment->mBits & 2) == 0)
      && UFG::RoadNetworkGraph::GetNumLanesFromToThru(graph, from_edge, to_edge, thru_node, this->m_LaneFlags) > 0;
}

// File Line: 105
// RVA: 0x659900
void __fastcall UFG::VehicleWayFinderClient::SetRoadNetworkType(UFG::VehicleWayFinderClient *this, unsigned int type)
{
  this->m_RoadNetworkType = type;
}

// File Line: 119
// RVA: 0x6594F0
void __fastcall UFG::VehicleWayFinderClient::SetLaneFlagsFromGuide(
        UFG::VehicleWayFinderClient *this,
        UFG::RoadNetworkGuide *guide)
{
  UFG::SimObjectGame *m_SimObj; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int mNext; // ecx

  if ( guide )
  {
    if ( guide->m_Attached )
    {
      m_SimObj = (UFG::SimObjectGame *)guide->m_SimObj;
      if ( m_SimObj )
      {
        m_Flags = m_SimObj->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_SimObj->m_Components.p[24].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_SimObj, UFG::RoadSpaceComponent::_TypeUID);
          else
            m_pComponent = UFG::SimObject::GetComponentOfType(m_SimObj, UFG::RoadSpaceComponent::_TypeUID);
        }
        else
        {
          m_pComponent = m_SimObj->m_Components.p[24].m_pComponent;
        }
        if ( m_pComponent )
        {
          mNext = (unsigned int)m_pComponent[30].m_SafePointerList.mNode.mNext;
          this->m_LaneFlags = mNext;
          if ( (mNext & 1) != 0 )
            this->m_LaneFlags = mNext | 0x20;
        }
      }
    }
  }
}

// File Line: 144
// RVA: 0x6582B0
void __fastcall UFG::VehicleWayFinderClient::ResetWay(UFG::VehicleWayFinderClient *this)
{
  UFG::WayFinderClient::ResetWay(this);
  UFG::VehicleWayFinderClient::SetLaneFlagsFromGuide(this, this->m_RoadGuide);
}

