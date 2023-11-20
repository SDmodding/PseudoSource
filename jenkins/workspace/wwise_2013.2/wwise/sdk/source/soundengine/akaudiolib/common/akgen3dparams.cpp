// File Line: 41
// RVA: 0xA92C90
void __fastcall CAkGen3DParams::CAkGen3DParams(CAkGen3DParams *this)
{
  char v1; // dl
  char v2; // dl
  float v3; // eax

  this->vfptr = (CAkGen3DParamsVtbl *)&CAkGen3DParams::`vftable';
  this->m_Params.m_pAttenuation = 0i64;
  v1 = *((_BYTE *)&this->m_Params + 68);
  *(_QWORD *)&this->m_Params.m_ID = 0i64;
  *(_QWORD *)&this->m_Params.m_ePathMode = 0i64;
  v2 = v1 & 0xDE | 8;
  *((_BYTE *)&this->m_Params + 68) = v2;
  this->m_Params.m_Position.X = g_DefaultSoundPosition.Position.X;
  this->m_Params.m_Position.Y = g_DefaultSoundPosition.Position.Y;
  v3 = g_DefaultSoundPosition.Position.Z;
  this->m_Params.m_pArrayVertex = 0i64;
  this->m_Params.m_Position.Z = v3;
  this->m_Params.m_ulNumVertices = 0;
  this->m_Params.m_pArrayPlaylist = 0i64;
  this->m_Params.m_ulNumPlaylistItem = 0;
  *((_BYTE *)&this->m_Params + 68) = v2 & 0xF9 | 0x10;
  *(_QWORD *)&this->m_Params.m_fConeOutsideVolume = 0i64;
}

// File Line: 69
// RVA: 0xA93030
void __fastcall CAkGen3DParams::Term(CAkGen3DParams *this)
{
  AkPathVertex *v1; // rdx
  CAkGen3DParams *v2; // rbx
  AkPathListItem *v3; // rdx

  v1 = this->m_Params.m_pArrayVertex;
  v2 = this;
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
    v2->m_Params.m_pArrayVertex = 0i64;
  }
  v3 = v2->m_Params.m_pArrayPlaylist;
  if ( v3 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v3);
    v2->m_Params.m_pArrayPlaylist = 0i64;
  }
  v2->m_Params.m_ulNumPlaylistItem = 0;
  v2->m_Params.m_ulNumVertices = 0;
}

// File Line: 90
// RVA: 0xA92FE0
void __fastcall CAkGen3DParams::SetTransition(CAkGen3DParams *this, int in_TransitionTime)
{
  __int64 v2; // rax
  CAkGen3DParams *v3; // r9
  AkPathListItem *v4; // rcx
  AkPathListItem *v5; // rdx
  __int64 v6; // rcx

  v2 = 0i64;
  v3 = this;
  this->m_Params.m_TransitionTime = in_TransitionTime;
  if ( this->m_Params.m_ulNumPlaylistItem )
  {
    do
    {
      v4 = v3->m_Params.m_pArrayPlaylist;
      v5 = &v4[v2];
      v6 = v4[v2].iNumVertices;
      if ( (signed int)v6 > 0 )
        *((_DWORD *)&v5->pVertices[v6] - 1) = v3->m_Params.m_TransitionTime;
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v3->m_Params.m_ulNumPlaylistItem );
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
           (*((_BYTE *)&this->m_Params + 68) >> 5) & 1,
           in_pState);
}

// File Line: 111
// RVA: 0xA92DE0
__int64 __fastcall CAkGen3DParams::SetPath(CAkGen3DParams *this, AkPathVertex *in_pArrayVertex, unsigned int in_ulNumVertices, AkPathListItemOffset *in_pArrayPlaylist, unsigned int in_ulNumPlaylistItem)
{
  AkPathVertex *v5; // r12
  AkPathVertex *v6; // rdx
  unsigned int v7; // edi
  AkPathListItemOffset *v8; // rsi
  unsigned int v9; // er15
  CAkGen3DParams *v10; // rbx
  unsigned int v11; // ebp
  AkPathListItem *v12; // rdx
  AkPathVertex *v13; // rax
  AkPathListItem *v14; // rax
  unsigned int v15; // er9
  __int64 v16; // rdx
  AkPathListItemOffset *v17; // r8
  unsigned int v18; // er10
  AkPathListItem *v19; // rcx
  __int64 v20; // r8

  v5 = in_pArrayVertex;
  v6 = this->m_Params.m_pArrayVertex;
  v7 = 0;
  v8 = in_pArrayPlaylist;
  v9 = in_ulNumVertices;
  v10 = this;
  v11 = 1;
  if ( v6 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v6);
    v10->m_Params.m_pArrayVertex = 0i64;
  }
  v12 = v10->m_Params.m_pArrayPlaylist;
  if ( v12 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v12);
    v10->m_Params.m_pArrayPlaylist = 0i64;
  }
  v10->m_Params.m_ulNumVertices = 0;
  v10->m_Params.m_ulNumPlaylistItem = 0;
  if ( v9 && in_ulNumPlaylistItem && v5 && v8 )
  {
    v13 = (AkPathVertex *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 16 * v9);
    v10->m_Params.m_pArrayVertex = v13;
    if ( v13
      && (memmove(v13, v5, 16 * v9),
          v10->m_Params.m_ulNumVertices = v9,
          v14 = (AkPathListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * in_ulNumPlaylistItem),
          (v10->m_Params.m_pArrayPlaylist = v14) != 0i64) )
    {
      v10->m_Params.m_ulNumPlaylistItem = in_ulNumPlaylistItem;
      v15 = 0;
      if ( in_ulNumPlaylistItem )
      {
        v16 = 0i64;
        v17 = v8;
        while ( 1 )
        {
          v18 = v8->ulVerticesOffset;
          v10->m_Params.m_pArrayPlaylist[v16].iNumVertices = v8->iNumVertices;
          ++v8;
          if ( v17->ulVerticesOffset >= v9 )
            break;
          ++v15;
          ++v16;
          ++v17;
          v10->m_Params.m_pArrayPlaylist[v16 - 1].pVertices = &v10->m_Params.m_pArrayVertex[v18];
          *((_DWORD *)&v10->m_Params.m_pArrayPlaylist[v16] - 3) = 0;
          *((_DWORD *)&v10->m_Params.m_pArrayPlaylist[v16] - 2) = 0;
          if ( v15 >= in_ulNumPlaylistItem )
            goto LABEL_19;
        }
        v11 = 2;
      }
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
  if ( v10->m_Params.m_ulNumPlaylistItem > 0 )
  {
    do
    {
      v19 = v10->m_Params.m_pArrayPlaylist;
      v20 = v19[v7].iNumVertices;
      if ( (signed int)v20 > 0 )
        *((_DWORD *)&v19[v7].pVertices[v20] - 1) = v10->m_Params.m_TransitionTime;
      ++v7;
    }
    while ( v7 < v10->m_Params.m_ulNumPlaylistItem );
  }
  return v11;
}

// File Line: 224
// RVA: 0xA92D00
void __fastcall CAkGen3DParamsEx::~CAkGen3DParamsEx(CAkGen3DParamsEx *this)
{
  bool *v1; // rdx
  CAkGen3DParamsEx *v2; // rbx
  CAkAttenuation *v3; // rcx

  v1 = this->m_PathState.pbPlayed;
  v2 = this;
  this->vfptr = (CAkGen3DParamsVtbl *)&CAkGen3DParamsEx::`vftable';
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
    v2->m_PathState.pbPlayed = 0i64;
  }
  v2->vfptr = (CAkGen3DParamsVtbl *)&CAkGen3DParams::`vftable';
  v3 = v2->m_Params.m_pAttenuation;
  if ( v3 )
    ((void (*)(void))v3->vfptr->Release)();
}

// File Line: 229
// RVA: 0xA92DB0
void __fastcall CAkGen3DParamsEx::FreePathInfo(CAkGen3DParamsEx *this)
{
  bool *v1; // rdx
  CAkGen3DParamsEx *v2; // rbx

  v1 = this->m_PathState.pbPlayed;
  v2 = this;
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
    v2->m_PathState.pbPlayed = 0i64;
  }
}

