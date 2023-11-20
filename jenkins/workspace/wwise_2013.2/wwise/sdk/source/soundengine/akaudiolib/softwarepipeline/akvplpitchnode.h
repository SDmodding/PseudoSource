// File Line: 31
// RVA: 0xA65070
void __fastcall CAkVPLPitchNode::CAkVPLPitchNode(CAkVPLPitchNode *this, CAkVPLSrcCbxNode *in_pCbx)
{
  CAkVPLPitchNode *v2; // rdi
  CAkVPLSrcCbxNode *v3; // rbx

  v2 = this;
  this->vfptr = (CAkVPLNodeVtbl *)&CAkVPLPitchNode::`vftable;
  this->m_pInput = 0i64;
  v3 = in_pCbx;
  Assembly::GetRCX(&this->m_Pitch);
  v2->m_pCbx = v3;
  v2->m_pPBI = 0i64;
  v2->m_BufferIn.pData = 0i64;
  v2->m_BufferIn.uNumMarkers = 0;
  v2->m_BufferIn.pMarkers = 0i64;
  *(_QWORD *)&v2->m_BufferIn.eState = 43i64;
  v2->m_BufferIn.posInfo.uStartPos = -1;
  v2->m_BufferIn.posInfo.fLastRate = 1.0;
  v2->m_BufferIn.posInfo.uFileEnd = -1;
  v2->m_BufferIn.posInfo.uSampleRate = 1;
  v2->m_BufferOut.pData = 0i64;
  v2->m_BufferOut.uNumMarkers = 0;
  v2->m_BufferOut.pMarkers = 0i64;
  *(_QWORD *)&v2->m_BufferOut.eState = 43i64;
  v2->m_BufferOut.posInfo.uStartPos = -1;
  v2->m_BufferOut.posInfo.fLastRate = 1.0;
  v2->m_BufferOut.posInfo.uFileEnd = -1;
  v2->m_BufferOut.posInfo.uSampleRate = 1;
}

