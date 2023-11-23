// File Line: 41
// RVA: 0xA91D80
void __fastcall CAkVPLNode::Disconnect(CAkVPLNode *this)
{
  this->m_pInput = 0i64;
}

// File Line: 51
// RVA: 0xA91C30
void __fastcall CAkVPLNode::CopyRelevantMarkers(
        AkPipelineBuffer *in_pInputBuffer,
        AkPipelineBuffer *io_pBuffer,
        unsigned int in_ulBufferStartOffset,
        unsigned int in_ulNumFrames)
{
  AkBufferMarker *pMarkers; // rcx
  unsigned __int16 v9; // di
  unsigned int *p_dwPositionInBuffer; // rcx
  __int64 uNumMarkers; // r8
  AkBufferMarker *v12; // rax
  AkBufferMarker *v13; // r15
  AkBufferMarker *v14; // rdx
  AkBufferMarker *v15; // rcx
  unsigned int v16; // r8d
  AkBufferMarker *v17; // r10
  AkAudioMarker *p_marker; // r9
  unsigned int dwPositionInBuffer; // edx
  CAkPBI *pContext; // rax

  pMarkers = in_pInputBuffer->pMarkers;
  if ( pMarkers )
  {
    v9 = 0;
    if ( in_pInputBuffer->uNumMarkers )
    {
      p_dwPositionInBuffer = &pMarkers->dwPositionInBuffer;
      uNumMarkers = in_pInputBuffer->uNumMarkers;
      do
      {
        if ( *p_dwPositionInBuffer >= in_ulBufferStartOffset
          && *p_dwPositionInBuffer < in_ulBufferStartOffset + in_ulNumFrames )
        {
          ++v9;
        }
        p_dwPositionInBuffer += 8;
        --uNumMarkers;
      }
      while ( uNumMarkers );
      if ( v9 )
      {
        v12 = (AkBufferMarker *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 32i64 * (io_pBuffer->uNumMarkers + v9));
        v13 = v12;
        if ( v12 )
        {
          v14 = io_pBuffer->pMarkers;
          if ( v14 )
            memmove(v12, v14, 32 * (unsigned int)io_pBuffer->uNumMarkers);
          v15 = in_pInputBuffer->pMarkers;
          v16 = 0;
          v17 = &v13[io_pBuffer->uNumMarkers];
          if ( in_pInputBuffer->uNumMarkers )
          {
            p_marker = &v17->marker;
            do
            {
              dwPositionInBuffer = v15->dwPositionInBuffer;
              if ( dwPositionInBuffer >= in_ulBufferStartOffset
                && dwPositionInBuffer < in_ulBufferStartOffset + in_ulNumFrames )
              {
                pContext = v15->pContext;
                LODWORD(p_marker[-1].strLabel) = 0;
                ++v17;
                v17[-1].pContext = pContext;
                p_marker += 2;
                *(_QWORD *)&p_marker[-2].dwIdentifier = *(_QWORD *)&v15->marker.dwIdentifier;
                p_marker[-2].strLabel = v15->marker.strLabel;
              }
              ++v16;
              ++v15;
            }
            while ( v16 < in_pInputBuffer->uNumMarkers );
          }
          AkPipelineBuffer::FreeMarkers(io_pBuffer);
          io_pBuffer->uNumMarkers += v9;
          io_pBuffer->pMarkers = v13;
        }
        else
        {
          AkPipelineBuffer::FreeMarkers(io_pBuffer);
        }
      }
    }
  }
}

