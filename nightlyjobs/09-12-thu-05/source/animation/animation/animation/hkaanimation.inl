// File Line: 78
// RVA: 0xB1D860
void __usercall hkaAnimation::getExtractedMotionReferenceFrame(hkaAnimation *this@<rcx>, float time@<xmm1>, hkQsTransformf *motionOut@<r8>, __int64 a4@<rdx>)
{
  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, __int64, hkQsTransformf *))this->m_extractedMotion.m_pntr->vfptr[1].__first_virtual_table_function__)(
    this->m_extractedMotion.m_pntr,
    a4,
    motionOut);
}

// File Line: 83
// RVA: 0xB1D850
void __usercall hkaAnimation::getExtractedMotionDeltaReferenceFrame(hkaAnimation *this@<rcx>, float time@<xmm1>, float nextTime@<xmm2>, __int64 loops@<r9>, __int64 a5@<r8>, hkQsTransformf *deltaMotionOut, float cropStartAmount, float cropEndAmount)
{
  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, hkBaseObjectVtbl *, __int64, __int64))this->m_extractedMotion.m_pntr->vfptr[2].__vecDelDtor)(
    this->m_extractedMotion.m_pntr,
    this->m_extractedMotion.m_pntr->vfptr,
    a5,
    loops);
}

