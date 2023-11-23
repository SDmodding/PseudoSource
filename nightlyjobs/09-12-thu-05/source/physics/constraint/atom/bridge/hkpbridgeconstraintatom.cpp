// File Line: 15
// RVA: 0xD4D3B0
void __fastcall hkBridgeConstraintAtom_callData(
        hkpConstraintData *m_constraintData,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  ((void (__fastcall *)(hkpConstraintData *, hkpConstraintQueryIn *, hkpConstraintQueryOut *))m_constraintData->vfptr[10].__vecDelDtor)(
    m_constraintData,
    in,
    out);
}

// File Line: 20
// RVA: 0xD4D390
void __fastcall hkpBridgeConstraintAtom::init(hkpBridgeConstraintAtom *this, hkpConstraintData *constraintData)
{
  this->m_constraintData = constraintData;
  this->m_buildJacobianFunc = hkBridgeConstraintAtom_callData;
}

