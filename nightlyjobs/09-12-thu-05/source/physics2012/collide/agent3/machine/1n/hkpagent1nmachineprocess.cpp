// File Line: 64
// RVA: 0xD3ED70
void __fastcall fixupPotentialContactPointers(
        char *extensionBuffer,
        _BYTE *dst,
        int bytesUsedInExtensionBuffer,
        hkpProcessCollisionOutput::PotentialInfo *potentialInfo)
{
  hkpProcessCollisionOutput::ContactRef *i; // rax
  __int64 v6; // r9

  if ( potentialInfo )
  {
    for ( i = potentialInfo->m_potentialContacts; i < potentialInfo->m_firstFreePotentialContact; ++i )
    {
      v6 = (char *)i->m_agentEntry - extensionBuffer;
      if ( v6 >= 0 && v6 < bytesUsedInExtensionBuffer )
      {
        i->m_agentEntry = (hkpAgentEntry *)&dst[v6];
        i->m_agentData = (char *)i->m_agentData + dst - extensionBuffer;
      }
    }
  }
}

