// File Line: 41
// RVA: 0xB1DD00
void __fastcall hkaReferencePoseAnimation::setSkeleton(hkaReferencePoseAnimation *this, hkaSkeleton *skeleton)
{
  hkaSkeleton *v2; // rbx
  hkaReferencePoseAnimation *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = skeleton;
  v3 = this;
  if ( skeleton )
    hkReferencedObject::addReference((hkReferencedObject *)&skeleton->vfptr);
  v4 = (hkReferencedObject *)&v3->m_skeleton.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_skeleton.m_pntr = v2;
}

