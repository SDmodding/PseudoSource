// File Line: 19
// RVA: 0xC37740
void __fastcall hkaiTraversalAnalysisSettings::hkaiTraversalAnalysisSettings(hkaiTraversalAnalysisSettings *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiTraversalAnalysisSettings::`vftable;
  this->m_minEdgeLength = 0.1;
  this->m_maxSectionDistance = 5.0;
  this->m_up.m_quad = _xmm;
  this->m_characterHeight = 2.0;
  this->m_characterRadius = 0.2;
  this->m_raiseEdgeHeightLimit = 0.25;
}

// File Line: 25
// RVA: 0xC37790
void __fastcall hkaiTraversalAnalysisSettings::hkaiTraversalAnalysisSettings(
        hkaiTraversalAnalysisSettings *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiTraversalAnalysisSettings::`vftable;
}

// File Line: 30
// RVA: 0xC377B0
void __fastcall hkaiTraversalAnalysisSettings::~hkaiTraversalAnalysisSettings(hkaiTraversalAnalysisSettings *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

