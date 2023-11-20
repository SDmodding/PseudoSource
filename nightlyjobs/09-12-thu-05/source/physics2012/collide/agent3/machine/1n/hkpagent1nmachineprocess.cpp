// File Line: 64
// RVA: 0xD3ED70
void __fastcall fixupPotentialContactPointers(const char *extensionBuffer, void *dst, int bytesUsedInExtensionBuffer, hkpProcessCollisionOutput::PotentialInfo *potentialInfo)
{
  hkpProcessCollisionOutput::PotentialInfo *v4; // r10
  hkpProcessCollisionOutput::ContactRef *v5; // rax
  signed __int64 v6; // r9

  v4 = potentialInfo;
  if ( potentialInfo )
  {
    v5 = potentialInfo->m_potentialContacts;
    if ( potentialInfo->m_potentialContacts < potentialInfo->m_firstFreePotentialContact )
    {
      do
      {
        v6 = (char *)v5->m_agentEntry - (char *)extensionBuffer;
        if ( v6 >= 0 && v6 < bytesUsedInExtensionBuffer )
        {
          v5->m_agentEntry = (hkpAgentEntry *)((char *)dst + v6);
          v5->m_agentData = (char *)v5->m_agentData + (_BYTE *)dst - extensionBuffer;
        }
        ++v5;
      }
      while ( v5 < v4->m_firstFreePotentialContact );
    }
  }
}

