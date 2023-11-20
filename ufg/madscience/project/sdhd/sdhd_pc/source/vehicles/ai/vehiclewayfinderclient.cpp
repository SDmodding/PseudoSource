// File Line: 21
// RVA: 0x643320
void __fastcall UFG::VehicleWayFinderClient::VehicleWayFinderClient(UFG::VehicleWayFinderClient *this, UFG::RoadNetworkGuide *guide, unsigned int laneFlags)
{
  unsigned int v3; // ebx
  UFG::RoadNetworkGuide *v4; // rdi
  UFG::VehicleWayFinderClient *v5; // rsi

  v3 = laneFlags;
  v4 = guide;
  v5 = this;
  UFG::WayFinderClient::WayFinderClient((UFG::WayFinderClient *)&this->vfptr);
  v5->vfptr = (UFG::WayFinderClientVtbl *)&UFG::VehicleWayFinderClient::`vftable';
  v5->m_RoadNetworkType = 0;
  v5->m_LaneFlags = v3;
  v5->m_RoadGuide = v4;
  v5->m_AllowFootPaths = 0;
  UFG::VehicleWayFinderClient::SetLaneFlagsFromGuide(v5, v4);
}

// File Line: 26
// RVA: 0x647A70
bool __fastcall UFG::VehicleWayFinderClient::CanTurnAround(UFG::VehicleWayFinderClient *this)
{
  UFG::RoadNetworkGuide *v1; // rcx
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::AiDriverComponent *v4; // rax
  bool result; // al

  v1 = this->m_RoadGuide;
  if ( v1
    && (v2 = (UFG::SimObjectCVBase *)v1->m_SimObj) != 0i64
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v4 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v4 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2)),
        v4) )
  {
    result = v4->m_bCanTurnAround;
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 37
// RVA: 0x651220
__int64 __fastcall UFG::VehicleWayFinderClient::GetWayEdge(UFG::VehicleWayFinderClient *this, UFG::WayGraph *graph)
{
  UFG::VehicleWayFinderClient *v2; // rax
  UFG::RoadNetworkGuide *v3; // rcx
  UFG::WayGraph *v4; // rbx
  UFG::RoadNetworkLocation *v5; // rax
  UFG::RoadNetworkNode *v6; // rdi
  __int64 result; // rax

  v2 = this;
  v3 = this->m_RoadGuide;
  v4 = graph;
  if ( !v3 || !v3->m_Attached )
    return v2->m_CurrWayEdge;
  v5 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v3);
  v6 = UFG::RoadNetworkLocation::GetRoadNetworkNode(v5);
  if ( v6->mType.mValue == 1 )
    result = v4->vfptr->GetNumEdges(v4) + v6->mIndex;
  else
    result = v6->mIndex;
  return result;
}

// File Line: 51
// RVA: 0x6512A0
signed __int64 __fastcall UFG::VehicleWayFinderClient::GetWayNode(UFG::VehicleWayFinderClient *this, UFG::WayGraph *graph)
{
  UFG::VehicleWayFinderClient *v2; // rax
  UFG::RoadNetworkGuide *v3; // rcx
  UFG::WayGraph *v4; // rdi
  UFG::RoadNetworkConnection *v5; // rax
  __int64 v7; // rdx
  int v8; // ecx
  _QWORD *v9; // rax
  char *v10; // rbx

  v2 = this;
  v3 = this->m_RoadGuide;
  v4 = graph;
  if ( !v3 || !v3->m_Attached )
    return v2->m_CurrWayNode;
  v5 = UFG::RoadNetworkGuide::GetNextConnection(v3);
  if ( !v5 )
    return 0xFFFFi64;
  v7 = v5->mGate.mOffset;
  v8 = 0;
  if ( v7 )
    v9 = (__int64 *)((char *)&v5->mGate.mOffset + v7);
  else
    v9 = 0i64;
  v10 = (char *)v9 + *v9;
  if ( !*v9 )
    v10 = 0i64;
  if ( *(_WORD *)v10 == 1 )
    v8 = v4->vfptr->GetNumEdges(v4);
  return (unsigned int)(v8 + *((_DWORD *)v10 + 6));
}

// File Line: 64
// RVA: 0x64EF40
UFG::qVector3 *__fastcall UFG::VehicleWayFinderClient::GetPosition(UFG::VehicleWayFinderClient *this, UFG::qVector3 *result)
{
  UFG::RoadNetworkGuide *v2; // rax
  UFG::qVector3 *v3; // rbx
  UFG::RoadNetworkLocation *v4; // rax
  UFG::qVector3 *v5; // rax
  float v6; // xmm0_4
  float v7; // xmm1_4

  v2 = this->m_RoadGuide;
  v3 = result;
  if ( v2 && v2->m_Attached )
  {
    v4 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(this->m_RoadGuide);
    UFG::RoadNetworkLocation::GetPos(v4, v3);
    v5 = v3;
  }
  else
  {
    v6 = this->m_CurrPos.y;
    v7 = this->m_CurrPos.z;
    result->x = this->m_CurrPos.x;
    v5 = result;
    result->y = v6;
    result->z = v7;
  }
  return v5;
}

// File Line: 72
// RVA: 0x64DA50
UFG::qVector3 *__fastcall UFG::VehicleWayFinderClient::GetDirection(UFG::VehicleWayFinderClient *this, UFG::qVector3 *result)
{
  UFG::RoadNetworkGuide *v2; // rax
  UFG::qVector3 *v3; // rbx
  UFG::RoadNetworkLocation *v4; // rax
  UFG::qVector3 *v5; // rax
  float v6; // xmm0_4
  float v7; // xmm1_4

  v2 = this->m_RoadGuide;
  v3 = result;
  if ( v2 && v2->m_Attached )
  {
    v4 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(this->m_RoadGuide);
    UFG::RoadNetworkLocation::GetTangent(v4, v3);
    v5 = v3;
  }
  else
  {
    v6 = this->m_CurrDir.y;
    v7 = this->m_CurrDir.z;
    result->x = this->m_CurrDir.x;
    v5 = result;
    result->y = v6;
    result->z = v7;
  }
  return v5;
}

// File Line: 80
// RVA: 0x647990
bool __fastcall UFG::VehicleWayFinderClient::CanGo(UFG::VehicleWayFinderClient *this, UFG::WayGraph *graph, unsigned __int16 from_edge, unsigned __int16 to_edge, unsigned __int16 thru_node)
{
  UFG::RoadNetworkGraph *v5; // rdi
  UFG::VehicleWayFinderClient *v6; // rsi
  unsigned __int16 v7; // bp
  unsigned __int16 v8; // r15
  bool result; // al
  UFG::RoadNetworkResource *v10; // rbx
  UFG::RoadNetworkSegment *v11; // r14
  UFG::RoadNetworkSegment *v12; // rax

  v5 = (UFG::RoadNetworkGraph *)graph;
  v6 = this;
  v7 = to_edge;
  v8 = from_edge;
  if ( graph->vfptr->IsEdge(graph, thru_node)
    || v7 == v6->vfptr->GetWayEdge((UFG::WayFinderClient *)&v6->vfptr, (UFG::WayGraph *)&v5->vfptr) )
  {
    return 1;
  }
  v10 = v5->pRoadNetworkResource;
  v11 = UFG::RoadNetworkResource::GetSegment(v5->pRoadNetworkResource, v7);
  v12 = UFG::RoadNetworkResource::GetSegment(v10, v8);
  if ( v6->m_AllowFootPaths || (*(_DWORD *)&v12->mBits >> 1) & 1 || !((*(_DWORD *)&v11->mBits >> 1) & 1) )
    result = UFG::RoadNetworkGraph::GetNumLanesFromToThru(v5, v8, v7, thru_node, v6->m_LaneFlags) > 0;
  else
    result = 0;
  return result;
}

// File Line: 105
// RVA: 0x659900
void __fastcall UFG::VehicleWayFinderClient::SetRoadNetworkType(UFG::VehicleWayFinderClient *this, unsigned int type)
{
  this->m_RoadNetworkType = type;
}

// File Line: 119
// RVA: 0x6594F0
void __fastcall UFG::VehicleWayFinderClient::SetLaneFlagsFromGuide(UFG::VehicleWayFinderClient *this, UFG::RoadNetworkGuide *guide)
{
  UFG::VehicleWayFinderClient *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  unsigned int v6; // ecx

  if ( guide )
  {
    v2 = this;
    if ( guide->m_Attached )
    {
      v3 = (UFG::SimObjectGame *)guide->m_SimObj;
      if ( v3 )
      {
        v4 = v3->m_Flags;
        if ( (v4 >> 14) & 1 )
        {
          v5 = v3->m_Components.p[24].m_pComponent;
        }
        else if ( (v4 & 0x8000u) == 0 )
        {
          if ( (v4 >> 13) & 1 )
          {
            v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID);
          }
          else if ( (v4 >> 12) & 1 )
          {
            v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID);
          }
          else
          {
            v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RoadSpaceComponent::_TypeUID);
          }
        }
        else
        {
          v5 = v3->m_Components.p[24].m_pComponent;
        }
        if ( v5 )
        {
          v6 = (unsigned int)v5[30].m_SafePointerList.mNode.mNext;
          v2->m_LaneFlags = v6;
          if ( v6 & 1 )
            v2->m_LaneFlags = v6 | 0x20;
        }
      }
    }
  }
}

// File Line: 144
// RVA: 0x6582B0
void __fastcall UFG::VehicleWayFinderClient::ResetWay(UFG::VehicleWayFinderClient *this)
{
  UFG::VehicleWayFinderClient *v1; // rbx

  v1 = this;
  UFG::WayFinderClient::ResetWay((UFG::WayFinderClient *)&this->vfptr);
  UFG::VehicleWayFinderClient::SetLaneFlagsFromGuide(v1, v1->m_RoadGuide);
}

