// File Line: 41
// RVA: 0xB1DD00
void __fastcall hkaReferencePoseAnimation::setSkeleton(hkaReferencePoseAnimation *this, hkaSkeleton *skeleton)
{
  hkaSkeleton *m_pntr; // rcx

  if ( skeleton )
    hkReferencedObject::addReference(skeleton);
  m_pntr = this->m_skeleton.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_skeleton.m_pntr = skeleton;
}

