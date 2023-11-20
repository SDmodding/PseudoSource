// File Line: 41
// RVA: 0xA91D80
void __fastcall CAkVPLNode::Disconnect(CAkVPLNode *this)
{
  this->m_pInput = 0i64;
}

// File Line: 51
// RVA: 0xA91C30
void __fastcall CAkVPLNode::CopyRelevantMarkers(AkPipelineBuffer *in_pInputBuffer, AkPipelineBuffer *io_pBuffer, unsigned int in_ulBufferStartOffset, unsigned int in_ulNumFrames)
{
  AkPipelineBuffer *v4; // r14
  AkBufferMarker *v5; // rcx
  unsigned int v6; // ebp
  unsigned int v7; // ebx
  AkPipelineBuffer *v8; // rsi
  unsigned __int16 v9; // di
  unsigned int *v10; // rcx
  __int64 v11; // r8
  AkBufferMarker *v12; // rax
  AkBufferMarker *v13; // r15
  AkBufferMarker *v14; // rdx
  AkBufferMarker *v15; // rcx
  unsigned int v16; // er8
  signed __int64 v17; // r10
  signed __int64 v18; // r9
  unsigned int v19; // edx
  CAkPBI *v20; // rax

  v4 = in_pInputBuffer;
  v5 = in_pInputBuffer->pMarkers;
  v6 = in_ulNumFrames;
  v7 = in_ulBufferStartOffset;
  v8 = io_pBuffer;
  if ( v5 )
  {
    v9 = 0;
    if ( v4->uNumMarkers )
    {
      v10 = &v5->dwPositionInBuffer;
      v11 = v4->uNumMarkers;
      do
      {
        if ( *v10 >= v7 && *v10 < v7 + in_ulNumFrames )
          ++v9;
        v10 += 8;
        --v11;
      }
      while ( v11 );
      if ( v9 )
      {
        v12 = (AkBufferMarker *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 32i64 * (io_pBuffer->uNumMarkers + v9));
        v13 = v12;
        if ( v12 )
        {
          v14 = v8->pMarkers;
          if ( v14 )
            memmove(v12, v14, 32 * (unsigned int)v8->uNumMarkers);
          v15 = v4->pMarkers;
          v16 = 0;
          v17 = (signed __int64)&v13[v8->uNumMarkers];
          if ( v4->uNumMarkers > 0u )
          {
            v18 = v17 + 16;
            do
            {
              v19 = v15->dwPositionInBuffer;
              if ( v19 >= v7 && v19 < v7 + v6 )
              {
                v20 = v15->pContext;
                *(_DWORD *)(v18 - 8) = 0;
                v17 += 32i64;
                *(_QWORD *)(v17 - 32) = v20;
                v18 += 32i64;
                *(_QWORD *)(v18 - 32) = *(_QWORD *)&v15->marker.dwIdentifier;
                *(_QWORD *)(v18 - 24) = v15->marker.strLabel;
              }
              ++v16;
              ++v15;
            }
            while ( v16 < v4->uNumMarkers );
          }
          AkPipelineBuffer::FreeMarkers(v8);
          v8->uNumMarkers += v9;
          v8->pMarkers = v13;
        }
        else
        {
          AkPipelineBuffer::FreeMarkers(v8);
        }
      }
    }
  }
}

