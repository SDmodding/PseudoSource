// File Line: 30
// RVA: 0xD1E020
void __fastcall hkpMoppBvTreeStreamAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = (hkpCollisionAgent *(__fastcall *)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *))hkpBvTreeStreamAgent::createBvTreeShapeAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, MOPP, CONVEX);
  f.m_createFunc = (hkpCollisionAgent *(__fastcall *)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *))hkpBvTreeStreamAgent::createShapeBvAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpMoppAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CONVEX, MOPP);
  f.m_createFunc = hkpMoppAgent::createBvBvAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpMoppAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, MOPP, MOPP);
}

