// File Line: 78
// RVA: 0xB1D860
void __fastcall hkaAnimation::getExtractedMotionReferenceFrame(
        hkaAnimation *this,
        float time,
        hkQsTransformf *motionOut)
{
  __int64 v3; // rdx

  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, __int64, hkQsTransformf *))this->m_extractedMotion.m_pntr->vfptr[1].__first_virtual_table_function__)(
    this->m_extractedMotion.m_pntr,
    v3,
    motionOut);
}

// File Line: 83
// RVA: 0xB1D850
void __fastcall hkaAnimation::getExtractedMotionDeltaReferenceFrame(
        hkaAnimation *this,
        float time,
        float nextTime,
        __int64 loops,
        hkQsTransformf *deltaMotionOut,
        float cropStartAmount,
        float cropEndAmount)
{
  __int64 v7; // r8

  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, hkBaseObjectVtbl *, __int64, __int64))this->m_extractedMotion.m_pntr->vfptr[2].__vecDelDtor)(
    this->m_extractedMotion.m_pntr,
    this->m_extractedMotion.m_pntr->vfptr,
    v7,
    loops);
}

