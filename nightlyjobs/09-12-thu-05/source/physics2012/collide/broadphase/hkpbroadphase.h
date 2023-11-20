// File Line: 87
// RVA: 0xD071E0
hkpBroadPhase *__fastcall hkpBroadPhase::getCapabilityDelegate(hkpBroadPhase *this, hkpBroadPhase::Capabilities cap)
{
  hkpBroadPhase *result; // rax

  result = 0i64;
  if ( cap & this->m_caps )
    result = this;
  return result;
}

