// File Line: 18
// RVA: 0xD7B430
void __fastcall hkpSimpleContactConstraintAtom::hkpSimpleContactConstraintAtom(
        hkpSimpleContactConstraintAtom *this,
        hkFinishLoadedObjectFlag f)
{
  if ( f.m_finishing )
    this->m_contactPointPropertiesStriding = 4 * (this->m_numUserDatasForBodyA + this->m_numUserDatasForBodyB + 8);
}

