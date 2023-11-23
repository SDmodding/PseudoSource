// File Line: 103
// RVA: 0x8D9140
float __fastcall Scaleform::GFx::SpriteDef::GetFrameRate(Scaleform::GFx::SpriteDef *this)
{
  return this->pMovieDef->pData.pObject->Header.FPS;
}

// File Line: 104
// RVA: 0x8D91A0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::SpriteDef::GetFrameRect(
        Scaleform::GFx::SpriteDef *this,
        Scaleform::Render::Rect<float> *result)
{
  result->x2 = 1.0;
  result->y2 = 1.0;
  *(_QWORD *)&result->x1 = 0i64;
  return result;
}

// File Line: 106
// RVA: 0x8E1570
__int64 __fastcall Scaleform::GFx::SpriteDef::GetVersion(Scaleform::GFx::SpriteDef *this)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::MovieDataDef *))this->pMovieDef->vfptr[2].GetKey)(this->pMovieDef);
}

// File Line: 107
// RVA: 0x8DDE60
__int64 __fastcall Scaleform::GFx::SpriteDef::GetSWFFlags(Scaleform::GFx::SpriteDef *this)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::MovieDataDef *))this->pMovieDef->vfptr[4].GetKey)(this->pMovieDef);
}

// File Line: 109
// RVA: 0x8D7A80
__int64 __fastcall Scaleform::GFx::SpriteDef::GetFileBytes(Scaleform::GFx::SpriteDef *this)
{
  return this->pMovieDef->pData.pObject->Header.FileLength;
}

// File Line: 110
// RVA: 0x8D7BD0
const char *__fastcall Scaleform::GFx::SpriteDef::GetFileURL(Scaleform::GFx::SpriteDef *this)
{
  return (const char *)((this->pMovieDef->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
}

// File Line: 115
// RVA: 0x8DAA90
bool __fastcall Scaleform::GFx::SpriteDef::GetLabeledFrame(
        Scaleform::GFx::SpriteDef *this,
        const char *label,
        unsigned int *frameNumber,
        bool translateNumbers)
{
  return Scaleform::GFx::MovieDataDef::TranslateFrameString(&this->NamedFrames, label, frameNumber, translateNumbers);
}

// File Line: 119
// RVA: 0x8D8DF0
Scaleform::String *__fastcall Scaleform::GFx::SpriteDef::GetFrameLabel(
        Scaleform::GFx::SpriteDef *this,
        unsigned int frameNumber,
        unsigned int *exactFrameNumberForLabel)
{
  return Scaleform::GFx::MovieDataDef::TranslateNumberToFrameString(
           &this->NamedFrames,
           frameNumber,
           exactFrameNumberForLabel);
}

// File Line: 130
// RVA: 0x908AE0
void __fastcall Scaleform::GFx::SpriteDef::SetLoadingPlaylistFrame(
        Scaleform::GFx::SpriteDef *this,
        Scaleform::GFx::TimelineDef::Frame *frame,
        Scaleform::GFx::LogState *plog)
{
  __int64 LoadingFrame; // rax
  Scaleform::Log *pObject; // rax
  unsigned __int64 Size; // rsi

  LoadingFrame = this->LoadingFrame;
  if ( SLODWORD(this->Playlist.Data.Size) > (int)LoadingFrame )
  {
    this->Playlist.Data.Data[LoadingFrame] = *frame;
  }
  else if ( plog && (plog->pLog.pObject || Scaleform::Log::GetGlobalLog()) )
  {
    pObject = plog->pLog.pObject;
    Size = this->Playlist.Data.Size;
    if ( !pObject )
      pObject = Scaleform::Log::GetGlobalLog();
    Scaleform::Log::LogError(
      pObject,
      "Invalid SWF file: failed to load sprites frame #%d since total frames counter is %d",
      (unsigned int)(this->LoadingFrame + 1),
      (unsigned int)Size);
  }
}

// File Line: 146
// RVA: 0x8DC210
Scaleform::GFx::TimelineDef::Frame *__fastcall Scaleform::GFx::SpriteDef::GetPlaylist(
        Scaleform::GFx::SpriteDef *this,
        Scaleform::GFx::TimelineDef::Frame *result,
        int frameNumber)
{
  *result = this->Playlist.Data.Data[frameNumber];
  return result;
}

// File Line: 165
// RVA: 0x8DDD10
__int64 __fastcall Scaleform::GFx::SpriteDef::GetResourceTypeCode(Scaleform::GFx::SpriteDef *this)
{
  return 33792i64;
}

// File Line: 168
// RVA: 0x90B6F0
void __fastcall Scaleform::GFx::SpriteDef::SetScale9Grid(
        Scaleform::GFx::SpriteDef *this,
        Scaleform::Render::Rect<float> *r)
{
  __int64 v4; // rax
  Scaleform::GFx::Scale9Grid *pScale9Grid; // rcx
  float y2; // xmm2_4
  float x2; // xmm1_4
  float y1; // xmm0_4
  int v9; // [rsp+48h] [rbp+10h] BYREF
  __int64 v10; // [rsp+50h] [rbp+18h]

  if ( !this->pScale9Grid )
  {
    v9 = 258;
    v4 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::SpriteDef *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
           Scaleform::Memory::pGlobalHeap,
           this,
           16i64,
           &v9,
           -2i64);
    v10 = v4;
    if ( v4 )
    {
      *(_QWORD *)v4 = 0i64;
      *(_QWORD *)(v4 + 8) = 0i64;
    }
    else
    {
      v4 = 0i64;
    }
    this->pScale9Grid = (Scaleform::GFx::Scale9Grid *)v4;
  }
  pScale9Grid = this->pScale9Grid;
  y2 = r->y2;
  x2 = r->x2;
  y1 = r->y1;
  pScale9Grid->Rect.x1 = r->x1;
  pScale9Grid->Rect.y1 = y1;
  pScale9Grid->Rect.x2 = x2;
  pScale9Grid->Rect.y2 = y2;
}

// File Line: 307
// RVA: 0x8A8660
void __fastcall Scaleform::GFx::TimelineSnapshot::~TimelineSnapshot(Scaleform::GFx::TimelineSnapshot *this)
{
  Scaleform::List<Scaleform::GFx::TimelineSnapshot::SnapshotElement,Scaleform::GFx::TimelineSnapshot::SnapshotElement> *p_SnapshotList; // r8
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *pNext; // rdx
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *v4; // rcx
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *FirstPage; // rdx
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *v6; // rbx

  p_SnapshotList = &this->SnapshotList;
  pNext = (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *)this->SnapshotList.Root.pNext;
  if ( pNext != (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *)&this->SnapshotList )
  {
    do
    {
      v4 = pNext[1].pNext;
      pNext->pNext = this->SnapshotHeap.FirstEmptySlot;
      this->SnapshotHeap.FirstEmptySlot = pNext;
      pNext = v4;
    }
    while ( v4 != (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *)p_SnapshotList );
  }
  p_SnapshotList->Root.pPrev = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)p_SnapshotList;
  p_SnapshotList->Root.pNext = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)p_SnapshotList;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->SnapshotSortedArray.Data.Data);
  FirstPage = this->SnapshotHeap.FirstPage;
  if ( this->SnapshotHeap.FirstPage )
  {
    do
    {
      v6 = FirstPage->pNext;
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      FirstPage = v6;
    }
    while ( v6 );
  }
}

