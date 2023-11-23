// File Line: 41
// RVA: 0xA92C90
void __fastcall CAkGen3DParams::CAkGen3DParams(CAkGen3DParams *this)
{
  char v1; // dl
  char v2; // dl
  float Z; // eax

  this->vfptr = (CAkGen3DParamsVtbl *)&CAkGen3DParams::`vftable;
  this->m_Params.m_pAttenuation = 0i64;
  v1 = *((_BYTE *)&this->m_Params + 68);
  *(_QWORD *)&this->m_Params.m_ID = 0i64;
  *(_QWORD *)&this->m_Params.m_ePathMode = 0i64;
  v2 = v1 & 0xD6 | 8;
  *((_BYTE *)&this->m_Params + 68) = v2;
  this->m_Params.m_Position.X = g_DefaultSoundPosition.Position.X;
  this->m_Params.m_Position.Y = g_DefaultSoundPosition.Position.Y;
  Z = g_DefaultSoundPosition.Position.Z;
  this->m_Params.m_pArrayVertex = 0i64;
  this->m_Params.m_Position.Z = Z;
  this->m_Params.m_ulNumVertices = 0;
  this->m_Params.m_pArrayPlaylist = 0i64;
  this->m_Params.m_ulNumPlaylistItem = 0;
  *((_BYTE *)&this->m_Params + 68) = v2 & 0xE9 | 0x10;
  *(_QWORD *)&this->m_Params.m_fConeOutsideVolume = 0i64;
}

// File Line: 69
// RVA: 0xA93030
void __fastcall CAkGen3DParams::Term(CAkGen3DParams *this)
{
  AkPathVertex *m_pArrayVertex; // rdx
  AkPathListItem *m_pArrayPlaylist; // rdx

  m_pArrayVertex = this->m_Params.m_pArrayVertex;
  if ( m_pArrayVertex )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pArrayVertex);
    this->m_Params.m_pArrayVertex = 0i64;
  }
  m_pArrayPlaylist = this->m_Params.m_pArrayPlaylist;
  if ( m_pArrayPlaylist )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pArrayPlaylist);
    this->m_Params.m_pArrayPlaylist = 0i64;
  }
  this->m_Params.m_ulNumPlaylistItem = 0;
  this->m_Params.m_ulNumVertices = 0;
}

// File Line: 90
// RVA: 0xA92FE0
void __fastcall CAkGen3DParams::SetTransition(CAkGen3DParams *this, int in_TransitionTime)
{
  __int64 v2; // rax
  AkPathListItem *v4; // rdx
  __int64 iNumVertices; // rcx

  v2 = 0i64;
  for ( this->m_Params.m_TransitionTime = in_TransitionTime;
        (unsigned int)v2 < this->m_Params.m_ulNumPlaylistItem;
        v2 = (unsigned int)(v2 + 1) )
  {
    v4 = &this->m_Params.m_pArrayPlaylist[v2];
    iNumVertices = v4->iNumVertices;
    if ( (int)iNumVertices > 0 )
      v4->pVertices[iNumVertices - 1].Duration = this->m_Params.m_TransitionTime;
  }
}

// File Line: 96
// RVA: 0xA92FA0
AKRESULT __fastcall CAkGen3DParams::SetPathPlayList(CAkGen3DParams *this, CAkPath *in_pPath, AkPathState *in_pState)
{
  return CAkPathManager::SetPathsList(
           g_pPathManager,
           in_pPath,
           this->m_Params.m_pArrayPlaylist,
           this->m_Params.m_ulNumPlaylistItem,
           this->m_Params.m_ePathMode,
           (*((_BYTE *)&this->m_Params + 68) & 0x20) != 0,
           in_pState);
}

// File Line: 111
// RVA: 0xA92DE0
__int64 __fastcall CAkGen3DParams::SetPath(
        CAkGen3DParams *this,
        AkPathVertex *in_pArrayVertex,
        unsigned int in_ulNumVertices,
        AkPathListItemOffset *in_pArrayPlaylist,
        unsigned int in_ulNumPlaylistItem)
{
  AkPathVertex *m_pArrayVertex; // rdx
  unsigned int v7; // edi
  unsigned int v11; // ebp
  AkPathListItem *m_pArrayPlaylist; // rdx
  AkPathVertex *v13; // rax
  AkPathListItem *v14; // rax
  unsigned int v15; // r9d
  __int64 v16; // rdx
  AkPathListItemOffset *v17; // r8
  unsigned int ulVerticesOffset; // r10d
  AkPathListItem *v19; // rcx
  __int64 iNumVertices; // r8

  m_pArrayVertex = this->m_Params.m_pArrayVertex;
  v7 = 0;
  v11 = 1;
  if ( m_pArrayVertex )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pArrayVertex);
    this->m_Params.m_pArrayVertex = 0i64;
  }
  m_pArrayPlaylist = this->m_Params.m_pArrayPlaylist;
  if ( m_pArrayPlaylist )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pArrayPlaylist);
    this->m_Params.m_pArrayPlaylist = 0i64;
  }
  this->m_Params.m_ulNumVertices = 0;
  this->m_Params.m_ulNumPlaylistItem = 0;
  if ( in_ulNumVertices && in_ulNumPlaylistItem && in_pArrayVertex && in_pArrayPlaylist )
  {
    v13 = (AkPathVertex *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 16 * in_ulNumVertices);
    this->m_Params.m_pArrayVertex = v13;
    if ( v13
      && (memmove(v13, in_pArrayVertex, 16 * in_ulNumVertices),
          this->m_Params.m_ulNumVertices = in_ulNumVertices,
          v14 = (AkPathListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * in_ulNumPlaylistItem),
          (this->m_Params.m_pArrayPlaylist = v14) != 0i64) )
    {
      this->m_Params.m_ulNumPlaylistItem = in_ulNumPlaylistItem;
      v15 = 0;
      v16 = 0i64;
      v17 = in_pArrayPlaylist;
      while ( 1 )
      {
        ulVerticesOffset = in_pArrayPlaylist->ulVerticesOffset;
        this->m_Params.m_pArrayPlaylist[v16].iNumVertices = in_pArrayPlaylist->iNumVertices;
        ++in_pArrayPlaylist;
        if ( v17->ulVerticesOffset >= in_ulNumVertices )
          break;
        ++v15;
        ++v16;
        ++v17;
        this->m_Params.m_pArrayPlaylist[v16 - 1].pVertices = &this->m_Params.m_pArrayVertex[ulVerticesOffset];
        this->m_Params.m_pArrayPlaylist[v16 - 1].fRangeX = 0.0;
        this->m_Params.m_pArrayPlaylist[v16 - 1].fRangeY = 0.0;
        if ( v15 >= in_ulNumPlaylistItem )
          goto LABEL_19;
      }
      v11 = 2;
    }
    else
    {
      v11 = 52;
    }
  }
  else
  {
    v11 = 31;
  }
LABEL_19:
  if ( this->m_Params.m_ulNumPlaylistItem )
  {
    do
    {
      v19 = this->m_Params.m_pArrayPlaylist;
      iNumVertices = v19[v7].iNumVertices;
      if ( (int)iNumVertices > 0 )
        v19[v7].pVertices[iNumVertices - 1].Duration = this->m_Params.m_TransitionTime;
      ++v7;
    }
    while ( v7 < this->m_Params.m_ulNumPlaylistItem );
  }
  return v11;
}

// File Line: 224
// RVA: 0xA92D00
void __fastcall CAkGen3DParamsEx::~CAkGen3DParamsEx(CAkGen3DParamsEx *this)
{
  bool *pbPlayed; // rdx
  CAkAttenuation *m_pAttenuation; // rcx

  pbPlayed = this->m_PathState.pbPlayed;
  this->vfptr = (CAkGen3DParamsVtbl *)&CAkGen3DParamsEx::`vftable;
  if ( pbPlayed )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, pbPlayed);
    this->m_PathState.pbPlayed = 0i64;
  }
  this->vfptr = (CAkGen3DParamsVtbl *)&CAkGen3DParams::`vftable;
  m_pAttenuation = this->m_Params.m_pAttenuation;
  if ( m_pAttenuation )
    m_pAttenuation->vfptr->Release(m_pAttenuation);
}

// File Line: 229
// RVA: 0xA92DB0
void __fastcall CAkGen3DParamsEx::FreePathInfo(CAkGen3DParamsEx *this)
{
  bool *pbPlayed; // rdx

  pbPlayed = this->m_PathState.pbPlayed;
  if ( pbPlayed )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, pbPlayed);
    this->m_PathState.pbPlayed = 0i64;
  }
}

