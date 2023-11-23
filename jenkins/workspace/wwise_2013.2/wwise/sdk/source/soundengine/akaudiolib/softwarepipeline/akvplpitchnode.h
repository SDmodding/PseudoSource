// File Line: 31
// RVA: 0xA65070
void __fastcall CAkVPLPitchNode::CAkVPLPitchNode(CAkVPLPitchNode *this, CAkVPLSrcCbxNode *in_pCbx)
{
  this->vfptr = (CAkVPLNodeVtbl *)&CAkVPLPitchNode::`vftable;
  this->m_pInput = 0i64;
  Assembly::GetRCX(&this->m_Pitch);
  this->m_pCbx = in_pCbx;
  this->m_pPBI = 0i64;
  this->m_BufferIn.pData = 0i64;
  this->m_BufferIn.uNumMarkers = 0;
  this->m_BufferIn.pMarkers = 0i64;
  *(_QWORD *)&this->m_BufferIn.eState = 43i64;
  this->m_BufferIn.posInfo.uStartPos = -1;
  this->m_BufferIn.posInfo.fLastRate = 1.0;
  this->m_BufferIn.posInfo.uFileEnd = -1;
  this->m_BufferIn.posInfo.uSampleRate = 1;
  this->m_BufferOut.pData = 0i64;
  this->m_BufferOut.uNumMarkers = 0;
  this->m_BufferOut.pMarkers = 0i64;
  *(_QWORD *)&this->m_BufferOut.eState = 43i64;
  this->m_BufferOut.posInfo.uStartPos = -1;
  this->m_BufferOut.posInfo.fLastRate = 1.0;
  this->m_BufferOut.posInfo.uFileEnd = -1;
  this->m_BufferOut.posInfo.uSampleRate = 1;
}

