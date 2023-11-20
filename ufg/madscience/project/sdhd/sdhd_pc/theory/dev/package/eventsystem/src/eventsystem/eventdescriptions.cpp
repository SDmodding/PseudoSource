// File Line: 14
// RVA: 0x146A8D0
__int64 dynamic_initializer_for__UFG::TeleportEvent::EVENT_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32(UFG::TeleportEvent::m_Name, 0xFFFFFFFF);
  UFG::TeleportEvent::EVENT_UID = result;
  return result;
}

