// File Line: 13
// RVA: 0xE33D50
void __fastcall hkAlignSceneToNodeOptions::hkAlignSceneToNodeOptions(hkAlignSceneToNodeOptions *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkAlignSceneToNodeOptions::`vftable;
  hkStringPtr::hkStringPtr(&this->m_nodeName);
}

// File Line: 18
// RVA: 0xE33D90
void __fastcall hkAlignSceneToNodeOptions::hkAlignSceneToNodeOptions(
        hkAlignSceneToNodeOptions *this,
        hkFinishLoadedObjectFlag f)
{
  hkStringPtr *p_m_nodeName; // rcx

  p_m_nodeName = &this->m_nodeName;
  p_m_nodeName[-4].m_stringAndFlag = (const char *)&hkAlignSceneToNodeOptions::`vftable;
  hkStringPtr::hkStringPtr(p_m_nodeName, f);
}

// File Line: 22
// RVA: 0xE33DD0
hkStringPtr *__fastcall hkAlignSceneToNodeOptions::getNodeName(hkAlignSceneToNodeOptions *this)
{
  return &this->m_nodeName;
}

// File Line: 27
// RVA: 0xE33DC0
void __fastcall hkAlignSceneToNodeOptions::setNodeName(hkAlignSceneToNodeOptions *this, const char *name)
{
  hkStringPtr::operator=(&this->m_nodeName, name);
}

