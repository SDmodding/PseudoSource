// File Line: 57
// RVA: 0xCED800
void __fastcall hkpAgentRegisterUtil::_registerBvTreeAgents(hkpCollisionDispatcher *dis)
{
  hkpCollisionDispatcher::setEnableChecks(dis, 0);
  hkpBvTreeAgent::registerAgent(dis);
  hkpMoppAgent::registerAgent(dis);
  hkpBvTreeStreamAgent::registerAgent(dis);
  hkpMoppBvTreeStreamAgent::registerAgent(dis);
  hkpBvCompressedMeshAgent::registerAgent(dis);
  hkpStaticCompoundAgent::registerAgent(dis);
  hkBvTreeAgent3::registerAgent3(dis);
  hkpCollisionDispatcher::setEnableChecks(dis, (hkBool)1);
}

// File Line: 88
// RVA: 0xCED8F0
void __fastcall hkpAgentRegisterUtil::_registerListAgents(hkpCollisionDispatcher *dis)
{
  hkpListAgent::registerAgent(dis);
  hkpCollisionDispatcher::setEnableChecks(dis, 0);
  hkpCollectionAgent3::registerAgent3(dis);
  hkpCollectionCollectionAgent3::registerAgent3(dis);
  hkpCollisionDispatcher::setEnableChecks(dis, (hkBool)1);
  hkpConvexListAgent::registerAgent(dis);
  hkConvexListAgent3::registerAgent3(dis);
  if ( hkpCollisionAgent::registerHeightFieldAgent )
    hkpCollisionAgent::registerHeightFieldAgent(dis);
}

// File Line: 122
// RVA: 0xCED860
void __fastcall hkpAgentRegisterUtil::_registerTerminalAgents(hkpCollisionDispatcher *dis)
{
  hkpPredGskfAgent::registerAgent(dis);
  hkPredGskAgent3::registerAgent3(dis, CONVEX, CONVEX);
  hkPredGskCylinderAgent3::registerAgent3(dis);
  hkpBoxBoxAgent::registerAgent(dis);
  hkBoxBoxAgent3::registerAgent3(dis);
  hkpSphereSphereAgent::registerAgent(dis);
  hkpSphereCapsuleAgent::registerAgent(dis);
  hkpSphereTriangleAgent::registerAgent2(dis);
  hkpSphereBoxAgent::registerAgent(dis);
  hkpCapsuleCapsuleAgent::registerAgent(dis);
  hkpCapsuleTriangleAgent::registerAgent(dis);
  hkCapsuleTriangleAgent3::registerAgent3(dis);
  hkpMultiSphereTriangleAgent::registerAgent(dis);
}

// File Line: 178
// RVA: 0xCED790
void __fastcall hkpAgentRegisterUtil::registerAllAgents(hkpCollisionDispatcher *dis)
{
  hkpRegisterAlternateShapeTypes(dis);
  hkpBvAgent::registerAgent(dis);
  hkpMultiSphereAgent::registerAgent(dis);
  hkpAgentRegisterUtil::_registerBvTreeAgents(dis);
  hkpCollisionDispatcher::setEnableChecks(dis, 0);
  hkpShapeCollectionAgent::registerAgent(dis);
  hkpCollisionDispatcher::setEnableChecks(dis, (hkBool)1);
  hkpAgentRegisterUtil::_registerListAgents(dis);
  hkpTransformAgent::registerAgent(dis);
  hkpPhantomAgent::registerAgent(dis);
  hkpAgentRegisterUtil::_registerTerminalAgents(dis);
}

