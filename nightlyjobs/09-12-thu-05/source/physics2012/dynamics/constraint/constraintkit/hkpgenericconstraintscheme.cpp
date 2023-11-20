// File Line: 15
// RVA: 0xD77250
void __fastcall hkpGenericConstraintDataScheme::hkpGenericConstraintDataScheme(hkpGenericConstraintDataScheme *this, hkFinishLoadedObjectFlag f)
{
  hkpGenericConstraintDataScheme *v2; // rbx
  hkArray<int,hkContainerHeapAllocator> *v3; // rcx

  v2 = this;
  if ( f.m_finishing )
  {
    this->m_info.m_sizeOfSchemas = 32;
    v3 = &this->m_commands;
    LODWORD(v3[-2].m_data) = 0;
    *(_QWORD *)&v3[-2].m_size = 0i64;
    hkpConstraintConstructionKit::computeConstraintInfo(v3, &v2->m_info);
    v2->m_info.m_maxSizeOfSchema = v2->m_info.m_sizeOfSchemas;
  }
}

