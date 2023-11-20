// File Line: 57
// RVA: 0xCED800
void __fastcall hkpAgentRegisterUtil::_registerBvTreeAgents(hkpCollisionDispatcher *dis)
{
  hkpCollisionDispatcher *v1; // rbx

  v1 = dis;
  hkpCollisionDispatcher::setEnableChecks(dis, 0);
  hkpBvTreeAgent::registerAgent(v1);
  hkpMoppAgent::registerAgent(v1);
  hkpBvTreeStreamAgent::registerAgent(v1);
  hkpMoppBvTreeStreamAgent::registerAgent(v1);
  hkpBvCompressedMeshAgent::registerAgent(v1);
  hkpStaticCompoundAgent::registerAgent(v1);
  hkBvTreeAgent3::registerAgent3(v1);
  hkpCollisionDispatcher::setEnableChecks(v1, (hkBool)1);
}

// File Line: 88
// RVA: 0xCED8F0
void __fastcall hkpAgentRegisterUtil::_registerListAgents(hkpCollisionDispatcher *dis)
{
  hkpCollisionDispatcher *v1; // rbx

  v1 = dis;
  hkpListAgent::registerAgent(dis);
  hkpCollisionDispatcher::setEnableChecks(v1, 0);
  hkpCollectionAgent3::registerAgent3(v1);
  hkpCollectionCollectionAgent3::registerAgent3(v1);
  hkpCollisionDispatcher::setEnableChecks(v1, (hkBool)1);
  hkpConvexListAgent::registerAgent(v1);
  hkConvexListAgent3::registerAgent3(v1);
  if ( hkpCollisionAgent::registerHeightFieldAgent )
    hkpCollisionAgent::registerHeightFieldAgent(v1);
}

// File Line: 122
// RVA: 0xCED860
void __fastcall hkpAgentRegisterUtil::_registerTerminalAgents(hkpCollisionDispatcher *dis)
{
  hkpCollisionDispatcher *v1; // rbx

  v1 = dis;
  hkpPredGskfAgent::registerAgent(dis);
  hkPredGskAgent3::registerAgent3(v1, CONVEX, CONVEX);
  hkPredGskCylinderAgent3::registerAgent3(v1);
  hkpBoxBoxAgent::registerAgent(v1);
  hkBoxBoxAgent3::registerAgent3(v1);
  hkpSphereSphereAgent::registerAgent(v1);
  hkpSphereCapsuleAgent::registerAgent(v1);
  hkpSphereTriangleAgent::registerAgent2(v1);
  hkpSphereBoxAgent::registerAgent(v1);
  hkpCapsuleCapsuleAgent::registerAgent(v1);
  hkpCapsuleTriangleAgent::registerAgent(v1);
  hkCapsuleTriangleAgent3::registerAgent3(v1);
  hkpMultiSphereTriangleAgent::registerAgent(v1);
}

// File Line: 178
// RVA: 0xCED790
void __fastcall hkpAgentRegisterUtil::registerAllAgents(hkpCollisionDispatcher *dis)
{
  hkpCollisionDispatcher *v1; // rbx

  v1 = dis;
  hkpRegisterAlternateShapeTypes(dis);
  hkpBvAgent::registerAgent(v1);
  hkpMultiSphereAgent::registerAgent(v1);
  hkpAgentRegisterUtil::_registerBvTreeAgents(v1);
  hkpCollisionDispatcher::setEnableChecks(v1, 0);
  hkpShapeCollectionAgent::registerAgent(v1);
  hkpCollisionDispatcher::setEnableChecks(v1, (hkBool)1);
  hkpAgentRegisterUtil::_registerListAgents(v1);
  hkpTransformAgent::registerAgent(v1);
  hkpPhantomAgent::registerAgent(v1);
  hkpAgentRegisterUtil::_registerTerminalAgents(v1);
}

