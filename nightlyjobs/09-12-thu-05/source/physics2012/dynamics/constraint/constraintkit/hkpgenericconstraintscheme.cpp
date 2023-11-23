// File Line: 15
// RVA: 0xD77250
void __fastcall hkpGenericConstraintDataScheme::hkpGenericConstraintDataScheme(
        hkpGenericConstraintDataScheme *this,
        hkFinishLoadedObjectFlag f)
{
  hkArray<int,hkContainerHeapAllocator> *p_m_commands; // rcx

  if ( f.m_finishing )
  {
    this->m_info.m_sizeOfSchemas = 32;
    p_m_commands = &this->m_commands;
    LODWORD(p_m_commands[-2].m_data) = 0;
    *(_QWORD *)&p_m_commands[-2].m_size = 0i64;
    hkpConstraintConstructionKit::computeConstraintInfo(p_m_commands, &this->m_info);
    this->m_info.m_maxSizeOfSchema = this->m_info.m_sizeOfSchemas;
  }
}

